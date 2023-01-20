<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkGradientBitmapCache.h"

struct SkGradientBitmapCache::Entry {
    Entry* fPrev;
    Entry* fNext;

    void* fBuffer;
    size_t fSize;
    SkBitmap fBitmap;

    Entry(const void* buffer, size_t size, const SkBitmap& bm)
        : fPrev(nullptr)
        , fNext(nullptr)
        , fBitmap(bm)
    {
=======

#include "SkGradientBitmapCache.h"

struct SkGradientBitmapCache::Entry {
    Entry*      fPrev;
    Entry*      fNext;

    void*       fBuffer;
    size_t      fSize;
    SkBitmap    fBitmap;

    Entry(const void* buffer, size_t size, const SkBitmap& bm)
            : fPrev(NULL),
              fNext(NULL),
              fBitmap(bm) {
>>>>>>> miniblink49
        fBuffer = sk_malloc_throw(size);
        fSize = size;
        memcpy(fBuffer, buffer, size);
    }

    ~Entry() { sk_free(fBuffer); }

<<<<<<< HEAD
    bool equals(const void* buffer, size_t size) const
    {
=======
    bool equals(const void* buffer, size_t size) const {
>>>>>>> miniblink49
        return (fSize == size) && !memcmp(fBuffer, buffer, size);
    }
};

<<<<<<< HEAD
SkGradientBitmapCache::SkGradientBitmapCache(int max)
    : fMaxEntries(max)
{
    fEntryCount = 0;
    fHead = fTail = nullptr;
=======
SkGradientBitmapCache::SkGradientBitmapCache(int max) : fMaxEntries(max) {
    fEntryCount = 0;
    fHead = fTail = NULL;
>>>>>>> miniblink49

    this->validate();
}

<<<<<<< HEAD
SkGradientBitmapCache::~SkGradientBitmapCache()
{
=======
SkGradientBitmapCache::~SkGradientBitmapCache() {
>>>>>>> miniblink49
    this->validate();

    Entry* entry = fHead;
    while (entry) {
        Entry* next = entry->fNext;
        delete entry;
        entry = next;
    }
}

<<<<<<< HEAD
SkGradientBitmapCache::Entry* SkGradientBitmapCache::release(Entry* entry) const
{
=======
SkGradientBitmapCache::Entry* SkGradientBitmapCache::detach(Entry* entry) const {
>>>>>>> miniblink49
    if (entry->fPrev) {
        SkASSERT(fHead != entry);
        entry->fPrev->fNext = entry->fNext;
    } else {
        SkASSERT(fHead == entry);
        fHead = entry->fNext;
    }
    if (entry->fNext) {
        SkASSERT(fTail != entry);
        entry->fNext->fPrev = entry->fPrev;
    } else {
        SkASSERT(fTail == entry);
        fTail = entry->fPrev;
    }
    return entry;
}

<<<<<<< HEAD
void SkGradientBitmapCache::attachToHead(Entry* entry) const
{
    entry->fPrev = nullptr;
=======
void SkGradientBitmapCache::attachToHead(Entry* entry) const {
    entry->fPrev = NULL;
>>>>>>> miniblink49
    entry->fNext = fHead;
    if (fHead) {
        fHead->fPrev = entry;
    } else {
        fTail = entry;
    }
    fHead = entry;
}

<<<<<<< HEAD
bool SkGradientBitmapCache::find(const void* buffer, size_t size, SkBitmap* bm) const
{
=======
bool SkGradientBitmapCache::find(const void* buffer, size_t size, SkBitmap* bm) const {
>>>>>>> miniblink49
    AutoValidate av(this);

    Entry* entry = fHead;
    while (entry) {
        if (entry->equals(buffer, size)) {
            if (bm) {
                *bm = entry->fBitmap;
            }
            // move to the head of our list, so we purge it last
<<<<<<< HEAD
            this->release(entry);
=======
            this->detach(entry);
>>>>>>> miniblink49
            this->attachToHead(entry);
            return true;
        }
        entry = entry->fNext;
    }
    return false;
}

<<<<<<< HEAD
void SkGradientBitmapCache::add(const void* buffer, size_t len, const SkBitmap& bm)
{
=======
void SkGradientBitmapCache::add(const void* buffer, size_t len, const SkBitmap& bm) {
>>>>>>> miniblink49
    AutoValidate av(this);

    if (fEntryCount == fMaxEntries) {
        SkASSERT(fTail);
<<<<<<< HEAD
        delete this->release(fTail);
        fEntryCount -= 1;
    }

    Entry* entry = new Entry(buffer, len, bm);
=======
        delete this->detach(fTail);
        fEntryCount -= 1;
    }

    Entry* entry = SkNEW_ARGS(Entry, (buffer, len, bm));
>>>>>>> miniblink49
    this->attachToHead(entry);
    fEntryCount += 1;
}

///////////////////////////////////////////////////////////////////////////////

#ifdef SK_DEBUG

<<<<<<< HEAD
void SkGradientBitmapCache::validate() const
{
    SkASSERT(fEntryCount >= 0 && fEntryCount <= fMaxEntries);

    if (fEntryCount > 0) {
        SkASSERT(nullptr == fHead->fPrev);
        SkASSERT(nullptr == fTail->fNext);
=======
void SkGradientBitmapCache::validate() const {
    SkASSERT(fEntryCount >= 0 && fEntryCount <= fMaxEntries);

    if (fEntryCount > 0) {
        SkASSERT(NULL == fHead->fPrev);
        SkASSERT(NULL == fTail->fNext);
>>>>>>> miniblink49

        if (fEntryCount == 1) {
            SkASSERT(fHead == fTail);
        } else {
            SkASSERT(fHead != fTail);
        }

        Entry* entry = fHead;
        int count = 0;
        while (entry) {
            count += 1;
            entry = entry->fNext;
        }
        SkASSERT(count == fEntryCount);

        entry = fTail;
        while (entry) {
            count -= 1;
            entry = entry->fPrev;
        }
        SkASSERT(0 == count);
    } else {
<<<<<<< HEAD
        SkASSERT(nullptr == fHead);
        SkASSERT(nullptr == fTail);
=======
        SkASSERT(NULL == fHead);
        SkASSERT(NULL == fTail);
>>>>>>> miniblink49
    }
}

#endif
