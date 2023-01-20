/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkMaskCache_DEFINED
#define SkMaskCache_DEFINED

#include "SkBlurTypes.h"
#include "SkCachedData.h"
#include "SkMask.h"
<<<<<<< HEAD
#include "SkRRect.h"
#include "SkRect.h"
#include "SkResourceCache.h"
=======
#include "SkRect.h"
#include "SkResourceCache.h"
#include "SkRRect.h"
>>>>>>> miniblink49

class SkMaskCache {
public:
    /**
     * On success, return a ref to the SkCachedData that holds the pixels, and have mask
     * already point to that memory.
     *
<<<<<<< HEAD
     * On failure, return nullptr.
     */
    static SkCachedData* FindAndRef(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
        const SkRRect& rrect, SkMask* mask,
        SkResourceCache* localCache = nullptr);
    static SkCachedData* FindAndRef(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
        const SkRect rects[], int count, SkMask* mask,
        SkResourceCache* localCache = nullptr);
=======
     * On failure, return NULL.
     */
    static SkCachedData* FindAndRef(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
                                    const SkRRect& rrect, SkMask* mask,
                                    SkResourceCache* localCache = NULL);
    static SkCachedData* FindAndRef(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
                                    const SkRect rects[], int count, SkMask* mask,
                                    SkResourceCache* localCache = NULL);
>>>>>>> miniblink49

    /**
     * Add a mask and its pixel-data to the cache.
     */
    static void Add(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
<<<<<<< HEAD
        const SkRRect& rrect, const SkMask& mask, SkCachedData* data,
        SkResourceCache* localCache = nullptr);
    static void Add(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
        const SkRect rects[], int count, const SkMask& mask, SkCachedData* data,
        SkResourceCache* localCache = nullptr);
=======
                    const SkRRect& rrect, const SkMask& mask, SkCachedData* data,
                    SkResourceCache* localCache = NULL);
    static void Add(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
                    const SkRect rects[], int count, const SkMask& mask, SkCachedData* data,
                    SkResourceCache* localCache = NULL);
>>>>>>> miniblink49
};

#endif
