/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gl/GrGLPathRendering.h"
<<<<<<< HEAD
#include "gl/GrGLGpu.h"
#include "gl/GrGLUtil.h"
=======
#include "gl/GrGLNameAllocator.h"
#include "gl/GrGLUtil.h"
#include "gl/GrGLGpu.h"
>>>>>>> miniblink49

#include "GrGLPath.h"
#include "GrGLPathRange.h"
#include "GrGLPathRendering.h"

#include "SkStream.h"
#include "SkTypeface.h"

#define GL_CALL(X) GR_GL_CALL(this->gpu()->glInterface(), X)
#define GL_CALL_RET(RET, X) GR_GL_CALL_RET(this->gpu()->glInterface(), RET, X)

<<<<<<< HEAD
// Number of paths to allocate per glGenPaths call. The call can be overly slow on command buffer GL
// implementation. The call has a result value, and thus waiting for the call completion is needed.
static const GrGLsizei kPathIDPreallocationAmount = 65536;
=======
>>>>>>> miniblink49

static const GrGLenum gIndexType2GLType[] = {
    GR_GL_UNSIGNED_BYTE,
    GR_GL_UNSIGNED_SHORT,
    GR_GL_UNSIGNED_INT
};

GR_STATIC_ASSERT(0 == GrPathRange::kU8_PathIndexType);
GR_STATIC_ASSERT(1 == GrPathRange::kU16_PathIndexType);
GR_STATIC_ASSERT(2 == GrPathRange::kU32_PathIndexType);
GR_STATIC_ASSERT(GrPathRange::kU32_PathIndexType == GrPathRange::kLast_PathIndexType);

static const GrGLenum gXformType2GLType[] = {
    GR_GL_NONE,
    GR_GL_TRANSLATE_X,
    GR_GL_TRANSLATE_Y,
    GR_GL_TRANSLATE_2D,
    GR_GL_TRANSPOSE_AFFINE_2D
};

GR_STATIC_ASSERT(0 == GrPathRendering::kNone_PathTransformType);
GR_STATIC_ASSERT(1 == GrPathRendering::kTranslateX_PathTransformType);
GR_STATIC_ASSERT(2 == GrPathRendering::kTranslateY_PathTransformType);
GR_STATIC_ASSERT(3 == GrPathRendering::kTranslate_PathTransformType);
GR_STATIC_ASSERT(4 == GrPathRendering::kAffine_PathTransformType);
GR_STATIC_ASSERT(GrPathRendering::kAffine_PathTransformType == GrPathRendering::kLast_PathTransformType);

<<<<<<< HEAD
#ifdef SK_DEBUG
static const GrGLenum gXformType2ComponentCount[] = {
    0,
    1,
    1,
    2,
    6
};

static void verify_floats(const float* floats, int count)
{
    for (int i = 0; i < count; ++i) {
        SkASSERT(!SkScalarIsNaN(SkFloatToScalar(floats[i])));
    }
}
#endif

static GrGLenum gr_stencil_op_to_gl_path_rendering_fill_mode(GrStencilOp op)
{
    switch (op) {
    default:
        SkFAIL("Unexpected path fill.");
        /* fallthrough */;
    case GrStencilOp::kIncWrap:
        return GR_GL_COUNT_UP;
    case GrStencilOp::kInvert:
        return GR_GL_INVERT;
=======
static GrGLenum gr_stencil_op_to_gl_path_rendering_fill_mode(GrStencilOp op) {
    switch (op) {
        default:
            SkFAIL("Unexpected path fill.");
            /* fallthrough */;
        case kIncClamp_StencilOp:
            return GR_GL_COUNT_UP;
        case kInvert_StencilOp:
            return GR_GL_INVERT;
>>>>>>> miniblink49
    }
}

GrGLPathRendering::GrGLPathRendering(GrGLGpu* gpu)
<<<<<<< HEAD
    : GrPathRendering(gpu)
    , fPreallocatedPathCount(0)
{
    const GrGLInterface* glInterface = gpu->glInterface();
    fCaps.bindFragmentInputSupport = nullptr != glInterface->fFunctions.fBindFragmentInputLocation;
}

GrGLPathRendering::~GrGLPathRendering()
{
    if (fPreallocatedPathCount > 0) {
        this->deletePaths(fFirstPreallocatedPathID, fPreallocatedPathCount);
    }
}

void GrGLPathRendering::disconnect(GrGpu::DisconnectType type)
{
    if (GrGpu::DisconnectType::kCleanup == type) {
        this->deletePaths(fFirstPreallocatedPathID, fPreallocatedPathCount);
    };
    fPreallocatedPathCount = 0;
}

void GrGLPathRendering::resetContext()
{
=======
    : GrPathRendering(gpu) {
}

GrGLPathRendering::~GrGLPathRendering() {
}

void GrGLPathRendering::abandonGpuResources() {
    fPathNameAllocator.reset(NULL);
}

void GrGLPathRendering::resetContext() {
>>>>>>> miniblink49
    fHWProjectionMatrixState.invalidate();
    // we don't use the model view matrix.
    GL_CALL(MatrixLoadIdentity(GR_GL_PATH_MODELVIEW));

    fHWPathStencilSettings.invalidate();
}

<<<<<<< HEAD
GrPath* GrGLPathRendering::createPath(const SkPath& inPath, const GrStyle& style)
{
    return new GrGLPath(this->gpu(), inPath, style);
}

GrPathRange* GrGLPathRendering::createPathRange(GrPathRange::PathGenerator* pathGenerator,
    const GrStyle& style)
{
    return new GrGLPathRange(this->gpu(), pathGenerator, style);
}

void GrGLPathRendering::onStencilPath(const StencilPathArgs& args, const GrPath* path)
{
=======
GrPath* GrGLPathRendering::createPath(const SkPath& inPath, const GrStrokeInfo& stroke) {
    return SkNEW_ARGS(GrGLPath, (this->gpu(), inPath, stroke));
}

GrPathRange* GrGLPathRendering::createPathRange(GrPathRange::PathGenerator* pathGenerator,
                                                const GrStrokeInfo& stroke) {
    return SkNEW_ARGS(GrGLPathRange, (this->gpu(), pathGenerator, stroke));
}

void GrGLPathRendering::onStencilPath(const StencilPathArgs& args, const GrPath* path) {
>>>>>>> miniblink49
    GrGLGpu* gpu = this->gpu();
    SkASSERT(gpu->caps()->shaderCaps()->pathRenderingSupport());
    gpu->flushColorWrite(false);
    gpu->flushDrawFace(GrPipelineBuilder::kBoth_DrawFace);

    GrGLRenderTarget* rt = static_cast<GrGLRenderTarget*>(args.fRenderTarget);
    SkISize size = SkISize::Make(rt->width(), rt->height());
    this->setProjectionMatrix(*args.fViewMatrix, size, rt->origin());
    gpu->flushScissor(*args.fScissor, rt->getViewport(), rt->origin());
<<<<<<< HEAD
    gpu->flushHWAAState(rt, args.fUseHWAA, true);
    gpu->flushRenderTarget(rt, nullptr);
=======
    gpu->flushHWAAState(rt, args.fUseHWAA);
    gpu->flushRenderTarget(rt, NULL);
>>>>>>> miniblink49

    const GrGLPath* glPath = static_cast<const GrGLPath*>(path);

    this->flushPathStencilSettings(*args.fStencil);
    SkASSERT(!fHWPathStencilSettings.isTwoSided());

<<<<<<< HEAD
    GrGLenum fillMode = gr_stencil_op_to_gl_path_rendering_fill_mode(fHWPathStencilSettings.front().fPassOp);
    GrGLint writeMask = fHWPathStencilSettings.front().fWriteMask;
=======
    GrGLenum fillMode = gr_stencil_op_to_gl_path_rendering_fill_mode(
        fHWPathStencilSettings.passOp(GrStencilSettings::kFront_Face));
    GrGLint writeMask = fHWPathStencilSettings.writeMask(GrStencilSettings::kFront_Face);
>>>>>>> miniblink49

    if (glPath->shouldFill()) {
        GL_CALL(StencilFillPath(glPath->pathID(), fillMode, writeMask));
    }
    if (glPath->shouldStroke()) {
        GL_CALL(StencilStrokePath(glPath->pathID(), 0xffff, writeMask));
    }
}

<<<<<<< HEAD
void GrGLPathRendering::onDrawPath(const GrPipeline& pipeline,
    const GrPrimitiveProcessor& primProc,
    const GrStencilSettings& stencilPassSettings,
    const GrPath* path)
{
    if (!this->gpu()->flushGLState(pipeline, primProc)) {
=======
void GrGLPathRendering::onDrawPath(const DrawPathArgs& args, const GrPath* path) {
    if (!this->gpu()->flushGLState(args)) {
>>>>>>> miniblink49
        return;
    }
    const GrGLPath* glPath = static_cast<const GrGLPath*>(path);

<<<<<<< HEAD
    this->flushPathStencilSettings(stencilPassSettings);
    SkASSERT(!fHWPathStencilSettings.isTwoSided());

    GrGLenum fillMode = gr_stencil_op_to_gl_path_rendering_fill_mode(fHWPathStencilSettings.front().fPassOp);
    GrGLint writeMask = fHWPathStencilSettings.front().fWriteMask;
=======
    this->flushPathStencilSettings(*args.fStencil);
    SkASSERT(!fHWPathStencilSettings.isTwoSided());

    GrGLenum fillMode = gr_stencil_op_to_gl_path_rendering_fill_mode(
        fHWPathStencilSettings.passOp(GrStencilSettings::kFront_Face));
    GrGLint writeMask = fHWPathStencilSettings.writeMask(GrStencilSettings::kFront_Face);
>>>>>>> miniblink49

    if (glPath->shouldStroke()) {
        if (glPath->shouldFill()) {
            GL_CALL(StencilFillPath(glPath->pathID(), fillMode, writeMask));
        }
        GL_CALL(StencilThenCoverStrokePath(glPath->pathID(), 0xffff, writeMask,
<<<<<<< HEAD
            GR_GL_BOUNDING_BOX));
    } else {
        GL_CALL(StencilThenCoverFillPath(glPath->pathID(), fillMode, writeMask,
            GR_GL_BOUNDING_BOX));
    }
}

void GrGLPathRendering::onDrawPaths(const GrPipeline& pipeline,
    const GrPrimitiveProcessor& primProc,
    const GrStencilSettings& stencilPassSettings,
    const GrPathRange* pathRange, const void* indices,
    PathIndexType indexType, const float transformValues[],
    PathTransformType transformType, int count)
{
    SkDEBUGCODE(verify_floats(transformValues, gXformType2ComponentCount[transformType] * count));

    if (!this->gpu()->flushGLState(pipeline, primProc)) {
        return;
    }
    this->flushPathStencilSettings(stencilPassSettings);
    SkASSERT(!fHWPathStencilSettings.isTwoSided());

    const GrGLPathRange* glPathRange = static_cast<const GrGLPathRange*>(pathRange);

    GrGLenum fillMode = gr_stencil_op_to_gl_path_rendering_fill_mode(fHWPathStencilSettings.front().fPassOp);
    GrGLint writeMask = fHWPathStencilSettings.front().fWriteMask;
=======
                                           GR_GL_BOUNDING_BOX));
    } else {
        GL_CALL(StencilThenCoverFillPath(glPath->pathID(), fillMode, writeMask,
                                         GR_GL_BOUNDING_BOX));
    }
}

void GrGLPathRendering::onDrawPaths(const DrawPathArgs& args, const GrPathRange* pathRange,
                                    const void* indices, PathIndexType indexType,
                                    const float transformValues[], PathTransformType transformType,
                                    int count) {
    if (!this->gpu()->flushGLState(args)) {
        return;
    }
    this->flushPathStencilSettings(*args.fStencil);
    SkASSERT(!fHWPathStencilSettings.isTwoSided());


    const GrGLPathRange* glPathRange = static_cast<const GrGLPathRange*>(pathRange);

    GrGLenum fillMode =
        gr_stencil_op_to_gl_path_rendering_fill_mode(
            fHWPathStencilSettings.passOp(GrStencilSettings::kFront_Face));
    GrGLint writeMask =
        fHWPathStencilSettings.writeMask(GrStencilSettings::kFront_Face);
>>>>>>> miniblink49

    if (glPathRange->shouldStroke()) {
        if (glPathRange->shouldFill()) {
            GL_CALL(StencilFillPathInstanced(
<<<<<<< HEAD
                count, gIndexType2GLType[indexType], indices, glPathRange->basePathID(),
                fillMode, writeMask, gXformType2GLType[transformType],
                transformValues));
        }
        GL_CALL(StencilThenCoverStrokePathInstanced(
            count, gIndexType2GLType[indexType], indices, glPathRange->basePathID(),
            0xffff, writeMask, GR_GL_BOUNDING_BOX_OF_BOUNDING_BOXES,
            gXformType2GLType[transformType], transformValues));
    } else {
        GL_CALL(StencilThenCoverFillPathInstanced(
            count, gIndexType2GLType[indexType], indices, glPathRange->basePathID(),
            fillMode, writeMask, GR_GL_BOUNDING_BOX_OF_BOUNDING_BOXES,
            gXformType2GLType[transformType], transformValues));
=======
                            count, gIndexType2GLType[indexType], indices, glPathRange->basePathID(),
                            fillMode, writeMask, gXformType2GLType[transformType],
                            transformValues));
        }
        GL_CALL(StencilThenCoverStrokePathInstanced(
                            count, gIndexType2GLType[indexType], indices, glPathRange->basePathID(),
                            0xffff, writeMask, GR_GL_BOUNDING_BOX_OF_BOUNDING_BOXES,
                            gXformType2GLType[transformType], transformValues));
    } else {
        GL_CALL(StencilThenCoverFillPathInstanced(
                            count, gIndexType2GLType[indexType], indices, glPathRange->basePathID(),
                            fillMode, writeMask, GR_GL_BOUNDING_BOX_OF_BOUNDING_BOXES,
                            gXformType2GLType[transformType], transformValues));
>>>>>>> miniblink49
    }
}

void GrGLPathRendering::setProgramPathFragmentInputTransform(GrGLuint program, GrGLint location,
<<<<<<< HEAD
    GrGLenum genMode, GrGLint components,
    const SkMatrix& matrix)
{
    float coefficients[3 * 3];
=======
                                                             GrGLenum genMode, GrGLint components,
                                                             const SkMatrix& matrix) {
    GrGLfloat coefficients[3 * 3];
>>>>>>> miniblink49
    SkASSERT(components >= 1 && components <= 3);

    coefficients[0] = SkScalarToFloat(matrix[SkMatrix::kMScaleX]);
    coefficients[1] = SkScalarToFloat(matrix[SkMatrix::kMSkewX]);
    coefficients[2] = SkScalarToFloat(matrix[SkMatrix::kMTransX]);

    if (components >= 2) {
        coefficients[3] = SkScalarToFloat(matrix[SkMatrix::kMSkewY]);
        coefficients[4] = SkScalarToFloat(matrix[SkMatrix::kMScaleY]);
        coefficients[5] = SkScalarToFloat(matrix[SkMatrix::kMTransY]);
    }

    if (components >= 3) {
        coefficients[6] = SkScalarToFloat(matrix[SkMatrix::kMPersp0]);
        coefficients[7] = SkScalarToFloat(matrix[SkMatrix::kMPersp1]);
        coefficients[8] = SkScalarToFloat(matrix[SkMatrix::kMPersp2]);
    }
<<<<<<< HEAD
    SkDEBUGCODE(verify_floats(coefficients, components * 3));
=======
>>>>>>> miniblink49

    GL_CALL(ProgramPathFragmentInputGen(program, location, genMode, components, coefficients));
}

void GrGLPathRendering::setProjectionMatrix(const SkMatrix& matrix,
<<<<<<< HEAD
    const SkISize& renderTargetSize,
    GrSurfaceOrigin renderTargetOrigin)
{

    SkASSERT(this->gpu()->glCaps().shaderCaps()->pathRenderingSupport());

    if (renderTargetOrigin == fHWProjectionMatrixState.fRenderTargetOrigin && renderTargetSize == fHWProjectionMatrixState.fRenderTargetSize && matrix.cheapEqualTo(fHWProjectionMatrixState.fViewMatrix)) {
=======
                                            const SkISize& renderTargetSize,
                                            GrSurfaceOrigin renderTargetOrigin) {

    SkASSERT(this->gpu()->glCaps().shaderCaps()->pathRenderingSupport());

    if (renderTargetOrigin == fHWProjectionMatrixState.fRenderTargetOrigin &&
        renderTargetSize == fHWProjectionMatrixState.fRenderTargetSize &&
        matrix.cheapEqualTo(fHWProjectionMatrixState.fViewMatrix)) {
>>>>>>> miniblink49
        return;
    }

    fHWProjectionMatrixState.fViewMatrix = matrix;
    fHWProjectionMatrixState.fRenderTargetSize = renderTargetSize;
    fHWProjectionMatrixState.fRenderTargetOrigin = renderTargetOrigin;

<<<<<<< HEAD
    float glMatrix[4 * 4];
    fHWProjectionMatrixState.getRTAdjustedGLMatrix<4>(glMatrix);
    SkDEBUGCODE(verify_floats(glMatrix, SK_ARRAY_COUNT(glMatrix)));
    GL_CALL(MatrixLoadf(GR_GL_PATH_PROJECTION, glMatrix));
}

GrGLuint GrGLPathRendering::genPaths(GrGLsizei range)
{
    SkASSERT(range > 0);
    GrGLuint firstID;
    if (fPreallocatedPathCount >= range) {
        firstID = fFirstPreallocatedPathID;
        fPreallocatedPathCount -= range;
        fFirstPreallocatedPathID += range;
        return firstID;
    }
    // Allocate range + the amount to fill up preallocation amount. If succeed, either join with
    // the existing preallocation range or delete the existing and use the new (potentially partial)
    // preallocation range.
    GrGLsizei allocAmount = range + (kPathIDPreallocationAmount - fPreallocatedPathCount);
    if (allocAmount >= range) {
        GL_CALL_RET(firstID, GenPaths(allocAmount));

        if (firstID != 0) {
            if (fPreallocatedPathCount > 0 && firstID == fFirstPreallocatedPathID + fPreallocatedPathCount) {
                firstID = fFirstPreallocatedPathID;
                fPreallocatedPathCount += allocAmount - range;
                fFirstPreallocatedPathID += range;
                return firstID;
            }

            if (allocAmount > range) {
                if (fPreallocatedPathCount > 0) {
                    this->deletePaths(fFirstPreallocatedPathID, fPreallocatedPathCount);
                }
                fFirstPreallocatedPathID = firstID + range;
                fPreallocatedPathCount = allocAmount - range;
            }
            // Special case: if allocAmount == range, we have full preallocated range.
            return firstID;
        }
    }
    // Failed to allocate with preallocation. Remove existing preallocation and try to allocate just
    // the range.
    if (fPreallocatedPathCount > 0) {
        this->deletePaths(fFirstPreallocatedPathID, fPreallocatedPathCount);
        fPreallocatedPathCount = 0;
    }

    GL_CALL_RET(firstID, GenPaths(range));
    if (firstID == 0) {
        SkDebugf("Warning: Failed to allocate path\n");
    }
    return firstID;
}

void GrGLPathRendering::deletePaths(GrGLuint path, GrGLsizei range)
{
    GL_CALL(DeletePaths(path, range));
}

void GrGLPathRendering::flushPathStencilSettings(const GrStencilSettings& stencilSettings)
{
    if (fHWPathStencilSettings != stencilSettings) {
        SkASSERT(stencilSettings.isValid());
        // Just the func, ref, and mask is set here. The op and write mask are params to the call
        // that draws the path to the SB (glStencilFillPath)
        uint16_t ref = stencilSettings.front().fRef;
        GrStencilTest test = stencilSettings.front().fTest;
        uint16_t testMask = stencilSettings.front().fTestMask;

        if (!fHWPathStencilSettings.isValid() || ref != fHWPathStencilSettings.front().fRef || test != fHWPathStencilSettings.front().fTest || testMask != fHWPathStencilSettings.front().fTestMask) {
            GL_CALL(PathStencilFunc(GrToGLStencilFunc(test), ref, testMask));
        }
=======
    GrGLfloat glMatrix[4 * 4];
    fHWProjectionMatrixState.getRTAdjustedGLMatrix<4>(glMatrix);
    GL_CALL(MatrixLoadf(GR_GL_PATH_PROJECTION, glMatrix));
}

GrGLuint GrGLPathRendering::genPaths(GrGLsizei range) {
    if (range > 1) {
        GrGLuint name;
        GL_CALL_RET(name, GenPaths(range));
        return name;
    }

    if (NULL == fPathNameAllocator.get()) {
        static const int range = 65536;
        GrGLuint firstName;
        GL_CALL_RET(firstName, GenPaths(range));
        fPathNameAllocator.reset(SkNEW_ARGS(GrGLNameAllocator, (firstName, firstName + range)));
    }

    // When allocating names one at a time, pull from a client-side pool of
    // available names in order to save a round trip to the GL server.
    GrGLuint name = fPathNameAllocator->allocateName();

    if (0 == name) {
        // Our reserved path names are all in use. Fall back on GenPaths.
        GL_CALL_RET(name, GenPaths(1));
    }

    return name;
}

void GrGLPathRendering::deletePaths(GrGLuint path, GrGLsizei range) {
    if (range > 1) {
        // It is not supported to delete names in ranges that were allocated
        // individually using GrGLPathNameAllocator.
        SkASSERT(NULL == fPathNameAllocator.get() ||
                 path + range <= fPathNameAllocator->firstName() ||
                 path >= fPathNameAllocator->endName());
        GL_CALL(DeletePaths(path, range));
        return;
    }

    if (NULL == fPathNameAllocator.get() ||
        path < fPathNameAllocator->firstName() ||
        path >= fPathNameAllocator->endName()) {
        // If we aren't inside fPathNameAllocator's range then this name was
        // generated by the GenPaths fallback (or else was never allocated).
        GL_CALL(DeletePaths(path, 1));
        return;
    }

    // Make the path empty to save memory, but don't free the name in the driver.
    GL_CALL(PathCommands(path, 0, NULL, 0, GR_GL_FLOAT, NULL));
    fPathNameAllocator->free(path);
}

void GrGLPathRendering::flushPathStencilSettings(const GrStencilSettings& stencilSettings) {
    if (fHWPathStencilSettings != stencilSettings) {
        // Just the func, ref, and mask is set here. The op and write mask are params to the call
        // that draws the path to the SB (glStencilFillPath)
        GrGLenum func =
            GrToGLStencilFunc(stencilSettings.func(GrStencilSettings::kFront_Face));
        GL_CALL(PathStencilFunc(func, stencilSettings.funcRef(GrStencilSettings::kFront_Face),
                                stencilSettings.funcMask(GrStencilSettings::kFront_Face)));

>>>>>>> miniblink49
        fHWPathStencilSettings = stencilSettings;
    }
}

<<<<<<< HEAD
inline GrGLGpu* GrGLPathRendering::gpu()
{
=======
inline GrGLGpu* GrGLPathRendering::gpu() {
>>>>>>> miniblink49
    return static_cast<GrGLGpu*>(fGpu);
}
