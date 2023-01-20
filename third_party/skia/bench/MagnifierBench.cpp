/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkMagnifierImageFilter.h"
#include "SkRandom.h"

<<<<<<< HEAD
#define FILTER_WIDTH_SMALL 32
#define FILTER_HEIGHT_SMALL 32
#define FILTER_WIDTH_LARGE 256
=======
#define FILTER_WIDTH_SMALL  32
#define FILTER_HEIGHT_SMALL 32
#define FILTER_WIDTH_LARGE  256
>>>>>>> miniblink49
#define FILTER_HEIGHT_LARGE 256

class MagnifierBench : public Benchmark {
public:
<<<<<<< HEAD
    MagnifierBench(bool small)
        : fIsSmall(small)
        , fInitialized(false)
    {
    }

protected:
    const char* onGetName() override
    {
        return fIsSmall ? "magnifier_small" : "magnifier_large";
    }

    void onDelayedSetup() override
    {
=======
    MagnifierBench(bool small) :
        fIsSmall(small), fInitialized(false) {
    }

protected:
    const char* onGetName() override {
        return fIsSmall ? "magnifier_small" : "magnifier_large";
    }

    void onPreDraw() override {
>>>>>>> miniblink49
        if (!fInitialized) {
            make_checkerboard();
            fInitialized = true;
        }
    }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        const int w = fIsSmall ? FILTER_WIDTH_SMALL : FILTER_WIDTH_LARGE;
        const int h = fIsSmall ? FILTER_HEIGHT_SMALL : FILTER_HEIGHT_LARGE;
        SkPaint paint;
        paint.setImageFilter(
<<<<<<< HEAD
            SkMagnifierImageFilter::Make(
                SkRect::MakeXYWH(SkIntToScalar(w / 4),
                    SkIntToScalar(h / 4),
                    SkIntToScalar(w / 2),
                    SkIntToScalar(h / 2)),
                100, nullptr));
=======
            SkMagnifierImageFilter::Create(
                SkRect::MakeXYWH(SkIntToScalar(w / 4),
                                 SkIntToScalar(h / 4),
                                 SkIntToScalar(w / 2),
                                 SkIntToScalar(h / 2)), 100))->unref();
>>>>>>> miniblink49

        for (int i = 0; i < loops; i++) {
            canvas->drawBitmap(fCheckerboard, 0, 0, &paint);
        }
    }

private:
<<<<<<< HEAD
    void make_checkerboard()
    {
=======
    void make_checkerboard() {
>>>>>>> miniblink49
        const int w = fIsSmall ? FILTER_WIDTH_SMALL : FILTER_WIDTH_LARGE;
        const int h = fIsSmall ? FILTER_HEIGHT_LARGE : FILTER_HEIGHT_LARGE;
        fCheckerboard.allocN32Pixels(w, h);
        SkCanvas canvas(fCheckerboard);
        canvas.clear(0x00000000);
        SkPaint darkPaint;
        darkPaint.setColor(0xFF804020);
        SkPaint lightPaint;
        lightPaint.setColor(0xFF244484);
        for (int y = 0; y < h; y += 16) {
            for (int x = 0; x < w; x += 16) {
                canvas.save();
                canvas.translate(SkIntToScalar(x), SkIntToScalar(y));
                canvas.drawRect(SkRect::MakeXYWH(0, 0, 8, 8), darkPaint);
                canvas.drawRect(SkRect::MakeXYWH(8, 0, 8, 8), lightPaint);
                canvas.drawRect(SkRect::MakeXYWH(0, 8, 8, 8), lightPaint);
                canvas.drawRect(SkRect::MakeXYWH(8, 8, 8, 8), darkPaint);
                canvas.restore();
            }
        }
    }

    bool fIsSmall;
    bool fInitialized;
    SkBitmap fCheckerboard;
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new MagnifierBench(true);)
DEF_BENCH(return new MagnifierBench(false);)
=======
DEF_BENCH( return new MagnifierBench(true); )
DEF_BENCH( return new MagnifierBench(false); )
>>>>>>> miniblink49
