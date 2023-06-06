
#include "content/web_impl_win/WebTaskRunnerImpl.h"
#include "content/web_impl_win/WebThreadImpl.h"

#include "third_party/WebKit/Source/wtf/CurrentTime.h"

#include "base/location.h"
#include "base/callback.h"
#include "base/memory/ref_counted.h"
#include "base/threading/platform_thread.h"

namespace content {

class RunnerTaskWrap : public blink::WebThread::Task {
public:
    explicit RunnerTaskWrap(const base::Closure& task)
        : m_task(task)
    {
    }

    void run() override
    {
        m_task.Run();
    }

private:
    base::Closure m_task;
};

class SingleThreadTaskRunnerImpl : public base::SingleThreadTaskRunner {
public:
    explicit SingleThreadTaskRunnerImpl(WebThreadImpl* thread)
    {
        m_thread = thread;
        m_validThreadId = base::kInvalidThreadId;
        BindToCurrentThread();
    }

    void SingleThreadTaskRunnerImpl::BindToCurrentThread()
    {
        base::AutoLock lock(m_validThreadIdLock);
        DCHECK_EQ(base::kInvalidThreadId, m_validThreadId);
        m_validThreadId = base::PlatformThread::CurrentId();
    }

    // SingleThreadTaskRunner implementation
    bool PostDelayedTask(const tracked_objects::Location& from_here, const base::Closure& task, base::TimeDelta delay) override
    {
        m_thread->postDelayedTask(from_here, new RunnerTaskWrap(task), delay.ToInternalValue() / 1000);
        return true;
    }

    bool PostNonNestableDelayedTask(const tracked_objects::Location& from_here, const base::Closure& task, base::TimeDelta delay) override
    {
        m_thread->postDelayedTask(from_here, new RunnerTaskWrap(task), delay.ToInternalValue() / 1000);
        return true;
    }

    bool RunsTasksOnCurrentThread() const override
    {
        base::AutoLock lock(m_validThreadIdLock);
        return m_validThreadId == base::PlatformThread::CurrentId();
    }

    friend class base::RefCountedThreadSafe<SingleThreadTaskRunnerImpl>;
    ~SingleThreadTaskRunnerImpl() override
    {

    }

private:
    WebThreadImpl* m_thread;

    // ID of the thread |this| was created on.  Could be accessed on multiple
    // threads, protected by |m_validThreadIdLock|.
    base::PlatformThreadId m_validThreadId;
    mutable base::Lock m_validThreadIdLock;

    DISALLOW_COPY_AND_ASSIGN(SingleThreadTaskRunnerImpl);
};

WebTaskRunnerImpl::WebTaskRunnerImpl(WebThreadImpl* threadImpl)
    : m_thread(threadImpl)
    , m_taskRunner(new SingleThreadTaskRunnerImpl(threadImpl))
{
    m_taskRunner->AddRef();
}

WebTaskRunnerImpl::~WebTaskRunnerImpl()
{
    m_taskRunner->Release();
}

void WebTaskRunnerImpl::postDelayedTask(const blink::WebTraceLocation& location, const base::Closure& task, double delayMs)
{
    m_thread->postDelayedTask(location, new RunnerTaskWrap(task), (long long)delayMs);
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
    return m_taskRunner;
}

}