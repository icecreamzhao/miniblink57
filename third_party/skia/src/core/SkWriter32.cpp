/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkWriter32.h"
#include "SkReader32.h"
#include "SkString.h"
=======
#include "SkReader32.h"
#include "SkString.h"
#include "SkWriter32.h"
>>>>>>> miniblink49

/*
 *  Strings are stored as: length[4-bytes] + string_data + '\0' + pad_to_mul_4
 */

<<<<<<< HEAD
const char* SkReader32::readString(size_t* outLen)
{
=======
const char* SkReader32::readString(size_t* outLen) {
>>>>>>> miniblink49
    size_t len = this->readU32();
    const void* ptr = this->peek();

    // skip over the string + '\0' and then pad to a multiple of 4
    size_t alignedSize = SkAlign4(len + 1);
    this->skip(alignedSize);

    if (outLen) {
        *outLen = len;
    }
    return (const char*)ptr;
}

<<<<<<< HEAD
size_t SkReader32::readIntoString(SkString* copy)
{
=======
size_t SkReader32::readIntoString(SkString* copy) {
>>>>>>> miniblink49
    size_t len;
    const char* ptr = this->readString(&len);
    if (copy) {
        copy->set(ptr, len);
    }
    return len;
}

<<<<<<< HEAD
void SkWriter32::writeString(const char str[], size_t len)
{
    if (nullptr == str) {
=======
void SkWriter32::writeString(const char str[], size_t len) {
    if (NULL == str) {
>>>>>>> miniblink49
        str = "";
        len = 0;
    }
    if ((long)len < 0) {
        len = strlen(str);
    }

    // [ 4 byte len ] [ str ... ] [1 - 4 \0s]
    uint32_t* ptr = this->reservePad(sizeof(uint32_t) + len + 1);
    *ptr = SkToU32(len);
    char* chars = (char*)(ptr + 1);
    memcpy(chars, str, len);
    chars[len] = '\0';
}

<<<<<<< HEAD
size_t SkWriter32::WriteStringSize(const char* str, size_t len)
{
=======
size_t SkWriter32::WriteStringSize(const char* str, size_t len) {
>>>>>>> miniblink49
    if ((long)len < 0) {
        SkASSERT(str);
        len = strlen(str);
    }
<<<<<<< HEAD
    const size_t lenBytes = 4; // we use 4 bytes to record the length
=======
    const size_t lenBytes = 4;    // we use 4 bytes to record the length
>>>>>>> miniblink49
    // add 1 since we also write a terminating 0
    return SkAlign4(lenBytes + len + 1);
}

<<<<<<< HEAD
void SkWriter32::growToAtLeast(size_t size)
{
    const bool wasExternal = (fExternal != nullptr) && (fData == fExternal);
=======
void SkWriter32::growToAtLeast(size_t size) {
    const bool wasExternal = (fExternal != NULL) && (fData == fExternal);
>>>>>>> miniblink49

    fCapacity = 4096 + SkTMax(size, fCapacity + (fCapacity / 2));
    fInternal.realloc(fCapacity);
    fData = fInternal.get();

    if (wasExternal) {
        // we were external, so copy in the data
        memcpy(fData, fExternal, fUsed);
    }
}

<<<<<<< HEAD
sk_sp<SkData> SkWriter32::snapshotAsData() const
{
    return SkData::MakeWithCopy(fData, fUsed);
=======
SkData* SkWriter32::snapshotAsData() const {
    return SkData::NewWithCopy(fData, fUsed);
>>>>>>> miniblink49
}
