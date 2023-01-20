/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkMagnifierImageFilter_DEFINED
#define SkMagnifierImageFilter_DEFINED

#include "SkImageFilter.h"
#include "SkRect.h"

class SK_API SkMagnifierImageFilter : public SkImageFilter {
public:
    static sk_sp<SkImageFilter> Make(const SkRect& src, SkScalar inset,
        sk_sp<SkImageFilter> input,
        const CropRect* cropRect = nullptr);
=======

#ifndef SkMagnifierImageFilter_DEFINED
#define SkMagnifierImageFilter_DEFINED

#include "SkRect.h"
#include "SkImageFilter.h"

class SK_API SkMagnifierImageFilter : public SkImageFilter {
public:
    static SkImageFilter* Create(const SkRect& src, SkScalar inset, SkImageFilter* input = NULL);
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkMagnifierImageFilter)

<<<<<<< HEAD
#ifdef SK_SUPPORT_LEGACY_IMAGEFILTER_PTR
    static SkImageFilter* Create(const SkRect& src, SkScalar inset,
        SkImageFilter* input = nullptr)
    {
        return Make(src, inset, sk_ref_sp<SkImageFilter>(input)).release();
    }
#endif

protected:
    SkMagnifierImageFilter(const SkRect& srcRect,
        SkScalar inset,
        sk_sp<SkImageFilter> input,
        const CropRect* cropRect);
    void flatten(SkWriteBuffer&) const override;

    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
        SkIPoint* offset) const override;
=======
protected:
    SkMagnifierImageFilter(const SkRect& srcRect, SkScalar inset, SkImageFilter* input);
    void flatten(SkWriteBuffer&) const override;

    bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                       SkBitmap* result, SkIPoint* offset) const override;
#if SK_SUPPORT_GPU
    bool asFragmentProcessor(GrFragmentProcessor**, GrProcessorDataManager*, GrTexture*,
                             const SkMatrix&, const SkIRect& bounds) const override;
#endif
>>>>>>> miniblink49

private:
    SkRect fSrcRect;
    SkScalar fInset;
    typedef SkImageFilter INHERITED;
};

#endif
