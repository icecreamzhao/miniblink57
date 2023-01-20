/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkPathOpsPoint_DEFINED
#define SkPathOpsPoint_DEFINED

#include "SkPathOpsTypes.h"
#include "SkPoint.h"

<<<<<<< HEAD
inline bool AlmostEqualUlps(const SkPoint& pt1, const SkPoint& pt2)
{
=======
inline bool AlmostEqualUlps(const SkPoint& pt1, const SkPoint& pt2) {
>>>>>>> miniblink49
    return AlmostEqualUlps(pt1.fX, pt2.fX) && AlmostEqualUlps(pt1.fY, pt2.fY);
}

struct SkDVector {
    double fX;
    double fY;

<<<<<<< HEAD
    void set(const SkVector& pt)
    {
=======
    void set(const SkVector& pt) {
>>>>>>> miniblink49
        fX = pt.fX;
        fY = pt.fY;
    }

    // only used by testing
<<<<<<< HEAD
    void operator+=(const SkDVector& v)
    {
=======
    void operator+=(const SkDVector& v) {
>>>>>>> miniblink49
        fX += v.fX;
        fY += v.fY;
    }

    // only called by nearestT, which is currently only used by testing
<<<<<<< HEAD
    void operator-=(const SkDVector& v)
    {
=======
    void operator-=(const SkDVector& v) {
>>>>>>> miniblink49
        fX -= v.fX;
        fY -= v.fY;
    }

    // only used by testing
<<<<<<< HEAD
    void operator/=(const double s)
    {
=======
    void operator/=(const double s) {
>>>>>>> miniblink49
        fX /= s;
        fY /= s;
    }

    // only used by testing
<<<<<<< HEAD
    void operator*=(const double s)
    {
=======
    void operator*=(const double s) {
>>>>>>> miniblink49
        fX *= s;
        fY *= s;
    }

<<<<<<< HEAD
    SkVector asSkVector() const
    {
        SkVector v = { SkDoubleToScalar(fX), SkDoubleToScalar(fY) };
=======
    SkVector asSkVector() const {
        SkVector v = {SkDoubleToScalar(fX), SkDoubleToScalar(fY)};
>>>>>>> miniblink49
        return v;
    }

    // only used by testing
<<<<<<< HEAD
    double cross(const SkDVector& a) const
    {
=======
    double cross(const SkDVector& a) const {
>>>>>>> miniblink49
        return fX * a.fY - fY * a.fX;
    }

    // similar to cross, this bastardization considers nearly coincident to be zero
<<<<<<< HEAD
    double crossCheck(const SkDVector& a) const
    {
=======
    double crossCheck(const SkDVector& a) const {
>>>>>>> miniblink49
        double xy = fX * a.fY;
        double yx = fY * a.fX;
        return AlmostEqualUlps(xy, yx) ? 0 : xy - yx;
    }

<<<<<<< HEAD
    double dot(const SkDVector& a) const
    {
        return fX * a.fX + fY * a.fY;
    }

    double length() const
    {
        return sqrt(lengthSquared());
    }

    double lengthSquared() const
    {
=======
    double dot(const SkDVector& a) const {
        return fX * a.fX + fY * a.fY;
    }

    double length() const {
        return sqrt(lengthSquared());
    }

    double lengthSquared() const {
>>>>>>> miniblink49
        return fX * fX + fY * fY;
    }
};

struct SkDPoint {
    double fX;
    double fY;

<<<<<<< HEAD
    void set(const SkPoint& pt)
    {
=======
    void set(const SkPoint& pt) {
>>>>>>> miniblink49
        fX = pt.fX;
        fY = pt.fY;
    }

    friend SkDVector operator-(const SkDPoint& a, const SkDPoint& b);

<<<<<<< HEAD
    friend bool operator==(const SkDPoint& a, const SkDPoint& b)
    {
        return a.fX == b.fX && a.fY == b.fY;
    }

    friend bool operator!=(const SkDPoint& a, const SkDPoint& b)
    {
        return a.fX != b.fX || a.fY != b.fY;
    }

    void operator=(const SkPoint& pt)
    {
=======
    friend bool operator==(const SkDPoint& a, const SkDPoint& b) {
        return a.fX == b.fX && a.fY == b.fY;
    }

    friend bool operator!=(const SkDPoint& a, const SkDPoint& b) {
        return a.fX != b.fX || a.fY != b.fY;
    }

    void operator=(const SkPoint& pt) {
>>>>>>> miniblink49
        fX = pt.fX;
        fY = pt.fY;
    }

    // only used by testing
<<<<<<< HEAD
    void operator+=(const SkDVector& v)
    {
=======
    void operator+=(const SkDVector& v) {
>>>>>>> miniblink49
        fX += v.fX;
        fY += v.fY;
    }

    // only used by testing
<<<<<<< HEAD
    void operator-=(const SkDVector& v)
    {
=======
    void operator-=(const SkDVector& v) {
>>>>>>> miniblink49
        fX -= v.fX;
        fY -= v.fY;
    }

    // only used by testing
<<<<<<< HEAD
    SkDPoint operator+(const SkDVector& v)
    {
=======
    SkDPoint operator+(const SkDVector& v) {
>>>>>>> miniblink49
        SkDPoint result = *this;
        result += v;
        return result;
    }

    // only used by testing
<<<<<<< HEAD
    SkDPoint operator-(const SkDVector& v)
    {
=======
    SkDPoint operator-(const SkDVector& v) {
>>>>>>> miniblink49
        SkDPoint result = *this;
        result -= v;
        return result;
    }

    // note: this can not be implemented with
    // return approximately_equal(a.fY, fY) && approximately_equal(a.fX, fX);
    // because that will not take the magnitude of the values into account
<<<<<<< HEAD
    bool approximatelyEqual(const SkDPoint& a) const
    {
=======
    bool approximatelyEqual(const SkDPoint& a) const {
>>>>>>> miniblink49
        if (approximately_equal(fX, a.fX) && approximately_equal(fY, a.fY)) {
            return true;
        }
        if (!RoughlyEqualUlps(fX, a.fX) || !RoughlyEqualUlps(fY, a.fY)) {
            return false;
        }
<<<<<<< HEAD
        double dist = distance(a); // OPTIMIZATION: can we compare against distSq instead ?
=======
        double dist = distance(a);  // OPTIMIZATION: can we compare against distSq instead ?
>>>>>>> miniblink49
        double tiniest = SkTMin(SkTMin(SkTMin(fX, a.fX), fY), a.fY);
        double largest = SkTMax(SkTMax(SkTMax(fX, a.fX), fY), a.fY);
        largest = SkTMax(largest, -tiniest);
        return AlmostPequalUlps(largest, largest + dist); // is the dist within ULPS tolerance?
    }

<<<<<<< HEAD
    bool approximatelyEqual(const SkPoint& a) const
    {
=======
    bool approximatelyEqual(const SkPoint& a) const {
>>>>>>> miniblink49
        SkDPoint dA;
        dA.set(a);
        return approximatelyEqual(dA);
    }

<<<<<<< HEAD
    static bool ApproximatelyEqual(const SkPoint& a, const SkPoint& b)
    {
=======
    static bool ApproximatelyEqual(const SkPoint& a, const SkPoint& b) {
>>>>>>> miniblink49
        if (approximately_equal(a.fX, b.fX) && approximately_equal(a.fY, b.fY)) {
            return true;
        }
        if (!RoughlyEqualUlps(a.fX, b.fX) || !RoughlyEqualUlps(a.fY, b.fY)) {
            return false;
        }
        SkDPoint dA, dB;
        dA.set(a);
        dB.set(b);
<<<<<<< HEAD
        double dist = dA.distance(dB); // OPTIMIZATION: can we compare against distSq instead ?
        float tiniest = SkTMin(SkTMin(SkTMin(a.fX, b.fX), a.fY), b.fY);
        float largest = SkTMax(SkTMax(SkTMax(a.fX, b.fX), a.fY), b.fY);
        largest = SkTMax(largest, -tiniest);
        return AlmostPequalUlps((double)largest, largest + dist); // is dist within ULPS tolerance?
    }

    // only used by testing
    bool approximatelyZero() const
    {
        return approximately_zero(fX) && approximately_zero(fY);
    }

    SkPoint asSkPoint() const
    {
        SkPoint pt = { SkDoubleToScalar(fX), SkDoubleToScalar(fY) };
        return pt;
    }

    double distance(const SkDPoint& a) const
    {
=======
        double dist = dA.distance(dB);  // OPTIMIZATION: can we compare against distSq instead ?
        float tiniest = SkTMin(SkTMin(SkTMin(a.fX, b.fX), a.fY), b.fY);
        float largest = SkTMax(SkTMax(SkTMax(a.fX, b.fX), a.fY), b.fY);
        largest = SkTMax(largest, -tiniest);
        return AlmostPequalUlps((double) largest, largest + dist); // is dist within ULPS tolerance?
    }

    // only used by testing
    bool approximatelyZero() const {
        return approximately_zero(fX) && approximately_zero(fY);
    }

    SkPoint asSkPoint() const {
        SkPoint pt = {SkDoubleToScalar(fX), SkDoubleToScalar(fY)};
        return pt;
    }

    double distance(const SkDPoint& a) const {
>>>>>>> miniblink49
        SkDVector temp = *this - a;
        return temp.length();
    }

<<<<<<< HEAD
    double distanceSquared(const SkDPoint& a) const
    {
=======
    double distanceSquared(const SkDPoint& a) const {
>>>>>>> miniblink49
        SkDVector temp = *this - a;
        return temp.lengthSquared();
    }

<<<<<<< HEAD
    static SkDPoint Mid(const SkDPoint& a, const SkDPoint& b)
    {
=======
    static SkDPoint Mid(const SkDPoint& a, const SkDPoint& b) {
>>>>>>> miniblink49
        SkDPoint result;
        result.fX = (a.fX + b.fX) / 2;
        result.fY = (a.fY + b.fY) / 2;
        return result;
    }

<<<<<<< HEAD
    bool roughlyEqual(const SkDPoint& a) const
    {
        if (roughly_equal(fX, a.fX) && roughly_equal(fY, a.fY)) {
            return true;
        }
        double dist = distance(a); // OPTIMIZATION: can we compare against distSq instead ?
=======
    bool roughlyEqual(const SkDPoint& a) const {
        if (roughly_equal(fX, a.fX) && roughly_equal(fY, a.fY)) {
            return true;
        }
        double dist = distance(a);  // OPTIMIZATION: can we compare against distSq instead ?
>>>>>>> miniblink49
        double tiniest = SkTMin(SkTMin(SkTMin(fX, a.fX), fY), a.fY);
        double largest = SkTMax(SkTMax(SkTMax(fX, a.fX), fY), a.fY);
        largest = SkTMax(largest, -tiniest);
        return RoughlyEqualUlps(largest, largest + dist); // is the dist within ULPS tolerance?
    }

<<<<<<< HEAD
    static bool RoughlyEqual(const SkPoint& a, const SkPoint& b)
    {
=======
    static bool RoughlyEqual(const SkPoint& a, const SkPoint& b) {
>>>>>>> miniblink49
        if (!RoughlyEqualUlps(a.fX, b.fX) && !RoughlyEqualUlps(a.fY, b.fY)) {
            return false;
        }
        SkDPoint dA, dB;
        dA.set(a);
        dB.set(b);
<<<<<<< HEAD
        double dist = dA.distance(dB); // OPTIMIZATION: can we compare against distSq instead ?
        float tiniest = SkTMin(SkTMin(SkTMin(a.fX, b.fX), a.fY), b.fY);
        float largest = SkTMax(SkTMax(SkTMax(a.fX, b.fX), a.fY), b.fY);
        largest = SkTMax(largest, -tiniest);
        return RoughlyEqualUlps((double)largest, largest + dist); // is dist within ULPS tolerance?
=======
        double dist = dA.distance(dB);  // OPTIMIZATION: can we compare against distSq instead ?
        float tiniest = SkTMin(SkTMin(SkTMin(a.fX, b.fX), a.fY), b.fY);
        float largest = SkTMax(SkTMax(SkTMax(a.fX, b.fX), a.fY), b.fY);
        largest = SkTMax(largest, -tiniest);
        return RoughlyEqualUlps((double) largest, largest + dist); // is dist within ULPS tolerance?
>>>>>>> miniblink49
    }

    // utilities callable by the user from the debugger when the implementation code is linked in
    void dump() const;
    static void Dump(const SkPoint& pt);
    static void DumpHex(const SkPoint& pt);
};

#endif
