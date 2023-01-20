/*
* Copyright 2014 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#if SK_SUPPORT_GPU

#include "GrRectanizer_pow2.h"
#include "GrRectanizer_skyline.h"
#include "SkRandom.h"
#include "SkSize.h"
#include "SkTDArray.h"
#include "Test.h"

static const int kWidth = 1024;
static const int kHeight = 1024;

// Basic test of a GrRectanizer-derived class' functionality
<<<<<<< HEAD
static void test_rectanizer_basic(skiatest::Reporter* reporter, GrRectanizer* rectanizer)
{
=======
static void test_rectanizer_basic(skiatest::Reporter* reporter, GrRectanizer* rectanizer) {
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, kWidth == rectanizer->width());
    REPORTER_ASSERT(reporter, kHeight == rectanizer->height());

    SkIPoint16 loc;

    REPORTER_ASSERT(reporter, rectanizer->addRect(50, 50, &loc));
    REPORTER_ASSERT(reporter, rectanizer->percentFull() > 0.0f);
    rectanizer->reset();
    REPORTER_ASSERT(reporter, rectanizer->percentFull() == 0.0f);
}

static void test_rectanizer_inserts(skiatest::Reporter*,
<<<<<<< HEAD
    GrRectanizer* rectanizer,
    const SkTDArray<SkISize>& rects)
{
=======
                                    GrRectanizer* rectanizer,
                                    const SkTDArray<SkISize>& rects) {
>>>>>>> miniblink49
    int i;
    for (i = 0; i < rects.count(); ++i) {
        SkIPoint16 loc;
        if (!rectanizer->addRect(rects[i].fWidth, rects[i].fHeight, &loc)) {
            break;
        }
    }

    //SkDebugf("\n***%d %f\n", i, rectanizer->percentFull());
}

<<<<<<< HEAD
static void test_skyline(skiatest::Reporter* reporter, const SkTDArray<SkISize>& rects)
{
=======
static void test_skyline(skiatest::Reporter* reporter, const SkTDArray<SkISize>& rects) {
>>>>>>> miniblink49
    GrRectanizerSkyline skylineRectanizer(kWidth, kHeight);

    test_rectanizer_basic(reporter, &skylineRectanizer);
    test_rectanizer_inserts(reporter, &skylineRectanizer, rects);
}

<<<<<<< HEAD
static void test_pow2(skiatest::Reporter* reporter, const SkTDArray<SkISize>& rects)
{
=======
static void test_pow2(skiatest::Reporter* reporter, const SkTDArray<SkISize>& rects) {
>>>>>>> miniblink49
    GrRectanizerPow2 pow2Rectanizer(kWidth, kHeight);

    test_rectanizer_basic(reporter, &pow2Rectanizer);
    test_rectanizer_inserts(reporter, &pow2Rectanizer, rects);
}

<<<<<<< HEAD
DEF_GPUTEST(GpuRectanizer, reporter, factory)
{
=======
DEF_GPUTEST(GpuRectanizer, reporter, factory) {
>>>>>>> miniblink49
    SkTDArray<SkISize> rects;
    SkRandom rand;

    for (int i = 0; i < 50; i++) {
        rects.push(SkISize::Make(rand.nextRangeU(1, kWidth / 2),
<<<<<<< HEAD
            rand.nextRangeU(1, kHeight / 2)));
=======
                                 rand.nextRangeU(1, kHeight / 2)));
>>>>>>> miniblink49
    }

    test_skyline(reporter, rects);
    test_pow2(reporter, rects);
}

#endif
