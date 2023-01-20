/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkAutoPixmapStorage.h"
=======
>>>>>>> miniblink49
#include "SkDeviceLooper.h"
#include "SkRasterClip.h"
#include "Test.h"

<<<<<<< HEAD
static void make_pm(SkAutoPixmapStorage* pixmap, int w, int h)
{
    pixmap->alloc(SkImageInfo::Make(w, h, kAlpha_8_SkColorType, kPremul_SkAlphaType));
}

static bool equal(const SkRasterClip& a, const SkRasterClip& b)
{
=======
static void make_pm(SkAutoPixmapStorage* pixmap, int w, int h) {
    pixmap->alloc(SkImageInfo::Make(w, h, kAlpha_8_SkColorType, kPremul_SkAlphaType));
}

static bool equal(const SkRasterClip& a, const SkRasterClip& b) {
>>>>>>> miniblink49
    if (a.isBW()) {
        return b.isBW() && a.bwRgn() == b.bwRgn();
    } else {
        return a.isAA() && a.aaRgn() == b.aaRgn();
    }
}

static const struct {
    SkISize fDevSize;
    SkIRect fRCBounds;
    SkIRect fRect;
} gRec[] = {
    { { 4000, 10 }, { 0, 0, 4000, 10 }, { 0, 0, 4000, 4000 } },
    { { 10, 4000 }, { 0, 0, 10, 4000 }, { 0, 0, 4000, 4000 } },
    // very large devce, small rect
    { { 32000, 10 }, { 0, 0, 32000, 10 }, { 0, 0, 4000, 4000 } },
    { { 10, 32000 }, { 0, 0, 10, 32000 }, { 0, 0, 4000, 4000 } },
    // very large device, small clip
    { { 32000, 10 }, { 0, 0, 4000, 10 }, { 0, 0, 32000, 32000 } },
    { { 10, 32000 }, { 0, 0, 10, 4000 }, { 0, 0, 32000, 32000 } },
};

<<<<<<< HEAD
static void test_simple(skiatest::Reporter* reporter)
{
=======
static void test_simple(skiatest::Reporter* reporter) {
>>>>>>> miniblink49

    for (size_t i = 0; i < SK_ARRAY_COUNT(gRec); ++i) {
        SkAutoPixmapStorage pmap;
        make_pm(&pmap, gRec[i].fDevSize.width(), gRec[i].fDevSize.height());

        SkRasterClip rc(gRec[i].fRCBounds);

        for (int aa = 0; aa <= 1; ++aa) {
            SkDeviceLooper looper(pmap, rc, gRec[i].fRect, SkToBool(aa));

            bool valid = looper.next();
            REPORTER_ASSERT(reporter, valid);
            if (valid) {
                REPORTER_ASSERT(reporter, looper.getPixmap().width() == pmap.width());
                REPORTER_ASSERT(reporter, looper.getPixmap().height() == pmap.height());
                REPORTER_ASSERT(reporter, equal(looper.getRC(), rc));

                REPORTER_ASSERT(reporter, !looper.next());
            }
        }
        // test that a rect that doesn't intersect returns no loops
        {
            SkIRect r = rc.getBounds();
            r.offset(r.width(), 0);
            SkDeviceLooper looper(pmap, rc, r, false);
            REPORTER_ASSERT(reporter, !looper.next());
        }
    }
}

// mask-bits are interpreted as the areas where the clip is visible
//  [ 0x01  0x02 ]
//  [ 0x04  0x08 ]
//
<<<<<<< HEAD
static void make_rgn(SkRegion* rgn, int w, int h, unsigned mask)
{
=======
static void make_rgn(SkRegion* rgn, int w, int h, unsigned mask) {
>>>>>>> miniblink49
    SkASSERT(SkAlign2(w));
    SkASSERT(SkAlign2(h));
    w >>= 1;
    h >>= 1;
    const SkIRect baseR = SkIRect::MakeWH(w, h);

    int bit = 1;
    for (int y = 0; y <= 1; ++y) {
        for (int x = 0; x <= 1; ++x) {
            if (mask & bit) {
                SkIRect r = baseR;
                r.offset(x * w, y * h);
                rgn->op(r, SkRegion::kUnion_Op);
            }
            bit <<= 1;
        }
    }
}

<<<<<<< HEAD
static void test_complex(skiatest::Reporter* reporter)
{
=======
static void test_complex(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    // choose size values that will result in 4 quadrants, given fAA setting
    const int BW_SIZE = 17 * 1000;
    const int AA_SIZE = 7 * 1000;

    struct {
        SkISize fSize;
<<<<<<< HEAD
        bool fAA;
    } const gRec[] = {
        { { BW_SIZE, BW_SIZE }, false },
        { { AA_SIZE, AA_SIZE }, true },
=======
        bool    fAA;
    } const gRec[] = {
        { { BW_SIZE, BW_SIZE }, false },
        { {  AA_SIZE, AA_SIZE }, true },
>>>>>>> miniblink49
    };

    for (size_t i = 0; i < SK_ARRAY_COUNT(gRec); ++i) {
        const int w = gRec[i].fSize.width();
        const int h = gRec[i].fSize.height();

        SkAutoPixmapStorage pmap;
        make_pm(&pmap, w, h);

        const SkIRect rect = SkIRect::MakeWH(w, h);

        // mask-bits are interpreted as the areas where the clip is visible
        //  [ 0x01  0x02 ]
        //  [ 0x04  0x08 ]
        //
        for (int mask = 0; mask <= 15; ++mask) {
            SkRegion rgn;
            make_rgn(&rgn, w, h, mask);

            SkRasterClip rc;
            rc.op(rgn, SkRegion::kReplace_Op);

            SkDeviceLooper looper(pmap, rc, rect, gRec[i].fAA);
            while (looper.next()) {
                REPORTER_ASSERT(reporter, !looper.getRC().isEmpty());
            }
        }
    }
}

<<<<<<< HEAD
DEF_TEST(DeviceLooper, reporter)
{
=======
DEF_TEST(DeviceLooper, reporter) {
>>>>>>> miniblink49
    test_simple(reporter);
    test_complex(reporter);
}
