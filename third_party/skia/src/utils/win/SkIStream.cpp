<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTypes.h"
#if defined(SK_BUILD_FOR_WIN32)

=======

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <ole2.h>
>>>>>>> miniblink49
#include "SkIStream.h"
#include "SkStream.h"

/**
 * SkBaseIStream
 */
<<<<<<< HEAD
SkBaseIStream::SkBaseIStream()
    : _refcount(1)
{
}
SkBaseIStream::~SkBaseIStream() { }

HRESULT STDMETHODCALLTYPE SkBaseIStream::QueryInterface(REFIID iid, void** ppvObject)
{
    if (nullptr == ppvObject) {
=======
SkBaseIStream::SkBaseIStream() : _refcount(1) { }
SkBaseIStream::~SkBaseIStream() { }

HRESULT STDMETHODCALLTYPE SkBaseIStream::QueryInterface(REFIID iid
                                                      , void ** ppvObject)
{
    if (NULL == ppvObject) {
>>>>>>> miniblink49
        return E_INVALIDARG;
    }
    if (iid == __uuidof(IUnknown)
        || iid == __uuidof(IStream)
<<<<<<< HEAD
        || iid == __uuidof(ISequentialStream)) {
=======
        || iid == __uuidof(ISequentialStream))
    {
>>>>>>> miniblink49
        *ppvObject = static_cast<IStream*>(this);
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
ULONG STDMETHODCALLTYPE SkBaseIStream::AddRef(void)
{
    return (ULONG)InterlockedIncrement(&_refcount);
}

ULONG STDMETHODCALLTYPE SkBaseIStream::Release(void)
{
    ULONG res = (ULONG)InterlockedDecrement(&_refcount);
=======
ULONG STDMETHODCALLTYPE SkBaseIStream::AddRef(void) {
    return (ULONG)InterlockedIncrement(&_refcount);
}

ULONG STDMETHODCALLTYPE SkBaseIStream::Release(void) {
    ULONG res = (ULONG) InterlockedDecrement(&_refcount);
>>>>>>> miniblink49
    if (0 == res) {
        delete this;
    }
    return res;
}

// ISequentialStream Interface
<<<<<<< HEAD
HRESULT STDMETHODCALLTYPE SkBaseIStream::Read(void* pv, ULONG cb, ULONG* pcbRead)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SkBaseIStream::Write(void const* pv, ULONG cb, ULONG* pcbWritten)
{
    return E_NOTIMPL;
}

// IStream Interface
HRESULT STDMETHODCALLTYPE SkBaseIStream::SetSize(ULARGE_INTEGER)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SkBaseIStream::CopyTo(IStream*, ULARGE_INTEGER, ULARGE_INTEGER*, ULARGE_INTEGER*)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SkBaseIStream::Commit(DWORD)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SkBaseIStream::Revert(void)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SkBaseIStream::LockRegion(ULARGE_INTEGER, ULARGE_INTEGER, DWORD)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SkBaseIStream::UnlockRegion(ULARGE_INTEGER, ULARGE_INTEGER, DWORD)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SkBaseIStream::Clone(IStream**)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SkBaseIStream::Seek(LARGE_INTEGER liDistanceToMove, DWORD dwOrigin, ULARGE_INTEGER* lpNewFilePointer)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE SkBaseIStream::Stat(STATSTG* pStatstg, DWORD grfStatFlag)
{
    return E_NOTIMPL;
}
=======
HRESULT STDMETHODCALLTYPE SkBaseIStream::Read(void* pv
                                            , ULONG cb
                                            , ULONG* pcbRead)
{ return E_NOTIMPL; }

HRESULT STDMETHODCALLTYPE SkBaseIStream::Write(void const* pv
                                             , ULONG cb
                                             , ULONG* pcbWritten)
{ return E_NOTIMPL; }

// IStream Interface
HRESULT STDMETHODCALLTYPE SkBaseIStream::SetSize(ULARGE_INTEGER)
{ return E_NOTIMPL; }

HRESULT STDMETHODCALLTYPE SkBaseIStream::CopyTo(IStream*
                                              , ULARGE_INTEGER
                                              , ULARGE_INTEGER*
                                              , ULARGE_INTEGER*)
{ return E_NOTIMPL; }

HRESULT STDMETHODCALLTYPE SkBaseIStream::Commit(DWORD)
{ return E_NOTIMPL; }

HRESULT STDMETHODCALLTYPE SkBaseIStream::Revert(void)
{ return E_NOTIMPL; }

HRESULT STDMETHODCALLTYPE SkBaseIStream::LockRegion(ULARGE_INTEGER
                                                  , ULARGE_INTEGER
                                                  , DWORD)
{ return E_NOTIMPL; }

HRESULT STDMETHODCALLTYPE SkBaseIStream::UnlockRegion(ULARGE_INTEGER
                                                    , ULARGE_INTEGER
                                                    , DWORD)
{ return E_NOTIMPL; }

HRESULT STDMETHODCALLTYPE SkBaseIStream::Clone(IStream **)
{ return E_NOTIMPL; }

HRESULT STDMETHODCALLTYPE SkBaseIStream::Seek(LARGE_INTEGER liDistanceToMove
                                            , DWORD dwOrigin
                                            , ULARGE_INTEGER* lpNewFilePointer)
{ return E_NOTIMPL; }

HRESULT STDMETHODCALLTYPE SkBaseIStream::Stat(STATSTG* pStatstg
                                            , DWORD grfStatFlag)
{ return E_NOTIMPL; }

>>>>>>> miniblink49

/**
 * SkIStream
 */
SkIStream::SkIStream(SkStream* stream, bool deleteOnRelease)
    : SkBaseIStream()
    , fSkStream(stream)
    , fDeleteOnRelease(deleteOnRelease)
    , fLocation()
{
    this->fSkStream->rewind();
}

<<<<<<< HEAD
SkIStream::~SkIStream()
{
=======
SkIStream::~SkIStream() {
>>>>>>> miniblink49
    if (fDeleteOnRelease) {
        delete this->fSkStream;
    }
}

<<<<<<< HEAD
HRESULT SkIStream::CreateFromSkStream(SkStream* stream, bool deleteOnRelease, IStream** ppStream)
{
    if (nullptr == stream) {
=======
HRESULT SkIStream::CreateFromSkStream(SkStream* stream
                                    , bool deleteOnRelease
                                    , IStream ** ppStream)
{
    if (NULL == stream) {
>>>>>>> miniblink49
        return E_INVALIDARG;
    }
    *ppStream = new SkIStream(stream, deleteOnRelease);
    return S_OK;
}

// ISequentialStream Interface
<<<<<<< HEAD
HRESULT STDMETHODCALLTYPE SkIStream::Read(void* pv, ULONG cb, ULONG* pcbRead)
{
=======
HRESULT STDMETHODCALLTYPE SkIStream::Read(void* pv, ULONG cb, ULONG* pcbRead) {
>>>>>>> miniblink49
    *pcbRead = static_cast<ULONG>(this->fSkStream->read(pv, cb));
    this->fLocation.QuadPart += *pcbRead;
    return (*pcbRead == cb) ? S_OK : S_FALSE;
}

<<<<<<< HEAD
HRESULT STDMETHODCALLTYPE SkIStream::Write(void const* pv, ULONG cb, ULONG* pcbWritten)
=======
HRESULT STDMETHODCALLTYPE SkIStream::Write(void const* pv
                                         , ULONG cb
                                         , ULONG* pcbWritten)
>>>>>>> miniblink49
{
    return STG_E_CANTSAVE;
}

// IStream Interface
<<<<<<< HEAD
HRESULT STDMETHODCALLTYPE SkIStream::Seek(LARGE_INTEGER liDistanceToMove, DWORD dwOrigin, ULARGE_INTEGER* lpNewFilePointer)
{
    HRESULT hr = S_OK;

    switch (dwOrigin) {
=======
HRESULT STDMETHODCALLTYPE SkIStream::Seek(LARGE_INTEGER liDistanceToMove
                                        , DWORD dwOrigin
                                        , ULARGE_INTEGER* lpNewFilePointer)
{
    HRESULT hr = S_OK;

    switch(dwOrigin) {
>>>>>>> miniblink49
    case STREAM_SEEK_SET: {
        if (!this->fSkStream->rewind()) {
            hr = E_FAIL;
        } else {
            size_t skipped = this->fSkStream->skip(
<<<<<<< HEAD
                static_cast<size_t>(liDistanceToMove.QuadPart));
=======
                static_cast<size_t>(liDistanceToMove.QuadPart)
            );
>>>>>>> miniblink49
            this->fLocation.QuadPart = skipped;
            if (skipped != liDistanceToMove.QuadPart) {
                hr = E_FAIL;
            }
        }
        break;
    }
    case STREAM_SEEK_CUR: {
        size_t skipped = this->fSkStream->skip(
<<<<<<< HEAD
            static_cast<size_t>(liDistanceToMove.QuadPart));
=======
            static_cast<size_t>(liDistanceToMove.QuadPart)
        );
>>>>>>> miniblink49
        this->fLocation.QuadPart += skipped;
        if (skipped != liDistanceToMove.QuadPart) {
            hr = E_FAIL;
        }
        break;
    }
    case STREAM_SEEK_END: {
        if (!this->fSkStream->rewind()) {
            hr = E_FAIL;
        } else {
            // FIXME: Should not depend on getLength.
            // See https://code.google.com/p/skia/issues/detail?id=1570
            LONGLONG skip = this->fSkStream->getLength()
<<<<<<< HEAD
                + liDistanceToMove.QuadPart;
=======
                          + liDistanceToMove.QuadPart;
>>>>>>> miniblink49
            size_t skipped = this->fSkStream->skip(static_cast<size_t>(skip));
            this->fLocation.QuadPart = skipped;
            if (skipped != skip) {
                hr = E_FAIL;
            }
        }
        break;
    }
    default:
        hr = STG_E_INVALIDFUNCTION;
        break;
    }

    if (lpNewFilePointer) {
        lpNewFilePointer->QuadPart = this->fLocation.QuadPart;
    }
    return hr;
}

<<<<<<< HEAD
HRESULT STDMETHODCALLTYPE SkIStream::Stat(STATSTG* pStatstg, DWORD grfStatFlag)
=======
HRESULT STDMETHODCALLTYPE SkIStream::Stat(STATSTG* pStatstg
                                        , DWORD grfStatFlag)
>>>>>>> miniblink49
{
    if (0 == (grfStatFlag & STATFLAG_NONAME)) {
        return STG_E_INVALIDFLAG;
    }
<<<<<<< HEAD
    pStatstg->pwcsName = nullptr;
=======
    pStatstg->pwcsName = NULL;
>>>>>>> miniblink49
    // FIXME: Should not depend on getLength
    // See https://code.google.com/p/skia/issues/detail?id=1570
    pStatstg->cbSize.QuadPart = this->fSkStream->getLength();
    pStatstg->clsid = CLSID_NULL;
    pStatstg->type = STGTY_STREAM;
    pStatstg->grfMode = STGM_READ;
    return S_OK;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
/**
 * SkIWStream
 */
SkWIStream::SkWIStream(SkWStream* stream)
    : SkBaseIStream()
    , fSkWStream(stream)
<<<<<<< HEAD
{
}

SkWIStream::~SkWIStream()
{
=======
{ }

SkWIStream::~SkWIStream() {
>>>>>>> miniblink49
    if (this->fSkWStream) {
        this->fSkWStream->flush();
    }
}

<<<<<<< HEAD
HRESULT SkWIStream::CreateFromSkWStream(SkWStream* stream, IStream** ppStream)
=======
HRESULT SkWIStream::CreateFromSkWStream(SkWStream* stream
                                      , IStream ** ppStream)
>>>>>>> miniblink49
{
    *ppStream = new SkWIStream(stream);
    return S_OK;
}

// ISequentialStream Interface
<<<<<<< HEAD
HRESULT STDMETHODCALLTYPE SkWIStream::Write(void const* pv, ULONG cb, ULONG* pcbWritten)
=======
HRESULT STDMETHODCALLTYPE SkWIStream::Write(void const* pv
                                          , ULONG cb
                                          , ULONG* pcbWritten)
>>>>>>> miniblink49
{
    HRESULT hr = S_OK;
    bool wrote = this->fSkWStream->write(pv, cb);
    if (wrote) {
        *pcbWritten = cb;
    } else {
        *pcbWritten = 0;
        hr = S_FALSE;
    }
    return hr;
}

// IStream Interface
<<<<<<< HEAD
HRESULT STDMETHODCALLTYPE SkWIStream::Commit(DWORD)
{
=======
HRESULT STDMETHODCALLTYPE SkWIStream::Commit(DWORD) {
>>>>>>> miniblink49
    this->fSkWStream->flush();
    return S_OK;
}

<<<<<<< HEAD
HRESULT STDMETHODCALLTYPE SkWIStream::Stat(STATSTG* pStatstg, DWORD grfStatFlag)
=======
HRESULT STDMETHODCALLTYPE SkWIStream::Stat(STATSTG* pStatstg
                                         , DWORD grfStatFlag)
>>>>>>> miniblink49
{
    if (0 == (grfStatFlag & STATFLAG_NONAME)) {
        return STG_E_INVALIDFLAG;
    }
<<<<<<< HEAD
    pStatstg->pwcsName = nullptr;
=======
    pStatstg->pwcsName = NULL;
>>>>>>> miniblink49
    pStatstg->cbSize.QuadPart = 0;
    pStatstg->clsid = CLSID_NULL;
    pStatstg->type = STGTY_STREAM;
    pStatstg->grfMode = STGM_WRITE;
    return S_OK;
}
<<<<<<< HEAD
#endif //defined(SK_BUILD_FOR_WIN32)
=======
>>>>>>> miniblink49
