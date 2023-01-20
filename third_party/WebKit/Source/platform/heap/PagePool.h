// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PagePool_h
#define PagePool_h

#include "platform/heap/ThreadState.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
>>>>>>> miniblink49
#include "wtf/ThreadingPrimitives.h"

namespace blink {

class BasePage;
class PageMemory;

<<<<<<< HEAD
template <typename DataType>
class PagePool {
    USING_FAST_MALLOC(PagePool);

protected:
    PagePool()
    {
        for (int i = 0; i < BlinkGC::NumberOfArenas; ++i)
=======
template<typename DataType>
class PagePool {
protected:
    PagePool()
    {
        for (int i = 0; i < ThreadState::NumberOfHeaps; ++i)
>>>>>>> miniblink49
            m_pool[i] = nullptr;
    }

    class PoolEntry {
<<<<<<< HEAD
        USING_FAST_MALLOC(PoolEntry);

=======
>>>>>>> miniblink49
    public:
        PoolEntry(DataType* data, PoolEntry* next)
            : data(data)
            , next(next)
<<<<<<< HEAD
        {
        }
=======
        { }
>>>>>>> miniblink49

        DataType* data;
        PoolEntry* next;
    };

<<<<<<< HEAD
    PoolEntry* m_pool[BlinkGC::NumberOfArenas];
=======
    PoolEntry* m_pool[ThreadState::NumberOfHeaps];
>>>>>>> miniblink49
};

// Once pages have been used for one type of thread heap they will never be
// reused for another type of thread heap.  Instead of unmapping, we add the
// pages to a pool of pages to be reused later by a thread heap of the same
// type. This is done as a security feature to avoid type confusion.  The
<<<<<<< HEAD
// heaps are type segregated by having separate thread arenas for different
=======
// heaps are type segregated by having separate thread heaps for different
>>>>>>> miniblink49
// types of objects.  Holding on to pages ensures that the same virtual address
// space cannot be used for objects of another type than the type contained
// in this page to begin with.
class FreePagePool : public PagePool<PageMemory> {
public:
    ~FreePagePool();
    void addFreePage(int, PageMemory*);
    PageMemory* takeFreePage(int);

private:
<<<<<<< HEAD
    Mutex m_mutex[BlinkGC::NumberOfArenas];
=======
    Mutex m_mutex[ThreadState::NumberOfHeaps];
>>>>>>> miniblink49
};

class OrphanedPagePool : public PagePool<BasePage> {
public:
    // The orphaned zap value must be zero in the lowest bits to allow for
    // using the mark bit when tracing.
    static const uint8_t orphanedZapValue = 0xdc;

    ~OrphanedPagePool();
    void addOrphanedPage(int, BasePage*);
    void decommitOrphanedPages();
<<<<<<< HEAD
#if DCHECK_IS_ON()
=======
#if ENABLE(ASSERT)
>>>>>>> miniblink49
    bool contains(void*);
#endif

    // For orphaned pages, we need to memset with ASan disabled, because
    // the orphaned pages can still contain poisoned memory or annotated
    // container but we want to forcibly clear the orphaned pages without
    // causing ASan errors. asanDisabledMemset must not be used for
    // non-orphaned pages.
    static void asanDisabledMemset(Address, char, size_t);
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    void clearMemory(PageMemory*);
};

} // namespace blink

#endif
