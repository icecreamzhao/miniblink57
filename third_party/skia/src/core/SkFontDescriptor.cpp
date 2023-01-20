/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkFontDescriptor.h"
<<<<<<< HEAD
#include "SkData.h"
#include "SkStream.h"
=======
#include "SkStream.h"
#include "SkData.h"
>>>>>>> miniblink49

enum {
    // these must match the sfnt 'name' enums
    kFontFamilyName = 0x01,
<<<<<<< HEAD
    kFullName = 0x04,
=======
    kFullName       = 0x04,
>>>>>>> miniblink49
    kPostscriptName = 0x06,

    // These count backwards from 0xFF, so as not to collide with the SFNT
    // defines for names in its 'name' table.
<<<<<<< HEAD
    kFontAxes = 0xFC,
    kFontIndex = 0xFD,
    kFontFileName = 0xFE, // Remove when MIN_PICTURE_VERSION > 41
    kSentinel = 0xFF,
};

SkFontDescriptor::SkFontDescriptor(SkTypeface::Style style)
    : fStyle(style)
{
}

static void read_string(SkStream* stream, SkString* string)
{
=======
    kFontAxes       = 0xFC,
    kFontIndex      = 0xFD,
    kFontFileName   = 0xFE,  // Remove when MIN_PICTURE_VERSION > 41
    kSentinel       = 0xFF,
};

SkFontDescriptor::SkFontDescriptor(SkTypeface::Style style) : fStyle(style) { }

static void read_string(SkStream* stream, SkString* string) {
>>>>>>> miniblink49
    const uint32_t length = SkToU32(stream->readPackedUInt());
    if (length > 0) {
        string->resize(length);
        stream->read(string->writable_str(), length);
    }
}

// Remove when MIN_PICTURE_VERSION > 41
<<<<<<< HEAD
static void skip_string(SkStream* stream)
{
=======
static void skip_string(SkStream* stream) {
>>>>>>> miniblink49
    const uint32_t length = SkToU32(stream->readPackedUInt());
    if (length > 0) {
        stream->skip(length);
    }
}

<<<<<<< HEAD
static void write_string(SkWStream* stream, const SkString& string, uint32_t id)
{
=======
static void write_string(SkWStream* stream, const SkString& string, uint32_t id) {
>>>>>>> miniblink49
    if (!string.isEmpty()) {
        stream->writePackedUInt(id);
        stream->writePackedUInt(string.size());
        stream->write(string.c_str(), string.size());
    }
}

<<<<<<< HEAD
static size_t read_uint(SkStream* stream)
{
    return stream->readPackedUInt();
}

static void write_uint(SkWStream* stream, size_t n, uint32_t id)
{
=======
static size_t read_uint(SkStream* stream) {
    return stream->readPackedUInt();
}

static void write_uint(SkWStream* stream, size_t n, uint32_t id) {
>>>>>>> miniblink49
    stream->writePackedUInt(id);
    stream->writePackedUInt(n);
}

<<<<<<< HEAD
bool SkFontDescriptor::Deserialize(SkStream* stream, SkFontDescriptor* result)
{
    result->fStyle = (SkTypeface::Style)stream->readPackedUInt();
=======
SkFontDescriptor::SkFontDescriptor(SkStream* stream) {
    fStyle = (SkTypeface::Style)stream->readPackedUInt();
>>>>>>> miniblink49

    SkAutoSTMalloc<4, SkFixed> axis;
    size_t axisCount = 0;
    size_t index = 0;
    for (size_t id; (id = stream->readPackedUInt()) != kSentinel;) {
        switch (id) {
<<<<<<< HEAD
        case kFontFamilyName:
            read_string(stream, &result->fFamilyName);
            break;
        case kFullName:
            read_string(stream, &result->fFullName);
            break;
        case kPostscriptName:
            read_string(stream, &result->fPostscriptName);
            break;
        case kFontAxes:
            axisCount = read_uint(stream);
            axis.reset(axisCount);
            for (size_t i = 0; i < axisCount; ++i) {
                axis[i] = read_uint(stream);
            }
            break;
        case kFontIndex:
            index = read_uint(stream);
            break;
        case kFontFileName: // Remove when MIN_PICTURE_VERSION > 41
            skip_string(stream);
            break;
        default:
            SkDEBUGFAIL("Unknown id used by a font descriptor");
            return false;
=======
            case kFontFamilyName:
                read_string(stream, &fFamilyName);
                break;
            case kFullName:
                read_string(stream, &fFullName);
                break;
            case kPostscriptName:
                read_string(stream, &fPostscriptName);
                break;
            case kFontAxes:
                axisCount = read_uint(stream);
                axis.reset(axisCount);
                for (size_t i = 0; i < axisCount; ++i) {
                    axis[i] = read_uint(stream);
                }
                break;
            case kFontIndex:
                index = read_uint(stream);
                break;
            case kFontFileName:  // Remove when MIN_PICTURE_VERSION > 41
                skip_string(stream);
                break;
            default:
                SkDEBUGFAIL("Unknown id used by a font descriptor");
                return;
>>>>>>> miniblink49
        }
    }

    size_t length = stream->readPackedUInt();
    if (length > 0) {
<<<<<<< HEAD
        sk_sp<SkData> data(SkData::MakeUninitialized(length));
        if (stream->read(data->writable_data(), length) == length) {
            result->fFontData.reset(new SkFontData(new SkMemoryStream(data),
                index, axis, axisCount));
        } else {
            SkDEBUGFAIL("Could not read font data");
            return false;
        }
    }
    return true;
}

void SkFontDescriptor::serialize(SkWStream* stream)
{
=======
        SkAutoTUnref<SkData> data(SkData::NewUninitialized(length));
        if (stream->read(data->writable_data(), length) == length) {
            fFontData.reset(new SkFontData(SkNEW_ARGS(SkMemoryStream, (data)), index,
                                           axis, axisCount));
        }
    }
}

void SkFontDescriptor::serialize(SkWStream* stream) {
>>>>>>> miniblink49
    stream->writePackedUInt(fStyle);

    write_string(stream, fFamilyName, kFontFamilyName);
    write_string(stream, fFullName, kFullName);
    write_string(stream, fPostscriptName, kPostscriptName);
    if (fFontData.get()) {
        if (fFontData->getIndex()) {
            write_uint(stream, fFontData->getIndex(), kFontIndex);
        }
        if (fFontData->getAxisCount()) {
            write_uint(stream, fFontData->getAxisCount(), kFontAxes);
            for (int i = 0; i < fFontData->getAxisCount(); ++i) {
                stream->writePackedUInt(fFontData->getAxis()[i]);
            }
        }
    }

    stream->writePackedUInt(kSentinel);

    if (fFontData.get() && fFontData->hasStream()) {
        SkAutoTDelete<SkStreamAsset> fontData(fFontData->detachStream());
        size_t length = fontData->getLength();
        stream->writePackedUInt(length);
        stream->writeStream(fontData, length);
    } else {
        stream->writePackedUInt(0);
    }
}
