/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "DecodeFile.h"
#include "SampleCode.h"
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkCornerPathEffect.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
=======
#include "SampleCode.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkCornerPathEffect.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkImageDecoder.h"
>>>>>>> miniblink49
#include "SkPath.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkView.h"
#include "SkXfermode.h"

#include "SkColorPriv.h"
#include "SkStream.h"

class LinesView : public SampleView {
public:
    LinesView() { }

protected:
    // overrides from SkEventSink
    bool onQuery(SkEvent* evt) override
    {
=======
#include "SkUtils.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkXfermode.h"

#include "SkStream.h"
#include "SkXMLParser.h"
#include "SkColorPriv.h"
#include "SkImageDecoder.h"

class LinesView : public SampleView {
public:
    LinesView() {}

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Lines");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    /*
     0x1F * x + 0x1F * (32 - x)
     */
<<<<<<< HEAD
    void drawRings(SkCanvas* canvas)
    {
        canvas->scale(SkIntToScalar(1) / 2, SkIntToScalar(1) / 2);

        SkRect r;
=======
    void drawRings(SkCanvas* canvas) {
        canvas->scale(SkIntToScalar(1)/2, SkIntToScalar(1)/2);

        SkRect  r;
>>>>>>> miniblink49
        SkScalar x = SkIntToScalar(10);
        SkScalar y = SkIntToScalar(10);
        r.set(x, y, x + SkIntToScalar(100), y + SkIntToScalar(100));

        SkPaint paint;
<<<<<<< HEAD
        //   paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setStrokeWidth(SkScalarHalf(SkIntToScalar(3)));
        paint.setColor(0xFFFF8800);
        //   paint.setColor(0xFFFFFFFF);
        canvas->drawRect(r, paint);
    }

    void onDrawContent(SkCanvas* canvas) override
    {
        SkBitmap bm;
        decode_file("/kill.gif", &bm);
        canvas->drawBitmap(bm, 0, 0, nullptr);
=======
     //   paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setStrokeWidth(SkScalarHalf(SkIntToScalar(3)));
        paint.setColor(0xFFFF8800);
     //   paint.setColor(0xFFFFFFFF);
        canvas->drawRect(r, paint);
    }

    virtual void onDrawContent(SkCanvas* canvas) {
        SkBitmap bm;
        SkImageDecoder::DecodeFile("/kill.gif", &bm);
        canvas->drawBitmap(bm, 0, 0, NULL);
>>>>>>> miniblink49

        this->drawRings(canvas);
        return;

        SkPaint paint;

<<<<<<< HEAD
        //  fAlpha = 0x80;
=======
      //  fAlpha = 0x80;
>>>>>>> miniblink49
        paint.setColor(SK_ColorWHITE);
        paint.setAlpha(fAlpha & 0xFF);
        SkRect r;

        SkScalar x = SkIntToScalar(10);
        SkScalar y = SkIntToScalar(10);
        r.set(x, y, x + SkIntToScalar(100), y + SkIntToScalar(100));
        canvas->drawRect(r, paint);
        return;

<<<<<<< HEAD
        paint.setColor(0xffffff00); // yellow
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setStrokeWidth(SkIntToScalar(2));

        //        y += SK_Scalar1/2;

        canvas->drawLine(x, y, x + SkIntToScalar(90), y + SkIntToScalar(90), paint);

        paint.setAntiAlias(true); // with anti-aliasing
=======
        paint.setColor(0xffffff00);            // yellow
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setStrokeWidth(SkIntToScalar(2));

//        y += SK_Scalar1/2;

        canvas->drawLine(x, y, x + SkIntToScalar(90), y + SkIntToScalar(90), paint);

        paint.setAntiAlias(true);              // with anti-aliasing
>>>>>>> miniblink49
        y += SkIntToScalar(10);
        canvas->drawLine(x, y, x + SkIntToScalar(90), y + SkIntToScalar(90), paint);
    }

<<<<<<< HEAD
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned) override
    {
        fAlpha = SkScalarRoundToInt(y);
        this->inval(nullptr);
        return nullptr;
    }

private:
=======
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned) override {
        fAlpha = SkScalarRoundToInt(y);
        this->inval(NULL);
        return NULL;
    }
private:

>>>>>>> miniblink49
    int fAlpha;
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new LinesView; }
static SkViewRegister reg(MyFactory);
