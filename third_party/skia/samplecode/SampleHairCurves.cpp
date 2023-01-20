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
#include "SkPath.h"
#include "SkRandom.h"
#include "SkView.h"

class HairCurvesView : public SampleView {
public:
    HairCurvesView()
    {
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkPath.h"
#include "SkRandom.h"

class HairCurvesView : public SampleView {
public:
    HairCurvesView() {
>>>>>>> miniblink49
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
            SampleCode::TitleR(evt, "HairCurves");
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
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setStrokeWidth(0);
        canvas->save();
        canvas->scale(1000 * SK_Scalar1, 1000 * SK_Scalar1);
        SkRandom rand;
        SkRandom randW;
        SkPath curves;
        SkPath hulls;
        SkPath ctrlPts;
        for (int i = 0; i < 100; ++i) {
            SkScalar pts[] = {
                rand.nextUScalar1(), rand.nextUScalar1(),
                rand.nextUScalar1(), rand.nextUScalar1(),
                rand.nextUScalar1(), rand.nextUScalar1(),
                rand.nextUScalar1(), rand.nextUScalar1()
            };
            curves.moveTo(pts[0], pts[1]);
            curves.cubicTo(pts[2], pts[3],
<<<<<<< HEAD
                pts[4], pts[5],
                pts[6], pts[7]);
=======
                         pts[4], pts[5],
                         pts[6], pts[7]);
>>>>>>> miniblink49

            hulls.moveTo(pts[0], pts[1]);
            hulls.lineTo(pts[2], pts[3]);
            hulls.lineTo(pts[4], pts[5]);
            hulls.lineTo(pts[6], pts[7]);

            ctrlPts.addCircle(pts[0], pts[1], SK_Scalar1 / 200);
            ctrlPts.addCircle(pts[2], pts[3], SK_Scalar1 / 200);
            ctrlPts.addCircle(pts[4], pts[5], SK_Scalar1 / 200);
            ctrlPts.addCircle(pts[6], pts[7], SK_Scalar1 / 200);
        }
        for (int i = 0; i < 100; ++i) {
            SkScalar pts[] = {
<<<<<<< HEAD
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
            };
            curves.moveTo(pts[0], pts[1]);
            curves.quadTo(pts[2], pts[3],
                pts[4], pts[5]);
=======
                rand.nextUScalar1(), rand.nextUScalar1(),
                rand.nextUScalar1(), rand.nextUScalar1(),
                rand.nextUScalar1(), rand.nextUScalar1(),
            };
            curves.moveTo(pts[0], pts[1]);
            curves.quadTo(pts[2], pts[3],
                          pts[4], pts[5]);
>>>>>>> miniblink49

            hulls.moveTo(pts[0], pts[1]);
            hulls.lineTo(pts[2], pts[3]);
            hulls.lineTo(pts[4], pts[5]);

            ctrlPts.addCircle(pts[0], pts[1], SK_Scalar1 / 200);
            ctrlPts.addCircle(pts[2], pts[3], SK_Scalar1 / 200);
            ctrlPts.addCircle(pts[4], pts[5], SK_Scalar1 / 200);
        }
        for (int i = 0; i < 100; ++i) {
            SkScalar pts[] = {
<<<<<<< HEAD
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
=======
                rand.nextUScalar1(), rand.nextUScalar1(),
                rand.nextUScalar1(), rand.nextUScalar1(),
                rand.nextUScalar1(), rand.nextUScalar1(),
>>>>>>> miniblink49
            };
            SkScalar weight = randW.nextUScalar1() * 2.0f;

            curves.moveTo(pts[0], pts[1]);
            curves.conicTo(pts[2], pts[3],
<<<<<<< HEAD
                pts[4], pts[5],
                weight);
=======
                          pts[4], pts[5],
                          weight);
>>>>>>> miniblink49

            hulls.moveTo(pts[0], pts[1]);
            hulls.lineTo(pts[2], pts[3]);
            hulls.lineTo(pts[4], pts[5]);

            ctrlPts.addCircle(pts[0], pts[1], SK_Scalar1 / 200);
            ctrlPts.addCircle(pts[2], pts[3], SK_Scalar1 / 200);
            ctrlPts.addCircle(pts[4], pts[5], SK_Scalar1 / 200);
        }
        for (int i = 0; i < 100; ++i) {
            SkScalar pts[] = {
<<<<<<< HEAD
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
                rand.nextUScalar1(),
=======
                rand.nextUScalar1(), rand.nextUScalar1(),
                rand.nextUScalar1(), rand.nextUScalar1(),
>>>>>>> miniblink49
            };
            curves.moveTo(pts[0], pts[1]);
            curves.lineTo(pts[2], pts[3]);

            ctrlPts.addCircle(pts[0], pts[1], SK_Scalar1 / 200);
            ctrlPts.addCircle(pts[2], pts[3], SK_Scalar1 / 200);
        }

        paint.setColor(SK_ColorBLACK);
        canvas->drawPath(curves, paint);
        paint.setColor(SK_ColorRED);
        //canvas->drawPath(hulls, paint);
        paint.setStyle(SkPaint::kFill_Style);
        paint.setColor(SK_ColorBLUE);
        //canvas->drawPath(ctrlPts, paint);

        canvas->restore();
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new HairCurvesView; }
static SkViewRegister reg(MyFactory);
