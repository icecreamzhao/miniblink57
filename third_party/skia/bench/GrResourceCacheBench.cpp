<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"

#if SK_SUPPORT_GPU

<<<<<<< HEAD
#include "GrContext.h"
#include "GrGpu.h"
#include "GrGpuResource.h"
#include "GrGpuResourcePriv.h"
=======
#include "GrGpuResource.h"
#include "GrGpuResourcePriv.h"
#include "GrContext.h"
#include "GrGpu.h"
>>>>>>> miniblink49
#include "GrResourceCache.h"
#include "SkCanvas.h"

enum {
    CACHE_SIZE_COUNT = 4096,
};

class BenchResource : public GrGpuResource {
public:
<<<<<<< HEAD
    BenchResource(GrGpu* gpu)
        : INHERITED(gpu)
    {
        this->registerWithCache(SkBudgeted::kYes);
    }

    static void ComputeKey(int i, int keyData32Count, GrUniqueKey* key)
    {
=======
    BenchResource (GrGpu* gpu)
        : INHERITED(gpu, kCached_LifeCycle) {
        this->registerWithCache();
    }

    static void ComputeKey(int i, int keyData32Count, GrUniqueKey* key) {
>>>>>>> miniblink49
        static GrUniqueKey::Domain kDomain = GrUniqueKey::GenerateDomain();
        GrUniqueKey::Builder builder(key, kDomain, keyData32Count);
        for (int j = 0; j < keyData32Count; ++j) {
            builder[j] = i + j;
        }
    }

private:
    size_t onGpuMemorySize() const override { return 100; }
    typedef GrGpuResource INHERITED;
};

<<<<<<< HEAD
static void populate_cache(GrGpu* gpu, int resourceCount, int keyData32Count)
{
    for (int i = 0; i < resourceCount; ++i) {
        GrUniqueKey key;
        BenchResource::ComputeKey(i, keyData32Count, &key);
        GrGpuResource* resource = new BenchResource(gpu);
=======
static void populate_cache(GrGpu* gpu, int resourceCount, int keyData32Count) {
    for (int i = 0; i < resourceCount; ++i) {
        GrUniqueKey key;
        BenchResource::ComputeKey(i, keyData32Count, &key);
        GrGpuResource* resource = SkNEW_ARGS(BenchResource, (gpu));
>>>>>>> miniblink49
        resource->resourcePriv().setUniqueKey(key);
        resource->unref();
    }
}

class GrResourceCacheBenchAdd : public Benchmark {
public:
    GrResourceCacheBenchAdd(int keyData32Count)
        : fFullName("grresourcecache_add")
<<<<<<< HEAD
        , fKeyData32Count(keyData32Count)
    {
=======
        , fKeyData32Count(keyData32Count) {
>>>>>>> miniblink49
        if (keyData32Count > 1) {
            fFullName.appendf("_%d", fKeyData32Count);
        }
    }

<<<<<<< HEAD
    bool isSuitableFor(Backend backend) override
    {
        return backend == kNonRendering_Backend;
    }

protected:
    const char* onGetName() override
    {
        return fFullName.c_str();
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
        SkAutoTUnref<GrContext> context(GrContext::CreateMockContext());
        if (nullptr == context) {
=======
    bool isSuitableFor(Backend backend) override {
        return backend == kNonRendering_Backend;
    }
protected:
    const char* onGetName() override {
        return fFullName.c_str();
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
        SkAutoTUnref<GrContext> context(GrContext::CreateMockContext());
        if (NULL == context) {
>>>>>>> miniblink49
            return;
        }
        // Set the cache budget to be very large so no purging occurs.
        context->setResourceCacheLimits(CACHE_SIZE_COUNT, 1 << 30);

        GrResourceCache* cache = context->getResourceCache();

        // Make sure the cache is empty.
        cache->purgeAllUnlocked();
        SkASSERT(0 == cache->getResourceCount() && 0 == cache->getResourceBytes());

        GrGpu* gpu = context->getGpu();

        for (int i = 0; i < loops; ++i) {
            populate_cache(gpu, CACHE_SIZE_COUNT, fKeyData32Count);
            SkASSERT(CACHE_SIZE_COUNT == cache->getResourceCount());
        }
    }

private:
    SkString fFullName;
    int fKeyData32Count;
    typedef Benchmark INHERITED;
};

class GrResourceCacheBenchFind : public Benchmark {
public:
    GrResourceCacheBenchFind(int keyData32Count)
        : fFullName("grresourcecache_find")
<<<<<<< HEAD
        , fKeyData32Count(keyData32Count)
    {
=======
        , fKeyData32Count(keyData32Count) {
>>>>>>> miniblink49
        if (keyData32Count > 1) {
            fFullName.appendf("_%d", fKeyData32Count);
        }
    }

<<<<<<< HEAD
    bool isSuitableFor(Backend backend) override
    {
        return backend == kNonRendering_Backend;
    }

protected:
    const char* onGetName() override
    {
        return fFullName.c_str();
    }

    void onDelayedSetup() override
    {
=======
    bool isSuitableFor(Backend backend) override {
        return backend == kNonRendering_Backend;
    }
protected:
    const char* onGetName() override {
        return fFullName.c_str();
    }

    void onPreDraw() override {
>>>>>>> miniblink49
        fContext.reset(GrContext::CreateMockContext());
        if (!fContext) {
            return;
        }
        // Set the cache budget to be very large so no purging occurs.
        fContext->setResourceCacheLimits(CACHE_SIZE_COUNT, 1 << 30);

        GrResourceCache* cache = fContext->getResourceCache();

        // Make sure the cache is empty.
        cache->purgeAllUnlocked();
        SkASSERT(0 == cache->getResourceCount() && 0 == cache->getResourceBytes());

        GrGpu* gpu = fContext->getGpu();

        populate_cache(gpu, CACHE_SIZE_COUNT, fKeyData32Count);
    }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        if (!fContext) {
            return;
        }
        GrResourceCache* cache = fContext->getResourceCache();
        SkASSERT(CACHE_SIZE_COUNT == cache->getResourceCount());
        for (int i = 0; i < loops; ++i) {
            for (int k = 0; k < CACHE_SIZE_COUNT; ++k) {
                GrUniqueKey key;
                BenchResource::ComputeKey(k, fKeyData32Count, &key);
                SkAutoTUnref<GrGpuResource> resource(cache->findAndRefUniqueResource(key));
                SkASSERT(resource);
            }
        }
    }

private:
    SkAutoTUnref<GrContext> fContext;
    SkString fFullName;
    int fKeyData32Count;
    typedef Benchmark INHERITED;
};

<<<<<<< HEAD
DEF_BENCH(return new GrResourceCacheBenchAdd(1);)
#ifdef SK_RELEASE
// Only on release because on debug the SkTDynamicHash validation is too slow.
DEF_BENCH(return new GrResourceCacheBenchAdd(2);)
DEF_BENCH(return new GrResourceCacheBenchAdd(3);)
DEF_BENCH(return new GrResourceCacheBenchAdd(4);)
DEF_BENCH(return new GrResourceCacheBenchAdd(5);)
DEF_BENCH(return new GrResourceCacheBenchAdd(10);)
DEF_BENCH(return new GrResourceCacheBenchAdd(25);)
DEF_BENCH(return new GrResourceCacheBenchAdd(54);)
DEF_BENCH(return new GrResourceCacheBenchAdd(55);)
DEF_BENCH(return new GrResourceCacheBenchAdd(56);)
#endif

DEF_BENCH(return new GrResourceCacheBenchFind(1);)
#ifdef SK_RELEASE
DEF_BENCH(return new GrResourceCacheBenchFind(2);)
DEF_BENCH(return new GrResourceCacheBenchFind(3);)
DEF_BENCH(return new GrResourceCacheBenchFind(4);)
DEF_BENCH(return new GrResourceCacheBenchFind(5);)
DEF_BENCH(return new GrResourceCacheBenchFind(10);)
DEF_BENCH(return new GrResourceCacheBenchFind(25);)
DEF_BENCH(return new GrResourceCacheBenchFind(54);)
DEF_BENCH(return new GrResourceCacheBenchFind(55);)
DEF_BENCH(return new GrResourceCacheBenchFind(56);)
=======
DEF_BENCH( return new GrResourceCacheBenchAdd(1); )
#ifdef SK_RELEASE
// Only on release because on debug the SkTDynamicHash validation is too slow.
DEF_BENCH( return new GrResourceCacheBenchAdd(2); )
DEF_BENCH( return new GrResourceCacheBenchAdd(3); )
DEF_BENCH( return new GrResourceCacheBenchAdd(4); )
DEF_BENCH( return new GrResourceCacheBenchAdd(5); )
DEF_BENCH( return new GrResourceCacheBenchAdd(10); )
DEF_BENCH( return new GrResourceCacheBenchAdd(25); )
DEF_BENCH( return new GrResourceCacheBenchAdd(54); )
DEF_BENCH( return new GrResourceCacheBenchAdd(55); )
DEF_BENCH( return new GrResourceCacheBenchAdd(56); )
#endif

DEF_BENCH( return new GrResourceCacheBenchFind(1); )
#ifdef SK_RELEASE
DEF_BENCH( return new GrResourceCacheBenchFind(2); )
DEF_BENCH( return new GrResourceCacheBenchFind(3); )
DEF_BENCH( return new GrResourceCacheBenchFind(4); )
DEF_BENCH( return new GrResourceCacheBenchFind(5); )
DEF_BENCH( return new GrResourceCacheBenchFind(10); )
DEF_BENCH( return new GrResourceCacheBenchFind(25); )
DEF_BENCH( return new GrResourceCacheBenchFind(54); )
DEF_BENCH( return new GrResourceCacheBenchFind(55); )
DEF_BENCH( return new GrResourceCacheBenchFind(56); )
>>>>>>> miniblink49
#endif

#endif
