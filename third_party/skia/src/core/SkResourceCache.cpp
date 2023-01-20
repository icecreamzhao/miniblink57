/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkResourceCache.h"
=======
>>>>>>> miniblink49
#include "SkChecksum.h"
#include "SkMessageBus.h"
#include "SkMipMap.h"
#include "SkMutex.h"
#include "SkPixelRef.h"
<<<<<<< HEAD
#include "SkTraceMemoryDump.h"

#include <stddef.h>
#include <stdlib.h>
=======
#include "SkResourceCache.h"

#include <stddef.h>
>>>>>>> miniblink49

DECLARE_SKMESSAGEBUS_MESSAGE(SkResourceCache::PurgeSharedIDMessage)

// This can be defined by the caller's build system
//#define SK_USE_DISCARDABLE_SCALEDIMAGECACHE

#ifndef SK_DISCARDABLEMEMORY_SCALEDIMAGECACHE_COUNT_LIMIT
<<<<<<< HEAD
#define SK_DISCARDABLEMEMORY_SCALEDIMAGECACHE_COUNT_LIMIT 1024
#endif

#ifndef SK_DEFAULT_IMAGE_CACHE_LIMIT
#define SK_DEFAULT_IMAGE_CACHE_LIMIT (32 * 1024 * 1024)
#endif

void SkResourceCache::Key::init(void* nameSpace, uint64_t sharedID, size_t dataSize)
{
    SkASSERT(SkAlign4(dataSize) == dataSize);
=======
#   define SK_DISCARDABLEMEMORY_SCALEDIMAGECACHE_COUNT_LIMIT   1024
#endif

#ifndef SK_DEFAULT_IMAGE_CACHE_LIMIT
    #define SK_DEFAULT_IMAGE_CACHE_LIMIT     (2 * 1024 * 1024)
#endif

void SkResourceCache::Key::init(void* nameSpace, uint64_t sharedID, size_t length) {
    SkASSERT(SkAlign4(length) == length);
>>>>>>> miniblink49

    // fCount32 and fHash are not hashed
    static const int kUnhashedLocal32s = 2; // fCache32 + fHash
    static const int kSharedIDLocal32s = 2; // fSharedID_lo + fSharedID_hi
    static const int kHashedLocal32s = kSharedIDLocal32s + (sizeof(fNamespace) >> 2);
    static const int kLocal32s = kUnhashedLocal32s + kHashedLocal32s;

<<<<<<< HEAD
    static_assert(sizeof(Key) == (kLocal32s << 2), "unaccounted_key_locals");
    static_assert(sizeof(Key) == offsetof(Key, fNamespace) + sizeof(fNamespace),
        "namespace_field_must_be_last");

    fCount32 = SkToS32(kLocal32s + (dataSize >> 2));
=======
    SK_COMPILE_ASSERT(sizeof(Key) == (kLocal32s << 2), unaccounted_key_locals);
    SK_COMPILE_ASSERT(sizeof(Key) == offsetof(Key, fNamespace) + sizeof(fNamespace),
                      namespace_field_must_be_last);

    fCount32 = SkToS32(kLocal32s + (length >> 2));
>>>>>>> miniblink49
    fSharedID_lo = (uint32_t)sharedID;
    fSharedID_hi = (uint32_t)(sharedID >> 32);
    fNamespace = nameSpace;
    // skip unhashed fields when computing the murmur
    fHash = SkChecksum::Murmur3(this->as32() + kUnhashedLocal32s,
<<<<<<< HEAD
        (fCount32 - kUnhashedLocal32s) << 2);
=======
                                (fCount32 - kUnhashedLocal32s) << 2);
>>>>>>> miniblink49
}

#include "SkTDynamicHash.h"

<<<<<<< HEAD
class SkResourceCache::Hash : public SkTDynamicHash<SkResourceCache::Rec, SkResourceCache::Key> {
};

///////////////////////////////////////////////////////////////////////////////

void SkResourceCache::init()
{
    fHead = nullptr;
    fTail = nullptr;
=======
class SkResourceCache::Hash :
    public SkTDynamicHash<SkResourceCache::Rec, SkResourceCache::Key> {};


///////////////////////////////////////////////////////////////////////////////

void SkResourceCache::init() {
    fHead = NULL;
    fTail = NULL;
>>>>>>> miniblink49
    fHash = new Hash;
    fTotalBytesUsed = 0;
    fCount = 0;
    fSingleAllocationByteLimit = 0;
<<<<<<< HEAD
    fAllocator = nullptr;

    // One of these should be explicit set by the caller after we return.
    fTotalByteLimit = 0;
    fDiscardableFactory = nullptr;
=======
    fAllocator = NULL;

    // One of these should be explicit set by the caller after we return.
    fTotalByteLimit = 0;
    fDiscardableFactory = NULL;
>>>>>>> miniblink49
}

#include "SkDiscardableMemory.h"

class SkOneShotDiscardablePixelRef : public SkPixelRef {
public:
<<<<<<< HEAD
    // Ownership of the discardablememory is transfered to the pixelref
    // The pixelref will ref() the colortable (if not NULL), and unref() in destructor
    SkOneShotDiscardablePixelRef(const SkImageInfo&, SkDiscardableMemory*, size_t rowBytes,
        SkColorTable*);
=======

    // Ownership of the discardablememory is transfered to the pixelref
    SkOneShotDiscardablePixelRef(const SkImageInfo&, SkDiscardableMemory*, size_t rowBytes);
>>>>>>> miniblink49
    ~SkOneShotDiscardablePixelRef();

protected:
    bool onNewLockPixels(LockRec*) override;
    void onUnlockPixels() override;
    size_t getAllocatedSizeInBytes() const override;

<<<<<<< HEAD
    SkDiscardableMemory* diagnostic_only_getDiscardable() const override { return fDM; }

private:
    SkDiscardableMemory* fDM;
    size_t fRB;
    bool fFirstTime;
    SkColorTable* fCTable;
=======
private:
    SkDiscardableMemory* fDM;
    size_t               fRB;
    bool                 fFirstTime;
>>>>>>> miniblink49

    typedef SkPixelRef INHERITED;
};

SkOneShotDiscardablePixelRef::SkOneShotDiscardablePixelRef(const SkImageInfo& info,
<<<<<<< HEAD
    SkDiscardableMemory* dm,
    size_t rowBytes,
    SkColorTable* ctable)
    : INHERITED(info)
    , fDM(dm)
    , fRB(rowBytes)
    , fCTable(ctable)
{
    SkASSERT(dm->data());
    fFirstTime = true;
    SkSafeRef(ctable);
}

SkOneShotDiscardablePixelRef::~SkOneShotDiscardablePixelRef()
{
    delete fDM;
    SkSafeUnref(fCTable);
}

bool SkOneShotDiscardablePixelRef::onNewLockPixels(LockRec* rec)
{
=======
                                             SkDiscardableMemory* dm,
                                             size_t rowBytes)
    : INHERITED(info)
    , fDM(dm)
    , fRB(rowBytes)
{
    SkASSERT(dm->data());
    fFirstTime = true;
}

SkOneShotDiscardablePixelRef::~SkOneShotDiscardablePixelRef() {
    SkDELETE(fDM);
}

bool SkOneShotDiscardablePixelRef::onNewLockPixels(LockRec* rec) {
>>>>>>> miniblink49
    if (fFirstTime) {
        // we're already locked
        SkASSERT(fDM->data());
        fFirstTime = false;
        goto SUCCESS;
    }

    // A previous call to onUnlock may have deleted our DM, so check for that
<<<<<<< HEAD
    if (nullptr == fDM) {
=======
    if (NULL == fDM) {
>>>>>>> miniblink49
        return false;
    }

    if (!fDM->lock()) {
        // since it failed, we delete it now, to free-up the resource
        delete fDM;
<<<<<<< HEAD
        fDM = nullptr;
=======
        fDM = NULL;
>>>>>>> miniblink49
        return false;
    }

SUCCESS:
    rec->fPixels = fDM->data();
<<<<<<< HEAD
    rec->fColorTable = fCTable;
=======
    rec->fColorTable = NULL;
>>>>>>> miniblink49
    rec->fRowBytes = fRB;
    return true;
}

<<<<<<< HEAD
void SkOneShotDiscardablePixelRef::onUnlockPixels()
{
=======
void SkOneShotDiscardablePixelRef::onUnlockPixels() {
>>>>>>> miniblink49
    SkASSERT(!fFirstTime);
    fDM->unlock();
}

<<<<<<< HEAD
size_t SkOneShotDiscardablePixelRef::getAllocatedSizeInBytes() const
{
=======
size_t SkOneShotDiscardablePixelRef::getAllocatedSizeInBytes() const {
>>>>>>> miniblink49
    return this->info().getSafeSize(fRB);
}

class SkResourceCacheDiscardableAllocator : public SkBitmap::Allocator {
public:
<<<<<<< HEAD
    SkResourceCacheDiscardableAllocator(SkResourceCache::DiscardableFactory factory)
    {
=======
    SkResourceCacheDiscardableAllocator(SkResourceCache::DiscardableFactory factory) {
>>>>>>> miniblink49
        SkASSERT(factory);
        fFactory = factory;
    }

    bool allocPixelRef(SkBitmap*, SkColorTable*) override;

private:
    SkResourceCache::DiscardableFactory fFactory;
};

<<<<<<< HEAD
bool SkResourceCacheDiscardableAllocator::allocPixelRef(SkBitmap* bitmap, SkColorTable* ctable)
{
=======
bool SkResourceCacheDiscardableAllocator::allocPixelRef(SkBitmap* bitmap, SkColorTable* ctable) {
>>>>>>> miniblink49
    size_t size = bitmap->getSize();
    uint64_t size64 = bitmap->computeSize64();
    if (0 == size || size64 > (uint64_t)size) {
        return false;
    }

<<<<<<< HEAD
    if (kIndex_8_SkColorType == bitmap->colorType()) {
        if (!ctable) {
            return false;
        }
    } else {
        ctable = nullptr;
    }

    SkDiscardableMemory* dm = fFactory(size);
    if (nullptr == dm) {
=======
    SkDiscardableMemory* dm = fFactory(size);
    if (NULL == dm) {
        return false;
    }

    // can we relax this?
    if (kN32_SkColorType != bitmap->colorType()) {
>>>>>>> miniblink49
        return false;
    }

    SkImageInfo info = bitmap->info();
<<<<<<< HEAD
    bitmap->setPixelRef(new SkOneShotDiscardablePixelRef(info, dm, bitmap->rowBytes(),
                            ctable))
        ->unref();
=======
    bitmap->setPixelRef(SkNEW_ARGS(SkOneShotDiscardablePixelRef,
                                   (info, dm, bitmap->rowBytes())))->unref();
>>>>>>> miniblink49
    bitmap->lockPixels();
    return bitmap->readyToDraw();
}

<<<<<<< HEAD
SkResourceCache::SkResourceCache(DiscardableFactory factory)
{
    this->init();
    fDiscardableFactory = factory;

    fAllocator = new SkResourceCacheDiscardableAllocator(factory);
}

SkResourceCache::SkResourceCache(size_t byteLimit)
{
=======
SkResourceCache::SkResourceCache(DiscardableFactory factory) {
    this->init();
    fDiscardableFactory = factory;

    fAllocator = SkNEW_ARGS(SkResourceCacheDiscardableAllocator, (factory));
}

SkResourceCache::SkResourceCache(size_t byteLimit) {
>>>>>>> miniblink49
    this->init();
    fTotalByteLimit = byteLimit;
}

<<<<<<< HEAD
SkResourceCache::~SkResourceCache()
{
=======
SkResourceCache::~SkResourceCache() {
>>>>>>> miniblink49
    SkSafeUnref(fAllocator);

    Rec* rec = fHead;
    while (rec) {
        Rec* next = rec->fNext;
<<<<<<< HEAD
        delete rec;
=======
        SkDELETE(rec);
>>>>>>> miniblink49
        rec = next;
    }
    delete fHash;
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool SkResourceCache::find(const Key& key, FindVisitor visitor, void* context)
{
=======
bool SkResourceCache::find(const Key& key, FindVisitor visitor, void* context) {
>>>>>>> miniblink49
    this->checkMessages();

    Rec* rec = fHash->find(key);
    if (rec) {
        if (visitor(*rec, context)) {
<<<<<<< HEAD
            this->moveToHead(rec); // for our LRU
            return true;
        } else {
            this->remove(rec); // stale
=======
            this->moveToHead(rec);  // for our LRU
            return true;
        } else {
            this->remove(rec);  // stale
>>>>>>> miniblink49
            return false;
        }
    }
    return false;
}

<<<<<<< HEAD
static void make_size_str(size_t size, SkString* str)
{
=======
static void make_size_str(size_t size, SkString* str) {
>>>>>>> miniblink49
    const char suffix[] = { 'b', 'k', 'm', 'g', 't', 0 };
    int i = 0;
    while (suffix[i] && (size > 1024)) {
        i += 1;
        size >>= 10;
    }
    str->printf("%zu%c", size, suffix[i]);
}

static bool gDumpCacheTransactions;

<<<<<<< HEAD
void SkResourceCache::add(Rec* rec)
{
=======
void SkResourceCache::add(Rec* rec) {
>>>>>>> miniblink49
    this->checkMessages();

    SkASSERT(rec);
    // See if we already have this key (racy inserts, etc.)
    Rec* existing = fHash->find(rec->getKey());
    if (existing) {
<<<<<<< HEAD
        delete rec;
=======
        SkDELETE(rec);
>>>>>>> miniblink49
        return;
    }

    this->addToHead(rec);
    fHash->add(rec);

    if (gDumpCacheTransactions) {
        SkString bytesStr, totalStr;
        make_size_str(rec->bytesUsed(), &bytesStr);
        make_size_str(fTotalBytesUsed, &totalStr);
        SkDebugf("RC:    add %5s %12p key %08x -- total %5s, count %d\n",
<<<<<<< HEAD
            bytesStr.c_str(), rec, rec->getHash(), totalStr.c_str(), fCount);
=======
                 bytesStr.c_str(), rec, rec->getHash(), totalStr.c_str(), fCount);
>>>>>>> miniblink49
    }

    // since the new rec may push us over-budget, we perform a purge check now
    this->purgeAsNeeded();
}

<<<<<<< HEAD
void SkResourceCache::remove(Rec* rec)
{
    size_t used = rec->bytesUsed();
    SkASSERT(used <= fTotalBytesUsed);

    this->release(rec);
=======
void SkResourceCache::remove(Rec* rec) {
    size_t used = rec->bytesUsed();
    SkASSERT(used <= fTotalBytesUsed);

    this->detach(rec);
>>>>>>> miniblink49
    fHash->remove(rec->getKey());

    fTotalBytesUsed -= used;
    fCount -= 1;

    if (gDumpCacheTransactions) {
        SkString bytesStr, totalStr;
        make_size_str(used, &bytesStr);
        make_size_str(fTotalBytesUsed, &totalStr);
        SkDebugf("RC: remove %5s %12p key %08x -- total %5s, count %d\n",
<<<<<<< HEAD
            bytesStr.c_str(), rec, rec->getHash(), totalStr.c_str(), fCount);
    }

    delete rec;
}

void SkResourceCache::purgeAsNeeded(bool forcePurge)
{
    size_t byteLimit;
    int countLimit;

    if (fDiscardableFactory) {
        countLimit = SK_DISCARDABLEMEMORY_SCALEDIMAGECACHE_COUNT_LIMIT;
        byteLimit = SK_MaxU32; // no limit based on bytes
=======
                 bytesStr.c_str(), rec, rec->getHash(), totalStr.c_str(), fCount);
    }

    SkDELETE(rec);
}

void SkResourceCache::purgeAsNeeded(bool forcePurge) {
    size_t byteLimit;
    int    countLimit;

    if (fDiscardableFactory) {
        countLimit = SK_DISCARDABLEMEMORY_SCALEDIMAGECACHE_COUNT_LIMIT;
        byteLimit = SK_MaxU32;  // no limit based on bytes
>>>>>>> miniblink49
    } else {
        countLimit = SK_MaxS32; // no limit based on count
        byteLimit = fTotalByteLimit;
    }

    Rec* rec = fTail;
    while (rec) {
        if (!forcePurge && fTotalBytesUsed < byteLimit && fCount < countLimit) {
            break;
        }

        Rec* prev = rec->fPrev;
        this->remove(rec);
        rec = prev;
    }
}

//#define SK_TRACK_PURGE_SHAREDID_HITRATE

#ifdef SK_TRACK_PURGE_SHAREDID_HITRATE
static int gPurgeCallCounter;
static int gPurgeHitCounter;
#endif

<<<<<<< HEAD
void SkResourceCache::purgeSharedID(uint64_t sharedID)
{
=======
void SkResourceCache::purgeSharedID(uint64_t sharedID) {
>>>>>>> miniblink49
    if (0 == sharedID) {
        return;
    }

#ifdef SK_TRACK_PURGE_SHAREDID_HITRATE
    gPurgeCallCounter += 1;
    bool found = false;
#endif
    // go backwards, just like purgeAsNeeded, just to make the code similar.
    // could iterate either direction and still be correct.
    Rec* rec = fTail;
    while (rec) {
        Rec* prev = rec->fPrev;
        if (rec->getKey().getSharedID() == sharedID) {
<<<<<<< HEAD
            //            SkDebugf("purgeSharedID id=%llx rec=%p\n", sharedID, rec);
=======
//            SkDebugf("purgeSharedID id=%llx rec=%p\n", sharedID, rec);
>>>>>>> miniblink49
            this->remove(rec);
#ifdef SK_TRACK_PURGE_SHAREDID_HITRATE
            found = true;
#endif
        }
        rec = prev;
    }

#ifdef SK_TRACK_PURGE_SHAREDID_HITRATE
    if (found) {
        gPurgeHitCounter += 1;
    }

    SkDebugf("PurgeShared calls=%d hits=%d rate=%g\n", gPurgeCallCounter, gPurgeHitCounter,
<<<<<<< HEAD
        gPurgeHitCounter * 100.0 / gPurgeCallCounter);
#endif
}

void SkResourceCache::visitAll(Visitor visitor, void* context)
{
    // go backwards, just like purgeAsNeeded, just to make the code similar.
    // could iterate either direction and still be correct.
    Rec* rec = fTail;
    while (rec) {
        visitor(*rec, context);
        rec = rec->fPrev;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

size_t SkResourceCache::setTotalByteLimit(size_t newLimit)
{
=======
             gPurgeHitCounter * 100.0 / gPurgeCallCounter);
#endif
}

size_t SkResourceCache::setTotalByteLimit(size_t newLimit) {
>>>>>>> miniblink49
    size_t prevLimit = fTotalByteLimit;
    fTotalByteLimit = newLimit;
    if (newLimit < prevLimit) {
        this->purgeAsNeeded();
    }
    return prevLimit;
}

<<<<<<< HEAD
SkCachedData* SkResourceCache::newCachedData(size_t bytes)
{
=======
SkCachedData* SkResourceCache::newCachedData(size_t bytes) {
>>>>>>> miniblink49
    this->checkMessages();

    if (fDiscardableFactory) {
        SkDiscardableMemory* dm = fDiscardableFactory(bytes);
<<<<<<< HEAD
        return dm ? new SkCachedData(bytes, dm) : nullptr;
    } else {
        return new SkCachedData(sk_malloc_throw(bytes), bytes);
=======
        return dm ? SkNEW_ARGS(SkCachedData, (bytes, dm)) : NULL;
    } else {
        return SkNEW_ARGS(SkCachedData, (sk_malloc_throw(bytes), bytes));
>>>>>>> miniblink49
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkResourceCache::release(Rec* rec)
{
=======
void SkResourceCache::detach(Rec* rec) {
>>>>>>> miniblink49
    Rec* prev = rec->fPrev;
    Rec* next = rec->fNext;

    if (!prev) {
        SkASSERT(fHead == rec);
        fHead = next;
    } else {
        prev->fNext = next;
    }

    if (!next) {
        fTail = prev;
    } else {
        next->fPrev = prev;
    }

<<<<<<< HEAD
    rec->fNext = rec->fPrev = nullptr;
}

void SkResourceCache::moveToHead(Rec* rec)
{
=======
    rec->fNext = rec->fPrev = NULL;
}

void SkResourceCache::moveToHead(Rec* rec) {
>>>>>>> miniblink49
    if (fHead == rec) {
        return;
    }

    SkASSERT(fHead);
    SkASSERT(fTail);

    this->validate();

<<<<<<< HEAD
    this->release(rec);
=======
    this->detach(rec);
>>>>>>> miniblink49

    fHead->fPrev = rec;
    rec->fNext = fHead;
    fHead = rec;

    this->validate();
}

<<<<<<< HEAD
void SkResourceCache::addToHead(Rec* rec)
{
    this->validate();

    rec->fPrev = nullptr;
=======
void SkResourceCache::addToHead(Rec* rec) {
    this->validate();

    rec->fPrev = NULL;
>>>>>>> miniblink49
    rec->fNext = fHead;
    if (fHead) {
        fHead->fPrev = rec;
    }
    fHead = rec;
    if (!fTail) {
        fTail = rec;
    }
    fTotalBytesUsed += rec->bytesUsed();
    fCount += 1;

    this->validate();
}

///////////////////////////////////////////////////////////////////////////////

#ifdef SK_DEBUG
<<<<<<< HEAD
void SkResourceCache::validate() const
{
    if (nullptr == fHead) {
        SkASSERT(nullptr == fTail);
=======
void SkResourceCache::validate() const {
    if (NULL == fHead) {
        SkASSERT(NULL == fTail);
>>>>>>> miniblink49
        SkASSERT(0 == fTotalBytesUsed);
        return;
    }

    if (fHead == fTail) {
<<<<<<< HEAD
        SkASSERT(nullptr == fHead->fPrev);
        SkASSERT(nullptr == fHead->fNext);
=======
        SkASSERT(NULL == fHead->fPrev);
        SkASSERT(NULL == fHead->fNext);
>>>>>>> miniblink49
        SkASSERT(fHead->bytesUsed() == fTotalBytesUsed);
        return;
    }

<<<<<<< HEAD
    SkASSERT(nullptr == fHead->fPrev);
    SkASSERT(fHead->fNext);
    SkASSERT(nullptr == fTail->fNext);
=======
    SkASSERT(NULL == fHead->fPrev);
    SkASSERT(fHead->fNext);
    SkASSERT(NULL == fTail->fNext);
>>>>>>> miniblink49
    SkASSERT(fTail->fPrev);

    size_t used = 0;
    int count = 0;
    const Rec* rec = fHead;
    while (rec) {
        count += 1;
        used += rec->bytesUsed();
        SkASSERT(used <= fTotalBytesUsed);
        rec = rec->fNext;
    }
    SkASSERT(fCount == count);

    rec = fTail;
    while (rec) {
        SkASSERT(count > 0);
        count -= 1;
        SkASSERT(used >= rec->bytesUsed());
        used -= rec->bytesUsed();
        rec = rec->fPrev;
    }

    SkASSERT(0 == count);
    SkASSERT(0 == used);
}
#endif

<<<<<<< HEAD
void SkResourceCache::dump() const
{
    this->validate();

    SkDebugf("SkResourceCache: count=%d bytes=%d %s\n",
        fCount, fTotalBytesUsed, fDiscardableFactory ? "discardable" : "malloc");
}

size_t SkResourceCache::setSingleAllocationByteLimit(size_t newLimit)
{
=======
void SkResourceCache::dump() const {
    this->validate();

    SkDebugf("SkResourceCache: count=%d bytes=%d %s\n",
             fCount, fTotalBytesUsed, fDiscardableFactory ? "discardable" : "malloc");
}

size_t SkResourceCache::setSingleAllocationByteLimit(size_t newLimit) {
>>>>>>> miniblink49
    size_t oldLimit = fSingleAllocationByteLimit;
    fSingleAllocationByteLimit = newLimit;
    return oldLimit;
}

<<<<<<< HEAD
size_t SkResourceCache::getSingleAllocationByteLimit() const
{
    return fSingleAllocationByteLimit;
}

size_t SkResourceCache::getEffectiveSingleAllocationByteLimit() const
{
=======
size_t SkResourceCache::getSingleAllocationByteLimit() const {
    return fSingleAllocationByteLimit;
}

size_t SkResourceCache::getEffectiveSingleAllocationByteLimit() const {
>>>>>>> miniblink49
    // fSingleAllocationByteLimit == 0 means the caller is asking for our default
    size_t limit = fSingleAllocationByteLimit;

    // if we're not discardable (i.e. we are fixed-budget) then cap the single-limit
    // to our budget.
<<<<<<< HEAD
    if (nullptr == fDiscardableFactory) {
=======
    if (NULL == fDiscardableFactory) {
>>>>>>> miniblink49
        if (0 == limit) {
            limit = fTotalByteLimit;
        } else {
            limit = SkTMin(limit, fTotalByteLimit);
        }
    }
    return limit;
}

<<<<<<< HEAD
void SkResourceCache::checkMessages()
{
=======
void SkResourceCache::checkMessages() {
>>>>>>> miniblink49
    SkTArray<PurgeSharedIDMessage> msgs;
    fPurgeSharedIDInbox.poll(&msgs);
    for (int i = 0; i < msgs.count(); ++i) {
        this->purgeSharedID(msgs[i].fSharedID);
    }
}

///////////////////////////////////////////////////////////////////////////////

SK_DECLARE_STATIC_MUTEX(gMutex);
<<<<<<< HEAD
static SkResourceCache* gResourceCache = nullptr;

/** Must hold gMutex when calling. */
static SkResourceCache* get_cache()
{
    // gMutex is always held when this is called, so we don't need to be fancy in here.
    gMutex.assertHeld();
    if (nullptr == gResourceCache) {
#ifdef SK_USE_DISCARDABLE_SCALEDIMAGECACHE
        gResourceCache = new SkResourceCache(SkDiscardableMemory::Create);
#else
        gResourceCache = new SkResourceCache(SK_DEFAULT_IMAGE_CACHE_LIMIT);
#endif
=======
static SkResourceCache* gResourceCache = NULL;
static void cleanup_gResourceCache() {
    // We'll clean this up in our own tests, but disable for clients.
    // Chrome seems to have funky multi-process things going on in unit tests that
    // makes this unsafe to delete when the main process atexit()s.
    // SkLazyPtr does the same sort of thing.
#if SK_DEVELOPER
    SkDELETE(gResourceCache);
#endif
}

/** Must hold gMutex when calling. */
static SkResourceCache* get_cache() {
    // gMutex is always held when this is called, so we don't need to be fancy in here.
    gMutex.assertHeld();
    if (NULL == gResourceCache) {
#ifdef SK_USE_DISCARDABLE_SCALEDIMAGECACHE
        gResourceCache = SkNEW_ARGS(SkResourceCache, (SkDiscardableMemory::Create));
#else
        gResourceCache = SkNEW_ARGS(SkResourceCache, (SK_DEFAULT_IMAGE_CACHE_LIMIT));
#endif
        atexit(cleanup_gResourceCache);
>>>>>>> miniblink49
    }
    return gResourceCache;
}

<<<<<<< HEAD
size_t SkResourceCache::GetTotalBytesUsed()
{
=======
size_t SkResourceCache::GetTotalBytesUsed() {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->getTotalBytesUsed();
}

<<<<<<< HEAD
size_t SkResourceCache::GetTotalByteLimit()
{
=======
size_t SkResourceCache::GetTotalByteLimit() {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->getTotalByteLimit();
}

<<<<<<< HEAD
size_t SkResourceCache::SetTotalByteLimit(size_t newLimit)
{
=======
size_t SkResourceCache::SetTotalByteLimit(size_t newLimit) {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->setTotalByteLimit(newLimit);
}

<<<<<<< HEAD
SkResourceCache::DiscardableFactory SkResourceCache::GetDiscardableFactory()
{
=======
SkResourceCache::DiscardableFactory SkResourceCache::GetDiscardableFactory() {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->discardableFactory();
}

<<<<<<< HEAD
SkBitmap::Allocator* SkResourceCache::GetAllocator()
{
=======
SkBitmap::Allocator* SkResourceCache::GetAllocator() {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->allocator();
}

<<<<<<< HEAD
SkCachedData* SkResourceCache::NewCachedData(size_t bytes)
{
=======
SkCachedData* SkResourceCache::NewCachedData(size_t bytes) {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->newCachedData(bytes);
}

<<<<<<< HEAD
void SkResourceCache::Dump()
{
=======
void SkResourceCache::Dump() {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    get_cache()->dump();
}

<<<<<<< HEAD
size_t SkResourceCache::SetSingleAllocationByteLimit(size_t size)
{
=======
size_t SkResourceCache::SetSingleAllocationByteLimit(size_t size) {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->setSingleAllocationByteLimit(size);
}

<<<<<<< HEAD
size_t SkResourceCache::GetSingleAllocationByteLimit()
{
=======
size_t SkResourceCache::GetSingleAllocationByteLimit() {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->getSingleAllocationByteLimit();
}

<<<<<<< HEAD
size_t SkResourceCache::GetEffectiveSingleAllocationByteLimit()
{
=======
size_t SkResourceCache::GetEffectiveSingleAllocationByteLimit() {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->getEffectiveSingleAllocationByteLimit();
}

<<<<<<< HEAD
void SkResourceCache::PurgeAll()
{
=======
void SkResourceCache::PurgeAll() {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->purgeAll();
}

<<<<<<< HEAD
bool SkResourceCache::Find(const Key& key, FindVisitor visitor, void* context)
{
=======
bool SkResourceCache::Find(const Key& key, FindVisitor visitor, void* context) {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    return get_cache()->find(key, visitor, context);
}

<<<<<<< HEAD
void SkResourceCache::Add(Rec* rec)
{
=======
void SkResourceCache::Add(Rec* rec) {
>>>>>>> miniblink49
    SkAutoMutexAcquire am(gMutex);
    get_cache()->add(rec);
}

<<<<<<< HEAD
void SkResourceCache::VisitAll(Visitor visitor, void* context)
{
    SkAutoMutexAcquire am(gMutex);
    get_cache()->visitAll(visitor, context);
}

void SkResourceCache::PostPurgeSharedID(uint64_t sharedID)
{
=======
void SkResourceCache::PostPurgeSharedID(uint64_t sharedID) {
>>>>>>> miniblink49
    if (sharedID) {
        SkMessageBus<PurgeSharedIDMessage>::Post(PurgeSharedIDMessage(sharedID));
    }
}

///////////////////////////////////////////////////////////////////////////////

#include "SkGraphics.h"
#include "SkImageFilter.h"

<<<<<<< HEAD
size_t SkGraphics::GetResourceCacheTotalBytesUsed()
{
    return SkResourceCache::GetTotalBytesUsed();
}

size_t SkGraphics::GetResourceCacheTotalByteLimit()
{
    return SkResourceCache::GetTotalByteLimit();
}

size_t SkGraphics::SetResourceCacheTotalByteLimit(size_t newLimit)
{
    return SkResourceCache::SetTotalByteLimit(newLimit);
}

size_t SkGraphics::GetResourceCacheSingleAllocationByteLimit()
{
    return SkResourceCache::GetSingleAllocationByteLimit();
}

size_t SkGraphics::SetResourceCacheSingleAllocationByteLimit(size_t newLimit)
{
    return SkResourceCache::SetSingleAllocationByteLimit(newLimit);
}

void SkGraphics::PurgeResourceCache()
{
=======
size_t SkGraphics::GetResourceCacheTotalBytesUsed() {
    return SkResourceCache::GetTotalBytesUsed();
}

size_t SkGraphics::GetResourceCacheTotalByteLimit() {
    return SkResourceCache::GetTotalByteLimit();
}

size_t SkGraphics::SetResourceCacheTotalByteLimit(size_t newLimit) {
    return SkResourceCache::SetTotalByteLimit(newLimit);
}

size_t SkGraphics::GetResourceCacheSingleAllocationByteLimit() {
    return SkResourceCache::GetSingleAllocationByteLimit();
}

size_t SkGraphics::SetResourceCacheSingleAllocationByteLimit(size_t newLimit) {
    return SkResourceCache::SetSingleAllocationByteLimit(newLimit);
}

void SkGraphics::PurgeResourceCache() {
>>>>>>> miniblink49
    SkImageFilter::PurgeCache();
    return SkResourceCache::PurgeAll();
}

<<<<<<< HEAD
/////////////

static void dump_visitor(const SkResourceCache::Rec& rec, void*)
{
    SkDebugf("RC: %12s bytes %9lu  discardable %p\n",
        rec.getCategory(), rec.bytesUsed(), rec.diagnostic_only_getDiscardable());
}

void SkResourceCache::TestDumpMemoryStatistics()
{
    VisitAll(dump_visitor, nullptr);
}

static void sk_trace_dump_visitor(const SkResourceCache::Rec& rec, void* context)
{
    SkTraceMemoryDump* dump = static_cast<SkTraceMemoryDump*>(context);
    SkString dumpName = SkStringPrintf("skia/sk_resource_cache/%s_%p", rec.getCategory(), &rec);
    SkDiscardableMemory* discardable = rec.diagnostic_only_getDiscardable();
    if (discardable) {
        dump->setDiscardableMemoryBacking(dumpName.c_str(), *discardable);

        // The discardable memory size will be calculated by dumper, but we also dump what we think
        // the size of object in memory is irrespective of whether object is live or dead.
        dump->dumpNumericValue(dumpName.c_str(), "discardable_size", "bytes", rec.bytesUsed());
    } else {
        dump->dumpNumericValue(dumpName.c_str(), "size", "bytes", rec.bytesUsed());
        dump->setMemoryBacking(dumpName.c_str(), "malloc", nullptr);
    }
}

void SkResourceCache::DumpMemoryStatistics(SkTraceMemoryDump* dump)
{
    // Since resource could be backed by malloc or discardable, the cache always dumps detailed
    // stats to be accurate.
    VisitAll(sk_trace_dump_visitor, dump);
}
=======
>>>>>>> miniblink49
