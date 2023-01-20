/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkDisplacementMapEffect.h"
#include "SkImageSource.h"
#include "SkSurface.h"

#define FILTER_WIDTH_SMALL 32
#define FILTER_HEIGHT_SMALL 32
#define FILTER_WIDTH_LARGE 256
=======
#include "SkBitmapSource.h"
#include "SkCanvas.h"
#include "SkDisplacementMapEffect.h"

#define FILTER_WIDTH_SMALL  32
#define FILTER_HEIGHT_SMALL 32
#define FILTER_WIDTH_LARGE  256
>>>>>>> miniblink49
#define FILTER_HEIGHT_LARGE 256

class DisplacementBaseBench : public Benchmark {
public:
<<<<<<< HEAD
    DisplacementBaseBench(bool small)
        : fInitialized(false)
        , fIsSmall(small)
    {
    }

protected:
    void onDelayedSetup() override
    {
=======
    DisplacementBaseBench(bool small) :
        fInitialized(false), fIsSmall(small) {
    }

protected:
    void onPreDraw() override {
>>>>>>> miniblink49
        if (!fInitialized) {
            this->makeBitmap();
            this->makeCheckerboard();
            fInitialized = true;
        }
    }

<<<<<<< HEAD
    void makeBitmap()
    {
=======
    void makeBitmap() {
>>>>>>> miniblink49
        const int w = this->isSmall() ? FILTER_WIDTH_SMALL : FILTER_WIDTH_LARGE;
        const int h = this->isSmall() ? FILTER_HEIGHT_LARGE : FILTER_HEIGHT_LARGE;
        fBitmap.allocN32Pixels(w, h);
        SkCanvas canvas(fBitmap);
        canvas.clear(0x00000000);
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setColor(0xFF884422);
        paint.setTextSize(SkIntToScalar(96));
        const char* str = "g";
        canvas.drawText(str, strlen(str), SkIntToScalar(15), SkIntToScalar(55), paint);
    }

<<<<<<< HEAD
    void makeCheckerboard()
    {
        const int w = this->isSmall() ? FILTER_WIDTH_SMALL : FILTER_WIDTH_LARGE;
        const int h = this->isSmall() ? FILTER_HEIGHT_LARGE : FILTER_HEIGHT_LARGE;
        auto surface(SkSurface::MakeRasterN32Premul(w, h));
        SkCanvas* canvas = surface->getCanvas();
        canvas->clear(0x00000000);
=======
    void makeCheckerboard() {
        const int w = this->isSmall() ? FILTER_WIDTH_SMALL : FILTER_WIDTH_LARGE;
        const int h = this->isSmall() ? FILTER_HEIGHT_LARGE : FILTER_HEIGHT_LARGE;
        fCheckerboard.allocN32Pixels(w, h);
        SkCanvas canvas(fCheckerboard);
        canvas.clear(0x00000000);
>>>>>>> miniblink49
        SkPaint darkPaint;
        darkPaint.setColor(0xFF804020);
        SkPaint lightPaint;
        lightPaint.setColor(0xFF244484);
        for (int y = 0; y < h; y += 16) {
            for (int x = 0; x < w; x += 16) {
<<<<<<< HEAD
                canvas->save();
                canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
                canvas->drawRect(SkRect::MakeXYWH(0, 0, 8, 8), darkPaint);
                canvas->drawRect(SkRect::MakeXYWH(8, 0, 8, 8), lightPaint);
                canvas->drawRect(SkRect::MakeXYWH(0, 8, 8, 8), lightPaint);
                canvas->drawRect(SkRect::MakeXYWH(8, 8, 8, 8), darkPaint);
                canvas->restore();
            }
        }

        fCheckerboard = surface->makeImageSnapshot();
    }

    void drawClippedBitmap(SkCanvas* canvas, int x, int y, const SkPaint& paint)
    {
        canvas->save();
        canvas->clipRect(SkRect::MakeXYWH(SkIntToScalar(x), SkIntToScalar(y),
            SkIntToScalar(fBitmap.width()),
            SkIntToScalar(fBitmap.height())));
=======
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

    void drawClippedBitmap(SkCanvas* canvas, int x, int y, const SkPaint& paint) {
        canvas->save();
        canvas->clipRect(SkRect::MakeXYWH(SkIntToScalar(x), SkIntToScalar(y),
                                          SkIntToScalar(fBitmap.width()),
                                          SkIntToScalar(fBitmap.height())));
>>>>>>> miniblink49
        canvas->drawBitmap(fBitmap, SkIntToScalar(x), SkIntToScalar(y), &paint);
        canvas->restore();
    }

    inline bool isSmall() const { return fIsSmall; }

<<<<<<< HEAD
    SkBitmap fBitmap;
    sk_sp<SkImage> fCheckerboard;

=======
    SkBitmap fBitmap, fCheckerboard;
>>>>>>> miniblink49
private:
    bool fInitialized;
    bool fIsSmall;
    typedef Benchmark INHERITED;
};

class DisplacementZeroBench : public DisplacementBaseBench {
public:
<<<<<<< HEAD
    DisplacementZeroBench(bool small)
        : INHERITED(small)
    {
    }

protected:
    const char* onGetName() override
    {
        return this->isSmall() ? "displacement_zero_small" : "displacement_zero_large";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        SkPaint paint;
        sk_sp<SkImageFilter> displ(SkImageSource::Make(fCheckerboard));
        // No displacement effect
        paint.setImageFilter(SkDisplacementMapEffect::Make(
            SkDisplacementMapEffect::kR_ChannelSelectorType,
            SkDisplacementMapEffect::kG_ChannelSelectorType,
            0.0f, std::move(displ), nullptr));
=======
    DisplacementZeroBench(bool small) : INHERITED(small) {
    }

protected:
    const char* onGetName() override {
        return this->isSmall() ? "displacement_zero_small" : "displacement_zero_large";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        SkPaint paint;
        SkAutoTUnref<SkImageFilter> displ(SkBitmapSource::Create(fCheckerboard));
        // No displacement effect
        paint.setImageFilter(SkDisplacementMapEffect::Create(
            SkDisplacementMapEffect::kR_ChannelSelectorType,
            SkDisplacementMapEffect::kG_ChannelSelectorType, 0.0f, displ))->unref();
>>>>>>> miniblink49

        for (int i = 0; i < loops; i++) {
            this->drawClippedBitmap(canvas, 0, 0, paint);
        }
    }

private:
    typedef DisplacementBaseBench INHERITED;
};

class DisplacementAlphaBench : public DisplacementBaseBench {
public:
<<<<<<< HEAD
    DisplacementAlphaBench(bool small)
        : INHERITED(small)
    {
    }

protected:
    const char* onGetName() override
    {
        return isSmall() ? "displacement_alpha_small" : "displacement_alpha_large";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        SkPaint paint;
        sk_sp<SkImageFilter> displ(SkImageSource::Make(fCheckerboard));
        // Displacement, with 1 alpha component (which isn't pre-multiplied)
        paint.setImageFilter(SkDisplacementMapEffect::Make(
            SkDisplacementMapEffect::kB_ChannelSelectorType,
            SkDisplacementMapEffect::kA_ChannelSelectorType,
            16.0f, std::move(displ), nullptr));
        for (int i = 0; i < loops; i++) {
            this->drawClippedBitmap(canvas, 100, 0, paint);
=======
    DisplacementAlphaBench(bool small) : INHERITED(small) {
    }

protected:
    const char* onGetName() override {
        return isSmall() ? "displacement_alpha_small" : "displacement_alpha_large";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        SkPaint paint;
        SkAutoTUnref<SkImageFilter> displ(SkBitmapSource::Create(fCheckerboard));
        // Displacement, with 1 alpha component (which isn't pre-multiplied)
        paint.setImageFilter(SkDisplacementMapEffect::Create(
            SkDisplacementMapEffect::kB_ChannelSelectorType,
            SkDisplacementMapEffect::kA_ChannelSelectorType, 16.0f, displ))->unref();
        for (int i = 0; i < loops; i++) {
            drawClippedBitmap(canvas, 100, 0, paint);
>>>>>>> miniblink49
        }
    }

private:
    typedef DisplacementBaseBench INHERITED;
};

class DisplacementFullBench : public DisplacementBaseBench {
public:
<<<<<<< HEAD
    DisplacementFullBench(bool small)
        : INHERITED(small)
    {
    }

protected:
    const char* onGetName() override
    {
        return isSmall() ? "displacement_full_small" : "displacement_full_large";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        SkPaint paint;
        sk_sp<SkImageFilter> displ(SkImageSource::Make(fCheckerboard));
        // Displacement, with 2 non-alpha components
        paint.setImageFilter(SkDisplacementMapEffect::Make(
            SkDisplacementMapEffect::kR_ChannelSelectorType,
            SkDisplacementMapEffect::kB_ChannelSelectorType,
            32.0f, std::move(displ), nullptr));
=======
    DisplacementFullBench(bool small) : INHERITED(small) {
    }

protected:
    const char* onGetName() override {
        return isSmall() ? "displacement_full_small" : "displacement_full_large";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        SkPaint paint;
        SkAutoTUnref<SkImageFilter> displ(SkBitmapSource::Create(fCheckerboard));
        // Displacement, with 2 non-alpha components
        paint.setImageFilter(SkDisplacementMapEffect::Create(
            SkDisplacementMapEffect::kR_ChannelSelectorType,
            SkDisplacementMapEffect::kB_ChannelSelectorType, 32.0f, displ))->unref();
>>>>>>> miniblink49
        for (int i = 0; i < loops; ++i) {
            this->drawClippedBitmap(canvas, 200, 0, paint);
        }
    }

private:
    typedef DisplacementBaseBench INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new DisplacementZeroBench(true);)
DEF_BENCH(return new DisplacementAlphaBench(true);)
DEF_BENCH(return new DisplacementFullBench(true);)
DEF_BENCH(return new DisplacementZeroBench(false);)
DEF_BENCH(return new DisplacementAlphaBench(false);)
DEF_BENCH(return new DisplacementFullBench(false);)
=======
DEF_BENCH( return new DisplacementZeroBench(true); )
DEF_BENCH( return new DisplacementAlphaBench(true); )
DEF_BENCH( return new DisplacementFullBench(true); )
DEF_BENCH( return new DisplacementZeroBench(false); )
DEF_BENCH( return new DisplacementAlphaBench(false); )
DEF_BENCH( return new DisplacementFullBench(false); )
>>>>>>> miniblink49
