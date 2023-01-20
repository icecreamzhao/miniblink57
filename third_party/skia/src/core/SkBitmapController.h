/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkBitmapController_DEFINED
#define SkBitmapController_DEFINED

#include "SkBitmap.h"
<<<<<<< HEAD
#include "SkBitmapCache.h"
#include "SkFilterQuality.h"
#include "SkMatrix.h"

class SkBitmapProvider;

=======
#include "SkFilterQuality.h"
#include "SkMatrix.h"

>>>>>>> miniblink49
/**
 *  Handles request to scale, filter, and lock a bitmap to be rasterized.
 */
class SkBitmapController : ::SkNoncopyable {
public:
    class State : ::SkNoncopyable {
    public:
<<<<<<< HEAD
        virtual ~State() { }
=======
        virtual ~State() {}
>>>>>>> miniblink49

        const SkPixmap& pixmap() const { return fPixmap; }
        const SkMatrix& invMatrix() const { return fInvMatrix; }
        SkFilterQuality quality() const { return fQuality; }
<<<<<<< HEAD

    protected:
        SkPixmap fPixmap;
        SkMatrix fInvMatrix;
        SkFilterQuality fQuality;

=======
    
    protected:
        SkPixmap        fPixmap;
        SkMatrix        fInvMatrix;
        SkFilterQuality fQuality;
    
>>>>>>> miniblink49
    private:
        friend class SkBitmapController;
    };

<<<<<<< HEAD
    virtual ~SkBitmapController() { }

    State* requestBitmap(const SkBitmapProvider&, const SkMatrix& inverse, SkFilterQuality,
        void* storage, size_t storageSize);

    State* requestBitmap(const SkBitmapProvider& bp, const SkMatrix& inv, SkFilterQuality quality)
    {
        return this->requestBitmap(bp, inv, quality, nullptr, 0);
    }

protected:
    virtual State* onRequestBitmap(const SkBitmapProvider&, const SkMatrix& inv, SkFilterQuality,
        void* storage, size_t storageSize)
        = 0;
=======
    virtual ~SkBitmapController() {}

    State* requestBitmap(const SkBitmap&, const SkMatrix& inverse, SkFilterQuality,
                         void* storage, size_t storageSize);

    State* requestBitmap(const SkBitmap& bm, const SkMatrix& inverse, SkFilterQuality quality) {
        return this->requestBitmap(bm, inverse, quality, NULL, 0);
    }

protected:
    virtual State* onRequestBitmap(const SkBitmap&, const SkMatrix& inverse, SkFilterQuality,
                                   void* storage, size_t storageSize) = 0;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#include "SkMipMap.h"

class SkDefaultBitmapController : public SkBitmapController {
public:
    SkDefaultBitmapController(SkSourceGammaTreatment treatment)
        : fSrcGammaTreatment(treatment)
    {
    }

protected:
    State* onRequestBitmap(const SkBitmapProvider&, const SkMatrix& inverse, SkFilterQuality,
        void* storage, size_t storageSize) override;

private:
    const SkSourceGammaTreatment fSrcGammaTreatment;
=======
class SkDefaultBitmapController : public SkBitmapController {
public:
    SkDefaultBitmapController() {}
    
protected:
    State* onRequestBitmap(const SkBitmap&, const SkMatrix& inverse, SkFilterQuality,
                           void* storage, size_t storageSize) override;
>>>>>>> miniblink49
};

#endif
