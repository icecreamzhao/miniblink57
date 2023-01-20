/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkDiscardablePixelRef_DEFINED
#define SkDiscardablePixelRef_DEFINED

#include "SkDiscardableMemory.h"
#include "SkImageGeneratorPriv.h"
#include "SkImageInfo.h"
#include "SkPixelRef.h"

/**
 *  A PixelRef backed by SkDiscardableMemory, with the ability to
 *  re-generate the pixels (via a SkImageGenerator) if the DM is
 *  purged.
 */
class SkDiscardablePixelRef : public SkPixelRef {
public:
<<<<<<< HEAD
    SkDiscardableMemory* diagnostic_only_getDiscardable() const override
    {
        return fDiscardableMemory;
    }
=======
    
>>>>>>> miniblink49

protected:
    ~SkDiscardablePixelRef();

    bool onNewLockPixels(LockRec*) override;
    void onUnlockPixels() override;
    bool onLockPixelsAreWritable() const override { return false; }

<<<<<<< HEAD
    SkData* onRefEncodedData() override
    {
        return fGenerator->refEncodedData();
    }

    bool onIsLazyGenerated() const override { return true; }

=======
    SkData* onRefEncodedData() override {
        return fGenerator->refEncodedData();
    }

>>>>>>> miniblink49
private:
    SkImageGenerator* const fGenerator;
    SkDiscardableMemory::Factory* const fDMFactory;
    const size_t fRowBytes;
    // These const members should not change over the life of the
    // PixelRef, since the SkBitmap doesn't expect them to change.

    SkDiscardableMemory* fDiscardableMemory;
<<<<<<< HEAD
    bool fDiscardableMemoryIsLocked;
=======
    bool                 fDiscardableMemoryIsLocked;
>>>>>>> miniblink49
    SkAutoTUnref<SkColorTable> fCTable;

    /* Takes ownership of SkImageGenerator. */
    SkDiscardablePixelRef(const SkImageInfo&, SkImageGenerator*,
<<<<<<< HEAD
        size_t rowBytes,
        SkDiscardableMemory::Factory* factory);

    bool onQueryYUV8(SkYUVSizeInfo* sizeInfo, SkYUVColorSpace* colorSpace) const override
    {
=======
                          size_t rowBytes,
                          SkDiscardableMemory::Factory* factory);

    bool onGetYUV8Planes(SkISize sizes[3],
                         void* planes[3],
                         size_t rowBytes[3],
                         SkYUVColorSpace* colorSpace) override {
>>>>>>> miniblink49
        // If the image was already decoded with lockPixels(), favor not
        // re-decoding to YUV8 planes.
        if (fDiscardableMemory) {
            return false;
        }
<<<<<<< HEAD
        return fGenerator->queryYUV8(sizeInfo, colorSpace);
    }

    bool onGetYUV8Planes(const SkYUVSizeInfo& sizeInfo, void* planes[3]) override
    {
        // If the image was already decoded with lockPixels(), favor not
        // re-decoding to YUV8 planes.
        if (fDiscardableMemory) {
            return false;
        }
        return fGenerator->getYUV8Planes(sizeInfo, planes);
    }

    friend bool SkDEPRECATED_InstallDiscardablePixelRef(SkImageGenerator*, const SkIRect*, SkBitmap*,
        SkDiscardableMemory::Factory*);
=======
        return fGenerator->getYUV8Planes(sizes, planes, rowBytes, colorSpace);
    }

    friend bool SkInstallDiscardablePixelRef(SkImageGenerator*, const SkIRect*, SkBitmap*,
                                             SkDiscardableMemory::Factory*);
>>>>>>> miniblink49

    typedef SkPixelRef INHERITED;
};

<<<<<<< HEAD
#endif // SkDiscardablePixelRef_DEFINED
=======
#endif  // SkDiscardablePixelRef_DEFINED
>>>>>>> miniblink49
