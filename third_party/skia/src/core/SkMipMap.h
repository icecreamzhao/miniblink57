/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkMipMap_DEFINED
#define SkMipMap_DEFINED

#include "SkCachedData.h"
<<<<<<< HEAD
#include "SkPixmap.h"
#include "SkScalar.h"
#include "SkShader.h"
#include "SkSize.h"
=======
#include "SkScalar.h"
>>>>>>> miniblink49

class SkBitmap;
class SkDiscardableMemory;

typedef SkDiscardableMemory* (*SkDiscardableFactoryProc)(size_t bytes);

<<<<<<< HEAD
/*
 * SkMipMap will generate mipmap levels when given a base mipmap level image.
 *
 * Any function which deals with mipmap levels indices will start with index 0
 * being the first mipmap level which was generated. Said another way, it does
 * not include the base level in its range.
 */
class SkMipMap : public SkCachedData {
public:
    static SkMipMap* Build(const SkPixmap& src, SkSourceGammaTreatment, SkDiscardableFactoryProc);
    static SkMipMap* Build(const SkBitmap& src, SkSourceGammaTreatment, SkDiscardableFactoryProc);

    static SkSourceGammaTreatment DeduceTreatment(const SkShader::ContextRec& rec)
    {
        return (SkShader::ContextRec::kPMColor_DstType == rec.fPreferredDstType) ? SkSourceGammaTreatment::kIgnore : SkSourceGammaTreatment::kRespect;
    }

    // Determines how many levels a SkMipMap will have without creating that mipmap.
    // This does not include the base mipmap level that the user provided when
    // creating the SkMipMap.
    static int ComputeLevelCount(int baseWidth, int baseHeight);

    // Determines the size of a given mipmap level.
    // |level| is an index into the generated mipmap levels. It does not include
    // the base level. So index 0 represents mipmap level 1.
    static SkISize ComputeLevelSize(int baseWidth, int baseHeight, int level);

    struct Level {
        SkPixmap fPixmap;
        SkSize fScale; // < 1.0
    };

    bool extractLevel(const SkSize& scale, Level*) const;

    // countLevels returns the number of mipmap levels generated (which does not
    // include the base mipmap level).
    int countLevels() const;

    // |index| is an index into the generated mipmap levels. It does not include
    // the base level. So index 0 represents mipmap level 1.
    bool getLevel(int index, Level*) const;

protected:
    void onDataChange(void* oldData, void* newData) override
    {
        fLevels = (Level*)newData; // could be nullptr
    }

private:
    sk_sp<SkColorSpace> fCS;
    Level* fLevels; // managed by the baseclass, may be null due to onDataChanged.
    int fCount;

    SkMipMap(void* malloc, size_t size)
        : INHERITED(malloc, size)
    {
    }
    SkMipMap(size_t size, SkDiscardableMemory* dm)
        : INHERITED(size, dm)
    {
    }
=======
class SkMipMap : public SkCachedData {
public:
    static SkMipMap* Build(const SkBitmap& src, SkDiscardableFactoryProc);

    struct Level {
        void*       fPixels;
        uint32_t    fRowBytes;
        uint32_t    fWidth, fHeight;
        float       fScale; // < 1.0
    };

    bool extractLevel(SkScalar scale, Level*) const;

protected:
    void onDataChange(void* oldData, void* newData) override {
        fLevels = (Level*)newData; // could be NULL
    }

private:
    Level*  fLevels;
    int     fCount;

    // we take ownership of levels, and will free it with sk_free()
    SkMipMap(void* malloc, size_t size) : INHERITED(malloc, size) {}
    SkMipMap(size_t size, SkDiscardableMemory* dm) : INHERITED(size, dm) {}
>>>>>>> miniblink49

    static size_t AllocLevelsSize(int levelCount, size_t pixelSize);

    typedef SkCachedData INHERITED;
};

#endif
