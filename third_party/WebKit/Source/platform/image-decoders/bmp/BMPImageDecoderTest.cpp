// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "platform/image-decoders/bmp/BMPImageDecoder.h"

#include "platform/SharedBuffer.h"
#include "platform/image-decoders/ImageDecoderTestHelpers.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "wtf/PtrUtil.h"
#include <memory>
=======
#include "config.h"
#include "platform/image-decoders/bmp/BMPImageDecoder.h"

#include "platform/SharedBuffer.h"
#include "public/platform/WebUnitTestSupport.h"
#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    std::unique_ptr<ImageDecoder> createDecoder()
    {
        return WTF::wrapUnique(
            new BMPImageDecoder(ImageDecoder::AlphaNotPremultiplied,
                ColorBehavior::transformToTargetForTesting(),
                ImageDecoder::noDecodedImageByteLimit));
    }
=======
PassRefPtr<SharedBuffer> readFile(const char* fileName)
{
    String filePath = Platform::current()->unitTestSupport()->webKitRootDir();
    filePath.append(fileName);

    return Platform::current()->unitTestSupport()->readFromFile(filePath);
}

PassOwnPtr<BMPImageDecoder> createDecoder()
{
    return adoptPtr(new BMPImageDecoder(ImageSource::AlphaNotPremultiplied, ImageSource::GammaAndColorProfileApplied, ImageDecoder::noDecodedImageByteLimit));
}
>>>>>>> miniblink49

} // anonymous namespace

TEST(BMPImageDecoderTest, isSizeAvailable)
{
<<<<<<< HEAD
    const char* bmpFile = "/LayoutTests/images/resources/lenna.bmp"; // 256x256
    RefPtr<SharedBuffer> data = readFile(bmpFile);
    ASSERT_TRUE(data.get());

    std::unique_ptr<ImageDecoder> decoder = createDecoder();
=======
    const char* bmpFile = "/LayoutTests/fast/images/resources/lenna.bmp"; // 256x256
    RefPtr<SharedBuffer> data = readFile(bmpFile);
    ASSERT_TRUE(data.get());

    OwnPtr<BMPImageDecoder> decoder = createDecoder();
>>>>>>> miniblink49
    decoder->setData(data.get(), true);
    EXPECT_TRUE(decoder->isSizeAvailable());
    EXPECT_EQ(256, decoder->size().width());
    EXPECT_EQ(256, decoder->size().height());
}

TEST(BMPImageDecoderTest, parseAndDecode)
{
<<<<<<< HEAD
    const char* bmpFile = "/LayoutTests/images/resources/lenna.bmp"; // 256x256
    RefPtr<SharedBuffer> data = readFile(bmpFile);
    ASSERT_TRUE(data.get());

    std::unique_ptr<ImageDecoder> decoder = createDecoder();
=======
    const char* bmpFile = "/LayoutTests/fast/images/resources/lenna.bmp"; // 256x256
    RefPtr<SharedBuffer> data = readFile(bmpFile);
    ASSERT_TRUE(data.get());

    OwnPtr<BMPImageDecoder> decoder = createDecoder();
>>>>>>> miniblink49
    decoder->setData(data.get(), true);

    ImageFrame* frame = decoder->frameBufferAtIndex(0);
    ASSERT_TRUE(frame);
<<<<<<< HEAD
    EXPECT_EQ(ImageFrame::FrameComplete, frame->getStatus());
    EXPECT_EQ(256, frame->bitmap().width());
    EXPECT_EQ(256, frame->bitmap().height());
=======
    EXPECT_EQ(ImageFrame::FrameComplete, frame->status());
    EXPECT_EQ(256, frame->getSkBitmap().width());
    EXPECT_EQ(256, frame->getSkBitmap().height());
>>>>>>> miniblink49
    EXPECT_FALSE(decoder->failed());
}

// Test if a BMP decoder returns a proper error while decoding an empty image.
TEST(BMPImageDecoderTest, emptyImage)
{
<<<<<<< HEAD
    const char* bmpFile = "/LayoutTests/images/resources/0x0.bmp"; // 0x0
    RefPtr<SharedBuffer> data = readFile(bmpFile);
    ASSERT_TRUE(data.get());

    std::unique_ptr<ImageDecoder> decoder = createDecoder();
=======
    const char* bmpFile = "/LayoutTests/fast/images/resources/0x0.bmp"; // 0x0
    RefPtr<SharedBuffer> data = readFile(bmpFile);
    ASSERT_TRUE(data.get());

    OwnPtr<BMPImageDecoder> decoder = createDecoder();
>>>>>>> miniblink49
    decoder->setData(data.get(), true);

    ImageFrame* frame = decoder->frameBufferAtIndex(0);
    ASSERT_TRUE(frame);
<<<<<<< HEAD
    EXPECT_EQ(ImageFrame::FrameEmpty, frame->getStatus());
    EXPECT_TRUE(decoder->failed());
}

TEST(BMPImageDecoderTest, int32MinHeight)
{
    const char* bmpFile = "/LayoutTests/images/resources/1xint32_min.bmp"; // 0xINT32_MIN
    RefPtr<SharedBuffer> data = readFile(bmpFile);
    std::unique_ptr<ImageDecoder> decoder = createDecoder();
    // Test when not all data is received.
    decoder->setData(data.get(), false);
    EXPECT_FALSE(decoder->isSizeAvailable());
    EXPECT_TRUE(decoder->failed());
}

// This test verifies that calling SharedBuffer::mergeSegmentsIntoBuffer() does
// not break BMP decoding at a critical point: in between a call to decode the
// size (when BMPImageDecoder stops while it may still have input data to
// read) and a call to do a full decode.
TEST(BMPImageDecoderTest, mergeBuffer)
{
    const char* bmpFile = "/LayoutTests/images/resources/lenna.bmp";
    testMergeBuffer(&createDecoder, bmpFile);
}

=======
    EXPECT_EQ(ImageFrame::FrameEmpty, frame->status());
    EXPECT_TRUE(decoder->failed());
}

>>>>>>> miniblink49
} // namespace blink
