/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkPathOpsTypes_DEFINED
#define SkPathOpsTypes_DEFINED

<<<<<<< HEAD
#include <float.h> // for FLT_EPSILON
#include <math.h> // for fabs, sqrt
=======
#include <float.h>  // for FLT_EPSILON
#include <math.h>   // for fabs, sqrt
>>>>>>> miniblink49

#include "SkFloatingPoint.h"
#include "SkPath.h"
#include "SkPathOps.h"
#include "SkPathOpsDebug.h"
#include "SkScalar.h"

enum SkPathOpsMask {
    kWinding_PathOpsMask = -1,
    kNo_PathOpsMask = 0,
    kEvenOdd_PathOpsMask = 1
};

class SkOpCoincidence;
class SkOpContour;
class SkOpContourHead;
<<<<<<< HEAD
class SkIntersections;
class SkIntersectionHelper;

class SkOpGlobalState {
public:
    SkOpGlobalState(SkOpCoincidence* coincidence, SkOpContourHead* head SkDEBUGPARAMS(bool debugSkipAssert) SkDEBUGPARAMS(const char* testName));
=======

class SkOpGlobalState {
public:
    SkOpGlobalState(SkOpCoincidence* coincidence, SkOpContourHead* head);
>>>>>>> miniblink49

    enum Phase {
        kIntersecting,
        kWalking,
        kFixWinding,
    };

    enum {
        kMaxWindingTries = 10
    };

<<<<<<< HEAD
    bool angleCoincidence() const
    {
        return fAngleCoincidence;
    }

    void bumpNested()
    {
        ++fNested;
    }

    void clearNested()
    {
        fNested = 0;
    }

    SkOpCoincidence* coincidence()
    {
        return fCoincidence;
    }

    SkOpContourHead* contourHead()
    {
=======
    bool angleCoincidence() {
        return fAngleCoincidence;
    }

    void bumpNested() {
        ++fNested;
    }

    void clearNested() {
        fNested = 0;
    }

    SkOpCoincidence* coincidence() {
        return fCoincidence;
    }

    SkOpContourHead* contourHead() {
>>>>>>> miniblink49
        return fContourHead;
    }

#ifdef SK_DEBUG
    const struct SkOpAngle* debugAngle(int id) const;
    SkOpContour* debugContour(int id);
    const class SkOpPtT* debugPtT(int id) const;
    bool debugRunFail() const;
    const class SkOpSegment* debugSegment(int id) const;
<<<<<<< HEAD
    bool debugSkipAssert() const { return fDebugSkipAssert; }
    const class SkOpSpanBase* debugSpan(int id) const;
    const char* debugTestName() const { return fDebugTestName; }
#endif

#if DEBUG_T_SECT_LOOP_COUNT
    void debugAddLoopCount(SkIntersections*, const SkIntersectionHelper&,
        const SkIntersectionHelper&);
    void debugDoYourWorst(SkOpGlobalState*);
    void debugLoopReport();
    void debugResetLoopCounts();
#endif

    int nested() const
    {
=======
    const class SkOpSpanBase* debugSpan(int id) const;
#endif

    int nested() const {
>>>>>>> miniblink49
        return fNested;
    }

#ifdef SK_DEBUG
<<<<<<< HEAD
    int nextAngleID()
    {
        return ++fAngleID;
    }

    int nextCoinID()
    {
        return ++fCoinID;
    }

    int nextContourID()
    {
        return ++fContourID;
    }

    int nextPtTID()
    {
        return ++fPtTID;
    }

    int nextSegmentID()
    {
        return ++fSegmentID;
    }

    int nextSpanID()
    {
=======
    int nextAngleID() {
        return ++fAngleID;
    }

    int nextContourID() {
        return ++fContourID;
    }
    int nextPtTID() {
        return ++fPtTID;
    }

    int nextSegmentID() {
        return ++fSegmentID;
    }

    int nextSpanID() {
>>>>>>> miniblink49
        return ++fSpanID;
    }
#endif

<<<<<<< HEAD
    Phase phase() const
    {
        return fPhase;
    }

    void setAngleCoincidence()
    {
        fAngleCoincidence = true;
    }

    void setContourHead(SkOpContourHead* contourHead)
    {
        fContourHead = contourHead;
    }

    void setPhase(Phase phase)
    {
=======
    Phase phase() const {
        return fPhase;
    }

    void setAngleCoincidence() {
        fAngleCoincidence = true;
    }
    
    void setContourHead(SkOpContourHead* contourHead) {
        fContourHead = contourHead;
    }

    void setPhase(Phase phase) {
>>>>>>> miniblink49
        SkASSERT(fPhase != phase);
        fPhase = phase;
    }

    // called in very rare cases where angles are sorted incorrectly -- signfies op will fail
<<<<<<< HEAD
    void setWindingFailed()
    {
        fWindingFailed = true;
    }

    bool windingFailed() const
    {
=======
    void setWindingFailed() {
        fWindingFailed = true;
    }

    bool windingFailed() const {
>>>>>>> miniblink49
        return fWindingFailed;
    }

private:
    SkOpCoincidence* fCoincidence;
    SkOpContourHead* fContourHead;
    int fNested;
    bool fWindingFailed;
    bool fAngleCoincidence;
    Phase fPhase;
#ifdef SK_DEBUG
<<<<<<< HEAD
    const char* fDebugTestName;
    int fAngleID;
    int fCoinID;
=======
    int fAngleID;
>>>>>>> miniblink49
    int fContourID;
    int fPtTID;
    int fSegmentID;
    int fSpanID;
<<<<<<< HEAD
    bool fDebugSkipAssert;
#endif
#if DEBUG_T_SECT_LOOP_COUNT
    int fDebugLoopCount[3];
    SkPath::Verb fDebugWorstVerb[6];
    SkPoint fDebugWorstPts[24];
    float fDebugWorstWeight[6];
=======
>>>>>>> miniblink49
#endif
};

// Use Almost Equal when comparing coordinates. Use epsilon to compare T values.
bool AlmostEqualUlps(float a, float b);
<<<<<<< HEAD
inline bool AlmostEqualUlps(double a, double b)
{
    return AlmostEqualUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool AlmostEqualUlps_Pin(float a, float b);
inline bool AlmostEqualUlps_Pin(double a, double b)
{
    return AlmostEqualUlps_Pin(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

=======
inline bool AlmostEqualUlps(double a, double b) {
    return AlmostEqualUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

>>>>>>> miniblink49
// Use Almost Dequal when comparing should not special case denormalized values.
bool AlmostDequalUlps(float a, float b);
bool AlmostDequalUlps(double a, double b);

bool NotAlmostEqualUlps(float a, float b);
<<<<<<< HEAD
inline bool NotAlmostEqualUlps(double a, double b)
{
    return NotAlmostEqualUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool NotAlmostEqualUlps_Pin(float a, float b);
inline bool NotAlmostEqualUlps_Pin(double a, double b)
{
    return NotAlmostEqualUlps_Pin(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool NotAlmostDequalUlps(float a, float b);
inline bool NotAlmostDequalUlps(double a, double b)
{
=======
inline bool NotAlmostEqualUlps(double a, double b) {
    return NotAlmostEqualUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool NotAlmostDequalUlps(float a, float b);
inline bool NotAlmostDequalUlps(double a, double b) {
>>>>>>> miniblink49
    return NotAlmostDequalUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

// Use Almost Bequal when comparing coordinates in conjunction with between.
bool AlmostBequalUlps(float a, float b);
<<<<<<< HEAD
inline bool AlmostBequalUlps(double a, double b)
{
=======
inline bool AlmostBequalUlps(double a, double b) {
>>>>>>> miniblink49
    return AlmostBequalUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool AlmostPequalUlps(float a, float b);
<<<<<<< HEAD
inline bool AlmostPequalUlps(double a, double b)
{
=======
inline bool AlmostPequalUlps(double a, double b) {
>>>>>>> miniblink49
    return AlmostPequalUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool RoughlyEqualUlps(float a, float b);
<<<<<<< HEAD
inline bool RoughlyEqualUlps(double a, double b)
{
=======
inline bool RoughlyEqualUlps(double a, double b) {
>>>>>>> miniblink49
    return RoughlyEqualUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool AlmostLessUlps(float a, float b);
<<<<<<< HEAD
inline bool AlmostLessUlps(double a, double b)
{
=======
inline bool AlmostLessUlps(double a, double b) {
>>>>>>> miniblink49
    return AlmostLessUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool AlmostLessOrEqualUlps(float a, float b);
<<<<<<< HEAD
inline bool AlmostLessOrEqualUlps(double a, double b)
{
=======
inline bool AlmostLessOrEqualUlps(double a, double b) {
>>>>>>> miniblink49
    return AlmostLessOrEqualUlps(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

bool AlmostBetweenUlps(float a, float b, float c);
<<<<<<< HEAD
inline bool AlmostBetweenUlps(double a, double b, double c)
{
=======
inline bool AlmostBetweenUlps(double a, double b, double c) {
>>>>>>> miniblink49
    return AlmostBetweenUlps(SkDoubleToScalar(a), SkDoubleToScalar(b), SkDoubleToScalar(c));
}

int UlpsDistance(float a, float b);
<<<<<<< HEAD
inline int UlpsDistance(double a, double b)
{
=======
inline int UlpsDistance(double a, double b) {
>>>>>>> miniblink49
    return UlpsDistance(SkDoubleToScalar(a), SkDoubleToScalar(b));
}

// FLT_EPSILON == 1.19209290E-07 == 1 / (2 ^ 23)
// DBL_EPSILON == 2.22045e-16
const double FLT_EPSILON_CUBED = FLT_EPSILON * FLT_EPSILON * FLT_EPSILON;
const double FLT_EPSILON_HALF = FLT_EPSILON / 2;
const double FLT_EPSILON_DOUBLE = FLT_EPSILON * 2;
const double FLT_EPSILON_ORDERABLE_ERR = FLT_EPSILON * 16;
const double FLT_EPSILON_SQUARED = FLT_EPSILON * FLT_EPSILON;
const double FLT_EPSILON_SQRT = sqrt(FLT_EPSILON);
const double FLT_EPSILON_INVERSE = 1 / FLT_EPSILON;
<<<<<<< HEAD
const double DBL_EPSILON_ERR = DBL_EPSILON * 4; // FIXME: tune -- allow a few bits of error
=======
const double DBL_EPSILON_ERR = DBL_EPSILON * 4;  // FIXME: tune -- allow a few bits of error
>>>>>>> miniblink49
const double DBL_EPSILON_SUBDIVIDE_ERR = DBL_EPSILON * 16;
const double ROUGH_EPSILON = FLT_EPSILON * 64;
const double MORE_ROUGH_EPSILON = FLT_EPSILON * 256;
const double WAY_ROUGH_EPSILON = FLT_EPSILON * 2048;
const double BUMP_EPSILON = FLT_EPSILON * 4096;

<<<<<<< HEAD
inline bool zero_or_one(double x)
{
    return x == 0 || x == 1;
}

inline bool approximately_zero(double x)
{
    return fabs(x) < FLT_EPSILON;
}

inline bool precisely_zero(double x)
{
    return fabs(x) < DBL_EPSILON_ERR;
}

inline bool precisely_subdivide_zero(double x)
{
    return fabs(x) < DBL_EPSILON_SUBDIVIDE_ERR;
}

inline bool approximately_zero(float x)
{
    return fabs(x) < FLT_EPSILON;
}

inline bool approximately_zero_cubed(double x)
{
    return fabs(x) < FLT_EPSILON_CUBED;
}

inline bool approximately_zero_half(double x)
{
    return fabs(x) < FLT_EPSILON_HALF;
}

inline bool approximately_zero_double(double x)
{
    return fabs(x) < FLT_EPSILON_DOUBLE;
}

inline bool approximately_zero_orderable(double x)
{
    return fabs(x) < FLT_EPSILON_ORDERABLE_ERR;
}

inline bool approximately_zero_squared(double x)
{
    return fabs(x) < FLT_EPSILON_SQUARED;
}

inline bool approximately_zero_sqrt(double x)
{
    return fabs(x) < FLT_EPSILON_SQRT;
}

inline bool roughly_zero(double x)
{
    return fabs(x) < ROUGH_EPSILON;
}

inline bool approximately_zero_inverse(double x)
{
=======
inline bool zero_or_one(double x) {
    return x == 0 || x == 1;
}

inline bool approximately_zero(double x) {
    return fabs(x) < FLT_EPSILON;
}

inline bool precisely_zero(double x) {
    return fabs(x) < DBL_EPSILON_ERR;
}

inline bool precisely_subdivide_zero(double x) {
    return fabs(x) < DBL_EPSILON_SUBDIVIDE_ERR;
}

inline bool approximately_zero(float x) {
    return fabs(x) < FLT_EPSILON;
}

inline bool approximately_zero_cubed(double x) {
    return fabs(x) < FLT_EPSILON_CUBED;
}

inline bool approximately_zero_half(double x) {
    return fabs(x) < FLT_EPSILON_HALF;
}

inline bool approximately_zero_double(double x) {
    return fabs(x) < FLT_EPSILON_DOUBLE;
}

inline bool approximately_zero_orderable(double x) {
    return fabs(x) < FLT_EPSILON_ORDERABLE_ERR;
}

inline bool approximately_zero_squared(double x) {
    return fabs(x) < FLT_EPSILON_SQUARED;
}

inline bool approximately_zero_sqrt(double x) {
    return fabs(x) < FLT_EPSILON_SQRT;
}

inline bool roughly_zero(double x) {
    return fabs(x) < ROUGH_EPSILON;
}

inline bool approximately_zero_inverse(double x) {
>>>>>>> miniblink49
    return fabs(x) > FLT_EPSILON_INVERSE;
}

// OPTIMIZATION: if called multiple times with the same denom, we want to pass 1/y instead
<<<<<<< HEAD
inline bool approximately_zero_when_compared_to(double x, double y)
{
    return x == 0 || fabs(x) < fabs(y * FLT_EPSILON);
}

inline bool precisely_zero_when_compared_to(double x, double y)
{
=======
inline bool approximately_zero_when_compared_to(double x, double y) {
    return x == 0 || fabs(x) < fabs(y * FLT_EPSILON);
}

inline bool precisely_zero_when_compared_to(double x, double y) {
>>>>>>> miniblink49
    return x == 0 || fabs(x) < fabs(y * DBL_EPSILON);
}

// Use this for comparing Ts in the range of 0 to 1. For general numbers (larger and smaller) use
// AlmostEqualUlps instead.
<<<<<<< HEAD
inline bool approximately_equal(double x, double y)
{
    return approximately_zero(x - y);
}

inline bool precisely_equal(double x, double y)
{
    return precisely_zero(x - y);
}

inline bool precisely_subdivide_equal(double x, double y)
{
    return precisely_subdivide_zero(x - y);
}

inline bool approximately_equal_half(double x, double y)
{
    return approximately_zero_half(x - y);
}

inline bool approximately_equal_double(double x, double y)
{
    return approximately_zero_double(x - y);
}

inline bool approximately_equal_orderable(double x, double y)
{
    return approximately_zero_orderable(x - y);
}

inline bool approximately_equal_squared(double x, double y)
{
    return approximately_equal(x, y);
}

inline bool approximately_greater(double x, double y)
{
    return x - FLT_EPSILON >= y;
}

inline bool approximately_greater_double(double x, double y)
{
    return x - FLT_EPSILON_DOUBLE >= y;
}

inline bool approximately_greater_orderable(double x, double y)
{
    return x - FLT_EPSILON_ORDERABLE_ERR >= y;
}

inline bool approximately_greater_or_equal(double x, double y)
{
    return x + FLT_EPSILON > y;
}

inline bool approximately_greater_or_equal_double(double x, double y)
{
    return x + FLT_EPSILON_DOUBLE > y;
}

inline bool approximately_greater_or_equal_orderable(double x, double y)
{
    return x + FLT_EPSILON_ORDERABLE_ERR > y;
}

inline bool approximately_lesser(double x, double y)
{
    return x + FLT_EPSILON <= y;
}

inline bool approximately_lesser_double(double x, double y)
{
    return x + FLT_EPSILON_DOUBLE <= y;
}

inline bool approximately_lesser_orderable(double x, double y)
{
    return x + FLT_EPSILON_ORDERABLE_ERR <= y;
}

inline bool approximately_lesser_or_equal(double x, double y)
{
    return x - FLT_EPSILON < y;
}

inline bool approximately_lesser_or_equal_double(double x, double y)
{
    return x - FLT_EPSILON_DOUBLE < y;
}

inline bool approximately_lesser_or_equal_orderable(double x, double y)
{
    return x - FLT_EPSILON_ORDERABLE_ERR < y;
}

inline bool approximately_greater_than_one(double x)
{
    return x > 1 - FLT_EPSILON;
}

inline bool precisely_greater_than_one(double x)
{
    return x > 1 - DBL_EPSILON_ERR;
}

inline bool approximately_less_than_zero(double x)
{
    return x < FLT_EPSILON;
}

inline bool precisely_less_than_zero(double x)
{
    return x < DBL_EPSILON_ERR;
}

inline bool approximately_negative(double x)
{
    return x < FLT_EPSILON;
}

inline bool approximately_negative_orderable(double x)
{
    return x < FLT_EPSILON_ORDERABLE_ERR;
}

inline bool precisely_negative(double x)
{
    return x < DBL_EPSILON_ERR;
}

inline bool approximately_one_or_less(double x)
{
    return x < 1 + FLT_EPSILON;
}

inline bool approximately_one_or_less_double(double x)
{
    return x < 1 + FLT_EPSILON_DOUBLE;
}

inline bool approximately_positive(double x)
{
    return x > -FLT_EPSILON;
}

inline bool approximately_positive_squared(double x)
{
    return x > -(FLT_EPSILON_SQUARED);
}

inline bool approximately_zero_or_more(double x)
{
    return x > -FLT_EPSILON;
}

inline bool approximately_zero_or_more_double(double x)
{
    return x > -FLT_EPSILON_DOUBLE;
}

inline bool approximately_between_orderable(double a, double b, double c)
{
    return a <= c
        ? approximately_negative_orderable(a - b) && approximately_negative_orderable(b - c)
        : approximately_negative_orderable(b - a) && approximately_negative_orderable(c - b);
}

inline bool approximately_between(double a, double b, double c)
{
    return a <= c ? approximately_negative(a - b) && approximately_negative(b - c)
                  : approximately_negative(b - a) && approximately_negative(c - b);
}

inline bool precisely_between(double a, double b, double c)
{
    return a <= c ? precisely_negative(a - b) && precisely_negative(b - c)
                  : precisely_negative(b - a) && precisely_negative(c - b);
}

// returns true if (a <= b <= c) || (a >= b >= c)
inline bool between(double a, double b, double c)
{
    SkASSERT(((a <= b && b <= c) || (a >= b && b >= c)) == ((a - b) * (c - b) <= 0)
        || (precisely_zero(a) && precisely_zero(b) && precisely_zero(c)));
    return (a - b) * (c - b) <= 0;
}

inline bool roughly_equal(double x, double y)
{
    return fabs(x - y) < ROUGH_EPSILON;
}

inline bool roughly_negative(double x)
{
    return x < ROUGH_EPSILON;
}

inline bool roughly_between(double a, double b, double c)
{
    return a <= c ? roughly_negative(a - b) && roughly_negative(b - c)
                  : roughly_negative(b - a) && roughly_negative(c - b);
}

inline bool more_roughly_equal(double x, double y)
{
    return fabs(x - y) < MORE_ROUGH_EPSILON;
}

inline bool way_roughly_equal(double x, double y)
{
=======
inline bool approximately_equal(double x, double y) {
    return approximately_zero(x - y);
}

inline bool precisely_equal(double x, double y) {
    return precisely_zero(x - y);
}

inline bool precisely_subdivide_equal(double x, double y) {
    return precisely_subdivide_zero(x - y);
}

inline bool approximately_equal_half(double x, double y) {
    return approximately_zero_half(x - y);
}

inline bool approximately_equal_double(double x, double y) {
    return approximately_zero_double(x - y);
}

inline bool approximately_equal_orderable(double x, double y) {
    return approximately_zero_orderable(x - y);
}

inline bool approximately_equal_squared(double x, double y) {
    return approximately_equal(x, y);
}

inline bool approximately_greater(double x, double y) {
    return x - FLT_EPSILON >= y;
}

inline bool approximately_greater_double(double x, double y) {
    return x - FLT_EPSILON_DOUBLE >= y;
}

inline bool approximately_greater_orderable(double x, double y) {
    return x - FLT_EPSILON_ORDERABLE_ERR >= y;
}

inline bool approximately_greater_or_equal(double x, double y) {
    return x + FLT_EPSILON > y;
}

inline bool approximately_greater_or_equal_double(double x, double y) {
    return x + FLT_EPSILON_DOUBLE > y;
}

inline bool approximately_greater_or_equal_orderable(double x, double y) {
    return x + FLT_EPSILON_ORDERABLE_ERR > y;
}

inline bool approximately_lesser(double x, double y) {
    return x + FLT_EPSILON <= y;
}

inline bool approximately_lesser_double(double x, double y) {
    return x + FLT_EPSILON_DOUBLE <= y;
}

inline bool approximately_lesser_orderable(double x, double y) {
    return x + FLT_EPSILON_ORDERABLE_ERR <= y;
}

inline bool approximately_lesser_or_equal(double x, double y) {
    return x - FLT_EPSILON < y;
}

inline bool approximately_lesser_or_equal_double(double x, double y) {
    return x - FLT_EPSILON_DOUBLE < y;
}

inline bool approximately_lesser_or_equal_orderable(double x, double y) {
    return x - FLT_EPSILON_ORDERABLE_ERR < y;
}

inline bool approximately_greater_than_one(double x) {
    return x > 1 - FLT_EPSILON;
}

inline bool precisely_greater_than_one(double x) {
    return x > 1 - DBL_EPSILON_ERR;
}

inline bool approximately_less_than_zero(double x) {
    return x < FLT_EPSILON;
}

inline bool precisely_less_than_zero(double x) {
    return x < DBL_EPSILON_ERR;
}

inline bool approximately_negative(double x) {
    return x < FLT_EPSILON;
}

inline bool approximately_negative_orderable(double x) {
    return x < FLT_EPSILON_ORDERABLE_ERR;
}

inline bool precisely_negative(double x) {
    return x < DBL_EPSILON_ERR;
}

inline bool approximately_one_or_less(double x) {
    return x < 1 + FLT_EPSILON;
}

inline bool approximately_one_or_less_double(double x) {
    return x < 1 + FLT_EPSILON_DOUBLE;
}

inline bool approximately_positive(double x) {
    return x > -FLT_EPSILON;
}

inline bool approximately_positive_squared(double x) {
    return x > -(FLT_EPSILON_SQUARED);
}

inline bool approximately_zero_or_more(double x) {
    return x > -FLT_EPSILON;
}

inline bool approximately_zero_or_more_double(double x) {
    return x > -FLT_EPSILON_DOUBLE;
}

inline bool approximately_between_orderable(double a, double b, double c) {
    return a <= c
            ? approximately_negative_orderable(a - b) && approximately_negative_orderable(b - c)
            : approximately_negative_orderable(b - a) && approximately_negative_orderable(c - b);
}

inline bool approximately_between(double a, double b, double c) {
    return a <= c ? approximately_negative(a - b) && approximately_negative(b - c)
            : approximately_negative(b - a) && approximately_negative(c - b);
}

inline bool precisely_between(double a, double b, double c) {
    return a <= c ? precisely_negative(a - b) && precisely_negative(b - c)
            : precisely_negative(b - a) && precisely_negative(c - b);
}

// returns true if (a <= b <= c) || (a >= b >= c)
inline bool between(double a, double b, double c) {
    SkASSERT(((a <= b && b <= c) || (a >= b && b >= c)) == ((a - b) * (c - b) <= 0)
            || (precisely_zero(a) && precisely_zero(b) && precisely_zero(c)));
    return (a - b) * (c - b) <= 0;
}

inline bool roughly_equal(double x, double y) {
    return fabs(x - y) < ROUGH_EPSILON;
}

inline bool roughly_negative(double x) {
    return x < ROUGH_EPSILON;
}

inline bool roughly_between(double a, double b, double c) {
    return a <= c ? roughly_negative(a - b) && roughly_negative(b - c)
            : roughly_negative(b - a) && roughly_negative(c - b);
}

inline bool more_roughly_equal(double x, double y) {
    return fabs(x - y) < MORE_ROUGH_EPSILON;
}

inline bool way_roughly_equal(double x, double y) {
>>>>>>> miniblink49
    return fabs(x - y) < WAY_ROUGH_EPSILON;
}

struct SkDPoint;
struct SkDVector;
struct SkDLine;
struct SkDQuad;
struct SkDConic;
struct SkDCubic;
struct SkDRect;

<<<<<<< HEAD
inline SkPath::Verb SkPathOpsPointsToVerb(int points)
{
    int verb = (1 << points) >> 1;
#ifdef SK_DEBUG
    switch (points) {
    case 0:
        SkASSERT(SkPath::kMove_Verb == verb);
        break;
    case 1:
        SkASSERT(SkPath::kLine_Verb == verb);
        break;
    case 2:
        SkASSERT(SkPath::kQuad_Verb == verb);
        break;
    case 3:
        SkASSERT(SkPath::kCubic_Verb == verb);
        break;
    default:
        SkDEBUGFAIL("should not be here");
=======
inline SkPath::Verb SkPathOpsPointsToVerb(int points) {
    int verb = (1 << points) >> 1;
#ifdef SK_DEBUG
    switch (points) {
        case 0: SkASSERT(SkPath::kMove_Verb == verb); break;
        case 1: SkASSERT(SkPath::kLine_Verb == verb); break;
        case 2: SkASSERT(SkPath::kQuad_Verb == verb); break;
        case 3: SkASSERT(SkPath::kCubic_Verb == verb); break;
        default: SkDEBUGFAIL("should not be here");
>>>>>>> miniblink49
    }
#endif
    return (SkPath::Verb)verb;
}

<<<<<<< HEAD
inline int SkPathOpsVerbToPoints(SkPath::Verb verb)
{
    int points = (int)verb - (((int)verb + 1) >> 2);
#ifdef SK_DEBUG
    switch (verb) {
    case SkPath::kLine_Verb:
        SkASSERT(1 == points);
        break;
    case SkPath::kQuad_Verb:
        SkASSERT(2 == points);
        break;
    case SkPath::kConic_Verb:
        SkASSERT(2 == points);
        break;
    case SkPath::kCubic_Verb:
        SkASSERT(3 == points);
        break;
    default:
        SkDEBUGFAIL("should not get here");
=======
inline int SkPathOpsVerbToPoints(SkPath::Verb verb) {
    int points = (int) verb - (((int) verb + 1) >> 2);
#ifdef SK_DEBUG
    switch (verb) {
        case SkPath::kLine_Verb: SkASSERT(1 == points); break;
        case SkPath::kQuad_Verb: SkASSERT(2 == points); break;
        case SkPath::kConic_Verb: SkASSERT(2 == points); break;
        case SkPath::kCubic_Verb: SkASSERT(3 == points); break;
        default: SkDEBUGFAIL("should not get here");
>>>>>>> miniblink49
    }
#endif
    return points;
}

<<<<<<< HEAD
inline double SkDInterp(double A, double B, double t)
{
=======
inline double SkDInterp(double A, double B, double t) {
>>>>>>> miniblink49
    return A + (B - A) * t;
}

double SkDCubeRoot(double x);

/* Returns -1 if negative, 0 if zero, 1 if positive
*/
<<<<<<< HEAD
inline int SkDSign(double x)
{
=======
inline int SkDSign(double x) {
>>>>>>> miniblink49
    return (x > 0) - (x < 0);
}

/* Returns 0 if negative, 1 if zero, 2 if positive
*/
<<<<<<< HEAD
inline int SKDSide(double x)
{
=======
inline int SKDSide(double x) {
>>>>>>> miniblink49
    return (x > 0) + (x >= 0);
}

/* Returns 1 if negative, 2 if zero, 4 if positive
*/
<<<<<<< HEAD
inline int SkDSideBit(double x)
{
    return 1 << SKDSide(x);
}

inline double SkPinT(double t)
{
=======
inline int SkDSideBit(double x) {
    return 1 << SKDSide(x);
}

inline double SkPinT(double t) {
>>>>>>> miniblink49
    return precisely_less_than_zero(t) ? 0 : precisely_greater_than_one(t) ? 1 : t;
}

#endif
