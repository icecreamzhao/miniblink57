/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebLayerTreeView_h
#define WebLayerTreeView_h

<<<<<<< HEAD
#include "WebBrowserControlsState.h"
#include "WebColor.h"
#include "WebCommon.h"
#include "WebCompositorMutatorClient.h"
#include "WebEventListenerProperties.h"
#include "WebFloatPoint.h"
#include "WebSize.h"

namespace cc {
class AnimationHost;
}
=======
#include "WebColor.h"
#include "WebCommon.h"
#include "WebFloatPoint.h"
#include "WebNonCopyable.h"
#include "WebPrivateOwnPtr.h"
#include "WebSize.h"
#include "WebTopControlsState.h"

class SkBitmap;
>>>>>>> miniblink49

namespace blink {

class WebCompositeAndReadbackAsyncCallback;
<<<<<<< HEAD
class WebLayer;
class WebLayoutAndPaintAsyncCallback;
struct WebPoint;
class WebSelection;
=======
class WebCompositorAnimationTimeline;
class WebLayer;
class WebLayoutAndPaintAsyncCallback;
struct WebPoint;
struct WebSelectionBound;
class WebSelection;
class WebWidget;
>>>>>>> miniblink49

class WebLayerTreeView {
public:
    virtual ~WebLayerTreeView() { }

    // Initialization and lifecycle --------------------------------------

    // Sets the root of the tree. The root is set by way of the constructor.
<<<<<<< HEAD
    virtual void setRootLayer(const WebLayer&) { }
    virtual void clearRootLayer() { }

    // TODO(loyso): This should use CompositorAnimationHost. crbug.com/584551
    virtual cc::AnimationHost* compositorAnimationHost() { return nullptr; }

    // View properties ---------------------------------------------------

    // Viewport size is given in physical pixels.
    virtual void setViewportSize(const WebSize& deviceViewportSize) { }
    virtual WebSize getViewportSize() const { return WebSize(); }

    virtual void setDeviceScaleFactor(float) { }

    // Sets the background color for the viewport.
    virtual void setBackgroundColor(WebColor) { }

    // Sets the background transparency for the viewport. The default is 'false'.
    virtual void setHasTransparentBackground(bool) { }

    // Sets whether this view is visible. In threaded mode, a view that is not
    // visible will not composite or trigger updateAnimations() or layout() calls
    // until it becomes visible.
    virtual void setVisible(bool) { }

    // Sets the current page scale factor and minimum / maximum limits. Both
    // limits are initially 1 (no page scale allowed).
    virtual void setPageScaleFactorAndLimits(float pageScaleFactor,
        float minimum,
        float maximum) { }

    // Starts an animation of the page scale to a target scale factor and scroll
    // offset.
    // If useAnchor is true, destination is a point on the screen that will remain
    // fixed for the duration of the animation.
    // If useAnchor is false, destination is the final top-left scroll position.
    virtual void startPageScaleAnimation(const WebPoint& destination,
        bool useAnchor,
        float newPageScale,
        double durationSec) { }

    // Returns true if the page scale animation had started.
    virtual bool hasPendingPageScaleAnimation() const { return false; }

    virtual void heuristicsForGpuRasterizationUpdated(bool) { }

    // Sets the amount that the browser controls are showing, from 0 (hidden) to 1
    // (fully shown).
    virtual void setBrowserControlsShownRatio(float) { }

    // Update browser controls permitted and current states
    virtual void updateBrowserControlsState(WebBrowserControlsState constraints,
        WebBrowserControlsState current,
        bool animate) { }

    // Set browser controls height. If |shrinkViewport| is set to true, then Blink
    // shrunk the viewport clip layers by the browser controls height.
    virtual void setBrowserControlsHeight(float height, bool shrinkViewport) { }

    // Flow control and scheduling ---------------------------------------

    // Indicates that blink needs a BeginFrame, but that nothing might actually be
    // dirty.
=======
    virtual void setRootLayer(const WebLayer&) = 0;
    virtual void clearRootLayer() = 0;

    virtual void attachCompositorAnimationTimeline(WebCompositorAnimationTimeline*) { }
    virtual void detachCompositorAnimationTimeline(WebCompositorAnimationTimeline*) { }

    // View properties ---------------------------------------------------

    virtual void setViewportSize(const WebSize& deviceViewportSize) = 0;
    // Gives the viewport size in physical device pixels.
    virtual WebSize deviceViewportSize() const = 0;

    virtual void setDeviceScaleFactor(float) = 0;
    virtual float deviceScaleFactor() const = 0;

    // Sets the background color for the viewport.
    virtual void setBackgroundColor(WebColor) = 0;

    // Sets the background transparency for the viewport. The default is 'false'.
    virtual void setHasTransparentBackground(bool) = 0;

    // Sets whether this view is visible. In threaded mode, a view that is not visible will not
    // composite or trigger updateAnimations() or layout() calls until it becomes visible.
    virtual void setVisible(bool) = 0;

    // Sets the current page scale factor and minimum / maximum limits. Both limits are initially 1 (no page scale allowed).
    virtual void setPageScaleFactorAndLimits(float pageScaleFactor, float minimum, float maximum) = 0;

    // Starts an animation of the page scale to a target scale factor and scroll offset.
    // If useAnchor is true, destination is a point on the screen that will remain fixed for the duration of the animation.
    // If useAnchor is false, destination is the final top-left scroll position.
    virtual void startPageScaleAnimation(const WebPoint& destination, bool useAnchor, float newPageScale, double durationSec) = 0;

    virtual void heuristicsForGpuRasterizationUpdated(bool) { }

    // Sets the amount that the top controls are showing, from 0 (hidden) to 1
    // (fully shown).
    virtual void setTopControlsShownRatio(float) { }

    // Update top controls permitted and current states
    virtual void updateTopControlsState(WebTopControlsState constraints, WebTopControlsState current, bool animate) { }

    // Set top controls height. If |shrinkViewport| is set to true, then Blink shrunk the viewport clip
    // layers by the top controls height.
    virtual void setTopControlsHeight(float height, bool shrinkViewport) { }

    // Flow control and scheduling ---------------------------------------

    // Indicates that an animation needs to be updated.
    virtual void setNeedsAnimate() = 0;

    // Indicates that blink needs a BeginFrame, but that nothing might actually be dirty.
>>>>>>> miniblink49
    virtual void setNeedsBeginFrame() { }

    // Indicates that blink needs a BeginFrame and to update compositor state.
    virtual void setNeedsCompositorUpdate() { }

    // Relays the end of a fling animation.
    virtual void didStopFlinging() { }

    // Run layout and paint of all pending document changes asynchronously.
<<<<<<< HEAD
    // The caller is resposible for keeping the WebLayoutAndPaintAsyncCallback
    // object alive until it is called.
    virtual void layoutAndPaintAsync(WebLayoutAndPaintAsyncCallback*) { }

    // The caller is responsible for keeping the
    // WebCompositeAndReadbackAsyncCallback object alive until it is called.
    virtual void compositeAndReadbackAsync(
        WebCompositeAndReadbackAsyncCallback*) { }
=======
    // The caller is resposible for keeping the WebLayoutAndPaintAsyncCallback object
    // alive until it is called.
    virtual void layoutAndPaintAsync(WebLayoutAndPaintAsyncCallback*) { }

    // The caller is responsible for keeping the WebCompositeAndReadbackAsyncCallback
    // object alive until it is called.
    virtual void compositeAndReadbackAsync(WebCompositeAndReadbackAsyncCallback*) { }

    // Blocks until the most recently composited frame has finished rendering on the GPU.
    // This can have a significant performance impact and should be used with care.
    virtual void finishAllRendering() = 0;
>>>>>>> miniblink49

    // Prevents updates to layer tree from becoming visible.
    virtual void setDeferCommits(bool deferCommits) { }

<<<<<<< HEAD
    // Identify key layers to the compositor when using the pinch virtual
    // viewport.
=======
    // Take responsiblity for this layer's animations, even if this layer hasn't yet
    // been added to the tree.
    virtual void registerForAnimations(WebLayer* layer) { }

    // Identify key layers to the compositor when using the pinch virtual viewport.
>>>>>>> miniblink49
    virtual void registerViewportLayers(
        const WebLayer* overscrollElasticityLayer,
        const WebLayer* pageScaleLayer,
        const WebLayer* innerViewportScrollLayer,
        const WebLayer* outerViewportScrollLayer) { }
    virtual void clearViewportLayers() { }

    // Used to update the active selection bounds.
<<<<<<< HEAD
    virtual void registerSelection(const WebSelection&) { }
    virtual void clearSelection() { }

    // Mutations are plumbed back to the layer tree via the mutator client.
    virtual void setMutatorClient(std::unique_ptr<WebCompositorMutatorClient>) { }

    // For when the embedder itself change scales on the page (e.g. devtools)
    // and wants all of the content at the new scale to be crisp.
    virtual void forceRecalculateRasterScales() { }

    // Input properties ---------------------------------------------------
    virtual void setEventListenerProperties(WebEventListenerClass,
        WebEventListenerProperties) {};
    virtual void setHaveScrollEventHandlers(bool) {};

    // Debugging / dangerous ---------------------------------------------

    virtual WebEventListenerProperties eventListenerProperties(
        WebEventListenerClass) const
    {
        return WebEventListenerProperties::Nothing;
    };
    virtual bool haveScrollEventHandlers() const { return false; };

=======
    // FIXME: Remove this overload when downstream consumers have been updated to use WebSelection, crbug.com/466672.
    virtual void registerSelection(const WebSelectionBound& start, const WebSelectionBound& end) { }
    virtual void registerSelection(const WebSelection&) { }
    virtual void clearSelection() { }

    // Debugging / dangerous ---------------------------------------------

>>>>>>> miniblink49
    virtual int layerTreeId() const { return 0; }

    // Toggles the FPS counter in the HUD layer
    virtual void setShowFPSCounter(bool) { }

    // Toggles the paint rects in the HUD layer
    virtual void setShowPaintRects(bool) { }

    // Toggles the debug borders on layers
    virtual void setShowDebugBorders(bool) { }

<<<<<<< HEAD
    // Toggles scroll bottleneck rects on the HUD layer
    virtual void setShowScrollBottleneckRects(bool) { }
=======
    // Toggles continuous painting
    virtual void setContinuousPaintingEnabled(bool) { }

    // Toggles scroll bottleneck rects on the HUD layer
    virtual void setShowScrollBottleneckRects(bool) { }

    // Move down Hud layer when qb aero effect enabled
    virtual void SetHudLayerTopInset(int inset) {}
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebLayerTreeView_h
