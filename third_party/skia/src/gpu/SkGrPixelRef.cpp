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
=======


>>>>>>> miniblink49
#include "SkGrPixelRef.h"

#include "GrContext.h"
#include "GrTexture.h"
#include "GrTexturePriv.h"
#include "SkBitmapCache.h"
#include "SkGr.h"
#include "SkRect.h"

<<<<<<< HEAD
SkROLockPixelsPixelRef::SkROLockPixelsPixelRef(const SkImageInfo& info)
    : INHERITED(info)
{
}

SkROLockPixelsPixelRef::~SkROLockPixelsPixelRef() { }

bool SkROLockPixelsPixelRef::onNewLockPixels(LockRec* rec)
{
    fBitmap.reset();
    //    SkDebugf("---------- calling readpixels in support of lockpixels\n");
    if (!this->onReadPixels(&fBitmap, this->info().colorType(), nullptr)) {
=======
// since we call lockPixels recursively on fBitmap, we need a distinct mutex,
// to avoid deadlock with the default one provided by SkPixelRef.
SK_DECLARE_STATIC_MUTEX(gROLockPixelsPixelRefMutex);

SkROLockPixelsPixelRef::SkROLockPixelsPixelRef(const SkImageInfo& info)
    : INHERITED(info, &gROLockPixelsPixelRefMutex) {}

SkROLockPixelsPixelRef::~SkROLockPixelsPixelRef() {}

bool SkROLockPixelsPixelRef::onNewLockPixels(LockRec* rec) {
    fBitmap.reset();
//    SkDebugf("---------- calling readpixels in support of lockpixels\n");
    if (!this->onReadPixels(&fBitmap, NULL)) {
>>>>>>> miniblink49
        SkDebugf("SkROLockPixelsPixelRef::onLockPixels failed!\n");
        return false;
    }
    fBitmap.lockPixels();
<<<<<<< HEAD
    if (nullptr == fBitmap.getPixels()) {
=======
    if (NULL == fBitmap.getPixels()) {
>>>>>>> miniblink49
        return false;
    }

    rec->fPixels = fBitmap.getPixels();
<<<<<<< HEAD
    rec->fColorTable = nullptr;
=======
    rec->fColorTable = NULL;
>>>>>>> miniblink49
    rec->fRowBytes = fBitmap.rowBytes();
    return true;
}

<<<<<<< HEAD
void SkROLockPixelsPixelRef::onUnlockPixels()
{
    fBitmap.unlockPixels();
}

bool SkROLockPixelsPixelRef::onLockPixelsAreWritable() const
{
=======
void SkROLockPixelsPixelRef::onUnlockPixels() {
    fBitmap.unlockPixels();
}

bool SkROLockPixelsPixelRef::onLockPixelsAreWritable() const {
>>>>>>> miniblink49
    return false;
}

///////////////////////////////////////////////////////////////////////////////

static SkGrPixelRef* copy_to_new_texture_pixelref(GrTexture* texture, SkColorType dstCT,
<<<<<<< HEAD
    SkColorSpace* dstCS, const SkIRect* subset)
{
    if (nullptr == texture || kUnknown_SkColorType == dstCT) {
        return nullptr;
    }
    GrContext* context = texture->getContext();
    if (nullptr == context) {
        return nullptr;
=======
                                                  SkColorProfileType dstPT, const SkIRect* subset) {
    if (NULL == texture || kUnknown_SkColorType == dstCT) {
        return NULL;
    }
    GrContext* context = texture->getContext();
    if (NULL == context) {
        return NULL;
>>>>>>> miniblink49
    }
    GrSurfaceDesc desc;

    SkIRect srcRect;

    if (!subset) {
<<<<<<< HEAD
        desc.fWidth = texture->width();
=======
        desc.fWidth  = texture->width();
>>>>>>> miniblink49
        desc.fHeight = texture->height();
        srcRect = SkIRect::MakeWH(texture->width(), texture->height());
    } else {
        SkASSERT(SkIRect::MakeWH(texture->width(), texture->height()).contains(*subset));
        // Create a new texture that is the size of subset.
        desc.fWidth = subset->width();
        desc.fHeight = subset->height();
        srcRect = *subset;
    }
    desc.fFlags = kRenderTarget_GrSurfaceFlag;
<<<<<<< HEAD
    desc.fConfig = SkImageInfo2GrPixelConfig(dstCT, kPremul_SkAlphaType, dstCS, *context->caps());
    desc.fIsMipMapped = false;

    GrTexture* dst = context->textureProvider()->createTexture(desc, SkBudgeted::kNo, nullptr, 0);
    if (nullptr == dst) {
        return nullptr;
    }

    // Blink is relying on the above copy being sent to GL immediately in the case when the source
    // is a WebGL canvas backing store. We could have a TODO to remove this flush, but we have
    // a larger TODO to remove SkGrPixelRef entirely.
    context->copySurface(dst, texture, srcRect, SkIPoint::Make(0, 0));
    context->flushSurfaceWrites(dst);

    SkImageInfo info = SkImageInfo::Make(desc.fWidth, desc.fHeight, dstCT, kPremul_SkAlphaType,
        sk_ref_sp(dstCS));
    SkGrPixelRef* pixelRef = new SkGrPixelRef(info, dst);
=======
    desc.fConfig = SkImageInfo2GrPixelConfig(dstCT, kPremul_SkAlphaType, dstPT);

    GrTexture* dst = context->textureProvider()->createTexture(desc, false, NULL, 0);
    if (NULL == dst) {
        return NULL;
    }

    // Blink is relying on the above copy being sent to GL immediately in the case when the source
    // is a WebGL canvas backing store. We could have a TODO to remove this flush flag, but we have
    // a larger TODO to remove SkGrPixelRef entirely.
    context->copySurface(dst->asRenderTarget(), texture, srcRect, SkIPoint::Make(0,0),
                         GrContext::kFlushWrites_PixelOp);
  
    SkImageInfo info = SkImageInfo::Make(desc.fWidth, desc.fHeight, dstCT, kPremul_SkAlphaType,
                                         dstPT);
    SkGrPixelRef* pixelRef = SkNEW_ARGS(SkGrPixelRef, (info, dst));
>>>>>>> miniblink49
    SkSafeUnref(dst);
    return pixelRef;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkGrPixelRef::SkGrPixelRef(const SkImageInfo& info, GrSurface* surface)
    : INHERITED(info)
{
=======
SkGrPixelRef::SkGrPixelRef(const SkImageInfo& info, GrSurface* surface) : INHERITED(info) {
>>>>>>> miniblink49
    // For surfaces that are both textures and render targets, the texture owns the
    // render target but not vice versa. So we ref the texture to keep both alive for
    // the lifetime of this pixel ref.
    fSurface = SkSafeRef(surface->asTexture());
<<<<<<< HEAD
    if (nullptr == fSurface) {
=======
    if (NULL == fSurface) {
>>>>>>> miniblink49
        fSurface = SkSafeRef(surface);
    }

    if (fSurface) {
        SkASSERT(info.width() <= fSurface->width());
        SkASSERT(info.height() <= fSurface->height());
    }
}

<<<<<<< HEAD
SkGrPixelRef::~SkGrPixelRef()
{
    SkSafeUnref(fSurface);
}

GrTexture* SkGrPixelRef::getTexture()
{
    if (fSurface) {
        return fSurface->asTexture();
    }
    return nullptr;
}

void SkGrPixelRef::onNotifyPixelsChanged()
{
=======
SkGrPixelRef::~SkGrPixelRef() {
    SkSafeUnref(fSurface);
}

GrTexture* SkGrPixelRef::getTexture() {
    if (fSurface) {
        return fSurface->asTexture();
    }
    return NULL;
}

void SkGrPixelRef::onNotifyPixelsChanged() {
>>>>>>> miniblink49
    GrTexture* texture = this->getTexture();
    if (texture) {
        texture->texturePriv().dirtyMipMaps(true);
    }
}

<<<<<<< HEAD
SkPixelRef* SkGrPixelRef::deepCopy(SkColorType dstCT, SkColorSpace* dstCS, const SkIRect* subset)
{
    if (nullptr == fSurface) {
        return nullptr;
=======
SkPixelRef* SkGrPixelRef::deepCopy(SkColorType dstCT, SkColorProfileType dstPT,
                                   const SkIRect* subset) {
    if (NULL == fSurface) {
        return NULL;
>>>>>>> miniblink49
    }

    // Note that when copying a render-target-backed pixel ref, we
    // return a texture-backed pixel ref instead.  This is because
    // render-target pixel refs are usually created in conjunction with
    // a GrTexture owned elsewhere (e.g., SkGpuDevice), and cannot live
    // independently of that texture.  Texture-backed pixel refs, on the other
    // hand, own their GrTextures, and are thus self-contained.
<<<<<<< HEAD
    return copy_to_new_texture_pixelref(fSurface->asTexture(), dstCT, dstCS, subset);
}

static bool tryAllocBitmapPixels(SkBitmap* bitmap)
{
    SkBitmap::Allocator* allocator = SkBitmapCache::GetAllocator();
    if (nullptr != allocator) {
=======
    return copy_to_new_texture_pixelref(fSurface->asTexture(), dstCT, dstPT, subset);
}

static bool tryAllocBitmapPixels(SkBitmap* bitmap) {
    SkBitmap::Allocator* allocator = SkBitmapCache::GetAllocator();
    if (NULL != allocator) {
>>>>>>> miniblink49
        return allocator->allocPixelRef(bitmap, 0);
    } else {
        // DiscardableMemory is not available, fallback to default allocator
        return bitmap->tryAllocPixels();
    }
}

<<<<<<< HEAD
bool SkGrPixelRef::onReadPixels(SkBitmap* dst, SkColorType colorType, const SkIRect* subset)
{
    if (nullptr == fSurface || fSurface->wasDestroyed()) {
        return false;
    }

    GrPixelConfig config;
    if (kRGBA_8888_SkColorType == colorType) {
        config = kRGBA_8888_GrPixelConfig;
    } else if (kBGRA_8888_SkColorType == colorType) {
        config = kBGRA_8888_GrPixelConfig;
    } else {
=======
bool SkGrPixelRef::onReadPixels(SkBitmap* dst, const SkIRect* subset) {
    if (NULL == fSurface || fSurface->wasDestroyed()) {
>>>>>>> miniblink49
        return false;
    }

    SkIRect bounds;
    if (subset) {
        bounds = *subset;
    } else {
        bounds = SkIRect::MakeWH(this->info().width(), this->info().height());
    }

    //Check the cache
<<<<<<< HEAD
    if (!SkBitmapCache::Find(this->getGenerationID(), bounds, dst)) {
        //Cache miss

        SkBitmap cachedBitmap;
        cachedBitmap.setInfo(SkImageInfo::Make(bounds.width(), bounds.height(), colorType,
            this->info().alphaType(),
            sk_ref_sp(this->info().colorSpace())));
=======
    if(!SkBitmapCache::Find(this->getGenerationID(), bounds, dst)) {
        //Cache miss

        SkBitmap cachedBitmap;
        cachedBitmap.setInfo(this->info().makeWH(bounds.width(), bounds.height()));
>>>>>>> miniblink49

        // If we can't alloc the pixels, then fail
        if (!tryAllocBitmapPixels(&cachedBitmap)) {
            return false;
        }

        // Try to read the pixels from the surface
        void* buffer = cachedBitmap.getPixels();
        bool readPixelsOk = fSurface->readPixels(bounds.fLeft, bounds.fTop,
<<<<<<< HEAD
            bounds.width(), bounds.height(),
            config, buffer, cachedBitmap.rowBytes());
=======
                                bounds.width(), bounds.height(),
                                kSkia8888_GrPixelConfig,
                                buffer, cachedBitmap.rowBytes());
>>>>>>> miniblink49

        if (!readPixelsOk) {
            return false;
        }

        // If we are here, pixels were read correctly from the surface.
        cachedBitmap.setImmutable();
        //Add to the cache
        SkBitmapCache::Add(this, bounds, cachedBitmap);

        dst->swap(cachedBitmap);
    }

    return true;
<<<<<<< HEAD
=======

>>>>>>> miniblink49
}
