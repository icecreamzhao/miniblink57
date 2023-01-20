/*
 * Copyright (C) 2008, 2011 Apple Inc. All Rights Reserved.
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

#ifndef ScrollableArea_h
#define ScrollableArea_h

#include "platform/PlatformExport.h"
#include "platform/RuntimeEnabledFeatures.h"
<<<<<<< HEAD
#include "platform/geometry/FloatQuad.h"
#include "platform/geometry/LayoutRect.h"
#include "platform/graphics/Color.h"
#include "platform/heap/Handle.h"
#include "platform/scroll/ScrollAnimatorBase.h"
#include "platform/scroll/ScrollTypes.h"
#include "platform/scroll/Scrollbar.h"
#include "wtf/MathExtras.h"
=======
#include "platform/geometry/DoublePoint.h"
#include "platform/heap/Handle.h"
#include "platform/scroll/ScrollAnimator.h"
#include "platform/scroll/ScrollTypes.h"
#include "platform/scroll/Scrollbar.h"
>>>>>>> miniblink49
#include "wtf/Noncopyable.h"
#include "wtf/Vector.h"

namespace blink {

<<<<<<< HEAD
class CompositorAnimationHost;
class CompositorAnimationTimeline;
class GraphicsLayer;
class HostWindow;
class LayoutBox;
class LayoutObject;
class PaintLayer;
class ProgrammaticScrollAnimator;
struct ScrollAlignment;
class ScrollAnchor;
class ScrollAnimatorBase;
class CompositorAnimationTimeline;
=======
class DoubleRect;
class FloatPoint;
class GraphicsLayer;
class HostWindow;
class PlatformWheelEvent;
class ProgrammaticScrollAnimator;
struct ScrollAlignment;
class ScrollAnimator;

enum ScrollBehavior {
    ScrollBehaviorAuto,
    ScrollBehaviorInstant,
    ScrollBehaviorSmooth,
};
>>>>>>> miniblink49

enum IncludeScrollbarsInRect {
    ExcludeScrollbars,
    IncludeScrollbars,
};

<<<<<<< HEAD
class PLATFORM_EXPORT ScrollableArea : public GarbageCollectedMixin {
    WTF_MAKE_NONCOPYABLE(ScrollableArea);

public:
    static int pixelsPerLineStep(HostWindow*);
=======
#if ENABLE(OILPAN)
// Oilpan: Using the transition type WillBeGarbageCollectedMixin is
// problematic non-Oilpan as the type expands to DummyBase, exporting it
// also from 'platform' as a result. Bringing about duplicate DummyBases
// as core also exports same; with component build linking fails as a
// result. Hence the workaround of not using a transition type.
class PLATFORM_EXPORT ScrollableArea : public GarbageCollectedMixin {
#else
class PLATFORM_EXPORT ScrollableArea {
#endif
    WTF_MAKE_NONCOPYABLE(ScrollableArea);
public:
    static int pixelsPerLineStep();
>>>>>>> miniblink49
    static float minFractionToStepWhenPaging();
    static int maxOverlapBetweenPages();

    // Convert a non-finite scroll value (Infinity, -Infinity, NaN) to 0 as
    // per http://dev.w3.org/csswg/cssom-view/#normalize-non_finite-values.
<<<<<<< HEAD
    static float normalizeNonFiniteScroll(float value)
    {
        return std_isfinite(value) ? value : 0.0;
    }

    // The window that hosts the ScrollableArea. The ScrollableArea will
    // communicate scrolls and repaints to the host window in the window's
    // coordinate space.
    virtual HostWindow* getHostWindow() const { return 0; }

    virtual ScrollResult userScroll(ScrollGranularity, const ScrollOffset&);

    virtual void setScrollOffset(const ScrollOffset&,
        ScrollType,
        ScrollBehavior = ScrollBehaviorInstant);
    virtual void scrollBy(const ScrollOffset&,
        ScrollType,
        ScrollBehavior = ScrollBehaviorInstant);
    void setScrollOffsetSingleAxis(ScrollbarOrientation,
        float,
        ScrollType,
        ScrollBehavior = ScrollBehaviorInstant);

    // Scrolls the area so that the given rect, given in the document's content
    // coordinates, such that it's visible in the area. Returns the new location
    // of the input rect relative once again to the document.
    // Note, in the case of a Document container, such as FrameView, the output
    // will always be the input rect since scrolling it can't change the location
    // of content relative to the document, unlike an overflowing element.
    virtual LayoutRect scrollIntoView(const LayoutRect& rectInContent,
        const ScrollAlignment& alignX,
        const ScrollAlignment& alignY,
        ScrollType = ProgrammaticScroll);

    // Returns a rect, in the space of the area's backing graphics layer, that
    // contains the visual region of all scrollbar parts.
    virtual LayoutRect visualRectForScrollbarParts() const = 0;

    static bool scrollBehaviorFromString(const String&, ScrollBehavior&);

=======
    static double normalizeNonFiniteScroll(double value) { return std::isfinite(value) ? value : 0.0; }

    // The window that hosts the ScrollableArea. The ScrollableArea will communicate scrolls and repaints to the
    // host window in the window's coordinate space.
    virtual HostWindow* hostWindow() const { return 0; }

    virtual ScrollResultOneDimensional userScroll(ScrollDirectionPhysical, ScrollGranularity, float delta = 1);

    virtual void setScrollPosition(const DoublePoint&, ScrollType, ScrollBehavior = ScrollBehaviorInstant);
    virtual void scrollBy(const DoubleSize&, ScrollType, ScrollBehavior = ScrollBehaviorInstant);
    void setScrollPositionSingleAxis(ScrollbarOrientation, double, ScrollType, ScrollBehavior = ScrollBehaviorInstant);

    // Scrolls the area so that the given rect, given in the document's content coordinates, such that it's
    // visible in the area. Returns the new location of the input rect relative once again to the document.
    // Note, in the case of a Document container, such as FrameView, the output will always be the input rect
    // since scrolling it can't change the location of content relative to the document, unlike an overflowing
    // element.
    virtual LayoutRect scrollIntoView(const LayoutRect& rectInContent, const ScrollAlignment& alignX, const ScrollAlignment& alignY);

    // Scrolls the area so that the given rect, given in the area's content coordinates, such that it's
    // cenetered in the second rect, which is given relative to the area's origin.
    void scrollIntoRect(const LayoutRect& rectInContent, const FloatRect& targetRectInFrame);

    static bool scrollBehaviorFromString(const String&, ScrollBehavior&);

    virtual ScrollResult handleWheel(const PlatformWheelEvent&);

    bool inLiveResize() const { return m_inLiveResize; }
    void willStartLiveResize();
    void willEndLiveResize();

>>>>>>> miniblink49
    void contentAreaWillPaint() const;
    void mouseEnteredContentArea() const;
    void mouseExitedContentArea() const;
    void mouseMovedInContentArea() const;
<<<<<<< HEAD
    void mouseEnteredScrollbar(Scrollbar&);
    void mouseExitedScrollbar(Scrollbar&);
    void mouseCapturedScrollbar();
    void mouseReleasedScrollbar();
=======
    void mouseEnteredScrollbar(Scrollbar*) const;
    void mouseExitedScrollbar(Scrollbar*) const;
>>>>>>> miniblink49
    void contentAreaDidShow() const;
    void contentAreaDidHide() const;

    void finishCurrentScrollAnimations() const;

<<<<<<< HEAD
    virtual void didAddScrollbar(Scrollbar&, ScrollbarOrientation);
    virtual void willRemoveScrollbar(Scrollbar&, ScrollbarOrientation);

    // Called when this ScrollableArea becomes or unbecomes the global root
    // scroller.
    virtual void didChangeGlobalRootScroller() { }
=======
    virtual void didAddScrollbar(Scrollbar*, ScrollbarOrientation);
    virtual void willRemoveScrollbar(Scrollbar*, ScrollbarOrientation);
>>>>>>> miniblink49

    virtual void contentsResized();

    bool hasOverlayScrollbars() const;
<<<<<<< HEAD
    void setScrollbarOverlayColorTheme(ScrollbarOverlayColorTheme);
    void recalculateScrollbarOverlayColorTheme(Color);
    ScrollbarOverlayColorTheme getScrollbarOverlayColorTheme() const
    {
        return static_cast<ScrollbarOverlayColorTheme>(
            m_scrollbarOverlayColorTheme);
    }

    // This getter will create a ScrollAnimatorBase if it doesn't already exist.
    ScrollAnimatorBase& scrollAnimator() const;

    // This getter will return null if the ScrollAnimatorBase hasn't been created
    // yet.
    ScrollAnimatorBase* existingScrollAnimator() const
    {
        return m_scrollAnimator;
    }

    ProgrammaticScrollAnimator& programmaticScrollAnimator() const;
    ProgrammaticScrollAnimator* existingProgrammaticScrollAnimator() const
    {
        return m_programmaticScrollAnimator;
    }

    virtual CompositorAnimationHost* compositorAnimationHost() const
    {
        return nullptr;
    }
    virtual CompositorAnimationTimeline* compositorAnimationTimeline() const
    {
        return nullptr;
    }

    // See Source/core/layout/README.md for an explanation of scroll origin.
    const IntPoint& scrollOrigin() const { return m_scrollOrigin; }
    bool scrollOriginChanged() const { return m_scrollOriginChanged; }

    // This is used to determine whether the incoming fractional scroll offset
    // should be truncated to integer. Current rule is that if
    // preferCompositingToLCDTextEnabled() is disabled (which is true on low-dpi
    // device by default) we should do the truncation.  The justification is that
    // non-composited elements using fractional scroll offsets is causing too much
    // nasty bugs but does not add too benefit on low-dpi devices.
    // TODO(szager): Now that scroll offsets are floats everywhere, can we get rid
    // of this?
    virtual bool shouldUseIntegerScrollOffset() const
    {
        return !RuntimeEnabledFeatures::fractionalScrollOffsetsEnabled();
    }

    virtual bool isActive() const = 0;
    virtual int scrollSize(ScrollbarOrientation) const = 0;
    void setScrollbarNeedsPaintInvalidation(ScrollbarOrientation);
    virtual bool isScrollCornerVisible() const = 0;
    virtual IntRect scrollCornerRect() const = 0;
    void setScrollCornerNeedsPaintInvalidation();
    virtual void getTickmarks(Vector<IntRect>&) const { }

    // Convert points and rects between the scrollbar and its containing Widget.
    // The client needs to implement these in order to be aware of layout effects
    // like CSS transforms.
    virtual IntRect convertFromScrollbarToContainingWidget(
        const Scrollbar& scrollbar,
        const IntRect& scrollbarRect) const
    {
        return scrollbar.Widget::convertToContainingWidget(scrollbarRect);
    }
    virtual IntRect convertFromContainingWidgetToScrollbar(
        const Scrollbar& scrollbar,
        const IntRect& parentRect) const
    {
        return scrollbar.Widget::convertFromContainingWidget(parentRect);
    }
    virtual IntPoint convertFromScrollbarToContainingWidget(
        const Scrollbar& scrollbar,
        const IntPoint& scrollbarPoint) const
    {
        return scrollbar.Widget::convertToContainingWidget(scrollbarPoint);
    }
    virtual IntPoint convertFromContainingWidgetToScrollbar(
        const Scrollbar& scrollbar,
        const IntPoint& parentPoint) const
    {
        return scrollbar.Widget::convertFromContainingWidget(parentPoint);
    }

    virtual Scrollbar* horizontalScrollbar() const { return nullptr; }
    virtual Scrollbar* verticalScrollbar() const { return nullptr; }

    virtual PaintLayer* layer() const { return nullptr; }

    // scrollPosition is the location of the top/left of the scroll viewport in
    // the coordinate system defined by the top/left of the overflow rect.
    // scrollOffset is the offset of the scroll viewport from its position when
    // scrolled all the way to the beginning of its content's flow.
    // For a more detailed explanation of scrollPosition, scrollOffset, and
    // scrollOrigin, see core/layout/README.md.
    FloatPoint scrollPosition() const
    {
        return FloatPoint(scrollOrigin()) + getScrollOffset();
    }
    virtual IntSize scrollOffsetInt() const = 0;
    virtual ScrollOffset getScrollOffset() const
    {
        return ScrollOffset(scrollOffsetInt());
    }
    virtual IntSize minimumScrollOffsetInt() const = 0;
    virtual ScrollOffset minimumScrollOffset() const
    {
        return ScrollOffset(minimumScrollOffsetInt());
    }
    virtual IntSize maximumScrollOffsetInt() const = 0;
    virtual ScrollOffset maximumScrollOffset() const
    {
        return ScrollOffset(maximumScrollOffsetInt());
    }

    virtual IntRect visibleContentRect(
        IncludeScrollbarsInRect = ExcludeScrollbars) const;
=======
    void setScrollbarOverlayStyle(ScrollbarOverlayStyle);
    ScrollbarOverlayStyle scrollbarOverlayStyle() const { return static_cast<ScrollbarOverlayStyle>(m_scrollbarOverlayStyle); }

    // This getter will create a ScrollAnimator if it doesn't already exist.
    ScrollAnimator* scrollAnimator() const;

    // This getter will return null if the ScrollAnimator hasn't been created yet.
    ScrollAnimator* existingScrollAnimator() const { return m_animators ? m_animators->scrollAnimator.get() : 0; }

    ProgrammaticScrollAnimator* programmaticScrollAnimator() const;
    ProgrammaticScrollAnimator* existingProgrammaticScrollAnimator() const
    {
        return m_animators ? m_animators->programmaticScrollAnimator.get() : 0;
    }

    const IntPoint& scrollOrigin() const { return m_scrollOrigin; }
    bool scrollOriginChanged() const { return m_scrollOriginChanged; }


    // This is used to determine whether the incoming fractional scroll offset should
    // be truncated to integer. Current rule is that if preferCompositingToLCDTextEnabled()
    // is disabled (which is true on low-dpi device by default) we should do the truncation.
    // The justification is that non-composited elements using fractional scroll offsets
    // is causing too much nasty bugs but does not add too benefit on low-dpi devices.
    virtual bool shouldUseIntegerScrollOffset() const { return !RuntimeEnabledFeatures::fractionalScrollOffsetsEnabled(); }

    virtual bool isActive() const = 0;
    virtual int scrollSize(ScrollbarOrientation) const = 0;
    virtual void invalidateScrollbar(Scrollbar*, const IntRect&);
    virtual bool isScrollCornerVisible() const = 0;
    virtual IntRect scrollCornerRect() const = 0;
    virtual void invalidateScrollCorner(const IntRect&);
    virtual void getTickmarks(Vector<IntRect>&) const { }

    // Convert points and rects between the scrollbar and its containing view.
    // The client needs to implement these in order to be aware of layout effects
    // like CSS transforms.
    virtual IntRect convertFromScrollbarToContainingView(const Scrollbar* scrollbar, const IntRect& scrollbarRect) const
    {
        return scrollbar->Widget::convertToContainingView(scrollbarRect);
    }
    virtual IntRect convertFromContainingViewToScrollbar(const Scrollbar* scrollbar, const IntRect& parentRect) const
    {
        return scrollbar->Widget::convertFromContainingView(parentRect);
    }
    virtual IntPoint convertFromScrollbarToContainingView(const Scrollbar* scrollbar, const IntPoint& scrollbarPoint) const
    {
        return scrollbar->Widget::convertToContainingView(scrollbarPoint);
    }
    virtual IntPoint convertFromContainingViewToScrollbar(const Scrollbar* scrollbar, const IntPoint& parentPoint) const
    {
        return scrollbar->Widget::convertFromContainingView(parentPoint);
    }

    virtual Scrollbar* horizontalScrollbar() const { return 0; }
    virtual Scrollbar* verticalScrollbar() const { return 0; }

    // scrollPosition is relative to the scrollOrigin. i.e. If the page is RTL
    // then scrollPosition will be negative. By default, scrollPositionDouble()
    // just call into scrollPosition(). Subclass can override scrollPositionDouble()
    // to return floating point precision scrolloffset.
    // FIXME: Remove scrollPosition(). crbug.com/414283.
    virtual IntPoint scrollPosition() const = 0;
    virtual DoublePoint scrollPositionDouble() const { return DoublePoint(scrollPosition()); }
    virtual IntPoint minimumScrollPosition() const = 0;
    virtual DoublePoint minimumScrollPositionDouble() const { return DoublePoint(minimumScrollPosition()); }
    virtual IntPoint maximumScrollPosition() const = 0;
    virtual DoublePoint maximumScrollPositionDouble() const { return DoublePoint(maximumScrollPosition()); }

    virtual DoubleRect visibleContentRectDouble(IncludeScrollbarsInRect = ExcludeScrollbars) const;
    virtual IntRect visibleContentRect(IncludeScrollbarsInRect = ExcludeScrollbars) const;
>>>>>>> miniblink49
    virtual int visibleHeight() const { return visibleContentRect().height(); }
    virtual int visibleWidth() const { return visibleContentRect().width(); }
    virtual IntSize contentsSize() const = 0;
    virtual IntPoint lastKnownMousePosition() const { return IntPoint(); }

    virtual bool shouldSuspendScrollAnimations() const { return true; }
    virtual void scrollbarStyleChanged() { }
<<<<<<< HEAD
    virtual bool scrollbarsCanBeActive() const = 0;

    // Returns the bounding box of this scrollable area, in the coordinate system
    // of the enclosing scroll view.
=======

    virtual bool scrollbarsCanBeActive() const = 0;

    // Returns the bounding box of this scrollable area, in the coordinate system of the enclosing scroll view.
>>>>>>> miniblink49
    virtual IntRect scrollableAreaBoundingBox() const = 0;

    virtual bool scrollAnimatorEnabled() const { return false; }

    // NOTE: Only called from Internals for testing.
<<<<<<< HEAD
    void updateScrollOffsetFromInternals(const IntSize&);

    IntSize clampScrollOffset(const IntSize&) const;
    ScrollOffset clampScrollOffset(const ScrollOffset&) const;

    // Let subclasses provide a way of asking for and servicing scroll
    // animations.
    virtual bool scheduleAnimation();
=======
    void setScrollOffsetFromInternals(const IntPoint&);

    IntPoint clampScrollPosition(const IntPoint&) const;
    DoublePoint clampScrollPosition(const DoublePoint&) const;

    // Let subclasses provide a way of asking for and servicing scroll
    // animations.
    bool scheduleAnimation();
>>>>>>> miniblink49
    virtual void serviceScrollAnimations(double monotonicTime);
    virtual void updateCompositorScrollAnimations();
    virtual void registerForAnimation() { }
    virtual void deregisterForAnimation() { }

<<<<<<< HEAD
    virtual bool usesCompositedScrolling() const { return false; }
    virtual bool shouldScrollOnMainThread() const;

    // Overlay scrollbars can "fade-out" when inactive.
    virtual bool scrollbarsHidden() const;
    virtual void setScrollbarsHidden(bool);
=======
    void notifyCompositorAnimationFinished(int groupId);

    virtual bool usesCompositedScrolling() const { return false; }
>>>>>>> miniblink49

    // Returns true if the GraphicsLayer tree needs to be rebuilt.
    virtual bool updateAfterCompositingChange() { return false; }

    virtual bool userInputScrollable(ScrollbarOrientation) const = 0;
    virtual bool shouldPlaceVerticalScrollbarOnLeft() const = 0;

    // Convenience functions
<<<<<<< HEAD
    float minimumScrollOffset(ScrollbarOrientation orientation)
    {
        return orientation == HorizontalScrollbar ? minimumScrollOffset().width()
                                                  : minimumScrollOffset().height();
    }
    float maximumScrollOffset(ScrollbarOrientation orientation)
    {
        return orientation == HorizontalScrollbar ? maximumScrollOffset().width()
                                                  : maximumScrollOffset().height();
    }
    float clampScrollOffset(ScrollbarOrientation orientation, float offset)
    {
        return clampTo(offset, minimumScrollOffset(orientation),
            maximumScrollOffset(orientation));
=======
    int scrollPosition(ScrollbarOrientation orientation) { return orientation == HorizontalScrollbar ? scrollPosition().x() : scrollPosition().y(); }
    int minimumScrollPosition(ScrollbarOrientation orientation) { return orientation == HorizontalScrollbar ? minimumScrollPosition().x() : minimumScrollPosition().y(); }
    int maximumScrollPosition(ScrollbarOrientation orientation) { return orientation == HorizontalScrollbar ? maximumScrollPosition().x() : maximumScrollPosition().y(); }
    int clampScrollPosition(ScrollbarOrientation orientation, int pos)  { return std::max(std::min(pos, maximumScrollPosition(orientation)), minimumScrollPosition(orientation)); }

    bool hasVerticalBarDamage() const { return !m_verticalBarDamage.isEmpty(); }
    bool hasHorizontalBarDamage() const { return !m_horizontalBarDamage.isEmpty(); }
    const IntRect& verticalBarDamage() const { return m_verticalBarDamage; }
    const IntRect& horizontalBarDamage() const { return m_horizontalBarDamage; }

    void addScrollbarDamage(Scrollbar* scrollbar, const IntRect& rect)
    {
        if (scrollbar == horizontalScrollbar())
            m_horizontalBarDamage.unite(rect);
        else
            m_verticalBarDamage.unite(rect);
    }

    void resetScrollbarDamage()
    {
        m_verticalBarDamage = IntRect();
        m_horizontalBarDamage = IntRect();
>>>>>>> miniblink49
    }

    virtual GraphicsLayer* layerForContainer() const;
    virtual GraphicsLayer* layerForScrolling() const { return 0; }
    virtual GraphicsLayer* layerForHorizontalScrollbar() const { return 0; }
    virtual GraphicsLayer* layerForVerticalScrollbar() const { return 0; }
    virtual GraphicsLayer* layerForScrollCorner() const { return 0; }
    bool hasLayerForHorizontalScrollbar() const;
    bool hasLayerForVerticalScrollbar() const;
    bool hasLayerForScrollCorner() const;

<<<<<<< HEAD
    void layerForScrollingDidChange(CompositorAnimationTimeline*);

    void cancelScrollAnimation();
    virtual void cancelProgrammaticScrollAnimation();

    virtual ~ScrollableArea();

    // Called when any of horizontal scrollbar, vertical scrollbar and scroll
    // corner is setNeedsPaintInvalidation.
    virtual void scrollControlWasSetNeedsPaintInvalidation() = 0;
=======
    void layerForScrollingDidChange();

    void cancelScrollAnimation();
    void cancelProgrammaticScrollAnimation();

    virtual ~ScrollableArea();

    virtual void invalidateScrollbarRect(Scrollbar*, const IntRect&) = 0;
    virtual void invalidateScrollCornerRect(const IntRect&) = 0;
>>>>>>> miniblink49

    // Returns the default scroll style this area should scroll with when not
    // explicitly specified. E.g. The scrolling behavior of an element can be
    // specified in CSS.
<<<<<<< HEAD
    virtual ScrollBehavior scrollBehaviorStyle() const
    {
        return ScrollBehaviorInstant;
    }

    // TODO(bokan): FrameView::setScrollOffset uses updateScrollbars to scroll
    // which bails out early if its already in updateScrollbars, the effect being
    // that programmatic scrolls (i.e. setScrollOffset) are disabled when in
=======
    virtual ScrollBehavior scrollBehaviorStyle() const { return ScrollBehaviorInstant; }

    // TODO(bokan): This is only used in FrameView to check scrollability but is
    // needed here to allow RootFrameViewport to preserve wheelHandler
    // semantics. Not sure why it's FrameView specific, it could probably be
    // generalized to other types of ScrollableAreas.
    virtual bool isScrollable() { return true; }

    // TODO(bokan): FrameView::setScrollPosition uses updateScrollbars to scroll
    // which bails out early if its already in updateScrollbars, the effect being
    // that programmatic scrolls (i.e. setScrollPosition) are disabled when in
>>>>>>> miniblink49
    // updateScrollbars. Expose this here to allow RootFrameViewport to match the
    // semantics for now but it should be cleaned up at the source.
    virtual bool isProgrammaticallyScrollable() { return true; }

    // Subtracts space occupied by this ScrollableArea's scrollbars.
    // Does nothing if overlay scrollbars are enabled.
<<<<<<< HEAD
    IntSize excludeScrollbars(const IntSize&) const;

    virtual int verticalScrollbarWidth(
        OverlayScrollbarClipBehavior = IgnoreOverlayScrollbarSize) const;
    virtual int horizontalScrollbarHeight(
        OverlayScrollbarClipBehavior = IgnoreOverlayScrollbarSize) const;

    // Returns the widget associated with this ScrollableArea.
    virtual Widget* getWidget() { return nullptr; }

    virtual LayoutBox* layoutBox() const { return nullptr; }

    // Maps a quad from the coordinate system of a LayoutObject contained by the
    // ScrollableArea to the coordinate system of the ScrollableArea's visible
    // content rect.  If the LayoutObject* argument is null, the argument quad is
    // considered to be in the coordinate space of the overflow rect.
    virtual FloatQuad localToVisibleContentQuad(const FloatQuad&,
        const LayoutObject*,
        unsigned = 0) const;

    virtual bool isFrameView() const { return false; }
    virtual bool isPaintLayerScrollableArea() const { return false; }
    virtual bool isRootFrameViewport() const { return false; }

    // Returns true if the scroller adjusts the scroll offset to compensate
    // for layout movements (bit.ly/scroll-anchoring).
    virtual bool shouldPerformScrollAnchoring() const { return false; }

    // Need to promptly let go of owned animator objects.
    EAGERLY_FINALIZE();
    DECLARE_VIRTUAL_TRACE();

    virtual void clearScrollableArea();

    virtual ScrollAnchor* scrollAnchor() { return nullptr; }

    virtual void didScrollWithScrollbar(ScrollbarPart, ScrollbarOrientation) { }
=======
    virtual IntSize excludeScrollbars(const IntSize&) const;

    // Need to promptly let go of owned animator objects.
    EAGERLY_FINALIZE();
    DEFINE_INLINE_VIRTUAL_TRACE() { }
>>>>>>> miniblink49

protected:
    ScrollableArea();

<<<<<<< HEAD
    ScrollbarOrientation scrollbarOrientationFromDirection(
        ScrollDirectionPhysical) const;
    float scrollStep(ScrollGranularity, ScrollbarOrientation) const;

    void setScrollOrigin(const IntPoint&);
    void resetScrollOriginChanged() { m_scrollOriginChanged = false; }

    // Needed to let the animators call scrollOffsetChanged.
    friend class ScrollAnimatorCompositorCoordinator;
    void scrollOffsetChanged(const ScrollOffset&, ScrollType);

    bool horizontalScrollbarNeedsPaintInvalidation() const
    {
        return m_horizontalScrollbarNeedsPaintInvalidation;
    }
    bool verticalScrollbarNeedsPaintInvalidation() const
    {
        return m_verticalScrollbarNeedsPaintInvalidation;
    }
    bool scrollCornerNeedsPaintInvalidation() const
    {
        return m_scrollCornerNeedsPaintInvalidation;
    }
    void clearNeedsPaintInvalidationForScrollControls()
    {
        m_horizontalScrollbarNeedsPaintInvalidation = false;
        m_verticalScrollbarNeedsPaintInvalidation = false;
        m_scrollCornerNeedsPaintInvalidation = false;
    }
    void showOverlayScrollbars();

    // Called when scrollbar hides/shows for overlay scrollbars. This callback
    // shouldn't do any significant work as it can be called unexpectadly often
    // on Mac. This happens because painting code has to set alpha to 1, paint,
    // then reset to alpha, causing spurrious "visibilityChanged" calls.
    virtual void scrollbarVisibilityChanged() { }

private:
    void programmaticScrollHelper(const ScrollOffset&, ScrollBehavior);
    void userScrollHelper(const ScrollOffset&, ScrollBehavior);

    void fadeOverlayScrollbarsTimerFired(TimerBase*);

    // This function should be overriden by subclasses to perform the actual
    // scroll of the content.
    virtual void updateScrollOffset(const ScrollOffset&, ScrollType) = 0;
=======
    void setScrollOrigin(const IntPoint&);
    void resetScrollOriginChanged() { m_scrollOriginChanged = false; }

    // Needed to let the animators call scrollPositionChanged.
    friend class ScrollAnimator;
    friend class ProgrammaticScrollAnimator;
    void scrollPositionChanged(const DoublePoint&, ScrollType);

    void clearScrollAnimators();

private:
    void programmaticScrollHelper(const DoublePoint&, ScrollBehavior);
    void userScrollHelper(const DoublePoint&, ScrollBehavior);

    // This function should be overriden by subclasses to perform the actual
    // scroll of the content. By default the DoublePoint version will just
    // call into the IntPoint version. If fractional scroll is needed, one
    // can override the DoublePoint version to take advantage of the double
    // precision scroll offset.
    // FIXME: Remove the IntPoint version. And change the function to
    // take DoubleSize. crbug.com/414283.
    virtual void setScrollOffset(const IntPoint&, ScrollType) = 0;
    virtual void setScrollOffset(const DoublePoint& offset, ScrollType scrollType)
    {
        setScrollOffset(flooredIntPoint(offset), scrollType);
    }
>>>>>>> miniblink49

    virtual int lineStep(ScrollbarOrientation) const;
    virtual int pageStep(ScrollbarOrientation) const;
    virtual int documentStep(ScrollbarOrientation) const;
    virtual float pixelStep(ScrollbarOrientation) const;

<<<<<<< HEAD
    mutable Member<ScrollAnimatorBase> m_scrollAnimator;
    mutable Member<ProgrammaticScrollAnimator> m_programmaticScrollAnimator;

    std::unique_ptr<Timer<ScrollableArea>> m_fadeOverlayScrollbarsTimer;

    unsigned m_scrollbarOverlayColorTheme : 2;

    unsigned m_scrollOriginChanged : 1;

    unsigned m_horizontalScrollbarNeedsPaintInvalidation : 1;
    unsigned m_verticalScrollbarNeedsPaintInvalidation : 1;
    unsigned m_scrollCornerNeedsPaintInvalidation : 1;
    unsigned m_scrollbarsHidden : 1;
    unsigned m_scrollbarCaptured : 1;
    unsigned m_mouseOverScrollbar : 1;

    // There are 6 possible combinations of writing mode and direction. Scroll
    // origin will be non-zero in the x or y axis if there is any reversed
    // direction or writing-mode. The combinations are:
    // writing-mode / direction     scrollOrigin.x() set    scrollOrigin.y() set
    // horizontal-tb / ltr          NO                      NO
    // horizontal-tb / rtl          YES                     NO
=======
    // Stores the paint invalidations for the scrollbars during layout.
    IntRect m_horizontalBarDamage;
    IntRect m_verticalBarDamage;

    struct ScrollableAreaAnimators {
        OwnPtr<ScrollAnimator> scrollAnimator;
        OwnPtr<ProgrammaticScrollAnimator> programmaticScrollAnimator;
    };

    mutable OwnPtr<ScrollableAreaAnimators> m_animators;

    unsigned m_inLiveResize : 1;

    unsigned m_scrollbarOverlayStyle : 2; // ScrollbarOverlayStyle

    unsigned m_scrollOriginChanged : 1;

    // There are 8 possible combinations of writing mode and direction. Scroll origin will be non-zero in the x or y axis
    // if there is any reversed direction or writing-mode. The combinations are:
    // writing-mode / direction     scrollOrigin.x() set    scrollOrigin.y() set
    // horizontal-tb / ltr          NO                      NO
    // horizontal-tb / rtl          YES                     NO
    // horizontal-bt / ltr          NO                      YES
    // horizontal-bt / rtl          YES                     YES
>>>>>>> miniblink49
    // vertical-lr / ltr            NO                      NO
    // vertical-lr / rtl            NO                      YES
    // vertical-rl / ltr            YES                     NO
    // vertical-rl / rtl            YES                     YES
    IntPoint m_scrollOrigin;
};

} // namespace blink

#endif // ScrollableArea_h
