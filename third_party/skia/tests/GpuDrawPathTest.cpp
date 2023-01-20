/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTypes.h"

#if SK_SUPPORT_GPU

#include "GrContext.h"
#include "GrPath.h"
#include "GrStyle.h"
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkColor.h"
#include "SkDashPathEffect.h"
#include "SkPaint.h"
#include "SkPath.h"
=======
#if SK_SUPPORT_GPU

#include "GrContext.h"
#include "GrContextFactory.h"
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkColor.h"
#include "SkPaint.h"
>>>>>>> miniblink49
#include "SkRRect.h"
#include "SkRect.h"
#include "SkSurface.h"
#include "Test.h"

<<<<<<< HEAD
#include <initializer_list>

static void test_drawPathEmpty(skiatest::Reporter*, SkCanvas* canvas)
{
    // Filling an empty path should not crash.
    SkPaint paint;
    SkRect emptyRect = SkRect::MakeEmpty();
    canvas->drawRect(emptyRect, paint);
    canvas->drawPath(SkPath(), paint);
    canvas->drawOval(emptyRect, paint);
    canvas->drawRect(emptyRect, paint);
    canvas->drawRRect(SkRRect::MakeRect(emptyRect), paint);
=======
static void test_drawPathEmpty(skiatest::Reporter*, SkCanvas* canvas) {
    // Filling an empty path should not crash.
    SkPaint paint;
    canvas->drawRect(SkRect(), paint);
    canvas->drawPath(SkPath(), paint);
    canvas->drawOval(SkRect(), paint);
    canvas->drawRect(SkRect(), paint);
    canvas->drawRRect(SkRRect(), paint);
>>>>>>> miniblink49

    // Stroking an empty path should not crash.
    paint.setAntiAlias(true);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setColor(SK_ColorGRAY);
    paint.setStrokeWidth(SkIntToScalar(20));
    paint.setStrokeJoin(SkPaint::kRound_Join);
<<<<<<< HEAD
    canvas->drawRect(emptyRect, paint);
    canvas->drawPath(SkPath(), paint);
    canvas->drawOval(emptyRect, paint);
    canvas->drawRect(emptyRect, paint);
    canvas->drawRRect(SkRRect::MakeRect(emptyRect), paint);
}

static void fill_and_stroke(SkCanvas* canvas, const SkPath& p1, const SkPath& p2,
    sk_sp<SkPathEffect> effect)
{
    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setPathEffect(effect);

    canvas->drawPath(p1, paint);
    canvas->drawPath(p2, paint);

    paint.setStyle(SkPaint::kStroke_Style);
    canvas->drawPath(p1, paint);
    canvas->drawPath(p2, paint);
}

static void test_drawSameRectOvals(skiatest::Reporter*, SkCanvas* canvas)
{
    // Drawing ovals with similar bounds but different points order should not crash.

    SkPath oval1, oval2;
    const SkRect rect = SkRect::MakeWH(100, 50);
    oval1.addOval(rect, SkPath::kCW_Direction);
    oval2.addOval(rect, SkPath::kCCW_Direction);

    fill_and_stroke(canvas, oval1, oval2, nullptr);

    const SkScalar intervals[] = { 1, 1 };
    fill_and_stroke(canvas, oval1, oval2, SkDashPathEffect::Make(intervals, 2, 0));
}

DEF_GPUTEST_FOR_ALL_GL_CONTEXTS(GpuDrawPath, reporter, ctxInfo)
{
    for (auto& test_func : { &test_drawPathEmpty, &test_drawSameRectOvals }) {
        for (auto& sampleCount : { 0, 4, 16 }) {
            SkImageInfo info = SkImageInfo::MakeN32Premul(255, 255);
            auto surface(
                SkSurface::MakeRenderTarget(ctxInfo.grContext(), SkBudgeted::kNo, info,
                    sampleCount, nullptr));
            if (!surface) {
                continue;
            }
            test_func(reporter, surface->getCanvas());
=======
    canvas->drawRect(SkRect(), paint);
    canvas->drawPath(SkPath(), paint);
    canvas->drawOval(SkRect(), paint);
    canvas->drawRect(SkRect(), paint);
    canvas->drawRRect(SkRRect(), paint);
}


DEF_GPUTEST(GpuDrawPath, reporter, factory) {
    return;

    for (int type = 0; type < GrContextFactory::kLastGLContextType; ++type) {
        GrContextFactory::GLContextType glType = static_cast<GrContextFactory::GLContextType>(type);

        GrContext* grContext = factory->get(glType);
        if (NULL == grContext) {
            continue;
        }
        static const int sampleCounts[] = { 0, 4, 16 };

        for (size_t i = 0; i < SK_ARRAY_COUNT(sampleCounts); ++i) {
            SkImageInfo info = SkImageInfo::MakeN32Premul(255, 255);
            
            SkAutoTUnref<SkSurface> surface(
                SkSurface::NewRenderTarget(grContext, SkSurface::kNo_Budgeted, info,
                                           sampleCounts[i], NULL));
            test_drawPathEmpty(reporter, surface->getCanvas());
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
DEF_GPUTEST(GrPathKeys, reporter, /*factory*/)
{
    // Keys should not ignore conic weights.
    SkPath path1, path2;
    path1.setIsVolatile(true);
    path2.setIsVolatile(true);
    SkPoint p0 = SkPoint::Make(100, 0);
    SkPoint p1 = SkPoint::Make(100, 100);

    path1.conicTo(p0, p1, .5f);
    path2.conicTo(p0, p1, .7f);

    bool isVolatile;
    GrUniqueKey key1, key2;
    GrPath::ComputeKey(path1, GrStyle::SimpleFill(), &key1, &isVolatile);
    GrPath::ComputeKey(path2, GrStyle::SimpleFill(), &key2, &isVolatile);
    REPORTER_ASSERT(reporter, key1 != key2);
}

=======
>>>>>>> miniblink49
#endif
