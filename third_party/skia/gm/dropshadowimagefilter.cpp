/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkColorFilter.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkColorFilter.h"
>>>>>>> miniblink49

#include "SkColorFilterImageFilter.h"
#include "SkDropShadowImageFilter.h"

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static void draw_paint(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imf)
{
    SkPaint paint;
    paint.setImageFilter(std::move(imf));
=======
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
    paint.setColor(SK_ColorGREEN);
    paint.setImageFilter(std::move(imf));
    paint.setAntiAlias(true);
    canvas->save();
    canvas->clipRect(r);
    canvas->drawCircle(r.centerX(), r.centerY(), r.width() / 3, paint);
    canvas->restore();
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
    paint.setColor(SK_ColorGREEN);
    paint.setImageFilter(imf);
    paint.setAntiAlias(true);
    canvas->save();
    canvas->clipRect(r);
    canvas->drawCircle(r.centerX(), r.centerY(), r.width()/3, paint);
    canvas->restore();
}

static void draw_text(SkCanvas* canvas, const SkRect& r, SkImageFilter* imf) {
    SkPaint paint;
    paint.setImageFilter(imf);
    paint.setColor(SK_ColorGREEN);
    paint.setAntiAlias(true);
    sk_tool_utils::set_portable_typeface(&paint);
    paint.setTextSize(r.height()/2);
>>>>>>> miniblink49
    paint.setTextAlign(SkPaint::kCenter_Align);
    canvas->save();
    canvas->clipRect(r);
    canvas->drawText("Text", 4, r.centerX(), r.centerY(), paint);
    canvas->restore();
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
=======
    draw_path(&c, r, NULL);

    paint.setImageFilter(imf);
>>>>>>> miniblink49
    canvas->save();
    canvas->clipRect(r);
    canvas->drawBitmap(bm, 0, 0, &paint);
    canvas->restore();
}

<<<<<<< HEAD
=======
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

class DropShadowImageFilterGM : public skiagm::GM {
public:
<<<<<<< HEAD
    DropShadowImageFilterGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("dropshadowimagefilter");
    }

    SkISize onISize() override { return SkISize::Make(400, 656); }

    void onDraw(SkCanvas* canvas) override
    {
        void (*drawProc[])(SkCanvas*, const SkRect&, sk_sp<SkImageFilter>) = {
            draw_bitmap, draw_path, draw_paint, draw_text
        };

        sk_sp<SkColorFilter> cf(SkColorFilter::MakeModeFilter(SK_ColorMAGENTA,
            SkXfermode::kSrcIn_Mode));
        sk_sp<SkImageFilter> cfif(SkColorFilterImageFilter::Make(std::move(cf), nullptr));
        SkImageFilter::CropRect cropRect(SkRect::Make(SkIRect::MakeXYWH(10, 10, 44, 44)),
            SkImageFilter::CropRect::kHasAll_CropEdge);
        SkImageFilter::CropRect bogusRect(SkRect::Make(SkIRect::MakeXYWH(-100, -100, 10, 10)),
            SkImageFilter::CropRect::kHasAll_CropEdge);

        sk_sp<SkImageFilter> filters[] = {
            nullptr,
            SkDropShadowImageFilter::Make(7.0f, 0.0f, 0.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, nullptr),
            SkDropShadowImageFilter::Make(0.0f, 7.0f, 3.0f, 0.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, nullptr),
            SkDropShadowImageFilter::Make(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, nullptr),
            SkDropShadowImageFilter::Make(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, std::move(cfif)),
            SkDropShadowImageFilter::Make(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, nullptr, &cropRect),
            SkDropShadowImageFilter::Make(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, nullptr, &bogusRect),
            SkDropShadowImageFilter::Make(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowOnly_ShadowMode, nullptr),
=======
    DropShadowImageFilterGM () {}

protected:

    virtual SkString onShortName() {
        return SkString("dropshadowimagefilter");
    }

    virtual SkISize onISize() { return SkISize::Make(400, 656); }

    void draw_frame(SkCanvas* canvas, const SkRect& r) {
        SkPaint paint;
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setColor(SK_ColorRED);
        canvas->drawRect(r, paint);
    }

    virtual void onDraw(SkCanvas* canvas) {
        void (*drawProc[])(SkCanvas*, const SkRect&, SkImageFilter*) = {
            draw_sprite, draw_bitmap, draw_path, draw_paint, draw_text
        };

        SkAutoTUnref<SkColorFilter> cf(
            SkColorFilter::CreateModeFilter(SK_ColorMAGENTA, SkXfermode::kSrcIn_Mode));
        SkAutoTUnref<SkImageFilter> cfif(SkColorFilterImageFilter::Create(cf.get()));
        SkImageFilter::CropRect cropRect(SkRect::Make(SkIRect::MakeXYWH(10, 10, 44, 44)),
                                         SkImageFilter::CropRect::kHasAll_CropEdge);
        SkImageFilter::CropRect bogusRect(SkRect::Make(SkIRect::MakeXYWH(-100, -100, 10, 10)),
                                          SkImageFilter::CropRect::kHasAll_CropEdge);

        SkImageFilter* filters[] = {
            NULL,
            SkDropShadowImageFilter::Create(7.0f, 0.0f, 0.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode),
            SkDropShadowImageFilter::Create(0.0f, 7.0f, 3.0f, 0.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode),
            SkDropShadowImageFilter::Create(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode),
            SkDropShadowImageFilter::Create(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, cfif, NULL),
            SkDropShadowImageFilter::Create(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, NULL, &cropRect),
            SkDropShadowImageFilter::Create(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, NULL, &bogusRect),
            SkDropShadowImageFilter::Create(7.0f, 7.0f, 3.0f, 3.0f, SK_ColorBLUE,
                SkDropShadowImageFilter::kDrawShadowOnly_ShadowMode),
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
    typedef GM INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new DropShadowImageFilterGM;)
=======
static skiagm::GM* MyFactory(void*) { return new DropShadowImageFilterGM; }
static skiagm::GMRegistry reg(MyFactory);
>>>>>>> miniblink49
