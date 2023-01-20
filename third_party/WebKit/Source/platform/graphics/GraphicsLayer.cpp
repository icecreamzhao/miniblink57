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

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/graphics/GraphicsLayer.h"

#include "SkImageFilter.h"
#include "SkMatrix44.h"
<<<<<<< HEAD
#include "base/trace_event/trace_event_argument.h"
#include "cc/layers/layer.h"
#include "platform/DragImage.h"
#include "platform/geometry/FloatRect.h"
#include "platform/geometry/LayoutRect.h"
#include "platform/geometry/Region.h"
#include "platform/graphics/BitmapImage.h"
#include "platform/graphics/CompositorFilterOperations.h"
#include "platform/graphics/FirstPaintInvalidationTracking.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/Image.h"
#include "platform/graphics/LinkHighlight.h"
#include "platform/graphics/paint/DrawingRecorder.h"
#include "platform/graphics/paint/PaintController.h"
#include "platform/graphics/paint/RasterInvalidationTracking.h"
#include "platform/instrumentation/tracing/TraceEvent.h"
#include "platform/json/JSONValues.h"
#include "platform/scroll/ScrollableArea.h"
#include "platform/text/TextStream.h"
#include "public/platform/Platform.h"
#include "public/platform/WebCompositorSupport.h"
#include "public/platform/WebFloatPoint.h"
#include "public/platform/WebFloatRect.h"
=======
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "platform/geometry/FloatRect.h"
#include "platform/geometry/LayoutRect.h"
#include "platform/graphics/FirstPaintInvalidationTracking.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/GraphicsLayerFactory.h"
#include "platform/graphics/Image.h"
#include "platform/graphics/filters/SkiaImageFilterBuilder.h"
#include "platform/graphics/paint/DisplayItemList.h"
#include "platform/graphics/paint/DrawingRecorder.h"
#include "platform/scroll/ScrollableArea.h"
#include "platform/text/TextStream.h"
#include "public/platform/Platform.h"
#include "public/platform/WebCompositorAnimation.h"
#include "public/platform/WebCompositorSupport.h"
#include "public/platform/WebFilterOperations.h"
#include "public/platform/WebFloatPoint.h"
#include "public/platform/WebFloatRect.h"
#include "public/platform/WebGraphicsLayerDebugInfo.h"
>>>>>>> miniblink49
#include "public/platform/WebLayer.h"
#include "public/platform/WebPoint.h"
#include "public/platform/WebSize.h"
#include "wtf/CurrentTime.h"
#include "wtf/HashMap.h"
#include "wtf/HashSet.h"
<<<<<<< HEAD
#include "wtf/MathExtras.h"
#include "wtf/PtrUtil.h"
#include "wtf/text/StringUTF8Adaptor.h"
#include "wtf/text/WTFString.h"
#include <algorithm>
#include <cmath>
#include <memory>
#include <utility>
=======
#include "wtf/text/WTFString.h"
#include <algorithm>
>>>>>>> miniblink49

#ifndef NDEBUG
#include <stdio.h>
#endif

namespace blink {

<<<<<<< HEAD
template class RasterInvalidationTrackingMap<const GraphicsLayer>;
static RasterInvalidationTrackingMap<const GraphicsLayer>&
rasterInvalidationTrackingMap()
{
    DEFINE_STATIC_LOCAL(RasterInvalidationTrackingMap<const GraphicsLayer>, map,
        ());
    return map;
}

std::unique_ptr<GraphicsLayer> GraphicsLayer::create(
    GraphicsLayerClient* client)
{
    return WTF::wrapUnique(new GraphicsLayer(client));
=======
struct PaintInvalidationTrackingInfo {
    Vector<FloatRect> invalidationRects;
    Vector<String> invalidationObjects;
};

typedef HashMap<const GraphicsLayer*, PaintInvalidationTrackingInfo> PaintInvalidationTrackingMap;
static PaintInvalidationTrackingMap& paintInvalidationTrackingMap()
{
    DEFINE_STATIC_LOCAL(PaintInvalidationTrackingMap, map, ());
    return map;
}

PassOwnPtr<GraphicsLayer> GraphicsLayer::create(GraphicsLayerFactory* factory, GraphicsLayerClient* client)
{
    return factory->createGraphicsLayer(client);
>>>>>>> miniblink49
}

GraphicsLayer::GraphicsLayer(GraphicsLayerClient* client)
    : m_client(client)
    , m_backgroundColor(Color::transparent)
    , m_opacity(1)
    , m_blendMode(WebBlendModeNormal)
<<<<<<< HEAD
=======
    , m_scrollBlocksOn(WebScrollBlocksOnNone)
>>>>>>> miniblink49
    , m_hasTransformOrigin(false)
    , m_contentsOpaque(false)
    , m_shouldFlattenTransform(true)
    , m_backfaceVisibility(true)
<<<<<<< HEAD
=======
    , m_masksToBounds(false)
>>>>>>> miniblink49
    , m_drawsContent(false)
    , m_contentsVisible(true)
    , m_isRootForIsolatedGroup(false)
    , m_hasScrollParent(false)
    , m_hasClipParent(false)
<<<<<<< HEAD
    , m_painted(false)
    , m_isTrackingRasterInvalidations(client && client->isTrackingRasterInvalidations())
=======
>>>>>>> miniblink49
    , m_paintingPhase(GraphicsLayerPaintAllWithOverflowClip)
    , m_parent(0)
    , m_maskLayer(0)
    , m_contentsClippingMaskLayer(0)
<<<<<<< HEAD
    , m_paintCount(0)
    , m_contentsLayer(0)
    , m_contentsLayerId(0)
    , m_scrollableArea(nullptr)
    , m_renderingContext3d(0)
    , m_colorBehavior(ColorBehavior::transformToGlobalTarget())
    , m_hasPreferredRasterBounds(false)
{
#if DCHECK_IS_ON()
=======
    , m_replicaLayer(0)
    , m_replicatedLayer(0)
    , m_paintCount(0)
    , m_contentsLayer(0)
    , m_contentsLayerId(0)
    , m_scrollableArea(0)
    , m_3dRenderingContext(0)
{
#if ENABLE(ASSERT)
>>>>>>> miniblink49
    if (m_client)
        m_client->verifyNotPainting();
#endif

<<<<<<< HEAD
    // In true color mode, no inputs are adjusted, and all colors are converted
    // at rasterization time.
    if (RuntimeEnabledFeatures::trueColorRenderingEnabled())
        m_colorBehavior = ColorBehavior::tag();

    m_contentLayerDelegate = WTF::makeUnique<ContentLayerDelegate>(this);
    m_layer = Platform::current()->compositorSupport()->createContentLayer(
        m_contentLayerDelegate.get());
    m_layer->layer()->setDrawsContent(m_drawsContent && m_contentsVisible);
    m_layer->layer()->setLayerClient(this);
=======
    m_contentLayerDelegate = adoptPtr(new ContentLayerDelegate(this));
    m_layer = adoptPtr(Platform::current()->compositorSupport()->createContentLayer(m_contentLayerDelegate.get()));
    m_layer->layer()->setDrawsContent(m_drawsContent && m_contentsVisible);
    m_layer->layer()->setWebLayerClient(this);
    m_layer->setAutomaticallyComputeRasterScale(true);
>>>>>>> miniblink49
}

GraphicsLayer::~GraphicsLayer()
{
    for (size_t i = 0; i < m_linkHighlights.size(); ++i)
        m_linkHighlights[i]->clearCurrentGraphicsLayer();
    m_linkHighlights.clear();

<<<<<<< HEAD
#if DCHECK_IS_ON()
=======
#if ENABLE(ASSERT)
>>>>>>> miniblink49
    if (m_client)
        m_client->verifyNotPainting();
#endif

<<<<<<< HEAD
    removeAllChildren();
    removeFromParent();

    rasterInvalidationTrackingMap().remove(this);
    DCHECK(!m_parent);
}

LayoutRect GraphicsLayer::visualRect() const
{
    LayoutRect bounds = LayoutRect(FloatPoint(), size());
    bounds.move(offsetFromLayoutObjectWithSubpixelAccumulation());
    return bounds;
}

void GraphicsLayer::setHasWillChangeTransformHint(bool hasWillChangeTransform)
{
    m_layer->layer()->setHasWillChangeTransformHint(hasWillChangeTransform);
}

void GraphicsLayer::setPreferredRasterBounds(const IntSize& bounds)
{
    m_preferredRasterBounds = bounds;
    m_hasPreferredRasterBounds = true;
    m_layer->layer()->setPreferredRasterBounds(bounds);
}

void GraphicsLayer::clearPreferredRasterBounds()
{
    m_preferredRasterBounds = IntSize();
    m_hasPreferredRasterBounds = false;
    m_layer->layer()->clearPreferredRasterBounds();
=======
    if (m_replicaLayer)
        m_replicaLayer->setReplicatedLayer(0);

    if (m_replicatedLayer)
        m_replicatedLayer->setReplicatedByLayer(0);

    removeAllChildren();
    removeFromParent();

    resetTrackedPaintInvalidations();
    ASSERT(!m_parent);
>>>>>>> miniblink49
}

void GraphicsLayer::setParent(GraphicsLayer* layer)
{
<<<<<<< HEAD
#if DCHECK_IS_ON()
    DCHECK(!layer || !layer->hasAncestor(this));
#endif
    m_parent = layer;
}

#if DCHECK_IS_ON()
=======
    ASSERT(!layer || !layer->hasAncestor(this));
    m_parent = layer;
}

#if ENABLE(ASSERT)
>>>>>>> miniblink49

bool GraphicsLayer::hasAncestor(GraphicsLayer* ancestor) const
{
    for (GraphicsLayer* curr = parent(); curr; curr = curr->parent()) {
        if (curr == ancestor)
            return true;
    }

    return false;
}

#endif

bool GraphicsLayer::setChildren(const GraphicsLayerVector& newChildren)
{
    // If the contents of the arrays are the same, nothing to do.
    if (newChildren == m_children)
        return false;

    removeAllChildren();

    size_t listSize = newChildren.size();
    for (size_t i = 0; i < listSize; ++i)
        addChildInternal(newChildren[i]);

    updateChildList();

    return true;
}

void GraphicsLayer::addChildInternal(GraphicsLayer* childLayer)
{
<<<<<<< HEAD
    DCHECK_NE(childLayer, this);
=======
    ASSERT(childLayer != this);
>>>>>>> miniblink49

    if (childLayer->parent())
        childLayer->removeFromParent();

    childLayer->setParent(this);
<<<<<<< HEAD
    m_children.push_back(childLayer);
=======
    m_children.append(childLayer);
>>>>>>> miniblink49

    // Don't call updateChildList here, this function is used in cases where it
    // should not be called until all children are processed.
}

void GraphicsLayer::addChild(GraphicsLayer* childLayer)
{
    addChildInternal(childLayer);
    updateChildList();
}

<<<<<<< HEAD
void GraphicsLayer::addChildBelow(GraphicsLayer* childLayer,
    GraphicsLayer* sibling)
{
    DCHECK_NE(childLayer, this);
=======
void GraphicsLayer::addChildBelow(GraphicsLayer* childLayer, GraphicsLayer* sibling)
{
    ASSERT(childLayer != this);
>>>>>>> miniblink49
    childLayer->removeFromParent();

    bool found = false;
    for (unsigned i = 0; i < m_children.size(); i++) {
        if (sibling == m_children[i]) {
            m_children.insert(i, childLayer);
            found = true;
            break;
        }
    }

    childLayer->setParent(this);

    if (!found)
<<<<<<< HEAD
        m_children.push_back(childLayer);
=======
        m_children.append(childLayer);
>>>>>>> miniblink49

    updateChildList();
}

void GraphicsLayer::removeAllChildren()
{
    while (!m_children.isEmpty()) {
<<<<<<< HEAD
        GraphicsLayer* curLayer = m_children.back();
        DCHECK(curLayer->parent());
=======
        GraphicsLayer* curLayer = m_children.last();
        ASSERT(curLayer->parent());
>>>>>>> miniblink49
        curLayer->removeFromParent();
    }
}

void GraphicsLayer::removeFromParent()
{
    if (m_parent) {
        // We use reverseFind so that removeAllChildren() isn't n^2.
        m_parent->m_children.remove(m_parent->m_children.reverseFind(this));
        setParent(0);
    }

    platformLayer()->removeFromParent();
}

<<<<<<< HEAD
void GraphicsLayer::setOffsetFromLayoutObject(
    const IntSize& offset,
    ShouldSetNeedsDisplay shouldSetNeedsDisplay)
=======
void GraphicsLayer::setReplicatedByLayer(GraphicsLayer* layer)
{
    // FIXME: this could probably be a full early exit.
    if (m_replicaLayer != layer) {
        if (m_replicaLayer)
            m_replicaLayer->setReplicatedLayer(0);

        if (layer)
            layer->setReplicatedLayer(this);

        m_replicaLayer = layer;
    }

    WebLayer* webReplicaLayer = layer ? layer->platformLayer() : 0;
    platformLayer()->setReplicaLayer(webReplicaLayer);
}

void GraphicsLayer::setOffsetFromLayoutObject(const IntSize& offset, ShouldSetNeedsDisplay shouldSetNeedsDisplay)
>>>>>>> miniblink49
{
    setOffsetDoubleFromLayoutObject(offset);
}

<<<<<<< HEAD
void GraphicsLayer::setOffsetDoubleFromLayoutObject(
    const DoubleSize& offset,
    ShouldSetNeedsDisplay shouldSetNeedsDisplay)
=======
void GraphicsLayer::setOffsetDoubleFromLayoutObject(const DoubleSize& offset, ShouldSetNeedsDisplay shouldSetNeedsDisplay)
>>>>>>> miniblink49
{
    if (offset == m_offsetFromLayoutObject)
        return;

    m_offsetFromLayoutObject = offset;
<<<<<<< HEAD
    platformLayer()->setFiltersOrigin(FloatPoint() - toFloatSize(offset));
=======
>>>>>>> miniblink49

    // If the compositing layer offset changes, we need to repaint.
    if (shouldSetNeedsDisplay == SetNeedsDisplay)
        setNeedsDisplay();
}

<<<<<<< HEAD
LayoutSize GraphicsLayer::offsetFromLayoutObjectWithSubpixelAccumulation()
    const
{
    return LayoutSize(offsetFromLayoutObject()) + client()->subpixelAccumulation();
}

IntRect GraphicsLayer::interestRect()
{
    return m_previousInterestRect;
}

void GraphicsLayer::paint(const IntRect* interestRect,
    GraphicsContext::DisabledMode disabledMode)
{
    if (paintWithoutCommit(interestRect, disabledMode)) {
        getPaintController().commitNewDisplayItems(
            offsetFromLayoutObjectWithSubpixelAccumulation());
        if (RuntimeEnabledFeatures::paintUnderInvalidationCheckingEnabled()) {
            sk_sp<SkPicture> newPicture = capturePicture();
            checkPaintUnderInvalidations(*newPicture);
            RasterInvalidationTracking& tracking = rasterInvalidationTrackingMap().add(this);
            tracking.lastPaintedPicture = std::move(newPicture);
            tracking.lastInterestRect = m_previousInterestRect;
            tracking.rasterInvalidationRegionSinceLastPaint = Region();
        }
    }
}

bool GraphicsLayer::paintWithoutCommit(
    const IntRect* interestRect,
    GraphicsContext::DisabledMode disabledMode)
{
    DCHECK(drawsContent());

    if (!m_client)
        return false;
    if (FirstPaintInvalidationTracking::isEnabled())
        m_debugInfo.clearAnnotatedInvalidateRects();
    incrementPaintCount();

    IntRect newInterestRect;
    if (!interestRect) {
        newInterestRect = m_client->computeInterestRect(this, m_previousInterestRect);
        interestRect = &newInterestRect;
    }

    if (!getPaintController().subsequenceCachingIsDisabled() && !m_client->needsRepaint(*this) && !getPaintController().cacheIsEmpty() && m_previousInterestRect == *interestRect) {
        return false;
    }

    GraphicsContext context(getPaintController(), disabledMode, nullptr,
        m_colorBehavior);

    m_previousInterestRect = *interestRect;
    m_client->paintContents(this, context, m_paintingPhase, *interestRect);
    return true;
=======
void GraphicsLayer::paintGraphicsLayerContents(GraphicsContext& context, const IntRect& clip)
{
    if (!m_client)
        return;
    if (firstPaintInvalidationTrackingEnabled())
        m_debugInfo.clearAnnotatedInvalidateRects();
    incrementPaintCount();
#ifndef NDEBUG
    if (m_displayItemList && contentsOpaque()) {
        ASSERT(RuntimeEnabledFeatures::slimmingPaintEnabled());
        FloatRect rect(FloatPoint(), size());
        if (!DrawingRecorder::useCachedDrawingIfPossible(context, *this, DisplayItem::DebugRedFill)) {
            DrawingRecorder recorder(context, *this, DisplayItem::DebugRedFill, rect);
            context.fillRect(rect, SK_ColorRED);
        }
    }
#endif
    m_client->paintContents(this, context, m_paintingPhase, clip);
>>>>>>> miniblink49
}

void GraphicsLayer::updateChildList()
{
    WebLayer* childHost = m_layer->layer();
    childHost->removeAllChildren();

    clearContentsLayerIfUnregistered();

    if (m_contentsLayer) {
<<<<<<< HEAD
        // FIXME: Add the contents layer in the correct order with negative z-order
        // children. This does not currently cause visible rendering issues because
        // contents layers are only used for replaced elements that don't have
        // children.
=======
        // FIXME: add the contents layer in the correct order with negative z-order children.
        // This does not cause visible rendering issues because currently contents layers are only used
        // for replaced elements that don't have children.
>>>>>>> miniblink49
        childHost->addChild(m_contentsLayer);
    }

    for (size_t i = 0; i < m_children.size(); ++i)
        childHost->addChild(m_children[i]->platformLayer());

    for (size_t i = 0; i < m_linkHighlights.size(); ++i)
        childHost->addChild(m_linkHighlights[i]->layer());
}

void GraphicsLayer::updateLayerIsDrawable()
{
<<<<<<< HEAD
    // For the rest of the accelerated compositor code, there is no reason to make
    // a distinction between drawsContent and contentsVisible. So, for
    // m_layer->layer(), these two flags are combined here. |m_contentsLayer|
    // shouldn't receive the drawsContent flag, so it is only given
    // contentsVisible.
=======
    // For the rest of the accelerated compositor code, there is no reason to make a
    // distinction between drawsContent and contentsVisible. So, for m_layer->layer(), these two
    // flags are combined here. m_contentsLayer shouldn't receive the drawsContent flag
    // so it is only given contentsVisible.
>>>>>>> miniblink49

    m_layer->layer()->setDrawsContent(m_drawsContent && m_contentsVisible);
    if (WebLayer* contentsLayer = contentsLayerIfRegistered())
        contentsLayer->setDrawsContent(m_contentsVisible);

    if (m_drawsContent) {
        m_layer->layer()->invalidate();
        for (size_t i = 0; i < m_linkHighlights.size(); ++i)
            m_linkHighlights[i]->invalidate();
    }
}

void GraphicsLayer::updateContentsRect()
{
    WebLayer* contentsLayer = contentsLayerIfRegistered();
    if (!contentsLayer)
        return;

<<<<<<< HEAD
    contentsLayer->setPosition(
        FloatPoint(m_contentsRect.x(), m_contentsRect.y()));
    contentsLayer->setBounds(
        IntSize(m_contentsRect.width(), m_contentsRect.height()));

    if (m_contentsClippingMaskLayer) {
        if (m_contentsClippingMaskLayer->size() != m_contentsRect.size()) {
            m_contentsClippingMaskLayer->setSize(FloatSize(m_contentsRect.size()));
            m_contentsClippingMaskLayer->setNeedsDisplay();
        }
        m_contentsClippingMaskLayer->setPosition(FloatPoint());
        m_contentsClippingMaskLayer->setOffsetFromLayoutObject(
            offsetFromLayoutObject() + IntSize(m_contentsRect.location().x(), m_contentsRect.location().y()));
=======
    contentsLayer->setPosition(FloatPoint(m_contentsRect.x(), m_contentsRect.y()));
    contentsLayer->setBounds(IntSize(m_contentsRect.width(), m_contentsRect.height()));

    if (m_contentsClippingMaskLayer) {
        if (m_contentsClippingMaskLayer->size() != m_contentsRect.size()) {
            m_contentsClippingMaskLayer->setSize(m_contentsRect.size());
            m_contentsClippingMaskLayer->setNeedsDisplay();
        }
        m_contentsClippingMaskLayer->setPosition(FloatPoint());
        m_contentsClippingMaskLayer->setOffsetFromLayoutObject(offsetFromLayoutObject() + IntSize(m_contentsRect.location().x(), m_contentsRect.location().y()));
>>>>>>> miniblink49
    }
}

static HashSet<int>* s_registeredLayerSet;

void GraphicsLayer::registerContentsLayer(WebLayer* layer)
{
    if (!s_registeredLayerSet)
        s_registeredLayerSet = new HashSet<int>;
    if (s_registeredLayerSet->contains(layer->id()))
        CRASH();
    s_registeredLayerSet->add(layer->id());
}

void GraphicsLayer::unregisterContentsLayer(WebLayer* layer)
{
<<<<<<< HEAD
    DCHECK(s_registeredLayerSet);
=======
    ASSERT(s_registeredLayerSet);
>>>>>>> miniblink49
    if (!s_registeredLayerSet->contains(layer->id()))
        CRASH();
    s_registeredLayerSet->remove(layer->id());
}

void GraphicsLayer::setContentsTo(WebLayer* layer)
{
    bool childrenChanged = false;
    if (layer) {
<<<<<<< HEAD
        DCHECK(s_registeredLayerSet);
=======
        ASSERT(s_registeredLayerSet);
>>>>>>> miniblink49
        if (!s_registeredLayerSet->contains(layer->id()))
            CRASH();
        if (m_contentsLayerId != layer->id()) {
            setupContentsLayer(layer);
            childrenChanged = true;
        }
        updateContentsRect();
    } else {
        if (m_contentsLayer) {
            childrenChanged = true;

            // The old contents layer will be removed via updateChildList.
            m_contentsLayer = 0;
            m_contentsLayerId = 0;
        }
    }

    if (childrenChanged)
        updateChildList();
}

void GraphicsLayer::setupContentsLayer(WebLayer* contentsLayer)
{
<<<<<<< HEAD
    DCHECK(contentsLayer);
    m_contentsLayer = contentsLayer;
    m_contentsLayerId = m_contentsLayer->id();

    m_contentsLayer->setLayerClient(this);
    m_contentsLayer->setTransformOrigin(FloatPoint3D());
    m_contentsLayer->setUseParentBackfaceVisibility(true);

    // It is necessary to call setDrawsContent as soon as we receive the new
    // contentsLayer, for the correctness of early exit conditions in
    // setDrawsContent() and setContentsVisible().
    m_contentsLayer->setDrawsContent(m_contentsVisible);

    // Insert the content layer first. Video elements require this, because they
    // have shadow content that must display in front of the video.
    m_layer->layer()->insertChild(m_contentsLayer, 0);
    WebLayer* borderWebLayer = m_contentsClippingMaskLayer
        ? m_contentsClippingMaskLayer->platformLayer()
        : 0;
    m_contentsLayer->setMaskLayer(borderWebLayer);

    m_contentsLayer->setRenderingContext(m_renderingContext3d);
=======
    ASSERT(contentsLayer);
    m_contentsLayer = contentsLayer;
    m_contentsLayerId = m_contentsLayer->id();

    m_contentsLayer->setWebLayerClient(this);
    m_contentsLayer->setTransformOrigin(FloatPoint3D());
    m_contentsLayer->setUseParentBackfaceVisibility(true);

    // It is necessary to call setDrawsContent as soon as we receive the new contentsLayer, for
    // the correctness of early exit conditions in setDrawsContent() and setContentsVisible().
    m_contentsLayer->setDrawsContent(m_contentsVisible);

    // Insert the content layer first. Video elements require this, because they have
    // shadow content that must display in front of the video.
    m_layer->layer()->insertChild(m_contentsLayer, 0);
    WebLayer* borderWebLayer = m_contentsClippingMaskLayer ? m_contentsClippingMaskLayer->platformLayer() : 0;
    m_contentsLayer->setMaskLayer(borderWebLayer);

    m_contentsLayer->setRenderingContext(m_3dRenderingContext);
>>>>>>> miniblink49
}

void GraphicsLayer::clearContentsLayerIfUnregistered()
{
    if (!m_contentsLayerId || s_registeredLayerSet->contains(m_contentsLayerId))
        return;

    m_contentsLayer = 0;
    m_contentsLayerId = 0;
}

GraphicsLayerDebugInfo& GraphicsLayer::debugInfo()
{
    return m_debugInfo;
}

<<<<<<< HEAD
=======
WebGraphicsLayerDebugInfo* GraphicsLayer::takeDebugInfoFor(WebLayer* layer)
{
    GraphicsLayerDebugInfo* clone = m_debugInfo.clone();
    clone->setDebugName(debugName(layer));
    return clone;
}

>>>>>>> miniblink49
WebLayer* GraphicsLayer::contentsLayerIfRegistered()
{
    clearContentsLayerIfUnregistered();
    return m_contentsLayer;
}

<<<<<<< HEAD
void GraphicsLayer::setTracksRasterInvalidations(
    bool tracksRasterInvalidations)
{
    resetTrackedRasterInvalidations();
    m_isTrackingRasterInvalidations = tracksRasterInvalidations;
}

void GraphicsLayer::resetTrackedRasterInvalidations()
{
    RasterInvalidationTracking* tracking = rasterInvalidationTrackingMap().find(this);
    if (!tracking)
        return;

    if (RuntimeEnabledFeatures::paintUnderInvalidationCheckingEnabled())
        tracking->trackedRasterInvalidations.clear();
    else
        rasterInvalidationTrackingMap().remove(this);
}

bool GraphicsLayer::hasTrackedRasterInvalidations() const
{
    if (auto* tracking = getRasterInvalidationTracking())
        return !tracking->trackedRasterInvalidations.isEmpty();
    return false;
}

const RasterInvalidationTracking* GraphicsLayer::getRasterInvalidationTracking()
    const
{
    return rasterInvalidationTrackingMap().find(this);
}

void GraphicsLayer::trackRasterInvalidation(const DisplayItemClient& client,
    const IntRect& rect,
    PaintInvalidationReason reason)
{
    if (!isTrackingOrCheckingRasterInvalidations() || rect.isEmpty())
        return;

    RasterInvalidationTracking& tracking = rasterInvalidationTrackingMap().add(this);

    if (m_isTrackingRasterInvalidations) {
        RasterInvalidationInfo info;
        info.client = &client;
        info.clientDebugName = client.debugName();
        info.rect = rect;
        info.reason = reason;
        tracking.trackedRasterInvalidations.push_back(info);
    }

    if (RuntimeEnabledFeatures::paintUnderInvalidationCheckingEnabled()) {
        // TODO(crbug.com/496260): Some antialiasing effects overflow the paint
        // invalidation rect.
        IntRect r = rect;
        r.inflate(1);
        tracking.rasterInvalidationRegionSinceLastPaint.unite(r);
    }
}

template <typename T>
static std::unique_ptr<JSONArray> pointAsJSONArray(const T& point)
{
    std::unique_ptr<JSONArray> array = JSONArray::create();
    array->pushDouble(point.x());
    array->pushDouble(point.y());
=======
void GraphicsLayer::resetTrackedPaintInvalidations()
{
    paintInvalidationTrackingMap().remove(this);
}

void GraphicsLayer::trackPaintInvalidationRect(const FloatRect& rect)
{
    if (rect.isEmpty())
        return;

    // The caller must check isTrackingPaintInvalidations() before calling this method
    // to avoid constructing the rect unnecessarily.
    ASSERT(isTrackingPaintInvalidations());

    paintInvalidationTrackingMap().add(this, PaintInvalidationTrackingInfo()).storedValue->value.invalidationRects.append(rect);
}

void GraphicsLayer::trackPaintInvalidationObject(const String& objectDebugString)
{
    if (objectDebugString.isEmpty())
        return;

    // The caller must check isTrackingPaintInvalidations() before calling this method
    // because constructing the debug string will be costly.
    ASSERT(isTrackingPaintInvalidations());

    if (!RuntimeEnabledFeatures::slimmingPaintEnabled())
        return;

    paintInvalidationTrackingMap().add(this, PaintInvalidationTrackingInfo()).storedValue->value.invalidationObjects.append(objectDebugString);
}

static bool compareFloatRects(const FloatRect& a, const FloatRect& b)
{
    if (a.x() != b.x())
        return a.x() > b.x();
    if (a.y() != b.y())
        return a.y() > b.y();
    if (a.width() != b.width())
        return a.width() > b.width();
    return a.height() > b.height();
}

template <typename T>
static PassRefPtr<JSONArray> pointAsJSONArray(const T& point)
{
    RefPtr<JSONArray> array = adoptRef(new JSONArray);
    array->pushNumber(point.x());
    array->pushNumber(point.y());
>>>>>>> miniblink49
    return array;
}

template <typename T>
<<<<<<< HEAD
static std::unique_ptr<JSONArray> sizeAsJSONArray(const T& size)
{
    std::unique_ptr<JSONArray> array = JSONArray::create();
    array->pushDouble(size.width());
    array->pushDouble(size.height());
=======
static PassRefPtr<JSONArray> sizeAsJSONArray(const T& size)
{
    RefPtr<JSONArray> array = adoptRef(new JSONArray);
    array->pushNumber(size.width());
    array->pushNumber(size.height());
    return array;
}

template <typename T>
static PassRefPtr<JSONArray> rectAsJSONArray(const T& rect)
{
    RefPtr<JSONArray> array = adoptRef(new JSONArray);
    array->pushNumber(rect.x());
    array->pushNumber(rect.y());
    array->pushNumber(rect.width());
    array->pushNumber(rect.height());
>>>>>>> miniblink49
    return array;
}

static double roundCloseToZero(double number)
{
    return std::abs(number) < 1e-7 ? 0 : number;
}

<<<<<<< HEAD
static std::unique_ptr<JSONArray> transformAsJSONArray(
    const TransformationMatrix& t)
{
    std::unique_ptr<JSONArray> array = JSONArray::create();
    {
        std::unique_ptr<JSONArray> row = JSONArray::create();
        row->pushDouble(roundCloseToZero(t.m11()));
        row->pushDouble(roundCloseToZero(t.m12()));
        row->pushDouble(roundCloseToZero(t.m13()));
        row->pushDouble(roundCloseToZero(t.m14()));
        array->pushArray(std::move(row));
    }
    {
        std::unique_ptr<JSONArray> row = JSONArray::create();
        row->pushDouble(roundCloseToZero(t.m21()));
        row->pushDouble(roundCloseToZero(t.m22()));
        row->pushDouble(roundCloseToZero(t.m23()));
        row->pushDouble(roundCloseToZero(t.m24()));
        array->pushArray(std::move(row));
    }
    {
        std::unique_ptr<JSONArray> row = JSONArray::create();
        row->pushDouble(roundCloseToZero(t.m31()));
        row->pushDouble(roundCloseToZero(t.m32()));
        row->pushDouble(roundCloseToZero(t.m33()));
        row->pushDouble(roundCloseToZero(t.m34()));
        array->pushArray(std::move(row));
    }
    {
        std::unique_ptr<JSONArray> row = JSONArray::create();
        row->pushDouble(roundCloseToZero(t.m41()));
        row->pushDouble(roundCloseToZero(t.m42()));
        row->pushDouble(roundCloseToZero(t.m43()));
        row->pushDouble(roundCloseToZero(t.m44()));
        array->pushArray(std::move(row));
=======
static PassRefPtr<JSONArray> transformAsJSONArray(const TransformationMatrix& t)
{
    RefPtr<JSONArray> array = adoptRef(new JSONArray);
    {
        RefPtr<JSONArray> row = adoptRef(new JSONArray);
        row->pushNumber(roundCloseToZero(t.m11()));
        row->pushNumber(roundCloseToZero(t.m12()));
        row->pushNumber(roundCloseToZero(t.m13()));
        row->pushNumber(roundCloseToZero(t.m14()));
        array->pushArray(row);
    }
    {
        RefPtr<JSONArray> row = adoptRef(new JSONArray);
        row->pushNumber(roundCloseToZero(t.m21()));
        row->pushNumber(roundCloseToZero(t.m22()));
        row->pushNumber(roundCloseToZero(t.m23()));
        row->pushNumber(roundCloseToZero(t.m24()));
        array->pushArray(row);
    }
    {
        RefPtr<JSONArray> row = adoptRef(new JSONArray);
        row->pushNumber(roundCloseToZero(t.m31()));
        row->pushNumber(roundCloseToZero(t.m32()));
        row->pushNumber(roundCloseToZero(t.m33()));
        row->pushNumber(roundCloseToZero(t.m34()));
        array->pushArray(row);
    }
    {
        RefPtr<JSONArray> row = adoptRef(new JSONArray);
        row->pushNumber(roundCloseToZero(t.m41()));
        row->pushNumber(roundCloseToZero(t.m42()));
        row->pushNumber(roundCloseToZero(t.m43()));
        row->pushNumber(roundCloseToZero(t.m44()));
        array->pushArray(row);
>>>>>>> miniblink49
    }
    return array;
}

static String pointerAsString(const void* ptr)
{
    TextStream ts;
    ts << ptr;
    return ts.release();
}

<<<<<<< HEAD
std::unique_ptr<JSONObject> GraphicsLayer::layerTreeAsJSON(
    LayerTreeFlags flags) const
{
    RenderingContextMap renderingContextMap;
    if (flags & OutputAsLayerTree)
        return layerTreeAsJSONInternal(flags, renderingContextMap);
    std::unique_ptr<JSONObject> json = JSONObject::create();
    std::unique_ptr<JSONArray> layersArray = JSONArray::create();
    for (auto& child : m_children)
        child->layersAsJSONArray(flags, renderingContextMap, layersArray.get());
    json->setArray("layers", std::move(layersArray));
    return json;
}

std::unique_ptr<JSONObject> GraphicsLayer::layerAsJSONInternal(
    LayerTreeFlags flags,
    RenderingContextMap& renderingContextMap) const
{
    std::unique_ptr<JSONObject> json = JSONObject::create();

    if (flags & LayerTreeIncludesDebugInfo)
        json->setString("this", pointerAsString(this));

    json->setString("name", debugName());
=======
PassRefPtr<JSONObject> GraphicsLayer::layerTreeAsJSON(LayerTreeFlags flags, RenderingContextMap& renderingContextMap) const
{
    RefPtr<JSONObject> json = adoptRef(new JSONObject);

    if (flags & LayerTreeIncludesDebugInfo) {
        json->setString("this", pointerAsString(this));
        json->setString("debugName", m_client->debugName(this));
    }
>>>>>>> miniblink49

    if (m_position != FloatPoint())
        json->setArray("position", pointAsJSONArray(m_position));

<<<<<<< HEAD
    if (flags & LayerTreeIncludesDebugInfo && m_offsetFromLayoutObject != DoubleSize()) {
        json->setArray("offsetFromLayoutObject",
            sizeAsJSONArray(m_offsetFromLayoutObject));
    }

=======
>>>>>>> miniblink49
    if (m_hasTransformOrigin && m_transformOrigin != FloatPoint3D(m_size.width() * 0.5f, m_size.height() * 0.5f, 0))
        json->setArray("transformOrigin", pointAsJSONArray(m_transformOrigin));

    if (m_size != IntSize())
        json->setArray("bounds", sizeAsJSONArray(m_size));

    if (m_opacity != 1)
<<<<<<< HEAD
        json->setDouble("opacity", m_opacity);

    if (m_blendMode != WebBlendModeNormal) {
        json->setString("blendMode",
            compositeOperatorName(CompositeSourceOver, m_blendMode));
=======
        json->setNumber("opacity", m_opacity);

    if (m_blendMode != WebBlendModeNormal)
        json->setString("blendMode", compositeOperatorName(CompositeSourceOver, m_blendMode));

    if ((flags & LayerTreeIncludesScrollBlocksOn) && m_scrollBlocksOn) {
        RefPtr<JSONArray> scrollBlocksOnJSON = adoptRef(new JSONArray);
        if (m_scrollBlocksOn & WebScrollBlocksOnStartTouch)
            scrollBlocksOnJSON->pushString("StartTouch");
        if (m_scrollBlocksOn & WebScrollBlocksOnWheelEvent)
            scrollBlocksOnJSON->pushString("WheelEvent");
        if (m_scrollBlocksOn & WebScrollBlocksOnScrollEvent)
            scrollBlocksOnJSON->pushString("ScrollEvent");
        json->setArray("scrollBlocksOn", scrollBlocksOnJSON);
>>>>>>> miniblink49
    }

    if (m_isRootForIsolatedGroup)
        json->setBoolean("isolate", m_isRootForIsolatedGroup);

    if (m_contentsOpaque)
        json->setBoolean("contentsOpaque", m_contentsOpaque);

    if (!m_shouldFlattenTransform)
        json->setBoolean("shouldFlattenTransform", m_shouldFlattenTransform);

<<<<<<< HEAD
    if (m_renderingContext3d) {
        RenderingContextMap::const_iterator it = renderingContextMap.find(m_renderingContext3d);
        int contextId = renderingContextMap.size() + 1;
        if (it == renderingContextMap.end())
            renderingContextMap.set(m_renderingContext3d, contextId);
        else
            contextId = it->value;

        json->setInteger("3dRenderingContext", contextId);
=======
    if (m_3dRenderingContext) {
        RenderingContextMap::const_iterator it = renderingContextMap.find(m_3dRenderingContext);
        int contextId = renderingContextMap.size() + 1;
        if (it == renderingContextMap.end())
            renderingContextMap.set(m_3dRenderingContext, contextId);
        else
            contextId = it->value;

        json->setNumber("3dRenderingContext", contextId);
>>>>>>> miniblink49
    }

    if (m_drawsContent)
        json->setBoolean("drawsContent", m_drawsContent);

    if (!m_contentsVisible)
        json->setBoolean("contentsVisible", m_contentsVisible);

<<<<<<< HEAD
    if (!m_backfaceVisibility) {
        json->setString("backfaceVisibility",
            m_backfaceVisibility ? "visible" : "hidden");
    }

    if (m_hasPreferredRasterBounds) {
        json->setArray("preferredRasterBounds",
            sizeAsJSONArray(m_preferredRasterBounds));
    }
=======
    if (!m_backfaceVisibility)
        json->setString("backfaceVisibility", m_backfaceVisibility ? "visible" : "hidden");
>>>>>>> miniblink49

    if (flags & LayerTreeIncludesDebugInfo)
        json->setString("client", pointerAsString(m_client));

<<<<<<< HEAD
    if (m_backgroundColor.alpha()) {
        json->setString("backgroundColor",
            m_backgroundColor.nameForLayoutTreeAsText());
    }
=======
    if (m_backgroundColor.alpha())
        json->setString("backgroundColor", m_backgroundColor.nameForLayoutTreeAsText());
>>>>>>> miniblink49

    if (!m_transform.isIdentity())
        json->setArray("transform", transformAsJSONArray(m_transform));

<<<<<<< HEAD
    if (flags & LayerTreeIncludesPaintInvalidations)
        rasterInvalidationTrackingMap().asJSON(this, json.get());

    if ((flags & LayerTreeIncludesPaintingPhases) && m_paintingPhase) {
        std::unique_ptr<JSONArray> paintingPhasesJSON = JSONArray::create();
=======
    if (m_replicaLayer)
        json->setObject("replicaLayer", m_replicaLayer->layerTreeAsJSON(flags, renderingContextMap));

    if (m_replicatedLayer)
        json->setString("replicatedLayer", flags & LayerTreeIncludesDebugInfo ? pointerAsString(m_replicatedLayer) : "");

    PaintInvalidationTrackingMap::iterator it = paintInvalidationTrackingMap().find(this);
    if (it != paintInvalidationTrackingMap().end()) {
        if (flags & LayerTreeIncludesPaintInvalidationRects) {
            Vector<FloatRect>& rects = it->value.invalidationRects;
            if (!rects.isEmpty()) {
                std::sort(rects.begin(), rects.end(), &compareFloatRects);
                RefPtr<JSONArray> rectsJSON = adoptRef(new JSONArray);
                for (auto& rect : rects) {
                    if (rect.isEmpty())
                        continue;
                    rectsJSON->pushArray(rectAsJSONArray(rect));
                }
                json->setArray("repaintRects", rectsJSON);
            }
        }

        if (RuntimeEnabledFeatures::slimmingPaintEnabled() && (flags & LayerTreeIncludesPaintInvalidationObjects)) {
            Vector<String>& clients = it->value.invalidationObjects;
            if (!clients.isEmpty()) {
                RefPtr<JSONArray> clientsJSON = adoptRef(new JSONArray);
                for (auto& clientString : clients)
                    clientsJSON->pushString(clientString);
                json->setArray("paintInvalidationClients", clientsJSON);
            }
        }
    }

    if ((flags & LayerTreeIncludesPaintingPhases) && m_paintingPhase) {
        RefPtr<JSONArray> paintingPhasesJSON = adoptRef(new JSONArray);
>>>>>>> miniblink49
        if (m_paintingPhase & GraphicsLayerPaintBackground)
            paintingPhasesJSON->pushString("GraphicsLayerPaintBackground");
        if (m_paintingPhase & GraphicsLayerPaintForeground)
            paintingPhasesJSON->pushString("GraphicsLayerPaintForeground");
        if (m_paintingPhase & GraphicsLayerPaintMask)
            paintingPhasesJSON->pushString("GraphicsLayerPaintMask");
        if (m_paintingPhase & GraphicsLayerPaintChildClippingMask)
            paintingPhasesJSON->pushString("GraphicsLayerPaintChildClippingMask");
<<<<<<< HEAD
        if (m_paintingPhase & GraphicsLayerPaintAncestorClippingMask)
            paintingPhasesJSON->pushString("GraphicsLayerPaintAncestorClippingMask");
=======
>>>>>>> miniblink49
        if (m_paintingPhase & GraphicsLayerPaintOverflowContents)
            paintingPhasesJSON->pushString("GraphicsLayerPaintOverflowContents");
        if (m_paintingPhase & GraphicsLayerPaintCompositedScroll)
            paintingPhasesJSON->pushString("GraphicsLayerPaintCompositedScroll");
<<<<<<< HEAD
        if (m_paintingPhase & GraphicsLayerPaintDecoration)
            paintingPhasesJSON->pushString("GraphicsLayerPaintDecoration");
        json->setArray("paintingPhases", std::move(paintingPhasesJSON));
=======
        json->setArray("paintingPhases", paintingPhasesJSON);
>>>>>>> miniblink49
    }

    if (flags & LayerTreeIncludesClipAndScrollParents) {
        if (m_hasScrollParent)
            json->setBoolean("hasScrollParent", true);
        if (m_hasClipParent)
            json->setBoolean("hasClipParent", true);
    }

    if (flags & (LayerTreeIncludesDebugInfo | LayerTreeIncludesCompositingReasons)) {
        bool debug = flags & LayerTreeIncludesDebugInfo;
<<<<<<< HEAD
        std::unique_ptr<JSONArray> compositingReasonsJSON = JSONArray::create();
        for (size_t i = 0; i < kNumberOfCompositingReasons; ++i) {
            if (m_debugInfo.getCompositingReasons() & kCompositingReasonStringMap[i].reason) {
                compositingReasonsJSON->pushString(
                    debug ? kCompositingReasonStringMap[i].description
                          : kCompositingReasonStringMap[i].shortName);
            }
        }
        json->setArray("compositingReasons", std::move(compositingReasonsJSON));

        std::unique_ptr<JSONArray> squashingDisallowedReasonsJSON = JSONArray::create();
        for (size_t i = 0; i < kNumberOfSquashingDisallowedReasons; ++i) {
            if (m_debugInfo.getSquashingDisallowedReasons() & kSquashingDisallowedReasonStringMap[i].reason) {
                squashingDisallowedReasonsJSON->pushString(
                    debug ? kSquashingDisallowedReasonStringMap[i].description
                          : kSquashingDisallowedReasonStringMap[i].shortName);
            }
        }
        json->setArray("squashingDisallowedReasons",
            std::move(squashingDisallowedReasonsJSON));
    }

    if (m_maskLayer) {
        std::unique_ptr<JSONArray> maskLayerJSON = JSONArray::create();
        maskLayerJSON->pushObject(
            m_maskLayer->layerAsJSONInternal(flags, renderingContextMap));
        json->setArray("maskLayer", std::move(maskLayerJSON));
    }

    if (m_contentsClippingMaskLayer) {
        std::unique_ptr<JSONArray> contentsClippingMaskLayerJSON = JSONArray::create();
        contentsClippingMaskLayerJSON->pushObject(
            m_contentsClippingMaskLayer->layerAsJSONInternal(flags,
                renderingContextMap));
        json->setArray("contentsClippingMaskLayer",
            std::move(contentsClippingMaskLayerJSON));
=======
        RefPtr<JSONArray> compositingReasonsJSON = adoptRef(new JSONArray);
        for (size_t i = 0; i < kNumberOfCompositingReasons; ++i) {
            if (m_debugInfo.compositingReasons() & kCompositingReasonStringMap[i].reason)
                compositingReasonsJSON->pushString(debug ? kCompositingReasonStringMap[i].description : kCompositingReasonStringMap[i].shortName);
        }
        json->setArray("compositingReasons", compositingReasonsJSON);
    }

    if (m_children.size()) {
        RefPtr<JSONArray> childrenJSON = adoptRef(new JSONArray);
        for (size_t i = 0; i < m_children.size(); i++)
            childrenJSON->pushObject(m_children[i]->layerTreeAsJSON(flags, renderingContextMap));
        json->setArray("children", childrenJSON);
>>>>>>> miniblink49
    }

    return json;
}

<<<<<<< HEAD
std::unique_ptr<JSONObject> GraphicsLayer::layerTreeAsJSONInternal(
    LayerTreeFlags flags,
    RenderingContextMap& renderingContextMap) const
{
    std::unique_ptr<JSONObject> json = layerAsJSONInternal(flags, renderingContextMap);

    if (m_children.size()) {
        std::unique_ptr<JSONArray> childrenJSON = JSONArray::create();
        for (size_t i = 0; i < m_children.size(); i++) {
            childrenJSON->pushObject(
                m_children[i]->layerTreeAsJSONInternal(flags, renderingContextMap));
        }
        json->setArray("children", std::move(childrenJSON));
    }

    return json;
}

void GraphicsLayer::layersAsJSONArray(LayerTreeFlags flags,
    RenderingContextMap& renderingContextMap,
    JSONArray* jsonArray) const
{
    jsonArray->pushObject(layerAsJSONInternal(flags, renderingContextMap));

    if (m_children.size()) {
        for (auto& child : m_children)
            child->layersAsJSONArray(flags, renderingContextMap, jsonArray);
    }
}

String GraphicsLayer::layerTreeAsText(LayerTreeFlags flags) const
{
    return layerTreeAsJSON(flags)->toPrettyJSONString();
}

static const cc::Layer* ccLayerForWebLayer(const WebLayer* webLayer)
{
    return webLayer ? webLayer->ccLayer() : nullptr;
}

String GraphicsLayer::debugName(cc::Layer* layer) const
=======
String GraphicsLayer::layerTreeAsText(LayerTreeFlags flags) const
{
    RenderingContextMap renderingContextMap;
    RefPtr<JSONObject> json = layerTreeAsJSON(flags, renderingContextMap);
    return json->toPrettyJSONString();
}

String GraphicsLayer::debugName(WebLayer* webLayer) const
>>>>>>> miniblink49
{
    String name;
    if (!m_client)
        return name;

    String highlightDebugName;
    for (size_t i = 0; i < m_linkHighlights.size(); ++i) {
<<<<<<< HEAD
        if (layer == ccLayerForWebLayer(m_linkHighlights[i]->layer())) {
=======
        if (webLayer == m_linkHighlights[i]->layer()) {
>>>>>>> miniblink49
            highlightDebugName = "LinkHighlight[" + String::number(i) + "] for " + m_client->debugName(this);
            break;
        }
    }

<<<<<<< HEAD
    if (layer->id() == m_contentsLayerId) {
        name = "ContentsLayer for " + m_client->debugName(this);
    } else if (!highlightDebugName.isEmpty()) {
        name = highlightDebugName;
    } else if (layer == ccLayerForWebLayer(m_layer->layer())) {
        name = m_client->debugName(this);
    } else {
        NOTREACHED();
=======
    if (webLayer == m_contentsLayer) {
        name = "ContentsLayer for " + m_client->debugName(this);
    } else if (!highlightDebugName.isEmpty()) {
        name = highlightDebugName;
    } else if (webLayer == m_layer->layer()) {
        name = m_client->debugName(this);
    } else {
        ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    }
    return name;
}

void GraphicsLayer::setCompositingReasons(CompositingReasons reasons)
{
    m_debugInfo.setCompositingReasons(reasons);
}

<<<<<<< HEAD
void GraphicsLayer::setSquashingDisallowedReasons(
    SquashingDisallowedReasons reasons)
{
    m_debugInfo.setSquashingDisallowedReasons(reasons);
}

=======
>>>>>>> miniblink49
void GraphicsLayer::setOwnerNodeId(int nodeId)
{
    m_debugInfo.setOwnerNodeId(nodeId);
}

void GraphicsLayer::setPosition(const FloatPoint& point)
{
    m_position = point;
    platformLayer()->setPosition(m_position);
}

void GraphicsLayer::setSize(const FloatSize& size)
{
<<<<<<< HEAD
    // We are receiving negative sizes here that cause assertions to fail in the
    // compositor. Clamp them to 0 to avoid those assertions.
    // FIXME: This should be an DCHECK instead, as negative sizes should not exist
    // in WebCore.
=======
    // We are receiving negative sizes here that cause assertions to fail in the compositor. Clamp them to 0 to
    // avoid those assertions.
    // FIXME: This should be an ASSERT instead, as negative sizes should not exist in WebCore.
>>>>>>> miniblink49
    FloatSize clampedSize = size;
    if (clampedSize.width() < 0 || clampedSize.height() < 0)
        clampedSize = FloatSize();

    if (clampedSize == m_size)
        return;

    m_size = clampedSize;

    m_layer->layer()->setBounds(flooredIntSize(m_size));
    // Note that we don't resize m_contentsLayer. It's up the caller to do that.
<<<<<<< HEAD
=======

#ifndef NDEBUG
    // The red debug fill needs to be invalidated if the layer resizes.
    if (m_displayItemList) {
        ASSERT(RuntimeEnabledFeatures::slimmingPaintEnabled());
        m_displayItemList->invalidate(displayItemClient());
    }
#endif
>>>>>>> miniblink49
}

void GraphicsLayer::setTransform(const TransformationMatrix& transform)
{
    m_transform = transform;
<<<<<<< HEAD
    platformLayer()->setTransform(
        TransformationMatrix::toSkMatrix44(m_transform));
=======
    platformLayer()->setTransform(TransformationMatrix::toSkMatrix44(m_transform));
>>>>>>> miniblink49
}

void GraphicsLayer::setTransformOrigin(const FloatPoint3D& transformOrigin)
{
    m_hasTransformOrigin = true;
    m_transformOrigin = transformOrigin;
    platformLayer()->setTransformOrigin(transformOrigin);
}

void GraphicsLayer::setShouldFlattenTransform(bool shouldFlatten)
{
    if (shouldFlatten == m_shouldFlattenTransform)
        return;

    m_shouldFlattenTransform = shouldFlatten;

    m_layer->layer()->setShouldFlattenTransform(shouldFlatten);
}

void GraphicsLayer::setRenderingContext(int context)
{
<<<<<<< HEAD
    if (m_renderingContext3d == context)
        return;

    m_renderingContext3d = context;
    m_layer->layer()->setRenderingContext(context);

    if (m_contentsLayer)
        m_contentsLayer->setRenderingContext(m_renderingContext3d);
}

bool GraphicsLayer::masksToBounds() const
{
    return m_layer->layer()->masksToBounds();
=======
    if (m_3dRenderingContext == context)
        return;

    m_3dRenderingContext = context;
    m_layer->layer()->setRenderingContext(context);

    if (m_contentsLayer)
        m_contentsLayer->setRenderingContext(m_3dRenderingContext);
>>>>>>> miniblink49
}

void GraphicsLayer::setMasksToBounds(bool masksToBounds)
{
<<<<<<< HEAD
    m_layer->layer()->setMasksToBounds(masksToBounds);
=======
    m_masksToBounds = masksToBounds;
    m_layer->layer()->setMasksToBounds(m_masksToBounds);
>>>>>>> miniblink49
}

void GraphicsLayer::setDrawsContent(bool drawsContent)
{
<<<<<<< HEAD
    // NOTE: This early-exit is only correct because we also properly call
    // WebLayer::setDrawsContent() whenever |m_contentsLayer| is set to a new
    // layer in setupContentsLayer().
=======
    // Note carefully this early-exit is only correct because we also properly call
    // WebLayer::setDrawsContent whenever m_contentsLayer is set to a new layer in setupContentsLayer().
>>>>>>> miniblink49
    if (drawsContent == m_drawsContent)
        return;

    m_drawsContent = drawsContent;
    updateLayerIsDrawable();
<<<<<<< HEAD

    if (!drawsContent && m_paintController)
        m_paintController.reset();
=======
>>>>>>> miniblink49
}

void GraphicsLayer::setContentsVisible(bool contentsVisible)
{
<<<<<<< HEAD
    // NOTE: This early-exit is only correct because we also properly call
    // WebLayer::setDrawsContent() whenever |m_contentsLayer| is set to a new
    // layer in setupContentsLayer().
=======
    // Note carefully this early-exit is only correct because we also properly call
    // WebLayer::setDrawsContent whenever m_contentsLayer is set to a new layer in setupContentsLayer().
>>>>>>> miniblink49
    if (contentsVisible == m_contentsVisible)
        return;

    m_contentsVisible = contentsVisible;
    updateLayerIsDrawable();
}

void GraphicsLayer::setClipParent(WebLayer* parent)
{
    m_hasClipParent = !!parent;
    m_layer->layer()->setClipParent(parent);
}

void GraphicsLayer::setScrollParent(WebLayer* parent)
{
    m_hasScrollParent = !!parent;
    m_layer->layer()->setScrollParent(parent);
}

void GraphicsLayer::setBackgroundColor(const Color& color)
{
    if (color == m_backgroundColor)
        return;

    m_backgroundColor = color;
    m_layer->layer()->setBackgroundColor(m_backgroundColor.rgb());
}

void GraphicsLayer::setContentsOpaque(bool opaque)
{
    m_contentsOpaque = opaque;
    m_layer->layer()->setOpaque(m_contentsOpaque);
    clearContentsLayerIfUnregistered();
    if (m_contentsLayer)
        m_contentsLayer->setOpaque(opaque);
}

void GraphicsLayer::setMaskLayer(GraphicsLayer* maskLayer)
{
    if (maskLayer == m_maskLayer)
        return;

    m_maskLayer = maskLayer;
    WebLayer* maskWebLayer = m_maskLayer ? m_maskLayer->platformLayer() : 0;
    m_layer->layer()->setMaskLayer(maskWebLayer);
}

<<<<<<< HEAD
void GraphicsLayer::setContentsClippingMaskLayer(
    GraphicsLayer* contentsClippingMaskLayer)
=======
void GraphicsLayer::setContentsClippingMaskLayer(GraphicsLayer* contentsClippingMaskLayer)
>>>>>>> miniblink49
{
    if (contentsClippingMaskLayer == m_contentsClippingMaskLayer)
        return;

    m_contentsClippingMaskLayer = contentsClippingMaskLayer;
    WebLayer* contentsLayer = contentsLayerIfRegistered();
    if (!contentsLayer)
        return;
<<<<<<< HEAD
    WebLayer* contentsClippingMaskWebLayer = m_contentsClippingMaskLayer ? m_contentsClippingMaskLayer->platformLayer()
                                                                         : 0;
=======
    WebLayer* contentsClippingMaskWebLayer = m_contentsClippingMaskLayer ? m_contentsClippingMaskLayer->platformLayer() : 0;
>>>>>>> miniblink49
    contentsLayer->setMaskLayer(contentsClippingMaskWebLayer);
    updateContentsRect();
}

void GraphicsLayer::setBackfaceVisibility(bool visible)
{
    m_backfaceVisibility = visible;
<<<<<<< HEAD
    platformLayer()->setDoubleSided(m_backfaceVisibility);
=======
    m_layer->setDoubleSided(m_backfaceVisibility);
>>>>>>> miniblink49
}

void GraphicsLayer::setOpacity(float opacity)
{
<<<<<<< HEAD
    float clampedOpacity = clampTo(opacity, 0.0f, 1.0f);
=======
    float clampedOpacity = std::max(std::min(opacity, 1.0f), 0.0f);
>>>>>>> miniblink49
    m_opacity = clampedOpacity;
    platformLayer()->setOpacity(opacity);
}

void GraphicsLayer::setBlendMode(WebBlendMode blendMode)
{
    if (m_blendMode == blendMode)
        return;
    m_blendMode = blendMode;
    platformLayer()->setBlendMode(blendMode);
}

<<<<<<< HEAD
=======
void GraphicsLayer::setScrollBlocksOn(WebScrollBlocksOn scrollBlocksOn)
{
    if (m_scrollBlocksOn == scrollBlocksOn)
        return;
    m_scrollBlocksOn = scrollBlocksOn;
    platformLayer()->setScrollBlocksOn(scrollBlocksOn);
}

>>>>>>> miniblink49
void GraphicsLayer::setIsRootForIsolatedGroup(bool isolated)
{
    if (m_isRootForIsolatedGroup == isolated)
        return;
    m_isRootForIsolatedGroup = isolated;
    platformLayer()->setIsRootForIsolatedGroup(isolated);
}

void GraphicsLayer::setContentsNeedsDisplay()
{
    if (WebLayer* contentsLayer = contentsLayerIfRegistered()) {
        contentsLayer->invalidate();
<<<<<<< HEAD
        trackRasterInvalidation(*this, m_contentsRect, PaintInvalidationFull);
=======
        if (isTrackingPaintInvalidations())
            trackPaintInvalidationRect(m_contentsRect);
>>>>>>> miniblink49
    }
}

void GraphicsLayer::setNeedsDisplay()
{
<<<<<<< HEAD
    if (!drawsContent())
        return;

    // TODO(chrishtr): Stop invalidating the rects once
    // FrameView::paintRecursively() does so.
    m_layer->layer()->invalidate();
    for (size_t i = 0; i < m_linkHighlights.size(); ++i)
        m_linkHighlights[i]->invalidate();
    getPaintController().invalidateAll();

    trackRasterInvalidation(*this, IntRect(IntPoint(), expandedIntSize(m_size)),
        PaintInvalidationFull);
}

DISABLE_CFI_PERF
void GraphicsLayer::setNeedsDisplayInRect(
    const IntRect& rect,
    PaintInvalidationReason invalidationReason,
    const DisplayItemClient& client)
{
    if (!drawsContent())
        return;

    m_layer->layer()->invalidateRect(rect);
    if (FirstPaintInvalidationTracking::isEnabled())
        m_debugInfo.appendAnnotatedInvalidateRect(rect, invalidationReason);
    for (size_t i = 0; i < m_linkHighlights.size(); ++i)
        m_linkHighlights[i]->invalidate();

    trackRasterInvalidation(client, rect, invalidationReason);
=======
    if (drawsContent()) {
        m_layer->layer()->invalidate();
        if (isTrackingPaintInvalidations())
            trackPaintInvalidationRect(FloatRect(FloatPoint(), m_size));
        for (size_t i = 0; i < m_linkHighlights.size(); ++i)
            m_linkHighlights[i]->invalidate();

        if (RuntimeEnabledFeatures::slimmingPaintEnabled()) {
            displayItemList()->invalidateAll();
            if (isTrackingPaintInvalidations())
                trackPaintInvalidationObject("##ALL##");
        }
    }
}

void GraphicsLayer::setNeedsDisplayInRect(const IntRect& rect, PaintInvalidationReason invalidationReason)
{
    if (drawsContent()) {
        m_layer->layer()->invalidateRect(rect);
        if (firstPaintInvalidationTrackingEnabled())
            m_debugInfo.appendAnnotatedInvalidateRect(rect, invalidationReason);
        if (isTrackingPaintInvalidations())
            trackPaintInvalidationRect(rect);
        for (size_t i = 0; i < m_linkHighlights.size(); ++i)
            m_linkHighlights[i]->invalidate();
    }
}

void GraphicsLayer::invalidateDisplayItemClient(const DisplayItemClientWrapper& displayItemClient)
{
    ASSERT(RuntimeEnabledFeatures::slimmingPaintEnabled());
    displayItemList()->invalidate(displayItemClient.displayItemClient());
    if (isTrackingPaintInvalidations())
        trackPaintInvalidationObject(displayItemClient.debugName());
>>>>>>> miniblink49
}

void GraphicsLayer::setContentsRect(const IntRect& rect)
{
    if (rect == m_contentsRect)
        return;

    m_contentsRect = rect;
    updateContentsRect();
}

<<<<<<< HEAD
void GraphicsLayer::setContentsToImage(
    Image* image,
    RespectImageOrientationEnum respectImageOrientation)
{
    sk_sp<SkImage> skImage = image ? image->imageForCurrentFrame(m_colorBehavior) : nullptr;

    if (image && skImage && image->isBitmapImage()) {
        if (respectImageOrientation == RespectImageOrientation) {
            ImageOrientation imageOrientation = toBitmapImage(image)->currentFrameOrientation();
            skImage = DragImage::resizeAndOrientImage(std::move(skImage), imageOrientation);
        }
    }

    if (image && skImage) {
        if (!m_imageLayer) {
            m_imageLayer = Platform::current()->compositorSupport()->createImageLayer();
            registerContentsLayer(m_imageLayer->layer());
        }
        m_imageLayer->setImage(skImage.get());
=======
void GraphicsLayer::setContentsToImage(Image* image)
{
    SkBitmap bitmap;
    if (image && image->bitmapForCurrentFrame(&bitmap)) {
        if (!m_imageLayer) {
            m_imageLayer = adoptPtr(Platform::current()->compositorSupport()->createImageLayer());
            registerContentsLayer(m_imageLayer->layer());
        }
        m_imageLayer->setImageBitmap(bitmap);
>>>>>>> miniblink49
        m_imageLayer->layer()->setOpaque(image->currentFrameKnownToBeOpaque());
        updateContentsRect();
    } else {
        if (m_imageLayer) {
            unregisterContentsLayer(m_imageLayer->layer());
<<<<<<< HEAD
            m_imageLayer.reset();
=======
            m_imageLayer.clear();
>>>>>>> miniblink49
        }
    }

    setContentsTo(m_imageLayer ? m_imageLayer->layer() : 0);
}

<<<<<<< HEAD
=======
void GraphicsLayer::setContentsToNinePatch(Image* image, const IntRect& aperture)
{
    if (m_ninePatchLayer) {
        unregisterContentsLayer(m_ninePatchLayer->layer());
        m_ninePatchLayer.clear();
    }
    SkBitmap bitmap;
    if (image && image->bitmapForCurrentFrame(&bitmap)) {
        m_ninePatchLayer = adoptPtr(Platform::current()->compositorSupport()->createNinePatchLayer());
        int borderWidth = bitmap.width() - aperture.width();
        int borderHeight = bitmap.height() - aperture.height();
        WebRect border(aperture.x(), aperture.y(), borderWidth, borderHeight);

        m_ninePatchLayer->setBitmap(bitmap);
        m_ninePatchLayer->setAperture(aperture);
        m_ninePatchLayer->setBorder(border);

        m_ninePatchLayer->layer()->setOpaque(image->currentFrameKnownToBeOpaque());
        registerContentsLayer(m_ninePatchLayer->layer());
    }
    setContentsTo(m_ninePatchLayer ? m_ninePatchLayer->layer() : 0);
}

bool GraphicsLayer::addAnimation(PassOwnPtr<WebCompositorAnimation> popAnimation)
{
    OwnPtr<WebCompositorAnimation> animation(popAnimation);
    ASSERT(animation);
    platformLayer()->setAnimationDelegate(this);

    // Remove any existing animations with the same animation id and target property.
    platformLayer()->removeAnimation(animation->id(), animation->targetProperty());
    return platformLayer()->addAnimation(animation.leakPtr());
}

void GraphicsLayer::pauseAnimation(int animationId, double timeOffset)
{
    platformLayer()->pauseAnimation(animationId, timeOffset);
}

void GraphicsLayer::removeAnimation(int animationId)
{
    platformLayer()->removeAnimation(animationId);
}

>>>>>>> miniblink49
WebLayer* GraphicsLayer::platformLayer() const
{
    return m_layer->layer();
}

<<<<<<< HEAD
void GraphicsLayer::setFilters(CompositorFilterOperations filters)
{
    platformLayer()->setFilters(filters.releaseCcFilterOperations());
}

void GraphicsLayer::setBackdropFilters(CompositorFilterOperations filters)
{
    platformLayer()->setBackgroundFilters(filters.releaseCcFilterOperations());
}

void GraphicsLayer::setStickyPositionConstraint(
    const WebLayerStickyPositionConstraint& stickyConstraint)
{
    m_layer->layer()->setStickyPositionConstraint(stickyConstraint);
=======
void GraphicsLayer::setFilters(const FilterOperations& filters)
{
    SkiaImageFilterBuilder builder;
    OwnPtr<WebFilterOperations> webFilters = adoptPtr(Platform::current()->compositorSupport()->createFilterOperations());
    FilterOutsets outsets = filters.outsets();
    builder.setCropOffset(FloatSize(outsets.left(), outsets.top()));
    builder.buildFilterOperations(filters, webFilters.get());
    m_layer->layer()->setFilters(*webFilters);
>>>>>>> miniblink49
}

void GraphicsLayer::setFilterQuality(SkFilterQuality filterQuality)
{
    if (m_imageLayer)
        m_imageLayer->setNearestNeighbor(filterQuality == kNone_SkFilterQuality);
}

void GraphicsLayer::setPaintingPhase(GraphicsLayerPaintingPhase phase)
{
    if (m_paintingPhase == phase)
        return;
    m_paintingPhase = phase;
    setNeedsDisplay();
}

<<<<<<< HEAD
void GraphicsLayer::addLinkHighlight(LinkHighlight* linkHighlight)
{
    DCHECK(linkHighlight && !m_linkHighlights.contains(linkHighlight));
    m_linkHighlights.push_back(linkHighlight);
    linkHighlight->layer()->setLayerClient(this);
    updateChildList();
}

void GraphicsLayer::removeLinkHighlight(LinkHighlight* linkHighlight)
=======
void GraphicsLayer::addLinkHighlight(LinkHighlightClient* linkHighlight)
{
    ASSERT(linkHighlight && !m_linkHighlights.contains(linkHighlight));
    m_linkHighlights.append(linkHighlight);
    linkHighlight->layer()->setWebLayerClient(this);
    updateChildList();
}

void GraphicsLayer::removeLinkHighlight(LinkHighlightClient* linkHighlight)
>>>>>>> miniblink49
{
    m_linkHighlights.remove(m_linkHighlights.find(linkHighlight));
    updateChildList();
}

<<<<<<< HEAD
void GraphicsLayer::setScrollableArea(ScrollableArea* scrollableArea,
    bool isVisualViewport)
=======
void GraphicsLayer::setScrollableArea(ScrollableArea* scrollableArea, bool isViewport)
>>>>>>> miniblink49
{
    if (m_scrollableArea == scrollableArea)
        return;

    m_scrollableArea = scrollableArea;

<<<<<<< HEAD
    // VisualViewport scrolling may involve pinch zoom and gets routed through
    // WebViewImpl explicitly rather than via GraphicsLayer::didScroll since it
    // needs to be set in tandem with the page scale delta.
    if (isVisualViewport)
=======
    // Viewport scrolling may involve pinch zoom and gets routed through
    // WebViewImpl explicitly rather than via GraphicsLayer::didScroll.
    if (isViewport)
>>>>>>> miniblink49
        m_layer->layer()->setScrollClient(0);
    else
        m_layer->layer()->setScrollClient(this);
}

<<<<<<< HEAD
void GraphicsLayer::didScroll()
{
    if (m_scrollableArea) {
        ScrollOffset newOffset = toFloatSize(m_layer->layer()->scrollPositionDouble() - m_scrollableArea->scrollOrigin());
        m_scrollableArea->setScrollOffset(newOffset, CompositorScroll);
    }
}

std::unique_ptr<base::trace_event::ConvertableToTraceFormat>
GraphicsLayer::TakeDebugInfo(cc::Layer* layer)
{
    std::unique_ptr<base::trace_event::TracedValue> tracedValue(
        m_debugInfo.asTracedValue());
    tracedValue->SetString(
        "layer_name", WTF::StringUTF8Adaptor(debugName(layer)).asStringPiece());
    return std::move(tracedValue);
}

void GraphicsLayer::didUpdateMainThreadScrollingReasons()
{
    m_debugInfo.setMainThreadScrollingReasons(
        platformLayer()->mainThreadScrollingReasons());
}

void GraphicsLayer::didChangeScrollbarsHidden(bool hidden)
{
    if (m_scrollableArea)
        m_scrollableArea->setScrollbarsHidden(hidden);
}

PaintController& GraphicsLayer::getPaintController()
{
    RELEASE_ASSERT(drawsContent());
    if (!m_paintController)
        m_paintController = PaintController::create();
    return *m_paintController;
}

void GraphicsLayer::setElementId(const CompositorElementId& id)
{
    if (WebLayer* layer = platformLayer())
        layer->setElementId(id);
}

CompositorElementId GraphicsLayer::elementId() const
{
    if (WebLayer* layer = platformLayer())
        return layer->elementId();
    return CompositorElementId();
}

void GraphicsLayer::setCompositorMutableProperties(uint32_t properties)
{
    if (WebLayer* layer = platformLayer())
        layer->setCompositorMutableProperties(properties);
}

sk_sp<SkPicture> GraphicsLayer::capturePicture()
{
    if (!drawsContent())
        return nullptr;

    IntSize intSize = expandedIntSize(size());
    GraphicsContext graphicsContext(getPaintController(),
        GraphicsContext::NothingDisabled, nullptr,
        m_colorBehavior);
    graphicsContext.beginRecording(IntRect(IntPoint(0, 0), intSize));
    getPaintController().paintArtifact().replay(graphicsContext);
    return graphicsContext.endRecording();
}

static bool pixelComponentsDiffer(int c1, int c2)
{
    // Compare strictly for saturated values.
    if (c1 == 0 || c1 == 255 || c2 == 0 || c2 == 255)
        return c1 != c2;
    // Tolerate invisible differences that may occur in gradients etc.
    return abs(c1 - c2) > 2;
}

static bool pixelsDiffer(SkColor p1, SkColor p2)
{
    return pixelComponentsDiffer(SkColorGetA(p1), SkColorGetA(p2)) || pixelComponentsDiffer(SkColorGetR(p1), SkColorGetR(p2)) || pixelComponentsDiffer(SkColorGetG(p1), SkColorGetG(p2)) || pixelComponentsDiffer(SkColorGetB(p1), SkColorGetB(p2));
}

void GraphicsLayer::checkPaintUnderInvalidations(const SkPicture& newPicture)
{
    if (!drawsContent())
        return;

    RasterInvalidationTracking* tracking = rasterInvalidationTrackingMap().find(this);
    if (!tracking)
        return;

    if (!tracking->lastPaintedPicture)
        return;

    IntRect rect = intersection(tracking->lastInterestRect, interestRect());
    if (rect.isEmpty())
        return;

    SkBitmap oldBitmap;
    oldBitmap.allocPixels(
        SkImageInfo::MakeN32Premul(rect.width(), rect.height()));
    {
        SkCanvas canvas(oldBitmap);
        canvas.clear(SK_ColorTRANSPARENT);
        canvas.translate(-rect.x(), -rect.y());
        canvas.drawPicture(tracking->lastPaintedPicture.get());
    }

    SkBitmap newBitmap;
    newBitmap.allocPixels(
        SkImageInfo::MakeN32Premul(rect.width(), rect.height()));
    {
        SkCanvas canvas(newBitmap);
        canvas.clear(SK_ColorTRANSPARENT);
        canvas.translate(-rect.x(), -rect.y());
        canvas.drawPicture(&newPicture);
    }

    oldBitmap.lockPixels();
    newBitmap.lockPixels();
    int mismatchingPixels = 0;
    static const int maxMismatchesToReport = 50;
    for (int bitmapY = 0; bitmapY < rect.height(); ++bitmapY) {
        int layerY = bitmapY + rect.y();
        for (int bitmapX = 0; bitmapX < rect.width(); ++bitmapX) {
            int layerX = bitmapX + rect.x();
            SkColor oldPixel = oldBitmap.getColor(bitmapX, bitmapY);
            SkColor newPixel = newBitmap.getColor(bitmapX, bitmapY);
            if (pixelsDiffer(oldPixel, newPixel) && !tracking->rasterInvalidationRegionSinceLastPaint.contains(IntPoint(layerX, layerY))) {
                if (mismatchingPixels < maxMismatchesToReport) {
                    UnderPaintInvalidation underPaintInvalidation = { layerX, layerY,
                        oldPixel, newPixel };
                    tracking->underPaintInvalidations.push_back(underPaintInvalidation);
                    LOG(ERROR) << debugName()
                               << " Uninvalidated old/new pixels mismatch at " << layerX
                               << "," << layerY << " old:" << std::hex << oldPixel
                               << " new:" << newPixel;
                } else if (mismatchingPixels == maxMismatchesToReport) {
                    LOG(ERROR) << "and more...";
                }
                ++mismatchingPixels;
                *newBitmap.getAddr32(bitmapX, bitmapY) = SkColorSetARGB(0xFF, 0xA0, 0, 0); // Dark red.
            } else {
                *newBitmap.getAddr32(bitmapX, bitmapY) = SK_ColorTRANSPARENT;
            }
        }
    }
    oldBitmap.unlockPixels();
    newBitmap.unlockPixels();

    // Visualize under-invalidations by overlaying the new bitmap (containing red
    // pixels indicating under-invalidations, and transparent pixels otherwise)
    // onto the painting.
    SkPictureRecorder recorder;
    recorder.beginRecording(rect);
    recorder.getRecordingCanvas()->drawBitmap(newBitmap, rect.x(), rect.y());
    sk_sp<SkPicture> picture = recorder.finishRecordingAsPicture();
    getPaintController().appendDebugDrawingAfterCommit(
        *this, picture, offsetFromLayoutObjectWithSubpixelAccumulation());
=======
void GraphicsLayer::paint(GraphicsContext& context, const IntRect& clip)
{
    paintGraphicsLayerContents(context, clip);
}


void GraphicsLayer::notifyAnimationStarted(double monotonicTime, int group)
{
    if (m_client)
        m_client->notifyAnimationStarted(this, monotonicTime, group);
}

void GraphicsLayer::notifyAnimationFinished(double, int group)
{
    if (m_scrollableArea)
        m_scrollableArea->notifyCompositorAnimationFinished(group);
}

void GraphicsLayer::didScroll()
{
    if (m_scrollableArea) {
        DoublePoint newPosition = m_scrollableArea->minimumScrollPosition() + toDoubleSize(m_layer->layer()->scrollPositionDouble());

        // FrameView::setScrollPosition doesn't work for compositor commits (interacts poorly with programmatic scroll animations)
        // so we need to use the ScrollableArea version. The FrameView method should go away soon anyway.
        m_scrollableArea->ScrollableArea::setScrollPosition(newPosition, CompositorScroll);
    }
}

DisplayItemList* GraphicsLayer::displayItemList()
{
    if (!RuntimeEnabledFeatures::slimmingPaintEnabled())
        return 0;
    if (!m_displayItemList)
        m_displayItemList = DisplayItemList::create();
    return m_displayItemList.get();
>>>>>>> miniblink49
}

} // namespace blink

#ifndef NDEBUG
void showGraphicsLayerTree(const blink::GraphicsLayer* layer)
{
    if (!layer) {
<<<<<<< HEAD
        LOG(INFO) << "Cannot showGraphicsLayerTree for (nil).";
=======
        fprintf(stderr, "Cannot showGraphicsLayerTree for (nil).\n");
>>>>>>> miniblink49
        return;
    }

    String output = layer->layerTreeAsText(blink::LayerTreeIncludesDebugInfo);
<<<<<<< HEAD
    LOG(INFO) << output.utf8().data();
=======
    fprintf(stderr, "%s\n", output.utf8().data());
>>>>>>> miniblink49
}
#endif
