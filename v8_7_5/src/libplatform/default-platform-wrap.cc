
#include "default-platform-wrap.h"
#include "src/libplatform/default-platform.h"

namespace gin {

DefaultPlatformWrap::DefaultPlatformWrap()
{
    m_defaultPlatform = new v8::platform::DefaultPlatform();
}

std::shared_ptr<v8::TaskRunner> DefaultPlatformWrap::GetForegroundTaskRunner(v8::Isolate* isolate)
{
    return m_defaultPlatform->GetForegroundTaskRunner(isolate);
}

void DefaultPlatformWrap::CallOnWorkerThread(std::unique_ptr<v8::Task> task)
{
    m_defaultPlatform->CallOnWorkerThread(std::move(task));
}

int DefaultPlatformWrap::NumberOfWorkerThreads()
{
    return m_defaultPlatform->NumberOfWorkerThreads();
}

void DefaultPlatformWrap::CallDelayedOnWorkerThread(std::unique_ptr<v8::Task> task, double delay_in_seconds)
{
    return m_defaultPlatform->CallDelayedOnWorkerThread(std::move(task), delay_in_seconds);
}

double DefaultPlatformWrap::CurrentClockTimeMillis()
{
    return m_defaultPlatform->CurrentClockTimeMillis();
}

}
