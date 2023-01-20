/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Resources.h"
<<<<<<< HEAD
#include "SkAnnotationKeys.h"
#include "SkCanvas.h"
#include "SkFixed.h"
#include "SkFontDescriptor.h"
#include "SkImage.h"
#include "SkImageSource.h"
#include "SkLightingShader.h"
=======
#include "SkBitmapSource.h"
#include "SkCanvas.h"
#include "SkFixed.h"
#include "SkFontDescriptor.h"
>>>>>>> miniblink49
#include "SkMallocPixelRef.h"
#include "SkOSFile.h"
#include "SkPictureRecorder.h"
#include "SkTableColorFilter.h"
#include "SkTemplates.h"
#include "SkTypeface.h"
<<<<<<< HEAD
#include "SkValidatingReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkXfermodeImageFilter.h"
#include "Test.h"
#include "sk_tool_utils.h"
=======
#include "SkWriteBuffer.h"
#include "SkValidatingReadBuffer.h"
#include "SkXfermodeImageFilter.h"
#include "Test.h"
>>>>>>> miniblink49

static const uint32_t kArraySize = 64;
static const int kBitmapSize = 256;

<<<<<<< HEAD
template <typename T>
static void TestAlignment(T* testObj, skiatest::Reporter* reporter)
{
=======
template<typename T>
static void TestAlignment(T* testObj, skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    // Test memory read/write functions directly
    unsigned char dataWritten[1024];
    size_t bytesWrittenToMemory = testObj->writeToMemory(dataWritten);
    REPORTER_ASSERT(reporter, SkAlign4(bytesWrittenToMemory) == bytesWrittenToMemory);
    size_t bytesReadFromMemory = testObj->readFromMemory(dataWritten, bytesWrittenToMemory);
    REPORTER_ASSERT(reporter, SkAlign4(bytesReadFromMemory) == bytesReadFromMemory);
}

<<<<<<< HEAD
template <typename T>
struct SerializationUtils {
    // Generic case for flattenables
    static void Write(SkWriteBuffer& writer, const T* flattenable)
    {
        writer.writeFlattenable(flattenable);
    }
    static void Read(SkValidatingReadBuffer& reader, T** flattenable)
    {
=======
template<typename T> struct SerializationUtils {
    // Generic case for flattenables
    static void Write(SkWriteBuffer& writer, const T* flattenable) {
        writer.writeFlattenable(flattenable);
    }
    static void Read(SkValidatingReadBuffer& reader, T** flattenable) {
>>>>>>> miniblink49
        *flattenable = (T*)reader.readFlattenable(T::GetFlattenableType());
    }
};

<<<<<<< HEAD
template <>
struct SerializationUtils<SkMatrix> {
    static void Write(SkWriteBuffer& writer, const SkMatrix* matrix)
    {
        writer.writeMatrix(*matrix);
    }
    static void Read(SkValidatingReadBuffer& reader, SkMatrix* matrix)
    {
=======
template<> struct SerializationUtils<SkMatrix> {
    static void Write(SkWriteBuffer& writer, const SkMatrix* matrix) {
        writer.writeMatrix(*matrix);
    }
    static void Read(SkValidatingReadBuffer& reader, SkMatrix* matrix) {
>>>>>>> miniblink49
        reader.readMatrix(matrix);
    }
};

<<<<<<< HEAD
template <>
struct SerializationUtils<SkPath> {
    static void Write(SkWriteBuffer& writer, const SkPath* path)
    {
        writer.writePath(*path);
    }
    static void Read(SkValidatingReadBuffer& reader, SkPath* path)
    {
=======
template<> struct SerializationUtils<SkPath> {
    static void Write(SkWriteBuffer& writer, const SkPath* path) {
        writer.writePath(*path);
    }
    static void Read(SkValidatingReadBuffer& reader, SkPath* path) {
>>>>>>> miniblink49
        reader.readPath(path);
    }
};

<<<<<<< HEAD
template <>
struct SerializationUtils<SkRegion> {
    static void Write(SkWriteBuffer& writer, const SkRegion* region)
    {
        writer.writeRegion(*region);
    }
    static void Read(SkValidatingReadBuffer& reader, SkRegion* region)
    {
=======
template<> struct SerializationUtils<SkRegion> {
    static void Write(SkWriteBuffer& writer, const SkRegion* region) {
        writer.writeRegion(*region);
    }
    static void Read(SkValidatingReadBuffer& reader, SkRegion* region) {
>>>>>>> miniblink49
        reader.readRegion(region);
    }
};

<<<<<<< HEAD
template <>
struct SerializationUtils<SkString> {
    static void Write(SkWriteBuffer& writer, const SkString* string)
    {
        writer.writeString(string->c_str());
    }
    static void Read(SkValidatingReadBuffer& reader, SkString* string)
    {
=======
template<> struct SerializationUtils<SkString> {
    static void Write(SkWriteBuffer& writer, const SkString* string) {
        writer.writeString(string->c_str());
    }
    static void Read(SkValidatingReadBuffer& reader, SkString* string) {
>>>>>>> miniblink49
        reader.readString(string);
    }
};

<<<<<<< HEAD
template <>
struct SerializationUtils<unsigned char> {
    static void Write(SkWriteBuffer& writer, unsigned char* data, uint32_t arraySize)
    {
        writer.writeByteArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, unsigned char* data, uint32_t arraySize)
    {
=======
template<> struct SerializationUtils<unsigned char> {
    static void Write(SkWriteBuffer& writer, unsigned char* data, uint32_t arraySize) {
        writer.writeByteArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, unsigned char* data, uint32_t arraySize) {
>>>>>>> miniblink49
        return reader.readByteArray(data, arraySize);
    }
};

<<<<<<< HEAD
template <>
struct SerializationUtils<SkColor> {
    static void Write(SkWriteBuffer& writer, SkColor* data, uint32_t arraySize)
    {
        writer.writeColorArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, SkColor* data, uint32_t arraySize)
    {
=======
template<> struct SerializationUtils<SkColor> {
    static void Write(SkWriteBuffer& writer, SkColor* data, uint32_t arraySize) {
        writer.writeColorArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, SkColor* data, uint32_t arraySize) {
>>>>>>> miniblink49
        return reader.readColorArray(data, arraySize);
    }
};

<<<<<<< HEAD
template <>
struct SerializationUtils<int32_t> {
    static void Write(SkWriteBuffer& writer, int32_t* data, uint32_t arraySize)
    {
        writer.writeIntArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, int32_t* data, uint32_t arraySize)
    {
=======
template<> struct SerializationUtils<int32_t> {
    static void Write(SkWriteBuffer& writer, int32_t* data, uint32_t arraySize) {
        writer.writeIntArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, int32_t* data, uint32_t arraySize) {
>>>>>>> miniblink49
        return reader.readIntArray(data, arraySize);
    }
};

<<<<<<< HEAD
template <>
struct SerializationUtils<SkPoint> {
    static void Write(SkWriteBuffer& writer, SkPoint* data, uint32_t arraySize)
    {
        writer.writePointArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, SkPoint* data, uint32_t arraySize)
    {
=======
template<> struct SerializationUtils<SkPoint> {
    static void Write(SkWriteBuffer& writer, SkPoint* data, uint32_t arraySize) {
        writer.writePointArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, SkPoint* data, uint32_t arraySize) {
>>>>>>> miniblink49
        return reader.readPointArray(data, arraySize);
    }
};

<<<<<<< HEAD
template <>
struct SerializationUtils<SkScalar> {
    static void Write(SkWriteBuffer& writer, SkScalar* data, uint32_t arraySize)
    {
        writer.writeScalarArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, SkScalar* data, uint32_t arraySize)
    {
=======
template<> struct SerializationUtils<SkScalar> {
    static void Write(SkWriteBuffer& writer, SkScalar* data, uint32_t arraySize) {
        writer.writeScalarArray(data, arraySize);
    }
    static bool Read(SkValidatingReadBuffer& reader, SkScalar* data, uint32_t arraySize) {
>>>>>>> miniblink49
        return reader.readScalarArray(data, arraySize);
    }
};

<<<<<<< HEAD
template <typename T, bool testInvalid>
struct SerializationTestUtils {
    static void InvalidateData(unsigned char* data) { }
};

template <>
struct SerializationTestUtils<SkString, true> {
    static void InvalidateData(unsigned char* data)
    {
=======
template<typename T, bool testInvalid> struct SerializationTestUtils {
    static void InvalidateData(unsigned char* data) {}
};

template<> struct SerializationTestUtils<SkString, true> {
    static void InvalidateData(unsigned char* data) {
>>>>>>> miniblink49
        data[3] |= 0x80; // Reverse sign of 1st integer
    }
};

<<<<<<< HEAD
template <typename T, bool testInvalid>
static void TestObjectSerializationNoAlign(T* testObj, skiatest::Reporter* reporter)
{
    SkBinaryWriteBuffer writer;
=======
template<typename T, bool testInvalid>
static void TestObjectSerializationNoAlign(T* testObj, skiatest::Reporter* reporter) {
    SkWriteBuffer writer(SkWriteBuffer::kValidation_Flag);
>>>>>>> miniblink49
    SerializationUtils<T>::Write(writer, testObj);
    size_t bytesWritten = writer.bytesWritten();
    REPORTER_ASSERT(reporter, SkAlign4(bytesWritten) == bytesWritten);

    unsigned char dataWritten[1024];
    writer.writeToMemory(dataWritten);

    SerializationTestUtils<T, testInvalid>::InvalidateData(dataWritten);

    // Make sure this fails when it should (test with smaller size, but still multiple of 4)
    SkValidatingReadBuffer buffer(dataWritten, bytesWritten - 4);
    T obj;
    SerializationUtils<T>::Read(buffer, &obj);
    REPORTER_ASSERT(reporter, !buffer.isValid());

    // Make sure this succeeds when it should
    SkValidatingReadBuffer buffer2(dataWritten, bytesWritten);
    const unsigned char* peekBefore = static_cast<const unsigned char*>(buffer2.skip(0));
    T obj2;
    SerializationUtils<T>::Read(buffer2, &obj2);
    const unsigned char* peekAfter = static_cast<const unsigned char*>(buffer2.skip(0));
    // This should have succeeded, since there are enough bytes to read this
    REPORTER_ASSERT(reporter, buffer2.isValid() == !testInvalid);
    // Note: This following test should always succeed, regardless of whether the buffer is valid,
    // since if it is invalid, it will simply skip to the end, as if it had read the whole buffer.
    REPORTER_ASSERT(reporter, static_cast<size_t>(peekAfter - peekBefore) == bytesWritten);
}

<<<<<<< HEAD
template <typename T>
static void TestObjectSerialization(T* testObj, skiatest::Reporter* reporter)
{
=======
template<typename T>
static void TestObjectSerialization(T* testObj, skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    TestObjectSerializationNoAlign<T, false>(testObj, reporter);
    TestAlignment(testObj, reporter);
}

<<<<<<< HEAD
template <typename T>
static T* TestFlattenableSerialization(T* testObj, bool shouldSucceed,
    skiatest::Reporter* reporter)
{
    SkBinaryWriteBuffer writer;
=======
template<typename T>
static T* TestFlattenableSerialization(T* testObj, bool shouldSucceed,
                                       skiatest::Reporter* reporter) {
    SkWriteBuffer writer(SkWriteBuffer::kValidation_Flag);
>>>>>>> miniblink49
    SerializationUtils<T>::Write(writer, testObj);
    size_t bytesWritten = writer.bytesWritten();
    REPORTER_ASSERT(reporter, SkAlign4(bytesWritten) == bytesWritten);

<<<<<<< HEAD
    SkASSERT(bytesWritten <= 4096);
    unsigned char dataWritten[4096];
=======
    unsigned char dataWritten[4096];
    SkASSERT(bytesWritten <= sizeof(dataWritten));
>>>>>>> miniblink49
    writer.writeToMemory(dataWritten);

    // Make sure this fails when it should (test with smaller size, but still multiple of 4)
    SkValidatingReadBuffer buffer(dataWritten, bytesWritten - 4);
<<<<<<< HEAD
    T* obj = nullptr;
    SerializationUtils<T>::Read(buffer, &obj);
    REPORTER_ASSERT(reporter, !buffer.isValid());
    REPORTER_ASSERT(reporter, nullptr == obj);
=======
    T* obj = NULL;
    SerializationUtils<T>::Read(buffer, &obj);
    REPORTER_ASSERT(reporter, !buffer.isValid());
    REPORTER_ASSERT(reporter, NULL == obj);
>>>>>>> miniblink49

    // Make sure this succeeds when it should
    SkValidatingReadBuffer buffer2(dataWritten, bytesWritten);
    const unsigned char* peekBefore = static_cast<const unsigned char*>(buffer2.skip(0));
<<<<<<< HEAD
    T* obj2 = nullptr;
=======
    T* obj2 = NULL;
>>>>>>> miniblink49
    SerializationUtils<T>::Read(buffer2, &obj2);
    const unsigned char* peekAfter = static_cast<const unsigned char*>(buffer2.skip(0));
    if (shouldSucceed) {
        // This should have succeeded, since there are enough bytes to read this
        REPORTER_ASSERT(reporter, buffer2.isValid());
        REPORTER_ASSERT(reporter, static_cast<size_t>(peekAfter - peekBefore) == bytesWritten);
        REPORTER_ASSERT(reporter, obj2);
    } else {
        // If the deserialization was supposed to fail, make sure it did
        REPORTER_ASSERT(reporter, !buffer.isValid());
<<<<<<< HEAD
        REPORTER_ASSERT(reporter, nullptr == obj2);
=======
        REPORTER_ASSERT(reporter, NULL == obj2);
>>>>>>> miniblink49
    }

    return obj2; // Return object to perform further validity tests on it
}

<<<<<<< HEAD
template <typename T>
static void TestArraySerialization(T* data, skiatest::Reporter* reporter)
{
    SkBinaryWriteBuffer writer;
=======
template<typename T>
static void TestArraySerialization(T* data, skiatest::Reporter* reporter) {
    SkWriteBuffer writer(SkWriteBuffer::kValidation_Flag);
>>>>>>> miniblink49
    SerializationUtils<T>::Write(writer, data, kArraySize);
    size_t bytesWritten = writer.bytesWritten();
    // This should write the length (in 4 bytes) and the array
    REPORTER_ASSERT(reporter, (4 + kArraySize * sizeof(T)) == bytesWritten);

    unsigned char dataWritten[1024];
    writer.writeToMemory(dataWritten);

    // Make sure this fails when it should
    SkValidatingReadBuffer buffer(dataWritten, bytesWritten);
    T dataRead[kArraySize];
    bool success = SerializationUtils<T>::Read(buffer, dataRead, kArraySize / 2);
    // This should have failed, since the provided size was too small
    REPORTER_ASSERT(reporter, !success);

    // Make sure this succeeds when it should
    SkValidatingReadBuffer buffer2(dataWritten, bytesWritten);
    success = SerializationUtils<T>::Read(buffer2, dataRead, kArraySize);
    // This should have succeeded, since there are enough bytes to read this
    REPORTER_ASSERT(reporter, success);
}

static void TestBitmapSerialization(const SkBitmap& validBitmap,
<<<<<<< HEAD
    const SkBitmap& invalidBitmap,
    bool shouldSucceed,
    skiatest::Reporter* reporter)
{
    sk_sp<SkImage> validImage(SkImage::MakeFromBitmap(validBitmap));
    sk_sp<SkImageFilter> validBitmapSource(SkImageSource::Make(std::move(validImage)));
    sk_sp<SkImage> invalidImage(SkImage::MakeFromBitmap(invalidBitmap));
    sk_sp<SkImageFilter> invalidBitmapSource(SkImageSource::Make(std::move(invalidImage)));
    sk_sp<SkImageFilter> xfermodeImageFilter(
        SkXfermodeImageFilter::Make(SkXfermode::Make(SkXfermode::kSrcOver_Mode),
            std::move(invalidBitmapSource),
            std::move(validBitmapSource), nullptr));

    SkAutoTUnref<SkImageFilter> deserializedFilter(
        TestFlattenableSerialization<SkImageFilter>(
            xfermodeImageFilter.get(), shouldSucceed, reporter));
=======
                                    const SkBitmap& invalidBitmap,
                                    bool shouldSucceed,
                                    skiatest::Reporter* reporter) {
    SkAutoTUnref<SkBitmapSource> validBitmapSource(SkBitmapSource::Create(validBitmap));
    SkAutoTUnref<SkBitmapSource> invalidBitmapSource(SkBitmapSource::Create(invalidBitmap));
    SkAutoTUnref<SkXfermode> mode(SkXfermode::Create(SkXfermode::kSrcOver_Mode));
    SkAutoTUnref<SkXfermodeImageFilter> xfermodeImageFilter(
        SkXfermodeImageFilter::Create(mode, invalidBitmapSource, validBitmapSource));

    SkAutoTUnref<SkImageFilter> deserializedFilter(
        TestFlattenableSerialization<SkImageFilter>(
            xfermodeImageFilter, shouldSucceed, reporter));
>>>>>>> miniblink49

    // Try to render a small bitmap using the invalid deserialized filter
    // to make sure we don't crash while trying to render it
    if (shouldSucceed) {
        SkBitmap bitmap;
        bitmap.allocN32Pixels(24, 24);
        SkCanvas canvas(bitmap);
        canvas.clear(0x00000000);
        SkPaint paint;
        paint.setImageFilter(deserializedFilter);
        canvas.clipRect(SkRect::MakeXYWH(0, 0, SkIntToScalar(24), SkIntToScalar(24)));
        canvas.drawBitmap(bitmap, 0, 0, &paint);
    }
}

<<<<<<< HEAD
static void TestXfermodeSerialization(skiatest::Reporter* reporter)
{
    for (size_t i = 0; i <= SkXfermode::kLastMode; ++i) {
        if (i == SkXfermode::kSrcOver_Mode) {
            // skip SrcOver, as it is allowed to return nullptr from Create()
            continue;
        }
        auto mode(SkXfermode::Make(static_cast<SkXfermode::Mode>(i)));
        REPORTER_ASSERT(reporter, mode);
=======
static void TestXfermodeSerialization(skiatest::Reporter* reporter) {
    for (size_t i = 0; i <= SkXfermode::kLastMode; ++i) {
        if (i == SkXfermode::kSrcOver_Mode) {
            // skip SrcOver, as it is allowed to return NULL from Create()
            continue;
        }
        SkAutoTUnref<SkXfermode> mode(SkXfermode::Create(static_cast<SkXfermode::Mode>(i)));
        REPORTER_ASSERT(reporter, mode.get());
>>>>>>> miniblink49
        SkAutoTUnref<SkXfermode> copy(
            TestFlattenableSerialization<SkXfermode>(mode.get(), true, reporter));
    }
}

<<<<<<< HEAD
static void TestColorFilterSerialization(skiatest::Reporter* reporter)
{
=======
static void TestColorFilterSerialization(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    uint8_t table[256];
    for (int i = 0; i < 256; ++i) {
        table[i] = (i * 41) % 256;
    }
<<<<<<< HEAD
    auto colorFilter(SkTableColorFilter::Make(table));
=======
    SkAutoTUnref<SkColorFilter> colorFilter(SkTableColorFilter::Create(table));
>>>>>>> miniblink49
    SkAutoTUnref<SkColorFilter> copy(
        TestFlattenableSerialization<SkColorFilter>(colorFilter.get(), true, reporter));
}

<<<<<<< HEAD
static SkBitmap draw_picture(SkPicture& picture)
{
    SkBitmap bitmap;
    bitmap.allocN32Pixels(SkScalarCeilToInt(picture.cullRect().width()),
        SkScalarCeilToInt(picture.cullRect().height()));
    SkCanvas canvas(bitmap);
    picture.playback(&canvas);
    return bitmap;
}

static void compare_bitmaps(skiatest::Reporter* reporter,
    const SkBitmap& b1, const SkBitmap& b2)
{
=======
static SkBitmap draw_picture(SkPicture& picture) {
     SkBitmap bitmap;
     bitmap.allocN32Pixels(SkScalarCeilToInt(picture.cullRect().width()), 
                           SkScalarCeilToInt(picture.cullRect().height()));
     SkCanvas canvas(bitmap);
     picture.playback(&canvas);
     return bitmap;
}

static void compare_bitmaps(skiatest::Reporter* reporter,
                            const SkBitmap& b1, const SkBitmap& b2) {
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, b1.width() == b2.width());
    REPORTER_ASSERT(reporter, b1.height() == b2.height());
    SkAutoLockPixels autoLockPixels1(b1);
    SkAutoLockPixels autoLockPixels2(b2);

<<<<<<< HEAD
    if ((b1.width() != b2.width()) || (b1.height() != b2.height())) {
=======
    if ((b1.width() != b2.width()) ||
        (b1.height() != b2.height())) {
>>>>>>> miniblink49
        return;
    }

    int pixelErrors = 0;
    for (int y = 0; y < b2.height(); ++y) {
        for (int x = 0; x < b2.width(); ++x) {
            if (b1.getColor(x, y) != b2.getColor(x, y))
                ++pixelErrors;
        }
    }
    REPORTER_ASSERT(reporter, 0 == pixelErrors);
}
<<<<<<< HEAD
static void serialize_and_compare_typeface(sk_sp<SkTypeface> typeface, const char* text,
    skiatest::Reporter* reporter)
=======
static void serialize_and_compare_typeface(SkTypeface* typeface, const char* text,
                                           skiatest::Reporter* reporter)
>>>>>>> miniblink49
{
    // Create a paint with the typeface.
    SkPaint paint;
    paint.setColor(SK_ColorGRAY);
    paint.setTextSize(SkIntToScalar(30));
<<<<<<< HEAD
    paint.setTypeface(std::move(typeface));
=======
    paint.setTypeface(typeface);
>>>>>>> miniblink49

    // Paint some text.
    SkPictureRecorder recorder;
    SkIRect canvasRect = SkIRect::MakeWH(kBitmapSize, kBitmapSize);
<<<<<<< HEAD
    SkCanvas* canvas = recorder.beginRecording(SkIntToScalar(canvasRect.width()),
        SkIntToScalar(canvasRect.height()),
        nullptr, 0);
    canvas->drawColor(SK_ColorWHITE);
    canvas->drawText(text, 2, 24, 32, paint);
    sk_sp<SkPicture> picture(recorder.finishRecordingAsPicture());
=======
    SkCanvas* canvas = recorder.beginRecording(SkIntToScalar(canvasRect.width()), 
                                               SkIntToScalar(canvasRect.height()), 
                                               NULL, 0);
    canvas->drawColor(SK_ColorWHITE);
    canvas->drawText(text, 2, 24, 32, paint);
    SkAutoTUnref<SkPicture> picture(recorder.endRecording());
>>>>>>> miniblink49

    // Serlialize picture and create its clone from stream.
    SkDynamicMemoryWStream stream;
    picture->serialize(&stream);
    SkAutoTDelete<SkStream> inputStream(stream.detachAsStream());
<<<<<<< HEAD
    sk_sp<SkPicture> loadedPicture(SkPicture::MakeFromStream(inputStream.get()));
=======
    SkAutoTUnref<SkPicture> loadedPicture(SkPicture::CreateFromStream(inputStream.get()));
>>>>>>> miniblink49

    // Draw both original and clone picture and compare bitmaps -- they should be identical.
    SkBitmap origBitmap = draw_picture(*picture);
    SkBitmap destBitmap = draw_picture(*loadedPicture);
    compare_bitmaps(reporter, origBitmap, destBitmap);
}

<<<<<<< HEAD
static void TestPictureTypefaceSerialization(skiatest::Reporter* reporter)
{
    {
        // Load typeface from file to test CreateFromFile with index.
        SkString filename = GetResourcePath("/fonts/test.ttc");
        sk_sp<SkTypeface> typeface(SkTypeface::MakeFromFile(filename.c_str(), 1));
        if (!typeface) {
            INFOF(reporter, "Could not run fontstream test because test.ttc not found.");
        } else {
            serialize_and_compare_typeface(std::move(typeface), "A!", reporter);
=======
static void TestPictureTypefaceSerialization(skiatest::Reporter* reporter) {
    {
        // Load typeface from file to test CreateFromFile with index.
        SkString filename = GetResourcePath("/fonts/test.ttc");
        SkAutoTUnref<SkTypeface> typeface(SkTypeface::CreateFromFile(filename.c_str(), 1));
        if (!typeface) {
            SkDebugf("Could not run fontstream test because test.ttc not found.");
        } else {
            serialize_and_compare_typeface(typeface, "A!", reporter);
>>>>>>> miniblink49
        }
    }

    {
        // Load typeface as stream to create with axis settings.
        SkAutoTDelete<SkStreamAsset> distortable(GetResourceAsStream("/fonts/Distortable.ttf"));
        if (!distortable) {
<<<<<<< HEAD
            INFOF(reporter, "Could not run fontstream test because Distortable.ttf not found.");
        } else {
            SkFixed axis = SK_FixedSqrt2;
            sk_sp<SkTypeface> typeface(SkTypeface::MakeFromFontData(
                new SkFontData(distortable.release(), 0, &axis, 1)));
            if (!typeface) {
                INFOF(reporter, "Could not run fontstream test because Distortable.ttf not created.");
            } else {
                serialize_and_compare_typeface(std::move(typeface), "abc", reporter);
=======
            SkDebugf("Could not run fontstream test because Distortable.ttf not found.");
        } else {
            SkFixed axis = SK_FixedSqrt2;
            SkAutoTUnref<SkTypeface> typeface(SkTypeface::CreateFromFontData(
                new SkFontData(distortable.detach(), 0, &axis, 1)));
            if (!typeface) {
                SkDebugf("Could not run fontstream test because Distortable.ttf not created.");
            } else {
                serialize_and_compare_typeface(typeface, "abc", reporter);
>>>>>>> miniblink49
            }
        }
    }
}

<<<<<<< HEAD
static void setup_bitmap_for_canvas(SkBitmap* bitmap)
{
    bitmap->allocN32Pixels(kBitmapSize, kBitmapSize);
}

static void make_checkerboard_bitmap(SkBitmap& bitmap)
{
=======
static void setup_bitmap_for_canvas(SkBitmap* bitmap) {
    bitmap->allocN32Pixels(kBitmapSize, kBitmapSize);
}

static void make_checkerboard_bitmap(SkBitmap& bitmap) {
>>>>>>> miniblink49
    setup_bitmap_for_canvas(&bitmap);

    SkCanvas canvas(bitmap);
    canvas.clear(0x00000000);
    SkPaint darkPaint;
    darkPaint.setColor(0xFF804020);
    SkPaint lightPaint;
    lightPaint.setColor(0xFF244484);
    const int i = kBitmapSize / 8;
    const SkScalar f = SkIntToScalar(i);
    for (int y = 0; y < kBitmapSize; y += i) {
        for (int x = 0; x < kBitmapSize; x += i) {
            canvas.save();
            canvas.translate(SkIntToScalar(x), SkIntToScalar(y));
            canvas.drawRect(SkRect::MakeXYWH(0, 0, f, f), darkPaint);
            canvas.drawRect(SkRect::MakeXYWH(f, 0, f, f), lightPaint);
            canvas.drawRect(SkRect::MakeXYWH(0, f, f, f), lightPaint);
            canvas.drawRect(SkRect::MakeXYWH(f, f, f, f), darkPaint);
            canvas.restore();
        }
    }
}

<<<<<<< HEAD
static void draw_something(SkCanvas* canvas)
{
=======
static void draw_something(SkCanvas* canvas) {
>>>>>>> miniblink49
    SkPaint paint;
    SkBitmap bitmap;
    make_checkerboard_bitmap(bitmap);

    canvas->save();
    canvas->scale(0.5f, 0.5f);
<<<<<<< HEAD
    canvas->drawBitmap(bitmap, 0, 0, nullptr);
=======
    canvas->drawBitmap(bitmap, 0, 0, NULL);
>>>>>>> miniblink49
    canvas->restore();

    paint.setAntiAlias(true);

    paint.setColor(SK_ColorRED);
<<<<<<< HEAD
    canvas->drawCircle(SkIntToScalar(kBitmapSize / 2), SkIntToScalar(kBitmapSize / 2), SkIntToScalar(kBitmapSize / 3), paint);
    paint.setColor(SK_ColorBLACK);
    paint.setTextSize(SkIntToScalar(kBitmapSize / 3));
    canvas->drawText("Picture", 7, SkIntToScalar(kBitmapSize / 2), SkIntToScalar(kBitmapSize / 4), paint);
}

DEF_TEST(Serialization, reporter)
{
=======
    canvas->drawCircle(SkIntToScalar(kBitmapSize/2), SkIntToScalar(kBitmapSize/2), SkIntToScalar(kBitmapSize/3), paint);
    paint.setColor(SK_ColorBLACK);
    paint.setTextSize(SkIntToScalar(kBitmapSize/3));
    canvas->drawText("Picture", 7, SkIntToScalar(kBitmapSize/2), SkIntToScalar(kBitmapSize/4), paint);
}

DEF_TEST(Serialization, reporter) {
>>>>>>> miniblink49
    // Test matrix serialization
    {
        SkMatrix matrix = SkMatrix::I();
        TestObjectSerialization(&matrix, reporter);
    }

    // Test path serialization
    {
        SkPath path;
        TestObjectSerialization(&path, reporter);
    }

    // Test region serialization
    {
        SkRegion region;
        TestObjectSerialization(&region, reporter);
    }

    // Test xfermode serialization
    {
        TestXfermodeSerialization(reporter);
    }

    // Test color filter serialization
    {
        TestColorFilterSerialization(reporter);
    }

    // Test string serialization
    {
        SkString string("string");
        TestObjectSerializationNoAlign<SkString, false>(&string, reporter);
        TestObjectSerializationNoAlign<SkString, true>(&string, reporter);
    }

    // Test rrect serialization
    {
        // SkRRect does not initialize anything.
        // An uninitialized SkRRect can be serialized,
        // but will branch on uninitialized data when deserialized.
        SkRRect rrect;
        SkRect rect = SkRect::MakeXYWH(1, 2, 20, 30);
<<<<<<< HEAD
        SkVector corners[4] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 } };
=======
        SkVector corners[4] = { {1, 2}, {2, 3}, {3,4}, {4,5} };
>>>>>>> miniblink49
        rrect.setRectRadii(rect, corners);
        TestAlignment(&rrect, reporter);
    }

    // Test readByteArray
    {
        unsigned char data[kArraySize] = { 1, 2, 3 };
        TestArraySerialization(data, reporter);
    }

    // Test readColorArray
    {
        SkColor data[kArraySize] = { SK_ColorBLACK, SK_ColorWHITE, SK_ColorRED };
        TestArraySerialization(data, reporter);
    }

    // Test readIntArray
    {
        int32_t data[kArraySize] = { 1, 2, 4, 8 };
        TestArraySerialization(data, reporter);
    }

    // Test readPointArray
    {
<<<<<<< HEAD
        SkPoint data[kArraySize] = { { 6, 7 }, { 42, 128 } };
=======
        SkPoint data[kArraySize] = { {6, 7}, {42, 128} };
>>>>>>> miniblink49
        TestArraySerialization(data, reporter);
    }

    // Test readScalarArray
    {
        SkScalar data[kArraySize] = { SK_Scalar1, SK_ScalarHalf, SK_ScalarMax };
        TestArraySerialization(data, reporter);
    }

    // Test invalid deserializations
    {
        SkImageInfo info = SkImageInfo::MakeN32Premul(kBitmapSize, kBitmapSize);

        SkBitmap validBitmap;
        validBitmap.setInfo(info);

        // Create a bitmap with a really large height
        SkBitmap invalidBitmap;
        invalidBitmap.setInfo(info.makeWH(info.width(), 1000000000));

        // The deserialization should succeed, and the rendering shouldn't crash,
        // even when the device fails to initialize, due to its size
        TestBitmapSerialization(validBitmap, invalidBitmap, true, reporter);
    }

    // Test simple SkPicture serialization
    {
        SkPictureRecorder recorder;
        draw_something(recorder.beginRecording(SkIntToScalar(kBitmapSize),
<<<<<<< HEAD
            SkIntToScalar(kBitmapSize),
            nullptr, 0));
        sk_sp<SkPicture> pict(recorder.finishRecordingAsPicture());

        // Serialize picture
        SkBinaryWriteBuffer writer;
=======
                                               SkIntToScalar(kBitmapSize),
                                               NULL, 0));
        SkAutoTUnref<SkPicture> pict(recorder.endRecording());

        // Serialize picture
        SkWriteBuffer writer(SkWriteBuffer::kValidation_Flag);
>>>>>>> miniblink49
        pict->flatten(writer);
        size_t size = writer.bytesWritten();
        SkAutoTMalloc<unsigned char> data(size);
        writer.writeToMemory(static_cast<void*>(data.get()));

        // Deserialize picture
        SkValidatingReadBuffer reader(static_cast<void*>(data.get()), size);
<<<<<<< HEAD
        sk_sp<SkPicture> readPict(SkPicture::MakeFromBuffer(reader));
=======
        SkAutoTUnref<SkPicture> readPict(
            SkPicture::CreateFromBuffer(reader));
>>>>>>> miniblink49
        REPORTER_ASSERT(reporter, readPict.get());
    }

    TestPictureTypefaceSerialization(reporter);
<<<<<<< HEAD

    // Test SkLightingShader/NormalMapSource serialization
    {
        const int kTexSize = 2;

        SkLights::Builder builder;

        builder.add(SkLights::Light(SkColor3f::Make(1.0f, 1.0f, 1.0f),
            SkVector3::Make(1.0f, 0.0f, 0.0f)));
        builder.add(SkLights::Light(SkColor3f::Make(0.2f, 0.2f, 0.2f)));

        sk_sp<SkLights> fLights = builder.finish();

        SkBitmap diffuse = sk_tool_utils::create_checkerboard_bitmap(
            kTexSize, kTexSize,
            sk_tool_utils::color_to_565(0x0),
            sk_tool_utils::color_to_565(0xFF804020),
            8);

        SkRect bitmapBounds = SkRect::MakeIWH(diffuse.width(), diffuse.height());

        SkMatrix matrix;
        SkRect r = SkRect::MakeWH(SkIntToScalar(kTexSize), SkIntToScalar(kTexSize));
        matrix.setRectToRect(bitmapBounds, r, SkMatrix::kFill_ScaleToFit);

        SkVector invNormRotation = { SkScalarSqrt(0.3f), SkScalarSqrt(0.7f) };
        SkBitmap normals;
        normals.allocN32Pixels(kTexSize, kTexSize);

        sk_tool_utils::create_frustum_normal_map(&normals, SkIRect::MakeWH(kTexSize, kTexSize));
        sk_sp<SkShader> lightingShader = SkLightingShader::Make(diffuse, normals, fLights,
            invNormRotation, &matrix, &matrix);

        SkAutoTUnref<SkShader>(TestFlattenableSerialization(lightingShader.get(), true, reporter));
        // TODO test equality?
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
#include "SkAnnotation.h"

static sk_sp<SkPicture> copy_picture_via_serialization(SkPicture* src)
{
    SkDynamicMemoryWStream wstream;
    src->serialize(&wstream);
    SkAutoTDelete<SkStreamAsset> rstream(wstream.detachAsStream());
    return SkPicture::MakeFromStream(rstream);
}

struct AnnotationRec {
    const SkRect fRect;
    const char* fKey;
    SkData* fValue;
};

class TestAnnotationCanvas : public SkCanvas {
    skiatest::Reporter* fReporter;
    const AnnotationRec* fRec;
    int fCount;
    int fCurrIndex;

public:
    TestAnnotationCanvas(skiatest::Reporter* reporter, const AnnotationRec rec[], int count)
        : SkCanvas(100, 100)
        , fReporter(reporter)
        , fRec(rec)
        , fCount(count)
        , fCurrIndex(0)
    {
    }

    ~TestAnnotationCanvas()
    {
        REPORTER_ASSERT(fReporter, fCount == fCurrIndex);
    }

protected:
    void onDrawAnnotation(const SkRect& rect, const char key[], SkData* value)
    {
        REPORTER_ASSERT(fReporter, fCurrIndex < fCount);
        REPORTER_ASSERT(fReporter, rect == fRec[fCurrIndex].fRect);
        REPORTER_ASSERT(fReporter, !strcmp(key, fRec[fCurrIndex].fKey));
        REPORTER_ASSERT(fReporter, value->equals(fRec[fCurrIndex].fValue));
        fCurrIndex += 1;
    }
};

/*
 *  Test the 3 annotation types by recording them into a picture, serializing, and then playing
 *  them back into another canvas.
 */
DEF_TEST(Annotations, reporter)
{
    SkPictureRecorder recorder;
    SkCanvas* recordingCanvas = recorder.beginRecording(SkRect::MakeWH(100, 100));

    const char* str0 = "rect-with-url";
    const SkRect r0 = SkRect::MakeWH(10, 10);
    SkAutoTUnref<SkData> d0(SkData::NewWithCString(str0));
    SkAnnotateRectWithURL(recordingCanvas, r0, d0);

    const char* str1 = "named-destination";
    const SkRect r1 = SkRect::MakeXYWH(5, 5, 0, 0); // collapsed to a point
    SkAutoTUnref<SkData> d1(SkData::NewWithCString(str1));
    SkAnnotateNamedDestination(recordingCanvas, { r1.x(), r1.y() }, d1);

    const char* str2 = "link-to-destination";
    const SkRect r2 = SkRect::MakeXYWH(20, 20, 5, 6);
    SkAutoTUnref<SkData> d2(SkData::NewWithCString(str2));
    SkAnnotateLinkToDestination(recordingCanvas, r2, d2);

    const AnnotationRec recs[] = {
        { r0, SkAnnotationKeys::URL_Key(), d0 },
        { r1, SkAnnotationKeys::Define_Named_Dest_Key(), d1 },
        { r2, SkAnnotationKeys::Link_Named_Dest_Key(), d2 },
    };

    sk_sp<SkPicture> pict0(recorder.finishRecordingAsPicture());
    sk_sp<SkPicture> pict1(copy_picture_via_serialization(pict0.get()));

    TestAnnotationCanvas canvas(reporter, recs, SK_ARRAY_COUNT(recs));
    canvas.drawPicture(pict1);
=======
>>>>>>> miniblink49
}
