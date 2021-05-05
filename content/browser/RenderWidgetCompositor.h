// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_RENDERER_GPU_RENDER_WIDGET_COMPOSITOR_H_
#define CONTENT_RENDERER_GPU_RENDER_WIDGET_COMPOSITOR_H_

#include "base/callback.h"
#include "base/memory/weak_ptr.h"
#include "base/time/time.h"
#include "base/values.h"
//#include "cc/input/top_controls_state.h"
#include "cc/trees/layer_tree_host.h"
#include "cc/trees/layer_tree_host_client.h"
#include "cc/trees/layer_tree_host_single_thread_client.h"
#include "cc/trees/layer_tree_settings.h"
#include "third_party/WebKit/Source/core/animation/AnimationTimeline.h"
#include "third_party/WebKit/public/platform/WebLayerTreeView.h"
#include "third_party/skia/include/core/SkBitmap.h"

namespace base {
class SingleThreadTaskRunner;
}

namespace cc {
class InputHandler;
class Layer;
class LayerTreeHost;
class DirectCompositorFrameSink;
class Display;
}

namespace content {

class BrowserCompositorOutputSurface;
class SoftwareOutputSurface;
class WebSharedBitmapManager;
class RenderViewHost;
class BrowserSoftwareOutputDevice;
class RasterWorkerPool;
class SynchronousCompositorFrameSink;

class RenderWidgetCompositor
    : public blink::WebLayerTreeView,
      public cc::LayerTreeHostClient {
public:
    RenderWidgetCompositor();

    void initOnUiThread();
    void initOnRenderThread(RenderViewHost* reenderViewHost, base::SingleThreadTaskRunner* uiThreadRunner);

    void onHostResizedInRenderThread();
    void onHostResizedInUiThread(int width, int height);
    void swapBuffers();
    //////////////////////////////////////////////////////////////////////////
    // WebLayerTreeView implementation.
    virtual void setRootLayer(const blink::WebLayer& layer) override;
    virtual void clearRootLayer() override;
    virtual void setViewportSize(const blink::WebSize& device_viewport_size) override;
    virtual blink::WebFloatPoint adjustEventPointForPinchZoom(
        const blink::WebFloatPoint& point) const;
    virtual void setDeviceScaleFactor(float device_scale) override;
    virtual void setBackgroundColor(blink::WebColor color) override;
    virtual void setHasTransparentBackground(bool transparent) override;
    virtual void setVisible(bool visible) override;
    virtual void setPageScaleFactorAndLimits(float page_scale_factor,
        float minimum,
        float maximum) override;
    virtual void startPageScaleAnimation(const blink::WebPoint& destination,
        bool use_anchor,
        float new_page_scale,
        double duration_sec, bool is_smooth_scroll) /*override*/;
    virtual void heuristicsForGpuRasterizationUpdated(bool matches_heuristics) override;
    virtual void setNeedsAnimate() /*override*/;
    virtual void setNeedsBeginFrame() override;
    virtual void setNeedsCompositorUpdate() override;
    virtual void didStopFlinging() override;
    virtual void layoutAndPaintAsync(
        blink::WebLayoutAndPaintAsyncCallback* callback) override;
    virtual void compositeAndReadbackAsync(
        blink::WebCompositeAndReadbackAsyncCallback* callback) override;
    virtual void setDeferCommits(bool defer_commits) override;

    virtual void registerViewportLayers(
        const blink::WebLayer* overscrollElasticityLayer,
        const blink::WebLayer* pageScaleLayer,
        const blink::WebLayer* innerViewportScrollLayer,
        const blink::WebLayer* outerViewportScrollLayer) override;
    virtual void clearViewportLayers() override;
    virtual void registerSelection(const blink::WebSelection& selection) override;
    virtual void clearSelection() override;
    virtual int layerTreeId() const override;

    // cc::LayerTreeHostClient
    virtual void WillBeginMainFrame() override;
    // Marks finishing compositing-related tasks on the main thread. In threaded
    // mode, this corresponds to DidCommit().
    virtual void BeginMainFrame(const cc::BeginFrameArgs& args) override;
    virtual void BeginMainFrameNotExpectedSoon() override;
    virtual void DidBeginMainFrame() override;
    //virtual void Layout() override;
    virtual void ApplyViewportDeltas(
        const gfx::Vector2dF& inner_delta,
        const gfx::Vector2dF& outer_delta,
        const gfx::Vector2dF& elastic_overscroll_delta,
        float page_scale,
        float top_controls_delta) override { }

    virtual void RequestNewOutputSurface() /*override*/;
    virtual void DidInitializeOutputSurface() /*override*/ { }
    virtual void DidFailToInitializeOutputSurface() /*override*/ { }
    virtual void WillCommit() override { }
    virtual void DidCommit() override { }
    virtual void DidCommitAndDrawFrame() /*override*/ { }
    virtual void DidCompleteSwapBuffers() /*override*/ { }
    //   virtual void RecordFrameTimingEvents(
    //     scoped_ptr<cc::FrameTimingTracker::CompositeTimingSet> composite_events,
    //     scoped_ptr<cc::FrameTimingTracker::MainFrameTimingSet> main_frame_events) override {}

    virtual void RequestNewCompositorFrameSink() override {};
    virtual void DidInitializeCompositorFrameSink() override {};
    virtual void DidFailToInitializeCompositorFrameSink() override {};
    virtual void DidReceiveCompositorFrameAck() override {};

    virtual void DidCompletePageScaleAnimation() override { }

    //virtual void SendBeginFramesToChildren(const cc::BeginFrameArgs& args) override {}

    virtual void UpdateLayerTreeHost() override;

    //////////////////////////////////////////////////////////////////////////
    void initializeLayerTreeView();

    void firePaintEvent(HDC hdc, const RECT* paintRect);
    void fireTimerEvent();
    //////////////////////////////////////////////////////////////////////////

    bool isResizing() const
    {
        return m_isSizing;
    }

private:
    bool m_isSizing;
    std::unique_ptr<cc::LayerTreeHost> m_layerTreeHost;
    cc::Display* m_display;
    cc::DirectCompositorFrameSink* m_sink;
    SoftwareOutputSurface* m_outputSurface;
    std::unique_ptr<cc::AnimationHost> m_animationHost;

    WebSharedBitmapManager* m_sharedBitmapManager;
    RasterWorkerPool* m_rasterWorkerPool;

    base::MessageLoop* m_uiThread;
    RenderViewHost* m_renderViewHost;

    SIZE m_size;

    int m_pendingSwaps;
};

} // content

#endif // ONTENT_RENDERER_GPU_RENDER_WIDGET_COMPOSITOR_H_