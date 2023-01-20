/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBlurImageFilter.h"
#include "SkRandom.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkBlurImageFilter.h"
#include "SkRandom.h"
>>>>>>> miniblink49

#define WIDTH 500
#define HEIGHT 500

<<<<<<< HEAD
void imageblurgm_draw(SkScalar fSigmaX, SkScalar fSigmaY, SkCanvas* canvas)
{
    SkPaint paint;
    paint.setImageFilter(SkBlurImageFilter::Make(fSigmaX, fSigmaY, nullptr));
    canvas->saveLayer(nullptr, &paint);
    const char* str = "The quick brown fox jumped over the lazy dog.";

    SkRandom rand;
    SkPaint textPaint;
    textPaint.setAntiAlias(true);
    sk_tool_utils::set_portable_typeface(&textPaint);
    for (int i = 0; i < 25; ++i) {
        int x = rand.nextULessThan(WIDTH);
        int y = rand.nextULessThan(HEIGHT);
        textPaint.setColor(sk_tool_utils::color_to_565(rand.nextBits(24) | 0xFF000000));
        textPaint.setTextSize(rand.nextRangeScalar(0, 300));
        canvas->drawText(str, strlen(str), SkIntToScalar(x),
            SkIntToScalar(y), textPaint);
    }
    canvas->restore();
}
DEF_SIMPLE_GM_BG(imageblur, canvas, WIDTH, HEIGHT, SK_ColorBLACK)
{
    imageblurgm_draw(24.0f, 0.0f, canvas);
}
DEF_SIMPLE_GM_BG(imageblur_large, canvas, WIDTH, HEIGHT, SK_ColorBLACK)
{
    imageblurgm_draw(80.0f, 80.0f, canvas);
=======
namespace skiagm {

class ImageBlurGM : public GM {
public:
    ImageBlurGM(SkScalar sigmaX, SkScalar sigmaY, const char* suffix)
        : fSigmaX(sigmaX), fSigmaY(sigmaY) {
        this->setBGColor(0xFF000000);
        fName.printf("imageblur%s", suffix);
    }

protected:

    SkString onShortName() override {
        return fName;
    }

    SkISize onISize() override {
        return SkISize::Make(WIDTH, HEIGHT);
    }

    void onDraw(SkCanvas* canvas) override {
        SkPaint paint;
        paint.setImageFilter(SkBlurImageFilter::Create(fSigmaX, fSigmaY))->unref();
        canvas->saveLayer(NULL, &paint);
        const char* str = "The quick brown fox jumped over the lazy dog.";

        SkRandom rand;
        SkPaint textPaint;
        textPaint.setAntiAlias(true);
        sk_tool_utils::set_portable_typeface(&textPaint);
        for (int i = 0; i < 25; ++i) {
            int x = rand.nextULessThan(WIDTH);
            int y = rand.nextULessThan(HEIGHT);
            textPaint.setColor(rand.nextBits(24) | 0xFF000000);
            textPaint.setTextSize(rand.nextRangeScalar(0, 300));
            canvas->drawText(str, strlen(str), SkIntToScalar(x),
                             SkIntToScalar(y), textPaint);
        }
        canvas->restore();
    }

private:
    SkScalar fSigmaX;
    SkScalar fSigmaY;
    SkString fName;

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static GM* MyFactory1(void*) { return new ImageBlurGM(24.0f, 0.0f, ""); }
static GMRegistry reg1(MyFactory1);

static GM* MyFactory2(void*) { return new ImageBlurGM(80.0f, 80.0f, "_large"); }
static GMRegistry reg2(MyFactory2);

>>>>>>> miniblink49
}
