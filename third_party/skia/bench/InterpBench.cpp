<<<<<<< HEAD
/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkColorPriv.h"
#include "SkFixed.h"
=======
#include "Benchmark.h"
#include "SkColorPriv.h"
>>>>>>> miniblink49
#include "SkMatrix.h"
#include "SkPaint.h"
#include "SkRandom.h"
#include "SkString.h"

<<<<<<< HEAD
#define TILE(x, width) (((x)&0xFFFF) * width >> 16)
=======
#define TILE(x, width)  (((x) & 0xFFFF) * width >> 16)
>>>>>>> miniblink49

class InterpBench : public Benchmark {
    enum {
        kBuffer = 128,
<<<<<<< HEAD
        kLoop = 20000
    };
    SkString fName;
    int16_t fDst[kBuffer];
    float fFx, fDx;

public:
    InterpBench(const char name[])
    {
=======
        kLoop   = 20000
    };
    SkString    fName;
    int16_t     fDst[kBuffer];
    float       fFx, fDx;
public:
    InterpBench(const char name[])  {
>>>>>>> miniblink49
        fName.printf("interp_%s", name);
        fFx = 3.3f;
        fDx = 0.1257f;
    }

<<<<<<< HEAD
    bool isSuitableFor(Backend backend) override
    {
=======
    bool isSuitableFor(Backend backend) override {
>>>>>>> miniblink49
        return backend == kNonRendering_Backend;
    }

    virtual void performTest(int16_t dst[], float x, float dx, int count) = 0;

protected:
    virtual int mulLoopCount() const { return 1; }

<<<<<<< HEAD
    const char* onGetName() override
    {
        return fName.c_str();
    }

    void onDraw(int loops, SkCanvas*) override
    {
=======
    virtual const char* onGetName() {
        return fName.c_str();
    }

    virtual void onDraw(const int loops, SkCanvas*) {
>>>>>>> miniblink49
        int n = loops * this->mulLoopCount();
        for (int i = 0; i < n; i++) {
            this->performTest(fDst, fFx, fDx, kBuffer);
        }
    }

private:
    typedef Benchmark INHERITED;
};

class Fixed16D16Interp : public InterpBench {
public:
<<<<<<< HEAD
    Fixed16D16Interp()
        : INHERITED("16.16")
    {
    }

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override
    {
        SkFixed curr = SkFloatToFixed(fx);
        SkFixed step = SkFloatToFixed(dx);
        for (int i = 0; i < count; i += 4) {
            dst[i + 0] = TILE(curr, count);
            curr += step;
            dst[i + 1] = TILE(curr, count);
            curr += step;
            dst[i + 2] = TILE(curr, count);
            curr += step;
            dst[i + 3] = TILE(curr, count);
            curr += step;
        }
    }

=======
    Fixed16D16Interp() : INHERITED("16.16") {}

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override {
        SkFixed curr = SkFloatToFixed(fx);
        SkFixed step = SkFloatToFixed(dx);
        for (int i = 0; i < count; i += 4) {
            dst[i + 0] = TILE(curr, count); curr += step;
            dst[i + 1] = TILE(curr, count); curr += step;
            dst[i + 2] = TILE(curr, count); curr += step;
            dst[i + 3] = TILE(curr, count); curr += step;
        }
    }
>>>>>>> miniblink49
private:
    typedef InterpBench INHERITED;
};

class Fixed32D32Interp : public InterpBench {
public:
<<<<<<< HEAD
    Fixed32D32Interp()
        : INHERITED("32.32")
    {
    }

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override
    {
=======
    Fixed32D32Interp() : INHERITED("32.32") {}

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override {
>>>>>>> miniblink49
        int64_t curr = (int64_t)(fx * 65536 * 655536);
        int64_t step = (int64_t)(dx * 65536 * 655536);
        SkFixed tmp;
        for (int i = 0; i < count; i += 4) {
            tmp = (SkFixed)(curr >> 16);
            dst[i + 0] = TILE(tmp, count);
            curr += step;

            tmp = (SkFixed)(curr >> 16);
            dst[i + 1] = TILE(tmp, count);
            curr += step;

            tmp = (SkFixed)(curr >> 16);
            dst[i + 2] = TILE(tmp, count);
            curr += step;

            tmp = (SkFixed)(curr >> 16);
            dst[i + 3] = TILE(tmp, count);
            curr += step;
        }
    }
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    typedef InterpBench INHERITED;
};

class Fixed16D48Interp : public InterpBench {
public:
<<<<<<< HEAD
    Fixed16D48Interp()
        : INHERITED("16.48")
    {
    }

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override
    {
=======
    Fixed16D48Interp() : INHERITED("16.48") {}

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override {
>>>>>>> miniblink49
        int64_t curr = (int64_t)(fx * 65536 * 655536 * 65536);
        int64_t step = (int64_t)(dx * 65536 * 655536 * 65536);
        SkFixed tmp;
        for (int i = 0; i < count; i += 4) {
<<<<<<< HEAD
            tmp = (SkFixed)(curr >> 32);
            dst[i + 0] = TILE(tmp, count);
            curr += step;
            tmp = (SkFixed)(curr >> 32);
            dst[i + 1] = TILE(tmp, count);
            curr += step;
            tmp = (SkFixed)(curr >> 32);
            dst[i + 2] = TILE(tmp, count);
            curr += step;
            tmp = (SkFixed)(curr >> 32);
            dst[i + 3] = TILE(tmp, count);
            curr += step;
        }
    }

=======
            tmp = (SkFixed) (curr >> 32); dst[i + 0] = TILE(tmp, count); curr += step;
            tmp = (SkFixed) (curr >> 32); dst[i + 1] = TILE(tmp, count); curr += step;
            tmp = (SkFixed) (curr >> 32); dst[i + 2] = TILE(tmp, count); curr += step;
            tmp = (SkFixed) (curr >> 32); dst[i + 3] = TILE(tmp, count); curr += step;
        }
    }
>>>>>>> miniblink49
private:
    typedef InterpBench INHERITED;
};

class FloatInterp : public InterpBench {
public:
<<<<<<< HEAD
    FloatInterp()
        : INHERITED("float")
    {
    }

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override
    {
        SkFixed tmp;
        for (int i = 0; i < count; i += 4) {
            tmp = SkFloatToFixed(fx);
            dst[i + 0] = TILE(tmp, count);
            fx += dx;
            tmp = SkFloatToFixed(fx);
            dst[i + 1] = TILE(tmp, count);
            fx += dx;
            tmp = SkFloatToFixed(fx);
            dst[i + 2] = TILE(tmp, count);
            fx += dx;
            tmp = SkFloatToFixed(fx);
            dst[i + 3] = TILE(tmp, count);
            fx += dx;
        }
    }

=======
    FloatInterp() : INHERITED("float") {}

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override {
        SkFixed tmp;
        for (int i = 0; i < count; i += 4) {
            tmp = SkFloatToFixed(fx); dst[i + 0] = TILE(tmp, count); fx += dx;
            tmp = SkFloatToFixed(fx); dst[i + 1] = TILE(tmp, count); fx += dx;
            tmp = SkFloatToFixed(fx); dst[i + 2] = TILE(tmp, count); fx += dx;
            tmp = SkFloatToFixed(fx); dst[i + 3] = TILE(tmp, count); fx += dx;
        }
    }
>>>>>>> miniblink49
private:
    typedef InterpBench INHERITED;
};

class DoubleInterp : public InterpBench {
public:
<<<<<<< HEAD
    DoubleInterp()
        : INHERITED("double")
    {
    }

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override
    {
=======
    DoubleInterp() : INHERITED("double") {}

protected:
    void performTest(int16_t dst[], float fx, float dx, int count) override {
>>>>>>> miniblink49
        double ffx = fx;
        double ddx = dx;
        SkFixed tmp;
        for (int i = 0; i < count; i += 4) {
<<<<<<< HEAD
            tmp = SkDoubleToFixed(ffx);
            dst[i + 0] = TILE(tmp, count);
            ffx += ddx;
            tmp = SkDoubleToFixed(ffx);
            dst[i + 1] = TILE(tmp, count);
            ffx += ddx;
            tmp = SkDoubleToFixed(ffx);
            dst[i + 2] = TILE(tmp, count);
            ffx += ddx;
            tmp = SkDoubleToFixed(ffx);
            dst[i + 3] = TILE(tmp, count);
            ffx += ddx;
        }
    }

=======
            tmp = SkDoubleToFixed(ffx); dst[i + 0] = TILE(tmp, count); ffx += ddx;
            tmp = SkDoubleToFixed(ffx); dst[i + 1] = TILE(tmp, count); ffx += ddx;
            tmp = SkDoubleToFixed(ffx); dst[i + 2] = TILE(tmp, count); ffx += ddx;
            tmp = SkDoubleToFixed(ffx); dst[i + 3] = TILE(tmp, count); ffx += ddx;
        }
    }
>>>>>>> miniblink49
private:
    typedef InterpBench INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new Fixed16D16Interp();)
DEF_BENCH(return new Fixed32D32Interp();)
DEF_BENCH(return new Fixed16D48Interp();)
DEF_BENCH(return new FloatInterp();)
DEF_BENCH(return new DoubleInterp();)
=======
DEF_BENCH( return new Fixed16D16Interp(); )
DEF_BENCH( return new Fixed32D32Interp(); )
DEF_BENCH( return new Fixed16D48Interp(); )
DEF_BENCH( return new FloatInterp(); )
DEF_BENCH( return new DoubleInterp(); )
>>>>>>> miniblink49
