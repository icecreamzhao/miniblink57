/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkChecksum.h"
#include "SkPaint.h"
#include "SkString.h"
#include "SkTemplates.h"

#include "gUniqueGlyphIDs.h"
<<<<<<< HEAD
#define gUniqueGlyphIDs_Sentinel 0xFFFF

static int count_glyphs(const uint16_t start[])
{
=======
#define gUniqueGlyphIDs_Sentinel    0xFFFF

static int count_glyphs(const uint16_t start[]) {
>>>>>>> miniblink49
    const uint16_t* curr = start;
    while (*curr != gUniqueGlyphIDs_Sentinel) {
        curr += 1;
    }
    return static_cast<int>(curr - start);
}

class FontCacheBench : public Benchmark {
public:
<<<<<<< HEAD
    FontCacheBench() { }

protected:
    const char* onGetName() override
    {
        return "fontcache";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    FontCacheBench()  {}

protected:
    const char* onGetName() override {
        return "fontcache";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;
        this->setupPaint(&paint);
        paint.setTextEncoding(SkPaint::kGlyphID_TextEncoding);

        const uint16_t* array = gUniqueGlyphIDs;
        while (*array != gUniqueGlyphIDs_Sentinel) {
            int count = count_glyphs(array);
            for (int i = 0; i < loops; ++i) {
                paint.measureText(array, count * sizeof(uint16_t));
            }
<<<<<<< HEAD
            array += count + 1; // skip the sentinel
=======
            array += count + 1;    // skip the sentinel
>>>>>>> miniblink49
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static uint32_t rotr(uint32_t value, unsigned bits)
{
=======
static uint32_t rotr(uint32_t value, unsigned bits) {
>>>>>>> miniblink49
    return (value >> bits) | (value << (32 - bits));
}

typedef uint32_t (*HasherProc)(uint32_t);

<<<<<<< HEAD
static uint32_t hasher0(uint32_t value)
{
=======
static uint32_t hasher0(uint32_t value) {
>>>>>>> miniblink49
    value = value ^ (value >> 16);
    return value ^ (value >> 8);
}

static const struct {
    const char* fName;
<<<<<<< HEAD
    HasherProc fHasher;
} gRec[] = {
    { "hasher0", hasher0 },
    { "hasher2", SkChecksum::Mix },
};

#define kMaxHashBits 12
#define kMaxHashCount (1 << kMaxHashBits)

static int count_collisions(const uint16_t array[], int count, HasherProc proc,
    unsigned hashMask)
{
=======
    HasherProc  fHasher;
} gRec[] = {
    { "hasher0",  hasher0 },
    { "hasher2",  SkChecksum::Mix },
};

#define kMaxHashBits   12
#define kMaxHashCount  (1 << kMaxHashBits)

static int count_collisions(const uint16_t array[], int count, HasherProc proc,
                            unsigned hashMask) {
>>>>>>> miniblink49
    char table[kMaxHashCount];
    sk_bzero(table, sizeof(table));

    int collisions = 0;
    for (int i = 0; i < count; ++i) {
        int index = proc(array[i]) & hashMask;
        collisions += table[index];
        table[index] = 1;
    }
    return collisions;
}

<<<<<<< HEAD
static void dump_array(const uint16_t array[], int count)
{
=======
static void dump_array(const uint16_t array[], int count) {
>>>>>>> miniblink49
    for (int i = 0; i < count; ++i) {
        SkDebugf(" %d,", array[i]);
    }
    SkDebugf("\n");
}

class FontCacheEfficiency : public Benchmark {
public:
<<<<<<< HEAD
    FontCacheEfficiency()
    {
        if (false)
            dump_array(nullptr, 0);
        if (false)
            rotr(0, 0);
    }

protected:
    const char* onGetName() override
    {
        return "fontefficiency";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    FontCacheEfficiency()  {
        if (false) dump_array(NULL, 0);
        if (false) rotr(0, 0);
    }

protected:
    const char* onGetName() override {
        return "fontefficiency";
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        static bool gDone;
        if (gDone) {
            return;
        }
        gDone = true;

        for (int hashBits = 6; hashBits <= 12; hashBits += 1) {
            int hashMask = ((1 << hashBits) - 1);
            for (int limit = 32; limit <= 1024; limit <<= 1) {
                for (size_t i = 0; i < SK_ARRAY_COUNT(gRec); ++i) {
                    int collisions = 0;
                    int glyphs = 0;
                    const uint16_t* array = gUniqueGlyphIDs;
                    while (*array != gUniqueGlyphIDs_Sentinel) {
                        int count = SkMin32(count_glyphs(array), limit);
                        collisions += count_collisions(array, count, gRec[i].fHasher, hashMask);
                        glyphs += count;
<<<<<<< HEAD
                        array += count + 1; // skip the sentinel
                    }
                    SkDebugf("hashBits [%d] limit [%d] collisions [%d / %d = %1.2g%%] using %s\n", hashBits, limit, collisions, glyphs,
                        collisions * 100.0 / glyphs, gRec[i].fName);
=======
                        array += count + 1;    // skip the sentinel
                    }
                    SkDebugf("hashBits [%d] limit [%d] collisions [%d / %d = %1.2g%%] using %s\n", hashBits, limit, collisions, glyphs,
                             collisions * 100.0 / glyphs, gRec[i].fName);
>>>>>>> miniblink49
                }
            }
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new FontCacheBench();)
=======
DEF_BENCH( return new FontCacheBench(); )
>>>>>>> miniblink49

// undefine this to run the efficiency test
//DEF_BENCH( return new FontCacheEfficiency(); )
