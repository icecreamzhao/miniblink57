#include "ConsoleMessage.h"
#include "bindings/core/v8/ScriptState.h"
#include "config.h"
#include "platform/heap/Handle.h"
#include "wtf/Forward.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"
#include "wtf/text/WTFString.h"
//#include "platform/EventTracer.h"
#include "core/css/CSSSelector.h"
#include "core/css/CSSStyleSheet.h"
#include "core/dom/CharacterData.h"
#include "core/dom/Document.h"
#include "core/dom/Element.h"
#include "core/events/Event.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/LocalFrame.h"
#include "core/inspector/InspectorInstrumentation.h"
#include "core/inspector/InspectorTraceEvents.h"
#include "core/page/Page.h"
#include "core/xmlhttprequest/XMLHttpRequest.h"
#include "gen/blink/core/InstrumentingAgents.h"
#include "platform/graphics/GraphicsContext.h"
#include "platform/graphics/GraphicsLayer.h"
//#include "platform/TracedValue.h"

namespace blink {

// ScriptArguments::ScriptArguments(ScriptState* scriptState, Vector<ScriptValue>& arguments)
// 	: m_scriptState(scriptState)
// {
// 	notImplemented();
// 	m_arguments.swap(arguments);
// }
//

// ScriptArguments::~ScriptArguments()
// {
// 	;
// }

//////////////////////////////////////////////////////////////////////////

std::unique_ptr<TracedValue> InspectorScheduleStyleInvalidationTrackingEvent::attributeChange(Element&, const InvalidationSet&, const QualifiedName&)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorScheduleStyleInvalidationTrackingEvent::classChange(Element&, const InvalidationSet&, const AtomicString&)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorScheduleStyleInvalidationTrackingEvent::idChange(Element&, const InvalidationSet&, const AtomicString&)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorScheduleStyleInvalidationTrackingEvent::pseudoChange(Element&, const InvalidationSet&, CSSSelector::PseudoType)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorLayoutInvalidationTrackingEvent::data(const LayoutObject* layoutObject, LayoutInvalidationReasonForTracing reason)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorPaintInvalidationTrackingEvent::data(const LayoutObject* layoutObject, const LayoutObject& paintContainer)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorScrollInvalidationTrackingEvent::data(const LayoutObject& layoutObject)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorSendRequestEvent::data(unsigned long identifier, LocalFrame* frame, const ResourceRequest& request)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorReceiveResponseEvent::data(unsigned long identifier, LocalFrame* frame, const ResourceResponse& response)
{
    notImplemented();
    return nullptr;
}

std::unique_ptr<TracedValue> InspectorReceiveDataEvent::data(unsigned long identifier, LocalFrame* frame, int encodedDataLength)
{
    notImplemented();
    return nullptr;
}

namespace InspectorResourceFinishEvent {
    std::unique_ptr<TracedValue> data(unsigned long identifier,
        double finishTime,
        bool didFail,
        int64_t encodedDataLength)
    {
        DebugBreak();
        return nullptr;
    }
}

// const char InspectorStyleInvalidatorInvalidateEvent::ElementHasPendingInvalidationList[] = "Element has pending invalidation list";
// const char InspectorStyleInvalidatorInvalidateEvent::InvalidateCustomPseudo[] = "Invalidate custom pseudo element";
// const char InspectorStyleInvalidatorInvalidateEvent::InvalidationSetMatchedAttribute[] = "Invalidation set matched attribute";
// const char InspectorStyleInvalidatorInvalidateEvent::InvalidationSetMatchedClass[] = "Invalidation set matched class";
// const char InspectorStyleInvalidatorInvalidateEvent::InvalidationSetMatchedId[] = "Invalidation set matched id";
// const char InspectorStyleInvalidatorInvalidateEvent::InvalidationSetMatchedTagName[] = "Invalidation set matched tagName";
// const char InspectorStyleInvalidatorInvalidateEvent::PreventStyleSharingForParent[] = "Prevent style sharing for parent";
//
//
// const char InspectorLayerInvalidationTrackingEvent::SquashingLayerGeometryWasUpdated[] = "Squashing layer geometry was updated";
// const char InspectorLayerInvalidationTrackingEvent::AddedToSquashingLayer[] = "The layer may have been added to an already-existing squashing layer";
// const char InspectorLayerInvalidationTrackingEvent::RemovedFromSquashingLayer[] = "Removed the layer from a squashing layer";
// const char InspectorLayerInvalidationTrackingEvent::ReflectionLayerChanged[] = "Reflection layer change";
// const char InspectorLayerInvalidationTrackingEvent::NewCompositedLayer[] = "Assigned a new composited layer";

#if 0
PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorLayerInvalidationTrackingEvent::data(const DeprecatedPaintLayer* layer, const char* reason)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorPaintEvent::data(LayoutObject* layoutObject, const LayoutRect& clipRect, const GraphicsLayer* graphicsLayer)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> frameEventData(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}


PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorCommitLoadEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorMarkLoadEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorScrollLayerEvent::data(LayoutObject* layoutObject)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorUpdateLayerTreeEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorEvaluateScriptEvent::data(LocalFrame* frame, const String& url, int lineNumber)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorFunctionCallEvent::data(ExecutionContext* context, int scriptId, const String& scriptName, int scriptLine)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorPaintImageEvent::data(const LayoutImage& layoutImage)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorPaintImageEvent::data(const LayoutObject& owningLayoutObject, const StyleImage& styleImage)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorPaintImageEvent::data(const LayoutObject* owningLayoutObject, const ImageResource& imageResource)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorUpdateCountersEvent::data()
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorInvalidateLayoutEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorRecalculateStylesEvent::data(LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorEventDispatchEvent::data(const Event& event)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorTimeStampEvent::data(ExecutionContext* context, const String& message)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorTracingSessionIdForWorkerEvent::data(const String& sessionId, const String& workerId, WorkerThread* workerThread)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorTracingStartedInFrame::data(const String& sessionId, LocalFrame* frame)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorSetLayerTreeId::data(const String& sessionId, int layerTreeId)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorAnimationEvent::data(const Animation& player)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorAnimationStateEvent::data(const Animation& player)
{
    notImplemented();
    return nullptr;
}

PassRefPtr<TraceEvent::ConvertableToTraceFormat> InspectorHitTestEvent::endData(const HitTestRequest& request, const HitTestLocation& location, const HitTestResult& result)
{
    notImplemented();
    return nullptr;
}
#endif

// PassRefPtrWillBeRawPtr<ScriptArguments> ScriptArguments::create(ScriptState* scriptState, Vector<ScriptValue>& arguments)
// {
//     notImplemented();
//     return nullptr;
// }
//
// bool ScriptArguments::getFirstArgumentAsString(String& result) const
// {
//     notImplemented();
//     return true;
// }

//////////////////////////////////////////////////////////////////////////

InstrumentingAgents::InstrumentingAgents()
{
    DebugBreak();
}

DEFINE_TRACE(InstrumentingAgents)
{
}

//////////////////////////////////////////////////////////////////////////

namespace InspectorInstrumentation {

    bool consoleAgentEnabled(ExecutionContext* executionContext)
    {
        //notImplemented();
        return false;
    }

    bool collectingHTMLParseErrorsImpl(InstrumentingAgents* instrumentingAgents)
    {
        //notImplemented();
        return false;
    }

    NativeBreakpoint::NativeBreakpoint(ExecutionContext*, const char* name, bool sync)
    {
    }
    NativeBreakpoint::NativeBreakpoint(ExecutionContext*, EventTarget*, Event*)
    {
    }

    NativeBreakpoint::~NativeBreakpoint()
    {
    }

    AsyncTask::AsyncTask(ExecutionContext*, void* task)
    {
    }

    AsyncTask::AsyncTask(ExecutionContext*, void* task, bool enabled)
    {
    }

    AsyncTask::~AsyncTask()
    {
    }

    void asyncTaskScheduled(ExecutionContext* context, const String& name, void* task)
    {
    }

    void asyncTaskScheduled(ExecutionContext* context, const String& name, void* task, bool recurring)
    {
    }

    void asyncTaskCanceled(ExecutionContext* context, void* task)
    {
    }

    void allAsyncTasksCanceled(ExecutionContext* context)
    {
    }

    bool forcePseudoState(Element*, CSSSelector::PseudoType) { return false; }
    bool shouldWaitForDebuggerOnWorkerStart(ExecutionContext*) { return false; }
    bool shouldForceCORSPreflight(Document*) { return false; }
    bool shouldBlockRequest(LocalFrame*, const ResourceRequest&) { return false; }

    bool isDebuggerPaused(LocalFrame*)
    {
        return false;
    }

    void didReceiveResourceResponseButCanceled(LocalFrame* frame, DocumentLoader* loader, unsigned long identifier, const ResourceResponse& r, Resource* resource)
    {
    }

    void continueAfterXFrameOptionsDenied(LocalFrame* frame, DocumentLoader* loader, unsigned long identifier, const ResourceResponse& r, Resource* resource)
    {
    }

    void continueWithPolicyIgnore(LocalFrame* frame, DocumentLoader* loader, unsigned long identifier, const ResourceResponse& r, Resource* resource)
    {
    }

    // JavaScriptDialog::JavaScriptDialog(LocalFrame*, const String& message, ChromeClient::DialogType)
    // {
    //
    // }
    //
    // void JavaScriptDialog::setResult(bool)
    // {
    //
    // }
    //
    // JavaScriptDialog::~JavaScriptDialog()
    // {
    //
    // }
    //
    //
    // StyleRecalc::StyleRecalc(Document*) {}
    // StyleRecalc::~StyleRecalc() {}

#define GEN_instrumentingAgentsFor_FUNC(type)          \
    InstrumentingAgents* instrumentingAgentsFor(type*) \
    {                                                  \
        return nullptr;                                \
    }

#define GEN_instrumentingAgentsForNonDocumentContext_FUNC(type)          \
    InstrumentingAgents* instrumentingAgentsForNonDocumentContext(type*) \
    {                                                                    \
        return nullptr;                                                  \
    }

    //GEN_instrumentingAgentsFor_FUNC(Document)
    GEN_instrumentingAgentsFor_FUNC(Page)
        GEN_instrumentingAgentsForNonDocumentContext_FUNC(ExecutionContext)
        //GEN_instrumentingAgentsFor_FUNC(EventTarget)
        GEN_instrumentingAgentsFor_FUNC(LayoutObject)

        //////////////////////////////////////////////////////////////////////////
        void didClearDocumentOfWindowObject(LocalFrame*)
    {
        ;
    }
    void willInsertDOMNode(Node*) { ; }
    void didInsertDOMNode(Node*) { ; }
    void willRemoveDOMNode(Node*) { ; }
    void willModifyDOMAttr(Element*, const AtomicString&, const AtomicString&) { ; }
    void didModifyDOMAttr(Element*, const QualifiedName&, const AtomicString&) { ; }
    void didRemoveDOMAttr(Element*, const QualifiedName&) { ; }
    void characterDataModified(CharacterData*) { ; }
    void didInvalidateStyleAttr(Node*) { ; }
    void didPerformElementShadowDistribution(Element*) { ; }
    void documentDetached(Document*) { ; }
    void activeStyleSheetsUpdated(Document*) { ; }
    void mediaQueryResultChanged(Document*) { ; }
    void didPushShadowRoot(Element*, ShadowRoot*) { ; }
    void willPopShadowRoot(Element*, ShadowRoot*) { ; }
    void willSendXMLHttpOrFetchNetworkRequest(ExecutionContext*, const String&) { ; }
    void didFireWebGLError(Element*, const String&) { ; }
    void didFireWebGLWarning(Element*) { ; }
    void didFireWebGLErrorOrWarning(Element*, const String&) { ; }
    void didUpdateLayout(LocalFrame*) { ; }
    void didResizeMainFrame(LocalFrame*) { ; }
    void didPaint(LocalFrame*, const GraphicsLayer*, GraphicsContext&, const LayoutRect&) { ; }
    void didScheduleStyleRecalculation(Document*) { ; }
    void applyUserAgentOverride(LocalFrame*, String*) { ; }
    void didBlockRequest(LocalFrame*, const ResourceRequest&, DocumentLoader*, const FetchInitiatorInfo&, ResourceRequestBlockedReason) { ; }
    void didChangeResourcePriority(LocalFrame*, unsigned long, ResourceLoadPriority) { ; }
    void willSendRequest(LocalFrame*, unsigned long, DocumentLoader*, ResourceRequest&, const ResourceResponse&, const FetchInitiatorInfo&) { ; }
    void markResourceAsCached(LocalFrame*, unsigned long) { ; }
    void didReceiveResourceResponse(LocalFrame*, unsigned long, DocumentLoader*, const ResourceResponse&, Resource*) { ; }
    void didReceiveData(LocalFrame*, unsigned long, const char*, int, int) { ; }
    void didFinishLoading(LocalFrame*, unsigned long, double, int64_t) { ; }
    void didReceiveCORSRedirectResponse(LocalFrame*, unsigned long, DocumentLoader*, const ResourceResponse&, Resource*) { ; }
    void didFailLoading(LocalFrame*, unsigned long, const ResourceError&) { ; }
    void documentThreadableLoaderStartedLoadingForClient(ExecutionContext*, unsigned long, ThreadableLoaderClient*) { ; }
    void documentThreadableLoaderFailedToStartLoadingForClient(ExecutionContext*, ThreadableLoaderClient*) { ; }
    void willSendEventSourceRequest(ExecutionContext*, ThreadableLoaderClient*) { ; }
    void willDispatchEventSourceEvent(ExecutionContext*, ThreadableLoaderClient*, const AtomicString&, const AtomicString&, const String&) { ; }
    void didFinishEventSourceRequest(ExecutionContext*, ThreadableLoaderClient*) { ; }
    void willLoadXHR(ExecutionContext*, XMLHttpRequest*, ThreadableLoaderClient*, const AtomicString&, const KURL&, bool, PassRefPtr<EncodedFormData>, const HTTPHeaderMap&, bool) { ; }
    void didFailXHRLoading(ExecutionContext*, XMLHttpRequest*, ThreadableLoaderClient*, const AtomicString&, const String&) { ; }
    void didFinishXHRLoading(ExecutionContext*, XMLHttpRequest*, ThreadableLoaderClient*, const AtomicString&, const String&) { ; }
    void willStartFetch(ExecutionContext*, ThreadableLoaderClient*) { ; }
    void didFailFetch(ExecutionContext*, ThreadableLoaderClient*) { ; }
    void didFinishFetch(ExecutionContext*, ThreadableLoaderClient*, const AtomicString&, const String&) { ; }
    void scriptImported(ExecutionContext*, unsigned long, const String&) { ; }
    void scriptExecutionBlockedByCSP(ExecutionContext*, const String&) { ; }
    void didReceiveScriptResponse(ExecutionContext*, unsigned long) { ; }
    void didStartProvisionalLoad(LocalFrame*) { ; }
    void domContentLoadedEventFired(LocalFrame*) { ; }
    void loadEventFired(LocalFrame*) { ; }
    void frameAttachedToParent(LocalFrame*) { ; }
    void frameDetachedFromParent(LocalFrame*) { ; }
    void didCommitLoad(LocalFrame*, DocumentLoader*) { ; }
    void frameDocumentUpdated(LocalFrame*) { ; }
    void frameStartedLoading(LocalFrame*) { ; }
    void frameStoppedLoading(LocalFrame*) { ; }
    void frameScheduledNavigation(LocalFrame*, double) { ; }
    void frameClearedScheduledNavigation(LocalFrame*) { ; }
    void didStartWorker(ExecutionContext*, WorkerInspectorProxy*, bool) { ; }
    void workerTerminated(ExecutionContext*, WorkerInspectorProxy*) { ; }
    void didCreateWebSocket(Document*, unsigned long, const KURL&, const String&) { ; }
    void willSendWebSocketHandshakeRequest(Document*, unsigned long, const WebSocketHandshakeRequest*) { ; }
    void didReceiveWebSocketHandshakeResponse(Document*, unsigned long, const WebSocketHandshakeRequest*, const WebSocketHandshakeResponse*) { ; }
    void didCloseWebSocket(Document*, unsigned long) { ; }
    void didReceiveWebSocketFrame(Document*, unsigned long, int, bool, const char*, size_t) { ; }
    void didSendWebSocketFrame(Document*, unsigned long, int, bool, const char*, size_t) { ; }
    void didReceiveWebSocketFrameError(Document*, unsigned long, const String&) { ; }
    void networkStateChanged(LocalFrame*, bool) { ; }
    void updateApplicationCacheStatus(LocalFrame*) { ; }
    void layerTreeDidChange(LocalFrame*) { ; }
    void pseudoElementCreated(PseudoElement*) { ; }
    void pseudoElementDestroyed(PseudoElement*) { ; }
    void didCreateAnimation(Document*, unsigned) { ; }
    void animationPlayStateChanged(Document*, Animation*, Animation::AnimationPlayState, Animation::AnimationPlayState) { ; }
    void windowCreated(LocalFrame*, LocalFrame*) { ; }
    void willRecalculateStyle(Document*) { ; }
    void didRecalculateStyle(Document*) { ; }

    //int FrontendCounter::s_frontendCounter = 0;

} // InspectorInstrumentation

} // namespace blink