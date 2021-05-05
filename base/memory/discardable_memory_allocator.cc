// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/memory/discardable_memory_allocator.h"

#include "base/logging.h"
#include "base/memory/discardable_memory.h"
#include <vector>

namespace base {
namespace {

    DiscardableMemoryAllocator* g_allocator = nullptr;

    class TestingDiscardableMemory : public DiscardableMemory {
    public:
        explicit TestingDiscardableMemory(size_t size)
            : m_isLocked(true)
        {
            m_data.resize(size);
        }
        ~TestingDiscardableMemory() override
        {
        }

        // WebDiscardableMemory:
        virtual bool Lock() override
        {
            ASSERT(!m_isLocked);
            m_isLocked = true;
            return false;
        }

        virtual void* data() const override
        {
            ASSERT(m_isLocked);
            return (void*)(m_data.data());
        }

        virtual void Unlock() override
        {
            ASSERT(m_isLocked);
            m_isLocked = false;
            // Force eviction to catch clients not correctly checking the return value of lock().
            memset(m_data.data(), 0, m_data.size());
        }

        virtual trace_event::MemoryAllocatorDump* CreateMemoryAllocatorDump(
            const char* name,
            trace_event::ProcessMemoryDump* pmd) const override
        {
            return nullptr;
        }

    private:
        std::vector<char> m_data;
        bool m_isLocked;
    };

    class WebDiscardableMemoryAllocator : public DiscardableMemoryAllocator {
    public:
        virtual std::unique_ptr<DiscardableMemory> AllocateLockedDiscardableMemory(size_t size) override
        {
            return std::unique_ptr<DiscardableMemory>(new TestingDiscardableMemory(size));
        }
    };

} // namespace

// static
void DiscardableMemoryAllocator::SetInstance(
    DiscardableMemoryAllocator* allocator)
{
    DCHECK(allocator);

    // Make sure this function is only called once before the first call
    // to GetInstance().
    DCHECK(!g_allocator);

    g_allocator = allocator;
}

// static
DiscardableMemoryAllocator* DiscardableMemoryAllocator::GetInstance()
{
    if (!g_allocator)
        g_allocator = new WebDiscardableMemoryAllocator();
    DCHECK(g_allocator);
    return g_allocator;
}

} // namespace base
