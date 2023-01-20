/*
 * Copyright (C) 2006, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2009 Google Inc. All rights reserved.
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

<<<<<<< HEAD
#include "platform/Timer.h"

#include "platform/instrumentation/tracing/TraceEvent.h"
=======
#include "config.h"
#include "platform/Timer.h"

#include "platform/TraceEvent.h"
>>>>>>> miniblink49
#include "public/platform/Platform.h"
#include "public/platform/WebScheduler.h"
#include "wtf/AddressSanitizer.h"
#include "wtf/Atomics.h"
#include "wtf/CurrentTime.h"
#include "wtf/HashSet.h"
#include <algorithm>
#include <limits.h>
#include <limits>
#include <math.h>

namespace blink {

<<<<<<< HEAD
TimerBase::TimerBase(RefPtr<WebTaskRunner> webTaskRunner)
    : m_nextFireTime(0)
    , m_repeatInterval(0)
    , m_webTaskRunner(std::move(webTaskRunner))
    ,
#if DCHECK_IS_ON()
    m_thread(currentThread())
    ,
#endif
    m_weakPtrFactory(this)
{
    ASSERT(m_webTaskRunner);
=======
TimerBase::TimerBase()
    : m_nextFireTime(0)
    , m_unalignedNextFireTime(0)
    , m_repeatInterval(0)
    , m_cancellableTimerTask(nullptr)
    , m_webScheduler(Platform::current()->currentThread()->scheduler())
#if ENABLE(ASSERT)
    , m_thread(currentThread())
#endif
{
>>>>>>> miniblink49
}

TimerBase::~TimerBase()
{
    stop();
}

<<<<<<< HEAD
void TimerBase::start(double nextFireInterval,
    double repeatInterval,
    const WebTraceLocation& caller)
{
#if DCHECK_IS_ON()
    DCHECK_EQ(m_thread, currentThread());
#endif

    m_location = caller;
    m_repeatInterval = repeatInterval;
    setNextFireTime(timerMonotonicallyIncreasingTime(), nextFireInterval);
=======
void TimerBase::start(double nextFireInterval, double repeatInterval, const WebTraceLocation& caller)
{
    ASSERT(m_thread == currentThread());

    m_location = caller;
    m_repeatInterval = repeatInterval;
    setNextFireTime(monotonicallyIncreasingTime(), nextFireInterval);
>>>>>>> miniblink49
}

void TimerBase::stop()
{
<<<<<<< HEAD
#if DCHECK_IS_ON()
    DCHECK_EQ(m_thread, currentThread());
#endif

    m_repeatInterval = 0;
    m_nextFireTime = 0;
    m_weakPtrFactory.revokeAll();
=======
    ASSERT(m_thread == currentThread());

    m_repeatInterval = 0;
    m_nextFireTime = 0;
    if (m_cancellableTimerTask)
        m_cancellableTimerTask->cancel();
    m_cancellableTimerTask = nullptr;
>>>>>>> miniblink49
}

double TimerBase::nextFireInterval() const
{
    ASSERT(isActive());
<<<<<<< HEAD
    double current = timerMonotonicallyIncreasingTime();
=======
    double current = monotonicallyIncreasingTime();
>>>>>>> miniblink49
    if (m_nextFireTime < current)
        return 0;
    return m_nextFireTime - current;
}

<<<<<<< HEAD
void TimerBase::moveToNewTaskRunner(RefPtr<WebTaskRunner> taskRunner)
{
#if DCHECK_IS_ON()
    DCHECK_EQ(m_thread, currentThread());
    DCHECK(taskRunner->runsTasksOnCurrentThread());
#endif
    // If the underlying task runner stays the same, ignore it.
    if (m_webTaskRunner->toSingleThreadTaskRunner() == taskRunner->toSingleThreadTaskRunner()) {
        return;
    }

    bool active = isActive();
    m_weakPtrFactory.revokeAll();
    m_webTaskRunner = std::move(taskRunner);

    if (!active)
        return;

    double now = timerMonotonicallyIncreasingTime();
    double nextFireTime = std::max(m_nextFireTime, now);
    m_nextFireTime = 0;

    setNextFireTime(now, nextFireTime - now);
}

// static
RefPtr<WebTaskRunner> TimerBase::getTimerTaskRunner()
{
    return Platform::current()->currentThread()->scheduler()->timerTaskRunner();
}

// static
RefPtr<WebTaskRunner> TimerBase::getUnthrottledTaskRunner()
{
    return Platform::current()->currentThread()->getWebTaskRunner();
}

RefPtr<WebTaskRunner> TimerBase::timerTaskRunner() const
{
    return m_webTaskRunner;
}

void TimerBase::setNextFireTime(double now, double delay)
{
#if DCHECK_IS_ON()
    DCHECK_EQ(m_thread, currentThread());
#endif

    double newTime = now + delay;

    if (m_nextFireTime != newTime) {
        m_nextFireTime = newTime;

        // Cancel any previously posted task.
        m_weakPtrFactory.revokeAll();

        double delayMs = 1000.0 * (newTime - now);
        timerTaskRunner()->postDelayedTask(
            m_location,
            base::Bind(&TimerBase::runInternal, m_weakPtrFactory.createWeakPtr()),
            delayMs);
    }
}

NO_SANITIZE_ADDRESS
=======
void TimerBase::setNextFireTime(double now, double delay)
{
    ASSERT(m_thread == currentThread());

    m_unalignedNextFireTime = now + delay;

    double newTime = alignedFireTime(m_unalignedNextFireTime);
    if (m_nextFireTime != newTime) {
        m_nextFireTime = newTime;
        if (m_cancellableTimerTask)
            m_cancellableTimerTask->cancel();
        m_cancellableTimerTask = new CancellableTimerTask(this);
        if (newTime != m_unalignedNextFireTime) {
            // If the timer is being aligned, use postTimerTaskAt() to schedule it
            // so that the relative order of aligned timers is preserved.
            // TODO(skyostil): Move timer alignment into the scheduler.
            m_webScheduler->postTimerTaskAt(m_location, m_cancellableTimerTask, m_nextFireTime);
        } else {
            // Round the delay up to the nearest millisecond to be consistant with the
            // previous behavior of BlinkPlatformImpl::setSharedTimerFireInterval.
            long long delayMs = static_cast<long long>(ceil((newTime - now) * 1000.0));
            if (delayMs < 0)
                delayMs = 0;
            m_webScheduler->postTimerTask(m_location, m_cancellableTimerTask, delayMs);
        }
    }
}

NO_LAZY_SWEEP_SANITIZE_ADDRESS
>>>>>>> miniblink49
void TimerBase::runInternal()
{
    if (!canFire())
        return;

<<<<<<< HEAD
    m_weakPtrFactory.revokeAll();

    TRACE_EVENT0("blink", "TimerBase::run");
#if DCHECK_IS_ON()
    DCHECK_EQ(m_thread, currentThread())
        << "Timer posted by " << m_location.function_name() << " "
        << m_location.file_name() << " was run on a different thread";
#endif

    if (m_repeatInterval) {
        double now = timerMonotonicallyIncreasingTime();
        // This computation should be drift free, and it will cope if we miss a
        // beat, which can easily happen if the thread is busy.  It will also cope
        // if we get called slightly before m_unalignedNextFireTime, which can
        // happen due to lack of timer precision.
        double intervalToNextFireTime = m_repeatInterval - fmod(now - m_nextFireTime, m_repeatInterval);
        setNextFireTime(timerMonotonicallyIncreasingTime(), intervalToNextFireTime);
    } else {
        m_nextFireTime = 0;
    }
    fired();
}

bool TimerBase::Comparator::operator()(const TimerBase* a,
    const TimerBase* b) const
{
    return a->m_nextFireTime < b->m_nextFireTime;
}

// static
double TimerBase::timerMonotonicallyIncreasingTime() const
{
    return timerTaskRunner()->monotonicallyIncreasingVirtualTimeSeconds();
=======
    TRACE_EVENT0("blink", "TimerBase::run");
    ASSERT_WITH_MESSAGE(m_thread == currentThread(), "Timer posted by %s %s was run on a different thread", m_location.functionName(), m_location.fileName());
    TRACE_EVENT_SET_SAMPLING_STATE("blink", "BlinkInternal");

    m_nextFireTime = 0;
    // Note: repeating timers drift, but this is preserving the functionality of the old timer heap.
    // See crbug.com/328700.
    if (m_repeatInterval)
        setNextFireTime(monotonicallyIncreasingTime(), m_repeatInterval);
    fired();
    TRACE_EVENT_SET_SAMPLING_STATE("blink", "Sleeping");
}

void TimerBase::didChangeAlignmentInterval(double now)
{
    setNextFireTime(now, m_unalignedNextFireTime - now);
}

double TimerBase::nextUnalignedFireInterval() const
{
    ASSERT(isActive());
    return std::max(m_unalignedNextFireTime - monotonicallyIncreasingTime(), 0.0);
}

bool TimerBase::Comparator::operator()(const TimerBase* a, const TimerBase* b) const
{
    return a->m_unalignedNextFireTime < b->m_unalignedNextFireTime;
>>>>>>> miniblink49
}

} // namespace blink
