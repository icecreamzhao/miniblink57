
#include "config.h"
#include "base/compiler_specific.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include "third_party/WebKit/public/platform/WebScheduler.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"
#include "third_party/WebKit/public/web/WebView.h"
#include "third_party/WebKit/Source/platform/WebTaskRunner.h"
#include "third_party/WebKit/Source/wtf/CurrentTime.h"
#include "content/web_impl_win/WebSchedulerImpl.h"
#include "content/web_impl_win/WebViewSchedulerImpl.h"
#include "content/web_impl_win/WebThreadImpl.h"
#include "content/web_impl_win/WebTaskRunnerImpl.h"

namespace content {

class IdleTaskToTask : public blink::WebThread::Task {
public:
    IdleTaskToTask(blink::WebThread::IdleTask* task) { m_task = task; }

    virtual ~IdleTaskToTask() override { delete m_task; }

    virtual void run() override { m_task->run(0); }
private:
    blink::WebThread::IdleTask* m_task;
};

WebSchedulerImpl::WebSchedulerImpl(WebThreadImpl* thread)
    : m_thread(thread)
    , m_taskRunner(nullptr)
{
}

WebSchedulerImpl::~WebSchedulerImpl() { }

void WebSchedulerImpl::shutdown() 
{
}

bool WebSchedulerImpl::shouldYieldForHighPriorityWork()
{
    return false; 
}

bool WebSchedulerImpl::canExceedIdleDeadlineIfRequired() { return true; }

void WebSchedulerImpl::postIdleTask(const blink::WebTraceLocation& location, blink::WebThread::IdleTask* task)
{
    m_thread->postDelayedTask(location, (new IdleTaskToTask(task)), 0);
}

void WebSchedulerImpl::postNonNestableIdleTask(const blink::WebTraceLocation& location, blink::WebThread::IdleTask* task)
{
    m_thread->postDelayedTask(location, (new IdleTaskToTask(task)), 0);
}

void WebSchedulerImpl::postIdleTaskAfterWakeup(const blink::WebTraceLocation& location, blink::WebThread::IdleTask* task)
{ 
    m_thread->postDelayedTask(location, (new IdleTaskToTask(task)), 0);
}

void WebSchedulerImpl::postLoadingTask(const blink::WebTraceLocation& location, blink::WebThread::Task* task) 
{
    //m_thread->postDelayedTaskWithPriorityCrossThread(location, task, 0, WebThreadImpl::kDefaultPriority);
    m_thread->postDelayedTask(location, task, 0);
}

void WebSchedulerImpl::postTimerTask(const blink::WebTraceLocation& location, blink::WebThread::Task* task, long long delayMs)
{
    m_thread->postDelayedTask(location, task, delayMs);
}

void WebSchedulerImpl::postTimerTaskAt(const blink::WebTraceLocation&, blink::WebThread::Task*, double monotonicTime) { notImplemented(); }

void WebSchedulerImpl::suspendTimerQueue() 
{
    m_thread->suspendTimerQueue();
}

void WebSchedulerImpl::resumeTimerQueue() 
{
    m_thread->resumeTimerQueue();
}

void WebSchedulerImpl::cancelTimerTask(blink::WebThread::Task* task)
{
    m_thread->cancelTimerTask(task);
}

void WebSchedulerImpl::postIdleTask(const blink::WebTraceLocation&, PassOwnPtr<IdleTask>) { notImplemented(); }
void WebSchedulerImpl::postNonNestableIdleTask(const blink::WebTraceLocation&, PassOwnPtr<IdleTask>) { notImplemented(); }
void WebSchedulerImpl::postIdleTaskAfterWakeup(const blink::WebTraceLocation&, PassOwnPtr<IdleTask>) { notImplemented(); }
void WebSchedulerImpl::postLoadingTask(const blink::WebTraceLocation&, PassOwnPtr<Task>) { notImplemented(); }

// class WebTaskRunnerImpl : public blink::WebTaskRunner {
// public:
//     WebTaskRunnerImpl(WebSchedulerImpl* scheduler)
//     {
//         m_scheduler = scheduler;
//     }
// 
//     class WebTaskRunnerImplTask : public blink::WebThread::Task {
//     public:
//         WebTaskRunnerImplTask(const base::Closure& callback)
//         {
//             m_callback = callback;
//         }
// 
//         void run() override
//         {
//             m_callback.Run();
//         }
//     private:
//         base::Closure m_callback;
//     };
// 
//     void postDelayedTask(const blink::WebTraceLocation& from, const base::Closure& callback, double delayMs) override
//     {
//         m_scheduler->postTimerTask(from, new WebTaskRunnerImplTask(callback), delayMs);
//     }
// 
//     // Returns true if the current thread is a thread on which a task may be run.
//     // Can be called from any thread.
//     bool runsTasksOnCurrentThread() override
//     {
//         DebugBreak();
//         return false;
//     }
// 
//     double virtualTimeSeconds() const override
//     {
//         return monotonicallyIncreasingVirtualTimeSeconds();
//     }
// 
//     double monotonicallyIncreasingVirtualTimeSeconds() const override
//     {
//         return WTF::monotonicallyIncreasingTimeMS();
//     }
// 
//     base::SingleThreadTaskRunner* toSingleThreadTaskRunner() override
//     {
//         DebugBreak();
//         return nullptr;
//     }
// private:
//     WebSchedulerImpl* m_scheduler;
// };

blink::WebTaskRunner* WebSchedulerImpl::loadingTaskRunner()
{
    if (!m_taskRunner)
        m_taskRunner = new WebTaskRunnerImpl(m_thread);
    return m_taskRunner;
}

blink::WebTaskRunner* WebSchedulerImpl::timerTaskRunner()
{
    if (!m_taskRunner)
        m_taskRunner = new WebTaskRunnerImpl(m_thread);
    return m_taskRunner;
}

std::unique_ptr<blink::WebViewScheduler> WebSchedulerImpl::createWebViewScheduler(blink::WebScheduler::InterventionReporter* webview, blink::WebViewScheduler::WebViewSchedulerSettings*)
{
    WebViewSchedulerImpl* webViewSchedulerImpl = new WebViewSchedulerImpl((blink::WebView*)webview, true);
    return std::unique_ptr<blink::WebViewScheduler>(webViewSchedulerImpl);
}

void WebSchedulerImpl::addPendingNavigation(blink::WebScheduler::NavigatingFrameType)
{
    
}

void WebSchedulerImpl::removePendingNavigation(blink::WebScheduler::NavigatingFrameType)
{
    
}

} // content