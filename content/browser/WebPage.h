
#ifndef WebPage_h
#define WebPage_h

#include "KdGuiApi.h"
#include "KdGuiApiImp.h"
#include "KdPageInfo.h"
#include "third_party/WebKit/Source/platform/geometry/IntPoint.h"
#include "third_party/WebKit/Source/platform/geometry/IntRect.h"
#include "third_party/WebKit/Source/platform/geometry/IntSize.h"
#include "third_party/WebKit/Source/wtf/Allocator.h"
#include "third_party/WebKit/public/web/WebViewClient.h"

class CefBrowserHostImpl;

namespace blink {
class Page;
class Frame;
class LocalFrame;
class WebLocalFrame;
class WebViewImpl;
class FrameLoaderClientImpl;
class WebFrameClient;
class ChromeClient;
class ContextMenuClient;
class EditorClient;
class DragClient;
struct Referrer;
}

using namespace blink;

namespace base {
class SingleThreadTaskRunner;
}

namespace content {

class WebPageImpl;
struct AsynchronousResLoadInfo;
class WebFrameClientImpl;
class RenderViewHost;

struct KWebApiCallbackSet {
    PFN_KdPageCallback m_xmlHaveFinished;
    PFN_KdPageWinMsgCallback m_msgPreCallBack;
    PFN_KdPageWinMsgCallback m_msgPostCallBack;
    PFN_KdPageCallback m_unintCallBack;
    PFN_KdPageScriptInitCallback m_scriptInitCallBack;
    PFN_KdResCallback m_resHandle;
    PFN_KdResCallback m_resOtherNameQuery;
    PFN_KdPagePaintCallback m_paint;
    //NPInvokeFunctionPtr m_javascriptCallCppPtr;
};

class WebPage {
    USING_FAST_MALLOC(WebPage);

public:
    enum RenderLayer {
        ContentsLayer = 0x10,
        ScrollBarLayer = 0x20,
        PanIconLayer = 0x40,
        AllLayers = 0xff
    };

    static base::SingleThreadTaskRunner* initOnImplThread();
    static void initOnBlinkThread();

    WebPage(KdGuiObjPtr kdGuiObj, void* foreignPtr);
    ~WebPage();

    bool init(HWND hWnd, RenderViewHost* renderViewHostImpl);

    void windowCloseRequested();

    void javaScriptAlert(String& message);

    void loadURL(int64 frameId, const wchar_t* url, const blink::Referrer& referrer, const wchar_t* extraHeaders);
    void loadRequest(int64 frameId, const blink::WebURLRequest& request);
    void loadHTMLString(int64 frameId, const WebData& html, const WebURL& baseURL, const WebURL& unreachableURL = WebURL(), bool replace = false);
    void reload();

    // system message
    void firePaintEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireMouseEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireCaptureChangedEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireKillFocusEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    LRESULT fireCursorEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL& bHandle);
    LRESULT fireWheelEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL& bHandle);
    void fireKeyUpEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireKeyDownEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireKeyPressEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    bool fireTimerEvent();

    void sendOrientationChangeEvent();

    LRESULT fireInputEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    bool fireInputEventToRichEdit(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    void fireResizeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    IntSize viewportSize() const;
    void setViewportSize(const IntSize& size);

    void repaintRequested(const IntRect& windowRect);

    void setIsDraggableRegionNcHitTest();

    HWND getHWND() const;

    void setFocus(bool enabel);

    void setBackgroundColor(COLORREF c);

    void showDebugNodeData();

    CefBrowserHostImpl* browser();
    void setBrowser(CefBrowserHostImpl* browserImpl);

    WebViewImpl* webViewImpl();
    WebFrame* mainFrame();

    WebFrameClientImpl* webFrameClientImpl();

    WebFrame* getWebFrameFromFrameId(int64 frameId);

    void beginMainFrame();
    void layout();

    // kMainFrameId must be -1 to align with renderer expectations.
    static const int64 kMainFrameId = -1;
    static const int64 kFocusedFrameId = -2;
    static const int64 kUnspecifiedFrameId = -3;
    static const int64 kInvalidFrameId = -4;

protected:
    WebPageImpl* m_pageImpl;
};

} // namespace WebCore

#endif // WebPage_h