/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkOnce.h"
<<<<<<< HEAD
#include "SkTaskGroup.h"
#include "Test.h"

static void add_five(int* x)
{
    *x += 5;
}

DEF_TEST(SkOnce_Singlethreaded, r)
{
    int x = 0;

    // No matter how many times we do this, x will be 5.
    SkOnce once;
    once(add_five, &x);
    once(add_five, &x);
    once(add_five, &x);
    once(add_five, &x);
    once(add_five, &x);
=======
#include "SkRunnable.h"
#include "SkTaskGroup.h"
#include "Test.h"

static void add_five(int* x) {
    *x += 5;
}

SK_DECLARE_STATIC_ONCE(st_once);
DEF_TEST(SkOnce_Singlethreaded, r) {
    int x = 0;

    // No matter how many times we do this, x will be 5.
    SkOnce(&st_once, add_five, &x);
    SkOnce(&st_once, add_five, &x);
    SkOnce(&st_once, add_five, &x);
    SkOnce(&st_once, add_five, &x);
    SkOnce(&st_once, add_five, &x);
>>>>>>> miniblink49

    REPORTER_ASSERT(r, 5 == x);
}

<<<<<<< HEAD
DEF_TEST(SkOnce_Multithreaded, r)
{
    int x = 0;

    // Run a bunch of tasks to be the first to add six to x.
    SkOnce once;
    SkTaskGroup().batch(1021, [&](int) {
        once([&] { x += 6; });
=======
SK_DECLARE_STATIC_ONCE(mt_once);
DEF_TEST(SkOnce_Multithreaded, r) {
    int x = 0;
    // Run a bunch of tasks to be the first to add six to x.
    sk_parallel_for(1021, [&](int) {
        void(*add_six)(int*) = [](int* p) { *p += 6; };
        SkOnce(&mt_once, add_six, &x);
>>>>>>> miniblink49
    });

    // Only one should have done the +=.
    REPORTER_ASSERT(r, 6 == x);
}

static int gX = 0;
static void inc_gX() { gX++; }

<<<<<<< HEAD
DEF_TEST(SkOnce_NoArg, r)
{
    SkOnce once;
    once(inc_gX);
    once(inc_gX);
    once(inc_gX);
=======
SK_DECLARE_STATIC_ONCE(noarg_once);
DEF_TEST(SkOnce_NoArg, r) {
    SkOnce(&noarg_once, inc_gX);
    SkOnce(&noarg_once, inc_gX);
    SkOnce(&noarg_once, inc_gX);
>>>>>>> miniblink49
    REPORTER_ASSERT(r, 1 == gX);
}
