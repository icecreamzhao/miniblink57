
#define ENABLE_MB 1
#define _CRT_SECURE_NO_WARNINGS 1

//#define ENABLE_IN_MB_MAIN

#include "core/mb.h"
#include "core/MbWebView.h"
#include "wke/wkedefine.h"
#include "common/ThreadCall.h"
#include "common/StringUtil.h"
#include "common/LiveIdDetect.h"
#if ENABLE_IN_MB_MAIN
#include "verify/SqBind.h"
#include "printing/PdfViewerPlugin.h"
#include "printing/Printing.h"
#include "download/DownloadMgr.h"
#endif // ENABLE_IN_MB_MAIN

#include <vector>
#include <stdio.h>
#include <Shlwapi.h>

bool g_mbIsInit = false;
DWORD g_uiThreadId = 0;

namespace mb {
unsigned int g_mbMask = 0;
}

mbStringPtr MB_CALL_TYPE mbCreateString(const utf8* str, size_t length)
{
    return (mbStringPtr)wkeCreateString(str, length);
}

void MB_CALL_TYPE mbDeleteString(mbStringPtr str)
{
    wkeDeleteString((wkeString)str);
}

static bool checkThreadCallIsValidImpl(const char* funcName, bool isBlinkThread)
{
    std::wstring textMsg;
    if (!g_mbIsInit) {
        textMsg = L"禁止未初始化调用此接口：";
        textMsg += common::utf8ToUtf16(funcName);
        ::MessageBoxW(nullptr, textMsg.c_str(), L"警告", MB_OK);
        ::TerminateProcess((HANDLE)-1, 5);
        return false;
    }

    if (isBlinkThread) {
        if (common::ThreadCall::isBlinkThread())
            return true;
    } else {
        if (common::ThreadCall::isUiThread())
            return true;
    }

    textMsg = L"禁止跨线程调用此接口：";
    textMsg += common::utf8ToUtf16(funcName);
    textMsg += L"，";

    wchar_t* temp = (wchar_t*)malloc(0x200);
    wsprintf(temp, L"当前线程:%d，主线程：%d", ::GetCurrentThreadId(), common::ThreadCall::getUiThreadId());
    textMsg += temp;
    free(temp);

    ::MessageBoxW(nullptr, textMsg.c_str(), L"警告", MB_OK);
    ::TerminateProcess((HANDLE)-1, 5);
    return false;
}

static bool checkThreadCallIsValid(const char* funcName)
{
    return checkThreadCallIsValidImpl(funcName, false);
}

void MB_CALL_TYPE mbInit(const mbSettings* settings)
{
    if (g_mbIsInit)
        return;
    g_mbIsInit = true;
    if (settings)
        mb::g_mbMask = settings->mask;
    OutputDebugStringA("mb.cpp, mbInit\n");    

    common::ThreadCall::init((const mbSettings*)settings);
}

void MB_CALL_TYPE mbUninit()
{  
    common::ThreadCall::shutdown();
}

mbWebView MB_CALL_TYPE mbCreateWebView()
{
    checkThreadCallIsValid(__FUNCTION__);
    mb::MbWebView* result = new mb::MbWebView();

    common::ThreadCall::callBlinkThreadAsync([result] {
        result->createWkeWebWindowOrViewInBlinkThread(false);
    });

    return result;
}

#define ENABLE_VERIFY 0

static void licenseCheck()
{
#if ENABLE_VERIFY && ENABLE_IN_MB_MAIN
    static bool isInit = false;
    if (!isInit) {
        isInit = true;
        SqBind* verify = SqBind::getInst();

#if 0
        // std::string requestCode = verify->createRequestCode("email:weolar@qq.com");
        std::string license = verify->createLicense("4gAAAMgBAAC6AQAAEAYAAJMCAAC6AQAAsgQAALoBAABMAgAAzwQAALoBAABOAgAAkwIAALgBAADEBAAAAwcAALoBAADwBQAA8AUAALACAABaAgAAbQAAALoAAADwBQAA8AUAAAMGAABSBgAAuAYAAM8AAACoAgAAUwAAAOcBAABLAAAAWgIAAFMAAACwAgAAawEAALgGAAAuAgAAsAIAADkBAABsBQAAmwEAALACAABLAAAA5wEAAAwBAAADBwAANQQAAAwBAADPBAAAgAAAAIAAAAAGAwAADgcAAAYDAAADAAAABQAAAAMAAAADAAAAAwAAAAMAAAADAAAAAwAAAAMAAAADAAAA/wUAAOcBAAAMAQAAAwcAAAMGAABxBAAAsgQAAP0AAADiAAAAmAMAAE4CAAA5AQAAuAEAAC4CAADnAQAABQAAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAACLAwAAuAEAAC4CAADnAQAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAAsAIAAIsDAABsBQAAmwEAAOcBAABLAAAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAHgIAAGwFAABLAAAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA5wEAADkBAAC4BgAAfAAAAIMGAABLAAAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAmAMAAIMGAABLAAAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA5wEAAMEDAABsBQAAUwAAAOcBAABLAAAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAmwEAAGwFAADBAwAAWgIAAHwAAADaAgAAmAMAAGwFAAAuAgAA5wEAADkBAABsBQAA5wEAAMQEAADtAwAA5wEAAAwBAAADBwAAAwYAAHEEAABaAgAAawYAAFIGAACbAQAA5wEAADkBAAC4AQAALgIAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA2gIAAAMAAAC4AQAAagYAAAMHAACAAAAAqAIAAAwBAABSBgAA/QAAAKgCAAB8AAAAUgYAAKoFAACoAgAADAEAALIEAACAAAAAqAIAAOcBAADEBAAA+AEAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAugAAAOcBAAD9AAAAqgUAAKgCAAAMAQAAsgQAAIAAAACoAgAAuAEAAGgFAACtAQAASwAAAK0BAACXBAAAUwAAAKgCAACLAwAAqgUAAIAAAABLAAAAbQAAALIEAABaAgAASwAAAK0BAACXBAAAWgIAAAMGAACbAQAAUgYAALgGAABsBQAAPQMAANoCAACBBgAAawYAAOIBAACXBAAAUgYAALACAADaAgAA5wEAAIEGAABsBQAAuAEAAPgBAABrAQAAbAUAANoCAAADBwAAsAIAALoBAACBBgAAxAQAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAACbAQAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAALACAABTAAAA5wEAADkBAABsBQAAUwAAAGwFAAA5AQAAWgIAAHwAAABrBgAAAwAAALACAABTAAAA5wEAAAUAAABsBQAAmwEAAOcBAAA5AQAAugAAAFMAAADnAQAAOQEAALACAABTAAAAAwcAAHwAAAC4BgAAfAAAAG0AAAB8AAAAgwYAAHwAAACqBQAAfAAAALACAAAeAgAAqgUAAHwAAAC4BgAABwAAAKoFAAB8AAAAgwYAAHwAAAC4BgAAfAAAALgBAAAuAgAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAiwMAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAgQYAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAgQYAAGwFAABTAAAAsAIAAAUAAACDBgAAPQMAALACAACLAwAAgwYAAAcAAACwAgAAgQYAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAgQYAALoAAAAHAAAAbAUAADkBAABsBQAAUwAAAOcBAAADAAAAbAUAAFMAAADnAQAASwAAALoAAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADaAgAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAALgBAADnAQAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAALgBAADnAQAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAALgBAADnAQAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAANoCAADBAwAAbAUAALgBAADnAQAAwQMAAIMGAAA9AwAA2gIAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAOcBAADEBAAAkwIAAGsGAADiAQAAlwQAAFIGAABsBQAAUwAAANoCAABLAAAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAmwEAAGsGAABLAAAAsgQAAJgDAABSBgAAzwQAAAMHAAAHAAAAgAAAAM8EAAC4BgAAcQQAAIAAAADPBAAAAwcAAB4CAABSBgAATgIAALgBAAAuAgAAgQYAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAA+AEAALgBAABqBgAAgAAAAM8EAAADBwAAHgIAAFIGAABOAgAASwAAAG0AAACwAgAA/QAAALACAADaAgAAWgIAAM8AAADiAAAAfAAAAHEEAADEBAAAUgYAANoCAAADAAAA/QAAALACAADaAgAAAwAAAJMCAABaAgAAUgYAAGoGAAA9AwAAbAUAAK0BAACXBAAAUwAAAHEEAABtAAAAcQQAAIEGAABrBgAAuAEAAOcBAAA5AQAAAwYAAC4CAABqBgAAOQEAALIEAAADAAAAaAUAAAQAAAC4AQAALgIAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA5wEAAAUAAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA5wEAAIEGAABsBQAAUwAAAOcBAAA5AQAAbAUAAD0DAADnAQAAmAMAALgGAABTAAAAawYAAIEGAABsBQAAUwAAAOcBAAAFAAAAbAUAAFMAAADnAQAA+AEAAGwFAABTAAAA5wEAAIEGAABaAgAAmAMAALgGAAB8AAAAgwYAAAcAAAC4BgAATwAAAIMGAAB8AAAAgwYAAIEGAACDBgAAfAAAALgGAACAAAAAgwYAAHwAAAC4BgAATwAAALgGAAB8AAAAgwYAAEsAAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAA4gAAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAAC4AQAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAAC4AQAA5wEAADkBAABsBQAALgIAAG0AAAAuAgAAbAUAAC4CAAADBwAAaAUAAIMGAABPAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAAC4AQAA5wEAAGsBAACDBgAAPQMAAOcBAAA5AQAAbAUAAFMAAABrBgAAOQEAAGwFAADnAQAAxAQAAPgBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAACbAQAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAALACAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAALACAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAALACAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAA5AQAAbAUAAJsBAACwAgAAOQEAALACAABTAAAAqgUAAC4CAABsBQAAmwEAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAALgBAABPAAAA4gEAAFMAAABxBAAAbQAAAHEEAAA5AQAAbAUAAIEGAADEBAAAOQEAAGwFAABTAAAA5wEAADkBAABsBQAAUwAAAOcBAAAFAAAAWgIAAOcBAAD9AAAAnQYAALgGAAAHAAAAawEAAOIBAAAQBgAABwAAAGsBAACAAAAArQEAAAcAAABrAQAAAwAAALgGAAAHAAAAOQEAAEsAAAC6AAAAUwAAAOcBAAA5AQAAbAUAAFMAAADnAQAAOQEAAGwFAABTAAAAgQYAAEsAAAA=");
        
        HANDLE hFile = CreateFileW(L"D:\\license.key", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
        if (INVALID_HANDLE_VALUE == hFile)
            DebugBreak();

        DWORD numberOfBytesWrite = 0;
        BOOL b = ::WriteFile(hFile, license.c_str(), license.size(), &numberOfBytesWrite, nullptr);
        ::CloseHandle(hFile);
#endif
        OutputDebugStringA("licenseCheck\n");
        verify->timerFire();
    }
#endif
}

mbWebView MB_CALL_TYPE mbCreateWebWindow(mbWindowType type, HWND parent, int x, int y, int width, int height)
{
    checkThreadCallIsValid(__FUNCTION__);

    licenseCheck();

    mb::MbWebView* result = new mb::MbWebView();
    result->createWkeWebWindowInUiThread(type, parent, x, y, width, height);
    common::ThreadCall::callBlinkThreadAsync([result] {
        result->createWkeWebWindowOrViewInBlinkThread(true);
    });

    return result;
}

mbWebView MB_CALL_TYPE mbCreateWebCustomWindow(HWND parent, DWORD style, DWORD styleEx, int x, int y, int width, int height)
{
    checkThreadCallIsValid(__FUNCTION__);

    licenseCheck();

    mb::MbWebView* result = new mb::MbWebView();
    result->createWkeWebWindowImplInUiThread(parent, style, styleEx, x, y, width, height);
    common::ThreadCall::callBlinkThreadAsync([result] {
        result->createWkeWebWindowOrViewInBlinkThread(true);
    });

    return result;
}

void MB_CALL_TYPE mbDestroyWebView(mbWebView webview)
{
    webview->preDestroy();

    if (webview->m_destroyCallback)
        webview->m_destroyCallback(webview, webview->m_destroyCallbackParam, nullptr);

    common::ThreadCall::callBlinkThreadAsync([webview] {
        delete webview;
    });
}

void MB_CALL_TYPE mbMoveToCenter(mbWebView webview)
{
    int width = 0;
    int height = 0;

    HWND hWnd = webview->getHostWnd();

    RECT rect = { 0 };
    ::GetWindowRect(hWnd, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;

    int parentWidth = 0;
    int parentHeight = 0;
    if (WS_CHILD == ::GetWindowLong(hWnd, GWL_STYLE)) {
        HWND parent = ::GetParent(hWnd);
        RECT rect = { 0 };
        ::GetClientRect(parent, &rect);
        parentWidth = rect.right - rect.left;
        parentHeight = rect.bottom - rect.top;
    } else {
        parentWidth = ::GetSystemMetrics(SM_CXSCREEN);
        parentHeight = ::GetSystemMetrics(SM_CYSCREEN);
    }

    int x = (parentWidth - width) / 2;
    int y = (parentHeight - height) / 2;

    ::MoveWindow(hWnd, x, y, width, height, FALSE);
}

void MB_CALL_TYPE mbSetMouseEnabled(mbWebView webView, bool b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetMouseEnabled(webView->getWkeWebView(), !!b);
    });
}

void MB_CALL_TYPE mbSetTouchEnabled(mbWebView webView, bool b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetTouchEnabled(webView->getWkeWebView(), !!b);
    });
}

void MB_CALL_TYPE mbSetContextMenuEnabled(mbWebView webView, bool b)
{
#if ENABLE_IN_MB_MAIN
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetContextMenuEnabled(webView->getWkeWebView(), !!b);
    });
#endif
}

void MB_CALL_TYPE mbSetNavigationToNewWindowEnable(mbWebView webView, BOOL b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetNavigationToNewWindowEnable(webView->getWkeWebView(), !!b);
    });
}

void MB_CALL_TYPE mbSetHeadlessEnabled(mbWebView webView, BOOL b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetHeadlessEnabled(webView->getWkeWebView(), !!b);
    });
}

void MB_CALL_TYPE mbSetDragDropEnable(mbWebView webView, BOOL b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetDragDropEnable(webView->getWkeWebView(), !!b);
    });
}

void MB_CALL_TYPE mbSetContextMenuItemShow(mbWebView webView, mbMenuItemId item, BOOL isShow)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, item, isShow] {
        wkeSetContextMenuItemShow(webView->getWkeWebView(), (wkeMenuItemId)item, !!isShow);
    });
}

void MB_CALL_TYPE mbSetDragEnable(mbWebView webView, BOOL b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetDragEnable(webView->getWkeWebView(), !!b);
    });
}

const utf8* MB_CALL_TYPE mbGetTitle(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
	return webView->getTitle().c_str();
}

const utf8* MB_CALL_TYPE mbGetUrl(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
	return webView->getUrl().c_str();
}

static void canGoForwardOrBack(mbWebView webView, mbCanGoBackForwardCallback callback, void* param, BOOL isGoForward)
{
    if (!callback)
        return;

    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id) {
        callback(nullptr, param, kMbAsynRequestStateFail, false);
        return;
    }
    common::LiveIdDetect::get()->unlock(id, webView);

    common::ThreadCall::callBlinkThreadAsync([webView, callback, param, isGoForward] {
        bool b = false;
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 != id) {
            b = isGoForward ? wkeCanGoForward(webView->getWkeWebView()) : wkeCanGoBack(webView->getWkeWebView());
            common::LiveIdDetect::get()->unlock(id, webView);
        }

        common::ThreadCall::callUiThreadAsync([webView, callback, param, b] {
            int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
            if (-1 == id) {
                callback(nullptr, param, kMbAsynRequestStateFail, false);
                return;
            }
            callback(webView, param, kMbAsynRequestStateOk, b);
            common::LiveIdDetect::get()->unlock(id, webView);
        });
    });
}

void MB_CALL_TYPE mbCanGoForward(mbWebView webView, mbCanGoBackForwardCallback callback, void* param)
{
    //checkThreadCallIsValid(__FUNCTION__);
    canGoForwardOrBack(webView, callback, param, TRUE);
}

void MB_CALL_TYPE mbCanGoBack(mbWebView webView, mbCanGoBackForwardCallback callback, void* param)
{
    //checkThreadCallIsValid(__FUNCTION__);
    canGoForwardOrBack(webView, callback, param, FALSE);
}

void MB_CALL_TYPE mbGetCookie(mbWebView webView, mbGetCookieCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    if (!callback)
        return;

    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id) {
        callback(nullptr, param, kMbAsynRequestStateFail, nullptr);
        return;
    }
    common::LiveIdDetect::get()->unlock(id, nullptr);

    common::ThreadCall::callBlinkThreadAsync([webView, callback, param] {
        std::string* cookie = nullptr;
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 != id) {
            cookie = new std::string(wkeGetCookie(webView->getWkeWebView()));
            common::LiveIdDetect::get()->unlock(id, webView);
        } else
            cookie = new std::string("");
                
        common::ThreadCall::callUiThreadAsync([webView, id, callback, param, cookie] {
            int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
            if (-1 == id) {
                callback(nullptr, param, kMbAsynRequestStateFail, nullptr);
                delete cookie;
                return;
            }
            callback(webView, param, kMbAsynRequestStateOk, cookie->c_str());
            common::LiveIdDetect::get()->unlock(id, webView);
            delete cookie;
        });
    });
}

const utf8* MB_CALL_TYPE mbGetCookieOnBlinkThread(mbWebView webView)
{
    checkThreadCallIsValidImpl(__FUNCTION__, true);
    return wkeGetCookie(webView->getWkeWebView());
}

void MB_CALL_TYPE mbClearCookie(mbWebView webView)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeClearCookie(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbSetHandle(mbWebView webView, HWND wnd)
{
    checkThreadCallIsValid(__FUNCTION__);
    
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, wnd] {
        webView->setHostWnd(wnd); // 必须在这设置，不能放闭包外。那样会导致提前设置的mbSetDragDropEnable无效，从而导致RegisterDragDrop被设置
        wkeSetHandle(webView->getWkeWebView(), wnd);
    });
}

HWND MB_CALL_TYPE mbGetHostHWND(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    return webView->getHostWnd();
}

void MB_CALL_TYPE mbSetHandleOffset(mbWebView webView, int x, int y)
{
    checkThreadCallIsValid(__FUNCTION__);

    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;
    webView->setOffset(x, y);
    common::LiveIdDetect::get()->unlock(id, nullptr);

    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, x, y] {
        wkeSetHandleOffset(webView->getWkeWebView(), x, y);
    });
}

void MB_CALL_TYPE mbSetCspCheckEnable(mbWebView webView, BOOL b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetCspCheckEnable(webView->getWkeWebView(), !!b);
    });
}

void MB_CALL_TYPE mbSetNpapiPluginsEnabled(mbWebView webView, BOOL b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetNpapiPluginsEnabled(webView->getWkeWebView(), !!b);
    });
}

void MB_CALL_TYPE mbSetMemoryCacheEnable(mbWebView webView, BOOL b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetMemoryCacheEnable(webView->getWkeWebView(), !!b);
    });
}

void MB_CALL_TYPE mbSetResourceGc(mbWebView webView, int intervalSec)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, intervalSec] {
        wkeSetResourceGc(webView->getWkeWebView(), intervalSec);
    });
}

void MB_CALL_TYPE mbSetCookie(mbWebView webView, const utf8* url, const utf8* cookie)
{
    //checkThreadCallIsValid(__FUNCTION__);

    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;

    std::string* urlString = new std::string(url);
    std::string* cookieString = new std::string(cookie);
    common::LiveIdDetect::get()->unlock(id, webView);

    common::ThreadCall::callBlinkThreadAsync([webView, id, urlString, cookieString] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 != id) {
            wkeSetCookie(webView->getWkeWebView(), urlString->c_str(), cookieString->c_str());
            common::LiveIdDetect::get()->unlock(id, webView);
        }
        
        OutputDebugStringA("mbSetCookie:");
        OutputDebugStringA(cookieString->c_str());
        OutputDebugStringA("\n");
        delete urlString;
        delete cookieString;
    });
}

void MB_CALL_TYPE mbSetCookieEnabled(mbWebView webView, BOOL b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, b] {
        wkeSetCookieEnabled(webView->getWkeWebView(), !!b);
    });
}

static void setCookieJarFullPathImpl(mbWebView webView, std::wstring* pathString)
{
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 != id) {
        std::string pathUtf8 = common::utf16ToUtf8(pathString->c_str());
        wkeSetDebugConfig(webView->getWkeWebView(), "setCookieJarFullPath", pathUtf8.c_str());
        common::LiveIdDetect::get()->unlock(id, webView);
    } else if (!webView) {
        wkeSetCookieJarFullPath(nullptr, pathString->c_str());
    }
    delete pathString;
}

// 此api如果在blink线程被调用，必须立刻执行。否则会产生老cookie路径文件
void MB_CALL_TYPE mbSetCookieJarFullPath(mbWebView webView, const WCHAR* path)
{
    //checkThreadCallIsValid(__FUNCTION__);
    if (!path)
        return;
    std::wstring* pathString = new std::wstring(path);
    if (0 == pathString->size()) {
        delete pathString;
        return;
    }
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id) {
        delete pathString;
        return;
    }
    common::LiveIdDetect::get()->unlock(id, webView);

    if (common::ThreadCall::isBlinkThread()) {
        setCookieJarFullPathImpl(webView, pathString);
    } else {
        common::ThreadCall::callBlinkThreadAsync([webView, pathString] {
            setCookieJarFullPathImpl(webView, pathString);
        });
    }
}

void MB_CALL_TYPE mbSetCookieJarPath(mbWebView webView, const WCHAR* path)
{
    if (!path)
        return;
    std::wstring pathString(path);
    if (0 == pathString.size())
        return;
    if (L'\\' != pathString[pathString.size() - 1])
        pathString += L'\\';
    pathString += L"cookies.dat";
    mbSetCookieJarFullPath(webView, pathString.c_str());
}

static void setLocalStorageFullPathImpl(mbWebView webView, std::wstring* pathString)
{
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 != id) {
        std::string pathUtf8 = common::utf16ToUtf8(pathString->c_str());
        wkeSetDebugConfig(webView->getWkeWebView(), "setLocalStorageFullPath", pathUtf8.c_str());
        common::LiveIdDetect::get()->unlock(id, webView);
    } else if (!webView) {
        wkeSetLocalStorageFullPath(nullptr, pathString->c_str());
    }
    delete pathString;
}

void MB_CALL_TYPE mbSetLocalStorageFullPath(mbWebView webView, const WCHAR* path)
{
    //checkThreadCallIsValid(__FUNCTION__);
    if (!path)
        return;
    std::wstring* pathString = new std::wstring(path);
    if (0 == pathString->size()) {
        delete pathString;
        return;
    }
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id) {
        delete pathString;
        return;
    }
    common::LiveIdDetect::get()->unlock(id, webView);

    if (common::ThreadCall::isBlinkThread()) {
        setLocalStorageFullPathImpl(webView, pathString);
    } else {
        common::ThreadCall::callBlinkThreadAsync([webView, pathString] {
            setLocalStorageFullPathImpl(webView, pathString);
        });
    }
}

void MB_CALL_TYPE mbSetDiskCacheEnabled(mbWebView webView, BOOL enable)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsync([enable] {
        wkeSetDebugConfig(nullptr, "diskCache", (enable ? "1" : "0"));
    });
}

void MB_CALL_TYPE mbAddPluginDirectory(mbWebView webView, const WCHAR* path)
{
    //checkThreadCallIsValid(__FUNCTION__);
    std::wstring* pathString = new std::wstring(path);
    common::setPluginDirectory(*pathString);

    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, pathString] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 != id) {
            wkeAddPluginDirectory(webView->getWkeWebView(), pathString->c_str());
            common::LiveIdDetect::get()->unlock(id, webView);
        }
        delete pathString;
    });
}

void MB_CALL_TYPE mbSetUserAgent(mbWebView webView, const utf8* userAgent)
{
    std::string* userAgentString = new std::string(userAgent);

    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, userAgentString] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 == id) {
            wkeSetUserAgent(webView->getWkeWebView(), userAgentString->c_str()); 
            common::LiveIdDetect::get()->unlock(id, webView);
        }
        delete userAgentString;
    });
}

void MB_CALL_TYPE mbSetZoomFactor(mbWebView webView, float factor)
{
    //checkThreadCallIsValid(__FUNCTION__);
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;
    webView->setZoomFactor(factor);
    common::LiveIdDetect::get()->unlock(id, webView);

    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [id, webView, factor] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 == id)
            return;
        wkeSetZoomFactor(webView->getWkeWebView(), factor);
        common::LiveIdDetect::get()->unlock(id, webView);
    });
}

float MB_CALL_TYPE mbGetZoomFactor(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    return webView->getZoomFactor();
}

void MB_CALL_TYPE mbSetDebugConfig(mbWebView webView, const char* debug, const char* param)
{
    //checkThreadCallIsValid(__FUNCTION__);
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;

    std::string* debugString = new std::string(debug);
    std::string* paramString = new std::string(param);
   
    common::LiveIdDetect::get()->unlock(id, webView);

    common::ThreadCall::callBlinkThreadAsync([webView, debugString, paramString] {
        if (!webView)
            wkeSetDebugConfig(nullptr, debugString->c_str(), paramString->c_str());
        else {
            int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
            if (-1 != id) {
                wkeSetDebugConfig(webView->getWkeWebView(), debugString->c_str(), paramString->c_str());
                common::LiveIdDetect::get()->unlock(id, webView);
            }
        }        
        delete debugString;
        delete paramString;
    });
}

void MB_CALL_TYPE mbSetProxy(mbWebView webView, const mbProxy* proxy)
{
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;

    mbProxy* proxyCopy = new mbProxy();
    memcpy(proxyCopy, proxy, sizeof(mbProxy));
    common::LiveIdDetect::get()->unlock(id, webView);

    common::ThreadCall::callBlinkThreadAsync([webView, proxyCopy] {
		if (!webView)
			wkeSetProxy((const wkeProxy*)proxyCopy);
        else {
            int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
            if (-1 != id) {
                wkeSetViewProxy(webView->getWkeWebView(), (wkeProxy*)proxyCopy);
                common::LiveIdDetect::get()->unlock(id, webView);
            }
        }
        delete proxyCopy;
    });
}

void MB_CALL_TYPE mbResize(mbWebView webView, int w, int h)
{
    checkThreadCallIsValid(__FUNCTION__);
    webView->onResize(w, h, true);
}

static bool WKE_CALL_TYPE onNavigation(wkeWebView wkeWebview, void* param, wkeNavigationType navigationType, const wkeString url)
{
    const utf8* urlString = wkeGetString(url);
    BOOL result = true;
    mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return false;

    result = webView->getClosure().m_NavigationCallback(webView, webView->getClosure().m_NavigationParam, (mbNavigationType)navigationType, urlString);
    common::LiveIdDetect::get()->unlock(id, webView);

    return !!result;
}

static bool WKE_CALL_TYPE onNavigationSync(wkeWebView wkeWebview, void* param, wkeNavigationType navigationType, const wkeString url)
{
    mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return false;

    const utf8* urlString = wkeGetString(url);
    BOOL result = true;

    common::LiveIdDetect::get()->unlock(id, webView);

    common::ThreadCall::callUiThreadSync([&result, id, webView, navigationType, urlString] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 == id) {
            result = FALSE;
            return;
        }
        result = webView->getClosure().m_NavigationCallback(webView, webView->getClosure().m_NavigationParam, (mbNavigationType)navigationType, urlString);
        common::LiveIdDetect::get()->unlock(id, webView);
    });

    return !!result;
}

static mbWebFrameHandle toMbFrameHandle(wkeWebView wkeWebview, wkeWebFrameHandle frameId)
{
    if (wkeIsMainFrame(wkeWebview, frameId))
        return (mbWebFrameHandle)-2;
    return (wkeWebFrameHandle)frameId;
}

static void WKE_CALL_TYPE onDocumentReady(wkeWebView wkeWebview, void* param, wkeWebFrameHandle frameId)
{
    mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;
    
    mbWebFrameHandle mbFrameId = toMbFrameHandle(wkeWebview, frameId);
    common::LiveIdDetect::get()->unlock(id, webView);

    common::ThreadCall::callUiThreadAsync([webView, mbFrameId] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 == id)
            return;
        webView->getClosure().m_DocumentReadyCallback(webView, webView->getClosure().m_DocumentReadyParam, mbFrameId);
        common::LiveIdDetect::get()->unlock(id, webView);
    });
}

void MB_CALL_TYPE mbOnPaintUpdated(mbWebView webView, mbPaintUpdatedCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    webView->setPaintUpdatedCallback(callback, param);
}

HDC MB_CALL_TYPE mbGetLockedViewDC(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    return webView->getViewDC();
}

void MB_CALL_TYPE mbUnlockViewDC(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    webView->unlockViewDC();
}

void MB_CALL_TYPE mbOnCreateView(mbWebView webView, mbCreateViewCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    webView->getClosure().setCreateViewCallback(callback, param);
}

struct DownloadWrap {
    std::string url;
    std::string mime;
    std::string contentDisposition;
    blinkWebURLRequestPtr blinkRequest;

    ~DownloadWrap()
    {

    }
};

BOOL MB_CALL_TYPE mbPopupDownloadMgr(mbWebView webView, const char* url, void* downloadWrap)
{
#if ENABLE_IN_MB_MAIN    
    static DownloadMgr* downloadUi = nullptr;
    if (!downloadUi)
        downloadUi = new DownloadMgr();

    if (downloadWrap) {
        DownloadWrap* job = (DownloadWrap*)downloadWrap;
        downloadUi->onNewDownloadItem(job->url.c_str(), job->mime.c_str(), job->contentDisposition.c_str());
    } else
        downloadUi->createWnd();
#endif
    return TRUE;
}

mbDownloadOpt MB_CALL_TYPE mbPopupDialogAndDownload(mbWebView webView,
    void* param,
    size_t expectedContentLength,
    const char* url,
    const char* mime,
    const char* disposition,
    mbNetJob job,
    mbNetJobDataBind* dataBind,
    mbDownloadBind* callbackBind)
{
#if ENABLE_IN_MB_MAIN
    return DownloadMgr::simpleDownload(webView, nullptr, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);
#endif
    return kMbDownloadOptCancel;
}

mbDownloadOpt MB_CALL_TYPE mbDownloadByPath(mbWebView webView,
    void* param,
    const WCHAR* path,
    size_t expectedContentLength,
    const char* url,
    const char* mime,
    const char* disposition,
    mbNetJob job,
    mbNetJobDataBind* dataBind,
    mbDownloadBind* callbackBind)
{
#if ENABLE_IN_MB_MAIN
    return DownloadMgr::simpleDownload(webView, path, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);
#endif
    return kMbDownloadOptCancel;
}

void WKE_CALL_TYPE wkeNetJobDataRecvWrap(void* ptr, wkeNetJob job, const char* data, int length)
{
    mbNetJobDataBind* bindWrap = (mbNetJobDataBind*)ptr;
    bindWrap->recvCallback(bindWrap->param, job, data, length);
}

void WKE_CALL_TYPE wkeNetJobDataFinishWrap(void* ptr, wkeNetJob job, wkeLoadingResult result)
{
    mbNetJobDataBind* bindWrap = (mbNetJobDataBind*)ptr;
    bindWrap->finishCallback(bindWrap->param, job, (mbLoadingResult)result);
    delete bindWrap;
}

static wkeDownloadOpt WKE_CALL_TYPE onDownloadInBlinkThread(wkeWebView wkeWebview, void* param, size_t expectedContentLength, const char* url, const char* mime, const char* disposition, wkeNetJob job, wkeNetJobDataBind* dataBind)
{
    mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return kWkeDownloadOptCancel;
    common::LiveIdDetect::get()->unlock(id, webView);

    mbNetJobDataBind* bindWrap = new mbNetJobDataBind();
    dataBind->param = nullptr;
    dataBind->recvCallback = nullptr;
    dataBind->finishCallback = nullptr;

    wkeDownloadOpt opt = (wkeDownloadOpt)webView->getClosure().m_DownloadInBlinkThreadCallback(webView,
        webView->getClosure().m_DownloadInBlinkThreadParam,
        expectedContentLength,
        url, mime, disposition, (mbNetJob)job, bindWrap);

    if (bindWrap->param) {
        dataBind->param = bindWrap;
        dataBind->recvCallback = wkeNetJobDataRecvWrap;
        dataBind->finishCallback = wkeNetJobDataFinishWrap;
    }

    return opt;
}

static bool WKE_CALL_TYPE onDownload(wkeWebView wkeWebview, void* param, const char* url)
{
    mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return false;
    common::LiveIdDetect::get()->unlock(id, webView);

    wkeTempCallbackInfo* temInfo = wkeGetTempCallbackInfo(wkeWebview);
    if (temInfo->size != sizeof(wkeTempCallbackInfo))
        return false;

    mbWebFrameHandle mbFrameId = toMbFrameHandle(wkeWebview, temInfo->frame);
    const char* mime = wkeNetGetMIMEType(temInfo->job, nullptr);
    const char* contentDisposition = wkeNetGetHTTPHeaderFieldFromResponse(temInfo->job, "Content-Disposition");

    DownloadWrap* downloadWrap = new DownloadWrap();
    downloadWrap->url = url;
    downloadWrap->mime = mime;
    downloadWrap->contentDisposition = contentDisposition;
    downloadWrap->blinkRequest = wkeNetCopyWebUrlRequest(temInfo->job, false);

    common::ThreadCall::callUiThreadAsync([webView, mbFrameId, downloadWrap] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 == id) {
            delete downloadWrap;
            return;
        }
        common::LiveIdDetect::get()->unlock(id, webView);
        webView->getClosure().m_DownloadCallback(webView, webView->getClosure().m_DownloadParam, mbFrameId, downloadWrap->url.c_str(), downloadWrap);
        delete downloadWrap;
    });

    return false;
}

static void WKE_CALL_TYPE onAlertBox(wkeWebView wkeWebview, void* param, const wkeString msg)
{
    mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;
    common::LiveIdDetect::get()->unlock(id, webView);
    webView->getClosure().m_AlertBoxCallback(webView, webView->getClosure().m_AlertBoxParam, wkeGetString(msg));
}

static bool WKE_CALL_TYPE onConfirmBox(wkeWebView wkeWebview, void* param, const wkeString msg)
{
    mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return false;
    common::LiveIdDetect::get()->unlock(id, webView);
    BOOL result = webView->getClosure().m_ConfirmBoxCallback(webView, webView->getClosure().m_ConfirmBoxParam, wkeGetString(msg));
    return !!result;
}

static void WKE_CALL_TYPE onConsole(wkeWebView wkeWebview, void* param, wkeConsoleLevel level, const wkeString message, const wkeString sourceName, unsigned sourceLine, const wkeString stackTrace)
{
    mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;
    common::LiveIdDetect::get()->unlock(id, webView);

    webView->getClosure().m_ConsoleCallback(webView, webView->getClosure().m_ConsoleParam, 
        (mbConsoleLevel)level, wkeGetString(message), wkeGetString(sourceName), sourceLine, wkeGetString(stackTrace));
}

static void WKE_CALL_TYPE onNetGetFavicon(wkeWebView wkeWebview, void* param, const utf8* url, wkeMemBuf* buf)
{
    mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;
    common::LiveIdDetect::get()->unlock(id, webView);

    std::string* urlString = new std::string(url ? url : "");

    wkeMemBuf* bufCopy = nullptr;
    if (buf && 0 != buf->length)
        bufCopy = wkeCreateMemBuf(wkeWebview, buf->data, buf->length);

    common::ThreadCall::callUiThreadAsync([id, webView, urlString, bufCopy] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 == id) {
            delete urlString;
            wkeFreeMemBuf(bufCopy);
            return;
        }
        common::LiveIdDetect::get()->unlock(id, webView);

        webView->getClosure().m_NetGetFaviconCallback(webView, webView->getClosure().m_NetGetFaviconParam, urlString->c_str(), (mbMemBuf*)(bufCopy));
        delete urlString;
        wkeFreeMemBuf(bufCopy);
    });
}

bool WKE_CALL_TYPE onWindowClosingCallback(wkeWebView webWindow, void* param)
{
	BOOL result = true;
	mbWebView webView = (mbWebView)param;
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return true;
    common::LiveIdDetect::get()->unlock(id, webView);

	common::ThreadCall::callUiThreadSync([&result, id, webView] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
		if (-1 == id)
			return;
        common::LiveIdDetect::get()->unlock(id, webView);

		result = webView->getClosure().m_ClosingCallback(webView, webView->getClosure().m_ClosingParam, nullptr);
	});

	return !!result;
}

#include "core/MbCallback.h"

// BOOL MB_CALL_TYPE mbOnClose(mbWebView webView, mbCloseCallback callback, void* param)
// {
// 	webView->m_closeCallback = callback;
// 	webView->m_closeCallbackParam = param;
// 	return TRUE;
// }

BOOL MB_CALL_TYPE mbOnDestroy(mbWebView webView, mbDestroyCallback callback, void* param)
{
    webView->m_destroyCallback = callback;
    webView->m_destroyCallbackParam = param;
    return TRUE;
}

BOOL MB_CALL_TYPE mbOnPrinting(mbWebView webView, mbPrintingCallback callback, void* param)
{
    webView->m_printingCallback = callback;
    webView->m_printingCallbackParam = param;
    return TRUE;
}

void MB_CALL_TYPE mbWake(mbWebView webView)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::wake();
}

void MB_CALL_TYPE mbGoBack(mbWebView webView)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeGoBack(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbGoForward(mbWebView webView)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeGoForward(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbStopLoading(mbWebView webView)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeStopLoading(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbReload(mbWebView webView)
{
    //checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeReload(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbPerformCookieCommand(mbWebView webView, mbCookieCommand command)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, command] {
        wkePerformCookieCommand(webView->getWkeWebView(), (wkeCookieCommand)command);
    });
}

void MB_CALL_TYPE mbEditorSelectAll(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeSelectAll(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbEditorCopy(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeCopy(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbEditorCut(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeCut(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbEditorPaste(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkePaste(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbEditorDelete(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeEditorDelete(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbEditorUndo(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeEditorUndo(webView->getWkeWebView());
    });
}

BOOL MB_CALL_TYPE mbFireMouseEvent(mbWebView webView, unsigned int message, int x, int y, unsigned int flags)
{
    checkThreadCallIsValid(__FUNCTION__);
    webView->onMouseMessage(message, x, y, flags);
   
    return true;
}

BOOL MB_CALL_TYPE mbFireContextMenuEvent(mbWebView webView, int x, int y, unsigned int flags)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, x, y, flags] {
        wkeFireContextMenuEvent(webView->getWkeWebView(), x, y, flags);
    });

    return true;
}

BOOL MB_CALL_TYPE mbFireMouseWheelEvent(mbWebView webView, int x, int y, int delta, unsigned int flags)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, x, y, delta, flags] {
        wkeFireMouseWheelEvent(webView->getWkeWebView(), x, y, delta, flags);
    });

    return true;
}

BOOL MB_CALL_TYPE mbFireKeyUpEvent(mbWebView webView, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, virtualKeyCode, flags, isSystemKey] {
        wkeFireKeyUpEvent(webView->getWkeWebView(), virtualKeyCode, flags, !!isSystemKey);
    });

    return true;
}

BOOL MB_CALL_TYPE mbFireKeyDownEvent(mbWebView webView, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, virtualKeyCode, flags, isSystemKey] {
        wkeFireKeyDownEvent(webView->getWkeWebView(), virtualKeyCode, flags, !!isSystemKey);

//         if (113 == virtualKeyCode) {
//             wkeSetDebugConfig(webView->getWkeWebView(), "showDevTools", "E:/mycode/miniblink49/trunk/third_party/WebKit/Source/devtools/front_end/inspector.html");
//         }

//         char* output = (char*)malloc(0x100);
//         sprintf(output, "mbFireKeyDownEvent: %d\n", virtualKeyCode);
//         OutputDebugStringA(output);
//         free(output);
    });

    return true;
}

BOOL MB_CALL_TYPE mbFireKeyPressEvent(mbWebView webView, unsigned int charCode, unsigned int flags, BOOL isSystemKey)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, charCode, flags, isSystemKey] {
        wkeFireKeyPressEvent(webView->getWkeWebView(), charCode, flags, !!isSystemKey);
    });

    return true;
}

BOOL MB_CALL_TYPE mbFireWindowsMessage(mbWebView webView, HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result)
{
    checkThreadCallIsValid(__FUNCTION__);

    if (WM_SETCURSOR == message) {
        if (webView->setCursorInfoTypeByCache()) {
            if (result)
                *result = 1;
            return true;
        }
    } else if (WM_IME_STARTCOMPOSITION) {
        common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, hWnd] {
            int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
            if (-1 == id)
                return;
            common::LiveIdDetect::get()->unlock(id, webView);

            wkeRect caret = wkeGetCaretRect(webView->getWkeWebView());

            POINT offset = webView->getOffset();
            int x = caret.x + offset.x;
            int y = caret.y + offset.y;

            common::ThreadCall::callUiThreadAsync([hWnd, webView, x, y] {
                int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
                if (-1 == id)
                    return;
                common::LiveIdDetect::get()->unlock(id, webView);

                COMPOSITIONFORM compositionForm;
                compositionForm.dwStyle = CFS_POINT | CFS_FORCE_POSITION;
                compositionForm.ptCurrentPos.x = x;
                compositionForm.ptCurrentPos.y = y;

                HIMC hIMC = ::ImmGetContext(hWnd);
                ::ImmSetCompositionWindow(hIMC, &compositionForm);
                ::ImmReleaseContext(hWnd, hIMC);
            });
        });
        return true;
    } else {
        common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, hWnd, message, wParam, lParam] {
            LRESULT result = 0;
            wkeFireWindowsMessage(webView->getWkeWebView(), hWnd, message, wParam, lParam, &result);
        });
    }
    return false;
}

void MB_CALL_TYPE mbSetFocus(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeSetFocus(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbKillFocus(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView] {
        wkeKillFocus(webView->getWkeWebView());
    });
}

void MB_CALL_TYPE mbShowWindow(mbWebView webView, BOOL b)
{
    checkThreadCallIsValid(__FUNCTION__);
    webView->setShow(!!b);
}


//////////////////////////////////////////////////////////////////////////
// void readFile(const wchar_t* path, std::vector<char>* buffer)
// {
//     HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//     if (INVALID_HANDLE_VALUE == hFile) {
// 
//         std::vector<WCHAR> filenameBuffer;
//         filenameBuffer.resize(MAX_PATH + 3);
//         ::GetModuleFileNameW(NULL, filenameBuffer.data(), MAX_PATH);
//         ::PathRemoveFileSpecW(filenameBuffer.data());
// 
//         ::PathAppendW(filenameBuffer.data(), L"mtmb.exp");
//         if (::PathFileExistsW(filenameBuffer.data()))
//             DebugBreak();
//         return;
//     }
// 
//     DWORD fileSizeHigh;
//     const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
// 
//     DWORD numberOfBytesRead = 0;
//     buffer->resize(bufferSize);
//     BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
//     ::CloseHandle(hFile);
//     b = b;
// }
// 
// static bool hookUrl(void* job, const char* url, const char* hookUrl, const wchar_t* localFile, const char* mime)
// {
//     if (0 == strstr(url, hookUrl))
//         return false;
// 
//     //mbNetSetMIMEType(job, (char*)mime);
// 
//     std::vector<char> buffer;
//     readFile(localFile, &buffer);
//     if (0 == buffer.size())
//         return false;
// 
//     mbNetSetData(job, &buffer[0], buffer.size());
// 
//     OutputDebugStringA("hookUrl:");
//     OutputDebugStringA(url);
//     OutputDebugStringA("\n");
// 
//     return true;
// }
// 
// static BOOL MB_CALL_TYPE handleLoadUrlBegin(mbWebView webView, void* param, const char* url, void* job)
// {
//     if (hookUrl(job, url, "ncpc/nc.js", L"F:\\test\\demo\\20190513\\DianTools\\nc.js", "text/javascript"))
//         return true;
// 
//     if (hookUrl(job, url, "uab/117.js", L"F:\\test\\demo\\20190513\\DianTools\\117.js", "text/javascript"))
//         return true;
// 
//     return false;
// }
//////////////////////////////////////////////////////////////////////////

void MB_CALL_TYPE mbLoadURL(mbWebView webView, const utf8* url)
{
    checkThreadCallIsValid(__FUNCTION__);
    std::string* urlString = new std::string(url);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, urlString] {
        wkeLoadURL(webView->getWkeWebView(), urlString->c_str());
        delete urlString;
    });

    //////////////////////////////////////////////////////////////////////////
    //mbOnLoadUrlBegin(webView, handleLoadUrlBegin, nullptr);
    //////////////////////////////////////////////////////////////////////////
}

void MB_CALL_TYPE mbLoadHtmlWithBaseUrl(mbWebView webView, const utf8* html, const utf8* baseUrl)
{
    checkThreadCallIsValid(__FUNCTION__);
    std::string* htmlString = new std::string(html);
    std::string* baseUrlString = new std::string(baseUrl);
    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, htmlString, baseUrlString] {
        wkeLoadHtmlWithBaseUrl(webView->getWkeWebView(), htmlString->c_str(), baseUrlString->c_str());
        delete htmlString;
        delete baseUrlString;
    });
}

mbWebFrameHandle MB_CALL_TYPE mbWebFrameGetMainFrame(mbWebView webView)
{
    return (mbWebFrameHandle)-2;
}

BOOL MB_CALL_TYPE mbIsMainFrame(mbWebView webView, mbWebFrameHandle frameId)
{
    checkThreadCallIsValid(__FUNCTION__);
    bool b = (frameId == (mbWebFrameHandle)-2);
    return b;
}

void MB_CALL_TYPE mbUtilSerializeToMHTML(mbWebView webView, mbGetMHTMLCallback calback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    if (!calback)
        return;

    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, calback, param] {
        const utf8* mhtml = wkeUtilSerializeToMHTML(webView->getWkeWebView());
        calback(webView, param, mhtml);
    });
}

void MB_CALL_TYPE mbGetContentAsMarkup(mbWebView webView, mbGetContentAsMarkupCallback calback, void* param, mbWebFrameHandle frameId)
{
    checkThreadCallIsValid(__FUNCTION__);
    if (!calback)
        return;

    common::ThreadCall::callBlinkThreadAsyncWithValid(webView, [webView, calback, param, frameId] {
        wkeWebFrameHandle wkeFrameId = (wkeWebFrameHandle)frameId;
        if ((mbWebFrameHandle)-2 == frameId)
            wkeFrameId = wkeWebFrameGetMainFrame(webView->getWkeWebView());

        size_t size = 0;
        const utf8* content = wkeGetContentAsMarkup(webView->getWkeWebView(), wkeFrameId, &size);
        std::vector<char>* contentCopy = new std::vector<char>();
        if (size > 0) {
            contentCopy->resize(size);
            memcpy(&contentCopy->at(0), content, size);
        }
        common::ThreadCall::callUiThreadAsync([webView, calback, param, contentCopy, size] {
            int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
            if (-1 != id) {
                common::LiveIdDetect::get()->unlock(id, webView);

                if (size > 0)
                    calback(webView, param, &contentCopy->at(0), size);
                else
                    calback(webView, param, nullptr, 0);
            }
            delete contentCopy;
        });
    });
}

const char* MB_CALL_TYPE mbUtilCreateRequestCode(const char* registerInfo)
{
    if (!registerInfo || 1000 < strlen(registerInfo))
        return nullptr;

#if ENABLE_VERIFY && ENABLE_IN_MB_MAIN
    SqBind* verify = SqBind::getInst();
    std::string* requestCode = new std::string(verify->createRequestCode(registerInfo));

    common::ThreadCall::callBlinkThreadAsync([requestCode] {
        delete requestCode;
    });

    return requestCode->c_str();
#else
    return nullptr;
#endif
}

BOOL MB_CALL_TYPE mbUtilIsRegistered(const wchar_t* defaultPath)
{
#if ENABLE_VERIFY && ENABLE_IN_MB_MAIN
    return SqBind::getInst()->loadLicenseAndVerify(std::wstring(defaultPath));
#else
    return TRUE;
#endif
}

BOOL MB_CALL_TYPE mbUtilPrint(mbWebView webView, mbWebFrameHandle frameId, const mbPrintSettings* settings)
{
#if ENABLE_IN_MB_MAIN
    if (webView->m_printing)
        return FALSE;

    BOOL b = TRUE;
    if (webView->m_printingCallback)
        b = webView->m_printingCallback(webView, webView->m_printingCallbackParam, kPrintintStepStart, nullptr, nullptr, 0);
    if (!b)
        return FALSE;

    webView->m_printing = new printing::Printing(webView, frameId);
    webView->m_printing->run(settings);
#endif
    return TRUE;
}

class MbJsValue {
public:
    MbJsValue()
    {
        m_id = common::LiveIdDetect::get()->constructed(this);
    }

    ~MbJsValue()
    {
        common::LiveIdDetect::get()->deconstructed(m_id);
    }

    static MbJsValue* wkeJsValueToMb(jsExecState es, jsValue v)
    {
        MbJsValue* result = new MbJsValue();
        jsType wkeType = jsTypeOf(v);
        switch (wkeType) {
        case JSTYPE_NUMBER:
            result->m_type = kMbJsTypeNumber;
            result->m_doubleVal = jsToDouble(es, v);
            break;
        case JSTYPE_STRING:
            result->m_type = kMbJsTypeString;
            result->m_strVal = jsToString(es, v);
            break;
        case JSTYPE_BOOLEAN:
            result->m_type = kMbJsTypeBool;
            result->m_boolVal = jsToBoolean(es, v);
            break;
        case JSTYPE_OBJECT:
            result->m_type = kMbJsTypeString;
            result->m_strVal = "[Object]";
            break;
        case JSTYPE_FUNCTION:
            result->m_type = kMbJsTypeString;
            result->m_strVal = "[Function]";
            break;
        case JSTYPE_UNDEFINED:
            result->m_type = kMbJsTypeUndefined;
            break;
        case JSTYPE_ARRAY:
            result->m_type = kMbJsTypeString;
            result->m_strVal = "[Array]";
            break;
        case JSTYPE_NULL:
            result->m_type = kMbJsTypeNull;
            break;
        }
        return result;
    }

    int64_t getId() const { return m_id; }
    mbJsType getType() const { return m_type; }

    double getDoubleVal() const { return m_doubleVal; }
    std::string getStrVal() const { return m_strVal; }
    bool getBoolVal() const { return m_boolVal; }

private:
    int64_t m_id;
    mbJsType m_type;

    double m_doubleVal;
    std::string m_strVal;
    bool m_boolVal;
};

double MB_CALL_TYPE mbJsToDouble(mbJsExecState es, mbJsValue v)
{
    MbJsValue* jsV = (MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return 0;

    double result = 0;
    if (kMbJsTypeNumber == jsV->getType())
        result = jsV->getDoubleVal();
    common::LiveIdDetect::get()->unlock(v, jsV);

    return result;
}

BOOL MB_CALL_TYPE mbJsToBoolean(mbJsExecState es, mbJsValue v)
{
    MbJsValue* jsV = (MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return false;

    bool result = false;
    if (kMbJsTypeBool == jsV->getType())
        result = jsV->getBoolVal();
    common::LiveIdDetect::get()->unlock(v, jsV);

    return result;
}

std::vector<std::vector<char>*>* s_sharedStringBuffers = nullptr;
static const char* createTempCharString(const char* str, size_t length)
{
    if (!str || 0 == length)
        return "";
    std::vector<char>* stringBuffer = new std::vector<char>(length);
    memcpy(&stringBuffer->at(0), str, length * sizeof(char));
    stringBuffer->push_back('\0');

    if (!s_sharedStringBuffers)
        s_sharedStringBuffers = new std::vector<std::vector<char>*>();
    s_sharedStringBuffers->push_back(stringBuffer);
    return &stringBuffer->at(0);
}

template<class T>
static void freeShareds(std::vector<T*>* s_shared)
{
    if (!s_shared)
        return;

    for (size_t i = 0; i < s_shared->size(); ++i) {
        delete s_shared->at(i);
    }
    s_shared->clear();
}

static void freeTempCharStrings()
{
    freeShareds(s_sharedStringBuffers);
}

std::vector<mbJsValue>* s_jsValues;

const utf8* MB_CALL_TYPE mbJsToString(mbJsExecState es, mbJsValue v)
{
    MbJsValue* jsV = (MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return "";

    std::string result;
    if (kMbJsTypeString == jsV->getType())
        result = jsV->getStrVal();
    common::LiveIdDetect::get()->unlock(v, jsV);

    if (0 == result.size())
        return "";

    return createTempCharString(result.c_str(), result.size());
}

void MB_CALL_TYPE mbOnJsQuery(mbWebView webView, mbJsQueryCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);

    std::function<void(mbJsExecState es, int64_t queryId, int customMsg, const utf8* request)>* closure = nullptr;
    closure = new std::function<void(mbJsExecState es, int64_t queryId, int customMsg, const utf8* request)>(
        /*std::move*/([webView, callback, param](mbJsExecState es, int64_t queryId, int customMsg, const utf8* request) {
            return callback(webView, param, es, queryId, customMsg, request);
    }));
    webView->getClosure().setJsQueryClosure(closure);
}

void MB_CALL_TYPE mbResponseQuery(mbWebView webView, int64_t queryId, int customMsg, const utf8* response)
{
    std::string* requestString = new std::string(response ? response: "");
    common::ThreadCall::callBlinkThreadAsync([webView, queryId, customMsg, requestString] {
        std::pair<wkeWebFrameHandle, int>* idInfo = (std::pair<wkeWebFrameHandle, int>*)queryId;
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 == id) {
            delete idInfo;
            delete requestString;
            return;
        }
        common::LiveIdDetect::get()->unlock(id, webView);

//         char queryIdString[30] = { 0 };
//         sprintf(queryIdString, "%d, %d, `", idInfo->second, customMsg);

        wkeWebView wkeWebview = webView->getWkeWebView();
//         std::string injectScript = "window.__onMbQuery__(";
//         injectScript += queryIdString;
//         injectScript += requestString->c_str();
//         injectScript += "`);";
//         wkeRunJsByFrame(wkeWebview, idInfo->first, injectScript.c_str(), false);

        jsExecState es = wkeGetGlobalExecByFrame(wkeWebview, idInfo->first);
        jsValue windowVal = jsGlobalObject(es);
        jsValue jsFunc = jsGet(es, windowVal, "__onMbQuery__");

        jsValue args[3];
        args[0] = jsInt(idInfo->second);
        args[1] = jsInt(customMsg);
        args[2] = jsString(es, requestString->c_str());
        jsCallGlobal(es, jsFunc, args, 3);       

        delete idInfo;
        delete requestString;
    });
}

mbJsValue MB_CALL_TYPE mbRunJsSync(mbWebView webView, mbWebFrameHandle frameId, const utf8* script, BOOL isInClosure)
{
    checkThreadCallIsValid(__FUNCTION__);

//     int64_t id = webView->getId();
//     std::string* scriptString = new std::string(script);
//     MbJsValue* mbVal = nullptr;
//     common::ThreadCall::callBlinkThreadSync([id, webView, frameId, scriptString, isInClosure, &mbVal] {
//         if (!common::LiveIdDetect::get()->isLive(id)) {
//             delete scriptString;
//             return;
//         }
//         wkeWebView wkeWebview = webView->getWkeWebView();
//         wkeWebFrameHandle wkeFrameId = (wkeWebFrameHandle)frameId;
//         if ((mbWebFrameHandle)-2 == frameId)
//             wkeFrameId = wkeWebFrameGetMainFrame(wkeWebview);
//         jsValue ret = wkeRunJsByFrame(wkeWebview, wkeFrameId, scriptString->c_str(), !!isInClosure);
// 
//         jsExecState es = wkeGetGlobalExecByFrame(wkeWebview, wkeFrameId);
//         mbVal = MbJsValue::wkeJsValueToMb(es, ret);
//     });
// 
//     if (!mbVal)
//         return 0;
// 
//     common::ThreadCall::callUiThreadAsync([] {
//         freeTempCharStrings();
//     });
// 
//     return mbVal->getId();

    return 0;
}

static void callRunJsCallback(mbWebView webView, void* param, mbRunJsCallback callback, jsExecState es, MbJsValue* mbVal)
{
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 != id) {
        callback(webView, param, es, mbVal->getId());
        common::LiveIdDetect::get()->unlock(id, webView);
    }
    
    freeTempCharStrings();
    delete mbVal;
}

void runJsOnBlinkThread(mbWebView webView, mbWebFrameHandle frameId, std::string* scriptString, BOOL isInClosure, mbRunJsCallback callback, void* param)
{
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id) {
        delete scriptString;
        return;
    }
    common::LiveIdDetect::get()->unlock(id, webView);

    wkeWebView wkeWebview = webView->getWkeWebView();
    wkeWebFrameHandle wkeFrameId = (wkeWebFrameHandle)frameId;
    if ((mbWebFrameHandle)-2 == frameId)
        wkeFrameId = wkeWebFrameGetMainFrame(wkeWebview);
    jsValue ret = wkeRunJsByFrame(wkeWebview, wkeFrameId, scriptString->c_str(), !!isInClosure);

    jsExecState es = wkeGetGlobalExecByFrame(wkeWebview, wkeFrameId);

    if (callback) {
        MbJsValue* mbVal = MbJsValue::wkeJsValueToMb(es, ret);
        common::ThreadCall::callUiThreadAsync([webView, param, callback, es, mbVal] {
            callRunJsCallback(webView, param, callback, es, mbVal);
        });
    }
    delete scriptString;    
}

void MB_CALL_TYPE mbRunJs(mbWebView webView, mbWebFrameHandle frameId, const utf8* script, BOOL isInClosure, mbRunJsCallback callback, void* param, void* unuse)
{
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;
    common::LiveIdDetect::get()->unlock(id, nullptr);

    std::string* scriptString = new std::string(script);
    if (common::ThreadCall::isBlinkThread())
        runJsOnBlinkThread(webView, frameId, scriptString, isInClosure, callback, param);
    else {
        common::ThreadCall::callBlinkThreadAsync([id, webView, frameId, scriptString, isInClosure, callback, param] {
            runJsOnBlinkThread(webView, frameId, scriptString, isInClosure, callback, param);
        });
    }
}

void MB_CALL_TYPE mbNetHookRequest(mbNetJob jobPtr)
{
    wkeNetHookRequest(jobPtr);
}

const utf8* MB_CALL_TYPE mbNetGetHTTPHeaderField(mbNetJob jobPtr, const char* key, BOOL fromRequestOrResponse)
{
    if (fromRequestOrResponse)
        return wkeNetGetHTTPHeaderField((wkeNetJob)jobPtr, key);
    return wkeNetGetHTTPHeaderFieldFromResponse((wkeNetJob)jobPtr, key);
}

void MB_CALL_TYPE mbNetSetHTTPHeaderField(mbNetJob jobPtr, const wchar_t* key, const wchar_t* value, BOOL response)
{
    wkeNetSetHTTPHeaderField((wkeNetJob)jobPtr, key, value, !!response);
}

void MB_CALL_TYPE mbNetSetData(mbNetJob jobPtr, void* buf, int len)
{
    if (common::ThreadCall::isBlinkThread())
        wkeNetSetData(jobPtr, buf, len);
    else {
        std::vector<char>* bufferCopy = new std::vector<char>();
        bufferCopy->resize(len);
        memcpy(&bufferCopy->at(0), buf, len);
        common::ThreadCall::callBlinkThreadAsync([jobPtr, bufferCopy] {
            wkeNetSetData(jobPtr, &bufferCopy->at(0), bufferCopy->size());
            delete bufferCopy;
        });
    }    
}

void MB_CALL_TYPE mbNetChangeRequestUrl(mbNetJob jobPtr, const char* url)
{
    //wkeNetChangeRequestUrl(jobPtr, url);
    if (common::ThreadCall::isBlinkThread())
        wkeSetDebugConfig((wkeWebView)jobPtr, "changeRequestUrl", url);
    else {
        std::string* urlCopy = new std::string(url);
        common::ThreadCall::callBlinkThreadAsync([jobPtr, urlCopy] {
            wkeSetDebugConfig((wkeWebView)jobPtr, "changeRequestUrl", urlCopy->c_str());
            delete urlCopy;
        });
    }
}

void MB_CALL_TYPE mbNetSetMIMEType(mbNetJob jobPtr, const char* type)
{
    if (common::ThreadCall::isBlinkThread())
        wkeNetSetMIMEType(jobPtr, type);
    else {
        std::string* typeCopy = new std::string(type);
        common::ThreadCall::callBlinkThreadAsync([jobPtr, typeCopy] {
            wkeNetSetMIMEType(jobPtr, typeCopy->c_str());
            delete typeCopy;
        });
    }
}

const char* MB_CALL_TYPE mbNetGetMIMEType(mbNetJob jobPtr)
{
    return wkeNetGetMIMEType((wkeNetJob)jobPtr, nullptr);
}

void MB_CALL_TYPE mbNetContinueJob(mbNetJob jobPtr)
{
    if (common::ThreadCall::isBlinkThread())
        wkeNetContinueJob(jobPtr);
    else {
        common::ThreadCall::callBlinkThreadAsync([jobPtr] {
            wkeNetContinueJob(jobPtr);
        });
    }
}

const mbSlist* MB_CALL_TYPE mbNetGetRawHttpHeadInBlinkThread(mbNetJob jobPtr)
{
    if (common::ThreadCall::isBlinkThread())
        return (const mbSlist*)wkeNetGetRawHttpHead((wkeNetJob)jobPtr);
    return nullptr;
}

void MB_CALL_TYPE mbNetHoldJobToAsynCommit(mbNetJob jobPtr)
{
    if (common::ThreadCall::isBlinkThread())
        wkeNetHoldJobToAsynCommit(jobPtr);
    else {
        common::ThreadCall::callBlinkThreadAsync([jobPtr] {
            wkeNetHoldJobToAsynCommit(jobPtr);
        });
    }
}

void MB_CALL_TYPE mbNetCancelRequest(mbNetJob jobPtr)
{
  if (common::ThreadCall::isBlinkThread())
      wkeNetCancelRequest(jobPtr);
  else {
    common::ThreadCall::callBlinkThreadAsync([jobPtr] {
        wkeNetCancelRequest(jobPtr);
    });
  }
}

const utf8* MB_CALL_TYPE mbUtilBase64Encode(const utf8* str)
{
    return wkeUtilBase64Encode(str);
}

const utf8* MB_CALL_TYPE mbUtilBase64Decode(const utf8* str)
{
    return wkeUtilBase64Decode(str);
}

struct UrlRequestWrap {
    int64_t id;
    mbWebView webView;
    mbUrlRequestCallbacks callbacks;
    void* param;
};

static void WKE_CALL_TYPE onUrlRequestWillRedirectCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr oldRequest, wkeWebUrlRequestPtr request, wkeWebUrlResponsePtr redirectResponse)
{
    UrlRequestWrap* self = (UrlRequestWrap*)param;
    void* unuse = common::LiveIdDetect::get()->getPtrLocked(self->id);
    if (!unuse)
        return;
  
    self->callbacks.willRedirectCallback(self->webView, self->param,
        (mbWebUrlRequestPtr)oldRequest, (mbWebUrlRequestPtr)request, (mbWebUrlResponsePtr)redirectResponse);
    common::LiveIdDetect::get()->unlock(self->id, unuse);
}

static void WKE_CALL_TYPE onUrlRequestDidReceiveResponseCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, wkeWebUrlResponsePtr response)
{
    UrlRequestWrap* self = (UrlRequestWrap*)param;
    void* unuse = common::LiveIdDetect::get()->getPtrLocked(self->id);
    if (!unuse)
        return;
    self->callbacks.didReceiveResponseCallback(self->webView, self->param,
        (mbWebUrlRequestPtr)request, (mbWebUrlResponsePtr)response);
    common::LiveIdDetect::get()->unlock(self->id, unuse);
}

static void WKE_CALL_TYPE onUrlRequestDidReceiveDataCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, const char* data, int dataLength)
{
    UrlRequestWrap* self = (UrlRequestWrap*)param;
    void* unuse = common::LiveIdDetect::get()->getPtrLocked(self->id);
    if (!unuse)
        return;
    self->callbacks.didReceiveDataCallback(self->webView, self->param, (mbWebUrlRequestPtr)request, data, dataLength);
    common::LiveIdDetect::get()->unlock(self->id, unuse);
}

static void WKE_CALL_TYPE onUrlRequestDidFailCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, const utf8* error)
{
    UrlRequestWrap* self = (UrlRequestWrap*)param;
    void* unuse = common::LiveIdDetect::get()->getPtrLocked(self->id);
    if (!unuse)
        return;
    self->callbacks.didFailCallback(self->webView, self->param, (mbWebUrlRequestPtr)request, error);
    common::LiveIdDetect::get()->unlock(self->id, unuse);
}

static void WKE_CALL_TYPE onUrlRequestDidFinishLoadingCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, double finishTime)
{
    UrlRequestWrap* self = (UrlRequestWrap*)param;
    void* unuse = common::LiveIdDetect::get()->getPtrLocked(self->id);
    if (!unuse)
        return;
    self->callbacks.didFinishLoadingCallback(self->webView, self->param, (mbWebUrlRequestPtr)request, finishTime);
    common::LiveIdDetect::get()->unlock(self->id, unuse);
}

mbWebUrlRequestPtr MB_CALL_TYPE mbNetCreateWebUrlRequest(const utf8* url, const utf8* method, const utf8* mime)
{
    return (mbWebUrlRequestPtr)wkeNetCreateWebUrlRequest(/*webView ? webView->getWkeWebView() : nullptr , */url, method, mime);
}

void MB_CALL_TYPE mbNetAddHTTPHeaderFieldToUrlRequest(mbWebUrlRequestPtr request, const utf8* name, const utf8* value)
{
    wkeNetAddHTTPHeaderFieldToUrlRequest((wkeWebUrlRequestPtr)request, name, value);
}

int MB_CALL_TYPE mbNetGetHttpStatusCode(mbWebUrlResponsePtr response)
{
    return wkeNetGetHttpStatusCode((wkeWebUrlResponsePtr)response);
}

mbRequestType MB_CALL_TYPE mbNetGetRequestMethod(mbNetJob jobPtr)
{
    return (mbRequestType)wkeNetGetRequestMethod((wkeNetJob)jobPtr);
}

long long MB_CALL_TYPE mbNetGetExpectedContentLength(mbWebUrlResponsePtr response)
{
    return wkeNetGetExpectedContentLength((wkeWebUrlResponsePtr)response);
}

const utf8* MB_CALL_TYPE mbNetGetResponseUrl(mbWebUrlResponsePtr response)
{
    return wkeNetGetResponseUrl((wkeWebUrlResponsePtr)response);
}

int MB_CALL_TYPE mbNetStartUrlRequest(mbWebView webView, mbWebUrlRequestPtr request, void* param, const mbUrlRequestCallbacks* callbacks)
{
    wkeUrlRequestCallbacks callbacksWrap = {
        onUrlRequestWillRedirectCallback ,
        onUrlRequestDidReceiveResponseCallback,
        onUrlRequestDidReceiveDataCallback,
        onUrlRequestDidFailCallback,
        onUrlRequestDidFinishLoadingCallback,
    };

    UrlRequestWrap* wrap = new UrlRequestWrap();

    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return 0;
    common::LiveIdDetect::get()->unlock(id, webView);

    wrap->id = id;
    wrap->webView = webView;
    wrap->callbacks = *callbacks;
    wrap->param = param;
    return wkeNetStartUrlRequest(webView ? webView->getWkeWebView() : nullptr, (wkeWebUrlRequestPtr)request, wrap, &callbacksWrap);
}

void MB_CALL_TYPE mbNetCancelWebUrlRequest(int requestId)
{
    wkeNetCancelWebUrlRequest(requestId);
}

void MB_CALL_TYPE mbSetNodeJsEnable(mbWebView webView, BOOL b)
{
    webView->setEnableNode(!!b);
}

void MB_CALL_TYPE mbSetDeviceParameter(mbWebView webView, const char* device, const char* paramStr, int paramInt, float paramFloat)
{
    std::string* deviceCopy = new std::string(device);
    std::string* paramStrCopy = nullptr;
    if (paramStr)
        paramStrCopy = new std::string(paramStr);

    common::ThreadCall::callBlinkThreadAsync([webView, deviceCopy, paramStrCopy, paramInt, paramFloat] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 != id) {
            wkeSetDeviceParameter(webView->getWkeWebView(), deviceCopy->c_str(), paramStrCopy ? paramStrCopy->c_str() : nullptr, paramInt, paramFloat);
            common::LiveIdDetect::get()->unlock(id, webView);
        }
        
        delete deviceCopy;
        if (paramStrCopy)
            delete paramStrCopy;
    });
}

const utf8* MB_CALL_TYPE mbUtilDecodeURLEscape(const utf8* str)
{
    return wkeUtilDecodeURLEscape(str);
}

const utf8* MB_CALL_TYPE mbUtilEncodeURLEscape(const utf8* str)
{
    return wkeUtilEncodeURLEscape(str);
}

const mbMemBuf* MB_CALL_TYPE mbUtilCreateV8Snapshot(const utf8* str)
{
#if ENABLE_IN_MB_MAIN
    return (const mbMemBuf*)wkeUtilCreateV8Snapshot(str);
#else
    return nullptr;
#endif
}

void MB_CALL_TYPE mbUtilPrintToPdf(mbWebView webView, mbWebFrameHandle frameId, const mbPrintSettings* settings, mbPrintPdfDataCallback callback, void* param)
{
#if ENABLE_IN_MB_MAIN
    mbPrintSettings* settingsWrap = new mbPrintSettings();
    *settingsWrap = *settings;

    common::ThreadCall::callBlinkThreadAsync([webView, settingsWrap, callback, param] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 != id) {
            common::LiveIdDetect::get()->unlock(id, webView);
            const wkePdfDatas* datas = wkeUtilPrintToPdf(webView->getWkeWebView(), nullptr, (const wkePrintSettings*)settingsWrap);
            callback(webView, param, (const mbPdfDatas*)datas);
            wkeUtilRelasePrintPdfDatas(datas);
        }
        delete settingsWrap;
    });
#endif
}

void MB_CALL_TYPE mbUtilPrintToBitmap(mbWebView webView, mbWebFrameHandle frameId, const mbScreenshotSettings* settings, mbPrintBitmapCallback callback, void* param)
{
#if ENABLE_IN_MB_MAIN
    mbScreenshotSettings* settingsWrap = nullptr;
    if (settings) {
        new mbScreenshotSettings();
        *settingsWrap = *settings;
    }

    common::ThreadCall::callBlinkThreadAsync([webView, settingsWrap, callback, param] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 != id) {
            common::LiveIdDetect::get()->unlock(id, webView);
            const wkeMemBuf* data = wkePrintToBitmap(webView->getWkeWebView(), nullptr, (const wkeScreenshotSettings*)settingsWrap);
            callback(webView, param, (const char*)data->data, data->length);
            wkeFreeMemBuf((wkeMemBuf*)data);
        }
        delete settingsWrap;
    });
#endif
}

class ScreenshotWrap {
public:
    ScreenshotWrap(mbWebView webView, mbOnScreenshot callback, void* param)
    {
        m_webView = webView;
        m_callback = callback;
        m_param = param;
    }

    static void WKE_CALL_TYPE onScreenshotWrap(wkeWebView webView, void* param, const char* data, size_t size)
    {
        ScreenshotWrap* self = (ScreenshotWrap*)param;
        self->m_callback(self->m_webView, self->m_param, data, size);
    }

private:
    mbWebView m_webView;
    mbOnScreenshot m_callback;
    void* m_param;
};

void MB_CALL_TYPE mbUtilScreenshot(mbWebView webView, const mbScreenshotSettings* settings, mbOnScreenshot callback, void* param)
{
#if ENABLE_IN_MB_MAIN
    mbScreenshotSettings* settingsWrap = nullptr;
    if (settings) {
        new mbScreenshotSettings();
        *settingsWrap = *settings;
    }

    ScreenshotWrap* wrap = new ScreenshotWrap(webView, callback, param);

    common::ThreadCall::callBlinkThreadAsync([webView, settingsWrap, wrap, callback, param] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 != id) {
            common::LiveIdDetect::get()->unlock(id, webView);
            wkeScreenshot(webView->getWkeWebView(), (const wkeScreenshotSettings*)settingsWrap, ScreenshotWrap::onScreenshotWrap, wrap);
        } else {
            callback(nullptr, param, nullptr, 0);
        }
        delete settingsWrap;
    });
#endif
}

void MB_CALL_TYPE mbFreeMemBuf(mbMemBuf* buf)
{
    wkeFreeMemBuf((wkeMemBuf*)buf);
}

static void onGetPdfPageDataCallback(mbWebView webView, mbOnGetPdfPageDataCallback callback, void* param, void* data, size_t size)
{
    std::vector<char>* dataCopy = nullptr;
    if (data) { 
        dataCopy = new std::vector<char>();
        dataCopy->resize(size);
        memcpy(&dataCopy->at(0), data, size);
    }

    common::ThreadCall::callUiThreadAsync([webView, dataCopy, callback, param] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        common::LiveIdDetect::get()->unlock(id, webView);
        if (dataCopy && -1 != id)
            callback(webView, param, &dataCopy->at(0), dataCopy->size());
        else
            callback(webView, param, nullptr, 0);

        if (dataCopy)
            delete dataCopy;
    });
}

void MB_CALL_TYPE mbGetPdfPageData(mbWebView webView, mbOnGetPdfPageDataCallback callback, void* param)
{
#if ENABLE_IN_MB_MAIN
    int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
    if (-1 == id)
        return;
    common::LiveIdDetect::get()->unlock(id, webView);

    if (!webView->getWkeWebView())
        return callback(webView, param, nullptr, 0);
    
    common::ThreadCall::callBlinkThreadAsync([webView, callback, param] {
        int64_t id = common::LiveIdDetect::get()->getIdLocked(webView);
        if (-1 == id)
            return onGetPdfPageDataCallback(nullptr, callback, param, nullptr, 0);
        common::LiveIdDetect::get()->unlock(id, webView);

        printing::PdfViewerPlugin* plugin = (printing::PdfViewerPlugin*)wkeGetUserKeyValue(webView->getWkeWebView(), "MbPdfViewerPlugin");
        if (!plugin)
            return onGetPdfPageDataCallback(webView, callback, param, nullptr, 0);
        
        std::vector<char>* data = plugin->getPdfData();
        if (!data || 0 == data->size())
            return onGetPdfPageDataCallback(webView, callback, param, nullptr, 0);

        onGetPdfPageDataCallback(webView, callback, param, &data->at(0), data->size());
    });
#endif // if ENABLE_IN_MB_MAIN
}

void mbSetUserKeyValue(mbWebView webView, const char* key, void* value)
{
	checkThreadCallIsValid(__FUNCTION__);
	
	if (!key)
		return;
	webView->getUuserKeyValues()[key] = value;
}

void* mbGetUserKeyValue(mbWebView webView, const char* key)
{
	checkThreadCallIsValid(__FUNCTION__);
	std::map<std::string, void*>::const_iterator it = webView->getUuserKeyValues().find(key);
	if (webView->getUuserKeyValues().end() == it)
		return nullptr;
	return it->second;
}

mbPostBodyElements* MB_CALL_TYPE mbNetGetPostBody(void *jobPtr)
{
    return (mbPostBodyElements*)wkeNetGetPostBody(jobPtr);
}

mbPostBodyElements* MB_CALL_TYPE mbNetCreatePostBodyElements(mbWebView webView, size_t length)
{
    return (mbPostBodyElements*)wkeNetCreatePostBodyElements(webView->getWkeWebView(), length);
}

void MB_CALL_TYPE mbNetFreePostBodyElements(mbPostBodyElements* elements)
{
    wkeNetFreePostBodyElements((wkePostBodyElements*)elements);
}

mbPostBodyElement* MB_CALL_TYPE mbNetCreatePostBodyElement(mbWebView webView)
{
    return (mbPostBodyElement*)wkeNetCreatePostBodyElement(webView->getWkeWebView());
}

void MB_CALL_TYPE mbNetFreePostBodyElement(mbPostBodyElement* element)
{
    return wkeNetFreePostBodyElement((wkePostBodyElement*)element);
}

#pragma comment(linker, "/EXPORT:mbInit=_mbInit@4")
#pragma comment(linker, "/EXPORT:mbUninit=_mbUninit@0")
#pragma comment(linker, "/EXPORT:mbCreateString=_mbCreateString@8")
#pragma comment(linker, "/EXPORT:mbDeleteString=_mbDeleteString@4")
#pragma comment(linker, "/EXPORT:mbNetSetData=_mbNetSetData@12")
#pragma comment(linker, "/EXPORT:mbNetGetHTTPHeaderField=_mbNetGetHTTPHeaderField@12")
#pragma comment(linker, "/EXPORT:mbNetSetHTTPHeaderField=_mbNetSetHTTPHeaderField@16")
#pragma comment(linker, "/EXPORT:mbNetChangeRequestUrl=_mbNetChangeRequestUrl@8")
#pragma comment(linker, "/EXPORT:mbNetHookRequest=_mbNetHookRequest@4")
#pragma comment(linker, "/EXPORT:mbNetCreateWebUrlRequest=_mbNetCreateWebUrlRequest@12")
#pragma comment(linker, "/EXPORT:mbNetStartUrlRequest=_mbNetStartUrlRequest@16")
#pragma comment(linker, "/EXPORT:mbNetGetHttpStatusCode=_mbNetGetHttpStatusCode@4")
#pragma comment(linker, "/EXPORT:mbNetGetExpectedContentLength=_mbNetGetExpectedContentLength@4")
#pragma comment(linker, "/EXPORT:mbNetGetResponseUrl=_mbNetGetResponseUrl@4")
#pragma comment(linker, "/EXPORT:mbNetGetMIMEType=_mbNetGetMIMEType@4")
#pragma comment(linker, "/EXPORT:mbNetGetRequestMethod=_mbNetGetRequestMethod@4")
#pragma comment(linker, "/EXPORT:mbNetCancelWebUrlRequest=_mbNetCancelWebUrlRequest@4")
#pragma comment(linker, "/EXPORT:mbNetAddHTTPHeaderFieldToUrlRequest=_mbNetAddHTTPHeaderFieldToUrlRequest@12")
#pragma comment(linker, "/EXPORT:mbNetSetMIMEType=_mbNetSetMIMEType@8")
#pragma comment(linker, "/EXPORT:mbNetContinueJob=_mbNetContinueJob@4")
#pragma comment(linker, "/EXPORT:mbNetGetRawHttpHeadInBlinkThread=_mbNetGetRawHttpHeadInBlinkThread@4")
#pragma comment(linker, "/EXPORT:mbNetHoldJobToAsynCommit=_mbNetHoldJobToAsynCommit@4")
#pragma comment(linker, "/EXPORT:mbNetCancelRequest=_mbNetCancelRequest@4")
#pragma comment(linker, "/EXPORT:mbNetGetPostBody=_mbNetGetPostBody@4")
#pragma comment(linker, "/EXPORT:mbNetCreatePostBodyElements=_mbNetCreatePostBodyElements@8")
#pragma comment(linker, "/EXPORT:mbNetFreePostBodyElements=_mbNetFreePostBodyElements@4")
#pragma comment(linker, "/EXPORT:mbNetCreatePostBodyElement=_mbNetCreatePostBodyElement@4")
#pragma comment(linker, "/EXPORT:mbNetFreePostBodyElement=_mbNetFreePostBodyElement@4")
#pragma comment(linker, "/EXPORT:mbCreateWebView=_mbCreateWebView@0")
#pragma comment(linker, "/EXPORT:mbCreateWebWindow=_mbCreateWebWindow@24")
#pragma comment(linker, "/EXPORT:mbCreateWebCustomWindow=_mbCreateWebCustomWindow@28")
#pragma comment(linker, "/EXPORT:mbDestroyWebView=_mbDestroyWebView@4")
#pragma comment(linker, "/EXPORT:mbMoveToCenter=_mbMoveToCenter@4")
#pragma comment(linker, "/EXPORT:mbSetNavigationToNewWindowEnable=_mbSetNavigationToNewWindowEnable@8")
#pragma comment(linker, "/EXPORT:mbSetMouseEnabled=_mbSetMouseEnabled@8")
#pragma comment(linker, "/EXPORT:mbSetTouchEnabled=_mbSetTouchEnabled@8")
#pragma comment(linker, "/EXPORT:mbSetContextMenuEnabled=_mbSetContextMenuEnabled@8")
#pragma comment(linker, "/EXPORT:mbSetHeadlessEnabled=_mbSetHeadlessEnabled@8")
#pragma comment(linker, "/EXPORT:mbSetDragDropEnable=_mbSetDragDropEnable@8")
#pragma comment(linker, "/EXPORT:mbSetDragEnable=_mbSetDragEnable@8")
#pragma comment(linker, "/EXPORT:mbSetDebugConfig=_mbSetDebugConfig@12")
#pragma comment(linker, "/EXPORT:mbSetProxy=_mbSetProxy@8")
#pragma comment(linker, "/EXPORT:mbSetHandle=_mbSetHandle@8")
#pragma comment(linker, "/EXPORT:mbSetHandleOffset=_mbSetHandleOffset@12")
#pragma comment(linker, "/EXPORT:mbGetHostHWND=_mbGetHostHWND@4")
#pragma comment(linker, "/EXPORT:mbSetCspCheckEnable=_mbSetCspCheckEnable@8")
#pragma comment(linker, "/EXPORT:mbSetNpapiPluginsEnabled=_mbSetNpapiPluginsEnabled@8")
#pragma comment(linker, "/EXPORT:mbSetMemoryCacheEnable=_mbSetMemoryCacheEnable@8")
#pragma comment(linker, "/EXPORT:mbSetContextMenuItemShow=_mbSetContextMenuItemShow@12")
#pragma comment(linker, "/EXPORT:mbSetCookie=_mbSetCookie@12")
#pragma comment(linker, "/EXPORT:mbSetCookieEnabled=_mbSetCookieEnabled@8")
#pragma comment(linker, "/EXPORT:mbSetCookieJarPath=_mbSetCookieJarPath@8")
#pragma comment(linker, "/EXPORT:mbSetCookieJarFullPath=_mbSetCookieJarFullPath@8")
#pragma comment(linker, "/EXPORT:mbSetLocalStorageFullPath=_mbSetLocalStorageFullPath@8")
#pragma comment(linker, "/EXPORT:mbSetDiskCacheEnabled=_mbSetDiskCacheEnabled@8")
#pragma comment(linker, "/EXPORT:mbSetUserAgent=_mbSetUserAgent@8")
#pragma comment(linker, "/EXPORT:mbAddPluginDirectory=_mbAddPluginDirectory@8")
#pragma comment(linker, "/EXPORT:mbSetResourceGc=_mbSetResourceGc@8")
#pragma comment(linker, "/EXPORT:mbSetZoomFactor=_mbSetZoomFactor@8")
#pragma comment(linker, "/EXPORT:mbGetZoomFactor=_mbGetZoomFactor@4")
#pragma comment(linker, "/EXPORT:mbCanGoForward=_mbCanGoForward@12")
#pragma comment(linker, "/EXPORT:mbCanGoBack=_mbCanGoBack@12")
#pragma comment(linker, "/EXPORT:mbGetTitle=_mbGetTitle@4")
#pragma comment(linker, "/EXPORT:mbGetUrl=_mbGetUrl@4")
#pragma comment(linker, "/EXPORT:mbGetCookie=_mbGetCookie@12")
#pragma comment(linker, "/EXPORT:mbGetCookieOnBlinkThread=_mbGetCookieOnBlinkThread@4")
#pragma comment(linker, "/EXPORT:mbClearCookie=_mbClearCookie@4")
#pragma comment(linker, "/EXPORT:mbResize=_mbResize@12")
#pragma comment(linker, "/EXPORT:mbOnNavigation=_mbOnNavigation@12")
#pragma comment(linker, "/EXPORT:mbOnNavigationSync=_mbOnNavigationSync@12")
#pragma comment(linker, "/EXPORT:mbOnCreateView=_mbOnCreateView@12")
#pragma comment(linker, "/EXPORT:mbOnDocumentReady=_mbOnDocumentReady@12")
#pragma comment(linker, "/EXPORT:mbOnPaintUpdated=_mbOnPaintUpdated@12")
#pragma comment(linker, "/EXPORT:mbOnLoadUrlBegin=_mbOnLoadUrlBegin@12")
#pragma comment(linker, "/EXPORT:mbOnLoadUrlEnd=_mbOnLoadUrlEnd@12")
#pragma comment(linker, "/EXPORT:mbOnTitleChanged=_mbOnTitleChanged@12")
#pragma comment(linker, "/EXPORT:mbOnURLChanged=_mbOnURLChanged@12")
#pragma comment(linker, "/EXPORT:mbOnLoadingFinish=_mbOnLoadingFinish@12")
#pragma comment(linker, "/EXPORT:mbOnDownload=_mbOnDownload@12")
#pragma comment(linker, "/EXPORT:mbOnDownloadInBlinkThread=_mbOnDownloadInBlinkThread@12")
#pragma comment(linker, "/EXPORT:mbOnAlertBox=_mbOnAlertBox@12")
#pragma comment(linker, "/EXPORT:mbOnConfirmBox=_mbOnConfirmBox@12")
#pragma comment(linker, "/EXPORT:mbOnPromptBox=_mbOnPromptBox@12")
#pragma comment(linker, "/EXPORT:mbOnNetGetFavicon=_mbOnNetGetFavicon@12")
#pragma comment(linker, "/EXPORT:mbOnConsole=_mbOnConsole@12")
#pragma comment(linker, "/EXPORT:mbOnClose=_mbOnClose@12")
#pragma comment(linker, "/EXPORT:mbOnDestroy=_mbOnDestroy@12")
#pragma comment(linker, "/EXPORT:mbOnPrinting=_mbOnPrinting@12")
#pragma comment(linker, "/EXPORT:mbOnDidCreateScriptContext=_mbOnDidCreateScriptContext@12")
#pragma comment(linker, "/EXPORT:mbGoBack=_mbGoBack@4")
#pragma comment(linker, "/EXPORT:mbGoForward=_mbGoForward@4")
#pragma comment(linker, "/EXPORT:mbStopLoading=_mbStopLoading@4")
#pragma comment(linker, "/EXPORT:mbReload=_mbReload@4")
#pragma comment(linker, "/EXPORT:mbPerformCookieCommand=_mbPerformCookieCommand@8")
#pragma comment(linker, "/EXPORT:mbEditorSelectAll=_mbEditorSelectAll@4")
#pragma comment(linker, "/EXPORT:mbEditorCopy=_mbEditorCopy@4")
#pragma comment(linker, "/EXPORT:mbEditorCut=_mbEditorCut@4")
#pragma comment(linker, "/EXPORT:mbEditorPaste=_mbEditorPaste@4")
#pragma comment(linker, "/EXPORT:mbEditorDelete=_mbEditorDelete@4")
#pragma comment(linker, "/EXPORT:mbEditorUndo=_mbEditorUndo@4")
#pragma comment(linker, "/EXPORT:mbFireMouseEvent=_mbFireMouseEvent@20")
#pragma comment(linker, "/EXPORT:mbFireContextMenuEvent=_mbFireContextMenuEvent@16")
#pragma comment(linker, "/EXPORT:mbFireMouseWheelEvent=_mbFireMouseWheelEvent@20")
#pragma comment(linker, "/EXPORT:mbFireKeyUpEvent=_mbFireKeyUpEvent@16")
#pragma comment(linker, "/EXPORT:mbFireKeyDownEvent=_mbFireKeyDownEvent@16")
#pragma comment(linker, "/EXPORT:mbFireKeyPressEvent=_mbFireKeyPressEvent@16")
#pragma comment(linker, "/EXPORT:mbFireWindowsMessage=_mbFireWindowsMessage@24")
#pragma comment(linker, "/EXPORT:mbSetFocus=_mbSetFocus@4")
#pragma comment(linker, "/EXPORT:mbKillFocus=_mbKillFocus@4")
#pragma comment(linker, "/EXPORT:mbShowWindow=_mbShowWindow@8")
#pragma comment(linker, "/EXPORT:mbLoadURL=_mbLoadURL@8")
#pragma comment(linker, "/EXPORT:mbLoadHtmlWithBaseUrl=_mbLoadHtmlWithBaseUrl@12")
#pragma comment(linker, "/EXPORT:mbGetLockedViewDC=_mbGetLockedViewDC@4")
#pragma comment(linker, "/EXPORT:mbUnlockViewDC=_mbUnlockViewDC@4")
#pragma comment(linker, "/EXPORT:mbWake=_mbWake@4")
#pragma comment(linker, "/EXPORT:mbJsToDouble=_mbJsToDouble@12")
#pragma comment(linker, "/EXPORT:mbJsToBoolean=_mbJsToBoolean@12")
#pragma comment(linker, "/EXPORT:mbJsToString=_mbJsToString@12")
#pragma comment(linker, "/EXPORT:mbOnJsQuery=_mbOnJsQuery@12")
#pragma comment(linker, "/EXPORT:mbResponseQuery=_mbResponseQuery@20")
#pragma comment(linker, "/EXPORT:mbRunJs=_mbRunJs@28")
#pragma comment(linker, "/EXPORT:mbRunJsSync=_mbRunJsSync@16")
#pragma comment(linker, "/EXPORT:mbWebFrameGetMainFrame=_mbWebFrameGetMainFrame@4")
#pragma comment(linker, "/EXPORT:mbIsMainFrame=_mbIsMainFrame@8")
#pragma comment(linker, "/EXPORT:mbSetNodeJsEnable=_mbSetNodeJsEnable@8")
#pragma comment(linker, "/EXPORT:mbSetDeviceParameter=_mbSetDeviceParameter@20")
#pragma comment(linker, "/EXPORT:mbUtilSerializeToMHTML=_mbUtilSerializeToMHTML@12")
#pragma comment(linker, "/EXPORT:mbGetContentAsMarkup=_mbGetContentAsMarkup@16")
#pragma comment(linker, "/EXPORT:mbUtilCreateRequestCode=_mbUtilCreateRequestCode@4")
#pragma comment(linker, "/EXPORT:mbUtilIsRegistered=_mbUtilIsRegistered@4")
#pragma comment(linker, "/EXPORT:mbUtilPrint=_mbUtilPrint@12")
#pragma comment(linker, "/EXPORT:mbUtilPrintToPdf=_mbUtilPrintToPdf@20")
#pragma comment(linker, "/EXPORT:mbUtilPrintToBitmap=_mbUtilPrintToBitmap@20")
#pragma comment(linker, "/EXPORT:mbUtilScreenshot=_mbUtilScreenshot@16")
#pragma comment(linker, "/EXPORT:mbUtilBase64Encode=_mbUtilBase64Encode@4")
#pragma comment(linker, "/EXPORT:mbUtilBase64Decode=_mbUtilBase64Decode@4")
#pragma comment(linker, "/EXPORT:mbUtilDecodeURLEscape=_mbUtilDecodeURLEscape@4")
#pragma comment(linker, "/EXPORT:mbUtilEncodeURLEscape=_mbUtilEncodeURLEscape@4")
#pragma comment(linker, "/EXPORT:mbUtilBase64Decode=_mbUtilBase64Decode@4")
#pragma comment(linker, "/EXPORT:mbUtilCreateV8Snapshot=_mbUtilCreateV8Snapshot@4")
#pragma comment(linker, "/EXPORT:mbPopupDownloadMgr=_mbPopupDownloadMgr@12")
#pragma comment(linker, "/EXPORT:mbPopupDialogAndDownload=_mbPopupDialogAndDownload@36")
#pragma comment(linker, "/EXPORT:mbDownloadByPath=_mbDownloadByPath@40")
#pragma comment(linker, "/EXPORT:mbFreeMemBuf=_mbFreeMemBuf@4")
#pragma comment(linker, "/EXPORT:mbGetPdfPageData=_mbGetPdfPageData@12")


