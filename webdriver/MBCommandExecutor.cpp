
#include "webdriver/MBCommandExecutor.h"

#include "webdriver/MBSession.h"
#include "webdriver/CommandHandlerRepository.h"
#include "webdriver/MBCommandHandler.h"
#include "webdriver/CommandExecutor.h"
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
    OutputDebugStringToFile("MBCommandExecutor::threadProc 4\n");
    *wait = 1;

    mbRunMessageLoop();
    return 0;
}

void MB_CALL_TYPE onJsQueryCallback(mbWebView webView, void* param, mbJsExecState es, int64_t queryId, int customMsg, const utf8* request);

static void MB_CALL_TYPE onAlertBoxCallback(mbWebView webview, void* param, const utf8* msg)
{
    std::string output("Alert: ");
    output += msg;
    output += '\n';
    OutputDebugStringA(output.c_str());
    //MessageBoxA(0, output.c_str(), 0, 0);

    const std::string* newStr = (const std::string*)mbGetUserKeyValue(webview, "AlertText");
    if (newStr)
        delete newStr;
    newStr = new std::string(msg);
    mbSetUserKeyValue(webview, "AlertText", (void*)newStr);
    OutputDebugStringA("onAlertBoxCallback 1\n");

    int count = 0;
    while (count < 20) {
        count++;
        const char* alertWaitFlag = (const char*)mbGetUserKeyValue(webview, "AlertWaitFlag");
        if (alertWaitFlag) {
            std::string alertWaitFlagStr = alertWaitFlag;
            if ("AcceptAlert" == alertWaitFlagStr || "DismissAlert" == alertWaitFlagStr)
                break;
        }
        Sleep(500);
    }
    OutputDebugStringA("onAlertBoxCallback 2\n");
}

static BOOL MB_CALL_TYPE onLoadUrlBegin(mbWebView webView, void* param, const char* url, void* job)
{
    //http://web-platform.test:8000/webdriver/tests/support/inline.py?doc=%3C%21doctype+html%3E%0A%3Cmeta+charset%3DUTF-8%3E%0A%3Ca+href%3D%23%3Elink+text%3C%2Fa%3E&mime=text%2Fhtml&charset=UTF-8
    if (0 == strstr(url, "inline.py?doc=%3C%21doctype+html%3E%0A%3Cmeta+charset%3DUTF-8%3E%0A%3Ca+href%3D%23%3Elink+text%3C%2Fa%3E"))
        return FALSE;

    mbNetHookRequest(job);
    return TRUE;
}

static void MB_CALL_TYPE onLoadUrlEnd(mbWebView webView, void* param, const char* url, void* job, void* buf, int len)
{
    std::string urlStr("handleLoadUrlEnd:");
    urlStr += std::string((const char*)buf, len);
    urlStr += "\n";
    OutputDebugStringA(urlStr.c_str());
}

static void initWebview(mbWebView mbView)
{
    ::mbSetNavigationToNewWindowEnable(mbView, TRUE);
    ::mbSetCspCheckEnable(mbView, TRUE);
    ::mbShowWindow(mbView, TRUE);
    ::mbOnAlertBox(mbView, onAlertBoxCallback, nullptr);
    ::mbOnLoadUrlBegin(mbView, onLoadUrlBegin, nullptr);
    ::mbOnLoadUrlEnd(mbView, onLoadUrlEnd, nullptr);
}

// 本函数位于webkit线程
mbWebView MBCommandExecutor::onCreateViewCallback(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url, const mbWindowFeatures* windowFeatures)
{
    std::string output = "onCreateViewCallback:";
    output += url;
    output += "\n";
    OutputDebugStringToFile(output.c_str());

    mbWebView mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 110, 60, 600, 700);
    ::mbOnCreateView(mbView, onCreateViewCallback, nullptr);
    initWebview(mbView);

    MBCommandExecutor* executor = (MBCommandExecutor*)param;
    executor->addManagedBrowser(mbView, MBSession::uuidCreate());

    return mbView;
}

// 本函数执行在http server work线程
int MBCommandExecutor::createNewBrowser(std::string* errorMessage, mbWebView* mbwebview, std::string* browserId)
{
    WDLOG(TRACE) << "Entering MBCommandExecutor::CreateNewBrowser";

    mbWebView mbView = NULL_WEBVIEW;
    MBCommandExecutor* self = this;
    postToUiThreadSync([self , &mbView] {
        mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 100, 50, 600, 700);
        mbOnJsQuery(mbView, onJsQueryCallback, (void*)self);
        mbOnCreateView(mbView, onCreateViewCallback, (void*)self);
        initWebview(mbView);
    });

    if (mbwebview)
        *mbwebview = mbView;

    //LOG(INFO) << "Persistent hovering set to: " << this->input_manager_->use_persistent_hover();
    //this->proxy_manager_->SetProxySettings(process_window_info.hwndBrowser);
    addManagedBrowser(mbView, MBSession::uuidCreate());

    return WD_SUCCESS;
}

void MBCommandExecutor::addManagedBrowser(mbWebView mbView, const std::string& browserId)
{
    WDLOG(TRACE) << "Entering MBCommandExecutor::AddManagedBrowser"; // 只有SwitchToWindowCommandHandler才能强行设置当前webview
    ::EnterCriticalSection(&m_managedBrowsersLock);
    m_managedBrowsers[browserId] = mbView;
    ::LeaveCriticalSection(&m_managedBrowsersLock);

    if (m_mbView == NULL_WEBVIEW) {
        WDLOG(TRACE) << "Setting current browser id to " << browserId;
        setView(mbView, browserId);
    }
}

void MBCommandExecutor::setView(mbWebView view, const std::string& browserId)
{
    ::EnterCriticalSection(&m_managedBrowsersLock);
    m_mbView = view;
    m_browserId = browserId;
    ::LeaveCriticalSection(&m_managedBrowsersLock);
}

int MBCommandExecutor::getManagedBrowser(const std::string& browserId, mbWebView* webview) const
{
    WDLOG(TRACE) << "Entering MBCommandExecutor::GetManagedBrowser";

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
        if (webview == it->second) {
            m_managedBrowsers.erase(it);
            break;
        }
    }
    ::LeaveCriticalSection(&m_managedBrowsersLock);
}


void MBCommandExecutor::getManagedBrowserHandles(std::vector<std::string>* managedBrowsers) const
{
    WDLOG(TRACE) << "Entering MBCommandExecutor::GetManagedBrowserHandles";

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
    if (!m_commandHandlers->IsValidCommand(command.command_type())) {
        std::string output = "Command not implemented:";
        output += command.command_type();
        MessageBoxA(0, output.c_str(), 0, 0);
        WDLOG(WARN) << "Unable to find command handler for " << command.command_type();
        response.SetErrorResponse(ERROR_UNKNOWN_COMMAND, "Command not implemented");
    } else if (!command.is_valid_parameters()) {
        WDLOG(WARN) << "command.is_valid_parameters for " << command.command_type();
        response.SetErrorResponse(ERROR_INVALID_ARGUMENT, "parameters property of command is not a valid JSON object");
    } else {
        std::string command_type = command.command_type();
        CommandHandlerHandle handle = m_commandHandlers->GetCommandHandler(command.command_type());
        handle->Execute(*this, command, &response);
        isOk = true;
    }    
    *serializedResponse = response.Serialize();
    return isOk;
}

}