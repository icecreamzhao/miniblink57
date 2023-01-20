/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrDistanceFieldGeoProc.h"
<<<<<<< HEAD
=======
#include "GrFontAtlasSizes.h"
>>>>>>> miniblink49
#include "GrInvariantOutput.h"
#include "GrTexture.h"

#include "SkDistanceFieldGen.h"

<<<<<<< HEAD
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLGeometryProcessor.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
#include "glsl/GrGLSLUtil.h"
#include "glsl/GrGLSLVarying.h"
#include "glsl/GrGLSLVertexShaderBuilder.h"

// Assuming a radius of a little less than the diagonal of the fragment
#define SK_DistanceFieldAAFactor "0.65"

class GrGLDistanceFieldA8TextGeoProc : public GrGLSLGeometryProcessor {
public:
    GrGLDistanceFieldA8TextGeoProc()
        : fViewMatrix(SkMatrix::InvalidMatrix())
#ifdef SK_GAMMA_APPLY_TO_A8
        , fDistanceAdjust(-1.0f)
#endif
    {
    }

    void onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) override
    {
        const GrDistanceFieldA8TextGeoProc& dfTexEffect = args.fGP.cast<GrDistanceFieldA8TextGeoProc>();
        GrGLSLPPFragmentBuilder* fragBuilder = args.fFragBuilder;
        SkAssertResult(fragBuilder->enableFeature(
            GrGLSLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));

        GrGLSLVertexBuilder* vertBuilder = args.fVertBuilder;
        GrGLSLVaryingHandler* varyingHandler = args.fVaryingHandler;
        GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;

        // emit attributes
        varyingHandler->emitAttributes(dfTexEffect);

#ifdef SK_GAMMA_APPLY_TO_A8
        // adjust based on gamma
        const char* distanceAdjustUniName = nullptr;
        // width, height, 1/(3*width)
        fDistanceAdjustUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
=======
#include "gl/GrGLProcessor.h"
#include "gl/GrGLTexture.h"
#include "gl/GrGLGeometryProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"

// Assuming a radius of a little less than the diagonal of the fragment
#define SK_DistanceFieldAAFactor     "0.65"

class GrGLDistanceFieldA8TextGeoProc : public GrGLGeometryProcessor {
public:
    GrGLDistanceFieldA8TextGeoProc(const GrGeometryProcessor&,
                                   const GrBatchTracker&)
        : fViewMatrix(SkMatrix::InvalidMatrix())
        , fColor(GrColor_ILLEGAL)
#ifdef SK_GAMMA_APPLY_TO_A8
        , fDistanceAdjust(-1.0f)
#endif
        {}

    void onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) override{
        const GrDistanceFieldA8TextGeoProc& dfTexEffect =
                args.fGP.cast<GrDistanceFieldA8TextGeoProc>();
        GrGLGPBuilder* pb = args.fPB;
        GrGLFragmentBuilder* fsBuilder = args.fPB->getFragmentShaderBuilder();
        SkAssertResult(fsBuilder->enableFeature(
                GrGLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));

        GrGLVertexBuilder* vsBuilder = args.fPB->getVertexShaderBuilder();

        // emit attributes
        vsBuilder->emitAttributes(dfTexEffect);

#ifdef SK_GAMMA_APPLY_TO_A8
        // adjust based on gamma
        const char* distanceAdjustUniName = NULL;
        // width, height, 1/(3*width)
        fDistanceAdjustUni = args.fPB->addUniform(GrGLProgramBuilder::kFragment_Visibility,
>>>>>>> miniblink49
            kFloat_GrSLType, kDefault_GrSLPrecision,
            "DistanceAdjust", &distanceAdjustUniName);
#endif

        // Setup pass through color
        if (!dfTexEffect.colorIgnored()) {
<<<<<<< HEAD
            varyingHandler->addPassThroughAttribute(dfTexEffect.inColor(), args.fOutputColor);
        }

        // Setup position
        this->setupPosition(vertBuilder,
            uniformHandler,
            gpArgs,
            dfTexEffect.inPosition()->fName,
            dfTexEffect.viewMatrix(),
            &fViewMatrixUniform);

        // emit transforms
        this->emitTransforms(vertBuilder,
            varyingHandler,
            uniformHandler,
            gpArgs->fPositionVar,
            dfTexEffect.inPosition()->fName,
            args.fTransformsIn,
            args.fTransformsOut);

        // add varyings
        GrGLSLVertToFrag recipScale(kFloat_GrSLType);
        GrGLSLVertToFrag uv(kVec2f_GrSLType);
        bool isUniformScale = (dfTexEffect.getFlags() & kUniformScale_DistanceFieldEffectMask) == kUniformScale_DistanceFieldEffectMask;
        bool isSimilarity = SkToBool(dfTexEffect.getFlags() & kSimilarity_DistanceFieldEffectFlag);
        bool isGammaCorrect = SkToBool(dfTexEffect.getFlags() & kGammaCorrect_DistanceFieldEffectFlag);
        varyingHandler->addVarying("TextureCoords", &uv, kHigh_GrSLPrecision);
        vertBuilder->codeAppendf("%s = %s;", uv.vsOut(), dfTexEffect.inTextureCoords()->fName);

        // compute numbers to be hardcoded to convert texture coordinates from float to int
        SkASSERT(dfTexEffect.numTextures() == 1);
        GrTexture* atlas = dfTexEffect.textureAccess(0).getTexture();
        SkASSERT(atlas && SkIsPow2(atlas->width()) && SkIsPow2(atlas->height()));

        GrGLSLVertToFrag st(kVec2f_GrSLType);
        varyingHandler->addVarying("IntTextureCoords", &st, kHigh_GrSLPrecision);
        vertBuilder->codeAppendf("%s = vec2(%d, %d) * %s;", st.vsOut(),
            atlas->width(), atlas->height(),
            dfTexEffect.inTextureCoords()->fName);

        // Use highp to work around aliasing issues
        fragBuilder->appendPrecisionModifier(kHigh_GrSLPrecision);
        fragBuilder->codeAppendf("vec2 uv = %s;\n", uv.fsIn());

        fragBuilder->codeAppend("\tfloat texColor = ");
        fragBuilder->appendTextureLookup(args.fTexSamplers[0],
            "uv",
            kVec2f_GrSLType);
        fragBuilder->codeAppend(".r;\n");
        fragBuilder->codeAppend("\tfloat distance = " SK_DistanceFieldMultiplier "*(texColor - " SK_DistanceFieldThreshold ");");
#ifdef SK_GAMMA_APPLY_TO_A8
        // adjust width based on gamma
        fragBuilder->codeAppendf("distance -= %s;", distanceAdjustUniName);
#endif

        fragBuilder->codeAppend("float afwidth;");
        if (isUniformScale) {
            // For uniform scale, we adjust for the effect of the transformation on the distance
            // by using the length of the gradient of the t coordinate in the y direction.
            // We use st coordinates to ensure we're mapping 1:1 from texel space to pixel space.
            // We use the y gradient because there is a bug in the Mali 400 in the x direction.

            // this gives us a smooth step across approximately one fragment
            fragBuilder->codeAppendf("afwidth = abs(" SK_DistanceFieldAAFactor "*dFdy(%s.y));",
                st.fsIn());
        } else if (isSimilarity) {
            // For similarity transform, we adjust the effect of the transformation on the distance
            // by using the length of the gradient of the texture coordinates. We use st coordinates
            // to ensure we're mapping 1:1 from texel space to pixel space.
            // We use the y gradient because there is a bug in the Mali 400 in the x direction.

            // this gives us a smooth step across approximately one fragment
            fragBuilder->codeAppendf("float st_grad_len = length(dFdy(%s));", st.fsIn());
            fragBuilder->codeAppend("afwidth = abs(" SK_DistanceFieldAAFactor "*st_grad_len);");
=======
            if (dfTexEffect.hasVertexColor()) {
                pb->addPassThroughAttribute(dfTexEffect.inColor(), args.fOutputColor);
            } else {
                this->setupUniformColor(pb, args.fOutputColor, &fColorUniform);
            }
        }

        // Setup position
        this->setupPosition(pb, gpArgs, dfTexEffect.inPosition()->fName, dfTexEffect.viewMatrix(),
                            &fViewMatrixUniform);

        // emit transforms
        this->emitTransforms(args.fPB, gpArgs->fPositionVar, dfTexEffect.inPosition()->fName,
                             args.fTransformsIn, args.fTransformsOut);

        // add varyings
        GrGLVertToFrag recipScale(kFloat_GrSLType);
        GrGLVertToFrag st(kVec2f_GrSLType);
        bool isSimilarity = SkToBool(dfTexEffect.getFlags() & kSimilarity_DistanceFieldEffectFlag);
        args.fPB->addVarying("IntTextureCoords", &st, kHigh_GrSLPrecision);
        vsBuilder->codeAppendf("%s = %s;", st.vsOut(), dfTexEffect.inTextureCoords()->fName);

        GrGLVertToFrag uv(kVec2f_GrSLType);
        args.fPB->addVarying("TextureCoords", &uv, kHigh_GrSLPrecision);
        // this is only used with text, so our texture bounds always match the glyph atlas
        vsBuilder->codeAppendf("%s = vec2(" GR_FONT_ATLAS_A8_RECIP_WIDTH ", "
                               GR_FONT_ATLAS_RECIP_HEIGHT ")*%s;", uv.vsOut(),
                               dfTexEffect.inTextureCoords()->fName);
        
        // Use highp to work around aliasing issues
        fsBuilder->codeAppend(GrGLShaderVar::PrecisionString(kHigh_GrSLPrecision,
                                                             pb->ctxInfo().standard()));
        fsBuilder->codeAppendf("vec2 uv = %s;\n", uv.fsIn());

        fsBuilder->codeAppend("\tfloat texColor = ");
        fsBuilder->appendTextureLookup(args.fSamplers[0],
                                       "uv",
                                       kVec2f_GrSLType);
        fsBuilder->codeAppend(".r;\n");
        fsBuilder->codeAppend("\tfloat distance = "
                       SK_DistanceFieldMultiplier "*(texColor - " SK_DistanceFieldThreshold ");");
#ifdef SK_GAMMA_APPLY_TO_A8
        // adjust width based on gamma
        fsBuilder->codeAppendf("distance -= %s;", distanceAdjustUniName);
#endif

        fsBuilder->codeAppend("float afwidth;");
        if (isSimilarity) {
            // For uniform scale, we adjust for the effect of the transformation on the distance
            // by using the length of the gradient of the texture coordinates. We use st coordinates
            // to ensure we're mapping 1:1 from texel space to pixel space.

            // this gives us a smooth step across approximately one fragment
            // we use y to work around a Mali400 bug in the x direction
            fsBuilder->codeAppendf("afwidth = abs(" SK_DistanceFieldAAFactor "*dFdy(%s.y));",
                                       st.fsIn());
>>>>>>> miniblink49
        } else {
            // For general transforms, to determine the amount of correction we multiply a unit
            // vector pointing along the SDF gradient direction by the Jacobian of the st coords
            // (which is the inverse transform for this fragment) and take the length of the result.
<<<<<<< HEAD
            fragBuilder->codeAppend("vec2 dist_grad = vec2(dFdx(distance), dFdy(distance));");
            // the length of the gradient may be 0, so we need to check for this
            // this also compensates for the Adreno, which likes to drop tiles on division by 0
            fragBuilder->codeAppend("float dg_len2 = dot(dist_grad, dist_grad);");
            fragBuilder->codeAppend("if (dg_len2 < 0.0001) {");
            fragBuilder->codeAppend("dist_grad = vec2(0.7071, 0.7071);");
            fragBuilder->codeAppend("} else {");
            fragBuilder->codeAppend("dist_grad = dist_grad*inversesqrt(dg_len2);");
            fragBuilder->codeAppend("}");

            fragBuilder->codeAppendf("vec2 Jdx = dFdx(%s);", st.fsIn());
            fragBuilder->codeAppendf("vec2 Jdy = dFdy(%s);", st.fsIn());
            fragBuilder->codeAppend("vec2 grad = vec2(dist_grad.x*Jdx.x + dist_grad.y*Jdy.x,");
            fragBuilder->codeAppend("                 dist_grad.x*Jdx.y + dist_grad.y*Jdy.y);");

            // this gives us a smooth step across approximately one fragment
            fragBuilder->codeAppend("afwidth = " SK_DistanceFieldAAFactor "*length(grad);");
        }

        // The smoothstep falloff compensates for the non-linear sRGB response curve. If we are
        // doing gamma-correct rendering (to an sRGB or F16 buffer), then we actually want distance
        // mapped linearly to coverage, so use a linear step:
        if (isGammaCorrect) {
            fragBuilder->codeAppend(
                "float val = clamp(distance + afwidth / (2.0 * afwidth), 0.0, 1.0);");
        } else {
            fragBuilder->codeAppend("float val = smoothstep(-afwidth, afwidth, distance);");
        }

        fragBuilder->codeAppendf("%s = vec4(val);", args.fOutputCoverage);
    }

    void setData(const GrGLSLProgramDataManager& pdman, const GrPrimitiveProcessor& proc) override
    {
=======
            fsBuilder->codeAppend("vec2 dist_grad = vec2(dFdx(distance), dFdy(distance));");
            // the length of the gradient may be 0, so we need to check for this
            // this also compensates for the Adreno, which likes to drop tiles on division by 0
            fsBuilder->codeAppend("float dg_len2 = dot(dist_grad, dist_grad);");
            fsBuilder->codeAppend("if (dg_len2 < 0.0001) {");
            fsBuilder->codeAppend("dist_grad = vec2(0.7071, 0.7071);");
            fsBuilder->codeAppend("} else {");
            fsBuilder->codeAppend("dist_grad = dist_grad*inversesqrt(dg_len2);");
            fsBuilder->codeAppend("}");

            fsBuilder->codeAppendf("vec2 Jdx = dFdx(%s);", st.fsIn());
            fsBuilder->codeAppendf("vec2 Jdy = dFdy(%s);", st.fsIn());
            fsBuilder->codeAppend("vec2 grad = vec2(dist_grad.x*Jdx.x + dist_grad.y*Jdy.x,");
            fsBuilder->codeAppend("                 dist_grad.x*Jdx.y + dist_grad.y*Jdy.y);");

            // this gives us a smooth step across approximately one fragment
            fsBuilder->codeAppend("afwidth = " SK_DistanceFieldAAFactor "*length(grad);");
        }
        fsBuilder->codeAppend("float val = smoothstep(-afwidth, afwidth, distance);");

        fsBuilder->codeAppendf("%s = vec4(val);", args.fOutputCoverage);
    }

    virtual void setData(const GrGLProgramDataManager& pdman,
                         const GrPrimitiveProcessor& proc,
                         const GrBatchTracker& bt) override {
>>>>>>> miniblink49
#ifdef SK_GAMMA_APPLY_TO_A8
        const GrDistanceFieldA8TextGeoProc& dfTexEffect = proc.cast<GrDistanceFieldA8TextGeoProc>();
        float distanceAdjust = dfTexEffect.getDistanceAdjust();
        if (distanceAdjust != fDistanceAdjust) {
            pdman.set1f(fDistanceAdjustUni, distanceAdjust);
            fDistanceAdjust = distanceAdjust;
        }
#endif
        const GrDistanceFieldA8TextGeoProc& dfa8gp = proc.cast<GrDistanceFieldA8TextGeoProc>();

        if (!dfa8gp.viewMatrix().isIdentity() && !fViewMatrix.cheapEqualTo(dfa8gp.viewMatrix())) {
            fViewMatrix = dfa8gp.viewMatrix();
<<<<<<< HEAD
            float viewMatrix[3 * 3];
            GrGLSLGetMatrix<3>(viewMatrix, fViewMatrix);
            pdman.setMatrix3f(fViewMatrixUniform, viewMatrix);
        }
    }

    static inline void GenKey(const GrGeometryProcessor& gp,
        const GrGLSLCaps&,
        GrProcessorKeyBuilder* b)
    {
        const GrDistanceFieldA8TextGeoProc& dfTexEffect = gp.cast<GrDistanceFieldA8TextGeoProc>();
        uint32_t key = dfTexEffect.getFlags();
        key |= dfTexEffect.colorIgnored() << 16;
        key |= ComputePosKey(dfTexEffect.viewMatrix()) << 25;
        b->add32(key);

        // Currently we hardcode numbers to convert atlas coordinates to normalized floating point
        SkASSERT(gp.numTextures() == 1);
        GrTexture* atlas = gp.textureAccess(0).getTexture();
        SkASSERT(atlas);
        b->add32(atlas->width());
        b->add32(atlas->height());
    }

private:
    SkMatrix fViewMatrix;
    UniformHandle fViewMatrixUniform;
#ifdef SK_GAMMA_APPLY_TO_A8
    float fDistanceAdjust;
    UniformHandle fDistanceAdjustUni;
#endif

    typedef GrGLSLGeometryProcessor INHERITED;
=======
            GrGLfloat viewMatrix[3 * 3];
            GrGLGetMatrix<3>(viewMatrix, fViewMatrix);
            pdman.setMatrix3f(fViewMatrixUniform, viewMatrix);
        }

        if (dfa8gp.color() != fColor && !dfa8gp.hasVertexColor()) {
            GrGLfloat c[4];
            GrColorToRGBAFloat(dfa8gp.color(), c);
            pdman.set4fv(fColorUniform, 1, c);
            fColor = dfa8gp.color();
        }
    }

    static inline void GenKey(const GrGeometryProcessor& gp,
                              const GrBatchTracker& bt,
                              const GrGLSLCaps&,
                              GrProcessorKeyBuilder* b) {
        const GrDistanceFieldA8TextGeoProc& dfTexEffect = gp.cast<GrDistanceFieldA8TextGeoProc>();
        uint32_t key = dfTexEffect.getFlags();
        key |= dfTexEffect.hasVertexColor() << 16;
        key |= dfTexEffect.colorIgnored() << 17;
        key |= ComputePosKey(dfTexEffect.viewMatrix()) << 25;
        b->add32(key);
    }

private:
    SkMatrix      fViewMatrix;
    GrColor       fColor;
    UniformHandle fColorUniform;
    UniformHandle fViewMatrixUniform;
#ifdef SK_GAMMA_APPLY_TO_A8
    float         fDistanceAdjust;
    UniformHandle fDistanceAdjustUni;
#endif

    typedef GrGLGeometryProcessor INHERITED;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

GrDistanceFieldA8TextGeoProc::GrDistanceFieldA8TextGeoProc(GrColor color,
<<<<<<< HEAD
    const SkMatrix& viewMatrix,
    GrTexture* texture,
    const GrTextureParams& params,
#ifdef SK_GAMMA_APPLY_TO_A8
    float distanceAdjust,
#endif
    uint32_t flags,
    bool usesLocalCoords)
=======
                                                           const SkMatrix& viewMatrix,
                                                           GrTexture* texture,
                                                           const GrTextureParams& params,
#ifdef SK_GAMMA_APPLY_TO_A8
                                                           float distanceAdjust,
#endif
                                                           uint32_t flags,
                                                           bool usesLocalCoords)
>>>>>>> miniblink49
    : fColor(color)
    , fViewMatrix(viewMatrix)
    , fTextureAccess(texture, params)
#ifdef SK_GAMMA_APPLY_TO_A8
    , fDistanceAdjust(distanceAdjust)
#endif
    , fFlags(flags & kNonLCD_DistanceFieldEffectMask)
<<<<<<< HEAD
    , fInColor(nullptr)
    , fUsesLocalCoords(usesLocalCoords)
{
    SkASSERT(!(flags & ~kNonLCD_DistanceFieldEffectMask));
    this->initClassID<GrDistanceFieldA8TextGeoProc>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
        kHigh_GrSLPrecision));
    fInColor = &this->addVertexAttrib(Attribute("inColor", kVec4ub_GrVertexAttribType));
    fInTextureCoords = &this->addVertexAttrib(Attribute("inTextureCoords",
        kVec2us_GrVertexAttribType,
        kHigh_GrSLPrecision));
    this->addTextureAccess(&fTextureAccess);
}

void GrDistanceFieldA8TextGeoProc::getGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLDistanceFieldA8TextGeoProc::GenKey(*this, caps, b);
}

GrGLSLPrimitiveProcessor* GrDistanceFieldA8TextGeoProc::createGLSLInstance(const GrGLSLCaps&) const
{
    return new GrGLDistanceFieldA8TextGeoProc();
=======
    , fInColor(NULL)
    , fUsesLocalCoords(usesLocalCoords) {
    SkASSERT(!(flags & ~kNonLCD_DistanceFieldEffectMask));
    this->initClassID<GrDistanceFieldA8TextGeoProc>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
                                                   kHigh_GrSLPrecision));
    if (flags & kColorAttr_DistanceFieldEffectFlag) {
        fInColor = &this->addVertexAttrib(Attribute("inColor", kVec4ub_GrVertexAttribType));
    }
    fInTextureCoords = &this->addVertexAttrib(Attribute("inTextureCoords",
                                                          kVec2s_GrVertexAttribType));
    this->addTextureAccess(&fTextureAccess);
}

void GrDistanceFieldA8TextGeoProc::getGLProcessorKey(const GrBatchTracker& bt,
                                                     const GrGLSLCaps& caps,
                                                     GrProcessorKeyBuilder* b) const {
    GrGLDistanceFieldA8TextGeoProc::GenKey(*this, bt, caps, b);
}

GrGLPrimitiveProcessor*
GrDistanceFieldA8TextGeoProc::createGLInstance(const GrBatchTracker& bt,
                                               const GrGLSLCaps&) const {
    return SkNEW_ARGS(GrGLDistanceFieldA8TextGeoProc, (*this, bt));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

GR_DEFINE_GEOMETRY_PROCESSOR_TEST(GrDistanceFieldA8TextGeoProc);

<<<<<<< HEAD
sk_sp<GrGeometryProcessor> GrDistanceFieldA8TextGeoProc::TestCreate(GrProcessorTestData* d)
{
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx : GrProcessorUnitTest::kAlphaTextureIdx;
=======
GrGeometryProcessor* GrDistanceFieldA8TextGeoProc::TestCreate(GrProcessorTestData* d) {
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

    uint32_t flags = 0;
    flags |= d->fRandom->nextBool() ? kSimilarity_DistanceFieldEffectFlag : 0;
    if (flags & kSimilarity_DistanceFieldEffectFlag) {
        flags |= d->fRandom->nextBool() ? kScaleOnly_DistanceFieldEffectFlag : 0;
    }

    return GrDistanceFieldA8TextGeoProc::Make(GrRandomColor(d->fRandom),
        GrTest::TestMatrix(d->fRandom),
        d->fTextures[texIdx], params,
#ifdef SK_GAMMA_APPLY_TO_A8
        d->fRandom->nextF(),
#endif
        flags,
        d->fRandom->nextBool());
=======
    GrTextureParams params(tileModes, d->fRandom->nextBool() ? GrTextureParams::kBilerp_FilterMode :
                                                           GrTextureParams::kNone_FilterMode);

    return GrDistanceFieldA8TextGeoProc::Create(GrRandomColor(d->fRandom),
                                                GrTest::TestMatrix(d->fRandom),
                                                d->fTextures[texIdx], params,
#ifdef SK_GAMMA_APPLY_TO_A8
                                                d->fRandom->nextF(),
#endif
                                                d->fRandom->nextBool() ?
                                                    kSimilarity_DistanceFieldEffectFlag : 0,
                                                    d->fRandom->nextBool());
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GrGLDistanceFieldPathGeoProc : public GrGLSLGeometryProcessor {
public:
    GrGLDistanceFieldPathGeoProc()
        : fViewMatrix(SkMatrix::InvalidMatrix())
        , fTextureSize(SkISize::Make(-1, -1))
    {
    }

    void onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) override
    {
        const GrDistanceFieldPathGeoProc& dfTexEffect = args.fGP.cast<GrDistanceFieldPathGeoProc>();

        GrGLSLPPFragmentBuilder* fragBuilder = args.fFragBuilder;
        SkAssertResult(fragBuilder->enableFeature(
            GrGLSLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));

        GrGLSLVertexBuilder* vertBuilder = args.fVertBuilder;
        GrGLSLVaryingHandler* varyingHandler = args.fVaryingHandler;
        GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;

        // emit attributes
        varyingHandler->emitAttributes(dfTexEffect);

        GrGLSLVertToFrag v(kVec2f_GrSLType);
        varyingHandler->addVarying("TextureCoords", &v, kHigh_GrSLPrecision);

        // setup pass through color
        if (!dfTexEffect.colorIgnored()) {
            varyingHandler->addPassThroughAttribute(dfTexEffect.inColor(), args.fOutputColor);
        }
        vertBuilder->codeAppendf("%s = %s;", v.vsOut(), dfTexEffect.inTextureCoords()->fName);

        // Setup position
        this->setupPosition(vertBuilder,
            uniformHandler,
            gpArgs,
            dfTexEffect.inPosition()->fName,
            dfTexEffect.viewMatrix(),
            &fViewMatrixUniform);

        // emit transforms
        this->emitTransforms(vertBuilder,
            varyingHandler,
            uniformHandler,
            gpArgs->fPositionVar,
            dfTexEffect.inPosition()->fName,
            args.fTransformsIn,
            args.fTransformsOut);

        const char* textureSizeUniName = nullptr;
        fTextureSizeUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
            kVec2f_GrSLType, kDefault_GrSLPrecision,
            "TextureSize", &textureSizeUniName);

        // Use highp to work around aliasing issues
        fragBuilder->appendPrecisionModifier(kHigh_GrSLPrecision);
        fragBuilder->codeAppendf("vec2 uv = %s;", v.fsIn());

        fragBuilder->codeAppend("float texColor = ");
        fragBuilder->appendTextureLookup(args.fTexSamplers[0],
            "uv",
            kVec2f_GrSLType);
        fragBuilder->codeAppend(".r;");
        fragBuilder->codeAppend("float distance = " SK_DistanceFieldMultiplier "*(texColor - " SK_DistanceFieldThreshold ");");

        fragBuilder->appendPrecisionModifier(kHigh_GrSLPrecision);
        fragBuilder->codeAppendf("vec2 st = uv*%s;", textureSizeUniName);
        fragBuilder->codeAppend("float afwidth;");
        bool isUniformScale = (dfTexEffect.getFlags() & kUniformScale_DistanceFieldEffectMask) == kUniformScale_DistanceFieldEffectMask;
        bool isSimilarity = SkToBool(dfTexEffect.getFlags() & kSimilarity_DistanceFieldEffectFlag);
        bool isGammaCorrect = SkToBool(dfTexEffect.getFlags() & kGammaCorrect_DistanceFieldEffectFlag);
        if (isUniformScale) {
            // For uniform scale, we adjust for the effect of the transformation on the distance
            // by using the length of the gradient of the t coordinate in the y direction.
            // We use st coordinates to ensure we're mapping 1:1 from texel space to pixel space.
            // We use the y gradient because there is a bug in the Mali 400 in the x direction.

            // this gives us a smooth step across approximately one fragment
            fragBuilder->codeAppend("afwidth = abs(" SK_DistanceFieldAAFactor "*dFdy(st.y));");

        } else if (isSimilarity) {
            // For similarity transform, we adjust the effect of the transformation on the distance
            // by using the length of the gradient of the texture coordinates. We use st coordinates
            // to ensure we're mapping 1:1 from texel space to pixel space.
            // We use the y gradient because there is a bug in the Mali 400 in the x direction.

            // this gives us a smooth step across approximately one fragment
            fragBuilder->codeAppend("float st_grad_len = length(dFdy(st));");
            fragBuilder->codeAppend("afwidth = abs(" SK_DistanceFieldAAFactor "*st_grad_len);");
=======
class GrGLDistanceFieldPathGeoProc : public GrGLGeometryProcessor {
public:
    GrGLDistanceFieldPathGeoProc(const GrGeometryProcessor&,
                                          const GrBatchTracker&)
        : fViewMatrix(SkMatrix::InvalidMatrix())
        , fColor(GrColor_ILLEGAL)
        , fTextureSize(SkISize::Make(-1, -1)) {}

    void onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) override{
        const GrDistanceFieldPathGeoProc& dfTexEffect = args.fGP.cast<GrDistanceFieldPathGeoProc>();

        GrGLGPBuilder* pb = args.fPB;
        GrGLFragmentBuilder* fsBuilder = args.fPB->getFragmentShaderBuilder();
        SkAssertResult(fsBuilder->enableFeature(
                                     GrGLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));

        GrGLVertexBuilder* vsBuilder = args.fPB->getVertexShaderBuilder();

        // emit attributes
        vsBuilder->emitAttributes(dfTexEffect);

        GrGLVertToFrag v(kVec2f_GrSLType);
        args.fPB->addVarying("TextureCoords", &v, kHigh_GrSLPrecision);

        // setup pass through color
        if (!dfTexEffect.colorIgnored()) {
            if (dfTexEffect.hasVertexColor()) {
                pb->addPassThroughAttribute(dfTexEffect.inColor(), args.fOutputColor);
            } else {
                this->setupUniformColor(pb, args.fOutputColor, &fColorUniform);
            }
        }
        vsBuilder->codeAppendf("%s = %s;", v.vsOut(), dfTexEffect.inTextureCoords()->fName);

        // Setup position
        this->setupPosition(pb, gpArgs, dfTexEffect.inPosition()->fName, dfTexEffect.viewMatrix(),
                            &fViewMatrixUniform);

        // emit transforms
        this->emitTransforms(args.fPB, gpArgs->fPositionVar, dfTexEffect.inPosition()->fName,
                             args.fTransformsIn, args.fTransformsOut);

        const char* textureSizeUniName = NULL;
        fTextureSizeUni = args.fPB->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                              kVec2f_GrSLType, kDefault_GrSLPrecision,
                                              "TextureSize", &textureSizeUniName);

        // Use highp to work around aliasing issues
        fsBuilder->codeAppend(GrGLShaderVar::PrecisionString(kHigh_GrSLPrecision,
                                                             pb->ctxInfo().standard()));
        fsBuilder->codeAppendf("vec2 uv = %s;", v.fsIn());

        fsBuilder->codeAppend("float texColor = ");
        fsBuilder->appendTextureLookup(args.fSamplers[0],
                                       "uv",
                                       kVec2f_GrSLType);
        fsBuilder->codeAppend(".r;");
        fsBuilder->codeAppend("float distance = "
            SK_DistanceFieldMultiplier "*(texColor - " SK_DistanceFieldThreshold ");");

        fsBuilder->codeAppend(GrGLShaderVar::PrecisionString(kHigh_GrSLPrecision,
                                                             pb->ctxInfo().standard()));
        fsBuilder->codeAppendf("vec2 st = uv*%s;", textureSizeUniName);
        fsBuilder->codeAppend("float afwidth;");
        if (dfTexEffect.getFlags() & kSimilarity_DistanceFieldEffectFlag) {
            // For uniform scale, we adjust for the effect of the transformation on the distance
            // by using the length of the gradient of the texture coordinates. We use st coordinates
            // to ensure we're mapping 1:1 from texel space to pixel space.

            // this gives us a smooth step across approximately one fragment
            fsBuilder->codeAppend("afwidth = abs(" SK_DistanceFieldAAFactor "*dFdy(st.y));");
>>>>>>> miniblink49
        } else {
            // For general transforms, to determine the amount of correction we multiply a unit
            // vector pointing along the SDF gradient direction by the Jacobian of the st coords
            // (which is the inverse transform for this fragment) and take the length of the result.
<<<<<<< HEAD
            fragBuilder->codeAppend("vec2 dist_grad = vec2(dFdx(distance), dFdy(distance));");
            // the length of the gradient may be 0, so we need to check for this
            // this also compensates for the Adreno, which likes to drop tiles on division by 0
            fragBuilder->codeAppend("float dg_len2 = dot(dist_grad, dist_grad);");
            fragBuilder->codeAppend("if (dg_len2 < 0.0001) {");
            fragBuilder->codeAppend("dist_grad = vec2(0.7071, 0.7071);");
            fragBuilder->codeAppend("} else {");
            fragBuilder->codeAppend("dist_grad = dist_grad*inversesqrt(dg_len2);");
            fragBuilder->codeAppend("}");

            fragBuilder->codeAppend("vec2 Jdx = dFdx(st);");
            fragBuilder->codeAppend("vec2 Jdy = dFdy(st);");
            fragBuilder->codeAppend("vec2 grad = vec2(dist_grad.x*Jdx.x + dist_grad.y*Jdy.x,");
            fragBuilder->codeAppend("                 dist_grad.x*Jdx.y + dist_grad.y*Jdy.y);");

            // this gives us a smooth step across approximately one fragment
            fragBuilder->codeAppend("afwidth = " SK_DistanceFieldAAFactor "*length(grad);");
        }
        // The smoothstep falloff compensates for the non-linear sRGB response curve. If we are
        // doing gamma-correct rendering (to an sRGB or F16 buffer), then we actually want distance
        // mapped linearly to coverage, so use a linear step:
        if (isGammaCorrect) {
            fragBuilder->codeAppend(
                "float val = clamp(distance + afwidth / (2.0 * afwidth), 0.0, 1.0);");
        } else {
            fragBuilder->codeAppend("float val = smoothstep(-afwidth, afwidth, distance);");
        }

        fragBuilder->codeAppendf("%s = vec4(val);", args.fOutputCoverage);
    }

    void setData(const GrGLSLProgramDataManager& pdman, const GrPrimitiveProcessor& proc) override
    {
        SkASSERT(fTextureSizeUni.isValid());

        GrTexture* texture = proc.texture(0);
        if (texture->width() != fTextureSize.width() || texture->height() != fTextureSize.height()) {
            fTextureSize = SkISize::Make(texture->width(), texture->height());
            pdman.set2f(fTextureSizeUni,
                SkIntToScalar(fTextureSize.width()),
                SkIntToScalar(fTextureSize.height()));
=======
            fsBuilder->codeAppend("vec2 dist_grad = vec2(dFdx(distance), dFdy(distance));");
            // the length of the gradient may be 0, so we need to check for this
            // this also compensates for the Adreno, which likes to drop tiles on division by 0
            fsBuilder->codeAppend("float dg_len2 = dot(dist_grad, dist_grad);");
            fsBuilder->codeAppend("if (dg_len2 < 0.0001) {");
            fsBuilder->codeAppend("dist_grad = vec2(0.7071, 0.7071);");
            fsBuilder->codeAppend("} else {");
            fsBuilder->codeAppend("dist_grad = dist_grad*inversesqrt(dg_len2);");
            fsBuilder->codeAppend("}");

            fsBuilder->codeAppend("vec2 Jdx = dFdx(st);");
            fsBuilder->codeAppend("vec2 Jdy = dFdy(st);");
            fsBuilder->codeAppend("vec2 grad = vec2(dist_grad.x*Jdx.x + dist_grad.y*Jdy.x,");
            fsBuilder->codeAppend("                 dist_grad.x*Jdx.y + dist_grad.y*Jdy.y);");

            // this gives us a smooth step across approximately one fragment
            fsBuilder->codeAppend("afwidth = " SK_DistanceFieldAAFactor "*length(grad);");
        }
        fsBuilder->codeAppend("float val = smoothstep(-afwidth, afwidth, distance);");

        fsBuilder->codeAppendf("%s = vec4(val);", args.fOutputCoverage);
    }

    virtual void setData(const GrGLProgramDataManager& pdman,
                         const GrPrimitiveProcessor& proc,
                         const GrBatchTracker& bt) override {
        SkASSERT(fTextureSizeUni.isValid());

        GrTexture* texture = proc.texture(0);
        if (texture->width() != fTextureSize.width() || 
            texture->height() != fTextureSize.height()) {
            fTextureSize = SkISize::Make(texture->width(), texture->height());
            pdman.set2f(fTextureSizeUni,
                        SkIntToScalar(fTextureSize.width()),
                        SkIntToScalar(fTextureSize.height()));
>>>>>>> miniblink49
        }

        const GrDistanceFieldPathGeoProc& dfpgp = proc.cast<GrDistanceFieldPathGeoProc>();

        if (!dfpgp.viewMatrix().isIdentity() && !fViewMatrix.cheapEqualTo(dfpgp.viewMatrix())) {
            fViewMatrix = dfpgp.viewMatrix();
<<<<<<< HEAD
            float viewMatrix[3 * 3];
            GrGLSLGetMatrix<3>(viewMatrix, fViewMatrix);
            pdman.setMatrix3f(fViewMatrixUniform, viewMatrix);
        }
    }

    static inline void GenKey(const GrGeometryProcessor& gp,
        const GrGLSLCaps&,
        GrProcessorKeyBuilder* b)
    {
=======
            GrGLfloat viewMatrix[3 * 3];
            GrGLGetMatrix<3>(viewMatrix, fViewMatrix);
            pdman.setMatrix3f(fViewMatrixUniform, viewMatrix);
        }

        if (dfpgp.color() != fColor) {
            GrGLfloat c[4];
            GrColorToRGBAFloat(dfpgp.color(), c);
            pdman.set4fv(fColorUniform, 1, c);
            fColor = dfpgp.color();
        }
    }

    static inline void GenKey(const GrGeometryProcessor& gp,
                              const GrBatchTracker& bt,
                              const GrGLSLCaps&,
                              GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
        const GrDistanceFieldPathGeoProc& dfTexEffect = gp.cast<GrDistanceFieldPathGeoProc>();

        uint32_t key = dfTexEffect.getFlags();
        key |= dfTexEffect.colorIgnored() << 16;
<<<<<<< HEAD
=======
        key |= dfTexEffect.hasVertexColor() << 17;
>>>>>>> miniblink49
        key |= ComputePosKey(dfTexEffect.viewMatrix()) << 25;
        b->add32(key);
    }

private:
<<<<<<< HEAD
    UniformHandle fTextureSizeUni;
    UniformHandle fViewMatrixUniform;
    SkMatrix fViewMatrix;
    SkISize fTextureSize;

    typedef GrGLSLGeometryProcessor INHERITED;
=======
    UniformHandle fColorUniform;
    UniformHandle fTextureSizeUni;
    UniformHandle fViewMatrixUniform;
    SkMatrix      fViewMatrix;
    GrColor       fColor;
    SkISize       fTextureSize;

    typedef GrGLGeometryProcessor INHERITED;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

GrDistanceFieldPathGeoProc::GrDistanceFieldPathGeoProc(
<<<<<<< HEAD
    GrColor color,
    const SkMatrix& viewMatrix,
    GrTexture* texture,
    const GrTextureParams& params,
    uint32_t flags,
    bool usesLocalCoords)
=======
        GrColor color,
        const SkMatrix& viewMatrix,
        GrTexture* texture,
        const GrTextureParams& params,
        uint32_t flags,
        bool usesLocalCoords)
>>>>>>> miniblink49
    : fColor(color)
    , fViewMatrix(viewMatrix)
    , fTextureAccess(texture, params)
    , fFlags(flags & kNonLCD_DistanceFieldEffectMask)
<<<<<<< HEAD
    , fInColor(nullptr)
    , fUsesLocalCoords(usesLocalCoords)
{
    SkASSERT(!(flags & ~kNonLCD_DistanceFieldEffectMask));
    this->initClassID<GrDistanceFieldPathGeoProc>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
        kHigh_GrSLPrecision));
    fInColor = &this->addVertexAttrib(Attribute("inColor", kVec4ub_GrVertexAttribType));
    fInTextureCoords = &this->addVertexAttrib(Attribute("inTextureCoords",
        kVec2f_GrVertexAttribType));
    this->addTextureAccess(&fTextureAccess);
}

void GrDistanceFieldPathGeoProc::getGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLDistanceFieldPathGeoProc::GenKey(*this, caps, b);
}

GrGLSLPrimitiveProcessor* GrDistanceFieldPathGeoProc::createGLSLInstance(const GrGLSLCaps&) const
{
    return new GrGLDistanceFieldPathGeoProc();
=======
    , fInColor(NULL)
    , fUsesLocalCoords(usesLocalCoords) {
    SkASSERT(!(flags & ~kNonLCD_DistanceFieldEffectMask));
    this->initClassID<GrDistanceFieldPathGeoProc>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
                                                   kHigh_GrSLPrecision));
    if (flags & kColorAttr_DistanceFieldEffectFlag) {
        fInColor = &this->addVertexAttrib(Attribute("inColor", kVec4ub_GrVertexAttribType));
    }
    fInTextureCoords = &this->addVertexAttrib(Attribute("inTextureCoords",
                                                        kVec2f_GrVertexAttribType));
    this->addTextureAccess(&fTextureAccess);
}

void GrDistanceFieldPathGeoProc::getGLProcessorKey(const GrBatchTracker& bt,
                                                   const GrGLSLCaps& caps,
                                                   GrProcessorKeyBuilder* b) const {
    GrGLDistanceFieldPathGeoProc::GenKey(*this, bt, caps, b);
}

GrGLPrimitiveProcessor*
GrDistanceFieldPathGeoProc::createGLInstance(const GrBatchTracker& bt, const GrGLSLCaps&) const {
    return SkNEW_ARGS(GrGLDistanceFieldPathGeoProc, (*this, bt));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

GR_DEFINE_GEOMETRY_PROCESSOR_TEST(GrDistanceFieldPathGeoProc);

<<<<<<< HEAD
sk_sp<GrGeometryProcessor> GrDistanceFieldPathGeoProc::TestCreate(GrProcessorTestData* d)
{
=======
GrGeometryProcessor* GrDistanceFieldPathGeoProc::TestCreate(GrProcessorTestData* d) {
>>>>>>> miniblink49
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx
                                        : GrProcessorUnitTest::kAlphaTextureIdx;
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

    uint32_t flags = 0;
    flags |= d->fRandom->nextBool() ? kSimilarity_DistanceFieldEffectFlag : 0;
    if (flags & kSimilarity_DistanceFieldEffectFlag) {
        flags |= d->fRandom->nextBool() ? kScaleOnly_DistanceFieldEffectFlag : 0;
    }

    return GrDistanceFieldPathGeoProc::Make(GrRandomColor(d->fRandom),
        GrTest::TestMatrix(d->fRandom),
        d->fTextures[texIdx],
        params,
        flags,
        d->fRandom->nextBool());
=======
    GrTextureParams params(tileModes, d->fRandom->nextBool() ? GrTextureParams::kBilerp_FilterMode
                                                             : GrTextureParams::kNone_FilterMode);

    return GrDistanceFieldPathGeoProc::Create(GrRandomColor(d->fRandom),
                                              GrTest::TestMatrix(d->fRandom),
                                              d->fTextures[texIdx],
                                              params,
                                              d->fRandom->nextBool() ?
                                                      kSimilarity_DistanceFieldEffectFlag : 0,
                                                      d->fRandom->nextBool());
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GrGLDistanceFieldLCDTextGeoProc : public GrGLSLGeometryProcessor {
public:
    GrGLDistanceFieldLCDTextGeoProc()
        : fViewMatrix(SkMatrix::InvalidMatrix())
    {
        fDistanceAdjust = GrDistanceFieldLCDTextGeoProc::DistanceAdjust::Make(1.0f, 1.0f, 1.0f);
    }

    void onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) override
    {
        const GrDistanceFieldLCDTextGeoProc& dfTexEffect = args.fGP.cast<GrDistanceFieldLCDTextGeoProc>();

        GrGLSLVertexBuilder* vertBuilder = args.fVertBuilder;
        GrGLSLVaryingHandler* varyingHandler = args.fVaryingHandler;
        GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;

        // emit attributes
        varyingHandler->emitAttributes(dfTexEffect);

        GrGLSLPPFragmentBuilder* fragBuilder = args.fFragBuilder;

        // setup pass through color
        if (!dfTexEffect.colorIgnored()) {
            varyingHandler->addPassThroughAttribute(dfTexEffect.inColor(), args.fOutputColor);
        }

        // Setup position
        this->setupPosition(vertBuilder,
            uniformHandler,
            gpArgs,
            dfTexEffect.inPosition()->fName,
            dfTexEffect.viewMatrix(),
            &fViewMatrixUniform);

        // emit transforms
        this->emitTransforms(vertBuilder,
            varyingHandler,
            uniformHandler,
            gpArgs->fPositionVar,
            dfTexEffect.inPosition()->fName,
            args.fTransformsIn,
            args.fTransformsOut);

        // set up varyings
        bool isUniformScale = (dfTexEffect.getFlags() & kUniformScale_DistanceFieldEffectMask) == kUniformScale_DistanceFieldEffectMask;
        bool isSimilarity = SkToBool(dfTexEffect.getFlags() & kSimilarity_DistanceFieldEffectFlag);
        bool isGammaCorrect = SkToBool(dfTexEffect.getFlags() & kGammaCorrect_DistanceFieldEffectFlag);
        GrGLSLVertToFrag recipScale(kFloat_GrSLType);
        GrGLSLVertToFrag uv(kVec2f_GrSLType);
        varyingHandler->addVarying("TextureCoords", &uv, kHigh_GrSLPrecision);
        vertBuilder->codeAppendf("%s = %s;", uv.vsOut(), dfTexEffect.inTextureCoords()->fName);

        // compute numbers to be hardcoded to convert texture coordinates from float to int
        SkASSERT(dfTexEffect.numTextures() == 1);
        GrTexture* atlas = dfTexEffect.textureAccess(0).getTexture();
        SkASSERT(atlas && SkIsPow2(atlas->width()) && SkIsPow2(atlas->height()));

        GrGLSLVertToFrag st(kVec2f_GrSLType);
        varyingHandler->addVarying("IntTextureCoords", &st, kHigh_GrSLPrecision);
        vertBuilder->codeAppendf("%s = vec2(%d, %d) * %s;", st.vsOut(),
            atlas->width(), atlas->height(),
            dfTexEffect.inTextureCoords()->fName);

        // add frag shader code

        SkAssertResult(fragBuilder->enableFeature(
            GrGLSLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));

        // create LCD offset adjusted by inverse of transform
        // Use highp to work around aliasing issues
        fragBuilder->appendPrecisionModifier(kHigh_GrSLPrecision);
        fragBuilder->codeAppendf("vec2 uv = %s;\n", uv.fsIn());
        fragBuilder->appendPrecisionModifier(kHigh_GrSLPrecision);

        SkScalar lcdDelta = 1.0f / (3.0f * atlas->width());
        if (dfTexEffect.getFlags() & kBGR_DistanceFieldEffectFlag) {
            fragBuilder->codeAppendf("float delta = -%.*f;\n", SK_FLT_DECIMAL_DIG, lcdDelta);
        } else {
            fragBuilder->codeAppendf("float delta = %.*f;\n", SK_FLT_DECIMAL_DIG, lcdDelta);
        }
        if (isUniformScale) {
            fragBuilder->codeAppendf("float st_grad_len = abs(dFdy(%s.y));", st.fsIn());
            fragBuilder->codeAppend("vec2 offset = vec2(st_grad_len*delta, 0.0);");
        } else if (isSimilarity) {
            // For a similarity matrix with rotation, the gradient will not be aligned
            // with the texel coordinate axes, so we need to calculate it.
            // We use dFdy because of a Mali 400 bug, and rotate -90 degrees to
            // get the gradient in the x direction.
            fragBuilder->codeAppendf("vec2 st_grad = dFdy(%s);", st.fsIn());
            fragBuilder->codeAppend("float st_grad_len = length(st_grad);");
            fragBuilder->codeAppend("vec2 offset = delta*vec2(st_grad.y, -st_grad.x);");
        } else {
            fragBuilder->codeAppendf("vec2 st = %s;\n", st.fsIn());

            fragBuilder->codeAppend("vec2 Jdx = dFdx(st);");
            fragBuilder->codeAppend("vec2 Jdy = dFdy(st);");
            fragBuilder->codeAppend("vec2 offset = delta*Jdx;");
        }

        // green is distance to uv center
        fragBuilder->codeAppend("\tvec4 texColor = ");
        fragBuilder->appendTextureLookup(args.fTexSamplers[0], "uv", kVec2f_GrSLType);
        fragBuilder->codeAppend(";\n");
        fragBuilder->codeAppend("\tvec3 distance;\n");
        fragBuilder->codeAppend("\tdistance.y = texColor.r;\n");
        // red is distance to left offset
        fragBuilder->codeAppend("\tvec2 uv_adjusted = uv - offset;\n");
        fragBuilder->codeAppend("\ttexColor = ");
        fragBuilder->appendTextureLookup(args.fTexSamplers[0], "uv_adjusted", kVec2f_GrSLType);
        fragBuilder->codeAppend(";\n");
        fragBuilder->codeAppend("\tdistance.x = texColor.r;\n");
        // blue is distance to right offset
        fragBuilder->codeAppend("\tuv_adjusted = uv + offset;\n");
        fragBuilder->codeAppend("\ttexColor = ");
        fragBuilder->appendTextureLookup(args.fTexSamplers[0], "uv_adjusted", kVec2f_GrSLType);
        fragBuilder->codeAppend(";\n");
        fragBuilder->codeAppend("\tdistance.z = texColor.r;\n");

        fragBuilder->codeAppend("\tdistance = "
                                "vec3(" SK_DistanceFieldMultiplier ")*(distance - vec3(" SK_DistanceFieldThreshold "));");

        // adjust width based on gamma
        const char* distanceAdjustUniName = nullptr;
        fDistanceAdjustUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
            kVec3f_GrSLType, kDefault_GrSLPrecision,
            "DistanceAdjust", &distanceAdjustUniName);
        fragBuilder->codeAppendf("distance -= %s;", distanceAdjustUniName);
=======
class GrGLDistanceFieldLCDTextGeoProc : public GrGLGeometryProcessor {
public:
    GrGLDistanceFieldLCDTextGeoProc(const GrGeometryProcessor&, const GrBatchTracker&)
        : fViewMatrix(SkMatrix::InvalidMatrix()), fColor(GrColor_ILLEGAL) {
        fDistanceAdjust = GrDistanceFieldLCDTextGeoProc::DistanceAdjust::Make(1.0f, 1.0f, 1.0f);
    }

    void onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) override{
        const GrDistanceFieldLCDTextGeoProc& dfTexEffect =
                args.fGP.cast<GrDistanceFieldLCDTextGeoProc>();
        GrGLGPBuilder* pb = args.fPB;

        GrGLVertexBuilder* vsBuilder = args.fPB->getVertexShaderBuilder();

        // emit attributes
        vsBuilder->emitAttributes(dfTexEffect);

        // setup pass through color
        if (!dfTexEffect.colorIgnored()) {
            this->setupUniformColor(pb, args.fOutputColor, &fColorUniform);
        }

        // Setup position
        this->setupPosition(pb, gpArgs, dfTexEffect.inPosition()->fName, dfTexEffect.viewMatrix(),
                            &fViewMatrixUniform);

        // emit transforms
        this->emitTransforms(args.fPB, gpArgs->fPositionVar, dfTexEffect.inPosition()->fName,
                             args.fTransformsIn, args.fTransformsOut);

        // set up varyings
        bool isUniformScale = SkToBool(dfTexEffect.getFlags() & kUniformScale_DistanceFieldEffectMask);
        GrGLVertToFrag recipScale(kFloat_GrSLType);
        GrGLVertToFrag st(kVec2f_GrSLType);
        args.fPB->addVarying("IntTextureCoords", &st, kHigh_GrSLPrecision);
        vsBuilder->codeAppendf("%s = %s;", st.vsOut(), dfTexEffect.inTextureCoords()->fName);

        GrGLVertToFrag uv(kVec2f_GrSLType);
        args.fPB->addVarying("TextureCoords", &uv, kHigh_GrSLPrecision);
        // this is only used with text, so our texture bounds always match the glyph atlas
        vsBuilder->codeAppendf("%s = vec2(" GR_FONT_ATLAS_A8_RECIP_WIDTH ", "
                               GR_FONT_ATLAS_RECIP_HEIGHT ")*%s;", uv.vsOut(),
                               dfTexEffect.inTextureCoords()->fName);

        // add frag shader code
        GrGLFragmentBuilder* fsBuilder = args.fPB->getFragmentShaderBuilder();

        SkAssertResult(fsBuilder->enableFeature(
                GrGLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));

        // create LCD offset adjusted by inverse of transform
        // Use highp to work around aliasing issues
        fsBuilder->codeAppend(GrGLShaderVar::PrecisionString(kHigh_GrSLPrecision,
                                                             pb->ctxInfo().standard()));
        fsBuilder->codeAppendf("vec2 uv = %s;\n", uv.fsIn());
        fsBuilder->codeAppend(GrGLShaderVar::PrecisionString(kHigh_GrSLPrecision,
                                                             pb->ctxInfo().standard()));
        if (dfTexEffect.getFlags() & kBGR_DistanceFieldEffectFlag) {
            fsBuilder->codeAppend("float delta = -" GR_FONT_ATLAS_LCD_DELTA ";\n");
        } else {
            fsBuilder->codeAppend("float delta = " GR_FONT_ATLAS_LCD_DELTA ";\n");
        }
        if (isUniformScale) {
            fsBuilder->codeAppendf("float dy = abs(dFdy(%s.y));", st.fsIn());
            fsBuilder->codeAppend("vec2 offset = vec2(dy*delta, 0.0);");
        } else {
            fsBuilder->codeAppendf("vec2 st = %s;\n", st.fsIn());

            fsBuilder->codeAppend("vec2 Jdx = dFdx(st);");
            fsBuilder->codeAppend("vec2 Jdy = dFdy(st);");
            fsBuilder->codeAppend("vec2 offset = delta*Jdx;");
        }

        // green is distance to uv center
        fsBuilder->codeAppend("\tvec4 texColor = ");
        fsBuilder->appendTextureLookup(args.fSamplers[0], "uv", kVec2f_GrSLType);
        fsBuilder->codeAppend(";\n");
        fsBuilder->codeAppend("\tvec3 distance;\n");
        fsBuilder->codeAppend("\tdistance.y = texColor.r;\n");
        // red is distance to left offset
        fsBuilder->codeAppend("\tvec2 uv_adjusted = uv - offset;\n");
        fsBuilder->codeAppend("\ttexColor = ");
        fsBuilder->appendTextureLookup(args.fSamplers[0], "uv_adjusted", kVec2f_GrSLType);
        fsBuilder->codeAppend(";\n");
        fsBuilder->codeAppend("\tdistance.x = texColor.r;\n");
        // blue is distance to right offset
        fsBuilder->codeAppend("\tuv_adjusted = uv + offset;\n");
        fsBuilder->codeAppend("\ttexColor = ");
        fsBuilder->appendTextureLookup(args.fSamplers[0], "uv_adjusted", kVec2f_GrSLType);
        fsBuilder->codeAppend(";\n");
        fsBuilder->codeAppend("\tdistance.z = texColor.r;\n");

        fsBuilder->codeAppend("\tdistance = "
           "vec3(" SK_DistanceFieldMultiplier ")*(distance - vec3(" SK_DistanceFieldThreshold"));");

        // adjust width based on gamma
        const char* distanceAdjustUniName = NULL;
        fDistanceAdjustUni = args.fPB->addUniform(GrGLProgramBuilder::kFragment_Visibility,
            kVec3f_GrSLType, kDefault_GrSLPrecision,
            "DistanceAdjust", &distanceAdjustUniName);
        fsBuilder->codeAppendf("distance -= %s;", distanceAdjustUniName);
>>>>>>> miniblink49

        // To be strictly correct, we should compute the anti-aliasing factor separately
        // for each color component. However, this is only important when using perspective
        // transformations, and even then using a single factor seems like a reasonable
        // trade-off between quality and speed.
<<<<<<< HEAD
        fragBuilder->codeAppend("float afwidth;");
        if (isSimilarity) {
            // For similarity transform (uniform scale-only is a subset of this), we adjust for the
            // effect of the transformation on the distance by using the length of the gradient of
            // the texture coordinates. We use st coordinates to ensure we're mapping 1:1 from texel
            // space to pixel space.

            // this gives us a smooth step across approximately one fragment
            fragBuilder->codeAppend("afwidth = " SK_DistanceFieldAAFactor "*st_grad_len;");
=======
        fsBuilder->codeAppend("float afwidth;");
        if (isUniformScale) {
            // For uniform scale, we adjust for the effect of the transformation on the distance
            // by using the length of the gradient of the texture coordinates. We use st coordinates
            // to ensure we're mapping 1:1 from texel space to pixel space.

            // this gives us a smooth step across approximately one fragment
            fsBuilder->codeAppend("afwidth = " SK_DistanceFieldAAFactor "*dy;");
>>>>>>> miniblink49
        } else {
            // For general transforms, to determine the amount of correction we multiply a unit
            // vector pointing along the SDF gradient direction by the Jacobian of the st coords
            // (which is the inverse transform for this fragment) and take the length of the result.
<<<<<<< HEAD
            fragBuilder->codeAppend("vec2 dist_grad = vec2(dFdx(distance.r), dFdy(distance.r));");
            // the length of the gradient may be 0, so we need to check for this
            // this also compensates for the Adreno, which likes to drop tiles on division by 0
            fragBuilder->codeAppend("float dg_len2 = dot(dist_grad, dist_grad);");
            fragBuilder->codeAppend("if (dg_len2 < 0.0001) {");
            fragBuilder->codeAppend("dist_grad = vec2(0.7071, 0.7071);");
            fragBuilder->codeAppend("} else {");
            fragBuilder->codeAppend("dist_grad = dist_grad*inversesqrt(dg_len2);");
            fragBuilder->codeAppend("}");
            fragBuilder->codeAppend("vec2 grad = vec2(dist_grad.x*Jdx.x + dist_grad.y*Jdy.x,");
            fragBuilder->codeAppend("                 dist_grad.x*Jdx.y + dist_grad.y*Jdy.y);");

            // this gives us a smooth step across approximately one fragment
            fragBuilder->codeAppend("afwidth = " SK_DistanceFieldAAFactor "*length(grad);");
        }

        // The smoothstep falloff compensates for the non-linear sRGB response curve. If we are
        // doing gamma-correct rendering (to an sRGB or F16 buffer), then we actually want distance
        // mapped linearly to coverage, so use a linear step:
        if (isGammaCorrect) {
            fragBuilder->codeAppend("vec4 val = "
                                    "vec4(clamp(distance + vec3(afwidth) / vec3(2.0 * afwidth), 0.0, 1.0), 1.0f);");
        } else {
            fragBuilder->codeAppend(
                "vec4 val = vec4(smoothstep(vec3(-afwidth), vec3(afwidth), distance), 1.0);");
        }

        // set alpha to be max of rgb coverage
        fragBuilder->codeAppend("val.a = max(max(val.r, val.g), val.b);");

        fragBuilder->codeAppendf("%s = val;", args.fOutputCoverage);
    }

    void setData(const GrGLSLProgramDataManager& pdman,
        const GrPrimitiveProcessor& processor) override
    {
=======
            fsBuilder->codeAppend("vec2 dist_grad = vec2(dFdx(distance.r), dFdy(distance.r));");
            // the length of the gradient may be 0, so we need to check for this
            // this also compensates for the Adreno, which likes to drop tiles on division by 0
            fsBuilder->codeAppend("float dg_len2 = dot(dist_grad, dist_grad);");
            fsBuilder->codeAppend("if (dg_len2 < 0.0001) {");
            fsBuilder->codeAppend("dist_grad = vec2(0.7071, 0.7071);");
            fsBuilder->codeAppend("} else {");
            fsBuilder->codeAppend("dist_grad = dist_grad*inversesqrt(dg_len2);");
            fsBuilder->codeAppend("}");
            fsBuilder->codeAppend("vec2 grad = vec2(dist_grad.x*Jdx.x + dist_grad.y*Jdy.x,");
            fsBuilder->codeAppend("                 dist_grad.x*Jdx.y + dist_grad.y*Jdy.y);");

            // this gives us a smooth step across approximately one fragment
            fsBuilder->codeAppend("afwidth = " SK_DistanceFieldAAFactor "*length(grad);");
        }

        fsBuilder->codeAppend(
                      "vec4 val = vec4(smoothstep(vec3(-afwidth), vec3(afwidth), distance), 1.0);");

        fsBuilder->codeAppendf("%s = vec4(val);", args.fOutputCoverage);
    }

    virtual void setData(const GrGLProgramDataManager& pdman,
                         const GrPrimitiveProcessor& processor,
                         const GrBatchTracker& bt) override {
>>>>>>> miniblink49
        SkASSERT(fDistanceAdjustUni.isValid());

        const GrDistanceFieldLCDTextGeoProc& dflcd = processor.cast<GrDistanceFieldLCDTextGeoProc>();
        GrDistanceFieldLCDTextGeoProc::DistanceAdjust wa = dflcd.getDistanceAdjust();
        if (wa != fDistanceAdjust) {
            pdman.set3f(fDistanceAdjustUni,
<<<<<<< HEAD
                wa.fR,
                wa.fG,
                wa.fB);
=======
                        wa.fR,
                        wa.fG,
                        wa.fB);
>>>>>>> miniblink49
            fDistanceAdjust = wa;
        }

        if (!dflcd.viewMatrix().isIdentity() && !fViewMatrix.cheapEqualTo(dflcd.viewMatrix())) {
            fViewMatrix = dflcd.viewMatrix();
<<<<<<< HEAD
            float viewMatrix[3 * 3];
            GrGLSLGetMatrix<3>(viewMatrix, fViewMatrix);
            pdman.setMatrix3f(fViewMatrixUniform, viewMatrix);
        }
    }

    static inline void GenKey(const GrGeometryProcessor& gp,
        const GrGLSLCaps&,
        GrProcessorKeyBuilder* b)
    {
=======
            GrGLfloat viewMatrix[3 * 3];
            GrGLGetMatrix<3>(viewMatrix, fViewMatrix);
            pdman.setMatrix3f(fViewMatrixUniform, viewMatrix);
        }

        if (dflcd.color() != fColor) {
            GrGLfloat c[4];
            GrColorToRGBAFloat(dflcd.color(), c);
            pdman.set4fv(fColorUniform, 1, c);
            fColor = dflcd.color();
        }
    }

    static inline void GenKey(const GrGeometryProcessor& gp,
                              const GrBatchTracker& bt,
                              const GrGLSLCaps&,
                              GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
        const GrDistanceFieldLCDTextGeoProc& dfTexEffect = gp.cast<GrDistanceFieldLCDTextGeoProc>();

        uint32_t key = dfTexEffect.getFlags();
        key |= dfTexEffect.colorIgnored() << 16;
        key |= ComputePosKey(dfTexEffect.viewMatrix()) << 25;
        b->add32(key);
<<<<<<< HEAD

        // Currently we hardcode numbers to convert atlas coordinates to normalized floating point
        SkASSERT(gp.numTextures() == 1);
        GrTexture* atlas = gp.textureAccess(0).getTexture();
        SkASSERT(atlas);
        b->add32(atlas->width());
        b->add32(atlas->height());
    }

private:
    SkMatrix fViewMatrix;
    UniformHandle fViewMatrixUniform;
    UniformHandle fColorUniform;
    GrDistanceFieldLCDTextGeoProc::DistanceAdjust fDistanceAdjust;
    UniformHandle fDistanceAdjustUni;

    typedef GrGLSLGeometryProcessor INHERITED;
=======
    }

private:
    SkMatrix                                     fViewMatrix;
    GrColor                                      fColor;
    UniformHandle                                fViewMatrixUniform;
    UniformHandle                                fColorUniform;
    GrDistanceFieldLCDTextGeoProc::DistanceAdjust fDistanceAdjust;
    UniformHandle                                fDistanceAdjustUni;

    typedef GrGLGeometryProcessor INHERITED;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

GrDistanceFieldLCDTextGeoProc::GrDistanceFieldLCDTextGeoProc(
<<<<<<< HEAD
    GrColor color, const SkMatrix& viewMatrix,
    GrTexture* texture, const GrTextureParams& params,
    DistanceAdjust distanceAdjust,
    uint32_t flags, bool usesLocalCoords)
=======
                                                  GrColor color, const SkMatrix& viewMatrix,
                                                  GrTexture* texture, const GrTextureParams& params,
                                                  DistanceAdjust distanceAdjust,
                                                  uint32_t flags, bool usesLocalCoords)
>>>>>>> miniblink49
    : fColor(color)
    , fViewMatrix(viewMatrix)
    , fTextureAccess(texture, params)
    , fDistanceAdjust(distanceAdjust)
    , fFlags(flags & kLCD_DistanceFieldEffectMask)
<<<<<<< HEAD
    , fUsesLocalCoords(usesLocalCoords)
{
    SkASSERT(!(flags & ~kLCD_DistanceFieldEffectMask) && (flags & kUseLCD_DistanceFieldEffectFlag));
    this->initClassID<GrDistanceFieldLCDTextGeoProc>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
        kHigh_GrSLPrecision));
    fInColor = &this->addVertexAttrib(Attribute("inColor", kVec4ub_GrVertexAttribType));
    fInTextureCoords = &this->addVertexAttrib(Attribute("inTextureCoords",
        kVec2us_GrVertexAttribType,
        kHigh_GrSLPrecision));
    this->addTextureAccess(&fTextureAccess);
}

void GrDistanceFieldLCDTextGeoProc::getGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLDistanceFieldLCDTextGeoProc::GenKey(*this, caps, b);
}

GrGLSLPrimitiveProcessor* GrDistanceFieldLCDTextGeoProc::createGLSLInstance(const GrGLSLCaps&) const
{
    return new GrGLDistanceFieldLCDTextGeoProc();
=======
    , fUsesLocalCoords(usesLocalCoords) {
    SkASSERT(!(flags & ~kLCD_DistanceFieldEffectMask) && (flags & kUseLCD_DistanceFieldEffectFlag));
    this->initClassID<GrDistanceFieldLCDTextGeoProc>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
                                                   kHigh_GrSLPrecision));
    fInTextureCoords = &this->addVertexAttrib(Attribute("inTextureCoords",
                                                        kVec2s_GrVertexAttribType));
    this->addTextureAccess(&fTextureAccess);
}

void GrDistanceFieldLCDTextGeoProc::getGLProcessorKey(const GrBatchTracker& bt,
                                                      const GrGLSLCaps& caps,
                                                      GrProcessorKeyBuilder* b) const {
    GrGLDistanceFieldLCDTextGeoProc::GenKey(*this, bt, caps, b);
}

GrGLPrimitiveProcessor*
GrDistanceFieldLCDTextGeoProc::createGLInstance(const GrBatchTracker& bt,
                                                const GrGLSLCaps&) const {
    return SkNEW_ARGS(GrGLDistanceFieldLCDTextGeoProc, (*this, bt));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

GR_DEFINE_GEOMETRY_PROCESSOR_TEST(GrDistanceFieldLCDTextGeoProc);

<<<<<<< HEAD
sk_sp<GrGeometryProcessor> GrDistanceFieldLCDTextGeoProc::TestCreate(GrProcessorTestData* d)
{
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx : GrProcessorUnitTest::kAlphaTextureIdx;
=======
GrGeometryProcessor* GrDistanceFieldLCDTextGeoProc::TestCreate(GrProcessorTestData* d) {
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
    DistanceAdjust wa = { 0.0f, 0.1f, -0.1f };
    uint32_t flags = kUseLCD_DistanceFieldEffectFlag;
    flags |= d->fRandom->nextBool() ? kSimilarity_DistanceFieldEffectFlag : 0;
    if (flags & kSimilarity_DistanceFieldEffectFlag) {
        flags |= d->fRandom->nextBool() ? kScaleOnly_DistanceFieldEffectFlag : 0;
    }
    flags |= d->fRandom->nextBool() ? kBGR_DistanceFieldEffectFlag : 0;
    return GrDistanceFieldLCDTextGeoProc::Make(GrRandomColor(d->fRandom),
        GrTest::TestMatrix(d->fRandom),
        d->fTextures[texIdx], params,
        wa,
        flags,
        d->fRandom->nextBool());
=======
    GrTextureParams params(tileModes, d->fRandom->nextBool() ? GrTextureParams::kBilerp_FilterMode :
                           GrTextureParams::kNone_FilterMode);
    DistanceAdjust wa = { 0.0f, 0.1f, -0.1f };
    uint32_t flags = kUseLCD_DistanceFieldEffectFlag;
    flags |= d->fRandom->nextBool() ? kUniformScale_DistanceFieldEffectMask : 0;
    flags |= d->fRandom->nextBool() ? kBGR_DistanceFieldEffectFlag : 0;
    return GrDistanceFieldLCDTextGeoProc::Create(GrRandomColor(d->fRandom),
                                                 GrTest::TestMatrix(d->fRandom),
                                                 d->fTextures[texIdx], params,
                                                 wa,
                                                 flags,
                                                 d->fRandom->nextBool());
>>>>>>> miniblink49
}
