/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBlurImageFilter.h"
#include "SkCanvas.h"
#include "SkRSXform.h"
#include "SkSurface.h"
#include "gm.h"

static void make_bm(SkBitmap* bm)
{
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkBlurImageFilter.h"
#include "SkRSXform.h"
#include "SkSurface.h"

static void make_bm(SkBitmap* bm) {
>>>>>>> miniblink49
    bm->allocN32Pixels(100, 100);
    bm->eraseColor(SK_ColorBLUE);

    SkCanvas canvas(*bm);
    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setColor(SK_ColorRED);
    canvas.drawCircle(50, 50, 50, paint);
}

<<<<<<< HEAD
static void draw_1_bitmap(SkCanvas* canvas, const SkBitmap& bm, bool doClip,
    int dx, int dy, sk_sp<SkImageFilter> filter)
{
=======
static void draw_2_bitmaps(SkCanvas* canvas, const SkBitmap& bm, bool doClip,
                           int dx, int dy, SkImageFilter* filter = NULL) {
>>>>>>> miniblink49
    SkAutoCanvasRestore acr(canvas, true);
    SkPaint paint;

    SkRect clipR = SkRect::MakeXYWH(SkIntToScalar(dx),
<<<<<<< HEAD
        SkIntToScalar(dy),
        SkIntToScalar(bm.width()),
        SkIntToScalar(bm.height()));

    paint.setImageFilter(std::move(filter));
    clipR.inset(5, 5);

=======
                                    SkIntToScalar(dy),
                                    SkIntToScalar(bm.width()),
                                    SkIntToScalar(bm.height()));

    paint.setImageFilter(filter);
    clipR.inset(5, 5);

    if (doClip) {
        canvas->save();
        canvas->clipRect(clipR);
    }
    canvas->drawSprite(bm, dx, dy, &paint);
    if (doClip) {
        canvas->restore();
    }

>>>>>>> miniblink49
    canvas->translate(SkIntToScalar(bm.width() + 20), 0);

    if (doClip) {
        canvas->save();
        canvas->clipRect(clipR);
    }
    canvas->drawBitmap(bm, SkIntToScalar(dx), SkIntToScalar(dy), &paint);
    if (doClip) {
        canvas->restore();
    }
}

/**
 *  Compare output of drawSprite and drawBitmap (esp. clipping and imagefilters)
 */
class SpriteBitmapGM : public skiagm::GM {
public:
<<<<<<< HEAD
    SpriteBitmapGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("spritebitmap");
    }

    SkISize onISize() override
    {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
    SpriteBitmapGM() {}

protected:

    SkString onShortName() override {
        return SkString("spritebitmap");
    }

    SkISize onISize() override {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkBitmap bm;
        make_bm(&bm);

        int dx = 10;
        int dy = 10;

        SkScalar sigma = 8;
<<<<<<< HEAD
        sk_sp<SkImageFilter> filter(SkBlurImageFilter::Make(sigma, sigma, nullptr));

        draw_1_bitmap(canvas, bm, false, dx, dy, nullptr);
        dy += bm.height() + 20;
        draw_1_bitmap(canvas, bm, false, dx, dy, filter);
        dy += bm.height() + 20;
        draw_1_bitmap(canvas, bm, true, dx, dy, nullptr);
        dy += bm.height() + 20;
        draw_1_bitmap(canvas, bm, true, dx, dy, filter);
=======
        SkAutoTUnref<SkImageFilter> filter(SkBlurImageFilter::Create(sigma, sigma));

        draw_2_bitmaps(canvas, bm, false, dx, dy);
        dy += bm.height() + 20;
        draw_2_bitmaps(canvas, bm, false, dx, dy, filter);
        dy += bm.height() + 20;
        draw_2_bitmaps(canvas, bm, true, dx, dy);
        dy += bm.height() + 20;
        draw_2_bitmaps(canvas, bm, true, dx, dy, filter);
>>>>>>> miniblink49
    }

private:
    typedef GM INHERITED;
};
<<<<<<< HEAD
DEF_GM(return new SpriteBitmapGM;)
=======
DEF_GM( return new SpriteBitmapGM; )

>>>>>>> miniblink49
