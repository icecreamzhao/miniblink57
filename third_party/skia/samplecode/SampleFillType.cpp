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
#include "SkCornerPathEffect.h"
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkCornerPathEffect.h"
#include "SkCullPoints.h"
>>>>>>> miniblink49
#include "SkGradientShader.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
<<<<<<< HEAD
#include "SkView.h"

class FillTypeView : public SampleView {
    SkPath fPath;

public:
    FillTypeView()
    {
=======

class FillTypeView : public SampleView {
    SkPath fPath;
public:
    FillTypeView() {
>>>>>>> miniblink49
        const SkScalar radius = SkIntToScalar(45);
        fPath.addCircle(SkIntToScalar(50), SkIntToScalar(50), radius);
        fPath.addCircle(SkIntToScalar(100), SkIntToScalar(100), radius);

        this->setBGColor(0xFFDDDDDD);
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    virtual bool onQuery(SkEvent* evt)
    {
=======
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "FillType");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    void showPath(SkCanvas* canvas, int x, int y, SkPath::FillType ft,
<<<<<<< HEAD
        SkScalar scale, const SkPaint& paint)
    {
=======
                  SkScalar scale, const SkPaint& paint) {
>>>>>>> miniblink49

        const SkRect r = { 0, 0, SkIntToScalar(150), SkIntToScalar(150) };

        canvas->save();
        canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
        canvas->clipRect(r);
        canvas->drawColor(SK_ColorWHITE);
        fPath.setFillType(ft);
        canvas->translate(r.centerX(), r.centerY());
        canvas->scale(scale, scale);
        canvas->translate(-r.centerX(), -r.centerY());
        canvas->drawPath(fPath, paint);
        canvas->restore();
    }

<<<<<<< HEAD
    void showFour(SkCanvas* canvas, SkScalar scale, const SkPaint& paint)
    {
        showPath(canvas, 0, 0, SkPath::kWinding_FillType,
            scale, paint);
        showPath(canvas, 200, 0, SkPath::kEvenOdd_FillType,
            scale, paint);
        showPath(canvas, 00, 200, SkPath::kInverseWinding_FillType,
            scale, paint);
        showPath(canvas, 200, 200, SkPath::kInverseEvenOdd_FillType,
            scale, paint);
    }

    virtual void onDrawContent(SkCanvas* canvas)
    {
        canvas->translate(SkIntToScalar(20), SkIntToScalar(20));

        SkPaint paint;
        const SkScalar scale = SkIntToScalar(5) / 4;
=======
    void showFour(SkCanvas* canvas, SkScalar scale, const SkPaint& paint) {
        showPath(canvas,   0,   0, SkPath::kWinding_FillType,
                 scale, paint);
        showPath(canvas, 200,   0, SkPath::kEvenOdd_FillType,
                 scale, paint);
        showPath(canvas,  00, 200, SkPath::kInverseWinding_FillType,
                 scale, paint);
        showPath(canvas, 200, 200, SkPath::kInverseEvenOdd_FillType,
                 scale, paint);
    }

    virtual void onDrawContent(SkCanvas* canvas) {
        canvas->translate(SkIntToScalar(20), SkIntToScalar(20));

        SkPaint paint;
        const SkScalar scale = SkIntToScalar(5)/4;
>>>>>>> miniblink49

        paint.setAntiAlias(false);
        paint.setColor(0x8000FF00);

        showFour(canvas, SK_Scalar1, paint);
        canvas->translate(SkIntToScalar(450), 0);
        showFour(canvas, scale, paint);

        paint.setAntiAlias(true);

        canvas->translate(SkIntToScalar(-450), SkIntToScalar(450));
        showFour(canvas, SK_Scalar1, paint);
        canvas->translate(SkIntToScalar(450), 0);
        showFour(canvas, scale, paint);
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new FillTypeView; }
static SkViewRegister reg(MyFactory);
