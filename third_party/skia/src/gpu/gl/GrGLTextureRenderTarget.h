/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef GrGLTextureRenderTarget_DEFINED
#define GrGLTextureRenderTarget_DEFINED

#include "GrGLGpu.h"
#include "GrGLRenderTarget.h"
#include "GrGLTexture.h"
=======

#ifndef GrGLTextureRenderTarget_DEFINED
#define GrGLTextureRenderTarget_DEFINED

#include "GrGLTexture.h"
#include "GrGLRenderTarget.h"
>>>>>>> miniblink49

class GrGLGpu;

#ifdef SK_BUILD_FOR_WIN
// Windows gives bogus warnings about inheriting asTexture/asRenderTarget via dominance.
#pragma warning(push)
<<<<<<< HEAD
#pragma warning(disable : 4250)
=======
#pragma warning(disable: 4250)
>>>>>>> miniblink49
#endif

class GrGLTextureRenderTarget : public GrGLTexture, public GrGLRenderTarget {
public:
    // We're virtually derived from GrSurface (via both GrGLTexture and GrGLRenderTarget) so its
    // constructor must be explicitly called.
    GrGLTextureRenderTarget(GrGLGpu* gpu,
<<<<<<< HEAD
        SkBudgeted budgeted,
        const GrSurfaceDesc& desc,
        const GrGLTexture::IDDesc& texIDDesc,
        const GrGLRenderTarget::IDDesc& rtIDDesc)
        : GrSurface(gpu, desc)
        , GrGLTexture(gpu, desc, texIDDesc)
        , GrGLRenderTarget(gpu, desc, rtIDDesc)
    {
        this->registerWithCache(budgeted);
    }

    bool canAttemptStencilAttachment() const override;

    void dumpMemoryStatistics(SkTraceMemoryDump* traceMemoryDump) const override;

    static GrGLTextureRenderTarget* CreateWrapped(GrGLGpu* gpu, const GrSurfaceDesc& desc,
        const GrGLTexture::IDDesc& texIDDesc,
        const GrGLRenderTarget::IDDesc& rtIDDesc);

protected:
    void onAbandon() override
    {
=======
                            const GrSurfaceDesc& desc,
                            const GrGLTexture::IDDesc& texIDDesc,
                            const GrGLRenderTarget::IDDesc& rtIDDesc)
        : GrSurface(gpu, texIDDesc.fLifeCycle, desc)
        , GrGLTexture(gpu, desc, texIDDesc, GrGLTexture::kDerived)
        , GrGLRenderTarget(gpu, desc, rtIDDesc, GrGLRenderTarget::kDerived) {
        this->registerWithCache();
    }

protected:
    void onAbandon() override {
>>>>>>> miniblink49
        GrGLRenderTarget::onAbandon();
        GrGLTexture::onAbandon();
    }

<<<<<<< HEAD
    void onRelease() override
    {
=======
    void onRelease() override {
>>>>>>> miniblink49
        GrGLRenderTarget::onRelease();
        GrGLTexture::onRelease();
    }

private:
<<<<<<< HEAD
    // Constructor for instances wrapping backend objects.
    GrGLTextureRenderTarget(GrGLGpu* gpu,
        const GrSurfaceDesc& desc,
        const GrGLTexture::IDDesc& texIDDesc,
        const GrGLRenderTarget::IDDesc& rtIDDesc)
        : GrSurface(gpu, desc)
        , GrGLTexture(gpu, desc, texIDDesc)
        , GrGLRenderTarget(gpu, desc, rtIDDesc)
    {
        this->registerWithCacheWrapped();
    }

    // GrGLRenderTarget accounts for the texture's memory and any MSAA renderbuffer's memory.
    size_t onGpuMemorySize() const override
    {
        return GrGLRenderTarget::onGpuMemorySize();
    }
=======
    // GrGLRenderTarget accounts for the texture's memory and any MSAA renderbuffer's memory.
    size_t onGpuMemorySize() const override {
        return GrGLRenderTarget::onGpuMemorySize();
    }

>>>>>>> miniblink49
};

#ifdef SK_BUILD_FOR_WIN
#pragma warning(pop)
#endif

#endif
