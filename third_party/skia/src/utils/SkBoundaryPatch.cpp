<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkBoundaryPatch.h"

<<<<<<< HEAD
SkBoundaryPatch::SkBoundaryPatch()
    : fBoundary(nullptr)
{
}

SkBoundaryPatch::~SkBoundaryPatch()
{
    SkSafeUnref(fBoundary);
}

SkBoundary* SkBoundaryPatch::setBoundary(SkBoundary* b)
{
=======
SkBoundaryPatch::SkBoundaryPatch() : fBoundary(NULL) {}

SkBoundaryPatch::~SkBoundaryPatch() {
    SkSafeUnref(fBoundary);
}

SkBoundary* SkBoundaryPatch::setBoundary(SkBoundary* b) {
>>>>>>> miniblink49
    SkRefCnt_SafeAssign(fBoundary, b);
    return b;
}

<<<<<<< HEAD
static SkPoint SkMakePoint(SkScalar x, SkScalar y)
{
=======
static SkPoint SkMakePoint(SkScalar x, SkScalar y) {
>>>>>>> miniblink49
    SkPoint pt;
    pt.set(x, y);
    return pt;
}

<<<<<<< HEAD
static SkPoint SkPointInterp(const SkPoint& a, const SkPoint& b, SkScalar t)
{
    return SkMakePoint(SkScalarInterp(a.fX, b.fX, t),
        SkScalarInterp(a.fY, b.fY, t));
}

SkPoint SkBoundaryPatch::eval(SkScalar unitU, SkScalar unitV)
{
    SkBoundary* b = fBoundary;
    SkPoint u = SkPointInterp(b->eval(SkBoundary::kLeft, SK_Scalar1 - unitV),
        b->eval(SkBoundary::kRight, unitV),
        unitU);
    SkPoint v = SkPointInterp(b->eval(SkBoundary::kTop, unitU),
        b->eval(SkBoundary::kBottom, SK_Scalar1 - unitU),
        unitV);
    return SkMakePoint(SkScalarAve(u.fX, v.fX),
        SkScalarAve(u.fY, v.fY));
}

bool SkBoundaryPatch::evalPatch(SkPoint verts[], int rows, int cols)
{
=======
static SkPoint SkPointInterp(const SkPoint& a, const SkPoint& b, SkScalar t) {
    return SkMakePoint(SkScalarInterp(a.fX, b.fX, t),
                       SkScalarInterp(a.fY, b.fY, t));
}

SkPoint SkBoundaryPatch::eval(SkScalar unitU, SkScalar unitV) {
    SkBoundary* b = fBoundary;
    SkPoint u = SkPointInterp(b->eval(SkBoundary::kLeft, SK_Scalar1 - unitV),
                              b->eval(SkBoundary::kRight, unitV),
                              unitU);
    SkPoint v = SkPointInterp(b->eval(SkBoundary::kTop, unitU),
                              b->eval(SkBoundary::kBottom, SK_Scalar1 - unitU),
                              unitV);
    return SkMakePoint(SkScalarAve(u.fX, v.fX),
                       SkScalarAve(u.fY, v.fY));
}

bool SkBoundaryPatch::evalPatch(SkPoint verts[], int rows, int cols) {
>>>>>>> miniblink49
    if (rows < 2 || cols < 2) {
        return false;
    }

    const SkScalar invR = SkScalarInvert(SkIntToScalar(rows - 1));
    const SkScalar invC = SkScalarInvert(SkIntToScalar(cols - 1));

    for (int y = 0; y < cols; y++) {
        SkScalar yy = y * invC;
        for (int x = 0; x < rows; x++) {
            *verts++ = this->eval(x * invR, yy);
        }
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

#include "SkGeometry.h"

<<<<<<< HEAD
SkPoint SkLineBoundary::eval(Edge e, SkScalar t)
{
=======
SkPoint SkLineBoundary::eval(Edge e, SkScalar t) {
>>>>>>> miniblink49
    SkASSERT((unsigned)e < 4);
    return SkPointInterp(fPts[e], fPts[(e + 1) & 3], t);
}

<<<<<<< HEAD
SkPoint SkCubicBoundary::eval(Edge e, SkScalar t)
{
=======
SkPoint SkCubicBoundary::eval(Edge e, SkScalar t) {
>>>>>>> miniblink49
    SkASSERT((unsigned)e < 4);

    // ensure our 4th cubic wraps to the start of the first
    fPts[12] = fPts[0];

    SkPoint loc;
<<<<<<< HEAD
    SkEvalCubicAt(&fPts[e * 3], t, &loc, nullptr, nullptr);
=======
    SkEvalCubicAt(&fPts[e * 3], t, &loc, NULL, NULL);
>>>>>>> miniblink49
    return loc;
}
