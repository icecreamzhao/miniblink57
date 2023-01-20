/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkOpts.h"
#include "SkSwizzle.h"
=======
>>>>>>> miniblink49
#include "SkSwizzler.h"
#include "Test.h"

// These are the values that we will look for to indicate that the fill was successful
<<<<<<< HEAD
static const uint8_t kFillIndex = 0x11;
static const uint8_t kFillGray = 0x22;
static const uint16_t kFill565 = 0x3344;
static const uint32_t kFillColor = 0x55667788;

static void check_fill(skiatest::Reporter* r,
    const SkImageInfo& imageInfo,
    uint32_t startRow,
    uint32_t endRow,
    size_t rowBytes,
    uint32_t offset,
    uint32_t colorOrIndex)
{
=======
static const uint8_t kFillIndex = 0x1;
static const uint32_t kFillColor = 0x22334455;

static void check_fill(skiatest::Reporter* r,
                       const SkImageInfo& imageInfo,
                       uint32_t startRow,
                       uint32_t endRow,
                       size_t rowBytes,
                       uint32_t offset,
                       uint32_t colorOrIndex,
                       SkPMColor* colorTable) {
>>>>>>> miniblink49

    // Calculate the total size of the image in bytes.  Use the smallest possible size.
    // The offset value tells us to adjust the pointer from the memory we allocate in order
    // to test on different memory alignments.  If offset is nonzero, we need to increase the
    // size of the memory we allocate in order to make sure that we have enough.  We are
    // still allocating the smallest possible size.
    const size_t totalBytes = imageInfo.getSafeSize(rowBytes) + offset;

    // Create fake image data where every byte has a value of 0
<<<<<<< HEAD
    SkAutoTDeleteArray<uint8_t> storage(new uint8_t[totalBytes]);
=======
    SkAutoTDeleteArray<uint8_t> storage(SkNEW_ARRAY(uint8_t, totalBytes));
>>>>>>> miniblink49
    memset(storage.get(), 0, totalBytes);
    // Adjust the pointer in order to test on different memory alignments
    uint8_t* imageData = storage.get() + offset;
    uint8_t* imageStart = imageData + rowBytes * startRow;
<<<<<<< HEAD
    const SkImageInfo fillInfo = imageInfo.makeWH(imageInfo.width(), endRow - startRow + 1);
    SkSampler::Fill(fillInfo, imageStart, rowBytes, colorOrIndex, SkCodec::kNo_ZeroInitialized);
=======

    // Fill image with the fill value starting at the indicated row
    SkSwizzler::Fill(imageStart, imageInfo, rowBytes, endRow - startRow + 1, colorOrIndex,
            colorTable);
>>>>>>> miniblink49

    // Ensure that the pixels are filled properly
    // The bots should catch any memory corruption
    uint8_t* indexPtr = imageData + startRow * rowBytes;
    uint8_t* grayPtr = indexPtr;
<<<<<<< HEAD
    uint32_t* colorPtr = (uint32_t*)indexPtr;
    uint16_t* color565Ptr = (uint16_t*)indexPtr;
    for (uint32_t y = startRow; y <= endRow; y++) {
        for (int32_t x = 0; x < imageInfo.width(); x++) {
            switch (imageInfo.colorType()) {
            case kIndex_8_SkColorType:
                REPORTER_ASSERT(r, kFillIndex == indexPtr[x]);
                break;
            case kN32_SkColorType:
                REPORTER_ASSERT(r, kFillColor == colorPtr[x]);
                break;
            case kGray_8_SkColorType:
                REPORTER_ASSERT(r, kFillGray == grayPtr[x]);
                break;
            case kRGB_565_SkColorType:
                REPORTER_ASSERT(r, kFill565 == color565Ptr[x]);
                break;
            default:
                REPORTER_ASSERT(r, false);
                break;
            }
        }
        indexPtr += rowBytes;
        colorPtr = (uint32_t*)indexPtr;
=======
    uint32_t* colorPtr = (uint32_t*) indexPtr;
    for (uint32_t y = startRow; y <= endRow; y++) {
        for (int32_t x = 0; x < imageInfo.width(); x++) {
            switch (imageInfo.colorType()) {
                case kIndex_8_SkColorType:
                    REPORTER_ASSERT(r, kFillIndex == indexPtr[x]);
                    break;
                case kN32_SkColorType:
                    REPORTER_ASSERT(r, kFillColor == colorPtr[x]);
                    break;
                case kGray_8_SkColorType:
                    // We always fill kGray with black
                    REPORTER_ASSERT(r, (uint8_t) kFillColor == grayPtr[x]);
                    break;
                default:
                    REPORTER_ASSERT(r, false);
                    break;
            }
        }
        indexPtr += rowBytes;
        colorPtr = (uint32_t*) indexPtr;
>>>>>>> miniblink49
    }
}

// Test Fill() with different combinations of dimensions, alignment, and padding
<<<<<<< HEAD
DEF_TEST(SwizzlerFill, r)
{
=======
DEF_TEST(SwizzlerFill, r) {
    // Set up a color table
    SkPMColor colorTable[kFillIndex + 1];
    colorTable[kFillIndex] = kFillColor;
    // Apart from the fill index, we will leave the other colors in the color table uninitialized.
    // If we incorrectly try to fill with this uninitialized memory, the bots will catch it.

>>>>>>> miniblink49
    // Test on an invalid width and representative widths
    const uint32_t widths[] = { 0, 10, 50 };

    // In order to call Fill(), there must be at least one row to fill
    // Test on the smallest possible height and representative heights
    const uint32_t heights[] = { 1, 5, 10 };

    // Test on interesting possibilities for row padding
<<<<<<< HEAD
    const uint32_t paddings[] = { 0, 4 };
=======
    const uint32_t paddings[] = { 0, 1, 2, 3, 4 };
>>>>>>> miniblink49

    // Iterate over test dimensions
    for (uint32_t width : widths) {
        for (uint32_t height : heights) {

            // Create image info objects
<<<<<<< HEAD
            const SkImageInfo colorInfo = SkImageInfo::MakeN32(width, height, kUnknown_SkAlphaType);
            const SkImageInfo grayInfo = colorInfo.makeColorType(kGray_8_SkColorType);
            const SkImageInfo indexInfo = colorInfo.makeColorType(kIndex_8_SkColorType);
            const SkImageInfo color565Info = colorInfo.makeColorType(kRGB_565_SkColorType);
=======
            const SkImageInfo colorInfo = SkImageInfo::MakeN32(width, height,
                kUnknown_SkAlphaType);
            const SkImageInfo indexInfo = colorInfo.makeColorType(kIndex_8_SkColorType);
            const SkImageInfo grayInfo = colorInfo.makeColorType(kGray_8_SkColorType);
>>>>>>> miniblink49

            for (uint32_t padding : paddings) {

                // Calculate row bytes
<<<<<<< HEAD
                const size_t colorRowBytes = SkColorTypeBytesPerPixel(kN32_SkColorType) * width
                    + padding;
                const size_t indexRowBytes = width + padding;
                const size_t grayRowBytes = indexRowBytes;
                const size_t color565RowBytes = SkColorTypeBytesPerPixel(kRGB_565_SkColorType) * width + padding;

                // If there is padding, we can invent an offset to change the memory alignment
                for (uint32_t offset = 0; offset <= padding; offset += 4) {
=======
                size_t colorRowBytes = SkColorTypeBytesPerPixel(kN32_SkColorType) * width +
                        padding;
                size_t indexRowBytes = width + padding;
                size_t grayRowBytes = indexRowBytes;

                // If there is padding, we can invent an offset to change the memory alignment
                for (uint32_t offset = 0; offset <= padding; offset++) {
>>>>>>> miniblink49

                    // Test all possible start rows with all possible end rows
                    for (uint32_t startRow = 0; startRow < height; startRow++) {
                        for (uint32_t endRow = startRow; endRow < height; endRow++) {

<<<<<<< HEAD
                            // Test fill with each color type
                            check_fill(r, colorInfo, startRow, endRow, colorRowBytes, offset,
                                kFillColor);
                            check_fill(r, indexInfo, startRow, endRow, indexRowBytes, offset,
                                kFillIndex);
                            check_fill(r, grayInfo, startRow, endRow, grayRowBytes, offset,
                                kFillGray);
                            check_fill(r, color565Info, startRow, endRow, color565RowBytes, offset,
                                kFill565);
=======
                            // Fill with an index that we use to look up a color
                            check_fill(r, colorInfo, startRow, endRow, colorRowBytes, offset,
                                    kFillIndex, colorTable);

                            // Fill with a color
                            check_fill(r, colorInfo, startRow, endRow, colorRowBytes, offset,
                                    kFillColor, NULL);

                            // Fill with an index
                            check_fill(r, indexInfo, startRow, endRow, indexRowBytes, offset,
                                    kFillIndex, NULL);

                            // Fill a grayscale image
                            check_fill(r, grayInfo, startRow, endRow, grayRowBytes, offset,
                                    kFillColor, NULL);
>>>>>>> miniblink49
                        }
                    }
                }
            }
        }
    }
}
<<<<<<< HEAD

DEF_TEST(SwizzleOpts, r)
{
    uint32_t dst, src;

    // forall c, c*255 == c, c*0 == 0
    for (int c = 0; c <= 255; c++) {
        src = (255 << 24) | c;
        SkOpts::RGBA_to_rgbA(&dst, &src, 1);
        REPORTER_ASSERT(r, dst == src);
        SkOpts::RGBA_to_bgrA(&dst, &src, 1);
        REPORTER_ASSERT(r, dst == (uint32_t)((255 << 24) | (c << 16)));

        src = (0 << 24) | c;
        SkOpts::RGBA_to_rgbA(&dst, &src, 1);
        REPORTER_ASSERT(r, dst == 0);
        SkOpts::RGBA_to_bgrA(&dst, &src, 1);
        REPORTER_ASSERT(r, dst == 0);
    }

    // check a totally arbitrary color
    src = 0xFACEB004;
    SkOpts::RGBA_to_rgbA(&dst, &src, 1);
    REPORTER_ASSERT(r, dst == 0xFACAAD04);

    // swap red and blue
    SkOpts::RGBA_to_BGRA(&dst, &src, 1);
    REPORTER_ASSERT(r, dst == 0xFA04B0CE);

    // all together now
    SkOpts::RGBA_to_bgrA(&dst, &src, 1);
    REPORTER_ASSERT(r, dst == 0xFA04ADCA);
}

DEF_TEST(PublicSwizzleOpts, r)
{
    uint32_t dst, src;

    // check a totally arbitrary color
    src = 0xFACEB004;
    SkSwapRB(&dst, &src, 1);
    REPORTER_ASSERT(r, dst == 0xFA04B0CE);
}
=======
>>>>>>> miniblink49
