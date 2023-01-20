/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTypes.h"

=======
>>>>>>> miniblink49
// This tests a Gr class
#if SK_SUPPORT_GPU

#include "Benchmark.h"
#include "GrMemoryPool.h"
#include "SkRandom.h"
#include "SkTDArray.h"
#include "SkTemplates.h"

// change this to 0 to compare GrMemoryPool to default new / delete
<<<<<<< HEAD
#define OVERRIDE_NEW 1
=======
#define OVERRIDE_NEW    1
>>>>>>> miniblink49

struct A {
    int gStuff[10];
#if OVERRIDE_NEW
<<<<<<< HEAD
    void* operator new(size_t size)
    {
        return gBenchPool.allocate(size);
    }
    void operator delete(void* mem)
    {
        if (mem) {
            return gBenchPool.release(mem);
        }
    }
=======
    void* operator new (size_t size) { return gBenchPool.allocate(size); }
    void operator delete (void* mem) { if (mem) { return gBenchPool.release(mem); } }
>>>>>>> miniblink49
#endif
    static GrMemoryPool gBenchPool;
};
GrMemoryPool A::gBenchPool(10 * (1 << 10), 10 * (1 << 10));

/**
 * This benchmark creates and deletes objects in stack order
 */
class GrMemoryPoolBenchStack : public Benchmark {
public:
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
        return "grmemorypool_stack";
    }

    void onDraw(int loops, SkCanvas*) override
    {
=======
    virtual const char* onGetName() {
        return "grmemorypool_stack";
    }

    virtual void onDraw(const int loops, SkCanvas*) {
>>>>>>> miniblink49
        SkRandom r;
        enum {
            kMaxObjects = 4 * (1 << 10),
        };
        A* objects[kMaxObjects];

<<<<<<< HEAD
        // We delete if a random number [-1, 1] is < the thresh. Otherwise,
        // we allocate. We start allocate-biased and ping-pong to delete-biased
        SkScalar delThresh = -SK_ScalarHalf;
=======
        // We delete if a random [-1, 1] fixed pt is < the thresh. Otherwise,
        // we allocate. We start allocate-biased and ping-pong to delete-biased
        SkFixed delThresh = -SK_FixedHalf;
>>>>>>> miniblink49
        const int kSwitchThreshPeriod = loops / (2 * kMaxObjects);
        int s = 0;

        int count = 0;
        for (int i = 0; i < loops; i++, ++s) {
            if (kSwitchThreshPeriod == s) {
                delThresh = -delThresh;
                s = 0;
            }
<<<<<<< HEAD
            SkScalar del = r.nextSScalar1();
            if (count && (kMaxObjects == count || del < delThresh)) {
                delete objects[count - 1];
=======
            SkFixed del = r.nextSFixed1();
            if (count &&
                (kMaxObjects == count || del < delThresh)) {
                delete objects[count-1];
>>>>>>> miniblink49
                --count;
            } else {
                objects[count] = new A;
                ++count;
            }
        }
        for (int i = 0; i < count; ++i) {
            delete objects[i];
        }
    }

private:
    typedef Benchmark INHERITED;
};

struct B {
    int gStuff[10];
#if OVERRIDE_NEW
<<<<<<< HEAD
    void* operator new(size_t size)
    {
        return gBenchPool.allocate(size);
    }
    void operator delete(void* mem)
    {
        if (mem) {
            return gBenchPool.release(mem);
        }
    }
=======
    void* operator new (size_t size) { return gBenchPool.allocate(size); }
    void operator delete (void* mem) { if (mem) { return gBenchPool.release(mem); } }
>>>>>>> miniblink49
#endif
    static GrMemoryPool gBenchPool;
};
GrMemoryPool B::gBenchPool(10 * (1 << 10), 10 * (1 << 10));

/**
 * This benchmark creates objects and deletes them in random order
 */
class GrMemoryPoolBenchRandom : public Benchmark {
public:
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
        return "grmemorypool_random";
    }

    void onDraw(int loops, SkCanvas*) override
    {
=======
    virtual const char* onGetName() {
        return "grmemorypool_random";
    }

    virtual void onDraw(const int loops, SkCanvas*) {
>>>>>>> miniblink49
        SkRandom r;
        enum {
            kMaxObjects = 4 * (1 << 10),
        };
        SkAutoTDelete<B> objects[kMaxObjects];

        for (int i = 0; i < loops; i++) {
<<<<<<< HEAD
            uint32_t idx = r.nextRangeU(0, kMaxObjects - 1);
            if (nullptr == objects[idx].get()) {
                objects[idx].reset(new B);
            } else {
                objects[idx].reset();
=======
            uint32_t idx = r.nextRangeU(0, kMaxObjects-1);
            if (NULL == objects[idx].get()) {
                objects[idx].reset(new B);
            } else {
                objects[idx].free();
>>>>>>> miniblink49
            }
        }
    }

private:
    typedef Benchmark INHERITED;
};

struct C {
    int gStuff[10];
#if OVERRIDE_NEW
<<<<<<< HEAD
    void* operator new(size_t size)
    {
        return gBenchPool.allocate(size);
    }
    void operator delete(void* mem)
    {
        if (mem) {
            return gBenchPool.release(mem);
        }
    }
=======
    void* operator new (size_t size) { return gBenchPool.allocate(size); }
    void operator delete (void* mem) { if (mem) { return gBenchPool.release(mem); } }
>>>>>>> miniblink49
#endif
    static GrMemoryPool gBenchPool;
};
GrMemoryPool C::gBenchPool(10 * (1 << 10), 10 * (1 << 10));

/**
 * This benchmark creates objects and deletes them in queue order
 */
class GrMemoryPoolBenchQueue : public Benchmark {
    enum {
        M = 4 * (1 << 10),
    };
<<<<<<< HEAD

public:
    bool isSuitableFor(Backend backend) override
    {
=======
public:
    bool isSuitableFor(Backend backend) override {
>>>>>>> miniblink49
        return backend == kNonRendering_Backend;
    }

protected:
<<<<<<< HEAD
    const char* onGetName() override
    {
        return "grmemorypool_queue";
    }

    void onDraw(int loops, SkCanvas*) override
    {
        SkRandom r;
        C* objects[M];
        for (int i = 0; i < loops; i++) {
            uint32_t count = r.nextRangeU(0, M - 1);
=======
    virtual const char* onGetName() {
        return "grmemorypool_queue";
    }

    virtual void onDraw(const int loops, SkCanvas*) {
        SkRandom r;
        C* objects[M];
        for (int i = 0; i < loops; i++) {
            uint32_t count = r.nextRangeU(0, M-1);
>>>>>>> miniblink49
            for (uint32_t i = 0; i < count; i++) {
                objects[i] = new C;
            }
            for (uint32_t i = 0; i < count; i++) {
                delete objects[i];
            }
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new GrMemoryPoolBenchStack();)
DEF_BENCH(return new GrMemoryPoolBenchRandom();)
DEF_BENCH(return new GrMemoryPoolBenchQueue();)
=======
DEF_BENCH( return new GrMemoryPoolBenchStack(); )
DEF_BENCH( return new GrMemoryPoolBenchRandom(); )
DEF_BENCH( return new GrMemoryPoolBenchQueue(); )
>>>>>>> miniblink49

#endif
