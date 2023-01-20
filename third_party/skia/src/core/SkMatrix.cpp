/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMatrix.h"
#include "SkFloatBits.h"
<<<<<<< HEAD
#include "SkNx.h"
#include "SkPaint.h"
#include "SkRSXform.h"
#include "SkString.h"
#include <stddef.h>

static void normalize_perspective(SkScalar mat[9])
{
=======
#include "SkRSXform.h"
#include "SkString.h"
#include "SkNx.h"

#include <stddef.h>

static void normalize_perspective(SkScalar mat[9]) {
>>>>>>> miniblink49
    // If it was interesting to never store the last element, we could divide all 8 other
    // elements here by the 9th, making it 1.0...
    //
    // When SkScalar was SkFixed, we would sometimes rescale the entire matrix to keep its
    // component values from getting too large. This is not a concern when using floats/doubles,
    // so we do nothing now.

    // Disable this for now, but it could be enabled.
#if 0
    if (0 == mat[SkMatrix::kMPersp0] && 0 == mat[SkMatrix::kMPersp1]) {
        SkScalar p2 = mat[SkMatrix::kMPersp2];
        if (p2 != 0 && p2 != 1) {
            double inv = 1.0 / p2;
            for (int i = 0; i < 6; ++i) {
                mat[i] = SkDoubleToScalar(mat[i] * inv);
            }
            mat[SkMatrix::kMPersp2] = 1;
        }
    }
#endif
}

// In a few places, we performed the following
//      a * b + c * d + e
// as
//      a * b + (c * d + e)
//
// sdot and scross are indended to capture these compound operations into a
// function, with an eye toward considering upscaling the intermediates to
// doubles for more precision (as we do in concat and invert).
//
// However, these few lines that performed the last add before the "dot", cause
// tiny image differences, so we guard that change until we see the impact on
// chrome's layouttests.
//
#define SK_LEGACY_MATRIX_MATH_ORDER

<<<<<<< HEAD
static inline float SkDoubleToFloat(double x)
{
=======
static inline float SkDoubleToFloat(double x) {
>>>>>>> miniblink49
    return static_cast<float>(x);
}

/*      [scale-x    skew-x      trans-x]   [X]   [X']
        [skew-y     scale-y     trans-y] * [Y] = [Y']
        [persp-0    persp-1     persp-2]   [1]   [1 ]
*/

<<<<<<< HEAD
void SkMatrix::reset()
{
    fMat[kMScaleX] = fMat[kMScaleY] = fMat[kMPersp2] = 1;
    fMat[kMSkewX] = fMat[kMSkewY] = fMat[kMTransX] = fMat[kMTransY] = fMat[kMPersp0] = fMat[kMPersp1] = 0;
    this->setTypeMask(kIdentity_Mask | kRectStaysRect_Mask);
}

void SkMatrix::set9(const SkScalar buffer[])
{
=======
void SkMatrix::reset() {
    fMat[kMScaleX] = fMat[kMScaleY] = fMat[kMPersp2] = 1;
    fMat[kMSkewX]  = fMat[kMSkewY] =
    fMat[kMTransX] = fMat[kMTransY] =
    fMat[kMPersp0] = fMat[kMPersp1] = 0;
    this->setTypeMask(kIdentity_Mask | kRectStaysRect_Mask);
}

void SkMatrix::set9(const SkScalar buffer[]) {
>>>>>>> miniblink49
    memcpy(fMat, buffer, 9 * sizeof(SkScalar));
    normalize_perspective(fMat);
    this->setTypeMask(kUnknown_Mask);
}

<<<<<<< HEAD
void SkMatrix::setAffine(const SkScalar buffer[])
{
    fMat[kMScaleX] = buffer[kAScaleX];
    fMat[kMSkewX] = buffer[kASkewX];
    fMat[kMTransX] = buffer[kATransX];
    fMat[kMSkewY] = buffer[kASkewY];
=======
void SkMatrix::setAffine(const SkScalar buffer[]) {
    fMat[kMScaleX] = buffer[kAScaleX];
    fMat[kMSkewX]  = buffer[kASkewX];
    fMat[kMTransX] = buffer[kATransX];
    fMat[kMSkewY]  = buffer[kASkewY];
>>>>>>> miniblink49
    fMat[kMScaleY] = buffer[kAScaleY];
    fMat[kMTransY] = buffer[kATransY];
    fMat[kMPersp0] = 0;
    fMat[kMPersp1] = 0;
    fMat[kMPersp2] = 1;
    this->setTypeMask(kUnknown_Mask);
}

// this guy aligns with the masks, so we can compute a mask from a varaible 0/1
enum {
    kTranslate_Shift,
    kScale_Shift,
    kAffine_Shift,
    kPerspective_Shift,
    kRectStaysRect_Shift
};

static const int32_t kScalar1Int = 0x3f800000;

<<<<<<< HEAD
uint8_t SkMatrix::computePerspectiveTypeMask() const
{
=======
uint8_t SkMatrix::computePerspectiveTypeMask() const {
>>>>>>> miniblink49
    // Benchmarking suggests that replacing this set of SkScalarAs2sCompliment
    // is a win, but replacing those below is not. We don't yet understand
    // that result.
    if (fMat[kMPersp0] != 0 || fMat[kMPersp1] != 0 || fMat[kMPersp2] != 1) {
        // If this is a perspective transform, we return true for all other
        // transform flags - this does not disable any optimizations, respects
        // the rule that the type mask must be conservative, and speeds up
        // type mask computation.
        return SkToU8(kORableMasks);
    }

    return SkToU8(kOnlyPerspectiveValid_Mask | kUnknown_Mask);
}

<<<<<<< HEAD
uint8_t SkMatrix::computeTypeMask() const
{
=======
uint8_t SkMatrix::computeTypeMask() const {
>>>>>>> miniblink49
    unsigned mask = 0;

    if (fMat[kMPersp0] != 0 || fMat[kMPersp1] != 0 || fMat[kMPersp2] != 1) {
        // Once it is determined that that this is a perspective transform,
        // all other flags are moot as far as optimizations are concerned.
        return SkToU8(kORableMasks);
    }

    if (fMat[kMTransX] != 0 || fMat[kMTransY] != 0) {
        mask |= kTranslate_Mask;
    }

    int m00 = SkScalarAs2sCompliment(fMat[SkMatrix::kMScaleX]);
    int m01 = SkScalarAs2sCompliment(fMat[SkMatrix::kMSkewX]);
    int m10 = SkScalarAs2sCompliment(fMat[SkMatrix::kMSkewY]);
    int m11 = SkScalarAs2sCompliment(fMat[SkMatrix::kMScaleY]);

    if (m01 | m10) {
        // The skew components may be scale-inducing, unless we are dealing
        // with a pure rotation.  Testing for a pure rotation is expensive,
        // so we opt for being conservative by always setting the scale bit.
        // along with affine.
        // By doing this, we are also ensuring that matrices have the same
        // type masks as their inverses.
        mask |= kAffine_Mask | kScale_Mask;

        // For rectStaysRect, in the affine case, we only need check that
        // the primary diagonal is all zeros and that the secondary diagonal
        // is all non-zero.

        // map non-zero to 1
        m01 = m01 != 0;
        m10 = m10 != 0;

<<<<<<< HEAD
        int dp0 = 0 == (m00 | m11); // true if both are 0
        int ds1 = m01 & m10; // true if both are 1
=======
        int dp0 = 0 == (m00 | m11) ;  // true if both are 0
        int ds1 = m01 & m10;        // true if both are 1
>>>>>>> miniblink49

        mask |= (dp0 & ds1) << kRectStaysRect_Shift;
    } else {
        // Only test for scale explicitly if not affine, since affine sets the
        // scale bit.
<<<<<<< HEAD
        if ((m00 ^ kScalar1Int) | (m11 ^ kScalar1Int)) {
=======
        if ((m00 - kScalar1Int) | (m11 - kScalar1Int)) {
>>>>>>> miniblink49
            mask |= kScale_Mask;
        }

        // Not affine, therefore we already know secondary diagonal is
        // all zeros, so we just need to check that primary diagonal is
        // all non-zero.

        // map non-zero to 1
        m00 = m00 != 0;
        m11 = m11 != 0;

        // record if the (p)rimary diagonal is all non-zero
        mask |= (m00 & m11) << kRectStaysRect_Shift;
    }

    return SkToU8(mask);
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool operator==(const SkMatrix& a, const SkMatrix& b)
{
    const SkScalar* SK_RESTRICT ma = a.fMat;
    const SkScalar* SK_RESTRICT mb = b.fMat;

    return ma[0] == mb[0] && ma[1] == mb[1] && ma[2] == mb[2] && ma[3] == mb[3] && ma[4] == mb[4] && ma[5] == mb[5] && ma[6] == mb[6] && ma[7] == mb[7] && ma[8] == mb[8];
=======
bool operator==(const SkMatrix& a, const SkMatrix& b) {
    const SkScalar* SK_RESTRICT ma = a.fMat;
    const SkScalar* SK_RESTRICT mb = b.fMat;

    return  ma[0] == mb[0] && ma[1] == mb[1] && ma[2] == mb[2] &&
            ma[3] == mb[3] && ma[4] == mb[4] && ma[5] == mb[5] &&
            ma[6] == mb[6] && ma[7] == mb[7] && ma[8] == mb[8];
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

// helper function to determine if upper-left 2x2 of matrix is degenerate
static inline bool is_degenerate_2x2(SkScalar scaleX, SkScalar skewX,
<<<<<<< HEAD
    SkScalar skewY, SkScalar scaleY)
{
    SkScalar perp_dot = scaleX * scaleY - skewX * skewY;
    return SkScalarNearlyZero(perp_dot, SK_ScalarNearlyZero * SK_ScalarNearlyZero);
=======
                                     SkScalar skewY,  SkScalar scaleY) {
    SkScalar perp_dot = scaleX*scaleY - skewX*skewY;
    return SkScalarNearlyZero(perp_dot, SK_ScalarNearlyZero*SK_ScalarNearlyZero);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool SkMatrix::isSimilarity(SkScalar tol) const
{
=======
bool SkMatrix::isSimilarity(SkScalar tol) const {
>>>>>>> miniblink49
    // if identity or translate matrix
    TypeMask mask = this->getType();
    if (mask <= kTranslate_Mask) {
        return true;
    }
    if (mask & kPerspective_Mask) {
        return false;
    }

    SkScalar mx = fMat[kMScaleX];
    SkScalar my = fMat[kMScaleY];
    // if no skew, can just compare scale factors
    if (!(mask & kAffine_Mask)) {
        return !SkScalarNearlyZero(mx) && SkScalarNearlyEqual(SkScalarAbs(mx), SkScalarAbs(my));
    }
    SkScalar sx = fMat[kMSkewX];
    SkScalar sy = fMat[kMSkewY];

    if (is_degenerate_2x2(mx, sx, sy, my)) {
        return false;
    }

    // upper 2x2 is rotation/reflection + uniform scale if basis vectors
    // are 90 degree rotations of each other
    return (SkScalarNearlyEqual(mx, my, tol) && SkScalarNearlyEqual(sx, -sy, tol))
        || (SkScalarNearlyEqual(mx, -my, tol) && SkScalarNearlyEqual(sx, sy, tol));
}

<<<<<<< HEAD
bool SkMatrix::preservesRightAngles(SkScalar tol) const
{
=======
bool SkMatrix::preservesRightAngles(SkScalar tol) const {
>>>>>>> miniblink49
    TypeMask mask = this->getType();

    if (mask <= kTranslate_Mask) {
        // identity, translate and/or scale
        return true;
    }
    if (mask & kPerspective_Mask) {
        return false;
    }

    SkASSERT(mask & (kAffine_Mask | kScale_Mask));

    SkScalar mx = fMat[kMScaleX];
    SkScalar my = fMat[kMScaleY];
    SkScalar sx = fMat[kMSkewX];
    SkScalar sy = fMat[kMSkewY];

    if (is_degenerate_2x2(mx, sx, sy, my)) {
        return false;
    }

    // upper 2x2 is scale + rotation/reflection if basis vectors are orthogonal
    SkVector vec[2];
    vec[0].set(mx, sy);
    vec[1].set(sx, my);

    return SkScalarNearlyZero(vec[0].dot(vec[1]), SkScalarSquare(tol));
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static inline SkScalar sdot(SkScalar a, SkScalar b, SkScalar c, SkScalar d)
{
=======
static inline SkScalar sdot(SkScalar a, SkScalar b, SkScalar c, SkScalar d) {
>>>>>>> miniblink49
    return a * b + c * d;
}

static inline SkScalar sdot(SkScalar a, SkScalar b, SkScalar c, SkScalar d,
<<<<<<< HEAD
    SkScalar e, SkScalar f)
{
    return a * b + c * d + e * f;
}

static inline SkScalar scross(SkScalar a, SkScalar b, SkScalar c, SkScalar d)
{
    return a * b - c * d;
}

void SkMatrix::setTranslate(SkScalar dx, SkScalar dy)
{
=======
                             SkScalar e, SkScalar f) {
    return a * b + c * d + e * f;
}

static inline SkScalar scross(SkScalar a, SkScalar b, SkScalar c, SkScalar d) {
    return a * b - c * d;
}

void SkMatrix::setTranslate(SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
    if (dx || dy) {
        fMat[kMTransX] = dx;
        fMat[kMTransY] = dy;

        fMat[kMScaleX] = fMat[kMScaleY] = fMat[kMPersp2] = 1;
<<<<<<< HEAD
        fMat[kMSkewX] = fMat[kMSkewY] = fMat[kMPersp0] = fMat[kMPersp1] = 0;
=======
        fMat[kMSkewX]  = fMat[kMSkewY] =
        fMat[kMPersp0] = fMat[kMPersp1] = 0;
>>>>>>> miniblink49

        this->setTypeMask(kTranslate_Mask | kRectStaysRect_Mask);
    } else {
        this->reset();
    }
}

<<<<<<< HEAD
void SkMatrix::preTranslate(SkScalar dx, SkScalar dy)
{
=======
void SkMatrix::preTranslate(SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
    if (!dx && !dy) {
        return;
    }

    if (this->hasPerspective()) {
<<<<<<< HEAD
        SkMatrix m;
=======
        SkMatrix    m;
>>>>>>> miniblink49
        m.setTranslate(dx, dy);
        this->preConcat(m);
    } else {
        fMat[kMTransX] += sdot(fMat[kMScaleX], dx, fMat[kMSkewX], dy);
        fMat[kMTransY] += sdot(fMat[kMSkewY], dx, fMat[kMScaleY], dy);
        this->setTypeMask(kUnknown_Mask | kOnlyPerspectiveValid_Mask);
    }
}

<<<<<<< HEAD
void SkMatrix::postTranslate(SkScalar dx, SkScalar dy)
{
=======
void SkMatrix::postTranslate(SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
    if (!dx && !dy) {
        return;
    }

    if (this->hasPerspective()) {
<<<<<<< HEAD
        SkMatrix m;
=======
        SkMatrix    m;
>>>>>>> miniblink49
        m.setTranslate(dx, dy);
        this->postConcat(m);
    } else {
        fMat[kMTransX] += dx;
        fMat[kMTransY] += dy;
        this->setTypeMask(kUnknown_Mask | kOnlyPerspectiveValid_Mask);
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkMatrix::setScale(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py)
{
=======
void SkMatrix::setScale(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
>>>>>>> miniblink49
    if (1 == sx && 1 == sy) {
        this->reset();
    } else {
        this->setScaleTranslate(sx, sy, px - sx * px, py - sy * py);
    }
}

<<<<<<< HEAD
void SkMatrix::setScale(SkScalar sx, SkScalar sy)
{
=======
void SkMatrix::setScale(SkScalar sx, SkScalar sy) {
>>>>>>> miniblink49
    if (1 == sx && 1 == sy) {
        this->reset();
    } else {
        fMat[kMScaleX] = sx;
        fMat[kMScaleY] = sy;
        fMat[kMPersp2] = 1;

<<<<<<< HEAD
        fMat[kMTransX] = fMat[kMTransY] = fMat[kMSkewX] = fMat[kMSkewY] = fMat[kMPersp0] = fMat[kMPersp1] = 0;
=======
        fMat[kMTransX] = fMat[kMTransY] =
        fMat[kMSkewX]  = fMat[kMSkewY] =
        fMat[kMPersp0] = fMat[kMPersp1] = 0;
>>>>>>> miniblink49

        this->setTypeMask(kScale_Mask | kRectStaysRect_Mask);
    }
}

<<<<<<< HEAD
bool SkMatrix::setIDiv(int divx, int divy)
{
=======
bool SkMatrix::setIDiv(int divx, int divy) {
>>>>>>> miniblink49
    if (!divx || !divy) {
        return false;
    }
    this->setScale(SkScalarInvert(divx), SkScalarInvert(divy));
    return true;
}

<<<<<<< HEAD
void SkMatrix::preScale(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py)
{
=======
void SkMatrix::preScale(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
>>>>>>> miniblink49
    if (1 == sx && 1 == sy) {
        return;
    }

<<<<<<< HEAD
    SkMatrix m;
=======
    SkMatrix    m;
>>>>>>> miniblink49
    m.setScale(sx, sy, px, py);
    this->preConcat(m);
}

<<<<<<< HEAD
void SkMatrix::preScale(SkScalar sx, SkScalar sy)
{
=======
void SkMatrix::preScale(SkScalar sx, SkScalar sy) {
>>>>>>> miniblink49
    if (1 == sx && 1 == sy) {
        return;
    }

    // the assumption is that these multiplies are very cheap, and that
    // a full concat and/or just computing the matrix type is more expensive.
    // Also, the fixed-point case checks for overflow, but the float doesn't,
    // so we can get away with these blind multiplies.

    fMat[kMScaleX] *= sx;
<<<<<<< HEAD
    fMat[kMSkewY] *= sx;
    fMat[kMPersp0] *= sx;

    fMat[kMSkewX] *= sy;
    fMat[kMScaleY] *= sy;
    fMat[kMPersp1] *= sy;

    // Attempt to simplify our type when applying an inverse scale.
    // TODO: The persp/affine preconditions are in place to keep the mask consistent with
    //       what computeTypeMask() would produce (persp/skew always implies kScale).
    //       We should investigate whether these flag dependencies are truly needed.
    if (fMat[kMScaleX] == 1 && fMat[kMScaleY] == 1
        && !(fTypeMask & (kPerspective_Mask | kAffine_Mask))) {
        this->clearTypeMask(kScale_Mask);
    } else {
        this->orTypeMask(kScale_Mask);
    }
}

void SkMatrix::postScale(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py)
{
    if (1 == sx && 1 == sy) {
        return;
    }
    SkMatrix m;
=======
    fMat[kMSkewY]  *= sx;
    fMat[kMPersp0] *= sx;

    fMat[kMSkewX]  *= sy;
    fMat[kMScaleY] *= sy;
    fMat[kMPersp1] *= sy;

    this->orTypeMask(kScale_Mask);
}

void SkMatrix::postScale(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    if (1 == sx && 1 == sy) {
        return;
    }
    SkMatrix    m;
>>>>>>> miniblink49
    m.setScale(sx, sy, px, py);
    this->postConcat(m);
}

<<<<<<< HEAD
void SkMatrix::postScale(SkScalar sx, SkScalar sy)
{
    if (1 == sx && 1 == sy) {
        return;
    }
    SkMatrix m;
=======
void SkMatrix::postScale(SkScalar sx, SkScalar sy) {
    if (1 == sx && 1 == sy) {
        return;
    }
    SkMatrix    m;
>>>>>>> miniblink49
    m.setScale(sx, sy);
    this->postConcat(m);
}

// this guy perhaps can go away, if we have a fract/high-precision way to
// scale matrices
<<<<<<< HEAD
bool SkMatrix::postIDiv(int divx, int divy)
{
=======
bool SkMatrix::postIDiv(int divx, int divy) {
>>>>>>> miniblink49
    if (divx == 0 || divy == 0) {
        return false;
    }

    const float invX = 1.f / divx;
    const float invY = 1.f / divy;

    fMat[kMScaleX] *= invX;
<<<<<<< HEAD
    fMat[kMSkewX] *= invX;
    fMat[kMTransX] *= invX;

    fMat[kMScaleY] *= invY;
    fMat[kMSkewY] *= invY;
=======
    fMat[kMSkewX]  *= invX;
    fMat[kMTransX] *= invX;

    fMat[kMScaleY] *= invY;
    fMat[kMSkewY]  *= invY;
>>>>>>> miniblink49
    fMat[kMTransY] *= invY;

    this->setTypeMask(kUnknown_Mask);
    return true;
}

////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkMatrix::setSinCos(SkScalar sinV, SkScalar cosV, SkScalar px, SkScalar py)
{
    const SkScalar oneMinusCosV = 1 - cosV;

    fMat[kMScaleX] = cosV;
    fMat[kMSkewX] = -sinV;
    fMat[kMTransX] = sdot(sinV, py, oneMinusCosV, px);

    fMat[kMSkewY] = sinV;
    fMat[kMScaleY] = cosV;
    fMat[kMTransY] = sdot(-sinV, px, oneMinusCosV, py);
=======
void SkMatrix::setSinCos(SkScalar sinV, SkScalar cosV, SkScalar px, SkScalar py) {
    const SkScalar oneMinusCosV = 1 - cosV;

    fMat[kMScaleX]  = cosV;
    fMat[kMSkewX]   = -sinV;
    fMat[kMTransX]  = sdot(sinV, py, oneMinusCosV, px);

    fMat[kMSkewY]   = sinV;
    fMat[kMScaleY]  = cosV;
    fMat[kMTransY]  = sdot(-sinV, px, oneMinusCosV, py);
>>>>>>> miniblink49

    fMat[kMPersp0] = fMat[kMPersp1] = 0;
    fMat[kMPersp2] = 1;

    this->setTypeMask(kUnknown_Mask | kOnlyPerspectiveValid_Mask);
}

<<<<<<< HEAD
SkMatrix& SkMatrix::setRSXform(const SkRSXform& xform)
{
    fMat[kMScaleX] = xform.fSCos;
    fMat[kMSkewX] = -xform.fSSin;
    fMat[kMTransX] = xform.fTx;

    fMat[kMSkewY] = xform.fSSin;
    fMat[kMScaleY] = xform.fSCos;
    fMat[kMTransY] = xform.fTy;

    fMat[kMPersp0] = fMat[kMPersp1] = 0;
    fMat[kMPersp2] = 1;

=======
SkMatrix& SkMatrix::setRSXform(const SkRSXform& xform) {
    fMat[kMScaleX]  = xform.fSCos;
    fMat[kMSkewX]   = -xform.fSSin;
    fMat[kMTransX]  = xform.fTx;
    
    fMat[kMSkewY]   = xform.fSSin;
    fMat[kMScaleY]  = xform.fSCos;
    fMat[kMTransY]  = xform.fTy;
    
    fMat[kMPersp0] = fMat[kMPersp1] = 0;
    fMat[kMPersp2] = 1;
    
>>>>>>> miniblink49
    this->setTypeMask(kUnknown_Mask | kOnlyPerspectiveValid_Mask);
    return *this;
}

<<<<<<< HEAD
void SkMatrix::setSinCos(SkScalar sinV, SkScalar cosV)
{
    fMat[kMScaleX] = cosV;
    fMat[kMSkewX] = -sinV;
    fMat[kMTransX] = 0;

    fMat[kMSkewY] = sinV;
    fMat[kMScaleY] = cosV;
    fMat[kMTransY] = 0;
=======
void SkMatrix::setSinCos(SkScalar sinV, SkScalar cosV) {
    fMat[kMScaleX]  = cosV;
    fMat[kMSkewX]   = -sinV;
    fMat[kMTransX]  = 0;

    fMat[kMSkewY]   = sinV;
    fMat[kMScaleY]  = cosV;
    fMat[kMTransY]  = 0;
>>>>>>> miniblink49

    fMat[kMPersp0] = fMat[kMPersp1] = 0;
    fMat[kMPersp2] = 1;

    this->setTypeMask(kUnknown_Mask | kOnlyPerspectiveValid_Mask);
}

<<<<<<< HEAD
void SkMatrix::setRotate(SkScalar degrees, SkScalar px, SkScalar py)
{
=======
void SkMatrix::setRotate(SkScalar degrees, SkScalar px, SkScalar py) {
>>>>>>> miniblink49
    SkScalar sinV, cosV;
    sinV = SkScalarSinCos(SkDegreesToRadians(degrees), &cosV);
    this->setSinCos(sinV, cosV, px, py);
}

<<<<<<< HEAD
void SkMatrix::setRotate(SkScalar degrees)
{
=======
void SkMatrix::setRotate(SkScalar degrees) {
>>>>>>> miniblink49
    SkScalar sinV, cosV;
    sinV = SkScalarSinCos(SkDegreesToRadians(degrees), &cosV);
    this->setSinCos(sinV, cosV);
}

<<<<<<< HEAD
void SkMatrix::preRotate(SkScalar degrees, SkScalar px, SkScalar py)
{
    SkMatrix m;
=======
void SkMatrix::preRotate(SkScalar degrees, SkScalar px, SkScalar py) {
    SkMatrix    m;
>>>>>>> miniblink49
    m.setRotate(degrees, px, py);
    this->preConcat(m);
}

<<<<<<< HEAD
void SkMatrix::preRotate(SkScalar degrees)
{
    SkMatrix m;
=======
void SkMatrix::preRotate(SkScalar degrees) {
    SkMatrix    m;
>>>>>>> miniblink49
    m.setRotate(degrees);
    this->preConcat(m);
}

<<<<<<< HEAD
void SkMatrix::postRotate(SkScalar degrees, SkScalar px, SkScalar py)
{
    SkMatrix m;
=======
void SkMatrix::postRotate(SkScalar degrees, SkScalar px, SkScalar py) {
    SkMatrix    m;
>>>>>>> miniblink49
    m.setRotate(degrees, px, py);
    this->postConcat(m);
}

<<<<<<< HEAD
void SkMatrix::postRotate(SkScalar degrees)
{
    SkMatrix m;
=======
void SkMatrix::postRotate(SkScalar degrees) {
    SkMatrix    m;
>>>>>>> miniblink49
    m.setRotate(degrees);
    this->postConcat(m);
}

////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkMatrix::setSkew(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py)
{
    fMat[kMScaleX] = 1;
    fMat[kMSkewX] = sx;
    fMat[kMTransX] = -sx * py;

    fMat[kMSkewY] = sy;
    fMat[kMScaleY] = 1;
    fMat[kMTransY] = -sy * px;
=======
void SkMatrix::setSkew(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    fMat[kMScaleX]  = 1;
    fMat[kMSkewX]   = sx;
    fMat[kMTransX]  = -sx * py;

    fMat[kMSkewY]   = sy;
    fMat[kMScaleY]  = 1;
    fMat[kMTransY]  = -sy * px;
>>>>>>> miniblink49

    fMat[kMPersp0] = fMat[kMPersp1] = 0;
    fMat[kMPersp2] = 1;

    this->setTypeMask(kUnknown_Mask | kOnlyPerspectiveValid_Mask);
}

<<<<<<< HEAD
void SkMatrix::setSkew(SkScalar sx, SkScalar sy)
{
    fMat[kMScaleX] = 1;
    fMat[kMSkewX] = sx;
    fMat[kMTransX] = 0;

    fMat[kMSkewY] = sy;
    fMat[kMScaleY] = 1;
    fMat[kMTransY] = 0;
=======
void SkMatrix::setSkew(SkScalar sx, SkScalar sy) {
    fMat[kMScaleX]  = 1;
    fMat[kMSkewX]   = sx;
    fMat[kMTransX]  = 0;

    fMat[kMSkewY]   = sy;
    fMat[kMScaleY]  = 1;
    fMat[kMTransY]  = 0;
>>>>>>> miniblink49

    fMat[kMPersp0] = fMat[kMPersp1] = 0;
    fMat[kMPersp2] = 1;

    this->setTypeMask(kUnknown_Mask | kOnlyPerspectiveValid_Mask);
}

<<<<<<< HEAD
void SkMatrix::preSkew(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py)
{
    SkMatrix m;
=======
void SkMatrix::preSkew(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    SkMatrix    m;
>>>>>>> miniblink49
    m.setSkew(sx, sy, px, py);
    this->preConcat(m);
}

<<<<<<< HEAD
void SkMatrix::preSkew(SkScalar sx, SkScalar sy)
{
    SkMatrix m;
=======
void SkMatrix::preSkew(SkScalar sx, SkScalar sy) {
    SkMatrix    m;
>>>>>>> miniblink49
    m.setSkew(sx, sy);
    this->preConcat(m);
}

<<<<<<< HEAD
void SkMatrix::postSkew(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py)
{
    SkMatrix m;
=======
void SkMatrix::postSkew(SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    SkMatrix    m;
>>>>>>> miniblink49
    m.setSkew(sx, sy, px, py);
    this->postConcat(m);
}

<<<<<<< HEAD
void SkMatrix::postSkew(SkScalar sx, SkScalar sy)
{
    SkMatrix m;
=======
void SkMatrix::postSkew(SkScalar sx, SkScalar sy) {
    SkMatrix    m;
>>>>>>> miniblink49
    m.setSkew(sx, sy);
    this->postConcat(m);
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool SkMatrix::setRectToRect(const SkRect& src, const SkRect& dst, ScaleToFit align)
{
=======
bool SkMatrix::setRectToRect(const SkRect& src, const SkRect& dst, ScaleToFit align) {
>>>>>>> miniblink49
    if (src.isEmpty()) {
        this->reset();
        return false;
    }

    if (dst.isEmpty()) {
        sk_bzero(fMat, 8 * sizeof(SkScalar));
        fMat[kMPersp2] = 1;
        this->setTypeMask(kScale_Mask | kRectStaysRect_Mask);
    } else {
<<<<<<< HEAD
        SkScalar tx, sx = dst.width() / src.width();
        SkScalar ty, sy = dst.height() / src.height();
        bool xLarger = false;
=======
        SkScalar    tx, sx = dst.width() / src.width();
        SkScalar    ty, sy = dst.height() / src.height();
        bool        xLarger = false;
>>>>>>> miniblink49

        if (align != kFill_ScaleToFit) {
            if (sx > sy) {
                xLarger = true;
                sx = sy;
            } else {
                sy = sx;
            }
        }

        tx = dst.fLeft - src.fLeft * sx;
        ty = dst.fTop - src.fTop * sy;
        if (align == kCenter_ScaleToFit || align == kEnd_ScaleToFit) {
            SkScalar diff;

            if (xLarger) {
                diff = dst.width() - src.width() * sy;
            } else {
                diff = dst.height() - src.height() * sy;
            }

            if (align == kCenter_ScaleToFit) {
                diff = SkScalarHalf(diff);
            }

            if (xLarger) {
                tx += diff;
            } else {
                ty += diff;
            }
        }

        this->setScaleTranslate(sx, sy, tx, ty);
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static inline float muladdmul(float a, float b, float c, float d)
{
    return SkDoubleToFloat((double)a * b + (double)c * d);
}

static inline float rowcol3(const float row[], const float col[])
{
    return row[0] * col[0] + row[1] * col[3] + row[2] * col[6];
}

static bool only_scale_and_translate(unsigned mask)
{
    return 0 == (mask & (SkMatrix::kAffine_Mask | SkMatrix::kPerspective_Mask));
}

void SkMatrix::setConcat(const SkMatrix& a, const SkMatrix& b)
{
=======
static inline float muladdmul(float a, float b, float c, float d) {
    return SkDoubleToFloat((double)a * b + (double)c * d);
}

static inline float rowcol3(const float row[], const float col[]) {
    return row[0] * col[0] + row[1] * col[3] + row[2] * col[6];
}

static bool only_scale_and_translate(unsigned mask) {
    return 0 == (mask & (SkMatrix::kAffine_Mask | SkMatrix::kPerspective_Mask));
}

void SkMatrix::setConcat(const SkMatrix& a, const SkMatrix& b) {
>>>>>>> miniblink49
    TypeMask aType = a.getType();
    TypeMask bType = b.getType();

    if (a.isTriviallyIdentity()) {
        *this = b;
    } else if (b.isTriviallyIdentity()) {
        *this = a;
    } else if (only_scale_and_translate(aType | bType)) {
        this->setScaleTranslate(a.fMat[kMScaleX] * b.fMat[kMScaleX],
<<<<<<< HEAD
            a.fMat[kMScaleY] * b.fMat[kMScaleY],
            a.fMat[kMScaleX] * b.fMat[kMTransX] + a.fMat[kMTransX],
            a.fMat[kMScaleY] * b.fMat[kMTransY] + a.fMat[kMTransY]);
=======
                                a.fMat[kMScaleY] * b.fMat[kMScaleY],
                                a.fMat[kMScaleX] * b.fMat[kMTransX] + a.fMat[kMTransX],
                                a.fMat[kMScaleY] * b.fMat[kMTransY] + a.fMat[kMTransY]);
>>>>>>> miniblink49
    } else {
        SkMatrix tmp;

        if ((aType | bType) & kPerspective_Mask) {
            tmp.fMat[kMScaleX] = rowcol3(&a.fMat[0], &b.fMat[0]);
<<<<<<< HEAD
            tmp.fMat[kMSkewX] = rowcol3(&a.fMat[0], &b.fMat[1]);
            tmp.fMat[kMTransX] = rowcol3(&a.fMat[0], &b.fMat[2]);
            tmp.fMat[kMSkewY] = rowcol3(&a.fMat[3], &b.fMat[0]);
=======
            tmp.fMat[kMSkewX]  = rowcol3(&a.fMat[0], &b.fMat[1]);
            tmp.fMat[kMTransX] = rowcol3(&a.fMat[0], &b.fMat[2]);
            tmp.fMat[kMSkewY]  = rowcol3(&a.fMat[3], &b.fMat[0]);
>>>>>>> miniblink49
            tmp.fMat[kMScaleY] = rowcol3(&a.fMat[3], &b.fMat[1]);
            tmp.fMat[kMTransY] = rowcol3(&a.fMat[3], &b.fMat[2]);
            tmp.fMat[kMPersp0] = rowcol3(&a.fMat[6], &b.fMat[0]);
            tmp.fMat[kMPersp1] = rowcol3(&a.fMat[6], &b.fMat[1]);
            tmp.fMat[kMPersp2] = rowcol3(&a.fMat[6], &b.fMat[2]);

            normalize_perspective(tmp.fMat);
            tmp.setTypeMask(kUnknown_Mask);
        } else {
            tmp.fMat[kMScaleX] = muladdmul(a.fMat[kMScaleX],
<<<<<<< HEAD
                b.fMat[kMScaleX],
                a.fMat[kMSkewX],
                b.fMat[kMSkewY]);

            tmp.fMat[kMSkewX] = muladdmul(a.fMat[kMScaleX],
                b.fMat[kMSkewX],
                a.fMat[kMSkewX],
                b.fMat[kMScaleY]);

            tmp.fMat[kMTransX] = muladdmul(a.fMat[kMScaleX],
                                     b.fMat[kMTransX],
                                     a.fMat[kMSkewX],
                                     b.fMat[kMTransY])
                + a.fMat[kMTransX];

            tmp.fMat[kMSkewY] = muladdmul(a.fMat[kMSkewY],
                b.fMat[kMScaleX],
                a.fMat[kMScaleY],
                b.fMat[kMSkewY]);

            tmp.fMat[kMScaleY] = muladdmul(a.fMat[kMSkewY],
                b.fMat[kMSkewX],
                a.fMat[kMScaleY],
                b.fMat[kMScaleY]);

            tmp.fMat[kMTransY] = muladdmul(a.fMat[kMSkewY],
                                     b.fMat[kMTransX],
                                     a.fMat[kMScaleY],
                                     b.fMat[kMTransY])
                + a.fMat[kMTransY];
=======
                                           b.fMat[kMScaleX],
                                           a.fMat[kMSkewX],
                                           b.fMat[kMSkewY]);

            tmp.fMat[kMSkewX]  = muladdmul(a.fMat[kMScaleX],
                                           b.fMat[kMSkewX],
                                           a.fMat[kMSkewX],
                                           b.fMat[kMScaleY]);

            tmp.fMat[kMTransX] = muladdmul(a.fMat[kMScaleX],
                                           b.fMat[kMTransX],
                                           a.fMat[kMSkewX],
                                           b.fMat[kMTransY]) + a.fMat[kMTransX];

            tmp.fMat[kMSkewY]  = muladdmul(a.fMat[kMSkewY],
                                           b.fMat[kMScaleX],
                                           a.fMat[kMScaleY],
                                           b.fMat[kMSkewY]);

            tmp.fMat[kMScaleY] = muladdmul(a.fMat[kMSkewY],
                                           b.fMat[kMSkewX],
                                           a.fMat[kMScaleY],
                                           b.fMat[kMScaleY]);

            tmp.fMat[kMTransY] = muladdmul(a.fMat[kMSkewY],
                                           b.fMat[kMTransX],
                                           a.fMat[kMScaleY],
                                           b.fMat[kMTransY]) + a.fMat[kMTransY];
>>>>>>> miniblink49

            tmp.fMat[kMPersp0] = 0;
            tmp.fMat[kMPersp1] = 0;
            tmp.fMat[kMPersp2] = 1;
            //SkDebugf("Concat mat non-persp type: %d\n", tmp.getType());
            //SkASSERT(!(tmp.getType() & kPerspective_Mask));
            tmp.setTypeMask(kUnknown_Mask | kOnlyPerspectiveValid_Mask);
        }
        *this = tmp;
    }
}

<<<<<<< HEAD
void SkMatrix::preConcat(const SkMatrix& mat)
{
    // check for identity first, so we don't do a needless copy of ourselves
    // to ourselves inside setConcat()
    if (!mat.isIdentity()) {
=======
void SkMatrix::preConcat(const SkMatrix& mat) {
    // check for identity first, so we don't do a needless copy of ourselves
    // to ourselves inside setConcat()
    if(!mat.isIdentity()) {
>>>>>>> miniblink49
        this->setConcat(*this, mat);
    }
}

<<<<<<< HEAD
void SkMatrix::postConcat(const SkMatrix& mat)
{
=======
void SkMatrix::postConcat(const SkMatrix& mat) {
>>>>>>> miniblink49
    // check for identity first, so we don't do a needless copy of ourselves
    // to ourselves inside setConcat()
    if (!mat.isIdentity()) {
        this->setConcat(mat, *this);
    }
}

///////////////////////////////////////////////////////////////////////////////

/*  Matrix inversion is very expensive, but also the place where keeping
    precision may be most important (here and matrix concat). Hence to avoid
    bitmap blitting artifacts when walking the inverse, we use doubles for
    the intermediate math, even though we know that is more expensive.
 */

static inline SkScalar scross_dscale(SkScalar a, SkScalar b,
<<<<<<< HEAD
    SkScalar c, SkScalar d, double scale)
{
    return SkDoubleToScalar(scross(a, b, c, d) * scale);
}

static inline double dcross(double a, double b, double c, double d)
{
=======
                                     SkScalar c, SkScalar d, double scale) {
    return SkDoubleToScalar(scross(a, b, c, d) * scale);
}

static inline double dcross(double a, double b, double c, double d) {
>>>>>>> miniblink49
    return a * b - c * d;
}

static inline SkScalar dcross_dscale(double a, double b,
<<<<<<< HEAD
    double c, double d, double scale)
{
    return SkDoubleToScalar(dcross(a, b, c, d) * scale);
}

static double sk_inv_determinant(const float mat[9], int isPerspective)
{
    double det;

    if (isPerspective) {
        det = mat[SkMatrix::kMScaleX] * dcross(mat[SkMatrix::kMScaleY], mat[SkMatrix::kMPersp2], mat[SkMatrix::kMTransY], mat[SkMatrix::kMPersp1])
            + mat[SkMatrix::kMSkewX] * dcross(mat[SkMatrix::kMTransY], mat[SkMatrix::kMPersp0], mat[SkMatrix::kMSkewY], mat[SkMatrix::kMPersp2])
            + mat[SkMatrix::kMTransX] * dcross(mat[SkMatrix::kMSkewY], mat[SkMatrix::kMPersp1], mat[SkMatrix::kMScaleY], mat[SkMatrix::kMPersp0]);
    } else {
        det = dcross(mat[SkMatrix::kMScaleX], mat[SkMatrix::kMScaleY],
            mat[SkMatrix::kMSkewX], mat[SkMatrix::kMSkewY]);
=======
                                     double c, double d, double scale) {
    return SkDoubleToScalar(dcross(a, b, c, d) * scale);
}

static double sk_inv_determinant(const float mat[9], int isPerspective) {
    double det;

    if (isPerspective) {
        det = mat[SkMatrix::kMScaleX] *
              dcross(mat[SkMatrix::kMScaleY], mat[SkMatrix::kMPersp2],
                     mat[SkMatrix::kMTransY], mat[SkMatrix::kMPersp1])
              +
              mat[SkMatrix::kMSkewX]  *
              dcross(mat[SkMatrix::kMTransY], mat[SkMatrix::kMPersp0],
                     mat[SkMatrix::kMSkewY],  mat[SkMatrix::kMPersp2])
              +
              mat[SkMatrix::kMTransX] *
              dcross(mat[SkMatrix::kMSkewY],  mat[SkMatrix::kMPersp1],
                     mat[SkMatrix::kMScaleY], mat[SkMatrix::kMPersp0]);
    } else {
        det = dcross(mat[SkMatrix::kMScaleX], mat[SkMatrix::kMScaleY],
                     mat[SkMatrix::kMSkewX], mat[SkMatrix::kMSkewY]);
>>>>>>> miniblink49
    }

    // Since the determinant is on the order of the cube of the matrix members,
    // compare to the cube of the default nearly-zero constant (although an
    // estimate of the condition number would be better if it wasn't so expensive).
    if (SkScalarNearlyZero((float)det, SK_ScalarNearlyZero * SK_ScalarNearlyZero * SK_ScalarNearlyZero)) {
        return 0;
    }
    return 1.0 / det;
}

<<<<<<< HEAD
void SkMatrix::SetAffineIdentity(SkScalar affine[6])
{
=======
void SkMatrix::SetAffineIdentity(SkScalar affine[6]) {
>>>>>>> miniblink49
    affine[kAScaleX] = 1;
    affine[kASkewY] = 0;
    affine[kASkewX] = 0;
    affine[kAScaleY] = 1;
    affine[kATransX] = 0;
    affine[kATransY] = 0;
}

<<<<<<< HEAD
bool SkMatrix::asAffine(SkScalar affine[6]) const
{
=======
bool SkMatrix::asAffine(SkScalar affine[6]) const {
>>>>>>> miniblink49
    if (this->hasPerspective()) {
        return false;
    }
    if (affine) {
        affine[kAScaleX] = this->fMat[kMScaleX];
        affine[kASkewY] = this->fMat[kMSkewY];
        affine[kASkewX] = this->fMat[kMSkewX];
        affine[kAScaleY] = this->fMat[kMScaleY];
        affine[kATransX] = this->fMat[kMTransX];
        affine[kATransY] = this->fMat[kMTransY];
    }
    return true;
}

<<<<<<< HEAD
void SkMatrix::ComputeInv(SkScalar dst[9], const SkScalar src[9], double invDet, bool isPersp)
{
=======
void SkMatrix::ComputeInv(SkScalar dst[9], const SkScalar src[9], double invDet, bool isPersp) {
>>>>>>> miniblink49
    SkASSERT(src != dst);
    SkASSERT(src && dst);

    if (isPersp) {
        dst[kMScaleX] = scross_dscale(src[kMScaleY], src[kMPersp2], src[kMTransY], src[kMPersp1], invDet);
<<<<<<< HEAD
        dst[kMSkewX] = scross_dscale(src[kMTransX], src[kMPersp1], src[kMSkewX], src[kMPersp2], invDet);
        dst[kMTransX] = scross_dscale(src[kMSkewX], src[kMTransY], src[kMTransX], src[kMScaleY], invDet);

        dst[kMSkewY] = scross_dscale(src[kMTransY], src[kMPersp0], src[kMSkewY], src[kMPersp2], invDet);
        dst[kMScaleY] = scross_dscale(src[kMScaleX], src[kMPersp2], src[kMTransX], src[kMPersp0], invDet);
        dst[kMTransY] = scross_dscale(src[kMTransX], src[kMSkewY], src[kMScaleX], src[kMTransY], invDet);

        dst[kMPersp0] = scross_dscale(src[kMSkewY], src[kMPersp1], src[kMScaleY], src[kMPersp0], invDet);
        dst[kMPersp1] = scross_dscale(src[kMSkewX], src[kMPersp0], src[kMScaleX], src[kMPersp1], invDet);
        dst[kMPersp2] = scross_dscale(src[kMScaleX], src[kMScaleY], src[kMSkewX], src[kMSkewY], invDet);
    } else { // not perspective
        dst[kMScaleX] = SkDoubleToScalar(src[kMScaleY] * invDet);
        dst[kMSkewX] = SkDoubleToScalar(-src[kMSkewX] * invDet);
        dst[kMTransX] = dcross_dscale(src[kMSkewX], src[kMTransY], src[kMScaleY], src[kMTransX], invDet);

        dst[kMSkewY] = SkDoubleToScalar(-src[kMSkewY] * invDet);
=======
        dst[kMSkewX]  = scross_dscale(src[kMTransX], src[kMPersp1], src[kMSkewX],  src[kMPersp2], invDet);
        dst[kMTransX] = scross_dscale(src[kMSkewX],  src[kMTransY], src[kMTransX], src[kMScaleY], invDet);

        dst[kMSkewY]  = scross_dscale(src[kMTransY], src[kMPersp0], src[kMSkewY],  src[kMPersp2], invDet);
        dst[kMScaleY] = scross_dscale(src[kMScaleX], src[kMPersp2], src[kMTransX], src[kMPersp0], invDet);
        dst[kMTransY] = scross_dscale(src[kMTransX], src[kMSkewY],  src[kMScaleX], src[kMTransY], invDet);

        dst[kMPersp0] = scross_dscale(src[kMSkewY],  src[kMPersp1], src[kMScaleY], src[kMPersp0], invDet);
        dst[kMPersp1] = scross_dscale(src[kMSkewX],  src[kMPersp0], src[kMScaleX], src[kMPersp1], invDet);
        dst[kMPersp2] = scross_dscale(src[kMScaleX], src[kMScaleY], src[kMSkewX],  src[kMSkewY],  invDet);
    } else {   // not perspective
        dst[kMScaleX] = SkDoubleToScalar(src[kMScaleY] * invDet);
        dst[kMSkewX]  = SkDoubleToScalar(-src[kMSkewX] * invDet);
        dst[kMTransX] = dcross_dscale(src[kMSkewX], src[kMTransY], src[kMScaleY], src[kMTransX], invDet);

        dst[kMSkewY]  = SkDoubleToScalar(-src[kMSkewY] * invDet);
>>>>>>> miniblink49
        dst[kMScaleY] = SkDoubleToScalar(src[kMScaleX] * invDet);
        dst[kMTransY] = dcross_dscale(src[kMSkewY], src[kMTransX], src[kMScaleX], src[kMTransY], invDet);

        dst[kMPersp0] = 0;
        dst[kMPersp1] = 0;
        dst[kMPersp2] = 1;
    }
}

<<<<<<< HEAD
bool SkMatrix::invertNonIdentity(SkMatrix* inv) const
{
=======
bool SkMatrix::invertNonIdentity(SkMatrix* inv) const {
>>>>>>> miniblink49
    SkASSERT(!this->isIdentity());

    TypeMask mask = this->getType();

    if (0 == (mask & ~(kScale_Mask | kTranslate_Mask))) {
        bool invertible = true;
        if (inv) {
            if (mask & kScale_Mask) {
                SkScalar invX = fMat[kMScaleX];
                SkScalar invY = fMat[kMScaleY];
                if (0 == invX || 0 == invY) {
                    return false;
                }
                invX = SkScalarInvert(invX);
                invY = SkScalarInvert(invY);

                // Must be careful when writing to inv, since it may be the
                // same memory as this.

<<<<<<< HEAD
                inv->fMat[kMSkewX] = inv->fMat[kMSkewY] = inv->fMat[kMPersp0] = inv->fMat[kMPersp1] = 0;
=======
                inv->fMat[kMSkewX] = inv->fMat[kMSkewY] =
                inv->fMat[kMPersp0] = inv->fMat[kMPersp1] = 0;
>>>>>>> miniblink49

                inv->fMat[kMScaleX] = invX;
                inv->fMat[kMScaleY] = invY;
                inv->fMat[kMPersp2] = 1;
                inv->fMat[kMTransX] = -fMat[kMTransX] * invX;
                inv->fMat[kMTransY] = -fMat[kMTransY] * invY;

                inv->setTypeMask(mask | kRectStaysRect_Mask);
            } else {
                // translate only
                inv->setTranslate(-fMat[kMTransX], -fMat[kMTransY]);
            }
<<<<<<< HEAD
        } else { // inv is nullptr, just check if we're invertible
=======
        } else {    // inv is NULL, just check if we're invertible
>>>>>>> miniblink49
            if (!fMat[kMScaleX] || !fMat[kMScaleY]) {
                invertible = false;
            }
        }
        return invertible;
    }

<<<<<<< HEAD
    int isPersp = mask & kPerspective_Mask;
=======
    int    isPersp = mask & kPerspective_Mask;
>>>>>>> miniblink49
    double invDet = sk_inv_determinant(fMat, isPersp);

    if (invDet == 0) { // underflow
        return false;
    }

    bool applyingInPlace = (inv == this);

    SkMatrix* tmp = inv;

    SkMatrix storage;
<<<<<<< HEAD
    if (applyingInPlace || nullptr == tmp) {
        tmp = &storage; // we either need to avoid trampling memory or have no memory
=======
    if (applyingInPlace || NULL == tmp) {
        tmp = &storage;     // we either need to avoid trampling memory or have no memory
>>>>>>> miniblink49
    }

    ComputeInv(tmp->fMat, fMat, invDet, isPersp);
    if (!tmp->isFinite()) {
        return false;
    }

    tmp->setTypeMask(fTypeMask);

    if (applyingInPlace) {
        *inv = storage; // need to copy answer back
    }

    return true;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkMatrix::Identity_pts(const SkMatrix& m, SkPoint dst[], const SkPoint src[], int count)
{
=======
void SkMatrix::Identity_pts(const SkMatrix& m, SkPoint dst[], const SkPoint src[], int count) {
>>>>>>> miniblink49
    SkASSERT(m.getType() == 0);

    if (dst != src && count > 0) {
        memcpy(dst, src, count * sizeof(SkPoint));
    }
}

<<<<<<< HEAD
void SkMatrix::Trans_pts(const SkMatrix& m, SkPoint dst[], const SkPoint src[], int count)
{
    SkASSERT(m.getType() <= SkMatrix::kTranslate_Mask);
=======
void SkMatrix::Trans_pts(const SkMatrix& m, SkPoint dst[], const SkPoint src[], int count) {
    SkASSERT(m.getType() <= kTranslate_Mask);

>>>>>>> miniblink49
    if (count > 0) {
        SkScalar tx = m.getTranslateX();
        SkScalar ty = m.getTranslateY();
        if (count & 1) {
            dst->fX = src->fX + tx;
            dst->fY = src->fY + ty;
            src += 1;
            dst += 1;
        }
        Sk4s trans4(tx, ty, tx, ty);
        count >>= 1;
        if (count & 1) {
<<<<<<< HEAD
            (Sk4s::Load(src) + trans4).store(dst);
=======
            (Sk4s::Load(&src->fX) + trans4).store(&dst->fX);
>>>>>>> miniblink49
            src += 2;
            dst += 2;
        }
        count >>= 1;
        for (int i = 0; i < count; ++i) {
<<<<<<< HEAD
            (Sk4s::Load(src + 0) + trans4).store(dst + 0);
            (Sk4s::Load(src + 2) + trans4).store(dst + 2);
=======
            (Sk4s::Load(&src[0].fX) + trans4).store(&dst[0].fX);
            (Sk4s::Load(&src[2].fX) + trans4).store(&dst[2].fX);
>>>>>>> miniblink49
            src += 4;
            dst += 4;
        }
    }
}

<<<<<<< HEAD
void SkMatrix::Scale_pts(const SkMatrix& m, SkPoint dst[], const SkPoint src[], int count)
{
    SkASSERT(m.getType() <= (SkMatrix::kScale_Mask | SkMatrix::kTranslate_Mask));
=======
void SkMatrix::Scale_pts(const SkMatrix& m, SkPoint dst[], const SkPoint src[], int count) {
    SkASSERT(m.getType() <= (kScale_Mask | kTranslate_Mask));

>>>>>>> miniblink49
    if (count > 0) {
        SkScalar tx = m.getTranslateX();
        SkScalar ty = m.getTranslateY();
        SkScalar sx = m.getScaleX();
        SkScalar sy = m.getScaleY();
        if (count & 1) {
            dst->fX = src->fX * sx + tx;
            dst->fY = src->fY * sy + ty;
            src += 1;
            dst += 1;
        }
        Sk4s trans4(tx, ty, tx, ty);
        Sk4s scale4(sx, sy, sx, sy);
        count >>= 1;
        if (count & 1) {
<<<<<<< HEAD
            (Sk4s::Load(src) * scale4 + trans4).store(dst);
=======
            (Sk4s::Load(&src->fX) * scale4 + trans4).store(&dst->fX);
>>>>>>> miniblink49
            src += 2;
            dst += 2;
        }
        count >>= 1;
        for (int i = 0; i < count; ++i) {
<<<<<<< HEAD
            (Sk4s::Load(src + 0) * scale4 + trans4).store(dst + 0);
            (Sk4s::Load(src + 2) * scale4 + trans4).store(dst + 2);
=======
            (Sk4s::Load(&src[0].fX) * scale4 + trans4).store(&dst[0].fX);
            (Sk4s::Load(&src[2].fX) * scale4 + trans4).store(&dst[2].fX);
>>>>>>> miniblink49
            src += 4;
            dst += 4;
        }
    }
}

void SkMatrix::Persp_pts(const SkMatrix& m, SkPoint dst[],
<<<<<<< HEAD
    const SkPoint src[], int count)
{
=======
                         const SkPoint src[], int count) {
>>>>>>> miniblink49
    SkASSERT(m.hasPerspective());

    if (count > 0) {
        do {
            SkScalar sy = src->fY;
            SkScalar sx = src->fX;
            src += 1;

<<<<<<< HEAD
            SkScalar x = sdot(sx, m.fMat[kMScaleX], sy, m.fMat[kMSkewX]) + m.fMat[kMTransX];
            SkScalar y = sdot(sx, m.fMat[kMSkewY], sy, m.fMat[kMScaleY]) + m.fMat[kMTransY];
=======
            SkScalar x = sdot(sx, m.fMat[kMScaleX], sy, m.fMat[kMSkewX])  + m.fMat[kMTransX];
            SkScalar y = sdot(sx, m.fMat[kMSkewY],  sy, m.fMat[kMScaleY]) + m.fMat[kMTransY];
>>>>>>> miniblink49
#ifdef SK_LEGACY_MATRIX_MATH_ORDER
            SkScalar z = sx * m.fMat[kMPersp0] + (sy * m.fMat[kMPersp1] + m.fMat[kMPersp2]);
#else
            SkScalar z = sdot(sx, m.fMat[kMPersp0], sy, m.fMat[kMPersp1]) + m.fMat[kMPersp2];
#endif
            if (z) {
                z = SkScalarFastInvert(z);
            }

            dst->fY = y * z;
            dst->fX = x * z;
            dst += 1;
        } while (--count);
    }
}

<<<<<<< HEAD
void SkMatrix::Affine_vpts(const SkMatrix& m, SkPoint dst[], const SkPoint src[], int count)
{
    SkASSERT(m.getType() != SkMatrix::kPerspective_Mask);
=======
void SkMatrix::Affine_vpts(const SkMatrix& m, SkPoint dst[], const SkPoint src[], int count) {
    SkASSERT(m.getType() != kPerspective_Mask);

>>>>>>> miniblink49
    if (count > 0) {
        SkScalar tx = m.getTranslateX();
        SkScalar ty = m.getTranslateY();
        SkScalar sx = m.getScaleX();
        SkScalar sy = m.getScaleY();
        SkScalar kx = m.getSkewX();
        SkScalar ky = m.getSkewY();
        if (count & 1) {
            dst->set(src->fX * sx + src->fY * kx + tx,
<<<<<<< HEAD
                src->fX * ky + src->fY * sy + ty);
=======
                     src->fX * ky + src->fY * sy + ty);
>>>>>>> miniblink49
            src += 1;
            dst += 1;
        }
        Sk4s trans4(tx, ty, tx, ty);
        Sk4s scale4(sx, sy, sx, sy);
<<<<<<< HEAD
        Sk4s skew4(kx, ky, kx, ky); // applied to swizzle of src4
        count >>= 1;
        for (int i = 0; i < count; ++i) {
            Sk4s src4 = Sk4s::Load(src);
            Sk4s swz4 = SkNx_shuffle<1, 0, 3, 2>(src4); // y0 x0, y1 x1
            (src4 * scale4 + swz4 * skew4 + trans4).store(dst);
=======
        Sk4s  skew4(kx, ky, kx, ky);    // applied to swizzle of src4
        count >>= 1;
        for (int i = 0; i < count; ++i) {
            Sk4s src4 = Sk4s::Load(&src->fX);
            Sk4s swz4(src[0].fY, src[0].fX, src[1].fY, src[1].fX);  // need ABCD -> BADC
            (src4 * scale4 + swz4 * skew4 + trans4).store(&dst->fX);
>>>>>>> miniblink49
            src += 2;
            dst += 2;
        }
    }
}

const SkMatrix::MapPtsProc SkMatrix::gMapPtsProcs[] = {
    SkMatrix::Identity_pts, SkMatrix::Trans_pts,
<<<<<<< HEAD
    SkMatrix::Scale_pts, SkMatrix::Scale_pts,
    SkMatrix::Affine_vpts, SkMatrix::Affine_vpts,
    SkMatrix::Affine_vpts, SkMatrix::Affine_vpts,
    // repeat the persp proc 8 times
    SkMatrix::Persp_pts, SkMatrix::Persp_pts,
    SkMatrix::Persp_pts, SkMatrix::Persp_pts,
    SkMatrix::Persp_pts, SkMatrix::Persp_pts,
    SkMatrix::Persp_pts, SkMatrix::Persp_pts
=======
    SkMatrix::Scale_pts,   SkMatrix::Scale_pts,
    SkMatrix::Affine_vpts,  SkMatrix::Affine_vpts,
    SkMatrix::Affine_vpts,  SkMatrix::Affine_vpts,
    // repeat the persp proc 8 times
    SkMatrix::Persp_pts,    SkMatrix::Persp_pts,
    SkMatrix::Persp_pts,    SkMatrix::Persp_pts,
    SkMatrix::Persp_pts,    SkMatrix::Persp_pts,
    SkMatrix::Persp_pts,    SkMatrix::Persp_pts
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkMatrix::mapHomogeneousPoints(SkScalar dst[], const SkScalar src[], int count) const
{
    SkASSERT((dst && src && count > 0) || 0 == count);
    // no partial overlap
    SkASSERT(src == dst || &dst[3 * count] <= &src[0] || &src[3 * count] <= &dst[0]);

    if (count > 0) {
        if (this->isIdentity()) {
            memcpy(dst, src, 3 * count * sizeof(SkScalar));
=======
void SkMatrix::mapHomogeneousPoints(SkScalar dst[], const SkScalar src[], int count) const {
    SkASSERT((dst && src && count > 0) || 0 == count);
    // no partial overlap
    SkASSERT(src == dst || &dst[3*count] <= &src[0] || &src[3*count] <= &dst[0]);

    if (count > 0) {
        if (this->isIdentity()) {
            memcpy(dst, src, 3*count*sizeof(SkScalar));
>>>>>>> miniblink49
            return;
        }
        do {
            SkScalar sx = src[0];
            SkScalar sy = src[1];
            SkScalar sw = src[2];
            src += 3;

<<<<<<< HEAD
            SkScalar x = sdot(sx, fMat[kMScaleX], sy, fMat[kMSkewX], sw, fMat[kMTransX]);
            SkScalar y = sdot(sx, fMat[kMSkewY], sy, fMat[kMScaleY], sw, fMat[kMTransY]);
=======
            SkScalar x = sdot(sx, fMat[kMScaleX], sy, fMat[kMSkewX],  sw, fMat[kMTransX]);
            SkScalar y = sdot(sx, fMat[kMSkewY],  sy, fMat[kMScaleY], sw, fMat[kMTransY]);
>>>>>>> miniblink49
            SkScalar w = sdot(sx, fMat[kMPersp0], sy, fMat[kMPersp1], sw, fMat[kMPersp2]);

            dst[0] = x;
            dst[1] = y;
            dst[2] = w;
            dst += 3;
        } while (--count);
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkMatrix::mapVectors(SkPoint dst[], const SkPoint src[], int count) const
{
=======
void SkMatrix::mapVectors(SkPoint dst[], const SkPoint src[], int count) const {
>>>>>>> miniblink49
    if (this->hasPerspective()) {
        SkPoint origin;

        MapXYProc proc = this->getMapXYProc();
        proc(*this, 0, 0, &origin);

        for (int i = count - 1; i >= 0; --i) {
            SkPoint tmp;

            proc(*this, src[i].fX, src[i].fY, &tmp);
            dst[i].set(tmp.fX - origin.fX, tmp.fY - origin.fY);
        }
    } else {
        SkMatrix tmp = *this;

        tmp.fMat[kMTransX] = tmp.fMat[kMTransY] = 0;
        tmp.clearTypeMask(kTranslate_Mask);
        tmp.mapPoints(dst, src, count);
    }
}

<<<<<<< HEAD
bool SkMatrix::mapRect(SkRect* dst, const SkRect& src) const
{
=======
bool SkMatrix::mapRect(SkRect* dst, const SkRect& src) const {
>>>>>>> miniblink49
    SkASSERT(dst);

    if (this->rectStaysRect()) {
        this->mapPoints((SkPoint*)dst, (const SkPoint*)&src, 2);
        dst->sort();
        return true;
    } else {
        SkPoint quad[4];

        src.toQuad(quad);
        this->mapPoints(quad, quad, 4);
        dst->set(quad, 4);
        return false;
    }
}

<<<<<<< HEAD
SkScalar SkMatrix::mapRadius(SkScalar radius) const
{
    SkVector vec[2];
=======
SkScalar SkMatrix::mapRadius(SkScalar radius) const {
    SkVector    vec[2];
>>>>>>> miniblink49

    vec[0].set(radius, 0);
    vec[1].set(0, radius);
    this->mapVectors(vec, 2);

    SkScalar d0 = vec[0].length();
    SkScalar d1 = vec[1].length();

    // return geometric mean
    return SkScalarSqrt(d0 * d1);
}

///////////////////////////////////////////////////////////////////////////////

void SkMatrix::Persp_xy(const SkMatrix& m, SkScalar sx, SkScalar sy,
<<<<<<< HEAD
    SkPoint* pt)
{
    SkASSERT(m.hasPerspective());

    SkScalar x = sdot(sx, m.fMat[kMScaleX], sy, m.fMat[kMSkewX]) + m.fMat[kMTransX];
    SkScalar y = sdot(sx, m.fMat[kMSkewY], sy, m.fMat[kMScaleY]) + m.fMat[kMTransY];
=======
                        SkPoint* pt) {
    SkASSERT(m.hasPerspective());

    SkScalar x = sdot(sx, m.fMat[kMScaleX], sy, m.fMat[kMSkewX])  + m.fMat[kMTransX];
    SkScalar y = sdot(sx, m.fMat[kMSkewY],  sy, m.fMat[kMScaleY]) + m.fMat[kMTransY];
>>>>>>> miniblink49
    SkScalar z = sdot(sx, m.fMat[kMPersp0], sy, m.fMat[kMPersp1]) + m.fMat[kMPersp2];
    if (z) {
        z = SkScalarFastInvert(z);
    }
    pt->fX = x * z;
    pt->fY = y * z;
}

void SkMatrix::RotTrans_xy(const SkMatrix& m, SkScalar sx, SkScalar sy,
<<<<<<< HEAD
    SkPoint* pt)
{
    SkASSERT((m.getType() & (kAffine_Mask | kPerspective_Mask)) == kAffine_Mask);

#ifdef SK_LEGACY_MATRIX_MATH_ORDER
    pt->fX = sx * m.fMat[kMScaleX] + (sy * m.fMat[kMSkewX] + m.fMat[kMTransX]);
    pt->fY = sx * m.fMat[kMSkewY] + (sy * m.fMat[kMScaleY] + m.fMat[kMTransY]);
#else
    pt->fX = sdot(sx, m.fMat[kMScaleX], sy, m.fMat[kMSkewX]) + m.fMat[kMTransX];
    pt->fY = sdot(sx, m.fMat[kMSkewY], sy, m.fMat[kMScaleY]) + m.fMat[kMTransY];
=======
                           SkPoint* pt) {
    SkASSERT((m.getType() & (kAffine_Mask | kPerspective_Mask)) == kAffine_Mask);

#ifdef SK_LEGACY_MATRIX_MATH_ORDER
    pt->fX = sx * m.fMat[kMScaleX] + (sy * m.fMat[kMSkewX]  +  m.fMat[kMTransX]);
    pt->fY = sx * m.fMat[kMSkewY]  + (sy * m.fMat[kMScaleY] + m.fMat[kMTransY]);
#else
    pt->fX = sdot(sx, m.fMat[kMScaleX], sy, m.fMat[kMSkewX])  + m.fMat[kMTransX];
    pt->fY = sdot(sx, m.fMat[kMSkewY],  sy, m.fMat[kMScaleY]) + m.fMat[kMTransY];
>>>>>>> miniblink49
#endif
}

void SkMatrix::Rot_xy(const SkMatrix& m, SkScalar sx, SkScalar sy,
<<<<<<< HEAD
    SkPoint* pt)
{
    SkASSERT((m.getType() & (kAffine_Mask | kPerspective_Mask)) == kAffine_Mask);
=======
                      SkPoint* pt) {
    SkASSERT((m.getType() & (kAffine_Mask | kPerspective_Mask))== kAffine_Mask);
>>>>>>> miniblink49
    SkASSERT(0 == m.fMat[kMTransX]);
    SkASSERT(0 == m.fMat[kMTransY]);

#ifdef SK_LEGACY_MATRIX_MATH_ORDER
<<<<<<< HEAD
    pt->fX = sx * m.fMat[kMScaleX] + (sy * m.fMat[kMSkewX] + m.fMat[kMTransX]);
    pt->fY = sx * m.fMat[kMSkewY] + (sy * m.fMat[kMScaleY] + m.fMat[kMTransY]);
#else
    pt->fX = sdot(sx, m.fMat[kMScaleX], sy, m.fMat[kMSkewX]) + m.fMat[kMTransX];
    pt->fY = sdot(sx, m.fMat[kMSkewY], sy, m.fMat[kMScaleY]) + m.fMat[kMTransY];
=======
    pt->fX = sx * m.fMat[kMScaleX] + (sy * m.fMat[kMSkewX]  + m.fMat[kMTransX]);
    pt->fY = sx * m.fMat[kMSkewY]  + (sy * m.fMat[kMScaleY] + m.fMat[kMTransY]);
#else
    pt->fX = sdot(sx, m.fMat[kMScaleX], sy, m.fMat[kMSkewX])  + m.fMat[kMTransX];
    pt->fY = sdot(sx, m.fMat[kMSkewY],  sy, m.fMat[kMScaleY]) + m.fMat[kMTransY];
>>>>>>> miniblink49
#endif
}

void SkMatrix::ScaleTrans_xy(const SkMatrix& m, SkScalar sx, SkScalar sy,
<<<<<<< HEAD
    SkPoint* pt)
{
    SkASSERT((m.getType() & (kScale_Mask | kAffine_Mask | kPerspective_Mask))
        == kScale_Mask);
=======
                             SkPoint* pt) {
    SkASSERT((m.getType() & (kScale_Mask | kAffine_Mask | kPerspective_Mask))
             == kScale_Mask);
>>>>>>> miniblink49

    pt->fX = sx * m.fMat[kMScaleX] + m.fMat[kMTransX];
    pt->fY = sy * m.fMat[kMScaleY] + m.fMat[kMTransY];
}

void SkMatrix::Scale_xy(const SkMatrix& m, SkScalar sx, SkScalar sy,
<<<<<<< HEAD
    SkPoint* pt)
{
    SkASSERT((m.getType() & (kScale_Mask | kAffine_Mask | kPerspective_Mask))
        == kScale_Mask);
=======
                        SkPoint* pt) {
    SkASSERT((m.getType() & (kScale_Mask | kAffine_Mask | kPerspective_Mask))
             == kScale_Mask);
>>>>>>> miniblink49
    SkASSERT(0 == m.fMat[kMTransX]);
    SkASSERT(0 == m.fMat[kMTransY]);

    pt->fX = sx * m.fMat[kMScaleX];
    pt->fY = sy * m.fMat[kMScaleY];
}

void SkMatrix::Trans_xy(const SkMatrix& m, SkScalar sx, SkScalar sy,
<<<<<<< HEAD
    SkPoint* pt)
{
=======
                        SkPoint* pt) {
>>>>>>> miniblink49
    SkASSERT(m.getType() == kTranslate_Mask);

    pt->fX = sx + m.fMat[kMTransX];
    pt->fY = sy + m.fMat[kMTransY];
}

void SkMatrix::Identity_xy(const SkMatrix& m, SkScalar sx, SkScalar sy,
<<<<<<< HEAD
    SkPoint* pt)
{
=======
                           SkPoint* pt) {
>>>>>>> miniblink49
    SkASSERT(0 == m.getType());

    pt->fX = sx;
    pt->fY = sy;
}

const SkMatrix::MapXYProc SkMatrix::gMapXYProcs[] = {
    SkMatrix::Identity_xy, SkMatrix::Trans_xy,
<<<<<<< HEAD
    SkMatrix::Scale_xy, SkMatrix::ScaleTrans_xy,
    SkMatrix::Rot_xy, SkMatrix::RotTrans_xy,
    SkMatrix::Rot_xy, SkMatrix::RotTrans_xy,
    // repeat the persp proc 8 times
    SkMatrix::Persp_xy, SkMatrix::Persp_xy,
    SkMatrix::Persp_xy, SkMatrix::Persp_xy,
    SkMatrix::Persp_xy, SkMatrix::Persp_xy,
    SkMatrix::Persp_xy, SkMatrix::Persp_xy
=======
    SkMatrix::Scale_xy,    SkMatrix::ScaleTrans_xy,
    SkMatrix::Rot_xy,      SkMatrix::RotTrans_xy,
    SkMatrix::Rot_xy,      SkMatrix::RotTrans_xy,
    // repeat the persp proc 8 times
    SkMatrix::Persp_xy,    SkMatrix::Persp_xy,
    SkMatrix::Persp_xy,    SkMatrix::Persp_xy,
    SkMatrix::Persp_xy,    SkMatrix::Persp_xy,
    SkMatrix::Persp_xy,    SkMatrix::Persp_xy
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

// if its nearly zero (just made up 26, perhaps it should be bigger or smaller)
<<<<<<< HEAD
#define PerspNearlyZero(x) SkScalarNearlyZero(x, (1.0f / (1 << 26)))

bool SkMatrix::isFixedStepInX() const
{
    return PerspNearlyZero(fMat[kMPersp0]);
}

SkVector SkMatrix::fixedStepInX(SkScalar y) const
{
    SkASSERT(PerspNearlyZero(fMat[kMPersp0]));
    if (PerspNearlyZero(fMat[kMPersp1]) && PerspNearlyZero(fMat[kMPersp2] - 1)) {
        return SkVector::Make(fMat[kMScaleX], fMat[kMSkewY]);
    } else {
        SkScalar z = y * fMat[kMPersp1] + fMat[kMPersp2];
        return SkVector::Make(fMat[kMScaleX] / z, fMat[kMSkewY] / z);
    }
=======
#define PerspNearlyZero(x)  SkScalarNearlyZero(x, (1.0f / (1 << 26)))

bool SkMatrix::fixedStepInX(SkScalar y, SkFixed* stepX, SkFixed* stepY) const {
    if (PerspNearlyZero(fMat[kMPersp0])) {
        if (stepX || stepY) {
            if (PerspNearlyZero(fMat[kMPersp1]) &&
                    PerspNearlyZero(fMat[kMPersp2] - 1)) {
                if (stepX) {
                    *stepX = SkScalarToFixed(fMat[kMScaleX]);
                }
                if (stepY) {
                    *stepY = SkScalarToFixed(fMat[kMSkewY]);
                }
            } else {
                SkScalar z = y * fMat[kMPersp1] + fMat[kMPersp2];
                if (stepX) {
                    *stepX = SkScalarToFixed(fMat[kMScaleX] / z);
                }
                if (stepY) {
                    *stepY = SkScalarToFixed(fMat[kMSkewY] / z);
                }
            }
        }
        return true;
    }
    return false;
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

#include "SkPerspIter.h"

SkPerspIter::SkPerspIter(const SkMatrix& m, SkScalar x0, SkScalar y0, int count)
<<<<<<< HEAD
    : fMatrix(m)
    , fSX(x0)
    , fSY(y0)
    , fCount(count)
{
=======
        : fMatrix(m), fSX(x0), fSY(y0), fCount(count) {
>>>>>>> miniblink49
    SkPoint pt;

    SkMatrix::Persp_xy(m, x0, y0, &pt);
    fX = SkScalarToFixed(pt.fX);
    fY = SkScalarToFixed(pt.fY);
}

<<<<<<< HEAD
int SkPerspIter::next()
{
=======
int SkPerspIter::next() {
>>>>>>> miniblink49
    int n = fCount;

    if (0 == n) {
        return 0;
    }
    SkPoint pt;
    SkFixed x = fX;
    SkFixed y = fY;
    SkFixed dx, dy;

    if (n >= kCount) {
        n = kCount;
        fSX += SkIntToScalar(kCount);
        SkMatrix::Persp_xy(fMatrix, fSX, fSY, &pt);
        fX = SkScalarToFixed(pt.fX);
        fY = SkScalarToFixed(pt.fY);
        dx = (fX - x) >> kShift;
        dy = (fY - y) >> kShift;
    } else {
        fSX += SkIntToScalar(n);
        SkMatrix::Persp_xy(fMatrix, fSX, fSY, &pt);
        fX = SkScalarToFixed(pt.fX);
        fY = SkScalarToFixed(pt.fY);
        dx = (fX - x) / n;
        dy = (fY - y) / n;
    }

    SkFixed* p = fStorage;
    for (int i = 0; i < n; i++) {
<<<<<<< HEAD
        *p++ = x;
        x += dx;
        *p++ = y;
        y += dy;
=======
        *p++ = x; x += dx;
        *p++ = y; y += dy;
>>>>>>> miniblink49
    }

    fCount -= n;
    return n;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static inline bool checkForZero(float x)
{
    return x * x == 0;
}

static inline bool poly_to_point(SkPoint* pt, const SkPoint poly[], int count)
{
    float x = 1, y = 1;
=======
static inline bool checkForZero(float x) {
    return x*x == 0;
}

static inline bool poly_to_point(SkPoint* pt, const SkPoint poly[], int count) {
    float   x = 1, y = 1;
>>>>>>> miniblink49
    SkPoint pt1, pt2;

    if (count > 1) {
        pt1.fX = poly[1].fX - poly[0].fX;
        pt1.fY = poly[1].fY - poly[0].fY;
        y = SkPoint::Length(pt1.fX, pt1.fY);
        if (checkForZero(y)) {
            return false;
        }
        switch (count) {
<<<<<<< HEAD
        case 2:
            break;
        case 3:
            pt2.fX = poly[0].fY - poly[2].fY;
            pt2.fY = poly[2].fX - poly[0].fX;
            goto CALC_X;
        default:
            pt2.fX = poly[0].fY - poly[3].fY;
            pt2.fY = poly[3].fX - poly[0].fX;
        CALC_X:
            x = sdot(pt1.fX, pt2.fX, pt1.fY, pt2.fY) / y;
            break;
=======
            case 2:
                break;
            case 3:
                pt2.fX = poly[0].fY - poly[2].fY;
                pt2.fY = poly[2].fX - poly[0].fX;
                goto CALC_X;
            default:
                pt2.fX = poly[0].fY - poly[3].fY;
                pt2.fY = poly[3].fX - poly[0].fX;
            CALC_X:
                x = sdot(pt1.fX, pt2.fX, pt1.fY, pt2.fY) / y;
                break;
>>>>>>> miniblink49
        }
    }
    pt->set(x, y);
    return true;
}

bool SkMatrix::Poly2Proc(const SkPoint srcPt[], SkMatrix* dst,
<<<<<<< HEAD
    const SkPoint& scale)
{
=======
                         const SkPoint& scale) {
>>>>>>> miniblink49
    float invScale = 1 / scale.fY;

    dst->fMat[kMScaleX] = (srcPt[1].fY - srcPt[0].fY) * invScale;
    dst->fMat[kMSkewY] = (srcPt[0].fX - srcPt[1].fX) * invScale;
    dst->fMat[kMPersp0] = 0;
    dst->fMat[kMSkewX] = (srcPt[1].fX - srcPt[0].fX) * invScale;
    dst->fMat[kMScaleY] = (srcPt[1].fY - srcPt[0].fY) * invScale;
    dst->fMat[kMPersp1] = 0;
    dst->fMat[kMTransX] = srcPt[0].fX;
    dst->fMat[kMTransY] = srcPt[0].fY;
    dst->fMat[kMPersp2] = 1;
    dst->setTypeMask(kUnknown_Mask);
    return true;
}

bool SkMatrix::Poly3Proc(const SkPoint srcPt[], SkMatrix* dst,
<<<<<<< HEAD
    const SkPoint& scale)
{
=======
                         const SkPoint& scale) {
>>>>>>> miniblink49
    float invScale = 1 / scale.fX;
    dst->fMat[kMScaleX] = (srcPt[2].fX - srcPt[0].fX) * invScale;
    dst->fMat[kMSkewY] = (srcPt[2].fY - srcPt[0].fY) * invScale;
    dst->fMat[kMPersp0] = 0;

    invScale = 1 / scale.fY;
    dst->fMat[kMSkewX] = (srcPt[1].fX - srcPt[0].fX) * invScale;
    dst->fMat[kMScaleY] = (srcPt[1].fY - srcPt[0].fY) * invScale;
    dst->fMat[kMPersp1] = 0;

    dst->fMat[kMTransX] = srcPt[0].fX;
    dst->fMat[kMTransY] = srcPt[0].fY;
    dst->fMat[kMPersp2] = 1;
    dst->setTypeMask(kUnknown_Mask);
    return true;
}

bool SkMatrix::Poly4Proc(const SkPoint srcPt[], SkMatrix* dst,
<<<<<<< HEAD
    const SkPoint& scale)
{
    float a1, a2;
    float x0, y0, x1, y1, x2, y2;
=======
                         const SkPoint& scale) {
    float   a1, a2;
    float   x0, y0, x1, y1, x2, y2;
>>>>>>> miniblink49

    x0 = srcPt[2].fX - srcPt[0].fX;
    y0 = srcPt[2].fY - srcPt[0].fY;
    x1 = srcPt[2].fX - srcPt[1].fX;
    y1 = srcPt[2].fY - srcPt[1].fY;
    x2 = srcPt[2].fX - srcPt[3].fX;
    y2 = srcPt[2].fY - srcPt[3].fY;

    /* check if abs(x2) > abs(y2) */
<<<<<<< HEAD
    if (x2 > 0 ? y2 > 0 ? x2 > y2 : x2 > -y2 : y2 > 0 ? -x2 > y2 : x2 < y2) {
=======
    if ( x2 > 0 ? y2 > 0 ? x2 > y2 : x2 > -y2 : y2 > 0 ? -x2 > y2 : x2 < y2) {
>>>>>>> miniblink49
        float denom = SkScalarMulDiv(x1, y2, x2) - y1;
        if (checkForZero(denom)) {
            return false;
        }
        a1 = (SkScalarMulDiv(x0 - x1, y2, x2) - y0 + y1) / denom;
    } else {
        float denom = x1 - SkScalarMulDiv(y1, x2, y2);
        if (checkForZero(denom)) {
            return false;
        }
        a1 = (x0 - x1 - SkScalarMulDiv(y0 - y1, x2, y2)) / denom;
    }

    /* check if abs(x1) > abs(y1) */
<<<<<<< HEAD
    if (x1 > 0 ? y1 > 0 ? x1 > y1 : x1 > -y1 : y1 > 0 ? -x1 > y1 : x1 < y1) {
=======
    if ( x1 > 0 ? y1 > 0 ? x1 > y1 : x1 > -y1 : y1 > 0 ? -x1 > y1 : x1 < y1) {
>>>>>>> miniblink49
        float denom = y2 - SkScalarMulDiv(x2, y1, x1);
        if (checkForZero(denom)) {
            return false;
        }
        a2 = (y0 - y2 - SkScalarMulDiv(x0 - x2, y1, x1)) / denom;
    } else {
        float denom = SkScalarMulDiv(y2, x1, y1) - x2;
        if (checkForZero(denom)) {
            return false;
        }
        a2 = (SkScalarMulDiv(y0 - y2, x1, y1) - x0 + x2) / denom;
    }

    float invScale = SkScalarInvert(scale.fX);
    dst->fMat[kMScaleX] = (a2 * srcPt[3].fX + srcPt[3].fX - srcPt[0].fX) * invScale;
<<<<<<< HEAD
    dst->fMat[kMSkewY] = (a2 * srcPt[3].fY + srcPt[3].fY - srcPt[0].fY) * invScale;
    dst->fMat[kMPersp0] = a2 * invScale;

    invScale = SkScalarInvert(scale.fY);
    dst->fMat[kMSkewX] = (a1 * srcPt[1].fX + srcPt[1].fX - srcPt[0].fX) * invScale;
=======
    dst->fMat[kMSkewY]  = (a2 * srcPt[3].fY + srcPt[3].fY - srcPt[0].fY) * invScale;
    dst->fMat[kMPersp0] = a2 * invScale;

    invScale = SkScalarInvert(scale.fY);
    dst->fMat[kMSkewX]  = (a1 * srcPt[1].fX + srcPt[1].fX - srcPt[0].fX) * invScale;
>>>>>>> miniblink49
    dst->fMat[kMScaleY] = (a1 * srcPt[1].fY + srcPt[1].fY - srcPt[0].fY) * invScale;
    dst->fMat[kMPersp1] = a1 * invScale;

    dst->fMat[kMTransX] = srcPt[0].fX;
    dst->fMat[kMTransY] = srcPt[0].fY;
    dst->fMat[kMPersp2] = 1;
    dst->setTypeMask(kUnknown_Mask);
    return true;
}

typedef bool (*PolyMapProc)(const SkPoint[], SkMatrix*, const SkPoint&);

/*  Taken from Rob Johnson's original sample code in QuickDraw GX
*/
bool SkMatrix::setPolyToPoly(const SkPoint src[], const SkPoint dst[],
<<<<<<< HEAD
    int count)
{
=======
                             int count) {
>>>>>>> miniblink49
    if ((unsigned)count > 4) {
        SkDebugf("--- SkMatrix::setPolyToPoly count out of range %d\n", count);
        return false;
    }

    if (0 == count) {
        this->reset();
        return true;
    }
    if (1 == count) {
        this->setTranslate(dst[0].fX - src[0].fX, dst[0].fY - src[0].fY);
        return true;
    }

    SkPoint scale;
<<<<<<< HEAD
    if (!poly_to_point(&scale, src, count) || SkScalarNearlyZero(scale.fX) || SkScalarNearlyZero(scale.fY)) {
=======
    if (!poly_to_point(&scale, src, count) ||
            SkScalarNearlyZero(scale.fX) ||
            SkScalarNearlyZero(scale.fY)) {
>>>>>>> miniblink49
        return false;
    }

    static const PolyMapProc gPolyMapProcs[] = {
        SkMatrix::Poly2Proc, SkMatrix::Poly3Proc, SkMatrix::Poly4Proc
    };
    PolyMapProc proc = gPolyMapProcs[count - 2];

    SkMatrix tempMap, result;
    tempMap.setTypeMask(kUnknown_Mask);

    if (!proc(src, &tempMap, scale)) {
        return false;
    }
    if (!tempMap.invert(&result)) {
        return false;
    }
    if (!proc(dst, &tempMap, scale)) {
        return false;
    }
    this->setConcat(tempMap, result);
    return true;
}

///////////////////////////////////////////////////////////////////////////////

enum MinMaxOrBoth {
    kMin_MinMaxOrBoth,
    kMax_MinMaxOrBoth,
    kBoth_MinMaxOrBoth
};

<<<<<<< HEAD
template <MinMaxOrBoth MIN_MAX_OR_BOTH>
bool get_scale_factor(SkMatrix::TypeMask typeMask,
    const SkScalar m[9],
    SkScalar results[/*1 or 2*/])
{
=======
template <MinMaxOrBoth MIN_MAX_OR_BOTH> bool get_scale_factor(SkMatrix::TypeMask typeMask,
                                                              const SkScalar m[9],
                                                              SkScalar results[/*1 or 2*/]) {
>>>>>>> miniblink49
    if (typeMask & SkMatrix::kPerspective_Mask) {
        return false;
    }
    if (SkMatrix::kIdentity_Mask == typeMask) {
        results[0] = SK_Scalar1;
        if (kBoth_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
            results[1] = SK_Scalar1;
        }
        return true;
    }
    if (!(typeMask & SkMatrix::kAffine_Mask)) {
        if (kMin_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
<<<<<<< HEAD
            results[0] = SkMinScalar(SkScalarAbs(m[SkMatrix::kMScaleX]),
                SkScalarAbs(m[SkMatrix::kMScaleY]));
        } else if (kMax_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
            results[0] = SkMaxScalar(SkScalarAbs(m[SkMatrix::kMScaleX]),
                SkScalarAbs(m[SkMatrix::kMScaleY]));
        } else {
            results[0] = SkScalarAbs(m[SkMatrix::kMScaleX]);
            results[1] = SkScalarAbs(m[SkMatrix::kMScaleY]);
            if (results[0] > results[1]) {
                SkTSwap(results[0], results[1]);
            }
=======
             results[0] = SkMinScalar(SkScalarAbs(m[SkMatrix::kMScaleX]),
                                      SkScalarAbs(m[SkMatrix::kMScaleY]));
        } else if (kMax_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
             results[0] = SkMaxScalar(SkScalarAbs(m[SkMatrix::kMScaleX]),
                                      SkScalarAbs(m[SkMatrix::kMScaleY]));
        } else {
            results[0] = SkScalarAbs(m[SkMatrix::kMScaleX]);
            results[1] = SkScalarAbs(m[SkMatrix::kMScaleY]);
             if (results[0] > results[1]) {
                 SkTSwap(results[0], results[1]);
             }
>>>>>>> miniblink49
        }
        return true;
    }
    // ignore the translation part of the matrix, just look at 2x2 portion.
    // compute singular values, take largest or smallest abs value.
    // [a b; b c] = A^T*A
    SkScalar a = sdot(m[SkMatrix::kMScaleX], m[SkMatrix::kMScaleX],
<<<<<<< HEAD
        m[SkMatrix::kMSkewY], m[SkMatrix::kMSkewY]);
    SkScalar b = sdot(m[SkMatrix::kMScaleX], m[SkMatrix::kMSkewX],
        m[SkMatrix::kMScaleY], m[SkMatrix::kMSkewY]);
    SkScalar c = sdot(m[SkMatrix::kMSkewX], m[SkMatrix::kMSkewX],
        m[SkMatrix::kMScaleY], m[SkMatrix::kMScaleY]);
=======
                      m[SkMatrix::kMSkewY],  m[SkMatrix::kMSkewY]);
    SkScalar b = sdot(m[SkMatrix::kMScaleX], m[SkMatrix::kMSkewX],
                      m[SkMatrix::kMScaleY], m[SkMatrix::kMSkewY]);
    SkScalar c = sdot(m[SkMatrix::kMSkewX],  m[SkMatrix::kMSkewX],
                      m[SkMatrix::kMScaleY], m[SkMatrix::kMScaleY]);
>>>>>>> miniblink49
    // eigenvalues of A^T*A are the squared singular values of A.
    // characteristic equation is det((A^T*A) - l*I) = 0
    // l^2 - (a + c)l + (ac-b^2)
    // solve using quadratic equation (divisor is non-zero since l^2 has 1 coeff
    // and roots are guaranteed to be pos and real).
    SkScalar bSqd = b * b;
    // if upper left 2x2 is orthogonal save some math
<<<<<<< HEAD
    if (bSqd <= SK_ScalarNearlyZero * SK_ScalarNearlyZero) {
=======
    if (bSqd <= SK_ScalarNearlyZero*SK_ScalarNearlyZero) {
>>>>>>> miniblink49
        if (kMin_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
            results[0] = SkMinScalar(a, c);
        } else if (kMax_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
            results[0] = SkMaxScalar(a, c);
        } else {
            results[0] = a;
            results[1] = c;
            if (results[0] > results[1]) {
                SkTSwap(results[0], results[1]);
            }
        }
    } else {
        SkScalar aminusc = a - c;
        SkScalar apluscdiv2 = SkScalarHalf(a + c);
        SkScalar x = SkScalarHalf(SkScalarSqrt(aminusc * aminusc + 4 * bSqd));
        if (kMin_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
            results[0] = apluscdiv2 - x;
        } else if (kMax_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
            results[0] = apluscdiv2 + x;
        } else {
            results[0] = apluscdiv2 - x;
            results[1] = apluscdiv2 + x;
        }
    }
<<<<<<< HEAD
    if (SkScalarIsNaN(results[0])) {
        return false;
    }
    SkASSERT(results[0] >= 0);
    results[0] = SkScalarSqrt(results[0]);
    if (kBoth_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
        if (SkScalarIsNaN(results[1])) {
            return false;
        }
=======
    SkASSERT(results[0] >= 0);
    results[0] = SkScalarSqrt(results[0]);
    if (kBoth_MinMaxOrBoth == MIN_MAX_OR_BOTH) {
>>>>>>> miniblink49
        SkASSERT(results[1] >= 0);
        results[1] = SkScalarSqrt(results[1]);
    }
    return true;
}

<<<<<<< HEAD
SkScalar SkMatrix::getMinScale() const
{
=======
SkScalar SkMatrix::getMinScale() const {
>>>>>>> miniblink49
    SkScalar factor;
    if (get_scale_factor<kMin_MinMaxOrBoth>(this->getType(), fMat, &factor)) {
        return factor;
    } else {
        return -1;
    }
}

<<<<<<< HEAD
SkScalar SkMatrix::getMaxScale() const
{
=======
SkScalar SkMatrix::getMaxScale() const {
>>>>>>> miniblink49
    SkScalar factor;
    if (get_scale_factor<kMax_MinMaxOrBoth>(this->getType(), fMat, &factor)) {
        return factor;
    } else {
        return -1;
    }
}

<<<<<<< HEAD
bool SkMatrix::getMinMaxScales(SkScalar scaleFactors[2]) const
{
=======
bool SkMatrix::getMinMaxScales(SkScalar scaleFactors[2]) const {
>>>>>>> miniblink49
    return get_scale_factor<kBoth_MinMaxOrBoth>(this->getType(), fMat, scaleFactors);
}

namespace {

<<<<<<< HEAD
// SkMatrix is C++11 POD (trivial and standard-layout), but not aggregate (it has private fields).
struct AggregateMatrix {
=======
struct PODMatrix {
>>>>>>> miniblink49
    SkScalar matrix[9];
    uint32_t typemask;

    const SkMatrix& asSkMatrix() const { return *reinterpret_cast<const SkMatrix*>(this); }
};
<<<<<<< HEAD
static_assert(sizeof(AggregateMatrix) == sizeof(SkMatrix), "AggregateMatrix size mismatch.");

} // namespace

const SkMatrix& SkMatrix::I()
{
    static_assert(offsetof(SkMatrix, fMat) == offsetof(AggregateMatrix, matrix), "fMat");
    static_assert(offsetof(SkMatrix, fTypeMask) == offsetof(AggregateMatrix, typemask), "fTypeMask");

    static const AggregateMatrix identity = { { SK_Scalar1, 0, 0,
                                                  0, SK_Scalar1, 0,
                                                  0, 0, SK_Scalar1 },
        kIdentity_Mask | kRectStaysRect_Mask };
=======
SK_COMPILE_ASSERT(sizeof(PODMatrix) == sizeof(SkMatrix), PODMatrixSizeMismatch);

}  // namespace

const SkMatrix& SkMatrix::I() {
    SK_COMPILE_ASSERT(offsetof(SkMatrix, fMat)      == offsetof(PODMatrix, matrix),   BadfMat);
    SK_COMPILE_ASSERT(offsetof(SkMatrix, fTypeMask) == offsetof(PODMatrix, typemask), BadfTypeMask);

    static const PODMatrix identity = { {SK_Scalar1, 0, 0,
                                         0, SK_Scalar1, 0,
                                         0, 0, SK_Scalar1 },
                                       kIdentity_Mask | kRectStaysRect_Mask};
>>>>>>> miniblink49
    SkASSERT(identity.asSkMatrix().isIdentity());
    return identity.asSkMatrix();
}

<<<<<<< HEAD
const SkMatrix& SkMatrix::InvalidMatrix()
{
    static_assert(offsetof(SkMatrix, fMat) == offsetof(AggregateMatrix, matrix), "fMat");
    static_assert(offsetof(SkMatrix, fTypeMask) == offsetof(AggregateMatrix, typemask), "fTypeMask");

    static const AggregateMatrix invalid = { { SK_ScalarMax, SK_ScalarMax, SK_ScalarMax,
                                                 SK_ScalarMax, SK_ScalarMax, SK_ScalarMax,
                                                 SK_ScalarMax, SK_ScalarMax, SK_ScalarMax },
        kTranslate_Mask | kScale_Mask | kAffine_Mask | kPerspective_Mask };
    return invalid.asSkMatrix();
}

bool SkMatrix::decomposeScale(SkSize* scale, SkMatrix* remaining) const
{
=======
const SkMatrix& SkMatrix::InvalidMatrix() {
    SK_COMPILE_ASSERT(offsetof(SkMatrix, fMat)      == offsetof(PODMatrix, matrix),   BadfMat);
    SK_COMPILE_ASSERT(offsetof(SkMatrix, fTypeMask) == offsetof(PODMatrix, typemask), BadfTypeMask);

    static const PODMatrix invalid =
        { {SK_ScalarMax, SK_ScalarMax, SK_ScalarMax,
           SK_ScalarMax, SK_ScalarMax, SK_ScalarMax,
           SK_ScalarMax, SK_ScalarMax, SK_ScalarMax },
         kTranslate_Mask | kScale_Mask | kAffine_Mask | kPerspective_Mask };
    return invalid.asSkMatrix();
}

bool SkMatrix::decomposeScale(SkSize* scale, SkMatrix* remaining) const {
>>>>>>> miniblink49
    if (this->hasPerspective()) {
        return false;
    }

    const SkScalar sx = SkVector::Length(this->getScaleX(), this->getSkewY());
    const SkScalar sy = SkVector::Length(this->getSkewX(), this->getScaleY());
<<<<<<< HEAD
    if (!SkScalarIsFinite(sx) || !SkScalarIsFinite(sy) || SkScalarNearlyZero(sx) || SkScalarNearlyZero(sy)) {
=======
    if (!SkScalarIsFinite(sx) || !SkScalarIsFinite(sy) ||
        SkScalarNearlyZero(sx) || SkScalarNearlyZero(sy)) {
>>>>>>> miniblink49
        return false;
    }

    if (scale) {
        scale->set(sx, sy);
    }
    if (remaining) {
        *remaining = *this;
        remaining->postScale(SkScalarInvert(sx), SkScalarInvert(sy));
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
size_t SkMatrix::writeToMemory(void* buffer) const
{
=======
size_t SkMatrix::writeToMemory(void* buffer) const {
>>>>>>> miniblink49
    // TODO write less for simple matrices
    static const size_t sizeInMemory = 9 * sizeof(SkScalar);
    if (buffer) {
        memcpy(buffer, fMat, sizeInMemory);
    }
    return sizeInMemory;
}

<<<<<<< HEAD
size_t SkMatrix::readFromMemory(const void* buffer, size_t length)
{
=======
size_t SkMatrix::readFromMemory(const void* buffer, size_t length) {
>>>>>>> miniblink49
    static const size_t sizeInMemory = 9 * sizeof(SkScalar);
    if (length < sizeInMemory) {
        return 0;
    }
    if (buffer) {
        memcpy(fMat, buffer, sizeInMemory);
        this->setTypeMask(kUnknown_Mask);
    }
    return sizeInMemory;
}

<<<<<<< HEAD
void SkMatrix::dump() const
{
=======
void SkMatrix::dump() const {
>>>>>>> miniblink49
    SkString str;
    this->toString(&str);
    SkDebugf("%s\n", str.c_str());
}

<<<<<<< HEAD
void SkMatrix::toString(SkString* str) const
{
    str->appendf("[%8.4f %8.4f %8.4f][%8.4f %8.4f %8.4f][%8.4f %8.4f %8.4f]",
        fMat[0], fMat[1], fMat[2], fMat[3], fMat[4], fMat[5],
        fMat[6], fMat[7], fMat[8]);
=======
void SkMatrix::toString(SkString* str) const {
    str->appendf("[%8.4f %8.4f %8.4f][%8.4f %8.4f %8.4f][%8.4f %8.4f %8.4f]",
             fMat[0], fMat[1], fMat[2], fMat[3], fMat[4], fMat[5],
             fMat[6], fMat[7], fMat[8]);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

#include "SkMatrixUtils.h"

<<<<<<< HEAD
bool SkTreatAsSprite(const SkMatrix& mat, const SkISize& size, const SkPaint& paint)
{
    // Our path aa is 2-bits, and our rect aa is 8, so we could use 8,
    // but in practice 4 seems enough (still looks smooth) and allows
    // more slightly fractional cases to fall into the fast (sprite) case.
    static const unsigned kAntiAliasSubpixelBits = 4;

    const unsigned subpixelBits = paint.isAntiAlias() ? kAntiAliasSubpixelBits : 0;

=======
bool SkTreatAsSprite(const SkMatrix& mat, int width, int height,
                     unsigned subpixelBits) {
>>>>>>> miniblink49
    // quick reject on affine or perspective
    if (mat.getType() & ~(SkMatrix::kScale_Mask | SkMatrix::kTranslate_Mask)) {
        return false;
    }

    // quick success check
    if (!subpixelBits && !(mat.getType() & ~SkMatrix::kTranslate_Mask)) {
        return true;
    }

    // mapRect supports negative scales, so we eliminate those first
    if (mat.getScaleX() < 0 || mat.getScaleY() < 0) {
        return false;
    }

    SkRect dst;
<<<<<<< HEAD
    SkIRect isrc = SkIRect::MakeSize(size);
=======
    SkIRect isrc = { 0, 0, width, height };
>>>>>>> miniblink49

    {
        SkRect src;
        src.set(isrc);
        mat.mapRect(&dst, src);
    }

    // just apply the translate to isrc
    isrc.offset(SkScalarRoundToInt(mat.getTranslateX()),
<<<<<<< HEAD
        SkScalarRoundToInt(mat.getTranslateY()));

    if (subpixelBits) {
        isrc.fLeft = SkLeftShift(isrc.fLeft, subpixelBits);
        isrc.fTop = SkLeftShift(isrc.fTop, subpixelBits);
        isrc.fRight = SkLeftShift(isrc.fRight, subpixelBits);
        isrc.fBottom = SkLeftShift(isrc.fBottom, subpixelBits);
=======
                SkScalarRoundToInt(mat.getTranslateY()));

    if (subpixelBits) {
        isrc.fLeft <<= subpixelBits;
        isrc.fTop <<= subpixelBits;
        isrc.fRight <<= subpixelBits;
        isrc.fBottom <<= subpixelBits;
>>>>>>> miniblink49

        const float scale = 1 << subpixelBits;
        dst.fLeft *= scale;
        dst.fTop *= scale;
        dst.fRight *= scale;
        dst.fBottom *= scale;
    }

    SkIRect idst;
    dst.round(&idst);
    return isrc == idst;
}

// A square matrix M can be decomposed (via polar decomposition) into two matrices --
// an orthogonal matrix Q and a symmetric matrix S. In turn we can decompose S into U*W*U^T,
// where U is another orthogonal matrix and W is a scale matrix. These can be recombined
// to give M = (Q*U)*W*U^T, i.e., the product of two orthogonal matrices and a scale matrix.
//
// The one wrinkle is that traditionally Q may contain a reflection -- the
// calculation has been rejiggered to put that reflection into W.
bool SkDecomposeUpper2x2(const SkMatrix& matrix,
<<<<<<< HEAD
    SkPoint* rotation1,
    SkPoint* scale,
    SkPoint* rotation2)
{
=======
                         SkPoint* rotation1,
                         SkPoint* scale,
                         SkPoint* rotation2) {
>>>>>>> miniblink49

    SkScalar A = matrix[SkMatrix::kMScaleX];
    SkScalar B = matrix[SkMatrix::kMSkewX];
    SkScalar C = matrix[SkMatrix::kMSkewY];
    SkScalar D = matrix[SkMatrix::kMScaleY];

    if (is_degenerate_2x2(A, B, C, D)) {
        return false;
    }

    double w1, w2;
    SkScalar cos1, sin1;
    SkScalar cos2, sin2;

    // do polar decomposition (M = Q*S)
    SkScalar cosQ, sinQ;
    double Sa, Sb, Sd;
    // if M is already symmetric (i.e., M = I*S)
    if (SkScalarNearlyEqual(B, C)) {
        cosQ = 1;
        sinQ = 0;

        Sa = A;
        Sb = B;
        Sd = D;
    } else {
        cosQ = A + D;
        sinQ = C - B;
<<<<<<< HEAD
        SkScalar reciplen = SkScalarInvert(SkScalarSqrt(cosQ * cosQ + sinQ * sinQ));
=======
        SkScalar reciplen = SkScalarInvert(SkScalarSqrt(cosQ*cosQ + sinQ*sinQ));
>>>>>>> miniblink49
        cosQ *= reciplen;
        sinQ *= reciplen;

        // S = Q^-1*M
        // we don't calc Sc since it's symmetric
<<<<<<< HEAD
        Sa = A * cosQ + C * sinQ;
        Sb = B * cosQ + D * sinQ;
        Sd = -B * sinQ + D * cosQ;
=======
        Sa = A*cosQ + C*sinQ;
        Sb = B*cosQ + D*sinQ;
        Sd = -B*sinQ + D*cosQ;
>>>>>>> miniblink49
    }

    // Now we need to compute eigenvalues of S (our scale factors)
    // and eigenvectors (bases for our rotation)
    // From this, should be able to reconstruct S as U*W*U^T
    if (SkScalarNearlyZero(SkDoubleToScalar(Sb))) {
        // already diagonalized
        cos1 = 1;
        sin1 = 0;
        w1 = Sa;
        w2 = Sd;
        cos2 = cosQ;
        sin2 = sinQ;
    } else {
        double diff = Sa - Sd;
<<<<<<< HEAD
        double discriminant = sqrt(diff * diff + 4.0 * Sb * Sb);
        double trace = Sa + Sd;
        if (diff > 0) {
            w1 = 0.5 * (trace + discriminant);
            w2 = 0.5 * (trace - discriminant);
        } else {
            w1 = 0.5 * (trace - discriminant);
            w2 = 0.5 * (trace + discriminant);
        }

        cos1 = SkDoubleToScalar(Sb);
        sin1 = SkDoubleToScalar(w1 - Sa);
        SkScalar reciplen = SkScalarInvert(SkScalarSqrt(cos1 * cos1 + sin1 * sin1));
=======
        double discriminant = sqrt(diff*diff + 4.0*Sb*Sb);
        double trace = Sa + Sd;
        if (diff > 0) {
            w1 = 0.5*(trace + discriminant);
            w2 = 0.5*(trace - discriminant);
        } else {
            w1 = 0.5*(trace - discriminant);
            w2 = 0.5*(trace + discriminant);
        }

        cos1 = SkDoubleToScalar(Sb); sin1 = SkDoubleToScalar(w1 - Sa);
        SkScalar reciplen = SkScalarInvert(SkScalarSqrt(cos1*cos1 + sin1*sin1));
>>>>>>> miniblink49
        cos1 *= reciplen;
        sin1 *= reciplen;

        // rotation 2 is composition of Q and U
<<<<<<< HEAD
        cos2 = cos1 * cosQ - sin1 * sinQ;
        sin2 = sin1 * cosQ + cos1 * sinQ;
=======
        cos2 = cos1*cosQ - sin1*sinQ;
        sin2 = sin1*cosQ + cos1*sinQ;
>>>>>>> miniblink49

        // rotation 1 is U^T
        sin1 = -sin1;
    }

    if (scale) {
        scale->fX = SkDoubleToScalar(w1);
        scale->fY = SkDoubleToScalar(w2);
    }
    if (rotation1) {
        rotation1->fX = cos1;
        rotation1->fY = sin1;
    }
    if (rotation2) {
        rotation2->fX = cos2;
        rotation2->fY = sin2;
    }

    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkRSXform::toQuad(SkScalar width, SkScalar height, SkPoint quad[4]) const
{
=======
void SkRSXform::toQuad(SkScalar width, SkScalar height, SkPoint quad[4]) const {
>>>>>>> miniblink49
#if 0
    // This is the slow way, but it documents what we're doing
    quad[0].set(0, 0);
    quad[1].set(width, 0);
    quad[2].set(width, height);
    quad[3].set(0, height);
    SkMatrix m;
    m.setRSXform(*this).mapPoints(quad, quad, 4);
#else
    const SkScalar m00 = fSCos;
    const SkScalar m01 = -fSSin;
    const SkScalar m02 = fTx;
    const SkScalar m10 = -m01;
    const SkScalar m11 = m00;
    const SkScalar m12 = fTy;

    quad[0].set(m02, m12);
    quad[1].set(m00 * width + m02, m10 * width + m12);
    quad[2].set(m00 * width + m01 * height + m02, m10 * width + m11 * height + m12);
    quad[3].set(m01 * height + m02, m11 * height + m12);
#endif
}
<<<<<<< HEAD
=======

>>>>>>> miniblink49
