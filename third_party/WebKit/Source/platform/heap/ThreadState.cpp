/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
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
#include "platform/heap/ThreadState.h"

#include "base/trace_event/process_memory_dump.h"
#include "platform/Histogram.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/ScriptForbiddenScope.h"
#include "platform/heap/BlinkGCMemoryDumpProvider.h"
#include "platform/heap/CallbackStack.h"
#include "platform/heap/Handle.h"
#include "platform/heap/Heap.h"
#include "platform/heap/HeapCompact.h"
#include "platform/heap/PagePool.h"
#include "platform/heap/SafePoint.h"
#include "platform/heap/Visitor.h"
#include "platform/instrumentation/tracing/TraceEvent.h"
#include "platform/instrumentation/tracing/web_memory_allocator_dump.h"
#include "platform/instrumentation/tracing/web_process_memory_dump.h"
=======
#include "config.h"
#include "platform/heap/ThreadState.h"

#include "platform/ScriptForbiddenScope.h"
#include "platform/TraceEvent.h"
#include "platform/heap/CallbackStack.h"
#include "platform/heap/Handle.h"
#include "platform/heap/Heap.h"
#include "platform/heap/MarkingVisitor.h"
#include "platform/heap/SafePoint.h"
>>>>>>> miniblink49
#include "public/platform/Platform.h"
#include "public/platform/WebScheduler.h"
#include "public/platform/WebThread.h"
#include "public/platform/WebTraceLocation.h"
<<<<<<< HEAD
#include "wtf/CurrentTime.h"
#include "wtf/DataLog.h"
#include "wtf/PtrUtil.h"
#include "wtf/StackUtil.h"
#include "wtf/ThreadingPrimitives.h"
#include "wtf/allocator/Partitions.h"
#include <memory>
#include <v8.h>
=======
#include "wtf/Partitions.h"
#include "wtf/ThreadingPrimitives.h"
#if ENABLE(GC_PROFILING)
#include "platform/TracedValue.h"
#include "wtf/text/StringHash.h"
#endif
>>>>>>> miniblink49

#if OS(WIN)
#include <stddef.h>
#include <windows.h>
#include <winnt.h>
<<<<<<< HEAD
=======
#elif defined(__GLIBC__)
extern "C" void* __libc_stack_end;  // NOLINT
>>>>>>> miniblink49
#endif

#if defined(MEMORY_SANITIZER)
#include <sanitizer/msan_interface.h>
#endif

<<<<<<< HEAD
=======
#if ENABLE(GC_PROFILING)
#include <limits>
#endif

>>>>>>> miniblink49
#if OS(FREEBSD)
#include <pthread_np.h>
#endif

namespace blink {

WTF::ThreadSpecific<ThreadState*>* ThreadState::s_threadSpecific = nullptr;
<<<<<<< HEAD
uint8_t ThreadState::s_mainThreadStateStorage[sizeof(ThreadState)];

const size_t defaultAllocatedObjectSizeThreshold = 100 * 1024;

const char* ThreadState::gcReasonString(BlinkGC::GCReason reason)
{
    switch (reason) {
    case BlinkGC::IdleGC:
        return "IdleGC";
    case BlinkGC::PreciseGC:
        return "PreciseGC";
    case BlinkGC::ConservativeGC:
        return "ConservativeGC";
    case BlinkGC::ForcedGC:
        return "ForcedGC";
    case BlinkGC::MemoryPressureGC:
        return "MemoryPressureGC";
    case BlinkGC::PageNavigationGC:
        return "PageNavigationGC";
    default:
        NOTREACHED();
    }
    return "<Unknown>";
}

class ParkThreadsScope final {
    STACK_ALLOCATED();

public:
    explicit ParkThreadsScope(ThreadState* state)
        : m_state(state)
        , m_shouldResumeThreads(false)
    {
    }

    bool parkThreads()
    {
        TRACE_EVENT0("blink_gc", "ThreadHeap::ParkThreadsScope");

        // TODO(haraken): In an unlikely coincidence that two threads decide
        // to collect garbage at the same time, avoid doing two GCs in
        // a row and return false.
        double startTime = WTF::currentTimeMS();

        m_shouldResumeThreads = m_state->heap().park();

        double timeForStoppingThreads = WTF::currentTimeMS() - startTime;
        DEFINE_THREAD_SAFE_STATIC_LOCAL(
            CustomCountHistogram, timeToStopThreadsHistogram,
            new CustomCountHistogram("BlinkGC.TimeForStoppingThreads", 1, 1000,
                50));
        timeToStopThreadsHistogram.count(timeForStoppingThreads);

        return m_shouldResumeThreads;
    }

    ~ParkThreadsScope()
    {
        // Only cleanup if we parked all threads in which case the GC happened
        // and we need to resume the other threads.
        if (m_shouldResumeThreads)
            m_state->heap().resume();
    }

private:
    ThreadState* m_state;
    bool m_shouldResumeThreads;
};

ThreadState::ThreadState()
    : m_thread(currentThread())
    , m_persistentRegion(WTF::makeUnique<PersistentRegion>())
    , m_startOfStack(reinterpret_cast<intptr_t*>(WTF::getStackStart()))
    , m_endOfStack(reinterpret_cast<intptr_t*>(WTF::getStackStart()))
=======
uintptr_t ThreadState::s_mainThreadStackStart = 0;
uintptr_t ThreadState::s_mainThreadUnderestimatedStackSize = 0;
uint8_t ThreadState::s_mainThreadStateStorage[sizeof(ThreadState)];
SafePointBarrier* ThreadState::s_safePointBarrier = nullptr;

RecursiveMutex& ThreadState::threadAttachMutex()
{
    AtomicallyInitializedStaticReference(RecursiveMutex, mutex, (new RecursiveMutex));
    return mutex;
}

ThreadState::ThreadState()
    : m_thread(currentThread())
    , m_persistentRegion(adoptPtr(new PersistentRegion()))
    , m_startOfStack(reinterpret_cast<intptr_t*>(StackFrameDepth::getStackStart()))
    , m_endOfStack(reinterpret_cast<intptr_t*>(StackFrameDepth::getStackStart()))
>>>>>>> miniblink49
    , m_safePointScopeMarker(nullptr)
    , m_atSafePoint(false)
    , m_interruptors()
    , m_sweepForbidden(false)
    , m_noAllocationCount(0)
    , m_gcForbiddenCount(0)
<<<<<<< HEAD
    , m_mixinsBeingConstructedCount(0)
    , m_accumulatedSweepingTime(0)
    , m_vectorBackingArenaIndex(BlinkGC::Vector1ArenaIndex)
    , m_currentArenaAges(0)
=======
    , m_vectorBackingHeapIndex(Vector1HeapIndex)
    , m_currentHeapAges(0)
>>>>>>> miniblink49
    , m_isTerminating(false)
    , m_gcMixinMarker(nullptr)
    , m_shouldFlushHeapDoesNotContainCache(false)
    , m_gcState(NoGCScheduled)
<<<<<<< HEAD
    , m_threadLocalWeakCallbackStack(CallbackStack::create())
    , m_isolate(nullptr)
    , m_traceDOMWrappers(nullptr)
    , m_invalidateDeadObjectsInWrappersMarkingDeque(nullptr)
    ,
#if defined(ADDRESS_SANITIZER)
    m_asanFakeStack(__asan_get_current_fake_stack())
    ,
#endif
#if defined(LEAK_SANITIZER)
    m_disabledStaticPersistentsRegistration(0)
    ,
#endif
    m_allocatedObjectSize(0)
    , m_markedObjectSize(0)
    , m_reportedMemoryToV8(0)
=======
    , m_traceDOMWrappers(nullptr)
#if defined(ADDRESS_SANITIZER)
    , m_asanFakeStack(__asan_get_current_fake_stack())
#endif
#if ENABLE(GC_PROFILING)
    , m_nextFreeListSnapshotTime(-std::numeric_limits<double>::infinity())
#endif
>>>>>>> miniblink49
{
    ASSERT(checkThread());
    ASSERT(!**s_threadSpecific);
    **s_threadSpecific = this;

<<<<<<< HEAD
    m_heap = new ThreadHeap();
    ASSERT(m_heap);
    m_heap->attach(this);

    for (int arenaIndex = 0; arenaIndex < BlinkGC::LargeObjectArenaIndex;
         arenaIndex++)
        m_arenas[arenaIndex] = new NormalPageArena(this, arenaIndex);
    m_arenas[BlinkGC::LargeObjectArenaIndex] = new LargeObjectArena(this, BlinkGC::LargeObjectArenaIndex);

    m_likelyToBePromptlyFreed = wrapArrayUnique(new int[likelyToBePromptlyFreedArraySize]);
    clearArenaAges();
=======
    if (isMainThread()) {
        s_mainThreadStackStart = reinterpret_cast<uintptr_t>(m_startOfStack) - sizeof(void*);
        size_t underestimatedStackSize = StackFrameDepth::getUnderestimatedStackSize();
        if (underestimatedStackSize > sizeof(void*))
            s_mainThreadUnderestimatedStackSize = underestimatedStackSize - sizeof(void*);
    }

    for (int heapIndex = 0; heapIndex < LargeObjectHeapIndex; heapIndex++)
        m_heaps[heapIndex] = new NormalPageHeap(this, heapIndex);
    m_heaps[LargeObjectHeapIndex] = new LargeObjectHeap(this, LargeObjectHeapIndex);

    m_likelyToBePromptlyFreed = adoptArrayPtr(new int[likelyToBePromptlyFreedArraySize]);
    clearHeapAges();

    m_threadLocalWeakCallbackStack = new CallbackStack();
>>>>>>> miniblink49
}

ThreadState::~ThreadState()
{
    ASSERT(checkThread());
<<<<<<< HEAD
    for (int i = 0; i < BlinkGC::NumberOfArenas; ++i)
        delete m_arenas[i];

    **s_threadSpecific = nullptr;
=======
    delete m_threadLocalWeakCallbackStack;
    m_threadLocalWeakCallbackStack = nullptr;
    for (int i = 0; i < NumberOfHeaps; ++i)
        delete m_heaps[i];
    deleteAllValues(m_interruptors);
    **s_threadSpecific = nullptr;
    if (isMainThread()) {
        s_mainThreadStackStart = 0;
        s_mainThreadUnderestimatedStackSize = 0;
    }
}

void ThreadState::init()
{
    s_threadSpecific = new WTF::ThreadSpecific<ThreadState*>();
    s_safePointBarrier = new SafePointBarrier;
}

void ThreadState::shutdown()
{
    delete s_safePointBarrier;
    s_safePointBarrier = nullptr;

    // Thread-local storage shouldn't be disposed, so we don't call ~ThreadSpecific().
>>>>>>> miniblink49
}

void ThreadState::attachMainThread()
{
<<<<<<< HEAD
    RELEASE_ASSERT(!ProcessHeap::s_shutdownComplete);
    s_threadSpecific = new WTF::ThreadSpecific<ThreadState*>();
    new (s_mainThreadStateStorage) ThreadState();
}

void ThreadState::attachCurrentThread()
{
    RELEASE_ASSERT(!ProcessHeap::s_shutdownComplete);
    new ThreadState();
}

void ThreadState::cleanupPages()
{
    ASSERT(checkThread());
    for (int i = 0; i < BlinkGC::NumberOfArenas; ++i)
        m_arenas[i]->cleanupPages();
}

void ThreadState::runTerminationGC()
{
    if (isMainThread()) {
        cleanupPages();
        return;
    }
    ASSERT(checkThread());

    // Finish sweeping.
    completeSweep();

    releaseStaticPersistentNodes();

    // From here on ignore all conservatively discovered
    // pointers into the heap owned by this thread.
    m_isTerminating = true;

    // Set the terminate flag on all heap pages of this thread. This is used to
    // ensure we don't trace pages on other threads that are not part of the
    // thread local GC.
    prepareForThreadStateTermination();

    ProcessHeap::crossThreadPersistentRegion().prepareForThreadStateTermination(
        this);

    // Do thread local GC's as long as the count of thread local Persistents
    // changes and is above zero.
    int oldCount = -1;
    int currentCount = getPersistentRegion()->numberOfPersistents();
    ASSERT(currentCount >= 0);
    while (currentCount != oldCount) {
        collectGarbageForTerminatingThread();
        // Release the thread-local static persistents that were
        // instantiated while running the termination GC.
        releaseStaticPersistentNodes();
        oldCount = currentCount;
        currentCount = getPersistentRegion()->numberOfPersistents();
    }
    // We should not have any persistents left when getting to this point,
    // if we have it is probably a bug so adding a debug ASSERT to catch this.
    ASSERT(!currentCount);
    // All of pre-finalizers should be consumed.
    ASSERT(m_orderedPreFinalizers.isEmpty());
    RELEASE_ASSERT(gcState() == NoGCScheduled);

    // Add pages to the orphaned page pool to ensure any global GCs from this
    // point on will not trace objects on this thread's arenas.
    cleanupPages();
}

void ThreadState::cleanupMainThread()
{
    ASSERT(isMainThread());

    releaseStaticPersistentNodes();

    // Finish sweeping before shutting down V8. Otherwise, some destructor
    // may access V8 and cause crashes.
    completeSweep();

    // It is unsafe to trigger GCs after this point because some
    // destructor may access already-detached V8 and cause crashes.
    // Also it is useless. So we forbid GCs.
    enterGCForbiddenScope();
=======
    RELEASE_ASSERT(!Heap::s_shutdownCalled);
    MutexLocker locker(threadAttachMutex());
    ThreadState* state = new(s_mainThreadStateStorage) ThreadState();
    attachedThreads().add(state);
>>>>>>> miniblink49
}

void ThreadState::detachMainThread()
{
    // Enter a safe point before trying to acquire threadAttachMutex
    // to avoid dead lock if another thread is preparing for GC, has acquired
    // threadAttachMutex and waiting for other threads to pause or reach a
    // safepoint.
    ThreadState* state = mainThreadState();
<<<<<<< HEAD
    ASSERT(!state->isSweepingInProgress());

    state->heap().detach(state);
    state->~ThreadState();
}

void ThreadState::detachCurrentThread()
{
    ThreadState* state = current();
    state->heap().detach(state);
    RELEASE_ASSERT(state->gcState() == ThreadState::NoGCScheduled);
    delete state;
=======

    // 1. Finish sweeping.
    state->completeSweep();
    {
        SafePointAwareMutexLocker locker(threadAttachMutex(), NoHeapPointersOnStack);

        // 2. Add the main thread's heap pages to the orphaned pool.
        state->cleanupPages();

        // 3. Detach the main thread.
        ASSERT(attachedThreads().contains(state));
        attachedThreads().remove(state);
        state->~ThreadState();
    }
    shutdownHeapIfNecessary();
}

void ThreadState::shutdownHeapIfNecessary()
{
    // We don't need to enter a safe point before acquiring threadAttachMutex
    // because this thread is already detached.

    MutexLocker locker(threadAttachMutex());
    // We start shutting down the heap if there is no running thread
    // and Heap::shutdown() is already called.
    if (!attachedThreads().size() && Heap::s_shutdownCalled)
        Heap::doShutdown();
}

void ThreadState::attach()
{
    RELEASE_ASSERT(!Heap::s_shutdownCalled);
    MutexLocker locker(threadAttachMutex());
    ThreadState* state = new ThreadState();
    attachedThreads().add(state);
}

void ThreadState::cleanupPages()
{
    ASSERT(checkThread());
    for (int i = 0; i < NumberOfHeaps; ++i)
        m_heaps[i]->cleanupPages();
}

void ThreadState::cleanup()
{
    ASSERT(checkThread());
    {
        // Grab the threadAttachMutex to ensure only one thread can shutdown at
        // a time and that no other thread can do a global GC. It also allows
        // safe iteration of the attachedThreads set which happens as part of
        // thread local GC asserts. We enter a safepoint while waiting for the
        // lock to avoid a dead-lock where another thread has already requested
        // GC.
        SafePointAwareMutexLocker locker(threadAttachMutex(), NoHeapPointersOnStack);

        // Finish sweeping.
        completeSweep();

        // From here on ignore all conservatively discovered
        // pointers into the heap owned by this thread.
        m_isTerminating = true;

        // Set the terminate flag on all heap pages of this thread. This is used to
        // ensure we don't trace pages on other threads that are not part of the
        // thread local GC.
        prepareHeapForTermination();

        // Do thread local GC's as long as the count of thread local Persistents
        // changes and is above zero.
        int oldCount = -1;
        int currentCount = persistentRegion()->numberOfPersistents();
        ASSERT(currentCount >= 0);
        while (currentCount != oldCount) {
            Heap::collectGarbageForTerminatingThread(this);
            oldCount = currentCount;
            currentCount = persistentRegion()->numberOfPersistents();
        }
        // We should not have any persistents left when getting to this point,
        // if we have it is probably a bug so adding a debug ASSERT to catch this.
        ASSERT(!currentCount);
        // All of pre-finalizers should be consumed.
        ASSERT(m_orderedPreFinalizers.isEmpty());
        RELEASE_ASSERT(gcState() == NoGCScheduled);

        // Add pages to the orphaned page pool to ensure any global GCs from this point
        // on will not trace objects on this thread's heaps.
        cleanupPages();

        ASSERT(attachedThreads().contains(this));
        attachedThreads().remove(this);
    }
}

void ThreadState::detach()
{
    ThreadState* state = current();
    state->cleanup();
    RELEASE_ASSERT(state->gcState() == ThreadState::NoGCScheduled);
    delete state;
    shutdownHeapIfNecessary();
}

void ThreadState::visitPersistentRoots(Visitor* visitor)
{
    TRACE_EVENT0("blink_gc", "ThreadState::visitPersistentRoots");
    crossThreadPersistentRegion().tracePersistentNodes(visitor);

    for (ThreadState* state : attachedThreads())
        state->visitPersistents(visitor);
}

void ThreadState::visitStackRoots(Visitor* visitor)
{
    TRACE_EVENT0("blink_gc", "ThreadState::visitStackRoots");
    for (ThreadState* state : attachedThreads())
        state->visitStack(visitor);
>>>>>>> miniblink49
}

NO_SANITIZE_ADDRESS
void ThreadState::visitAsanFakeStackForPointer(Visitor* visitor, Address ptr)
{
#if defined(ADDRESS_SANITIZER)
    Address* start = reinterpret_cast<Address*>(m_startOfStack);
    Address* end = reinterpret_cast<Address*>(m_endOfStack);
    Address* fakeFrameStart = nullptr;
    Address* fakeFrameEnd = nullptr;
    Address* maybeFakeFrame = reinterpret_cast<Address*>(ptr);
<<<<<<< HEAD
    Address* realFrameForFakeFrame = reinterpret_cast<Address*>(
        __asan_addr_is_in_fake_stack(m_asanFakeStack, maybeFakeFrame,
            reinterpret_cast<void**>(&fakeFrameStart),
            reinterpret_cast<void**>(&fakeFrameEnd)));
=======
    Address* realFrameForFakeFrame =
        reinterpret_cast<Address*>(
            __asan_addr_is_in_fake_stack(
                m_asanFakeStack, maybeFakeFrame,
                reinterpret_cast<void**>(&fakeFrameStart),
                reinterpret_cast<void**>(&fakeFrameEnd)));
>>>>>>> miniblink49
    if (realFrameForFakeFrame) {
        // This is a fake frame from the asan fake stack.
        if (realFrameForFakeFrame > end && start > realFrameForFakeFrame) {
            // The real stack address for the asan fake frame is
            // within the stack range that we need to scan so we need
            // to visit the values in the fake frame.
            for (Address* p = fakeFrameStart; p < fakeFrameEnd; ++p)
<<<<<<< HEAD
                m_heap->checkAndMarkPointer(visitor, *p);
=======
                Heap::checkAndMarkPointer(visitor, *p);
>>>>>>> miniblink49
        }
    }
#endif
}

<<<<<<< HEAD
// Stack scanning may overrun the bounds of local objects and/or race with
// other threads that use this stack.
NO_SANITIZE_ADDRESS
NO_SANITIZE_THREAD
void ThreadState::visitStack(Visitor* visitor)
{
    if (m_stackState == BlinkGC::NoHeapPointersOnStack)
=======
NO_SANITIZE_ADDRESS
void ThreadState::visitStack(Visitor* visitor)
{
    if (m_stackState == NoHeapPointersOnStack)
>>>>>>> miniblink49
        return;

    Address* start = reinterpret_cast<Address*>(m_startOfStack);
    // If there is a safepoint scope marker we should stop the stack
    // scanning there to not touch active parts of the stack. Anything
    // interesting beyond that point is in the safepoint stack copy.
    // If there is no scope marker the thread is blocked and we should
    // scan all the way to the recorded end stack pointer.
    Address* end = reinterpret_cast<Address*>(m_endOfStack);
    Address* safePointScopeMarker = reinterpret_cast<Address*>(m_safePointScopeMarker);
    Address* current = safePointScopeMarker ? safePointScopeMarker : end;

    // Ensure that current is aligned by address size otherwise the loop below
    // will read past start address.
    current = reinterpret_cast<Address*>(reinterpret_cast<intptr_t>(current) & ~(sizeof(Address) - 1));

    for (; current < start; ++current) {
        Address ptr = *current;
#if defined(MEMORY_SANITIZER)
        // |ptr| may be uninitialized by design. Mark it as initialized to keep
        // MSan from complaining.
        // Note: it may be tempting to get rid of |ptr| and simply use |current|
        // here, but that would be incorrect. We intentionally use a local
        // variable because we don't want to unpoison the original stack.
        __msan_unpoison(&ptr, sizeof(ptr));
#endif
<<<<<<< HEAD
        m_heap->checkAndMarkPointer(visitor, ptr);
=======
        Heap::checkAndMarkPointer(visitor, ptr);
>>>>>>> miniblink49
        visitAsanFakeStackForPointer(visitor, ptr);
    }

    for (Address ptr : m_safePointStackCopy) {
#if defined(MEMORY_SANITIZER)
        // See the comment above.
        __msan_unpoison(&ptr, sizeof(ptr));
#endif
<<<<<<< HEAD
        m_heap->checkAndMarkPointer(visitor, ptr);
=======
        Heap::checkAndMarkPointer(visitor, ptr);
>>>>>>> miniblink49
        visitAsanFakeStackForPointer(visitor, ptr);
    }
}

void ThreadState::visitPersistents(Visitor* visitor)
{
    m_persistentRegion->tracePersistentNodes(visitor);
    if (m_traceDOMWrappers) {
        TRACE_EVENT0("blink_gc", "V8GCController::traceDOMWrappers");
        m_traceDOMWrappers(m_isolate, visitor);
    }
}

<<<<<<< HEAD
ThreadState::GCSnapshotInfo::GCSnapshotInfo(size_t numObjectTypes)
    : liveCount(Vector<int>(numObjectTypes))
    , deadCount(Vector<int>(numObjectTypes))
    , liveSize(Vector<size_t>(numObjectTypes))
    , deadSize(Vector<size_t>(numObjectTypes))
{
}

void ThreadState::pushThreadLocalWeakCallback(void* object,
    WeakCallback callback)
=======
#if ENABLE(GC_PROFILING)
const GCInfo* ThreadState::findGCInfo(Address address)
{
    if (BasePage* page = findPageFromAddress(address))
        return page->findGCInfo(address);
    return nullptr;
}

size_t ThreadState::SnapshotInfo::getClassTag(const GCInfo* gcInfo)
{
    ClassTagMap::AddResult result = classTags.add(gcInfo, classTags.size());
    if (result.isNewEntry) {
        liveCount.append(0);
        deadCount.append(0);
        liveSize.append(0);
        deadSize.append(0);
        generations.append(GenerationCountsVector());
        generations.last().fill(0, 8);
    }
    return result.storedValue->value;
}

void ThreadState::snapshot()
{
    SnapshotInfo info(this);
    RefPtr<TracedValue> json = TracedValue::create();

#define SNAPSHOT_HEAP(HeapType)                                    \
    {                                                              \
        json->beginDictionary();                                   \
        json->setString("name", #HeapType);                        \
        m_heaps[HeapType##HeapIndex]->snapshot(json.get(), &info); \
        json->endDictionary();                                     \
    }
    json->beginArray("heaps");
    SNAPSHOT_HEAP(EagerSweep);
    SNAPSHOT_HEAP(NormalPage1);
    SNAPSHOT_HEAP(NormalPage2);
    SNAPSHOT_HEAP(NormalPage3);
    SNAPSHOT_HEAP(NormalPage4);
    SNAPSHOT_HEAP(Vector1);
    SNAPSHOT_HEAP(Vector2);
    SNAPSHOT_HEAP(Vector3);
    SNAPSHOT_HEAP(Vector4);
    SNAPSHOT_HEAP(InlineVector);
    SNAPSHOT_HEAP(HashTable);
    SNAPSHOT_HEAP(LargeObject);
    FOR_EACH_TYPED_HEAP(SNAPSHOT_HEAP);
    json->endArray();
#undef SNAPSHOT_HEAP

    json->setInteger("allocatedSpace", Heap::allocatedSpace());
    json->setInteger("objectSpace", Heap::allocatedObjectSize());
    json->setInteger("pageCount", info.pageCount);
    json->setInteger("freeSize", info.freeSize);

    Vector<String> classNameVector(info.classTags.size());
    for (SnapshotInfo::ClassTagMap::iterator it = info.classTags.begin(); it != info.classTags.end(); ++it)
        classNameVector[it->value] = it->key->m_className;

    size_t liveSize = 0;
    size_t deadSize = 0;
    json->beginArray("classes");
    for (size_t i = 0; i < classNameVector.size(); ++i) {
        json->beginDictionary();
        json->setString("name", classNameVector[i]);
        json->setInteger("liveCount", info.liveCount[i]);
        json->setInteger("deadCount", info.deadCount[i]);
        json->setInteger("liveSize", info.liveSize[i]);
        json->setInteger("deadSize", info.deadSize[i]);
        liveSize += info.liveSize[i];
        deadSize += info.deadSize[i];

        json->beginArray("generations");
        for (size_t j = 0; j < numberOfGenerationsToTrack; ++j)
            json->pushInteger(info.generations[i][j]);
        json->endArray();
        json->endDictionary();
    }
    json->endArray();
    json->setInteger("liveSize", liveSize);
    json->setInteger("deadSize", deadSize);

    auto jsonPtr = json.release();
    TRACE_EVENT_OBJECT_SNAPSHOT_WITH_ID("blink_gc", "ThreadState", this, jsonPtr);
#ifdef _DEBUG
    String traceFormat = jsonPtr->asTraceFormat();
    traceFormat.append("\n");
    OutputDebugStringW(traceFormat.charactersWithNullTermination().data());
#endif
}

void ThreadState::incrementMarkedObjectsAge()
{
    for (int i = 0; i < NumberOfHeaps; ++i)
        m_heaps[i]->incrementMarkedObjectsAge();
}
#endif

void ThreadState::pushThreadLocalWeakCallback(void* object, WeakCallback callback)
>>>>>>> miniblink49
{
    CallbackStack::Item* slot = m_threadLocalWeakCallbackStack->allocateEntry();
    *slot = CallbackStack::Item(object, callback);
}

bool ThreadState::popAndInvokeThreadLocalWeakCallback(Visitor* visitor)
{
    ASSERT(checkThread());
    // For weak processing we should never reach orphaned pages since orphaned
    // pages are not traced and thus objects on those pages are never be
    // registered as objects on orphaned pages. We cannot assert this here since
    // we might have an off-heap collection. We assert it in
<<<<<<< HEAD
    // ThreadHeap::pushThreadLocalWeakCallback.
    if (CallbackStack::Item* item = m_threadLocalWeakCallbackStack->pop()) {
=======
    // Heap::pushThreadLocalWeakCallback.
    if (CallbackStack::Item* item = m_threadLocalWeakCallbackStack->pop()) {
        // Note that the thread-local weak processing can be called for
        // an already dead object (for which isHeapObjectAlive(object) can
        // return false). This can happen in the following scenario:
        //
        // 1) Marking runs. A weak callback for an object X is registered
        //    to the thread that created the object X (say, thread P).
        // 2) Marking finishes. All other threads are resumed.
        // 3) The object X becomes unreachable.
        // 4) A next GC hits before the thread P wakes up.
        // 5) Marking runs. The object X is not marked.
        // 6) Marking finishes. All other threads are resumed.
        // 7) The thread P wakes up and invokes pending weak callbacks.
        //    The weak callback for the object X is called, but the object X
        //    is already dead.
        //
        // Even in this case, it is safe to access the object X in the weak
        // callback because it is not yet swept. It is completely wasteful
        // to invoke the weak callback for dead objects but it is just
        // wasteful and safe.
        //
        // TODO(Oilpan): Avoid calling weak callbacks for dead objects.
        // We can do that by checking isHeapObjectAlive(object) before
        // calling the weak callback, but in that case Callback::Item
        // needs to understand T*.
>>>>>>> miniblink49
        item->call(visitor);
        return true;
    }
    return false;
}

void ThreadState::threadLocalWeakProcessing()
{
    ASSERT(checkThread());
    ASSERT(!sweepForbidden());
    TRACE_EVENT0("blink_gc", "ThreadState::threadLocalWeakProcessing");
<<<<<<< HEAD
    double startTime = WTF::currentTimeMS();

    SweepForbiddenScope sweepForbiddenScope(this);
    ScriptForbiddenIfMainThreadScope scriptForbiddenScope;
=======
    SweepForbiddenScope forbiddenScope(this);
    if (isMainThread())
        ScriptForbiddenScope::enter();
>>>>>>> miniblink49

    // Disallow allocation during weak processing.
    // It would be technically safe to allow allocations, but it is unsafe
    // to mutate an object graph in a way in which a dead object gets
    // resurrected or mutate a HashTable (because HashTable's weak processing
    // assumes that the HashTable hasn't been mutated since the latest marking).
    // Due to the complexity, we just forbid allocations.
    NoAllocationScope noAllocationScope(this);

<<<<<<< HEAD
    GCForbiddenScope gcForbiddenScope(this);
    std::unique_ptr<Visitor> visitor = Visitor::create(this, VisitorMarkingMode::WeakProcessing);

    // Perform thread-specific weak processing.
    while (popAndInvokeThreadLocalWeakCallback(visitor.get())) {
    }

    m_threadLocalWeakCallbackStack->decommit();

    if (isMainThread()) {
        double timeForThreadLocalWeakProcessing = WTF::currentTimeMS() - startTime;
        DEFINE_STATIC_LOCAL(
            CustomCountHistogram, timeForWeakHistogram,
            ("BlinkGC.TimeForThreadLocalWeakProcessing", 1, 10 * 1000, 50));
        timeForWeakHistogram.count(timeForThreadLocalWeakProcessing);
    }
}

size_t ThreadState::totalMemorySize()
{
    return m_heap->heapStats().allocatedObjectSize() + m_heap->heapStats().markedObjectSize() + WTF::Partitions::totalSizeOfCommittedPages();
}

size_t ThreadState::estimatedLiveSize(size_t estimationBaseSize,
    size_t sizeAtLastGC)
{
    if (m_heap->heapStats().wrapperCountAtLastGC() == 0) {
        // We'll reach here only before hitting the first GC.
        return 0;
    }

    // (estimated size) = (estimation base size) - (heap size at the last GC) /
    //   (# of persistent handles at the last GC) *
    //     (# of persistent handles collected since the last GC);
    size_t sizeRetainedByCollectedPersistents = static_cast<size_t>(
        1.0 * sizeAtLastGC / m_heap->heapStats().wrapperCountAtLastGC() * m_heap->heapStats().collectedWrapperCount());
    if (estimationBaseSize < sizeRetainedByCollectedPersistents)
        return 0;
    return estimationBaseSize - sizeRetainedByCollectedPersistents;
}

double ThreadState::heapGrowingRate()
{
    size_t currentSize = m_heap->heapStats().allocatedObjectSize() + m_heap->heapStats().markedObjectSize();
    size_t estimatedSize = estimatedLiveSize(
        m_heap->heapStats().markedObjectSizeAtLastCompleteSweep(),
        m_heap->heapStats().markedObjectSizeAtLastCompleteSweep());

    // If the estimatedSize is 0, we set a high growing rate to trigger a GC.
    double growingRate = estimatedSize > 0 ? 1.0 * currentSize / estimatedSize : 100;
    TRACE_COUNTER1(TRACE_DISABLED_BY_DEFAULT("blink_gc"),
        "ThreadState::heapEstimatedSizeKB",
        std::min(estimatedSize / 1024, static_cast<size_t>(INT_MAX)));
    TRACE_COUNTER1(TRACE_DISABLED_BY_DEFAULT("blink_gc"),
        "ThreadState::heapGrowingRate",
        static_cast<int>(100 * growingRate));
    return growingRate;
}

double ThreadState::partitionAllocGrowingRate()
{
    size_t currentSize = WTF::Partitions::totalSizeOfCommittedPages();
    size_t estimatedSize = estimatedLiveSize(
        currentSize, m_heap->heapStats().partitionAllocSizeAtLastGC());

    // If the estimatedSize is 0, we set a high growing rate to trigger a GC.
    double growingRate = estimatedSize > 0 ? 1.0 * currentSize / estimatedSize : 100;
    TRACE_COUNTER1(TRACE_DISABLED_BY_DEFAULT("blink_gc"),
        "ThreadState::partitionAllocEstimatedSizeKB",
        std::min(estimatedSize / 1024, static_cast<size_t>(INT_MAX)));
    TRACE_COUNTER1(TRACE_DISABLED_BY_DEFAULT("blink_gc"),
        "ThreadState::partitionAllocGrowingRate",
        static_cast<int>(100 * growingRate));
    return growingRate;
}

// TODO(haraken): We should improve the GC heuristics. The heuristics affect
// performance significantly.
bool ThreadState::judgeGCThreshold(size_t allocatedObjectSizeThreshold,
    size_t totalMemorySizeThreshold,
    double heapGrowingRateThreshold)
{
    // If the allocated object size or the total memory size is small, don't
    // trigger a GC.
    if (m_heap->heapStats().allocatedObjectSize() < allocatedObjectSizeThreshold || totalMemorySize() < totalMemorySizeThreshold)
        return false;
// If the growing rate of Oilpan's heap or PartitionAlloc is high enough,
// trigger a GC.
#if PRINT_HEAP_STATS
    dataLogF("heapGrowingRate=%.1lf, partitionAllocGrowingRate=%.1lf\n",
        heapGrowingRate(), partitionAllocGrowingRate());
#endif
    return heapGrowingRate() >= heapGrowingRateThreshold || partitionAllocGrowingRate() >= heapGrowingRateThreshold;
}

=======
    MarkingVisitor<Visitor::WeakProcessing> weakProcessingVisitor;

    // Perform thread-specific weak processing.
    while (popAndInvokeThreadLocalWeakCallback(&weakProcessingVisitor)) { }

    if (isMainThread())
        ScriptForbiddenScope::exit();
}

CrossThreadPersistentRegion& ThreadState::crossThreadPersistentRegion()
{
    AtomicallyInitializedStaticReference(CrossThreadPersistentRegion, persistentRegion, new CrossThreadPersistentRegion());
    return persistentRegion;
}

bool ThreadState::shouldForceMemoryPressureGC()
{
    // Avoid potential overflow by truncating to Kb.
    size_t currentObjectSizeKb = (Heap::allocatedObjectSize() + Heap::markedObjectSize() + WTF::Partitions::totalSizeOfCommittedPages()) >> 10;
    if (currentObjectSizeKb < 300 * 1024)
        return false;

    size_t estimatedLiveObjectSizeKb = Heap::estimatedLiveObjectSize() >> 10;
    // If we're consuming too much memory, trigger a conservative GC
    // aggressively. This is a safe guard to avoid OOM.
    return currentObjectSizeKb > (estimatedLiveObjectSizeKb * 3) / 2;
}

// TODO(haraken): We should improve the GC heuristics.
// These heuristics affect performance significantly.
>>>>>>> miniblink49
bool ThreadState::shouldScheduleIdleGC()
{
    if (gcState() != NoGCScheduled)
        return false;
<<<<<<< HEAD
    return judgeGCThreshold(defaultAllocatedObjectSizeThreshold, 1024 * 1024,
        1.5);
}

bool ThreadState::shouldScheduleV8FollowupGC()
{
    return judgeGCThreshold(defaultAllocatedObjectSizeThreshold, 32 * 1024 * 1024,
        1.5);
}

bool ThreadState::shouldSchedulePageNavigationGC(float estimatedRemovalRatio)
{
    // If estimatedRemovalRatio is low we should let IdleGC handle this.
    if (estimatedRemovalRatio < 0.01)
        return false;
    return judgeGCThreshold(defaultAllocatedObjectSizeThreshold, 32 * 1024 * 1024,
        1.5 * (1 - estimatedRemovalRatio));
}

bool ThreadState::shouldForceConservativeGC()
{
    // TODO(haraken): 400% is too large. Lower the heap growing factor.
    return judgeGCThreshold(defaultAllocatedObjectSizeThreshold, 32 * 1024 * 1024,
        5.0);
}

// If we're consuming too much memory, trigger a conservative GC
// aggressively. This is a safe guard to avoid OOM.
bool ThreadState::shouldForceMemoryPressureGC()
{
    if (totalMemorySize() < 300 * 1024 * 1024)
        return false;
    return judgeGCThreshold(0, 0, 1.5);
}

void ThreadState::scheduleV8FollowupGCIfNeeded(BlinkGC::V8GCType gcType)
{
    ASSERT(checkThread());
    ThreadHeap::reportMemoryUsageForTracing();

#if PRINT_HEAP_STATS
    dataLogF("ThreadState::scheduleV8FollowupGCIfNeeded (gcType=%s)\n",
        gcType == BlinkGC::V8MajorGC ? "MajorGC" : "MinorGC");
#endif

    if (isGCForbidden())
        return;

    // This completeSweep() will do nothing in common cases since we've
    // called completeSweep() before V8 starts minor/major GCs.
    completeSweep();
    ASSERT(!isSweepingInProgress());
    ASSERT(!sweepForbidden());

    if ((gcType == BlinkGC::V8MajorGC && shouldForceMemoryPressureGC()) || shouldScheduleV8FollowupGC()) {
#if PRINT_HEAP_STATS
        dataLogF("Scheduled PreciseGC\n");
#endif
        schedulePreciseGC();
        return;
    }
    if (gcType == BlinkGC::V8MajorGC && shouldScheduleIdleGC()) {
#if PRINT_HEAP_STATS
        dataLogF("Scheduled IdleGC\n");
#endif
        scheduleIdleGC();
        return;
    }
}

void ThreadState::willStartV8GC(BlinkGC::V8GCType gcType)
{
    // Finish Oilpan's complete sweeping before running a V8 major GC.
    // This will let the GC collect more V8 objects.
    //
    // TODO(haraken): It's a bit too late for a major GC to schedule
    // completeSweep() here, because gcPrologue for a major GC is called
    // not at the point where the major GC started but at the point where
    // the major GC requests object grouping.
    if (gcType == BlinkGC::V8MajorGC)
        completeSweep();
}

void ThreadState::schedulePageNavigationGCIfNeeded(
    float estimatedRemovalRatio)
{
    ASSERT(checkThread());
    ThreadHeap::reportMemoryUsageForTracing();

#if PRINT_HEAP_STATS
    dataLogF(
        "ThreadState::schedulePageNavigationGCIfNeeded "
        "(estimatedRemovalRatio=%.2lf)\n",
        estimatedRemovalRatio);
#endif

    if (isGCForbidden())
        return;

    // Finish on-going lazy sweeping.
    // TODO(haraken): It might not make sense to force completeSweep() for all
    // page navigations.
    completeSweep();
    ASSERT(!isSweepingInProgress());
    ASSERT(!sweepForbidden());

    if (shouldForceMemoryPressureGC()) {
#if PRINT_HEAP_STATS
        dataLogF("Scheduled MemoryPressureGC\n");
#endif
        collectGarbage(BlinkGC::HeapPointersOnStack, BlinkGC::GCWithoutSweep,
            BlinkGC::MemoryPressureGC);
        return;
    }
    if (shouldSchedulePageNavigationGC(estimatedRemovalRatio)) {
#if PRINT_HEAP_STATS
        dataLogF("Scheduled PageNavigationGC\n");
#endif
        schedulePageNavigationGC();
    }
}

void ThreadState::schedulePageNavigationGC()
{
    ASSERT(checkThread());
    ASSERT(!isSweepingInProgress());
    setGCState(PageNavigationGCScheduled);
=======
#if ENABLE(IDLE_GC)
    // Avoid potential overflow by truncating to Kb.
    size_t allocatedObjectSizeKb = Heap::allocatedObjectSize() >> 10;
    // The estimated size is updated when the main thread finishes lazy
    // sweeping. If this thread reaches here before the main thread finishes
    // lazy sweeping, the thread will use the estimated size of the last GC.
    size_t estimatedLiveObjectSizeKb = Heap::estimatedLiveObjectSize() >> 10;
    // Heap::markedObjectSize() may be underestimated if any thread has not
    // finished completeSweep().
    size_t currentObjectSizeKb = allocatedObjectSizeKb + ((Heap::markedObjectSize() + WTF::Partitions::totalSizeOfCommittedPages()) >> 10);
    // Schedule an idle GC if Oilpan has allocated more than 1 MB since
    // the last GC and the current memory usage is >50% larger than
    // the estimated live memory usage.
    return allocatedObjectSizeKb >= 1024 && currentObjectSizeKb > (estimatedLiveObjectSizeKb * 3) / 2;
#else
    return false;
#endif
}

// TODO(haraken): We should improve the GC heuristics.
// These heuristics affect performance significantly.
bool ThreadState::shouldSchedulePreciseGC()
{
    if (gcState() != NoGCScheduled)
        return false;
#if ENABLE(IDLE_GC)
    return false;
#else
    // Avoid potential overflow by truncating to Kb.
    size_t allocatedObjectSizeKb = Heap::allocatedObjectSize() >> 10;
    // The estimated size is updated when the main thread finishes lazy
    // sweeping. If this thread reaches here before the main thread finishes
    // lazy sweeping, the thread will use the estimated size of the last GC.
    size_t estimatedLiveObjectSizeKb = Heap::estimatedLiveObjectSize() >> 10;
    // Heap::markedObjectSize() may be underestimated if any thread has not
    // finished completeSweep().
    size_t currentObjectSizeKb = allocatedObjectSizeKb + ((Heap::markedObjectSize() + WTF::Partitions::totalSizeOfCommittedPages()) >> 10);
    // Schedule a precise GC if Oilpan has allocated more than 1 MB since
    // the last GC and the current memory usage is >50% larger than
    // the estimated live memory usage.
    return allocatedObjectSizeKb >= 1024 && currentObjectSizeKb > (estimatedLiveObjectSizeKb * 3) / 2;
#endif
}

// TODO(haraken): We should improve the GC heuristics.
// These heuristics affect performance significantly.
bool ThreadState::shouldForceConservativeGC()
{
    if (UNLIKELY(isGCForbidden()))
        return false;

    if (shouldForceMemoryPressureGC())
        return true;

    // Avoid potential overflow by truncating to Kb.
    size_t allocatedObjectSizeKb = Heap::allocatedObjectSize() >> 10;
    // The estimated size is updated when the main thread finishes lazy
    // sweeping. If this thread reaches here before the main thread finishes
    // lazy sweeping, the thread will use the estimated size of the last GC.
    size_t estimatedLiveObjectSizeKb = Heap::estimatedLiveObjectSize() >> 10;
    // Heap::markedObjectSize() may be underestimated if any thread has not
    // finished completeSweep().
    size_t currentObjectSizeKb = allocatedObjectSizeKb + ((Heap::markedObjectSize() + WTF::Partitions::totalSizeOfCommittedPages()) >> 10);
    // Schedule a conservative GC if Oilpan has allocated more than 32 MB since
    // the last GC and the current memory usage is >400% larger than
    // the estimated live memory usage.
    // TODO(haraken): 400% is too large. Lower the heap growing factor.
    return allocatedObjectSizeKb >= 32 * 1024 && currentObjectSizeKb > 5 * estimatedLiveObjectSizeKb;
>>>>>>> miniblink49
}

void ThreadState::scheduleGCIfNeeded()
{
    ASSERT(checkThread());
<<<<<<< HEAD
    ThreadHeap::reportMemoryUsageForTracing();

#if PRINT_HEAP_STATS
    dataLogF("ThreadState::scheduleGCIfNeeded\n");
#endif

    // Allocation is allowed during sweeping, but those allocations should not
    // trigger nested GCs.
    if (isGCForbidden())
        return;

=======
    // Allocation is allowed during sweeping, but those allocations should not
    // trigger nested GCs.
>>>>>>> miniblink49
    if (isSweepingInProgress())
        return;
    ASSERT(!sweepForbidden());

<<<<<<< HEAD
    reportMemoryToV8();

    if (shouldForceMemoryPressureGC()) {
        completeSweep();
        if (shouldForceMemoryPressureGC()) {
#if PRINT_HEAP_STATS
            dataLogF("Scheduled MemoryPressureGC\n");
#endif
            collectGarbage(BlinkGC::HeapPointersOnStack, BlinkGC::GCWithoutSweep,
                BlinkGC::MemoryPressureGC);
            return;
        }
    }

    if (shouldForceConservativeGC()) {
        completeSweep();
        if (shouldForceConservativeGC()) {
#if PRINT_HEAP_STATS
            dataLogF("Scheduled ConservativeGC\n");
#endif
            collectGarbage(BlinkGC::HeapPointersOnStack, BlinkGC::GCWithoutSweep,
                BlinkGC::ConservativeGC);
            return;
        }
    }
    if (shouldScheduleIdleGC()) {
#if PRINT_HEAP_STATS
        dataLogF("Scheduled IdleGC\n");
#endif
        scheduleIdleGC();
        return;
    }
}

ThreadState* ThreadState::fromObject(const void* object)
{
    ASSERT(object);
    BasePage* page = pageFromObject(object);
    ASSERT(page);
    ASSERT(page->arena());
    return page->arena()->getThreadState();
=======
    Heap::reportMemoryUsageForTracing();

    if (shouldForceConservativeGC()) {
        Heap::collectGarbage(HeapPointersOnStack, GCWithoutSweep, Heap::ConservativeGC);
        return;
    }
    if (shouldSchedulePreciseGC())
        schedulePreciseGC();
    else if (shouldScheduleIdleGC())
        scheduleIdleGC();
>>>>>>> miniblink49
}

void ThreadState::performIdleGC(double deadlineSeconds)
{
    ASSERT(checkThread());
    ASSERT(isMainThread());
<<<<<<< HEAD
    ASSERT(Platform::current()->currentThread()->scheduler());
=======
>>>>>>> miniblink49

    if (gcState() != IdleGCScheduled)
        return;

<<<<<<< HEAD
    if (isGCForbidden()) {
        // If GC is forbidden at this point, try again.
        scheduleIdleGC();
        return;
    }

    double idleDeltaInSeconds = deadlineSeconds - monotonicallyIncreasingTime();
    if (idleDeltaInSeconds <= m_heap->heapStats().estimatedMarkingTime() && !Platform::current()->currentThread()->scheduler()->canExceedIdleDeadlineIfRequired()) {
=======
    double idleDeltaInSeconds = deadlineSeconds - Platform::current()->monotonicallyIncreasingTime();
    TRACE_EVENT2("blink_gc", "ThreadState::performIdleGC", "idleDeltaInSeconds", idleDeltaInSeconds, "estimatedMarkingTime", Heap::estimatedMarkingTime());
    if (idleDeltaInSeconds <= Heap::estimatedMarkingTime() && !Platform::current()->currentThread()->scheduler()->canExceedIdleDeadlineIfRequired()) {
>>>>>>> miniblink49
        // If marking is estimated to take longer than the deadline and we can't
        // exceed the deadline, then reschedule for the next idle period.
        scheduleIdleGC();
        return;
    }

<<<<<<< HEAD
    TRACE_EVENT2("blink_gc", "ThreadState::performIdleGC", "idleDeltaInSeconds",
        idleDeltaInSeconds, "estimatedMarkingTime",
        m_heap->heapStats().estimatedMarkingTime());
    collectGarbage(BlinkGC::NoHeapPointersOnStack, BlinkGC::GCWithoutSweep,
        BlinkGC::IdleGC);
=======
    Heap::collectGarbage(NoHeapPointersOnStack, GCWithoutSweep, Heap::IdleGC);
>>>>>>> miniblink49
}

void ThreadState::performIdleLazySweep(double deadlineSeconds)
{
    ASSERT(checkThread());
    ASSERT(isMainThread());

    // If we are not in a sweeping phase, there is nothing to do here.
    if (!isSweepingInProgress())
        return;

    // This check is here to prevent performIdleLazySweep() from being called
    // recursively. I'm not sure if it can happen but it would be safer to have
    // the check just in case.
    if (sweepForbidden())
        return;

<<<<<<< HEAD
    TRACE_EVENT1("blink_gc,devtools.timeline",
        "ThreadState::performIdleLazySweep", "idleDeltaInSeconds",
        deadlineSeconds - monotonicallyIncreasingTime());
=======
    TRACE_EVENT1("blink_gc", "ThreadState::performIdleLazySweep", "idleDeltaInSeconds", deadlineSeconds - Platform::current()->monotonicallyIncreasingTime());
>>>>>>> miniblink49

    bool sweepCompleted = true;
    SweepForbiddenScope scope(this);
    {
<<<<<<< HEAD
        double startTime = WTF::currentTimeMS();
        ScriptForbiddenIfMainThreadScope scriptForbiddenScope;

        for (int i = 0; i < BlinkGC::NumberOfArenas; i++) {
            // lazySweepWithDeadline() won't check the deadline until it sweeps
            // 10 pages. So we give a small slack for safety.
            double slack = 0.001;
            double remainingBudget = deadlineSeconds - slack - monotonicallyIncreasingTime();
            if (remainingBudget <= 0 || !m_arenas[i]->lazySweepWithDeadline(deadlineSeconds)) {
=======
        if (isMainThread())
            ScriptForbiddenScope::enter();

        for (int i = 0; i < NumberOfHeaps; i++) {
            // lazySweepWithDeadline() won't check the deadline until it sweeps
            // 10 pages. So we give a small slack for safety.
            double slack = 0.001;
            double remainingBudget = deadlineSeconds - slack - Platform::current()->monotonicallyIncreasingTime();
            if (remainingBudget <= 0 || !m_heaps[i]->lazySweepWithDeadline(deadlineSeconds)) {
>>>>>>> miniblink49
                // We couldn't finish the sweeping within the deadline.
                // We request another idle task for the remaining sweeping.
                scheduleIdleLazySweep();
                sweepCompleted = false;
                break;
            }
        }

<<<<<<< HEAD
        accumulateSweepingTime(WTF::currentTimeMS() - startTime);
=======
        if (isMainThread())
            ScriptForbiddenScope::exit();
>>>>>>> miniblink49
    }

    if (sweepCompleted)
        postSweep();
}

void ThreadState::scheduleIdleGC()
{
    // TODO(haraken): Idle GC should be supported in worker threads as well.
    if (!isMainThread())
        return;

    if (isSweepingInProgress()) {
        setGCState(SweepingAndIdleGCScheduled);
        return;
    }

<<<<<<< HEAD
    // Some threads (e.g. PPAPI thread) don't have a scheduler.
    if (!Platform::current()->currentThread()->scheduler())
        return;

    Platform::current()->currentThread()->scheduler()->postNonNestableIdleTask(
        BLINK_FROM_HERE,
        WTF::bind(&ThreadState::performIdleGC, WTF::unretained(this)));
=======
    Platform::current()->currentThread()->scheduler()->postNonNestableIdleTask(FROM_HERE, WTF::bind<double>(&ThreadState::performIdleGC, this));
>>>>>>> miniblink49
    setGCState(IdleGCScheduled);
}

void ThreadState::scheduleIdleLazySweep()
{
    // TODO(haraken): Idle complete sweep should be supported in worker threads.
    if (!isMainThread())
        return;

<<<<<<< HEAD
    // Some threads (e.g. PPAPI thread) don't have a scheduler.
    if (!Platform::current()->currentThread()->scheduler())
        return;

    Platform::current()->currentThread()->scheduler()->postIdleTask(
        BLINK_FROM_HERE,
        WTF::bind(&ThreadState::performIdleLazySweep, WTF::unretained(this)));
=======
#if ENABLE(LAZY_SWEEPING)
    Platform::current()->currentThread()->scheduler()->postIdleTask(FROM_HERE, WTF::bind<double>(&ThreadState::performIdleLazySweep, this));
#endif
>>>>>>> miniblink49
}

void ThreadState::schedulePreciseGC()
{
    ASSERT(checkThread());
    if (isSweepingInProgress()) {
        setGCState(SweepingAndPreciseGCScheduled);
        return;
    }

    setGCState(PreciseGCScheduled);
}

namespace {

<<<<<<< HEAD
#define UNEXPECTED_GCSTATE(s)                                       \
    case ThreadState::s:                                            \
        LOG(FATAL) << "Unexpected transition while in GCState " #s; \
        return

    void unexpectedGCState(ThreadState::GCState gcState)
    {
        switch (gcState) {
            UNEXPECTED_GCSTATE(NoGCScheduled);
            UNEXPECTED_GCSTATE(IdleGCScheduled);
            UNEXPECTED_GCSTATE(PreciseGCScheduled);
            UNEXPECTED_GCSTATE(FullGCScheduled);
            UNEXPECTED_GCSTATE(GCRunning);
            UNEXPECTED_GCSTATE(Sweeping);
            UNEXPECTED_GCSTATE(SweepingAndIdleGCScheduled);
            UNEXPECTED_GCSTATE(SweepingAndPreciseGCScheduled);
        default:
            ASSERT_NOT_REACHED();
            return;
        }
    }
=======
#define UNEXPECTED_GCSTATE(s) case ThreadState::s: RELEASE_ASSERT_WITH_MESSAGE(false, "Unexpected transition while in GCState " #s); return

void unexpectedGCState(ThreadState::GCState gcState)
{
    switch (gcState) {
        UNEXPECTED_GCSTATE(NoGCScheduled);
        UNEXPECTED_GCSTATE(IdleGCScheduled);
        UNEXPECTED_GCSTATE(PreciseGCScheduled);
        UNEXPECTED_GCSTATE(FullGCScheduled);
        UNEXPECTED_GCSTATE(GCRunning);
        UNEXPECTED_GCSTATE(EagerSweepScheduled);
        UNEXPECTED_GCSTATE(LazySweepScheduled);
        UNEXPECTED_GCSTATE(Sweeping);
        UNEXPECTED_GCSTATE(SweepingAndIdleGCScheduled);
        UNEXPECTED_GCSTATE(SweepingAndPreciseGCScheduled);
    default:
        ASSERT_NOT_REACHED();
        return;
    }
}
>>>>>>> miniblink49

#undef UNEXPECTED_GCSTATE

} // namespace

<<<<<<< HEAD
#define VERIFY_STATE_TRANSITION(condition) \
    if (UNLIKELY(!(condition)))            \
    unexpectedGCState(m_gcState)
=======
#define VERIFY_STATE_TRANSITION(condition) if (UNLIKELY(!(condition))) unexpectedGCState(m_gcState)
>>>>>>> miniblink49

void ThreadState::setGCState(GCState gcState)
{
    switch (gcState) {
    case NoGCScheduled:
        ASSERT(checkThread());
        VERIFY_STATE_TRANSITION(m_gcState == Sweeping || m_gcState == SweepingAndIdleGCScheduled);
        break;
    case IdleGCScheduled:
    case PreciseGCScheduled:
    case FullGCScheduled:
<<<<<<< HEAD
    case PageNavigationGCScheduled:
        ASSERT(checkThread());
        VERIFY_STATE_TRANSITION(
            m_gcState == NoGCScheduled || m_gcState == IdleGCScheduled || m_gcState == PreciseGCScheduled || m_gcState == FullGCScheduled || m_gcState == PageNavigationGCScheduled || m_gcState == Sweeping || m_gcState == SweepingAndIdleGCScheduled || m_gcState == SweepingAndPreciseGCScheduled);
=======
        ASSERT(checkThread());
        VERIFY_STATE_TRANSITION(m_gcState == NoGCScheduled || m_gcState == IdleGCScheduled || m_gcState == PreciseGCScheduled || m_gcState == FullGCScheduled || m_gcState == SweepingAndIdleGCScheduled || m_gcState == SweepingAndPreciseGCScheduled);
>>>>>>> miniblink49
        completeSweep();
        break;
    case GCRunning:
        ASSERT(!isInGC());
        VERIFY_STATE_TRANSITION(m_gcState != GCRunning);
        break;
<<<<<<< HEAD
    case Sweeping:
        DCHECK(isInGC());
        ASSERT(checkThread());
        VERIFY_STATE_TRANSITION(m_gcState == GCRunning);
        break;
=======
    case EagerSweepScheduled:
    case LazySweepScheduled:
        ASSERT(isInGC());
        VERIFY_STATE_TRANSITION(m_gcState == GCRunning);
        break;
    case Sweeping:
        ASSERT(checkThread());
        VERIFY_STATE_TRANSITION(m_gcState == EagerSweepScheduled || m_gcState == LazySweepScheduled);
        break;
>>>>>>> miniblink49
    case SweepingAndIdleGCScheduled:
    case SweepingAndPreciseGCScheduled:
        ASSERT(checkThread());
        VERIFY_STATE_TRANSITION(m_gcState == Sweeping || m_gcState == SweepingAndIdleGCScheduled || m_gcState == SweepingAndPreciseGCScheduled);
        break;
    default:
        ASSERT_NOT_REACHED();
    }
    m_gcState = gcState;
<<<<<<< HEAD
=======
#if ENABLE(GC_PROFILING)
    if (isMainThread()) {
        TRACE_COUNTER1("blink_gc", "ThreadState::gcState", static_cast<int>(m_gcState));
    }
#endif
>>>>>>> miniblink49
}

#undef VERIFY_STATE_TRANSITION

<<<<<<< HEAD
void ThreadState::runScheduledGC(BlinkGC::StackState stackState)
{
    ASSERT(checkThread());
    if (stackState != BlinkGC::NoHeapPointersOnStack)
        return;

    // If a safe point is entered while initiating a GC, we clearly do
    // not want to do another as part of that -- the safe point is only
=======
ThreadState::GCState ThreadState::gcState() const
{
    return m_gcState;
}

void ThreadState::didV8MajorGC()
{
    ASSERT(checkThread());
    if (isMainThread()) {
        // Lower the estimated live object size because the V8 major GC is
        // expected to have collected a lot of DOM wrappers and dropped
        // references to their DOM objects.
        Heap::setEstimatedLiveObjectSize(Heap::estimatedLiveObjectSize() / 2);

        if (shouldForceMemoryPressureGC()) {
            // Under memory pressure, force a conservative GC.
            Heap::collectGarbage(HeapPointersOnStack, GCWithoutSweep, Heap::ConservativeGC);
            return;
        }
    }
}

void ThreadState::runScheduledGC(StackState stackState)
{
    ASSERT(checkThread());
    if (stackState != NoHeapPointersOnStack)
        return;

    // If a safe point is entered while initiating a GC, we clearly do
    // not want to do another as part that -- the safe point is only
>>>>>>> miniblink49
    // entered after checking if a scheduled GC ought to run first.
    // Prevent that from happening by marking GCs as forbidden while
    // one is initiated and later running.
    if (isGCForbidden())
        return;

    switch (gcState()) {
    case FullGCScheduled:
<<<<<<< HEAD
        collectAllGarbage();
        break;
    case PreciseGCScheduled:
        collectGarbage(BlinkGC::NoHeapPointersOnStack, BlinkGC::GCWithoutSweep,
            BlinkGC::PreciseGC);
        break;
    case PageNavigationGCScheduled:
        collectGarbage(BlinkGC::NoHeapPointersOnStack, BlinkGC::GCWithSweep,
            BlinkGC::PageNavigationGC);
=======
        Heap::collectAllGarbage();
        break;
    case PreciseGCScheduled:
        Heap::collectGarbage(NoHeapPointersOnStack, GCWithoutSweep, Heap::PreciseGC);
>>>>>>> miniblink49
        break;
    case IdleGCScheduled:
        // Idle time GC will be scheduled by Blink Scheduler.
        break;
    default:
        break;
    }
}

<<<<<<< HEAD
void ThreadState::flushHeapDoesNotContainCacheIfNeeded()
{
    if (m_shouldFlushHeapDoesNotContainCache) {
        m_heap->flushHeapDoesNotContainCache();
=======
void ThreadState::prepareRegionTree()
{
    // Add the regions allocated by this thread to the region search tree.
    for (PageMemoryRegion* region : m_allocatedRegionsSinceLastGC)
        Heap::addPageMemoryRegion(region);
    m_allocatedRegionsSinceLastGC.clear();
}

void ThreadState::flushHeapDoesNotContainCacheIfNeeded()
{
    if (m_shouldFlushHeapDoesNotContainCache) {
        Heap::flushHeapDoesNotContainCache();
>>>>>>> miniblink49
        m_shouldFlushHeapDoesNotContainCache = false;
    }
}

void ThreadState::makeConsistentForGC()
{
    ASSERT(isInGC());
    TRACE_EVENT0("blink_gc", "ThreadState::makeConsistentForGC");
<<<<<<< HEAD
    for (int i = 0; i < BlinkGC::NumberOfArenas; ++i)
        m_arenas[i]->makeConsistentForGC();
}

void ThreadState::compact()
{
    if (!heap().compaction()->isCompacting())
        return;

    SweepForbiddenScope scope(this);
    ScriptForbiddenIfMainThreadScope scriptForbiddenScope;
    NoAllocationScope noAllocationScope(this);

    // Compaction is done eagerly and before the mutator threads get
    // to run again. Doing it lazily is problematic, as the mutator's
    // references to live objects could suddenly be invalidated by
    // compaction of a page/heap. We do know all the references to
    // the relocating objects just after marking, but won't later.
    // (e.g., stack references could have been created, new objects
    // created which refer to old collection objects, and so on.)

    // Compact the hash table backing store arena first, it usually has
    // higher fragmentation and is larger.
    //
    // TODO: implement bail out wrt any overall deadline, not compacting
    // the remaining arenas if the time budget has been exceeded.
    heap().compaction()->startThreadCompaction();
    for (int i = BlinkGC::HashTableArenaIndex; i >= BlinkGC::Vector1ArenaIndex;
         --i)
        static_cast<NormalPageArena*>(m_arenas[i])->sweepAndCompact();
    heap().compaction()->finishThreadCompaction();
=======
    for (int i = 0; i < NumberOfHeaps; ++i)
        m_heaps[i]->makeConsistentForGC();
>>>>>>> miniblink49
}

void ThreadState::makeConsistentForMutator()
{
    ASSERT(isInGC());
<<<<<<< HEAD
    for (int i = 0; i < BlinkGC::NumberOfArenas; ++i)
        m_arenas[i]->makeConsistentForMutator();
=======
    for (int i = 0; i < NumberOfHeaps; ++i)
        m_heaps[i]->makeConsistentForMutator();
>>>>>>> miniblink49
}

void ThreadState::preGC()
{
<<<<<<< HEAD
    if (RuntimeEnabledFeatures::traceWrappablesEnabled() && m_isolate && m_performCleanup)
        m_performCleanup(m_isolate);

    ASSERT(!isInGC());
    setGCState(GCRunning);
    makeConsistentForGC();
    flushHeapDoesNotContainCacheIfNeeded();
    clearArenaAges();

    // It is possible, albeit rare, for a thread to be kept
    // at a safepoint across multiple GCs, as resuming all attached
    // threads after the "global" GC phases will contend for the shared
    // safepoint barrier mutexes etc, which can additionally delay
    // a thread. Enough so that another thread may initiate
    // a new GC before this has happened.
    //
    // In which case the parked thread's ThreadState will have unprocessed
    // entries on its local weak callback stack when that later GC goes
    // ahead. Clear out and invalidate the stack now, as the thread
    // should only process callbacks that's found to be reachable by
    // the latest GC, when it eventually gets to next perform
    // thread-local weak processing.
    m_threadLocalWeakCallbackStack->decommit();
    m_threadLocalWeakCallbackStack->commit();
}

void ThreadState::postGC(BlinkGC::GCType gcType)
{
    if (RuntimeEnabledFeatures::traceWrappablesEnabled() && m_invalidateDeadObjectsInWrappersMarkingDeque) {
        m_invalidateDeadObjectsInWrappersMarkingDeque(m_isolate);
    }

    ASSERT(isInGC());
    for (int i = 0; i < BlinkGC::NumberOfArenas; i++)
        m_arenas[i]->prepareForSweep();

    if (gcType == BlinkGC::TakeSnapshot) {
=======
    ASSERT(!isInGC());
    setGCState(GCRunning);
    makeConsistentForGC();
    prepareRegionTree();
    flushHeapDoesNotContainCacheIfNeeded();
    clearHeapAges();
}

void ThreadState::postGC(GCType gcType)
{
    ASSERT(isInGC());

#if ENABLE(GC_PROFILING)
    // We snapshot the heap prior to sweeping to get numbers for both resources
    // that have been allocated since the last GC and for resources that are
    // going to be freed.
    bool gcTracingEnabled = false;
    TRACE_EVENT_CATEGORY_GROUP_ENABLED("blink_gc", &gcTracingEnabled);

    if (gcTracingEnabled) {
        bool disabledByDefaultGCTracingEnabled;
        TRACE_EVENT_CATEGORY_GROUP_ENABLED(TRACE_DISABLED_BY_DEFAULT("blink_gc"), &disabledByDefaultGCTracingEnabled);

        snapshot();
        if (disabledByDefaultGCTracingEnabled)
            collectAndReportMarkSweepStats();
        incrementMarkedObjectsAge();
    }
#endif

    for (int i = 0; i < NumberOfHeaps; i++)
        m_heaps[i]->prepareForSweep();

    if (gcType == GCWithSweep) {
        setGCState(EagerSweepScheduled);
    } else if (gcType == GCWithoutSweep) {
        setGCState(LazySweepScheduled);
    } else {
>>>>>>> miniblink49
        takeSnapshot(SnapshotType::HeapSnapshot);

        // This unmarks all marked objects and marks all unmarked objects dead.
        makeConsistentForMutator();

        takeSnapshot(SnapshotType::FreelistSnapshot);

        // Force setting NoGCScheduled to circumvent checkThread()
        // in setGCState().
        m_gcState = NoGCScheduled;
<<<<<<< HEAD
        return;
    }

    ASSERT(checkThread());

    threadLocalWeakProcessing();
}

void ThreadState::preSweep(BlinkGC::GCType gcType)
{
    if (gcState() == NoGCScheduled)
        return;
=======
    }
}

void ThreadState::preSweep()
{
    ASSERT(checkThread());
    if (gcState() != EagerSweepScheduled && gcState() != LazySweepScheduled)
        return;

    threadLocalWeakProcessing();

#if ENABLE(LAZY_SWEEPING)
    GCState previousGCState = gcState();
#endif
>>>>>>> miniblink49
    // We have to set the GCState to Sweeping before calling pre-finalizers
    // to disallow a GC during the pre-finalizers.
    setGCState(Sweeping);

    // Allocation is allowed during the pre-finalizers and destructors.
    // However, they must not mutate an object graph in a way in which
    // a dead object gets resurrected.
    invokePreFinalizers();

<<<<<<< HEAD
    m_accumulatedSweepingTime = 0;

    eagerSweep();

    // Any sweep compaction must happen after pre-finalizers and eager
    // sweeping, as it will finalize dead objects in compactable arenas
    // (e.g., backing stores for container objects.)
    //
    // As per-contract for prefinalizers, those finalizable objects must
    // still be accessible when the prefinalizer runs, hence we cannot
    // schedule compaction until those have run. Similarly for eager sweeping.
    compact();

#if defined(ADDRESS_SANITIZER)
    poisonAllHeaps();
#endif

    if (gcType == BlinkGC::GCWithSweep) {
        // Eager sweeping should happen only in testing.
        completeSweep();
    } else {
        DCHECK(gcType == BlinkGC::GCWithoutSweep);
        // The default behavior is lazy sweeping.
        scheduleIdleLazySweep();
    }
=======
#if defined(ADDRESS_SANITIZER)
    poisonEagerHeap(SetPoison);
#endif

#if ENABLE(LAZY_SWEEPING)
    if (previousGCState == EagerSweepScheduled) {
        // Eager sweeping should happen only in testing.
        eagerSweep();
#if defined(ADDRESS_SANITIZER)
        poisonAllHeaps();
#endif
        completeSweep();
    } else {
        // The default behavior is lazy sweeping.
        eagerSweep();
#if defined(ADDRESS_SANITIZER)
        poisonAllHeaps();
#endif
        scheduleIdleLazySweep();
    }
#else
    completeSweep();
#endif

#if ENABLE(GC_PROFILING)
    snapshotFreeListIfNecessary();
#endif
>>>>>>> miniblink49
}

#if defined(ADDRESS_SANITIZER)
void ThreadState::poisonAllHeaps()
{
<<<<<<< HEAD
    CrossThreadPersistentRegion::LockScope persistentLock(
        ProcessHeap::crossThreadPersistentRegion());
    // Poisoning all unmarked objects in the other arenas.
    for (int i = 1; i < BlinkGC::NumberOfArenas; i++)
        m_arenas[i]->poisonArena();
    // CrossThreadPersistents in unmarked objects may be accessed from other
    // threads (e.g. in CrossThreadPersistentRegion::shouldTracePersistent) and
    // that would be fine.
    ProcessHeap::crossThreadPersistentRegion().unpoisonCrossThreadPersistents();
}

void ThreadState::poisonEagerArena()
{
    CrossThreadPersistentRegion::LockScope persistentLock(
        ProcessHeap::crossThreadPersistentRegion());
    m_arenas[BlinkGC::EagerSweepArenaIndex]->poisonArena();
    // CrossThreadPersistents in unmarked objects may be accessed from other
    // threads (e.g. in CrossThreadPersistentRegion::shouldTracePersistent) and
    // that would be fine.
    ProcessHeap::crossThreadPersistentRegion().unpoisonCrossThreadPersistents();
=======
    // TODO(Oilpan): enable the poisoning always.
#if ENABLE(OILPAN)
    // Unpoison the live objects remaining in the eager heaps..
    poisonEagerHeap(ClearPoison);
    // ..along with poisoning all unmarked objects in the other heaps.
    for (int i = 1; i < NumberOfHeaps; i++)
        m_heaps[i]->poisonHeap(UnmarkedOnly, SetPoison);
#endif
}

void ThreadState::poisonEagerHeap(Poisoning poisoning)
{
    // TODO(Oilpan): enable the poisoning always.
#if ENABLE(OILPAN)
    m_heaps[EagerSweepHeapIndex]->poisonHeap(MarkedAndUnmarked, poisoning);
#endif
>>>>>>> miniblink49
}
#endif

void ThreadState::eagerSweep()
{
<<<<<<< HEAD
#if defined(ADDRESS_SANITIZER)
    poisonEagerArena();
#endif
=======
>>>>>>> miniblink49
    ASSERT(checkThread());
    // Some objects need to be finalized promptly and cannot be handled
    // by lazy sweeping. Keep those in a designated heap and sweep it
    // eagerly.
    ASSERT(isSweepingInProgress());

    // Mirroring the completeSweep() condition; see its comment.
    if (sweepForbidden())
        return;

    SweepForbiddenScope scope(this);
<<<<<<< HEAD
    ScriptForbiddenIfMainThreadScope scriptForbiddenScope;

    double startTime = WTF::currentTimeMS();
    m_arenas[BlinkGC::EagerSweepArenaIndex]->completeSweep();
    accumulateSweepingTime(WTF::currentTimeMS() - startTime);
=======
    {
        if (isMainThread())
            ScriptForbiddenScope::enter();

        m_heaps[EagerSweepHeapIndex]->completeSweep();

        if (isMainThread())
            ScriptForbiddenScope::exit();
    }
>>>>>>> miniblink49
}

void ThreadState::completeSweep()
{
    ASSERT(checkThread());
    // If we are not in a sweeping phase, there is nothing to do here.
    if (!isSweepingInProgress())
        return;

    // completeSweep() can be called recursively if finalizers can allocate
    // memory and the allocation triggers completeSweep(). This check prevents
    // the sweeping from being executed recursively.
    if (sweepForbidden())
        return;

    SweepForbiddenScope scope(this);
    {
<<<<<<< HEAD
        ScriptForbiddenIfMainThreadScope scriptForbiddenScope;

        TRACE_EVENT0("blink_gc,devtools.timeline", "ThreadState::completeSweep");
        double startTime = WTF::currentTimeMS();

        static_assert(BlinkGC::EagerSweepArenaIndex == 0,
            "Eagerly swept arenas must be processed first.");
        for (int i = 0; i < BlinkGC::NumberOfArenas; i++)
            m_arenas[i]->completeSweep();

        double timeForCompleteSweep = WTF::currentTimeMS() - startTime;
        accumulateSweepingTime(timeForCompleteSweep);

        if (isMainThread()) {
            DEFINE_STATIC_LOCAL(CustomCountHistogram, completeSweepHistogram,
                ("BlinkGC.CompleteSweep", 1, 10 * 1000, 50));
            completeSweepHistogram.count(timeForCompleteSweep);
        }
=======
        if (isMainThread())
            ScriptForbiddenScope::enter();

        TRACE_EVENT0("blink_gc", "ThreadState::completeSweep");
        double timeStamp = WTF::currentTimeMS();

        static_assert(EagerSweepHeapIndex == 0, "Eagerly swept heaps must be processed first.");
        for (int i = 0; i < NumberOfHeaps; i++)
            m_heaps[i]->completeSweep();

        Platform::current()->histogramCustomCounts("BlinkGC.CompleteSweep", WTF::currentTimeMS() - timeStamp, 0, 10 * 1000, 50);

        if (isMainThread())
            ScriptForbiddenScope::exit();
>>>>>>> miniblink49
    }

    postSweep();
}

void ThreadState::postSweep()
{
    ASSERT(checkThread());
<<<<<<< HEAD
    ThreadHeap::reportMemoryUsageForTracing();

    if (isMainThread()) {
        double collectionRate = 0;
        if (m_heap->heapStats().objectSizeAtLastGC() > 0)
            collectionRate = 1 - 1.0 * m_heap->heapStats().markedObjectSize() / m_heap->heapStats().objectSizeAtLastGC();
        TRACE_COUNTER1(TRACE_DISABLED_BY_DEFAULT("blink_gc"),
            "ThreadState::collectionRate",
            static_cast<int>(100 * collectionRate));

#if PRINT_HEAP_STATS
        dataLogF("ThreadState::postSweep (collectionRate=%d%%)\n",
            static_cast<int>(100 * collectionRate));
#endif

        // ThreadHeap::markedObjectSize() may be underestimated here if any other
        // thread has not yet finished lazy sweeping.
        m_heap->heapStats().setMarkedObjectSizeAtLastCompleteSweep(
            m_heap->heapStats().markedObjectSize());

        DEFINE_STATIC_LOCAL(CustomCountHistogram, objectSizeBeforeGCHistogram,
            ("BlinkGC.ObjectSizeBeforeGC", 1, 4 * 1024 * 1024, 50));
        objectSizeBeforeGCHistogram.count(m_heap->heapStats().objectSizeAtLastGC() / 1024);
        DEFINE_STATIC_LOCAL(CustomCountHistogram, objectSizeAfterGCHistogram,
            ("BlinkGC.ObjectSizeAfterGC", 1, 4 * 1024 * 1024, 50));
        objectSizeAfterGCHistogram.count(m_heap->heapStats().markedObjectSize() / 1024);
        DEFINE_STATIC_LOCAL(CustomCountHistogram, collectionRateHistogram,
            ("BlinkGC.CollectionRate", 1, 100, 20));
        collectionRateHistogram.count(static_cast<int>(100 * collectionRate));
        DEFINE_STATIC_LOCAL(
            CustomCountHistogram, timeForSweepHistogram,
            ("BlinkGC.TimeForSweepingAllObjects", 1, 10 * 1000, 50));
        timeForSweepHistogram.count(m_accumulatedSweepingTime);

#define COUNT_COLLECTION_RATE_HISTOGRAM_BY_GC_REASON(GCReason)   \
    case BlinkGC::GCReason: {                                    \
        DEFINE_STATIC_LOCAL(CustomCountHistogram, histogram,     \
            ("BlinkGC.CollectionRate_" #GCReason, 1, 100, 20));  \
        histogram.count(static_cast<int>(100 * collectionRate)); \
        break;                                                   \
    }

        switch (m_heap->lastGCReason()) {
            COUNT_COLLECTION_RATE_HISTOGRAM_BY_GC_REASON(IdleGC)
            COUNT_COLLECTION_RATE_HISTOGRAM_BY_GC_REASON(PreciseGC)
            COUNT_COLLECTION_RATE_HISTOGRAM_BY_GC_REASON(ConservativeGC)
            COUNT_COLLECTION_RATE_HISTOGRAM_BY_GC_REASON(ForcedGC)
            COUNT_COLLECTION_RATE_HISTOGRAM_BY_GC_REASON(MemoryPressureGC)
            COUNT_COLLECTION_RATE_HISTOGRAM_BY_GC_REASON(PageNavigationGC)
        default:
            break;
        }
=======
    Heap::reportMemoryUsageForTracing();

    if (isMainThread()) {
        // At the point where the main thread finishes lazy sweeping,
        // we estimate the live object size. Heap::markedObjectSize()
        // may be underestimated if any other thread has not finished
        // lazy sweeping.
        Heap::setEstimatedLiveObjectSize(Heap::markedObjectSize() + Heap::externalObjectSizeAtLastGC());
>>>>>>> miniblink49
    }

    switch (gcState()) {
    case Sweeping:
        setGCState(NoGCScheduled);
        break;
    case SweepingAndPreciseGCScheduled:
        setGCState(PreciseGCScheduled);
        break;
    case SweepingAndIdleGCScheduled:
        setGCState(NoGCScheduled);
        scheduleIdleGC();
        break;
    default:
        ASSERT_NOT_REACHED();
    }
}

<<<<<<< HEAD
void ThreadState::prepareForThreadStateTermination()
{
    ASSERT(checkThread());
    for (int i = 0; i < BlinkGC::NumberOfArenas; ++i)
        m_arenas[i]->prepareHeapForTermination();
}

#if DCHECK_IS_ON()
BasePage* ThreadState::findPageFromAddress(Address address)
{
    for (int i = 0; i < BlinkGC::NumberOfArenas; ++i) {
        if (BasePage* page = m_arenas[i]->findPageFromAddress(address))
=======
void ThreadState::prepareHeapForTermination()
{
    ASSERT(checkThread());
    for (int i = 0; i < NumberOfHeaps; ++i)
        m_heaps[i]->prepareHeapForTermination();
}

#if ENABLE(ASSERT) || ENABLE(GC_PROFILING)
BasePage* ThreadState::findPageFromAddress(Address address)
{
    for (int i = 0; i < NumberOfHeaps; ++i) {
        if (BasePage* page = m_heaps[i]->findPageFromAddress(address))
>>>>>>> miniblink49
            return page;
    }
    return nullptr;
}
#endif

size_t ThreadState::objectPayloadSizeForTesting()
{
    size_t objectPayloadSize = 0;
<<<<<<< HEAD
    for (int i = 0; i < BlinkGC::NumberOfArenas; ++i)
        objectPayloadSize += m_arenas[i]->objectPayloadSizeForTesting();
    return objectPayloadSize;
}

void ThreadState::safePoint(BlinkGC::StackState stackState)
{
    ASSERT(checkThread());
    ThreadHeap::reportMemoryUsageForTracing();

=======
    for (int i = 0; i < NumberOfHeaps; ++i)
        objectPayloadSize += m_heaps[i]->objectPayloadSizeForTesting();
    return objectPayloadSize;
}

bool ThreadState::stopThreads()
{
    return s_safePointBarrier->parkOthers();
}

void ThreadState::resumeThreads()
{
    s_safePointBarrier->resumeOthers();
}

void ThreadState::safePoint(StackState stackState)
{
    ASSERT(checkThread());
>>>>>>> miniblink49
    runScheduledGC(stackState);
    ASSERT(!m_atSafePoint);
    m_stackState = stackState;
    m_atSafePoint = true;
<<<<<<< HEAD
    m_heap->checkAndPark(this, nullptr);
    m_atSafePoint = false;
    m_stackState = BlinkGC::HeapPointersOnStack;
}

#ifdef ADDRESS_SANITIZER
// When we are running under AddressSanitizer with
// detect_stack_use_after_return=1 then stack marker obtained from
// SafePointScope will point into a fake stack.  Detect this case by checking if
// it falls in between current stack frame and stack start and use an arbitrary
// high enough value for it.  Don't adjust stack marker in any other case to
// match behavior of code running without AddressSanitizer.
NO_SANITIZE_ADDRESS static void* adjustScopeMarkerForAdressSanitizer(
    void* scopeMarker)
{
    Address start = reinterpret_cast<Address>(WTF::getStackStart());
=======
    s_safePointBarrier->checkAndPark(this);
    m_atSafePoint = false;
    m_stackState = HeapPointersOnStack;
    preSweep();
}

#ifdef ADDRESS_SANITIZER
// When we are running under AddressSanitizer with detect_stack_use_after_return=1
// then stack marker obtained from SafePointScope will point into a fake stack.
// Detect this case by checking if it falls in between current stack frame
// and stack start and use an arbitrary high enough value for it.
// Don't adjust stack marker in any other case to match behavior of code running
// without AddressSanitizer.
NO_SANITIZE_ADDRESS static void* adjustScopeMarkerForAdressSanitizer(void* scopeMarker)
{
    Address start = reinterpret_cast<Address>(StackFrameDepth::getStackStart());
>>>>>>> miniblink49
    Address end = reinterpret_cast<Address>(&start);
    RELEASE_ASSERT(end < start);

    if (end <= scopeMarker && scopeMarker < start)
        return scopeMarker;

    // 256 is as good an approximation as any else.
    const size_t bytesToCopy = sizeof(Address) * 256;
    if (static_cast<size_t>(start - end) < bytesToCopy)
        return start;

    return end + bytesToCopy;
}
#endif

<<<<<<< HEAD
void ThreadState::enterSafePoint(BlinkGC::StackState stackState,
    void* scopeMarker)
{
    ASSERT(checkThread());
#ifdef ADDRESS_SANITIZER
    if (stackState == BlinkGC::HeapPointersOnStack)
        scopeMarker = adjustScopeMarkerForAdressSanitizer(scopeMarker);
#endif
    ASSERT(stackState == BlinkGC::NoHeapPointersOnStack || scopeMarker);
=======
void ThreadState::enterSafePoint(StackState stackState, void* scopeMarker)
{
    ASSERT(checkThread());
#ifdef ADDRESS_SANITIZER
    if (stackState == HeapPointersOnStack)
        scopeMarker = adjustScopeMarkerForAdressSanitizer(scopeMarker);
#endif
    ASSERT(stackState == NoHeapPointersOnStack || scopeMarker);
>>>>>>> miniblink49
    runScheduledGC(stackState);
    ASSERT(!m_atSafePoint);
    m_atSafePoint = true;
    m_stackState = stackState;
    m_safePointScopeMarker = scopeMarker;
<<<<<<< HEAD
    m_heap->enterSafePoint(this);
=======
    s_safePointBarrier->enterSafePoint(this);
>>>>>>> miniblink49
}

void ThreadState::leaveSafePoint(SafePointAwareMutexLocker* locker)
{
    ASSERT(checkThread());
    ASSERT(m_atSafePoint);
<<<<<<< HEAD
    m_heap->leaveSafePoint(this, locker);
    m_atSafePoint = false;
    m_stackState = BlinkGC::HeapPointersOnStack;
    clearSafePointScopeMarker();
}

void ThreadState::reportMemoryToV8()
{
    if (!m_isolate)
        return;

    size_t currentHeapSize = m_allocatedObjectSize + m_markedObjectSize;
    int64_t diff = static_cast<int64_t>(currentHeapSize) - static_cast<int64_t>(m_reportedMemoryToV8);
    m_isolate->AdjustAmountOfExternalAllocatedMemory(diff);
    m_reportedMemoryToV8 = currentHeapSize;
}

void ThreadState::resetHeapCounters()
{
    m_allocatedObjectSize = 0;
    m_markedObjectSize = 0;
}

void ThreadState::increaseAllocatedObjectSize(size_t delta)
{
    m_allocatedObjectSize += delta;
    m_heap->heapStats().increaseAllocatedObjectSize(delta);
}

void ThreadState::decreaseAllocatedObjectSize(size_t delta)
{
    m_allocatedObjectSize -= delta;
    m_heap->heapStats().decreaseAllocatedObjectSize(delta);
}

void ThreadState::increaseMarkedObjectSize(size_t delta)
{
    m_markedObjectSize += delta;
    m_heap->heapStats().increaseMarkedObjectSize(delta);
=======
    s_safePointBarrier->leaveSafePoint(this, locker);
    m_atSafePoint = false;
    m_stackState = HeapPointersOnStack;
    clearSafePointScopeMarker();
    preSweep();
>>>>>>> miniblink49
}

void ThreadState::copyStackUntilSafePointScope()
{
<<<<<<< HEAD
    if (!m_safePointScopeMarker || m_stackState == BlinkGC::NoHeapPointersOnStack)
=======
    if (!m_safePointScopeMarker || m_stackState == NoHeapPointersOnStack)
>>>>>>> miniblink49
        return;

    Address* to = reinterpret_cast<Address*>(m_safePointScopeMarker);
    Address* from = reinterpret_cast<Address*>(m_endOfStack);
    RELEASE_ASSERT(from < to);
    RELEASE_ASSERT(to <= reinterpret_cast<Address*>(m_startOfStack));
    size_t slotCount = static_cast<size_t>(to - from);
<<<<<<< HEAD
// Catch potential performance issues.
=======
    // Catch potential performance issues.
>>>>>>> miniblink49
#if defined(LEAK_SANITIZER) || defined(ADDRESS_SANITIZER)
    // ASan/LSan use more space on the stack and we therefore
    // increase the allowed stack copying for those builds.
    ASSERT(slotCount < 2048);
#else
    ASSERT(slotCount < 1024);
#endif

    ASSERT(!m_safePointStackCopy.size());
    m_safePointStackCopy.resize(slotCount);
    for (size_t i = 0; i < slotCount; ++i) {
        m_safePointStackCopy[i] = from[i];
    }
}

<<<<<<< HEAD
void ThreadState::addInterruptor(
    std::unique_ptr<BlinkGCInterruptor> interruptor)
{
    ASSERT(checkThread());
    SafePointScope scope(BlinkGC::HeapPointersOnStack);
    {
        MutexLocker locker(m_heap->threadAttachMutex());
        m_interruptors.push_back(std::move(interruptor));
    }
}

void ThreadState::registerStaticPersistentNode(
    PersistentNode* node,
    PersistentClearCallback callback)
{
#if defined(LEAK_SANITIZER)
    if (m_disabledStaticPersistentsRegistration)
        return;
#endif

    ASSERT(!m_staticPersistents.contains(node));
    m_staticPersistents.add(node, callback);
}

void ThreadState::releaseStaticPersistentNodes()
{
    HashMap<PersistentNode*, ThreadState::PersistentClearCallback>
        staticPersistents;
    staticPersistents.swap(m_staticPersistents);

    PersistentRegion* persistentRegion = getPersistentRegion();
    for (const auto& it : staticPersistents)
        persistentRegion->releasePersistentNode(it.key, it.value);
}

void ThreadState::freePersistentNode(PersistentNode* persistentNode)
{
    PersistentRegion* persistentRegion = getPersistentRegion();
    persistentRegion->freePersistentNode(persistentNode);
    // Do not allow static persistents to be freed before
    // they're all released in releaseStaticPersistentNodes().
    //
    // There's no fundamental reason why this couldn't be supported,
    // but no known use for it.
    ASSERT(!m_staticPersistents.contains(persistentNode));
}

#if defined(LEAK_SANITIZER)
void ThreadState::enterStaticReferenceRegistrationDisabledScope()
{
    m_disabledStaticPersistentsRegistration++;
}

void ThreadState::leaveStaticReferenceRegistrationDisabledScope()
{
    ASSERT(m_disabledStaticPersistentsRegistration);
    m_disabledStaticPersistentsRegistration--;
}
#endif

void ThreadState::lockThreadAttachMutex()
{
    m_heap->threadAttachMutex().lock();
=======
void ThreadState::addInterruptor(Interruptor* interruptor)
{
    ASSERT(checkThread());
    SafePointScope scope(HeapPointersOnStack);
    {
        MutexLocker locker(threadAttachMutex());
        m_interruptors.append(interruptor);
    }
}

void ThreadState::removeInterruptor(Interruptor* interruptor)
{
    ASSERT(checkThread());
    SafePointScope scope(HeapPointersOnStack);
    {
        MutexLocker locker(threadAttachMutex());
        size_t index = m_interruptors.find(interruptor);
        RELEASE_ASSERT(index != kNotFound);
        m_interruptors.remove(index);
    }
}

void ThreadState::Interruptor::onInterrupted()
{
    ThreadState* state = ThreadState::current();
    ASSERT(state);
    ASSERT(!state->isAtSafePoint());
    state->safePoint(HeapPointersOnStack);
}

ThreadState::AttachedThreadStateSet& ThreadState::attachedThreads()
{
    DEFINE_STATIC_LOCAL(AttachedThreadStateSet, threads, ());
    return threads;
}

void ThreadState::lockThreadAttachMutex()
{
    threadAttachMutex().lock();
>>>>>>> miniblink49
}

void ThreadState::unlockThreadAttachMutex()
{
<<<<<<< HEAD
    m_heap->threadAttachMutex().unlock();
=======
    threadAttachMutex().unlock();
>>>>>>> miniblink49
}

void ThreadState::invokePreFinalizers()
{
    ASSERT(checkThread());
    ASSERT(!sweepForbidden());
    TRACE_EVENT0("blink_gc", "ThreadState::invokePreFinalizers");

<<<<<<< HEAD
    double startTime = WTF::currentTimeMS();
    if (!m_orderedPreFinalizers.isEmpty()) {
        SweepForbiddenScope sweepForbidden(this);
        ScriptForbiddenIfMainThreadScope scriptForbidden;

        // Call the prefinalizers in the opposite order to their registration.
        //
        // The prefinalizer callback wrapper returns |true| when its associated
        // object is unreachable garbage and the prefinalizer callback has run.
        // The registered prefinalizer entry must then be removed and deleted.
        //
        auto it = --m_orderedPreFinalizers.end();
        bool done;
        do {
            auto entry = it;
            done = it == m_orderedPreFinalizers.begin();
            if (!done)
                --it;
            if ((entry->second)(entry->first))
                m_orderedPreFinalizers.remove(entry);
        } while (!done);
    }
    if (isMainThread()) {
        double timeForInvokingPreFinalizers = WTF::currentTimeMS() - startTime;
        DEFINE_STATIC_LOCAL(
            CustomCountHistogram, preFinalizersHistogram,
            ("BlinkGC.TimeForInvokingPreFinalizers", 1, 10 * 1000, 50));
        preFinalizersHistogram.count(timeForInvokingPreFinalizers);
    }
}

void ThreadState::clearArenaAges()
{
    memset(m_arenaAges, 0, sizeof(size_t) * BlinkGC::NumberOfArenas);
    memset(m_likelyToBePromptlyFreed.get(), 0,
        sizeof(int) * likelyToBePromptlyFreedArraySize);
    m_currentArenaAges = 0;
}

int ThreadState::arenaIndexOfVectorArenaLeastRecentlyExpanded(
    int beginArenaIndex,
    int endArenaIndex)
{
    size_t minArenaAge = m_arenaAges[beginArenaIndex];
    int arenaIndexWithMinArenaAge = beginArenaIndex;
    for (int arenaIndex = beginArenaIndex + 1; arenaIndex <= endArenaIndex;
         arenaIndex++) {
        if (m_arenaAges[arenaIndex] < minArenaAge) {
            minArenaAge = m_arenaAges[arenaIndex];
            arenaIndexWithMinArenaAge = arenaIndex;
        }
    }
    ASSERT(isVectorArenaIndex(arenaIndexWithMinArenaAge));
    return arenaIndexWithMinArenaAge;
}

BaseArena* ThreadState::expandedVectorBackingArena(size_t gcInfoIndex)
=======
    if (isMainThread())
        ScriptForbiddenScope::enter();

    SweepForbiddenScope forbiddenScope(this);
    Vector<PreFinalizer> deadPreFinalizers;
    // Call the pre-finalizers in the reverse order in which they
    // are registered.
    for (auto it = m_orderedPreFinalizers.rbegin(); it != m_orderedPreFinalizers.rend(); ++it) {
        if (!(it->second)(it->first))
            continue;
        deadPreFinalizers.append(*it);
    }
    // FIXME: removeAll is inefficient.  It can shrink repeatedly.
    m_orderedPreFinalizers.removeAll(deadPreFinalizers);

    if (isMainThread())
        ScriptForbiddenScope::exit();
}

void ThreadState::clearHeapAges()
{
    memset(m_heapAges, 0, sizeof(size_t) * NumberOfHeaps);
    memset(m_likelyToBePromptlyFreed.get(), 0, sizeof(int) * likelyToBePromptlyFreedArraySize);
    m_currentHeapAges = 0;
}

int ThreadState::heapIndexOfVectorHeapLeastRecentlyExpanded(int beginHeapIndex, int endHeapIndex)
{
    size_t minHeapAge = m_heapAges[beginHeapIndex];
    int heapIndexWithMinHeapAge = beginHeapIndex;
    for (int heapIndex = beginHeapIndex + 1; heapIndex <= endHeapIndex; heapIndex++) {
        if (m_heapAges[heapIndex] < minHeapAge) {
            minHeapAge = m_heapAges[heapIndex];
            heapIndexWithMinHeapAge = heapIndex;
        }
    }
    ASSERT(isVectorHeapIndex(heapIndexWithMinHeapAge));
    return heapIndexWithMinHeapAge;
}

BaseHeap* ThreadState::expandedVectorBackingHeap(size_t gcInfoIndex)
>>>>>>> miniblink49
{
    ASSERT(checkThread());
    size_t entryIndex = gcInfoIndex & likelyToBePromptlyFreedArrayMask;
    --m_likelyToBePromptlyFreed[entryIndex];
<<<<<<< HEAD
    int arenaIndex = m_vectorBackingArenaIndex;
    m_arenaAges[arenaIndex] = ++m_currentArenaAges;
    m_vectorBackingArenaIndex = arenaIndexOfVectorArenaLeastRecentlyExpanded(
        BlinkGC::Vector1ArenaIndex, BlinkGC::Vector4ArenaIndex);
    return m_arenas[arenaIndex];
}

void ThreadState::allocationPointAdjusted(int arenaIndex)
{
    m_arenaAges[arenaIndex] = ++m_currentArenaAges;
    if (m_vectorBackingArenaIndex == arenaIndex)
        m_vectorBackingArenaIndex = arenaIndexOfVectorArenaLeastRecentlyExpanded(
            BlinkGC::Vector1ArenaIndex, BlinkGC::Vector4ArenaIndex);
=======
    int heapIndex = m_vectorBackingHeapIndex;
    m_heapAges[heapIndex] = ++m_currentHeapAges;
    m_vectorBackingHeapIndex = heapIndexOfVectorHeapLeastRecentlyExpanded(Vector1HeapIndex, Vector4HeapIndex);
    return m_heaps[heapIndex];
}

void ThreadState::allocationPointAdjusted(int heapIndex)
{
    m_heapAges[heapIndex] = ++m_currentHeapAges;
    if (m_vectorBackingHeapIndex == heapIndex)
        m_vectorBackingHeapIndex = heapIndexOfVectorHeapLeastRecentlyExpanded(Vector1HeapIndex, Vector4HeapIndex);
>>>>>>> miniblink49
}

void ThreadState::promptlyFreed(size_t gcInfoIndex)
{
    ASSERT(checkThread());
    size_t entryIndex = gcInfoIndex & likelyToBePromptlyFreedArrayMask;
<<<<<<< HEAD
    // See the comment in vectorBackingArena() for why this is +3.
=======
    // See the comment in vectorBackingHeap() for why this is +3.
>>>>>>> miniblink49
    m_likelyToBePromptlyFreed[entryIndex] += 3;
}

void ThreadState::takeSnapshot(SnapshotType type)
{
    ASSERT(isInGC());

<<<<<<< HEAD
    // 0 is used as index for freelist entries. Objects are indexed 1 to
    // gcInfoIndex.
    GCSnapshotInfo info(GCInfoTable::gcInfoIndex() + 1);
    String threadDumpName = String::format("blink_gc/thread_%lu",
        static_cast<unsigned long>(m_thread));
    const String heapsDumpName = threadDumpName + "/heaps";
    const String classesDumpName = threadDumpName + "/classes";

    int numberOfHeapsReported = 0;
#define SNAPSHOT_HEAP(ArenaType)                                            \
    {                                                                       \
        numberOfHeapsReported++;                                            \
        switch (type) {                                                     \
        case SnapshotType::HeapSnapshot:                                    \
            m_arenas[BlinkGC::ArenaType##ArenaIndex]->takeSnapshot(         \
                heapsDumpName + "/" #ArenaType, info);                      \
            break;                                                          \
        case SnapshotType::FreelistSnapshot:                                \
            m_arenas[BlinkGC::ArenaType##ArenaIndex]->takeFreelistSnapshot( \
                heapsDumpName + "/" #ArenaType);                            \
            break;                                                          \
        default:                                                            \
            ASSERT_NOT_REACHED();                                           \
        }                                                                   \
=======
    int numberOfHeapsReported = 0;
#define SNAPSHOT_HEAP(HeapType)                                                                                \
    {                                                                                                          \
        numberOfHeapsReported++;                                                                               \
        String allocatorBaseName;                                                                              \
        allocatorBaseName = String::format("blink_gc/thread_%lu/heaps/" #HeapType, (unsigned long)(m_thread)); \
        switch (type) {                                                                                        \
        case SnapshotType::HeapSnapshot:                                                                       \
            m_heaps[HeapType##HeapIndex]->takeSnapshot(allocatorBaseName);                                     \
            break;                                                                                             \
        case SnapshotType::FreelistSnapshot:                                                                   \
            m_heaps[HeapType##HeapIndex]->takeFreelistSnapshot(allocatorBaseName);                             \
            break;                                                                                             \
        default:                                                                                               \
            ASSERT_NOT_REACHED();                                                                              \
        }                                                                                                      \
>>>>>>> miniblink49
    }

    SNAPSHOT_HEAP(NormalPage1);
    SNAPSHOT_HEAP(NormalPage2);
    SNAPSHOT_HEAP(NormalPage3);
    SNAPSHOT_HEAP(NormalPage4);
    SNAPSHOT_HEAP(EagerSweep);
    SNAPSHOT_HEAP(Vector1);
    SNAPSHOT_HEAP(Vector2);
    SNAPSHOT_HEAP(Vector3);
    SNAPSHOT_HEAP(Vector4);
    SNAPSHOT_HEAP(InlineVector);
    SNAPSHOT_HEAP(HashTable);
    SNAPSHOT_HEAP(LargeObject);
<<<<<<< HEAD
    FOR_EACH_TYPED_ARENA(SNAPSHOT_HEAP);

    ASSERT(numberOfHeapsReported == BlinkGC::NumberOfArenas);

#undef SNAPSHOT_HEAP

    if (type == SnapshotType::FreelistSnapshot)
        return;

    size_t totalLiveCount = 0;
    size_t totalDeadCount = 0;
    size_t totalLiveSize = 0;
    size_t totalDeadSize = 0;
    for (size_t gcInfoIndex = 1; gcInfoIndex <= GCInfoTable::gcInfoIndex();
         ++gcInfoIndex) {
        totalLiveCount += info.liveCount[gcInfoIndex];
        totalDeadCount += info.deadCount[gcInfoIndex];
        totalLiveSize += info.liveSize[gcInfoIndex];
        totalDeadSize += info.deadSize[gcInfoIndex];
    }

    base::trace_event::MemoryAllocatorDump* threadDump = BlinkGCMemoryDumpProvider::instance()
                                                             ->createMemoryAllocatorDumpForCurrentGC(threadDumpName);
    threadDump->AddScalar("live_count", "objects", totalLiveCount);
    threadDump->AddScalar("dead_count", "objects", totalDeadCount);
    threadDump->AddScalar("live_size", "bytes", totalLiveSize);
    threadDump->AddScalar("dead_size", "bytes", totalDeadSize);

    base::trace_event::MemoryAllocatorDump* heapsDump = BlinkGCMemoryDumpProvider::instance()
                                                            ->createMemoryAllocatorDumpForCurrentGC(heapsDumpName);
    base::trace_event::MemoryAllocatorDump* classesDump = BlinkGCMemoryDumpProvider::instance()
                                                              ->createMemoryAllocatorDumpForCurrentGC(classesDumpName);
    BlinkGCMemoryDumpProvider::instance()
        ->currentProcessMemoryDump()
        ->AddOwnershipEdge(classesDump->guid(), heapsDump->guid());
}

void ThreadState::collectGarbage(BlinkGC::StackState stackState,
    BlinkGC::GCType gcType,
    BlinkGC::GCReason reason)
{
    // Nested collectGarbage() invocations aren't supported.
    RELEASE_ASSERT(!isGCForbidden());
    completeSweep();

    GCForbiddenScope gcForbiddenScope(this);

    {
        // Access to the CrossThreadPersistentRegion has to be prevented while in
        // the marking phase because otherwise other threads may allocate or free
        // PersistentNodes and we can't handle that.
        CrossThreadPersistentRegion::LockScope persistentLock(
            ProcessHeap::crossThreadPersistentRegion());
        {
            SafePointScope safePointScope(stackState, this);

            // Resume all parked threads upon leaving this scope.
            ParkThreadsScope parkThreadsScope(this);

            // Try to park the other threads. If we're unable to, bail out of the GC.
            if (!parkThreadsScope.parkThreads())
                return;

            std::unique_ptr<Visitor> visitor;
            if (gcType == BlinkGC::TakeSnapshot) {
                visitor = Visitor::create(this, VisitorMarkingMode::SnapshotMarking);
            } else {
                DCHECK(gcType == BlinkGC::GCWithSweep || gcType == BlinkGC::GCWithoutSweep);
                if (heap().compaction()->shouldCompact(this, gcType, reason)) {
                    heap().compaction()->initialize(this);
                    visitor = Visitor::create(
                        this, VisitorMarkingMode::GlobalMarkingWithCompaction);
                } else {
                    visitor = Visitor::create(this, VisitorMarkingMode::GlobalMarking);
                }
            }

            ScriptForbiddenIfMainThreadScope scriptForbidden;

            TRACE_EVENT2("blink_gc,devtools.timeline", "BlinkGCMarking",
                "lazySweeping", gcType == BlinkGC::GCWithoutSweep,
                "gcReason", gcReasonString(reason));
            double startTime = WTF::currentTimeMS();

            if (gcType == BlinkGC::TakeSnapshot)
                BlinkGCMemoryDumpProvider::instance()->clearProcessDumpForCurrentGC();

            // Disallow allocation during garbage collection (but not during the
            // finalization that happens when the visitorScope is torn down).
            NoAllocationScope noAllocationScope(this);

            heap().commitCallbackStacks();
            heap().preGC();

            StackFrameDepthScope stackDepthScope(&heap().stackFrameDepth());

            size_t totalObjectSize = heap().heapStats().allocatedObjectSize() + heap().heapStats().markedObjectSize();
            if (gcType != BlinkGC::TakeSnapshot)
                heap().resetHeapCounters();

            {
                // 1. Trace persistent roots.
                heap().visitPersistentRoots(visitor.get());

                // 2. Trace objects reachable from the stack.  We do this independent of
                // the
                // given stackState since other threads might have a different stack
                // state.
                heap().visitStackRoots(visitor.get());

                // 3. Transitive closure to trace objects including ephemerons.
                heap().processMarkingStack(visitor.get());

                heap().postMarkingProcessing(visitor.get());
                heap().globalWeakProcessing(visitor.get());
            }

            // Now we can delete all orphaned pages because there are no dangling
            // pointers to the orphaned pages.  (If we have such dangling pointers,
            // we should have crashed during marking before getting here.)
            heap().getOrphanedPagePool()->decommitOrphanedPages();

            double markingTimeInMilliseconds = WTF::currentTimeMS() - startTime;
            heap().heapStats().setEstimatedMarkingTimePerByte(
                totalObjectSize ? (markingTimeInMilliseconds / 1000 / totalObjectSize)
                                : 0);

#if PRINT_HEAP_STATS
            dataLogF(
                "ThreadHeap::collectGarbage (gcReason=%s, lazySweeping=%d, "
                "time=%.1lfms)\n",
                gcReasonString(reason), gcType == BlinkGC::GCWithoutSweep,
                markingTimeInMilliseconds);
#endif

            DEFINE_THREAD_SAFE_STATIC_LOCAL(
                CustomCountHistogram, markingTimeHistogram,
                new CustomCountHistogram("BlinkGC.CollectGarbage", 0, 10 * 1000, 50));
            markingTimeHistogram.count(markingTimeInMilliseconds);
            DEFINE_THREAD_SAFE_STATIC_LOCAL(
                CustomCountHistogram, totalObjectSpaceHistogram,
                new CustomCountHistogram("BlinkGC.TotalObjectSpace", 0, 4 * 1024 * 1024,
                    50));
            totalObjectSpaceHistogram.count(ProcessHeap::totalAllocatedObjectSize() / 1024);
            DEFINE_THREAD_SAFE_STATIC_LOCAL(
                CustomCountHistogram, totalAllocatedSpaceHistogram,
                new CustomCountHistogram("BlinkGC.TotalAllocatedSpace", 0,
                    4 * 1024 * 1024, 50));
            totalAllocatedSpaceHistogram.count(ProcessHeap::totalAllocatedSpace() / 1024);
            DEFINE_THREAD_SAFE_STATIC_LOCAL(
                EnumerationHistogram, gcReasonHistogram,
                new EnumerationHistogram("BlinkGC.GCReason",
                    BlinkGC::NumberOfGCReason));
            gcReasonHistogram.count(reason);

            heap().m_lastGCReason = reason;

            ThreadHeap::reportMemoryUsageHistogram();
            WTF::Partitions::reportMemoryUsageHistogram();
        }
        heap().postGC(gcType);
    }

    heap().preSweep(gcType);
    heap().decommitCallbackStacks();
}

void ThreadState::collectGarbageForTerminatingThread()
{
    // A thread-specific termination GC must not allow other global GCs to go
    // ahead while it is running, hence the termination GC does not enter a
    // safepoint. VisitorScope will not enter also a safepoint scope for
    // ThreadTerminationGC.
    GCForbiddenScope gcForbiddenScope(this);

    {
        std::unique_ptr<Visitor> visitor = Visitor::create(this, VisitorMarkingMode::ThreadLocalMarking);

        NoAllocationScope noAllocationScope(this);

        heap().commitCallbackStacks();
        preGC();

        // 1. Trace the thread local persistent roots. For thread local GCs we
        // don't trace the stack (ie. no conservative scanning) since this is
        // only called during thread shutdown where there should be no objects
        // on the stack.
        // We also assume that orphaned pages have no objects reachable from
        // persistent handles on other threads or CrossThreadPersistents.  The
        // only cases where this could happen is if a subsequent conservative
        // global GC finds a "pointer" on the stack or due to a programming
        // error where an object has a dangling cross-thread pointer to an
        // object on this heap.
        visitPersistents(visitor.get());

        // 2. Trace objects reachable from the thread's persistent roots
        // including ephemerons.
        heap().processMarkingStack(visitor.get());

        heap().postMarkingProcessing(visitor.get());
        heap().globalWeakProcessing(visitor.get());
    }

    postGC(BlinkGC::GCWithSweep);
    preSweep(BlinkGC::GCWithSweep);
    heap().decommitCallbackStacks();
}

void ThreadState::collectAllGarbage()
{
    // We need to run multiple GCs to collect a chain of persistent handles.
    size_t previousLiveObjects = 0;
    for (int i = 0; i < 5; ++i) {
        collectGarbage(BlinkGC::NoHeapPointersOnStack, BlinkGC::GCWithSweep,
            BlinkGC::ForcedGC);
        size_t liveObjects = heap().heapStats().markedObjectSize();
        if (liveObjects == previousLiveObjects)
            break;
        previousLiveObjects = liveObjects;
    }
}

=======
    FOR_EACH_TYPED_HEAP(SNAPSHOT_HEAP);

    ASSERT(numberOfHeapsReported == NumberOfHeaps);

#undef SNAPSHOT_HEAP
}

#if ENABLE(GC_PROFILING)
const GCInfo* ThreadState::findGCInfoFromAllThreads(Address address)
{
    bool needLockForIteration = !ThreadState::current()->isInGC();
    if (needLockForIteration)
        threadAttachMutex().lock();

    for (ThreadState* state : attachedThreads()) {
        if (const GCInfo* gcInfo = state->findGCInfo(address)) {
            if (needLockForIteration)
                threadAttachMutex().unlock();
            return gcInfo;
        }
    }
    if (needLockForIteration)
        threadAttachMutex().unlock();
    return nullptr;
}

void ThreadState::snapshotFreeListIfNecessary()
{
    bool enabled = false;
    TRACE_EVENT_CATEGORY_GROUP_ENABLED(TRACE_DISABLED_BY_DEFAULT("blink_gc"), &enabled);
    if (!enabled)
        return;

    static const double recordIntervalSeconds = 0.010;
    double now = monotonicallyIncreasingTime();
    if (now > m_nextFreeListSnapshotTime) {
        snapshotFreeList();
        m_nextFreeListSnapshotTime = now + recordIntervalSeconds;
    }
}

void ThreadState::snapshotFreeList()
{
    RefPtr<TracedValue> json = TracedValue::create();

#define SNAPSHOT_FREE_LIST(HeapType)                           \
    {                                                          \
        json->beginDictionary();                               \
        json->setString("name", #HeapType);                    \
        m_heaps[HeapType##HeapIndex]->snapshotFreeList(*json); \
        json->endDictionary();                                 \
    }

    json->beginArray("heaps");
    SNAPSHOT_FREE_LIST(EagerSweep);
    SNAPSHOT_FREE_LIST(NormalPage1);
    SNAPSHOT_FREE_LIST(NormalPage2);
    SNAPSHOT_FREE_LIST(NormalPage3);
    SNAPSHOT_FREE_LIST(NormalPage4);
    SNAPSHOT_FREE_LIST(Vector1);
    SNAPSHOT_FREE_LIST(Vector2);
    SNAPSHOT_FREE_LIST(Vector3);
    SNAPSHOT_FREE_LIST(Vector4);
    SNAPSHOT_FREE_LIST(InlineVector);
    SNAPSHOT_FREE_LIST(HashTable);
    SNAPSHOT_FREE_LIST(LargeObject);
    FOR_EACH_TYPED_HEAP(SNAPSHOT_FREE_LIST);
    json->endArray();

#undef SNAPSHOT_FREE_LIST

    TRACE_EVENT_OBJECT_SNAPSHOT_WITH_ID(TRACE_DISABLED_BY_DEFAULT("blink_gc"), "FreeList", this, json.release());
}

void ThreadState::collectAndReportMarkSweepStats() const
{
    if (!isMainThread())
        return;

    ClassAgeCountsMap markingClassAgeCounts;
    for (int i = 0; i < NumberOfHeaps; ++i)
        m_heaps[i]->countMarkedObjects(markingClassAgeCounts);
    reportMarkSweepStats("MarkingStats", markingClassAgeCounts);

    ClassAgeCountsMap sweepingClassAgeCounts;
    for (int i = 0; i < NumberOfHeaps; ++i)
        m_heaps[i]->countObjectsToSweep(sweepingClassAgeCounts);
    reportMarkSweepStats("SweepingStats", sweepingClassAgeCounts);
}

void ThreadState::reportMarkSweepStats(const char* statsName, const ClassAgeCountsMap& classAgeCounts) const
{
    RefPtr<TracedValue> json = TracedValue::create();
    for (ClassAgeCountsMap::const_iterator it = classAgeCounts.begin(), end = classAgeCounts.end(); it != end; ++it) {
        json->beginArray(it->key.ascii().data());
        for (size_t age = 0; age <= maxHeapObjectAge; ++age)
            json->pushInteger(it->value.ages[age]);
        json->endArray();
    }
    TRACE_EVENT_OBJECT_SNAPSHOT_WITH_ID(TRACE_DISABLED_BY_DEFAULT("blink_gc"), statsName, this, json.release());
}
#endif

>>>>>>> miniblink49
} // namespace blink
