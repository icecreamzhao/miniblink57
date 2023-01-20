/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrTestUtils.h"
<<<<<<< HEAD
#include "GrStyle.h"
#include "SkDashPathPriv.h"
=======
>>>>>>> miniblink49
#include "SkMatrix.h"
#include "SkPath.h"
#include "SkRRect.h"

#ifdef GR_TEST_UTILS

<<<<<<< HEAD
static const SkMatrix& test_matrix(SkRandom* random, bool includePerspective)
{
=======
static const SkMatrix& test_matrix(SkRandom* random, bool includePerspective) {
>>>>>>> miniblink49
    static SkMatrix gMatrices[5];
    static const int kPerspectiveCount = 1;
    static bool gOnce;
    if (!gOnce) {
        gOnce = true;
        gMatrices[0].reset();
        gMatrices[1].setTranslate(SkIntToScalar(-100), SkIntToScalar(100));
        gMatrices[2].setRotate(SkIntToScalar(17));
        gMatrices[3].setRotate(SkIntToScalar(185));
        gMatrices[3].postTranslate(SkIntToScalar(66), SkIntToScalar(-33));
        gMatrices[3].postScale(SkIntToScalar(2), SK_ScalarHalf);

        // Perspective matrices
        gMatrices[4].setRotate(SkIntToScalar(215));
        gMatrices[4].set(SkMatrix::kMPersp0, 0.00013f);
        gMatrices[4].set(SkMatrix::kMPersp1, -0.000039f);
    }

    uint32_t count = static_cast<uint32_t>(SK_ARRAY_COUNT(gMatrices));
    if (includePerspective) {
        return gMatrices[random->nextULessThan(count)];
    } else {
        return gMatrices[random->nextULessThan(count - kPerspectiveCount)];
    }
}

namespace GrTest {
const SkMatrix& TestMatrix(SkRandom* random) { return test_matrix(random, true); }

<<<<<<< HEAD
const SkMatrix& TestMatrixPreservesRightAngles(SkRandom* random)
{
=======
const SkMatrix& TestMatrixPreservesRightAngles(SkRandom* random) {
>>>>>>> miniblink49
    static SkMatrix gMatrices[5];
    static bool gOnce;
    if (!gOnce) {
        gOnce = true;
        // identity
        gMatrices[0].reset();
        // translation
        gMatrices[1].setTranslate(SkIntToScalar(-100), SkIntToScalar(100));
        // scale
        gMatrices[2].setScale(SkIntToScalar(17), SkIntToScalar(17));
        // scale + translation
        gMatrices[3].setScale(SkIntToScalar(-17), SkIntToScalar(-17));
        gMatrices[3].postTranslate(SkIntToScalar(66), SkIntToScalar(-33));
        // orthogonal basis vectors
        gMatrices[4].reset();
        gMatrices[4].setScale(SkIntToScalar(-1), SkIntToScalar(-1));
        gMatrices[4].setRotate(47);

        for (size_t i = 0; i < SK_ARRAY_COUNT(gMatrices); i++) {
            SkASSERT(gMatrices[i].preservesRightAngles());
        }
    }
    return gMatrices[random->nextULessThan(static_cast<uint32_t>(SK_ARRAY_COUNT(gMatrices)))];
}

<<<<<<< HEAD
const SkMatrix& TestMatrixRectStaysRect(SkRandom* random)
{
=======
const SkMatrix& TestMatrixRectStaysRect(SkRandom* random) {
>>>>>>> miniblink49
    static SkMatrix gMatrices[6];
    static bool gOnce;
    if (!gOnce) {
        gOnce = true;
        // identity
        gMatrices[0].reset();
        // translation
        gMatrices[1].setTranslate(SkIntToScalar(-100), SkIntToScalar(100));
        // scale
        gMatrices[2].setScale(SkIntToScalar(17), SkIntToScalar(17));
        // scale + translation
        gMatrices[3].setScale(SkIntToScalar(-17), SkIntToScalar(-17));
        gMatrices[3].postTranslate(SkIntToScalar(66), SkIntToScalar(-33));
        // reflection
        gMatrices[4].setScale(SkIntToScalar(-1), SkIntToScalar(-1));
        // 90 degress rotation
        gMatrices[5].setRotate(90);

        for (size_t i = 0; i < SK_ARRAY_COUNT(gMatrices); i++) {
            SkASSERT(gMatrices[i].rectStaysRect());
        }
    }
    return gMatrices[random->nextULessThan(static_cast<uint32_t>(SK_ARRAY_COUNT(gMatrices)))];
}

const SkMatrix& TestMatrixInvertible(SkRandom* random) { return test_matrix(random, false); }

<<<<<<< HEAD
const SkRect& TestRect(SkRandom* random)
{
=======
const SkRect& TestRect(SkRandom* random) {
>>>>>>> miniblink49
    static SkRect gRects[7];
    static bool gOnce;
    if (!gOnce) {
        gOnce = true;
        gRects[0] = SkRect::MakeWH(1.f, 1.f);
        gRects[1] = SkRect::MakeWH(1.0f, 256.0f);
        gRects[2] = SkRect::MakeWH(256.0f, 1.0f);
<<<<<<< HEAD
        gRects[3] = SkRect::MakeLargest();
        gRects[4] = SkRect::MakeLTRB(-65535.0f, -65535.0f, 65535.0f, 65535.0f);
        gRects[5] = SkRect::MakeLTRB(-10.0f, -10.0f, 10.0f, 10.0f);
=======
        gRects[4] = SkRect::MakeLargest();
        gRects[5] = SkRect::MakeLTRB(-65535.0f, -65535.0f, 65535.0f, 65535.0f);
        gRects[6] = SkRect::MakeLTRB(-10.0f, -10.0f, 10.0f, 10.0f);
>>>>>>> miniblink49
    }
    return gRects[random->nextULessThan(static_cast<uint32_t>(SK_ARRAY_COUNT(gRects)))];
}

// Just some simple rects for code which expects its input very sanitized
<<<<<<< HEAD
const SkRect& TestSquare(SkRandom* random)
{
=======
const SkRect& TestSquare(SkRandom* random) {
>>>>>>> miniblink49
    static SkRect gRects[2];
    static bool gOnce;
    if (!gOnce) {
        gOnce = true;
        gRects[0] = SkRect::MakeWH(128.f, 128.f);
        gRects[1] = SkRect::MakeWH(256.0f, 256.0f);
    }
    return gRects[random->nextULessThan(static_cast<uint32_t>(SK_ARRAY_COUNT(gRects)))];
}

<<<<<<< HEAD
const SkRRect& TestRRectSimple(SkRandom* random)
{
=======
const SkRRect& TestRRectSimple(SkRandom* random) {
>>>>>>> miniblink49
    static SkRRect gRRect[2];
    static bool gOnce;
    if (!gOnce) {
        gOnce = true;
        SkRect rectangle = SkRect::MakeWH(10.f, 20.f);
        // true round rect with circular corners
        gRRect[0].setRectXY(rectangle, 1.f, 1.f);
        // true round rect with elliptical corners
        gRRect[1].setRectXY(rectangle, 2.0f, 1.0f);

        for (size_t i = 0; i < SK_ARRAY_COUNT(gRRect); i++) {
            SkASSERT(gRRect[i].isSimple());
        }
    }
    return gRRect[random->nextULessThan(static_cast<uint32_t>(SK_ARRAY_COUNT(gRRect)))];
}

<<<<<<< HEAD
const SkPath& TestPath(SkRandom* random)
{
=======
const SkPath& TestPath(SkRandom* random) {
>>>>>>> miniblink49
    static SkPath gPath[7];
    static bool gOnce;
    if (!gOnce) {
        gOnce = true;
        // line
        gPath[0].moveTo(0.f, 0.f);
        gPath[0].lineTo(10.f, 10.f);
        // quad
        gPath[1].moveTo(0.f, 0.f);
        gPath[1].quadTo(10.f, 10.f, 20.f, 20.f);
        // conic
        gPath[2].moveTo(0.f, 0.f);
        gPath[2].conicTo(10.f, 10.f, 20.f, 20.f, 1.f);
        // cubic
        gPath[3].moveTo(0.f, 0.f);
        gPath[3].cubicTo(10.f, 10.f, 20.f, 20.f, 30.f, 30.f);
        // all three
        gPath[4].moveTo(0.f, 0.f);
        gPath[4].lineTo(10.f, 10.f);
        gPath[4].quadTo(10.f, 10.f, 20.f, 20.f);
        gPath[4].conicTo(10.f, 10.f, 20.f, 20.f, 1.f);
        gPath[4].cubicTo(10.f, 10.f, 20.f, 20.f, 30.f, 30.f);
        // convex
        gPath[5].moveTo(0.0f, 0.0f);
        gPath[5].lineTo(10.0f, 0.0f);
        gPath[5].lineTo(10.0f, 10.0f);
        gPath[5].lineTo(0.0f, 10.0f);
        gPath[5].close();
        // concave
        gPath[6].moveTo(0.0f, 0.0f);
        gPath[6].lineTo(5.0f, 5.0f);
        gPath[6].lineTo(10.0f, 0.0f);
        gPath[6].lineTo(10.0f, 10.0f);
        gPath[6].lineTo(0.0f, 10.0f);
        gPath[6].close();
    }

    return gPath[random->nextULessThan(static_cast<uint32_t>(SK_ARRAY_COUNT(gPath)))];
}

<<<<<<< HEAD
const SkPath& TestPathConvex(SkRandom* random)
{
=======
const SkPath& TestPathConvex(SkRandom* random) {
>>>>>>> miniblink49
    static SkPath gPath[3];
    static bool gOnce;
    if (!gOnce) {
        gOnce = true;
        // narrow rect
        gPath[0].moveTo(-1.5f, -50.0f);
        gPath[0].lineTo(-1.5f, -50.0f);
<<<<<<< HEAD
        gPath[0].lineTo(1.5f, -50.0f);
        gPath[0].lineTo(1.5f, 50.0f);
        gPath[0].lineTo(-1.5f, 50.0f);
        // degenerate
        gPath[1].moveTo(-0.025f, -0.025f);
        gPath[1].lineTo(-0.025f, -0.025f);
        gPath[1].lineTo(0.025f, -0.025f);
        gPath[1].lineTo(0.025f, 0.025f);
        gPath[1].lineTo(-0.025f, 0.025f);
        // clipped triangle
        gPath[2].moveTo(-10.0f, -50.0f);
        gPath[2].lineTo(-10.0f, -50.0f);
        gPath[2].lineTo(10.0f, -50.0f);
        gPath[2].lineTo(50.0f, 31.0f);
        gPath[2].lineTo(40.0f, 50.0f);
        gPath[2].lineTo(-40.0f, 50.0f);
        gPath[2].lineTo(-50.0f, 31.0f);
=======
        gPath[0].lineTo( 1.5f, -50.0f);
        gPath[0].lineTo( 1.5f,  50.0f);
        gPath[0].lineTo(-1.5f,  50.0f);
        // degenerate
        gPath[1].moveTo(-0.025f, -0.025f);
        gPath[1].lineTo(-0.025f, -0.025f);
        gPath[1].lineTo( 0.025f, -0.025f);
        gPath[1].lineTo( 0.025f,  0.025f);
        gPath[1].lineTo(-0.025f,  0.025f);
        // clipped triangle
        gPath[2].moveTo(-10.0f, -50.0f);
        gPath[2].lineTo(-10.0f, -50.0f);
        gPath[2].lineTo( 10.0f, -50.0f);
        gPath[2].lineTo( 50.0f,  31.0f);
        gPath[2].lineTo( 40.0f,  50.0f);
        gPath[2].lineTo(-40.0f,  50.0f);
        gPath[2].lineTo(-50.0f,  31.0f);
>>>>>>> miniblink49

        for (size_t i = 0; i < SK_ARRAY_COUNT(gPath); i++) {
            SkASSERT(SkPath::kConvex_Convexity == gPath[i].getConvexity());
        }
    }

    return gPath[random->nextULessThan(static_cast<uint32_t>(SK_ARRAY_COUNT(gPath)))];
}

<<<<<<< HEAD
static void randomize_stroke_rec(SkStrokeRec* rec, SkRandom* random)
{
    bool strokeAndFill = random->nextBool();
    SkScalar strokeWidth = random->nextBool() ? 0.f : 1.f;
    rec->setStrokeStyle(strokeWidth, strokeAndFill);
=======
SkStrokeRec TestStrokeRec(SkRandom* random) {
    SkStrokeRec::InitStyle style =
            SkStrokeRec::InitStyle(random->nextULessThan(SkStrokeRec::kFill_InitStyle + 1));
    SkStrokeRec rec(style);
    bool strokeAndFill = random->nextBool();
    SkScalar strokeWidth = random->nextBool() ? 0.f : 1.f;
    rec.setStrokeStyle(strokeWidth, strokeAndFill);
>>>>>>> miniblink49

    SkPaint::Cap cap = SkPaint::Cap(random->nextULessThan(SkPaint::kCapCount));
    SkPaint::Join join = SkPaint::Join(random->nextULessThan(SkPaint::kJoinCount));
    SkScalar miterLimit = random->nextRangeScalar(1.f, 5.f);
<<<<<<< HEAD
    rec->setStrokeParams(cap, join, miterLimit);
}

SkStrokeRec TestStrokeRec(SkRandom* random)
{
    SkStrokeRec::InitStyle style = SkStrokeRec::InitStyle(random->nextULessThan(SkStrokeRec::kFill_InitStyle + 1));
    SkStrokeRec rec(style);
    randomize_stroke_rec(&rec, random);
    return rec;
}

void TestStyle(SkRandom* random, GrStyle* style)
{
    SkStrokeRec::InitStyle initStyle = SkStrokeRec::InitStyle(random->nextULessThan(SkStrokeRec::kFill_InitStyle + 1));
    SkStrokeRec stroke(initStyle);
    randomize_stroke_rec(&stroke, random);
    sk_sp<SkPathEffect> pe;
    if (random->nextBool()) {
        int cnt = random->nextRangeU(1, 50) * 2;
        SkAutoTDeleteArray<SkScalar> intervals(new SkScalar[cnt]);
        SkScalar sum = 0;
        for (int i = 0; i < cnt; i++) {
            intervals[i] = random->nextRangeScalar(SkDoubleToScalar(0.01),
                SkDoubleToScalar(10.0));
            sum += intervals[i];
        }
        SkScalar phase = random->nextRangeScalar(0, sum);
        pe = TestDashPathEffect::Make(intervals.get(), cnt, phase);
    }
    *style = GrStyle(stroke, pe.get());
}

TestDashPathEffect::TestDashPathEffect(const SkScalar* intervals, int count, SkScalar phase)
{
    fCount = count;
    fIntervals.reset(count);
    memcpy(fIntervals.get(), intervals, count * sizeof(SkScalar));
    SkDashPath::CalcDashParameters(phase, intervals, count, &fInitialDashLength,
        &fInitialDashIndex, &fIntervalLength, &fPhase);
}

bool TestDashPathEffect::filterPath(SkPath* dst, const SkPath& src, SkStrokeRec* rec,
    const SkRect* cullRect) const
{
    return SkDashPath::InternalFilter(dst, src, rec, cullRect, fIntervals.get(), fCount,
        fInitialDashLength, fInitialDashIndex, fIntervalLength);
}

SkPathEffect::DashType TestDashPathEffect::asADash(DashInfo* info) const
{
    if (info) {
        if (info->fCount >= fCount && info->fIntervals) {
            memcpy(info->fIntervals, fIntervals.get(), fCount * sizeof(SkScalar));
        }
        info->fCount = fCount;
        info->fPhase = fPhase;
    }
    return kDash_DashType;
}

} // namespace GrTest
=======
    rec.setStrokeParams(cap, join, miterLimit);
    return rec;
}

};
>>>>>>> miniblink49

#endif
