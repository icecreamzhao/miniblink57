
#define ENABLE_MB 1
#define _CRT_SECURE_NO_WARNINGS 1

//#define ENABLE_IN_MB_MAIN

#include "core/mb.h"

void TestDll()
{
    mbWebView mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, nullptr, 0, 0, 1200, 900);

    HWND hWnd = mbGetHostHWND(mbView);
    mbLoadURL(mbView, "file:///G:/test/exe_test/honghe_20200324/MathSubject/DyCourseware/GeoGebra/HTML5/5.0/previewggb.html");

    mbShowWindow(mbView, TRUE);
    ::ShowWindow(hWnd, SW_SHOW);
    ::UpdateWindow(hWnd);

    //MessageBoxA(0, 0, 0, 0);

    MSG msg = { 0 };
    while (true) {
        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (WM_QUIT == msg.message)
                break;

            ::TranslateMessage(&msg);
            ::DispatchMessageW(&msg);
        }
        ::mbWake(NULL_WEBVIEW);
        ::Sleep(5);
    }
}