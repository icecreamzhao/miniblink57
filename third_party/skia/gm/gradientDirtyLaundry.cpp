<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkGradientShader.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkGradientShader.h"
>>>>>>> miniblink49

using namespace skiagm;

struct GradData {
<<<<<<< HEAD
    int fCount;
    const SkColor* fColors;
=======
    int             fCount;
    const SkColor*  fColors;
>>>>>>> miniblink49
    const SkScalar* fPos;
};

static const SkColor gColors[] = {
<<<<<<< HEAD
    SK_ColorRED,
    SK_ColorGREEN,
    SK_ColorBLUE,
    SK_ColorWHITE,
    SK_ColorBLACK,
    SK_ColorRED,
    SK_ColorGREEN,
    SK_ColorBLUE,
    SK_ColorWHITE,
    SK_ColorBLACK,
    SK_ColorRED,
    SK_ColorGREEN,
    SK_ColorBLUE,
    SK_ColorWHITE,
    SK_ColorBLACK,
    SK_ColorRED,
    SK_ColorGREEN,
    SK_ColorBLUE,
    SK_ColorWHITE,
    SK_ColorBLACK,
    SK_ColorRED,
    SK_ColorGREEN,
    SK_ColorBLUE,
    SK_ColorWHITE,
    SK_ColorBLACK,
    SK_ColorRED,
    SK_ColorGREEN,
    SK_ColorBLUE,
    SK_ColorWHITE,
    SK_ColorBLACK,
    SK_ColorRED,
    SK_ColorGREEN,
    SK_ColorBLUE,
    SK_ColorWHITE,
    SK_ColorBLACK,
    SK_ColorRED,
    SK_ColorGREEN,
    SK_ColorBLUE,
    SK_ColorWHITE,
    SK_ColorBLACK,
=======
    SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK,
    SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK,
    SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK,
    SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK,
    SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK,
    SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK,
    SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK,
    SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK,
>>>>>>> miniblink49
};

//static const SkScalar gPos[] = { SK_Scalar1*999/2000, SK_Scalar1*1001/2000 };

static const GradData gGradData[] = {
<<<<<<< HEAD
    { 40, gColors, nullptr },
    //  { 2, gColors, gPos },
    //  { 2, gCol2, nullptr },
};

static sk_sp<SkShader> MakeLinear(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm)
{
    return SkGradientShader::MakeLinear(pts, data.fColors, data.fPos, data.fCount, tm);
}

static sk_sp<SkShader> MakeRadial(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm)
{
    const SkPoint pt { SkScalarAve(pts[0].fX, pts[1].fX), SkScalarAve(pts[0].fY, pts[1].fY) };
    return SkGradientShader::MakeRadial(pt, pt.fX, data.fColors, data.fPos, data.fCount, tm);
}

static sk_sp<SkShader> MakeSweep(const SkPoint pts[2], const GradData& data, SkShader::TileMode)
{
    const SkPoint pt { SkScalarAve(pts[0].fX, pts[1].fX), SkScalarAve(pts[0].fY, pts[1].fY) };
    return SkGradientShader::MakeSweep(pt.fX, pt.fY, data.fColors, data.fPos, data.fCount);
}

typedef sk_sp<SkShader> (*GradMaker)(const SkPoint pts[2], const GradData&, SkShader::TileMode);

static const GradMaker gGradMakers[] = {
    MakeLinear,
    MakeRadial,
    MakeSweep,
=======
    { 40, gColors, NULL },
    //  { 2, gColors, gPos },
    //  { 2, gCol2, NULL },
};

static SkShader* MakeLinear(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm) {
    return SkGradientShader::CreateLinear(pts, data.fColors, data.fPos, data.fCount, tm);
}

static SkShader* MakeRadial(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm) {
    SkPoint center;
    center.set(SkScalarAve(pts[0].fX, pts[1].fX),
               SkScalarAve(pts[0].fY, pts[1].fY));
    return SkGradientShader::CreateRadial(center, center.fX, data.fColors,
                                          data.fPos, data.fCount, tm);
}

static SkShader* MakeSweep(const SkPoint pts[2], const GradData& data, SkShader::TileMode) {
    SkPoint center;
    center.set(SkScalarAve(pts[0].fX, pts[1].fX),
               SkScalarAve(pts[0].fY, pts[1].fY));
    return SkGradientShader::CreateSweep(center.fX, center.fY, data.fColors, data.fPos, data.fCount);
}


typedef SkShader* (*GradMaker)(const SkPoint pts[2], const GradData& data, SkShader::TileMode tm);

static const GradMaker gGradMakers[] = {
    MakeLinear, MakeRadial, MakeSweep,
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

class GradientsGM : public GM {
public:
<<<<<<< HEAD
    GradientsGM()
    {
=======
    GradientsGM() {
>>>>>>> miniblink49
        this->setBGColor(sk_tool_utils::color_to_565(0xFFDDDDDD));
    }

protected:
    SkString onShortName() override { return SkString("gradient_dirty_laundry"); }
    SkISize onISize() override { return SkISize::Make(640, 615); }

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
        SkPoint pts[2] = { { 0, 0 },
            { SkIntToScalar(100), SkIntToScalar(100) } };
=======
    void onDraw(SkCanvas* canvas) override {
        SkPoint pts[2] = { { 0, 0 },
                           { SkIntToScalar(100), SkIntToScalar(100) }
        };
>>>>>>> miniblink49
        SkShader::TileMode tm = SkShader::kClamp_TileMode;
        SkRect r = { 0, 0, SkIntToScalar(100), SkIntToScalar(100) };
        SkPaint paint;
        paint.setAntiAlias(true);

        canvas->translate(SkIntToScalar(20), SkIntToScalar(20));
        for (size_t i = 0; i < SK_ARRAY_COUNT(gGradData); i++) {
            canvas->save();
            for (size_t j = 0; j < SK_ARRAY_COUNT(gGradMakers); j++) {
<<<<<<< HEAD
                paint.setShader(gGradMakers[j](pts, gGradData[i], tm));
=======
                SkShader* shader = gGradMakers[j](pts, gGradData[i], tm);
                paint.setShader(shader)->unref();
>>>>>>> miniblink49
                canvas->drawRect(r, paint);
                canvas->translate(0, SkIntToScalar(120));
            }
            canvas->restore();
            canvas->translate(SkIntToScalar(120), 0);
        }
    }

private:
    typedef GM INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new GradientsGM; }
static GMRegistry reg(MyFactory);
