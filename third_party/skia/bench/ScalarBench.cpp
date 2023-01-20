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
#include "SkFloatBits.h"
#include "SkRandom.h"
#include "SkRect.h"
#include "SkString.h"

class ScalarBench : public Benchmark {
<<<<<<< HEAD
    SkString fName;

public:
    ScalarBench(const char name[])
    {
        fName.printf("scalar_%s", name);
    }

    bool isSuitableFor(Backend backend) override
    {
=======
    SkString    fName;
public:
    ScalarBench(const char name[])  {
        fName.printf("scalar_%s", name);
    }

    bool isSuitableFor(Backend backend) override {
>>>>>>> miniblink49
        return backend == kNonRendering_Backend;
    }

    virtual void performTest() = 0;

protected:
    virtual int mulLoopCount() const { return 1; }

<<<<<<< HEAD
    const char* onGetName() override
    {
        return fName.c_str();
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    const char* onGetName() override {
        return fName.c_str();
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        for (int i = 0; i < loops; i++) {
            this->performTest();
        }
    }

private:
    typedef Benchmark INHERITED;
};

// having unknown values in our arrays can throw off the timing a lot, perhaps
// handling NaN values is a lot slower. Anyway, this guy is just meant to put
// reasonable values in our arrays.
<<<<<<< HEAD
template <typename T>
void init9(T array[9])
{
=======
template <typename T> void init9(T array[9]) {
>>>>>>> miniblink49
    SkRandom rand;
    for (int i = 0; i < 9; i++) {
        array[i] = rand.nextSScalar1();
    }
}

class FloatComparisonBench : public ScalarBench {
public:
<<<<<<< HEAD
    FloatComparisonBench()
        : INHERITED("compare_float")
    {
        init9(fArray);
    }

protected:
    virtual int mulLoopCount() const { return 4; }
    virtual void performTest()
    {
=======
    FloatComparisonBench() : INHERITED("compare_float") {
        init9(fArray);
    }
protected:
    virtual int mulLoopCount() const { return 4; }
    virtual void performTest() {
>>>>>>> miniblink49
        // xoring into a volatile prevents the compiler from optimizing these checks away.
        volatile bool junk = false;
        junk ^= (fArray[6] != 0.0f || fArray[7] != 0.0f || fArray[8] != 1.0f);
        junk ^= (fArray[2] != 0.0f || fArray[5] != 0.0f);
    }
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    float fArray[9];
    typedef ScalarBench INHERITED;
};

class ForcedIntComparisonBench : public ScalarBench {
public:
    ForcedIntComparisonBench()
<<<<<<< HEAD
        : INHERITED("compare_forced_int")
    {
        init9(fArray);
    }

protected:
    virtual int mulLoopCount() const { return 4; }
    virtual void performTest()
    {
        // xoring into a volatile prevents the compiler from optimizing these checks away.
        volatile int32_t junk = 0;
        junk ^= (SkScalarAs2sCompliment(fArray[6]) | SkScalarAs2sCompliment(fArray[7]) | (SkScalarAs2sCompliment(fArray[8]) - kPersp1Int));
        junk ^= (SkScalarAs2sCompliment(fArray[2]) | SkScalarAs2sCompliment(fArray[5]));
    }

=======
    : INHERITED("compare_forced_int") {
        init9(fArray);
    }
protected:
    virtual int mulLoopCount() const { return 4; }
    virtual void performTest() {
        // xoring into a volatile prevents the compiler from optimizing these checks away.
        volatile int32_t junk = 0;
        junk ^= (SkScalarAs2sCompliment(fArray[6]) |
                 SkScalarAs2sCompliment(fArray[7]) |
                (SkScalarAs2sCompliment(fArray[8]) - kPersp1Int));
        junk ^= (SkScalarAs2sCompliment(fArray[2]) |
                 SkScalarAs2sCompliment(fArray[5]));
    }
>>>>>>> miniblink49
private:
    static const int32_t kPersp1Int = 0x3f800000;
    SkScalar fArray[9];
    typedef ScalarBench INHERITED;
};

class IsFiniteScalarBench : public ScalarBench {
public:
<<<<<<< HEAD
    IsFiniteScalarBench()
        : INHERITED("isfinite")
    {
=======
    IsFiniteScalarBench() : INHERITED("isfinite") {
>>>>>>> miniblink49
        SkRandom rand;
        for (size_t i = 0; i < ARRAY_N; ++i) {
            fArray[i] = rand.nextSScalar1();
        }
    }
<<<<<<< HEAD

protected:
    int mulLoopCount() const override { return 1; }
    void performTest() override
    {
=======
protected:
    int mulLoopCount() const override { return 1; }
    void performTest() override {
>>>>>>> miniblink49
        int sum = 0;
        for (size_t i = 0; i < ARRAY_N; ++i) {
            // We pass -fArray[i], so the compiler can't cheat and treat the
            // value as an int (even though we tell it that it is a float)
            sum += SkScalarIsFinite(-fArray[i]);
        }
        // we do this so the compiler won't optimize our loop away...
        this->doSomething(fArray, sum);
    }

<<<<<<< HEAD
    virtual void doSomething(SkScalar array[], int sum) { }

=======
    virtual void doSomething(SkScalar array[], int sum) {}
>>>>>>> miniblink49
private:
    enum {
        ARRAY_N = 64
    };
    SkScalar fArray[ARRAY_N];

    typedef ScalarBench INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

class RectBoundsBench : public Benchmark {
    enum {
        PTS = 100,
    };
    SkPoint fPts[PTS];

public:
<<<<<<< HEAD
    RectBoundsBench()
    {
=======
    RectBoundsBench() {
>>>>>>> miniblink49
        SkRandom rand;
        for (int i = 0; i < PTS; ++i) {
            fPts[i].fX = rand.nextSScalar1();
            fPts[i].fY = rand.nextSScalar1();
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
        return "rect_bounds";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    const char* onGetName() override {
        return "rect_bounds";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkRect r;
        for (int i = 0; i < loops; ++i) {
            for (int i = 0; i < 1000; ++i) {
                r.set(fPts, PTS);
            }
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new FloatComparisonBench();)
DEF_BENCH(return new ForcedIntComparisonBench();)
DEF_BENCH(return new RectBoundsBench();)
DEF_BENCH(return new IsFiniteScalarBench();)
=======
DEF_BENCH( return new FloatComparisonBench(); )
DEF_BENCH( return new ForcedIntComparisonBench(); )
DEF_BENCH( return new RectBoundsBench(); )
DEF_BENCH( return new IsFiniteScalarBench(); )
>>>>>>> miniblink49
