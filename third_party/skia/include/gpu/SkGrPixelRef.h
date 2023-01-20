/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkGrPixelRef_DEFINED
#define SkGrPixelRef_DEFINED

<<<<<<< HEAD
#include "GrRenderTarget.h"
#include "GrTexture.h"
#include "SkBitmap.h"
#include "SkPixelRef.h"
=======
#include "SkBitmap.h"
#include "SkPixelRef.h"
#include "GrTexture.h"
#include "GrRenderTarget.h"

>>>>>>> miniblink49

/**
 *  Common baseclass that implements onLockPixels() by calling onReadPixels().
 *  Since it has a copy, it always returns false for onLockPixelsAreWritable().
 */
class SK_API SkROLockPixelsPixelRef : public SkPixelRef {
public:
    SkROLockPixelsPixelRef(const SkImageInfo&);
    virtual ~SkROLockPixelsPixelRef();

protected:
    bool onNewLockPixels(LockRec*) override;
    void onUnlockPixels() override;
<<<<<<< HEAD
    bool onLockPixelsAreWritable() const override; // return false;

private:
    SkBitmap fBitmap;
=======
    bool onLockPixelsAreWritable() const override;   // return false;

private:
    SkBitmap    fBitmap;
>>>>>>> miniblink49
    typedef SkPixelRef INHERITED;
};

/**
 *  PixelRef that wraps a GrSurface
 */
class SK_API SkGrPixelRef : public SkROLockPixelsPixelRef {
public:
    /**
     * Constructs a pixel ref around a GrSurface.
     */
    SkGrPixelRef(const SkImageInfo&, GrSurface*);
    virtual ~SkGrPixelRef();

    // override from SkPixelRef
    GrTexture* getTexture() override;

protected:
    // overrides from SkPixelRef
<<<<<<< HEAD
    bool onReadPixels(SkBitmap* dst, SkColorType, const SkIRect* subset) override;
    SkPixelRef* deepCopy(SkColorType, SkColorSpace*, const SkIRect* subset) override;
    void onNotifyPixelsChanged() override;

private:
    GrSurface* fSurface;
=======
    bool onReadPixels(SkBitmap* dst, const SkIRect* subset) override;
    SkPixelRef* deepCopy(SkColorType, SkColorProfileType,
                         const SkIRect* subset) override;
    void onNotifyPixelsChanged() override;

private:
    GrSurface*  fSurface;
>>>>>>> miniblink49
    typedef SkROLockPixelsPixelRef INHERITED;
};

#endif
