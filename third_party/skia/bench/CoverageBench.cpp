/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
<<<<<<< HEAD
#include "SkAutoPixmapStorage.h"
=======
>>>>>>> miniblink49
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkColorPriv.h"
#include "SkDraw.h"
#include "SkMatrix.h"
#include "SkPath.h"
#include "SkRasterClip.h"

class DrawPathBench : public Benchmark {
<<<<<<< HEAD
    SkPaint fPaint;
    SkString fName;
    SkPath fPath;
    SkRasterClip fRC;
    SkAutoPixmapStorage fPixmap;
    SkMatrix fIdentity;
    SkDraw fDraw;
    bool fDrawCoverage;

public:
    DrawPathBench(bool drawCoverage)
        : fDrawCoverage(drawCoverage)
    {
=======
    SkPaint     fPaint;
    SkString    fName;
    SkPath      fPath;
    SkRasterClip fRC;
    SkAutoPixmapStorage fPixmap;
    SkMatrix    fIdentity;
    SkDraw      fDraw;
    bool        fDrawCoverage;
public:
    DrawPathBench(bool drawCoverage) : fDrawCoverage(drawCoverage) {
>>>>>>> miniblink49
        fPaint.setAntiAlias(true);
        fName.printf("draw_coverage_%s", drawCoverage ? "true" : "false");

        fPath.moveTo(0, 0);
        fPath.quadTo(500, 0, 500, 500);
        fPath.quadTo(250, 0, 0, 500);

        fPixmap.alloc(SkImageInfo::MakeA8(500, 500));

        fIdentity.setIdentity();
        fRC.setRect(fPath.getBounds().round());

<<<<<<< HEAD
        fDraw.fDst = fPixmap;
        fDraw.fMatrix = &fIdentity;
        fDraw.fRC = &fRC;
    }

protected:
    const char* onGetName() override
    {
        return fName.c_str();
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
        fDraw.fDst      = fPixmap;
        fDraw.fMatrix   = &fIdentity;
        fDraw.fClip     = &fRC.bwRgn();
        fDraw.fRC       = &fRC;
    }

protected:
    const char* onGetName() override {
        return fName.c_str();
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        if (fDrawCoverage) {
            for (int i = 0; i < loops; ++i) {
                fDraw.drawPathCoverage(fPath, fPaint);
            }
        } else {
            for (int i = 0; i < loops; ++i) {
                fDraw.drawPath(fPath, fPaint);
            }
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new DrawPathBench(false))
DEF_BENCH(return new DrawPathBench(true))
=======
DEF_BENCH( return new DrawPathBench(false) )
DEF_BENCH( return new DrawPathBench(true) )
>>>>>>> miniblink49
