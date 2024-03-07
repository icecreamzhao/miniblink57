// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/WebKit/Source/platform/heap/UnifiedHeapController.h"

#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/WrapperTypeInfo.h"
#include "third_party/WebKit/Source/platform/heap/heap.h"
#include "third_party/WebKit/Source/platform/heap/MarkingVisitor.h"
//#include "third_party/WebKit/Source/core/dom/ActiveDOMObject.h"
#include "third_party/WebKit/Source/core/events/EventTarget.h"
#include "third_party/WebKit/Source/bindings/core/v8/V8GCController.h"
// #include "third_party/blink/renderer/platform/heap/heap_stats_collector.h"
// #include "third_party/blink/renderer/platform/heap/marking_visitor.h"
// #include "third_party/blink/renderer/platform/heap/thread_state.h"
// #include "third_party/blink/renderer/platform/runtime_enabled_features.h"

#if V8_MAJOR_VERSION >= 7

namespace blink {

UnifiedHeapController::UnifiedHeapController(ThreadState* threadState)
    : m_threadState(threadState)
    , m_v8References(nullptr)
{
}

UnifiedHeapController::~UnifiedHeapController()
{
    if (m_v8References)
        delete m_v8References;
}

std::vector<std::pair<void*, void*>>* UnifiedHeapController::leakV8References()
{
    std::vector<std::pair<void*, void*> >* v8References = m_v8References;
    m_v8References = nullptr;
    return v8References;
}

void UnifiedHeapController::TracePrologue(
#if V8_MAJOR_VERSION > 7
    v8::EmbedderHeapTracer::TraceFlags flags
#endif
)
{
    //OutputDebugStringA("UnifiedHeapController::TracePrologue\n");
//     VLOG(2) << "UnifiedHeapController::TracePrologue";
//     ThreadHeapStatsCollector::BlinkGCInV8Scope nested_scope(m_threadState->Heap().stats_collector());
// 
//     // Be conservative here as a new garbage collection gets started right away.
//     m_threadState->FinishIncrementalMarkingIfRunning(BlinkGC::kHeapPointersOnStack, BlinkGC::kIncrementalMarking, BlinkGC::kLazySweeping, m_threadState->current_gc_data_.reason);
// 
//     // Reset any previously scheduled garbage collections.
//     m_threadState->SetGCState(ThreadState::kNoGCScheduled);
//     // Start incremental marking with unified tracing.
//     m_threadState->IncrementalMarkingStart(BlinkGC::GCReason::kUnifiedHeapGC);

    is_tracing_done_ = false;
}

void UnifiedHeapController::EnterFinalPause(EmbedderStackState stack_state)
{
    //OutputDebugStringA("UnifiedHeapController::EnterFinalPause\n");
//     VLOG(2) << "UnifiedHeapController::EnterFinalPause";
//     ThreadHeapStatsCollector::BlinkGCInV8Scope nested_scope(
//         m_threadState->Heap().stats_collector());
//     ThreadHeapStatsCollector::Scope stats_scope(m_threadState->Heap().stats_collector(), ThreadHeapStatsCollector::kAtomicPhase);
//     m_threadState->EnterAtomicPause();
//     m_threadState->EnterGCForbiddenScope();
// 
//     {
//         ThreadHeapStatsCollector::Scope mark_prologue_scope(m_threadState->Heap().stats_collector(), ThreadHeapStatsCollector::kUnifiedMarkingAtomicPrologue);
//         m_threadState->AtomicPauseMarkPrologue(ToBlinkGCStackState(stack_state), BlinkGC::kIncrementalMarking, BlinkGC::GCReason::kUnifiedHeapGC);
//     }

    // ActiveScriptWrappableBase::traceActiveScriptWrappables

    //OutputDebugStringA("UnifiedHeapController::EnterFinalPause 1\n");
    //V8GCController::gcPrologue(v8::Isolate::GetCurrent(), v8::kGCTypeMarkSweepCompact, v8::kGCCallbackFlagForced, nullptr);
    //OutputDebugStringA("UnifiedHeapController::EnterFinalPause 2\n");
}

void UnifiedHeapController::TraceEpilogue(
#if V8_MAJOR_VERSION > 7
    v8::EmbedderHeapTracer::TraceSummary* trace_summary
#endif
)
{
    //OutputDebugStringA("UnifiedHeapController::TraceEpilogue\n");
//     VLOG(2) << "UnifiedHeapController::TraceEpilogue";
// 
//     {
//         ThreadHeapStatsCollector::BlinkGCInV8Scope nested_scope(m_threadState->Heap().stats_collector());
//         ThreadHeapStatsCollector::Scope stats_scope(m_threadState->Heap().stats_collector(), ThreadHeapStatsCollector::kAtomicPhase);
// 
//         m_threadState->AtomicPauseMarkEpilogue(BlinkGC::kIncrementalMarking);
//         m_threadState->LeaveAtomicPause();
//         m_threadState->LeaveGCForbiddenScope();
//         m_threadState->AtomicPauseSweepAndCompact(BlinkGC::kIncrementalMarking, BlinkGC::kLazySweeping);
//     }
// 
//     if (!m_threadState->IsSweepingInProgress()) {
//         // Sweeping was finished during the atomic pause. Update statistics needs to
//         // run outside of the top-most stats scope.
//         m_threadState->UpdateStatisticsAfterSweeping();
//     }
}

void UnifiedHeapController::RegisterV8References(const std::vector<std::pair<void*, void*>>& internalFieldsOfPotentialWrappers)
{
//     VLOG(2) << "UnifiedHeapController::RegisterV8References";
//     DCHECK(thread_state()->IsMarkingInProgress());

//     const bool was_in_atomic_pause = thread_state()->in_atomic_pause();
//     if (!was_in_atomic_pause)
//         ThreadState::Current()->EnterAtomicPause();

    //OwnPtr<Visitor> visitor = adoptPtr(new MarkingVisitor<Visitor::GlobalMarking>());

//     for (size_t i = 0; i < internalFieldsOfPotentialWrappers.size(); ++i) {
//         if (!m_v8References)
//             m_v8References = new std::vector<std::pair<void*, void*>>();
// 
//         std::pair<void*, void*> internalFields = internalFieldsOfPotentialWrappers[i];
//         WrapperTypeInfo* wrapperTypeInfo = reinterpret_cast<WrapperTypeInfo*>(internalFields.first);
// 
//         void* scriptWrappablePtr = internalFields.second;
//         ScriptWrappable* scriptWrappable = (ScriptWrappable*)scriptWrappablePtr;
// 
//         char* output = (char*)malloc(0x100);
//         sprintf_s(output, 0x99, "UnifiedHeapController::RegisterV8References: %p %p\n", wrapperTypeInfo, scriptWrappable);
//         OutputDebugStringA(output);
//         free(output);
// 
//         if (wrapperTypeInfo->ginEmbedder != gin::GinEmbedder::kEmbedderBlink)
//             continue;
//         
//         is_tracing_done_ = false;
//         //wrapperTypeInfo->trace(visitor.get(), scriptWrappable);
//         m_v8References->push_back(std::pair<void*, void*>(wrapperTypeInfo, scriptWrappable));
//     }

//     if (!was_in_atomic_pause)
//         ThreadState::Current()->LeaveAtomicPause();
}

bool UnifiedHeapController::AdvanceTracing(double deadline_in_ms)
{
    //OutputDebugStringA("AdvanceTracing\n");
//     VLOG(2) << "UnifiedHeapController::AdvanceTracing";
//     ThreadHeapStatsCollector::Scope advance_tracing_scope(m_threadState->Heap().stats_collector(), ThreadHeapStatsCollector::kUnifiedMarkingStep);
// 
//     if (!m_threadState->in_atomic_pause()) {
//         // V8 calls into embedder tracing from its own marking to ensure
//         // progress. Oilpan will additionally schedule marking steps.
//         ThreadState::AtomicPauseScope atomic_pause_scope(m_threadState);
//         TimeTicks deadline = TimeTicks() + TimeDelta::FromMillisecondsD(deadline_in_ms);
//         is_tracing_done_ = m_threadState->MarkPhaseAdvanceMarking(deadline);
//         return is_tracing_done_;
//     }
// 
//     m_threadState->AtomicPauseMarkTransitiveClosure();
    is_tracing_done_ = true;

    return true;
}

bool UnifiedHeapController::IsTracingDone()
{
    return is_tracing_done_;
}

const WrapperTypeInfo* toWrapperTypeInfo(const v8::TracedGlobal<v8::Object>& wrapper);

bool UnifiedHeapController::IsRootForNonTracingGCInternal(const v8::TracedGlobal<v8::Value>& handle)
{
    const uint16_t classId = handle.WrapperClassId();
    // Stand-alone TracedGlobal reference or kCustomWrappableId. Keep as root as we don't know better.
    if (classId != WrapperTypeInfo::NodeClassId && classId != WrapperTypeInfo::ObjectClassId)
        return true;

    const v8::TracedGlobal<v8::Object>& traced = handle.As<v8::Object>();
    v8::Local<v8::Object> wrapper = traced.Get(v8::Isolate::GetCurrent());

//     if (toWrapperTypeInfo(traced)->isActiveScriptWrappable() && toScriptWrappable(traced)->hasPendingActivity())
//         return true;

    const WrapperTypeInfo* type = toWrapperTypeInfo(wrapper);
    if (!type)
        return false;
    if (type->isActiveScriptWrappable())
        return true;

    EventTarget* target = type->toEventTarget(wrapper);
    if (target && target->hasEventListeners())
        return true;

    ScriptWrappable* scriptWrappable = toScriptWrappable(wrapper);
    if (scriptWrappable && scriptWrappable->hasPendingActivity())
        return true;

// 
//     ActiveDOMObject* activeDOMObject = type->toActiveDOMObject(wrapper);
//     ScriptWrappable* scriptWrap = toScriptWrappable(wrapper);
// 
//     if (activeDOMObject && activeDOMObject->hasPendingActivity())
//         return true;
// 
// 
//     if (scriptWrap && scriptWrap->hasScriptWrappableEventListeners())
//         return true;

    return false;
}

bool UnifiedHeapController::IsRootForNonTracingGC(const v8::TracedGlobal<v8::Value>& handle)
{
    return IsRootForNonTracingGCInternal(handle);
}

}  // namespace blink

#endif
