/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gm.h"

#include "Resources.h"
#include "SkBlurImageFilter.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkColorFilterImageFilter.h"
#include "SkColorMatrixFilter.h"
=======
#include "SkColorFilterImageFilter.h"
#include "SkColorMatrixFilter.h"
#include "SkCanvas.h"
>>>>>>> miniblink49
#include "SkGradientShader.h"
#include "SkStream.h"
#include "SkTypeface.h"

/*
 * Spits out a dummy gradient to test blur with shader on paint
 */
<<<<<<< HEAD
static sk_sp<SkShader> MakeLinear()
{
    static const SkPoint kPts[] = { { 0, 0 }, { 32, 32 } };
    static const SkScalar kPos[] = { 0, SK_Scalar1 / 2, SK_Scalar1 };
    static const SkColor kColors[] = { 0x80F00080, 0xF0F08000, 0x800080F0 };
    return SkGradientShader::MakeLinear(kPts, kColors, kPos, SK_ARRAY_COUNT(kColors),
        SkShader::kClamp_TileMode);
}

static sk_sp<SkImageFilter> make_grayscale(sk_sp<SkImageFilter> input)
{
=======
static SkShader* MakeLinear() {
    static const SkPoint     kPts[] = { { 0, 0 }, { 32, 32 } };
    static const SkScalar    kPos[] = { 0, SK_Scalar1/2, SK_Scalar1 };
    static const SkColor kColors[] = {0x80F00080, 0xF0F08000, 0x800080F0 };
    return SkGradientShader::CreateLinear(kPts, kColors, kPos,
                                          SK_ARRAY_COUNT(kColors), SkShader::kClamp_TileMode);
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
    sk_sp<SkColorFilter> filter(SkColorFilter::MakeMatrixFilterRowMajor255(matrix));
    return SkColorFilterImageFilter::Make(std::move(filter), std::move(input));
}

static sk_sp<SkImageFilter> make_blur(float amount, sk_sp<SkImageFilter> input)
{
    return SkBlurImageFilter::Make(amount, amount, std::move(input));
=======
    SkAutoTUnref<SkColorFilter> filter(SkColorMatrixFilter::Create(matrix));
    return SkColorFilterImageFilter::Create(filter, input);
}

static SkImageFilter* make_blur(float amount, SkImageFilter* input = NULL) {
    return SkBlurImageFilter::Create(amount, amount, input);
>>>>>>> miniblink49
}

namespace skiagm {

class ColorEmojiGM : public GM {
public:
<<<<<<< HEAD
    ColorEmojiGM() { }

protected:
    struct EmojiFont {
        sk_sp<SkTypeface> typeface;
        const char* text;
    } emojiFont;
    virtual void onOnceBeforeDraw() override
    {
        emojiFont.typeface = sk_tool_utils::emoji_typeface();
        emojiFont.text = sk_tool_utils::emoji_sample_text();
    }

    SkString onShortName() override
    {
        SkString name("coloremoji");
        name.append(sk_tool_utils::platform_os_emoji());
        return name;
    }

    SkISize onISize() override
    {
        return SkISize::Make(650, 900);
    }

    void onDraw(SkCanvas* canvas) override
    {

        canvas->drawColor(sk_tool_utils::color_to_565(SK_ColorGRAY));

        SkPaint paint;
        paint.setTypeface(emojiFont.typeface);
        const char* text = emojiFont.text;

        // draw text at different point sizes
        const int textSize[] = {
            10,
            30,
            50,
        };
        const int textYOffset[] = {
            10,
            40,
            100,
        };
        SkASSERT(sizeof(textSize) == sizeof(textYOffset));
        size_t y_offset = 0;
        for (size_t y = 0; y < sizeof(textSize) / sizeof(int); y++) {
            paint.setTextSize(SkIntToScalar(textSize[y]));
            canvas->drawText(text, strlen(text), 10, SkIntToScalar(textYOffset[y]), paint);
            y_offset += textYOffset[y];
        }

        // draw with shaders and image filters
        for (int makeLinear = 0; makeLinear < 2; makeLinear++) {
            for (int makeBlur = 0; makeBlur < 2; makeBlur++) {
                for (int makeGray = 0; makeGray < 2; makeGray++) {
                    SkPaint shaderPaint;
                    shaderPaint.setTypeface(sk_ref_sp(paint.getTypeface()));
                    if (SkToBool(makeLinear)) {
                        shaderPaint.setShader(MakeLinear());
                    }

                    if (SkToBool(makeBlur) && SkToBool(makeGray)) {
                        sk_sp<SkImageFilter> grayScale(make_grayscale(nullptr));
                        sk_sp<SkImageFilter> blur(make_blur(3.0f, std::move(grayScale)));
                        shaderPaint.setImageFilter(std::move(blur));
                    } else if (SkToBool(makeBlur)) {
                        shaderPaint.setImageFilter(make_blur(3.0f, nullptr));
                    } else if (SkToBool(makeGray)) {
                        shaderPaint.setImageFilter(make_grayscale(nullptr));
                    }
                    shaderPaint.setTextSize(30);
                    canvas->drawText(text, strlen(text), 380, SkIntToScalar(y_offset),
                        shaderPaint);
                    y_offset += 32;
                }
            }
        }

        // setup work needed to draw text with different clips
        canvas->translate(10, 160);
        paint.setTextSize(40);

        // compute the bounds of the text
        SkRect bounds;
        paint.measureText(text, strlen(text), &bounds);

        const SkScalar boundsHalfWidth = bounds.width() * SK_ScalarHalf;
        const SkScalar boundsHalfHeight = bounds.height() * SK_ScalarHalf;
        const SkScalar boundsQuarterWidth = boundsHalfWidth * SK_ScalarHalf;
        const SkScalar boundsQuarterHeight = boundsHalfHeight * SK_ScalarHalf;

        SkRect upperLeftClip = SkRect::MakeXYWH(bounds.left(), bounds.top(),
            boundsHalfWidth, boundsHalfHeight);
        SkRect lowerRightClip = SkRect::MakeXYWH(bounds.centerX(), bounds.centerY(),
            boundsHalfWidth, boundsHalfHeight);
        SkRect interiorClip = bounds;
        interiorClip.inset(boundsQuarterWidth, boundsQuarterHeight);

        const SkRect clipRects[] = { bounds, upperLeftClip, lowerRightClip, interiorClip };

        SkPaint clipHairline;
        clipHairline.setColor(SK_ColorWHITE);
        clipHairline.setStyle(SkPaint::kStroke_Style);

        for (size_t x = 0; x < sizeof(clipRects) / sizeof(SkRect); ++x) {
            canvas->save();
            canvas->drawRect(clipRects[x], clipHairline);
            paint.setAlpha(0x20);
            canvas->drawText(text, strlen(text), 0, 0, paint);
            canvas->clipRect(clipRects[x]);
            paint.setAlpha(0xFF);
            canvas->drawText(text, strlen(text), 0, 0, paint);
            canvas->restore();
            canvas->translate(0, bounds.height() + SkIntToScalar(25));
        }
    }

=======
    ColorEmojiGM() : fCBDT_CBLC_Typeface(NULL), fSBIX_Typeface(NULL) { }

protected:
    struct EmojiFont {
        SkTypeface* typeface;
        const char* text;
    } emojiFonts[2];
    virtual void onOnceBeforeDraw() override {
        fCBDT_CBLC_Typeface.reset(GetResourceAsTypeface("/fonts/Funkster.ttf"));
        emojiFonts[0].typeface = fCBDT_CBLC_Typeface;
        emojiFonts[0].text = "hamburgerfons";

        fSBIX_Typeface.reset(SkTypeface::CreateFromName("Apple Color Emoji", SkTypeface::kNormal));
        emojiFonts[1].typeface = fSBIX_Typeface;
        emojiFonts[1].text = "\xF0\x9F\x92\xB0" "\xF0\x9F\x8F\xA1" "\xF0\x9F\x8E\x85" // 💰🏡🎅
                             "\xF0\x9F\x8D\xAA" "\xF0\x9F\x8D\x95" "\xF0\x9F\x9A\x80" // 🍪🍕🚀
                             "\xF0\x9F\x9A\xBB" "\xF0\x9F\x92\xA9" "\xF0\x9F\x93\xB7" // 🚻💩📷
                             "\xF0\x9F\x93\xA6" // 📦
                             "\xF0\x9F\x87\xBA" "\xF0\x9F\x87\xB8" "\xF0\x9F\x87\xA6"; // 🇺🇸🇦
    }

    SkString onShortName() override {
        return SkString("coloremoji");
    }

    SkISize onISize() override {
        return SkISize::Make(650, 900);
    }

    void onDraw(SkCanvas* canvas) override {

        canvas->drawColor(SK_ColorGRAY);

        for (size_t i = 0; i < SK_ARRAY_COUNT(emojiFonts); ++i) {
            SkPaint paint;
            paint.setTypeface(emojiFonts[i].typeface);
            const char* text = emojiFonts[i].text;

            // draw text at different point sizes
            const int textSize[] = { 10, 30, 50, };
            const int textYOffset[] = { 10, 40, 100, };
            SkASSERT(sizeof(textSize) == sizeof(textYOffset));
            size_t y_offset = 0;
            for (size_t y = 0; y < sizeof(textSize) / sizeof(int); y++) {
                paint.setTextSize(SkIntToScalar(textSize[y]));
                canvas->drawText(text, strlen(text), 10, SkIntToScalar(textYOffset[y]), paint);
                y_offset += textYOffset[y];
            }

            // draw with shaders and image filters
            for (int makeLinear = 0; makeLinear < 2; makeLinear++) {
                for (int makeBlur = 0; makeBlur < 2; makeBlur++) {
                    for (int makeGray = 0; makeGray < 2; makeGray++) {
                        SkPaint shaderPaint;
                        shaderPaint.setTypeface(paint.getTypeface());
                        if (SkToBool(makeLinear)) {
                            shaderPaint.setShader(MakeLinear())->unref();
                        }

                        if (SkToBool(makeBlur) && SkToBool(makeGray)) {
                            SkAutoTUnref<SkImageFilter> grayScale(make_grayscale(NULL));
                            SkAutoTUnref<SkImageFilter> blur(make_blur(3.0f, grayScale));
                            shaderPaint.setImageFilter(blur);
                        } else if (SkToBool(makeBlur)) {
                            SkAutoTUnref<SkImageFilter> blur(make_blur(3.0f, NULL));
                            shaderPaint.setImageFilter(blur);
                        } else if (SkToBool(makeGray)) {
                            SkAutoTUnref<SkImageFilter> grayScale(make_grayscale(NULL));
                            shaderPaint.setImageFilter(grayScale);
                        }
                        shaderPaint.setTextSize(30);
                        canvas->drawText(text, strlen(text), 380, SkIntToScalar(y_offset),
                                         shaderPaint);
                        y_offset += 32;
                    }
                }
            }

            // setup work needed to draw text with different clips
            canvas->translate(10, 160);
            paint.setTextSize(40);

            // compute the bounds of the text
            SkRect bounds;
            paint.measureText(text, strlen(text), &bounds);

            const SkScalar boundsHalfWidth = bounds.width() * SK_ScalarHalf;
            const SkScalar boundsHalfHeight = bounds.height() * SK_ScalarHalf;
            const SkScalar boundsQuarterWidth = boundsHalfWidth * SK_ScalarHalf;
            const SkScalar boundsQuarterHeight = boundsHalfHeight * SK_ScalarHalf;

            SkRect upperLeftClip = SkRect::MakeXYWH(bounds.left(), bounds.top(),
                                                    boundsHalfWidth, boundsHalfHeight);
            SkRect lowerRightClip = SkRect::MakeXYWH(bounds.centerX(), bounds.centerY(),
                                                     boundsHalfWidth, boundsHalfHeight);
            SkRect interiorClip = bounds;
            interiorClip.inset(boundsQuarterWidth, boundsQuarterHeight);

            const SkRect clipRects[] = { bounds, upperLeftClip, lowerRightClip, interiorClip };

            SkPaint clipHairline;
            clipHairline.setColor(SK_ColorWHITE);
            clipHairline.setStyle(SkPaint::kStroke_Style);

            for (size_t x = 0; x < sizeof(clipRects) / sizeof(SkRect); ++x) {
                canvas->save();
                canvas->drawRect(clipRects[x], clipHairline);
                paint.setAlpha(0x20);
                canvas->drawText(text, strlen(text), 0, 0, paint);
                canvas->clipRect(clipRects[x]);
                paint.setAlpha(0xFF);
                canvas->drawText(text, strlen(text), 0, 0, paint);
                canvas->restore();
                canvas->translate(0, bounds.height() + SkIntToScalar(25));
            }
        }
    }

private:
    SkAutoTUnref<SkTypeface> fCBDT_CBLC_Typeface;
    SkAutoTUnref<SkTypeface> fSBIX_Typeface;

>>>>>>> miniblink49
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new ColorEmojiGM;)
=======
static GM* MyFactory(void*) { return new ColorEmojiGM; }
static GMRegistry reg(MyFactory);
>>>>>>> miniblink49

}
