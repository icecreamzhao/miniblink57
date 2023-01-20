/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkArithmeticMode_gpu.h"

#if SK_SUPPORT_GPU
#include "GrContext.h"
#include "GrFragmentProcessor.h"
#include "GrInvariantOutput.h"
#include "GrProcessor.h"
#include "GrTexture.h"
<<<<<<< HEAD
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
#include "glsl/GrGLSLXferProcessor.h"

static void add_arithmetic_code(GrGLSLFragmentBuilder* fragBuilder,
    const char* srcColor,
    const char* dstColor,
    const char* outputColor,
    const char* kUni,
    bool enforcePMColor)
{
    // We don't try to optimize for this case at all
    if (nullptr == srcColor) {
        fragBuilder->codeAppend("const vec4 src = vec4(1);");
    } else {
        fragBuilder->codeAppendf("vec4 src = %s;", srcColor);
    }

    fragBuilder->codeAppendf("vec4 dst = %s;", dstColor);
    fragBuilder->codeAppendf("%s = %s.x * src * dst + %s.y * src + %s.z * dst + %s.w;",
        outputColor, kUni, kUni, kUni, kUni);
    fragBuilder->codeAppendf("%s = clamp(%s, 0.0, 1.0);\n", outputColor, outputColor);
    if (enforcePMColor) {
        fragBuilder->codeAppendf("%s.rgb = min(%s.rgb, %s.a);",
            outputColor, outputColor, outputColor);
    }
}

class GLArithmeticFP : public GrGLSLFragmentProcessor {
public:
    void emitCode(EmitArgs& args) override
    {
        const GrArithmeticFP& arith = args.fFp.cast<GrArithmeticFP>();

        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        SkString dstColor("dstColor");
        this->emitChild(0, nullptr, &dstColor, args);

        fKUni = args.fUniformHandler->addUniform(kFragment_GrShaderFlag,
            kVec4f_GrSLType, kDefault_GrSLPrecision,
            "k");
        const char* kUni = args.fUniformHandler->getUniformCStr(fKUni);

        add_arithmetic_code(fragBuilder,
            args.fInputColor,
            dstColor.c_str(),
            args.fOutputColor,
            kUni,
            arith.enforcePMColor());
    }

    static void GenKey(const GrProcessor& proc, const GrGLSLCaps&, GrProcessorKeyBuilder* b)
    {
=======
#include "gl/GrGLCaps.h"
#include "gl/GrGLProcessor.h"
#include "gl/GrGLProgramDataManager.h"
#include "gl/builders/GrGLProgramBuilder.h"

static const bool gUseUnpremul = false;

static void add_arithmetic_code(GrGLFragmentBuilder* fsBuilder,
                                const char* inputColor,
                                const char* dstColor,
                                const char* outputColor,
                                const char* kUni,
                                bool enforcePMColor) {
    // We don't try to optimize for this case at all
    if (NULL == inputColor) {
        fsBuilder->codeAppend("const vec4 src = vec4(1);");
    } else {
        fsBuilder->codeAppendf("vec4 src = %s;", inputColor);
        if (gUseUnpremul) {
            fsBuilder->codeAppend("src.rgb = clamp(src.rgb / src.a, 0.0, 1.0);");
        }
    }

    fsBuilder->codeAppendf("vec4 dst = %s;", dstColor);
    if (gUseUnpremul) {
        fsBuilder->codeAppend("dst.rgb = clamp(dst.rgb / dst.a, 0.0, 1.0);");
    }

    fsBuilder->codeAppendf("%s = %s.x * src * dst + %s.y * src + %s.z * dst + %s.w;",
                           outputColor, kUni, kUni, kUni, kUni);
    fsBuilder->codeAppendf("%s = clamp(%s, 0.0, 1.0);\n", outputColor, outputColor);
    if (gUseUnpremul) {
        fsBuilder->codeAppendf("%s.rgb *= %s.a;", outputColor, outputColor);
    } else if (enforcePMColor) {
        fsBuilder->codeAppendf("%s.rgb = min(%s.rgb, %s.a);",
                               outputColor, outputColor, outputColor);
    }
}

class GLArithmeticFP : public GrGLFragmentProcessor {
public:
    GLArithmeticFP(const GrProcessor&)
        : fEnforcePMColor(true) {
    }

    ~GLArithmeticFP() override {}

    void emitCode(GrGLFPBuilder* builder,
                  const GrFragmentProcessor& fp,
                  const char* outputColor,
                  const char* inputColor,
                  const TransformedCoordsArray& coords,
                  const TextureSamplerArray& samplers) override {
        GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
        fsBuilder->codeAppend("vec4 bgColor = ");
        fsBuilder->appendTextureLookup(samplers[0], coords[0].c_str(), coords[0].getType());
        fsBuilder->codeAppendf(";");
        const char* dstColor = "bgColor";

        fKUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                    kVec4f_GrSLType, kDefault_GrSLPrecision,
                                    "k");
        const char* kUni = builder->getUniformCStr(fKUni);

        add_arithmetic_code(fsBuilder, inputColor, dstColor, outputColor, kUni, fEnforcePMColor);
    }

    void setData(const GrGLProgramDataManager& pdman, const GrProcessor& proc) override {
        const GrArithmeticFP& arith = proc.cast<GrArithmeticFP>();
        pdman.set4f(fKUni, arith.k1(), arith.k2(), arith.k3(), arith.k4());
        fEnforcePMColor = arith.enforcePMColor();
    }

    static void GenKey(const GrProcessor& proc, const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
        const GrArithmeticFP& arith = proc.cast<GrArithmeticFP>();
        uint32_t key = arith.enforcePMColor() ? 1 : 0;
        b->add32(key);
    }

<<<<<<< HEAD
protected:
    void onSetData(const GrGLSLProgramDataManager& pdman, const GrProcessor& proc) override
    {
        const GrArithmeticFP& arith = proc.cast<GrArithmeticFP>();
        pdman.set4f(fKUni, arith.k1(), arith.k2(), arith.k3(), arith.k4());
    }

private:
    GrGLSLProgramDataManager::UniformHandle fKUni;

    typedef GrGLSLFragmentProcessor INHERITED;
=======
private:
    GrGLProgramDataManager::UniformHandle fKUni;
    bool fEnforcePMColor;

    typedef GrGLFragmentProcessor INHERITED;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrArithmeticFP::GrArithmeticFP(float k1, float k2, float k3, float k4, bool enforcePMColor,
    sk_sp<GrFragmentProcessor> dst)
    : fK1(k1)
    , fK2(k2)
    , fK3(k3)
    , fK4(k4)
    , fEnforcePMColor(enforcePMColor)
{
    this->initClassID<GrArithmeticFP>();

    SkASSERT(dst);
    SkDEBUGCODE(int dstIndex =) this->registerChildProcessor(std::move(dst));
    SkASSERT(0 == dstIndex);
}

void GrArithmeticFP::onGetGLSLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const
{
    GLArithmeticFP::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* GrArithmeticFP::onCreateGLSLInstance() const
{
    return new GLArithmeticFP;
}

bool GrArithmeticFP::onIsEqual(const GrFragmentProcessor& fpBase) const
{
    const GrArithmeticFP& fp = fpBase.cast<GrArithmeticFP>();
    return fK1 == fp.fK1 && fK2 == fp.fK2 && fK3 == fp.fK3 && fK4 == fp.fK4 && fEnforcePMColor == fp.fEnforcePMColor;
}

void GrArithmeticFP::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
=======
GrArithmeticFP::GrArithmeticFP(GrProcessorDataManager*, float k1, float k2, float k3, float k4,
                               bool enforcePMColor, GrTexture* background)
  : fK1(k1), fK2(k2), fK3(k3), fK4(k4), fEnforcePMColor(enforcePMColor) {
    this->initClassID<GrArithmeticFP>();

    SkASSERT(background);

    fBackgroundTransform.reset(kLocal_GrCoordSet, background,
                               GrTextureParams::kNone_FilterMode);
    this->addCoordTransform(&fBackgroundTransform);
    fBackgroundAccess.reset(background);
    this->addTextureAccess(&fBackgroundAccess);
}

void GrArithmeticFP::getGLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const {
    GLArithmeticFP::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* GrArithmeticFP::createGLInstance() const {
    return SkNEW_ARGS(GLArithmeticFP, (*this));
}

bool GrArithmeticFP::onIsEqual(const GrFragmentProcessor& fpBase) const {
    const GrArithmeticFP& fp = fpBase.cast<GrArithmeticFP>();
    return fK1 == fp.fK1 &&
           fK2 == fp.fK2 &&
           fK3 == fp.fK3 &&
           fK4 == fp.fK4 &&
           fEnforcePMColor == fp.fEnforcePMColor;
}

void GrArithmeticFP::onComputeInvariantOutput(GrInvariantOutput* inout) const {
>>>>>>> miniblink49
    // TODO: optimize this
    inout->setToUnknown(GrInvariantOutput::kWill_ReadInput);
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrArithmeticFP::TestCreate(GrProcessorTestData* d)
{
=======
GrFragmentProcessor* GrArithmeticFP::TestCreate(GrProcessorTestData* d) {
>>>>>>> miniblink49
    float k1 = d->fRandom->nextF();
    float k2 = d->fRandom->nextF();
    float k3 = d->fRandom->nextF();
    float k4 = d->fRandom->nextF();
    bool enforcePMColor = d->fRandom->nextBool();

<<<<<<< HEAD
    sk_sp<GrFragmentProcessor> dst(GrProcessorUnitTest::MakeChildFP(d));
    return GrArithmeticFP::Make(k1, k2, k3, k4, enforcePMColor, std::move(dst));
=======
    return SkNEW_ARGS(GrArithmeticFP, (d->fProcDataManager, k1, k2, k3, k4, enforcePMColor,
                                       d->fTextures[0]));
>>>>>>> miniblink49
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrArithmeticFP);

///////////////////////////////////////////////////////////////////////////////
// Xfer Processor
///////////////////////////////////////////////////////////////////////////////

class ArithmeticXP : public GrXferProcessor {
public:
    ArithmeticXP(const DstTexture*, bool hasMixedSamples,
<<<<<<< HEAD
        float k1, float k2, float k3, float k4, bool enforcePMColor);

    const char* name() const override { return "Arithmetic"; }

    GrGLSLXferProcessor* createGLSLInstance() const override;
=======
                 float k1, float k2, float k3, float k4, bool enforcePMColor);

    const char* name() const override { return "Arithmetic"; }

    GrGLXferProcessor* createGLInstance() const override;
>>>>>>> miniblink49

    float k1() const { return fK1; }
    float k2() const { return fK2; }
    float k3() const { return fK3; }
    float k4() const { return fK4; }
    bool enforcePMColor() const { return fEnforcePMColor; }

private:
<<<<<<< HEAD
    GrXferProcessor::OptFlags onGetOptimizations(const GrPipelineOptimizations& optimizations,
        bool doesStencilWrite,
        GrColor* overrideColor,
        const GrCaps& caps) const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const override;

    bool onIsEqual(const GrXferProcessor& xpBase) const override
    {
        const ArithmeticXP& xp = xpBase.cast<ArithmeticXP>();
        if (fK1 != xp.fK1 || fK2 != xp.fK2 || fK3 != xp.fK3 || fK4 != xp.fK4 || fEnforcePMColor != xp.fEnforcePMColor) {
=======
    GrXferProcessor::OptFlags onGetOptimizations(const GrProcOptInfo& colorPOI,
                                                 const GrProcOptInfo& coveragePOI,
                                                 bool doesStencilWrite,
                                                 GrColor* overrideColor,
                                                 const GrCaps& caps) override;

    void onGetGLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const override;

    bool onIsEqual(const GrXferProcessor& xpBase) const override {
        const ArithmeticXP& xp = xpBase.cast<ArithmeticXP>();
        if (fK1 != xp.fK1 ||
            fK2 != xp.fK2 ||
            fK3 != xp.fK3 ||
            fK4 != xp.fK4 ||
            fEnforcePMColor != xp.fEnforcePMColor) {
>>>>>>> miniblink49
            return false;
        }
        return true;
    }

<<<<<<< HEAD
    float fK1, fK2, fK3, fK4;
    bool fEnforcePMColor;
=======
    float                       fK1, fK2, fK3, fK4;
    bool                        fEnforcePMColor;
>>>>>>> miniblink49

    typedef GrXferProcessor INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GLArithmeticXP : public GrGLSLXferProcessor {
public:
    GLArithmeticXP(const ArithmeticXP& arithmeticXP)
        : fEnforcePMColor(arithmeticXP.enforcePMColor())
    {
    }

    ~GLArithmeticXP() override { }

    static void GenKey(const GrProcessor& processor, const GrGLSLCaps& caps,
        GrProcessorKeyBuilder* b)
    {
=======
class GLArithmeticXP : public GrGLXferProcessor {
public:
    GLArithmeticXP(const GrProcessor&)
        : fEnforcePMColor(true) {
    }

    ~GLArithmeticXP() override {}

    static void GenKey(const GrProcessor& processor, const GrGLSLCaps& caps,
                       GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
        const ArithmeticXP& arith = processor.cast<ArithmeticXP>();
        uint32_t key = arith.enforcePMColor() ? 1 : 0;
        b->add32(key);
    }

private:
<<<<<<< HEAD
    void emitBlendCodeForDstRead(GrGLSLXPFragmentBuilder* fragBuilder,
        GrGLSLUniformHandler* uniformHandler,
        const char* srcColor,
        const char* srcCoverage,
        const char* dstColor,
        const char* outColor,
        const char* outColorSecondary,
        const GrXferProcessor& proc) override
    {
        fKUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
            kVec4f_GrSLType, kDefault_GrSLPrecision,
            "k");
        const char* kUni = uniformHandler->getUniformCStr(fKUni);

        add_arithmetic_code(fragBuilder, srcColor, dstColor, outColor, kUni, fEnforcePMColor);

        // Apply coverage.
        INHERITED::DefaultCoverageModulation(fragBuilder, srcCoverage, dstColor, outColor,
            outColorSecondary, proc);
    }

    void onSetData(const GrGLSLProgramDataManager& pdman,
        const GrXferProcessor& processor) override
    {
=======
    void emitBlendCodeForDstRead(GrGLXPBuilder* pb, const char* srcColor, const char* dstColor,
                                 const char* outColor, const GrXferProcessor& proc) override {
        GrGLXPFragmentBuilder* fsBuilder = pb->getFragmentShaderBuilder();

        fKUni = pb->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                               kVec4f_GrSLType, kDefault_GrSLPrecision,
                               "k");
        const char* kUni = pb->getUniformCStr(fKUni);

        add_arithmetic_code(fsBuilder, srcColor, dstColor, outColor, kUni, fEnforcePMColor);
    }

    void onSetData(const GrGLProgramDataManager& pdman,
                   const GrXferProcessor& processor) override {
>>>>>>> miniblink49
        const ArithmeticXP& arith = processor.cast<ArithmeticXP>();
        pdman.set4f(fKUni, arith.k1(), arith.k2(), arith.k3(), arith.k4());
        fEnforcePMColor = arith.enforcePMColor();
    };

<<<<<<< HEAD
    GrGLSLProgramDataManager::UniformHandle fKUni;
    bool fEnforcePMColor;

    typedef GrGLSLXferProcessor INHERITED;
=======
    GrGLProgramDataManager::UniformHandle fKUni;
    bool fEnforcePMColor;

    typedef GrGLXferProcessor INHERITED;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

ArithmeticXP::ArithmeticXP(const DstTexture* dstTexture, bool hasMixedSamples,
<<<<<<< HEAD
    float k1, float k2, float k3, float k4, bool enforcePMColor)
=======
                           float k1, float k2, float k3, float k4, bool enforcePMColor)
>>>>>>> miniblink49
    : INHERITED(dstTexture, true, hasMixedSamples)
    , fK1(k1)
    , fK2(k2)
    , fK3(k3)
    , fK4(k4)
<<<<<<< HEAD
    , fEnforcePMColor(enforcePMColor)
{
    this->initClassID<ArithmeticXP>();
}

void ArithmeticXP::onGetGLSLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const
{
    GLArithmeticXP::GenKey(*this, caps, b);
}

GrGLSLXferProcessor* ArithmeticXP::createGLSLInstance() const { return new GLArithmeticXP(*this); }

GrXferProcessor::OptFlags ArithmeticXP::onGetOptimizations(
    const GrPipelineOptimizations& optimizations,
    bool doesStencilWrite,
    GrColor* overrideColor,
    const GrCaps& caps) const
{
    return GrXferProcessor::kNone_OptFlags;
=======
    , fEnforcePMColor(enforcePMColor) {
    this->initClassID<ArithmeticXP>();
}

void ArithmeticXP::onGetGLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const {
    GLArithmeticXP::GenKey(*this, caps, b);
}

GrGLXferProcessor* ArithmeticXP::createGLInstance() const {
    return SkNEW_ARGS(GLArithmeticXP, (*this));
}

GrXferProcessor::OptFlags ArithmeticXP::onGetOptimizations(const GrProcOptInfo& colorPOI,
                                                           const GrProcOptInfo& coveragePOI,
                                                           bool doesStencilWrite,
                                                           GrColor* overrideColor,
                                                           const GrCaps& caps) {
   return GrXferProcessor::kNone_OptFlags;
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

GrArithmeticXPFactory::GrArithmeticXPFactory(float k1, float k2, float k3, float k4,
<<<<<<< HEAD
    bool enforcePMColor)
    : fK1(k1)
    , fK2(k2)
    , fK3(k3)
    , fK4(k4)
    , fEnforcePMColor(enforcePMColor)
{
=======
                                             bool enforcePMColor) 
    : fK1(k1), fK2(k2), fK3(k3), fK4(k4), fEnforcePMColor(enforcePMColor) {
>>>>>>> miniblink49
    this->initClassID<GrArithmeticXPFactory>();
}

GrXferProcessor*
GrArithmeticXPFactory::onCreateXferProcessor(const GrCaps& caps,
<<<<<<< HEAD
    const GrPipelineOptimizations& optimizations,
    bool hasMixedSamples,
    const DstTexture* dstTexture) const
{
    return new ArithmeticXP(dstTexture, hasMixedSamples, fK1, fK2, fK3, fK4, fEnforcePMColor);
}

void GrArithmeticXPFactory::getInvariantBlendedColor(const GrProcOptInfo& colorPOI,
    InvariantBlendedColor* blendedColor) const
{
=======
                                             const GrProcOptInfo& colorPOI,
                                             const GrProcOptInfo& coveragePOI,
                                             bool hasMixedSamples,
                                             const DstTexture* dstTexture) const {
    return SkNEW_ARGS(ArithmeticXP, (dstTexture, hasMixedSamples, fK1, fK2, fK3, fK4,
                                     fEnforcePMColor));
}


void GrArithmeticXPFactory::getInvariantBlendedColor(const GrProcOptInfo& colorPOI,
                                                     InvariantBlendedColor* blendedColor) const {
>>>>>>> miniblink49
    blendedColor->fWillBlendWithDst = true;

    // TODO: We could try to optimize this more. For example if fK1 and fK3 are zero, then we won't
    // be blending the color with dst at all so we can know what the output color is (up to the
    // valid color components passed in).
    blendedColor->fKnownColorFlags = kNone_GrColorComponentFlags;
}

GR_DEFINE_XP_FACTORY_TEST(GrArithmeticXPFactory);

<<<<<<< HEAD
sk_sp<GrXPFactory> GrArithmeticXPFactory::TestCreate(GrProcessorTestData* d)
{
=======
GrXPFactory* GrArithmeticXPFactory::TestCreate(GrProcessorTestData* d) {
>>>>>>> miniblink49
    float k1 = d->fRandom->nextF();
    float k2 = d->fRandom->nextF();
    float k3 = d->fRandom->nextF();
    float k4 = d->fRandom->nextF();
    bool enforcePMColor = d->fRandom->nextBool();

<<<<<<< HEAD
    return GrArithmeticXPFactory::Make(k1, k2, k3, k4, enforcePMColor);
=======
    return GrArithmeticXPFactory::Create(k1, k2, k3, k4, enforcePMColor);
>>>>>>> miniblink49
}

#endif
