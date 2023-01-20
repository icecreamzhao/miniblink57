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
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkString.h"

<<<<<<< HEAD
static bool union_proc(SkRegion& a, SkRegion& b)
{
=======
static bool union_proc(SkRegion& a, SkRegion& b) {
>>>>>>> miniblink49
    SkRegion result;
    return result.op(a, b, SkRegion::kUnion_Op);
}

<<<<<<< HEAD
static bool sect_proc(SkRegion& a, SkRegion& b)
{
=======
static bool sect_proc(SkRegion& a, SkRegion& b) {
>>>>>>> miniblink49
    SkRegion result;
    return result.op(a, b, SkRegion::kIntersect_Op);
}

<<<<<<< HEAD
static bool diff_proc(SkRegion& a, SkRegion& b)
{
=======
static bool diff_proc(SkRegion& a, SkRegion& b) {
>>>>>>> miniblink49
    SkRegion result;
    return result.op(a, b, SkRegion::kDifference_Op);
}

<<<<<<< HEAD
static bool diffrect_proc(SkRegion& a, SkRegion& b)
{
=======
static bool diffrect_proc(SkRegion& a, SkRegion& b) {
>>>>>>> miniblink49
    SkRegion result;
    return result.op(a, b.getBounds(), SkRegion::kDifference_Op);
}

<<<<<<< HEAD
static bool diffrectbig_proc(SkRegion& a, SkRegion& b)
{
=======
static bool diffrectbig_proc(SkRegion& a, SkRegion& b) {
>>>>>>> miniblink49
    SkRegion result;
    return result.op(a, a.getBounds(), SkRegion::kDifference_Op);
}

<<<<<<< HEAD
static bool containsrect_proc(SkRegion& a, SkRegion& b)
{
    SkIRect r = a.getBounds();
    r.inset(r.width() / 4, r.height() / 4);
    (void)a.contains(r);

    r = b.getBounds();
    r.inset(r.width() / 4, r.height() / 4);
    return b.contains(r);
}

static bool sectsrgn_proc(SkRegion& a, SkRegion& b)
{
    return a.intersects(b);
}

static bool sectsrect_proc(SkRegion& a, SkRegion& b)
{
    SkIRect r = a.getBounds();
    r.inset(r.width() / 4, r.height() / 4);
    return a.intersects(r);
}

static bool containsxy_proc(SkRegion& a, SkRegion& b)
{
=======
static bool containsrect_proc(SkRegion& a, SkRegion& b) {
    SkIRect r = a.getBounds();
    r.inset(r.width()/4, r.height()/4);
    (void)a.contains(r);

    r = b.getBounds();
    r.inset(r.width()/4, r.height()/4);
    return b.contains(r);
}

static bool sectsrgn_proc(SkRegion& a, SkRegion& b) {
    return a.intersects(b);
}

static bool sectsrect_proc(SkRegion& a, SkRegion& b) {
    SkIRect r = a.getBounds();
    r.inset(r.width()/4, r.height()/4);
    return a.intersects(r);
}

static bool containsxy_proc(SkRegion& a, SkRegion& b) {
>>>>>>> miniblink49
    const SkIRect& r = a.getBounds();
    const int dx = r.width() / 8;
    const int dy = r.height() / 8;
    for (int y = r.fTop; y < r.fBottom; y += dy) {
        for (int x = r.fLeft; x < r.fRight; x += dx) {
            (void)a.contains(x, y);
        }
    }
    return true;
}

class RegionBench : public Benchmark {
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
        W = 1024,
        H = 768,
    };

<<<<<<< HEAD
    SkIRect randrect(SkRandom& rand)
    {
=======
    SkIRect randrect(SkRandom& rand) {
>>>>>>> miniblink49
        int x = rand.nextU() % W;
        int y = rand.nextU() % H;
        int w = rand.nextU() % W;
        int h = rand.nextU() % H;
        return SkIRect::MakeXYWH(x, y, w >> 1, h >> 1);
    }

<<<<<<< HEAD
    RegionBench(int count, Proc proc, const char name[])
    {
=======
    RegionBench(int count, Proc proc, const char name[])  {
>>>>>>> miniblink49
        fProc = proc;
        fName.printf("region_%s_%d", name, count);

        SkRandom rand;
        for (int i = 0; i < count; i++) {
            fA.op(randrect(rand), SkRegion::kXOR_Op);
            fB.op(randrect(rand), SkRegion::kXOR_Op);
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
    const char* onGetName() override { return fName.c_str(); }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    virtual const char* onGetName() { return fName.c_str(); }

    virtual void onDraw(const int loops, SkCanvas* canvas) {
>>>>>>> miniblink49
        Proc proc = fProc;
        for (int i = 0; i < loops; ++i) {
            proc(fA, fB);
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#define SMALL 16

DEF_BENCH(return new RegionBench(SMALL, union_proc, "union");)
DEF_BENCH(return new RegionBench(SMALL, sect_proc, "intersect");)
DEF_BENCH(return new RegionBench(SMALL, diff_proc, "difference");)
DEF_BENCH(return new RegionBench(SMALL, diffrect_proc, "differencerect");)
DEF_BENCH(return new RegionBench(SMALL, diffrectbig_proc, "differencerectbig");)
DEF_BENCH(return new RegionBench(SMALL, containsrect_proc, "containsrect");)
DEF_BENCH(return new RegionBench(SMALL, sectsrgn_proc, "intersectsrgn");)
DEF_BENCH(return new RegionBench(SMALL, sectsrect_proc, "intersectsrect");)
DEF_BENCH(return new RegionBench(SMALL, containsxy_proc, "containsxy");)
=======
#define SMALL   16

DEF_BENCH( return SkNEW_ARGS(RegionBench, (SMALL, union_proc, "union")); )
DEF_BENCH( return SkNEW_ARGS(RegionBench, (SMALL, sect_proc, "intersect")); )
DEF_BENCH( return SkNEW_ARGS(RegionBench, (SMALL, diff_proc, "difference")); )
DEF_BENCH( return SkNEW_ARGS(RegionBench, (SMALL, diffrect_proc, "differencerect")); )
DEF_BENCH( return SkNEW_ARGS(RegionBench, (SMALL, diffrectbig_proc, "differencerectbig")); )
DEF_BENCH( return SkNEW_ARGS(RegionBench, (SMALL, containsrect_proc, "containsrect")); )
DEF_BENCH( return SkNEW_ARGS(RegionBench, (SMALL, sectsrgn_proc, "intersectsrgn")); )
DEF_BENCH( return SkNEW_ARGS(RegionBench, (SMALL, sectsrect_proc, "intersectsrect")); )
DEF_BENCH( return SkNEW_ARGS(RegionBench, (SMALL, containsxy_proc, "containsxy")); )
>>>>>>> miniblink49
