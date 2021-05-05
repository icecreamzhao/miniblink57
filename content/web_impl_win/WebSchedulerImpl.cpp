
#include "base/compiler_specific.h"
#include "config.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include "third_party/WebKit/public/platform/WebScheduler.h"
#include "third_party/WebKit/public/platform/WebTaskRunner.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"

#include "content/web_impl_win/WebSchedulerImpl.h"
#include "content/web_impl_win/WebThreadImpl.h"
#include "content/web_impl_win/WebViewSchedulerImpl.h"

namespace content {

WebSchedulerImpl::WebSchedulerImpl(WebThreadImpl* threadImpl)
    : m_thread(threadImpl)
{
}

WebSchedulerImpl::~WebSchedulerImpl() { }

void WebSchedulerImpl::shutdown() { notImplemented(); }

bool WebSchedulerImpl::shouldYieldForHighPriorityWork()
{
    return false;
}

bool WebSchedulerImpl::canExceedIdleDeadlineIfRequired()
{
    return false;
}

class IdleToRunnerTask : public blink::WebTaskRunner::Task {
public:
    IdleToRunnerTask(blink::WebThread::IdleTask* task)
        : m_task(task)
    {
    }

    virtual ~IdleToRunnerTask() override
    {
        delete m_task;
    }

    virtual void run() override
    {
        m_task->run(1.0);
    }

private:
    blink::WebThread::IdleTask* m_task;
};

void WebSchedulerImpl::postIdleTask(const blink::WebTraceLocation& location, blink::WebThread::IdleTask* task)
{
    m_thread->getWebTaskRunner()->postTask(location, new IdleToRunnerTask(task));
}

void WebSchedulerImpl::postNonNestableIdleTask(const blink::WebTraceLocation& location, blink::WebThread::IdleTask* task)
{
    m_thread->getWebTaskRunner()->postTask(location, new IdleToRunnerTask(task));
}

void WebSchedulerImpl::postIdleTaskAfterWakeup(const blink::WebTraceLocation& location, blink::WebThread::IdleTask* task)
{
    m_thread->getWebTaskRunner()->postTask(location, new IdleToRunnerTask(task));
}

//void WebSchedulerImpl::postLoadingTask(const blink::WebTraceLocation& location, blink::WebThread::Task* task) { m_thread->postDelayedTask(location, task, 0); }

// void WebSchedulerImpl::postTimerTask(const blink::WebTraceLocation& location, blink::WebThread::Task* task, long long delayMs)
// {
//     m_thread->postDelayedTask(location, task, delayMs);
// }

//void WebSchedulerImpl::postTimerTaskAt(const blink::WebTraceLocation&, blink::WebThread::Task*, double monotonicTime) { notImplemented(); }

void WebSchedulerImpl::suspendTimerQueue() { notImplemented(); }

void WebSchedulerImpl::resumeTimerQueue() { notImplemented(); }

void WebSchedulerImpl::postIdleTask(const blink::WebTraceLocation&, std::unique_ptr<IdleTask>) { notImplemented(); }
void WebSchedulerImpl::postNonNestableIdleTask(const blink::WebTraceLocation&, std::unique_ptr<IdleTask>) { notImplemented(); }
void WebSchedulerImpl::postIdleTaskAfterWakeup(const blink::WebTraceLocation&, std::unique_ptr<IdleTask>) { notImplemented(); }
//void WebSchedulerImpl::postLoadingTask(const blink::WebTraceLocation&, PassOwnPtr<Task>) { notImplemented(); }

blink::WebTaskRunner* WebSchedulerImpl::loadingTaskRunner()
{
    return m_thread->getWebTaskRunner();
}

blink::WebTaskRunner* WebSchedulerImpl::timerTaskRunner()
{
    return m_thread->getWebTaskRunner();
}

std::unique_ptr<blink::WebViewScheduler> WebSchedulerImpl::createWebViewScheduler(blink::WebView* webView)
{
    std::unique_ptr<blink::WebViewScheduler> viewScheduler(new WebViewSchedulerImpl(webView, true));
    return viewScheduler;
}

void WebSchedulerImpl::addPendingNavigation(blink::WebScheduler::NavigatingFrameType)
{
}

void WebSchedulerImpl::removePendingNavigation(blink::WebScheduler::NavigatingFrameType)
{
}

void WebSchedulerImpl::onNavigationStarted()
{
}

} // content