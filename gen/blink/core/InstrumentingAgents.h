// Code generated from InspectorInstrumentation.idl

#ifndef InstrumentingAgents_h
#define InstrumentingAgents_h

#include "core/CoreExport.h"
#include "platform/heap/Handle.h"
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"
#include "wtf/PassRefPtr.h"

namespace blink {

class InspectorAnimationAgent;
class InspectorApplicationCacheAgent;
class InspectorCSSAgent;
class InspectorDOMAgent;
class InspectorDOMDebuggerAgent;
class InspectorLayerTreeAgent;
class InspectorLogAgent;
class InspectorNetworkAgent;
class InspectorPageAgent;
class InspectorTracingAgent;
class InspectorWorkerAgent;

class CORE_EXPORT InstrumentingAgents : public GarbageCollected<InstrumentingAgents> {
    WTF_MAKE_NONCOPYABLE(InstrumentingAgents);

public:
    InstrumentingAgents();
    DECLARE_TRACE();

    bool hasInspectorAnimationAgents() const { return m_hasInspectorAnimationAgents; }
    const HeapHashSet<Member<InspectorAnimationAgent>>& inspectorAnimationAgents() const { return m_inspectorAnimationAgents; }
    void addInspectorAnimationAgent(InspectorAnimationAgent* agent);
    void removeInspectorAnimationAgent(InspectorAnimationAgent* agent);

    bool hasInspectorApplicationCacheAgents() const { return m_hasInspectorApplicationCacheAgents; }
    const HeapHashSet<Member<InspectorApplicationCacheAgent>>& inspectorApplicationCacheAgents() const { return m_inspectorApplicationCacheAgents; }
    void addInspectorApplicationCacheAgent(InspectorApplicationCacheAgent* agent);
    void removeInspectorApplicationCacheAgent(InspectorApplicationCacheAgent* agent);

    bool hasInspectorCSSAgents() const { return m_hasInspectorCSSAgents; }
    const HeapHashSet<Member<InspectorCSSAgent>>& inspectorCSSAgents() const { return m_inspectorCSSAgents; }
    void addInspectorCSSAgent(InspectorCSSAgent* agent);
    void removeInspectorCSSAgent(InspectorCSSAgent* agent);

    bool hasInspectorDOMAgents() const { return m_hasInspectorDOMAgents; }
    const HeapHashSet<Member<InspectorDOMAgent>>& inspectorDOMAgents() const { return m_inspectorDOMAgents; }
    void addInspectorDOMAgent(InspectorDOMAgent* agent);
    void removeInspectorDOMAgent(InspectorDOMAgent* agent);

    bool hasInspectorDOMDebuggerAgents() const { return m_hasInspectorDOMDebuggerAgents; }
    const HeapHashSet<Member<InspectorDOMDebuggerAgent>>& inspectorDOMDebuggerAgents() const { return m_inspectorDOMDebuggerAgents; }
    void addInspectorDOMDebuggerAgent(InspectorDOMDebuggerAgent* agent);
    void removeInspectorDOMDebuggerAgent(InspectorDOMDebuggerAgent* agent);

    bool hasInspectorLayerTreeAgents() const { return m_hasInspectorLayerTreeAgents; }
    const HeapHashSet<Member<InspectorLayerTreeAgent>>& inspectorLayerTreeAgents() const { return m_inspectorLayerTreeAgents; }
    void addInspectorLayerTreeAgent(InspectorLayerTreeAgent* agent);
    void removeInspectorLayerTreeAgent(InspectorLayerTreeAgent* agent);

    bool hasInspectorLogAgents() const { return m_hasInspectorLogAgents; }
    const HeapHashSet<Member<InspectorLogAgent>>& inspectorLogAgents() const { return m_inspectorLogAgents; }
    void addInspectorLogAgent(InspectorLogAgent* agent);
    void removeInspectorLogAgent(InspectorLogAgent* agent);

    bool hasInspectorNetworkAgents() const { return m_hasInspectorNetworkAgents; }
    const HeapHashSet<Member<InspectorNetworkAgent>>& inspectorNetworkAgents() const { return m_inspectorNetworkAgents; }
    void addInspectorNetworkAgent(InspectorNetworkAgent* agent);
    void removeInspectorNetworkAgent(InspectorNetworkAgent* agent);

    bool hasInspectorPageAgents() const { return m_hasInspectorPageAgents; }
    const HeapHashSet<Member<InspectorPageAgent>>& inspectorPageAgents() const { return m_inspectorPageAgents; }
    void addInspectorPageAgent(InspectorPageAgent* agent);
    void removeInspectorPageAgent(InspectorPageAgent* agent);

    bool hasInspectorTracingAgents() const { return m_hasInspectorTracingAgents; }
    const HeapHashSet<Member<InspectorTracingAgent>>& inspectorTracingAgents() const { return m_inspectorTracingAgents; }
    void addInspectorTracingAgent(InspectorTracingAgent* agent);
    void removeInspectorTracingAgent(InspectorTracingAgent* agent);

    bool hasInspectorWorkerAgents() const { return m_hasInspectorWorkerAgents; }
    const HeapHashSet<Member<InspectorWorkerAgent>>& inspectorWorkerAgents() const { return m_inspectorWorkerAgents; }
    void addInspectorWorkerAgent(InspectorWorkerAgent* agent);
    void removeInspectorWorkerAgent(InspectorWorkerAgent* agent);

private:
    HeapHashSet<Member<InspectorAnimationAgent>> m_inspectorAnimationAgents;
    bool m_hasInspectorAnimationAgents;
    HeapHashSet<Member<InspectorApplicationCacheAgent>> m_inspectorApplicationCacheAgents;
    bool m_hasInspectorApplicationCacheAgents;
    HeapHashSet<Member<InspectorCSSAgent>> m_inspectorCSSAgents;
    bool m_hasInspectorCSSAgents;
    HeapHashSet<Member<InspectorDOMAgent>> m_inspectorDOMAgents;
    bool m_hasInspectorDOMAgents;
    HeapHashSet<Member<InspectorDOMDebuggerAgent>> m_inspectorDOMDebuggerAgents;
    bool m_hasInspectorDOMDebuggerAgents;
    HeapHashSet<Member<InspectorLayerTreeAgent>> m_inspectorLayerTreeAgents;
    bool m_hasInspectorLayerTreeAgents;
    HeapHashSet<Member<InspectorLogAgent>> m_inspectorLogAgents;
    bool m_hasInspectorLogAgents;
    HeapHashSet<Member<InspectorNetworkAgent>> m_inspectorNetworkAgents;
    bool m_hasInspectorNetworkAgents;
    HeapHashSet<Member<InspectorPageAgent>> m_inspectorPageAgents;
    bool m_hasInspectorPageAgents;
    HeapHashSet<Member<InspectorTracingAgent>> m_inspectorTracingAgents;
    bool m_hasInspectorTracingAgents;
    HeapHashSet<Member<InspectorWorkerAgent>> m_inspectorWorkerAgents;
    bool m_hasInspectorWorkerAgents;
};

}

#endif // !defined(InstrumentingAgents_h)
