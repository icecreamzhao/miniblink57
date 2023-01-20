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
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkView.h"

class TwoPtConicalView : public SampleView {
public:
    TwoPtConicalView() { }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
    {
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"


class TwoPtConicalView : public SampleView {
public:
    TwoPtConicalView() {}

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "2PtConical");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
=======
    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        canvas->translate(SkIntToScalar(10), SkIntToScalar(20));

        SkColor colors[] = { SK_ColorRED, SK_ColorBLUE };
        SkPoint c0 = { 0, 0 };
        SkScalar r0 = 100;
        SkPoint c1 = { 100, 100 };
        SkScalar r1 = 100;
<<<<<<< HEAD
        SkPaint paint;
        paint.setShader(SkGradientShader::MakeTwoPointConical(c0, r0, c1, r1, colors,
            nullptr, 2,
            SkShader::kClamp_TileMode));
=======
        SkShader* s = SkGradientShader::CreateTwoPointConical(c0, r0, c1, r1, colors,
                                                             NULL, 2,
                                                             SkShader::kClamp_TileMode);

        SkPaint paint;
        paint.setShader(s)->unref();
>>>>>>> miniblink49
        canvas->drawPaint(paint);
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new TwoPtConicalView; }
static SkViewRegister reg(MyFactory);
