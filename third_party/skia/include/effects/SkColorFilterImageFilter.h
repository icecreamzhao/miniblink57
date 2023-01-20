/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkColorFilterImageFilter_DEFINED
#define SkColorFilterImageFilter_DEFINED

#include "SkImageFilter.h"

class SkColorFilter;

class SK_API SkColorFilterImageFilter : public SkImageFilter {
public:
<<<<<<< HEAD
    static sk_sp<SkImageFilter> Make(sk_sp<SkColorFilter> cf,
        sk_sp<SkImageFilter> input,
        const CropRect* cropRect = NULL);
=======
    static SkColorFilterImageFilter* Create(SkColorFilter* cf,
                                            SkImageFilter* input = NULL,
                                            const CropRect* cropRect = NULL);
    virtual ~SkColorFilterImageFilter();
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkColorFilterImageFilter)

<<<<<<< HEAD
#ifdef SK_SUPPORT_LEGACY_IMAGEFILTER_PTR
    static SkImageFilter* Create(SkColorFilter* cf,
        SkImageFilter* input = NULL,
        const CropRect* cropRect = NULL)
    {
        return Make(sk_ref_sp<SkColorFilter>(cf),
            sk_ref_sp<SkImageFilter>(input),
            cropRect)
            .release();
    }
#endif

protected:
    void flatten(SkWriteBuffer&) const override;
    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
        SkIPoint* offset) const override;
    bool onIsColorFilterNode(SkColorFilter**) const override;
    bool onCanHandleComplexCTM() const override { return true; }
    bool affectsTransparentBlack() const override;

private:
    SkColorFilterImageFilter(sk_sp<SkColorFilter> cf,
        sk_sp<SkImageFilter> input,
        const CropRect* cropRect);

    sk_sp<SkColorFilter> fColorFilter;
=======
protected:
    void flatten(SkWriteBuffer&) const override;

    virtual bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                               SkBitmap* result, SkIPoint* loc) const override;

    bool onIsColorFilterNode(SkColorFilter**) const override;

private:
    SkColorFilterImageFilter(SkColorFilter* cf,
                             SkImageFilter* input,
                             const CropRect* cropRect);
    SkColorFilter*  fColorFilter;
>>>>>>> miniblink49

    typedef SkImageFilter INHERITED;
};

#endif
