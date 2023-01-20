<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
/* Tests text vertical text rendering with different fonts and centering.
 */

#include "SkCanvas.h"
#include "SkTypeface.h"
#include "gm.h"
=======

/* Tests text vertical text rendering with different fonts and centering.
 */

#include "gm.h"
#include "SkCanvas.h"
#include "SkTypeface.h"
>>>>>>> miniblink49

namespace skiagm {

class VertText2GM : public GM {
public:
<<<<<<< HEAD
    VertText2GM() { }

protected:
    void onOnceBeforeDraw() override
    {
        const int pointSize = 24;
        textHeight = SkIntToScalar(pointSize);
        fProp = SkTypeface::MakeFromName(sk_tool_utils::platform_font_name("sans-serif"),
            SkFontStyle());
        fMono = SkTypeface::MakeFromName(sk_tool_utils::platform_font_name("monospace"),
            SkFontStyle());
    }

    SkString onShortName() override
    {
        SkString name("verttext2");
        name.append(sk_tool_utils::major_platform_os_name());
        return name;
=======
    VertText2GM()
        : fProp(NULL)
        , fMono(NULL) {
    }

    virtual ~VertText2GM() {
        SkSafeUnref(fProp);
        SkSafeUnref(fMono);
    }

protected:
    void onOnceBeforeDraw() override {
        const int pointSize = 24;
        textHeight = SkIntToScalar(pointSize);
        fProp = sk_tool_utils::create_portable_typeface("Helvetica", SkTypeface::kNormal);
        fMono = sk_tool_utils::create_portable_typeface("Courier New", SkTypeface::kNormal);
    }

    SkString onShortName() override {
        return SkString("verttext2");
>>>>>>> miniblink49
    }

    SkISize onISize() override { return SkISize::Make(640, 480); }

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
=======
    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        for (int i = 0; i < 3; ++i) {
            SkPaint paint;
            paint.setColor(SK_ColorRED);
            paint.setAntiAlias(true);
            y = textHeight;
            canvas->drawLine(0, SkIntToScalar(10),
<<<<<<< HEAD
                SkIntToScalar(110), SkIntToScalar(10), paint);
            canvas->drawLine(0, SkIntToScalar(240),
                SkIntToScalar(110), SkIntToScalar(240), paint);
            canvas->drawLine(0, SkIntToScalar(470),
                SkIntToScalar(110), SkIntToScalar(470), paint);
            drawText(canvas, SkString("Proportional / Top Aligned"),
                fProp, SkPaint::kLeft_Align);
            drawText(canvas, SkString("<   Proportional / Centered   >"),
                fProp, SkPaint::kCenter_Align);
            drawText(canvas, SkString("Monospaced / Top Aligned"),
                fMono, SkPaint::kLeft_Align);
            drawText(canvas, SkString("<    Monospaced / Centered    >"),
                fMono, SkPaint::kCenter_Align);
=======
                    SkIntToScalar(110), SkIntToScalar(10), paint);
            canvas->drawLine(0, SkIntToScalar(240),
                    SkIntToScalar(110), SkIntToScalar(240), paint);
            canvas->drawLine(0, SkIntToScalar(470),
                    SkIntToScalar(110), SkIntToScalar(470), paint);
            drawText(canvas, SkString("Proportional / Top Aligned"),
                     fProp,  SkPaint::kLeft_Align);
            drawText(canvas, SkString("<   Proportional / Centered   >"),
                     fProp,  SkPaint::kCenter_Align);
            drawText(canvas, SkString("Monospaced / Top Aligned"),
                     fMono, SkPaint::kLeft_Align);
            drawText(canvas, SkString("<    Monospaced / Centered    >"),
                     fMono, SkPaint::kCenter_Align);
>>>>>>> miniblink49
            canvas->rotate(SkIntToScalar(-15));
            canvas->translate(textHeight * 4, SkIntToScalar(50));
            if (i > 0) {
                canvas->translate(0, SkIntToScalar(50));
            }
        }
    }

    void drawText(SkCanvas* canvas, const SkString& string,
<<<<<<< HEAD
        sk_sp<SkTypeface> family, SkPaint::Align alignment)
    {
=======
                  SkTypeface* family, SkPaint::Align alignment) {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setColor(SK_ColorBLACK);
        paint.setAntiAlias(true);
        paint.setVerticalText(true);
        paint.setTextAlign(alignment);
<<<<<<< HEAD
        paint.setTypeface(std::move(family));
        paint.setTextSize(textHeight);

        canvas->drawText(string.c_str(), string.size(), y,
            SkIntToScalar(alignment == SkPaint::kLeft_Align ? 10 : 240),
            paint);
=======
        paint.setTypeface(family);
        paint.setTextSize(textHeight);

        canvas->drawText(string.c_str(), string.size(), y,
                SkIntToScalar(alignment == SkPaint::kLeft_Align ? 10 : 240),
                paint);
>>>>>>> miniblink49
        y += textHeight;
    }

private:
    typedef GM INHERITED;
    SkScalar y, textHeight;
<<<<<<< HEAD
    sk_sp<SkTypeface> fProp;
    sk_sp<SkTypeface> fMono;
=======
    SkTypeface* fProp;
    SkTypeface* fMono;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new VertText2GM; }
static GMRegistry reg(MyFactory);

}
