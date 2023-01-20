/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkMorphologyImageFilter_DEFINED
#define SkMorphologyImageFilter_DEFINED

#include "SkColor.h"
#include "SkImageFilter.h"
#include "SkSize.h"

<<<<<<< HEAD
///////////////////////////////////////////////////////////////////////////////
class SK_API SkMorphologyImageFilter : public SkImageFilter {
public:
    SkRect computeFastBounds(const SkRect& src) const override;
    SkIRect onFilterNodeBounds(const SkIRect& src, const SkMatrix&, MapDirection) const override;
=======
class SK_API SkMorphologyImageFilter : public SkImageFilter {
public:
    void computeFastBounds(const SkRect& src, SkRect* dst) const override;
    bool onFilterBounds(const SkIRect& src, const SkMatrix& ctm, SkIRect* dst) const override;
>>>>>>> miniblink49

    /**
     * All morphology procs have the same signature: src is the source buffer, dst the
     * destination buffer, radius is the morphology radius, width and height are the bounds
     * of the destination buffer (in pixels), and srcStride and dstStride are the
     * number of pixels per row in each buffer. All buffers are 8888.
     */

    typedef void (*Proc)(const SkPMColor* src, SkPMColor* dst, int radius,
<<<<<<< HEAD
        int width, int height, int srcStride, int dstStride);

protected:
    enum Op {
        kErode_Op,
        kDilate_Op,
    };

    virtual Op op() const = 0;

    SkMorphologyImageFilter(int radiusX, int radiusY,
        sk_sp<SkImageFilter> input,
        const CropRect* cropRect);
    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source,
        const Context&,
        SkIPoint* offset) const override;
    void flatten(SkWriteBuffer&) const override;

    SkISize radius() const { return fRadius; }

private:
    SkISize fRadius;

    typedef SkImageFilter INHERITED;
};

///////////////////////////////////////////////////////////////////////////////
class SK_API SkDilateImageFilter : public SkMorphologyImageFilter {
public:
    static sk_sp<SkImageFilter> Make(int radiusX, int radiusY,
        sk_sp<SkImageFilter> input,
        const CropRect* cropRect = nullptr);
=======
                         int width, int height, int srcStride, int dstStride);

protected:
    SkMorphologyImageFilter(int radiusX, int radiusY, SkImageFilter* input,
                            const CropRect* cropRect);
    bool filterImageGeneric(Proc procX, Proc procY,
                            Proxy*, const SkBitmap& src, const Context&,
                            SkBitmap* result, SkIPoint* offset) const;
    void flatten(SkWriteBuffer&) const override;
#if SK_SUPPORT_GPU
    bool canFilterImageGPU() const override { return true; }
    bool filterImageGPUGeneric(bool dilate, Proxy* proxy, const SkBitmap& src,
                               const Context& ctm, SkBitmap* result,
                               SkIPoint* offset) const;
#endif

    SkISize    radius() const { return fRadius; }

private:
    SkISize    fRadius;
    typedef SkImageFilter INHERITED;
};

class SK_API SkDilateImageFilter : public SkMorphologyImageFilter {
public:
    static SkDilateImageFilter* Create(int radiusX, int radiusY,
                                       SkImageFilter* input = NULL,
                                       const CropRect* cropRect = NULL) {
        if (radiusX < 0 || radiusY < 0) {
            return NULL;
        }
        return SkNEW_ARGS(SkDilateImageFilter, (radiusX, radiusY, input, cropRect));
    }

    bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                       SkBitmap* result, SkIPoint* offset) const override;
#if SK_SUPPORT_GPU
    bool filterImageGPU(Proxy* proxy, const SkBitmap& src, const Context&,
                        SkBitmap* result, SkIPoint* offset) const override;
#endif
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkDilateImageFilter)

<<<<<<< HEAD
#ifdef SK_SUPPORT_LEGACY_IMAGEFILTER_PTR
    static SkImageFilter* Create(int radiusX, int radiusY,
        SkImageFilter* input = nullptr,
        const CropRect* cropRect = nullptr)
    {
        return Make(radiusX, radiusY,
            sk_ref_sp<SkImageFilter>(input),
            cropRect)
            .release();
    }
#endif

protected:
    Op op() const override { return kDilate_Op; }

private:
    SkDilateImageFilter(int radiusX, int radiusY,
        sk_sp<SkImageFilter> input,
        const CropRect* cropRect)
        : INHERITED(radiusX, radiusY, input, cropRect)
    {
    }

    typedef SkMorphologyImageFilter INHERITED;
};

///////////////////////////////////////////////////////////////////////////////
class SK_API SkErodeImageFilter : public SkMorphologyImageFilter {
public:
    static sk_sp<SkImageFilter> Make(int radiusX, int radiusY,
        sk_sp<SkImageFilter> input,
        const CropRect* cropRect = nullptr);
=======
protected:
    SkDilateImageFilter(int radiusX, int radiusY, SkImageFilter* input, const CropRect* cropRect)
        : INHERITED(radiusX, radiusY, input, cropRect) {}
private:
    typedef SkMorphologyImageFilter INHERITED;
};

class SK_API SkErodeImageFilter : public SkMorphologyImageFilter {
public:
    static SkErodeImageFilter* Create(int radiusX, int radiusY,
                                      SkImageFilter* input = NULL,
                                      const CropRect* cropRect = NULL) {
        if (radiusX < 0 || radiusY < 0) {
            return NULL;
        }
        return SkNEW_ARGS(SkErodeImageFilter, (radiusX, radiusY, input, cropRect));
    }

    bool onFilterImage(Proxy*, const SkBitmap& src, const Context&,
                       SkBitmap* result, SkIPoint* offset) const override;
#if SK_SUPPORT_GPU
    bool filterImageGPU(Proxy* proxy, const SkBitmap& src, const Context&,
                        SkBitmap* result, SkIPoint* offset) const override;
#endif
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkErodeImageFilter)

<<<<<<< HEAD
#ifdef SK_SUPPORT_LEGACY_IMAGEFILTER_PTR
    static SkImageFilter* Create(int radiusX, int radiusY,
        SkImageFilter* input = nullptr,
        const CropRect* cropRect = nullptr)
    {
        return Make(radiusX, radiusY,
            sk_ref_sp<SkImageFilter>(input),
            cropRect)
            .release();
    }
#endif

protected:
    Op op() const override { return kErode_Op; }

private:
    SkErodeImageFilter(int radiusX, int radiusY,
        sk_sp<SkImageFilter> input, const CropRect* cropRect)
        : INHERITED(radiusX, radiusY, input, cropRect)
    {
    }

=======
protected:
    SkErodeImageFilter(int radiusX, int radiusY, SkImageFilter* input, const CropRect* cropRect)
        : INHERITED(radiusX, radiusY, input, cropRect) {}

private:
>>>>>>> miniblink49
    typedef SkMorphologyImageFilter INHERITED;
};

#endif
