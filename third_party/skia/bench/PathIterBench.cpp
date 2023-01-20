<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "Benchmark.h"
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkColorPriv.h"
#include "SkPaint.h"
<<<<<<< HEAD
#include "SkPath.h"
=======
>>>>>>> miniblink49
#include "SkRandom.h"
#include "SkShader.h"
#include "SkString.h"

<<<<<<< HEAD
static int rand_pts(SkRandom& rand, SkPoint pts[4])
{
=======
static int rand_pts(SkRandom& rand, SkPoint pts[4]) {
>>>>>>> miniblink49
    int n = rand.nextU() & 3;
    n += 1;

    for (int i = 0; i < n; ++i) {
        pts[i].fX = rand.nextSScalar1();
        pts[i].fY = rand.nextSScalar1();
    }
    return n;
}

class PathIterBench : public Benchmark {
<<<<<<< HEAD
    SkString fName;
    SkPath fPath;
    bool fRaw;

public:
    PathIterBench(bool raw)
    {
=======
    SkString    fName;
    SkPath      fPath;
    bool        fRaw;

public:
    PathIterBench(bool raw)  {
>>>>>>> miniblink49
        fName.printf("pathiter_%s", raw ? "raw" : "consume");
        fRaw = raw;

        SkRandom rand;
        for (int i = 0; i < 1000; ++i) {
            SkPoint pts[4];
            int n = rand_pts(rand, pts);
            switch (n) {
<<<<<<< HEAD
            case 1:
                fPath.moveTo(pts[0]);
                break;
            case 2:
                fPath.lineTo(pts[1]);
                break;
            case 3:
                fPath.quadTo(pts[1], pts[2]);
                break;
            case 4:
                fPath.cubicTo(pts[1], pts[2], pts[3]);
                break;
=======
                case 1:
                    fPath.moveTo(pts[0]);
                    break;
                case 2:
                    fPath.lineTo(pts[1]);
                    break;
                case 3:
                    fPath.quadTo(pts[1], pts[2]);
                    break;
                case 4:
                    fPath.cubicTo(pts[1], pts[2], pts[3]);
                    break;
>>>>>>> miniblink49
            }
        }
    }

<<<<<<< HEAD
    bool isSuitableFor(Backend backend) override
    {
=======
    bool isSuitableFor(Backend backend) override {
>>>>>>> miniblink49
        return backend == kNonRendering_Backend;
    }

protected:
<<<<<<< HEAD
    const char* onGetName() override
    {
        return fName.c_str();
    }

    void onDraw(int loops, SkCanvas*) override
    {
=======
    const char* onGetName() override {
        return fName.c_str();
    }

    void onDraw(const int loops, SkCanvas*) override {
>>>>>>> miniblink49
        if (fRaw) {
            for (int i = 0; i < loops; ++i) {
                SkPath::RawIter iter(fPath);
                SkPath::Verb verb;
<<<<<<< HEAD
                SkPoint pts[4];
=======
                SkPoint      pts[4];
>>>>>>> miniblink49

                while ((verb = iter.next(pts)) != SkPath::kDone_Verb) { }
            }
        } else {
            for (int i = 0; i < loops; ++i) {
                SkPath::Iter iter(fPath, false);
                SkPath::Verb verb;
<<<<<<< HEAD
                SkPoint pts[4];
=======
                SkPoint      pts[4];
>>>>>>> miniblink49

                while ((verb = iter.next(pts)) != SkPath::kDone_Verb) { }
            }
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new PathIterBench(false);)
DEF_BENCH(return new PathIterBench(true);)
=======
DEF_BENCH( return new PathIterBench(false); )
DEF_BENCH( return new PathIterBench(true); )
>>>>>>> miniblink49
