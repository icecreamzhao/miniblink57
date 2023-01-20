/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkDisplacementMapEffect_DEFINED
#define SkDisplacementMapEffect_DEFINED

#include "SkImageFilter.h"
<<<<<<< HEAD
=======
#include "SkBitmap.h"
>>>>>>> miniblink49

class SK_API SkDisplacementMapEffect : public SkImageFilter {
public:
    enum ChannelSelectorType {
        kUnknown_ChannelSelectorType,
        kR_ChannelSelectorType,
        kG_ChannelSelectorType,
        kB_ChannelSelectorType,
        kA_ChannelSelectorType
    };

<<<<<<< HEAD
    ~SkDisplacementMapEffect() override;

    static sk_sp<SkImageFilter> Make(ChannelSelectorType xChannelSelector,
        ChannelSelectorType yChannelSelector,
        SkScalar scale,
        sk_sp<SkImageFilter> displacement,
        sk_sp<SkImageFilter> color,
        const CropRect* cropRect = nullptr);

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkDisplacementMapEffect)

    SkRect computeFastBounds(const SkRect& src) const override;

    virtual SkIRect onFilterBounds(const SkIRect& src, const SkMatrix&,
        MapDirection) const override;
    SkIRect onFilterNodeBounds(const SkIRect&, const SkMatrix&, MapDirection) const override;

    SK_TO_STRING_OVERRIDE()

#ifdef SK_SUPPORT_LEGACY_IMAGEFILTER_PTR
    static SkImageFilter* Create(ChannelSelectorType xChannelSelector,
        ChannelSelectorType yChannelSelector,
        SkScalar scale, SkImageFilter* displacement,
        SkImageFilter* color = nullptr,
        const CropRect* cropRect = nullptr)
    {
        return Make(xChannelSelector, yChannelSelector, scale,
            sk_ref_sp<SkImageFilter>(displacement),
            sk_ref_sp<SkImageFilter>(color),
            cropRect)
            .release();
    }
#endif

protected:
    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context&,
        SkIPoint* offset) const override;

    SkDisplacementMapEffect(ChannelSelectorType xChannelSelector,
        ChannelSelectorType yChannelSelector,
        SkScalar scale, sk_sp<SkImageFilter> inputs[2],
        const CropRect* cropRect);
=======
    ~SkDisplacementMapEffect();

    static SkDisplacementMapEffect* Create(ChannelSelectorType xChannelSelector,
                                           ChannelSelectorType yChannelSelector,
                                           SkScalar scale, SkImageFilter* displacement,
                                           SkImageFilter* color = NULL,
                                           const CropRect* cropRect = NULL);

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkDisplacementMapEffect)

    virtual bool onFilterImage(Proxy* proxy,
                               const SkBitmap& src,
                               const Context& ctx,
                               SkBitmap* dst,
                               SkIPoint* offset) const override;
    void computeFastBounds(const SkRect& src, SkRect* dst) const override;

    virtual bool onFilterBounds(const SkIRect& src, const SkMatrix&,
                                SkIRect* dst) const override;

#if SK_SUPPORT_GPU
    bool canFilterImageGPU() const override { return true; }
    virtual bool filterImageGPU(Proxy* proxy, const SkBitmap& src, const Context& ctx,
                                SkBitmap* result, SkIPoint* offset) const override;
#endif

    SK_TO_STRING_OVERRIDE()

protected:
    SkDisplacementMapEffect(ChannelSelectorType xChannelSelector,
                            ChannelSelectorType yChannelSelector,
                            SkScalar scale, SkImageFilter* inputs[2],
                            const CropRect* cropRect);
>>>>>>> miniblink49
    void flatten(SkWriteBuffer&) const override;

private:
    ChannelSelectorType fXChannelSelector;
    ChannelSelectorType fYChannelSelector;
    SkScalar fScale;
    typedef SkImageFilter INHERITED;
    const SkImageFilter* getDisplacementInput() const { return getInput(0); }
    const SkImageFilter* getColorInput() const { return getInput(1); }
};

#endif
