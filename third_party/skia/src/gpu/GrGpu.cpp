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
#include "GrGpu.h"

#include "GrBuffer.h"
#include "GrCaps.h"
#include "GrContext.h"
#include "GrGpuResourcePriv.h"
#include "GrMesh.h"
#include "GrPathRendering.h"
#include "GrPipeline.h"
#include "GrRenderTargetPriv.h"
#include "GrResourceCache.h"
#include "GrResourceProvider.h"
#include "GrStencilAttachment.h"
#include "GrSurfacePriv.h"
#include "GrTexturePriv.h"
#include "SkMathPriv.h"

GrMesh& GrMesh::operator=(const GrMesh& di)
{
    fPrimitiveType = di.fPrimitiveType;
    fStartVertex = di.fStartVertex;
    fStartIndex = di.fStartIndex;
    fVertexCount = di.fVertexCount;
    fIndexCount = di.fIndexCount;

    fInstanceCount = di.fInstanceCount;
    fVerticesPerInstance = di.fVerticesPerInstance;
    fIndicesPerInstance = di.fIndicesPerInstance;
    fMaxInstancesPerDraw = di.fMaxInstancesPerDraw;
=======

#include "GrGpu.h"

#include "GrCaps.h"
#include "GrContext.h"
#include "GrGpuResourcePriv.h"
#include "GrIndexBuffer.h"
#include "GrPathRendering.h"
#include "GrResourceCache.h"
#include "GrRenderTargetPriv.h"
#include "GrStencilAttachment.h"
#include "GrVertexBuffer.h"
#include "GrVertices.h"

GrVertices& GrVertices::operator =(const GrVertices& di) {
    fPrimitiveType  = di.fPrimitiveType;
    fStartVertex    = di.fStartVertex;
    fStartIndex     = di.fStartIndex;
    fVertexCount    = di.fVertexCount;
    fIndexCount     = di.fIndexCount;

    fInstanceCount          = di.fInstanceCount;
    fVerticesPerInstance    = di.fVerticesPerInstance;
    fIndicesPerInstance     = di.fIndicesPerInstance;
    fMaxInstancesPerDraw    = di.fMaxInstancesPerDraw;
>>>>>>> miniblink49

    fVertexBuffer.reset(di.vertexBuffer());
    fIndexBuffer.reset(di.indexBuffer());

    return *this;
}

////////////////////////////////////////////////////////////////////////////////

GrGpu::GrGpu(GrContext* context)
<<<<<<< HEAD
    : fResetTimestamp(kExpiredTimestamp + 1)
    , fResetBits(kAll_GrBackendState)
    , fMultisampleSpecsAllocator(1)
    , fContext(context)
{
}

GrGpu::~GrGpu() { }

void GrGpu::disconnect(DisconnectType) { }

////////////////////////////////////////////////////////////////////////////////

bool GrGpu::makeCopyForTextureParams(int width, int height, const GrTextureParams& textureParams,
    GrTextureProducer::CopyParams* copyParams) const
{
    const GrCaps& caps = *this->caps();
    if (textureParams.isTiled() && !caps.npotTextureTileSupport() && (!SkIsPow2(width) || !SkIsPow2(height))) {
        copyParams->fWidth = GrNextPow2(width);
        copyParams->fHeight = GrNextPow2(height);
        switch (textureParams.filterMode()) {
        case GrTextureParams::kNone_FilterMode:
            copyParams->fFilter = GrTextureParams::kNone_FilterMode;
            break;
        case GrTextureParams::kBilerp_FilterMode:
        case GrTextureParams::kMipMap_FilterMode:
            // We are only ever scaling up so no reason to ever indicate kMipMap.
            copyParams->fFilter = GrTextureParams::kBilerp_FilterMode;
            break;
        }
        return true;
    }
    return false;
}

static GrSurfaceOrigin resolve_origin(GrSurfaceOrigin origin, bool renderTarget)
{
=======
    : fResetTimestamp(kExpiredTimestamp+1)
    , fResetBits(kAll_GrBackendState)
    , fGpuTraceMarkerCount(0)
    , fContext(context) {
}

GrGpu::~GrGpu() {}

void GrGpu::contextAbandoned() {}

////////////////////////////////////////////////////////////////////////////////

static GrSurfaceOrigin resolve_origin(GrSurfaceOrigin origin, bool renderTarget) {
>>>>>>> miniblink49
    // By default, GrRenderTargets are GL's normal orientation so that they
    // can be drawn to by the outside world without the client having
    // to render upside down.
    if (kDefault_GrSurfaceOrigin == origin) {
        return renderTarget ? kBottomLeft_GrSurfaceOrigin : kTopLeft_GrSurfaceOrigin;
    } else {
        return origin;
    }
}

<<<<<<< HEAD
/**
 * Prior to creating a texture, make sure the type of texture being created is
 * supported by calling check_texture_creation_params.
 *
 * @param caps The capabilities of the GL device.
 * @param desc The descriptor of the texture to create.
 * @param isRT Indicates if the texture can be a render target.
 */
static bool check_texture_creation_params(const GrCaps& caps, const GrSurfaceDesc& desc,
    bool* isRT, const SkTArray<GrMipLevel>& texels)
{
    if (!caps.isConfigTexturable(desc.fConfig)) {
        return false;
    }

    *isRT = SkToBool(desc.fFlags & kRenderTarget_GrSurfaceFlag);
    if (*isRT && !caps.isConfigRenderable(desc.fConfig, desc.fSampleCnt > 0)) {
        return false;
    }

    // We currently do not support multisampled textures
    if (!*isRT && desc.fSampleCnt > 0) {
        return false;
    }

    if (*isRT) {
        int maxRTSize = caps.maxRenderTargetSize();
        if (desc.fWidth > maxRTSize || desc.fHeight > maxRTSize) {
            return false;
        }
    } else {
        int maxSize = caps.maxTextureSize();
        if (desc.fWidth > maxSize || desc.fHeight > maxSize) {
            return false;
        }
    }

    for (int i = 0; i < texels.count(); ++i) {
        if (!texels[i].fPixels) {
            return false;
        }
    }
    return true;
}

GrTexture* GrGpu::createTexture(const GrSurfaceDesc& origDesc, SkBudgeted budgeted,
    const SkTArray<GrMipLevel>& texels)
{
    GrSurfaceDesc desc = origDesc;

    const GrCaps* caps = this->caps();
    bool isRT = false;
    bool textureCreationParamsValid = check_texture_creation_params(*caps, desc, &isRT, texels);
    if (!textureCreationParamsValid) {
        return nullptr;
    }

    desc.fSampleCnt = SkTMin(desc.fSampleCnt, caps->maxSampleCount());
    // Attempt to catch un- or wrongly intialized sample counts;
=======
GrTexture* GrGpu::createTexture(const GrSurfaceDesc& origDesc, bool budgeted,
                                const void* srcData, size_t rowBytes) {
    GrSurfaceDesc desc = origDesc;

    if (!this->caps()->isConfigTexturable(desc.fConfig)) {
        return NULL;
    }

    bool isRT = SkToBool(desc.fFlags & kRenderTarget_GrSurfaceFlag);
    if (isRT && !this->caps()->isConfigRenderable(desc.fConfig, desc.fSampleCnt > 0)) {
        return NULL;
    }

    // We currently not support multisampled textures
    if (!isRT && desc.fSampleCnt > 0) {
        return NULL;
    }

    GrTexture *tex = NULL;

    if (isRT) {
        int maxRTSize = this->caps()->maxRenderTargetSize();
        if (desc.fWidth > maxRTSize || desc.fHeight > maxRTSize) {
            return NULL;
        }
    } else {
        int maxSize = this->caps()->maxTextureSize();
        if (desc.fWidth > maxSize || desc.fHeight > maxSize) {
            return NULL;
        }
    }

    GrGpuResource::LifeCycle lifeCycle = budgeted ? GrGpuResource::kCached_LifeCycle :
                                                    GrGpuResource::kUncached_LifeCycle;

    desc.fSampleCnt = SkTMin(desc.fSampleCnt, this->caps()->maxSampleCount());
    // Attempt to catch un- or wrongly initialized sample counts;
>>>>>>> miniblink49
    SkASSERT(desc.fSampleCnt >= 0 && desc.fSampleCnt <= 64);

    desc.fOrigin = resolve_origin(desc.fOrigin, isRT);

<<<<<<< HEAD
    GrTexture* tex = nullptr;

=======
>>>>>>> miniblink49
    if (GrPixelConfigIsCompressed(desc.fConfig)) {
        // We shouldn't be rendering into this
        SkASSERT(!isRT);
        SkASSERT(0 == desc.fSampleCnt);

<<<<<<< HEAD
        if (!caps->npotTextureTileSupport() && (!SkIsPow2(desc.fWidth) || !SkIsPow2(desc.fHeight))) {
            return nullptr;
        }

        this->handleDirtyContext();
        tex = this->onCreateCompressedTexture(desc, budgeted, texels);
    } else {
        this->handleDirtyContext();
        tex = this->onCreateTexture(desc, budgeted, texels);
    }
    if (tex) {
        if (!caps->reuseScratchTextures() && !isRT) {
            tex->resourcePriv().removeScratchKey();
        }
        fStats.incTextureCreates();
        if (!texels.empty()) {
            if (texels[0].fPixels) {
                fStats.incTextureUploads();
            }
=======
        if (!this->caps()->npotTextureTileSupport() &&
            (!SkIsPow2(desc.fWidth) || !SkIsPow2(desc.fHeight))) {
            return NULL;
        }

        this->handleDirtyContext();
        tex = this->onCreateCompressedTexture(desc, lifeCycle, srcData);
    } else {
        this->handleDirtyContext();
        tex = this->onCreateTexture(desc, lifeCycle, srcData, rowBytes);
    }
    if (!this->caps()->reuseScratchTextures() && !isRT) {
        tex->resourcePriv().removeScratchKey();
    }
    if (tex) {
        fStats.incTextureCreates();
        if (srcData) {
            fStats.incTextureUploads();
>>>>>>> miniblink49
        }
    }
    return tex;
}

<<<<<<< HEAD
GrTexture* GrGpu::wrapBackendTexture(const GrBackendTextureDesc& desc, GrWrapOwnership ownership)
{
    this->handleDirtyContext();
    if (!this->caps()->isConfigTexturable(desc.fConfig)) {
        return nullptr;
    }
    if ((desc.fFlags & kRenderTarget_GrBackendTextureFlag) && !this->caps()->isConfigRenderable(desc.fConfig, desc.fSampleCnt > 0)) {
        return nullptr;
    }
    int maxSize = this->caps()->maxTextureSize();
    if (desc.fWidth > maxSize || desc.fHeight > maxSize) {
        return nullptr;
    }
    GrTexture* tex = this->onWrapBackendTexture(desc, ownership);
    if (nullptr == tex) {
        return nullptr;
    }
    // TODO: defer this and attach dynamically
    GrRenderTarget* tgt = tex->asRenderTarget();
    if (tgt && !fContext->resourceProvider()->attachStencilAttachment(tgt)) {
        tex->unref();
        return nullptr;
=======
bool GrGpu::attachStencilAttachmentToRenderTarget(GrRenderTarget* rt) {
    SkASSERT(NULL == rt->renderTargetPriv().getStencilAttachment());
    GrUniqueKey sbKey;

    int width = rt->width();
    int height = rt->height();
#if 0
    if (this->caps()->oversizedStencilSupport()) {
        width  = SkNextPow2(width);
        height = SkNextPow2(height);
    }
#endif

    GrStencilAttachment::ComputeSharedStencilAttachmentKey(width, height,
        rt->numStencilSamples(), &sbKey);
    SkAutoTUnref<GrStencilAttachment> sb(static_cast<GrStencilAttachment*>(
        this->getContext()->getResourceCache()->findAndRefUniqueResource(sbKey)));
    if (sb) {
        if (this->attachStencilAttachmentToRenderTarget(sb, rt)) {
            rt->renderTargetPriv().didAttachStencilAttachment(sb);
            return true;
        }
        return false;
    }
    if (this->createStencilAttachmentForRenderTarget(rt, width, height)) {
        // Right now we're clearing the stencil buffer here after it is
        // attached to an RT for the first time. When we start matching
        // stencil buffers with smaller color targets this will no longer
        // be correct because it won't be guaranteed to clear the entire
        // sb.
        // We used to clear down in the GL subclass using a special purpose
        // FBO. But iOS doesn't allow a stencil-only FBO. It reports unsupported
        // FBO status.
        this->clearStencil(rt);
        GrStencilAttachment* sb = rt->renderTargetPriv().getStencilAttachment();
        sb->resourcePriv().setUniqueKey(sbKey);
        return true;
    } else {
        return false;
    }
}

GrTexture* GrGpu::wrapBackendTexture(const GrBackendTextureDesc& desc, GrWrapOwnership ownership) {
    this->handleDirtyContext();
    GrTexture* tex = this->onWrapBackendTexture(desc, ownership);
    if (NULL == tex) {
        return NULL;
    }
    // TODO: defer this and attach dynamically
    GrRenderTarget* tgt = tex->asRenderTarget();
    if (tgt && !this->attachStencilAttachmentToRenderTarget(tgt)) {
        tex->unref();
        return NULL;
>>>>>>> miniblink49
    } else {
        return tex;
    }
}

GrRenderTarget* GrGpu::wrapBackendRenderTarget(const GrBackendRenderTargetDesc& desc,
<<<<<<< HEAD
    GrWrapOwnership ownership)
{
    if (!this->caps()->isConfigRenderable(desc.fConfig, desc.fSampleCnt > 0)) {
        return nullptr;
    }
=======
                                               GrWrapOwnership ownership) {
>>>>>>> miniblink49
    this->handleDirtyContext();
    return this->onWrapBackendRenderTarget(desc, ownership);
}

<<<<<<< HEAD
GrRenderTarget* GrGpu::wrapBackendTextureAsRenderTarget(const GrBackendTextureDesc& desc)
{
    this->handleDirtyContext();
    if (!(desc.fFlags & kRenderTarget_GrBackendTextureFlag)) {
        return nullptr;
    }
    if (!this->caps()->isConfigRenderable(desc.fConfig, desc.fSampleCnt > 0)) {
        return nullptr;
    }
    int maxSize = this->caps()->maxTextureSize();
    if (desc.fWidth > maxSize || desc.fHeight > maxSize) {
        return nullptr;
    }
    return this->onWrapBackendTextureAsRenderTarget(desc);
}

GrBuffer* GrGpu::createBuffer(size_t size, GrBufferType intendedType,
    GrAccessPattern accessPattern, const void* data)
{
    this->handleDirtyContext();
    GrBuffer* buffer = this->onCreateBuffer(size, intendedType, accessPattern, data);
    if (!this->caps()->reuseScratchBuffers()) {
        buffer->resourcePriv().removeScratchKey();
    }
    return buffer;
}

bool GrGpu::copySurface(GrSurface* dst,
    GrSurface* src,
    const SkIRect& srcRect,
    const SkIPoint& dstPoint)
{
=======
GrVertexBuffer* GrGpu::createVertexBuffer(size_t size, bool dynamic) {
    this->handleDirtyContext();
    GrVertexBuffer* vb = this->onCreateVertexBuffer(size, dynamic);
    if (!this->caps()->reuseScratchBuffers()) {
        vb->resourcePriv().removeScratchKey();
    }
    return vb;
}

GrIndexBuffer* GrGpu::createIndexBuffer(size_t size, bool dynamic) {
    this->handleDirtyContext();
    GrIndexBuffer* ib = this->onCreateIndexBuffer(size, dynamic);
    if (!this->caps()->reuseScratchBuffers()) {
        ib->resourcePriv().removeScratchKey();
    }
    return ib;
}

void GrGpu::clear(const SkIRect* rect,
                  GrColor color,
                  bool canIgnoreRect,
                  GrRenderTarget* renderTarget) {
    SkASSERT(renderTarget);
    this->handleDirtyContext();
    this->onClear(renderTarget, rect, color, canIgnoreRect);
}

void GrGpu::clearStencilClip(const SkIRect& rect,
                             bool insideClip,
                             GrRenderTarget* renderTarget) {
    SkASSERT(renderTarget);
    this->handleDirtyContext();
    this->onClearStencilClip(renderTarget, rect, insideClip);
}

bool GrGpu::copySurface(GrSurface* dst,
                        GrSurface* src,
                        const SkIRect& srcRect,
                        const SkIPoint& dstPoint) {
>>>>>>> miniblink49
    SkASSERT(dst && src);
    this->handleDirtyContext();
    return this->onCopySurface(dst, src, srcRect, dstPoint);
}

<<<<<<< HEAD
bool GrGpu::getReadPixelsInfo(GrSurface* srcSurface, int width, int height, size_t rowBytes,
    GrPixelConfig readConfig, DrawPreference* drawPreference,
    ReadPixelTempDrawInfo* tempDrawInfo)
{
    SkASSERT(drawPreference);
    SkASSERT(tempDrawInfo);
    SkASSERT(kGpuPrefersDraw_DrawPreference != *drawPreference);

    // We currently do not support reading into a compressed buffer
    if (GrPixelConfigIsCompressed(readConfig)) {
        return false;
    }

    if (!this->onGetReadPixelsInfo(srcSurface, width, height, rowBytes, readConfig, drawPreference,
            tempDrawInfo)) {
        return false;
    }

    // Check to see if we're going to request that the caller draw when drawing is not possible.
    if (!srcSurface->asTexture() || !this->caps()->isConfigRenderable(tempDrawInfo->fTempSurfaceDesc.fConfig, false)) {
        // If we don't have a fallback to a straight read then fail.
        if (kRequireDraw_DrawPreference == *drawPreference) {
            return false;
        }
        *drawPreference = kNoDraw_DrawPreference;
    }

    return true;
}
bool GrGpu::getWritePixelsInfo(GrSurface* dstSurface, int width, int height,
    GrPixelConfig srcConfig, DrawPreference* drawPreference,
    WritePixelTempDrawInfo* tempDrawInfo)
{
    SkASSERT(drawPreference);
    SkASSERT(tempDrawInfo);
    SkASSERT(kGpuPrefersDraw_DrawPreference != *drawPreference);

    if (GrPixelConfigIsCompressed(dstSurface->desc().fConfig) && dstSurface->desc().fConfig != srcConfig) {
        return false;
    }

    if (SkToBool(dstSurface->asRenderTarget())) {
        if (this->caps()->useDrawInsteadOfAllRenderTargetWrites()) {
            ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
        } else if (this->caps()->useDrawInsteadOfPartialRenderTargetWrite() && (width < dstSurface->width() || height < dstSurface->height())) {
            ElevateDrawPreference(drawPreference, kRequireDraw_DrawPreference);
        }
    }

    if (!this->onGetWritePixelsInfo(dstSurface, width, height, srcConfig, drawPreference,
            tempDrawInfo)) {
        return false;
    }

    // Check to see if we're going to request that the caller draw when drawing is not possible.
    if (!dstSurface->asRenderTarget() || !this->caps()->isConfigTexturable(tempDrawInfo->fTempSurfaceDesc.fConfig)) {
        // If we don't have a fallback to a straight upload then fail.
        if (kRequireDraw_DrawPreference == *drawPreference || !this->caps()->isConfigTexturable(srcConfig)) {
            return false;
        }
        *drawPreference = kNoDraw_DrawPreference;
    }
    return true;
}

bool GrGpu::readPixels(GrSurface* surface,
    int left, int top, int width, int height,
    GrPixelConfig config, void* buffer,
    size_t rowBytes)
{
    this->handleDirtyContext();

    // We cannot read pixels into a compressed buffer
    if (GrPixelConfigIsCompressed(config)) {
        return false;
    }

    size_t bpp = GrBytesPerPixel(config);
    if (!GrSurfacePriv::AdjustReadPixelParams(surface->width(), surface->height(), bpp,
            &left, &top, &width, &height,
            &buffer,
            &rowBytes)) {
        return false;
    }

    return this->onReadPixels(surface,
        left, top, width, height,
        config, buffer,
        rowBytes);
}

bool GrGpu::writePixels(GrSurface* surface,
    int left, int top, int width, int height,
    GrPixelConfig config, const SkTArray<GrMipLevel>& texels)
{
    if (!surface) {
        return false;
    }
    for (int currentMipLevel = 0; currentMipLevel < texels.count(); currentMipLevel++) {
        if (!texels[currentMipLevel].fPixels) {
            return false;
        }
    }

    this->handleDirtyContext();
    if (this->onWritePixels(surface, left, top, width, height, config, texels)) {
        SkIRect rect = SkIRect::MakeXYWH(left, top, width, height);
        this->didWriteToSurface(surface, &rect, texels.count());
=======
bool GrGpu::readPixels(GrRenderTarget* target,
                       int left, int top, int width, int height,
                       GrPixelConfig config, void* buffer,
                       size_t rowBytes) {
    this->handleDirtyContext();
    return this->onReadPixels(target, left, top, width, height,
                              config, buffer, rowBytes);
}

bool GrGpu::writeTexturePixels(GrTexture* texture,
                               int left, int top, int width, int height,
                               GrPixelConfig config, const void* buffer,
                               size_t rowBytes) {
    this->handleDirtyContext();
    if (this->onWriteTexturePixels(texture, left, top, width, height,
                                   config, buffer, rowBytes)) {
>>>>>>> miniblink49
        fStats.incTextureUploads();
        return true;
    }
    return false;
}

<<<<<<< HEAD
bool GrGpu::writePixels(GrSurface* surface,
    int left, int top, int width, int height,
    GrPixelConfig config, const void* buffer,
    size_t rowBytes)
{
    GrMipLevel mipLevel;
    mipLevel.fPixels = buffer;
    mipLevel.fRowBytes = rowBytes;
    SkSTArray<1, GrMipLevel> texels;
    texels.push_back(mipLevel);

    return this->writePixels(surface, left, top, width, height, config, texels);
}

bool GrGpu::transferPixels(GrSurface* surface,
    int left, int top, int width, int height,
    GrPixelConfig config, GrBuffer* transferBuffer,
    size_t offset, size_t rowBytes)
{
    SkASSERT(transferBuffer);

    this->handleDirtyContext();
    if (this->onTransferPixels(surface, left, top, width, height, config,
            transferBuffer, offset, rowBytes)) {
        SkIRect rect = SkIRect::MakeXYWH(left, top, width, height);
        this->didWriteToSurface(surface, &rect);
        fStats.incTransfersToTexture();
        return true;
    }
    return false;
}

void GrGpu::resolveRenderTarget(GrRenderTarget* target)
{
=======
void GrGpu::resolveRenderTarget(GrRenderTarget* target) {
>>>>>>> miniblink49
    SkASSERT(target);
    this->handleDirtyContext();
    this->onResolveRenderTarget(target);
}

<<<<<<< HEAD
void GrGpu::didWriteToSurface(GrSurface* surface, const SkIRect* bounds, uint32_t mipLevels) const
{
    SkASSERT(surface);
    // Mark any MIP chain and resolve buffer as dirty if and only if there is a non-empty bounds.
    if (nullptr == bounds || !bounds->isEmpty()) {
        if (GrRenderTarget* target = surface->asRenderTarget()) {
            target->flagAsNeedingResolve(bounds);
        }
        GrTexture* texture = surface->asTexture();
        if (texture && 1 == mipLevels) {
            texture->texturePriv().dirtyMipMaps(true);
=======
typedef GrTraceMarkerSet::Iter TMIter;
void GrGpu::saveActiveTraceMarkers() {
    if (this->caps()->gpuTracingSupport()) {
        SkASSERT(0 == fStoredTraceMarkers.count());
        fStoredTraceMarkers.addSet(fActiveTraceMarkers);
        for (TMIter iter = fStoredTraceMarkers.begin(); iter != fStoredTraceMarkers.end(); ++iter) {
            this->removeGpuTraceMarker(&(*iter));
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
inline static uint8_t multisample_specs_id(uint8_t numSamples, GrSurfaceOrigin origin,
    const GrCaps& caps)
{
    if (!caps.sampleLocationsSupport()) {
        return numSamples;
    }

    SkASSERT(numSamples < 128);
    SkASSERT(kTopLeft_GrSurfaceOrigin == origin || kBottomLeft_GrSurfaceOrigin == origin);
    return (numSamples << 1) | (origin - 1);

    GR_STATIC_ASSERT(1 == kTopLeft_GrSurfaceOrigin);
    GR_STATIC_ASSERT(2 == kBottomLeft_GrSurfaceOrigin);
}

const GrGpu::MultisampleSpecs& GrGpu::getMultisampleSpecs(GrRenderTarget* rt,
    const GrStencilSettings& stencil)
{
    const GrSurfaceDesc& desc = rt->desc();
    uint8_t surfDescKey = multisample_specs_id(desc.fSampleCnt, desc.fOrigin, *this->caps());
    if (fMultisampleSpecsMap.count() > surfDescKey && fMultisampleSpecsMap[surfDescKey]) {
#if !defined(SK_DEBUG)
        // In debug mode we query the multisample info every time and verify the caching is correct.
        return *fMultisampleSpecsMap[surfDescKey];
#endif
    }
    int effectiveSampleCnt;
    SkAutoTDeleteArray<SkPoint> locations(nullptr);
    this->onGetMultisampleSpecs(rt, stencil, &effectiveSampleCnt, &locations);
    SkASSERT(effectiveSampleCnt && effectiveSampleCnt >= desc.fSampleCnt);
    uint8_t effectiveKey = multisample_specs_id(effectiveSampleCnt, desc.fOrigin, *this->caps());
    if (fMultisampleSpecsMap.count() > effectiveKey && fMultisampleSpecsMap[effectiveKey]) {
        const MultisampleSpecs& specs = *fMultisampleSpecsMap[effectiveKey];
        SkASSERT(effectiveKey == specs.fUniqueID);
        SkASSERT(effectiveSampleCnt == specs.fEffectiveSampleCnt);
        SkASSERT(!this->caps()->sampleLocationsSupport() || !memcmp(locations.get(), specs.fSampleLocations.get(), effectiveSampleCnt * sizeof(SkPoint)));
        SkASSERT(surfDescKey <= effectiveKey);
        SkASSERT(!fMultisampleSpecsMap[surfDescKey] || fMultisampleSpecsMap[surfDescKey] == &specs);
        fMultisampleSpecsMap[surfDescKey] = &specs;
        return specs;
    }
    const MultisampleSpecs& specs = *new (&fMultisampleSpecsAllocator)
                                        MultisampleSpecs { effectiveKey, effectiveSampleCnt, locations.release() };
    if (fMultisampleSpecsMap.count() <= effectiveKey) {
        int n = 1 + effectiveKey - fMultisampleSpecsMap.count();
        fMultisampleSpecsMap.push_back_n(n, (const MultisampleSpecs*)nullptr);
    }
    fMultisampleSpecsMap[effectiveKey] = &specs;
    if (effectiveSampleCnt != desc.fSampleCnt) {
        SkASSERT(surfDescKey < effectiveKey);
        fMultisampleSpecsMap[surfDescKey] = &specs;
    }
    return specs;
=======
void GrGpu::restoreActiveTraceMarkers() {
    if (this->caps()->gpuTracingSupport()) {
        SkASSERT(0 == fActiveTraceMarkers.count());
        for (TMIter iter = fStoredTraceMarkers.begin(); iter != fStoredTraceMarkers.end(); ++iter) {
            this->addGpuTraceMarker(&(*iter));
        }
        for (TMIter iter = fActiveTraceMarkers.begin(); iter != fActiveTraceMarkers.end(); ++iter) {
            this->fStoredTraceMarkers.remove(*iter);
        }
    }
}

void GrGpu::addGpuTraceMarker(const GrGpuTraceMarker* marker) {
    if (this->caps()->gpuTracingSupport()) {
        SkASSERT(fGpuTraceMarkerCount >= 0);
        this->fActiveTraceMarkers.add(*marker);
        this->didAddGpuTraceMarker();
        ++fGpuTraceMarkerCount;
    }
}

void GrGpu::removeGpuTraceMarker(const GrGpuTraceMarker* marker) {
    if (this->caps()->gpuTracingSupport()) {
        SkASSERT(fGpuTraceMarkerCount >= 1);
        this->fActiveTraceMarkers.remove(*marker);
        this->didRemoveGpuTraceMarker();
        --fGpuTraceMarkerCount;
    }
}

////////////////////////////////////////////////////////////////////////////////

void GrGpu::draw(const DrawArgs& args, const GrVertices& vertices) {
    this->handleDirtyContext();
    GrVertices::Iterator iter;
    const GrNonInstancedVertices* verts = iter.init(vertices);
    do {
        this->onDraw(args, *verts);
    } while ((verts = iter.next()));
>>>>>>> miniblink49
}
