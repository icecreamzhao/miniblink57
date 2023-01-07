// Tutorial.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "Tutorial.h"
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#include "../../../mbvip/core/mb.h"
#include "CWndSimple.h"
#include "CWndBrowser.h"
#include "CWndChart.h"


#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TUTORIAL));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    //wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TUTORIAL);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 将实例句柄存储在全局变量中

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 在此处添加使用 hdc 的任何绘图代码...

        RECT rcClient;
        ::GetClientRect(hWnd, &rcClient);

        HBRUSH hbr = (HBRUSH)::GetStockObject(GRAY_BRUSH); // 绘制背景色
        ::FillRect(hdc, &rcClient, hbr);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


void createWndTrans()
{
    mbWebView window = mbCreateWebWindow(MB_WINDOW_TYPE_TRANSPARENT, NULL, 0, 0, 536, 358);

    const char* url = "http://baidu.com";// GetInterfaceLibraryInfo()->getQiYouWebBaseUrl() + "/user";
    mbLoadURL(window, url);
    mbMoveToCenter(window);
    mbShowWindow(window, TRUE);
}

void createWndBrowser()
{
    CWndBrowser* rootWin = new CWndBrowser();
    rootWin->createWnd();
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TUTORIAL, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    TCHAR szMbPath[MAX_PATH];
    ::GetModuleFileName(NULL, szMbPath, MAX_PATH);
    ::PathRemoveFileSpec(szMbPath);
    //::PathAppendW(szMbPath, L"..\\..\\miniblink.dll");
    ::PathAppendW(szMbPath, L"..\\..\\..\\out\\Windows_Debug_Win32\\miniblink.dll");

	if (!::PathFileExists(szMbPath)) {
		::MessageBoxW(NULL, szMbPath, L"miniblink.dll没找到，请放到下面路径：", MB_OK);
		return 0;
	}

    //// 这个是wke窗口，跟mb窗口不兼容，不能调用mbInit，不然不能初始化wke
    //createWndChart();
    //return 0;

    mbSettings settings;
    memset(&settings, 0, sizeof(settings));
    //settings.mask = MB_ENABLE_NODEJS;
    mbSetMbMainDllPath(szMbPath);
    mbInit(&settings);

    // 显示mb窗口
    //createWndTrans(); 
    createWndSimple();
    //createWndBrowser();

    // 显示win32窗口
    //// 执行应用程序初始化:   
    //if (!InitInstance (hInstance, nCmdShow))
    //{
    //    return FALSE;
    //}

	MSG msg;

    // 主消息循环:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

    mbUninit();

	return (int) msg.wParam;
}

