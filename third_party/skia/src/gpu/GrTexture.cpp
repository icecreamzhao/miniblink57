<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "GrTexture.h"
#include "GrCaps.h"
#include "GrContext.h"
#include "GrGpu.h"
#include "GrRenderTarget.h"
#include "GrRenderTargetPriv.h"
#include "GrResourceKey.h"
#include "GrTexturePriv.h"
#include "GrTypes.h"
#include "SkMath.h"
#include "SkMipMap.h"
#include "SkTypes.h"

void GrTexture::dirtyMipMaps(bool mipMapsDirty)
{
    if (mipMapsDirty) {
        if (kValid_MipMapsStatus == fMipMapsStatus) {
            fMipMapsStatus = kAllocated_MipMapsStatus;
=======
#include "GrContext.h"
#include "GrCaps.h"
#include "GrGpu.h"
#include "GrResourceKey.h"
#include "GrRenderTarget.h"
#include "GrRenderTargetPriv.h"
#include "GrTexture.h"
#include "GrTexturePriv.h"

void GrTexture::dirtyMipMaps(bool mipMapsDirty) {
    if (mipMapsDirty) {
        if (kValid_MipMapsStatus == fMipMapsStatus) {
           fMipMapsStatus = kAllocated_MipMapsStatus;
>>>>>>> miniblink49
        }
    } else {
        const bool sizeChanged = kNotAllocated_MipMapsStatus == fMipMapsStatus;
        fMipMapsStatus = kValid_MipMapsStatus;
        if (sizeChanged) {
            // This must not be called until after changing fMipMapsStatus.
            this->didChangeGpuMemorySize();
<<<<<<< HEAD
            // TODO(http://skbug.com/4548) - The desc and scratch key should be
            // updated to reflect the newly-allocated mipmaps.
=======
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
size_t GrTexture::onGpuMemorySize() const
{
=======
size_t GrTexture::onGpuMemorySize() const {
>>>>>>> miniblink49
    size_t textureSize;

    if (GrPixelConfigIsCompressed(fDesc.fConfig)) {
        textureSize = GrCompressedFormatDataSize(fDesc.fConfig, fDesc.fWidth, fDesc.fHeight);
    } else {
<<<<<<< HEAD
        textureSize = (size_t)fDesc.fWidth * fDesc.fHeight * GrBytesPerPixel(fDesc.fConfig);
=======
        textureSize = (size_t) fDesc.fWidth * fDesc.fHeight * GrBytesPerPixel(fDesc.fConfig);
>>>>>>> miniblink49
    }

    if (this->texturePriv().hasMipMaps()) {
        // We don't have to worry about the mipmaps being a different size than
        // we'd expect because we never change fDesc.fWidth/fHeight.
<<<<<<< HEAD
        textureSize += textureSize / 3;
    }

    SkASSERT(!SkToBool(fDesc.fFlags & kRenderTarget_GrSurfaceFlag));
    SkASSERT(textureSize <= WorseCaseSize(fDesc));

    return textureSize;
}

void GrTexture::validateDesc() const
{
=======
        textureSize *= 2;
    }
    return textureSize;
}

void GrTexture::validateDesc() const {
>>>>>>> miniblink49
    if (this->asRenderTarget()) {
        // This texture has a render target
        SkASSERT(0 != (fDesc.fFlags & kRenderTarget_GrSurfaceFlag));
        SkASSERT(fDesc.fSampleCnt == this->asRenderTarget()->numColorSamples());
    } else {
        SkASSERT(0 == (fDesc.fFlags & kRenderTarget_GrSurfaceFlag));
        SkASSERT(0 == fDesc.fSampleCnt);
    }
}

//////////////////////////////////////////////////////////////////////////////

namespace {

// FIXME:  This should be refactored with the code in gl/GrGLGpu.cpp.
<<<<<<< HEAD
GrSurfaceOrigin resolve_origin(const GrSurfaceDesc& desc)
{
=======
GrSurfaceOrigin resolve_origin(const GrSurfaceDesc& desc) {
>>>>>>> miniblink49
    // By default, GrRenderTargets are GL's normal orientation so that they
    // can be drawn to by the outside world without the client having
    // to render upside down.
    bool renderTarget = 0 != (desc.fFlags & kRenderTarget_GrSurfaceFlag);
    if (kDefault_GrSurfaceOrigin == desc.fOrigin) {
        return renderTarget ? kBottomLeft_GrSurfaceOrigin : kTopLeft_GrSurfaceOrigin;
    } else {
        return desc.fOrigin;
    }
}
}

//////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
GrTexture::GrTexture(GrGpu* gpu, const GrSurfaceDesc& desc, GrSLType samplerType,
    bool wasMipMapDataProvided)
    : INHERITED(gpu, desc)
    , fSamplerType(samplerType)
    // Gamma treatment is explicitly set after creation via GrTexturePriv
    , fGammaTreatment(SkSourceGammaTreatment::kIgnore)
{
    if (wasMipMapDataProvided) {
        fMipMapsStatus = kValid_MipMapsStatus;
        fMaxMipMapLevel = SkMipMap::ComputeLevelCount(fDesc.fWidth, fDesc.fHeight);
    } else {
        fMipMapsStatus = kNotAllocated_MipMapsStatus;
        fMaxMipMapLevel = 0;
    }
}

void GrTexture::computeScratchKey(GrScratchKey* key) const
{
    if (!GrPixelConfigIsCompressed(fDesc.fConfig)) {
        GrTexturePriv::ComputeScratchKey(fDesc, key);
    }
}

void GrTexturePriv::ComputeScratchKey(const GrSurfaceDesc& desc, GrScratchKey* key)
{
    static const GrScratchKey::ResourceType kType = GrScratchKey::GenerateResourceType();

    GrSurfaceOrigin origin = resolve_origin(desc);
    uint32_t flags = desc.fFlags & ~kCheckAllocation_GrSurfaceFlag;

    // make sure desc.fConfig fits in 5 bits
    SkASSERT(sk_float_log2(kLast_GrPixelConfig) <= 5);
    SkASSERT(static_cast<int>(desc.fConfig) < (1 << 5));
=======
GrTexture::GrTexture(GrGpu* gpu, LifeCycle lifeCycle, const GrSurfaceDesc& desc)
    : INHERITED(gpu, lifeCycle, desc)
    , fMipMapsStatus(kNotAllocated_MipMapsStatus) {

    if (!this->isExternal() && !GrPixelConfigIsCompressed(desc.fConfig)) {
        GrScratchKey key;
        GrTexturePriv::ComputeScratchKey(desc, &key);
        this->setScratchKey(key);
    }
    // only make sense if alloc size is pow2
    fShiftFixedX = 31 - SkCLZ(fDesc.fWidth);
    fShiftFixedY = 31 - SkCLZ(fDesc.fHeight);
}

void GrTexturePriv::ComputeScratchKey(const GrSurfaceDesc& desc, GrScratchKey* key) {
    static const GrScratchKey::ResourceType kType = GrScratchKey::GenerateResourceType();

    GrScratchKey::Builder builder(key, kType, 2);

    GrSurfaceOrigin origin = resolve_origin(desc);
    uint32_t flags = desc.fFlags & ~kCheckAllocation_GrSurfaceFlag;

    SkASSERT(desc.fWidth <= SK_MaxU16);
    SkASSERT(desc.fHeight <= SK_MaxU16);
    SkASSERT(static_cast<int>(desc.fConfig) < (1 << 6));
>>>>>>> miniblink49
    SkASSERT(desc.fSampleCnt < (1 << 8));
    SkASSERT(flags < (1 << 10));
    SkASSERT(static_cast<int>(origin) < (1 << 8));

<<<<<<< HEAD
    GrScratchKey::Builder builder(key, kType, 3);
    builder[0] = desc.fWidth;
    builder[1] = desc.fHeight;
    builder[2] = desc.fConfig | (desc.fIsMipMapped << 5) | (desc.fSampleCnt << 6) | (flags << 14)
        | (origin << 24);
=======
    builder[0] = desc.fWidth | (desc.fHeight << 16);
    builder[1] = desc.fConfig | (desc.fSampleCnt << 6) | (flags << 14) | (origin << 24);
>>>>>>> miniblink49
}
