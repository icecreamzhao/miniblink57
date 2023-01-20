/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/DragImage.h"

#include "platform/fonts/FontDescription.h"
#include "platform/fonts/FontTraits.h"
#include "platform/geometry/IntSize.h"
#include "platform/graphics/BitmapImage.h"
#include "platform/graphics/Image.h"
<<<<<<< HEAD
#include "platform/graphics/skia/SkiaUtils.h"
#include "platform/weborigin/KURL.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "third_party/skia/include/core/SkColor.h"
#include "third_party/skia/include/core/SkImage.h"
#include "third_party/skia/include/core/SkPixelRef.h"
#include "third_party/skia/include/core/SkSurface.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"
#include <memory>
=======
#include "platform/weborigin/KURL.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkColor.h"
#include "third_party/skia/include/core/SkPixelRef.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"
#include <gtest/gtest.h>
>>>>>>> miniblink49

namespace blink {

class TestImage : public Image {
public:
<<<<<<< HEAD
    static PassRefPtr<TestImage> create(sk_sp<SkImage> image)
    {
        return adoptRef(new TestImage(image));
    }
=======
>>>>>>> miniblink49

    static PassRefPtr<TestImage> create(const IntSize& size)
    {
        return adoptRef(new TestImage(size));
    }

<<<<<<< HEAD
    IntSize size() const override
    {
        ASSERT(m_image);

        return IntSize(m_image->width(), m_image->height());
    }

    sk_sp<SkImage> imageForCurrentFrame(const ColorBehavior&) override
    {
        return m_image;
    }

    bool currentFrameKnownToBeOpaque(MetadataMode = UseCurrentMetadata) override
=======
    explicit TestImage(const IntSize& size)
        : Image(0)
        , m_size(size)
    {
        m_bitmap.allocN32Pixels(size.width(), size.height());
        m_bitmap.eraseColor(SK_ColorTRANSPARENT);
    }

    IntSize size() const override
    {
        return m_size;
    }

    bool bitmapForCurrentFrame(SkBitmap* bitmap) override
    {
        if (m_size.isZero())
            return false;

        *bitmap = m_bitmap;
        return true;
    }

    // Stub implementations of pure virtual Image functions.
    void destroyDecodedData(bool) override
    {
    }

    bool currentFrameKnownToBeOpaque() override
>>>>>>> miniblink49
    {
        return false;
    }

<<<<<<< HEAD
    void destroyDecodedData() override
    {
        // Image pure virtual stub.
    }

    void draw(SkCanvas*,
        const SkPaint&,
        const FloatRect&,
        const FloatRect&,
        RespectImageOrientationEnum,
        ImageClampingMode,
        const ColorBehavior&) override
    {
        // Image pure virtual stub.
    }

private:
    explicit TestImage(sk_sp<SkImage> image)
        : m_image(image)
    {
    }

    explicit TestImage(IntSize size)
        : m_image(nullptr)
    {
        sk_sp<SkSurface> surface = createSkSurface(size);
        if (!surface)
            return;

        surface->getCanvas()->clear(SK_ColorTRANSPARENT);
        m_image = surface->makeImageSnapshot();
    }

    static sk_sp<SkSurface> createSkSurface(IntSize size)
    {
        return SkSurface::MakeRaster(
            SkImageInfo::MakeN32(size.width(), size.height(), kPremul_SkAlphaType));
    }

    sk_sp<SkImage> m_image;
=======
    void draw(SkCanvas*, const SkPaint&, const FloatRect&, const FloatRect&, RespectImageOrientationEnum, ImageClampingMode) override
    {
    }

private:
    IntSize m_size;
    SkBitmap m_bitmap;
>>>>>>> miniblink49
};

TEST(DragImageTest, NullHandling)
{
    EXPECT_FALSE(DragImage::create(0));

    RefPtr<TestImage> nullTestImage(TestImage::create(IntSize()));
    EXPECT_FALSE(DragImage::create(nullTestImage.get()));
}

TEST(DragImageTest, NonNullHandling)
{
    RefPtr<TestImage> testImage(TestImage::create(IntSize(2, 2)));
<<<<<<< HEAD
    std::unique_ptr<DragImage> dragImage = DragImage::create(testImage.get());
=======
    OwnPtr<DragImage> dragImage = DragImage::create(testImage.get());
>>>>>>> miniblink49
    ASSERT_TRUE(dragImage);

    dragImage->scale(0.5, 0.5);
    IntSize size = dragImage->size();
    EXPECT_EQ(1, size.width());
    EXPECT_EQ(1, size.height());
<<<<<<< HEAD
=======

    dragImage->dissolveToFraction(0.5);
>>>>>>> miniblink49
}

TEST(DragImageTest, CreateDragImage)
{
<<<<<<< HEAD
    // Tests that the DrageImage implementation doesn't choke on null values
    // of imageForCurrentFrame().
    // FIXME: how is this test any different from test NullHandling?
    RefPtr<TestImage> testImage(TestImage::create(IntSize()));
    EXPECT_FALSE(DragImage::create(testImage.get()));
=======
    {
        // Tests that the DrageImage implementation doesn't choke on null values
        // of bitmapForCurrentFrame().
        RefPtr<TestImage> testImage(TestImage::create(IntSize()));
        EXPECT_FALSE(DragImage::create(testImage.get()));
    }

    {
        // Tests that the drag image is a deep copy.
        RefPtr<TestImage> testImage(TestImage::create(IntSize(1, 1)));
        OwnPtr<DragImage> dragImage = DragImage::create(testImage.get());
        ASSERT_TRUE(dragImage);
        SkBitmap bitmap;
        EXPECT_TRUE(testImage->bitmapForCurrentFrame(&bitmap));
        SkAutoLockPixels lock1(dragImage->bitmap()), lock2(bitmap);
        EXPECT_NE(dragImage->bitmap().getPixels(), bitmap.getPixels());
    }
>>>>>>> miniblink49
}

TEST(DragImageTest, TrimWhitespace)
{
    KURL url(ParsedURLString, "http://www.example.com/");
    String testLabel = "          Example Example Example      \n    ";
    String expectedLabel = "Example Example Example";
    float deviceScaleFactor = 1.0f;

    FontDescription fontDescription;
    fontDescription.firstFamily().setFamily("Arial");
    fontDescription.setSpecifiedSize(16);
    fontDescription.setIsAbsoluteSize(true);
    fontDescription.setGenericFamily(FontDescription::NoFamily);
    fontDescription.setWeight(FontWeightNormal);
    fontDescription.setStyle(FontStyleNormal);

<<<<<<< HEAD
    std::unique_ptr<DragImage> testImage = DragImage::create(url, testLabel, fontDescription, deviceScaleFactor);
    std::unique_ptr<DragImage> expectedImage = DragImage::create(url, expectedLabel, fontDescription, deviceScaleFactor);
=======
    OwnPtr<DragImage> testImage =
        DragImage::create(url, testLabel, fontDescription, deviceScaleFactor);
    OwnPtr<DragImage> expectedImage =
        DragImage::create(url, expectedLabel, fontDescription, deviceScaleFactor);
>>>>>>> miniblink49

    EXPECT_EQ(testImage->size().width(), expectedImage->size().width());
}

// SkPixelRef which fails to lock, as a lazy pixel ref might if its pixels
// cannot be generated.
class InvalidPixelRef : public SkPixelRef {
public:
<<<<<<< HEAD
    InvalidPixelRef(const SkImageInfo& info)
        : SkPixelRef(info)
    {
    }

=======
    InvalidPixelRef(const SkImageInfo& info) : SkPixelRef(info) { }
>>>>>>> miniblink49
private:
    bool onNewLockPixels(LockRec*) override { return false; }
    void onUnlockPixels() override { ASSERT_NOT_REACHED(); }
};

TEST(DragImageTest, InvalidRotatedBitmapImage)
{
    // This test is mostly useful with MSAN builds, which can actually detect
    // the use of uninitialized memory.

    // Create a BitmapImage which will fail to produce pixels, and hence not
    // draw.
    SkImageInfo info = SkImageInfo::MakeN32Premul(100, 100);
<<<<<<< HEAD
    sk_sp<SkPixelRef> pixelRef(new InvalidPixelRef(info));
    SkBitmap invalidBitmap;
    invalidBitmap.setInfo(info);
    invalidBitmap.setPixelRef(pixelRef.get());
    RefPtr<BitmapImage> image = BitmapImage::createWithOrientationForTesting(
        invalidBitmap, OriginRightTop);
=======
    RefPtr<SkPixelRef> pixelRef = adoptRef(new InvalidPixelRef(info));
    SkBitmap invalidBitmap;
    invalidBitmap.setInfo(info);
    invalidBitmap.setPixelRef(pixelRef.get());
    RefPtr<BitmapImage> image = BitmapImage::createWithOrientationForTesting(invalidBitmap, OriginRightTop);
>>>>>>> miniblink49

    // Create a DragImage from it. In MSAN builds, this will cause a failure if
    // the pixel memory is not initialized, if we have to respect non-default
    // orientation.
<<<<<<< HEAD
    std::unique_ptr<DragImage> dragImage = DragImage::create(image.get(), RespectImageOrientation);

    // With an invalid pixel ref, BitmapImage should have no backing SkImage =>
    // we don't allocate a DragImage.
    ASSERT_FALSE(dragImage);
=======
    OwnPtr<DragImage> dragImage = DragImage::create(image.get(), RespectImageOrientation);

    // The DragImage should be fully transparent.
    const SkBitmap& dragImageBitmap = dragImage->bitmap();
    SkAutoLockPixels lock(dragImageBitmap);
    ASSERT_NE(nullptr, dragImageBitmap.getPixels());
    for (int x = 0; x < dragImageBitmap.width(); x++) {
        for (int y = 0; y < dragImageBitmap.height(); y++) {
            int alpha = SkColorGetA(dragImageBitmap.getColor(x, y));
            ASSERT_EQ(0, alpha);
        }
    }
>>>>>>> miniblink49
}

TEST(DragImageTest, InterpolationNone)
{
    SkBitmap expectedBitmap;
    expectedBitmap.allocN32Pixels(4, 4);
    {
        SkAutoLockPixels lock(expectedBitmap);
        expectedBitmap.eraseArea(SkIRect::MakeXYWH(0, 0, 2, 2), 0xFFFFFFFF);
        expectedBitmap.eraseArea(SkIRect::MakeXYWH(0, 2, 2, 2), 0xFF000000);
        expectedBitmap.eraseArea(SkIRect::MakeXYWH(2, 0, 2, 2), 0xFF000000);
        expectedBitmap.eraseArea(SkIRect::MakeXYWH(2, 2, 2, 2), 0xFFFFFFFF);
    }

<<<<<<< HEAD
    SkBitmap testBitmap;
    testBitmap.allocN32Pixels(2, 2);
=======
    RefPtr<TestImage> testImage(TestImage::create(IntSize(2, 2)));
    SkBitmap testBitmap;
    EXPECT_TRUE(testImage->bitmapForCurrentFrame(&testBitmap));
>>>>>>> miniblink49
    {
        SkAutoLockPixels lock(testBitmap);
        testBitmap.eraseArea(SkIRect::MakeXYWH(0, 0, 1, 1), 0xFFFFFFFF);
        testBitmap.eraseArea(SkIRect::MakeXYWH(0, 1, 1, 1), 0xFF000000);
        testBitmap.eraseArea(SkIRect::MakeXYWH(1, 0, 1, 1), 0xFF000000);
        testBitmap.eraseArea(SkIRect::MakeXYWH(1, 1, 1, 1), 0xFFFFFFFF);
    }

<<<<<<< HEAD
    RefPtr<TestImage> testImage = TestImage::create(SkImage::MakeFromBitmap(testBitmap));
    std::unique_ptr<DragImage> dragImage = DragImage::create(
        testImage.get(), DoNotRespectImageOrientation, 1, InterpolationNone);
=======
    OwnPtr<DragImage> dragImage = DragImage::create(testImage.get(), DoNotRespectImageOrientation, 1, InterpolationNone);
>>>>>>> miniblink49
    ASSERT_TRUE(dragImage);
    dragImage->scale(2, 2);
    const SkBitmap& dragBitmap = dragImage->bitmap();
    {
        SkAutoLockPixels lock1(dragBitmap);
        SkAutoLockPixels lock2(expectedBitmap);
        for (int x = 0; x < dragBitmap.width(); ++x)
            for (int y = 0; y < dragBitmap.height(); ++y)
                EXPECT_EQ(expectedBitmap.getColor(x, y), dragBitmap.getColor(x, y));
    }
}

} // namespace blink
