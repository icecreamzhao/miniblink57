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
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkRandom.h"
#include "SkView.h"

typedef SkScalar (*MakePathProc)(SkPath*);

static SkScalar make_frame(SkPath* path)
{
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGraphics.h"
#include "SkRandom.h"
#include "SkBlurDrawLooper.h"
#include "SkGradientShader.h"

typedef SkScalar (*MakePathProc)(SkPath*);

static SkScalar make_frame(SkPath* path) {
>>>>>>> miniblink49
    SkRect r = { 10, 10, 630, 470 };
    path->addRoundRect(r, 15, 15);

    SkPaint paint;
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(5);
    paint.getFillPath(*path, path);
    return 15;
}

<<<<<<< HEAD
static SkScalar make_triangle(SkPath* path)
{
=======
static SkScalar make_triangle(SkPath* path) {
>>>>>>> miniblink49
    static const int gCoord[] = {
        10, 20, 15, 5, 30, 30
    };
    path->moveTo(SkIntToScalar(gCoord[0]), SkIntToScalar(gCoord[1]));
    path->lineTo(SkIntToScalar(gCoord[2]), SkIntToScalar(gCoord[3]));
    path->lineTo(SkIntToScalar(gCoord[4]), SkIntToScalar(gCoord[5]));
    path->close();
    path->offset(10, 0);
    return SkIntToScalar(30);
}

<<<<<<< HEAD
static SkScalar make_rect(SkPath* path)
{
=======
static SkScalar make_rect(SkPath* path) {
>>>>>>> miniblink49
    SkRect r = { 10, 10, 30, 30 };
    path->addRect(r);
    path->offset(10, 0);
    return SkIntToScalar(30);
}

<<<<<<< HEAD
static SkScalar make_oval(SkPath* path)
{
=======
static SkScalar make_oval(SkPath* path) {
>>>>>>> miniblink49
    SkRect r = { 10, 10, 30, 30 };
    path->addOval(r);
    path->offset(10, 0);
    return SkIntToScalar(30);
}

<<<<<<< HEAD
static SkScalar make_sawtooth(SkPath* path)
{
=======
static SkScalar make_sawtooth(SkPath* path) {
>>>>>>> miniblink49
    SkScalar x = SkIntToScalar(20);
    SkScalar y = SkIntToScalar(20);
    const SkScalar x0 = x;
    const SkScalar dx = SK_Scalar1 * 5;
    const SkScalar dy = SK_Scalar1 * 10;

    path->moveTo(x, y);
    for (int i = 0; i < 32; i++) {
        x += dx;
        path->lineTo(x, y - dy);
        x += dx;
        path->lineTo(x, y + dy);
    }
    path->lineTo(x, y + 2 * dy);
    path->lineTo(x0, y + 2 * dy);
    path->close();
    return SkIntToScalar(30);
}

<<<<<<< HEAD
static SkScalar make_star(SkPath* path, int n)
{
=======
static SkScalar make_star(SkPath* path, int n) {
>>>>>>> miniblink49
    const SkScalar c = SkIntToScalar(45);
    const SkScalar r = SkIntToScalar(20);

    SkScalar rad = -SK_ScalarPI / 2;
    const SkScalar drad = (n >> 1) * SK_ScalarPI * 2 / n;

    path->moveTo(c, c - r);
    for (int i = 1; i < n; i++) {
        rad += drad;
        SkScalar cosV, sinV = SkScalarSinCos(rad, &cosV);
        path->lineTo(c + SkScalarMul(cosV, r), c + SkScalarMul(sinV, r));
    }
    path->close();
    return r * 2 * 6 / 5;
}

static SkScalar make_star_5(SkPath* path) { return make_star(path, 5); }
static SkScalar make_star_13(SkPath* path) { return make_star(path, 13); }

static const MakePathProc gProcs[] = {
    make_frame,
    make_triangle,
    make_rect,
    make_oval,
    make_sawtooth,
    make_star_5,
    make_star_13
};

<<<<<<< HEAD
#define N SK_ARRAY_COUNT(gProcs)

class PathFillView : public SampleView {
    SkPath fPath[N];
    SkScalar fDY[N];

public:
    PathFillView()
    {
=======
#define N   SK_ARRAY_COUNT(gProcs)

class PathFillView : public SampleView {
    SkPath  fPath[N];
    SkScalar fDY[N];

public:
    PathFillView() {
>>>>>>> miniblink49
        for (size_t i = 0; i < N; i++) {
            fDY[i] = gProcs[i](&fPath[i]);
        }
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
            SampleCode::TitleR(evt, "PathFill");
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

        for (size_t i = 0; i < N; i++) {
            canvas->drawPath(fPath[i], paint);
            canvas->translate(0, fDY[i]);
        }
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new PathFillView; }
static SkViewRegister reg(MyFactory);
