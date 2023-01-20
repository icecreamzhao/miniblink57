/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkPathOpsQuad_DEFINED
#define SkPathOpsQuad_DEFINED

#include "SkPathOpsPoint.h"

struct SkOpCurve;

struct SkDQuadPair {
<<<<<<< HEAD
    const SkDQuad& first() const { return (const SkDQuad&)pts[0]; }
    const SkDQuad& second() const { return (const SkDQuad&)pts[2]; }
=======
    const SkDQuad& first() const { return (const SkDQuad&) pts[0]; }
    const SkDQuad& second() const { return (const SkDQuad&) pts[2]; }
>>>>>>> miniblink49
    SkDPoint pts[5];
};

struct SkDQuad {
    static const int kPointCount = 3;
    static const int kPointLast = kPointCount - 1;
    static const int kMaxIntersections = 4;

    SkDPoint fPts[kPointCount];

<<<<<<< HEAD
    bool collapsed() const
    {
        return fPts[0].approximatelyEqual(fPts[1]) && fPts[0].approximatelyEqual(fPts[2]);
    }

    bool controlsInside() const
    {
=======
    bool collapsed() const {
        return fPts[0].approximatelyEqual(fPts[1]) && fPts[0].approximatelyEqual(fPts[2]);
    }

    bool controlsInside() const {
>>>>>>> miniblink49
        SkDVector v01 = fPts[0] - fPts[1];
        SkDVector v02 = fPts[0] - fPts[2];
        SkDVector v12 = fPts[1] - fPts[2];
        return v02.dot(v01) > 0 && v02.dot(v12) > 0;
    }

<<<<<<< HEAD
    void debugInit()
    {
        sk_bzero(fPts, sizeof(fPts));
    }

    SkDQuad flip() const
    {
        SkDQuad result = { { fPts[2], fPts[1], fPts[0] } };
        return result;
    }

    static bool IsConic() { return false; }

    const SkDQuad& set(const SkPoint pts[kPointCount])
    {
=======
    void debugInit() {
        sk_bzero(fPts, sizeof(fPts));
    }

    SkDQuad flip() const {
        SkDQuad result = {{fPts[2], fPts[1], fPts[0]}};
        return result;
    }

    static bool IsCubic() { return false; }

    const SkDQuad& set(const SkPoint pts[kPointCount]) {
>>>>>>> miniblink49
        fPts[0] = pts[0];
        fPts[1] = pts[1];
        fPts[2] = pts[2];
        return *this;
    }

<<<<<<< HEAD
    const SkDPoint& operator[](int n) const
    {
        SkASSERT(n >= 0 && n < kPointCount);
        return fPts[n];
    }
    SkDPoint& operator[](int n)
    {
        SkASSERT(n >= 0 && n < kPointCount);
        return fPts[n];
    }
=======
    const SkDPoint& operator[](int n) const { SkASSERT(n >= 0 && n < kPointCount); return fPts[n]; }
    SkDPoint& operator[](int n) { SkASSERT(n >= 0 && n < kPointCount); return fPts[n]; }
>>>>>>> miniblink49

    static int AddValidTs(double s[], int realRoots, double* t);
    void align(int endIndex, SkDPoint* dstPt) const;
    SkDQuadPair chopAt(double t) const;
    SkDVector dxdyAtT(double t) const;
    static int FindExtrema(const double src[], double tValue[1]);
<<<<<<< HEAD

    /**
     *  Return the number of valid roots (0 < root < 1) for this cubic intersecting the
     *  specified horizontal line.
     */
    int horizontalIntersect(double yIntercept, double roots[2]) const;

    bool hullIntersects(const SkDQuad&, bool* isLinear) const;
    bool hullIntersects(const SkDConic&, bool* isLinear) const;
    bool hullIntersects(const SkDCubic&, bool* isLinear) const;
=======
    bool hullIntersects(const SkDQuad& , bool* isLinear) const;
    bool hullIntersects(const SkDConic& , bool* isLinear) const;
    bool hullIntersects(const SkDCubic& , bool* isLinear) const;
>>>>>>> miniblink49
    bool isLinear(int startIndex, int endIndex) const;
    bool monotonicInX() const;
    bool monotonicInY() const;
    void otherPts(int oddMan, const SkDPoint* endPt[2]) const;
    SkDPoint ptAtT(double t) const;
    static int RootsReal(double A, double B, double C, double t[2]);
    static int RootsValidT(const double A, const double B, const double C, double s[2]);
    static void SetABC(const double* quad, double* a, double* b, double* c);
    SkDQuad subDivide(double t1, double t2) const;
<<<<<<< HEAD
    static SkDQuad SubDivide(const SkPoint a[kPointCount], double t1, double t2)
    {
=======
    static SkDQuad SubDivide(const SkPoint a[kPointCount], double t1, double t2) {
>>>>>>> miniblink49
        SkDQuad quad;
        quad.set(a);
        return quad.subDivide(t1, t2);
    }
    SkDPoint subDivide(const SkDPoint& a, const SkDPoint& c, double t1, double t2) const;
    static SkDPoint SubDivide(const SkPoint pts[kPointCount], const SkDPoint& a, const SkDPoint& c,
<<<<<<< HEAD
        double t1, double t2)
    {
=======
                              double t1, double t2) {
>>>>>>> miniblink49
        SkDQuad quad;
        quad.set(pts);
        return quad.subDivide(a, c, t1, t2);
    }

<<<<<<< HEAD
    /**
     *  Return the number of valid roots (0 < root < 1) for this cubic intersecting the
     *  specified vertical line.
     */
    int verticalIntersect(double xIntercept, double roots[2]) const;

=======
>>>>>>> miniblink49
    SkDCubic debugToCubic() const;
    // utilities callable by the user from the debugger when the implementation code is linked in
    void dump() const;
    void dumpID(int id) const;
    void dumpInner() const;

private:
<<<<<<< HEAD
    //  static double Tangent(const double* quadratic, double t);  // uncalled
=======
//  static double Tangent(const double* quadratic, double t);  // uncalled
>>>>>>> miniblink49
};

#endif
