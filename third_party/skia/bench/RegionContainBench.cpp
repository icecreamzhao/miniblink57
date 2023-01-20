/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkString.h"

<<<<<<< HEAD
static bool sect_proc(SkRegion& a, SkRegion& b)
{
=======
static bool sect_proc(SkRegion& a, SkRegion& b) {
>>>>>>> miniblink49
    SkRegion result;
    return result.op(a, b, SkRegion::kIntersect_Op);
}

class RegionContainBench : public Benchmark {
public:
    typedef bool (*Proc)(SkRegion& a, SkRegion& b);
    SkRegion fA, fB;
<<<<<<< HEAD
    Proc fProc;
=======
    Proc     fProc;
>>>>>>> miniblink49
    SkString fName;

    enum {
        W = 200,
        H = 200,
        COUNT = 10,
    };

<<<<<<< HEAD
    SkIRect randrect(SkRandom& rand, int i)
    {
        int w = rand.nextU() % W;
        return SkIRect::MakeXYWH(0, i * H / COUNT, w, H / COUNT);
    }

    RegionContainBench(Proc proc, const char name[])
    {
=======
    SkIRect randrect(SkRandom& rand, int i) {
        int w = rand.nextU() % W;
        return SkIRect::MakeXYWH(0, i*H/COUNT, w, H/COUNT);
    }

    RegionContainBench(Proc proc, const char name[])  {
>>>>>>> miniblink49
        fProc = proc;
        fName.printf("region_contains_%s", name);

        SkRandom rand;
        for (int i = 0; i < COUNT; i++) {
            fA.op(randrect(rand, i), SkRegion::kXOR_Op);
        }

        fB.setRect(0, 0, H, W);
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
    const char* onGetName() override { return fName.c_str(); }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas*) override
    {
        Proc proc = fProc;

        for (int i = 0; i < loops; ++i) {
            proc(fA, fB);
=======
    void onDraw(const int loops, SkCanvas*) override {
        Proc proc = fProc;

        for (int i = 0; i < loops; ++i) {
           proc(fA, fB);
>>>>>>> miniblink49
        }
    }

private:
    typedef Benchmark INHERITED;
};

<<<<<<< HEAD
DEF_BENCH(return new RegionContainBench(sect_proc, "sect");)
=======
DEF_BENCH( return SkNEW_ARGS(RegionContainBench, (sect_proc, "sect")); )
>>>>>>> miniblink49
