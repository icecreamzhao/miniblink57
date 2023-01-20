// Code generated from InspectorInstrumentation.idl

#ifndef InspectorInstrumentationInl_h
#define InspectorInstrumentationInl_h

#include "core/animation/Animation.h"
#include "core/dom/CharacterData.h"
#include "core/dom/PseudoElement.h"
#include "core/html/HTMLSlotElement.h"
#include "core/inspector/InspectorInstrumentation.h"

namespace blink {

class ConsoleMessage;
class ThreadableLoaderClient;
class WebSocketHandshakeRequest;
class WebSocketHandshakeResponse;
class WorkerInspectorProxy;
class XMLHttpRequest;

namespace InspectorInstrumentation {

    CORE_EXPORT void didClearDocumentOfWindowObject(LocalFrame*);
    CORE_EXPORT void willInsertDOMNode(Node*);
    CORE_EXPORT void didInsertDOMNode(Node*);
    CORE_EXPORT void willRemoveDOMNode(Node*);
    CORE_EXPORT void willModifyDOMAttr(Element*, const AtomicString&, const AtomicString&);
    CORE_EXPORT void didModifyDOMAttr(Element*, const QualifiedName&, const AtomicString&);
    CORE_EXPORT void didRemoveDOMAttr(Element*, const QualifiedName&);
    CORE_EXPORT void characterDataModified(CharacterData*);
    CORE_EXPORT void didInvalidateStyleAttr(Node*);
    CORE_EXPORT void didPerformElementShadowDistribution(Element*);
    CORE_EXPORT void didPerformSlotDistribution(HTMLSlotElement*);
    CORE_EXPORT void documentDetached(Document*);
    CORE_EXPORT void activeStyleSheetsUpdated(Document*);
    CORE_EXPORT void fontsUpdated(Document*);
    CORE_EXPORT void mediaQueryResultChanged(Document*);
    CORE_EXPORT void didPushShadowRoot(Element*, ShadowRoot*);
    CORE_EXPORT void willPopShadowRoot(Element*, ShadowRoot*);
    CORE_EXPORT void willSendXMLHttpOrFetchNetworkRequest(ExecutionContext*, const String&);
    CORE_EXPORT void didFireWebGLError(Element*, const String&);
    CORE_EXPORT void didFireWebGLWarning(Element*);
    CORE_EXPORT void didFireWebGLErrorOrWarning(Element*, const String&);
    CORE_EXPORT void didUpdateLayout(LocalFrame*);
    CORE_EXPORT void didResizeMainFrame(LocalFrame*);
    CORE_EXPORT void didPaint(LocalFrame*, const GraphicsLayer*, GraphicsContext&, const LayoutRect&);
    CORE_EXPORT void didScheduleStyleRecalculation(Document*);
    CORE_EXPORT void applyUserAgentOverride(LocalFrame*, String*);
    CORE_EXPORT void didBlockRequest(LocalFrame*, const ResourceRequest&, DocumentLoader*, const FetchInitiatorInfo&, ResourceRequestBlockedReason);
    CORE_EXPORT void didChangeResourcePriority(LocalFrame*, unsigned long, ResourceLoadPriority);
    CORE_EXPORT void willSendRequest(LocalFrame*, unsigned long, DocumentLoader*, ResourceRequest&, const ResourceResponse&, const FetchInitiatorInfo&);
    CORE_EXPORT void markResourceAsCached(LocalFrame*, unsigned long);
    CORE_EXPORT void didReceiveResourceResponse(LocalFrame*, unsigned long, DocumentLoader*, const ResourceResponse&, Resource*);
    CORE_EXPORT void didReceiveData(LocalFrame*, unsigned long, const char*, int);
    CORE_EXPORT void didReceiveEncodedDataLength(LocalFrame*, unsigned long, int);
    CORE_EXPORT void didFinishLoading(LocalFrame*, unsigned long, double, int64_t);
    CORE_EXPORT void didReceiveCORSRedirectResponse(LocalFrame*, unsigned long, DocumentLoader*, const ResourceResponse&, Resource*);
    CORE_EXPORT void didFailLoading(LocalFrame*, unsigned long, const ResourceError&);
    CORE_EXPORT void documentThreadableLoaderStartedLoadingForClient(ExecutionContext*, unsigned long, ThreadableLoaderClient*);
    CORE_EXPORT void documentThreadableLoaderFailedToStartLoadingForClient(ExecutionContext*, ThreadableLoaderClient*);
    CORE_EXPORT void willSendEventSourceRequest(ExecutionContext*, ThreadableLoaderClient*);
    CORE_EXPORT void willDispatchEventSourceEvent(ExecutionContext*, ThreadableLoaderClient*, const AtomicString&, const AtomicString&, const String&);
    CORE_EXPORT void didFinishEventSourceRequest(ExecutionContext*, ThreadableLoaderClient*);
    CORE_EXPORT void willLoadXHR(ExecutionContext*, XMLHttpRequest*, ThreadableLoaderClient*, const AtomicString&, const KURL&, bool, PassRefPtr<EncodedFormData>, const HTTPHeaderMap&, bool);
    CORE_EXPORT void didFailXHRLoading(ExecutionContext*, XMLHttpRequest*, ThreadableLoaderClient*, const AtomicString&, const String&);
    CORE_EXPORT void didFinishXHRLoading(ExecutionContext*, XMLHttpRequest*, ThreadableLoaderClient*, const AtomicString&, const String&);
    CORE_EXPORT void willStartFetch(ExecutionContext*, ThreadableLoaderClient*);
    CORE_EXPORT void didFailFetch(ExecutionContext*, ThreadableLoaderClient*);
    CORE_EXPORT void didFinishFetch(ExecutionContext*, ThreadableLoaderClient*, const AtomicString&, const String&);
    CORE_EXPORT void scriptImported(ExecutionContext*, unsigned long, const String&);
    CORE_EXPORT void scriptExecutionBlockedByCSP(ExecutionContext*, const String&);
    CORE_EXPORT void didReceiveScriptResponse(ExecutionContext*, unsigned long);
    CORE_EXPORT void domContentLoadedEventFired(LocalFrame*);
    CORE_EXPORT void loadEventFired(LocalFrame*);
    CORE_EXPORT void frameAttachedToParent(LocalFrame*);
    CORE_EXPORT void frameDetachedFromParent(LocalFrame*);
    CORE_EXPORT void didCommitLoad(LocalFrame*, DocumentLoader*);
    CORE_EXPORT void frameDocumentUpdated(LocalFrame*);
    CORE_EXPORT void frameStartedLoading(LocalFrame*);
    CORE_EXPORT void frameStoppedLoading(LocalFrame*);
    CORE_EXPORT void frameScheduledNavigation(LocalFrame*, double);
    CORE_EXPORT void frameClearedScheduledNavigation(LocalFrame*);
    CORE_EXPORT void didStartWorker(ExecutionContext*, WorkerInspectorProxy*, bool);
    CORE_EXPORT void workerTerminated(ExecutionContext*, WorkerInspectorProxy*);
    CORE_EXPORT void didCreateWebSocket(Document*, unsigned long, const KURL&, const String&);
    CORE_EXPORT void willSendWebSocketHandshakeRequest(Document*, unsigned long, const WebSocketHandshakeRequest*);
    CORE_EXPORT void didReceiveWebSocketHandshakeResponse(Document*, unsigned long, const WebSocketHandshakeRequest*, const WebSocketHandshakeResponse*);
    CORE_EXPORT void didCloseWebSocket(Document*, unsigned long);
    CORE_EXPORT void didReceiveWebSocketFrame(Document*, unsigned long, int, bool, const char*, size_t);
    CORE_EXPORT void didSendWebSocketFrame(Document*, unsigned long, int, bool, const char*, size_t);
    CORE_EXPORT void didReceiveWebSocketFrameError(Document*, unsigned long, const String&);
    CORE_EXPORT void networkStateChanged(LocalFrame*, bool);
    CORE_EXPORT void updateApplicationCacheStatus(LocalFrame*);
    CORE_EXPORT void layerTreeDidChange(LocalFrame*);
    CORE_EXPORT void pseudoElementCreated(PseudoElement*);
    CORE_EXPORT void pseudoElementDestroyed(PseudoElement*);
    CORE_EXPORT void didCreateAnimation(Document*, unsigned);
    CORE_EXPORT void animationPlayStateChanged(Document*, Animation*, Animation::AnimationPlayState, Animation::AnimationPlayState);
    CORE_EXPORT void windowCreated(LocalFrame*, LocalFrame*);
    CORE_EXPORT void consoleMessageAdded(ExecutionContext*, ConsoleMessage*);
    CORE_EXPORT void willRecalculateStyle(Document*);
    CORE_EXPORT void didRecalculateStyle(Document*);
    CORE_EXPORT void willRunJavaScriptDialog(LocalFrame*, const String&, ChromeClient::DialogType);
    CORE_EXPORT void didRunJavaScriptDialog(LocalFrame*, bool);
} // namespace InspectorInstrumentation

} // namespace blink

#endif // !defined(InspectorInstrumentationInl_h)
