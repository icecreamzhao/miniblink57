
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkColorTable_DEFINED
#define SkColorTable_DEFINED

#include "../private/SkOnce.h"
#include "SkColor.h"
#include "SkFlattenable.h"
#include "SkImageInfo.h"
=======

#ifndef SkColorTable_DEFINED
#define SkColorTable_DEFINED

#include "SkColor.h"
#include "SkFlattenable.h"
#include "SkImageInfo.h"
#include "SkLazyPtr.h"
>>>>>>> miniblink49

/** \class SkColorTable

    SkColorTable holds an array SkPMColors (premultiplied 32-bit colors) used by
    8-bit bitmaps, where the bitmap bytes are interpreted as indices into the colortable.

    SkColorTable is thread-safe.
*/
class SK_API SkColorTable : public SkRefCnt {
public:
    /** Copy up to 256 colors into a new SkColorTable.
     */
    SkColorTable(const SkPMColor colors[], int count);
    virtual ~SkColorTable();

    /** Returns the number of colors in the table.
     */
    int count() const { return fCount; }

    /** Returns the specified color from the table. In the debug build, this asserts that
     *  the index is in range (0 <= index < count).
     */
<<<<<<< HEAD
    SkPMColor operator[](int index) const
    {
=======
    SkPMColor operator[](int index) const {
>>>>>>> miniblink49
        SkASSERT(fColors != NULL && (unsigned)index < (unsigned)fCount);
        return fColors[index];
    }

    /** Return the array of colors for reading.
     */
    const SkPMColor* readColors() const { return fColors; }

    /** read16BitCache() returns the array of RGB16 colors that mirror the 32bit colors.
     */
    const uint16_t* read16BitCache() const;

<<<<<<< HEAD
    void writeToBuffer(SkWriteBuffer&) const;

    // may return null
    static SkColorTable* Create(SkReadBuffer&);

private:
    enum AllocatedWithMalloc {
        kAllocatedWithMalloc
    };
    // assumes ownership of colors (assumes it was allocated w/ malloc)
    SkColorTable(SkPMColor* colors, int count, AllocatedWithMalloc);

    SkPMColor* fColors;
    mutable uint16_t* f16BitCache = nullptr;
    mutable SkOnce f16BitCacheOnce;
    int fCount;

    void init(const SkPMColor* colors, int count);

    friend class SkImageGenerator;
    friend class SkBitmapRegionCodec;
    // Only call if no other thread or cache has seen this table.
    void dangerous_overwriteColors(const SkPMColor newColors[], int count)
    {
        if (count < 0 || count > fCount) {
            sk_throw();
        }
        // assumes that f16BitCache nas NOT been initialized yet, so we don't try to update it
        memcpy(fColors, newColors, count * sizeof(SkPMColor));
        fCount = count; // update fCount, in case count is smaller
    }

=======
    explicit SkColorTable(SkReadBuffer&);
    void writeToBuffer(SkWriteBuffer&) const;

private:
    static void Free16BitCache(uint16_t*);

    SkPMColor*                          fColors;
    SkLazyPtr<uint16_t, Free16BitCache> f16BitCache;
    int                                 fCount;

    void init(const SkPMColor* colors, int count);

>>>>>>> miniblink49
    typedef SkRefCnt INHERITED;
};

#endif
