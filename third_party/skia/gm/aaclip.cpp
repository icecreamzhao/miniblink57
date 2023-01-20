/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkPath.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkPath.h"
>>>>>>> miniblink49

/** Draw a 2px border around the target, then red behind the target;
    set the clip to match the target, then draw >> the target in blue.
*/

<<<<<<< HEAD
static void draw(SkCanvas* canvas, SkRect& target, int x, int y)
{
=======
static void draw(SkCanvas* canvas, SkRect& target, int x, int y) {
>>>>>>> miniblink49
    SkPaint borderPaint;
    borderPaint.setColor(SkColorSetRGB(0x0, 0xDD, 0x0));
    borderPaint.setAntiAlias(true);
    SkPaint backgroundPaint;
    backgroundPaint.setColor(SkColorSetRGB(0xDD, 0x0, 0x0));
    backgroundPaint.setAntiAlias(true);
    SkPaint foregroundPaint;
    foregroundPaint.setColor(SkColorSetRGB(0x0, 0x0, 0xDD));
    foregroundPaint.setAntiAlias(true);

    canvas->save();
    canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
    target.inset(SkIntToScalar(-2), SkIntToScalar(-2));
    canvas->drawRect(target, borderPaint);
    target.inset(SkIntToScalar(2), SkIntToScalar(2));
    canvas->drawRect(target, backgroundPaint);
    canvas->clipRect(target, SkRegion::kIntersect_Op, true);
    target.inset(SkIntToScalar(-4), SkIntToScalar(-4));
    canvas->drawRect(target, foregroundPaint);
    canvas->restore();
}

<<<<<<< HEAD
static void draw_square(SkCanvas* canvas, int x, int y)
{
    SkRect target(SkRect::MakeWH(10 * SK_Scalar1, 10 * SK_Scalar1));
    draw(canvas, target, x, y);
}

static void draw_column(SkCanvas* canvas, int x, int y)
{
    SkRect target(SkRect::MakeWH(1 * SK_Scalar1, 10 * SK_Scalar1));
    draw(canvas, target, x, y);
}

static void draw_bar(SkCanvas* canvas, int x, int y)
{
    SkRect target(SkRect::MakeWH(10 * SK_Scalar1, 1 * SK_Scalar1));
    draw(canvas, target, x, y);
}

static void draw_rect_tests(SkCanvas* canvas)
{
=======
static void draw_square(SkCanvas* canvas, int x, int y) {
    SkRect target (SkRect::MakeWH(10 * SK_Scalar1, 10 * SK_Scalar1));
    draw(canvas, target, x, y);
}

static void draw_column(SkCanvas* canvas, int x, int y) {
    SkRect target (SkRect::MakeWH(1 * SK_Scalar1, 10 * SK_Scalar1));
    draw(canvas, target, x, y);
}

static void draw_bar(SkCanvas* canvas, int x, int y) {
    SkRect target (SkRect::MakeWH(10 * SK_Scalar1, 1 * SK_Scalar1));
    draw(canvas, target, x, y);
}

static void draw_rect_tests(SkCanvas* canvas) {
>>>>>>> miniblink49
    draw_square(canvas, 10, 10);
    draw_column(canvas, 30, 10);
    draw_bar(canvas, 10, 30);
}

/**
   Test a set of clipping problems discovered while writing blitAntiRect,
   and test all the code paths through the clipping blitters.
   Each region should show as a blue center surrounded by a 2px green
   border, with no red.
*/

class AAClipGM : public skiagm::GM {
public:
<<<<<<< HEAD
    AAClipGM()
    {
    }

protected:
    SkString onShortName() override
    {
        return SkString("aaclip");
    }

    SkISize onISize() override
    {
        return SkISize::Make(240, 120);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
    AAClipGM() {

    }

protected:
    SkString onShortName() override {
        return SkString("aaclip");
    }

    SkISize onISize() override {
        return SkISize::Make(240, 120);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        // Initial pixel-boundary-aligned draw
        draw_rect_tests(canvas);

        // Repeat 4x with .2, .4, .6, .8 px offsets
        canvas->translate(SK_Scalar1 / 5, SK_Scalar1 / 5);
        canvas->translate(SkIntToScalar(50), 0);
        draw_rect_tests(canvas);

        canvas->translate(SK_Scalar1 / 5, SK_Scalar1 / 5);
        canvas->translate(SkIntToScalar(50), 0);
        draw_rect_tests(canvas);

        canvas->translate(SK_Scalar1 / 5, SK_Scalar1 / 5);
        canvas->translate(SkIntToScalar(50), 0);
        draw_rect_tests(canvas);

        canvas->translate(SK_Scalar1 / 5, SK_Scalar1 / 5);
        canvas->translate(SkIntToScalar(50), 0);
        draw_rect_tests(canvas);
    }

private:
    typedef skiagm::GM INHERITED;
};

<<<<<<< HEAD
DEF_GM(return new AAClipGM;)
=======
DEF_GM( return SkNEW(AAClipGM); )
>>>>>>> miniblink49

/////////////////////////////////////////////////////////////////////////

#ifdef SK_BUILD_FOR_MAC

<<<<<<< HEAD
static SkCanvas* make_canvas(const SkBitmap& bm)
{
    const SkImageInfo& info = bm.info();
    if (info.bytesPerPixel() == 4) {
        return SkCanvas::NewRasterDirectN32(info.width(), info.height(),
            (SkPMColor*)bm.getPixels(),
            bm.rowBytes());
    } else {
        return new SkCanvas(bm);
=======
static SkCanvas* make_canvas(const SkBitmap& bm) {
    const SkImageInfo& info = bm.info();
    if (info.bytesPerPixel() == 4) {
        return SkCanvas::NewRasterDirectN32(info.width(), info.height(),
                                            (SkPMColor*)bm.getPixels(),
                                            bm.rowBytes());
    } else {
        return SkNEW_ARGS(SkCanvas, (bm));
>>>>>>> miniblink49
    }
}

#include "SkCGUtils.h"
<<<<<<< HEAD
static void test_image(SkCanvas* canvas, const SkImageInfo& info)
{
=======
static void test_image(SkCanvas* canvas, const SkImageInfo& info) {
>>>>>>> miniblink49
    SkBitmap bm;
    bm.allocPixels(info);

    SkAutoTUnref<SkCanvas> newc(make_canvas(bm));
    if (info.isOpaque()) {
        bm.eraseColor(SK_ColorGREEN);
    } else {
        bm.eraseColor(0);
    }

    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setColor(SK_ColorBLUE);
    newc->drawCircle(50, 50, 49, paint);
    canvas->drawBitmap(bm, 10, 10);

<<<<<<< HEAD
    CGImageRef image = SkCreateCGImageRefWithColorspace(bm, nullptr);
=======
    CGImageRef image = SkCreateCGImageRefWithColorspace(bm, NULL);
>>>>>>> miniblink49

    SkBitmap bm2;
    SkCreateBitmapFromCGImage(&bm2, image);
    CGImageRelease(image);

    canvas->drawBitmap(bm2, 10, 120);
}

class CGImageGM : public skiagm::GM {
public:
<<<<<<< HEAD
    CGImageGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("cgimage");
    }

    SkISize onISize() override
    {
        return SkISize::Make(800, 250);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
    CGImageGM() {}

protected:
    SkString onShortName() override {
        return SkString("cgimage");
    }

    SkISize onISize() override {
        return SkISize::Make(800, 250);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        const struct {
            SkColorType fCT;
            SkAlphaType fAT;
        } rec[] = {
            { kRGB_565_SkColorType, kOpaque_SkAlphaType },

            { kRGBA_8888_SkColorType, kPremul_SkAlphaType },
            { kRGBA_8888_SkColorType, kUnpremul_SkAlphaType },
            { kRGBA_8888_SkColorType, kOpaque_SkAlphaType },

            { kBGRA_8888_SkColorType, kPremul_SkAlphaType },
            { kBGRA_8888_SkColorType, kUnpremul_SkAlphaType },
            { kBGRA_8888_SkColorType, kOpaque_SkAlphaType },
        };

        for (size_t i = 0; i < SK_ARRAY_COUNT(rec); ++i) {
            SkImageInfo info = SkImageInfo::Make(100, 100, rec[i].fCT, rec[i].fAT);
            test_image(canvas, info);
            canvas->translate(info.width() + 10, 0);
        }
    }

private:
    typedef skiagm::GM INHERITED;
};

#if 0 // Disabled pending fix from reed@
<<<<<<< HEAD
DEF_GM( return new CGImageGM; )
=======
DEF_GM( return SkNEW(CGImageGM); )
>>>>>>> miniblink49
#endif
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
// https://bug.skia.org/3716
=======
// skbug.com/3716
>>>>>>> miniblink49
class ClipCubicGM : public skiagm::GM {
    const SkScalar W = 100;
    const SkScalar H = 240;

    SkPath fVPath, fHPath;
<<<<<<< HEAD

public:
    ClipCubicGM()
    {
        fVPath.moveTo(W, 0);
        fVPath.cubicTo(W, H - 10, 0, 10, 0, H);

        SkMatrix pivot;
        pivot.setRotate(90, W / 2, H / 2);
=======
public:
    ClipCubicGM() {
        fVPath.moveTo(W, 0);
        fVPath.cubicTo(W, H-10, 0, 10, 0, H);
    
        SkMatrix pivot;
        pivot.setRotate(90, W/2, H/2);
>>>>>>> miniblink49
        fVPath.transform(pivot, &fHPath);
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("clipcubic");
    }

    SkISize onISize() override
    {
        return SkISize::Make(400, 410);
    }

    void doDraw(SkCanvas* canvas, const SkPath& path)
    {
        SkPaint paint;
        paint.setAntiAlias(true);

        paint.setColor(sk_tool_utils::color_to_565(0xFFCCCCCC));
        canvas->drawPath(path, paint);

=======
    SkString onShortName() override {
        return SkString("clipcubic");
    }
    
    SkISize onISize() override {
        return SkISize::Make(400, 410);
    }

    void doDraw(SkCanvas* canvas, const SkPath& path) {
        SkPaint paint;
        paint.setAntiAlias(true);
        
        paint.setColor(0xFFCCCCCC);
        canvas->drawPath(path, paint);
        
>>>>>>> miniblink49
        paint.setColor(SK_ColorRED);
        paint.setStyle(SkPaint::kStroke_Style);
        canvas->drawPath(path, paint);
    }

<<<<<<< HEAD
    void drawAndClip(SkCanvas* canvas, const SkPath& path, SkScalar dx, SkScalar dy)
    {
        SkAutoCanvasRestore acr(canvas, true);

        SkRect r = SkRect::MakeXYWH(0, H / 4, W, H / 2);
        SkPaint paint;
        paint.setColor(sk_tool_utils::color_to_565(0xFF8888FF));

        canvas->drawRect(r, paint);
        this->doDraw(canvas, path);

=======
    void drawAndClip(SkCanvas* canvas, const SkPath& path, SkScalar dx, SkScalar dy) {
        SkAutoCanvasRestore acr(canvas, true);

        SkRect r = SkRect::MakeXYWH(0, H/4, W, H/2);
        SkPaint paint;
        paint.setColor(0xFF8888FF);

        canvas->drawRect(r, paint);
        this->doDraw(canvas, path);
        
>>>>>>> miniblink49
        canvas->translate(dx, dy);

        canvas->drawRect(r, paint);
        canvas->clipRect(r);
        this->doDraw(canvas, path);
    }

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
=======
    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        canvas->translate(80, 10);
        this->drawAndClip(canvas, fVPath, 200, 0);
        canvas->translate(0, 200);
        this->drawAndClip(canvas, fHPath, 200, 0);
    }
<<<<<<< HEAD

private:
    typedef skiagm::GM INHERITED;
};
DEF_GM(return new ClipCubicGM;)
=======
    
private:
    typedef skiagm::GM INHERITED;
};
DEF_GM( return SkNEW(ClipCubicGM); )

>>>>>>> miniblink49
