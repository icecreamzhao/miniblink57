<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SampleCode.h"
<<<<<<< HEAD
#include "SkBlurDrawLooper.h"
#include "SkBlurMask.h"
=======
#include "SkBlurMask.h"
#include "SkBlurDrawLooper.h"
>>>>>>> miniblink49
#include "SkCanvas.h"
#include "SkPath.h"
#include "SkPathMeasure.h"

<<<<<<< HEAD
#define REPEAT_COUNT 1

static void textStrokePath(SkCanvas* canvas)
{
    SkPaint paint;
    SkPath path;
    SkRect rect;

    canvas->save();
    canvas->scale(SkIntToScalar(250), SkIntToScalar(250));

    rect.set(0.0f, 0.21f,
        0.78f, 0.99f);
=======
#define REPEAT_COUNT    1

static void textStrokePath(SkCanvas* canvas) {
    SkPaint paint;
    SkPath  path;
    SkRect  rect;

    canvas->save();
    canvas->scale(SkIntToScalar(250),SkIntToScalar(250));

    rect.set(0.0f,  0.21f,
             0.78f, 0.99f);
>>>>>>> miniblink49

    path.addArc(rect, SkIntToScalar(280), SkIntToScalar(350));

    paint.setAntiAlias(true);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setColor(0xFFFF0000);
    paint.setTextSize(0.085f);
    paint.setStrokeWidth(.005f);

    canvas->drawPath(path, paint);

<<<<<<< HEAD
    paint.setLooper(SkBlurDrawLooper::Make(SK_ColorBLACK, SkBlurMask::ConvertRadiusToSigma(0.002f),
        0.0f, 0.0f));

    const char* text = "DRAWING STROKED TEXT WITH A BLUR ON A PATH";
    size_t len = strlen(text);

    canvas->drawTextOnPathHV(text, len, path, 0,
        -0.025f, paint);
    canvas->restore();
}

static void textPathMatrix(SkCanvas* canvas)
{
    SkPaint paint;
    SkPath path;
=======
    paint.setLooper(SkBlurDrawLooper::Create(SK_ColorBLACK,
                                             SkBlurMask::ConvertRadiusToSigma(0.002f),
                                             0.0f,
                                             0.0f))->unref();

    const char* text = "DRAWING STROKED TEXT WITH A BLUR ON A PATH";
    size_t      len = strlen(text);

    canvas->drawTextOnPathHV(text, len, path, 0,
                             -0.025f, paint);
    canvas->restore();
}

static void textPathMatrix(SkCanvas* canvas) {
    SkPaint paint;
    SkPath  path;
>>>>>>> miniblink49
    SkMatrix matrix;

    path.moveTo(SkIntToScalar(050), SkIntToScalar(200));
    path.quadTo(SkIntToScalar(250), SkIntToScalar(000),
<<<<<<< HEAD
        SkIntToScalar(450), SkIntToScalar(200));
=======
                SkIntToScalar(450), SkIntToScalar(200));
>>>>>>> miniblink49

    paint.setAntiAlias(true);

    paint.setStyle(SkPaint::kStroke_Style);
    canvas->drawPath(path, paint);
    paint.setStyle(SkPaint::kFill_Style);
    paint.setTextSize(SkIntToScalar(48));
    paint.setTextAlign(SkPaint::kRight_Align);

    const char* text = "Reflection";
<<<<<<< HEAD
    size_t len = strlen(text);

    SkPathMeasure meas(path, false);
    SkScalar pathLen = meas.getLength();

    canvas->drawTextOnPath(text, len, path, nullptr, paint);
=======
    size_t      len = strlen(text);

    SkPathMeasure   meas(path, false);
    SkScalar pathLen = meas.getLength();

    canvas->drawTextOnPath(text, len, path, NULL, paint);
>>>>>>> miniblink49

    paint.setColor(SK_ColorRED);
    matrix.setScale(-SK_Scalar1, SK_Scalar1);
    matrix.postTranslate(pathLen, 0);
    canvas->drawTextOnPath(text, len, path, &matrix, paint);

    paint.setColor(SK_ColorBLUE);
    matrix.setScale(SK_Scalar1, -SK_Scalar1);
    canvas->drawTextOnPath(text, len, path, &matrix, paint);

    paint.setColor(SK_ColorGREEN);
    matrix.setScale(-SK_Scalar1, -SK_Scalar1);
    matrix.postTranslate(pathLen, 0);
    canvas->drawTextOnPath(text, len, path, &matrix, paint);
}

class TextOnPathView : public SampleView {
public:
<<<<<<< HEAD
    SkPath fPath;
    SkScalar fHOffset;

protected:
    void onOnceBeforeDraw() override
    {
        SkRect r;
        r.set(SkIntToScalar(100), SkIntToScalar(100),
            SkIntToScalar(300), SkIntToScalar(300));
=======
    SkPath      fPath;
    SkScalar    fHOffset;

protected:
    void onOnceBeforeDraw() override {
        SkRect r;
        r.set(SkIntToScalar(100), SkIntToScalar(100),
              SkIntToScalar(300), SkIntToScalar(300));
>>>>>>> miniblink49
        fPath.addOval(r);
        fPath.offset(SkIntToScalar(-50), SkIntToScalar(-50));

        fHOffset = SkIntToScalar(50);
    }

    // overrides from SkEventSink
<<<<<<< HEAD
    bool onQuery(SkEvent* evt) override
    {
=======
    bool onQuery(SkEvent* evt) override {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Text On Path");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
=======
    void onDrawContent(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setTextSize(SkIntToScalar(48));

        const char* text = "Hamburgefons";
<<<<<<< HEAD
        size_t len = strlen(text);
=======
        size_t      len = strlen(text);
>>>>>>> miniblink49

        for (int j = 0; j < REPEAT_COUNT; j++) {
            SkScalar x = fHOffset;

            paint.setColor(SK_ColorBLACK);
            canvas->drawTextOnPathHV(text, len, fPath,
<<<<<<< HEAD
                x, paint.getTextSize() / 2, paint);

            paint.setColor(SK_ColorRED);
            canvas->drawTextOnPathHV(text, len, fPath,
                x + SkIntToScalar(50), 0, paint);

            paint.setColor(SK_ColorBLUE);
            canvas->drawTextOnPathHV(text, len, fPath,
                x + SkIntToScalar(100), -paint.getTextSize() / 2, paint);
=======
                                     x, paint.getTextSize()/2, paint);

            paint.setColor(SK_ColorRED);
            canvas->drawTextOnPathHV(text, len, fPath,
                                     x + SkIntToScalar(50), 0, paint);

            paint.setColor(SK_ColorBLUE);
            canvas->drawTextOnPathHV(text, len, fPath,
                         x + SkIntToScalar(100), -paint.getTextSize()/2, paint);
>>>>>>> miniblink49
        }

        paint.setColor(SK_ColorGREEN);
        paint.setStyle(SkPaint::kStroke_Style);
        canvas->drawPath(fPath, paint);

        canvas->translate(SkIntToScalar(275), 0);
        textStrokePath(canvas);

        canvas->translate(SkIntToScalar(-275), SkIntToScalar(250));
        textPathMatrix(canvas);

        if (REPEAT_COUNT > 1)
<<<<<<< HEAD
            this->inval(nullptr);
    }

    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override
    {
        fHints += 1;
        this->inval(nullptr);
        return this->INHERITED::onFindClickHandler(x, y, modi);
    }

    bool onClick(Click* click) override
    {
=======
            this->inval(NULL);
    }

    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override {
        fHints += 1;
        this->inval(NULL);
        return this->INHERITED::onFindClickHandler(x, y, modi);
    }

    bool onClick(Click* click) override {
>>>>>>> miniblink49
        return this->INHERITED::onClick(click);
    }

private:
    int fHints;
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static SkView* MyFactory()
{
=======
static SkView* MyFactory() {
>>>>>>> miniblink49
    return new TextOnPathView;
}

static SkViewRegister reg(MyFactory);
