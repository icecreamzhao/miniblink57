/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrBezierEffect.h"

<<<<<<< HEAD
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLGeometryProcessor.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
#include "glsl/GrGLSLUtil.h"
#include "glsl/GrGLSLVarying.h"
#include "glsl/GrGLSLVertexShaderBuilder.h"

class GrGLConicEffect : public GrGLSLGeometryProcessor {
public:
    GrGLConicEffect(const GrGeometryProcessor&);
=======
#include "gl/GrGLProcessor.h"
#include "gl/GrGLGeometryProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"

class GrGLConicEffect : public GrGLGeometryProcessor {
public:
    GrGLConicEffect(const GrGeometryProcessor&,
                    const GrBatchTracker&);
>>>>>>> miniblink49

    void onEmitCode(EmitArgs&, GrGPArgs*) override;

    static inline void GenKey(const GrGeometryProcessor&,
<<<<<<< HEAD
        const GrGLSLCaps&,
        GrProcessorKeyBuilder*);

    void setData(const GrGLSLProgramDataManager& pdman,
        const GrPrimitiveProcessor& primProc) override
    {
=======
                              const GrBatchTracker&,
                              const GrGLSLCaps&,
                              GrProcessorKeyBuilder*);

    virtual void setData(const GrGLProgramDataManager& pdman,
                         const GrPrimitiveProcessor& primProc,
                         const GrBatchTracker& bt) override {
>>>>>>> miniblink49
        const GrConicEffect& ce = primProc.cast<GrConicEffect>();

        if (!ce.viewMatrix().isIdentity() && !fViewMatrix.cheapEqualTo(ce.viewMatrix())) {
            fViewMatrix = ce.viewMatrix();
<<<<<<< HEAD
            float viewMatrix[3 * 3];
            GrGLSLGetMatrix<3>(viewMatrix, fViewMatrix);
=======
            GrGLfloat viewMatrix[3 * 3];
            GrGLGetMatrix<3>(viewMatrix, fViewMatrix);
>>>>>>> miniblink49
            pdman.setMatrix3f(fViewMatrixUniform, viewMatrix);
        }

        if (ce.color() != fColor) {
<<<<<<< HEAD
            float c[4];
=======
            GrGLfloat c[4];
>>>>>>> miniblink49
            GrColorToRGBAFloat(ce.color(), c);
            pdman.set4fv(fColorUniform, 1, c);
            fColor = ce.color();
        }

        if (ce.coverageScale() != 0xff && ce.coverageScale() != fCoverageScale) {
            pdman.set1f(fCoverageScaleUniform, GrNormalizeByteToFloat(ce.coverageScale()));
            fCoverageScale = ce.coverageScale();
        }
    }

    void setTransformData(const GrPrimitiveProcessor& primProc,
<<<<<<< HEAD
        const GrGLSLProgramDataManager& pdman,
        int index,
        const SkTArray<const GrCoordTransform*, true>& transforms) override
    {
=======
                          const GrGLProgramDataManager& pdman,
                          int index,
                          const SkTArray<const GrCoordTransform*, true>& transforms) override {
>>>>>>> miniblink49
        this->setTransformDataHelper<GrConicEffect>(primProc, pdman, index, transforms);
    }

private:
    SkMatrix fViewMatrix;
    GrColor fColor;
    uint8_t fCoverageScale;
    GrPrimitiveEdgeType fEdgeType;
    UniformHandle fColorUniform;
    UniformHandle fCoverageScaleUniform;
    UniformHandle fViewMatrixUniform;

<<<<<<< HEAD
    typedef GrGLSLGeometryProcessor INHERITED;
};

GrGLConicEffect::GrGLConicEffect(const GrGeometryProcessor& processor)
    : fViewMatrix(SkMatrix::InvalidMatrix())
    , fColor(GrColor_ILLEGAL)
    , fCoverageScale(0xff)
{
=======
    typedef GrGLGeometryProcessor INHERITED;
};

GrGLConicEffect::GrGLConicEffect(const GrGeometryProcessor& processor,
                                 const GrBatchTracker& bt)
    : fViewMatrix(SkMatrix::InvalidMatrix()), fColor(GrColor_ILLEGAL), fCoverageScale(0xff) {
>>>>>>> miniblink49
    const GrConicEffect& ce = processor.cast<GrConicEffect>();
    fEdgeType = ce.getEdgeType();
}

<<<<<<< HEAD
void GrGLConicEffect::onEmitCode(EmitArgs& args, GrGPArgs* gpArgs)
{
    GrGLSLVertexBuilder* vertBuilder = args.fVertBuilder;
    const GrConicEffect& gp = args.fGP.cast<GrConicEffect>();
    GrGLSLVaryingHandler* varyingHandler = args.fVaryingHandler;
    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;

    // emit attributes
    varyingHandler->emitAttributes(gp);

    GrGLSLVertToFrag v(kVec4f_GrSLType);
    varyingHandler->addVarying("ConicCoeffs", &v, kHigh_GrSLPrecision);
    vertBuilder->codeAppendf("%s = %s;", v.vsOut(), gp.inConicCoeffs()->fName);

    GrGLSLPPFragmentBuilder* fragBuilder = args.fFragBuilder;
    // Setup pass through color
    if (!gp.colorIgnored()) {
        this->setupUniformColor(fragBuilder, uniformHandler, args.fOutputColor, &fColorUniform);
    }

    // Setup position
    this->setupPosition(vertBuilder,
        uniformHandler,
        gpArgs,
        gp.inPosition()->fName,
        gp.viewMatrix(),
        &fViewMatrixUniform);

    // emit transforms with position
    this->emitTransforms(vertBuilder,
        varyingHandler,
        uniformHandler,
        gpArgs->fPositionVar,
        gp.inPosition()->fName,
        gp.localMatrix(),
        args.fTransformsIn,
        args.fTransformsOut);

    // TODO: this precision check should actually be a check on the number of bits
    // high and medium provide and the selection of the lowest level that suffices.
    // Additionally we should assert that the upstream code only lets us get here if
    // either high or medium provides the required number of bits.
    GrSLPrecision precision = kHigh_GrSLPrecision;
    const GrShaderCaps::PrecisionInfo& highP = args.fGLSLCaps->getFloatShaderPrecisionInfo(
        kFragment_GrShaderType,
        kHigh_GrSLPrecision);
    if (!highP.supported()) {
        precision = kMedium_GrSLPrecision;
    }

    GrGLSLShaderVar edgeAlpha("edgeAlpha", kFloat_GrSLType, 0, precision);
    GrGLSLShaderVar dklmdx("dklmdx", kVec3f_GrSLType, 0, precision);
    GrGLSLShaderVar dklmdy("dklmdy", kVec3f_GrSLType, 0, precision);
    GrGLSLShaderVar dfdx("dfdx", kFloat_GrSLType, 0, precision);
    GrGLSLShaderVar dfdy("dfdy", kFloat_GrSLType, 0, precision);
    GrGLSLShaderVar gF("gF", kVec2f_GrSLType, 0, precision);
    GrGLSLShaderVar gFM("gFM", kFloat_GrSLType, 0, precision);
    GrGLSLShaderVar func("func", kFloat_GrSLType, 0, precision);

    fragBuilder->declAppend(edgeAlpha);
    fragBuilder->declAppend(dklmdx);
    fragBuilder->declAppend(dklmdy);
    fragBuilder->declAppend(dfdx);
    fragBuilder->declAppend(dfdy);
    fragBuilder->declAppend(gF);
    fragBuilder->declAppend(gFM);
    fragBuilder->declAppend(func);

    switch (fEdgeType) {
    case kHairlineAA_GrProcessorEdgeType: {
        SkAssertResult(fragBuilder->enableFeature(
            GrGLSLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
        fragBuilder->codeAppendf("%s = dFdx(%s.xyz);", dklmdx.c_str(), v.fsIn());
        fragBuilder->codeAppendf("%s = dFdy(%s.xyz);", dklmdy.c_str(), v.fsIn());
        fragBuilder->codeAppendf("%s = 2.0 * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
            dfdx.c_str(),
            v.fsIn(), dklmdx.c_str(),
            v.fsIn(), dklmdx.c_str(),
            v.fsIn(), dklmdx.c_str());
        fragBuilder->codeAppendf("%s = 2.0 * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
            dfdy.c_str(),
            v.fsIn(), dklmdy.c_str(),
            v.fsIn(), dklmdy.c_str(),
            v.fsIn(), dklmdy.c_str());
        fragBuilder->codeAppendf("%s = vec2(%s, %s);", gF.c_str(), dfdx.c_str(), dfdy.c_str());
        fragBuilder->codeAppendf("%s = sqrt(dot(%s, %s));",
            gFM.c_str(), gF.c_str(), gF.c_str());
        fragBuilder->codeAppendf("%s = %s.x*%s.x - %s.y*%s.z;",
            func.c_str(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn());
        fragBuilder->codeAppendf("%s = abs(%s);", func.c_str(), func.c_str());
        fragBuilder->codeAppendf("%s = %s / %s;",
            edgeAlpha.c_str(), func.c_str(), gFM.c_str());
        fragBuilder->codeAppendf("%s = max(1.0 - %s, 0.0);",
            edgeAlpha.c_str(), edgeAlpha.c_str());
        // Add line below for smooth cubic ramp
        // fragBuilder->codeAppend("edgeAlpha = edgeAlpha*edgeAlpha*(3.0-2.0*edgeAlpha);");
        break;
    }
    case kFillAA_GrProcessorEdgeType: {
        SkAssertResult(fragBuilder->enableFeature(
            GrGLSLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
        fragBuilder->codeAppendf("%s = dFdx(%s.xyz);", dklmdx.c_str(), v.fsIn());
        fragBuilder->codeAppendf("%s = dFdy(%s.xyz);", dklmdy.c_str(), v.fsIn());
        fragBuilder->codeAppendf("%s ="
                                 "2.0 * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
            dfdx.c_str(),
            v.fsIn(), dklmdx.c_str(),
            v.fsIn(), dklmdx.c_str(),
            v.fsIn(), dklmdx.c_str());
        fragBuilder->codeAppendf("%s ="
                                 "2.0 * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
            dfdy.c_str(),
            v.fsIn(), dklmdy.c_str(),
            v.fsIn(), dklmdy.c_str(),
            v.fsIn(), dklmdy.c_str());
        fragBuilder->codeAppendf("%s = vec2(%s, %s);", gF.c_str(), dfdx.c_str(), dfdy.c_str());
        fragBuilder->codeAppendf("%s = sqrt(dot(%s, %s));",
            gFM.c_str(), gF.c_str(), gF.c_str());
        fragBuilder->codeAppendf("%s = %s.x * %s.x - %s.y * %s.z;",
            func.c_str(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn());
        fragBuilder->codeAppendf("%s = %s / %s;",
            edgeAlpha.c_str(), func.c_str(), gFM.c_str());
        fragBuilder->codeAppendf("%s = clamp(1.0 - %s, 0.0, 1.0);",
            edgeAlpha.c_str(), edgeAlpha.c_str());
        // Add line below for smooth cubic ramp
        // fragBuilder->codeAppend("edgeAlpha = edgeAlpha*edgeAlpha*(3.0-2.0*edgeAlpha);");
        break;
    }
    case kFillBW_GrProcessorEdgeType: {
        fragBuilder->codeAppendf("%s = %s.x * %s.x - %s.y * %s.z;",
            edgeAlpha.c_str(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn());
        fragBuilder->codeAppendf("%s = float(%s < 0.0);",
            edgeAlpha.c_str(), edgeAlpha.c_str());
        break;
    }
    default:
        SkFAIL("Shouldn't get here");
=======
void GrGLConicEffect::onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) {
    GrGLGPBuilder* pb = args.fPB;
    GrGLVertexBuilder* vsBuilder = args.fPB->getVertexShaderBuilder();
    const GrConicEffect& gp = args.fGP.cast<GrConicEffect>();

    // emit attributes
    vsBuilder->emitAttributes(gp);

    GrGLVertToFrag v(kVec4f_GrSLType);
    args.fPB->addVarying("ConicCoeffs", &v);
    vsBuilder->codeAppendf("%s = %s;", v.vsOut(), gp.inConicCoeffs()->fName);

    // Setup pass through color
    if (!gp.colorIgnored()) {
        this->setupUniformColor(args.fPB, args.fOutputColor, &fColorUniform);
    }

    // Setup position
    this->setupPosition(pb, gpArgs, gp.inPosition()->fName, gp.viewMatrix(), &fViewMatrixUniform);

    // emit transforms with position
    this->emitTransforms(pb, gpArgs->fPositionVar, gp.inPosition()->fName, gp.localMatrix(),
                         args.fTransformsIn, args.fTransformsOut);

    GrGLFragmentBuilder* fsBuilder = args.fPB->getFragmentShaderBuilder();
    fsBuilder->codeAppend("float edgeAlpha;");

    switch (fEdgeType) {
        case kHairlineAA_GrProcessorEdgeType: {
            SkAssertResult(fsBuilder->enableFeature(
                    GrGLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
            fsBuilder->codeAppendf("vec3 dklmdx = dFdx(%s.xyz);", v.fsIn());
            fsBuilder->codeAppendf("vec3 dklmdy = dFdy(%s.xyz);", v.fsIn());
            fsBuilder->codeAppendf("float dfdx ="
                                   "2.0 * %s.x * dklmdx.x - %s.y * dklmdx.z - %s.z * dklmdx.y;",
                                   v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppendf("float dfdy ="
                                   "2.0 * %s.x * dklmdy.x - %s.y * dklmdy.z - %s.z * dklmdy.y;",
                                   v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppend("vec2 gF = vec2(dfdx, dfdy);");
            fsBuilder->codeAppend("float gFM = sqrt(dot(gF, gF));");
            fsBuilder->codeAppendf("float func = %s.x*%s.x - %s.y*%s.z;", v.fsIn(), v.fsIn(),
                                   v.fsIn(), v.fsIn());
            fsBuilder->codeAppend("func = abs(func);");
            fsBuilder->codeAppend("edgeAlpha = func / gFM;");
            fsBuilder->codeAppend("edgeAlpha = max(1.0 - edgeAlpha, 0.0);");
            // Add line below for smooth cubic ramp
            // fsBuilder->codeAppend("edgeAlpha = edgeAlpha*edgeAlpha*(3.0-2.0*edgeAlpha);");
            break;
        }
        case kFillAA_GrProcessorEdgeType: {
            SkAssertResult(fsBuilder->enableFeature(
                    GrGLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
            fsBuilder->codeAppendf("vec3 dklmdx = dFdx(%s.xyz);", v.fsIn());
            fsBuilder->codeAppendf("vec3 dklmdy = dFdy(%s.xyz);", v.fsIn());
            fsBuilder->codeAppendf("float dfdx ="
                                   "2.0 * %s.x * dklmdx.x - %s.y * dklmdx.z - %s.z * dklmdx.y;",
                                   v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppendf("float dfdy ="
                                   "2.0 * %s.x * dklmdy.x - %s.y * dklmdy.z - %s.z * dklmdy.y;",
                                   v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppend("vec2 gF = vec2(dfdx, dfdy);");
            fsBuilder->codeAppend("float gFM = sqrt(dot(gF, gF));");
            fsBuilder->codeAppendf("float func = %s.x * %s.x - %s.y * %s.z;", v.fsIn(), v.fsIn(),
                                   v.fsIn(), v.fsIn());
            fsBuilder->codeAppend("edgeAlpha = func / gFM;");
            fsBuilder->codeAppend("edgeAlpha = clamp(1.0 - edgeAlpha, 0.0, 1.0);");
            // Add line below for smooth cubic ramp
            // fsBuilder->codeAppend("edgeAlpha = edgeAlpha*edgeAlpha*(3.0-2.0*edgeAlpha);");
            break;
        }
        case kFillBW_GrProcessorEdgeType: {
            fsBuilder->codeAppendf("edgeAlpha = %s.x * %s.x - %s.y * %s.z;", v.fsIn(), v.fsIn(),
                                   v.fsIn(), v.fsIn());
            fsBuilder->codeAppend("edgeAlpha = float(edgeAlpha < 0.0);");
            break;
        }
        default:
            SkFAIL("Shouldn't get here");
>>>>>>> miniblink49
    }

    // TODO should we really be doing this?
    if (gp.coverageScale() != 0xff) {
        const char* coverageScale;
<<<<<<< HEAD
        fCoverageScaleUniform = uniformHandler->addUniform(kFragment_GrShaderFlag,
            kFloat_GrSLType,
            kHigh_GrSLPrecision,
            "Coverage",
            &coverageScale);
        fragBuilder->codeAppendf("%s = vec4(%s * %s);",
            args.fOutputCoverage, coverageScale, edgeAlpha.c_str());
    } else {
        fragBuilder->codeAppendf("%s = vec4(%s);", args.fOutputCoverage, edgeAlpha.c_str());
=======
        fCoverageScaleUniform = pb->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                               kFloat_GrSLType,
                                               kDefault_GrSLPrecision,
                                               "Coverage",
                                               &coverageScale);
        fsBuilder->codeAppendf("%s = vec4(%s * edgeAlpha);", args.fOutputCoverage, coverageScale);
    } else {
        fsBuilder->codeAppendf("%s = vec4(edgeAlpha);", args.fOutputCoverage);
>>>>>>> miniblink49
    }
}

void GrGLConicEffect::GenKey(const GrGeometryProcessor& gp,
<<<<<<< HEAD
    const GrGLSLCaps&,
    GrProcessorKeyBuilder* b)
{
=======
                             const GrBatchTracker& bt,
                             const GrGLSLCaps&,
                             GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    const GrConicEffect& ce = gp.cast<GrConicEffect>();
    uint32_t key = ce.isAntiAliased() ? (ce.isFilled() ? 0x0 : 0x1) : 0x2;
    key |= GrColor_ILLEGAL != ce.color() ? 0x4 : 0x0;
    key |= 0xff != ce.coverageScale() ? 0x8 : 0x0;
    key |= ce.usesLocalCoords() && ce.localMatrix().hasPerspective() ? 0x10 : 0x0;
    key |= ComputePosKey(ce.viewMatrix()) << 5;
    b->add32(key);
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrConicEffect::~GrConicEffect() { }

void GrConicEffect::getGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLConicEffect::GenKey(*this, caps, b);
}

GrGLSLPrimitiveProcessor* GrConicEffect::createGLSLInstance(const GrGLSLCaps&) const
{
    return new GrGLConicEffect(*this);
}

GrConicEffect::GrConicEffect(GrColor color, const SkMatrix& viewMatrix, uint8_t coverage,
    GrPrimitiveEdgeType edgeType, const SkMatrix& localMatrix,
    bool usesLocalCoords)
=======
GrConicEffect::~GrConicEffect() {}

void GrConicEffect::getGLProcessorKey(const GrBatchTracker& bt,
                                      const GrGLSLCaps& caps,
                                      GrProcessorKeyBuilder* b) const {
    GrGLConicEffect::GenKey(*this, bt, caps, b);
}

GrGLPrimitiveProcessor* GrConicEffect::createGLInstance(const GrBatchTracker& bt,
                                                        const GrGLSLCaps&) const {
    return SkNEW_ARGS(GrGLConicEffect, (*this, bt));
}

GrConicEffect::GrConicEffect(GrColor color, const SkMatrix& viewMatrix, uint8_t coverage,
                             GrPrimitiveEdgeType edgeType, const SkMatrix& localMatrix,
                             bool usesLocalCoords)
>>>>>>> miniblink49
    : fColor(color)
    , fViewMatrix(viewMatrix)
    , fLocalMatrix(viewMatrix)
    , fUsesLocalCoords(usesLocalCoords)
    , fCoverageScale(coverage)
<<<<<<< HEAD
    , fEdgeType(edgeType)
{
    this->initClassID<GrConicEffect>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
        kHigh_GrSLPrecision));
    fInConicCoeffs = &this->addVertexAttrib(Attribute("inConicCoeffs",
        kVec4f_GrVertexAttribType));
=======
    , fEdgeType(edgeType) {
    this->initClassID<GrConicEffect>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
                                                   kHigh_GrSLPrecision));
    fInConicCoeffs = &this->addVertexAttrib(Attribute("inConicCoeffs",
                                                      kVec4f_GrVertexAttribType));
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

GR_DEFINE_GEOMETRY_PROCESSOR_TEST(GrConicEffect);

<<<<<<< HEAD
sk_sp<GrGeometryProcessor> GrConicEffect::TestCreate(GrProcessorTestData* d)
{
    sk_sp<GrGeometryProcessor> gp;
    do {
        GrPrimitiveEdgeType edgeType = static_cast<GrPrimitiveEdgeType>(
            d->fRandom->nextULessThan(kGrProcessorEdgeTypeCnt));
        gp = GrConicEffect::Make(GrRandomColor(d->fRandom), GrTest::TestMatrix(d->fRandom),
            edgeType, *d->fCaps,
            GrTest::TestMatrix(d->fRandom), d->fRandom->nextBool());
    } while (nullptr == gp);
=======
GrGeometryProcessor* GrConicEffect::TestCreate(GrProcessorTestData* d) {
    GrGeometryProcessor* gp;
    do {
        GrPrimitiveEdgeType edgeType =
                static_cast<GrPrimitiveEdgeType>(
                        d->fRandom->nextULessThan(kGrProcessorEdgeTypeCnt));
        gp = GrConicEffect::Create(GrRandomColor(d->fRandom), GrTest::TestMatrix(d->fRandom),
                                   edgeType, *d->fCaps,
                                   GrTest::TestMatrix(d->fRandom), d->fRandom->nextBool());
    } while (NULL == gp);
>>>>>>> miniblink49
    return gp;
}

//////////////////////////////////////////////////////////////////////////////
// Quad
//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GrGLQuadEffect : public GrGLSLGeometryProcessor {
public:
    GrGLQuadEffect(const GrGeometryProcessor&);
=======
class GrGLQuadEffect : public GrGLGeometryProcessor {
public:
    GrGLQuadEffect(const GrGeometryProcessor&,
                   const GrBatchTracker&);
>>>>>>> miniblink49

    void onEmitCode(EmitArgs&, GrGPArgs*) override;

    static inline void GenKey(const GrGeometryProcessor&,
<<<<<<< HEAD
        const GrGLSLCaps&,
        GrProcessorKeyBuilder*);

    void setData(const GrGLSLProgramDataManager& pdman,
        const GrPrimitiveProcessor& primProc) override
    {
=======
                              const GrBatchTracker&,
                              const GrGLSLCaps&,
                              GrProcessorKeyBuilder*);

    virtual void setData(const GrGLProgramDataManager& pdman,
                         const GrPrimitiveProcessor& primProc,
                         const GrBatchTracker& bt) override {
>>>>>>> miniblink49
        const GrQuadEffect& qe = primProc.cast<GrQuadEffect>();

        if (!qe.viewMatrix().isIdentity() && !fViewMatrix.cheapEqualTo(qe.viewMatrix())) {
            fViewMatrix = qe.viewMatrix();
<<<<<<< HEAD
            float viewMatrix[3 * 3];
            GrGLSLGetMatrix<3>(viewMatrix, fViewMatrix);
=======
            GrGLfloat viewMatrix[3 * 3];
            GrGLGetMatrix<3>(viewMatrix, fViewMatrix);
>>>>>>> miniblink49
            pdman.setMatrix3f(fViewMatrixUniform, viewMatrix);
        }

        if (qe.color() != fColor) {
<<<<<<< HEAD
            float c[4];
=======
            GrGLfloat c[4];
>>>>>>> miniblink49
            GrColorToRGBAFloat(qe.color(), c);
            pdman.set4fv(fColorUniform, 1, c);
            fColor = qe.color();
        }

        if (qe.coverageScale() != 0xff && qe.coverageScale() != fCoverageScale) {
            pdman.set1f(fCoverageScaleUniform, GrNormalizeByteToFloat(qe.coverageScale()));
            fCoverageScale = qe.coverageScale();
        }
    }

    void setTransformData(const GrPrimitiveProcessor& primProc,
<<<<<<< HEAD
        const GrGLSLProgramDataManager& pdman,
        int index,
        const SkTArray<const GrCoordTransform*, true>& transforms) override
    {
=======
                          const GrGLProgramDataManager& pdman,
                          int index,
                          const SkTArray<const GrCoordTransform*, true>& transforms) override {
>>>>>>> miniblink49
        this->setTransformDataHelper<GrQuadEffect>(primProc, pdman, index, transforms);
    }

private:
    SkMatrix fViewMatrix;
    GrColor fColor;
    uint8_t fCoverageScale;
    GrPrimitiveEdgeType fEdgeType;
    UniformHandle fColorUniform;
    UniformHandle fCoverageScaleUniform;
    UniformHandle fViewMatrixUniform;

<<<<<<< HEAD
    typedef GrGLSLGeometryProcessor INHERITED;
};

GrGLQuadEffect::GrGLQuadEffect(const GrGeometryProcessor& processor)
    : fViewMatrix(SkMatrix::InvalidMatrix())
    , fColor(GrColor_ILLEGAL)
    , fCoverageScale(0xff)
{
=======
    typedef GrGLGeometryProcessor INHERITED;
};

GrGLQuadEffect::GrGLQuadEffect(const GrGeometryProcessor& processor,
                               const GrBatchTracker& bt)
    : fViewMatrix(SkMatrix::InvalidMatrix()), fColor(GrColor_ILLEGAL), fCoverageScale(0xff) {
>>>>>>> miniblink49
    const GrQuadEffect& ce = processor.cast<GrQuadEffect>();
    fEdgeType = ce.getEdgeType();
}

<<<<<<< HEAD
void GrGLQuadEffect::onEmitCode(EmitArgs& args, GrGPArgs* gpArgs)
{
    GrGLSLVertexBuilder* vertBuilder = args.fVertBuilder;
    const GrQuadEffect& gp = args.fGP.cast<GrQuadEffect>();
    GrGLSLVaryingHandler* varyingHandler = args.fVaryingHandler;
    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;

    // emit attributes
    varyingHandler->emitAttributes(gp);

    GrGLSLVertToFrag v(kVec4f_GrSLType);
    varyingHandler->addVarying("HairQuadEdge", &v);
    vertBuilder->codeAppendf("%s = %s;", v.vsOut(), gp.inHairQuadEdge()->fName);

    GrGLSLPPFragmentBuilder* fragBuilder = args.fFragBuilder;
    // Setup pass through color
    if (!gp.colorIgnored()) {
        this->setupUniformColor(fragBuilder, uniformHandler, args.fOutputColor, &fColorUniform);
    }

    // Setup position
    this->setupPosition(vertBuilder,
        uniformHandler,
        gpArgs,
        gp.inPosition()->fName,
        gp.viewMatrix(),
        &fViewMatrixUniform);

    // emit transforms with position
    this->emitTransforms(vertBuilder,
        varyingHandler,
        uniformHandler,
        gpArgs->fPositionVar,
        gp.inPosition()->fName,
        gp.localMatrix(),
        args.fTransformsIn,
        args.fTransformsOut);

    fragBuilder->codeAppendf("float edgeAlpha;");

    switch (fEdgeType) {
    case kHairlineAA_GrProcessorEdgeType: {
        SkAssertResult(fragBuilder->enableFeature(
            GrGLSLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
        fragBuilder->codeAppendf("vec2 duvdx = dFdx(%s.xy);", v.fsIn());
        fragBuilder->codeAppendf("vec2 duvdy = dFdy(%s.xy);", v.fsIn());
        fragBuilder->codeAppendf("vec2 gF = vec2(2.0 * %s.x * duvdx.x - duvdx.y,"
                                 "               2.0 * %s.x * duvdy.x - duvdy.y);",
            v.fsIn(), v.fsIn());
        fragBuilder->codeAppendf("edgeAlpha = (%s.x * %s.x - %s.y);",
            v.fsIn(), v.fsIn(), v.fsIn());
        fragBuilder->codeAppend("edgeAlpha = sqrt(edgeAlpha * edgeAlpha / dot(gF, gF));");
        fragBuilder->codeAppend("edgeAlpha = max(1.0 - edgeAlpha, 0.0);");
        // Add line below for smooth cubic ramp
        // fragBuilder->codeAppend("edgeAlpha = edgeAlpha*edgeAlpha*(3.0-2.0*edgeAlpha);");
        break;
    }
    case kFillAA_GrProcessorEdgeType: {
        SkAssertResult(fragBuilder->enableFeature(
            GrGLSLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
        fragBuilder->codeAppendf("vec2 duvdx = dFdx(%s.xy);", v.fsIn());
        fragBuilder->codeAppendf("vec2 duvdy = dFdy(%s.xy);", v.fsIn());
        fragBuilder->codeAppendf("vec2 gF = vec2(2.0 * %s.x * duvdx.x - duvdx.y,"
                                 "               2.0 * %s.x * duvdy.x - duvdy.y);",
            v.fsIn(), v.fsIn());
        fragBuilder->codeAppendf("edgeAlpha = (%s.x * %s.x - %s.y);",
            v.fsIn(), v.fsIn(), v.fsIn());
        fragBuilder->codeAppend("edgeAlpha = edgeAlpha / sqrt(dot(gF, gF));");
        fragBuilder->codeAppend("edgeAlpha = clamp(1.0 - edgeAlpha, 0.0, 1.0);");
        // Add line below for smooth cubic ramp
        // fragBuilder->codeAppend("edgeAlpha = edgeAlpha*edgeAlpha*(3.0-2.0*edgeAlpha);");
        break;
    }
    case kFillBW_GrProcessorEdgeType: {
        fragBuilder->codeAppendf("edgeAlpha = (%s.x * %s.x - %s.y);",
            v.fsIn(), v.fsIn(), v.fsIn());
        fragBuilder->codeAppend("edgeAlpha = float(edgeAlpha < 0.0);");
        break;
    }
    default:
        SkFAIL("Shouldn't get here");
=======
void GrGLQuadEffect::onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) {
    GrGLGPBuilder* pb = args.fPB;
    GrGLVertexBuilder* vsBuilder = args.fPB->getVertexShaderBuilder();
    const GrQuadEffect& gp = args.fGP.cast<GrQuadEffect>();

    // emit attributes
    vsBuilder->emitAttributes(gp);

    GrGLVertToFrag v(kVec4f_GrSLType);
    args.fPB->addVarying("HairQuadEdge", &v);
    vsBuilder->codeAppendf("%s = %s;", v.vsOut(), gp.inHairQuadEdge()->fName);

    // Setup pass through color
    if (!gp.colorIgnored()) {
        this->setupUniformColor(args.fPB, args.fOutputColor, &fColorUniform);
    }

    // Setup position
    this->setupPosition(pb, gpArgs, gp.inPosition()->fName, gp.viewMatrix(), &fViewMatrixUniform);

    // emit transforms with position
    this->emitTransforms(pb, gpArgs->fPositionVar, gp.inPosition()->fName, gp.localMatrix(),
                         args.fTransformsIn, args.fTransformsOut);

    GrGLFragmentBuilder* fsBuilder = args.fPB->getFragmentShaderBuilder();
    fsBuilder->codeAppendf("float edgeAlpha;");

    switch (fEdgeType) {
        case kHairlineAA_GrProcessorEdgeType: {
            SkAssertResult(fsBuilder->enableFeature(
                    GrGLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
            fsBuilder->codeAppendf("vec2 duvdx = dFdx(%s.xy);", v.fsIn());
            fsBuilder->codeAppendf("vec2 duvdy = dFdy(%s.xy);", v.fsIn());
            fsBuilder->codeAppendf("vec2 gF = vec2(2.0 * %s.x * duvdx.x - duvdx.y,"
                                   "               2.0 * %s.x * duvdy.x - duvdy.y);",
                                   v.fsIn(), v.fsIn());
            fsBuilder->codeAppendf("edgeAlpha = (%s.x * %s.x - %s.y);", v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppend("edgeAlpha = sqrt(edgeAlpha * edgeAlpha / dot(gF, gF));");
            fsBuilder->codeAppend("edgeAlpha = max(1.0 - edgeAlpha, 0.0);");
            // Add line below for smooth cubic ramp
            // fsBuilder->codeAppend("edgeAlpha = edgeAlpha*edgeAlpha*(3.0-2.0*edgeAlpha);");
            break;
        }
        case kFillAA_GrProcessorEdgeType: {
            SkAssertResult(fsBuilder->enableFeature(
                    GrGLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
            fsBuilder->codeAppendf("vec2 duvdx = dFdx(%s.xy);", v.fsIn());
            fsBuilder->codeAppendf("vec2 duvdy = dFdy(%s.xy);", v.fsIn());
            fsBuilder->codeAppendf("vec2 gF = vec2(2.0 * %s.x * duvdx.x - duvdx.y,"
                                   "               2.0 * %s.x * duvdy.x - duvdy.y);",
                                   v.fsIn(), v.fsIn());
            fsBuilder->codeAppendf("edgeAlpha = (%s.x * %s.x - %s.y);", v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppend("edgeAlpha = edgeAlpha / sqrt(dot(gF, gF));");
            fsBuilder->codeAppend("edgeAlpha = clamp(1.0 - edgeAlpha, 0.0, 1.0);");
            // Add line below for smooth cubic ramp
            // fsBuilder->codeAppend("edgeAlpha = edgeAlpha*edgeAlpha*(3.0-2.0*edgeAlpha);");
            break;
        }
        case kFillBW_GrProcessorEdgeType: {
            fsBuilder->codeAppendf("edgeAlpha = (%s.x * %s.x - %s.y);", v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppend("edgeAlpha = float(edgeAlpha < 0.0);");
            break;
        }
        default:
            SkFAIL("Shouldn't get here");
>>>>>>> miniblink49
    }

    if (0xff != gp.coverageScale()) {
        const char* coverageScale;
<<<<<<< HEAD
        fCoverageScaleUniform = uniformHandler->addUniform(kFragment_GrShaderFlag,
            kFloat_GrSLType,
            kDefault_GrSLPrecision,
            "Coverage",
            &coverageScale);
        fragBuilder->codeAppendf("%s = vec4(%s * edgeAlpha);", args.fOutputCoverage, coverageScale);
    } else {
        fragBuilder->codeAppendf("%s = vec4(edgeAlpha);", args.fOutputCoverage);
=======
        fCoverageScaleUniform = pb->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                          kFloat_GrSLType,
                                          kDefault_GrSLPrecision,
                                          "Coverage",
                                          &coverageScale);
        fsBuilder->codeAppendf("%s = vec4(%s * edgeAlpha);", args.fOutputCoverage, coverageScale);
    } else {
        fsBuilder->codeAppendf("%s = vec4(edgeAlpha);", args.fOutputCoverage);
>>>>>>> miniblink49
    }
}

void GrGLQuadEffect::GenKey(const GrGeometryProcessor& gp,
<<<<<<< HEAD
    const GrGLSLCaps&,
    GrProcessorKeyBuilder* b)
{
=======
                            const GrBatchTracker& bt,
                            const GrGLSLCaps&,
                            GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    const GrQuadEffect& ce = gp.cast<GrQuadEffect>();
    uint32_t key = ce.isAntiAliased() ? (ce.isFilled() ? 0x0 : 0x1) : 0x2;
    key |= ce.color() != GrColor_ILLEGAL ? 0x4 : 0x0;
    key |= ce.coverageScale() != 0xff ? 0x8 : 0x0;
    key |= ce.usesLocalCoords() && ce.localMatrix().hasPerspective() ? 0x10 : 0x0;
    key |= ComputePosKey(ce.viewMatrix()) << 5;
    b->add32(key);
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrQuadEffect::~GrQuadEffect() { }

void GrQuadEffect::getGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLQuadEffect::GenKey(*this, caps, b);
}

GrGLSLPrimitiveProcessor* GrQuadEffect::createGLSLInstance(const GrGLSLCaps&) const
{
    return new GrGLQuadEffect(*this);
}

GrQuadEffect::GrQuadEffect(GrColor color, const SkMatrix& viewMatrix, uint8_t coverage,
    GrPrimitiveEdgeType edgeType, const SkMatrix& localMatrix,
    bool usesLocalCoords)
=======
GrQuadEffect::~GrQuadEffect() {}

void GrQuadEffect::getGLProcessorKey(const GrBatchTracker& bt,
                                     const GrGLSLCaps& caps,
                                     GrProcessorKeyBuilder* b) const {
    GrGLQuadEffect::GenKey(*this, bt, caps, b);
}

GrGLPrimitiveProcessor* GrQuadEffect::createGLInstance(const GrBatchTracker& bt,
                                                       const GrGLSLCaps&) const {
    return SkNEW_ARGS(GrGLQuadEffect, (*this, bt));
}

GrQuadEffect::GrQuadEffect(GrColor color, const SkMatrix& viewMatrix, uint8_t coverage,
                           GrPrimitiveEdgeType edgeType, const SkMatrix& localMatrix,
                           bool usesLocalCoords)
>>>>>>> miniblink49
    : fColor(color)
    , fViewMatrix(viewMatrix)
    , fLocalMatrix(localMatrix)
    , fUsesLocalCoords(usesLocalCoords)
    , fCoverageScale(coverage)
<<<<<<< HEAD
    , fEdgeType(edgeType)
{
    this->initClassID<GrQuadEffect>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
        kHigh_GrSLPrecision));
    fInHairQuadEdge = &this->addVertexAttrib(Attribute("inHairQuadEdge",
        kVec4f_GrVertexAttribType));
=======
    , fEdgeType(edgeType) {
    this->initClassID<GrQuadEffect>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
                                                   kHigh_GrSLPrecision));
    fInHairQuadEdge = &this->addVertexAttrib(Attribute("inHairQuadEdge",
                                                        kVec4f_GrVertexAttribType));
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

GR_DEFINE_GEOMETRY_PROCESSOR_TEST(GrQuadEffect);

<<<<<<< HEAD
sk_sp<GrGeometryProcessor> GrQuadEffect::TestCreate(GrProcessorTestData* d)
{
    sk_sp<GrGeometryProcessor> gp;
    do {
        GrPrimitiveEdgeType edgeType = static_cast<GrPrimitiveEdgeType>(
            d->fRandom->nextULessThan(kGrProcessorEdgeTypeCnt));
        gp = GrQuadEffect::Make(GrRandomColor(d->fRandom),
            GrTest::TestMatrix(d->fRandom),
            edgeType, *d->fCaps,
            GrTest::TestMatrix(d->fRandom),
            d->fRandom->nextBool());
    } while (nullptr == gp);
=======
GrGeometryProcessor* GrQuadEffect::TestCreate(GrProcessorTestData* d) {
    GrGeometryProcessor* gp;
    do {
        GrPrimitiveEdgeType edgeType = static_cast<GrPrimitiveEdgeType>(
                d->fRandom->nextULessThan(kGrProcessorEdgeTypeCnt));
        gp = GrQuadEffect::Create(GrRandomColor(d->fRandom),
                                  GrTest::TestMatrix(d->fRandom),
                                  edgeType, *d->fCaps,
                                  GrTest::TestMatrix(d->fRandom),
                                  d->fRandom->nextBool());
    } while (NULL == gp);
>>>>>>> miniblink49
    return gp;
}

//////////////////////////////////////////////////////////////////////////////
// Cubic
//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GrGLCubicEffect : public GrGLSLGeometryProcessor {
public:
    GrGLCubicEffect(const GrGeometryProcessor&);
=======
class GrGLCubicEffect : public GrGLGeometryProcessor {
public:
    GrGLCubicEffect(const GrGeometryProcessor&,
                    const GrBatchTracker&);
>>>>>>> miniblink49

    void onEmitCode(EmitArgs&, GrGPArgs*) override;

    static inline void GenKey(const GrGeometryProcessor&,
<<<<<<< HEAD
        const GrGLSLCaps&,
        GrProcessorKeyBuilder*);

    void setData(const GrGLSLProgramDataManager& pdman,
        const GrPrimitiveProcessor& primProc) override
    {
=======
                              const GrBatchTracker&,
                              const GrGLSLCaps&,
                              GrProcessorKeyBuilder*);

    virtual void setData(const GrGLProgramDataManager& pdman,
                         const GrPrimitiveProcessor& primProc,
                         const GrBatchTracker& bt) override {
>>>>>>> miniblink49
        const GrCubicEffect& ce = primProc.cast<GrCubicEffect>();

        if (!ce.viewMatrix().isIdentity() && !fViewMatrix.cheapEqualTo(ce.viewMatrix())) {
            fViewMatrix = ce.viewMatrix();
<<<<<<< HEAD
            float viewMatrix[3 * 3];
            GrGLSLGetMatrix<3>(viewMatrix, fViewMatrix);
=======
            GrGLfloat viewMatrix[3 * 3];
            GrGLGetMatrix<3>(viewMatrix, fViewMatrix);
>>>>>>> miniblink49
            pdman.setMatrix3f(fViewMatrixUniform, viewMatrix);
        }

        if (ce.color() != fColor) {
<<<<<<< HEAD
            float c[4];
=======
            GrGLfloat c[4];
>>>>>>> miniblink49
            GrColorToRGBAFloat(ce.color(), c);
            pdman.set4fv(fColorUniform, 1, c);
            fColor = ce.color();
        }
    }

private:
    SkMatrix fViewMatrix;
    GrColor fColor;
    GrPrimitiveEdgeType fEdgeType;
    UniformHandle fColorUniform;
    UniformHandle fViewMatrixUniform;

<<<<<<< HEAD
    typedef GrGLSLGeometryProcessor INHERITED;
};

GrGLCubicEffect::GrGLCubicEffect(const GrGeometryProcessor& processor)
    : fViewMatrix(SkMatrix::InvalidMatrix())
    , fColor(GrColor_ILLEGAL)
{
=======
    typedef GrGLGeometryProcessor INHERITED;
};

GrGLCubicEffect::GrGLCubicEffect(const GrGeometryProcessor& processor,
                                 const GrBatchTracker&)
    : fViewMatrix(SkMatrix::InvalidMatrix()), fColor(GrColor_ILLEGAL) {
>>>>>>> miniblink49
    const GrCubicEffect& ce = processor.cast<GrCubicEffect>();
    fEdgeType = ce.getEdgeType();
}

<<<<<<< HEAD
void GrGLCubicEffect::onEmitCode(EmitArgs& args, GrGPArgs* gpArgs)
{
    GrGLSLVertexBuilder* vertBuilder = args.fVertBuilder;
    const GrCubicEffect& gp = args.fGP.cast<GrCubicEffect>();
    GrGLSLVaryingHandler* varyingHandler = args.fVaryingHandler;
    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;

    // emit attributes
    varyingHandler->emitAttributes(gp);

    GrGLSLVertToFrag v(kVec4f_GrSLType);
    varyingHandler->addVarying("CubicCoeffs", &v, kHigh_GrSLPrecision);
    vertBuilder->codeAppendf("%s = %s;", v.vsOut(), gp.inCubicCoeffs()->fName);

    GrGLSLPPFragmentBuilder* fragBuilder = args.fFragBuilder;
    // Setup pass through color
    if (!gp.colorIgnored()) {
        this->setupUniformColor(fragBuilder, uniformHandler, args.fOutputColor, &fColorUniform);
    }

    // Setup position
    this->setupPosition(vertBuilder,
        uniformHandler,
        gpArgs,
        gp.inPosition()->fName,
        gp.viewMatrix(),
        &fViewMatrixUniform);

    // emit transforms with position
    this->emitTransforms(vertBuilder,
        varyingHandler,
        uniformHandler,
        gpArgs->fPositionVar,
        gp.inPosition()->fName,
        args.fTransformsIn,
        args.fTransformsOut);

    GrGLSLShaderVar edgeAlpha("edgeAlpha", kFloat_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLSLShaderVar dklmdx("dklmdx", kVec3f_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLSLShaderVar dklmdy("dklmdy", kVec3f_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLSLShaderVar dfdx("dfdx", kFloat_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLSLShaderVar dfdy("dfdy", kFloat_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLSLShaderVar gF("gF", kVec2f_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLSLShaderVar gFM("gFM", kFloat_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLSLShaderVar func("func", kFloat_GrSLType, 0, kHigh_GrSLPrecision);

    fragBuilder->declAppend(edgeAlpha);
    fragBuilder->declAppend(dklmdx);
    fragBuilder->declAppend(dklmdy);
    fragBuilder->declAppend(dfdx);
    fragBuilder->declAppend(dfdy);
    fragBuilder->declAppend(gF);
    fragBuilder->declAppend(gFM);
    fragBuilder->declAppend(func);

    switch (fEdgeType) {
    case kHairlineAA_GrProcessorEdgeType: {
        SkAssertResult(fragBuilder->enableFeature(
            GrGLSLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
        fragBuilder->codeAppendf("%s = dFdx(%s.xyz);", dklmdx.c_str(), v.fsIn());
        fragBuilder->codeAppendf("%s = dFdy(%s.xyz);", dklmdy.c_str(), v.fsIn());
        fragBuilder->codeAppendf("%s = 3.0 * %s.x * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
            dfdx.c_str(), v.fsIn(), v.fsIn(), dklmdx.c_str(), v.fsIn(),
            dklmdx.c_str(), v.fsIn(), dklmdx.c_str());
        fragBuilder->codeAppendf("%s = 3.0 * %s.x * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
            dfdy.c_str(), v.fsIn(), v.fsIn(), dklmdy.c_str(), v.fsIn(),
            dklmdy.c_str(), v.fsIn(), dklmdy.c_str());
        fragBuilder->codeAppendf("%s = vec2(%s, %s);", gF.c_str(), dfdx.c_str(), dfdy.c_str());
        fragBuilder->codeAppendf("%s = sqrt(dot(%s, %s));",
            gFM.c_str(), gF.c_str(), gF.c_str());
        fragBuilder->codeAppendf("%s = %s.x * %s.x * %s.x - %s.y * %s.z;",
            func.c_str(), v.fsIn(), v.fsIn(),
            v.fsIn(), v.fsIn(), v.fsIn());
        fragBuilder->codeAppendf("%s = abs(%s);", func.c_str(), func.c_str());
        fragBuilder->codeAppendf("%s = %s / %s;",
            edgeAlpha.c_str(), func.c_str(), gFM.c_str());
        fragBuilder->codeAppendf("%s = max(1.0 - %s, 0.0);",
            edgeAlpha.c_str(), edgeAlpha.c_str());
        // Add line below for smooth cubic ramp
        // fragBuilder->codeAppendf("%s = %s * %s * (3.0 - 2.0 * %s);",
        //                        edgeAlpha.c_str(), edgeAlpha.c_str(), edgeAlpha.c_str(),
        //                        edgeAlpha.c_str());
        break;
    }
    case kFillAA_GrProcessorEdgeType: {
        SkAssertResult(fragBuilder->enableFeature(
            GrGLSLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
        fragBuilder->codeAppendf("%s = dFdx(%s.xyz);", dklmdx.c_str(), v.fsIn());
        fragBuilder->codeAppendf("%s = dFdy(%s.xyz);", dklmdy.c_str(), v.fsIn());
        fragBuilder->codeAppendf("%s ="
                                 "3.0 * %s.x * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
            dfdx.c_str(), v.fsIn(), v.fsIn(), dklmdx.c_str(), v.fsIn(),
            dklmdx.c_str(), v.fsIn(), dklmdx.c_str());
        fragBuilder->codeAppendf("%s = 3.0 * %s.x * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
            dfdy.c_str(), v.fsIn(), v.fsIn(), dklmdy.c_str(), v.fsIn(),
            dklmdy.c_str(), v.fsIn(), dklmdy.c_str());
        fragBuilder->codeAppendf("%s = vec2(%s, %s);", gF.c_str(), dfdx.c_str(), dfdy.c_str());
        fragBuilder->codeAppendf("%s = sqrt(dot(%s, %s));",
            gFM.c_str(), gF.c_str(), gF.c_str());
        fragBuilder->codeAppendf("%s = %s.x * %s.x * %s.x - %s.y * %s.z;",
            func.c_str(),
            v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn());
        fragBuilder->codeAppendf("%s = %s / %s;",
            edgeAlpha.c_str(), func.c_str(), gFM.c_str());
        fragBuilder->codeAppendf("%s = clamp(1.0 - %s, 0.0, 1.0);",
            edgeAlpha.c_str(), edgeAlpha.c_str());
        // Add line below for smooth cubic ramp
        // fragBuilder->codeAppendf("%s = %s * %s * (3.0 - 2.0 * %s);",
        //                        edgeAlpha.c_str(), edgeAlpha.c_str(), edgeAlpha.c_str(),
        //                        edgeAlpha.c_str());
        break;
    }
    case kFillBW_GrProcessorEdgeType: {
        fragBuilder->codeAppendf("%s = %s.x * %s.x * %s.x - %s.y * %s.z;",
            edgeAlpha.c_str(), v.fsIn(), v.fsIn(),
            v.fsIn(), v.fsIn(), v.fsIn());
        fragBuilder->codeAppendf("%s = float(%s < 0.0);", edgeAlpha.c_str(), edgeAlpha.c_str());
        break;
    }
    default:
        SkFAIL("Shouldn't get here");
    }

    fragBuilder->codeAppendf("%s = vec4(%s);", args.fOutputCoverage, edgeAlpha.c_str());
}

void GrGLCubicEffect::GenKey(const GrGeometryProcessor& gp,
    const GrGLSLCaps&,
    GrProcessorKeyBuilder* b)
{
=======
void GrGLCubicEffect::onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) {
    GrGLVertexBuilder* vsBuilder = args.fPB->getVertexShaderBuilder();
    const GrCubicEffect& gp = args.fGP.cast<GrCubicEffect>();

    // emit attributes
    vsBuilder->emitAttributes(gp);

    GrGLVertToFrag v(kVec4f_GrSLType);
    args.fPB->addVarying("CubicCoeffs", &v, kHigh_GrSLPrecision);
    vsBuilder->codeAppendf("%s = %s;", v.vsOut(), gp.inCubicCoeffs()->fName);

    // Setup pass through color
    if (!gp.colorIgnored()) {
        this->setupUniformColor(args.fPB, args.fOutputColor, &fColorUniform);
    }

    // Setup position
    this->setupPosition(args.fPB, gpArgs, gp.inPosition()->fName, gp.viewMatrix(),
                        &fViewMatrixUniform);

    // emit transforms with position
    this->emitTransforms(args.fPB, gpArgs->fPositionVar, gp.inPosition()->fName, args.fTransformsIn,
                         args.fTransformsOut);

    GrGLFragmentBuilder* fsBuilder = args.fPB->getFragmentShaderBuilder();

    GrGLShaderVar edgeAlpha("edgeAlpha", kFloat_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLShaderVar dklmdx("dklmdx", kVec3f_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLShaderVar dklmdy("dklmdy", kVec3f_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLShaderVar dfdx("dfdx", kFloat_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLShaderVar dfdy("dfdy", kFloat_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLShaderVar gF("gF", kVec2f_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLShaderVar gFM("gFM", kFloat_GrSLType, 0, kHigh_GrSLPrecision);
    GrGLShaderVar func("func", kFloat_GrSLType, 0, kHigh_GrSLPrecision);

    fsBuilder->declAppend(edgeAlpha);
    fsBuilder->declAppend(dklmdx);
    fsBuilder->declAppend(dklmdy);
    fsBuilder->declAppend(dfdx);
    fsBuilder->declAppend(dfdy);
    fsBuilder->declAppend(gF);
    fsBuilder->declAppend(gFM);
    fsBuilder->declAppend(func);

    switch (fEdgeType) {
        case kHairlineAA_GrProcessorEdgeType: {
            SkAssertResult(fsBuilder->enableFeature(
                    GrGLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
            fsBuilder->codeAppendf("%s = dFdx(%s.xyz);", dklmdx.c_str(), v.fsIn());
            fsBuilder->codeAppendf("%s = dFdy(%s.xyz);", dklmdy.c_str(), v.fsIn());
            fsBuilder->codeAppendf("%s = 3.0 * %s.x * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
                                   dfdx.c_str(), v.fsIn(), v.fsIn(), dklmdx.c_str(), v.fsIn(),
                                   dklmdx.c_str(), v.fsIn(), dklmdx.c_str());
            fsBuilder->codeAppendf("%s = 3.0 * %s.x * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
                                   dfdy.c_str(), v.fsIn(), v.fsIn(), dklmdy.c_str(), v.fsIn(),
                                   dklmdy.c_str(), v.fsIn(), dklmdy.c_str());
            fsBuilder->codeAppendf("%s = vec2(%s, %s);", gF.c_str(), dfdx.c_str(), dfdy.c_str());
            fsBuilder->codeAppendf("%s = sqrt(dot(%s, %s));", gFM.c_str(), gF.c_str(), gF.c_str());
            fsBuilder->codeAppendf("%s = %s.x * %s.x * %s.x - %s.y * %s.z;",
                                   func.c_str(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppendf("%s = abs(%s);", func.c_str(), func.c_str());
            fsBuilder->codeAppendf("%s = %s / %s;",
                                   edgeAlpha.c_str(), func.c_str(), gFM.c_str());
            fsBuilder->codeAppendf("%s = max(1.0 - %s, 0.0);",
                                   edgeAlpha.c_str(), edgeAlpha.c_str());
            // Add line below for smooth cubic ramp
            // fsBuilder->codeAppendf("%s = %s * %s * (3.0 - 2.0 * %s);",
            //                        edgeAlpha.c_str(), edgeAlpha.c_str(), edgeAlpha.c_str(),
            //                        edgeAlpha.c_str());
            break;
        }
        case kFillAA_GrProcessorEdgeType: {
            SkAssertResult(fsBuilder->enableFeature(
                    GrGLFragmentShaderBuilder::kStandardDerivatives_GLSLFeature));
            fsBuilder->codeAppendf("%s = dFdx(%s.xyz);", dklmdx.c_str(), v.fsIn());
            fsBuilder->codeAppendf("%s = dFdy(%s.xyz);", dklmdy.c_str(), v.fsIn());
            fsBuilder->codeAppendf("%s ="
                                   "3.0 * %s.x * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
                                   dfdx.c_str(), v.fsIn(), v.fsIn(), dklmdx.c_str(), v.fsIn(),
                                   dklmdx.c_str(), v.fsIn(), dklmdx.c_str());
            fsBuilder->codeAppendf("%s = 3.0 * %s.x * %s.x * %s.x - %s.y * %s.z - %s.z * %s.y;",
                                   dfdy.c_str(), v.fsIn(), v.fsIn(), dklmdy.c_str(), v.fsIn(),
                                   dklmdy.c_str(), v.fsIn(), dklmdy.c_str());
            fsBuilder->codeAppendf("%s = vec2(%s, %s);", gF.c_str(), dfdx.c_str(), dfdy.c_str());
            fsBuilder->codeAppendf("%s = sqrt(dot(%s, %s));", gFM.c_str(), gF.c_str(), gF.c_str());
            fsBuilder->codeAppendf("%s = %s.x * %s.x * %s.x - %s.y * %s.z;",
                                   func.c_str(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppendf("%s = %s / %s;",
                                   edgeAlpha.c_str(), func.c_str(), gFM.c_str());
            fsBuilder->codeAppendf("%s = clamp(1.0 - %s, 0.0, 1.0);",
                                   edgeAlpha.c_str(), edgeAlpha.c_str());
            // Add line below for smooth cubic ramp
            // fsBuilder->codeAppendf("%s = %s * %s * (3.0 - 2.0 * %s);",
            //                        edgeAlpha.c_str(), edgeAlpha.c_str(), edgeAlpha.c_str(),
            //                        edgeAlpha.c_str());
            break;
        }
        case kFillBW_GrProcessorEdgeType: {
            fsBuilder->codeAppendf("%s = %s.x * %s.x * %s.x - %s.y * %s.z;",
                                   edgeAlpha.c_str(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn(), v.fsIn());
            fsBuilder->codeAppendf("%s = float(%s < 0.0);", edgeAlpha.c_str(), edgeAlpha.c_str());
            break;
        }
        default:
            SkFAIL("Shouldn't get here");
    }


    fsBuilder->codeAppendf("%s = vec4(%s);", args.fOutputCoverage, edgeAlpha.c_str());
}

void GrGLCubicEffect::GenKey(const GrGeometryProcessor& gp,
                             const GrBatchTracker& bt,
                             const GrGLSLCaps&,
                             GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    const GrCubicEffect& ce = gp.cast<GrCubicEffect>();
    uint32_t key = ce.isAntiAliased() ? (ce.isFilled() ? 0x0 : 0x1) : 0x2;
    key |= ce.color() != GrColor_ILLEGAL ? 0x4 : 0x8;
    key |= ComputePosKey(ce.viewMatrix()) << 5;
    b->add32(key);
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
GrCubicEffect::~GrCubicEffect() { }

void GrCubicEffect::getGLSLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const
{
    GrGLCubicEffect::GenKey(*this, caps, b);
}

GrGLSLPrimitiveProcessor* GrCubicEffect::createGLSLInstance(const GrGLSLCaps&) const
{
    return new GrGLCubicEffect(*this);
}

GrCubicEffect::GrCubicEffect(GrColor color, const SkMatrix& viewMatrix,
    GrPrimitiveEdgeType edgeType)
    : fColor(color)
    , fViewMatrix(viewMatrix)
    , fEdgeType(edgeType)
{
    this->initClassID<GrCubicEffect>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
        kHigh_GrSLPrecision));
    fInCubicCoeffs = &this->addVertexAttrib(Attribute("inCubicCoeffs",
        kVec4f_GrVertexAttribType));
=======
GrCubicEffect::~GrCubicEffect() {}

void GrCubicEffect::getGLProcessorKey(const GrBatchTracker& bt,
                                      const GrGLSLCaps& caps,
                                      GrProcessorKeyBuilder* b) const {
    GrGLCubicEffect::GenKey(*this, bt, caps, b);
}

GrGLPrimitiveProcessor* GrCubicEffect::createGLInstance(const GrBatchTracker& bt,
                                                        const GrGLSLCaps&) const {
    return SkNEW_ARGS(GrGLCubicEffect, (*this, bt));
}

GrCubicEffect::GrCubicEffect(GrColor color, const SkMatrix& viewMatrix,
                             GrPrimitiveEdgeType edgeType)
    : fColor(color)
    , fViewMatrix(viewMatrix)
    , fEdgeType(edgeType) {
    this->initClassID<GrCubicEffect>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType,
                                                   kHigh_GrSLPrecision));
    fInCubicCoeffs = &this->addVertexAttrib(Attribute("inCubicCoeffs",
                                                        kVec4f_GrVertexAttribType));
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

GR_DEFINE_GEOMETRY_PROCESSOR_TEST(GrCubicEffect);

<<<<<<< HEAD
sk_sp<GrGeometryProcessor> GrCubicEffect::TestCreate(GrProcessorTestData* d)
{
    sk_sp<GrGeometryProcessor> gp;
    do {
        GrPrimitiveEdgeType edgeType = static_cast<GrPrimitiveEdgeType>(
            d->fRandom->nextULessThan(kGrProcessorEdgeTypeCnt));
        gp = GrCubicEffect::Make(GrRandomColor(d->fRandom),
            GrTest::TestMatrix(d->fRandom), edgeType, *d->fCaps);
    } while (nullptr == gp);
    return gp;
}
=======
GrGeometryProcessor* GrCubicEffect::TestCreate(GrProcessorTestData* d) {
    GrGeometryProcessor* gp;
    do {
        GrPrimitiveEdgeType edgeType =
                static_cast<GrPrimitiveEdgeType>(
                        d->fRandom->nextULessThan(kGrProcessorEdgeTypeCnt));
        gp = GrCubicEffect::Create(GrRandomColor(d->fRandom),
                                   GrTest::TestMatrix(d->fRandom), edgeType, *d->fCaps);
    } while (NULL == gp);
    return gp;
}

>>>>>>> miniblink49
