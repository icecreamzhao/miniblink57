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
#include "SkBlurMask.h"
#include "SkBlurMaskFilter.h"
#include "SkCanvas.h"
<<<<<<< HEAD
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
=======
#include "SkDevice.h"
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
=======
#include "SkUtils.h"
#include "SkXfermode.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkView.h"
>>>>>>> miniblink49

#include "SkOSFile.h"
#include "SkStream.h"

class TextAlphaView : public SampleView {
public:
<<<<<<< HEAD
    TextAlphaView()
    {
=======
    TextAlphaView() {
>>>>>>> miniblink49
        fByte = 0xFF;
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    bool onQuery(SkEvent* evt) override
    {
=======
    bool onQuery(SkEvent* evt) override {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "TextAlpha");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
        const char* str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        SkPaint paint;
        SkScalar x = SkIntToScalar(10);
        SkScalar y = SkIntToScalar(20);
=======
    void onDrawContent(SkCanvas* canvas) override {
        const char* str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        SkPaint paint;
        SkScalar    x = SkIntToScalar(10);
        SkScalar    y = SkIntToScalar(20);
>>>>>>> miniblink49

        paint.setFlags(0x105);

        paint.setARGB(fByte, 0xFF, 0xFF, 0xFF);

<<<<<<< HEAD
        paint.setMaskFilter(SkBlurMaskFilter::Make(kNormal_SkBlurStyle,
            SkBlurMask::ConvertRadiusToSigma(3)));
=======
        paint.setMaskFilter(SkBlurMaskFilter::Create(kNormal_SkBlurStyle,
                                    SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(3))));
        paint.getMaskFilter()->unref();
>>>>>>> miniblink49

        SkRandom rand;

        for (int ps = 6; ps <= 35; ps++) {
            paint.setColor(rand.nextU() | (0xFF << 24));
            paint.setTextSize(SkIntToScalar(ps));
            paint.setTextSize(SkIntToScalar(24));
            canvas->drawText(str, strlen(str), x, y, paint);
<<<<<<< HEAD
            y += paint.getFontMetrics(nullptr);
        }
    }

    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned) override
    {
        return new Click(this);
    }

    bool onClick(Click* click) override
    {
=======
            y += paint.getFontMetrics(NULL);
        }
    }

    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned) override {
        return new Click(this);
    }

    bool onClick(Click* click) override {
>>>>>>> miniblink49
        int y = click->fICurr.fY;
        if (y < 0) {
            y = 0;
        } else if (y > 255) {
            y = 255;
        }
        fByte = y;
<<<<<<< HEAD
        this->inval(nullptr);
=======
        this->inval(NULL);
>>>>>>> miniblink49
        return true;
    }

private:
    int fByte;

    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new TextAlphaView; }
static SkViewRegister reg(MyFactory);
