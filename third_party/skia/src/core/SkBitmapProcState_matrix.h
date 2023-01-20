<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMath.h"
#include "SkMathPriv.h"

<<<<<<< HEAD
#define SCALE_FILTER_NAME MAKENAME(_filter_scale)
#define AFFINE_FILTER_NAME MAKENAME(_filter_affine)
#define PERSP_FILTER_NAME MAKENAME(_filter_persp)

#define PACK_FILTER_X_NAME MAKENAME(_pack_filter_x)
#define PACK_FILTER_Y_NAME MAKENAME(_pack_filter_y)

#ifndef PREAMBLE
#define PREAMBLE(state)
#define PREAMBLE_PARAM_X
#define PREAMBLE_PARAM_Y
#define PREAMBLE_ARG_X
#define PREAMBLE_ARG_Y
=======
#define SCALE_FILTER_NAME       MAKENAME(_filter_scale)
#define AFFINE_FILTER_NAME      MAKENAME(_filter_affine)
#define PERSP_FILTER_NAME       MAKENAME(_filter_persp)

#define PACK_FILTER_X_NAME  MAKENAME(_pack_filter_x)
#define PACK_FILTER_Y_NAME  MAKENAME(_pack_filter_y)

#ifndef PREAMBLE
    #define PREAMBLE(state)
    #define PREAMBLE_PARAM_X
    #define PREAMBLE_PARAM_Y
    #define PREAMBLE_ARG_X
    #define PREAMBLE_ARG_Y
>>>>>>> miniblink49
#endif

// declare functions externally to suppress warnings.
void SCALE_FILTER_NAME(const SkBitmapProcState& s,
<<<<<<< HEAD
    uint32_t xy[], int count, int x, int y);
void AFFINE_FILTER_NAME(const SkBitmapProcState& s,
    uint32_t xy[], int count, int x, int y);
void PERSP_FILTER_NAME(const SkBitmapProcState& s,
    uint32_t* SK_RESTRICT xy, int count,
    int x, int y);

static inline uint32_t PACK_FILTER_Y_NAME(SkFixed f, unsigned max,
    SkFixed one PREAMBLE_PARAM_Y)
{
=======
                              uint32_t xy[], int count, int x, int y);
void AFFINE_FILTER_NAME(const SkBitmapProcState& s,
                               uint32_t xy[], int count, int x, int y);
void PERSP_FILTER_NAME(const SkBitmapProcState& s,
                              uint32_t* SK_RESTRICT xy, int count,
                              int x, int y);

static inline uint32_t PACK_FILTER_Y_NAME(SkFixed f, unsigned max,
                                          SkFixed one PREAMBLE_PARAM_Y) {
>>>>>>> miniblink49
    unsigned i = TILEY_PROCF(f, max);
    i = (i << 4) | TILEY_LOW_BITS(f, max);
    return (i << 14) | (TILEY_PROCF((f + one), max));
}

static inline uint32_t PACK_FILTER_X_NAME(SkFixed f, unsigned max,
<<<<<<< HEAD
    SkFixed one PREAMBLE_PARAM_X)
{
=======
                                          SkFixed one PREAMBLE_PARAM_X) {
>>>>>>> miniblink49
    unsigned i = TILEX_PROCF(f, max);
    i = (i << 4) | TILEX_LOW_BITS(f, max);
    return (i << 14) | (TILEX_PROCF((f + one), max));
}

void SCALE_FILTER_NAME(const SkBitmapProcState& s,
<<<<<<< HEAD
    uint32_t xy[], int count, int x, int y)
{
    SkASSERT((s.fInvType & ~(SkMatrix::kTranslate_Mask | SkMatrix::kScale_Mask)) == 0);
=======
                              uint32_t xy[], int count, int x, int y) {
    SkASSERT((s.fInvType & ~(SkMatrix::kTranslate_Mask |
                             SkMatrix::kScale_Mask)) == 0);
>>>>>>> miniblink49
    SkASSERT(s.fInvKy == 0);

    PREAMBLE(s);

    const unsigned maxX = s.fPixmap.width() - 1;
    const SkFixed one = s.fFilterOneX;
    const SkFractionalInt dx = s.fInvSxFractionalInt;
    SkFractionalInt fx;

    {
<<<<<<< HEAD
        const SkBitmapProcStateAutoMapper mapper(s, x, y);
        const SkFixed fy = mapper.fixedY();
=======
        SkPoint pt;
        s.fInvProc(s.fInvMatrix, SkIntToScalar(x) + SK_ScalarHalf,
                                  SkIntToScalar(y) + SK_ScalarHalf, &pt);
        const SkFixed fy = SkScalarToFixed(pt.fY) - (s.fFilterOneY >> 1);
>>>>>>> miniblink49
        const unsigned maxY = s.fPixmap.height() - 1;
        // compute our two Y values up front
        *xy++ = PACK_FILTER_Y_NAME(fy, maxY, s.fFilterOneY PREAMBLE_ARG_Y);
        // now initialize fx
<<<<<<< HEAD
        fx = mapper.fractionalIntX();
=======
        fx = SkScalarToFractionalInt(pt.fX) - (SkFixedToFractionalInt(one) >> 1);
>>>>>>> miniblink49
    }

#ifdef CHECK_FOR_DECAL
    if (can_truncate_to_fixed_for_decal(fx, dx, count, maxX)) {
        decal_filter_scale(xy, SkFractionalIntToFixed(fx),
<<<<<<< HEAD
            SkFractionalIntToFixed(dx), count);
=======
                           SkFractionalIntToFixed(dx), count);
>>>>>>> miniblink49
    } else
#endif
    {
        do {
            SkFixed fixedFx = SkFractionalIntToFixed(fx);
            *xy++ = PACK_FILTER_X_NAME(fixedFx, maxX, one PREAMBLE_ARG_X);
            fx += dx;
        } while (--count != 0);
    }
}

void AFFINE_FILTER_NAME(const SkBitmapProcState& s,
<<<<<<< HEAD
    uint32_t xy[], int count, int x, int y)
{
    SkASSERT(s.fInvType & SkMatrix::kAffine_Mask);
    SkASSERT((s.fInvType & ~(SkMatrix::kTranslate_Mask | SkMatrix::kScale_Mask | SkMatrix::kAffine_Mask)) == 0);

    PREAMBLE(s);
    const SkBitmapProcStateAutoMapper mapper(s, x, y);

    SkFixed oneX = s.fFilterOneX;
    SkFixed oneY = s.fFilterOneY;
    SkFixed fx = mapper.fixedX();
    SkFixed fy = mapper.fixedY();
=======
                               uint32_t xy[], int count, int x, int y) {
    SkASSERT(s.fInvType & SkMatrix::kAffine_Mask);
    SkASSERT((s.fInvType & ~(SkMatrix::kTranslate_Mask |
                             SkMatrix::kScale_Mask |
                             SkMatrix::kAffine_Mask)) == 0);

    PREAMBLE(s);
    SkPoint srcPt;
    s.fInvProc(s.fInvMatrix,
               SkIntToScalar(x) + SK_ScalarHalf,
               SkIntToScalar(y) + SK_ScalarHalf, &srcPt);

    SkFixed oneX = s.fFilterOneX;
    SkFixed oneY = s.fFilterOneY;
    SkFixed fx = SkScalarToFixed(srcPt.fX) - (oneX >> 1);
    SkFixed fy = SkScalarToFixed(srcPt.fY) - (oneY >> 1);
>>>>>>> miniblink49
    SkFixed dx = s.fInvSx;
    SkFixed dy = s.fInvKy;
    unsigned maxX = s.fPixmap.width() - 1;
    unsigned maxY = s.fPixmap.height() - 1;

    do {
        *xy++ = PACK_FILTER_Y_NAME(fy, maxY, oneY PREAMBLE_ARG_Y);
        fy += dy;
        *xy++ = PACK_FILTER_X_NAME(fx, maxX, oneX PREAMBLE_ARG_X);
        fx += dx;
    } while (--count != 0);
}

void PERSP_FILTER_NAME(const SkBitmapProcState& s,
<<<<<<< HEAD
    uint32_t* SK_RESTRICT xy, int count,
    int x, int y)
{
=======
                              uint32_t* SK_RESTRICT xy, int count,
                              int x, int y) {
>>>>>>> miniblink49
    SkASSERT(s.fInvType & SkMatrix::kPerspective_Mask);

    PREAMBLE(s);
    unsigned maxX = s.fPixmap.width() - 1;
    unsigned maxY = s.fPixmap.height() - 1;
    SkFixed oneX = s.fFilterOneX;
    SkFixed oneY = s.fFilterOneY;

<<<<<<< HEAD
    SkPerspIter iter(s.fInvMatrix,
        SkIntToScalar(x) + SK_ScalarHalf,
        SkIntToScalar(y) + SK_ScalarHalf, count);
=======
    SkPerspIter   iter(s.fInvMatrix,
                       SkIntToScalar(x) + SK_ScalarHalf,
                       SkIntToScalar(y) + SK_ScalarHalf, count);
>>>>>>> miniblink49

    while ((count = iter.next()) != 0) {
        const SkFixed* SK_RESTRICT srcXY = iter.getXY();
        do {
            *xy++ = PACK_FILTER_Y_NAME(srcXY[1] - (oneY >> 1), maxY,
<<<<<<< HEAD
                oneY PREAMBLE_ARG_Y);
            *xy++ = PACK_FILTER_X_NAME(srcXY[0] - (oneX >> 1), maxX,
                oneX PREAMBLE_ARG_X);
=======
                                       oneY PREAMBLE_ARG_Y);
            *xy++ = PACK_FILTER_X_NAME(srcXY[0] - (oneX >> 1), maxX,
                                       oneX PREAMBLE_ARG_X);
>>>>>>> miniblink49
            srcXY += 2;
        } while (--count != 0);
    }
}

#undef MAKENAME
#undef TILEX_PROCF
#undef TILEY_PROCF
#ifdef CHECK_FOR_DECAL
<<<<<<< HEAD
#undef CHECK_FOR_DECAL
=======
    #undef CHECK_FOR_DECAL
>>>>>>> miniblink49
#endif

#undef SCALE_FILTER_NAME
#undef AFFINE_FILTER_NAME
#undef PERSP_FILTER_NAME

#undef PREAMBLE
#undef PREAMBLE_PARAM_X
#undef PREAMBLE_PARAM_Y
#undef PREAMBLE_ARG_X
#undef PREAMBLE_ARG_Y

#undef TILEX_LOW_BITS
#undef TILEY_LOW_BITS
