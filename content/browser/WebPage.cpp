
#include "commctrl.h"
#include "windows.h"
#undef max
#undef min

#define UseKdMsgSystem 1
#define QueryPerformance 1

#include "skia/ext/platform_canvas.h"
#include "third_party/WebKit/Source/platform/graphics/Color.h"
#include "third_party/WebKit/Source/web/WebViewImpl.h"
#include "third_party/WebKit/public/platform/WebCursorInfo.h"

#include "WebPage.h"
#include "WebPageImpl.h"

extern WCHAR szTitle[];
extern WCHAR szWindowClass[];

namespace content {

void WebPage::initOnBlinkThread()
{
    WebPageImpl::initOnBlinkThread();
}

base::SingleThreadTaskRunner* WebPage::initOnImplThread()
{
    base::SingleThreadTaskRunner* result = WebPageImpl::initOnImplThread();
    return result;
}

WebPage::WebPage(KdGuiObjPtr kdGuiObj, void* foreignPtr)
{
    m_pageImpl = nullptr;
}

WebPage::~WebPage()
{
    if (m_pageImpl) {
        delete m_pageImpl;
        m_pageImpl = 0;
    }
}

bool WebPage::init(HWND hWnd, RenderViewHost* renderViewHost)
{
    m_pageImpl = new WebPageImpl(renderViewHost);
    m_pageImpl->init(this, hWnd);

    return true;
}

void WebPage::setViewportSize(const IntSize& size)
{
    m_pageImpl->setViewportSize(size);
}

// LocalFrame* WebPage::localFrame()
// {
//     return m_pageImpl->m_webViewImpl->mainFrameImpl()->frame();
// }

// 本次点击是一次模拟标题栏
void WebPage::setIsDraggableRegionNcHitTest()
{
    m_pageImpl->m_isDraggableRegionNcHitTest = true;
}

void WebPage::windowCloseRequested()
{
    m_pageImpl->windowCloseRequested();

    delete m_pageImpl;
    m_pageImpl = 0;
}

bool WebPage::fireTimerEvent()
{
    if (m_pageImpl)
        return m_pageImpl->fireTimerEvent();
    return false;
}

void WebPage::fireResizeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_pageImpl)
        m_pageImpl->fireResizeEvent(hWnd, message, wParam, lParam);
}

void WebPage::repaintRequested(const IntRect& windowRect)
{
    if (m_pageImpl)
        m_pageImpl->repaintRequested(windowRect);
}

void WebPage::firePaintEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    BeginPaint(hWnd, &ps);
    if (m_pageImpl)
        m_pageImpl->firePaintEvent(ps.hdc, &ps.rcPaint);
    EndPaint(hWnd, &ps);
}

void WebPage::fireCaptureChangedEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_pageImpl)
        m_pageImpl->fireCaptureChangedEvent(hWnd, message, wParam, lParam);
}

void WebPage::fireKillFocusEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_pageImpl)
        m_pageImpl->fireKillFocusEvent(hWnd, message, wParam, lParam);
}

void WebPage::fireMouseEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_pageImpl)
        m_pageImpl->fireMouseEvent(hWnd, message, wParam, lParam);
}

LRESULT WebPage::fireCursorEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL& bHandle)
{
    if (m_pageImpl)
        return m_pageImpl->fireCursorEvent(hWnd, message, wParam, lParam, bHandle);
    return 0;
}

LRESULT WebPage::fireWheelEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL& bHandle)
{
    if (m_pageImpl)
        return m_pageImpl->fireWheelEvent(hWnd, message, wParam, lParam, bHandle);
    return 0;
}

void WebPage::fireKeyUpEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_pageImpl)
        m_pageImpl->fireKeyUpEvent(hWnd, message, wParam, lParam);
    return;
}

void WebPage::fireKeyDownEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_pageImpl)
        m_pageImpl->fireKeyDownEvent(hWnd, message, wParam, lParam);
    return;
}

void WebPage::fireKeyPressEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (m_pageImpl)
        m_pageImpl->fireKeyPressEvent(hWnd, message, wParam, lParam);
    return;
}

void WebPage::sendOrientationChangeEvent()
{
    if (m_pageImpl)
        m_pageImpl->sendOrientationChangeEvent();
}

IntSize WebPage::viewportSize() const
{
    if (m_pageImpl)
        return m_pageImpl->m_viewportSize;
    return IntSize();
}

HWND WebPage::getHWND() const
{
    if (m_pageImpl)
        return m_pageImpl->m_hWnd;
    return 0;
}

// Page* WebPage::page() const
// {
//     if (m_pageImpl)
//         return m_pageImpl->m_page;
//     return nullptr;
// }

#if 1

// 返回1表示调用def函数。这是因为1是S_FALSE
LRESULT WebPage::fireInputEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //     bool handled = false;
    //     WebCore::Frame* frame = m_page->focusController()->focusedOrMainFrame();
    //
    //     // we forward the key event to WebCore first to handle potential DOM
    //     // defined event handlers and later on end up in EditorClientQt::handleKeyboardEvent
    //     // to trigger editor commands via triggerAction().
    //
    //     PlatformKeyboardEvent::Type type = (PlatformKeyboardEvent::Type)-1;
    //     if (WM_KEYUP == message) {
    //         type = PlatformKeyboardEvent::KeyUp;
    //     } else if (WM_KEYDOWN == message) {
    //         type = PlatformKeyboardEvent::RawKeyDown;
    //     } else if (WM_CHAR == message) {
    //         type = PlatformKeyboardEvent::Char;
    //     }
    //
    //     if ((PlatformKeyboardEvent::Type)-1 != type) {
    //         PlatformKeyboardEvent evt(hWnd, wParam, lParam, type, true);
    //         handled = frame->eventHandler()->keyEvent(evt);
    //         if (handled)
    //             return 1;
    //     }

    return fireInputEventToRichEdit(hWnd, message, wParam, lParam);
}

// 一般都是richedit的事件
bool WebPage::fireInputEventToRichEdit(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    bool handled = false;

    //     Node* node = m_frame->document()->focusedNode();
    //     if (node && node->localName() == *SVGNames::svgricheditbaseTag) {
    //         SVGRichEditBaseElement* edit = (SVGRichEditBaseElement*)node;
    //         PassRefPtr<WinNativeEvent> evt = WinNativeEvent::create(hWnd, message, wParam, lParam);
    //         edit->defaultEventHandler((Event*)evt.get());
    //         return evt->m_hRes;
    //     } else {
    //         node = node;
    //     }

    return 1;
}

#endif

void WebPage::loadURL(int64 frameId, const wchar_t* url, const blink::Referrer& referrer, const wchar_t* extraHeaders)
{
    if (m_pageImpl)
        m_pageImpl->loadURL(frameId, url, referrer, extraHeaders);
}

void WebPage::loadRequest(int64 frameId, const blink::WebURLRequest& request)
{
    if (m_pageImpl)
        m_pageImpl->loadRequest(frameId, request);
}

void WebPage::reload()
{
    if (mainFrame())
        mainFrame()->reload(blink::WebFrameLoadType::Reload);
}

void WebPage::loadHTMLString(int64 frameId, const WebData& html, const WebURL& baseURL, const WebURL& unreachableURL, bool replace)
{
    //     String sUrl;
    //     sUrl = sUrl.format("res:///kdData_%f.svg", randomNumber());
    //
    //     postResToAsynchronousLoad((const WCHAR *)sUrl.charactersWithNullTermination(), lpData, nLen, true);
    //     loadFormUrl((const WCHAR *)sUrl.charactersWithNullTermination());

    if (m_pageImpl)
        m_pageImpl->loadHTMLString(frameId, html, baseURL, unreachableURL, replace);
}

void WebPage::setBackgroundColor(COLORREF c)
{
    if (m_pageImpl)
        m_pageImpl->m_bdColor = c;
}

void WebPage::setFocus(bool enabel)
{
    if (m_pageImpl)
        m_pageImpl->setFocus(enabel);
}

CefBrowserHostImpl* WebPage::browser()
{
    ASSERT(m_pageImpl);
    if (m_pageImpl)
        return m_pageImpl->browser();
    return nullptr;
}

void WebPage::setBrowser(CefBrowserHostImpl* browserImpl)
{
    ASSERT(m_pageImpl);
    if (m_pageImpl)
        m_pageImpl->setBrowser(browserImpl);
}

WebViewImpl* WebPage::webViewImpl()
{
    ASSERT(m_pageImpl);
    if (m_pageImpl)
        return m_pageImpl->m_webViewImpl;
    return nullptr;
}

WebFrame* WebPage::mainFrame()
{
    if (!webViewImpl())
        return nullptr;

    WebFrame* frame = webViewImpl()->mainFrame();
    if (!frame)
        return nullptr;
    return frame;
}

WebFrameClientImpl* WebPage::webFrameClientImpl()
{
    if (!m_pageImpl)
        return nullptr;
    return m_pageImpl->m_webFrameClient;
}

WebFrame* WebPage::getWebFrameFromFrameId(int64 frameId)
{
    if (!m_pageImpl)
        return nullptr;
    return m_pageImpl->getWebFrameFromFrameId(frameId);
}

void WebPage::beginMainFrame()
{
    if (!m_pageImpl)
        return;
    return m_pageImpl->beginMainFrame(true);
}

void WebPage::layout()
{
    if (!m_pageImpl)
        return;
    return m_pageImpl->layout();
}

} // namespace WebCore