/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkDeque.h"
#include "Test.h"

<<<<<<< HEAD
static void assert_count(skiatest::Reporter* reporter, const SkDeque& deq, int count)
{
=======
static void assert_count(skiatest::Reporter* reporter, const SkDeque& deq, int count) {
>>>>>>> miniblink49
    if (0 == count) {
        REPORTER_ASSERT(reporter, deq.empty());
        REPORTER_ASSERT(reporter, 0 == deq.count());
        REPORTER_ASSERT(reporter, sizeof(int) == deq.elemSize());
<<<<<<< HEAD
        REPORTER_ASSERT(reporter, nullptr == deq.front());
        REPORTER_ASSERT(reporter, nullptr == deq.back());
=======
        REPORTER_ASSERT(reporter, NULL == deq.front());
        REPORTER_ASSERT(reporter, NULL == deq.back());
>>>>>>> miniblink49
    } else {
        REPORTER_ASSERT(reporter, !deq.empty());
        REPORTER_ASSERT(reporter, count == deq.count());
        REPORTER_ASSERT(reporter, sizeof(int) == deq.elemSize());
        REPORTER_ASSERT(reporter, deq.front());
        REPORTER_ASSERT(reporter, deq.back());
        if (1 == count) {
            REPORTER_ASSERT(reporter, deq.back() == deq.front());
        } else {
            REPORTER_ASSERT(reporter, deq.back() != deq.front());
        }
    }
}

static void assert_iter(skiatest::Reporter* reporter, const SkDeque& deq,
<<<<<<< HEAD
    int max, int min)
{
=======
                        int max, int min) {
>>>>>>> miniblink49
    // test forward iteration
    SkDeque::Iter iter(deq, SkDeque::Iter::kFront_IterStart);
    void* ptr;

    int value = max;
    while ((ptr = iter.next())) {
        REPORTER_ASSERT(reporter, value == *(int*)ptr);
        value -= 1;
    }
<<<<<<< HEAD
    REPORTER_ASSERT(reporter, value + 1 == min);
=======
    REPORTER_ASSERT(reporter, value+1 == min);
>>>>>>> miniblink49

    // test reverse iteration
    iter.reset(deq, SkDeque::Iter::kBack_IterStart);

    value = min;
    while ((ptr = iter.prev())) {
        REPORTER_ASSERT(reporter, value == *(int*)ptr);
        value += 1;
    }
<<<<<<< HEAD
    REPORTER_ASSERT(reporter, value - 1 == max);
=======
    REPORTER_ASSERT(reporter, value-1 == max);
>>>>>>> miniblink49

    // test mixed iteration
    iter.reset(deq, SkDeque::Iter::kFront_IterStart);

    value = max;
    // forward iteration half-way
<<<<<<< HEAD
    for (int i = 0; i < deq.count() / 2 && (ptr = iter.next()); i++) {
=======
    for (int i = 0; i < deq.count()/2 && (ptr = iter.next()); i++) {
>>>>>>> miniblink49
        REPORTER_ASSERT(reporter, value == *(int*)ptr);
        value -= 1;
    }
    // then back down w/ reverse iteration
    while ((ptr = iter.prev())) {
        REPORTER_ASSERT(reporter, value == *(int*)ptr);
        value += 1;
    }
<<<<<<< HEAD
    REPORTER_ASSERT(reporter, value - 1 == max);
=======
    REPORTER_ASSERT(reporter, value-1 == max);
>>>>>>> miniblink49
}

// This helper is intended to only give the unit test access to SkDeque's
// private numBlocksAllocated method
class DequeUnitTestHelper {
public:
    int fNumBlocksAllocated;

<<<<<<< HEAD
    DequeUnitTestHelper(const SkDeque& deq)
    {
=======
    DequeUnitTestHelper(const SkDeque& deq) {
>>>>>>> miniblink49
        fNumBlocksAllocated = deq.numBlocksAllocated();
    }
};

static void assert_blocks(skiatest::Reporter* reporter,
<<<<<<< HEAD
    const SkDeque& deq,
    int allocCount)
{
=======
                          const SkDeque& deq,
                          int allocCount) {
>>>>>>> miniblink49
    DequeUnitTestHelper helper(deq);

    if (0 == deq.count()) {
        REPORTER_ASSERT(reporter, 1 == helper.fNumBlocksAllocated);
    } else {
        int expected = (deq.count() + allocCount - 1) / allocCount;
        // A block isn't freed in the deque when it first becomes empty so
        // sometimes an extra block lingers around
        REPORTER_ASSERT(reporter,
<<<<<<< HEAD
            expected == helper.fNumBlocksAllocated || expected + 1 == helper.fNumBlocksAllocated);
    }
}

static void TestSub(skiatest::Reporter* reporter, int allocCount)
{
=======
            expected == helper.fNumBlocksAllocated ||
            expected+1 == helper.fNumBlocksAllocated);
    }
}

static void TestSub(skiatest::Reporter* reporter, int allocCount) {
>>>>>>> miniblink49
    SkDeque deq(sizeof(int), allocCount);
    int i;

    // test pushing on the front

    assert_count(reporter, deq, 0);
    for (i = 1; i <= 10; i++) {
        *(int*)deq.push_front() = i;
    }
    assert_count(reporter, deq, 10);
    assert_iter(reporter, deq, 10, 1);
    assert_blocks(reporter, deq, allocCount);

    for (i = 0; i < 5; i++) {
        deq.pop_front();
    }
    assert_count(reporter, deq, 5);
    assert_iter(reporter, deq, 5, 1);
    assert_blocks(reporter, deq, allocCount);

    for (i = 0; i < 5; i++) {
        deq.pop_front();
    }
    assert_count(reporter, deq, 0);
    assert_blocks(reporter, deq, allocCount);

    // now test pushing on the back

    for (i = 10; i >= 1; --i) {
        *(int*)deq.push_back() = i;
    }
    assert_count(reporter, deq, 10);
    assert_iter(reporter, deq, 10, 1);
    assert_blocks(reporter, deq, allocCount);

    for (i = 0; i < 5; i++) {
        deq.pop_back();
    }
    assert_count(reporter, deq, 5);
    assert_iter(reporter, deq, 10, 6);
    assert_blocks(reporter, deq, allocCount);

    for (i = 0; i < 5; i++) {
        deq.pop_back();
    }
    assert_count(reporter, deq, 0);
    assert_blocks(reporter, deq, allocCount);

    // now test pushing/popping on both ends

    *(int*)deq.push_front() = 5;
    *(int*)deq.push_back() = 4;
    *(int*)deq.push_front() = 6;
    *(int*)deq.push_back() = 3;
    *(int*)deq.push_front() = 7;
    *(int*)deq.push_back() = 2;
    *(int*)deq.push_front() = 8;
    *(int*)deq.push_back() = 1;
    assert_count(reporter, deq, 8);
    assert_iter(reporter, deq, 8, 1);
    assert_blocks(reporter, deq, allocCount);
}

<<<<<<< HEAD
DEF_TEST(Deque, reporter)
{
=======
DEF_TEST(Deque, reporter) {
>>>>>>> miniblink49
    // test it once with the default allocation count
    TestSub(reporter, 1);
    // test it again with a generous allocation count
    TestSub(reporter, 10);
}
