/*
* Copyright 2013 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

<<<<<<< HEAD
=======
#include "gm.h"
>>>>>>> miniblink49
#include "SkBlurMask.h"
#include "SkBlurMaskFilter.h"
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkLayerDrawLooper.h"
#include "SkPaint.h"
#include "SkPath.h"
#include "SkPoint.h"
<<<<<<< HEAD
#include "SkRRect.h"
#include "SkRect.h"
#include "SkString.h"
#include "SkXfermode.h"
#include "gm.h"
=======
#include "SkRect.h"
#include "SkRRect.h"
#include "SkString.h"
#include "SkXfermode.h"
>>>>>>> miniblink49

// This GM mimics a blurred RR seen in the wild.
class BlurRoundRectGM : public skiagm::GM {
public:
<<<<<<< HEAD
    BlurRoundRectGM(int width, int height)
        : fName("blurroundrect")
        , fWidth(width)
        , fHeight(height)
    {
        fName.appendf("-WH-%ix%i-unevenCorners", width, height);
    }

    SkString onShortName() override
    {
        return fName;
    }

    SkISize onISize() override
    {
        return SkISize::Make(fWidth, fHeight);
    }

    void onOnceBeforeDraw() override
    {
=======
    BlurRoundRectGM(int width, int height, int radius)
        : fName("blurroundrect")
    {
        SkRect r = SkRect::MakeWH(SkIntToScalar(width), SkIntToScalar(height));
        fRRect.setRectXY(r, SkIntToScalar(radius), SkIntToScalar(radius));
        fName.appendf("-WH-%ix%i-corner-%i", width, height, radius);
    }

    BlurRoundRectGM(int width, int height)
        : fName("blurroundrect") {
        fName.appendf("-WH-%ix%i-unevenCorners", width,  height);
>>>>>>> miniblink49
        SkVector radii[4];
        radii[0].set(SkIntToScalar(30), SkIntToScalar(30));
        radii[1].set(SkIntToScalar(10), SkIntToScalar(10));
        radii[2].set(SkIntToScalar(30), SkIntToScalar(30));
        radii[3].set(SkIntToScalar(10), SkIntToScalar(10));
<<<<<<< HEAD
        SkRect r = SkRect::MakeWH(SkIntToScalar(fWidth), SkIntToScalar(fHeight));
        fRRect.setRectRadii(r, radii);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
        SkRect r = SkRect::MakeWH(SkIntToScalar(width), SkIntToScalar(height));
        fRRect.setRectRadii(r, radii);
    }

    SkString onShortName() override {
        return fName;
    }

    SkISize onISize() override {
        return SkISize::Make(SkScalarCeilToInt(fRRect.rect().width()),
                             SkScalarCeilToInt(fRRect.rect().height()));
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkLayerDrawLooper::Builder looperBuilder;
        {
            SkLayerDrawLooper::LayerInfo info;
            info.fPaintBits = SkLayerDrawLooper::kMaskFilter_Bit
<<<<<<< HEAD
                | SkLayerDrawLooper::kColorFilter_Bit;
=======
                              | SkLayerDrawLooper::kColorFilter_Bit;
>>>>>>> miniblink49
            info.fColorMode = SkXfermode::kSrc_Mode;
            info.fOffset = SkPoint::Make(SkIntToScalar(-1), SkIntToScalar(0));
            info.fPostTranslate = false;
            SkPaint* paint = looperBuilder.addLayerOnTop(info);
<<<<<<< HEAD
            paint->setMaskFilter(SkBlurMaskFilter::Make(
                kNormal_SkBlurStyle,
                SkBlurMask::ConvertRadiusToSigma(SK_ScalarHalf),
                SkBlurMaskFilter::kHighQuality_BlurFlag));
            paint->setColorFilter(SkColorFilter::MakeModeFilter(
                sk_tool_utils::color_to_565(SK_ColorLTGRAY),
                SkXfermode::kSrcIn_Mode));
            paint->setColor(sk_tool_utils::color_to_565(SK_ColorGRAY));
=======
            SkMaskFilter* maskFilter = SkBlurMaskFilter::Create(
                    kNormal_SkBlurStyle,
                    SkBlurMask::ConvertRadiusToSigma(SK_ScalarHalf),
                    SkBlurMaskFilter::kHighQuality_BlurFlag);
            paint->setMaskFilter(maskFilter)->unref();
            SkColorFilter* colorFilter = SkColorFilter::CreateModeFilter(SK_ColorLTGRAY,
                    SkXfermode::kSrcIn_Mode);
            paint->setColorFilter(colorFilter)->unref();
            paint->setColor(SK_ColorGRAY);
>>>>>>> miniblink49
        }
        {
            SkLayerDrawLooper::LayerInfo info;
            looperBuilder.addLayerOnTop(info);
        }
        SkPaint paint;
        canvas->drawRect(fRRect.rect(), paint);

<<<<<<< HEAD
        paint.setLooper(looperBuilder.detach());
=======
        paint.setLooper(looperBuilder.detachLooper())->unref();
>>>>>>> miniblink49
        paint.setColor(SK_ColorCYAN);
        paint.setAntiAlias(true);

        canvas->drawRRect(fRRect, paint);
    }

private:
<<<<<<< HEAD
    SkString fName;
    SkRRect fRRect;
    int fWidth, fHeight;
=======
    SkString        fName;
    SkRRect         fRRect;
>>>>>>> miniblink49

    typedef skiagm::GM INHERITED;
};

#include "SkGradientShader.h"
/*
 * Spits out a dummy gradient to test blur with shader on paint
 */
<<<<<<< HEAD
static sk_sp<SkShader> MakeRadial()
{
=======
static SkShader* MakeRadial() {
>>>>>>> miniblink49
    SkPoint pts[2] = {
        { 0, 0 },
        { SkIntToScalar(100), SkIntToScalar(100) }
    };
    SkShader::TileMode tm = SkShader::kClamp_TileMode;
<<<<<<< HEAD
    const SkColor colors[] = {
        SK_ColorRED,
        SK_ColorGREEN,
    };
    const SkScalar pos[] = { SK_Scalar1 / 4, SK_Scalar1 * 3 / 4 };
=======
    const SkColor colors[] = { SK_ColorRED, SK_ColorGREEN, };
    const SkScalar pos[] = { SK_Scalar1/4, SK_Scalar1*3/4 };
>>>>>>> miniblink49
    SkMatrix scale;
    scale.setScale(0.5f, 0.5f);
    scale.postTranslate(5.f, 5.f);
    SkPoint center0, center1;
    center0.set(SkScalarAve(pts[0].fX, pts[1].fX),
<<<<<<< HEAD
        SkScalarAve(pts[0].fY, pts[1].fY));
    center1.set(SkScalarInterp(pts[0].fX, pts[1].fX, SkIntToScalar(3) / 5),
        SkScalarInterp(pts[0].fY, pts[1].fY, SkIntToScalar(1) / 4));
    return SkGradientShader::MakeTwoPointConical(center1, (pts[1].fX - pts[0].fX) / 7,
        center0, (pts[1].fX - pts[0].fX) / 2,
        colors, pos, SK_ARRAY_COUNT(colors), tm,
        0, &scale);
=======
                SkScalarAve(pts[0].fY, pts[1].fY));
    center1.set(SkScalarInterp(pts[0].fX, pts[1].fX, SkIntToScalar(3)/5),
                SkScalarInterp(pts[0].fY, pts[1].fY, SkIntToScalar(1)/4));
    return SkGradientShader::CreateTwoPointConical(center1, (pts[1].fX - pts[0].fX) / 7,
                                                   center0, (pts[1].fX - pts[0].fX) / 2,
                                                   colors, pos, SK_ARRAY_COUNT(colors), tm,
                                                   0, &scale);
>>>>>>> miniblink49
}

// Simpler blurred RR test cases where all the radii are the same.
class SimpleBlurRoundRectGM : public skiagm::GM {
public:
    SimpleBlurRoundRectGM()
<<<<<<< HEAD
        : fName("simpleblurroundrect")
    {
    }

protected:
    SkString onShortName() override
    {
        return fName;
    }

    SkISize onISize() override
    {
        return SkISize::Make(1000, 500);
    }

    void onDraw(SkCanvas* canvas) override
    {
        canvas->scale(1.5f, 1.5f);
        canvas->translate(50, 50);

        const float blurRadii[] = { 1, 5, 10, 20 };
        const int cornerRadii[] = { 1, 5, 10, 20 };
=======
        : fName("simpleblurroundrect") {
    }

protected:

    SkString onShortName() override {
        return fName;
    }

    SkISize onISize() override {
        return SkISize::Make(1000, 500);
    }

    void onDraw(SkCanvas* canvas) override {
        canvas->scale(1.5f, 1.5f);
        canvas->translate(50,50);

        const float blurRadii[] = { 1,5,10,20 };
        const int cornerRadii[] = { 1,5,10,20 };
>>>>>>> miniblink49
        const SkRect r = SkRect::MakeWH(SkIntToScalar(25), SkIntToScalar(25));
        for (size_t i = 0; i < SK_ARRAY_COUNT(blurRadii); ++i) {
            SkAutoCanvasRestore autoRestore(canvas, true);
            canvas->translate(0, (r.height() + SkIntToScalar(50)) * i);
            for (size_t j = 0; j < SK_ARRAY_COUNT(cornerRadii); ++j) {
                for (int k = 0; k <= 1; k++) {
<<<<<<< HEAD
                    SkPaint paint;
                    paint.setColor(SK_ColorBLACK);
                    paint.setMaskFilter(SkBlurMaskFilter::Make(kNormal_SkBlurStyle,
                        SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(blurRadii[i])),
                        SkBlurMaskFilter::kHighQuality_BlurFlag));

                    bool useRadial = SkToBool(k);
                    if (useRadial) {
                        paint.setShader(MakeRadial());
=======
                    SkMaskFilter* filter = SkBlurMaskFilter::Create(
                        kNormal_SkBlurStyle,
                        SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(blurRadii[i])),
                        SkBlurMaskFilter::kHighQuality_BlurFlag);
                    SkPaint paint;
                    paint.setColor(SK_ColorBLACK);
                    paint.setMaskFilter(filter)->unref();

                    bool useRadial = SkToBool(k);
                    if (useRadial) {
                        paint.setShader(MakeRadial())->unref();
>>>>>>> miniblink49
                    }

                    SkRRect rrect;
                    rrect.setRectXY(r, SkIntToScalar(cornerRadii[j]),
<<<<<<< HEAD
                        SkIntToScalar(cornerRadii[j]));
=======
                                    SkIntToScalar(cornerRadii[j]));
>>>>>>> miniblink49
                    canvas->drawRRect(rrect, paint);
                    canvas->translate(r.width() + SkIntToScalar(50), 0);
                }
            }
        }
    }
<<<<<<< HEAD

private:
    const SkString fName;

    typedef skiagm::GM INHERITED;
=======
private:
    const SkString  fName;

    typedef         skiagm::GM INHERITED;
>>>>>>> miniblink49
};

// Create one with dimensions/rounded corners based on the skp
//
// TODO(scroggo): Disabled in an attempt to rememdy
// https://code.google.com/p/skia/issues/detail?id=1801 ('Win7 Test bots all failing GenerateGMs:
// ran wrong number of tests')
//DEF_GM(return new BlurRoundRectGM(600, 5514, 6);)

// Rounded rect with two opposite corners with large radii, the other two
// small.
DEF_GM(return new BlurRoundRectGM(100, 100);)

DEF_GM(return new SimpleBlurRoundRectGM();)
