
#include "content/web_impl_win/WebTaskRunnerImpl.h"
#include "content/web_impl_win/WebThreadImpl.h"

#include "third_party/WebKit/Source/wtf/CurrentTime.h"

namespace content {

WebTaskRunnerImpl::WebTaskRunnerImpl(WebThreadImpl* threadImpl)
    : m_thread(threadImpl)
{
}

WebTaskRunnerImpl::~WebTaskRunnerImpl()
{
}

void WebTaskRunnerImpl::postDelayedTask(const blink::WebTraceLocation& location, const base::Closure& task, double delayMs)
{
}

bool WebTaskRunnerImpl::runsTasksOnCurrentThread()
{
    return m_thread->isCurrentThread();
}

double WebTaskRunnerImpl::virtualTimeSeconds() const
{
    return WTF::monotonicallyIncreasingTime();
}

double WebTaskRunnerImpl::monotonicallyIncreasingVirtualTimeSeconds() const
{
    return WTF::monotonicallyIncreasingTime();
}

base::SingleThreadTaskRunner* WebTaskRunnerImpl::toSingleThreadTaskRunner()
{
    DebugBreak();
    return nullptr;
}

double WebTaskRunnerImpl::virtualTimeSeconds() const
{
    return WTF::monotonicallyIncreasingTime();
}

double WebTaskRunnerImpl::monotonicallyIncreasingVirtualTimeSeconds() const
{
    return WTF::monotonicallyIncreasingTime();
}

}