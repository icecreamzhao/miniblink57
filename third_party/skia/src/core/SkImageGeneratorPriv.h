/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkImageGeneratorPriv_DEFINED
#define SkImageGeneratorPriv_DEFINED

<<<<<<< HEAD
#include "SkDiscardableMemory.h"
#include "SkImageGenerator.h"
=======
#include "SkImageGenerator.h"
#include "SkDiscardableMemory.h"
>>>>>>> miniblink49

/**
 *  Takes ownership of SkImageGenerator.  If this method fails for
 *  whatever reason, it will return false and immediatetely delete
 *  the generator.  If it succeeds, it will modify destination
 *  bitmap.
 *
<<<<<<< HEAD
 *  If generator is nullptr, will safely return false.
 *
 *  If this fails or when the SkDiscardablePixelRef that is
 *  installed into destination is destroyed, it will call
 *  `delete` on the generator.  Therefore, generator should be
 *  allocated with `new`.
=======
 *  If generator is NULL, will safely return false.
 *
 *  If this fails or when the SkDiscardablePixelRef that is
 *  installed into destination is destroyed, it will call
 *  SkDELETE() on the generator.  Therefore, generator should be
 *  allocated with SkNEW() or SkNEW_ARGS().
>>>>>>> miniblink49
 *
 *  @param destination Upon success, this bitmap will be
 *  configured and have a pixelref installed.
 *
<<<<<<< HEAD
 *  @param factory If not nullptr, this object will be used as a
 *  source of discardable memory when decoding.  If nullptr, then
=======
 *  @param factory If not NULL, this object will be used as a
 *  source of discardable memory when decoding.  If NULL, then
>>>>>>> miniblink49
 *  SkDiscardableMemory::Create() will be called.
 *
 *  @return true iff successful.
 */
<<<<<<< HEAD
bool SkDEPRECATED_InstallDiscardablePixelRef(SkImageGenerator*, const SkIRect* subset,
    SkBitmap* destination,
    SkDiscardableMemory::Factory* factory);
=======
bool SkInstallDiscardablePixelRef(SkImageGenerator*, const SkIRect* subset, SkBitmap* destination,
                                  SkDiscardableMemory::Factory* factory);
>>>>>>> miniblink49

#endif
