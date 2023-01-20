/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef Benchmark_DEFINED
#define Benchmark_DEFINED

#include "SkPoint.h"
#include "SkRefCnt.h"
#include "SkString.h"
#include "SkTRegistry.h"

#define DEF_BENCH3(code, N) \
    static BenchRegistry gBench##N([](void*) -> Benchmark* { code; });
#define DEF_BENCH2(code, N) DEF_BENCH3(code, N)
#define DEF_BENCH(code) DEF_BENCH2(code, __COUNTER__)

/*
 *  With the above macros, you can register benches as follows (at the bottom
 *  of your .cpp)
 *
 *  DEF_BENCH(return new MyBenchmark(...))
 *  DEF_BENCH(return new MyBenchmark(...))
 *  DEF_BENCH(return new MyBenchmark(...))
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
class SkCanvas;
class SkPaint;

class SkTriState {
public:
    enum State {
        kDefault,
        kTrue,
        kFalse
    };
    static const char* Name[];
};

class Benchmark : public SkRefCnt {
public:
    Benchmark();

    const char* getName();
    const char* getUniqueName();
    SkIPoint getSize();

    enum Backend {
        kNonRendering_Backend,
        kRaster_Backend,
        kGPU_Backend,
        kPDF_Backend,
        kHWUI_Backend,
    };

    // Call to determine whether the benchmark is intended for
    // the rendering mode.
<<<<<<< HEAD
    virtual bool isSuitableFor(Backend backend)
    {
        return backend != kNonRendering_Backend;
    }

    virtual int calculateLoops(int defaultLoops) const
    {
=======
    virtual bool isSuitableFor(Backend backend) {
        return backend != kNonRendering_Backend;
    }

    virtual int calculateLoops(int defaultLoops) const {
>>>>>>> miniblink49
        return defaultLoops;
    }

    // Call before draw, allows the benchmark to do setup work outside of the
    // timer. When a benchmark is repeatedly drawn, this should be called once
    // before the initial draw.
<<<<<<< HEAD
    void delayedSetup();
=======
    void preDraw();
>>>>>>> miniblink49

    // Called once before and after a series of draw calls to a single canvas.
    // The setup/break down in these calls is not timed.
    void perCanvasPreDraw(SkCanvas*);
    void perCanvasPostDraw(SkCanvas*);

<<<<<<< HEAD
    // Called just before and after each call to draw().  Not timed.
    void preDraw(SkCanvas*);
    void postDraw(SkCanvas*);

    // Bench framework can tune loops to be large enough for stable timing.
    void draw(int loops, SkCanvas*);

    void setForceAlpha(int alpha)
    {
        fForceAlpha = alpha;
    }

    void setDither(SkTriState::State state)
    {
=======
    // Bench framework can tune loops to be large enough for stable timing.
    void draw(const int loops, SkCanvas*);

    void setForceAlpha(int alpha) {
        fForceAlpha = alpha;
    }

    void setDither(SkTriState::State state) {
>>>>>>> miniblink49
        fDither = state;
    }

    /** Assign masks for paint-flags. These will be applied when setupPaint()
     *  is called.
     *
     *  Performs the following on the paint:
     *      uint32_t flags = paint.getFlags();
     *      flags &= ~clearMask;
     *      flags |= orMask;
     *      paint.setFlags(flags);
     */
<<<<<<< HEAD
    void setPaintMasks(uint32_t orMask, uint32_t clearMask)
    {
=======
    void setPaintMasks(uint32_t orMask, uint32_t clearMask) {
>>>>>>> miniblink49
        fOrMask = orMask;
        fClearMask = clearMask;
    }

    /*
     * Benches which support running in a visual mode can advertise this functionality
     */
    virtual bool isVisual() { return false; }

<<<<<<< HEAD
    /*
     * VisualBench frequently resets the canvas.  As a result we need to bulk call all of the hooks
     */
    void preTimingHooks(SkCanvas* canvas)
    {
        this->perCanvasPreDraw(canvas);
        this->preDraw(canvas);
    }

    void postTimingHooks(SkCanvas* canvas)
    {
        this->postDraw(canvas);
        this->perCanvasPostDraw(canvas);
    }

    virtual void getGpuStats(SkCanvas*, SkTArray<SkString>* keys, SkTArray<double>* values) { }

=======
>>>>>>> miniblink49
protected:
    virtual void setupPaint(SkPaint* paint);

    virtual const char* onGetName() = 0;
    virtual const char* onGetUniqueName() { return this->onGetName(); }
<<<<<<< HEAD
    virtual void onDelayedSetup() { }
    virtual void onPerCanvasPreDraw(SkCanvas*) { }
    virtual void onPerCanvasPostDraw(SkCanvas*) { }
    virtual void onPreDraw(SkCanvas*) { }
    virtual void onPostDraw(SkCanvas*) { }
    // Each bench should do its main work in a loop like this:
    //   for (int i = 0; i < loops; i++) { <work here> }
    virtual void onDraw(int loops, SkCanvas*) = 0;
=======
    virtual void onPreDraw() {}
    virtual void onPerCanvasPreDraw(SkCanvas*) {}
    virtual void onPerCanvasPostDraw(SkCanvas*) {}
    // Each bench should do its main work in a loop like this:
    //   for (int i = 0; i < loops; i++) { <work here> }
    virtual void onDraw(const int loops, SkCanvas*) = 0;
>>>>>>> miniblink49

    virtual SkIPoint onGetSize();

private:
<<<<<<< HEAD
    int fForceAlpha;
    SkTriState::State fDither;
    uint32_t fOrMask, fClearMask;
=======
    int     fForceAlpha;
    SkTriState::State  fDither;
    uint32_t    fOrMask, fClearMask;
>>>>>>> miniblink49

    typedef SkRefCnt INHERITED;
};

<<<<<<< HEAD
typedef SkTRegistry<Benchmark* (*)(void*)> BenchRegistry;
=======
typedef SkTRegistry<Benchmark*(*)(void*)> BenchRegistry;
>>>>>>> miniblink49

#endif
