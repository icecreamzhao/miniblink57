// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "bindings/core/v8/ScriptWrappableVisitor.h"

#include "bindings/core/v8/ActiveScriptWrappable.h"
#include "bindings/core/v8/DOMWrapperWorld.h"
#include "bindings/core/v8/ScopedPersistent.h"
#include "bindings/core/v8/ScriptWrappableVisitorVerifier.h"
#include "bindings/core/v8/V8AbstractEventListener.h"
#include "bindings/core/v8/WrapperTypeInfo.h"
#include "core/dom/DocumentStyleSheetCollection.h"
#include "core/dom/ElementRareData.h"
#include "core/dom/NodeListsNodeData.h"
#include "core/dom/NodeRareData.h"
#include "core/dom/StyleEngine.h"
#include "core/dom/shadow/ElementShadow.h"
#include "core/html/imports/HTMLImportsController.h"
#include "platform/heap/HeapCompact.h"
#include "platform/heap/HeapPage.h"
#include "public/platform/Platform.h"
#include "public/platform/WebScheduler.h"
#include "wtf/AutoReset.h"

namespace blink {

ScriptWrappableVisitor::ScriptWrappableVisitor(v8::Isolate* isolate)
    //: Visitor(/*ThreadState**/ThreadState::current(), /*VisitorMarkingMode*/VisitorMarkingMode::GlobalMarking)
    : m_isolate(isolate)
    , m_isTracingDone(false)
{
}

ScriptWrappableVisitor::~ScriptWrappableVisitor() { }

void ScriptWrappableVisitor::TracePrologue(
#if V8_MAJOR_VERSION > 7
    v8::EmbedderHeapTracer::TraceFlags flags
#endif
    )
{
    // This CHECK ensures that wrapper tracing is not started from scopes
    // that forbid GC execution, e.g., constructors.
    CHECK(ThreadState::current());
    CHECK(!ThreadState::current()->isWrapperTracingForbidden());
    performCleanup();

    CHECK(!m_tracingInProgress);
    CHECK(!m_shouldCleanup);
    CHECK(m_headersToUnmark.isEmpty());
    CHECK(m_markingDeque.isEmpty());
    CHECK(m_verifierDeque.isEmpty());
    m_tracingInProgress = true;
    m_isTracingDone = false;
}

void ScriptWrappableVisitor::EnterFinalPause(
#if V8_MAJOR_VERSION >= 7
    v8::EmbedderHeapTracer::EmbedderStackState
#endif
    )
{
    CHECK(ThreadState::current());
    CHECK(!ThreadState::current()->isWrapperTracingForbidden());
    ActiveScriptWrappableBase::traceActiveScriptWrappables(m_isolate, this);
}

void ScriptWrappableVisitor::TraceEpilogue(
#if V8_MAJOR_VERSION > 7
    v8::EmbedderHeapTracer::TraceSummary* trace_summary
#endif
)
{
    CHECK(ThreadState::current());
    CHECK(!ThreadState::current()->isWrapperTracingForbidden());
    DCHECK(m_markingDeque.isEmpty());
#if DCHECK_IS_ON()
    ScriptWrappableVisitorVerifier verifier;
    for (auto& markingData : m_verifierDeque) {
        markingData.traceWrappers(&verifier);
    }
#endif

    m_shouldCleanup = true;
    m_tracingInProgress = false;
    scheduleIdleLazyCleanup();
}

void ScriptWrappableVisitor::AbortTracing()
{
    CHECK(ThreadState::current());
    m_shouldCleanup = true;
    m_tracingInProgress = false;
    performCleanup();
}

size_t ScriptWrappableVisitor::NumberOfWrappersToTrace()
{
    CHECK(ThreadState::current());
    return m_markingDeque.size();
}

#if V8_MAJOR_VERSION >= 7

bool ScriptWrappableVisitor::IsTracingDone(void)
{
    return m_isTracingDone;
}

#endif

void ScriptWrappableVisitor::performCleanup()
{
    if (!m_shouldCleanup)
        return;

    for (auto header : m_headersToUnmark) {
        // Dead objects residing in the marking deque may become invalid due to
        // minor garbage collections and are therefore set to nullptr. We have
        // to skip over such objects.
        if (header)
            header->unmarkWrapperHeader();
    }

    m_headersToUnmark.clear();
    m_markingDeque.clear();
    m_verifierDeque.clear();
    m_shouldCleanup = false;
}

void ScriptWrappableVisitor::scheduleIdleLazyCleanup()
{
    // Some threads (e.g. PPAPI thread) don't have a scheduler.
    if (!Platform::current()->currentThread()->scheduler())
        return;

    if (m_idleCleanupTaskScheduled)
        return;

    Platform::current()->currentThread()->scheduler()->postIdleTask(
        BLINK_FROM_HERE, WTF::bind(&ScriptWrappableVisitor::performLazyCleanup, WTF::unretained(this)));
    m_idleCleanupTaskScheduled = true;
}

void ScriptWrappableVisitor::performLazyCleanup(double deadlineSeconds)
{
    m_idleCleanupTaskScheduled = false;

    if (!m_shouldCleanup)
        return;

    TRACE_EVENT1("blink_gc,devtools.timeline",
        "ScriptWrappableVisitor::performLazyCleanup",
        "idleDeltaInSeconds",
        deadlineSeconds - monotonicallyIncreasingTime());

    const int kDeadlineCheckInterval = 2500;
    int processedWrapperCount = 0;
    for (auto it = m_headersToUnmark.rbegin(); it != m_headersToUnmark.rend();) {
        auto header = *it;
        // Dead objects residing in the marking deque may become invalid due to
        // minor garbage collections and are therefore set to nullptr. We have
        // to skip over such objects.
        if (header)
            header->unmarkWrapperHeader();

        ++it;
        m_headersToUnmark.pop_back();

        processedWrapperCount++;
        if (processedWrapperCount % kDeadlineCheckInterval == 0) {
            if (deadlineSeconds <= monotonicallyIncreasingTime()) {
                scheduleIdleLazyCleanup();
                return;
            }
        }
    }

    // Unmarked all headers.
    CHECK(m_headersToUnmark.isEmpty());
    m_markingDeque.clear();
    m_verifierDeque.clear();
    m_shouldCleanup = false;
}

void ScriptWrappableVisitor::RegisterV8Reference(const std::pair<void*, void*>& internalFields)
{
    if (!m_tracingInProgress)
        return;

    WrapperTypeInfo* wrapperTypeInfo = reinterpret_cast<WrapperTypeInfo*>(internalFields.first);
    if (wrapperTypeInfo->ginEmbedder != gin::GinEmbedder::kEmbedderBlink)
        return;
    
    DCHECK(wrapperTypeInfo->wrapperClassId == WrapperTypeInfo::NodeClassId || wrapperTypeInfo->wrapperClassId == WrapperTypeInfo::ObjectClassId);

    ScriptWrappable* scriptWrappable = reinterpret_cast<ScriptWrappable*>(internalFields.second);
    wrapperTypeInfo->traceWrappers(this, scriptWrappable);
}

void ScriptWrappableVisitor::RegisterV8References(const std::vector<std::pair<void*, void*>>& internalFieldsOfPotentialWrappers)
{
    CHECK(ThreadState::current());
    // TODO(hlopko): Visit the vector in the V8 instead of passing it over if
    // there is no performance impact
    for (auto& pair : internalFieldsOfPotentialWrappers) {
        RegisterV8Reference(pair);
    }
}

bool ScriptWrappableVisitor::AdvanceTracing(double deadlineInMs
#if V8_MAJOR_VERSION < 7
    , v8::EmbedderHeapTracer::AdvanceTracingActions actions
#endif
    )
{
    constexpr int kObjectsBeforeInterrupt = 100;
    // Do not drain the marking deque in a state where we can generally not
    // perform a GC. This makes sure that TraceTraits and friends find
    // themselves in a well-defined environment, e.g., properly set up vtables.
    CHECK(ThreadState::current());
    CHECK(!ThreadState::current()->isWrapperTracingForbidden());
    CHECK(m_tracingInProgress);
    m_isTracingDone = true;
    const bool result = V8_MAJOR_VERSION >= 7;

    WTF::AutoReset<bool>(&m_advancingTracing, true);
    while (
#if V8_MAJOR_VERSION < 7
        actions.force_completion == v8::EmbedderHeapTracer::ForceCompletionAction::FORCE_COMPLETION ||
#endif
        WTF::monotonicallyIncreasingTimeMS() < deadlineInMs) {
        for (int objects = 0; objects++ < kObjectsBeforeInterrupt;) {
            if (m_markingDeque.isEmpty()) {
                return result;
            }
            
            WrapperMarkingData data = m_markingDeque.takeFirst();
            data.traceWrappers(this);
        }
    }

    return result;
}

bool ScriptWrappableVisitor::markWrapperHeader(HeapObjectHeader* header) const
{
    if (header->isWrapperHeaderMarked())
        return false;

    // Verify that no compactable & movable objects are slated for
    // lazy unmarking.
    DCHECK(!HeapCompact::isCompactableArena(
        pageFromObject(header)->arena()->arenaIndex()));
    header->markWrapperHeader();
    m_headersToUnmark.push_back(header);
    return true;
}

void ScriptWrappableVisitor::markWrappersInAllWorlds(const ScriptWrappable* scriptWrappable) const
{
    DOMWrapperWorld::markWrappersInAllWorlds(const_cast<ScriptWrappable*>(scriptWrappable), this);
}

void ScriptWrappableVisitor::writeBarrier(const void* srcObject, const TraceWrapperV8Reference<v8::Value>* dstObject)
{
    if (!RuntimeEnabledFeatures::traceWrappablesEnabled())
        return;
    
    if (!srcObject || !dstObject || dstObject->isEmpty())
        return;
    
    // We only require a write barrier if |srcObject|  is already marked. Note
    // that this implicitly disables the write barrier when the GC is not
    // active as object will not be marked in this case.
    if (!HeapObjectHeader::fromPayload(srcObject)->isWrapperHeaderMarked()) {
        return;
    }
    currentVisitor(ThreadState::current()->isolate())->markWrapper(&(const_cast<TraceWrapperV8Reference<v8::Value>*>(dstObject)->get()));
}

void ScriptWrappableVisitor::traceWrappers(const TraceWrapperV8Reference<v8::Value>& tracedWrapper) const
{
    markWrapper(&(const_cast<TraceWrapperV8Reference<v8::Value>&>(tracedWrapper).get()));
}

void ScriptWrappableVisitor::markWrapper(
    const v8::PersistentBase<v8::Value>* handle) const
{
    // The write barrier may try to mark a wrapper because cleanup is still
    // delayed. Bail out in this case.
    if (!m_tracingInProgress)
        return;
#if V8_MAJOR_VERSION <= 7
    handle->RegisterExternalReference(m_isolate);
#else
    DebugBreak();
#endif
}

void ScriptWrappableVisitor::dispatchTraceWrappers(
    const TraceWrapperBase* wrapperBase) const
{
    wrapperBase->traceWrappers(this);
}

#define DEFINE_DISPATCH_TRACE_WRAPPERS(className)       \
    void ScriptWrappableVisitor::dispatchTraceWrappers( \
        const className* traceable) const               \
    {                                                   \
        traceable->traceWrappers(this);                 \
    }

WRAPPER_VISITOR_SPECIAL_CLASSES(DEFINE_DISPATCH_TRACE_WRAPPERS);

#undef DEFINE_DISPATCH_TRACE_WRAPPERS

void ScriptWrappableVisitor::invalidateDeadObjectsInMarkingDeque()
{
    for (auto it = m_markingDeque.begin(); it != m_markingDeque.end(); ++it) {
        auto& markingData = *it;
        if (markingData.shouldBeInvalidated()) {
            markingData.invalidate();
        }
    }
    for (auto it = m_verifierDeque.begin(); it != m_verifierDeque.end(); ++it) {
        auto& markingData = *it;
        if (markingData.shouldBeInvalidated()) {
            markingData.invalidate();
        }
    }
    for (auto it = m_headersToUnmark.begin(); it != m_headersToUnmark.end();
         ++it) {
        auto header = *it;
        if (header && !header->isMarked()) {
            *it = nullptr;
        }
    }
}

void ScriptWrappableVisitor::invalidateDeadObjectsInMarkingDeque(
    v8::Isolate* isolate)
{
    ScriptWrappableVisitor* scriptWrappableVisitor = V8PerIsolateData::from(isolate)->scriptWrappableVisitor();
    if (scriptWrappableVisitor)
        scriptWrappableVisitor->invalidateDeadObjectsInMarkingDeque();
}

void ScriptWrappableVisitor::performCleanup(v8::Isolate* isolate)
{
    ScriptWrappableVisitor* scriptWrappableVisitor = V8PerIsolateData::from(isolate)->scriptWrappableVisitor();
    if (scriptWrappableVisitor)
        scriptWrappableVisitor->performCleanup();
}

WrapperVisitor* ScriptWrappableVisitor::currentVisitor(v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->scriptWrappableVisitor();
}

bool ScriptWrappableVisitor::pushToMarkingDeque(
    void (*traceWrappersCallback)(const WrapperVisitor*, const void*),
    void (*trace)(Visitor*, void*),
    HeapObjectHeader* (*heapObjectHeaderCallback)(const void*),
    void (*missedWriteBarrierCallback)(void),
    const void* object) const
{
    if (!m_tracingInProgress)
        return false;

    m_markingDeque.append(WrapperMarkingData(traceWrappersCallback, trace, heapObjectHeaderCallback, object));
#if DCHECK_IS_ON()
    if (!m_advancingTracing) {
        m_verifierDeque.append(WrapperMarkingData(traceWrappersCallback, trace, heapObjectHeaderCallback, object));
    }
#endif
    return true;
}

// void ScriptWrappableVisitor::mark(const void*, TraceCallback)
// {
// 
// }
// 
// void ScriptWrappableVisitor::markHeader(HeapObjectHeader*, TraceCallback)
// {
// 
// }
// 
// void ScriptWrappableVisitor::registerDelayedMarkNoTracing(const void*)
// {
// 
// }
// 
// void ScriptWrappableVisitor::registerWeakMembers(const void*, const void*, WeakCallback)
// {
// 
// }
// 
// void ScriptWrappableVisitor::registerWeakTable(const void*, EphemeronCallback, EphemeronCallback)
// {
// 
// }
// 
// #if DCHECK_IS_ON()
// bool ScriptWrappableVisitor::weakTableRegistered(const void*)
// {
//     return true;
// }
// #endif
// 
// bool ScriptWrappableVisitor::ensureMarked(const void*)
// {
//     return true;
// }
// 
// void ScriptWrappableVisitor::registerMovingObjectReference(MovableReference*)
// {
// 
// }
// 
// void ScriptWrappableVisitor::registerMovingObjectCallback(MovableReference, MovingObjectCallback, void*)
// {
// 
// }
// 
// void ScriptWrappableVisitor::registerWeakCellWithCallback(void**, WeakCallback)
// {
// 
// }

} // namespace blink
