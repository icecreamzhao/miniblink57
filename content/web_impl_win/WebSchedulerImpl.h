
#include "base/compiler_specific.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include "third_party/WebKit/public/platform/WebScheduler.h"

namespace content {

class WebThreadImpl;

class BLINK_PLATFORM_EXPORT WebSchedulerImpl : public blink::WebScheduler {
public:
    WebSchedulerImpl(WebThreadImpl*);
    virtual ~WebSchedulerImpl();

    // Called to prevent any more pending tasks from running. Must be called on
    // the associated WebThread.
    virtual void shutdown() override;

    // Returns true if there is high priority work pending on the associated WebThread
    // and the caller should yield to let the scheduler service that work.
    // Must be called on the associated WebThread.
    virtual bool shouldYieldForHighPriorityWork() override;

    // Returns true if a currently running idle task could exceed its deadline
    // without impacting user experience too much. This should only be used if
    // there is a task which cannot be pre-empted and is likely to take longer
    // than the largest expected idle task deadline. It should NOT be polled to
    // check whether more work can be performed on the current idle task after
    // its deadline has expired - post a new idle task for the continuation of
    // the work in this case.
    // Must be called from the associated WebThread.
    virtual bool canExceedIdleDeadlineIfRequired() override;

    // Schedule an idle task to run the associated WebThread. For non-critical
    // tasks which may be reordered relative to other task types and may be
    // starved for an arbitrarily long time if no idle time is available.
    // Takes ownership of |IdleTask|. Can be called from any thread.
    virtual void postIdleTask(const blink::WebTraceLocation&, blink::WebThread::IdleTask*) override;

    // Like postIdleTask but guarantees that the posted task will not run
    // nested within an already-running task. Posting an idle task as
    // non-nestable may not affect when the task gets run, or it could
    // make it run later than it normally would, but it won't make it
    // run earlier than it normally would.
    virtual void postNonNestableIdleTask(const blink::WebTraceLocation&, blink::WebThread::IdleTask*) override;

    // Like postIdleTask but does not run the idle task until after some other
    // task has run. This enables posting of a task which won't stop the Blink
    // main thread from sleeping, but will start running after it wakes up.
    // Takes ownership of |IdleTask|. Can be called from any thread.
    virtual void postIdleTaskAfterWakeup(const blink::WebTraceLocation&, blink::WebThread::IdleTask*) override;

    // Returns a WebTaskRunner for loading tasks. Can be called from any thread.
    virtual blink::WebTaskRunner* loadingTaskRunner() override;

    // Returns a WebTaskRunner for timer tasks. Can be called from any thread.
    virtual blink::WebTaskRunner* timerTaskRunner() override;

    // Suspends the timer queue and increments the timer queue suspension count.
    // May only be called from the main thread.
    virtual void suspendTimerQueue() override;

    // Decrements the timer queue suspension count and re-enables the timer queue
    // if the suspension count is zero and the current scheduler policy allows it.
    virtual void resumeTimerQueue() override;

    virtual std::unique_ptr<blink::WebViewScheduler> createWebViewScheduler(blink::WebView*) override;

    virtual void addPendingNavigation(NavigatingFrameType) override;

    // Tells the scheduler that a navigation task is no longer pending.
    virtual void removePendingNavigation(NavigatingFrameType) override;

    // Tells the scheduler that an expected navigation was started.
    virtual void onNavigationStarted() override;

#ifdef INSIDE_BLINK
    // Helpers for posting bound functions as tasks.
    typedef Function<void(double deadlineSeconds)> IdleTask;
    typedef Function<void()> Task;

    void postIdleTask(const blink::WebTraceLocation&, std::unique_ptr<IdleTask>);
    void postNonNestableIdleTask(const blink::WebTraceLocation&, std::unique_ptr<IdleTask>);
    void postIdleTaskAfterWakeup(const blink::WebTraceLocation&, std::unique_ptr<IdleTask>);
    void postLoadingTask(const blink::WebTraceLocation&, std::unique_ptr<Task>);
#endif

private:
    WebThreadImpl* m_thread;
};

} // content