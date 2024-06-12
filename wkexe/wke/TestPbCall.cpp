// testcall.cpp : 定义应用程序的入口点。
//

#include "testcall.h"
#include "wke.h"
#include <windows.h>

#define MAX_LOADSTRING 100

#define DEFINDE_WKE_DECLARE(funcName, returnVal, args)             \
    typedef returnVal (WINAPI* Pfn_##funcName)args;                \
    Pfn_##funcName funcName = nullptr;                             

#define DEFINDE_WKE_LOADER(funcName) \
    funcName = (Pfn_##funcName)::GetProcAddress(hMod, #funcName);

DEFINDE_WKE_DECLARE(wkepbCreateWebWindowAndLoadUrl, void*, (HWND hParentWnd, DWORD flag, const WCHAR* url));
DEFINDE_WKE_DECLARE(wkepbEnableDpi, void, (void*));
DEFINDE_WKE_DECLARE(wkepbGetUrl, const wchar_t*, (void*));
DEFINDE_WKE_DECLARE(wkepbSetMemoryCacheEnable, void, (void*, bool));
DEFINDE_WKE_DECLARE(wkepbSetNavigationToNewWindowEnable, void, (void*, bool));

void initFunc()
{
    HMODULE hMod = ::GetModuleHandleW(L"node.dll");
    DEFINDE_WKE_LOADER(wkepbEnableDpi);
    DEFINDE_WKE_LOADER(wkepbCreateWebWindowAndLoadUrl);
    DEFINDE_WKE_LOADER(wkepbGetUrl);
    DEFINDE_WKE_LOADER(wkepbSetMemoryCacheEnable);
    DEFINDE_WKE_LOADER(wkepbSetNavigationToNewWindowEnable);
}

static HHOOK g_hMouseHook = nullptr;

LRESULT CALLBACK resizeHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (HCBT_MOVESIZE == nCode) {
        HWND hWnd = (HWND)wParam;
    }

    return ::CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
}

//////////////////////////////////////////////////////////////////////////
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING] = L"testCallTile";
WCHAR szWindowClass[MAX_LOADSTRING] = L"testCallClass";

ATOM                registerClass(HINSTANCE hInstance);
BOOL                initInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY testPbCallMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    registerClass(hInstance);

    if (!initInstance(hInstance, nCmdShow))
        return FALSE;

    HACCEL hAccelTable = ::LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TESTCALL));

    MSG msg;

    // 主消息循环: 
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    wkeShutdown();

    return (int)msg.wParam;
}

ATOM registerClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = ::LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TESTCALL));
    wcex.hCursor = ::LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TESTCALL);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = ::LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

void* g_wkeHandle = nullptr;

BOOL initInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 将实例句柄存储在全局变量中

    HWND hWnd = ::CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        500, 500, 800, 600, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
        return FALSE;

    ::ShowWindow(hWnd, nCmdShow);
    ::UpdateWindow(hWnd);

    initFunc();

    // L"file:///E:/test/w3school/wkejs.htm"
    g_wkeHandle = wkepbCreateWebWindowAndLoadUrl(hWnd, 0, L"https://www.baidu.com/");
    wkepbEnableDpi(g_wkeHandle);
    wkepbSetMemoryCacheEnable(g_wkeHandle, false);
    wkepbSetNavigationToNewWindowEnable(g_wkeHandle, false);

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 分析菜单选择: 
        switch (wmId) {
        case IDM_ABOUT:
            ::DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            ::DestroyWindow(hWnd);
            break;
        default:
            return ::DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = ::BeginPaint(hWnd, &ps);
        // TODO: 在此处添加使用 hdc 的任何绘图代码...
        ::EndPaint(hWnd, &ps);
        if (0) {
            const wchar_t* url = wkepbGetUrl(g_wkeHandle);
            url = nullptr;
        }
    }
    break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        break;
    default:
        return ::DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            ::EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
