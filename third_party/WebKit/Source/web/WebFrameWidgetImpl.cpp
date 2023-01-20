/*
 * Copyright (C) 2014 Google Inc. All rights reserved.
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
#include "web/WebFrameWidgetImpl.h"

#include "core/dom/DocumentUserGestureToken.h"
#include "core/editing/EditingUtilities.h"
=======
#include "config.h"
#include "web/WebFrameWidgetImpl.h"

>>>>>>> miniblink49
#include "core/editing/Editor.h"
#include "core/editing/FrameSelection.h"
#include "core/editing/InputMethodController.h"
#include "core/editing/PlainTextRange.h"
<<<<<<< HEAD
#include "core/frame/FrameHost.h"
#include "core/frame/FrameView.h"
#include "core/frame/RemoteFrame.h"
#include "core/frame/Settings.h"
#include "core/frame/VisualViewport.h"
#include "core/html/HTMLTextAreaElement.h"
#include "core/input/EventHandler.h"
#include "core/layout/LayoutView.h"
#include "core/layout/api/LayoutViewItem.h"
#include "core/layout/compositing/PaintLayerCompositor.h"
#include "core/page/ContextMenuController.h"
#include "core/page/FocusController.h"
#include "core/page/Page.h"
#include "core/page/PointerLockController.h"
#include "platform/KeyboardCodes.h"
#include "platform/WebFrameScheduler.h"
#include "platform/animation/CompositorAnimationHost.h"
#include "platform/graphics/CompositorMutatorClient.h"
#include "public/web/WebAutofillClient.h"
#include "public/web/WebPlugin.h"
#include "public/web/WebRange.h"
#include "public/web/WebWidgetClient.h"
#include "web/CompositionUnderlineVectorBuilder.h"
#include "web/CompositorMutatorImpl.h"
#include "web/CompositorProxyClientImpl.h"
#include "web/ContextMenuAllowedScope.h"
//#include "web/InspectorOverlay.h"
#include "web/PageOverlay.h"
//#include "web/WebDevToolsAgentImpl.h"
#include "web/WebInputEventConversion.h"
#include "web/WebInputMethodControllerImpl.h"
#include "web/WebLocalFrameImpl.h"
#include "web/WebPluginContainerImpl.h"
#include "web/WebRemoteFrameImpl.h"
#include "web/WebViewFrameWidget.h"
#include "wtf/AutoReset.h"
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

// WebFrameWidget ------------------------------------------------------------

WebFrameWidget* WebFrameWidget::create(WebWidgetClient* client,
    WebLocalFrame* localRoot)
=======
#include "core/frame/FrameView.h"
#include "core/frame/RemoteFrame.h"
#include "core/frame/Settings.h"
#include "core/input/EventHandler.h"
#include "core/layout/LayoutView.h"
#include "core/layout/compositing/DeprecatedPaintLayerCompositor.h"
#include "core/page/FocusController.h"
#include "core/page/Page.h"
#include "platform/KeyboardCodes.h"
#include "platform/NotImplemented.h"
#include "public/web/WebBeginFrameArgs.h"
#include "public/web/WebWidgetClient.h"
#include "web/WebDevToolsAgentImpl.h"
#include "web/WebInputEventConversion.h"
#include "web/WebLocalFrameImpl.h"
#include "web/WebPluginContainerImpl.h"
#include "web/WebRemoteFrameImpl.h"
#include "web/WebViewImpl.h"
#include "wtf/RefCountedLeakCounter.h"

namespace blink {

// WebFrameWidget ----------------------------------------------------------------

WebFrameWidget* WebFrameWidget::create(WebWidgetClient* client, WebLocalFrame* localRoot)
>>>>>>> miniblink49
{
    // Pass the WebFrameWidget's self-reference to the caller.
    return WebFrameWidgetImpl::create(client, localRoot);
}

<<<<<<< HEAD
WebFrameWidget* WebFrameWidget::create(WebWidgetClient* client,
    WebView* webView,
    WebLocalFrame* mainFrame)
{
    return new WebViewFrameWidget(client, toWebViewImpl(*webView),
        toWebLocalFrameImpl(*mainFrame));
}

WebFrameWidgetImpl* WebFrameWidgetImpl::create(WebWidgetClient* client,
    WebLocalFrame* localRoot)
{
    // Pass the WebFrameWidgetImpl's self-reference to the caller.
    return new WebFrameWidgetImpl(
        client, localRoot); // SelfKeepAlive is set in constructor.
}

WebFrameWidgetImpl::WebFrameWidgetImpl(WebWidgetClient* client,
    WebLocalFrame* localRoot)
    : m_client(client)
    , m_localRoot(toWebLocalFrameImpl(localRoot))
    , m_mutator(nullptr)
=======
WebFrameWidgetImpl* WebFrameWidgetImpl::create(WebWidgetClient* client, WebLocalFrame* localRoot)
{
    // Pass the WebFrameWidgetImpl's self-reference to the caller.
    return adoptRef(new WebFrameWidgetImpl(client, localRoot)).leakRef();
}

// static
HashSet<WebFrameWidgetImpl*>& WebFrameWidgetImpl::allInstances()
{
    DEFINE_STATIC_LOCAL(HashSet<WebFrameWidgetImpl*>, allInstances, ());
    return allInstances;
}

#ifndef NDEBUG
DEFINE_DEBUG_ONLY_GLOBAL(WTF::RefCountedLeakCounter, webFrameWidgetImplCounter, ("WebFrameWidgetImplCounter"));
#endif

WebFrameWidgetImpl::WebFrameWidgetImpl(WebWidgetClient* client, WebLocalFrame* localRoot)
    : m_client(client)
    , m_localRoot(toWebLocalFrameImpl(localRoot))
>>>>>>> miniblink49
    , m_layerTreeView(nullptr)
    , m_rootLayer(nullptr)
    , m_rootGraphicsLayer(nullptr)
    , m_isAcceleratedCompositingActive(false)
    , m_layerTreeViewClosed(false)
    , m_suppressNextKeypressEvent(false)
<<<<<<< HEAD
    , m_isTransparent(false)
    , m_imeAcceptEvents(true)
    , m_selfKeepAlive(this)
{
    DCHECK(m_localRoot->frame()->isLocalRoot());
    initializeLayerTreeView();
    m_localRoot->setFrameWidget(this);

    if (localRoot->parent())
        setIsTransparent(true);
}

WebFrameWidgetImpl::~WebFrameWidgetImpl() { }

DEFINE_TRACE(WebFrameWidgetImpl)
{
    visitor->trace(m_localRoot);
    visitor->trace(m_mouseCaptureNode);
=======
    , m_ignoreInputEvents(false)
{
    ASSERT(m_localRoot->frame()->isLocalRoot());
    initializeLayerTreeView();
    m_localRoot->setFrameWidget(this);
    allInstances().add(this);

#ifndef NDEBUG
    webFrameWidgetImplCounter.increment();
#endif
}

WebFrameWidgetImpl::~WebFrameWidgetImpl()
{
#ifndef NDEBUG
    webFrameWidgetImplCounter.decrement();
#endif
>>>>>>> miniblink49
}

// WebWidget ------------------------------------------------------------------

void WebFrameWidgetImpl::close()
{
<<<<<<< HEAD
=======
    WebDevToolsAgentImpl::webFrameWidgetImplClosed(this);
    ASSERT(allInstances().contains(this));
    allInstances().remove(this);

>>>>>>> miniblink49
    m_localRoot->setFrameWidget(nullptr);
    m_localRoot = nullptr;
    // Reset the delegate to prevent notifications being sent as we're being
    // deleted.
    m_client = nullptr;

<<<<<<< HEAD
    m_mutator = nullptr;
    m_layerTreeView = nullptr;
    m_rootLayer = nullptr;
    m_rootGraphicsLayer = nullptr;
    m_animationHost = nullptr;

    m_selfKeepAlive.clear();
=======
    deref(); // Balances ref() acquired in WebFrameWidget::create
>>>>>>> miniblink49
}

WebSize WebFrameWidgetImpl::size()
{
    return m_size;
}

<<<<<<< HEAD
=======
void WebFrameWidgetImpl::willStartLiveResize()
{
    if (m_localRoot->frameView())
        m_localRoot->frameView()->willStartLiveResize();
}

>>>>>>> miniblink49
void WebFrameWidgetImpl::resize(const WebSize& newSize)
{
    if (m_size == newSize)
        return;

    FrameView* view = m_localRoot->frameView();
    if (!view)
        return;

    m_size = newSize;

    updateMainFrameLayoutSize();

    view->resize(m_size);

<<<<<<< HEAD
    // FIXME: In WebViewImpl this layout was a precursor to setting the minimum
    // scale limit.  It is not clear if this is necessary for frame-level widget
    // resize.
    if (view->needsLayout())
        view->layout();

    // FIXME: Investigate whether this is needed; comment from eseidel suggests
    // that this function is flawed.
=======
    // FIXME: In WebViewImpl this layout was a precursor to setting the minimum scale limit.
    // It is not clear if this is necessary for frame-level widget resize.
    if (view->needsLayout())
        view->layout();

    // FIXME: Investigate whether this is needed; comment from eseidel suggests that this function
    // is flawed.
>>>>>>> miniblink49
    sendResizeEventAndRepaint();
}

void WebFrameWidgetImpl::sendResizeEventAndRepaint()
{
    // FIXME: This is wrong. The FrameView is responsible sending a resizeEvent
    // as part of layout. Layout is also responsible for sending invalidations
    // to the embedder. This method and all callers may be wrong. -- eseidel.
    if (m_localRoot->frameView()) {
        // Enqueues the resize event.
        m_localRoot->frame()->document()->enqueueResizeEvent();
    }

    if (m_client) {
        if (isAcceleratedCompositingActive()) {
            updateLayerTreeViewport();
        } else {
            WebRect damagedRect(0, 0, m_size.width, m_size.height);
            m_client->didInvalidateRect(damagedRect);
        }
    }
}

<<<<<<< HEAD
void WebFrameWidgetImpl::resizeVisualViewport(const WebSize& newSize)
{
    // TODO(alexmos, kenrb): resizing behavior such as this should be changed
    // to use Page messages.  https://crbug.com/599688.
    page()->frameHost().visualViewport().setSize(newSize);
    page()->frameHost().visualViewport().clampToBoundaries();

    view()->didUpdateFullscreenSize();
=======
void WebFrameWidgetImpl::resizePinchViewport(const WebSize& newSize)
{
    // FIXME: Implement pinch viewport for out-of-process iframes.
>>>>>>> miniblink49
}

void WebFrameWidgetImpl::updateMainFrameLayoutSize()
{
    if (!m_localRoot)
        return;

<<<<<<< HEAD
    FrameView* view = m_localRoot->frameView();
=======
    RefPtrWillBeRawPtr<FrameView> view = m_localRoot->frameView();
>>>>>>> miniblink49
    if (!view)
        return;

    WebSize layoutSize = m_size;

    view->setLayoutSize(layoutSize);
}

<<<<<<< HEAD
void WebFrameWidgetImpl::didEnterFullscreen()
{
    view()->didEnterFullscreen();
}

void WebFrameWidgetImpl::didExitFullscreen()
{
    view()->didExitFullscreen();
}

void WebFrameWidgetImpl::beginFrame(double lastFrameTimeMonotonic)
{
    TRACE_EVENT1("blink", "WebFrameWidgetImpl::beginFrame", "frameTime",
        lastFrameTimeMonotonic);
    DCHECK(lastFrameTimeMonotonic);
    PageWidgetDelegate::animate(*page(), lastFrameTimeMonotonic);
}

void WebFrameWidgetImpl::updateAllLifecyclePhases()
{
    TRACE_EVENT0("blink", "WebFrameWidgetImpl::updateAllLifecyclePhases");
    if (!m_localRoot)
        return;

    if (InspectorOverlay* overlay = inspectorOverlay()) {
        //     overlay->updateAllLifecyclePhases();
        //     // TODO(chrishtr): integrate paint into the overlay's lifecycle.
        //     if (overlay->pageOverlay() && overlay->pageOverlay()->graphicsLayer())
        //       overlay->pageOverlay()->graphicsLayer()->paint(nullptr);
    }
    PageWidgetDelegate::updateAllLifecyclePhases(*page(), *m_localRoot->frame());
=======
void WebFrameWidgetImpl::setIgnoreInputEvents(bool newValue)
{
    ASSERT(m_ignoreInputEvents != newValue);
    m_ignoreInputEvents = newValue;
}

void WebFrameWidgetImpl::willEndLiveResize()
{
    if (m_localRoot->frameView())
        m_localRoot->frameView()->willEndLiveResize();
}

void WebFrameWidgetImpl::willEnterFullScreen()
{
    // FIXME: Implement full screen for out-of-process iframes.
}

void WebFrameWidgetImpl::didEnterFullScreen()
{
    // FIXME: Implement full screen for out-of-process iframes.
}

void WebFrameWidgetImpl::willExitFullScreen()
{
    // FIXME: Implement full screen for out-of-process iframes.
}

void WebFrameWidgetImpl::didExitFullScreen()
{
    // FIXME: Implement full screen for out-of-process iframes.
}

void WebFrameWidgetImpl::beginFrame(const WebBeginFrameArgs& frameTime)
{
    TRACE_EVENT0("blink", "WebFrameWidgetImpl::beginFrame");

    WebBeginFrameArgs validFrameTime(frameTime);
    if (!validFrameTime.lastFrameTimeMonotonic)
        validFrameTime.lastFrameTimeMonotonic = monotonicallyIncreasingTime();

    PageWidgetDelegate::animate(*page(), validFrameTime.lastFrameTimeMonotonic, *m_localRoot->frame());
}

void WebFrameWidgetImpl::layout()
{
    TRACE_EVENT0("blink", "WebFrameWidgetImpl::layout");
    if (!m_localRoot)
        return;

    PageWidgetDelegate::layout(*page(), *m_localRoot->frame());
>>>>>>> miniblink49
    updateLayerTreeBackgroundColor();
}

void WebFrameWidgetImpl::paint(WebCanvas* canvas, const WebRect& rect)
{
    // Out-of-process iframes require compositing.
<<<<<<< HEAD
    NOTREACHED();
}

=======
    ASSERT_NOT_REACHED();
}


>>>>>>> miniblink49
void WebFrameWidgetImpl::updateLayerTreeViewport()
{
    if (!page() || !m_layerTreeView)
        return;

<<<<<<< HEAD
    // Pass the limits even though this is for subframes, as the limits will be
    // needed in setting the raster scale.
    m_layerTreeView->setPageScaleFactorAndLimits(
        1, view()->minimumPageScaleFactor(), view()->maximumPageScaleFactor());
=======
    // FIXME: We need access to page scale information from the WebView.
    m_layerTreeView->setPageScaleFactorAndLimits(1, 1, 1);
>>>>>>> miniblink49
}

void WebFrameWidgetImpl::updateLayerTreeBackgroundColor()
{
    if (!m_layerTreeView)
        return;

<<<<<<< HEAD
    m_layerTreeView->setBackgroundColor(backgroundColor());
=======
    m_layerTreeView->setBackgroundColor(alphaChannel(view()->backgroundColorOverride()) ? view()->backgroundColorOverride() : view()->backgroundColor());
>>>>>>> miniblink49
}

void WebFrameWidgetImpl::updateLayerTreeDeviceScaleFactor()
{
<<<<<<< HEAD
    DCHECK(page());
    DCHECK(m_layerTreeView);
=======
    ASSERT(page());
    ASSERT(m_layerTreeView);
>>>>>>> miniblink49

    float deviceScaleFactor = page()->deviceScaleFactor();
    m_layerTreeView->setDeviceScaleFactor(deviceScaleFactor);
}

<<<<<<< HEAD
void WebFrameWidgetImpl::setIsTransparent(bool isTransparent)
{
    m_isTransparent = isTransparent;

    if (m_layerTreeView)
        m_layerTreeView->setHasTransparentBackground(isTransparent);
}

bool WebFrameWidgetImpl::isTransparent() const
{
    return m_isTransparent;
}

void WebFrameWidgetImpl::layoutAndPaintAsync(
    WebLayoutAndPaintAsyncCallback* callback)
=======
bool WebFrameWidgetImpl::isTransparent() const
{
    // FIXME: This might need to proxy to the WebView's isTransparent().
    return false;
}

void WebFrameWidgetImpl::layoutAndPaintAsync(WebLayoutAndPaintAsyncCallback* callback)
>>>>>>> miniblink49
{
    m_layerTreeView->layoutAndPaintAsync(callback);
}

<<<<<<< HEAD
void WebFrameWidgetImpl::compositeAndReadbackAsync(
    WebCompositeAndReadbackAsyncCallback* callback)
=======
void WebFrameWidgetImpl::compositeAndReadbackAsync(WebCompositeAndReadbackAsyncCallback* callback)
>>>>>>> miniblink49
{
    m_layerTreeView->compositeAndReadbackAsync(callback);
}

void WebFrameWidgetImpl::themeChanged()
{
    FrameView* view = m_localRoot->frameView();

    WebRect damagedRect(0, 0, m_size.width, m_size.height);
    view->invalidateRect(damagedRect);
}

const WebInputEvent* WebFrameWidgetImpl::m_currentInputEvent = nullptr;

<<<<<<< HEAD
WebInputEventResult WebFrameWidgetImpl::handleInputEvent(
    const WebInputEvent& inputEvent)
{
    TRACE_EVENT1("input", "WebFrameWidgetImpl::handleInputEvent", "type",
        WebInputEvent::GetName(inputEvent.type()));

    // If a drag-and-drop operation is in progress, ignore input events.
    if (m_doingDragAndDrop)
        return WebInputEventResult::HandledSuppressed;

    // Don't handle events once we've started shutting down.
    if (!page())
        return WebInputEventResult::NotHandled;

    if (InspectorOverlay* overlay = inspectorOverlay()) {
        //     if (overlay->handleInputEvent(inputEvent))
        //       return WebInputEventResult::HandledSuppressed;
    }

    // Report the event to be NOT processed by WebKit, so that the browser can
    // handle it appropriately.
    if (ignoreInputEvents())
        return WebInputEventResult::NotHandled;

    // FIXME: pass event to m_localRoot's WebDevToolsAgentImpl once available.

    AutoReset<const WebInputEvent*> currentEventChange(&m_currentInputEvent,
        &inputEvent);

    if (m_mouseCaptureNode && WebInputEvent::isMouseEventType(inputEvent.type())) {
        TRACE_EVENT1("input", "captured mouse event", "type", inputEvent.type());
        // Save m_mouseCaptureNode since mouseCaptureLost() will clear it.
        Node* node = m_mouseCaptureNode;

        // Not all platforms call mouseCaptureLost() directly.
        if (inputEvent.type() == WebInputEvent::MouseUp)
            mouseCaptureLost();

        std::unique_ptr<UserGestureIndicator> gestureIndicator;

        AtomicString eventType;
        switch (inputEvent.type()) {
=======
// FIXME: autogenerate this kind of code, and use it throughout Blink rather than
// the one-offs for subsets of these values.
static String inputTypeToName(WebInputEvent::Type type)
{
    switch (type) {
    case WebInputEvent::MouseDown:
        return EventTypeNames::mousedown;
    case WebInputEvent::MouseUp:
        return EventTypeNames::mouseup;
    case WebInputEvent::MouseMove:
        return EventTypeNames::mousemove;
    case WebInputEvent::MouseEnter:
        return EventTypeNames::mouseenter;
    case WebInputEvent::MouseLeave:
        return EventTypeNames::mouseleave;
    case WebInputEvent::ContextMenu:
        return EventTypeNames::contextmenu;
    case WebInputEvent::MouseWheel:
        return EventTypeNames::mousewheel;
    case WebInputEvent::KeyDown:
        return EventTypeNames::keydown;
    case WebInputEvent::KeyUp:
        return EventTypeNames::keyup;
    case WebInputEvent::GestureScrollBegin:
        return EventTypeNames::gesturescrollstart;
    case WebInputEvent::GestureScrollEnd:
        return EventTypeNames::gesturescrollend;
    case WebInputEvent::GestureScrollUpdate:
        return EventTypeNames::gesturescrollupdate;
    case WebInputEvent::GestureTapDown:
        return EventTypeNames::gesturetapdown;
    case WebInputEvent::GestureShowPress:
        return EventTypeNames::gestureshowpress;
    case WebInputEvent::GestureTap:
        return EventTypeNames::gesturetap;
    case WebInputEvent::GestureTapUnconfirmed:
        return EventTypeNames::gesturetapunconfirmed;
    case WebInputEvent::TouchStart:
        return EventTypeNames::touchstart;
    case WebInputEvent::TouchMove:
        return EventTypeNames::touchmove;
    case WebInputEvent::TouchEnd:
        return EventTypeNames::touchend;
    case WebInputEvent::TouchCancel:
        return EventTypeNames::touchcancel;
    default:
        return String("unknown");
    }
}

bool WebFrameWidgetImpl::handleInputEvent(const WebInputEvent& inputEvent)
{

    TRACE_EVENT1("input", "WebFrameWidgetImpl::handleInputEvent", "type", inputTypeToName(inputEvent.type).ascii());

    WebDevToolsAgentImpl* devTools = m_localRoot ? m_localRoot->devToolsAgentImpl() : nullptr;
    if (devTools && devTools->handleInputEvent(inputEvent))
        return true;

    // Report the event to be NOT processed by WebKit, so that the browser can handle it appropriately.
    if (m_ignoreInputEvents)
        return false;

    // FIXME: pass event to m_localRoot's WebDevToolsAgentImpl once available.

    TemporaryChange<const WebInputEvent*> currentEventChange(m_currentInputEvent, &inputEvent);

    if (m_mouseCaptureNode && WebInputEvent::isMouseEventType(inputEvent.type)) {
        TRACE_EVENT1("input", "captured mouse event", "type", inputEvent.type);
        // Save m_mouseCaptureNode since mouseCaptureLost() will clear it.
        RefPtrWillBeRawPtr<Node> node = m_mouseCaptureNode;

        // Not all platforms call mouseCaptureLost() directly.
        if (inputEvent.type == WebInputEvent::MouseUp)
            mouseCaptureLost();

        OwnPtr<UserGestureIndicator> gestureIndicator;

        AtomicString eventType;
        switch (inputEvent.type) {
>>>>>>> miniblink49
        case WebInputEvent::MouseMove:
            eventType = EventTypeNames::mousemove;
            break;
        case WebInputEvent::MouseLeave:
            eventType = EventTypeNames::mouseout;
            break;
        case WebInputEvent::MouseDown:
            eventType = EventTypeNames::mousedown;
<<<<<<< HEAD
            gestureIndicator = WTF::wrapUnique(
                new UserGestureIndicator(DocumentUserGestureToken::create(
                    &node->document(), UserGestureToken::NewGesture)));
=======
            gestureIndicator = adoptPtr(new UserGestureIndicator(DefinitelyProcessingNewUserGesture));
>>>>>>> miniblink49
            m_mouseCaptureGestureToken = gestureIndicator->currentToken();
            break;
        case WebInputEvent::MouseUp:
            eventType = EventTypeNames::mouseup;
<<<<<<< HEAD
            gestureIndicator = WTF::wrapUnique(
                new UserGestureIndicator(m_mouseCaptureGestureToken.release()));
            break;
        default:
            NOTREACHED();
        }

        node->dispatchMouseEvent(
            PlatformMouseEventBuilder(
                m_localRoot->frameView(),
                static_cast<const WebMouseEvent&>(inputEvent)),
            eventType, static_cast<const WebMouseEvent&>(inputEvent).clickCount);
        return WebInputEventResult::HandledSystem;
    }

    return PageWidgetDelegate::handleInputEvent(
        *this, WebCoalescedInputEvent(inputEvent), m_localRoot->frame());
=======
            gestureIndicator = adoptPtr(new UserGestureIndicator(m_mouseCaptureGestureToken.release()));
            break;
        default:
            ASSERT_NOT_REACHED();
        }

        node->dispatchMouseEvent(
            PlatformMouseEventBuilder(m_localRoot->frameView(), static_cast<const WebMouseEvent&>(inputEvent)),
            eventType, static_cast<const WebMouseEvent&>(inputEvent).clickCount);
        return true;
    }

    return PageWidgetDelegate::handleInputEvent(*this, inputEvent, m_localRoot->frame());
>>>>>>> miniblink49
}

void WebFrameWidgetImpl::setCursorVisibilityState(bool isVisible)
{
    page()->setIsCursorVisible(isVisible);
}

bool WebFrameWidgetImpl::hasTouchEventHandlersAt(const WebPoint& point)
{
<<<<<<< HEAD
    // FIXME: Implement this. Note that the point must be divided by
    // pageScaleFactor.
    return true;
}

void WebFrameWidgetImpl::setBaseBackgroundColor(WebColor color)
{
    if (m_baseBackgroundColor == color)
        return;

    m_baseBackgroundColor = color;

    m_localRoot->frameView()->setBaseBackgroundColor(color);
}

WebInputMethodControllerImpl*
WebFrameWidgetImpl::getActiveWebInputMethodController() const
{
    return WebInputMethodControllerImpl::fromFrame(focusedLocalFrameInWidget());
}

void WebFrameWidgetImpl::scheduleAnimation()
{
    if (m_layerTreeView) {
        m_layerTreeView->setNeedsBeginFrame();
=======
    // FIXME: Implement this. Note that the point must be divided by pageScaleFactor.
    return true;
}

void WebFrameWidgetImpl::scheduleAnimation()
{
    if (m_layerTreeView) {
        m_layerTreeView->setNeedsAnimate();
>>>>>>> miniblink49
        return;
    }
    if (m_client)
        m_client->scheduleAnimation();
}

<<<<<<< HEAD
CompositorProxyClient* WebFrameWidgetImpl::createCompositorProxyClient()
{
    if (!m_mutator) {
        std::unique_ptr<CompositorMutatorClient> mutatorClient = CompositorMutatorImpl::createClient();
        m_mutator = static_cast<CompositorMutatorImpl*>(mutatorClient->mutator());
        m_layerTreeView->setMutatorClient(std::move(mutatorClient));
    }
    return new CompositorProxyClientImpl(m_mutator);
}

void WebFrameWidgetImpl::applyViewportDeltas(
    const WebFloatSize& visualViewportDelta,
    const WebFloatSize& mainFrameDelta,
    const WebFloatSize& elasticOverscrollDelta,
    float pageScaleDelta,
    float browserControlsDelta)
=======
void WebFrameWidgetImpl::applyViewportDeltas(
    const WebFloatSize& pinchViewportDelta,
    const WebFloatSize& mainFrameDelta,
    const WebFloatSize& elasticOverscrollDelta,
    float pageScaleDelta,
    float topControlsDelta)
>>>>>>> miniblink49
{
    // FIXME: To be implemented.
}

void WebFrameWidgetImpl::mouseCaptureLost()
{
    TRACE_EVENT_ASYNC_END0("input", "capturing mouse", this);
    m_mouseCaptureNode = nullptr;
}

void WebFrameWidgetImpl::setFocus(bool enable)
{
    page()->focusController().setFocused(enable);
    if (enable) {
        page()->focusController().setActive(true);
<<<<<<< HEAD
        LocalFrame* focusedFrame = page()->focusController().focusedFrame();
        if (focusedFrame) {
            Element* element = focusedFrame->document()->focusedElement();
            if (element && focusedFrame->selection().selection().isNone()) {
                // If the selection was cleared while the WebView was not
                // focused, then the focus element shows with a focus ring but
                // no caret and does respond to keyboard inputs.
                focusedFrame->document()->updateStyleAndLayoutTree();
                if (element->isTextControl()) {
                    element->updateFocusAppearance(SelectionBehaviorOnFocus::Restore);
                } else if (hasEditableStyle(*element)) {
=======
        RefPtrWillBeRawPtr<Frame> focusedFrame = page()->focusController().focusedFrame();
        if (focusedFrame && focusedFrame->isLocalFrame()) {
            LocalFrame* localFrame = toLocalFrame(focusedFrame.get());
            Element* element = localFrame->document()->focusedElement();
            if (element && localFrame->selection().selection().isNone()) {
                // If the selection was cleared while the WebView was not
                // focused, then the focus element shows with a focus ring but
                // no caret and does respond to keyboard inputs.
                if (element->isTextFormControl()) {
                    element->updateFocusAppearance(true);
                } else if (element->isContentEditable()) {
>>>>>>> miniblink49
                    // updateFocusAppearance() selects all the text of
                    // contentseditable DIVs. So we set the selection explicitly
                    // instead. Note that this has the side effect of moving the
                    // caret back to the beginning of the text.
                    Position position(element, 0);
<<<<<<< HEAD
                    focusedFrame->selection().setSelection(
                        SelectionInDOMTree::Builder().collapse(position).build());
                }
            }
        }
        m_imeAcceptEvents = true;
    } else {
        LocalFrame* focusedFrame = focusedLocalFrameInWidget();
        if (focusedFrame) {
            // Finish an ongoing composition to delete the composition node.
            if (focusedFrame->inputMethodController().hasComposition()) {
                // TODO(xiaochengh): The use of
                // updateStyleAndLayoutIgnorePendingStylesheets needs to be audited.
                // See http://crbug.com/590369 for more details.
                focusedFrame->document()
                    ->updateStyleAndLayoutIgnorePendingStylesheets();

                focusedFrame->inputMethodController().finishComposingText(
                    InputMethodController::KeepSelection);
            }
            m_imeAcceptEvents = false;
        }
    }
}

// TODO(ekaramad):This method is almost duplicated in WebViewImpl as well. This
// code needs to be refactored  (http://crbug.com/629721).
WebRange WebFrameWidgetImpl::compositionRange()
{
    LocalFrame* focused = focusedLocalFrameAvailableForIme();
    if (!focused)
        return WebRange();

    const EphemeralRange range = focused->inputMethodController().compositionEphemeralRange();
    if (range.isNull())
        return WebRange();

    Element* editable = focused->selection().rootEditableElementOrDocumentElement();
    DCHECK(editable);

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    editable->document().updateStyleAndLayoutIgnorePendingStylesheets();

    return PlainTextRange::create(*editable, range);
=======
                    localFrame->selection().setSelection(VisibleSelection(position, SEL_DEFAULT_AFFINITY));
                }
            }
        }
    }
}

bool WebFrameWidgetImpl::setComposition(
    const WebString& text,
    const WebVector<WebCompositionUnderline>& underlines,
    int selectionStart,
    int selectionEnd)
{
    // FIXME: To be implemented.
    return false;
}

bool WebFrameWidgetImpl::confirmComposition()
{
    // FIXME: To be implemented.
    return false;
}

bool WebFrameWidgetImpl::confirmComposition(ConfirmCompositionBehavior selectionBehavior)
{
    // FIXME: To be implemented.
    return false;
}

bool WebFrameWidgetImpl::confirmComposition(const WebString& text)
{
    // FIXME: To be implemented.
    return false;
}

bool WebFrameWidgetImpl::compositionRange(size_t* location, size_t* length)
{
    // FIXME: To be implemented.
    return false;
}

WebTextInputInfo WebFrameWidgetImpl::textInputInfo()
{
    WebTextInputInfo info;
    // FIXME: To be implemented.
    return info;
>>>>>>> miniblink49
}

WebColor WebFrameWidgetImpl::backgroundColor() const
{
    if (isTransparent())
        return Color::transparent;
    if (!m_localRoot->frameView())
<<<<<<< HEAD
        return m_baseBackgroundColor;
=======
        return view()->backgroundColor();
>>>>>>> miniblink49
    FrameView* view = m_localRoot->frameView();
    return view->documentBackgroundColor().rgb();
}

<<<<<<< HEAD
// TODO(ekaramad):This method is almost duplicated in WebViewImpl as well. This
// code needs to be refactored  (http://crbug.com/629721).
bool WebFrameWidgetImpl::selectionBounds(WebRect& anchor,
    WebRect& focus) const
{
    const LocalFrame* localFrame = focusedLocalFrameInWidget();
    if (!localFrame)
        return false;

    FrameSelection& selection = localFrame->selection();
    if (selection.isNone())
        return false;

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    localFrame->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    DocumentLifecycle::DisallowTransitionScope disallowTransition(
        localFrame->document()->lifecycle());
=======
bool WebFrameWidgetImpl::selectionBounds(WebRect& anchor, WebRect& focus) const
{
    const Frame* frame = focusedCoreFrame();
    if (!frame || !frame->isLocalFrame())
        return false;

    const LocalFrame* localFrame = toLocalFrame(frame);
    if (!localFrame)
        return false;
    FrameSelection& selection = localFrame->selection();
>>>>>>> miniblink49

    if (selection.isCaret()) {
        anchor = focus = selection.absoluteCaretBounds();
    } else {
<<<<<<< HEAD
        const EphemeralRange selectedRange = selection.selection().toNormalizedEphemeralRange();
        if (selectedRange.isNull())
            return false;
        anchor = localFrame->editor().firstRectForRange(
            EphemeralRange(selectedRange.startPosition()));
        focus = localFrame->editor().firstRectForRange(
            EphemeralRange(selectedRange.endPosition()));
    }

    // FIXME: This doesn't apply page scale. This should probably be contents to
    // viewport. crbug.com/459293.
=======
        RefPtrWillBeRawPtr<Range> selectedRange = selection.toNormalizedRange();
        if (!selectedRange)
            return false;

        RefPtrWillBeRawPtr<Range> range(Range::create(selectedRange->startContainer()->document(),
            selectedRange->startContainer(),
            selectedRange->startOffset(),
            selectedRange->startContainer(),
            selectedRange->startOffset()));
        anchor = localFrame->editor().firstRectForRange(range.get());

        range = Range::create(selectedRange->endContainer()->document(),
            selectedRange->endContainer(),
            selectedRange->endOffset(),
            selectedRange->endContainer(),
            selectedRange->endOffset());
        focus = localFrame->editor().firstRectForRange(range.get());
    }

    // FIXME: This doesn't apply page scale. This should probably be contents to viewport. crbug.com/459293.
>>>>>>> miniblink49
    IntRect scaledAnchor(localFrame->view()->contentsToRootFrame(anchor));
    IntRect scaledFocus(localFrame->view()->contentsToRootFrame(focus));

    anchor = scaledAnchor;
    focus = scaledFocus;

    if (!selection.selection().isBaseFirst())
        std::swap(anchor, focus);
    return true;
}

<<<<<<< HEAD
// TODO(ekaramad):This method is almost duplicated in WebViewImpl as well. This
// code needs to be refactored  (http://crbug.com/629721).
bool WebFrameWidgetImpl::selectionTextDirection(WebTextDirection& start,
    WebTextDirection& end) const
{
    const LocalFrame* frame = focusedLocalFrameInWidget();
    if (!frame)
        return false;

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    frame->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    FrameSelection& selection = frame->selection();
    if (selection.selection().toNormalizedEphemeralRange().isNull())
        return false;
    start = toWebTextDirection(primaryDirectionOf(*selection.start().anchorNode()));
    end = toWebTextDirection(primaryDirectionOf(*selection.end().anchorNode()));
    return true;
}

// TODO(ekaramad):This method is almost duplicated in WebViewImpl as well. This
// code needs to be refactored  (http://crbug.com/629721).
bool WebFrameWidgetImpl::isSelectionAnchorFirst() const
{
    if (const LocalFrame* frame = focusedLocalFrameInWidget())
=======
bool WebFrameWidgetImpl::selectionTextDirection(WebTextDirection& start, WebTextDirection& end) const
{
    if (!focusedCoreFrame()->isLocalFrame())
        return false;
    const LocalFrame* frame = toLocalFrame(focusedCoreFrame());
    if (!frame)
        return false;
    FrameSelection& selection = frame->selection();
    if (!selection.toNormalizedRange())
        return false;
    start = toWebTextDirection(selection.start().primaryDirection());
    end = toWebTextDirection(selection.end().primaryDirection());
    return true;
}

bool WebFrameWidgetImpl::isSelectionAnchorFirst() const
{
    if (!focusedCoreFrame()->isLocalFrame())
        return false;
    if (const LocalFrame* frame = toLocalFrame(focusedCoreFrame()))
>>>>>>> miniblink49
        return frame->selection().selection().isBaseFirst();
    return false;
}

<<<<<<< HEAD
// TODO(ekaramad):This method is almost duplicated in WebViewImpl as well. This
// code needs to be refactored  (http://crbug.com/629721).
WebRange WebFrameWidgetImpl::caretOrSelectionRange()
{
    LocalFrame* focused = focusedLocalFrameInWidget();
    if (!focused)
        return WebRange();

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    focused->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    return focused->inputMethodController().getSelectionOffsets();
=======
bool WebFrameWidgetImpl::caretOrSelectionRange(size_t* location, size_t* length)
{
    if (!focusedCoreFrame()->isLocalFrame())
        return false;
    const LocalFrame* focused = toLocalFrame(focusedCoreFrame());
    if (!focused)
        return false;

    PlainTextRange selectionOffsets = focused->inputMethodController().getSelectionOffsets();
    if (selectionOffsets.isNull())
        return false;

    *location = selectionOffsets.start();
    *length = selectionOffsets.length();
    return true;
>>>>>>> miniblink49
}

void WebFrameWidgetImpl::setTextDirection(WebTextDirection direction)
{
    // The Editor::setBaseWritingDirection() function checks if we can change
    // the text direction of the selected node and updates its DOM "dir"
    // attribute and its CSS "direction" property.
    // So, we just call the function as Safari does.
<<<<<<< HEAD
    const LocalFrame* focused = focusedLocalFrameInWidget();
=======
    if (!focusedCoreFrame()->isLocalFrame())
        return;
    const LocalFrame* focused = toLocalFrame(focusedCoreFrame());
>>>>>>> miniblink49
    if (!focused)
        return;

    Editor& editor = focused->editor();
    if (!editor.canEdit())
        return;

    switch (direction) {
    case WebTextDirectionDefault:
        editor.setBaseWritingDirection(NaturalWritingDirection);
        break;

    case WebTextDirectionLeftToRight:
        editor.setBaseWritingDirection(LeftToRightWritingDirection);
        break;

    case WebTextDirectionRightToLeft:
        editor.setBaseWritingDirection(RightToLeftWritingDirection);
        break;

    default:
<<<<<<< HEAD
        NOTIMPLEMENTED();
=======
        notImplemented();
>>>>>>> miniblink49
        break;
    }
}

bool WebFrameWidgetImpl::isAcceleratedCompositingActive() const
{
    return m_isAcceleratedCompositingActive;
}

void WebFrameWidgetImpl::willCloseLayerTreeView()
{
<<<<<<< HEAD
    if (m_layerTreeView) {
        page()->willCloseLayerTreeView(*m_layerTreeView,
            m_localRoot->frame()->view());
    }

    setIsAcceleratedCompositingActive(false);
    m_mutator = nullptr;
    m_layerTreeView = nullptr;
    m_animationHost = nullptr;
    m_layerTreeViewClosed = true;
}

void WebFrameWidgetImpl::didAcquirePointerLock()
{
    page()->pointerLockController().didAcquirePointerLock();
}

void WebFrameWidgetImpl::didNotAcquirePointerLock()
{
    page()->pointerLockController().didNotAcquirePointerLock();
}

void WebFrameWidgetImpl::didLosePointerLock()
{
    page()->pointerLockController().didLosePointerLock();
}

// TODO(ekaramad):This method is almost duplicated in WebViewImpl as well. This
// code needs to be refactored  (http://crbug.com/629721).
bool WebFrameWidgetImpl::getCompositionCharacterBounds(
    WebVector<WebRect>& bounds)
{
    WebRange range = compositionRange();
    if (range.isEmpty())
        return false;

    LocalFrame* frame = focusedLocalFrameInWidget();
    if (!frame)
        return false;

    WebLocalFrameImpl* webLocalFrame = WebLocalFrameImpl::fromFrame(frame);
    size_t characterCount = range.length();
    size_t offset = range.startOffset();
    WebVector<WebRect> result(characterCount);
    WebRect webrect;
    for (size_t i = 0; i < characterCount; ++i) {
        if (!webLocalFrame->firstRectForCharacterRange(offset + i, 1, webrect)) {
            DLOG(ERROR) << "Could not retrieve character rectangle at " << i;
            return false;
        }
        result[i] = webrect;
    }

    bounds.swap(result);
    return true;
}

// TODO(ekaramad):This method is almost duplicated in WebViewImpl as well. This
// code needs to be refactored  (http://crbug.com/629721).
void WebFrameWidgetImpl::applyReplacementRange(const WebRange& range)
{
    if (LocalFrame* frame = focusedLocalFrameInWidget()) {
        // TODO(dglazkov): Going from LocalFrame to WebLocalFrameImpl seems
        // silly. What is going on here?
        WebLocalFrameImpl::fromFrame(frame)->selectRange(range);
    }
}

void WebFrameWidgetImpl::setRemoteViewportIntersection(
    const WebRect& viewportIntersection)
{
    // Remote viewports are only applicable to local frames with remote ancestors.
    DCHECK(m_localRoot->parent() && m_localRoot->parent()->isWebRemoteFrame());

    if (m_localRoot->frameView()) {
        m_localRoot->frameView()->setViewportIntersectionFromParent(
            viewportIntersection);
    }
}

void WebFrameWidgetImpl::handleMouseLeave(LocalFrame& mainFrame,
    const WebMouseEvent& event)
=======
    setIsAcceleratedCompositingActive(false);
    m_layerTreeView = nullptr;
    m_layerTreeViewClosed = true;
}

void WebFrameWidgetImpl::didChangeWindowResizerRect()
{
    if (m_localRoot->frameView())
        m_localRoot->frameView()->windowResizerRectChanged();
}

void WebFrameWidgetImpl::handleMouseLeave(LocalFrame& mainFrame, const WebMouseEvent& event)
>>>>>>> miniblink49
{
    // FIXME: WebWidget doesn't have the method below.
    // m_client->setMouseOverURL(WebURL());
    PageWidgetEventHandler::handleMouseLeave(mainFrame, event);
}

<<<<<<< HEAD
void WebFrameWidgetImpl::handleMouseDown(LocalFrame& mainFrame,
    const WebMouseEvent& event)
=======
void WebFrameWidgetImpl::handleMouseDown(LocalFrame& mainFrame, const WebMouseEvent& event)
>>>>>>> miniblink49
{
    // Take capture on a mouse down on a plugin so we can send it mouse events.
    // If the hit node is a plugin but a scrollbar is over it don't start mouse
    // capture because it will interfere with the scrollbar receiving events.
    IntPoint point(event.x, event.y);
<<<<<<< HEAD
    if (event.button == WebMouseEvent::Button::Left) {
        point = m_localRoot->frameView()->rootFrameToContents(point);
        HitTestResult result(
            m_localRoot->frame()->eventHandler().hitTestResultAtPoint(point));
=======
    if (event.button == WebMouseEvent::ButtonLeft) {
        point = m_localRoot->frameView()->rootFrameToContents(point);
        HitTestResult result(m_localRoot->frame()->eventHandler().hitTestResultAtPoint(point));
>>>>>>> miniblink49
        result.setToShadowHostIfInUserAgentShadowRoot();
        Node* hitNode = result.innerNode();

        if (!result.scrollbar() && hitNode && hitNode->layoutObject() && hitNode->layoutObject()->isEmbeddedObject()) {
            m_mouseCaptureNode = hitNode;
            TRACE_EVENT_ASYNC_BEGIN0("input", "capturing mouse", this);
        }
    }

    PageWidgetEventHandler::handleMouseDown(mainFrame, event);

<<<<<<< HEAD
    if (event.button == WebMouseEvent::Button::Left && m_mouseCaptureNode)
        m_mouseCaptureGestureToken = mainFrame.eventHandler().takeLastMouseDownGestureToken();

    // Dispatch the contextmenu event regardless of if the click was swallowed.
    if (!page()->settings().getShowContextMenuOnMouseUp()) {
#if OS(MACOSX)
        if (event.button == WebMouseEvent::Button::Right || (event.button == WebMouseEvent::Button::Left && event.modifiers() & WebMouseEvent::ControlKey))
            mouseContextMenu(event);
#else
        if (event.button == WebMouseEvent::Button::Right)
            mouseContextMenu(event);
#endif
    }
}

void WebFrameWidgetImpl::mouseContextMenu(const WebMouseEvent& event)
{
    page()->contextMenuController().clearContextMenu();

    PlatformMouseEventBuilder pme(m_localRoot->frameView(), event);

    // Find the right target frame. See issue 1186900.
    HitTestResult result = hitTestResultForRootFramePos(pme.position());
    Frame* targetFrame;
    if (result.innerNodeOrImageMapImage())
        targetFrame = result.innerNodeOrImageMapImage()->document().frame();
    else
        targetFrame = page()->focusController().focusedOrMainFrame();

    // This will need to be changed to a nullptr check when focus control
    // is refactored, at which point focusedOrMainFrame will never return a
    // RemoteFrame.
    // See https://crbug.com/341918.
    if (!targetFrame->isLocalFrame())
        return;

    LocalFrame* targetLocalFrame = toLocalFrame(targetFrame);

#if OS(WIN)
    targetLocalFrame->view()->setCursor(pointerCursor());
#endif

    {
        ContextMenuAllowedScope scope;
        targetLocalFrame->eventHandler().sendContextMenuEvent(pme, nullptr);
    }
    // Actually showing the context menu is handled by the ContextMenuClient
    // implementation...
}

void WebFrameWidgetImpl::handleMouseUp(LocalFrame& mainFrame,
    const WebMouseEvent& event)
{
    PageWidgetEventHandler::handleMouseUp(mainFrame, event);

    if (page()->settings().getShowContextMenuOnMouseUp()) {
        // Dispatch the contextmenu event regardless of if the click was swallowed.
        // On Mac/Linux, we handle it on mouse down, not up.
        if (event.button == WebMouseEvent::Button::Right)
            mouseContextMenu(event);
    }
}

WebInputEventResult WebFrameWidgetImpl::handleMouseWheel(
    LocalFrame& mainFrame,
    const WebMouseWheelEvent& event)
=======
    if (event.button == WebMouseEvent::ButtonLeft && m_mouseCaptureNode)
        m_mouseCaptureGestureToken = mainFrame.eventHandler().takeLastMouseDownGestureToken();

    // FIXME: Add context menu support.
}

void WebFrameWidgetImpl::handleMouseUp(LocalFrame& mainFrame, const WebMouseEvent& event)
{
    PageWidgetEventHandler::handleMouseUp(mainFrame, event);

    // FIXME: Add context menu support (Windows).
}

bool WebFrameWidgetImpl::handleMouseWheel(LocalFrame& mainFrame, const WebMouseWheelEvent& event)
>>>>>>> miniblink49
{
    return PageWidgetEventHandler::handleMouseWheel(mainFrame, event);
}

<<<<<<< HEAD
WebInputEventResult WebFrameWidgetImpl::handleGestureEvent(
    const WebGestureEvent& event)
{
    WebInputEventResult eventResult = WebInputEventResult::NotHandled;
    bool eventCancelled = false;
    switch (event.type()) {
    case WebInputEvent::GestureScrollBegin:
    case WebInputEvent::GestureScrollEnd:
    case WebInputEvent::GestureScrollUpdate:
    case WebInputEvent::GestureTap:
    case WebInputEvent::GestureTapUnconfirmed:
    case WebInputEvent::GestureTapDown:
    case WebInputEvent::GestureShowPress:
    case WebInputEvent::GestureTapCancel:
    case WebInputEvent::GestureDoubleTap:
    case WebInputEvent::GestureTwoFingerTap:
    case WebInputEvent::GestureLongPress:
    case WebInputEvent::GestureLongTap:
        break;
    case WebInputEvent::GestureFlingStart:
    case WebInputEvent::GestureFlingCancel:
        m_client->didHandleGestureEvent(event, eventCancelled);
        return WebInputEventResult::NotHandled;
    default:
        NOTREACHED();
    }
    LocalFrame* frame = m_localRoot->frame();
    WebGestureEvent scaledEvent = TransformWebGestureEvent(frame->view(), event);
    eventResult = frame->eventHandler().handleGestureEvent(scaledEvent);
    m_client->didHandleGestureEvent(event, eventCancelled);
    return eventResult;
}

WebInputEventResult WebFrameWidgetImpl::handleKeyEvent(
    const WebKeyboardEvent& event)
{
    DCHECK((event.type() == WebInputEvent::RawKeyDown) || (event.type() == WebInputEvent::KeyDown) || (event.type() == WebInputEvent::KeyUp));
=======
bool WebFrameWidgetImpl::handleGestureEvent(const WebGestureEvent& event)
{
    // FIXME: Add gesture support.
    return false;
}

bool WebFrameWidgetImpl::handleKeyEvent(const WebKeyboardEvent& event)
{
    ASSERT((event.type == WebInputEvent::RawKeyDown)
        || (event.type == WebInputEvent::KeyDown)
        || (event.type == WebInputEvent::KeyUp));
>>>>>>> miniblink49

    // Please refer to the comments explaining the m_suppressNextKeypressEvent
    // member.
    // The m_suppressNextKeypressEvent is set if the KeyDown is handled by
    // Webkit. A keyDown event is typically associated with a keyPress(char)
    // event and a keyUp event. We reset this flag here as this is a new keyDown
    // event.
    m_suppressNextKeypressEvent = false;

<<<<<<< HEAD
    Frame* focusedFrame = focusedCoreFrame();
    if (focusedFrame && focusedFrame->isRemoteFrame()) {
        WebRemoteFrameImpl* webFrame = WebRemoteFrameImpl::fromFrame(*toRemoteFrame(focusedFrame));
        webFrame->client()->forwardInputEvent(&event);
        return WebInputEventResult::HandledSystem;
    }

    if (!focusedFrame || !focusedFrame->isLocalFrame())
        return WebInputEventResult::NotHandled;

    LocalFrame* frame = toLocalFrame(focusedFrame);

    WebInputEventResult result = frame->eventHandler().keyEvent(event);
    if (result != WebInputEventResult::NotHandled) {
        if (WebInputEvent::RawKeyDown == event.type()) {
            // Suppress the next keypress event unless the focused node is a plugin
            // node.  (Flash needs these keypress events to handle non-US keyboards.)
=======
    RefPtrWillBeRawPtr<Frame> focusedFrame = focusedCoreFrame();
    if (focusedFrame && focusedFrame->isRemoteFrame()) {
        WebRemoteFrameImpl* webFrame = WebRemoteFrameImpl::fromFrame(*toRemoteFrame(focusedFrame.get()));
        webFrame->client()->forwardInputEvent(&event);
        return true;
    }

    if (!focusedFrame || !focusedFrame->isLocalFrame())
        return false;

    RefPtrWillBeRawPtr<LocalFrame> frame = toLocalFrame(focusedFrame.get());

    PlatformKeyboardEventBuilder evt(event);

    if (frame->eventHandler().keyEvent(evt)) {
        if (WebInputEvent::RawKeyDown == event.type) {
            // Suppress the next keypress event unless the focused node is a plugin node.
            // (Flash needs these keypress events to handle non-US keyboards.)
>>>>>>> miniblink49
            Element* element = focusedElement();
            if (!element || !element->layoutObject() || !element->layoutObject()->isEmbeddedObject())
                m_suppressNextKeypressEvent = true;
        }
<<<<<<< HEAD
        return result;
    }

#if !OS(MACOSX)
    const WebInputEvent::Type contextMenuKeyTriggeringEventType =
#if OS(WIN)
        WebInputEvent::KeyUp;
#else
        WebInputEvent::RawKeyDown;
#endif
    const WebInputEvent::Type shiftF10TriggeringEventType = WebInputEvent::RawKeyDown;

    bool isUnmodifiedMenuKey = !(event.modifiers() & WebInputEvent::InputModifiers) && event.windowsKeyCode == VKEY_APPS;
    bool isShiftF10 = (event.modifiers() & WebInputEvent::InputModifiers) == WebInputEvent::ShiftKey && event.windowsKeyCode == VKEY_F10;
    if ((isUnmodifiedMenuKey && event.type() == contextMenuKeyTriggeringEventType) || (isShiftF10 && event.type() == shiftF10TriggeringEventType)) {
        view()->sendContextMenuEvent(event);
        return WebInputEventResult::HandledSystem;
    }
#endif // !OS(MACOSX)

    return WebInputEventResult::NotHandled;
}

WebInputEventResult WebFrameWidgetImpl::handleCharEvent(
    const WebKeyboardEvent& event)
{
    DCHECK_EQ(event.type(), WebInputEvent::Char);
=======
        return true;
    }

    return keyEventDefault(event);
}

bool WebFrameWidgetImpl::handleCharEvent(const WebKeyboardEvent& event)
{
    ASSERT(event.type == WebInputEvent::Char);
>>>>>>> miniblink49

    // Please refer to the comments explaining the m_suppressNextKeypressEvent
    // member.  The m_suppressNextKeypressEvent is set if the KeyDown is
    // handled by Webkit. A keyDown event is typically associated with a
    // keyPress(char) event and a keyUp event. We reset this flag here as it
    // only applies to the current keyPress event.
    bool suppress = m_suppressNextKeypressEvent;
    m_suppressNextKeypressEvent = false;

    LocalFrame* frame = toLocalFrame(focusedCoreFrame());
    if (!frame)
<<<<<<< HEAD
        return suppress ? WebInputEventResult::HandledSuppressed
                        : WebInputEventResult::NotHandled;

    EventHandler& handler = frame->eventHandler();

    if (!event.isCharacterKey())
        return WebInputEventResult::HandledSuppressed;

    // Accesskeys are triggered by char events and can't be suppressed.
    // It is unclear whether a keypress should be dispatched as well
    // crbug.com/563507
    if (handler.handleAccessKey(event))
        return WebInputEventResult::HandledSystem;
=======
        return suppress;

    EventHandler& handler = frame->eventHandler();

    PlatformKeyboardEventBuilder evt(event);
    if (!evt.isCharacterKey())
        return true;

    // Accesskeys are triggered by char events and can't be suppressed.
    if (handler.handleAccessKey(evt))
        return true;
>>>>>>> miniblink49

    // Safari 3.1 does not pass off windows system key messages (WM_SYSCHAR) to
    // the eventHandler::keyEvent. We mimic this behavior on all platforms since
    // for now we are converting other platform's key events to windows key
    // events.
<<<<<<< HEAD
    if (event.isSystemKey)
        return WebInputEventResult::NotHandled;

    if (suppress)
        return WebInputEventResult::HandledSuppressed;

    WebInputEventResult result = handler.keyEvent(event);
    if (result != WebInputEventResult::NotHandled)
        return result;

    return WebInputEventResult::NotHandled;
=======
    if (evt.isSystemKey())
        return false;

    if (!suppress && !handler.keyEvent(evt))
        return keyEventDefault(event);

    return true;
}


bool WebFrameWidgetImpl::keyEventDefault(const WebKeyboardEvent& event)
{
    LocalFrame* frame = toLocalFrame(focusedCoreFrame());
    if (!frame)
        return false;

    switch (event.type) {
    case WebInputEvent::Char:
        if (event.windowsKeyCode == VKEY_SPACE) {
            int keyCode = ((event.modifiers & WebInputEvent::ShiftKey) ? VKEY_PRIOR : VKEY_NEXT);
            return scrollViewWithKeyboard(keyCode, event.modifiers);
        }
        break;
    case WebInputEvent::RawKeyDown:
        if (event.modifiers == WebInputEvent::ControlKey) {
            switch (event.windowsKeyCode) {
#if !OS(MACOSX)
            case 'A':
                WebFrame::fromFrame(focusedCoreFrame())->executeCommand(WebString::fromUTF8("SelectAll"));
                return true;
            case VKEY_INSERT:
            case 'C':
                WebFrame::fromFrame(focusedCoreFrame())->executeCommand(WebString::fromUTF8("Copy"));
                return true;
#endif
            // Match FF behavior in the sense that Ctrl+home/end are the only Ctrl
            // key combinations which affect scrolling. Safari is buggy in the
            // sense that it scrolls the page for all Ctrl+scrolling key
            // combinations. For e.g. Ctrl+pgup/pgdn/up/down, etc.
            case VKEY_HOME:
            case VKEY_END:
                break;
            default:
                return false;
            }
        }
        if (!event.isSystemKey && !(event.modifiers & WebInputEvent::ShiftKey))
            return scrollViewWithKeyboard(event.windowsKeyCode, event.modifiers);
        break;
    default:
        break;
    }
    return false;
}

bool WebFrameWidgetImpl::scrollViewWithKeyboard(int keyCode, int modifiers)
{
    ScrollDirection scrollDirection;
    ScrollGranularity scrollGranularity;
#if OS(MACOSX)
    // Control-Up/Down should be PageUp/Down on Mac.
    if (modifiers & WebMouseEvent::ControlKey) {
        if (keyCode == VKEY_UP)
            keyCode = VKEY_PRIOR;
        else if (keyCode == VKEY_DOWN)
            keyCode = VKEY_NEXT;
    }
#endif
    if (!mapKeyCodeForScroll(keyCode, &scrollDirection, &scrollGranularity))
        return false;

    if (LocalFrame* frame = toLocalFrame(focusedCoreFrame()))
        return frame->eventHandler().bubblingScroll(scrollDirection, scrollGranularity);
    return false;
}

bool WebFrameWidgetImpl::mapKeyCodeForScroll(
    int keyCode,
    ScrollDirection* scrollDirection,
    ScrollGranularity* scrollGranularity)
{
    switch (keyCode) {
    case VKEY_LEFT:
        *scrollDirection = ScrollLeftIgnoringWritingMode;
        *scrollGranularity = ScrollByLine;
        break;
    case VKEY_RIGHT:
        *scrollDirection = ScrollRightIgnoringWritingMode;
        *scrollGranularity = ScrollByLine;
        break;
    case VKEY_UP:
        *scrollDirection = ScrollUpIgnoringWritingMode;
        *scrollGranularity = ScrollByLine;
        break;
    case VKEY_DOWN:
        *scrollDirection = ScrollDownIgnoringWritingMode;
        *scrollGranularity = ScrollByLine;
        break;
    case VKEY_HOME:
        *scrollDirection = ScrollUpIgnoringWritingMode;
        *scrollGranularity = ScrollByDocument;
        break;
    case VKEY_END:
        *scrollDirection = ScrollDownIgnoringWritingMode;
        *scrollGranularity = ScrollByDocument;
        break;
    case VKEY_PRIOR: // page up
        *scrollDirection = ScrollUpIgnoringWritingMode;
        *scrollGranularity = ScrollByPage;
        break;
    case VKEY_NEXT: // page down
        *scrollDirection = ScrollDownIgnoringWritingMode;
        *scrollGranularity = ScrollByPage;
        break;
    default:
        return false;
    }

    return true;
>>>>>>> miniblink49
}

Frame* WebFrameWidgetImpl::focusedCoreFrame() const
{
    return page() ? page()->focusController().focusedOrMainFrame() : nullptr;
}

Element* WebFrameWidgetImpl::focusedElement() const
{
<<<<<<< HEAD
    LocalFrame* frame = page()->focusController().focusedFrame();
    if (!frame)
        return nullptr;

    Document* document = frame->document();
=======
    Frame* frame = page()->focusController().focusedFrame();
    if (!frame || !frame->isLocalFrame())
        return nullptr;

    Document* document = toLocalFrame(frame)->document();
>>>>>>> miniblink49
    if (!document)
        return nullptr;

    return document->focusedElement();
}

void WebFrameWidgetImpl::initializeLayerTreeView()
{
    if (m_client) {
<<<<<<< HEAD
        DCHECK(!m_mutator);
        m_layerTreeView = m_client->initializeLayerTreeView();
        if (m_layerTreeView && m_layerTreeView->compositorAnimationHost()) {
            m_animationHost = WTF::makeUnique<CompositorAnimationHost>(
                m_layerTreeView->compositorAnimationHost());
        }
    }

    //   if (WebDevToolsAgentImpl* devTools = m_localRoot->devToolsAgentImpl())
    //     devTools->layerTreeViewChanged(m_layerTreeView);

    page()->settings().setAcceleratedCompositingEnabled(m_layerTreeView);
    if (m_layerTreeView) {
        page()->layerTreeViewInitialized(*m_layerTreeView,
            m_localRoot->frame()->view());
    }

    // FIXME: only unittests, click to play, Android priting, and printing (for
    // headers and footers) make this assert necessary. We should make them not
    // hit this code and then delete allowsBrokenNullLayerTreeView.
    DCHECK(m_layerTreeView || !m_client || m_client->allowsBrokenNullLayerTreeView());
=======
        m_client->initializeLayerTreeView();
        m_layerTreeView = m_client->layerTreeView();
    }

    if (WebDevToolsAgentImpl* devTools = m_localRoot->devToolsAgentImpl())
        devTools->layerTreeViewChanged(m_layerTreeView);

    page()->settings().setAcceleratedCompositingEnabled(m_layerTreeView);

    // FIXME: only unittests, click to play, Android priting, and printing (for headers and footers)
    // make this assert necessary. We should make them not hit this code and then delete allowsBrokenNullLayerTreeView.
    ASSERT(m_layerTreeView || !m_client || m_client->allowsBrokenNullLayerTreeView());
>>>>>>> miniblink49
}

void WebFrameWidgetImpl::setIsAcceleratedCompositingActive(bool active)
{
    // In the middle of shutting down; don't try to spin back up a compositor.
    // FIXME: compositing startup/shutdown should be refactored so that it
    // turns on explicitly rather than lazily, which causes this awkwardness.
    if (m_layerTreeViewClosed)
        return;

<<<<<<< HEAD
    DCHECK(!active || m_layerTreeView);
=======
    ASSERT(!active || m_layerTreeView);
>>>>>>> miniblink49

    if (m_isAcceleratedCompositingActive == active)
        return;

    if (!m_client)
        return;

    if (active) {
<<<<<<< HEAD
        TRACE_EVENT0("blink",
            "WebViewImpl::setIsAcceleratedCompositingActive(true)");
        m_layerTreeView->setRootLayer(*m_rootLayer);

        m_layerTreeView->setVisible(page()->isPageVisible());
=======
        TRACE_EVENT0("blink", "WebViewImpl::setIsAcceleratedCompositingActive(true)");
        m_layerTreeView->setRootLayer(*m_rootLayer);

        bool visible = page()->visibilityState() == PageVisibilityStateVisible;
        m_layerTreeView->setVisible(visible);
>>>>>>> miniblink49
        updateLayerTreeDeviceScaleFactor();
        updateLayerTreeBackgroundColor();
        m_layerTreeView->setHasTransparentBackground(isTransparent());
        updateLayerTreeViewport();
        m_isAcceleratedCompositingActive = true;
    }
<<<<<<< HEAD
}

PaintLayerCompositor* WebFrameWidgetImpl::compositor() const
{
    LocalFrame* frame = m_localRoot->frame();
    if (!frame || !frame->document() || frame->document()->layoutViewItem().isNull())
        return nullptr;

    return frame->document()->layoutViewItem().compositor();
=======
    if (m_localRoot->frameView())
        m_localRoot->frameView()->setClipsRepaints(!m_isAcceleratedCompositingActive);
}

DeprecatedPaintLayerCompositor* WebFrameWidgetImpl::compositor() const
{
    LocalFrame* frame = toLocalFrame(toCoreFrame(m_localRoot));
    if (!frame || !frame->document() || !frame->document()->layoutView())
        return nullptr;

    return frame->document()->layoutView()->compositor();
}

void WebFrameWidgetImpl::suppressInvalidations(bool enable)
{
    if (m_client)
        m_client->suppressCompositorScheduling(enable);
>>>>>>> miniblink49
}

void WebFrameWidgetImpl::setRootGraphicsLayer(GraphicsLayer* layer)
{
<<<<<<< HEAD
=======
    suppressInvalidations(true);

>>>>>>> miniblink49
    m_rootGraphicsLayer = layer;
    m_rootLayer = layer ? layer->platformLayer() : nullptr;

    setIsAcceleratedCompositingActive(layer);

<<<<<<< HEAD
    if (!m_layerTreeView)
        return;

    if (m_rootLayer)
        m_layerTreeView->setRootLayer(*m_rootLayer);
    else
        m_layerTreeView->clearRootLayer();
}

void WebFrameWidgetImpl::setRootLayer(WebLayer* layer)
{
    m_rootLayer = layer;

    setIsAcceleratedCompositingActive(layer);

    if (!m_layerTreeView)
        return;

    if (m_rootLayer)
        m_layerTreeView->setRootLayer(*m_rootLayer);
    else
        m_layerTreeView->clearRootLayer();
}

WebLayerTreeView* WebFrameWidgetImpl::getLayerTreeView() const
{
    return m_layerTreeView;
}

CompositorAnimationHost* WebFrameWidgetImpl::animationHost() const
{
    return m_animationHost.get();
}

HitTestResult WebFrameWidgetImpl::coreHitTestResultAt(
    const WebPoint& pointInViewport)
{
    DocumentLifecycle::AllowThrottlingScope throttlingScope(
        m_localRoot->frame()->document()->lifecycle());
    FrameView* view = m_localRoot->frameView();
    IntPoint pointInRootFrame = view->contentsToFrame(view->viewportToContents(pointInViewport));
    return hitTestResultForRootFramePos(pointInRootFrame);
}

void WebFrameWidgetImpl::setVisibilityState(
    WebPageVisibilityState visibilityState)
{
    if (m_layerTreeView)
        m_layerTreeView->setVisible(visibilityState == WebPageVisibilityStateVisible);
}

HitTestResult WebFrameWidgetImpl::hitTestResultForRootFramePos(
    const IntPoint& posInRootFrame)
{
    IntPoint docPoint(
        m_localRoot->frame()->view()->rootFrameToContents(posInRootFrame));
    HitTestResult result = m_localRoot->frame()->eventHandler().hitTestResultAtPoint(
        docPoint, HitTestRequest::ReadOnly | HitTestRequest::Active);
    result.setToShadowHostIfInUserAgentShadowRoot();
    return result;
}

InspectorOverlay* WebFrameWidgetImpl::inspectorOverlay()
{
    if (!m_localRoot)
        return nullptr;
    //   if (WebDevToolsAgentImpl* devtools = m_localRoot->devToolsAgentImpl())
    //     return devtools->overlay();
    DebugBreak();
    return nullptr;
}

LocalFrame* WebFrameWidgetImpl::focusedLocalFrameInWidget() const
{
    LocalFrame* frame = page()->focusController().focusedFrame();
    return (frame && frame->localFrameRoot() == m_localRoot->frame()) ? frame
                                                                      : nullptr;
}

WebPlugin* WebFrameWidgetImpl::focusedPluginIfInputMethodSupported(
    LocalFrame* frame) const
{
    WebPluginContainerImpl* container = WebLocalFrameImpl::currentPluginContainer(frame);
    if (container && container->supportsInputMethod())
        return container->plugin();
    return nullptr;
}

LocalFrame* WebFrameWidgetImpl::focusedLocalFrameAvailableForIme() const
{
    if (!m_imeAcceptEvents)
        return nullptr;
    return focusedLocalFrameInWidget();
=======
    if (m_layerTreeView) {
        if (m_rootLayer) {
            m_layerTreeView->setRootLayer(*m_rootLayer);
            // We register viewport layers here since there may not be a layer
            // tree view prior to this point.
            GraphicsLayer* rootScrollLayer = compositor()->scrollLayer();
            ASSERT(rootScrollLayer);
            WebLayer* pageScaleLayer = rootScrollLayer->parent() ? rootScrollLayer->parent()->platformLayer() : nullptr;
            m_layerTreeView->registerViewportLayers(nullptr, pageScaleLayer, rootScrollLayer->platformLayer(), nullptr);
        } else {
            m_layerTreeView->clearRootLayer();
            m_layerTreeView->clearViewportLayers();
        }
    }

    suppressInvalidations(false);
}

void WebFrameWidgetImpl::attachCompositorAnimationTimeline(WebCompositorAnimationTimeline* compositorTimeline)
{
    if (m_layerTreeView)
        m_layerTreeView->attachCompositorAnimationTimeline(compositorTimeline);

}

void WebFrameWidgetImpl::detachCompositorAnimationTimeline(WebCompositorAnimationTimeline* compositorTimeline)
{
    if (m_layerTreeView)
        m_layerTreeView->detachCompositorAnimationTimeline(compositorTimeline);
}

void WebFrameWidgetImpl::setVisibilityState(WebPageVisibilityState visibilityState, bool isInitialState)
{
    if (!page())
        return;

    // FIXME: This is not correct, since Show and Hide messages for a frame's Widget do not necessarily
    // correspond to Page visibility, but is necessary until we properly sort out OOPIF visibility.
    page()->setVisibilityState(static_cast<PageVisibilityState>(visibilityState), isInitialState);

    if (m_layerTreeView) {
        bool visible = visibilityState == WebPageVisibilityStateVisible;
        m_layerTreeView->setVisible(visible);
    }
>>>>>>> miniblink49
}

} // namespace blink
