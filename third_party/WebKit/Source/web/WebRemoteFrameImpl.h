// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebRemoteFrameImpl_h
#define WebRemoteFrameImpl_h

<<<<<<< HEAD
#include "core/frame/RemoteFrame.h"
#include "platform/heap/SelfKeepAlive.h"
#include "public/platform/WebInsecureRequestPolicy.h"
#include "public/web/WebRemoteFrame.h"
#include "public/web/WebRemoteFrameClient.h"
#include "web/RemoteFrameClientImpl.h"
#include "web/WebExport.h"
#include "web/WebFrameImplBase.h"
#include "wtf/Compiler.h"
=======
#include "core/frame/FrameOwner.h"
#include "platform/heap/Handle.h"
#include "public/web/WebRemoteFrame.h"
#include "public/web/WebRemoteFrameClient.h"
#include "web/RemoteFrameClientImpl.h"
#include "wtf/HashMap.h"
#include "wtf/OwnPtr.h"
#include "wtf/RefCounted.h"
>>>>>>> miniblink49

namespace blink {

class FrameHost;
class FrameOwner;
class RemoteFrame;
<<<<<<< HEAD
enum class WebFrameLoadType;
class WebAssociatedURLLoader;
struct WebAssociatedURLLoaderOptions;

class WEB_EXPORT WebRemoteFrameImpl final
    : public WebFrameImplBase,
      NON_EXPORTED_BASE(public WebRemoteFrame) {
public:
    static WebRemoteFrameImpl* create(WebTreeScopeType,
        WebRemoteFrameClient*,
        WebFrame* opener = nullptr);
    ~WebRemoteFrameImpl() override;

    // WebFrame methods:
=======

class WebRemoteFrameImpl final : public RefCountedWillBeGarbageCollectedFinalized<WebRemoteFrameImpl>, public WebRemoteFrame {
public:
    static WebRemoteFrame* create(WebTreeScopeType, WebRemoteFrameClient*);
    ~WebRemoteFrameImpl() override;

    // WebRemoteFrame methods.
    bool isWebLocalFrame() const override;
    WebLocalFrame* toWebLocalFrame() override;
    bool isWebRemoteFrame() const override;
    WebRemoteFrame* toWebRemoteFrame() override;
>>>>>>> miniblink49
    void close() override;
    WebString uniqueName() const override;
    WebString assignedName() const override;
    void setName(const WebString&) override;
    WebVector<WebIconURL> iconURLs(int iconTypesMask) const override;
<<<<<<< HEAD
    void setSharedWorkerRepositoryClient(
        WebSharedWorkerRepositoryClient*) override;
    void setCanHaveScrollbars(bool) override;
    WebSize getScrollOffset() const override;
    void setScrollOffset(const WebSize&) override;
=======
    void setRemoteWebLayer(WebLayer*) override;
    void setSharedWorkerRepositoryClient(WebSharedWorkerRepositoryClient*) override;
    void setCanHaveScrollbars(bool) override;
    WebSize scrollOffset() const override;
    void setScrollOffset(const WebSize&) override;
    WebSize minimumScrollOffset() const override;
    WebSize maximumScrollOffset() const override;
>>>>>>> miniblink49
    WebSize contentsSize() const override;
    bool hasVisibleContent() const override;
    WebRect visibleContentRect() const override;
    bool hasHorizontalScrollbar() const override;
    bool hasVerticalScrollbar() const override;
    WebView* view() const override;
<<<<<<< HEAD
    WebDocument document() const override;
    WebPerformance performance() const override;
    void dispatchUnloadEvent() override;
    void executeScript(const WebScriptSource&) override;
    void executeScriptInIsolatedWorld(int worldID,
        const WebScriptSource* sources,
        unsigned numSources) override;
    void setIsolatedWorldSecurityOrigin(int worldID,
        const WebSecurityOrigin&) override;
    void setIsolatedWorldContentSecurityPolicy(int worldID,
        const WebString&) override;
    void collectGarbage() override;
    v8::Local<v8::Value> executeScriptAndReturnValue(
        const WebScriptSource&) override;
    void executeScriptInIsolatedWorld(
        int worldID,
        const WebScriptSource* sourcesIn,
        unsigned numSources,
        WebVector<v8::Local<v8::Value>>* results) override;
=======
    void removeChild(WebFrame*) override;
    WebDocument document() const override;
#ifdef MINIBLINK_NOT_IMPLEMENTED
    WebPerformance performance() const override;
#endif // MINIBLINK_NOT_IMPLEMENTED
    bool dispatchBeforeUnloadEvent() override;
    void dispatchUnloadEvent() override;
    NPObject* windowObject() const override;
    void bindToWindowObject(const WebString& name, NPObject*) override;
    void bindToWindowObject(const WebString& name, NPObject*, void*) override;
    void executeScript(const WebScriptSource&) override;
    void executeScriptInIsolatedWorld(
        int worldID, const WebScriptSource* sources, unsigned numSources,
        int extensionGroup) override;
    void setIsolatedWorldSecurityOrigin(int worldID, const WebSecurityOrigin&) override;
    void setIsolatedWorldContentSecurityPolicy(int worldID, const WebString&) override;
    void addMessageToConsole(const WebConsoleMessage&) override;
    void collectGarbage() override;
    bool checkIfRunInsecureContent(const WebURL&) const override;
    v8::Local<v8::Value> executeScriptAndReturnValue(
        const WebScriptSource&) override;
    void executeScriptInIsolatedWorld(
        int worldID, const WebScriptSource* sourcesIn, unsigned numSources,
        int extensionGroup, WebVector<v8::Local<v8::Value>>* results) override;
>>>>>>> miniblink49
    v8::Local<v8::Value> callFunctionEvenIfScriptDisabled(
        v8::Local<v8::Function>,
        v8::Local<v8::Value>,
        int argc,
        v8::Local<v8::Value> argv[]) override;
    v8::Local<v8::Context> mainWorldScriptContext() const override;
<<<<<<< HEAD
    v8::Local<v8::Context> deprecatedMainWorldScriptContext() const override;
    void reload(WebFrameLoadType) override;
    void reloadWithOverrideURL(const WebURL& overrideUrl,
        WebFrameLoadType) override;
    void loadRequest(const WebURLRequest&) override;
    void loadHTMLString(const WebData& html,
        const WebURL& baseURL,
        const WebURL& unreachableURL,
=======
    void reload(bool ignoreCache) override;
    void reloadWithOverrideURL(const WebURL& overrideUrl, bool ignoreCache) override;
    void loadRequest(const WebURLRequest&) override;
    void loadHistoryItem(const WebHistoryItem&, WebHistoryLoadType, WebURLRequest::CachePolicy) override;
    void loadData(
        const WebData&, const WebString& mimeType, const WebString& textEncoding,
        const WebURL& baseURL, const WebURL& unreachableURL, bool replace) override;
    void loadHTMLString(
        const WebData& html, const WebURL& baseURL, const WebURL& unreachableURL,
>>>>>>> miniblink49
        bool replace) override;
    void stopLoading() override;
    WebDataSource* provisionalDataSource() const override;
    WebDataSource* dataSource() const override;
    void enableViewSourceMode(bool enable) override;
    bool isViewSourceModeEnabled() const override;
    void setReferrerForRequest(WebURLRequest&, const WebURL& referrer) override;
    void dispatchWillSendRequest(WebURLRequest&) override;
<<<<<<< HEAD
    WebAssociatedURLLoader* createAssociatedURLLoader(
        const WebAssociatedURLLoaderOptions&) override;
    unsigned unloadListenerCount() const override;
    int printBegin(const WebPrintParams&,
        const WebNode& constrainToNode) override;
=======
    WebURLLoader* createAssociatedURLLoader(const WebURLLoaderOptions&) override;
    unsigned unloadListenerCount() const override;
    void replaceSelection(const WebString&) override;
    void insertText(const WebString&) override;
    void setMarkedText(const WebString&, unsigned location, unsigned length) override;
    void unmarkText() override;
    bool hasMarkedText() const override;
    WebRange markedRange() const override;
    bool firstRectForCharacterRange(unsigned location, unsigned length, WebRect&) const override;
    size_t characterIndexForPoint(const WebPoint&) const override;
    bool executeCommand(const WebString&, const WebNode& = WebNode()) override;
    bool executeCommand(const WebString&, const WebString& value, const WebNode& = WebNode()) override;
    bool isCommandEnabled(const WebString&) const override;
    void enableContinuousSpellChecking(bool) override;
    bool isContinuousSpellCheckingEnabled() const override;
    void requestTextChecking(const WebElement&) override;
    void replaceMisspelledRange(const WebString&) override;
    void removeSpellingMarkers() override;
    bool hasSelection() const override;
    WebRange selectionRange() const override;
    WebString selectionAsText() const override;
    WebString selectionAsMarkup() const override;
    bool selectWordAroundCaret() override;
    void selectRange(const WebPoint& base, const WebPoint& extent) override;
    void selectRange(const WebRange&) override;
    void moveRangeSelection(const WebPoint& base, const WebPoint& extent, WebFrame::TextGranularity = CharacterGranularity) override;
    void moveCaretSelection(const WebPoint&) override;
    bool setEditableSelectionOffsets(int start, int end) override;
    bool setCompositionFromExistingText(int compositionStart, int compositionEnd, const WebVector<WebCompositionUnderline>& underlines) override;
    void extendSelectionAndDelete(int before, int after) override;
    void setCaretVisible(bool) override;
    int printBegin(const WebPrintParams&, const WebNode& constrainToNode) override;
>>>>>>> miniblink49
    float printPage(int pageToPrint, WebCanvas*) override;
    float getPrintPageShrink(int page) override;
    void printEnd() override;
    bool isPrintScalingDisabledForPlugin(const WebNode&) override;
<<<<<<< HEAD
    void printPagesWithBoundaries(WebCanvas*, const WebSize&) override;
=======
    bool hasCustomPageSizeStyle(int pageIndex) override;
    bool isPageBoxVisible(int pageIndex) override;
    void pageSizeAndMarginsInPixels(
        int pageIndex,
        WebSize& pageSize,
        int& marginTop,
        int& marginRight,
        int& marginBottom,
        int& marginLeft) override;
    WebString pageProperty(const WebString& propertyName, int pageIndex) override;
    void printPagesWithBoundaries(WebCanvas*, const WebSize&) override;
    bool find(
        int identifier, const WebString& searchText, const WebFindOptions&,
        bool wrapWithinFrame, WebRect* selectionRect) override;
    void stopFinding(bool clearSelection) override;
    void scopeStringMatches(
        int identifier, const WebString& searchText, const WebFindOptions&,
        bool reset) override;
    void cancelPendingScopingEffort() override;
    void increaseMatchCount(int count, int identifier) override;
    void resetMatchCount() override;
    int findMatchMarkersVersion() const override;
    WebFloatRect activeFindMatchRect() override;
    void findMatchRects(WebVector<WebFloatRect>&) override;
    int selectNearestFindMatch(const WebFloatPoint&, WebRect* selectionRect) override;
    void setTickmarks(const WebVector<WebRect>&) override;
>>>>>>> miniblink49
    void dispatchMessageEventWithOriginCheck(
        const WebSecurityOrigin& intendedTargetOrigin,
        const WebDOMEvent&) override;

<<<<<<< HEAD
    WebRect selectionBoundsRect() const override;

    WebString layerTreeAsText(bool showDebugInfo = false) const override;

    WebFrameImplBase* toImplBase() { return this; }

    // WebFrameImplBase methods:
    void initializeCoreFrame(FrameHost*,
        FrameOwner*,
        const AtomicString& name,
        const AtomicString& uniqueName) override;
    RemoteFrame* frame() const override { return m_frame.get(); }

    void setCoreFrame(RemoteFrame*);
=======
    WebString contentAsText(size_t maxChars) const override;
    WebString contentAsMarkup() const override;
    WebString layoutTreeAsText(LayoutAsTextControls toShow = LayoutAsTextNormal) const override;
    WebString markerTextForListItem(const WebElement&) const override;
    WebRect selectionBoundsRect() const override;

    bool selectionStartHasSpellingMarkerFor(int from, int length) const override;
    WebString layerTreeAsText(bool showDebugInfo = false) const override;

    WebLocalFrame* createLocalChild(WebTreeScopeType, const WebString& name, WebSandboxFlags, WebFrameClient*, WebFrame* previousSibling) override;
    WebRemoteFrame* createRemoteChild(WebTreeScopeType, const WebString& name, WebSandboxFlags, WebRemoteFrameClient*) override;

    void initializeCoreFrame(FrameHost*, FrameOwner*, const AtomicString& name);

    void setCoreFrame(PassRefPtrWillBeRawPtr<RemoteFrame>);
    RemoteFrame* frame() const { return m_frame.get(); }
>>>>>>> miniblink49

    WebRemoteFrameClient* client() const { return m_client; }

    static WebRemoteFrameImpl* fromFrame(RemoteFrame&);

<<<<<<< HEAD
    // WebRemoteFrame methods:
    WebLocalFrame* createLocalChild(WebTreeScopeType,
        const WebString& name,
        const WebString& uniqueName,
        WebSandboxFlags,
        WebFrameClient*,
        WebFrame* previousSibling,
        const WebFrameOwnerProperties&,
        WebFrame* opener) override;
    WebRemoteFrame* createRemoteChild(WebTreeScopeType,
        const WebString& name,
        const WebString& uniqueName,
        WebSandboxFlags,
        WebRemoteFrameClient*,
        WebFrame* opener) override;
    void setWebLayer(WebLayer*) override;
    void setReplicatedOrigin(const WebSecurityOrigin&) const override;
    void setReplicatedSandboxFlags(WebSandboxFlags) const override;
    void setReplicatedName(const WebString& name,
        const WebString& uniqueName) const override;
    void setReplicatedFeaturePolicyHeader(
        const WebParsedFeaturePolicy& parsedHeader) const override;
    void addReplicatedContentSecurityPolicyHeader(
        const WebString& headerValue,
        WebContentSecurityPolicyType,
        WebContentSecurityPolicySource) const override;
    void resetReplicatedContentSecurityPolicy() const override;
    void setReplicatedInsecureRequestPolicy(
        WebInsecureRequestPolicy) const override;
    void setReplicatedPotentiallyTrustworthyUniqueOrigin(bool) const override;
    void dispatchLoadEventOnFrameOwner() const override;
=======
    void initializeFromFrame(WebLocalFrame*) const override;

    void setReplicatedOrigin(const WebSecurityOrigin&) const override;
    void setReplicatedSandboxFlags(WebSandboxFlags) const override;
    void setReplicatedName(const WebString&) const override;
    void DispatchLoadEventForFrameOwner() const override;
>>>>>>> miniblink49

    void didStartLoading() override;
    void didStopLoading() override;

<<<<<<< HEAD
    bool isIgnoredForHitTest() const override;

    void willEnterFullscreen() override;

    void setHasReceivedUserGesture() override;

    DECLARE_TRACE();
=======
#if ENABLE(OILPAN)
    DECLARE_TRACE();
#endif
>>>>>>> miniblink49

private:
    WebRemoteFrameImpl(WebTreeScopeType, WebRemoteFrameClient*);

<<<<<<< HEAD
    // Inherited from WebFrame, but intentionally hidden: it never makes sense
    // to call these on a WebRemoteFrameImpl.
    bool isWebLocalFrame() const override;
    WebLocalFrame* toWebLocalFrame() override;
    bool isWebRemoteFrame() const override;
    WebRemoteFrame* toWebRemoteFrame() override;

    Member<RemoteFrameClientImpl> m_frameClient;
    Member<RemoteFrame> m_frame;
    WebRemoteFrameClient* m_client;

    // Oilpan: WebRemoteFrameImpl must remain alive until close() is called.
    // Accomplish that by keeping a self-referential Persistent<>. It is
    // cleared upon close().
    SelfKeepAlive<WebRemoteFrameImpl> m_selfKeepAlive;
};

DEFINE_TYPE_CASTS(WebRemoteFrameImpl,
    WebFrame,
    frame,
    frame->isWebRemoteFrame(),
    frame.isWebRemoteFrame());
=======
    RemoteFrameClientImpl m_frameClient;
    RefPtrWillBeMember<RemoteFrame> m_frame;
    WebRemoteFrameClient* m_client;

    WillBeHeapHashMap<WebFrame*, OwnPtrWillBeMember<FrameOwner>> m_ownersForChildren;

#if ENABLE(OILPAN)
    // Oilpan: to provide the guarantee of having the frame live until
    // close() is called, an instance keep a self-persistent. It is
    // cleared upon calling close(). This avoids having to assume that
    // an embedder's WebFrame references are all discovered via thread
    // state (stack, registers) should an Oilpan GC strike while we're
    // in the process of detaching.
    GC_PLUGIN_IGNORE("340522")
    Persistent<WebRemoteFrameImpl> m_selfKeepAlive;
#endif
};

DEFINE_TYPE_CASTS(WebRemoteFrameImpl, WebFrame, frame, frame->isWebRemoteFrame(), frame.isWebRemoteFrame());
>>>>>>> miniblink49

} // namespace blink

#endif // WebRemoteFrameImpl_h
