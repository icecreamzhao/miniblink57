/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SampleCode.h"
<<<<<<< HEAD
#include "Sk1DPathEffect.h"
#include "SkAnimTimer.h"
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkCornerPathEffect.h"
#include "SkDrawable.h"
#include "SkGradientShader.h"
#include "SkLayerRasterizer.h"
#include "SkPath.h"
#include "SkPathMeasure.h"
#include "SkPictureRecorder.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
#include "SkView.h"

#include "SkParsePath.h"
static void testparse()
{
=======
#include "SkAnimTimer.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkDrawable.h"
#include "SkGradientShader.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
#include "SkComposeShader.h"
#include "Sk1DPathEffect.h"
#include "SkCornerPathEffect.h"
#include "SkPathMeasure.h"
#include "SkPictureRecorder.h"
#include "SkRandom.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkLayerRasterizer.h"

#include "SkParsePath.h"
static void testparse() {
>>>>>>> miniblink49
    SkRect r;
    r.set(0, 0, 10, 10.5f);
    SkPath p, p2;
    SkString str, str2;

    p.addRect(r);
    SkParsePath::ToSVGString(p, &str);
    SkParsePath::FromSVGString(str.c_str(), &p2);
    SkParsePath::ToSVGString(p2, &str2);
}

class ArcsView : public SampleView {
    class MyDrawable : public SkDrawable {
<<<<<<< HEAD
        SkRect fR;
        SkScalar fSweep;

    public:
        MyDrawable(const SkRect& r)
            : fR(r)
            , fSweep(0)
        {
        }

        void setSweep(SkScalar sweep)
        {
=======
        SkRect   fR;
        SkScalar fSweep;
    public:
        MyDrawable(const SkRect& r) : fR(r), fSweep(0) {}

        void setSweep(SkScalar sweep) {
>>>>>>> miniblink49
            if (fSweep != sweep) {
                fSweep = sweep;
                this->notifyDrawingChanged();
            }
        }

<<<<<<< HEAD
        void onDraw(SkCanvas* canvas) override
        {
=======
        void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
            SkPaint paint;
            paint.setAntiAlias(true);
            paint.setStrokeWidth(SkIntToScalar(2));

            paint.setStyle(SkPaint::kFill_Style);
            paint.setColor(0x800000FF);
            canvas->drawArc(fR, 0, fSweep, true, paint);

            paint.setColor(0x800FF000);
            canvas->drawArc(fR, 0, fSweep, false, paint);

            paint.setStyle(SkPaint::kStroke_Style);
            paint.setColor(SK_ColorRED);
            canvas->drawArc(fR, 0, fSweep, true, paint);

            paint.setStrokeWidth(0);
            paint.setColor(SK_ColorBLUE);
            canvas->drawArc(fR, 0, fSweep, false, paint);
        }

<<<<<<< HEAD
        SkRect onGetBounds() override
        {
=======
        SkRect onGetBounds() override {
>>>>>>> miniblink49
            SkRect r(fR);
            r.outset(2, 2);
            return r;
        }
    };

public:
    SkRect fRect;
<<<<<<< HEAD
    sk_sp<MyDrawable> fAnimatingDrawable;
    sk_sp<SkDrawable> fRootDrawable;

    ArcsView()
    {
=======
    MyDrawable* fAnimatingDrawable;
    SkDrawable* fRootDrawable;

    ArcsView() {
>>>>>>> miniblink49
        testparse();
        fSweep = SkIntToScalar(100);
        this->setBGColor(0xFFDDDDDD);

        fRect.set(0, 0, SkIntToScalar(200), SkIntToScalar(200));
        fRect.offset(SkIntToScalar(20), SkIntToScalar(20));
<<<<<<< HEAD
        fAnimatingDrawable = sk_make_sp<MyDrawable>(fRect);

        SkPictureRecorder recorder;
        this->drawRoot(recorder.beginRecording(SkRect::MakeWH(800, 500)));
        fRootDrawable = recorder.finishRecordingAsDrawable();
=======
        fAnimatingDrawable = SkNEW_ARGS(MyDrawable, (fRect));

        SkPictureRecorder recorder;
        this->drawRoot(recorder.beginRecording(SkRect::MakeWH(800, 500)));
        fRootDrawable = recorder.endRecordingAsDrawable();
    }

    ~ArcsView() override {
        fAnimatingDrawable->unref();
        fRootDrawable->unref();
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
            SampleCode::TitleR(evt, "Arcs");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    static void DrawRectWithLines(SkCanvas* canvas, const SkRect& r, const SkPaint& p)
    {
=======
    static void DrawRectWithLines(SkCanvas* canvas, const SkRect& r, const SkPaint& p) {
>>>>>>> miniblink49
        canvas->drawRect(r, p);
        canvas->drawLine(r.fLeft, r.fTop, r.fRight, r.fBottom, p);
        canvas->drawLine(r.fLeft, r.fBottom, r.fRight, r.fTop, p);
        canvas->drawLine(r.fLeft, r.centerY(), r.fRight, r.centerY(), p);
        canvas->drawLine(r.centerX(), r.fTop, r.centerX(), r.fBottom, p);
    }

<<<<<<< HEAD
    static void DrawLabel(SkCanvas* canvas, const SkRect& rect, SkScalar start, SkScalar sweep)
    {
=======
    static void DrawLabel(SkCanvas* canvas, const SkRect& rect, SkScalar start, SkScalar sweep) {
>>>>>>> miniblink49
        SkPaint paint;

        paint.setAntiAlias(true);
        paint.setTextAlign(SkPaint::kCenter_Align);

<<<<<<< HEAD
        SkString str;
=======
        SkString    str;
>>>>>>> miniblink49

        str.appendScalar(start);
        str.append(", ");
        str.appendScalar(sweep);
        canvas->drawText(str.c_str(), str.size(), rect.centerX(),
<<<<<<< HEAD
            rect.fBottom + paint.getTextSize() * 5 / 4, paint);
    }

    static void DrawArcs(SkCanvas* canvas)
    {
        SkPaint paint;
        SkRect r;
=======
                         rect.fBottom + paint.getTextSize() * 5/4, paint);
    }

    static void DrawArcs(SkCanvas* canvas) {
        SkPaint paint;
        SkRect  r;
>>>>>>> miniblink49
        SkScalar w = 75;
        SkScalar h = 50;

        r.set(0, 0, w, h);
        paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);

        canvas->save();
        canvas->translate(SkIntToScalar(10), SkIntToScalar(300));

        paint.setStrokeWidth(SkIntToScalar(1));

        static const SkScalar gAngles[] = {
            0, 360,
            0, 45,
            0, -45,
            720, 135,
            -90, 269,
            -90, 270,
            -90, 271,
            -180, -270,
            225, 90
        };

        for (size_t i = 0; i < SK_ARRAY_COUNT(gAngles); i += 2) {
            paint.setColor(SK_ColorBLACK);
            DrawRectWithLines(canvas, r, paint);

            paint.setColor(SK_ColorRED);
<<<<<<< HEAD
            canvas->drawArc(r, gAngles[i], gAngles[i + 1], false, paint);

            DrawLabel(canvas, r, gAngles[i], gAngles[i + 1]);
=======
            canvas->drawArc(r, gAngles[i], gAngles[i+1], false, paint);

            DrawLabel(canvas, r, gAngles[i], gAngles[i+1]);
>>>>>>> miniblink49

            canvas->translate(w * 8 / 7, 0);
        }

        canvas->restore();
    }

<<<<<<< HEAD
    void drawRoot(SkCanvas* canvas)
    {
=======
    void drawRoot(SkCanvas* canvas) {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setStrokeWidth(SkIntToScalar(2));
        paint.setStyle(SkPaint::kStroke_Style);

        DrawRectWithLines(canvas, fRect, paint);

<<<<<<< HEAD
        canvas->drawDrawable(fAnimatingDrawable.get());
=======
        canvas->drawDrawable(fAnimatingDrawable);
>>>>>>> miniblink49

        DrawArcs(canvas);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
        canvas->drawDrawable(fRootDrawable.get());
    }

    bool onAnimate(const SkAnimTimer& timer) override
    {
=======
    void onDrawContent(SkCanvas* canvas) override {
        canvas->drawDrawable(fRootDrawable);
    }

    bool onAnimate(const SkAnimTimer& timer) override {
>>>>>>> miniblink49
        SkScalar angle = SkDoubleToScalar(fmod(timer.secs() * 360 / 24, 360));
        fAnimatingDrawable->setSweep(angle);
        return true;
    }

<<<<<<< HEAD
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override
    {
        //   fSweep += SK_Scalar1;
        this->inval(nullptr);
=======
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override {
     //   fSweep += SK_Scalar1;
        this->inval(NULL);
>>>>>>> miniblink49
        return this->INHERITED::onFindClickHandler(x, y, modi);
    }

private:
    SkScalar fSweep;

    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new ArcsView; }
static SkViewRegister reg(MyFactory);
