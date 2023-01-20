/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrGLTexture.h"
#include "GrGLGpu.h"
<<<<<<< HEAD
#include "SkTraceMemoryDump.h"
=======
>>>>>>> miniblink49

#define GPUGL static_cast<GrGLGpu*>(this->getGpu())
#define GL_CALL(X) GR_GL_CALL(GPUGL->glInterface(), X)

<<<<<<< HEAD
inline static GrSLType sampler_type(const GrGLTexture::IDDesc& idDesc, const GrGLGpu* gpu)
{
    if (idDesc.fInfo.fTarget == GR_GL_TEXTURE_EXTERNAL) {
        SkASSERT(gpu->glCaps().glslCaps()->externalTextureSupport());
        return kSamplerExternal_GrSLType;
    } else if (idDesc.fInfo.fTarget == GR_GL_TEXTURE_RECTANGLE) {
        SkASSERT(gpu->glCaps().rectangleTextureSupport());
        return kSampler2DRect_GrSLType;
    } else {
        SkASSERT(idDesc.fInfo.fTarget == GR_GL_TEXTURE_2D);
        return kSampler2D_GrSLType;
    }
}

// Because this class is virtually derived from GrSurface we must explicitly call its constructor.
GrGLTexture::GrGLTexture(GrGLGpu* gpu, SkBudgeted budgeted, const GrSurfaceDesc& desc,
    const IDDesc& idDesc)
    : GrSurface(gpu, desc)
    , INHERITED(gpu, desc, sampler_type(idDesc, gpu), false)
{
    this->init(desc, idDesc);
    this->registerWithCache(budgeted);
}

GrGLTexture::GrGLTexture(GrGLGpu* gpu, SkBudgeted budgeted, const GrSurfaceDesc& desc,
    const IDDesc& idDesc,
    bool wasMipMapDataProvided)
    : GrSurface(gpu, desc)
    , INHERITED(gpu, desc, sampler_type(idDesc, gpu), wasMipMapDataProvided)
{
    this->init(desc, idDesc);
    this->registerWithCache(budgeted);
}

GrGLTexture::GrGLTexture(GrGLGpu* gpu, Wrapped, const GrSurfaceDesc& desc, const IDDesc& idDesc)
    : GrSurface(gpu, desc)
    , INHERITED(gpu, desc, sampler_type(idDesc, gpu), false)
{
    this->init(desc, idDesc);
    this->registerWithCacheWrapped();
}

GrGLTexture::GrGLTexture(GrGLGpu* gpu, const GrSurfaceDesc& desc, const IDDesc& idDesc)
    : GrSurface(gpu, desc)
    , INHERITED(gpu, desc, sampler_type(idDesc, gpu), false)
{
    this->init(desc, idDesc);
}

void GrGLTexture::init(const GrSurfaceDesc& desc, const IDDesc& idDesc)
{
    SkASSERT(0 != idDesc.fInfo.fID);
    fTexParams.invalidate();
    fTexParamsTimestamp = GrGpu::kExpiredTimestamp;
    fInfo = idDesc.fInfo;
    fTextureIDOwnership = idDesc.fOwnership;
}

void GrGLTexture::onRelease()
{
    if (fInfo.fID) {
        if (GrBackendObjectOwnership::kBorrowed != fTextureIDOwnership) {
            GL_CALL(DeleteTextures(1, &fInfo.fID));
        }
        fInfo.fID = 0;
=======
// Because this class is virtually derived from GrSurface we must explicitly call its constructor.
GrGLTexture::GrGLTexture(GrGLGpu* gpu, const GrSurfaceDesc& desc, const IDDesc& idDesc)
    : GrSurface(gpu, idDesc.fLifeCycle, desc)
    , INHERITED(gpu, idDesc.fLifeCycle, desc) {
    this->init(desc, idDesc);
    this->registerWithCache();
}

GrGLTexture::GrGLTexture(GrGLGpu* gpu, const GrSurfaceDesc& desc, const IDDesc& idDesc, Derived)
    : GrSurface(gpu, idDesc.fLifeCycle, desc)
    , INHERITED(gpu, idDesc.fLifeCycle, desc) {
    this->init(desc, idDesc);
}

void GrGLTexture::init(const GrSurfaceDesc& desc, const IDDesc& idDesc) {
    SkASSERT(0 != idDesc.fTextureID);
    fTexParams.invalidate();
    fTexParamsTimestamp = GrGpu::kExpiredTimestamp;
    fTextureID = idDesc.fTextureID;
    fTextureIDLifecycle = idDesc.fLifeCycle;
}

void GrGLTexture::onRelease() {
    if (fTextureID) {
        if (GrGpuResource::kBorrowed_LifeCycle != fTextureIDLifecycle) {
            GL_CALL(DeleteTextures(1, &fTextureID));
        }
        fTextureID = 0;
>>>>>>> miniblink49
    }
    INHERITED::onRelease();
}

<<<<<<< HEAD
void GrGLTexture::onAbandon()
{
    fInfo.fTarget = 0;
    fInfo.fID = 0;
    INHERITED::onAbandon();
}

GrBackendObject GrGLTexture::getTextureHandle() const
{
#ifdef SK_IGNORE_GL_TEXTURE_TARGET
    return static_cast<GrBackendObject>(this->textureID());
#else
    return reinterpret_cast<GrBackendObject>(&fInfo);
#endif
}

void GrGLTexture::setMemoryBacking(SkTraceMemoryDump* traceMemoryDump,
    const SkString& dumpName) const
{
    SkString texture_id;
    texture_id.appendU32(this->textureID());
    traceMemoryDump->setMemoryBacking(dumpName.c_str(), "gl_texture",
        texture_id.c_str());
}

GrGLTexture* GrGLTexture::CreateWrapped(GrGLGpu* gpu, const GrSurfaceDesc& desc,
    const IDDesc& idDesc)
{
    return new GrGLTexture(gpu, kWrapped, desc, idDesc);
=======
void GrGLTexture::onAbandon() {
    fTextureID = 0;
    INHERITED::onAbandon();
}

GrBackendObject GrGLTexture::getTextureHandle() const {
    return static_cast<GrBackendObject>(this->textureID());
>>>>>>> miniblink49
}
