/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkResourceCache.h"

namespace {
static void* gGlobalAddress;
class TestKey : public SkResourceCache::Key {
public:
    intptr_t fValue;

<<<<<<< HEAD
    TestKey(intptr_t value)
        : fValue(value)
    {
=======
    TestKey(intptr_t value) : fValue(value) {
>>>>>>> miniblink49
        this->init(&gGlobalAddress, 0, sizeof(fValue));
    }
};
struct TestRec : public SkResourceCache::Rec {
<<<<<<< HEAD
    TestKey fKey;
    intptr_t fValue;

    TestRec(const TestKey& key, intptr_t value)
        : fKey(key)
        , fValue(value)
    {
    }

    const Key& getKey() const override { return fKey; }
    size_t bytesUsed() const override { return sizeof(fKey) + sizeof(fValue); }
    const char* getCategory() const override { return "imagecachebench-test"; }
    SkDiscardableMemory* diagnostic_only_getDiscardable() const override { return nullptr; }

    static bool Visitor(const SkResourceCache::Rec&, void*)
    {
=======
    TestKey     fKey;
    intptr_t    fValue;

    TestRec(const TestKey& key, intptr_t value) : fKey(key), fValue(value) {}

    const Key& getKey() const override { return fKey; }
    size_t bytesUsed() const override { return sizeof(fKey) + sizeof(fValue); }

    static bool Visitor(const SkResourceCache::Rec&, void*) {
>>>>>>> miniblink49
        return true;
    }
};
}

class ImageCacheBench : public Benchmark {
    SkResourceCache fCache;

    enum {
        CACHE_COUNT = 500
    };
<<<<<<< HEAD

public:
    ImageCacheBench()
        : fCache(CACHE_COUNT * 100)
    {
    }

    void populateCache()
    {
        for (int i = 0; i < CACHE_COUNT; ++i) {
            fCache.add(new TestRec(TestKey(i), i));
=======
public:
    ImageCacheBench()  : fCache(CACHE_COUNT * 100) {}

    void populateCache() {
        for (int i = 0; i < CACHE_COUNT; ++i) {
            fCache.add(SkNEW_ARGS(TestRec, (TestKey(i), i)));
>>>>>>> miniblink49
        }
    }

protected:
<<<<<<< HEAD
    const char* onGetName() override
    {
        return "imagecache";
    }

    void onDraw(int loops, SkCanvas*) override
    {
=======
    const char* onGetName() override {
        return "imagecache";
    }

    void onDraw(const int loops, SkCanvas*) override {
>>>>>>> miniblink49
        if (fCache.getTotalBytesUsed() == 0) {
            this->populateCache();
        }

        TestKey key(-1);
        // search for a miss (-1)
        for (int i = 0; i < loops; ++i) {
<<<<<<< HEAD
            SkDEBUGCODE(bool found =) fCache.find(key, TestRec::Visitor, nullptr);
=======
            SkDEBUGCODE(bool found =) fCache.find(key, TestRec::Visitor, NULL);
>>>>>>> miniblink49
            SkASSERT(!found);
        }
    }

private:
    typedef Benchmark INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new ImageCacheBench();)
=======
DEF_BENCH( return new ImageCacheBench(); )
>>>>>>> miniblink49
