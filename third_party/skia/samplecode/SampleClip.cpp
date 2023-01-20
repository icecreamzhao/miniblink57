/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SampleCode.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkColorPriv.h"
#include "SkPaint.h"
#include "SkPath.h"
#include "SkRandom.h"
#include "SkView.h"

#define W 150
#define H 200

static void show_text(SkCanvas* canvas, bool doAA)
{
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkColorPriv.h"
#include "SkDevice.h"
#include "SkPaint.h"
#include "SkRandom.h"

#define W   150
#define H   200

static void show_text(SkCanvas* canvas, bool doAA) {
>>>>>>> miniblink49
    SkRandom rand;
    SkPaint paint;
    paint.setAntiAlias(doAA);
    paint.setLCDRenderText(true);
    paint.setTextSize(SkIntToScalar(20));

    for (int i = 0; i < 200; ++i) {
        paint.setColor((SK_A32_MASK << SK_A32_SHIFT) | rand.nextU());
        canvas->drawText("Hamburgefons", 12,
<<<<<<< HEAD
            rand.nextSScalar1() * W, rand.nextSScalar1() * H + 20,
            paint);
    }
}

static void show_fill(SkCanvas* canvas, bool doAA)
{
=======
                         rand.nextSScalar1() * W, rand.nextSScalar1() * H + 20,
                         paint);
    }
}

static void show_fill(SkCanvas* canvas, bool doAA) {
>>>>>>> miniblink49
    SkRandom rand;
    SkPaint paint;
    paint.setAntiAlias(doAA);

    for (int i = 0; i < 50; ++i) {
        SkRect r;
        SkPath p;

        r.setXYWH(rand.nextSScalar1() * W, rand.nextSScalar1() * H,
<<<<<<< HEAD
            rand.nextUScalar1() * W, rand.nextUScalar1() * H);
=======
                  rand.nextUScalar1() * W, rand.nextUScalar1() * H);
>>>>>>> miniblink49
        paint.setColor(rand.nextU());
        canvas->drawRect(r, paint);

        r.setXYWH(rand.nextSScalar1() * W, rand.nextSScalar1() * H,
<<<<<<< HEAD
            rand.nextUScalar1() * W, rand.nextUScalar1() * H);
=======
                  rand.nextUScalar1() * W, rand.nextUScalar1() * H);
>>>>>>> miniblink49
        paint.setColor(rand.nextU());
        p.addOval(r);
        canvas->drawPath(p, paint);
    }
}

<<<<<<< HEAD
static SkScalar randRange(SkRandom& rand, SkScalar min, SkScalar max)
{
=======
static SkScalar randRange(SkRandom& rand, SkScalar min, SkScalar max) {
>>>>>>> miniblink49
    SkASSERT(min <= max);
    return min + SkScalarMul(rand.nextUScalar1(), max - min);
}

<<<<<<< HEAD
static void show_stroke(SkCanvas* canvas, bool doAA, SkScalar strokeWidth, int n)
{
=======
static void show_stroke(SkCanvas* canvas, bool doAA, SkScalar strokeWidth, int n) {
>>>>>>> miniblink49
    SkRandom rand;
    SkPaint paint;
    paint.setAntiAlias(doAA);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(strokeWidth);

    for (int i = 0; i < n; ++i) {
        SkRect r;
        SkPath p;

        r.setXYWH(rand.nextSScalar1() * W, rand.nextSScalar1() * H,
<<<<<<< HEAD
            rand.nextUScalar1() * W, rand.nextUScalar1() * H);
=======
                  rand.nextUScalar1() * W, rand.nextUScalar1() * H);
>>>>>>> miniblink49
        paint.setColor(rand.nextU());
        canvas->drawRect(r, paint);

        r.setXYWH(rand.nextSScalar1() * W, rand.nextSScalar1() * H,
<<<<<<< HEAD
            rand.nextUScalar1() * W, rand.nextUScalar1() * H);
=======
                  rand.nextUScalar1() * W, rand.nextUScalar1() * H);
>>>>>>> miniblink49
        paint.setColor(rand.nextU());
        p.addOval(r);
        canvas->drawPath(p, paint);

<<<<<<< HEAD
        const SkScalar minx = -SkIntToScalar(W) / 4;
        const SkScalar maxx = 5 * SkIntToScalar(W) / 4;
        const SkScalar miny = -SkIntToScalar(H) / 4;
        const SkScalar maxy = 5 * SkIntToScalar(H) / 4;
        paint.setColor(rand.nextU());
        canvas->drawLine(randRange(rand, minx, maxx), randRange(rand, miny, maxy),
            randRange(rand, minx, maxx), randRange(rand, miny, maxy),
            paint);
    }
}

static void show_hair(SkCanvas* canvas, bool doAA)
{
    show_stroke(canvas, doAA, 0, 150);
}

static void show_thick(SkCanvas* canvas, bool doAA)
{
=======
        const SkScalar minx = -SkIntToScalar(W)/4;
        const SkScalar maxx = 5*SkIntToScalar(W)/4;
        const SkScalar miny = -SkIntToScalar(H)/4;
        const SkScalar maxy = 5*SkIntToScalar(H)/4;
        paint.setColor(rand.nextU());
        canvas->drawLine(randRange(rand, minx, maxx), randRange(rand, miny, maxy),
                         randRange(rand, minx, maxx), randRange(rand, miny, maxy),
                         paint);
    }
}

static void show_hair(SkCanvas* canvas, bool doAA) {
    show_stroke(canvas, doAA, 0, 150);
}

static void show_thick(SkCanvas* canvas, bool doAA) {
>>>>>>> miniblink49
    show_stroke(canvas, doAA, SkIntToScalar(5), 50);
}

typedef void (*CanvasProc)(SkCanvas*, bool);

#include "SkAAClip.h"

class ClipView : public SampleView {
public:
<<<<<<< HEAD
    ClipView()
    {
=======
    ClipView() {
>>>>>>> miniblink49
        SkAAClip clip;
        SkIRect r = { -2, -3, 842, 18 };
        clip.setRect(r);
    }

<<<<<<< HEAD
    virtual ~ClipView()
    {
=======
    virtual ~ClipView() {
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
            SampleCode::TitleR(evt, "Clip");
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
        canvas->drawColor(SK_ColorWHITE);
        canvas->translate(SkIntToScalar(20), SkIntToScalar(20));

        static const CanvasProc gProc[] = {
            show_text, show_thick, show_hair, show_fill
        };

        SkRect r = { 0, 0, SkIntToScalar(W), SkIntToScalar(H) };
        SkPath clipPath;
        r.inset(SK_Scalar1 / 4, SK_Scalar1 / 4);
        clipPath.addRoundRect(r, SkIntToScalar(20), SkIntToScalar(20));

<<<<<<< HEAD
        //        clipPath.toggleInverseFillType();
=======
//        clipPath.toggleInverseFillType();
>>>>>>> miniblink49

        for (int aa = 0; aa <= 1; ++aa) {
            canvas->save();
            for (size_t i = 0; i < SK_ARRAY_COUNT(gProc); ++i) {
                canvas->save();
                canvas->clipPath(clipPath, SkRegion::kIntersect_Op, SkToBool(aa));
<<<<<<< HEAD
                //                canvas->drawColor(SK_ColorWHITE);
=======
//                canvas->drawColor(SK_ColorWHITE);
>>>>>>> miniblink49
                gProc[i](canvas, SkToBool(aa));
                canvas->restore();
                canvas->translate(W * SK_Scalar1 * 8 / 7, 0);
            }
            canvas->restore();
            canvas->translate(0, H * SK_Scalar1 * 8 / 7);
        }
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new ClipView; }
static SkViewRegister reg(MyFactory);
