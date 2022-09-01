
#if ENABLE_IN_MB_MAIN
#if ENABLE_NODE_JS
#include "uv.h"
#include "nodeblink.h"
#endif
#endif

#include "ThreadCall.h"
#include "LiveIdDetect.h"
#if ENABLE_IN_MB_MAIN
#include "media/FlashMediaPlayerImpl.h"
#include "media/FFmpegMediaPlayerImpl.h"
#include "media/ffmpeg/FFmpegDll.h"
#if ENABLE_NODE_JS
#include "libplatform/libplatform.h"
#include "v8.h"
#endif
#endif
#include "wke/wkedefine.h"

#include "base/json/json_reader.h"
#include "base/values.h"
#include "third_party/WebKit/Source/wtf/text/qt4/mbchar.h"

#include <shlwapi.h>
#include <process.h>
#include <vector>
#if !defined(WIN32)
#include <gtk/gtk.h>
#endif

// #define VLD_FORCE_ENABLE 1
// #include "C:\\Program Files (x86)\\Visual Leak Detector\\include\\vld.h"

#define USE_ORIG_CC 1

extern HMODULE g_hModule;

namespace wke {
extern bool g_enableSkipJsError;
}

namespace content {
extern DWORD g_uiThreadId;
}

namespace common {

DWORD ThreadCall::m_blinkThreadId = 0;
DWORD ThreadCall::m_uiThreadId = 0;
DWORD ThreadCall::m_mediaThreadId = 0;

ThreadCallballInfo ThreadCall::s_blinkThreadInitedInfo;
ThreadCallballInfo ThreadCall::s_blinkThreadIdleInfo;
ThreadCallballInfo ThreadCall::s_uiThreadIdleInfo;

ThreadCall::CompositorTpye ThreadCall::m_compositorTpye = kCompositorTpyeSoftware;
uv_loop_t* ThreadCall::m_blinkLoop = nullptr;
v8::Platform* ThreadCall::m_v8platform = nullptr;

const int WM_THREAD_CALL = (WM_USER + 0x5325);

std::list<ThreadCall::TaskItem*>* ThreadCall::m_taskQueue[] = { 0 };
CRITICAL_SECTION ThreadCall::m_taskQueueMutex;

UINT kMsgExitMbMsgLoop = 0;

// static bool s_blinkNeedExit = false;
// static bool s_blinkExitFinish = false;

static bool* s_blinkExitFlag = nullptr;

void ThreadCall::init(const mbSettings* settings)
{
    kMsgExitMbMsgLoop = ::RegisterWindowMessageW(u16("exitMbMsgLoop"));
    initTaskQueue();

    m_uiThreadId = ::GetCurrentThreadId();
    createBlinkThread(settings);

    createMediaThread();
    initializeOffScreenTimerWindow();
}

void ThreadCall::initTaskQueue()
{
    if (!m_taskQueue[0]) {
        for (int i = 0; i < kMaxTaskQueue; ++i)
            m_taskQueue[i] = new std::list<TaskItem*>();
        ::InitializeCriticalSection(&m_taskQueueMutex);
    }
}

void ThreadCall::threadCallbackWrap(void* data)
{
    TaskAsyncData* asyncData = (TaskAsyncData*)data;
    std::function<void(void)>* closure = (std::function<void(void)>*)asyncData->dataEx;
    (*closure)();
}

void ThreadCall::asynThreadCallbackWrap(void* data)
{
    TaskAsyncData* asyncData = (TaskAsyncData*)data;
    std::function<void(void)>* closure = (std::function<void(void)>*)asyncData->dataEx;
    (*closure)();
    delete closure;
}

void ThreadCall::callBlinkThreadAsyncWithValid(const TraceLocation& caller, mbWebView webviewHandle, std::function<void(mb::MbWebView* webview)>&& closure)
{
    int64_t id = (int64_t)webviewHandle;
    std::function<void(mb::MbWebView* webview)>* closureDummy = new std::function<void(mb::MbWebView* webview)>(std::move(closure));

    callBlinkThreadAsync(caller, [id, closureDummy] {
        mb::MbWebView* webview = (mb::MbWebView*)common::LiveIdDetect::get()->getPtr(id);
        if (webview)
            (*closureDummy)(webview);
        delete closureDummy;
    });
}

void ThreadCall::callBlinkThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    std::function<void(void)>* closureDummy = new std::function<void(void)>(std::move(closure));
    TaskAsyncData* asyncData = cretaeAsyncData(caller, m_blinkThreadId, closureDummy, m_blinkThreadId);
    callAsync(asyncData, asynThreadCallbackWrap, asyncData);
}

void ThreadCall::callUiThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    std::function<void(void)>* closureDummy = new std::function<void(void)>(std::move(closure));
    TaskAsyncData* asyncData = cretaeAsyncData(caller, m_uiThreadId, closureDummy, m_uiThreadId);
    callAsync(asyncData, asynThreadCallbackWrap, asyncData);
}

void ThreadCall::callSyncAndWait(TaskAsyncData* asyncData)
{
    callAsync(asyncData, threadCallbackWrap, asyncData);
    waitForCallThreadAsync(asyncData);
    delete asyncData;
}

void ThreadCall::callUiThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    TaskAsyncData* asyncData = cretaeAsyncData(caller, m_uiThreadId, &closure, ::GetCurrentThreadId());
    callSyncAndWait(asyncData);
}

void ThreadCall::callBlinkThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    TaskAsyncData* asyncData = cretaeAsyncData(caller, m_blinkThreadId, &closure, ::GetCurrentThreadId());
    callSyncAndWait(asyncData);
}

void ThreadCall::callMediaThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    std::function<void(void)>* closureDummy = new std::function<void(void)>(std::move(closure));
    TaskAsyncData* asyncData = cretaeAsyncData(caller, m_mediaThreadId, closureDummy, m_mediaThreadId);
    callAsync(asyncData, asynThreadCallbackWrap, asyncData);
}

void ThreadCall::setThreadIdle(mbThreadCallback callback, void* param1, void* param2)
{
    common::ThreadCallballInfo* info = nullptr;
    if (common::ThreadCall::isBlinkThread()) {
        info = &common::ThreadCall::s_blinkThreadIdleInfo;
    } else if (common::ThreadCall::isUiThread()) {
        info = &common::ThreadCall::s_uiThreadIdleInfo;
    } else
        return;

    info->cb = callback;
    info->param1 = param1;
    info->param2 = param2;
}

void ThreadCall::setBlinkThreadInited(mbThreadCallback callback, void* param1, void* param2)
{
    common::ThreadCall::s_blinkThreadInitedInfo.cb = callback;
    common::ThreadCall::s_blinkThreadInitedInfo.param1 = param1;
    common::ThreadCall::s_blinkThreadInitedInfo.param2 = param2;
}

void ThreadCall::postNodeCoreThreadTask(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    callUiThreadAsync(caller, std::move(closure));
}

void ThreadCall::shutdown()
{
    exitBlinkMessageLoop();
}

bool ThreadCall::isBlinkThread()
{
    return m_blinkThreadId == ::GetCurrentThreadId();
}

bool ThreadCall::isUiThread()
{
    return m_uiThreadId == ::GetCurrentThreadId();
}

void ThreadCall::callbackInOtherThread(TaskAsyncData* asyncData)
{
    if (asyncData->call) {
        asyncData->ret = nullptr;
        asyncData->call(asyncData->data);
        asyncData->event = TRUE;
    }
}

ThreadCall::TaskQueueType ThreadCall::getWhichTypeByThreadId(DWORD idThread)
{
    if (m_blinkThreadId == idThread)
        return kBlinkTaskQueue;
    if (m_uiThreadId == idThread)
        return kUiTaskQueue;
    if (m_mediaThreadId == idThread)
        return kMediaTaskQueue;
    return kMaxTaskQueue;
}

void ThreadCall::callAsync(TaskAsyncData* asyncData, CoreMainTask call, void* data)
{
    asyncData->call = call;
    asyncData->data = data;
    postThreadMessage(asyncData->toThreadId, WM_THREAD_CALL, asyncData);
}

void* ThreadCall::waitForCallThreadAsync(TaskAsyncData* asyncData)
{
    bool firstPost = false;
    void* ret = asyncData->ret;
    while (!asyncData->event) {
        ::Sleep(1);

        // 有npapi插件的时候，createwebview会死等，然后主窗口又可能会发消息给npapi窗口，造成死锁
        MSG msg;
        if (::PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE) != FALSE) {
            ::TranslateMessage(&msg);
            ::DispatchMessageW(&msg);
        }

        if (!firstPost)
            ::PostThreadMessageW(::GetCurrentThreadId(), WM_NULL, 0, 0);
        firstPost = true;
    }

    return ret;
}

ThreadCall::TaskAsyncData* ThreadCall::cretaeAsyncData(const TraceLocation& caller, DWORD toThreadId, void* dataEx, DWORD destroyThreadId)
{
    TaskAsyncData* asyncData = new TaskAsyncData();
    asyncData->event = FALSE;
    asyncData->dataEx = dataEx;
    asyncData->fromThreadId = ::GetCurrentThreadId();
    asyncData->toThreadId = toThreadId;
    asyncData->destroyThreadId = destroyThreadId;
    asyncData->caller = caller;

    return asyncData;
}

static DWORD s_recordExitFlag = 0;

static void __stdcall runner()
{
    DWORD threadId = ::GetCurrentThreadId();
    bool needExit = ThreadCall::runUntilIdle(threadId);
}

void ThreadCall::exitBlinkMessageLoop()
{
    bool hadExit = false;
    s_blinkExitFlag = &hadExit;
    ::PostThreadMessageW(m_blinkThreadId, WM_QUIT, (WPARAM)::GetCurrentThreadId(), (LPARAM)s_blinkExitFlag);
    while (!hadExit) {
        wake();
        ::Sleep(20);
    }
    OutputDebugStringA("ThreadCall::exitBlinkMessageLoop\n");
}

void ThreadCall::postThreadMessage(DWORD idThread, UINT msg, TaskAsyncData* asyncData)
{
    TaskQueueType type = getWhichTypeByThreadId(idThread);
    if (kMaxTaskQueue == type)
        return;

    ::EnterCriticalSection(&m_taskQueueMutex);

    static size_t s_maxSize = 0;
    if (s_maxSize < m_taskQueue[0]->size())
        s_maxSize = m_taskQueue[0]->size();

//     if (m_taskQueue[0]->size() > 50)
//         OutputDebugStringA("ThreadCall::postThreadMessage too much\n");

    m_taskQueue[type]->push_back(new TaskItem(idThread, msg, asyncData));
    ::LeaveCriticalSection(&m_taskQueueMutex);

    if (kCompositorTpyeMC != m_compositorTpye) {
        if (kBlinkTaskQueue == type)
            wkeSetDebugConfig(nullptr, "postBlinkTask", (const char*)runner);
        else if (kUiTaskQueue == type)
            wkeSetDebugConfig(nullptr, "postUiTask", (const char*)runner);
    }
}

void ThreadCall::wake()
{
    DWORD threadId = ::GetCurrentThreadId();
    runUntilIdle(threadId);

    if (kCompositorTpyeMC != m_compositorTpye) {
        if (isUiThread()) {
            static DWORD s_lastTime = 0;
            DWORD t1 = ::GetTickCount();
            wkeSetDebugConfig(nullptr, "runUntilIdleWithoutMsgPeek", nullptr);
            DWORD t2 = ::GetTickCount();

            if (t1 - s_lastTime != 0) {
//                 char* output = (char*)malloc(0x100);
//                 sprintf_s(output, 0x99, "ThreadCall::wake: %d %d\n", t1 - s_lastTime, t2 - t1);
//                 OutputDebugStringA(output);
//                 free(output);
            }
            s_lastTime = t1;
        }
    }
}

void ThreadCall::runV8(DWORD threadId)
{
#if ENABLE_IN_MB_MAIN
#if ENABLE_NODEJS
    if (loop) {
        BlinkMicrotaskSuppressionHandle handle = nodeBlinkMicrotaskSuppressionEnter(isolate);
        bool more = (0 != uv_run(loop, UV_RUN_NOWAIT));
        nodeBlinkMicrotaskSuppressionLeave(handle);
    }

    if (platform && isolate)
        v8::platform::PumpMessageLoop(platform, isolate);
#endif
#endif
}

bool ThreadCall::runNoWait(DWORD threadId)
{
    runV8(threadId);

    TaskQueueType type = getWhichTypeByThreadId(threadId);
    TaskItem* it = nullptr;

    ::EnterCriticalSection(&m_taskQueueMutex);
    std::list<ThreadCall::TaskItem*>* task = m_taskQueue[type];
    if (!task) {
        ::LeaveCriticalSection(&m_taskQueueMutex);
        return false;
    }

    std::list<ThreadCall::TaskItem*>::iterator itor = m_taskQueue[type]->begin();
    if (itor == m_taskQueue[type]->end()) {
        ::LeaveCriticalSection(&m_taskQueueMutex);
        return false;
    }

    it = *itor;
    m_taskQueue[type]->pop_front();

    ::LeaveCriticalSection(&m_taskQueueMutex);

    if (!it)
        return false;

    bool needExit = (runTaskQueue(it->msg, it->asyncData));
    delete it;

    return needExit;
}

bool ThreadCall::runUntilIdle(DWORD threadId)
{
    runV8(threadId);

    TaskQueueType type = getWhichTypeByThreadId(threadId);
    TaskItem* it = nullptr;
    std::list<ThreadCall::TaskItem*> taskQueue;

    ::EnterCriticalSection(&m_taskQueueMutex);
    if (!m_taskQueue[type]) {
        ::LeaveCriticalSection(&m_taskQueueMutex);
        return false;
    }

    for (std::list<ThreadCall::TaskItem*>::iterator itor = m_taskQueue[type]->begin(); itor != m_taskQueue[type]->end(); ++itor) {
        it = *itor;
        taskQueue.push_back(it);
    }

    m_taskQueue[type]->clear();
    ::LeaveCriticalSection(&m_taskQueueMutex);
    if (!taskQueue.size())
        return false;

    bool needExit = false;
    for (std::list<ThreadCall::TaskItem*>::iterator itor = taskQueue.begin(); itor != taskQueue.end(); ++itor) {
        it = *itor;
        if (runTaskQueue(it->msg, it->asyncData))
            needExit = true;
        delete it;
    }
    
    return needExit;
}

bool ThreadCall::runTaskQueue(UINT msg, TaskAsyncData* asyncData)
{
    if (WM_THREAD_CALL != msg)
        return false;

    callbackInOtherThread(asyncData);

    if (asyncData->destroyThreadId == ::GetCurrentThreadId())
        delete asyncData;
    else if (asyncData->destroyThreadId != asyncData->fromThreadId)
        DebugBreak();

    return false;
}

void ThreadCall::uiMessageLoop()
{
    MSG msg = { 0 };
    DWORD threadId = ::GetCurrentThreadId();
    static DWORD s_lastTime = 0;

    while (WM_QUIT != msg.message) {
        DWORD t1 = ::GetTickCount();

        if (s_uiThreadIdleInfo.cb)
            s_uiThreadIdleInfo.cb(s_uiThreadIdleInfo.param1, s_uiThreadIdleInfo.param2);

        if (runNoWait(threadId))
            break;

//         if (!::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE) && t1 - s_lastTime > 10) {
//             //::Sleep(0);
//             continue;
//         }
// 
//         if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
//             ::TranslateMessage(&msg);
//             ::DispatchMessageW(&msg);
//         }

        if (::GetMessageW(&msg, NULL, 0, 0) > 0) {
            ::TranslateMessage(&msg);
            ::DispatchMessageW(&msg);
        }

        DWORD t2 = ::GetTickCount();

        wake();

        DWORD t3 = ::GetTickCount();
        if (t1 != s_lastTime) {
//             char* output = (char*)malloc(0x100);
//             sprintf_s(output, 0x99, "ThreadCall::uiMessageLoop: %d %d %d\n", t1 - s_lastTime, t2 - t1, t3 - t2);
//             OutputDebugStringA(output);
//             free(output);
        }
        s_lastTime = t1;

//         if (msg.message < WM_USER)
//             ::Sleep(1);
    }
}

void ThreadCall::blinkMessageLoop(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate)
{
    OutputDebugStringA("ThreadCall::blinkMessageLoop\n");

    MSG msg = { 0 };
    DWORD threadId = ::GetCurrentThreadId();

    bool isInBlinkThread = isBlinkThread();
    if (!isInBlinkThread)
        DebugBreak();

    static DWORD s_lastTime = 0;

    while (WM_QUIT != msg.message) {
        DWORD t1 = ::GetTickCount();

        if (isInBlinkThread) {
            if (kCompositorTpyeMC != m_compositorTpye)
                wkeSetDebugConfig(nullptr, "runUntilIdle", nullptr);
            else
                wkeWake(nullptr);
        }

        if (s_blinkThreadInitedInfo.cb) {
            s_blinkThreadInitedInfo.cb(s_blinkThreadInitedInfo.param1, s_blinkThreadInitedInfo.param2);
            s_blinkThreadInitedInfo.cb = nullptr;
        }
        if (s_blinkThreadIdleInfo.cb)
            s_blinkThreadIdleInfo.cb(s_blinkThreadIdleInfo.param1, s_blinkThreadIdleInfo.param2);

        if (runNoWait(threadId)) {
            printf("runNoWait-----------------------------\n");
            break;
        }
//         if (!::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
//              ::Sleep(0);
//             continue;
//         }

        DWORD t2 = ::GetTickCount();

//         while (true) {
//             ::Sleep(100);
//         }

//         if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
//             ::TranslateMessage(&msg);
//             ::DispatchMessageW(&msg);
//         }
#if defined(OS_WIN)
        if (::GetMessageW(&msg, NULL, 0, 0) > 0) {
            ::TranslateMessage(&msg);
            ::DispatchMessageW(&msg);
        }
#else
        usleep(100);
        //printf("ThreadCall::blinkMessageLoop 222\n");
#endif
//         if (msg.message < WM_USER)
//             ::Sleep(1);

        DWORD t3 = ::GetTickCount();

        if (t1 != s_lastTime || t2 != t1 || t3 != t2) {
//             char* output = (char*)malloc(0x100);
//             sprintf_s(output, 0x99, "ThreadCall::blinkMessageLoop: %d %d %d\n", t1 - s_lastTime, t2 - t1, t3 - t2);
//             OutputDebugStringA(output);
//             free(output);
        }
        s_lastTime = t1;

        //::PostThreadMessageW(threadId, WM_USER + 1, 0, 0);
        if (s_blinkExitFlag) {
            OutputDebugStringA("ThreadCall::blinkMessageLoop exit and notif\n");
            break;
        }
    }
}

struct InitBlinkInfo {
    bool created;
    const mbSettings* settings;
};

static HWND s_timerWindowHandle = 0;
const LPCWSTR kTimerWindowClassName = u16("MbVipTimerWindowClass");
static long s_pendingTimers = 0;
static UINT s_timerFiredMessage = 0;
DWORD s_timerWindowWndProcThreadId = 0;

LRESULT CALLBACK ThreadCall::timerWindowWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (s_timerWindowWndProcThreadId != ::GetCurrentThreadId()) // win10好像有bug，会意外的在别的线程本函数被调用
        return 0;

    LRESULT result = 0;

    if (s_timerFiredMessage == message) {
        _InterlockedExchange(&s_pendingTimers, 0);
        wake();
    } else
        result = ::DefWindowProcW(hWnd, message, wParam, lParam);

    return result;
}

static void WINAPI heartbeatTimerProc()
{
    if (!s_timerWindowHandle)
        return;

    if (_InterlockedIncrement(&s_pendingTimers) == 1)
        ::PostMessageW(s_timerWindowHandle, s_timerFiredMessage, 0, 0);
}

void ThreadCall::initializeOffScreenTimerWindow()
{
    if (s_timerWindowHandle)
        return;
    s_timerWindowWndProcThreadId = ::GetCurrentThreadId();

    WNDCLASSEXW wcex = { 0 };
    wcex.cbSize = sizeof(WNDCLASSEXW);
    wcex.lpfnWndProc = timerWindowWndProc;
    wcex.hInstance = ::GetModuleHandleW(NULL);
    wcex.lpszClassName = kTimerWindowClassName;
    ::RegisterClassExW(&wcex);

    s_timerWindowHandle = CreateWindowExW(0, // window ex-style
        kTimerWindowClassName, // window class name
        u16("OffScreenTimer"), // window caption
        WS_POPUP, 1, 1, 1, 1, NULL, NULL, ::GetModuleHandleW(NULL), NULL);
    //::SetTimer(s_timerWindowHandle, (UINT_PTR)s_timerWindowHandle, 10, 0);
    s_timerFiredMessage = RegisterWindowMessageW(u16("com.weolar.MbVip.TimerFired"));

    wkeSetDebugConfig(nullptr, "setUiThreadHeartbeatCallback", (const char*)heartbeatTimerProc);
}

#if ENABLE_IN_MB_MAIN

static wkeMediaPlayer WKE_CALL_TYPE onMediaPlayerFactory(wkeWebView webView, wkeMediaPlayerClient client, void* npBrowserFuncs, void* npPluginFuncs)
{
#ifndef _WIN64
//     if (!npBrowserFuncs || !npPluginFuncs)
//         return nullptr;
//     return new FlashMediaPlayerImpl(webView, client, npBrowserFuncs, npPluginFuncs);

    *((int*)npBrowserFuncs) = 0;

    if (media::initFFmpeg())
        return new media::FFmpegMediaPlayerImpl(webView, client);
#endif

    return nullptr;
}

#endif

static bool WKE_CALL_TYPE onIsMediaPlayerSupportsMIMEType(const utf8* mime)
{
    std::string mimeStr(mime);
    if (-1 != mimeStr.find("video/mp4"))
        return true;
    if (-1 != mimeStr.find("audio/mpeg"))
        return true;
    return false;
}

void initMainDllPath()
{
#if ENABLE_IN_MB_MAIN
    std::vector<wchar_t>* path = new std::vector<wchar_t>();
    path->resize(MAX_PATH + 1);
    memset(&path->at(0), 0, sizeof(wchar_t) * (MAX_PATH + 1));
    ::GetModuleFileNameW(g_hModule, &path->at(0), MAX_PATH);
    ::PathRemoveFileSpecW(&path->at(0));

    ::PathAppendW(&path->at(0), u16("node.dll"));
    wkeSetWkeDllPath(&path->at(0));
#endif
}

bool isValidVersion(InitBlinkInfo* initBlinkInfo)
{
    if (!initBlinkInfo || !initBlinkInfo->settings)
        return false;

    intptr_t version = initBlinkInfo->settings->version;
    return (kMbVersion <= version && version <= kMbMaxVersion);
}

unsigned int ThreadCall::blinkThread(void* param)
{
    m_blinkThreadId = ::GetCurrentThreadId();

    InitBlinkInfo* initBlinkInfo = (InitBlinkInfo*)param;
    setThreadName("blinkThread");

    wkeSettings settings;
    memset(&settings, 0, sizeof(wkeSettings));

    if (isValidVersion(initBlinkInfo) && initBlinkInfo->settings->mask & WKE_SETTING_PROXY) {
        memcpy(&settings.proxy, &initBlinkInfo->settings->proxy, sizeof(wkeProxy));
    }

    settings.mask |= WKE_SETTING_EXTENSION;
    settings.extension = "EnableOc";
    wkeInitializeEx(kCompositorTpyeMC == m_compositorTpye ? nullptr : &settings);

    if (kCompositorTpyeEGLGLES2 == m_compositorTpye) {
        wkeSetDebugConfig(nullptr, "initOrigChromeBlinkThread:egles2", nullptr);
    } else if (kCompositorTpyeSwiftShader == m_compositorTpye) {
        wkeSetDebugConfig(nullptr, "initOrigChromeBlinkThread:swiftshader", nullptr);
    } else if (kCompositorTpyeSoftware == m_compositorTpye) {
        wkeSetDebugConfig(nullptr, "initOrigChromeBlinkThread", nullptr);
    }

    //wkeSetDebugConfig(nullptr, "paintcallbackInOtherThread", (const char*)m_uiThreadId);
    content::g_uiThreadId = m_uiThreadId;

    wkeSetDebugConfig(nullptr, "smootTextEnable", "1");
    wkeSetDebugConfig(nullptr, "flashChineseEnable", nullptr);
    wkeSetDebugConfig(nullptr, "minimumFontSize", "13");
    //wkeSetDebugConfig(nullptr, "drawTileLine", "1");
    
    initBlinkInfo->created = true;

    v8::Isolate* isolate = nullptr;

#if ENABLE_IN_MB_MAIN
    if (!initBlinkInfo->settings || !(initBlinkInfo->settings->mask & MB_ENABLE_DISABLE_H5VIDEO))
        wkeSetMediaPlayerFactory(nullptr, onMediaPlayerFactory, onIsMediaPlayerSupportsMIMEType);

#if ENABLE_NODEJS
    if (initBlinkInfo->settings && (initBlinkInfo->settings->mask & MB_ENABLE_NODEJS)) {
        m_blinkLoop = (uv_loop_t*)malloc(sizeof(uv_loop_t));
        uv_loop_init(m_blinkLoop);
        m_v8platform = (v8::Platform*)nodeCreateDefaultPlatform();
        isolate = v8::Isolate::GetCurrent();
    }
#endif
    
#endif
//     SYSTEM_INFO SystemInfo;
//     GetSystemInfo(&SystemInfo);
// 
//     if (SystemInfo.dwNumberOfProcessors <= 1)
//         return 0;
//     DWORD dwMask = 0x0000;
//     DWORD dwtmp = 0x0001;
//     int nProcessorNum = 0;
//     for (int i = 0; i < 32; i++) {
//         if (SystemInfo.dwActiveProcessorMask & dwtmp) {
//             nProcessorNum++;
//             if (nProcessorNum <= 2) {
//                 //如果系统中有多个处理器，则选择第二个处理器
//                 dwMask = dwtmp;
//             } else {
//                 break;
//             }
//         }
// 
//         dwtmp *= 2;
//     }
//     ::SetThreadAffinityMask(::GetCurrentThread(), dwMask);

    blinkMessageLoop(m_blinkLoop, m_v8platform, isolate);

#if ENABLE_IN_MB_MAIN
    //wkeSaveMemoryCache(nullptr);
#endif

#ifdef _DEBUG
    wkeShutdownForDebug();
#else
    wkeSetDebugConfig(nullptr, "saveDiskCache", nullptr);
#endif
    *s_blinkExitFlag = true;

    return 0;
}

void ThreadCall::setConfigOfSetting(const mbSettings* settings)
{
    std::unique_ptr<base::Value> json = base::JSONReader::Read(base::StringPiece(settings->config));
    if (!json.get())
        return;

    base::DictionaryValue* json_value = nullptr;
    if (!json->GetAsDictionary(&json_value))
        return;

    bool enableSkipJs = false;
    if (json_value->GetBoolean("enableSkipJs", &enableSkipJs) && enableSkipJs)
        wke::g_enableSkipJsError = true;
}

void ThreadCall::createBlinkThread(const mbSettings* settings)
{
    InitBlinkInfo initBlinkInfo;
    initBlinkInfo.created = false;
    initBlinkInfo.settings = settings;

    if (settings) {
        m_compositorTpye = (settings->mask & MB_ENABLE_DISABLE_CC) ? kCompositorTpyeMC : kCompositorTpyeSoftware;
        if (settings->mask & MB_ENABLE_ENABLE_EGLGLES2)
            m_compositorTpye = kCompositorTpyeEGLGLES2;

        if (settings->mask & MB_ENABLE_ENABLE_SWIFTSHAER)
            m_compositorTpye = kCompositorTpyeSwiftShader;

        if (settings->version >= kMbVersion && settings->config) {
            setConfigOfSetting(settings);
        }
    }

#ifdef _WIN64
    m_compositorTpye = kCompositorTpyeMC;
#endif

    if (m_compositorTpye != kCompositorTpyeMC)
        OutputDebugStringW(u16("开启CC\n"));
    else
        OutputDebugStringW(u16("禁用CC\n"));

    unsigned threadIdentifier = 0;
    HANDLE threadHandle = reinterpret_cast<HANDLE>(_beginthreadex(0, 0, blinkThread, &initBlinkInfo, 0, &threadIdentifier));

    while (!initBlinkInfo.created) { ::Sleep(20); }
#if defined(OS_WIN)
    ::CloseHandle(threadHandle);
#endif
    if (kCompositorTpyeMC != m_compositorTpye)
        wkeSetDebugConfig(nullptr, "initOrigChromeUiThread", nullptr);
}

unsigned int ThreadCall::mediaThread(void* param)
{
//     setThreadName("mbMediaThread");
//     m_mediaThreadId = ::GetCurrentThreadId();
//     blinkMessageLoop(nullptr, nullptr, nullptr);
    return 0;
}

void ThreadCall::createMediaThread()
{
//     unsigned threadIdentifier = 0;
//     HANDLE threadHandle = reinterpret_cast<HANDLE>(_beginthreadex(0, 0, mediaThread, nullptr, 0, &threadIdentifier));
//     ::CloseHandle(threadHandle);
}

typedef struct tagTHREADNAME_INFO {
    DWORD dwType; // must be 0x1000
    LPCSTR szName; // pointer to name (in user addr space)
    DWORD dwThreadID; // thread ID (-1=caller thread)
    DWORD dwFlags; // reserved for future use, must be zero
} THREADNAME_INFO;

void ThreadCall::setThreadName(const char* szThreadName)
{
#if defined(OS_WIN) 
    THREADNAME_INFO info;
    info.dwType = 0x1000;
    info.szName = szThreadName;
    info.dwThreadID = ::GetCurrentThreadId();
    info.dwFlags = 0;

    __try {
        ::RaiseException(0x406D1388, 0, sizeof(info) / sizeof(DWORD), (const ULONG_PTR*)&info);
    } __except (EXCEPTION_CONTINUE_EXECUTION) {
    }
#endif
}

} // common

void MyOutputDebugStringA(const char* lpcszOutputString, ...)
{
#if defined(OS_WIN) 
    std::string strResult;
    if (NULL != lpcszOutputString) {
        va_list marker = NULL;
        va_start(marker, lpcszOutputString); //初始化变量参数
        size_t nLength = _vscprintf(lpcszOutputString, marker) + 1; //获取格式化字符串长度
        std::vector<char> vBuffer(nLength, '\0'); //创建用于存储格式化字符串的字符数组
        int nWritten = _vsnprintf_s(&vBuffer[0], vBuffer.size(), nLength, lpcszOutputString, marker);
        if (nWritten > 0) {
            strResult = &vBuffer[0];
        }
        va_end(marker); //重置变量参数
    }
    if (!strResult.empty()) {
        std::string strFormated = "[sunflover] ";
        strFormated.append(strResult);
        OutputDebugStringA(strFormated.c_str());
    }
#endif
}