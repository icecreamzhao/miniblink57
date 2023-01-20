// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "web/WebRemoteFrameImpl.h"

#include "core/dom/Fullscreen.h"
#include "core/dom/RemoteSecurityContext.h"
#include "core/dom/SecurityContext.h"
#include "core/frame/FrameView.h"
#include "core/frame/Settings.h"
#include "core/frame/csp/ContentSecurityPolicy.h"
#include "core/html/HTMLFrameOwnerElement.h"
#include "core/layout/LayoutObject.h"
=======
#include "config.h"
#include "web/WebRemoteFrameImpl.h"

#include "core/frame/FrameView.h"
#include "core/frame/RemoteFrame.h"
#include "core/frame/Settings.h"
>>>>>>> miniblink49
#include "core/page/Page.h"
#include "platform/heap/Handle.h"
#include "public/platform/WebFloatRect.h"
#include "public/platform/WebRect.h"
#include "public/web/WebDocument.h"
<<<<<<< HEAD
#include "public/web/WebFrameOwnerProperties.h"
#include "public/web/WebPerformance.h"
#include "public/web/WebRange.h"
#include "public/web/WebTreeScopeType.h"
#include "web/RemoteFrameOwner.h"
#include "web/WebLocalFrameImpl.h"
#include "web/WebViewImpl.h"
=======
#include "public/web/WebPerformance.h"
#include "public/web/WebRange.h"
#include "public/web/WebTreeScopeType.h"
#include "web/RemoteBridgeFrameOwner.h"
#include "web/WebViewImpl.h"
//#include <v8/include/v8.h>
>>>>>>> miniblink49
#include <v8.h>

namespace blink {

<<<<<<< HEAD
WebRemoteFrame* WebRemoteFrame::create(WebTreeScopeType scope,
    WebRemoteFrameClient* client,
    WebFrame* opener)
{
    return WebRemoteFrameImpl::create(scope, client, opener);
}

WebRemoteFrameImpl* WebRemoteFrameImpl::create(WebTreeScopeType scope,
    WebRemoteFrameClient* client,
    WebFrame* opener)
{
    WebRemoteFrameImpl* frame = new WebRemoteFrameImpl(scope, client);
    frame->setOpener(opener);
    return frame;
}

WebRemoteFrameImpl::~WebRemoteFrameImpl() { }

DEFINE_TRACE(WebRemoteFrameImpl)
{
    visitor->trace(m_frameClient);
    visitor->trace(m_frame);
    WebFrame::traceFrames(visitor, this);
    WebFrameImplBase::trace(visitor);
}
=======
WebRemoteFrame* WebRemoteFrame::create(WebTreeScopeType scope, WebRemoteFrameClient* client)
{
    return WebRemoteFrameImpl::create(scope, client);
}

WebRemoteFrame* WebRemoteFrameImpl::create(WebTreeScopeType scope, WebRemoteFrameClient* client)
{
    WebRemoteFrameImpl* frame = new WebRemoteFrameImpl(scope, client);
#if ENABLE(OILPAN)
    return frame;
#else
    return adoptRef(frame).leakRef();
#endif
}

WebRemoteFrameImpl::~WebRemoteFrameImpl()
{
}

#if ENABLE(OILPAN)
DEFINE_TRACE(WebRemoteFrameImpl)
{
    visitor->trace(m_frame);
    visitor->trace(m_ownersForChildren);
    visitor->template registerWeakMembers<WebFrame, &WebFrame::clearWeakFrames>(this);
    WebFrame::traceFrames(visitor, this);
}
#endif
>>>>>>> miniblink49

bool WebRemoteFrameImpl::isWebLocalFrame() const
{
    return false;
}

WebLocalFrame* WebRemoteFrameImpl::toWebLocalFrame()
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return nullptr;
}

bool WebRemoteFrameImpl::isWebRemoteFrame() const
{
    return true;
}

WebRemoteFrame* WebRemoteFrameImpl::toWebRemoteFrame()
{
    return this;
}

void WebRemoteFrameImpl::close()
{
<<<<<<< HEAD
    WebRemoteFrame::close();

    m_selfKeepAlive.clear();
=======
#if ENABLE(OILPAN)
    m_selfKeepAlive.clear();
#else
    deref();
#endif
>>>>>>> miniblink49
}

WebString WebRemoteFrameImpl::uniqueName() const
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return WebString();
}

WebString WebRemoteFrameImpl::assignedName() const
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return WebString();
}

void WebRemoteFrameImpl::setName(const WebString&)
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

WebVector<WebIconURL> WebRemoteFrameImpl::iconURLs(int iconTypesMask) const
{
<<<<<<< HEAD
    NOTREACHED();
    return WebVector<WebIconURL>();
}

void WebRemoteFrameImpl::setSharedWorkerRepositoryClient(
    WebSharedWorkerRepositoryClient*)
{
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
    return WebVector<WebIconURL>();
}

void WebRemoteFrameImpl::setRemoteWebLayer(WebLayer* webLayer)
{
    if (!frame())
        return;

    frame()->setRemotePlatformLayer(webLayer);
}

void WebRemoteFrameImpl::setSharedWorkerRepositoryClient(WebSharedWorkerRepositoryClient*)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

void WebRemoteFrameImpl::setCanHaveScrollbars(bool)
{
<<<<<<< HEAD
    NOTREACHED();
}

WebSize WebRemoteFrameImpl::getScrollOffset() const
{
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
}

WebSize WebRemoteFrameImpl::scrollOffset() const
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return WebSize();
}

void WebRemoteFrameImpl::setScrollOffset(const WebSize&)
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
}

WebSize WebRemoteFrameImpl::minimumScrollOffset() const
{
    ASSERT_NOT_REACHED();
    return WebSize();
}

WebSize WebRemoteFrameImpl::maximumScrollOffset() const
{
    ASSERT_NOT_REACHED();
    return WebSize();
>>>>>>> miniblink49
}

WebSize WebRemoteFrameImpl::contentsSize() const
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return WebSize();
}

bool WebRemoteFrameImpl::hasVisibleContent() const
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return false;
}

WebRect WebRemoteFrameImpl::visibleContentRect() const
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return WebRect();
}

bool WebRemoteFrameImpl::hasHorizontalScrollbar() const
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return false;
}

bool WebRemoteFrameImpl::hasVerticalScrollbar() const
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return false;
}

WebView* WebRemoteFrameImpl::view() const
{
    if (!frame())
        return nullptr;
    return WebViewImpl::fromPage(frame()->page());
}

<<<<<<< HEAD
=======
void WebRemoteFrameImpl::removeChild(WebFrame* frame)
{
    WebFrame::removeChild(frame);
    m_ownersForChildren.remove(frame);
}

>>>>>>> miniblink49
WebDocument WebRemoteFrameImpl::document() const
{
    // TODO(dcheng): this should also ASSERT_NOT_REACHED, but a lot of
    // code tries to access the document of a remote frame at the moment.
    return WebDocument();
}

<<<<<<< HEAD
WebPerformance WebRemoteFrameImpl::performance() const
{
    NOTREACHED();
    return WebPerformance();
}

void WebRemoteFrameImpl::dispatchUnloadEvent()
{
    NOTREACHED();
=======
#ifdef MINIBLINK_NOT_IMPLEMENTED
WebPerformance WebRemoteFrameImpl::performance() const
{
    ASSERT_NOT_REACHED();
    return WebPerformance();
}
#endif // MINIBLINK_NOT_IMPLEMENTED

bool WebRemoteFrameImpl::dispatchBeforeUnloadEvent()
{
    ASSERT_NOT_REACHED();
    return false;
}

void WebRemoteFrameImpl::dispatchUnloadEvent()
{
    ASSERT_NOT_REACHED();
}

NPObject* WebRemoteFrameImpl::windowObject() const
{
    ASSERT_NOT_REACHED();
    return nullptr;
}

void WebRemoteFrameImpl::bindToWindowObject(const WebString& name, NPObject*)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::bindToWindowObject(const WebString& name, NPObject*, void*)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

void WebRemoteFrameImpl::executeScript(const WebScriptSource&)
{
<<<<<<< HEAD
    NOTREACHED();
}

void WebRemoteFrameImpl::executeScriptInIsolatedWorld(
    int worldID,
    const WebScriptSource* sources,
    unsigned numSources)
{
    NOTREACHED();
}

void WebRemoteFrameImpl::setIsolatedWorldSecurityOrigin(
    int worldID,
    const WebSecurityOrigin&)
{
    NOTREACHED();
}

void WebRemoteFrameImpl::setIsolatedWorldContentSecurityPolicy(
    int worldID,
    const WebString&)
{
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::executeScriptInIsolatedWorld(
    int worldID, const WebScriptSource* sources, unsigned numSources,
    int extensionGroup)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::setIsolatedWorldSecurityOrigin(int worldID, const WebSecurityOrigin&)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::setIsolatedWorldContentSecurityPolicy(int worldID, const WebString&)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::addMessageToConsole(const WebConsoleMessage&)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

void WebRemoteFrameImpl::collectGarbage()
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
}

bool WebRemoteFrameImpl::checkIfRunInsecureContent(const WebURL&) const
{
    ASSERT_NOT_REACHED();
    return false;
>>>>>>> miniblink49
}

v8::Local<v8::Value> WebRemoteFrameImpl::executeScriptAndReturnValue(
    const WebScriptSource&)
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return v8::Local<v8::Value>();
}

void WebRemoteFrameImpl::executeScriptInIsolatedWorld(
<<<<<<< HEAD
    int worldID,
    const WebScriptSource* sourcesIn,
    unsigned numSources,
    WebVector<v8::Local<v8::Value>>* results)
{
    NOTREACHED();
=======
    int worldID, const WebScriptSource* sourcesIn, unsigned numSources,
    int extensionGroup, WebVector<v8::Local<v8::Value>>* results)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

v8::Local<v8::Value> WebRemoteFrameImpl::callFunctionEvenIfScriptDisabled(
    v8::Local<v8::Function>,
    v8::Local<v8::Value>,
    int argc,
    v8::Local<v8::Value> argv[])
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return v8::Local<v8::Value>();
}

v8::Local<v8::Context> WebRemoteFrameImpl::mainWorldScriptContext() const
{
<<<<<<< HEAD
    NOTREACHED();
    return v8::Local<v8::Context>();
}

v8::Local<v8::Context> WebRemoteFrameImpl::deprecatedMainWorldScriptContext()
    const
{
    return toV8Context(frame(), DOMWrapperWorld::mainWorld());
}

void WebRemoteFrameImpl::reload(WebFrameLoadType)
{
    NOTREACHED();
}

void WebRemoteFrameImpl::reloadWithOverrideURL(const WebURL& overrideUrl,
    WebFrameLoadType)
{
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
    return v8::Local<v8::Context>();
}

void WebRemoteFrameImpl::reload(bool ignoreCache)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::reloadWithOverrideURL(const WebURL& overrideUrl, bool ignoreCache)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

void WebRemoteFrameImpl::loadRequest(const WebURLRequest&)
{
<<<<<<< HEAD
    NOTREACHED();
}

void WebRemoteFrameImpl::loadHTMLString(const WebData& html,
    const WebURL& baseURL,
    const WebURL& unreachableURL,
    bool replace)
{
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::loadHistoryItem(const WebHistoryItem&, WebHistoryLoadType, WebURLRequest::CachePolicy)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::loadData(
    const WebData&, const WebString& mimeType, const WebString& textEncoding,
    const WebURL& baseURL, const WebURL& unreachableURL, bool replace)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::loadHTMLString(
    const WebData& html, const WebURL& baseURL, const WebURL& unreachableURL,
    bool replace)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

void WebRemoteFrameImpl::stopLoading()
{
    // TODO(dcheng,japhet): Calling this method should stop loads
    // in all subframes, both remote and local.
}

WebDataSource* WebRemoteFrameImpl::provisionalDataSource() const
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return nullptr;
}

WebDataSource* WebRemoteFrameImpl::dataSource() const
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return nullptr;
}

void WebRemoteFrameImpl::enableViewSourceMode(bool enable)
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

bool WebRemoteFrameImpl::isViewSourceModeEnabled() const
{
<<<<<<< HEAD
    NOTREACHED();
    return false;
}

void WebRemoteFrameImpl::setReferrerForRequest(WebURLRequest&,
    const WebURL& referrer)
{
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
    return false;
}

void WebRemoteFrameImpl::setReferrerForRequest(WebURLRequest&, const WebURL& referrer)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

void WebRemoteFrameImpl::dispatchWillSendRequest(WebURLRequest&)
{
<<<<<<< HEAD
    NOTREACHED();
}

WebAssociatedURLLoader* WebRemoteFrameImpl::createAssociatedURLLoader(
    const WebAssociatedURLLoaderOptions&)
{
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
}

WebURLLoader* WebRemoteFrameImpl::createAssociatedURLLoader(const WebURLLoaderOptions&)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return nullptr;
}

unsigned WebRemoteFrameImpl::unloadListenerCount() const
{
<<<<<<< HEAD
    NOTREACHED();
    return 0;
}

int WebRemoteFrameImpl::printBegin(const WebPrintParams&,
    const WebNode& constrainToNode)
{
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
    return 0;
}

void WebRemoteFrameImpl::replaceSelection(const WebString&)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::insertText(const WebString&)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::setMarkedText(const WebString&, unsigned location, unsigned length)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::unmarkText()
{
    ASSERT_NOT_REACHED();
}

bool WebRemoteFrameImpl::hasMarkedText() const
{
    ASSERT_NOT_REACHED();
    return false;
}

WebRange WebRemoteFrameImpl::markedRange() const
{
    ASSERT_NOT_REACHED();
    return WebRange();
}

bool WebRemoteFrameImpl::firstRectForCharacterRange(unsigned location, unsigned length, WebRect&) const
{
    ASSERT_NOT_REACHED();
    return false;
}

size_t WebRemoteFrameImpl::characterIndexForPoint(const WebPoint&) const
{
    ASSERT_NOT_REACHED();
    return 0;
}

bool WebRemoteFrameImpl::executeCommand(const WebString&, const WebNode&)
{
    ASSERT_NOT_REACHED();
    return false;
}

bool WebRemoteFrameImpl::executeCommand(const WebString&, const WebString& value, const WebNode&)
{
    ASSERT_NOT_REACHED();
    return false;
}

bool WebRemoteFrameImpl::isCommandEnabled(const WebString&) const
{
    ASSERT_NOT_REACHED();
    return false;
}

void WebRemoteFrameImpl::enableContinuousSpellChecking(bool)
{
}

bool WebRemoteFrameImpl::isContinuousSpellCheckingEnabled() const
{
    return false;
}

void WebRemoteFrameImpl::requestTextChecking(const WebElement&)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::replaceMisspelledRange(const WebString&)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::removeSpellingMarkers()
{
    ASSERT_NOT_REACHED();
}

bool WebRemoteFrameImpl::hasSelection() const
{
    ASSERT_NOT_REACHED();
    return false;
}

WebRange WebRemoteFrameImpl::selectionRange() const
{
    ASSERT_NOT_REACHED();
    return WebRange();
}

WebString WebRemoteFrameImpl::selectionAsText() const
{
    ASSERT_NOT_REACHED();
    return WebString();
}

WebString WebRemoteFrameImpl::selectionAsMarkup() const
{
    ASSERT_NOT_REACHED();
    return WebString();
}

bool WebRemoteFrameImpl::selectWordAroundCaret()
{
    ASSERT_NOT_REACHED();
    return false;
}

void WebRemoteFrameImpl::selectRange(const WebPoint& base, const WebPoint& extent)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::selectRange(const WebRange&)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::moveRangeSelection(const WebPoint& base, const WebPoint& extent, WebFrame::TextGranularity granularity)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::moveCaretSelection(const WebPoint&)
{
    ASSERT_NOT_REACHED();
}

bool WebRemoteFrameImpl::setEditableSelectionOffsets(int start, int end)
{
    ASSERT_NOT_REACHED();
    return false;
}

bool WebRemoteFrameImpl::setCompositionFromExistingText(int compositionStart, int compositionEnd, const WebVector<WebCompositionUnderline>& underlines)
{
    ASSERT_NOT_REACHED();
    return false;
}

void WebRemoteFrameImpl::extendSelectionAndDelete(int before, int after)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::setCaretVisible(bool)
{
    ASSERT_NOT_REACHED();
}

int WebRemoteFrameImpl::printBegin(const WebPrintParams&, const WebNode& constrainToNode)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return 0;
}

float WebRemoteFrameImpl::printPage(int pageToPrint, WebCanvas*)
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return 0.0;
}

float WebRemoteFrameImpl::getPrintPageShrink(int page)
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return 0.0;
}

void WebRemoteFrameImpl::printEnd()
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

bool WebRemoteFrameImpl::isPrintScalingDisabledForPlugin(const WebNode&)
{
<<<<<<< HEAD
    NOTREACHED();
    return false;
}

void WebRemoteFrameImpl::printPagesWithBoundaries(WebCanvas*, const WebSize&)
{
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
    return false;
}

bool WebRemoteFrameImpl::hasCustomPageSizeStyle(int pageIndex)
{
    ASSERT_NOT_REACHED();
    return false;
}

bool WebRemoteFrameImpl::isPageBoxVisible(int pageIndex)
{
    ASSERT_NOT_REACHED();
    return false;
}

void WebRemoteFrameImpl::pageSizeAndMarginsInPixels(
    int pageIndex,
    WebSize& pageSize,
    int& marginTop,
    int& marginRight,
    int& marginBottom,
    int& marginLeft)
{
    ASSERT_NOT_REACHED();
}

WebString WebRemoteFrameImpl::pageProperty(const WebString& propertyName, int pageIndex)
{
    ASSERT_NOT_REACHED();
    return WebString();
}

void WebRemoteFrameImpl::printPagesWithBoundaries(WebCanvas*, const WebSize&)
{
    ASSERT_NOT_REACHED();
}

bool WebRemoteFrameImpl::find(
    int identifier, const WebString& searchText, const WebFindOptions&,
    bool wrapWithinFrame, WebRect* selectionRect)
{
    ASSERT_NOT_REACHED();
    return false;
}

void WebRemoteFrameImpl::stopFinding(bool clearSelection)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::scopeStringMatches(
    int identifier, const WebString& searchText, const WebFindOptions&,
    bool reset)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::cancelPendingScopingEffort()
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::increaseMatchCount(int count, int identifier)
{
    ASSERT_NOT_REACHED();
}

void WebRemoteFrameImpl::resetMatchCount()
{
    ASSERT_NOT_REACHED();
}

int WebRemoteFrameImpl::findMatchMarkersVersion() const
{
    ASSERT_NOT_REACHED();
    return 0;
}

WebFloatRect WebRemoteFrameImpl::activeFindMatchRect()
{
    ASSERT_NOT_REACHED();
    return WebFloatRect();
}

void WebRemoteFrameImpl::findMatchRects(WebVector<WebFloatRect>&)
{
    ASSERT_NOT_REACHED();
}

int WebRemoteFrameImpl::selectNearestFindMatch(const WebFloatPoint&, WebRect* selectionRect)
{
    ASSERT_NOT_REACHED();
    return 0;
}

void WebRemoteFrameImpl::setTickmarks(const WebVector<WebRect>&)
{
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
}

void WebRemoteFrameImpl::dispatchMessageEventWithOriginCheck(
    const WebSecurityOrigin& intendedTargetOrigin,
    const WebDOMEvent&)
{
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
}

WebString WebRemoteFrameImpl::contentAsText(size_t maxChars) const
{
    ASSERT_NOT_REACHED();
    return WebString();
}

WebString WebRemoteFrameImpl::contentAsMarkup() const
{
    ASSERT_NOT_REACHED();
    return WebString();
}

WebString WebRemoteFrameImpl::layoutTreeAsText(LayoutAsTextControls toShow) const
{
    ASSERT_NOT_REACHED();
    return WebString();
}

WebString WebRemoteFrameImpl::markerTextForListItem(const WebElement&) const
{
    ASSERT_NOT_REACHED();
    return WebString();
>>>>>>> miniblink49
}

WebRect WebRemoteFrameImpl::selectionBoundsRect() const
{
<<<<<<< HEAD
    NOTREACHED();
    return WebRect();
}

WebString WebRemoteFrameImpl::layerTreeAsText(bool showDebugInfo) const
{
    NOTREACHED();
    return WebString();
}

WebLocalFrame* WebRemoteFrameImpl::createLocalChild(
    WebTreeScopeType scope,
    const WebString& name,
    const WebString& uniqueName,
    WebSandboxFlags sandboxFlags,
    WebFrameClient* client,
    WebFrame* previousSibling,
    const WebFrameOwnerProperties& frameOwnerProperties,
    WebFrame* opener)
{
    WebLocalFrameImpl* child = WebLocalFrameImpl::create(scope, client, opener);
    insertAfter(child, previousSibling);
    RemoteFrameOwner* owner = RemoteFrameOwner::create(
        static_cast<SandboxFlags>(sandboxFlags), frameOwnerProperties);
    // FIXME: currently this calls LocalFrame::init() on the created LocalFrame,
    // which may result in the browser observing two navigations to about:blank
    // (one from the initial frame creation, and one from swapping it into the
    // remote process).  FrameLoader might need a special initialization function
    // for this case to avoid that duplicate navigation.
    child->initializeCoreFrame(frame()->host(), owner, name, uniqueName);
    // Partially related with the above FIXME--the init() call may trigger JS
    // dispatch. However,
    // if the parent is remote, it should never be detached synchronously...
    DCHECK(child->frame());
    return child;
}

void WebRemoteFrameImpl::initializeCoreFrame(FrameHost* host,
    FrameOwner* owner,
    const AtomicString& name,
    const AtomicString& uniqueName)
{
    setCoreFrame(RemoteFrame::create(m_frameClient.get(), host, owner));
    frame()->createView();
    m_frame->tree().setPrecalculatedName(name, uniqueName);
}

WebRemoteFrame* WebRemoteFrameImpl::createRemoteChild(
    WebTreeScopeType scope,
    const WebString& name,
    const WebString& uniqueName,
    WebSandboxFlags sandboxFlags,
    WebRemoteFrameClient* client,
    WebFrame* opener)
{
    WebRemoteFrameImpl* child = WebRemoteFrameImpl::create(scope, client, opener);
    appendChild(child);
    RemoteFrameOwner* owner = RemoteFrameOwner::create(
        static_cast<SandboxFlags>(sandboxFlags), WebFrameOwnerProperties());
    child->initializeCoreFrame(frame()->host(), owner, name, uniqueName);
    return child;
}

void WebRemoteFrameImpl::setWebLayer(WebLayer* layer)
{
    if (!frame())
        return;

    frame()->setWebLayer(layer);
}

void WebRemoteFrameImpl::setCoreFrame(RemoteFrame* frame)
=======
    ASSERT_NOT_REACHED();
    return WebRect();
}

bool WebRemoteFrameImpl::selectionStartHasSpellingMarkerFor(int from, int length) const
{
    ASSERT_NOT_REACHED();
    return false;
}

WebString WebRemoteFrameImpl::layerTreeAsText(bool showDebugInfo) const
{
    ASSERT_NOT_REACHED();
    return WebString();
}

WebLocalFrame* WebRemoteFrameImpl::createLocalChild(WebTreeScopeType scope, const WebString& name, WebSandboxFlags sandboxFlags, WebFrameClient* client, WebFrame* previousSibling)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    WebLocalFrameImpl* child = toWebLocalFrameImpl(WebLocalFrame::create(scope, client));
    WillBeHeapHashMap<WebFrame*, OwnPtrWillBeMember<FrameOwner>>::AddResult result =
        m_ownersForChildren.add(child, RemoteBridgeFrameOwner::create(child, static_cast<SandboxFlags>(sandboxFlags)));
    insertAfter(child, previousSibling);
    // FIXME: currently this calls LocalFrame::init() on the created LocalFrame, which may
    // result in the browser observing two navigations to about:blank (one from the initial
    // frame creation, and one from swapping it into the remote process). FrameLoader might
    // need a special initialization function for this case to avoid that duplicate navigation.
    child->initializeCoreFrame(frame()->host(), result.storedValue->value.get(), name, nullAtom);
    // Partially related with the above FIXME--the init() call may trigger JS dispatch. However,
    // if the parent is remote, it should never be detached synchronously...
    ASSERT(child->frame());
    return child;
#endif // MINIBLINK_NOT_IMPLEMENTED
    notImplemented();
    return nullptr;
}


void WebRemoteFrameImpl::initializeCoreFrame(FrameHost* host, FrameOwner* owner, const AtomicString& name)
{
    setCoreFrame(RemoteFrame::create(&m_frameClient, host, owner));
    frame()->createView();
    m_frame->tree().setName(name, nullAtom);
}

WebRemoteFrame* WebRemoteFrameImpl::createRemoteChild(WebTreeScopeType scope, const WebString& name, WebSandboxFlags sandboxFlags, WebRemoteFrameClient* client)
{
#ifdef MINIBLINK_NOT_IMPLEMENTED
    WebRemoteFrameImpl* child = toWebRemoteFrameImpl(WebRemoteFrame::create(scope, client));
    WillBeHeapHashMap<WebFrame*, OwnPtrWillBeMember<FrameOwner>>::AddResult result =
        m_ownersForChildren.add(child, RemoteBridgeFrameOwner::create(nullptr, static_cast<SandboxFlags>(sandboxFlags)));
    appendChild(child);
    child->initializeCoreFrame(frame()->host(), result.storedValue->value.get(), name);
    return child;
#endif // MINIBLINK_NOT_IMPLEMENTED
    notImplemented();
    return nullptr;
}

void WebRemoteFrameImpl::setCoreFrame(PassRefPtrWillBeRawPtr<RemoteFrame> frame)
>>>>>>> miniblink49
{
    m_frame = frame;
}

WebRemoteFrameImpl* WebRemoteFrameImpl::fromFrame(RemoteFrame& frame)
{
<<<<<<< HEAD
    if (!frame.client())
        return nullptr;
    return static_cast<RemoteFrameClientImpl*>(frame.client())->webFrame();
}

void WebRemoteFrameImpl::setReplicatedOrigin(
    const WebSecurityOrigin& origin) const
{
    DCHECK(frame());
    frame()->securityContext()->setReplicatedOrigin(origin);

    // If the origin of a remote frame changed, the accessibility object for the
    // owner element now points to a different child.
    //
    // TODO(dmazzoni, dcheng): there's probably a better way to solve this.
    // Run SitePerProcessAccessibilityBrowserTest.TwoCrossSiteNavigations to
    // ensure an alternate fix works.  http://crbug.com/566222
    FrameOwner* owner = frame()->owner();
    if (owner && owner->isLocal()) {
        HTMLElement* ownerElement = toHTMLFrameOwnerElement(owner);
        AXObjectCache* cache = ownerElement->document().existingAXObjectCache();
        if (cache)
            cache->childrenChanged(ownerElement);
    }
}

void WebRemoteFrameImpl::setReplicatedSandboxFlags(
    WebSandboxFlags flags) const
{
    DCHECK(frame());
    frame()->securityContext()->enforceSandboxFlags(
        static_cast<SandboxFlags>(flags));
}

void WebRemoteFrameImpl::setReplicatedName(const WebString& name,
    const WebString& uniqueName) const
{
    DCHECK(frame());
    frame()->tree().setPrecalculatedName(name, uniqueName);
}

void WebRemoteFrameImpl::setReplicatedFeaturePolicyHeader(
    const WebParsedFeaturePolicy& parsedHeader) const
{
    if (RuntimeEnabledFeatures::featurePolicyEnabled()) {
        FeaturePolicy* parentFeaturePolicy = nullptr;
        if (parent()) {
            Frame* parentFrame = frame()->client()->parent();
            parentFeaturePolicy = parentFrame->securityContext()->getFeaturePolicy();
        }
        frame()->securityContext()->setFeaturePolicyFromHeader(parsedHeader,
            parentFeaturePolicy);
    }
}

void WebRemoteFrameImpl::addReplicatedContentSecurityPolicyHeader(
    const WebString& headerValue,
    WebContentSecurityPolicyType type,
    WebContentSecurityPolicySource source) const
{
    frame()->securityContext()->contentSecurityPolicy()->addPolicyFromHeaderValue(
        headerValue, static_cast<ContentSecurityPolicyHeaderType>(type),
        static_cast<ContentSecurityPolicyHeaderSource>(source));
}

void WebRemoteFrameImpl::resetReplicatedContentSecurityPolicy() const
{
    frame()->securityContext()->resetReplicatedContentSecurityPolicy();
}

void WebRemoteFrameImpl::setReplicatedInsecureRequestPolicy(
    WebInsecureRequestPolicy policy) const
{
    DCHECK(frame());
    frame()->securityContext()->setInsecureRequestPolicy(policy);
}

void WebRemoteFrameImpl::setReplicatedPotentiallyTrustworthyUniqueOrigin(
    bool isUniqueOriginPotentiallyTrustworthy) const
{
    DCHECK(frame());
    // If |isUniqueOriginPotentiallyTrustworthy| is true, then the origin must be
    // unique.
    DCHECK(!isUniqueOriginPotentiallyTrustworthy || frame()->securityContext()->getSecurityOrigin()->isUnique());
    frame()
        ->securityContext()
        ->getSecurityOrigin()
        ->setUniqueOriginIsPotentiallyTrustworthy(
            isUniqueOriginPotentiallyTrustworthy);
}

void WebRemoteFrameImpl::dispatchLoadEventOnFrameOwner() const
{
    DCHECK(frame()->owner()->isLocal());
=======
#ifdef MINIBLINK_NOT_IMPLEMENTED
    if (!frame.client())
        return nullptr;
    return static_cast<RemoteFrameClientImpl*>(frame.client())->webFrame();
#endif // MINIBLINK_NOT_IMPLEMENTED
    notImplemented();
    return nullptr;
}

void WebRemoteFrameImpl::initializeFromFrame(WebLocalFrame* source) const
{
    ASSERT(source);
    WebLocalFrameImpl* localFrameImpl = toWebLocalFrameImpl(source);

    // TODO(bokan): The scale_factor argument here used to be the now-removed
    // FrameView::visibleContentScaleFactor but the callee uses this parameter
    // to set the device scale factor. crbug.com/493262
    client()->initializeChildFrame(
        localFrameImpl->frame()->view()->frameRect(),
        1);
}

void WebRemoteFrameImpl::setReplicatedOrigin(const WebSecurityOrigin& origin) const
{
    ASSERT(frame());
    frame()->securityContext()->setReplicatedOrigin(origin);
}

void WebRemoteFrameImpl::setReplicatedSandboxFlags(WebSandboxFlags flags) const
{
    ASSERT(frame());
    frame()->securityContext()->enforceSandboxFlags(static_cast<SandboxFlags>(flags));
}

void WebRemoteFrameImpl::setReplicatedName(const WebString& name) const
{
    ASSERT(frame());
    frame()->tree().setName(name, nullAtom);
}

void WebRemoteFrameImpl::DispatchLoadEventForFrameOwner() const
{
    ASSERT(frame()->owner()->isLocal());
>>>>>>> miniblink49
    frame()->owner()->dispatchLoad();
}

void WebRemoteFrameImpl::didStartLoading()
{
    frame()->setIsLoading(true);
}

void WebRemoteFrameImpl::didStopLoading()
{
    frame()->setIsLoading(false);
    if (parent() && parent()->isWebLocalFrame()) {
<<<<<<< HEAD
        WebLocalFrameImpl* parentFrame = toWebLocalFrameImpl(parent()->toWebLocalFrame());
=======
        WebLocalFrameImpl* parentFrame =
            toWebLocalFrameImpl(parent()->toWebLocalFrame());
>>>>>>> miniblink49
        parentFrame->frame()->loader().checkCompleted();
    }
}

<<<<<<< HEAD
bool WebRemoteFrameImpl::isIgnoredForHitTest() const
{
    HTMLFrameOwnerElement* owner = frame()->deprecatedLocalOwner();
    if (!owner || !owner->layoutObject())
        return false;
    return owner->layoutObject()->style()->pointerEvents() == EPointerEvents::kNone;
}

void WebRemoteFrameImpl::willEnterFullscreen()
{
    // This should only ever be called when the FrameOwner is local.
    HTMLFrameOwnerElement* ownerElement = toHTMLFrameOwnerElement(frame()->owner());

    // Call requestFullscreen() on |ownerElement| to make it the provisional
    // fullscreen element in FullscreenController, and to prepare
    // fullscreenchange events that will need to fire on it and its (local)
    // ancestors. The events will be triggered if/when fullscreen is entered.
    //
    // Passing |forCrossProcessAncestor| to requestFullscreen is necessary
    // because:
    // - |ownerElement| will need :-webkit-full-screen-ancestor style in
    //   addition to :-webkit-full-screen.
    // - there's no need to resend the ToggleFullscreen IPC to the browser
    //   process.
    //
    // TODO(alexmos): currently, this assumes prefixed requests, but in the
    // future, this should plumb in information about which request type
    // (prefixed or unprefixed) to use for firing fullscreen events.
    Fullscreen::requestFullscreen(*ownerElement,
        Fullscreen::RequestType::Prefixed,
        true /* forCrossProcessAncestor */);
}

void WebRemoteFrameImpl::setHasReceivedUserGesture()
{
    frame()->setDocumentHasReceivedUserGesture();
}

WebRemoteFrameImpl::WebRemoteFrameImpl(WebTreeScopeType scope,
    WebRemoteFrameClient* client)
    : WebRemoteFrame(scope)
    , m_frameClient(RemoteFrameClientImpl::create(this))
    , m_client(client)
    , m_selfKeepAlive(this)
=======
WebRemoteFrameImpl::WebRemoteFrameImpl(WebTreeScopeType scope, WebRemoteFrameClient* client)
    : WebRemoteFrame(scope)
    , m_frameClient(this)
    , m_client(client)
#if ENABLE(OILPAN)
    , m_selfKeepAlive(this)
#endif
>>>>>>> miniblink49
{
}

} // namespace blink
