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
#include "SkCanvas.h"
#include "SkPaint.h"
#include "SkRandom.h"

/**
 * Draws full screen opaque rectangles. It is designed to test any optimizations in the GPU backend
 * to turn such draws into clears.
 */
class FSRectBench : public Benchmark {
public:
<<<<<<< HEAD
    FSRectBench()
        : fInit(false)
    {
    }
=======
    FSRectBench() : fInit(false) { }
>>>>>>> miniblink49

protected:
    const char* onGetName() override { return "fullscreen_rects"; }

<<<<<<< HEAD
    void onDelayedSetup() override
    {
=======
    void onPreDraw() override {
>>>>>>> miniblink49
        if (!fInit) {
            SkRandom rand;
            static const SkScalar kMinOffset = 0;
            static const SkScalar kMaxOffset = 100 * SK_Scalar1;
            static const SkScalar kOffsetRange = kMaxOffset - kMinOffset;
            for (int i = 0; i < N; ++i) {
                fRects[i].fLeft = -kMinOffset - SkScalarMul(rand.nextUScalar1(), kOffsetRange);
                fRects[i].fTop = -kMinOffset - SkScalarMul(rand.nextUScalar1(), kOffsetRange);
                fRects[i].fRight = W + kMinOffset + SkScalarMul(rand.nextUScalar1(), kOffsetRange);
                fRects[i].fBottom = H + kMinOffset + SkScalarMul(rand.nextUScalar1(), kOffsetRange);
                fColors[i] = rand.nextU() | 0xFF000000;
            }
            fInit = true;
        }
    }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;
        for (int i = 0; i < loops; ++i) {
            paint.setColor(fColors[i % N]);
            canvas->drawRect(fRects[i % N], paint);
        }
    }

private:
    enum {
        W = 640,
        H = 480,
        N = 300,
    };
<<<<<<< HEAD
    SkRect fRects[N];
=======
    SkRect  fRects[N];
>>>>>>> miniblink49
    SkColor fColors[N];
    bool fInit;

    typedef Benchmark INHERITED;
};

<<<<<<< HEAD
DEF_BENCH(return new FSRectBench();)
=======
DEF_BENCH( return SkNEW_ARGS(FSRectBench, ()); )
>>>>>>> miniblink49
