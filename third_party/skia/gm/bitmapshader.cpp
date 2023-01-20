<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "gm.h"

#include "SkBitmap.h"
#include "SkPaint.h"
#include "SkShader.h"

namespace skiagm {

<<<<<<< HEAD
static void draw_bm(SkBitmap* bm)
{
=======
static void draw_bm(SkBitmap* bm) {
>>>>>>> miniblink49
    SkPaint bluePaint;
    bluePaint.setColor(SK_ColorBLUE);

    bm->allocN32Pixels(20, 20);
    bm->eraseColor(SK_ColorRED);

    SkCanvas canvas(*bm);
    canvas.drawCircle(10, 10, 5, bluePaint);
}

<<<<<<< HEAD
static void draw_mask(SkBitmap* bm)
{
=======
static void draw_mask(SkBitmap* bm) {
>>>>>>> miniblink49
    SkPaint circlePaint;
    circlePaint.setColor(SK_ColorBLACK);

    bm->allocPixels(SkImageInfo::MakeA8(20, 20));
    bm->eraseColor(SK_ColorTRANSPARENT);

    SkCanvas canvas(*bm);
    canvas.drawCircle(10, 10, 10, circlePaint);
}

<<<<<<< HEAD
class BitmapShaderGM : public GM {

protected:
    void onOnceBeforeDraw() override
    {
        this->setBGColor(sk_tool_utils::color_to_565(SK_ColorGRAY));
=======
static void adopt_shader(SkPaint* paint, SkShader* shader) {
    paint->setShader(shader);
    SkSafeUnref(shader);
}

class BitmapShaderGM : public GM {

protected:
    void onOnceBeforeDraw() override {
        this->setBGColor(SK_ColorGRAY);
>>>>>>> miniblink49
        draw_bm(&fBitmap);
        draw_mask(&fMask);
    }

<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("bitmapshaders");
    }

    SkISize onISize() override
    {
        return SkISize::Make(150, 100);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
    virtual SkString onShortName() {
        return SkString("bitmapshaders");
    }

    virtual SkISize onISize() {
        return SkISize::Make(150, 100);
    }

    virtual void onDraw(SkCanvas* canvas) {
>>>>>>> miniblink49
        SkPaint paint;

        for (int i = 0; i < 2; i++) {
            SkMatrix s;
            s.reset();
            if (1 == i) {
                s.setScale(1.5f, 1.5f);
                s.postTranslate(2, 2);
            }

            canvas->save();
<<<<<<< HEAD
            paint.setShader(SkShader::MakeBitmapShader(fBitmap, SkShader::kClamp_TileMode,
                SkShader::kClamp_TileMode, &s));
=======
            adopt_shader(&paint, SkShader::CreateBitmapShader(fBitmap, SkShader::kClamp_TileMode,
                                                              SkShader::kClamp_TileMode, &s));
>>>>>>> miniblink49

            // draw the shader with a bitmap mask
            canvas->drawBitmap(fMask, 0, 0, &paint);
            canvas->drawBitmap(fMask, 30, 0, &paint);

            canvas->translate(0, 25);

            canvas->drawCircle(10, 10, 10, paint);
            canvas->drawCircle(40, 10, 10, paint); // no blue circle expected

            canvas->translate(0, 25);

            // clear the shader, colorized by a solid color with a bitmap mask
<<<<<<< HEAD
            paint.setShader(nullptr);
=======
            paint.setShader(NULL);
>>>>>>> miniblink49
            paint.setColor(SK_ColorGREEN);
            canvas->drawBitmap(fMask, 0, 0, &paint);
            canvas->drawBitmap(fMask, 30, 0, &paint);

            canvas->translate(0, 25);

<<<<<<< HEAD
            paint.setShader(SkShader::MakeBitmapShader(fMask, SkShader::kRepeat_TileMode,
                SkShader::kRepeat_TileMode, &s));
=======
            adopt_shader(&paint, SkShader::CreateBitmapShader(fMask, SkShader::kRepeat_TileMode,
                                                              SkShader::kRepeat_TileMode, &s));
>>>>>>> miniblink49
            paint.setColor(SK_ColorRED);

            // draw the mask using the shader and a color
            canvas->drawRect(SkRect::MakeXYWH(0, 0, 20, 20), paint);
            canvas->drawRect(SkRect::MakeXYWH(30, 0, 20, 20), paint);
            canvas->restore();
            canvas->translate(60, 0);
        }
    }

private:
    SkBitmap fBitmap;
    SkBitmap fMask;

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new BitmapShaderGM; }
static GMRegistry reg(MyFactory);

}
