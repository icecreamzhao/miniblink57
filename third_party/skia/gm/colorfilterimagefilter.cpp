/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======
#include "gm.h"
>>>>>>> miniblink49
#include "SkCanvas.h"
#include "SkColorMatrixFilter.h"
#include "SkColorPriv.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "gm.h"
=======
>>>>>>> miniblink49

#include "SkBlurImageFilter.h"
#include "SkColorFilterImageFilter.h"

<<<<<<< HEAD
#define FILTER_WIDTH SkIntToScalar(30)
#define FILTER_HEIGHT SkIntToScalar(30)
#define MARGIN SkIntToScalar(10)

static sk_sp<SkColorFilter> cf_make_brightness(float brightness)
{
    SkScalar amount255 = SkScalarMul(brightness, SkIntToScalar(255));
    SkScalar matrix[20] = {
        1, 0, 0, 0, amount255,
        0, 1, 0, 0, amount255,
        0, 0, 1, 0, amount255,
        0, 0, 0, 1, 0
    };
    return SkColorFilter::MakeMatrixFilterRowMajor255(matrix);
}

static sk_sp<SkColorFilter> cf_make_grayscale()
{
=======
#define FILTER_WIDTH    SkIntToScalar(30)
#define FILTER_HEIGHT   SkIntToScalar(30)
#define MARGIN          SkIntToScalar(10)

static SkImageFilter* make_blur(float amount, SkImageFilter* input = NULL) {
    return SkBlurImageFilter::Create(amount, amount, input);
}

static SkImageFilter* make_brightness(float amount, SkImageFilter* input = NULL) {
    SkScalar amount255 = SkScalarMul(amount, SkIntToScalar(255));
    SkScalar matrix[20] = { 1, 0, 0, 0, amount255,
                            0, 1, 0, 0, amount255,
                            0, 0, 1, 0, amount255,
                            0, 0, 0, 1, 0 };
    SkAutoTUnref<SkColorFilter> filter(SkColorMatrixFilter::Create(matrix));
    return SkColorFilterImageFilter::Create(filter, input);
}

static SkImageFilter* make_grayscale(SkImageFilter* input = NULL) {
>>>>>>> miniblink49
    SkScalar matrix[20];
    memset(matrix, 0, 20 * sizeof(SkScalar));
    matrix[0] = matrix[5] = matrix[10] = 0.2126f;
    matrix[1] = matrix[6] = matrix[11] = 0.7152f;
    matrix[2] = matrix[7] = matrix[12] = 0.0722f;
    matrix[18] = 1.0f;
<<<<<<< HEAD
    return SkColorFilter::MakeMatrixFilterRowMajor255(matrix);
}

static sk_sp<SkColorFilter> cf_make_colorize(SkColor color)
{
    return SkColorFilter::MakeModeFilter(color, SkXfermode::kSrc_Mode);
}

static void sk_gm_get_colorfilters(SkTArray<sk_sp<SkColorFilter>>* array)
{
    array->push_back(cf_make_brightness(0.5f));
    array->push_back(cf_make_grayscale());
    array->push_back(cf_make_colorize(SK_ColorBLUE));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
#include "Resources.h"
#include "SkGradientShader.h"
#include "SkImage.h"

static sk_sp<SkShader> sh_make_lineargradient0()
{
    const SkPoint pts[] = { { 0, 0 }, { 100, 100 } };
    const SkColor colors[] = { SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE };
    return SkGradientShader::MakeLinear(pts, colors, nullptr, 3, SkShader::kRepeat_TileMode);
}

static sk_sp<SkShader> sh_make_lineargradient1()
{
    const SkPoint pts[] = { { 0, 0 }, { 100, 100 } };
    const SkColor colors[] = { SK_ColorRED, 0x0000FF00, SK_ColorBLUE };
    return SkGradientShader::MakeLinear(pts, colors, nullptr, 3, SkShader::kRepeat_TileMode);
}

static sk_sp<SkShader> sh_make_image()
{
    sk_sp<SkImage> image(GetResourceAsImage("mandrill_128.png"));
    if (!image) {
        return nullptr;
    }
    return image->makeShader(SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode);
}

static void sk_gm_get_shaders(SkTDArray<SkShader*>* array)
{
    if (auto shader = sh_make_lineargradient0()) {
        *array->append() = shader.release();
    }
    if (auto shader = sh_make_lineargradient1()) {
        *array->append() = shader.release();
    }
    if (auto shader = sh_make_image()) {
        *array->append() = shader.release();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static sk_sp<SkImageFilter> make_blur(float amount, sk_sp<SkImageFilter> input)
{
    return SkBlurImageFilter::Make(amount, amount, std::move(input));
}

static sk_sp<SkImageFilter> make_brightness(float amount, sk_sp<SkImageFilter> input)
{
    return SkColorFilterImageFilter::Make(cf_make_brightness(amount), std::move(input));
}

static sk_sp<SkImageFilter> make_grayscale(sk_sp<SkImageFilter> input)
{
    return SkColorFilterImageFilter::Make(cf_make_grayscale(), std::move(input));
}

static sk_sp<SkImageFilter> make_mode_blue(sk_sp<SkImageFilter> input)
{
    return SkColorFilterImageFilter::Make(cf_make_colorize(SK_ColorBLUE), std::move(input));
}

static void draw_clipped_rect(SkCanvas* canvas,
    const SkRect& r,
    const SkPaint& paint,
    float outset = 0.0f)
{
    canvas->save();
    SkRect clip(r);
    clip.outset(outset, outset);
    canvas->clipRect(clip);
    canvas->drawRect(r, paint);
    canvas->restore();
}

DEF_SIMPLE_GM(colorfilterimagefilter, canvas, 400, 100)
{
    SkRect r = SkRect::MakeWH(FILTER_WIDTH, FILTER_HEIGHT);
    SkPaint paint;
    paint.setColor(SK_ColorRED);
    canvas->save();
    for (float brightness = -1.0f; brightness <= 1.0f; brightness += 0.2f) {
        sk_sp<SkImageFilter> dim(make_brightness(-brightness, nullptr));
        sk_sp<SkImageFilter> bright(make_brightness(brightness, std::move(dim)));
        paint.setImageFilter(std::move(bright));
        draw_clipped_rect(canvas, r, paint);
        canvas->translate(FILTER_WIDTH + MARGIN, 0);
    }
    canvas->restore();
    canvas->translate(0, FILTER_HEIGHT + MARGIN);
    {
        sk_sp<SkImageFilter> brightness(make_brightness(0.9f, nullptr));
        sk_sp<SkImageFilter> grayscale(make_grayscale(std::move(brightness)));
        paint.setImageFilter(std::move(grayscale));
        draw_clipped_rect(canvas, r, paint);
        canvas->translate(FILTER_WIDTH + MARGIN, 0);
    }
    {
        sk_sp<SkImageFilter> grayscale(make_grayscale(nullptr));
        sk_sp<SkImageFilter> brightness(make_brightness(0.9f, std::move(grayscale)));
        paint.setImageFilter(std::move(brightness));
        draw_clipped_rect(canvas, r, paint);
        canvas->translate(FILTER_WIDTH + MARGIN, 0);
    }
    {
        sk_sp<SkImageFilter> blue(make_mode_blue(nullptr));
        sk_sp<SkImageFilter> brightness(make_brightness(1.0f, std::move(blue)));
        paint.setImageFilter(std::move(brightness));
        draw_clipped_rect(canvas, r, paint);
        canvas->translate(FILTER_WIDTH + MARGIN, 0);
    }
    {
        sk_sp<SkImageFilter> brightness(make_brightness(1.0f, nullptr));
        sk_sp<SkImageFilter> blue(make_mode_blue(std::move(brightness)));
        paint.setImageFilter(std::move(blue));
        draw_clipped_rect(canvas, r, paint);
        canvas->translate(FILTER_WIDTH + MARGIN, 0);
    }
    {
        sk_sp<SkImageFilter> blur(make_blur(3.0f, nullptr));
        sk_sp<SkImageFilter> brightness(make_brightness(0.5f, std::move(blur)));
        paint.setImageFilter(std::move(brightness));
        draw_clipped_rect(canvas, r, paint, 3);
        canvas->translate(FILTER_WIDTH + MARGIN, 0);
    }
    {
        sk_sp<SkImageFilter> blue(make_mode_blue(nullptr));
        paint.setImageFilter(std::move(blue));
        draw_clipped_rect(canvas, r, paint, 5);
        canvas->translate(FILTER_WIDTH + MARGIN, 0);
    }
}

DEF_SIMPLE_GM(colorfilterimagefilter_layer, canvas, 32, 32)
{
    SkAutoCanvasRestore autoCanvasRestore(canvas, false);
    SkColorMatrix cm;
    cm.setSaturation(0.0f);
    sk_sp<SkColorFilter> cf(SkColorFilter::MakeMatrixFilterRowMajor255(cm.fMat));
    SkPaint p;
    p.setImageFilter(SkColorFilterImageFilter::Make(std::move(cf), nullptr));
    canvas->saveLayer(NULL, &p);
    canvas->clear(SK_ColorRED);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class SkTRefArray : public SkTDArray<T> {
public:
    ~SkTRefArray() { this->unrefAll(); }
};

DEF_SIMPLE_GM(colorfiltershader, canvas, 610, 450)
{
    SkTArray<sk_sp<SkColorFilter>> filters;
    sk_gm_get_colorfilters(&filters);

    SkTRefArray<SkShader*> shaders;
    sk_gm_get_shaders(&shaders);

    SkPaint paint;
    SkRect r = SkRect::MakeWH(120, 120);

    canvas->translate(20, 20);
    for (int y = 0; y < shaders.count(); ++y) {
        SkShader* shader = shaders[y];

        canvas->save();
        for (int x = -1; x < filters.count(); ++x) {
            sk_sp<SkColorFilter> filter = x >= 0 ? filters[x] : nullptr;

            paint.setShader(shader->makeWithColorFilter(filter));
            canvas->drawRect(r, paint);
            canvas->translate(150, 0);
        }
        canvas->restore();
        canvas->translate(0, 150);
    }
}
=======
    SkAutoTUnref<SkColorFilter> filter(SkColorMatrixFilter::Create(matrix));
    return SkColorFilterImageFilter::Create(filter, input);
}

static SkImageFilter* make_mode_blue(SkImageFilter* input = NULL) {
    SkAutoTUnref<SkColorFilter> filter(
        SkColorFilter::CreateModeFilter(SK_ColorBLUE, SkXfermode::kSrcIn_Mode));
    return SkColorFilterImageFilter::Create(filter, input);
}

class ColorFilterImageFilterGM : public skiagm::GM {
public:
    ColorFilterImageFilterGM () {}

protected:

    virtual SkString onShortName() {
        return SkString("colorfilterimagefilter");
    }

    void drawClippedRect(SkCanvas* canvas, const SkRect& r, const SkPaint& paint, float outset = 0.0f) {
        canvas->save();
        SkRect clip(r);
        clip.outset(outset, outset);
        canvas->clipRect(clip);
        canvas->drawRect(r, paint);
        canvas->restore();
    }

    virtual SkISize onISize() { return SkISize::Make(400, 100); }

    virtual void onDraw(SkCanvas* canvas) {

        SkRect r = SkRect::MakeWH(FILTER_WIDTH, FILTER_HEIGHT);
        SkPaint paint;
        paint.setColor(SK_ColorRED);
        canvas->save();
        for (float brightness = -1.0f; brightness <= 1.0f; brightness += 0.2f) {
            SkAutoTUnref<SkImageFilter> dim(make_brightness(-brightness));
            SkAutoTUnref<SkImageFilter> bright(make_brightness(brightness, dim));
            paint.setImageFilter(bright);
            drawClippedRect(canvas, r, paint);
            canvas->translate(FILTER_WIDTH + MARGIN, 0);
        }
        canvas->restore();
        canvas->translate(0, FILTER_HEIGHT + MARGIN);
        {
            SkAutoTUnref<SkImageFilter> brightness(make_brightness(0.9f));
            SkAutoTUnref<SkImageFilter> grayscale(make_grayscale(brightness));
            paint.setImageFilter(grayscale);
            drawClippedRect(canvas, r, paint);
            canvas->translate(FILTER_WIDTH + MARGIN, 0);
        }
        {
            SkAutoTUnref<SkImageFilter> grayscale(make_grayscale());
            SkAutoTUnref<SkImageFilter> brightness(make_brightness(0.9f, grayscale));
            paint.setImageFilter(brightness);
            drawClippedRect(canvas, r, paint);
            canvas->translate(FILTER_WIDTH + MARGIN, 0);
        }
        {
            SkAutoTUnref<SkImageFilter> blue(make_mode_blue());
            SkAutoTUnref<SkImageFilter> brightness(make_brightness(1.0f, blue));
            paint.setImageFilter(brightness);
            drawClippedRect(canvas, r, paint);
            canvas->translate(FILTER_WIDTH + MARGIN, 0);
        }
        {
            SkAutoTUnref<SkImageFilter> brightness(make_brightness(1.0f));
            SkAutoTUnref<SkImageFilter> blue(make_mode_blue(brightness));
            paint.setImageFilter(blue);
            drawClippedRect(canvas, r, paint);
            canvas->translate(FILTER_WIDTH + MARGIN, 0);
        }
        {
            SkAutoTUnref<SkImageFilter> blur(make_blur(3.0f));
            SkAutoTUnref<SkImageFilter> brightness(make_brightness(0.5f, blur));
            paint.setImageFilter(brightness);
            drawClippedRect(canvas, r, paint, 3);
            canvas->translate(FILTER_WIDTH + MARGIN, 0);
        }
    }

private:
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static skiagm::GM* MyFactory(void*) { return new ColorFilterImageFilterGM; }
static skiagm::GMRegistry reg(MyFactory);
>>>>>>> miniblink49
