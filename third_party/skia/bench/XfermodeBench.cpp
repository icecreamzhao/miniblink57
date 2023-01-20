<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
<<<<<<< HEAD
#include "SkArithmeticMode.h"
=======
>>>>>>> miniblink49
#include "SkCanvas.h"
#include "SkPaint.h"
#include "SkRandom.h"
#include "SkString.h"
#include "SkXfermode.h"

// Benchmark that draws non-AA rects or AA text with an SkXfermode::Mode.
class XfermodeBench : public Benchmark {
public:
<<<<<<< HEAD
    XfermodeBench(SkXfermode::Mode mode, bool aa)
    {
        fXfermode = SkXfermode::Make(mode);
=======
    XfermodeBench(SkXfermode::Mode mode, bool aa) {
        fXfermode.reset(SkXfermode::Create(mode));
>>>>>>> miniblink49
        fAA = aa;
        SkASSERT(fXfermode.get() || SkXfermode::kSrcOver_Mode == mode);
        fName.printf("Xfermode_%s%s", SkXfermode::ModeName(mode), aa ? "_aa" : "");
    }

<<<<<<< HEAD
    XfermodeBench(sk_sp<SkXfermode> xferMode, const char* name, bool aa)
    {
        fXfermode = xferMode;
=======
    XfermodeBench(SkXfermode* xferMode, const char* name, bool aa) {
        SkASSERT(xferMode);
        fXfermode.reset(xferMode);
>>>>>>> miniblink49
        fAA = aa;
        fName.printf("Xfermode_%s%s", name, aa ? "_aa" : "");
    }

protected:
    const char* onGetName() override { return fName.c_str(); }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        const char* text = "Hamburgefons";
        size_t len = strlen(text);
        SkISize size = canvas->getDeviceSize();
        SkRandom random;
        for (int i = 0; i < loops; ++i) {
            SkPaint paint;
<<<<<<< HEAD
            paint.setXfermode(fXfermode);
=======
            paint.setXfermode(fXfermode.get());
>>>>>>> miniblink49
            paint.setColor(random.nextU());
            if (fAA) {
                // Draw text to exercise AA code paths.
                paint.setAntiAlias(true);
                paint.setTextSize(random.nextRangeScalar(12, 96));
                SkScalar x = random.nextRangeScalar(0, (SkScalar)size.fWidth),
                         y = random.nextRangeScalar(0, (SkScalar)size.fHeight);
                for (int j = 0; j < 1000; ++j) {
                    canvas->drawText(text, len, x, y, paint);
                }
            } else {
                // Draw rects to exercise non-AA code paths.
                SkScalar w = random.nextRangeScalar(50, 100);
                SkScalar h = random.nextRangeScalar(50, 100);
                SkRect rect = SkRect::MakeXYWH(
                    random.nextUScalar1() * (size.fWidth - w),
                    random.nextUScalar1() * (size.fHeight - h),
                    w,
<<<<<<< HEAD
                    h);
=======
                    h
                );
>>>>>>> miniblink49
                for (int j = 0; j < 1000; ++j) {
                    canvas->drawRect(rect, paint);
                }
            }
        }
    }

private:
<<<<<<< HEAD
    sk_sp<SkXfermode> fXfermode;
=======
    SkAutoTUnref<SkXfermode> fXfermode;
>>>>>>> miniblink49
    SkString fName;
    bool fAA;

    typedef Benchmark INHERITED;
};

class XferCreateBench : public Benchmark {
public:
<<<<<<< HEAD
    bool isSuitableFor(Backend backend) override
    {
=======
    bool isSuitableFor(Backend backend) override {
>>>>>>> miniblink49
        return backend == kNonRendering_Backend;
    }

protected:
    const char* onGetName() override { return "xfermode_create"; }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
        for (int outer = 0; outer < loops * 10; ++outer) {
            for (int i = 0; i <= SkXfermode::kLastMode; ++i) {
                (void)SkXfermode::Make(SkXfermode::Mode(i));
=======
    void onDraw(const int loops, SkCanvas* canvas) override {
        for (int outer = 0; outer < loops * 10; ++outer) {
            for (int i = 0; i <= SkXfermode::kLastMode; ++i) {
                SkXfermode* xfer = SkXfermode::Create(SkXfermode::Mode(i));
                SkSafeUnref(xfer);
>>>>>>> miniblink49
            }
        }
    }

private:
    typedef Benchmark INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#define BENCH(...)                                          \
    DEF_BENCH(return new XfermodeBench(__VA_ARGS__, true);) \
    DEF_BENCH(return new XfermodeBench(__VA_ARGS__, false);)
=======
#define BENCH(...)                                             \
    DEF_BENCH( return new XfermodeBench(__VA_ARGS__, true); )  \
    DEF_BENCH( return new XfermodeBench(__VA_ARGS__, false); )
>>>>>>> miniblink49

BENCH(SkXfermode::kClear_Mode)
BENCH(SkXfermode::kSrc_Mode)
BENCH(SkXfermode::kDst_Mode)
BENCH(SkXfermode::kSrcOver_Mode)
BENCH(SkXfermode::kDstOver_Mode)
BENCH(SkXfermode::kSrcIn_Mode)
BENCH(SkXfermode::kDstIn_Mode)
BENCH(SkXfermode::kSrcOut_Mode)
BENCH(SkXfermode::kDstOut_Mode)
BENCH(SkXfermode::kSrcATop_Mode)
BENCH(SkXfermode::kDstATop_Mode)
BENCH(SkXfermode::kXor_Mode)

BENCH(SkXfermode::kPlus_Mode)
BENCH(SkXfermode::kModulate_Mode)
BENCH(SkXfermode::kScreen_Mode)

BENCH(SkXfermode::kOverlay_Mode)
BENCH(SkXfermode::kDarken_Mode)
BENCH(SkXfermode::kLighten_Mode)
BENCH(SkXfermode::kColorDodge_Mode)
BENCH(SkXfermode::kColorBurn_Mode)
BENCH(SkXfermode::kHardLight_Mode)
BENCH(SkXfermode::kSoftLight_Mode)
BENCH(SkXfermode::kDifference_Mode)
BENCH(SkXfermode::kExclusion_Mode)
BENCH(SkXfermode::kMultiply_Mode)

BENCH(SkXfermode::kHue_Mode)
BENCH(SkXfermode::kSaturation_Mode)
BENCH(SkXfermode::kColor_Mode)
BENCH(SkXfermode::kLuminosity_Mode)

<<<<<<< HEAD
DEF_BENCH(return new XfermodeBench(SkArithmeticMode::Make(0.2f, -0.3f, 1.5f, -0.7f, false),
    "arithmetic", false);)
DEF_BENCH(return new XfermodeBench(SkArithmeticMode::Make(0.2f, -0.3f, 1.5f, -0.7f, true),
    "arithmetic_enforce_pm", false);)
DEF_BENCH(return new XfermodeBench(SkArithmeticMode::Make(0.2f, -0.3f, 1.5f, -0.7f, false),
    "arithmetic", true);)
DEF_BENCH(return new XfermodeBench(SkArithmeticMode::Make(0.2f, -0.3f, 1.5f, -0.7f, true),
    "arithmetic_enforce_pm", true);)

=======
>>>>>>> miniblink49
DEF_BENCH(return new XferCreateBench;)
