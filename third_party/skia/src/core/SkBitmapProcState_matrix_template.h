/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkBitmapProcState_MatrixTemplates_DEFINED
#define SkBitmapProcState_MatrixTemplates_DEFINED

#include "SkMath.h"
#include "SkMathPriv.h"

template <typename TileProc, bool tryDecal>
void NoFilterProc_Scale(const SkBitmapProcState& s, uint32_t xy[],
<<<<<<< HEAD
    int count, int x, int y)
{
    SkASSERT((s.fInvType & ~(SkMatrix::kTranslate_Mask | SkMatrix::kScale_Mask)) == 0);
=======
                        int count, int x, int y) {
    SkASSERT((s.fInvType & ~(SkMatrix::kTranslate_Mask |
                             SkMatrix::kScale_Mask)) == 0);
>>>>>>> miniblink49

    // we store y, x, x, x, x, x

    const unsigned maxX = s.fPixmap.width() - 1;
    SkFractionalInt fx;
    {
<<<<<<< HEAD
        const SkBitmapProcStateAutoMapper mapper(s, x, y);
        const unsigned maxY = s.fPixmap.height() - 1;
        *xy++ = TileProc::Y(s, mapper.fixedY(), maxY);
        fx = mapper.fractionalIntX();
=======
        SkPoint pt;
        s.fInvProc(s.fInvMatrix, SkIntToScalar(x) + SK_ScalarHalf,
                                  SkIntToScalar(y) + SK_ScalarHalf, &pt);
        fx = SkScalarToFractionalInt(pt.fY);
        const unsigned maxY = s.fPixmap.height() - 1;
        *xy++ = TileProc::Y(s, SkFractionalIntToFixed(fx), maxY);
        fx = SkScalarToFractionalInt(pt.fX);
>>>>>>> miniblink49
    }

    if (0 == maxX) {
        // all of the following X values must be 0
        memset(xy, 0, count * sizeof(uint16_t));
        return;
    }

    const SkFractionalInt dx = s.fInvSxFractionalInt;

    if (tryDecal && can_truncate_to_fixed_for_decal(fx, dx, count, maxX)) {
        decal_nofilter_scale(xy, SkFractionalIntToFixed(fx),
<<<<<<< HEAD
            SkFractionalIntToFixed(dx), count);
=======
                             SkFractionalIntToFixed(dx), count);
>>>>>>> miniblink49
    } else {
        int i;
        for (i = (count >> 2); i > 0; --i) {
            unsigned a, b;
<<<<<<< HEAD
            a = TileProc::X(s, SkFractionalIntToFixed(fx), maxX);
            fx += dx;
            b = TileProc::X(s, SkFractionalIntToFixed(fx), maxX);
            fx += dx;
=======
            a = TileProc::X(s, SkFractionalIntToFixed(fx), maxX); fx += dx;
            b = TileProc::X(s, SkFractionalIntToFixed(fx), maxX); fx += dx;
>>>>>>> miniblink49
#ifdef SK_CPU_BENDIAN
            *xy++ = (a << 16) | b;
#else
            *xy++ = (b << 16) | a;
#endif
<<<<<<< HEAD
            a = TileProc::X(s, SkFractionalIntToFixed(fx), maxX);
            fx += dx;
            b = TileProc::X(s, SkFractionalIntToFixed(fx), maxX);
            fx += dx;
=======
            a = TileProc::X(s, SkFractionalIntToFixed(fx), maxX); fx += dx;
            b = TileProc::X(s, SkFractionalIntToFixed(fx), maxX); fx += dx;
>>>>>>> miniblink49
#ifdef SK_CPU_BENDIAN
            *xy++ = (a << 16) | b;
#else
            *xy++ = (b << 16) | a;
#endif
        }
        uint16_t* xx = (uint16_t*)xy;
        for (i = (count & 3); i > 0; --i) {
<<<<<<< HEAD
            *xx++ = TileProc::X(s, SkFractionalIntToFixed(fx), maxX);
            fx += dx;
=======
            *xx++ = TileProc::X(s, SkFractionalIntToFixed(fx), maxX); fx += dx;
>>>>>>> miniblink49
        }
    }
}

// note: we could special-case on a matrix which is skewed in X but not Y.
// this would require a more general setup thatn SCALE does, but could use
// SCALE's inner loop that only looks at dx

template <typename TileProc>
void NoFilterProc_Affine(const SkBitmapProcState& s, uint32_t xy[],
<<<<<<< HEAD
    int count, int x, int y)
{
    SkASSERT(s.fInvType & SkMatrix::kAffine_Mask);
    SkASSERT((s.fInvType & ~(SkMatrix::kTranslate_Mask | SkMatrix::kScale_Mask | SkMatrix::kAffine_Mask)) == 0);

    const SkBitmapProcStateAutoMapper mapper(s, x, y);

    SkFractionalInt fx = mapper.fractionalIntX();
    SkFractionalInt fy = mapper.fractionalIntY();
=======
                         int count, int x, int y) {
    SkASSERT(s.fInvType & SkMatrix::kAffine_Mask);
    SkASSERT((s.fInvType & ~(SkMatrix::kTranslate_Mask |
                             SkMatrix::kScale_Mask |
                             SkMatrix::kAffine_Mask)) == 0);

    SkPoint srcPt;
    s.fInvProc(s.fInvMatrix,
               SkIntToScalar(x) + SK_ScalarHalf,
               SkIntToScalar(y) + SK_ScalarHalf, &srcPt);

    SkFractionalInt fx = SkScalarToFractionalInt(srcPt.fX);
    SkFractionalInt fy = SkScalarToFractionalInt(srcPt.fY);
>>>>>>> miniblink49
    SkFractionalInt dx = s.fInvSxFractionalInt;
    SkFractionalInt dy = s.fInvKyFractionalInt;
    int maxX = s.fPixmap.width() - 1;
    int maxY = s.fPixmap.height() - 1;

    for (int i = count; i > 0; --i) {
<<<<<<< HEAD
        *xy++ = (TileProc::Y(s, SkFractionalIntToFixed(fy), maxY) << 16) | TileProc::X(s, SkFractionalIntToFixed(fx), maxX);
        fx += dx;
        fy += dy;
=======
        *xy++ = (TileProc::Y(s, SkFractionalIntToFixed(fy), maxY) << 16) |
                 TileProc::X(s, SkFractionalIntToFixed(fx), maxX);
        fx += dx; fy += dy;
>>>>>>> miniblink49
    }
}

template <typename TileProc>
void NoFilterProc_Persp(const SkBitmapProcState& s, uint32_t* SK_RESTRICT xy,
<<<<<<< HEAD
    int count, int x, int y)
{
=======
                        int count, int x, int y) {
>>>>>>> miniblink49
    SkASSERT(s.fInvType & SkMatrix::kPerspective_Mask);

    int maxX = s.fPixmap.width() - 1;
    int maxY = s.fPixmap.height() - 1;

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
        while (--count >= 0) {
<<<<<<< HEAD
            *xy++ = (TileProc::Y(s, srcXY[1], maxY) << 16) | TileProc::X(s, srcXY[0], maxX);
=======
            *xy++ = (TileProc::Y(s, srcXY[1], maxY) << 16) |
                     TileProc::X(s, srcXY[0], maxX);
>>>>>>> miniblink49
            srcXY += 2;
        }
    }
}

#endif
