/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrPipeline.h"

#include "GrCaps.h"
<<<<<<< HEAD
#include "GrDrawContext.h"
#include "GrDrawTarget.h"
#include "GrGpu.h"
#include "GrPipelineBuilder.h"
#include "GrProcOptInfo.h"
#include "GrRenderTargetPriv.h"
#include "GrXferProcessor.h"

#include "batches/GrBatch.h"

GrPipeline* GrPipeline::CreateAt(void* memory, const CreateArgs& args,
    GrXPOverridesForBatch* overrides)
{
    const GrPipelineBuilder& builder = *args.fPipelineBuilder;

    GrPipeline* pipeline = new (memory) GrPipeline;
    GrRenderTarget* rt = args.fDrawContext->accessRenderTarget();
    pipeline->fRenderTarget.reset(rt);
    SkASSERT(pipeline->fRenderTarget);
    pipeline->fScissorState = *args.fScissor;
    if (builder.hasUserStencilSettings() || args.fHasStencilClip) {
        const GrRenderTargetPriv& rtPriv = rt->renderTargetPriv();
        pipeline->fStencilSettings.reset(*builder.getUserStencil(), args.fHasStencilClip,
            rtPriv.numStencilBits());
        SkASSERT(!pipeline->fStencilSettings.usesWrapOp() || args.fCaps->stencilWrapOpsSupport());
    }
    pipeline->fDrawFace = builder.getDrawFace();

    pipeline->fFlags = 0;
    if (builder.isHWAntialias()) {
        pipeline->fFlags |= kHWAA_Flag;
    }
    if (builder.snapVerticesToPixelCenters()) {
        pipeline->fFlags |= kSnapVertices_Flag;
    }
    if (builder.getDisableOutputConversionToSRGB()) {
        pipeline->fFlags |= kDisableOutputConversionToSRGB_Flag;
    }
    if (builder.getAllowSRGBInputs()) {
        pipeline->fFlags |= kAllowSRGBInputs_Flag;
    }
    if (args.fHasStencilClip) {
        pipeline->fFlags |= kHasStencilClip_Flag;
    }

    // Create XferProcessor from DS's XPFactory
    bool hasMixedSamples = args.fDrawContext->hasMixedSamples() && (builder.isHWAntialias() || !pipeline->fStencilSettings.isDisabled());
    const GrXPFactory* xpFactory = builder.getXPFactory();
    SkAutoTUnref<GrXferProcessor> xferProcessor;
    if (xpFactory) {
        xferProcessor.reset(xpFactory->createXferProcessor(args.fOpts,
            hasMixedSamples,
            &args.fDstTexture,
            *args.fCaps));
        if (!xferProcessor) {
            pipeline->~GrPipeline();
            return nullptr;
        }
    } else {
        // This may return nullptr in the common case of src-over implemented using hw blending.
        xferProcessor.reset(GrPorterDuffXPFactory::CreateSrcOverXferProcessor(
            *args.fCaps,
            args.fOpts,
            hasMixedSamples,
            &args.fDstTexture));
    }
    GrColor overrideColor = GrColor_ILLEGAL;
    if (args.fOpts.fColorPOI.firstEffectiveProcessorIndex() != 0) {
        overrideColor = args.fOpts.fColorPOI.inputColorToFirstEffectiveProccesor();
    }

    GrXferProcessor::OptFlags optFlags = GrXferProcessor::kNone_OptFlags;

    const GrXferProcessor* xpForOpts = xferProcessor ? xferProcessor.get() : &GrPorterDuffXPFactory::SimpleSrcOverXP();
    optFlags = xpForOpts->getOptimizations(args.fOpts,
        pipeline->fStencilSettings.doesWrite(),
        &overrideColor,
        *args.fCaps);

    // When path rendering the stencil settings are not always set on the GrPipelineBuilder
    // so we must check the draw type. In cases where we will skip drawing we simply return a
    // null GrPipeline.
    if (GrXferProcessor::kSkipDraw_OptFlag & optFlags) {
        pipeline->~GrPipeline();
        return nullptr;
=======
#include "GrBatch.h"
#include "GrGpu.h"
#include "GrPipelineBuilder.h"
#include "GrProcOptInfo.h"
#include "GrXferProcessor.h"

GrPipeline::GrPipeline(const GrPipelineBuilder& pipelineBuilder,
                       const GrProcOptInfo& colorPOI,
                       const GrProcOptInfo& coveragePOI,
                       const GrCaps& caps,
                       const GrScissorState& scissorState,
                       const GrXferProcessor::DstTexture* dstTexture) {
    // Create XferProcessor from DS's XPFactory
    SkAutoTUnref<GrXferProcessor> xferProcessor(
        pipelineBuilder.getXPFactory()->createXferProcessor(
            colorPOI, coveragePOI, pipelineBuilder.hasMixedSamples(), dstTexture, caps));

    GrColor overrideColor = GrColor_ILLEGAL;
    if (colorPOI.firstEffectiveStageIndex() != 0) {
        overrideColor = colorPOI.inputColorToEffectiveStage();
    }

    GrXferProcessor::OptFlags optFlags = GrXferProcessor::kNone_OptFlags;
    if (xferProcessor) {
        fXferProcessor.reset(xferProcessor.get());

        optFlags = xferProcessor->getOptimizations(colorPOI,
                                                   coveragePOI,
                                                   pipelineBuilder.getStencil().doesWrite(),
                                                   &overrideColor,
                                                   caps);
>>>>>>> miniblink49
    }

    // No need to have an override color if it isn't even going to be used.
    if (SkToBool(GrXferProcessor::kIgnoreColor_OptFlag & optFlags)) {
        overrideColor = GrColor_ILLEGAL;
    }

<<<<<<< HEAD
    pipeline->fXferProcessor.reset(xferProcessor);

    int firstColorProcessorIdx = args.fOpts.fColorPOI.firstEffectiveProcessorIndex();

    // TODO: Once we can handle single or four channel input into coverage GrFragmentProcessors
    // then we can use GrPipelineBuilder's coverageProcInfo (like color above) to set this initial
    // information.
    int firstCoverageProcessorIdx = 0;

    pipeline->adjustProgramFromOptimizations(builder, optFlags, args.fOpts.fColorPOI,
        args.fOpts.fCoveragePOI, &firstColorProcessorIdx,
        &firstCoverageProcessorIdx);

    bool usesLocalCoords = false;

    // Copy GrFragmentProcessors from GrPipelineBuilder to Pipeline
    pipeline->fNumColorProcessors = builder.numColorFragmentProcessors() - firstColorProcessorIdx;
    int numTotalProcessors = pipeline->fNumColorProcessors + builder.numCoverageFragmentProcessors() - firstCoverageProcessorIdx;
    pipeline->fFragmentProcessors.reset(numTotalProcessors);
    int currFPIdx = 0;
    for (int i = firstColorProcessorIdx; i < builder.numColorFragmentProcessors();
         ++i, ++currFPIdx) {
        const GrFragmentProcessor* fp = builder.getColorFragmentProcessor(i);
        pipeline->fFragmentProcessors[currFPIdx].reset(fp);
        usesLocalCoords = usesLocalCoords || fp->usesLocalCoords();
    }

    for (int i = firstCoverageProcessorIdx; i < builder.numCoverageFragmentProcessors();
         ++i, ++currFPIdx) {
        const GrFragmentProcessor* fp = builder.getCoverageFragmentProcessor(i);
        pipeline->fFragmentProcessors[currFPIdx].reset(fp);
        usesLocalCoords = usesLocalCoords || fp->usesLocalCoords();
    }

    // Setup info we need to pass to GrPrimitiveProcessors that are used with this GrPipeline.
    overrides->fFlags = 0;
    if (!SkToBool(optFlags & GrXferProcessor::kIgnoreColor_OptFlag)) {
        overrides->fFlags |= GrXPOverridesForBatch::kReadsColor_Flag;
    }
    if (GrColor_ILLEGAL != overrideColor) {
        overrides->fFlags |= GrXPOverridesForBatch::kUseOverrideColor_Flag;
        overrides->fOverrideColor = overrideColor;
    }
    if (!SkToBool(optFlags & GrXferProcessor::kIgnoreCoverage_OptFlag)) {
        overrides->fFlags |= GrXPOverridesForBatch::kReadsCoverage_Flag;
    }
    if (usesLocalCoords) {
        overrides->fFlags |= GrXPOverridesForBatch::kReadsLocalCoords_Flag;
    }
    if (SkToBool(optFlags & GrXferProcessor::kCanTweakAlphaForCoverage_OptFlag)) {
        overrides->fFlags |= GrXPOverridesForBatch::kCanTweakAlphaForCoverage_Flag;
    }

    GrXPFactory::InvariantBlendedColor blendedColor;
    if (xpFactory) {
        xpFactory->getInvariantBlendedColor(args.fOpts.fColorPOI, &blendedColor);
    } else {
        GrPorterDuffXPFactory::SrcOverInvariantBlendedColor(args.fOpts.fColorPOI.color(),
            args.fOpts.fColorPOI.validFlags(),
            args.fOpts.fColorPOI.isOpaque(),
            &blendedColor);
    }
    if (blendedColor.fWillBlendWithDst) {
        overrides->fFlags |= GrXPOverridesForBatch::kWillColorBlendWithDst_Flag;
    }

    return pipeline;
}

static void add_dependencies_for_processor(const GrFragmentProcessor* proc, GrRenderTarget* rt)
{
    for (int i = 0; i < proc->numChildProcessors(); ++i) {
        // need to recurse
        add_dependencies_for_processor(&proc->childProcessor(i), rt);
    }

    for (int i = 0; i < proc->numTextures(); ++i) {
        GrTexture* texture = proc->textureAccess(i).getTexture();
        SkASSERT(rt->getLastDrawTarget());
        rt->getLastDrawTarget()->addDependency(texture);
    }
}

void GrPipeline::addDependenciesTo(GrRenderTarget* rt) const
{
    for (int i = 0; i < fFragmentProcessors.count(); ++i) {
        add_dependencies_for_processor(fFragmentProcessors[i].get(), rt);
    }

    const GrXferProcessor& xfer = this->getXferProcessor();

    for (int i = 0; i < xfer.numTextures(); ++i) {
        GrTexture* texture = xfer.textureAccess(i).getTexture();
        SkASSERT(rt->getLastDrawTarget());
        rt->getLastDrawTarget()->addDependency(texture);
=======
    // When path rendering the stencil settings are not always set on the GrPipelineBuilder
    // so we must check the draw type. In cases where we will skip drawing we simply return a
    // null GrPipeline.
    if (!xferProcessor || (GrXferProcessor::kSkipDraw_OptFlag & optFlags)) {
        // Set the fields that don't default init and return. The lack of a render target will
        // indicate that this can be skipped.
        fFlags = 0;
        fDrawFace = GrPipelineBuilder::kInvalid_DrawFace;
        return;
    }

    fRenderTarget.reset(pipelineBuilder.fRenderTarget.get());
    SkASSERT(fRenderTarget);
    fScissorState = scissorState;
    fStencilSettings = pipelineBuilder.getStencil();
    fDrawFace = pipelineBuilder.getDrawFace();

    fFlags = 0;
    if (pipelineBuilder.isHWAntialias()) {
        fFlags |= kHWAA_Flag;
    }
    if (pipelineBuilder.isDither()) {
        fFlags |= kDither_Flag;
    }
    if (pipelineBuilder.snapVerticesToPixelCenters()) {
        fFlags |= kSnapVertices_Flag;
    }

    int firstColorStageIdx = colorPOI.firstEffectiveStageIndex();

    // TODO: Once we can handle single or four channel input into coverage stages then we can use
    // GrPipelineBuilder's coverageProcInfo (like color above) to set this initial information.
    int firstCoverageStageIdx = 0;

    this->adjustProgramFromOptimizations(pipelineBuilder, optFlags, colorPOI, coveragePOI,
                                         &firstColorStageIdx, &firstCoverageStageIdx);

    bool usesLocalCoords = false;

    // Copy Stages from PipelineBuilder to Pipeline
    for (int i = firstColorStageIdx; i < pipelineBuilder.numColorFragmentStages(); ++i) {
        SkNEW_APPEND_TO_TARRAY(&fFragmentStages,
                               GrPendingFragmentStage,
                               (pipelineBuilder.fColorStages[i]));
        usesLocalCoords = usesLocalCoords ||
                          pipelineBuilder.fColorStages[i].processor()->usesLocalCoords();
    }

    fNumColorStages = fFragmentStages.count();
    for (int i = firstCoverageStageIdx; i < pipelineBuilder.numCoverageFragmentStages(); ++i) {
        SkNEW_APPEND_TO_TARRAY(&fFragmentStages,
                               GrPendingFragmentStage,
                               (pipelineBuilder.fCoverageStages[i]));
        usesLocalCoords = usesLocalCoords ||
                          pipelineBuilder.fCoverageStages[i].processor()->usesLocalCoords();
    }

    // Setup info we need to pass to GrPrimitiveProcessors that are used with this GrPipeline.
    fInfoForPrimitiveProcessor.fFlags = 0;
    if (!SkToBool(optFlags & GrXferProcessor::kIgnoreColor_OptFlag)) {
        fInfoForPrimitiveProcessor.fFlags |= GrPipelineInfo::kReadsColor_GrPipelineInfoFlag;
    }
    if (GrColor_ILLEGAL != overrideColor) {
        fInfoForPrimitiveProcessor.fFlags |= GrPipelineInfo::kUseOverrideColor_GrPipelineInfoFlag;
        fInfoForPrimitiveProcessor.fOverrideColor = overrideColor;
    }
    if (!SkToBool(optFlags & GrXferProcessor::kIgnoreCoverage_OptFlag)) {
        fInfoForPrimitiveProcessor.fFlags |= GrPipelineInfo::kReadsCoverage_GrPipelineInfoFlag;
    }
    if (usesLocalCoords) {
        fInfoForPrimitiveProcessor.fFlags |= GrPipelineInfo::kReadsLocalCoords_GrPipelineInfoFlag;
    }
    if (SkToBool(optFlags & GrXferProcessor::kCanTweakAlphaForCoverage_OptFlag)) {
       fInfoForPrimitiveProcessor.fFlags |=
           GrPipelineInfo::kCanTweakAlphaForCoverage_GrPipelineInfoFlag; 
>>>>>>> miniblink49
    }
}

void GrPipeline::adjustProgramFromOptimizations(const GrPipelineBuilder& pipelineBuilder,
<<<<<<< HEAD
    GrXferProcessor::OptFlags flags,
    const GrProcOptInfo& colorPOI,
    const GrProcOptInfo& coveragePOI,
    int* firstColorProcessorIdx,
    int* firstCoverageProcessorIdx)
{
    fIgnoresCoverage = SkToBool(flags & GrXferProcessor::kIgnoreCoverage_OptFlag);

    if ((flags & GrXferProcessor::kIgnoreColor_OptFlag) || (flags & GrXferProcessor::kOverrideColor_OptFlag)) {
        *firstColorProcessorIdx = pipelineBuilder.numColorFragmentProcessors();
    }

    if (flags & GrXferProcessor::kIgnoreCoverage_OptFlag) {
        *firstCoverageProcessorIdx = pipelineBuilder.numCoverageFragmentProcessors();
=======
                                                GrXferProcessor::OptFlags flags,
                                                const GrProcOptInfo& colorPOI,
                                                const GrProcOptInfo& coveragePOI,
                                                int* firstColorStageIdx,
                                                int* firstCoverageStageIdx) {
    fReadsFragPosition = fXferProcessor->willReadFragmentPosition();

    if ((flags & GrXferProcessor::kIgnoreColor_OptFlag) ||
        (flags & GrXferProcessor::kOverrideColor_OptFlag)) {
        *firstColorStageIdx = pipelineBuilder.numColorFragmentStages();
    } else {
        if (coveragePOI.readsFragPosition()) {
            fReadsFragPosition = true;
        }
    }

    if (flags & GrXferProcessor::kIgnoreCoverage_OptFlag) {
        *firstCoverageStageIdx = pipelineBuilder.numCoverageFragmentStages();
    } else {
        if (coveragePOI.readsFragPosition()) {
            fReadsFragPosition = true;
        }
>>>>>>> miniblink49
    }
}

////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool GrPipeline::AreEqual(const GrPipeline& a, const GrPipeline& b,
    bool ignoreCoordTransforms)
{
    SkASSERT(&a != &b);

    if (a.getRenderTarget() != b.getRenderTarget() || a.fFragmentProcessors.count() != b.fFragmentProcessors.count() || a.fNumColorProcessors != b.fNumColorProcessors || a.fScissorState != b.fScissorState || a.fFlags != b.fFlags || a.fStencilSettings != b.fStencilSettings || a.fDrawFace != b.fDrawFace) {
        return false;
    }

    // Most of the time both are nullptr
    if (a.fXferProcessor.get() || b.fXferProcessor.get()) {
        if (!a.getXferProcessor().isEqual(b.getXferProcessor())) {
            return false;
        }
    }

    for (int i = 0; i < a.numFragmentProcessors(); i++) {
        if (!a.getFragmentProcessor(i).isEqual(b.getFragmentProcessor(i), ignoreCoordTransforms)) {
=======
bool GrPipeline::isEqual(const GrPipeline& that) const {
    if (this->getRenderTarget() != that.getRenderTarget() ||
        this->fFragmentStages.count() != that.fFragmentStages.count() ||
        this->fNumColorStages != that.fNumColorStages ||
        this->fScissorState != that.fScissorState ||
        this->fFlags != that.fFlags ||
        this->fStencilSettings != that.fStencilSettings ||
        this->fDrawFace != that.fDrawFace) {
        return false;
    }

    if (!this->getXferProcessor()->isEqual(*that.getXferProcessor())) {
        return false;
    }

    // The program desc comparison should have already assured that the stage counts match.
    SkASSERT(this->numFragmentStages() == that.numFragmentStages());
    for (int i = 0; i < this->numFragmentStages(); i++) {

        if (this->getFragmentStage(i) != that.getFragmentStage(i)) {
>>>>>>> miniblink49
            return false;
        }
    }
    return true;
}
<<<<<<< HEAD
=======

>>>>>>> miniblink49
