/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======
#include "gm.h"
>>>>>>> miniblink49
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "gm.h"

#include "SkBlurImageFilter.h"
#include "SkColorFilterImageFilter.h"
=======

#include "SkBitmapSource.h"
#include "SkBlurImageFilter.h"
>>>>>>> miniblink49
#include "SkColorMatrixFilter.h"
#include "SkDisplacementMapEffect.h"
#include "SkDropShadowImageFilter.h"
#include "SkGradientShader.h"
<<<<<<< HEAD
#include "SkImageSource.h"
#include "SkLightingImageFilter.h"
#include "SkMergeImageFilter.h"
#include "SkMorphologyImageFilter.h"
#include "SkOffsetImageFilter.h"
#include "SkPoint3.h"
#include "SkSurface.h"
=======
#include "SkMorphologyImageFilter.h"
#include "SkColorFilterImageFilter.h"
#include "SkMergeImageFilter.h"
#include "SkOffsetImageFilter.h"
>>>>>>> miniblink49

///////////////////////////////////////////////////////////////////////////////

class ImageFiltersCropExpandGM : public skiagm::GM {
public:
<<<<<<< HEAD
    ImageFiltersCropExpandGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("imagefilterscropexpand");
    }

    SkISize onISize() override { return SkISize::Make(730, 650); }

    void onDraw(SkCanvas* canvas) override
    {
        SkImageFilter::CropRect cropRect(
            SkRect::Make(SkIRect::MakeXYWH(10, 10, 44, 44)),
            SkImageFilter::CropRect::kHasAll_CropEdge);

        sk_sp<SkImage> gradientCircle(MakeGradientCircle(64, 64));
        SkBitmap checkerboard;
        MakeCheckerboard(&checkerboard);

        sk_sp<SkImageFilter> gradientCircleSource(SkImageSource::Make(std::move(gradientCircle)));
        sk_sp<SkImageFilter> noopCropped(SkOffsetImageFilter::Make(0, 0, nullptr, &cropRect));
        // This color matrix saturates the green component but only partly increases the opacity.
        // For the opaque checkerboard, the opacity boost doesn't matter but it does impact the
        // area outside the checkerboard.
        SkScalar matrix[20] = { 1, 0, 0, 0, 0,
            0, 1, 0, 0, 255,
            0, 0, 1, 0, 0,
            0, 0, 0, 1, 32 };
        sk_sp<SkColorFilter> cfAlphaTrans(SkColorFilter::MakeMatrixFilterRowMajor255(matrix));

        SkRect r = SkRect::MakeWH(SkIntToScalar(64), SkIntToScalar(64));
        SkScalar MARGIN = SkIntToScalar(12);

        SkPoint3 pointLocation = SkPoint3::Make(0, 0, SkIntToScalar(10));
        SkScalar kd = SkIntToScalar(2);
        SkScalar surfaceScale = SkIntToScalar(1);
        SkIRect bounds;
        r.roundOut(&bounds);

        SkPaint paint;
        canvas->translate(MARGIN, MARGIN);
        for (int outset = -15; outset <= 20; outset += 5) {
            canvas->save();
            SkRect rect = cropRect.rect();
            rect.outset(SkIntToScalar(outset),
                SkIntToScalar(outset));
            SkImageFilter::CropRect bigRect(rect, SkImageFilter::CropRect::kHasAll_CropEdge);

            Draw(canvas, checkerboard, rect, SkColorFilterImageFilter::Make(cfAlphaTrans, noopCropped, &bigRect));

            Draw(canvas, checkerboard, rect, SkBlurImageFilter::Make(0.3f, 0.3f, noopCropped, &bigRect));

            Draw(canvas, checkerboard, rect, SkBlurImageFilter::Make(8.0f, 8.0f, noopCropped, &bigRect));

            Draw(canvas, checkerboard, rect, SkDilateImageFilter::Make(2, 2, noopCropped, &bigRect));

            Draw(canvas, checkerboard, rect, SkErodeImageFilter::Make(2, 2, noopCropped, &bigRect));

            Draw(canvas, checkerboard, rect,
                SkDropShadowImageFilter::Make(
                    SkIntToScalar(10),
                    SkIntToScalar(10),
                    SkIntToScalar(3),
                    SkIntToScalar(3),
                    SK_ColorBLUE,
                    SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode,
                    noopCropped,
                    &bigRect));

            Draw(canvas, checkerboard, rect,
                SkDisplacementMapEffect::Make(SkDisplacementMapEffect::kR_ChannelSelectorType,
                    SkDisplacementMapEffect::kR_ChannelSelectorType,
                    SkIntToScalar(12),
                    gradientCircleSource,
                    noopCropped,
                    &bigRect));

            Draw(canvas, checkerboard, rect,
                SkOffsetImageFilter::Make(SkIntToScalar(-8), SkIntToScalar(16),
                    noopCropped,
                    &bigRect));

            Draw(canvas, checkerboard, rect,
                SkLightingImageFilter::MakePointLitDiffuse(pointLocation,
                    SK_ColorWHITE,
                    surfaceScale,
                    kd,
                    noopCropped,
                    &bigRect));

            canvas->restore();
            canvas->translate(0, SkIntToScalar(80));
        }
    }

private:
    static void MakeCheckerboard(SkBitmap* bitmap)
    {
=======
    ImageFiltersCropExpandGM () {}

protected:

    virtual SkString onShortName() {
        return SkString("imagefilterscropexpand");
    }

    virtual SkISize onISize() { return SkISize::Make(570, 650); }

    void make_checkerboard(SkBitmap* bitmap) {
>>>>>>> miniblink49
        bitmap->allocN32Pixels(64, 64);
        SkCanvas canvas(*bitmap);
        canvas.clear(0xFFFF0000);
        SkPaint darkPaint;
<<<<<<< HEAD
        darkPaint.setColor(sk_tool_utils::color_to_565(0xFF404040));
        SkPaint lightPaint;
        lightPaint.setColor(sk_tool_utils::color_to_565(0xFFA0A0A0));
=======
        darkPaint.setColor(0xFF404040);
        SkPaint lightPaint;
        lightPaint.setColor(0xFFA0A0A0);
>>>>>>> miniblink49
        for (int y = 8; y < 48; y += 16) {
            for (int x = 8; x < 48; x += 16) {
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

<<<<<<< HEAD
    static sk_sp<SkImage> MakeGradientCircle(int width, int height)
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

    static void Draw(SkCanvas* canvas, const SkBitmap& bitmap, const SkRect& rect,
        sk_sp<SkImageFilter> filter)
    {
        SkPaint paint;
        paint.setImageFilter(std::move(filter));
=======
    void make_gradient_circle(int width, int height, SkBitmap* bitmap) {
        SkScalar x = SkIntToScalar(width / 2);
        SkScalar y = SkIntToScalar(height / 2);
        SkScalar radius = SkMinScalar(x, y) * 0.8f;
        bitmap->allocN32Pixels(width, height);
        SkCanvas canvas(*bitmap);
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

    static void draw(SkCanvas* canvas, const SkBitmap& bitmap, const SkRect& rect, SkImageFilter* filter) {
        SkPaint paint;
        paint.setImageFilter(filter)->unref();
>>>>>>> miniblink49
        canvas->saveLayer(&rect, &paint);
        canvas->drawBitmap(bitmap, 0, 0);
        canvas->restore();

        SkPaint strokePaint;
        strokePaint.setColor(0xFFFF0000);
        strokePaint.setStyle(SkPaint::kStroke_Style);
        canvas->drawRect(rect, strokePaint);

        canvas->translate(SkIntToScalar(80), 0);
    }

<<<<<<< HEAD
=======
    virtual void onDraw(SkCanvas* canvas) {
        SkAutoTUnref<SkColorFilter> cf(
            SkColorFilter::CreateModeFilter(SK_ColorBLUE, SkXfermode::kSrcIn_Mode));
        SkImageFilter::CropRect crop_rect(
            SkRect::Make(SkIRect::MakeXYWH(10, 10, 44, 44)),
            SkImageFilter::CropRect::kHasAll_CropEdge);

        SkBitmap gradient_circle, checkerboard;
        make_gradient_circle(64, 64, &gradient_circle);
        make_checkerboard(&checkerboard);

        SkAutoTUnref<SkImageFilter> gradient_circle_source(
            SkBitmapSource::Create(gradient_circle));
        SkAutoTUnref<SkImageFilter> noop_cropped(
            SkOffsetImageFilter::Create(0, 0, NULL, &crop_rect));
        SkScalar sk255 = SkIntToScalar(255);
        SkScalar matrix[20] = { 1, 0, 0, 0, 0,
                                0, 1, 0, 0, sk255,
                                0, 0, 1, 0, 0,
                                0, 0, 0, 0, sk255 };
        SkAutoTUnref<SkColorFilter> cf_alpha_trans(SkColorMatrixFilter::Create(matrix));

        SkRect r = SkRect::MakeWH(SkIntToScalar(64), SkIntToScalar(64));
        SkScalar MARGIN = SkIntToScalar(12);

        SkIRect bounds;
        r.roundOut(&bounds);

        SkPaint paint;
        canvas->translate(MARGIN, MARGIN);
        for (int outset = -15; outset <= 20; outset += 5) {
            canvas->save();
            SkRect rect = crop_rect.rect();
            rect.outset(SkIntToScalar(outset),
                        SkIntToScalar(outset));
            SkImageFilter::CropRect big_rect(rect, SkImageFilter::CropRect::kHasAll_CropEdge);

            draw(canvas, checkerboard, rect, SkColorFilterImageFilter::Create(
                cf_alpha_trans, noop_cropped.get(), &big_rect));

            draw(canvas, checkerboard, rect, SkBlurImageFilter::Create(
                8.0f, 8.0f, noop_cropped.get(), &big_rect));

            draw(canvas, checkerboard, rect, SkDilateImageFilter::Create(
                2, 2, noop_cropped.get(), &big_rect));

            draw(canvas, checkerboard, rect, SkErodeImageFilter::Create(
                2, 2, noop_cropped.get(), &big_rect));

            draw(canvas, checkerboard, rect, SkDropShadowImageFilter::Create(
                SkIntToScalar(10), SkIntToScalar(10), SkIntToScalar(3), SkIntToScalar(3),
                SK_ColorBLUE, SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode,
                noop_cropped.get(), &big_rect));

            draw(canvas, checkerboard, rect, SkDisplacementMapEffect::Create(
                SkDisplacementMapEffect::kR_ChannelSelectorType,
                SkDisplacementMapEffect::kR_ChannelSelectorType,
                SkIntToScalar(12),
                gradient_circle_source.get(),
                noop_cropped.get(),
                &big_rect));

            draw(canvas, checkerboard, rect, SkOffsetImageFilter::Create(
                SkIntToScalar(-8), SkIntToScalar(16), noop_cropped.get(), &big_rect));

            canvas->restore();
            canvas->translate(0, SkIntToScalar(80));
        }
    }

private:
>>>>>>> miniblink49
    typedef GM INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new ImageFiltersCropExpandGM;)
=======
static skiagm::GM* MyFactory(void*) { return new ImageFiltersCropExpandGM; }
static skiagm::GMRegistry reg(MyFactory);
>>>>>>> miniblink49
