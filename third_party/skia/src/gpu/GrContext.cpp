<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrContext.h"
<<<<<<< HEAD
#include "GrContextOptions.h"
#include "GrDrawContext.h"
#include "GrDrawingManager.h"
#include "GrLayerCache.h"
#include "GrResourceCache.h"
#include "GrResourceProvider.h"
#include "GrSoftwarePathRenderer.h"
#include "GrSurfacePriv.h"

#include "SkConfig8888.h"
#include "SkGrPriv.h"

#include "batches/GrCopySurfaceBatch.h"
#include "effects/GrConfigConversionEffect.h"
#include "effects/GrGammaEffect.h"
#include "text/GrTextBlobCache.h"

#define ASSERT_OWNED_RESOURCE(R) SkASSERT(!(R) || (R)->getContext() == this)
#define ASSERT_SINGLE_OWNER \
    SkDEBUGCODE(GrSingleOwner::AutoEnforce debug_SingleOwner(&fSingleOwner);)
#define RETURN_IF_ABANDONED                \
    if (fDrawingManager->wasAbandoned()) { \
        return;                            \
    }
#define RETURN_FALSE_IF_ABANDONED          \
    if (fDrawingManager->wasAbandoned()) { \
        return false;                      \
    }
#define RETURN_NULL_IF_ABANDONED           \
    if (fDrawingManager->wasAbandoned()) { \
        return nullptr;                    \
    }

////////////////////////////////////////////////////////////////////////////////

GrContext* GrContext::Create(GrBackend backend, GrBackendContext backendContext)
{
=======

#include "GrAARectRenderer.h"
#include "GrBatch.h"
#include "GrBatchFontCache.h"
#include "GrBatchTarget.h"
#include "GrBatchTest.h"
#include "GrCaps.h"
#include "GrContextOptions.h"
#include "GrDefaultGeoProcFactory.h"
#include "GrDrawContext.h"
#include "GrGpuResource.h"
#include "GrGpuResourcePriv.h"
#include "GrGpu.h"
#include "GrImmediateDrawTarget.h"
#include "GrIndexBuffer.h"
#include "GrInOrderDrawBuffer.h"
#include "GrLayerCache.h"
#include "GrOvalRenderer.h"
#include "GrPathRenderer.h"
#include "GrPathUtils.h"
#include "GrRenderTargetPriv.h"
#include "GrResourceCache.h"
#include "GrResourceProvider.h"
#include "GrSoftwarePathRenderer.h"
#include "GrStrokeInfo.h"
#include "GrSurfacePriv.h"
#include "GrTextBlobCache.h"
#include "GrTexturePriv.h"
#include "GrTraceMarker.h"
#include "GrTracing.h"
#include "GrVertices.h"
#include "SkDashPathPriv.h"
#include "SkConfig8888.h"
#include "SkGr.h"
#include "SkRRect.h"
#include "SkStrokeRec.h"
#include "SkSurfacePriv.h"
#include "SkTLazy.h"
#include "SkTLS.h"
#include "SkTraceEvent.h"

#include "effects/GrConfigConversionEffect.h"
#include "effects/GrDashingEffect.h"
#include "effects/GrSingleTextureEffect.h"

#define ASSERT_OWNED_RESOURCE(R) SkASSERT(!(R) || (R)->getContext() == this)
#define RETURN_IF_ABANDONED if (fDrawingMgr.abandoned()) { return; }
#define RETURN_FALSE_IF_ABANDONED if (fDrawingMgr.abandoned()) { return false; }
#define RETURN_NULL_IF_ABANDONED if (fDrawingMgr.abandoned()) { return NULL; }


////////////////////////////////////////////////////////////////////////////////

void GrContext::DrawingMgr::init(GrContext* context) {
    fContext = context;

#ifdef IMMEDIATE_MODE
    fDrawTarget = SkNEW_ARGS(GrImmediateDrawTarget, (context));
#else
    fDrawTarget = SkNEW_ARGS(GrInOrderDrawBuffer, (context));
#endif    
}

void GrContext::DrawingMgr::cleanup() {
    SkSafeSetNull(fDrawTarget);
    for (int i = 0; i < kNumPixelGeometries; ++i) {
        SkSafeSetNull(fDrawContext[i][0]);
        SkSafeSetNull(fDrawContext[i][1]);
    }
}

GrContext::DrawingMgr::~DrawingMgr() {
    this->cleanup();
}

void GrContext::DrawingMgr::abandon() {
    SkSafeSetNull(fDrawTarget);
    for (int i = 0; i < kNumPixelGeometries; ++i) {
        for (int j = 0; j < kNumDFTOptions; ++j) {
            if (fDrawContext[i][j]) {
                SkSafeSetNull(fDrawContext[i][j]->fDrawTarget);
                SkSafeSetNull(fDrawContext[i][j]);
            }
        }
    }
}

void GrContext::DrawingMgr::purgeResources() {
    if (fDrawTarget) {
        fDrawTarget->purgeResources();
    }
}

void GrContext::DrawingMgr::reset() {
    if (fDrawTarget) {
        fDrawTarget->reset();
    }
}

void GrContext::DrawingMgr::flush() {
    if (fDrawTarget) {
        fDrawTarget->flush();
    }
}

GrDrawContext* GrContext::DrawingMgr::drawContext(const SkSurfaceProps* surfaceProps) { 
    if (this->abandoned()) {
        return NULL;
    }

    const SkSurfaceProps props(SkSurfacePropsCopyOrDefault(surfaceProps));

    SkASSERT(props.pixelGeometry() < kNumPixelGeometries);
    if (!fDrawContext[props.pixelGeometry()][props.isUseDistanceFieldFonts()]) {
        fDrawContext[props.pixelGeometry()][props.isUseDistanceFieldFonts()] =
                SkNEW_ARGS(GrDrawContext, (fContext, fDrawTarget, props));
    }

    return fDrawContext[props.pixelGeometry()][props.isUseDistanceFieldFonts()]; 
}

////////////////////////////////////////////////////////////////////////////////


GrContext* GrContext::Create(GrBackend backend, GrBackendContext backendContext) {
>>>>>>> miniblink49
    GrContextOptions defaultOptions;
    return Create(backend, backendContext, defaultOptions);
}

GrContext* GrContext::Create(GrBackend backend, GrBackendContext backendContext,
<<<<<<< HEAD
    const GrContextOptions& options)
{
    GrContext* context = new GrContext;
=======
                             const GrContextOptions& options) {
    GrContext* context = SkNEW(GrContext);
>>>>>>> miniblink49

    if (context->init(backend, backendContext, options)) {
        return context;
    } else {
        context->unref();
<<<<<<< HEAD
        return nullptr;
=======
        return NULL;
>>>>>>> miniblink49
    }
}

static int32_t gNextID = 1;
<<<<<<< HEAD
static int32_t next_id()
{
=======
static int32_t next_id() {
>>>>>>> miniblink49
    int32_t id;
    do {
        id = sk_atomic_inc(&gNextID);
    } while (id == SK_InvalidGenID);
    return id;
}

<<<<<<< HEAD
GrContext::GrContext()
    : fUniqueID(next_id())
{
    fGpu = nullptr;
    fCaps = nullptr;
    fResourceCache = nullptr;
    fResourceProvider = nullptr;
    fBatchFontCache = nullptr;
=======
GrContext::GrContext() : fUniqueID(next_id()) {
    fGpu = NULL;
    fCaps = NULL;
    fResourceCache = NULL;
    fResourceProvider = NULL;
    fPathRendererChain = NULL;
    fSoftwarePathRenderer = NULL;
    fBatchFontCache = NULL;
>>>>>>> miniblink49
    fFlushToReduceCacheSize = false;
}

bool GrContext::init(GrBackend backend, GrBackendContext backendContext,
<<<<<<< HEAD
    const GrContextOptions& options)
{
    ASSERT_SINGLE_OWNER
=======
                     const GrContextOptions& options) {
>>>>>>> miniblink49
    SkASSERT(!fGpu);

    fGpu = GrGpu::Create(backend, backendContext, options, this);
    if (!fGpu) {
        return false;
    }
<<<<<<< HEAD
    this->initCommon(options);
    return true;
}

void GrContext::initCommon(const GrContextOptions& options)
{
    ASSERT_SINGLE_OWNER

    fCaps = SkRef(fGpu->caps());
    fResourceCache = new GrResourceCache(fCaps);
    fResourceCache->setOverBudgetCallback(OverBudgetCB, this);
    fResourceProvider = new GrResourceProvider(fGpu, fResourceCache, &fSingleOwner);

    fLayerCache.reset(new GrLayerCache(this));

    fDidTestPMConversions = false;

    GrDrawTarget::Options dtOptions;
    dtOptions.fClipBatchToBounds = options.fClipBatchToBounds;
    dtOptions.fDrawBatchBounds = options.fDrawBatchBounds;
    dtOptions.fMaxBatchLookback = options.fMaxBatchLookback;
    dtOptions.fMaxBatchLookahead = options.fMaxBatchLookahead;
    fDrawingManager.reset(new GrDrawingManager(this, dtOptions, &fSingleOwner));

    // GrBatchFontCache will eventually replace GrFontCache
    fBatchFontCache = new GrBatchFontCache(this);

    fTextBlobCache.reset(new GrTextBlobCache(TextBlobCacheOverBudgetCB, this));
}

GrContext::~GrContext()
{
    ASSERT_SINGLE_OWNER

=======
    this->initCommon();
    return true;
}

void GrContext::initCommon() {
    fCaps = SkRef(fGpu->caps());
    fResourceCache = SkNEW(GrResourceCache);
    fResourceCache->setOverBudgetCallback(OverBudgetCB, this);
    fResourceProvider = SkNEW_ARGS(GrResourceProvider, (fGpu, fResourceCache));

    fLayerCache.reset(SkNEW_ARGS(GrLayerCache, (this)));

    fDidTestPMConversions = false;

    fDrawingMgr.init(this);

    // GrBatchFontCache will eventually replace GrFontCache
    fBatchFontCache = SkNEW_ARGS(GrBatchFontCache, (this));

    fTextBlobCache.reset(SkNEW_ARGS(GrTextBlobCache, (TextBlobCacheOverBudgetCB, this)));
}

GrContext::~GrContext() {
>>>>>>> miniblink49
    if (!fGpu) {
        SkASSERT(!fCaps);
        return;
    }

    this->flush();

<<<<<<< HEAD
    fDrawingManager->cleanup();
=======
    fDrawingMgr.cleanup();
>>>>>>> miniblink49

    for (int i = 0; i < fCleanUpData.count(); ++i) {
        (*fCleanUpData[i].fFunc)(this, fCleanUpData[i].fInfo);
    }

<<<<<<< HEAD
    delete fResourceProvider;
    delete fResourceCache;
    delete fBatchFontCache;

    fGpu->unref();
    fCaps->unref();
}

GrContextThreadSafeProxy* GrContext::threadSafeProxy()
{
    if (!fThreadSafeProxy) {
        fThreadSafeProxy.reset(new GrContextThreadSafeProxy(fCaps, this->uniqueID()));
    }
    return SkRef(fThreadSafeProxy.get());
}

void GrContext::abandonContext()
{
    ASSERT_SINGLE_OWNER

    fResourceProvider->abandon();

    // Need to abandon the drawing manager first so all the render targets
    // will be released/forgotten before they too are abandoned.
    fDrawingManager->abandon();

=======
    SkDELETE(fResourceProvider);
    SkDELETE(fResourceCache);
    SkDELETE(fBatchFontCache);

    fGpu->unref();
    fCaps->unref();
    SkSafeUnref(fPathRendererChain);
    SkSafeUnref(fSoftwarePathRenderer);
}

void GrContext::abandonContext() {
    fResourceProvider->abandon();
>>>>>>> miniblink49
    // abandon first to so destructors
    // don't try to free the resources in the API.
    fResourceCache->abandonAll();

<<<<<<< HEAD
    fGpu->disconnect(GrGpu::DisconnectType::kAbandon);
=======
    fGpu->contextAbandoned();

    // a path renderer may be holding onto resources that
    // are now unusable
    SkSafeSetNull(fPathRendererChain);
    SkSafeSetNull(fSoftwarePathRenderer);

    fDrawingMgr.abandon();
>>>>>>> miniblink49

    fBatchFontCache->freeAll();
    fLayerCache->freeAll();
    fTextBlobCache->freeAll();
}

<<<<<<< HEAD
void GrContext::releaseResourcesAndAbandonContext()
{
    ASSERT_SINGLE_OWNER

    fResourceProvider->abandon();

    // Need to abandon the drawing manager first so all the render targets
    // will be released/forgotten before they too are abandoned.
    fDrawingManager->abandon();

    // Release all resources in the backend 3D API.
    fResourceCache->releaseAll();

    fGpu->disconnect(GrGpu::DisconnectType::kCleanup);

    fBatchFontCache->freeAll();
    fLayerCache->freeAll();
    fTextBlobCache->freeAll();
}

void GrContext::resetContext(uint32_t state)
{
    ASSERT_SINGLE_OWNER
    fGpu->markContextDirty(state);
}

void GrContext::freeGpuResources()
{
    ASSERT_SINGLE_OWNER

    this->flush();

    fBatchFontCache->freeAll();
    fLayerCache->freeAll();

    fDrawingManager->freeGpuResources();
=======
void GrContext::resetContext(uint32_t state) {
    fGpu->markContextDirty(state);
}

void GrContext::freeGpuResources() {
    this->flush();

    fDrawingMgr.purgeResources();

    fBatchFontCache->freeAll();
    fLayerCache->freeAll();
    // a path renderer may be holding onto resources
    SkSafeSetNull(fPathRendererChain);
    SkSafeSetNull(fSoftwarePathRenderer);
>>>>>>> miniblink49

    fResourceCache->purgeAllUnlocked();
}

<<<<<<< HEAD
void GrContext::getResourceCacheUsage(int* resourceCount, size_t* resourceBytes) const
{
    ASSERT_SINGLE_OWNER

=======
void GrContext::getResourceCacheUsage(int* resourceCount, size_t* resourceBytes) const {
>>>>>>> miniblink49
    if (resourceCount) {
        *resourceCount = fResourceCache->getBudgetedResourceCount();
    }
    if (resourceBytes) {
        *resourceBytes = fResourceCache->getBudgetedResourceBytes();
    }
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrContext::OverBudgetCB(void* data)
{
=======
void GrContext::OverBudgetCB(void* data) {
>>>>>>> miniblink49
    SkASSERT(data);

    GrContext* context = reinterpret_cast<GrContext*>(data);

<<<<<<< HEAD
    // Flush the GrBufferedDrawTarget to possibly free up some textures
    context->fFlushToReduceCacheSize = true;
}

void GrContext::TextBlobCacheOverBudgetCB(void* data)
{
=======
    // Flush the InOrderDrawBuffer to possibly free up some textures
    context->fFlushToReduceCacheSize = true;
}

void GrContext::TextBlobCacheOverBudgetCB(void* data) {
>>>>>>> miniblink49
    SkASSERT(data);

    // Unlike the GrResourceCache, TextBlobs are drawn at the SkGpuDevice level, therefore they
    // cannot use fFlushTorReduceCacheSize because it uses AutoCheckFlush.  The solution is to move
    // drawText calls to below the GrContext level, but this is not trivial because they call
    // drawPath on SkGpuDevice
    GrContext* context = reinterpret_cast<GrContext*>(data);
    context->flush();
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrContext::flush(int flagsBitfield)
{
    ASSERT_SINGLE_OWNER
    RETURN_IF_ABANDONED

    if (kDiscard_FlushBit & flagsBitfield) {
        fDrawingManager->reset();
    } else {
        fDrawingManager->flush();
=======
void GrContext::flush(int flagsBitfield) {
    RETURN_IF_ABANDONED

    if (kDiscard_FlushBit & flagsBitfield) {
        fDrawingMgr.reset();
    } else {
        fDrawingMgr.flush();
>>>>>>> miniblink49
    }
    fResourceCache->notifyFlushOccurred();
    fFlushToReduceCacheSize = false;
}

bool sw_convert_to_premul(GrPixelConfig srcConfig, int width, int height, size_t inRowBytes,
<<<<<<< HEAD
    const void* inPixels, size_t outRowBytes, void* outPixels)
{
    SkSrcPixelInfo srcPI;
    if (!GrPixelConfigToColorAndColorSpace(srcConfig, &srcPI.fColorType, nullptr)) {
=======
                          const void* inPixels, size_t outRowBytes, void* outPixels) {
    SkSrcPixelInfo srcPI;
    if (!GrPixelConfig2ColorAndProfileType(srcConfig, &srcPI.fColorType, NULL)) {
>>>>>>> miniblink49
        return false;
    }
    srcPI.fAlphaType = kUnpremul_SkAlphaType;
    srcPI.fPixels = inPixels;
    srcPI.fRowBytes = inRowBytes;

    SkDstPixelInfo dstPI;
    dstPI.fColorType = srcPI.fColorType;
    dstPI.fAlphaType = kPremul_SkAlphaType;
    dstPI.fPixels = outPixels;
    dstPI.fRowBytes = outRowBytes;

    return srcPI.convertPixelsTo(&dstPI, width, height);
}

bool GrContext::writeSurfacePixels(GrSurface* surface,
<<<<<<< HEAD
    int left, int top, int width, int height,
    GrPixelConfig srcConfig, const void* buffer, size_t rowBytes,
    uint32_t pixelOpsFlags)
{
    ASSERT_SINGLE_OWNER
    RETURN_FALSE_IF_ABANDONED
    ASSERT_OWNED_RESOURCE(surface);
    SkASSERT(surface);
    GR_AUDIT_TRAIL_AUTO_FRAME(&fAuditTrail, "GrContext::writeSurfacePixels");

    this->testPMConversionsIfNecessary(pixelOpsFlags);

    // Trim the params here so that if we wind up making a temporary surface it can be as small as
    // necessary and because GrGpu::getWritePixelsInfo requires it.
    if (!GrSurfacePriv::AdjustWritePixelParams(surface->width(), surface->height(),
            GrBytesPerPixel(srcConfig), &left, &top, &width,
            &height, &buffer, &rowBytes)) {
        return false;
    }

    bool applyPremulToSrc = false;
=======
                                   int left, int top, int width, int height,
                                   GrPixelConfig srcConfig, const void* buffer, size_t rowBytes,
                                   uint32_t pixelOpsFlags) {
    RETURN_FALSE_IF_ABANDONED
    {
        GrTexture* texture = NULL;
        if (!(kUnpremul_PixelOpsFlag & pixelOpsFlags) && (texture = surface->asTexture()) &&
            fGpu->canWriteTexturePixels(texture, srcConfig) &&
            (!fCaps->useDrawInsteadOfPartialRenderTargetWrite() || !surface->asRenderTarget() ||
              (width == texture->width() && height == texture->height()))) {

            if (!(kDontFlush_PixelOpsFlag & pixelOpsFlags) &&
                surface->surfacePriv().hasPendingIO()) {
                this->flush();
            }
            return fGpu->writeTexturePixels(texture, left, top, width, height,
                                            srcConfig, buffer, rowBytes);
            // Don't need to check kFlushWrites_PixelOp here, we just did a direct write so the
            // upload is already flushed.
        }
    }

    // If we didn't do a direct texture write then we upload the pixels to a texture and draw.
    GrRenderTarget* renderTarget = surface->asRenderTarget();
    if (!renderTarget) {
        return false;
    }

    // We ignore the preferred config unless it is a R/B swap of the src config. In that case
    // we will upload the original src data to a scratch texture but we will spoof it as the swapped
    // config. This scratch will then have R and B swapped. We correct for this by swapping again
    // when drawing the scratch to the dst using a conversion effect.
    bool swapRAndB = false;
    GrPixelConfig writeConfig = srcConfig;
    if (GrPixelConfigSwapRAndB(srcConfig) ==
        fGpu->preferredWritePixelsConfig(srcConfig, renderTarget->config())) {
        writeConfig = GrPixelConfigSwapRAndB(srcConfig);
        swapRAndB = true;
    }

    GrSurfaceDesc desc;
    desc.fWidth = width;
    desc.fHeight = height;
    desc.fConfig = writeConfig;
    SkAutoTUnref<GrTexture> texture(this->textureProvider()->refScratchTexture(desc,
        GrTextureProvider::kApprox_ScratchTexMatch));
    if (!texture) {
        return false;
    }

    SkAutoTUnref<const GrFragmentProcessor> fp;
    SkMatrix textureMatrix;
    textureMatrix.setIDiv(texture->width(), texture->height());

    // allocate a tmp buffer and sw convert the pixels to premul
    SkAutoSTMalloc<128 * 128, uint32_t> tmpPixels(0);

    GrPaint paint;
>>>>>>> miniblink49
    if (kUnpremul_PixelOpsFlag & pixelOpsFlags) {
        if (!GrPixelConfigIs8888(srcConfig)) {
            return false;
        }
<<<<<<< HEAD
        applyPremulToSrc = true;
    }

    GrGpu::DrawPreference drawPreference = GrGpu::kNoDraw_DrawPreference;
    // Don't prefer to draw for the conversion (and thereby access a texture from the cache) when
    // we've already determined that there isn't a roundtrip preserving conversion processor pair.
    if (applyPremulToSrc && !this->didFailPMUPMConversionTest()) {
        drawPreference = GrGpu::kCallerPrefersDraw_DrawPreference;
    }

    GrGpu::WritePixelTempDrawInfo tempDrawInfo;
    if (!fGpu->getWritePixelsInfo(surface, width, height, srcConfig, &drawPreference,
            &tempDrawInfo)) {
        return false;
    }

    if (!(kDontFlush_PixelOpsFlag & pixelOpsFlags) && surface->surfacePriv().hasPendingIO()) {
        this->flush();
    }

    SkAutoTUnref<GrTexture> tempTexture;
    if (GrGpu::kNoDraw_DrawPreference != drawPreference) {
        tempTexture.reset(
            this->textureProvider()->createApproxTexture(tempDrawInfo.fTempSurfaceDesc));
        if (!tempTexture && GrGpu::kRequireDraw_DrawPreference == drawPreference) {
            return false;
        }
    }

    // temp buffer for doing sw premul conversion, if needed.
    SkAutoSTMalloc<128 * 128, uint32_t> tmpPixels(0);
    if (tempTexture) {
        sk_sp<GrFragmentProcessor> fp;
        SkMatrix textureMatrix;
        textureMatrix.setIDiv(tempTexture->width(), tempTexture->height());
        if (applyPremulToSrc) {
            fp = this->createUPMToPMEffect(tempTexture, tempDrawInfo.fSwizzle, textureMatrix);
            // If premultiplying was the only reason for the draw, fall back to a straight write.
            if (!fp) {
                if (GrGpu::kCallerPrefersDraw_DrawPreference == drawPreference) {
                    tempTexture.reset(nullptr);
                }
            } else {
                applyPremulToSrc = false;
            }
        }
        if (tempTexture) {
            if (!fp) {
                fp = GrConfigConversionEffect::Make(tempTexture, tempDrawInfo.fSwizzle,
                    GrConfigConversionEffect::kNone_PMConversion,
                    textureMatrix);
                if (!fp) {
                    return false;
                }
            }
            GrRenderTarget* renderTarget = surface->asRenderTarget();
            SkASSERT(renderTarget);
            if (tempTexture->surfacePriv().hasPendingIO()) {
                this->flush();
            }
            if (applyPremulToSrc) {
                size_t tmpRowBytes = 4 * width;
                tmpPixels.reset(width * height);
                if (!sw_convert_to_premul(srcConfig, width, height, rowBytes, buffer, tmpRowBytes,
                        tmpPixels.get())) {
                    return false;
                }
                rowBytes = tmpRowBytes;
                buffer = tmpPixels.get();
                applyPremulToSrc = false;
            }
            if (!fGpu->writePixels(tempTexture, 0, 0, width, height,
                    tempDrawInfo.fWriteConfig, buffer,
                    rowBytes)) {
                return false;
            }
            SkMatrix matrix;
            matrix.setTranslate(SkIntToScalar(left), SkIntToScalar(top));
            sk_sp<GrDrawContext> drawContext(this->drawContext(sk_ref_sp(renderTarget)));
            if (!drawContext) {
                return false;
            }
            GrPaint paint;
            paint.addColorFragmentProcessor(std::move(fp));
            paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);
            paint.setAllowSRGBInputs(true);
            SkRect rect = SkRect::MakeWH(SkIntToScalar(width), SkIntToScalar(height));
            drawContext->drawRect(GrNoClip(), paint, matrix, rect, nullptr);

            if (kFlushWrites_PixelOp & pixelOpsFlags) {
                this->flushSurfaceWrites(surface);
            }
        }
    }
    if (!tempTexture) {
        if (applyPremulToSrc) {
            size_t tmpRowBytes = 4 * width;
            tmpPixels.reset(width * height);
            if (!sw_convert_to_premul(srcConfig, width, height, rowBytes, buffer, tmpRowBytes,
                    tmpPixels.get())) {
=======
        fp.reset(this->createUPMToPMEffect(paint.getProcessorDataManager(), texture, swapRAndB,
                                           textureMatrix));
        // handle the unpremul step on the CPU if we couldn't create an effect to do it.
        if (!fp) {
            size_t tmpRowBytes = 4 * width;
            tmpPixels.reset(width * height);
            if (!sw_convert_to_premul(srcConfig, width, height, rowBytes, buffer, tmpRowBytes,
                                      tmpPixels.get())) {
>>>>>>> miniblink49
                return false;
            }
            rowBytes = tmpRowBytes;
            buffer = tmpPixels.get();
<<<<<<< HEAD
            applyPremulToSrc = false;
        }
        return fGpu->writePixels(surface, left, top, width, height, srcConfig, buffer, rowBytes);
    }
    return true;
}

bool GrContext::readSurfacePixels(GrSurface* src,
    int left, int top, int width, int height,
    GrPixelConfig dstConfig, void* buffer, size_t rowBytes,
    uint32_t flags)
{
    ASSERT_SINGLE_OWNER
    RETURN_FALSE_IF_ABANDONED
    ASSERT_OWNED_RESOURCE(src);
    SkASSERT(src);
    GR_AUDIT_TRAIL_AUTO_FRAME(&fAuditTrail, "GrContext::readSurfacePixels");

    this->testPMConversionsIfNecessary(flags);
    SkAutoMutexAcquire ama(fReadPixelsMutex);

    // Adjust the params so that if we wind up using an intermediate surface we've already done
    // all the trimming and the temporary can be the min size required.
    if (!GrSurfacePriv::AdjustReadPixelParams(src->width(), src->height(),
            GrBytesPerPixel(dstConfig), &left,
            &top, &width, &height, &buffer, &rowBytes)) {
        return false;
    }

    if (!(kDontFlush_PixelOpsFlag & flags) && src->surfacePriv().hasPendingWrite()) {
        this->flush();
    }

    bool unpremul = SkToBool(kUnpremul_PixelOpsFlag & flags);
    if (unpremul && !GrPixelConfigIs8888(dstConfig)) {
        // The unpremul flag is only allowed for 8888 configs.
        return false;
    }

    GrGpu::DrawPreference drawPreference = GrGpu::kNoDraw_DrawPreference;
    // Don't prefer to draw for the conversion (and thereby access a texture from the cache) when
    // we've already determined that there isn't a roundtrip preserving conversion processor pair.
    if (unpremul && !this->didFailPMUPMConversionTest()) {
        drawPreference = GrGpu::kCallerPrefersDraw_DrawPreference;
    }

    GrGpu::ReadPixelTempDrawInfo tempDrawInfo;
    if (!fGpu->getReadPixelsInfo(src, width, height, rowBytes, dstConfig, &drawPreference,
            &tempDrawInfo)) {
        return false;
    }

    SkAutoTUnref<GrSurface> surfaceToRead(SkRef(src));
    bool didTempDraw = false;
    if (GrGpu::kNoDraw_DrawPreference != drawPreference) {
        if (tempDrawInfo.fUseExactScratch) {
            // We only respect this when the entire src is being read. Otherwise we can trigger too
            // many odd ball texture sizes and trash the cache.
            if (width != src->width() || height != src->height()) {
                tempDrawInfo.fUseExactScratch = false;
            }
        }
        SkAutoTUnref<GrTexture> temp;
        if (tempDrawInfo.fUseExactScratch) {
            temp.reset(this->textureProvider()->createTexture(tempDrawInfo.fTempSurfaceDesc,
                SkBudgeted::kYes));
        } else {
            temp.reset(this->textureProvider()->createApproxTexture(tempDrawInfo.fTempSurfaceDesc));
        }
        if (temp) {
            SkMatrix textureMatrix;
            textureMatrix.setTranslate(SkIntToScalar(left), SkIntToScalar(top));
            textureMatrix.postIDiv(src->width(), src->height());
            sk_sp<GrFragmentProcessor> fp;
            if (unpremul) {
                fp = this->createPMToUPMEffect(src->asTexture(), tempDrawInfo.fSwizzle,
                    textureMatrix);
                if (fp) {
                    unpremul = false; // we no longer need to do this on CPU after the read back.
                } else if (GrGpu::kCallerPrefersDraw_DrawPreference == drawPreference) {
                    // We only wanted to do the draw in order to perform the unpremul so don't
                    // bother.
                    temp.reset(nullptr);
                }
            }
            if (!fp && temp) {
                fp = GrConfigConversionEffect::Make(src->asTexture(), tempDrawInfo.fSwizzle,
                    GrConfigConversionEffect::kNone_PMConversion,
                    textureMatrix);
            }
            if (fp) {
                GrPaint paint;
                paint.addColorFragmentProcessor(std::move(fp));
                paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);
                paint.setAllowSRGBInputs(true);
                SkRect rect = SkRect::MakeWH(SkIntToScalar(width), SkIntToScalar(height));
                sk_sp<GrDrawContext> drawContext(
                    this->drawContext(sk_ref_sp(temp->asRenderTarget())));
                drawContext->drawRect(GrNoClip(), paint, SkMatrix::I(), rect, nullptr);
                surfaceToRead.reset(SkRef(temp.get()));
                left = 0;
                top = 0;
                didTempDraw = true;
=======
        }
    }

    if (!fp) {
        fp.reset(GrConfigConversionEffect::Create(paint.getProcessorDataManager(),
                                                  texture,
                                                  swapRAndB,
                                                  GrConfigConversionEffect::kNone_PMConversion,
                                                  textureMatrix));
    }

    // Even if the client told us not to flush, we still flush here. The client may have known that
    // writes to the original surface caused no data hazards, but they can't know that the scratch
    // we just got is safe.
    if (texture->surfacePriv().hasPendingIO()) {
        this->flush();
    }
    if (!fGpu->writeTexturePixels(texture, 0, 0, width, height,
                                  writeConfig, buffer, rowBytes)) {
        return false;
    }

    SkMatrix matrix;
    matrix.setTranslate(SkIntToScalar(left), SkIntToScalar(top));

    GrDrawContext* drawContext = this->drawContext();
    if (!drawContext) {
        return false;
    }

    paint.addColorProcessor(fp);

    SkRect rect = SkRect::MakeWH(SkIntToScalar(width), SkIntToScalar(height));

    drawContext->drawRect(renderTarget, GrClip::WideOpen(), paint, matrix, rect, NULL);

    if (kFlushWrites_PixelOp & pixelOpsFlags) {
        this->flushSurfaceWrites(surface);
    }

    return true;
}

// toggles between RGBA and BGRA
static SkColorType toggle_colortype32(SkColorType ct) {
    if (kRGBA_8888_SkColorType == ct) {
        return kBGRA_8888_SkColorType;
    } else {
        SkASSERT(kBGRA_8888_SkColorType == ct);
        return kRGBA_8888_SkColorType;
    }
}

bool GrContext::readRenderTargetPixels(GrRenderTarget* target,
                                       int left, int top, int width, int height,
                                       GrPixelConfig dstConfig, void* buffer, size_t rowBytes,
                                       uint32_t flags) {
    RETURN_FALSE_IF_ABANDONED
    ASSERT_OWNED_RESOURCE(target);
    SkASSERT(target);

    if (!(kDontFlush_PixelOpsFlag & flags) && target->surfacePriv().hasPendingWrite()) {
        this->flush();
    }

    // Determine which conversions have to be applied: flipY, swapRAnd, and/or unpremul.

    // If fGpu->readPixels would incur a y-flip cost then we will read the pixels upside down. We'll
    // either do the flipY by drawing into a scratch with a matrix or on the cpu after the read.
    bool flipY = fGpu->readPixelsWillPayForYFlip(target, left, top,
                                                 width, height, dstConfig,
                                                 rowBytes);
    // We ignore the preferred config if it is different than our config unless it is an R/B swap.
    // In that case we'll perform an R and B swap while drawing to a scratch texture of the swapped
    // config. Then we will call readPixels on the scratch with the swapped config. The swaps during
    // the draw cancels out the fact that we call readPixels with a config that is R/B swapped from
    // dstConfig.
    GrPixelConfig readConfig = dstConfig;
    bool swapRAndB = false;
    if (GrPixelConfigSwapRAndB(dstConfig) ==
        fGpu->preferredReadPixelsConfig(dstConfig, target->config())) {
        readConfig = GrPixelConfigSwapRAndB(readConfig);
        swapRAndB = true;
    }

    bool unpremul = SkToBool(kUnpremul_PixelOpsFlag & flags);

    if (unpremul && !GrPixelConfigIs8888(dstConfig)) {
        // The unpremul flag is only allowed for these two configs.
        return false;
    }

    SkAutoTUnref<GrTexture> tempTexture;

    // If the src is a texture and we would have to do conversions after read pixels, we instead
    // do the conversions by drawing the src to a scratch texture. If we handle any of the
    // conversions in the draw we set the corresponding bool to false so that we don't reapply it
    // on the read back pixels.
    GrTexture* src = target->asTexture();
    if (src && (swapRAndB || unpremul || flipY)) {
        // Make the scratch a render so we can read its pixels.
        GrSurfaceDesc desc;
        desc.fFlags = kRenderTarget_GrSurfaceFlag;
        desc.fWidth = width;
        desc.fHeight = height;
        desc.fConfig = readConfig;
        desc.fOrigin = kTopLeft_GrSurfaceOrigin;

        // When a full read back is faster than a partial we could always make the scratch exactly
        // match the passed rect. However, if we see many different size rectangles we will trash
        // our texture cache and pay the cost of creating and destroying many textures. So, we only
        // request an exact match when the caller is reading an entire RT.
        GrTextureProvider::ScratchTexMatch match = GrTextureProvider::kApprox_ScratchTexMatch;
        if (0 == left &&
            0 == top &&
            target->width() == width &&
            target->height() == height &&
            fGpu->fullReadPixelsIsFasterThanPartial()) {
            match = GrTextureProvider::kExact_ScratchTexMatch;
        }
        tempTexture.reset(this->textureProvider()->refScratchTexture(desc, match));
        if (tempTexture) {
            // compute a matrix to perform the draw
            SkMatrix textureMatrix;
            textureMatrix.setTranslate(SK_Scalar1 *left, SK_Scalar1 *top);
            textureMatrix.postIDiv(src->width(), src->height());

            GrPaint paint;
            SkAutoTUnref<const GrFragmentProcessor> fp;
            if (unpremul) {
                fp.reset(this->createPMToUPMEffect(paint.getProcessorDataManager(), src, swapRAndB,
                                                   textureMatrix));
                if (fp) {
                    unpremul = false; // we no longer need to do this on CPU after the read back.
                }
            }
            // If we failed to create a PM->UPM effect and have no other conversions to perform then
            // there is no longer any point to using the scratch.
            if (fp || flipY || swapRAndB) {
                if (!fp) {
                    fp.reset(GrConfigConversionEffect::Create(paint.getProcessorDataManager(),
                            src, swapRAndB, GrConfigConversionEffect::kNone_PMConversion,
                            textureMatrix));
                }
                swapRAndB = false; // we will handle the swap in the draw.

                // We protect the existing geometry here since it may not be
                // clear to the caller that a draw operation (i.e., drawSimpleRect)
                // can be invoked in this method
                {
                    GrDrawContext* drawContext = this->drawContext();
                    if (!drawContext) {
                        return false;
                    }

                    paint.addColorProcessor(fp);

                    SkRect rect = SkRect::MakeWH(SkIntToScalar(width), SkIntToScalar(height));

                    drawContext->drawRect(tempTexture->asRenderTarget(), GrClip::WideOpen(), paint,
                                          SkMatrix::I(), rect, NULL);                    

                    // we want to read back from the scratch's origin
                    left = 0;
                    top = 0;
                    target = tempTexture->asRenderTarget();
                }
                this->flushSurfaceWrites(target);
>>>>>>> miniblink49
            }
        }
    }

<<<<<<< HEAD
    if (GrGpu::kRequireDraw_DrawPreference == drawPreference && !didTempDraw) {
        return false;
    }
    GrPixelConfig configToRead = dstConfig;
    if (didTempDraw) {
        this->flushSurfaceWrites(surfaceToRead);
        configToRead = tempDrawInfo.fReadConfig;
    }
    if (!fGpu->readPixels(surfaceToRead, left, top, width, height, configToRead, buffer,
            rowBytes)) {
        return false;
    }

    // Perform umpremul conversion if we weren't able to perform it as a draw.
    if (unpremul) {
        SkDstPixelInfo dstPI;
        if (!GrPixelConfigToColorAndColorSpace(dstConfig, &dstPI.fColorType, nullptr)) {
=======
    if (!fGpu->readPixels(target,
                          left, top, width, height,
                          readConfig, buffer, rowBytes)) {
        return false;
    }
    // Perform any conversions we weren't able to perform using a scratch texture.
    if (unpremul || swapRAndB) {
        SkDstPixelInfo dstPI;
        if (!GrPixelConfig2ColorAndProfileType(dstConfig, &dstPI.fColorType, NULL)) {
>>>>>>> miniblink49
            return false;
        }
        dstPI.fAlphaType = kUnpremul_SkAlphaType;
        dstPI.fPixels = buffer;
        dstPI.fRowBytes = rowBytes;

        SkSrcPixelInfo srcPI;
<<<<<<< HEAD
        srcPI.fColorType = dstPI.fColorType;
=======
        srcPI.fColorType = swapRAndB ? toggle_colortype32(dstPI.fColorType) : dstPI.fColorType;
>>>>>>> miniblink49
        srcPI.fAlphaType = kPremul_SkAlphaType;
        srcPI.fPixels = buffer;
        srcPI.fRowBytes = rowBytes;

        return srcPI.convertPixelsTo(&dstPI, width, height);
    }
    return true;
}

<<<<<<< HEAD
bool GrContext::applyGamma(GrRenderTarget* dst, GrTexture* src, SkScalar gamma)
{
    ASSERT_SINGLE_OWNER
    RETURN_FALSE_IF_ABANDONED
    ASSERT_OWNED_RESOURCE(dst);
    ASSERT_OWNED_RESOURCE(src);
    GR_AUDIT_TRAIL_AUTO_FRAME(&fAuditTrail, "GrContext::applyGamma");

    // Dimensions must match exactly.
    if (dst->width() != src->width() || dst->height() != src->height()) {
        return false;
    }

    SkSurfaceProps props(SkSurfaceProps::kGammaCorrect_Flag,
        SkSurfaceProps::kLegacyFontHost_InitType);
    sk_sp<GrDrawContext> drawContext(this->drawContext(sk_ref_sp(dst), &props));
    if (!drawContext) {
        return false;
    }

    GrPaint paint;
    paint.addColorTextureProcessor(src, GrCoordTransform::MakeDivByTextureWHMatrix(src));
    if (!SkScalarNearlyEqual(gamma, 1.0f)) {
        paint.addColorFragmentProcessor(GrGammaEffect::Make(gamma));
    }
    paint.setPorterDuffXPFactory(SkXfermode::kSrc_Mode);
    paint.setGammaCorrect(true);

    SkRect rect;
    src->getBoundsRect(&rect);
    drawContext->drawRect(GrNoClip(), paint, SkMatrix::I(), rect);

    this->flushSurfaceWrites(dst);
    return true;
}

void GrContext::prepareSurfaceForExternalIO(GrSurface* surface)
{
    ASSERT_SINGLE_OWNER
=======
void GrContext::prepareSurfaceForExternalIO(GrSurface* surface) {
>>>>>>> miniblink49
    RETURN_IF_ABANDONED
    SkASSERT(surface);
    ASSERT_OWNED_RESOURCE(surface);
    if (surface->surfacePriv().hasPendingIO()) {
        this->flush();
    }
    GrRenderTarget* rt = surface->asRenderTarget();
    if (fGpu && rt) {
        fGpu->resolveRenderTarget(rt);
    }
}

<<<<<<< HEAD
bool GrContext::copySurface(GrSurface* dst, GrSurface* src, const SkIRect& srcRect,
    const SkIPoint& dstPoint)
{
    ASSERT_SINGLE_OWNER
    RETURN_FALSE_IF_ABANDONED
    GR_AUDIT_TRAIL_AUTO_FRAME(&fAuditTrail, "GrContext::copySurface");

    if (!src || !dst) {
        return false;
=======
void GrContext::copySurface(GrSurface* dst, GrSurface* src, const SkIRect& srcRect,
                            const SkIPoint& dstPoint, uint32_t pixelOpsFlags) {
    RETURN_IF_ABANDONED
    if (!src || !dst) {
        return;
>>>>>>> miniblink49
    }
    ASSERT_OWNED_RESOURCE(src);
    ASSERT_OWNED_RESOURCE(dst);

<<<<<<< HEAD
    if (!dst->asRenderTarget()) {
        SkIRect clippedSrcRect;
        SkIPoint clippedDstPoint;
        if (!GrCopySurfaceBatch::ClipSrcRectAndDstPoint(dst, src, srcRect, dstPoint,
                &clippedSrcRect, &clippedDstPoint)) {
            return false;
        }
        // If we don't have an RT for the dst then we won't have a GrDrawContext to insert the
        // the copy surface into. In the future we plan to have a more limited Context type
        // (GrCopyContext?) that has the subset of GrDrawContext operations that should be
        // allowed on textures that aren't render targets.
        // For now we just flush any writes to the src and issue an immediate copy to the dst.
        src->flushWrites();
        return fGpu->copySurface(dst, src, clippedSrcRect, clippedDstPoint);
    }
    sk_sp<GrDrawContext> drawContext(this->drawContext(sk_ref_sp(dst->asRenderTarget())));
    if (!drawContext) {
        return false;
    }

    if (!drawContext->copySurface(src, srcRect, dstPoint)) {
        return false;
    }
    return true;
}

void GrContext::flushSurfaceWrites(GrSurface* surface)
{
    ASSERT_SINGLE_OWNER
=======
    // Since we're going to the draw target and not GPU, no need to check kNoFlush
    // here.
    if (!dst->asRenderTarget()) {
        return;
    }

    GrDrawContext* drawContext = this->drawContext();
    if (!drawContext) {
        return;
    }

    drawContext->copySurface(dst->asRenderTarget(), src, srcRect, dstPoint);

    if (kFlushWrites_PixelOp & pixelOpsFlags) {
        this->flush();
    }
}

void GrContext::flushSurfaceWrites(GrSurface* surface) {
>>>>>>> miniblink49
    RETURN_IF_ABANDONED
    if (surface->surfacePriv().hasPendingWrite()) {
        this->flush();
    }
}

<<<<<<< HEAD
////////////////////////////////////////////////////////////////////////////////
int GrContext::getRecommendedSampleCount(GrPixelConfig config,
    SkScalar dpi) const
{
    ASSERT_SINGLE_OWNER

=======
/*
 * This method finds a path renderer that can draw the specified path on
 * the provided target.
 * Due to its expense, the software path renderer has split out so it can
 * can be individually allowed/disallowed via the "allowSW" boolean.
 */
GrPathRenderer* GrContext::getPathRenderer(const GrDrawTarget* target,
                                           const GrPipelineBuilder* pipelineBuilder,
                                           const SkMatrix& viewMatrix,
                                           const SkPath& path,
                                           const GrStrokeInfo& stroke,
                                           bool allowSW,
                                           GrPathRendererChain::DrawType drawType,
                                           GrPathRendererChain::StencilSupport* stencilSupport) {

    if (!fPathRendererChain) {
        fPathRendererChain = SkNEW_ARGS(GrPathRendererChain, (this));
    }

    GrPathRenderer* pr = fPathRendererChain->getPathRenderer(target,
                                                             pipelineBuilder,
                                                             viewMatrix,
                                                             path,
                                                             stroke,
                                                             drawType,
                                                             stencilSupport);

    if (!pr && allowSW) {
        if (!fSoftwarePathRenderer) {
            fSoftwarePathRenderer = SkNEW_ARGS(GrSoftwarePathRenderer, (this));
        }
        pr = fSoftwarePathRenderer;
    }

    return pr;
}

////////////////////////////////////////////////////////////////////////////////
int GrContext::getRecommendedSampleCount(GrPixelConfig config,
                                         SkScalar dpi) const {
>>>>>>> miniblink49
    if (!this->caps()->isConfigRenderable(config, true)) {
        return 0;
    }
    int chosenSampleCount = 0;
    if (fGpu->caps()->shaderCaps()->pathRenderingSupport()) {
        if (dpi >= 250.0f) {
            chosenSampleCount = 4;
        } else {
            chosenSampleCount = 16;
        }
    }
<<<<<<< HEAD
    return chosenSampleCount <= fGpu->caps()->maxSampleCount() ? chosenSampleCount : 0;
}

sk_sp<GrDrawContext> GrContext::drawContext(sk_sp<GrRenderTarget> rt,
    const SkSurfaceProps* surfaceProps)
{
    ASSERT_SINGLE_OWNER
    return fDrawingManager->drawContext(std::move(rt), surfaceProps);
}

sk_sp<GrDrawContext> GrContext::newDrawContext(SkBackingFit fit,
    int width, int height,
    GrPixelConfig config,
    int sampleCnt,
    GrSurfaceOrigin origin,
    const SkSurfaceProps* surfaceProps,
    SkBudgeted budgeted)
{
    GrSurfaceDesc desc;
    desc.fFlags = kRenderTarget_GrSurfaceFlag;
    desc.fOrigin = origin;
    desc.fWidth = width;
    desc.fHeight = height;
    desc.fConfig = config;
    desc.fSampleCnt = sampleCnt;

    sk_sp<GrTexture> tex;
    if (SkBackingFit::kExact == fit) {
        tex.reset(this->textureProvider()->createTexture(desc, budgeted));
    } else {
        tex.reset(this->textureProvider()->createApproxTexture(desc));
    }
    if (!tex) {
        return nullptr;
    }

    sk_sp<GrDrawContext> drawContext(this->drawContext(sk_ref_sp(tex->asRenderTarget()),
        surfaceProps));
    if (!drawContext) {
        return nullptr;
    }

    return drawContext;
}

bool GrContext::abandoned() const
{
    ASSERT_SINGLE_OWNER
    return fDrawingManager->wasAbandoned();
}

namespace {
void test_pm_conversions(GrContext* ctx, int* pmToUPMValue, int* upmToPMValue)
{
=======
    return chosenSampleCount <= fGpu->caps()->maxSampleCount() ?
        chosenSampleCount : 0;
}

namespace {
void test_pm_conversions(GrContext* ctx, int* pmToUPMValue, int* upmToPMValue) {
>>>>>>> miniblink49
    GrConfigConversionEffect::PMConversion pmToUPM;
    GrConfigConversionEffect::PMConversion upmToPM;
    GrConfigConversionEffect::TestForPreservingPMConversions(ctx, &pmToUPM, &upmToPM);
    *pmToUPMValue = pmToUPM;
    *upmToPMValue = upmToPM;
}
}

<<<<<<< HEAD
void GrContext::testPMConversionsIfNecessary(uint32_t flags)
{
    ASSERT_SINGLE_OWNER
    if (SkToBool(kUnpremul_PixelOpsFlag & flags)) {
        SkAutoMutexAcquire ama(fTestPMConversionsMutex);
        if (!fDidTestPMConversions) {
            test_pm_conversions(this, &fPMToUPMConversion, &fUPMToPMConversion);
            fDidTestPMConversions = true;
        }
    }
}

sk_sp<GrFragmentProcessor> GrContext::createPMToUPMEffect(GrTexture* texture,
    const GrSwizzle& swizzle,
    const SkMatrix& matrix) const
{
    ASSERT_SINGLE_OWNER
    // We should have already called this->testPMConversionsIfNecessary().
    SkASSERT(fDidTestPMConversions);
    GrConfigConversionEffect::PMConversion pmToUPM = static_cast<GrConfigConversionEffect::PMConversion>(fPMToUPMConversion);
    if (GrConfigConversionEffect::kNone_PMConversion != pmToUPM) {
        return GrConfigConversionEffect::Make(texture, swizzle, pmToUPM, matrix);
    } else {
        return nullptr;
    }
}

sk_sp<GrFragmentProcessor> GrContext::createUPMToPMEffect(GrTexture* texture,
    const GrSwizzle& swizzle,
    const SkMatrix& matrix) const
{
    ASSERT_SINGLE_OWNER
    // We should have already called this->testPMConversionsIfNecessary().
    SkASSERT(fDidTestPMConversions);
    GrConfigConversionEffect::PMConversion upmToPM = static_cast<GrConfigConversionEffect::PMConversion>(fUPMToPMConversion);
    if (GrConfigConversionEffect::kNone_PMConversion != upmToPM) {
        return GrConfigConversionEffect::Make(texture, swizzle, upmToPM, matrix);
    } else {
        return nullptr;
    }
}

bool GrContext::didFailPMUPMConversionTest() const
{
    ASSERT_SINGLE_OWNER
    // We should have already called this->testPMConversionsIfNecessary().
    SkASSERT(fDidTestPMConversions);
    // The PM<->UPM tests fail or succeed together so we only need to check one.
    return GrConfigConversionEffect::kNone_PMConversion == fPMToUPMConversion;
}

//////////////////////////////////////////////////////////////////////////////

void GrContext::getResourceCacheLimits(int* maxTextures, size_t* maxTextureBytes) const
{
    ASSERT_SINGLE_OWNER
=======
const GrFragmentProcessor* GrContext::createPMToUPMEffect(GrProcessorDataManager* procDataManager,
                                                          GrTexture* texture,
                                                          bool swapRAndB,
                                                          const SkMatrix& matrix) {
    if (!fDidTestPMConversions) {
        test_pm_conversions(this, &fPMToUPMConversion, &fUPMToPMConversion);
        fDidTestPMConversions = true;
    }
    GrConfigConversionEffect::PMConversion pmToUPM =
        static_cast<GrConfigConversionEffect::PMConversion>(fPMToUPMConversion);
    if (GrConfigConversionEffect::kNone_PMConversion != pmToUPM) {
        return GrConfigConversionEffect::Create(procDataManager, texture, swapRAndB, pmToUPM,
                                                matrix);
    } else {
        return NULL;
    }
}

const GrFragmentProcessor* GrContext::createUPMToPMEffect(GrProcessorDataManager* procDataManager,
                                                          GrTexture* texture,
                                                          bool swapRAndB,
                                                          const SkMatrix& matrix) {
    if (!fDidTestPMConversions) {
        test_pm_conversions(this, &fPMToUPMConversion, &fUPMToPMConversion);
        fDidTestPMConversions = true;
    }
    GrConfigConversionEffect::PMConversion upmToPM =
        static_cast<GrConfigConversionEffect::PMConversion>(fUPMToPMConversion);
    if (GrConfigConversionEffect::kNone_PMConversion != upmToPM) {
        return GrConfigConversionEffect::Create(procDataManager, texture, swapRAndB, upmToPM,
                                                matrix);
    } else {
        return NULL;
    }
}

//////////////////////////////////////////////////////////////////////////////

void GrContext::getResourceCacheLimits(int* maxTextures, size_t* maxTextureBytes) const {
>>>>>>> miniblink49
    if (maxTextures) {
        *maxTextures = fResourceCache->getMaxResourceCount();
    }
    if (maxTextureBytes) {
        *maxTextureBytes = fResourceCache->getMaxResourceBytes();
    }
}

<<<<<<< HEAD
void GrContext::setResourceCacheLimits(int maxTextures, size_t maxTextureBytes)
{
    ASSERT_SINGLE_OWNER
=======
void GrContext::setResourceCacheLimits(int maxTextures, size_t maxTextureBytes) {
>>>>>>> miniblink49
    fResourceCache->setLimits(maxTextures, maxTextureBytes);
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrContext::dumpMemoryStatistics(SkTraceMemoryDump* traceMemoryDump) const
{
    ASSERT_SINGLE_OWNER
    fResourceCache->dumpMemoryStatistics(traceMemoryDump);
}
=======
void GrContext::addGpuTraceMarker(const GrGpuTraceMarker* marker) {
    fGpu->addGpuTraceMarker(marker);
}

void GrContext::removeGpuTraceMarker(const GrGpuTraceMarker* marker) {
    fGpu->removeGpuTraceMarker(marker);
}

>>>>>>> miniblink49
