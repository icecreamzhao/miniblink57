/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkImage_Gpu_DEFINED
#define SkImage_Gpu_DEFINED

<<<<<<< HEAD
#include "GrGpuResourcePriv.h"
#include "GrTexture.h"
#include "SkAtomics.h"
#include "SkBitmap.h"
#include "SkGr.h"
#include "SkImagePriv.h"
#include "SkImage_Base.h"
=======
#include "GrTexture.h"
#include "GrGpuResourcePriv.h"
#include "SkBitmap.h"
#include "SkImage_Base.h"
#include "SkImagePriv.h"
>>>>>>> miniblink49
#include "SkSurface.h"

class SkImage_Gpu : public SkImage_Base {
public:
<<<<<<< HEAD
=======
    

>>>>>>> miniblink49
    /**
     *  An "image" can be a subset/window into a larger texture, so we explicit take the
     *  width and height.
     */
<<<<<<< HEAD
    SkImage_Gpu(int w, int h, uint32_t uniqueID, SkAlphaType, GrTexture*, SkBudgeted);
    ~SkImage_Gpu() override;

    SkImageInfo onImageInfo() const override
    {
        return GrMakeInfoFromTexture(fTexture, fTexture->width(), fTexture->height(), isOpaque());
    }

    void applyBudgetDecision() const
    {
        if (SkBudgeted::kYes == fBudgeted) {
            fTexture->resourcePriv().makeBudgeted();
        } else {
            fTexture->resourcePriv().makeUnbudgeted();
        }
    }

    bool getROPixels(SkBitmap*, CachingHint) const override;
    GrTexture* asTextureRef(GrContext* ctx, const GrTextureParams& params,
        SkSourceGammaTreatment) const override;
    sk_sp<SkImage> onMakeSubset(const SkIRect&) const override;

    GrTexture* peekTexture() const override { return fTexture; }
    bool isOpaque() const override;
    bool onReadPixels(const SkImageInfo&, void* dstPixels, size_t dstRowBytes,
        int srcX, int srcY, CachingHint) const override;

    sk_sp<SkSurface> onNewSurface(const SkImageInfo& info) const override
    {
        return SkSurface::MakeRenderTarget(fTexture->getContext(), SkBudgeted::kNo, info);
    }

    bool asBitmapForImageFilters(SkBitmap* bitmap) const override;

private:
    SkAutoTUnref<GrTexture> fTexture;
    const SkAlphaType fAlphaType;
    const SkBudgeted fBudgeted;
    mutable SkAtomic<bool> fAddedRasterVersionToCache;
=======
    SkImage_Gpu(int w, int h, SkAlphaType, GrTexture*, int sampleCountForNewSurfaces,
                SkSurface::Budgeted);

    void applyBudgetDecision() const {
        GrTexture* tex = this->getTexture();
        SkASSERT(tex);
        if (fBudgeted) {
            tex->resourcePriv().makeBudgeted();
        } else {
            tex->resourcePriv().makeUnbudgeted();
        }
    }

    bool getROPixels(SkBitmap*) const override;
    GrTexture* getTexture() const override { return fTexture; }
    SkShader* onNewShader(SkShader::TileMode,
                          SkShader::TileMode,
                          const SkMatrix* localMatrix) const override;
    bool isOpaque() const override;
    SkSurface* onNewSurface(const SkImageInfo&, const SkSurfaceProps&) const override;
    bool onReadPixels(const SkImageInfo&, void* dstPixels, size_t dstRowBytes,
                      int srcX, int srcY) const override;

private:
    SkAutoTUnref<GrTexture> fTexture;
    const int               fSampleCountForNewSurfaces;   // 0 if we don't know
    const SkAlphaType       fAlphaType;
    SkSurface::Budgeted     fBudgeted;
>>>>>>> miniblink49

    typedef SkImage_Base INHERITED;
};

#endif
