
/*
 * Copyright 2008 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkWriter32_DEFINED
#define SkWriter32_DEFINED

#include "../private/SkTemplates.h"
=======

#ifndef SkWriter32_DEFINED
#define SkWriter32_DEFINED

>>>>>>> miniblink49
#include "SkData.h"
#include "SkMatrix.h"
#include "SkPath.h"
#include "SkPoint.h"
#include "SkRRect.h"
#include "SkRect.h"
#include "SkRegion.h"
#include "SkScalar.h"
#include "SkStream.h"
<<<<<<< HEAD
=======
#include "SkTemplates.h"
>>>>>>> miniblink49
#include "SkTypes.h"

class SK_API SkWriter32 : SkNoncopyable {
public:
    /**
     *  The caller can specify an initial block of storage, which the caller manages.
     *
     *  SkWriter32 will try to back reserve and write calls with this external storage until the
     *  first time an allocation doesn't fit.  From then it will use dynamically allocated storage.
     *  This used to be optional behavior, but pipe now relies on it.
     */
<<<<<<< HEAD
    SkWriter32(void* external = NULL, size_t externalBytes = 0)
    {
=======
    SkWriter32(void* external = NULL, size_t externalBytes = 0) {
>>>>>>> miniblink49
        this->reset(external, externalBytes);
    }

    // return the current offset (will always be a multiple of 4)
    size_t bytesWritten() const { return fUsed; }

    SK_ATTR_DEPRECATED("use bytesWritten")
    size_t size() const { return this->bytesWritten(); }

<<<<<<< HEAD
    void reset(void* external = NULL, size_t externalBytes = 0)
    {
=======
    void reset(void* external = NULL, size_t externalBytes = 0) {
>>>>>>> miniblink49
        SkASSERT(SkIsAlign4((uintptr_t)external));
        SkASSERT(SkIsAlign4(externalBytes));

        fData = (uint8_t*)external;
        fCapacity = externalBytes;
        fUsed = 0;
        fExternal = external;
    }

<<<<<<< HEAD
    // size MUST be multiple of 4
    uint32_t* reserve(size_t size)
    {
=======
    // Returns the current buffer.
    // The pointer may be invalidated by any future write calls.
    const uint32_t* contiguousArray() const {
        return (uint32_t*)fData;
    }

    // size MUST be multiple of 4
    uint32_t* reserve(size_t size) {
>>>>>>> miniblink49
        SkASSERT(SkAlign4(size) == size);
        size_t offset = fUsed;
        size_t totalRequired = fUsed + size;
        if (totalRequired > fCapacity) {
            this->growToAtLeast(totalRequired);
        }
        fUsed = totalRequired;
        return (uint32_t*)(fData + offset);
    }

    /**
     *  Read a T record at offset, which must be a multiple of 4. Only legal if the record
     *  was written atomically using the write methods below.
     */
<<<<<<< HEAD
    template <typename T>
    const T& readTAt(size_t offset) const
    {
=======
    template<typename T>
    const T& readTAt(size_t offset) const {
>>>>>>> miniblink49
        SkASSERT(SkAlign4(offset) == offset);
        SkASSERT(offset < fUsed);
        return *(T*)(fData + offset);
    }

    /**
     *  Overwrite a T record at offset, which must be a multiple of 4. Only legal if the record
     *  was written atomically using the write methods below.
     */
<<<<<<< HEAD
    template <typename T>
    void overwriteTAt(size_t offset, const T& value)
    {
=======
    template<typename T>
    void overwriteTAt(size_t offset, const T& value) {
>>>>>>> miniblink49
        SkASSERT(SkAlign4(offset) == offset);
        SkASSERT(offset < fUsed);
        *(T*)(fData + offset) = value;
    }

<<<<<<< HEAD
    bool writeBool(bool value)
    {
=======
    bool writeBool(bool value) {
>>>>>>> miniblink49
        this->write32(value);
        return value;
    }

<<<<<<< HEAD
    void writeInt(int32_t value)
    {
        this->write32(value);
    }

    void write8(int32_t value)
    {
        *(int32_t*)this->reserve(sizeof(value)) = value & 0xFF;
    }

    void write16(int32_t value)
    {
        *(int32_t*)this->reserve(sizeof(value)) = value & 0xFFFF;
    }

    void write32(int32_t value)
    {
        *(int32_t*)this->reserve(sizeof(value)) = value;
    }

    void writePtr(void* value)
    {
        *(void**)this->reserve(sizeof(value)) = value;
    }

    void writeScalar(SkScalar value)
    {
        *(SkScalar*)this->reserve(sizeof(value)) = value;
    }

    void writePoint(const SkPoint& pt)
    {
        *(SkPoint*)this->reserve(sizeof(pt)) = pt;
    }

    void writeRect(const SkRect& rect)
    {
        *(SkRect*)this->reserve(sizeof(rect)) = rect;
    }

    void writeIRect(const SkIRect& rect)
    {
        *(SkIRect*)this->reserve(sizeof(rect)) = rect;
    }

    void writeRRect(const SkRRect& rrect)
    {
        rrect.writeToMemory(this->reserve(SkRRect::kSizeInMemory));
    }

    void writePath(const SkPath& path)
    {
=======
    void writeInt(int32_t value) {
        this->write32(value);
    }

    void write8(int32_t value) {
        *(int32_t*)this->reserve(sizeof(value)) = value & 0xFF;
    }

    void write16(int32_t value) {
        *(int32_t*)this->reserve(sizeof(value)) = value & 0xFFFF;
    }

    void write32(int32_t value) {
        *(int32_t*)this->reserve(sizeof(value)) = value;
    }

    void writePtr(void* value) {
        *(void**)this->reserve(sizeof(value)) = value;
    }

    void writeScalar(SkScalar value) {
        *(SkScalar*)this->reserve(sizeof(value)) = value;
    }

    void writePoint(const SkPoint& pt) {
        *(SkPoint*)this->reserve(sizeof(pt)) = pt;
    }

    void writeRect(const SkRect& rect) {
        *(SkRect*)this->reserve(sizeof(rect)) = rect;
    }

    void writeIRect(const SkIRect& rect) {
        *(SkIRect*)this->reserve(sizeof(rect)) = rect;
    }

    void writeRRect(const SkRRect& rrect) {
        rrect.writeToMemory(this->reserve(SkRRect::kSizeInMemory));
    }

    void writePath(const SkPath& path) {
>>>>>>> miniblink49
        size_t size = path.writeToMemory(NULL);
        SkASSERT(SkAlign4(size) == size);
        path.writeToMemory(this->reserve(size));
    }

<<<<<<< HEAD
    void writeMatrix(const SkMatrix& matrix)
    {
=======
    void writeMatrix(const SkMatrix& matrix) {
>>>>>>> miniblink49
        size_t size = matrix.writeToMemory(NULL);
        SkASSERT(SkAlign4(size) == size);
        matrix.writeToMemory(this->reserve(size));
    }

<<<<<<< HEAD
    void writeRegion(const SkRegion& rgn)
    {
=======
    void writeRegion(const SkRegion& rgn) {
>>>>>>> miniblink49
        size_t size = rgn.writeToMemory(NULL);
        SkASSERT(SkAlign4(size) == size);
        rgn.writeToMemory(this->reserve(size));
    }

    // write count bytes (must be a multiple of 4)
<<<<<<< HEAD
    void writeMul4(const void* values, size_t size)
    {
=======
    void writeMul4(const void* values, size_t size) {
>>>>>>> miniblink49
        this->write(values, size);
    }

    /**
     *  Write size bytes from values. size must be a multiple of 4, though
     *  values need not be 4-byte aligned.
     */
<<<<<<< HEAD
    void write(const void* values, size_t size)
    {
        SkASSERT(SkAlign4(size) == size);
        sk_careful_memcpy(this->reserve(size), values, size);
=======
    void write(const void* values, size_t size) {
        SkASSERT(SkAlign4(size) == size);
        memcpy(this->reserve(size), values, size);
>>>>>>> miniblink49
    }

    /**
     *  Reserve size bytes. Does not need to be 4 byte aligned. The remaining space (if any) will be
     *  filled in with zeroes.
     */
<<<<<<< HEAD
    uint32_t* reservePad(size_t size)
    {
=======
    uint32_t* reservePad(size_t size) {
>>>>>>> miniblink49
        size_t alignedSize = SkAlign4(size);
        uint32_t* p = this->reserve(alignedSize);
        if (alignedSize != size) {
            SkASSERT(alignedSize >= 4);
            p[alignedSize / 4 - 1] = 0;
        }
        return p;
    }

    /**
     *  Write size bytes from src, and pad to 4 byte alignment with zeroes.
     */
<<<<<<< HEAD
    void writePad(const void* src, size_t size)
    {
        sk_careful_memcpy(this->reservePad(size), src, size);
=======
    void writePad(const void* src, size_t size) {
        memcpy(this->reservePad(size), src, size);
>>>>>>> miniblink49
    }

    /**
     *  Writes a string to the writer, which can be retrieved with
     *  SkReader32::readString().
     *  The length can be specified, or if -1 is passed, it will be computed by
     *  calling strlen(). The length must be < max size_t.
     *
     *  If you write NULL, it will be read as "".
     */
    void writeString(const char* str, size_t len = (size_t)-1);

    /**
     *  Computes the size (aligned to multiple of 4) need to write the string
     *  in a call to writeString(). If the length is not specified, it will be
     *  computed by calling strlen().
     */
    static size_t WriteStringSize(const char* str, size_t len = (size_t)-1);

<<<<<<< HEAD
    void writeData(const SkData* data)
    {
        uint32_t len = data ? SkToU32(data->size()) : 0;
        this->write32(len);
        if (data) {
            this->writePad(data->data(), len);
        }
    }

    static size_t WriteDataSize(const SkData* data)
    {
        return 4 + SkAlign4(data ? data->size() : 0);
    }

=======
>>>>>>> miniblink49
    /**
     *  Move the cursor back to offset bytes from the beginning.
     *  offset must be a multiple of 4 no greater than size().
     */
<<<<<<< HEAD
    void rewindToOffset(size_t offset)
    {
=======
    void rewindToOffset(size_t offset) {
>>>>>>> miniblink49
        SkASSERT(SkAlign4(offset) == offset);
        SkASSERT(offset <= bytesWritten());
        fUsed = offset;
    }

    // copy into a single buffer (allocated by caller). Must be at least size()
<<<<<<< HEAD
    void flatten(void* dst) const
    {
        memcpy(dst, fData, fUsed);
    }

    bool writeToStream(SkWStream* stream) const
    {
=======
    void flatten(void* dst) const {
        memcpy(dst, fData, fUsed);
    }

    bool writeToStream(SkWStream* stream) const {
>>>>>>> miniblink49
        return stream->write(fData, fUsed);
    }

    // read from the stream, and write up to length bytes. Return the actual
    // number of bytes written.
<<<<<<< HEAD
    size_t readFromStream(SkStream* stream, size_t length)
    {
=======
    size_t readFromStream(SkStream* stream, size_t length) {
>>>>>>> miniblink49
        return stream->read(this->reservePad(length), length);
    }

    /**
     *  Captures a snapshot of the data as it is right now, and return it.
     */
<<<<<<< HEAD
    sk_sp<SkData> snapshotAsData() const;

private:
    void growToAtLeast(size_t size);

    uint8_t* fData; // Points to either fInternal or fExternal.
    size_t fCapacity; // Number of bytes we can write to fData.
    size_t fUsed; // Number of bytes written.
    void* fExternal; // Unmanaged memory block.
    SkAutoTMalloc<uint8_t> fInternal; // Managed memory block.
=======
    SkData* snapshotAsData() const;
private:
    void growToAtLeast(size_t size);

    uint8_t* fData;                    // Points to either fInternal or fExternal.
    size_t fCapacity;                  // Number of bytes we can write to fData.
    size_t fUsed;                      // Number of bytes written.
    void* fExternal;                   // Unmanaged memory block.
    SkAutoTMalloc<uint8_t> fInternal;  // Managed memory block.
>>>>>>> miniblink49
};

/**
 *  Helper class to allocated SIZE bytes as part of the writer, and to provide
 *  that storage to the constructor as its initial storage buffer.
 *
 *  This wrapper ensures proper alignment rules are met for the storage.
 */
<<<<<<< HEAD
template <size_t SIZE>
class SkSWriter32 : public SkWriter32 {
public:
    SkSWriter32() { this->reset(); }

    void reset() { this->INHERITED::reset(fData.fStorage, SIZE); }

private:
    union {
        void* fPtrAlignment;
        double fDoubleAlignment;
        char fStorage[SIZE];
=======
template <size_t SIZE> class SkSWriter32 : public SkWriter32 {
public:
    SkSWriter32() { this->reset(); }

    void reset() {this->INHERITED::reset(fData.fStorage, SIZE); }

private:
    union {
        void*   fPtrAlignment;
        double  fDoubleAlignment;
        char    fStorage[SIZE];
>>>>>>> miniblink49
    } fData;

    typedef SkWriter32 INHERITED;
};

#endif
