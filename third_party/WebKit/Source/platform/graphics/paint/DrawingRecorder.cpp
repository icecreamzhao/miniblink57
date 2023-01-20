// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/graphics/paint/DrawingRecorder.h"

#include "platform/RuntimeEnabledFeatures.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/GraphicsLayer.h"
<<<<<<< HEAD
#include "platform/graphics/paint/PaintController.h"
=======
#include "platform/graphics/paint/CachedDisplayItem.h"
#include "platform/graphics/paint/DisplayItemList.h"
>>>>>>> miniblink49
#include "third_party/skia/include/core/SkPicture.h"

namespace blink {

<<<<<<< HEAD
DrawingRecorder::DrawingRecorder(GraphicsContext& context,
    const DisplayItemClient& displayItemClient,
    DisplayItem::Type displayItemType,
    const FloatRect& floatCullRect)
    : m_context(context)
    , m_displayItemClient(displayItemClient)
    , m_displayItemType(displayItemType)
    , m_knownToBeOpaque(false)
#if DCHECK_IS_ON()
    , m_displayItemPosition(
          m_context.getPaintController().newDisplayItemList().size())
#endif
{
    if (context.getPaintController().displayItemConstructionIsDisabled())
        return;

    // Must check DrawingRecorder::useCachedDrawingIfPossible before creating the
    // DrawingRecorder.
    DCHECK(RuntimeEnabledFeatures::paintUnderInvalidationCheckingEnabled() || !useCachedDrawingIfPossible(m_context, m_displayItemClient, m_displayItemType));

    DCHECK(DisplayItem::isDrawingType(displayItemType));

#if DCHECK_IS_ON()
    context.setInDrawingRecorder(true);
#endif

    // Use the enclosing int rect, since pixel-snapping may be applied to the
    // bounds of the object during painting. Potentially expanding the cull rect
    // by a pixel or two also does not affect correctness, and is very unlikely to
    // matter for performance.
    IntRect cullRect = enclosingIntRect(floatCullRect);
    context.beginRecording(cullRect);

#if DCHECK_IS_ON()
    if (RuntimeEnabledFeatures::slimmingPaintStrictCullRectClippingEnabled()) {
        // Skia depends on the cull rect containing all of the display item
        // commands. When strict cull rect clipping is enabled, make this explicit.
        // This allows us to identify potential incorrect cull rects that might
        // otherwise be masked due to Skia internal optimizations.
        context.save();
        // Expand the verification clip by one pixel to account for Skia's
        // SkCanvas::getClipBounds() expansion, used in testing cull rects.
        // TODO(schenney) This is not the best place to do this. Ideally, we would
        // expand by one pixel in device (pixel) space, but to do that we would need
        // to add the verification mode to Skia.
        cullRect.inflate(1);
        context.clipRect(cullRect, NotAntiAliased, SkClipOp::kIntersect);
=======
bool DrawingRecorder::useCachedDrawingIfPossible(GraphicsContext& context, const DisplayItemClientWrapper& client, DisplayItem::Type type)
{
    if (!RuntimeEnabledFeatures::slimmingPaintEnabled())
        return false;

    ASSERT(context.displayItemList());
    ASSERT(DisplayItem::isDrawingType(type));

    if (context.displayItemList()->displayItemConstructionIsDisabled() || RuntimeEnabledFeatures::slimmingPaintUnderInvalidationCheckingEnabled())
        return false;

    if (!context.displayItemList()->clientCacheIsValid(client.displayItemClient()))
        return false;

    context.displayItemList()->createAndAppend<CachedDisplayItem>(client, DisplayItem::drawingTypeToCachedType(type));
    return true;
}

DrawingRecorder::DrawingRecorder(GraphicsContext& context, const DisplayItemClientWrapper& displayItemClient, DisplayItem::Type displayItemType, const FloatRect& cullRect)
    : m_context(context)
    , m_displayItemClient(displayItemClient)
    , m_displayItemType(displayItemType)
#if ENABLE(ASSERT)
    , m_displayItemPosition(RuntimeEnabledFeatures::slimmingPaintEnabled() ? m_context.displayItemList()->newDisplayItemsSize() : 0)
    , m_underInvalidationCheckingMode(DrawingDisplayItem::CheckPicture)
#endif
{
    if (!RuntimeEnabledFeatures::slimmingPaintEnabled())
        return;

    ASSERT(context.displayItemList());
    if (context.displayItemList()->displayItemConstructionIsDisabled())
        return;

    // Must check DrawingRecorder::useCachedDrawingIfPossible before creating the DrawingRecorder.
    ASSERT(!useCachedDrawingIfPossible(m_context, m_displayItemClient, m_displayItemType));

    ASSERT(DisplayItem::isDrawingType(displayItemType));

#if ENABLE(ASSERT)
    context.setInDrawingRecorder(true);
#endif

    context.beginRecording(cullRect);

#if ENABLE(ASSERT)
    if (RuntimeEnabledFeatures::slimmingPaintStrictCullRectClippingEnabled()) {
        // Skia depends on the cull rect containing all of the display item commands. When strict
        // cull rect clipping is enabled, make this explicit. This allows us to identify potential
        // incorrect cull rects that might otherwise be masked due to Skia internal optimizations.
        context.save();
        IntRect verificationClip = enclosingIntRect(cullRect);
        // Expand the verification clip by one pixel to account for Skia's SkCanvas::getClipBounds()
        // expansion, used in testing cull rects.
        // TODO(schenney) This is not the best place to do this. Ideally, we would expand by one pixel
        // in device (pixel) space, but to do that we would need to add the verification mode to Skia.
        verificationClip.inflate(1);
        context.clipRect(verificationClip, NotAntiAliased, SkRegion::kIntersect_Op);
>>>>>>> miniblink49
    }
#endif
}

DrawingRecorder::~DrawingRecorder()
{
<<<<<<< HEAD
    if (m_context.getPaintController().displayItemConstructionIsDisabled())
        return;

#if DCHECK_IS_ON()
=======
    if (!RuntimeEnabledFeatures::slimmingPaintEnabled())
        return;

    ASSERT(m_context.displayItemList());
    if (m_context.displayItemList()->displayItemConstructionIsDisabled())
        return;

#if ENABLE(ASSERT)
>>>>>>> miniblink49
    if (RuntimeEnabledFeatures::slimmingPaintStrictCullRectClippingEnabled())
        m_context.restore();

    m_context.setInDrawingRecorder(false);
<<<<<<< HEAD
    DCHECK(m_displayItemPosition == m_context.getPaintController().newDisplayItemList().size());
#endif

    sk_sp<const SkPicture> picture = m_context.endRecording();

#if DCHECK_IS_ON()
    if (!RuntimeEnabledFeatures::slimmingPaintStrictCullRectClippingEnabled() && !m_context.getPaintController().isForSkPictureBuilder() && m_displayItemClient.paintedOutputOfObjectHasNoEffectRegardlessOfSize()) {
        DCHECK_EQ(0, picture->approximateOpCount())
            << m_displayItemClient.debugName();
    }
#endif

    m_context.getPaintController().createAndAppend<DrawingDisplayItem>(
        m_displayItemClient, m_displayItemType, picture, m_knownToBeOpaque);
=======
    ASSERT(m_displayItemPosition == m_context.displayItemList()->newDisplayItemsSize());
#endif

    m_context.displayItemList()->createAndAppend<DrawingDisplayItem>(m_displayItemClient
        , m_displayItemType
        , m_context.endRecording()
#if ENABLE(ASSERT)
        , m_underInvalidationCheckingMode
#endif
        );
>>>>>>> miniblink49
}

} // namespace blink
