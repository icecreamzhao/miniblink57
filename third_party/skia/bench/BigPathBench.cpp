/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkPath.h"
<<<<<<< HEAD
#include "sk_tool_utils.h"
=======
#include "SkString.h"

static void make_path(SkPath& path) {
    #include "BigPathBench.inc"
}
>>>>>>> miniblink49

enum Align {
    kLeft_Align,
    kMiddle_Align,
    kRight_Align
};

const char* gAlignName[] = { "left", "middle", "right" };

// Inspired by crbug.com/455429
class BigPathBench : public Benchmark {
<<<<<<< HEAD
    SkPath fPath;
    SkString fName;
    Align fAlign;
    bool fRound;

public:
    BigPathBench(Align align, bool round)
        : fAlign(align)
        , fRound(round)
    {
=======
    SkPath      fPath;
    SkString    fName;
    Align       fAlign;
    bool        fRound;

public:
    BigPathBench(Align align, bool round) : fAlign(align), fRound(round) {
>>>>>>> miniblink49
        fName.printf("bigpath_%s", gAlignName[fAlign]);
        if (round) {
            fName.append("_round");
        }
    }

protected:
<<<<<<< HEAD
    const char* onGetName() override
    {
        return fName.c_str();
    }

    SkIPoint onGetSize() override
    {
        return SkIPoint::Make(640, 100);
    }

    void onDelayedSetup() override
    {
        sk_tool_utils::make_big_path(fPath);
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    const char* onGetName() override {
        return fName.c_str();
    }

    SkIPoint onGetSize() override {
        return SkIPoint::Make(640, 100);
    }

    void onPreDraw() override {
        make_path(fPath);
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setStrokeWidth(2);
        if (fRound) {
            paint.setStrokeJoin(SkPaint::kRound_Join);
        }
        this->setupPaint(&paint);

        const SkRect r = fPath.getBounds();
        switch (fAlign) {
<<<<<<< HEAD
        case kLeft_Align:
            canvas->translate(-r.left(), 0);
            break;
        case kMiddle_Align:
            break;
        case kRight_Align:
            canvas->translate(640 - r.right(), 0);
            break;
=======
            case kLeft_Align:
                canvas->translate(-r.left(), 0);
                break;
            case kMiddle_Align:
                break;
            case kRight_Align:
                canvas->translate(640 - r.right(), 0);
                break;
>>>>>>> miniblink49
        }

        for (int i = 0; i < loops; i++) {
            canvas->drawPath(fPath, paint);
        }
    }

private:
    typedef Benchmark INHERITED;
};

<<<<<<< HEAD
DEF_BENCH(return new BigPathBench(kLeft_Align, false);)
DEF_BENCH(return new BigPathBench(kMiddle_Align, false);)
DEF_BENCH(return new BigPathBench(kRight_Align, false);)

DEF_BENCH(return new BigPathBench(kLeft_Align, true);)
DEF_BENCH(return new BigPathBench(kMiddle_Align, true);)
DEF_BENCH(return new BigPathBench(kRight_Align, true);)
=======
DEF_BENCH( return new BigPathBench(kLeft_Align,     false); )
DEF_BENCH( return new BigPathBench(kMiddle_Align,   false); )
DEF_BENCH( return new BigPathBench(kRight_Align,    false); )

DEF_BENCH( return new BigPathBench(kLeft_Align,     true); )
DEF_BENCH( return new BigPathBench(kMiddle_Align,   true); )
DEF_BENCH( return new BigPathBench(kRight_Align,    true); )

>>>>>>> miniblink49
