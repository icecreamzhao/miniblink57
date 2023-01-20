/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkSharedMutex.h"
#include "SkTaskGroup.h"

#include "Test.h"

<<<<<<< HEAD
DEF_TEST(SkSharedMutexBasic, r)
{
    SkSharedMutex sm;
    sm.acquire();
    sm.assertHeld();
    sm.release();
    sm.acquireShared();
    sm.assertHeldShared();
    sm.releaseShared();
}

DEF_TEST(SkSharedMutexMultiThreaded, r)
{
=======
DEF_TEST(SkSharedMutexBasic, r) {
    SkSharedMutex sm;
    sm.acquire();
    sm.release();
    sm.acquireShared();
    sm.releaseShared();
}

DEF_TEST(SkSharedMutexMultiThreaded, r) {
>>>>>>> miniblink49
    SkSharedMutex sm;
    static const int kSharedSize = 10;
    int shared[kSharedSize];
    int value = 0;
    for (int i = 0; i < kSharedSize; ++i) {
        shared[i] = 0;
    }
<<<<<<< HEAD
    SkTaskGroup().batch(8, [&](int threadIndex) {
        if (threadIndex % 4 != 0) {
            for (int c = 0; c < 100000; ++c) {
                sm.acquireShared();
                sm.assertHeldShared();
=======
    sk_parallel_for(8, [&](int threadIndex) {
        if (threadIndex % 4 != 0) {
            for (int c = 0; c < 100000; ++c) {
                sm.acquireShared();
>>>>>>> miniblink49
                int v = shared[0];
                for (int i = 1; i < kSharedSize; ++i) {
                    REPORTER_ASSERT(r, v == shared[i]);
                }
                sm.releaseShared();
            }
        } else {
            for (int c = 0; c < 100000; ++c) {
                sm.acquire();
<<<<<<< HEAD
                sm.assertHeld();
=======
>>>>>>> miniblink49
                value += 1;
                for (int i = 0; i < kSharedSize; ++i) {
                    shared[i] = value;
                }
                sm.release();
            }
        }
    });
}
