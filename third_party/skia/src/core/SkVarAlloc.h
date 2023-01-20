/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkVarAlloc_DEFINED
#define SkVarAlloc_DEFINED

#include "SkTypes.h"

class SkVarAlloc : SkNoncopyable {
public:
    // Smallest block we'll allocate is 2**N bytes.
    explicit SkVarAlloc(size_t minLgSize);
    // Same as above, but first uses up to len bytes from storage.
    SkVarAlloc(size_t minLgSize, char* storage, size_t len);

    ~SkVarAlloc();

<<<<<<< HEAD
    // Returns contiguous bytes aligned at least for pointers.
    char* alloc(size_t bytes)
    {
        bytes = SkAlignPtr(bytes);

        if (bytes > fRemaining) {
            this->makeSpace(bytes);
=======
    // Returns contiguous bytes aligned at least for pointers.  You may pass SK_MALLOC_THROW, etc.
    char* alloc(size_t bytes, unsigned sk_malloc_flags) {
        bytes = SkAlignPtr(bytes);

        if (bytes > fRemaining) {
            this->makeSpace(bytes, sk_malloc_flags);
>>>>>>> miniblink49
        }
        SkASSERT(bytes <= fRemaining);

        char* ptr = fByte;
        fByte += bytes;
        fRemaining = SkToU32(fRemaining - bytes);
        return ptr;
    }

    // Returns our best estimate of the number of bytes we've allocated.
    // (We may not track this precisely to save space.)
    size_t approxBytesAllocated() const { return fBytesAllocated; }

private:
<<<<<<< HEAD
    void makeSpace(size_t bytes);
=======
    void makeSpace(size_t bytes, unsigned flags);
>>>>>>> miniblink49

    size_t fBytesAllocated;

    char* fByte;
    unsigned fRemaining;
    unsigned fLgSize;

    struct Block;
    Block* fBlock;
};
<<<<<<< HEAD
static_assert(sizeof(SkVarAlloc) <= 32, "SkVarAllocSize");

#endif //SkVarAlloc_DEFINED
=======
SK_COMPILE_ASSERT(sizeof(SkVarAlloc) <= 32, SkVarAllocSize);

#endif//SkVarAlloc_DEFINED
>>>>>>> miniblink49
