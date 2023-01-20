<<<<<<< HEAD
=======

>>>>>>> miniblink49
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
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "gm.h"

static void make_bitmap(SkBitmap* bitmap)
{
=======

static void make_bitmap(SkBitmap* bitmap) {
>>>>>>> miniblink49
    bitmap->allocN32Pixels(64, 64);

    SkCanvas canvas(*bitmap);

    canvas.drawColor(SK_ColorRED);
    SkPaint paint;
    paint.setAntiAlias(true);
    const SkPoint pts[] = { { 0, 0 }, { 64, 64 } };
    const SkColor colors[] = { SK_ColorWHITE, SK_ColorBLUE };
<<<<<<< HEAD
    paint.setShader(SkGradientShader::MakeLinear(pts, colors, nullptr, 2,
        SkShader::kClamp_TileMode));
=======
    paint.setShader(SkGradientShader::CreateLinear(pts, colors, NULL, 2,
                                                   SkShader::kClamp_TileMode))->unref();
>>>>>>> miniblink49
    canvas.drawCircle(32, 32, 32, paint);
}

class DrawBitmapRect2 : public skiagm::GM {
    bool fUseIRect;
<<<<<<< HEAD

public:
    DrawBitmapRect2(bool useIRect)
        : fUseIRect(useIRect)
    {
    }

protected:
    SkString onShortName() override
    {
=======
public:
    DrawBitmapRect2(bool useIRect) : fUseIRect(useIRect) {
    }

protected:
    SkString onShortName() override {
>>>>>>> miniblink49
        SkString str;
        str.printf("bitmaprect_%s", fUseIRect ? "i" : "s");
        return str;
    }

<<<<<<< HEAD
    SkISize onISize() override
    {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override
    {
        canvas->drawColor(sk_tool_utils::color_to_565(0xFFCCCCCC));
=======
    SkISize onISize() override {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override {
        canvas->drawColor(0xFFCCCCCC);
>>>>>>> miniblink49

        const SkIRect src[] = {
            { 0, 0, 32, 32 },
            { 0, 0, 80, 80 },
            { 32, 32, 96, 96 },
<<<<<<< HEAD
            {
                -32,
                -32,
                32,
                32,
            }
=======
            { -32, -32, 32, 32, }
>>>>>>> miniblink49
        };

        SkPaint paint;
        paint.setStyle(SkPaint::kStroke_Style);

        SkBitmap bitmap;
        make_bitmap(&bitmap);

        SkRect dstR = { 0, 200, 128, 380 };

        canvas->translate(16, 40);
        for (size_t i = 0; i < SK_ARRAY_COUNT(src); i++) {
            SkRect srcR;
            srcR.set(src[i]);

            canvas->drawBitmap(bitmap, 0, 0, &paint);
            if (!fUseIRect) {
<<<<<<< HEAD
                canvas->drawBitmapRect(bitmap, srcR, dstR, &paint,
                    SkCanvas::kStrict_SrcRectConstraint);
            } else {
                canvas->drawBitmapRect(bitmap, src[i], dstR, &paint);
=======
                canvas->drawBitmapRectToRect(bitmap, &srcR, dstR, &paint);
            } else {
                canvas->drawBitmapRect(bitmap, &src[i], dstR, &paint);
>>>>>>> miniblink49
            }

            canvas->drawRect(dstR, paint);
            canvas->drawRect(srcR, paint);

            canvas->translate(160, 0);
        }
    }

private:
    typedef skiagm::GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static void make_3x3_bitmap(SkBitmap* bitmap)
{
=======
static void make_3x3_bitmap(SkBitmap* bitmap) {
>>>>>>> miniblink49
    const int xSize = 3;
    const int ySize = 3;

    const SkColor textureData[xSize][ySize] = {
<<<<<<< HEAD
        { SK_ColorRED, SK_ColorWHITE, SK_ColorBLUE },
        { SK_ColorGREEN, SK_ColorBLACK, SK_ColorCYAN },
        { SK_ColorYELLOW, SK_ColorGRAY, SK_ColorMAGENTA }
=======
        { SK_ColorRED,    SK_ColorWHITE, SK_ColorBLUE },
        { SK_ColorGREEN,  SK_ColorBLACK, SK_ColorCYAN },
        { SK_ColorYELLOW, SK_ColorGRAY,  SK_ColorMAGENTA }
>>>>>>> miniblink49
    };

    bitmap->allocN32Pixels(xSize, ySize, true);
    SkCanvas canvas(*bitmap);
    SkPaint paint;

    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            paint.setColor(textureData[x][y]);
            canvas.drawIRect(SkIRect::MakeXYWH(x, y, 1, 1), paint);
        }
    }
}

<<<<<<< HEAD
// This GM attempts to make visible any issues drawBitmapRect may have
=======
// This GM attempts to make visible any issues drawBitmapRectToRect may have
>>>>>>> miniblink49
// with partial source rects. In this case the eight pixels on the border
// should be half the width/height of the central pixel, i.e.:
//                         __|____|__
//                           |    |
//                         __|____|__
//                           |    |
class DrawBitmapRect3 : public skiagm::GM {
public:
<<<<<<< HEAD
    DrawBitmapRect3()
    {
=======
    DrawBitmapRect3() {
>>>>>>> miniblink49
        this->setBGColor(SK_ColorBLACK);
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
=======
    SkString onShortName() override {
>>>>>>> miniblink49
        SkString str;
        str.printf("3x3bitmaprect");
        return str;
    }

<<<<<<< HEAD
    SkISize onISize() override
    {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
    SkISize onISize() override {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49

        SkBitmap bitmap;
        make_3x3_bitmap(&bitmap);

        SkRect srcR = { 0.5f, 0.5f, 2.5f, 2.5f };
        SkRect dstR = { 100, 100, 300, 200 };

<<<<<<< HEAD
        canvas->drawBitmapRect(bitmap, srcR, dstR, nullptr, SkCanvas::kStrict_SrcRectConstraint);
=======
        canvas->drawBitmapRectToRect(bitmap, &srcR, dstR, NULL);
>>>>>>> miniblink49
    }

private:
    typedef skiagm::GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
static void make_big_bitmap(SkBitmap* bitmap)
{
=======
static void make_big_bitmap(SkBitmap* bitmap) {
>>>>>>> miniblink49

    static const int gXSize = 4096;
    static const int gYSize = 4096;
    static const int gBorderWidth = 10;

    bitmap->allocN32Pixels(gXSize, gYSize);
    for (int y = 0; y < gYSize; ++y) {
        for (int x = 0; x < gXSize; ++x) {
<<<<<<< HEAD
            if (x <= gBorderWidth || x >= gXSize - gBorderWidth || y <= gBorderWidth || y >= gYSize - gBorderWidth) {
=======
            if (x <= gBorderWidth || x >= gXSize-gBorderWidth ||
                y <= gBorderWidth || y >= gYSize-gBorderWidth) {
>>>>>>> miniblink49
                *bitmap->getAddr32(x, y) = SkPreMultiplyColor(0x88FFFFFF);
            } else {
                *bitmap->getAddr32(x, y) = SkPreMultiplyColor(0x88FF0000);
            }
        }
    }
}

// This GM attempts to reveal any issues we may have when the GPU has to
// break up a large texture in order to draw it. The XOR transfer mode will
// create stripes in the image if there is imprecision in the destination
// tile placement.
class DrawBitmapRect4 : public skiagm::GM {
    bool fUseIRect;
    SkBitmap fBigBitmap;

public:
<<<<<<< HEAD
    DrawBitmapRect4(bool useIRect)
        : fUseIRect(useIRect)
    {
=======
    DrawBitmapRect4(bool useIRect) : fUseIRect(useIRect) {
>>>>>>> miniblink49
        this->setBGColor(0x88444444);
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
=======
    SkString onShortName() override {
>>>>>>> miniblink49
        SkString str;
        str.printf("bigbitmaprect_%s", fUseIRect ? "i" : "s");
        return str;
    }

<<<<<<< HEAD
    SkISize onISize() override
    {
        return SkISize::Make(640, 480);
    }

    void onOnceBeforeDraw() override
    {
        make_big_bitmap(&fBigBitmap);
    }

    void onDraw(SkCanvas* canvas) override
    {
        SkPaint paint;
        paint.setAlpha(128);
        paint.setXfermode(SkXfermode::Make(SkXfermode::kXor_Mode));
=======
    SkISize onISize() override {
        return SkISize::Make(640, 480);
    }

    void onOnceBeforeDraw() override {
        make_big_bitmap(&fBigBitmap);
    }

    void onDraw(SkCanvas* canvas) override {

        SkXfermode* mode = SkXfermode::Create(SkXfermode::kXor_Mode);

        SkPaint paint;
        paint.setAlpha(128);
        paint.setXfermode(mode)->unref();
>>>>>>> miniblink49

        SkRect srcR1 = { 0.0f, 0.0f, 4096.0f, 2040.0f };
        SkRect dstR1 = { 10.1f, 10.1f, 629.9f, 400.9f };

        SkRect srcR2 = { 4085.0f, 10.0f, 4087.0f, 12.0f };
        SkRect dstR2 = { 10, 410, 30, 430 };

        if (!fUseIRect) {
<<<<<<< HEAD
            canvas->drawBitmapRect(fBigBitmap, srcR1, dstR1, &paint,
                SkCanvas::kStrict_SrcRectConstraint);
            canvas->drawBitmapRect(fBigBitmap, srcR2, dstR2, &paint,
                SkCanvas::kStrict_SrcRectConstraint);
        } else {
            canvas->drawBitmapRect(fBigBitmap, srcR1.roundOut(), dstR1, &paint);
            canvas->drawBitmapRect(fBigBitmap, srcR2.roundOut(), dstR2, &paint);
=======
            canvas->drawBitmapRectToRect(fBigBitmap, &srcR1, dstR1, &paint);
            canvas->drawBitmapRectToRect(fBigBitmap, &srcR2, dstR2, &paint);
        } else {
            SkIRect iSrcR1, iSrcR2;

            srcR1.roundOut(&iSrcR1);
            srcR2.roundOut(&iSrcR2);

            canvas->drawBitmapRect(fBigBitmap, &iSrcR1, dstR1, &paint);
            canvas->drawBitmapRect(fBigBitmap, &iSrcR2, dstR2, &paint);
>>>>>>> miniblink49
        }
    }

private:
    typedef skiagm::GM INHERITED;
};

class BitmapRectRounding : public skiagm::GM {
    SkBitmap fBM;

public:
<<<<<<< HEAD
    BitmapRectRounding() { }

protected:
    SkString onShortName() override
    {
=======
    BitmapRectRounding() {}

protected:
    SkString onShortName() override {
>>>>>>> miniblink49
        SkString str;
        str.printf("bitmaprect_rounding");
        return str;
    }

<<<<<<< HEAD
    SkISize onISize() override
    {
        return SkISize::Make(640, 480);
    }

    void onOnceBeforeDraw() override
    {
=======
    SkISize onISize() override {
        return SkISize::Make(640, 480);
    }

    void onOnceBeforeDraw() override {
>>>>>>> miniblink49
        fBM.allocN32Pixels(10, 10);
        fBM.eraseColor(SK_ColorBLUE);
    }

    // This choice of coordinates and matrix land the bottom edge of the clip (and bitmap dst)
    // at exactly 1/2 pixel boundary. However, drawBitmapRect may lose precision along the way.
    // If it does, we may see a red-line at the bottom, instead of the bitmap exactly matching
    // the clip (in which case we should see all blue).
    // The correct image should be all blue.
<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
=======
    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setColor(SK_ColorRED);

        const SkRect r = SkRect::MakeXYWH(1, 1, 110, 114);
        canvas->scale(0.9f, 0.9f);

        // the drawRect shows the same problem as clipRect(r) followed by drawcolor(red)
        canvas->drawRect(r, paint);
<<<<<<< HEAD
        canvas->drawBitmapRect(fBM, r, nullptr);
=======
        canvas->drawBitmapRect(fBM, NULL, r, NULL);
>>>>>>> miniblink49
    }

private:
    typedef skiagm::GM INHERITED;
};
<<<<<<< HEAD
DEF_GM(return new BitmapRectRounding;)

//////////////////////////////////////////////////////////////////////////////

DEF_GM(return new DrawBitmapRect2(false);)
DEF_GM(return new DrawBitmapRect2(true);)
DEF_GM(return new DrawBitmapRect3();)

#ifndef SK_BUILD_FOR_ANDROID
DEF_GM(return new DrawBitmapRect4(false);)
DEF_GM(return new DrawBitmapRect4(true);)
#endif
=======
DEF_GM( return new BitmapRectRounding; )

//////////////////////////////////////////////////////////////////////////////

static skiagm::GM* MyFactory0(void*) { return new DrawBitmapRect2(false); }
static skiagm::GM* MyFactory1(void*) { return new DrawBitmapRect2(true); }

static skiagm::GM* MyFactory2(void*) { return new DrawBitmapRect3(); }

#ifndef SK_BUILD_FOR_ANDROID
static skiagm::GM* MyFactory3(void*) { return new DrawBitmapRect4(false); }
static skiagm::GM* MyFactory4(void*) { return new DrawBitmapRect4(true); }
#endif

static skiagm::GMRegistry reg0(MyFactory0);
static skiagm::GMRegistry reg1(MyFactory1);

static skiagm::GMRegistry reg2(MyFactory2);

#ifndef SK_BUILD_FOR_ANDROID
static skiagm::GMRegistry reg3(MyFactory3);
static skiagm::GMRegistry reg4(MyFactory4);
#endif

>>>>>>> miniblink49
