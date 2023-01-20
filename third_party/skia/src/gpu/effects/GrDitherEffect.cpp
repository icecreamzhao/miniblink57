/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrDitherEffect.h"
#include "GrFragmentProcessor.h"
#include "GrInvariantOutput.h"
#include "SkRect.h"
<<<<<<< HEAD
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
=======
#include "gl/GrGLProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"
>>>>>>> miniblink49

//////////////////////////////////////////////////////////////////////////////

class DitherEffect : public GrFragmentProcessor {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make()
    {
        return sk_sp<GrFragmentProcessor>(new DitherEffect);
=======
    static GrFragmentProcessor* Create() {
        GR_CREATE_STATIC_PROCESSOR(gDitherEffect, DitherEffect, ())
        return SkRef(gDitherEffect);
>>>>>>> miniblink49
    }

    virtual ~DitherEffect() {};

    const char* name() const override { return "Dither"; }

<<<<<<< HEAD
private:
    DitherEffect()
    {
=======
    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

private:
    DitherEffect() {
>>>>>>> miniblink49
        this->initClassID<DitherEffect>();
        this->setWillReadFragmentPosition();
    }

<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

=======
>>>>>>> miniblink49
    // All dither effects are equal
    bool onIsEqual(const GrFragmentProcessor&) const override { return true; }

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override;

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    typedef GrFragmentProcessor INHERITED;
};

<<<<<<< HEAD
void DitherEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
=======
void DitherEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const {
>>>>>>> miniblink49
    inout->setToUnknown(GrInvariantOutput::kWill_ReadInput);
}

//////////////////////////////////////////////////////////////////////////////

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(DitherEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> DitherEffect::TestCreate(GrProcessorTestData*)
{
    return DitherEffect::Make();
=======
GrFragmentProcessor* DitherEffect::TestCreate(GrProcessorTestData*) {
    return DitherEffect::Create();
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GLDitherEffect : public GrGLSLFragmentProcessor {
public:
    void emitCode(EmitArgs& args) override;

private:
    typedef GrGLSLFragmentProcessor INHERITED;
};

void GLDitherEffect::emitCode(EmitArgs& args)
{
    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
=======
class GLDitherEffect : public GrGLFragmentProcessor {
public:
    GLDitherEffect(const GrProcessor&);

    virtual void emitCode(GrGLFPBuilder* builder,
                          const GrFragmentProcessor& fp,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;

private:
    typedef GrGLFragmentProcessor INHERITED;
};

GLDitherEffect::GLDitherEffect(const GrProcessor&) {
}

void GLDitherEffect::emitCode(GrGLFPBuilder* builder,
                              const GrFragmentProcessor& fp,
                              const char* outputColor,
                              const char* inputColor,
                              const TransformedCoordsArray&,
                              const TextureSamplerArray& samplers) {
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
>>>>>>> miniblink49
    // Generate a random number based on the fragment position. For this
    // random number generator, we use the "GLSL rand" function
    // that seems to be floating around on the internet. It works under
    // the assumption that sin(<big number>) oscillates with high frequency
    // and sampling it will generate "randomness". Since we're using this
    // for rendering and not cryptography it should be OK.

    // For each channel c, add the random offset to the pixel to either bump
    // it up or let it remain constant during quantization.
<<<<<<< HEAD
    fragBuilder->codeAppendf("\t\tfloat r = "
                             "fract(sin(dot(%s.xy ,vec2(12.9898,78.233))) * 43758.5453);\n",
        fragBuilder->fragmentPosition());
    fragBuilder->codeAppendf("\t\t%s = (1.0/255.0) * vec4(r, r, r, r) + %s;\n",
        args.fOutputColor, GrGLSLExpr4(args.fInputColor).c_str());
=======
    fsBuilder->codeAppendf("\t\tfloat r = "
                           "fract(sin(dot(%s.xy ,vec2(12.9898,78.233))) * 43758.5453);\n",
                           fsBuilder->fragmentPosition());
    fsBuilder->codeAppendf("\t\t%s = (1.0/255.0) * vec4(r, r, r, r) + %s;\n",
                           outputColor, GrGLSLExpr4(inputColor).c_str());
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void DitherEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GLDitherEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* DitherEffect::onCreateGLSLInstance() const
{
    return new GLDitherEffect;
}

sk_sp<GrFragmentProcessor> GrDitherEffect::Make() { return DitherEffect::Make(); }
=======
void DitherEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                     GrProcessorKeyBuilder* b) const {
    GLDitherEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* DitherEffect::createGLInstance() const  {
    return SkNEW_ARGS(GLDitherEffect, (*this));
}

GrFragmentProcessor* GrDitherEffect::Create() { return DitherEffect::Create(); }
>>>>>>> miniblink49
