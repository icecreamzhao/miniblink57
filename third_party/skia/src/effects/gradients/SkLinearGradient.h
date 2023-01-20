/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkLinearGradient_DEFINED
#define SkLinearGradient_DEFINED

#include "SkGradientShaderPriv.h"
<<<<<<< HEAD
#include "SkNx.h"

struct Sk4fStorage {
    float fArray[4];

    operator Sk4f() const
    {
        return Sk4f::Load(fArray);
    }

    Sk4fStorage& operator=(const Sk4f& src)
    {
        src.store(fArray);
        return *this;
    }
};

class SkLinearGradient : public SkGradientShaderBase {
public:
    enum {
        // Temp flag for testing the 4f impl.
        kForce4fContext_PrivateFlag = 1 << 7,
    };

    SkLinearGradient(const SkPoint pts[2], const Descriptor&);

    class LinearGradientContext : public SkGradientShaderBase::GradientShaderBaseContext {
    public:
        LinearGradientContext(const SkLinearGradient&, const ContextRec&);

        void shadeSpan(int x, int y, SkPMColor dstC[], int count) override;

        struct Rec {
            Sk4fStorage fColor;
            float fPos;
            float fPosScale;
        };

    private:
        SkTDArray<Rec> fRecs;
        bool fApplyAlphaAfterInterp;

        void shade4_clamp(int x, int y, SkPMColor dstC[], int count);
        template <bool, bool>
        void shade4_dx_clamp(SkPMColor dstC[], int count, float fx, float dx,
            float invDx, const float dither[2]);

        typedef SkGradientShaderBase::GradientShaderBaseContext INHERITED;
    };

    GradientType asAGradient(GradientInfo* info) const override;
#if SK_SUPPORT_GPU
    sk_sp<GrFragmentProcessor> asFragmentProcessor(GrContext*,
        const SkMatrix& viewM,
        const SkMatrix*,
        SkFilterQuality,
        SkSourceGammaTreatment) const override;
#endif
=======

class SkLinearGradient : public SkGradientShaderBase {
public:
    SkLinearGradient(const SkPoint pts[2], const Descriptor&);

    size_t contextSize() const override;

    class LinearGradientContext : public SkGradientShaderBase::GradientShaderBaseContext {
    public:
        LinearGradientContext(const SkLinearGradient&, const ContextRec&);
        ~LinearGradientContext() {}

        void shadeSpan(int x, int y, SkPMColor dstC[], int count) override;
        void shadeSpan16(int x, int y, uint16_t dstC[], int count) override;

    private:
        typedef SkGradientShaderBase::GradientShaderBaseContext INHERITED;
    };

    BitmapType asABitmap(SkBitmap*, SkMatrix*, TileMode*) const override;
    GradientType asAGradient(GradientInfo* info) const override;
    bool asFragmentProcessor(GrContext*, const SkPaint&, const SkMatrix& viewM,
                             const SkMatrix*, GrColor*, GrProcessorDataManager*,
                             GrFragmentProcessor**) const override;
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkLinearGradient)

protected:
    SkLinearGradient(SkReadBuffer& buffer);
    void flatten(SkWriteBuffer& buffer) const override;
<<<<<<< HEAD
    size_t onContextSize(const ContextRec&) const override;
    Context* onCreateContext(const ContextRec&, void* storage) const override;

private:
    class LinearGradient4fContext;

=======
    Context* onCreateContext(const ContextRec&, void* storage) const override;

private:
>>>>>>> miniblink49
    friend class SkGradientShader;
    typedef SkGradientShaderBase INHERITED;
    const SkPoint fStart;
    const SkPoint fEnd;
};

#endif
