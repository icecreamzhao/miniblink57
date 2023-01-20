/*
 * Copyright (C) 2011 Apple Inc. All Rights Reserved.
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
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
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
#include "platform/scroll/ScrollbarTheme.h"

#include "platform/PlatformMouseEvent.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/graphics/Color.h"
#include "platform/graphics/GraphicsContext.h"
<<<<<<< HEAD
#include "platform/graphics/GraphicsContextStateSaver.h"
#include "platform/graphics/paint/CompositingRecorder.h"
#include "platform/graphics/paint/CullRect.h"
#include "platform/graphics/paint/DrawingDisplayItem.h"
#include "platform/graphics/paint/DrawingRecorder.h"
#include "platform/graphics/paint/PaintController.h"
#include "platform/scroll/Scrollbar.h"
=======
#include "platform/graphics/paint/DisplayItemList.h"
#include "platform/graphics/paint/DrawingDisplayItem.h"
#include "platform/graphics/paint/DrawingRecorder.h"
#include "platform/scroll/ScrollbarThemeClient.h"
>>>>>>> miniblink49
#include "platform/scroll/ScrollbarThemeMock.h"
#include "platform/scroll/ScrollbarThemeOverlayMock.h"
#include "public/platform/Platform.h"
#include "public/platform/WebPoint.h"
#include "public/platform/WebRect.h"
#include "public/platform/WebScrollbarBehavior.h"
<<<<<<< HEAD
#include "wtf/Optional.h"

#if !OS(MACOSX)
=======

#if !OS(MACOSX)
#include "public/platform/WebRect.h"
>>>>>>> miniblink49
#include "public/platform/WebThemeEngine.h"
#endif

namespace blink {

bool ScrollbarTheme::gMockScrollbarsEnabled = false;

<<<<<<< HEAD
static inline bool shouldPaintScrollbarPart(const IntRect& partRect,
    const CullRect& cullRect)
{
    return (!partRect.isEmpty()) || cullRect.intersectsCullRect(partRect);
}

bool ScrollbarTheme::paint(const Scrollbar& scrollbar,
    GraphicsContext& graphicsContext,
    const CullRect& cullRect)
{
    // Create the ScrollbarControlPartMask based on the cullRect
=======
static inline bool shouldPaintScrollbarPart(const IntRect& partRect, const IntRect& damageRect)
{
    return (RuntimeEnabledFeatures::slimmingPaintEnabled() && !partRect.isEmpty()) || damageRect.intersects(partRect);
}

bool ScrollbarTheme::paint(ScrollbarThemeClient* scrollbar, GraphicsContext* graphicsContext, const IntRect& damageRect)
{
    // Create the ScrollbarControlPartMask based on the damageRect
>>>>>>> miniblink49
    ScrollbarControlPartMask scrollMask = NoPart;

    IntRect backButtonStartPaintRect;
    IntRect backButtonEndPaintRect;
    IntRect forwardButtonStartPaintRect;
    IntRect forwardButtonEndPaintRect;
    if (hasButtons(scrollbar)) {
        backButtonStartPaintRect = backButtonRect(scrollbar, BackButtonStartPart, true);
<<<<<<< HEAD
        if (shouldPaintScrollbarPart(backButtonStartPaintRect, cullRect))
            scrollMask |= BackButtonStartPart;
        backButtonEndPaintRect = backButtonRect(scrollbar, BackButtonEndPart, true);
        if (shouldPaintScrollbarPart(backButtonEndPaintRect, cullRect))
            scrollMask |= BackButtonEndPart;
        forwardButtonStartPaintRect = forwardButtonRect(scrollbar, ForwardButtonStartPart, true);
        if (shouldPaintScrollbarPart(forwardButtonStartPaintRect, cullRect))
            scrollMask |= ForwardButtonStartPart;
        forwardButtonEndPaintRect = forwardButtonRect(scrollbar, ForwardButtonEndPart, true);
        if (shouldPaintScrollbarPart(forwardButtonEndPaintRect, cullRect))
=======
        if (shouldPaintScrollbarPart(backButtonStartPaintRect, damageRect))
            scrollMask |= BackButtonStartPart;
        backButtonEndPaintRect = backButtonRect(scrollbar, BackButtonEndPart, true);
        if (shouldPaintScrollbarPart(backButtonEndPaintRect, damageRect))
            scrollMask |= BackButtonEndPart;
        forwardButtonStartPaintRect = forwardButtonRect(scrollbar, ForwardButtonStartPart, true);
        if (shouldPaintScrollbarPart(forwardButtonStartPaintRect, damageRect))
            scrollMask |= ForwardButtonStartPart;
        forwardButtonEndPaintRect = forwardButtonRect(scrollbar, ForwardButtonEndPart, true);
        if (shouldPaintScrollbarPart(forwardButtonEndPaintRect, damageRect))
>>>>>>> miniblink49
            scrollMask |= ForwardButtonEndPart;
    }

    IntRect startTrackRect;
    IntRect thumbRect;
    IntRect endTrackRect;
    IntRect trackPaintRect = trackRect(scrollbar, true);
<<<<<<< HEAD
    scrollMask |= TrackBGPart;
=======
    if (RuntimeEnabledFeatures::slimmingPaintEnabled() || damageRect.intersects(trackPaintRect))
        scrollMask |= TrackBGPart;
>>>>>>> miniblink49
    bool thumbPresent = hasThumb(scrollbar);
    if (thumbPresent) {
        IntRect track = trackRect(scrollbar);
        splitTrack(scrollbar, track, startTrackRect, thumbRect, endTrackRect);
<<<<<<< HEAD
        if (shouldPaintScrollbarPart(thumbRect, cullRect))
            scrollMask |= ThumbPart;
        if (shouldPaintScrollbarPart(startTrackRect, cullRect))
            scrollMask |= BackTrackPart;
        if (shouldPaintScrollbarPart(endTrackRect, cullRect))
=======
        if (shouldPaintScrollbarPart(thumbRect, damageRect))
            scrollMask |= ThumbPart;
        if (shouldPaintScrollbarPart(startTrackRect, damageRect))
            scrollMask |= BackTrackPart;
        if (shouldPaintScrollbarPart(endTrackRect, damageRect))
>>>>>>> miniblink49
            scrollMask |= ForwardTrackPart;
    }

    // Paint the scrollbar background (only used by custom CSS scrollbars).
    paintScrollbarBackground(graphicsContext, scrollbar);

    // Paint the back and forward buttons.
    if (scrollMask & BackButtonStartPart)
<<<<<<< HEAD
        paintButton(graphicsContext, scrollbar, backButtonStartPaintRect,
            BackButtonStartPart);
    if (scrollMask & BackButtonEndPart)
        paintButton(graphicsContext, scrollbar, backButtonEndPaintRect,
            BackButtonEndPart);
    if (scrollMask & ForwardButtonStartPart)
        paintButton(graphicsContext, scrollbar, forwardButtonStartPaintRect,
            ForwardButtonStartPart);
    if (scrollMask & ForwardButtonEndPart)
        paintButton(graphicsContext, scrollbar, forwardButtonEndPaintRect,
            ForwardButtonEndPart);
=======
        paintButton(graphicsContext, scrollbar, backButtonStartPaintRect, BackButtonStartPart);
    if (scrollMask & BackButtonEndPart)
        paintButton(graphicsContext, scrollbar, backButtonEndPaintRect, BackButtonEndPart);
    if (scrollMask & ForwardButtonStartPart)
        paintButton(graphicsContext, scrollbar, forwardButtonStartPaintRect, ForwardButtonStartPart);
    if (scrollMask & ForwardButtonEndPart)
        paintButton(graphicsContext, scrollbar, forwardButtonEndPaintRect, ForwardButtonEndPart);
>>>>>>> miniblink49

    if (scrollMask & TrackBGPart)
        paintTrackBackground(graphicsContext, scrollbar, trackPaintRect);

    if ((scrollMask & ForwardTrackPart) || (scrollMask & BackTrackPart)) {
        // Paint the track pieces above and below the thumb.
        if (scrollMask & BackTrackPart)
<<<<<<< HEAD
            paintTrackPiece(graphicsContext, scrollbar, startTrackRect,
                BackTrackPart);
        if (scrollMask & ForwardTrackPart)
            paintTrackPiece(graphicsContext, scrollbar, endTrackRect,
                ForwardTrackPart);
=======
            paintTrackPiece(graphicsContext, scrollbar, startTrackRect, BackTrackPart);
        if (scrollMask & ForwardTrackPart)
            paintTrackPiece(graphicsContext, scrollbar, endTrackRect, ForwardTrackPart);
>>>>>>> miniblink49

        paintTickmarks(graphicsContext, scrollbar, trackPaintRect);
    }

    // Paint the thumb.
<<<<<<< HEAD
    if (scrollMask & ThumbPart) {
        Optional<CompositingRecorder> compositingRecorder;
        float opacity = thumbOpacity(scrollbar);
        if (opacity != 1.0f) {
            FloatRect floatThumbRect(thumbRect);
            floatThumbRect.inflate(1); // some themes inflate thumb bounds
            compositingRecorder.emplace(graphicsContext, scrollbar,
                SkBlendMode::kSrcOver, opacity,
                &floatThumbRect);
        }

        paintThumb(graphicsContext, scrollbar, thumbRect);
    }
=======
    if (scrollMask & ThumbPart)
        paintThumb(graphicsContext, scrollbar, thumbRect);
>>>>>>> miniblink49

    return true;
}

<<<<<<< HEAD
ScrollbarPart ScrollbarTheme::hitTest(const ScrollbarThemeClient& scrollbar,
    const IntPoint& positionInRootFrame)
{
    ScrollbarPart result = NoPart;
    if (!scrollbar.enabled())
        return result;

    IntPoint testPosition = scrollbar.convertFromRootFrame(positionInRootFrame);
    testPosition.move(scrollbar.x(), scrollbar.y());

    if (!scrollbar.frameRect().contains(testPosition))
=======
ScrollbarPart ScrollbarTheme::hitTest(ScrollbarThemeClient* scrollbar, const IntPoint& position)
{
    ScrollbarPart result = NoPart;
    if (!scrollbar->enabled())
        return result;

    IntPoint testPosition = scrollbar->convertFromContainingWindow(position);
    testPosition.move(scrollbar->x(), scrollbar->y());

    if (!scrollbar->frameRect().contains(testPosition))
>>>>>>> miniblink49
        return NoPart;

    result = ScrollbarBGPart;

    IntRect track = trackRect(scrollbar);
    if (track.contains(testPosition)) {
        IntRect beforeThumbRect;
        IntRect thumbRect;
        IntRect afterThumbRect;
        splitTrack(scrollbar, track, beforeThumbRect, thumbRect, afterThumbRect);
        if (thumbRect.contains(testPosition))
            result = ThumbPart;
        else if (beforeThumbRect.contains(testPosition))
            result = BackTrackPart;
        else if (afterThumbRect.contains(testPosition))
            result = ForwardTrackPart;
        else
            result = TrackBGPart;
<<<<<<< HEAD
    } else if (backButtonRect(scrollbar, BackButtonStartPart)
                   .contains(testPosition)) {
        result = BackButtonStartPart;
    } else if (backButtonRect(scrollbar, BackButtonEndPart)
                   .contains(testPosition)) {
        result = BackButtonEndPart;
    } else if (forwardButtonRect(scrollbar, ForwardButtonStartPart)
                   .contains(testPosition)) {
        result = ForwardButtonStartPart;
    } else if (forwardButtonRect(scrollbar, ForwardButtonEndPart)
                   .contains(testPosition)) {
=======
    } else if (backButtonRect(scrollbar, BackButtonStartPart).contains(testPosition)) {
        result = BackButtonStartPart;
    } else if (backButtonRect(scrollbar, BackButtonEndPart).contains(testPosition)) {
        result = BackButtonEndPart;
    } else if (forwardButtonRect(scrollbar, ForwardButtonStartPart).contains(testPosition)) {
        result = ForwardButtonStartPart;
    } else if (forwardButtonRect(scrollbar, ForwardButtonEndPart).contains(testPosition)) {
>>>>>>> miniblink49
        result = ForwardButtonEndPart;
    }
    return result;
}

<<<<<<< HEAD
void ScrollbarTheme::paintScrollCorner(
    GraphicsContext& context,
    const DisplayItemClient& displayItemClient,
    const IntRect& cornerRect)
=======
void ScrollbarTheme::invalidatePart(ScrollbarThemeClient* scrollbar, ScrollbarPart part)
{
    if (part == NoPart)
        return;

    IntRect result;
    switch (part) {
    case BackButtonStartPart:
        result = backButtonRect(scrollbar, BackButtonStartPart, true);
        break;
    case BackButtonEndPart:
        result = backButtonRect(scrollbar, BackButtonEndPart, true);
        break;
    case ForwardButtonStartPart:
        result = forwardButtonRect(scrollbar, ForwardButtonStartPart, true);
        break;
    case ForwardButtonEndPart:
        result = forwardButtonRect(scrollbar, ForwardButtonEndPart, true);
        break;
    case TrackBGPart:
        result = trackRect(scrollbar, true);
        break;
    case ScrollbarBGPart:
        result = scrollbar->frameRect();
        break;
    default: {
        IntRect beforeThumbRect, thumbRect, afterThumbRect;
        splitTrack(scrollbar, trackRect(scrollbar), beforeThumbRect, thumbRect, afterThumbRect);
        if (part == BackTrackPart)
            result = beforeThumbRect;
        else if (part == ForwardTrackPart)
            result = afterThumbRect;
        else
            result = thumbRect;
    }
    }
    result.moveBy(-scrollbar->location());
    scrollbar->invalidateRect(result);
}

void ScrollbarTheme::paintScrollCorner(GraphicsContext* context, const DisplayItemClientWrapper& displayItemClient, const IntRect& cornerRect)
>>>>>>> miniblink49
{
    if (cornerRect.isEmpty())
        return;

<<<<<<< HEAD
    if (DrawingRecorder::useCachedDrawingIfPossible(
            context, displayItemClient, DisplayItem::kScrollbarCorner))
        return;

    DrawingRecorder recorder(context, displayItemClient,
        DisplayItem::kScrollbarCorner, cornerRect);
#if OS(MACOSX)
    context.fillRect(cornerRect, Color::white);
#else
    Platform::current()->themeEngine()->paint(
        context.canvas(), WebThemeEngine::PartScrollbarCorner,
        WebThemeEngine::StateNormal, WebRect(cornerRect), 0);
#endif
}

bool ScrollbarTheme::shouldCenterOnThumb(const ScrollbarThemeClient& scrollbar,
    const PlatformMouseEvent& evt)
{
    return Platform::current()->scrollbarBehavior()->shouldCenterOnThumb(
        evt.pointerProperties().button, evt.shiftKey(), evt.altKey());
}

void ScrollbarTheme::paintTickmarks(GraphicsContext& context,
    const Scrollbar& scrollbar,
    const IntRect& rect)
{
// Android paints tickmarks in the browser at FindResultBar.java.
#if !OS(ANDROID)
    if (scrollbar.orientation() != VerticalScrollbar)
        return;

    if (rect.height() <= 0 || rect.width() <= 0)
        return;

    // Get the tickmarks for the frameview.
    Vector<IntRect> tickmarks;
    scrollbar.getTickmarks(tickmarks);
    if (!tickmarks.size())
        return;

    if (DrawingRecorder::useCachedDrawingIfPossible(
            context, scrollbar, DisplayItem::kScrollbarTickmarks))
        return;

    DrawingRecorder recorder(context, scrollbar, DisplayItem::kScrollbarTickmarks,
        rect);
    GraphicsContextStateSaver stateSaver(context);
    context.setShouldAntialias(false);

    for (Vector<IntRect>::const_iterator i = tickmarks.begin();
         i != tickmarks.end(); ++i) {
        // Calculate how far down (in %) the tick-mark should appear.
        const float percent = static_cast<float>(i->y()) / scrollbar.totalSize();

        // Calculate how far down (in pixels) the tick-mark should appear.
        const int yPos = rect.y() + (rect.height() * percent);

        FloatRect tickRect(rect.x(), yPos, rect.width(), 3);
        context.fillRect(tickRect, Color(0xCC, 0xAA, 0x00, 0xFF));

        FloatRect tickStroke(rect.x() + tickmarkBorderWidth(), yPos + 1,
            rect.width() - 2 * tickmarkBorderWidth(), 1);
        context.fillRect(tickStroke, Color(0xFF, 0xDD, 0x00, 0xFF));
    }
#endif
}

bool ScrollbarTheme::shouldSnapBackToDragOrigin(
    const ScrollbarThemeClient& scrollbar,
    const PlatformMouseEvent& evt)
{
    IntPoint mousePosition = scrollbar.convertFromRootFrame(evt.position());
    mousePosition.move(scrollbar.x(), scrollbar.y());
    return Platform::current()->scrollbarBehavior()->shouldSnapBackToDragOrigin(
        mousePosition, trackRect(scrollbar),
        scrollbar.orientation() == HorizontalScrollbar);
}

double ScrollbarTheme::overlayScrollbarFadeOutDelaySeconds() const
{
    // On Mac, fading is controlled by the painting code in ScrollAnimatorMac.
    return 0.0;
}

double ScrollbarTheme::overlayScrollbarFadeOutDurationSeconds() const
{
    // On Mac, fading is controlled by the painting code in ScrollAnimatorMac.
    return 0.0;
}

int ScrollbarTheme::thumbPosition(const ScrollbarThemeClient& scrollbar,
    float scrollPosition)
{
    if (scrollbar.enabled()) {
        float size = scrollbar.totalSize() - scrollbar.visibleSize();
        // Avoid doing a floating point divide by zero and return 1 when
        // usedTotalSize == visibleSize.
        if (!size)
            return 0;
        float pos = std::max(0.0f, scrollPosition) * (trackLength(scrollbar) - thumbLength(scrollbar)) / size;
=======
    if (DrawingRecorder::useCachedDrawingIfPossible(*context, displayItemClient, DisplayItem::ScrollbarCorner))
        return;

    DrawingRecorder recorder(*context, displayItemClient, DisplayItem::ScrollbarCorner, cornerRect);
#if OS(MACOSX)
    context->fillRect(cornerRect, Color::white);
#else
    Platform::current()->themeEngine()->paint(context->canvas(), WebThemeEngine::PartScrollbarCorner, WebThemeEngine::StateNormal, WebRect(cornerRect), 0);
#endif
}

bool ScrollbarTheme::shouldCenterOnThumb(ScrollbarThemeClient* scrollbar, const PlatformMouseEvent& evt)
{
    return Platform::current()->scrollbarBehavior()->shouldCenterOnThumb(static_cast<WebScrollbarBehavior::Button>(evt.button()), evt.shiftKey(), evt.altKey());
}

bool ScrollbarTheme::shouldSnapBackToDragOrigin(ScrollbarThemeClient* scrollbar, const PlatformMouseEvent& evt)
{
    IntPoint mousePosition = scrollbar->convertFromContainingWindow(evt.position());
    mousePosition.move(scrollbar->x(), scrollbar->y());
    return Platform::current()->scrollbarBehavior()->shouldSnapBackToDragOrigin(mousePosition, trackRect(scrollbar), scrollbar->orientation() == HorizontalScrollbar);
}

int ScrollbarTheme::thumbPosition(ScrollbarThemeClient* scrollbar)
{
    if (scrollbar->enabled()) {
        float size = scrollbar->totalSize() - scrollbar->visibleSize();
        // Avoid doing a floating point divide by zero and return 1 when usedTotalSize == visibleSize.
        if (!size)
            return 0;
        float pos = std::max(0.0f, scrollbar->currentPos()) * (trackLength(scrollbar) - thumbLength(scrollbar)) / size;
>>>>>>> miniblink49
        return (pos < 1 && pos > 0) ? 1 : pos;
    }
    return 0;
}

<<<<<<< HEAD
int ScrollbarTheme::thumbLength(const ScrollbarThemeClient& scrollbar)
{
    if (!scrollbar.enabled())
        return 0;

    float overhang = fabsf(scrollbar.elasticOverscroll());
    float proportion = 0.0f;
    float totalSize = scrollbar.totalSize();
    if (totalSize > 0.0f) {
        proportion = (scrollbar.visibleSize() - overhang) / totalSize;
=======
int ScrollbarTheme::thumbLength(ScrollbarThemeClient* scrollbar)
{
    if (!scrollbar->enabled())
        return 0;

    float overhang = fabsf(scrollbar->elasticOverscroll());
    float proportion = 0.0f;
    float totalSize = scrollbar->totalSize();
    if (totalSize > 0.0f) {
        proportion = (scrollbar->visibleSize() - overhang) / totalSize;
>>>>>>> miniblink49
    }
    int trackLen = trackLength(scrollbar);
    int length = round(proportion * trackLen);
    length = std::max(length, minimumThumbLength(scrollbar));
    if (length > trackLen)
<<<<<<< HEAD
        length = 0; // Once the thumb is below the track length, it just goes away
            // (to make more room for the track).
    return length;
}

int ScrollbarTheme::trackPosition(const ScrollbarThemeClient& scrollbar)
{
    IntRect constrainedTrackRect = constrainTrackRectToTrackPieces(scrollbar, trackRect(scrollbar));
    return (scrollbar.orientation() == HorizontalScrollbar)
        ? constrainedTrackRect.x() - scrollbar.x()
        : constrainedTrackRect.y() - scrollbar.y();
}

int ScrollbarTheme::trackLength(const ScrollbarThemeClient& scrollbar)
{
    IntRect constrainedTrackRect = constrainTrackRectToTrackPieces(scrollbar, trackRect(scrollbar));
    return (scrollbar.orientation() == HorizontalScrollbar)
        ? constrainedTrackRect.width()
        : constrainedTrackRect.height();
}

IntRect ScrollbarTheme::thumbRect(const ScrollbarThemeClient& scrollbar)
=======
        length = 0; // Once the thumb is below the track length, it just goes away (to make more room for the track).
    return length;
}

int ScrollbarTheme::trackPosition(ScrollbarThemeClient* scrollbar)
{
    IntRect constrainedTrackRect = constrainTrackRectToTrackPieces(scrollbar, trackRect(scrollbar));
    return (scrollbar->orientation() == HorizontalScrollbar) ? constrainedTrackRect.x() - scrollbar->x() : constrainedTrackRect.y() - scrollbar->y();
}

int ScrollbarTheme::trackLength(ScrollbarThemeClient* scrollbar)
{
    IntRect constrainedTrackRect = constrainTrackRectToTrackPieces(scrollbar, trackRect(scrollbar));
    return (scrollbar->orientation() == HorizontalScrollbar) ? constrainedTrackRect.width() : constrainedTrackRect.height();
}

IntRect ScrollbarTheme::thumbRect(ScrollbarThemeClient* scrollbar)
>>>>>>> miniblink49
{
    if (!hasThumb(scrollbar))
        return IntRect();

    IntRect track = trackRect(scrollbar);
    IntRect startTrackRect;
    IntRect thumbRect;
    IntRect endTrackRect;
    splitTrack(scrollbar, track, startTrackRect, thumbRect, endTrackRect);

    return thumbRect;
}

<<<<<<< HEAD
int ScrollbarTheme::thumbThickness(const ScrollbarThemeClient& scrollbar)
{
    IntRect track = trackRect(scrollbar);
    return scrollbar.orientation() == HorizontalScrollbar ? track.height()
                                                          : track.width();
}

int ScrollbarTheme::minimumThumbLength(const ScrollbarThemeClient& scrollbar)
{
    return scrollbarThickness(scrollbar.controlSize());
}

void ScrollbarTheme::splitTrack(const ScrollbarThemeClient& scrollbar,
    const IntRect& unconstrainedTrackRect,
    IntRect& beforeThumbRect,
    IntRect& thumbRect,
    IntRect& afterThumbRect)
{
    // This function won't even get called unless we're big enough to have some
    // combination of these three rects where at least one of them is non-empty.
    IntRect trackRect = constrainTrackRectToTrackPieces(scrollbar, unconstrainedTrackRect);
    int thumbPos = thumbPosition(scrollbar);
    if (scrollbar.orientation() == HorizontalScrollbar) {
        thumbRect = IntRect(trackRect.x() + thumbPos, trackRect.y(),
            thumbLength(scrollbar), scrollbar.height());
        beforeThumbRect = IntRect(trackRect.x(), trackRect.y(), thumbPos + thumbRect.width() / 2,
            trackRect.height());
        afterThumbRect = IntRect(trackRect.x() + beforeThumbRect.width(), trackRect.y(),
            trackRect.maxX() - beforeThumbRect.maxX(), trackRect.height());
    } else {
        thumbRect = IntRect(trackRect.x(), trackRect.y() + thumbPos,
            scrollbar.width(), thumbLength(scrollbar));
        beforeThumbRect = IntRect(trackRect.x(), trackRect.y(), trackRect.width(),
            thumbPos + thumbRect.height() / 2);
        afterThumbRect = IntRect(trackRect.x(), trackRect.y() + beforeThumbRect.height(),
            trackRect.width(), trackRect.maxY() - beforeThumbRect.maxY());
    }
}

ScrollbarTheme& ScrollbarTheme::theme()
=======
int ScrollbarTheme::thumbThickness(ScrollbarThemeClient* scrollbar)
{
    IntRect track = trackRect(scrollbar);
    return scrollbar->orientation() == HorizontalScrollbar ? track.height() : track.width();
}

int ScrollbarTheme::minimumThumbLength(ScrollbarThemeClient* scrollbar)
{
    return scrollbarThickness(scrollbar->controlSize());
}

void ScrollbarTheme::splitTrack(ScrollbarThemeClient* scrollbar, const IntRect& unconstrainedTrackRect, IntRect& beforeThumbRect, IntRect& thumbRect, IntRect& afterThumbRect)
{
    // This function won't even get called unless we're big enough to have some combination of these three rects where at least
    // one of them is non-empty.
    IntRect trackRect = constrainTrackRectToTrackPieces(scrollbar, unconstrainedTrackRect);
    int thumbPos = thumbPosition(scrollbar);
    if (scrollbar->orientation() == HorizontalScrollbar) {
        thumbRect = IntRect(trackRect.x() + thumbPos, trackRect.y(), thumbLength(scrollbar), scrollbar->height());
        beforeThumbRect = IntRect(trackRect.x(), trackRect.y(), thumbPos + thumbRect.width() / 2, trackRect.height());
        afterThumbRect = IntRect(trackRect.x() + beforeThumbRect.width(), trackRect.y(), trackRect.maxX() - beforeThumbRect.maxX(), trackRect.height());
    } else {
        thumbRect = IntRect(trackRect.x(), trackRect.y() + thumbPos, scrollbar->width(), thumbLength(scrollbar));
        beforeThumbRect = IntRect(trackRect.x(), trackRect.y(), trackRect.width(), thumbPos + thumbRect.height() / 2);
        afterThumbRect = IntRect(trackRect.x(), trackRect.y() + beforeThumbRect.height(), trackRect.width(), trackRect.maxY() - beforeThumbRect.maxY());
    }
}

ScrollbarTheme* ScrollbarTheme::theme()
>>>>>>> miniblink49
{
    if (ScrollbarTheme::mockScrollbarsEnabled()) {
        if (RuntimeEnabledFeatures::overlayScrollbarsEnabled()) {
            DEFINE_STATIC_LOCAL(ScrollbarThemeOverlayMock, overlayMockTheme, ());
<<<<<<< HEAD
            return overlayMockTheme;
        }

        DEFINE_STATIC_LOCAL(ScrollbarThemeMock, mockTheme, ());
        return mockTheme;
=======
            return &overlayMockTheme;
        }

        DEFINE_STATIC_LOCAL(ScrollbarThemeMock, mockTheme, ());
        return &mockTheme;
>>>>>>> miniblink49
    }
    return nativeTheme();
}

void ScrollbarTheme::setMockScrollbarsEnabled(bool flag)
{
    gMockScrollbarsEnabled = flag;
}

bool ScrollbarTheme::mockScrollbarsEnabled()
{
    return gMockScrollbarsEnabled;
}

<<<<<<< HEAD
DisplayItem::Type ScrollbarTheme::buttonPartToDisplayItemType(
    ScrollbarPart part)
{
    switch (part) {
    case BackButtonStartPart:
        return DisplayItem::kScrollbarBackButtonStart;
    case BackButtonEndPart:
        return DisplayItem::kScrollbarBackButtonEnd;
    case ForwardButtonStartPart:
        return DisplayItem::kScrollbarForwardButtonStart;
    case ForwardButtonEndPart:
        return DisplayItem::kScrollbarForwardButtonEnd;
    default:
        ASSERT_NOT_REACHED();
        return DisplayItem::kScrollbarBackButtonStart;
    }
}

DisplayItem::Type ScrollbarTheme::trackPiecePartToDisplayItemType(
    ScrollbarPart part)
{
    switch (part) {
    case BackTrackPart:
        return DisplayItem::kScrollbarBackTrack;
    case ForwardTrackPart:
        return DisplayItem::kScrollbarForwardTrack;
    default:
        ASSERT_NOT_REACHED();
        return DisplayItem::kScrollbarBackTrack;
=======
DisplayItem::Type ScrollbarTheme::buttonPartToDisplayItemType(ScrollbarPart part)
{
    switch (part) {
    case BackButtonStartPart:
        return DisplayItem::ScrollbarBackButtonStart;
    case BackButtonEndPart:
        return DisplayItem::ScrollbarBackButtonEnd;
    case ForwardButtonStartPart:
        return DisplayItem::ScrollbarForwardButtonStart;
    case ForwardButtonEndPart:
        return DisplayItem::ScrollbarForwardButtonEnd;
    default:
        ASSERT_NOT_REACHED();
        return DisplayItem::ScrollbarBackButtonStart;
    }
}

DisplayItem::Type ScrollbarTheme::trackPiecePartToDisplayItemType(ScrollbarPart part)
{
    switch (part) {
    case BackTrackPart:
        return DisplayItem::ScrollbarBackTrack;
    case ForwardTrackPart:
        return DisplayItem::ScrollbarForwardTrack;
    default:
        ASSERT_NOT_REACHED();
        return DisplayItem::ScrollbarBackTrack;
>>>>>>> miniblink49
    }
}

} // namespace blink
