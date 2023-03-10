/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkCachedData.h"
#include "SkResourceCache.h"
#include "SkYUVPlanesCache.h"
#include "Test.h"

enum LockedState {
    kUnlocked,
    kLocked,
};

enum CachedState {
    kNotInCache,
    kInCache,
};

static void check_data(skiatest::Reporter* reporter, SkCachedData* data,
    int refcnt, CachedState cacheState, LockedState lockedState)
{
    REPORTER_ASSERT(reporter, data->testing_only_getRefCnt() == refcnt);
    REPORTER_ASSERT(reporter, data->testing_only_isInCache() == (kInCache == cacheState));
    bool isLocked = (data->data() != nullptr);
    REPORTER_ASSERT(reporter, isLocked == (lockedState == kLocked));
}

DEF_TEST(YUVPlanesCache, reporter)
{
    SkResourceCache cache(1024);

    SkYUVPlanesCache::Info yuvInfo;
    for (int i = 0; i < 3; i++) {
        yuvInfo.fSizeInfo.fSizes[i].fWidth = 20 * i;
        yuvInfo.fSizeInfo.fSizes[i].fHeight = 10 * i;
        yuvInfo.fSizeInfo.fWidthBytes[i] = 80 * i;
    }
    yuvInfo.fColorSpace = kRec601_SkYUVColorSpace;

    const uint32_t genID = 12345678;

    SkCachedData* data = SkYUVPlanesCache::FindAndRef(genID, &yuvInfo, &cache);
    REPORTER_ASSERT(reporter, nullptr == data);

    size_t size = 256;
    data = cache.newCachedData(size);
    memset(data->writable_data(), 0xff, size);

    SkYUVPlanesCache::Add(genID, data, &yuvInfo, &cache);
    check_data(reporter, data, 2, kInCache, kLocked);

    data->unref();
    check_data(reporter, data, 1, kInCache, kUnlocked);

    SkYUVPlanesCache::Info yuvInfoRead;
    data = SkYUVPlanesCache::FindAndRef(genID, &yuvInfoRead, &cache);

    REPORTER_ASSERT(reporter, data);
    REPORTER_ASSERT(reporter, data->size() == size);
    for (int i = 0; i < 3; ++i) {
        REPORTER_ASSERT(reporter, yuvInfo.fSizeInfo.fSizes[i].fWidth == yuvInfoRead.fSizeInfo.fSizes[i].fWidth);
        REPORTER_ASSERT(reporter, yuvInfo.fSizeInfo.fSizes[i].fHeight == yuvInfoRead.fSizeInfo.fSizes[i].fHeight);
        REPORTER_ASSERT(reporter, yuvInfo.fSizeInfo.fWidthBytes[i] == yuvInfoRead.fSizeInfo.fWidthBytes[i]);
    }
    REPORTER_ASSERT(reporter, yuvInfo.fColorSpace == yuvInfoRead.fColorSpace);

    check_data(reporter, data, 2, kInCache, kLocked);

    cache.purgeAll();
    check_data(reporter, data, 1, kNotInCache, kLocked);
    data->unref();
}
