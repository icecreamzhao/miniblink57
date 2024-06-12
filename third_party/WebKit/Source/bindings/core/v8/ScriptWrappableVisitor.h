// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ScriptWrappableVisitor_h
#define ScriptWrappableVisitor_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "core/CoreExport.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/heap/HeapPage.h"
#include "platform/heap/WrapperVisitor.h"
#include "wtf/Deque.h"
#include "wtf/Vector.h"
#include <v8.h>

namespace blink {

class HeapObjectHeader;
template <typename T>
class Member;
template <typename T>
class TraceWrapperV8Reference;

class WrapperMarkingData {
public:
    WrapperMarkingData(
        void (*traceWrappersCallback)(const WrapperVisitor*, const void*),
        void (*traceCallback)(Visitor*, void*),
        HeapObjectHeader* (*heapObjectHeaderCallback)(const void*),
        const void* object)
        : m_traceWrappersCallback(traceWrappersCallback)
        , m_traceCallback(traceCallback)
        , m_heapObjectHeaderCallback(heapObjectHeaderCallback)
        , m_rawObjectPointer(object)
    {
        DCHECK(m_traceWrappersCallback);
        DCHECK(m_heapObjectHeaderCallback);
        DCHECK(m_rawObjectPointer);
    }

    inline void traceWrappers(WrapperVisitor* visitor)
    {
        if (m_rawObjectPointer) {
            m_traceWrappersCallback(visitor, m_rawObjectPointer);
        }
    }

    inline void trace(Visitor* visitor)
    {
        if (m_rawObjectPointer) {
            m_traceCallback(visitor, const_cast<void*>(m_rawObjectPointer));
        }
    }

    // Returns true when object was marked. Ignores (returns true) invalidated
    // objects.
    inline bool isWrapperHeaderMarked()
    {
        return !m_rawObjectPointer || heapObjectHeader()->isWrapperHeaderMarked();
    }

    inline const void* rawObjectPointer() { return m_rawObjectPointer; }

private:
    inline bool shouldBeInvalidated()
    {
        return m_rawObjectPointer && !heapObjectHeader()->isMarked();
    }

    inline void invalidate() { m_rawObjectPointer = nullptr; }

    inline const HeapObjectHeader* heapObjectHeader()
    {
        DCHECK(m_rawObjectPointer);
        return m_heapObjectHeaderCallback(m_rawObjectPointer);
    }

    void (*m_traceWrappersCallback)(const WrapperVisitor*, const void*);
    void (*m_traceCallback)(Visitor*, void*);
    HeapObjectHeader* (*m_heapObjectHeaderCallback)(const void*);
    const void* m_rawObjectPointer;

    friend class ScriptWrappableVisitor;
};

// ScriptWrappableVisitor is able to trace through the objects to get all
// wrappers. It is used during V8 garbage collection.  When this visitor is
// set to the v8::Isolate as its embedder heap tracer, V8 will call it during
// its garbage collection. At the beginning, it will call TracePrologue, then
// repeatedly it will call AdvanceTracing, and at the end it will call
// TraceEpilogue. Everytime V8 finds new wrappers, it will let the tracer
// know using RegisterV8References.
class CORE_EXPORT ScriptWrappableVisitor 
    : public v8::EmbedderHeapTracer
    , public WrapperVisitor
    // , public Visitor 
{
    DISALLOW_IMPLICIT_CONSTRUCTORS(ScriptWrappableVisitor);

public:
    ScriptWrappableVisitor(v8::Isolate* isolate);
    ~ScriptWrappableVisitor() override;

    // Replace all dead objects in the marking deque with nullptr after oilpan
    // gc.
    static void invalidateDeadObjectsInMarkingDeque(v8::Isolate*);

    // Immediately clean up all wrappers.
    static void performCleanup(v8::Isolate*);

    void TracePrologue(
#if V8_MAJOR_VERSION > 7
        v8::EmbedderHeapTracer::TraceFlags flags
#endif
    ) override;

    static WrapperVisitor* currentVisitor(v8::Isolate*);

    static void writeBarrier(const void*,
        const TraceWrapperV8Reference<v8::Value>*);

    template <typename T>
    static void writeBarrier(const void* object, const Member<T> value)
    {
        writeBarrier(object, value.get());
    }

    template <typename T>
    static void writeBarrier(const void* srcObject, const T* dstObject)
    {
        static_assert(!NeedsAdjustAndMark<T>::value,
            "wrapper tracing is not supported within mixins");
        if (!RuntimeEnabledFeatures::traceWrappablesEnabled()) {
            return;
        }
        if (!srcObject || !dstObject) {
            return;
        }
        // We only require a write barrier if |srcObject|  is already marked. Note
        // that this implicitly disables the write barrier when the GC is not
        // active as object will not be marked in this case.
        if (!HeapObjectHeader::fromPayload(srcObject)->isWrapperHeaderMarked()) {
            return;
        }

        const ThreadState* threadState = ThreadState::current();
        DCHECK(threadState);
        // If the wrapper is already marked we can bail out here.
        if (TraceTrait<T>::heapObjectHeader(dstObject)->isWrapperHeaderMarked())
            return;
        // Otherwise, eagerly mark the wrapper header and put the object on the
        // marking deque for further processing.
        WrapperVisitor* const visitor = currentVisitor(threadState->isolate());
        visitor->markAndPushToMarkingDeque(dstObject);
    }

    void RegisterV8References(const std::vector<std::pair<void*, void*>>& internalFieldsOfPotentialWrappers) override;
    void RegisterV8Reference(const std::pair<void*, void*>& internalFields);
    bool AdvanceTracing(double deadlineInMs
#if V8_MAJOR_VERSION < 7
        , v8::EmbedderHeapTracer::AdvanceTracingActions
#endif
    ) override;
    void TraceEpilogue(
#if V8_MAJOR_VERSION > 7
        v8::EmbedderHeapTracer::TraceSummary* trace_summary
#endif
    ) override;
    void AbortTracing() /*override*/;
    void EnterFinalPause() /*override*/;
    size_t NumberOfWrappersToTrace() /*override*/;

#if V8_MAJOR_VERSION >= 7
    bool IsTracingDone(void) override;
    void EnterFinalPause(v8::EmbedderHeapTracer::EmbedderStackState) override;
#endif

    // Visitor
//     virtual void mark(const void*, TraceCallback) override;
//     virtual void markHeader(HeapObjectHeader*, TraceCallback) override;
//     virtual void registerDelayedMarkNoTracing(const void*) override;
//     virtual void registerWeakMembers(const void*, const void*, WeakCallback) override;
//     virtual void registerWeakTable(const void*, EphemeronCallback, EphemeronCallback) override;
// #if DCHECK_IS_ON()
//     virtual bool weakTableRegistered(const void*) override;
// #endif
//     virtual bool ensureMarked(const void*) override;
//     virtual void registerMovingObjectReference(MovableReference*) override;
//     virtual void registerMovingObjectCallback(MovableReference, MovingObjectCallback, void*) override;
//     virtual void registerWeakCellWithCallback(void**, WeakCallback) override;

    void dispatchTraceWrappers(const TraceWrapperBase*) const override;
#define DECLARE_DISPATCH_TRACE_WRAPPERS(className) \
    void dispatchTraceWrappers(const className*) const override;

    WRAPPER_VISITOR_SPECIAL_CLASSES(DECLARE_DISPATCH_TRACE_WRAPPERS);

#undef DECLARE_DISPATCH_TRACE_WRAPPERS

    void traceWrappers(const TraceWrapperV8Reference<v8::Value>&) const override;
    void markWrapper(const v8::PersistentBase<v8::Value>*) const override;

    void invalidateDeadObjectsInMarkingDeque();

    bool markWrapperHeader(HeapObjectHeader*) const override;

    // Mark wrappers in all worlds for the given script wrappable as alive in
    // V8.
    void markWrappersInAllWorlds(const ScriptWrappable*) const override;

    WTF::Deque<WrapperMarkingData>* getMarkingDeque() { return &m_markingDeque; }
    WTF::Deque<WrapperMarkingData>* getVerifierDeque()
    {
        return &m_verifierDeque;
    }
    WTF::Vector<HeapObjectHeader*>* getHeadersToUnmark()
    {
        return &m_headersToUnmark;
    }

protected:    
    bool pushToMarkingDeque(
        void (*traceWrappersCallback)(const WrapperVisitor*, const void*),
        void (*trace)(Visitor*, void*),
        HeapObjectHeader* (*heapObjectHeaderCallback)(const void*),
        void (*missedWriteBarrierCallback)(void),
        const void* object) const override;

private:
    // Returns true if wrapper tracing is currently in progress, i.e.,
    // TracePrologue has been called, and TraceEpilogue has not yet been called.
    bool m_tracingInProgress = false;

    // Is AdvanceTracing currently running? If not, we know that all calls of
    // pushToMarkingDeque are from V8 or new wrapper associations. And this
    // information is used by the verifier feature.
    bool m_advancingTracing = false;

    // Indicates whether an idle task for a lazy cleanup has already been
    // scheduled. The flag is used to avoid scheduling multiple idle tasks for
    // cleaning up.
    bool m_idleCleanupTaskScheduled = false;

    // Indicates whether cleanup should currently happen. The flag is used to
    // avoid cleaning up in the next GC cycle.
    bool m_shouldCleanup = false;

    // Immediately cleans up all wrappers.
    void performCleanup();

    // Schedule an idle task to perform a lazy (incremental) clean up of
    // wrappers.
    void scheduleIdleLazyCleanup();
    void performLazyCleanup(double deadlineSeconds);

    // Collection of objects we need to trace from. We assume it is safe to hold
    // on to the raw pointers because:
    // - oilpan object cannot move
    // - oilpan gc will call invalidateDeadObjectsInMarkingDeque to delete all
    //   obsolete objects
    mutable WTF::Deque<WrapperMarkingData> m_markingDeque;

    // Collection of objects we started tracing from. We assume it is safe to
    // hold on to the raw pointers because:
    // - oilpan object cannot move
    // - oilpan gc will call invalidateDeadObjectsInMarkingDeque to delete
    //   all obsolete objects
    //
    // These objects are used when TraceWrappablesVerifier feature is enabled to
    // verify that all objects reachable in the atomic pause were marked
    // incrementally. If not, there is one or multiple write barriers missing.
    mutable WTF::Deque<WrapperMarkingData> m_verifierDeque;

    // Collection of headers we need to unmark after the tracing finished. We
    // assume it is safe to hold on to the headers because:
    // - oilpan objects cannot move
    // - objects this headers belong to are invalidated by the oilpan GC in
    //   invalidateDeadObjectsInMarkingDeque.
    mutable WTF::Vector<HeapObjectHeader*> m_headersToUnmark;
    v8::Isolate* m_isolate;

    bool m_isTracingDone;
};

} // namespace blink

#endif // ScriptWrappableVisitor_h
