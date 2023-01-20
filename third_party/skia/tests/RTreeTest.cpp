/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkRTree.h"
#include "SkRandom.h"
#include "Test.h"

static const int NUM_RECTS = 200;
static const size_t NUM_ITERATIONS = 100;
static const size_t NUM_QUERIES = 50;

<<<<<<< HEAD
static SkRect random_rect(SkRandom& rand)
{
    SkRect rect = { 0, 0, 0, 0 };
    while (rect.isEmpty()) {
        rect.fLeft = rand.nextRangeF(0, 1000);
        rect.fRight = rand.nextRangeF(0, 1000);
        rect.fTop = rand.nextRangeF(0, 1000);
=======
static SkRect random_rect(SkRandom& rand) {
    SkRect rect = {0,0,0,0};
    while (rect.isEmpty()) {
        rect.fLeft   = rand.nextRangeF(0, 1000);
        rect.fRight  = rand.nextRangeF(0, 1000);
        rect.fTop    = rand.nextRangeF(0, 1000);
>>>>>>> miniblink49
        rect.fBottom = rand.nextRangeF(0, 1000);
        rect.sort();
    }
    return rect;
}

<<<<<<< HEAD
static bool verify_query(SkRect query, SkRect rects[], SkTDArray<int>& found)
{
    SkTDArray<int> expected;
=======
static bool verify_query(SkRect query, SkRect rects[], SkTDArray<unsigned>& found) {
    SkTDArray<unsigned> expected;
>>>>>>> miniblink49
    // manually intersect with every rectangle
    for (int i = 0; i < NUM_RECTS; ++i) {
        if (SkRect::Intersects(query, rects[i])) {
            expected.push(i);
        }
    }

    if (expected.count() != found.count()) {
        return false;
    }
    if (0 == expected.count()) {
        return true;
    }
    return found == expected;
}

static void run_queries(skiatest::Reporter* reporter, SkRandom& rand, SkRect rects[],
<<<<<<< HEAD
    const SkRTree& tree)
{
    for (size_t i = 0; i < NUM_QUERIES; ++i) {
        SkTDArray<int> hits;
=======
                        const SkRTree& tree) {
    for (size_t i = 0; i < NUM_QUERIES; ++i) {
        SkTDArray<unsigned> hits;
>>>>>>> miniblink49
        SkRect query = random_rect(rand);
        tree.search(query, &hits);
        REPORTER_ASSERT(reporter, verify_query(query, rects, hits));
    }
}

<<<<<<< HEAD
DEF_TEST(RTree, reporter)
{
=======
DEF_TEST(RTree, reporter) {
>>>>>>> miniblink49
    int expectedDepthMin = -1;
    int tmp = NUM_RECTS;
    while (tmp > 0) {
        tmp -= static_cast<int>(pow(static_cast<double>(SkRTree::kMaxChildren),
<<<<<<< HEAD
            static_cast<double>(expectedDepthMin + 1)));
=======
                                    static_cast<double>(expectedDepthMin + 1)));
>>>>>>> miniblink49
        ++expectedDepthMin;
    }

    int expectedDepthMax = -1;
    tmp = NUM_RECTS;
    while (tmp > 0) {
        tmp -= static_cast<int>(pow(static_cast<double>(SkRTree::kMinChildren),
<<<<<<< HEAD
            static_cast<double>(expectedDepthMax + 1)));
=======
                                    static_cast<double>(expectedDepthMax + 1)));
>>>>>>> miniblink49
        ++expectedDepthMax;
    }

    SkRandom rand;
    SkAutoTMalloc<SkRect> rects(NUM_RECTS);
    for (size_t i = 0; i < NUM_ITERATIONS; ++i) {
        SkRTree rtree;
        REPORTER_ASSERT(reporter, 0 == rtree.getCount());

        for (int j = 0; j < NUM_RECTS; j++) {
            rects[j] = random_rect(rand);
        }

        rtree.insert(rects.get(), NUM_RECTS);
<<<<<<< HEAD
        SkASSERT(rects); // SkRTree doesn't take ownership of rects.

        run_queries(reporter, rand, rects, rtree);
        REPORTER_ASSERT(reporter, NUM_RECTS == rtree.getCount());
        REPORTER_ASSERT(reporter, expectedDepthMin <= rtree.getDepth() && expectedDepthMax >= rtree.getDepth());
=======
        SkASSERT(rects);  // SkRTree doesn't take ownership of rects.

        run_queries(reporter, rand, rects, rtree);
        REPORTER_ASSERT(reporter, NUM_RECTS == rtree.getCount());
        REPORTER_ASSERT(reporter, expectedDepthMin <= rtree.getDepth() &&
                                  expectedDepthMax >= rtree.getDepth());
>>>>>>> miniblink49
    }
}
