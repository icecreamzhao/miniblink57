/*
 * Copyright (C) 2009 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GraphicsLayerClient_h
#define GraphicsLayerClient_h

#include "platform/PlatformExport.h"
<<<<<<< HEAD
#include "platform/geometry/LayoutSize.h"
=======
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

class GraphicsContext;
class GraphicsLayer;
class IntRect;

enum GraphicsLayerPaintingPhaseFlags {
    GraphicsLayerPaintBackground = (1 << 0),
    GraphicsLayerPaintForeground = (1 << 1),
    GraphicsLayerPaintMask = (1 << 2),
    GraphicsLayerPaintOverflowContents = (1 << 3),
    GraphicsLayerPaintCompositedScroll = (1 << 4),
    GraphicsLayerPaintChildClippingMask = (1 << 5),
<<<<<<< HEAD
    GraphicsLayerPaintAncestorClippingMask = (1 << 6),
    GraphicsLayerPaintDecoration = (1 << 7),
    GraphicsLayerPaintAllWithOverflowClip = (GraphicsLayerPaintBackground | GraphicsLayerPaintForeground | GraphicsLayerPaintMask | GraphicsLayerPaintDecoration)
=======
    GraphicsLayerPaintAllWithOverflowClip = (GraphicsLayerPaintBackground | GraphicsLayerPaintForeground | GraphicsLayerPaintMask)
>>>>>>> miniblink49
};
typedef unsigned GraphicsLayerPaintingPhase;

enum {
    LayerTreeNormal = 0,
<<<<<<< HEAD
    // Dump extra debugging info like layer addresses.
    LayerTreeIncludesDebugInfo = 1 << 0,
    LayerTreeIncludesPaintInvalidations = 1 << 1,
    LayerTreeIncludesPaintingPhases = 1 << 2,
    LayerTreeIncludesRootLayer = 1 << 3,
    LayerTreeIncludesClipAndScrollParents = 1 << 4,
    LayerTreeIncludesCompositingReasons = 1 << 5,
    // Outputs all layers as a layer tree. The default is output children
    // (excluding the root) as a layer list, in paint (preorder) order.
    OutputAsLayerTree = 1 << 6,
=======
    LayerTreeIncludesDebugInfo = 1 << 0, // Dump extra debugging info like layer addresses.
    LayerTreeIncludesPaintInvalidationRects = 1 << 1,
    LayerTreeIncludesPaintingPhases = 1 << 2,
    LayerTreeIncludesRootLayer = 1 << 3,
    LayerTreeIncludesClipAndScrollParents = 1 << 4,
    LayerTreeIncludesScrollBlocksOn = 1 << 5,
    LayerTreeIncludesPaintInvalidationObjects = 1 << 6,
    LayerTreeIncludesCompositingReasons = 1 << 7,
>>>>>>> miniblink49
};
typedef unsigned LayerTreeFlags;

class PLATFORM_EXPORT GraphicsLayerClient {
public:
<<<<<<< HEAD
    virtual ~GraphicsLayerClient() { }

    virtual void invalidateTargetElementForTesting() { }

    virtual IntRect computeInterestRect(
        const GraphicsLayer*,
        const IntRect& previousInterestRect) const = 0;
    virtual LayoutSize subpixelAccumulation() const { return LayoutSize(); }
    // Returns whether the client needs to be repainted with respect to the given
    // graphics layer.
    virtual bool needsRepaint(const GraphicsLayer&) const = 0;
    virtual void paintContents(const GraphicsLayer*,
        GraphicsContext&,
        GraphicsLayerPaintingPhase,
        const IntRect& interestRect) const = 0;

    virtual bool isTrackingRasterInvalidations() const { return false; }

    virtual String debugName(const GraphicsLayer*) const = 0;

#if DCHECK_IS_ON()
=======
    virtual ~GraphicsLayerClient() {}

    // Callback for when compositor animation started.
    virtual void notifyAnimationStarted(const GraphicsLayer*, double monotonicTime, int group) { }

    virtual void paintContents(const GraphicsLayer*, GraphicsContext&, GraphicsLayerPaintingPhase, const IntRect& inClip) = 0;
    virtual bool isTrackingPaintInvalidations() const { return false; }

    virtual String debugName(const GraphicsLayer*) = 0;

#if ENABLE(ASSERT)
>>>>>>> miniblink49
    // CompositedLayerMapping overrides this to verify that it is not
    // currently painting contents. An ASSERT fails, if it is.
    // This is executed in GraphicsLayer construction and destruction
    // to verify that we don't create or destroy GraphicsLayers
    // while painting.
    virtual void verifyNotPainting() { }
#endif
};

} // namespace blink

#endif // GraphicsLayerClient_h
