/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkTypes.h"
#if defined(SK_BUILD_FOR_WIN32)

#include "SkDWriteFontFileStream.h"
#include "SkHRESULT.h"
#include "SkTFitsIn.h"
#include "SkTScopedComPtr.h"
#include "SkTemplates.h"
#include "SkTypes.h"
=======

#include "SkTypes.h"
#include "SkDWriteFontFileStream.h"
#include "SkHRESULT.h"
#include "SkTemplates.h"
#include "SkTFitsIn.h"
#include "SkTScopedComPtr.h"
>>>>>>> miniblink49

#include <dwrite.h>

///////////////////////////////////////////////////////////////////////////////
//  SkIDWriteFontFileStream

SkDWriteFontFileStream::SkDWriteFontFileStream(IDWriteFontFileStream* fontFileStream)
    : fFontFileStream(SkRefComPtr(fontFileStream))
    , fPos(0)
<<<<<<< HEAD
    , fLockedMemory(nullptr)
    , fFragmentLock(nullptr)
{
}

SkDWriteFontFileStream::~SkDWriteFontFileStream()
{
=======
    , fLockedMemory(NULL)
    , fFragmentLock(NULL) {
}

SkDWriteFontFileStream::~SkDWriteFontFileStream() {
>>>>>>> miniblink49
    if (fFragmentLock) {
        fFontFileStream->ReleaseFileFragment(fFragmentLock);
    }
}

<<<<<<< HEAD
size_t SkDWriteFontFileStream::read(void* buffer, size_t size)
{
    HRESULT hr = S_OK;

    if (nullptr == buffer) {
=======
size_t SkDWriteFontFileStream::read(void* buffer, size_t size) {
    HRESULT hr = S_OK;

    if (NULL == buffer) {
>>>>>>> miniblink49
        size_t fileSize = this->getLength();

        if (fPos + size > fileSize) {
            size_t skipped = fileSize - fPos;
            fPos = fileSize;
            return skipped;
        } else {
            fPos += size;
            return size;
        }
    }

    const void* start;
    void* fragmentLock;
    hr = fFontFileStream->ReadFileFragment(&start, fPos, size, &fragmentLock);
    if (SUCCEEDED(hr)) {
        memcpy(buffer, start, size);
        fFontFileStream->ReleaseFileFragment(fragmentLock);
        fPos += size;
        return size;
    }

    //The read may have failed because we asked for too much data.
    size_t fileSize = this->getLength();
    if (fPos + size <= fileSize) {
        //This means we were within bounds, but failed for some other reason.
        return 0;
    }

    size_t read = fileSize - fPos;
    hr = fFontFileStream->ReadFileFragment(&start, fPos, read, &fragmentLock);
    if (SUCCEEDED(hr)) {
        memcpy(buffer, start, read);
        fFontFileStream->ReleaseFileFragment(fragmentLock);
        fPos = fileSize;
        return read;
    }

    return 0;
}

<<<<<<< HEAD
bool SkDWriteFontFileStream::isAtEnd() const
{
    return fPos == this->getLength();
}

bool SkDWriteFontFileStream::rewind()
{
=======
bool SkDWriteFontFileStream::isAtEnd() const {
    return fPos == this->getLength();
}

bool SkDWriteFontFileStream::rewind() {
>>>>>>> miniblink49
    fPos = 0;
    return true;
}

<<<<<<< HEAD
SkDWriteFontFileStream* SkDWriteFontFileStream::duplicate() const
{
    return new SkDWriteFontFileStream(fFontFileStream.get());
}

size_t SkDWriteFontFileStream::getPosition() const
{
    return fPos;
}

bool SkDWriteFontFileStream::seek(size_t position)
{
=======
SkDWriteFontFileStream* SkDWriteFontFileStream::duplicate() const {
    return SkNEW_ARGS(SkDWriteFontFileStream, (fFontFileStream.get()));
}

size_t SkDWriteFontFileStream::getPosition() const {
    return fPos;
}

bool SkDWriteFontFileStream::seek(size_t position) {
>>>>>>> miniblink49
    size_t length = this->getLength();
    fPos = (position > length) ? length : position;
    return true;
}

<<<<<<< HEAD
bool SkDWriteFontFileStream::move(long offset)
{
    return seek(fPos + offset);
}

SkDWriteFontFileStream* SkDWriteFontFileStream::fork() const
{
    SkAutoTDelete<SkDWriteFontFileStream> that(this->duplicate());
    that->seek(fPos);
    return that.release();
}

size_t SkDWriteFontFileStream::getLength() const
{
=======
bool SkDWriteFontFileStream::move(long offset) {
    return seek(fPos + offset);
}

SkDWriteFontFileStream* SkDWriteFontFileStream::fork() const {
    SkAutoTDelete<SkDWriteFontFileStream> that(this->duplicate());
    that->seek(fPos);
    return that.detach();
}

size_t SkDWriteFontFileStream::getLength() const {
>>>>>>> miniblink49
    HRESULT hr = S_OK;
    UINT64 realFileSize = 0;
    hr = fFontFileStream->GetFileSize(&realFileSize);
    if (!SkTFitsIn<size_t>(realFileSize)) {
        return 0;
    }
    return static_cast<size_t>(realFileSize);
}

<<<<<<< HEAD
const void* SkDWriteFontFileStream::getMemoryBase()
{
=======
const void* SkDWriteFontFileStream::getMemoryBase() {
>>>>>>> miniblink49
    if (fLockedMemory) {
        return fLockedMemory;
    }

    UINT64 fileSize;
    HRNM(fFontFileStream->GetFileSize(&fileSize), "Could not get file size");
    HRNM(fFontFileStream->ReadFileFragment(&fLockedMemory, 0, fileSize, &fFragmentLock),
<<<<<<< HEAD
        "Could not lock file fragment.");
=======
         "Could not lock file fragment.");
>>>>>>> miniblink49
    return fLockedMemory;
}

///////////////////////////////////////////////////////////////////////////////
//  SkIDWriteFontFileStreamWrapper

HRESULT SkDWriteFontFileStreamWrapper::Create(SkStreamAsset* stream,
<<<<<<< HEAD
    SkDWriteFontFileStreamWrapper** streamFontFileStream)
{
    *streamFontFileStream = new SkDWriteFontFileStreamWrapper(stream);
    if (nullptr == *streamFontFileStream) {
=======
                                              SkDWriteFontFileStreamWrapper** streamFontFileStream)
{
    *streamFontFileStream = new SkDWriteFontFileStreamWrapper(stream);
    if (NULL == streamFontFileStream) {
>>>>>>> miniblink49
        return E_OUTOFMEMORY;
    }
    return S_OK;
}

SkDWriteFontFileStreamWrapper::SkDWriteFontFileStreamWrapper(SkStreamAsset* stream)
<<<<<<< HEAD
    : fRefCount(1)
    , fStream(stream)
{
}

HRESULT STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::QueryInterface(REFIID iid, void** ppvObject)
{
=======
    : fRefCount(1), fStream(stream) {
}

HRESULT STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::QueryInterface(REFIID iid, void** ppvObject) {
>>>>>>> miniblink49
    if (iid == IID_IUnknown || iid == __uuidof(IDWriteFontFileStream)) {
        *ppvObject = this;
        AddRef();
        return S_OK;
    } else {
<<<<<<< HEAD
        *ppvObject = nullptr;
=======
        *ppvObject = NULL;
>>>>>>> miniblink49
        return E_NOINTERFACE;
    }
}

<<<<<<< HEAD
ULONG STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::AddRef()
{
    return InterlockedIncrement(&fRefCount);
}

ULONG STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::Release()
{
=======
ULONG STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::AddRef() {
    return InterlockedIncrement(&fRefCount);
}

ULONG STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::Release() {
>>>>>>> miniblink49
    ULONG newCount = InterlockedDecrement(&fRefCount);
    if (0 == newCount) {
        delete this;
    }
    return newCount;
}

HRESULT STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::ReadFileFragment(
    void const** fragmentStart,
    UINT64 fileOffset,
    UINT64 fragmentSize,
    void** fragmentContext)
{
    // The loader is responsible for doing a bounds check.
    UINT64 fileSize;
    this->GetFileSize(&fileSize);
    if (fileOffset > fileSize || fragmentSize > fileSize - fileOffset) {
<<<<<<< HEAD
        *fragmentStart = nullptr;
        *fragmentContext = nullptr;
=======
        *fragmentStart = NULL;
        *fragmentContext = NULL;
>>>>>>> miniblink49
        return E_FAIL;
    }

    if (!SkTFitsIn<size_t>(fileOffset + fragmentSize)) {
        return E_FAIL;
    }

    const void* data = fStream->getMemoryBase();
    if (data) {
        *fragmentStart = static_cast<BYTE const*>(data) + static_cast<size_t>(fileOffset);
<<<<<<< HEAD
        *fragmentContext = nullptr;
=======
        *fragmentContext = NULL;
>>>>>>> miniblink49

    } else {
        // May be called from multiple threads.
        SkAutoMutexAcquire ama(fStreamMutex);

<<<<<<< HEAD
        *fragmentStart = nullptr;
        *fragmentContext = nullptr;
=======
        *fragmentStart = NULL;
        *fragmentContext = NULL;
>>>>>>> miniblink49

        if (!fStream->seek(static_cast<size_t>(fileOffset))) {
            return E_FAIL;
        }
        SkAutoTMalloc<uint8_t> streamData(static_cast<size_t>(fragmentSize));
        if (fStream->read(streamData.get(), static_cast<size_t>(fragmentSize)) != fragmentSize) {
            return E_FAIL;
        }

        *fragmentStart = streamData.get();
<<<<<<< HEAD
        *fragmentContext = streamData.release();
=======
        *fragmentContext = streamData.detach();
>>>>>>> miniblink49
    }
    return S_OK;
}

<<<<<<< HEAD
void STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::ReleaseFileFragment(void* fragmentContext)
{
    sk_free(fragmentContext);
}

HRESULT STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::GetFileSize(UINT64* fileSize)
{
=======
void STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::ReleaseFileFragment(void* fragmentContext) {
    sk_free(fragmentContext);
}

HRESULT STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::GetFileSize(UINT64* fileSize) {
>>>>>>> miniblink49
    *fileSize = fStream->getLength();
    return S_OK;
}

<<<<<<< HEAD
HRESULT STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::GetLastWriteTime(UINT64* lastWriteTime)
{
=======
HRESULT STDMETHODCALLTYPE SkDWriteFontFileStreamWrapper::GetLastWriteTime(UINT64* lastWriteTime) {
>>>>>>> miniblink49
    // The concept of last write time does not apply to this loader.
    *lastWriteTime = 0;
    return E_NOTIMPL;
}
<<<<<<< HEAD

#endif //defined(SK_BUILD_FOR_WIN32)
=======
>>>>>>> miniblink49
