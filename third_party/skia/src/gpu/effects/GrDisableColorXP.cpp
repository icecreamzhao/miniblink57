/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "effects/GrDisableColorXP.h"
<<<<<<< HEAD
#include "GrPipeline.h"
#include "GrProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLXferProcessor.h"
=======
#include "GrProcessor.h"
#include "gl/GrGLXferProcessor.h"
#include "gl/builders/GrGLFragmentShaderBuilder.h"
#include "gl/builders/GrGLProgramBuilder.h"
>>>>>>> miniblink49

/**
 * This xfer processor disables color writing. Thus color and coverage and ignored and no blending
 * occurs. This XP is usful for things like stenciling.
 */
class DisableColorXP : public GrXferProcessor {
public:
<<<<<<< HEAD
    static GrXferProcessor* Create() { return new DisableColorXP; }
=======
    static GrXferProcessor* Create() {
        return SkNEW(DisableColorXP);
    }
>>>>>>> miniblink49

    ~DisableColorXP() override {};

    const char* name() const override { return "Disable Color"; }

<<<<<<< HEAD
    GrGLSLXferProcessor* createGLSLInstance() const override;
=======
    GrGLXferProcessor* createGLInstance() const override;
>>>>>>> miniblink49

private:
    DisableColorXP();

<<<<<<< HEAD
    GrXferProcessor::OptFlags onGetOptimizations(const GrPipelineOptimizations& optimizations,
        bool doesStencilWrite,
        GrColor* color,
        const GrCaps& caps) const override
    {
        return GrXferProcessor::kIgnoreColor_OptFlag | GrXferProcessor::kIgnoreCoverage_OptFlag;
    }

    void onGetGLSLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const override;

    void onGetBlendInfo(GrXferProcessor::BlendInfo* blendInfo) const override;

    bool onIsEqual(const GrXferProcessor& xpBase) const override
    {
=======
    GrXferProcessor::OptFlags onGetOptimizations(const GrProcOptInfo& colorPOI,
                                                 const GrProcOptInfo& coveragePOI,
                                                 bool doesStencilWrite,
                                                 GrColor* color,
                                                 const GrCaps& caps) override {
        return GrXferProcessor::kIgnoreColor_OptFlag | GrXferProcessor::kIgnoreCoverage_OptFlag;
    }

    void onGetGLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const override;

    void onGetBlendInfo(GrXferProcessor::BlendInfo* blendInfo) const override;

    bool onIsEqual(const GrXferProcessor& xpBase) const override {
>>>>>>> miniblink49
        return true;
    }

    typedef GrXferProcessor INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GLDisableColorXP : public GrGLSLXferProcessor {
public:
    GLDisableColorXP(const GrProcessor&) { }

    ~GLDisableColorXP() override { }

    static void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder*) { }

private:
    void emitOutputsForBlendState(const EmitArgs& args) override
    {
        // This emit code should be empty. However, on the nexus 6 there is a driver bug where if
        // you do not give gl_FragColor a value, the gl context is lost and we end up drawing
        // nothing. So this fix just sets the gl_FragColor arbitrarily to 0.
        GrGLSLXPFragmentBuilder* fragBuilder = args.fXPFragBuilder;
        fragBuilder->codeAppendf("%s = vec4(0);", args.fOutputPrimary);
    }

    void onSetData(const GrGLSLProgramDataManager&, const GrXferProcessor&) override { }

    typedef GrGLSLXferProcessor INHERITED;
=======
class GLDisableColorXP : public GrGLXferProcessor {
public:
    GLDisableColorXP(const GrProcessor&) {}

    ~GLDisableColorXP() override {}

    static void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder*) {}

private:
    void emitOutputsForBlendState(const EmitArgs& args) override {
        // This emit code should be empty. However, on the nexus 6 there is a driver bug where if
        // you do not give gl_FragColor a value, the gl context is lost and we end up drawing
        // nothing. So this fix just sets the gl_FragColor arbitrarily to 0.
        GrGLXPFragmentBuilder* fsBuilder = args.fPB->getFragmentShaderBuilder();
        fsBuilder->codeAppendf("%s = vec4(0);", args.fOutputPrimary);
    }

    void onSetData(const GrGLProgramDataManager&, const GrXferProcessor&) override {}

    typedef GrGLXferProcessor INHERITED;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DisableColorXP::DisableColorXP()
{
    this->initClassID<DisableColorXP>();
}

void DisableColorXP::onGetGLSLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const
{
    GLDisableColorXP::GenKey(*this, caps, b);
}

GrGLSLXferProcessor* DisableColorXP::createGLSLInstance() const { return new GLDisableColorXP(*this); }

void DisableColorXP::onGetBlendInfo(GrXferProcessor::BlendInfo* blendInfo) const
{
=======
DisableColorXP::DisableColorXP() {
    this->initClassID<DisableColorXP>();
}

void DisableColorXP::onGetGLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const {
    GLDisableColorXP::GenKey(*this, caps, b);
}

GrGLXferProcessor* DisableColorXP::createGLInstance() const {
    return SkNEW_ARGS(GLDisableColorXP, (*this));
}

void DisableColorXP::onGetBlendInfo(GrXferProcessor::BlendInfo* blendInfo) const {
>>>>>>> miniblink49
    blendInfo->fWriteColor = false;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrDisableColorXPFactory::GrDisableColorXPFactory()
{
=======
GrDisableColorXPFactory::GrDisableColorXPFactory() {
>>>>>>> miniblink49
    this->initClassID<GrDisableColorXPFactory>();
}

GrXferProcessor*
GrDisableColorXPFactory::onCreateXferProcessor(const GrCaps& caps,
<<<<<<< HEAD
    const GrPipelineOptimizations& optimizations,
    bool hasMixedSamples,
    const DstTexture* dst) const
{
    SkASSERT(!optimizations.fOverrides.fUsePLSDstRead);
=======
                                               const GrProcOptInfo& colorPOI,
                                               const GrProcOptInfo& covPOI,
                                               bool hasMixedSamples,
                                               const DstTexture* dst) const {
>>>>>>> miniblink49
    return DisableColorXP::Create();
}

GR_DEFINE_XP_FACTORY_TEST(GrDisableColorXPFactory);

<<<<<<< HEAD
sk_sp<GrXPFactory> GrDisableColorXPFactory::TestCreate(GrProcessorTestData*)
{
    return GrDisableColorXPFactory::Make();
}
=======
GrXPFactory* GrDisableColorXPFactory::TestCreate(GrProcessorTestData*) {
    return GrDisableColorXPFactory::Create();
}

>>>>>>> miniblink49
