/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkColorCubeFilter.h"
#include "SkGradientShader.h"
<<<<<<< HEAD
#include "SkTemplates.h"
=======
>>>>>>> miniblink49

class ColorCubeBench : public Benchmark {
    SkISize fSize;
    int fCubeDimension;
<<<<<<< HEAD
    sk_sp<SkData> fCubeData;
=======
    SkData* fCubeData;
>>>>>>> miniblink49
    SkBitmap fBitmap;

public:
    ColorCubeBench()
<<<<<<< HEAD
        : fCubeDimension(0)
    {
        fSize = SkISize::Make(2880, 1800); // 2014 Macbook Pro resolution
    }

protected:
    const char* onGetName() override
    {
        return "colorcube";
    }

    void onDelayedSetup() override
    {
=======
     : fCubeDimension(0)
     , fCubeData(NULL) {
        fSize = SkISize::Make(2880, 1800); // 2014 Macbook Pro resolution
    }

    ~ColorCubeBench() {
        SkSafeUnref(fCubeData);
    }

protected:
    const char* onGetName() override {
        return "colorcube";
    }

    void onPreDraw() override {
>>>>>>> miniblink49
        if (!SkToBool(fCubeData)) {
            this->makeCubeData();
            this->make_bitmap();
        }
    }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
        this->test(loops, canvas);
    }

    SkIPoint onGetSize() override
    {
=======
    void onDraw(const int loops, SkCanvas* canvas) override {
        this->test(loops, canvas);
    }

    SkIPoint onGetSize() override {
>>>>>>> miniblink49
        return SkIPoint::Make(fSize.width(), fSize.height());
    }

private:
<<<<<<< HEAD
    static sk_sp<SkShader> MakeLinear(const SkISize& size)
    {
        const SkPoint pts[2] = {
            { 0, 0 },
            { SkIntToScalar(size.width()), SkIntToScalar(size.height()) }
        };
        static const SkColor colors[] = { SK_ColorYELLOW, SK_ColorBLUE };
        return SkGradientShader::MakeLinear(
            pts, colors, nullptr, 2, SkShader::kRepeat_TileMode, 0, &SkMatrix::I());
    }

    void make_bitmap()
    {
=======
    static SkShader* MakeLinear(const SkISize& size) {
        const SkPoint pts[2] = {
                { 0, 0 },
                { SkIntToScalar(size.width()), SkIntToScalar(size.height()) }
            };
        static const SkColor colors[] = { SK_ColorYELLOW, SK_ColorBLUE };
        return SkGradientShader::CreateLinear(
            pts, colors, NULL, 2, SkShader::kRepeat_TileMode, 0, &SkMatrix::I());
    }

    void make_bitmap() {
>>>>>>> miniblink49
        fBitmap.allocN32Pixels(fSize.width(), fSize.height());
        SkCanvas canvas(fBitmap);
        canvas.clear(0x00000000);
        SkPaint paint;
        paint.setAntiAlias(true);
<<<<<<< HEAD
        paint.setShader(MakeLinear(fSize));
        SkRect r = { 0, 0, SkIntToScalar(fSize.width()), SkIntToScalar(fSize.height()) };
        canvas.drawRect(r, paint);
    }

    void makeCubeData()
    {
        fCubeDimension = 32;
        fCubeData = SkData::MakeUninitialized(sizeof(SkColor) * fCubeDimension * fCubeDimension * fCubeDimension);
        SkColor* pixels = (SkColor*)(fCubeData->writable_data());
        SkAutoTMalloc<uint8_t> lutMemory(fCubeDimension);
        uint8_t* lut = lutMemory.get();
=======
        SkShader* shader = MakeLinear(fSize);
        paint.setShader(shader);
        SkRect r = { 0, 0, SkIntToScalar(fSize.width()), SkIntToScalar(fSize.height()) };
        canvas.drawRect(r, paint);
        shader->unref();
    }

    void makeCubeData() {
        fCubeDimension = 32;
        fCubeData = SkData::NewUninitialized(sizeof(SkColor) *
            fCubeDimension * fCubeDimension * fCubeDimension);
        SkColor* pixels = (SkColor*)(fCubeData->writable_data());
        SkAutoMalloc lutMemory(fCubeDimension);
        uint8_t* lut = (uint8_t*)lutMemory.get();
>>>>>>> miniblink49
        const int maxIndex = fCubeDimension - 1;
        for (int i = 0; i < fCubeDimension; ++i) {
            // Make an invert lut, but the content of
            // the lut shouldn't affect performance.
            lut[i] = ((maxIndex - i) * 255) / maxIndex;
        }
        for (int r = 0; r < fCubeDimension; ++r) {
            for (int g = 0; g < fCubeDimension; ++g) {
                for (int b = 0; b < fCubeDimension; ++b) {
<<<<<<< HEAD
                    pixels[(fCubeDimension * ((fCubeDimension * b) + g)) + r] = SkColorSetARGB(0xFF, lut[r], lut[g], lut[b]);
=======
                    pixels[(fCubeDimension * ((fCubeDimension * b) + g)) + r] =
                        SkColorSetARGB(0xFF, lut[r], lut[g], lut[b]);
>>>>>>> miniblink49
                }
            }
        }
    }

<<<<<<< HEAD
    void test(int loops, SkCanvas* canvas)
    {
        SkPaint paint;
        for (int i = 0; i < loops; i++) {
            paint.setColorFilter(SkColorCubeFilter::Make(fCubeData, fCubeDimension));
=======
    void test(const int loops, SkCanvas* canvas) {
        SkPaint paint;
        for (int i = 0; i < loops; i++) {
            SkAutoTUnref<SkColorFilter> colorCube(
                SkColorCubeFilter::Create(fCubeData, fCubeDimension));
            paint.setColorFilter(colorCube);
>>>>>>> miniblink49
            canvas->drawBitmap(fBitmap, 0, 0, &paint);
        }
    }

    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new ColorCubeBench();)
=======
DEF_BENCH( return new ColorCubeBench(); )
>>>>>>> miniblink49
