<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkTwoPointConicalGradient_gpu.h"

#include "SkTwoPointConicalGradient.h"

#if SK_SUPPORT_GPU
<<<<<<< HEAD
#include "GrCoordTransform.h"
#include "GrInvariantOutput.h"
#include "GrPaint.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
// For brevity
typedef GrGLSLProgramDataManager::UniformHandle UniformHandle;
=======
#include "GrPaint.h"
#include "gl/builders/GrGLProgramBuilder.h"
// For brevity
typedef GrGLProgramDataManager::UniformHandle UniformHandle;
>>>>>>> miniblink49

static const SkScalar kErrorTol = 0.00001f;
static const SkScalar kEdgeErrorTol = 5.f * kErrorTol;

/**
 * We have three general cases for 2pt conical gradients. First we always assume that
 * the start radius <= end radius. Our first case (kInside_) is when the start circle
 * is completely enclosed by the end circle. The second case (kOutside_) is the case
 * when the start circle is either completely outside the end circle or the circles
 * overlap. The final case (kEdge_) is when the start circle is inside the end one,
 * but the two are just barely touching at 1 point along their edges.
 */
enum ConicalType {
    kInside_ConicalType,
    kOutside_ConicalType,
    kEdge_ConicalType,
};

//////////////////////////////////////////////////////////////////////////////

static void set_matrix_edge_conical(const SkTwoPointConicalGradient& shader,
<<<<<<< HEAD
    SkMatrix* invLMatrix)
{
=======
                                    SkMatrix* invLMatrix) {
>>>>>>> miniblink49
    // Inverse of the current local matrix is passed in then,
    // translate to center1, rotate so center2 is on x axis.
    const SkPoint& center1 = shader.getStartCenter();
    const SkPoint& center2 = shader.getEndCenter();

    invLMatrix->postTranslate(-center1.fX, -center1.fY);

    SkPoint diff = center2 - center1;
    SkScalar diffLen = diff.length();
    if (0 != diffLen) {
        SkScalar invDiffLen = SkScalarInvert(diffLen);
        SkMatrix rot;
        rot.setSinCos(-SkScalarMul(invDiffLen, diff.fY),
<<<<<<< HEAD
            SkScalarMul(invDiffLen, diff.fX));
=======
                       SkScalarMul(invDiffLen, diff.fX));
>>>>>>> miniblink49
        invLMatrix->postConcat(rot);
    }
}

class Edge2PtConicalEffect : public GrGradientEffect {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm)
    {
        return sk_sp<GrFragmentProcessor>(new Edge2PtConicalEffect(ctx, shader, matrix, tm));
    }

    virtual ~Edge2PtConicalEffect() { }

    const char* name() const override
    {
        return "Two-Point Conical Gradient Edge Touching";
    }

=======

    static GrFragmentProcessor* Create(GrContext* ctx,
                                       GrProcessorDataManager* procDataManager,
                                       const SkTwoPointConicalGradient& shader,
                                       const SkMatrix& matrix,
                                       SkShader::TileMode tm) {
        return SkNEW_ARGS(Edge2PtConicalEffect, (ctx, procDataManager, shader, matrix, tm));
    }

    virtual ~Edge2PtConicalEffect() {}

    const char* name() const override {
        return "Two-Point Conical Gradient Edge Touching";
    }

    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

>>>>>>> miniblink49
    // The radial gradient parameters can collapse to a linear (instead of quadratic) equation.
    SkScalar center() const { return fCenterX1; }
    SkScalar diffRadius() const { return fDiffRadius; }
    SkScalar radius() const { return fRadius0; }

private:
<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    bool onIsEqual(const GrFragmentProcessor& sBase) const override
    {
        const Edge2PtConicalEffect& s = sBase.cast<Edge2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) && this->fCenterX1 == s.fCenterX1 && this->fRadius0 == s.fRadius0 && this->fDiffRadius == s.fDiffRadius);
    }

    Edge2PtConicalEffect(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm)
        : INHERITED(ctx, shader, matrix, tm)
        , fCenterX1(shader.getCenterX1())
        , fRadius0(shader.getStartRadius())
        , fDiffRadius(shader.getDiffRadius())
    {
=======
    bool onIsEqual(const GrFragmentProcessor& sBase) const override {
        const Edge2PtConicalEffect& s = sBase.cast<Edge2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) &&
                this->fCenterX1 == s.fCenterX1 &&
                this->fRadius0 == s.fRadius0 &&
                this->fDiffRadius == s.fDiffRadius);
    }

    Edge2PtConicalEffect(GrContext* ctx,
                         GrProcessorDataManager* procDataManager,
                         const SkTwoPointConicalGradient& shader,
                         const SkMatrix& matrix,
                         SkShader::TileMode tm)
        : INHERITED(ctx, procDataManager, shader, matrix, tm),
        fCenterX1(shader.getCenterX1()),
        fRadius0(shader.getStartRadius()),
        fDiffRadius(shader.getDiffRadius()){
>>>>>>> miniblink49
        this->initClassID<Edge2PtConicalEffect>();
        // We should only be calling this shader if we are degenerate case with touching circles
        // When deciding if we are in edge case, we scaled by the end radius for cases when the
        // start radius was close to zero, otherwise we scaled by the start radius.  In addition
        // Our test for the edge case in set_matrix_circle_conical has a higher tolerance so we
        // need the sqrt value below
<<<<<<< HEAD
        SkASSERT(SkScalarAbs(SkScalarAbs(fDiffRadius) - fCenterX1) < (fRadius0 < kErrorTol ? shader.getEndRadius() * kEdgeErrorTol : fRadius0 * sqrt(kEdgeErrorTol)));
=======
        SkASSERT(SkScalarAbs(SkScalarAbs(fDiffRadius) - fCenterX1) <
                 (fRadius0 < kErrorTol ? shader.getEndRadius() * kEdgeErrorTol :
                                         fRadius0 * sqrt(kEdgeErrorTol)));
>>>>>>> miniblink49

        // We pass the linear part of the quadratic as a varying.
        //    float b = -2.0 * (fCenterX1 * x + fRadius0 * fDiffRadius * z)
        fBTransform = this->getCoordTransform();
        SkMatrix& bMatrix = *fBTransform.accessMatrix();
        SkScalar r0dr = SkScalarMul(fRadius0, fDiffRadius);
<<<<<<< HEAD
        bMatrix[SkMatrix::kMScaleX] = -2 * (SkScalarMul(fCenterX1, bMatrix[SkMatrix::kMScaleX]) + SkScalarMul(r0dr, bMatrix[SkMatrix::kMPersp0]));
        bMatrix[SkMatrix::kMSkewX] = -2 * (SkScalarMul(fCenterX1, bMatrix[SkMatrix::kMSkewX]) + SkScalarMul(r0dr, bMatrix[SkMatrix::kMPersp1]));
        bMatrix[SkMatrix::kMTransX] = -2 * (SkScalarMul(fCenterX1, bMatrix[SkMatrix::kMTransX]) + SkScalarMul(r0dr, bMatrix[SkMatrix::kMPersp2]));
=======
        bMatrix[SkMatrix::kMScaleX] = -2 * (SkScalarMul(fCenterX1, bMatrix[SkMatrix::kMScaleX]) +
                                            SkScalarMul(r0dr, bMatrix[SkMatrix::kMPersp0]));
        bMatrix[SkMatrix::kMSkewX] = -2 * (SkScalarMul(fCenterX1, bMatrix[SkMatrix::kMSkewX]) +
                                           SkScalarMul(r0dr, bMatrix[SkMatrix::kMPersp1]));
        bMatrix[SkMatrix::kMTransX] = -2 * (SkScalarMul(fCenterX1, bMatrix[SkMatrix::kMTransX]) +
                                            SkScalarMul(r0dr, bMatrix[SkMatrix::kMPersp2]));
>>>>>>> miniblink49
        this->addCoordTransform(&fBTransform);
    }

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    // @{
    // Cache of values - these can change arbitrarily, EXCEPT
    // we shouldn't change between degenerate and non-degenerate?!

    GrCoordTransform fBTransform;
<<<<<<< HEAD
    SkScalar fCenterX1;
    SkScalar fRadius0;
    SkScalar fDiffRadius;
=======
    SkScalar         fCenterX1;
    SkScalar         fRadius0;
    SkScalar         fDiffRadius;
>>>>>>> miniblink49

    // @}

    typedef GrGradientEffect INHERITED;
};

class GLEdge2PtConicalEffect : public GrGLGradientEffect {
public:
    GLEdge2PtConicalEffect(const GrProcessor&);
    virtual ~GLEdge2PtConicalEffect() { }

<<<<<<< HEAD
    virtual void emitCode(EmitArgs&) override;
=======
    virtual void emitCode(GrGLFPBuilder*,
                          const GrFragmentProcessor&,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;
    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;
>>>>>>> miniblink49

    static void GenKey(const GrProcessor&, const GrGLSLCaps& caps, GrProcessorKeyBuilder* b);

protected:
<<<<<<< HEAD
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

=======
>>>>>>> miniblink49
    UniformHandle fParamUni;

    const char* fVSVaryingName;
    const char* fFSVaryingName;

    // @{
    /// Values last uploaded as uniforms

    SkScalar fCachedRadius;
    SkScalar fCachedDiffRadius;

    // @}

private:
    typedef GrGLGradientEffect INHERITED;
<<<<<<< HEAD
};

void Edge2PtConicalEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GLEdge2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* Edge2PtConicalEffect::onCreateGLSLInstance() const
{
    return new GLEdge2PtConicalEffect(*this);
=======

};

void Edge2PtConicalEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                             GrProcessorKeyBuilder* b) const {
    GLEdge2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* Edge2PtConicalEffect::createGLInstance() const {
    return SkNEW_ARGS(GLEdge2PtConicalEffect, (*this));
>>>>>>> miniblink49
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(Edge2PtConicalEffect);

/*
 * All Two point conical gradient test create functions may occasionally create edge case shaders
 */
<<<<<<< HEAD
sk_sp<GrFragmentProcessor> Edge2PtConicalEffect::TestCreate(GrProcessorTestData* d)
{
    SkPoint center1 = { d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1() };
=======
GrFragmentProcessor* Edge2PtConicalEffect::TestCreate(GrProcessorTestData* d) {
    SkPoint center1 = {d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1()};
>>>>>>> miniblink49
    SkScalar radius1 = d->fRandom->nextUScalar1();
    SkPoint center2;
    SkScalar radius2;
    do {
        center2.set(d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1());
        // If the circles are identical the factory will give us an empty shader.
        // This will happen if we pick identical centers
    } while (center1 == center2);

    // Below makes sure that circle one is contained within circle two
    // and both circles are touching on an edge
    SkPoint diff = center2 - center1;
    SkScalar diffLen = diff.length();
    radius2 = radius1 + diffLen;

    SkColor colors[kMaxRandomGradientColors];
    SkScalar stopsArray[kMaxRandomGradientColors];
    SkScalar* stops = stopsArray;
    SkShader::TileMode tm;
    int colorCount = RandomGradientParams(d->fRandom, colors, &stops, &tm);
<<<<<<< HEAD
    auto shader = SkGradientShader::MakeTwoPointConical(center1, radius1, center2, radius2,
        colors, stops, colorCount, tm);
    sk_sp<GrFragmentProcessor> fp = shader->asFragmentProcessor(d->fContext,
        GrTest::TestMatrix(d->fRandom), NULL, kNone_SkFilterQuality,
        SkSourceGammaTreatment::kRespect);
    GrAlwaysAssert(fp);
=======
    SkAutoTUnref<SkShader> shader(SkGradientShader::CreateTwoPointConical(center1, radius1,
                                                                          center2, radius2,
                                                                          colors, stops, colorCount,
                                                                          tm));
    SkPaint paint;
    GrFragmentProcessor* fp;
    GrColor paintColor;
    SkAssertResult(shader->asFragmentProcessor(d->fContext, paint,
                                               GrTest::TestMatrix(d->fRandom), NULL,
                                               &paintColor, d->fProcDataManager, &fp));
>>>>>>> miniblink49
    return fp;
}

GLEdge2PtConicalEffect::GLEdge2PtConicalEffect(const GrProcessor&)
<<<<<<< HEAD
    : fVSVaryingName(nullptr)
    , fFSVaryingName(nullptr)
    , fCachedRadius(-SK_ScalarMax)
    , fCachedDiffRadius(-SK_ScalarMax)
{
}

void GLEdge2PtConicalEffect::emitCode(EmitArgs& args)
{
    const Edge2PtConicalEffect& ge = args.fFp.cast<Edge2PtConicalEffect>();
    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    this->emitUniforms(uniformHandler, ge);
    fParamUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec3f_GrSLType, kDefault_GrSLPrecision,
        "Conical2FSParams");
=======
    : fVSVaryingName(NULL)
    , fFSVaryingName(NULL)
    , fCachedRadius(-SK_ScalarMax)
    , fCachedDiffRadius(-SK_ScalarMax) {}

void GLEdge2PtConicalEffect::emitCode(GrGLFPBuilder* builder,
                                      const GrFragmentProcessor& fp,
                                      const char* outputColor,
                                      const char* inputColor,
                                      const TransformedCoordsArray& coords,
                                      const TextureSamplerArray& samplers) {
    const Edge2PtConicalEffect& ge = fp.cast<Edge2PtConicalEffect>();
    this->emitUniforms(builder, ge);
    fParamUni = builder->addUniformArray(GrGLProgramBuilder::kFragment_Visibility,
                                         kFloat_GrSLType, kDefault_GrSLPrecision,
                                         "Conical2FSParams", 3);
>>>>>>> miniblink49

    SkString cName("c");
    SkString tName("t");
    SkString p0; // start radius
    SkString p1; // start radius squared
    SkString p2; // difference in radii (r1 - r0)

<<<<<<< HEAD
    p0.appendf("%s.x", uniformHandler->getUniformVariable(fParamUni).getName().c_str());
    p1.appendf("%s.y", uniformHandler->getUniformVariable(fParamUni).getName().c_str());
    p2.appendf("%s.z", uniformHandler->getUniformVariable(fParamUni).getName().c_str());

    // We interpolate the linear component in coords[1].
    SkASSERT(args.fCoords[0].getType() == args.fCoords[1].getType());
    const char* coords2D;
    SkString bVar;
    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    if (kVec3f_GrSLType == args.fCoords[0].getType()) {
        fragBuilder->codeAppendf("\tvec3 interpolants = vec3(%s.xy / %s.z, %s.x / %s.z);\n",
            args.fCoords[0].c_str(), args.fCoords[0].c_str(),
            args.fCoords[1].c_str(), args.fCoords[1].c_str());
        coords2D = "interpolants.xy";
        bVar = "interpolants.z";
    } else {
        coords2D = args.fCoords[0].c_str();
        bVar.printf("%s.x", args.fCoords[1].c_str());
=======
    builder->getUniformVariable(fParamUni).appendArrayAccess(0, &p0);
    builder->getUniformVariable(fParamUni).appendArrayAccess(1, &p1);
    builder->getUniformVariable(fParamUni).appendArrayAccess(2, &p2);

    // We interpolate the linear component in coords[1].
    SkASSERT(coords[0].getType() == coords[1].getType());
    const char* coords2D;
    SkString bVar;
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    if (kVec3f_GrSLType == coords[0].getType()) {
        fsBuilder->codeAppendf("\tvec3 interpolants = vec3(%s.xy / %s.z, %s.x / %s.z);\n",
                               coords[0].c_str(), coords[0].c_str(), coords[1].c_str(),
                               coords[1].c_str());
        coords2D = "interpolants.xy";
        bVar = "interpolants.z";
    } else {
        coords2D = coords[0].c_str();
        bVar.printf("%s.x", coords[1].c_str());
>>>>>>> miniblink49
    }

    // output will default to transparent black (we simply won't write anything
    // else to it if invalid, instead of discarding or returning prematurely)
<<<<<<< HEAD
    fragBuilder->codeAppendf("\t%s = vec4(0.0,0.0,0.0,0.0);\n", args.fOutputColor);

    // c = (x^2)+(y^2) - params[1]
    fragBuilder->codeAppendf("\tfloat %s = dot(%s, %s) - %s;\n",
        cName.c_str(), coords2D, coords2D, p1.c_str());

    // linear case: t = -c/b
    fragBuilder->codeAppendf("\tfloat %s = -(%s / %s);\n", tName.c_str(),
        cName.c_str(), bVar.c_str());

    // if r(t) > 0, then t will be the x coordinate
    fragBuilder->codeAppendf("\tif (%s * %s + %s > 0.0) {\n", tName.c_str(),
        p2.c_str(), p0.c_str());
    fragBuilder->codeAppend("\t");
    this->emitColor(fragBuilder,
        uniformHandler,
        args.fGLSLCaps,
        ge,
        tName.c_str(),
        args.fOutputColor,
        args.fInputColor,
        args.fTexSamplers);
    fragBuilder->codeAppend("\t}\n");
}

void GLEdge2PtConicalEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& processor)
{
    INHERITED::onSetData(pdman, processor);
=======
    fsBuilder->codeAppendf("\t%s = vec4(0.0,0.0,0.0,0.0);\n", outputColor);

    // c = (x^2)+(y^2) - params[1]
    fsBuilder->codeAppendf("\tfloat %s = dot(%s, %s) - %s;\n",
                           cName.c_str(), coords2D, coords2D, p1.c_str());

    // linear case: t = -c/b
    fsBuilder->codeAppendf("\tfloat %s = -(%s / %s);\n", tName.c_str(),
                           cName.c_str(), bVar.c_str());

    // if r(t) > 0, then t will be the x coordinate
    fsBuilder->codeAppendf("\tif (%s * %s + %s > 0.0) {\n", tName.c_str(),
                           p2.c_str(), p0.c_str());
    fsBuilder->codeAppend("\t");
    this->emitColor(builder, ge, tName.c_str(), outputColor, inputColor, samplers);
    fsBuilder->codeAppend("\t}\n");
}

void GLEdge2PtConicalEffect::setData(const GrGLProgramDataManager& pdman,
                                     const GrProcessor& processor) {
    INHERITED::setData(pdman, processor);
>>>>>>> miniblink49
    const Edge2PtConicalEffect& data = processor.cast<Edge2PtConicalEffect>();
    SkScalar radius0 = data.radius();
    SkScalar diffRadius = data.diffRadius();

<<<<<<< HEAD
    if (fCachedRadius != radius0 || fCachedDiffRadius != diffRadius) {

        pdman.set3f(fParamUni, SkScalarToFloat(radius0),
            SkScalarToFloat(SkScalarMul(radius0, radius0)), SkScalarToFloat(diffRadius));
=======
    if (fCachedRadius != radius0 ||
        fCachedDiffRadius != diffRadius) {

        float values[3] = {
            SkScalarToFloat(radius0),
            SkScalarToFloat(SkScalarMul(radius0, radius0)),
            SkScalarToFloat(diffRadius)
        };

        pdman.set1fv(fParamUni, 3, values);
>>>>>>> miniblink49
        fCachedRadius = radius0;
        fCachedDiffRadius = diffRadius;
    }
}

void GLEdge2PtConicalEffect::GenKey(const GrProcessor& processor,
<<<<<<< HEAD
    const GrGLSLCaps&, GrProcessorKeyBuilder* b)
{
=======
                                    const GrGLSLCaps&, GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    b->add32(GenBaseGradientKey(processor));
}

//////////////////////////////////////////////////////////////////////////////
// Focal Conical Gradients
//////////////////////////////////////////////////////////////////////////////

static ConicalType set_matrix_focal_conical(const SkTwoPointConicalGradient& shader,
<<<<<<< HEAD
    SkMatrix* invLMatrix, SkScalar* focalX)
{
=======
                                            SkMatrix* invLMatrix, SkScalar* focalX) {
>>>>>>> miniblink49
    // Inverse of the current local matrix is passed in then,
    // translate, scale, and rotate such that endCircle is unit circle on x-axis,
    // and focal point is at the origin.
    ConicalType conicalType;
    const SkPoint& focal = shader.getStartCenter();
    const SkPoint& centerEnd = shader.getEndCenter();
    SkScalar radius = shader.getEndRadius();
    SkScalar invRadius = 1.f / radius;

    SkMatrix matrix;

    matrix.setTranslate(-centerEnd.fX, -centerEnd.fY);
    matrix.postScale(invRadius, invRadius);

    SkPoint focalTrans;
    matrix.mapPoints(&focalTrans, &focal, 1);
    *focalX = focalTrans.length();

    if (0.f != *focalX) {
        SkScalar invFocalX = SkScalarInvert(*focalX);
        SkMatrix rot;
        rot.setSinCos(-SkScalarMul(invFocalX, focalTrans.fY),
<<<<<<< HEAD
            SkScalarMul(invFocalX, focalTrans.fX));
=======
                      SkScalarMul(invFocalX, focalTrans.fX));
>>>>>>> miniblink49
        matrix.postConcat(rot);
    }

    matrix.postTranslate(-(*focalX), 0.f);

    // If the focal point is touching the edge of the circle it will
    // cause a degenerate case that must be handled separately
    // kEdgeErrorTol = 5 * kErrorTol was picked after manual testing the
    // stability trade off versus the linear approx used in the Edge Shader
    if (SkScalarAbs(1.f - (*focalX)) < kEdgeErrorTol) {
        return kEdge_ConicalType;
    }

    // Scale factor 1 / (1 - focalX * focalX)
    SkScalar oneMinusF2 = 1.f - SkScalarMul(*focalX, *focalX);
    SkScalar s = SkScalarInvert(oneMinusF2);

<<<<<<< HEAD
=======

>>>>>>> miniblink49
    if (s >= 0.f) {
        conicalType = kInside_ConicalType;
        matrix.postScale(s, s * SkScalarSqrt(oneMinusF2));
    } else {
        conicalType = kOutside_ConicalType;
        matrix.postScale(s, s);
    }

    invLMatrix->postConcat(matrix);

    return conicalType;
}

//////////////////////////////////////////////////////////////////////////////

class FocalOutside2PtConicalEffect : public GrGradientEffect {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm,
        SkScalar focalX)
    {
        return sk_sp<GrFragmentProcessor>(
            new FocalOutside2PtConicalEffect(ctx, shader, matrix, tm, focalX));
=======

    static GrFragmentProcessor* Create(GrContext* ctx,
                                       GrProcessorDataManager* procDataManager,
                                       const SkTwoPointConicalGradient& shader,
                                       const SkMatrix& matrix,
                                       SkShader::TileMode tm,
                                       SkScalar focalX) {
        return SkNEW_ARGS(FocalOutside2PtConicalEffect, (ctx, procDataManager, shader, matrix, tm,
                                                         focalX));
>>>>>>> miniblink49
    }

    virtual ~FocalOutside2PtConicalEffect() { }

<<<<<<< HEAD
    const char* name() const override
    {
        return "Two-Point Conical Gradient Focal Outside";
    }

=======
    const char* name() const override {
        return "Two-Point Conical Gradient Focal Outside";
    }

    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

>>>>>>> miniblink49
    bool isFlipped() const { return fIsFlipped; }
    SkScalar focal() const { return fFocalX; }

private:
<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    bool onIsEqual(const GrFragmentProcessor& sBase) const override
    {
        const FocalOutside2PtConicalEffect& s = sBase.cast<FocalOutside2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) && this->fFocalX == s.fFocalX && this->fIsFlipped == s.fIsFlipped);
    }

    FocalOutside2PtConicalEffect(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm,
        SkScalar focalX)
        : INHERITED(ctx, shader, matrix, tm)
        , fFocalX(focalX)
        , fIsFlipped(shader.isFlippedGrad())
    {
=======
    bool onIsEqual(const GrFragmentProcessor& sBase) const override {
        const FocalOutside2PtConicalEffect& s = sBase.cast<FocalOutside2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) &&
                this->fFocalX == s.fFocalX &&
                this->fIsFlipped == s.fIsFlipped);
    }

    FocalOutside2PtConicalEffect(GrContext* ctx,
                                 GrProcessorDataManager* procDataManager,
                                 const SkTwoPointConicalGradient& shader,
                                 const SkMatrix& matrix,
                                 SkShader::TileMode tm,
                                 SkScalar focalX)
    : INHERITED(ctx, procDataManager, shader, matrix, tm)
    , fFocalX(focalX)
    , fIsFlipped(shader.isFlippedGrad()) {
>>>>>>> miniblink49
        this->initClassID<FocalOutside2PtConicalEffect>();
    }

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

<<<<<<< HEAD
    SkScalar fFocalX;
    bool fIsFlipped;
=======
    SkScalar         fFocalX;
    bool             fIsFlipped;
>>>>>>> miniblink49

    typedef GrGradientEffect INHERITED;
};

class GLFocalOutside2PtConicalEffect : public GrGLGradientEffect {
public:
    GLFocalOutside2PtConicalEffect(const GrProcessor&);
    virtual ~GLFocalOutside2PtConicalEffect() { }

<<<<<<< HEAD
    virtual void emitCode(EmitArgs&) override;
=======
    virtual void emitCode(GrGLFPBuilder*,
                          const GrFragmentProcessor&,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;
    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;
>>>>>>> miniblink49

    static void GenKey(const GrProcessor&, const GrGLSLCaps& caps, GrProcessorKeyBuilder* b);

protected:
<<<<<<< HEAD
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

=======
>>>>>>> miniblink49
    UniformHandle fParamUni;

    const char* fVSVaryingName;
    const char* fFSVaryingName;

    bool fIsFlipped;

    // @{
    /// Values last uploaded as uniforms

    SkScalar fCachedFocal;

    // @}

private:
    typedef GrGLGradientEffect INHERITED;
<<<<<<< HEAD
};

void FocalOutside2PtConicalEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GLFocalOutside2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* FocalOutside2PtConicalEffect::onCreateGLSLInstance() const
{
    return new GLFocalOutside2PtConicalEffect(*this);
=======

};

void FocalOutside2PtConicalEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                                     GrProcessorKeyBuilder* b) const {
    GLFocalOutside2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* FocalOutside2PtConicalEffect::createGLInstance() const {
    return SkNEW_ARGS(GLFocalOutside2PtConicalEffect, (*this));
>>>>>>> miniblink49
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(FocalOutside2PtConicalEffect);

/*
 * All Two point conical gradient test create functions may occasionally create edge case shaders
 */
<<<<<<< HEAD
sk_sp<GrFragmentProcessor> FocalOutside2PtConicalEffect::TestCreate(GrProcessorTestData* d)
{
    SkPoint center1 = { d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1() };
=======
GrFragmentProcessor* FocalOutside2PtConicalEffect::TestCreate(GrProcessorTestData* d) {
    SkPoint center1 = {d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1()};
>>>>>>> miniblink49
    SkScalar radius1 = 0.f;
    SkPoint center2;
    SkScalar radius2;
    do {
        center2.set(d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1());
        // Need to make sure the centers are not the same or else focal point will be inside
    } while (center1 == center2);
<<<<<<< HEAD
    SkPoint diff = center2 - center1;
    SkScalar diffLen = diff.length();
    // Below makes sure that the focal point is not contained within circle two
    radius2 = d->fRandom->nextRangeF(0.f, diffLen);
=======
        SkPoint diff = center2 - center1;
        SkScalar diffLen = diff.length();
        // Below makes sure that the focal point is not contained within circle two
        radius2 = d->fRandom->nextRangeF(0.f, diffLen);
>>>>>>> miniblink49

    SkColor colors[kMaxRandomGradientColors];
    SkScalar stopsArray[kMaxRandomGradientColors];
    SkScalar* stops = stopsArray;
    SkShader::TileMode tm;
    int colorCount = RandomGradientParams(d->fRandom, colors, &stops, &tm);
<<<<<<< HEAD
    auto shader = SkGradientShader::MakeTwoPointConical(center1, radius1, center2, radius2,
        colors, stops, colorCount, tm);
    sk_sp<GrFragmentProcessor> fp = shader->asFragmentProcessor(d->fContext,
        GrTest::TestMatrix(d->fRandom), NULL, kNone_SkFilterQuality,
        SkSourceGammaTreatment::kRespect);
    GrAlwaysAssert(fp);
    return fp;
}

GLFocalOutside2PtConicalEffect::GLFocalOutside2PtConicalEffect(const GrProcessor& processor)
    : fVSVaryingName(nullptr)
    , fFSVaryingName(nullptr)
    , fCachedFocal(SK_ScalarMax)
{
=======
    SkAutoTUnref<SkShader> shader(SkGradientShader::CreateTwoPointConical(center1, radius1,
                                                                          center2, radius2,
                                                                          colors, stops, colorCount,
                                                                          tm));
    SkPaint paint;
    GrFragmentProcessor* effect;
    GrColor paintColor;
    GrPaint grPaint;
    SkAssertResult(shader->asFragmentProcessor(d->fContext, paint,
                                               GrTest::TestMatrix(d->fRandom), NULL,
                                               &paintColor, d->fProcDataManager,
                                               &effect));
    return effect;
}

GLFocalOutside2PtConicalEffect::GLFocalOutside2PtConicalEffect(const GrProcessor& processor)
    : fVSVaryingName(NULL)
    , fFSVaryingName(NULL)
    , fCachedFocal(SK_ScalarMax) {
>>>>>>> miniblink49
    const FocalOutside2PtConicalEffect& data = processor.cast<FocalOutside2PtConicalEffect>();
    fIsFlipped = data.isFlipped();
}

<<<<<<< HEAD
void GLFocalOutside2PtConicalEffect::emitCode(EmitArgs& args)
{
    const FocalOutside2PtConicalEffect& ge = args.fFp.cast<FocalOutside2PtConicalEffect>();
    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    this->emitUniforms(uniformHandler, ge);
    fParamUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec2f_GrSLType, kDefault_GrSLPrecision,
        "Conical2FSParams");
=======
void GLFocalOutside2PtConicalEffect::emitCode(GrGLFPBuilder* builder,
                                              const GrFragmentProcessor& fp,
                                              const char* outputColor,
                                              const char* inputColor,
                                              const TransformedCoordsArray& coords,
                                              const TextureSamplerArray& samplers) {
    const FocalOutside2PtConicalEffect& ge = fp.cast<FocalOutside2PtConicalEffect>();
    this->emitUniforms(builder, ge);
    fParamUni = builder->addUniformArray(GrGLProgramBuilder::kFragment_Visibility,
                                         kFloat_GrSLType, kDefault_GrSLPrecision,
                                         "Conical2FSParams", 2);
>>>>>>> miniblink49
    SkString tName("t");
    SkString p0; // focalX
    SkString p1; // 1 - focalX * focalX

<<<<<<< HEAD
    p0.appendf("%s.x", uniformHandler->getUniformVariable(fParamUni).getName().c_str());
    p1.appendf("%s.y", uniformHandler->getUniformVariable(fParamUni).getName().c_str());

    // if we have a vec3 from being in perspective, convert it to a vec2 first
    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    SkString coords2DString = fragBuilder->ensureFSCoords2D(args.fCoords, 0);
=======
    builder->getUniformVariable(fParamUni).appendArrayAccess(0, &p0);
    builder->getUniformVariable(fParamUni).appendArrayAccess(1, &p1);

    // if we have a vec3 from being in perspective, convert it to a vec2 first
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    SkString coords2DString = fsBuilder->ensureFSCoords2D(coords, 0);
>>>>>>> miniblink49
    const char* coords2D = coords2DString.c_str();

    // t = p.x * focal.x +/- sqrt(p.x^2 + (1 - focal.x^2) * p.y^2)

    // output will default to transparent black (we simply won't write anything
    // else to it if invalid, instead of discarding or returning prematurely)
<<<<<<< HEAD
    fragBuilder->codeAppendf("\t%s = vec4(0.0,0.0,0.0,0.0);\n", args.fOutputColor);

    fragBuilder->codeAppendf("\tfloat xs = %s.x * %s.x;\n", coords2D, coords2D);
    fragBuilder->codeAppendf("\tfloat ys = %s.y * %s.y;\n", coords2D, coords2D);
    fragBuilder->codeAppendf("\tfloat d = xs + %s * ys;\n", p1.c_str());
=======
    fsBuilder->codeAppendf("\t%s = vec4(0.0,0.0,0.0,0.0);\n", outputColor);

    fsBuilder->codeAppendf("\tfloat xs = %s.x * %s.x;\n", coords2D, coords2D);
    fsBuilder->codeAppendf("\tfloat ys = %s.y * %s.y;\n", coords2D, coords2D);
    fsBuilder->codeAppendf("\tfloat d = xs + %s * ys;\n", p1.c_str());
>>>>>>> miniblink49

    // Must check to see if we flipped the circle order (to make sure start radius < end radius)
    // If so we must also flip sign on sqrt
    if (!fIsFlipped) {
<<<<<<< HEAD
        fragBuilder->codeAppendf("\tfloat %s = %s.x * %s  + sqrt(d);\n", tName.c_str(),
            coords2D, p0.c_str());
    } else {
        fragBuilder->codeAppendf("\tfloat %s = %s.x * %s  - sqrt(d);\n", tName.c_str(),
            coords2D, p0.c_str());
    }

    fragBuilder->codeAppendf("\tif (%s >= 0.0 && d >= 0.0) {\n", tName.c_str());
    fragBuilder->codeAppend("\t\t");
    this->emitColor(fragBuilder,
        uniformHandler,
        args.fGLSLCaps,
        ge,
        tName.c_str(),
        args.fOutputColor,
        args.fInputColor,
        args.fTexSamplers);
    fragBuilder->codeAppend("\t}\n");
}

void GLFocalOutside2PtConicalEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& processor)
{
    INHERITED::onSetData(pdman, processor);
=======
        fsBuilder->codeAppendf("\tfloat %s = %s.x * %s  + sqrt(d);\n", tName.c_str(),
                               coords2D, p0.c_str());
    } else {
        fsBuilder->codeAppendf("\tfloat %s = %s.x * %s  - sqrt(d);\n", tName.c_str(),
                               coords2D, p0.c_str());
    }

    fsBuilder->codeAppendf("\tif (%s >= 0.0 && d >= 0.0) {\n", tName.c_str());
    fsBuilder->codeAppend("\t\t");
    this->emitColor(builder, ge, tName.c_str(), outputColor, inputColor, samplers);
    fsBuilder->codeAppend("\t}\n");
}

void GLFocalOutside2PtConicalEffect::setData(const GrGLProgramDataManager& pdman,
                                             const GrProcessor& processor) {
    INHERITED::setData(pdman, processor);
>>>>>>> miniblink49
    const FocalOutside2PtConicalEffect& data = processor.cast<FocalOutside2PtConicalEffect>();
    SkASSERT(data.isFlipped() == fIsFlipped);
    SkScalar focal = data.focal();

    if (fCachedFocal != focal) {
        SkScalar oneMinus2F = 1.f - SkScalarMul(focal, focal);

<<<<<<< HEAD
        pdman.set2f(fParamUni, SkScalarToFloat(focal), SkScalarToFloat(oneMinus2F));
=======
        float values[2] = {
            SkScalarToFloat(focal),
            SkScalarToFloat(oneMinus2F),
        };

        pdman.set1fv(fParamUni, 2, values);
>>>>>>> miniblink49
        fCachedFocal = focal;
    }
}

void GLFocalOutside2PtConicalEffect::GenKey(const GrProcessor& processor,
<<<<<<< HEAD
    const GrGLSLCaps&, GrProcessorKeyBuilder* b)
{
=======
                                            const GrGLSLCaps&, GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    uint32_t* key = b->add32n(2);
    key[0] = GenBaseGradientKey(processor);
    key[1] = processor.cast<FocalOutside2PtConicalEffect>().isFlipped();
}

//////////////////////////////////////////////////////////////////////////////

class GLFocalInside2PtConicalEffect;

class FocalInside2PtConicalEffect : public GrGradientEffect {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm,
        SkScalar focalX)
    {
        return sk_sp<GrFragmentProcessor>(
            new FocalInside2PtConicalEffect(ctx, shader, matrix, tm, focalX));
    }

    virtual ~FocalInside2PtConicalEffect() { }

    const char* name() const override
    {
        return "Two-Point Conical Gradient Focal Inside";
    }

    SkScalar focal() const { return fFocalX; }

    typedef GLFocalInside2PtConicalEffect GLSLProcessor;

private:
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    bool onIsEqual(const GrFragmentProcessor& sBase) const override
    {
        const FocalInside2PtConicalEffect& s = sBase.cast<FocalInside2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) && this->fFocalX == s.fFocalX);
    }

    FocalInside2PtConicalEffect(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm,
        SkScalar focalX)
        : INHERITED(ctx, shader, matrix, tm)
        , fFocalX(focalX)
    {
=======

    static GrFragmentProcessor* Create(GrContext* ctx,
                                       GrProcessorDataManager* procDataManager,
                                       const SkTwoPointConicalGradient& shader,
                                       const SkMatrix& matrix,
                                       SkShader::TileMode tm,
                                       SkScalar focalX) {
        return SkNEW_ARGS(FocalInside2PtConicalEffect, (ctx, procDataManager, shader, matrix, tm,
                                                        focalX));
    }

    virtual ~FocalInside2PtConicalEffect() {}

    const char* name() const override {
        return "Two-Point Conical Gradient Focal Inside";
    }

    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

    SkScalar focal() const { return fFocalX; }

    typedef GLFocalInside2PtConicalEffect GLProcessor;

private:
    bool onIsEqual(const GrFragmentProcessor& sBase) const override {
        const FocalInside2PtConicalEffect& s = sBase.cast<FocalInside2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) &&
                this->fFocalX == s.fFocalX);
    }

    FocalInside2PtConicalEffect(GrContext* ctx,
                                GrProcessorDataManager* procDataManager,
                                const SkTwoPointConicalGradient& shader,
                                const SkMatrix& matrix,
                                SkShader::TileMode tm,
                                SkScalar focalX)
        : INHERITED(ctx, procDataManager, shader, matrix, tm), fFocalX(focalX) {
>>>>>>> miniblink49
        this->initClassID<FocalInside2PtConicalEffect>();
    }

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

<<<<<<< HEAD
    SkScalar fFocalX;
=======
    SkScalar         fFocalX;
>>>>>>> miniblink49

    typedef GrGradientEffect INHERITED;
};

class GLFocalInside2PtConicalEffect : public GrGLGradientEffect {
public:
    GLFocalInside2PtConicalEffect(const GrProcessor&);
<<<<<<< HEAD
    virtual ~GLFocalInside2PtConicalEffect() { }

    virtual void emitCode(EmitArgs&) override;
=======
    virtual ~GLFocalInside2PtConicalEffect() {}

    virtual void emitCode(GrGLFPBuilder*,
                          const GrFragmentProcessor&,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;
    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;
>>>>>>> miniblink49

    static void GenKey(const GrProcessor&, const GrGLSLCaps& caps, GrProcessorKeyBuilder* b);

protected:
<<<<<<< HEAD
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

=======
>>>>>>> miniblink49
    UniformHandle fFocalUni;

    const char* fVSVaryingName;
    const char* fFSVaryingName;

    // @{
    /// Values last uploaded as uniforms

    SkScalar fCachedFocal;

    // @}

private:
    typedef GrGLGradientEffect INHERITED;
<<<<<<< HEAD
};

void FocalInside2PtConicalEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GLFocalInside2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* FocalInside2PtConicalEffect::onCreateGLSLInstance() const
{
    return new GLFocalInside2PtConicalEffect(*this);
=======

};

void FocalInside2PtConicalEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                               GrProcessorKeyBuilder* b) const {
    GLFocalInside2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* FocalInside2PtConicalEffect::createGLInstance() const {
    return SkNEW_ARGS(GLFocalInside2PtConicalEffect, (*this));
>>>>>>> miniblink49
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(FocalInside2PtConicalEffect);

/*
 * All Two point conical gradient test create functions may occasionally create edge case shaders
 */
<<<<<<< HEAD
sk_sp<GrFragmentProcessor> FocalInside2PtConicalEffect::TestCreate(GrProcessorTestData* d)
{
    SkPoint center1 = { d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1() };
=======
GrFragmentProcessor* FocalInside2PtConicalEffect::TestCreate(GrProcessorTestData* d) {
    SkPoint center1 = {d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1()};
>>>>>>> miniblink49
    SkScalar radius1 = 0.f;
    SkPoint center2;
    SkScalar radius2;
    do {
        center2.set(d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1());
        // Below makes sure radius2 is larger enouch such that the focal point
        // is inside the end circle
        SkScalar increase = d->fRandom->nextUScalar1();
        SkPoint diff = center2 - center1;
        SkScalar diffLen = diff.length();
        radius2 = diffLen + increase;
        // If the circles are identical the factory will give us an empty shader.
    } while (radius1 == radius2 && center1 == center2);

    SkColor colors[kMaxRandomGradientColors];
    SkScalar stopsArray[kMaxRandomGradientColors];
    SkScalar* stops = stopsArray;
    SkShader::TileMode tm;
    int colorCount = RandomGradientParams(d->fRandom, colors, &stops, &tm);
<<<<<<< HEAD
    auto shader = SkGradientShader::MakeTwoPointConical(center1, radius1, center2, radius2,
        colors, stops, colorCount, tm);
    sk_sp<GrFragmentProcessor> fp = shader->asFragmentProcessor(d->fContext,
        GrTest::TestMatrix(d->fRandom), NULL, kNone_SkFilterQuality,
        SkSourceGammaTreatment::kRespect);
    GrAlwaysAssert(fp);
=======
    SkAutoTUnref<SkShader> shader(SkGradientShader::CreateTwoPointConical(center1, radius1,
                                                                          center2, radius2,
                                                                          colors, stops, colorCount,
                                                                          tm));
    SkPaint paint;
    GrColor paintColor;
    GrFragmentProcessor* fp;
    SkAssertResult(shader->asFragmentProcessor(d->fContext, paint,
                                               GrTest::TestMatrix(d->fRandom), NULL,
                                               &paintColor, d->fProcDataManager, &fp));
>>>>>>> miniblink49
    return fp;
}

GLFocalInside2PtConicalEffect::GLFocalInside2PtConicalEffect(const GrProcessor&)
<<<<<<< HEAD
    : fVSVaryingName(nullptr)
    , fFSVaryingName(nullptr)
    , fCachedFocal(SK_ScalarMax)
{
}

void GLFocalInside2PtConicalEffect::emitCode(EmitArgs& args)
{
    const FocalInside2PtConicalEffect& ge = args.fFp.cast<FocalInside2PtConicalEffect>();
    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    this->emitUniforms(uniformHandler, ge);
    fFocalUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "Conical2FSParams");
=======
    : fVSVaryingName(NULL)
    , fFSVaryingName(NULL)
    , fCachedFocal(SK_ScalarMax) {}

void GLFocalInside2PtConicalEffect::emitCode(GrGLFPBuilder* builder,
                                             const GrFragmentProcessor& fp,
                                             const char* outputColor,
                                             const char* inputColor,
                                             const TransformedCoordsArray& coords,
                                             const TextureSamplerArray& samplers) {
    const FocalInside2PtConicalEffect& ge = fp.cast<FocalInside2PtConicalEffect>();
    this->emitUniforms(builder, ge);
    fFocalUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                    kFloat_GrSLType, kDefault_GrSLPrecision,
                                    "Conical2FSParams");
>>>>>>> miniblink49
    SkString tName("t");

    // this is the distance along x-axis from the end center to focal point in
    // transformed coordinates
<<<<<<< HEAD
    GrGLSLShaderVar focal = uniformHandler->getUniformVariable(fFocalUni);

    // if we have a vec3 from being in perspective, convert it to a vec2 first
    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    SkString coords2DString = fragBuilder->ensureFSCoords2D(args.fCoords, 0);
    const char* coords2D = coords2DString.c_str();

    // t = p.x * focalX + length(p)
    fragBuilder->codeAppendf("\tfloat %s = %s.x * %s  + length(%s);\n", tName.c_str(),
        coords2D, focal.c_str(), coords2D);

    this->emitColor(fragBuilder,
        uniformHandler,
        args.fGLSLCaps,
        ge,
        tName.c_str(),
        args.fOutputColor,
        args.fInputColor,
        args.fTexSamplers);
}

void GLFocalInside2PtConicalEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& processor)
{
    INHERITED::onSetData(pdman, processor);
=======
    GrGLShaderVar focal = builder->getUniformVariable(fFocalUni);

    // if we have a vec3 from being in perspective, convert it to a vec2 first
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    SkString coords2DString = fsBuilder->ensureFSCoords2D(coords, 0);
    const char* coords2D = coords2DString.c_str();

    // t = p.x * focalX + length(p)
    fsBuilder->codeAppendf("\tfloat %s = %s.x * %s  + length(%s);\n", tName.c_str(),
                           coords2D, focal.c_str(), coords2D);

    this->emitColor(builder, ge, tName.c_str(), outputColor, inputColor, samplers);
}

void GLFocalInside2PtConicalEffect::setData(const GrGLProgramDataManager& pdman,
                                            const GrProcessor& processor) {
    INHERITED::setData(pdman, processor);
>>>>>>> miniblink49
    const FocalInside2PtConicalEffect& data = processor.cast<FocalInside2PtConicalEffect>();
    SkScalar focal = data.focal();

    if (fCachedFocal != focal) {
        pdman.set1f(fFocalUni, SkScalarToFloat(focal));
        fCachedFocal = focal;
    }
}

void GLFocalInside2PtConicalEffect::GenKey(const GrProcessor& processor,
<<<<<<< HEAD
    const GrGLSLCaps&, GrProcessorKeyBuilder* b)
{
=======
                                           const GrGLSLCaps&, GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    b->add32(GenBaseGradientKey(processor));
}

//////////////////////////////////////////////////////////////////////////////
// Circle Conical Gradients
//////////////////////////////////////////////////////////////////////////////

struct CircleConicalInfo {
    SkPoint fCenterEnd;
    SkScalar fA;
    SkScalar fB;
    SkScalar fC;
};

// Returns focal distance along x-axis in transformed coords
static ConicalType set_matrix_circle_conical(const SkTwoPointConicalGradient& shader,
<<<<<<< HEAD
    SkMatrix* invLMatrix, CircleConicalInfo* info)
{
=======
                                             SkMatrix* invLMatrix, CircleConicalInfo* info) {
>>>>>>> miniblink49
    // Inverse of the current local matrix is passed in then,
    // translate and scale such that start circle is on the origin and has radius 1
    const SkPoint& centerStart = shader.getStartCenter();
    const SkPoint& centerEnd = shader.getEndCenter();
    SkScalar radiusStart = shader.getStartRadius();
    SkScalar radiusEnd = shader.getEndRadius();

    SkMatrix matrix;

    matrix.setTranslate(-centerStart.fX, -centerStart.fY);

    SkScalar invStartRad = 1.f / radiusStart;
    matrix.postScale(invStartRad, invStartRad);

    radiusEnd /= radiusStart;

    SkPoint centerEndTrans;
    matrix.mapPoints(&centerEndTrans, &centerEnd, 1);

    SkScalar A = centerEndTrans.fX * centerEndTrans.fX + centerEndTrans.fY * centerEndTrans.fY
<<<<<<< HEAD
        - radiusEnd * radiusEnd + 2 * radiusEnd - 1;
=======
                 - radiusEnd * radiusEnd + 2 * radiusEnd - 1;
>>>>>>> miniblink49

    // Check to see if start circle is inside end circle with edges touching.
    // If touching we return that it is of kEdge_ConicalType, and leave the matrix setting
    // to the edge shader. kEdgeErrorTol = 5 * kErrorTol was picked after manual testing
    // so that C = 1 / A is stable, and the linear approximation used in the Edge shader is
    // still accurate.
    if (SkScalarAbs(A) < kEdgeErrorTol) {
        return kEdge_ConicalType;
    }

    SkScalar C = 1.f / A;
    SkScalar B = (radiusEnd - 1.f) * C;

    matrix.postScale(C, C);

    invLMatrix->postConcat(matrix);

    info->fCenterEnd = centerEndTrans;
    info->fA = A;
    info->fB = B;
    info->fC = C;

    // if A ends up being negative, the start circle is contained completely inside the end cirlce
    if (A < 0.f) {
        return kInside_ConicalType;
    }
    return kOutside_ConicalType;
}

class CircleInside2PtConicalEffect : public GrGradientEffect {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm,
        const CircleConicalInfo& info)
    {
        return sk_sp<GrFragmentProcessor>(
            new CircleInside2PtConicalEffect(ctx, shader, matrix, tm, info));
    }

    virtual ~CircleInside2PtConicalEffect() { }

    const char* name() const override { return "Two-Point Conical Gradient Inside"; }

=======

    static GrFragmentProcessor* Create(GrContext* ctx,
                                       GrProcessorDataManager* procDataManager,
                                       const SkTwoPointConicalGradient& shader,
                                       const SkMatrix& matrix,
                                       SkShader::TileMode tm,
                                       const CircleConicalInfo& info) {
        return SkNEW_ARGS(CircleInside2PtConicalEffect, (ctx, procDataManager, shader, matrix, tm,
                                                         info));
    }

    virtual ~CircleInside2PtConicalEffect() {}

    const char* name() const override { return "Two-Point Conical Gradient Inside"; }

    virtual void getGLProcessorKey(const GrGLSLCaps& caps,
                                   GrProcessorKeyBuilder* b) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

>>>>>>> miniblink49
    SkScalar centerX() const { return fInfo.fCenterEnd.fX; }
    SkScalar centerY() const { return fInfo.fCenterEnd.fY; }
    SkScalar A() const { return fInfo.fA; }
    SkScalar B() const { return fInfo.fB; }
    SkScalar C() const { return fInfo.fC; }

private:
<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    virtual void onGetGLSLProcessorKey(const GrGLSLCaps& caps,
        GrProcessorKeyBuilder* b) const override;

    bool onIsEqual(const GrFragmentProcessor& sBase) const override
    {
        const CircleInside2PtConicalEffect& s = sBase.cast<CircleInside2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) && this->fInfo.fCenterEnd == s.fInfo.fCenterEnd && this->fInfo.fA == s.fInfo.fA && this->fInfo.fB == s.fInfo.fB && this->fInfo.fC == s.fInfo.fC);
    }

    CircleInside2PtConicalEffect(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm,
        const CircleConicalInfo& info)
        : INHERITED(ctx, shader, matrix, tm)
        , fInfo(info)
    {
=======
    bool onIsEqual(const GrFragmentProcessor& sBase) const override {
        const CircleInside2PtConicalEffect& s = sBase.cast<CircleInside2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) &&
                this->fInfo.fCenterEnd == s.fInfo.fCenterEnd &&
                this->fInfo.fA == s.fInfo.fA &&
                this->fInfo.fB == s.fInfo.fB &&
                this->fInfo.fC == s.fInfo.fC);
    }

    CircleInside2PtConicalEffect(GrContext* ctx,
                                 GrProcessorDataManager* procDataManager,
                                 const SkTwoPointConicalGradient& shader,
                                 const SkMatrix& matrix,
                                 SkShader::TileMode tm,
                                 const CircleConicalInfo& info)
        : INHERITED(ctx, procDataManager, shader, matrix, tm), fInfo(info) {
>>>>>>> miniblink49
        this->initClassID<CircleInside2PtConicalEffect>();
    }

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    const CircleConicalInfo fInfo;

    typedef GrGradientEffect INHERITED;
};

class GLCircleInside2PtConicalEffect : public GrGLGradientEffect {
public:
    GLCircleInside2PtConicalEffect(const GrProcessor&);
<<<<<<< HEAD
    virtual ~GLCircleInside2PtConicalEffect() { }

    virtual void emitCode(EmitArgs&) override;
=======
    virtual ~GLCircleInside2PtConicalEffect() {}

    virtual void emitCode(GrGLFPBuilder*,
                          const GrFragmentProcessor&,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;
    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;
>>>>>>> miniblink49

    static void GenKey(const GrProcessor&, const GrGLSLCaps& caps, GrProcessorKeyBuilder* b);

protected:
<<<<<<< HEAD
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

=======
>>>>>>> miniblink49
    UniformHandle fCenterUni;
    UniformHandle fParamUni;

    const char* fVSVaryingName;
    const char* fFSVaryingName;

    // @{
    /// Values last uploaded as uniforms

    SkScalar fCachedCenterX;
    SkScalar fCachedCenterY;
    SkScalar fCachedA;
    SkScalar fCachedB;
    SkScalar fCachedC;

    // @}

private:
    typedef GrGLGradientEffect INHERITED;
<<<<<<< HEAD
};

void CircleInside2PtConicalEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GLCircleInside2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* CircleInside2PtConicalEffect::onCreateGLSLInstance() const
{
    return new GLCircleInside2PtConicalEffect(*this);
=======

};

void CircleInside2PtConicalEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                                     GrProcessorKeyBuilder* b) const {
    GLCircleInside2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* CircleInside2PtConicalEffect::createGLInstance() const {
    return SkNEW_ARGS(GLCircleInside2PtConicalEffect, (*this));
>>>>>>> miniblink49
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(CircleInside2PtConicalEffect);

/*
 * All Two point conical gradient test create functions may occasionally create edge case shaders
 */
<<<<<<< HEAD
sk_sp<GrFragmentProcessor> CircleInside2PtConicalEffect::TestCreate(GrProcessorTestData* d)
{
    SkPoint center1 = { d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1() };
=======
GrFragmentProcessor*
CircleInside2PtConicalEffect::TestCreate(GrProcessorTestData* d) {
    SkPoint center1 = {d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1()};
>>>>>>> miniblink49
    SkScalar radius1 = d->fRandom->nextUScalar1() + 0.0001f; // make sure radius1 != 0
    SkPoint center2;
    SkScalar radius2;
    do {
        center2.set(d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1());
        // Below makes sure that circle one is contained within circle two
        SkScalar increase = d->fRandom->nextUScalar1();
        SkPoint diff = center2 - center1;
        SkScalar diffLen = diff.length();
        radius2 = radius1 + diffLen + increase;
        // If the circles are identical the factory will give us an empty shader.
    } while (radius1 == radius2 && center1 == center2);

    SkColor colors[kMaxRandomGradientColors];
    SkScalar stopsArray[kMaxRandomGradientColors];
    SkScalar* stops = stopsArray;
    SkShader::TileMode tm;
    int colorCount = RandomGradientParams(d->fRandom, colors, &stops, &tm);
<<<<<<< HEAD
    auto shader = SkGradientShader::MakeTwoPointConical(center1, radius1, center2, radius2,
        colors, stops, colorCount, tm);
    sk_sp<GrFragmentProcessor> fp = shader->asFragmentProcessor(d->fContext,
        GrTest::TestMatrix(d->fRandom), NULL, kNone_SkFilterQuality,
        SkSourceGammaTreatment::kRespect);
    GrAlwaysAssert(fp);
=======
    SkAutoTUnref<SkShader> shader(SkGradientShader::CreateTwoPointConical(center1, radius1,
                                                                          center2, radius2,
                                                                          colors, stops, colorCount,
                                                                          tm));
    SkPaint paint;
    GrColor paintColor;
    GrFragmentProcessor* fp;
    SkAssertResult(shader->asFragmentProcessor(d->fContext, paint,
                                               GrTest::TestMatrix(d->fRandom), NULL,
                                               &paintColor, d->fProcDataManager, &fp));
>>>>>>> miniblink49
    return fp;
}

GLCircleInside2PtConicalEffect::GLCircleInside2PtConicalEffect(const GrProcessor& processor)
<<<<<<< HEAD
    : fVSVaryingName(nullptr)
    , fFSVaryingName(nullptr)
=======
    : fVSVaryingName(NULL)
    , fFSVaryingName(NULL)
>>>>>>> miniblink49
    , fCachedCenterX(SK_ScalarMax)
    , fCachedCenterY(SK_ScalarMax)
    , fCachedA(SK_ScalarMax)
    , fCachedB(SK_ScalarMax)
<<<<<<< HEAD
    , fCachedC(SK_ScalarMax)
{
}

void GLCircleInside2PtConicalEffect::emitCode(EmitArgs& args)
{
    const CircleInside2PtConicalEffect& ge = args.fFp.cast<CircleInside2PtConicalEffect>();
    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    this->emitUniforms(uniformHandler, ge);
    fCenterUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec2f_GrSLType, kDefault_GrSLPrecision,
        "Conical2FSCenter");
    fParamUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec3f_GrSLType, kDefault_GrSLPrecision,
        "Conical2FSParams");
    SkString tName("t");

    GrGLSLShaderVar center = uniformHandler->getUniformVariable(fCenterUni);
    // params.x = A
    // params.y = B
    // params.z = C
    GrGLSLShaderVar params = uniformHandler->getUniformVariable(fParamUni);

    // if we have a vec3 from being in perspective, convert it to a vec2 first
    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    SkString coords2DString = fragBuilder->ensureFSCoords2D(args.fCoords, 0);
=======
    , fCachedC(SK_ScalarMax) {}

void GLCircleInside2PtConicalEffect::emitCode(GrGLFPBuilder* builder,
                                              const GrFragmentProcessor& fp,
                                              const char* outputColor,
                                              const char* inputColor,
                                              const TransformedCoordsArray& coords,
                                              const TextureSamplerArray& samplers) {
    const CircleInside2PtConicalEffect& ge = fp.cast<CircleInside2PtConicalEffect>();
    this->emitUniforms(builder, ge);
    fCenterUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                     kVec2f_GrSLType, kDefault_GrSLPrecision,
                                     "Conical2FSCenter");
    fParamUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                    kVec3f_GrSLType, kDefault_GrSLPrecision,
                                    "Conical2FSParams");
    SkString tName("t");

    GrGLShaderVar center = builder->getUniformVariable(fCenterUni);
    // params.x = A
    // params.y = B
    // params.z = C
    GrGLShaderVar params = builder->getUniformVariable(fParamUni);

    // if we have a vec3 from being in perspective, convert it to a vec2 first
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    SkString coords2DString = fsBuilder->ensureFSCoords2D(coords, 0);
>>>>>>> miniblink49
    const char* coords2D = coords2DString.c_str();

    // p = coords2D
    // e = center end
    // r = radius end
    // A = dot(e, e) - r^2 + 2 * r - 1
    // B = (r -1) / A
    // C = 1 / A
    // d = dot(e, p) + B
    // t = d +/- sqrt(d^2 - A * dot(p, p) + C)
<<<<<<< HEAD
    fragBuilder->codeAppendf("\tfloat pDotp = dot(%s,  %s);\n", coords2D, coords2D);
    fragBuilder->codeAppendf("\tfloat d = dot(%s,  %s) + %s.y;\n", coords2D, center.c_str(),
        params.c_str());
    fragBuilder->codeAppendf("\tfloat %s = d + sqrt(d * d - %s.x * pDotp + %s.z);\n",
        tName.c_str(), params.c_str(), params.c_str());

    this->emitColor(fragBuilder,
        uniformHandler,
        args.fGLSLCaps,
        ge,
        tName.c_str(),
        args.fOutputColor,
        args.fInputColor,
        args.fTexSamplers);
}

void GLCircleInside2PtConicalEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& processor)
{
    INHERITED::onSetData(pdman, processor);
=======
    fsBuilder->codeAppendf("\tfloat pDotp = dot(%s,  %s);\n", coords2D, coords2D);
    fsBuilder->codeAppendf("\tfloat d = dot(%s,  %s) + %s.y;\n", coords2D, center.c_str(),
                           params.c_str());
    fsBuilder->codeAppendf("\tfloat %s = d + sqrt(d * d - %s.x * pDotp + %s.z);\n",
                           tName.c_str(), params.c_str(), params.c_str());

    this->emitColor(builder, ge, tName.c_str(), outputColor, inputColor, samplers);
}

void GLCircleInside2PtConicalEffect::setData(const GrGLProgramDataManager& pdman,
                                             const GrProcessor& processor) {
    INHERITED::setData(pdman, processor);
>>>>>>> miniblink49
    const CircleInside2PtConicalEffect& data = processor.cast<CircleInside2PtConicalEffect>();
    SkScalar centerX = data.centerX();
    SkScalar centerY = data.centerY();
    SkScalar A = data.A();
    SkScalar B = data.B();
    SkScalar C = data.C();

<<<<<<< HEAD
    if (fCachedCenterX != centerX || fCachedCenterY != centerY || fCachedA != A || fCachedB != B || fCachedC != C) {
=======
    if (fCachedCenterX != centerX || fCachedCenterY != centerY ||
        fCachedA != A || fCachedB != B || fCachedC != C) {
>>>>>>> miniblink49

        pdman.set2f(fCenterUni, SkScalarToFloat(centerX), SkScalarToFloat(centerY));
        pdman.set3f(fParamUni, SkScalarToFloat(A), SkScalarToFloat(B), SkScalarToFloat(C));

        fCachedCenterX = centerX;
        fCachedCenterY = centerY;
        fCachedA = A;
        fCachedB = B;
        fCachedC = C;
    }
}

void GLCircleInside2PtConicalEffect::GenKey(const GrProcessor& processor,
<<<<<<< HEAD
    const GrGLSLCaps&, GrProcessorKeyBuilder* b)
{
=======
                                            const GrGLSLCaps&, GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    b->add32(GenBaseGradientKey(processor));
}

//////////////////////////////////////////////////////////////////////////////

class CircleOutside2PtConicalEffect : public GrGradientEffect {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm,
        const CircleConicalInfo& info)
    {
        return sk_sp<GrFragmentProcessor>(
            new CircleOutside2PtConicalEffect(ctx, shader, matrix, tm, info));
    }

    virtual ~CircleOutside2PtConicalEffect() { }

    const char* name() const override { return "Two-Point Conical Gradient Outside"; }

=======

    static GrFragmentProcessor* Create(GrContext* ctx,
                                       GrProcessorDataManager* procDataManager,
                                       const SkTwoPointConicalGradient& shader,
                                       const SkMatrix& matrix,
                                       SkShader::TileMode tm,
                                       const CircleConicalInfo& info) {
        return SkNEW_ARGS(CircleOutside2PtConicalEffect, (ctx, procDataManager, shader, matrix,
                                                          tm, info));
    }

    virtual ~CircleOutside2PtConicalEffect() {}

    const char* name() const override { return "Two-Point Conical Gradient Outside"; }

    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

>>>>>>> miniblink49
    SkScalar centerX() const { return fInfo.fCenterEnd.fX; }
    SkScalar centerY() const { return fInfo.fCenterEnd.fY; }
    SkScalar A() const { return fInfo.fA; }
    SkScalar B() const { return fInfo.fB; }
    SkScalar C() const { return fInfo.fC; }
    SkScalar tLimit() const { return fTLimit; }
    bool isFlipped() const { return fIsFlipped; }

private:
<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    bool onIsEqual(const GrFragmentProcessor& sBase) const override
    {
        const CircleOutside2PtConicalEffect& s = sBase.cast<CircleOutside2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) && this->fInfo.fCenterEnd == s.fInfo.fCenterEnd && this->fInfo.fA == s.fInfo.fA && this->fInfo.fB == s.fInfo.fB && this->fInfo.fC == s.fInfo.fC && this->fTLimit == s.fTLimit && this->fIsFlipped == s.fIsFlipped);
    }

    CircleOutside2PtConicalEffect(GrContext* ctx,
        const SkTwoPointConicalGradient& shader,
        const SkMatrix& matrix,
        SkShader::TileMode tm,
        const CircleConicalInfo& info)
        : INHERITED(ctx, shader, matrix, tm)
        , fInfo(info)
    {
=======
    bool onIsEqual(const GrFragmentProcessor& sBase) const override {
        const CircleOutside2PtConicalEffect& s = sBase.cast<CircleOutside2PtConicalEffect>();
        return (INHERITED::onIsEqual(sBase) &&
                this->fInfo.fCenterEnd == s.fInfo.fCenterEnd &&
                this->fInfo.fA == s.fInfo.fA &&
                this->fInfo.fB == s.fInfo.fB &&
                this->fInfo.fC == s.fInfo.fC &&
                this->fTLimit == s.fTLimit &&
                this->fIsFlipped == s.fIsFlipped);
    }

    CircleOutside2PtConicalEffect(GrContext* ctx,
                                  GrProcessorDataManager* procDataManager,
                                  const SkTwoPointConicalGradient& shader,
                                  const SkMatrix& matrix,
                                  SkShader::TileMode tm,
                                  const CircleConicalInfo& info)
        : INHERITED(ctx, procDataManager, shader, matrix, tm), fInfo(info) {
>>>>>>> miniblink49
        this->initClassID<CircleOutside2PtConicalEffect>();
        if (shader.getStartRadius() != shader.getEndRadius()) {
            fTLimit = shader.getStartRadius() / (shader.getStartRadius() - shader.getEndRadius());
        } else {
            fTLimit = SK_ScalarMin;
        }

        fIsFlipped = shader.isFlippedGrad();
    }

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    const CircleConicalInfo fInfo;
    SkScalar fTLimit;
    bool fIsFlipped;

    typedef GrGradientEffect INHERITED;
};

class GLCircleOutside2PtConicalEffect : public GrGLGradientEffect {
public:
    GLCircleOutside2PtConicalEffect(const GrProcessor&);
<<<<<<< HEAD
    virtual ~GLCircleOutside2PtConicalEffect() { }

    virtual void emitCode(EmitArgs&) override;
=======
    virtual ~GLCircleOutside2PtConicalEffect() {}

    virtual void emitCode(GrGLFPBuilder*,
                          const GrFragmentProcessor&,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;
    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;
>>>>>>> miniblink49

    static void GenKey(const GrProcessor&, const GrGLSLCaps& caps, GrProcessorKeyBuilder* b);

protected:
<<<<<<< HEAD
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

=======
>>>>>>> miniblink49
    UniformHandle fCenterUni;
    UniformHandle fParamUni;

    const char* fVSVaryingName;
    const char* fFSVaryingName;

    bool fIsFlipped;

    // @{
    /// Values last uploaded as uniforms

    SkScalar fCachedCenterX;
    SkScalar fCachedCenterY;
    SkScalar fCachedA;
    SkScalar fCachedB;
    SkScalar fCachedC;
    SkScalar fCachedTLimit;

    // @}

private:
    typedef GrGLGradientEffect INHERITED;
<<<<<<< HEAD
};

void CircleOutside2PtConicalEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GLCircleOutside2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* CircleOutside2PtConicalEffect::onCreateGLSLInstance() const
{
    return new GLCircleOutside2PtConicalEffect(*this);
=======

};

void CircleOutside2PtConicalEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                                      GrProcessorKeyBuilder* b) const {
    GLCircleOutside2PtConicalEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* CircleOutside2PtConicalEffect::createGLInstance() const {
    return SkNEW_ARGS(GLCircleOutside2PtConicalEffect, (*this));
>>>>>>> miniblink49
}

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(CircleOutside2PtConicalEffect);

/*
 * All Two point conical gradient test create functions may occasionally create edge case shaders
 */
<<<<<<< HEAD
sk_sp<GrFragmentProcessor> CircleOutside2PtConicalEffect::TestCreate(GrProcessorTestData* d)
{
    SkPoint center1 = { d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1() };
=======
GrFragmentProcessor* CircleOutside2PtConicalEffect::TestCreate(GrProcessorTestData* d) {
    SkPoint center1 = {d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1()};
>>>>>>> miniblink49
    SkScalar radius1 = d->fRandom->nextUScalar1() + 0.0001f; // make sure radius1 != 0
    SkPoint center2;
    SkScalar radius2;
    SkScalar diffLen;
    do {
        center2.set(d->fRandom->nextUScalar1(), d->fRandom->nextUScalar1());
        // If the circles share a center than we can't be in the outside case
    } while (center1 == center2);
    SkPoint diff = center2 - center1;
    diffLen = diff.length();
    // Below makes sure that circle one is not contained within circle two
    // and have radius2 >= radius to match sorting on cpu side
    radius2 = radius1 + d->fRandom->nextRangeF(0.f, diffLen);

    SkColor colors[kMaxRandomGradientColors];
    SkScalar stopsArray[kMaxRandomGradientColors];
    SkScalar* stops = stopsArray;
    SkShader::TileMode tm;
    int colorCount = RandomGradientParams(d->fRandom, colors, &stops, &tm);
<<<<<<< HEAD
    auto shader = SkGradientShader::MakeTwoPointConical(center1, radius1, center2, radius2,
        colors, stops, colorCount, tm);
    sk_sp<GrFragmentProcessor> fp = shader->asFragmentProcessor(
        d->fContext, GrTest::TestMatrix(d->fRandom), NULL, kNone_SkFilterQuality,
        SkSourceGammaTreatment::kRespect);
    GrAlwaysAssert(fp);
=======
    SkAutoTUnref<SkShader> shader(SkGradientShader::CreateTwoPointConical(center1, radius1,
                                                                          center2, radius2,
                                                                          colors, stops, colorCount,
                                                                          tm));
    SkPaint paint;
    GrColor paintColor;
    GrFragmentProcessor* fp;
    SkAssertResult(shader->asFragmentProcessor(d->fContext, paint,
                                               GrTest::TestMatrix(d->fRandom), NULL,
                                               &paintColor, d->fProcDataManager, &fp));
>>>>>>> miniblink49
    return fp;
}

GLCircleOutside2PtConicalEffect::GLCircleOutside2PtConicalEffect(const GrProcessor& processor)
<<<<<<< HEAD
    : fVSVaryingName(nullptr)
    , fFSVaryingName(nullptr)
=======
    : fVSVaryingName(NULL)
    , fFSVaryingName(NULL)
>>>>>>> miniblink49
    , fCachedCenterX(SK_ScalarMax)
    , fCachedCenterY(SK_ScalarMax)
    , fCachedA(SK_ScalarMax)
    , fCachedB(SK_ScalarMax)
    , fCachedC(SK_ScalarMax)
<<<<<<< HEAD
    , fCachedTLimit(SK_ScalarMax)
{
    const CircleOutside2PtConicalEffect& data = processor.cast<CircleOutside2PtConicalEffect>();
    fIsFlipped = data.isFlipped();
}

void GLCircleOutside2PtConicalEffect::emitCode(EmitArgs& args)
{
    const CircleOutside2PtConicalEffect& ge = args.fFp.cast<CircleOutside2PtConicalEffect>();
    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    this->emitUniforms(uniformHandler, ge);
    fCenterUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec2f_GrSLType, kDefault_GrSLPrecision,
        "Conical2FSCenter");
    fParamUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec4f_GrSLType, kDefault_GrSLPrecision,
        "Conical2FSParams");
    SkString tName("t");

    GrGLSLShaderVar center = uniformHandler->getUniformVariable(fCenterUni);
    // params.x = A
    // params.y = B
    // params.z = C
    GrGLSLShaderVar params = uniformHandler->getUniformVariable(fParamUni);

    // if we have a vec3 from being in perspective, convert it to a vec2 first
    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    SkString coords2DString = fragBuilder->ensureFSCoords2D(args.fCoords, 0);
=======
    , fCachedTLimit(SK_ScalarMax) {
    const CircleOutside2PtConicalEffect& data = processor.cast<CircleOutside2PtConicalEffect>();
    fIsFlipped = data.isFlipped();
    }

void GLCircleOutside2PtConicalEffect::emitCode(GrGLFPBuilder* builder,
                                               const GrFragmentProcessor& fp,
                                               const char* outputColor,
                                               const char* inputColor,
                                               const TransformedCoordsArray& coords,
                                               const TextureSamplerArray& samplers) {
    const CircleOutside2PtConicalEffect& ge = fp.cast<CircleOutside2PtConicalEffect>();
    this->emitUniforms(builder, ge);
    fCenterUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                     kVec2f_GrSLType, kDefault_GrSLPrecision,
                                     "Conical2FSCenter");
    fParamUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                    kVec4f_GrSLType, kDefault_GrSLPrecision,
                                    "Conical2FSParams");
    SkString tName("t");

    GrGLShaderVar center = builder->getUniformVariable(fCenterUni);
    // params.x = A
    // params.y = B
    // params.z = C
    GrGLShaderVar params = builder->getUniformVariable(fParamUni);

    // if we have a vec3 from being in perspective, convert it to a vec2 first
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    SkString coords2DString = fsBuilder->ensureFSCoords2D(coords, 0);
>>>>>>> miniblink49
    const char* coords2D = coords2DString.c_str();

    // output will default to transparent black (we simply won't write anything
    // else to it if invalid, instead of discarding or returning prematurely)
<<<<<<< HEAD
    fragBuilder->codeAppendf("\t%s = vec4(0.0,0.0,0.0,0.0);\n", args.fOutputColor);
=======
    fsBuilder->codeAppendf("\t%s = vec4(0.0,0.0,0.0,0.0);\n", outputColor);
>>>>>>> miniblink49

    // p = coords2D
    // e = center end
    // r = radius end
    // A = dot(e, e) - r^2 + 2 * r - 1
    // B = (r -1) / A
    // C = 1 / A
    // d = dot(e, p) + B
    // t = d +/- sqrt(d^2 - A * dot(p, p) + C)

<<<<<<< HEAD
    fragBuilder->codeAppendf("\tfloat pDotp = dot(%s,  %s);\n", coords2D, coords2D);
    fragBuilder->codeAppendf("\tfloat d = dot(%s,  %s) + %s.y;\n", coords2D, center.c_str(),
        params.c_str());
    fragBuilder->codeAppendf("\tfloat deter = d * d - %s.x * pDotp + %s.z;\n", params.c_str(),
        params.c_str());
=======
    fsBuilder->codeAppendf("\tfloat pDotp = dot(%s,  %s);\n", coords2D, coords2D);
    fsBuilder->codeAppendf("\tfloat d = dot(%s,  %s) + %s.y;\n", coords2D, center.c_str(),
                           params.c_str());
    fsBuilder->codeAppendf("\tfloat deter = d * d - %s.x * pDotp + %s.z;\n", params.c_str(),
                           params.c_str());
>>>>>>> miniblink49

    // Must check to see if we flipped the circle order (to make sure start radius < end radius)
    // If so we must also flip sign on sqrt
    if (!fIsFlipped) {
<<<<<<< HEAD
        fragBuilder->codeAppendf("\tfloat %s = d + sqrt(deter);\n", tName.c_str());
    } else {
        fragBuilder->codeAppendf("\tfloat %s = d - sqrt(deter);\n", tName.c_str());
    }

    fragBuilder->codeAppendf("\tif (%s >= %s.w && deter >= 0.0) {\n",
        tName.c_str(), params.c_str());
    fragBuilder->codeAppend("\t\t");
    this->emitColor(fragBuilder,
        uniformHandler,
        args.fGLSLCaps,
        ge,
        tName.c_str(),
        args.fOutputColor,
        args.fInputColor,
        args.fTexSamplers);
    fragBuilder->codeAppend("\t}\n");
}

void GLCircleOutside2PtConicalEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& processor)
{
    INHERITED::onSetData(pdman, processor);
=======
        fsBuilder->codeAppendf("\tfloat %s = d + sqrt(deter);\n", tName.c_str());
    } else {
        fsBuilder->codeAppendf("\tfloat %s = d - sqrt(deter);\n", tName.c_str());
    }

    fsBuilder->codeAppendf("\tif (%s >= %s.w && deter >= 0.0) {\n", tName.c_str(), params.c_str());
    fsBuilder->codeAppend("\t\t");
    this->emitColor(builder, ge, tName.c_str(), outputColor, inputColor, samplers);
    fsBuilder->codeAppend("\t}\n");
}

void GLCircleOutside2PtConicalEffect::setData(const GrGLProgramDataManager& pdman,
                                              const GrProcessor& processor) {
    INHERITED::setData(pdman, processor);
>>>>>>> miniblink49
    const CircleOutside2PtConicalEffect& data = processor.cast<CircleOutside2PtConicalEffect>();
    SkASSERT(data.isFlipped() == fIsFlipped);
    SkScalar centerX = data.centerX();
    SkScalar centerY = data.centerY();
    SkScalar A = data.A();
    SkScalar B = data.B();
    SkScalar C = data.C();
    SkScalar tLimit = data.tLimit();

<<<<<<< HEAD
    if (fCachedCenterX != centerX || fCachedCenterY != centerY || fCachedA != A || fCachedB != B || fCachedC != C || fCachedTLimit != tLimit) {

        pdman.set2f(fCenterUni, SkScalarToFloat(centerX), SkScalarToFloat(centerY));
        pdman.set4f(fParamUni, SkScalarToFloat(A), SkScalarToFloat(B), SkScalarToFloat(C),
            SkScalarToFloat(tLimit));
=======
    if (fCachedCenterX != centerX || fCachedCenterY != centerY ||
        fCachedA != A || fCachedB != B || fCachedC != C || fCachedTLimit != tLimit) {

        pdman.set2f(fCenterUni, SkScalarToFloat(centerX), SkScalarToFloat(centerY));
        pdman.set4f(fParamUni, SkScalarToFloat(A), SkScalarToFloat(B), SkScalarToFloat(C),
                   SkScalarToFloat(tLimit));
>>>>>>> miniblink49

        fCachedCenterX = centerX;
        fCachedCenterY = centerY;
        fCachedA = A;
        fCachedB = B;
        fCachedC = C;
        fCachedTLimit = tLimit;
    }
}

void GLCircleOutside2PtConicalEffect::GenKey(const GrProcessor& processor,
<<<<<<< HEAD
    const GrGLSLCaps&, GrProcessorKeyBuilder* b)
{
=======
                                             const GrGLSLCaps&, GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    uint32_t* key = b->add32n(2);
    key[0] = GenBaseGradientKey(processor);
    key[1] = processor.cast<CircleOutside2PtConicalEffect>().isFlipped();
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> Gr2PtConicalGradientEffect::Make(GrContext* ctx,
    const SkTwoPointConicalGradient& shader,
    SkShader::TileMode tm,
    const SkMatrix* localMatrix)
{
    SkMatrix matrix;
    if (!shader.getLocalMatrix().invert(&matrix)) {
        return nullptr;
=======
GrFragmentProcessor* Gr2PtConicalGradientEffect::Create(GrContext* ctx,
                                                        GrProcessorDataManager* procDataManager,
                                                        const SkTwoPointConicalGradient& shader,
                                                        SkShader::TileMode tm,
                                                        const SkMatrix* localMatrix) {
    SkMatrix matrix;
    if (!shader.getLocalMatrix().invert(&matrix)) {
        return NULL;
>>>>>>> miniblink49
    }
    if (localMatrix) {
        SkMatrix inv;
        if (!localMatrix->invert(&inv)) {
<<<<<<< HEAD
            return nullptr;
=======
            return NULL;
>>>>>>> miniblink49
        }
        matrix.postConcat(inv);
    }

    if (shader.getStartRadius() < kErrorTol) {
        SkScalar focalX;
        ConicalType type = set_matrix_focal_conical(shader, &matrix, &focalX);
        if (type == kInside_ConicalType) {
<<<<<<< HEAD
            return FocalInside2PtConicalEffect::Make(ctx, shader, matrix, tm, focalX);
        } else if (type == kEdge_ConicalType) {
            set_matrix_edge_conical(shader, &matrix);
            return Edge2PtConicalEffect::Make(ctx, shader, matrix, tm);
        } else {
            return FocalOutside2PtConicalEffect::Make(ctx, shader, matrix, tm, focalX);
=======
            return FocalInside2PtConicalEffect::Create(ctx, procDataManager, shader, matrix, tm,
                                                       focalX);
        } else if(type == kEdge_ConicalType) {
            set_matrix_edge_conical(shader, &matrix);
            return Edge2PtConicalEffect::Create(ctx, procDataManager, shader, matrix, tm);
        } else {
            return FocalOutside2PtConicalEffect::Create(ctx, procDataManager, shader, matrix, tm,
                                                        focalX);
>>>>>>> miniblink49
        }
    }

    CircleConicalInfo info;
    ConicalType type = set_matrix_circle_conical(shader, &matrix, &info);

    if (type == kInside_ConicalType) {
<<<<<<< HEAD
        return CircleInside2PtConicalEffect::Make(ctx, shader, matrix, tm, info);
    } else if (type == kEdge_ConicalType) {
        set_matrix_edge_conical(shader, &matrix);
        return Edge2PtConicalEffect::Make(ctx, shader, matrix, tm);
    } else {
        return CircleOutside2PtConicalEffect::Make(ctx, shader, matrix, tm, info);
=======
        return CircleInside2PtConicalEffect::Create(ctx, procDataManager,  shader, matrix, tm,
                                                    info);
    } else if (type == kEdge_ConicalType) {
        set_matrix_edge_conical(shader, &matrix);
        return Edge2PtConicalEffect::Create(ctx, procDataManager, shader, matrix, tm);
    } else {
        return CircleOutside2PtConicalEffect::Create(ctx, procDataManager, shader, matrix, tm,
                                                     info);
>>>>>>> miniblink49
    }
}

#endif
