/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkPath.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "Test.h"

<<<<<<< HEAD
static void Union(SkRegion* rgn, const SkIRect& rect)
{
    rgn->op(rect, SkRegion::kUnion_Op);
}

#define TEST_NO_INTERSECT(rgn, rect) REPORTER_ASSERT(reporter, !rgn.intersects(rect))
#define TEST_INTERSECT(rgn, rect) REPORTER_ASSERT(reporter, rgn.intersects(rect))
#define TEST_NO_CONTAINS(rgn, rect) REPORTER_ASSERT(reporter, !rgn.contains(rect))

// inspired by http://code.google.com/p/skia/issues/detail?id=958
//
static void test_fromchrome(skiatest::Reporter* reporter)
{
=======
static void Union(SkRegion* rgn, const SkIRect& rect) {
    rgn->op(rect, SkRegion::kUnion_Op);
}

#define TEST_NO_INTERSECT(rgn, rect)    REPORTER_ASSERT(reporter, !rgn.intersects(rect))
#define TEST_INTERSECT(rgn, rect)       REPORTER_ASSERT(reporter, rgn.intersects(rect))
#define TEST_NO_CONTAINS(rgn, rect)     REPORTER_ASSERT(reporter, !rgn.contains(rect))

// inspired by http://code.google.com/p/skia/issues/detail?id=958
//
static void test_fromchrome(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    SkRegion r;
    Union(&r, SkIRect::MakeXYWH(0, 0, 1, 1));
    TEST_NO_INTERSECT(r, SkIRect::MakeXYWH(0, 0, 0, 0));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(0, 0, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(-1, 0, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(-1, -1, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(0, -1, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(-1, -1, 3, 3));

    Union(&r, SkIRect::MakeXYWH(0, 0, 3, 3));
    Union(&r, SkIRect::MakeXYWH(10, 0, 3, 3));
    Union(&r, SkIRect::MakeXYWH(0, 10, 13, 3));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(-1, -1, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(2, -1, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(2, 2, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(-1, 2, 2, 2));

    TEST_INTERSECT(r, SkIRect::MakeXYWH(9, -1, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(12, -1, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(12, 2, 2, 2));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(9, 2, 2, 2));

    TEST_INTERSECT(r, SkIRect::MakeXYWH(0, -1, 13, 5));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(1, -1, 11, 5));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(2, -1, 9, 5));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(2, -1, 8, 5));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(3, -1, 8, 5));

    TEST_INTERSECT(r, SkIRect::MakeXYWH(0, 1, 13, 1));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(1, 1, 11, 1));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(2, 1, 9, 1));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(2, 1, 8, 1));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(3, 1, 8, 1));

    TEST_INTERSECT(r, SkIRect::MakeXYWH(0, 0, 13, 13));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(0, 1, 13, 11));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(0, 2, 13, 9));
    TEST_INTERSECT(r, SkIRect::MakeXYWH(0, 2, 13, 8));

<<<<<<< HEAD
=======

>>>>>>> miniblink49
    // These test SkRegion::contains(Rect) and SkRegion::contains(Region)

    SkRegion container;
    Union(&container, SkIRect::MakeXYWH(0, 0, 40, 20));
    Union(&container, SkIRect::MakeXYWH(30, 20, 10, 20));
    TEST_NO_CONTAINS(container, SkIRect::MakeXYWH(0, 0, 10, 39));
    TEST_NO_CONTAINS(container, SkIRect::MakeXYWH(29, 0, 10, 39));

    {
        SkRegion rgn;
        Union(&rgn, SkIRect::MakeXYWH(0, 0, 10, 10));
        Union(&rgn, SkIRect::MakeLTRB(5, 10, 20, 20));
        TEST_INTERSECT(rgn, SkIRect::MakeXYWH(15, 0, 5, 11));
    }
}

<<<<<<< HEAD
static void test_empties(skiatest::Reporter* reporter)
{
=======
static void test_empties(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    SkRegion valid(SkIRect::MakeWH(10, 10));
    SkRegion empty, empty2;

    REPORTER_ASSERT(reporter, empty.isEmpty());
    REPORTER_ASSERT(reporter, !valid.isEmpty());

    // test intersects
    REPORTER_ASSERT(reporter, !empty.intersects(empty2));
    REPORTER_ASSERT(reporter, !valid.intersects(empty));

    // test contains
    REPORTER_ASSERT(reporter, !empty.contains(empty2));
    REPORTER_ASSERT(reporter, !valid.contains(empty));
    REPORTER_ASSERT(reporter, !empty.contains(valid));

    SkPath emptyPath;
    emptyPath.moveTo(1, 5);
    emptyPath.close();
    SkRegion openClip;
    openClip.setRect(-16000, -16000, 16000, 16000);
<<<<<<< HEAD
    empty.setPath(emptyPath, openClip); // should not assert
=======
    empty.setPath(emptyPath, openClip);  // should not assert
>>>>>>> miniblink49
}

enum {
    W = 256,
    H = 256
};

<<<<<<< HEAD
static SkIRect randRect(SkRandom& rand)
{
=======
static SkIRect randRect(SkRandom& rand) {
>>>>>>> miniblink49
    int x = rand.nextU() % W;
    int y = rand.nextU() % H;
    int w = rand.nextU() % W;
    int h = rand.nextU() % H;
    return SkIRect::MakeXYWH(x, y, w >> 1, h >> 1);
}

<<<<<<< HEAD
static void randRgn(SkRandom& rand, SkRegion* rgn, int n)
{
=======
static void randRgn(SkRandom& rand, SkRegion* rgn, int n) {
>>>>>>> miniblink49
    rgn->setEmpty();
    for (int i = 0; i < n; ++i) {
        rgn->op(randRect(rand), SkRegion::kUnion_Op);
    }
}

<<<<<<< HEAD
static bool slow_contains(const SkRegion& outer, const SkRegion& inner)
{
=======
static bool slow_contains(const SkRegion& outer, const SkRegion& inner) {
>>>>>>> miniblink49
    SkRegion tmp;
    tmp.op(outer, inner, SkRegion::kUnion_Op);
    return outer == tmp;
}

<<<<<<< HEAD
static bool slow_contains(const SkRegion& outer, const SkIRect& r)
{
=======
static bool slow_contains(const SkRegion& outer, const SkIRect& r) {
>>>>>>> miniblink49
    SkRegion tmp;
    tmp.op(outer, SkRegion(r), SkRegion::kUnion_Op);
    return outer == tmp;
}

<<<<<<< HEAD
static bool slow_intersects(const SkRegion& outer, const SkRegion& inner)
{
=======
static bool slow_intersects(const SkRegion& outer, const SkRegion& inner) {
>>>>>>> miniblink49
    SkRegion tmp;
    return tmp.op(outer, inner, SkRegion::kIntersect_Op);
}

<<<<<<< HEAD
static void test_contains_iter(skiatest::Reporter* reporter, const SkRegion& rgn)
{
=======
static void test_contains_iter(skiatest::Reporter* reporter, const SkRegion& rgn) {
>>>>>>> miniblink49
    SkRegion::Iterator iter(rgn);
    while (!iter.done()) {
        SkIRect r = iter.rect();
        REPORTER_ASSERT(reporter, rgn.contains(r));
        r.inset(-1, -1);
        REPORTER_ASSERT(reporter, !rgn.contains(r));
        iter.next();
    }
}

static void contains_proc(skiatest::Reporter* reporter,
<<<<<<< HEAD
    const SkRegion& a, const SkRegion& b)
{
=======
                          const SkRegion& a, const SkRegion& b) {
>>>>>>> miniblink49
    // test rgn
    bool c0 = a.contains(b);
    bool c1 = slow_contains(a, b);
    REPORTER_ASSERT(reporter, c0 == c1);

    // test rect
    SkIRect r = a.getBounds();
<<<<<<< HEAD
    r.inset(r.width() / 4, r.height() / 4);
=======
    r.inset(r.width()/4, r.height()/4);
>>>>>>> miniblink49
    c0 = a.contains(r);
    c1 = slow_contains(a, r);
    REPORTER_ASSERT(reporter, c0 == c1);

    test_contains_iter(reporter, a);
    test_contains_iter(reporter, b);
}

<<<<<<< HEAD
static void test_intersects_iter(skiatest::Reporter* reporter, const SkRegion& rgn)
{
=======
static void test_intersects_iter(skiatest::Reporter* reporter, const SkRegion& rgn) {
>>>>>>> miniblink49
    SkRegion::Iterator iter(rgn);
    while (!iter.done()) {
        SkIRect r = iter.rect();
        REPORTER_ASSERT(reporter, rgn.intersects(r));
        r.inset(-1, -1);
        REPORTER_ASSERT(reporter, rgn.intersects(r));
        iter.next();
    }
}

static void intersects_proc(skiatest::Reporter* reporter,
<<<<<<< HEAD
    const SkRegion& a, const SkRegion& b)
{
=======
                          const SkRegion& a, const SkRegion& b) {
>>>>>>> miniblink49
    bool c0 = a.intersects(b);
    bool c1 = slow_intersects(a, b);
    REPORTER_ASSERT(reporter, c0 == c1);

    test_intersects_iter(reporter, a);
    test_intersects_iter(reporter, b);
}

static void test_proc(skiatest::Reporter* reporter,
<<<<<<< HEAD
    void (*proc)(skiatest::Reporter*,
        const SkRegion& a, const SkRegion&))
{
=======
                      void (*proc)(skiatest::Reporter*,
                                   const SkRegion& a, const SkRegion&)) {
>>>>>>> miniblink49
    SkRandom rand;
    for (int i = 0; i < 10000; ++i) {
        SkRegion outer;
        randRgn(rand, &outer, 8);
        SkRegion inner;
        randRgn(rand, &inner, 2);
        proc(reporter, outer, inner);
    }
}

<<<<<<< HEAD
static void rand_rect(SkIRect* rect, SkRandom& rand)
{
    int bits = 6;
    int shift = 32 - bits;
    rect->set(rand.nextU() >> shift, rand.nextU() >> shift,
        rand.nextU() >> shift, rand.nextU() >> shift);
    rect->sort();
}

static bool test_rects(const SkIRect rect[], int count)
{
=======
static void rand_rect(SkIRect* rect, SkRandom& rand) {
    int bits = 6;
    int shift = 32 - bits;
    rect->set(rand.nextU() >> shift, rand.nextU() >> shift,
              rand.nextU() >> shift, rand.nextU() >> shift);
    rect->sort();
}

static bool test_rects(const SkIRect rect[], int count) {
>>>>>>> miniblink49
    SkRegion rgn0, rgn1;

    for (int i = 0; i < count; i++) {
        rgn0.op(rect[i], SkRegion::kUnion_Op);
    }
    rgn1.setRects(rect, count);

    if (rgn0 != rgn1) {
        SkDebugf("\n");
        for (int i = 0; i < count; i++) {
            SkDebugf(" { %d, %d, %d, %d },\n",
<<<<<<< HEAD
                rect[i].fLeft, rect[i].fTop,
                rect[i].fRight, rect[i].fBottom);
=======
                     rect[i].fLeft, rect[i].fTop,
                     rect[i].fRight, rect[i].fBottom);
>>>>>>> miniblink49
        }
        SkDebugf("\n");
        return false;
    }
    return true;
}

<<<<<<< HEAD
DEF_TEST(Region, reporter)
{
=======
DEF_TEST(Region, reporter) {
>>>>>>> miniblink49
    const SkIRect r2[] = {
        { 0, 0, 1, 1 },
        { 2, 2, 3, 3 },
    };
    REPORTER_ASSERT(reporter, test_rects(r2, SK_ARRAY_COUNT(r2)));

    const SkIRect rects[] = {
        { 0, 0, 1, 2 },
        { 2, 1, 3, 3 },
        { 4, 0, 5, 1 },
        { 6, 0, 7, 4 },
    };
    REPORTER_ASSERT(reporter, test_rects(rects, SK_ARRAY_COUNT(rects)));

    SkRandom rand;
    for (int i = 0; i < 1000; i++) {
        SkRegion rgn0, rgn1;

        const int N = 8;
        SkIRect rect[N];
        for (int j = 0; j < N; j++) {
            rand_rect(&rect[j], rand);
        }
        REPORTER_ASSERT(reporter, test_rects(rect, N));
    }

    test_proc(reporter, contains_proc);
    test_proc(reporter, intersects_proc);
    test_empties(reporter);
    test_fromchrome(reporter);
}

// Test that writeToMemory reports the same number of bytes whether there was a
// buffer to write to or not.
<<<<<<< HEAD
static void test_write(const SkRegion& region, skiatest::Reporter* r)
{
    const size_t bytesNeeded = region.writeToMemory(nullptr);
=======
static void test_write(const SkRegion& region, skiatest::Reporter* r) {
    const size_t bytesNeeded = region.writeToMemory(NULL);
>>>>>>> miniblink49
    SkAutoMalloc storage(bytesNeeded);
    const size_t bytesWritten = region.writeToMemory(storage.get());
    REPORTER_ASSERT(r, bytesWritten == bytesNeeded);
}

<<<<<<< HEAD
DEF_TEST(Region_writeToMemory, r)
{
=======
DEF_TEST(Region_writeToMemory, r) {
>>>>>>> miniblink49
    // Test an empty region.
    SkRegion region;
    REPORTER_ASSERT(r, region.isEmpty());
    test_write(region, r);

    // Test a rectangular region
    bool nonEmpty = region.setRect(0, 0, 50, 50);
    REPORTER_ASSERT(r, nonEmpty);
    REPORTER_ASSERT(r, region.isRect());
    test_write(region, r);

    // Test a complex region
    nonEmpty = region.op(50, 50, 100, 100, SkRegion::kUnion_Op);
    REPORTER_ASSERT(r, nonEmpty);
    REPORTER_ASSERT(r, region.isComplex());
    test_write(region, r);
}
