<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrTextureProvider.h"
<<<<<<< HEAD

#include "../private/GrSingleOwner.h"
#include "GrCaps.h"
#include "GrGpu.h"
#include "GrResourceCache.h"
#include "GrTexturePriv.h"
#include "SkMathPriv.h"
#include "SkTArray.h"

#define ASSERT_SINGLE_OWNER \
    SkDEBUGCODE(GrSingleOwner::AutoEnforce debug_SingleOwner(fSingleOwner);)

enum ScratchTextureFlags {
    kExact_ScratchTextureFlag = 0x1,
    kNoPendingIO_ScratchTextureFlag = 0x2,
    kNoCreate_ScratchTextureFlag = 0x4,
};

GrTextureProvider::GrTextureProvider(GrGpu* gpu, GrResourceCache* cache, GrSingleOwner* singleOwner)
    : fCache(cache)
    , fGpu(gpu)
#ifdef SK_DEBUG
    , fSingleOwner(singleOwner)
#endif
{
}

GrTexture* GrTextureProvider::createMipMappedTexture(const GrSurfaceDesc& desc, SkBudgeted budgeted,
    const GrMipLevel* texels, int mipLevelCount)
{
    ASSERT_SINGLE_OWNER

    if (this->isAbandoned()) {
        return nullptr;
    }
    if (mipLevelCount && !texels) {
        return nullptr;
    }
    for (int i = 0; i < mipLevelCount; ++i) {
        if (!texels[i].fPixels) {
            return nullptr;
        }
    }

    if ((desc.fFlags & kRenderTarget_GrSurfaceFlag) && !fGpu->caps()->isConfigRenderable(desc.fConfig, desc.fSampleCnt > 0)) {
        return nullptr;
    }
    if (!GrPixelConfigIsCompressed(desc.fConfig)) {
        if (mipLevelCount < 2) {
            static const uint32_t kFlags = kExact_ScratchTextureFlag | kNoCreate_ScratchTextureFlag;
            if (GrTexture* texture = this->refScratchTexture(desc, kFlags)) {
                if (!mipLevelCount || texture->writePixels(0, 0, desc.fWidth, desc.fHeight, desc.fConfig, texels[0].fPixels, texels[0].fRowBytes)) {
                    if (SkBudgeted::kNo == budgeted) {
                        texture->resourcePriv().makeUnbudgeted();
                    }
                    return texture;
                }
                texture->unref();
            }
        }
    }

    SkTArray<GrMipLevel> texelsShallowCopy(mipLevelCount);
    for (int i = 0; i < mipLevelCount; ++i) {
        texelsShallowCopy.push_back(texels[i]);
    }
    return fGpu->createTexture(desc, budgeted, texelsShallowCopy);
}

GrTexture* GrTextureProvider::createTexture(const GrSurfaceDesc& desc, SkBudgeted budgeted,
    const void* srcData, size_t rowBytes)
{
    GrMipLevel tempTexels;
    GrMipLevel* texels = nullptr;
    int levelCount = 0;
    if (srcData) {
        tempTexels.fPixels = srcData;
        tempTexels.fRowBytes = rowBytes;
        texels = &tempTexels;
        levelCount = 1;
    }
    return this->createMipMappedTexture(desc, budgeted, texels, levelCount);
}

GrTexture* GrTextureProvider::createApproxTexture(const GrSurfaceDesc& desc)
{
    ASSERT_SINGLE_OWNER
    return this->internalCreateApproxTexture(desc, 0);
}

GrTexture* GrTextureProvider::internalCreateApproxTexture(const GrSurfaceDesc& desc,
    uint32_t scratchFlags)
{
    ASSERT_SINGLE_OWNER
    if (this->isAbandoned()) {
        return nullptr;
    }
    // Currently we don't recycle compressed textures as scratch.
    if (GrPixelConfigIsCompressed(desc.fConfig)) {
        return nullptr;
    } else {
        return this->refScratchTexture(desc, scratchFlags);
    }
}

GrTexture* GrTextureProvider::refScratchTexture(const GrSurfaceDesc& inDesc,
    uint32_t flags)
{
    ASSERT_SINGLE_OWNER
=======
#include "GrTexturePriv.h"
#include "GrResourceCache.h"
#include "GrGpu.h"

enum ScratchTextureFlags {
    kExact_ScratchTextureFlag           = 0x1,
    kNoPendingIO_ScratchTextureFlag     = 0x2,
    kNoCreate_ScratchTextureFlag        = 0x4,
};

GrTexture* GrTextureProvider::createTexture(const GrSurfaceDesc& desc, bool budgeted,
                                            const void* srcData, size_t rowBytes) {
    if (this->isAbandoned()) {
        return NULL;
    }
    if ((desc.fFlags & kRenderTarget_GrSurfaceFlag) &&
        !fGpu->caps()->isConfigRenderable(desc.fConfig, desc.fSampleCnt > 0)) {
        return NULL;
    }
    if (!GrPixelConfigIsCompressed(desc.fConfig)) {
        static const uint32_t kFlags = kExact_ScratchTextureFlag |
                                       kNoCreate_ScratchTextureFlag;
        if (GrTexture* texture = this->internalRefScratchTexture(desc, kFlags)) {
            if (!srcData || texture->writePixels(0, 0, desc.fWidth, desc.fHeight, desc.fConfig,
                                                 srcData, rowBytes)) {
                if (!budgeted) {
                    texture->resourcePriv().makeUnbudgeted();
                }
                return texture;
            }
            texture->unref();
        }
    }
    return fGpu->createTexture(desc, budgeted, srcData, rowBytes);
}

GrTexture* GrTextureProvider::refScratchTexture(const GrSurfaceDesc& desc, ScratchTexMatch match,
                                                bool calledDuringFlush) {
    if (this->isAbandoned()) {
        return NULL;
    }
    // Currently we don't recycle compressed textures as scratch.
    if (GrPixelConfigIsCompressed(desc.fConfig)) {
        return NULL;
    } else {
        uint32_t flags = 0;
        if (kExact_ScratchTexMatch == match) {
            flags |= kExact_ScratchTextureFlag;
        }
        if (calledDuringFlush) {
            flags |= kNoPendingIO_ScratchTextureFlag;
        }
        return this->internalRefScratchTexture(desc, flags);
    }
}

GrTexture* GrTextureProvider::internalRefScratchTexture(const GrSurfaceDesc& inDesc,
                                                        uint32_t flags) {
>>>>>>> miniblink49
    SkASSERT(!this->isAbandoned());
    SkASSERT(!GrPixelConfigIsCompressed(inDesc.fConfig));

    SkTCopyOnFirstWrite<GrSurfaceDesc> desc(inDesc);

    if (fGpu->caps()->reuseScratchTextures() || (desc->fFlags & kRenderTarget_GrSurfaceFlag)) {
        if (!(kExact_ScratchTextureFlag & flags)) {
            // bin by pow2 with a reasonable min
<<<<<<< HEAD
            const int kMinSize = 16;
            GrSurfaceDesc* wdesc = desc.writable();
            wdesc->fWidth = SkTMax(kMinSize, GrNextPow2(desc->fWidth));
            wdesc->fHeight = SkTMax(kMinSize, GrNextPow2(desc->fHeight));
=======
            static const int MIN_SIZE = 16;
            GrSurfaceDesc* wdesc = desc.writable();
            wdesc->fWidth  = SkTMax(MIN_SIZE, GrNextPow2(desc->fWidth));
            wdesc->fHeight = SkTMax(MIN_SIZE, GrNextPow2(desc->fHeight));
>>>>>>> miniblink49
        }

        GrScratchKey key;
        GrTexturePriv::ComputeScratchKey(*desc, &key);
        uint32_t scratchFlags = 0;
        if (kNoPendingIO_ScratchTextureFlag & flags) {
            scratchFlags = GrResourceCache::kRequireNoPendingIO_ScratchFlag;
<<<<<<< HEAD
        } else if (!(desc->fFlags & kRenderTarget_GrSurfaceFlag)) {
=======
        } else  if (!(desc->fFlags & kRenderTarget_GrSurfaceFlag)) {
>>>>>>> miniblink49
            // If it is not a render target then it will most likely be populated by
            // writePixels() which will trigger a flush if the texture has pending IO.
            scratchFlags = GrResourceCache::kPreferNoPendingIO_ScratchFlag;
        }
<<<<<<< HEAD
        GrGpuResource* resource = fCache->findAndRefScratchResource(key,
            GrSurface::WorseCaseSize(*desc),
            scratchFlags);
=======
        GrGpuResource* resource = fCache->findAndRefScratchResource(key, scratchFlags);
>>>>>>> miniblink49
        if (resource) {
            GrSurface* surface = static_cast<GrSurface*>(resource);
            GrRenderTarget* rt = surface->asRenderTarget();
            if (rt && fGpu->caps()->discardRenderTargetSupport()) {
                rt->discard();
            }
            return surface->asTexture();
        }
    }

    if (!(kNoCreate_ScratchTextureFlag & flags)) {
<<<<<<< HEAD
        return fGpu->createTexture(*desc, SkBudgeted::kYes);
    }

    return nullptr;
}

GrTexture* GrTextureProvider::wrapBackendTexture(const GrBackendTextureDesc& desc,
    GrWrapOwnership ownership)
{
    ASSERT_SINGLE_OWNER
    if (this->isAbandoned()) {
        return nullptr;
=======
        return fGpu->createTexture(*desc, true, NULL, 0);
    }

    return NULL;
}

GrTexture* GrTextureProvider::wrapBackendTexture(const GrBackendTextureDesc& desc,
                                                 GrWrapOwnership ownership) {
    if (this->isAbandoned()) {
        return NULL;
>>>>>>> miniblink49
    }
    return fGpu->wrapBackendTexture(desc, ownership);
}

<<<<<<< HEAD
GrRenderTarget* GrTextureProvider::wrapBackendRenderTarget(const GrBackendRenderTargetDesc& desc)
{
    ASSERT_SINGLE_OWNER
    return this->isAbandoned() ? nullptr : fGpu->wrapBackendRenderTarget(desc, kBorrow_GrWrapOwnership);
}

void GrTextureProvider::assignUniqueKeyToResource(const GrUniqueKey& key, GrGpuResource* resource)
{
    ASSERT_SINGLE_OWNER
=======
GrRenderTarget* GrTextureProvider::wrapBackendRenderTarget(const GrBackendRenderTargetDesc& desc) {
    return this->isAbandoned() ? NULL : fGpu->wrapBackendRenderTarget(desc,
                                                                      kBorrow_GrWrapOwnership);
}

void GrTextureProvider::assignUniqueKeyToResource(const GrUniqueKey& key, GrGpuResource* resource) {
>>>>>>> miniblink49
    if (this->isAbandoned() || !resource) {
        return;
    }
    resource->resourcePriv().setUniqueKey(key);
}

<<<<<<< HEAD
bool GrTextureProvider::existsResourceWithUniqueKey(const GrUniqueKey& key) const
{
    ASSERT_SINGLE_OWNER
    return this->isAbandoned() ? false : fCache->hasUniqueKey(key);
}

GrGpuResource* GrTextureProvider::findAndRefResourceByUniqueKey(const GrUniqueKey& key)
{
    ASSERT_SINGLE_OWNER
    return this->isAbandoned() ? nullptr : fCache->findAndRefUniqueResource(key);
}

GrTexture* GrTextureProvider::findAndRefTextureByUniqueKey(const GrUniqueKey& key)
{
    ASSERT_SINGLE_OWNER
    GrGpuResource* resource = this->findAndRefResourceByUniqueKey(key);
    if (resource) {
        GrTexture* texture = static_cast<GrSurface*>(resource)->asTexture();
        SkASSERT(texture);
        return texture;
    }
    return NULL;
=======
bool GrTextureProvider::existsResourceWithUniqueKey(const GrUniqueKey& key) const {
    return this->isAbandoned() ? false : fCache->hasUniqueKey(key);
}

GrGpuResource* GrTextureProvider::findAndRefResourceByUniqueKey(const GrUniqueKey& key) {
    return this->isAbandoned() ? NULL : fCache->findAndRefUniqueResource(key);
>>>>>>> miniblink49
}
