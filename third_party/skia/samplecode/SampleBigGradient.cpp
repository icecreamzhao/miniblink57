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

#include "SampleCode.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkView.h"

static sk_sp<SkShader> make_grad(SkScalar w, SkScalar h)
{
    SkColor colors[] = { 0xFF000000, 0xFF333333 };
    SkPoint pts[] = { { 0, 0 }, { w, h } };
    return SkGradientShader::MakeLinear(pts, colors, nullptr, 2, SkShader::kClamp_TileMode);
=======
#include "SampleCode.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"

static SkShader* make_grad(SkScalar w, SkScalar h) {
    SkColor colors[] = { 0xFF000000, 0xFF333333 };
    SkPoint pts[] = { { 0, 0 }, { w, h } };
    return SkGradientShader::CreateLinear(pts, colors, NULL, 2,
                                          SkShader::kClamp_TileMode);
>>>>>>> miniblink49
}

class BigGradientView : public SampleView {
public:
<<<<<<< HEAD
    BigGradientView() { }

protected:
    bool onQuery(SkEvent* evt) override
    {
=======
    BigGradientView() {}

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "BigGradient");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
        SkRect r;
        r.set(0, 0, this->width(), this->height());
        SkPaint p;
        p.setShader(make_grad(this->width(), this->height()));
=======
    virtual void onDrawContent(SkCanvas* canvas) {
        SkRect r;
        r.set(0, 0, this->width(), this->height());
        SkPaint p;
        p.setShader(make_grad(this->width(), this->height()))->unref();
>>>>>>> miniblink49
        canvas->drawRect(r, p);
    }

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new BigGradientView; }
static SkViewRegister reg(MyFactory);
