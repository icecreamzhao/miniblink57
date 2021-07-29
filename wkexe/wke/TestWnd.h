
static LPCWSTR kPopupWindowClassName2 = L"PopupWindowClass";

HWND m_hPopup = NULL;
LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK popupMenuWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    return wndProc(hWnd, message, wParam, lParam);
}

void registerClass() {
    static bool haveRegisteredWindowClass = false;
    if (haveRegisteredWindowClass)
        return;

    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.hIconSm = 0;
    wcex.style = 0;// CS_DROPSHADOW;

    wcex.lpfnWndProc = popupMenuWndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = sizeof(void*); // For the PopupMenu pointer
    wcex.hInstance = NULL;
    wcex.hIcon = 0;
    wcex.hCursor = LoadCursor(0, IDC_ARROW);
    wcex.hbrBackground = 0;
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = kPopupWindowClassName2;

    haveRegisteredWindowClass = true;

    RegisterClassEx(&wcex);
}

void onPaint(HWND hWnd, HDC hdc) {
    HBRUSH hbrush;
    hbrush = ::CreateSolidBrush(rand()); // ´´½¨À¶É«»­Ë¢
    ::SelectObject(hdc, hbrush);
    ::Rectangle(hdc, 0, 0, 366, 266);
    ::DeleteObject(hbrush);
}

LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    LRESULT lResult = 0;

    char* outstring = new char[200];
    sprintf_s(outstring, 199, "wndProc: %04x\n", message);
    OutputDebugStringA(outstring);
    delete outstring;

    switch (message) {
    case WM_MOUSEMOVE:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONUP: {
        if (WM_LBUTTONDOWN == message)
            OutputDebugStringA("WM_LBUTTONDOWN !~\n");
        if (WM_LBUTTONUP == message)
            OutputDebugStringA("WM_LBUTTONUP !~\n");

        break;
    }
    case WM_MOUSEWHEEL:

        break;

    case WM_SYSKEYDOWN:
    case WM_KEYDOWN: {

        break;
    }
    case WM_CHAR: {
        lResult = 0;
        switch (wParam) {
        case 0x0D:   // Enter/Return
                     //m_popupImpl->close();
                     //             index = focusedIndex();
                     //             ASSERT(index >= 0);
                     //             client()->valueChanged(index);
            break;
        case 0x1B:   // Escape
                     //m_popupImpl->close();
            break;
        case 0x09:   // TAB
        case 0x08:   // Backspace
        case 0x0A:   // Linefeed
        default:     // Character
            lResult = 1;
            break;
        }
        break;
    }

    case WM_PAINT: {
        PAINTSTRUCT paintInfo;
        ::BeginPaint(hWnd, &paintInfo);
        onPaint(hWnd, paintInfo.hdc);
        ::EndPaint(hWnd, &paintInfo);
        OutputDebugStringA("WM_PAINT\n");
        return 0;
        break;
    }
    case WM_PRINTCLIENT:
        onPaint(hWnd, (HDC)wParam);
        break;
    case WM_GETOBJECT:
        //onGetObject(wParam, lParam, lResult);
        break;

    case WM_TIMER:
        ::SetWindowPos(hWnd, HWND_TOP, 220, 220, 100, 200, /*SWP_NOMOVE | SWP_NOSIZE | */ SWP_SHOWWINDOW /*| SWP_NOACTIVATE*/);
        //::ShowWindow(hWnd, SW_SHOWNOACTIVATE);
        ::KillTimer(hWnd, 1);
        OutputDebugStringA("WM_TIMER\n");
        break;
    case WM_KILLFOCUS:
        ::ShowWindow(hWnd, SW_HIDE);
        ::SetWindowLongPtr(m_hPopup, 0, 0);
        break;
//     case WM_INIT_MENU:
//         initialize();
//         break;
//     case WM_COMMIT:
//         beginMainFrame();
//         break;
    case WM_MOUSEACTIVATE:
        lResult = MA_NOACTIVATE;
        break;
    default:
        lResult = ::DefWindowProc(hWnd, message, wParam, lParam);
    }

    return lResult;
}

void asynStartCreateWnd(HWND parent) {
    registerClass();

    if (!m_hPopup) {
        m_hPopup = CreateWindowEx(WS_EX_NOACTIVATE, kPopupWindowClassName2, L"MbPopupMenu2", WS_POPUP /*| WS_DISABLED*/,
            499, 400, 10, 20, parent, 0, 0, nullptr);
    }
    
    ::ShowWindow(m_hPopup, SW_HIDE);
    ::SetTimer(m_hPopup, 1, 2000, nullptr);
}