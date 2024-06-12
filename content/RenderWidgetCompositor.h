// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef orig_chrome_content_RenderWidgetCompositor_h
#define orig_chrome_content_RenderWidgetCompositor_h

#include "base/callback.h"
#include "cc/surfaces/surface_factory_client.h"
#include "cc/surfaces/surface_manager.h"
#include "cc/surfaces/surface_id_allocator.h"
#include "cc/trees/layer_tree_host.h"
#include "cc/trees/layer_tree_host_client.h"
#include "cc/trees/layer_tree_host_single_thread_client.h"
#include "cc/trees/layer_tree_settings.h"
#include "cc/input/input_handler.h"
#include "third_party/WebKit/public/platform/WebLayerTreeView.h"
#include "third_party/skia/include/core/SkBitmap.h"

namespace cc {
class InputHandler;
class Layer;
class LayerTreeHost;
class TaskGraphRunner;
class SoftwareOutputDevice;
class RendererSettings;
class SharedBitmapManager;
class OnscreenDisplayClient;
class SurfaceDisplayOutputSurface;
class SurfaceIdAllocator;
class SurfaceFactory;
class LayerTreeHostInProcess;
class AnimationHost;
class Display;
class DirectCompositorFrameSink;
}

namespace blink {
class CompositorAnimationTimeline;
}

namespace content {

class WebSharedBitmapManager;
class SoftwareOutputSurface;
class WebSharedBitmapManager;
class RenderViewHost;
class SoftwareOutputDevice;
class RasterWorkerPool;
class WebPageOcBridge;
class ChildGpuMemoryBufferManager;

class RenderWidgetCompositor
    : public blink::WebLayerTreeView
    , public cc::LayerTreeHostClient
    , public cc::SurfaceFactoryClient
    , public cc::InputHandlerClient {
public:
    RenderWidgetCompositor(WebPageOcBridge* webPageOcBridge, bool isUiThreadIsolate);
    ~RenderWidgetCompositor();

    void init(bool isUiThreadIsolate);
    void destroy();

    void onHostResized(int width, int height);
    void onHostResizedInUiThread();
    void setHWND(HWND hWnd);
    HDC getHdcLocked();
    void releaseHdc();

    void swapBuffers();
    void onSwapBuffers();
    void initOnUiThread();
    //////////////////////////////////////////////////////////////////////////
    // WebLayerTreeView implementation.
    virtual void setRootLayer(const blink::WebLayer& layer) override;
    virtual void clearRootLayer() override;

    virtual cc::AnimationHost* compositorAnimationHost() override;
    /*virtual*/ void attachCompositorAnimationTimeline(blink::CompositorAnimationTimeline* compositorTimeline) /*override*/;
    /*virtual*/ void detachCompositorAnimationTimeline(blink::CompositorAnimationTimeline* compositorTimeline) /*override*/;
    virtual void setViewportSize(const blink::WebSize& deviceViewportSize) override;
    virtual blink::WebFloatPoint adjustEventPointForPinchZoom(const blink::WebFloatPoint& point) const;
    virtual void setDeviceScaleFactor(float deviceScale) override;
    virtual void setBackgroundColor(blink::WebColor color) override;
    virtual void setHasTransparentBackground(bool transparent) override;
    virtual void setVisible(bool visible) override;
    virtual void setPageScaleFactorAndLimits(float page_scale_factor, float minimum, float maximum) override;
    virtual void startPageScaleAnimation(const blink::WebPoint& destination, bool useAnchor, float newPageScale, double durationSec) override;
    virtual void heuristicsForGpuRasterizationUpdated(bool matches_heuristics) override;
    /*virtual*/ void setNeedsAnimate() /*override*/;
    virtual void setNeedsBeginFrame() override;
    virtual void setNeedsCompositorUpdate() override;
    virtual void didStopFlinging() override;
    virtual void layoutAndPaintAsync(blink::WebLayoutAndPaintAsyncCallback* callback) override;
    virtual void compositeAndReadbackAsync(blink::WebCompositeAndReadbackAsyncCallback* callback) override;
    virtual void setDeferCommits(bool defer_commits) override;
    /*virtual*/ void registerForAnimations(blink::WebLayer* layer) /*override*/;
    virtual void registerViewportLayers(
        const blink::WebLayer* overscrollElasticityLayer,
        const blink::WebLayer* pageScaleLayer,
        const blink::WebLayer* innerViewportScrollLayer,
        const blink::WebLayer* outerViewportScrollLayer) override;
    virtual void clearViewportLayers() override;
    virtual void registerSelection(const blink::WebSelection& selection) override;
    virtual void clearSelection() override;
    virtual int layerTreeId() const override;

    /*virtual*/ blink::WebSize deviceViewportSize() const /*override*/;
    /*virtual*/ float deviceScaleFactor() const /*override*/;
    /*virtual*/ void finishAllRendering() /*override*/;

    //////////////////////////////////////////////////////////////////////////
    // LayerTreeHostSingleThreadClient
    //   virtual void DidPostSwapBuffers() override {}
    //   virtual void DidAbortSwapBuffers() override {}
    //   virtual void DidCompleteSwapBuffers() override {}
    //////////////////////////////////////////////////////////////////////////
    // cc::LayerTreeHostClient
    virtual void WillBeginMainFrame() override;
    // Marks finishing compositing-related tasks on the main thread. In threaded
    // mode, this corresponds to DidCommit().
    virtual void BeginMainFrame(const cc::BeginFrameArgs& args) override;
    virtual void BeginMainFrameNotExpectedSoon() override;
    virtual void DidBeginMainFrame() override;
    /*virtual*/ void Layout() /*override*/;
    virtual void ApplyViewportDeltas(
        const gfx::Vector2dF& inner_delta,
        const gfx::Vector2dF& outer_delta,
        const gfx::Vector2dF& elastic_overscroll_delta,
        float page_scale,
        float top_controls_delta) override { }

    virtual void RequestNewCompositorFrameSink() override;
    virtual void DidInitializeCompositorFrameSink() override;
    virtual void DidFailToInitializeCompositorFrameSink() override;
    virtual void WillCommit() override;
    virtual void DidCommit() override;
    virtual void DidCommitAndDrawFrame() override;
    /*virtual*/ void DidCompleteSwapBuffers() /*override*/;
//     virtual void RecordFrameTimingEvents(
//         scoped_ptr<cc::FrameTimingTracker::CompositeTimingSet> compositeEvents,
//         scoped_ptr<cc::FrameTimingTracker::MainFrameTimingSet> mainFrameEvents) override;

    virtual void UpdateLayerTreeHost() override;
    virtual void DidReceiveCompositorFrameAck() override;

    virtual void DidCompletePageScaleAnimation() override { }

    /*virtual*/ void SendBeginFramesToChildren(const cc::BeginFrameArgs& args) /*override*/ { }

    //////////////////////////////////////////////////////////////////////////
    void initializeLayerTreeView();

    void firePaintEvent(HDC hdc, const RECT& paintRect);
    bool fireWheelEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    //////////////////////////////////////////////////////////////////////////

    // cc::SurfaceFactoryClient implementation
    virtual void ReturnResources(const cc::ReturnedResourceArray& resources) override;
    virtual void SetBeginFrameSource(cc::BeginFrameSource* begin_frame_source) override;

    // cc::InputHandlerClient implementation.
    void WillShutdown() override;
    void Animate(base::TimeTicks time) override;
    void MainThreadHasStoppedFlinging() override;
    void ReconcileElasticOverscrollAndRootScroll() override;
    void UpdateRootLayerStateForSynchronousInputHandler(
        const gfx::ScrollOffset& total_scroll_offset,
        const gfx::ScrollOffset& max_scroll_offset,
        const gfx::SizeF& scrollable_size,
        float page_scale_factor,
        float min_page_scale_factor,
        float max_page_scale_factor) override;
    void DeliverInputForBeginFrame() override;

private:
    void initStep1OnUiThread(bool isUiThreadIsolate);

    gfx::Size m_size;

    WebPageOcBridge* m_webPageOcBridge;
    cc::LayerTreeHostInProcess* m_layerTreeHost;
    cc::AnimationHost* m_animationHost;
    SoftwareOutputDevice* m_softwareOutputDevice;

    HWND m_hWnd;

    cc::Display* m_display;
    cc::CompositorFrameSink* m_sink;
    cc::InputHandler* m_inputHandler;
    int m_pendingSwaps;

    //scoped_refptr<ContextProviderCommandBuffer> m_shareWorkerContextProvider;

    cc::SurfaceIdAllocator* m_idAllocator;
    //std::unique_ptr<cc::SurfaceDisplayOutputSurface> m_displayOutputSurface;
    //std::unique_ptr<cc::OnscreenDisplayClient> m_displayClient;
};

} // content

#endif // ONTENT_RENDERER_GPU_RENDER_WIDGET_COMPOSITOR_H_