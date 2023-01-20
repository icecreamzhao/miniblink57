/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrGLProgram.h"

#include "GrAllocator.h"
<<<<<<< HEAD
#include "GrCoordTransform.h"
#include "GrGLBuffer.h"
#include "GrGLGpu.h"
#include "GrGLPathRendering.h"
#include "GrPathProcessor.h"
#include "GrPipeline.h"
#include "GrProcessor.h"
#include "GrXferProcessor.h"
#include "SkXfermode.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLGeometryProcessor.h"
#include "glsl/GrGLSLXferProcessor.h"
=======
#include "GrProcessor.h"
#include "GrCoordTransform.h"
#include "GrGLGeometryProcessor.h"
#include "GrGLGpu.h"
#include "GrGLPathProcessor.h"
#include "GrGLPathRendering.h"
#include "GrGLShaderVar.h"
#include "GrGLXferProcessor.h"
#include "GrPathProcessor.h"
#include "GrPipeline.h"
#include "GrXferProcessor.h"
#include "SkXfermode.h"
>>>>>>> miniblink49

#define GL_CALL(X) GR_GL_CALL(fGpu->glInterface(), X)
#define GL_CALL_RET(R, X) GR_GL_CALL_RET(fGpu->glInterface(), R, X)

///////////////////////////////////////////////////////////////////////////////////////////////////

GrGLProgram::GrGLProgram(GrGLGpu* gpu,
<<<<<<< HEAD
    const GrProgramDesc& desc,
    const BuiltinUniformHandles& builtinUniforms,
    GrGLuint programID,
    const UniformInfoArray& uniforms,
    const SkTArray<GrGLSampler>& samplers,
    const VaryingInfoArray& pathProcVaryings,
    GrGLSLPrimitiveProcessor* geometryProcessor,
    GrGLSLXferProcessor* xferProcessor,
    const GrGLSLFragProcs& fragmentProcessors)
    : fBuiltinUniformHandles(builtinUniforms)
    , fProgramID(programID)
    , fGeometryProcessor(geometryProcessor)
    , fXferProcessor(xferProcessor)
    , fFragmentProcessors(fragmentProcessors)
    , fDesc(desc)
    , fGpu(gpu)
    , fProgramDataManager(gpu, programID, uniforms, pathProcVaryings)
{
    // Assign texture units to sampler uniforms one time up front.
    GL_CALL(UseProgram(fProgramID));
    fProgramDataManager.setSamplers(samplers);
}

GrGLProgram::~GrGLProgram()
{
    if (fProgramID) {
        GL_CALL(DeleteProgram(fProgramID));
    }
    for (int i = 0; i < fFragmentProcessors.count(); ++i) {
        delete fFragmentProcessors[i];
    }
}

void GrGLProgram::abandon()
{
=======
                         const GrProgramDesc& desc,
                         const BuiltinUniformHandles& builtinUniforms,
                         GrGLuint programID,
                         const UniformInfoArray& uniforms,
                         GrGLInstalledGeoProc* geometryProcessor,
                         GrGLInstalledXferProc* xferProcessor,
                         GrGLInstalledFragProcs* fragmentProcessors,
                         SkTArray<UniformHandle>* passSamplerUniforms)
    : fColor(GrColor_ILLEGAL)
    , fCoverage(0)
    , fDstTextureUnit(-1)
    , fBuiltinUniformHandles(builtinUniforms)
    , fProgramID(programID)
    , fGeometryProcessor(geometryProcessor)
    , fXferProcessor(xferProcessor)
    , fFragmentProcessors(SkRef(fragmentProcessors))
    , fDesc(desc)
    , fGpu(gpu)
    , fProgramDataManager(gpu, uniforms) {
    fSamplerUniforms.swap(passSamplerUniforms);
    // Assign texture units to sampler uniforms one time up front.
    GL_CALL(UseProgram(fProgramID));
    for (int i = 0; i < fSamplerUniforms.count(); i++) {
        fProgramDataManager.setSampler(fSamplerUniforms[i], i);
    }
}

GrGLProgram::~GrGLProgram() {
    if (fProgramID) {
        GL_CALL(DeleteProgram(fProgramID));
    }
}

void GrGLProgram::abandon() {
>>>>>>> miniblink49
    fProgramID = 0;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrGLProgram::setData(const GrPrimitiveProcessor& primProc, const GrPipeline& pipeline)
{
=======
template <class Proc>
static void append_texture_bindings(const Proc* ip,
                                    const GrProcessor& processor,
                                    SkTArray<const GrTextureAccess*>* textureBindings) {
    if (int numTextures = processor.numTextures()) {
        SkASSERT(textureBindings->count() == ip->fSamplersIdx);
        const GrTextureAccess** bindings = textureBindings->push_back_n(numTextures);
        int i = 0;
        do {
            bindings[i] = &processor.textureAccess(i);
        } while (++i < numTextures);
    }
}

void GrGLProgram::setData(const GrPrimitiveProcessor& primProc,
                          const GrPipeline& pipeline,
                          const GrBatchTracker& batchTracker,
                          SkTArray<const GrTextureAccess*>* textureBindings) {
>>>>>>> miniblink49
    this->setRenderTargetState(primProc, pipeline);

    // we set the textures, and uniforms for installed processors in a generic way, but subclasses
    // of GLProgram determine how to set coord transforms
<<<<<<< HEAD
    int nextSamplerIdx = 0;
    fGeometryProcessor->setData(fProgramDataManager, primProc);
    this->bindTextures(primProc, pipeline.getAllowSRGBInputs(), &nextSamplerIdx);

    this->setFragmentData(primProc, pipeline, &nextSamplerIdx);

    if (primProc.getPixelLocalStorageState() != GrPixelLocalStorageState::kDraw_GrPixelLocalStorageState) {
        const GrXferProcessor& xp = pipeline.getXferProcessor();
        fXferProcessor->setData(fProgramDataManager, xp);
        this->bindTextures(xp, pipeline.getAllowSRGBInputs(), &nextSamplerIdx);
    }
}

void GrGLProgram::generateMipmaps(const GrPrimitiveProcessor& primProc,
    const GrPipeline& pipeline)
{
    this->generateMipmaps(primProc, pipeline.getAllowSRGBInputs());

    int numProcessors = fFragmentProcessors.count();
    for (int i = 0; i < numProcessors; ++i) {
        const GrFragmentProcessor& processor = pipeline.getFragmentProcessor(i);
        this->generateMipmaps(processor, pipeline.getAllowSRGBInputs());
    }

    if (primProc.getPixelLocalStorageState() != GrPixelLocalStorageState::kDraw_GrPixelLocalStorageState) {
        const GrXferProcessor& xp = pipeline.getXferProcessor();
        this->generateMipmaps(xp, pipeline.getAllowSRGBInputs());
    }
}

void GrGLProgram::setFragmentData(const GrPrimitiveProcessor& primProc,
    const GrPipeline& pipeline,
    int* nextSamplerIdx)
{
    int numProcessors = fFragmentProcessors.count();
    for (int i = 0; i < numProcessors; ++i) {
        const GrFragmentProcessor& processor = pipeline.getFragmentProcessor(i);
        fFragmentProcessors[i]->setData(fProgramDataManager, processor);
        this->setTransformData(primProc, processor, i);
        this->bindTextures(processor, pipeline.getAllowSRGBInputs(), nextSamplerIdx);
    }
}
void GrGLProgram::setTransformData(const GrPrimitiveProcessor& primProc,
    const GrFragmentProcessor& processor,
    int index)
{
    fGeometryProcessor->setTransformData(primProc, fProgramDataManager, index,
        processor.coordTransforms());
}

void GrGLProgram::setRenderTargetState(const GrPrimitiveProcessor& primProc,
    const GrPipeline& pipeline)
{
    // Load the RT height uniform if it is needed to y-flip gl_FragCoord.
    if (fBuiltinUniformHandles.fRTHeightUni.isValid() && fRenderTargetState.fRenderTargetSize.fHeight != pipeline.getRenderTarget()->height()) {
        fProgramDataManager.set1f(fBuiltinUniformHandles.fRTHeightUni,
            SkIntToScalar(pipeline.getRenderTarget()->height()));
    }

    // set RT adjustment
    const GrRenderTarget* rt = pipeline.getRenderTarget();
    SkISize size;
    size.set(rt->width(), rt->height());
    if (!primProc.isPathRendering()) {
        if (fRenderTargetState.fRenderTargetOrigin != rt->origin() || fRenderTargetState.fRenderTargetSize != size) {
            fRenderTargetState.fRenderTargetSize = size;
            fRenderTargetState.fRenderTargetOrigin = rt->origin();

            float rtAdjustmentVec[4];
            fRenderTargetState.getRTAdjustmentVec(rtAdjustmentVec);
            fProgramDataManager.set4fv(fBuiltinUniformHandles.fRTAdjustmentUni, 1, rtAdjustmentVec);
        }
    } else {
        SkASSERT(fGpu->glCaps().shaderCaps()->pathRenderingSupport());
        const GrPathProcessor& pathProc = primProc.cast<GrPathProcessor>();
        fGpu->glPathRendering()->setProjectionMatrix(pathProc.viewMatrix(),
            size, rt->origin());
    }
}

void GrGLProgram::bindTextures(const GrProcessor& processor,
    bool allowSRGBInputs,
    int* nextSamplerIdx)
{
    for (int i = 0; i < processor.numTextures(); ++i) {
        const GrTextureAccess& access = processor.textureAccess(i);
        fGpu->bindTexture((*nextSamplerIdx)++, access.getParams(),
            allowSRGBInputs, static_cast<GrGLTexture*>(access.getTexture()));
    }
    for (int i = 0; i < processor.numBuffers(); ++i) {
        const GrBufferAccess& access = processor.bufferAccess(i);
        fGpu->bindTexelBuffer((*nextSamplerIdx)++, access.texelConfig(),
            static_cast<GrGLBuffer*>(access.buffer()));
    }
}

void GrGLProgram::generateMipmaps(const GrProcessor& processor,
    bool allowSRGBInputs)
{
    for (int i = 0; i < processor.numTextures(); ++i) {
        const GrTextureAccess& access = processor.textureAccess(i);
        fGpu->generateMipmaps(access.getParams(), allowSRGBInputs,
            static_cast<GrGLTexture*>(access.getTexture()));
    }
}
=======
    fGeometryProcessor->fGLProc->setData(fProgramDataManager, primProc, batchTracker);
    append_texture_bindings(fGeometryProcessor.get(), primProc, textureBindings);

    this->setFragmentData(primProc, pipeline, textureBindings);

    const GrXferProcessor& xp = *pipeline.getXferProcessor();
    fXferProcessor->fGLProc->setData(fProgramDataManager, xp);
    append_texture_bindings(fXferProcessor.get(), xp, textureBindings);

    // Some of GrGLProgram subclasses need to update state here
    this->didSetData();
}

void GrGLProgram::setFragmentData(const GrPrimitiveProcessor& primProc,
                                  const GrPipeline& pipeline,
                                  SkTArray<const GrTextureAccess*>* textureBindings) {
    int numProcessors = fFragmentProcessors->fProcs.count();
    for (int e = 0; e < numProcessors; ++e) {
        const GrPendingFragmentStage& stage = pipeline.getFragmentStage(e);
        const GrProcessor& processor = *stage.processor();
        fFragmentProcessors->fProcs[e]->fGLProc->setData(fProgramDataManager, processor);
        this->setTransformData(primProc,
                               stage,
                               e,
                               fFragmentProcessors->fProcs[e]);
        append_texture_bindings(fFragmentProcessors->fProcs[e], processor, textureBindings);
    }
}
void GrGLProgram::setTransformData(const GrPrimitiveProcessor& primProc,
                                   const GrPendingFragmentStage& processor,
                                   int index,
                                   GrGLInstalledFragProc* ip) {
    GrGLGeometryProcessor* gp =
            static_cast<GrGLGeometryProcessor*>(fGeometryProcessor.get()->fGLProc.get());
    gp->setTransformData(primProc, fProgramDataManager, index,
                         processor.processor()->coordTransforms());
}

void GrGLProgram::setRenderTargetState(const GrPrimitiveProcessor& primProc,
                                       const GrPipeline& pipeline) {
    // Load the RT height uniform if it is needed to y-flip gl_FragCoord.
    if (fBuiltinUniformHandles.fRTHeightUni.isValid() &&
        fRenderTargetState.fRenderTargetSize.fHeight != pipeline.getRenderTarget()->height()) {
        fProgramDataManager.set1f(fBuiltinUniformHandles.fRTHeightUni,
                                   SkIntToScalar(pipeline.getRenderTarget()->height()));
    }

    // call subclasses to set the actual view matrix
    this->onSetRenderTargetState(primProc, pipeline);
}

void GrGLProgram::onSetRenderTargetState(const GrPrimitiveProcessor&,
                                         const GrPipeline& pipeline) {
    const GrRenderTarget* rt = pipeline.getRenderTarget();
    SkISize size;
    size.set(rt->width(), rt->height());
    if (fRenderTargetState.fRenderTargetOrigin != rt->origin() ||
        fRenderTargetState.fRenderTargetSize != size) {
        fRenderTargetState.fRenderTargetSize = size;
        fRenderTargetState.fRenderTargetOrigin = rt->origin();

        GrGLfloat rtAdjustmentVec[4];
        fRenderTargetState.getRTAdjustmentVec(rtAdjustmentVec);
        fProgramDataManager.set4fv(fBuiltinUniformHandles.fRTAdjustmentUni, 1, rtAdjustmentVec);
    }
}

>>>>>>> miniblink49
