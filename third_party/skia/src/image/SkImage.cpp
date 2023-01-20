/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkBitmap.h"
<<<<<<< HEAD
#include "SkBitmapCache.h"
#include "SkCanvas.h"
#include "SkData.h"
#include "SkImageEncoder.h"
#include "SkImageFilter.h"
#include "SkImageGenerator.h"
#include "SkImagePriv.h"
#include "SkImageShader.h"
#include "SkImage_Base.h"
#include "SkNextID.h"
#include "SkPicture.h"
#include "SkPixelRef.h"
#include "SkPixelSerializer.h"
#include "SkReadPixelsRec.h"
#include "SkSpecialImage.h"
=======
#include "SkCanvas.h"
#include "SkData.h"
#include "SkImageGenerator.h"
#include "SkImagePriv.h"
#include "SkImage_Base.h"
#include "SkPixelRef.h"
#include "SkReadPixelsRec.h"
>>>>>>> miniblink49
#include "SkString.h"
#include "SkSurface.h"

#if SK_SUPPORT_GPU
<<<<<<< HEAD
#include "GrContext.h"
#include "GrTexture.h"
#include "SkImage_Gpu.h"
#endif

SkImage::SkImage(int width, int height, uint32_t uniqueID)
    : fWidth(width)
    , fHeight(height)
    , fUniqueID(kNeedNewImageUniqueID == uniqueID ? SkNextID::ImageID() : uniqueID)
{
    SkASSERT(width > 0);
    SkASSERT(height > 0);
}

bool SkImage::peekPixels(SkPixmap* pm) const
{
    SkPixmap tmp;
    if (!pm) {
        pm = &tmp;
    }
    return as_IB(this)->onPeekPixels(pm);
}

#ifdef SK_SUPPORT_LEGACY_PEEKPIXELS_PARMS
const void* SkImage::peekPixels(SkImageInfo* info, size_t* rowBytes) const
{
    SkPixmap pm;
    if (this->peekPixels(&pm)) {
        if (info) {
            *info = pm.info();
        }
        if (rowBytes) {
            *rowBytes = pm.rowBytes();
        }
        return pm.addr();
    }
    return nullptr;
}
#endif

bool SkImage::readPixels(const SkImageInfo& dstInfo, void* dstPixels, size_t dstRowBytes,
    int srcX, int srcY, CachingHint chint) const
{
=======
#include "GrTexture.h"
#include "GrContext.h"
#include "SkImage_Gpu.h"
#endif

uint32_t SkImage::NextUniqueID() {
    static int32_t gUniqueID;

    // never return 0;
    uint32_t id;
    do {
        id = sk_atomic_inc(&gUniqueID) + 1;
    } while (0 == id);
    return id;
}

const void* SkImage::peekPixels(SkImageInfo* info, size_t* rowBytes) const {
    SkImageInfo infoStorage;
    size_t rowBytesStorage;
    if (NULL == info) {
        info = &infoStorage;
    }
    if (NULL == rowBytes) {
        rowBytes = &rowBytesStorage;
    }
    return as_IB(this)->onPeekPixels(info, rowBytes);
}

bool SkImage::readPixels(const SkImageInfo& dstInfo, void* dstPixels, size_t dstRowBytes,
                           int srcX, int srcY) const {
>>>>>>> miniblink49
    SkReadPixelsRec rec(dstInfo, dstPixels, dstRowBytes, srcX, srcY);
    if (!rec.trim(this->width(), this->height())) {
        return false;
    }
<<<<<<< HEAD
    return as_IB(this)->onReadPixels(rec.fInfo, rec.fPixels, rec.fRowBytes, rec.fX, rec.fY, chint);
}

bool SkImage::scalePixels(const SkPixmap& dst, SkFilterQuality quality, CachingHint chint) const
{
    if (this->width() == dst.width() && this->height() == dst.height()) {
        return this->readPixels(dst, 0, 0, chint);
    }

    // Idea: If/when SkImageGenerator supports a native-scaling API (where the generator itself
    //       can scale more efficiently) we should take advantage of it here.
    //
    SkBitmap bm;
    if (as_IB(this)->getROPixels(&bm, chint)) {
        bm.lockPixels();
        SkPixmap pmap;
        // Note: By calling the pixmap scaler, we never cache the final result, so the chint
        //       is (currently) only being applied to the getROPixels. If we get a request to
        //       also attempt to cache the final (scaled) result, we would add that logic here.
        //
        return bm.peekPixels(&pmap) && pmap.scalePixels(dst, quality);
    }
    return false;
}

void SkImage::preroll(GrContext* ctx) const
{
    // For now, and to maintain parity w/ previous pixelref behavior, we just force the image
    // to produce a cached raster-bitmap form, so that drawing to a raster canvas should be fast.
    //
    SkBitmap bm;
    if (as_IB(this)->getROPixels(&bm)) {
        bm.lockPixels();
        bm.unlockPixels();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

sk_sp<SkShader> SkImage::makeShader(SkShader::TileMode tileX, SkShader::TileMode tileY,
    const SkMatrix* localMatrix) const
{
    return SkImageShader::Make(this, tileX, tileY, localMatrix);
}

#ifdef SK_SUPPORT_LEGACY_CREATESHADER_PTR
SkShader* SkImage::newShader(SkShader::TileMode tileX, SkShader::TileMode tileY,
    const SkMatrix* localMatrix) const
{
    return this->makeShader(tileX, tileY, localMatrix).release();
}
#endif

SkData* SkImage::encode(SkImageEncoder::Type type, int quality) const
{
=======
    return as_IB(this)->onReadPixels(rec.fInfo, rec.fPixels, rec.fRowBytes, rec.fX, rec.fY);
}

SkShader* SkImage::newShader(SkShader::TileMode tileX,
                             SkShader::TileMode tileY,
                             const SkMatrix* localMatrix) const {
    return as_IB(this)->onNewShader(tileX, tileY, localMatrix);
}

SkData* SkImage::encode(SkImageEncoder::Type type, int quality) const {
>>>>>>> miniblink49
    SkBitmap bm;
    if (as_IB(this)->getROPixels(&bm)) {
        return SkImageEncoder::EncodeData(bm, type, quality);
    }
<<<<<<< HEAD
    return nullptr;
}

SkData* SkImage::encode(SkPixelSerializer* serializer) const
{
    SkAutoTUnref<SkPixelSerializer> defaultSerializer;
    SkPixelSerializer* effectiveSerializer = serializer;
    if (!effectiveSerializer) {
        defaultSerializer.reset(SkImageEncoder::CreatePixelSerializer());
        SkASSERT(defaultSerializer.get());
        effectiveSerializer = defaultSerializer.get();
    }
    SkAutoTUnref<SkData> encoded(this->refEncoded());
    if (encoded && effectiveSerializer->useEncodedData(encoded->data(), encoded->size())) {
        return encoded.release();
    }

    SkBitmap bm;
    SkAutoPixmapUnlock apu;
    if (as_IB(this)->getROPixels(&bm) && bm.requestLock(&apu)) {
        return effectiveSerializer->encode(apu.pixmap());
    }

    return nullptr;
}

SkData* SkImage::refEncoded() const
{
    GrContext* ctx = nullptr; // should we allow the caller to pass in a ctx?
    return as_IB(this)->onRefEncoded(ctx);
}

sk_sp<SkImage> SkImage::MakeFromEncoded(sk_sp<SkData> encoded, const SkIRect* subset)
{
    if (nullptr == encoded || 0 == encoded->size()) {
        return nullptr;
    }
    SkImageGenerator* generator = SkImageGenerator::NewFromEncoded(encoded.get());
    return SkImage::MakeFromGenerator(generator, subset);
}

const char* SkImage::toString(SkString* str) const
{
    str->appendf("image: (id:%d (%d, %d) %s)", this->uniqueID(), this->width(), this->height(),
        this->isOpaque() ? "opaque" : "");
    return str->c_str();
}

sk_sp<SkImage> SkImage::makeSubset(const SkIRect& subset) const
{
    if (subset.isEmpty()) {
        return nullptr;
    }

    const SkIRect bounds = SkIRect::MakeWH(this->width(), this->height());
    if (!bounds.contains(subset)) {
        return nullptr;
    }

    // optimization : return self if the subset == our bounds
    if (bounds == subset) {
        return sk_ref_sp(const_cast<SkImage*>(this));
    }
    return as_IB(this)->onMakeSubset(subset);
=======
    return NULL;
}

SkData* SkImage::refEncoded() const {
    return as_IB(this)->onRefEncoded();
}

SkImage* SkImage::NewFromEncoded(SkData* encoded, const SkIRect* subset) {
    if (NULL == encoded || 0 == encoded->size()) {
        return NULL;
    }
    SkImageGenerator* generator = SkImageGenerator::NewFromEncoded(encoded);
    return generator ? SkImage::NewFromGenerator(generator, subset) : NULL;
}

SkSurface* SkImage::newSurface(const SkImageInfo& info, const SkSurfaceProps* props) const {
    if (NULL == props) {
        props = &as_IB(this)->props();
    }
    return as_IB(this)->onNewSurface(info, *props);
}

const char* SkImage::toString(SkString* str) const {
    str->appendf("image: (id:%d (%d, %d) %s)", this->uniqueID(), this->width(), this->height(),
                 this->isOpaque() ? "opaque" : "");
    return str->c_str();
}

SkImage* SkImage::newImage(int newWidth, int newHeight, const SkIRect* subset,
                           SkFilterQuality quality) const {
    if (newWidth <= 0 || newHeight <= 0) {
        return NULL;
    }

    const SkIRect bounds = SkIRect::MakeWH(this->width(), this->height());

    if (subset) {
        if (!bounds.contains(*subset)) {
            return NULL;
        }
        if (bounds == *subset) {
            subset = NULL;  // and fall through to check below
        }
    }

    if (NULL == subset && this->width() == newWidth && this->height() == newHeight) {
        return SkRef(const_cast<SkImage*>(this));
    }

    return as_IB(this)->onNewImage(newWidth, newHeight, subset, quality);
>>>>>>> miniblink49
}

#if SK_SUPPORT_GPU

<<<<<<< HEAD
GrTexture* SkImage::getTexture() const
{
    return as_IB(this)->peekTexture();
}

bool SkImage::isTextureBacked() const { return SkToBool(as_IB(this)->peekTexture()); }

GrBackendObject SkImage::getTextureHandle(bool flushPendingGrContextIO) const
{
    GrTexture* texture = as_IB(this)->peekTexture();
    if (texture) {
        GrContext* context = texture->getContext();
        if (context) {
=======
GrTexture* SkImage::getTexture() const {
    return as_IB(this)->getTexture();
}

bool SkImage::isTextureBacked() const { return SkToBool(as_IB(this)->getTexture()); }

GrBackendObject SkImage::getTextureHandle(bool flushPendingGrContextIO) const {
    GrTexture* texture = as_IB(this)->getTexture();
    if (texture) {
        GrContext* context = texture->getContext();
        if (context) {            
>>>>>>> miniblink49
            if (flushPendingGrContextIO) {
                context->prepareSurfaceForExternalIO(texture);
            }
        }
        return texture->getTextureHandle();
    }
    return 0;
}

#else

<<<<<<< HEAD
GrTexture* SkImage::getTexture() const
{
    return nullptr;
}
=======
GrTexture* SkImage::getTexture() const { return NULL; }
>>>>>>> miniblink49

bool SkImage::isTextureBacked() const { return false; }

GrBackendObject SkImage::getTextureHandle(bool) const { return 0; }

#endif

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static bool raster_canvas_supports(const SkImageInfo& info)
{
    switch (info.colorType()) {
    case kN32_SkColorType:
        return kUnpremul_SkAlphaType != info.alphaType();
    case kRGB_565_SkColorType:
        return true;
    case kAlpha_8_SkColorType:
        return true;
    default:
        break;
=======
static bool raster_canvas_supports(const SkImageInfo& info) {
    switch (info.colorType()) {
        case kN32_SkColorType:
            return kUnpremul_SkAlphaType != info.alphaType();
        case kRGB_565_SkColorType:
            return true;
        case kAlpha_8_SkColorType:
            return true;
        default:
            break;
>>>>>>> miniblink49
    }
    return false;
}

<<<<<<< HEAD
SkImage_Base::SkImage_Base(int width, int height, uint32_t uniqueID)
    : INHERITED(width, height, uniqueID)
    , fAddedToCache(false)
{
}

SkImage_Base::~SkImage_Base()
{
    if (fAddedToCache.load()) {
        SkNotifyBitmapGenIDIsStale(this->uniqueID());
    }
}

bool SkImage_Base::onReadPixels(const SkImageInfo& dstInfo, void* dstPixels, size_t dstRowBytes,
    int srcX, int srcY, CachingHint) const
{
=======
bool SkImage_Base::onReadPixels(const SkImageInfo& dstInfo, void* dstPixels, size_t dstRowBytes,
                                int srcX, int srcY) const {
>>>>>>> miniblink49
    if (!raster_canvas_supports(dstInfo)) {
        return false;
    }

    SkBitmap bm;
    bm.installPixels(dstInfo, dstPixels, dstRowBytes);
    SkCanvas canvas(bm);

    SkPaint paint;
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    canvas.drawImage(this, -SkIntToScalar(srcX), -SkIntToScalar(srcY), &paint);

    return true;
}

<<<<<<< HEAD
///////////////////////////////////////////////////////////////////////////////////////////////////

bool SkImage::readPixels(const SkPixmap& pmap, int srcX, int srcY, CachingHint chint) const
{
    return this->readPixels(pmap.info(), pmap.writable_addr(), pmap.rowBytes(), srcX, srcY, chint);
}

#if SK_SUPPORT_GPU
#include "GrTextureToYUVPlanes.h"
#endif

#include "SkRGBAToYUV.h"

bool SkImage::readYUV8Planes(const SkISize sizes[3], void* const planes[3],
    const size_t rowBytes[3], SkYUVColorSpace colorSpace) const
{
#if SK_SUPPORT_GPU
    if (GrTexture* texture = as_IB(this)->peekTexture()) {
        if (GrTextureToYUVPlanes(texture, sizes, planes, rowBytes, colorSpace)) {
            return true;
        }
    }
#endif
    return SkRGBAToYUV(this, sizes, planes, rowBytes, colorSpace);
=======
SkImage* SkImage_Base::onNewImage(int newWidth, int newHeight, const SkIRect* subset,
                                  SkFilterQuality quality) const {
    const bool opaque = this->isOpaque();
    const SkImageInfo info = SkImageInfo::Make(newWidth, newHeight, kN32_SkColorType,
                                               opaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType);
    SkAutoTUnref<SkSurface> surface(this->newSurface(info, NULL));
    if (!surface.get()) {
        return NULL;
    }

    SkRect src;
    if (subset) {
        src.set(*subset);
    } else {
        src = SkRect::MakeIWH(this->width(), this->height());
    }

    surface->getCanvas()->scale(newWidth / src.width(), newHeight / src.height());
    surface->getCanvas()->translate(-src.x(), -src.y());

    SkPaint paint;
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    paint.setFilterQuality(quality);
    surface->getCanvas()->drawImage(this, 0, 0, &paint);
    return surface->newImageSnapshot();
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<SkImage> SkImage::MakeFromBitmap(const SkBitmap& bm)
{
    SkPixelRef* pr = bm.pixelRef();
    if (nullptr == pr) {
        return nullptr;
=======
bool SkImage::peekPixels(SkPixmap* pmap) const {
    SkImageInfo info;
    size_t rowBytes;
    const void* pixels = this->peekPixels(&info, &rowBytes);
    if (pixels) {
        if (pmap) {
            pmap->reset(info, pixels, rowBytes);
        }
        return true;
    }
    return false;
}

bool SkImage::readPixels(const SkPixmap& pmap, int srcX, int srcY) const {
    return this->readPixels(pmap.info(), pmap.writable_addr(), pmap.rowBytes(), srcX, srcY);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

SkImage* SkImage::NewFromBitmap(const SkBitmap& bm) {
    SkPixelRef* pr = bm.pixelRef();
    if (NULL == pr) {
        return NULL;
>>>>>>> miniblink49
    }

#if SK_SUPPORT_GPU
    if (GrTexture* tex = pr->getTexture()) {
        SkAutoTUnref<GrTexture> unrefCopy;
        if (!bm.isImmutable()) {
<<<<<<< HEAD
            tex = GrDeepCopyTexture(tex, SkBudgeted::kNo);
            if (nullptr == tex) {
                return nullptr;
=======
            const bool notBudgeted = false;
            tex = GrDeepCopyTexture(tex, notBudgeted);
            if (NULL == tex) {
                return NULL;
>>>>>>> miniblink49
            }
            unrefCopy.reset(tex);
        }
        const SkImageInfo info = bm.info();
<<<<<<< HEAD
        return sk_make_sp<SkImage_Gpu>(info.width(), info.height(), bm.getGenerationID(),
            info.alphaType(), tex, SkBudgeted::kNo);
=======
        return SkNEW_ARGS(SkImage_Gpu, (info.width(), info.height(), info.alphaType(),
                                        tex, 0, SkSurface::kNo_Budgeted));
>>>>>>> miniblink49
    }
#endif

    // This will check for immutable (share or copy)
<<<<<<< HEAD
    return SkMakeImageFromRasterBitmap(bm);
}

bool SkImage::asLegacyBitmap(SkBitmap* bitmap, LegacyBitmapMode mode) const
{
    return as_IB(this)->onAsLegacyBitmap(bitmap, mode);
}

bool SkImage_Base::onAsLegacyBitmap(SkBitmap* bitmap, LegacyBitmapMode mode) const
{
    // As the base-class, all we can do is make a copy (regardless of mode).
    // Subclasses that want to be more optimal should override.
    SkImageInfo info = this->onImageInfo().makeColorType(kN32_SkColorType).makeAlphaType(this->isOpaque() ? kOpaque_SkAlphaType : kPremul_SkAlphaType);
=======
    return SkNewImageFromRasterBitmap(bm, false, NULL);
}

bool SkImage::asLegacyBitmap(SkBitmap* bitmap, LegacyBitmapMode mode) const {
    return as_IB(this)->onAsLegacyBitmap(bitmap, mode);
}

bool SkImage_Base::onAsLegacyBitmap(SkBitmap* bitmap, LegacyBitmapMode mode) const {
    // As the base-class, all we can do is make a copy (regardless of mode).
    // Subclasses that want to be more optimal should override.
    SkImageInfo info = SkImageInfo::MakeN32(this->width(), this->height(),
                                    this->isOpaque() ? kOpaque_SkAlphaType : kPremul_SkAlphaType);
>>>>>>> miniblink49
    if (!bitmap->tryAllocPixels(info)) {
        return false;
    }
    if (!this->readPixels(bitmap->info(), bitmap->getPixels(), bitmap->rowBytes(), 0, 0)) {
        bitmap->reset();
        return false;
    }

    if (kRO_LegacyBitmapMode == mode) {
        bitmap->setImmutable();
    }
    return true;
}

<<<<<<< HEAD
sk_sp<SkImage> SkImage::MakeFromPicture(sk_sp<SkPicture> picture, const SkISize& dimensions,
    const SkMatrix* matrix, const SkPaint* paint)
{
    if (!picture) {
        return nullptr;
    }
    return MakeFromGenerator(SkImageGenerator::NewFromPicture(dimensions, picture.get(),
        matrix, paint));
}

sk_sp<SkImage> SkImage::makeWithFilter(const SkImageFilter* filter, const SkIRect& subset,
    const SkIRect& clipBounds, SkIRect* outSubset,
    SkIPoint* offset) const
{
    if (!filter || !outSubset || !offset || !this->bounds().contains(subset)) {
        return nullptr;
    }
    sk_sp<SkSpecialImage> srcSpecialImage = SkSpecialImage::MakeFromImage(
        subset, sk_ref_sp(const_cast<SkImage*>(this)));
    if (!srcSpecialImage) {
        return nullptr;
    }

    // FIXME: build a cache here.
    SkImageFilter::Context context(SkMatrix::I(), clipBounds, nullptr);
    sk_sp<SkSpecialImage> result = filter->filterImage(srcSpecialImage.get(), context, offset);

    if (!result) {
        return nullptr;
    }

    SkIRect fullSize = SkIRect::MakeWH(result->width(), result->height());
#if SK_SUPPORT_GPU
    if (result->isTextureBacked()) {
        GrContext* context = result->getContext();
        sk_sp<GrTexture> texture = result->asTextureRef(context);
        fullSize = SkIRect::MakeWH(texture->width(), texture->height());
    }
#endif
    *outSubset = SkIRect::MakeWH(result->width(), result->height());
    if (!outSubset->intersect(clipBounds.makeOffset(-offset->x(), -offset->y()))) {
        return nullptr;
    }
    offset->fX += outSubset->x();
    offset->fY += outSubset->y();
    // This isn't really a "tight" subset, but includes any texture padding.
    return result->makeTightSubset(fullSize);
}

bool SkImage::isLazyGenerated() const
{
    return as_IB(this)->onIsLazyGenerated();
}

=======
>>>>>>> miniblink49
//////////////////////////////////////////////////////////////////////////////////////

#if !SK_SUPPORT_GPU

<<<<<<< HEAD
sk_sp<SkImage> SkImage::MakeTextureFromPixmap(GrContext*, const SkPixmap&, SkBudgeted budgeted)
{
    return nullptr;
}

sk_sp<SkImage> SkImage::MakeFromTexture(GrContext*, const GrBackendTextureDesc&, SkAlphaType,
    TextureReleaseProc, ReleaseContext)
{
    return nullptr;
}

size_t SkImage::getDeferredTextureImageData(const GrContextThreadSafeProxy&,
    const DeferredTextureImageUsageParams[],
    int paramCnt, void* buffer) const
{
    return 0;
}

sk_sp<SkImage> SkImage::MakeFromDeferredTextureImageData(GrContext* context, const void*,
    SkBudgeted)
{
    return nullptr;
}

sk_sp<SkImage> SkImage::MakeFromAdoptedTexture(GrContext*, const GrBackendTextureDesc&,
    SkAlphaType)
{
    return nullptr;
}

sk_sp<SkImage> SkImage::MakeFromTextureCopy(GrContext*, const GrBackendTextureDesc&, SkAlphaType)
{
    return nullptr;
}

sk_sp<SkImage> SkImage::MakeFromYUVTexturesCopy(GrContext* ctx, SkYUVColorSpace space,
    const GrBackendObject yuvTextureHandles[3],
    const SkISize yuvSizes[3],
    GrSurfaceOrigin origin)
{
    return nullptr;
}

sk_sp<SkImage> SkImage::makeTextureImage(GrContext*) const
{
    return nullptr;
}

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef SK_SUPPORT_LEGACY_IMAGEFACTORY
SkImage* SkImage::NewRasterCopy(const Info& info, const void* pixels, size_t rowBytes,
    SkColorTable* ctable)
{
    return MakeRasterCopy(SkPixmap(info, pixels, rowBytes, ctable)).release();
}

SkImage* SkImage::NewRasterData(const Info& info, SkData* pixels, size_t rowBytes)
{
    return MakeRasterData(info, sk_ref_sp(pixels), rowBytes).release();
}

SkImage* SkImage::NewFromRaster(const Info& info, const void* pixels, size_t rowBytes,
    RasterReleaseProc proc, ReleaseContext releasectx)
{
    return MakeFromRaster(SkPixmap(info, pixels, rowBytes), proc, releasectx).release();
}

SkImage* SkImage::NewFromBitmap(const SkBitmap& bm)
{
    return MakeFromBitmap(bm).release();
}

SkImage* SkImage::NewFromGenerator(SkImageGenerator* gen, const SkIRect* subset)
{
    return MakeFromGenerator(gen, subset).release();
}

SkImage* SkImage::NewFromEncoded(SkData* encoded, const SkIRect* subset)
{
    return MakeFromEncoded(sk_ref_sp(encoded), subset).release();
}

SkImage* SkImage::NewFromTexture(GrContext* ctx, const GrBackendTextureDesc& desc, SkAlphaType at,
    TextureReleaseProc proc, ReleaseContext releasectx)
{
    return MakeFromTexture(ctx, desc, at, proc, releasectx).release();
}

SkImage* SkImage::NewFromAdoptedTexture(GrContext* ctx, const GrBackendTextureDesc& desc,
    SkAlphaType at)
{
    return MakeFromAdoptedTexture(ctx, desc, at).release();
}

SkImage* SkImage::NewFromTextureCopy(GrContext* ctx, const GrBackendTextureDesc& desc,
    SkAlphaType at)
{
    return MakeFromTextureCopy(ctx, desc, at).release();
}

SkImage* SkImage::NewFromYUVTexturesCopy(GrContext* ctx, SkYUVColorSpace space,
    const GrBackendObject yuvTextureHandles[3],
    const SkISize yuvSizes[3],
    GrSurfaceOrigin origin)
{
    return MakeFromYUVTexturesCopy(ctx, space, yuvTextureHandles, yuvSizes, origin).release();
}

SkImage* SkImage::NewFromPicture(const SkPicture* picture, const SkISize& dimensions,
    const SkMatrix* matrix, const SkPaint* paint)
{
    return MakeFromPicture(sk_ref_sp(const_cast<SkPicture*>(picture)), dimensions,
        matrix, paint)
        .release();
}

SkImage* SkImage::NewTextureFromPixmap(GrContext* ctx, const SkPixmap& pmap, SkBudgeted budgeted)
{
    return MakeTextureFromPixmap(ctx, pmap, budgeted).release();
}

SkImage* SkImage::NewFromDeferredTextureImageData(GrContext* ctx, const void* data,
    SkBudgeted budgeted)
{
    return MakeFromDeferredTextureImageData(ctx, data, budgeted).release();
}
#endif

sk_sp<SkImage> MakeTextureFromMipMap(GrContext*, const SkImageInfo&, const GrMipLevel* texels,
    int mipLevelCount, SkBudgeted)
{
    return nullptr;
}
=======
SkImage* SkImage::NewFromTexture(GrContext*, const GrBackendTextureDesc&, SkAlphaType,
                                 TextureReleaseProc, ReleaseContext) {
    return NULL;
}

SkImage* SkImage::NewFromAdoptedTexture(GrContext*, const GrBackendTextureDesc&, SkAlphaType) {
    return NULL;
}

SkImage* SkImage::NewFromTextureCopy(GrContext*, const GrBackendTextureDesc&, SkAlphaType) {
    return NULL;
}

#endif
>>>>>>> miniblink49
