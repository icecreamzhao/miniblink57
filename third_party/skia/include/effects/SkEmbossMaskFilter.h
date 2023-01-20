/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkEmbossMaskFilter_DEFINED
#define SkEmbossMaskFilter_DEFINED

#include "SkMaskFilter.h"

/** \class SkEmbossMaskFilter

    This mask filter creates a 3D emboss look, by specifying a light and blur amount.
*/
class SK_API SkEmbossMaskFilter : public SkMaskFilter {
public:
    struct Light {
<<<<<<< HEAD
        SkScalar fDirection[3]; // x,y,z
        uint16_t fPad;
        uint8_t fAmbient;
        uint8_t fSpecular; // exponent, 4.4 right now
    };

    static sk_sp<SkMaskFilter> Make(SkScalar blurSigma, const Light& light);

#ifdef SK_SUPPORT_LEGACY_MASKFILTER_PTR
    static SkMaskFilter* Create(SkScalar blurSigma, const Light& light)
    {
        return Make(blurSigma, light).release();
    }
#endif
=======
        SkScalar    fDirection[3];  // x,y,z
        uint16_t    fPad;
        uint8_t     fAmbient;
        uint8_t     fSpecular;      // exponent, 4.4 right now
    };

    static SkEmbossMaskFilter* Create(SkScalar blurSigma, const Light& light);
>>>>>>> miniblink49

    // overrides from SkMaskFilter
    //  This method is not exported to java.
    SkMask::Format getFormat() const override;
    //  This method is not exported to java.
<<<<<<< HEAD
    bool filterMask(SkMask* dst, const SkMask& src, const SkMatrix&,
        SkIPoint* margin) const override;
=======
    virtual bool filterMask(SkMask* dst, const SkMask& src, const SkMatrix&,
                            SkIPoint* margin) const override;
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkEmbossMaskFilter)

protected:
    SkEmbossMaskFilter(SkScalar blurSigma, const Light& light);
    void flatten(SkWriteBuffer&) const override;

private:
<<<<<<< HEAD
    Light fLight;
    SkScalar fBlurSigma;
=======
    Light       fLight;
    SkScalar    fBlurSigma;
>>>>>>> miniblink49

    typedef SkMaskFilter INHERITED;
};

#endif
