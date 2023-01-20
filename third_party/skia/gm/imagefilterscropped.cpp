/*
 * Copyright 2011 Google Inc.
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
#include "SkMergeImageFilter.h"
#include "SkMorphologyImageFilter.h"
#include "SkOffsetImageFilter.h"

///////////////////////////////////////////////////////////////////////////////

static void draw_paint(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
    SkPaint paint;
    paint.setImageFilter(std::move(imf));
=======

#include "SkBlurImageFilter.h"
#include "SkMorphologyImageFilter.h"
#include "SkColorFilterImageFilter.h"
#include "SkBitmapSource.h"
#include "SkMergeImageFilter.h"
#include "SkOffsetImageFilter.h"
#include "SkTestImageFilters.h"

///////////////////////////////////////////////////////////////////////////////

static void draw_paint(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
    SkPaint paint;
    paint.setImageFilter(imf);
>>>>>>> miniblink49
    paint.setColor(SK_ColorBLACK);
    canvas->save();
    canvas->clipRect(r);
    canvas->drawPaint(paint);
    canvas->restore();
}

<<<<<<< HEAD
static void draw_path(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
    SkPaint paint;
    paint.setColor(SK_ColorMAGENTA);
    paint.setImageFilter(std::move(imf));
    paint.setAntiAlias(true);
    canvas->drawCircle(r.centerX(), r.centerY(), r.width() * 2 / 5, paint);
}

static void draw_text(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
    SkPaint paint;
    paint.setImageFilter(std::move(imf));
    paint.setColor(SK_ColorGREEN);
    paint.setAntiAlias(true);
    sk_tool_utils::set_portable_typeface(&paint);
    paint.setTextSize(r.height() / 2);
=======
static void draw_path(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
    SkPaint paint;
    paint.setColor(SK_ColorMAGENTA);
    paint.setImageFilter(imf);
    paint.setAntiAlias(true);
    canvas->drawCircle(r.centerX(), r.centerY(), r.width()*2/5, paint);
}

static void draw_text(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
    SkPaint paint;
    paint.setImageFilter(imf);
    paint.setColor(SK_ColorGREEN);
    paint.setAntiAlias(true);
    sk_tool_utils::set_portable_typeface_always(&paint);
    paint.setTextSize(r.height()/2);
>>>>>>> miniblink49
    paint.setTextAlign(SkPaint::kCenter_Align);
    canvas->drawText("Text", 4, r.centerX(), r.centerY(), paint);
}

<<<<<<< HEAD
static void draw_bitmap(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
=======
static void draw_bitmap(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
>>>>>>> miniblink49
    SkPaint paint;

    SkIRect bounds;
    r.roundOut(&bounds);

    SkBitmap bm;
    bm.allocN32Pixels(bounds.width(), bounds.height());
    bm.eraseColor(SK_ColorTRANSPARENT);
    SkCanvas c(bm);
<<<<<<< HEAD
    draw_path(&c, r, nullptr);

    paint.setImageFilter(std::move(imf));
    canvas->drawBitmap(bm, 0, 0, &paint);
}

=======
    draw_path(&c, r, NULL);

    paint.setImageFilter(imf);
    canvas->drawBitmap(bm, 0, 0, &paint);
}

static void draw_sprite(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
    SkPaint paint;

    SkIRect bounds;
    r.roundOut(&bounds);

    SkBitmap bm;
    bm.allocN32Pixels(bounds.width(), bounds.height());
    bm.eraseColor(SK_ColorRED);
    SkCanvas c(bm);

    SkIRect cropRect = SkIRect::MakeXYWH(10, 10, 44, 44);
    paint.setColor(SK_ColorGREEN);
    c.drawRect(SkRect::Make(cropRect), paint);

    paint.setImageFilter(imf);
    SkPoint loc = { r.fLeft, r.fTop };
    canvas->getTotalMatrix().mapPoints(&loc, 1);
    canvas->drawSprite(bm,
                       SkScalarRoundToInt(loc.fX), SkScalarRoundToInt(loc.fY),
                       &paint);
}

>>>>>>> miniblink49
///////////////////////////////////////////////////////////////////////////////

class ImageFiltersCroppedGM : public skiagm::GM {
public:
<<<<<<< HEAD
    ImageFiltersCroppedGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("imagefilterscropped");
    }

    SkISize onISize() override { return SkISize::Make(400, 960); }

    void make_checkerboard()
    {
=======
    ImageFiltersCroppedGM () {}

protected:
    virtual SkString onShortName() override {
        return SkString("imagefilterscropped");
    }

    virtual SkISize onISize() override { return SkISize::Make(400, 880); }

    void make_checkerboard() {
>>>>>>> miniblink49
        fCheckerboard.allocN32Pixels(80, 80);
        SkCanvas canvas(fCheckerboard);
        canvas.clear(SK_ColorTRANSPARENT);
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
        for (int y = 0; y < 80; y += 16) {
            for (int x = 0; x < 80; x += 16) {
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
    void draw_frame(SkCanvas* canvas, const SkRect& r)
    {
=======
    void draw_frame(SkCanvas* canvas, const SkRect& r) {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setColor(SK_ColorRED);
        canvas->drawRect(r, paint);
    }

<<<<<<< HEAD
    void onOnceBeforeDraw() override
    {
        make_checkerboard();
    }

    void onDraw(SkCanvas* canvas) override
    {
        void (*drawProc[])(SkCanvas*, const SkRect&, sk_sp<SkImageFilter>) = {
            draw_bitmap, draw_path, draw_paint, draw_text
        };

        sk_sp<SkColorFilter> cf(SkColorFilter::MakeModeFilter(SK_ColorBLUE,
            SkXfermode::kSrcIn_Mode));
        SkImageFilter::CropRect cropRect(SkRect::Make(SkIRect::MakeXYWH(10, 10, 44, 44)),
            SkImageFilter::CropRect::kHasAll_CropEdge);
        SkImageFilter::CropRect bogusRect(SkRect::Make(SkIRect::MakeXYWH(-100, -100, 10, 10)),
            SkImageFilter::CropRect::kHasAll_CropEdge);

        sk_sp<SkImageFilter> offset(SkOffsetImageFilter::Make(SkIntToScalar(-10),
            SkIntToScalar(-10),
            nullptr));

        sk_sp<SkImageFilter> cfOffset(SkColorFilterImageFilter::Make(cf, std::move(offset)));

        sk_sp<SkImageFilter> erodeX(SkErodeImageFilter::Make(8, 0, nullptr, &cropRect));
        sk_sp<SkImageFilter> erodeY(SkErodeImageFilter::Make(0, 8, nullptr, &cropRect));

        sk_sp<SkImageFilter> filters[] = {
            nullptr,
            SkColorFilterImageFilter::Make(cf, nullptr, &cropRect),
            SkBlurImageFilter::Make(0.0f, 0.0f, nullptr, &cropRect),
            SkBlurImageFilter::Make(1.0f, 1.0f, nullptr, &cropRect),
            SkBlurImageFilter::Make(8.0f, 0.0f, nullptr, &cropRect),
            SkBlurImageFilter::Make(0.0f, 8.0f, nullptr, &cropRect),
            SkBlurImageFilter::Make(8.0f, 8.0f, nullptr, &cropRect),
            SkErodeImageFilter::Make(1, 1, nullptr, &cropRect),
            SkErodeImageFilter::Make(8, 0, std::move(erodeY), &cropRect),
            SkErodeImageFilter::Make(0, 8, std::move(erodeX), &cropRect),
            SkErodeImageFilter::Make(8, 8, nullptr, &cropRect),
            SkMergeImageFilter::Make(nullptr,
                std::move(cfOffset),
                SkXfermode::kSrcOver_Mode,
                &cropRect),
            SkBlurImageFilter::Make(8.0f, 8.0f, nullptr, &bogusRect),
            SkColorFilterImageFilter::Make(cf, nullptr, &bogusRect),
=======
    virtual void onOnceBeforeDraw() override{
        make_checkerboard();
    }

    virtual void onDraw(SkCanvas* canvas) override {
        void (*drawProc[])(SkCanvas*, const SkRect&, SkImageFilter*) = {
            draw_sprite, draw_bitmap, draw_path, draw_paint, draw_text
        };

        SkAutoTUnref<SkColorFilter> cf(
            SkColorFilter::CreateModeFilter(SK_ColorBLUE, SkXfermode::kSrcIn_Mode));
        SkImageFilter::CropRect cropRect(SkRect::Make(SkIRect::MakeXYWH(10, 10, 44, 44)), SkImageFilter::CropRect::kHasAll_CropEdge);
        SkImageFilter::CropRect bogusRect(SkRect::Make(SkIRect::MakeXYWH(-100, -100, 10, 10)), SkImageFilter::CropRect::kHasAll_CropEdge);

        SkAutoTUnref<SkImageFilter> offset(SkOffsetImageFilter::Create(
            SkIntToScalar(-10), SkIntToScalar(-10)));

        SkAutoTUnref<SkImageFilter> cfOffset(SkColorFilterImageFilter::Create(cf.get(), offset.get()));

        SkAutoTUnref<SkImageFilter> erodeX(SkErodeImageFilter::Create(8, 0, NULL, &cropRect));
        SkAutoTUnref<SkImageFilter> erodeY(SkErodeImageFilter::Create(0, 8, NULL, &cropRect));

        SkImageFilter* filters[] = {
            NULL,
            SkColorFilterImageFilter::Create(cf.get(), NULL, &cropRect),
            SkBlurImageFilter::Create(1.0f, 1.0f, NULL, &cropRect),
            SkBlurImageFilter::Create(8.0f, 0.0f, NULL, &cropRect),
            SkBlurImageFilter::Create(0.0f, 8.0f, NULL, &cropRect),
            SkBlurImageFilter::Create(8.0f, 8.0f, NULL, &cropRect),
            SkErodeImageFilter::Create(1, 1, NULL, &cropRect),
            SkErodeImageFilter::Create(8, 0, erodeY, &cropRect),
            SkErodeImageFilter::Create(0, 8, erodeX, &cropRect),
            SkErodeImageFilter::Create(8, 8, NULL, &cropRect),
            SkMergeImageFilter::Create(NULL, cfOffset.get(), SkXfermode::kSrcOver_Mode, &cropRect),
            SkBlurImageFilter::Create(8.0f, 8.0f, NULL, &bogusRect),
            SkColorFilterImageFilter::Create(cf.get(), NULL, &bogusRect),
>>>>>>> miniblink49
        };

        SkRect r = SkRect::MakeWH(SkIntToScalar(64), SkIntToScalar(64));
        SkScalar MARGIN = SkIntToScalar(16);
        SkScalar DX = r.width() + MARGIN;
        SkScalar DY = r.height() + MARGIN;

        canvas->translate(MARGIN, MARGIN);
        for (size_t j = 0; j < SK_ARRAY_COUNT(drawProc); ++j) {
            canvas->save();
            for (size_t i = 0; i < SK_ARRAY_COUNT(filters); ++i) {
                SkPaint paint;
                canvas->drawBitmap(fCheckerboard, 0, 0);
                drawProc[j](canvas, r, filters[i]);
                canvas->translate(0, DY);
            }
            canvas->restore();
            canvas->translate(DX, 0);
        }
<<<<<<< HEAD
=======

        for(size_t j = 0; j < SK_ARRAY_COUNT(filters); ++j) {
            SkSafeUnref(filters[j]);
        }
>>>>>>> miniblink49
    }

private:
    SkBitmap fCheckerboard;
    typedef GM INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new ImageFiltersCroppedGM;)
=======
static skiagm::GM* MyFactory(void*) { return new ImageFiltersCroppedGM; }
static skiagm::GMRegistry reg(MyFactory);
>>>>>>> miniblink49
