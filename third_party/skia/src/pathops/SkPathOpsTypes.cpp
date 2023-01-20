/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkPathOpsTypes.h"
#include "SkFloatBits.h"
#include "SkOpCoincidence.h"

static bool arguments_denormalized(float a, float b, int epsilon)
{
=======
#include "SkFloatBits.h"
#include "SkOpCoincidence.h"
#include "SkPathOpsTypes.h"

static bool arguments_denormalized(float a, float b, int epsilon) {
>>>>>>> miniblink49
    float denormalizedCheck = FLT_EPSILON * epsilon / 2;
    return fabsf(a) <= denormalizedCheck && fabsf(b) <= denormalizedCheck;
}

// from http://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
// FIXME: move to SkFloatBits.h
<<<<<<< HEAD
static bool equal_ulps(float a, float b, int epsilon, int depsilon)
{
    if (arguments_denormalized(a, b, depsilon)) {
        return true;
    }
    int aBits = SkFloatAs2sCompliment(a);
    int bBits = SkFloatAs2sCompliment(b);
    // Find the difference in ULPs.
    return aBits < bBits + epsilon && bBits < aBits + epsilon;
}

static bool equal_ulps_pin(float a, float b, int epsilon, int depsilon)
{
=======
static bool equal_ulps(float a, float b, int epsilon, int depsilon) {
>>>>>>> miniblink49
    if (!SkScalarIsFinite(a) || !SkScalarIsFinite(b)) {
        return false;
    }
    if (arguments_denormalized(a, b, depsilon)) {
        return true;
    }
    int aBits = SkFloatAs2sCompliment(a);
    int bBits = SkFloatAs2sCompliment(b);
    // Find the difference in ULPs.
    return aBits < bBits + epsilon && bBits < aBits + epsilon;
}

<<<<<<< HEAD
static bool d_equal_ulps(float a, float b, int epsilon)
{
=======
static bool d_equal_ulps(float a, float b, int epsilon) {
    if (!SkScalarIsFinite(a) || !SkScalarIsFinite(b)) {
        return false;
    }
>>>>>>> miniblink49
    int aBits = SkFloatAs2sCompliment(a);
    int bBits = SkFloatAs2sCompliment(b);
    // Find the difference in ULPs.
    return aBits < bBits + epsilon && bBits < aBits + epsilon;
}

<<<<<<< HEAD
static bool not_equal_ulps(float a, float b, int epsilon)
{
    if (arguments_denormalized(a, b, epsilon)) {
        return false;
    }
    int aBits = SkFloatAs2sCompliment(a);
    int bBits = SkFloatAs2sCompliment(b);
    // Find the difference in ULPs.
    return aBits >= bBits + epsilon || bBits >= aBits + epsilon;
}

static bool not_equal_ulps_pin(float a, float b, int epsilon)
{
=======
static bool not_equal_ulps(float a, float b, int epsilon) {
>>>>>>> miniblink49
    if (!SkScalarIsFinite(a) || !SkScalarIsFinite(b)) {
        return false;
    }
    if (arguments_denormalized(a, b, epsilon)) {
        return false;
    }
    int aBits = SkFloatAs2sCompliment(a);
    int bBits = SkFloatAs2sCompliment(b);
    // Find the difference in ULPs.
    return aBits >= bBits + epsilon || bBits >= aBits + epsilon;
}

<<<<<<< HEAD
static bool d_not_equal_ulps(float a, float b, int epsilon)
{
=======
static bool d_not_equal_ulps(float a, float b, int epsilon) {
    if (!SkScalarIsFinite(a) || !SkScalarIsFinite(b)) {
        return false;
    }
>>>>>>> miniblink49
    int aBits = SkFloatAs2sCompliment(a);
    int bBits = SkFloatAs2sCompliment(b);
    // Find the difference in ULPs.
    return aBits >= bBits + epsilon || bBits >= aBits + epsilon;
}

<<<<<<< HEAD
static bool less_ulps(float a, float b, int epsilon)
{
=======
static bool less_ulps(float a, float b, int epsilon) {
    if (!SkScalarIsFinite(a) || !SkScalarIsFinite(b)) {
        return false;
    }
>>>>>>> miniblink49
    if (arguments_denormalized(a, b, epsilon)) {
        return a <= b - FLT_EPSILON * epsilon;
    }
    int aBits = SkFloatAs2sCompliment(a);
    int bBits = SkFloatAs2sCompliment(b);
    // Find the difference in ULPs.
    return aBits <= bBits - epsilon;
}

<<<<<<< HEAD
static bool less_or_equal_ulps(float a, float b, int epsilon)
{
=======
static bool less_or_equal_ulps(float a, float b, int epsilon) {
    if (!SkScalarIsFinite(a) || !SkScalarIsFinite(b)) {
        return false;
    }
>>>>>>> miniblink49
    if (arguments_denormalized(a, b, epsilon)) {
        return a < b + FLT_EPSILON * epsilon;
    }
    int aBits = SkFloatAs2sCompliment(a);
    int bBits = SkFloatAs2sCompliment(b);
    // Find the difference in ULPs.
    return aBits < bBits + epsilon;
}

// equality using the same error term as between
<<<<<<< HEAD
bool AlmostBequalUlps(float a, float b)
{
=======
bool AlmostBequalUlps(float a, float b) {
>>>>>>> miniblink49
    const int UlpsEpsilon = 2;
    return equal_ulps(a, b, UlpsEpsilon, UlpsEpsilon);
}

<<<<<<< HEAD
bool AlmostPequalUlps(float a, float b)
{
=======
bool AlmostPequalUlps(float a, float b) {
>>>>>>> miniblink49
    const int UlpsEpsilon = 8;
    return equal_ulps(a, b, UlpsEpsilon, UlpsEpsilon);
}

<<<<<<< HEAD
bool AlmostDequalUlps(float a, float b)
{
=======
bool AlmostDequalUlps(float a, float b) {
>>>>>>> miniblink49
    const int UlpsEpsilon = 16;
    return d_equal_ulps(a, b, UlpsEpsilon);
}

<<<<<<< HEAD
bool AlmostDequalUlps(double a, double b)
{
    return AlmostDequalUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool AlmostEqualUlps(float a, float b)
{
=======
bool AlmostDequalUlps(double a, double b) {
    if (SkScalarIsFinite(a) || SkScalarIsFinite(b)) {
        return AlmostDequalUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
    }
    return fabs(a - b) / SkTMax(fabs(a), fabs(b)) < FLT_EPSILON * 16;
}

bool AlmostEqualUlps(float a, float b) {
>>>>>>> miniblink49
    const int UlpsEpsilon = 16;
    return equal_ulps(a, b, UlpsEpsilon, UlpsEpsilon);
}

<<<<<<< HEAD
bool AlmostEqualUlps_Pin(float a, float b)
{
    const int UlpsEpsilon = 16;
    return equal_ulps_pin(a, b, UlpsEpsilon, UlpsEpsilon);
}

bool NotAlmostEqualUlps(float a, float b)
{
=======
bool NotAlmostEqualUlps(float a, float b) {
>>>>>>> miniblink49
    const int UlpsEpsilon = 16;
    return not_equal_ulps(a, b, UlpsEpsilon);
}

<<<<<<< HEAD
bool NotAlmostEqualUlps_Pin(float a, float b)
{
    const int UlpsEpsilon = 16;
    return not_equal_ulps_pin(a, b, UlpsEpsilon);
}

bool NotAlmostDequalUlps(float a, float b)
{
=======
bool NotAlmostDequalUlps(float a, float b) {
>>>>>>> miniblink49
    const int UlpsEpsilon = 16;
    return d_not_equal_ulps(a, b, UlpsEpsilon);
}

<<<<<<< HEAD
bool RoughlyEqualUlps(float a, float b)
{
=======
bool RoughlyEqualUlps(float a, float b) {
>>>>>>> miniblink49
    const int UlpsEpsilon = 256;
    const int DUlpsEpsilon = 1024;
    return equal_ulps(a, b, UlpsEpsilon, DUlpsEpsilon);
}

<<<<<<< HEAD
bool AlmostBetweenUlps(float a, float b, float c)
{
    const int UlpsEpsilon = 2;
    return a <= c ? less_or_equal_ulps(a, b, UlpsEpsilon) && less_or_equal_ulps(b, c, UlpsEpsilon)
                  : less_or_equal_ulps(b, a, UlpsEpsilon) && less_or_equal_ulps(c, b, UlpsEpsilon);
}

bool AlmostLessUlps(float a, float b)
{
=======
bool AlmostBetweenUlps(float a, float b, float c) {
    const int UlpsEpsilon = 2;
    return a <= c ? less_or_equal_ulps(a, b, UlpsEpsilon) && less_or_equal_ulps(b, c, UlpsEpsilon)
        : less_or_equal_ulps(b, a, UlpsEpsilon) && less_or_equal_ulps(c, b, UlpsEpsilon);
}

bool AlmostLessUlps(float a, float b) {
>>>>>>> miniblink49
    const int UlpsEpsilon = 16;
    return less_ulps(a, b, UlpsEpsilon);
}

<<<<<<< HEAD
bool AlmostLessOrEqualUlps(float a, float b)
{
=======
bool AlmostLessOrEqualUlps(float a, float b) {
>>>>>>> miniblink49
    const int UlpsEpsilon = 16;
    return less_or_equal_ulps(a, b, UlpsEpsilon);
}

<<<<<<< HEAD
int UlpsDistance(float a, float b)
{
=======
int UlpsDistance(float a, float b) {
    if (!SkScalarIsFinite(a) || !SkScalarIsFinite(b)) {
        return SK_MaxS32;
    }
>>>>>>> miniblink49
    SkFloatIntUnion floatIntA, floatIntB;
    floatIntA.fFloat = a;
    floatIntB.fFloat = b;
    // Different signs means they do not match.
    if ((floatIntA.fSignBitInt < 0) != (floatIntB.fSignBitInt < 0)) {
        // Check for equality to make sure +0 == -0
        return a == b ? 0 : SK_MaxS32;
    }
    // Find the difference in ULPs.
<<<<<<< HEAD
    return SkTAbs(floatIntA.fSignBitInt - floatIntB.fSignBitInt);
=======
    return abs(floatIntA.fSignBitInt - floatIntB.fSignBitInt);
>>>>>>> miniblink49
}

// cube root approximation using bit hack for 64-bit float
// adapted from Kahan's cbrt
<<<<<<< HEAD
static double cbrt_5d(double d)
{
    const unsigned int B1 = 715094163;
    double t = 0.0;
    unsigned int* pt = (unsigned int*)&t;
    unsigned int* px = (unsigned int*)&d;
=======
static double cbrt_5d(double d) {
    const unsigned int B1 = 715094163;
    double t = 0.0;
    unsigned int* pt = (unsigned int*) &t;
    unsigned int* px = (unsigned int*) &d;
>>>>>>> miniblink49
    pt[1] = px[1] / 3 + B1;
    return t;
}

// iterative cube root approximation using Halley's method (double)
<<<<<<< HEAD
static double cbrta_halleyd(const double a, const double R)
{
=======
static double cbrta_halleyd(const double a, const double R) {
>>>>>>> miniblink49
    const double a3 = a * a * a;
    const double b = a * (a3 + R + R) / (a3 + a3 + R);
    return b;
}

// cube root approximation using 3 iterations of Halley's method (double)
<<<<<<< HEAD
static double halley_cbrt3d(double d)
{
=======
static double halley_cbrt3d(double d) {
>>>>>>> miniblink49
    double a = cbrt_5d(d);
    a = cbrta_halleyd(a, d);
    a = cbrta_halleyd(a, d);
    return cbrta_halleyd(a, d);
}

<<<<<<< HEAD
double SkDCubeRoot(double x)
{
=======
double SkDCubeRoot(double x) {
>>>>>>> miniblink49
    if (approximately_zero_cubed(x)) {
        return 0;
    }
    double result = halley_cbrt3d(fabs(x));
    if (x < 0) {
        result = -result;
    }
    return result;
}

<<<<<<< HEAD
SkOpGlobalState::SkOpGlobalState(SkOpCoincidence* coincidence, SkOpContourHead* head SkDEBUGPARAMS(bool debugSkipAssert) SkDEBUGPARAMS(const char* testName))
=======
SkOpGlobalState::SkOpGlobalState(SkOpCoincidence* coincidence, SkOpContourHead* head)
>>>>>>> miniblink49
    : fCoincidence(coincidence)
    , fContourHead(head)
    , fNested(0)
    , fWindingFailed(false)
    , fAngleCoincidence(false)
    , fPhase(kIntersecting)
<<<<<<< HEAD
          SkDEBUGPARAMS(fDebugTestName(testName))
              SkDEBUGPARAMS(fAngleID(0))
                  SkDEBUGPARAMS(fCoinID(0))
                      SkDEBUGPARAMS(fContourID(0))
                          SkDEBUGPARAMS(fPtTID(0))
                              SkDEBUGPARAMS(fSegmentID(0))
                                  SkDEBUGPARAMS(fSpanID(0))
                                      SkDEBUGPARAMS(fDebugSkipAssert(debugSkipAssert))
{
    if (coincidence) {
        coincidence->debugSetGlobalState(this);
    }
#if DEBUG_T_SECT_LOOP_COUNT
    debugResetLoopCounts();
#endif
}
=======
    SkDEBUGPARAMS(fAngleID(0))
    SkDEBUGPARAMS(fContourID(0))
    SkDEBUGPARAMS(fPtTID(0))
    SkDEBUGPARAMS(fSegmentID(0))
    SkDEBUGPARAMS(fSpanID(0)) {
    if (coincidence) {
        coincidence->debugSetGlobalState(this);
    }
}

>>>>>>> miniblink49
