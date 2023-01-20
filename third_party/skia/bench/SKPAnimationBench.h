/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SKPAnimationBench_DEFINED
#define SKPAnimationBench_DEFINED

#include "SKPBench.h"
#include "Timer.h"

/**
 * Runs an SkPicture as a benchmark by repeatedly drawing it, first centering the picture and
 * for each step it concats the passed in matrix
 */
class SKPAnimationBench : public SKPBench {
public:
    class Animation : public SkRefCnt {
    public:
        virtual const char* getTag() = 0;
        virtual void preConcatFrameMatrix(double animationTimeMs, const SkIRect& devBounds,
<<<<<<< HEAD
            SkMatrix* drawMatrix)
            = 0;
        virtual ~Animation() { }
    };

    SKPAnimationBench(const char* name, const SkPicture*, const SkIRect& devClip, Animation*,
        bool doLooping);
=======
                                          SkMatrix* drawMatrix) = 0;
        virtual ~Animation() {}
    };

    SKPAnimationBench(const char* name, const SkPicture*, const SkIRect& devClip, Animation*,
                      bool doLooping);
>>>>>>> miniblink49

    static Animation* CreateZoomAnimation(SkScalar zoomMax, double zoomPeriodMs);

protected:
    const char* onGetUniqueName() override;
    void onPerCanvasPreDraw(SkCanvas* canvas) override;

<<<<<<< HEAD
    void drawMPDPicture() override
    {
=======
    void drawMPDPicture() override {
>>>>>>> miniblink49
        SkFAIL("MPD not supported\n");
    }
    void drawPicture() override;

private:
<<<<<<< HEAD
    SkAutoTUnref<Animation> fAnimation;
    WallTimer fAnimationTimer;
    SkString fUniqueName;
    SkIRect fDevBounds;
=======
    SkAutoTUnref<Animation>   fAnimation;
    WallTimer                 fAnimationTimer;
    SkString                  fUniqueName;
    SkIRect                   fDevBounds;
>>>>>>> miniblink49

    typedef SKPBench INHERITED;
};

#endif
