/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkPath.h"
#include "SkPictureRecorder.h"
#include "SkSurface.h"
#include "gm.h"

static void draw(SkCanvas* canvas, int width, int height, SkColor colors[2])
{
    const SkPoint center = { SkIntToScalar(width) / 2, SkIntToScalar(height) / 2 };
    const SkScalar radius = 40;
    SkPaint paint;
    paint.setShader(SkGradientShader::MakeRadial(center, radius, colors, nullptr, 2,
        SkShader::kMirror_TileMode));
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    canvas->drawPaint(paint);
}

static sk_sp<SkImage> make_raster_image(int width, int height, SkColor colors[2])
{
    auto surface(SkSurface::MakeRasterN32Premul(width, height));
    draw(surface->getCanvas(), width, height, colors);
    return surface->makeImageSnapshot();
}

static sk_sp<SkImage> make_picture_image(int width, int height, SkColor colors[2])
{
    SkPictureRecorder recorder;
    draw(recorder.beginRecording(SkRect::MakeIWH(width, height)), width, height, colors);
    return SkImage::MakeFromPicture(recorder.finishRecordingAsPicture(),
        SkISize::Make(width, height), nullptr, nullptr);
}

typedef sk_sp<SkImage> (*ImageMakerProc)(int width, int height, SkColor colors[2]);

static void show_image(SkCanvas* canvas, int width, int height, SkColor colors[2],
    ImageMakerProc proc)
{
    sk_sp<SkImage> image(proc(width, height, colors));
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkPath.h"

static void make_bm(SkBitmap* bm, int width, int height, SkColor colors[2]) {
    bm->allocN32Pixels(width, height);
    SkCanvas canvas(*bm);
    SkPoint center = {SkIntToScalar(width)/2, SkIntToScalar(height)/2};
    SkScalar radius = 40;
    SkShader* shader = SkGradientShader::CreateRadial(center, radius, colors, NULL, 2,
                                                      SkShader::kMirror_TileMode);
    SkPaint paint;
    paint.setShader(shader)->unref();
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    canvas.drawPaint(paint);
    bm->setImmutable();
}

static void show_bm(SkCanvas* canvas, int width, int height, SkColor colors[2]) {
    SkBitmap bm;
    make_bm(&bm, width, height, colors);
>>>>>>> miniblink49

    SkPaint paint;
    SkRect r;
    SkIRect ir;

    paint.setStyle(SkPaint::kStroke_Style);

    ir.set(0, 0, 128, 128);
    r.set(ir);

    canvas->save();
    canvas->clipRect(r);
<<<<<<< HEAD
    canvas->drawImage(image, 0, 0, nullptr);
=======
    canvas->drawBitmap(bm, 0, 0, NULL);
>>>>>>> miniblink49
    canvas->restore();
    canvas->drawRect(r, paint);

    r.offset(SkIntToScalar(150), 0);
<<<<<<< HEAD
    canvas->drawImageRect(image, ir, r, nullptr);
    canvas->drawRect(r, paint);

    r.offset(SkIntToScalar(150), 0);
    canvas->drawImageRect(image, r, nullptr);
=======
    // exercises extract bitmap, but not shader
    canvas->drawBitmapRect(bm, &ir, r, NULL);
    canvas->drawRect(r, paint);

    r.offset(SkIntToScalar(150), 0);
    // exercises bitmapshader
    canvas->drawBitmapRect(bm, NULL, r, NULL);
>>>>>>> miniblink49
    canvas->drawRect(r, paint);
}

class VeryLargeBitmapGM : public skiagm::GM {
<<<<<<< HEAD
    ImageMakerProc fProc;
    SkString fName;

public:
    VeryLargeBitmapGM(ImageMakerProc proc, const char suffix[])
        : fProc(proc)
    {
        fName.printf("verylarge%s", suffix);
    }

protected:
    SkString onShortName() override
    {
        return fName;
    }

    SkISize onISize() override
    {
        return SkISize::Make(500, 600);
    }

    void onDraw(SkCanvas* canvas) override
    {
        int veryBig = 65 * 1024; // 64K < size
        int big = 33 * 1024; // 32K < size < 64K
        // smaller than many max texture sizes, but large enough to gpu-tile for memory reasons.
        int medium = 5 * 1024;
=======
public:
    VeryLargeBitmapGM() {}

protected:
    SkString onShortName() override {
        return SkString("verylargebitmap");
    }

    SkISize onISize() override {
        return SkISize::Make(500, 600);
    }

    void onDraw(SkCanvas* canvas) override {
        int veryBig = 65*1024; // 64K < size
        int big = 33*1024;     // 32K < size < 64K
        // smaller than many max texture sizes, but large enough to gpu-tile for memory reasons.
        int medium = 5*1024;
>>>>>>> miniblink49
        int small = 150;

        SkColor colors[2];

        canvas->translate(SkIntToScalar(10), SkIntToScalar(10));
        colors[0] = SK_ColorRED;
        colors[1] = SK_ColorGREEN;
<<<<<<< HEAD
        show_image(canvas, small, small, colors, fProc);
=======
        show_bm(canvas, small, small, colors);
>>>>>>> miniblink49
        canvas->translate(0, SkIntToScalar(150));

        colors[0] = SK_ColorBLUE;
        colors[1] = SK_ColorMAGENTA;
<<<<<<< HEAD
        show_image(canvas, big, small, colors, fProc);
=======
        show_bm(canvas, big, small, colors);
>>>>>>> miniblink49
        canvas->translate(0, SkIntToScalar(150));

        colors[0] = SK_ColorMAGENTA;
        colors[1] = SK_ColorYELLOW;
<<<<<<< HEAD
        show_image(canvas, medium, medium, colors, fProc);
=======
        show_bm(canvas, medium, medium, colors);
>>>>>>> miniblink49
        canvas->translate(0, SkIntToScalar(150));

        colors[0] = SK_ColorGREEN;
        colors[1] = SK_ColorYELLOW;
        // as of this writing, the raster code will fail to draw the scaled version
        // since it has a 64K limit on x,y coordinates... (but gpu should succeed)
<<<<<<< HEAD
        show_image(canvas, veryBig, small, colors, fProc);
=======
        show_bm(canvas, veryBig, small, colors);
>>>>>>> miniblink49
    }

private:
    typedef skiagm::GM INHERITED;
};
<<<<<<< HEAD
DEF_GM(return new VeryLargeBitmapGM(make_raster_image, "bitmap");)
DEF_GM(return new VeryLargeBitmapGM(make_picture_image, "_picture_image");)
=======

//////////////////////////////////////////////////////////////////////////////

static skiagm::GM* MyFactory(void*) { return new VeryLargeBitmapGM; }
static skiagm::GMRegistry reg(MyFactory);
>>>>>>> miniblink49
