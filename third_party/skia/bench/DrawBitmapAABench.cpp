/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkMatrix.h"
#include "SkPaint.h"
#include "SkString.h"

/**
 * This bench measures the rendering time of SkCanvas::drawBitmap with different anti-aliasing /
 * matrix combinations.
 */

class DrawBitmapAABench : public Benchmark {
public:
    DrawBitmapAABench(bool doAA, const SkMatrix& matrix, const char name[])
        : fMatrix(matrix)
<<<<<<< HEAD
        , fName("draw_bitmap_")
    {
=======
        , fName("draw_bitmap_") {
>>>>>>> miniblink49

        fPaint.setAntiAlias(doAA);
        // Most clients use filtering, so let's focus on this for now.
        fPaint.setFilterQuality(kLow_SkFilterQuality);
        fName.appendf("%s_%s", doAA ? "aa" : "noaa", name);
    }

protected:
<<<<<<< HEAD
    const char* onGetName() override
    {
        return fName.c_str();
    }

    void onDelayedSetup() override
    {
=======
    const char* onGetName() override {
        return fName.c_str();
    }

    void onPreDraw() override {
>>>>>>> miniblink49
        fBitmap.allocN32Pixels(200, 200);
        fBitmap.eraseARGB(255, 0, 255, 0);
    }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        canvas->concat(fMatrix);
        for (int i = 0; i < loops; i++) {
            canvas->drawBitmap(fBitmap, 0, 0, &fPaint);
        }
    }

private:
<<<<<<< HEAD
    SkPaint fPaint;
=======
    SkPaint  fPaint;
>>>>>>> miniblink49
    SkMatrix fMatrix;
    SkString fName;
    SkBitmap fBitmap;

    typedef Benchmark INHERITED;
};

<<<<<<< HEAD
DEF_BENCH(return new DrawBitmapAABench(false, SkMatrix::MakeScale(1), "ident");)

DEF_BENCH(return new DrawBitmapAABench(false, SkMatrix::MakeScale(1.17f), "scale");)

DEF_BENCH(return new DrawBitmapAABench(false, SkMatrix::MakeTrans(17.5f, 17.5f), "translate");)
=======
DEF_BENCH( return new DrawBitmapAABench(false, SkMatrix::MakeScale(1), "ident"); )

DEF_BENCH( return new DrawBitmapAABench(false, SkMatrix::MakeScale(1.17f), "scale"); )

DEF_BENCH( return new DrawBitmapAABench(false, SkMatrix::MakeTrans(17.5f, 17.5f), "translate"); )
>>>>>>> miniblink49

DEF_BENCH(
    SkMatrix m;
    m.reset();
    m.preRotate(15);
<<<<<<< HEAD
    return new DrawBitmapAABench(false, m, "rotate");)

DEF_BENCH(return new DrawBitmapAABench(true, SkMatrix::MakeScale(1), "ident");)

DEF_BENCH(return new DrawBitmapAABench(true, SkMatrix::MakeScale(1.17f), "scale");)

DEF_BENCH(return new DrawBitmapAABench(true, SkMatrix::MakeTrans(17.5f, 17.5f), "translate");)
=======
    return new DrawBitmapAABench(false, m, "rotate");
)

DEF_BENCH( return new DrawBitmapAABench(true, SkMatrix::MakeScale(1), "ident"); )

DEF_BENCH( return new DrawBitmapAABench(true, SkMatrix::MakeScale(1.17f), "scale"); )

DEF_BENCH( return new DrawBitmapAABench(true, SkMatrix::MakeTrans(17.5f, 17.5f), "translate"); )
>>>>>>> miniblink49

DEF_BENCH(
    SkMatrix m;
    m.reset();
    m.preRotate(15);
<<<<<<< HEAD
    return new DrawBitmapAABench(true, m, "rotate");)
=======
    return new DrawBitmapAABench(true, m, "rotate");
)
>>>>>>> miniblink49
