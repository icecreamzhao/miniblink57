/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SampleCode.h"
#include "SkAnimTimer.h"
<<<<<<< HEAD
=======
#include "SkView.h"
>>>>>>> miniblink49
#include "SkCanvas.h"
#include "SkDrawable.h"
#include "SkInterpolator.h"
#include "SkPictureRecorder.h"
#include "SkRandom.h"
<<<<<<< HEAD
#include "SkView.h"

const SkRect gUnitSquare = { -1, -1, 1, 1 };

static void color_to_floats(SkColor c, SkScalar f[4])
{
=======

const SkRect gUnitSquare = { -1, -1, 1, 1 };

static void color_to_floats(SkColor c, SkScalar f[4]) {
>>>>>>> miniblink49
    f[0] = SkIntToScalar(SkColorGetA(c));
    f[1] = SkIntToScalar(SkColorGetR(c));
    f[2] = SkIntToScalar(SkColorGetG(c));
    f[3] = SkIntToScalar(SkColorGetB(c));
}

<<<<<<< HEAD
static SkColor floats_to_color(const SkScalar f[4])
{
    return SkColorSetARGB(SkScalarRoundToInt(f[0]),
        SkScalarRoundToInt(f[1]),
        SkScalarRoundToInt(f[2]),
        SkScalarRoundToInt(f[3]));
}

static bool oval_contains(const SkRect& r, SkScalar x, SkScalar y)
{
=======
static SkColor floats_to_color(const SkScalar f[4]) {
    return SkColorSetARGB(SkScalarRoundToInt(f[0]),
                          SkScalarRoundToInt(f[1]),
                          SkScalarRoundToInt(f[2]),
                          SkScalarRoundToInt(f[3]));
}

static bool oval_contains(const SkRect& r, SkScalar x, SkScalar y) {
>>>>>>> miniblink49
    SkMatrix m;
    m.setRectToRect(r, gUnitSquare, SkMatrix::kFill_ScaleToFit);
    SkPoint pt;
    m.mapXY(x, y, &pt);
    return pt.lengthSqd() <= 1;
}

<<<<<<< HEAD
static SkColor rand_opaque_color(uint32_t seed)
{
=======
static SkColor rand_opaque_color(uint32_t seed) {
>>>>>>> miniblink49
    SkRandom rand(seed);
    return rand.nextU() | (0xFF << 24);
}

class HTDrawable : public SkDrawable {
<<<<<<< HEAD
    SkRect fR;
    SkColor fColor;
    SkInterpolator* fInterp;
    SkMSec fTime;

public:
    HTDrawable(SkRandom& rand)
    {
        fR = SkRect::MakeXYWH(rand.nextRangeF(0, 640), rand.nextRangeF(0, 480),
            rand.nextRangeF(20, 200), rand.nextRangeF(20, 200));
        fColor = rand_opaque_color(rand.nextU());
        fInterp = nullptr;
        fTime = 0;
    }

    void spawnAnimation(SkMSec now)
    {
        this->setTime(now);

        delete fInterp;
        fInterp = new SkInterpolator(5, 3);
        SkScalar values[5];
        color_to_floats(fColor, values);
        values[4] = 0;
        fInterp->setKeyFrame(0, now, values);
        values[0] = 0;
        values[4] = 180;
        fInterp->setKeyFrame(1, now + 1000, values);
        color_to_floats(rand_opaque_color(fColor), values);
        values[4] = 360;
=======
    SkRect          fR;
    SkColor         fColor;
    SkInterpolator* fInterp;
    SkMSec          fTime;

public:
    HTDrawable(SkRandom& rand) {
        fR = SkRect::MakeXYWH(rand.nextRangeF(0, 640), rand.nextRangeF(0, 480),
                              rand.nextRangeF(20, 200), rand.nextRangeF(20, 200));
        fColor = rand_opaque_color(rand.nextU());
        fInterp = NULL;
        fTime = 0;
    }
    
    void spawnAnimation(SkMSec now) {
        this->setTime(now);

        SkDELETE(fInterp);
        fInterp = SkNEW_ARGS(SkInterpolator, (5, 3));
        SkScalar values[5];
        color_to_floats(fColor, values); values[4] = 0;
        fInterp->setKeyFrame(0, now, values);
        values[0] = 0; values[4] = 180;
        fInterp->setKeyFrame(1, now + 1000, values);
        color_to_floats(rand_opaque_color(fColor), values); values[4] = 360;
>>>>>>> miniblink49
        fInterp->setKeyFrame(2, now + 2000, values);

        fInterp->setMirror(true);
        fInterp->setRepeatCount(3);

        this->notifyDrawingChanged();
    }

<<<<<<< HEAD
    bool hitTest(SkScalar x, SkScalar y)
    {
=======
    bool hitTest(SkScalar x, SkScalar y) {
>>>>>>> miniblink49
        return oval_contains(fR, x, y);
    }

    void setTime(SkMSec time) { fTime = time; }

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
=======
    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkAutoCanvasRestore acr(canvas, false);

        SkPaint paint;
        paint.setAntiAlias(true);

        if (fInterp) {
            SkScalar values[5];
            SkInterpolator::Result res = fInterp->timeToValues(fTime, values);
            fColor = floats_to_color(values);

            canvas->save();
            canvas->translate(fR.centerX(), fR.centerY());
            canvas->rotate(values[4]);
            canvas->translate(-fR.centerX(), -fR.centerY());

            switch (res) {
<<<<<<< HEAD
            case SkInterpolator::kFreezeEnd_Result:
                delete fInterp;
                fInterp = nullptr;
                break;
            default:
                break;
=======
                case SkInterpolator::kFreezeEnd_Result:
                    SkDELETE(fInterp);
                    fInterp = NULL;
                    break;
                default:
                    break;
>>>>>>> miniblink49
            }
        }
        paint.setColor(fColor);
        canvas->drawRect(fR, paint);
    }

    SkRect onGetBounds() override { return fR; }
};

class HTView : public SampleView {
public:
    enum {
        N = 50,
        W = 640,
        H = 480,
    };
<<<<<<< HEAD

=======
    
>>>>>>> miniblink49
    struct Rec {
        HTDrawable* fDrawable;
    };
    Rec fArray[N];
<<<<<<< HEAD
    sk_sp<SkDrawable> fRoot;
    SkMSec fTime;

    HTView()
    {
=======
    SkAutoTUnref<SkDrawable> fRoot;
    SkMSec fTime;
    
    HTView() {
>>>>>>> miniblink49
        SkRandom rand;

        SkPictureRecorder recorder;
        SkCanvas* canvas = recorder.beginRecording(SkRect::MakeWH(W, H));
        for (int i = 0; i < N; ++i) {
            fArray[i].fDrawable = new HTDrawable(rand);
            canvas->drawDrawable(fArray[i].fDrawable);
            fArray[i].fDrawable->unref();
        }
<<<<<<< HEAD
        fRoot = recorder.finishRecordingAsDrawable();
    }

protected:
    bool onQuery(SkEvent* evt) override
    {
=======
        fRoot.reset(recorder.endRecordingAsDrawable());
    }

protected:
    bool onQuery(SkEvent* evt) override {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "HT");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
        canvas->drawDrawable(fRoot.get());
    }

    bool onAnimate(const SkAnimTimer& timer) override
    {
=======
    void onDrawContent(SkCanvas* canvas) override {
        canvas->drawDrawable(fRoot);
    }

    bool onAnimate(const SkAnimTimer& timer) override {
>>>>>>> miniblink49
        fTime = timer.msec();
        for (int i = 0; i < N; ++i) {
            fArray[i].fDrawable->setTime(fTime);
        }
        return true;
    }

<<<<<<< HEAD
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override
    {
=======
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override {
>>>>>>> miniblink49
        // search backwards to find the top-most
        for (int i = N - 1; i >= 0; --i) {
            if (fArray[i].fDrawable->hitTest(x, y)) {
                fArray[i].fDrawable->spawnAnimation(fTime);
                break;
            }
        }
<<<<<<< HEAD
        this->inval(nullptr);
        return nullptr;
=======
        this->inval(NULL);
        return NULL;
>>>>>>> miniblink49
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new HTView; }
static SkViewRegister reg(MyFactory);
