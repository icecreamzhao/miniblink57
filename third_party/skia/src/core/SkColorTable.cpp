<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2009 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkColorTable.h"
#include "SkReadBuffer.h"
#include "SkStream.h"
#include "SkTemplates.h"
#include "SkWriteBuffer.h"

void SkColorTable::init(const SkPMColor colors[], int count)
{
=======

#include "SkColorTable.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkStream.h"
#include "SkTemplates.h"

void SkColorTable::init(const SkPMColor colors[], int count) {
>>>>>>> miniblink49
    SkASSERT((unsigned)count <= 256);

    fCount = count;
    fColors = reinterpret_cast<SkPMColor*>(sk_malloc_throw(count * sizeof(SkPMColor)));

    memcpy(fColors, colors, count * sizeof(SkPMColor));
}

<<<<<<< HEAD
SkColorTable::SkColorTable(const SkPMColor colors[], int count)
{
=======
SkColorTable::SkColorTable(const SkPMColor colors[], int count) {
>>>>>>> miniblink49
    SkASSERT(0 == count || colors);
    if (count < 0) {
        count = 0;
    } else if (count > 256) {
        count = 256;
    }
    this->init(colors, count);
}

<<<<<<< HEAD
SkColorTable::SkColorTable(SkPMColor* colors, int count, AllocatedWithMalloc)
    : fColors(colors)
    , fCount(count)
{
    SkASSERT(count > 0 && count <= 256);
    SkASSERT(colors);
}

SkColorTable::~SkColorTable()
{
    sk_free(fColors);
    sk_free(f16BitCache);
=======
SkColorTable::~SkColorTable() {
    sk_free(fColors);
    // f16BitCache frees itself
>>>>>>> miniblink49
}

#include "SkColorPriv.h"

<<<<<<< HEAD
const uint16_t* SkColorTable::read16BitCache() const
{
    f16BitCacheOnce([this] {
        f16BitCache = (uint16_t*)sk_malloc_throw(fCount * sizeof(uint16_t));
        for (int i = 0; i < fCount; i++) {
            f16BitCache[i] = SkPixel32ToPixel16_ToU16(fColors[i]);
        }
    });
    return f16BitCache;
=======
namespace {
struct Build16BitCache {
    const SkPMColor* fColors;
    int fCount;

    uint16_t* operator()() const {
        uint16_t* cache = (uint16_t*)sk_malloc_throw(fCount * sizeof(uint16_t));
        for (int i = 0; i < fCount; i++) {
            cache[i] = SkPixel32ToPixel16_ToU16(fColors[i]);
        }
        return cache;
    }
};
}//namespace

void SkColorTable::Free16BitCache(uint16_t* cache) { sk_free(cache); }

const uint16_t* SkColorTable::read16BitCache() const {
    const Build16BitCache create = { fColors, fCount };
    return f16BitCache.get(create);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#if 0
=======
>>>>>>> miniblink49
SkColorTable::SkColorTable(SkReadBuffer& buffer) {
    if (buffer.isVersionLT(SkReadBuffer::kRemoveColorTableAlpha_Version)) {
        /*fAlphaType = */buffer.readUInt();
    }

    fCount = buffer.getArrayCount();
    size_t allocSize = fCount * sizeof(SkPMColor);
    SkDEBUGCODE(bool success = false;)
    if (buffer.validateAvailable(allocSize)) {
        fColors = (SkPMColor*)sk_malloc_throw(allocSize);
        SkDEBUGCODE(success =) buffer.readColorArray(fColors, fCount);
    } else {
        fCount = 0;
<<<<<<< HEAD
        fColors = nullptr;
=======
        fColors = NULL;
>>>>>>> miniblink49
    }
#ifdef SK_DEBUG
    SkASSERT((unsigned)fCount <= 256);
    SkASSERT(success);
#endif
}
<<<<<<< HEAD
#endif

void SkColorTable::writeToBuffer(SkWriteBuffer& buffer) const
{
    buffer.writeColorArray(fColors, fCount);
}

SkColorTable* SkColorTable::Create(SkReadBuffer& buffer)
{
    if (buffer.isVersionLT(SkReadBuffer::kRemoveColorTableAlpha_Version)) {
        /*fAlphaType = */ buffer.readUInt();
    }

    const int count = buffer.getArrayCount();
    if (0 == count) {
        return new SkColorTable(nullptr, 0);
    }

    if (count < 0 || count > 256) {
        buffer.validate(false);
        return nullptr;
    }

    const size_t allocSize = count * sizeof(SkPMColor);
    SkAutoTDelete<SkPMColor> colors((SkPMColor*)sk_malloc_throw(allocSize));
    if (!buffer.readColorArray(colors, count)) {
        return nullptr;
    }

    return new SkColorTable(colors.release(), count, kAllocatedWithMalloc);
}
=======

void SkColorTable::writeToBuffer(SkWriteBuffer& buffer) const {
    buffer.writeColorArray(fColors, fCount);
}
>>>>>>> miniblink49
