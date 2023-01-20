// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/heap/BlinkGCMemoryDumpProvider.h"

#include "base/trace_event/heap_profiler_allocation_context_tracker.h"
#include "base/trace_event/heap_profiler_allocation_register.h"
#include "base/trace_event/memory_allocator_dump.h"
#include "base/trace_event/process_memory_dump.h"
#include "base/trace_event/trace_event_memory_overhead.h"
#include "platform/heap/Handle.h"
#include "platform/instrumentation/tracing/web_memory_allocator_dump.h"
#include "public/platform/Platform.h"
=======
#include "config.h"
#include "Source/platform/heap/BlinkGCMemoryDumpProvider.h"

#include "platform/heap/Handle.h"
#include "public/platform/Platform.h"
#include "public/platform/WebMemoryAllocatorDump.h"
#include "public/platform/WebProcessMemoryDump.h"
>>>>>>> miniblink49
#include "wtf/StdLibExtras.h"
#include "wtf/Threading.h"

namespace blink {
<<<<<<< HEAD
namespace {

    void dumpMemoryTotals(base::trace_event::ProcessMemoryDump* memoryDump)
    {
        base::trace_event::MemoryAllocatorDump* allocatorDump = memoryDump->CreateAllocatorDump("blink_gc");
        allocatorDump->AddScalar("size", "bytes", ProcessHeap::totalAllocatedSpace());

        base::trace_event::MemoryAllocatorDump* objectsDump = memoryDump->CreateAllocatorDump("blink_gc/allocated_objects");

        // ThreadHeap::markedObjectSize() can be underestimated if we're still in the
        // process of lazy sweeping.
        objectsDump->AddScalar("size", "bytes",
            ProcessHeap::totalAllocatedObjectSize() + ProcessHeap::totalMarkedObjectSize());
    }

    void reportAllocation(Address address, size_t size, const char* typeName)
    {
        BlinkGCMemoryDumpProvider::instance()->insert(address, size, typeName);
    }

    void reportFree(Address address)
    {
        BlinkGCMemoryDumpProvider::instance()->remove(address);
    }

} // namespace
=======
>>>>>>> miniblink49

BlinkGCMemoryDumpProvider* BlinkGCMemoryDumpProvider::instance()
{
    DEFINE_STATIC_LOCAL(BlinkGCMemoryDumpProvider, instance, ());
    return &instance;
}

<<<<<<< HEAD
BlinkGCMemoryDumpProvider::~BlinkGCMemoryDumpProvider() { }

bool BlinkGCMemoryDumpProvider::OnMemoryDump(
    const base::trace_event::MemoryDumpArgs& args,
    base::trace_event::ProcessMemoryDump* memoryDump)
{
    using base::trace_event::MemoryDumpLevelOfDetail;
    MemoryDumpLevelOfDetail levelOfDetail = args.level_of_detail;
    // In the case of a detailed dump perform a mark-only GC pass to collect
    // more detailed stats.
    if (levelOfDetail == MemoryDumpLevelOfDetail::DETAILED)
        ThreadState::current()->collectGarbage(BlinkGC::NoHeapPointersOnStack,
            BlinkGC::TakeSnapshot,
            BlinkGC::ForcedGC);
    dumpMemoryTotals(memoryDump);

    if (m_isHeapProfilingEnabled) {
        // Overhead should always be reported, regardless of light vs. heavy.
        base::trace_event::TraceEventMemoryOverhead overhead;
        base::hash_map<base::trace_event::AllocationContext,
            base::trace_event::AllocationMetrics>
            metricsByContext;
        {
            MutexLocker locker(m_allocationRegisterMutex);
            if (levelOfDetail == MemoryDumpLevelOfDetail::DETAILED) {
                for (const auto& allocSize : *m_allocationRegister) {
                    base::trace_event::AllocationMetrics& metrics = metricsByContext[allocSize.context];
                    metrics.size += allocSize.size;
                    metrics.count++;
                }
            }
            m_allocationRegister->EstimateTraceMemoryOverhead(&overhead);
        }
        memoryDump->DumpHeapUsage(metricsByContext, overhead, "blink_gc");
    }

    // Merge all dumps collected by ThreadHeap::collectGarbage.
    if (levelOfDetail == MemoryDumpLevelOfDetail::DETAILED)
        memoryDump->TakeAllDumpsFrom(m_currentProcessMemoryDump.get());
    return true;
}

void BlinkGCMemoryDumpProvider::OnHeapProfilingEnabled(bool enabled)
{
    if (enabled) {
        {
            MutexLocker locker(m_allocationRegisterMutex);
            if (!m_allocationRegister)
                m_allocationRegister.reset(new base::trace_event::AllocationRegister());
        }
        HeapAllocHooks::setAllocationHook(reportAllocation);
        HeapAllocHooks::setFreeHook(reportFree);
    } else {
        HeapAllocHooks::setAllocationHook(nullptr);
        HeapAllocHooks::setFreeHook(nullptr);
    }
    m_isHeapProfilingEnabled = enabled;
}

base::trace_event::MemoryAllocatorDump*
BlinkGCMemoryDumpProvider::createMemoryAllocatorDumpForCurrentGC(
    const String& absoluteName)
{
    // TODO(bashi): Change type name of |absoluteName|.
    return m_currentProcessMemoryDump->CreateAllocatorDump(
        absoluteName.utf8().data());
=======
BlinkGCMemoryDumpProvider::~BlinkGCMemoryDumpProvider()
{
}

bool BlinkGCMemoryDumpProvider::onMemoryDump(blink::WebProcessMemoryDump* memoryDump)
{
    Heap::collectGarbage(ThreadState::NoHeapPointersOnStack, ThreadState::TakeSnapshot, Heap::ForcedGC);
    String dumpName = String::format("blink_gc/thread_%lu", static_cast<unsigned long>(WTF::currentThread()));
    WebMemoryAllocatorDump* allocatorDump = memoryDump->createMemoryAllocatorDump(dumpName);
    allocatorDump->AddScalar("size", "bytes", Heap::allocatedSpace());

    dumpName.append("/allocated_objects");
    WebMemoryAllocatorDump* objectsDump = memoryDump->createMemoryAllocatorDump(dumpName);
    objectsDump->AddScalar("size", "bytes", Heap::allocatedObjectSize() + Heap::markedObjectSize());
    objectsDump->AddScalar("estimated_live_object_size", "bytes", Heap::estimatedLiveObjectSize());

    // Merge all dumps collected by Heap::collectGarbage.
    memoryDump->takeAllDumpsFrom(m_currentProcessMemoryDump.get());
    return true;
}

WebMemoryAllocatorDump* BlinkGCMemoryDumpProvider::createMemoryAllocatorDumpForCurrentGC(const String& absoluteName)
{
    return m_currentProcessMemoryDump->createMemoryAllocatorDump(absoluteName);
>>>>>>> miniblink49
}

void BlinkGCMemoryDumpProvider::clearProcessDumpForCurrentGC()
{
<<<<<<< HEAD
    m_currentProcessMemoryDump->Clear();
}

BlinkGCMemoryDumpProvider::BlinkGCMemoryDumpProvider()
    : m_currentProcessMemoryDump(new base::trace_event::ProcessMemoryDump(
        nullptr,
        { base::trace_event::MemoryDumpLevelOfDetail::DETAILED }))
    , m_isHeapProfilingEnabled(false)
{
}

void BlinkGCMemoryDumpProvider::insert(Address address,
    size_t size,
    const char* typeName)
{
    base::trace_event::AllocationContext context;
    //   if (!base::trace_event::AllocationContextTracker::
    //            GetInstanceForCurrentThread()
    //                ->GetContextSnapshot(&context))
    //     return;
    DebugBreak();
    context.type_name = typeName;
    MutexLocker locker(m_allocationRegisterMutex);
    if (m_allocationRegister)
        m_allocationRegister->Insert(address, size, context);
}

void BlinkGCMemoryDumpProvider::remove(Address address)
{
    MutexLocker locker(m_allocationRegisterMutex);
    if (m_allocationRegister)
        m_allocationRegister->Remove(address);
}

=======
    m_currentProcessMemoryDump->clear();
}

BlinkGCMemoryDumpProvider::BlinkGCMemoryDumpProvider()
    : m_currentProcessMemoryDump(adoptPtr(Platform::current()->createProcessMemoryDump()))
{
}

>>>>>>> miniblink49
} // namespace blink
