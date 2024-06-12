
#include "webdriver/MBCommandExecutor.h"

#include "webdriver/MBSession.h"
#include "webdriver/CommandHandlerRepository.h"
#include "webdriver/MBCommandHandler.h"
#include "webdriver/CommandExecutor.h"
#include "webdriver/WebDriverConstants.h"
#include "webdriver/CommandHandlers/ElementUtil.h"
#include "webdriver/server/command.h"
#include "webdriver/server/response.h"
#include "webdriver/server/errorcodes.h"
#include "webdriver/server/command_types.h"
#include "webdriver/server/wd_logging.h"

#include <functional>
#include <process.h>
#include <string.h>

typedef unsigned(__stdcall* ThreadProcedure)(void*);

namespace webdriver {

MBCommandExecutor::MBCommandExecutor()
{
    static unsigned int s_threadId = 0;
    if (s_threadId == 0) {
        uintptr_t wait = 0;
        ThreadProcedure thread_proc = &MBCommandExecutor::threadProc;
        _beginthreadex(NULL, 0, thread_proc, (void*)(&wait), 0, &s_threadId);
        while (wait == 0) {
            Sleep(10);
        }
    }

    ::InitializeCriticalSection(&m_managedBrowsersLock);
    m_commandHandlers = new CommandHandlerRepository();
}

void MBCommandExecutor::initialize(int port, const std::string& sessionId)
{
    m_sessionId = sessionId;
}

#ifdef _WIN32
#pragma pack(push, 8)
typedef struct {
    DWORD dwType;     /* Must be 0x1000. */
    LPCSTR szName;    /* Pointer to name (in user addr space). */
    DWORD dwThreadID; /* Thread ID (-1=caller thread). */
    DWORD dwFlags;    /* Reserved for future use, must be zero. */
} THREADNAME_INFO_XP;
#pragma pack(pop)

static void setThreadName(const char* name)
{
    THREADNAME_INFO_XP info;
    info.dwType = 0x1000;
    info.szName = name;
    info.dwThreadID = ::GetCurrentThreadId();
    info.dwFlags = 0;

    __try {
        RaiseException(0x406D1388, 0, sizeof(info) / sizeof(DWORD),
            reinterpret_cast<DWORD_PTR*>(&info));
    }
    __except (EXCEPTION_CONTINUE_EXECUTION) {
    }
}
#endif // _WIN32

struct CallMbThreadInfo {
    uintptr_t wait = 0;
    std::function<void(void)> closure;
};

static void MB_CALL_TYPE onCallMbThread(mbWebView webView, void* param)
{
    CallMbThreadInfo* info = (CallMbThreadInfo*)param;
    (info->closure)();
    info->wait = 1;
}

void postToUiThreadSync(std::function<void(void)>&& closure)
{
    CallMbThreadInfo info;
    info.closure = std::move(closure);
    mbPostToUiThread(onCallMbThread, (void*)&info);
    while (info.wait == 0) {
        Sleep(100);
    }
}

static void MB_CALL_TYPE onCallMbThreadAsync(mbWebView webView, void* param)
{
    CallMbThreadInfo* info = (CallMbThreadInfo*)param;
    (info->closure)();
    delete info;
}

void postToUiThreadAsync(std::function<void(void)>&& closure)
{
    CallMbThreadInfo* info = new CallMbThreadInfo();
    info->closure = std::move(closure);
    mbPostToUiThread(onCallMbThreadAsync, (void*)info);
}

#ifndef _WIN32
void mbInitCustom(const mbSettings* settings)
{
    void* g_hMiniblinkMod = nullptr;
    //g_hMiniblinkMod = dlopen("/home/weolar/test/wpt-master/_venv3/bin/chrome/miniblink.so", RTLD_LAZY);
    //g_hMiniblinkMod = dlopen("/home/weolar/test/livi-browser-gtk/build/miniblink.so", RTLD_LAZY);
    if (!g_hMiniblinkMod) {
        std::vector<char> pathUtf8;
        pathUtf8.resize(400);
        memset(pathUtf8.data(), 0, pathUtf8.size());
        readlink("/proc/self/exe", pathUtf8.data(), pathUtf8.size() - 1);
        //g_hMiniblinkMod = dlopen("./miniblink.so", RTLD_LAZY);
        std::string path(pathUtf8.data());
        if ('/' == path[path.size() - 1]) // xxx/xxx/ -> xxx/xxx
            path[path.size() - 1] = ' ';
        size_t pos = path.find_last_of('/');
        path = path.substr(0, pos);
        path += "/miniblink.so";

        std::string outputStr = "mbInitCustom, path: ";
        outputStr += path;
        outputStr += "\n";
        OutputDebugStringToFile(outputStr.c_str());

        g_hMiniblinkMod = dlopen(path.c_str(), RTLD_LAZY);
    }

    FN_mbInit mbInitExFunc = (FN_mbInit)dlsym(g_hMiniblinkMod, "mbInit");

    char* output = (char*)malloc(0x100);
    sprintf(output, "mbInitCustom: g_hMiniblinkMod:%p, mbInitExFunc:%p\n", g_hMiniblinkMod, mbInitExFunc);
    OutputDebugStringToFile(output);
    free(output);

    mbInitExFunc(settings);

    OutputDebugStringToFile("mbInitCustom 2\n");

    MB_FOR_EACH_DEFINE_FUNCTION(MB_GET_PTR_ITERATOR0, MB_GET_PTR_ITERATOR1, MB_GET_PTR_ITERATOR2, MB_GET_PTR_ITERATOR3, \
        MB_GET_PTR_ITERATOR4, MB_GET_PTR_ITERATOR5, MB_GET_PTR_ITERATOR6, MB_GET_PTR_ITERATOR7, MB_GET_PTR_ITERATOR8, \
        MB_GET_PTR_ITERATOR9, MB_GET_PTR_ITERATOR10, MB_GET_PTR_ITERATOR11);
}
#endif

unsigned int MBCommandExecutor::threadProc(LPVOID lpParameter)
{
    OutputDebugStringToFile("MBCommandExecutor::threadProc 1\n");
#ifdef _WIN32
    setThreadName("MbUiThread");
#endif

    uintptr_t* wait = (uintptr_t*)lpParameter;
#ifdef _WIN32
    mbSetMbMainDllPath(L"miniblink_5775_x32.dll");
    mbInit(nullptr);
#else
    mbInitCustom(nullptr);    
#endif

    char* output = (char*)malloc(0x100);
    sprintf(output, "MBCommandExecutor::threadProc: %d\n", ::GetCurrentThreadId());
    OutputDebugStringA(output);
    free(output);

    *wait = 1;

    mbRunMessageLoop();

    OutputDebugStringA("MBCommandExecutor::threadProc exit!\n");
    return 0;
}

void MB_CALL_TYPE onJsQueryCallback(mbWebView webView, void* param, mbJsExecState es, int64_t queryId, int customMsg, const utf8* request);

BOOL onBoxCallback(mbWebView webview, void* param, const utf8* msg)
{
    JsQueryInfo* jsQueryInfo = (JsQueryInfo*)mbGetUserKeyValue(webview, "JsQueryInfo");

    ::EnterCriticalSection(&jsQueryInfo->lock);
    jsQueryInfo->isAlertOpen = true;
    jsQueryInfo->alertWaitFlag = "";
    jsQueryInfo->alertText = msg;
    ::LeaveCriticalSection(&jsQueryInfo->lock);

    BOOL ok = FALSE;
    int count = 0;
    while (/*count < 20*/true) {
        count++;

        std::string alertWaitFlag;
        ::EnterCriticalSection(&jsQueryInfo->lock);
        alertWaitFlag = jsQueryInfo->alertWaitFlag;
        ::LeaveCriticalSection(&jsQueryInfo->lock);

        if ("accept" == alertWaitFlag) {
            ok = TRUE;
            break;
        } else if ("dismiss" == alertWaitFlag) {
            ok = FALSE;
            break;
        }
        Sleep(100);
    }

    ::EnterCriticalSection(&jsQueryInfo->lock);
    jsQueryInfo->isAlertOpen = false;
    jsQueryInfo->alertWaitFlag = "";
    ::LeaveCriticalSection(&jsQueryInfo->lock);

    return ok;
}

mbStringPtr MB_CALL_TYPE onPromptBoxCallback(mbWebView webview, void* param, const utf8* msg, const utf8* defaultResult, BOOL* result)
{
    OutputDebugStringA("onPromptBoxCallback\n");
    *result = onBoxCallback(webview, param, msg);

    char* output = (char*)malloc(400);
    sprintf(output, "onPromptBoxCallback: [%s] [%s], [%d]\n", msg, defaultResult, *result);
    OutputDebugStringA(output);
    free(output);

    return mbCreateString(defaultResult, strlen(defaultResult));
}

BOOL MB_CALL_TYPE onConfirmBoxCallback(mbWebView webview, void* param, const utf8* msg)
{
    std::string output("onConfirmBoxCallback: ");
    output += msg;
    output += '\n';
    OutputDebugStringA(output.c_str());

    bool ok = onBoxCallback(webview, param, msg);
    OutputDebugStringA("onConfirmBoxCallback ok\n");
    return ok;
}

static void MB_CALL_TYPE onAlertBoxCallback(mbWebView webview, void* param, const utf8* msg)
{
    std::string output("onAlertBoxCallback: ");
    output += msg;
    output += '\n';
    OutputDebugStringA(output.c_str());

    onBoxCallback(webview, param, msg);
    OutputDebugStringA("onAlertBoxCallback ok\n");
}

static BOOL MB_CALL_TYPE onLoadUrlBegin(mbWebView webView, void* param, const char* url, void* job)
{
    //http://web-platform.test:8000/webdriver/tests/support/inline.py?doc=%3C%21doctype+html%3E%0A%3Cmeta+charset%3DUTF-8%3E%0A%3Ca+href%3D%23%3Elink+text%3C%2Fa%3E&mime=text%2Fhtml&charset=UTF-8
//     if (0 == strstr(url, "inline.py?doc=%3C%21doctype+html%3E%0A%3Cmeta+charset%3DUTF-8%3E%0A%3Ca+href%3D%23%3Elink+text%3C%2Fa%3E"))
//         return FALSE;

    //mbNetHookRequest(job);
    return TRUE;
}

static void MB_CALL_TYPE onLoadUrlEnd(mbWebView webView, void* param, const char* url, void* job, void* buf, int len)
{
    std::string urlStr("handleLoadUrlEnd:");
    urlStr += std::string((const char*)buf, len);
    urlStr += "\n";
    OutputDebugStringA(urlStr.c_str());
}

// 本函数位于webkit线程
mbWebView MBCommandExecutor::onCreateViewCallback(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url, const mbWindowFeatures* windowFeatures)
{
    std::string output = "onCreateViewCallback:";
    output += url;
    output += "\n";
    OutputDebugStringA(output.c_str());

    mbWebView mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 110, 60, 600, 700);
   
    MBCommandExecutor* executor = (MBCommandExecutor*)param;
    executor->initWebview(mbView);
    executor->addManagedBrowser(mbView, MBSession::uuidCreate());

    return mbView;
}

void MBCommandExecutor::initWebview(mbWebView mbView)
{
    ::mbSetUserKeyValue(mbView, "JsQueryInfo", (void*)new JsQueryInfo());
    ::mbSetNavigationToNewWindowEnable(mbView, TRUE);
    ::mbSetCspCheckEnable(mbView, TRUE);
    ::mbShowWindow(mbView, TRUE);
    ::mbOnAlertBox(mbView, onAlertBoxCallback, nullptr);
    ::mbOnConfirmBox(mbView, onConfirmBoxCallback, nullptr);
    ::mbOnPromptBox(mbView, onPromptBoxCallback, nullptr);
    ::mbOnLoadUrlBegin(mbView, onLoadUrlBegin, nullptr);
    ::mbOnLoadUrlEnd(mbView, onLoadUrlEnd, nullptr);
    ::mbOnCreateView(mbView, MBCommandExecutor::onCreateViewCallback, (void*)this);
    ::mbOnJsQuery(mbView, onJsQueryCallback, (void*)this);
}

// 本函数执行在http server work线程
int MBCommandExecutor::createNewBrowser(std::string* errorMessage, mbWebView* mbwebview, std::string* browserId)
{
    WDLOG(TRACE) << "Entering MBCommandExecutor::CreateNewBrowser";

    mbWebView mbView = NULL_WEBVIEW;
    MBCommandExecutor* self = this;
    postToUiThreadSync([self , &mbView] {
        mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 100, 50, 600, 700);
        self->initWebview(mbView);
    });

    if (mbwebview)
        *mbwebview = mbView;

    //LOG(INFO) << "Persistent hovering set to: " << this->input_manager_->use_persistent_hover();
    //this->proxy_manager_->SetProxySettings(process_window_info.hwndBrowser);
    *browserId = MBSession::uuidCreate();
    addManagedBrowser(mbView, *browserId);

    return WD_SUCCESS;
}

void MBCommandExecutor::addManagedBrowser(mbWebView mbView, const std::string& browserId)
{
    WDLOG(TRACE) << "Entering MBCommandExecutor::AddManagedBrowser"; // 只有SwitchToWindowCommandHandler才能强行设置当前webview
    ::EnterCriticalSection(&m_managedBrowsersLock);
    const size_t oldSize = m_managedBrowsers.size();
    m_managedBrowsers[browserId] = mbView;

    char* output = (char*)malloc(400);
    sprintf(output, "MBCommandExecutor::addManagedBrowser: %d %p, oldSize:%d %d\n", mbView, this, oldSize, m_managedBrowsers.size());
    OutputDebugStringA(output);
    free(output);

    ::LeaveCriticalSection(&m_managedBrowsersLock);

    if (view() == NULL_WEBVIEW) {
        WDLOG(TRACE) << "Setting current browser id to " << browserId;
        setView(mbView, browserId);
    }
}

void MBCommandExecutor::setView(mbWebView view, const std::string& browserId)
{
    ::EnterCriticalSection(&m_managedBrowsersLock);
    m_mbView = view;
    m_browserId = browserId;
    ::mbSetUserKeyValue(m_mbView, "MBCommandExecutor", this);
    ::LeaveCriticalSection(&m_managedBrowsersLock);
}

int MBCommandExecutor::getManagedBrowser(const std::string& browserId, mbWebView* webview) const
{
    //WDLOG(TRACE) << "Entering MBCommandExecutor::GetManagedBrowser";

    if (!is_valid()) {
        WDLOG(TRACE) << "Current command executor is not valid";
        return ENOSUCHDRIVER;
    }

    if (browserId == "") {
        WDLOG(WARN) << "Browser ID requested was an empty string";
        return ENOSUCHWINDOW;
    }

    ::EnterCriticalSection(&m_managedBrowsersLock);
    BrowserMap::const_iterator it = m_managedBrowsers.find(browserId);
    if (it == m_managedBrowsers.end()) {
        ::LeaveCriticalSection(&m_managedBrowsersLock);
        WDLOG(WARN) << "Unable to find managed browser with id " << browserId;
        return ENOSUCHWINDOW;
    }

    *webview = it->second;
    ::LeaveCriticalSection(&m_managedBrowsersLock);
    return WD_SUCCESS;
}

void MBCommandExecutor::closeAllWindow()
{
    OutputDebugStringA("MBCommandExecutor::closeAllWindow\n");
    ::EnterCriticalSection(&m_managedBrowsersLock);
    BrowserMap::const_iterator it = m_managedBrowsers.begin();
    for (; it != m_managedBrowsers.end(); ++it) {
        mbWebView mbView = it->second;
        postToUiThreadAsync([mbView] {
            mbDestroyWebView(mbView);
        });
    }
    m_managedBrowsers.clear();
    ::LeaveCriticalSection(&m_managedBrowsersLock);
}

bool MBCommandExecutor::isValidWebView(mbWebView webviewHandle)
{
    BOOL b = mbOnPrinting(webviewHandle, nullptr, nullptr);
    return b;
}

void MBCommandExecutor::setCurrentBrowserId(const std::string& id)
{
    DebugBreak();
}

void MBCommandExecutor::eraseManagedBrowserHandle(mbWebView webview)
{
    ::EnterCriticalSection(&m_managedBrowsersLock);
    BrowserMap::const_iterator it = m_managedBrowsers.begin();
    for (; it != m_managedBrowsers.end(); ++it) {
        if (webview != it->second)
            continue;

        m_managedBrowsers.erase(it);
        if (view() == webview) {
            if (m_managedBrowsers.size() != 0) {
                it = m_managedBrowsers.begin();
                setView(it->second, it->first);
            }
        }
        break;
    }

    char* output = (char*)malloc(400);
    sprintf(output, "MBCommandExecutor::eraseManagedBrowserHandle: %d\n", m_managedBrowsers.size());
    OutputDebugStringA(output);
    free(output);

    ::LeaveCriticalSection(&m_managedBrowsersLock);
}

void MBCommandExecutor::getManagedBrowserHandles(std::vector<std::string>* managedBrowsers) const
{
    //WDLOG(TRACE) << "Entering MBCommandExecutor::GetManagedBrowserHandles";

    ::EnterCriticalSection(&m_managedBrowsersLock);
    BrowserMap::const_iterator it = m_managedBrowsers.begin();
    for (; it != m_managedBrowsers.end(); ++it) {
        if (isValidWebView(it->second)) {
            managedBrowsers->push_back(it->first);
        }
        // Look for browser windows created by showModalDialog().
        //it->second->GetActiveDialogWindowHandle();
    }
    ::LeaveCriticalSection(&m_managedBrowsersLock);
}

bool MBCommandExecutor::executeCommand(const std::string& serializedCommand, std::string* serializedResponse)
{
    Command command;
    command.Deserialize(serializedCommand);
    Response response;

    bool isOk = false;
    std::string commandType = command.command_type();
    if (!m_commandHandlers->IsValidCommand(commandType)) {
        std::string output = "Command not implemented:";
        output += commandType;
        MessageBoxA(0, output.c_str(), 0, 0);
        WDLOG(WARN) << "Unable to find command handler for " << commandType;
        response.SetErrorResponse(ERROR_UNKNOWN_COMMAND, "Command not implemented");
    } else if (!command.is_valid_parameters()) {
        WDLOG(WARN) << "command.is_valid_parameters for " << commandType;
        response.SetErrorResponse(ERROR_INVALID_ARGUMENT, "parameters property of command is not a valid JSON object");
    } else {
        if (handleAlert(view(), m_unexpectedAlertBehavior, commandType, &response, /*serializedResponse,*/ &isOk)) {

        } else {
            CommandHandlerHandle handle = m_commandHandlers->GetCommandHandler(commandType);
            handle->Execute(*this, command, &response);
            isOk = true;
        }
    }    
    *serializedResponse = response.Serialize();
    return isOk;
}

}