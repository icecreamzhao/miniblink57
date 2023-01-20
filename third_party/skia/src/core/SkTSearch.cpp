<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTSearch.h"
#include <ctype.h>

static inline const char* index_into_base(const char* const* base, int index,
    size_t elemSize)
{
    return *(const char* const*)((const char*)base + index * elemSize);
}

int SkStrSearch(const char* const* base, int count, const char target[],
    size_t target_len, size_t elemSize)
=======

#include "SkTSearch.h"
#include <ctype.h>

static inline const char* index_into_base(const char*const* base, int index,
                                          size_t elemSize)
{
    return *(const char*const*)((const char*)base + index * elemSize);
}

int SkStrSearch(const char*const* base, int count, const char target[],
                size_t target_len, size_t elemSize)
>>>>>>> miniblink49
{
    if (count <= 0)
        return ~0;

<<<<<<< HEAD
    SkASSERT(base != nullptr);
=======
    SkASSERT(base != NULL);
>>>>>>> miniblink49

    int lo = 0;
    int hi = count - 1;

<<<<<<< HEAD
    while (lo < hi) {
=======
    while (lo < hi)
    {
>>>>>>> miniblink49
        int mid = (hi + lo) >> 1;
        const char* elem = index_into_base(base, mid, elemSize);

        int cmp = strncmp(elem, target, target_len);
        if (cmp < 0)
            lo = mid + 1;
        else if (cmp > 0 || strlen(elem) > target_len)
            hi = mid;
        else
            return mid;
    }

    const char* elem = index_into_base(base, hi, elemSize);
    int cmp = strncmp(elem, target, target_len);
<<<<<<< HEAD
    if (cmp || strlen(elem) > target_len) {
=======
    if (cmp || strlen(elem) > target_len)
    {
>>>>>>> miniblink49
        if (cmp < 0)
            hi += 1;
        hi = ~hi;
    }
    return hi;
}

<<<<<<< HEAD
int SkStrSearch(const char* const* base, int count, const char target[],
    size_t elemSize)
=======
int SkStrSearch(const char*const* base, int count, const char target[],
                size_t elemSize)
>>>>>>> miniblink49
{
    return SkStrSearch(base, count, target, strlen(target), elemSize);
}

<<<<<<< HEAD
int SkStrLCSearch(const char* const* base, int count, const char target[],
    size_t len, size_t elemSize)
=======
int SkStrLCSearch(const char*const* base, int count, const char target[],
                  size_t len, size_t elemSize)
>>>>>>> miniblink49
{
    SkASSERT(target);

    SkAutoAsciiToLC tolc(target, len);

    return SkStrSearch(base, count, tolc.lc(), len, elemSize);
}

<<<<<<< HEAD
int SkStrLCSearch(const char* const* base, int count, const char target[],
    size_t elemSize)
=======
int SkStrLCSearch(const char*const* base, int count, const char target[],
                  size_t elemSize)
>>>>>>> miniblink49
{
    return SkStrLCSearch(base, count, target, strlen(target), elemSize);
}

//////////////////////////////////////////////////////////////////////////////

SkAutoAsciiToLC::SkAutoAsciiToLC(const char str[], size_t len)
{
    // see if we need to compute the length
    if ((long)len < 0) {
        len = strlen(str);
    }
    fLength = len;

    // assign lc to our preallocated storage if len is small enough, or allocate
    // it on the heap
<<<<<<< HEAD
    char* lc;
=======
    char*   lc;
>>>>>>> miniblink49
    if (len <= STORAGE) {
        lc = fStorage;
    } else {
        lc = (char*)sk_malloc_throw(len + 1);
    }
    fLC = lc;

    // convert any asii to lower-case. we let non-ascii (utf8) chars pass
    // through unchanged
    for (int i = (int)(len - 1); i >= 0; --i) {
        int c = str[i];
<<<<<<< HEAD
        if ((c & 0x80) == 0) { // is just ascii
=======
        if ((c & 0x80) == 0) {   // is just ascii
>>>>>>> miniblink49
            c = tolower(c);
        }
        lc[i] = c;
    }
    lc[len] = 0;
}

SkAutoAsciiToLC::~SkAutoAsciiToLC()
{
    if (fLC != fStorage) {
        sk_free(fLC);
    }
}
