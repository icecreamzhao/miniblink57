/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SKPBench_DEFINED
#define SKPBench_DEFINED

#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkPicture.h"
<<<<<<< HEAD
#include "SkTDArray.h"

class SkSurface;
=======
>>>>>>> miniblink49

/**
 * Runs an SkPicture as a benchmark by repeatedly drawing it scaled inside a device clip.
 */
class SKPBench : public Benchmark {
public:
    SKPBench(const char* name, const SkPicture*, const SkIRect& devClip, SkScalar scale,
<<<<<<< HEAD
        bool useMultiPictureDraw, bool doLooping);
    ~SKPBench() override;

    int calculateLoops(int defaultLoops) const override
    {
        return fDoLooping ? defaultLoops : 1;
    }

    void getGpuStats(SkCanvas*, SkTArray<SkString>* keys, SkTArray<double>* values) override;

=======
             bool useMultiPictureDraw, bool doLooping);
    ~SKPBench() override;

    int calculateLoops(int defaultLoops) const override {
        return fDoLooping ? defaultLoops : 1;
    }

>>>>>>> miniblink49
protected:
    const char* onGetName() override;
    const char* onGetUniqueName() override;
    void onPerCanvasPreDraw(SkCanvas*) override;
    void onPerCanvasPostDraw(SkCanvas*) override;
    bool isSuitableFor(Backend backend) override;
<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override;
=======
    void onDraw(const int loops, SkCanvas* canvas) override;
>>>>>>> miniblink49
    SkIPoint onGetSize() override;

    virtual void drawMPDPicture();
    virtual void drawPicture();

    const SkPicture* picture() const { return fPic; }
    const SkTDArray<SkSurface*>& surfaces() const { return fSurfaces; }
    const SkTDArray<SkIRect>& tileRects() const { return fTileRects; }

private:
    SkAutoTUnref<const SkPicture> fPic;
    const SkIRect fClip;
    const SkScalar fScale;
    SkString fName;
    SkString fUniqueName;

    const bool fUseMultiPictureDraw;
<<<<<<< HEAD
    SkTDArray<SkSurface*> fSurfaces; // for MultiPictureDraw
    SkTDArray<SkIRect> fTileRects; // for MultiPictureDraw
=======
    SkTDArray<SkSurface*> fSurfaces;   // for MultiPictureDraw
    SkTDArray<SkIRect> fTileRects;     // for MultiPictureDraw
>>>>>>> miniblink49

    const bool fDoLooping;

    typedef Benchmark INHERITED;
};

#endif
