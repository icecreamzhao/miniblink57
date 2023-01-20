/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkGr.h"
<<<<<<< HEAD
#include "SkGrPriv.h"

#include "GrCaps.h"
#include "GrContext.h"
#include "GrGpuResourcePriv.h"
#include "GrImageIDTextureAdjuster.h"
#include "GrTextureParamsAdjuster.h"
#include "GrTexturePriv.h"
#include "GrTypes.h"
#include "GrXferProcessor.h"
#include "GrYUVProvider.h"

#include "SkCanvas.h"
=======

#include "GrCaps.h"
#include "GrDrawContext.h"
#include "GrXferProcessor.h"
>>>>>>> miniblink49
#include "SkColorFilter.h"
#include "SkConfig8888.h"
#include "SkData.h"
#include "SkErrorInternals.h"
#include "SkGrPixelRef.h"
#include "SkMessageBus.h"
<<<<<<< HEAD
#include "SkMipMap.h"
#include "SkPM4fPriv.h"
#include "SkPixelRef.h"
#include "SkResourceCache.h"
#include "SkTemplates.h"
#include "SkYUVPlanesCache.h"
#include "effects/GrBicubicEffect.h"
#include "effects/GrConstColorProcessor.h"
#include "effects/GrDitherEffect.h"
#include "effects/GrPorterDuffXferProcessor.h"
#include "effects/GrXfermodeFragmentProcessor.h"
#include "effects/GrYUVEffect.h"

#ifndef SK_IGNORE_ETC1_SUPPORT
#include "etc1.h"
#include "ktx.h"
#endif

GrSurfaceDesc GrImageInfoToSurfaceDesc(const SkImageInfo& info, const GrCaps& caps)
{
    GrSurfaceDesc desc;
    desc.fFlags = kNone_GrSurfaceFlags;
    desc.fWidth = info.width();
    desc.fHeight = info.height();
    desc.fConfig = SkImageInfo2GrPixelConfig(info, caps);
    desc.fSampleCnt = 0;
    return desc;
}

void GrMakeKeyFromImageID(GrUniqueKey* key, uint32_t imageID, const SkIRect& imageBounds)
{
    SkASSERT(key);
    SkASSERT(imageID);
    SkASSERT(!imageBounds.isEmpty());
    static const GrUniqueKey::Domain kImageIDDomain = GrUniqueKey::GenerateDomain();
    GrUniqueKey::Builder builder(key, kImageIDDomain, 5);
    builder[0] = imageID;
    builder[1] = imageBounds.fLeft;
    builder[2] = imageBounds.fTop;
    builder[3] = imageBounds.fRight;
    builder[4] = imageBounds.fBottom;
}

GrPixelConfig GrIsCompressedTextureDataSupported(GrContext* ctx, SkData* data,
    int expectedW, int expectedH,
    const void** outStartOfDataToUpload)
{
    *outStartOfDataToUpload = nullptr;
#ifndef SK_IGNORE_ETC1_SUPPORT
    if (!ctx->caps()->isConfigTexturable(kETC1_GrPixelConfig)) {
        return kUnknown_GrPixelConfig;
    }

    const uint8_t* bytes = data->bytes();
    if (data->size() > ETC_PKM_HEADER_SIZE && etc1_pkm_is_valid(bytes)) {
        // Does the data match the dimensions of the bitmap? If not,
        // then we don't know how to scale the image to match it...
        if (etc1_pkm_get_width(bytes) != (unsigned)expectedW || etc1_pkm_get_height(bytes) != (unsigned)expectedH) {
            return kUnknown_GrPixelConfig;
        }

        *outStartOfDataToUpload = bytes + ETC_PKM_HEADER_SIZE;
        return kETC1_GrPixelConfig;
    } else if (SkKTXFile::is_ktx(bytes, data->size())) {
        SkKTXFile ktx(data);

        // Is it actually an ETC1 texture?
        if (!ktx.isCompressedFormat(SkTextureCompressor::kETC1_Format)) {
            return kUnknown_GrPixelConfig;
        }

        // Does the data match the dimensions of the bitmap? If not,
        // then we don't know how to scale the image to match it...
        if (ktx.width() != expectedW || ktx.height() != expectedH) {
            return kUnknown_GrPixelConfig;
        }

        *outStartOfDataToUpload = ktx.pixelData();
        return kETC1_GrPixelConfig;
    }
#endif
    return kUnknown_GrPixelConfig;
}

//////////////////////////////////////////////////////////////////////////////

/**
 * Fill out buffer with the compressed format Ganesh expects from a colortable
 * based bitmap. [palette (colortable) + indices].
 *
 * At the moment Ganesh only supports 8bit version. If Ganesh allowed we others
 * we could detect that the colortable.count is <= 16, and then repack the
 * indices as nibbles to save RAM, but it would take more time (i.e. a lot
 * slower than memcpy), so skipping that for now.
 *
 * Ganesh wants a full 256 palette entry, even though Skia's ctable is only as big
 * as the colortable.count says it is.
 */
static void build_index8_data(void* buffer, const SkPixmap& pixmap)
{
    SkASSERT(kIndex_8_SkColorType == pixmap.colorType());

    const SkColorTable* ctable = pixmap.ctable();
=======
#include "SkPixelRef.h"
#include "SkResourceCache.h"
#include "SkTextureCompressor.h"
#include "SkYUVPlanesCache.h"
#include "effects/GrDitherEffect.h"
#include "effects/GrPorterDuffXferProcessor.h"
#include "effects/GrYUVtoRGBEffect.h"

#ifndef SK_IGNORE_ETC1_SUPPORT
#  include "ktx.h"
#  include "etc1.h"
#endif

/*  Fill out buffer with the compressed format Ganesh expects from a colortable
 based bitmap. [palette (colortable) + indices].

 At the moment Ganesh only supports 8bit version. If Ganesh allowed we others
 we could detect that the colortable.count is <= 16, and then repack the
 indices as nibbles to save RAM, but it would take more time (i.e. a lot
 slower than memcpy), so skipping that for now.

 Ganesh wants a full 256 palette entry, even though Skia's ctable is only as big
 as the colortable.count says it is.
 */
static void build_index8_data(void* buffer, const SkBitmap& bitmap) {
    SkASSERT(kIndex_8_SkColorType == bitmap.colorType());

    SkAutoLockPixels alp(bitmap);
    if (!bitmap.readyToDraw()) {
        SkDEBUGFAIL("bitmap not ready to draw!");
        return;
    }

    SkColorTable* ctable = bitmap.getColorTable();
>>>>>>> miniblink49
    char* dst = (char*)buffer;

    const int count = ctable->count();

    SkDstPixelInfo dstPI;
    dstPI.fColorType = kRGBA_8888_SkColorType;
    dstPI.fAlphaType = kPremul_SkAlphaType;
    dstPI.fPixels = buffer;
    dstPI.fRowBytes = count * sizeof(SkPMColor);

    SkSrcPixelInfo srcPI;
    srcPI.fColorType = kN32_SkColorType;
    srcPI.fAlphaType = kPremul_SkAlphaType;
    srcPI.fPixels = ctable->readColors();
    srcPI.fRowBytes = count * sizeof(SkPMColor);

    srcPI.convertPixelsTo(&dstPI, count, 1);

    // always skip a full 256 number of entries, even if we memcpy'd fewer
    dst += 256 * sizeof(GrColor);

<<<<<<< HEAD
    if ((unsigned)pixmap.width() == pixmap.rowBytes()) {
        memcpy(dst, pixmap.addr(), pixmap.getSafeSize());
    } else {
        // need to trim off the extra bytes per row
        size_t width = pixmap.width();
        size_t rowBytes = pixmap.rowBytes();
        const uint8_t* src = pixmap.addr8();
        for (int y = 0; y < pixmap.height(); y++) {
=======
    if ((unsigned)bitmap.width() == bitmap.rowBytes()) {
        memcpy(dst, bitmap.getPixels(), bitmap.getSize());
    } else {
        // need to trim off the extra bytes per row
        size_t width = bitmap.width();
        size_t rowBytes = bitmap.rowBytes();
        const char* src = (const char*)bitmap.getPixels();
        for (int y = 0; y < bitmap.height(); y++) {
>>>>>>> miniblink49
            memcpy(dst, src, width);
            src += rowBytes;
            dst += width;
        }
    }
}

<<<<<<< HEAD
/**
 *  Once we have made SkImages handle all lazy/deferred/generated content, the YUV apis will
 *  be gone from SkPixelRef, and we can remove this subclass entirely.
 */
class PixelRef_GrYUVProvider : public GrYUVProvider {
    SkPixelRef* fPR;

public:
    PixelRef_GrYUVProvider(SkPixelRef* pr)
        : fPR(pr)
    {
    }

    uint32_t onGetID() override { return fPR->getGenerationID(); }
    bool onQueryYUV8(SkYUVSizeInfo* sizeInfo, SkYUVColorSpace* colorSpace) const override
    {
        return fPR->queryYUV8(sizeInfo, colorSpace);
    }
    bool onGetYUV8Planes(const SkYUVSizeInfo& sizeInfo, void* planes[3]) override
    {
        return fPR->getYUV8Planes(sizeInfo, planes);
    }
};

static sk_sp<GrTexture> create_texture_from_yuv(GrContext* ctx, const SkBitmap& bm,
    const GrSurfaceDesc& desc)
{
    // Subsets are not supported, the whole pixelRef is loaded when using YUV decoding
    SkPixelRef* pixelRef = bm.pixelRef();
    if ((nullptr == pixelRef) || (pixelRef->info().width() != bm.info().width()) || (pixelRef->info().height() != bm.info().height())) {
        return nullptr;
    }

    PixelRef_GrYUVProvider provider(pixelRef);

    return provider.refAsTexture(ctx, desc, !bm.isVolatile());
}

static GrTexture* load_etc1_texture(GrContext* ctx, const SkBitmap& bm, GrSurfaceDesc desc)
{
    SkAutoTUnref<SkData> data(bm.pixelRef()->refEncodedData());
    if (!data) {
        return nullptr;
    }

    const void* startOfTexData;
    desc.fConfig = GrIsCompressedTextureDataSupported(ctx, data, bm.width(), bm.height(),
        &startOfTexData);
    if (kUnknown_GrPixelConfig == desc.fConfig) {
        return nullptr;
    }

    return ctx->textureProvider()->createTexture(desc, SkBudgeted::kYes, startOfTexData, 0);
}

GrTexture* GrUploadBitmapToTexture(GrContext* ctx, const SkBitmap& bitmap)
{
    GrSurfaceDesc desc = GrImageInfoToSurfaceDesc(bitmap.info(), *ctx->caps());
    if (GrTexture* texture = load_etc1_texture(ctx, bitmap, desc)) {
        return texture;
    }

    sk_sp<GrTexture> texture(create_texture_from_yuv(ctx, bitmap, desc));
    if (texture) {
        return texture.release();
    }

    SkAutoLockPixels alp(bitmap);
    if (!bitmap.readyToDraw()) {
        return nullptr;
    }
    SkPixmap pixmap;
    if (!bitmap.peekPixels(&pixmap)) {
        return nullptr;
    }
    return GrUploadPixmapToTexture(ctx, pixmap, SkBudgeted::kYes);
}

GrTexture* GrUploadPixmapToTexture(GrContext* ctx, const SkPixmap& pixmap, SkBudgeted budgeted)
{
    const SkPixmap* pmap = &pixmap;
    SkPixmap tmpPixmap;
    SkBitmap tmpBitmap;

    const GrCaps* caps = ctx->caps();
    GrSurfaceDesc desc = GrImageInfoToSurfaceDesc(pixmap.info(), *caps);

    if (caps->srgbSupport() && !GrPixelConfigIsSRGB(desc.fConfig) && pixmap.info().colorSpace() && pixmap.info().colorSpace()->gammaCloseToSRGB()) {
        // We were supplied an sRGB-like color space, but we don't have a suitable pixel config.
        // Convert to 8888 sRGB so we can handle the data correctly. The raster backend doesn't
        // handle sRGB Index8 -> sRGB 8888 correctly (yet), so lie about both the source and
        // destination (claim they're linear):
        SkImageInfo linSrcInfo = SkImageInfo::Make(pixmap.width(), pixmap.height(),
            pixmap.colorType(), pixmap.alphaType());
        SkPixmap linSrcPixmap(linSrcInfo, pixmap.addr(), pixmap.rowBytes(), pixmap.ctable());

        SkImageInfo dstInfo = SkImageInfo::Make(pixmap.width(), pixmap.height(),
            kN32_SkColorType, kPremul_SkAlphaType,
            sk_ref_sp(pixmap.info().colorSpace()));

        tmpBitmap.allocPixels(dstInfo);

        SkImageInfo linDstInfo = SkImageInfo::MakeN32Premul(pixmap.width(), pixmap.height());
        if (!linSrcPixmap.readPixels(linDstInfo, tmpBitmap.getPixels(), tmpBitmap.rowBytes())) {
            return nullptr;
        }
        if (!tmpBitmap.peekPixels(&tmpPixmap)) {
            return nullptr;
        }
        pmap = &tmpPixmap;
        // must rebuild desc, since we've forced the info to be N32
        desc = GrImageInfoToSurfaceDesc(pmap->info(), *caps);
    } else if (kGray_8_SkColorType == pixmap.colorType()) {
        // We don't have Gray8 support as a pixel config, so expand to 8888

        // We should have converted sRGB Gray8 above (if we have sRGB support):
        SkASSERT(!caps->srgbSupport() || !pixmap.info().colorSpace() || !pixmap.info().colorSpace()->gammaCloseToSRGB());

        SkImageInfo info = SkImageInfo::MakeN32(pixmap.width(), pixmap.height(),
            kOpaque_SkAlphaType);
        tmpBitmap.allocPixels(info);
        if (!pixmap.readPixels(info, tmpBitmap.getPixels(), tmpBitmap.rowBytes())) {
            return nullptr;
        }
        if (!tmpBitmap.peekPixels(&tmpPixmap)) {
            return nullptr;
        }
        pmap = &tmpPixmap;
        // must rebuild desc, since we've forced the info to be N32
        desc = GrImageInfoToSurfaceDesc(pmap->info(), *caps);
    } else if (kIndex_8_SkColorType == pixmap.colorType()) {
        if (caps->isConfigTexturable(kIndex_8_GrPixelConfig)) {
            size_t imageSize = GrCompressedFormatDataSize(kIndex_8_GrPixelConfig,
                pixmap.width(), pixmap.height());
            SkAutoMalloc storage(imageSize);
            build_index8_data(storage.get(), pixmap);

            // our compressed data will be trimmed, so pass width() for its
            // "rowBytes", since they are the same now.
            return ctx->textureProvider()->createTexture(desc, budgeted, storage.get(),
                pixmap.width());
        } else {
            SkImageInfo info = SkImageInfo::MakeN32Premul(pixmap.width(), pixmap.height());
            tmpBitmap.allocPixels(info);
            if (!pixmap.readPixels(info, tmpBitmap.getPixels(), tmpBitmap.rowBytes())) {
                return nullptr;
            }
            if (!tmpBitmap.peekPixels(&tmpPixmap)) {
                return nullptr;
            }
            pmap = &tmpPixmap;
            // must rebuild desc, since we've forced the info to be N32
            desc = GrImageInfoToSurfaceDesc(pmap->info(), *caps);
        }
    }

    return ctx->textureProvider()->createTexture(desc, budgeted, pmap->addr(),
        pmap->rowBytes());
}

////////////////////////////////////////////////////////////////////////////////

void GrInstallBitmapUniqueKeyInvalidator(const GrUniqueKey& key, SkPixelRef* pixelRef)
{
    class Invalidator : public SkPixelRef::GenIDChangeListener {
    public:
        explicit Invalidator(const GrUniqueKey& key)
            : fMsg(key)
        {
        }

    private:
        GrUniqueKeyInvalidatedMessage fMsg;

        void onChange() override { SkMessageBus<GrUniqueKeyInvalidatedMessage>::Post(fMsg); }
    };

    pixelRef->addGenIDChangeListener(new Invalidator(key));
}

GrTexture* GrGenerateMipMapsAndUploadToTexture(GrContext* ctx, const SkBitmap& bitmap,
    SkSourceGammaTreatment gammaTreatment)
{
    GrSurfaceDesc desc = GrImageInfoToSurfaceDesc(bitmap.info(), *ctx->caps());
    if (kIndex_8_SkColorType != bitmap.colorType() && !bitmap.readyToDraw()) {
        GrTexture* texture = load_etc1_texture(ctx, bitmap, desc);
=======
////////////////////////////////////////////////////////////////////////////////

struct Stretch {
    enum Type {
        kNone_Type,
        kBilerp_Type,
        kNearest_Type
    } fType;
    int fWidth;
    int fHeight;
};

static void get_stretch(const GrContext* ctx, int width, int height,
                        const GrTextureParams* params, Stretch* stretch) {
    stretch->fType = Stretch::kNone_Type;
    bool doStretch = false;
    if (params && params->isTiled() && !ctx->caps()->npotTextureTileSupport() &&
        (!SkIsPow2(width) || !SkIsPow2(height))) {
        doStretch = true;
        stretch->fWidth  = GrNextPow2(width);
        stretch->fHeight = GrNextPow2(height);
    } else if (width < ctx->caps()->minTextureSize() ||
               height < ctx->caps()->minTextureSize()) {
        // The small texture issues appear to be with tiling. Hence it seems ok to scale them
        // up using the GPU. If issues persist we may need to CPU-stretch.
        doStretch = true;
        stretch->fWidth = SkTMax(width, ctx->caps()->minTextureSize());
        stretch->fHeight = SkTMax(height, ctx->caps()->minTextureSize());
    }
    if (doStretch) {
        if (params) {
            switch(params->filterMode()) {
                case GrTextureParams::kNone_FilterMode:
                    stretch->fType = Stretch::kNearest_Type;
                    break;
                case GrTextureParams::kBilerp_FilterMode:
                case GrTextureParams::kMipMap_FilterMode:
                    stretch->fType = Stretch::kBilerp_Type;
                    break;
            }
        } else {
            stretch->fType = Stretch::kBilerp_Type;
        }
    } else {
        stretch->fWidth  = -1;
        stretch->fHeight = -1;
        stretch->fType = Stretch::kNone_Type;
    }
}

static bool make_stretched_key(const GrUniqueKey& origKey, const Stretch& stretch,
                               GrUniqueKey* stretchedKey) {
    if (origKey.isValid() && Stretch::kNone_Type != stretch.fType) {
        uint32_t width = SkToU16(stretch.fWidth);
        uint32_t height = SkToU16(stretch.fHeight);
        static const GrUniqueKey::Domain kDomain = GrUniqueKey::GenerateDomain();
        GrUniqueKey::Builder builder(stretchedKey, origKey, kDomain, 3);
        builder[0] = stretch.fType;
        builder[1] = width | (height << 16);
        builder.finish();
        return true;
    }
    SkASSERT(!stretchedKey->isValid());
    return false;
}

static void make_unstretched_key(const SkBitmap& bitmap, GrUniqueKey* key) {
    // Our id includes the offset, width, and height so that bitmaps created by extractSubset()
    // are unique.
    uint32_t genID = bitmap.getGenerationID();
    SkIPoint origin = bitmap.pixelRefOrigin();
    uint32_t width = SkToU16(bitmap.width());
    uint32_t height = SkToU16(bitmap.height());

    static const GrUniqueKey::Domain kDomain = GrUniqueKey::GenerateDomain();
    GrUniqueKey::Builder builder(key, kDomain, 4);
    builder[0] = genID;
    builder[1] = origin.fX;
    builder[2] = origin.fY;
    builder[3] = width | (height << 16);
}

static void make_bitmap_keys(const SkBitmap& bitmap,
                             const Stretch& stretch,
                             GrUniqueKey* key,
                             GrUniqueKey* stretchedKey) {
    make_unstretched_key(bitmap, key);
    if (Stretch::kNone_Type != stretch.fType) {
        make_stretched_key(*key, stretch, stretchedKey);
    }
}

static void generate_bitmap_texture_desc(const SkBitmap& bitmap, GrSurfaceDesc* desc) {
    desc->fFlags = kNone_GrSurfaceFlags;
    desc->fWidth = bitmap.width();
    desc->fHeight = bitmap.height();
    desc->fConfig = SkImageInfo2GrPixelConfig(bitmap.info());
    desc->fSampleCnt = 0;
}

namespace {

// When the SkPixelRef genID changes, invalidate a corresponding GrResource described by key.
class BitmapInvalidator : public SkPixelRef::GenIDChangeListener {
public:
    explicit BitmapInvalidator(const GrUniqueKey& key) : fMsg(key) {}
private:
    GrUniqueKeyInvalidatedMessage fMsg;

    void onChange() override {
        SkMessageBus<GrUniqueKeyInvalidatedMessage>::Post(fMsg);
    }
};

}  // namespace


static GrTexture* create_texture_for_bmp(GrContext* ctx,
                                         const GrUniqueKey& optionalKey,
                                         GrSurfaceDesc desc,
                                         SkPixelRef* pixelRefForInvalidationNotification,
                                         const void* pixels,
                                         size_t rowBytes) {
    GrTexture* result = ctx->textureProvider()->createTexture(desc, true, pixels, rowBytes);
    if (result && optionalKey.isValid()) {
        BitmapInvalidator* listener = SkNEW_ARGS(BitmapInvalidator, (optionalKey));
        pixelRefForInvalidationNotification->addGenIDChangeListener(listener);
        ctx->textureProvider()->assignUniqueKeyToTexture(optionalKey, result);
    }
    return result;
}

// creates a new texture that is the input texture scaled up. If optionalKey is valid it will be
// set on the new texture. stretch controls whether the scaling is done using nearest or bilerp
// filtering and the size to stretch the texture to.
GrTexture* stretch_texture(GrTexture* inputTexture, const Stretch& stretch,
                           SkPixelRef* pixelRef,
                           const GrUniqueKey& optionalKey) {
    SkASSERT(Stretch::kNone_Type != stretch.fType);

    GrContext* context = inputTexture->getContext();
    SkASSERT(context);
    const GrCaps* caps = context->caps();

    // Either it's a cache miss or the original wasn't cached to begin with.
    GrSurfaceDesc rtDesc = inputTexture->desc();
    rtDesc.fFlags =  rtDesc.fFlags | kRenderTarget_GrSurfaceFlag;
    rtDesc.fWidth  = stretch.fWidth;
    rtDesc.fHeight = stretch.fHeight;
    rtDesc.fConfig = GrMakePixelConfigUncompressed(rtDesc.fConfig);

    // If the config isn't renderable try converting to either A8 or an 32 bit config. Otherwise,
    // fail.
    if (!caps->isConfigRenderable(rtDesc.fConfig, false)) {
        if (GrPixelConfigIsAlphaOnly(rtDesc.fConfig)) {
            if (caps->isConfigRenderable(kAlpha_8_GrPixelConfig, false)) {
                rtDesc.fConfig = kAlpha_8_GrPixelConfig;
            } else if (caps->isConfigRenderable(kSkia8888_GrPixelConfig, false)) {
                rtDesc.fConfig = kSkia8888_GrPixelConfig;
            } else {
                return NULL;
            }
        } else if (kRGB_GrColorComponentFlags ==
                   (kRGB_GrColorComponentFlags & GrPixelConfigComponentMask(rtDesc.fConfig))) {
            if (caps->isConfigRenderable(kSkia8888_GrPixelConfig, false)) {
                rtDesc.fConfig = kSkia8888_GrPixelConfig;
            } else {
                return NULL;
            }
        } else {
            return NULL;
        }
    }

    GrTexture* stretched = create_texture_for_bmp(context, optionalKey, rtDesc, pixelRef, NULL, 0);

    if (!stretched) {
        return NULL;
    }
    GrPaint paint;

    // If filtering is not desired then we want to ensure all texels in the resampled image are
    // copies of texels from the original.
    GrTextureParams params(SkShader::kClamp_TileMode,
                           Stretch::kBilerp_Type == stretch.fType ?
                              GrTextureParams::kBilerp_FilterMode :
                              GrTextureParams::kNone_FilterMode);
    paint.addColorTextureProcessor(inputTexture, SkMatrix::I(), params);

    SkRect rect = SkRect::MakeWH(SkIntToScalar(rtDesc.fWidth), SkIntToScalar(rtDesc.fHeight));
    SkRect localRect = SkRect::MakeWH(1.f, 1.f);

    GrDrawContext* drawContext = context->drawContext();
    if (!drawContext) {
        return NULL;
    }

    drawContext->drawNonAARectToRect(stretched->asRenderTarget(), GrClip::WideOpen(), paint,
                                     SkMatrix::I(), rect, localRect);

    return stretched;
}

#ifndef SK_IGNORE_ETC1_SUPPORT
static GrTexture *load_etc1_texture(GrContext* ctx, const GrUniqueKey& optionalKey,
                                    const SkBitmap &bm, GrSurfaceDesc desc) {
    SkAutoTUnref<SkData> data(bm.pixelRef()->refEncodedData());

    // Is this even encoded data?
    if (NULL == data) {
        return NULL;
    }

    // Is this a valid PKM encoded data?
    const uint8_t *bytes = data->bytes();
    if (etc1_pkm_is_valid(bytes)) {
        uint32_t encodedWidth = etc1_pkm_get_width(bytes);
        uint32_t encodedHeight = etc1_pkm_get_height(bytes);

        // Does the data match the dimensions of the bitmap? If not,
        // then we don't know how to scale the image to match it...
        if (encodedWidth != static_cast<uint32_t>(bm.width()) ||
            encodedHeight != static_cast<uint32_t>(bm.height())) {
            return NULL;
        }

        // Everything seems good... skip ahead to the data.
        bytes += ETC_PKM_HEADER_SIZE;
        desc.fConfig = kETC1_GrPixelConfig;
    } else if (SkKTXFile::is_ktx(bytes)) {
        SkKTXFile ktx(data);

        // Is it actually an ETC1 texture?
        if (!ktx.isCompressedFormat(SkTextureCompressor::kETC1_Format)) {
            return NULL;
        }

        // Does the data match the dimensions of the bitmap? If not,
        // then we don't know how to scale the image to match it...
        if (ktx.width() != bm.width() || ktx.height() != bm.height()) {
            return NULL;
        }

        bytes = ktx.pixelData();
        desc.fConfig = kETC1_GrPixelConfig;
    } else {
        return NULL;
    }

    return create_texture_for_bmp(ctx, optionalKey, desc, bm.pixelRef(), bytes, 0);
}
#endif   // SK_IGNORE_ETC1_SUPPORT

static GrTexture* load_yuv_texture(GrContext* ctx, const GrUniqueKey& optionalKey,
                                   const SkBitmap& bm, const GrSurfaceDesc& desc) {
    // Subsets are not supported, the whole pixelRef is loaded when using YUV decoding
    SkPixelRef* pixelRef = bm.pixelRef();
    if ((NULL == pixelRef) || 
        (pixelRef->info().width()  != bm.info().width()) ||
        (pixelRef->info().height() != bm.info().height())) {
        return NULL;
    }

    const bool useCache = optionalKey.isValid();
    SkYUVPlanesCache::Info yuvInfo;
    SkAutoTUnref<SkCachedData> cachedData;
    SkAutoMalloc storage;
    if (useCache) {
        cachedData.reset(SkYUVPlanesCache::FindAndRef(pixelRef->getGenerationID(), &yuvInfo));
    }

    void* planes[3];
    if (cachedData.get()) {
        planes[0] = (void*)cachedData->data();
        planes[1] = (uint8_t*)planes[0] + yuvInfo.fSizeInMemory[0];
        planes[2] = (uint8_t*)planes[1] + yuvInfo.fSizeInMemory[1];
    } else {
        // Fetch yuv plane sizes for memory allocation. Here, width and height can be
        // rounded up to JPEG block size and be larger than the image's width and height.
        if (!pixelRef->getYUV8Planes(yuvInfo.fSize, NULL, NULL, NULL)) {
            return NULL;
        }

        // Allocate the memory for YUV
        size_t totalSize(0);
        for (int i = 0; i < 3; ++i) {
            yuvInfo.fRowBytes[i] = yuvInfo.fSize[i].fWidth;
            yuvInfo.fSizeInMemory[i] = yuvInfo.fRowBytes[i] * yuvInfo.fSize[i].fHeight;
            totalSize += yuvInfo.fSizeInMemory[i];
        }
        if (useCache) {
            cachedData.reset(SkResourceCache::NewCachedData(totalSize));
            planes[0] = cachedData->writable_data();
        } else {
            storage.reset(totalSize);
            planes[0] = storage.get();
        }
        planes[1] = (uint8_t*)planes[0] + yuvInfo.fSizeInMemory[0];
        planes[2] = (uint8_t*)planes[1] + yuvInfo.fSizeInMemory[1];

        // Get the YUV planes and update plane sizes to actual image size
        if (!pixelRef->getYUV8Planes(yuvInfo.fSize, planes, yuvInfo.fRowBytes,
                                     &yuvInfo.fColorSpace)) {
            return NULL;
        }

        if (useCache) {
            // Decoding is done, cache the resulting YUV planes
            SkYUVPlanesCache::Add(pixelRef->getGenerationID(), cachedData, &yuvInfo);
        }
    }

    GrSurfaceDesc yuvDesc;
    yuvDesc.fConfig = kAlpha_8_GrPixelConfig;
    SkAutoTUnref<GrTexture> yuvTextures[3];
    for (int i = 0; i < 3; ++i) {
        yuvDesc.fWidth  = yuvInfo.fSize[i].fWidth;
        yuvDesc.fHeight = yuvInfo.fSize[i].fHeight;
        bool needsExactTexture =
            (yuvDesc.fWidth  != yuvInfo.fSize[0].fWidth) ||
            (yuvDesc.fHeight != yuvInfo.fSize[0].fHeight);
        yuvTextures[i].reset(ctx->textureProvider()->refScratchTexture(yuvDesc,
            needsExactTexture ? GrTextureProvider::kExact_ScratchTexMatch :
                                GrTextureProvider::kApprox_ScratchTexMatch));
        if (!yuvTextures[i] ||
            !yuvTextures[i]->writePixels(0, 0, yuvDesc.fWidth, yuvDesc.fHeight,
                                         yuvDesc.fConfig, planes[i], yuvInfo.fRowBytes[i])) {
            return NULL;
        }
    }

    GrSurfaceDesc rtDesc = desc;
    rtDesc.fFlags = rtDesc.fFlags | kRenderTarget_GrSurfaceFlag;

    GrTexture* result = create_texture_for_bmp(ctx, optionalKey, rtDesc, pixelRef, NULL, 0);
    if (!result) {
        return NULL;
    }

    GrRenderTarget* renderTarget = result->asRenderTarget();
    SkASSERT(renderTarget);

    GrPaint paint;
    SkAutoTUnref<GrFragmentProcessor>
        yuvToRgbProcessor(GrYUVtoRGBEffect::Create(paint.getProcessorDataManager(), yuvTextures[0],
                                                   yuvTextures[1], yuvTextures[2],
                                                   yuvInfo.fSize, yuvInfo.fColorSpace));
    paint.addColorProcessor(yuvToRgbProcessor);
    SkRect r = SkRect::MakeWH(SkIntToScalar(yuvInfo.fSize[0].fWidth),
                              SkIntToScalar(yuvInfo.fSize[0].fHeight));

    GrDrawContext* drawContext = ctx->drawContext();
    if (!drawContext) {
        return NULL;
    }

    drawContext->drawRect(renderTarget, GrClip::WideOpen(), paint, SkMatrix::I(), r);

    return result;
}

static GrTexture* create_unstretched_bitmap_texture(GrContext* ctx,
                                                    const SkBitmap& origBitmap,
                                                    const GrUniqueKey& optionalKey) {
    SkBitmap tmpBitmap;

    const SkBitmap* bitmap = &origBitmap;

    GrSurfaceDesc desc;
    generate_bitmap_texture_desc(*bitmap, &desc);
    const GrCaps* caps = ctx->caps();

    if (kIndex_8_SkColorType == bitmap->colorType()) {
        if (caps->isConfigTexturable(kIndex_8_GrPixelConfig)) {
            size_t imageSize = GrCompressedFormatDataSize(kIndex_8_GrPixelConfig,
                                                          bitmap->width(), bitmap->height());
            SkAutoMalloc storage(imageSize);
            build_index8_data(storage.get(), origBitmap);

            // our compressed data will be trimmed, so pass width() for its
            // "rowBytes", since they are the same now.
            return create_texture_for_bmp(ctx, optionalKey, desc, origBitmap.pixelRef(),
                                          storage.get(), bitmap->width());
        } else {
            origBitmap.copyTo(&tmpBitmap, kN32_SkColorType);
            // now bitmap points to our temp, which has been promoted to 32bits
            bitmap = &tmpBitmap;
            desc.fConfig = SkImageInfo2GrPixelConfig(bitmap->info());
        }
    }

    // Is this an ETC1 encoded texture?
#ifndef SK_IGNORE_ETC1_SUPPORT
    // Make sure that the underlying device supports ETC1 textures before we go ahead
    // and check the data.
    else if (caps->isConfigTexturable(kETC1_GrPixelConfig)
            // If the bitmap had compressed data and was then uncompressed, it'll still return
            // compressed data on 'refEncodedData' and upload it. Probably not good, since if
            // the bitmap has available pixels, then they might not be what the decompressed
            // data is.
            && !(bitmap->readyToDraw())) {
        GrTexture *texture = load_etc1_texture(ctx, optionalKey, *bitmap, desc);
>>>>>>> miniblink49
        if (texture) {
            return texture;
        }
    }
<<<<<<< HEAD

    sk_sp<GrTexture> texture(create_texture_from_yuv(ctx, bitmap, desc));
    if (texture) {
        return texture.release();
    }

    // We don't support Gray8 directly in the GL backend, so fail-over to GrUploadBitmapToTexture.
    // That will transform the Gray8 to 8888, then use the driver/GPU to build mipmaps. If we build
    // the mips on the CPU here, they'll all be Gray8, which isn't useful. (They get treated as A8).
    // TODO: A better option might be to transform the initial bitmap here to 8888, then run the
    // CPU mip-mapper on that data before uploading. This is much less code for a rare case though:
    if (kGray_8_SkColorType == bitmap.colorType()) {
        return nullptr;
    }

    SkASSERT(sizeof(int) <= sizeof(uint32_t));
    if (bitmap.width() < 0 || bitmap.height() < 0) {
        return nullptr;
    }

    SkAutoPixmapUnlock srcUnlocker;
    if (!bitmap.requestLock(&srcUnlocker)) {
        return nullptr;
    }
    const SkPixmap& pixmap = srcUnlocker.pixmap();
    // Try to catch where we might have returned nullptr for src crbug.com/492818
    if (nullptr == pixmap.addr()) {
        sk_throw();
    }

    SkAutoTDelete<SkMipMap> mipmaps(SkMipMap::Build(pixmap, gammaTreatment, nullptr));
    if (!mipmaps) {
        return nullptr;
    }

    const int mipLevelCount = mipmaps->countLevels() + 1;
    if (mipLevelCount < 1) {
        return nullptr;
    }

    const bool isMipMapped = mipLevelCount > 1;
    desc.fIsMipMapped = isMipMapped;

    SkAutoTDeleteArray<GrMipLevel> texels(new GrMipLevel[mipLevelCount]);

    texels[0].fPixels = pixmap.addr();
    texels[0].fRowBytes = pixmap.rowBytes();

    for (int i = 1; i < mipLevelCount; ++i) {
        SkMipMap::Level generatedMipLevel;
        mipmaps->getLevel(i - 1, &generatedMipLevel);
        texels[i].fPixels = generatedMipLevel.fPixmap.addr();
        texels[i].fRowBytes = generatedMipLevel.fPixmap.rowBytes();
    }

    {
        GrTexture* texture = ctx->textureProvider()->createMipMappedTexture(desc,
            SkBudgeted::kYes,
            texels.get(),
            mipLevelCount);
        if (texture) {
            texture->texturePriv().setGammaTreatment(gammaTreatment);
        }
        return texture;
    }
}

GrTexture* GrUploadMipMapToTexture(GrContext* ctx, const SkImageInfo& info,
    const GrMipLevel* texels, int mipLevelCount)
{
    const GrCaps* caps = ctx->caps();
    return ctx->textureProvider()->createMipMappedTexture(GrImageInfoToSurfaceDesc(info, *caps),
        SkBudgeted::kYes, texels,
        mipLevelCount);
}

GrTexture* GrRefCachedBitmapTexture(GrContext* ctx, const SkBitmap& bitmap,
    const GrTextureParams& params,
    SkSourceGammaTreatment gammaTreatment)
{
    if (bitmap.getTexture()) {
        return GrBitmapTextureAdjuster(&bitmap).refTextureSafeForParams(params, gammaTreatment,
            nullptr);
    }
    return GrBitmapTextureMaker(ctx, bitmap).refTextureForParams(params, gammaTreatment);
}

=======
#endif   // SK_IGNORE_ETC1_SUPPORT

    GrTexture *texture = load_yuv_texture(ctx, optionalKey, *bitmap, desc);
    if (texture) {
        return texture;
    }

    SkAutoLockPixels alp(*bitmap);
    if (!bitmap->readyToDraw()) {
        return NULL;
    }

    return create_texture_for_bmp(ctx, optionalKey, desc, origBitmap.pixelRef(),
                                  bitmap->getPixels(), bitmap->rowBytes());
}

static GrTexture* create_bitmap_texture(GrContext* ctx,
                                        const SkBitmap& bmp,
                                        const Stretch& stretch,
                                        const GrUniqueKey& unstretchedKey,
                                        const GrUniqueKey& stretchedKey) {
    if (Stretch::kNone_Type != stretch.fType) {
        SkAutoTUnref<GrTexture> unstretched;
        // Check if we have the unstretched version in the cache, if not create it.
        if (unstretchedKey.isValid()) {
            unstretched.reset(ctx->textureProvider()->findAndRefTextureByUniqueKey(unstretchedKey));
        }
        if (!unstretched) {
            unstretched.reset(create_unstretched_bitmap_texture(ctx, bmp, unstretchedKey));
            if (!unstretched) {
                return NULL;
            }
        }
        GrTexture* stretched = stretch_texture(unstretched, stretch, bmp.pixelRef(), stretchedKey);
        return stretched;
    }

    return create_unstretched_bitmap_texture(ctx, bmp, unstretchedKey);

}

bool GrIsBitmapInCache(const GrContext* ctx,
                       const SkBitmap& bitmap,
                       const GrTextureParams* params) {
    Stretch stretch;
    get_stretch(ctx, bitmap.width(), bitmap.height(), params, &stretch);

    // Handle the case where the bitmap is explicitly texture backed.
    GrTexture* texture = bitmap.getTexture();
    if (texture) {
        if (Stretch::kNone_Type == stretch.fType) {
            return true;
        }
        // No keys for volatile bitmaps.
        if (bitmap.isVolatile()) {
            return false;
        }
        const GrUniqueKey& key = texture->getUniqueKey();
        if (!key.isValid()) {
            return false;
        }
        GrUniqueKey stretchedKey;
        make_stretched_key(key, stretch, &stretchedKey);
        return ctx->textureProvider()->existsTextureWithUniqueKey(stretchedKey);
    }

    // We don't cache volatile bitmaps
    if (bitmap.isVolatile()) {
        return false;
    }

    GrUniqueKey key, stretchedKey;
    make_bitmap_keys(bitmap, stretch, &key, &stretchedKey);
    return ctx->textureProvider()->existsTextureWithUniqueKey(
        (Stretch::kNone_Type == stretch.fType) ? key : stretchedKey);
}

GrTexture* GrRefCachedBitmapTexture(GrContext* ctx,
                                    const SkBitmap& bitmap,
                                    const GrTextureParams* params) {

    Stretch stretch;
    get_stretch(ctx, bitmap.width(), bitmap.height(), params, &stretch);

    GrTexture* result = bitmap.getTexture();
    if (result) {
        if (Stretch::kNone_Type == stretch.fType) {
            return SkRef(result);
        }
        GrUniqueKey stretchedKey;
        // Don't create a key for the resized version if the bmp is volatile.
        if (!bitmap.isVolatile()) {
            const GrUniqueKey& key = result->getUniqueKey();
            if (key.isValid()) {
                make_stretched_key(key, stretch, &stretchedKey);
                GrTexture* stretched =
                    ctx->textureProvider()->findAndRefTextureByUniqueKey(stretchedKey);
                if (stretched) {
                    return stretched;
                }
            }
        }
        return stretch_texture(result, stretch, bitmap.pixelRef(), stretchedKey);
    }

    GrUniqueKey key, resizedKey;

    if (!bitmap.isVolatile()) {
        // If the bitmap isn't changing try to find a cached copy first.
        make_bitmap_keys(bitmap, stretch, &key, &resizedKey);

        result = ctx->textureProvider()->findAndRefTextureByUniqueKey(
            resizedKey.isValid() ? resizedKey : key);
        if (result) {
            return result;
        }
    }

    result = create_bitmap_texture(ctx, bitmap, stretch, key, resizedKey);
    if (result) {
        return result;
    }

    SkErrorInternals::SetError( kInternalError_SkError,
                                "---- failed to create texture for cache [%d %d]\n",
                                bitmap.width(), bitmap.height());

    return NULL;
}
>>>>>>> miniblink49
///////////////////////////////////////////////////////////////////////////////

// alphatype is ignore for now, but if GrPixelConfig is expanded to encompass
// alpha info, that will be considered.
<<<<<<< HEAD
GrPixelConfig SkImageInfo2GrPixelConfig(SkColorType ct, SkAlphaType, const SkColorSpace* cs,
    const GrCaps& caps)
{
    // We intentionally ignore profile type for non-8888 formats. Anything we can't support
    // in hardware will be expanded to sRGB 8888 in GrUploadPixmapToTexture.
    switch (ct) {
    case kUnknown_SkColorType:
        return kUnknown_GrPixelConfig;
    case kAlpha_8_SkColorType:
        return kAlpha_8_GrPixelConfig;
    case kRGB_565_SkColorType:
        return kRGB_565_GrPixelConfig;
    case kARGB_4444_SkColorType:
        return kRGBA_4444_GrPixelConfig;
    case kRGBA_8888_SkColorType:
        return (caps.srgbSupport() && cs && cs->gammaCloseToSRGB())
            ? kSRGBA_8888_GrPixelConfig
            : kRGBA_8888_GrPixelConfig;
    case kBGRA_8888_SkColorType:
        return (caps.srgbSupport() && cs && cs->gammaCloseToSRGB())
            ? kSBGRA_8888_GrPixelConfig
            : kBGRA_8888_GrPixelConfig;
    case kIndex_8_SkColorType:
        return kIndex_8_GrPixelConfig;
    case kGray_8_SkColorType:
        return kAlpha_8_GrPixelConfig; // TODO: gray8 support on gpu
    case kRGBA_F16_SkColorType:
        return kRGBA_half_GrPixelConfig;
    }
    SkASSERT(0); // shouldn't get here
    return kUnknown_GrPixelConfig;
}

bool GrPixelConfigToColorAndColorSpace(GrPixelConfig config, SkColorType* ctOut,
    sk_sp<SkColorSpace>* csOut)
{
    SkColorType ct;
    sk_sp<SkColorSpace> cs = nullptr;
    switch (config) {
    case kAlpha_8_GrPixelConfig:
        ct = kAlpha_8_SkColorType;
        break;
    case kIndex_8_GrPixelConfig:
        ct = kIndex_8_SkColorType;
        break;
    case kRGB_565_GrPixelConfig:
        ct = kRGB_565_SkColorType;
        break;
    case kRGBA_4444_GrPixelConfig:
        ct = kARGB_4444_SkColorType;
        break;
    case kRGBA_8888_GrPixelConfig:
        ct = kRGBA_8888_SkColorType;
        break;
    case kBGRA_8888_GrPixelConfig:
        ct = kBGRA_8888_SkColorType;
        break;
    case kSRGBA_8888_GrPixelConfig:
        ct = kRGBA_8888_SkColorType;
        cs = SkColorSpace::NewNamed(SkColorSpace::kSRGB_Named);
        break;
    case kSBGRA_8888_GrPixelConfig:
        ct = kBGRA_8888_SkColorType;
        cs = SkColorSpace::NewNamed(SkColorSpace::kSRGB_Named);
        break;
    case kRGBA_half_GrPixelConfig:
        ct = kRGBA_F16_SkColorType;
        break;
    default:
        return false;
=======
GrPixelConfig SkImageInfo2GrPixelConfig(SkColorType ct, SkAlphaType, SkColorProfileType pt) {
    switch (ct) {
        case kUnknown_SkColorType:
            return kUnknown_GrPixelConfig;
        case kAlpha_8_SkColorType:
            return kAlpha_8_GrPixelConfig;
        case kRGB_565_SkColorType:
            return kRGB_565_GrPixelConfig;
        case kARGB_4444_SkColorType:
            return kRGBA_4444_GrPixelConfig;
        case kRGBA_8888_SkColorType:
            //if (kSRGB_SkColorProfileType == pt) {
            //    return kSRGBA_8888_GrPixelConfig;
            //}
            return kRGBA_8888_GrPixelConfig;
        case kBGRA_8888_SkColorType:
            return kBGRA_8888_GrPixelConfig;
        case kIndex_8_SkColorType:
            return kIndex_8_GrPixelConfig;
        case kGray_8_SkColorType:
            return kAlpha_8_GrPixelConfig; // TODO: gray8 support on gpu
    }
    SkASSERT(0);    // shouldn't get here
    return kUnknown_GrPixelConfig;
}

bool GrPixelConfig2ColorAndProfileType(GrPixelConfig config, SkColorType* ctOut,
                                       SkColorProfileType* ptOut) {
    SkColorType ct;
    SkColorProfileType pt = kLinear_SkColorProfileType;
    switch (config) {
        case kAlpha_8_GrPixelConfig:
            ct = kAlpha_8_SkColorType;
            break;
        case kIndex_8_GrPixelConfig:
            ct = kIndex_8_SkColorType;
            break;
        case kRGB_565_GrPixelConfig:
            ct = kRGB_565_SkColorType;
            break;
        case kRGBA_4444_GrPixelConfig:
            ct = kARGB_4444_SkColorType;
            break;
        case kRGBA_8888_GrPixelConfig:
            ct = kRGBA_8888_SkColorType;
            break;
        case kBGRA_8888_GrPixelConfig:
            ct = kBGRA_8888_SkColorType;
            break;
        case kSRGBA_8888_GrPixelConfig:
            ct = kRGBA_8888_SkColorType;
            pt = kSRGB_SkColorProfileType;
            break;
        default:
            return false;
>>>>>>> miniblink49
    }
    if (ctOut) {
        *ctOut = ct;
    }
<<<<<<< HEAD
    if (csOut) {
        *csOut = cs;
=======
    if (ptOut) {
        *ptOut = pt;
>>>>>>> miniblink49
    }
    return true;
}

<<<<<<< HEAD
////////////////////////////////////////////////////////////////////////////////////////////////

static inline bool blend_requires_shader(const SkXfermode::Mode mode, bool primitiveIsSrc)
{
    if (primitiveIsSrc) {
        return SkXfermode::kSrc_Mode != mode;
    } else {
        return SkXfermode::kDst_Mode != mode;
    }
}

static inline bool skpaint_to_grpaint_impl(GrContext* context,
    const SkPaint& skPaint,
    const SkMatrix& viewM,
    sk_sp<GrFragmentProcessor>* shaderProcessor,
    SkXfermode::Mode* primColorMode,
    bool primitiveIsSrc,
    bool allowSRGBInputs,
    GrPaint* grPaint)
{
    grPaint->setAntiAlias(skPaint.isAntiAlias());
    grPaint->setAllowSRGBInputs(allowSRGBInputs);

    // Raw translation of the SkPaint color to our 4f format:
    GrColor4f origColor = GrColor4f::FromGrColor(SkColorToUnpremulGrColor(skPaint.getColor()));

    // Linearize, if the color is meant to be in sRGB gamma:
    if (allowSRGBInputs) {
        origColor.fRGBA[0] = exact_srgb_to_linear(origColor.fRGBA[0]);
        origColor.fRGBA[1] = exact_srgb_to_linear(origColor.fRGBA[1]);
        origColor.fRGBA[2] = exact_srgb_to_linear(origColor.fRGBA[2]);
    }

    // Setup the initial color considering the shader, the SkPaint color, and the presence or not
    // of per-vertex colors.
    sk_sp<GrFragmentProcessor> shaderFP;
    if (!primColorMode || blend_requires_shader(*primColorMode, primitiveIsSrc)) {
        if (shaderProcessor) {
            shaderFP = *shaderProcessor;
        } else if (const SkShader* shader = skPaint.getShader()) {
            SkSourceGammaTreatment gammaTreatment = allowSRGBInputs
                ? SkSourceGammaTreatment::kRespect
                : SkSourceGammaTreatment::kIgnore;
            shaderFP = shader->asFragmentProcessor(context, viewM, nullptr,
                skPaint.getFilterQuality(), gammaTreatment);
            if (!shaderFP) {
                return false;
            }
        }
    }

    // Set this in below cases if the output of the shader/paint-color/paint-alpha/primXfermode is
    // a known constant value. In that case we can simply apply a color filter during this
    // conversion without converting the color filter to a GrFragmentProcessor.
    bool applyColorFilterToPaintColor = false;
    if (shaderFP) {
        if (primColorMode) {
            // There is a blend between the primitive color and the shader color. The shader sees
            // the opaque paint color. The shader's output is blended using the provided mode by
            // the primitive color. The blended color is then modulated by the paint's alpha.

            // The geometry processor will insert the primitive color to start the color chain, so
            // the GrPaint color will be ignored.

            GrColor shaderInput = origColor.opaque().toGrColor();

            // SRGBTODO: Preserve 4f on this code path
            shaderFP = GrFragmentProcessor::OverrideInput(shaderFP, shaderInput);
            if (primitiveIsSrc) {
                shaderFP = GrXfermodeFragmentProcessor::MakeFromDstProcessor(std::move(shaderFP),
                    *primColorMode);
            } else {
                shaderFP = GrXfermodeFragmentProcessor::MakeFromSrcProcessor(std::move(shaderFP),
                    *primColorMode);
            }
            // The above may return null if compose results in a pass through of the prim color.
            if (shaderFP) {
                grPaint->addColorFragmentProcessor(shaderFP);
            }

            // We can ignore origColor here - alpha is unchanged by gamma
            GrColor paintAlpha = SkColorAlphaToGrColor(skPaint.getColor());
            if (GrColor_WHITE != paintAlpha) {
                grPaint->addColorFragmentProcessor(GrConstColorProcessor::Make(
                    paintAlpha, GrConstColorProcessor::kModulateRGBA_InputMode));
            }
        } else {
            // The shader's FP sees the paint unpremul color
            grPaint->setColor4f(origColor);
            grPaint->addColorFragmentProcessor(std::move(shaderFP));
        }
    } else {
        if (primColorMode) {
            // There is a blend between the primitive color and the paint color. The blend considers
            // the opaque paint color. The paint's alpha is applied to the post-blended color.
            // SRGBTODO: Preserve 4f on this code path
            sk_sp<GrFragmentProcessor> processor(
                GrConstColorProcessor::Make(origColor.opaque().toGrColor(),
                    GrConstColorProcessor::kIgnore_InputMode));
            if (primitiveIsSrc) {
                processor = GrXfermodeFragmentProcessor::MakeFromDstProcessor(std::move(processor),
                    *primColorMode);
            } else {
                processor = GrXfermodeFragmentProcessor::MakeFromSrcProcessor(std::move(processor),
                    *primColorMode);
            }
            if (processor) {
                grPaint->addColorFragmentProcessor(std::move(processor));
            }

            grPaint->setColor4f(origColor.opaque());

            // We can ignore origColor here - alpha is unchanged by gamma
            GrColor paintAlpha = SkColorAlphaToGrColor(skPaint.getColor());
            if (GrColor_WHITE != paintAlpha) {
                grPaint->addColorFragmentProcessor(GrConstColorProcessor::Make(
                    paintAlpha, GrConstColorProcessor::kModulateRGBA_InputMode));
            }
        } else {
            // No shader, no primitive color.
            grPaint->setColor4f(origColor.premul());
            applyColorFilterToPaintColor = true;
        }
    }

    SkColorFilter* colorFilter = skPaint.getColorFilter();
    if (colorFilter) {
        if (applyColorFilterToPaintColor) {
            grPaint->setColor4f(GrColor4f::FromSkColor4f(
                colorFilter->filterColor4f(origColor.toSkColor4f()))
                                    .premul());
        } else {
            sk_sp<GrFragmentProcessor> cfFP(colorFilter->asFragmentProcessor(context));
            if (cfFP) {
                grPaint->addColorFragmentProcessor(std::move(cfFP));
            } else {
                return false;
=======
///////////////////////////////////////////////////////////////////////////////

bool SkPaint2GrPaintNoShader(GrContext* context, GrRenderTarget* rt, const SkPaint& skPaint,
                             GrColor paintColor, bool constantColor, GrPaint* grPaint) {

    grPaint->setDither(skPaint.isDither());
    grPaint->setAntiAlias(skPaint.isAntiAlias());

    SkXfermode* mode = skPaint.getXfermode();
    GrXPFactory* xpFactory = NULL;
    if (!SkXfermode::AsXPFactory(mode, &xpFactory)) {
        // Fall back to src-over
        // return false here?
        xpFactory = GrPorterDuffXPFactory::Create(SkXfermode::kSrcOver_Mode);
    }
    SkASSERT(xpFactory);
    grPaint->setXPFactory(xpFactory)->unref();

    //set the color of the paint to the one of the parameter
    grPaint->setColor(paintColor);

    SkColorFilter* colorFilter = skPaint.getColorFilter();
    if (colorFilter) {
        // if the source color is a constant then apply the filter here once rather than per pixel
        // in a shader.
        if (constantColor) {
            SkColor filtered = colorFilter->filterColor(skPaint.getColor());
            grPaint->setColor(SkColor2GrColor(filtered));
        } else {
            SkTDArray<GrFragmentProcessor*> array;
            // return false if failed?
            if (colorFilter->asFragmentProcessors(context, grPaint->getProcessorDataManager(),
                                                  &array)) {
                for (int i = 0; i < array.count(); ++i) {
                    grPaint->addColorProcessor(array[i]);
                    array[i]->unref();
                }
>>>>>>> miniblink49
            }
        }
    }

<<<<<<< HEAD
    // When the xfermode is null on the SkPaint (meaning kSrcOver) we need the XPFactory field on
    // the GrPaint to also be null (also kSrcOver).
    SkASSERT(!grPaint->getXPFactory());
    SkXfermode* xfermode = skPaint.getXfermode();
    if (xfermode) {
        grPaint->setXPFactory(xfermode->asXPFactory());
    }

#ifndef SK_IGNORE_GPU_DITHER
    if (skPaint.isDither() && grPaint->numColorFragmentProcessors() > 0) {
        grPaint->addColorFragmentProcessor(GrDitherEffect::Make());
=======
#ifndef SK_IGNORE_GPU_DITHER
    // If the dither flag is set, then we need to see if the underlying context
    // supports it. If not, then install a dither effect.
    if (skPaint.isDither() && grPaint->numColorStages() > 0) {
        // What are we rendering into?
        SkASSERT(rt);

        // Suspect the dithering flag has no effect on these configs, otherwise
        // fall back on setting the appropriate state.
        if (GrPixelConfigIs8888(rt->config()) ||
            GrPixelConfigIs8888(rt->config())) {
            // The dither flag is set and the target is likely
            // not going to be dithered by the GPU.
            SkAutoTUnref<GrFragmentProcessor> fp(GrDitherEffect::Create());
            if (fp.get()) {
                grPaint->addColorProcessor(fp);
                grPaint->setDither(false);
            }
        }
>>>>>>> miniblink49
    }
#endif
    return true;
}

<<<<<<< HEAD
bool SkPaintToGrPaint(GrContext* context, const SkPaint& skPaint, const SkMatrix& viewM,
    bool allowSRGBInputs, GrPaint* grPaint)
{
    return skpaint_to_grpaint_impl(context, skPaint, viewM, nullptr, nullptr, false,
        allowSRGBInputs, grPaint);
}

/** Replaces the SkShader (if any) on skPaint with the passed in GrFragmentProcessor. */
bool SkPaintToGrPaintReplaceShader(GrContext* context,
    const SkPaint& skPaint,
    sk_sp<GrFragmentProcessor> shaderFP,
    bool allowSRGBInputs,
    GrPaint* grPaint)
{
    if (!shaderFP) {
        return false;
    }
    return skpaint_to_grpaint_impl(context, skPaint, SkMatrix::I(), &shaderFP, nullptr, false,
        allowSRGBInputs, grPaint);
}

/** Ignores the SkShader (if any) on skPaint. */
bool SkPaintToGrPaintNoShader(GrContext* context,
    const SkPaint& skPaint,
    bool allowSRGBInputs,
    GrPaint* grPaint)
{
    // Use a ptr to a nullptr to to indicate that the SkShader is ignored and not replaced.
    static sk_sp<GrFragmentProcessor> kNullShaderFP(nullptr);
    static sk_sp<GrFragmentProcessor>* kIgnoreShader = &kNullShaderFP;
    return skpaint_to_grpaint_impl(context, skPaint, SkMatrix::I(), kIgnoreShader, nullptr, false,
        allowSRGBInputs, grPaint);
}

/** Blends the SkPaint's shader (or color if no shader) with a per-primitive color which must
be setup as a vertex attribute using the specified SkXfermode::Mode. */
bool SkPaintToGrPaintWithXfermode(GrContext* context,
    const SkPaint& skPaint,
    const SkMatrix& viewM,
    SkXfermode::Mode primColorMode,
    bool primitiveIsSrc,
    bool allowSRGBInputs,
    GrPaint* grPaint)
{
    return skpaint_to_grpaint_impl(context, skPaint, viewM, nullptr, &primColorMode, primitiveIsSrc,
        allowSRGBInputs, grPaint);
}

bool SkPaintToGrPaintWithTexture(GrContext* context,
    const SkPaint& paint,
    const SkMatrix& viewM,
    sk_sp<GrFragmentProcessor> fp,
    bool textureIsAlphaOnly,
    bool allowSRGBInputs,
    GrPaint* grPaint)
{
    sk_sp<GrFragmentProcessor> shaderFP;
    if (textureIsAlphaOnly) {
        if (const SkShader* shader = paint.getShader()) {
            SkSourceGammaTreatment gammaTreatment = allowSRGBInputs
                ? SkSourceGammaTreatment::kRespect
                : SkSourceGammaTreatment::kIgnore;
            shaderFP = shader->asFragmentProcessor(context,
                viewM,
                nullptr,
                paint.getFilterQuality(),
                gammaTreatment);
            if (!shaderFP) {
                return false;
            }
            sk_sp<GrFragmentProcessor> fpSeries[] = { std::move(shaderFP), std::move(fp) };
            shaderFP = GrFragmentProcessor::RunInSeries(fpSeries, 2);
        } else {
            shaderFP = GrFragmentProcessor::MulOutputByInputUnpremulColor(fp);
        }
    } else {
        shaderFP = GrFragmentProcessor::MulOutputByInputAlpha(fp);
    }

    return SkPaintToGrPaintReplaceShader(context, paint, std::move(shaderFP), allowSRGBInputs,
        grPaint);
}

////////////////////////////////////////////////////////////////////////////////////////////////

SkImageInfo GrMakeInfoFromTexture(GrTexture* tex, int w, int h, bool isOpaque)
{
=======
bool SkPaint2GrPaint(GrContext* context, GrRenderTarget* rt, const SkPaint& skPaint,
                     const SkMatrix& viewM, bool constantColor, GrPaint* grPaint) {
    SkShader* shader = skPaint.getShader();
    if (NULL == shader) {
        return SkPaint2GrPaintNoShader(context, rt, skPaint, SkColor2GrColor(skPaint.getColor()),
                                       constantColor, grPaint);
    }

    GrColor paintColor = SkColor2GrColor(skPaint.getColor());

    // Start a new block here in order to preserve our context state after calling
    // asFragmentProcessor(). Since these calls get passed back to the client, we don't really
    // want them messing around with the context.
    {
        // Allow the shader to modify paintColor and also create an effect to be installed as
        // the first color effect on the GrPaint.
        GrFragmentProcessor* fp = NULL;
        if (!shader->asFragmentProcessor(context, skPaint, viewM, NULL, &paintColor,
                                         grPaint->getProcessorDataManager(), &fp)) {
            return false;
        }
        if (fp) {
            grPaint->addColorProcessor(fp)->unref();
            constantColor = false;
        }
    }

    // The grcolor is automatically set when calling asFragmentProcessor.
    // If the shader can be seen as an effect it returns true and adds its effect to the grpaint.
    return SkPaint2GrPaintNoShader(context, rt, skPaint, paintColor, constantColor, grPaint);
}

SkImageInfo GrMakeInfoFromTexture(GrTexture* tex, int w, int h, bool isOpaque) {
>>>>>>> miniblink49
#ifdef SK_DEBUG
    const GrSurfaceDesc& desc = tex->desc();
    SkASSERT(w <= desc.fWidth);
    SkASSERT(h <= desc.fHeight);
#endif
    const GrPixelConfig config = tex->config();
<<<<<<< HEAD
    SkColorType ct = kUnknown_SkColorType;
    SkAlphaType at = isOpaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType;
    if (!GrPixelConfigToColorAndColorSpace(config, &ct, nullptr)) {
=======
    SkColorType ct;
    SkAlphaType at = isOpaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType;
    if (!GrPixelConfig2ColorAndProfileType(config, &ct, NULL)) {
>>>>>>> miniblink49
        ct = kUnknown_SkColorType;
    }
    return SkImageInfo::Make(w, h, ct, at);
}

<<<<<<< HEAD
void GrWrapTextureInBitmap(GrTexture* src, int w, int h, bool isOpaque, SkBitmap* dst)
{
    const SkImageInfo info = GrMakeInfoFromTexture(src, w, h, isOpaque);
    dst->setInfo(info);
    dst->setPixelRef(new SkGrPixelRef(info, src))->unref();
}

GrTextureParams::FilterMode GrSkFilterQualityToGrFilterMode(SkFilterQuality paintFilterQuality,
    const SkMatrix& viewM,
    const SkMatrix& localM,
    bool* doBicubic)
{
    *doBicubic = false;
    GrTextureParams::FilterMode textureFilterMode;
    switch (paintFilterQuality) {
    case kNone_SkFilterQuality:
        textureFilterMode = GrTextureParams::kNone_FilterMode;
        break;
    case kLow_SkFilterQuality:
        textureFilterMode = GrTextureParams::kBilerp_FilterMode;
        break;
    case kMedium_SkFilterQuality: {
        SkMatrix matrix;
        matrix.setConcat(viewM, localM);
        if (matrix.getMinScale() < SK_Scalar1) {
            textureFilterMode = GrTextureParams::kMipMap_FilterMode;
        } else {
            // Don't trigger MIP level generation unnecessarily.
            textureFilterMode = GrTextureParams::kBilerp_FilterMode;
        }
        break;
    }
    case kHigh_SkFilterQuality: {
        SkMatrix matrix;
        matrix.setConcat(viewM, localM);
        *doBicubic = GrBicubicEffect::ShouldUseBicubic(matrix, &textureFilterMode);
        break;
    }
    default:
        SkErrorInternals::SetError(kInvalidPaint_SkError,
            "Sorry, I don't understand the filtering "
            "mode you asked for.  Falling back to "
            "MIPMaps.");
        textureFilterMode = GrTextureParams::kMipMap_FilterMode;
        break;
    }
    return textureFilterMode;
=======

void GrWrapTextureInBitmap(GrTexture* src, int w, int h, bool isOpaque, SkBitmap* dst) {
    const SkImageInfo info = GrMakeInfoFromTexture(src, w, h, isOpaque);
    dst->setInfo(info);
    dst->setPixelRef(SkNEW_ARGS(SkGrPixelRef, (info, src)))->unref();
>>>>>>> miniblink49
}
