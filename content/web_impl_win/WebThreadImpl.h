#ifndef WebThreadImpl_h
#define WebThreadImpl_h

#include <vector>

#include "base/compiler_specific.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include "third_party/WebKit/public/platform/WebThread.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"

namespace blink {

class Task;

} // blink

namespace WTF {
class Mutex;
} // WTF

namespace base {
class WaitableEvent;
}

namespace content {

class WebSchedulerImpl;
class WebTimerBase;

class WebThreadImpl : public blink::WebThread {
public:
    explicit WebThreadImpl(const char* name);
    virtual ~WebThreadImpl();
    
    static const int kDefaultPriority = 100;
    static const int kLoadingPriority = 200;

    virtual void postTask(const blink::WebTraceLocation&, blink::WebThread::Task*) override;
    virtual void postDelayedTask(const blink::WebTraceLocation&, blink::WebThread::Task*, long long delayMs) override;
    void postDelayedTaskWithPriorityCrossThread(const blink::WebTraceLocation& location,
        blink::WebThread::Task* task,
        long long delayMs,
        int priority);

    virtual bool isCurrentThread() const override;
    virtual blink::PlatformThreadId threadId() const override;

    virtual void addTaskObserver(TaskObserver*) override;
    virtual void removeTaskObserver(TaskObserver*) override;

    // Returns the scheduler associated with the thread.
    virtual blink::WebScheduler* scheduler() const override;
    virtual blink::WebTaskRunner* getWebTaskRunner() override;

    void willExit();

    void startTriggerTasks();
    void schedulerTasks();
    bool hasImmediatelyTimer();

    void fire();
    
    void suspendTimerQueue();
    void resumeTimerQueue();

    void cancelTimerTask(WebThread::Task* task);

    void disableScheduler();
    void enableScheduler();

    std::vector<WebTimerBase*>& timerHeap();
    void updateSharedTimer();
    void appendUnusedTimerToDelete(WebTimerBase* timer) { m_unusedTimersToDelete.push_back(timer); }

    bool threadClosed() { return m_threadClosed; }

    void shutdown();

    static unsigned getNewCurrentHeapInsertionOrder();

private:
    void fireOnExit();
    void waitForExit();
    void fireTimeOnExit();

    struct TaskPair {
        TaskPair(const blink::WebTraceLocation& location, blink::WebThread::Task* task, long long delayMs, int priority);
        static void sortByPriority(std::vector<TaskPair*>*);

        blink::WebTraceLocation location;
        blink::WebThread::Task* task;
        long long delayMs;
        int priority;
        double createTime;
        unsigned heapInsertionOrder;
    };
    void postDelayedTaskImpl(
        const blink::WebTraceLocation& location, blink::WebThread::Task* task, long long delayMs, double* createTimeOnOtherThread, int priority, unsigned* heapInsertionOrder);
    
    static DWORD __stdcall WebThreadImplThreadEntryPoint(void* param);
    void threadEntryPoint();
    void deleteUnusedTimers();
    void deleteTimersOnExit();
    void deleteTaskPairsToPostOnExit();

    void willProcessTasks();
    void didProcessTasks();
    void clearEmptyObservers();

    base::WaitableEvent* m_hEvent;
    blink::PlatformThreadId m_threadId;
    bool m_willExit;
    bool m_threadClosed;

    int m_firingTimers; // Reentrancy guard.
    WebSchedulerImpl* m_webSchedulerImpl;

    // ������wtf�ĺ����������˳���wtf���ر��ˣ��Ͳ��ܷ�����
    std::vector<WebTimerBase*> m_timerHeap;
    std::vector<WebTimerBase*> m_unusedTimersToDelete;
    std::vector<TaskPair*> m_taskPairsToPost;
    std::vector<TaskObserver*> m_observers;
    bool m_isObserversDirty;
    const char* m_name;

    CRITICAL_SECTION m_taskPairsMutex;
    CRITICAL_SECTION m_observersMutex;
    bool m_suspendTimerQueue;

    bool m_hadThreadInit;
    HANDLE m_threadHandle;

    double m_currentFrameCreateTime; // ��ǰ֡ȫ��ʹ���������ʱ��
    static unsigned m_currentHeapInsertionOrder;

    bool m_isMainThread;
};

} // namespace content

#endif // WebThreadImpl_h