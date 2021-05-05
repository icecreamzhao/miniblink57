#include "third_party/WebKit/Source/platform/WebTaskRunner.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include "third_party/WebKit/public/platform/WebThread.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"

namespace content {

class WebThreadImpl;

class WebTaskRunnerImpl : public blink::WebTaskRunner {
public:
    WebTaskRunnerImpl(WebThreadImpl* threadImpl);
    virtual ~WebTaskRunnerImpl();

    virtual void postDelayedTask(const blink::WebTraceLocation&, const base::Closure&, double delayMs) override;

    virtual bool runsTasksOnCurrentThread() override;

    virtual double virtualTimeSeconds() const override;

    virtual double monotonicallyIncreasingVirtualTimeSeconds() const override;

    virtual base::SingleThreadTaskRunner* toSingleThreadTaskRunner() override;

private:
    WebThreadImpl* m_thread;
    base::SingleThreadTaskRunner* m_taskRunner;
};

}