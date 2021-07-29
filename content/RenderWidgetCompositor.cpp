// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/RenderWidgetCompositor.h"

#include "base/message_loop/message_loop.h"
#include "cc/animation/animation_host.h"
#include "cc/animation/animation_timeline.h"
#include "cc/blink/web_layer_impl.h"
#include "cc/layers/layer.h"
#include "cc/input/scroll_state_data.h"
#include "cc/input/scroll_state.h"
#include "cc/output/managed_memory_policy.h"
#include "cc/output/compositor_frame_sink.h"
#include "cc/output/texture_mailbox_deleter.h"
#include "cc/raster/task_graph_runner.h"
#include "cc/surfaces/surface_id_allocator.h"
#include "cc/surfaces/surface_manager.h"
#include "cc/surfaces/display.h"
#include "cc/surfaces/direct_compositor_frame_sink.h"
#include "cc/trees/layer_tree_host_in_process.h"
#include "content/OrigChromeMgr.h"
#include "content/WebPageOcBridge.h"
#include "content/WebSharedBitmapManager.h"
#include "content/browser/PlatformEventHandlerUtil.h"
#include "content/compositor/BrowserContextProvider.h"
#include "content/compositor/EmptyOutputSurface.h"
#include "content/compositor/GpuOutputSurface.h"
#include "content/compositor/SoftwareOutputDevice.h"
#include "content/compositor/SoftwareOutputSurface.h"
#include "content/gpu/ChildGpuMemoryBufferManager.h"
#include "gpu/command_buffer/client/gles2_interface.h"
#include "gpu/command_buffer/common/gpu_memory_allocation.h"
//#include "gpu/blink/webgraphicscontext3d_in_process_command_buffer_impl.h"
#include "third_party/WebKit/public/web/WebSelection.h"

namespace wke {
extern bool g_headlessEnable;
}

namespace content {

const cc::FrameSinkId kRootFrameSinkId_1(1, 1);
cc::SurfaceManager* g_surfaceManager = nullptr;
static uint32_t s_nextSurfaceIdNamespace = 1u;

RenderWidgetCompositor::RenderWidgetCompositor(WebPageOcBridge* webPageOcBridge, bool isUiThreadIsolate)
{
    m_webPageOcBridge = webPageOcBridge;
    m_softwareOutputDevice = nullptr;
    m_hWnd = nullptr;
    m_pendingSwaps = 0;
    m_display = nullptr;
    m_inputHandler = nullptr;

    init(isUiThreadIsolate);
}

void RenderWidgetCompositor::init(bool isUiThreadIsolate)
{
    cc::LayerTreeSettings settings;
    settings.layer_transforms_should_scale_layer_contents = true;
    settings.gpu_rasterization_forced = false;
    settings.gpu_rasterization_enabled = false;
    settings.create_low_res_tiling = true;
    settings.can_use_lcd_text = true;
    settings.use_distance_field_text = false;
    settings.use_zero_copy = false;
//     settings.accelerated_animation_enabled = true;
//     settings.use_compositor_animation_timelines = true;

    cc::LayerTreeHostInProcess::InitParams params;

    OrigChromeMgr* mgr = OrigChromeMgr::getInst();

    params.client = this;
//     params.shared_bitmap_manager = mgr->getSharedBitmapManager();
//     params.gpu_memory_buffer_manager = mgr->getChildGpuMemoryBufferManager();
    params.task_graph_runner = mgr->getTaskGraphRunner();
    params.settings = &settings;
    params.main_task_runner = base::MessageLoop::current()->task_runner();
    m_animationHost = cc::AnimationHost::CreateMainInstance().release();
    params.mutator_host = m_animationHost; // m_animationHost->CreateImplInstance(false).release();

    scoped_refptr<base::SingleThreadTaskRunner> implTaskRunner = isUiThreadIsolate ? mgr->getUiLoop()->task_runner() : params.main_task_runner;

    m_layerTreeHost = cc::LayerTreeHostInProcess::CreateThreaded(implTaskRunner, &params).release();
    m_layerTreeHost->SetVisible(true);
    m_inputHandler = m_layerTreeHost->GetInputHandler().get();
}

static void destroyOnUiThread(cc::SurfaceIdAllocator* idAllocator, cc::OutputSurface* outputSurface, cc::OnscreenDisplayClient* displayClient)
{
    if (idAllocator)
        delete idAllocator;
    if (outputSurface)
        delete outputSurface;
//     if (displayClient)
//         delete displayClient;
    DebugBreak();
}

RenderWidgetCompositor::~RenderWidgetCompositor()
{
    m_layerTreeHost->SetVisible(false);

    if (m_animationHost)
        delete m_animationHost;

    DebugBreak();
//     scoped_ptr<cc::OutputSurface> outputSurface;
//     if (!m_layerTreeHost->output_surface_lost())
//         outputSurface = m_layerTreeHost->ReleaseOutputSurface();
//     delete m_layerTreeHost;
// 
//     OrigChromeMgr::getInst()->getUiLoop()->task_runner()->PostTask(FROM_HERE,
//         base::Bind(&destroyOnUiThread, m_idAllocator.get(), outputSurface.release(), m_displayClient.release()));
}

void RenderWidgetCompositor::onHostResizedInUiThread()
{
    if (m_display)
        m_display->Resize(m_size);
}

void RenderWidgetCompositor::onHostResized(int width, int height)
{
    gfx::Size size(width, height);
    if (m_size == size)
        return;
    m_size = size;

    if (m_layerTreeHost && m_layerTreeHost->GetLayerTree())
        m_layerTreeHost->GetLayerTree()->SetViewportSize(m_size);

    OrigChromeMgr::getInst()->getUiLoop()->task_runner()->PostTask(FROM_HERE, base::Bind(&RenderWidgetCompositor::onHostResizedInUiThread, base::Unretained(this)));
}

void RenderWidgetCompositor::setHWND(HWND hWnd)
{
    m_hWnd = hWnd;

    if (m_softwareOutputDevice)
        m_softwareOutputDevice->setHWND(hWnd);
}

HDC RenderWidgetCompositor::getHdcLocked()
{
    if (m_softwareOutputDevice)
        return m_softwareOutputDevice->getHdcLocked();
    return nullptr;
}

void RenderWidgetCompositor::releaseHdc()
{
    if (m_softwareOutputDevice)
        m_softwareOutputDevice->releaseHdc();
}

// WebLayerTreeView implementation.
void RenderWidgetCompositor::setRootLayer(const blink::WebLayer& layer)
{
    if (wke::g_headlessEnable || !m_layerTreeHost || !m_layerTreeHost->GetLayerTree())
        return;
    scoped_refptr<cc::Layer> ccLayer((cc::Layer*)((&layer)->ccLayer()));
    m_layerTreeHost->GetLayerTree()->SetRootLayer(ccLayer);
}

void RenderWidgetCompositor::clearRootLayer()
{
    if (m_layerTreeHost && m_layerTreeHost->GetLayerTree())
        m_layerTreeHost->GetLayerTree()->SetRootLayer(scoped_refptr<cc::Layer>());
}

blink::WebSize RenderWidgetCompositor::deviceViewportSize() const
{
    gfx::Size size;
    if (m_layerTreeHost && m_layerTreeHost->GetLayerTree())
        size = m_layerTreeHost->GetLayerTree()->device_viewport_size();
    return blink::WebSize(size.width(), size.height());
}

float RenderWidgetCompositor::deviceScaleFactor() const
{
    float factor = 1;
    if (m_layerTreeHost && m_layerTreeHost->GetLayerTree())
        factor = m_layerTreeHost->GetLayerTree()->device_scale_factor();
    return factor;
}

void RenderWidgetCompositor::finishAllRendering()
{
    DebugBreak();
    //m_layerTreeHost->FinishAllRendering();
}

void RenderWidgetCompositor::attachCompositorAnimationTimeline(blink::CompositorAnimationTimeline* compositorTimeline)
{
    DCHECK(compositorTimeline);
    DCHECK(m_animationHost);
    //m_animationHost->AddAnimationTimeline(static_cast<const cc_blink::WebCompositorAnimationTimelineImpl*>(compositorTimeline)->animation_timeline());
}

void RenderWidgetCompositor::detachCompositorAnimationTimeline(blink::CompositorAnimationTimeline* compositorTimeline)
{
    DCHECK(compositorTimeline);
    DCHECK(m_animationHost);
    //m_animationHost->RemoveAnimationTimeline(static_cast<const cc_blink::WebCompositorAnimationTimelineImpl*>(compositorTimeline)->animation_timeline());
}

void RenderWidgetCompositor::setViewportSize(const blink::WebSize& deviceViewportSize)
{
    if (m_layerTreeHost && m_layerTreeHost->GetLayerTree())
        m_layerTreeHost->GetLayerTree()->SetViewportSize(gfx::Size(deviceViewportSize.width, deviceViewportSize.height));
}

blink::WebFloatPoint RenderWidgetCompositor::adjustEventPointForPinchZoom(const blink::WebFloatPoint& point) const
{
    return point;
}

void RenderWidgetCompositor::setDeviceScaleFactor(float deviceScale)
{
    DebugBreak();
    //m_layerTreeHost->SetDeviceScaleFactor(deviceScale);
}

void RenderWidgetCompositor::setBackgroundColor(blink::WebColor color)
{
    m_layerTreeHost->GetLayerTree()->set_background_color(color);
}

void RenderWidgetCompositor::setHasTransparentBackground(bool transparent)
{
    m_layerTreeHost->GetLayerTree()->set_has_transparent_background(transparent);
}

void RenderWidgetCompositor::setVisible(bool visible)
{
    if (m_layerTreeHost)
        m_layerTreeHost->SetVisible(visible);
    if (m_display)
        m_display->SetVisible(visible);

//     if (visible)
//         m_layerTreeHost->SetLayerTreeHostClientReady();
}

void RenderWidgetCompositor::setPageScaleFactorAndLimits(float page_scale_factor, float minimum, float maximum)
{
    m_layerTreeHost->GetLayerTree()->SetPageScaleFactorAndLimits(page_scale_factor, minimum, maximum);
}

void RenderWidgetCompositor::startPageScaleAnimation(const blink::WebPoint& destination, bool useAnchor, float newPageScale, double durationSec)
{
    base::TimeDelta duration = base::TimeDelta::FromMicroseconds((int64)(durationSec)*base::Time::kMicrosecondsPerSecond);
    m_layerTreeHost->GetLayerTree()->StartPageScaleAnimation(gfx::Vector2d(destination.x, destination.y), useAnchor, newPageScale, duration);
}

void RenderWidgetCompositor::heuristicsForGpuRasterizationUpdated(bool matches_heuristics)
{
    m_layerTreeHost->SetHasGpuRasterizationTrigger(matches_heuristics);
}

void RenderWidgetCompositor::setNeedsAnimate()
{
    m_layerTreeHost->SetNeedsAnimate();
    m_layerTreeHost->SetNeedsUpdateLayers();
}

void RenderWidgetCompositor::setNeedsBeginFrame()
{
    m_layerTreeHost->SetNeedsAnimate();
}

void RenderWidgetCompositor::setNeedsCompositorUpdate()
{
    DebugBreak();
    //m_layerTreeHost->SetNeedsUpdateLayers();
}

void RenderWidgetCompositor::didStopFlinging()
{
    DebugBreak();
    //m_layerTreeHost->DidStopFlinging();
}

extern bool g_popupMenuIniting;

void RenderWidgetCompositor::registerForAnimations(blink::WebLayer* layer)
{
//     if (g_popupMenuIniting)
//         return;
// 
//     cc::Layer* cc_layer = static_cast<cc_blink::WebLayerImpl*>(layer)->layer();
//     cc_layer->RegisterForAnimations(m_layerTreeHost->animation_registrar());
    DebugBreak();
}

void RenderWidgetCompositor::registerViewportLayers(
    const blink::WebLayer* overscrollElasticityLayer,
    const blink::WebLayer* pageScaleLayer,
    const blink::WebLayer* innerViewportScrollLayer,
    const blink::WebLayer* outerViewportScrollLayer)
{
    m_layerTreeHost->GetLayerTree()->RegisterViewportLayers(
        // TODO(bokan): This check can probably be removed now, but it looks
        // like overscroll elasticity may still be NULL until PinchViewport
        // registers its layers.
        // The scroll elasticity layer will only exist when using pinch virtual
        // viewports.
        overscrollElasticityLayer ? static_cast<const cc_blink::WebLayerImpl*>(overscrollElasticityLayer)->layer() : NULL,
        static_cast<const cc_blink::WebLayerImpl*>(pageScaleLayer)->layer(), static_cast<const cc_blink::WebLayerImpl*>(innerViewportScrollLayer)->layer(),
        // TODO(bokan): This check can probably be removed now, but it looks
        // like overscroll elasticity may still be NULL until PinchViewport
        // registers its layers.
        // The outer viewport layer will only exist when using pinch virtual
        // viewports.
        outerViewportScrollLayer ? static_cast<const cc_blink::WebLayerImpl*>(outerViewportScrollLayer)->layer() : NULL);
}

void RenderWidgetCompositor::clearViewportLayers()
{
    m_layerTreeHost->GetLayerTree()->RegisterViewportLayers(
        scoped_refptr<cc::Layer>(), scoped_refptr<cc::Layer>(),
        scoped_refptr<cc::Layer>(), scoped_refptr<cc::Layer>());
}

cc::LayerSelectionBound ConvertWebSelectionBound(const blink::WebSelection& web_selection, bool is_start)
{
    DebugBreak();
    cc::LayerSelectionBound cc_bound;
//     if (web_selection.isNone())
//         return cc_bound;
// 
//     const blink::WebSelectionBound& web_bound = is_start ? web_selection.start() : web_selection.end();
//     DCHECK(web_bound.layerId);
//     cc_bound.type = cc::SELECTION_BOUND_CENTER;
//     if (web_selection.isRange()) {
//         if (is_start) {
//             cc_bound.type = web_bound.isTextDirectionRTL ? cc::SELECTION_BOUND_RIGHT : cc::SELECTION_BOUND_LEFT;
//         } else {
//             cc_bound.type = web_bound.isTextDirectionRTL ? cc::SELECTION_BOUND_LEFT : cc::SELECTION_BOUND_RIGHT;
//         }
//     }
//     cc_bound.layer_id = web_bound.layerId;
//     cc_bound.edge_top = gfx::PointF(web_bound.edgeTopInLayer);
//     cc_bound.edge_bottom = gfx::PointF(web_bound.edgeBottomInLayer);
    return cc_bound;
}

cc::LayerSelection ConvertWebSelection(const blink::WebSelection& web_selection)
{
    cc::LayerSelection cc_selection;
    cc_selection.start = ConvertWebSelectionBound(web_selection, true);
    cc_selection.end = ConvertWebSelectionBound(web_selection, false);
    cc_selection.is_editable = web_selection.isEditable();
    cc_selection.is_empty_text_form_control = web_selection.isEmptyTextFormControl();
    return cc_selection;
}

void RenderWidgetCompositor::registerSelection(const blink::WebSelection& selection)
{
    m_layerTreeHost->GetLayerTree()->RegisterSelection(ConvertWebSelection(selection));
}

void RenderWidgetCompositor::clearSelection()
{
    cc::LayerSelection empty_selection;
    m_layerTreeHost->GetLayerTree()->RegisterSelection(empty_selection);
}

int RenderWidgetCompositor::layerTreeId() const
{
    return m_layerTreeHost->GetId();
}

void RenderWidgetCompositor::layoutAndPaintAsync(blink::WebLayoutAndPaintAsyncCallback* callback)
{
    DebugBreak();
}

void RenderWidgetCompositor::compositeAndReadbackAsync(blink::WebCompositeAndReadbackAsyncCallback* callback)
{
    DebugBreak();
}

void RenderWidgetCompositor::setDeferCommits(bool defer_commits)
{
    m_layerTreeHost->SetDeferCommits(defer_commits);
}
//////////////////////////////////////////////////////////////////////////

// static std::unique_ptr<gpu::gpu_blink::WebGraphicsContext3DInProcessCommandBufferImpl> createContextCommon(HWND window)
// {
// //     blink::WebGraphicsContext3D::Attributes attrs;
// //     attrs.shareResources = true;
// //     attrs.depth = false;
// //     attrs.stencil = false;
// //     attrs.antialias = false;
// //     attrs.noAutomaticFlushes = true;
// //     bool lose_context_when_out_of_memory = true;
// //     std::string url("chrome://gpu/GpuProcessTransportFactory::CreateContextCommon");
// // 
// //     scoped_ptr<gpu_blink::WebGraphicsContext3DInProcessCommandBufferImpl> context;
// //     if (window)
// //         context = gpu_blink::WebGraphicsContext3DInProcessCommandBufferImpl::CreateViewContext(attrs, true, window);
// //     else
// //         context = gpu_blink::WebGraphicsContext3DInProcessCommandBufferImpl::CreateOffscreenContext(attrs, true);
// //     return context.Pass();
//     DebugBreak();
//     return nullptr;
// }

static cc::SurfaceIdAllocator* genSurfaceIdAllocator()
{
    cc::SurfaceIdAllocator* allocator = new cc::SurfaceIdAllocator(/*s_nextSurfaceIdNamespace++*/);
//     if (g_surfaceManager)
//         allocator->RegisterSurfaceIdNamespace(g_surfaceManager);
    return allocator;
}

void RenderWidgetCompositor::WillBeginMainFrame()
{
}

void RenderWidgetCompositor::BeginMainFrame(const cc::BeginFrameArgs& args)
{
    m_webPageOcBridge->onBeginMainFrame();
}

void RenderWidgetCompositor::BeginMainFrameNotExpectedSoon()
{
}

void RenderWidgetCompositor::DidBeginMainFrame()
{
}

void RenderWidgetCompositor::Layout()
{
    m_webPageOcBridge->onLayout();
}

void RenderWidgetCompositor::DidInitializeCompositorFrameSink()
{
}

void RenderWidgetCompositor::DidFailToInitializeCompositorFrameSink()
{
}

void RenderWidgetCompositor::WillCommit()
{
}

void RenderWidgetCompositor::DidCommit()
{
}

void RenderWidgetCompositor::DidCommitAndDrawFrame()
{
}

void RenderWidgetCompositor::DidCompleteSwapBuffers()
{
}

void RenderWidgetCompositor::UpdateLayerTreeHost()
{

}

void RenderWidgetCompositor::DidReceiveCompositorFrameAck()
{

}

void RenderWidgetCompositor::SetBeginFrameSource(cc::BeginFrameSource* begin_frame_source)
{
    DebugBreak();
}

void RenderWidgetCompositor::WillShutdown()
{

}

void RenderWidgetCompositor::Animate(base::TimeTicks time)
{
    
}

void RenderWidgetCompositor::MainThreadHasStoppedFlinging()
{

}

void RenderWidgetCompositor::ReconcileElasticOverscrollAndRootScroll()
{

}

void RenderWidgetCompositor::UpdateRootLayerStateForSynchronousInputHandler(
    const gfx::ScrollOffset& total_scroll_offset,
    const gfx::ScrollOffset& max_scroll_offset,
    const gfx::SizeF& scrollable_size,
    float page_scale_factor,
    float min_page_scale_factor,
    float max_page_scale_factor)
{

}

void RenderWidgetCompositor::DeliverInputForBeginFrame()
{

}

// void RenderWidgetCompositor::RecordFrameTimingEvents(
//     scoped_ptr<cc::FrameTimingTracker::CompositeTimingSet> compositeEvents,
//     scoped_ptr<cc::FrameTimingTracker::MainFrameTimingSet> mainFrameEvents)
// {
//     //     const base::hash_map<int64_t, std::vector<CompositeTimingEvent>>::iterator& compositeEvent = compositeEvents.begin();
//     //     for (; compositeEvent != compositeEvents.end();++compositeEventcompositeEvent) {
//     //         int64_t frameId = composite_event.first;
//     //         const std::vector<cc::FrameTimingTracker::CompositeTimingEvent>& events =
//     //             compositeEvent.second;
//     //         std::vector<blink::WebFrameTimingEvent> webEvents;
//     //         for (size_t i = 0; i < events.size(); ++i) {
//     //             webEvents.push_back(blink::WebFrameTimingEvent(
//     //                 events[i].frame_id,
//     //                 (events[i].timestamp - base::TimeTicks()).InSecondsF()));
//     //         }
//     //         widget_->webwidget()->recordFrameTimingEvent(
//     //             blink::WebWidget::CompositeEvent, frameId, webEvents);
//     //     }
//     //
//     //     const base::hash_map<int64_t, std::vector<MainFrameTimingEvent>>& mainFrameEvent = mainFrameEvents.begin();
//     //     for (; mainFrameEvent != mainFrameEvents.end(); ++mainFrameEvent) {
//     //         int64_t frameId = mainFrameEvent.first;
//     //         const std::vector<cc::FrameTimingTracker::MainFrameTimingEvent>& events =
//     //             mainFrameEvent.second;
//     //         std::vector<blink::WebFrameTimingEvent> webEvents;
//     //         for (size_t i = 0; i < events.size(); ++i) {
//     //             webEvents.push_back(blink::WebFrameTimingEvent(
//     //                 events[i].frame_id,
//     //                 (events[i].timestamp - base::TimeTicks()).InSecondsF(),
//     //                 (events[i].end_time - base::TimeTicks()).InSecondsF()));
//     //         }
//     //         widget_->webwidget()->recordFrameTimingEvent(
//     //             blink::WebWidget::RenderEvent, frameId, webEvents);
//     //     }
// }

//////////////////////////////////////////////////////////////////////////

void RenderWidgetCompositor::initializeLayerTreeView()
{
    //     SIZE size = m_renderViewHost->windowSize();
    //     m_layerTreeHost->SetViewportSize(gfx::Size(size.cx, size.cy));
}

void RenderWidgetCompositor::firePaintEvent(HDC hdc, const RECT& paintRect)
{
    if (m_softwareOutputDevice)
        m_softwareOutputDevice->firePaintEvent(hdc, paintRect);
    else {
        //         gfx::Rect damageRect(paintRect);
        //         m_layerTreeHost->SetNeedsRedrawRect(damageRect);
        //         m_layerTreeHost->SetNeedsCommit();
    }
}

void RenderWidgetCompositor::onFireWheelEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int x = LOWORD(lParam);
    int y = HIWORD(lParam);
    POINT point = { x, y };
    ::ScreenToClient(hWnd, &point);
    x = point.x;
    y = point.y;

    int wheelDelta = GET_WHEEL_DELTA_WPARAM(wParam);
    int modifiers = 0;
    static const float cScrollbarPixelsPerLine = 100.0f / 3.0f;
    float delta = wheelDelta / static_cast<float>(WHEEL_DELTA);

    float deltaX = 0.f;
    float deltaY = 0.f;

    bool shiftKey = wParam & MK_SHIFT;
    bool ctrlKey = wParam & MK_CONTROL;

    if (shiftKey) {
        deltaX = delta * static_cast<float>(horizontalScrollChars()) * cScrollbarPixelsPerLine;
        deltaY = 0;
    } else {
        deltaX = 0;
        deltaY = delta;
        int verticalMultiplier = verticalScrollLines();
        if (verticalMultiplier != WHEEL_PAGESCROLL)
            deltaY *= static_cast<float>(verticalMultiplier) * cScrollbarPixelsPerLine;
    }

    cc::ScrollStateData data;
    cc::ScrollState scrollState(data);
    m_inputHandler->ScrollBegin(&scrollState, cc::InputHandler::WHEEL);

    scrollState.data()->position_x = x;
    scrollState.data()->position_y = y;
    scrollState.data()->delta_x = -deltaX;
    scrollState.data()->delta_y = -deltaY;
    m_inputHandler->ScrollBy(&scrollState);

    cc::ScrollStateData dataEmpty;
    cc::ScrollState scrollStateEmpty(dataEmpty);
    m_inputHandler->ScrollEnd(&scrollStateEmpty);
}

void RenderWidgetCompositor::fireWheelEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    OrigChromeMgr* mgr = OrigChromeMgr::getInst();
    mgr->getUiLoop()->task_runner()->PostTask(FROM_HERE, 
        base::Bind(&RenderWidgetCompositor::onFireWheelEvent, base::Unretained(this), hWnd, message, wParam, lParam));
}

void RenderWidgetCompositor::ReturnResources(const cc::ReturnedResourceArray& resources)
{
    ;
}

void RenderWidgetCompositor::swapBuffers()
{
    if (m_pendingSwaps > 0)
        return;
    ++m_pendingSwaps;

    OrigChromeMgr* mgr = OrigChromeMgr::getInst();
    mgr->getUiLoop()->task_runner()->PostTask(FROM_HERE, base::Bind(&RenderWidgetCompositor::onSwapBuffers, base::Unretained(this)));
}

void RenderWidgetCompositor::onSwapBuffers()
{
    if (!m_display)
        return;
    --m_pendingSwaps;
    m_display->DidReceiveSwapBuffersAck();
}

void RenderWidgetCompositor::initOnUiThread()
{
    OrigChromeMgr* mgr = OrigChromeMgr::getInst();

    cc::DelayBasedTimeSource* delayBasedTimeSource = new cc::DelayBasedTimeSource(mgr->getUiLoop()->task_runner().get());
    cc::BackToBackBeginFrameSource* backToBackBeginFrameSource = new cc::BackToBackBeginFrameSource(std::unique_ptr<cc::DelayBasedTimeSource>(delayBasedTimeSource));

    std::unique_ptr<SoftwareOutputSurface> outputSurface(SoftwareOutputSurface::Create(m_webPageOcBridge, this).release());
    m_softwareOutputDevice = (SoftwareOutputDevice*)outputSurface->software_device();

    if (m_hWnd)
        m_softwareOutputDevice->setHWND(m_hWnd);

    cc::SurfaceManager* surfaceManager = new cc::SurfaceManager();
    surfaceManager->RegisterFrameSinkId(kRootFrameSinkId_1);

    std::unique_ptr<cc::DisplayScheduler> scheduler(new cc::DisplayScheduler(mgr->getUiLoop()->task_runner().get(), 3));

    cc::RendererSettings softwareRendererSettings;
    m_display = new cc::Display(
        mgr->getSharedBitmapManager(),
        nullptr, // gpu_memory_buffer_manager,
        softwareRendererSettings,
        kRootFrameSinkId_1,
        backToBackBeginFrameSource, // begin_frame_source,
        std::move(outputSurface),
        std::move(scheduler), // scheduler ,
        nullptr // texture_mailbox_deleter
    );

    if (m_display) {
        m_display->Resize(m_size);
        m_display->SetVisible(true);
    }

    m_sink = new cc::DirectCompositorFrameSink(kRootFrameSinkId_1, //FrameSinkId
        surfaceManager, //SurfaceManager* surface_manager,
        m_display, //Display* display,
        nullptr, //scoped_refptr<ContextProvider> context_provider,
        nullptr, //scoped_refptr<ContextProvider> worker_context_provider,
        nullptr, //gpu::GpuMemoryBufferManager* gpu_memory_buffer_manager,
        mgr->getSharedBitmapManager() //SharedBitmapManager* shared_bitmap_manager
    );
    m_layerTreeHost->SetCompositorFrameSink(std::unique_ptr<cc::CompositorFrameSink>(m_sink));
}

// cc::LayerTreeHostClient
void RenderWidgetCompositor::RequestNewCompositorFrameSink()
{
    if (m_layerTreeHost && m_layerTreeHost->GetLayerTree())
        m_layerTreeHost->GetLayerTree()->SetViewportSize(m_size);

    OrigChromeMgr* mgr = OrigChromeMgr::getInst();
    mgr->getUiLoop()->task_runner()->PostTask(FROM_HERE, base::Bind(&RenderWidgetCompositor::initOnUiThread, base::Unretained(this)));
}

} // content