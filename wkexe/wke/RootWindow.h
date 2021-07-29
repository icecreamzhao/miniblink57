#ifndef RootWindow_h
#define RootWindow_h

#include "G:/mycode/miniblink57/wke/wkedefine.h"

#define IDC_NAV_BACK                    200
#define IDC_NAV_FORWARD                 201
#define IDC_NAV_RELOAD                  202
#define IDC_NAV_STOP                    203
#define IDC_NAV_TEST                    204

class HideWndHelp;

class RootWindow {
public:
    const static int buttonWidth = 72;
    const static int urlbarHeight = 24;
    const static int fontHeight = 14;

    RootWindow();
    ~RootWindow();

    bool onCommand(UINT id);
    void onPaint();
    void onSize(bool minimized);
    void onShowDevtools();
    void onFocus();
    void onTimer();
    void onWheel(WPARAM wParam, LPARAM lParam);

    wkeWebView createRootWindow();

    void setWkeView(wkeWebView wkeView) { m_wkeView = wkeView; }
    wkeWebView getWkeView() const { return m_wkeView; }

    HWND getHwnd() const { return m_hWnd; }

    void createChildControl(HWND parentHwnd);

    static LRESULT CALLBACK editWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
    void onMoreCommand();
    LRESULT hideWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static void WKE_CALL_TYPE onWkeUrlChangedCallback2(wkeWebView webView, void* param, wkeWebFrameHandle frame, const wkeString url);

    HWND m_hWnd;
    wkeWebView m_wkeView;

    HFONT m_font;
    HWND m_backHwnd;
    HWND m_forwardHwnd;
    HWND m_reloadHwnd;
    HWND m_stopHwnd;
    HWND m_testHwnd;
    HWND m_editHwnd;
    HBRUSH m_hbrush;

    HMENU m_hMenu;
    HideWndHelp* m_hideWndHelp;
};

#endif // RootWindow_h