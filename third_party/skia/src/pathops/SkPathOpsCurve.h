/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkPathOpsCurve_DEFINE
#define SkPathOpsCurve_DEFINE

#include "SkIntersections.h"

#ifndef SK_RELEASE
#include "SkPath.h"
#endif

struct SkPathOpsBounds;

struct SkOpCurve {
    SkPoint fPts[4];
    SkScalar fWeight;
    SkDEBUGCODE(SkPath::Verb fVerb);

<<<<<<< HEAD
    const SkPoint& operator[](int n) const
    {
=======
    const SkPoint& operator[](int n) const {
>>>>>>> miniblink49
        SkASSERT(n >= 0 && n <= SkPathOpsVerbToPoints(fVerb));
        return fPts[n];
    }

    void dump() const;

<<<<<<< HEAD
    void set(const SkDQuad& quad)
    {
=======
    void set(const SkDQuad& quad) {
>>>>>>> miniblink49
        for (int index = 0; index < SkDQuad::kPointCount; ++index) {
            fPts[index] = quad[index].asSkPoint();
        }
        SkDEBUGCODE(fWeight = 1);
        SkDEBUGCODE(fVerb = SkPath::kQuad_Verb);
    }

<<<<<<< HEAD
    void set(const SkDCubic& cubic)
    {
=======
    void set(const SkDCubic& cubic) {
>>>>>>> miniblink49
        for (int index = 0; index < SkDCubic::kPointCount; ++index) {
            fPts[index] = cubic[index].asSkPoint();
        }
        SkDEBUGCODE(fWeight = 1);
        SkDEBUGCODE(fVerb = SkPath::kCubic_Verb);
    }
<<<<<<< HEAD
=======

>>>>>>> miniblink49
};

struct SkDCurve {
    union {
        SkDLine fLine;
        SkDQuad fQuad;
        SkDConic fConic;
        SkDCubic fCubic;
    };
    SkDEBUGCODE(SkPath::Verb fVerb);

<<<<<<< HEAD
    const SkDPoint& operator[](int n) const
    {
=======
    const SkDPoint& operator[](int n) const {
>>>>>>> miniblink49
        SkASSERT(n >= 0 && n <= SkPathOpsVerbToPoints(fVerb));
        return fCubic[n];
    }

<<<<<<< HEAD
    SkDPoint& operator[](int n)
    {
=======
    SkDPoint& operator[](int n) {
>>>>>>> miniblink49
        SkASSERT(n >= 0 && n <= SkPathOpsVerbToPoints(fVerb));
        return fCubic[n];
    }

<<<<<<< HEAD
    SkDPoint conicTop(const SkPoint curve[3], SkScalar curveWeight,
        double s, double e, double* topT);
    SkDPoint cubicTop(const SkPoint curve[4], SkScalar, double s, double e, double* topT);
    void dumpID(int) const;
    SkDPoint lineTop(const SkPoint[2], SkScalar, double, double, double* topT);
    SkDPoint quadTop(const SkPoint curve[3], SkScalar, double s, double e, double* topT);

    void setConicBounds(const SkPoint curve[3], SkScalar curveWeight,
        double s, double e, SkPathOpsBounds*);
    void setCubicBounds(const SkPoint curve[4], SkScalar,
        double s, double e, SkPathOpsBounds*);
    void setQuadBounds(const SkPoint curve[3], SkScalar,
        double s, double e, SkPathOpsBounds*);
};

extern SkDPoint (SkDCurve::*const Top[])(const SkPoint curve[], SkScalar cWeight,
    double tStart, double tEnd, double* topT);

static SkDPoint dline_xy_at_t(const SkPoint a[2], SkScalar, double t)
{
=======
    SkDPoint conicTop(const SkPoint curve[3], SkScalar curveWeight, 
                      double s, double e, double* topT);
    SkDPoint cubicTop(const SkPoint curve[4], SkScalar , double s, double e, double* topT);
    void dumpID(int ) const;
    SkDPoint lineTop(const SkPoint[2], SkScalar , double , double , double* topT);
    SkDPoint quadTop(const SkPoint curve[3], SkScalar , double s, double e, double* topT);

    void setConicBounds(const SkPoint curve[3], SkScalar curveWeight, 
                        double s, double e, SkPathOpsBounds* );
    void setCubicBounds(const SkPoint curve[4], SkScalar ,
                        double s, double e, SkPathOpsBounds* );
    void setQuadBounds(const SkPoint curve[3], SkScalar ,
                       double s, double e, SkPathOpsBounds*);
};


extern SkDPoint (SkDCurve::* const Top[])(const SkPoint curve[], SkScalar cWeight,
    double tStart, double tEnd, double* topT);

static SkDPoint dline_xy_at_t(const SkPoint a[2], SkScalar , double t) {
>>>>>>> miniblink49
    SkDLine line;
    line.set(a);
    return line.ptAtT(t);
}

<<<<<<< HEAD
static SkDPoint dquad_xy_at_t(const SkPoint a[3], SkScalar, double t)
{
=======
static SkDPoint dquad_xy_at_t(const SkPoint a[3], SkScalar , double t) {
>>>>>>> miniblink49
    SkDQuad quad;
    quad.set(a);
    return quad.ptAtT(t);
}

<<<<<<< HEAD
static SkDPoint dconic_xy_at_t(const SkPoint a[3], SkScalar weight, double t)
{
=======
static SkDPoint dconic_xy_at_t(const SkPoint a[3], SkScalar weight, double t) {
>>>>>>> miniblink49
    SkDConic conic;
    conic.set(a, weight);
    return conic.ptAtT(t);
}

<<<<<<< HEAD
static SkDPoint dcubic_xy_at_t(const SkPoint a[4], SkScalar, double t)
{
=======
static SkDPoint dcubic_xy_at_t(const SkPoint a[4], SkScalar , double t) {
>>>>>>> miniblink49
    SkDCubic cubic;
    cubic.set(a);
    return cubic.ptAtT(t);
}

<<<<<<< HEAD
static SkDPoint (*const CurveDPointAtT[])(const SkPoint[], SkScalar, double) = {
    nullptr,
=======
static SkDPoint (* const CurveDPointAtT[])(const SkPoint[], SkScalar , double ) = {
    NULL,
>>>>>>> miniblink49
    dline_xy_at_t,
    dquad_xy_at_t,
    dconic_xy_at_t,
    dcubic_xy_at_t
};

<<<<<<< HEAD
static SkPoint fline_xy_at_t(const SkPoint a[2], SkScalar weight, double t)
{
    return dline_xy_at_t(a, weight, t).asSkPoint();
}

static SkPoint fquad_xy_at_t(const SkPoint a[3], SkScalar weight, double t)
{
    return dquad_xy_at_t(a, weight, t).asSkPoint();
}

static SkPoint fconic_xy_at_t(const SkPoint a[3], SkScalar weight, double t)
{
    return dconic_xy_at_t(a, weight, t).asSkPoint();
}

static SkPoint fcubic_xy_at_t(const SkPoint a[4], SkScalar weight, double t)
{
    return dcubic_xy_at_t(a, weight, t).asSkPoint();
}

static SkPoint (*const CurvePointAtT[])(const SkPoint[], SkScalar, double) = {
    nullptr,
=======
static SkPoint fline_xy_at_t(const SkPoint a[2], SkScalar weight, double t) {
    return dline_xy_at_t(a, weight, t).asSkPoint();
}

static SkPoint fquad_xy_at_t(const SkPoint a[3], SkScalar weight, double t) {
    return dquad_xy_at_t(a, weight, t).asSkPoint();
}

static SkPoint fconic_xy_at_t(const SkPoint a[3], SkScalar weight, double t) {
    return dconic_xy_at_t(a, weight, t).asSkPoint();
}

static SkPoint fcubic_xy_at_t(const SkPoint a[4], SkScalar weight, double t) {
    return dcubic_xy_at_t(a, weight, t).asSkPoint();
}

static SkPoint (* const CurvePointAtT[])(const SkPoint[], SkScalar , double ) = {
    NULL,
>>>>>>> miniblink49
    fline_xy_at_t,
    fquad_xy_at_t,
    fconic_xy_at_t,
    fcubic_xy_at_t
};

<<<<<<< HEAD
static SkDVector dline_dxdy_at_t(const SkPoint a[2], SkScalar, double)
{
=======
static SkDVector dline_dxdy_at_t(const SkPoint a[2], SkScalar , double ) {
>>>>>>> miniblink49
    SkDLine line;
    line.set(a);
    return line[1] - line[0];
}

<<<<<<< HEAD
static SkDVector dquad_dxdy_at_t(const SkPoint a[3], SkScalar, double t)
{
=======
static SkDVector dquad_dxdy_at_t(const SkPoint a[3], SkScalar , double t) {
>>>>>>> miniblink49
    SkDQuad quad;
    quad.set(a);
    return quad.dxdyAtT(t);
}

<<<<<<< HEAD
static SkDVector dconic_dxdy_at_t(const SkPoint a[3], SkScalar weight, double t)
{
=======
static SkDVector dconic_dxdy_at_t(const SkPoint a[3], SkScalar weight, double t) {
>>>>>>> miniblink49
    SkDConic conic;
    conic.set(a, weight);
    return conic.dxdyAtT(t);
}

<<<<<<< HEAD
static SkDVector dcubic_dxdy_at_t(const SkPoint a[4], SkScalar, double t)
{
=======
static SkDVector dcubic_dxdy_at_t(const SkPoint a[4], SkScalar , double t) {
>>>>>>> miniblink49
    SkDCubic cubic;
    cubic.set(a);
    return cubic.dxdyAtT(t);
}

<<<<<<< HEAD
static SkDVector (*const CurveDSlopeAtT[])(const SkPoint[], SkScalar, double) = {
    nullptr,
=======
static SkDVector (* const CurveDSlopeAtT[])(const SkPoint[], SkScalar , double ) = {
    NULL,
>>>>>>> miniblink49
    dline_dxdy_at_t,
    dquad_dxdy_at_t,
    dconic_dxdy_at_t,
    dcubic_dxdy_at_t
};

<<<<<<< HEAD
static SkVector fline_dxdy_at_t(const SkPoint a[2], SkScalar, double)
{
    return a[1] - a[0];
}

static SkVector fquad_dxdy_at_t(const SkPoint a[3], SkScalar weight, double t)
{
    return dquad_dxdy_at_t(a, weight, t).asSkVector();
}

static SkVector fconic_dxdy_at_t(const SkPoint a[3], SkScalar weight, double t)
{
    return dconic_dxdy_at_t(a, weight, t).asSkVector();
}

static SkVector fcubic_dxdy_at_t(const SkPoint a[4], SkScalar weight, double t)
{
    return dcubic_dxdy_at_t(a, weight, t).asSkVector();
}

static SkVector (*const CurveSlopeAtT[])(const SkPoint[], SkScalar, double) = {
    nullptr,
=======
static SkVector fline_dxdy_at_t(const SkPoint a[2], SkScalar , double ) {
    return a[1] - a[0];
}

static SkVector fquad_dxdy_at_t(const SkPoint a[3], SkScalar weight, double t) {
    return dquad_dxdy_at_t(a, weight, t).asSkVector();
}

static SkVector fconic_dxdy_at_t(const SkPoint a[3], SkScalar weight, double t) {
    return dconic_dxdy_at_t(a, weight, t).asSkVector();
}

static SkVector fcubic_dxdy_at_t(const SkPoint a[4], SkScalar weight, double t) {
    return dcubic_dxdy_at_t(a, weight, t).asSkVector();
}

static SkVector (* const CurveSlopeAtT[])(const SkPoint[], SkScalar , double ) = {
    NULL,
>>>>>>> miniblink49
    fline_dxdy_at_t,
    fquad_dxdy_at_t,
    fconic_dxdy_at_t,
    fcubic_dxdy_at_t
};

<<<<<<< HEAD
static bool line_is_vertical(const SkPoint a[2], SkScalar, double startT, double endT)
{
=======
static bool line_is_vertical(const SkPoint a[2], SkScalar , double startT, double endT) {
>>>>>>> miniblink49
    SkDLine line;
    line.set(a);
    SkDPoint dst[2] = { line.ptAtT(startT), line.ptAtT(endT) };
    return AlmostEqualUlps(dst[0].fX, dst[1].fX);
}

<<<<<<< HEAD
static bool quad_is_vertical(const SkPoint a[3], SkScalar, double startT, double endT)
{
=======
static bool quad_is_vertical(const SkPoint a[3], SkScalar , double startT, double endT) {
>>>>>>> miniblink49
    SkDQuad quad;
    quad.set(a);
    SkDQuad dst = quad.subDivide(startT, endT);
    return AlmostEqualUlps(dst[0].fX, dst[1].fX) && AlmostEqualUlps(dst[1].fX, dst[2].fX);
}

<<<<<<< HEAD
static bool conic_is_vertical(const SkPoint a[3], SkScalar weight, double startT, double endT)
{
=======
static bool conic_is_vertical(const SkPoint a[3], SkScalar weight, double startT, double endT) {
>>>>>>> miniblink49
    SkDConic conic;
    conic.set(a, weight);
    SkDConic dst = conic.subDivide(startT, endT);
    return AlmostEqualUlps(dst[0].fX, dst[1].fX) && AlmostEqualUlps(dst[1].fX, dst[2].fX);
}

<<<<<<< HEAD
static bool cubic_is_vertical(const SkPoint a[4], SkScalar, double startT, double endT)
{
=======
static bool cubic_is_vertical(const SkPoint a[4], SkScalar , double startT, double endT) {
>>>>>>> miniblink49
    SkDCubic cubic;
    cubic.set(a);
    SkDCubic dst = cubic.subDivide(startT, endT);
    return AlmostEqualUlps(dst[0].fX, dst[1].fX) && AlmostEqualUlps(dst[1].fX, dst[2].fX)
<<<<<<< HEAD
        && AlmostEqualUlps(dst[2].fX, dst[3].fX);
}

static bool (*const CurveIsVertical[])(const SkPoint[], SkScalar, double, double) = {
    nullptr,
=======
            && AlmostEqualUlps(dst[2].fX, dst[3].fX);
}

static bool (* const CurveIsVertical[])(const SkPoint[], SkScalar , double , double) = {
    NULL,
>>>>>>> miniblink49
    line_is_vertical,
    quad_is_vertical,
    conic_is_vertical,
    cubic_is_vertical
};

<<<<<<< HEAD
static void line_intersect_ray(const SkPoint a[2], SkScalar, const SkDLine& ray,
    SkIntersections* i)
{
=======
static void line_intersect_ray(const SkPoint a[2], SkScalar , const SkDLine& ray,
        SkIntersections* i) {
>>>>>>> miniblink49
    SkDLine line;
    line.set(a);
    i->intersectRay(line, ray);
}

<<<<<<< HEAD
static void quad_intersect_ray(const SkPoint a[3], SkScalar, const SkDLine& ray,
    SkIntersections* i)
{
=======
static void quad_intersect_ray(const SkPoint a[3], SkScalar , const SkDLine& ray,
        SkIntersections* i) {
>>>>>>> miniblink49
    SkDQuad quad;
    quad.set(a);
    i->intersectRay(quad, ray);
}

static void conic_intersect_ray(const SkPoint a[3], SkScalar weight, const SkDLine& ray,
<<<<<<< HEAD
    SkIntersections* i)
{
=======
        SkIntersections* i) {
>>>>>>> miniblink49
    SkDConic conic;
    conic.set(a, weight);
    i->intersectRay(conic, ray);
}

<<<<<<< HEAD
static void cubic_intersect_ray(const SkPoint a[4], SkScalar, const SkDLine& ray,
    SkIntersections* i)
{
=======
static void cubic_intersect_ray(const SkPoint a[4], SkScalar , const SkDLine& ray,
        SkIntersections* i) {
>>>>>>> miniblink49
    SkDCubic cubic;
    cubic.set(a);
    i->intersectRay(cubic, ray);
}

<<<<<<< HEAD
static void (*const CurveIntersectRay[])(const SkPoint[], SkScalar, const SkDLine&,
    SkIntersections*)
    = {
          nullptr,
          line_intersect_ray,
          quad_intersect_ray,
          conic_intersect_ray,
          cubic_intersect_ray
      };

static int line_intercept_h(const SkPoint a[2], SkScalar, SkScalar y, double* roots)
{
=======
static void (* const CurveIntersectRay[])(const SkPoint[] , SkScalar , const SkDLine& ,
        SkIntersections* ) = {
    NULL,
    line_intersect_ray,
    quad_intersect_ray,
    conic_intersect_ray,
    cubic_intersect_ray
};

static int line_intercept_h(const SkPoint a[2], SkScalar , SkScalar y, double* roots) {
>>>>>>> miniblink49
    SkDLine line;
    roots[0] = SkIntersections::HorizontalIntercept(line.set(a), y);
    return between(0, roots[0], 1);
}

<<<<<<< HEAD
static int line_intercept_v(const SkPoint a[2], SkScalar, SkScalar x, double* roots)
{
=======
static int line_intercept_v(const SkPoint a[2], SkScalar , SkScalar x, double* roots) {
>>>>>>> miniblink49
    SkDLine line;
    roots[0] = SkIntersections::VerticalIntercept(line.set(a), x);
    return between(0, roots[0], 1);
}

<<<<<<< HEAD
static int quad_intercept_h(const SkPoint a[2], SkScalar, SkScalar y, double* roots)
{
=======
static int quad_intercept_h(const SkPoint a[2], SkScalar , SkScalar y, double* roots) {
>>>>>>> miniblink49
    SkDQuad quad;
    return SkIntersections::HorizontalIntercept(quad.set(a), y, roots);
}

<<<<<<< HEAD
static int quad_intercept_v(const SkPoint a[2], SkScalar, SkScalar x, double* roots)
{
=======
static int quad_intercept_v(const SkPoint a[2], SkScalar , SkScalar x, double* roots) {
>>>>>>> miniblink49
    SkDQuad quad;
    return SkIntersections::VerticalIntercept(quad.set(a), x, roots);
}

<<<<<<< HEAD
static int conic_intercept_h(const SkPoint a[2], SkScalar w, SkScalar y, double* roots)
{
=======
static int conic_intercept_h(const SkPoint a[2], SkScalar w, SkScalar y, double* roots) {
>>>>>>> miniblink49
    SkDConic conic;
    return SkIntersections::HorizontalIntercept(conic.set(a, w), y, roots);
}

<<<<<<< HEAD
static int conic_intercept_v(const SkPoint a[2], SkScalar w, SkScalar x, double* roots)
{
=======
static int conic_intercept_v(const SkPoint a[2], SkScalar w, SkScalar x, double* roots) {
>>>>>>> miniblink49
    SkDConic conic;
    return SkIntersections::VerticalIntercept(conic.set(a, w), x, roots);
}

<<<<<<< HEAD
static int cubic_intercept_h(const SkPoint a[3], SkScalar, SkScalar y, double* roots)
{
=======
static int cubic_intercept_h(const SkPoint a[3], SkScalar , SkScalar y, double* roots) {
>>>>>>> miniblink49
    SkDCubic cubic;
    return cubic.set(a).horizontalIntersect(y, roots);
}

<<<<<<< HEAD
static int cubic_intercept_v(const SkPoint a[3], SkScalar, SkScalar x, double* roots)
{
=======
static int cubic_intercept_v(const SkPoint a[3], SkScalar , SkScalar x, double* roots) {
>>>>>>> miniblink49
    SkDCubic cubic;
    return cubic.set(a).verticalIntersect(x, roots);
}

<<<<<<< HEAD
static int (*const CurveIntercept[])(const SkPoint[], SkScalar, SkScalar, double*) = {
    nullptr,
    nullptr,
=======
static int (* const CurveIntercept[])(const SkPoint[] , SkScalar , SkScalar , double* ) = {
    NULL,
    NULL,
>>>>>>> miniblink49
    line_intercept_h,
    line_intercept_v,
    quad_intercept_h,
    quad_intercept_v,
    conic_intercept_h,
    conic_intercept_v,
    cubic_intercept_h,
    cubic_intercept_v,
};

#endif
