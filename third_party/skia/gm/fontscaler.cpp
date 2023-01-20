/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkTypeface.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkTypeface.h"
>>>>>>> miniblink49

namespace skiagm {

class FontScalerGM : public GM {
public:
<<<<<<< HEAD
    FontScalerGM()
    {
        this->setBGColor(0xFFFFFFFF);
    }

    virtual ~FontScalerGM()
    {
    }

protected:
    SkString onShortName() override
    {
        SkString name("fontscaler");
        name.append(sk_tool_utils::major_platform_os_name());
        return name;
    }

    SkISize onISize() override
    {
=======
    FontScalerGM() {
        this->setBGColor(0xFFFFFFFF);
    }

    virtual ~FontScalerGM() {
    }

protected:

    SkString onShortName() override {
        return SkString("fontscaler");
    }

    SkISize onISize() override {
>>>>>>> miniblink49
        return SkISize::Make(1450, 750);
    }

    static void rotate_about(SkCanvas* canvas,
<<<<<<< HEAD
        SkScalar degrees,
        SkScalar px, SkScalar py)
    {
=======
                             SkScalar degrees,
                             SkScalar px, SkScalar py) {
>>>>>>> miniblink49
        canvas->translate(px, py);
        canvas->rotate(degrees);
        canvas->translate(-px, -py);
    }

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
=======
    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;

        paint.setAntiAlias(true);
        paint.setLCDRenderText(true);
        //With freetype the default (normal hinting) can be really ugly.
        //Most distros now set slight (vertical hinting only) in any event.
        paint.setHinting(SkPaint::kSlight_Hinting);
<<<<<<< HEAD
=======
        sk_tool_utils::set_portable_typeface(&paint, "Times Roman", SkTypeface::kNormal);
>>>>>>> miniblink49

        const char* text = "Hamburgefons ooo mmm";
        const size_t textLen = strlen(text);

        for (int j = 0; j < 2; ++j) {
            // This used to do 6 iterations but it causes the N4 to crash in the MSAA4 config.
            for (int i = 0; i < 5; ++i) {
                SkScalar x = SkIntToScalar(10);
                SkScalar y = SkIntToScalar(20);

                SkAutoCanvasRestore acr(canvas, true);
                canvas->translate(SkIntToScalar(50 + i * 230),
<<<<<<< HEAD
                    SkIntToScalar(20));
=======
                                  SkIntToScalar(20));
>>>>>>> miniblink49
                rotate_about(canvas, SkIntToScalar(i * 5), x, y * 10);

                {
                    SkPaint p;
                    p.setAntiAlias(true);
                    SkRect r;
                    r.set(x - SkIntToScalar(3), SkIntToScalar(15),
<<<<<<< HEAD
                        x - SkIntToScalar(1), SkIntToScalar(280));
=======
                          x - SkIntToScalar(1), SkIntToScalar(280));
>>>>>>> miniblink49
                    canvas->drawRect(r, p);
                }

                for (int ps = 6; ps <= 22; ps++) {
                    paint.setTextSize(SkIntToScalar(ps));
                    canvas->drawText(text, textLen, x, y, paint);
<<<<<<< HEAD
                    y += paint.getFontMetrics(nullptr);
=======
                    y += paint.getFontMetrics(NULL);
>>>>>>> miniblink49
                }
            }
            canvas->translate(0, SkIntToScalar(360));
            paint.setSubpixelText(true);
        }
    }

private:
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new FontScalerGM; }
static GMRegistry reg(MyFactory);

}
