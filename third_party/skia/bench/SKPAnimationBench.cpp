/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SKPAnimationBench.h"
#include "SkCommandLineFlags.h"
#include "SkMultiPictureDraw.h"
#include "SkSurface.h"

SKPAnimationBench::SKPAnimationBench(const char* name, const SkPicture* pic, const SkIRect& clip,
<<<<<<< HEAD
    Animation* animation, bool doLooping)
    : INHERITED(name, pic, clip, 1.0, false, doLooping)
    , fAnimation(SkRef(animation))
{
    fUniqueName.printf("%s_%s", name, fAnimation->getTag());
}

const char* SKPAnimationBench::onGetUniqueName()
{
    return fUniqueName.c_str();
}

void SKPAnimationBench::onPerCanvasPreDraw(SkCanvas* canvas)
{
=======
                                     Animation* animation, bool doLooping)
    : INHERITED(name, pic, clip, 1.0, false, doLooping)
    , fAnimation(SkRef(animation)) {
    fUniqueName.printf("%s_%s", name, fAnimation->getTag());
}

const char* SKPAnimationBench::onGetUniqueName() {
    return fUniqueName.c_str();
}

void SKPAnimationBench::onPerCanvasPreDraw(SkCanvas* canvas) {
>>>>>>> miniblink49
    INHERITED::onPerCanvasPreDraw(canvas);
    SkAssertResult(canvas->getClipDeviceBounds(&fDevBounds));
    fAnimationTimer.start();
}

<<<<<<< HEAD
void SKPAnimationBench::drawPicture()
{
=======
void SKPAnimationBench::drawPicture() {
>>>>>>> miniblink49
    fAnimationTimer.end();

    for (int j = 0; j < this->tileRects().count(); ++j) {
        SkMatrix trans = SkMatrix::MakeTrans(-1.f * this->tileRects()[j].fLeft,
<<<<<<< HEAD
            -1.f * this->tileRects()[j].fTop);
        fAnimation->preConcatFrameMatrix(fAnimationTimer.fWall, fDevBounds, &trans);
        this->surfaces()[j]->getCanvas()->drawPicture(this->picture(), &trans, nullptr);
    }

    for (int j = 0; j < this->tileRects().count(); ++j) {
        this->surfaces()[j]->getCanvas()->flush();
=======
                                             -1.f * this->tileRects()[j].fTop);
        fAnimation->preConcatFrameMatrix(fAnimationTimer.fWall, fDevBounds, &trans);
        this->surfaces()[j]->getCanvas()->drawPicture(this->picture(), &trans, NULL);
    }

    for (int j = 0; j < this->tileRects().count(); ++j) {
       this->surfaces()[j]->getCanvas()->flush();
>>>>>>> miniblink49
    }
}

class ZoomAnimation : public SKPAnimationBench::Animation {
public:
    ZoomAnimation(SkScalar zoomMax, double zoomPeriodMs)
        : fZoomMax(zoomMax)
<<<<<<< HEAD
        , fZoomPeriodMs(zoomPeriodMs)
    {
=======
        , fZoomPeriodMs(zoomPeriodMs) {
>>>>>>> miniblink49
    }

    virtual const char* getTag() { return "zoom"; }

    virtual void preConcatFrameMatrix(double animationTimeMs, const SkIRect& devBounds,
<<<<<<< HEAD
        SkMatrix* drawMatrix)
    {
=======
                                      SkMatrix* drawMatrix) {
>>>>>>> miniblink49
        double t = fmod(animationTimeMs / fZoomPeriodMs, 1.0); // t is in [0, 1).
        t = fabs(2 * t - 1); // Make t ping-pong between 0 and 1
        SkScalar zoom = static_cast<SkScalar>(pow(fZoomMax, t));

        SkPoint center = SkPoint::Make((devBounds.fLeft + devBounds.fRight) / 2.0f,
<<<<<<< HEAD
            (devBounds.fTop + devBounds.fBottom) / 2.0f);
=======
                                       (devBounds.fTop + devBounds.fBottom) / 2.0f);
>>>>>>> miniblink49
        drawMatrix->preTranslate(center.fX, center.fY);
        drawMatrix->preScale(zoom, zoom);
        drawMatrix->preTranslate(-center.fX, -center.fY);
    }

private:
<<<<<<< HEAD
    double fZoomMax;
    double fZoomPeriodMs;
};

SKPAnimationBench::Animation* SKPAnimationBench::CreateZoomAnimation(SkScalar zoomMax,
    double zoomPeriodMs)
{
    return new ZoomAnimation(zoomMax, zoomPeriodMs);
=======
    double   fZoomMax;
    double   fZoomPeriodMs;
};

SKPAnimationBench::Animation* SKPAnimationBench::CreateZoomAnimation(SkScalar zoomMax,
                                                                     double zoomPeriodMs) {
    return SkNEW_ARGS(ZoomAnimation, (zoomMax, zoomPeriodMs));
>>>>>>> miniblink49
}
