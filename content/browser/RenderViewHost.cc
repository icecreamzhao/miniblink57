
#include "content/browser/RenderViewHost.h"

#include "base/command_line.h"
#include "build/blink/Resource.h"
#include "cc/raster/task_graph_runner.h"
#include "cc/trees/layer_tree_host.h"
#include "content/browser/RenderWidgetCompositor.h"
#include "content/browser/WebPage.h"
#include "content/browser/compositor/BrowserSoftwareOutputDevice.h"
#include "skia/ext/platform_canvas.h"
#include "third_party/WebKit/Source/platform/weborigin/Referrer.h"
#include "ui/gfx/geometry/rect.h"

namespace content {

RenderViewHost::RenderViewHost()
{
    m_renderThread = nullptr;
}

RenderViewHost::~RenderViewHost()
{
    // delete
}

void RenderViewHost::init(HINSTANCE hInstance)
{
    m_hWnd = nullptr;
    m_blinkPage = nullptr;
    m_renderWidgetCompositor = nullptr;

    base::CommandLine::Init(0, nullptr);

    kWindowClass = L"MINIBLINK";
    registerClass(hInstance);

    // Must first NULL pointer or we hit a DCHECK that the newly constructed
    // message loop is the current one.
    base::MessageLoop* mainMessageLoop = (new base::MessageLoop(base::MessageLoop::TYPE_UI));
    m_uiThreadRunner = mainMessageLoop->task_runner().get();

    const char* kThreadName = "CrBrowserMain";
    base::PlatformThread::SetName(kThreadName);

    newWindow(hInstance);
}

void RenderViewHost::run()
{
    base::MessageLoop::current()->Run();
}

LPCWSTR kWindowClass;

ATOM RenderViewHost::registerClass(HINSTANCE hInstance)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = wndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MINIWEBKIT_BLINK));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCE(IDC_MINIWEBKIT_BLINK);
    wcex.lpszClassName = kWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassEx(&wcex);
}

void RenderViewHost::newWindow(HINSTANCE hInstance)
{
    m_hWnd = CreateWindow(kWindowClass, L"MINI_BLINK", WS_OVERLAPPEDWINDOW,
        //460, 250, 988, 613,
        460, 250, 588, 613,
        NULL, NULL, hInstance, this);

    if (!m_hWnd)
        return;

    createRenderView();

    ::ShowWindow(m_hWnd, TRUE);
    ::UpdateWindow(m_hWnd);
    ::SetTimer(m_hWnd, 10010, 50, NULL);
}

class TimerTaskObserver : public base::MessageLoop::TaskObserver {
public:
    TimerTaskObserver(RenderViewHost* parent)
    {
        m_parent = parent;
    }

    // This method is called before processing a task.
    virtual void WillProcessTask(const base::PendingTask& pending_task) override
    {
        //if (m_parent->blinkPage())
        //  m_parent->blinkPage()->fireTimerEvent();
    }

    // This method is called after processing a task.
    virtual void DidProcessTask(const base::PendingTask& pending_task) override
    {
        //if (m_parent->blinkPage())
        //  m_parent->blinkPage()->fireTimerEvent();
    }

protected:
    RenderViewHost* m_parent;
    virtual ~TimerTaskObserver() { }
};

void RenderViewHost::createRenderView()
{
    base::Thread* threadObj = (new base::Thread("Render"));
    threadObj->Start();
    threadObj->message_loop()->PostTask(FROM_HERE, base::Bind(&RenderViewHost::initRenderThread, base::Unretained(this)));
}

void RenderViewHost::runTimer()
{
    if (m_blinkPage)
        m_blinkPage->fireTimerEvent();
    base::MessageLoop::current()->PostDelayedTask(FROM_HERE, base::Bind(&RenderViewHost::runTimer, base::Unretained(this)), base::TimeDelta::FromMilliseconds(50));
}

void RenderViewHost::initRenderThread()
{
    base::SingleThreadTaskRunner* renderThread = content::WebPage::initOnImplThread();
    m_renderThread = renderThread;

    m_renderWidgetCompositor = new RenderWidgetCompositor();
    m_renderWidgetCompositor->initOnRenderThread(this, m_uiThreadRunner);

    WebPage::initOnBlinkThread();
    m_blinkPage = new content::WebPage(nullptr, nullptr);
    m_blinkPage->init(nullptr, this);

    m_uiThreadRunner->PostTask(FROM_HERE,
        base::Bind(&RenderWidgetCompositor::initOnUiThread, base::Unretained(m_renderWidgetCompositor)));
}

void RenderViewHost::onRenderWidgetCompositorInitFinishInRenderThread()
{
    m_uiThreadRunner->PostTask(FROM_HERE, base::Bind(&RenderWidgetCompositor::onHostResizedInUiThread, base::Unretained(m_renderWidgetCompositor), m_windowSize.cx, m_windowSize.cy));
    m_renderWidgetCompositor->onHostResizedInRenderThread();

    // Test
    LPWSTR loadPath = GetCommandLineW();
    while (L' ' != *loadPath && 0 != *loadPath) {
        ++loadPath;
    }
    ++loadPath;

    if (0) {
        m_blinkPage->loadURL(-1, L"www.mobile01.com", blink::Referrer(), nullptr);
        m_blinkPage->loadURL(-1, L"file:///C:/Users/debugwang/Desktop/test/bet365_dump.html", blink::Referrer(), nullptr);
    } else
        m_blinkPage->loadURL(-1, loadPath, blink::Referrer(), nullptr);

    base::MessageLoop::current()->AddTaskObserver(new TimerTaskObserver(this));
    runTimer();
    m_blinkPage->setFocus(true);

    OutputDebugStringA("RenderViewHost::loadURL\n");
}

LRESULT CALLBACK RenderViewHost::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    RenderViewHost* self = nullptr;
    if (message == WM_NCCREATE) {
        LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
        self = static_cast<RenderViewHost*>(lpcs->lpCreateParams);
        ::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LPARAM>(self));
    } else
        self = reinterpret_cast<RenderViewHost*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));

    if (self)
        return self->HostWndProc(hWnd, message, wParam, lParam);
    return ::DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT RenderViewHost::HostWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;

    BOOL bHandle = FALSE;
    LRESULT lResult = 0;

    switch (message) {
    case WM_COMMAND:
        wmId = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        switch (wmId) {
        case IDM_ABOUT:
            ::MoveWindow(hWnd, 460, 250, 393 + 8, 613, TRUE);
            if (m_renderThread)
                m_renderThread->PostTask(FROM_HERE, base::Bind(&WebPage::sendOrientationChangeEvent, base::Unretained(m_blinkPage)));
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        break;
    case WM_PAINT:
        PAINTSTRUCT ps;
        BeginPaint(hWnd, &ps);
        firePaintEvent(ps.hdc, &ps.rcPaint);
        EndPaint(hWnd, &ps);
        break;

    case WM_TIMER:
        if (m_renderWidgetCompositor)
            m_renderWidgetCompositor->fireTimerEvent();
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_SIZE:
        m_windowSizeLock.Acquire();
        m_windowSize.cx = LOWORD(lParam);
        m_windowSize.cy = HIWORD(lParam);
        m_windowSizeLock.Release();

        if (m_renderThread && m_renderWidgetCompositor && !m_renderWidgetCompositor->isResizing()) {
            m_renderThread->PostTask(FROM_HERE, base::Bind(&RenderWidgetCompositor::onHostResizedInRenderThread, base::Unretained(m_renderWidgetCompositor)));
        }
        break;
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_XBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MOUSEMOVE:
    case WM_MOUSELEAVE: // TODO debugwang
        if (m_blinkPage && m_renderThread) {
            m_renderThread->PostTask(FROM_HERE,
                base::Bind(&WebPage::fireMouseEvent, base::Unretained(m_blinkPage), nullptr, message, wParam, lParam));
        }
        break;
    case WM_SETCURSOR:
        if (m_blinkPage)
            lResult = m_blinkPage->fireCursorEvent(hWnd, message, wParam, lParam, bHandle);
        if (bHandle)
            return lResult;
        break;
    case WM_MOUSEWHEEL:
        //lResult = webPage->fireWheelEvent(hWnd, message, wParam, lParam, bHandle);
        break;
    case WM_KEYUP:
        if (m_blinkPage && m_renderThread) {
            m_renderThread->PostTask(FROM_HERE,
                base::Bind(&WebPage::fireKeyUpEvent, base::Unretained(m_blinkPage), nullptr, message, wParam, lParam));
        }
        break;
    case WM_KEYDOWN:
        if (m_blinkPage && m_renderThread) {
            m_renderThread->PostTask(FROM_HERE,
                base::Bind(&WebPage::fireKeyDownEvent, base::Unretained(m_blinkPage), nullptr, message, wParam, lParam));

            if (wParam == VK_F4)
                m_renderThread->PostTask(FROM_HERE, base::Bind(&WebPage::reload, base::Unretained(m_blinkPage)));
        }
        break;
    case WM_CHAR:
        if (m_blinkPage && m_renderThread) {
            m_renderThread->PostTask(FROM_HERE,
                base::Bind(&WebPage::fireKeyPressEvent, base::Unretained(m_blinkPage), nullptr, message, wParam, lParam));
        }
        break;
    }

    if (!bHandle)
        return DefWindowProc(hWnd, message, wParam, lParam);
    return lResult;
}

void RenderViewHost::initializeLayerTreeView()
{
    m_renderWidgetCompositor->initializeLayerTreeView();
}

void RenderViewHost::firePaintEvent(HDC hdc, const RECT* paintRect)
{
    if (m_renderWidgetCompositor)
        m_renderWidgetCompositor->firePaintEvent(hdc, paintRect);
}

} // content