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

#ifndef WebContentLayerClient_h
#define WebContentLayerClient_h

<<<<<<< HEAD
#include "WebCommon.h"

namespace gfx {
class Rect;
}

namespace blink {

class WebDisplayItemList;
=======
#include "WebCanvas.h"
#include "WebCommon.h"

namespace blink {

class WebDisplayItemList;
struct WebRect;
>>>>>>> miniblink49

class BLINK_PLATFORM_EXPORT WebContentLayerClient {
public:
    enum PaintingControlSetting {
<<<<<<< HEAD
        // Returns the last PaintArtifact produced.
        PaintDefaultBehavior,
        // Paints the content to simulate the behavior of FrameView::paintTree().
        PaintDefaultBehaviorForTest,
        // Puts the GraphicsContext in disabled mode and disables display item
        // construction in PaintController.
        DisplayListConstructionDisabled,
        DisplayListCachingDisabled,
        DisplayListPaintingDisabled,
        SubsequenceCachingDisabled,
        PartialInvalidation
    };

    // The paintable region is the rectangular region, within the bounds of the
    // layer this client paints, that the client is capable of painting via
    // paintContents().  Calling paintContents will return a WebDisplayitemList
    // that is guaranteed valid only within this region.  In particular, this is
    // used to represent the interest rect in Blink.
    virtual gfx::Rect paintableRegion() = 0;
=======
        PaintDefaultBehavior,
        DisplayListConstructionDisabled,
        DisplayListCachingDisabled,
        DisplayListPaintingDisabled
    };

    // Paints the content area for the layer, typically dirty rects submitted
    // through WebContentLayer::setNeedsDisplay, submitting drawing commands
    // through the WebCanvas.
    // The canvas is already clipped to the |clip| rect.
    // The |PaintingControlSetting| enum controls painting to isolate different components in performance tests.
    virtual void paintContents(WebCanvas*, const WebRect& clip, PaintingControlSetting = PaintDefaultBehavior) = 0;
>>>>>>> miniblink49

    // Paints the content area for the layer, typically dirty rects submitted
    // through WebContentLayer::setNeedsDisplayInRect, submitting drawing commands
    // to populate the WebDisplayItemList.
<<<<<<< HEAD
    // The |PaintingControlSetting| enum controls painting to isolate different
    // components in performance tests.
    virtual void paintContents(WebDisplayItemList*,
        PaintingControlSetting = PaintDefaultBehavior)
        = 0;

    // Returns an estimate of the current memory usage within this object,
    // excluding memory shared with painting artifacts (i.e.,
    // WebDisplayItemList). Should be invoked after paintContents, so that the
    // result includes data cached internally during painting.
    virtual size_t approximateUnsharedMemoryUsage() const { return 0; }
=======
    // The |clip| rect defines the region of interest. The resulting WebDisplayItemList should contain
    // sufficient content to correctly paint the rect, but may also contain other content. The result
    // will be clipped on playback.
    // The |PaintingControlSetting| enum controls painting to isolate different components in performance tests.
    // Currently the DisplayListConstructionDisabled does nothing.
    virtual void paintContents(
        WebDisplayItemList*,
        const WebRect& clip,
        PaintingControlSetting = PaintDefaultBehavior) = 0;
>>>>>>> miniblink49

protected:
    virtual ~WebContentLayerClient() { }
};

} // namespace blink

#endif // WebContentLayerClient_h
