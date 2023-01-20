/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkColorMatrixFilter.h"
#include "SkGradientShader.h"
#include "gm.h"

static sk_sp<SkShader> make_shader(const SkRect& bounds)
{
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkGradientShader.h"

static SkShader* make_shader(const SkRect& bounds) {
>>>>>>> miniblink49
    const SkPoint pts[] = {
        { bounds.left(), bounds.top() },
        { bounds.right(), bounds.bottom() },
    };
    const SkColor colors[] = {
<<<<<<< HEAD
        SK_ColorRED,
        SK_ColorGREEN,
        SK_ColorBLUE,
        SK_ColorBLACK,
        SK_ColorCYAN,
        SK_ColorMAGENTA,
        SK_ColorYELLOW,
    };
    return SkGradientShader::MakeLinear(pts, colors, nullptr, SK_ARRAY_COUNT(colors),
        SkShader::kClamp_TileMode);
=======
        SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorBLACK,
        SK_ColorCYAN, SK_ColorMAGENTA, SK_ColorYELLOW,
    };
    return SkGradientShader::CreateLinear(pts,
                                          colors, NULL, SK_ARRAY_COUNT(colors),
                                          SkShader::kClamp_TileMode);
>>>>>>> miniblink49
}

typedef void (*InstallPaint)(SkPaint*, uint32_t, uint32_t);

<<<<<<< HEAD
static void install_nothing(SkPaint* paint, uint32_t, uint32_t)
{
    paint->setColorFilter(nullptr);
}

static void install_lighting(SkPaint* paint, uint32_t mul, uint32_t add)
{
    paint->setColorFilter(SkColorMatrixFilter::MakeLightingFilter(mul, add));
=======
static void install_nothing(SkPaint* paint, uint32_t, uint32_t) {
    paint->setColorFilter(NULL);
}

static void install_lighting(SkPaint* paint, uint32_t mul, uint32_t add) {
    paint->setColorFilter(SkColorFilter::CreateLightingFilter(mul, add))->unref();
>>>>>>> miniblink49
}

class ColorFiltersGM : public skiagm::GM {
public:
<<<<<<< HEAD
    ColorFiltersGM()
    {
=======
    ColorFiltersGM() {
>>>>>>> miniblink49
        fName.set("lightingcolorfilter");
    }

protected:
<<<<<<< HEAD
    virtual SkString onShortName() override
    {
        return fName;
    }

    virtual SkISize onISize() override
    {
        return SkISize::Make(620, 430);
    }

    void onDraw(SkCanvas* canvas) override
    {
        SkPaint paint;
        SkRect r;
        r.setWH(600, 50);
        paint.setShader(make_shader(r));

        const struct {
            InstallPaint fProc;
            uint32_t fData0, fData1;
=======
    virtual SkString onShortName() override {
        return fName;
    }

    virtual SkISize onISize() override {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override {
        SkPaint paint;
        SkRect r;
        r.setWH(600, 50);
        paint.setShader(make_shader(r))->unref();

        const struct {
            InstallPaint    fProc;
            uint32_t        fData0, fData1;
>>>>>>> miniblink49
        } rec[] = {
            { install_nothing, 0, 0 },
            { install_lighting, 0xFF0000, 0 },
            { install_lighting, 0x00FF00, 0 },
            { install_lighting, 0x0000FF, 0 },
            { install_lighting, 0x000000, 0xFF0000 },
            { install_lighting, 0x000000, 0x00FF00 },
            { install_lighting, 0x000000, 0x0000FF },
        };

        canvas->translate(10, 10);
        for (size_t i = 0; i < SK_ARRAY_COUNT(rec); ++i) {
            rec[i].fProc(&paint, rec[i].fData0, rec[i].fData1);
            canvas->drawRect(r, paint);
            canvas->translate(0, r.height() + 10);
        }
    }

private:
    SkString fName;
    typedef GM INHERITED;
};

<<<<<<< HEAD
//////////////////////////////////////////////////////////////////////////////

DEF_GM(return new ColorFiltersGM;)
=======

//////////////////////////////////////////////////////////////////////////////

DEF_GM( return SkNEW(ColorFiltersGM); )
>>>>>>> miniblink49
