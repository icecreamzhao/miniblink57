
#include "WebThreadImpl.h"
#include "config.h"

#include "content/web_impl_win/BlinkPlatformImpl.h"
#include <process.h>
#include <windows.h>

#include "content/web_impl_win/WebSchedulerImpl.h"
#include "content/web_impl_win/WebTimerBase.h"
#include "third_party/WebKit/Source/wtf/CurrentTime.h"
#include "third_party/WebKit/Source/wtf/ThreadingPrimitives.h"
#include "third_party/WebKit/platform/scheduler/child/web_task_runner_impl.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"

namespace content {

// 100ms is about a perceptable delay in UI, so use a half of that as a threshold.
// This is to prevent UI freeze when there are too many timers or machine performance is low.
static const double maxDurationOfFiringTimers = 0.050;

WebThreadImpl::WebThreadImpl(const char* name)
    : m_hEvent(NULL)
    , m_threadId(::GetCurrentThreadId())
    , m_webSchedulerImpl(new WebSchedulerImpl(this))
    , m_webTaskRunnerImpl(new WebTaskRunnerImpl(this))
    , m_name(name)
{
    m_name = name;
}

WebThreadImpl::~WebThreadImpl()
{
    delete m_webSchedulerImpl;
    delete m_webTaskRunnerImpl;
}

WebTaskRunner* WebThreadImpl::getWebTaskRunner()
{
    return m_webTaskRunnerImpl;
}

bool WebThreadImpl::isCurrentThread() const
{
    return ::GetCurrentThreadId() == m_threadId;
}

PlatformThreadId WebThreadImpl::threadId() const
{
    return m_threadId;
}

void WebThreadImpl::addTaskObserver(TaskObserver*)
{
    DebugBreak();
}

void WebThreadImpl::removeTaskObserver(TaskObserver*)
{
    DebugBreak();
}

void WebThreadImpl::addTaskTimeObserver(scheduler::TaskTimeObserver*)
{
    DebugBreak();
}
void WebThreadImpl::removeTaskTimeObserver(scheduler::TaskTimeObserver*)
{
    DebugBreak();
}

WebScheduler* WebThreadImpl::scheduler() const
{
    return m_webTaskRunnerImpl;
}

} // namespace content