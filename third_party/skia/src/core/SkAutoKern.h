<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkAutoKern_DEFINED
#define SkAutoKern_DEFINED

#include "SkGlyph.h"

<<<<<<< HEAD
#define SkAutoKern_Adjust(prev, next) SkIntToScalar(((next) - (prev) + 32) >> 6)

/* this is a helper class to perform auto-kerning
 * the adjust() method returns a SkScalar corresponding
=======
#define SkAutoKern_AdjustF(prev, next)    (((next) - (prev) + 32) >> 6 << 16)
#define SkAutoKern_AdjustS(prev, next)    SkIntToScalar(((next) - (prev) + 32) >> 6)

/* this is a helper class to perform auto-kerning
 * the adjust() method returns a SkFixed corresponding
>>>>>>> miniblink49
 * to a +1/0/-1 pixel adjustment
 */

class SkAutoKern {
public:
<<<<<<< HEAD
    SkAutoKern()
        : fPrevRsbDelta(0)
    {
    }

    SkScalar adjust(const SkGlyph& glyph)
    {
        //        if (SkAbs32(glyph.fLsbDelta) > 47 || SkAbs32(glyph.fRsbDelta) > 47)
        //            printf("------- %d> L %d R %d\n", glyph.f_GlyphID, glyph.fLsbDelta, glyph.fRsbDelta);
=======
    SkAutoKern() : fPrevRsbDelta(0) {}

    SkFixed  adjust(const SkGlyph&  glyph)
    {
//        if (SkAbs32(glyph.fLsbDelta) > 47 || SkAbs32(glyph.fRsbDelta) > 47)
//            printf("------- %d> L %d R %d\n", glyph.f_GlyphID, glyph.fLsbDelta, glyph.fRsbDelta);
>>>>>>> miniblink49

#if 0
        int  distort = fPrevRsbDelta - glyph.fLsbDelta;

        fPrevRsbDelta = glyph.fRsbDelta;

        if (distort >= 32)
<<<<<<< HEAD
            return -SK_Scalar1;
        else if (distort < -32)
            return +SK_Scalar1;
        else
            return 0;
#else
        SkScalar adjust = SkAutoKern_Adjust(fPrevRsbDelta, glyph.fLsbDelta);
=======
            return -SK_Fixed1;
        else if (distort < -32)
            return +SK_Fixed1;
        else
            return 0;
#else
        SkFixed adjust = SkAutoKern_AdjustF(fPrevRsbDelta, glyph.fLsbDelta);
>>>>>>> miniblink49
        fPrevRsbDelta = glyph.fRsbDelta;
        return adjust;
#endif
    }
<<<<<<< HEAD

private:
    int fPrevRsbDelta;
=======
private:
    int   fPrevRsbDelta;
>>>>>>> miniblink49
};

#endif
