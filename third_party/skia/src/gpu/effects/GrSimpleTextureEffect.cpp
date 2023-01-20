/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrSimpleTextureEffect.h"
#include "GrInvariantOutput.h"
#include "GrTexture.h"
<<<<<<< HEAD
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"

class GrGLSimpleTextureEffect : public GrGLSLFragmentProcessor {
public:
    void emitCode(EmitArgs& args) override
    {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        fragBuilder->codeAppendf("%s = ", args.fOutputColor);
        fragBuilder->appendTextureLookupAndModulate(args.fInputColor,
            args.fTexSamplers[0],
            args.fCoords[0].c_str(),
            args.fCoords[0].getType());
        fragBuilder->codeAppend(";");
    }

private:
    typedef GrGLSLFragmentProcessor INHERITED;
=======
#include "gl/GrGLCaps.h"
#include "gl/GrGLProcessor.h"
#include "gl/GrGLTexture.h"
#include "gl/builders/GrGLProgramBuilder.h"

class GrGLSimpleTextureEffect : public GrGLFragmentProcessor {
public:
    GrGLSimpleTextureEffect(const GrProcessor&) {}

    virtual void emitCode(GrGLFPBuilder* builder,
                          const GrFragmentProcessor& fp,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray& coords,
                          const TextureSamplerArray& samplers) override {
        GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
        fsBuilder->codeAppendf("\t%s = ", outputColor);
        fsBuilder->appendTextureLookupAndModulate(inputColor,
                                                  samplers[0],
                                                  coords[0].c_str(),
                                                  coords[0].getType());
        fsBuilder->codeAppend(";\n");
    }

private:
    typedef GrGLFragmentProcessor INHERITED;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrSimpleTextureEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
    this->updateInvariantOutputForModulation(inout);
}

void GrSimpleTextureEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLSimpleTextureEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* GrSimpleTextureEffect::onCreateGLSLInstance() const
{
    return new GrGLSimpleTextureEffect;
=======
void GrSimpleTextureEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const {
    this->updateInvariantOutputForModulation(inout);
}

void GrSimpleTextureEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                              GrProcessorKeyBuilder* b) const {
    GrGLSimpleTextureEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* GrSimpleTextureEffect::createGLInstance() const  {
    return SkNEW_ARGS(GrGLSimpleTextureEffect, (*this));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrSimpleTextureEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrSimpleTextureEffect::TestCreate(GrProcessorTestData* d)
{
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx : GrProcessorUnitTest::kAlphaTextureIdx;
=======
GrFragmentProcessor* GrSimpleTextureEffect::TestCreate(GrProcessorTestData* d) {
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx :
                                          GrProcessorUnitTest::kAlphaTextureIdx;
>>>>>>> miniblink49
    static const SkShader::TileMode kTileModes[] = {
        SkShader::kClamp_TileMode,
        SkShader::kRepeat_TileMode,
        SkShader::kMirror_TileMode,
    };
    SkShader::TileMode tileModes[] = {
        kTileModes[d->fRandom->nextULessThan(SK_ARRAY_COUNT(kTileModes))],
        kTileModes[d->fRandom->nextULessThan(SK_ARRAY_COUNT(kTileModes))],
    };
<<<<<<< HEAD
    GrTextureParams params(tileModes, d->fRandom->nextBool() ? GrTextureParams::kBilerp_FilterMode : GrTextureParams::kNone_FilterMode);
=======
    GrTextureParams params(tileModes, d->fRandom->nextBool() ? GrTextureParams::kBilerp_FilterMode :
                                                               GrTextureParams::kNone_FilterMode);
>>>>>>> miniblink49

    static const GrCoordSet kCoordSets[] = {
        kLocal_GrCoordSet,
        kDevice_GrCoordSet
    };
    GrCoordSet coordSet = kCoordSets[d->fRandom->nextULessThan(SK_ARRAY_COUNT(kCoordSets))];

    const SkMatrix& matrix = GrTest::TestMatrix(d->fRandom);
<<<<<<< HEAD
    return GrSimpleTextureEffect::Make(d->fTextures[texIdx], matrix, coordSet);
=======
    return GrSimpleTextureEffect::Create(d->fProcDataManager, d->fTextures[texIdx], matrix,
                                         coordSet);
>>>>>>> miniblink49
}
