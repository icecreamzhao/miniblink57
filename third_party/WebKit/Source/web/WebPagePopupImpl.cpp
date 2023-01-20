/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "web/WebPagePopupImpl.h"

#include "core/dom/ContextFeatures.h"
#include "core/events/MessageEvent.h"
#include "core/frame/FrameHost.h"
#include "core/frame/FrameView.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/Settings.h"
#include "core/frame/VisualViewport.h"
#include "core/input/EventHandler.h"
#include "core/layout/api/LayoutAPIShim.h"
#include "core/layout/api/LayoutViewItem.h"
#include "core/loader/EmptyClients.h"
#include "core/loader/FrameLoadRequest.h"
#include "core/page/FocusController.h"
#include "core/page/Page.h"
#include "core/page/PagePopupClient.h"
#include "core/page/PagePopupSupplement.h"
// #include "modules/accessibility/AXObject.h"
// #include "modules/accessibility/AXObjectCacheImpl.h"
#include "platform/EventDispatchForbiddenScope.h"
#include "platform/LayoutTestSupport.h"
#include "platform/ScriptForbiddenScope.h"
#include "platform/animation/CompositorAnimationHost.h"
#include "platform/heap/Handle.h"
#include "platform/instrumentation/tracing/TraceEvent.h"
#include "public/platform/WebCompositeAndReadbackAsyncCallback.h"
#include "public/platform/WebCursorInfo.h"
#include "public/platform/WebFloatRect.h"
//#include "public/web/WebAXObject.h"
=======
#include "config.h"
#include "web/WebPagePopupImpl.h"

#include "core/dom/ContextFeatures.h"
#include "core/frame/FrameHost.h"
#include "core/frame/FrameView.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/PinchViewport.h"
#include "core/frame/Settings.h"
#include "core/input/EventHandler.h"
#include "core/layout/LayoutView.h"
#include "core/loader/EmptyClients.h"
#include "core/loader/FrameLoadRequest.h"
#include "core/page/DOMWindowPagePopup.h"
#include "core/page/FocusController.h"
#include "core/page/Page.h"
#include "core/page/PagePopupClient.h"
#include "modules/accessibility/AXObject.h"
#include "modules/accessibility/AXObjectCacheImpl.h"
#include "platform/EventDispatchForbiddenScope.h"
#include "platform/LayoutTestSupport.h"
#include "platform/ScriptForbiddenScope.h"
#include "platform/TraceEvent.h"
#include "platform/heap/Handle.h"
#include "public/platform/WebCompositeAndReadbackAsyncCallback.h"
#include "public/platform/WebCursorInfo.h"
#include "public/web/WebAXObject.h"
>>>>>>> miniblink49
#include "public/web/WebFrameClient.h"
#include "public/web/WebViewClient.h"
#include "public/web/WebWidgetClient.h"
#include "web/WebInputEventConversion.h"
#include "web/WebLocalFrameImpl.h"
#include "web/WebSettingsImpl.h"
#include "web/WebViewImpl.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
=======
>>>>>>> miniblink49

namespace blink {

class PagePopupChromeClient final : public EmptyChromeClient {
<<<<<<< HEAD
public:
    static PagePopupChromeClient* create(WebPagePopupImpl* popup)
    {
        return new PagePopupChromeClient(popup);
    }

    void setWindowRect(const IntRect& rect, LocalFrame&) override
    {
        m_popup->setWindowRect(rect);
    }

private:
    explicit PagePopupChromeClient(WebPagePopupImpl* popup)
        : m_popup(popup)
    {
        DCHECK(m_popup->widgetClient());
    }

    void closeWindowSoon() override { m_popup->closePopup(); }

    IntRect rootWindowRect() override { return m_popup->windowRectInScreen(); }

    IntRect viewportToScreen(const IntRect& rect,
        const Widget* widget) const override
    {
        WebRect rectInScreen(rect);
        WebRect windowRect = m_popup->windowRectInScreen();
        m_popup->widgetClient()->convertViewportToWindow(&rectInScreen);
        rectInScreen.x += windowRect.x;
        rectInScreen.y += windowRect.y;
        return rectInScreen;
    }

    float windowToViewportScalar(const float scalarValue) const override
    {
        WebFloatRect viewportRect(0, 0, scalarValue, 0);
        m_popup->widgetClient()->convertWindowToViewport(&viewportRect);
        return viewportRect.width;
    }

    void addMessageToConsole(LocalFrame*,
        MessageSource,
        MessageLevel,
        const String& message,
        unsigned lineNumber,
        const String&,
        const String&) override
    {
#ifndef NDEBUG
        fprintf(stderr, "CONSOLE MESSSAGE:%u: %s\n", lineNumber,
            message.utf8().data());
=======
    WTF_MAKE_NONCOPYABLE(PagePopupChromeClient);
    WTF_MAKE_FAST_ALLOCATED(PagePopupChromeClient);

public:
    explicit PagePopupChromeClient(WebPagePopupImpl* popup)
        : m_popup(popup)
    {
        ASSERT(m_popup->widgetClient());
    }

    void setWindowRect(const IntRect& rect) override
    {
        m_popup->m_windowRectInScreen = rect;
        m_popup->widgetClient()->setWindowRect(m_popup->m_windowRectInScreen);
    }

private:
    void closeWindowSoon() override
    {
        m_popup->closePopup();
    }

    IntRect windowRect() override
    {
        return IntRect(m_popup->m_windowRectInScreen.x, m_popup->m_windowRectInScreen.y, m_popup->m_windowRectInScreen.width, m_popup->m_windowRectInScreen.height);
    }

    IntRect viewportToScreen(const IntRect& rect) const override
    {
        IntRect rectInScreen(rect);
        rectInScreen.move(m_popup->m_windowRectInScreen.x, m_popup->m_windowRectInScreen.y);
        return rectInScreen;
    }

    void addMessageToConsole(LocalFrame*, MessageSource, MessageLevel, const String& message, unsigned lineNumber, const String&, const String&) override
    {
#ifndef NDEBUG
        fprintf(stderr, "CONSOLE MESSSAGE:%u: %s\n", lineNumber, message.utf8().data());
>>>>>>> miniblink49
#endif
    }

    void invalidateRect(const IntRect& paintRect) override
    {
        if (!paintRect.isEmpty())
            m_popup->widgetClient()->didInvalidateRect(paintRect);
    }

<<<<<<< HEAD
    void scheduleAnimation(Widget*) override
    {
        // Calling scheduleAnimation on m_webView so WebViewTestProxy will call
        // beginFrame.
        if (LayoutTestSupport::isRunningLayoutTest())
            m_popup->m_webView->mainFrameImpl()->frameWidget()->scheduleAnimation();

        if (m_popup->isAcceleratedCompositingActive()) {
            DCHECK(m_popup->m_layerTreeView);
            m_popup->m_layerTreeView->setNeedsBeginFrame();
=======
    void scheduleAnimation() override
    {
        // Calling scheduleAnimation on m_webView so WebTestProxy will call beginFrame.
        if (LayoutTestSupport::isRunningLayoutTest())
            m_popup->m_webView->scheduleAnimation();

        if (m_popup->isAcceleratedCompositingActive()) {
            ASSERT(m_popup->m_layerTreeView);
            m_popup->m_layerTreeView->setNeedsAnimate();
>>>>>>> miniblink49
            return;
        }
        m_popup->m_widgetClient->scheduleAnimation();
    }

<<<<<<< HEAD
    void attachCompositorAnimationTimeline(CompositorAnimationTimeline* timeline,
        LocalFrame*) override
    {
        if (m_popup->m_animationHost)
            m_popup->m_animationHost->addTimeline(*timeline);
    }

    void detachCompositorAnimationTimeline(CompositorAnimationTimeline* timeline,
        LocalFrame*) override
    {
        if (m_popup->m_animationHost)
            m_popup->m_animationHost->removeTimeline(*timeline);
    }

    WebScreenInfo screenInfo() const override
    {
        return m_popup->m_webView->client()
            ? m_popup->m_webView->client()->screenInfo()
            : WebScreenInfo();
    }

    void* webView() const override { return m_popup->m_webView; }

    IntSize minimumWindowSize() const override { return IntSize(0, 0); }

    void setCursor(const Cursor& cursor, LocalFrame* localFrame) override
    {
        m_popup->m_widgetClient->didChangeCursor(WebCursorInfo(cursor));
    }

    void setEventListenerProperties(
        WebEventListenerClass eventClass,
        WebEventListenerProperties properties) override
    {
        if (m_popup->m_layerTreeView) {
            m_popup->m_layerTreeView->setEventListenerProperties(eventClass,
                properties);
            if (eventClass == WebEventListenerClass::TouchStartOrMove) {
                m_popup->widgetClient()->hasTouchEventHandlers(
                    properties != WebEventListenerProperties::Nothing || eventListenerProperties(WebEventListenerClass::TouchEndOrCancel) != WebEventListenerProperties::Nothing);
            } else if (eventClass == WebEventListenerClass::TouchEndOrCancel) {
                m_popup->widgetClient()->hasTouchEventHandlers(
                    properties != WebEventListenerProperties::Nothing || eventListenerProperties(WebEventListenerClass::TouchStartOrMove) != WebEventListenerProperties::Nothing);
            }
        } else {
            m_popup->widgetClient()->hasTouchEventHandlers(true);
        }
    }
    WebEventListenerProperties eventListenerProperties(
        WebEventListenerClass eventClass) const override
    {
        if (m_popup->m_layerTreeView)
            return m_popup->m_layerTreeView->eventListenerProperties(eventClass);
        return WebEventListenerProperties::Nothing;
    }

    void setHasScrollEventHandlers(bool hasEventHandlers) override
    {
        if (m_popup->m_layerTreeView)
            m_popup->m_layerTreeView->setHaveScrollEventHandlers(hasEventHandlers);
    }

    bool hasScrollEventHandlers() const override
    {
        if (m_popup->m_layerTreeView)
            return m_popup->m_layerTreeView->haveScrollEventHandlers();
        return false;
    }

    void setTouchAction(LocalFrame* frame, TouchAction touchAction) override
    {
        DCHECK(frame);
        WebLocalFrameImpl* webFrame = WebLocalFrameImpl::fromFrame(frame);
        WebFrameWidgetBase* widget = webFrame->localRoot()->frameWidget();
        if (!widget)
            return;

        if (WebWidgetClient* client = widget->client())
            client->setTouchAction(static_cast<WebTouchAction>(touchAction));
    }

    void attachRootGraphicsLayer(GraphicsLayer* graphicsLayer,
        LocalFrame* localRoot) override
=======
    WebScreenInfo screenInfo() const override
    {
        return m_popup->m_webView->client() ? m_popup->m_webView->client()->screenInfo() : WebScreenInfo();
    }

    void* webView() const override
    {
        return m_popup->m_webView;
    }

    IntSize minimumWindowSize() const override
    {
        return IntSize(0, 0);
    }

    void setCursor(const Cursor& cursor) override
    {
        if (m_popup->m_webView->client())
            m_popup->m_webView->client()->didChangeCursor(WebCursorInfo(cursor));
    }

    void needTouchEvents(bool needsTouchEvents) override
    {
        m_popup->widgetClient()->hasTouchEventHandlers(needsTouchEvents);
    }

    GraphicsLayerFactory* graphicsLayerFactory() const override
    {
        return m_popup->m_webView->graphicsLayerFactory();
    }

    void attachRootGraphicsLayer(GraphicsLayer* graphicsLayer, LocalFrame* localRoot) override
>>>>>>> miniblink49
    {
        m_popup->setRootGraphicsLayer(graphicsLayer);
    }

<<<<<<< HEAD
    //   void postAccessibilityNotification(
    //       AXObject* obj,
    //       AXObjectCache::AXNotification notification) override {
    //     WebLocalFrameImpl* frame = WebLocalFrameImpl::fromFrame(
    //         m_popup->m_popupClient->ownerElement().document().frame());
    //     if (obj && frame && frame->client())
    //       frame->client()->postAccessibilityEvent(
    //           WebAXObject(obj), static_cast<WebAXEvent>(notification));
    //   }

    void setToolTip(LocalFrame&,
        const String& tooltipText,
        TextDirection dir) override
    {
        if (m_popup->widgetClient())
            m_popup->widgetClient()->setToolTipText(tooltipText,
                toWebTextDirection(dir));
=======
    void postAccessibilityNotification(AXObject* obj, AXObjectCache::AXNotification notification) override
    {
#ifdef MINIBLINK_NOT_IMPLEMENTED
        WebLocalFrameImpl* frame = WebLocalFrameImpl::fromFrame(m_popup->m_popupClient->ownerElement().document().frame());
        if (obj && frame && frame->client())
            frame->client()->postAccessibilityEvent(WebAXObject(obj), static_cast<WebAXEvent>(notification));
#endif // MINIBLINK_NOT_IMPLEMENTED
        notImplemented();
    }

    void setToolTip(const String& tooltipText, TextDirection dir) override
    {
        if (m_popup->widgetClient())
            m_popup->widgetClient()->setToolTipText(tooltipText, toWebTextDirection(dir));
>>>>>>> miniblink49
    }

    WebPagePopupImpl* m_popup;
};

class PagePopupFeaturesClient : public ContextFeaturesClient {
    bool isEnabled(Document*, ContextFeatures::FeatureType, bool) override;
};

<<<<<<< HEAD
bool PagePopupFeaturesClient::isEnabled(Document*,
    ContextFeatures::FeatureType type,
    bool defaultValue)
=======
bool PagePopupFeaturesClient::isEnabled(Document*, ContextFeatures::FeatureType type, bool defaultValue)
>>>>>>> miniblink49
{
    if (type == ContextFeatures::PagePopup)
        return true;
    return defaultValue;
}

<<<<<<< HEAD
// WebPagePopupImpl ----------------------------------------------------------
=======
// WebPagePopupImpl ----------------------------------------------------------------
>>>>>>> miniblink49

WebPagePopupImpl::WebPagePopupImpl(WebWidgetClient* client)
    : m_widgetClient(client)
    , m_closing(false)
    , m_layerTreeView(0)
    , m_rootLayer(0)
    , m_rootGraphicsLayer(0)
    , m_isAcceleratedCompositingActive(false)
{
<<<<<<< HEAD
    DCHECK(client);
=======
    ASSERT(client);
>>>>>>> miniblink49
}

WebPagePopupImpl::~WebPagePopupImpl()
{
<<<<<<< HEAD
    DCHECK(!m_page);
}

bool WebPagePopupImpl::initialize(WebViewImpl* webView,
    PagePopupClient* popupClient)
{
    DCHECK(webView);
    DCHECK(popupClient);
    m_webView = webView;
    m_popupClient = popupClient;

    if (!m_widgetClient || !initializePage())
        return false;
    m_widgetClient->show(WebNavigationPolicy());
    setFocus(true);

=======
    ASSERT(!m_page);
}

bool WebPagePopupImpl::initialize(WebViewImpl* webView, PagePopupClient* popupClient)
{
    ASSERT(webView);
    ASSERT(popupClient);
    m_webView = webView;
    m_popupClient = popupClient;

    resize(m_popupClient->contentSize());

    if (!m_widgetClient || !initializePage())
        return false;
    m_widgetClient->scheduleAnimation();
    m_widgetClient->show(WebNavigationPolicy());
    setFocus(true);
>>>>>>> miniblink49
    return true;
}

bool WebPagePopupImpl::initializePage()
{
    Page::PageClients pageClients;
    fillWithEmptyClients(pageClients);
<<<<<<< HEAD
    m_chromeClient = PagePopupChromeClient::create(this);
    pageClients.chromeClient = m_chromeClient.get();

    Settings& mainSettings = m_webView->page()->settings();
    m_page = Page::create(pageClients);
    m_page->settings().setScriptEnabled(true);
    m_page->settings().setAllowScriptsToCloseWindows(true);
    m_page->settings().setDeviceSupportsTouch(
        mainSettings.getDeviceSupportsTouch());
    m_page->settings().setMinimumFontSize(mainSettings.getMinimumFontSize());
    m_page->settings().setMinimumLogicalFontSize(
        mainSettings.getMinimumLogicalFontSize());
    // FIXME: Should we support enabling a11y while a popup is shown?
    m_page->settings().setAccessibilityEnabled(
        mainSettings.getAccessibilityEnabled());
    m_page->settings().setScrollAnimatorEnabled(
        mainSettings.getScrollAnimatorEnabled());

    provideContextFeaturesTo(*m_page, WTF::makeUnique<PagePopupFeaturesClient>());
    DEFINE_STATIC_LOCAL(FrameLoaderClient, emptyFrameLoaderClient,
        (EmptyFrameLoaderClient::create()));
    LocalFrame* frame = LocalFrame::create(&emptyFrameLoaderClient, &m_page->frameHost(), 0);
    frame->setPagePopupOwner(m_popupClient->ownerElement());
    frame->setView(FrameView::create(*frame));
    frame->init();
    frame->view()->setParentVisible(true);
    frame->view()->setSelfVisible(true);
=======
    m_chromeClient = adoptPtr(new PagePopupChromeClient(this));
    pageClients.chromeClient = m_chromeClient.get();

    m_page = adoptPtrWillBeNoop(new Page(pageClients));
    m_page->settings().setScriptEnabled(true);
    m_page->settings().setAllowScriptsToCloseWindows(true);
    m_page->setDeviceScaleFactor(m_webView->deviceScaleFactor());
    m_page->settings().setDeviceSupportsTouch(m_webView->page()->settings().deviceSupportsTouch());
    // FIXME: Should we support enabling a11y while a popup is shown?
    m_page->settings().setAccessibilityEnabled(m_webView->page()->settings().accessibilityEnabled());
    m_page->settings().setScrollAnimatorEnabled(m_webView->page()->settings().scrollAnimatorEnabled());

    provideContextFeaturesTo(*m_page, adoptPtr(new PagePopupFeaturesClient()));
    static FrameLoaderClient* emptyFrameLoaderClient = new EmptyFrameLoaderClient();
    RefPtrWillBeRawPtr<LocalFrame> frame = LocalFrame::create(emptyFrameLoaderClient, &m_page->frameHost(), 0);
    frame->setPagePopupOwner(m_popupClient->ownerElement());
    frame->setView(FrameView::create(frame.get()));
    frame->init();
    frame->view()->resize(m_popupClient->contentSize());
>>>>>>> miniblink49
    frame->view()->setTransparent(false);
    if (AXObjectCache* cache = m_popupClient->ownerElement().document().existingAXObjectCache())
        cache->childrenChanged(&m_popupClient->ownerElement());

<<<<<<< HEAD
    DCHECK(frame->domWindow());
    PagePopupSupplement::install(*frame, *this, m_popupClient);
    DCHECK_EQ(m_popupClient->ownerElement().document().existingAXObjectCache(),
        frame->document()->existingAXObjectCache());

    RefPtr<SharedBuffer> data = SharedBuffer::create();
    m_popupClient->writeDocument(data.get());
    frame->loader().load(FrameLoadRequest(
        0, blankURL(), SubstituteData(data, "text/html", "UTF-8", KURL(), ForceSynchronousLoad)));
    frame->setPageZoomFactor(m_popupClient->zoomFactor());
=======
    ASSERT(frame->localDOMWindow());
    DOMWindowPagePopup::install(*frame->localDOMWindow(), *this, m_popupClient);
    ASSERT(m_popupClient->ownerElement().document().existingAXObjectCache() == frame->document()->existingAXObjectCache());

    RefPtr<SharedBuffer> data = SharedBuffer::create();
    m_popupClient->writeDocument(data.get());
    //////////////////////////////////////////////////////////////////////////
//     OutputDebugStringW(L"WebPagePopupImpl::initializePage:\n");
//     String xx = String::fromUTF8(data->data(), data->size());
//     xx.append('\n');
//     OutputDebugStringW(xx.charactersWithNullTermination().data());
//     OutputDebugStringW(L"WebPagePopupImpl::initializePage ------ \n");

//     data->clear();
//     Vector<char> buffer;
//     readScript(L"E:\\test\\select.htm", buffer);
//     data->append(buffer.data(), buffer.size());
//     PagePopupClient::addString(testWebPagePopupImpl, data.get());
    //////////////////////////////////////////////////////////////////////////

    frame->loader().load(FrameLoadRequest(0, blankURL(), SubstituteData(data, "text/html", "UTF-8", KURL(), ForceSynchronousLoad)));
>>>>>>> miniblink49
    return true;
}

void WebPagePopupImpl::postMessage(const String& message)
{
    if (!m_page)
        return;
    ScriptForbiddenScope::AllowUserAgentScript allowScript;
<<<<<<< HEAD
    if (LocalDOMWindow* window = toLocalFrame(m_page->mainFrame())->domWindow())
=======
    if (LocalDOMWindow* window = toLocalFrame(m_page->mainFrame())->localDOMWindow())
>>>>>>> miniblink49
        window->dispatchEvent(MessageEvent::create(message));
}

void WebPagePopupImpl::destroyPage()
{
    if (!m_page)
        return;

    m_page->willBeDestroyed();
    m_page.clear();
}

<<<<<<< HEAD
// AXObject* WebPagePopupImpl::rootAXObject() {
//   if (!m_page || !m_page->mainFrame())
//     return 0;
//   Document* document = toLocalFrame(m_page->mainFrame())->document();
//   if (!document)
//     return 0;
//   AXObjectCache* cache = document->axObjectCache();
//   DCHECK(cache);
//   return toAXObjectCacheImpl(cache)->getOrCreate(toLayoutView(
//       LayoutAPIShim::layoutObjectFrom(document->layoutViewItem())));
// }

void WebPagePopupImpl::setWindowRect(const IntRect& rectInScreen)
{
    widgetClient()->setWindowRect(rectInScreen);
=======
AXObject* WebPagePopupImpl::rootAXObject()
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (!m_page || !m_page->mainFrame())
        return 0;
    Document* document = toLocalFrame(m_page->mainFrame())->document();
    if (!document)
        return 0;
    AXObjectCache* cache = document->axObjectCache();
    ASSERT(cache);
    return toAXObjectCacheImpl(cache)->getOrCreate(document->layoutView());
#endif // MINIBLINK_NOT_IMPLEMENTED
    return 0;
}

void WebPagePopupImpl::setWindowRect(const IntRect& rect)
{
    m_chromeClient->setWindowRect(rect);
>>>>>>> miniblink49
}

void WebPagePopupImpl::setRootGraphicsLayer(GraphicsLayer* layer)
{
    m_rootGraphicsLayer = layer;
    m_rootLayer = layer ? layer->platformLayer() : 0;

    setIsAcceleratedCompositingActive(layer);
    if (m_layerTreeView) {
        if (m_rootLayer) {
            m_layerTreeView->setRootLayer(*m_rootLayer);
        } else {
            m_layerTreeView->clearRootLayer();
        }
    }
}

void WebPagePopupImpl::setIsAcceleratedCompositingActive(bool enter)
{
    if (m_isAcceleratedCompositingActive == enter)
        return;

    if (!enter) {
        m_isAcceleratedCompositingActive = false;
    } else if (m_layerTreeView) {
        m_isAcceleratedCompositingActive = true;
    } else {
<<<<<<< HEAD
        TRACE_EVENT0("blink",
            "WebPagePopupImpl::setIsAcceleratedCompositingActive(true)");

        m_layerTreeView = m_widgetClient->initializeLayerTreeView();
        if (m_layerTreeView) {
            m_layerTreeView->setVisible(true);
            m_isAcceleratedCompositingActive = true;
            m_animationHost = WTF::makeUnique<CompositorAnimationHost>(
                m_layerTreeView->compositorAnimationHost());
            m_page->layerTreeViewInitialized(*m_layerTreeView, nullptr);
        } else {
            m_isAcceleratedCompositingActive = false;
            m_animationHost = nullptr;
=======
        TRACE_EVENT0("blink", "WebPagePopupImpl::setIsAcceleratedCompositingActive(true)");

        m_widgetClient->initializeLayerTreeView();
        m_layerTreeView = m_widgetClient->layerTreeView();
        if (m_layerTreeView) {
            m_layerTreeView->setVisible(true);
            m_isAcceleratedCompositingActive = true;
            m_layerTreeView->setDeviceScaleFactor(m_widgetClient->deviceScaleFactor());
        } else {
            m_isAcceleratedCompositingActive = false;
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
void WebPagePopupImpl::beginFrame(double lastFrameTimeMonotonic)
{
    if (!m_page)
        return;
    // FIXME: This should use lastFrameTimeMonotonic but doing so
    // breaks tests.
    PageWidgetDelegate::animate(*m_page, monotonicallyIncreasingTime());
=======
WebSize WebPagePopupImpl::size()
{
    return m_popupClient->contentSize();
}

void WebPagePopupImpl::beginFrame(const WebBeginFrameArgs& frameTime)
{
    if (!m_page)
        return;
    // FIXME: This should use frameTime.lastFrameTimeMonotonic but doing so
    // breaks tests.
    PageWidgetDelegate::animate(*m_page, monotonicallyIncreasingTime(), *m_page->deprecatedLocalMainFrame());
>>>>>>> miniblink49
}

void WebPagePopupImpl::willCloseLayerTreeView()
{
<<<<<<< HEAD
    if (m_page && m_layerTreeView)
        m_page->willCloseLayerTreeView(*m_layerTreeView, nullptr);

    setIsAcceleratedCompositingActive(false);
    m_layerTreeView = nullptr;
    m_animationHost = nullptr;
}

void WebPagePopupImpl::updateAllLifecyclePhases()
{
    if (!m_page)
        return;
    PageWidgetDelegate::updateAllLifecyclePhases(
        *m_page, *m_page->deprecatedLocalMainFrame());
=======
    setIsAcceleratedCompositingActive(false);
    m_layerTreeView = 0;
}

void WebPagePopupImpl::layout()
{
    if (!m_page)
        return;
    PageWidgetDelegate::layout(*m_page, *m_page->deprecatedLocalMainFrame());
>>>>>>> miniblink49
}

void WebPagePopupImpl::paint(WebCanvas* canvas, const WebRect& rect)
{
    if (!m_closing)
<<<<<<< HEAD
        PageWidgetDelegate::paint(*m_page, canvas, rect,
            *m_page->deprecatedLocalMainFrame());
}

void WebPagePopupImpl::resize(const WebSize& newSizeInViewport)
{
    WebRect newSize(0, 0, newSizeInViewport.width, newSizeInViewport.height);
    widgetClient()->convertViewportToWindow(&newSize);

    WebRect windowRect = windowRectInScreen();

    // TODO(bokan): We should only call into this if the bounds actually changed
    // but this reveals a bug in Aura. crbug.com/633140.
    windowRect.width = newSize.width;
    windowRect.height = newSize.height;
    setWindowRect(windowRect);

    if (m_page) {
        toLocalFrame(m_page->mainFrame())->view()->resize(newSizeInViewport);
        m_page->frameHost().visualViewport().setSize(newSizeInViewport);
    }

    m_widgetClient->didInvalidateRect(
        WebRect(0, 0, newSize.width, newSize.height));
}

WebInputEventResult WebPagePopupImpl::handleKeyEvent(
    const WebKeyboardEvent& event)
{
    if (m_closing || !m_page->mainFrame() || !toLocalFrame(m_page->mainFrame())->view())
        return WebInputEventResult::NotHandled;
    return toLocalFrame(m_page->mainFrame())->eventHandler().keyEvent(event);
}

WebInputEventResult WebPagePopupImpl::handleCharEvent(
    const WebKeyboardEvent& event)
{
    return handleKeyEvent(event);
}

WebInputEventResult WebPagePopupImpl::handleGestureEvent(
    const WebGestureEvent& event)
{
    if (m_closing || !m_page || !m_page->mainFrame() || !toLocalFrame(m_page->mainFrame())->view())
        return WebInputEventResult::NotHandled;
    if ((event.type() == WebInputEvent::GestureTap || event.type() == WebInputEvent::GestureTapDown) && !isViewportPointInWindow(event.x, event.y)) {
        cancel();
        return WebInputEventResult::NotHandled;
    }
    LocalFrame& frame = *toLocalFrame(m_page->mainFrame());
    WebGestureEvent scaledEvent = TransformWebGestureEvent(frame.view(), event);
    return frame.eventHandler().handleGestureEvent(scaledEvent);
}

void WebPagePopupImpl::handleMouseDown(LocalFrame& mainFrame,
    const WebMouseEvent& event)
{
    if (isViewportPointInWindow(event.x, event.y))
=======
        PageWidgetDelegate::paint(*m_page, 0, canvas, rect, *m_page->deprecatedLocalMainFrame());
}

void WebPagePopupImpl::resize(const WebSize& newSize)
{
    m_windowRectInScreen = WebRect(m_windowRectInScreen.x, m_windowRectInScreen.y, newSize.width, newSize.height);
    m_widgetClient->setWindowRect(m_windowRectInScreen);

    if (m_page) {
        toLocalFrame(m_page->mainFrame())->view()->resize(newSize);
        m_page->frameHost().pinchViewport().setSize(newSize);
    }

    m_widgetClient->didInvalidateRect(WebRect(0, 0, newSize.width, newSize.height));
}

bool WebPagePopupImpl::handleKeyEvent(const WebKeyboardEvent& event)
{
    return handleKeyEvent(PlatformKeyboardEventBuilder(event));
}

bool WebPagePopupImpl::handleCharEvent(const WebKeyboardEvent& event)
{
    return handleKeyEvent(PlatformKeyboardEventBuilder(event));
}

bool WebPagePopupImpl::handleGestureEvent(const WebGestureEvent& event)
{
    if (m_closing || !m_page || !m_page->mainFrame() || !toLocalFrame(m_page->mainFrame())->view())
        return false;
    LocalFrame& frame = *toLocalFrame(m_page->mainFrame());
    return frame.eventHandler().handleGestureEvent(PlatformGestureEventBuilder(frame.view(), event));
}

void WebPagePopupImpl::handleMouseDown(LocalFrame& mainFrame, const WebMouseEvent& event)
{
    if (isMouseEventInWindow(event))
>>>>>>> miniblink49
        PageWidgetEventHandler::handleMouseDown(mainFrame, event);
    else
        cancel();
}

<<<<<<< HEAD
WebInputEventResult WebPagePopupImpl::handleMouseWheel(
    LocalFrame& mainFrame,
    const WebMouseWheelEvent& event)
{
    if (isViewportPointInWindow(event.x, event.y))
        return PageWidgetEventHandler::handleMouseWheel(mainFrame, event);
    cancel();
    return WebInputEventResult::NotHandled;
}

bool WebPagePopupImpl::isViewportPointInWindow(int x, int y)
{
    WebRect pointInWindow(x, y, 0, 0);
    widgetClient()->convertViewportToWindow(&pointInWindow);
    WebRect windowRect = windowRectInScreen();
    return IntRect(0, 0, windowRect.width, windowRect.height)
        .contains(IntPoint(pointInWindow.x, pointInWindow.y));
}

WebInputEventResult WebPagePopupImpl::handleInputEvent(
    const WebInputEvent& event)
{
    if (m_closing)
        return WebInputEventResult::NotHandled;
    return PageWidgetDelegate::handleInputEvent(
        *this, WebCoalescedInputEvent(event), m_page->deprecatedLocalMainFrame());
=======
bool WebPagePopupImpl::handleMouseWheel(LocalFrame& mainFrame, const WebMouseWheelEvent& event)
{
    if (isMouseEventInWindow(event))
        return PageWidgetEventHandler::handleMouseWheel(mainFrame, event);
    cancel();
    return false;
}

bool WebPagePopupImpl::isMouseEventInWindow(const WebMouseEvent& event)
{
    return IntRect(0, 0, m_windowRectInScreen.width, m_windowRectInScreen.height).contains(IntPoint(event.x, event.y));
}

bool WebPagePopupImpl::handleInputEvent(const WebInputEvent& event)
{
    if (m_closing)
        return false;
    return PageWidgetDelegate::handleInputEvent(*this, event, m_page->deprecatedLocalMainFrame());
}

bool WebPagePopupImpl::handleKeyEvent(const PlatformKeyboardEvent& event)
{
    if (m_closing || !m_page->mainFrame() || !toLocalFrame(m_page->mainFrame())->view())
        return false;
    return toLocalFrame(m_page->mainFrame())->eventHandler().keyEvent(event);
>>>>>>> miniblink49
}

void WebPagePopupImpl::setFocus(bool enable)
{
    if (!m_page)
        return;
    m_page->focusController().setFocused(enable);
    if (enable)
        m_page->focusController().setActive(true);
}

void WebPagePopupImpl::close()
{
    m_closing = true;
<<<<<<< HEAD
    // In case closePopup() was not called.
    if (m_page)
        cancel();
    m_widgetClient = nullptr;
=======
    destroyPage(); // In case closePopup() was not called.
    m_widgetClient = 0;
>>>>>>> miniblink49
    deref();
}

void WebPagePopupImpl::closePopup()
{
<<<<<<< HEAD
    {
        // This function can be called in EventDispatchForbiddenScope for the main
        // document, and the following operations dispatch some events.  It's safe
        // because web authors can't listen the events.
        EventDispatchForbiddenScope::AllowUserAgentEvents allowEvents;

        if (m_page) {
            toLocalFrame(m_page->mainFrame())->loader().stopAllLoaders();
            PagePopupSupplement::uninstall(*toLocalFrame(m_page->mainFrame()));
        }
        bool closeAlreadyCalled = m_closing;
        m_closing = true;

        destroyPage();

        // m_widgetClient might be 0 because this widget might be already closed.
        if (m_widgetClient && !closeAlreadyCalled) {
            // closeWidgetSoon() will call this->close() later.
            m_widgetClient->closeWidgetSoon();
        }
    }
    m_popupClient->didClosePopup();
    m_webView->cleanupPagePopup();
=======
    // This function can be called in EventDispatchForbiddenScope for the main
    // document, and the following operations dispatch some events.  It's safe
    // because web authors can't listen the events.
    EventDispatchForbiddenScope::AllowUserAgentEvents allowEvents;

    if (m_page) {
        toLocalFrame(m_page->mainFrame())->loader().stopAllLoaders();
        ASSERT(m_page->deprecatedLocalMainFrame()->localDOMWindow());
        DOMWindowPagePopup::uninstall(*m_page->deprecatedLocalMainFrame()->localDOMWindow());
    }
    m_closing = true;

    destroyPage();

    // m_widgetClient might be 0 because this widget might be already closed.
    if (m_widgetClient) {
        // closeWidgetSoon() will call this->close() later.
        m_widgetClient->closeWidgetSoon();
    }

    m_popupClient->didClosePopup();
>>>>>>> miniblink49
}

LocalDOMWindow* WebPagePopupImpl::window()
{
<<<<<<< HEAD
    return m_page->deprecatedLocalMainFrame()->domWindow();
}

void WebPagePopupImpl::layoutAndPaintAsync(
    WebLayoutAndPaintAsyncCallback* callback)
=======
    return m_page->deprecatedLocalMainFrame()->localDOMWindow();
}

void WebPagePopupImpl::layoutAndPaintAsync(WebLayoutAndPaintAsyncCallback* callback)
>>>>>>> miniblink49
{
    m_layerTreeView->layoutAndPaintAsync(callback);
}

<<<<<<< HEAD
void WebPagePopupImpl::compositeAndReadbackAsync(
    WebCompositeAndReadbackAsyncCallback* callback)
{
    DCHECK(isAcceleratedCompositingActive());
=======
void WebPagePopupImpl::compositeAndReadbackAsync(WebCompositeAndReadbackAsyncCallback* callback)
{
    ASSERT(isAcceleratedCompositingActive());
>>>>>>> miniblink49
    m_layerTreeView->compositeAndReadbackAsync(callback);
}

WebPoint WebPagePopupImpl::positionRelativeToOwner()
{
<<<<<<< HEAD
    WebRect rootWindowRect = m_webView->client()->rootWindowRect();
    WebRect windowRect = windowRectInScreen();
    return WebPoint(windowRect.x - rootWindowRect.x,
        windowRect.y - rootWindowRect.y);
=======
    WebRect windowRect = m_webView->client()->rootWindowRect();
    return WebPoint(m_windowRectInScreen.x - windowRect.x, m_windowRectInScreen.y - windowRect.y);
>>>>>>> miniblink49
}

void WebPagePopupImpl::cancel()
{
    if (m_popupClient)
        m_popupClient->closePopup();
}

<<<<<<< HEAD
WebRect WebPagePopupImpl::windowRectInScreen() const
{
    return widgetClient()->windowRect();
}

=======
>>>>>>> miniblink49
// WebPagePopup ----------------------------------------------------------------

WebPagePopup* WebPagePopup::create(WebWidgetClient* client)
{
    if (!client)
        CRASH();
    // A WebPagePopupImpl instance usually has two references.
    //  - One owned by the instance itself. It represents the visible widget.
    //  - One owned by a WebViewImpl. It's released when the WebViewImpl ask the
    //    WebPagePopupImpl to close.
    // We need them because the closing operation is asynchronous and the widget
    // can be closed while the WebViewImpl is unaware of it.
    return adoptRef(new WebPagePopupImpl(client)).leakRef();
}

} // namespace blink
