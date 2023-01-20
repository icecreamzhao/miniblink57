/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkDiscardablePixelRef.h"
#include "SkDiscardableMemory.h"
#include "SkImageGenerator.h"

SkDiscardablePixelRef::SkDiscardablePixelRef(const SkImageInfo& info,
<<<<<<< HEAD
    SkImageGenerator* generator,
    size_t rowBytes,
    SkDiscardableMemory::Factory* fact)
=======
                                             SkImageGenerator* generator,
                                             size_t rowBytes,
                                             SkDiscardableMemory::Factory* fact)
>>>>>>> miniblink49
    : INHERITED(info)
    , fGenerator(generator)
    , fDMFactory(fact)
    , fRowBytes(rowBytes)
<<<<<<< HEAD
    , fDiscardableMemory(nullptr)
    , fDiscardableMemoryIsLocked(false)
{
    SkASSERT(fGenerator != nullptr);
=======
    , fDiscardableMemory(NULL)
    , fDiscardableMemoryIsLocked(false)
{
    SkASSERT(fGenerator != NULL);
>>>>>>> miniblink49
    SkASSERT(fRowBytes > 0);
    // The SkImageGenerator contract requires fGenerator to always
    // decode the same image on each call to getPixels().
    this->setImmutable();
    SkSafeRef(fDMFactory);
}

<<<<<<< HEAD
SkDiscardablePixelRef::~SkDiscardablePixelRef()
{
=======
SkDiscardablePixelRef::~SkDiscardablePixelRef() {
>>>>>>> miniblink49
    if (fDiscardableMemoryIsLocked) {
        fDiscardableMemory->unlock();
        fDiscardableMemoryIsLocked = false;
    }
<<<<<<< HEAD
    delete fDiscardableMemory;
    SkSafeUnref(fDMFactory);
    delete fGenerator;
}

bool SkDiscardablePixelRef::onNewLockPixels(LockRec* rec)
{
    if (fDiscardableMemory != nullptr) {
=======
    SkDELETE(fDiscardableMemory);
    SkSafeUnref(fDMFactory);
    SkDELETE(fGenerator);
}

bool SkDiscardablePixelRef::onNewLockPixels(LockRec* rec) {
    if (fDiscardableMemory != NULL) {
>>>>>>> miniblink49
        if (fDiscardableMemory->lock()) {
            fDiscardableMemoryIsLocked = true;
            rec->fPixels = fDiscardableMemory->data();
            rec->fColorTable = fCTable.get();
            rec->fRowBytes = fRowBytes;
            return true;
        }
<<<<<<< HEAD
        delete fDiscardableMemory;
        fDiscardableMemory = nullptr;
=======
        SkDELETE(fDiscardableMemory);
        fDiscardableMemory = NULL;
>>>>>>> miniblink49
        fDiscardableMemoryIsLocked = false;
    }

    const size_t size = this->info().getSafeSize(fRowBytes);

<<<<<<< HEAD
    if (fDMFactory != nullptr) {
        fDiscardableMemory = fDMFactory->create(size);
        fDiscardableMemoryIsLocked = true;
    } else {
        fDiscardableMemory = SkDiscardableMemory::Create(size);
        fDiscardableMemoryIsLocked = true;
    }
    if (nullptr == fDiscardableMemory) {
        fDiscardableMemoryIsLocked = false;
        return false; // Memory allocation failed.
=======
    if (fDMFactory != NULL) {
        fDiscardableMemory = fDMFactory->create(size);
        fDiscardableMemoryIsLocked = true;
    } else {
        fDiscardableMemory = SkDiscardableMemory::Create(size);
        fDiscardableMemoryIsLocked = true;
    }
    if (NULL == fDiscardableMemory) {
        fDiscardableMemoryIsLocked = false;
        return false;  // Memory allocation failed.
>>>>>>> miniblink49
    }

    void* pixels = fDiscardableMemory->data();
    const SkImageInfo& info = this->info();
    SkPMColor colors[256];
    int colorCount = 0;

    if (!fGenerator->getPixels(info, pixels, fRowBytes, colors, &colorCount)) {
        fDiscardableMemory->unlock();
        fDiscardableMemoryIsLocked = false;
<<<<<<< HEAD
        delete fDiscardableMemory;
        fDiscardableMemory = nullptr;
=======
        SkDELETE(fDiscardableMemory);
        fDiscardableMemory = NULL;
>>>>>>> miniblink49
        return false;
    }

    // Note: our ctable is not purgeable, as it is not stored in the discardablememory block.
    // This is because SkColorTable is refcntable, and therefore our caller could hold onto it
    // beyond the scope of a lock/unlock. If we change the API/lifecycle for SkColorTable, we
    // could move it into the block, but then again perhaps it is small enough that this doesn't
    // really matter.
    if (colorCount > 0) {
<<<<<<< HEAD
        fCTable.reset(new SkColorTable(colors, colorCount));
    } else {
        fCTable.reset(nullptr);
=======
        fCTable.reset(SkNEW_ARGS(SkColorTable, (colors, colorCount)));
    } else {
        fCTable.reset(NULL);
>>>>>>> miniblink49
    }

    rec->fPixels = pixels;
    rec->fColorTable = fCTable.get();
    rec->fRowBytes = fRowBytes;
    return true;
}

<<<<<<< HEAD
void SkDiscardablePixelRef::onUnlockPixels()
{
=======
void SkDiscardablePixelRef::onUnlockPixels() {
>>>>>>> miniblink49
    fDiscardableMemory->unlock();
    fDiscardableMemoryIsLocked = false;
}

<<<<<<< HEAD
bool SkDEPRECATED_InstallDiscardablePixelRef(SkImageGenerator* generator, const SkIRect* subset,
    SkBitmap* dst, SkDiscardableMemory::Factory* factory)
{
    SkAutoTDelete<SkImageGenerator> autoGenerator(generator);
    if (nullptr == autoGenerator.get()) {
=======
bool SkInstallDiscardablePixelRef(SkImageGenerator* generator, const SkIRect* subset, SkBitmap* dst,
                                  SkDiscardableMemory::Factory* factory) {
    SkAutoTDelete<SkImageGenerator> autoGenerator(generator);
    if (NULL == autoGenerator.get()) {
>>>>>>> miniblink49
        return false;
    }

    SkImageInfo prInfo = autoGenerator->getInfo();
    if (prInfo.isEmpty()) {
        return false;
    }

    SkIPoint origin = SkIPoint::Make(0, 0);
    SkImageInfo bmInfo = prInfo;
    if (subset) {
        const SkIRect prBounds = SkIRect::MakeWH(prInfo.width(), prInfo.height());
        if (subset->isEmpty() || !prBounds.contains(*subset)) {
            return false;
        }
        bmInfo = prInfo.makeWH(subset->width(), subset->height());
        origin.set(subset->x(), subset->y());
    }

    // must compute our desired rowBytes w.r.t. the pixelRef's dimensions, not ours, which may be
    // smaller.
    if (!dst->setInfo(bmInfo, prInfo.minRowBytes())) {
        return false;
    }

    // Since dst->setInfo() may have changed/fixed-up info, we check from the bitmap
    SkASSERT(dst->info().colorType() != kUnknown_SkColorType);

<<<<<<< HEAD
    if (dst->empty()) { // Use a normal pixelref.
        return dst->tryAllocPixels();
    }
    SkAutoTUnref<SkDiscardablePixelRef> ref(
        new SkDiscardablePixelRef(prInfo, autoGenerator.release(), dst->rowBytes(), factory));
=======
    if (dst->empty()) {  // Use a normal pixelref.
        return dst->tryAllocPixels();
    }
    SkAutoTUnref<SkDiscardablePixelRef> ref(
        SkNEW_ARGS(SkDiscardablePixelRef,
                   (prInfo, autoGenerator.detach(), dst->rowBytes(), factory)));
>>>>>>> miniblink49
    dst->setPixelRef(ref, origin.x(), origin.y());
    return true;
}

// These are the public API

<<<<<<< HEAD
bool SkDEPRECATED_InstallDiscardablePixelRef(SkImageGenerator* generator, SkBitmap* dst)
{
    return SkDEPRECATED_InstallDiscardablePixelRef(generator, nullptr, dst, nullptr);
}

bool SkDEPRECATED_InstallDiscardablePixelRef(SkData* encoded, SkBitmap* dst)
{
    SkImageGenerator* generator = SkImageGenerator::NewFromEncoded(encoded);
    return generator ? SkDEPRECATED_InstallDiscardablePixelRef(generator, nullptr, dst, nullptr) : false;
=======
bool SkInstallDiscardablePixelRef(SkImageGenerator* generator, SkBitmap* dst) {
    return SkInstallDiscardablePixelRef(generator, NULL, dst, NULL);
}

bool SkInstallDiscardablePixelRef(SkData* encoded, SkBitmap* dst) {
    SkImageGenerator* generator = SkImageGenerator::NewFromEncoded(encoded);
    return generator ? SkInstallDiscardablePixelRef(generator, NULL, dst, NULL) : false;
>>>>>>> miniblink49
}
