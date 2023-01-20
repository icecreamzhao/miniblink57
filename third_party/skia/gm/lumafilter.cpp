/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkLumaColorFilter.h"
#include "gm.h"

static SkScalar kSize = 80;
static SkScalar kInset = 10;
static SkColor kColor1 = SkColorSetARGB(0xff, 0xff, 0xff, 0);
static SkColor kColor2 = SkColorSetARGB(0xff, 0x82, 0xff, 0);

static void draw_label(SkCanvas* canvas, const char* label,
    const SkPoint& offset)
{
=======
#include "gm.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkLumaColorFilter.h"

static SkScalar kSize   = 80;
static SkScalar kInset  = 10;
static SkColor  kColor1 = SkColorSetARGB(0xff, 0xff, 0xff, 0);
static SkColor  kColor2 = SkColorSetARGB(0xff, 0x80, 0xff, 0);

static void draw_label(SkCanvas* canvas, const char* label,
                       const SkPoint& offset) {
>>>>>>> miniblink49
    SkPaint paint;
    sk_tool_utils::set_portable_typeface(&paint);
    size_t len = strlen(label);

    SkScalar width = paint.measureText(label, len);
    canvas->drawText(label, len, offset.x() - width / 2, offset.y(),
<<<<<<< HEAD
        paint);
}

static void draw_scene(SkCanvas* canvas, const sk_sp<SkColorFilter>& filter, SkXfermode::Mode mode,
    const sk_sp<SkShader>& s1, const sk_sp<SkShader>& s2)
{
=======
                     paint);
}

static void draw_scene(SkCanvas* canvas, SkColorFilter* filter,
                       SkXfermode::Mode mode, SkShader* s1,
                       SkShader* s2) {
>>>>>>> miniblink49
    SkPaint paint;
    paint.setAntiAlias(true);
    SkRect r, c, bounds = SkRect::MakeWH(kSize, kSize);

    c = bounds;
    c.fRight = bounds.centerX();
    paint.setARGB(0x20, 0, 0, 0xff);
    canvas->drawRect(bounds, paint);

<<<<<<< HEAD
    canvas->saveLayer(&bounds, nullptr);
=======
    canvas->saveLayer(&bounds, NULL);
>>>>>>> miniblink49

    r = bounds;
    r.inset(kInset, 0);
    paint.setShader(s1);
    paint.setColor(s1 ? SK_ColorBLACK : SkColorSetA(kColor1, 0x80));
    canvas->drawOval(r, paint);
    if (!s1) {
        canvas->save();
        canvas->clipRect(c);
        paint.setColor(kColor1);
        canvas->drawOval(r, paint);
        canvas->restore();
    }

    SkPaint xferPaint;
    xferPaint.setXfermodeMode(mode);
    canvas->saveLayer(&bounds, &xferPaint);

    r = bounds;
    r.inset(0, kInset);
    paint.setShader(s2);
    paint.setColor(s2 ? SK_ColorBLACK : SkColorSetA(kColor2, 0x80));
    paint.setColorFilter(filter);
    canvas->drawOval(r, paint);
    if (!s2) {
        canvas->save();
        canvas->clipRect(c);
        paint.setColor(kColor2);
        canvas->drawOval(r, paint);
        canvas->restore();
    }

    canvas->restore();
    canvas->restore();
}

class LumaFilterGM : public skiagm::GM {
public:
<<<<<<< HEAD
    LumaFilterGM()
    {
        SkColor g1Colors[] = { kColor1, SkColorSetA(kColor1, 0x20) };
        SkColor g2Colors[] = { kColor2, SkColorSetA(kColor2, 0x20) };
        SkPoint g1Points[] = { { 0, 0 }, { 0, 100 } };
        SkPoint g2Points[] = { { 0, 0 }, { kSize, 0 } };
        SkScalar pos[] = { 0.2f, 1.0f };

        fFilter = SkLumaColorFilter::Make();
        fGr1 = SkGradientShader::MakeLinear(g1Points, g1Colors, pos, SK_ARRAY_COUNT(g1Colors),
            SkShader::kClamp_TileMode);
        fGr2 = SkGradientShader::MakeLinear(g2Points, g2Colors, pos, SK_ARRAY_COUNT(g2Colors),
            SkShader::kClamp_TileMode);
    }

protected:
    SkString onShortName() override
    {
        return SkString("lumafilter");
    }

    SkISize onISize() override
    {
        return SkISize::Make(600, 420);
    }

    void onDraw(SkCanvas* canvas) override
    {
        SkXfermode::Mode modes[] = {
            SkXfermode::kSrcOver_Mode,
            SkXfermode::kDstOver_Mode,
            SkXfermode::kSrcATop_Mode,
            SkXfermode::kDstATop_Mode,
            SkXfermode::kSrcIn_Mode,
            SkXfermode::kDstIn_Mode,
        };
        struct {
            const sk_sp<SkShader>& fShader1;
            const sk_sp<SkShader>& fShader2;
        } shaders[] = {
            { nullptr, nullptr },
            { nullptr, fGr2 },
            { fGr1, nullptr },
=======
    LumaFilterGM() {
        SkColor  g1Colors[] = { kColor1, SkColorSetA(kColor1, 0x20) };
        SkColor  g2Colors[] = { kColor2, SkColorSetA(kColor2, 0x20) };
        SkPoint  g1Points[] = { { 0, 0 }, { 0,     100 } };
        SkPoint  g2Points[] = { { 0, 0 }, { kSize, 0   } };
        SkScalar pos[] = { 0.2f, 1.0f };

        fFilter.reset(SkLumaColorFilter::Create());
        fGr1.reset(SkGradientShader::CreateLinear(g1Points,
                                                  g1Colors,
                                                  pos,
                                                  SK_ARRAY_COUNT(g1Colors),
                                                  SkShader::kClamp_TileMode));
        fGr2.reset(SkGradientShader::CreateLinear(g2Points,
                                                  g2Colors,
                                                  pos,
                                                  SK_ARRAY_COUNT(g2Colors),
                                                  SkShader::kClamp_TileMode));
    }

protected:

    SkString onShortName() override {
        return SkString("lumafilter");
    }

    SkISize onISize() override {
        return SkISize::Make(600, 420);
    }

    void onDraw(SkCanvas* canvas) override {
        SkXfermode::Mode modes[] = { SkXfermode::kSrcOver_Mode,
                                     SkXfermode::kDstOver_Mode,
                                     SkXfermode::kSrcATop_Mode,
                                     SkXfermode::kDstATop_Mode,
                                     SkXfermode::kSrcIn_Mode,
                                     SkXfermode::kDstIn_Mode,
                                   };
        struct {
            SkShader*   fShader1;
            SkShader*   fShader2;
        } shaders[] = {
            { NULL, NULL },
            { NULL, fGr2 },
            { fGr1, NULL },
>>>>>>> miniblink49
            { fGr1, fGr2 },
        };

        SkScalar gridStep = kSize + 2 * kInset;
        for (size_t i = 0; i < SK_ARRAY_COUNT(modes); ++i) {
            draw_label(canvas, SkXfermode::ModeName(modes[i]),
<<<<<<< HEAD
                SkPoint::Make(gridStep * (0.5f + i), 20));
=======
                       SkPoint::Make(gridStep * (0.5f + i), 20));
>>>>>>> miniblink49
        }

        for (size_t i = 0; i < SK_ARRAY_COUNT(shaders); ++i) {
            canvas->save();
            canvas->translate(kInset, gridStep * i + 30);
            for (size_t m = 0; m < SK_ARRAY_COUNT(modes); ++m) {
                draw_scene(canvas, fFilter, modes[m], shaders[i].fShader1,
<<<<<<< HEAD
                    shaders[i].fShader2);
=======
                           shaders[i].fShader2);
>>>>>>> miniblink49
                canvas->translate(gridStep, 0);
            }
            canvas->restore();
        }
    }

private:
<<<<<<< HEAD
    sk_sp<SkColorFilter> fFilter;
    sk_sp<SkShader> fGr1, fGr2;
=======
    SkAutoTUnref<SkColorFilter> fFilter;
    SkAutoTUnref<SkShader>      fGr1, fGr2;
>>>>>>> miniblink49

    typedef skiagm::GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new LumaFilterGM;)
=======
DEF_GM( return SkNEW(LumaFilterGM); )
>>>>>>> miniblink49
