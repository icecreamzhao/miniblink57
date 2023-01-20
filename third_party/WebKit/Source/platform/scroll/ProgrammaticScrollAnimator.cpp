// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/scroll/ProgrammaticScrollAnimator.h"

#include "platform/animation/CompositorAnimation.h"
#include "platform/animation/CompositorScrollOffsetAnimationCurve.h"
#include "platform/geometry/IntSize.h"
#include "platform/graphics/GraphicsLayer.h"
#include "platform/scroll/ScrollableArea.h"
#include "public/platform/Platform.h"
#include "public/platform/WebCompositorSupport.h"
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

ProgrammaticScrollAnimator::ProgrammaticScrollAnimator(
    ScrollableArea* scrollableArea)
    : m_scrollableArea(scrollableArea)
    , m_startTime(0.0)
{
}

ProgrammaticScrollAnimator::~ProgrammaticScrollAnimator() { }

void ProgrammaticScrollAnimator::resetAnimationState()
{
    ScrollAnimatorCompositorCoordinator::resetAnimationState();
    m_animationCurve.reset();
    m_startTime = 0.0;
}

void ProgrammaticScrollAnimator::notifyOffsetChanged(
    const ScrollOffset& offset)
{
    scrollOffsetChanged(offset, ProgrammaticScroll);
}

void ProgrammaticScrollAnimator::scrollToOffsetWithoutAnimation(
    const ScrollOffset& offset)
{
    cancelAnimation();
    notifyOffsetChanged(offset);
}

void ProgrammaticScrollAnimator::animateToOffset(const ScrollOffset& offset)
{
    if (m_runState == RunState::PostAnimationCleanup)
        resetAnimationState();

    m_startTime = 0.0;
    m_targetOffset = offset;
    m_animationCurve = CompositorScrollOffsetAnimationCurve::create(
        compositorOffsetFromBlinkOffset(m_targetOffset),
        CompositorScrollOffsetAnimationCurve::ScrollDurationDeltaBased);

    m_scrollableArea->registerForAnimation();
    if (!m_scrollableArea->scheduleAnimation()) {
        resetAnimationState();
        notifyOffsetChanged(offset);
=======
#include "config.h"
#include "platform/scroll/ProgrammaticScrollAnimator.h"

#include "platform/geometry/IntPoint.h"
#include "platform/graphics/GraphicsLayer.h"
#include "platform/scroll/ScrollableArea.h"
#include "public/platform/Platform.h"
#include "public/platform/WebCompositorAnimation.h"
#include "public/platform/WebCompositorSupport.h"
#include "public/platform/WebScrollOffsetAnimationCurve.h"

namespace blink {

PassOwnPtr<ProgrammaticScrollAnimator> ProgrammaticScrollAnimator::create(ScrollableArea* scrollableArea)
{
    return adoptPtr(new ProgrammaticScrollAnimator(scrollableArea));
}

ProgrammaticScrollAnimator::ProgrammaticScrollAnimator(ScrollableArea* scrollableArea)
    : m_scrollableArea(scrollableArea)
    , m_startTime(0.0)
    , m_runState(RunState::Idle)
    , m_compositorAnimationId(0)
    , m_compositorAnimationGroupId(0)
{
}

ProgrammaticScrollAnimator::~ProgrammaticScrollAnimator()
{
}

void ProgrammaticScrollAnimator::resetAnimationState()
{
    m_animationCurve.clear();
    m_startTime = 0.0;
    m_runState = RunState::Idle;
    m_compositorAnimationId = 0;
    m_compositorAnimationGroupId = 0;
}

void ProgrammaticScrollAnimator::notifyPositionChanged(const DoublePoint& offset)
{
    m_scrollableArea->scrollPositionChanged(offset, ProgrammaticScroll);
}

void ProgrammaticScrollAnimator::scrollToOffsetWithoutAnimation(const FloatPoint& offset)
{
    cancelAnimation();
    notifyPositionChanged(offset);
}

void ProgrammaticScrollAnimator::animateToOffset(FloatPoint offset)
{
    m_startTime = 0.0;
    m_targetOffset = offset;
    m_animationCurve = adoptPtr(Platform::current()->compositorSupport()->createScrollOffsetAnimationCurve(m_targetOffset, WebCompositorAnimationCurve::TimingFunctionTypeEaseInOut));

    m_animationCurve->setInitialValue(FloatPoint(m_scrollableArea->scrollPosition()));
    m_scrollableArea->registerForAnimation();
    if (!m_scrollableArea->scheduleAnimation()) {
        resetAnimationState();
        notifyPositionChanged(IntPoint(offset.x(), offset.y()));
>>>>>>> miniblink49
    }
    m_runState = RunState::WaitingToSendToCompositor;
}

void ProgrammaticScrollAnimator::cancelAnimation()
{
<<<<<<< HEAD
    ASSERT(m_runState != RunState::RunningOnCompositorButNeedsUpdate);
    ScrollAnimatorCompositorCoordinator::cancelAnimation();
=======
    switch (m_runState) {
    case RunState::Idle:
    case RunState::WaitingToCancelOnCompositor:
        break;
    case RunState::WaitingToSendToCompositor:
        if (m_compositorAnimationId) {
            // We still have a previous animation running on the compositor.
            m_runState = RunState::WaitingToCancelOnCompositor;
        } else {
            resetAnimationState();
        }
        break;
    case RunState::RunningOnMainThread:
        resetAnimationState();
        break;
    case RunState::RunningOnCompositor:
        m_runState = RunState::WaitingToCancelOnCompositor;

        // Get serviced the next time compositor updates are allowed.
        m_scrollableArea->registerForAnimation();
    }
>>>>>>> miniblink49
}

void ProgrammaticScrollAnimator::tickAnimation(double monotonicTime)
{
    if (m_runState != RunState::RunningOnMainThread)
        return;

    if (!m_startTime)
        m_startTime = monotonicTime;
    double elapsedTime = monotonicTime - m_startTime;
    bool isFinished = (elapsedTime > m_animationCurve->duration());
<<<<<<< HEAD
    ScrollOffset offset = blinkOffsetFromCompositorOffset(m_animationCurve->getValue(elapsedTime));
    notifyOffsetChanged(offset);

    if (isFinished) {
        m_runState = RunState::PostAnimationCleanup;
    } else if (!m_scrollableArea->scheduleAnimation()) {
        notifyOffsetChanged(offset);
=======
    FloatPoint offset = m_animationCurve->getValue(elapsedTime);
    notifyPositionChanged(IntPoint(offset.x(), offset.y()));

    if (isFinished) {
        resetAnimationState();
    } else if (!m_scrollableArea->scheduleAnimation()) {
        notifyPositionChanged(IntPoint(m_targetOffset.x(), m_targetOffset.y()));
>>>>>>> miniblink49
        resetAnimationState();
    }
}

<<<<<<< HEAD
void ProgrammaticScrollAnimator::updateCompositorAnimations()
{
    if (m_runState == RunState::PostAnimationCleanup) {
        // No special cleanup, simply reset animation state. We have this state
        // here because the state machine is shared with ScrollAnimator which
        // has to do some cleanup that requires the compositing state to be clean.
        return resetAnimationState();
    }

=======
bool ProgrammaticScrollAnimator::hasAnimationThatRequiresService() const
{
    switch (m_runState) {
    case RunState::Idle:
    case RunState::RunningOnCompositor:
        return false;
    case RunState::WaitingToSendToCompositor:
    case RunState::RunningOnMainThread:
    case RunState::WaitingToCancelOnCompositor:
        return true;
    }
    ASSERT_NOT_REACHED();
    return false;
}

void ProgrammaticScrollAnimator::updateCompositorAnimations()
{
>>>>>>> miniblink49
    if (m_compositorAnimationId && m_runState != RunState::RunningOnCompositor) {
        // If the current run state is WaitingToSendToCompositor but we have a
        // non-zero compositor animation id, there's a currently running
        // compositor animation that needs to be removed here before the new
        // animation is added below.
        ASSERT(m_runState == RunState::WaitingToCancelOnCompositor || m_runState == RunState::WaitingToSendToCompositor);
<<<<<<< HEAD

        removeAnimation();

=======
        if (GraphicsLayer* layer = m_scrollableArea->layerForScrolling())
            layer->removeAnimation(m_compositorAnimationId);
>>>>>>> miniblink49
        m_compositorAnimationId = 0;
        m_compositorAnimationGroupId = 0;
        if (m_runState == RunState::WaitingToCancelOnCompositor) {
            resetAnimationState();
            return;
        }
    }

    if (m_runState == RunState::WaitingToSendToCompositor) {
<<<<<<< HEAD
        if (!m_compositorAnimationAttachedToElementId)
            reattachCompositorPlayerIfNeeded(
                getScrollableArea()->compositorAnimationTimeline());

        bool sentToCompositor = false;

        if (!m_scrollableArea->shouldScrollOnMainThread()) {
            std::unique_ptr<CompositorAnimation> animation = CompositorAnimation::create(
                *m_animationCurve, CompositorTargetProperty::SCROLL_OFFSET, 0, 0);

            int animationId = animation->id();
            int animationGroupId = animation->group();

            if (addAnimation(std::move(animation))) {
                sentToCompositor = true;
                m_runState = RunState::RunningOnCompositor;
                m_compositorAnimationId = animationId;
                m_compositorAnimationGroupId = animationGroupId;
=======
        bool sentToCompositor = false;

        if (GraphicsLayer* layer = m_scrollableArea->layerForScrolling()) {
            if (!layer->platformLayer()->shouldScrollOnMainThread()) {
                OwnPtr<WebCompositorAnimation> animation = adoptPtr(Platform::current()->compositorSupport()->createAnimation(*m_animationCurve, WebCompositorAnimation::TargetPropertyScrollOffset));

                int animationId = animation->id();
                int animationGroupId = animation->group();
                if (m_scrollableArea->layerForScrolling()->addAnimation(animation.release())) {
                    sentToCompositor = true;
                    m_runState = RunState::RunningOnCompositor;
                    m_compositorAnimationId = animationId;
                    m_compositorAnimationGroupId = animationGroupId;
                }
>>>>>>> miniblink49
            }
        }

        if (!sentToCompositor) {
            m_runState = RunState::RunningOnMainThread;
<<<<<<< HEAD
            m_animationCurve->setInitialValue(
                compositorOffsetFromBlinkOffset(m_scrollableArea->getScrollOffset()));
            if (!m_scrollableArea->scheduleAnimation()) {
                notifyOffsetChanged(m_targetOffset);
=======
            if (!m_scrollableArea->scheduleAnimation()) {
                notifyPositionChanged(IntPoint(m_targetOffset.x(), m_targetOffset.y()));
>>>>>>> miniblink49
                resetAnimationState();
            }
        }
    }
}

<<<<<<< HEAD
void ProgrammaticScrollAnimator::layerForCompositedScrollingDidChange(
    CompositorAnimationTimeline* timeline)
{
    reattachCompositorPlayerIfNeeded(timeline);

=======
void ProgrammaticScrollAnimator::layerForCompositedScrollingDidChange()
{
>>>>>>> miniblink49
    // If the composited scrolling layer is lost during a composited animation,
    // continue the animation on the main thread.
    if (m_runState == RunState::RunningOnCompositor && !m_scrollableArea->layerForScrolling()) {
        m_runState = RunState::RunningOnMainThread;
        m_compositorAnimationId = 0;
        m_compositorAnimationGroupId = 0;
<<<<<<< HEAD
        m_animationCurve->setInitialValue(
            compositorOffsetFromBlinkOffset(m_scrollableArea->getScrollOffset()));
        m_scrollableArea->registerForAnimation();
        if (!m_scrollableArea->scheduleAnimation()) {
            resetAnimationState();
            notifyOffsetChanged(m_targetOffset);
=======
        m_animationCurve->setInitialValue(FloatPoint(m_scrollableArea->scrollPosition()));
        m_scrollableArea->registerForAnimation();
        if (!m_scrollableArea->scheduleAnimation()) {
            resetAnimationState();
            notifyPositionChanged(IntPoint(m_targetOffset.x(), m_targetOffset.y()));
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
void ProgrammaticScrollAnimator::notifyCompositorAnimationFinished(
    int groupId)
{
    ASSERT(m_runState != RunState::RunningOnCompositorButNeedsUpdate);
    ScrollAnimatorCompositorCoordinator::compositorAnimationFinished(groupId);
}

DEFINE_TRACE(ProgrammaticScrollAnimator)
{
    visitor->trace(m_scrollableArea);
    ScrollAnimatorCompositorCoordinator::trace(visitor);
=======
void ProgrammaticScrollAnimator::notifyCompositorAnimationFinished(int groupId)
{
    if (m_compositorAnimationGroupId != groupId)
        return;

    m_compositorAnimationId = 0;
    m_compositorAnimationGroupId = 0;

    switch (m_runState) {
    case RunState::Idle:
    case RunState::RunningOnMainThread:
        ASSERT_NOT_REACHED();
        break;
    case RunState::WaitingToSendToCompositor:
        break;
    case RunState::RunningOnCompositor:
    case RunState::WaitingToCancelOnCompositor:
        resetAnimationState();
    }
>>>>>>> miniblink49
}

} // namespace blink
