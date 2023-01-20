<<<<<<< HEAD
/*
=======
 /*
>>>>>>> miniblink49
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkDiscardableMemory.h"
#include "SkResourceCache.h"
#include "Test.h"

namespace {
static void* gGlobalAddress;
struct TestingKey : public SkResourceCache::Key {
<<<<<<< HEAD
    intptr_t fValue;

    TestingKey(intptr_t value, uint64_t sharedID = 0)
        : fValue(value)
    {
=======
    intptr_t    fValue;

    TestingKey(intptr_t value, uint64_t sharedID = 0) : fValue(value) {
>>>>>>> miniblink49
        this->init(&gGlobalAddress, sharedID, sizeof(fValue));
    }
};
struct TestingRec : public SkResourceCache::Rec {
<<<<<<< HEAD
    TestingRec(const TestingKey& key, uint32_t value)
        : fKey(key)
        , fValue(value)
    {
    }

    TestingKey fKey;
    intptr_t fValue;

    const Key& getKey() const override { return fKey; }
    size_t bytesUsed() const override { return sizeof(fKey) + sizeof(fValue); }
    const char* getCategory() const override { return "test_cache"; }
    SkDiscardableMemory* diagnostic_only_getDiscardable() const override { return nullptr; }

    static bool Visitor(const SkResourceCache::Rec& baseRec, void* context)
    {
        const TestingRec& rec = static_cast<const TestingRec&>(baseRec);
        intptr_t* result = (intptr_t*)context;

=======
    TestingRec(const TestingKey& key, uint32_t value) : fKey(key), fValue(value) {}

    TestingKey  fKey;
    intptr_t    fValue;

    const Key& getKey() const override { return fKey; }
    size_t bytesUsed() const override { return sizeof(fKey) + sizeof(fValue); }

    static bool Visitor(const SkResourceCache::Rec& baseRec, void* context) {
        const TestingRec& rec = static_cast<const TestingRec&>(baseRec);
        intptr_t* result = (intptr_t*)context;
        
>>>>>>> miniblink49
        *result = rec.fValue;
        return true;
    }
};
}

static const int COUNT = 10;
static const int DIM = 256;

<<<<<<< HEAD
static void test_cache(skiatest::Reporter* reporter, SkResourceCache& cache, bool testPurge)
{
=======
static void test_cache(skiatest::Reporter* reporter, SkResourceCache& cache, bool testPurge) {
>>>>>>> miniblink49
    for (int i = 0; i < COUNT; ++i) {
        TestingKey key(i);
        intptr_t value = -1;

        REPORTER_ASSERT(reporter, !cache.find(key, TestingRec::Visitor, &value));
        REPORTER_ASSERT(reporter, -1 == value);

<<<<<<< HEAD
        cache.add(new TestingRec(key, i));
=======
        cache.add(SkNEW_ARGS(TestingRec, (key, i)));
>>>>>>> miniblink49

        REPORTER_ASSERT(reporter, cache.find(key, TestingRec::Visitor, &value));
        REPORTER_ASSERT(reporter, i == value);
    }

    if (testPurge) {
        // stress test, should trigger purges
        for (int i = 0; i < COUNT * 100; ++i) {
            TestingKey key(i);
<<<<<<< HEAD
            cache.add(new TestingRec(key, i));
=======
            cache.add(SkNEW_ARGS(TestingRec, (key, i)));
>>>>>>> miniblink49
        }
    }

    // test the originals after all that purging
    for (int i = 0; i < COUNT; ++i) {
        intptr_t value;
        (void)cache.find(TestingKey(i), TestingRec::Visitor, &value);
    }

    cache.setTotalByteLimit(0);
}

<<<<<<< HEAD
static void test_cache_purge_shared_id(skiatest::Reporter* reporter, SkResourceCache& cache)
{
    for (int i = 0; i < COUNT; ++i) {
        TestingKey key(i, i & 1); // every other key will have a 1 for its sharedID
        cache.add(new TestingRec(key, i));
=======
static void test_cache_purge_shared_id(skiatest::Reporter* reporter, SkResourceCache& cache) {
    for (int i = 0; i < COUNT; ++i) {
        TestingKey key(i, i & 1);   // every other key will have a 1 for its sharedID        
        cache.add(SkNEW_ARGS(TestingRec, (key, i)));
>>>>>>> miniblink49
    }

    // Ensure that everyone is present
    for (int i = 0; i < COUNT; ++i) {
<<<<<<< HEAD
        TestingKey key(i, i & 1); // every other key will have a 1 for its sharedID
=======
        TestingKey key(i, i & 1);   // every other key will have a 1 for its sharedID
>>>>>>> miniblink49
        intptr_t value = -1;

        REPORTER_ASSERT(reporter, cache.find(key, TestingRec::Visitor, &value));
        REPORTER_ASSERT(reporter, value == i);
    }

    // Now purge the ones that had a non-zero sharedID (the odd-indexed ones)
    cache.purgeSharedID(1);

    // Ensure that only the even ones are still present
    for (int i = 0; i < COUNT; ++i) {
<<<<<<< HEAD
        TestingKey key(i, i & 1); // every other key will have a 1 for its sharedID
=======
        TestingKey key(i, i & 1);   // every other key will have a 1 for its sharedID
>>>>>>> miniblink49
        intptr_t value = -1;

        if (i & 1) {
            REPORTER_ASSERT(reporter, !cache.find(key, TestingRec::Visitor, &value));
        } else {
            REPORTER_ASSERT(reporter, cache.find(key, TestingRec::Visitor, &value));
            REPORTER_ASSERT(reporter, value == i);
        }
    }
}

#include "SkDiscardableMemoryPool.h"

static SkDiscardableMemoryPool* gPool;
<<<<<<< HEAD
static SkDiscardableMemory* pool_factory(size_t bytes)
{
=======
static SkDiscardableMemory* pool_factory(size_t bytes) {
>>>>>>> miniblink49
    SkASSERT(gPool);
    return gPool->create(bytes);
}

<<<<<<< HEAD
DEF_TEST(ImageCache, reporter)
{
    static const size_t defLimit = DIM * DIM * 4 * COUNT + 1024; // 1K slop
=======
DEF_TEST(ImageCache, reporter) {
    static const size_t defLimit = DIM * DIM * 4 * COUNT + 1024;    // 1K slop
>>>>>>> miniblink49

    {
        SkResourceCache cache(defLimit);
        test_cache(reporter, cache, true);
    }
    {
        SkAutoTUnref<SkDiscardableMemoryPool> pool(
<<<<<<< HEAD
            SkDiscardableMemoryPool::Create(defLimit, nullptr));
=======
                SkDiscardableMemoryPool::Create(defLimit, NULL));
>>>>>>> miniblink49
        gPool = pool.get();
        SkResourceCache cache(pool_factory);
        test_cache(reporter, cache, true);
    }
    {
        SkResourceCache cache(SkDiscardableMemory::Create);
        test_cache(reporter, cache, false);
    }
    {
        SkResourceCache cache(defLimit);
        test_cache_purge_shared_id(reporter, cache);
    }
}

<<<<<<< HEAD
DEF_TEST(ImageCache_doubleAdd, r)
{
=======
DEF_TEST(ImageCache_doubleAdd, r) {
>>>>>>> miniblink49
    // Adding the same key twice should be safe.
    SkResourceCache cache(4096);

    TestingKey key(1);

<<<<<<< HEAD
    cache.add(new TestingRec(key, 2));
    cache.add(new TestingRec(key, 3));
=======
    cache.add(SkNEW_ARGS(TestingRec, (key, 2)));
    cache.add(SkNEW_ARGS(TestingRec, (key, 3)));
>>>>>>> miniblink49

    // Lookup can return either value.
    intptr_t value = -1;
    REPORTER_ASSERT(r, cache.find(key, TestingRec::Visitor, &value));
    REPORTER_ASSERT(r, 2 == value || 3 == value);
}
