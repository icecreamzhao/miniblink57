/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkLineParameters_DEFINED
#define SkLineParameters_DEFINED

#include "SkPathOpsCubic.h"
#include "SkPathOpsLine.h"
#include "SkPathOpsQuad.h"

// Sources
// computer-aided design - volume 22 number 9 november 1990 pp 538 - 549
// online at http://cagd.cs.byu.edu/~tom/papers/bezclip.pdf

// This turns a line segment into a parameterized line, of the form
// ax + by + c = 0
// When a^2 + b^2 == 1, the line is normalized.
// The distance to the line for (x, y) is d(x,y) = ax + by + c
//
// Note that the distances below are not necessarily normalized. To get the true
// distance, it's necessary to either call normalize() after xxxEndPoints(), or
// divide the result of xxxDistance() by sqrt(normalSquared())

class SkLineParameters {
public:
<<<<<<< HEAD
    bool cubicEndPoints(const SkDCubic& pts)
    {
=======

    bool cubicEndPoints(const SkDCubic& pts) {
>>>>>>> miniblink49
        int endIndex = 1;
        cubicEndPoints(pts, 0, endIndex);
        if (dy() != 0) {
            return true;
        }
        if (dx() == 0) {
            cubicEndPoints(pts, 0, ++endIndex);
            SkASSERT(endIndex == 2);
            if (dy() != 0) {
                return true;
            }
            if (dx() == 0) {
<<<<<<< HEAD
                cubicEndPoints(pts, 0, ++endIndex); // line
=======
                cubicEndPoints(pts, 0, ++endIndex);  // line
>>>>>>> miniblink49
                SkASSERT(endIndex == 3);
                return false;
            }
        }
        // FIXME: after switching to round sort, remove bumping fA
        if (dx() < 0) { // only worry about y bias when breaking cw/ccw tie
            return true;
        }
        // if cubic tangent is on x axis, look at next control point to break tie
        // control point may be approximate, so it must move significantly to account for error
        if (NotAlmostEqualUlps(pts[0].fY, pts[++endIndex].fY)) {
            if (pts[0].fY > pts[endIndex].fY) {
                fA = DBL_EPSILON; // push it from 0 to slightly negative (y() returns -a)
            }
            return true;
        }
        if (endIndex == 3) {
            return true;
        }
        SkASSERT(endIndex == 2);
        if (pts[0].fY > pts[3].fY) {
            fA = DBL_EPSILON; // push it from 0 to slightly negative (y() returns -a)
        }
        return true;
    }

<<<<<<< HEAD
    void cubicEndPoints(const SkDCubic& pts, int s, int e)
    {
=======
    void cubicEndPoints(const SkDCubic& pts, int s, int e) {
>>>>>>> miniblink49
        fA = pts[s].fY - pts[e].fY;
        fB = pts[e].fX - pts[s].fX;
        fC = pts[s].fX * pts[e].fY - pts[e].fX * pts[s].fY;
    }

<<<<<<< HEAD
    double cubicPart(const SkDCubic& part)
    {
        cubicEndPoints(part);
        if (part[0] == part[1] || ((const SkDLine&)part[0]).nearRay(part[2])) {
=======
    double cubicPart(const SkDCubic& part) {
        cubicEndPoints(part);
        if (part[0] == part[1] || ((const SkDLine& ) part[0]).nearRay(part[2])) {
>>>>>>> miniblink49
            return pointDistance(part[3]);
        }
        return pointDistance(part[2]);
    }

<<<<<<< HEAD
    void lineEndPoints(const SkDLine& pts)
    {
=======
    void lineEndPoints(const SkDLine& pts) {
>>>>>>> miniblink49
        fA = pts[0].fY - pts[1].fY;
        fB = pts[1].fX - pts[0].fX;
        fC = pts[0].fX * pts[1].fY - pts[1].fX * pts[0].fY;
    }

<<<<<<< HEAD
    bool quadEndPoints(const SkDQuad& pts)
    {
=======
    bool quadEndPoints(const SkDQuad& pts) {
>>>>>>> miniblink49
        quadEndPoints(pts, 0, 1);
        if (dy() != 0) {
            return true;
        }
        if (dx() == 0) {
            quadEndPoints(pts, 0, 2);
            return false;
        }
        if (dx() < 0) { // only worry about y bias when breaking cw/ccw tie
            return true;
        }
        // FIXME: after switching to round sort, remove this
        if (pts[0].fY > pts[2].fY) {
            fA = DBL_EPSILON;
        }
        return true;
    }

<<<<<<< HEAD
    void quadEndPoints(const SkDQuad& pts, int s, int e)
    {
=======
    void quadEndPoints(const SkDQuad& pts, int s, int e) {
>>>>>>> miniblink49
        fA = pts[s].fY - pts[e].fY;
        fB = pts[e].fX - pts[s].fX;
        fC = pts[s].fX * pts[e].fY - pts[e].fX * pts[s].fY;
    }

<<<<<<< HEAD
    double quadPart(const SkDQuad& part)
    {
=======
    double quadPart(const SkDQuad& part) {
>>>>>>> miniblink49
        quadEndPoints(part);
        return pointDistance(part[2]);
    }

<<<<<<< HEAD
    double normalSquared() const
    {
        return fA * fA + fB * fB;
    }

    bool normalize()
    {
=======
    double normalSquared() const {
        return fA * fA + fB * fB;
    }

    bool normalize() {
>>>>>>> miniblink49
        double normal = sqrt(normalSquared());
        if (approximately_zero(normal)) {
            fA = fB = fC = 0;
            return false;
        }
        double reciprocal = 1 / normal;
        fA *= reciprocal;
        fB *= reciprocal;
        fC *= reciprocal;
        return true;
    }

<<<<<<< HEAD
    void cubicDistanceY(const SkDCubic& pts, SkDCubic& distance) const
    {
=======
    void cubicDistanceY(const SkDCubic& pts, SkDCubic& distance) const {
>>>>>>> miniblink49
        double oneThird = 1 / 3.0;
        for (int index = 0; index < 4; ++index) {
            distance[index].fX = index * oneThird;
            distance[index].fY = fA * pts[index].fX + fB * pts[index].fY + fC;
        }
    }

<<<<<<< HEAD
    void quadDistanceY(const SkDQuad& pts, SkDQuad& distance) const
    {
=======
    void quadDistanceY(const SkDQuad& pts, SkDQuad& distance) const {
>>>>>>> miniblink49
        double oneHalf = 1 / 2.0;
        for (int index = 0; index < 3; ++index) {
            distance[index].fX = index * oneHalf;
            distance[index].fY = fA * pts[index].fX + fB * pts[index].fY + fC;
        }
    }

<<<<<<< HEAD
    double controlPtDistance(const SkDCubic& pts, int index) const
    {
=======
    double controlPtDistance(const SkDCubic& pts, int index) const {
>>>>>>> miniblink49
        SkASSERT(index == 1 || index == 2);
        return fA * pts[index].fX + fB * pts[index].fY + fC;
    }

<<<<<<< HEAD
    double controlPtDistance(const SkDQuad& pts) const
    {
        return fA * pts[1].fX + fB * pts[1].fY + fC;
    }

    double pointDistance(const SkDPoint& pt) const
    {
        return fA * pt.fX + fB * pt.fY + fC;
    }

    double dx() const
    {
        return fB;
    }

    double dy() const
    {
=======
    double controlPtDistance(const SkDQuad& pts) const {
        return fA * pts[1].fX + fB * pts[1].fY + fC;
    }

    double pointDistance(const SkDPoint& pt) const {
        return fA * pt.fX + fB * pt.fY + fC;
    }

    double dx() const {
        return fB;
    }

    double dy() const {
>>>>>>> miniblink49
        return -fA;
    }

private:
    double fA;
    double fB;
    double fC;
};

#endif
