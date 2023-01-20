/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkMaskSwizzler.h"
#include "SkCodecPriv.h"
#include "SkColorPriv.h"

static void swizzle_mask16_to_rgba_opaque(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint16_t* srcPtr = ((uint16_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPackARGB_as_RGBA(0xFF, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask16_to_bgra_opaque(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint16_t* srcPtr = ((uint16_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPackARGB_as_BGRA(0xFF, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask16_to_rgba_unpremul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint16_t* srcPtr = ((uint16_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[0];
=======
#include "SkCodecPriv.h"
#include "SkColorPriv.h"
#include "SkMaskSwizzler.h"

static SkSwizzler::ResultAlpha swizzle_mask16_to_n32_opaque(
        void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks) {

    // Use the masks to decode to the destination
    uint16_t* srcPtr = (uint16_t*) srcRow;
    SkPMColor* dstPtr = (SkPMColor*) dstRow;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[i];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPackARGB32NoCheck(0xFF, red, green, blue);
    }
    return SkSwizzler::kOpaque_ResultAlpha;
}

static SkSwizzler::ResultAlpha swizzle_mask16_to_n32_unpremul(
        void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks) {

    // Use the masks to decode to the destination
    uint16_t* srcPtr = (uint16_t*) srcRow;
    SkPMColor* dstPtr = (SkPMColor*) dstRow;
    INIT_RESULT_ALPHA;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[i];
>>>>>>> miniblink49
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
<<<<<<< HEAD
        dstPtr[i] = SkPackARGB_as_RGBA(alpha, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask16_to_bgra_unpremul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint16_t* srcPtr = ((uint16_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[0];
=======
        UPDATE_RESULT_ALPHA(alpha);
        dstPtr[i] = SkPackARGB32NoCheck(alpha, red, green, blue);
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_mask16_to_n32_premul(
        void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks) {

    // Use the masks to decode to the destination
    uint16_t* srcPtr = (uint16_t*) srcRow;
    SkPMColor* dstPtr = (SkPMColor*) dstRow;
    INIT_RESULT_ALPHA;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[i];
>>>>>>> miniblink49
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
<<<<<<< HEAD
        dstPtr[i] = SkPackARGB_as_BGRA(alpha, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask16_to_rgba_premul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint16_t* srcPtr = ((uint16_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[0];
=======
        UPDATE_RESULT_ALPHA(alpha);
        dstPtr[i] = SkPreMultiplyARGB(alpha, red, green, blue);
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_mask24_to_n32_opaque(
        void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks) {

    // Use the masks to decode to the destination
    SkPMColor* dstPtr = (SkPMColor*) dstRow;
    for (int i = 0; i < 3*width; i += 3) {
        uint32_t p = srcRow[i] | (srcRow[i + 1] << 8) | srcRow[i + 2] << 16;
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i/3] = SkPackARGB32NoCheck(0xFF, red, green, blue);
    }
    return SkSwizzler::kOpaque_ResultAlpha;
}

static SkSwizzler::ResultAlpha swizzle_mask24_to_n32_unpremul(
        void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks) {

    // Use the masks to decode to the destination
    SkPMColor* dstPtr = (SkPMColor*) dstRow;
    INIT_RESULT_ALPHA;
    for (int i = 0; i < 3*width; i += 3) {
        uint32_t p = srcRow[i] | (srcRow[i + 1] << 8) | srcRow[i + 2] << 16;
>>>>>>> miniblink49
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
<<<<<<< HEAD
        dstPtr[i] = premultiply_argb_as_rgba(alpha, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask16_to_bgra_premul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint16_t* srcPtr = ((uint16_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[0];
=======
        UPDATE_RESULT_ALPHA(alpha);
        dstPtr[i/3] = SkPackARGB32NoCheck(alpha, red, green, blue);
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_mask24_to_n32_premul(
        void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks) {

    // Use the masks to decode to the destination
    SkPMColor* dstPtr = (SkPMColor*) dstRow;
    INIT_RESULT_ALPHA;
    for (int i = 0; i < 3*width; i += 3) {
        uint32_t p = srcRow[i] | (srcRow[i + 1] << 8) | srcRow[i + 2] << 16;
>>>>>>> miniblink49
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
<<<<<<< HEAD
        dstPtr[i] = premultiply_argb_as_bgra(alpha, red, green, blue);
        srcPtr += sampleX;
    }
}

// TODO (msarett): We have promoted a two byte per pixel image to 8888, only to
// convert it back to 565. Instead, we should swizzle to 565 directly.
static void swizzle_mask16_to_565(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint16_t* srcPtr = ((uint16_t*)srcRow) + startX;
    uint16_t* dstPtr = (uint16_t*)dstRow;
    for (int i = 0; i < width; i++) {
        uint16_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPack888ToRGB16(red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask24_to_rgba_opaque(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    srcRow += 3 * startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcRow[0] | (srcRow[1] << 8) | srcRow[2] << 16;
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPackARGB_as_RGBA(0xFF, red, green, blue);
        srcRow += 3 * sampleX;
    }
}

static void swizzle_mask24_to_bgra_opaque(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    srcRow += 3 * startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcRow[0] | (srcRow[1] << 8) | srcRow[2] << 16;
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPackARGB_as_BGRA(0xFF, red, green, blue);
        srcRow += 3 * sampleX;
    }
}

static void swizzle_mask24_to_rgba_unpremul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    srcRow += 3 * startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcRow[0] | (srcRow[1] << 8) | srcRow[2] << 16;
=======
        UPDATE_RESULT_ALPHA(alpha);
        dstPtr[i/3] = SkPreMultiplyARGB(alpha, red, green, blue);
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_mask32_to_n32_opaque(
        void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks) {

    // Use the masks to decode to the destination
    uint32_t* srcPtr = (uint32_t*) srcRow;
    SkPMColor* dstPtr = (SkPMColor*) dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[i];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPackARGB32NoCheck(0xFF, red, green, blue);
    }
    return SkSwizzler::kOpaque_ResultAlpha;
}

static SkSwizzler::ResultAlpha swizzle_mask32_to_n32_unpremul(
        void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks) {

    // Use the masks to decode to the destination
    uint32_t* srcPtr = (uint32_t*) srcRow;
    SkPMColor* dstPtr = (SkPMColor*) dstRow;
    INIT_RESULT_ALPHA;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[i];
>>>>>>> miniblink49
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
<<<<<<< HEAD
        dstPtr[i] = SkPackARGB_as_RGBA(alpha, red, green, blue);
        srcRow += 3 * sampleX;
    }
}

static void swizzle_mask24_to_bgra_unpremul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    srcRow += 3 * startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcRow[0] | (srcRow[1] << 8) | srcRow[2] << 16;
=======
        UPDATE_RESULT_ALPHA(alpha);
        dstPtr[i] = SkPackARGB32NoCheck(alpha, red, green, blue);
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_mask32_to_n32_premul(
        void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks) {

    // Use the masks to decode to the destination
    uint32_t* srcPtr = (uint32_t*) srcRow;
    SkPMColor* dstPtr = (SkPMColor*) dstRow;
    INIT_RESULT_ALPHA;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[i];
>>>>>>> miniblink49
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
<<<<<<< HEAD
        dstPtr[i] = SkPackARGB_as_BGRA(alpha, red, green, blue);
        srcRow += 3 * sampleX;
    }
}

static void swizzle_mask24_to_rgba_premul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    srcRow += 3 * startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcRow[0] | (srcRow[1] << 8) | srcRow[2] << 16;
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
        dstPtr[i] = premultiply_argb_as_rgba(alpha, red, green, blue);
        srcRow += 3 * sampleX;
    }
}

static void swizzle_mask24_to_bgra_premul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    srcRow += 3 * startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcRow[0] | (srcRow[1] << 8) | srcRow[2] << 16;
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
        dstPtr[i] = premultiply_argb_as_bgra(alpha, red, green, blue);
        srcRow += 3 * sampleX;
    }
}

static void swizzle_mask24_to_565(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    srcRow += 3 * startX;
    uint16_t* dstPtr = (uint16_t*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcRow[0] | (srcRow[1] << 8) | srcRow[2] << 16;
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPack888ToRGB16(red, green, blue);
        srcRow += 3 * sampleX;
    }
}

static void swizzle_mask32_to_rgba_opaque(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint32_t* srcPtr = ((uint32_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPackARGB_as_RGBA(0xFF, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask32_to_bgra_opaque(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint32_t* srcPtr = ((uint32_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPackARGB_as_BGRA(0xFF, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask32_to_rgba_unpremul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint32_t* srcPtr = ((uint32_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
        dstPtr[i] = SkPackARGB_as_RGBA(alpha, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask32_to_bgra_unpremul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint32_t* srcPtr = ((uint32_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
        dstPtr[i] = SkPackARGB_as_BGRA(alpha, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask32_to_rgba_premul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint32_t* srcPtr = ((uint32_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
        dstPtr[i] = premultiply_argb_as_rgba(alpha, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask32_to_bgra_premul(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{

    // Use the masks to decode to the destination
    uint32_t* srcPtr = ((uint32_t*)srcRow) + startX;
    SkPMColor* dstPtr = (SkPMColor*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        uint8_t alpha = masks->getAlpha(p);
        dstPtr[i] = premultiply_argb_as_bgra(alpha, red, green, blue);
        srcPtr += sampleX;
    }
}

static void swizzle_mask32_to_565(
    void* dstRow, const uint8_t* srcRow, int width, SkMasks* masks,
    uint32_t startX, uint32_t sampleX)
{
    // Use the masks to decode to the destination
    uint32_t* srcPtr = ((uint32_t*)srcRow) + startX;
    uint16_t* dstPtr = (uint16_t*)dstRow;
    for (int i = 0; i < width; i++) {
        uint32_t p = srcPtr[0];
        uint8_t red = masks->getRed(p);
        uint8_t green = masks->getGreen(p);
        uint8_t blue = masks->getBlue(p);
        dstPtr[i] = SkPack888ToRGB16(red, green, blue);
        srcPtr += sampleX;
    }
=======
        UPDATE_RESULT_ALPHA(alpha);
        dstPtr[i] = SkPreMultiplyARGB(alpha, red, green, blue);
    }
    return COMPUTE_RESULT_ALPHA;
>>>>>>> miniblink49
}

/*
 *
 * Create a new mask swizzler
 *
 */
<<<<<<< HEAD
SkMaskSwizzler* SkMaskSwizzler::CreateMaskSwizzler(const SkImageInfo& dstInfo,
    const SkImageInfo& srcInfo, SkMasks* masks, uint32_t bitsPerPixel,
    const SkCodec::Options& options)
{

    // Choose the appropriate row procedure
    RowProc proc = nullptr;
    switch (bitsPerPixel) {
    case 16:
        switch (dstInfo.colorType()) {
        case kRGBA_8888_SkColorType:
            if (kOpaque_SkAlphaType == srcInfo.alphaType()) {
                proc = &swizzle_mask16_to_rgba_opaque;
            } else {
                switch (dstInfo.alphaType()) {
                case kUnpremul_SkAlphaType:
                    proc = &swizzle_mask16_to_rgba_unpremul;
                    break;
                case kPremul_SkAlphaType:
                    proc = &swizzle_mask16_to_rgba_premul;
                    break;
                default:
                    break;
                }
            }
            break;
        case kBGRA_8888_SkColorType:
            if (kOpaque_SkAlphaType == srcInfo.alphaType()) {
                proc = &swizzle_mask16_to_bgra_opaque;
            } else {
                switch (dstInfo.alphaType()) {
                case kUnpremul_SkAlphaType:
                    proc = &swizzle_mask16_to_bgra_unpremul;
                    break;
                case kPremul_SkAlphaType:
                    proc = &swizzle_mask16_to_bgra_premul;
                    break;
                default:
                    break;
                }
            }
            break;
        case kRGB_565_SkColorType:
            proc = &swizzle_mask16_to_565;
            break;
        default:
            break;
        }
        break;
    case 24:
        switch (dstInfo.colorType()) {
        case kRGBA_8888_SkColorType:
            if (kOpaque_SkAlphaType == srcInfo.alphaType()) {
                proc = &swizzle_mask24_to_rgba_opaque;
            } else {
                switch (dstInfo.alphaType()) {
                case kUnpremul_SkAlphaType:
                    proc = &swizzle_mask24_to_rgba_unpremul;
                    break;
                case kPremul_SkAlphaType:
                    proc = &swizzle_mask24_to_rgba_premul;
                    break;
                default:
                    break;
                }
            }
            break;
        case kBGRA_8888_SkColorType:
            if (kOpaque_SkAlphaType == srcInfo.alphaType()) {
                proc = &swizzle_mask24_to_bgra_opaque;
            } else {
                switch (dstInfo.alphaType()) {
                case kUnpremul_SkAlphaType:
                    proc = &swizzle_mask24_to_bgra_unpremul;
                    break;
                case kPremul_SkAlphaType:
                    proc = &swizzle_mask24_to_bgra_premul;
                    break;
                default:
                    break;
                }
            }
            break;
        case kRGB_565_SkColorType:
            proc = &swizzle_mask24_to_565;
            break;
        default:
            break;
        }
        break;
    case 32:
        switch (dstInfo.colorType()) {
        case kRGBA_8888_SkColorType:
            if (kOpaque_SkAlphaType == srcInfo.alphaType()) {
                proc = &swizzle_mask32_to_rgba_opaque;
            } else {
                switch (dstInfo.alphaType()) {
                case kUnpremul_SkAlphaType:
                    proc = &swizzle_mask32_to_rgba_unpremul;
                    break;
                case kPremul_SkAlphaType:
                    proc = &swizzle_mask32_to_rgba_premul;
                    break;
                default:
                    break;
                }
            }
            break;
        case kBGRA_8888_SkColorType:
            if (kOpaque_SkAlphaType == srcInfo.alphaType()) {
                proc = &swizzle_mask32_to_bgra_opaque;
            } else {
                switch (dstInfo.alphaType()) {
                case kUnpremul_SkAlphaType:
                    proc = &swizzle_mask32_to_bgra_unpremul;
                    break;
                case kPremul_SkAlphaType:
                    proc = &swizzle_mask32_to_bgra_premul;
                    break;
                default:
                    break;
                }
            }
            break;
        case kRGB_565_SkColorType:
            proc = &swizzle_mask32_to_565;
            break;
        default:
            break;
        }
        break;
    default:
        SkASSERT(false);
        return nullptr;
    }

    int srcOffset = 0;
    int srcWidth = dstInfo.width();
    if (options.fSubset) {
        srcOffset = options.fSubset->left();
        srcWidth = options.fSubset->width();
    }

    return new SkMaskSwizzler(masks, proc, srcOffset, srcWidth);
=======
SkMaskSwizzler* SkMaskSwizzler::CreateMaskSwizzler(
        const SkImageInfo& info, void* dst, size_t dstRowBytes, SkMasks* masks,
        uint32_t bitsPerPixel) {

    // Choose the appropriate row procedure
    RowProc proc = NULL;
    switch (bitsPerPixel) {
        case 16:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    switch (info.alphaType()) {
                        case kUnpremul_SkAlphaType:
                            proc = &swizzle_mask16_to_n32_unpremul;
                            break;
                        case kPremul_SkAlphaType:
                            proc = &swizzle_mask16_to_n32_premul;
                            break;
                        case kOpaque_SkAlphaType:
                            proc = &swizzle_mask16_to_n32_opaque;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 24:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    switch (info.alphaType()) {
                        case kUnpremul_SkAlphaType:
                            proc = &swizzle_mask24_to_n32_unpremul;
                            break;
                        case kPremul_SkAlphaType:
                            proc = &swizzle_mask24_to_n32_premul;
                            break;
                        case kOpaque_SkAlphaType:
                            proc = &swizzle_mask24_to_n32_opaque;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 32:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    switch (info.alphaType()) {
                        case kUnpremul_SkAlphaType:
                            proc = &swizzle_mask32_to_n32_unpremul;
                            break;
                        case kPremul_SkAlphaType:
                            proc = &swizzle_mask32_to_n32_premul;
                            break;
                        case kOpaque_SkAlphaType:
                            proc = &swizzle_mask32_to_n32_opaque;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            SkASSERT(false);
            return NULL;
    }
    return SkNEW_ARGS(SkMaskSwizzler, (info, dst, dstRowBytes, masks, proc));
>>>>>>> miniblink49
}

/*
 *
 * Constructor for mask swizzler
 *
 */
<<<<<<< HEAD
SkMaskSwizzler::SkMaskSwizzler(SkMasks* masks, RowProc proc, int srcOffset, int subsetWidth)
    : fMasks(masks)
    , fRowProc(proc)
    , fSubsetWidth(subsetWidth)
    , fDstWidth(subsetWidth)
    , fSampleX(1)
    , fSrcOffset(srcOffset)
    , fX0(srcOffset)
{
}

int SkMaskSwizzler::onSetSampleX(int sampleX)
{
    // FIXME: Share this function with SkSwizzler?
    SkASSERT(sampleX > 0); // Surely there is an upper limit? Should there be
        // way to report failure?
    fSampleX = sampleX;
    fX0 = get_start_coord(sampleX) + fSrcOffset;
    fDstWidth = get_scaled_dimension(fSubsetWidth, sampleX);

    // check that fX0 is valid
    SkASSERT(fX0 >= 0);
    return fDstWidth;
}
=======
SkMaskSwizzler::SkMaskSwizzler(const SkImageInfo& dstInfo, void* dst,
                               size_t dstRowBytes, SkMasks* masks, RowProc proc)
    : fDstInfo(dstInfo)
    , fDst(dst)
    , fDstRowBytes(dstRowBytes)
    , fMasks(masks)
    , fRowProc(proc)
{}
>>>>>>> miniblink49

/*
 *
 * Swizzle the specified row
 *
 */
<<<<<<< HEAD
void SkMaskSwizzler::swizzle(void* dst, const uint8_t* SK_RESTRICT src)
{
    SkASSERT(nullptr != dst && nullptr != src);
    fRowProc(dst, src, fDstWidth, fMasks, fX0, fSampleX);
=======
SkSwizzler::ResultAlpha SkMaskSwizzler::next(const uint8_t* SK_RESTRICT src,
        int y) {
    // Choose the row
    void* row = SkTAddOffset<void>(fDst, y*fDstRowBytes);

    // Decode the row
    return fRowProc(row, src, fDstInfo.width(), fMasks);
>>>>>>> miniblink49
}
