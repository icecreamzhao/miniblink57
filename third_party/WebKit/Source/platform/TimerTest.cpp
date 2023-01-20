// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/Timer.h"

#include "platform/scheduler/base/task_queue_impl.h"
#include "platform/scheduler/child/web_task_runner_impl.h"
#include "platform/scheduler/renderer/renderer_scheduler_impl.h"
#include "platform/testing/TestingPlatformSupport.h"
#include "public/platform/Platform.h"
#include "public/platform/WebScheduler.h"
#include "public/platform/WebThread.h"
#include "public/platform/WebViewScheduler.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "wtf/CurrentTime.h"
#include "wtf/PtrUtil.h"
#include "wtf/RefCounted.h"
#include <memory>
=======
#include "config.h"
#include "platform/Timer.h"

#include "public/platform/Platform.h"
#include "public/platform/WebScheduler.h"
#include "public/platform/WebThread.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
>>>>>>> miniblink49
#include <queue>

using testing::ElementsAre;

namespace blink {
namespace {
<<<<<<< HEAD

    class TimerTest : public testing::Test {
    public:
        void SetUp() override
        {
            m_runTimes.clear();
            m_platform->advanceClockSeconds(10.0);
            m_startTime = monotonicallyIncreasingTime();
        }

        void countingTask(TimerBase*)
        {
            m_runTimes.push_back(monotonicallyIncreasingTime());
        }

        void recordNextFireTimeTask(TimerBase* timer)
        {
            m_nextFireTimes.push_back(monotonicallyIncreasingTime() + timer->nextFireInterval());
        }

        void runUntilDeadline(double deadline)
        {
            double period = deadline - monotonicallyIncreasingTime();
            EXPECT_GE(period, 0.0);
            m_platform->runForPeriodSeconds(period);
        }

        // Returns false if there are no pending delayed tasks, otherwise sets |time|
        // to the delay in seconds till the next pending delayed task is scheduled to
        // fire.
        bool timeTillNextDelayedTask(double* time) const
        {
            base::TimeTicks nextRunTime;
            if (!m_platform->rendererScheduler()
                     ->TimerTaskRunner()
                     ->GetTimeDomain()
                     ->NextScheduledRunTime(&nextRunTime))
                return false;
            *time = (nextRunTime - m_platform->rendererScheduler()->TimerTaskRunner()->GetTimeDomain()->Now())
                        .InSecondsF();
            return true;
        }

    protected:
        double m_startTime;
        WTF::Vector<double> m_runTimes;
        WTF::Vector<double> m_nextFireTimes;
        ScopedTestingPlatformSupport<TestingPlatformSupportWithMockScheduler>
            m_platform;
    };

    class OnHeapTimerOwner final
        : public GarbageCollectedFinalized<OnHeapTimerOwner> {
    public:
        class Record final : public RefCounted<Record> {
        public:
            static PassRefPtr<Record> create() { return adoptRef(new Record); }

            bool timerHasFired() const { return m_timerHasFired; }
            bool isDisposed() const { return m_isDisposed; }
            bool ownerIsDestructed() const { return m_ownerIsDestructed; }
            void setTimerHasFired() { m_timerHasFired = true; }
            void dispose() { m_isDisposed = true; }
            void setOwnerIsDestructed() { m_ownerIsDestructed = true; }

        private:
            Record() = default;

            bool m_timerHasFired = false;
            bool m_isDisposed = false;
            bool m_ownerIsDestructed = false;
        };

        explicit OnHeapTimerOwner(PassRefPtr<Record> record)
            : m_timer(this, &OnHeapTimerOwner::fired)
            , m_record(record)
        {
        }
        ~OnHeapTimerOwner() { m_record->setOwnerIsDestructed(); }

        void startOneShot(double interval, const WebTraceLocation& caller)
        {
            m_timer.startOneShot(interval, caller);
        }

        DEFINE_INLINE_TRACE() { }

    private:
        void fired(TimerBase*)
        {
            EXPECT_FALSE(m_record->isDisposed());
            m_record->setTimerHasFired();
        }

        Timer<OnHeapTimerOwner> m_timer;
        RefPtr<Record> m_record;
    };

    class GCForbiddenScope final {
    public:
        STACK_ALLOCATED();
        GCForbiddenScope() { ThreadState::current()->enterGCForbiddenScope(); }
        ~GCForbiddenScope() { ThreadState::current()->leaveGCForbiddenScope(); }
    };

    TEST_F(TimerTest, StartOneShot_Zero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);

        double runTime;
        EXPECT_FALSE(timeTillNextDelayedTask(&runTime));

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime));
    }

    TEST_F(TimerTest, StartOneShot_ZeroAndCancel)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);

        double runTime;
        EXPECT_FALSE(timeTillNextDelayedTask(&runTime));

        timer.stop();

        m_platform->runUntilIdle();
        EXPECT_FALSE(m_runTimes.size());
    }

    TEST_F(TimerTest, StartOneShot_ZeroAndCancelThenRepost)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);

        double runTime;
        EXPECT_FALSE(timeTillNextDelayedTask(&runTime));

        timer.stop();

        m_platform->runUntilIdle();
        EXPECT_FALSE(m_runTimes.size());

        timer.startOneShot(0, BLINK_FROM_HERE);

        EXPECT_FALSE(timeTillNextDelayedTask(&runTime));

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime));
    }

    TEST_F(TimerTest, StartOneShot_Zero_RepostingAfterRunning)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);

        double runTime;
        EXPECT_FALSE(timeTillNextDelayedTask(&runTime));

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime));

        timer.startOneShot(0, BLINK_FROM_HERE);

        EXPECT_FALSE(timeTillNextDelayedTask(&runTime));

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime, m_startTime));
    }

    TEST_F(TimerTest, StartOneShot_NonZero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10.0, BLINK_FROM_HERE);

        double runTime;
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(10.0, runTime);

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0));
    }

    TEST_F(TimerTest, StartOneShot_NonZeroAndCancel)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);

        double runTime;
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(10.0, runTime);

        timer.stop();
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));

        m_platform->runUntilIdle();
        EXPECT_FALSE(m_runTimes.size());
    }

    TEST_F(TimerTest, StartOneShot_NonZeroAndCancelThenRepost)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);

        double runTime;
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(10.0, runTime);

        timer.stop();
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));

        m_platform->runUntilIdle();
        EXPECT_FALSE(m_runTimes.size());

        double secondPostTime = monotonicallyIncreasingTime();
        timer.startOneShot(10, BLINK_FROM_HERE);

        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(10.0, runTime);

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(secondPostTime + 10.0));
    }

    TEST_F(TimerTest, StartOneShot_NonZero_RepostingAfterRunning)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);

        double runTime;
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(10.0, runTime);

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0));

        timer.startOneShot(20, BLINK_FROM_HERE);

        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(20.0, runTime);

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0, m_startTime + 30.0));
    }

    TEST_F(TimerTest, PostingTimerTwiceWithSameRunTimeDoesNothing)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);
        timer.startOneShot(10, BLINK_FROM_HERE);

        double runTime;
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(10.0, runTime);

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0));
    }

    TEST_F(TimerTest, PostingTimerTwiceWithNewerRunTimeCancelsOriginalTask)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);
        timer.startOneShot(0, BLINK_FROM_HERE);

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 0.0));
    }

    TEST_F(TimerTest, PostingTimerTwiceWithLaterRunTimeCancelsOriginalTask)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);
        timer.startOneShot(10, BLINK_FROM_HERE);

        m_platform->runUntilIdle();
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0));
    }

    TEST_F(TimerTest, StartRepeatingTask)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startRepeating(1.0, BLINK_FROM_HERE);

        double runTime;
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(1.0, runTime);

        runUntilDeadline(m_startTime + 5.5);
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 1.0, m_startTime + 2.0, m_startTime + 3.0, m_startTime + 4.0, m_startTime + 5.0));
    }

    TEST_F(TimerTest, StartRepeatingTask_ThenCancel)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startRepeating(1.0, BLINK_FROM_HERE);

        double runTime;
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(1.0, runTime);

        runUntilDeadline(m_startTime + 2.5);
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 1.0, m_startTime + 2.0));

        timer.stop();
        m_platform->runUntilIdle();

        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 1.0, m_startTime + 2.0));
    }

    TEST_F(TimerTest, StartRepeatingTask_ThenPostOneShot)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startRepeating(1.0, BLINK_FROM_HERE);

        double runTime;
        EXPECT_TRUE(timeTillNextDelayedTask(&runTime));
        EXPECT_FLOAT_EQ(1.0, runTime);

        runUntilDeadline(m_startTime + 2.5);
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 1.0, m_startTime + 2.0));

        timer.startOneShot(0, BLINK_FROM_HERE);
        m_platform->runUntilIdle();

        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 1.0, m_startTime + 2.0, m_startTime + 2.5));
    }

    TEST_F(TimerTest, IsActive_NeverPosted)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);

        EXPECT_FALSE(timer.isActive());
    }

    TEST_F(TimerTest, IsActive_AfterPosting_OneShotZero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);

        EXPECT_TRUE(timer.isActive());
    }

    TEST_F(TimerTest, IsActive_AfterPosting_OneShotNonZero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);

        EXPECT_TRUE(timer.isActive());
    }

    TEST_F(TimerTest, IsActive_AfterPosting_Repeating)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startRepeating(1.0, BLINK_FROM_HERE);

        EXPECT_TRUE(timer.isActive());
    }

    TEST_F(TimerTest, IsActive_AfterRunning_OneShotZero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);

        m_platform->runUntilIdle();
        EXPECT_FALSE(timer.isActive());
    }

    TEST_F(TimerTest, IsActive_AfterRunning_OneShotNonZero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);

        m_platform->runUntilIdle();
        EXPECT_FALSE(timer.isActive());
    }

    TEST_F(TimerTest, IsActive_AfterRunning_Repeating)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startRepeating(1.0, BLINK_FROM_HERE);

        runUntilDeadline(m_startTime + 10);
        EXPECT_TRUE(timer.isActive()); // It should run until cancelled.
    }

    TEST_F(TimerTest, NextFireInterval_OneShotZero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);

        EXPECT_FLOAT_EQ(0.0, timer.nextFireInterval());
    }

    TEST_F(TimerTest, NextFireInterval_OneShotNonZero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);

        EXPECT_FLOAT_EQ(10.0, timer.nextFireInterval());
    }

    TEST_F(TimerTest, NextFireInterval_OneShotNonZero_AfterAFewSeconds)
    {
        m_platform->setAutoAdvanceNowToPendingTasks(false);

        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);

        m_platform->advanceClockSeconds(2.0);
        EXPECT_FLOAT_EQ(8.0, timer.nextFireInterval());
    }

    TEST_F(TimerTest, NextFireInterval_Repeating)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startRepeating(20, BLINK_FROM_HERE);

        EXPECT_FLOAT_EQ(20.0, timer.nextFireInterval());
    }

    TEST_F(TimerTest, RepeatInterval_NeverStarted)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);

        EXPECT_FLOAT_EQ(0.0, timer.repeatInterval());
    }

    TEST_F(TimerTest, RepeatInterval_OneShotZero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);

        EXPECT_FLOAT_EQ(0.0, timer.repeatInterval());
    }

    TEST_F(TimerTest, RepeatInterval_OneShotNonZero)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startOneShot(10, BLINK_FROM_HERE);

        EXPECT_FLOAT_EQ(0.0, timer.repeatInterval());
    }

    TEST_F(TimerTest, RepeatInterval_Repeating)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startRepeating(20, BLINK_FROM_HERE);

        EXPECT_FLOAT_EQ(20.0, timer.repeatInterval());
    }

    TEST_F(TimerTest, AugmentRepeatInterval)
    {
        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startRepeating(10, BLINK_FROM_HERE);
        EXPECT_FLOAT_EQ(10.0, timer.repeatInterval());
        EXPECT_FLOAT_EQ(10.0, timer.nextFireInterval());

        m_platform->advanceClockSeconds(2.0);
        timer.augmentRepeatInterval(10);

        EXPECT_FLOAT_EQ(20.0, timer.repeatInterval());
        EXPECT_FLOAT_EQ(18.0, timer.nextFireInterval());

        // NOTE setAutoAdvanceNowToPendingTasks(true) (which uses
        // cc::OrderedSimpleTaskRunner) results in somewhat strange behavior of the
        // test clock which breaks this test.  Specifically the test clock advancing
        // logic ignores newly posted delayed tasks and advances too far.
        runUntilDeadline(m_startTime + 50.0);
        EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 20.0, m_startTime + 40.0));
    }

    TEST_F(TimerTest, AugmentRepeatInterval_TimerFireDelayed)
    {
        m_platform->setAutoAdvanceNowToPendingTasks(false);

        Timer<TimerTest> timer(this, &TimerTest::countingTask);
        timer.startRepeating(10, BLINK_FROM_HERE);
        EXPECT_FLOAT_EQ(10.0, timer.repeatInterval());
        EXPECT_FLOAT_EQ(10.0, timer.nextFireInterval());

        m_platform->advanceClockSeconds(123.0); // Make the timer long overdue.
        timer.augmentRepeatInterval(10);

        EXPECT_FLOAT_EQ(20.0, timer.repeatInterval());
        // The timer is overdue so it should be scheduled to fire immediatly.
        EXPECT_FLOAT_EQ(0.0, timer.nextFireInterval());
    }

    TEST_F(TimerTest, RepeatingTimerDoesNotDrift)
    {
        m_platform->setAutoAdvanceNowToPendingTasks(false);

        Timer<TimerTest> timer(this, &TimerTest::recordNextFireTimeTask);
        timer.startRepeating(2.0, BLINK_FROM_HERE);

        recordNextFireTimeTask(
            &timer); // Next scheduled task to run at m_startTime + 2.0

        // Simulate timer firing early. Next scheduled task to run at
        // m_startTime + 4.0
        m_platform->advanceClockSeconds(1.9);
        runUntilDeadline(monotonicallyIncreasingTime() + 0.2);

        // Next scheduled task to run at m_startTime + 6.0
        m_platform->runForPeriodSeconds(2.0);
        // Next scheduled task to run at m_startTime + 8.0
        m_platform->runForPeriodSeconds(2.1);
        // Next scheduled task to run at m_startTime + 10.0
        m_platform->runForPeriodSeconds(2.9);
        // Next scheduled task to run at m_startTime + 14.0 (skips a beat)
        m_platform->advanceClockSeconds(3.1);
        m_platform->runUntilIdle();
        // Next scheduled task to run at m_startTime + 18.0 (skips a beat)
        m_platform->advanceClockSeconds(4.0);
        m_platform->runUntilIdle();
        // Next scheduled task to run at m_startTime + 28.0 (skips 5 beats)
        m_platform->advanceClockSeconds(10.0);
        m_platform->runUntilIdle();

        EXPECT_THAT(
            m_nextFireTimes,
            ElementsAre(m_startTime + 2.0, m_startTime + 4.0, m_startTime + 6.0,
                m_startTime + 8.0, m_startTime + 10.0, m_startTime + 14.0,
                m_startTime + 18.0, m_startTime + 28.0));
    }

    template <typename TimerFiredClass>
    class TimerForTest : public TaskRunnerTimer<TimerFiredClass> {
    public:
        using TimerFiredFunction =
            typename TaskRunnerTimer<TimerFiredClass>::TimerFiredFunction;

        ~TimerForTest() override { }

        TimerForTest(RefPtr<WebTaskRunner> webTaskRunner,
            TimerFiredClass* timerFiredClass,
            TimerFiredFunction timerFiredFunction)
            : TaskRunnerTimer<TimerFiredClass>(std::move(webTaskRunner),
                timerFiredClass,
                timerFiredFunction)
        {
        }
    };

    TEST_F(TimerTest, UserSuppliedWebTaskRunner)
    {
        scoped_refptr<scheduler::TaskQueue> taskRunner(
            m_platform->rendererScheduler()->NewTimerTaskRunner(
                scheduler::TaskQueue::QueueType::TEST));
        RefPtr<scheduler::WebTaskRunnerImpl> webTaskRunner = scheduler::WebTaskRunnerImpl::create(taskRunner);
        TimerForTest<TimerTest> timer(webTaskRunner, this, &TimerTest::countingTask);
        timer.startOneShot(0, BLINK_FROM_HERE);

        // Make sure the task was posted on taskRunner.
        EXPECT_FALSE(taskRunner->IsEmpty());
    }

    TEST_F(TimerTest, RunOnHeapTimer)
    {
        RefPtr<OnHeapTimerOwner::Record> record = OnHeapTimerOwner::Record::create();
        Persistent<OnHeapTimerOwner> owner = new OnHeapTimerOwner(record);

        owner->startOneShot(0, BLINK_FROM_HERE);

        EXPECT_FALSE(record->timerHasFired());
        m_platform->runUntilIdle();
        EXPECT_TRUE(record->timerHasFired());
    }

    TEST_F(TimerTest, DestructOnHeapTimer)
    {
        RefPtr<OnHeapTimerOwner::Record> record = OnHeapTimerOwner::Record::create();
        Persistent<OnHeapTimerOwner> owner = new OnHeapTimerOwner(record);

        record->dispose();
        owner->startOneShot(0, BLINK_FROM_HERE);

        owner = nullptr;
        ThreadState::current()->collectGarbage(
            BlinkGC::NoHeapPointersOnStack, BlinkGC::GCWithSweep, BlinkGC::ForcedGC);
        EXPECT_TRUE(record->ownerIsDestructed());

        EXPECT_FALSE(record->timerHasFired());
        m_platform->runUntilIdle();
        EXPECT_FALSE(record->timerHasFired());
    }

    TEST_F(TimerTest, MarkOnHeapTimerAsUnreachable)
    {
        RefPtr<OnHeapTimerOwner::Record> record = OnHeapTimerOwner::Record::create();
        Persistent<OnHeapTimerOwner> owner = new OnHeapTimerOwner(record);

        record->dispose();
        owner->startOneShot(0, BLINK_FROM_HERE);

        owner = nullptr;
        ThreadState::current()->collectGarbage(BlinkGC::NoHeapPointersOnStack,
            BlinkGC::GCWithoutSweep,
            BlinkGC::ForcedGC);
        EXPECT_FALSE(record->ownerIsDestructed());

        {
            GCForbiddenScope scope;
            EXPECT_FALSE(record->timerHasFired());
            m_platform->runUntilIdle();
            EXPECT_FALSE(record->timerHasFired());
            EXPECT_FALSE(record->ownerIsDestructed());
        }
    }

    namespace {

        class TaskObserver : public base::MessageLoop::TaskObserver {
        public:
            TaskObserver(RefPtr<WebTaskRunner> task_runner,
                std::vector<RefPtr<WebTaskRunner>>* runOrder)
                : m_taskRunner(std::move(task_runner))
                , m_runOrder(runOrder)
            {
            }

            void WillProcessTask(const base::PendingTask&) { }

            void DidProcessTask(const base::PendingTask&)
            {
                m_runOrder->push_back(m_taskRunner);
            }

        private:
            RefPtr<WebTaskRunner> m_taskRunner;
            std::vector<RefPtr<WebTaskRunner>>* m_runOrder;
        };

    } // namespace

    TEST_F(TimerTest, MoveToNewTaskRunnerOneShot)
    {
        std::vector<RefPtr<WebTaskRunner>> runOrder;

        scoped_refptr<scheduler::TaskQueue> taskRunner1(
            m_platform->rendererScheduler()->NewTimerTaskRunner(
                scheduler::TaskQueue::QueueType::TEST));
        RefPtr<scheduler::WebTaskRunnerImpl> webTaskRunner1 = scheduler::WebTaskRunnerImpl::create(taskRunner1);
        TaskObserver taskObserver1(webTaskRunner1, &runOrder);
        taskRunner1->AddTaskObserver(&taskObserver1);

        scoped_refptr<scheduler::TaskQueue> taskRunner2(
            m_platform->rendererScheduler()->NewTimerTaskRunner(
                scheduler::TaskQueue::QueueType::TEST));
        RefPtr<scheduler::WebTaskRunnerImpl> webTaskRunner2 = scheduler::WebTaskRunnerImpl::create(taskRunner2);
        TaskObserver taskObserver2(webTaskRunner2, &runOrder);
        taskRunner2->AddTaskObserver(&taskObserver2);

        TimerForTest<TimerTest> timer(webTaskRunner1, this, &TimerTest::countingTask);

        double startTime = monotonicallyIncreasingTime();

        timer.startOneShot(1, BLINK_FROM_HERE);

        m_platform->runForPeriodSeconds(0.5);

        timer.moveToNewTaskRunner(webTaskRunner2);

        m_platform->runUntilIdle();

        EXPECT_THAT(m_runTimes, ElementsAre(startTime + 1.0));

        EXPECT_THAT(runOrder, ElementsAre(webTaskRunner2));

        EXPECT_TRUE(taskRunner1->IsEmpty());
        EXPECT_TRUE(taskRunner2->IsEmpty());
    }

    TEST_F(TimerTest, MoveToNewTaskRunnerRepeating)
    {
        std::vector<RefPtr<WebTaskRunner>> runOrder;

        scoped_refptr<scheduler::TaskQueue> taskRunner1(
            m_platform->rendererScheduler()->NewTimerTaskRunner(
                scheduler::TaskQueue::QueueType::TEST));
        RefPtr<scheduler::WebTaskRunnerImpl> webTaskRunner1 = scheduler::WebTaskRunnerImpl::create(taskRunner1);
        TaskObserver taskObserver1(webTaskRunner1, &runOrder);
        taskRunner1->AddTaskObserver(&taskObserver1);

        scoped_refptr<scheduler::TaskQueue> taskRunner2(
            m_platform->rendererScheduler()->NewTimerTaskRunner(
                scheduler::TaskQueue::QueueType::TEST));
        RefPtr<scheduler::WebTaskRunnerImpl> webTaskRunner2 = scheduler::WebTaskRunnerImpl::create(taskRunner2);
        TaskObserver taskObserver2(webTaskRunner2, &runOrder);
        taskRunner2->AddTaskObserver(&taskObserver2);

        TimerForTest<TimerTest> timer(webTaskRunner1, this, &TimerTest::countingTask);

        double startTime = monotonicallyIncreasingTime();

        timer.startRepeating(1, BLINK_FROM_HERE);

        m_platform->runForPeriodSeconds(2.5);

        timer.moveToNewTaskRunner(webTaskRunner2);

        m_platform->runForPeriodSeconds(2);

        EXPECT_THAT(m_runTimes, ElementsAre(startTime + 1.0, startTime + 2.0, startTime + 3.0, startTime + 4.0));

        EXPECT_THAT(runOrder, ElementsAre(webTaskRunner1, webTaskRunner1, webTaskRunner2, webTaskRunner2));

        EXPECT_TRUE(taskRunner1->IsEmpty());
        EXPECT_FALSE(taskRunner2->IsEmpty());
    }

    // This test checks that when inactive timer is moved to a different task
    // runner it isn't activated.
    TEST_F(TimerTest, MoveToNewTaskRunnerWithoutTasks)
    {
        scoped_refptr<scheduler::TaskQueue> taskRunner1(
            m_platform->rendererScheduler()->NewTimerTaskRunner(
                scheduler::TaskQueue::QueueType::TEST));
        RefPtr<scheduler::WebTaskRunnerImpl> webTaskRunner1 = scheduler::WebTaskRunnerImpl::create(taskRunner1);

        scoped_refptr<scheduler::TaskQueue> taskRunner2(
            m_platform->rendererScheduler()->NewTimerTaskRunner(
                scheduler::TaskQueue::QueueType::TEST));
        RefPtr<scheduler::WebTaskRunnerImpl> webTaskRunner2 = scheduler::WebTaskRunnerImpl::create(taskRunner2);

        TimerForTest<TimerTest> timer(webTaskRunner1, this, &TimerTest::countingTask);

        m_platform->runUntilIdle();
        EXPECT_TRUE(!m_runTimes.size());
        EXPECT_TRUE(taskRunner1->IsEmpty());
        EXPECT_TRUE(taskRunner2->IsEmpty());
    }

=======
double gCurrentTimeSecs = 0.0;

double currentTime()
{
    return gCurrentTimeSecs;
}

// This class exists because gcc doesn't know how to move an OwnPtr.
class RefCountedTaskContainer : public RefCounted<RefCountedTaskContainer> {
public:
    explicit RefCountedTaskContainer(WebThread::Task* task) : m_task(adoptPtr(task)) { }

    ~RefCountedTaskContainer() { }

    void run()
    {
        m_task->run();
    }

private:
    OwnPtr<WebThread::Task> m_task;
};

class DelayedTask {
public:
    DelayedTask(WebThread::Task* task, long long delayMs)
        : m_task(adoptRef(new RefCountedTaskContainer(task)))
        , m_runTimeSecs(monotonicallyIncreasingTime() + 0.001 * static_cast<double>(delayMs))
        , m_delayMs(delayMs) { }

    bool operator<(const DelayedTask& other) const
    {
        return m_runTimeSecs > other.m_runTimeSecs;
    }

    void run() const
    {
        m_task->run();
    }

    double runTimeSecs() const
    {
        return m_runTimeSecs;
    }

    long long delayMs() const
    {
        return m_delayMs;
    }

private:
    RefPtr<RefCountedTaskContainer> m_task;
    double m_runTimeSecs;
    long long m_delayMs;
};

class MockWebScheduler : public WebScheduler {
public:
    MockWebScheduler() { }
    ~MockWebScheduler() override { }

    bool shouldYieldForHighPriorityWork() override
    {
        return false;
    }

    bool canExceedIdleDeadlineIfRequired() override
    {
        return false;
    }

    void postIdleTask(const WebTraceLocation&, WebThread::IdleTask*) override
    {
    }

    void postNonNestableIdleTask(const WebTraceLocation&, WebThread::IdleTask*) override
    {
    }

    void postIdleTaskAfterWakeup(const WebTraceLocation&, WebThread::IdleTask*) override
    {
    }

    void postLoadingTask(const WebTraceLocation&, WebThread::Task*) override
    {
    }

    void postTimerTask(const WebTraceLocation&, WebThread::Task* task, long long delayMs) override
    {
        m_timerTasks.push(DelayedTask(task, delayMs));
    }

    void postTimerTaskAt(const WebTraceLocation&, WebThread::Task* task, double monotonicTime) override
    {
        m_timerTasks.push(DelayedTask(task, (monotonicTime - monotonicallyIncreasingTime()) * 1000));
    }

    void runUntilIdle()
    {
        while (!m_timerTasks.empty()) {
            gCurrentTimeSecs = m_timerTasks.top().runTimeSecs();
            m_timerTasks.top().run();
            m_timerTasks.pop();
        }
    }

    void runUntilIdleOrDeadlinePassed(double deadline)
    {
        while (!m_timerTasks.empty()) {
            if (m_timerTasks.top().runTimeSecs() > deadline) {
                gCurrentTimeSecs = deadline;
                break;
            }
            gCurrentTimeSecs = m_timerTasks.top().runTimeSecs();
            m_timerTasks.top().run();
            m_timerTasks.pop();
        }
    }

    bool hasOneTimerTask() const
    {
        return m_timerTasks.size() == 1;
    }

    long nextTimerTaskDelayMillis() const
    {
        ASSERT(hasOneTimerTask());
        return m_timerTasks.top().delayMs();
    }

private:
    std::priority_queue<DelayedTask> m_timerTasks;
};

class FakeWebThread : public WebThread {
public:
    FakeWebThread() : m_webScheduler(adoptPtr(new MockWebScheduler())) { }
    ~FakeWebThread() override { }

    // WebThread implementation:
    void postTask(const WebTraceLocation&, Task*)
    {
        ASSERT_NOT_REACHED();
    }

    virtual void postDelayedTask(const WebTraceLocation&, Task*, long long)
    {
        ASSERT_NOT_REACHED();
    }

    virtual bool isCurrentThread() const
    {
        ASSERT_NOT_REACHED();
        return true;
    }

    virtual PlatformThreadId threadId() const
    {
        ASSERT_NOT_REACHED();
        return 0;
    }

    WebScheduler* scheduler() const override
    {
        return m_webScheduler.get();
    }

    virtual void enterRunLoop()
    {
        ASSERT_NOT_REACHED();
    }

    virtual void exitRunLoop()
    {
        ASSERT_NOT_REACHED();
    }

private:
    OwnPtr<MockWebScheduler> m_webScheduler;
};

class TimerTestPlatform : public Platform {
public:
    TimerTestPlatform()
        : m_webThread(adoptPtr(new FakeWebThread())) { }
    ~TimerTestPlatform() override { }

    WebThread* currentThread() override
    {
        return m_webThread.get();
    }

    void cryptographicallyRandomValues(unsigned char*, size_t) override
    {
        ASSERT_NOT_REACHED();
    }

    const unsigned char* getTraceCategoryEnabledFlag(const char* categoryName) override
    {
        static const unsigned char enabled[] = {0};
        return enabled;
    }

    void runUntilIdle()
    {
        mockScheduler()->runUntilIdle();
    }

    void runUntilIdleOrDeadlinePassed(double deadline)
    {
        mockScheduler()->runUntilIdleOrDeadlinePassed(deadline);
    }

    bool hasOneTimerTask() const
    {
        return mockScheduler()->hasOneTimerTask();
    }

    long nextTimerTaskDelayMillis() const
    {
        return mockScheduler()->nextTimerTaskDelayMillis();
    }

private:
    MockWebScheduler* mockScheduler() const
    {
        return static_cast<MockWebScheduler*>(m_webThread->scheduler());
    }

    OwnPtr<FakeWebThread> m_webThread;
};

class TimerTest : public testing::Test {
public:
    void SetUp() override
    {
        m_platform = adoptPtr(new TimerTestPlatform());
        m_oldPlatform = Platform::current();
        Platform::initialize(m_platform.get());
        WTF::setMonotonicallyIncreasingTimeFunction(currentTime);

        m_runTimes.clear();
        gCurrentTimeSecs = 10.0;
        m_startTime = gCurrentTimeSecs;
    }

    void TearDown() override
    {
        Platform::initialize(m_oldPlatform);
    }

    void countingTask(Timer<TimerTest>*)
    {
        m_runTimes.push_back(monotonicallyIncreasingTime());
    }

    void advanceTimeBy(double timeSecs)
    {
        gCurrentTimeSecs += timeSecs;
    }

    void runUntilIdle()
    {
        m_platform->runUntilIdle();
    }

    void runUntilIdleOrDeadlinePassed(double deadline)
    {
        m_platform->runUntilIdleOrDeadlinePassed(deadline);
    }

    bool hasOneTimerTask() const
    {
        return m_platform->hasOneTimerTask();
    }

    long nextTimerTaskDelayMillis() const
    {
        return m_platform->nextTimerTaskDelayMillis();
    }

protected:
    double m_startTime;
    std::vector<double> m_runTimes;

private:
    OwnPtr<TimerTestPlatform> m_platform;
    Platform* m_oldPlatform;
};

TEST_F(TimerTest, StartOneShot_Zero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(0ll, nextTimerTaskDelayMillis());

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime));
}

TEST_F(TimerTest, StartOneShot_ZeroAndCancel)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(0ll, nextTimerTaskDelayMillis());

    timer.stop();

    runUntilIdle();
    EXPECT_TRUE(m_runTimes.empty());
}

TEST_F(TimerTest, StartOneShot_ZeroAndCancelThenRepost)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(0ll, nextTimerTaskDelayMillis());

    timer.stop();

    runUntilIdle();
    EXPECT_TRUE(m_runTimes.empty());

    timer.startOneShot(0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(0ll, nextTimerTaskDelayMillis());

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime));
}

TEST_F(TimerTest, StartOneShot_Zero_RepostingAfterRunning)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(0ll, nextTimerTaskDelayMillis());

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime));

    timer.startOneShot(0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(0ll, nextTimerTaskDelayMillis());

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime, m_startTime));
}

TEST_F(TimerTest, StartOneShot_NonZero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10.0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(10000ll, nextTimerTaskDelayMillis());

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0));
}

TEST_F(TimerTest, StartOneShot_NonZeroAndCancel)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(10000ll, nextTimerTaskDelayMillis());

    timer.stop();

    runUntilIdle();
    EXPECT_TRUE(m_runTimes.empty());
}

TEST_F(TimerTest, StartOneShot_NonZeroAndCancelThenRepost)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(10000ll, nextTimerTaskDelayMillis());

    timer.stop();

    runUntilIdle();
    EXPECT_TRUE(m_runTimes.empty());

    double secondPostTime = monotonicallyIncreasingTime();
    timer.startOneShot(10, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(10000ll, nextTimerTaskDelayMillis());

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(secondPostTime + 10.0));
}

TEST_F(TimerTest, StartOneShot_NonZero_RepostingAfterRunning)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(10000ll, nextTimerTaskDelayMillis());

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0));

    timer.startOneShot(20, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(20000ll, nextTimerTaskDelayMillis());

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0, m_startTime + 30.0));
}

TEST_F(TimerTest, PostingTimerTwiceWithSameRunTimeDoesNothing)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);
    timer.startOneShot(10, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(10000ll, nextTimerTaskDelayMillis());

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0));
}

TEST_F(TimerTest, PostingTimerTwiceWithNewerRunTimeCancelsOriginalTask)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);
    timer.startOneShot(0, FROM_HERE);

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 0.0));
}

TEST_F(TimerTest, PostingTimerTwiceWithLaterRunTimeCancelsOriginalTask)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(0, FROM_HERE);
    timer.startOneShot(10, FROM_HERE);

    runUntilIdle();
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 10.0));
}

TEST_F(TimerTest, StartRepeatingTask)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startRepeating(1.0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(1000ll, nextTimerTaskDelayMillis());

    runUntilIdleOrDeadlinePassed(m_startTime + 5.5);
    EXPECT_THAT(m_runTimes, ElementsAre(
        m_startTime + 1.0, m_startTime + 2.0, m_startTime + 3.0, m_startTime + 4.0, m_startTime + 5.0));
}

TEST_F(TimerTest, StartRepeatingTask_ThenCancel)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startRepeating(1.0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(1000ll, nextTimerTaskDelayMillis());

    runUntilIdleOrDeadlinePassed(m_startTime + 2.5);
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 1.0, m_startTime + 2.0));

    timer.stop();
    runUntilIdle();

    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 1.0, m_startTime + 2.0));
}

TEST_F(TimerTest, StartRepeatingTask_ThenPostOneShot)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startRepeating(1.0, FROM_HERE);

    ASSERT(hasOneTimerTask());
    EXPECT_EQ(1000ll, nextTimerTaskDelayMillis());

    runUntilIdleOrDeadlinePassed(m_startTime + 2.5);
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 1.0, m_startTime + 2.0));

    timer.startOneShot(0, FROM_HERE);
    runUntilIdle();

    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 1.0, m_startTime + 2.0, m_startTime + 2.5));
}

TEST_F(TimerTest, IsActive_NeverPosted)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);

    EXPECT_FALSE(timer.isActive());
}

TEST_F(TimerTest, IsActive_AfterPosting_OneShotZero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(0, FROM_HERE);

    EXPECT_TRUE(timer.isActive());
}

TEST_F(TimerTest, IsActive_AfterPosting_OneShotNonZero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);

    EXPECT_TRUE(timer.isActive());
}

TEST_F(TimerTest, IsActive_AfterPosting_Repeating)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startRepeating(1.0, FROM_HERE);

    EXPECT_TRUE(timer.isActive());
}

TEST_F(TimerTest, IsActive_AfterRunning_OneShotZero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(0, FROM_HERE);

    runUntilIdle();
    EXPECT_FALSE(timer.isActive());
}

TEST_F(TimerTest, IsActive_AfterRunning_OneShotNonZero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);

    runUntilIdle();
    EXPECT_FALSE(timer.isActive());
}

TEST_F(TimerTest, IsActive_AfterRunning_Repeating)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startRepeating(1.0, FROM_HERE);

    runUntilIdleOrDeadlinePassed(m_startTime + 10);
    EXPECT_TRUE(timer.isActive()); // It should run until cancelled.
}

TEST_F(TimerTest, NextFireInterval_OneShotZero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(0, FROM_HERE);

    EXPECT_FLOAT_EQ(0.0, timer.nextFireInterval());
}

TEST_F(TimerTest, NextFireInterval_OneShotNonZero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);

    EXPECT_FLOAT_EQ(10.0, timer.nextFireInterval());
}

TEST_F(TimerTest, NextFireInterval_OneShotNonZero_AfterAFewSeconds)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);

    advanceTimeBy(2.0);
    EXPECT_FLOAT_EQ(8.0, timer.nextFireInterval());
}

TEST_F(TimerTest, NextFireInterval_Repeating)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startRepeating(20, FROM_HERE);

    EXPECT_FLOAT_EQ(20.0, timer.nextFireInterval());
}

TEST_F(TimerTest, RepeatInterval_NeverStarted)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);

    EXPECT_FLOAT_EQ(0.0, timer.repeatInterval());
}

TEST_F(TimerTest, RepeatInterval_OneShotZero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(0, FROM_HERE);

    EXPECT_FLOAT_EQ(0.0, timer.repeatInterval());
}

TEST_F(TimerTest, RepeatInterval_OneShotNonZero)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startOneShot(10, FROM_HERE);

    EXPECT_FLOAT_EQ(0.0, timer.repeatInterval());
}

TEST_F(TimerTest, RepeatInterval_Repeating)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startRepeating(20, FROM_HERE);

    EXPECT_FLOAT_EQ(20.0, timer.repeatInterval());
}

TEST_F(TimerTest, AugmentRepeatInterval)
{
    Timer<TimerTest> timer(this, &TimerTest::countingTask);
    timer.startRepeating(10, FROM_HERE);
    EXPECT_FLOAT_EQ(10.0, timer.repeatInterval());
    EXPECT_FLOAT_EQ(10.0, timer.nextFireInterval());

    advanceTimeBy(2.0);
    timer.augmentRepeatInterval(10);

    EXPECT_FLOAT_EQ(20.0, timer.repeatInterval());
    EXPECT_FLOAT_EQ(18.0, timer.nextFireInterval());

    runUntilIdleOrDeadlinePassed(m_startTime + 50.0);
    EXPECT_THAT(m_runTimes, ElementsAre(m_startTime + 20.0, m_startTime + 40.0));
}

class MockTimerWithAlignment : public TimerBase {
public:
    MockTimerWithAlignment() : m_lastFireTime(0.0), m_alignedFireTime(0.0) { }

    void fired() override
    {
    }

    double alignedFireTime(double fireTime) const override
    {
        m_lastFireTime = fireTime;
        return m_alignedFireTime;
    }

    void setAlignedFireTime(double alignedFireTime)
    {
        m_alignedFireTime = alignedFireTime;
    }

    double lastFireTime() const
    {
        return m_lastFireTime;
    }

private:
    mutable double m_lastFireTime;
    double m_alignedFireTime;
};

TEST_F(TimerTest, TimerAlignment_OneShotZero)
{
    MockTimerWithAlignment timer;
    timer.setAlignedFireTime(m_startTime + 1.0);

    timer.start(0.0, 0.0, FROM_HERE);

    // The nextFireInterval gets overrriden.
    EXPECT_FLOAT_EQ(1.0, timer.nextFireInterval());
    EXPECT_FLOAT_EQ(0.0, timer.nextUnalignedFireInterval());
    EXPECT_FLOAT_EQ(m_startTime, timer.lastFireTime());
}

TEST_F(TimerTest, TimerAlignment_OneShotNonZero)
{
    MockTimerWithAlignment timer;
    timer.setAlignedFireTime(m_startTime + 1.0);

    timer.start(0.5, 0.0, FROM_HERE);

    // The nextFireInterval gets overrriden.
    EXPECT_FLOAT_EQ(1.0, timer.nextFireInterval());
    EXPECT_FLOAT_EQ(0.5, timer.nextUnalignedFireInterval());
    EXPECT_FLOAT_EQ(m_startTime + 0.5, timer.lastFireTime());
}

TEST_F(TimerTest, DidChangeAlignmentInterval)
{
    MockTimerWithAlignment timer;
    timer.setAlignedFireTime(m_startTime + 1.0);

    timer.start(0.0, 0.0, FROM_HERE);

    EXPECT_FLOAT_EQ(1.0, timer.nextFireInterval());
    EXPECT_FLOAT_EQ(0.0, timer.nextUnalignedFireInterval());
    EXPECT_FLOAT_EQ(m_startTime, timer.lastFireTime());

    timer.setAlignedFireTime(m_startTime);
    timer.didChangeAlignmentInterval(monotonicallyIncreasingTime());

    EXPECT_FLOAT_EQ(0.0, timer.nextFireInterval());
    EXPECT_FLOAT_EQ(0.0, timer.nextUnalignedFireInterval());
    EXPECT_FLOAT_EQ(m_startTime, timer.lastFireTime());
}


>>>>>>> miniblink49
} // namespace
} // namespace blink
