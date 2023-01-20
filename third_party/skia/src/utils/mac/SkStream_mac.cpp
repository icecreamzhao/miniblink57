/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTypes.h"
#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)

=======
>>>>>>> miniblink49
#include "SkCGUtils.h"
#include "SkStream.h"

// These are used by CGDataProviderCreateWithData

<<<<<<< HEAD
static void unref_proc(void* info, const void* addr, size_t size)
{
=======
static void unref_proc(void* info, const void* addr, size_t size) {
>>>>>>> miniblink49
    SkASSERT(info);
    ((SkRefCnt*)info)->unref();
}

<<<<<<< HEAD
static void delete_stream_proc(void* info, const void* addr, size_t size)
{
=======
static void delete_stream_proc(void* info, const void* addr, size_t size) {
>>>>>>> miniblink49
    SkASSERT(info);
    SkStream* stream = (SkStream*)info;
    SkASSERT(stream->getMemoryBase() == addr);
    SkASSERT(stream->getLength() == size);
<<<<<<< HEAD
    delete stream;
=======
    SkDELETE(stream);
>>>>>>> miniblink49
}

// These are used by CGDataProviderSequentialCallbacks

<<<<<<< HEAD
static size_t get_bytes_proc(void* info, void* buffer, size_t bytes)
{
=======
static size_t get_bytes_proc(void* info, void* buffer, size_t bytes) {
>>>>>>> miniblink49
    SkASSERT(info);
    return ((SkStream*)info)->read(buffer, bytes);
}

<<<<<<< HEAD
static off_t skip_forward_proc(void* info, off_t bytes)
{
    return ((SkStream*)info)->skip((size_t)bytes);
}

static void rewind_proc(void* info)
{
=======
static off_t skip_forward_proc(void* info, off_t bytes) {
    return ((SkStream*)info)->skip((size_t) bytes);
}

static void rewind_proc(void* info) {
>>>>>>> miniblink49
    SkASSERT(info);
    ((SkStream*)info)->rewind();
}

// Used when info is an SkStream.
<<<<<<< HEAD
static void release_info_proc(void* info)
{
    SkASSERT(info);
    delete (SkStream*)info;
}

CGDataProviderRef SkCreateDataProviderFromStream(SkStream* stream)
{
=======
static void release_info_proc(void* info) {
    SkASSERT(info);
    SkDELETE((SkStream*)info);
}

CGDataProviderRef SkCreateDataProviderFromStream(SkStream* stream) {
>>>>>>> miniblink49
    // TODO: Replace with SkStream::getData() when that is added. Then we only
    // have one version of CGDataProviderCreateWithData (i.e. same release proc)
    const void* addr = stream->getMemoryBase();
    if (addr) {
        // special-case when the stream is just a block of ram
        return CGDataProviderCreateWithData(stream, addr, stream->getLength(),
<<<<<<< HEAD
            delete_stream_proc);
=======
                                            delete_stream_proc);
>>>>>>> miniblink49
    }

    CGDataProviderSequentialCallbacks rec;
    sk_bzero(&rec, sizeof(rec));
    rec.version = 0;
    rec.getBytes = get_bytes_proc;
    rec.skipForward = skip_forward_proc;
    rec.rewind = rewind_proc;
    rec.releaseInfo = release_info_proc;
    return CGDataProviderCreateSequential(stream, &rec);
}

///////////////////////////////////////////////////////////////////////////////

#include "SkData.h"

<<<<<<< HEAD
CGDataProviderRef SkCreateDataProviderFromData(SkData* data)
{
    data->ref();
    return CGDataProviderCreateWithData(data, data->data(), data->size(),
        unref_proc);
}

#endif //defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
=======
CGDataProviderRef SkCreateDataProviderFromData(SkData* data) {
    data->ref();
    return CGDataProviderCreateWithData(data, data->data(), data->size(),
                                            unref_proc);
}
>>>>>>> miniblink49
