/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkPathOpsLine_DEFINED
#define SkPathOpsLine_DEFINED

#include "SkPathOpsPoint.h"

struct SkDLine {
    SkDPoint fPts[2];

<<<<<<< HEAD
    const SkDPoint& operator[](int n) const
    {
        SkASSERT(n >= 0 && n < 2);
        return fPts[n];
    }
    SkDPoint& operator[](int n)
    {
        SkASSERT(n >= 0 && n < 2);
        return fPts[n];
    }

    const SkDLine& set(const SkPoint pts[2])
    {
=======
    const SkDPoint& operator[](int n) const { SkASSERT(n >= 0 && n < 2); return fPts[n]; }
    SkDPoint& operator[](int n) { SkASSERT(n >= 0 && n < 2); return fPts[n]; }

    const SkDLine& set(const SkPoint pts[2]) {
>>>>>>> miniblink49
        fPts[0] = pts[0];
        fPts[1] = pts[1];
        return *this;
    }

    double exactPoint(const SkDPoint& xy) const;
    static double ExactPointH(const SkDPoint& xy, double left, double right, double y);
    static double ExactPointV(const SkDPoint& xy, double top, double bottom, double x);

<<<<<<< HEAD
=======
    // only used by testing
    double isLeft(const SkDPoint& pt) const;

>>>>>>> miniblink49
    double nearPoint(const SkDPoint& xy, bool* unequal) const;
    bool nearRay(const SkDPoint& xy) const;
    static double NearPointH(const SkDPoint& xy, double left, double right, double y);
    static double NearPointV(const SkDPoint& xy, double top, double bottom, double x);
    SkDPoint ptAtT(double t) const;

    void dump() const;
<<<<<<< HEAD
    void dumpID(int) const;
=======
    void dumpID(int ) const;
>>>>>>> miniblink49
    void dumpInner() const;
};

#endif
