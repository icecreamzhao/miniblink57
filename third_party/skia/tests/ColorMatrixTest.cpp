/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Test.h"

#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkColor.h"
#include "SkColorMatrixFilter.h"
#include "SkPaint.h"

#include <stdlib.h>

static inline void assert_color(skiatest::Reporter* reporter,
<<<<<<< HEAD
    SkColor expected, SkColor actual, int tolerance)
{
=======
                                SkColor expected, SkColor actual, int tolerance) {
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, abs((int)(SkColorGetA(expected) - SkColorGetA(actual))) <= tolerance);
    REPORTER_ASSERT(reporter, abs((int)(SkColorGetR(expected) - SkColorGetR(actual))) <= tolerance);
    REPORTER_ASSERT(reporter, abs((int)(SkColorGetG(expected) - SkColorGetG(actual))) <= tolerance);
    REPORTER_ASSERT(reporter, abs((int)(SkColorGetB(expected) - SkColorGetB(actual))) <= tolerance);
}

<<<<<<< HEAD
static inline void assert_color(skiatest::Reporter* reporter, SkColor expected, SkColor actual)
{
=======
static inline void assert_color(skiatest::Reporter* reporter, SkColor expected, SkColor actual) {
>>>>>>> miniblink49
    const int TOLERANCE = 1;
    assert_color(reporter, expected, actual, TOLERANCE);
}

/**
 * This test case is a mirror of the Android CTS tests for MatrixColorFilter
 * found in the android.graphics.ColorMatrixColorFilterTest class.
 */
<<<<<<< HEAD
static inline void test_colorMatrixCTS(skiatest::Reporter* reporter)
{

    SkBitmap bitmap;
    bitmap.allocN32Pixels(1, 1);
=======
static inline void test_colorMatrixCTS(skiatest::Reporter* reporter) {

    SkBitmap bitmap;
    bitmap.allocN32Pixels(1,1);
>>>>>>> miniblink49

    SkCanvas canvas(bitmap);
    SkPaint paint;

    SkScalar blueToCyan[20] = {
<<<<<<< HEAD
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f, 0.0f
    };
    paint.setColorFilter(SkColorFilter::MakeMatrixFilterRowMajor255(blueToCyan));
=======
            1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f, 0.0f };
    paint.setColorFilter(SkColorMatrixFilter::Create(blueToCyan))->unref();
>>>>>>> miniblink49

    paint.setColor(SK_ColorBLUE);
    canvas.drawPoint(0, 0, paint);
    assert_color(reporter, SK_ColorCYAN, bitmap.getColor(0, 0));

    paint.setColor(SK_ColorGREEN);
    canvas.drawPoint(0, 0, paint);
    assert_color(reporter, SK_ColorGREEN, bitmap.getColor(0, 0));

    paint.setColor(SK_ColorRED);
    canvas.drawPoint(0, 0, paint);
    assert_color(reporter, SK_ColorRED, bitmap.getColor(0, 0));

    // color components are clipped, not scaled
    paint.setColor(SK_ColorMAGENTA);
    canvas.drawPoint(0, 0, paint);
    assert_color(reporter, SK_ColorWHITE, bitmap.getColor(0, 0));

    SkScalar transparentRedAddBlue[20] = {
<<<<<<< HEAD
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f, 64.0f,
        -0.5f, 0.0f, 0.0f, 1.0f, 0.0f
    };
    paint.setColorFilter(SkColorFilter::MakeMatrixFilterRowMajor255(transparentRedAddBlue));
=======
            1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f, 64.0f,
           -0.5f, 0.0f, 0.0f, 1.0f, 0.0f
    };
    paint.setColorFilter(SkColorMatrixFilter::Create(transparentRedAddBlue))->unref();
>>>>>>> miniblink49
    bitmap.eraseColor(SK_ColorTRANSPARENT);

    paint.setColor(SK_ColorRED);
    canvas.drawPoint(0, 0, paint);
    assert_color(reporter, SkColorSetARGB(128, 255, 0, 64), bitmap.getColor(0, 0), 2);

    paint.setColor(SK_ColorCYAN);
    canvas.drawPoint(0, 0, paint);
    // blue gets clipped
    assert_color(reporter, SK_ColorCYAN, bitmap.getColor(0, 0));

    // change array to filter out green
    REPORTER_ASSERT(reporter, 1.0f == transparentRedAddBlue[6]);
    transparentRedAddBlue[6] = 0.0f;

    // check that changing the array has no effect
    canvas.drawPoint(0, 0, paint);
    assert_color(reporter, SK_ColorCYAN, bitmap.getColor(0, 0));

    // create a new filter with the changed matrix
<<<<<<< HEAD
    paint.setColorFilter(SkColorFilter::MakeMatrixFilterRowMajor255(transparentRedAddBlue));
=======
    paint.setColorFilter(SkColorMatrixFilter::Create(transparentRedAddBlue))->unref();
>>>>>>> miniblink49
    canvas.drawPoint(0, 0, paint);
    assert_color(reporter, SK_ColorBLUE, bitmap.getColor(0, 0));
}

<<<<<<< HEAD
DEF_TEST(ColorMatrix, reporter)
{
=======
DEF_TEST(ColorMatrix, reporter) {
>>>>>>> miniblink49
    test_colorMatrixCTS(reporter);
}
