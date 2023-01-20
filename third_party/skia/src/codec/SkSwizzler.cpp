/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkSwizzler.h"
#include "SkCodecPriv.h"
#include "SkColorPriv.h"
#include "SkOpts.h"
#include "SkTemplates.h"

static void copy(void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{
    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    memcpy(dst, src + offset, width * bpp);
}

static void sample1(void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{
    src += offset;
    uint8_t* dst8 = (uint8_t*)dst;
    for (int x = 0; x < width; x++) {
        dst8[x] = *src;
        src += deltaSrc;
    }
}

static void sample2(void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{
    src += offset;
    uint16_t* dst16 = (uint16_t*)dst;
    for (int x = 0; x < width; x++) {
        dst16[x] = *((const uint16_t*)src);
        src += deltaSrc;
    }
}

static void sample4(void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{
    src += offset;
    uint32_t* dst32 = (uint32_t*)dst;
    for (int x = 0; x < width; x++) {
        dst32[x] = *((const uint32_t*)src);
        src += deltaSrc;
    }
}

// kBit
// These routines exclusively choose between white and black

#define GRAYSCALE_BLACK 0
#define GRAYSCALE_WHITE 0xFF

// same as swizzle_bit_to_index and swizzle_bit_to_n32 except for value assigned to dst[x]
static void swizzle_bit_to_grayscale(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor* /*ctable*/)
{

    uint8_t* SK_RESTRICT dst = (uint8_t*)dstRow;

    // increment src by byte offset and bitIndex by bit offset
    src += offset / 8;
    int bitIndex = offset % 8;
    uint8_t currByte = *src;

    dst[0] = ((currByte >> (7 - bitIndex)) & 1) ? GRAYSCALE_WHITE : GRAYSCALE_BLACK;

    for (int x = 1; x < dstWidth; x++) {
        int bitOffset = bitIndex + deltaSrc;
        bitIndex = bitOffset % 8;
        currByte = *(src += bitOffset / 8);
        dst[x] = ((currByte >> (7 - bitIndex)) & 1) ? GRAYSCALE_WHITE : GRAYSCALE_BLACK;
    }
}

#undef GRAYSCALE_BLACK
#undef GRAYSCALE_WHITE

// same as swizzle_bit_to_grayscale and swizzle_bit_to_n32 except for value assigned to dst[x]
static void swizzle_bit_to_index(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor* /*ctable*/)
{
    uint8_t* SK_RESTRICT dst = (uint8_t*)dstRow;

    // increment src by byte offset and bitIndex by bit offset
    src += offset / 8;
    int bitIndex = offset % 8;
    uint8_t currByte = *src;

    dst[0] = ((currByte >> (7 - bitIndex)) & 1);

    for (int x = 1; x < dstWidth; x++) {
        int bitOffset = bitIndex + deltaSrc;
        bitIndex = bitOffset % 8;
        currByte = *(src += bitOffset / 8);
        dst[x] = ((currByte >> (7 - bitIndex)) & 1);
    }
}

// same as swizzle_bit_to_grayscale and swizzle_bit_to_index except for value assigned to dst[x]
static void swizzle_bit_to_n32(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor* /*ctable*/)
{
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;

    // increment src by byte offset and bitIndex by bit offset
    src += offset / 8;
    int bitIndex = offset % 8;
    uint8_t currByte = *src;

    dst[0] = ((currByte >> (7 - bitIndex)) & 1) ? SK_ColorWHITE : SK_ColorBLACK;

    for (int x = 1; x < dstWidth; x++) {
        int bitOffset = bitIndex + deltaSrc;
        bitIndex = bitOffset % 8;
        currByte = *(src += bitOffset / 8);
        dst[x] = ((currByte >> (7 - bitIndex)) & 1) ? SK_ColorWHITE : SK_ColorBLACK;
    }
}

#define RGB565_BLACK 0
#define RGB565_WHITE 0xFFFF

static void swizzle_bit_to_565(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor* /*ctable*/)
{
    uint16_t* SK_RESTRICT dst = (uint16_t*)dstRow;

    // increment src by byte offset and bitIndex by bit offset
    src += offset / 8;
    int bitIndex = offset % 8;
    uint8_t currByte = *src;

    dst[0] = ((currByte >> (7 - bitIndex)) & 1) ? RGB565_WHITE : RGB565_BLACK;

    for (int x = 1; x < dstWidth; x++) {
        int bitOffset = bitIndex + deltaSrc;
        bitIndex = bitOffset % 8;
        currByte = *(src += bitOffset / 8);
        dst[x] = ((currByte >> (7 - bitIndex)) & 1) ? RGB565_WHITE : RGB565_BLACK;
    }
}

#undef RGB565_BLACK
#undef RGB565_WHITE

// kIndex1, kIndex2, kIndex4

static void swizzle_small_index_to_index(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    uint8_t* dst = (uint8_t*)dstRow;
    src += offset / 8;
    int bitIndex = offset % 8;
    uint8_t currByte = *src;
    const uint8_t mask = (1 << bpp) - 1;
    uint8_t index = (currByte >> (8 - bpp - bitIndex)) & mask;
    dst[0] = index;

    for (int x = 1; x < dstWidth; x++) {
        int bitOffset = bitIndex + deltaSrc;
        bitIndex = bitOffset % 8;
        currByte = *(src += bitOffset / 8);
        index = (currByte >> (8 - bpp - bitIndex)) & mask;
        dst[x] = index;
    }
}

static void swizzle_small_index_to_565(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    uint16_t* dst = (uint16_t*)dstRow;
    src += offset / 8;
    int bitIndex = offset % 8;
    uint8_t currByte = *src;
    const uint8_t mask = (1 << bpp) - 1;
    uint8_t index = (currByte >> (8 - bpp - bitIndex)) & mask;
    dst[0] = SkPixel32ToPixel16(ctable[index]);

    for (int x = 1; x < dstWidth; x++) {
        int bitOffset = bitIndex + deltaSrc;
        bitIndex = bitOffset % 8;
        currByte = *(src += bitOffset / 8);
        index = (currByte >> (8 - bpp - bitIndex)) & mask;
        dst[x] = SkPixel32ToPixel16(ctable[index]);
    }
}

static void swizzle_small_index_to_n32(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    SkPMColor* dst = (SkPMColor*)dstRow;
    src += offset / 8;
    int bitIndex = offset % 8;
    uint8_t currByte = *src;
    const uint8_t mask = (1 << bpp) - 1;
    uint8_t index = (currByte >> (8 - bpp - bitIndex)) & mask;
    dst[0] = ctable[index];

    for (int x = 1; x < dstWidth; x++) {
        int bitOffset = bitIndex + deltaSrc;
        bitIndex = bitOffset % 8;
        currByte = *(src += bitOffset / 8);
        index = (currByte >> (8 - bpp - bitIndex)) & mask;
        dst[x] = ctable[index];
    }
=======
#include "SkCodecPriv.h"
#include "SkColorPriv.h"
#include "SkSwizzler.h"
#include "SkTemplates.h"
#include "SkUtils.h"

SkSwizzler::ResultAlpha SkSwizzler::GetResult(uint8_t zeroAlpha,
                                              uint8_t maxAlpha) {
    // In the transparent case, this returns 0x0000
    // In the opaque case, this returns 0xFFFF
    // If the row is neither transparent nor opaque, returns something else
    return (((uint16_t) maxAlpha) << 8) | zeroAlpha;
}

// kIndex1, kIndex2, kIndex4

static SkSwizzler::ResultAlpha swizzle_small_index_to_index(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bitsPerPixel, int y, const SkPMColor ctable[]) {

    uint8_t* SK_RESTRICT dst = (uint8_t*) dstRow;
    INIT_RESULT_ALPHA;
    const uint32_t pixelsPerByte = 8 / bitsPerPixel;
    const size_t rowBytes = compute_row_bytes_ppb(width, pixelsPerByte);
    const uint8_t mask = (1 << bitsPerPixel) - 1;
    int x = 0;
    for (uint32_t byte = 0; byte < rowBytes; byte++) {
        uint8_t pixelData = src[byte];
        for (uint32_t p = 0; p < pixelsPerByte && x < width; p++) {
            uint8_t index = (pixelData >> (8 - bitsPerPixel)) & mask;
            UPDATE_RESULT_ALPHA(ctable[index] >> SK_A32_SHIFT);
            dst[x] = index;
            pixelData <<= bitsPerPixel;
            x++;
        }
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_small_index_to_n32(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bitsPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*) dstRow;
    INIT_RESULT_ALPHA;
    const uint32_t pixelsPerByte = 8 / bitsPerPixel;
    const size_t rowBytes = compute_row_bytes_ppb(width, pixelsPerByte);
    const uint8_t mask = (1 << bitsPerPixel) - 1;
    int x = 0;
    for (uint32_t byte = 0; byte < rowBytes; byte++) {
        uint8_t pixelData = src[byte];
        for (uint32_t p = 0; p < pixelsPerByte && x < width; p++) {
            uint8_t index = (pixelData >> (8 - bitsPerPixel)) & mask;
            SkPMColor c = ctable[index];
            UPDATE_RESULT_ALPHA(c >> SK_A32_SHIFT);
            dst[x] = c;
            pixelData <<= bitsPerPixel;
            x++;
        }
    }
    return COMPUTE_RESULT_ALPHA;
>>>>>>> miniblink49
}

// kIndex

<<<<<<< HEAD
static void swizzle_index_to_n32(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        SkPMColor c = ctable[*src];
        dst[x] = c;
        src += deltaSrc;
    }
}

static void swizzle_index_to_n32_skipZ(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        SkPMColor c = ctable[*src];
        if (c != 0) {
            dst[x] = c;
        }
        src += deltaSrc;
    }
}

static void swizzle_index_to_565(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bytesPerPixel, int deltaSrc, int offset, const SkPMColor ctable[])
{
    src += offset;
    uint16_t* SK_RESTRICT dst = (uint16_t*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        dst[x] = SkPixel32ToPixel16(ctable[*src]);
        src += deltaSrc;
    }
}

// kGray

static void swizzle_gray_to_n32(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        dst[x] = SkPackARGB32NoCheck(0xFF, *src, *src, *src);
        src += deltaSrc;
    }
}

static void fast_swizzle_gray_to_n32(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    // Note that there is no need to distinguish between RGB and BGR.
    // Each color channel will get the same value.
    SkOpts::gray_to_RGB1((uint32_t*)dst, src + offset, width);
}

static void swizzle_gray_to_565(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bytesPerPixel, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    uint16_t* SK_RESTRICT dst = (uint16_t*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        dst[x] = SkPack888ToRGB16(src[0], src[0], src[0]);
        src += deltaSrc;
    }
}

// kGrayAlpha

static void swizzle_grayalpha_to_n32_unpremul(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* dst32 = (SkPMColor*)dst;
    for (int x = 0; x < width; x++) {
        dst32[x] = SkPackARGB32NoCheck(src[1], src[0], src[0], src[0]);
        src += deltaSrc;
    }
}

static void fast_swizzle_grayalpha_to_n32_unpremul(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    // Note that there is no need to distinguish between RGB and BGR.
    // Each color channel will get the same value.
    SkOpts::grayA_to_RGBA((uint32_t*)dst, src + offset, width);
}

static void swizzle_grayalpha_to_n32_premul(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* dst32 = (SkPMColor*)dst;
    for (int x = 0; x < width; x++) {
        uint8_t pmgray = SkMulDiv255Round(src[1], src[0]);
        dst32[x] = SkPackARGB32NoCheck(src[1], pmgray, pmgray, pmgray);
        src += deltaSrc;
    }
}

static void fast_swizzle_grayalpha_to_n32_premul(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    // Note that there is no need to distinguish between rgb and bgr.
    // Each color channel will get the same value.
    SkOpts::grayA_to_rgbA((uint32_t*)dst, src + offset, width);
}

// kBGR

static void swizzle_bgr_to_565(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    uint16_t* SK_RESTRICT dst = (uint16_t*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        dst[x] = SkPack888ToRGB16(src[2], src[1], src[0]);
        src += deltaSrc;
    }
}

// kRGB

static void swizzle_rgb_to_rgba(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        dst[x] = SkPackARGB_as_RGBA(0xFF, src[0], src[1], src[2]);
        src += deltaSrc;
    }
}

static void swizzle_rgb_to_bgra(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        dst[x] = SkPackARGB_as_BGRA(0xFF, src[0], src[1], src[2]);
        src += deltaSrc;
    }
}

static void fast_swizzle_rgb_to_rgba(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc,
    int offset, const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    SkOpts::RGB_to_RGB1((uint32_t*)dst, src + offset, width);
}

static void fast_swizzle_rgb_to_bgra(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc,
    int offset, const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    SkOpts::RGB_to_BGR1((uint32_t*)dst, src + offset, width);
}

static void swizzle_rgb_to_565(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bytesPerPixel, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    uint16_t* SK_RESTRICT dst = (uint16_t*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        dst[x] = SkPack888ToRGB16(src[0], src[1], src[2]);
        src += deltaSrc;
    }
}

// kRGBA

static void swizzle_rgba_to_rgba_premul(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        dst[x] = premultiply_argb_as_rgba(src[3], src[0], src[1], src[2]);
        src += deltaSrc;
    }
}

static void swizzle_rgba_to_bgra_premul(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        dst[x] = premultiply_argb_as_bgra(src[3], src[0], src[1], src[2]);
        src += deltaSrc;
    }
}

static void fast_swizzle_rgba_to_rgba_premul(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc,
    int offset, const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    SkOpts::RGBA_to_rgbA((uint32_t*)dst, src + offset, width);
}

static void fast_swizzle_rgba_to_bgra_premul(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc,
    int offset, const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    SkOpts::RGBA_to_bgrA((uint32_t*)dst, src + offset, width);
}

static void swizzle_rgba_to_bgra_unpremul(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    uint32_t* SK_RESTRICT dst = reinterpret_cast<uint32_t*>(dstRow);
    for (int x = 0; x < dstWidth; x++) {
        unsigned alpha = src[3];
        dst[x] = SkPackARGB_as_BGRA(alpha, src[0], src[1], src[2]);
        src += deltaSrc;
    }
}

static void fast_swizzle_rgba_to_bgra_unpremul(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    SkOpts::RGBA_to_BGRA((uint32_t*)dst, src + offset, width);
}

// kCMYK
//
// CMYK is stored as four bytes per pixel.
//
// We will implement a crude conversion from CMYK -> RGB using formulas
// from easyrgb.com.
//
// CMYK -> CMY
// C = C * (1 - K) + K
// M = M * (1 - K) + K
// Y = Y * (1 - K) + K
//
// libjpeg actually gives us inverted CMYK, so we must subtract the
// original terms from 1.
// CMYK -> CMY
// C = (1 - C) * (1 - (1 - K)) + (1 - K)
// M = (1 - M) * (1 - (1 - K)) + (1 - K)
// Y = (1 - Y) * (1 - (1 - K)) + (1 - K)
//
// Simplifying the above expression.
// CMYK -> CMY
// C = 1 - CK
// M = 1 - MK
// Y = 1 - YK
//
// CMY -> RGB
// R = (1 - C) * 255
// G = (1 - M) * 255
// B = (1 - Y) * 255
//
// Therefore the full conversion is below.  This can be verified at
// www.rapidtables.com (assuming inverted CMYK).
// CMYK -> RGB
// R = C * K * 255
// G = M * K * 255
// B = Y * K * 255
//
// As a final note, we have treated the CMYK values as if they were on
// a scale from 0-1, when in fact they are 8-bit ints scaling from 0-255.
// We must divide each CMYK component by 255 to obtain the true conversion
// we should perform.
// CMYK -> RGB
// R = C * K / 255
// G = M * K / 255
// B = Y * K / 255
static void swizzle_cmyk_to_rgba(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        const uint8_t r = SkMulDiv255Round(src[0], src[3]);
        const uint8_t g = SkMulDiv255Round(src[1], src[3]);
        const uint8_t b = SkMulDiv255Round(src[2], src[3]);

        dst[x] = SkPackARGB_as_RGBA(0xFF, r, g, b);
        src += deltaSrc;
    }
}

static void swizzle_cmyk_to_bgra(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        const uint8_t r = SkMulDiv255Round(src[0], src[3]);
        const uint8_t g = SkMulDiv255Round(src[1], src[3]);
        const uint8_t b = SkMulDiv255Round(src[2], src[3]);

        dst[x] = SkPackARGB_as_BGRA(0xFF, r, g, b);
        src += deltaSrc;
    }
}

static void fast_swizzle_cmyk_to_rgba(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    SkOpts::inverted_CMYK_to_RGB1((uint32_t*)dst, src + offset, width);
}

static void fast_swizzle_cmyk_to_bgra(
    void* dst, const uint8_t* src, int width, int bpp, int deltaSrc, int offset,
    const SkPMColor ctable[])
{

    // This function must not be called if we are sampling.  If we are not
    // sampling, deltaSrc should equal bpp.
    SkASSERT(deltaSrc == bpp);

    SkOpts::inverted_CMYK_to_BGR1((uint32_t*)dst, src + offset, width);
}

static void swizzle_cmyk_to_565(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{

    src += offset;
    uint16_t* SK_RESTRICT dst = (uint16_t*)dstRow;
    for (int x = 0; x < dstWidth; x++) {
        const uint8_t r = SkMulDiv255Round(src[0], src[3]);
        const uint8_t g = SkMulDiv255Round(src[1], src[3]);
        const uint8_t b = SkMulDiv255Round(src[2], src[3]);

        dst[x] = SkPack888ToRGB16(r, g, b);
        src += deltaSrc;
    }
}

template <SkSwizzler::RowProc proc>
void SkSwizzler::SkipLeadingGrayAlphaZerosThen(
    void* dst, const uint8_t* src, int width,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{
    SkASSERT(!ctable);

    const uint16_t* src16 = (const uint16_t*)(src + offset);
    uint32_t* dst32 = (uint32_t*)dst;

    // This may miss opportunities to skip when the output is premultiplied,
    // e.g. for a src pixel 0x00FF which is not zero but becomes zero after premultiplication.
    while (width > 0 && *src16 == 0x0000) {
        width--;
        dst32++;
        src16 += deltaSrc / 2;
    }
    proc(dst32, (const uint8_t*)src16, width, bpp, deltaSrc, 0, ctable);
}

template <SkSwizzler::RowProc proc>
void SkSwizzler::SkipLeading8888ZerosThen(
    void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int dstWidth,
    int bpp, int deltaSrc, int offset, const SkPMColor ctable[])
{
    SkASSERT(!ctable);

    auto src32 = (const uint32_t*)(src + offset);
    auto dst32 = (uint32_t*)dstRow;

    // This may miss opportunities to skip when the output is premultiplied,
    // e.g. for a src pixel 0x00FFFFFF which is not zero but becomes zero after premultiplication.
    while (dstWidth > 0 && *src32 == 0x00000000) {
        dstWidth--;
        dst32++;
        src32 += deltaSrc / 4;
    }
    proc(dst32, (const uint8_t*)src32, dstWidth, bpp, deltaSrc, 0, ctable);
}

SkSwizzler* SkSwizzler::CreateSwizzler(const SkEncodedInfo& encodedInfo,
    const SkPMColor* ctable,
    const SkImageInfo& dstInfo,
    const SkCodec::Options& options,
    const SkIRect* frame,
    bool preSwizzled)
{
    if (SkEncodedInfo::kPalette_Color == encodedInfo.color() && nullptr == ctable) {
        return nullptr;
    }

    RowProc fastProc = nullptr;
    RowProc proc = nullptr;
    if (preSwizzled) {
        switch (dstInfo.colorType()) {
        case kGray_8_SkColorType:
            proc = &sample1;
            fastProc = &copy;
            break;
        case kRGB_565_SkColorType:
            proc = &sample2;
            fastProc = &copy;
            break;
        case kRGBA_8888_SkColorType:
        case kBGRA_8888_SkColorType:
            proc = &sample4;
            fastProc = &copy;
            break;
        default:
            return nullptr;
        }
    } else {
        SkCodec::ZeroInitialized zeroInit = options.fZeroInitialized;
        const bool premultiply = (SkEncodedInfo::kOpaque_Alpha != encodedInfo.alpha()) && (kPremul_SkAlphaType == dstInfo.alphaType());

        switch (encodedInfo.color()) {
        case SkEncodedInfo::kGray_Color:
            switch (encodedInfo.bitsPerComponent()) {
            case 1:
                switch (dstInfo.colorType()) {
                case kRGBA_8888_SkColorType:
                case kBGRA_8888_SkColorType:
                    proc = &swizzle_bit_to_n32;
                    break;
                case kIndex_8_SkColorType:
                    proc = &swizzle_bit_to_index;
                    break;
                case kRGB_565_SkColorType:
                    proc = &swizzle_bit_to_565;
                    break;
                case kGray_8_SkColorType:
                    proc = &swizzle_bit_to_grayscale;
                    break;
                default:
                    return nullptr;
                }
                break;
            case 8:
                switch (dstInfo.colorType()) {
                case kRGBA_8888_SkColorType:
                case kBGRA_8888_SkColorType:
                    proc = &swizzle_gray_to_n32;
                    fastProc = &fast_swizzle_gray_to_n32;
                    break;
                case kGray_8_SkColorType:
                    proc = &sample1;
                    fastProc = &copy;
                    break;
                case kRGB_565_SkColorType:
                    proc = &swizzle_gray_to_565;
                    break;
                default:
                    return nullptr;
                }
                break;
            default:
                return nullptr;
            }
            break;
        case SkEncodedInfo::kGrayAlpha_Color:
            switch (dstInfo.colorType()) {
            case kRGBA_8888_SkColorType:
            case kBGRA_8888_SkColorType:
                if (premultiply) {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeadingGrayAlphaZerosThen<swizzle_grayalpha_to_n32_premul>;
                        fastProc = &SkipLeadingGrayAlphaZerosThen<fast_swizzle_grayalpha_to_n32_premul>;
                    } else {
                        proc = &swizzle_grayalpha_to_n32_premul;
                        fastProc = &fast_swizzle_grayalpha_to_n32_premul;
                    }
                } else {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeadingGrayAlphaZerosThen<swizzle_grayalpha_to_n32_unpremul>;
                        fastProc = &SkipLeadingGrayAlphaZerosThen<fast_swizzle_grayalpha_to_n32_unpremul>;
                    } else {
                        proc = &swizzle_grayalpha_to_n32_unpremul;
                        fastProc = &fast_swizzle_grayalpha_to_n32_unpremul;
                    }
                }
                break;
            default:
                return nullptr;
            }
            break;
        case SkEncodedInfo::kPalette_Color:
            // We assume that the color table is premultiplied and swizzled
            // as desired.
            switch (encodedInfo.bitsPerComponent()) {
            case 1:
            case 2:
            case 4:
                switch (dstInfo.colorType()) {
                case kRGBA_8888_SkColorType:
                case kBGRA_8888_SkColorType:
                    proc = &swizzle_small_index_to_n32;
                    break;
                case kRGB_565_SkColorType:
                    proc = &swizzle_small_index_to_565;
                    break;
=======
static SkSwizzler::ResultAlpha swizzle_index_to_index(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    uint8_t* SK_RESTRICT dst = (uint8_t*) dstRow;
    memcpy(dst, src, width);
    // TODO (msarett): Should we skip the loop here and guess that the row is opaque/not opaque?
    //                 SkScaledBitmap sampler just guesses that it is opaque.  This is dangerous
    //                 and probably wrong since gif and bmp (rarely) may have alpha.
    INIT_RESULT_ALPHA;
    for (int x = 0; x < width; x++) {
        UPDATE_RESULT_ALPHA(ctable[src[x]] >> SK_A32_SHIFT);
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_index_to_n32(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    INIT_RESULT_ALPHA;
    for (int x = 0; x < width; x++) {
        SkPMColor c = ctable[src[x]];
        UPDATE_RESULT_ALPHA(c >> SK_A32_SHIFT);
        dst[x] = c;
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_index_to_n32_skipZ(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    INIT_RESULT_ALPHA;
    for (int x = 0; x < width; x++) {
        SkPMColor c = ctable[src[x]];
        UPDATE_RESULT_ALPHA(c >> SK_A32_SHIFT);
        if (c != 0) {
            dst[x] = c;
        }
    }
    return COMPUTE_RESULT_ALPHA;
}

#undef A32_MASK_IN_PLACE

// kGray

static SkSwizzler::ResultAlpha swizzle_gray_to_n32(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < width; x++) {
        dst[x] = SkPackARGB32NoCheck(0xFF, src[x], src[x], src[x]);
    }
    return SkSwizzler::kOpaque_ResultAlpha;
}

static SkSwizzler::ResultAlpha swizzle_gray_to_gray(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {
    memcpy(dstRow, src, width);
    return SkSwizzler::kOpaque_ResultAlpha;
}

// kBGRX

static SkSwizzler::ResultAlpha swizzle_bgrx_to_n32(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < width; x++) {
        dst[x] = SkPackARGB32NoCheck(0xFF, src[2], src[1], src[0]);
        src += bytesPerPixel;
    }
    return SkSwizzler::kOpaque_ResultAlpha;
}

// kBGRA

static SkSwizzler::ResultAlpha swizzle_bgra_to_n32_unpremul(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    INIT_RESULT_ALPHA;
    for (int x = 0; x < width; x++) {
        uint8_t alpha = src[3];
        UPDATE_RESULT_ALPHA(alpha);
        dst[x] = SkPackARGB32NoCheck(alpha, src[2], src[1], src[0]);
        src += bytesPerPixel;
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_bgra_to_n32_premul(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    INIT_RESULT_ALPHA;
    for (int x = 0; x < width; x++) {
        uint8_t alpha = src[3];
        UPDATE_RESULT_ALPHA(alpha);
        dst[x] = SkPreMultiplyARGB(alpha, src[2], src[1], src[0]);
        src += bytesPerPixel;
    }
    return COMPUTE_RESULT_ALPHA;
}

// n32
static SkSwizzler::ResultAlpha swizzle_rgbx_to_n32(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    for (int x = 0; x < width; x++) {
        dst[x] = SkPackARGB32(0xFF, src[0], src[1], src[2]);
        src += bytesPerPixel;
    }
    return SkSwizzler::kOpaque_ResultAlpha;
}

static SkSwizzler::ResultAlpha swizzle_rgba_to_n32_premul(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    INIT_RESULT_ALPHA;
    for (int x = 0; x < width; x++) {
        unsigned alpha = src[3];
        UPDATE_RESULT_ALPHA(alpha);
        dst[x] = SkPreMultiplyARGB(alpha, src[0], src[1], src[2]);
        src += bytesPerPixel;
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_rgba_to_n32_unpremul(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    uint32_t* SK_RESTRICT dst = reinterpret_cast<uint32_t*>(dstRow);
    INIT_RESULT_ALPHA;
    for (int x = 0; x < width; x++) {
        unsigned alpha = src[3];
        UPDATE_RESULT_ALPHA(alpha);
        dst[x] = SkPackARGB32NoCheck(alpha, src[0], src[1], src[2]);
        src += bytesPerPixel;
    }
    return COMPUTE_RESULT_ALPHA;
}

static SkSwizzler::ResultAlpha swizzle_rgba_to_n32_premul_skipZ(
        void* SK_RESTRICT dstRow, const uint8_t* SK_RESTRICT src, int width,
        int bytesPerPixel, int y, const SkPMColor ctable[]) {

    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    INIT_RESULT_ALPHA;
    for (int x = 0; x < width; x++) {
        unsigned alpha = src[3];
        UPDATE_RESULT_ALPHA(alpha);
        if (0 != alpha) {
            dst[x] = SkPreMultiplyARGB(alpha, src[0], src[1], src[2]);
        }
        src += bytesPerPixel;
    }
    return COMPUTE_RESULT_ALPHA;
}

/**
    FIXME: This was my idea to cheat in order to continue taking advantage of skipping zeroes.
    This would be fine for drawing normally, but not for drawing with transfer modes. Being
    honest means we can draw correctly with transfer modes, with the cost of not being able
    to take advantage of Android's free unwritten pages. Something to keep in mind when we
    decide whether to switch to unpremul default.
static bool swizzle_rgba_to_n32_unpremul_skipZ(void* SK_RESTRICT dstRow,
                                               const uint8_t* SK_RESTRICT src,
                                               int width, int bitsPerPixel,
                                               const SkPMColor[]) {
    SkPMColor* SK_RESTRICT dst = (SkPMColor*)dstRow;
    unsigned alphaMask = 0xFF;
    for (int x = 0; x < width; x++) {
        unsigned alpha = src[3];
        // NOTE: We cheat here. The caller requested unpremul and skip zeroes. It's possible
        // the color components are not zero, but we skip them anyway, meaning they'll remain
        // zero (implied by the request to skip zeroes).
        if (0 != alpha) {
            dst[x] = SkPackARGB32NoCheck(alpha, src[0], src[1], src[2]);
        }
        src += deltaSrc;
        alphaMask &= alpha;
    }
    return alphaMask != 0xFF;
}
*/

SkSwizzler* SkSwizzler::CreateSwizzler(SkSwizzler::SrcConfig sc,
                                       const SkPMColor* ctable,
                                       const SkImageInfo& info, void* dst,
                                       size_t dstRowBytes,
                                       SkCodec::ZeroInitialized zeroInit) {
    if (info.colorType() == kUnknown_SkColorType || kUnknown == sc) {
        return NULL;
    }
    if (info.minRowBytes() > dstRowBytes) {
        return  NULL;
    }
    if ((kIndex == sc || kIndex4 == sc || kIndex2 == sc || kIndex1 == sc)
            && NULL == ctable) {
        return NULL;
    }
    RowProc proc = NULL;
    switch (sc) {
        case kIndex1:
        case kIndex2:
        case kIndex4:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    proc = &swizzle_small_index_to_n32;
                    break;
>>>>>>> miniblink49
                case kIndex_8_SkColorType:
                    proc = &swizzle_small_index_to_index;
                    break;
                default:
<<<<<<< HEAD
                    return nullptr;
                }
                break;
            case 8:
                switch (dstInfo.colorType()) {
                case kRGBA_8888_SkColorType:
                case kBGRA_8888_SkColorType:
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &swizzle_index_to_n32_skipZ;
                    } else {
                        proc = &swizzle_index_to_n32;
                    }
                    break;
                case kRGB_565_SkColorType:
                    proc = &swizzle_index_to_565;
                    break;
                case kIndex_8_SkColorType:
                    proc = &sample1;
                    fastProc = &copy;
                    break;
                default:
                    return nullptr;
                }
                break;
            default:
                return nullptr;
            }
            break;
        case SkEncodedInfo::kRGB_Color:
            switch (dstInfo.colorType()) {
            case kRGBA_8888_SkColorType:
                proc = &swizzle_rgb_to_rgba;
                fastProc = &fast_swizzle_rgb_to_rgba;
                break;
            case kBGRA_8888_SkColorType:
                proc = &swizzle_rgb_to_bgra;
                fastProc = &fast_swizzle_rgb_to_bgra;
                break;
            case kRGB_565_SkColorType:
                proc = &swizzle_rgb_to_565;
                break;
            default:
                return nullptr;
            }
            break;
        case SkEncodedInfo::kRGBA_Color:
            switch (dstInfo.colorType()) {
            case kRGBA_8888_SkColorType:
                if (premultiply) {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeading8888ZerosThen<swizzle_rgba_to_rgba_premul>;
                        fastProc = &SkipLeading8888ZerosThen<fast_swizzle_rgba_to_rgba_premul>;
                    } else {
                        proc = &swizzle_rgba_to_rgba_premul;
                        fastProc = &fast_swizzle_rgba_to_rgba_premul;
                    }
                } else {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeading8888ZerosThen<sample4>;
                        fastProc = &SkipLeading8888ZerosThen<copy>;
                    } else {
                        proc = &sample4;
                        fastProc = &copy;
                    }
                }
                break;
            case kBGRA_8888_SkColorType:
                if (premultiply) {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeading8888ZerosThen<swizzle_rgba_to_bgra_premul>;
                        fastProc = &SkipLeading8888ZerosThen<fast_swizzle_rgba_to_bgra_premul>;
                    } else {
                        proc = &swizzle_rgba_to_bgra_premul;
                        fastProc = &fast_swizzle_rgba_to_bgra_premul;
                    }
                } else {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeading8888ZerosThen<swizzle_rgba_to_bgra_unpremul>;
                        fastProc = &SkipLeading8888ZerosThen<fast_swizzle_rgba_to_bgra_unpremul>;
                    } else {
                        proc = &swizzle_rgba_to_bgra_unpremul;
                        fastProc = &fast_swizzle_rgba_to_bgra_unpremul;
                    }
                }
                break;
            default:
                return nullptr;
            }
            break;
        case SkEncodedInfo::kBGR_Color:
            switch (dstInfo.colorType()) {
            case kBGRA_8888_SkColorType:
                proc = &swizzle_rgb_to_rgba;
                fastProc = &fast_swizzle_rgb_to_rgba;
                break;
            case kRGBA_8888_SkColorType:
                proc = &swizzle_rgb_to_bgra;
                fastProc = &fast_swizzle_rgb_to_bgra;
                break;
            case kRGB_565_SkColorType:
                proc = &swizzle_bgr_to_565;
                break;
            default:
                return nullptr;
            }
            break;
        case SkEncodedInfo::kBGRX_Color:
            switch (dstInfo.colorType()) {
            case kBGRA_8888_SkColorType:
                proc = &swizzle_rgb_to_rgba;
                break;
            case kRGBA_8888_SkColorType:
                proc = &swizzle_rgb_to_bgra;
                break;
            case kRGB_565_SkColorType:
                proc = &swizzle_bgr_to_565;
                break;
            default:
                return nullptr;
            }
            break;
        case SkEncodedInfo::kBGRA_Color:
            switch (dstInfo.colorType()) {
            case kBGRA_8888_SkColorType:
                if (premultiply) {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeading8888ZerosThen<swizzle_rgba_to_rgba_premul>;
                        fastProc = &SkipLeading8888ZerosThen<fast_swizzle_rgba_to_rgba_premul>;
                    } else {
                        proc = &swizzle_rgba_to_rgba_premul;
                        fastProc = &fast_swizzle_rgba_to_rgba_premul;
                    }
                } else {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeading8888ZerosThen<sample4>;
                        fastProc = &SkipLeading8888ZerosThen<copy>;
                    } else {
                        proc = &sample4;
                        fastProc = &copy;
                    }
                }
                break;
            case kRGBA_8888_SkColorType:
                if (premultiply) {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeading8888ZerosThen<swizzle_rgba_to_bgra_premul>;
                        fastProc = &SkipLeading8888ZerosThen<fast_swizzle_rgba_to_bgra_premul>;
                    } else {
                        proc = &swizzle_rgba_to_bgra_premul;
                        fastProc = &fast_swizzle_rgba_to_bgra_premul;
                    }
                } else {
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &SkipLeading8888ZerosThen<swizzle_rgba_to_bgra_unpremul>;
                        fastProc = &SkipLeading8888ZerosThen<fast_swizzle_rgba_to_bgra_unpremul>;
                    } else {
                        proc = &swizzle_rgba_to_bgra_unpremul;
                        fastProc = &fast_swizzle_rgba_to_bgra_unpremul;
                    }
                }
                break;
            default:
                return nullptr;
            }
            break;
        case SkEncodedInfo::kInvertedCMYK_Color:
            switch (dstInfo.colorType()) {
            case kRGBA_8888_SkColorType:
                proc = &swizzle_cmyk_to_rgba;
                fastProc = &fast_swizzle_cmyk_to_rgba;
                break;
            case kBGRA_8888_SkColorType:
                proc = &swizzle_cmyk_to_bgra;
                fastProc = &fast_swizzle_cmyk_to_bgra;
                break;
            case kRGB_565_SkColorType:
                proc = &swizzle_cmyk_to_565;
                break;
            default:
                return nullptr;
            }
            break;
        default:
            return nullptr;
        }
    }

    int srcBPP;
    const int dstBPP = SkColorTypeBytesPerPixel(dstInfo.colorType());
    if (preSwizzled) {
        srcBPP = dstBPP;
    } else {
        // Store bpp in bytes if it is an even multiple, otherwise use bits
        uint8_t bitsPerPixel = encodedInfo.bitsPerPixel();
        srcBPP = SkIsAlign8(bitsPerPixel) ? bitsPerPixel / 8 : bitsPerPixel;
    }

    int srcOffset = 0;
    int srcWidth = dstInfo.width();
    int dstOffset = 0;
    int dstWidth = srcWidth;
    if (options.fSubset) {
        // We do not currently support subset decodes for image types that may have
        // frames (gif).
        SkASSERT(!frame);
        srcOffset = options.fSubset->left();
        srcWidth = options.fSubset->width();
        dstWidth = srcWidth;
    } else if (frame) {
        dstOffset = frame->left();
        srcWidth = frame->width();
    }

    return new SkSwizzler(fastProc, proc, ctable, srcOffset, srcWidth, dstOffset, dstWidth,
        srcBPP, dstBPP);
}

SkSwizzler::SkSwizzler(RowProc fastProc, RowProc proc, const SkPMColor* ctable, int srcOffset,
    int srcWidth, int dstOffset, int dstWidth, int srcBPP, int dstBPP)
    : fFastProc(fastProc)
    , fSlowProc(proc)
    , fActualProc(fFastProc ? fFastProc : fSlowProc)
    , fColorTable(ctable)
    , fSrcOffset(srcOffset)
    , fDstOffset(dstOffset)
    , fSrcOffsetUnits(srcOffset * srcBPP)
    , fDstOffsetBytes(dstOffset * dstBPP)
    , fSrcWidth(srcWidth)
    , fDstWidth(dstWidth)
    , fSwizzleWidth(srcWidth)
    , fAllocatedWidth(dstWidth)
    , fSampleX(1)
    , fSrcBPP(srcBPP)
    , fDstBPP(dstBPP)
{
}

int SkSwizzler::onSetSampleX(int sampleX)
{
    SkASSERT(sampleX > 0);

    fSampleX = sampleX;
    fSrcOffsetUnits = (get_start_coord(sampleX) + fSrcOffset) * fSrcBPP;
    fDstOffsetBytes = (fDstOffset / sampleX) * fDstBPP;
    fSwizzleWidth = get_scaled_dimension(fSrcWidth, sampleX);
    fAllocatedWidth = get_scaled_dimension(fDstWidth, sampleX);

    // The optimized swizzler functions do not support sampling.  Sampled swizzles
    // are already fast because they skip pixels.  We haven't seen a situation
    // where speeding up sampling has a significant impact on total decode time.
    if (1 == fSampleX && fFastProc) {
        fActualProc = fFastProc;
    } else {
        fActualProc = fSlowProc;
    }

    return fAllocatedWidth;
}

void SkSwizzler::swizzle(void* dst, const uint8_t* SK_RESTRICT src)
{
    SkASSERT(nullptr != dst && nullptr != src);
    fActualProc(SkTAddOffset<void>(dst, fDstOffsetBytes), src, fSwizzleWidth, fSrcBPP,
        fSampleX * fSrcBPP, fSrcOffsetUnits, fColorTable);
=======
                    break;
            }
            break;
        case kIndex:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    // We assume the color premultiplied ctable (or not) as desired.
                    if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                        proc = &swizzle_index_to_n32_skipZ;
                        break;
                    } else {
                        proc = &swizzle_index_to_n32;
                        break;
                    }
                    break;
                case kIndex_8_SkColorType:
                    proc = &swizzle_index_to_index;
                    break;
                default:
                    break;
            }
            break;
        case kGray:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    proc = &swizzle_gray_to_n32;
                    break;
                case kGray_8_SkColorType:
                    proc = &swizzle_gray_to_gray;
                default:
                    break;
            }
            break;
        case kBGR:
        case kBGRX:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    proc = &swizzle_bgrx_to_n32;
                    break;
                default:
                    break;
            }
            break;
        case kBGRA:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    switch (info.alphaType()) {
                        case kUnpremul_SkAlphaType:
                            proc = &swizzle_bgra_to_n32_unpremul;
                            break;
                        case kPremul_SkAlphaType:
                            proc = &swizzle_bgra_to_n32_premul;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case kRGBX:
            // TODO: Support other swizzles.
            switch (info.colorType()) {
                case kN32_SkColorType:
                    proc = &swizzle_rgbx_to_n32;
                    break;
                default:
                    break;
            }
            break;
        case kRGBA:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    if (info.alphaType() == kUnpremul_SkAlphaType) {
                        // Respect zeroInit?
                        proc = &swizzle_rgba_to_n32_unpremul;
                    } else {
                        if (SkCodec::kYes_ZeroInitialized == zeroInit) {
                            proc = &swizzle_rgba_to_n32_premul_skipZ;
                        } else {
                            proc = &swizzle_rgba_to_n32_premul;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        case kRGB:
            switch (info.colorType()) {
                case kN32_SkColorType:
                    proc = &swizzle_rgbx_to_n32;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    if (NULL == proc) {
        return NULL;
    }

    // Store deltaSrc in bytes if it is an even multiple, otherwise use bits
    int deltaSrc = SkIsAlign8(BitsPerPixel(sc)) ? BytesPerPixel(sc) :
            BitsPerPixel(sc);
    return SkNEW_ARGS(SkSwizzler, (proc, ctable, deltaSrc, info, dst,
                                   dstRowBytes));
}

SkSwizzler::SkSwizzler(RowProc proc, const SkPMColor* ctable,
                       int deltaSrc, const SkImageInfo& info, void* dst,
                       size_t rowBytes)
    : fRowProc(proc)
    , fColorTable(ctable)
    , fDeltaSrc(deltaSrc)
    , fDstInfo(info)
    , fDstRow(dst)
    , fDstRowBytes(rowBytes)
    , fCurrY(0)
{
    SkDEBUGCODE(fNextMode = kUninitialized_NextMode);
}

SkSwizzler::ResultAlpha SkSwizzler::next(const uint8_t* SK_RESTRICT src) {
    SkASSERT(0 <= fCurrY && fCurrY < fDstInfo.height());
    SkASSERT(fDstRow != NULL);
    SkASSERT(kDesignateRow_NextMode != fNextMode);
    SkDEBUGCODE(fNextMode = kConsecutive_NextMode);

    // Decode a row
    const ResultAlpha result = fRowProc(fDstRow, src, fDstInfo.width(),
            fDeltaSrc, fCurrY, fColorTable);

    // Move to the next row and return the result
    fCurrY++;
    fDstRow = SkTAddOffset<void>(fDstRow, fDstRowBytes);
    return result;
}

SkSwizzler::ResultAlpha SkSwizzler::next(const uint8_t* SK_RESTRICT src,
        int y) {
    SkASSERT(0 <= y && y < fDstInfo.height());
    SkASSERT(kConsecutive_NextMode != fNextMode);
    SkDEBUGCODE(fNextMode = kDesignateRow_NextMode);
    
    // Choose the row
    void* row = SkTAddOffset<void>(fDstRow, y*fDstRowBytes);

    // Decode the row
    return fRowProc(row, src, fDstInfo.width(), fDeltaSrc, fCurrY,
            fColorTable);
}

void SkSwizzler::Fill(void* dstStartRow, const SkImageInfo& dstInfo, size_t dstRowBytes,
        uint32_t numRows, uint32_t colorOrIndex, const SkPMColor* colorTable) {
    SkASSERT(dstStartRow != NULL);
    SkASSERT(numRows <= (uint32_t) dstInfo.height());

    // Calculate bytes to fill.  We use getSafeSize since the last row may not be padded.
    const size_t bytesToFill = dstInfo.makeWH(dstInfo.width(), numRows).getSafeSize(dstRowBytes);

    // Use the proper memset routine to fill the remaining bytes
    switch(dstInfo.colorType()) {
        case kN32_SkColorType:
            // Assume input is an index if we have a color table
            uint32_t color;
            if (NULL != colorTable) {
                SkASSERT(colorOrIndex == (uint8_t) colorOrIndex);
                color = colorTable[colorOrIndex];
            // Otherwise, assume the input is a color
            } else {
                color = colorOrIndex;
            }

            // We must fill row by row in the case of unaligned row bytes
            if (SkIsAlign4((size_t) dstStartRow) && SkIsAlign4(dstRowBytes)) {
                sk_memset32((uint32_t*) dstStartRow, color,
                        (uint32_t) bytesToFill / sizeof(SkPMColor));
            } else {
                // This is an unlikely, slow case
                SkCodecPrintf("Warning: Strange number of row bytes, fill will be slow.\n");
                uint32_t* dstRow = (uint32_t*) dstStartRow;
                for (uint32_t row = 0; row < numRows; row++) {
                    for (int32_t col = 0; col < dstInfo.width(); col++) {
                        dstRow[col] = color;
                    }
                    dstRow = SkTAddOffset<uint32_t>(dstRow, dstRowBytes);
                }
            }
            break;
        // On an index destination color type, always assume the input is an index
        case kIndex_8_SkColorType:
            SkASSERT(colorOrIndex == (uint8_t) colorOrIndex);
            memset(dstStartRow, colorOrIndex, bytesToFill);
            break;
        case kGray_8_SkColorType:
            // If the destination is kGray, the caller passes in an 8-bit color.
            // We will not assert that the high bits of colorOrIndex must be zeroed.
            // This allows us to take advantage of the fact that the low 8 bits of an
            // SKPMColor may be a valid a grayscale color.  For example, the low 8
            // bits of SK_ColorBLACK are identical to the grayscale representation
            // for black. 
            memset(dstStartRow, (uint8_t) colorOrIndex, bytesToFill);
            break;
        default:
            SkCodecPrintf("Error: Unsupported dst color type for fill().  Doing nothing.\n");
            SkASSERT(false);
            break;
    }
>>>>>>> miniblink49
}
