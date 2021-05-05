// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/RenderWidgetCompositor.h"

#include "cc/animation/animation_host.h"
#include "cc/animation/animation_timeline.h"
#include "cc/blink/web_layer_impl.h"
#include "cc/layers/layer.h"
#include "cc/output/output_surface_frame.h"
#include "cc/output/texture_mailbox_deleter.h"
#include "cc/raster/task_graph_runner.h"
#include "cc/surfaces/direct_compositor_frame_sink.h"
#include "cc/surfaces/display.h"
#include "cc/surfaces/surface_manager.h"
#include "cc/trees/layer_tree_host_in_process.h"
#include "content/browser/RenderViewHost.h"
#include "content/browser/WebPage.h"
#include "content/browser/WebSharedBitmapManager.h"
#include "content/browser/compositor/BrowserCompositorOutputSurface.h"
#include "content/browser/compositor/BrowserContextProvider.h"
#include "content/browser/compositor/BrowserSoftwareOutputDevice.h"
#include "content/renderer/raster_worker_pool.h"
#include "content/renderer/synchronous_compositor_frame_sink.h"
#include "skia/ext/platform_canvas.h"
#include "third_party/WebKit/Source/web/WebViewImpl.h"
#include "third_party/WebKit/public/web/WebSelection.h"

DWORD gRenderPID = 0;

namespace content {

class SoftwareDevice : public cc::SoftwareOutputDevice {
public:
    SoftwareDevice(RenderViewHost* renderView)
        : m_canvas(nullptr)
        , m_renderView(renderView)
        , m_pixelSize(1, 1)
    {
    }

    void Resize(const gfx::Size& pixelSize, float deviceScaleFactor) override
    {
        base::AutoLock lock(m_lock);
        m_pixelSize = pixelSize;

        if (0 == m_pixelSize.width())
            m_pixelSize.set_width(1);

        if (0 == m_pixelSize.height())
            m_pixelSize.set_height(1);
    }

    SkCanvas* BeginPaint(const gfx::Rect& damageRect) override
    {
        base::AutoLock lock(m_lock);
        damage_rect_ = damageRect;

        // Intentional no-op: canvas size is controlled by the embedder.
        if (m_canvas && (m_canvas->imageInfo().width() != m_pixelSize.width() || m_canvas->imageInfo().height() != m_pixelSize.height())) {
            delete m_canvas;
            m_canvas = nullptr;
        }

        if (!m_canvas)
            m_canvas = skia::CreatePlatformCanvas(m_pixelSize.width(), m_pixelSize.height(), true);
        return m_canvas;
    }

    void EndPaint() override
    {
        base::AutoLock lock(m_lock);
        if (!m_canvas)
            return;

        HDC hdc = ::GetDC(m_renderView->getPlatformHWND());
        skia::DrawToNativeContext(m_canvas, hdc, damage_rect_.x(), damage_rect_.y(), &damage_rect_.ToRECT());
        ::ReleaseDC(m_renderView->getPlatformHWND(), hdc);
    }

    void firePaintEvent(HDC hdc, const RECT* paintRect)
    {
        base::AutoLock lock(m_lock);
        if (!m_canvas || gfx::Rect(*paintRect).IsEmpty())
            return;

        skia::DrawToNativeContext(m_canvas, hdc, paintRect->left, paintRect->top, paintRect);
    }

private:
    base::Lock m_lock;
    SkCanvas* m_canvas;

    gfx::Size m_pixelSize;

    RenderViewHost* m_renderView;
    DISALLOW_COPY_AND_ASSIGN(SoftwareDevice);
};

class SoftwareOutputSurface : public cc::OutputSurface {
public:
    SoftwareOutputSurface(RenderWidgetCompositor* compositor, std::unique_ptr<SoftwareDevice> softwareDevice)
        : cc::OutputSurface(std::move(softwareDevice))
        , m_compositor(compositor)
    {
    }

    // cc::OutputSurface implementation.
    void BindToClient(cc::OutputSurfaceClient* client) override { }
    void EnsureBackbuffer() override { }
    void DiscardBackbuffer() override { }
    void BindFramebuffer() override { }
    void SwapBuffers(cc::OutputSurfaceFrame frame) override
    {
        m_compositor->swapBuffers();
    }
    void Reshape(const gfx::Size& size,
        float scale_factor,
        const gfx::ColorSpace& color_space,
        bool has_alpha,
        bool use_stencil) override
    {
        //software_device()->Resize(size, scale_factor);
    }
    uint32_t GetFramebufferCopyTextureFormat() override { return 0; }
    cc::OverlayCandidateValidator* GetOverlayCandidateValidator() const override
    {
        return nullptr;
    }
    bool IsDisplayedAsOverlayPlane() const override { return false; }
    unsigned GetOverlayTextureId() const override { return 0; }
    bool SurfaceIsSuspendForRecycle() const override { return false; }
    bool HasExternalStencilTest() const override { return false; }
    void ApplyExternalStencil() override { }

private:
    RenderWidgetCompositor* m_compositor;
};
const cc::FrameSinkId kRootFrameSinkId_1(1, 1);

RenderWidgetCompositor::RenderWidgetCompositor()
{
    m_isSizing = false;
    m_size.cx = 0;
    m_size.cy = 0;
    m_uiThread = nullptr;
    m_sink = nullptr;
    m_outputSurface = nullptr;
    m_display = nullptr;
    m_pendingSwaps = 0;
    m_sharedBitmapManager = new WebSharedBitmapManager();
}

void RenderWidgetCompositor::initOnUiThread()
{
    cc::DelayBasedTimeSource* delayBasedTimeSource = new cc::DelayBasedTimeSource(m_renderViewHost->getUiThreadRunner());
    cc::BackToBackBeginFrameSource* backToBackBeginFrameSource = new cc::BackToBackBeginFrameSource(std::unique_ptr<cc::DelayBasedTimeSource>(delayBasedTimeSource));

    m_outputSurface = new SoftwareOutputSurface(this, base::MakeUnique<SoftwareDevice>(m_renderViewHost));
    cc::SurfaceManager* surfaceManager = new cc::SurfaceManager();
    surfaceManager->RegisterFrameSinkId(kRootFrameSinkId_1);

    std::unique_ptr<cc::DisplayScheduler> scheduler(new cc::DisplayScheduler(m_renderViewHost->getUiThreadRunner(), 3));

    cc::RendererSettings softwareRendererSettings;
    m_display = new cc::Display(
        m_sharedBitmapManager,
        nullptr, // gpu_memory_buffer_manager,
        softwareRendererSettings,
        kRootFrameSinkId_1,
        backToBackBeginFrameSource, // begin_frame_source,
        std::unique_ptr<SoftwareOutputSurface>(m_outputSurface),
        std::move(scheduler), // scheduler ,
        nullptr // texture_mailbox_deleter
    );

    m_sink = new cc::DirectCompositorFrameSink(kRootFrameSinkId_1, //FrameSinkId
        surfaceManager, //SurfaceManager* surface_manager,
        m_display, //Display* display,
        nullptr, //scoped_refptr<ContextProvider> context_provider,
        nullptr, //scoped_refptr<ContextProvider> worker_context_provider,
        nullptr, //gpu::GpuMemoryBufferManager* gpu_memory_buffer_manager,
        m_sharedBitmapManager //SharedBitmapManager* shared_bitmap_manager
    );
    m_layerTreeHost->SetCompositorFrameSink(std::unique_ptr<cc::CompositorFrameSink>(m_sink));

    m_renderViewHost->getRenderThreadRunner()->PostTask(FROM_HERE,
        base::Bind(&RenderViewHost::onRenderWidgetCompositorInitFinishInRenderThread, base::Unretained(m_renderViewHost)));
}

void RenderWidgetCompositor::initOnRenderThread(RenderViewHost* reenderViewHost, base::SingleThreadTaskRunner* uiThreadRunner)
{
    gRenderPID = ::GetCurrentThreadId();

    m_renderViewHost = reenderViewHost;

    cc::LayerTreeSettings settings;
    settings.layer_transforms_should_scale_layer_contents = true;
    settings.gpu_rasterization_forced = false;
    settings.gpu_rasterization_enabled = true;
    settings.create_low_res_tiling = true;
    settings.can_use_lcd_text = false;
    settings.use_distance_field_text = false;
    settings.use_zero_copy = false;

    m_rasterWorkerPool = new RasterWorkerPool();
    m_rasterWorkerPool->Start(1, base::SimpleThread::Options());

    cc::LayerTreeHostInProcess::InitParams params;

    params.client = this;
    //     params.shared_bitmap_manager = m_sharedBitmapManager;
    //     params.gpu_memory_buffer_manager = nullptr;
    params.task_graph_runner = m_rasterWorkerPool->GetTaskGraphRunner();
    params.settings = &settings;
    params.main_task_runner = m_renderViewHost->getRenderThreadRunner(); // base::MessageLoop::current()->task_runner();
    m_animationHost = cc::AnimationHost::CreateMainInstance();
    params.mutator_host = m_animationHost.get();
    scoped_refptr<base::SingleThreadTaskRunner> uiThreadRunnerRefPtr(uiThreadRunner);
    m_layerTreeHost = cc::LayerTreeHostInProcess::CreateThreaded(uiThreadRunnerRefPtr, &params);
    setVisible(true);
}

void RenderWidgetCompositor::onHostResizedInUiThread(int width, int height)
{
    if (m_display) {
        m_display->SetVisible(true);
        m_display->Resize(gfx::Size(width, height));
    }

    if (m_outputSurface && m_outputSurface->software_device())
        m_outputSurface->software_device()->Resize(gfx::Size(width, height), 1);
}

void RenderWidgetCompositor::onHostResizedInRenderThread()
{
    OutputDebugStringA("RenderWidgetCompositor.onHostResizedInRenderThread\n");
    m_isSizing = true;

    do {
        SIZE size = m_renderViewHost->getWindowSizeLocked();
        if (m_size.cx == size.cx && m_size.cy == size.cy)
            break;
        m_size = size;

        if (m_layerTreeHost)
            m_layerTreeHost->GetLayerTree()->SetViewportSize(gfx::Size(size.cx, size.cy));
        m_renderViewHost->blinkPage()->fireResizeEvent(nullptr, WM_SIZE, 0, MAKELONG(size.cx, size.cy));

        m_renderViewHost->getUiThreadRunner()->PostTask(FROM_HERE,
            base::Bind(&RenderWidgetCompositor::onHostResizedInUiThread, base::Unretained(this), size.cx, size.cy));
    } while (true);

    m_isSizing = false;
}

// WebLayerTreeView implementation.
void RenderWidgetCompositor::setRootLayer(const blink::WebLayer& layer)
{
    scoped_refptr<cc::Layer> ccLayer((cc::Layer*)((&layer)->ccLayer()));
    m_layerTreeHost->GetLayerTree()->SetRootLayer(ccLayer);
}

void RenderWidgetCompositor::clearRootLayer()
{
    m_layerTreeHost->GetLayerTree()->SetRootLayer(scoped_refptr<cc::Layer>());
}

void RenderWidgetCompositor::setViewportSize(const WebSize& device_viewport_size)
{
    m_layerTreeHost->GetLayerTree()->SetViewportSize(gfx::Size(std::max(0, device_viewport_size.width), std::max(0, device_viewport_size.height)));
}

WebFloatPoint RenderWidgetCompositor::adjustEventPointForPinchZoom(const WebFloatPoint& point) const
{
    return point;
}

void RenderWidgetCompositor::setDeviceScaleFactor(float device_scale)
{
    m_layerTreeHost->GetLayerTree()->SetDeviceScaleFactor(device_scale);
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
    m_layerTreeHost->SetVisible(visible);

    //     if (visible)
    //         m_layerTreeHost->SetLayerTreeHostClientReady();
}

void RenderWidgetCompositor::setPageScaleFactorAndLimits(
    float page_scale_factor, float minimum, float maximum)
{
    m_layerTreeHost->GetLayerTree()->SetPageScaleFactorAndLimits(
        page_scale_factor, minimum, maximum);
}

void RenderWidgetCompositor::startPageScaleAnimation(
    const blink::WebPoint& destination,
    bool use_anchor,
    float new_page_scale,
    double duration_sec, bool is_smooth_scroll)
{
    base::TimeDelta duration = base::TimeDelta::FromMicroseconds(
        duration_sec * base::Time::kMicrosecondsPerSecond);
    m_layerTreeHost->GetLayerTree()->StartPageScaleAnimation(
        gfx::Vector2d(destination.x, destination.y),
        use_anchor,
        new_page_scale,
        duration);
}

void RenderWidgetCompositor::heuristicsForGpuRasterizationUpdated(
    bool matches_heuristics)
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
    m_layerTreeHost->SetNeedsUpdateLayers();
}

void RenderWidgetCompositor::didStopFlinging()
{
    m_layerTreeHost->DidStopFlinging();
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

cc::LayerSelectionBound ConvertWebSelectionBound(
    const WebSelection& web_selection,
    bool is_start)
{
    cc::LayerSelectionBound cc_bound;
    if (web_selection.isNone())
        return cc_bound;

    const blink::WebSelectionBound& web_bound = is_start ? web_selection.start() : web_selection.end();
    DCHECK(web_bound.layerId);
    cc_bound.type = gfx::SelectionBound::CENTER;
    if (web_selection.isRange()) {
        if (is_start) {
            cc_bound.type = web_bound.isTextDirectionRTL ? gfx::SelectionBound::RIGHT : gfx::SelectionBound::LEFT;
        } else {
            cc_bound.type = web_bound.isTextDirectionRTL ? gfx::SelectionBound::LEFT : gfx::SelectionBound::RIGHT;
        }
    }
    cc_bound.layer_id = web_bound.layerId;
    cc_bound.edge_top = gfx::Point(web_bound.edgeTopInLayer.x, web_bound.edgeTopInLayer.y);
    cc_bound.edge_bottom = gfx::Point(web_bound.edgeBottomInLayer.x, web_bound.edgeBottomInLayer.y);
    return cc_bound;
}

cc::LayerSelection ConvertWebSelection(const WebSelection& web_selection)
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
// cc::LayerTreeHostClient
void RenderWidgetCompositor::RequestNewOutputSurface()
{
}

void RenderWidgetCompositor::WillBeginMainFrame()
{
}

void RenderWidgetCompositor::BeginMainFrame(const cc::BeginFrameArgs& args)
{
    m_renderViewHost->blinkPage()->beginMainFrame();
}

void RenderWidgetCompositor::BeginMainFrameNotExpectedSoon()
{
}

void RenderWidgetCompositor::DidBeginMainFrame()
{
}

void RenderWidgetCompositor::UpdateLayerTreeHost()
{
    m_renderViewHost->blinkPage()->webViewImpl()->updateAllLifecyclePhases();
}

void RenderWidgetCompositor::initializeLayerTreeView()
{
    SIZE size = m_renderViewHost->windowSize();
    m_layerTreeHost->GetLayerTree()->SetViewportSize(gfx::Size(size.cx, size.cy));
}

void RenderWidgetCompositor::swapBuffers()
{
    ++m_pendingSwaps;
}

void RenderWidgetCompositor::firePaintEvent(HDC hdc, const RECT* paintRect)
{
    if (m_outputSurface && m_outputSurface->software_device()) {
        SoftwareDevice* device = (SoftwareDevice*)m_outputSurface->software_device();
        device->firePaintEvent(hdc, paintRect);
    }

    fireTimerEvent();
}

void RenderWidgetCompositor::fireTimerEvent()
{
    while (m_display && m_pendingSwaps >= 0) {
        m_display->DidReceiveSwapBuffersAck();
        --m_pendingSwaps;
    }
}

} // content