/*
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
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

#ifndef ScrollTypes_h
#define ScrollTypes_h

#include "platform/geometry/FloatPoint.h"
#include "public/platform/WebGestureEvent.h"
#include "wtf/Assertions.h"

namespace blink {

// A ScrollOffset represents an offset from the scroll origin of a
// ScrollableArea.  Note that "scroll origin" is not the same as the layout
// concept of "location", nor is it necessarily coincident with the top/left of
// the ScrollableArea's overflow rect.  See core/layout/README.md for more
// information.
typedef FloatSize ScrollOffset;

inline ScrollOffset toScrollOffset(const FloatPoint& p)
{
    return ScrollOffset(p.x(), p.y());
}

enum OverlayScrollbarClipBehavior {
    IgnoreOverlayScrollbarSize,
    ExcludeOverlayScrollbarSizeForHitTesting
};

enum ScrollDirection {
    ScrollUpIgnoringWritingMode,
    ScrollDownIgnoringWritingMode,
    ScrollLeftIgnoringWritingMode,
    ScrollRightIgnoringWritingMode,

    ScrollBlockDirectionBackward,
    ScrollBlockDirectionForward,
    ScrollInlineDirectionBackward,
    ScrollInlineDirectionForward
};

enum ScrollDirectionPhysical { ScrollUp,
    ScrollDown,
    ScrollLeft,
    ScrollRight };

enum ScrollType {
    UserScroll,
    ProgrammaticScroll,
    ClampingScroll,
    CompositorScroll,
    AnchoringScroll
};

inline bool scrollTypeClearsFragmentAnchor(ScrollType scrollType)
{
    return scrollType == UserScroll || scrollType == ProgrammaticScroll || scrollType == CompositorScroll;
}

// Convert logical scroll direction to physical. Physical scroll directions are
// unaffected.
inline ScrollDirectionPhysical toPhysicalDirection(ScrollDirection direction,
    bool isVertical,
    bool isFlipped)
{
    switch (direction) {
    case ScrollBlockDirectionBackward: {
        if (isVertical) {
            if (!isFlipped)
                return ScrollUp;
            return ScrollDown;
        }
        if (!isFlipped)
            return ScrollLeft;
        return ScrollRight;
    }
    case ScrollBlockDirectionForward: {
        if (isVertical) {
            if (!isFlipped)
                return ScrollDown;
            return ScrollUp;
        }
        if (!isFlipped)
            return ScrollRight;
        return ScrollLeft;
    }
    case ScrollInlineDirectionBackward: {
        if (isVertical) {
            if (!isFlipped)
                return ScrollLeft;
            return ScrollRight;
        }
        if (!isFlipped)
            return ScrollUp;
        return ScrollDown;
    }
    case ScrollInlineDirectionForward: {
        if (isVertical) {
            if (!isFlipped)
                return ScrollRight;
            return ScrollLeft;
        }
        if (!isFlipped)
            return ScrollDown;
        return ScrollUp;
    }
    // Direction is already physical
    case ScrollUpIgnoringWritingMode:
        return ScrollUp;
    case ScrollDownIgnoringWritingMode:
        return ScrollDown;
    case ScrollLeftIgnoringWritingMode:
        return ScrollLeft;
    case ScrollRightIgnoringWritingMode:
        return ScrollRight;
    default:
        ASSERT_NOT_REACHED();
        break;
    }
    return ScrollUp;
}

inline ScrollDirection toScrollDirection(ScrollDirectionPhysical direction)
{
    switch (direction) {
    case ScrollUp:
        return ScrollUpIgnoringWritingMode;
    case ScrollDown:
        return ScrollDownIgnoringWritingMode;
    case ScrollLeft:
        return ScrollLeftIgnoringWritingMode;
    case ScrollRight:
        return ScrollRightIgnoringWritingMode;
    default:
        ASSERT_NOT_REACHED();
        break;
    }
    return ScrollUpIgnoringWritingMode;
}

enum ScrollGranularity {
    ScrollByLine,
    ScrollByPage,
    ScrollByDocument,
    ScrollByPixel,
    ScrollByPrecisePixel
};

enum ScrollInertialPhase {
    ScrollInertialPhaseUnknown,
    ScrollInertialPhaseNonMomentum,
    ScrollInertialPhaseMomentum
};

enum ScrollbarOrientation { HorizontalScrollbar,
    VerticalScrollbar };

enum ScrollbarMode { ScrollbarAuto,
    ScrollbarAlwaysOff,
    ScrollbarAlwaysOn };

enum ScrollbarControlSize { RegularScrollbar,
    SmallScrollbar };

typedef unsigned ScrollbarControlState;

enum ScrollbarControlStateMask {
    ActiveScrollbarState = 1,
    EnabledScrollbarState = 1 << 1,
    PressedScrollbarState = 1 << 2
};

enum ScrollbarPart {
    NoPart = 0,
    BackButtonStartPart = 1,
    ForwardButtonStartPart = 1 << 1,
    BackTrackPart = 1 << 2,
    ThumbPart = 1 << 3,
    ForwardTrackPart = 1 << 4,
    BackButtonEndPart = 1 << 5,
    ForwardButtonEndPart = 1 << 6,
    ScrollbarBGPart = 1 << 7,
    TrackBGPart = 1 << 8,
    AllParts = 0xffffffff
};

enum ScrollbarOverlayColorTheme {
    ScrollbarOverlayColorThemeDark,
    ScrollbarOverlayColorThemeLight
};

enum ScrollBehavior {
    ScrollBehaviorAuto,
    ScrollBehaviorInstant,
    ScrollBehaviorSmooth,
};

// The result of an attempt to scroll. If didScroll is true, then
// unusedScrollDelta gives the amount of the scroll delta that was not consumed
// by scrolling.
struct ScrollResult {
    STACK_ALLOCATED();
    explicit ScrollResult()
        : didScrollX(false)
        , didScrollY(false)
        , unusedScrollDeltaX(0)
        , unusedScrollDeltaY(0)
    {
    }
    ScrollResult(bool didScrollX,
        bool didScrollY,
        float unusedScrollDeltaX,
        float unusedScrollDeltaY)
        : didScrollX(didScrollX)
        , didScrollY(didScrollY)
        , unusedScrollDeltaX(unusedScrollDeltaX)
        , unusedScrollDeltaY(unusedScrollDeltaY)
    {
    }

    bool didScroll() { return didScrollX || didScrollY; }

    bool didScrollX;
    bool didScrollY;

    // In pixels.
    float unusedScrollDeltaX;
    float unusedScrollDeltaY;
};

inline ScrollOffset toScrollDelta(ScrollbarOrientation orientation,
    float delta)
{
    return orientation == HorizontalScrollbar ? ScrollOffset(delta, 0.0f)
                                              : ScrollOffset(0.0f, delta);
}

inline ScrollOffset toScrollDelta(ScrollDirectionPhysical dir, float delta)
{
    if (dir == ScrollUp || dir == ScrollLeft)
        delta = -delta;

    return (dir == ScrollLeft || dir == ScrollRight) ? ScrollOffset(delta, 0)
                                                     : ScrollOffset(0, delta);
}

inline ScrollGranularity toPlatformScrollGranularity(
    WebGestureEvent::ScrollUnits units)
{
    switch (units) {
    case WebGestureEvent::ScrollUnits::PrecisePixels:
        return ScrollGranularity::ScrollByPrecisePixel;
    case WebGestureEvent::ScrollUnits::Pixels:
        return ScrollGranularity::ScrollByPixel;
    case WebGestureEvent::ScrollUnits::Page:
        return ScrollGranularity::ScrollByPage;
    default:
        NOTREACHED();
        return ScrollGranularity::ScrollByPrecisePixel;
    }
}

typedef unsigned ScrollbarControlPartMask;

} // namespace blink

#endif
