/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "Benchmark.h"
#include "SkMutex.h"
<<<<<<< HEAD
#include "SkSharedMutex.h"
#include "SkSpinlock.h"
#include "SkString.h"

template <typename Mutex>
class MutexBench : public Benchmark {
public:
    MutexBench(SkString benchPrefix)
        : fBenchName(benchPrefix += "UncontendedBenchmark")
    {
    }
    bool isSuitableFor(Backend backend) override
    {
=======

class MutexBench : public Benchmark {
public:
    bool isSuitableFor(Backend backend) override {
>>>>>>> miniblink49
        return backend == kNonRendering_Backend;
    }

protected:
<<<<<<< HEAD
    const char* onGetName() override
    {
        return fBenchName.c_str();
    }

    void onDraw(int loops, SkCanvas*) override
    {
        for (int i = 0; i < loops; i++) {
            fMu.acquire();
            fMu.release();
=======
    virtual const char* onGetName() {
        return "mutex";
    }

    virtual void onDraw(const int loops, SkCanvas*) {
        SkMutex mu;
        for (int i = 0; i < loops; i++) {
            mu.acquire();
            mu.release();
>>>>>>> miniblink49
        }
    }

private:
    typedef Benchmark INHERITED;
<<<<<<< HEAD
    SkString fBenchName;
    Mutex fMu;
};

class SharedBench : public Benchmark {
public:
    bool isSuitableFor(Backend backend) override
    {
        return backend == kNonRendering_Backend;
    }

protected:
    const char* onGetName() override
    {
        return "SkSharedMutexSharedUncontendedBenchmark";
    }

    void onDraw(int loops, SkCanvas*) override
    {
        for (int i = 0; i < loops; i++) {
            fMu.acquireShared();
            fMu.releaseShared();
        }
    }

private:
    typedef Benchmark INHERITED;
    SkSharedMutex fMu;
=======
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new MutexBench<SkSharedMutex>(SkString("SkSharedMutex"));)
DEF_BENCH(return new MutexBench<SkMutex>(SkString("SkMutex"));)
DEF_BENCH(return new MutexBench<SkSpinlock>(SkString("SkSpinlock"));)
DEF_BENCH(return new SharedBench;)
=======
DEF_BENCH( return new MutexBench(); )
>>>>>>> miniblink49
