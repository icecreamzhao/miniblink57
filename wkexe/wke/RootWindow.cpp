#include <windows.h>
#include <Shlwapi.h>
#include <xstring>
#include <vector>
#include "RootWindow.h"
#include "Resource.h"
#include "HideWndHelp.h"

std::string utf16ToChar(LPCWSTR lpszSrc, UINT codepage);
void readFile(const wchar_t* path, std::vector<char>* buffer);

bool saveDumpFile(const std::wstring& url, const char* buffer, unsigned int size)
{
    HANDLE hFile = NULL;
    bool   bRet = false;

    hFile = CreateFileW(url.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (!hFile || INVALID_HANDLE_VALUE == hFile)
        return false;

    DWORD numberOfBytesWritten = 0;
    ::WriteFile(hFile, buffer, size, &numberOfBytesWritten, NULL);
    ::CloseHandle(hFile);
    bRet = true;

    return bRet;
}

void setUserDataPtr(HWND hWnd, void* ptr)
{
    ::SetLastError(ERROR_SUCCESS);
    LONG_PTR result = ::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(ptr));
}

// Return the window's user data pointer.
template <typename T>
T getUserDataPtr(HWND hWnd)
{
    return reinterpret_cast<T>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
}

WNDPROC setWndProcPtr(HWND hWnd, WNDPROC wndProc)
{
    WNDPROC old = reinterpret_cast<WNDPROC>(::GetWindowLongPtr(hWnd, GWLP_WNDPROC));
    LONG_PTR result = ::SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(wndProc));
    return old;
}

RootWindow::RootWindow()
{
    m_hWnd = nullptr;
    m_wkeView = nullptr;

    m_font = nullptr;
    m_backHwnd = nullptr;
    m_forwardHwnd = nullptr;
    m_reloadHwnd = nullptr;
    m_stopHwnd = nullptr;
    m_editHwnd = nullptr;
    m_hbrush = nullptr;
    m_hMenu = nullptr;
    m_hideWndHelp = nullptr;
}

RootWindow::~RootWindow()
{
    OutputDebugStringA("~RootWindow\n");
}

const int kTestTaskTimerId = 135322;
static int g_countTest = 0;
wkeWebView g_wkeView = nullptr;

void CALLBACK onTestProc(HWND, UINT, UINT_PTR, DWORD)
{
    if ((g_countTest % 2) == 0) {
        wkeGoBack(g_wkeView);
    } else {
        wkeGoForward(g_wkeView);
    }
    g_countTest++;
}

void WKE_CALL_TYPE onShowDevtoolsCallback(wkeWebView webView, void* param)
{
    OutputDebugStringA("onShowDevtoolsCallback\n");
}

void WKE_CALL_TYPE onScreenshot(wkeWebView webView, void* param, const char* data, size_t size)
{
    if (0 == size)
        return;

    int* count = (int*)param;

    char path[200] = { 0 };
    sprintf_s(path, 0x99, "d:\\FeigeDownload\\%d.bmp", *count);

    (*count)++;

    HANDLE hFile = CreateFileA(path, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (!hFile || INVALID_HANDLE_VALUE == hFile)
        return;

    DWORD numberOfBytesWritten = 0;
    ::WriteFile(hFile, data, size, &numberOfBytesWritten, NULL);
    ::CloseHandle(hFile);
}

void printToPdf(wkeWebView view)
{
    wkePrintSettings settings = { 0 };

    int dpi = 600;
    settings.width = 8.266 * dpi;// dpi * 640; // in px or device context
    settings.height = 11.7 * dpi;// dpi * 740;
    settings.marginLeft = 0; // marginPrinterUnits
    settings.marginTop = 0;
    settings.marginRight = 0;
    settings.marginBottom = 0;
    settings.dpi = dpi;
    settings.isPrintPageHeadAndFooter = TRUE;
    settings.isPrintBackgroud = TRUE;
    settings.isLandscape = FALSE;
    settings.isPrintToMultiPage = FALSE;

    const wkePdfDatas* pdfDatas = wkeUtilPrintToPdf(view, nullptr, &settings);

    for (int i = 0; i < pdfDatas->count; ++i) {
        int size = pdfDatas->sizes[i];
        const void* data = pdfDatas->datas[i];

        wchar_t* output = (wchar_t*)malloc(0x200);
        swprintf_s(output, 0x100, L"D:\\Res\\%d.pdf", i);
        saveDumpFile(output, (const char*)data, size);
        free(output);
    }

    wkeUtilRelasePrintPdfDatas(pdfDatas);
}

const UINT kBaseId = 100;

LRESULT RootWindow::hideWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    UINT id = LOWORD(wParam);
    if (WM_COMMAND != uMsg)
        return ::DefWindowProc(hwnd, uMsg, wParam, lParam);

    if (kBaseId + 0 == id) {
        onShowDevtools();
        //wkeEditorSelectAll(m_wkeView);
        ///mbGetContentAsMarkup(m_mbView, onGetContentAsMarkupCallback, nullptr, (mbWebFrameHandle)-2);
    } else if (kBaseId + 1 == id) {
//         int count = 0;
//         wkeScreenshot(m_wkeView, nullptr, onScreenshot, &count);

        const utf8* cookie = wkeGetCookie(m_wkeView);
        wkeClearCookie(m_wkeView);
        cookie = wkeGetCookie(m_wkeView);
    }
    else if (kBaseId + 2 == id) {
        //printToPdf(m_wkeView);
        wkeGC(m_wkeView, 2);

    } else if (kBaseId + 3 == id) {
// 		std::vector<char> buffer;
// 		readFile(L"C:\\test\\web_test\\pdd.js", &buffer);
//      buffer.push_back('\0');
// 
//      wkeRunJS(m_wkeView, buffer.data());

        //wkeNavigateAtIndex(m_wkeView, 3);
    }

    return ::DefWindowProc(hwnd, uMsg, wParam, lParam);
}

static void appendMenuItem(const std::wstring& labelStr, HMENU hMenu, MENUITEMINFO* info, UINT* count)
{
    info->fMask |= MIIM_STRING | MIIM_ID;
    info->cch = labelStr.size();
    info->dwTypeData = const_cast<LPWSTR>(labelStr.c_str());
    info->wID = kBaseId + *count;
    ::InsertMenuItem(hMenu, *count, TRUE, info);
    (*count)++;
}

void RootWindow::onMoreCommand()
{
    POINT pt = { 0 };
    ::GetCursorPos(&pt);
    if (m_hMenu) {
        ::SetForegroundWindow(m_hideWndHelp->getWnd());
        ::TrackPopupMenu(m_hMenu, TPM_LEFTALIGN | TPM_TOPALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, 0, m_hideWndHelp->getWnd(), NULL);
        return;
    }

    RootWindow* self = this;
    m_hideWndHelp = new HideWndHelp(L"HideParentWindowClass", [self](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT {
        return self->hideWndProc(hWnd, uMsg, wParam, lParam);
    });

    m_hMenu = ::CreatePopupMenu();

    MENUITEMINFO info = { 0 };
    info.cbSize = sizeof(MENUITEMINFO);

    UINT count = 0;

    appendMenuItem(L"打开devtools", m_hMenu, &info, &count);
    appendMenuItem(L"清除所有cookies", m_hMenu, &info, &count);
    appendMenuItem(L"内存回收", m_hMenu, &info, &count);
    appendMenuItem(L"执行脚本", m_hMenu, &info, &count);

    ::SetForegroundWindow(m_hideWndHelp->getWnd());
    ::TrackPopupMenu(m_hMenu, TPM_LEFTALIGN | TPM_TOPALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, 0, m_hideWndHelp->getWnd(), NULL);

    return;
}

void RootWindow::onShowDevtools()
{
//     wkeRunJS(m_wkeView, "window.location.reload()");
//     return;

//     const char* url = "passport.58.com";
//     const char* cookie = nullptr;
// 
// 
//     wkeSetCookie(m_wkeView, url, "__utmz=0; Domain=.58.com; Expires=Thu, 01-Jan-1970 00:00:10 GMT; Path=/");
//     wkeSetCookie(m_wkeView, url, "58uname=0; Domain=.58.com; Expires=Thu, 01-Jan-1970 00:00:10 GMT; Path=/");
// 
//     wkeSetCookie(m_wkeView, url, "cloudpassport=0; Domain=.passport.58.com; Expires=Thu, 01-Jan-1970 00:00:10 GMT; Path=/");
//     cookie = wkeGetCookie(m_wkeView);
// 
//     //wkePerformCookieCommand(m_wkeView, wkeCookieCommandFlushCookiesToFile);

    std::vector<wchar_t> path;
    path.resize(MAX_PATH + 1);
    memset(&path[0], 0, sizeof(wchar_t) * (MAX_PATH + 1));
    ::GetModuleFileNameW(nullptr, &path[0], MAX_PATH);
    ::PathRemoveFileSpecW(&path[0]);

    ::PathAppendW(&path[0], L"front_end\\inspector.html");

    std::string pathA = "C:\\mycode\\miniblink\\third_party\\WebKit\\Source\\devtools\\front_end\\inspector.html";
    if (::PathFileExistsA(pathA.c_str())) {
        //wkeSetDebugConfig(m_wkeView, "showDevTools", pathA.c_str());
        wkeShowDevtools(m_wkeView, L"C:\\mycode\\miniblink\\third_party\\WebKit\\Source\\devtools\\front_end\\inspector.html", onShowDevtoolsCallback, nullptr);
        return;
    }
    
    if (::PathFileExistsW(&path[0])) {
        pathA = utf16ToChar(&path[0], CP_UTF8);
        wkeSetDebugConfig(m_wkeView, "showDevTools", pathA.c_str());       
    }
}

//////////////////////////////////////////////////////////////////////////

bool RootWindow::onCommand(UINT id) {
    switch (id) {
    case IDC_NAV_BACK:   // Back button
        wkeGoBack(m_wkeView);
        return true;
    case IDC_NAV_FORWARD:  // Forward button
        wkeGoForward(m_wkeView);
        return true;
    case IDC_NAV_RELOAD:  // Reload button
        wkeReload(m_wkeView);
        //wkeRunJS(m_wkeView, "try {var xx = document.getElementById('search-btn'); console.log('xx:' + xx); xx.click();}catch(e){console.log('e:' + e);}");
        return true;
    case IDC_NAV_STOP:  // Stop button
        wkeStopLoading(m_wkeView);
        return true;
    case IDC_NAV_TEST:
        onMoreCommand();

//////////////////////////////////////////////////////////////////////////
//         wkeRunJsByFrame(m_wkeView, wkeWebFrameGetMainFrame(m_wkeView),
//             "var htmlObj = document.getElementById(\"ne_wrap\");\n"
//             "var bodyObj =document.getElementsByTagName('body');\n"
//             "var computedStyle = document.defaultView.getComputedStyle(htmlObj, null);\n"
//             "console.log('htmlObj:' + computedStyle.overflowY);\n"
//             "computedStyle = document.defaultView.getComputedStyle(bodyObj[0], null);\n"
//             "console.log('bodyObj:' + computedStyle.overflowY);\n"
//             , true);
// 
//         static int count = 0;
//         if ((count % 2) == 0) {
//             wkeInsertCSSByFrame(m_wkeView, wkeWebFrameGetMainFrame(m_wkeView), "html { overflow:hidden; }");
//             OutputDebugStringA("hidden! \n");
//         } else {
//             wkeInsertCSSByFrame(m_wkeView, wkeWebFrameGetMainFrame(m_wkeView), "html { overflow:visible; }");
//             OutputDebugStringA("visible! \n");
//         }
//         count++;
//////////////////////////////////////////////////////////////////////////
        return true;
    }

    return false;
}

LRESULT CALLBACK rootWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

static void registerRootClass(HINSTANCE hInstance, const std::wstring& window_class, HBRUSH background_brush)
{
    // Only register the class one time.
    static bool classRegistered = false;
    if (classRegistered)
        return;
    classRegistered = true;

    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = rootWndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WKEXE));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = background_brush;
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = window_class.c_str();
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassEx(&wcex);
}

void RootWindow::onWkeUrlChangedCallback2(wkeWebView webView, void* param, wkeWebFrameHandle frame, const wkeString url)
{
    RootWindow* self = (RootWindow*)param;

    if (wkeIsMainFrame(webView, frame)) {
        const wchar_t* urlString = wkeToStringW(url);
        ::SetWindowText(self->m_editHwnd, urlString);
    }

    const utf8* ux = wkeGetURL(self->m_wkeView);

    ::EnableWindow(self->m_backHwnd, wkeCanGoBack(self->m_wkeView));
    ::EnableWindow(self->m_forwardHwnd, wkeCanGoForward(self->m_wkeView));
}

wkeWebView RootWindow::createRootWindow()
{
    RECT startRect;
    startRect.left = 400;
    startRect.top = 200;
    startRect.right = startRect.left + 1080;
    startRect.bottom = startRect.top + 680;
    const DWORD dwStyle = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN;

    const std::wstring& window_title = L"Miniblink";
    const std::wstring& window_class = L"MBRootWindow";

    HINSTANCE hInstance = GetModuleHandle(NULL);
    registerRootClass(hInstance, window_class, nullptr);

    int x, y, width, height;
    if (::IsRectEmpty(&startRect)) {
        // Use the default window position/size.
        x = y = width = height = CW_USEDEFAULT;
    } else {
        // Adjust the window size to account for window frame and controls.
        RECT window_rect = startRect;
        ::AdjustWindowRectEx(&window_rect, dwStyle, false, 0);

        x = startRect.left;
        y = startRect.top;
        width = window_rect.right - window_rect.left;
        height = window_rect.bottom - window_rect.top;
    }

    // Create the main window initially hidden.
    m_hWnd = CreateWindow(window_class.c_str(), window_title.c_str(),
        dwStyle,
        x, y, width, height,
        NULL, NULL, hInstance, NULL);

    setUserDataPtr(m_hWnd, this);

    createChildControl(m_hWnd);

    wkeWebView wkeView = wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL, m_hWnd, 0, urlbarHeight, width - 8, height - urlbarHeight - 20);

//     wkeWindowCreateInfo info;
//     info.size = sizeof(wkeWindowCreateInfo);
//     info.styleEx = 0;
//     info.style = WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
//     info.x = 0;
//     info.y = urlbarHeight;
//     info.width = width - 8;
//     info.height = height - urlbarHeight - 20;
//     info.parent = m_hWnd;
//     info.color = 0x00ffffff;
//     wkeWebView wkeView = wkeCreateWebCustomWindow(&info);

    setWkeView(wkeView);

    wkeOnURLChanged2(wkeView, onWkeUrlChangedCallback2, this);

    ::ShowWindow(m_hWnd, SW_SHOW);
    ::UpdateWindow(m_hWnd);
    ::SetTimer(m_hWnd, 0x1223, 5, nullptr);


//     const int guardbandSize = 8;
//     FILE* fs;
//     fopen_s(&fs, "C:\\Users\\weo\\AppData\\Local\\Temp\\Thunder Network\\Thunder7.9\\JumpIcon\\00000000000000000000.ico", "rb");
//     fseek(fs, 0, SEEK_END); 
//     int dwSize = ftell(fs); 
//     fseek(fs, 0, SEEK_SET);
//     char* memory = new char[dwSize + guardbandSize];
//     fread(memory, 1, dwSize, fs);
//     //memset(memory + dwSize, 0, guardbandSize);
//     fclose(fs);
//     //HICON hIcon = ::CreateIconFromResource((PBYTE)memory, dwSize, TRUE, 0x00030000);
//     HICON hIcon = CreateIconFromResourceEx(
//         (PBYTE)memory,
//         dwSize,
//         TRUE,
//         0x00030000,
//         0, 0,
//         LR_DEFAULTSIZE | LR_DEFAULTCOLOR
//         );
// 
//     char* output = (char*)malloc(0x100);
//     sprintf_s(output, 0x99, "hIcon: %x %x\n", hIcon, GetLastError());
//     OutputDebugStringA(output);
//     free(output);
// 
//     delete memory;

    //

    return wkeView;
}

void RootWindow::onPaint()
{
    PAINTSTRUCT ps;
    ::BeginPaint(m_hWnd, &ps);

    if (!m_hbrush)
        m_hbrush = ::CreateSolidBrush(0xffffffff);
    ::SelectObject(ps.hdc, m_hbrush);
    ::Rectangle(ps.hdc, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right - ps.rcPaint.left, ps.rcPaint.bottom - ps.rcPaint.top);

    ::EndPaint(m_hWnd, &ps);
}

void RootWindow::onSize(bool minimized)
{
    RECT rect;
    ::GetClientRect(m_hWnd, &rect);
    // Resize the window and address bar to match the new frame size.
    rect.top += urlbarHeight;

    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;

    int urloffset = rect.left + buttonWidth * 5;

    // Resize just the URL edit field.
    ::SetWindowPos(m_editHwnd, NULL, urloffset, 0, rect.right - urloffset, urlbarHeight, SWP_NOZORDER);
    wkeResizeWindow(m_wkeView, width, height);
    //wkeWake(m_wkeView);
}

void RootWindow::onFocus()
{
//     HWND hWnd = wkeGetHostHWND(m_wkeView);
//     wkeSetFocus(m_wkeView);
//     ::SetCapture(hWnd);
}

void RootWindow::onWheel(WPARAM wParam, LPARAM lParam)
{
    int x = LOWORD(lParam);
    int y = HIWORD(lParam);

    unsigned int flags = 0;

    if (wParam & MK_CONTROL)
        flags |= WKE_CONTROL;
    if (wParam & MK_SHIFT)
        flags |= WKE_SHIFT;

    if (wParam & MK_LBUTTON)
        flags |= WKE_LBUTTON;
    if (wParam & MK_MBUTTON)
        flags |= WKE_MBUTTON;
    if (wParam & MK_RBUTTON)
        flags |= WKE_RBUTTON;

    int delta = GET_WHEEL_DELTA_WPARAM(wParam);
    wkeFireMouseWheelEvent(m_wkeView, x, y, delta, flags);
}

void RootWindow::onTimer()
{
//     if (rand() % 3 == 0) {
//         wkeFireMouseEvent(m_wkeView, WM_LBUTTONDOWN, 125, 305, 0);
//         wkeFireMouseEvent(m_wkeView, WM_LBUTTONUP, 125, 305, 0);
//     } else {
//         wkeFireMouseEvent(m_wkeView, WM_LBUTTONDOWN, 143, 350, 0);
//         wkeFireMouseEvent(m_wkeView, WM_LBUTTONUP, 143, 350, 0);
//     }
}

LRESULT CALLBACK rootWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    RootWindow* self = getUserDataPtr<RootWindow*>(hWnd);
    if (!self)
        return ::DefWindowProc(hWnd, message, wParam, lParam);

    // Callback for the main window
    switch (message) {
    case WM_COMMAND:
        if (self->onCommand(LOWORD(wParam)))
            return 0;
        break;

    case WM_PAINT:
        self->onPaint();
        break;

    case WM_SIZE:
        self->onSize(wParam == SIZE_MINIMIZED);
        break;

    case WM_SETFOCUS:
        self->onFocus();
        return 0;

    case WM_KILLFOCUS:
        //wkeKillFocus(self->getWkeView());
        return 0;

    case WM_MOUSEWHEEL:
        self->onWheel(wParam, lParam);
        break;

    case WM_TIMER:
        self->onTimer();
        break;
// 
//     case WM_MOVING:
//     case WM_MOVE:
//         self->OnMove();
//         return 0;
// 
    case WM_ERASEBKGND:
//         if (self->OnEraseBkgnd())
//             break;
        // Don't erase the background.
        break;
// 
//     case WM_ENTERMENULOOP:
//         if (!wParam) {
//             // Entering the menu loop for the application menu.
//             CefSetOSModalLoop(true);
//         }
//         break;
// 
//     case WM_EXITMENULOOP:
//         if (!wParam) {
//             // Exiting the menu loop for the application menu.
//             CefSetOSModalLoop(false);
//         }
//         break;
// 
//     case WM_CLOSE:
//         if (self->OnClose())
//             return 0;  // Cancel the close.
//         break;
// 
//     case WM_NCHITTEST:
//     {
//         LRESULT hit = DefWindowProc(hWnd, message, wParam, lParam);
//         if (hit == HTCLIENT) {
//             POINTS points = MAKEPOINTS(lParam);
//             POINT point = { points.x, points.y };
//             ::ScreenToClient(hWnd, &point);
//             if (::PtInRegion(self->draggable_region_, point.x, point.y)) {
//                 // If cursor is inside a draggable region return HTCAPTION to allow
//                 // dragging.
//                 return HTCAPTION;
//             }
//         }
//         return hit;
//     }
// 
//     case WM_NCDESTROY:
//         // Clear the reference to |self|.
//         SetUserDataPtr(hWnd, NULL);
//         self->hwnd_ = NULL;
//         self->OnDestroyed();
//         return 0;
    }

    return ::DefWindowProc(hWnd, message, wParam, lParam);
}

#define MAX_URL_LENGTH 255
WNDPROC editWndProcOld = nullptr;

LRESULT CALLBACK RootWindow::editWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_CHAR:
        if (wParam == VK_RETURN) {
            HWND parent = GetParent(hWnd);
            RootWindow* self = getUserDataPtr<RootWindow*>(parent);

            // When the user hits the enter key load the URL.
            std::vector<wchar_t> strPtr;
            strPtr.resize(MAX_URL_LENGTH + 1);
            *((LPWORD)&strPtr[0]) = MAX_URL_LENGTH;
            LRESULT strLen = SendMessage(hWnd, EM_GETLINE, 0, (LPARAM)&strPtr[0]);
            if (strLen > 0) {
                strPtr[strLen] = 0;
                wkeLoadURLW(self->m_wkeView, &strPtr[0]);
            }

            return 0;
        }
        if (wParam == 1 && 0x1e0001 == lParam) {
            ::PostMessage(hWnd, EM_SETSEL, 0, -1);
        }
        break;
    case WM_NCDESTROY:
        // Clear the reference to |self|.
        break;
    }

    return CallWindowProc(editWndProcOld, hWnd, message, wParam, lParam);
}

void RootWindow::createChildControl(HWND parentHwnd)
{
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // Create the child controls.
    int xOffset = 0;

    RECT rect;
    ::GetClientRect(parentHwnd, &rect);

    // Create a scaled font.
    m_font = ::CreateFont(
        -fontHeight, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");

    m_backHwnd = ::CreateWindow(
        L"BUTTON", L"Back",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_DISABLED,
        xOffset, 0, buttonWidth, urlbarHeight,
        parentHwnd, reinterpret_cast<HMENU>(IDC_NAV_BACK), hInstance, 0);
    ::SendMessage(m_backHwnd, WM_SETFONT, reinterpret_cast<WPARAM>(m_font), TRUE);
    xOffset += buttonWidth;

    m_forwardHwnd = ::CreateWindow(
        L"BUTTON", L"Forward",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_DISABLED,
        xOffset, 0, buttonWidth, urlbarHeight,
        parentHwnd, reinterpret_cast<HMENU>(IDC_NAV_FORWARD), hInstance, 0);
    ::SendMessage(m_forwardHwnd, WM_SETFONT, reinterpret_cast<WPARAM>(m_font), TRUE);
    xOffset += buttonWidth;

    m_reloadHwnd = ::CreateWindow(
        L"BUTTON", L"Reload",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON /*| WS_DISABLED*/,
        xOffset, 0, buttonWidth, urlbarHeight,
        parentHwnd, reinterpret_cast<HMENU>(IDC_NAV_RELOAD), hInstance, 0);
    ::SendMessage(m_reloadHwnd, WM_SETFONT, reinterpret_cast<WPARAM>(m_font), TRUE);
    xOffset += buttonWidth;

    m_stopHwnd = ::CreateWindow(
        L"BUTTON", L"Stop",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_DISABLED,
        xOffset, 0, buttonWidth, urlbarHeight,
        parentHwnd, reinterpret_cast<HMENU>(IDC_NAV_STOP), hInstance, 0);
    ::SendMessage(m_stopHwnd, WM_SETFONT, reinterpret_cast<WPARAM>(m_font), TRUE);
    xOffset += buttonWidth;

    m_testHwnd = ::CreateWindow(
        L"BUTTON", L"Test",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        xOffset, 0, buttonWidth, urlbarHeight,
        parentHwnd, reinterpret_cast<HMENU>(IDC_NAV_TEST), hInstance, 0);
    ::SendMessage(m_testHwnd, WM_SETFONT, reinterpret_cast<WPARAM>(m_font), TRUE);
    xOffset += buttonWidth;

    m_editHwnd = ::CreateWindow(
        L"EDIT", 0,
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOVSCROLL |
        ES_AUTOHSCROLL /*| WS_DISABLED*/,
        xOffset, 0, rect.right - buttonWidth * 5, urlbarHeight,
        parentHwnd, 0, hInstance, 0);
    ::SendMessage(m_editHwnd, WM_SETFONT, reinterpret_cast<WPARAM>(m_font), TRUE);

    // Override the edit control's window procedure.
    editWndProcOld = setWndProcPtr(m_editHwnd, editWndProc);
}
