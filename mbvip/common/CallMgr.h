
#include "wke/wkedefine.h"
#include <windows.h>
#include <functional>

namespace MtRender {

class CallMgr {
private:

#define WM_THREAD_CALL (WM_USER + 0x5325)
#define WM_IME_STARTCOMPOSITION_ASYN (WM_USER + 0x5326)
#define WM_SETCURSOR_ASYN  (WM_USER + 0x5327)

    typedef void (*CoreMainTask)(void *data);
    struct TaskAsyncData {
        CoreMainTask call;
        void* data;
        void* dataEx;
        HANDLE event;
        void* ret;
        DWORD fromThreadId;
        DWORD toThreadId;
    };
    
public:
    static void init(const wkeSettings* settings);
    
    static void callBlinkThreadAsync(std::function<void(void)>&& closure);
    static void callBlinkThreadSync(std::function<void(void)>&& closure);
    static void callUiThreadSync(std::function<void(void)>&& closure);
    static void callUiThreadAsync(std::function<void(void)>&& closure);

    static void postNodeCoreThreadTask(std::function<void(void)>&& closure);

    static void shutdown();

    static void exitMessageLoop(DWORD threadId);
    static void messageLoop();

    static DWORD getUiThreadId() { return m_uiThreadId; }
    static DWORD getBlinkThreadId() { return m_blinkThreadId; }

    static bool isBlinkThread();
    static bool isUiThread();

    static void setMainThread();

private:
    static void createBlinkThread(const wkeSettings* settings);
    static void threadCallbackWrap(void* data);
    static void asynThreadCallbackWrap(void* data);

    static DWORD m_blinkThreadId;
    static DWORD m_uiThreadId;
    static DWORD m_mainThreadId;

    static void callbackInOtherThread(TaskAsyncData* asyncData);

    static void callAsync(TaskAsyncData* asyncData, CoreMainTask call, void* data);

    static void* waitForCallThreadAsync(TaskAsyncData* asyncData);

    static TaskAsyncData* cretaeAsyncData(DWORD toThreadId);

    static unsigned int CALLBACK blinkThread(void* created);
};

} // MtRender