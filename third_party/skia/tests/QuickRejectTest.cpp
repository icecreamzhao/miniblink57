/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkCanvas.h"
#include "SkDrawLooper.h"
#include "SkTypes.h"
#include "Test.h"

/*
 *  Subclass of looper that just draws once, with an offset in X.
 */
class TestLooper : public SkDrawLooper {
public:
<<<<<<< HEAD
    SkDrawLooper::Context* createContext(SkCanvas*, void* storage) const override
    {
        return new (storage) TestDrawLooperContext;
=======

    SkDrawLooper::Context* createContext(SkCanvas*, void* storage) const override {
        return SkNEW_PLACEMENT(storage, TestDrawLooperContext);
>>>>>>> miniblink49
    }

    size_t contextSize() const override { return sizeof(TestDrawLooperContext); }

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
    void toString(SkString* str) const override
    {
=======
    void toString(SkString* str) const override {
>>>>>>> miniblink49
        str->append("TestLooper:");
    }
#endif

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(TestLooper);

private:
    class TestDrawLooperContext : public SkDrawLooper::Context {
    public:
<<<<<<< HEAD
        TestDrawLooperContext()
            : fOnce(true)
        {
        }
        virtual ~TestDrawLooperContext() { }

        bool next(SkCanvas* canvas, SkPaint*) override
        {
=======
        TestDrawLooperContext() : fOnce(true) {}
        virtual ~TestDrawLooperContext() {}

        bool next(SkCanvas* canvas, SkPaint*) override {
>>>>>>> miniblink49
            if (fOnce) {
                fOnce = false;
                canvas->translate(SkIntToScalar(10), 0);
                return true;
            }
            return false;
        }
<<<<<<< HEAD

=======
>>>>>>> miniblink49
    private:
        bool fOnce;
    };
};

<<<<<<< HEAD
sk_sp<SkFlattenable> TestLooper::CreateProc(SkReadBuffer&) { return sk_make_sp<TestLooper>(); }

static void test_drawBitmap(skiatest::Reporter* reporter)
{
=======
SkFlattenable* TestLooper::CreateProc(SkReadBuffer&) { return SkNEW(TestLooper); }

static void test_drawBitmap(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    SkBitmap src;
    src.allocN32Pixels(10, 10);
    src.eraseColor(SK_ColorWHITE);

    SkBitmap dst;
    dst.allocN32Pixels(10, 10);
    dst.eraseColor(SK_ColorTRANSPARENT);

    SkCanvas canvas(dst);
<<<<<<< HEAD
    SkPaint paint;
=======
    SkPaint  paint;
>>>>>>> miniblink49

    // we are initially transparent
    REPORTER_ASSERT(reporter, 0 == *dst.getAddr32(5, 5));

    // we see the bitmap drawn
    canvas.drawBitmap(src, 0, 0, &paint);
    REPORTER_ASSERT(reporter, 0xFFFFFFFF == *dst.getAddr32(5, 5));

    // reverify we are clear again
    dst.eraseColor(SK_ColorTRANSPARENT);
    REPORTER_ASSERT(reporter, 0 == *dst.getAddr32(5, 5));

    // if the bitmap is clipped out, we don't draw it
    canvas.drawBitmap(src, SkIntToScalar(-10), 0, &paint);
    REPORTER_ASSERT(reporter, 0 == *dst.getAddr32(5, 5));

    // now install our looper, which will draw, since it internally translates
    // to the left. The test is to ensure that canvas' quickReject machinary
    // allows us through, even though sans-looper we would look like we should
    // be clipped out.
<<<<<<< HEAD
    paint.setLooper(sk_make_sp<TestLooper>());
=======
    paint.setLooper(new TestLooper)->unref();
>>>>>>> miniblink49
    canvas.drawBitmap(src, SkIntToScalar(-10), 0, &paint);
    REPORTER_ASSERT(reporter, 0xFFFFFFFF == *dst.getAddr32(5, 5));
}

<<<<<<< HEAD
static void test_layers(skiatest::Reporter* reporter)
{
=======
static void test_layers(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    SkCanvas canvas(100, 100);

    SkRect r = SkRect::MakeWH(10, 10);
    REPORTER_ASSERT(reporter, false == canvas.quickReject(r));

    r.offset(300, 300);
    REPORTER_ASSERT(reporter, true == canvas.quickReject(r));

    // Test that saveLayer updates quickReject
    SkRect bounds = SkRect::MakeLTRB(50, 50, 70, 70);
<<<<<<< HEAD
    canvas.saveLayer(&bounds, nullptr);
=======
    canvas.saveLayer(&bounds, NULL);
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, true == canvas.quickReject(SkRect::MakeWH(10, 10)));
    REPORTER_ASSERT(reporter, false == canvas.quickReject(SkRect::MakeWH(60, 60)));
}

<<<<<<< HEAD
DEF_TEST(QuickReject, reporter)
{
=======
DEF_TEST(QuickReject, reporter) {
>>>>>>> miniblink49
    test_drawBitmap(reporter);
    test_layers(reporter);
}
