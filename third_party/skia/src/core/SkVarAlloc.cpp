/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkVarAlloc.h"

<<<<<<< HEAD
=======
// We use non-standard malloc diagnostic methods to make sure our allocations are sized well.
#if defined(SK_BUILD_FOR_MAC)
    #include <malloc/malloc.h>
#elif defined(SK_BUILD_FOR_UNIX) || defined(SK_BUILD_FOR_WIN32)
    #include <malloc.h>
#endif

>>>>>>> miniblink49
struct SkVarAlloc::Block {
    Block* prev;
    char* data() { return (char*)(this + 1); }

<<<<<<< HEAD
    static Block* Alloc(Block* prev, size_t size)
    {
        SkASSERT(size >= sizeof(Block));
        Block* b = (Block*)sk_malloc_throw(size);
=======
    static Block* Alloc(Block* prev, size_t size, unsigned flags) {
        SkASSERT(size >= sizeof(Block));
        Block* b = (Block*)sk_malloc_flags(size, flags);
>>>>>>> miniblink49
        b->prev = prev;
        return b;
    }
};

SkVarAlloc::SkVarAlloc(size_t minLgSize)
    : fBytesAllocated(0)
<<<<<<< HEAD
    , fByte(nullptr)
    , fRemaining(0)
    , fLgSize(minLgSize)
    , fBlock(nullptr)
{
}
=======
    , fByte(NULL)
    , fRemaining(0)
    , fLgSize(minLgSize)
    , fBlock(NULL) {}
>>>>>>> miniblink49

SkVarAlloc::SkVarAlloc(size_t minLgSize, char* storage, size_t len)
    : fBytesAllocated(0)
    , fByte(storage)
    , fRemaining(len)
    , fLgSize(minLgSize)
<<<<<<< HEAD
    , fBlock(nullptr)
{
}

SkVarAlloc::~SkVarAlloc()
{
=======
    , fBlock(NULL) {}

SkVarAlloc::~SkVarAlloc() {
>>>>>>> miniblink49
    Block* b = fBlock;
    while (b) {
        Block* prev = b->prev;
        sk_free(b);
        b = prev;
    }
}

<<<<<<< HEAD
void SkVarAlloc::makeSpace(size_t bytes)
{
    SkASSERT(SkIsAlignPtr(bytes));

    size_t alloc = static_cast<size_t>(1) << fLgSize++;
=======
void SkVarAlloc::makeSpace(size_t bytes, unsigned flags) {
    SkASSERT(SkIsAlignPtr(bytes));

    size_t alloc = 1<<fLgSize++;
>>>>>>> miniblink49
    while (alloc < bytes + sizeof(Block)) {
        alloc *= 2;
    }
    fBytesAllocated += alloc;
<<<<<<< HEAD
    fBlock = Block::Alloc(fBlock, alloc);
    fByte = fBlock->data();
    fRemaining = alloc - sizeof(Block);
=======
    fBlock = Block::Alloc(fBlock, alloc, flags);
    fByte = fBlock->data();
    fRemaining = alloc - sizeof(Block);

#if defined(SK_BUILD_FOR_MAC)
    SkASSERT(alloc == malloc_good_size(alloc));
#elif defined(SK_BUILD_FOR_UNIX) && !defined(__UCLIBC__)
    // TODO(mtklein): tune so we can assert something like this
    //SkASSERT(alloc == malloc_usable_size(fBlock));
#endif
>>>>>>> miniblink49
}
