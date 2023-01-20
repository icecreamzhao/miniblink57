
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkWriteBuffer_DEFINED
#define SkWriteBuffer_DEFINED

<<<<<<< HEAD
#include "../private/SkTHash.h"
#include "SkData.h"
#include "SkImage.h"
=======
#include "SkData.h"
>>>>>>> miniblink49
#include "SkPath.h"
#include "SkPicture.h"
#include "SkPixelSerializer.h"
#include "SkRefCnt.h"
#include "SkWriter32.h"

class SkBitmap;
<<<<<<< HEAD
class SkFactorySet;
class SkFlattenable;
=======
class SkBitmapHeap;
class SkFactorySet;
class SkFlattenable;
class SkNamedFactorySet;
>>>>>>> miniblink49
class SkRefCntSet;

class SkWriteBuffer {
public:
<<<<<<< HEAD
    SkWriteBuffer() { }
    virtual ~SkWriteBuffer() { }

    virtual bool isCrossProcess() const = 0;

    virtual void writeByteArray(const void* data, size_t size) = 0;
    void writeDataAsByteArray(SkData* data)
    {
        this->writeByteArray(data->data(), data->size());
    }
    virtual void writeBool(bool value) = 0;
    virtual void writeScalar(SkScalar value) = 0;
    virtual void writeScalarArray(const SkScalar* value, uint32_t count) = 0;
    virtual void writeInt(int32_t value) = 0;
    virtual void writeIntArray(const int32_t* value, uint32_t count) = 0;
    virtual void writeUInt(uint32_t value) = 0;
    void write32(int32_t value)
    {
        this->writeInt(value);
    }
    virtual void writeString(const char* value) = 0;

    virtual void writeFlattenable(const SkFlattenable* flattenable) = 0;
    virtual void writeColor(SkColor color) = 0;
    virtual void writeColorArray(const SkColor* color, uint32_t count) = 0;
    virtual void writePoint(const SkPoint& point) = 0;
    virtual void writePointArray(const SkPoint* point, uint32_t count) = 0;
    virtual void writeMatrix(const SkMatrix& matrix) = 0;
    virtual void writeIRect(const SkIRect& rect) = 0;
    virtual void writeRect(const SkRect& rect) = 0;
    virtual void writeRegion(const SkRegion& region) = 0;
    virtual void writePath(const SkPath& path) = 0;
    virtual size_t writeStream(SkStream* stream, size_t length) = 0;
    virtual void writeBitmap(const SkBitmap& bitmap) = 0;
    virtual void writeImage(const SkImage*) = 0;
    virtual void writeTypeface(SkTypeface* typeface) = 0;
    virtual void writePaint(const SkPaint& paint) = 0;
};

/**
 * Concrete implementation that serializes to a flat binary blob.
 */
class SkBinaryWriteBuffer final : public SkWriteBuffer {
public:
    enum Flags {
        kCrossProcess_Flag = 1 << 0,
    };

    SkBinaryWriteBuffer(uint32_t flags = 0);
    SkBinaryWriteBuffer(void* initialStorage, size_t storageSize, uint32_t flags = 0);
    ~SkBinaryWriteBuffer();

    bool isCrossProcess() const override
    {
        return SkToBool(fFlags & kCrossProcess_Flag);
    }

    void reset(void* storage = NULL, size_t storageSize = 0)
    {
        fWriter.reset(storage, storageSize);
    }

    size_t bytesWritten() const { return fWriter.bytesWritten(); }

    void writeByteArray(const void* data, size_t size) override;
    void writeBool(bool value) override;
    void writeScalar(SkScalar value) override;
    void writeScalarArray(const SkScalar* value, uint32_t count) override;
    void writeInt(int32_t value) override;
    void writeIntArray(const int32_t* value, uint32_t count) override;
    void writeUInt(uint32_t value) override;
    void writeString(const char* value) override;

    void writeFlattenable(const SkFlattenable* flattenable) override;
    void writeColor(SkColor color) override;
    void writeColorArray(const SkColor* color, uint32_t count) override;
    void writePoint(const SkPoint& point) override;
    void writePointArray(const SkPoint* point, uint32_t count) override;
    void writeMatrix(const SkMatrix& matrix) override;
    void writeIRect(const SkIRect& rect) override;
    void writeRect(const SkRect& rect) override;
    void writeRegion(const SkRegion& region) override;
    void writePath(const SkPath& path) override;
    size_t writeStream(SkStream* stream, size_t length) override;
    void writeBitmap(const SkBitmap& bitmap) override;
    void writeImage(const SkImage*) override;
    void writeTypeface(SkTypeface* typeface) override;
    void writePaint(const SkPaint& paint) override;
=======
    enum Flags {
        kCrossProcess_Flag  = 1 << 0,
        kValidation_Flag    = 1 << 1,
    };

    SkWriteBuffer(uint32_t flags = 0);
    SkWriteBuffer(void* initialStorage, size_t storageSize, uint32_t flags = 0);
    ~SkWriteBuffer();

    bool isCrossProcess() const {
        return this->isValidating() || SkToBool(fFlags & kCrossProcess_Flag);
    }

    SkWriter32* getWriter32() { return &fWriter; }
    void reset(void* storage = NULL, size_t storageSize = 0) {
        fWriter.reset(storage, storageSize);
    }

    uint32_t* reserve(size_t size) { return fWriter.reserve(size); }

    size_t bytesWritten() const { return fWriter.bytesWritten(); }

    void writeByteArray(const void* data, size_t size);
    void writeDataAsByteArray(SkData* data) { this->writeByteArray(data->data(), data->size()); }
    void writeBool(bool value);
    void writeFixed(SkFixed value);
    void writeScalar(SkScalar value);
    void writeScalarArray(const SkScalar* value, uint32_t count);
    void writeInt(int32_t value);
    void writeIntArray(const int32_t* value, uint32_t count);
    void writeUInt(uint32_t value);
    void write32(int32_t value);
    void writeString(const char* value);
    void writeEncodedString(const void* value, size_t byteLength, SkPaint::TextEncoding encoding);
    void writeFunctionPtr(void* ptr) { fWriter.writePtr(ptr); }

    void writeFlattenable(const SkFlattenable* flattenable);
    void writeColor(const SkColor& color);
    void writeColorArray(const SkColor* color, uint32_t count);
    void writePoint(const SkPoint& point);
    void writePointArray(const SkPoint* point, uint32_t count);
    void writeMatrix(const SkMatrix& matrix);
    void writeIRect(const SkIRect& rect);
    void writeRect(const SkRect& rect);
    void writeRegion(const SkRegion& region);
    void writePath(const SkPath& path);
    size_t writeStream(SkStream* stream, size_t length);
    void writeBitmap(const SkBitmap& bitmap);
    void writeImage(const SkImage*);
    void writeTypeface(SkTypeface* typeface);
    void writePaint(const SkPaint& paint) { paint.flatten(*this); }
>>>>>>> miniblink49

    bool writeToStream(SkWStream*);
    void writeToMemory(void* dst) { fWriter.flatten(dst); }

    SkFactorySet* setFactoryRecorder(SkFactorySet*);
<<<<<<< HEAD
    SkRefCntSet* setTypefaceRecorder(SkRefCntSet*);

    /**
=======
    SkNamedFactorySet* setNamedFactoryRecorder(SkNamedFactorySet*);

    SkRefCntSet* getTypefaceRecorder() const { return fTFSet; }
    SkRefCntSet* setTypefaceRecorder(SkRefCntSet*);

    /**
     * Set an SkBitmapHeap to store bitmaps rather than flattening.
     *
     * Incompatible with an SkPixelSerializer. If an SkPixelSerializer is set,
     * setting an SkBitmapHeap will set the SkPixelSerializer to NULL in release
     * and crash in debug.
     */
    void setBitmapHeap(SkBitmapHeap*);

    /**
>>>>>>> miniblink49
     * Set an SkPixelSerializer to store an encoded representation of pixels,
     * e.g. SkBitmaps.
     *
     * Calls ref() on the serializer.
     *
     * TODO: Encode SkImage pixels as well.
<<<<<<< HEAD
=======
     *
     * Incompatible with the SkBitmapHeap. If an encoder is set fBitmapHeap will
     * be set to NULL in release and crash in debug.
>>>>>>> miniblink49
     */
    void setPixelSerializer(SkPixelSerializer*);
    SkPixelSerializer* getPixelSerializer() const { return fPixelSerializer; }

private:
<<<<<<< HEAD
    const uint32_t fFlags;
    SkFactorySet* fFactorySet;
    SkWriter32 fWriter;

    SkRefCntSet* fTFSet;

    SkAutoTUnref<SkPixelSerializer> fPixelSerializer;

    // Only used if we do not have an fFactorySet
    SkTHashMap<SkString, uint32_t> fFlattenableDict;
=======
    bool isValidating() const { return SkToBool(fFlags & kValidation_Flag); }

    const uint32_t fFlags;
    SkFactorySet* fFactorySet;
    SkNamedFactorySet* fNamedFactorySet;
    SkWriter32 fWriter;

    SkBitmapHeap* fBitmapHeap;
    SkRefCntSet* fTFSet;

    SkAutoTUnref<SkPixelSerializer> fPixelSerializer;
>>>>>>> miniblink49
};

#endif // SkWriteBuffer_DEFINED
