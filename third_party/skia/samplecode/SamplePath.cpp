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
#include "SkAnimTimer.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkParsePath.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkView.h"
#include "SkXfermode.h"

#include "SkGeometry.h"

#include <stdlib.h>

// http://code.google.com/p/skia/issues/detail?id=32
static void test_cubic()
{
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkImageDecoder.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
#include "SkXfermode.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkParsePath.h"
#include "SkTime.h"
#include "SkTypeface.h"

#include "SkGeometry.h"

// http://code.google.com/p/skia/issues/detail?id=32
static void test_cubic() {
>>>>>>> miniblink49
    SkPoint src[4] = {
        { 556.25000f, 523.03003f },
        { 556.23999f, 522.96002f },
        { 556.21997f, 522.89001f },
        { 556.21997f, 522.82001f }
    };
    SkPoint dst[11];
<<<<<<< HEAD
    dst[10].set(42, -42); // one past the end, that we don't clobber these
=======
    dst[10].set(42, -42);   // one past the end, that we don't clobber these
>>>>>>> miniblink49
    SkScalar tval[] = { 0.33333334f, 0.99999994f };

    SkChopCubicAt(src, dst, tval, 2);

#if 0
    for (int i = 0; i < 11; i++) {
        SkDebugf("--- %d [%g %g]\n", i, dst[i].fX, dst[i].fY);
    }
#endif
}

<<<<<<< HEAD
static void test_cubic2()
{
=======
static void test_cubic2() {
>>>>>>> miniblink49
    const char* str = "M2242 -590088L-377758 9.94099e+07L-377758 9.94099e+07L2242 -590088Z";
    SkPath path;
    SkParsePath::FromSVGString(str, &path);

    {
<<<<<<< HEAD
=======
#ifdef SK_BUILD_FOR_WIN
        // windows doesn't have strtof
        float x = (float)strtod("9.94099e+07", NULL);
#else
        float x = strtof("9.94099e+07", NULL);
#endif
        int ix = (int)x;
        int fx = (int)(x * 65536);
        int ffx = SkScalarToFixed(x);
        SkDebugf("%g %x %x %x\n", x, ix, fx, ffx);

>>>>>>> miniblink49
        SkRect r = path.getBounds();
        SkIRect ir;
        r.round(&ir);
        SkDebugf("[%g %g %g %g] [%x %x %x %x]\n",
<<<<<<< HEAD
            SkScalarToDouble(r.fLeft), SkScalarToDouble(r.fTop),
            SkScalarToDouble(r.fRight), SkScalarToDouble(r.fBottom),
            ir.fLeft, ir.fTop, ir.fRight, ir.fBottom);
=======
                SkScalarToDouble(r.fLeft), SkScalarToDouble(r.fTop),
                SkScalarToDouble(r.fRight), SkScalarToDouble(r.fBottom),
                ir.fLeft, ir.fTop, ir.fRight, ir.fBottom);
>>>>>>> miniblink49
    }

    SkBitmap bitmap;
    bitmap.allocN32Pixels(300, 200);

    SkCanvas canvas(bitmap);
    SkPaint paint;
    paint.setAntiAlias(true);
    canvas.drawPath(path, paint);
}

class PathView : public SampleView {
    SkScalar fPrevSecs;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
public:
    SkScalar fDStroke, fStroke, fMinStroke, fMaxStroke;
    SkPath fPath[6];
    bool fShowHairline;
    bool fOnce;

<<<<<<< HEAD
    PathView()
    {
=======
    PathView() {
>>>>>>> miniblink49
        fPrevSecs = 0;
        fOnce = false;
    }

<<<<<<< HEAD
    void init()
    {
=======
    void init() {
>>>>>>> miniblink49
        if (fOnce) {
            return;
        }
        fOnce = true;

        test_cubic();
        test_cubic2();

        fShowHairline = false;

        fDStroke = 1;
        fStroke = 10;
        fMinStroke = 10;
        fMaxStroke = 180;

        const SkScalar V = 85;

        fPath[0].moveTo(40, 70);
        fPath[0].lineTo(70, 70 + SK_ScalarHalf);
        fPath[0].lineTo(110, 70);

        fPath[1].moveTo(40, 70);
        fPath[1].lineTo(70, 70 - SK_ScalarHalf);
        fPath[1].lineTo(110, 70);

        fPath[2].moveTo(V, V);
        fPath[2].lineTo(50, V);
        fPath[2].lineTo(50, 50);

        fPath[3].moveTo(50, 50);
        fPath[3].lineTo(50, V);
        fPath[3].lineTo(V, V);

        fPath[4].moveTo(50, 50);
        fPath[4].lineTo(50, V);
        fPath[4].lineTo(52, 50);

        fPath[5].moveTo(52, 50);
        fPath[5].lineTo(50, V);
        fPath[5].lineTo(50, 50);

        this->setBGColor(0xFFDDDDDD);
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    bool onQuery(SkEvent* evt) override
    {
=======
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Paths");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void drawPath(SkCanvas* canvas, const SkPath& path, SkPaint::Join j)
    {
=======
    void drawPath(SkCanvas* canvas, const SkPath& path, SkPaint::Join j) {
>>>>>>> miniblink49
        SkPaint paint;

        paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);
        paint.setStrokeJoin(j);
        paint.setStrokeWidth(fStroke);

        if (fShowHairline) {
<<<<<<< HEAD
            SkPath fill;
=======
            SkPath  fill;
>>>>>>> miniblink49

            paint.getFillPath(path, &fill);
            paint.setStrokeWidth(0);
            canvas->drawPath(fill, paint);
        } else {
            canvas->drawPath(path, paint);
        }

        paint.setColor(SK_ColorRED);
        paint.setStrokeWidth(0);
        canvas->drawPath(path, paint);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
=======
    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        this->init();
        canvas->translate(50, 50);

        static const SkPaint::Join gJoins[] = {
            SkPaint::kBevel_Join,
            SkPaint::kMiter_Join,
            SkPaint::kRound_Join
        };

        for (size_t i = 0; i < SK_ARRAY_COUNT(gJoins); i++) {
            canvas->save();
            for (size_t j = 0; j < SK_ARRAY_COUNT(fPath); j++) {
                this->drawPath(canvas, fPath[j], gJoins[i]);
                canvas->translate(200, 0);
            }
            canvas->restore();

            canvas->translate(0, 200);
        }
    }
<<<<<<< HEAD

    bool onAnimate(const SkAnimTimer& timer) override
    {
=======
    
    bool onAnimate(const SkAnimTimer& timer) override {
>>>>>>> miniblink49
        SkScalar currSecs = timer.scaled(100);
        SkScalar delta = currSecs - fPrevSecs;
        fPrevSecs = currSecs;

        fStroke += fDStroke * delta;
        if (fStroke > fMaxStroke || fStroke < fMinStroke) {
            fDStroke = -fDStroke;
        }
        return true;
    }

<<<<<<< HEAD
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override
    {
        fShowHairline = !fShowHairline;
        this->inval(nullptr);
=======
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override {
        fShowHairline = !fShowHairline;
        this->inval(NULL);
>>>>>>> miniblink49
        return this->INHERITED::onFindClickHandler(x, y, modi);
    }

private:
    typedef SampleView INHERITED;
};
<<<<<<< HEAD
DEF_SAMPLE(return new PathView;)
=======
DEF_SAMPLE( return new PathView; )
>>>>>>> miniblink49

//////////////////////////////////////////////////////////////////////////////

#include "SkArcToPathEffect.h"
#include "SkCornerPathEffect.h"
#include "SkRandom.h"

class ArcToView : public SampleView {
    bool fDoFrame, fDoArcTo, fDoCorner, fDoConic;
    SkPaint fPtsPaint, fArcToPaint, fSkeletonPaint, fCornerPaint;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
public:
    enum {
        N = 4
    };
    SkPoint fPts[N];

    ArcToView()
<<<<<<< HEAD
        : fDoFrame(false)
        , fDoArcTo(false)
        , fDoCorner(false)
        , fDoConic(false)
=======
        : fDoFrame(false), fDoArcTo(false), fDoCorner(false), fDoConic(false)
>>>>>>> miniblink49
    {
        SkRandom rand;
        for (int i = 0; i < N; ++i) {
            fPts[i].fX = 20 + rand.nextUScalar1() * 640;
            fPts[i].fY = 20 + rand.nextUScalar1() * 480;
        }
<<<<<<< HEAD

=======
        
>>>>>>> miniblink49
        const SkScalar rad = 50;

        fPtsPaint.setAntiAlias(true);
        fPtsPaint.setStrokeWidth(15);
        fPtsPaint.setStrokeCap(SkPaint::kRound_Cap);

        fArcToPaint.setAntiAlias(true);
        fArcToPaint.setStyle(SkPaint::kStroke_Style);
        fArcToPaint.setStrokeWidth(9);
        fArcToPaint.setColor(0x800000FF);
<<<<<<< HEAD
        fArcToPaint.setPathEffect(SkArcToPathEffect::Make(rad));
=======
        fArcToPaint.setPathEffect(SkArcToPathEffect::Create(rad))->unref();
>>>>>>> miniblink49

        fCornerPaint.setAntiAlias(true);
        fCornerPaint.setStyle(SkPaint::kStroke_Style);
        fCornerPaint.setStrokeWidth(13);
        fCornerPaint.setColor(SK_ColorGREEN);
<<<<<<< HEAD
        fCornerPaint.setPathEffect(SkCornerPathEffect::Make(rad * 2));
=======
        fCornerPaint.setPathEffect(SkCornerPathEffect::Create(rad*2))->unref();
>>>>>>> miniblink49

        fSkeletonPaint.setAntiAlias(true);
        fSkeletonPaint.setStyle(SkPaint::kStroke_Style);
        fSkeletonPaint.setColor(SK_ColorRED);
    }

<<<<<<< HEAD
    void toggle(bool& value)
    {
        value = !value;
        this->inval(nullptr);
=======
    void toggle(bool& value) {
        value = !value;
        this->inval(NULL);
>>>>>>> miniblink49
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
            SampleCode::TitleR(evt, "ArcTo");
            return true;
        }
        SkUnichar uni;
        if (SampleCode::CharQ(*evt, &uni)) {
            switch (uni) {
<<<<<<< HEAD
            case '1':
                this->toggle(fDoFrame);
                return true;
            case '2':
                this->toggle(fDoArcTo);
                return true;
            case '3':
                this->toggle(fDoCorner);
                return true;
            case '4':
                this->toggle(fDoConic);
                return true;
            default:
                break;
=======
                case '1': this->toggle(fDoFrame); return true;
                case '2': this->toggle(fDoArcTo); return true;
                case '3': this->toggle(fDoCorner); return true;
                case '4': this->toggle(fDoConic); return true;
                default: break;
>>>>>>> miniblink49
            }
        }
        return this->INHERITED::onQuery(evt);
    }
<<<<<<< HEAD

    void makePath(SkPath* path)
    {
=======
    
    void makePath(SkPath* path) {
>>>>>>> miniblink49
        path->moveTo(fPts[0]);
        for (int i = 1; i < N; ++i) {
            path->lineTo(fPts[i]);
        }
        if (!fDoFrame) {
            path->close();
        }
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
=======
    void onDrawContent(SkCanvas* canvas) override {
>>>>>>> miniblink49
        canvas->drawPoints(SkCanvas::kPoints_PointMode, N, fPts, fPtsPaint);

        SkPath path;
        this->makePath(&path);

        if (fDoCorner) {
            canvas->drawPath(path, fCornerPaint);
        }
        if (fDoArcTo) {
            canvas->drawPath(path, fArcToPaint);
        }

        canvas->drawPath(path, fSkeletonPaint);
    }

<<<<<<< HEAD
    bool onClick(Click* click) override
    {
=======
    bool onClick(Click* click) override {
>>>>>>> miniblink49
        int32_t index;
        if (click->fMeta.findS32("index", &index)) {
            SkASSERT((unsigned)index < N);
            fPts[index] = click->fCurr;
<<<<<<< HEAD
            this->inval(nullptr);
=======
            this->inval(NULL);
>>>>>>> miniblink49
            return true;
        }
        return false;
    }

<<<<<<< HEAD
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override
    {
=======
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override {
>>>>>>> miniblink49
        const SkScalar tol = 4;
        const SkRect r = SkRect::MakeXYWH(x - tol, y - tol, tol * 2, tol * 2);
        for (int i = 0; i < N; ++i) {
            if (r.intersects(SkRect::MakeXYWH(fPts[i].fX, fPts[i].fY, 1, 1))) {
                Click* click = new Click(this);
                click->fMeta.setS32("index", i);
                return click;
            }
        }
        return this->INHERITED::onFindClickHandler(x, y, modi);
    }

private:
    typedef SampleView INHERITED;
};
<<<<<<< HEAD
DEF_SAMPLE(return new ArcToView;)
=======
DEF_SAMPLE( return new ArcToView; )

>>>>>>> miniblink49
