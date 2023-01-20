/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkFrontBufferedStream.h"
#include "SkStream.h"
#include "SkTemplates.h"

class FrontBufferedStream : public SkStreamRewindable {
public:
    // Called by Create.
    FrontBufferedStream(SkStream*, size_t bufferSize);

    size_t read(void* buffer, size_t size) override;

<<<<<<< HEAD
    size_t peek(void* buffer, size_t size) const override;
=======
    bool peek(void* buffer, size_t size) const override;
>>>>>>> miniblink49

    bool isAtEnd() const override;

    bool rewind() override;

<<<<<<< HEAD
=======
    bool hasPosition() const override { return true; }

    size_t getPosition() const override { return fOffset; }

>>>>>>> miniblink49
    bool hasLength() const override { return fHasLength; }

    size_t getLength() const override { return fLength; }

<<<<<<< HEAD
    SkStreamRewindable* duplicate() const override { return nullptr; }

private:
    SkAutoTDelete<SkStream> fStream;
    const bool fHasLength;
    const size_t fLength;
    // Current offset into the stream. Always >= 0.
    size_t fOffset;
    // Amount that has been buffered by calls to read. Will always be less than
    // fBufferSize.
    size_t fBufferedSoFar;
    // Total size of the buffer.
    const size_t fBufferSize;
    // FIXME: SkAutoTMalloc throws on failure. Instead, Create should return a
    // nullptr stream.
    SkAutoTMalloc<char> fBuffer;

    // Read up to size bytes from already buffered data, and copy to
    // dst, if non-nullptr. Updates fOffset. Assumes that fOffset is less
=======
    SkStreamRewindable* duplicate() const override { return NULL; }

private:
    SkAutoTDelete<SkStream> fStream;
    const bool              fHasLength;
    const size_t            fLength;
    // Current offset into the stream. Always >= 0.
    size_t                  fOffset;
    // Amount that has been buffered by calls to read. Will always be less than
    // fBufferSize.
    size_t                  fBufferedSoFar;
    // Total size of the buffer.
    const size_t            fBufferSize;
    // FIXME: SkAutoTMalloc throws on failure. Instead, Create should return a
    // NULL stream.
    SkAutoTMalloc<char>     fBuffer;

    // Read up to size bytes from already buffered data, and copy to
    // dst, if non-NULL. Updates fOffset. Assumes that fOffset is less
>>>>>>> miniblink49
    // than fBufferedSoFar.
    size_t readFromBuffer(char* dst, size_t size);

    // Buffer up to size bytes from the stream, and copy to dst if non-
<<<<<<< HEAD
    // nullptr. Updates fOffset and fBufferedSoFar. Assumes that fOffset is
=======
    // NULL. Updates fOffset and fBufferedSoFar. Assumes that fOffset is
>>>>>>> miniblink49
    // less than fBufferedSoFar, and size is greater than 0.
    size_t bufferAndWriteTo(char* dst, size_t size);

    // Read up to size bytes directly from the stream and into dst if non-
<<<<<<< HEAD
    // nullptr. Updates fOffset. Assumes fOffset is at or beyond the buffered
=======
    // NULL. Updates fOffset. Assumes fOffset is at or beyond the buffered
>>>>>>> miniblink49
    // data, and size is greater than 0.
    size_t readDirectlyFromStream(char* dst, size_t size);

    typedef SkStream INHERITED;
};

<<<<<<< HEAD
SkStreamRewindable* SkFrontBufferedStream::Create(SkStream* stream, size_t bufferSize)
{
    if (nullptr == stream) {
        return nullptr;
    }
    return new FrontBufferedStream(stream, bufferSize);
=======
SkStreamRewindable* SkFrontBufferedStream::Create(SkStream* stream, size_t bufferSize) {
    if (NULL == stream) {
        return NULL;
    }
    return SkNEW_ARGS(FrontBufferedStream, (stream, bufferSize));
>>>>>>> miniblink49
}

FrontBufferedStream::FrontBufferedStream(SkStream* stream, size_t bufferSize)
    : fStream(stream)
    , fHasLength(stream->hasPosition() && stream->hasLength())
    , fLength(stream->getLength() - stream->getPosition())
    , fOffset(0)
    , fBufferedSoFar(0)
    , fBufferSize(bufferSize)
<<<<<<< HEAD
    , fBuffer(bufferSize)
{
}

bool FrontBufferedStream::isAtEnd() const
{
=======
    , fBuffer(bufferSize) {}

bool FrontBufferedStream::isAtEnd() const {
>>>>>>> miniblink49
    if (fOffset < fBufferedSoFar) {
        // Even if the underlying stream is at the end, this stream has been
        // rewound after buffering, so it is not at the end.
        return false;
    }

    return fStream->isAtEnd();
}

<<<<<<< HEAD
bool FrontBufferedStream::rewind()
{
=======
bool FrontBufferedStream::rewind() {
>>>>>>> miniblink49
    // Only allow a rewind if we have not exceeded the buffer.
    if (fOffset <= fBufferSize) {
        fOffset = 0;
        return true;
    }
    return false;
}

<<<<<<< HEAD
size_t FrontBufferedStream::readFromBuffer(char* dst, size_t size)
{
=======
size_t FrontBufferedStream::readFromBuffer(char* dst, size_t size) {
>>>>>>> miniblink49
    SkASSERT(fOffset < fBufferedSoFar);
    // Some data has already been copied to fBuffer. Read up to the
    // lesser of the size requested and the remainder of the buffered
    // data.
    const size_t bytesToCopy = SkTMin(size, fBufferedSoFar - fOffset);
<<<<<<< HEAD
    if (dst != nullptr) {
=======
    if (dst != NULL) {
>>>>>>> miniblink49
        memcpy(dst, fBuffer + fOffset, bytesToCopy);
    }

    // Update fOffset to the new position. It is guaranteed to be
    // within the buffered data.
    fOffset += bytesToCopy;
    SkASSERT(fOffset <= fBufferedSoFar);

    return bytesToCopy;
}

<<<<<<< HEAD
size_t FrontBufferedStream::bufferAndWriteTo(char* dst, size_t size)
{
=======
size_t FrontBufferedStream::bufferAndWriteTo(char* dst, size_t size) {
>>>>>>> miniblink49
    SkASSERT(size > 0);
    SkASSERT(fOffset >= fBufferedSoFar);
    SkASSERT(fBuffer);
    // Data needs to be buffered. Buffer up to the lesser of the size requested
    // and the remainder of the max buffer size.
    const size_t bytesToBuffer = SkTMin(size, fBufferSize - fBufferedSoFar);
    char* buffer = fBuffer + fOffset;
    const size_t buffered = fStream->read(buffer, bytesToBuffer);

    fBufferedSoFar += buffered;
    fOffset = fBufferedSoFar;
    SkASSERT(fBufferedSoFar <= fBufferSize);

    // Copy the buffer to the destination buffer and update the amount read.
<<<<<<< HEAD
    if (dst != nullptr) {
=======
    if (dst != NULL) {
>>>>>>> miniblink49
        memcpy(dst, buffer, buffered);
    }

    return buffered;
}

<<<<<<< HEAD
size_t FrontBufferedStream::readDirectlyFromStream(char* dst, size_t size)
{
=======
size_t FrontBufferedStream::readDirectlyFromStream(char* dst, size_t size) {
>>>>>>> miniblink49
    SkASSERT(size > 0);
    // If we get here, we have buffered all that can be buffered.
    SkASSERT(fBufferSize == fBufferedSoFar && fOffset >= fBufferSize);

    const size_t bytesReadDirectly = fStream->read(dst, size);
    fOffset += bytesReadDirectly;

    // If we have read past the end of the buffer, rewinding is no longer
    // supported, so we can go ahead and free the memory.
    if (bytesReadDirectly > 0) {
<<<<<<< HEAD
        sk_free(fBuffer.release());
=======
        sk_free(fBuffer.detach());
>>>>>>> miniblink49
    }

    return bytesReadDirectly;
}

<<<<<<< HEAD
size_t FrontBufferedStream::peek(void* dst, size_t size) const
{
    // Keep track of the offset so we can return to it.
    const size_t start = fOffset;

    if (start >= fBufferSize) {
        // This stream is not able to buffer.
        return 0;
    }

    size = SkTMin(size, fBufferSize - start);
    FrontBufferedStream* nonConstThis = const_cast<FrontBufferedStream*>(this);
    const size_t bytesRead = nonConstThis->read(dst, size);
    nonConstThis->fOffset = start;
    return bytesRead;
}

size_t FrontBufferedStream::read(void* voidDst, size_t size)
{
    // Cast voidDst to a char* for easy addition.
    char* dst = reinterpret_cast<char*>(voidDst);
    SkDEBUGCODE(const size_t totalSize = size;)
        const size_t start
        = fOffset;
=======
bool FrontBufferedStream::peek(void* dst, size_t size) const {
    // Keep track of the offset so we can return to it.
    const size_t start = fOffset;
    if (start + size > fBufferSize) {
        // This stream is not able to buffer enough.
        return false;
    }
    FrontBufferedStream* nonConstThis = const_cast<FrontBufferedStream*>(this);
    SkDEBUGCODE(const size_t bytesRead =) nonConstThis->read(dst, size);
    SkASSERT(bytesRead == size);
    nonConstThis->fOffset = start;
    return true;
}

size_t FrontBufferedStream::read(void* voidDst, size_t size) {
    // Cast voidDst to a char* for easy addition.
    char* dst = reinterpret_cast<char*>(voidDst);
    SkDEBUGCODE(const size_t totalSize = size;)
    const size_t start = fOffset;
>>>>>>> miniblink49

    // First, read any data that was previously buffered.
    if (fOffset < fBufferedSoFar) {
        const size_t bytesCopied = this->readFromBuffer(dst, size);

        // Update the remaining number of bytes needed to read
        // and the destination buffer.
        size -= bytesCopied;
        SkASSERT(size + (fOffset - start) == totalSize);
<<<<<<< HEAD
        if (dst != nullptr) {
=======
        if (dst != NULL) {
>>>>>>> miniblink49
            dst += bytesCopied;
        }
    }

    // Buffer any more data that should be buffered, and copy it to the
    // destination.
    if (size > 0 && fBufferedSoFar < fBufferSize && !fStream->isAtEnd()) {
        const size_t buffered = this->bufferAndWriteTo(dst, size);

        // Update the remaining number of bytes needed to read
        // and the destination buffer.
        size -= buffered;
        SkASSERT(size + (fOffset - start) == totalSize);
<<<<<<< HEAD
        if (dst != nullptr) {
=======
        if (dst != NULL) {
>>>>>>> miniblink49
            dst += buffered;
        }
    }

    if (size > 0 && !fStream->isAtEnd()) {
        SkDEBUGCODE(const size_t bytesReadDirectly =) this->readDirectlyFromStream(dst, size);
        SkDEBUGCODE(size -= bytesReadDirectly;)
<<<<<<< HEAD
            SkASSERT(size + (fOffset - start) == totalSize);
=======
        SkASSERT(size + (fOffset - start) == totalSize);
>>>>>>> miniblink49
    }

    return fOffset - start;
}
