/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkColor.h"
#include "SkXfermode.h"
#include "Test.h"

<<<<<<< HEAD
#define ILLEGAL_MODE ((SkXfermode::Mode)-1)

static void test_asMode(skiatest::Reporter* reporter)
{
    for (int mode = 0; mode <= SkXfermode::kLastMode; mode++) {
        auto xfer = SkXfermode::Make((SkXfermode::Mode)mode);
=======
#define ILLEGAL_MODE    ((SkXfermode::Mode)-1)

static void test_asMode(skiatest::Reporter* reporter) {
    for (int mode = 0; mode <= SkXfermode::kLastMode; mode++) {
        SkXfermode* xfer = SkXfermode::Create((SkXfermode::Mode) mode);
>>>>>>> miniblink49

        SkXfermode::Mode reportedMode = ILLEGAL_MODE;
        REPORTER_ASSERT(reporter, reportedMode != mode);

        // test IsMode
        REPORTER_ASSERT(reporter, SkXfermode::AsMode(xfer, &reportedMode));
        REPORTER_ASSERT(reporter, reportedMode == mode);

        // repeat that test, but with asMode instead
        if (xfer) {
<<<<<<< HEAD
            reportedMode = (SkXfermode::Mode)-1;
            REPORTER_ASSERT(reporter, xfer->asMode(&reportedMode));
            REPORTER_ASSERT(reporter, reportedMode == mode);
=======
            reportedMode = (SkXfermode::Mode) -1;
            REPORTER_ASSERT(reporter, xfer->asMode(&reportedMode));
            REPORTER_ASSERT(reporter, reportedMode == mode);
            xfer->unref();
>>>>>>> miniblink49
        } else {
            REPORTER_ASSERT(reporter, SkXfermode::kSrcOver_Mode == mode);
        }
    }
}

<<<<<<< HEAD
static void test_IsMode(skiatest::Reporter* reporter)
{
    REPORTER_ASSERT(reporter, SkXfermode::IsMode(nullptr, SkXfermode::kSrcOver_Mode));
=======
static void test_IsMode(skiatest::Reporter* reporter) {
    REPORTER_ASSERT(reporter, SkXfermode::IsMode(NULL,
                                                 SkXfermode::kSrcOver_Mode));
>>>>>>> miniblink49

    for (int i = 0; i <= SkXfermode::kLastMode; ++i) {
        SkXfermode::Mode mode = (SkXfermode::Mode)i;

<<<<<<< HEAD
        auto xfer = SkXfermode::Make(mode);
        REPORTER_ASSERT(reporter, SkXfermode::IsMode(xfer, mode));

        if (SkXfermode::kSrcOver_Mode != mode) {
            REPORTER_ASSERT(reporter, !SkXfermode::IsMode(nullptr, mode));
=======
        SkXfermode* xfer = SkXfermode::Create(mode);
        REPORTER_ASSERT(reporter, SkXfermode::IsMode(xfer, mode));
        SkSafeUnref(xfer);

        if (SkXfermode::kSrcOver_Mode != mode) {
            REPORTER_ASSERT(reporter, !SkXfermode::IsMode(NULL, mode));
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
DEF_TEST(Xfermode, reporter)
{
=======
DEF_TEST(Xfermode, reporter) {
>>>>>>> miniblink49
    test_asMode(reporter);
    test_IsMode(reporter);
}
