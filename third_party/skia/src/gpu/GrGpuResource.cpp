<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrGpuResource.h"
#include "GrContext.h"
<<<<<<< HEAD
#include "GrGpu.h"
#include "GrGpuResourcePriv.h"
#include "GrResourceCache.h"
#include "SkTraceMemoryDump.h"

static inline GrResourceCache* get_resource_cache(GrGpu* gpu)
{
=======
#include "GrResourceCache.h"
#include "GrGpu.h"
#include "GrGpuResourcePriv.h"

static inline GrResourceCache* get_resource_cache(GrGpu* gpu) {
>>>>>>> miniblink49
    SkASSERT(gpu);
    SkASSERT(gpu->getContext());
    SkASSERT(gpu->getContext()->getResourceCache());
    return gpu->getContext()->getResourceCache();
}

<<<<<<< HEAD
GrGpuResource::GrGpuResource(GrGpu* gpu)
    : fGpu(gpu)
    , fGpuMemorySize(kInvalidGpuMemorySize)
    , fBudgeted(SkBudgeted::kNo)
    , fRefsWrappedObjects(false)
    , fUniqueID(CreateUniqueID())
{
    SkDEBUGCODE(fCacheArrayIndex = -1);
}

void GrGpuResource::registerWithCache(SkBudgeted budgeted)
{
    SkASSERT(fBudgeted == SkBudgeted::kNo);
    fBudgeted = budgeted;
    this->computeScratchKey(&fScratchKey);
    get_resource_cache(fGpu)->resourceAccess().insertResource(this);
}

void GrGpuResource::registerWithCacheWrapped()
{
    SkASSERT(fBudgeted == SkBudgeted::kNo);
    // Currently resources referencing wrapped objects are not budgeted.
    fRefsWrappedObjects = true;
    get_resource_cache(fGpu)->resourceAccess().insertResource(this);
}

GrGpuResource::~GrGpuResource()
{
=======
GrGpuResource::GrGpuResource(GrGpu* gpu, LifeCycle lifeCycle)
    : fGpu(gpu)
    , fGpuMemorySize(kInvalidGpuMemorySize)
    , fLifeCycle(lifeCycle)
    , fUniqueID(CreateUniqueID()) {
    SkDEBUGCODE(fCacheArrayIndex = -1);
}

void GrGpuResource::registerWithCache() {
    get_resource_cache(fGpu)->resourceAccess().insertResource(this);
}

GrGpuResource::~GrGpuResource() {
>>>>>>> miniblink49
    // The cache should have released or destroyed this resource.
    SkASSERT(this->wasDestroyed());
}

<<<<<<< HEAD
void GrGpuResource::release()
{
    SkASSERT(fGpu);
    this->onRelease();
    get_resource_cache(fGpu)->resourceAccess().removeResource(this);
    fGpu = nullptr;
    fGpuMemorySize = 0;
}

void GrGpuResource::abandon()
{
    if (this->wasDestroyed()) {
        return;
    }
    SkASSERT(fGpu);
    this->onAbandon();
    get_resource_cache(fGpu)->resourceAccess().removeResource(this);
    fGpu = nullptr;
    fGpuMemorySize = 0;
}

void GrGpuResource::dumpMemoryStatistics(SkTraceMemoryDump* traceMemoryDump) const
{
    // Dump resource as "skia/gpu_resources/resource_#".
    SkString dumpName("skia/gpu_resources/resource_");
    dumpName.appendS32(this->getUniqueID());

    traceMemoryDump->dumpNumericValue(dumpName.c_str(), "size", "bytes", this->gpuMemorySize());

    if (this->isPurgeable()) {
        traceMemoryDump->dumpNumericValue(dumpName.c_str(), "purgeable_size", "bytes",
            this->gpuMemorySize());
    }

    // Call setMemoryBacking to allow sub-classes with implementation specific backings (such as GL
    // objects) to provide additional information.
    this->setMemoryBacking(traceMemoryDump, dumpName);
}

const SkData* GrGpuResource::setCustomData(const SkData* data)
{
=======
void GrGpuResource::release() { 
    SkASSERT(fGpu);
    this->onRelease();
    get_resource_cache(fGpu)->resourceAccess().removeResource(this);
    fGpu = NULL;
    fGpuMemorySize = 0;
}

void GrGpuResource::abandon() {
    SkASSERT(fGpu);
    this->onAbandon();
    get_resource_cache(fGpu)->resourceAccess().removeResource(this);
    fGpu = NULL;
    fGpuMemorySize = 0;
}

const SkData* GrGpuResource::setCustomData(const SkData* data) {
>>>>>>> miniblink49
    SkSafeRef(data);
    fData.reset(data);
    return data;
}

<<<<<<< HEAD
const GrContext* GrGpuResource::getContext() const
{
    if (fGpu) {
        return fGpu->getContext();
    } else {
        return nullptr;
    }
}

GrContext* GrGpuResource::getContext()
{
    if (fGpu) {
        return fGpu->getContext();
    } else {
        return nullptr;
    }
}

void GrGpuResource::didChangeGpuMemorySize() const
{
=======
const GrContext* GrGpuResource::getContext() const {
    if (fGpu) {
        return fGpu->getContext();
    } else {
        return NULL;
    }
}

GrContext* GrGpuResource::getContext() {
    if (fGpu) {
        return fGpu->getContext();
    } else {
        return NULL;
    }
}

void GrGpuResource::didChangeGpuMemorySize() const {
>>>>>>> miniblink49
    if (this->wasDestroyed()) {
        return;
    }

    size_t oldSize = fGpuMemorySize;
    SkASSERT(kInvalidGpuMemorySize != oldSize);
    fGpuMemorySize = kInvalidGpuMemorySize;
    get_resource_cache(fGpu)->resourceAccess().didChangeGpuMemorySize(this, oldSize);
}

<<<<<<< HEAD
void GrGpuResource::removeUniqueKey()
{
    if (this->wasDestroyed()) {
        return;
    }
=======
void GrGpuResource::removeUniqueKey() {
>>>>>>> miniblink49
    SkASSERT(fUniqueKey.isValid());
    get_resource_cache(fGpu)->resourceAccess().removeUniqueKey(this);
}

<<<<<<< HEAD
void GrGpuResource::setUniqueKey(const GrUniqueKey& key)
{
=======
void GrGpuResource::setUniqueKey(const GrUniqueKey& key) {
>>>>>>> miniblink49
    SkASSERT(this->internalHasRef());
    SkASSERT(key.isValid());

    // Wrapped and uncached resources can never have a unique key.
<<<<<<< HEAD
    if (SkBudgeted::kNo == this->resourcePriv().isBudgeted()) {
=======
    if (!this->resourcePriv().isBudgeted()) {
>>>>>>> miniblink49
        return;
    }

    if (this->wasDestroyed()) {
        return;
    }

    get_resource_cache(fGpu)->resourceAccess().changeUniqueKey(this, key);
}

<<<<<<< HEAD
void GrGpuResource::notifyAllCntsAreZero(CntType lastCntTypeToReachZero) const
{
    if (this->wasDestroyed()) {
        // We've already been removed from the cache. Goodbye cruel world!
        delete this;
=======
void GrGpuResource::notifyAllCntsAreZero(CntType lastCntTypeToReachZero) const {
    if (this->wasDestroyed()) {
        // We've already been removed from the cache. Goodbye cruel world!
        SkDELETE(this);
>>>>>>> miniblink49
        return;
    }

    // We should have already handled this fully in notifyRefCntIsZero().
    SkASSERT(kRef_CntType != lastCntTypeToReachZero);

    GrGpuResource* mutableThis = const_cast<GrGpuResource*>(this);
<<<<<<< HEAD
    static const uint32_t kFlag = GrResourceCache::ResourceAccess::kAllCntsReachedZero_RefNotificationFlag;
    get_resource_cache(fGpu)->resourceAccess().notifyCntReachedZero(mutableThis, kFlag);
}

bool GrGpuResource::notifyRefCountIsZero() const
{
=======
    static const uint32_t kFlag =
        GrResourceCache::ResourceAccess::kAllCntsReachedZero_RefNotificationFlag;
    get_resource_cache(fGpu)->resourceAccess().notifyCntReachedZero(mutableThis, kFlag);
}

bool GrGpuResource::notifyRefCountIsZero() const {
>>>>>>> miniblink49
    if (this->wasDestroyed()) {
        // handle this in notifyAllCntsAreZero().
        return true;
    }

    GrGpuResource* mutableThis = const_cast<GrGpuResource*>(this);
<<<<<<< HEAD
    uint32_t flags = GrResourceCache::ResourceAccess::kRefCntReachedZero_RefNotificationFlag;
=======
    uint32_t flags =
        GrResourceCache::ResourceAccess::kRefCntReachedZero_RefNotificationFlag;
>>>>>>> miniblink49
    if (!this->internalHasPendingIO()) {
        flags |= GrResourceCache::ResourceAccess::kAllCntsReachedZero_RefNotificationFlag;
    }
    get_resource_cache(fGpu)->resourceAccess().notifyCntReachedZero(mutableThis, flags);

    // There is no need to call our notifyAllCntsAreZero function at this point since we already
    // told the cache about the state of cnts.
    return false;
}

<<<<<<< HEAD
void GrGpuResource::removeScratchKey()
{
=======
void GrGpuResource::setScratchKey(const GrScratchKey& scratchKey) {
    SkASSERT(!fScratchKey.isValid());
    SkASSERT(scratchKey.isValid());
    // Wrapped resources can never have a scratch key.
    if (this->cacheAccess().isExternal()) {
        return;
    }
    fScratchKey = scratchKey;
}

void GrGpuResource::removeScratchKey() {
>>>>>>> miniblink49
    if (!this->wasDestroyed() && fScratchKey.isValid()) {
        get_resource_cache(fGpu)->resourceAccess().willRemoveScratchKey(this);
        fScratchKey.reset();
    }
}

<<<<<<< HEAD
void GrGpuResource::makeBudgeted()
{
    if (!this->wasDestroyed() && SkBudgeted::kNo == fBudgeted) {
        // Currently resources referencing wrapped objects are not budgeted.
        SkASSERT(!fRefsWrappedObjects);
        fBudgeted = SkBudgeted::kYes;
=======
void GrGpuResource::makeBudgeted() {
    if (GrGpuResource::kUncached_LifeCycle == fLifeCycle) {
        fLifeCycle = kCached_LifeCycle;
>>>>>>> miniblink49
        get_resource_cache(fGpu)->resourceAccess().didChangeBudgetStatus(this);
    }
}

<<<<<<< HEAD
void GrGpuResource::makeUnbudgeted()
{
    if (!this->wasDestroyed() && SkBudgeted::kYes == fBudgeted && !fUniqueKey.isValid()) {
        fBudgeted = SkBudgeted::kNo;
=======
void GrGpuResource::makeUnbudgeted() {
    if (GrGpuResource::kCached_LifeCycle == fLifeCycle && !fUniqueKey.isValid()) {
        fLifeCycle = kUncached_LifeCycle;
>>>>>>> miniblink49
        get_resource_cache(fGpu)->resourceAccess().didChangeBudgetStatus(this);
    }
}

<<<<<<< HEAD
uint32_t GrGpuResource::CreateUniqueID()
{
=======
uint32_t GrGpuResource::CreateUniqueID() {
>>>>>>> miniblink49
    static int32_t gUniqueID = SK_InvalidUniqueID;
    uint32_t id;
    do {
        id = static_cast<uint32_t>(sk_atomic_inc(&gUniqueID) + 1);
    } while (id == SK_InvalidUniqueID);
    return id;
}
