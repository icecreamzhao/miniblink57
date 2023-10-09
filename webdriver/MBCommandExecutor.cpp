
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

static void postToUiThreadSync(std::function<void(void)>&& closure)
{
    CallMbThreadInfo info;
    info.closure = std::move(closure);
    mbPostToUiThread(onCallMbThread, (void*)&info);
    while (info.wait == 0) {
        Sleep(100);
    }
}

#ifndef _WIN32
inline void mbInitCustom(const mbSettings* settings)
{
    void* g_hMiniblinkMod = nullptr;
    //void* g_hMiniblinkMod = dlopen("/home/daniel/Desktop/wkexe/miniblink.so", RTLD_LAZY);
    //g_hMiniblinkMod = dlopen("/home/weolar/test/livi-browser-gtk/build/miniblink.so", RTLD_LAZY);
    if (!g_hMiniblinkMod)
        g_hMiniblinkMod = dlopen("./miniblink.so", RTLD_LAZY);

    FN_mbInit mbInitExFunc = (FN_mbInit)dlsym(g_hMiniblinkMod, "mbInit");

    char* output = (char*)malloc(0x100);
    sprintf(output, "mbInitCustom: %p\n", mbInitExFunc);
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

// 本函数执行在http server work线程
int MBCommandExecutor::createNewBrowser(std::string* errorMessage, mbWebView* mbwebview, std::string* browserId)
{
    WDLOG(TRACE) << "Entering MBCommandExecutor::CreateNewBrowser";

    mbWebView mbView = NULL_WEBVIEW;
    MBCommandExecutor* self = this;
    postToUiThreadSync([self , &mbView] {
        mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 100, 50, 600, 700);
        mbShowWindow(mbView, TRUE);
        mbOnJsQuery(mbView, onJsQueryCallback, (void*)self);
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
    m_managedBrowsers[browserId] = mbView;

    if (m_mbView == NULL_WEBVIEW) {
        WDLOG(TRACE) << "Setting current browser id to " << browserId;
        setView(mbView, browserId);
    }
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

    BrowserMap::const_iterator it = m_managedBrowsers.find(browserId);
    if (it == m_managedBrowsers.end()) {
        WDLOG(WARN) << "Unable to find managed browser with id " << browserId;
        return ENOSUCHWINDOW;
    }

    *webview = it->second;
    return WD_SUCCESS;
}

bool MBCommandExecutor::isValidWebView(mbWebView webviewHandle)
{
    return mbOnPrinting(webviewHandle, nullptr, nullptr);
}

void MBCommandExecutor::setCurrentBrowserId(const std::string& id)
{
    DebugBreak();
}

void MBCommandExecutor::getManagedBrowserHandles(std::vector<std::string>* managedBrowsers) const
{
    WDLOG(TRACE) << "Entering MBCommandExecutor::GetManagedBrowserHandles";

    BrowserMap::const_iterator it = m_managedBrowsers.begin();
    for (; it != m_managedBrowsers.end(); ++it) {
        if (isValidWebView(it->second)) {
            managedBrowsers->push_back(it->first);
        }
        // Look for browser windows created by showModalDialog().
        //it->second->GetActiveDialogWindowHandle();
    }
}

bool MBCommandExecutor::executeCommand(const std::string& serializedCommand, std::string* serializedResponse)
{
    Command command;
    command.Deserialize(serializedCommand);
    Response response;

    if (!m_commandHandlers->IsValidCommand(command.command_type())) {
        WDLOG(WARN) << "Unable to find command handler for " << command.command_type();
        response.SetErrorResponse(ERROR_UNKNOWN_COMMAND, "Command not implemented");
        DebugBreak();
        return false;
    } else if (!command.is_valid_parameters()) {
        WDLOG(WARN) << "command.is_valid_parameters for " << command.command_type();
        response.SetErrorResponse(ERROR_UNKNOWN_COMMAND, "Command not implemented");
        DebugBreak();
        return false;
    }

    std::string command_type = command.command_type();
    CommandHandlerHandle handle = m_commandHandlers->GetCommandHandler(command.command_type());
    handle->Execute(*this, command, &response);
    
    *serializedResponse = response.Serialize();

    return true;
}

}