#include <windows.h>
#include <commctrl.h>
#include <xstring>

HINSTANCE m_hInst;

// Menu-item identifiers 

#define IDM_SOLID       PS_SOLID 
#define IDM_DASH        PS_DASH 
#define IDM_DASHDOT     PS_DASHDOT 
#define IDM_DASHDOTDOT  PS_DASHDOTDOT 

#define IDM_PIE  1 
#define IDM_LINE 2 
#define IDM_BAR  3 

// Line-type flags  

#define SOLID       0 
#define DOT         1 
#define DASH        2 
#define DASHDOT     3 
#define DASHDOTDOT  4 

// Count of pens  

#define CPENS 5 

// Chart-type flags  

#define PIE  1 
#define LINE 2 
#define BAR  3 

class ToolsTip {
public:
    void init()
    {
        m_isShow = false;
        registerClass();
        m_hTipWnd = CreateWindowEx(0, L"MbToolsTip", L"Win32 Controls", WS_POPUP | WS_MINIMIZEBOX, 300, 400, 225, 140, HWND_DESKTOP, NULL, nullptr, this);
        ::SetPropW(m_hTipWnd, L"ToolsTip", (HANDLE)this);
        ::ShowWindow(m_hTipWnd, SW_SHOW);

        m_hFont = CreateFont(18, 0, 0, 0, FW_THIN, FALSE, FALSE, FALSE,
            GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, L"宋体");
    }

    ~ToolsTip()
    {
        ::DeleteObject(m_hFont);
    }

    bool registerClass()
    {
        WNDCLASSEX wcex;

        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DROPSHADOW;
        wcex.lpfnWndProc = wndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = nullptr;
        wcex.hIcon = nullptr;
        wcex.hCursor = LoadCursor(0, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = 0;
        wcex.lpszClassName = L"MbToolsTip";
        wcex.hIconSm = nullptr;
        return !!RegisterClassEx(&wcex);
    }

    void show(const WCHAR* text)
    {
    }

    static HMENU m_popMenu;

    static VOID APIENTRY DisplayContextMenu(HWND hWnd, const POINT& pt)
    {
        const int IDM_OPT1 = 1;
        const int IDM_OPT2 = 2;

        if (!m_popMenu)
            m_popMenu = ::CreatePopupMenu();
        // 一种方法是使用AppendMenu函数
        //::AppendMenu(hRoot, MF_POPUP, (UINT_PTR)pop1, L"操作");
        ::AppendMenu(m_popMenu, MF_STRING, IDM_OPT1, L"飞机");

        // 另一种方法是使用InsertMenuItem函数
        MENUITEMINFO mif;
        mif.cbSize = sizeof(MENUITEMINFO);
        mif.cch = 100;
        mif.dwItemData = NULL;
        mif.dwTypeData = L"机关枪";
        mif.fMask = MIIM_ID | MIIM_STRING | MIIM_STATE;
        mif.fState = MFS_ENABLED;
        mif.fType = MIIM_STRING;
        mif.wID = IDM_OPT2;

        ::InsertMenuItem(m_popMenu, IDM_OPT2, FALSE, &mif);
        ::TrackPopupMenu(m_popMenu, TPM_LEFTALIGN | TPM_TOPALIGN | TPM_RIGHTBUTTON,
            pt.x, pt.y, 0, (HWND)hWnd,
            NULL);

        // Destroy the menu. 
        //DestroyMenu(m_popMenu);
    }

    static LRESULT CALLBACK wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        static HPEN hpen[CPENS];
        static HBITMAP hbmp[CPENS];
        int i;

        switch (uMsg) {
        case WM_CREATE:
            break;

        case WM_RBUTTONUP: {
            POINT pt = { 100, 200 };
            DisplayContextMenu(hWnd, pt);
            break;
        }
        case WM_CONTEXTMENU: {
            POINT pt = { 100, 200 };

            break;
        }
        case WM_DESTROY:

            for (i = 0; i < CPENS; i++) {
                DeleteObject(hbmp[i]);
                DeleteObject(hpen[i]);
            }

            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        }
        return NULL;
    }

private:
    HWND m_hTipWnd;
    HFONT m_hFont;
    bool m_isShow;
    static const int m_kTimerId = 1;
    std::wstring m_text;
};

HMENU ToolsTip ::m_popMenu = nullptr;

int ToolsMain(HINSTANCE hInstance)
{
    m_hInst = hInstance;

    ToolsTip tip;
    tip.init();
    tip.show(L"sdafsa的df");

    MSG msg = { 0 };
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}