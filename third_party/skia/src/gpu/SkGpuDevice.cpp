/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkGpuDevice.h"

#include "GrBlurUtils.h"
#include "GrContext.h"
<<<<<<< HEAD
#include "GrGpu.h"
#include "GrGpuResourcePriv.h"
#include "GrImageIDTextureAdjuster.h"
#include "GrLayerHoister.h"
#include "GrRecordReplaceDraw.h"
#include "GrStyle.h"
#include "GrTracing.h"
#include "SkCanvasPriv.h"
#include "SkDraw.h"
#include "SkErrorInternals.h"
#include "SkGlyphCache.h"
#include "SkGr.h"
#include "SkGrPriv.h"
#include "SkGrTexturePixelRef.h"
#include "SkImageCacherator.h"
#include "SkImageFilter.h"
#include "SkImageFilterCache.h"
#include "SkImage_Base.h"
#include "SkLayerInfo.h"
#include "SkMaskFilter.h"
#include "SkNinePatchIter.h"
=======
#include "GrDrawContext.h"
#include "GrFontScaler.h"
#include "GrGpu.h"
#include "GrGpuResourcePriv.h"
#include "GrLayerHoister.h"
#include "GrRecordReplaceDraw.h"
#include "GrStrokeInfo.h"
#include "GrTextContext.h"
#include "GrTracing.h"
#include "SkCanvasPriv.h"
#include "SkDrawProcs.h"
#include "SkErrorInternals.h"
#include "SkGlyphCache.h"
#include "SkGrTexturePixelRef.h"
#include "SkImage_Base.h"
#include "SkImageFilter.h"
#include "SkLayerInfo.h"
#include "SkMaskFilter.h"
>>>>>>> miniblink49
#include "SkPathEffect.h"
#include "SkPicture.h"
#include "SkPictureData.h"
#include "SkRRect.h"
<<<<<<< HEAD
#include "SkRasterClip.h"
=======
>>>>>>> miniblink49
#include "SkRecord.h"
#include "SkStroke.h"
#include "SkSurface.h"
#include "SkSurface_Gpu.h"
#include "SkTLazy.h"
#include "SkUtils.h"
#include "SkVertState.h"
#include "SkXfermode.h"
<<<<<<< HEAD
#include "batches/GrRectBatchFactory.h"
=======
>>>>>>> miniblink49
#include "effects/GrBicubicEffect.h"
#include "effects/GrDashingEffect.h"
#include "effects/GrSimpleTextureEffect.h"
#include "effects/GrTextureDomain.h"
<<<<<<< HEAD
#include "text/GrTextUtils.h"

#if SK_SUPPORT_GPU

#define ASSERT_SINGLE_OWNER \
    SkDEBUGCODE(GrSingleOwner::AutoEnforce debug_SingleOwner(fContext->debugSingleOwner());)

=======

#if SK_SUPPORT_GPU

>>>>>>> miniblink49
enum { kDefaultImageFilterCacheSize = 32 * 1024 * 1024 };

#if 0
    extern bool (*gShouldDrawProc)();
<<<<<<< HEAD
#define CHECK_SHOULD_DRAW(draw)                    \
    do {                                           \
        if (gShouldDrawProc && !gShouldDrawProc()) \
            return;                                \
        this->prepareDraw(draw);                   \
    } while (0)
#else
#define CHECK_SHOULD_DRAW(draw) this->prepareDraw(draw)
#endif

=======
    #define CHECK_SHOULD_DRAW(draw)                             \
        do {                                                    \
            if (gShouldDrawProc && !gShouldDrawProc()) return;  \
            this->prepareDraw(draw);                            \
        } while (0)
#else
    #define CHECK_SHOULD_DRAW(draw) this->prepareDraw(draw)
#endif

// This constant represents the screen alignment criterion in texels for
// requiring texture domain clamping to prevent color bleeding when drawing
// a sub region of a larger source image.
#define COLOR_BLEED_TOLERANCE 0.001f

#define DO_DEFERRED_CLEAR()             \
    do {                                \
        if (fNeedClear) {               \
            this->clearAll();           \
        }                               \
    } while (false)                     \

///////////////////////////////////////////////////////////////////////////////

#define CHECK_FOR_ANNOTATION(paint) \
    do { if (paint.getAnnotation()) { return; } } while (0)

>>>>>>> miniblink49
///////////////////////////////////////////////////////////////////////////////

// Helper for turning a bitmap into a texture. If the bitmap is GrTexture backed this
// just accesses the backing GrTexture. Otherwise, it creates a cached texture
// representation and releases it in the destructor.
class AutoBitmapTexture : public SkNoncopyable {
public:
<<<<<<< HEAD
    AutoBitmapTexture() { }

    AutoBitmapTexture(GrContext* context,
        const SkBitmap& bitmap,
        const GrTextureParams& params,
        SkSourceGammaTreatment gammaTreatment,
        GrTexture** texture)
    {
        SkASSERT(texture);
        *texture = this->set(context, bitmap, params, gammaTreatment);
    }

    GrTexture* set(GrContext* context,
        const SkBitmap& bitmap,
        const GrTextureParams& params,
        SkSourceGammaTreatment gammaTreatment)
    {
        // Either get the texture directly from the bitmap, or else use the cache and
        // remember to unref it.
        if (GrTexture* bmpTexture = bitmap.getTexture()) {
            fTexture.reset(nullptr);
            return bmpTexture;
        } else {
            fTexture.reset(GrRefCachedBitmapTexture(context, bitmap, params, gammaTreatment));
=======
    AutoBitmapTexture() {}

    AutoBitmapTexture(GrContext* context,
                      const SkBitmap& bitmap,
                      const GrTextureParams* params,
                      GrTexture** texture) {
        SkASSERT(texture);
        *texture = this->set(context, bitmap, params);
    }

    GrTexture* set(GrContext* context,
                   const SkBitmap& bitmap,
                   const GrTextureParams* params) {
        // Either get the texture directly from the bitmap, or else use the cache and
        // remember to unref it.
        if (GrTexture* bmpTexture = bitmap.getTexture()) {
            fTexture.reset(NULL);
            return bmpTexture;
        } else {
            fTexture.reset(GrRefCachedBitmapTexture(context, bitmap, params));
>>>>>>> miniblink49
            return fTexture.get();
        }
    }

private:
    SkAutoTUnref<GrTexture> fTexture;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
/** Checks that the alpha type is legal and gets constructor flags. Returns false if device creation
    should fail. */
bool SkGpuDevice::CheckAlphaTypeAndGetFlags(
    const SkImageInfo* info, SkGpuDevice::InitContents init, unsigned* flags)
{
    *flags = 0;
    if (info) {
        switch (info->alphaType()) {
        case kPremul_SkAlphaType:
            break;
        case kOpaque_SkAlphaType:
            *flags |= SkGpuDevice::kIsOpaque_Flag;
            break;
        default: // If it is unpremul or unknown don't try to render
            return false;
=======
struct GrSkDrawProcs : public SkDrawProcs {
public:
    GrContext* fContext;
    GrTextContext* fTextContext;
    GrFontScaler* fFontScaler;  // cached in the skia glyphcache
};

///////////////////////////////////////////////////////////////////////////////

/** Checks that the alpha type is legal and gets constructor flags. Returns false if device creation
    should fail. */
bool SkGpuDevice::CheckAlphaTypeAndGetFlags(
                        const SkImageInfo* info, SkGpuDevice::InitContents init, unsigned* flags) {
    *flags = 0;
    if (info) {
        switch (info->alphaType()) {
            case kPremul_SkAlphaType:
                break;
            case kOpaque_SkAlphaType:
                *flags |= SkGpuDevice::kIsOpaque_Flag;
                break;
            default: // If it is unpremul or unknown don't try to render
                return false;
>>>>>>> miniblink49
        }
    }
    if (kClear_InitContents == init) {
        *flags |= kNeedClear_Flag;
    }
    return true;
}

<<<<<<< HEAD
sk_sp<SkGpuDevice> SkGpuDevice::Make(sk_sp<GrRenderTarget> rt, const SkSurfaceProps* props,
    InitContents init)
{
    if (!rt || rt->wasDestroyed() || !rt->getContext()) {
        return nullptr;
    }
    unsigned flags;
    if (!CheckAlphaTypeAndGetFlags(nullptr, init, &flags)) {
        return nullptr;
    }

    const int width = rt->width();
    const int height = rt->height();

    GrContext* context = rt->getContext();

    sk_sp<GrDrawContext> drawContext(context->drawContext(std::move(rt), props));
    return sk_sp<SkGpuDevice>(new SkGpuDevice(std::move(drawContext), width, height, flags));
}

sk_sp<SkBaseDevice> SkGpuDevice::Make(sk_sp<GrDrawContext> drawContext,
    int width, int height,
    InitContents init)
{
    if (!drawContext || drawContext->wasAbandoned()) {
        return nullptr;
    }
    unsigned flags;
    if (!CheckAlphaTypeAndGetFlags(nullptr, init, &flags)) {
        return nullptr;
    }
    return sk_sp<SkBaseDevice>(new SkGpuDevice(std::move(drawContext), width, height, flags));
}

sk_sp<SkGpuDevice> SkGpuDevice::Make(GrContext* context, SkBudgeted budgeted,
    const SkImageInfo& info, int sampleCount,
    const SkSurfaceProps* props, InitContents init)
{
    unsigned flags;
    if (!CheckAlphaTypeAndGetFlags(&info, init, &flags)) {
        return nullptr;
    }

    sk_sp<GrDrawContext> drawContext(CreateDrawContext(context, budgeted, info,
        sampleCount, props));
    if (!drawContext) {
        return nullptr;
    }

    return sk_sp<SkGpuDevice>(new SkGpuDevice(std::move(drawContext),
        info.width(), info.height(), flags));
}

SkGpuDevice::SkGpuDevice(sk_sp<GrDrawContext> drawContext, int width, int height, unsigned flags)
    : INHERITED(drawContext->surfaceProps())
    , fContext(SkRef(drawContext->accessRenderTarget()->getContext()))
    , fRenderTarget(drawContext->renderTarget())
    , fDrawContext(std::move(drawContext))
{
    fOpaque = SkToBool(flags & kIsOpaque_Flag);

    SkAlphaType at = fOpaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType;
    SkImageInfo info = fRenderTarget->surfacePriv().info(at).makeWH(width, height);
    SkPixelRef* pr = new SkGrPixelRef(info, fRenderTarget.get());
    fLegacyBitmap.setInfo(info);
    fLegacyBitmap.setPixelRef(pr)->unref();

    if (flags & kNeedClear_Flag) {
        this->clearAll();
    }
}

sk_sp<GrDrawContext> SkGpuDevice::CreateDrawContext(GrContext* context,
    SkBudgeted budgeted,
    const SkImageInfo& origInfo,
    int sampleCount,
    const SkSurfaceProps* surfaceProps)
{
    if (kUnknown_SkColorType == origInfo.colorType() || origInfo.width() < 0 || origInfo.height() < 0) {
        return nullptr;
    }

    if (!context) {
        return nullptr;
=======
SkGpuDevice* SkGpuDevice::Create(GrRenderTarget* rt, const SkSurfaceProps* props,
                                 InitContents init) {
    return SkGpuDevice::Create(rt, rt->width(), rt->height(), props, init);
}

SkGpuDevice* SkGpuDevice::Create(GrRenderTarget* rt, int width, int height,
                                 const SkSurfaceProps* props, InitContents init) {
    if (!rt || rt->wasDestroyed()) {
        return NULL;
    }
    unsigned flags;
    if (!CheckAlphaTypeAndGetFlags(NULL, init, &flags)) {
        return NULL;
    }
    return SkNEW_ARGS(SkGpuDevice, (rt, width, height, props, flags));
}

SkGpuDevice* SkGpuDevice::Create(GrContext* context, SkSurface::Budgeted budgeted,
                                 const SkImageInfo& info, int sampleCount,
                                 const SkSurfaceProps* props, InitContents init) {
    unsigned flags;
    if (!CheckAlphaTypeAndGetFlags(&info, init, &flags)) {
        return NULL;
    }

    SkAutoTUnref<GrRenderTarget> rt(CreateRenderTarget(context, budgeted, info,  sampleCount));
    if (NULL == rt) {
        return NULL;
    }

    return SkNEW_ARGS(SkGpuDevice, (rt, info.width(), info.height(), props, flags));
}

SkGpuDevice::SkGpuDevice(GrRenderTarget* rt, int width, int height,
                         const SkSurfaceProps* props, unsigned flags)
    : INHERITED(SkSurfacePropsCopyOrDefault(props))
{
    fDrawProcs = NULL;

    fContext = SkRef(rt->getContext());
    fNeedClear = SkToBool(flags & kNeedClear_Flag);
    fOpaque = SkToBool(flags & kIsOpaque_Flag);

    fRenderTarget = SkRef(rt);

    SkAlphaType at = fOpaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType;
    SkImageInfo info = rt->surfacePriv().info(at).makeWH(width, height);
    SkPixelRef* pr = SkNEW_ARGS(SkGrPixelRef, (info, rt));
    fLegacyBitmap.setInfo(info);
    fLegacyBitmap.setPixelRef(pr)->unref();

    fDrawContext.reset(SkRef(fContext->drawContext(&this->surfaceProps())));
}

GrRenderTarget* SkGpuDevice::CreateRenderTarget(GrContext* context, SkSurface::Budgeted budgeted,
                                                const SkImageInfo& origInfo, int sampleCount) {
    if (kUnknown_SkColorType == origInfo.colorType() ||
        origInfo.width() < 0 || origInfo.height() < 0) {
        return NULL;
    }

    if (!context) {
        return NULL;
>>>>>>> miniblink49
    }

    SkColorType ct = origInfo.colorType();
    SkAlphaType at = origInfo.alphaType();
<<<<<<< HEAD
    SkColorSpace* cs = origInfo.colorSpace();
    if (kRGB_565_SkColorType == ct || kGray_8_SkColorType == ct) {
        at = kOpaque_SkAlphaType; // force this setting
    }
    if (kOpaque_SkAlphaType != at) {
        at = kPremul_SkAlphaType; // force this setting
    }

    GrPixelConfig origConfig = SkImageInfo2GrPixelConfig(ct, at, cs, *context->caps());
    if (!context->caps()->isConfigRenderable(origConfig, sampleCount > 0)) {
        // Fall back from whatever ct was to default of kRGBA or kBGRA which is aliased as kN32
        ct = kN32_SkColorType;
    }

    GrPixelConfig config = SkImageInfo2GrPixelConfig(ct, at, cs, *context->caps());

    return context->newDrawContext(SkBackingFit::kExact, // Why exact?
        origInfo.width(), origInfo.height(),
        config, sampleCount,
        kDefault_GrSurfaceOrigin, surfaceProps, budgeted);
}

// This method ensures that we always have a texture-backed "bitmap" when we finally
// call through to the base impl so that the image filtering code will take the
// gpu-specific paths. This mirrors SkCanvas::internalDrawDevice (the other
// use of SkImageFilter::filterImage) in that the source and dest will have
// homogenous backing (e.g., raster or gpu).
void SkGpuDevice::drawSpriteWithFilter(const SkDraw& draw, const SkBitmap& bitmap,
    int x, int y, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawSpriteWithFilter", fContext);

    if (fContext->abandoned()) {
        return;
    }

    if (bitmap.getTexture()) {
        INHERITED::drawSpriteWithFilter(draw, bitmap, x, y, paint);
        return;
    }

    SkAutoLockPixels alp(bitmap, !bitmap.getTexture());
    if (!bitmap.getTexture() && !bitmap.readyToDraw()) {
        return;
    }

    GrTexture* texture;
    // draw sprite neither filters nor tiles.
    AutoBitmapTexture abt(fContext, bitmap, GrTextureParams::ClampNoFilter(),
        SkSourceGammaTreatment::kRespect, &texture);
    if (!texture) {
        return;
    }

    SkBitmap newBitmap;

    GrWrapTextureInBitmap(texture, texture->width(), texture->height(),
        bitmap.isOpaque(), &newBitmap);

    INHERITED::drawSpriteWithFilter(draw, newBitmap, x, y, paint);
=======
    if (kRGB_565_SkColorType == ct) {
        at = kOpaque_SkAlphaType;  // force this setting
    } else if (ct != kBGRA_8888_SkColorType && ct != kRGBA_8888_SkColorType) {
        // Fall back from whatever ct was to default of kRGBA or kBGRA which is aliased as kN32
        ct = kN32_SkColorType;
    }
    if (kOpaque_SkAlphaType != at) {
        at = kPremul_SkAlphaType;  // force this setting
    }
    const SkImageInfo info = SkImageInfo::Make(origInfo.width(), origInfo.height(), ct, at);

    GrSurfaceDesc desc;
    desc.fFlags = kRenderTarget_GrSurfaceFlag;
    desc.fWidth = info.width();
    desc.fHeight = info.height();
    desc.fConfig = SkImageInfo2GrPixelConfig(info);
    desc.fSampleCnt = sampleCount;
    GrTexture* texture = context->textureProvider()->createTexture(
        desc, SkToBool(budgeted), NULL, 0);
    if (NULL == texture) {
        return NULL;
    }
    SkASSERT(NULL != texture->asRenderTarget());
    return texture->asRenderTarget();
}

SkGpuDevice::~SkGpuDevice() {
    if (fDrawProcs) {
        delete fDrawProcs;
    }

    fRenderTarget->unref();
    fContext->unref();
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

bool SkGpuDevice::onReadPixels(const SkImageInfo& dstInfo, void* dstPixels, size_t dstRowBytes,
<<<<<<< HEAD
    int x, int y)
{
    ASSERT_SINGLE_OWNER

    // TODO: teach fRenderTarget to take ImageInfo directly to specify the src pixels
    GrPixelConfig config = SkImageInfo2GrPixelConfig(dstInfo, *fContext->caps());
=======
                               int x, int y) {
    DO_DEFERRED_CLEAR();

    // TODO: teach fRenderTarget to take ImageInfo directly to specify the src pixels
    GrPixelConfig config = SkImageInfo2GrPixelConfig(dstInfo);
>>>>>>> miniblink49
    if (kUnknown_GrPixelConfig == config) {
        return false;
    }

    uint32_t flags = 0;
    if (kUnpremul_SkAlphaType == dstInfo.alphaType()) {
        flags = GrContext::kUnpremul_PixelOpsFlag;
    }
    return fRenderTarget->readPixels(x, y, dstInfo.width(), dstInfo.height(), config, dstPixels,
<<<<<<< HEAD
        dstRowBytes, flags);
}

bool SkGpuDevice::onWritePixels(const SkImageInfo& info, const void* pixels, size_t rowBytes,
    int x, int y)
{
    ASSERT_SINGLE_OWNER
    // TODO: teach fRenderTarget to take ImageInfo directly to specify the src pixels
    GrPixelConfig config = SkImageInfo2GrPixelConfig(info, *fContext->caps());
=======
                                     dstRowBytes, flags);
}

bool SkGpuDevice::onWritePixels(const SkImageInfo& info, const void* pixels, size_t rowBytes,
                                int x, int y) {
    // TODO: teach fRenderTarget to take ImageInfo directly to specify the src pixels
    GrPixelConfig config = SkImageInfo2GrPixelConfig(info);
>>>>>>> miniblink49
    if (kUnknown_GrPixelConfig == config) {
        return false;
    }
    uint32_t flags = 0;
    if (kUnpremul_SkAlphaType == info.alphaType()) {
        flags = GrContext::kUnpremul_PixelOpsFlag;
    }
    fRenderTarget->writePixels(x, y, info.width(), info.height(), config, pixels, rowBytes, flags);

    // need to bump our genID for compatibility with clients that "know" we have a bitmap
    fLegacyBitmap.notifyPixelsChanged();

    return true;
}

<<<<<<< HEAD
const SkBitmap& SkGpuDevice::onAccessBitmap()
{
    ASSERT_SINGLE_OWNER
    return fLegacyBitmap;
}

bool SkGpuDevice::onAccessPixels(SkPixmap* pmap)
{
    ASSERT_SINGLE_OWNER
=======
const SkBitmap& SkGpuDevice::onAccessBitmap() {
    DO_DEFERRED_CLEAR();
    return fLegacyBitmap;
}

bool SkGpuDevice::onAccessPixels(SkPixmap* pmap) {
    DO_DEFERRED_CLEAR();
>>>>>>> miniblink49
    // For compatibility with clients the know we're backed w/ a bitmap, and want to inspect its
    // genID. When we can hide/remove that fact, we can eliminate this call to notify.
    // ... ugh.
    fLegacyBitmap.notifyPixelsChanged();
    return false;
}

<<<<<<< HEAD
void SkGpuDevice::onAttachToCanvas(SkCanvas* canvas)
{
    ASSERT_SINGLE_OWNER
=======
void SkGpuDevice::onAttachToCanvas(SkCanvas* canvas) {
>>>>>>> miniblink49
    INHERITED::onAttachToCanvas(canvas);

    // Canvas promises that this ptr is valid until onDetachFromCanvas is called
    fClipStack.reset(SkRef(canvas->getClipStack()));
}

<<<<<<< HEAD
void SkGpuDevice::onDetachFromCanvas()
{
    ASSERT_SINGLE_OWNER
    INHERITED::onDetachFromCanvas();
    fClip.reset();
    fClipStack.reset(nullptr);
=======
void SkGpuDevice::onDetachFromCanvas() {
    INHERITED::onDetachFromCanvas();
    fClip.reset();
    fClipStack.reset(NULL);
>>>>>>> miniblink49
}

// call this every draw call, to ensure that the context reflects our state,
// and not the state from some other canvas/device
<<<<<<< HEAD
void SkGpuDevice::prepareDraw(const SkDraw& draw)
{
    ASSERT_SINGLE_OWNER
=======
void SkGpuDevice::prepareDraw(const SkDraw& draw) {
>>>>>>> miniblink49
    SkASSERT(fClipStack.get());

    SkASSERT(draw.fClipStack && draw.fClipStack == fClipStack);

<<<<<<< HEAD
    fClip.reset(fClipStack, &this->getOrigin());
}

GrRenderTarget* SkGpuDevice::accessRenderTarget()
{
    ASSERT_SINGLE_OWNER
    return fRenderTarget.get();
}

GrDrawContext* SkGpuDevice::accessDrawContext()
{
    ASSERT_SINGLE_OWNER
    return fDrawContext.get();
}

void SkGpuDevice::clearAll()
{
    ASSERT_SINGLE_OWNER
    GrColor color = 0;
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "clearAll", fContext);
    SkIRect rect = SkIRect::MakeWH(this->width(), this->height());
    fDrawContext->clear(&rect, color, true);
}

void SkGpuDevice::replaceDrawContext(bool shouldRetainContent)
{
    ASSERT_SINGLE_OWNER

    SkBudgeted budgeted = fRenderTarget->resourcePriv().isBudgeted();

    sk_sp<GrDrawContext> newDC(CreateDrawContext(this->context(),
        budgeted,
        this->imageInfo(),
        fDrawContext->numColorSamples(),
        &this->surfaceProps()));
    if (!newDC) {
=======
    fClip.setClipStack(fClipStack, &this->getOrigin());

    DO_DEFERRED_CLEAR();
}

GrRenderTarget* SkGpuDevice::accessRenderTarget() {
    DO_DEFERRED_CLEAR();
    return fRenderTarget;
}

void SkGpuDevice::clearAll() {
    GrColor color = 0;
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::clearAll", fContext);
    SkIRect rect = SkIRect::MakeWH(this->width(), this->height());
    fDrawContext->clear(fRenderTarget, &rect, color, true);
    fNeedClear = false;
}

void SkGpuDevice::replaceRenderTarget(bool shouldRetainContent) {
    // Caller must have accessed the render target, because it knows the rt must be replaced.
    SkASSERT(!fNeedClear);

    SkSurface::Budgeted budgeted =
            fRenderTarget->resourcePriv().isBudgeted() ? SkSurface::kYes_Budgeted
                                                       : SkSurface::kNo_Budgeted;

    SkAutoTUnref<GrRenderTarget> newRT(CreateRenderTarget(
        fRenderTarget->getContext(), budgeted, this->imageInfo(), fRenderTarget->desc().fSampleCnt));

    if (NULL == newRT) {
>>>>>>> miniblink49
        return;
    }

    if (shouldRetainContent) {
        if (fRenderTarget->wasDestroyed()) {
            return;
        }
<<<<<<< HEAD
        newDC->copySurface(fDrawContext->asTexture().get(),
            SkIRect::MakeWH(this->width(), this->height()),
            SkIPoint::Make(0, 0));
    }

    SkASSERT(fDrawContext->accessRenderTarget() != newDC->accessRenderTarget());

    fRenderTarget = newDC->renderTarget();

#ifdef SK_DEBUG
    SkImageInfo info = fRenderTarget->surfacePriv().info(fOpaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType);
    SkASSERT(info == fLegacyBitmap.info());
#endif
    SkPixelRef* pr = new SkGrPixelRef(fLegacyBitmap.info(), fRenderTarget.get());
    fLegacyBitmap.setPixelRef(pr)->unref();

    fDrawContext = newDC;
=======
        this->context()->copySurface(newRT, fRenderTarget);
    }

    SkASSERT(fRenderTarget != newRT);

    fRenderTarget->unref();
    fRenderTarget = newRT.detach();

#ifdef SK_DEBUG
    SkImageInfo info = fRenderTarget->surfacePriv().info(fOpaque ? kOpaque_SkAlphaType :
                                                                   kPremul_SkAlphaType);
    SkASSERT(info == fLegacyBitmap.info());
#endif
    SkPixelRef* pr = SkNEW_ARGS(SkGrPixelRef, (fLegacyBitmap.info(), fRenderTarget));
    fLegacyBitmap.setPixelRef(pr)->unref();

    fDrawContext.reset(SkRef(fRenderTarget->getContext()->drawContext(&this->surfaceProps())));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkGpuDevice::drawPaint(const SkDraw& draw, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    CHECK_SHOULD_DRAW(draw);
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawPaint", fContext);

    GrPaint grPaint;
    if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
        return;
    }

    fDrawContext->drawPaint(fClip, grPaint, *draw.fMatrix);
=======
void SkGpuDevice::drawPaint(const SkDraw& draw, const SkPaint& paint) {
    CHECK_SHOULD_DRAW(draw);
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawPaint", fContext);

    GrPaint grPaint;
    if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix, true, &grPaint)) {
        return;
    }

    fDrawContext->drawPaint(fRenderTarget, fClip, grPaint, *draw.fMatrix);
>>>>>>> miniblink49
}

// must be in SkCanvas::PointMode order
static const GrPrimitiveType gPointMode2PrimtiveType[] = {
    kPoints_GrPrimitiveType,
    kLines_GrPrimitiveType,
    kLineStrip_GrPrimitiveType
};

<<<<<<< HEAD
// suppress antialiasing on axis-aligned integer-coordinate lines
static bool needs_antialiasing(SkCanvas::PointMode mode, size_t count, const SkPoint pts[])
{
    if (mode == SkCanvas::PointMode::kPoints_PointMode) {
        return false;
    }
    if (count == 2) {
        // We do not antialias as long as the primary axis of the line is integer-aligned, even if
        // the other coordinates are not. This does mean the two end pixels of the line will be
        // sharp even when they shouldn't be, but turning antialiasing on (as things stand
        // currently) means that the line will turn into a two-pixel-wide blur. While obviously a
        // more complete fix is possible down the road, for the time being we accept the error on
        // the two end pixels as being the lesser of two evils.
        if (pts[0].fX == pts[1].fX) {
            return ((int)pts[0].fX) != pts[0].fX;
        }
        if (pts[0].fY == pts[1].fY) {
            return ((int)pts[0].fY) != pts[0].fY;
        }
    }
    return true;
}

void SkGpuDevice::drawPoints(const SkDraw& draw, SkCanvas::PointMode mode,
    size_t count, const SkPoint pts[], const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawPoints", fContext);
=======
void SkGpuDevice::drawPoints(const SkDraw& draw, SkCanvas::PointMode mode,
                             size_t count, const SkPoint pts[], const SkPaint& paint) {
    CHECK_FOR_ANNOTATION(paint);
>>>>>>> miniblink49
    CHECK_SHOULD_DRAW(draw);

    SkScalar width = paint.getStrokeWidth();
    if (width < 0) {
        return;
    }

    if (paint.getPathEffect() && 2 == count && SkCanvas::kLines_PointMode == mode) {
<<<<<<< HEAD
        GrStyle style(paint, SkPaint::kStroke_Style);
        GrPaint grPaint;
        if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
                this->surfaceProps().isGammaCorrect(), &grPaint)) {
=======
        GrStrokeInfo strokeInfo(paint, SkPaint::kStroke_Style);
        GrPaint grPaint;
        if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix, true,
                             &grPaint)) {
>>>>>>> miniblink49
            return;
        }
        SkPath path;
        path.setIsVolatile(true);
        path.moveTo(pts[0]);
        path.lineTo(pts[1]);
<<<<<<< HEAD
        fDrawContext->drawPath(fClip, grPaint, *draw.fMatrix, path, style);
        return;
    }

    // we only handle non-antialiased hairlines and paints without path effects or mask filters,
    // else we let the SkDraw call our drawPath()
    if (width > 0 || paint.getPathEffect() || paint.getMaskFilter() || (paint.isAntiAlias() && needs_antialiasing(mode, count, pts))) {
=======
        fDrawContext->drawPath(fRenderTarget, fClip, grPaint, *draw.fMatrix, path, strokeInfo);
        return;
    }

    // we only handle hairlines and paints without path effects or mask filters,
    // else we let the SkDraw call our drawPath()
    if (width > 0 || paint.getPathEffect() || paint.getMaskFilter()) {
>>>>>>> miniblink49
        draw.drawPoints(mode, count, pts, paint, true);
        return;
    }

    GrPaint grPaint;
<<<<<<< HEAD
    if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
        return;
    }

    fDrawContext->drawVertices(fClip,
        grPaint,
        *draw.fMatrix,
        gPointMode2PrimtiveType[mode],
        SkToS32(count),
        (SkPoint*)pts,
        nullptr,
        nullptr,
        nullptr,
        0);
=======
    if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix, true, &grPaint)) {
        return;
    }

    fDrawContext->drawVertices(fRenderTarget,
                               fClip,
                               grPaint,
                               *draw.fMatrix,
                               gPointMode2PrimtiveType[mode],
                               SkToS32(count),
                               (SkPoint*)pts,
                               NULL,
                               NULL,
                               NULL,
                               0);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkGpuDevice::drawRect(const SkDraw& draw, const SkRect& rect, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawRect", fContext);
=======
void SkGpuDevice::drawRect(const SkDraw& draw, const SkRect& rect,
                           const SkPaint& paint) {
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawRect", fContext);

    CHECK_FOR_ANNOTATION(paint);
>>>>>>> miniblink49
    CHECK_SHOULD_DRAW(draw);

    bool doStroke = paint.getStyle() != SkPaint::kFill_Style;
    SkScalar width = paint.getStrokeWidth();

    /*
        We have special code for hairline strokes, miter-strokes, bevel-stroke
        and fills. Anything else we just call our path code.
     */
<<<<<<< HEAD
    bool usePath = doStroke && width > 0 && (paint.getStrokeJoin() == SkPaint::kRound_Join || (paint.getStrokeJoin() == SkPaint::kBevel_Join && rect.isEmpty()));

    // a few other reasons we might need to call drawPath...
    if (paint.getMaskFilter() || paint.getPathEffect() || paint.getStyle() == SkPaint::kStrokeAndFill_Style) { // we can't both stroke and fill rects
=======
    bool usePath = doStroke && width > 0 &&
                   (paint.getStrokeJoin() == SkPaint::kRound_Join ||
                    (paint.getStrokeJoin() == SkPaint::kBevel_Join && rect.isEmpty()));
    // another two reasons we might need to call drawPath...

    if (paint.getMaskFilter()) {
        usePath = true;
    }

    if (!usePath && paint.isAntiAlias() && !draw.fMatrix->rectStaysRect()) {
#if defined(SHADER_AA_FILL_RECT) || !defined(IGNORE_ROT_AA_RECT_OPT)
        if (doStroke) {
#endif
            usePath = true;
#if defined(SHADER_AA_FILL_RECT) || !defined(IGNORE_ROT_AA_RECT_OPT)
        } else {
            usePath = !draw.fMatrix->preservesRightAngles();
        }
#endif
    }
    // until we can both stroke and fill rectangles
    if (paint.getStyle() == SkPaint::kStrokeAndFill_Style) {
        usePath = true;
    }

    GrStrokeInfo strokeInfo(paint);

    const SkPathEffect* pe = paint.getPathEffect();
    if (!usePath && pe && !strokeInfo.isDashed()) {
>>>>>>> miniblink49
        usePath = true;
    }

    if (usePath) {
        SkPath path;
        path.setIsVolatile(true);
        path.addRect(rect);
<<<<<<< HEAD
        GrBlurUtils::drawPathWithMaskFilter(fContext, fDrawContext.get(),
            fClip, path, paint,
            *draw.fMatrix, nullptr,
            draw.fRC->getBounds(), true);
=======
        this->drawPath(draw, path, paint, NULL, true);
>>>>>>> miniblink49
        return;
    }

    GrPaint grPaint;
<<<<<<< HEAD
    if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
        return;
    }

    GrStyle style(paint);
    fDrawContext->drawRect(fClip, grPaint, *draw.fMatrix, rect, &style);
=======
    if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix, true, &grPaint)) {
        return;
    }

    fDrawContext->drawRect(fRenderTarget, fClip, grPaint, *draw.fMatrix, rect, &strokeInfo);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

void SkGpuDevice::drawRRect(const SkDraw& draw, const SkRRect& rect,
<<<<<<< HEAD
    const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawRRect", fContext);
    CHECK_SHOULD_DRAW(draw);

    GrPaint grPaint;
    if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
        return;
    }

    GrStyle style(paint);
=======
                            const SkPaint& paint) {
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawRRect", fContext);
    CHECK_FOR_ANNOTATION(paint);
    CHECK_SHOULD_DRAW(draw);

    GrPaint grPaint;
    if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix, true, &grPaint)) {
        return;
    }

    GrStrokeInfo strokeInfo(paint);
>>>>>>> miniblink49
    if (paint.getMaskFilter()) {
        // try to hit the fast path for drawing filtered round rects

        SkRRect devRRect;
        if (rect.transform(*draw.fMatrix, &devRRect)) {
            if (devRRect.allCornersCircular()) {
                SkRect maskRect;
<<<<<<< HEAD
                if (paint.getMaskFilter()->canFilterMaskGPU(devRRect,
                        draw.fRC->getBounds(),
                        *draw.fMatrix,
                        &maskRect)) {
                    SkIRect finalIRect;
                    maskRect.roundOut(&finalIRect);
                    if (draw.fRC->quickReject(finalIRect)) {
                        // clipped out
                        return;
                    }
                    if (paint.getMaskFilter()->directFilterRRectMaskGPU(fContext->textureProvider(),
                            fDrawContext.get(),
                            &grPaint,
                            fClip,
                            *draw.fMatrix,
                            style.strokeRec(),
                            devRRect)) {
                        return;
                    }
                }
            }
        }
    }

    if (paint.getMaskFilter() || style.pathEffect()) {
        // The only mask filter the native rrect drawing code could've handle was taken
        // care of above.
        // A path effect will presumably transform this rrect into something else.
        SkPath path;
        path.setIsVolatile(true);
        path.addRRect(rect);
        GrBlurUtils::drawPathWithMaskFilter(fContext, fDrawContext.get(),
            fClip, path, paint,
            *draw.fMatrix, nullptr,
            draw.fRC->getBounds(), true);
        return;
    }

    SkASSERT(!style.pathEffect());

    fDrawContext->drawRRect(fClip, grPaint, *draw.fMatrix, rect, style);
}

void SkGpuDevice::drawDRRect(const SkDraw& draw, const SkRRect& outer,
    const SkRRect& inner, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawDRRect", fContext);
    CHECK_SHOULD_DRAW(draw);

    if (outer.isEmpty()) {
        return;
    }

    if (inner.isEmpty()) {
        return this->drawRRect(draw, outer, paint);
    }

    SkStrokeRec stroke(paint);

    if (stroke.isFillStyle() && !paint.getMaskFilter() && !paint.getPathEffect()) {
        GrPaint grPaint;
        if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
                this->surfaceProps().isGammaCorrect(), &grPaint)) {
            return;
        }

        fDrawContext->drawDRRect(fClip, grPaint, *draw.fMatrix, outer, inner);
        return;
=======
                if (paint.getMaskFilter()->canFilterMaskGPU(devRRect.rect(),
                                                            draw.fClip->getBounds(),
                                                            *draw.fMatrix,
                                                            &maskRect)) {
                    SkIRect finalIRect;
                    maskRect.roundOut(&finalIRect);
                    if (draw.fClip->quickReject(finalIRect)) {
                        // clipped out
                        return;
                    }
                    if (paint.getMaskFilter()->directFilterRRectMaskGPU(fContext,
                                                                        fRenderTarget,
                                                                        &grPaint,
                                                                        fClip,
                                                                        *draw.fMatrix,
                                                                        strokeInfo,
                                                                        devRRect)) {
                        return;
                    }
                }

            }
        }

    }

    bool usePath = false;

    if (paint.getMaskFilter()) {
        usePath = true;
    } else {
        const SkPathEffect* pe = paint.getPathEffect();
        if (pe && !strokeInfo.isDashed()) {
            usePath = true;
        }
    }


    if (usePath) {
        SkPath path;
        path.setIsVolatile(true);
        path.addRRect(rect);
        this->drawPath(draw, path, paint, NULL, true);
        return;
    }

    fDrawContext->drawRRect(fRenderTarget, fClip, grPaint, *draw.fMatrix, rect, strokeInfo);
}

void SkGpuDevice::drawDRRect(const SkDraw& draw, const SkRRect& outer,
                             const SkRRect& inner, const SkPaint& paint) {
    SkStrokeRec stroke(paint);
    if (stroke.isFillStyle()) {

        CHECK_FOR_ANNOTATION(paint);
        CHECK_SHOULD_DRAW(draw);

        GrPaint grPaint;
        if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix, true,
                             &grPaint)) {
            return;
        }

        if (NULL == paint.getMaskFilter() && NULL == paint.getPathEffect()) {
            fDrawContext->drawDRRect(fRenderTarget, fClip, grPaint, *draw.fMatrix, outer, inner);
            return;
        }
>>>>>>> miniblink49
    }

    SkPath path;
    path.setIsVolatile(true);
    path.addRRect(outer);
    path.addRRect(inner);
    path.setFillType(SkPath::kEvenOdd_FillType);

<<<<<<< HEAD
    GrBlurUtils::drawPathWithMaskFilter(fContext, fDrawContext.get(),
        fClip, path, paint,
        *draw.fMatrix, nullptr,
        draw.fRC->getBounds(), true);
}

/////////////////////////////////////////////////////////////////////////////

void SkGpuDevice::drawOval(const SkDraw& draw, const SkRect& oval, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawOval", fContext);
    CHECK_SHOULD_DRAW(draw);

    // Presumably the path effect warps this to something other than an oval
    if (paint.getPathEffect()) {
        SkPath path;
        path.setIsVolatile(true);
        path.addOval(oval);
        this->drawPath(draw, path, paint, nullptr, true);
        return;
    }

    if (paint.getMaskFilter()) {
        // The RRect path can handle special case blurring
        SkRRect rr = SkRRect::MakeOval(oval);
        return this->drawRRect(draw, rr, paint);
    }

    GrPaint grPaint;
    if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
        return;
    }

    fDrawContext->drawOval(fClip, grPaint, *draw.fMatrix, oval, GrStyle(paint));
=======
    this->drawPath(draw, path, paint, NULL, true);
}


/////////////////////////////////////////////////////////////////////////////

void SkGpuDevice::drawOval(const SkDraw& draw, const SkRect& oval,
                           const SkPaint& paint) {
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawOval", fContext);
    CHECK_FOR_ANNOTATION(paint);
    CHECK_SHOULD_DRAW(draw);

    GrStrokeInfo strokeInfo(paint);

    bool usePath = false;
    // some basic reasons we might need to call drawPath...
    if (paint.getMaskFilter()) {
        usePath = true;
    } else {
        const SkPathEffect* pe = paint.getPathEffect();
        if (pe && !strokeInfo.isDashed()) {
            usePath = true;
        }
    }

    if (usePath) {
        SkPath path;
        path.setIsVolatile(true);
        path.addOval(oval);
        this->drawPath(draw, path, paint, NULL, true);
        return;
    }

    GrPaint grPaint;
    if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix, true, &grPaint)) {
        return;
    }

    fDrawContext->drawOval(fRenderTarget, fClip, grPaint, *draw.fMatrix, oval, strokeInfo);
>>>>>>> miniblink49
}

#include "SkMaskFilter.h"

///////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
void SkGpuDevice::drawStrokedLine(const SkPoint points[2],
    const SkDraw& draw,
    const SkPaint& origPaint)
{
    ASSERT_SINGLE_OWNER
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawStrokedLine", fContext);
    CHECK_SHOULD_DRAW(draw);

    // Adding support for round capping would require a GrDrawContext::fillRRectWithLocalMatrix
    // entry point
    SkASSERT(SkPaint::kRound_Cap != origPaint.getStrokeCap());
    SkASSERT(SkPaint::kStroke_Style == origPaint.getStyle());
    SkASSERT(!origPaint.getPathEffect());
    SkASSERT(!origPaint.getMaskFilter());

    const SkScalar halfWidth = 0.5f * origPaint.getStrokeWidth();
    SkASSERT(halfWidth > 0);

    SkVector v = points[1] - points[0];

    SkScalar length = SkPoint::Normalize(&v);
    if (!length) {
        v.fX = 1.0f;
        v.fY = 0.0f;
    }

    SkPaint newPaint(origPaint);
    newPaint.setStyle(SkPaint::kFill_Style);

    SkScalar xtraLength = 0.0f;
    if (SkPaint::kButt_Cap != origPaint.getStrokeCap()) {
        xtraLength = halfWidth;
    }

    SkPoint mid = points[0] + points[1];
    mid.scale(0.5f);

    SkRect rect = SkRect::MakeLTRB(mid.fX - halfWidth, mid.fY - 0.5f * length - xtraLength,
        mid.fX + halfWidth, mid.fY + 0.5f * length + xtraLength);
    SkMatrix m;
    m.setSinCos(v.fX, -v.fY, mid.fX, mid.fY);

    SkMatrix local = m;

    m.postConcat(*draw.fMatrix);

    GrPaint grPaint;
    if (!SkPaintToGrPaint(this->context(), newPaint, m,
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
        return;
    }

    fDrawContext->fillRectWithLocalMatrix(fClip, grPaint, m, rect, local);
}

void SkGpuDevice::drawPath(const SkDraw& draw, const SkPath& origSrcPath,
    const SkPaint& paint, const SkMatrix* prePathMatrix,
    bool pathIsMutable)
{
    ASSERT_SINGLE_OWNER
    if (!origSrcPath.isInverseFillType() && !paint.getPathEffect() && !prePathMatrix) {
        SkPoint points[2];
        if (SkPaint::kStroke_Style == paint.getStyle() && paint.getStrokeWidth() > 0 && !paint.getMaskFilter() && SkPaint::kRound_Cap != paint.getStrokeCap() && draw.fMatrix->preservesRightAngles() && origSrcPath.isLine(points)) {
            // Path-based stroking looks better for thin rects
            SkScalar strokeWidth = draw.fMatrix->getMaxScale() * paint.getStrokeWidth();
            if (strokeWidth >= 1.0f) {
                // Round capping support is currently disabled b.c. it would require
                // a RRect batch that takes a localMatrix.
                this->drawStrokedLine(points, draw, paint);
                return;
            }
        }
        bool isClosed;
        SkRect rect;
        if (origSrcPath.isRect(&rect, &isClosed) && isClosed) {
            this->drawRect(draw, rect, paint);
            return;
        }
        if (origSrcPath.isOval(&rect)) {
            this->drawOval(draw, rect, paint);
            return;
        }
        SkRRect rrect;
        if (origSrcPath.isRRect(&rrect)) {
            this->drawRRect(draw, rrect, paint);
            return;
        }
    }

    CHECK_SHOULD_DRAW(draw);
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawPath", fContext);

    GrBlurUtils::drawPathWithMaskFilter(fContext, fDrawContext.get(),
        fClip, origSrcPath, paint,
        *draw.fMatrix, prePathMatrix,
        draw.fRC->getBounds(), pathIsMutable);
=======

static SkBitmap wrap_texture(GrTexture* texture, int width, int height) {
    SkBitmap result;
    result.setInfo(SkImageInfo::MakeN32Premul(width, height));
    result.setPixelRef(SkNEW_ARGS(SkGrPixelRef, (result.info(), texture)))->unref();
    return result;
}

void SkGpuDevice::drawPath(const SkDraw& draw, const SkPath& origSrcPath,
                           const SkPaint& paint, const SkMatrix* prePathMatrix,
                           bool pathIsMutable) {
    CHECK_FOR_ANNOTATION(paint);
    CHECK_SHOULD_DRAW(draw);
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawPath", fContext);

    GrBlurUtils::drawPathWithMaskFilter(fContext, fDrawContext, fRenderTarget,
                                        fClip, origSrcPath, paint,
                                        *draw.fMatrix, prePathMatrix,
                                        draw.fClip->getBounds(), pathIsMutable);
>>>>>>> miniblink49
}

static const int kBmpSmallTileSize = 1 << 10;

<<<<<<< HEAD
static inline int get_tile_count(const SkIRect& srcRect, int tileSize)
{
=======
static inline int get_tile_count(const SkIRect& srcRect, int tileSize)  {
>>>>>>> miniblink49
    int tilesX = (srcRect.fRight / tileSize) - (srcRect.fLeft / tileSize) + 1;
    int tilesY = (srcRect.fBottom / tileSize) - (srcRect.fTop / tileSize) + 1;
    return tilesX * tilesY;
}

<<<<<<< HEAD
static int determine_tile_size(const SkIRect& src, int maxTileSize)
{
=======
static int determine_tile_size(const SkBitmap& bitmap, const SkIRect& src, int maxTileSize) {
>>>>>>> miniblink49
    if (maxTileSize <= kBmpSmallTileSize) {
        return maxTileSize;
    }

    size_t maxTileTotalTileSize = get_tile_count(src, maxTileSize);
    size_t smallTotalTileSize = get_tile_count(src, kBmpSmallTileSize);

    maxTileTotalTileSize *= maxTileSize * maxTileSize;
    smallTotalTileSize *= kBmpSmallTileSize * kBmpSmallTileSize;

    if (maxTileTotalTileSize > 2 * smallTotalTileSize) {
        return kBmpSmallTileSize;
    } else {
        return maxTileSize;
    }
}

// Given a bitmap, an optional src rect, and a context with a clip and matrix determine what
// pixels from the bitmap are necessary.
<<<<<<< HEAD
static void determine_clipped_src_rect(int width, int height,
    const GrClip& clip,
    const SkMatrix& viewMatrix,
    const SkISize& imageSize,
    const SkRect* srcRectPtr,
    SkIRect* clippedSrcIRect)
{
    clip.getConservativeBounds(width, height, clippedSrcIRect, nullptr);
=======
static void determine_clipped_src_rect(const GrRenderTarget* rt,
                                       const GrClip& clip,
                                       const SkMatrix& viewMatrix,
                                       const SkBitmap& bitmap,
                                       const SkRect* srcRectPtr,
                                       SkIRect* clippedSrcIRect) {
    clip.getConservativeBounds(rt, clippedSrcIRect, NULL);
>>>>>>> miniblink49
    SkMatrix inv;
    if (!viewMatrix.invert(&inv)) {
        clippedSrcIRect->setEmpty();
        return;
    }
    SkRect clippedSrcRect = SkRect::Make(*clippedSrcIRect);
    inv.mapRect(&clippedSrcRect);
    if (srcRectPtr) {
        // we've setup src space 0,0 to map to the top left of the src rect.
        clippedSrcRect.offset(srcRectPtr->fLeft, srcRectPtr->fTop);
        if (!clippedSrcRect.intersect(*srcRectPtr)) {
            clippedSrcIRect->setEmpty();
            return;
        }
    }
    clippedSrcRect.roundOut(clippedSrcIRect);
<<<<<<< HEAD
    SkIRect bmpBounds = SkIRect::MakeSize(imageSize);
=======
    SkIRect bmpBounds = SkIRect::MakeWH(bitmap.width(), bitmap.height());
>>>>>>> miniblink49
    if (!clippedSrcIRect->intersect(bmpBounds)) {
        clippedSrcIRect->setEmpty();
    }
}

<<<<<<< HEAD
bool SkGpuDevice::shouldTileImageID(uint32_t imageID, const SkIRect& imageRect,
    const SkMatrix& viewMatrix,
    const GrTextureParams& params,
    const SkRect* srcRectPtr,
    int maxTileSize,
    int* tileSize,
    SkIRect* clippedSubset) const
{
    ASSERT_SINGLE_OWNER
    // if it's larger than the max tile size, then we have no choice but tiling.
    if (imageRect.width() > maxTileSize || imageRect.height() > maxTileSize) {
        determine_clipped_src_rect(fDrawContext->width(), fDrawContext->height(),
            fClip, viewMatrix, imageRect.size(),
            srcRectPtr, clippedSubset);
        *tileSize = determine_tile_size(*clippedSubset, maxTileSize);
        return true;
    }

    // If the image would only produce 4 tiles of the smaller size, don't bother tiling it.
    const size_t area = imageRect.width() * imageRect.height();
    if (area < 4 * kBmpSmallTileSize * kBmpSmallTileSize) {
=======
bool SkGpuDevice::shouldTileBitmap(const SkBitmap& bitmap,
                                   const SkMatrix& viewMatrix,
                                   const GrTextureParams& params,
                                   const SkRect* srcRectPtr,
                                   int maxTileSize,
                                   int* tileSize,
                                   SkIRect* clippedSrcRect) const {
    // if bitmap is explictly texture backed then just use the texture
    if (bitmap.getTexture()) {
        return false;
    }

    // if it's larger than the max tile size, then we have no choice but tiling.
    if (bitmap.width() > maxTileSize || bitmap.height() > maxTileSize) {
        determine_clipped_src_rect(fRenderTarget, fClip, viewMatrix, bitmap,
                                   srcRectPtr, clippedSrcRect);
        *tileSize = determine_tile_size(bitmap, *clippedSrcRect, maxTileSize);
        return true;
    }

    if (bitmap.width() * bitmap.height() < 4 * kBmpSmallTileSize * kBmpSmallTileSize) {
        return false;
    }

    // if the entire texture is already in our cache then no reason to tile it
    if (GrIsBitmapInCache(fContext, bitmap, &params)) {
>>>>>>> miniblink49
        return false;
    }

    // At this point we know we could do the draw by uploading the entire bitmap
    // as a texture. However, if the texture would be large compared to the
    // cache size and we don't require most of it for this draw then tile to
    // reduce the amount of upload and cache spill.

    // assumption here is that sw bitmap size is a good proxy for its size as
    // a texture
<<<<<<< HEAD
    size_t bmpSize = area * sizeof(SkPMColor); // assume 32bit pixels
    size_t cacheSize;
    fContext->getResourceCacheLimits(nullptr, &cacheSize);
=======
    size_t bmpSize = bitmap.getSize();
    size_t cacheSize;
    fContext->getResourceCacheLimits(NULL, &cacheSize);
>>>>>>> miniblink49
    if (bmpSize < cacheSize / 2) {
        return false;
    }

<<<<<<< HEAD
    // Figure out how much of the src we will need based on the src rect and clipping. Reject if
    // tiling memory savings would be < 50%.
    determine_clipped_src_rect(fDrawContext->width(), fDrawContext->height(),
        fClip, viewMatrix, imageRect.size(), srcRectPtr,
        clippedSubset);
    *tileSize = kBmpSmallTileSize; // already know whole bitmap fits in one max sized tile.
    size_t usedTileBytes = get_tile_count(*clippedSubset, kBmpSmallTileSize) * kBmpSmallTileSize * kBmpSmallTileSize;
=======
    // Figure out how much of the src we will need based on the src rect and clipping.
    determine_clipped_src_rect(fRenderTarget, fClip, viewMatrix, bitmap, srcRectPtr,
                               clippedSrcRect);
    *tileSize = kBmpSmallTileSize; // already know whole bitmap fits in one max sized tile.
    size_t usedTileBytes = get_tile_count(*clippedSrcRect, kBmpSmallTileSize) *
                           kBmpSmallTileSize * kBmpSmallTileSize;
>>>>>>> miniblink49

    return usedTileBytes < 2 * bmpSize;
}

<<<<<<< HEAD
bool SkGpuDevice::shouldTileBitmap(const SkBitmap& bitmap,
    const SkMatrix& viewMatrix,
    const GrTextureParams& params,
    const SkRect* srcRectPtr,
    int maxTileSize,
    int* tileSize,
    SkIRect* clippedSrcRect) const
{
    ASSERT_SINGLE_OWNER
    // if bitmap is explictly texture backed then just use the texture
    if (bitmap.getTexture()) {
        return false;
    }

    return this->shouldTileImageID(bitmap.getGenerationID(), bitmap.getSubset(), viewMatrix, params,
        srcRectPtr, maxTileSize, tileSize, clippedSrcRect);
}

bool SkGpuDevice::shouldTileImage(const SkImage* image, const SkRect* srcRectPtr,
    SkCanvas::SrcRectConstraint constraint, SkFilterQuality quality,
    const SkMatrix& viewMatrix) const
{
    ASSERT_SINGLE_OWNER
    // if image is explictly texture backed then just use the texture
    if (as_IB(image)->peekTexture()) {
        return false;
    }

    GrTextureParams params;
    bool doBicubic;
    GrTextureParams::FilterMode textureFilterMode = GrSkFilterQualityToGrFilterMode(quality, viewMatrix, SkMatrix::I(), &doBicubic);

    int tileFilterPad;
    if (doBicubic) {
        tileFilterPad = GrBicubicEffect::kFilterTexelPad;
    } else if (GrTextureParams::kNone_FilterMode == textureFilterMode) {
        tileFilterPad = 0;
    } else {
        tileFilterPad = 1;
    }
    params.setFilterMode(textureFilterMode);

    int maxTileSize = fContext->caps()->maxTileSize() - 2 * tileFilterPad;

    // these are output, which we safely ignore, as we just want to know the predicate
    int outTileSize;
    SkIRect outClippedSrcRect;

    return this->shouldTileImageID(image->unique(), image->bounds(), viewMatrix, params, srcRectPtr,
        maxTileSize, &outTileSize, &outClippedSrcRect);
}

void SkGpuDevice::drawBitmap(const SkDraw& origDraw,
    const SkBitmap& bitmap,
    const SkMatrix& m,
    const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    CHECK_SHOULD_DRAW(origDraw);
    SkMatrix viewMatrix;
    viewMatrix.setConcat(*origDraw.fMatrix, m);
    if (bitmap.getTexture()) {
        GrBitmapTextureAdjuster adjuster(&bitmap);
        // We can use kFast here because we know texture-backed bitmaps don't support extractSubset.
        this->drawTextureProducer(&adjuster, nullptr, nullptr, SkCanvas::kFast_SrcRectConstraint,
            viewMatrix, fClip, paint);
        return;
    }
    int maxTileSize = fContext->caps()->maxTileSize();

    // The tile code path doesn't currently support AA, so if the paint asked for aa and we could
    // draw untiled, then we bypass checking for tiling purely for optimization reasons.
    bool drawAA = !fDrawContext->isUnifiedMultisampled() && paint.isAntiAlias() && bitmap.width() <= maxTileSize && bitmap.height() <= maxTileSize;

    bool skipTileCheck = drawAA || paint.getMaskFilter();

    if (!skipTileCheck) {
        SkRect srcRect = SkRect::MakeIWH(bitmap.width(), bitmap.height());
        int tileSize;
        SkIRect clippedSrcRect;

        GrTextureParams params;
        bool doBicubic;
        GrTextureParams::FilterMode textureFilterMode = GrSkFilterQualityToGrFilterMode(paint.getFilterQuality(), viewMatrix, SkMatrix::I(),
            &doBicubic);

        int tileFilterPad;

        if (doBicubic) {
            tileFilterPad = GrBicubicEffect::kFilterTexelPad;
        } else if (GrTextureParams::kNone_FilterMode == textureFilterMode) {
            tileFilterPad = 0;
        } else {
            tileFilterPad = 1;
        }
        params.setFilterMode(textureFilterMode);

        int maxTileSizeForFilter = fContext->caps()->maxTileSize() - 2 * tileFilterPad;
        if (this->shouldTileBitmap(bitmap, viewMatrix, params, &srcRect,
                maxTileSizeForFilter, &tileSize, &clippedSrcRect)) {
            this->drawTiledBitmap(bitmap, viewMatrix, srcRect, clippedSrcRect, params, paint,
                SkCanvas::kStrict_SrcRectConstraint, tileSize, doBicubic);
            return;
        }
    }
    GrBitmapTextureMaker maker(fContext, bitmap);
    this->drawTextureProducer(&maker, nullptr, nullptr, SkCanvas::kStrict_SrcRectConstraint,
        viewMatrix, fClip, paint);
=======
void SkGpuDevice::drawBitmap(const SkDraw& origDraw,
                             const SkBitmap& bitmap,
                             const SkMatrix& m,
                             const SkPaint& paint) {
    SkMatrix concat;
    SkTCopyOnFirstWrite<SkDraw> draw(origDraw);
    if (!m.isIdentity()) {
        concat.setConcat(*draw->fMatrix, m);
        draw.writable()->fMatrix = &concat;
    }
    this->drawBitmapCommon(*draw, bitmap, NULL, NULL, paint, SkCanvas::kNone_DrawBitmapRectFlag);
>>>>>>> miniblink49
}

// This method outsets 'iRect' by 'outset' all around and then clamps its extents to
// 'clamp'. 'offset' is adjusted to remain positioned over the top-left corner
// of 'iRect' for all possible outsets/clamps.
static inline void clamped_outset_with_offset(SkIRect* iRect,
<<<<<<< HEAD
    int outset,
    SkPoint* offset,
    const SkIRect& clamp)
{
=======
                                              int outset,
                                              SkPoint* offset,
                                              const SkIRect& clamp) {
>>>>>>> miniblink49
    iRect->outset(outset, outset);

    int leftClampDelta = clamp.fLeft - iRect->fLeft;
    if (leftClampDelta > 0) {
        offset->fX -= outset - leftClampDelta;
        iRect->fLeft = clamp.fLeft;
    } else {
        offset->fX -= outset;
    }

    int topClampDelta = clamp.fTop - iRect->fTop;
    if (topClampDelta > 0) {
        offset->fY -= outset - topClampDelta;
        iRect->fTop = clamp.fTop;
    } else {
        offset->fY -= outset;
    }

    if (iRect->fRight > clamp.fRight) {
        iRect->fRight = clamp.fRight;
    }
    if (iRect->fBottom > clamp.fBottom) {
        iRect->fBottom = clamp.fBottom;
    }
}

<<<<<<< HEAD
// Break 'bitmap' into several tiles to draw it since it has already
// been determined to be too large to fit in VRAM
void SkGpuDevice::drawTiledBitmap(const SkBitmap& bitmap,
    const SkMatrix& viewMatrix,
    const SkRect& srcRect,
    const SkIRect& clippedSrcIRect,
    const GrTextureParams& params,
    const SkPaint& origPaint,
    SkCanvas::SrcRectConstraint constraint,
    int tileSize,
    bool bicubic)
{
    ASSERT_SINGLE_OWNER

    // This is the funnel for all paths that draw tiled bitmaps/images. Log histogram entries.
    SK_HISTOGRAM_BOOLEAN("DrawTiled", true);
    LogDrawScaleFactor(viewMatrix, origPaint.getFilterQuality());

=======
static bool has_aligned_samples(const SkRect& srcRect,
                                const SkRect& transformedRect) {
    // detect pixel disalignment
    if (SkScalarAbs(SkScalarRoundToScalar(transformedRect.left()) -
            transformedRect.left()) < COLOR_BLEED_TOLERANCE &&
        SkScalarAbs(SkScalarRoundToScalar(transformedRect.top()) -
            transformedRect.top()) < COLOR_BLEED_TOLERANCE &&
        SkScalarAbs(transformedRect.width() - srcRect.width()) <
            COLOR_BLEED_TOLERANCE &&
        SkScalarAbs(transformedRect.height() - srcRect.height()) <
            COLOR_BLEED_TOLERANCE) {
        return true;
    }
    return false;
}

static bool may_color_bleed(const SkRect& srcRect,
                            const SkRect& transformedRect,
                            const SkMatrix& m) {
    // Only gets called if has_aligned_samples returned false.
    // So we can assume that sampling is axis aligned but not texel aligned.
    SkASSERT(!has_aligned_samples(srcRect, transformedRect));
    SkRect innerSrcRect(srcRect), innerTransformedRect,
        outerTransformedRect(transformedRect);
    innerSrcRect.inset(SK_ScalarHalf, SK_ScalarHalf);
    m.mapRect(&innerTransformedRect, innerSrcRect);

    // The gap between outerTransformedRect and innerTransformedRect
    // represents the projection of the source border area, which is
    // problematic for color bleeding.  We must check whether any
    // destination pixels sample the border area.
    outerTransformedRect.inset(COLOR_BLEED_TOLERANCE, COLOR_BLEED_TOLERANCE);
    innerTransformedRect.outset(COLOR_BLEED_TOLERANCE, COLOR_BLEED_TOLERANCE);
    SkIRect outer, inner;
    outerTransformedRect.round(&outer);
    innerTransformedRect.round(&inner);
    // If the inner and outer rects round to the same result, it means the
    // border does not overlap any pixel centers. Yay!
    return inner != outer;
}

static bool needs_texture_domain(const SkBitmap& bitmap,
                                 const SkRect& srcRect,
                                 GrTextureParams &params,
                                 const SkMatrix& contextMatrix,
                                 bool bicubic) {
    bool needsTextureDomain = false;
    GrTexture* tex = bitmap.getTexture();
    int width = tex ? tex->width() : bitmap.width();
    int height = tex ? tex->height() : bitmap.height();

    if (bicubic || params.filterMode() != GrTextureParams::kNone_FilterMode) {
        // Need texture domain if drawing a sub rect
        needsTextureDomain = srcRect.width() < width ||
                             srcRect.height() < height;
        if (!bicubic && needsTextureDomain && contextMatrix.rectStaysRect()) {
            // sampling is axis-aligned
            SkRect transformedRect;
            contextMatrix.mapRect(&transformedRect, srcRect);

            if (has_aligned_samples(srcRect, transformedRect)) {
                params.setFilterMode(GrTextureParams::kNone_FilterMode);
                needsTextureDomain = false;
            } else {
                needsTextureDomain = may_color_bleed(srcRect, transformedRect, contextMatrix);
            }
        }
    }
    return needsTextureDomain;
}

void SkGpuDevice::drawBitmapCommon(const SkDraw& draw,
                                   const SkBitmap& bitmap,
                                   const SkRect* srcRectPtr,
                                   const SkSize* dstSizePtr,
                                   const SkPaint& paint,
                                   SkCanvas::DrawBitmapRectFlags flags) {
    CHECK_SHOULD_DRAW(draw);

    SkRect srcRect;
    SkSize dstSize;
    // If there is no src rect, or the src rect contains the entire bitmap then we're effectively
    // in the (easier) bleed case, so update flags.
    if (NULL == srcRectPtr) {
        SkScalar w = SkIntToScalar(bitmap.width());
        SkScalar h = SkIntToScalar(bitmap.height());
        dstSize.fWidth = w;
        dstSize.fHeight = h;
        srcRect.set(0, 0, w, h);
    } else {
        SkASSERT(dstSizePtr);
        srcRect = *srcRectPtr;
        dstSize = *dstSizePtr;
    }
    GrTexture* tex = bitmap.getTexture();
    int width = tex ? tex->width() : bitmap.width();
    int height = tex ? tex->height() : bitmap.height();
    if (srcRect.fLeft <= 0 && srcRect.fTop <= 0 &&
        srcRect.fRight >= width && srcRect.fBottom >= height) {
        flags = (SkCanvas::DrawBitmapRectFlags) (flags | SkCanvas::kBleed_DrawBitmapRectFlag);
    }

    // If the render target is not msaa and draw is antialiased, we call
    // drawRect instead of drawing on the render target directly.
    // FIXME: the tiled bitmap code path doesn't currently support
    // anti-aliased edges, we work around that for now by drawing directly
    // if the image size exceeds maximum texture size.
    int maxTextureSize = fContext->caps()->maxTextureSize();
    bool directDraw = fRenderTarget->isUnifiedMultisampled() ||
                      !paint.isAntiAlias() ||
                      bitmap.width() > maxTextureSize ||
                      bitmap.height() > maxTextureSize;

    // we check whether dst rect are pixel aligned
    if (!directDraw) {
        bool staysRect = draw.fMatrix->rectStaysRect();

        if (staysRect) {
            SkRect rect;
            SkRect dstRect = SkRect::MakeXYWH(0, 0, dstSize.fWidth, dstSize.fHeight);
            draw.fMatrix->mapRect(&rect, dstRect);
            const SkScalar *scalars = rect.asScalars();
            bool isDstPixelAligned = true;
            for (int i = 0; i < 4; i++) {
                if (!SkScalarIsInt(scalars[i])) {
                    isDstPixelAligned = false;
                    break;
                }
            }

            if (isDstPixelAligned)
                directDraw = true;
        }
    }

    if (paint.getMaskFilter() || !directDraw) {
        // Convert the bitmap to a shader so that the rect can be drawn
        // through drawRect, which supports mask filters.
        SkBitmap        tmp;    // subset of bitmap, if necessary
        const SkBitmap* bitmapPtr = &bitmap;
        SkMatrix localM;
        if (srcRectPtr) {
            localM.setTranslate(-srcRectPtr->fLeft, -srcRectPtr->fTop);
            localM.postScale(dstSize.fWidth / srcRectPtr->width(),
                             dstSize.fHeight / srcRectPtr->height());
            // In bleed mode we position and trim the bitmap based on the src rect which is
            // already accounted for in 'm' and 'srcRect'. In clamp mode we need to chop out
            // the desired portion of the bitmap and then update 'm' and 'srcRect' to
            // compensate.
            if (!(SkCanvas::kBleed_DrawBitmapRectFlag & flags)) {
                SkIRect iSrc;
                srcRect.roundOut(&iSrc);

                SkPoint offset = SkPoint::Make(SkIntToScalar(iSrc.fLeft),
                                               SkIntToScalar(iSrc.fTop));

                if (!bitmap.extractSubset(&tmp, iSrc)) {
                    return;     // extraction failed
                }
                bitmapPtr = &tmp;
                srcRect.offset(-offset.fX, -offset.fY);

                // The source rect has changed so update the matrix
                localM.preTranslate(offset.fX, offset.fY);
            }
        } else {
            localM.reset();
        }

        SkPaint paintWithShader(paint);
        paintWithShader.setShader(SkShader::CreateBitmapShader(*bitmapPtr,
            SkShader::kClamp_TileMode, SkShader::kClamp_TileMode, &localM))->unref();
        SkRect dstRect = {0, 0, dstSize.fWidth, dstSize.fHeight};
        this->drawRect(draw, dstRect, paintWithShader);

        return;
    }

    // If there is no mask filter than it is OK to handle the src rect -> dst rect scaling using
    // the view matrix rather than a local matrix.
    SkMatrix m;
    m.setScale(dstSize.fWidth / srcRect.width(),
               dstSize.fHeight / srcRect.height());
    SkMatrix viewM = *draw.fMatrix;
    viewM.preConcat(m);

    GrTextureParams params;
    SkFilterQuality paintFilterQuality = paint.getFilterQuality();
    GrTextureParams::FilterMode textureFilterMode;

    bool doBicubic = false;

    switch(paintFilterQuality) {
        case kNone_SkFilterQuality:
            textureFilterMode = GrTextureParams::kNone_FilterMode;
            break;
        case kLow_SkFilterQuality:
            textureFilterMode = GrTextureParams::kBilerp_FilterMode;
            break;
        case kMedium_SkFilterQuality:
            if (viewM.getMinScale() < SK_Scalar1) {
                textureFilterMode = GrTextureParams::kMipMap_FilterMode;
            } else {
                // Don't trigger MIP level generation unnecessarily.
                textureFilterMode = GrTextureParams::kBilerp_FilterMode;
            }
            break;
        case kHigh_SkFilterQuality:
            // Minification can look bad with the bicubic effect.
            doBicubic =
                GrBicubicEffect::ShouldUseBicubic(viewM, &textureFilterMode);
            break;
        default:
            SkErrorInternals::SetError( kInvalidPaint_SkError,
                                        "Sorry, I don't understand the filtering "
                                        "mode you asked for.  Falling back to "
                                        "MIPMaps.");
            textureFilterMode = GrTextureParams::kMipMap_FilterMode;
            break;
    }

    int tileFilterPad;
    if (doBicubic) {
        tileFilterPad = GrBicubicEffect::kFilterTexelPad;
    } else if (GrTextureParams::kNone_FilterMode == textureFilterMode) {
        tileFilterPad = 0;
    } else {
        tileFilterPad = 1;
    }
    params.setFilterMode(textureFilterMode);

    int maxTileSize = fContext->caps()->maxTextureSize() - 2 * tileFilterPad;
    int tileSize;

    SkIRect clippedSrcRect;
    if (this->shouldTileBitmap(bitmap, viewM, params, srcRectPtr, maxTileSize, &tileSize,
                               &clippedSrcRect)) {
        this->drawTiledBitmap(bitmap, viewM, srcRect, clippedSrcRect, params, paint, flags,
                              tileSize, doBicubic);
    } else {
        // take the simple case
        bool needsTextureDomain = needs_texture_domain(bitmap,
                                                       srcRect,
                                                       params,
                                                       viewM,
                                                       doBicubic);
        this->internalDrawBitmap(bitmap,
                                 viewM,
                                 srcRect,
                                 params,
                                 paint,
                                 flags,
                                 doBicubic,
                                 needsTextureDomain);
    }
}

// Break 'bitmap' into several tiles to draw it since it has already
// been determined to be too large to fit in VRAM
void SkGpuDevice::drawTiledBitmap(const SkBitmap& bitmap,
                                  const SkMatrix& viewMatrix,
                                  const SkRect& srcRect,
                                  const SkIRect& clippedSrcIRect,
                                  const GrTextureParams& params,
                                  const SkPaint& paint,
                                  SkCanvas::DrawBitmapRectFlags flags,
                                  int tileSize,
                                  bool bicubic) {
>>>>>>> miniblink49
    // The following pixel lock is technically redundant, but it is desirable
    // to lock outside of the tile loop to prevent redecoding the whole image
    // at each tile in cases where 'bitmap' holds an SkDiscardablePixelRef that
    // is larger than the limit of the discardable memory pool.
    SkAutoLockPixels alp(bitmap);
<<<<<<< HEAD

    const SkPaint* paint = &origPaint;
    SkPaint tempPaint;
    if (origPaint.isAntiAlias() && !fDrawContext->isUnifiedMultisampled()) {
        // Drop antialiasing to avoid seams at tile boundaries.
        tempPaint = origPaint;
        tempPaint.setAntiAlias(false);
        paint = &tempPaint;
    }
=======
>>>>>>> miniblink49
    SkRect clippedSrcRect = SkRect::Make(clippedSrcIRect);

    int nx = bitmap.width() / tileSize;
    int ny = bitmap.height() / tileSize;
    for (int x = 0; x <= nx; x++) {
        for (int y = 0; y <= ny; y++) {
            SkRect tileR;
            tileR.set(SkIntToScalar(x * tileSize),
<<<<<<< HEAD
                SkIntToScalar(y * tileSize),
                SkIntToScalar((x + 1) * tileSize),
                SkIntToScalar((y + 1) * tileSize));
=======
                      SkIntToScalar(y * tileSize),
                      SkIntToScalar((x + 1) * tileSize),
                      SkIntToScalar((y + 1) * tileSize));
>>>>>>> miniblink49

            if (!SkRect::Intersects(tileR, clippedSrcRect)) {
                continue;
            }

            if (!tileR.intersect(srcRect)) {
                continue;
            }

            SkBitmap tmpB;
            SkIRect iTileR;
            tileR.roundOut(&iTileR);
            SkPoint offset = SkPoint::Make(SkIntToScalar(iTileR.fLeft),
<<<<<<< HEAD
                SkIntToScalar(iTileR.fTop));
=======
                                           SkIntToScalar(iTileR.fTop));
>>>>>>> miniblink49

            // Adjust the context matrix to draw at the right x,y in device space
            SkMatrix viewM = viewMatrix;
            SkMatrix tmpM;
            tmpM.setTranslate(offset.fX - srcRect.fLeft, offset.fY - srcRect.fTop);
            viewM.preConcat(tmpM);

            if (GrTextureParams::kNone_FilterMode != params.filterMode() || bicubic) {
                SkIRect iClampRect;

<<<<<<< HEAD
                if (SkCanvas::kFast_SrcRectConstraint == constraint) {
=======
                if (SkCanvas::kBleed_DrawBitmapRectFlag & flags) {
>>>>>>> miniblink49
                    // In bleed mode we want to always expand the tile on all edges
                    // but stay within the bitmap bounds
                    iClampRect = SkIRect::MakeWH(bitmap.width(), bitmap.height());
                } else {
                    // In texture-domain/clamp mode we only want to expand the
                    // tile on edges interior to "srcRect" (i.e., we want to
                    // not bleed across the original clamped edges)
                    srcRect.roundOut(&iClampRect);
                }
                int outset = bicubic ? GrBicubicEffect::kFilterTexelPad : 1;
                clamped_outset_with_offset(&iTileR, outset, &offset, iClampRect);
            }

            if (bitmap.extractSubset(&tmpB, iTileR)) {
                // now offset it to make it "local" to our tmp bitmap
                tileR.offset(-offset.fX, -offset.fY);
                GrTextureParams paramsTemp = params;
<<<<<<< HEAD
                // de-optimized this determination
                bool needsTextureDomain = true;
                this->internalDrawBitmap(tmpB,
                    viewM,
                    tileR,
                    paramsTemp,
                    *paint,
                    constraint,
                    bicubic,
                    needsTextureDomain);
=======
                bool needsTextureDomain = needs_texture_domain(bitmap,
                                                               srcRect,
                                                               paramsTemp,
                                                               viewM,
                                                               bicubic);
                this->internalDrawBitmap(tmpB,
                                         viewM,
                                         tileR,
                                         paramsTemp,
                                         paint,
                                         flags,
                                         bicubic,
                                         needsTextureDomain);
>>>>>>> miniblink49
            }
        }
    }
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 *  This is called by drawBitmap(), which has to handle images that may be too
 *  large to be represented by a single texture.
 *
 *  internalDrawBitmap assumes that the specified bitmap will fit in a texture
 *  and that non-texture portion of the GrPaint has already been setup.
 */
void SkGpuDevice::internalDrawBitmap(const SkBitmap& bitmap,
<<<<<<< HEAD
    const SkMatrix& viewMatrix,
    const SkRect& srcRect,
    const GrTextureParams& params,
    const SkPaint& paint,
    SkCanvas::SrcRectConstraint constraint,
    bool bicubic,
    bool needsTextureDomain)
{
    // We should have already handled bitmaps larger than the max texture size.
    SkASSERT(bitmap.width() <= fContext->caps()->maxTextureSize() && bitmap.height() <= fContext->caps()->maxTextureSize());
    // Unless the bitmap is inherently texture-backed, we should be respecting the max tile size
    // by the time we get here.
    SkASSERT(bitmap.getTexture() || (bitmap.width() <= fContext->caps()->maxTileSize() && bitmap.height() <= fContext->caps()->maxTileSize()));

    GrTexture* texture;
    SkSourceGammaTreatment gammaTreatment = this->surfaceProps().isGammaCorrect()
        ? SkSourceGammaTreatment::kRespect
        : SkSourceGammaTreatment::kIgnore;
    AutoBitmapTexture abt(fContext, bitmap, params, gammaTreatment, &texture);
    if (nullptr == texture) {
        return;
    }

    SkRect dstRect = { 0, 0, srcRect.width(), srcRect.height() };
    SkRect paintRect;
    SkScalar wInv = SkScalarInvert(SkIntToScalar(texture->width()));
    SkScalar hInv = SkScalarInvert(SkIntToScalar(texture->height()));
    paintRect.setLTRB(SkScalarMul(srcRect.fLeft, wInv),
        SkScalarMul(srcRect.fTop, hInv),
        SkScalarMul(srcRect.fRight, wInv),
        SkScalarMul(srcRect.fBottom, hInv));

    SkMatrix texMatrix;
    texMatrix.reset();
    if (kAlpha_8_SkColorType == bitmap.colorType() && paint.getShader()) {
        // In cases where we are doing an A8 bitmap draw with a shader installed, we cannot use
        // local coords with the bitmap draw since it may mess up texture look ups for the shader.
        // Thus we need to pass in the transform matrix directly to the texture processor used for
        // the bitmap draw.
        texMatrix.setScale(wInv, hInv);
    }
=======
                                     const SkMatrix& viewMatrix,
                                     const SkRect& srcRect,
                                     const GrTextureParams& params,
                                     const SkPaint& paint,
                                     SkCanvas::DrawBitmapRectFlags flags,
                                     bool bicubic,
                                     bool needsTextureDomain) {
    SkASSERT(bitmap.width() <= fContext->caps()->maxTextureSize() &&
             bitmap.height() <= fContext->caps()->maxTextureSize());

    GrTexture* texture;
    AutoBitmapTexture abt(fContext, bitmap, &params, &texture);
    if (NULL == texture) {
        return;
    }

    SkRect dstRect = {0, 0, srcRect.width(), srcRect.height() };
    SkRect paintRect;
    SkScalar wInv = SkScalarInvert(SkIntToScalar(texture->width()));
    SkScalar hInv = SkScalarInvert(SkIntToScalar(texture->height()));
    paintRect.setLTRB(SkScalarMul(srcRect.fLeft,   wInv),
                      SkScalarMul(srcRect.fTop,    hInv),
                      SkScalarMul(srcRect.fRight,  wInv),
                      SkScalarMul(srcRect.fBottom, hInv));
>>>>>>> miniblink49

    SkRect textureDomain = SkRect::MakeEmpty();

    // Construct a GrPaint by setting the bitmap texture as the first effect and then configuring
    // the rest from the SkPaint.
<<<<<<< HEAD
    sk_sp<GrFragmentProcessor> fp;

    if (needsTextureDomain && (SkCanvas::kStrict_SrcRectConstraint == constraint)) {
=======
    GrPaint grPaint;
    SkAutoTUnref<GrFragmentProcessor> fp;

    if (needsTextureDomain && !(flags & SkCanvas::kBleed_DrawBitmapRectFlag)) {
>>>>>>> miniblink49
        // Use a constrained texture domain to avoid color bleeding
        SkScalar left, top, right, bottom;
        if (srcRect.width() > SK_Scalar1) {
            SkScalar border = SK_ScalarHalf / texture->width();
            left = paintRect.left() + border;
            right = paintRect.right() - border;
        } else {
            left = right = SkScalarHalf(paintRect.left() + paintRect.right());
        }
        if (srcRect.height() > SK_Scalar1) {
            SkScalar border = SK_ScalarHalf / texture->height();
            top = paintRect.top() + border;
            bottom = paintRect.bottom() - border;
        } else {
            top = bottom = SkScalarHalf(paintRect.top() + paintRect.bottom());
        }
        textureDomain.setLTRB(left, top, right, bottom);
        if (bicubic) {
<<<<<<< HEAD
            fp = GrBicubicEffect::Make(texture, texMatrix, textureDomain);
        } else {
            fp = GrTextureDomainEffect::Make(texture, texMatrix, textureDomain,
                GrTextureDomain::kClamp_Mode, params.filterMode());
=======
            fp.reset(GrBicubicEffect::Create(grPaint.getProcessorDataManager(), texture,
                                             SkMatrix::I(), textureDomain));
        } else {
            fp.reset(GrTextureDomainEffect::Create(grPaint.getProcessorDataManager(),
                                                   texture,
                                                   SkMatrix::I(),
                                                   textureDomain,
                                                   GrTextureDomain::kClamp_Mode,
                                                   params.filterMode()));
>>>>>>> miniblink49
        }
    } else if (bicubic) {
        SkASSERT(GrTextureParams::kNone_FilterMode == params.filterMode());
        SkShader::TileMode tileModes[2] = { params.getTileModeX(), params.getTileModeY() };
<<<<<<< HEAD
        fp = GrBicubicEffect::Make(texture, texMatrix, tileModes);
    } else {
        fp = GrSimpleTextureEffect::Make(texture, texMatrix, params);
    }

    GrPaint grPaint;
    if (!SkPaintToGrPaintWithTexture(this->context(), paint, viewMatrix, std::move(fp),
            kAlpha_8_SkColorType == bitmap.colorType(),
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
        return;
    }

    if (kAlpha_8_SkColorType == bitmap.colorType() && paint.getShader()) {
        // We don't have local coords in this case and have previously set the transform
        // matrices directly on the texture processor.
        fDrawContext->drawRect(fClip, grPaint, viewMatrix, dstRect);
    } else {
        fDrawContext->fillRectToRect(fClip, grPaint, viewMatrix, dstRect, paintRect);
=======
        fp.reset(GrBicubicEffect::Create(grPaint.getProcessorDataManager(), texture, SkMatrix::I(),
                                         tileModes));
    } else {
        fp.reset(GrSimpleTextureEffect::Create(grPaint.getProcessorDataManager(), texture,
                                               SkMatrix::I(), params));
    }

    grPaint.addColorProcessor(fp);
    bool alphaOnly = !(kAlpha_8_SkColorType == bitmap.colorType());
    GrColor paintColor = (alphaOnly) ? SkColor2GrColorJustAlpha(paint.getColor()) :
                                       SkColor2GrColor(paint.getColor());
    if (!SkPaint2GrPaintNoShader(this->context(), fRenderTarget, paint, paintColor, false,
                                 &grPaint)) {
        return;
    }

    fDrawContext->drawNonAARectToRect(fRenderTarget, fClip, grPaint, viewMatrix, dstRect,
                                      paintRect);
}

bool SkGpuDevice::filterTexture(GrContext* context, GrTexture* texture,
                                int width, int height,
                                const SkImageFilter* filter,
                                const SkImageFilter::Context& ctx,
                                SkBitmap* result, SkIPoint* offset) {
    SkASSERT(filter);

    SkImageFilter::Proxy proxy(this);

    if (filter->canFilterImageGPU()) {
        return filter->filterImageGPU(&proxy, wrap_texture(texture, width, height),
                                      ctx, result, offset);
    } else {
        return false;
>>>>>>> miniblink49
    }
}

void SkGpuDevice::drawSprite(const SkDraw& draw, const SkBitmap& bitmap,
<<<<<<< HEAD
    int left, int top, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
=======
                             int left, int top, const SkPaint& paint) {
>>>>>>> miniblink49
    // drawSprite is defined to be in device coords.
    CHECK_SHOULD_DRAW(draw);

    SkAutoLockPixels alp(bitmap, !bitmap.getTexture());
    if (!bitmap.getTexture() && !bitmap.readyToDraw()) {
        return;
    }

<<<<<<< HEAD
    int offX = bitmap.pixelRefOrigin().fX;
    int offY = bitmap.pixelRefOrigin().fY;
=======
>>>>>>> miniblink49
    int w = bitmap.width();
    int h = bitmap.height();

    GrTexture* texture;
<<<<<<< HEAD
    // draw sprite neither filters nor tiles.
    AutoBitmapTexture abt(fContext, bitmap, GrTextureParams::ClampNoFilter(),
        SkSourceGammaTreatment::kRespect, &texture);
=======
    // draw sprite uses the default texture params
    AutoBitmapTexture abt(fContext, bitmap, NULL, &texture);
>>>>>>> miniblink49
    if (!texture) {
        return;
    }

<<<<<<< HEAD
    bool alphaOnly = kAlpha_8_SkColorType == bitmap.colorType();

    SkASSERT(!paint.getImageFilter());

    GrPaint grPaint;
    sk_sp<GrFragmentProcessor> fp(GrSimpleTextureEffect::Make(texture, SkMatrix::I()));
    if (alphaOnly) {
        fp = GrFragmentProcessor::MulOutputByInputUnpremulColor(std::move(fp));
    } else {
        fp = GrFragmentProcessor::MulOutputByInputAlpha(std::move(fp));
    }
    if (!SkPaintToGrPaintReplaceShader(this->context(), paint, std::move(fp),
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
        return;
    }

    fDrawContext->fillRectToRect(fClip,
        grPaint,
        SkMatrix::I(),
        SkRect::MakeXYWH(SkIntToScalar(left),
            SkIntToScalar(top),
            SkIntToScalar(w),
            SkIntToScalar(h)),
        SkRect::MakeXYWH(SkIntToScalar(offX) / texture->width(),
            SkIntToScalar(offY) / texture->height(),
            SkIntToScalar(w) / texture->width(),
            SkIntToScalar(h) / texture->height()));
}

void SkGpuDevice::drawBitmapRect(const SkDraw& draw, const SkBitmap& bitmap,
    const SkRect* src, const SkRect& origDst,
    const SkPaint& paint, SkCanvas::SrcRectConstraint constraint)
{
    ASSERT_SINGLE_OWNER
    CHECK_SHOULD_DRAW(draw);
    if (bitmap.getTexture()) {
        GrBitmapTextureAdjuster adjuster(&bitmap);
        this->drawTextureProducer(&adjuster, src, &origDst, constraint, *draw.fMatrix, fClip,
            paint);
        return;
    }
    // The src rect is inferred to be the bmp bounds if not provided. Otherwise, the src rect must
    // be clipped to the bmp bounds. To determine tiling parameters we need the filter mode which
    // in turn requires knowing the src-to-dst mapping. If the src was clipped to the bmp bounds
    // then we use the src-to-dst mapping to compute a new clipped dst rect.
    const SkRect* dst = &origDst;
    const SkRect bmpBounds = SkRect::MakeIWH(bitmap.width(), bitmap.height());
    // Compute matrix from the two rectangles
    if (!src) {
        src = &bmpBounds;
    }

    SkMatrix srcToDstMatrix;
    if (!srcToDstMatrix.setRectToRect(*src, *dst, SkMatrix::kFill_ScaleToFit)) {
        return;
    }
    SkRect tmpSrc, tmpDst;
    if (src != &bmpBounds) {
        if (!bmpBounds.contains(*src)) {
            tmpSrc = *src;
            if (!tmpSrc.intersect(bmpBounds)) {
                return; // nothing to draw
            }
            src = &tmpSrc;
            srcToDstMatrix.mapRect(&tmpDst, *src);
            dst = &tmpDst;
        }
    }

    int maxTileSize = fContext->caps()->maxTileSize();

    // The tile code path doesn't currently support AA, so if the paint asked for aa and we could
    // draw untiled, then we bypass checking for tiling purely for optimization reasons.
    bool drawAA = !fDrawContext->isUnifiedMultisampled() && paint.isAntiAlias() && bitmap.width() <= maxTileSize && bitmap.height() <= maxTileSize;

    bool skipTileCheck = drawAA || paint.getMaskFilter();

    if (!skipTileCheck) {
        int tileSize;
        SkIRect clippedSrcRect;

        GrTextureParams params;
        bool doBicubic;
        GrTextureParams::FilterMode textureFilterMode = GrSkFilterQualityToGrFilterMode(paint.getFilterQuality(), *draw.fMatrix, srcToDstMatrix,
            &doBicubic);

        int tileFilterPad;

        if (doBicubic) {
            tileFilterPad = GrBicubicEffect::kFilterTexelPad;
        } else if (GrTextureParams::kNone_FilterMode == textureFilterMode) {
            tileFilterPad = 0;
        } else {
            tileFilterPad = 1;
        }
        params.setFilterMode(textureFilterMode);

        int maxTileSizeForFilter = fContext->caps()->maxTileSize() - 2 * tileFilterPad;
        // Fold the dst rect into the view matrix. This is only OK because we don't get here if
        // we have a mask filter.
        SkMatrix viewMatrix = *draw.fMatrix;
        viewMatrix.preTranslate(dst->fLeft, dst->fTop);
        viewMatrix.preScale(dst->width() / src->width(), dst->height() / src->height());
        if (this->shouldTileBitmap(bitmap, viewMatrix, params, src,
                maxTileSizeForFilter, &tileSize, &clippedSrcRect)) {
            this->drawTiledBitmap(bitmap, viewMatrix, *src, clippedSrcRect, params, paint,
                constraint, tileSize, doBicubic);
            return;
        }
    }
    GrBitmapTextureMaker maker(fContext, bitmap);
    this->drawTextureProducer(&maker, src, dst, constraint, *draw.fMatrix, fClip, paint);
}

void SkGpuDevice::drawDevice(const SkDraw& draw, SkBaseDevice* device,
    int x, int y, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    // clear of the source device must occur before CHECK_SHOULD_DRAW
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawDevice", fContext);
    SkGpuDevice* dev = static_cast<SkGpuDevice*>(device);

    // drawDevice is defined to be in device coords.
    CHECK_SHOULD_DRAW(draw);

    sk_sp<GrTexture> devTex(dev->accessDrawContext()->asTexture());
    if (!devTex) {
=======
    SkImageFilter* filter = paint.getImageFilter();
    // This bitmap will own the filtered result as a texture.
    SkBitmap filteredBitmap;

    if (filter) {
        SkIPoint offset = SkIPoint::Make(0, 0);
        SkMatrix matrix(*draw.fMatrix);
        matrix.postTranslate(SkIntToScalar(-left), SkIntToScalar(-top));
        SkIRect clipBounds = SkIRect::MakeWH(bitmap.width(), bitmap.height());
        SkAutoTUnref<SkImageFilter::Cache> cache(getImageFilterCache());
        // This cache is transient, and is freed (along with all its contained
        // textures) when it goes out of scope.
        SkImageFilter::Context ctx(matrix, clipBounds, cache);
        if (this->filterTexture(fContext, texture, w, h, filter, ctx, &filteredBitmap,
                                &offset)) {
            texture = (GrTexture*) filteredBitmap.getTexture();
            w = filteredBitmap.width();
            h = filteredBitmap.height();
            left += offset.x();
            top += offset.y();
        } else {
            return;
        }
    }

    GrPaint grPaint;
    grPaint.addColorTextureProcessor(texture, SkMatrix::I());

    if (!SkPaint2GrPaintNoShader(this->context(), fRenderTarget, paint,
                                 SkColor2GrColorJustAlpha(paint.getColor()), false, &grPaint)) {
        return;
    }

    fDrawContext->drawNonAARectToRect(fRenderTarget,
                                      fClip,
                                      grPaint,
                                      SkMatrix::I(),
                                      SkRect::MakeXYWH(SkIntToScalar(left),
                                                       SkIntToScalar(top),
                                                       SkIntToScalar(w),
                                                       SkIntToScalar(h)),
                                      SkRect::MakeXYWH(0,
                                                       0,
                                                       SK_Scalar1 * w / texture->width(),
                                                       SK_Scalar1 * h / texture->height()));
}

void SkGpuDevice::drawBitmapRect(const SkDraw& origDraw, const SkBitmap& bitmap,
                                 const SkRect* src, const SkRect& dst,
                                 const SkPaint& paint,
                                 SkCanvas::DrawBitmapRectFlags flags) {
    SkMatrix    matrix;
    SkRect      bitmapBounds, tmpSrc;

    bitmapBounds.set(0, 0,
                     SkIntToScalar(bitmap.width()),
                     SkIntToScalar(bitmap.height()));

    // Compute matrix from the two rectangles
    if (src) {
        tmpSrc = *src;
    } else {
        tmpSrc = bitmapBounds;
    }

    matrix.setRectToRect(tmpSrc, dst, SkMatrix::kFill_ScaleToFit);

    // clip the tmpSrc to the bounds of the bitmap. No check needed if src==null.
    if (src) {
        if (!bitmapBounds.contains(tmpSrc)) {
            if (!tmpSrc.intersect(bitmapBounds)) {
                return; // nothing to draw
            }
        }
    }

    SkRect tmpDst;
    matrix.mapRect(&tmpDst, tmpSrc);

    SkTCopyOnFirstWrite<SkDraw> draw(origDraw);
    if (0 != tmpDst.fLeft || 0 != tmpDst.fTop) {
        // Translate so that tempDst's top left is at the origin.
        matrix = *origDraw.fMatrix;
        matrix.preTranslate(tmpDst.fLeft, tmpDst.fTop);
        draw.writable()->fMatrix = &matrix;
    }
    SkSize dstSize;
    dstSize.fWidth = tmpDst.width();
    dstSize.fHeight = tmpDst.height();

    this->drawBitmapCommon(*draw, bitmap, &tmpSrc, &dstSize, paint, flags);
}

void SkGpuDevice::drawDevice(const SkDraw& draw, SkBaseDevice* device,
                             int x, int y, const SkPaint& paint) {
    // clear of the source device must occur before CHECK_SHOULD_DRAW
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawDevice", fContext);
    SkGpuDevice* dev = static_cast<SkGpuDevice*>(device);

    // TODO: If the source device covers the whole of this device, we could
    // omit fNeedsClear -related flushing.
    // TODO: if source needs clear, we could maybe omit the draw fully.

    // drawDevice is defined to be in device coords.
    CHECK_SHOULD_DRAW(draw);

    GrRenderTarget* devRT = dev->accessRenderTarget();
    GrTexture* devTex;
    if (NULL == (devTex = devRT->asTexture())) {
>>>>>>> miniblink49
        return;
    }

    const SkImageInfo ii = dev->imageInfo();
    int w = ii.width();
    int h = ii.height();

<<<<<<< HEAD
    SkASSERT(!paint.getImageFilter());

    GrPaint grPaint;
    sk_sp<GrFragmentProcessor> fp(GrSimpleTextureEffect::Make(devTex.get(), SkMatrix::I()));
    if (GrPixelConfigIsAlphaOnly(devTex->config())) {
        // Can this happen?
        fp = GrFragmentProcessor::MulOutputByInputUnpremulColor(std::move(fp));
    } else {
        fp = GrFragmentProcessor::MulOutputByInputAlpha(std::move(fp));
    }

    if (!SkPaintToGrPaintReplaceShader(this->context(), paint, std::move(fp),
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
=======
    SkImageFilter* filter = paint.getImageFilter();
    // This bitmap will own the filtered result as a texture.
    SkBitmap filteredBitmap;

    if (filter) {
        SkIPoint offset = SkIPoint::Make(0, 0);
        SkMatrix matrix(*draw.fMatrix);
        matrix.postTranslate(SkIntToScalar(-x), SkIntToScalar(-y));
        SkIRect clipBounds = SkIRect::MakeWH(devTex->width(), devTex->height());
        // This cache is transient, and is freed (along with all its contained
        // textures) when it goes out of scope.
        SkAutoTUnref<SkImageFilter::Cache> cache(getImageFilterCache());
        SkImageFilter::Context ctx(matrix, clipBounds, cache);
        if (this->filterTexture(fContext, devTex, device->width(), device->height(),
                                filter, ctx, &filteredBitmap, &offset)) {
            devTex = filteredBitmap.getTexture();
            w = filteredBitmap.width();
            h = filteredBitmap.height();
            x += offset.fX;
            y += offset.fY;
        } else {
            return;
        }
    }

    GrPaint grPaint;
    grPaint.addColorTextureProcessor(devTex, SkMatrix::I());

    if (!SkPaint2GrPaintNoShader(this->context(), fRenderTarget, paint,
                                 SkColor2GrColorJustAlpha(paint.getColor()), false, &grPaint)) {
>>>>>>> miniblink49
        return;
    }

    SkRect dstRect = SkRect::MakeXYWH(SkIntToScalar(x),
<<<<<<< HEAD
        SkIntToScalar(y),
        SkIntToScalar(w),
        SkIntToScalar(h));
=======
                                      SkIntToScalar(y),
                                      SkIntToScalar(w),
                                      SkIntToScalar(h));
>>>>>>> miniblink49

    // The device being drawn may not fill up its texture (e.g. saveLayer uses approximate
    // scratch texture).
    SkRect srcRect = SkRect::MakeWH(SK_Scalar1 * w / devTex->width(),
<<<<<<< HEAD
        SK_Scalar1 * h / devTex->height());

    fDrawContext->fillRectToRect(fClip, grPaint, SkMatrix::I(), dstRect, srcRect);
}

void SkGpuDevice::drawImage(const SkDraw& draw, const SkImage* image, SkScalar x, SkScalar y,
    const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    SkMatrix viewMatrix = *draw.fMatrix;
    viewMatrix.preTranslate(x, y);
    if (as_IB(image)->peekTexture()) {
        CHECK_SHOULD_DRAW(draw);
        GrImageTextureAdjuster adjuster(as_IB(image));
        this->drawTextureProducer(&adjuster, nullptr, nullptr, SkCanvas::kFast_SrcRectConstraint,
            viewMatrix, fClip, paint);
        return;
    } else {
        SkBitmap bm;
        if (this->shouldTileImage(image, nullptr, SkCanvas::kFast_SrcRectConstraint,
                paint.getFilterQuality(), *draw.fMatrix)) {
            // only support tiling as bitmap at the moment, so force raster-version
            if (!as_IB(image)->getROPixels(&bm)) {
                return;
            }
            this->drawBitmap(draw, bm, SkMatrix::MakeTrans(x, y), paint);
        } else if (SkImageCacherator* cacher = as_IB(image)->peekCacherator()) {
            CHECK_SHOULD_DRAW(draw);
            GrImageTextureMaker maker(fContext, cacher, image, SkImage::kAllow_CachingHint);
            this->drawTextureProducer(&maker, nullptr, nullptr, SkCanvas::kFast_SrcRectConstraint,
                viewMatrix, fClip, paint);
        } else if (as_IB(image)->getROPixels(&bm)) {
            this->drawBitmap(draw, bm, SkMatrix::MakeTrans(x, y), paint);
        }
=======
                                    SK_Scalar1 * h / devTex->height());

    fDrawContext->drawNonAARectToRect(fRenderTarget, fClip, grPaint, SkMatrix::I(), dstRect,
                                      srcRect);
}

bool SkGpuDevice::canHandleImageFilter(const SkImageFilter* filter) {
    return filter->canFilterImageGPU();
}

bool SkGpuDevice::filterImage(const SkImageFilter* filter, const SkBitmap& src,
                              const SkImageFilter::Context& ctx,
                              SkBitmap* result, SkIPoint* offset) {
    // want explicitly our impl, so guard against a subclass of us overriding it
    if (!this->SkGpuDevice::canHandleImageFilter(filter)) {
        return false;
    }

    SkAutoLockPixels alp(src, !src.getTexture());
    if (!src.getTexture() && !src.readyToDraw()) {
        return false;
    }

    GrTexture* texture;
    // We assume here that the filter will not attempt to tile the src. Otherwise, this cache lookup
    // must be pushed upstack.
    AutoBitmapTexture abt(fContext, src, NULL, &texture);
    if (!texture) {
        return false;
    }

    return this->filterTexture(fContext, texture, src.width(), src.height(),
                               filter, ctx, result, offset);
}

static bool wrap_as_bm(const SkImage* image, SkBitmap* bm) {
    GrTexture* tex = as_IB(image)->getTexture();
    if (tex) {
        GrWrapTextureInBitmap(tex, image->width(), image->height(), image->isOpaque(), bm);
        return true;
    } else {
        return as_IB(image)->getROPixels(bm);
    }
}

void SkGpuDevice::drawImage(const SkDraw& draw, const SkImage* image, SkScalar x, SkScalar y,
                            const SkPaint& paint) {
    SkBitmap bm;
    if (wrap_as_bm(image, &bm)) {
        this->drawBitmap(draw, bm, SkMatrix::MakeTrans(x, y), paint);
>>>>>>> miniblink49
    }
}

void SkGpuDevice::drawImageRect(const SkDraw& draw, const SkImage* image, const SkRect* src,
<<<<<<< HEAD
    const SkRect& dst, const SkPaint& paint,
    SkCanvas::SrcRectConstraint constraint)
{
    ASSERT_SINGLE_OWNER
    if (as_IB(image)->peekTexture()) {
        CHECK_SHOULD_DRAW(draw);
        GrImageTextureAdjuster adjuster(as_IB(image));
        this->drawTextureProducer(&adjuster, src, &dst, constraint, *draw.fMatrix, fClip, paint);
        return;
    }
    SkBitmap bm;
    SkMatrix totalMatrix = *draw.fMatrix;
    totalMatrix.preScale(dst.width() / (src ? src->width() : image->width()),
        dst.height() / (src ? src->height() : image->height()));
    if (this->shouldTileImage(image, src, constraint, paint.getFilterQuality(), totalMatrix)) {
        // only support tiling as bitmap at the moment, so force raster-version
        if (!as_IB(image)->getROPixels(&bm)) {
            return;
        }
        this->drawBitmapRect(draw, bm, src, dst, paint, constraint);
    } else if (SkImageCacherator* cacher = as_IB(image)->peekCacherator()) {
        CHECK_SHOULD_DRAW(draw);
        GrImageTextureMaker maker(fContext, cacher, image, SkImage::kAllow_CachingHint);
        this->drawTextureProducer(&maker, src, &dst, constraint, *draw.fMatrix, fClip, paint);
    } else if (as_IB(image)->getROPixels(&bm)) {
        this->drawBitmapRect(draw, bm, src, dst, paint, constraint);
    }
}

void SkGpuDevice::drawProducerNine(const SkDraw& draw, GrTextureProducer* producer,
    const SkIRect& center, const SkRect& dst, const SkPaint& paint)
{
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawProducerNine", fContext);

    CHECK_SHOULD_DRAW(draw);

    bool useFallback = paint.getMaskFilter() || paint.isAntiAlias() || fDrawContext->isUnifiedMultisampled();
    bool doBicubic;
    GrTextureParams::FilterMode textureFilterMode = GrSkFilterQualityToGrFilterMode(paint.getFilterQuality(), *draw.fMatrix, SkMatrix::I(),
        &doBicubic);
    if (useFallback || doBicubic || GrTextureParams::kNone_FilterMode != textureFilterMode) {
        SkNinePatchIter iter(producer->width(), producer->height(), center, dst);

        SkRect srcR, dstR;
        while (iter.next(&srcR, &dstR)) {
            this->drawTextureProducer(producer, &srcR, &dstR, SkCanvas::kStrict_SrcRectConstraint,
                *draw.fMatrix, fClip, paint);
        }
        return;
    }

    static const GrTextureParams::FilterMode kMode = GrTextureParams::kNone_FilterMode;
    bool gammaCorrect = this->surfaceProps().isGammaCorrect();
    SkSourceGammaTreatment gammaTreatment = gammaCorrect
        ? SkSourceGammaTreatment::kRespect
        : SkSourceGammaTreatment::kIgnore;
    sk_sp<GrFragmentProcessor> fp(
        producer->createFragmentProcessor(SkMatrix::I(),
            SkRect::MakeIWH(producer->width(), producer->height()),
            GrTextureProducer::kNo_FilterConstraint, true,
            &kMode, gammaTreatment));
    GrPaint grPaint;
    if (!SkPaintToGrPaintWithTexture(this->context(), paint, *draw.fMatrix, std::move(fp),
            producer->isAlphaOnly(), gammaCorrect, &grPaint)) {
        return;
    }

    fDrawContext->drawImageNine(fClip, grPaint, *draw.fMatrix, producer->width(),
        producer->height(), center, dst);
}

void SkGpuDevice::drawImageNine(const SkDraw& draw, const SkImage* image,
    const SkIRect& center, const SkRect& dst, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    if (as_IB(image)->peekTexture()) {
        GrImageTextureAdjuster adjuster(as_IB(image));
        this->drawProducerNine(draw, &adjuster, center, dst, paint);
    } else {
        SkBitmap bm;
        if (SkImageCacherator* cacher = as_IB(image)->peekCacherator()) {
            GrImageTextureMaker maker(fContext, cacher, image, SkImage::kAllow_CachingHint);
            this->drawProducerNine(draw, &maker, center, dst, paint);
        } else if (as_IB(image)->getROPixels(&bm)) {
            this->drawBitmapNine(draw, bm, center, dst, paint);
        }
    }
}

void SkGpuDevice::drawBitmapNine(const SkDraw& draw, const SkBitmap& bitmap, const SkIRect& center,
    const SkRect& dst, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    if (bitmap.getTexture()) {
        GrBitmapTextureAdjuster adjuster(&bitmap);
        this->drawProducerNine(draw, &adjuster, center, dst, paint);
    } else {
        GrBitmapTextureMaker maker(fContext, bitmap);
        this->drawProducerNine(draw, &maker, center, dst, paint);
=======
                                const SkRect& dst, const SkPaint& paint) {
    SkBitmap bm;
    if (wrap_as_bm(image, &bm)) {
        this->drawBitmapRect(draw, bm, src, dst, paint, SkCanvas::kNone_DrawBitmapRectFlag);
>>>>>>> miniblink49
    }
}

///////////////////////////////////////////////////////////////////////////////

// must be in SkCanvas::VertexMode order
static const GrPrimitiveType gVertexMode2PrimitiveType[] = {
    kTriangles_GrPrimitiveType,
    kTriangleStrip_GrPrimitiveType,
    kTriangleFan_GrPrimitiveType,
};

void SkGpuDevice::drawVertices(const SkDraw& draw, SkCanvas::VertexMode vmode,
<<<<<<< HEAD
    int vertexCount, const SkPoint vertices[],
    const SkPoint texs[], const SkColor colors[],
    SkXfermode* xmode,
    const uint16_t indices[], int indexCount,
    const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    CHECK_SHOULD_DRAW(draw);
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawVertices", fContext);

    // If both textures and vertex-colors are nullptr, strokes hairlines with the paint's color.
    if ((nullptr == texs || nullptr == paint.getShader()) && nullptr == colors) {

        texs = nullptr;
=======
                              int vertexCount, const SkPoint vertices[],
                              const SkPoint texs[], const SkColor colors[],
                              SkXfermode* xmode,
                              const uint16_t indices[], int indexCount,
                              const SkPaint& paint) {
    CHECK_SHOULD_DRAW(draw);
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawVertices", fContext);

    const uint16_t* outIndices;
    SkAutoTDeleteArray<uint16_t> outAlloc(NULL);
    GrPrimitiveType primType;
    GrPaint grPaint;

    // If both textures and vertex-colors are NULL, strokes hairlines with the paint's color.
    if ((NULL == texs || NULL == paint.getShader()) && NULL == colors) {

        texs = NULL;
>>>>>>> miniblink49

        SkPaint copy(paint);
        copy.setStyle(SkPaint::kStroke_Style);
        copy.setStrokeWidth(0);

<<<<<<< HEAD
        GrPaint grPaint;
        // we ignore the shader if texs is null.
        if (!SkPaintToGrPaintNoShader(this->context(), copy,
                this->surfaceProps().isGammaCorrect(), &grPaint)) {
            return;
        }

        int triangleCount = 0;
        int n = (nullptr == indices) ? vertexCount : indexCount;
        switch (vmode) {
        case SkCanvas::kTriangles_VertexMode:
            triangleCount = n / 3;
            break;
        case SkCanvas::kTriangleStrip_VertexMode:
        case SkCanvas::kTriangleFan_VertexMode:
            triangleCount = n - 2;
            break;
        }

        VertState state(vertexCount, indices, indexCount);
=======
        // we ignore the shader if texs is null.
        if (!SkPaint2GrPaintNoShader(this->context(), fRenderTarget, copy,
                                     SkColor2GrColor(copy.getColor()), NULL == colors, &grPaint)) {
            return;
        }

        primType = kLines_GrPrimitiveType;
        int triangleCount = 0;
        int n = (NULL == indices) ? vertexCount : indexCount;
        switch (vmode) {
            case SkCanvas::kTriangles_VertexMode:
                triangleCount = n / 3;
                break;
            case SkCanvas::kTriangleStrip_VertexMode:
            case SkCanvas::kTriangleFan_VertexMode:
                triangleCount = n - 2;
                break;
        }

        VertState       state(vertexCount, indices, indexCount);
>>>>>>> miniblink49
        VertState::Proc vertProc = state.chooseProc(vmode);

        //number of indices for lines per triangle with kLines
        indexCount = triangleCount * 6;

<<<<<<< HEAD
        SkAutoTDeleteArray<uint16_t> lineIndices(new uint16_t[indexCount]);
        int i = 0;
        while (vertProc(&state)) {
            lineIndices[i] = state.f0;
            lineIndices[i + 1] = state.f1;
            lineIndices[i + 2] = state.f1;
            lineIndices[i + 3] = state.f2;
            lineIndices[i + 4] = state.f2;
            lineIndices[i + 5] = state.f0;
            i += 6;
        }
        fDrawContext->drawVertices(fClip,
            grPaint,
            *draw.fMatrix,
            kLines_GrPrimitiveType,
            vertexCount,
            vertices,
            texs,
            colors,
            lineIndices.get(),
            indexCount);
        return;
    }

    GrPrimitiveType primType = gVertexMode2PrimitiveType[vmode];

    SkAutoSTMalloc<128, GrColor> convertedColors(0);
    if (colors) {
        // need to convert byte order and from non-PM to PM. TODO: Keep unpremul until after
        // interpolation.
        convertedColors.reset(vertexCount);
        for (int i = 0; i < vertexCount; ++i) {
            convertedColors[i] = SkColorToPremulGrColor(colors[i]);
        }
        colors = convertedColors.get();
    }
    GrPaint grPaint;
    if (texs && paint.getShader()) {
        if (colors) {
            // When there are texs and colors the shader and colors are combined using xmode. A null
            // xmode is defined to mean modulate.
            SkXfermode::Mode colorMode;
            if (xmode) {
                if (!xmode->asMode(&colorMode)) {
                    return;
                }
            } else {
                colorMode = SkXfermode::kModulate_Mode;
            }
            if (!SkPaintToGrPaintWithXfermode(this->context(), paint, *draw.fMatrix, colorMode,
                    false, this->surfaceProps().isGammaCorrect(),
                    &grPaint)) {
                return;
            }
        } else {
            // We have a shader, but no colors to blend it against.
            if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
                    this->surfaceProps().isGammaCorrect(), &grPaint)) {
                return;
            }
        }
    } else {
        if (colors) {
            // We have colors, but either have no shader or no texture coords (which implies that
            // we should ignore the shader).
            if (!SkPaintToGrPaintWithPrimitiveColor(this->context(), paint,
                    this->surfaceProps().isGammaCorrect(),
                    &grPaint)) {
                return;
            }
        } else {
            // No colors and no shaders. Just draw with the paint color.
            if (!SkPaintToGrPaintNoShader(this->context(), paint,
                    this->surfaceProps().isGammaCorrect(), &grPaint)) {
                return;
            }
        }
    }

    fDrawContext->drawVertices(fClip,
        grPaint,
        *draw.fMatrix,
        primType,
        vertexCount,
        vertices,
        texs,
        colors,
        indices,
        indexCount);
=======
        outAlloc.reset(SkNEW_ARRAY(uint16_t, indexCount));
        outIndices = outAlloc.get();
        uint16_t* auxIndices = outAlloc.get();
        int i = 0;
        while (vertProc(&state)) {
            auxIndices[i]     = state.f0;
            auxIndices[i + 1] = state.f1;
            auxIndices[i + 2] = state.f1;
            auxIndices[i + 3] = state.f2;
            auxIndices[i + 4] = state.f2;
            auxIndices[i + 5] = state.f0;
            i += 6;
        }
    } else {
        outIndices = indices;
        primType = gVertexMode2PrimitiveType[vmode];

        if (NULL == texs || NULL == paint.getShader()) {
            if (!SkPaint2GrPaintNoShader(this->context(), fRenderTarget, paint,
                                         SkColor2GrColor(paint.getColor()),
                                         NULL == colors, &grPaint)) {
                return;
            }
        } else {
            if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix,
                                 NULL == colors, &grPaint)) {
                return;
            }
        }
    }

#if 0
    if (xmode && texs && colors) {
        if (!SkXfermode::IsMode(xmode, SkXfermode::kModulate_Mode)) {
            SkDebugf("Unsupported vertex-color/texture xfer mode.\n");
            return;
        }
    }
#endif

    SkAutoSTMalloc<128, GrColor> convertedColors(0);
    if (colors) {
        // need to convert byte order and from non-PM to PM
        convertedColors.reset(vertexCount);
        SkColor color;
        for (int i = 0; i < vertexCount; ++i) {
            color = colors[i];
            if (paint.getAlpha() != 255) {
                color = SkColorSetA(color, SkMulDiv255Round(SkColorGetA(color), paint.getAlpha()));
            }
            convertedColors[i] = SkColor2GrColor(color);
        }
        colors = convertedColors.get();
    }
    fDrawContext->drawVertices(fRenderTarget,
                               fClip,
                               grPaint,
                               *draw.fMatrix,
                               primType,
                               vertexCount,
                               vertices,
                               texs,
                               colors,
                               outIndices,
                               indexCount);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkGpuDevice::drawAtlas(const SkDraw& draw, const SkImage* atlas, const SkRSXform xform[],
    const SkRect texRect[], const SkColor colors[], int count,
    SkXfermode::Mode mode, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    if (paint.isAntiAlias()) {
        this->INHERITED::drawAtlas(draw, atlas, xform, texRect, colors, count, mode, paint);
        return;
    }

    CHECK_SHOULD_DRAW(draw);
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawText", fContext);

    SkPaint p(paint);
    p.setShader(atlas->makeShader(SkShader::kClamp_TileMode, SkShader::kClamp_TileMode));

    GrPaint grPaint;
    if (colors) {
        if (!SkPaintToGrPaintWithXfermode(this->context(), p, *draw.fMatrix, mode, true,
                this->surfaceProps().isGammaCorrect(), &grPaint)) {
            return;
        }
    } else {
        if (!SkPaintToGrPaint(this->context(), p, *draw.fMatrix,
                this->surfaceProps().isGammaCorrect(), &grPaint)) {
            return;
        }
    }

    SkDEBUGCODE(this->validate();)
        fDrawContext->drawAtlas(fClip, grPaint, *draw.fMatrix, count, xform, texRect, colors);
=======
static void append_quad_indices(uint16_t indices[], int quadIndex) {
    int i = quadIndex * 4;
    indices[0] = i + 0; indices[1] = i + 1; indices[2] = i + 2;
    indices[3] = i + 2; indices[4] = i + 3; indices[5] = i + 0;
}

void SkGpuDevice::drawAtlas(const SkDraw& d, const SkImage* atlas, const SkRSXform xform[],
                            const SkRect texRect[], const SkColor colors[], int count,
                            SkXfermode::Mode mode, const SkPaint& paint) {
    if (paint.isAntiAlias()) {
        this->INHERITED::drawAtlas(d, atlas, xform, texRect, colors, count, mode, paint);
        return;
    }

    SkPaint p(paint);
    p.setShader(atlas->newShader(SkShader::kClamp_TileMode, SkShader::kClamp_TileMode))->unref();

    const int vertCount = count * 4;
    const int indexCount = count * 6;
    SkAutoTMalloc<SkPoint> vertStorage(vertCount * 2);
    SkPoint* verts = vertStorage.get();
    SkPoint* texs = verts + vertCount;
    SkAutoTMalloc<uint16_t> indexStorage(indexCount);
    uint16_t* indices = indexStorage.get();
    SkAutoTUnref<SkXfermode> xfer(SkXfermode::Create(mode));

    for (int i = 0; i < count; ++i) {
        xform[i].toQuad(texRect[i].width(), texRect[i].height(), verts);
        texRect[i].toQuad(texs);
        append_quad_indices(indices, i);
        verts += 4;
        texs += 4;
        indices += 6;
    }

    verts = vertStorage.get();
    texs = verts + vertCount;
    indices = indexStorage.get();
    this->drawVertices(d, SkCanvas::kTriangles_VertexMode, vertCount, verts, texs, colors, xfer,
                       indices, indexCount, p);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

void SkGpuDevice::drawText(const SkDraw& draw, const void* text,
<<<<<<< HEAD
    size_t byteLength, SkScalar x, SkScalar y,
    const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    CHECK_SHOULD_DRAW(draw);
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawText", fContext);

    GrPaint grPaint;
    if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
=======
                           size_t byteLength, SkScalar x, SkScalar y,
                           const SkPaint& paint) {
    CHECK_SHOULD_DRAW(draw);
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawText", fContext);

    GrPaint grPaint;
    if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix, true, &grPaint)) {
>>>>>>> miniblink49
        return;
    }

    SkDEBUGCODE(this->validate();)

<<<<<<< HEAD
        fDrawContext->drawText(fClip, grPaint, paint, *draw.fMatrix,
            (const char*)text, byteLength, x, y, draw.fRC->getBounds());
}

void SkGpuDevice::drawPosText(const SkDraw& draw, const void* text, size_t byteLength,
    const SkScalar pos[], int scalarsPerPos,
    const SkPoint& offset, const SkPaint& paint)
{
    ASSERT_SINGLE_OWNER
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawPosText", fContext);
    CHECK_SHOULD_DRAW(draw);

    GrPaint grPaint;
    if (!SkPaintToGrPaint(this->context(), paint, *draw.fMatrix,
            this->surfaceProps().isGammaCorrect(), &grPaint)) {
=======
    fDrawContext->drawText(fRenderTarget, fClip, grPaint, paint, *draw.fMatrix,
                           (const char *)text, byteLength, x, y, draw.fClip->getBounds());
}

void SkGpuDevice::drawPosText(const SkDraw& draw, const void* text, size_t byteLength,
                              const SkScalar pos[], int scalarsPerPos,
                              const SkPoint& offset, const SkPaint& paint) {
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawPosText", fContext);
    CHECK_SHOULD_DRAW(draw);

    GrPaint grPaint;
    if (!SkPaint2GrPaint(this->context(), fRenderTarget, paint, *draw.fMatrix, true, &grPaint)) {
>>>>>>> miniblink49
        return;
    }

    SkDEBUGCODE(this->validate();)

<<<<<<< HEAD
        fDrawContext->drawPosText(fClip, grPaint, paint, *draw.fMatrix,
            (const char*)text, byteLength, pos, scalarsPerPos, offset,
            draw.fRC->getBounds());
}

void SkGpuDevice::drawTextBlob(const SkDraw& draw, const SkTextBlob* blob, SkScalar x, SkScalar y,
    const SkPaint& paint, SkDrawFilter* drawFilter)
{
    ASSERT_SINGLE_OWNER
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice", "drawTextBlob", fContext);
=======
    fDrawContext->drawPosText(fRenderTarget, fClip, grPaint, paint, *draw.fMatrix,
                              (const char *)text, byteLength, pos, scalarsPerPos, offset,
                              draw.fClip->getBounds());
}

void SkGpuDevice::drawTextBlob(const SkDraw& draw, const SkTextBlob* blob, SkScalar x, SkScalar y,
                               const SkPaint& paint, SkDrawFilter* drawFilter) {
    GR_CREATE_TRACE_MARKER_CONTEXT("SkGpuDevice::drawTextBlob", fContext);
>>>>>>> miniblink49
    CHECK_SHOULD_DRAW(draw);

    SkDEBUGCODE(this->validate();)

<<<<<<< HEAD
        fDrawContext->drawTextBlob(fClip, paint, *draw.fMatrix,
            blob, x, y, drawFilter, draw.fRC->getBounds());
=======
    fDrawContext->drawTextBlob(fRenderTarget, fClip, paint, *draw.fMatrix,
                               blob, x, y, drawFilter, draw.fClip->getBounds());
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool SkGpuDevice::onShouldDisableLCD(const SkPaint& paint) const
{
    return GrTextUtils::ShouldDisableLCD(paint);
}

void SkGpuDevice::flush()
{
    ASSERT_SINGLE_OWNER

=======
bool SkGpuDevice::onShouldDisableLCD(const SkPaint& paint) const {
    return GrTextContext::ShouldDisableLCD(paint);
}

void SkGpuDevice::flush() {
    DO_DEFERRED_CLEAR();
>>>>>>> miniblink49
    fRenderTarget->prepareForExternalIO();
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkBaseDevice* SkGpuDevice::onCreateDevice(const CreateInfo& cinfo, const SkPaint*)
{
    ASSERT_SINGLE_OWNER

    SkSurfaceProps props(this->surfaceProps().flags(), cinfo.fPixelGeometry);

    // layers are never drawn in repeat modes, so we can request an approx
    // match and ignore any padding.
    SkBackingFit fit = kNever_TileUsage == cinfo.fTileUsage ? SkBackingFit::kApprox
                                                            : SkBackingFit::kExact;

    sk_sp<GrDrawContext> dc(fContext->newDrawContext(fit,
        cinfo.fInfo.width(), cinfo.fInfo.height(),
        fDrawContext->config(),
        fDrawContext->desc().fSampleCnt,
        kDefault_GrSurfaceOrigin,
        &props));
    if (!dc) {
        SkErrorInternals::SetError(kInternalError_SkError,
            "---- failed to create gpu device texture [%d %d]\n",
            cinfo.fInfo.width(), cinfo.fInfo.height());
        return nullptr;
    }

    // Skia's convention is to only clear a device if it is non-opaque.
    InitContents init = cinfo.fInfo.isOpaque() ? kUninit_InitContents : kClear_InitContents;

    return SkGpuDevice::Make(std::move(dc),
        cinfo.fInfo.width(), cinfo.fInfo.height(),
        init)
        .release();
}

sk_sp<SkSurface> SkGpuDevice::makeSurface(const SkImageInfo& info, const SkSurfaceProps& props)
{
    ASSERT_SINGLE_OWNER
    // TODO: Change the signature of newSurface to take a budgeted parameter.
    static const SkBudgeted kBudgeted = SkBudgeted::kNo;
    return SkSurface::MakeRenderTarget(fContext, kBudgeted, info, fDrawContext->desc().fSampleCnt,
        &props);
}

bool SkGpuDevice::EXPERIMENTAL_drawPicture(SkCanvas* mainCanvas, const SkPicture* mainPicture,
    const SkMatrix* matrix, const SkPaint* paint)
{
    ASSERT_SINGLE_OWNER
#ifndef SK_IGNORE_GPU_LAYER_HOISTING
    // todo: should handle this natively
    if (paint || (kRGBA_8888_SkColorType != mainCanvas->imageInfo().colorType() && kBGRA_8888_SkColorType != mainCanvas->imageInfo().colorType())) {
        return false;
    }

    const SkBigPicture::AccelData* data = nullptr;
=======
SkBaseDevice* SkGpuDevice::onCreateDevice(const CreateInfo& cinfo, const SkPaint*) {
    GrSurfaceDesc desc;
    desc.fConfig = fRenderTarget->config();
    desc.fFlags = kRenderTarget_GrSurfaceFlag;
    desc.fWidth = cinfo.fInfo.width();
    desc.fHeight = cinfo.fInfo.height();
    desc.fSampleCnt = fRenderTarget->desc().fSampleCnt;

    SkAutoTUnref<GrTexture> texture;
    // Skia's convention is to only clear a device if it is non-opaque.
    InitContents init = cinfo.fInfo.isOpaque() ? kUninit_InitContents : kClear_InitContents;

    // layers are never draw in repeat modes, so we can request an approx
    // match and ignore any padding.
    const GrTextureProvider::ScratchTexMatch match = (kNever_TileUsage == cinfo.fTileUsage) ?
                                                  GrTextureProvider::kApprox_ScratchTexMatch :
                                                  GrTextureProvider::kExact_ScratchTexMatch;
    texture.reset(fContext->textureProvider()->refScratchTexture(desc, match));

    if (texture) {
        SkSurfaceProps props(this->surfaceProps().flags(), cinfo.fPixelGeometry);
        return SkGpuDevice::Create(
            texture->asRenderTarget(), cinfo.fInfo.width(), cinfo.fInfo.height(), &props, init);
    } else {
        SkErrorInternals::SetError( kInternalError_SkError,
                                    "---- failed to create gpu device texture [%d %d]\n",
                                    cinfo.fInfo.width(), cinfo.fInfo.height());
        return NULL;
    }
}

SkSurface* SkGpuDevice::newSurface(const SkImageInfo& info, const SkSurfaceProps& props) {
    // TODO: Change the signature of newSurface to take a budgeted parameter.
    static const SkSurface::Budgeted kBudgeted = SkSurface::kNo_Budgeted;
    return SkSurface::NewRenderTarget(fContext, kBudgeted, info, fRenderTarget->desc().fSampleCnt,
                                      &props);
}

bool SkGpuDevice::EXPERIMENTAL_drawPicture(SkCanvas* mainCanvas, const SkPicture* mainPicture,
                                           const SkMatrix* matrix, const SkPaint* paint) {
#ifndef SK_IGNORE_GPU_LAYER_HOISTING
    // todo: should handle this natively
    if (paint) {
        return false;
    }

    const SkBigPicture::AccelData* data = NULL;
>>>>>>> miniblink49
    if (const SkBigPicture* bp = mainPicture->asSkBigPicture()) {
        data = bp->accelData();
    }
    if (!data) {
        return false;
    }

<<<<<<< HEAD
    const SkLayerInfo* gpuData = static_cast<const SkLayerInfo*>(data);
=======
    const SkLayerInfo *gpuData = static_cast<const SkLayerInfo*>(data);
>>>>>>> miniblink49
    if (0 == gpuData->numBlocks()) {
        return false;
    }

    SkTDArray<GrHoistedLayer> atlasedNeedRendering, atlasedRecycled;

    SkIRect iBounds;
    if (!mainCanvas->getClipDeviceBounds(&iBounds)) {
        return false;
    }

    SkRect clipBounds = SkRect::Make(iBounds);

    SkMatrix initialMatrix = mainCanvas->getTotalMatrix();

<<<<<<< HEAD
    GrLayerHoister::Begin(fContext);

    GrLayerHoister::FindLayersToAtlas(fContext, mainPicture,
        initialMatrix,
        clipBounds,
        &atlasedNeedRendering, &atlasedRecycled,
        fDrawContext->numColorSamples());
=======
    GrLayerHoister::FindLayersToAtlas(fContext, mainPicture,
                                      initialMatrix,
                                      clipBounds,
                                      &atlasedNeedRendering, &atlasedRecycled,
                                      fRenderTarget->numColorSamples());
>>>>>>> miniblink49

    GrLayerHoister::DrawLayersToAtlas(fContext, atlasedNeedRendering);

    SkTDArray<GrHoistedLayer> needRendering, recycled;

    SkAutoCanvasMatrixPaint acmp(mainCanvas, matrix, paint, mainPicture->cullRect());

    GrLayerHoister::FindLayersToHoist(fContext, mainPicture,
<<<<<<< HEAD
        initialMatrix,
        clipBounds,
        &needRendering, &recycled,
        fDrawContext->numColorSamples());
=======
                                      initialMatrix,
                                      clipBounds,
                                      &needRendering, &recycled,
                                      fRenderTarget->numColorSamples());
>>>>>>> miniblink49

    GrLayerHoister::DrawLayers(fContext, needRendering);

    // Render the entire picture using new layers
    GrRecordReplaceDraw(mainPicture, mainCanvas, fContext->getLayerCache(),
<<<<<<< HEAD
        initialMatrix, nullptr);
=======
                        initialMatrix, NULL);
>>>>>>> miniblink49

    GrLayerHoister::UnlockLayers(fContext, needRendering);
    GrLayerHoister::UnlockLayers(fContext, recycled);
    GrLayerHoister::UnlockLayers(fContext, atlasedNeedRendering);
    GrLayerHoister::UnlockLayers(fContext, atlasedRecycled);
<<<<<<< HEAD
    GrLayerHoister::End(fContext);
=======
>>>>>>> miniblink49

    return true;
#else
    return false;
#endif
}

<<<<<<< HEAD
SkImageFilterCache* SkGpuDevice::getImageFilterCache()
{
    ASSERT_SINGLE_OWNER
    // We always return a transient cache, so it is freed after each
    // filter traversal.
    return SkImageFilterCache::Create(kDefaultImageFilterCacheSize);
=======
SkImageFilter::Cache* SkGpuDevice::getImageFilterCache() {
    // We always return a transient cache, so it is freed after each
    // filter traversal.
    return SkImageFilter::Cache::Create(kDefaultImageFilterCacheSize);
>>>>>>> miniblink49
}

#endif
