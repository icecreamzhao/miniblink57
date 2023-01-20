/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrBicubicEffect.h"
#include "GrInvariantOutput.h"
<<<<<<< HEAD
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
=======
#include "gl/builders/GrGLProgramBuilder.h"
>>>>>>> miniblink49

#define DS(x) SkDoubleToScalar(x)

const SkScalar GrBicubicEffect::gMitchellCoefficients[16] = {
<<<<<<< HEAD
    DS(1.0 / 18.0),
    DS(-9.0 / 18.0),
    DS(15.0 / 18.0),
    DS(-7.0 / 18.0),
    DS(16.0 / 18.0),
    DS(0.0 / 18.0),
    DS(-36.0 / 18.0),
    DS(21.0 / 18.0),
    DS(1.0 / 18.0),
    DS(9.0 / 18.0),
    DS(27.0 / 18.0),
    DS(-21.0 / 18.0),
    DS(0.0 / 18.0),
    DS(0.0 / 18.0),
    DS(-6.0 / 18.0),
    DS(7.0 / 18.0),
};

class GrGLBicubicEffect : public GrGLSLFragmentProcessor {
public:
    void emitCode(EmitArgs&) override;

    static inline void GenKey(const GrProcessor& effect, const GrGLSLCaps&,
        GrProcessorKeyBuilder* b)
    {
=======
    DS( 1.0 / 18.0), DS(-9.0 / 18.0), DS( 15.0 / 18.0), DS( -7.0 / 18.0),
    DS(16.0 / 18.0), DS( 0.0 / 18.0), DS(-36.0 / 18.0), DS( 21.0 / 18.0),
    DS( 1.0 / 18.0), DS( 9.0 / 18.0), DS( 27.0 / 18.0), DS(-21.0 / 18.0),
    DS( 0.0 / 18.0), DS( 0.0 / 18.0), DS( -6.0 / 18.0), DS(  7.0 / 18.0),
};


class GrGLBicubicEffect : public GrGLFragmentProcessor {
public:
    GrGLBicubicEffect(const GrProcessor&);

    virtual void emitCode(GrGLFPBuilder*,
                          const GrFragmentProcessor&,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;

    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;

    static inline void GenKey(const GrProcessor& effect, const GrGLSLCaps&,
                              GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
        const GrTextureDomain& domain = effect.cast<GrBicubicEffect>().domain();
        b->add32(GrTextureDomain::GLDomain::DomainKey(domain));
    }

<<<<<<< HEAD
protected:
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

private:
    typedef GrGLSLProgramDataManager::UniformHandle UniformHandle;

    UniformHandle fCoefficientsUni;
    UniformHandle fImageIncrementUni;
    GrTextureDomain::GLDomain fDomain;

    typedef GrGLSLFragmentProcessor INHERITED;
};

void GrGLBicubicEffect::emitCode(EmitArgs& args)
{
    const GrTextureDomain& domain = args.fFp.cast<GrBicubicEffect>().domain();

    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    fCoefficientsUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kMat44f_GrSLType, kDefault_GrSLPrecision,
        "Coefficients");
    fImageIncrementUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec2f_GrSLType, kDefault_GrSLPrecision,
        "ImageIncrement");

    const char* imgInc = uniformHandler->getUniformCStr(fImageIncrementUni);
    const char* coeff = uniformHandler->getUniformCStr(fCoefficientsUni);

    SkString cubicBlendName;

    static const GrGLSLShaderVar gCubicBlendArgs[] = {
        GrGLSLShaderVar("coefficients", kMat44f_GrSLType),
        GrGLSLShaderVar("t", kFloat_GrSLType),
        GrGLSLShaderVar("c0", kVec4f_GrSLType),
        GrGLSLShaderVar("c1", kVec4f_GrSLType),
        GrGLSLShaderVar("c2", kVec4f_GrSLType),
        GrGLSLShaderVar("c3", kVec4f_GrSLType),
    };
    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    SkString coords2D = fragBuilder->ensureFSCoords2D(args.fCoords, 0);
    fragBuilder->emitFunction(kVec4f_GrSLType,
        "cubicBlend",
        SK_ARRAY_COUNT(gCubicBlendArgs),
        gCubicBlendArgs,
        "\tvec4 ts = vec4(1.0, t, t * t, t * t * t);\n"
        "\tvec4 c = coefficients * ts;\n"
        "\treturn c.x * c0 + c.y * c1 + c.z * c2 + c.w * c3;\n",
        &cubicBlendName);
    fragBuilder->codeAppendf("\tvec2 coord = %s - %s * vec2(0.5);\n", coords2D.c_str(), imgInc);
=======
private:
    typedef GrGLProgramDataManager::UniformHandle UniformHandle;

    UniformHandle               fCoefficientsUni;
    UniformHandle               fImageIncrementUni;
    GrTextureDomain::GLDomain   fDomain;

    typedef GrGLFragmentProcessor INHERITED;
};

GrGLBicubicEffect::GrGLBicubicEffect(const GrProcessor&) {
}

void GrGLBicubicEffect::emitCode(GrGLFPBuilder* builder,
                                 const GrFragmentProcessor& effect,
                                 const char* outputColor,
                                 const char* inputColor,
                                 const TransformedCoordsArray& coords,
                                 const TextureSamplerArray& samplers) {
    const GrTextureDomain& domain = effect.cast<GrBicubicEffect>().domain();

    fCoefficientsUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                           kMat44f_GrSLType, kDefault_GrSLPrecision,
                                           "Coefficients");
    fImageIncrementUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                             kVec2f_GrSLType, kDefault_GrSLPrecision,
                                             "ImageIncrement");

    const char* imgInc = builder->getUniformCStr(fImageIncrementUni);
    const char* coeff = builder->getUniformCStr(fCoefficientsUni);

    SkString cubicBlendName;

    static const GrGLShaderVar gCubicBlendArgs[] = {
        GrGLShaderVar("coefficients",  kMat44f_GrSLType),
        GrGLShaderVar("t",             kFloat_GrSLType),
        GrGLShaderVar("c0",            kVec4f_GrSLType),
        GrGLShaderVar("c1",            kVec4f_GrSLType),
        GrGLShaderVar("c2",            kVec4f_GrSLType),
        GrGLShaderVar("c3",            kVec4f_GrSLType),
    };
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    SkString coords2D = fsBuilder->ensureFSCoords2D(coords, 0);
    fsBuilder->emitFunction(kVec4f_GrSLType,
                            "cubicBlend",
                            SK_ARRAY_COUNT(gCubicBlendArgs),
                            gCubicBlendArgs,
                            "\tvec4 ts = vec4(1.0, t, t * t, t * t * t);\n"
                            "\tvec4 c = coefficients * ts;\n"
                            "\treturn c.x * c0 + c.y * c1 + c.z * c2 + c.w * c3;\n",
                            &cubicBlendName);
    fsBuilder->codeAppendf("\tvec2 coord = %s - %s * vec2(0.5);\n", coords2D.c_str(), imgInc);
>>>>>>> miniblink49
    // We unnormalize the coord in order to determine our fractional offset (f) within the texel
    // We then snap coord to a texel center and renormalize. The snap prevents cases where the
    // starting coords are near a texel boundary and accumulations of imgInc would cause us to skip/
    // double hit a texel.
<<<<<<< HEAD
    fragBuilder->codeAppendf("\tcoord /= %s;\n", imgInc);
    fragBuilder->codeAppend("\tvec2 f = fract(coord);\n");
    fragBuilder->codeAppendf("\tcoord = (coord - f + vec2(0.5)) * %s;\n", imgInc);
    fragBuilder->codeAppend("\tvec4 rowColors[4];\n");
=======
    fsBuilder->codeAppendf("\tcoord /= %s;\n", imgInc);
    fsBuilder->codeAppend("\tvec2 f = fract(coord);\n");
    fsBuilder->codeAppendf("\tcoord = (coord - f + vec2(0.5)) * %s;\n", imgInc);
    fsBuilder->codeAppend("\tvec4 rowColors[4];\n");
>>>>>>> miniblink49
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            SkString coord;
            coord.printf("coord + %s * vec2(%d, %d)", imgInc, x - 1, y - 1);
            SkString sampleVar;
            sampleVar.printf("rowColors[%d]", x);
<<<<<<< HEAD
            fDomain.sampleTexture(fragBuilder,
                args.fUniformHandler,
                args.fGLSLCaps,
                domain,
                sampleVar.c_str(),
                coord,
                args.fTexSamplers[0]);
        }
        fragBuilder->codeAppendf(
            "\tvec4 s%d = %s(%s, f.x, rowColors[0], rowColors[1], rowColors[2], rowColors[3]);\n",
            y, cubicBlendName.c_str(), coeff);
    }
    SkString bicubicColor;
    bicubicColor.printf("%s(%s, f.y, s0, s1, s2, s3)", cubicBlendName.c_str(), coeff);
    fragBuilder->codeAppendf("\t%s = %s;\n",
        args.fOutputColor, (GrGLSLExpr4(bicubicColor.c_str()) * GrGLSLExpr4(args.fInputColor)).c_str());
}

void GrGLBicubicEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& processor)
{
=======
            fDomain.sampleTexture(fsBuilder, domain, sampleVar.c_str(), coord, samplers[0]);
        }
        fsBuilder->codeAppendf("\tvec4 s%d = %s(%s, f.x, rowColors[0], rowColors[1], rowColors[2], rowColors[3]);\n", y, cubicBlendName.c_str(), coeff);
    }
    SkString bicubicColor;
    bicubicColor.printf("%s(%s, f.y, s0, s1, s2, s3)", cubicBlendName.c_str(), coeff);
    fsBuilder->codeAppendf("\t%s = %s;\n", outputColor, (GrGLSLExpr4(bicubicColor.c_str()) * GrGLSLExpr4(inputColor)).c_str());
}

void GrGLBicubicEffect::setData(const GrGLProgramDataManager& pdman,
                                const GrProcessor& processor) {
>>>>>>> miniblink49
    const GrBicubicEffect& bicubicEffect = processor.cast<GrBicubicEffect>();
    const GrTexture& texture = *processor.texture(0);
    float imageIncrement[2];
    imageIncrement[0] = 1.0f / texture.width();
    imageIncrement[1] = 1.0f / texture.height();
    pdman.set2fv(fImageIncrementUni, 1, imageIncrement);
    pdman.setMatrix4f(fCoefficientsUni, bicubicEffect.coefficients());
    fDomain.setData(pdman, bicubicEffect.domain(), texture.origin());
}

static inline void convert_row_major_scalar_coeffs_to_column_major_floats(float dst[16],
<<<<<<< HEAD
    const SkScalar src[16])
{
=======
                                                                          const SkScalar src[16]) {
>>>>>>> miniblink49
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            dst[x * 4 + y] = SkScalarToFloat(src[y * 4 + x]);
        }
    }
}

<<<<<<< HEAD
GrBicubicEffect::GrBicubicEffect(GrTexture* texture,
    const SkScalar coefficients[16],
    const SkMatrix& matrix,
    const SkShader::TileMode tileModes[2])
    : INHERITED(texture, matrix, GrTextureParams(tileModes, GrTextureParams::kNone_FilterMode))
    , fDomain(GrTextureDomain::IgnoredDomain())
{
=======
GrBicubicEffect::GrBicubicEffect(GrProcessorDataManager* procDataManager,
                                 GrTexture* texture,
                                 const SkScalar coefficients[16],
                                 const SkMatrix &matrix,
                                 const SkShader::TileMode tileModes[2])
  : INHERITED(procDataManager, texture, matrix,
              GrTextureParams(tileModes, GrTextureParams::kNone_FilterMode))
  , fDomain(GrTextureDomain::IgnoredDomain()) {
>>>>>>> miniblink49
    this->initClassID<GrBicubicEffect>();
    convert_row_major_scalar_coeffs_to_column_major_floats(fCoefficients, coefficients);
}

<<<<<<< HEAD
GrBicubicEffect::GrBicubicEffect(GrTexture* texture,
    const SkScalar coefficients[16],
    const SkMatrix& matrix,
    const SkRect& domain)
    : INHERITED(texture, matrix,
        GrTextureParams(SkShader::kClamp_TileMode, GrTextureParams::kNone_FilterMode))
    , fDomain(domain, GrTextureDomain::kClamp_Mode)
{
=======
GrBicubicEffect::GrBicubicEffect(GrProcessorDataManager* procDataManager,
                                 GrTexture* texture,
                                 const SkScalar coefficients[16],
                                 const SkMatrix &matrix,
                                 const SkRect& domain)
  : INHERITED(procDataManager, texture, matrix,
              GrTextureParams(SkShader::kClamp_TileMode, GrTextureParams::kNone_FilterMode))
  , fDomain(domain, GrTextureDomain::kClamp_Mode) {
>>>>>>> miniblink49
    this->initClassID<GrBicubicEffect>();
    convert_row_major_scalar_coeffs_to_column_major_floats(fCoefficients, coefficients);
}

<<<<<<< HEAD
GrBicubicEffect::~GrBicubicEffect()
{
}

void GrBicubicEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLBicubicEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* GrBicubicEffect::onCreateGLSLInstance() const
{
    return new GrGLBicubicEffect;
}

bool GrBicubicEffect::onIsEqual(const GrFragmentProcessor& sBase) const
{
    const GrBicubicEffect& s = sBase.cast<GrBicubicEffect>();
    return !memcmp(fCoefficients, s.coefficients(), 16) && fDomain == s.fDomain;
}

void GrBicubicEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
=======
GrBicubicEffect::~GrBicubicEffect() {
}

void GrBicubicEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                        GrProcessorKeyBuilder* b) const {
    GrGLBicubicEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* GrBicubicEffect::createGLInstance() const  {
    return SkNEW_ARGS(GrGLBicubicEffect, (*this));
}

bool GrBicubicEffect::onIsEqual(const GrFragmentProcessor& sBase) const {
    const GrBicubicEffect& s = sBase.cast<GrBicubicEffect>();
    return !memcmp(fCoefficients, s.coefficients(), 16) &&
           fDomain == s.fDomain;
}

void GrBicubicEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const {
>>>>>>> miniblink49
    // FIXME: Perhaps we can do better.
    inout->mulByUnknownSingleComponent();
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrBicubicEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrBicubicEffect::TestCreate(GrProcessorTestData* d)
{
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx : GrProcessorUnitTest::kAlphaTextureIdx;
=======
GrFragmentProcessor* GrBicubicEffect::TestCreate(GrProcessorTestData* d) {
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx :
                                          GrProcessorUnitTest::kAlphaTextureIdx;
>>>>>>> miniblink49
    SkScalar coefficients[16];
    for (int i = 0; i < 16; i++) {
        coefficients[i] = d->fRandom->nextSScalar1();
    }
<<<<<<< HEAD
    return GrBicubicEffect::Make(d->fTextures[texIdx], coefficients);
=======
    return GrBicubicEffect::Create(d->fProcDataManager, d->fTextures[texIdx], coefficients);
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

bool GrBicubicEffect::ShouldUseBicubic(const SkMatrix& matrix,
<<<<<<< HEAD
    GrTextureParams::FilterMode* filterMode)
{
=======
                                       GrTextureParams::FilterMode* filterMode) {
>>>>>>> miniblink49
    if (matrix.isIdentity()) {
        *filterMode = GrTextureParams::kNone_FilterMode;
        return false;
    }

    SkScalar scales[2];
    if (!matrix.getMinMaxScales(scales) || scales[0] < SK_Scalar1) {
        // Bicubic doesn't handle arbitrary minimization well, as src texels can be skipped
        // entirely,
        *filterMode = GrTextureParams::kMipMap_FilterMode;
        return false;
    }
    // At this point if scales[1] == SK_Scalar1 then the matrix doesn't do any scaling.
    if (scales[1] == SK_Scalar1) {
<<<<<<< HEAD
        if (matrix.rectStaysRect() && SkScalarIsInt(matrix.getTranslateX()) && SkScalarIsInt(matrix.getTranslateY())) {
=======
        if (matrix.rectStaysRect() && SkScalarIsInt(matrix.getTranslateX()) &&
            SkScalarIsInt(matrix.getTranslateY())) {
>>>>>>> miniblink49
            *filterMode = GrTextureParams::kNone_FilterMode;
        } else {
            // Use bilerp to handle rotation or fractional translation.
            *filterMode = GrTextureParams::kBilerp_FilterMode;
        }
        return false;
    }
    // When we use the bicubic filtering effect each sample is read from the texture using
    // nearest neighbor sampling.
    *filterMode = GrTextureParams::kNone_FilterMode;
    return true;
}
