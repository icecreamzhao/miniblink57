// Code generated from InspectorInstrumentation.idl

#include "InspectorInstrumentationInl.h"
#include "InspectorOverridesInl.h"
#include "InstrumentingAgents.h"
#include "core/CoreExport.h"
#include "core/inspector/InspectorAnimationAgent.h"
#include "core/inspector/InspectorApplicationCacheAgent.h"
#include "core/inspector/InspectorCSSAgent.h"
#include "core/inspector/InspectorDOMAgent.h"
#include "core/inspector/InspectorDOMDebuggerAgent.h"
#include "core/inspector/InspectorLayerTreeAgent.h"
#include "core/inspector/InspectorLogAgent.h"
#include "core/inspector/InspectorNetworkAgent.h"
#include "core/inspector/InspectorPageAgent.h"
#include "core/inspector/InspectorTracingAgent.h"
#include "core/inspector/InspectorWorkerAgent.h"

namespace blink {

InstrumentingAgents::InstrumentingAgents()
    : m_hasInspectorAnimationAgents(false)
    , m_hasInspectorApplicationCacheAgents(false)
    , m_hasInspectorCSSAgents(false)
    , m_hasInspectorDOMAgents(false)
    , m_hasInspectorDOMDebuggerAgents(false)
    , m_hasInspectorLayerTreeAgents(false)
    , m_hasInspectorLogAgents(false)
    , m_hasInspectorNetworkAgents(false)
    , m_hasInspectorPageAgents(false)
    , m_hasInspectorTracingAgents(false)
    , m_hasInspectorWorkerAgents(false)
{
}

void InstrumentingAgents::addInspectorAnimationAgent(InspectorAnimationAgent* agent)
{
    m_inspectorAnimationAgents.add(agent);
    m_hasInspectorAnimationAgents = true;
}

void InstrumentingAgents::removeInspectorAnimationAgent(InspectorAnimationAgent* agent)
{
    m_inspectorAnimationAgents.remove(agent);
    m_hasInspectorAnimationAgents = !m_inspectorAnimationAgents.isEmpty();
}

void InstrumentingAgents::addInspectorApplicationCacheAgent(InspectorApplicationCacheAgent* agent)
{
    m_inspectorApplicationCacheAgents.add(agent);
    m_hasInspectorApplicationCacheAgents = true;
}

void InstrumentingAgents::removeInspectorApplicationCacheAgent(InspectorApplicationCacheAgent* agent)
{
    m_inspectorApplicationCacheAgents.remove(agent);
    m_hasInspectorApplicationCacheAgents = !m_inspectorApplicationCacheAgents.isEmpty();
}

void InstrumentingAgents::addInspectorCSSAgent(InspectorCSSAgent* agent)
{
    m_inspectorCSSAgents.add(agent);
    m_hasInspectorCSSAgents = true;
}

void InstrumentingAgents::removeInspectorCSSAgent(InspectorCSSAgent* agent)
{
    m_inspectorCSSAgents.remove(agent);
    m_hasInspectorCSSAgents = !m_inspectorCSSAgents.isEmpty();
}

void InstrumentingAgents::addInspectorDOMAgent(InspectorDOMAgent* agent)
{
    m_inspectorDOMAgents.add(agent);
    m_hasInspectorDOMAgents = true;
}

void InstrumentingAgents::removeInspectorDOMAgent(InspectorDOMAgent* agent)
{
    m_inspectorDOMAgents.remove(agent);
    m_hasInspectorDOMAgents = !m_inspectorDOMAgents.isEmpty();
}

void InstrumentingAgents::addInspectorDOMDebuggerAgent(InspectorDOMDebuggerAgent* agent)
{
    m_inspectorDOMDebuggerAgents.add(agent);
    m_hasInspectorDOMDebuggerAgents = true;
}

void InstrumentingAgents::removeInspectorDOMDebuggerAgent(InspectorDOMDebuggerAgent* agent)
{
    m_inspectorDOMDebuggerAgents.remove(agent);
    m_hasInspectorDOMDebuggerAgents = !m_inspectorDOMDebuggerAgents.isEmpty();
}

void InstrumentingAgents::addInspectorLayerTreeAgent(InspectorLayerTreeAgent* agent)
{
    m_inspectorLayerTreeAgents.add(agent);
    m_hasInspectorLayerTreeAgents = true;
}

void InstrumentingAgents::removeInspectorLayerTreeAgent(InspectorLayerTreeAgent* agent)
{
    m_inspectorLayerTreeAgents.remove(agent);
    m_hasInspectorLayerTreeAgents = !m_inspectorLayerTreeAgents.isEmpty();
}

void InstrumentingAgents::addInspectorLogAgent(InspectorLogAgent* agent)
{
    m_inspectorLogAgents.add(agent);
    m_hasInspectorLogAgents = true;
}

void InstrumentingAgents::removeInspectorLogAgent(InspectorLogAgent* agent)
{
    m_inspectorLogAgents.remove(agent);
    m_hasInspectorLogAgents = !m_inspectorLogAgents.isEmpty();
}

void InstrumentingAgents::addInspectorNetworkAgent(InspectorNetworkAgent* agent)
{
    m_inspectorNetworkAgents.add(agent);
    m_hasInspectorNetworkAgents = true;
}

void InstrumentingAgents::removeInspectorNetworkAgent(InspectorNetworkAgent* agent)
{
    m_inspectorNetworkAgents.remove(agent);
    m_hasInspectorNetworkAgents = !m_inspectorNetworkAgents.isEmpty();
}

void InstrumentingAgents::addInspectorPageAgent(InspectorPageAgent* agent)
{
    m_inspectorPageAgents.add(agent);
    m_hasInspectorPageAgents = true;
}

void InstrumentingAgents::removeInspectorPageAgent(InspectorPageAgent* agent)
{
    m_inspectorPageAgents.remove(agent);
    m_hasInspectorPageAgents = !m_inspectorPageAgents.isEmpty();
}

void InstrumentingAgents::addInspectorTracingAgent(InspectorTracingAgent* agent)
{
    m_inspectorTracingAgents.add(agent);
    m_hasInspectorTracingAgents = true;
}

void InstrumentingAgents::removeInspectorTracingAgent(InspectorTracingAgent* agent)
{
    m_inspectorTracingAgents.remove(agent);
    m_hasInspectorTracingAgents = !m_inspectorTracingAgents.isEmpty();
}

void InstrumentingAgents::addInspectorWorkerAgent(InspectorWorkerAgent* agent)
{
    m_inspectorWorkerAgents.add(agent);
    m_hasInspectorWorkerAgents = true;
}

void InstrumentingAgents::removeInspectorWorkerAgent(InspectorWorkerAgent* agent)
{
    m_inspectorWorkerAgents.remove(agent);
    m_hasInspectorWorkerAgents = !m_inspectorWorkerAgents.isEmpty();
}

DEFINE_TRACE(InstrumentingAgents)
{
    visitor->trace(m_inspectorAnimationAgents);
    visitor->trace(m_inspectorApplicationCacheAgents);
    visitor->trace(m_inspectorCSSAgents);
    visitor->trace(m_inspectorDOMAgents);
    visitor->trace(m_inspectorDOMDebuggerAgents);
    visitor->trace(m_inspectorLayerTreeAgents);
    visitor->trace(m_inspectorLogAgents);
    visitor->trace(m_inspectorNetworkAgents);
    visitor->trace(m_inspectorPageAgents);
    visitor->trace(m_inspectorTracingAgents);
    visitor->trace(m_inspectorWorkerAgents);
}

namespace InspectorInstrumentation {

    void didClearDocumentOfWindowObject(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->didClearDocumentOfWindowObject(paramLocalFrame);
        }
        if (agents->hasInspectorAnimationAgents()) {
            for (InspectorAnimationAgent* agent : agents->inspectorAnimationAgents())
                agent->didClearDocumentOfWindowObject(paramLocalFrame);
        }
    }

    void willInsertDOMNode(Node* parent)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(parent);
        if (!agents)
            return;
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->willInsertDOMNode(parent);
        }
    }

    void didInsertDOMNode(Node* paramNode)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramNode);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->didInsertDOMNode(paramNode);
        }
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->didInsertDOMNode(paramNode);
        }
    }

    void willRemoveDOMNode(Node* paramNode)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramNode);
        if (!agents)
            return;
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->willRemoveDOMNode(paramNode);
        }
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->willRemoveDOMNode(paramNode);
        }
    }

    void willModifyDOMAttr(Element* paramElement, const AtomicString& oldValue, const AtomicString& newValue)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->willModifyDOMAttr(paramElement, oldValue, newValue);
        }
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->willModifyDOMAttr(paramElement, oldValue, newValue);
        }
    }

    void didModifyDOMAttr(Element* paramElement, const QualifiedName& name, const AtomicString& value)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->didModifyDOMAttr(paramElement, name, value);
        }
    }

    void didRemoveDOMAttr(Element* paramElement, const QualifiedName& name)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->didRemoveDOMAttr(paramElement, name);
        }
    }

    void characterDataModified(CharacterData* paramCharacterData)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramCharacterData);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->characterDataModified(paramCharacterData);
        }
    }

    void didInvalidateStyleAttr(Node* paramNode)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramNode);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->didInvalidateStyleAttr(paramNode);
        }
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->didInvalidateStyleAttr(paramNode);
        }
    }

    void didPerformElementShadowDistribution(Element* paramElement)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->didPerformElementShadowDistribution(paramElement);
        }
    }

    void didPerformSlotDistribution(HTMLSlotElement* paramHTMLSlotElement)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramHTMLSlotElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->didPerformSlotDistribution(paramHTMLSlotElement);
        }
    }

    void documentDetached(Document* paramDocument)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorCSSAgents()) {
            for (InspectorCSSAgent* agent : agents->inspectorCSSAgents())
                agent->documentDetached(paramDocument);
        }
    }

    void activeStyleSheetsUpdated(Document* paramDocument)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorCSSAgents()) {
            for (InspectorCSSAgent* agent : agents->inspectorCSSAgents())
                agent->activeStyleSheetsUpdated(paramDocument);
        }
    }

    void fontsUpdated(Document* paramDocument)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorCSSAgents()) {
            for (InspectorCSSAgent* agent : agents->inspectorCSSAgents())
                agent->fontsUpdated();
        }
    }

    void mediaQueryResultChanged(Document* paramDocument)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorCSSAgents()) {
            for (InspectorCSSAgent* agent : agents->inspectorCSSAgents())
                agent->mediaQueryResultChanged();
        }
    }

    void didPushShadowRoot(Element* host, ShadowRoot* paramShadowRoot)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(host);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->didPushShadowRoot(host, paramShadowRoot);
        }
    }

    void willPopShadowRoot(Element* host, ShadowRoot* paramShadowRoot)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(host);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->willPopShadowRoot(host, paramShadowRoot);
        }
    }

    void willSendXMLHttpOrFetchNetworkRequest(ExecutionContext* paramExecutionContext, const String& url)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->willSendXMLHttpOrFetchNetworkRequest(url);
        }
    }

    void didFireWebGLError(Element* paramElement, const String& errorName)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->didFireWebGLError(errorName);
        }
    }

    void didFireWebGLWarning(Element* paramElement)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->didFireWebGLWarning();
        }
    }

    void didFireWebGLErrorOrWarning(Element* paramElement, const String& message)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->didFireWebGLErrorOrWarning(message);
        }
    }

    void didUpdateLayout(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->didUpdateLayout();
        }
    }

    void didResizeMainFrame(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->didResizeMainFrame();
        }
    }

    void didPaint(LocalFrame* paramLocalFrame, const GraphicsLayer* paramGraphicsLayer, GraphicsContext& paramGraphicsContext, const LayoutRect& paramLayoutRect)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorLayerTreeAgents()) {
            for (InspectorLayerTreeAgent* agent : agents->inspectorLayerTreeAgents())
                agent->didPaint(paramGraphicsLayer, paramGraphicsContext, paramLayoutRect);
        }
    }

    void didScheduleStyleRecalculation(Document* paramDocument)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didScheduleStyleRecalculation(paramDocument);
        }
    }

    void applyUserAgentOverride(LocalFrame* paramLocalFrame, String* userAgent)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->applyUserAgentOverride(userAgent);
        }
    }

    void didBlockRequest(LocalFrame* paramLocalFrame, const ResourceRequest& paramResourceRequest, DocumentLoader* paramDocumentLoader, const FetchInitiatorInfo& paramFetchInitiatorInfo, ResourceRequestBlockedReason paramResourceRequestBlockedReason)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didBlockRequest(paramLocalFrame, paramResourceRequest, paramDocumentLoader, paramFetchInitiatorInfo, paramResourceRequestBlockedReason);
        }
    }

    void didChangeResourcePriority(LocalFrame* paramLocalFrame, unsigned long identifier, ResourceLoadPriority loadPriority)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didChangeResourcePriority(identifier, loadPriority);
        }
    }

    void willSendRequest(LocalFrame* paramLocalFrame, unsigned long identifier, DocumentLoader* paramDocumentLoader, ResourceRequest& paramResourceRequest, const ResourceResponse& redirectResponse, const FetchInitiatorInfo& paramFetchInitiatorInfo)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->willSendRequest(paramLocalFrame, identifier, paramDocumentLoader, paramResourceRequest, redirectResponse, paramFetchInitiatorInfo);
        }
    }

    void markResourceAsCached(LocalFrame* paramLocalFrame, unsigned long identifier)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->markResourceAsCached(identifier);
        }
    }

    void didReceiveResourceResponse(LocalFrame* paramLocalFrame, unsigned long identifier, DocumentLoader* paramDocumentLoader, const ResourceResponse& paramResourceResponse, Resource* paramResource)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didReceiveResourceResponse(paramLocalFrame, identifier, paramDocumentLoader, paramResourceResponse, paramResource);
        }
    }

    void didReceiveData(LocalFrame* paramLocalFrame, unsigned long identifier, const char* data, int dataLength)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didReceiveData(paramLocalFrame, identifier, data, dataLength);
        }
    }

    void didReceiveEncodedDataLength(LocalFrame* paramLocalFrame, unsigned long identifier, int encodedDataLength)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didReceiveEncodedDataLength(paramLocalFrame, identifier, encodedDataLength);
        }
    }

    void didFinishLoading(LocalFrame* frame, unsigned long identifier, double finishTime, int64_t encodedDataLength)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(frame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didFinishLoading(identifier, finishTime, encodedDataLength);
        }
    }

    void didReceiveCORSRedirectResponse(LocalFrame* paramLocalFrame, unsigned long identifier, DocumentLoader* paramDocumentLoader, const ResourceResponse& paramResourceResponse, Resource* paramResource)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didReceiveCORSRedirectResponse(paramLocalFrame, identifier, paramDocumentLoader, paramResourceResponse, paramResource);
        }
    }

    void didFailLoading(LocalFrame* frame, unsigned long identifier, const ResourceError& paramResourceError)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(frame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didFailLoading(identifier, paramResourceError);
        }
    }

    void documentThreadableLoaderStartedLoadingForClient(ExecutionContext* paramExecutionContext, unsigned long identifier, ThreadableLoaderClient* client)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->documentThreadableLoaderStartedLoadingForClient(identifier, client);
        }
    }

    void documentThreadableLoaderFailedToStartLoadingForClient(ExecutionContext* paramExecutionContext, ThreadableLoaderClient* client)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->documentThreadableLoaderFailedToStartLoadingForClient(client);
        }
    }

    void willSendEventSourceRequest(ExecutionContext* paramExecutionContext, ThreadableLoaderClient* eventSource)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->willSendEventSourceRequest(eventSource);
        }
    }

    void willDispatchEventSourceEvent(ExecutionContext* paramExecutionContext, ThreadableLoaderClient* eventSource, const AtomicString& eventName, const AtomicString& eventId, const String& data)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->willDispatchEventSourceEvent(eventSource, eventName, eventId, data);
        }
    }

    void didFinishEventSourceRequest(ExecutionContext* paramExecutionContext, ThreadableLoaderClient* eventSource)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didFinishEventSourceRequest(eventSource);
        }
    }

    void willLoadXHR(ExecutionContext* paramExecutionContext, XMLHttpRequest* xhr, ThreadableLoaderClient* client, const AtomicString& method, const KURL& url, bool async, PassRefPtr<EncodedFormData> prpParamEncodedFormData, const HTTPHeaderMap& headers, bool includeCredentials)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        RefPtr<EncodedFormData> paramEncodedFormData = prpParamEncodedFormData;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->willLoadXHR(xhr, client, method, url, async, paramEncodedFormData, headers, includeCredentials);
        }
    }

    void didFailXHRLoading(ExecutionContext* paramExecutionContext, XMLHttpRequest* xhr, ThreadableLoaderClient* client, const AtomicString& method, const String& url)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didFailXHRLoading(paramExecutionContext, xhr, client, method, url);
        }
    }

    void didFinishXHRLoading(ExecutionContext* paramExecutionContext, XMLHttpRequest* xhr, ThreadableLoaderClient* client, const AtomicString& method, const String& url)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didFinishXHRLoading(paramExecutionContext, xhr, client, method, url);
        }
    }

    void willStartFetch(ExecutionContext* paramExecutionContext, ThreadableLoaderClient* paramThreadableLoaderClient)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->willStartFetch(paramThreadableLoaderClient);
        }
    }

    void didFailFetch(ExecutionContext* paramExecutionContext, ThreadableLoaderClient* paramThreadableLoaderClient)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didFailFetch(paramThreadableLoaderClient);
        }
    }

    void didFinishFetch(ExecutionContext* paramExecutionContext, ThreadableLoaderClient* paramThreadableLoaderClient, const AtomicString& method, const String& url)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didFinishFetch(paramExecutionContext, paramThreadableLoaderClient, method, url);
        }
    }

    void scriptImported(ExecutionContext* paramExecutionContext, unsigned long identifier, const String& sourceString)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->scriptImported(identifier, sourceString);
        }
    }

    void scriptExecutionBlockedByCSP(ExecutionContext* paramExecutionContext, const String& directiveText)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorDOMDebuggerAgents()) {
            for (InspectorDOMDebuggerAgent* agent : agents->inspectorDOMDebuggerAgents())
                agent->scriptExecutionBlockedByCSP(directiveText);
        }
    }

    void didReceiveScriptResponse(ExecutionContext* paramExecutionContext, unsigned long identifier)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didReceiveScriptResponse(identifier);
        }
    }

    void domContentLoadedEventFired(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->domContentLoadedEventFired(paramLocalFrame);
        }
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->domContentLoadedEventFired(paramLocalFrame);
        }
    }

    void loadEventFired(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->loadEventFired(paramLocalFrame);
        }
    }

    void frameAttachedToParent(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->frameAttachedToParent(paramLocalFrame);
        }
    }

    void frameDetachedFromParent(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->frameDetachedFromParent(paramLocalFrame);
        }
    }

    void didCommitLoad(LocalFrame* paramLocalFrame, DocumentLoader* paramDocumentLoader)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didCommitLoad(paramLocalFrame, paramDocumentLoader);
        }
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->didCommitLoad(paramLocalFrame, paramDocumentLoader);
        }
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->didCommitLoad(paramLocalFrame, paramDocumentLoader);
        }
    }

    void frameDocumentUpdated(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->frameDocumentUpdated(paramLocalFrame);
        }
    }

    void frameStartedLoading(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->frameStartedLoading(paramLocalFrame);
        }
        if (agents->hasInspectorTracingAgents()) {
            for (InspectorTracingAgent* agent : agents->inspectorTracingAgents())
                agent->frameStartedLoading(paramLocalFrame);
        }
    }

    void frameStoppedLoading(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->frameStoppedLoading(paramLocalFrame);
        }
        if (agents->hasInspectorTracingAgents()) {
            for (InspectorTracingAgent* agent : agents->inspectorTracingAgents())
                agent->frameStoppedLoading(paramLocalFrame);
        }
    }

    void frameScheduledNavigation(LocalFrame* paramLocalFrame, double delay)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->frameScheduledNavigation(paramLocalFrame, delay);
        }
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->frameScheduledNavigation(paramLocalFrame, delay);
        }
    }

    void frameClearedScheduledNavigation(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->frameClearedScheduledNavigation(paramLocalFrame);
        }
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->frameClearedScheduledNavigation(paramLocalFrame);
        }
    }

    void didStartWorker(ExecutionContext* paramExecutionContext, WorkerInspectorProxy* proxy, bool waitingForDebugger)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorWorkerAgents()) {
            for (InspectorWorkerAgent* agent : agents->inspectorWorkerAgents())
                agent->didStartWorker(proxy, waitingForDebugger);
        }
    }

    void workerTerminated(ExecutionContext* paramExecutionContext, WorkerInspectorProxy* proxy)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorWorkerAgents()) {
            for (InspectorWorkerAgent* agent : agents->inspectorWorkerAgents())
                agent->workerTerminated(proxy);
        }
    }

    void didCreateWebSocket(Document* paramDocument, unsigned long identifier, const KURL& requestURL, const String& protocol)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didCreateWebSocket(paramDocument, identifier, requestURL, protocol);
        }
    }

    void willSendWebSocketHandshakeRequest(Document* paramDocument, unsigned long identifier, const WebSocketHandshakeRequest* request)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->willSendWebSocketHandshakeRequest(paramDocument, identifier, request);
        }
    }

    void didReceiveWebSocketHandshakeResponse(Document* paramDocument, unsigned long identifier, const WebSocketHandshakeRequest* request, const WebSocketHandshakeResponse* response)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didReceiveWebSocketHandshakeResponse(paramDocument, identifier, request, response);
        }
    }

    void didCloseWebSocket(Document* paramDocument, unsigned long identifier)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didCloseWebSocket(paramDocument, identifier);
        }
    }

    void didReceiveWebSocketFrame(Document* paramDocument, unsigned long identifier, int opCode, bool masked, const char* payload, size_t payloadLength)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didReceiveWebSocketFrame(identifier, opCode, masked, payload, payloadLength);
        }
    }

    void didSendWebSocketFrame(Document* paramDocument, unsigned long identifier, int opCode, bool masked, const char* payload, size_t payloadLength)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didSendWebSocketFrame(identifier, opCode, masked, payload, payloadLength);
        }
    }

    void didReceiveWebSocketFrameError(Document* paramDocument, unsigned long identifier, const String& errorMessage)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didReceiveWebSocketFrameError(identifier, errorMessage);
        }
    }

    void networkStateChanged(LocalFrame* paramLocalFrame, bool online)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorApplicationCacheAgents()) {
            for (InspectorApplicationCacheAgent* agent : agents->inspectorApplicationCacheAgents())
                agent->networkStateChanged(paramLocalFrame, online);
        }
    }

    void updateApplicationCacheStatus(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorApplicationCacheAgents()) {
            for (InspectorApplicationCacheAgent* agent : agents->inspectorApplicationCacheAgents())
                agent->updateApplicationCacheStatus(paramLocalFrame);
        }
    }

    void layerTreeDidChange(LocalFrame* paramLocalFrame)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return;
        if (agents->hasInspectorLayerTreeAgents()) {
            for (InspectorLayerTreeAgent* agent : agents->inspectorLayerTreeAgents())
                agent->layerTreeDidChange();
        }
    }

    void pseudoElementCreated(PseudoElement* paramPseudoElement)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramPseudoElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->pseudoElementCreated(paramPseudoElement);
        }
    }

    void pseudoElementDestroyed(PseudoElement* paramPseudoElement)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramPseudoElement);
        if (!agents)
            return;
        if (agents->hasInspectorDOMAgents()) {
            for (InspectorDOMAgent* agent : agents->inspectorDOMAgents())
                agent->pseudoElementDestroyed(paramPseudoElement);
        }
    }

    void didCreateAnimation(Document* paramDocument, unsigned paramunsigned)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorAnimationAgents()) {
            for (InspectorAnimationAgent* agent : agents->inspectorAnimationAgents())
                agent->didCreateAnimation(paramunsigned);
        }
    }

    void animationPlayStateChanged(Document* paramDocument, Animation* paramAnimation, Animation::AnimationPlayState oldPlayState, Animation::AnimationPlayState newPlayState)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorAnimationAgents()) {
            for (InspectorAnimationAgent* agent : agents->inspectorAnimationAgents())
                agent->animationPlayStateChanged(paramAnimation, oldPlayState, newPlayState);
        }
    }

    void windowCreated(LocalFrame* opener, LocalFrame* created)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(opener);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->windowCreated(created);
        }
    }

    void consoleMessageAdded(ExecutionContext* paramExecutionContext, ConsoleMessage* paramConsoleMessage)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramExecutionContext);
        if (!agents)
            return;
        if (agents->hasInspectorLogAgents()) {
            for (InspectorLogAgent* agent : agents->inspectorLogAgents())
                agent->consoleMessageAdded(paramConsoleMessage);
        }
    }

    void willRecalculateStyle(Document* paramDocument)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->willRecalculateStyle(paramDocument);
        }
    }

    void didRecalculateStyle(Document* paramDocument)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->didRecalculateStyle();
        }
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                agent->didRecalculateStyle();
        }
    }

    void willRunJavaScriptDialog(LocalFrame* frame, const String& message, ChromeClient::DialogType dialogType)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(frame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->willRunJavaScriptDialog(message, dialogType);
        }
    }

    void didRunJavaScriptDialog(LocalFrame* frame, bool result)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(frame);
        if (!agents)
            return;
        if (agents->hasInspectorPageAgents()) {
            for (InspectorPageAgent* agent : agents->inspectorPageAgents())
                agent->didRunJavaScriptDialog(result);
        }
    }

    bool forcePseudoState(Element* element, CSSSelector::PseudoType pseudoState)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(element);
        if (!agents)
            return false;
        if (agents->hasInspectorCSSAgents()) {
            for (InspectorCSSAgent* agent : agents->inspectorCSSAgents())
                return agent->forcePseudoState(element, pseudoState);
        }
        return false;
    }

    bool shouldWaitForDebuggerOnWorkerStart(ExecutionContext* context)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(context);
        if (!agents)
            return false;
        if (agents->hasInspectorWorkerAgents()) {
            for (InspectorWorkerAgent* agent : agents->inspectorWorkerAgents())
                return agent->shouldWaitForDebuggerOnWorkerStart();
        }
        return false;
    }

    bool shouldForceCORSPreflight(Document* paramDocument)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramDocument);
        if (!agents)
            return false;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                return agent->shouldForceCORSPreflight();
        }
        return false;
    }

    bool shouldBlockRequest(LocalFrame* paramLocalFrame, const ResourceRequest& paramResourceRequest)
    {
        InstrumentingAgents* agents = instrumentingAgentsFor(paramLocalFrame);
        if (!agents)
            return false;
        if (agents->hasInspectorNetworkAgents()) {
            for (InspectorNetworkAgent* agent : agents->inspectorNetworkAgents())
                return agent->shouldBlockRequest(paramResourceRequest);
        }
        return false;
    }

} // namespace InspectorInstrumentation

} // namespace blink
