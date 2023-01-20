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
#include "SkPaint.h"
#include "SkPath.h"
#include "SkView.h"
=======
#include "SampleCode.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkPaint.h"
>>>>>>> miniblink49

// ensure that we don't accidentally screw up the bounds when the oval is
// fractional, and the impl computes the center and radii, and uses them to
// reconstruct the edges of the circle.
// see bug# 1504910
<<<<<<< HEAD
static void test_circlebounds(SkCanvas*)
{
=======
static void test_circlebounds(SkCanvas*) {
>>>>>>> miniblink49
    SkRect r = { 1.39999998f, 1, 21.3999996f, 21 };
    SkPath p;
    p.addOval(r);
    SkASSERT(r == p.getBounds());
}

class CircleView : public SampleView {
public:
    static const SkScalar ANIM_DX;
    static const SkScalar ANIM_DY;
    static const SkScalar ANIM_RAD;
    SkScalar fDX, fDY, fRAD;

<<<<<<< HEAD
    CircleView()
    {
=======
    CircleView() {
>>>>>>> miniblink49
        fDX = fDY = fRAD = 0;
        fN = 3;
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
            SampleCode::TitleR(evt, "Circles");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void circle(SkCanvas* canvas, int width, bool aa)
    {
=======
    void circle(SkCanvas* canvas, int width, bool aa) {
>>>>>>> miniblink49
        SkPaint paint;

        paint.setAntiAlias(aa);
        if (width < 0) {
            paint.setStyle(SkPaint::kFill_Style);
        } else {
            paint.setStyle(SkPaint::kStroke_Style);
            paint.setStrokeWidth(SkIntToScalar(width));
        }
        canvas->drawCircle(0, 0, SkIntToScalar(9) + fRAD, paint);
        if (false) { // avoid bit rot, suppress warning
            test_circlebounds(canvas);
        }
    }

<<<<<<< HEAD
    void drawSix(SkCanvas* canvas, SkScalar dx, SkScalar dy)
    {
=======
    void drawSix(SkCanvas* canvas, SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
        for (int width = -1; width <= 1; width++) {
            canvas->save();
            circle(canvas, width, false);
            canvas->translate(0, dy);
            circle(canvas, width, true);
            canvas->restore();
            canvas->translate(dx, 0);
        }
    }

<<<<<<< HEAD
    static void make_poly(SkPath* path, int n)
    {
=======
    static void make_poly(SkPath* path, int n) {
>>>>>>> miniblink49
        if (n <= 0) {
            return;
        }
        path->incReserve(n + 1);
        path->moveTo(SK_Scalar1, 0);
        SkScalar step = SK_ScalarPI * 2 / n;
        SkScalar angle = 0;
        for (int i = 1; i < n; i++) {
            angle += step;
            SkScalar c, s = SkScalarSinCos(angle, &c);
            path->lineTo(c, s);
        }
        path->close();
    }

<<<<<<< HEAD
    static void rotate(SkCanvas* canvas, SkScalar angle, SkScalar px, SkScalar py)
    {
=======
    static void rotate(SkCanvas* canvas, SkScalar angle, SkScalar px, SkScalar py) {
>>>>>>> miniblink49
        canvas->translate(-px, -py);
        canvas->rotate(angle);
        canvas->translate(px, py);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);
        //        canvas->drawCircle(250, 250, 220, paint);
=======
    virtual void onDrawContent(SkCanvas* canvas) {
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);
//        canvas->drawCircle(250, 250, 220, paint);
>>>>>>> miniblink49
        SkMatrix matrix;
        matrix.setScale(SkIntToScalar(100), SkIntToScalar(100));
        matrix.postTranslate(SkIntToScalar(200), SkIntToScalar(200));
        canvas->concat(matrix);
        for (int n = 3; n < 20; n++) {
            SkPath path;
            make_poly(&path, n);
            SkAutoCanvasRestore acr(canvas, true);
            canvas->rotate(SkIntToScalar(10) * (n - 3));
            canvas->translate(-SK_Scalar1, 0);
            canvas->drawPath(path, paint);
        }
    }

private:
    int fN;
    typedef SampleView INHERITED;
};

const SkScalar CircleView::ANIM_DX(SK_Scalar1 / 67);
const SkScalar CircleView::ANIM_DY(SK_Scalar1 / 29);
const SkScalar CircleView::ANIM_RAD(SK_Scalar1 / 19);

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new CircleView; }
static SkViewRegister reg(MyFactory);
