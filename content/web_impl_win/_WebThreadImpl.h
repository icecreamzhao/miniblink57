#include "base/compiler_specific.h"
#include "third_party/WebKit/Source/platform/WebTaskRunner.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include "third_party/WebKit/public/platform/WebThread.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"

namespace blink {

class WebTaskRunner;

} // blink

namespace WTF {
class Mutex;
} // WTF

namespace content {

class WebSchedulerImpl;
class WebTaskRunnerImpl;
class WebTimerBase;

class BLINK_PLATFORM_EXPORT WebThreadImpl : public blink::WebThread {
public:
    WebThreadImpl(const char* name);

    virtual WebTaskRunner* getWebTaskRunner() override;

    virtual bool isCurrentThread() const override;
    virtual PlatformThreadId threadId() const override;

    virtual void addTaskObserver(TaskObserver*) override;
    virtual void removeTaskObserver(TaskObserver*) override;

    virtual void addTaskTimeObserver(scheduler::TaskTimeObserver*) override;
    virtual void removeTaskTimeObserver(scheduler::TaskTimeObserver*) override;

    // Returns the scheduler associated with the thread.
    virtual WebScheduler* scheduler() const override;

    virtual ~WebThreadImpl() { }

private:
    WebSchedulerImpl* m_webSchedulerImpl;
    blink::scheduler::WebTaskRunnerImpl* m_webTaskRunnerImpl;
};

} // namespace content