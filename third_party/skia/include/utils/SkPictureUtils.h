/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkPictureUtils_DEFINED
#define SkPictureUtils_DEFINED

#include "SkPicture.h"

// TODO: remove this file?

class SK_API SkPictureUtils {
public:
    /**
     *  How many bytes are allocated to hold the SkPicture.
     *  Includes operations, parameters, bounding data, deletion listeners;
     *  includes nested SkPictures, but does not include large objects that
     *  SkRecord holds a reference to (e.g. paths, or pixels backing bitmaps).
     */
<<<<<<< HEAD
    static size_t ApproximateBytesUsed(const SkPicture* pict)
    {
=======
    static size_t ApproximateBytesUsed(const SkPicture* pict) {
>>>>>>> miniblink49
        return pict->approximateBytesUsed();
    }
};

#endif
