/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "PathOpsQuadIntersectionTestData.h"
#include "SkIntersections.h"
#include "SkPathOpsRect.h"
#include "SkReduceOrder.h"
#include "Test.h"

static const SkDQuad testSet[] = {
<<<<<<< HEAD
    { { { 1, 1 }, { 2, 2 }, { 1, 1.000003 } } },
    { { { 1, 0 }, { 2, 6 }, { 3, 0 } } }
=======
    {{{1, 1}, {2, 2}, {1, 1.000003}}},
    {{{1, 0}, {2, 6}, {3, 0}}}
>>>>>>> miniblink49
};

static const size_t testSetCount = SK_ARRAY_COUNT(testSet);

<<<<<<< HEAD
static void oneOffTest(skiatest::Reporter* reporter)
{
    for (size_t index = 0; index < testSetCount; ++index) {
        const SkDQuad& quad = testSet[index];
        SkReduceOrder reducer;
        SkDEBUGCODE(int result =) reducer.reduce(quad);
=======
static void oneOffTest(skiatest::Reporter* reporter) {
    for (size_t index = 0; index < testSetCount; ++index) {
        const SkDQuad& quad = testSet[index];
        SkReduceOrder reducer;
        SkDEBUGCODE(int result = ) reducer.reduce(quad);
>>>>>>> miniblink49
        SkASSERT(result == 3);
    }
}

<<<<<<< HEAD
static void standardTestCases(skiatest::Reporter* reporter)
{
=======
static void standardTestCases(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    size_t index;
    SkReduceOrder reducer;
    int order;
    enum {
        RunAll,
        RunQuadraticLines,
        RunQuadraticModLines,
        RunNone
<<<<<<< HEAD
    } run
        = RunAll;
=======
    } run = RunAll;
>>>>>>> miniblink49
    int firstTestIndex = 0;
#if 0
    run = RunQuadraticLines;
    firstTestIndex = 1;
#endif
<<<<<<< HEAD
    int firstQuadraticLineTest = run == RunAll ? 0 : run == RunQuadraticLines ? firstTestIndex : SK_MaxS32;
    int firstQuadraticModLineTest = run == RunAll ? 0 : run == RunQuadraticModLines ? firstTestIndex : SK_MaxS32;
=======
    int firstQuadraticLineTest = run == RunAll ? 0 : run == RunQuadraticLines ? firstTestIndex
            : SK_MaxS32;
    int firstQuadraticModLineTest = run == RunAll ? 0 : run == RunQuadraticModLines ? firstTestIndex
            : SK_MaxS32;
>>>>>>> miniblink49

    for (index = firstQuadraticLineTest; index < quadraticLines_count; ++index) {
        const SkDQuad& quad = quadraticLines[index];
        order = reducer.reduce(quad);
        if (order != 2) {
<<<<<<< HEAD
            SkDebugf("[%d] line quad order=%d\n", (int)index, order);
=======
            SkDebugf("[%d] line quad order=%d\n", (int) index, order);
>>>>>>> miniblink49
        }
    }
    for (index = firstQuadraticModLineTest; index < quadraticModEpsilonLines_count; ++index) {
        const SkDQuad& quad = quadraticModEpsilonLines[index];
        order = reducer.reduce(quad);
<<<<<<< HEAD
        if (order != 2 && order != 3) { // FIXME: data probably is not good
            SkDebugf("[%d] line mod quad order=%d\n", (int)index, order);
=======
        if (order != 2 && order != 3) {  // FIXME: data probably is not good
            SkDebugf("[%d] line mod quad order=%d\n", (int) index, order);
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
DEF_TEST(PathOpsReduceOrderQuad, reporter)
{
=======
DEF_TEST(PathOpsReduceOrderQuad, reporter) {
>>>>>>> miniblink49
    oneOffTest(reporter);
    standardTestCases(reporter);
}
