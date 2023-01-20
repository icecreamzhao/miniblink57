/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Test.h"

#include "SkMallocPixelRef.h"
#include "SkPixelRef.h"

<<<<<<< HEAD
static void decrement_counter_proc(void* pixels, void* ctx)
{
=======
static void decrement_counter_proc(void* pixels, void* ctx) {
>>>>>>> miniblink49
    int* counter = (int*)ctx;
    *counter -= 1;
}

<<<<<<< HEAD
static void test_dont_leak_install(skiatest::Reporter* reporter)
{
=======
static void test_dont_leak_install(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    bool success;
    int release_counter;
    SkImageInfo info;
    SkBitmap bm;

    info = SkImageInfo::MakeN32Premul(0, 0);
    release_counter = 1;
<<<<<<< HEAD
    success = bm.installPixels(info, nullptr, 0, nullptr, decrement_counter_proc, &release_counter);
=======
    success = bm.installPixels(info, NULL, 0, NULL, decrement_counter_proc, &release_counter);
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, true == success);
    bm.reset();
    REPORTER_ASSERT(reporter, 0 == release_counter);

    info = SkImageInfo::MakeN32Premul(10, 10);
    release_counter = 1;
<<<<<<< HEAD
    success = bm.installPixels(info, nullptr, 0, nullptr, decrement_counter_proc, &release_counter);
=======
    success = bm.installPixels(info, NULL, 0, NULL, decrement_counter_proc, &release_counter);
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, true == success);
    bm.reset();
    REPORTER_ASSERT(reporter, 0 == release_counter);

    info = SkImageInfo::MakeN32Premul(-10, -10);
    release_counter = 1;
<<<<<<< HEAD
    success = bm.installPixels(info, nullptr, 0, nullptr, decrement_counter_proc, &release_counter);
=======
    success = bm.installPixels(info, NULL, 0, NULL, decrement_counter_proc, &release_counter);
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, false == success);
    bm.reset();
    REPORTER_ASSERT(reporter, 0 == release_counter);
}

<<<<<<< HEAD
static void test_install(skiatest::Reporter* reporter)
{
=======
static void test_install(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    bool success;
    SkImageInfo info = SkImageInfo::MakeN32Premul(0, 0);
    SkBitmap bm;
    // make sure we don't assert on an empty install
<<<<<<< HEAD
    success = bm.installPixels(info, nullptr, 0);
=======
    success = bm.installPixels(info, NULL, 0);
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, success);

    // no pixels should be the same as setInfo()
    info = SkImageInfo::MakeN32Premul(10, 10);
<<<<<<< HEAD
    success = bm.installPixels(info, nullptr, 0);
    REPORTER_ASSERT(reporter, success);
=======
    success = bm.installPixels(info, NULL, 0);
    REPORTER_ASSERT(reporter, success);

>>>>>>> miniblink49
}

class TestListener : public SkPixelRef::GenIDChangeListener {
public:
<<<<<<< HEAD
    explicit TestListener(int* ptr)
        : fPtr(ptr)
    {
    }
    void onChange() override { (*fPtr)++; }

=======
    explicit TestListener(int* ptr) : fPtr(ptr) {}
    void onChange() override { (*fPtr)++; }
>>>>>>> miniblink49
private:
    int* fPtr;
};

<<<<<<< HEAD
DEF_TEST(PixelRef_GenIDChange, r)
{
    SkImageInfo info = SkImageInfo::MakeN32Premul(10, 10);

    SkAutoTUnref<SkPixelRef> pixelRef(SkMallocPixelRef::NewAllocate(info, 0, nullptr));

    // Register a listener.
    int count = 0;
    pixelRef->addGenIDChangeListener(new TestListener(&count));
=======
DEF_TEST(PixelRef_GenIDChange, r) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(10, 10);

    SkAutoTUnref<SkPixelRef> pixelRef(SkMallocPixelRef::NewAllocate(info, 0, NULL));

    // Register a listener.
    int count = 0;
    pixelRef->addGenIDChangeListener(SkNEW_ARGS(TestListener, (&count)));
>>>>>>> miniblink49
    REPORTER_ASSERT(r, 0 == count);

    // No one has looked at our pixelRef's generation ID, so invalidating it doesn't make sense.
    // (An SkPixelRef tree falls in the forest but there's nobody around to hear it.  Do we care?)
    pixelRef->notifyPixelsChanged();
    REPORTER_ASSERT(r, 0 == count);

    // Force the generation ID to be calculated.
    REPORTER_ASSERT(r, 0 != pixelRef->getGenerationID());

    // Our listener was dropped in the first call to notifyPixelsChanged().  This is a no-op.
    pixelRef->notifyPixelsChanged();
    REPORTER_ASSERT(r, 0 == count);

    // Force the generation ID to be recalculated, then add a listener.
    REPORTER_ASSERT(r, 0 != pixelRef->getGenerationID());
<<<<<<< HEAD
    pixelRef->addGenIDChangeListener(new TestListener(&count));
    pixelRef->notifyPixelsChanged();
    REPORTER_ASSERT(r, 1 == count);

    // Quick check that nullptr is safe.
    REPORTER_ASSERT(r, 0 != pixelRef->getGenerationID());
    pixelRef->addGenIDChangeListener(nullptr);
=======
    pixelRef->addGenIDChangeListener(SkNEW_ARGS(TestListener, (&count)));
    pixelRef->notifyPixelsChanged();
    REPORTER_ASSERT(r, 1 == count);

    // Quick check that NULL is safe.
    REPORTER_ASSERT(r, 0 != pixelRef->getGenerationID());
    pixelRef->addGenIDChangeListener(NULL);
>>>>>>> miniblink49
    pixelRef->notifyPixelsChanged();

    test_install(r);
    test_dont_leak_install(r);
}
