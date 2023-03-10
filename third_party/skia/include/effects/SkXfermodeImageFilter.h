/*
 * Copyright 2013 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkXfermodeImageFilter_DEFINED
#define SkXfermodeImageFilter_DEFINED

#include "SkImageFilter.h"
#include "SkArithmeticImageFilter.h"

class SkBitmap;
class SkXfermode;
enum class SkBlendMode;

class SK_API SkXfermodeImageFilter : public SkImageFilter {
    /**
     * This filter takes an xfermode, and uses it to composite the foreground
     * over the background.  If foreground or background is NULL, the input
     * bitmap (src) is used instead.
     */

public:
    static sk_sp<SkImageFilter> Make(sk_sp<SkXfermode> mode, sk_sp<SkImageFilter> background,
        sk_sp<SkImageFilter> foreground, const CropRect* cropRect);
    static sk_sp<SkImageFilter> Make(sk_sp<SkXfermode> mode, sk_sp<SkImageFilter> background)
    {
        return Make(std::move(mode), std::move(background), nullptr, nullptr);
    }
    static sk_sp<SkImageFilter> Make(SkBlendMode mode, sk_sp<SkImageFilter> background,
        sk_sp<SkImageFilter> foreground, const CropRect* cropRect);

    // Arithmetic image filtering used to be implemented using SkXfermode. Some clients still rely
    // on these factories existing in this class.
    static sk_sp<SkImageFilter> MakeArithmetic(float k1, float k2, float k3, float k4, bool enforcePMColor, sk_sp<SkImageFilter> background,
        sk_sp<SkImageFilter> foreground,
        const SkImageFilter::CropRect* cropRect)
    {
        return SkArithmeticImageFilter::Make(k1, k2, k3, k4, enforcePMColor, std::move(background),
            std::move(foreground), cropRect);
    }

#ifdef SK_SUPPORT_LEGACY_XFERMODE_PTR
    static SkImageFilter* Create(SkXfermode* mode, SkImageFilter* background,
        SkImageFilter* foreground = NULL,
        const CropRect* cropRect = NULL)
    {
        return Make(sk_ref_sp(mode),
            sk_ref_sp(background),
            sk_ref_sp(foreground),
            cropRect)
            .release();
    }
#endif
#ifdef SK_SUPPORT_LEGACY_IMAGEFILTER_PTR
    static sk_sp<SkImageFilter> Make(sk_sp<SkXfermode> mode, SkImageFilter* background,
        SkImageFilter* foreground, const CropRect* cropRect)
    {
        return Make(std::move(mode),
            sk_ref_sp(background),
            sk_ref_sp(foreground),
            cropRect);
    }
    static sk_sp<SkImageFilter> Make(sk_sp<SkXfermode> mode, SkImageFilter* background)
    {
        return Make(std::move(mode), sk_ref_sp(background));
    }
#endif

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkXfermodeImageFilter)

protected:
    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
        SkIPoint* offset) const override;

#if SK_SUPPORT_GPU
    sk_sp<SkSpecialImage> filterImageGPU(SkSpecialImage* source,
        sk_sp<SkSpecialImage> background,
        const SkIPoint& backgroundOffset,
        sk_sp<SkSpecialImage> foreground,
        const SkIPoint& foregroundOffset,
        const SkIRect& bounds) const;
#endif

    SkXfermodeImageFilter(sk_sp<SkXfermode> mode, sk_sp<SkImageFilter> inputs[2],
        const CropRect* cropRect);
    void flatten(SkWriteBuffer&) const override;

private:
    sk_sp<SkXfermode> fMode;
    typedef SkImageFilter INHERITED;
};

#endif
