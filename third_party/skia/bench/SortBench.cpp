/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkRandom.h"
#include "SkString.h"
#include "SkTSort.h"

<<<<<<< HEAD
#include <stdlib.h>

static const int N = 1000;

static void rand_proc(int array[N])
{
=======
static const int N = 1000;

static void rand_proc(int array[N]) {
>>>>>>> miniblink49
    SkRandom rand;
    for (int i = 0; i < N; ++i) {
        array[i] = rand.nextS();
    }
}

<<<<<<< HEAD
static void randN_proc(int array[N])
{
=======
static void randN_proc(int array[N]) {
>>>>>>> miniblink49
    SkRandom rand;
    int mod = N / 10;
    for (int i = 0; i < N; ++i) {
        array[i] = rand.nextU() % mod;
    }
}

<<<<<<< HEAD
static void forward_proc(int array[N])
{
=======
static void forward_proc(int array[N]) {
>>>>>>> miniblink49
    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }
}

<<<<<<< HEAD
static void backward_proc(int array[N])
{
=======
static void backward_proc(int array[N]) {
>>>>>>> miniblink49
    for (int i = 0; i < N; ++i) {
        array[i] = -i;
    }
}

<<<<<<< HEAD
static void same_proc(int array[N])
{
=======
static void same_proc(int array[N]) {
>>>>>>> miniblink49
    for (int i = 0; i < N; ++i) {
        array[i] = N;
    }
}

typedef void (*SortProc)(int array[N]);

enum Type {
<<<<<<< HEAD
    kRand,
    kRandN,
    kFore,
    kBack,
    kSame
=======
    kRand, kRandN, kFore, kBack, kSame
>>>>>>> miniblink49
};

static const struct {
    const char* fName;
<<<<<<< HEAD
    SortProc fProc;
=======
    SortProc    fProc;
>>>>>>> miniblink49
} gRec[] = {
    { "rand", rand_proc },
    { "rand10", randN_proc },
    { "forward", forward_proc },
    { "backward", backward_proc },
    { "repeated", same_proc },
};

<<<<<<< HEAD
static void skqsort_sort(int array[N])
{
=======
static void skqsort_sort(int array[N]) {
>>>>>>> miniblink49
    // End is inclusive for SkTQSort!
    SkTQSort<int>(array, array + N - 1);
}

<<<<<<< HEAD
static void skheap_sort(int array[N])
{
=======
static void skheap_sort(int array[N]) {
>>>>>>> miniblink49
    SkTHeapSort<int>(array, N);
}

extern "C" {
<<<<<<< HEAD
static int int_compare(const void* a, const void* b)
{
    const int ai = *(const int*)a;
    const int bi = *(const int*)b;
    return ai < bi ? -1 : (ai > bi);
}
}

static void qsort_sort(int array[N])
{
=======
    static int int_compare(const void* a, const void* b) {
        const int ai = *(const int*)a;
        const int bi = *(const int*)b;
        return ai < bi ? -1 : (ai > bi);
    }
}

static void qsort_sort(int array[N]) {
>>>>>>> miniblink49
    qsort(array, N, sizeof(int), int_compare);
}

enum SortType {
<<<<<<< HEAD
    kSKQSort,
    kSKHeap,
    kQSort
=======
    kSKQSort, kSKHeap, kQSort
>>>>>>> miniblink49
};

static const struct {
    const char* fName;
<<<<<<< HEAD
    SortProc fProc;
=======
    SortProc    fProc;
>>>>>>> miniblink49
} gSorts[] = {
    { "skqsort", skqsort_sort },
    { "skheap", skheap_sort },
    { "qsort", qsort_sort },
};

class SortBench : public Benchmark {
<<<<<<< HEAD
    SkString fName;
    const Type fType;
    const SortProc fSortProc;
    SkAutoTMalloc<int> fUnsorted;

public:
    SortBench(Type t, SortType s)
        : fType(t)
        , fSortProc(gSorts[s].fProc)
    {
        fName.printf("sort_%s_%s", gSorts[s].fName, gRec[t].fName);
    }

    bool isSuitableFor(Backend backend) override
    {
=======
    SkString           fName;
    const Type         fType;
    const SortProc     fSortProc;
    SkAutoTMalloc<int> fUnsorted;

public:
    SortBench(Type t, SortType s) : fType(t), fSortProc(gSorts[s].fProc) {
        fName.printf("sort_%s_%s", gSorts[s].fName, gRec[t].fName);
    }

    bool isSuitableFor(Backend backend) override {
>>>>>>> miniblink49
        return backend == kNonRendering_Backend;
    }

protected:
<<<<<<< HEAD
    const char* onGetName() override
    {
=======
    const char* onGetName() override {
>>>>>>> miniblink49
        return fName.c_str();
    }

    // Delayed initialization only done if onDraw will be called.
<<<<<<< HEAD
    void onDelayedSetup() override
    {
=======
    void onPreDraw() override {
>>>>>>> miniblink49
        fUnsorted.reset(N);
        gRec[fType].fProc(fUnsorted.get());
    }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas*) override
    {
        SkAutoTMalloc<int> sorted(N);
        for (int i = 0; i < loops; i++) {
            memcpy(sorted.get(), fUnsorted.get(), N * sizeof(int));
=======
    void onDraw(const int loops, SkCanvas*) override {
        SkAutoTMalloc<int> sorted(N);
        for (int i = 0; i < loops; i++) {
            memcpy(sorted.get(), fUnsorted.get(), N*sizeof(int));
>>>>>>> miniblink49
            fSortProc(sorted.get());
#ifdef SK_DEBUG
            for (int j = 1; j < N; ++j) {
                SkASSERT(sorted[j - 1] <= sorted[j]);
            }
#endif
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static Benchmark* NewSkQSort(Type t)
{
    return new SortBench(t, kSKQSort);
}
static Benchmark* NewSkHeap(Type t)
{
    return new SortBench(t, kSKHeap);
}
static Benchmark* NewQSort(Type t)
{
    return new SortBench(t, kQSort);
}

DEF_BENCH(return NewSkQSort(kRand);)
DEF_BENCH(return NewSkHeap(kRand);)
DEF_BENCH(return NewQSort(kRand);)

DEF_BENCH(return NewSkQSort(kRandN);)
DEF_BENCH(return NewSkHeap(kRandN);)
DEF_BENCH(return NewQSort(kRandN);)

DEF_BENCH(return NewSkQSort(kFore);)
DEF_BENCH(return NewSkHeap(kFore);)
DEF_BENCH(return NewQSort(kFore);)

DEF_BENCH(return NewSkQSort(kBack);)
DEF_BENCH(return NewSkHeap(kBack);)
DEF_BENCH(return NewQSort(kBack);)

DEF_BENCH(return NewSkQSort(kSame);)
DEF_BENCH(return NewSkHeap(kSame);)
DEF_BENCH(return NewQSort(kSame);)
=======
static Benchmark* NewSkQSort(Type t) {
    return new SortBench(t, kSKQSort);
}
static Benchmark* NewSkHeap(Type t) {
    return new SortBench(t, kSKHeap);
}
static Benchmark* NewQSort(Type t) {
    return new SortBench(t, kQSort);
}

DEF_BENCH( return NewSkQSort(kRand); )
DEF_BENCH( return NewSkHeap(kRand); )
DEF_BENCH( return NewQSort(kRand); )

DEF_BENCH( return NewSkQSort(kRandN); )
DEF_BENCH( return NewSkHeap(kRandN); )
DEF_BENCH( return NewQSort(kRandN); )

DEF_BENCH( return NewSkQSort(kFore); )
DEF_BENCH( return NewSkHeap(kFore); )
DEF_BENCH( return NewQSort(kFore); )

DEF_BENCH( return NewSkQSort(kBack); )
DEF_BENCH( return NewSkHeap(kBack); )
DEF_BENCH( return NewQSort(kBack); )

DEF_BENCH( return NewSkQSort(kSame); )
DEF_BENCH( return NewSkHeap(kSame); )
DEF_BENCH( return NewQSort(kSame); )
>>>>>>> miniblink49
