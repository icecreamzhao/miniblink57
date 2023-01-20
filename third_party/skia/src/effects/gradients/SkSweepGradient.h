<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkSweepGradient_DEFINED
#define SkSweepGradient_DEFINED

#include "SkGradientShaderPriv.h"

class SkSweepGradient : public SkGradientShaderBase {
public:
    SkSweepGradient(SkScalar cx, SkScalar cy, const Descriptor&);

<<<<<<< HEAD
=======
    size_t contextSize() const override;

>>>>>>> miniblink49
    class SweepGradientContext : public SkGradientShaderBase::GradientShaderBaseContext {
    public:
        SweepGradientContext(const SkSweepGradient& shader, const ContextRec&);

        void shadeSpan(int x, int y, SkPMColor dstC[], int count) override;
<<<<<<< HEAD
=======
        void shadeSpan16(int x, int y, uint16_t dstC[], int count) override;
>>>>>>> miniblink49

    private:
        typedef SkGradientShaderBase::GradientShaderBaseContext INHERITED;
    };

<<<<<<< HEAD
    GradientType asAGradient(GradientInfo* info) const override;

#if SK_SUPPORT_GPU
    sk_sp<GrFragmentProcessor> asFragmentProcessor(GrContext*,
        const SkMatrix& viewM,
        const SkMatrix*,
        SkFilterQuality,
        SkSourceGammaTreatment) const override;
#endif
=======
    BitmapType asABitmap(SkBitmap* bitmap, SkMatrix* matrix, TileMode* xy) const override;

    GradientType asAGradient(GradientInfo* info) const override;

    bool asFragmentProcessor(GrContext*, const SkPaint&, const SkMatrix& viewM,
                             const SkMatrix*, GrColor*, GrProcessorDataManager*,
                             GrFragmentProcessor**) const override;
>>>>>>> miniblink49

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkSweepGradient)

protected:
    void flatten(SkWriteBuffer& buffer) const override;
<<<<<<< HEAD
    size_t onContextSize(const ContextRec&) const override;
=======
>>>>>>> miniblink49
    Context* onCreateContext(const ContextRec&, void* storage) const override;

private:
    const SkPoint fCenter;

    friend class SkGradientShader;
    typedef SkGradientShaderBase INHERITED;
};

#endif
