/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD

#include "SkGradientShader.h"
#include "gm.h"

namespace skiagm {

static sk_sp<SkShader> MakeLinear(SkScalar width, SkScalar height, bool alternate,
    const SkMatrix& localMatrix)
{
    SkPoint pts[2] = { { 0, 0 }, { width, height } };
    SkColor colors[2] = { SK_ColorRED, SK_ColorGREEN };
    if (alternate) {
        pts[1].fY = 0;
        colors[0] = SK_ColorBLUE;
        colors[1] = SK_ColorYELLOW;
    }
    return SkGradientShader::MakeLinear(pts, colors, nullptr, 2, SkShader::kClamp_TileMode,
        0, &localMatrix);
=======
#include "gm.h"
#include "SkGradientShader.h"

namespace skiagm {

static SkShader* MakeLinear(SkScalar width, SkScalar height, bool alternate,
                            const SkMatrix& localMatrix) {
  SkPoint pts[2] = { {0, 0}, {width, height}};
  SkColor colors[2] = {SK_ColorRED, SK_ColorGREEN};
  if (alternate) {
    pts[1].fY = 0;
    colors[0] = SK_ColorBLUE;
    colors[1] = SK_ColorYELLOW;
  }
  return SkGradientShader::CreateLinear(pts, colors, NULL, 2,
                                        SkShader::kClamp_TileMode, 0, &localMatrix);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

class ShaderBoundsGM : public GM {
public:
<<<<<<< HEAD
    typedef sk_sp<SkShader> (*ShaderGenFunc)(SkScalar width, SkScalar height,
        bool alternate, const SkMatrix& localMatrix);
    ShaderBoundsGM(ShaderGenFunc maker, const SkString& name)
        : fShaderMaker(maker)
        , fName(name)
    {
    }

protected:
    SkString onShortName() override
    {
=======
    typedef SkShader* (*ShaderGenFunc)(SkScalar width, SkScalar height,
                                       bool alternate, const SkMatrix& localMatrix);
    ShaderBoundsGM(ShaderGenFunc maker, const SkString& name)
        : fShaderMaker(maker),
          fName(name) {
    }

protected:

    SkString onShortName() override {
>>>>>>> miniblink49
        return fName;
    }

    SkISize onISize() override { return SkISize::Make(320, 240); }

<<<<<<< HEAD
    SkMatrix onGetInitialTransform() const override
    {
=======
    SkMatrix onGetInitialTransform() const override {
>>>>>>> miniblink49
        SkMatrix result;
        SkScalar scale = 0.8f;
        result.setScale(scale, scale);
        result.postTranslate(SkIntToScalar(7), SkIntToScalar(23));
        return result;
    }

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
        // The PDF device has already clipped to the content area, but we
        // do it again here so that the raster and pdf results are consistent.
        canvas->clipRect(SkRect::MakeWH(SkIntToScalar(320),
            SkIntToScalar(240)));
=======
    void onDraw(SkCanvas* canvas) override {
        // The PDF device has already clipped to the content area, but we
        // do it again here so that the raster and pdf results are consistent.
        canvas->clipRect(SkRect::MakeWH(SkIntToScalar(320),
                                        SkIntToScalar(240)));
>>>>>>> miniblink49

        SkMatrix canvasScale;
        SkScalar scale = 0.7f;
        canvasScale.setScale(scale, scale);
        canvas->concat(canvasScale);

        // Background shader.
        SkPaint paint;
<<<<<<< HEAD
        paint.setShader(MakeShader(559, 387, false));
        SkRect r = SkRect::MakeXYWH(SkIntToScalar(-12), SkIntToScalar(-41),
            SkIntToScalar(571), SkIntToScalar(428));
        canvas->drawRect(r, paint);

        // Constrained shader.
        paint.setShader(MakeShader(101, 151, true));
        r = SkRect::MakeXYWH(SkIntToScalar(43), SkIntToScalar(71),
            SkIntToScalar(101), SkIntToScalar(151));
=======
        paint.setShader(MakeShader(559, 387, false))->unref();
        SkRect r = SkRect::MakeXYWH(SkIntToScalar(-12), SkIntToScalar(-41),
                                    SkIntToScalar(571), SkIntToScalar(428));
        canvas->drawRect(r, paint);

        // Constrained shader.
        paint.setShader(MakeShader(101, 151, true))->unref();
        r = SkRect::MakeXYWH(SkIntToScalar(43), SkIntToScalar(71),
                             SkIntToScalar(101), SkIntToScalar(151));
>>>>>>> miniblink49
        canvas->clipRect(r);
        canvas->drawRect(r, paint);
    }

<<<<<<< HEAD
    sk_sp<SkShader> MakeShader(int width, int height, bool background)
    {
=======
    SkShader* MakeShader(int width, int height, bool background) {
>>>>>>> miniblink49
        SkScalar scale = 0.5f;
        if (background) {
            scale = 0.6f;
        }
        SkScalar shaderWidth = width / scale;
        SkScalar shaderHeight = height / scale;
        SkMatrix shaderScale = SkMatrix::MakeScale(scale);
<<<<<<< HEAD
        return fShaderMaker(shaderWidth, shaderHeight, background, shaderScale);
=======
        SkShader* shader = fShaderMaker(shaderWidth, shaderHeight, background, shaderScale);
        return shader;
>>>>>>> miniblink49
    }

private:
    typedef GM INHERITED;

    ShaderGenFunc fShaderMaker;
    SkString fName;

<<<<<<< HEAD
    sk_sp<SkShader> MakeShader(bool background);
=======
    SkShader* MakeShader(bool background);
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static GM* MyFactory(void*)
{
=======
static GM* MyFactory(void*) {
>>>>>>> miniblink49
    return new ShaderBoundsGM(MakeLinear, SkString("shaderbounds_linear"));
}
static GMRegistry reg(MyFactory);

}
