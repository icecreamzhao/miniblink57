/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkMaskCache.h"

#define CHECK_LOCAL(localCache, localName, globalName, ...) \
    ((localCache) ? localCache->localName(__VA_ARGS__) : SkResourceCache::globalName(__VA_ARGS__))

struct MaskValue {
<<<<<<< HEAD
    SkMask fMask;
    SkCachedData* fData;
=======
    SkMask          fMask;
    SkCachedData*   fData;
>>>>>>> miniblink49
};

namespace {
static unsigned gRRectBlurKeyNamespaceLabel;

struct RRectBlurKey : public SkResourceCache::Key {
public:
    RRectBlurKey(SkScalar sigma, const SkRRect& rrect, SkBlurStyle style, SkBlurQuality quality)
        : fSigma(sigma)
        , fStyle(style)
        , fQuality(quality)
        , fRRect(rrect)
    {
        this->init(&gRRectBlurKeyNamespaceLabel, 0,
<<<<<<< HEAD
            sizeof(fSigma) + sizeof(fStyle) + sizeof(fQuality) + sizeof(fRRect));
    }

    SkScalar fSigma;
    int32_t fStyle;
    int32_t fQuality;
    SkRRect fRRect;
=======
                   sizeof(fSigma) + sizeof(fStyle) + sizeof(fQuality) + sizeof(fRRect));
    }

    SkScalar   fSigma;
    int32_t    fStyle;
    int32_t    fQuality;
    SkRRect    fRRect;
>>>>>>> miniblink49
};

struct RRectBlurRec : public SkResourceCache::Rec {
    RRectBlurRec(RRectBlurKey key, const SkMask& mask, SkCachedData* data)
        : fKey(key)
    {
        fValue.fMask = mask;
        fValue.fData = data;
        fValue.fData->attachToCacheAndRef();
    }
<<<<<<< HEAD
    ~RRectBlurRec()
    {
        fValue.fData->detachFromCacheAndUnref();
    }

    RRectBlurKey fKey;
    MaskValue fValue;

    const Key& getKey() const override { return fKey; }
    size_t bytesUsed() const override { return sizeof(*this) + fValue.fData->size(); }
    const char* getCategory() const override { return "rrect-blur"; }
    SkDiscardableMemory* diagnostic_only_getDiscardable() const override
    {
        return fValue.fData->diagnostic_only_getDiscardable();
    }

    static bool Visitor(const SkResourceCache::Rec& baseRec, void* contextData)
    {
=======
    ~RRectBlurRec() {
        fValue.fData->detachFromCacheAndUnref();
    }

    RRectBlurKey   fKey;
    MaskValue      fValue;

    const Key& getKey() const override { return fKey; }
    size_t bytesUsed() const override { return sizeof(*this) + fValue.fData->size(); }

    static bool Visitor(const SkResourceCache::Rec& baseRec, void* contextData) {
>>>>>>> miniblink49
        const RRectBlurRec& rec = static_cast<const RRectBlurRec&>(baseRec);
        MaskValue* result = (MaskValue*)contextData;

        SkCachedData* tmpData = rec.fValue.fData;
        tmpData->ref();
<<<<<<< HEAD
        if (nullptr == tmpData->data()) {
=======
        if (NULL == tmpData->data()) {
>>>>>>> miniblink49
            tmpData->unref();
            return false;
        }
        *result = rec.fValue;
        return true;
    }
};
} // namespace

SkCachedData* SkMaskCache::FindAndRef(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
<<<<<<< HEAD
    const SkRRect& rrect, SkMask* mask, SkResourceCache* localCache)
{
    MaskValue result;
    RRectBlurKey key(sigma, rrect, style, quality);
    if (!CHECK_LOCAL(localCache, find, Find, key, RRectBlurRec::Visitor, &result)) {
        return nullptr;
=======
                                  const SkRRect& rrect, SkMask* mask, SkResourceCache* localCache) {
    MaskValue result;
    RRectBlurKey key(sigma, rrect, style, quality);
    if (!CHECK_LOCAL(localCache, find, Find, key, RRectBlurRec::Visitor, &result)) {
        return NULL;
>>>>>>> miniblink49
    }

    *mask = result.fMask;
    mask->fImage = (uint8_t*)(result.fData->data());
    return result.fData;
}

void SkMaskCache::Add(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
<<<<<<< HEAD
    const SkRRect& rrect, const SkMask& mask, SkCachedData* data,
    SkResourceCache* localCache)
{
    RRectBlurKey key(sigma, rrect, style, quality);
    return CHECK_LOCAL(localCache, add, Add, new RRectBlurRec(key, mask, data));
=======
                      const SkRRect& rrect, const SkMask& mask, SkCachedData* data,
                      SkResourceCache* localCache) {
    RRectBlurKey key(sigma, rrect, style, quality);
    return CHECK_LOCAL(localCache, add, Add, SkNEW_ARGS(RRectBlurRec, (key, mask, data)));
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////////////////

namespace {
static unsigned gRectsBlurKeyNamespaceLabel;

struct RectsBlurKey : public SkResourceCache::Key {
public:
    RectsBlurKey(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
<<<<<<< HEAD
        const SkRect rects[], int count)
=======
                 const SkRect rects[], int count)
>>>>>>> miniblink49
        : fSigma(sigma)
        , fStyle(style)
        , fQuality(quality)
    {
        SkASSERT(1 == count || 2 == count);
        SkIRect ir;
        rects[0].roundOut(&ir);
<<<<<<< HEAD
        fSizes[0] = SkSize::Make(rects[0].width(), rects[0].height());
        if (2 == count) {
            fSizes[1] = SkSize::Make(rects[1].width(), rects[1].height());
            fSizes[2] = SkSize::Make(rects[0].x() - rects[1].x(), rects[0].y() - rects[1].y());
        } else {
            fSizes[1] = SkSize::Make(0, 0);
            fSizes[2] = SkSize::Make(0, 0);
        }
        fSizes[3] = SkSize::Make(rects[0].x() - ir.x(), rects[0].y() - ir.y());

        this->init(&gRectsBlurKeyNamespaceLabel, 0,
            sizeof(fSigma) + sizeof(fStyle) + sizeof(fQuality) + sizeof(fSizes));
    }

    SkScalar fSigma;
    int32_t fStyle;
    int32_t fQuality;
    SkSize fSizes[4];
=======
        fSizes[0] = SkSize::Make(0, 0);
        fSizes[1] = SkSize::Make(0, 0);
        fSizes[2] = SkSize::Make(0, 0);
        fSizes[3] = SkSize::Make(rects[0].x() - ir.x(), rects[0].y() - ir.y());
        for (int i = 0; i < count; i++) {
            fSizes[i] = SkSize::Make(rects[i].width(), rects[i].height());
        }
        if (2 == count) {
            fSizes[2] = SkSize::Make(rects[0].x() - rects[1].x(), rects[0].y() - rects[1].y());
        }

        this->init(&gRectsBlurKeyNamespaceLabel, 0,
                   sizeof(fSigma) + sizeof(fStyle) + sizeof(fQuality) + sizeof(fSizes));
    }

    SkScalar    fSigma;
    int32_t     fStyle;
    int32_t     fQuality;
    SkSize      fSizes[4];
>>>>>>> miniblink49
};

struct RectsBlurRec : public SkResourceCache::Rec {
    RectsBlurRec(RectsBlurKey key, const SkMask& mask, SkCachedData* data)
        : fKey(key)
    {
        fValue.fMask = mask;
        fValue.fData = data;
        fValue.fData->attachToCacheAndRef();
    }
<<<<<<< HEAD
    ~RectsBlurRec()
    {
        fValue.fData->detachFromCacheAndUnref();
    }

    RectsBlurKey fKey;
    MaskValue fValue;

    const Key& getKey() const override { return fKey; }
    size_t bytesUsed() const override { return sizeof(*this) + fValue.fData->size(); }
    const char* getCategory() const override { return "rects-blur"; }
    SkDiscardableMemory* diagnostic_only_getDiscardable() const override
    {
        return fValue.fData->diagnostic_only_getDiscardable();
    }

    static bool Visitor(const SkResourceCache::Rec& baseRec, void* contextData)
    {
=======
    ~RectsBlurRec() {
        fValue.fData->detachFromCacheAndUnref();
    }

    RectsBlurKey   fKey;
    MaskValue      fValue;

    const Key& getKey() const override { return fKey; }
    size_t bytesUsed() const override { return sizeof(*this) + fValue.fData->size(); }

    static bool Visitor(const SkResourceCache::Rec& baseRec, void* contextData) {
>>>>>>> miniblink49
        const RectsBlurRec& rec = static_cast<const RectsBlurRec&>(baseRec);
        MaskValue* result = static_cast<MaskValue*>(contextData);

        SkCachedData* tmpData = rec.fValue.fData;
        tmpData->ref();
<<<<<<< HEAD
        if (nullptr == tmpData->data()) {
=======
        if (NULL == tmpData->data()) {
>>>>>>> miniblink49
            tmpData->unref();
            return false;
        }
        *result = rec.fValue;
        return true;
    }
};
} // namespace

SkCachedData* SkMaskCache::FindAndRef(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
<<<<<<< HEAD
    const SkRect rects[], int count, SkMask* mask,
    SkResourceCache* localCache)
{
    MaskValue result;
    RectsBlurKey key(sigma, style, quality, rects, count);
    if (!CHECK_LOCAL(localCache, find, Find, key, RectsBlurRec::Visitor, &result)) {
        return nullptr;
=======
                                      const SkRect rects[], int count, SkMask* mask,
                                      SkResourceCache* localCache) {
    MaskValue result;
    RectsBlurKey key(sigma, style, quality, rects, count);
    if (!CHECK_LOCAL(localCache, find, Find, key, RectsBlurRec::Visitor, &result)) {
        return NULL;
>>>>>>> miniblink49
    }

    *mask = result.fMask;
    mask->fImage = (uint8_t*)(result.fData->data());
    return result.fData;
}

void SkMaskCache::Add(SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
<<<<<<< HEAD
    const SkRect rects[], int count, const SkMask& mask, SkCachedData* data,
    SkResourceCache* localCache)
{
    RectsBlurKey key(sigma, style, quality, rects, count);
    return CHECK_LOCAL(localCache, add, Add, new RectsBlurRec(key, mask, data));
=======
                      const SkRect rects[], int count, const SkMask& mask, SkCachedData* data,
                      SkResourceCache* localCache) {
    RectsBlurKey key(sigma, style, quality, rects, count);
    return CHECK_LOCAL(localCache, add, Add, SkNEW_ARGS(RectsBlurRec, (key, mask, data)));
>>>>>>> miniblink49
}
