/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkValidatingReadBuffer.h"
#include "SkBitmap.h"
#include "SkErrorInternals.h"
#include "SkStream.h"
#include "SkTypeface.h"

SkValidatingReadBuffer::SkValidatingReadBuffer(const void* data, size_t size)
    : fError(false)
{
=======
#include "SkBitmap.h"
#include "SkErrorInternals.h"
#include "SkValidatingReadBuffer.h"
#include "SkStream.h"
#include "SkTypeface.h"

SkValidatingReadBuffer::SkValidatingReadBuffer(const void* data, size_t size) :
    fError(false) {
>>>>>>> miniblink49
    this->setMemory(data, size);
    this->setFlags(SkReadBuffer::kValidation_Flag);
}

<<<<<<< HEAD
SkValidatingReadBuffer::~SkValidatingReadBuffer()
{
}

bool SkValidatingReadBuffer::validate(bool isValid)
{
=======
SkValidatingReadBuffer::~SkValidatingReadBuffer() {
}

bool SkValidatingReadBuffer::validate(bool isValid) {
>>>>>>> miniblink49
    if (!fError && !isValid) {
        // When an error is found, send the read cursor to the end of the stream
        fReader.skip(fReader.available());
        fError = true;
    }
    return !fError;
}

<<<<<<< HEAD
bool SkValidatingReadBuffer::isValid() const
{
    return !fError;
}

void SkValidatingReadBuffer::setMemory(const void* data, size_t size)
{
=======
bool SkValidatingReadBuffer::isValid() const {
    return !fError;
}

void SkValidatingReadBuffer::setMemory(const void* data, size_t size) {
>>>>>>> miniblink49
    this->validate(IsPtrAlign4(data) && (SkAlign4(size) == size));
    if (!fError) {
        fReader.setMemory(data, size);
    }
}

<<<<<<< HEAD
const void* SkValidatingReadBuffer::skip(size_t size)
{
=======
const void* SkValidatingReadBuffer::skip(size_t size) {
>>>>>>> miniblink49
    size_t inc = SkAlign4(size);
    const void* addr = fReader.peek();
    this->validate(IsPtrAlign4(addr) && fReader.isAvailable(inc));
    if (!fError) {
        fReader.skip(size);
    }
    return addr;
}

// All the methods in this file funnel down into either readInt(), readScalar() or skip(),
// followed by a memcpy. So we've got all our validation in readInt(), readScalar() and skip();
// if they fail they'll return a zero value or skip nothing, respectively, and set fError to
// true, which the caller should check to see if an error occurred during the read operation.

<<<<<<< HEAD
bool SkValidatingReadBuffer::readBool()
{
=======
bool SkValidatingReadBuffer::readBool() {
>>>>>>> miniblink49
    uint32_t value = this->readInt();
    // Boolean value should be either 0 or 1
    this->validate(!(value & ~1));
    return value != 0;
}

<<<<<<< HEAD
SkColor SkValidatingReadBuffer::readColor()
{
    return this->readInt();
}

int32_t SkValidatingReadBuffer::readInt()
{
=======
SkColor SkValidatingReadBuffer::readColor() {
    return this->readInt();
}

SkFixed SkValidatingReadBuffer::readFixed() {
    return this->readInt();
}

int32_t SkValidatingReadBuffer::readInt() {
>>>>>>> miniblink49
    const size_t inc = sizeof(int32_t);
    this->validate(IsPtrAlign4(fReader.peek()) && fReader.isAvailable(inc));
    return fError ? 0 : fReader.readInt();
}

<<<<<<< HEAD
SkScalar SkValidatingReadBuffer::readScalar()
{
=======
SkScalar SkValidatingReadBuffer::readScalar() {
>>>>>>> miniblink49
    const size_t inc = sizeof(SkScalar);
    this->validate(IsPtrAlign4(fReader.peek()) && fReader.isAvailable(inc));
    return fError ? 0 : fReader.readScalar();
}

<<<<<<< HEAD
uint32_t SkValidatingReadBuffer::readUInt()
{
    return this->readInt();
}

int32_t SkValidatingReadBuffer::read32()
{
    return this->readInt();
}

uint8_t SkValidatingReadBuffer::peekByte()
{
    if (fReader.available() <= 0) {
        fError = true;
        return 0;
    }
    return *((uint8_t*)fReader.peek());
}

void SkValidatingReadBuffer::readString(SkString* string)
{
=======
uint32_t SkValidatingReadBuffer::readUInt() {
    return this->readInt();
}

int32_t SkValidatingReadBuffer::read32() {
    return this->readInt();
}

void SkValidatingReadBuffer::readString(SkString* string) {
>>>>>>> miniblink49
    const size_t len = this->readUInt();
    const void* ptr = fReader.peek();
    const char* cptr = (const char*)ptr;

    // skip over the string + '\0' and then pad to a multiple of 4
    const size_t alignedSize = SkAlign4(len + 1);
    this->skip(alignedSize);
    if (!fError) {
        this->validate(cptr[len] == '\0');
    }
    if (!fError) {
        string->set(cptr, len);
    }
}

<<<<<<< HEAD
void SkValidatingReadBuffer::readPoint(SkPoint* point)
{
=======
void* SkValidatingReadBuffer::readEncodedString(size_t* length, SkPaint::TextEncoding encoding) {
    const int32_t encodingType = this->readInt();
    this->validate(encodingType == encoding);
    *length = this->readInt();
    const void* ptr = this->skip(SkAlign4(*length));
    void* data = NULL;
    if (!fError) {
        data = sk_malloc_throw(*length);
        memcpy(data, ptr, *length);
    }
    return data;
}

void SkValidatingReadBuffer::readPoint(SkPoint* point) {
>>>>>>> miniblink49
    point->fX = this->readScalar();
    point->fY = this->readScalar();
}

<<<<<<< HEAD
void SkValidatingReadBuffer::readMatrix(SkMatrix* matrix)
{
=======
void SkValidatingReadBuffer::readMatrix(SkMatrix* matrix) {
>>>>>>> miniblink49
    size_t size = 0;
    if (!fError) {
        size = matrix->readFromMemory(fReader.peek(), fReader.available());
        this->validate((SkAlign4(size) == size) && (0 != size));
    }
    if (!fError) {
        (void)this->skip(size);
    }
}

<<<<<<< HEAD
void SkValidatingReadBuffer::readIRect(SkIRect* rect)
{
=======
void SkValidatingReadBuffer::readIRect(SkIRect* rect) {
>>>>>>> miniblink49
    const void* ptr = this->skip(sizeof(SkIRect));
    if (!fError) {
        memcpy(rect, ptr, sizeof(SkIRect));
    }
}

<<<<<<< HEAD
void SkValidatingReadBuffer::readRect(SkRect* rect)
{
=======
void SkValidatingReadBuffer::readRect(SkRect* rect) {
>>>>>>> miniblink49
    const void* ptr = this->skip(sizeof(SkRect));
    if (!fError) {
        memcpy(rect, ptr, sizeof(SkRect));
    }
}

<<<<<<< HEAD
void SkValidatingReadBuffer::readRRect(SkRRect* rrect)
{
    const void* ptr = this->skip(sizeof(SkRRect));
    if (!fError) {
        memcpy(rrect, ptr, sizeof(SkRRect));
    }
}

void SkValidatingReadBuffer::readRegion(SkRegion* region)
{
=======
void SkValidatingReadBuffer::readRegion(SkRegion* region) {
>>>>>>> miniblink49
    size_t size = 0;
    if (!fError) {
        size = region->readFromMemory(fReader.peek(), fReader.available());
        this->validate((SkAlign4(size) == size) && (0 != size));
    }
    if (!fError) {
        (void)this->skip(size);
    }
}

<<<<<<< HEAD
void SkValidatingReadBuffer::readPath(SkPath* path)
{
=======
void SkValidatingReadBuffer::readPath(SkPath* path) {
>>>>>>> miniblink49
    size_t size = 0;
    if (!fError) {
        size = path->readFromMemory(fReader.peek(), fReader.available());
        this->validate((SkAlign4(size) == size) && (0 != size));
    }
    if (!fError) {
        (void)this->skip(size);
    }
}

<<<<<<< HEAD
bool SkValidatingReadBuffer::readArray(void* value, size_t size, size_t elementSize)
{
=======
bool SkValidatingReadBuffer::readArray(void* value, size_t size, size_t elementSize) {
>>>>>>> miniblink49
    const uint32_t count = this->getArrayCount();
    this->validate(size == count);
    (void)this->skip(sizeof(uint32_t)); // Skip array count
    const uint64_t byteLength64 = sk_64_mul(count, elementSize);
    const size_t byteLength = count * elementSize;
    this->validate(byteLength == byteLength64);
    const void* ptr = this->skip(SkAlign4(byteLength));
    if (!fError) {
        memcpy(value, ptr, byteLength);
        return true;
    }
    return false;
}

<<<<<<< HEAD
bool SkValidatingReadBuffer::readByteArray(void* value, size_t size)
{
    return readArray(static_cast<unsigned char*>(value), size, sizeof(unsigned char));
}

bool SkValidatingReadBuffer::readColorArray(SkColor* colors, size_t size)
{
    return readArray(colors, size, sizeof(SkColor));
}

bool SkValidatingReadBuffer::readIntArray(int32_t* values, size_t size)
{
    return readArray(values, size, sizeof(int32_t));
}

bool SkValidatingReadBuffer::readPointArray(SkPoint* points, size_t size)
{
    return readArray(points, size, sizeof(SkPoint));
}

bool SkValidatingReadBuffer::readScalarArray(SkScalar* values, size_t size)
{
    return readArray(values, size, sizeof(SkScalar));
}

uint32_t SkValidatingReadBuffer::getArrayCount()
{
=======
bool SkValidatingReadBuffer::readByteArray(void* value, size_t size) {
    return readArray(static_cast<unsigned char*>(value), size, sizeof(unsigned char));
}

bool SkValidatingReadBuffer::readColorArray(SkColor* colors, size_t size) {
    return readArray(colors, size, sizeof(SkColor));
}

bool SkValidatingReadBuffer::readIntArray(int32_t* values, size_t size) {
    return readArray(values, size, sizeof(int32_t));
}

bool SkValidatingReadBuffer::readPointArray(SkPoint* points, size_t size) {
    return readArray(points, size, sizeof(SkPoint));
}

bool SkValidatingReadBuffer::readScalarArray(SkScalar* values, size_t size) {
    return readArray(values, size, sizeof(SkScalar));
}

uint32_t SkValidatingReadBuffer::getArrayCount() {
>>>>>>> miniblink49
    const size_t inc = sizeof(uint32_t);
    fError = fError || !IsPtrAlign4(fReader.peek()) || !fReader.isAvailable(inc);
    return fError ? 0 : *(uint32_t*)fReader.peek();
}

<<<<<<< HEAD
SkTypeface* SkValidatingReadBuffer::readTypeface()
{
    SkASSERT(false);
    // TODO: Implement this (securely) when needed
    return nullptr;
}

bool SkValidatingReadBuffer::validateAvailable(size_t size)
{
    return this->validate((size <= SK_MaxU32) && fReader.isAvailable(static_cast<uint32_t>(size)));
}

SkFlattenable* SkValidatingReadBuffer::readFlattenable(SkFlattenable::Type type)
{
    // The validating read buffer always uses strings and string-indices for unflattening.
    SkASSERT(0 == this->factoryCount());

    uint8_t firstByte = this->peekByte();
    if (fError) {
        return nullptr;
    }

    SkString name;
    if (firstByte) {
        // If the first byte is non-zero, the flattenable is specified by a string.
        this->readString(&name);
        if (fError) {
            return nullptr;
        }

        // Add the string to the dictionary.
        fFlattenableDict.set(fFlattenableDict.count() + 1, name);
    } else {
        // Read the index.  We are guaranteed that the first byte
        // is zeroed, so we must shift down a byte.
        uint32_t index = fReader.readU32() >> 8;
        if (0 == index) {
            return nullptr; // writer failed to give us the flattenable
        }

        SkString* namePtr = fFlattenableDict.find(index);
        if (!namePtr) {
            return nullptr;
        }
        name = *namePtr;
=======
SkTypeface* SkValidatingReadBuffer::readTypeface() {
    // TODO: Implement this (securely) when needed
    return NULL;
}

bool SkValidatingReadBuffer::validateAvailable(size_t size) {
    return this->validate((size <= SK_MaxU32) && fReader.isAvailable(static_cast<uint32_t>(size)));
}

SkFlattenable* SkValidatingReadBuffer::readFlattenable(SkFlattenable::Type type) {
    SkString name;
    this->readString(&name);
    if (fError) {
        return NULL;
>>>>>>> miniblink49
    }

    // Is this the type we wanted ?
    const char* cname = name.c_str();
    SkFlattenable::Type baseType;
    if (!SkFlattenable::NameToType(cname, &baseType) || (baseType != type)) {
<<<<<<< HEAD
        return nullptr;
    }

    // Get the factory for this flattenable.
    SkFlattenable::Factory factory = this->getCustomFactory(name);
    if (!factory) {
        factory = SkFlattenable::NameToFactory(cname);
        if (!factory) {
            return nullptr; // writer failed to give us the flattenable
        }
    }

    // If we get here, the factory is non-null.
    sk_sp<SkFlattenable> obj;
    uint32_t sizeRecorded = this->readUInt();
    size_t offset = fReader.offset();
    obj = (*factory)(*this);
    // check that we read the amount we expected
    size_t sizeRead = fReader.offset() - offset;
    this->validate(sizeRecorded == sizeRead);
    if (fError) {
        obj = nullptr;
    }
    return obj.release();
=======
        return NULL;
    }

    SkFlattenable::Factory factory = SkFlattenable::NameToFactory(cname);
    if (NULL == factory) {
        return NULL; // writer failed to give us the flattenable
    }

    // if we get here, factory may still be null, but if that is the case, the
    // failure was ours, not the writer.
    SkFlattenable* obj = NULL;
    uint32_t sizeRecorded = this->readUInt();
    if (factory) {
        size_t offset = fReader.offset();
        obj = (*factory)(*this);
        // check that we read the amount we expected
        size_t sizeRead = fReader.offset() - offset;
        this->validate(sizeRecorded == sizeRead);
        if (fError) {
            // we could try to fix up the offset...
            SkSafeUnref(obj);
            obj = NULL;
        }
    } else {
        // we must skip the remaining data
        this->skip(sizeRecorded);
        SkASSERT(false);
    }
    return obj;
}

void SkValidatingReadBuffer::skipFlattenable() {
    SkString name;
    this->readString(&name);
    if (fError) {
        return;
    }
    uint32_t sizeRecorded = this->readUInt();
    this->skip(sizeRecorded);
>>>>>>> miniblink49
}
