
#ifndef CONTENT_BROWSER_RENDERER_HOST_RENDER_VIEW_HOST_H_
#define CONTENT_BROWSER_RENDERER_HOST_RENDER_VIEW_HOST_H_

#include <windows.h>

#include "base/synchronization/lock.h"

namespace base {
class Thread;
class MessageLoop;
class SingleThreadTaskRunner;
}

namespace gfx {
class Rect;
}

class SkCanvas;

namespace content {

class WebPage;
class MessageLoop;
class RenderWidgetCompositor;

class RenderViewHost {
public:
    RenderViewHost();
    ~RenderViewHost();

    void init(HINSTANCE hInstance);

    void run();

    LPCWSTR kWindowClass;

    ATOM registerClass(HINSTANCE hInstance);

    void newWindow(HINSTANCE hInstance);
    void createRenderView();

    void runTimer();

    void initRenderThread();

    static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    LRESULT HostWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    void initializeLayerTreeView();

    WebPage* blinkPage() { return m_blinkPage; }

    RenderWidgetCompositor* renderWidgetCompositor() { return m_renderWidgetCompositor; }

    SIZE windowSize() { return m_windowSize; }

    HWND getPlatformHWND() { return m_hWnd; }

    void firePaintEvent(HDC hdc, const RECT* paintRect);

    void onRenderWidgetCompositorInitFinishInRenderThread();

    base::SingleThreadTaskRunner* getRenderThreadRunner() const
    {
        return m_renderThread;
    }

    base::SingleThreadTaskRunner* getUiThreadRunner() const
    {
        return m_uiThreadRunner;
    }

    SIZE getWindowSizeLocked()
    {
        m_windowSizeLock.Acquire();
        SIZE windowSize = m_windowSize;
        m_windowSizeLock.Release();
        return windowSize;
    }

private:
    base::SingleThreadTaskRunner* m_renderThread;
    base::SingleThreadTaskRunner* m_uiThreadRunner;
    RenderWidgetCompositor* m_renderWidgetCompositor;
    WebPage* m_blinkPage;
    HWND m_hWnd;

    SIZE m_windowSize;
    base::Lock m_windowSizeLock;
};

} // content

#endif // CONTENT_BROWSER_RENDERER_HOST_RENDER_VIEW_HOST_H_