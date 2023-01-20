<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBitSet.h"

SkBitSet::SkBitSet(int numberOfBits)
    : fBitData(nullptr)
    , fDwordCount(0)
    , fBitCount(numberOfBits)
{
=======

#include "SkBitSet.h"

SkBitSet::SkBitSet(int numberOfBits)
    : fBitData(NULL), fDwordCount(0), fBitCount(numberOfBits) {
>>>>>>> miniblink49
    SkASSERT(numberOfBits > 0);
    // Round up size to 32-bit boundary.
    fDwordCount = (numberOfBits + 31) / 32;
    fBitData.set(sk_calloc_throw(fDwordCount * sizeof(uint32_t)));
}

SkBitSet::SkBitSet(const SkBitSet& source)
<<<<<<< HEAD
    : fBitData(nullptr)
    , fDwordCount(0)
    , fBitCount(0)
{
    *this = source;
}

SkBitSet& SkBitSet::operator=(const SkBitSet& rhs)
{
=======
    : fBitData(NULL), fDwordCount(0), fBitCount(0) {
    *this = source;
}

SkBitSet& SkBitSet::operator=(const SkBitSet& rhs) {
>>>>>>> miniblink49
    if (this == &rhs) {
        return *this;
    }
    fBitCount = rhs.fBitCount;
<<<<<<< HEAD
    fBitData.reset();
=======
    fBitData.free();
>>>>>>> miniblink49
    fDwordCount = rhs.fDwordCount;
    fBitData.set(sk_malloc_throw(fDwordCount * sizeof(uint32_t)));
    memcpy(fBitData.get(), rhs.fBitData.get(), fDwordCount * sizeof(uint32_t));
    return *this;
}

<<<<<<< HEAD
bool SkBitSet::operator==(const SkBitSet& rhs)
{
    if (fBitCount == rhs.fBitCount) {
        if (fBitData.get() != nullptr) {
            return (memcmp(fBitData.get(), rhs.fBitData.get(),
                        fDwordCount * sizeof(uint32_t))
                == 0);
=======
bool SkBitSet::operator==(const SkBitSet& rhs) {
    if (fBitCount == rhs.fBitCount) {
        if (fBitData.get() != NULL) {
            return (memcmp(fBitData.get(), rhs.fBitData.get(),
                           fDwordCount * sizeof(uint32_t)) == 0);
>>>>>>> miniblink49
        }
        return true;
    }
    return false;
}

<<<<<<< HEAD
bool SkBitSet::operator!=(const SkBitSet& rhs)
{
    return !(*this == rhs);
}

void SkBitSet::clearAll()
{
    if (fBitData.get() != nullptr) {
=======
bool SkBitSet::operator!=(const SkBitSet& rhs) {
    return !(*this == rhs);
}

void SkBitSet::clearAll() {
    if (fBitData.get() != NULL) {
>>>>>>> miniblink49
        sk_bzero(fBitData.get(), fDwordCount * sizeof(uint32_t));
    }
}

<<<<<<< HEAD
bool SkBitSet::orBits(const SkBitSet& source)
{
=======
bool SkBitSet::orBits(const SkBitSet& source) {
>>>>>>> miniblink49
    if (fBitCount != source.fBitCount) {
        return false;
    }
    uint32_t* targetBitmap = this->internalGet(0);
    uint32_t* sourceBitmap = source.internalGet(0);
    for (size_t i = 0; i < fDwordCount; ++i) {
        targetBitmap[i] |= sourceBitmap[i];
    }
    return true;
}
