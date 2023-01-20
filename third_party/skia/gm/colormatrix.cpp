/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkColorMatrixFilter.h"
#include "SkGradientShader.h"
#include "SkImage.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkColorMatrixFilter.h"
#include "SkGradientShader.h"
#include "SkImage.h"
>>>>>>> miniblink49

#define WIDTH 500
#define HEIGHT 500

<<<<<<< HEAD
static void set_color_matrix(SkPaint* paint, const SkColorMatrix& matrix)
{
    paint->setColorFilter(SkColorFilter::MakeMatrixFilterRowMajor255(matrix.fMat));
}

static void set_array(SkPaint* paint, const SkScalar array[])
{
    paint->setColorFilter(SkColorFilter::MakeMatrixFilterRowMajor255(array));
=======
static void set_color_matrix(SkPaint* paint, const SkColorMatrix& matrix) {
    paint->setColorFilter(SkColorMatrixFilter::Create(matrix))->unref();
}

static void set_array(SkPaint* paint, const SkScalar array[]) {
    paint->setColorFilter(SkColorMatrixFilter::Create(array))->unref();
>>>>>>> miniblink49
}

class ColorMatrixGM : public skiagm::GM {
public:
<<<<<<< HEAD
    ColorMatrixGM()
    {
=======
    ColorMatrixGM() {
>>>>>>> miniblink49
        this->setBGColor(sk_tool_utils::color_to_565(0xFF808080));
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("colormatrix");
    }

    SkISize onISize() override
    {
        return SkISize::Make(WIDTH, HEIGHT);
    }

    void onOnceBeforeDraw() override
    {
        fSolidImg = CreateSolidBitmap(64, 64);
        fTransparentImg = CreateTransparentBitmap(64, 64);
    }

    static sk_sp<SkImage> CreateSolidBitmap(int width, int height)
    {
=======
    SkString onShortName() override {
        return SkString("colormatrix");
    }

    SkISize onISize() override {
        return SkISize::Make(WIDTH, HEIGHT);
    }
    
    void onOnceBeforeDraw() override {
        fSolidImg.reset(CreateSolidBitmap(64, 64));
        fTransparentImg.reset(CreateTransparentBitmap(64, 64));
    }

    static SkImage* CreateSolidBitmap(int width, int height) {
>>>>>>> miniblink49
        SkBitmap bm;
        bm.allocN32Pixels(width, height);
        SkCanvas canvas(bm);
        canvas.clear(0x0);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                SkPaint paint;
                paint.setColor(SkColorSetARGB(255, x * 255 / width, y * 255 / height, 0));
                canvas.drawRect(SkRect::MakeXYWH(SkIntToScalar(x),
<<<<<<< HEAD
                                    SkIntToScalar(y), SK_Scalar1, SK_Scalar1),
                    paint);
            }
        }
        return SkImage::MakeFromBitmap(bm);
    }

    // creates a bitmap with shades of transparent gray.
    static sk_sp<SkImage> CreateTransparentBitmap(int width, int height)
    {
=======
                    SkIntToScalar(y), SK_Scalar1, SK_Scalar1), paint);
            }
        }
        return SkImage::NewFromBitmap(bm);
    }

    // creates a bitmap with shades of transparent gray.
    static SkImage* CreateTransparentBitmap(int width, int height) {
>>>>>>> miniblink49
        SkBitmap bm;
        bm.allocN32Pixels(width, height);
        SkCanvas canvas(bm);
        canvas.clear(0x0);

<<<<<<< HEAD
        SkPoint pts[] = { { 0, 0 }, { SkIntToScalar(width), SkIntToScalar(height) } };
        SkColor colors[] = { 0x00000000, 0xFFFFFFFF };
        SkPaint paint;
        paint.setShader(SkGradientShader::MakeLinear(pts, colors, nullptr, 2,
            SkShader::kClamp_TileMode));
        canvas.drawRect(SkRect::MakeWH(SkIntToScalar(width), SkIntToScalar(height)), paint);
        return SkImage::MakeFromBitmap(bm);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
        SkPoint pts[] = {{0, 0}, {SkIntToScalar(width), SkIntToScalar(height)}};
        SkColor colors[] = {0x00000000, 0xFFFFFFFF};
        SkPaint paint;
        paint.setShader(SkGradientShader::CreateLinear(pts, colors, NULL, 2,
                                                       SkShader::kClamp_TileMode))->unref();
        canvas.drawRect(SkRect::MakeWH(SkIntToScalar(width), SkIntToScalar(height)), paint);
        return SkImage::NewFromBitmap(bm);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;
        SkColorMatrix matrix;

        paint.setXfermodeMode(SkXfermode::kSrc_Mode);
<<<<<<< HEAD
        const SkImage* bmps[] = { fSolidImg.get(), fTransparentImg.get() };
=======
        const SkImage* bmps[] = { fSolidImg, fTransparentImg };
>>>>>>> miniblink49

        for (size_t i = 0; i < SK_ARRAY_COUNT(bmps); ++i) {
            matrix.setIdentity();
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 0, 0, &paint);

            matrix.setRotate(SkColorMatrix::kR_Axis, 90);
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 80, 0, &paint);

            matrix.setRotate(SkColorMatrix::kG_Axis, 90);
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 160, 0, &paint);

            matrix.setRotate(SkColorMatrix::kB_Axis, 90);
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 240, 0, &paint);
            ///////////////////////////////////////////////
            matrix.setSaturation(0.0f);
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 0, 80, &paint);

            matrix.setSaturation(0.5f);
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 80, 80, &paint);

            matrix.setSaturation(1.0f);
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 160, 80, &paint);

            matrix.setSaturation(2.0f);
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 240, 80, &paint);
            ///////////////////////////////////////////////
            matrix.setRGB2YUV();
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 0, 160, &paint);

            matrix.setYUV2RGB();
            set_color_matrix(&paint, matrix);
            canvas->drawImage(bmps[i], 80, 160, &paint);

            SkScalar s1 = SK_Scalar1;
            SkScalar s255 = SkIntToScalar(255);
            // Move red into alpha, set color to white
            SkScalar data[20] = {
<<<<<<< HEAD
                0,
                0,
                0,
                0,
                s255,
                0,
                0,
                0,
                0,
                s255,
                0,
                0,
                0,
                0,
                s255,
                s1,
                0,
                0,
                0,
                0,
=======
                0,  0, 0, 0, s255,
                0,  0, 0, 0, s255,
                0,  0, 0, 0, s255,
                s1, 0, 0, 0, 0,
>>>>>>> miniblink49
            };

            set_array(&paint, data);
            canvas->drawImage(bmps[i], 160, 160, &paint);
            ///////////////////////////////////////////////
            canvas->translate(0, 240);
        }
    }

private:
<<<<<<< HEAD
    sk_sp<SkImage> fSolidImg;
    sk_sp<SkImage> fTransparentImg;

    typedef skiagm::GM INHERITED;
};
DEF_GM(return new ColorMatrixGM;)
=======
    SkAutoTUnref<SkImage>   fSolidImg;
    SkAutoTUnref<SkImage>   fTransparentImg;

    typedef skiagm::GM INHERITED;
};
DEF_GM( return new ColorMatrixGM; )

>>>>>>> miniblink49
