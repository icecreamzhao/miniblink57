/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkTemplates.h"
#include "SkUtils.h"

template <typename T, bool kInline>
class MemsetBench : public Benchmark {
public:
    explicit MemsetBench(int n)
        : fN(n)
        , fBuffer(n)
<<<<<<< HEAD
        , fName(SkStringPrintf("memset%d_%d%s", sizeof(T) * 8, n, kInline ? "_inline" : ""))
    {
    }
=======
        , fName(SkStringPrintf("memset%d_%d%s", sizeof(T)*8, n, kInline ? "_inline" : "")) {}
>>>>>>> miniblink49

    bool isSuitableFor(Backend backend) override { return backend == kNonRendering_Backend; }
    const char* onGetName() override { return fName.c_str(); }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas*) override;
=======
    void onDraw(const int loops, SkCanvas*) override;
>>>>>>> miniblink49

private:
    int fN;
    SkAutoTMalloc<T> fBuffer;
    SkString fName;
};

<<<<<<< HEAD
template <>
void MemsetBench<uint32_t, false>::onDraw(int loops, SkCanvas*)
{
    for (int i = 0; i < 1000 * loops; i++) {
=======
template <> void MemsetBench<uint32_t, false>::onDraw(const int loops, SkCanvas*) {
    for (int i = 0; i < 1000*loops; i++) {
>>>>>>> miniblink49
        sk_memset32(fBuffer.get(), 0xFACEB004, fN);
    }
}

<<<<<<< HEAD
template <>
void MemsetBench<uint16_t, false>::onDraw(int loops, SkCanvas*)
{
    for (int i = 0; i < 1000 * loops; i++) {
=======
template <> void MemsetBench<uint16_t, false>::onDraw(const int loops, SkCanvas*) {
    for (int i = 0; i < 1000*loops; i++) {
>>>>>>> miniblink49
        sk_memset16(fBuffer.get(), 0x4973, fN);
    }
}

template <typename T>
<<<<<<< HEAD
static void memsetT(T* dst, T val, int n)
{
    for (int i = 0; i < n; i++) {
        dst[i] = val;
    }
}

template <>
void MemsetBench<uint32_t, true>::onDraw(int loops, SkCanvas*)
{
    for (int i = 0; i < 1000 * loops; i++) {
=======
static void memsetT(T* dst, T val, int n) {
    for (int i = 0; i < n; i++) { dst[i] = val; }
}

template <> void MemsetBench<uint32_t, true>::onDraw(const int loops, SkCanvas*) {
    for (int i = 0; i < 1000*loops; i++) {
>>>>>>> miniblink49
        memsetT<uint32_t>(fBuffer.get(), 0xFACEB004, fN);
    }
}

<<<<<<< HEAD
template <>
void MemsetBench<uint16_t, true>::onDraw(int loops, SkCanvas*)
{
    for (int i = 0; i < 1000 * loops; i++) {
=======
template <> void MemsetBench<uint16_t, true>::onDraw(const int loops, SkCanvas*) {
    for (int i = 0; i < 1000*loops; i++) {
>>>>>>> miniblink49
        memsetT<uint16_t>(fBuffer.get(), 0x4973, fN);
    }
}

<<<<<<< HEAD
DEF_BENCH(return (new MemsetBench<uint32_t, true>(1)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(1)));
DEF_BENCH(return (new MemsetBench<uint32_t, true>(10)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(10)));
DEF_BENCH(return (new MemsetBench<uint32_t, true>(100)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(100)));
DEF_BENCH(return (new MemsetBench<uint32_t, true>(1000)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(1000)));
DEF_BENCH(return (new MemsetBench<uint32_t, true>(10000)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(10000)));
DEF_BENCH(return (new MemsetBench<uint32_t, true>(100000)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(100000)));

DEF_BENCH(return (new MemsetBench<uint16_t, true>(1)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(1)));
DEF_BENCH(return (new MemsetBench<uint16_t, true>(10)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(10)));
DEF_BENCH(return (new MemsetBench<uint16_t, true>(100)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(100)));
DEF_BENCH(return (new MemsetBench<uint16_t, true>(1000)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(1000)));
DEF_BENCH(return (new MemsetBench<uint16_t, true>(10000)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(10000)));
DEF_BENCH(return (new MemsetBench<uint16_t, true>(100000)));
=======
DEF_BENCH(return (new MemsetBench<uint32_t,  true>(1)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(1)));
DEF_BENCH(return (new MemsetBench<uint32_t,  true>(10)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(10)));
DEF_BENCH(return (new MemsetBench<uint32_t,  true>(100)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(100)));
DEF_BENCH(return (new MemsetBench<uint32_t,  true>(1000)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(1000)));
DEF_BENCH(return (new MemsetBench<uint32_t,  true>(10000)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(10000)));
DEF_BENCH(return (new MemsetBench<uint32_t,  true>(100000)));
DEF_BENCH(return (new MemsetBench<uint32_t, false>(100000)));

DEF_BENCH(return (new MemsetBench<uint16_t,  true>(1)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(1)));
DEF_BENCH(return (new MemsetBench<uint16_t,  true>(10)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(10)));
DEF_BENCH(return (new MemsetBench<uint16_t,  true>(100)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(100)));
DEF_BENCH(return (new MemsetBench<uint16_t,  true>(1000)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(1000)));
DEF_BENCH(return (new MemsetBench<uint16_t,  true>(10000)));
DEF_BENCH(return (new MemsetBench<uint16_t, false>(10000)));
DEF_BENCH(return (new MemsetBench<uint16_t,  true>(100000)));
>>>>>>> miniblink49
DEF_BENCH(return (new MemsetBench<uint16_t, false>(100000)));
