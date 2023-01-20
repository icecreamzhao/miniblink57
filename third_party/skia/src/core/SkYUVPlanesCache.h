/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkYUVPlanesCache_DEFINED
#define SkYUVPlanesCache_DEFINED

#include "SkCachedData.h"
#include "SkImageInfo.h"
<<<<<<< HEAD
#include "SkYUVSizeInfo.h"
=======
>>>>>>> miniblink49

class SkResourceCache;

class SkYUVPlanesCache {
public:
    /**
     * The Info struct contains data about the 3 Y, U and V planes of memory stored
     * contiguously, in that order, as a single block of memory within SkYUVPlanesCache.
     *
<<<<<<< HEAD
     * fSizeInfo: fWidth, fHeight, and fWidthBytes of each of the Y, U, and V planes.
     * fColorSpace: color space that will be used for the YUV -> RGB conversion.
     */
    struct Info {
        SkYUVSizeInfo fSizeInfo;
=======
     * fSize: Width and height of each of the 3 planes (in pixels).
     * fSizeInMemory: Amount of memory allocated for each plane (may be different from
                      "height * rowBytes", depending on the jpeg decoder's block size).
     *                The sum of these is the total size stored within SkYUVPlanesCache.
     * fRowBytes: rowBytes for each of the 3 planes (in bytes).
     * fColorSpace: color space that will be used for the YUV -> RGB conversion.
     */
    struct Info {
        SkISize fSize[3];
        size_t  fSizeInMemory[3];
        size_t  fRowBytes[3];
>>>>>>> miniblink49
        SkYUVColorSpace fColorSpace;
    };
    /**
     * On success, return a ref to the SkCachedData that holds the pixels.
     *
<<<<<<< HEAD
     * On failure, return nullptr.
     */
    static SkCachedData* FindAndRef(uint32_t genID, Info* info,
        SkResourceCache* localCache = nullptr);
=======
     * On failure, return NULL.
     */
    static SkCachedData* FindAndRef(uint32_t genID, Info* info,
                                    SkResourceCache* localCache = NULL);
>>>>>>> miniblink49

    /**
     * Add a pixelRef ID and its YUV planes data to the cache.
     */
    static void Add(uint32_t genID, SkCachedData* data, Info* info,
<<<<<<< HEAD
        SkResourceCache* localCache = nullptr);
=======
                    SkResourceCache* localCache = NULL);
>>>>>>> miniblink49
};

#endif
