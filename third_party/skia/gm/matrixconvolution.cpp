/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkColor.h"
#include "SkGradientShader.h"
#include "SkMatrixConvolutionImageFilter.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkColor.h"
#include "SkMatrixConvolutionImageFilter.h"
#include "SkGradientShader.h"
>>>>>>> miniblink49

namespace skiagm {

class MatrixConvolutionGM : public GM {
public:
<<<<<<< HEAD
    MatrixConvolutionGM()
    {
=======
    MatrixConvolutionGM() : fInitialized(false) {
>>>>>>> miniblink49
        this->setBGColor(0x00000000);
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("matrixconvolution");
    }

    void makeBitmap()
    {
=======

    virtual SkString onShortName() {
        return SkString("matrixconvolution");
    }

    void make_bitmap() {
>>>>>>> miniblink49
        fBitmap.allocN32Pixels(80, 80);
        SkCanvas canvas(fBitmap);
        canvas.clear(0x00000000);
        SkPaint paint;
        paint.setAntiAlias(true);
        sk_tool_utils::set_portable_typeface(&paint);
        paint.setColor(0xFFFFFFFF);
        paint.setTextSize(SkIntToScalar(180));
        SkPoint pts[2] = { SkPoint::Make(0, 0),
<<<<<<< HEAD
            SkPoint::Make(0, SkIntToScalar(80)) };
        SkColor colors[2] = { 0xFFFFFFFF, 0x40404040 };
        SkScalar pos[2] = { 0, SkIntToScalar(80) };
        paint.setShader(SkGradientShader::MakeLinear(
            pts, colors, pos, 2, SkShader::kClamp_TileMode));
=======
                           SkPoint::Make(0, SkIntToScalar(80)) };
        SkColor colors[2] = { 0xFFFFFFFF, 0x40404040 };
        SkScalar pos[2] = { 0, SkIntToScalar(80) };
        paint.setShader(SkGradientShader::CreateLinear(
            pts, colors, pos, 2, SkShader::kClamp_TileMode))->unref();
>>>>>>> miniblink49
        const char* str = "e";
        canvas.drawText(str, strlen(str), SkIntToScalar(-10), SkIntToScalar(80), paint);
    }

<<<<<<< HEAD
    SkISize onISize() override
    {
=======
    virtual SkISize onISize() {
>>>>>>> miniblink49
        return SkISize::Make(500, 300);
    }

    void draw(SkCanvas* canvas, int x, int y, const SkIPoint& kernelOffset,
<<<<<<< HEAD
        SkMatrixConvolutionImageFilter::TileMode tileMode, bool convolveAlpha,
        const SkImageFilter::CropRect* cropRect = nullptr)
    {
        SkScalar kernel[9] = {
            SkIntToScalar(1),
            SkIntToScalar(1),
            SkIntToScalar(1),
            SkIntToScalar(1),
            SkIntToScalar(-7),
            SkIntToScalar(1),
            SkIntToScalar(1),
            SkIntToScalar(1),
            SkIntToScalar(1),
=======
              SkMatrixConvolutionImageFilter::TileMode tileMode, bool convolveAlpha,
              const SkImageFilter::CropRect* cropRect = NULL) {
        SkScalar kernel[9] = {
            SkIntToScalar( 1), SkIntToScalar( 1), SkIntToScalar( 1),
            SkIntToScalar( 1), SkIntToScalar(-7), SkIntToScalar( 1),
            SkIntToScalar( 1), SkIntToScalar( 1), SkIntToScalar( 1),
>>>>>>> miniblink49
        };
        SkISize kernelSize = SkISize::Make(3, 3);
        SkScalar gain = 0.3f, bias = SkIntToScalar(100);
        SkPaint paint;
<<<<<<< HEAD
        paint.setImageFilter(SkMatrixConvolutionImageFilter::Make(kernelSize,
            kernel,
            gain,
            bias,
            kernelOffset,
            tileMode,
            convolveAlpha,
            nullptr,
            cropRect));
        canvas->save();
        canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
        canvas->clipRect(SkRect::MakeWH(SkIntToScalar(fBitmap.width()),
            SkIntToScalar(fBitmap.height())));
=======
        SkAutoTUnref<SkImageFilter> filter(
            SkMatrixConvolutionImageFilter::Create(kernelSize,
                                                   kernel,
                                                   gain,
                                                   bias,
                                                   kernelOffset,
                                                   tileMode,
                                                   convolveAlpha,
                                                   NULL,
                                                   cropRect));
        paint.setImageFilter(filter);
        canvas->save();
        canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
        canvas->clipRect(SkRect::MakeWH(SkIntToScalar(fBitmap.width()),
                                        SkIntToScalar(fBitmap.height())));
>>>>>>> miniblink49
        canvas->drawBitmap(fBitmap, 0, 0, &paint);
        canvas->restore();
    }

    typedef SkMatrixConvolutionImageFilter MCIF;

<<<<<<< HEAD
    void onOnceBeforeDraw() override
    {
        this->makeBitmap();
    }

    void onDraw(SkCanvas* canvas) override
    {
        canvas->clear(SK_ColorBLACK);
        SkIPoint kernelOffset = SkIPoint::Make(1, 0);
        SkImageFilter::CropRect rect(SkRect::Make(fBitmap.bounds()));
        for (int x = 10; x < 310; x += 100) {
            this->draw(canvas, x, 10, kernelOffset, MCIF::kClamp_TileMode, true, &rect);
            this->draw(canvas, x, 110, kernelOffset, MCIF::kClampToBlack_TileMode, true, &rect);
            this->draw(canvas, x, 210, kernelOffset, MCIF::kRepeat_TileMode, true, &rect);
            kernelOffset.fY++;
        }
        kernelOffset.fY = 1;
        SkImageFilter::CropRect smallRect(SkRect::MakeXYWH(10, 5, 60, 60));
        this->draw(canvas, 310, 10, kernelOffset, MCIF::kClamp_TileMode, true, &smallRect);
        this->draw(canvas, 310, 110, kernelOffset, MCIF::kClampToBlack_TileMode, true, &smallRect);
        this->draw(canvas, 310, 210, kernelOffset, MCIF::kRepeat_TileMode, true, &smallRect);

        this->draw(canvas, 410, 10, kernelOffset, MCIF::kClamp_TileMode, false, &rect);
        this->draw(canvas, 410, 110, kernelOffset, MCIF::kClampToBlack_TileMode, false, &rect);
        this->draw(canvas, 410, 210, kernelOffset, MCIF::kRepeat_TileMode, false, &rect);
    }

private:
    SkBitmap fBitmap;

    typedef GM INHERITED;
=======
    virtual void onDraw(SkCanvas* canvas) {
        if (!fInitialized) {
            make_bitmap();
            fInitialized = true;
        }
        canvas->clear(SK_ColorBLACK);
        SkIPoint kernelOffset = SkIPoint::Make(1, 0);
        for (int x = 10; x < 310; x += 100) {
            this->draw(canvas, x, 10, kernelOffset, MCIF::kClamp_TileMode, true);
            this->draw(canvas, x, 110, kernelOffset, MCIF::kClampToBlack_TileMode, true);
            this->draw(canvas, x, 210, kernelOffset, MCIF::kRepeat_TileMode, true);
            kernelOffset.fY++;
        }
        kernelOffset.fY = 1;
        SkImageFilter::CropRect rect(SkRect::MakeXYWH(10, 5, 60, 60));
        this->draw(canvas, 310, 10, kernelOffset, MCIF::kClamp_TileMode, true, &rect);
        this->draw(canvas, 310, 110, kernelOffset, MCIF::kClampToBlack_TileMode, true, &rect);
        this->draw(canvas, 310, 210, kernelOffset, MCIF::kRepeat_TileMode, true, &rect);

        this->draw(canvas, 410, 10, kernelOffset, MCIF::kClamp_TileMode, false);
        this->draw(canvas, 410, 110, kernelOffset, MCIF::kClampToBlack_TileMode, false);
        this->draw(canvas, 410, 210, kernelOffset, MCIF::kRepeat_TileMode, false);
    }

private:
    typedef GM INHERITED;
    SkBitmap fBitmap;
    bool fInitialized;
>>>>>>> miniblink49
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new MatrixConvolutionGM;)
=======
static GM* MyFactory(void*) { return new MatrixConvolutionGM; }
static GMRegistry reg(MyFactory);
>>>>>>> miniblink49

}
