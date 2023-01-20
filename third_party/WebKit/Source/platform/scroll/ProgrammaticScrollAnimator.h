// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ProgrammaticScrollAnimator_h
#define ProgrammaticScrollAnimator_h

<<<<<<< HEAD
#include "platform/heap/Handle.h"
#include "platform/scroll/ScrollAnimatorCompositorCoordinator.h"
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"
#include <memory>
=======
#include "platform/geometry/FloatPoint.h"
#include "wtf/FastAllocBase.h"
#include "wtf/Noncopyable.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
>>>>>>> miniblink49

namespace blink {

class ScrollableArea;
<<<<<<< HEAD
class CompositorAnimationTimeline;
class CompositorScrollOffsetAnimationCurve;

// Animator for fixed-destination scrolls, such as those triggered by
// CSSOM View scroll APIs.
class ProgrammaticScrollAnimator : public ScrollAnimatorCompositorCoordinator {
    WTF_MAKE_NONCOPYABLE(ProgrammaticScrollAnimator);

public:
    static ProgrammaticScrollAnimator* create(ScrollableArea* scrollableArea)
    {
        return new ProgrammaticScrollAnimator(scrollableArea);
    }

    virtual ~ProgrammaticScrollAnimator();

    void scrollToOffsetWithoutAnimation(const ScrollOffset&);
    void animateToOffset(const ScrollOffset&);

    // ScrollAnimatorCompositorCoordinator implementation.
    void resetAnimationState() override;
    void cancelAnimation() override;
    void takeOverCompositorAnimation() override {};
    ScrollableArea* getScrollableArea() const override
    {
        return m_scrollableArea;
    }
    void tickAnimation(double monotonicTime) override;
    void updateCompositorAnimations() override;
    void notifyCompositorAnimationFinished(int groupId) override;
    void notifyCompositorAnimationAborted(int groupId) override {};
    void layerForCompositedScrollingDidChange(
        CompositorAnimationTimeline*) override;

    DECLARE_TRACE();
=======
class WebScrollOffsetAnimationCurve;

// Animator for fixed-destination scrolls, such as those triggered by
// CSSOM View scroll APIs.
class ProgrammaticScrollAnimator {
    WTF_MAKE_NONCOPYABLE(ProgrammaticScrollAnimator);
    WTF_MAKE_FAST_ALLOCATED(ProgrammaticScrollAnimator);
public:
    static PassOwnPtr<ProgrammaticScrollAnimator> create(ScrollableArea*);

    ~ProgrammaticScrollAnimator();

    void scrollToOffsetWithoutAnimation(const FloatPoint&);
    void animateToOffset(FloatPoint);
    void cancelAnimation();
    void tickAnimation(double monotonicTime);
    bool hasAnimationThatRequiresService() const;
    void updateCompositorAnimations();
    void layerForCompositedScrollingDidChange();
    void notifyCompositorAnimationFinished(int groupId);
>>>>>>> miniblink49

private:
    explicit ProgrammaticScrollAnimator(ScrollableArea*);

<<<<<<< HEAD
    void notifyOffsetChanged(const ScrollOffset&);

    Member<ScrollableArea> m_scrollableArea;
    std::unique_ptr<CompositorScrollOffsetAnimationCurve> m_animationCurve;
    ScrollOffset m_targetOffset;
    double m_startTime;
=======
    enum class RunState {
        // No animation.
        Idle,

        // Waiting to send an animation to the compositor. There might also
        // already be another animation running on the compositor that will need
        // to be canceled first.
        WaitingToSendToCompositor,

        // Running an animation on the compositor.
        RunningOnCompositor,

        // Running an animation on the main thread.
        RunningOnMainThread,

        // Waiting to cancel the animation currently running on the compositor.
        // There is no pending animation to replace the canceled animation.
        WaitingToCancelOnCompositor
    };

    void resetAnimationState();
    void notifyPositionChanged(const DoublePoint&);

    ScrollableArea* m_scrollableArea;
    OwnPtr<WebScrollOffsetAnimationCurve> m_animationCurve;
    FloatPoint m_targetOffset;
    double m_startTime;
    RunState m_runState;
    int m_compositorAnimationId;
    int m_compositorAnimationGroupId;
>>>>>>> miniblink49
};

} // namespace blink

#endif // ProgrammaticScrollAnimator_h
