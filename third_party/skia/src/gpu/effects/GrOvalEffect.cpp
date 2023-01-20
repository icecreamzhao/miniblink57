/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrOvalEffect.h"

#include "GrFragmentProcessor.h"
#include "GrInvariantOutput.h"
#include "SkRect.h"
<<<<<<< HEAD
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
=======
#include "gl/GrGLProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"
>>>>>>> miniblink49

//////////////////////////////////////////////////////////////////////////////

class CircleEffect : public GrFragmentProcessor {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrPrimitiveEdgeType, const SkPoint& center,
        SkScalar radius);
=======
    static GrFragmentProcessor* Create(GrPrimitiveEdgeType, const SkPoint& center, SkScalar radius);
>>>>>>> miniblink49

    virtual ~CircleEffect() {};

    const char* name() const override { return "Circle"; }

<<<<<<< HEAD
=======
    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

>>>>>>> miniblink49
    const SkPoint& getCenter() const { return fCenter; }
    SkScalar getRadius() const { return fRadius; }

    GrPrimitiveEdgeType getEdgeType() const { return fEdgeType; }

private:
    CircleEffect(GrPrimitiveEdgeType, const SkPoint& center, SkScalar radius);

<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

=======
>>>>>>> miniblink49
    bool onIsEqual(const GrFragmentProcessor&) const override;

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override;

<<<<<<< HEAD
    SkPoint fCenter;
    SkScalar fRadius;
    GrPrimitiveEdgeType fEdgeType;
=======
    SkPoint             fCenter;
    SkScalar            fRadius;
    GrPrimitiveEdgeType    fEdgeType;
>>>>>>> miniblink49

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    typedef GrFragmentProcessor INHERITED;
};

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> CircleEffect::Make(GrPrimitiveEdgeType edgeType, const SkPoint& center,
    SkScalar radius)
{
    SkASSERT(radius >= 0);
    return sk_sp<GrFragmentProcessor>(new CircleEffect(edgeType, center, radius));
}

void CircleEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
=======
GrFragmentProcessor* CircleEffect::Create(GrPrimitiveEdgeType edgeType, const SkPoint& center,
                                          SkScalar radius) {
    SkASSERT(radius >= 0);
    return SkNEW_ARGS(CircleEffect, (edgeType, center, radius));
}

void CircleEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const {
>>>>>>> miniblink49
    inout->mulByUnknownSingleComponent();
}

CircleEffect::CircleEffect(GrPrimitiveEdgeType edgeType, const SkPoint& c, SkScalar r)
    : fCenter(c)
    , fRadius(r)
<<<<<<< HEAD
    , fEdgeType(edgeType)
{
=======
    , fEdgeType(edgeType) {
>>>>>>> miniblink49
    this->initClassID<CircleEffect>();
    this->setWillReadFragmentPosition();
}

<<<<<<< HEAD
bool CircleEffect::onIsEqual(const GrFragmentProcessor& other) const
{
=======
bool CircleEffect::onIsEqual(const GrFragmentProcessor& other) const {
>>>>>>> miniblink49
    const CircleEffect& ce = other.cast<CircleEffect>();
    return fEdgeType == ce.fEdgeType && fCenter == ce.fCenter && fRadius == ce.fRadius;
}

//////////////////////////////////////////////////////////////////////////////

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(CircleEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> CircleEffect::TestCreate(GrProcessorTestData* d)
{
=======
GrFragmentProcessor* CircleEffect::TestCreate(GrProcessorTestData* d) {
>>>>>>> miniblink49
    SkPoint center;
    center.fX = d->fRandom->nextRangeScalar(0.f, 1000.f);
    center.fY = d->fRandom->nextRangeScalar(0.f, 1000.f);
    SkScalar radius = d->fRandom->nextRangeF(0.f, 1000.f);
    GrPrimitiveEdgeType et;
    do {
        et = (GrPrimitiveEdgeType)d->fRandom->nextULessThan(kGrProcessorEdgeTypeCnt);
    } while (kHairlineAA_GrProcessorEdgeType == et);
<<<<<<< HEAD
    return CircleEffect::Make(et, center, radius);
=======
    return CircleEffect::Create(et, center, radius);
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GLCircleEffect : public GrGLSLFragmentProcessor {
public:
    GLCircleEffect()
        : fPrevRadius(-1.0f)
    {
    }

    virtual void emitCode(EmitArgs&) override;

    static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder*);

protected:
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

private:
    GrGLSLProgramDataManager::UniformHandle fCircleUniform;
    SkPoint fPrevCenter;
    SkScalar fPrevRadius;

    typedef GrGLSLFragmentProcessor INHERITED;
};

void GLCircleEffect::emitCode(EmitArgs& args)
{
    const CircleEffect& ce = args.fFp.cast<CircleEffect>();
    const char* circleName;
    // The circle uniform is (center.x, center.y, radius + 0.5, 1 / (radius + 0.5)) for regular
    // fills and (..., radius - 0.5, 1 / (radius - 0.5)) for inverse fills.
    fCircleUniform = args.fUniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec4f_GrSLType, kDefault_GrSLPrecision,
        "circle",
        &circleName);

    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    const char* fragmentPos = fragBuilder->fragmentPosition();
=======
class GLCircleEffect : public GrGLFragmentProcessor {
public:
    GLCircleEffect(const GrProcessor&);

    virtual void emitCode(GrGLFPBuilder* builder,
                          const GrFragmentProcessor& fp,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;

    static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder*);

    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;

private:
    GrGLProgramDataManager::UniformHandle fCircleUniform;
    SkPoint                               fPrevCenter;
    SkScalar                              fPrevRadius;

    typedef GrGLFragmentProcessor INHERITED;
};

GLCircleEffect::GLCircleEffect(const GrProcessor&) {
    fPrevRadius = -1.f;
}

void GLCircleEffect::emitCode(GrGLFPBuilder* builder,
                              const GrFragmentProcessor& fp,
                              const char* outputColor,
                              const char* inputColor,
                              const TransformedCoordsArray&,
                              const TextureSamplerArray& samplers) {
    const CircleEffect& ce = fp.cast<CircleEffect>();
    const char *circleName;
    // The circle uniform is (center.x, center.y, radius + 0.5, 1 / (radius + 0.5)) for regular
    // fills and (..., radius - 0.5, 1 / (radius - 0.5)) for inverse fills.
    fCircleUniform = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                         kVec4f_GrSLType, kDefault_GrSLPrecision,
                                         "circle",
                                         &circleName);

    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    const char* fragmentPos = fsBuilder->fragmentPosition();
>>>>>>> miniblink49

    SkASSERT(kHairlineAA_GrProcessorEdgeType != ce.getEdgeType());
    // TODO: Right now the distance to circle caclulation is performed in a space normalized to the
    // radius and then denormalized. This is to prevent overflow on devices that have a "real"
    // mediump. It'd be nice to only to this on mediump devices but we currently don't have the
    // caps here.
    if (GrProcessorEdgeTypeIsInverseFill(ce.getEdgeType())) {
<<<<<<< HEAD
        fragBuilder->codeAppendf("float d = (length((%s.xy - %s.xy) * %s.w) - 1.0) * %s.z;",
            circleName, fragmentPos, circleName, circleName);
    } else {
        fragBuilder->codeAppendf("float d = (1.0 - length((%s.xy - %s.xy) *  %s.w)) * %s.z;",
            circleName, fragmentPos, circleName, circleName);
    }
    if (GrProcessorEdgeTypeIsAA(ce.getEdgeType())) {
        fragBuilder->codeAppend("d = clamp(d, 0.0, 1.0);");
    } else {
        fragBuilder->codeAppend("d = d > 0.5 ? 1.0 : 0.0;");
    }

    fragBuilder->codeAppendf("%s = %s;", args.fOutputColor,
        (GrGLSLExpr4(args.fInputColor) * GrGLSLExpr1("d")).c_str());
}

void GLCircleEffect::GenKey(const GrProcessor& processor, const GrGLSLCaps&,
    GrProcessorKeyBuilder* b)
{
=======
        fsBuilder->codeAppendf("\t\tfloat d = (length((%s.xy - %s.xy) * %s.w) - 1.0) * %s.z;\n",
                                circleName, fragmentPos, circleName, circleName);
    } else {
        fsBuilder->codeAppendf("\t\tfloat d = (1.0 - length((%s.xy - %s.xy) *  %s.w)) * %s.z;\n",
                               circleName, fragmentPos, circleName, circleName);
    }
    if (GrProcessorEdgeTypeIsAA(ce.getEdgeType())) {
        fsBuilder->codeAppend("\t\td = clamp(d, 0.0, 1.0);\n");
    } else {
        fsBuilder->codeAppend("\t\td = d > 0.5 ? 1.0 : 0.0;\n");
    }

    fsBuilder->codeAppendf("\t\t%s = %s;\n", outputColor,
                           (GrGLSLExpr4(inputColor) * GrGLSLExpr1("d")).c_str());
}

void GLCircleEffect::GenKey(const GrProcessor& processor, const GrGLSLCaps&,
                            GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    const CircleEffect& ce = processor.cast<CircleEffect>();
    b->add32(ce.getEdgeType());
}

<<<<<<< HEAD
void GLCircleEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& processor)
{
=======
void GLCircleEffect::setData(const GrGLProgramDataManager& pdman, const GrProcessor& processor) {
>>>>>>> miniblink49
    const CircleEffect& ce = processor.cast<CircleEffect>();
    if (ce.getRadius() != fPrevRadius || ce.getCenter() != fPrevCenter) {
        SkScalar radius = ce.getRadius();
        if (GrProcessorEdgeTypeIsInverseFill(ce.getEdgeType())) {
            radius -= 0.5f;
        } else {
            radius += 0.5f;
        }
        pdman.set4f(fCircleUniform, ce.getCenter().fX, ce.getCenter().fY, radius,
<<<<<<< HEAD
            SkScalarInvert(radius));
=======
                    SkScalarInvert(radius));
>>>>>>> miniblink49
        fPrevCenter = ce.getCenter();
        fPrevRadius = ce.getRadius();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void CircleEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GLCircleEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* CircleEffect::onCreateGLSLInstance() const
{
    return new GLCircleEffect;
=======
void CircleEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                     GrProcessorKeyBuilder* b) const {
    GLCircleEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* CircleEffect::createGLInstance() const  {
    return SkNEW_ARGS(GLCircleEffect, (*this));
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

class EllipseEffect : public GrFragmentProcessor {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrPrimitiveEdgeType, const SkPoint& center,
        SkScalar rx, SkScalar ry);
=======
    static GrFragmentProcessor* Create(GrPrimitiveEdgeType, const SkPoint& center, SkScalar rx,
                                       SkScalar ry);
>>>>>>> miniblink49

    virtual ~EllipseEffect() {};

    const char* name() const override { return "Ellipse"; }

<<<<<<< HEAD
=======
    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

>>>>>>> miniblink49
    const SkPoint& getCenter() const { return fCenter; }
    SkVector getRadii() const { return fRadii; }

    GrPrimitiveEdgeType getEdgeType() const { return fEdgeType; }

private:
    EllipseEffect(GrPrimitiveEdgeType, const SkPoint& center, SkScalar rx, SkScalar ry);

<<<<<<< HEAD
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

=======
>>>>>>> miniblink49
    bool onIsEqual(const GrFragmentProcessor&) const override;

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override;

<<<<<<< HEAD
    SkPoint fCenter;
    SkVector fRadii;
    GrPrimitiveEdgeType fEdgeType;
=======
    SkPoint             fCenter;
    SkVector            fRadii;
    GrPrimitiveEdgeType    fEdgeType;
>>>>>>> miniblink49

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    typedef GrFragmentProcessor INHERITED;
};

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> EllipseEffect::Make(GrPrimitiveEdgeType edgeType,
    const SkPoint& center,
    SkScalar rx,
    SkScalar ry)
{
    SkASSERT(rx >= 0 && ry >= 0);
    return sk_sp<GrFragmentProcessor>(new EllipseEffect(edgeType, center, rx, ry));
}

void EllipseEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
=======
GrFragmentProcessor* EllipseEffect::Create(GrPrimitiveEdgeType edgeType,
                                           const SkPoint& center,
                                           SkScalar rx,
                                           SkScalar ry) {
    SkASSERT(rx >= 0 && ry >= 0);
    return SkNEW_ARGS(EllipseEffect, (edgeType, center, rx, ry));
}

void EllipseEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const {
>>>>>>> miniblink49
    inout->mulByUnknownSingleComponent();
}

EllipseEffect::EllipseEffect(GrPrimitiveEdgeType edgeType, const SkPoint& c, SkScalar rx, SkScalar ry)
    : fCenter(c)
    , fRadii(SkVector::Make(rx, ry))
<<<<<<< HEAD
    , fEdgeType(edgeType)
{
=======
    , fEdgeType(edgeType) {
>>>>>>> miniblink49
    this->initClassID<EllipseEffect>();
    this->setWillReadFragmentPosition();
}

<<<<<<< HEAD
bool EllipseEffect::onIsEqual(const GrFragmentProcessor& other) const
{
=======
bool EllipseEffect::onIsEqual(const GrFragmentProcessor& other) const {
>>>>>>> miniblink49
    const EllipseEffect& ee = other.cast<EllipseEffect>();
    return fEdgeType == ee.fEdgeType && fCenter == ee.fCenter && fRadii == ee.fRadii;
}

//////////////////////////////////////////////////////////////////////////////

GR_DEFINE_FRAGMENT_PROCESSOR_TEST(EllipseEffect);

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> EllipseEffect::TestCreate(GrProcessorTestData* d)
{
=======
GrFragmentProcessor* EllipseEffect::TestCreate(GrProcessorTestData* d) {
>>>>>>> miniblink49
    SkPoint center;
    center.fX = d->fRandom->nextRangeScalar(0.f, 1000.f);
    center.fY = d->fRandom->nextRangeScalar(0.f, 1000.f);
    SkScalar rx = d->fRandom->nextRangeF(0.f, 1000.f);
    SkScalar ry = d->fRandom->nextRangeF(0.f, 1000.f);
    GrPrimitiveEdgeType et;
    do {
        et = (GrPrimitiveEdgeType)d->fRandom->nextULessThan(kGrProcessorEdgeTypeCnt);
    } while (kHairlineAA_GrProcessorEdgeType == et);
<<<<<<< HEAD
    return EllipseEffect::Make(et, center, rx, ry);
=======
    return EllipseEffect::Create(et, center, rx, ry);
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
class GLEllipseEffect : public GrGLSLFragmentProcessor {
public:
    GLEllipseEffect()
    {
        fPrevRadii.fX = -1.0f;
    }

    void emitCode(EmitArgs&) override;

    static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder*);

protected:
    void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

private:
    GrGLSLProgramDataManager::UniformHandle fEllipseUniform;
    GrGLSLProgramDataManager::UniformHandle fScaleUniform;
    SkPoint fPrevCenter;
    SkVector fPrevRadii;

    typedef GrGLSLFragmentProcessor INHERITED;
};

void GLEllipseEffect::emitCode(EmitArgs& args)
{
    const EllipseEffect& ee = args.fFp.cast<EllipseEffect>();
    const char* ellipseName;
    // The ellipse uniform is (center.x, center.y, 1 / rx^2, 1 / ry^2)
    // The last two terms can underflow on mediump, so we use highp.
    fEllipseUniform = args.fUniformHandler->addUniform(kFragment_GrShaderFlag,
        kVec4f_GrSLType, kHigh_GrSLPrecision,
        "ellipse",
        &ellipseName);
    // If we're on a device with a "real" mediump then we'll do the distance computation in a space
    // that is normalized by the larger radius. The scale uniform will be scale, 1/scale. The
    // inverse squared radii uniform values are already in this normalized space. The center is
    // not.
    const char* scaleName = nullptr;
    if (args.fGLSLCaps->floatPrecisionVaries()) {
        fScaleUniform = args.fUniformHandler->addUniform(
            kFragment_GrShaderFlag, kVec2f_GrSLType, kDefault_GrSLPrecision,
            "scale", &scaleName);
    }

    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
    const char* fragmentPos = fragBuilder->fragmentPosition();

    // d is the offset to the ellipse center
    fragBuilder->codeAppendf("vec2 d = %s.xy - %s.xy;", fragmentPos, ellipseName);
    if (scaleName) {
        fragBuilder->codeAppendf("d *= %s.y;", scaleName);
    }
    fragBuilder->codeAppendf("vec2 Z = d * %s.zw;", ellipseName);
    // implicit is the evaluation of (x/rx)^2 + (y/ry)^2 - 1.
    fragBuilder->codeAppend("float implicit = dot(Z, d) - 1.0;");
    // grad_dot is the squared length of the gradient of the implicit.
    fragBuilder->codeAppendf("float grad_dot = 4.0 * dot(Z, Z);");
    // Avoid calling inversesqrt on zero.
    fragBuilder->codeAppend("grad_dot = max(grad_dot, 1.0e-4);");
    fragBuilder->codeAppendf("float approx_dist = implicit * inversesqrt(grad_dot);");
    if (scaleName) {
        fragBuilder->codeAppendf("approx_dist *= %s.x;", scaleName);
    }

    switch (ee.getEdgeType()) {
    case kFillAA_GrProcessorEdgeType:
        fragBuilder->codeAppend("float alpha = clamp(0.5 - approx_dist, 0.0, 1.0);");
        break;
    case kInverseFillAA_GrProcessorEdgeType:
        fragBuilder->codeAppend("float alpha = clamp(0.5 + approx_dist, 0.0, 1.0);");
        break;
    case kFillBW_GrProcessorEdgeType:
        fragBuilder->codeAppend("float alpha = approx_dist > 0.0 ? 0.0 : 1.0;");
        break;
    case kInverseFillBW_GrProcessorEdgeType:
        fragBuilder->codeAppend("float alpha = approx_dist > 0.0 ? 1.0 : 0.0;");
        break;
    case kHairlineAA_GrProcessorEdgeType:
        SkFAIL("Hairline not expected here.");
    }

    fragBuilder->codeAppendf("%s = %s;", args.fOutputColor,
        (GrGLSLExpr4(args.fInputColor) * GrGLSLExpr1("alpha")).c_str());
}

void GLEllipseEffect::GenKey(const GrProcessor& effect, const GrGLSLCaps&,
    GrProcessorKeyBuilder* b)
{
=======
class GLEllipseEffect : public GrGLFragmentProcessor {
public:
    GLEllipseEffect(const GrProcessor&);

    virtual void emitCode(GrGLFPBuilder* builder,
                          const GrFragmentProcessor& fp,
                          const char* outputColor,
                          const char* inputColor,
                          const TransformedCoordsArray&,
                          const TextureSamplerArray&) override;

    static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder*);

    void setData(const GrGLProgramDataManager&, const GrProcessor&) override;

private:
    GrGLProgramDataManager::UniformHandle fEllipseUniform;
    SkPoint                               fPrevCenter;
    SkVector                              fPrevRadii;

    typedef GrGLFragmentProcessor INHERITED;
};

GLEllipseEffect::GLEllipseEffect(const GrProcessor& effect) {
    fPrevRadii.fX = -1.f;
}

void GLEllipseEffect::emitCode(GrGLFPBuilder* builder,
                               const GrFragmentProcessor& fp,
                               const char* outputColor,
                               const char* inputColor,
                               const TransformedCoordsArray&,
                               const TextureSamplerArray& samplers) {
    const EllipseEffect& ee = fp.cast<EllipseEffect>();
    const char *ellipseName;
    // The ellipse uniform is (center.x, center.y, 1 / rx^2, 1 / ry^2)
    fEllipseUniform = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                         kVec4f_GrSLType, kDefault_GrSLPrecision,
                                         "ellipse",
                                         &ellipseName);

    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();
    const char* fragmentPos = fsBuilder->fragmentPosition();

    // d is the offset to the ellipse center
    fsBuilder->codeAppendf("\t\tvec2 d = %s.xy - %s.xy;\n", fragmentPos, ellipseName);
    fsBuilder->codeAppendf("\t\tvec2 Z = d * %s.zw;\n", ellipseName);
    // implicit is the evaluation of (x/rx)^2 + (y/ry)^2 - 1.
    fsBuilder->codeAppend("\t\tfloat implicit = dot(Z, d) - 1.0;\n");
    // grad_dot is the squared length of the gradient of the implicit.
    fsBuilder->codeAppendf("\t\tfloat grad_dot = 4.0 * dot(Z, Z);\n");
    // avoid calling inversesqrt on zero.
    fsBuilder->codeAppend("\t\tgrad_dot = max(grad_dot, 1.0e-4);\n");
    fsBuilder->codeAppendf("\t\tfloat approx_dist = implicit * inversesqrt(grad_dot);\n");

    switch (ee.getEdgeType()) {
        case kFillAA_GrProcessorEdgeType:
            fsBuilder->codeAppend("\t\tfloat alpha = clamp(0.5 - approx_dist, 0.0, 1.0);\n");
            break;
        case kInverseFillAA_GrProcessorEdgeType:
            fsBuilder->codeAppend("\t\tfloat alpha = clamp(0.5 + approx_dist, 0.0, 1.0);\n");
            break;
        case kFillBW_GrProcessorEdgeType:
            fsBuilder->codeAppend("\t\tfloat alpha = approx_dist > 0.0 ? 0.0 : 1.0;\n");
            break;
        case kInverseFillBW_GrProcessorEdgeType:
            fsBuilder->codeAppend("\t\tfloat alpha = approx_dist > 0.0 ? 1.0 : 0.0;\n");
            break;
        case kHairlineAA_GrProcessorEdgeType:
            SkFAIL("Hairline not expected here.");
    }

    fsBuilder->codeAppendf("\t\t%s = %s;\n", outputColor,
                           (GrGLSLExpr4(inputColor) * GrGLSLExpr1("alpha")).c_str());
}

void GLEllipseEffect::GenKey(const GrProcessor& effect, const GrGLSLCaps&,
                             GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
    const EllipseEffect& ee = effect.cast<EllipseEffect>();
    b->add32(ee.getEdgeType());
}

<<<<<<< HEAD
void GLEllipseEffect::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& effect)
{
    const EllipseEffect& ee = effect.cast<EllipseEffect>();
    if (ee.getRadii() != fPrevRadii || ee.getCenter() != fPrevCenter) {
        float invRXSqd;
        float invRYSqd;
        // If we're using a scale factor to work around precision issues, choose the larger radius
        // as the scale factor. The inv radii need to be pre-adjusted by the scale factor.
        if (fScaleUniform.isValid()) {
            if (ee.getRadii().fX > ee.getRadii().fY) {
                invRXSqd = 1.f;
                invRYSqd = (ee.getRadii().fX * ee.getRadii().fX) / (ee.getRadii().fY * ee.getRadii().fY);
                pdman.set2f(fScaleUniform, ee.getRadii().fX, 1.f / ee.getRadii().fX);
            } else {
                invRXSqd = (ee.getRadii().fY * ee.getRadii().fY) / (ee.getRadii().fX * ee.getRadii().fX);
                invRYSqd = 1.f;
                pdman.set2f(fScaleUniform, ee.getRadii().fY, 1.f / ee.getRadii().fY);
            }
        } else {
            invRXSqd = 1.f / (ee.getRadii().fX * ee.getRadii().fX);
            invRYSqd = 1.f / (ee.getRadii().fY * ee.getRadii().fY);
        }
=======
void GLEllipseEffect::setData(const GrGLProgramDataManager& pdman, const GrProcessor& effect) {
    const EllipseEffect& ee = effect.cast<EllipseEffect>();
    if (ee.getRadii() != fPrevRadii || ee.getCenter() != fPrevCenter) {
        SkScalar invRXSqd = 1.f / (ee.getRadii().fX * ee.getRadii().fX);
        SkScalar invRYSqd = 1.f / (ee.getRadii().fY * ee.getRadii().fY);
>>>>>>> miniblink49
        pdman.set4f(fEllipseUniform, ee.getCenter().fX, ee.getCenter().fY, invRXSqd, invRYSqd);
        fPrevCenter = ee.getCenter();
        fPrevRadii = ee.getRadii();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void EllipseEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GLEllipseEffect::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* EllipseEffect::onCreateGLSLInstance() const
{
    return new GLEllipseEffect;
=======
void EllipseEffect::getGLProcessorKey(const GrGLSLCaps& caps,
                                     GrProcessorKeyBuilder* b) const {
    GLEllipseEffect::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* EllipseEffect::createGLInstance() const  {
    return SkNEW_ARGS(GLEllipseEffect, (*this));
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
sk_sp<GrFragmentProcessor> GrOvalEffect::Make(GrPrimitiveEdgeType edgeType, const SkRect& oval)
{
    if (kHairlineAA_GrProcessorEdgeType == edgeType) {
        return nullptr;
=======
GrFragmentProcessor* GrOvalEffect::Create(GrPrimitiveEdgeType edgeType, const SkRect& oval) {
    if (kHairlineAA_GrProcessorEdgeType == edgeType) {
        return NULL;
>>>>>>> miniblink49
    }
    SkScalar w = oval.width();
    SkScalar h = oval.height();
    if (SkScalarNearlyEqual(w, h)) {
        w /= 2;
<<<<<<< HEAD
        return CircleEffect::Make(edgeType, SkPoint::Make(oval.fLeft + w, oval.fTop + w), w);
    } else {
        w /= 2;
        h /= 2;
        return EllipseEffect::Make(edgeType, SkPoint::Make(oval.fLeft + w, oval.fTop + h), w, h);
    }

    return nullptr;
=======
        return CircleEffect::Create(edgeType, SkPoint::Make(oval.fLeft + w, oval.fTop + w), w);
    } else {
        w /= 2;
        h /= 2;
        return EllipseEffect::Create(edgeType, SkPoint::Make(oval.fLeft + w, oval.fTop + h), w, h);
    }

    return NULL;
>>>>>>> miniblink49
}
