#ifndef WebPagePaint_h
#define WebPagePaint_h

#include <base/basictypes.h>

#include "third_party/WebKit/Source/wtf/text/qt4/UnicodeQt4.h"

#include "third_party/WebKit/Source/core/frame/Frame.h"
#include "third_party/WebKit/Source/core/frame/FrameView.h"
#include "third_party/WebKit/Source/core/frame/LocalFrame.h"
#include "third_party/WebKit/Source/core/frame/Settings.h"
#include "third_party/WebKit/Source/core/input/EventHandler.h"
#include "third_party/WebKit/Source/core/loader/FrameLoadRequest.h"
#include "third_party/WebKit/Source/core/page/FocusController.h"
#include "third_party/WebKit/Source/core/page/NetworkStateNotifier.h"
#include "third_party/WebKit/Source/core/page/Page.h"
#include "third_party/WebKit/Source/platform/geometry/IntRect.h"
#include "third_party/WebKit/Source/platform/geometry/win/IntRectWin.h"
#include "third_party/WebKit/Source/platform/graphics/GraphicsContext.h"
#include "third_party/WebKit/Source/platform/graphics/paint/DisplayItemList.h"
#include "third_party/WebKit/Source/platform/network/ResourceRequest.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/platform/weborigin/SecurityOrigin.h"
#include "third_party/WebKit/Source/web/ChromeClientImpl.h"
#include "third_party/WebKit/Source/web/ContextMenuClientImpl.h"
#include "third_party/WebKit/Source/web/EditorClientImpl.h"
#include "third_party/WebKit/Source/web/FrameLoaderClientImpl.h"
#include "third_party/WebKit/Source/web/WebLocalFrameImpl.h"
#include "third_party/WebKit/Source/web/WebSettingsImpl.h"
#include "third_party/WebKit/Source/web/WebViewImpl.h"
#include "third_party/WebKit/public/platform/WebCursorInfo.h"
#include "third_party/WebKit/public/platform/WebMouseWheelEvent.h"
#include "third_party/WebKit/public/web/WebFrameClient.h"
#include "third_party/WebKit/public/web/WebLocalFrame.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "third_party/WebKit/public/web/win/WebFontRendering.h"

#include "third_party/WebKit/Source/core/layout/LayoutText.h" // test

#include "third_party/skia/include/ports/SkTypeface_win.h"

#include "content/web_impl_win/BlinkPlatformImpl.h"
//#include "content/web_impl_win/WebThreadImpl.h"
#include "content/browser/RenderViewHost.h"

#include "gen/blink/platform/RuntimeEnabledFeatures.h"
#include "gin/array_buffer.h"
#include "gin/public/isolate_holder.h"
#include "third_party/WebKit/public/web/WebKit.h"
#include "ui/gfx/win/dpi.h"

#include "WebFrameClientImpl.h"

#include "skia/ext/platform_canvas.h"

#include "WebPage.h"
#include "WebPageImpl.h"
#include "wtypes.h"

#include "base/rand_util.h"

namespace content {

static void setRuntimeEnabledFeatures();

static BlinkPlatformImpl* gBlinkPlatform = nullptr;

void WebPageImpl::initOnBlinkThread()
{
    setRuntimeEnabledFeatures();

    //gfx::win::InitDeviceScaleFactor();
    gin::IsolateHolder::Initialize(gin::IsolateHolder::kNonStrictMode, gin::ArrayBufferAllocator::SharedInstance());
    blink::initialize(gBlinkPlatform);

    sk_sp<SkFontMgr> fontMgr(SkFontMgr_New_GDI());
    blink::WebFontRendering::setSkiaFontManager(fontMgr);
}

base::SingleThreadTaskRunner* WebPageImpl::initOnImplThread(/*const base::Closure& task*/)
{
    gBlinkPlatform = new BlinkPlatformImpl();
    blink::WebThread* webThread = gBlinkPlatform->createBlinkThread();
    //webThread->getSingleThreadTaskRunner()->PostTask(FROM_HERE, task);
    return webThread->getSingleThreadTaskRunner();
}

WebPageImpl::WebPageImpl(RenderViewHost* renderViewHost)
{
    m_pagePtr = 0;
    m_bdColor = RGB(199, 237, 204) | 0xff000000;
    m_memoryCanvas = nullptr;
    m_needsCommit = true;
    //m_layerTreeHost = nullptr;
    m_lastFrameTimeMonotonic = WTF::currentTime();
    ;
    m_webViewImpl = nullptr;
    m_mouseInWindow = false;
    m_debugCount = 0;
    m_hWnd = NULL;
    m_state = UNINIT;
    m_frameLoaderClient = NULL;
    m_chromeClient = NULL;
    m_page = NULL;
    m_isAlert = false;
    m_isDraggableRegionNcHitTest = false;
    m_lastMouseDownTime = 0;
    m_callbacks.m_xmlHaveFinished = 0;
    m_scheduleMessageCount = 0;
    m_postpaintMessageCount = 0;
    m_hasResize = false;
    m_postMouseLeave = false;
    m_bMouseTrack = true;

    m_renderViewHost = renderViewHost;

    memset(&m_callbacks, 0, sizeof(KWebApiCallbackSet));

    m_webFrameClient = new content::WebFrameClientImpl();

    WebLocalFrameImpl* webLocalFrameImpl = (WebLocalFrameImpl*)WebLocalFrame::create(WebTreeScopeType::Document, m_webFrameClient);
    m_webViewImpl = WebViewImpl::create(this, blink::WebPageVisibilityStateVisible);
    m_webViewImpl->setMainFrame(webLocalFrameImpl);

    blink::WebFrameWidget* webFrameWidget = blink::WebFrameWidget::create(this, m_webViewImpl, webLocalFrameImpl);

    initSetting();

    m_frameLoaderClient = FrameLoaderClientImpl::create(webLocalFrameImpl);
}

WebPageImpl::~WebPageImpl()
{
    m_state = DESTROYING;
    FrameLoader* loader = &m_webViewImpl->mainFrameImpl()->frame()->loader();
    if (loader)
        loader->detach();

    // 在Page::~Page()中销毁
    if (!m_webFrameClient)
        delete m_webFrameClient;
    m_webFrameClient = nullptr;

    if (m_page)
        delete m_page;
    m_page = 0;

    if (!m_dirtyCanvas)
        delete m_dirtyCanvas;
    m_dirtyCanvas = nullptr;

    if (!m_memoryCanvas)
        delete m_memoryCanvas;
    m_memoryCanvas = nullptr;

    m_pagePtr = 0;
}

WebView* WebPageImpl::createView(WebLocalFrame* creator,
    const WebURLRequest& request,
    const WebWindowFeatures& features,
    const WebString& name,
    WebNavigationPolicy policy,
    bool suppressOpener)
{
    //     scoped_refptr<CefBrowserHostImpl> browserHostImpl = CefBrowserInfoManager::GetInstance()->CreateBrowserHostIfAllow(
    //         m_pagePtr, creator, request, features, name, policy, suppressOpener);
    //     if (!browserHostImpl)
    //         return nullptr;
    //     if (!browserHostImpl->webPage())
    //         return nullptr;
    //     return browserHostImpl->webPage()->webViewImpl();
    DebugBreak();
    return nullptr;
}

void WebPageImpl::init(WebPage* pagePtr, HWND hWnd)
{
    m_hWnd = hWnd;

    LONG windowStyle = GetWindowLongPtr(hWnd, GWL_EXSTYLE);
    m_useLayeredBuffer = !!((windowStyle)&WS_EX_LAYERED);

    m_pagePtr = pagePtr;
    m_webFrameClient->setWebPage(m_pagePtr);

    m_state = INIT;
}

void WebPageImpl::clearPaintWhenLayeredWindow(SkCanvas* canvas, const IntRect& rect)
{
    if (!m_useLayeredBuffer)
        return;

    // When using transparency mode clear the rectangle before painting.
    SkPaint clearPaint;
    clearPaint.setARGB(0, 0, 0, 0);
    clearPaint.setXfermodeMode(SkXfermode::kClear_Mode);

    SkRect skrc;
    skrc.set(rect.x(), rect.y(), rect.x() + rect.width(), rect.y() + rect.height());
    canvas->drawRect(skrc, clearPaint);
}

bool WebPageImpl::doMergeDirtyList(bool forceMerge)
{
    int nDirty = (int)m_paintMessageQueue.size();
    if (nDirty < 1) {
        return false;
    }

    int bestDelta = forceMerge ? 0x7FFFFFFF : 0;
    int mergeA = 0;
    int mergeB = 0;
    for (int i = 0; i < nDirty - 1; i++) {
        for (int j = i + 1; j < nDirty; j++) {
            int delta = intUnionArea(&m_paintMessageQueue[i], &m_paintMessageQueue[j]) - intRectArea(&m_paintMessageQueue[i]) - intRectArea(&m_paintMessageQueue[j]);
            if (bestDelta > delta) {
                mergeA = i;
                mergeB = j;
                bestDelta = delta;
            }
        }
    }

    if (mergeA != mergeB) {
        m_paintMessageQueue[mergeA].unite(m_paintMessageQueue[mergeB]);
        for (int i = mergeB + 1; i < nDirty; i++)
            m_paintMessageQueue[i - 1] = m_paintMessageQueue[i];

        m_paintMessageQueue.pop_back();
        return true;
    }

    return false;
}

void WebPageImpl::postPaintMessage(const IntRect* paintRect)
{
    if (!paintRect || paintRect->isEmpty())
        return;

    m_postpaintMessageCount++;

    if (m_paintMessageQueue.size() > m_paintMessageQueueSize && 0 != m_scheduleMessageCount)
        return; // 从SchedulePaintEvent发送过来的

    if (m_paintMessageQueue.size() > m_paintMessageQueueSize) {
        IntRect destroyRect = m_paintMessageQueue[0];
        m_paintMessageQueue.remove(0);
    }

    // TODO 脏矩形合并
    for (int i = 0; i < (int)m_paintMessageQueue.size(); ++i) {
        IntRect* paintRectFromQueue = &m_paintMessageQueue[i];
        if (paintRectFromQueue == paintRect)
            paintRectFromQueue->setWidth(0);
    }

    m_paintMessageQueue.append(*paintRect);

    m_postpaintMessageCount--;
}

void WebPageImpl::testPaint()
{
    for (size_t index = 0; index < m_paintMessageQueue.size(); ++index) {
        IntRect* paintRect = &m_paintMessageQueue[index];
        WCHAR msg[100] = { 0 };
        swprintf(msg, L"testPaint: %d %d %x\n", paintRect->y(), paintRect->height(), index);
        OutputDebugStringW(msg);
    }
}

void WebPageImpl::beginMainFrame(bool force)
{
    double lastFrameTimeMonotonic = WTF::currentTime();

    if (needsCommit() || force) {
        clearNeedsCommit();

        double lastFrameTimeMonotonic = WTF::currentTime();

        m_webViewImpl->beginFrame(m_lastFrameTimeMonotonic);
        m_webViewImpl->updateAllLifecyclePhases();
    }

    schedulePaintEvent();

    m_lastFrameTimeMonotonic = lastFrameTimeMonotonic;
}

void WebPageImpl::layout()
{
    if (!m_webViewImpl)
        return;
    return m_webViewImpl->updateAllLifecyclePhases();
}

void WebPageImpl::schedulePaintEvent()
{
    if (0 != m_scheduleMessageCount)
        notImplemented();

    if (!m_pagePtr->getHWND())
        return;

    m_scheduleMessageCount++;

    HDC hdc = ::GetDC(m_pagePtr->getHWND());

    IntRect lastTimeRect;
    bool loopAgain = false;
    do {
        loopAgain = false;
        lastTimeRect.setSize(IntSize());
        mergeDirtyList();
        int queueSize = (int)m_paintMessageQueue.size();
        for (int i = 0; i < queueSize; ++i) {
            IntRect* paintRect = &m_paintMessageQueue[i];
            if (lastTimeRect == *paintRect || lastTimeRect.contains(*paintRect))
                continue;

            lastTimeRect = *paintRect;
            //fastFree(paintRect);
            if (!lastTimeRect.isEmpty()) { // 这里可能会重入postPaintMessage，所以需要重新合并脏矩形，并且小心一些bug
                doPaint(hdc, &lastTimeRect);

                // 这里还有优化空间，可以把很短间隔的差距不大的矩形忽略掉
                if (queueSize != (int)m_paintMessageQueue.size()) { // 如果在绘制的时候被请求了脏矩形，则重新合并
                    m_paintMessageQueue.remove(0, i + 1);
                    loopAgain = true;
                    break;
                }
            }
        }

    } while (loopAgain);
    ::ReleaseDC(m_pagePtr->getHWND(), hdc);

    m_paintMessageQueue.clear();
    m_scheduleMessageCount--;
}

void WebPageImpl::doPaint(HDC hdc, const IntRect* paintRect)
{
    RECT rcPaint = { 0, 0, 500, 500 };
    m_paintRect = *paintRect;

    bool needsFullTreeSync = true; // false; 先全部层都更新，这样滚动条才能被刷新到
    if (!m_memoryCanvas || m_hasResize) {
        m_hasResize = false;
        needsFullTreeSync = true;
        m_paintRect = m_clientRect;

        if (m_memoryCanvas)
            delete m_memoryCanvas;
        m_memoryCanvas = skia::CreatePlatformCanvas(m_clientRect.width(), m_clientRect.height(), !m_useLayeredBuffer);
    }

    m_paintRect.intersect(m_clientRect);
    if (m_paintRect.isEmpty())
        return;

#if QueryPerformance
    LARGE_INTEGER now0;
    LARGE_INTEGER now1 = { 0 };
    QueryPerformanceCounter(&now0);
#endif
    clearPaintWhenLayeredWindow(m_memoryCanvas, m_paintRect);

    skia::ScopedPlatformPaint scopedPlatformPaint(m_memoryCanvas);
    HDC hMemoryDC = scopedPlatformPaint.GetPlatformSurface();

    updateLayers(m_paintRect, m_memoryCanvas, needsFullTreeSync); // 绘制脏矩形

    if (m_useLayeredBuffer) { // 再把内存dc画到hdc上
        RECT rtWnd;
        ::GetWindowRect(m_pagePtr->getHWND(), &rtWnd);
        m_winodwRect = winRectToIntRect(rtWnd);
        //skia::DrawToNativeLayeredContext(m_memoryCanvas.get(), hdc, m_winodwRect.x(), m_winodwRect.y(), &((RECT)m_clientRect));
    } else {
        drawDebugLine(m_memoryCanvas, m_paintRect);
        skia::DrawToNativeContext(m_memoryCanvas, hdc, m_paintRect.x(), m_paintRect.y(), &intRectToWinRect(m_paintRect));
    }

    //::Rectangle(hdc, m_paintRect.x(), m_paintRect.y(), m_paintRect.maxX(), m_paintRect.maxY());
    //::Rectangle(hdc, 220, 40, 366, 266);
}

void WebPageImpl::drawDebugLine(SkCanvas* memoryCanvas, const IntRect& paintRect)
{
    m_debugCount++;

    //     OwnPtr<GraphicsContext> context = GraphicsContext::deprecatedCreateWithCanvas(memoryCanvas, GraphicsContext::NothingDisabled);
    //
    //     context->setStrokeStyle(SolidStroke);
    //     context->setStrokeColor(0xff000000 | (::GetTickCount() + base::RandInt(0, 0x1223345)));
    //     context->drawLine(IntPoint(paintRect.x(), paintRect.y()), IntPoint(paintRect.maxX(), paintRect.maxY()));
    //     context->drawLine(IntPoint(paintRect.maxX(), paintRect.y()), IntPoint(paintRect.x(), paintRect.maxY()));
    //     context->strokeRect(paintRect, 2);

    //     WCHAR msg[200] = { 0 };
    //     wsprintfW(msg, L"drawDebugLine : %d %d %d %d   | %d\n\n", m_paintRect.x(), m_paintRect.y(), m_paintRect.width(), m_paintRect.height(), m_debugCount);
    //     OutputDebugStringW(msg);
}

void WebPageImpl::updateLayers(const IntRect& dirtyRect, SkCanvas* canvas, bool needsFullTreeSync)
{
    if (dirtyRect.isEmpty() /*|| !m_layerTreeHost*/)
        return;

    setPainting(true);

    SkPaint paint;
    canvas->save();
    canvas->clipRect(dirtyRect);

    //m_layerTreeHost->updateLayers(canvas, dirtyRect, needsFullTreeSync);

    canvas->restore();
    setPainting(false);
}

void WebPageImpl::firePaintEvent(HDC hdc, const RECT* paintRect)
{
    if (!m_memoryCanvas || m_clientRect.isEmpty())
        return;

    //         SkPaint myPaint;
    //         myPaint.setColor(0xff11ff33);
    //         myPaint.setXfermodeMode(SkXfermode::kSrc_Mode);
    //         m_memoryCanvas->drawRect(blink::IntRect(150, 100, 100, 100), myPaint); // weolar

    //skia::DrawToNativeContext(m_memoryCanvas, hdc, 0, 0, &intRectToWinRect(m_clientRect));
    skia::DrawToNativeContext(m_memoryCanvas, hdc, paintRect->left, paintRect->top, paintRect);
    //::Rectangle(hdc, 20, 20, 266, 166);

    //     WCHAR msg[200] = { 0 };
    //     wsprintfW(msg, L"paintEvent : %d %d %d %d  \n\n", paintRect->left, paintRect->top, paintRect->right - paintRect->left, paintRect->bottom - paintRect->top);
    //     OutputDebugStringW(msg);
}

void WebPageImpl::windowCloseRequested()
{
    if (INIT != m_state)
        return;
    m_state = DESTROYING;

    ::SetWindowLongPtr(m_hWnd, GWLP_USERDATA, 0);

    // 在KFrameLoaderClient::frameLoaderDestroyed()也会调用到此，所以在给脚本发消息的时候注意一下
    // WebCore::WebPage::windowCloseRequested+0x1a
    // WebCore::KFrameLoaderClient::frameLoaderDestroyed+0xc
    // WebCore::FrameLoader::~FrameLoader+0x7e
    // WebCore::Frame::~Frame+0xd0
    // WTF::RefCounted<WebCore::Frame>::deref+0x16
    // WebCore::Frame::lifeSupportTimerFired+0x5
    // WebCore::Timer<WebCore::MainResourceLoader>::fired+0xc
    // WebCore::ThreadTimers::sharedTimerFiredInternal+0x8b
    // WebCore::ThreadTimers::sharedTimerFired+0xe
    // WebCore::WebPage::windowCloseRequested+0x99
    // 所以这里可能有重入
    //SharedTimerKd::inst()->timerEvent(); // 很多异步清理资源的工作会放在定时器里，所以最后再执行一遍

    // TODO_Weolar
    // 发生unload消息给脚本

    // 清空webkit的资源缓存
    //memoryCache()->evictResources();

    ::KillTimer(m_hWnd, (UINT_PTR)this);
}

#ifndef NDEBUG
BOOL gd_bShowTree = FALSE;
#endif

void WebPageImpl::showDebugNodeData()
{
#ifndef NDEBUG
    //m_webViewImpl->mainFrameImpl()->frame()->document()->showTreeForThis();
    DebugBreak();
#endif
}

bool WebPageImpl::fireTimerEvent()
{
    bool needFireMore = false;
    //     WebThreadImpl* thread = nullptr;
    //     thread = (content::WebThreadImpl*)(blink::Platform::current()->currentThread());
    //     thread->startTriggerTasks();
    //     needFireMore = thread->schedulerTasks();

    beginMainFrame(false);

#ifndef NDEBUG
    if (gd_bShowTree) {
        showDebugNodeData();
        //m_layerTreeHost->showDebug();
        //ThreadProxy::SetNeedsUpdateLayers;
    }
#endif
    return needFireMore;
}

void WebPageImpl::fireResizeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (INIT != m_state || m_isAlert)
        return;

    UINT cx, cy;
    cx = LOWORD(lParam);
    cy = HIWORD(lParam);

    if (!m_hWnd)
        m_hWnd = hWnd;

    IntSize size(cx, cy);
    setViewportSize(size);
}

void WebPageImpl::setViewportSize(const IntSize& size)
{
    m_viewportSize = size;

    ASSERT(INIT == m_state);
    if (DESTROYING == m_state)
        return;

    if (size.isEmpty())
        return;

    m_webViewImpl->resize(WebSize(size));

    m_clientRect = IntRect(0, 0, size.width(), size.height());

    RECT rtWnd;
    ::GetWindowRect(m_hWnd, &rtWnd);
    m_winodwRect = winRectToIntRect(rtWnd);
    m_hasResize = true;
}

void WebPageImpl::repaintRequested(const IntRect& windowRect)
{
    if (INIT != m_state || windowRect.isEmpty() || windowRect.maxY() < 0 || windowRect.maxX() < 0)
        return;

    //     RECT winRect = {windowRect.x(), windowRect.y(),
    //       windowRect.x() + windowRect.width(), windowRect.y() + windowRect.height()};

    //     WCHAR msg[200] = {0};
    //     wsprintfW(msg, L"repaintRequested : %d %d %d %d\n", windowRect.x(), windowRect.y(), windowRect.width(), windowRect.maxY());
    //     OutputDebugStringW(msg);

    //  ::InvalidateRect(m_hWnd, &winRect, false);
    postPaintMessage(&windowRect);
}

// Called when a region of the WebWidget needs to be re-painted.
void WebPageImpl::didInvalidateRect(const WebRect& r)
{
    IntRect windowRect(r);
    if (-1 == windowRect.width() || -1 == windowRect.height())
        windowRect = m_clientRect;
    repaintRequested(windowRect);
    setNeedsCommit();
}

// Called when the Widget has changed size as a result of an auto-resize.
void WebPageImpl::didAutoResize(const WebSize& newSize)
{
    //notImplemented();
}

// void WebPageImpl::didUpdateLayoutSize(const WebSize& newSize)
// {
//     //notImplemented();
// }

void WebPageImpl::scheduleAnimation()
{
    setNeedsCommit();
}

WebLayerTreeView* WebPageImpl::initializeLayerTreeView()
{
    m_renderViewHost->initializeLayerTreeView();
    return layerTreeView();
}

WebLayerTreeView* WebPageImpl::layerTreeView()
{
    return (WebLayerTreeView*)m_renderViewHost->renderWidgetCompositor();
}

void WebPageImpl::didChangeCursor(const WebCursorInfo& cursor)
{
    if (m_cursorType == cursor.type)
        return;
    m_cursorType = cursor.type;

    //     static int i = 0;
    //     String xx = String::format("WebPageImpl::didChangeCursor: %d\n", ++i);
    //     OutputDebugStringW(xx.charactersWithNullTermination().data());

    ::PostMessage(m_hWnd, WM_SETCURSOR, 0, 0);
}

LRESULT WebPageImpl::fireCursorEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL& bHandle)
{
    HCURSOR hCur = NULL;
    switch (m_cursorType) {
    case WebCursorInfo::TypeIBeam:
        hCur = ::LoadCursor(NULL, IDC_IBEAM);
        break;
    case WebCursorInfo::TypeHand:
        hCur = ::LoadCursor(NULL, IDC_HAND);
        break;
    case WebCursorInfo::TypeWait:
        hCur = ::LoadCursor(NULL, IDC_WAIT);
        break;
    case WebCursorInfo::TypeHelp:
        hCur = ::LoadCursor(NULL, IDC_HELP);
        break;
    case WebCursorInfo::TypeEastResize:
        hCur = ::LoadCursor(NULL, IDC_SIZEWE);
        break;
    case WebCursorInfo::TypeNorthResize:
        hCur = ::LoadCursor(NULL, IDC_SIZENS);
        break;
    case WebCursorInfo::TypeSouthWestResize:
    case WebCursorInfo::TypeNorthEastResize:
        hCur = ::LoadCursor(NULL, IDC_SIZENESW);
        break;
    case WebCursorInfo::TypeSouthResize:
    case WebCursorInfo::TypeNorthSouthResize:
        hCur = ::LoadCursor(NULL, IDC_SIZENS);
        break;
    case WebCursorInfo::TypeNorthWestResize:
    case WebCursorInfo::TypeSouthEastResize:
        hCur = ::LoadCursor(NULL, IDC_SIZENWSE);
        break;
    case WebCursorInfo::TypeWestResize:
    case WebCursorInfo::TypeEastWestResize:
        hCur = ::LoadCursor(NULL, IDC_SIZEWE);
        break;
    case WebCursorInfo::TypeNorthEastSouthWestResize:
    case WebCursorInfo::TypeNorthWestSouthEastResize:
        hCur = ::LoadCursor(NULL, IDC_SIZEALL);
        break;
    }

    if (hCur) {
        ::SetCursor(hCur);
        bHandle = TRUE;
    }

    return 0;
}

static int verticalScrollLines()
{
    static ULONG scrollLines;
    if (!scrollLines && !SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &scrollLines, 0))
        scrollLines = 3;
    return scrollLines;
}

static int horizontalScrollChars()
{
    static ULONG scrollChars;
    if (!scrollChars && !SystemParametersInfo(SPI_GETWHEELSCROLLCHARS, 0, &scrollChars, 0))
        scrollChars = 1;
    return scrollChars;
}

LRESULT WebPageImpl::fireWheelEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL& bHandle)
{
    int x = LOWORD(lParam);
    int y = HIWORD(lParam);

    int wheelDelta = GET_WHEEL_DELTA_WPARAM(wParam);

    static const float cScrollbarPixelsPerLine = 100.0f / 3.0f;
    float delta = wheelDelta / static_cast<float>(WHEEL_DELTA);

    float deltaX = 0.f;
    float deltaY = 0.f;

    bool shiftKey = wParam & MK_SHIFT;
    bool ctrlKey = wParam & MK_CONTROL;
    bool altKey = GetKeyState(VK_MENU) & 0x8000;
    //blink::PlatformWheelEventGranularity granularity = blink::ScrollByPageWheelEvent;

    if (shiftKey) {
        deltaX = delta * static_cast<float>(horizontalScrollChars()) * cScrollbarPixelsPerLine;
        deltaY = 0;
        //granularity = blink::ScrollByPixelWheelEvent;
    } else {
        deltaX = 0;
        deltaY = delta;
        int verticalMultiplier = verticalScrollLines();
        //         granularity = (verticalMultiplier == WHEEL_PAGESCROLL) ? blink::ScrollByPageWheelEvent : blink::ScrollByPixelWheelEvent;
        //         if (granularity == blink::ScrollByPixelWheelEvent)
        //             deltaY *= static_cast<float>(verticalMultiplier)* cScrollbarPixelsPerLine;
    }

    blink::WebMouseWheelEvent webWheelEvent;
    webWheelEvent.setType(WebInputEvent::MouseWheel);
    webWheelEvent.x = x;
    webWheelEvent.y = y;
    webWheelEvent.globalX = x;
    webWheelEvent.globalY = x;
    webWheelEvent.deltaX = deltaX;
    webWheelEvent.deltaY = deltaY;
    webWheelEvent.wheelTicksX = 0.f;
    webWheelEvent.wheelTicksY = delta;
    m_webViewImpl->handleInputEvent(webWheelEvent);
    return 0;
}

static const unsigned short HIGH_BIT_MASK_SHORT = 0x8000;
static bool isKeypadEvent(WPARAM code, LPARAM keyData, WebInputEvent::Type type);
static inline String singleCharacterString(UChar c) { return String(&c, 1); }

static WebKeyboardEvent buildKeyboardEvent(WebInputEvent::Type type, UINT message, WPARAM wParam, LPARAM lParam)
{
    unsigned int virtualKeyCode = wParam;
    unsigned int flags = 0;
    if (HIWORD(lParam) & KF_REPEAT)
        flags |= KF_REPEAT;
    if (HIWORD(lParam) & KF_EXTENDED)
        flags |= KF_REPEAT;
    bool systemKey = false;

    LPARAM keyData = MAKELPARAM(0, (WORD)flags);

    int modifiers = 0;
    if (GetKeyState(VK_SHIFT) & HIGH_BIT_MASK_SHORT)
        modifiers |= WebInputEvent::ShiftKey;
    if (GetKeyState(VK_CONTROL) & HIGH_BIT_MASK_SHORT)
        modifiers |= WebInputEvent::ControlKey;
    if (GetKeyState(VK_MENU) & HIGH_BIT_MASK_SHORT)
        modifiers |= WebInputEvent::AltKey;
    if (isKeypadEvent(wParam, keyData, type))
        modifiers |= WebInputEvent::IsKeyPad;

    WebKeyboardEvent keyEvent(type, modifiers, WTF::currentTime());
    keyEvent.windowsKeyCode = (type == WebInputEvent::RawKeyDown || type == WebInputEvent::KeyUp) ? wParam : 0;
    keyEvent.nativeKeyCode = wParam;
    keyEvent.domCode = 0;
    keyEvent.domKey = 0;

    memset(keyEvent.text, 0, sizeof(WebUChar) * WebKeyboardEvent::textLengthCap);
    keyEvent.text[0] = (WebUChar)wParam;
    return keyEvent;
}

bool WebPageImpl::fireKeyUpEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    WebKeyboardEvent keyEvent = buildKeyboardEvent(WebInputEvent::KeyUp, message, wParam, lParam);
    return m_webViewImpl->handleInputEvent(keyEvent) != blink::WebInputEventResult::NotHandled;
}

bool WebPageImpl::fireKeyDownEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    unsigned int virtualKeyCode = wParam;
    WebKeyboardEvent keyEvent = buildKeyboardEvent(WebInputEvent::RawKeyDown, message, wParam, lParam);
    //     ChromeClient* client = (ChromeClient*)page()->chrome()->client();
    //     if (client->popupMenu() && client->popupMenu()->keyDown(keyEvent))
    //         return true;

    //     WebCore::Frame* frame = page()->focusController()->focusedOrMainFrame();
    //     bool handled = frame->eventHandler()->keyEvent(keyEvent);
    bool handled = m_webViewImpl->handleInputEvent(keyEvent) != blink::WebInputEventResult::NotHandled;
    bool systemKey = false;
    // These events cannot be canceled, and we have no default handling for them.
    // FIXME: match IE list more closely, see <http://msdn2.microsoft.com/en-us/library/ms536938.aspx>.
    if (systemKey && virtualKeyCode != VK_RETURN)
        return false;

    if (handled) {
        MSG msg;
        ::PeekMessage(&msg, NULL, WM_CHAR, WM_CHAR, PM_REMOVE);
        return true;
    }

    return false;
}

bool WebPageImpl::fireKeyPressEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    unsigned int charCode = wParam;
    unsigned int flags = 0;
    if (HIWORD(lParam) & KF_REPEAT)
        flags |= KF_REPEAT;
    if (HIWORD(lParam) & KF_EXTENDED)
        flags |= KF_EXTENDED;
    LPARAM keyData = MAKELPARAM(0, (WORD)flags);
    bool systemKey = false;
    //     ChromeClient* client = (ChromeClient*)page()->chrome()->client();
    //     if (client->popupMenu() && client->popupMenu()->keyPress(keyEvent))
    //         return true;
    //     if (systemKey)
    //         return frame->eventHandler()->handleAccessKey(keyEvent);
    WebKeyboardEvent keyEvent = buildKeyboardEvent(WebInputEvent::Char, message, wParam, lParam);
    return m_webViewImpl->handleInputEvent(keyEvent) != blink::WebInputEventResult::NotHandled;
}

static void makeDraggableRegionNcHitTest(HWND hWnd, LPARAM lParam, bool* isDraggableRegionNcHitTest, IntPoint& lastPosForDrag)
{
    int xPos = ((int)(short)LOWORD(lParam));
    int yPos = ((int)(short)HIWORD(lParam));
    if (true == *isDraggableRegionNcHitTest) {
        //::PostMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(xPos, yPos));
        ::PostMessage(hWnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
        lastPosForDrag = IntPoint(xPos, yPos);
    } else {
        ::SetCapture(hWnd);
    }
    //*isDraggableRegionNcHitTest = false;
}

void WebPageImpl::fireCaptureChangedEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //     const INT vkey = GetSystemMetrics(SM_SWAPBUTTON) ? VK_RBUTTON : VK_LBUTTON;
    //     LONG bLButtonIsDown = GetAsyncKeyState(vkey) & 0x8000;
    //
    //     WCHAR msg[100] = {0};
    //     swprintf(msg, L"WebPage::captureChangedEvent 1: %x %x\n", m_isDraggableRegionNcHitTest, bLButtonIsDown);
    //     OutputDebugStringW(msg);

    if (m_isDraggableRegionNcHitTest /*&& 0 == bLButtonIsDown*/) {
        ::ReleaseCapture();
        m_isDraggableRegionNcHitTest = false;

        //         POINT ptCursor;
        //         ::GetCursorPos(&ptCursor);
        //         ::ScreenToClient(hWnd, &ptCursor);
        //         lParam = MAKELONG(ptCursor.x, ptCursor.y);
        lParam = MAKELONG(m_lastPosForDrag.x(), m_lastPosForDrag.y());
        fireMouseEvent(hWnd, WM_LBUTTONUP, wParam, lParam);
    }
}

void WebPageImpl::fireKillFocusEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //     // only set the focused frame inactive so that we stop painting the caret
    //     // and the focus frame. But don't tell the focus controller so that upon
    //     // focusInEvent() we can re-activate the frame.
    //     FocusController* focusController = &page()->focusController();
    //     // Call setFocused first so that window.onblur doesn't get called twice
    //     focusController->setFocused(false);
    //     focusController->setActive(false);
    //     focusController->focusDocumentView((localFrame()));
}

void WebPageImpl::fireTouchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static uint32_t uniqueTouchEventId = 0;
    uniqueTouchEventId++;

    WebInputEvent::Type type;
    WebTouchPoint::State state;
    if (WM_LBUTTONDOWN == message) {
        type = WebInputEvent::TouchStart;
        state = WebTouchPoint::StatePressed;
    } else if (WM_LBUTTONUP == message) {
        type = WebInputEvent::TouchEnd;
        state = WebTouchPoint::StateReleased;
    } else if (WM_MOUSEMOVE == message) {
        type = WebInputEvent::TouchMove;
        state = WebTouchPoint::StateMoved;
    }

    WebTouchEvent webTouchEvent(type, 0, WTF::currentTime());
    webTouchEvent.touchesLength = 1;
    webTouchEvent.uniqueTouchEventId = uniqueTouchEventId;

    WebTouchPoint& webTouchPoint = webTouchEvent.touches[0];
    webTouchPoint.state = state;
    webTouchPoint.id = 0;

    POINT ptCursor;
    ::GetCursorPos(&ptCursor);

    webTouchPoint.screenPosition.x = ptCursor.x;
    webTouchPoint.screenPosition.y = ptCursor.y;

    webTouchPoint.position.x = ((int)(short)LOWORD(lParam));
    webTouchPoint.position.y = ((int)(short)HIWORD(lParam));

    webTouchPoint.radiusX = 10;
    webTouchPoint.radiusY = 10;
    webTouchPoint.rotationAngle = 0;

    m_webViewImpl->handleInputEvent(webTouchEvent);
}

void WebPageImpl::fireMouseEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //     fireTouchEvent(hWnd, message, wParam, lParam);
    //     return;

    m_isDraggableRegionNcHitTest = false;
    if (true == m_isAlert)
        return;

    if (m_bMouseTrack && !m_postMouseLeave) { // 若允许追踪，则
        TRACKMOUSEEVENT csTME;
        csTME.cbSize = sizeof(csTME);
        csTME.dwFlags = TME_LEAVE | TME_HOVER;
        csTME.hwndTrack = m_hWnd; // 指定要追踪的窗口
        csTME.dwHoverTime = 10; // 鼠标在按钮上停留超过10ms，才认为状态为HOVER
        ::TrackMouseEvent(&csTME); // 开启Windows的WM_MOUSELEAVE，WM_MOUSEHOVER事件支持
        m_bMouseTrack = false; // 若已经追踪，则停止追踪
    }

    bool shift = false, ctrl = false, alt = false, meta = false;
    int clickCount = 0;

    IntPoint pos;
    IntPoint globalPos;

    if (WM_MOUSELEAVE == message) {
        m_postMouseLeave = true;

        POINT ptCursor;
        ::GetCursorPos(&ptCursor);
        globalPos = IntPoint(ptCursor.x, ptCursor.y);
        ::ScreenToClient(hWnd, &ptCursor);
        if (ptCursor.x < 2)
            ptCursor.x = -1;
        else if (ptCursor.x > 10)
            ptCursor.x += 2;

        if (ptCursor.y < 2)
            ptCursor.y = -1;
        else if (ptCursor.y > 10)
            ptCursor.y += 2;

        pos = IntPoint(ptCursor.x, ptCursor.y);

        lParam = MAKELPARAM(ptCursor.x, ptCursor.y);
    } else {
        m_postMouseLeave = false;
        pos.setX(((int)(short)LOWORD(lParam)));
        pos.setY(((int)(short)HIWORD(lParam)));

        POINT widgetpt = { pos.x(), pos.y() };
        ::ClientToScreen(hWnd, &widgetpt);
        globalPos.setX(widgetpt.x);
        globalPos.setY(widgetpt.y);
    }

    if (WM_MOUSELEAVE == message)
        m_bMouseTrack = true;

    //PlatformMouseEventWin ev(hWnd, message, wParam, lParam, FALSE);

    WebPointerProperties::Button button;
    WebInputEvent::Type type;
    double time = WTF::currentTime();

    if (WM_LBUTTONDOWN == message || WM_MBUTTONDOWN == message || WM_RBUTTONDOWN == message) {
        switch (message) {
        case WM_LBUTTONDOWN:
            button = WebPointerProperties::Button::Left;
            break;
        case WM_MBUTTONDOWN:
            button = WebPointerProperties::Button::Middle;
            break;
        case WM_RBUTTONDOWN:
            button = WebPointerProperties::Button::Right;
            break;
        }
        m_isDraggableRegionNcHitTest = false;
        type = WebInputEvent::MouseDown;
        if (time - m_lastMouseDownTime < 0.45) {
            clickCount = 2;
        }
        m_lastMouseDownTime = time;
        //m_webViewImpl->handleInputEvent(webMouseEvent);
        makeDraggableRegionNcHitTest(hWnd, lParam, &m_isDraggableRegionNcHitTest, m_lastPosForDrag);
    } else if (WM_LBUTTONUP == message || WM_MBUTTONUP == message || WM_RBUTTONUP == message) {
        switch (message) {
        case WM_LBUTTONUP:
            button = WebPointerProperties::Button::Left;
            break;
        case WM_MBUTTONUP:
            button = WebPointerProperties::Button::Middle;
            break;
        case WM_RBUTTONUP:
            button = WebPointerProperties::Button::Right;
            break;
        }
        ::ReleaseCapture();
        //m_webViewImpl->dragSourceSystemDragEnded();
        type = WebInputEvent::MouseUp;
        //m_webViewImpl->handleInputEvent(webMouseEvent);
    } else if (WM_MOUSEMOVE == message || WM_MOUSELEAVE == message) {
        if (wParam & MK_LBUTTON)
            button = WebPointerProperties::Button::Left;
        else if (wParam & MK_MBUTTON)
            button = WebPointerProperties::Button::Middle;
        else if (wParam & MK_RBUTTON)
            button = WebPointerProperties::Button::Right;
        else
            button = WebPointerProperties::Button::NoButton;

        switch (message) {
        case WM_MOUSEMOVE:
            if (!m_mouseInWindow) {
                type = WebInputEvent::MouseEnter;
                m_mouseInWindow = true;
            } else
                type = WebInputEvent::MouseMove;
            //m_webViewImpl->handleInputEvent(webMouseEvent);
            break;
        case WM_MOUSELEAVE:
            type = WebInputEvent::MouseLeave;
            //m_webViewImpl->dragSourceSystemDragEnded();
            //m_webViewImpl->handleInputEvent(webMouseEvent);
            m_mouseInWindow = false;
            break;
        }
    }

    WebMouseEvent webMouseEvent(type, 0, WTF::currentTime());
    webMouseEvent.button = button;
    webMouseEvent.x = pos.x();
    webMouseEvent.y = pos.y();
    webMouseEvent.movementX = pos.x();
    webMouseEvent.movementY = pos.y();
    webMouseEvent.windowX = pos.x();
    webMouseEvent.windowY = pos.y();
    webMouseEvent.globalX = globalPos.x();
    webMouseEvent.globalY = globalPos.y();

    m_webViewImpl->handleInputEvent(webMouseEvent);
}

void WebPageImpl::loadURL(int64 frameId, const wchar_t* url, const blink::Referrer& referrer, const wchar_t* extraHeaders)
{
    int length = wcslen(url);
    String urlW((const UChar*)url, length);
    KURL kurl(ParsedURLString, urlW.utf8().data());

    WebURL webURL = kurl;
    blink::WebURLRequest request(webURL);
    loadRequest(frameId, request);
}

void WebPageImpl::loadRequest(int64 frameId, const blink::WebURLRequest& request)
{
    if (!m_webViewImpl || !m_webViewImpl->mainFrame())
        return;

    blink::WebURLRequest requestWrap(request);
    WebFrame* webFrame = getWebFrameFromFrameId(frameId);
    if (!webFrame)
        return;

    requestWrap.setHTTPHeaderField(WebString::fromLatin1("Accept"), WebString::fromLatin1("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"));
    webFrame->loadRequest(requestWrap);
}

void WebPageImpl::loadHTMLString(int64 frameId, const WebData& html, const WebURL& baseURL, const WebURL& unreachableURL, bool replace)
{
    if (!m_webViewImpl || !m_webViewImpl->mainFrame())
        return;

    WebFrame* webFrame = getWebFrameFromFrameId(frameId);
    if (!webFrame)
        return;
    webFrame->loadHTMLString(html, baseURL, unreachableURL, replace);
}

void WebPageImpl::sendOrientationChangeEvent()
{
    // debugwangTODO
    WebSettingsImpl* settings = m_webViewImpl->settingsImpl();
    settings->setFitScreenEnabled(false);
    return;

    WebFrame* frame = m_webViewImpl->mainFrame();
    if (!frame)
        return;
    WebLocalFrame* webFrame = frame->toWebLocalFrame();
    if (!webFrame)
        return;
    webFrame->sendOrientationChangeEvent();
}

void WebPageImpl::setFocus(bool enabel)
{
    m_webViewImpl->setFocus(enabel);
}

CefBrowserHostImpl* WebPageImpl::browser() const
{
    return m_browser;
}

void WebPageImpl::setBrowser(CefBrowserHostImpl* browser)
{
    m_browser = browser;
}

WebFrame* WebPageImpl::getWebFrameFromFrameId(int64 frameId)
{
    blink::WebFrame* webFrame = nullptr;
    if (WebPage::kMainFrameId != frameId) {
        //         Frame* frame = toCoreFrame(m_webViewImpl->mainFrame());
        //
        //         while (frame && frame->frameID() != frameId)
        //             frame = frame->tree().traverseNext();
        //         if (!frame)
        //             return nullptr;
        //
        //         webFrame = WebFrame::fromFrame(frame);
        DebugBreak();
    } else
        webFrame = m_webViewImpl->mainFrame();

    return webFrame;
}

WebStorageNamespace* WebPageImpl::createSessionStorageNamespace()
{
    return ((content::BlinkPlatformImpl*)Platform::current())->createSessionStorageNamespace();
}

static bool isKeypadEvent(WPARAM code, LPARAM keyData, WebInputEvent::Type type)
{
    if (type != WebInputEvent::RawKeyDown && type != WebInputEvent::KeyUp)
        return false;

    switch (code) {
    case VK_NUMLOCK:
    case VK_NUMPAD0:
    case VK_NUMPAD1:
    case VK_NUMPAD2:
    case VK_NUMPAD3:
    case VK_NUMPAD4:
    case VK_NUMPAD5:
    case VK_NUMPAD6:
    case VK_NUMPAD7:
    case VK_NUMPAD8:
    case VK_NUMPAD9:
    case VK_MULTIPLY:
    case VK_ADD:
    case VK_SEPARATOR:
    case VK_SUBTRACT:
    case VK_DECIMAL:
    case VK_DIVIDE:
        return true;
    case VK_RETURN:
        return HIWORD(keyData) & KF_EXTENDED;
    case VK_INSERT:
    case VK_DELETE:
    case VK_PRIOR:
    case VK_NEXT:
    case VK_END:
    case VK_HOME:
    case VK_LEFT:
    case VK_UP:
    case VK_RIGHT:
    case VK_DOWN:
        return !(HIWORD(keyData) & KF_EXTENDED);
    default:
        return false;
    }
}

static void setRuntimeEnabledFeatures()
{
    //    blink::RuntimeEnabledFeatures::setSlimmingPaintEnabled(true);
    blink::RuntimeEnabledFeatures::setXSLTEnabled(false);
    //    blink::RuntimeEnabledFeatures::setExperimentalStreamEnabled(false);
    blink::RuntimeEnabledFeatures::setFrameTimingSupportEnabled(false);
    blink::RuntimeEnabledFeatures::setSharedWorkerEnabled(false);
    blink::RuntimeEnabledFeatures::setOverlayScrollbarsEnabled(false);
    blink::RuntimeEnabledFeatures::setOrientationEventEnabled(true);
    //     blink::RuntimeEnabledFeatures::setAlwaysUseComplexTextEnabled(false);
    //     blink::RuntimeEnabledFeatures::setHiResEventTimeStampEnabled(false);
}

bool WebPageImpl::initSetting()
{
    WebSettingsImpl* settings = m_webViewImpl->settingsImpl();
    if (!settings)
        return false;

    blink::networkStateNotifier().setWebConnection(blink::WebConnectionTypeEthernet, 100);
    blink::networkStateNotifier().setOnLine(true);

    settings->setTextAreasAreResizable(true);
    settings->setStandardFontFamily(WebString(L"微软雅黑", 4));
    //settings->setUsesEncodingDetector(true);
    settings->setJavaScriptEnabled(true);
    settings->setAllowFileAccessFromFileURLs(true);
    settings->setAcceleratedCompositingEnabled(true);
    settings->setUseSolidColorScrollbars(false);
    settings->setTextAutosizingEnabled(true);
    settings->setMinimumFontSize(10);
    settings->setMinimumLogicalFontSize(10);
    settings->setDefaultFontSize(16);
    settings->setDefaultFixedFontSize(16);
    settings->setLoadsImagesAutomatically(true);
    settings->setJavaScriptEnabled(true);

    settings->setViewportStyle(blink::WebViewportStyle::Mobile);
    if (1) {
        settings->setViewportEnabled(true);
        settings->setFitScreenEnabled(false);
        //settings->setAutoDetectToOpenFitScreenEnabled(true);
        //m_webViewImpl->enableAutoResizeMode(WebSize(360, 600), WebSize(360, 600));
    }

    return true;
}

} // blink

#endif // WebPagePaint_h