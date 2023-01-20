<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkStream.h"
#include "SkData.h"
#include "SkFixed.h"
#include "SkOSFile.h"
#include "SkStreamPriv.h"
#include "SkString.h"
=======

#include "SkStream.h"
#include "SkStreamPriv.h"
#include "SkData.h"
#include "SkFixed.h"
#include "SkString.h"
#include "SkOSFile.h"
>>>>>>> miniblink49
#include "SkTypes.h"

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
int8_t SkStream::readS8()
{
=======

int8_t SkStream::readS8() {
>>>>>>> miniblink49
    int8_t value;
    SkDEBUGCODE(size_t len =) this->read(&value, 1);
    SkASSERT(1 == len);
    return value;
}

<<<<<<< HEAD
int16_t SkStream::readS16()
{
=======
int16_t SkStream::readS16() {
>>>>>>> miniblink49
    int16_t value;
    SkDEBUGCODE(size_t len =) this->read(&value, 2);
    SkASSERT(2 == len);
    return value;
}

<<<<<<< HEAD
int32_t SkStream::readS32()
{
=======
int32_t SkStream::readS32() {
>>>>>>> miniblink49
    int32_t value;
    SkDEBUGCODE(size_t len =) this->read(&value, 4);
    SkASSERT(4 == len);
    return value;
}

<<<<<<< HEAD
SkScalar SkStream::readScalar()
{
=======
SkScalar SkStream::readScalar() {
>>>>>>> miniblink49
    SkScalar value;
    SkDEBUGCODE(size_t len =) this->read(&value, sizeof(SkScalar));
    SkASSERT(sizeof(SkScalar) == len);
    return value;
}

<<<<<<< HEAD
#define SK_MAX_BYTE_FOR_U8 0xFD
#define SK_BYTE_SENTINEL_FOR_U16 0xFE
#define SK_BYTE_SENTINEL_FOR_U32 0xFF

size_t SkStream::readPackedUInt()
{
=======
#define SK_MAX_BYTE_FOR_U8          0xFD
#define SK_BYTE_SENTINEL_FOR_U16    0xFE
#define SK_BYTE_SENTINEL_FOR_U32    0xFF

size_t SkStream::readPackedUInt() {
>>>>>>> miniblink49
    uint8_t byte;
    if (!this->read(&byte, 1)) {
        return 0;
    }
    if (SK_BYTE_SENTINEL_FOR_U16 == byte) {
        return this->readU16();
    } else if (SK_BYTE_SENTINEL_FOR_U32 == byte) {
        return this->readU32();
    } else {
        return byte;
    }
}

//////////////////////////////////////////////////////////////////////////////////////

SkWStream::~SkWStream()
{
}

void SkWStream::newline()
{
    this->write("\n", 1);
}

void SkWStream::flush()
{
}

<<<<<<< HEAD
=======
bool SkWStream::writeText(const char text[])
{
    SkASSERT(text);
    return this->write(text, strlen(text));
}

>>>>>>> miniblink49
bool SkWStream::writeDecAsText(int32_t dec)
{
    char buffer[SkStrAppendS32_MaxSize];
    char* stop = SkStrAppendS32(buffer, dec);
    return this->write(buffer, stop - buffer);
}

bool SkWStream::writeBigDecAsText(int64_t dec, int minDigits)
{
    char buffer[SkStrAppendU64_MaxSize];
    char* stop = SkStrAppendU64(buffer, dec, minDigits);
    return this->write(buffer, stop - buffer);
}

bool SkWStream::writeHexAsText(uint32_t hex, int digits)
{
<<<<<<< HEAD
    SkString tmp;
=======
    SkString    tmp;
>>>>>>> miniblink49
    tmp.appendHex(hex, digits);
    return this->write(tmp.c_str(), tmp.size());
}

bool SkWStream::writeScalarAsText(SkScalar value)
{
    char buffer[SkStrAppendScalar_MaxSize];
    char* stop = SkStrAppendScalar(buffer, value);
    return this->write(buffer, stop - buffer);
}

<<<<<<< HEAD
bool SkWStream::write8(U8CPU value)
{
=======
bool SkWStream::write8(U8CPU value) {
>>>>>>> miniblink49
    uint8_t v = SkToU8(value);
    return this->write(&v, 1);
}

<<<<<<< HEAD
bool SkWStream::write16(U16CPU value)
{
=======
bool SkWStream::write16(U16CPU value) {
>>>>>>> miniblink49
    uint16_t v = SkToU16(value);
    return this->write(&v, 2);
}

<<<<<<< HEAD
bool SkWStream::write32(uint32_t value)
{
    return this->write(&value, 4);
}

bool SkWStream::writeScalar(SkScalar value)
{
    return this->write(&value, sizeof(value));
}

int SkWStream::SizeOfPackedUInt(size_t value)
{
=======
bool SkWStream::write32(uint32_t value) {
    return this->write(&value, 4);
}

bool SkWStream::writeScalar(SkScalar value) {
    return this->write(&value, sizeof(value));
}

int SkWStream::SizeOfPackedUInt(size_t value) {
>>>>>>> miniblink49
    if (value <= SK_MAX_BYTE_FOR_U8) {
        return 1;
    } else if (value <= 0xFFFF) {
        return 3;
    }
    return 5;
}

<<<<<<< HEAD
bool SkWStream::writePackedUInt(size_t value)
{
=======
bool SkWStream::writePackedUInt(size_t value) {
>>>>>>> miniblink49
    uint8_t data[5];
    size_t len = 1;
    if (value <= SK_MAX_BYTE_FOR_U8) {
        data[0] = value;
        len = 1;
    } else if (value <= 0xFFFF) {
        uint16_t value16 = value;
        data[0] = SK_BYTE_SENTINEL_FOR_U16;
        memcpy(&data[1], &value16, 2);
        len = 3;
    } else {
        uint32_t value32 = SkToU32(value);
        data[0] = SK_BYTE_SENTINEL_FOR_U32;
        memcpy(&data[1], &value32, 4);
        len = 5;
    }
    return this->write(data, len);
}

<<<<<<< HEAD
bool SkWStream::writeStream(SkStream* stream, size_t length)
{
=======
bool SkWStream::writeStream(SkStream* stream, size_t length) {
>>>>>>> miniblink49
    char scratch[1024];
    const size_t MAX = sizeof(scratch);

    while (length != 0) {
        size_t n = length;
        if (n > MAX) {
            n = MAX;
        }
        stream->read(scratch, n);
        if (!this->write(scratch, n)) {
            return false;
        }
        length -= n;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkFILEStream::SkFILEStream(const char file[])
    : fName(file)
    , fOwnership(kCallerPasses_Ownership)
{
    fFILE = file ? sk_fopen(fName.c_str(), kRead_SkFILE_Flag) : nullptr;
}

SkFILEStream::SkFILEStream(FILE* file, Ownership ownership)
    : fFILE(file)
    , fOwnership(ownership)
{
}

SkFILEStream::~SkFILEStream()
{
=======
SkFILEStream::SkFILEStream(const char file[]) : fName(file), fOwnership(kCallerPasses_Ownership) {
    fFILE = file ? sk_fopen(fName.c_str(), kRead_SkFILE_Flag) : NULL;
}

SkFILEStream::SkFILEStream(FILE* file, Ownership ownership)
    : fFILE((SkFILE*)file)
    , fOwnership(ownership) {
}

SkFILEStream::~SkFILEStream() {
>>>>>>> miniblink49
    if (fFILE && fOwnership != kCallerRetains_Ownership) {
        sk_fclose(fFILE);
    }
}

<<<<<<< HEAD
void SkFILEStream::setPath(const char path[])
{
    fName.set(path);
    if (fFILE) {
        sk_fclose(fFILE);
        fFILE = nullptr;
=======
void SkFILEStream::setPath(const char path[]) {
    fName.set(path);
    if (fFILE) {
        sk_fclose(fFILE);
        fFILE = NULL;
>>>>>>> miniblink49
    }
    if (path) {
        fFILE = sk_fopen(fName.c_str(), kRead_SkFILE_Flag);
    }
}

<<<<<<< HEAD
size_t SkFILEStream::read(void* buffer, size_t size)
{
=======
size_t SkFILEStream::read(void* buffer, size_t size) {
>>>>>>> miniblink49
    if (fFILE) {
        return sk_fread(buffer, size, fFILE);
    }
    return 0;
}

<<<<<<< HEAD
bool SkFILEStream::isAtEnd() const
{
    return sk_feof(fFILE);
}

bool SkFILEStream::rewind()
{
=======
bool SkFILEStream::isAtEnd() const {
    return sk_feof(fFILE);
}

bool SkFILEStream::rewind() {
>>>>>>> miniblink49
    if (fFILE) {
        if (sk_frewind(fFILE)) {
            return true;
        }
        // we hit an error
        sk_fclose(fFILE);
<<<<<<< HEAD
        fFILE = nullptr;
=======
        fFILE = NULL;
>>>>>>> miniblink49
    }
    return false;
}

<<<<<<< HEAD
SkStreamAsset* SkFILEStream::duplicate() const
{
    if (nullptr == fFILE) {
=======
SkStreamAsset* SkFILEStream::duplicate() const {
    if (NULL == fFILE) {
>>>>>>> miniblink49
        return new SkMemoryStream();
    }

    if (fData.get()) {
        return new SkMemoryStream(fData);
    }

    if (!fName.isEmpty()) {
        SkAutoTDelete<SkFILEStream> that(new SkFILEStream(fName.c_str()));
        if (sk_fidentical(that->fFILE, this->fFILE)) {
<<<<<<< HEAD
            return that.release();
        }
    }

    fData = SkData::MakeFromFILE(fFILE);
    if (nullptr == fData) {
        return nullptr;
=======
            return that.detach();
        }
    }

    fData.reset(SkData::NewFromFILE(fFILE));
    if (NULL == fData.get()) {
        return NULL;
>>>>>>> miniblink49
    }
    return new SkMemoryStream(fData);
}

<<<<<<< HEAD
size_t SkFILEStream::getPosition() const
{
    return sk_ftell(fFILE);
}

bool SkFILEStream::seek(size_t position)
{
    return sk_fseek(fFILE, position);
}

bool SkFILEStream::move(long offset)
{
    return sk_fmove(fFILE, offset);
}

SkStreamAsset* SkFILEStream::fork() const
{
    SkAutoTDelete<SkStreamAsset> that(this->duplicate());
    that->seek(this->getPosition());
    return that.release();
}

size_t SkFILEStream::getLength() const
{
    return sk_fgetsize(fFILE);
}

const void* SkFILEStream::getMemoryBase()
{
    if (nullptr == fData.get()) {
        return nullptr;
=======
size_t SkFILEStream::getPosition() const {
    return sk_ftell(fFILE);
}

bool SkFILEStream::seek(size_t position) {
    return sk_fseek(fFILE, position);
}

bool SkFILEStream::move(long offset) {
    return sk_fmove(fFILE, offset);
}

SkStreamAsset* SkFILEStream::fork() const {
    SkAutoTDelete<SkStreamAsset> that(this->duplicate());
    that->seek(this->getPosition());
    return that.detach();
}

size_t SkFILEStream::getLength() const {
    return sk_fgetsize(fFILE);
}

const void* SkFILEStream::getMemoryBase() {
    if (NULL == fData.get()) {
        return NULL;
>>>>>>> miniblink49
    }
    return fData->data();
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static sk_sp<SkData> newFromParams(const void* src, size_t size, bool copyData)
{
    if (copyData) {
        return SkData::MakeWithCopy(src, size);
    } else {
        return SkData::MakeWithoutCopy(src, size);
    }
}

SkMemoryStream::SkMemoryStream()
{
    fData = SkData::MakeEmpty();
    fOffset = 0;
}

SkMemoryStream::SkMemoryStream(size_t size)
{
    fData = SkData::MakeUninitialized(size);
    fOffset = 0;
}

SkMemoryStream::SkMemoryStream(const void* src, size_t size, bool copyData)
{
=======
static SkData* newFromParams(const void* src, size_t size, bool copyData) {
    if (copyData) {
        return SkData::NewWithCopy(src, size);
    } else {
        return SkData::NewWithoutCopy(src, size);
    }
}

SkMemoryStream::SkMemoryStream() {
    fData = SkData::NewEmpty();
    fOffset = 0;
}

SkMemoryStream::SkMemoryStream(size_t size) {
    fData = SkData::NewUninitialized(size);
    fOffset = 0;
}

SkMemoryStream::SkMemoryStream(const void* src, size_t size, bool copyData) {
>>>>>>> miniblink49
    fData = newFromParams(src, size, copyData);
    fOffset = 0;
}

<<<<<<< HEAD
SkMemoryStream::SkMemoryStream(sk_sp<SkData> data)
    : fData(std::move(data))
{
    if (nullptr == fData) {
        fData = SkData::MakeEmpty();
    }
    fOffset = 0;
}

SkMemoryStream::SkMemoryStream(SkData* data)
{
    if (nullptr == data) {
        fData = SkData::MakeEmpty();
    } else {
        fData = sk_ref_sp(data);
=======
SkMemoryStream::SkMemoryStream(SkData* data) {
    if (NULL == data) {
        fData = SkData::NewEmpty();
    } else {
        fData = data;
        fData->ref();
>>>>>>> miniblink49
    }
    fOffset = 0;
}

<<<<<<< HEAD
void SkMemoryStream::setMemoryOwned(const void* src, size_t size)
{
    fData = SkData::MakeFromMalloc(src, size);
    fOffset = 0;
}

void SkMemoryStream::setMemory(const void* src, size_t size, bool copyData)
{
=======
SkMemoryStream::~SkMemoryStream() {
    fData->unref();
}

void SkMemoryStream::setMemoryOwned(const void* src, size_t size) {
    fData->unref();
    fData = SkData::NewFromMalloc(src, size);
    fOffset = 0;
}

void SkMemoryStream::setMemory(const void* src, size_t size, bool copyData) {
    fData->unref();
>>>>>>> miniblink49
    fData = newFromParams(src, size, copyData);
    fOffset = 0;
}

<<<<<<< HEAD
SkData* SkMemoryStream::copyToData() const
{
    return SkSafeRef(fData.get());
}

SkData* SkMemoryStream::setData(SkData* data)
{
    if (nullptr == data) {
        fData = SkData::MakeEmpty();
    } else {
        fData = sk_ref_sp(data);
=======
SkData* SkMemoryStream::copyToData() const {
    fData->ref();
    return fData;
}

SkData* SkMemoryStream::setData(SkData* data) {
    fData->unref();
    if (NULL == data) {
        fData = SkData::NewEmpty();
    } else {
        fData = data;
        fData->ref();
>>>>>>> miniblink49
    }
    fOffset = 0;
    return data;
}

<<<<<<< HEAD
void SkMemoryStream::skipToAlign4()
{
=======
void SkMemoryStream::skipToAlign4() {
>>>>>>> miniblink49
    // cast to remove unary-minus warning
    fOffset += -(int)fOffset & 0x03;
}

<<<<<<< HEAD
size_t SkMemoryStream::read(void* buffer, size_t size)
{
=======
size_t SkMemoryStream::read(void* buffer, size_t size) {
>>>>>>> miniblink49
    size_t dataSize = fData->size();

    if (size > dataSize - fOffset) {
        size = dataSize - fOffset;
    }
    if (buffer) {
        memcpy(buffer, fData->bytes() + fOffset, size);
    }
    fOffset += size;
    return size;
}

<<<<<<< HEAD
size_t SkMemoryStream::peek(void* buffer, size_t size) const
{
    SkASSERT(buffer != nullptr);

    const size_t currentOffset = fOffset;
    SkMemoryStream* nonConstThis = const_cast<SkMemoryStream*>(this);
    const size_t bytesRead = nonConstThis->read(buffer, size);
    nonConstThis->fOffset = currentOffset;
    return bytesRead;
}

bool SkMemoryStream::isAtEnd() const
{
    return fOffset == fData->size();
}

bool SkMemoryStream::rewind()
{
=======
bool SkMemoryStream::peek(void* buffer, size_t size) const {
    SkASSERT(buffer != NULL);
    const size_t position = fOffset;
    if (size > fData->size() - position) {
        // The stream is not large enough to satisfy this request.
        return false;
    }
    SkMemoryStream* nonConstThis = const_cast<SkMemoryStream*>(this);
    SkDEBUGCODE(const size_t bytesRead =) nonConstThis->read(buffer, size);
    SkASSERT(bytesRead == size);
    nonConstThis->fOffset = position;
    return true;
}

bool SkMemoryStream::isAtEnd() const {
    return fOffset == fData->size();
}

bool SkMemoryStream::rewind() {
>>>>>>> miniblink49
    fOffset = 0;
    return true;
}

<<<<<<< HEAD
SkMemoryStream* SkMemoryStream::duplicate() const { return new SkMemoryStream(fData); }

size_t SkMemoryStream::getPosition() const
{
    return fOffset;
}

bool SkMemoryStream::seek(size_t position)
{
    fOffset = position > fData->size()
        ? fData->size()
        : position;
    return true;
}

bool SkMemoryStream::move(long offset)
{
    return this->seek(fOffset + offset);
}

SkMemoryStream* SkMemoryStream::fork() const
{
    SkAutoTDelete<SkMemoryStream> that(this->duplicate());
    that->seek(fOffset);
    return that.release();
}

size_t SkMemoryStream::getLength() const
{
    return fData->size();
}

const void* SkMemoryStream::getMemoryBase()
{
    return fData->data();
}

const void* SkMemoryStream::getAtPos()
{
=======
SkMemoryStream* SkMemoryStream::duplicate() const {
    return SkNEW_ARGS(SkMemoryStream, (fData));
}

size_t SkMemoryStream::getPosition() const {
    return fOffset;
}

bool SkMemoryStream::seek(size_t position) {
    fOffset = position > fData->size()
            ? fData->size()
            : position;
    return true;
}

bool SkMemoryStream::move(long offset) {
    return this->seek(fOffset + offset);
}

SkMemoryStream* SkMemoryStream::fork() const {
    SkAutoTDelete<SkMemoryStream> that(this->duplicate());
    that->seek(fOffset);
    return that.detach();
}

size_t SkMemoryStream::getLength() const {
    return fData->size();
}

const void* SkMemoryStream::getMemoryBase() {
    return fData->data();
}

const void* SkMemoryStream::getAtPos() {
>>>>>>> miniblink49
    return fData->bytes() + fOffset;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

SkFILEWStream::SkFILEWStream(const char path[])
{
    fFILE = sk_fopen(path, kWrite_SkFILE_Flag);
}

SkFILEWStream::~SkFILEWStream()
{
    if (fFILE) {
        sk_fclose(fFILE);
    }
}

<<<<<<< HEAD
size_t SkFILEWStream::bytesWritten() const
{
=======
size_t SkFILEWStream::bytesWritten() const {
>>>>>>> miniblink49
    return sk_ftell(fFILE);
}

bool SkFILEWStream::write(const void* buffer, size_t size)
{
<<<<<<< HEAD
    if (fFILE == nullptr) {
        return false;
    }

    if (sk_fwrite(buffer, size, fFILE) != size) {
        SkDEBUGCODE(SkDebugf("SkFILEWStream failed writing %d bytes\n", size);)
            sk_fclose(fFILE);
        fFILE = nullptr;
=======
    if (fFILE == NULL) {
        return false;
    }

    if (sk_fwrite(buffer, size, fFILE) != size)
    {
        SkDEBUGCODE(SkDebugf("SkFILEWStream failed writing %d bytes\n", size);)
        sk_fclose(fFILE);
        fFILE = NULL;
>>>>>>> miniblink49
        return false;
    }
    return true;
}

void SkFILEWStream::flush()
{
    if (fFILE) {
        sk_fflush(fFILE);
    }
}

<<<<<<< HEAD
void SkFILEWStream::fsync()
{
    flush();
    if (fFILE) {
        sk_fsync(fFILE);
    }
}

////////////////////////////////////////////////////////////////////////

SkMemoryWStream::SkMemoryWStream(void* buffer, size_t size)
    : fBuffer((char*)buffer)
    , fMaxLength(size)
    , fBytesWritten(0)
{
}

bool SkMemoryWStream::write(const void* buffer, size_t size)
{
=======
////////////////////////////////////////////////////////////////////////

SkMemoryWStream::SkMemoryWStream(void* buffer, size_t size)
    : fBuffer((char*)buffer), fMaxLength(size), fBytesWritten(0)
{
}

bool SkMemoryWStream::write(const void* buffer, size_t size) {
>>>>>>> miniblink49
    size = SkTMin(size, fMaxLength - fBytesWritten);
    if (size > 0) {
        memcpy(fBuffer + fBytesWritten, buffer, size);
        fBytesWritten += size;
        return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#define SkDynamicMemoryWStream_MinBlockSize 256

struct SkDynamicMemoryWStream::Block {
    Block* fNext;
    char* fCurr;
    char* fStop;

    const char* start() const { return (const char*)(this + 1); }
    char* start() { return (char*)(this + 1); }
    size_t avail() const { return fStop - fCurr; }
    size_t written() const { return fCurr - this->start(); }

    void init(size_t size)
    {
        fNext = nullptr;
=======
#define SkDynamicMemoryWStream_MinBlockSize   256

struct SkDynamicMemoryWStream::Block {
    Block*  fNext;
    char*   fCurr;
    char*   fStop;

    const char* start() const { return (const char*)(this + 1); }
    char*   start() { return (char*)(this + 1); }
    size_t  avail() const { return fStop - fCurr; }
    size_t  written() const { return fCurr - this->start(); }

    void init(size_t size)
    {
        fNext = NULL;
>>>>>>> miniblink49
        fCurr = this->start();
        fStop = this->start() + size;
    }

    const void* append(const void* data, size_t size)
    {
        SkASSERT((size_t)(fStop - fCurr) >= size);
        memcpy(fCurr, data, size);
        fCurr += size;
        return (const void*)((const char*)data + size);
    }
};

SkDynamicMemoryWStream::SkDynamicMemoryWStream()
<<<<<<< HEAD
    : fHead(nullptr)
    , fTail(nullptr)
    , fBytesWritten(0)
=======
    : fHead(NULL), fTail(NULL), fBytesWritten(0), fCopy(NULL)
>>>>>>> miniblink49
{
}

SkDynamicMemoryWStream::~SkDynamicMemoryWStream()
{
    reset();
}

void SkDynamicMemoryWStream::reset()
{
    this->invalidateCopy();

<<<<<<< HEAD
    Block* block = fHead;

    while (block != nullptr) {
        Block* next = block->fNext;
        sk_free(block);
        block = next;
    }
    fHead = fTail = nullptr;
=======
    Block*  block = fHead;

    while (block != NULL) {
        Block*  next = block->fNext;
        sk_free(block);
        block = next;
    }
    fHead = fTail = NULL;
>>>>>>> miniblink49
    fBytesWritten = 0;
}

bool SkDynamicMemoryWStream::write(const void* buffer, size_t count)
{
    if (count > 0) {
        this->invalidateCopy();

        fBytesWritten += count;

<<<<<<< HEAD
        size_t size;

        if (fTail != nullptr && fTail->avail() > 0) {
=======
        size_t  size;

        if (fTail != NULL && fTail->avail() > 0) {
>>>>>>> miniblink49
            size = SkTMin(fTail->avail(), count);
            buffer = fTail->append(buffer, size);
            SkASSERT(count >= size);
            count -= size;
            if (count == 0)
                return true;
        }

        size = SkTMax<size_t>(count, SkDynamicMemoryWStream_MinBlockSize);
        Block* block = (Block*)sk_malloc_throw(sizeof(Block) + size);
        block->init(size);
        block->append(buffer, count);

<<<<<<< HEAD
        if (fTail != nullptr)
=======
        if (fTail != NULL)
>>>>>>> miniblink49
            fTail->fNext = block;
        else
            fHead = fTail = block;
        fTail = block;
    }
    return true;
}

bool SkDynamicMemoryWStream::write(const void* buffer, size_t offset, size_t count)
{
    if (offset + count > fBytesWritten) {
        return false; // test does not partially modify
    }

    this->invalidateCopy();

    Block* block = fHead;
<<<<<<< HEAD
    while (block != nullptr) {
=======
    while (block != NULL) {
>>>>>>> miniblink49
        size_t size = block->written();
        if (offset < size) {
            size_t part = offset + count > size ? size - offset : count;
            memcpy(block->start() + offset, buffer, part);
            if (count <= part)
                return true;
            count -= part;
<<<<<<< HEAD
            buffer = (const void*)((char*)buffer + part);
=======
            buffer = (const void*) ((char* ) buffer + part);
>>>>>>> miniblink49
        }
        offset = offset > size ? offset - size : 0;
        block = block->fNext;
    }
    return false;
}

bool SkDynamicMemoryWStream::read(void* buffer, size_t offset, size_t count)
{
    if (offset + count > fBytesWritten)
        return false; // test does not partially modify
    Block* block = fHead;
<<<<<<< HEAD
    while (block != nullptr) {
=======
    while (block != NULL) {
>>>>>>> miniblink49
        size_t size = block->written();
        if (offset < size) {
            size_t part = offset + count > size ? size - offset : count;
            memcpy(buffer, block->start() + offset, part);
            if (count <= part)
                return true;
            count -= part;
<<<<<<< HEAD
            buffer = (void*)((char*)buffer + part);
=======
            buffer = (void*) ((char* ) buffer + part);
>>>>>>> miniblink49
        }
        offset = offset > size ? offset - size : 0;
        block = block->fNext;
    }
    return false;
}

void SkDynamicMemoryWStream::copyTo(void* dst) const
{
    if (fCopy) {
        memcpy(dst, fCopy->data(), fBytesWritten);
    } else {
        Block* block = fHead;

<<<<<<< HEAD
        while (block != nullptr) {
=======
        while (block != NULL) {
>>>>>>> miniblink49
            size_t size = block->written();
            memcpy(dst, block->start(), size);
            dst = (void*)((char*)dst + size);
            block = block->fNext;
        }
    }
}

<<<<<<< HEAD
void SkDynamicMemoryWStream::writeToStream(SkWStream* dst) const
{
    for (Block* block = fHead; block != nullptr; block = block->fNext) {
=======
void SkDynamicMemoryWStream::writeToStream(SkWStream* dst) const {
    for (Block* block = fHead; block != NULL; block = block->fNext) {
>>>>>>> miniblink49
        dst->write(block->start(), block->written());
    }
}

void SkDynamicMemoryWStream::padToAlign4()
{
    // cast to remove unary-minus warning
    int padBytes = -(int)fBytesWritten & 0x03;
    if (padBytes == 0)
        return;
    int zero = 0;
    write(&zero, padBytes);
}

<<<<<<< HEAD
SkData* SkDynamicMemoryWStream::copyToData() const
{
    if (nullptr == fCopy) {
        auto data = SkData::MakeUninitialized(fBytesWritten);
        // be sure to call copyTo() before we assign to fCopy
        this->copyTo(data->writable_data());
        fCopy = std::move(data);
    }
    return SkRef(fCopy.get());
}

void SkDynamicMemoryWStream::invalidateCopy()
{
    fCopy = nullptr;
=======
SkData* SkDynamicMemoryWStream::copyToData() const {
    if (NULL == fCopy) {
        SkData* data = SkData::NewUninitialized(fBytesWritten);
        // be sure to call copyTo() before we assign to fCopy
        this->copyTo(data->writable_data());
        fCopy = data;
    }
    return SkRef(fCopy);
}

void SkDynamicMemoryWStream::invalidateCopy() {
    if (fCopy) {
        fCopy->unref();
        fCopy = NULL;
    }
>>>>>>> miniblink49
}

class SkBlockMemoryRefCnt : public SkRefCnt {
public:
<<<<<<< HEAD
    explicit SkBlockMemoryRefCnt(SkDynamicMemoryWStream::Block* head)
        : fHead(head)
    {
    }

    virtual ~SkBlockMemoryRefCnt()
    {
        SkDynamicMemoryWStream::Block* block = fHead;
        while (block != nullptr) {
=======
    explicit SkBlockMemoryRefCnt(SkDynamicMemoryWStream::Block* head) : fHead(head) { }

    virtual ~SkBlockMemoryRefCnt() {
        SkDynamicMemoryWStream::Block* block = fHead;
        while (block != NULL) {
>>>>>>> miniblink49
            SkDynamicMemoryWStream::Block* next = block->fNext;
            sk_free(block);
            block = next;
        }
    }

    SkDynamicMemoryWStream::Block* const fHead;
};

class SkBlockMemoryStream : public SkStreamAsset {
public:
    SkBlockMemoryStream(SkDynamicMemoryWStream::Block* head, size_t size)
<<<<<<< HEAD
        : fBlockMemory(new SkBlockMemoryRefCnt(head))
        , fCurrent(head)
        , fSize(size)
        , fOffset(0)
        , fCurrentOffset(0)
    {
    }

    SkBlockMemoryStream(SkBlockMemoryRefCnt* headRef, size_t size)
        : fBlockMemory(SkRef(headRef))
        , fCurrent(fBlockMemory->fHead)
        , fSize(size)
        , fOffset(0)
        , fCurrentOffset(0)
    {
    }

    size_t read(void* buffer, size_t rawCount) override
    {
=======
        : fBlockMemory(SkNEW_ARGS(SkBlockMemoryRefCnt, (head))), fCurrent(head)
        , fSize(size) , fOffset(0), fCurrentOffset(0) { }

    SkBlockMemoryStream(SkBlockMemoryRefCnt* headRef, size_t size)
        : fBlockMemory(SkRef(headRef)), fCurrent(fBlockMemory->fHead)
        , fSize(size) , fOffset(0), fCurrentOffset(0) { }

    size_t read(void* buffer, size_t rawCount) override {
>>>>>>> miniblink49
        size_t count = rawCount;
        if (fOffset + count > fSize) {
            count = fSize - fOffset;
        }
        size_t bytesLeftToRead = count;
<<<<<<< HEAD
        while (fCurrent != nullptr) {
=======
        while (fCurrent != NULL) {
>>>>>>> miniblink49
            size_t bytesLeftInCurrent = fCurrent->written() - fCurrentOffset;
            size_t bytesFromCurrent = SkTMin(bytesLeftToRead, bytesLeftInCurrent);
            if (buffer) {
                memcpy(buffer, fCurrent->start() + fCurrentOffset, bytesFromCurrent);
                buffer = SkTAddOffset<void>(buffer, bytesFromCurrent);
            }
            if (bytesLeftToRead <= bytesFromCurrent) {
                fCurrentOffset += bytesFromCurrent;
                fOffset += count;
                return count;
            }
            bytesLeftToRead -= bytesFromCurrent;
            fCurrent = fCurrent->fNext;
            fCurrentOffset = 0;
        }
        SkASSERT(false);
        return 0;
    }

<<<<<<< HEAD
    bool isAtEnd() const override
    {
        return fOffset == fSize;
    }

    size_t peek(void* buff, size_t bytesToPeek) const override
    {
        SkASSERT(buff != nullptr);

        bytesToPeek = SkTMin(bytesToPeek, fSize - fOffset);

        size_t bytesLeftToPeek = bytesToPeek;
        char* buffer = static_cast<char*>(buff);
        const SkDynamicMemoryWStream::Block* current = fCurrent;
        size_t currentOffset = fCurrentOffset;
        while (bytesLeftToPeek) {
            SkASSERT(current);
            size_t bytesFromCurrent = SkTMin(current->written() - currentOffset, bytesLeftToPeek);
            memcpy(buffer, current->start() + currentOffset, bytesFromCurrent);
            bytesLeftToPeek -= bytesFromCurrent;
=======
    bool isAtEnd() const override {
        return fOffset == fSize;
    }

    bool peek(void* buff, size_t size) const override {
        SkASSERT(buff != NULL);
        if (fOffset + size > fSize) {
            return false;
        }
        char* buffer = static_cast<char*>(buff);
        const SkDynamicMemoryWStream::Block* current = fCurrent;
        size_t currentOffset = fCurrentOffset;
        while (size) {
            SkASSERT(current);
            size_t bytesFromCurrent =
                    SkTMin(current->written() - currentOffset, size);
            memcpy(buffer, current->start() + currentOffset, bytesFromCurrent);
            size -= bytesFromCurrent;
>>>>>>> miniblink49
            buffer += bytesFromCurrent;
            current = current->fNext;
            currentOffset = 0;
        }
<<<<<<< HEAD
        return bytesToPeek;
    }

    bool rewind() override
    {
=======
        return true;
    }

    bool rewind() override {
>>>>>>> miniblink49
        fCurrent = fBlockMemory->fHead;
        fOffset = 0;
        fCurrentOffset = 0;
        return true;
    }

<<<<<<< HEAD
    SkBlockMemoryStream* duplicate() const override
    {
        return new SkBlockMemoryStream(fBlockMemory.get(), fSize);
    }

    size_t getPosition() const override
    {
        return fOffset;
    }

    bool seek(size_t position) override
    {
=======
    SkBlockMemoryStream* duplicate() const override {
        return SkNEW_ARGS(SkBlockMemoryStream, (fBlockMemory.get(), fSize));
    }

    size_t getPosition() const override {
        return fOffset;
    }

    bool seek(size_t position) override {
>>>>>>> miniblink49
        // If possible, skip forward.
        if (position >= fOffset) {
            size_t skipAmount = position - fOffset;
            return this->skip(skipAmount) == skipAmount;
        }
        // If possible, move backward within the current block.
        size_t moveBackAmount = fOffset - position;
        if (moveBackAmount <= fCurrentOffset) {
            fCurrentOffset -= moveBackAmount;
            fOffset -= moveBackAmount;
            return true;
        }
        // Otherwise rewind and move forward.
        return this->rewind() && this->skip(position) == position;
    }

<<<<<<< HEAD
    bool move(long offset) override
    {
        return seek(fOffset + offset);
    }

    SkBlockMemoryStream* fork() const override
    {
=======
    bool move(long offset) override {
        return seek(fOffset + offset);
    }

    SkBlockMemoryStream* fork() const override {
>>>>>>> miniblink49
        SkAutoTDelete<SkBlockMemoryStream> that(this->duplicate());
        that->fCurrent = this->fCurrent;
        that->fOffset = this->fOffset;
        that->fCurrentOffset = this->fCurrentOffset;
<<<<<<< HEAD
        return that.release();
    }

    size_t getLength() const override
    {
        return fSize;
    }

    const void* getMemoryBase() override
    {
        if (nullptr != fBlockMemory->fHead && nullptr == fBlockMemory->fHead->fNext) {
            return fBlockMemory->fHead->start();
        }
        return nullptr;
=======
        return that.detach();
    }

    size_t getLength() const override {
        return fSize;
    }

    const void* getMemoryBase() override {
        if (NULL == fBlockMemory->fHead->fNext) {
            return fBlockMemory->fHead->start();
        }
        return NULL;
>>>>>>> miniblink49
    }

private:
    SkAutoTUnref<SkBlockMemoryRefCnt> const fBlockMemory;
<<<<<<< HEAD
    SkDynamicMemoryWStream::Block const* fCurrent;
=======
    SkDynamicMemoryWStream::Block const * fCurrent;
>>>>>>> miniblink49
    size_t const fSize;
    size_t fOffset;
    size_t fCurrentOffset;
};

<<<<<<< HEAD
SkStreamAsset* SkDynamicMemoryWStream::detachAsStream()
{
    if (fCopy) {
        SkMemoryStream* stream = new SkMemoryStream(fCopy);
        this->reset();
        return stream;
    }
    SkBlockMemoryStream* stream = new SkBlockMemoryStream(fHead, fBytesWritten);
=======
SkStreamAsset* SkDynamicMemoryWStream::detachAsStream() {
    if (fCopy) {
        SkMemoryStream* stream = SkNEW_ARGS(SkMemoryStream, (fCopy));
        this->reset();
        return stream;
    }
    SkBlockMemoryStream* stream = SkNEW_ARGS(SkBlockMemoryStream, (fHead, fBytesWritten));
>>>>>>> miniblink49
    fHead = 0;
    this->reset();
    return stream;
}

///////////////////////////////////////////////////////////////////////////////

void SkDebugWStream::newline()
{
<<<<<<< HEAD
#if defined(SK_DEBUG)
=======
#if defined(SK_DEBUG) || defined(SK_DEVELOPER)
>>>>>>> miniblink49
    SkDebugf("\n");
    fBytesWritten++;
#endif
}

bool SkDebugWStream::write(const void* buffer, size_t size)
{
<<<<<<< HEAD
#if defined(SK_DEBUG)
    char* s = new char[size + 1];
=======
#if defined(SK_DEBUG) || defined(SK_DEVELOPER)
    char* s = new char[size+1];
>>>>>>> miniblink49
    memcpy(s, buffer, size);
    s[size] = 0;
    SkDebugf("%s", s);
    delete[] s;
    fBytesWritten += size;
#endif
    return true;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static sk_sp<SkData> mmap_filename(const char path[])
{
    FILE* file = sk_fopen(path, kRead_SkFILE_Flag);
    if (nullptr == file) {
        return nullptr;
    }

    auto data = SkData::MakeFromFILE(file);
=======

static SkData* mmap_filename(const char path[]) {
    SkFILE* file = sk_fopen(path, kRead_SkFILE_Flag);
    if (NULL == file) {
        return NULL;
    }

    SkData* data = SkData::NewFromFILE(file);
>>>>>>> miniblink49
    sk_fclose(file);
    return data;
}

<<<<<<< HEAD
SkStreamAsset* SkStream::NewFromFile(const char path[])
{
    auto data(mmap_filename(path));
    if (data) {
        return new SkMemoryStream(std::move(data));
=======
SkStreamAsset* SkStream::NewFromFile(const char path[]) {
    SkAutoTUnref<SkData> data(mmap_filename(path));
    if (data.get()) {
        return SkNEW_ARGS(SkMemoryStream, (data.get()));
>>>>>>> miniblink49
    }

    // If we get here, then our attempt at using mmap failed, so try normal
    // file access.
<<<<<<< HEAD
    SkFILEStream* stream = new SkFILEStream(path);
    if (!stream->isValid()) {
        delete stream;
        stream = nullptr;
=======
    SkFILEStream* stream = SkNEW_ARGS(SkFILEStream, (path));
    if (!stream->isValid()) {
        SkDELETE(stream);
        stream = NULL;
>>>>>>> miniblink49
    }
    return stream;
}

// Declared in SkStreamPriv.h:
<<<<<<< HEAD
sk_sp<SkData> SkCopyStreamToData(SkStream* stream)
{
    SkASSERT(stream != nullptr);

    if (stream->hasLength()) {
        return SkData::MakeFromStream(stream, stream->getLength());
=======
size_t SkCopyStreamToStorage(SkAutoMalloc* storage, SkStream* stream) {
    SkASSERT(storage != NULL);
    SkASSERT(stream != NULL);

    if (stream->hasLength()) {
        const size_t length = stream->getLength();
        void* dst = storage->reset(length);
        if (stream->read(dst, length) != length) {
            return 0;
        }
        return length;
    }

    SkDynamicMemoryWStream tempStream;
    // Arbitrary buffer size.
    const size_t bufferSize = 256 * 1024; // 256KB
    char buffer[bufferSize];
    SkDEBUGCODE(size_t debugLength = 0;)
    do {
        size_t bytesRead = stream->read(buffer, bufferSize);
        tempStream.write(buffer, bytesRead);
        SkDEBUGCODE(debugLength += bytesRead);
        SkASSERT(tempStream.bytesWritten() == debugLength);
    } while (!stream->isAtEnd());
    const size_t length = tempStream.bytesWritten();
    void* dst = storage->reset(length);
    tempStream.copyTo(dst);
    return length;
}

// Declared in SkStreamPriv.h:
SkData* SkCopyStreamToData(SkStream* stream) {
    SkASSERT(stream != NULL);

    if (stream->hasLength()) {
        return SkData::NewFromStream(stream, stream->getLength());
>>>>>>> miniblink49
    }

    SkDynamicMemoryWStream tempStream;
    const size_t bufferSize = 4096;
    char buffer[bufferSize];
    do {
        size_t bytesRead = stream->read(buffer, bufferSize);
        tempStream.write(buffer, bytesRead);
    } while (!stream->isAtEnd());
<<<<<<< HEAD
    return sk_sp<SkData>(tempStream.copyToData());
}

bool SkStreamCopy(SkWStream* out, SkStream* input)
{
    const char* base = static_cast<const char*>(input->getMemoryBase());
    if (base && input->hasPosition() && input->hasLength()) {
        // Shortcut that avoids the while loop.
        size_t position = input->getPosition();
        size_t length = input->getLength();
        SkASSERT(length >= position);
        return out->write(&base[position], length - position);
    }
    char scratch[4096];
    size_t count;
    while (true) {
        count = input->read(scratch, sizeof(scratch));
        if (0 == count) {
            return true;
        }
        if (!out->write(scratch, count)) {
            return false;
        }
    }
=======
    return tempStream.copyToData();
}

SkStreamRewindable* SkStreamRewindableFromSkStream(SkStream* stream) {
    if (!stream) {
        return NULL;
    }
    SkAutoTDelete<SkStreamRewindable> dupStream(stream->duplicate());
    if (dupStream) {
        return dupStream.detach();
    }
    stream->rewind();
    if (stream->hasLength()) {
        size_t length = stream->getLength();
        if (stream->hasPosition()) {  // If stream has length, but can't rewind.
            length -= stream->getPosition();
        }
        SkAutoTUnref<SkData> data(SkData::NewFromStream(stream, length));
        return SkNEW_ARGS(SkMemoryStream, (data.get()));
    }
    SkDynamicMemoryWStream tempStream;
    const size_t bufferSize = 4096;
    char buffer[bufferSize];
    do {
        size_t bytesRead = stream->read(buffer, bufferSize);
        tempStream.write(buffer, bytesRead);
    } while (!stream->isAtEnd());
    return tempStream.detachAsStream();  // returns a SkBlockMemoryStream,
                                         // cheaper than copying to SkData
>>>>>>> miniblink49
}
