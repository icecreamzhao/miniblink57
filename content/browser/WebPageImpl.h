#ifndef WebPageImpl_h
#define WebPageImpl_h

#include "base/rand_util.h"

namespace cc {
class LayerTreeHost;
}

namespace cef {
class BrowserHostImpl;
}

namespace blink {
class Color;
}

using namespace blink;

namespace content {

class WebFrameClientImpl;
class WebPage;

class WebPageImpl : public WebViewClient {
public:
    WebPageImpl(RenderViewHost* renderViewHost);
    ~WebPageImpl();

    static base::SingleThreadTaskRunner* initOnImplThread();
    static void initOnBlinkThread();

    virtual WebView* createView(WebLocalFrame* creator,
        const WebURLRequest& request,
        const WebWindowFeatures& features,
        const WebString& name,
        WebNavigationPolicy policy,
        bool suppressOpener) override;

    void init(WebPage* pagePtr, HWND hWnd);
    void windowCloseRequested();

    // WebViewClient
    virtual void didInvalidateRect(const WebRect&) override;
    virtual void didAutoResize(const WebSize& newSize) override;
    //virtual void didUpdateLayoutSize(const WebSize& newSize) override;
    virtual void scheduleAnimation() override;
    virtual WebLayerTreeView* initializeLayerTreeView() override;
    virtual WebStorageNamespace* createSessionStorageNamespace() override;

    // Return a compositing view used for this widget. This is owned by the
    // WebWidgetClient.
    /*virtual*/ WebLayerTreeView* layerTreeView() /*override*/;

    // WebWidgetClient
    virtual void didChangeCursor(const WebCursorInfo&) override;

    void clearPaintWhenLayeredWindow(SkCanvas* canvas, const IntRect& rect);

    // Merge any areas that would reduce the total area
    void mergeDirtyList()
    {
        while (doMergeDirtyList(true)) { };
    }

    bool doMergeDirtyList(bool forceMerge);

    void postPaintMessage(const IntRect* paintRect);

    void testPaint();

    void beginMainFrame(bool force);
    void doPaint(HDC hdc, const IntRect* paintRect);
    void schedulePaintEvent();

    void layout();

    void repaintRequested(const IntRect& windowRect);

    bool fireTimerEvent();
    void fireResizeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireCaptureChangedEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void firePaintEvent(HDC hdc, const RECT* paintRect);
    void fireKillFocusEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireMouseEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireTouchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    LRESULT fireCursorEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL& bHandle);
    LRESULT fireWheelEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL& bHandle);
    bool fireKeyUpEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    bool fireKeyDownEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    bool fireKeyPressEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    void sendOrientationChangeEvent();

    void setViewportSize(const IntSize& size);

    int m_debugCount;

    void drawDebugLine(SkCanvas* memoryCanvas, const IntRect& paintRect);

    void updateLayers(const IntRect& dirtyRect, SkCanvas* canvas, bool needsFullTreeSync);

    void setPainting(bool value) { m_painting = value; }

    void showDebugNodeData();

    bool needsCommit() { return m_needsCommit; }
    void setNeedsCommit() { m_needsCommit = true; }
    void clearNeedsCommit() { m_needsCommit = false; }
    //cc::LayerTreeHost* layerTreeHost() { return m_layerTreeHost; }

    void loadURL(int64 frameId, const wchar_t* url, const blink::Referrer& referrer, const wchar_t* extraHeaders);
    void loadRequest(int64 frameId, const blink::WebURLRequest& request);
    void loadHTMLString(int64 frameId, const WebData& html, const WebURL& baseURL, const WebURL& unreachableURL, bool replace);

    bool initSetting();

    CefBrowserHostImpl* browser() const;
    void setBrowser(CefBrowserHostImpl* browser);

    WebFrame* getWebFrameFromFrameId(int64 frameId);

    void setFocus(bool enabel);

    // ----

    bool m_useLayeredBuffer;

    IntRect m_winodwRect;
    IntRect m_clientRect; // 方便WebPage修改

    bool m_hasResize;

    bool m_postMouseLeave; // 系统的MouseLeave获取到的鼠标位置不太准确，自己在定时器里再抛一次

    RGBA32 m_bdColor;

    double m_lastFrameTimeMonotonic;
    WebPage* m_pagePtr;
    WebViewImpl* m_webViewImpl;

    bool m_mouseInWindow;

    HWND m_hWnd;
    bool m_isDraggableRegionNcHitTest;

    IntSize m_viewportSize;

    // May be NULL if the browser has not yet been created or if the browser has
    // been destroyed.
    CefBrowserHostImpl* m_browser;

    IntRect m_paintRect;
    SkCanvas* m_dirtyCanvas;
    SkCanvas* m_memoryCanvas;

    bool m_painting;
    bool m_canScheduleResourceLoader;

    Vector<IntRect> m_paintMessageQueue;
    static const int m_paintMessageQueueSize = 200;

    int m_postpaintMessageCount;
    int m_scheduleMessageCount;

    bool m_needsCommit;

    FrameLoaderClientImpl* m_frameLoaderClient;
    //RefPtr<LocalFrame> m_localFrame;

    ChromeClient* m_chromeClient;
    ContextMenuClient* m_contextMenuClient;
    EditorClient* m_editorClient;
    DragClient* m_dragClient;
    Page* m_page;

    enum WebPageState {
        INIT,
        UNINIT,
        DESTROYING
    } m_state;

    bool m_LMouseDown;
    bool m_RMouseDown;

    void* m_foreignPtr;

    bool m_isAlert;

    IntPoint m_lastPosForDrag;
    double m_lastMouseDownTime;

    WebFrameClientImpl* m_webFrameClient;

    KWebApiCallbackSet m_callbacks;

    bool m_bMouseTrack;

    KdPageDebugInfo m_debugInfo;

    BOOL* m_messageStackVar; // 给消息处理函数使用，保存地址。例如，WM_TIMER中调用DestroyWindow，
    // 窗口摧毁了，消息函数还在进入WM_TIMER的处理函数，导致野指针崩溃.

    WebCursorInfo::Type m_cursorType;

    RenderViewHost* m_renderViewHost;
};
} // blink

#endif // WebPageImpl_h