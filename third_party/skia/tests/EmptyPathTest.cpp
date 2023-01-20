/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkCanvas.h"
#include "SkPath.h"
#include "Test.h"

<<<<<<< HEAD
#define DIMENSION 32

static void drawAndTest(skiatest::Reporter* reporter, const SkPath& path,
    const SkPaint& paint, bool shouldDraw)
{
    SkBitmap bm;
    bm.allocN32Pixels(DIMENSION, DIMENSION);
    SkASSERT(DIMENSION * 4 == bm.rowBytes()); // ensure no padding on each row
=======
#define DIMENSION   32

static void drawAndTest(skiatest::Reporter* reporter, const SkPath& path,
                        const SkPaint& paint, bool shouldDraw) {
    SkBitmap bm;
    bm.allocN32Pixels(DIMENSION, DIMENSION);
    SkASSERT(DIMENSION*4 == bm.rowBytes()); // ensure no padding on each row
>>>>>>> miniblink49
    bm.eraseColor(SK_ColorTRANSPARENT);

    SkCanvas canvas(bm);
    SkPaint p(paint);
    p.setColor(SK_ColorWHITE);

    canvas.drawPath(path, p);

    size_t count = DIMENSION * DIMENSION;
    const SkPMColor* ptr = bm.getAddr32(0, 0);

    SkPMColor andValue = ~0U;
    SkPMColor orValue = 0;
    for (size_t i = 0; i < count; ++i) {
        SkPMColor c = ptr[i];
        andValue &= c;
        orValue |= c;
    }

    // success means we drew everywhere or nowhere (depending on shouldDraw)
    bool success = shouldDraw ? (~0U == andValue) : (0 == orValue);

    if (!success) {
        const char* str;
        if (shouldDraw) {
            str = "Path expected to draw everywhere, but didn't. ";
        } else {
            str = "Path expected to draw nowhere, but did. ";
        }
        ERRORF(reporter, "%s style[%d] cap[%d] join[%d] antialias[%d]"
<<<<<<< HEAD
                         " filltype[%d] ptcount[%d]",
            str, paint.getStyle(),
            paint.getStrokeCap(), paint.getStrokeJoin(),
            paint.isAntiAlias(), path.getFillType(), path.countPoints());
        // uncomment this if you want to step in to see the failure
        //        canvas.drawPath(path, p);
    }
}

enum DrawCaps {
    kDontDrawCaps,
    kDrawCaps
};

static void iter_paint(skiatest::Reporter* reporter, const SkPath& path, bool shouldDraw,
    DrawCaps drawCaps)
{
=======
               " filltype[%d] ptcount[%d]", str, paint.getStyle(),
               paint.getStrokeCap(), paint.getStrokeJoin(),
               paint.isAntiAlias(), path.getFillType(), path.countPoints());
// uncomment this if you want to step in to see the failure
//        canvas.drawPath(path, p);
    }
}

static void iter_paint(skiatest::Reporter* reporter, const SkPath& path, bool shouldDraw) {
>>>>>>> miniblink49
    static const SkPaint::Cap gCaps[] = {
        SkPaint::kButt_Cap,
        SkPaint::kRound_Cap,
        SkPaint::kSquare_Cap
    };
    static const SkPaint::Join gJoins[] = {
        SkPaint::kMiter_Join,
        SkPaint::kRound_Join,
        SkPaint::kBevel_Join
    };
    static const SkPaint::Style gStyles[] = {
        SkPaint::kFill_Style,
        SkPaint::kStroke_Style,
        SkPaint::kStrokeAndFill_Style
    };
    for (size_t cap = 0; cap < SK_ARRAY_COUNT(gCaps); ++cap) {
        for (size_t join = 0; join < SK_ARRAY_COUNT(gJoins); ++join) {
            for (size_t style = 0; style < SK_ARRAY_COUNT(gStyles); ++style) {
<<<<<<< HEAD
                if (drawCaps && SkPaint::kButt_Cap != gCaps[cap]
                    && SkPaint::kFill_Style != gStyles[style]) {
                    continue;
                }

=======
>>>>>>> miniblink49
                SkPaint paint;
                paint.setStrokeWidth(SkIntToScalar(10));

                paint.setStrokeCap(gCaps[cap]);
                paint.setStrokeJoin(gJoins[join]);
                paint.setStyle(gStyles[style]);

                paint.setAntiAlias(false);
                drawAndTest(reporter, path, paint, shouldDraw);
                paint.setAntiAlias(true);
                drawAndTest(reporter, path, paint, shouldDraw);
            }
        }
    }
}

<<<<<<< HEAD
#define CX (SkIntToScalar(DIMENSION) / 2)
#define CY (SkIntToScalar(DIMENSION) / 2)

static void make_empty(SkPath*)
{
}
static void make_M(SkPath* path) { path->moveTo(CX, CY); }
static void make_MM(SkPath* path)
{
    path->moveTo(CX, CY);
    path->moveTo(CX, CY);
}
static void make_MZM(SkPath* path)
{
    path->moveTo(CX, CY);
    path->close();
    path->moveTo(CX, CY);
}
static void make_L(SkPath* path)
{
    path->moveTo(CX, CY);
    path->lineTo(CX, CY);
}
static void make_Q(SkPath* path)
{
    path->moveTo(CX, CY);
    path->quadTo(CX, CY, CX, CY);
}
static void make_C(SkPath* path)
{
    path->moveTo(CX, CY);
    path->cubicTo(CX, CY, CX, CY, CX, CY);
}
=======
#define CX  (SkIntToScalar(DIMENSION) / 2)
#define CY  (SkIntToScalar(DIMENSION) / 2)

static void make_empty(SkPath*) {}
static void make_M(SkPath* path) { path->moveTo(CX, CY); }
static void make_MM(SkPath* path) { path->moveTo(CX, CY); path->moveTo(CX, CY); }
static void make_MZM(SkPath* path) { path->moveTo(CX, CY); path->close(); path->moveTo(CX, CY); }
static void make_L(SkPath* path) { path->moveTo(CX, CY); path->lineTo(CX, CY); }
static void make_Q(SkPath* path) { path->moveTo(CX, CY); path->quadTo(CX, CY, CX, CY); }
static void make_C(SkPath* path) { path->moveTo(CX, CY); path->cubicTo(CX, CY, CX, CY, CX, CY); }
>>>>>>> miniblink49

/*  Two invariants are tested: How does an empty/degenerate path draw?
 *  - if the path is drawn inverse, it should draw everywhere
 *  - if the path is drawn non-inverse, it should draw nowhere
 *
 *  Things to iterate on:
 *  - path (empty, degenerate line/quad/cubic w/ and w/o close
 *  - paint style
 *  - path filltype
 *  - path stroke variants (e.g. caps, joins, width)
 */
<<<<<<< HEAD
static void test_emptydrawing(skiatest::Reporter* reporter)
{
=======
static void test_emptydrawing(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    static void (*gMakeProc[])(SkPath*) = {
        make_empty, make_M, make_MM, make_MZM, make_L, make_Q, make_C
    };
    static SkPath::FillType gFills[] = {
        SkPath::kWinding_FillType,
        SkPath::kEvenOdd_FillType,
        SkPath::kInverseWinding_FillType,
        SkPath::kInverseEvenOdd_FillType
    };
    for (int doClose = 0; doClose < 2; ++doClose) {
<<<<<<< HEAD
        for (size_t i = 0; i < SK_ARRAY_COUNT(gMakeProc); ++i) {
=======
        for  (size_t i = 0; i < SK_ARRAY_COUNT(gMakeProc); ++i) {
>>>>>>> miniblink49
            SkPath path;
            gMakeProc[i](&path);
            if (doClose) {
                path.close();
            }
<<<<<<< HEAD
            /* zero length segments and close following moves draw round and square caps */
            bool allowCaps = make_L == gMakeProc[i] || make_Q == gMakeProc[i]
                || make_C == gMakeProc[i] || make_MZM == gMakeProc[i];
            allowCaps |= SkToBool(doClose);
            for (size_t fill = 0; fill < SK_ARRAY_COUNT(gFills); ++fill) {
                path.setFillType(gFills[fill]);
                bool shouldDraw = path.isInverseFillType();
                iter_paint(reporter, path, shouldDraw, allowCaps ? kDrawCaps : kDontDrawCaps);
=======
            for (size_t fill = 0; fill < SK_ARRAY_COUNT(gFills); ++fill) {
                path.setFillType(gFills[fill]);
                bool shouldDraw = path.isInverseFillType();
                iter_paint(reporter, path, shouldDraw);
>>>>>>> miniblink49
            }
        }
    }
}

<<<<<<< HEAD
DEF_TEST(EmptyPath, reporter)
{
=======
DEF_TEST(EmptyPath, reporter) {
>>>>>>> miniblink49
    test_emptydrawing(reporter);
}
