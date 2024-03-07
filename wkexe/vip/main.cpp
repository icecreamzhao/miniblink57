
#include "../../mbvip/core/mb.h"
#include "RootWindow.h"

#include <time.h> 
#include <windows.h>
#include <string>
#include <vector>
#include <time.h>
#include <process.h>
#include <shlobj.h>
#include <propvarutil.h>
#include <wininet.h>
#include <CommCtrl.h>
#include <tuple>
#include <crtdbg.h>
#include <psapi.h>
#include <iosfwd>
#include <sstream>
#include <set>
#include <TlHelp32.h>
#include <xmmintrin.h>
// #include "quickjs/quickjs.h"
// #include "quickjs/quickjs-libc.h"

// #define VLD_FORCE_ENABLE 1
// #include "C:\\Program Files (x86)\\Visual Leak Detector\\include\\vld.h"

#pragma comment(lib,"Imm32.lib")

void testSynMain();
void testGuard();
int winMainPrint();
int APIENTRY wWinMainIE(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow);
int APIENTRY wWinMain2(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow);

#define CLS_WINDOW L"mbTestWindow"
void readFile(const wchar_t* path, std::vector<char>* buffer);
void writeFile(const wchar_t* path, const std::vector<char>& buffer);

LRESULT WINAPI testWindowProc(
    __in HWND hWnd,
    __in UINT msg,
    __in WPARAM wParam,
    __in LPARAM lParam)
{
    LRESULT result = 0;
    mbWebView view = (mbWebView)::GetProp(hWnd, L"mb");
    if (!view)
        return ::DefWindowProc(hWnd, msg, wParam, lParam);

    switch (msg) {
    case WM_NCDESTROY:
        if (::GetProp(hWnd, L"subView")) {
            RemoveProp(hWnd, L"subView");
        } else {
            printf("Destroying\n");
            mbDestroyWebView(view);
            printf("Destroyed\n");
            PostQuitMessage(0);
        }
        return 0;

    case WM_ERASEBKGND:
        return TRUE;

    case WM_PAINT:
    {
        if (WS_EX_LAYERED == (WS_EX_LAYERED & GetWindowLong(hWnd, GWL_EXSTYLE)))
            break;
        //mbRepaintIfNeeded(view);

        PAINTSTRUCT ps = { 0 };
        HDC hdc = ::BeginPaint(hWnd, &ps);

        RECT rcClip = ps.rcPaint;

        RECT rcClient;
        ::GetClientRect(hWnd, &rcClient);

        RECT rcInvalid = rcClient;
        if (rcClip.right != rcClip.left && rcClip.bottom != rcClip.top)
            ::IntersectRect(&rcInvalid, &rcClip, &rcClient);

        int srcX = rcInvalid.left - rcClient.left;
        int srcY = rcInvalid.top - rcClient.top;
        int destX = rcInvalid.left;
        int destY = rcInvalid.top;
        int width = rcInvalid.right - rcInvalid.left;
        int height = rcInvalid.bottom - rcInvalid.top;

        if (0 != width && 0 != height) {
            HDC hMbDC = mbGetLockedViewDC(view);
            ::BitBlt(hdc, destX, destY, width, height, hMbDC, srcX, srcY, SRCCOPY);
            mbUnlockViewDC(view);
        }

        ::EndPaint(hWnd, &ps);
        return 1;
        break;
    }
    case WM_SIZE:
    {
        RECT rc = { 0 };
        ::GetClientRect(hWnd, &rc);
        int width = rc.right - rc.left;
        int height = rc.bottom - rc.top;

        ::mbResize(view, width, height);
        // mbRepaintIfNeeded(view);
        ::mbWake(view);

        return 0;
    }
    case WM_KEYDOWN:
    {
        unsigned int virtualKeyCode = wParam;
        unsigned int flags = 0;
        if (HIWORD(lParam) & KF_REPEAT)
            flags |= MB_REPEAT;
        if (HIWORD(lParam) & KF_EXTENDED)
            flags |= MB_EXTENDED;

        if (mbFireKeyDownEvent(view, virtualKeyCode, flags, false))
            return 0;
        break;
    }
    case WM_KEYUP:
    {
        unsigned int virtualKeyCode = wParam;
        unsigned int flags = 0;
        if (HIWORD(lParam) & KF_REPEAT)
            flags |= MB_REPEAT;
        if (HIWORD(lParam) & KF_EXTENDED)
            flags |= MB_EXTENDED;

        if (mbFireKeyUpEvent(view, virtualKeyCode, flags, false))
            return 0;
        break;
    }
    case WM_CHAR:
    {
        unsigned int charCode = wParam;
        unsigned int flags = 0;
        if (HIWORD(lParam) & KF_REPEAT)
            flags |= MB_REPEAT;
        if (HIWORD(lParam) & KF_EXTENDED)
            flags |= MB_EXTENDED;

        if (mbFireKeyPressEvent(view, charCode, flags, false))
            return 0;
        break;
    }
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
    case WM_MBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MOUSEMOVE:
    {
        if (msg == WM_LBUTTONDOWN || msg == WM_MBUTTONDOWN || msg == WM_RBUTTONDOWN) {
            if (::GetFocus() != hWnd)
                ::SetFocus(hWnd);
            ::SetCapture(hWnd);
        } else if (msg == WM_LBUTTONUP || msg == WM_MBUTTONUP || msg == WM_RBUTTONUP) {
            ReleaseCapture();
        }

        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        unsigned int flags = 0;

        if (wParam & MK_CONTROL)
            flags |= MB_CONTROL;
        if (wParam & MK_SHIFT)
            flags |= MB_SHIFT;

        if (wParam & MK_LBUTTON)
            flags |= MB_LBUTTON;
        if (wParam & MK_MBUTTON)
            flags |= MB_MBUTTON;
        if (wParam & MK_RBUTTON)
            flags |= MB_RBUTTON;

        if (mbFireMouseEvent(view, msg, x, y, flags))
            return 0;
        break;
    }
    case WM_CONTEXTMENU:
    {
        POINT pt;
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);

        if (pt.x != -1 && pt.y != -1)
            ScreenToClient(hWnd, &pt);

        unsigned int flags = 0;

        if (wParam & MK_CONTROL)
            flags |= MB_CONTROL;
        if (wParam & MK_SHIFT)
            flags |= MB_SHIFT;

        if (wParam & MK_LBUTTON)
            flags |= MB_LBUTTON;
        if (wParam & MK_MBUTTON)
            flags |= MB_MBUTTON;
        if (wParam & MK_RBUTTON)
            flags |= MB_RBUTTON;

        if (mbFireContextMenuEvent(view, pt.x, pt.y, flags))
            return 0;
        break;
    }
    case WM_MOUSEWHEEL:
    {
        POINT pt;
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);
        ::ScreenToClient(hWnd, &pt);

        int delta = GET_WHEEL_DELTA_WPARAM(wParam);

        unsigned int flags = 0;

        if (wParam & MK_CONTROL)
            flags |= MB_CONTROL;
        if (wParam & MK_SHIFT)
            flags |= MB_SHIFT;

        if (wParam & MK_LBUTTON)
            flags |= MB_LBUTTON;
        if (wParam & MK_MBUTTON)
            flags |= MB_MBUTTON;
        if (wParam & MK_RBUTTON)
            flags |= MB_RBUTTON;

        if (mbFireMouseWheelEvent(view, pt.x, pt.y, delta, flags))
            return 0;
        break;
    }
    case WM_SETFOCUS:
        mbSetFocus(view);
        return 0;

    case WM_KILLFOCUS:
        mbKillFocus(view);
        return 0;

    case WM_SETCURSOR:
        if (mbFireWindowsMessage(view, hWnd, WM_SETCURSOR, 0, 0, &result))
            return result;
        break;

    case WM_IME_STARTCOMPOSITION: {
        if (mbFireWindowsMessage(view, hWnd, WM_IME_STARTCOMPOSITION, 0, 0, &result))
            return result;
        break;
        }
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

BOOL RegWndClass(LPCTSTR lpcsClassName, DWORD dwStyle)
{
    WNDCLASS wndclass = { 0 };

    wndclass.style = dwStyle;
    wndclass.lpfnWndProc = testWindowProc;
    wndclass.cbClsExtra = 200;
    wndclass.cbWndExtra = 200;
    wndclass.hInstance = ::GetModuleHandle(NULL);
    wndclass.hIcon = NULL;
    //wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = lpcsClassName;

    ::RegisterClass(&wndclass);
    return TRUE;
}

BOOL UnregWndClass(LPCTSTR lpcsClassName)
{
    ::UnregisterClass(lpcsClassName, ::GetModuleHandle(NULL));
    return TRUE;
}

void MB_CALL_TYPE handlePaintUpdatedCallback(mbWebView webView, void* param, const HDC hdc, int x, int y, int cx, int cy)
{
    HWND hWnd = (HWND)param;
    BOOL callOk = FALSE;
    if (WS_EX_LAYERED == (WS_EX_LAYERED & GetWindowLong(hWnd, GWL_EXSTYLE))) {
        RECT rectDest;
        ::GetWindowRect(hWnd, &rectDest);

        SIZE sizeDest = { rectDest.right - rectDest.left, rectDest.bottom - rectDest.top };
        POINT pointDest = { 0, 0 }; // { rectDest.left, rectDest.top };
        POINT pointSource = { 0, 0 };

        BITMAP bmp = { 0 };
        HBITMAP hBmp = (HBITMAP)::GetCurrentObject(hdc, OBJ_BITMAP);
        ::GetObject(hBmp, sizeof(BITMAP), (LPSTR)&bmp);

        sizeDest.cx = bmp.bmWidth;
        sizeDest.cy = bmp.bmHeight;

        HDC hdcScreen = GetDC(hWnd);

        BLENDFUNCTION blend = { 0 };
        blend.BlendOp = AC_SRC_OVER;
        blend.SourceConstantAlpha = 255;
        blend.AlphaFormat = AC_SRC_ALPHA;
        callOk = ::UpdateLayeredWindow(hWnd, hdcScreen, nullptr, &sizeDest, hdc, &pointSource, RGB(0xFF, 0xFF, 0xFF), &blend, ULW_ALPHA);
        if (!callOk) {
            HDC hdcMemory = ::CreateCompatibleDC(hdcScreen);
            HBITMAP hbmpMemory = ::CreateCompatibleBitmap(hdcScreen, sizeDest.cx, sizeDest.cy);
            HBITMAP hbmpOld = (HBITMAP)::SelectObject(hdcMemory, hbmpMemory);

            ::BitBlt(hdcMemory, 0, 0, sizeDest.cx, sizeDest.cy, hdc, 0, 0, SRCCOPY | CAPTUREBLT);

            ::BitBlt(hdc, 0, 0, sizeDest.cx, sizeDest.cy, hdcMemory, 0, 0, SRCCOPY | CAPTUREBLT); //!

            callOk = ::UpdateLayeredWindow(hWnd, hdcScreen, nullptr, &sizeDest, hdcMemory, &pointSource, RGB(0xFF, 0xFF, 0xFF), &blend, ULW_ALPHA);

            ::SelectObject(hdcMemory, (HGDIOBJ)hbmpOld);
            ::DeleteObject((HGDIOBJ)hbmpMemory);
            ::DeleteDC(hdcMemory);
        }

        ::ReleaseDC(hWnd, hdcScreen);
    } else {
        RECT rc = { x, y, x + cx, y + cy };
        ::InvalidateRect(hWnd, &rc, FALSE);
    }
}

void MB_CALL_TYPE handleDocumentReady(mbWebView webView, void* param, mbWebFrameHandle frameId)
{
}

void MB_CALL_TYPE handleLoadingFinish(mbWebView webView, void* param, mbWebFrameHandle frameId, const utf8* url, mbLoadingResult result, const utf8* failedReason)
{
    //printf("HandleLoadingFinish url:%s result:%d\n", ::mbToString(url), result);
    //if(result == MB_LOADING_SUCCEEDED)
    //::mbNetGetFavicon(webView, HandleFaviconReceived, param);
    OutputDebugStringA("handleLoadingFinish \n");
}

mbWebView MB_CALL_TYPE handleCreateView(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url, const mbWindowFeatures* windowFeatures)
{
    mbWebView view = mbCreateWebView();
    HWND hWnd = ::CreateWindowEx(WS_EX_APPWINDOW, CLS_WINDOW, NULL, WS_OVERLAPPEDWINDOW | WS_VISIBLE, windowFeatures->x, windowFeatures->y, windowFeatures->width, windowFeatures->height, NULL, NULL, ::GetModuleHandle(NULL), NULL);
    ::SetProp(hWnd, L"mb", (HANDLE)view);
    ::SetProp(hWnd, L"subView", (HANDLE)TRUE);
    ::mbSetHandle(view, hWnd);
    ::mbOnPaintUpdated(view, handlePaintUpdatedCallback, hWnd);
    ::mbOnLoadingFinish(view, handleLoadingFinish, (void*)view);
    ::mbOnCreateView(view, handleCreateView, (void*)view);
    ::mbSetNavigationToNewWindowEnable(view, true);
    ::mbSetCspCheckEnable(view, true);

    RECT rc = { 0 };
    ::GetClientRect(hWnd, &rc);
    ::mbResize(view, rc.right, rc.bottom);

    //mbShowWindow(view, TRUE);
    return view;
}

void MB_CALL_TYPE onJsQuery(mbWebView webView, void* param, mbJsExecState es, int64_t queryId, int customMsg, const utf8* request)
{
    mbResponseQuery(webView, queryId, customMsg, request/*"I am response"*/);
}

void MB_CALL_TYPE onPaintBitUpdatedCallback(mbWebView webView, void* param, const void* buffer, const mbRect* r, int width, int height);

void createSimpleMb()
{
    //mbWebView view = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 0, 0, 840, 680);

    mbWebView view = mbCreateWebView();
    HWND hWnd = ::CreateWindowEx(/*WS_EX_APPWINDOW*/0, CLS_WINDOW, NULL, WS_OVERLAPPEDWINDOW, 0, 0, 840, 680, NULL, NULL, ::GetModuleHandle(NULL), NULL);
    ::SetProp(hWnd, L"mb", (HANDLE)view);
    ::mbSetTransparent(view, true);
    ::mbSetHandle(view, hWnd);
    ::mbOnPaintUpdated(view, handlePaintUpdatedCallback, hWnd);
    ::mbOnPaintBitUpdated(view, onPaintBitUpdatedCallback, nullptr);

//     ::mbOnDocumentReady(view, handleDocumentReady, (void*)view);
//     ::mbOnLoadingFinish(view, handleLoadingFinish, (void*)view);
//     ::mbOnCreateView(view, handleCreateView, (void*)view);
//     ::mbSetNavigationToNewWindowEnable(view, true);
//     ::mbSetCspCheckEnable(view, false);

    hWnd = mbGetHostHWND(view);
    RECT rc = { 0 };
    ::GetClientRect(hWnd, &rc);
    ::mbResize(view, rc.right, rc.bottom);

    mbMoveToCenter(view);
    mbShowWindow(view, TRUE);
    ::ShowWindow(hWnd, SW_SHOW);
    //mbSetHeadlessEnabled(view, TRUE);

    //::mbLoadHTML(view, "<html><head><style></style><script type=\"text/javascript\">var test = 'test';</script></head><body></body></html>");
    //https://www.baidu.com/s?wd=123

    char* randUrl = (char*)malloc(0x100);
    sprintf_s(randUrl, 0x99, "https://www.baidu.com/s?wd=%d", ::GetTickCount());

    ::mbLoadURL(view, "file:///G:/mycode/mbvip/out/x86/Release/1234.htm");
//     //::mbLoadURL(view, "file:///C:/Users/weo/AppData/Local/AllMobilize/parent.htm");
//     //::mbLoadURL(view, "file:///E:/mycode/mtmb/Debug/guiji.htm");
//     //::mbLoadURL(view, "https://passport.csdn.net/account/login");//http://www.17sucai.com/pins/demo-show?id=23150
// 
//     mbOnJsQuery(view, onJsQuery, (void*)1);

    free(randUrl);
}

void createMbClient()
{
    RootWindow* rootWin = new RootWindow();
    rootWin->createRootWindow();
}

void ASSERT(bool b)
{
    if (!b)
        DebugBreak();
}

void crxEncryptMain();
std::vector<DWORD> GetCurrentProcessOtherInstance();
void testSync();
int testNet();

/////

const unsigned int kMyMagicLen = 4096;

struct MyHead {
    size_t size;
    unsigned char unuse[kMyMagicLen - 4];
    unsigned char magic[kMyMagicLen];
};

typedef void* (__cdecl* FN_Free)(void*);
FN_Free origFree = nullptr;

void* __cdecl MyFree(void* p) {
    if (!p)
        return nullptr;

    MyHead* head = (MyHead*)p;
    head--;
    for (size_t i = 0; i < kMyMagicLen; ++i) {
        if (head->magic[i] != 0x22)
            DebugBreak();
    }

    VirtualFree(head, 0, MEM_RELEASE);
    return nullptr;
}

typedef void* (__cdecl* FN_Malloc)(size_t);
FN_Malloc origMalloc = nullptr;

static int GetRealSize(size_t s) {
    int ret = ((s / 4096) + 3) * 4096;
    return ret;
}

typedef void* (__cdecl* FN_CreateThread)(void* lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
FN_CreateThread s_origCreateThread = nullptr;

HANDLE MyCreateThread(void* lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
{
  return s_origCreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
}

void* __cdecl MyMalloc(size_t s) {
    if (0 == s)
        return nullptr;

    MyHead* head = (MyHead*)::VirtualAlloc(NULL, GetRealSize(s), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    head->size = s;
    memset(head->magic, 0x22, kMyMagicLen);

    DWORD dwOldProtect = 0;
    VirtualProtect((char*)head + 4096, 4096, PAGE_READONLY, &dwOldProtect);

    head++;
    return head;
}

typedef void* (__cdecl* FN_Realloc)(void*, size_t);
FN_Realloc origRealloc = nullptr;

void* __cdecl MyRealloc(void* p, size_t s) {
    MyHead* head = (MyHead*)p;
    if (!head) {
        if (0 == s)
            return nullptr;

        return MyMalloc(s);
    }

    head--;
    for (size_t i = 0; i < kMyMagicLen; ++i) {
        if (head->magic[i] != 0x22)
            DebugBreak();
    }
    MyFree(p);
    return MyMalloc(s);
}

typedef void* (__cdecl* FN_MyCalloc)(size_t _Count, size_t _Size);
FN_MyCalloc origCalloc = nullptr;
void* __cdecl MyCalloc(size_t _Count, size_t _Size)
{
    void* ret = MyMalloc(_Count * _Size);
    memset(ret, 0, sizeof(_Count * _Size));
    return ret;
}

BOOL HookAddrByHotpatch(void* addr, void* pfnNew, void** pfnOld) {
    void* pFunc = (void*)addr;
    DWORD dwOldProtect = 0;
    DWORD dwAddress = 0;

    BYTE pBuf[5] = { 0xE9, 0, };
    BYTE pBuf2[2] = { 0xEB, 0xF9 };

    PBYTE pByte = (PBYTE)pFunc;
    if (pByte[0] != 0x8B && pByte[1] != 0xff)
        return FALSE;

    if (pfnOld)
        *pfnOld = (void*)&pByte[2];

    VirtualProtect((LPVOID)((DWORD)pFunc - 5), 7, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    dwAddress = (DWORD)pfnNew - (DWORD)pFunc; //计算Hook函数和被Hook函数的地址偏移

    memcpy(&pBuf[1], &dwAddress, 4); //将偏移地址拼凑到“JMP XXXXx"中

    memcpy((LPVOID)((DWORD)pFunc - 5), pBuf, 5); //将“JMP pfnNew”写入pFunc-5的位置，也就是五个NOP的位置

                                                 // 2. MOV EDI, EDI (0x8BFF)
                                                 // 将“JMP-7”写入pFunc的位置，也就是MOV EDI, EDI的位置
    memcpy((void*)pFunc, pBuf2, 2);

    VirtualProtect((LPVOID)((DWORD)pFunc - 5), 7, dwOldProtect, &dwOldProtect);
    return TRUE;
}

BOOL HookByHotpatch(LPCWSTR szDllName, LPCSTR szFuncName, void* pfnNew, void** pfnOld)
{
    void* pFunc = (void*)GetProcAddress(LoadLibraryW(szDllName), szFuncName);
    return HookAddrByHotpatch((void*)pFunc, pfnNew, pfnOld);
}

// xxx.new2-data = "aaa";
// /*  xxx */
// //ssxxxx
class FixV8Error {
public:
    FixV8Error(std::string* source)
    {
        m_pos = 0;
        m_sentenceBegin = 0;
        m_sentenceEnd = 0;
        m_isError = false;
        m_isInSingleComments = false;
        m_isInMutilComments = false;
        m_source = source;
    }

    void run()
    {
        for (; m_pos < m_source->size() - 1; ++m_pos) {
            runImpl(m_source->at(m_pos));
            if (m_isError)
                return;
        }
    }

    void fixV8ErrorImpl()
    {
        for (size_t i = m_sentenceBegin; i < m_sentenceEnd; ++i) {
            (*m_source)[i] = ' ';
        }
    }

    void fixV8Error()
    {
        for (size_t i = m_sentenceBegin; i < m_sentenceEnd; ++i) {
            if ('-' != m_source->at(i)) {
                continue;
            }
            for (size_t j = i; j < m_sentenceEnd; ++j) {
                char c = m_source->at(j);
                if ('A'<= c && c <= 'Z' || 'a'<= c && c <= 'z' || ' ' == c || '\r' == c || '\n' == c)
                    continue;
                if (';' <= c)
                    return;
                if ('=' == c) {
                    fixV8ErrorImpl();
                    return;
                }
            }
        }
    }

    void runImpl(char c)
    {
        switch (c) {
        case '/': {
            ++m_pos;
            if ('/' == m_source->at(m_pos)) {
                gotoSingleCommentsEnd();
            } else if ('*' == m_source->at(m_pos)) {
                gotoMutilCommentsEnd();
            }
            if (m_isError)
                return;
            m_sentenceBegin = m_pos;
            m_sentenceEnd = m_pos;
            break;
        }
        case '\'': {
            gotoSingleQuotationEnd();
            if (m_isError)
                return;
            break;
        }
        case '\"': {
            gotoQuotationEnd();
            if (m_isError)
                return;
            break;
        }
        case '\n': // no break;
        case ';': {
            fixV8Error();
            m_sentenceBegin = m_sentenceEnd;
            m_sentenceEnd++;
            break;
        }
        default: {
            m_sentenceEnd++;
        }

        }
    }

private:
    void gotoQuotationEnd()
    {
        bool find = false;
        for (; m_pos < m_source->size(); ++m_pos) {
            if ('\\' == m_source->at(m_pos)) {
                ++m_pos;
                continue;
            } else if ('\n' == m_source->at(m_pos)) {
                m_isError = true;
                return;
            } else if ('"' == m_source->at(m_pos)) {
                ++m_pos;
                find = true;
                break;
            }
        }
        if (!find)
            m_isError = true;
    }

    void gotoSingleQuotationEnd()
    {
        bool find = false;
        for (; m_pos < m_source->size(); ++m_pos) {
            if ('\\' == m_source->at(m_pos)) {
                ++m_pos;
                continue;
            } else if ('\n' == m_source->at(m_pos)) {
                m_isError = true;
                return;
            } else if ('\'' == m_source->at(m_pos)) {
                ++m_pos;
                find = true;
                break;
            }
        }
        if (!find)
            m_isError = true;
    }

    void gotoSingleCommentsEnd()
    {
        for (; m_pos < m_source->size(); ++m_pos) {
            if ('\n' == m_source->at(m_pos)) {
                ++m_pos;
                return;
            }
        }
    }

    void gotoMutilCommentsEnd()
    {
        for (; m_pos < m_source->size() - 1; ++m_pos) {
            if ('*' == m_source->at(m_pos) && '//' == m_source->at(m_pos + 1)) {
                ++m_pos;
                return;
            }
        }
        m_isError = true;
    }

    size_t m_pos;
    size_t m_sentenceBegin;
    size_t m_sentenceEnd;
    bool m_isError;
    bool m_isInSingleComments; // //
    bool m_isInMutilComments; // /**/
    std::string* m_source;
};

// int testQuickjs()
// {
//     std::vector<char> buffer;
//     readFile(L"G:\\test\\web_test\\xmlifa\\test_v8.js", &buffer);
// 
//     const char* filename = "<input>";
// 
//     JSRuntime* rt;
//     JSContext* ctx;
//     rt = JS_NewRuntime();
//     ctx = JS_NewContextRaw(rt);
//     JS_AddIntrinsicBaseObjects(ctx);
//     //js_std_add_helpers(ctx, argc, argv);
//     //js_std_eval_binary(ctx, (const uint8_t *)buffer.data(), buffer.size(), 0);
//     JSValue v = JS_Eval(ctx, buffer.data(), buffer.size(), "<input>", JS_EVAL_TYPE_GLOBAL);
//     //js_std_loop(ctx);
// 
//     JSValue res_val, exception_val;
//     exception_val = JS_GetException(ctx);
// 
//     JSValue name, stack;
//     const char* stack_str;
//     const char *error_name;
//     int ret, error_line, pos, pos_line;
//     BOOL is_error, has_error_line;
//     
//     name = JS_GetPropertyStr(ctx, exception_val, "name");
//     error_name = JS_ToCString(ctx, name);
//     stack = JS_GetPropertyStr(ctx, exception_val, "stack");
//     if (!JS_IsUndefined(stack)) {
//         stack_str = JS_ToCString(ctx, stack);
//         if (stack_str) {
//             const char* p;
//             int len;
// 
// //             if (outfile)
// //                 fprintf(outfile, "%s", stack_str);
// 
//             len = strlen(filename);
//             p = strstr(stack_str, filename);
//             if (p != NULL && p[len] == ':') {
//                 error_line = atoi(p + len + 1);
//                 has_error_line = TRUE;
//             }
//             JS_FreeCString(ctx, stack_str);
//         }
//     }
//     JS_FreeValue(ctx, stack);
//     JS_FreeValue(ctx, name);
// 
//     JS_FreeContext(ctx);
//     JS_FreeRuntime(rt);
//     return 0;
// }

size_t gotoPosImpl(std::string* source, size_t index, bool* find, char ch, bool ignoreSpacing)
{
    size_t i = index;
    for (; i < source->size() && i < index + 10; ++i) {
        char c = source->at(i);
        if (ch == c) {
            *find = true;
            return i;
        }

        if (!('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9') 
            && !(ignoreSpacing && ' ' == c)) {
            *find = false;
            return i;
        }
    }

    if (i == source->size() - 1)
        return -1;

    *find = false;
    return i;
}

size_t gotoMinuPos(std::string* source, size_t index, bool* find)
{
    return gotoPosImpl(source, index, find, '-', false);
}

size_t gotoEqPos(std::string* source, size_t index, bool* find)
{
    return gotoPosImpl(source, index, find, '=', true);
}

void nopScript(std::string* source, size_t index, size_t len)
{
    for (size_t i = index; i < index + len &&  i < source->size(); ++i) {
        (*source)[i] = ';';
    }
}

// document.getElementById("content").new2-data = "aaa"; 	// Uncaught
bool fixV8ErrorImpl(std::string* source)
{
    bool find = false;
    bool findMinus = false;
    bool findEq = false;
    for (size_t i = 0; i < source->size() - 1; ++i) {
        char c = source->at(i);
        if ('.' != c)
            continue;

        size_t pos1 = gotoMinuPos(source, i + 1, &findMinus);
        if (-1 == pos1)
            return false;
        if (!findMinus) {
            i = pos1 - 1;
            continue;
        }

        size_t pos2 = gotoEqPos(source, pos1 + 1, &findEq);
        if (-1 == pos2)
            return false;
        if (!findEq) {
            i = pos2 - 1;
            continue;
        }

        char c1 = source->at(pos2);
        nopScript(source, i, pos2 - i + 1);
        i = pos2;
        find = true;
    }
    return find;
}

bool FindIpAddr(const std::string& str);
void testMain();

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{

    //HookByHotpatch(L"kernel32.DLL", (LPCSTR)"CreateThread", ((void*)(MyCreateThread)), (void**)&s_origCreateThread);
//     testMain();
//     return 0;
// 
//     g_TestTls111 = new TestTls();
//     g_TestTls222 = new TestTls();

    bool b = false;

    //b = FindIpAddr("candidate:842163049  1 udp 1677729535 113..74.127.28 6978  typ srflx raddr 0.0.0.0 rport 0 generation 0 ufrag 1HT/ network-cost 999");
//     b = FindIpAddr("a 123.74.127.28 6978");
//     b = FindIpAddr("123.74.127.28 6978");
//     b = FindIpAddr("123.74.127. 28 6978");
//     b = FindIpAddr("123.74.127.238");
//     b = FindIpAddr("123.74.127.2383");
    //b = FindIpAddr(" 123.74.127.233 ");
    //b = FindIpAddr("123..74.127.233 ");
//     b = FindIpAddr(" 123.74.127..28 ..");
//     b = FindIpAddr("123.74.12 7.28");
//     b = FindIpAddr(".123.74.12 7.28");

    //fortchrome::DelChromeInk();
    //return 0;

    //testQuickjs();
//     std::vector<char> buffer;
//     readFile(L"G:\\test\\web_test\\xmlifa\\test_v8.js", &buffer);
//     std::string str(buffer.data(), buffer.size());
// //     FixV8Error fix(&str);
// //     fix.run();
// 
//     //std::string str("xxx.asdasdasd.new-ab = \'123\'\n");
//     //std::string str("xxx.asdasdasd.new-ab =");
//     //std::string str("xxx.asdasdasd.new-ab");
//     //std::string str(".asdasdasd.new-ab=");
//     fixV8ErrorImpl(&str);
//     buffer.resize(str.size());
//     memcpy(buffer.data(), str.c_str(), str.size());
//     writeFile(L"G:\\test\\web_test\\xmlifa\\test_v8_2.js", buffer);

//     HookByHotpatch(L"ucrtbase.DLL", (LPCSTR)"malloc", ((void*)(MyMalloc)), (void**)&origMalloc);
//     HookByHotpatch(L"ucrtbase.DLL", (LPCSTR)"free", ((void*)(MyFree)), (void**)&origFree);
//     HookByHotpatch(L"ucrtbase.DLL", (LPCSTR)"realloc", ((void*)(MyRealloc)), (void**)&origRealloc);
//     HookByHotpatch(L"ucrtbase.DLL", (LPCSTR)"calloc", ((void*)(MyCalloc)), (void**)&origCalloc);
    

//     crxEncryptMain();
//     return 0;

    //return wWinMainSql();
    //KillVs();
    //return FixV8Main();
    //GetCurrentProcessOtherInstance();
    //testSync();

#if 0 //def _DEBUG
    //return wWinMain2(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
    //return wWinMainIE(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
#endif // DEBUG

//     SeekableBuf seekableBuf;
//     seekableBuf.append();

//     wchar_t lpszShortPath[300];
//     GetShortPathName(L"G:\\test\\web_test\\updata_proj 我\\bin_2020.12.3_1\\updata\\updata_test.js", lpszShortPath, 255);
//     OutputDebugStringA("");
     //return WinMainOGL(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

// 
    //testHook();
    //testCondVar();

    //fixFenjianli();
     //deleteVirus2(L"E:\\mycode\\chromium\\trunk\\src\\chrome\\test\\data\\empty.html");//L"D:\\Program Files (x86)\\Tencent\\QQ\\Bin\\AddEmotion.htm"

//     findVirus(L"d:\\");
    //fixChromiumVirusHtml(L"E:\\mycode\\chromium.bb_master\\src\\");
    //fileToHex(L"E:\\mycode\\miniblink49\\trunk\\node\\lib\\internal\\bootstrap_node.js");
     //changeCRLF(L"E:\\mycode\\mtmb\\mtmb\\printing\\printing.cpp");
    //findKeyCode();

    //VLDEnable();

    RegWndClass(CLS_WINDOW, CS_HREDRAW | CS_VREDRAW);
    
    mbSettings* settings = new mbSettings();
    memset(settings, 0, sizeof(mbSettings));

    //settings->mask |= MB_SETTING_PROXY;
    //settings->proxy.type = MB_PROXY_HTTP;
    //strcpy(settings->proxy.hostname, "127.0.0.1");
    //settings->proxy.port = 10809;
    //settings->proxy.username[50];
    //strcpy(settings->proxy.password, "c906d0c8902c75d3910cd46c21dc34e8");

    //settings->mask = MB_ENABLE_NODEJS;
    //settings->mask = MB_ENABLE_DISABLE_CC;
    //settings->mask |= MB_ENABLE_DISABLE_H5VIDEO;
    //settings->mask |= MB_ENABLE_ENABLE_SWIFTSHAER;
    //settings->mask |= MB_ENABLE_ENABLE_EGLGLES2;
    settings->version = kMbVersion;
    //settings->mainDllPath = L"E:\\mycode\\mtmb\\Debug\\node.dll";

    //settings->config = "{\"enableSkipJs\":true}";
    settings->config = "{}";

    //mbSetMbDllPath(L"G:\\mycode\\miniblink57\\Debug\\node.dll");
    //mbSetMbMainDllPath(L"G:\\mycode\\mb\\out\\Debug\\node.dll");
#ifdef _WIN64
    mbSetMbMainDllPath(L"miniblink_5775_x64.dll");
#else
    mbSetMbMainDllPath(L"miniblink_5775_x32.dll");
#endif

    //mbSetMbMainDllPath(L"node.dll");

    //settings->mainDllPath = L"node_v8_7_5.dll";
    //mbSetMbMainDllPath(L"node_v8_7_5.dll");

//     mbFillFuncPtr();
//     mbSettings* settings = mbCreateInitSettings();
//     mbSetInitSettings(settings, "DisableCC", nullptr);
    mbInit(settings);

    mbSetUserAgent(NULL_WEBVIEW, "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like XSD) Chrome/79.0.3945.130 Safari/537.36");

    //mbEnableHighDPISupport();
    //mbSetNpapiPluginsEnabled(NULL_WEBVIEW, false);

    createMbClient();
    //createSimpleMb();
    
//     MSG msg = { 0 };
//     while (true) {
//         if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
//             if (g_quitCount > 0) {
//                 ++g_quitCount;
//             }
//             if (g_quitCount > 100) {
//                 ::PostThreadMessage(::GetCurrentThreadId(), WM_QUIT, 0, 0);
//             }
//             if (WM_QUIT == msg.message)
//                 break;                
// 
//             ::TranslateMessage(&msg);
//             ::DispatchMessageW(&msg);
//         }
//         ::mbWake(NULL_WEBVIEW);
//         ::Sleep(5);
//     }

    mbRunMessageLoop();

//     MSG msg = { 0 };
//     while (::GetMessageW(&msg, NULL, 0, 0)) {
//         ::TranslateMessage(&msg);
//         ::DispatchMessageW(&msg);
//     }
    
#ifdef _DEBUG
    mbUninit();
#endif

    //VLDReportLeaks();

    UnregWndClass(CLS_WINDOW);

    return 0;
}
