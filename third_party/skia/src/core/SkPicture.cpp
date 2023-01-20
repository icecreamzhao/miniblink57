/*
 * Copyright 2007 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkPicture.h"
#include "SkAtomics.h"
#include "SkImageGenerator.h"
#include "SkMessageBus.h"
=======
#include "SkAtomics.h"
#include "SkMessageBus.h"
#include "SkPicture.h"
>>>>>>> miniblink49
#include "SkPictureData.h"
#include "SkPicturePlayback.h"
#include "SkPictureRecord.h"
#include "SkPictureRecorder.h"

<<<<<<< HEAD
#if defined(SK_DISALLOW_CROSSPROCESS_PICTUREIMAGEFILTERS) || defined(SK_ENABLE_PICTURE_IO_SECURITY_PRECAUTIONS)
=======
#if defined(SK_DISALLOW_CROSSPROCESS_PICTUREIMAGEFILTERS) || \
    defined(SK_ENABLE_PICTURE_IO_SECURITY_PRECAUTIONS)
>>>>>>> miniblink49
static bool g_AllPictureIOSecurityPrecautionsEnabled = true;
#else
static bool g_AllPictureIOSecurityPrecautionsEnabled = false;
#endif

DECLARE_SKMESSAGEBUS_MESSAGE(SkPicture::DeletionMessage);

/* SkPicture impl.  This handles generic responsibilities like unique IDs and serialization. */

<<<<<<< HEAD
SkPicture::SkPicture()
    : fUniqueID(0)
{
}

SkPicture::~SkPicture()
{
=======
SkPicture::SkPicture() : fUniqueID(0) {}

SkPicture::~SkPicture() {
>>>>>>> miniblink49
    // TODO: move this to ~SkBigPicture() only?

    // If the ID is still zero, no one has read it, so no need to send this message.
    uint32_t id = sk_atomic_load(&fUniqueID, sk_memory_order_relaxed);
    if (id != 0) {
        SkPicture::DeletionMessage msg = { (int32_t)id };
        SkMessageBus<SkPicture::DeletionMessage>::Post(msg);
    }
}

<<<<<<< HEAD
uint32_t SkPicture::uniqueID() const
{
=======
uint32_t SkPicture::uniqueID() const {
>>>>>>> miniblink49
    static uint32_t gNextID = 1;
    uint32_t id = sk_atomic_load(&fUniqueID, sk_memory_order_relaxed);
    while (id == 0) {
        uint32_t next = sk_atomic_fetch_add(&gNextID, 1u);
        if (sk_atomic_compare_exchange(&fUniqueID, &id, next,
<<<<<<< HEAD
                sk_memory_order_relaxed,
                sk_memory_order_relaxed)) {
=======
                                       sk_memory_order_relaxed,
                                       sk_memory_order_relaxed)) {
>>>>>>> miniblink49
            id = next;
        } else {
            // sk_atomic_compare_exchange replaced id with the current value of fUniqueID.
        }
    }
    return id;
}

static const char kMagic[] = { 's', 'k', 'i', 'a', 'p', 'i', 'c', 't' };

<<<<<<< HEAD
SkPictInfo SkPicture::createHeader() const
{
=======
SkPictInfo SkPicture::createHeader() const {
>>>>>>> miniblink49
    SkPictInfo info;
    // Copy magic bytes at the beginning of the header
    static_assert(sizeof(kMagic) == 8, "");
    static_assert(sizeof(kMagic) == sizeof(info.fMagic), "");
    memcpy(info.fMagic, kMagic, sizeof(kMagic));

    // Set picture info after magic bytes in the header
    info.fVersion = CURRENT_PICTURE_VERSION;
    info.fCullRect = this->cullRect();
    info.fFlags = SkPictInfo::kCrossProcess_Flag;
    // TODO: remove this flag, since we're always float (now)
    info.fFlags |= SkPictInfo::kScalarIsFloat_Flag;

    if (8 == sizeof(void*)) {
        info.fFlags |= SkPictInfo::kPtrIs64Bit_Flag;
    }
    return info;
}

<<<<<<< HEAD
bool SkPicture::IsValidPictInfo(const SkPictInfo& info)
{
=======
bool SkPicture::IsValidPictInfo(const SkPictInfo& info) {
>>>>>>> miniblink49
    if (0 != memcmp(info.fMagic, kMagic, sizeof(kMagic))) {
        return false;
    }
    if (info.fVersion < MIN_PICTURE_VERSION || info.fVersion > CURRENT_PICTURE_VERSION) {
        return false;
    }
    return true;
}

<<<<<<< HEAD
bool SkPicture::InternalOnly_StreamIsSKP(SkStream* stream, SkPictInfo* pInfo)
{
=======
bool SkPicture::InternalOnly_StreamIsSKP(SkStream* stream, SkPictInfo* pInfo) {
>>>>>>> miniblink49
    if (!stream) {
        return false;
    }

    SkPictInfo info;
    SkASSERT(sizeof(kMagic) == sizeof(info.fMagic));
    if (!stream->read(&info.fMagic, sizeof(kMagic))) {
        return false;
    }

<<<<<<< HEAD
    info.fVersion = stream->readU32();
    info.fCullRect.fLeft = stream->readScalar();
    info.fCullRect.fTop = stream->readScalar();
    info.fCullRect.fRight = stream->readScalar();
    info.fCullRect.fBottom = stream->readScalar();
    info.fFlags = stream->readU32();

    if (IsValidPictInfo(info)) {
        if (pInfo) {
            *pInfo = info;
        }
=======
    info.fVersion          = stream->readU32();
    info.fCullRect.fLeft   = stream->readScalar();
    info.fCullRect.fTop    = stream->readScalar();
    info.fCullRect.fRight  = stream->readScalar();
    info.fCullRect.fBottom = stream->readScalar();
    info.fFlags            = stream->readU32();

    if (IsValidPictInfo(info)) {
        if (pInfo) { *pInfo = info; }
>>>>>>> miniblink49
        return true;
    }
    return false;
}

<<<<<<< HEAD
bool SkPicture::InternalOnly_BufferIsSKP(SkReadBuffer* buffer, SkPictInfo* pInfo)
{
=======
bool SkPicture::InternalOnly_BufferIsSKP(SkReadBuffer* buffer, SkPictInfo* pInfo) {
>>>>>>> miniblink49
    SkPictInfo info;
    SkASSERT(sizeof(kMagic) == sizeof(info.fMagic));
    if (!buffer->readByteArray(&info.fMagic, sizeof(kMagic))) {
        return false;
    }

    info.fVersion = buffer->readUInt();
    buffer->readRect(&info.fCullRect);
    info.fFlags = buffer->readUInt();

    if (IsValidPictInfo(info)) {
<<<<<<< HEAD
        if (pInfo) {
            *pInfo = info;
        }
=======
        if (pInfo) { *pInfo = info; }
>>>>>>> miniblink49
        return true;
    }
    return false;
}

<<<<<<< HEAD
sk_sp<SkPicture> SkPicture::Forwardport(const SkPictInfo& info,
    const SkPictureData* data,
    const SkReadBuffer* buffer)
{
=======
SkPicture* SkPicture::Forwardport(const SkPictInfo& info, const SkPictureData* data) {
>>>>>>> miniblink49
    if (!data) {
        return nullptr;
    }
    SkPicturePlayback playback(data);
    SkPictureRecorder r;
<<<<<<< HEAD
    playback.draw(r.beginRecording(info.fCullRect), nullptr /*no callback*/, buffer);
    return r.finishRecordingAsPicture();
}

static bool default_install(const void* src, size_t length, SkBitmap* dst)
{
    sk_sp<SkData> encoded(SkData::MakeWithCopy(src, length));
    return encoded && SkDEPRECATED_InstallDiscardablePixelRef(SkImageGenerator::NewFromEncoded(encoded.get()), dst);
}

sk_sp<SkPicture> SkPicture::MakeFromStream(SkStream* stream)
{
    return MakeFromStream(stream, &default_install, nullptr);
}

sk_sp<SkPicture> SkPicture::MakeFromStream(SkStream* stream, InstallPixelRefProc proc)
{
    return MakeFromStream(stream, proc, nullptr);
}

sk_sp<SkPicture> SkPicture::MakeFromStream(SkStream* stream, InstallPixelRefProc proc,
    SkTypefacePlayback* typefaces)
{
=======
    playback.draw(r.beginRecording(SkScalarCeilToInt(info.fCullRect.width()),
                                   SkScalarCeilToInt(info.fCullRect.height())),
                  nullptr/*no callback*/);
    return r.endRecording();
}

SkPicture* SkPicture::CreateFromStream(SkStream* stream, InstallPixelRefProc proc) {
>>>>>>> miniblink49
    SkPictInfo info;
    if (!InternalOnly_StreamIsSKP(stream, &info) || !stream->readBool()) {
        return nullptr;
    }
<<<<<<< HEAD
    SkAutoTDelete<SkPictureData> data(
        SkPictureData::CreateFromStream(stream, info, proc, typefaces));
    return Forwardport(info, data, nullptr);
}

sk_sp<SkPicture> SkPicture::MakeFromBuffer(SkReadBuffer& buffer)
{
=======
    SkAutoTDelete<SkPictureData> data(SkPictureData::CreateFromStream(stream, info, proc));
    return Forwardport(info, data);
}

SkPicture* SkPicture::CreateFromBuffer(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    SkPictInfo info;
    if (!InternalOnly_BufferIsSKP(&buffer, &info) || !buffer.readBool()) {
        return nullptr;
    }
    SkAutoTDelete<SkPictureData> data(SkPictureData::CreateFromBuffer(buffer, info));
<<<<<<< HEAD
    return Forwardport(info, data, &buffer);
}

SkPictureData* SkPicture::backport() const
{
    SkPictInfo info = this->createHeader();
    SkPictureRecord rec(SkISize::Make(info.fCullRect.width(), info.fCullRect.height()), 0 /*flags*/);
    rec.beginRecording();
    this->playback(&rec);
    rec.endRecording();
    return new SkPictureData(rec, info);
}

void SkPicture::serialize(SkWStream* stream, SkPixelSerializer* pixelSerializer) const
{
    this->serialize(stream, pixelSerializer, nullptr);
}

void SkPicture::serialize(SkWStream* stream,
    SkPixelSerializer* pixelSerializer,
    SkRefCntSet* typefaceSet) const
{
=======
    return Forwardport(info, data);
}

SkPictureData* SkPicture::backport() const {
    SkPictInfo info = this->createHeader();
    SkPictureRecord rec(SkISize::Make(info.fCullRect.width(), info.fCullRect.height()), 0/*flags*/);
    rec.beginRecording();
        this->playback(&rec);
    rec.endRecording();
    return SkNEW_ARGS(SkPictureData, (rec, info, false/*deep copy ops?*/));
}

void SkPicture::serialize(SkWStream* stream, SkPixelSerializer* pixelSerializer) const {
>>>>>>> miniblink49
    SkPictInfo info = this->createHeader();
    SkAutoTDelete<SkPictureData> data(this->backport());

    stream->write(&info, sizeof(info));
    if (data) {
        stream->writeBool(true);
<<<<<<< HEAD
        data->serialize(stream, pixelSerializer, typefaceSet);
=======
        data->serialize(stream, pixelSerializer);
>>>>>>> miniblink49
    } else {
        stream->writeBool(false);
    }
}

<<<<<<< HEAD
void SkPicture::flatten(SkWriteBuffer& buffer) const
{
=======
void SkPicture::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    SkPictInfo info = this->createHeader();
    SkAutoTDelete<SkPictureData> data(this->backport());

    buffer.writeByteArray(&info.fMagic, sizeof(info.fMagic));
    buffer.writeUInt(info.fVersion);
    buffer.writeRect(info.fCullRect);
    buffer.writeUInt(info.fFlags);
    if (data) {
        buffer.writeBool(true);
        data->flatten(buffer);
    } else {
        buffer.writeBool(false);
    }
}

<<<<<<< HEAD
#ifdef SK_SUPPORT_LEGACY_PICTURE_GPUVETO
bool SkPicture::suitableForGpuRasterization(GrContext*, const char** whyNot) const
{
    if (this->numSlowPaths() > 5) {
        if (whyNot) {
            *whyNot = "Too many slow paths (either concave or dashed).";
        }
=======
bool SkPicture::suitableForGpuRasterization(GrContext*, const char** whyNot) const {
    if (this->numSlowPaths() > 5) {
        if (whyNot) { *whyNot = "Too many slow paths (either concave or dashed)."; }
>>>>>>> miniblink49
        return false;
    }
    return true;
}
<<<<<<< HEAD
#endif

// Global setting to disable security precautions for serialization.
void SkPicture::SetPictureIOSecurityPrecautionsEnabled_Dangerous(bool set)
{
    g_AllPictureIOSecurityPrecautionsEnabled = set;
}

bool SkPicture::PictureIOSecurityPrecautionsEnabled()
{
=======

// Global setting to disable security precautions for serialization.
void SkPicture::SetPictureIOSecurityPrecautionsEnabled_Dangerous(bool set) {
    g_AllPictureIOSecurityPrecautionsEnabled = set;
}

bool SkPicture::PictureIOSecurityPrecautionsEnabled() {
>>>>>>> miniblink49
    return g_AllPictureIOSecurityPrecautionsEnabled;
}
