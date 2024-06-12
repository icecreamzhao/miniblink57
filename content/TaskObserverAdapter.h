
#ifndef content_TaskObserverAdapter_h
#define content_TaskObserverAdapter_h

#include "base/message_loop/message_loop.h"
#include "third_party/WebKit/public/platform/scheduler/base/task_time_observer.h"
#include "third_party/WebKit/public/platform/WebThread.h"

namespace content {

class TaskObserverAdapter : public base::MessageLoop::TaskObserver {
public:
    TaskObserverAdapter(blink::WebThread::TaskObserver* observer)
        : m_taskObs(observer)
    {
    }

    TaskObserverAdapter(blink::scheduler::TaskTimeObserver* observer)
        : m_taskTimeObs(observer)
    {

    }

    void* getTask() const
    {
        if (m_taskObs) {
            return m_taskObs;
        }
        return m_taskTimeObs;
    }

    bool isEqual(const TaskObserverAdapter& other) const
    {
        if (m_taskObs == other.m_taskObs)
            return true;
        if (m_taskTimeObs == other.m_taskTimeObs)
            return true;
        return false;
    }

    void WillProcessTask(const base::PendingTask& pending_task) override
    {
        if (m_taskObs) {
            m_taskObs->willProcessTask();
        } else {
            m_taskTimeObs->willProcessTask(nullptr, 0);
        }
    }

    void DidProcessTask(const base::PendingTask& pending_task) override
    {
        if (m_taskObs) {
            m_taskObs->didProcessTask();
        } else {
            m_taskTimeObs->didProcessTask(nullptr, 0, 0);
        }
    }

    blink::WebThread::TaskObserver* m_taskObs = nullptr;
    blink::scheduler::TaskTimeObserver* m_taskTimeObs = nullptr;
    //blink::WebThread::TaskObserver* m_observer;
};

}

#endif // content_TaskObserverAdapter_h