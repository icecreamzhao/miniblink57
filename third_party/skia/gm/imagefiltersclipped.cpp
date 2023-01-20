/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======
#include "sk_tool_utils.h"
#include "SkBitmapSource.h"
>>>>>>> miniblink49
#include "SkBlurImageFilter.h"
#include "SkColor.h"
#include "SkDisplacementMapEffect.h"
#include "SkDropShadowImageFilter.h"
#include "SkGradientShader.h"
<<<<<<< HEAD
#include "SkImage.h"
#include "SkImageSource.h"
#include "SkLightingImageFilter.h"
#include "SkMorphologyImageFilter.h"
#include "SkOffsetImageFilter.h"
#include "SkPaintImageFilter.h"
#include "SkPerlinNoiseShader.h"
#include "SkPoint3.h"
#include "SkScalar.h"
#include "SkSurface.h"
#include "gm.h"
#include "sk_tool_utils.h"
=======
#include "SkMorphologyImageFilter.h"
#include "SkOffsetImageFilter.h"
#include "SkPerlinNoiseShader.h"
#include "SkRectShaderImageFilter.h"
#include "SkScalar.h"
#include "gm.h"
>>>>>>> miniblink49

#define RESIZE_FACTOR_X SkIntToScalar(2)
#define RESIZE_FACTOR_Y SkIntToScalar(5)

<<<<<<< HEAD
static sk_sp<SkImage> make_gradient_circle(int width, int height)
{
    SkScalar x = SkIntToScalar(width / 2);
    SkScalar y = SkIntToScalar(height / 2);
    SkScalar radius = SkMinScalar(x, y) * 0.8f;
    auto surface(SkSurface::MakeRasterN32Premul(width, height));
    SkCanvas* canvas = surface->getCanvas();
    canvas->clear(0x00000000);
    SkColor colors[2];
    colors[0] = SK_ColorWHITE;
    colors[1] = SK_ColorBLACK;
    SkPaint paint;
    paint.setShader(SkGradientShader::MakeRadial(SkPoint::Make(x, y), radius, colors, nullptr,
        2, SkShader::kClamp_TileMode));
    canvas->drawCircle(x, y, radius, paint);
    return surface->makeImageSnapshot();
}

static void draw_clipped_filter(SkCanvas* canvas, sk_sp<SkImageFilter> filter, size_t i,
    const SkRect& primBounds, const SkRect& clipBounds)
{
    SkPaint paint;
    paint.setColor(SK_ColorWHITE);
    paint.setImageFilter(std::move(filter));
    paint.setAntiAlias(true);
    canvas->save();
    canvas->clipRect(clipBounds);
    if (5 == i) {
        canvas->translate(SkIntToScalar(16), SkIntToScalar(-32));
    } else if (6 == i) {
        canvas->scale(SkScalarInvert(RESIZE_FACTOR_X), SkScalarInvert(RESIZE_FACTOR_Y));
    }
    canvas->drawCircle(primBounds.centerX(), primBounds.centerY(),
        primBounds.width() * 2 / 5, paint);
    canvas->restore();
}

=======
>>>>>>> miniblink49
namespace skiagm {

class ImageFiltersClippedGM : public GM {
public:
<<<<<<< HEAD
    ImageFiltersClippedGM()
    {
=======
    ImageFiltersClippedGM() : fInitialized(false) {
>>>>>>> miniblink49
        this->setBGColor(0x00000000);
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("imagefiltersclipped");
    }

    SkISize onISize() override
    {
        return SkISize::Make(860, 500);
    }

    void onOnceBeforeDraw() override
    {
        fCheckerboard = SkImage::MakeFromBitmap(sk_tool_utils::create_checkerboard_bitmap(64, 64, 0xFFA0A0A0, 0xFF404040, 8));
        fGradientCircle = make_gradient_circle(64, 64);
    }

    void onDraw(SkCanvas* canvas) override
    {
        canvas->clear(SK_ColorBLACK);

        sk_sp<SkImageFilter> gradient(SkImageSource::Make(fGradientCircle));
        sk_sp<SkImageFilter> checkerboard(SkImageSource::Make(fCheckerboard));
        SkMatrix resizeMatrix;
        resizeMatrix.setScale(RESIZE_FACTOR_X, RESIZE_FACTOR_Y);
        SkPoint3 pointLocation = SkPoint3::Make(32, 32, SkIntToScalar(10));

        sk_sp<SkImageFilter> filters[] = {
            SkBlurImageFilter::Make(SkIntToScalar(12), SkIntToScalar(12), nullptr),
            SkDropShadowImageFilter::Make(
                SkIntToScalar(10), SkIntToScalar(10),
                SkIntToScalar(3), SkIntToScalar(3), SK_ColorGREEN,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode,
                nullptr),
            SkDisplacementMapEffect::Make(SkDisplacementMapEffect::kR_ChannelSelectorType,
                SkDisplacementMapEffect::kR_ChannelSelectorType,
                SkIntToScalar(12),
                std::move(gradient),
                checkerboard),
            SkDilateImageFilter::Make(2, 2, checkerboard),
            SkErodeImageFilter::Make(2, 2, checkerboard),
            SkOffsetImageFilter::Make(SkIntToScalar(-16), SkIntToScalar(32), nullptr),
            SkImageFilter::MakeMatrixFilter(resizeMatrix, kNone_SkFilterQuality, nullptr),
            SkLightingImageFilter::MakePointLitDiffuse(pointLocation, SK_ColorWHITE, SK_Scalar1,
                SkIntToScalar(2), checkerboard),

=======

    SkString onShortName() override {
        return SkString("imagefiltersclipped");
    }

    SkISize onISize() override {
        return SkISize::Make(860, 500);
    }

    void make_gradient_circle(int width, int height) {
        SkScalar x = SkIntToScalar(width / 2);
        SkScalar y = SkIntToScalar(height / 2);
        SkScalar radius = SkMinScalar(x, y) * 0.8f;
        fGradientCircle.allocN32Pixels(width, height);
        SkCanvas canvas(fGradientCircle);
        canvas.clear(0x00000000);
        SkColor colors[2];
        colors[0] = SK_ColorWHITE;
        colors[1] = SK_ColorBLACK;
        SkAutoTUnref<SkShader> shader(
            SkGradientShader::CreateRadial(SkPoint::Make(x, y), radius, colors, NULL, 2,
                                           SkShader::kClamp_TileMode)
        );
        SkPaint paint;
        paint.setShader(shader);
        canvas.drawCircle(x, y, radius, paint);
    }

    void onDraw(SkCanvas* canvas) override {
        if (!fInitialized) {
            fCheckerboard.allocN32Pixels(64, 64);
            SkCanvas checkerboardCanvas(fCheckerboard);
            sk_tool_utils::draw_checkerboard(&checkerboardCanvas, 0xFFA0A0A0, 0xFF404040, 8);

            this->make_gradient_circle(64, 64);
            fInitialized = true;
        }
        canvas->clear(SK_ColorBLACK);

        SkAutoTUnref<SkImageFilter> gradient(SkBitmapSource::Create(fGradientCircle));
        SkAutoTUnref<SkImageFilter> checkerboard(SkBitmapSource::Create(fCheckerboard));
        SkAutoTUnref<SkShader> noise(SkPerlinNoiseShader::CreateFractalNoise(
            SkDoubleToScalar(0.1), SkDoubleToScalar(0.05), 1, 0));
        SkMatrix resizeMatrix;
        resizeMatrix.setScale(RESIZE_FACTOR_X, RESIZE_FACTOR_Y);

        SkImageFilter* filters[] = {
            SkBlurImageFilter::Create(SkIntToScalar(12), SkIntToScalar(12)),
            SkDropShadowImageFilter::Create(SkIntToScalar(10), SkIntToScalar(10),
                SkIntToScalar(3), SkIntToScalar(3), SK_ColorGREEN,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode),
            SkDisplacementMapEffect::Create(SkDisplacementMapEffect::kR_ChannelSelectorType,
                                            SkDisplacementMapEffect::kR_ChannelSelectorType,
                                            SkIntToScalar(12),
                                            gradient.get(),
                                            checkerboard.get()),
            SkDilateImageFilter::Create(2, 2, checkerboard.get()),
            SkErodeImageFilter::Create(2, 2, checkerboard.get()),
            SkOffsetImageFilter::Create(SkIntToScalar(-16), SkIntToScalar(32)),
            SkImageFilter::CreateMatrixFilter(resizeMatrix, kNone_SkFilterQuality),
            SkRectShaderImageFilter::Create(noise),
>>>>>>> miniblink49
        };

        SkRect r = SkRect::MakeWH(SkIntToScalar(64), SkIntToScalar(64));
        SkScalar margin = SkIntToScalar(16);
        SkRect bounds = r;
        bounds.outset(margin, margin);

<<<<<<< HEAD
        canvas->save();
=======
>>>>>>> miniblink49
        for (int xOffset = 0; xOffset < 80; xOffset += 16) {
            canvas->save();
            bounds.fLeft = SkIntToScalar(xOffset);
            for (size_t i = 0; i < SK_ARRAY_COUNT(filters); ++i) {
<<<<<<< HEAD
                draw_clipped_filter(canvas, filters[i], i, r, bounds);
=======
                SkPaint paint;
                paint.setColor(SK_ColorWHITE);
                paint.setImageFilter(filters[i]);
                paint.setAntiAlias(true);
                canvas->save();
                canvas->clipRect(bounds);
                if (5 == i) {
                    canvas->translate(SkIntToScalar(16), SkIntToScalar(-32));
                } else if (6 == i) {
                    canvas->scale(SkScalarInvert(RESIZE_FACTOR_X),
                                  SkScalarInvert(RESIZE_FACTOR_Y));
                }
                canvas->drawCircle(r.centerX(), r.centerY(), r.width() * 2 / 5, paint);
                canvas->restore();
>>>>>>> miniblink49
                canvas->translate(r.width() + margin, 0);
            }
            canvas->restore();
            canvas->translate(0, r.height() + margin);
        }
<<<<<<< HEAD
        canvas->restore();

        SkPaint noisePaint;
        noisePaint.setShader(SkPerlinNoiseShader::MakeFractalNoise(0.1f, 0.05f, 1, 0));

        sk_sp<SkImageFilter> rectFilter(SkPaintImageFilter::Make(noisePaint));
        canvas->translate(SK_ARRAY_COUNT(filters) * (r.width() + margin), 0);
        for (int xOffset = 0; xOffset < 80; xOffset += 16) {
            bounds.fLeft = SkIntToScalar(xOffset);
            draw_clipped_filter(canvas, rectFilter, 0, r, bounds);
            canvas->translate(0, r.height() + margin);
=======

        for (size_t i = 0; i < SK_ARRAY_COUNT(filters); ++i) {
            SkSafeUnref(filters[i]);
>>>>>>> miniblink49
        }
    }

private:
<<<<<<< HEAD
    sk_sp<SkImage> fCheckerboard, fGradientCircle;

=======
    bool fInitialized;
    SkBitmap fCheckerboard;
    SkBitmap fGradientCircle;
>>>>>>> miniblink49
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new ImageFiltersClippedGM;)
=======
static GM* MyFactory(void*) { return new ImageFiltersClippedGM; }
static GMRegistry reg(MyFactory);

>>>>>>> miniblink49
}
