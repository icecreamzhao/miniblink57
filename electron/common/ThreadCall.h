
#ifndef common_ThreadCall_h
#define common_ThreadCall_h

#include "node/uv/include/uv.h"
#include "v8.h"
#include "mbvip/core/mb.h"
#include <functional>
#include <list>

namespace atom {

class ThreadCall {
private:
    typedef void (*CoreMainTask)(void* data);
    struct TaskAsyncData {
        CoreMainTask call;
        void* data;
        void* dataEx;
        BOOL event;
        void* ret;
        DWORD fromThreadId;
        DWORD toThreadId;
        DWORD destroyThreadId;
    };

public:
    static void init(uv_loop_t* loop);
    static void initTaskQueue();

    static void createBlinkThread(v8::Platform* v8platform); // Blink�߳�Ҫ�ȴ��������ܵ���init
    static void callBlinkThreadAsync(std::function<void(void)>&& closure);
    static void callBlinkThreadSync(std::function<void(void)>&& closure);
    static void callUiThreadSync(std::function<void(void)>&& closure);
    static void callUiThreadAsync(std::function<void(void)>&& closure);

    static void postNodeCoreThreadTask(std::function<void(void)>&& closure);

    static void shutdown();

    static void exitMessageLoop(DWORD threadId);
    static void exitReEnterMessageLoop(DWORD threadId); // ��ק��Ϣʱ��������������Ϣѭ��
    static void messageLoop(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate);

    static uv_loop_t* getUiLoop() { return m_uiLoop; }
    static uv_loop_t* getBlinkLoop() { return m_blinkLoop; }

    static DWORD getUiThreadId() { return m_uiThreadId; }
    static DWORD getBlinkThreadId() { return m_blinkThreadId; }

    static bool isBlinkThread();
    static bool isUiThread();

    static void setMainThread();

    static v8::Platform* getBlinkThreadV8Platform() { return m_v8platformOfBlink; }

    static void runUiThread(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate);
    static void runMainThread();
private:
    static void MB_CALL_TYPE onBlinkThreadInited(void* param1, void* param2);

    static void MB_CALL_TYPE OnBlinkThreadIdle(ThreadCall* self, v8::Isolate* isolate);
    static void MB_CALL_TYPE OnUiThreadIdle(ThreadCall* self, v8::Isolate* isolate);

    /// <summary>
//     static void callSyncAndWait(TaskAsyncData* asyncData);
//     static void callThreadAsync(std::function<void(void)> closure);
//     static void threadCallbackWrap(void* data);
//     static void asynThreadCallbackWrap(void* data);

    static DWORD m_blinkThreadId;
    static DWORD m_uiThreadId;
    static DWORD m_mainThreadId;

    static uv_loop_t* m_uiLoop;
    static uv_loop_t* m_blinkLoop;

    static void callbackInOtherThread(TaskAsyncData* asyncData);
    static void callAsync(TaskAsyncData* asyncData, CoreMainTask call, void* data);
    static void* waitForCallThreadAsync(TaskAsyncData* asyncData);
    static TaskAsyncData* cretaeAsyncData(uv_loop_t* loop, DWORD toThreadId, void* dataEx, DWORD destroyThreadId);
    static void postThreadMessage(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam);

    static void blinkThread(void* created);

    static v8::Platform* m_v8platformOfBlink;
    static v8::Platform* m_v8platformOfUi;

    struct TaskItem {
        TaskItem(DWORD idThread, UINT msg, WPARAM wParam, LPARAM lParam)
        {
            this->idThread = idThread;
            this->msg = msg;
            this->wParam = wParam;
            this->lParam = lParam;
        }
        DWORD idThread;
        UINT msg;
        WPARAM wParam;
        LPARAM lParam;
    };
    enum TaskQueueType {
        kBlinkTaskQueue = 0,
        kUiTaskQueue,
        kMainTaskQueue,

        kMaxTaskQueue,
    };

    static TaskQueueType getWhichTypeByThreadId(DWORD idThread);
    static bool doTaskQueue(DWORD threadId);
    static bool runTaskQueue(UINT msg, WPARAM wParam, LPARAM lParam);
    static std::list<TaskItem*>* m_taskQueue[kMaxTaskQueue];
    static CRITICAL_SECTION m_taskQueueMutex;
};

} // atom

#endif // common_ThreadCall_h