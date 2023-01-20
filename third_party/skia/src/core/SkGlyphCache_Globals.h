/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkGlyphCache_Globals_DEFINED
#define SkGlyphCache_Globals_DEFINED

#include "SkGlyphCache.h"
#include "SkMutex.h"
#include "SkSpinlock.h"
#include "SkTLS.h"

#ifndef SK_DEFAULT_FONT_CACHE_COUNT_LIMIT
<<<<<<< HEAD
#define SK_DEFAULT_FONT_CACHE_COUNT_LIMIT 2048
#endif

#ifndef SK_DEFAULT_FONT_CACHE_LIMIT
#define SK_DEFAULT_FONT_CACHE_LIMIT (2 * 1024 * 1024)
=======
    #define SK_DEFAULT_FONT_CACHE_COUNT_LIMIT   2048
#endif

#ifndef SK_DEFAULT_FONT_CACHE_LIMIT
    #define SK_DEFAULT_FONT_CACHE_LIMIT     (2 * 1024 * 1024)
>>>>>>> miniblink49
#endif

///////////////////////////////////////////////////////////////////////////////

class SkGlyphCache_Globals {
public:
<<<<<<< HEAD
    SkGlyphCache_Globals()
    {
        fHead = nullptr;
=======
    SkGlyphCache_Globals() {
        fHead = NULL;
>>>>>>> miniblink49
        fTotalMemoryUsed = 0;
        fCacheSizeLimit = SK_DEFAULT_FONT_CACHE_LIMIT;
        fCacheCount = 0;
        fCacheCountLimit = SK_DEFAULT_FONT_CACHE_COUNT_LIMIT;
    }

<<<<<<< HEAD
    ~SkGlyphCache_Globals()
    {
        SkGlyphCache* cache = fHead;
        while (cache) {
            SkGlyphCache* next = cache->fNext;
            delete cache;
=======
    ~SkGlyphCache_Globals() {
        SkGlyphCache* cache = fHead;
        while (cache) {
            SkGlyphCache* next = cache->fNext;
            SkDELETE(cache);
>>>>>>> miniblink49
            cache = next;
        }
    }

<<<<<<< HEAD
    mutable SkSpinlock fLock;
=======
    SkSpinlock     fLock;
>>>>>>> miniblink49

    SkGlyphCache* internalGetHead() const { return fHead; }
    SkGlyphCache* internalGetTail() const;

<<<<<<< HEAD
    size_t getTotalMemoryUsed() const;
    int getCacheCountUsed() const;
=======
    size_t getTotalMemoryUsed() const { return fTotalMemoryUsed; }
    int getCacheCountUsed() const { return fCacheCount; }
>>>>>>> miniblink49

#ifdef SK_DEBUG
    void validate() const;
#else
<<<<<<< HEAD
    void validate() const
    {
    }
#endif

    int getCacheCountLimit() const;
    int setCacheCountLimit(int limit);

    size_t getCacheSizeLimit() const;
    size_t setCacheSizeLimit(size_t limit);
=======
    void validate() const {}
#endif

    int getCacheCountLimit() const { return fCacheCountLimit; }
    int setCacheCountLimit(int limit);

    size_t  getCacheSizeLimit() const { return fCacheSizeLimit; }
    size_t  setCacheSizeLimit(size_t limit);

    // returns true if this cache is over-budget either due to size limit
    // or count limit.
    bool isOverBudget() const {
        return fCacheCount > fCacheCountLimit ||
               fTotalMemoryUsed > fCacheSizeLimit;
    }
>>>>>>> miniblink49

    void purgeAll(); // does not change budget

    // call when a glyphcache is available for caching (i.e. not in use)
    void attachCacheToHead(SkGlyphCache*);

    // can only be called when the mutex is already held
    void internalDetachCache(SkGlyphCache*);
    void internalAttachCacheToHead(SkGlyphCache*);

private:
    SkGlyphCache* fHead;
<<<<<<< HEAD
    size_t fTotalMemoryUsed;
    size_t fCacheSizeLimit;
=======
    size_t  fTotalMemoryUsed;
    size_t  fCacheSizeLimit;
>>>>>>> miniblink49
    int32_t fCacheCountLimit;
    int32_t fCacheCount;

    // Checkout budgets, modulated by the specified min-bytes-needed-to-purge,
    // and attempt to purge caches to match.
    // Returns number of bytes freed.
    size_t internalPurge(size_t minBytesNeeded = 0);
};

#endif
