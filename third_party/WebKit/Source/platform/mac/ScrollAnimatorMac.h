/*
 * Copyright (C) 2010, 2011 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ScrollAnimatorMac_h
#define ScrollAnimatorMac_h

#include "platform/Timer.h"
<<<<<<< HEAD
#include "platform/WebTaskRunner.h"
#include "platform/geometry/FloatPoint.h"
#include "platform/geometry/FloatSize.h"
#include "platform/geometry/IntRect.h"
#include "platform/heap/Handle.h"
#include "platform/scroll/ScrollAnimatorBase.h"
#include "wtf/RetainPtr.h"
#include <memory>

OBJC_CLASS BlinkScrollAnimationHelperDelegate;
OBJC_CLASS BlinkScrollbarPainterControllerDelegate;
OBJC_CLASS BlinkScrollbarPainterDelegate;
=======
#include "platform/geometry/FloatPoint.h"
#include "platform/geometry/FloatSize.h"
#include "platform/geometry/IntRect.h"
#include "platform/scroll/ScrollAnimator.h"
#include "wtf/RetainPtr.h"

OBJC_CLASS WebScrollAnimationHelperDelegate;
OBJC_CLASS WebScrollbarPainterControllerDelegate;
OBJC_CLASS WebScrollbarPainterDelegate;
>>>>>>> miniblink49

typedef id ScrollbarPainterController;

namespace blink {

class Scrollbar;

<<<<<<< HEAD
class PLATFORM_EXPORT ScrollAnimatorMac : public ScrollAnimatorBase {
    USING_PRE_FINALIZER(ScrollAnimatorMac, dispose);
=======
class PLATFORM_EXPORT ScrollAnimatorMac : public ScrollAnimator {
>>>>>>> miniblink49

public:
    ScrollAnimatorMac(ScrollableArea*);
    ~ScrollAnimatorMac() override;

<<<<<<< HEAD
    void dispose() override;

    void immediateScrollToOffsetForScrollAnimation(const ScrollOffset& newOffset);
=======
    void immediateScrollToPointForScrollAnimation(const FloatPoint& newPosition);
>>>>>>> miniblink49
    bool haveScrolledSincePageLoad() const { return m_haveScrolledSincePageLoad; }

    void updateScrollerStyle();

    bool scrollbarPaintTimerIsActive() const;
    void startScrollbarPaintTimer();
    void stopScrollbarPaintTimer();

<<<<<<< HEAD
    void sendContentAreaScrolledSoon(const ScrollOffset& scrollDelta);

    void setVisibleScrollerThumbRect(const IntRect&);

    DEFINE_INLINE_VIRTUAL_TRACE() { ScrollAnimatorBase::trace(visitor); }

private:
    RetainPtr<id> m_scrollAnimationHelper;
    RetainPtr<BlinkScrollAnimationHelperDelegate> m_scrollAnimationHelperDelegate;

    RetainPtr<ScrollbarPainterController> m_scrollbarPainterController;
    RetainPtr<BlinkScrollbarPainterControllerDelegate>
        m_scrollbarPainterControllerDelegate;
    RetainPtr<BlinkScrollbarPainterDelegate> m_horizontalScrollbarPainterDelegate;
    RetainPtr<BlinkScrollbarPainterDelegate> m_verticalScrollbarPainterDelegate;

    void initialScrollbarPaintTask();
    TaskHandle m_initialScrollbarPaintTaskHandle;

    void sendContentAreaScrolledTask();
    TaskHandle m_sendContentAreaScrolledTaskHandle;
    RefPtr<WebTaskRunner> m_taskRunner;
    ScrollOffset m_contentAreaScrolledTimerScrollDelta;

    ScrollResult userScroll(ScrollGranularity,
        const ScrollOffset& delta) override;
    void scrollToOffsetWithoutAnimation(const ScrollOffset&) override;

    void cancelAnimation() override;
=======
    void sendContentAreaScrolledSoon(const FloatSize& scrollDelta);

    void setVisibleScrollerThumbRect(const IntRect&);

    static bool canUseCoordinatedScrollbar();

private:
    RetainPtr<id> m_scrollAnimationHelper;
    RetainPtr<WebScrollAnimationHelperDelegate> m_scrollAnimationHelperDelegate;

    RetainPtr<ScrollbarPainterController> m_scrollbarPainterController;
    RetainPtr<WebScrollbarPainterControllerDelegate> m_scrollbarPainterControllerDelegate;
    RetainPtr<WebScrollbarPainterDelegate> m_horizontalScrollbarPainterDelegate;
    RetainPtr<WebScrollbarPainterDelegate> m_verticalScrollbarPainterDelegate;

    void initialScrollbarPaintTimerFired(Timer<ScrollAnimatorMac>*);
    Timer<ScrollAnimatorMac> m_initialScrollbarPaintTimer;

    void sendContentAreaScrolledTimerFired(Timer<ScrollAnimatorMac>*);
    Timer<ScrollAnimatorMac> m_sendContentAreaScrolledTimer;
    FloatSize m_contentAreaScrolledTimerScrollDelta;

    ScrollResultOneDimensional userScroll(ScrollbarOrientation, ScrollGranularity, float step, float delta) override;
    void scrollToOffsetWithoutAnimation(const FloatPoint&) override;

    void handleWheelEventPhase(PlatformWheelEventPhase) override;

    void cancelAnimations() override;
    void setIsActive() override;
>>>>>>> miniblink49

    void contentAreaWillPaint() const override;
    void mouseEnteredContentArea() const override;
    void mouseExitedContentArea() const override;
    void mouseMovedInContentArea() const override;
<<<<<<< HEAD
    void mouseEnteredScrollbar(Scrollbar&) const override;
    void mouseExitedScrollbar(Scrollbar&) const override;
    void contentsResized() const override;
    void contentAreaDidShow() const override;
    void contentAreaDidHide() const override;

    void finishCurrentScrollAnimations() override;

    void didAddVerticalScrollbar(Scrollbar&) override;
    void willRemoveVerticalScrollbar(Scrollbar&) override;
    void didAddHorizontalScrollbar(Scrollbar&) override;
    void willRemoveHorizontalScrollbar(Scrollbar&) override;

    void notifyContentAreaScrolled(const ScrollOffset& delta) override;

    bool setScrollbarsVisibleForTesting(bool) override;

    ScrollOffset adjustScrollOffsetIfNecessary(const ScrollOffset&) const;

    void immediateScrollTo(const ScrollOffset&);
=======
    void mouseEnteredScrollbar(Scrollbar*) const override;
    void mouseExitedScrollbar(Scrollbar*) const override;
    void willStartLiveResize() override;
    void contentsResized() const override;
    void willEndLiveResize() override;
    void contentAreaDidShow() const override;
    void contentAreaDidHide() const override;
    void didBeginScrollGesture() const;
    void didEndScrollGesture() const;
    void mayBeginScrollGesture() const;

    void finishCurrentScrollAnimations() override;

    void didAddVerticalScrollbar(Scrollbar*) override;
    void willRemoveVerticalScrollbar(Scrollbar*) override;
    void didAddHorizontalScrollbar(Scrollbar*) override;
    void willRemoveHorizontalScrollbar(Scrollbar*) override;

    bool shouldScrollbarParticipateInHitTesting(Scrollbar*) override;

    void notifyContentAreaScrolled(const FloatSize& delta) override;

    FloatPoint adjustScrollPositionIfNecessary(const FloatPoint&) const;

    void immediateScrollTo(const FloatPoint&);
>>>>>>> miniblink49

    bool m_haveScrolledSincePageLoad;
    bool m_needsScrollerStyleUpdate;
    IntRect m_visibleScrollerThumbRect;
};

} // namespace blink

#endif // ScrollAnimatorMac_h
