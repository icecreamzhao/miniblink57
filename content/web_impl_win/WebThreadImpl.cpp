
#include "config.h"

#include "content/web_impl_win/WebThreadImpl.h"
#include "content/web_impl_win/BlinkPlatformImpl.h"
#include "content/web_impl_win/WebTimerBase.h"
#include "content/web_impl_win/WebSchedulerImpl.h"
#include "content/web_impl_win/ActivatingTimerCheck.h"
#include "content/browser/SharedTimerWin.h"
#include "content/TaskObserverAdapter.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"
#include "third_party/WebKit/public/platform/scheduler/base/task_time_observer.h"
#include "third_party/WebKit/Source/wtf/ThreadingPrimitives.h"
#include "third_party/WebKit/Source/wtf/CurrentTime.h"
#include "base/synchronization/waitable_event.h"

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
#include "wke/wkeUtil.h"
#endif

#ifndef NO_USE_ORIG_CHROME
#include "content/OrigChromeMgr.h"
#endif

#include "base/compiler_specific.h"
//#include "base/thread.h"

#include <windows.h>
#include <process.h>
#include <mmsystem.h>

namespace content {

// 100ms is about a perceptable delay in UI, so use a half of that as a threshold.
// This is to prevent UI freeze when there are too many timers or machine performance is low.
static const double kMaxDurationOfFiringTimers = 0.100;

unsigned WebThreadImpl::m_currentHeapInsertionOrder = 0;

DWORD __stdcall WebThreadImpl::WebThreadImplThreadEntryPoint(void* param)
{
    WebThreadImpl* impl = (WebThreadImpl*)param;
    impl->threadEntryPoint();
    return 0;
}

unsigned WebThreadImpl::getNewCurrentHeapInsertionOrder()
{
    return atomicIncrement((volatile int *)&m_currentHeapInsertionOrder);
}

#ifndef NDEBUG
ActivatingTimerCheck* gActivatingTimerCheck = nullptr;
#endif

WebThreadImpl::WebThreadImpl(const char* name)
    : m_hEvent(NULL)
    , m_threadId(-1)
    , m_firingTimers(0)
    , m_webSchedulerImpl(new WebSchedulerImpl(this))
    , m_isObserversDirty(false)
    , m_name(name)
    , m_suspendTimerQueue(false)
    , m_hadThreadInit(false)
    , m_willExit(false)
    , m_threadClosed(false)
    , m_threadHandle(nullptr)
    , m_currentFrameCreateTime(0)
{
    m_name = name;
    ::InitializeCriticalSection(&m_taskPairsMutex);
    ::InitializeCriticalSection(&m_observersMutex);
    
    m_isMainThread = (0 == strcmp("MainThread", name));
    if (m_isMainThread) {
#ifdef _DEBUG
        if (!gActivatingTimerCheck)
            gActivatingTimerCheck = new ActivatingTimerCheck();
#endif
        m_hadThreadInit = true;
        m_threadId = WTF::currentThread();
        updateSharedTimer();
        return;
    }

    //m_hEvent = ::CreateEventW(NULL, FALSE, FALSE, NULL);
    m_hEvent = new base::WaitableEvent(base::WaitableEvent::ResetPolicy::AUTOMATIC, base::WaitableEvent::InitialState::NOT_SIGNALED);

    DWORD threadIdentifier = 0;
    m_threadHandle = ::CreateThread(0, 0, WebThreadImplThreadEntryPoint, this, 0, &threadIdentifier);
 
    while (!m_hadThreadInit) {
        Sleep(1);
    };
}

WebThreadImpl::~WebThreadImpl()
{
    shutdown();

    if (m_threadHandle) {
        ::WaitForSingleObject(m_threadHandle, INFINITE);
        ::CloseHandle(m_threadHandle);
        m_threadHandle = nullptr;
    }

    delete m_webSchedulerImpl;
    
    ::DeleteCriticalSection(&m_taskPairsMutex);
    ::DeleteCriticalSection(&m_observersMutex);
    
    BlinkPlatformImpl* platform = (BlinkPlatformImpl*)blink::Platform::current();
    platform->onThreadExit(this);
}

void WebThreadImpl::shutdown()
{
    if (m_isMainThread)
        stopSharedTimer();
    willExit();
    waitForExit();
}

void WebThreadImpl::waitForExit()
{
    if (m_threadId == WTF::currentThread())
        return;

    while (!m_threadClosed) {
        Sleep(20);
    }
}

void WebThreadImpl::willExit()
{
    m_willExit = true;
    if (m_hEvent) {
        //::SetEvent(m_hEvent);
        m_hEvent->Signal();
    }

    if (m_threadId == WTF::currentThread())
        fireOnExit();
}

void WebThreadImpl::threadEntryPoint()
{
    //base::SetThreadName(m_name);

    printf("WebThreadImpl::threadEntryPoint begin: %s\n", m_name);

    m_threadId = WTF::currentThread();
    BlinkPlatformImpl::onCurrentThreadWhenWebThreadImplCreated(this);
    m_hadThreadInit = true;

    while (!m_willExit) {
        //DWORD dReturn = ::WaitForSingleObject(m_hEvent, INFINITE);
        m_hEvent->Wait();

        startTriggerTasks();

        while (!m_timerHeap.empty()) {
            schedulerTasks();
            ::Sleep(1);
        }
    }

    printf("WebThreadImpl::threadEntryPoint exit: %s\n", m_name);

    //::CloseHandle(m_hEvent);
    delete m_hEvent;
    m_hEvent = nullptr;

    fireOnExit();
    m_threadClosed = true;
}

void WebThreadImpl::postTask(const blink::WebTraceLocation& location, blink::WebThread::Task* task)
{
#ifndef NO_USE_ORIG_CHROME
    if (OrigChromeMgr::getInst() && m_isMainThread)
        return OrigChromeMgr::postWebTask(location, task);
#endif
    postDelayedTask(location, task, 0);
}

void WebThreadImpl::postDelayedTaskImpl(
    const blink::WebTraceLocation& location, blink::WebThread::Task* task, 
    long long delayMs, double* createTimeOnOtherThread, int priority, unsigned* heapInsertionOrder)
{
    // delete by self
    WebTimerBase* timer = WebTimerBase::create(this, location, task, priority);
    timer->startFromOtherThread((double)delayMs / 1000.0, createTimeOnOtherThread, heapInsertionOrder);
}

void WebThreadImpl::postDelayedTaskWithPriorityCrossThread(
    const blink::WebTraceLocation& location, 
    blink::WebThread::Task* task,
    long long delayMs,
    int priority)
{
    if (!task) // io�߳��˳���ʱ�򣬿���Ϊnull
        return;

#ifndef NO_USE_ORIG_CHROME
    RELEASE_ASSERT(!OrigChromeMgr::getInst() || !m_isMainThread);
#endif

    if (m_willExit) {
        if (m_hEvent) {
            //::SetEvent(m_hEvent);
            m_hEvent->Signal();
        }
        delete task;
        return;
    }

    if (isCurrentThread()) {
        postDelayedTaskImpl(location, task, delayMs, &m_currentFrameCreateTime, priority, nullptr);
        return;
    }

    ::EnterCriticalSection(&m_taskPairsMutex);
    m_taskPairsToPost.push_back(new TaskPair(location, task, delayMs, priority));

    if (m_taskPairsToPost.size() > 500)
        OutputDebugStringA("WebThreadImpl::postDelayedTaskWithPriorityCrossThread too much\n");

    if (m_hEvent) {
        //::SetEvent(m_hEvent);
        m_hEvent->Signal();
    }
    ::LeaveCriticalSection(&m_taskPairsMutex);
}

void WebThreadImpl::postDelayedTask(const blink::WebTraceLocation& location, blink::WebThread::Task* task, long long delayMs)
{
#ifndef NO_USE_ORIG_CHROME
    if (OrigChromeMgr::getInst() && m_isMainThread)
        return OrigChromeMgr::postWebDelayedTask(location, task, delayMs);
#endif
    postDelayedTaskWithPriorityCrossThread(location, task, delayMs, kLoadingPriority);
}

WebThreadImpl::TaskPair::TaskPair(const blink::WebTraceLocation& location, blink::WebThread::Task* task, long long delayMs, int priority)
{
    this->location = location;
    this->task = task;
    this->delayMs = delayMs;
    this->priority = priority;
    this->createTime = WTF::currentTime();
    this->heapInsertionOrder = WebThreadImpl::getNewCurrentHeapInsertionOrder();
}

void WebThreadImpl::TaskPair::sortByPriority(std::vector<WebThreadImpl::TaskPair*>* tasks)
{
    for (size_t i = 0; i < tasks->size(); ++i) {
        for (size_t j = i + 1; j < tasks->size(); ++j) {
            int a = tasks->at(i)->priority;
            int b = tasks->at(j)->priority;
            if (!(a < b))
                continue;

            WebThreadImpl::TaskPair* ptr = tasks->at(i);
            *(&tasks->at(i)) = tasks->at(j);
            *(&tasks->at(j)) = ptr;
        }
    }
}

void WebThreadImpl::startTriggerTasks()
{
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::freeV8TempObejctOnOneFrameBefore();
#endif
    m_currentFrameCreateTime = WTF::currentTime();
    
    while (true) {
        ::EnterCriticalSection(&m_taskPairsMutex);
        if (0 == m_taskPairsToPost.size()) {
            LeaveCriticalSection(&m_taskPairsMutex);
            break;
        }
        
        std::vector<TaskPair*> taskPairsToPostCopy = m_taskPairsToPost;
        m_taskPairsToPost.clear();
        ::LeaveCriticalSection(&m_taskPairsMutex);

        for (size_t i = 0; i < taskPairsToPostCopy.size(); ++i) {
            TaskPair* taskPair = taskPairsToPostCopy[i];
            postDelayedTaskImpl(taskPair->location, taskPair->task, taskPair->delayMs, &taskPair->createTime, taskPair->priority, &taskPair->heapInsertionOrder);

            delete taskPair;
        }
    } 
}

bool WebThreadImpl::isCurrentThread() const 
{
    return threadId() == WTF::currentThread();
}

blink::PlatformThreadId WebThreadImpl::threadId() const
{
    return m_threadId;
}

std::vector<TaskObserverAdapter*>::iterator WebThreadImpl::findObserver(std::vector<TaskObserverAdapter*>& observers, void* observer)
{
    for (std::vector<TaskObserverAdapter*>::iterator it = observers.begin(); it != observers.end(); ++it) {
        if ((*it)->m_taskObs == observer)
            return it;
        if ((*it)->m_taskTimeObs == observer)
            return it;
    }

    return observers.end();
}

class EmptyTask : public blink::WebThread::Task {
public:
    virtual ~EmptyTask() override {}
    virtual void run() override {};
};

void WebThreadImpl::addTaskObserverImpl(TaskObserverAdapter* observer)
{
#ifndef NO_USE_ORIG_CHROME
    if (OrigChromeMgr::getInst() && m_isMainThread)
        return OrigChromeMgr::addTaskObserver(observer);
#endif

    ::EnterCriticalSection(&m_observersMutex);
    if (m_observers.end() != findObserver(m_observers, observer)) {
        if (m_hEvent) {
            //::SetEvent(m_hEvent);
            m_hEvent->Signal();
        }
        ::LeaveCriticalSection(&m_observersMutex);
        return;
    }

    m_observers.push_back(observer);
    ::LeaveCriticalSection(&m_observersMutex);

    double fireTime = currentTime();
    if (!m_timerHeap.empty() && (m_timerHeap[0]->m_nextFireTime <= fireTime)) {
        if (m_hEvent) {
            //::SetEvent(m_hEvent);
            m_hEvent->Signal();
        }
    } else
        postTask(FROM_HERE, new EmptyTask());

    m_isObserversDirty = true;
}

void WebThreadImpl::removeTaskObserverImpl(const TaskObserverAdapter& observer)
{
#ifndef NO_USE_ORIG_CHROME
    if (OrigChromeMgr::getInst() && m_isMainThread)
        return OrigChromeMgr::removeTaskObserver(observer);
#endif

    ::EnterCriticalSection(&m_observersMutex);
    for (size_t i = 0; i < m_observers.size(); ++i) {
        if (m_observers[i]->isEqual(observer)) {
            delete m_observers[i];
            m_observers[i] = nullptr;
        }
    }
    ::LeaveCriticalSection(&m_observersMutex);
    m_isObserversDirty = true;
}

void WebThreadImpl::addTaskObserver(blink::WebThread::TaskObserver* observer)
{
    addTaskObserverImpl(new TaskObserverAdapter(observer));
}

void WebThreadImpl::removeTaskObserver(blink::WebThread::TaskObserver* observer)
{
    TaskObserverAdapter adapter(observer);
    removeTaskObserverImpl(adapter);
}

void WebThreadImpl::addTaskTimeObserver(blink::scheduler::TaskTimeObserver* observer)
{
    addTaskObserverImpl(new TaskObserverAdapter(observer));
}

void WebThreadImpl::removeTaskTimeObserver(blink::scheduler::TaskTimeObserver* observer)
{
    TaskObserverAdapter adapter(observer);
    removeTaskObserverImpl(adapter);
}

void WebThreadImpl::willProcessTasks()
{
    // ��Щ�ص�������Microtask::enqueueMicrotask�������˳���ʱ��append��������Ҫ�����ִ�У�����һЩImageLoadû���ͷ�
    for (size_t i = 0; ; ++i) {
        ::EnterCriticalSection(&m_observersMutex);
        if (i >= m_observers.size()) {
            ::LeaveCriticalSection(&m_observersMutex);
            break;
        }
        TaskObserverAdapter* observer = m_observers[i];
        ::LeaveCriticalSection(&m_observersMutex);
        base::PendingTask pendingTask(FROM_HERE, base::Bind([] {}));
        if (observer)
            observer->WillProcessTask(pendingTask);
    }
    clearEmptyObservers();
}

void WebThreadImpl::didProcessTasks()
{
    for (size_t i = 0; ; ++i) {
        ::EnterCriticalSection(&m_observersMutex);
        if (i >= m_observers.size()) {
            ::LeaveCriticalSection(&m_observersMutex);
            break;
        }
        TaskObserverAdapter* observer = m_observers[i];
        ::LeaveCriticalSection(&m_observersMutex);

        base::PendingTask pendingTask(FROM_HERE, base::Bind([] {}));
        if (observer)
            observer->DidProcessTask(pendingTask);
    }
    clearEmptyObservers();
}

void WebThreadImpl::clearEmptyObservers()
{
    if (!m_isObserversDirty)
        return;
    m_isObserversDirty = false;

    ::EnterCriticalSection(&m_observersMutex);
    std::vector<TaskObserverAdapter*>::iterator it = m_observers.begin();
    for (; it != m_observers.end();) {
        if (nullptr == *it)
            it = m_observers.erase(it);
        else
            ++it;

        if (it == m_observers.end())
            break;
    }
    ::LeaveCriticalSection(&m_observersMutex);
}

blink::WebScheduler* WebThreadImpl::scheduler() const
{
    return m_webSchedulerImpl;
}

blink::WebTaskRunner* WebThreadImpl::getWebTaskRunner()
{
    return m_webSchedulerImpl->timerTaskRunner();
}

void WebThreadImpl::deleteUnusedTimers()
{
    for (size_t i = 0; i < m_unusedTimersToDelete.size(); ++i) {
        WebTimerBase* timer = m_unusedTimersToDelete[i];

#if 0
        if (1 == timer->refCount()) {
            for (size_t j = 0; j < m_timerHeap.size(); ++j) {
                WebTimerBase* timerOther = m_timerHeap[j];
                if (timerOther == timer)
                    DebugBreak();
            }
        }
#endif
        timer->deref();
    }
    m_unusedTimersToDelete.clear();
}

void WebThreadImpl::deleteTimersOnExit()
{
    for (size_t i = 0; i < m_timerHeap.size(); ++i) {
        WebTimerBase* timer = m_timerHeap[i];
        timer->deref();
    }
    m_timerHeap.clear();
}

void WebThreadImpl::deleteTaskPairsToPostOnExit()
{
    for (size_t i = 0; i < m_taskPairsToPost.size(); ++i) {
        TaskPair* taskPair = m_taskPairsToPost[i];
        delete taskPair;
    }
    m_taskPairsToPost.clear();
}

void WebThreadImpl::suspendTimerQueue()
{
    m_suspendTimerQueue = true;
}

void WebThreadImpl::resumeTimerQueue()
{
    m_suspendTimerQueue = false;
}

void WebThreadImpl::disableScheduler()
{
    ++m_firingTimers;
}

void WebThreadImpl::enableScheduler()
{
    --m_firingTimers;
}

void WebThreadImpl::fire()
{
    startTriggerTasks();
    schedulerTasks();
}

void WebThreadImpl::fireTimeOnExit()
{
    while (!m_timerHeap.empty()) {
        WebTimerBase* timer = m_timerHeap[0];
        timer->m_nextFireTime = 0;
        timer->heapDeleteMin();

        willProcessTasks();
        timer->fired(); // ���ܻ�append m_timerHeap
        didProcessTasks();
    }
}

void WebThreadImpl::fireOnExit()
{
    startTriggerTasks();
    fireTimeOnExit();
    ASSERT(0 == m_timerHeap.size() && 0 == m_taskPairsToPost.size());

    deleteUnusedTimers();
    deleteTimersOnExit();
    deleteTaskPairsToPostOnExit();
}

bool WebThreadImpl::hasImmediatelyTimer()
{
    double fireTime = currentTime();
    return !m_timerHeap.empty() && (m_timerHeap[0]->m_nextFireTime <= fireTime);
}

void WebThreadImpl::schedulerTasks()
{
    // Do a re-entrancy check.
    if (m_firingTimers > 0 /*|| m_suspendTimerQueue*/) 
        return;
    ++m_firingTimers;

    ASSERT(m_threadId == WTF::currentThread());
    
    deleteUnusedTimers();

    double fireTime = currentTime();
    double timeToQuit = fireTime + kMaxDurationOfFiringTimers;

#if 0 // def _DEBUG
    std::vector<WebTimerBase*> dumpTimerHeap = m_timerHeap;
    for (size_t i = 0; i < dumpTimerHeap.size(); ++i) {
        if (!gActivatingTimerCheck->isActivating(dumpTimerHeap[i]))
            DebugBreak();
    }
#endif

    startTriggerTasks(); // ���������䣬�������ѭ���ڱ��̲߳�ͣ��Ӷ�ʱ������startTriggerTasks��ľ�û����ִ���ˡ�

    if (m_timerHeap.size() > 500) {
        char* output = (char*)malloc(0x100);
        sprintf(output, "WebThreadImpl::scheduler Tasks is too much: %d\n", (int)m_timerHeap.size());
        OutputDebugStringA(output);
        free(output);
    }
    
    bool hasFire = false;
    while (!m_timerHeap.empty() && (m_timerHeap[0]->m_nextFireTime <= fireTime || m_willExit)) {
        hasFire = true;
        WebTimerBase* timer = m_timerHeap[0];
        timer->m_nextFireTime = 0;
        timer->heapDeleteMin();

        double interval = timer->repeatInterval();
        timer->setNextFireTime(interval ? fireTime + interval : 0, nullptr);
#if 0 // def _DEBUG
        size_t count = gActivatingTimerCheck->count();
        WebTimerBase* timerDump = timer;
        if (!gActivatingTimerCheck->isActivating(timer))
            DebugBreak();
#endif
//         std::string name = m_name;
//         if (name == "ioThread") {            
//             printf("WebThreadImpl::schedulerTasks, ioThread: m_timerHeap.size():%zu %s\n", m_timerHeap.size(), timer->getTraceLocation().function_name());
//         }

        // Once the timer has been fired, it may be deleted, so do nothing else with it after this point.
        willProcessTasks();
        timer->fired();
        didProcessTasks();

        startTriggerTasks();

        // Catch the case where the timer asked timers to fire in a nested event loop, or we are over time limit.
        if (!m_firingTimers || timeToQuit < currentTime()) // weolar
            break;
    }
    if (!hasFire) {
        willProcessTasks();
        didProcessTasks();
    }
    
    --m_firingTimers;

    updateSharedTimer();
}

void WebThreadImpl::cancelTimerTask(WebThread::Task* task)
{
    bool find = false;
    for (size_t i = 0; i < m_timerHeap.size(); ++i) {
        WebTimerBase* timer = m_timerHeap[i];
        if (timer->getTask() == task) {
            if (find)
                DebugBreak();
            timer->setNextFireTime(0, nullptr);
            find = true;
        }
    }
}

void WebThreadImpl::updateSharedTimer()
{
    if (m_isMainThread)
        setSharedTimerFireInterval(0.016);
}

std::vector<WebTimerBase*>& WebThreadImpl::timerHeap()
{
    return m_timerHeap;
}

} // namespace content