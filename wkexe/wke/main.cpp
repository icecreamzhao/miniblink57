
#define _CRT_SECURE_NO_WARNINGS 1

#include "app.h"
#include <vector>
#include <ShObjIdl.h>
#include <ShlObj.h>
#include <Shlwapi.h>
#include <string>

#include "G:/mycode/mb/wkexe/gwkemgr.h"

int APIENTRY testPbCallMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow);
int APIENTRY wkeBrowserMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow);
int ToolsMain(HINSTANCE hInstance);
int bugMain();
int MtRenderMain();
int testmain2(LPCTSTR args[], int argc);

void readJsFile(const char* path, std::vector<char>* buffer)
{
    HANDLE hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        DebugBreak();
        return;
    }

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
    b = b;
}

int saveDumpFile(const char* path, char* buffer, unsigned int size)
{
    void* hFile = CreateFileA(path, GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if ((void*)-1 != hFile) {
        DWORD dwSize = 0;
        WriteFile(hFile, buffer, size, &dwSize, NULL);
        CloseHandle(hFile);
        return 1;
    }
    return 0;
}

void toHex()
{
    std::vector<char> buffer;
    readJsFile("E:\\mycode\\miniblink49\\trunk\\node\\lib\\util.js", &buffer);
    // const unsigned char util_native[] = { 
    std::string result = "const unsigned char util_native[] = { ";
    for (size_t i = 0; i < buffer.size(); ++i) {
        char hex[0x30] = { 0 };
        sprintf_s(hex, 0x29, "%d,", buffer[i]);
        result += hex;
    }
    result += "};";
}

void fixChromiumVirusHtml(const wchar_t * lpPath);

void changeCRLF(const wchar_t * lpPath);
void changeCrlfPath(const wchar_t * lpPath);
int main2(LPCTSTR args[], int argc);
int mb_simple_demo();
void findVueBloomMenu(const wchar_t * lpPath);

LRESULT CALLBACK testWhiteScreenWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  // Callback for the main window
  switch (message) {
  case WM_CLOSE:
    ::ExitProcess(0);
    break;
  }
  return ::DefWindowProc(hWnd, message, wParam, lParam);
}

HWND g_testWhiteScreenhWnd = NULL;
class WkeBinderImpl : public WkeBinder {
public:
  WkeBinderImpl()
  {
    m_hDC = ::CreateCompatibleDC(0);
  }

  void createBitmap()
  {
    BITMAPINFO bi = { 0 };
    memset(&bi, 0, sizeof(bi));
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = (int)m_width;
    bi.bmiHeader.biHeight = -(int)m_height;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;

    HBITMAP hbmp = ::CreateDIBSection(0, &bi, DIB_RGB_COLORS, &m_pixels, NULL, 0);
    hbmp = (HBITMAP)SelectObject(m_hDC, hbmp);
    if (hbmp)
      DeleteObject(hbmp);
  }

  static LRESULT CALLBACK signWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
  {
    // Callback for the main window
    switch (message) {
    case WM_CREATE:
      wkeInitialize();
      break;
    case WM_CLOSE:
      ::ExitProcess(0);
      break;
    }
    return ::DefWindowProc(hWnd, message, wParam, lParam);
  }

  void createSignWnd()
  {
    static bool s_init = false;
    if (s_init)
      return;
    s_init = true;

    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = &signWndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = NULL;
    wcex.hIcon = NULL;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = NULL;
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = L"createSignWnd";
    wcex.hIconSm = NULL;

    RegisterClassEx(&wcex);

    CreateWindow(L"createSignWnd", L"createSignWnd",
      0,
      0, 0, 500, 600,
      NULL, NULL, NULL, NULL);
  }

  void on_paint_bit_updated(const void* buffer, const wkeRect* r) override
  {
    if (m_pixels == nullptr) {
      if (m_width != r->w || m_height != r->h)
        return;
      createBitmap();

      createSignWnd();
    }

    memcpy(m_pixels, buffer, r->w * r->h * 4);

    HDC hScreenDC = ::GetDC(m_hwnd);
    //::BitBlt(m_hDC, r->x, r->y, m_width, m_height, m_hDC, r->x, r->y, SRCCOPY);
    ::BitBlt(hScreenDC, r->x, r->y, m_width, m_height, m_hDC, r->x, r->y, SRCCOPY);
    ::ReleaseDC(m_hwnd, hScreenDC);
  }

  void on_url_changed(const wkeString url) override
  {

  }

  int m_width = 500;
  int m_height = 600;
  HDC m_hDC = nullptr;
  void* m_pixels = nullptr;
  HWND m_hwnd = nullptr;
  wkeWebView m_hView = nullptr;
};

void createTestWhiteScreen()
{
  wkeSetWkeDllPath(L"G:\\mycode\\mb\\out\\Release_vc6\\node.dll");

  WNDCLASSEX wcex;

  wcex.cbSize = sizeof(WNDCLASSEX);

  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = testWhiteScreenWndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = NULL;
  wcex.hIcon = NULL;
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = NULL;
  wcex.lpszMenuName = nullptr;
  wcex.lpszClassName = L"wWinMain";
  wcex.hIconSm = NULL;

  RegisterClassEx(&wcex);

  g_testWhiteScreenhWnd = CreateWindow(L"wWinMain", L"wWinMain",
    0,
    0, 0, 500, 600,
    NULL, NULL, NULL, NULL);
  ShowWindow(g_testWhiteScreenhWnd, SW_SHOW);

  GWkeMgr* mgr = GWkeMgr::instance();
  WkeBinderImpl* wkeBinderImpl = new WkeBinderImpl();
  wkeBinderImpl->m_hwnd = g_testWhiteScreenhWnd;
  wkeBinderImpl->m_hView = mgr->add_browser(wkeBinderImpl);
  wkeResize(wkeBinderImpl->m_hView, 500, 600);

  wkeRunMessageLoop();
}

int WINAPI wWinMain(
    __in HINSTANCE hInstance,
    __in_opt HINSTANCE hPrevInstance,
    __in LPWSTR lpCmdLine,
    __in int nCmdShow
    )
{
//   char* ret = add_fragment("http://a.com/", "http://b.com/#123");
//   return 0;
    //printStdcall();
    //return 0;
    //findVueBloomMenu(L"e:\\");
    //return 0;         
    // ::OleInitialize(nullptr);

    //return mb_simple_demo();
//     changeCRLF(L"E:\\mycode\\mtmb\\mtmb\\Media\\FlashPlugin.cpp");
//      return 0;
//     main2(nullptr, 0);
//     return 0;
    // saveDumpFile("E:\\mycode\\miniblink49\\trunk\\out\\Release_NoNode\\dumpzlib\\dumpzlib_all.dat", bufferAll.data(), bufferAll.size());

    //return testEncode();
    //return ToolsMain(hInstance);
    //return wkeBrowserMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
    //return testPbCallMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
    //return bugMain();
    //return MtRenderMain();
    //return testmain2(nullptr, 0);
    //fixChromiumVirusHtml(L"E:\\mycode\\chromium.bb_master\\src\\");
    //wkeSetWkeDllPath(L"G:\\mycode\\mb\\out\\Release_NoNode\\node.dll");

#ifdef _WIN64
    wkeSetWkeDllPath(L"miniblink_x64.dll");
#endif
    //wkeSetWkeDllPath(L"node_v8_7_5.dll");
    //wkeSetWkeDllPath(L"G:\\test\\exe_test\\memory_load\\build\\mbsplit\\dlls\\mbsplit.dll");

    wkeSettings settings;
    memset(&settings, 0, sizeof(wkeSettings));

//     settings.mask = WKE_SETTING_PROXY;
//     settings.proxy.type = WKE_PROXY_SOCKS5;
//     strcpy(settings.proxy.hostname, "192.168.81.1");
//     settings.proxy.port = 1080;
    wkeInitializeEx(&settings);

    wkeEnableHighDPISupport();

//     wkeSetDebugConfig(nullptr, "v8flags", "--turbo");
//     wkeSetDebugConfig(nullptr, "v8flags", "--block_concurrent_recompilation");

//     wkeWebView webview = wkeCreateWebWindow(WKE_WINDOW_TYPE_POPUP, NULL, 0, 0, 600, 600);
//     wkeLoadURL(webview, "https://www.w3school.com.cn/tiy/t.asp?f=html_select");
//     wkeShowWindow(webview, true);
// 
//     MSG msg = { 0 };
//     while (GetMessageW(&msg, NULL, 0, 0)) {
//         TranslateMessage(&msg);
//         DispatchMessageW(&msg);
//     }
//     return 0;

    Application app = { 0 };
    runApplication(&app);
#ifdef _DEBUG
    wkeShutdownForDebug();
#endif
    return 0;
}
