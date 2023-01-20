/*
 * Copyright 2014 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkMatrixImageFilter_DEFINED
#define SkMatrixImageFilter_DEFINED

#include "SkImageFilter.h"
<<<<<<< HEAD
#include "SkMatrix.h"
=======
#include "SkScalar.h"
#include "SkSize.h"
#include "SkPoint.h"
#include "SkPaint.h"
>>>>>>> miniblink49

/*! \class SkMatrixImageFilter
    Matrix transformation image filter.  This filter draws its source
    input transformed by the given matrix.
 */

class SK_API SkMatrixImageFilter : public SkImageFilter {
public:
    /** Construct a 2D transformation image filter.
<<<<<<< HEAD
     *  @param transform     The matrix to apply when drawing the src bitmap
     *  @param filterQuality The quality of filtering to apply when scaling.
     *  @param input         The input image filter.  If nullptr, the src bitmap
     *                       passed to filterImage() is used instead.
     */

    static sk_sp<SkImageFilter> Make(const SkMatrix& transform,
        SkFilterQuality filterQuality,
        sk_sp<SkImageFilter> input);

    SkRect computeFastBounds(const SkRect&) const override;
=======
     *  @param transform    The matrix to apply when drawing the src bitmap
     *  @param filterLevel  The quality of filtering to apply when scaling.
     *  @param input        The input image filter.  If NULL, the src bitmap
     *                      passed to filterImage() is used instead.
     */

    static SkMatrixImageFilter* Create(const SkMatrix& transform,
                                       SkFilterQuality,
                                       SkImageFilter* input = NULL);
    virtual ~SkMatrixImageFilter();

    void computeFastBounds(const SkRect&, SkRect*) const override;
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkMatrixImageFilter)

<<<<<<< HEAD
#ifdef SK_SUPPORT_LEGACY_IMAGEFILTER_PTR
    static SkImageFilter* Create(const SkMatrix& transform,
        SkFilterQuality filterQuality,
        SkImageFilter* input = nullptr)
    {
        return Make(transform, filterQuality, sk_ref_sp<SkImageFilter>(input)).release();
    }
#endif

protected:
    SkMatrixImageFilter(const SkMatrix& transform,
        SkFilterQuality,
        sk_sp<SkImageFilter> input);
    void flatten(SkWriteBuffer&) const override;

    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
        SkIPoint* offset) const override;
    SkIRect onFilterNodeBounds(const SkIRect& src, const SkMatrix&, MapDirection) const override;

private:
    SkMatrix fTransform;
    SkFilterQuality fFilterQuality;
=======
protected:
    SkMatrixImageFilter(const SkMatrix& transform,
                        SkFilterQuality,
                        SkImageFilter* input);
    void flatten(SkWriteBuffer&) const override;

    virtual bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                               SkBitmap* result, SkIPoint* loc) const override;
    virtual bool onFilterBounds(const SkIRect& src, const SkMatrix&,
                                SkIRect* dst) const override;

private:
    SkMatrix              fTransform;
    SkFilterQuality       fFilterQuality;
>>>>>>> miniblink49
    typedef SkImageFilter INHERITED;
};

#endif
