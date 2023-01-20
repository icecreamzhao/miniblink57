/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "PathOpsExtendedTest.h"
#include "PathOpsThreadedCommon.h"
#include "SkCanvas.h"
#include "SkRandom.h"
#include "SkTSort.h"
#include "Test.h"

<<<<<<< HEAD
static void testTightBoundsLines(PathOpsThreadState* data)
{
=======
static void testTightBoundsLines(PathOpsThreadState* data) {
>>>>>>> miniblink49
    SkRandom ran;
    for (int index = 0; index < 1000; ++index) {
        SkPath path;
        int contourCount = ran.nextRangeU(1, 10);
        for (int cIndex = 0; cIndex < contourCount; ++cIndex) {
            int lineCount = ran.nextRangeU(1, 10);
            path.moveTo(ran.nextRangeF(-1000, 1000), ran.nextRangeF(-1000, 1000));
            for (int lIndex = 0; lIndex < lineCount; ++lIndex) {
                path.lineTo(ran.nextRangeF(-1000, 1000), ran.nextRangeF(-1000, 1000));
            }
            if (ran.nextBool()) {
                path.close();
            }
        }
        SkRect classicBounds = path.getBounds();
        SkRect tightBounds;
        REPORTER_ASSERT(data->fReporter, TightBounds(path, &tightBounds));
        REPORTER_ASSERT(data->fReporter, classicBounds == tightBounds);
    }
}

<<<<<<< HEAD
DEF_TEST(PathOpsTightBoundsLines, reporter)
{
=======
DEF_TEST(PathOpsTightBoundsLines, reporter) {
>>>>>>> miniblink49
    initializeTests(reporter, "tightBoundsLines");
    PathOpsThreadedTestRunner testRunner(reporter);
    int outerCount = reporter->allowExtendedTest() ? 100 : 1;
    for (int index = 0; index < outerCount; ++index) {
        for (int idx2 = 0; idx2 < 10; ++idx2) {
<<<<<<< HEAD
            *testRunner.fRunnables.append() = new PathOpsThreadedRunnable(&testTightBoundsLines, 0, 0, 0, 0, &testRunner);
=======
            *testRunner.fRunnables.append() = SkNEW_ARGS(PathOpsThreadedRunnable,
                    (&testTightBoundsLines, 0, 0, 0, 0, &testRunner));
>>>>>>> miniblink49
        }
    }
    testRunner.render();
}

<<<<<<< HEAD
static void testTightBoundsQuads(PathOpsThreadState* data)
{
=======
static void testTightBoundsQuads(PathOpsThreadState* data) {
>>>>>>> miniblink49
    SkRandom ran;
    const int bitWidth = 32;
    const int bitHeight = 32;
    const float pathMin = 1;
<<<<<<< HEAD
    const float pathMax = (float)(bitHeight - 2);
=======
    const float pathMax = (float) (bitHeight - 2);
>>>>>>> miniblink49
    SkBitmap& bits = *data->fBitmap;
    if (bits.width() == 0) {
        bits.allocN32Pixels(bitWidth, bitHeight);
    }
    SkCanvas canvas(bits);
    SkPaint paint;
    for (int index = 0; index < 100; ++index) {
        SkPath path;
        int contourCount = ran.nextRangeU(1, 10);
        for (int cIndex = 0; cIndex < contourCount; ++cIndex) {
            int lineCount = ran.nextRangeU(1, 10);
            path.moveTo(ran.nextRangeF(1, pathMax), ran.nextRangeF(pathMin, pathMax));
            for (int lIndex = 0; lIndex < lineCount; ++lIndex) {
                if (ran.nextBool()) {
                    path.lineTo(ran.nextRangeF(pathMin, pathMax), ran.nextRangeF(pathMin, pathMax));
                } else {
                    path.quadTo(ran.nextRangeF(pathMin, pathMax), ran.nextRangeF(pathMin, pathMax),
<<<<<<< HEAD
                        ran.nextRangeF(pathMin, pathMax), ran.nextRangeF(pathMin, pathMax));
=======
                            ran.nextRangeF(pathMin, pathMax), ran.nextRangeF(pathMin, pathMax));
>>>>>>> miniblink49
                }
            }
            if (ran.nextBool()) {
                path.close();
            }
        }
        SkRect classicBounds = path.getBounds();
        SkRect tightBounds;
        REPORTER_ASSERT(data->fReporter, TightBounds(path, &tightBounds));
        REPORTER_ASSERT(data->fReporter, classicBounds.contains(tightBounds));
        canvas.drawColor(SK_ColorWHITE);
        canvas.drawPath(path, paint);
<<<<<<< HEAD
        SkIRect bitsWritten = { 31, 31, 0, 0 };
=======
        SkIRect bitsWritten = {31, 31, 0, 0};
>>>>>>> miniblink49
        for (int y = 0; y < bitHeight; ++y) {
            uint32_t* addr1 = data->fBitmap->getAddr32(0, y);
            bool lineWritten = false;
            for (int x = 0; x < bitWidth; ++x) {
<<<<<<< HEAD
                if (addr1[x] == (uint32_t)-1) {
=======
                if (addr1[x] == (uint32_t) -1) {
>>>>>>> miniblink49
                    continue;
                }
                lineWritten = true;
                bitsWritten.fLeft = SkTMin(bitsWritten.fLeft, x);
                bitsWritten.fRight = SkTMax(bitsWritten.fRight, x);
            }
            if (!lineWritten) {
                continue;
            }
            bitsWritten.fTop = SkTMin(bitsWritten.fTop, y);
            bitsWritten.fBottom = SkTMax(bitsWritten.fBottom, y);
        }
        if (!bitsWritten.isEmpty()) {
            SkIRect tightOut;
            tightBounds.roundOut(&tightOut);
            REPORTER_ASSERT(data->fReporter, tightOut.contains(bitsWritten));
        }
    }
}

<<<<<<< HEAD
DEF_TEST(PathOpsTightBoundsQuads, reporter)
{
=======
DEF_TEST(PathOpsTightBoundsQuads, reporter) {
>>>>>>> miniblink49
    initializeTests(reporter, "tightBoundsQuads");
    PathOpsThreadedTestRunner testRunner(reporter);
    int outerCount = reporter->allowExtendedTest() ? 100 : 1;
    for (int index = 0; index < outerCount; ++index) {
        for (int idx2 = 0; idx2 < 10; ++idx2) {
<<<<<<< HEAD
            *testRunner.fRunnables.append() = new PathOpsThreadedRunnable(&testTightBoundsQuads, 0, 0, 0, 0, &testRunner);
=======
            *testRunner.fRunnables.append() = SkNEW_ARGS(PathOpsThreadedRunnable,
                    (&testTightBoundsQuads, 0, 0, 0, 0, &testRunner));
>>>>>>> miniblink49
        }
    }
    testRunner.render();
}
