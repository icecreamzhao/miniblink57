
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkDrawBitmap.h"
#include "SkAnimateMaker.h"
#include "SkCanvas.h"
#include "SkData.h"
#include "SkImage.h"
=======

#include "SkDrawBitmap.h"
#include "SkAnimateMaker.h"
#include "SkCanvas.h"
#include "SkImageDecoder.h"
>>>>>>> miniblink49
#include "SkPaint.h"
#include "SkStream.h"

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkBaseBitmap::fInfo[] = {
    SK_MEMBER(x, Float),
    SK_MEMBER(y, Float)
};

#endif

DEFINE_GET_MEMBER(SkBaseBitmap);

<<<<<<< HEAD
SkBaseBitmap::SkBaseBitmap()
    : x(0)
    , y(0)
{
}

SkBaseBitmap::~SkBaseBitmap()
{
}

bool SkBaseBitmap::draw(SkAnimateMaker& maker)
{
=======
SkBaseBitmap::SkBaseBitmap() : x(0), y(0) {
}

SkBaseBitmap::~SkBaseBitmap() {
}

bool SkBaseBitmap::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    SkBoundableAuto boundable(this, maker);
    maker.fCanvas->drawBitmap(fBitmap, x, y, maker.fPaint);
    return false;
}

enum SkDrawBitmap_Properties {
    SK_PROPERTY(erase)
};

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDrawBitmap::fInfo[] = {
    SK_MEMBER_INHERITED,
    SK_MEMBER_PROPERTY(erase, ARGB),
    SK_MEMBER(format, BitmapFormat),
    SK_MEMBER(height, Int),
    SK_MEMBER(rowBytes, Int),
    SK_MEMBER(width, Int),
};

#endif

DEFINE_GET_MEMBER(SkDrawBitmap);

<<<<<<< HEAD
SkDrawBitmap::SkDrawBitmap()
    : format((SkColorType)-1)
    , height(-1)
    , rowBytes(0)
    , width(-1)
    , fColor(0)
    , fColorSet(false)
{
}

SkDrawBitmap::~SkDrawBitmap()
{
}

#ifdef SK_DUMP_ENABLED
void SkDrawBitmap::dump(SkAnimateMaker* maker)
{
    dumpBase(maker);
    dumpAttrs(maker);
    if (fColorSet)
        SkDebugf("erase=\"argb(%d,%d,%d,%d)\" ", SkColorGetA(fColor) / 255, SkColorGetR(fColor),
            SkColorGetG(fColor), SkColorGetB(fColor));
    if (rowBytes > 0)
        SkDebugf("rowBytes=\"%d\" ", rowBytes);
    const char* formatName SK_INIT_TO_AVOID_WARNING;
    switch (format) {
    case 0:
        formatName = "none";
        break;
    case 1:
        formatName = "A8";
        break;
    case 2:
        formatName = "Index8";
        break;
    case 3:
        formatName = "RGB16";
        break;
    case 4:
        formatName = "RGB32";
        break;
=======
SkDrawBitmap::SkDrawBitmap() : format((SkColorType) -1), height(-1),
    rowBytes(0),    width(-1), fColor(0), fColorSet(false) {
}

SkDrawBitmap::~SkDrawBitmap() {
}

#ifdef SK_DUMP_ENABLED
void SkDrawBitmap::dump(SkAnimateMaker* maker) {
    dumpBase(maker);
    dumpAttrs(maker);
    if (fColorSet)
        SkDebugf("erase=\"argb(%d,%d,%d,%d)\" ", SkColorGetA(fColor)/255, SkColorGetR(fColor),
            SkColorGetG(fColor), SkColorGetB(fColor));
    if (rowBytes > 0)
        SkDebugf("rowBytes=\"%d\" ", rowBytes);
    const char* formatName;
    switch (format) {
        case 0: formatName = "none"; break;
        case 1: formatName = "A8"; break;
        case 2: formatName = "Index8"; break;
        case 3: formatName = "RGB16"; break;
        case 4: formatName = "RGB32"; break;
>>>>>>> miniblink49
    }
    SkDebugf("format=\"%s\" />\n", formatName);
}
#endif

<<<<<<< HEAD
void SkDrawBitmap::onEndElement(SkAnimateMaker&)
{
=======
void SkDrawBitmap::onEndElement(SkAnimateMaker&) {
>>>>>>> miniblink49
    SkASSERT(width != -1);
    SkASSERT(height != -1);
    SkASSERT(rowBytes >= 0);
    SkColorType colorType = SkColorType(format);
    fBitmap.allocPixels(SkImageInfo::Make(width, height, colorType, kPremul_SkAlphaType),
<<<<<<< HEAD
        rowBytes);
=======
                        rowBytes);
>>>>>>> miniblink49
    if (fColorSet)
        fBitmap.eraseColor(fColor);
}

bool SkDrawBitmap::setProperty(int index, SkScriptValue& value)
{
    switch (index) {
<<<<<<< HEAD
    case SK_PROPERTY(erase):
        SkASSERT(value.fType == SkType_ARGB);
        fColor = value.fOperand.fS32;
        fColorSet = true;
        break;
    default:
        SkASSERT(0);
        return false;
=======
        case SK_PROPERTY(erase):
            SkASSERT(value.fType == SkType_ARGB);
            fColor = value.fOperand.fS32;
            fColorSet = true;
            break;
        default:
            SkASSERT(0);
            return false;
>>>>>>> miniblink49
    }
    return true;
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
enum SkImageBaseBitmap_Properties {
    SK_PROPERTY(height),
    SK_PROPERTY(width)
};

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkImageBaseBitmap::fInfo[] = {
    SK_MEMBER_INHERITED,
    SK_MEMBER(base64, Base64),
    SK_MEMBER_PROPERTY(height, Int),
    SK_MEMBER(src, String),
    SK_MEMBER_PROPERTY(width, Int)
};

#endif

DEFINE_GET_MEMBER(SkImageBaseBitmap);

<<<<<<< HEAD
SkImageBaseBitmap::SkImageBaseBitmap()
    : fDirty(true)
    , fUriBase(nullptr)
{
    base64.fData = nullptr;
    base64.fLength = 0;
}

SkImageBaseBitmap::~SkImageBaseBitmap()
{
    delete[] base64.fData;
}

SkDisplayable* SkImageBaseBitmap::deepCopy(SkAnimateMaker* maker)
{
    SkDisplayable* copy = INHERITED::deepCopy(maker);
    ((SkImageBaseBitmap*)copy)->fUriBase = ((SkImageBaseBitmap*)this)->fUriBase;
    return copy;
}

void SkImageBaseBitmap::dirty()
{
    fDirty = true;
}

bool SkImageBaseBitmap::draw(SkAnimateMaker& maker)
{
=======
SkImageBaseBitmap::SkImageBaseBitmap() : fDirty(true), fUriBase(NULL) {
    base64.fData = NULL;
    base64.fLength = 0;
}

SkImageBaseBitmap::~SkImageBaseBitmap() {
    delete[] base64.fData;
}

SkDisplayable* SkImageBaseBitmap::deepCopy(SkAnimateMaker* maker) {
    SkDisplayable* copy = INHERITED::deepCopy(maker);
    ((SkImageBaseBitmap*) copy)->fUriBase = ((SkImageBaseBitmap*) this)->fUriBase;
    return copy;
}

void SkImageBaseBitmap::dirty() {
    fDirty = true;
}

bool SkImageBaseBitmap::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    if (fDirty)
        resolve();
    return INHERITED::draw(maker);
}

<<<<<<< HEAD
bool SkImageBaseBitmap::getProperty(int index, SkScriptValue* value) const
{
    if (fDirty)
        resolve();
    switch (index) {
    case SK_PROPERTY(height):
        value->fOperand.fS32 = fBitmap.height();
        break;
    case SK_PROPERTY(width):
        value->fOperand.fS32 = fBitmap.width();
        break;
=======
bool SkImageBaseBitmap::getProperty(int index, SkScriptValue* value) const {
    if (fDirty)
        resolve();
    switch (index) {
        case SK_PROPERTY(height):
            value->fOperand.fS32 = fBitmap.height();
            break;
        case SK_PROPERTY(width):
            value->fOperand.fS32 = fBitmap.width();
            break;
>>>>>>> miniblink49
    default:
        SkASSERT(0);
        return false;
    }
    value->fType = SkType_Int;
    return true;
}

<<<<<<< HEAD
void SkImageBaseBitmap::onEndElement(SkAnimateMaker& maker)
{
    fUriBase = maker.fPrefix.c_str();
}

void SkImageBaseBitmap::resolve()
{
    fDirty = false;
    if (base64.fData) {
        fBitmap.reset();
        sk_sp<SkData> data = SkData::MakeWithoutCopy(base64.fData, base64.fLength);
        sk_sp<SkImage> image = SkImage::MakeFromEncoded(data);
        image->asLegacyBitmap(&fBitmap, SkImage::kRO_LegacyBitmapMode);
=======
void SkImageBaseBitmap::onEndElement(SkAnimateMaker& maker) {
    fUriBase = maker.fPrefix.c_str();
}

void SkImageBaseBitmap::resolve() {
    fDirty = false;
    if (base64.fData) {
        fBitmap.reset();
        SkImageDecoder::DecodeMemory(base64.fData, base64.fLength, &fBitmap);
>>>>>>> miniblink49
    } else if (src.size()) {
        if (fLast.equals(src))
            return;
        fLast.set(src);
        fBitmap.reset();

        //SkStream* stream = SkStream::GetURIStream(fUriBase, src.c_str());
<<<<<<< HEAD
        sk_sp<SkData> data = SkData::MakeFromFileName(src.c_str());
        if (data) {
            sk_sp<SkImage> image = SkImage::MakeFromEncoded(data);
            image->asLegacyBitmap(&fBitmap, SkImage::kRO_LegacyBitmapMode);
=======
        SkAutoTDelete<SkStreamAsset> stream(SkStream::NewFromFile(src.c_str()));
        if (stream.get()) {
            SkImageDecoder::DecodeStream(stream, &fBitmap);
>>>>>>> miniblink49
        }
    }
}
