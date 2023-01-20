/*
 * Copyright 2007 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMask.h"

//#define TRACK_SKMASK_LIFETIME

/** returns the product if it is positive and fits in 31 bits. Otherwise this
    returns 0.
 */
<<<<<<< HEAD
static int32_t safeMul32(int32_t a, int32_t b)
{
=======
static int32_t safeMul32(int32_t a, int32_t b) {
>>>>>>> miniblink49
    int64_t size = sk_64_mul(a, b);
    if (size > 0 && sk_64_isS32(size)) {
        return sk_64_asS32(size);
    }
    return 0;
}

<<<<<<< HEAD
size_t SkMask::computeImageSize() const
{
    return safeMul32(fBounds.height(), fRowBytes);
}

size_t SkMask::computeTotalImageSize() const
{
=======
size_t SkMask::computeImageSize() const {
    return safeMul32(fBounds.height(), fRowBytes);
}

size_t SkMask::computeTotalImageSize() const {
>>>>>>> miniblink49
    size_t size = this->computeImageSize();
    if (fFormat == SkMask::k3D_Format) {
        size = safeMul32(SkToS32(size), 3);
    }
    return size;
}

#ifdef TRACK_SKMASK_LIFETIME
<<<<<<< HEAD
static int gCounter;
=======
    static int gCounter;
>>>>>>> miniblink49
#endif

/** We explicitly use this allocator for SkBimap pixels, so that we can
    freely assign memory allocated by one class to the other.
*/
<<<<<<< HEAD
uint8_t* SkMask::AllocImage(size_t size)
{
=======
uint8_t* SkMask::AllocImage(size_t size) {
>>>>>>> miniblink49
#ifdef TRACK_SKMASK_LIFETIME
    SkDebugf("SkMask::AllocImage %d\n", gCounter++);
#endif
    return (uint8_t*)sk_malloc_throw(SkAlign4(size));
}

/** We explicitly use this allocator for SkBimap pixels, so that we can
    freely assign memory allocated by one class to the other.
*/
<<<<<<< HEAD
void SkMask::FreeImage(void* image)
{
=======
void SkMask::FreeImage(void* image) {
>>>>>>> miniblink49
#ifdef TRACK_SKMASK_LIFETIME
    if (image) {
        SkDebugf("SkMask::FreeImage  %d\n", --gCounter);
    }
#endif
    sk_free(image);
}

///////////////////////////////////////////////////////////////////////////////

static const int gMaskFormatToShift[] = {
    ~0, // BW -- not supported
<<<<<<< HEAD
    0, // A8
    0, // 3D
    2, // ARGB32
    1, // LCD16
};

static int maskFormatToShift(SkMask::Format format)
{
=======
    0,  // A8
    0,  // 3D
    2,  // ARGB32
    1,  // LCD16
};

static int maskFormatToShift(SkMask::Format format) {
>>>>>>> miniblink49
    SkASSERT((unsigned)format < SK_ARRAY_COUNT(gMaskFormatToShift));
    SkASSERT(SkMask::kBW_Format != format);
    return gMaskFormatToShift[format];
}

<<<<<<< HEAD
void* SkMask::getAddr(int x, int y) const
{
=======
void* SkMask::getAddr(int x, int y) const {
>>>>>>> miniblink49
    SkASSERT(kBW_Format != fFormat);
    SkASSERT(fBounds.contains(x, y));
    SkASSERT(fImage);

    char* addr = (char*)fImage;
    addr += (y - fBounds.fTop) * fRowBytes;
    addr += (x - fBounds.fLeft) << maskFormatToShift(fFormat);
    return addr;
}
