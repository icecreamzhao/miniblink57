/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkPixelRef.h"
#include "SkBitmapCache.h"
#include "SkMutex.h"
=======
#include "SkBitmapCache.h"
#include "SkMutex.h"
#include "SkPixelRef.h"
>>>>>>> miniblink49
#include "SkTraceEvent.h"

//#define SK_SUPPORT_LEGACY_UNBALANCED_PIXELREF_LOCKCOUNT
//#define SK_TRACE_PIXELREF_LIFETIME

<<<<<<< HEAD
#include "SkNextID.h"

uint32_t SkNextID::ImageID()
{
    static uint32_t gID = 0;
    uint32_t id;
    // Loop in case our global wraps around, as we never want to return a 0.
    do {
        id = sk_atomic_fetch_add(&gID, 2u) + 2; // Never set the low bit.
    } while (0 == id);
    return id;
=======
#ifdef SK_BUILD_FOR_WIN32
    // We don't have SK_BASE_MUTEX_INIT on Windows.

    // must be a power-of-2. undef to just use 1 mutex
    #define PIXELREF_MUTEX_RING_COUNT       32
    static SkBaseMutex gPixelRefMutexRing[PIXELREF_MUTEX_RING_COUNT];

#else
    static SkBaseMutex gPixelRefMutexRing[] = {
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,

        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,

        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,

        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
        SK_BASE_MUTEX_INIT, SK_BASE_MUTEX_INIT,
    };
    // must be a power-of-2. undef to just use 1 mutex
    #define PIXELREF_MUTEX_RING_COUNT SK_ARRAY_COUNT(gPixelRefMutexRing)

#endif

static SkBaseMutex* get_default_mutex() {
    static int32_t gPixelRefMutexRingIndex;

    SkASSERT(SkIsPow2(PIXELREF_MUTEX_RING_COUNT));

    // atomic_inc might be overkill here. It may be fine if once in a while
    // we hit a race-condition and two subsequent calls get the same index...
    int index = sk_atomic_inc(&gPixelRefMutexRingIndex);
    return &gPixelRefMutexRing[index & (PIXELREF_MUTEX_RING_COUNT - 1)];
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
// just need a > 0 value, so pick a funny one to aid in debugging
#define SKPIXELREF_PRELOCKED_LOCKCOUNT 123456789

static SkImageInfo validate_info(const SkImageInfo& info)
{
=======
static uint32_t next_gen_id() {
    static uint32_t gNextGenID = 0;
    uint32_t genID;
    // Loop in case our global wraps around, as we never want to return a 0.
    do {
        genID = sk_atomic_fetch_add(&gNextGenID, 2u) + 2;  // Never set the low bit.
    } while (0 == genID);
    return genID;
}

///////////////////////////////////////////////////////////////////////////////

void SkPixelRef::setMutex(SkBaseMutex* mutex) {
    if (NULL == mutex) {
        mutex = get_default_mutex();
    }
    fMutex = mutex;
}

// just need a > 0 value, so pick a funny one to aid in debugging
#define SKPIXELREF_PRELOCKED_LOCKCOUNT     123456789

static SkImageInfo validate_info(const SkImageInfo& info) {
>>>>>>> miniblink49
    SkAlphaType newAlphaType = info.alphaType();
    SkAssertResult(SkColorTypeValidateAlphaType(info.colorType(), info.alphaType(), &newAlphaType));
    return info.makeAlphaType(newAlphaType);
}

#ifdef SK_TRACE_PIXELREF_LIFETIME
<<<<<<< HEAD
static int32_t gInstCounter;
=======
    static int32_t gInstCounter;
>>>>>>> miniblink49
#endif

SkPixelRef::SkPixelRef(const SkImageInfo& info)
    : fInfo(validate_info(info))
#ifdef SK_BUILD_FOR_ANDROID_FRAMEWORK
<<<<<<< HEAD
    , fStableID(SkNextID::ImageID())
=======
    , fStableID(next_gen_id())
>>>>>>> miniblink49
#endif

{
#ifdef SK_TRACE_PIXELREF_LIFETIME
    SkDebugf(" pixelref %d\n", sk_atomic_inc(&gInstCounter));
#endif
<<<<<<< HEAD
    fRec.zero();
    fLockCount = 0;
    this->needsNewGenID();
    fMutability = kMutable;
=======
    this->setMutex(NULL);
    fRec.zero();
    fLockCount = 0;
    this->needsNewGenID();
    fIsImmutable = false;
>>>>>>> miniblink49
    fPreLocked = false;
    fAddedToCache.store(false);
}

<<<<<<< HEAD
SkPixelRef::~SkPixelRef()
{
=======

SkPixelRef::SkPixelRef(const SkImageInfo& info, SkBaseMutex* mutex)
    : fInfo(validate_info(info))
#ifdef SK_BUILD_FOR_ANDROID_FRAMEWORK
    , fStableID(next_gen_id())
#endif
{
#ifdef SK_TRACE_PIXELREF_LIFETIME
    SkDebugf(" pixelref %d\n", sk_atomic_inc(&gInstCounter));
#endif
    this->setMutex(mutex);
    fRec.zero();
    fLockCount = 0;
    this->needsNewGenID();
    fIsImmutable = false;
    fPreLocked = false;
    fAddedToCache.store(false);
}

SkPixelRef::~SkPixelRef() {
>>>>>>> miniblink49
#ifndef SK_SUPPORT_LEGACY_UNBALANCED_PIXELREF_LOCKCOUNT
    SkASSERT(SKPIXELREF_PRELOCKED_LOCKCOUNT == fLockCount || 0 == fLockCount);
#endif

#ifdef SK_TRACE_PIXELREF_LIFETIME
    SkDebugf("~pixelref %d\n", sk_atomic_dec(&gInstCounter) - 1);
#endif
    this->callGenIDChangeListeners();
}

<<<<<<< HEAD
void SkPixelRef::needsNewGenID()
{
=======
void SkPixelRef::needsNewGenID() {
>>>>>>> miniblink49
    fTaggedGenID.store(0);
    SkASSERT(!this->genIDIsUnique()); // This method isn't threadsafe, so the assert should be fine.
}

<<<<<<< HEAD
void SkPixelRef::cloneGenID(const SkPixelRef& that)
{
=======
void SkPixelRef::cloneGenID(const SkPixelRef& that) {
>>>>>>> miniblink49
    // This is subtle.  We must call that.getGenerationID() to make sure its genID isn't 0.
    uint32_t genID = that.getGenerationID();

    // Neither ID is unique any more.
    // (These & ~1u are actually redundant.  that.getGenerationID() just did it for us.)
    this->fTaggedGenID.store(genID & ~1u);
<<<<<<< HEAD
    that.fTaggedGenID.store(genID & ~1u);

    // This method isn't threadsafe, so these asserts should be fine.
    SkASSERT(!this->genIDIsUnique());
    SkASSERT(!that.genIDIsUnique());
}

static void validate_pixels_ctable(const SkImageInfo& info, const SkColorTable* ctable)
{
    if (info.isEmpty()) {
        return; // can't require ctable if the dimensions are empty
    }
    if (kIndex_8_SkColorType == info.colorType()) {
        SkASSERT(ctable);
    } else {
        SkASSERT(nullptr == ctable);
    }
}

void SkPixelRef::setPreLocked(void* pixels, size_t rowBytes, SkColorTable* ctable)
{
    SkASSERT(pixels);
    validate_pixels_ctable(fInfo, ctable);
=======
    that. fTaggedGenID.store(genID & ~1u);

    // This method isn't threadsafe, so these asserts should be fine.
    SkASSERT(!this->genIDIsUnique());
    SkASSERT(!that. genIDIsUnique());
}

static void validate_pixels_ctable(const SkImageInfo& info, const void* pixels,
                                   const SkColorTable* ctable) {
    if (info.isEmpty()) {
        return; // can't require pixels if the dimensions are empty
    }
    SkASSERT(pixels);
    if (kIndex_8_SkColorType == info.colorType()) {
        SkASSERT(ctable);
    } else {
        SkASSERT(NULL == ctable);
    }
}

void SkPixelRef::setPreLocked(void* pixels, size_t rowBytes, SkColorTable* ctable) {
#ifndef SK_IGNORE_PIXELREF_SETPRELOCKED
    validate_pixels_ctable(fInfo, pixels, ctable);
>>>>>>> miniblink49
    // only call me in your constructor, otherwise fLockCount tracking can get
    // out of sync.
    fRec.fPixels = pixels;
    fRec.fColorTable = ctable;
    fRec.fRowBytes = rowBytes;
    fLockCount = SKPIXELREF_PRELOCKED_LOCKCOUNT;
    fPreLocked = true;
<<<<<<< HEAD
}

// Increments fLockCount only on success
bool SkPixelRef::lockPixelsInsideMutex()
{
    fMutex.assertHeld();
=======
#endif
}

// Increments fLockCount only on success
bool SkPixelRef::lockPixelsInsideMutex() {
    fMutex->assertHeld();
>>>>>>> miniblink49

    if (1 == ++fLockCount) {
        SkASSERT(fRec.isZero());
        if (!this->onNewLockPixels(&fRec)) {
            fRec.zero();
<<<<<<< HEAD
            fLockCount -= 1; // we return fLockCount unchanged if we fail.
            return false;
        }
    }
    if (fRec.fPixels) {
        validate_pixels_ctable(fInfo, fRec.fColorTable);
        return true;
    }
    // no pixels, so we failed (somehow)
    --fLockCount;
    return false;
=======
            fLockCount -= 1;    // we return fLockCount unchanged if we fail.
            return false;
        }
    }
    validate_pixels_ctable(fInfo, fRec.fPixels, fRec.fColorTable);
    return fRec.fPixels != NULL;
>>>>>>> miniblink49
}

// For historical reasons, we always inc fLockCount, even if we return false.
// It would be nice to change this (it seems), and only inc if we actually succeed...
<<<<<<< HEAD
bool SkPixelRef::lockPixels()
{
=======
bool SkPixelRef::lockPixels() {
>>>>>>> miniblink49
    SkASSERT(!fPreLocked || SKPIXELREF_PRELOCKED_LOCKCOUNT == fLockCount);

    if (!fPreLocked) {
        TRACE_EVENT_BEGIN0("skia", "SkPixelRef::lockPixelsMutex");
<<<<<<< HEAD
        SkAutoMutexAcquire ac(fMutex);
        TRACE_EVENT_END0("skia", "SkPixelRef::lockPixelsMutex");
        SkDEBUGCODE(int oldCount = fLockCount;) bool success = this->lockPixelsInsideMutex();
=======
        SkAutoMutexAcquire  ac(*fMutex);
        TRACE_EVENT_END0("skia", "SkPixelRef::lockPixelsMutex");
        SkDEBUGCODE(int oldCount = fLockCount;)
        bool success = this->lockPixelsInsideMutex();
>>>>>>> miniblink49
        // lockPixelsInsideMutex only increments the count if it succeeds.
        SkASSERT(oldCount + (int)success == fLockCount);

        if (!success) {
            // For compatibility with SkBitmap calling lockPixels, we still want to increment
            // fLockCount even if we failed. If we updated SkBitmap we could remove this oddity.
            fLockCount += 1;
            return false;
        }
    }
<<<<<<< HEAD
    if (fRec.fPixels) {
        validate_pixels_ctable(fInfo, fRec.fColorTable);
        return true;
    }
    return false;
}

bool SkPixelRef::lockPixels(LockRec* rec)
{
=======
    validate_pixels_ctable(fInfo, fRec.fPixels, fRec.fColorTable);
    return fRec.fPixels != NULL;
}

bool SkPixelRef::lockPixels(LockRec* rec) {
>>>>>>> miniblink49
    if (this->lockPixels()) {
        *rec = fRec;
        return true;
    }
    return false;
}

<<<<<<< HEAD
void SkPixelRef::unlockPixels()
{
    SkASSERT(!fPreLocked || SKPIXELREF_PRELOCKED_LOCKCOUNT == fLockCount);

    if (!fPreLocked) {
        SkAutoMutexAcquire ac(fMutex);
=======
void SkPixelRef::unlockPixels() {
    SkASSERT(!fPreLocked || SKPIXELREF_PRELOCKED_LOCKCOUNT == fLockCount);

    if (!fPreLocked) {
        SkAutoMutexAcquire  ac(*fMutex);
>>>>>>> miniblink49

        SkASSERT(fLockCount > 0);
        if (0 == --fLockCount) {
            // don't call onUnlockPixels unless onLockPixels succeeded
            if (fRec.fPixels) {
                this->onUnlockPixels();
                fRec.zero();
            } else {
                SkASSERT(fRec.isZero());
            }
        }
    }
}

<<<<<<< HEAD
bool SkPixelRef::requestLock(const LockRequest& request, LockResult* result)
{
=======
bool SkPixelRef::requestLock(const LockRequest& request, LockResult* result) {
>>>>>>> miniblink49
    SkASSERT(result);
    if (request.fSize.isEmpty()) {
        return false;
    }
    // until we support subsets, we have to check this...
    if (request.fSize.width() != fInfo.width() || request.fSize.height() != fInfo.height()) {
        return false;
    }

    if (fPreLocked) {
<<<<<<< HEAD
        result->fUnlockProc = nullptr;
        result->fUnlockContext = nullptr;
=======
        result->fUnlockProc = NULL;
        result->fUnlockContext = NULL;
>>>>>>> miniblink49
        result->fCTable = fRec.fColorTable;
        result->fPixels = fRec.fPixels;
        result->fRowBytes = fRec.fRowBytes;
        result->fSize.set(fInfo.width(), fInfo.height());
    } else {
<<<<<<< HEAD
        SkAutoMutexAcquire ac(fMutex);
=======
        SkAutoMutexAcquire  ac(*fMutex);
>>>>>>> miniblink49
        if (!this->onRequestLock(request, result)) {
            return false;
        }
    }
<<<<<<< HEAD
    if (result->fPixels) {
        validate_pixels_ctable(fInfo, result->fCTable);
        return true;
    }
    return false;
}

bool SkPixelRef::lockPixelsAreWritable() const
{
    return this->onLockPixelsAreWritable();
}

bool SkPixelRef::onLockPixelsAreWritable() const
{
    return true;
}

uint32_t SkPixelRef::getGenerationID() const
{
    uint32_t id = fTaggedGenID.load();
    if (0 == id) {
        uint32_t next = SkNextID::ImageID() | 1u;
        if (fTaggedGenID.compare_exchange(&id, next)) {
            id = next; // There was no race or we won the race.  fTaggedGenID is next now.
=======
    validate_pixels_ctable(fInfo, result->fPixels, result->fCTable);
    return result->fPixels != NULL;
}

bool SkPixelRef::lockPixelsAreWritable() const {
    return this->onLockPixelsAreWritable();
}

bool SkPixelRef::onLockPixelsAreWritable() const {
    return true;
}

uint32_t SkPixelRef::getGenerationID() const {
    uint32_t id = fTaggedGenID.load();
    if (0 == id) {
        uint32_t next = next_gen_id() | 1u;
        if (fTaggedGenID.compare_exchange(&id, next)) {
            id = next;  // There was no race or we won the race.  fTaggedGenID is next now.
>>>>>>> miniblink49
        } else {
            // We lost a race to set fTaggedGenID. compare_exchange() filled id with the winner.
        }
        // We can't quite SkASSERT(this->genIDIsUnique()). It could be non-unique
        // if we got here via the else path (pretty unlikely, but possible).
    }
<<<<<<< HEAD
    return id & ~1u; // Mask off bottom unique bit.
}

void SkPixelRef::addGenIDChangeListener(GenIDChangeListener* listener)
{
    if (nullptr == listener || !this->genIDIsUnique()) {
        // No point in tracking this if we're not going to call it.
        delete listener;
=======
    return id & ~1u;  // Mask off bottom unique bit.
}

void SkPixelRef::addGenIDChangeListener(GenIDChangeListener* listener) {
    if (NULL == listener || !this->genIDIsUnique()) {
        // No point in tracking this if we're not going to call it.
        SkDELETE(listener);
>>>>>>> miniblink49
        return;
    }
    *fGenIDChangeListeners.append() = listener;
}

// we need to be called *before* the genID gets changed or zerod
<<<<<<< HEAD
void SkPixelRef::callGenIDChangeListeners()
{
=======
void SkPixelRef::callGenIDChangeListeners() {
>>>>>>> miniblink49
    // We don't invalidate ourselves if we think another SkPixelRef is sharing our genID.
    if (this->genIDIsUnique()) {
        for (int i = 0; i < fGenIDChangeListeners.count(); i++) {
            fGenIDChangeListeners[i]->onChange();
        }

        // TODO: SkAtomic could add "old_value = atomic.xchg(new_value)" to make this clearer.
        if (fAddedToCache.load()) {
            SkNotifyBitmapGenIDIsStale(this->getGenerationID());
            fAddedToCache.store(false);
        }
    }
    // Listeners get at most one shot, so whether these triggered or not, blow them away.
    fGenIDChangeListeners.deleteAll();
}

<<<<<<< HEAD
void SkPixelRef::notifyPixelsChanged()
{
#ifdef SK_DEBUG
    if (this->isImmutable()) {
=======
void SkPixelRef::notifyPixelsChanged() {
#ifdef SK_DEBUG
    if (fIsImmutable) {
>>>>>>> miniblink49
        SkDebugf("========== notifyPixelsChanged called on immutable pixelref");
    }
#endif
    this->callGenIDChangeListeners();
    this->needsNewGenID();
    this->onNotifyPixelsChanged();
}

<<<<<<< HEAD
void SkPixelRef::changeAlphaType(SkAlphaType at)
{
    *const_cast<SkImageInfo*>(&fInfo) = fInfo.makeAlphaType(at);
}

void SkPixelRef::setImmutable()
{
    fMutability = kImmutable;
}

void SkPixelRef::setImmutableWithID(uint32_t genID)
{
    /*
     *  We are forcing the genID to match an external value. The caller must ensure that this
     *  value does not conflict with other content.
     *
     *  One use is to force this pixelref's id to match an SkImage's id
     */
    fMutability = kImmutable;
    fTaggedGenID.store(genID);
}

void SkPixelRef::setTemporarilyImmutable()
{
    SkASSERT(fMutability != kImmutable);
    fMutability = kTemporarilyImmutable;
}

void SkPixelRef::restoreMutability()
{
    SkASSERT(fMutability != kImmutable);
    fMutability = kMutable;
}

bool SkPixelRef::readPixels(SkBitmap* dst, SkColorType ct, const SkIRect* subset)
{
    return this->onReadPixels(dst, ct, subset);
=======
void SkPixelRef::changeAlphaType(SkAlphaType at) {
    *const_cast<SkImageInfo*>(&fInfo) = fInfo.makeAlphaType(at);
}

void SkPixelRef::setImmutable() {
    fIsImmutable = true;
}

bool SkPixelRef::readPixels(SkBitmap* dst, const SkIRect* subset) {
    return this->onReadPixels(dst, subset);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool SkPixelRef::onReadPixels(SkBitmap* dst, SkColorType, const SkIRect* subset)
{
=======
bool SkPixelRef::onReadPixels(SkBitmap* dst, const SkIRect* subset) {
>>>>>>> miniblink49
    return false;
}

void SkPixelRef::onNotifyPixelsChanged() { }

<<<<<<< HEAD
SkData* SkPixelRef::onRefEncodedData()
{
    return nullptr;
}

size_t SkPixelRef::getAllocatedSizeInBytes() const
{
    return 0;
}

static void unlock_legacy_result(void* ctx)
{
    SkPixelRef* pr = (SkPixelRef*)ctx;
    pr->unlockPixels();
    pr->unref(); // balancing the Ref in onRequestLoc
}

bool SkPixelRef::onRequestLock(const LockRequest& request, LockResult* result)
{
=======
SkData* SkPixelRef::onRefEncodedData() {
    return NULL;
}

bool SkPixelRef::onGetYUV8Planes(SkISize sizes[3], void* planes[3], size_t rowBytes[3],
                                 SkYUVColorSpace* colorSpace) {
    return false;
}

size_t SkPixelRef::getAllocatedSizeInBytes() const {
    return 0;
}

static void unlock_legacy_result(void* ctx) {
    SkPixelRef* pr = (SkPixelRef*)ctx;
    pr->unlockPixels();
    pr->unref();    // balancing the Ref in onRequestLoc
}

bool SkPixelRef::onRequestLock(const LockRequest& request, LockResult* result) {
>>>>>>> miniblink49
    if (!this->lockPixelsInsideMutex()) {
        return false;
    }

    result->fUnlockProc = unlock_legacy_result;
<<<<<<< HEAD
    result->fUnlockContext = SkRef(this); // this is balanced in our fUnlockProc
=======
    result->fUnlockContext = SkRef(this);   // this is balanced in our fUnlockProc
>>>>>>> miniblink49
    result->fCTable = fRec.fColorTable;
    result->fPixels = fRec.fPixels;
    result->fRowBytes = fRec.fRowBytes;
    result->fSize.set(fInfo.width(), fInfo.height());
    return true;
}
