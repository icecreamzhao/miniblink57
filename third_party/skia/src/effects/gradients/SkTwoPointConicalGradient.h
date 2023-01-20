<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkTwoPointConicalGradient_DEFINED
#define SkTwoPointConicalGradient_DEFINED

#include "SkGradientShaderPriv.h"

// TODO(dominikg): Worth making it truly immutable (i.e. set values in constructor)?
// Should only be initialized once via init(). Immutable afterwards.
struct TwoPtRadial {
    enum {
<<<<<<< HEAD
        // This value is outside the range SK_FixedMin to SK_FixedMax.
        kDontDrawT = 0x80000000
    };

    float fCenterX, fCenterY;
    float fDCenterX, fDCenterY;
    float fRadius;
    float fDRadius;
    float fA;
    float fRadius2;
    float fRDR;
    bool fFlipped;

    void init(const SkPoint& center0, SkScalar rad0,
        const SkPoint& center1, SkScalar rad1,
        bool flipped);

    static bool DontDrawT(SkFixed t)
    {
=======
        kDontDrawT  = 0x80000000
    };

    float   fCenterX, fCenterY;
    float   fDCenterX, fDCenterY;
    float   fRadius;
    float   fDRadius;
    float   fA;
    float   fRadius2;
    float   fRDR;
    bool    fFlipped;

    void init(const SkPoint& center0, SkScalar rad0,
              const SkPoint& center1, SkScalar rad1,
              bool flipped);

    static bool DontDrawT(SkFixed t) {
>>>>>>> miniblink49
        return kDontDrawT == (uint32_t)t;
    }
};

<<<<<<< HEAD
class SkTwoPointConicalGradient : public SkGradientShaderBase {
    TwoPtRadial fRec;

public:
    SkTwoPointConicalGradient(const SkPoint& start, SkScalar startRadius,
        const SkPoint& end, SkScalar endRadius,
        bool flippedGrad, const Descriptor&);
=======

class SkTwoPointConicalGradient : public SkGradientShaderBase {
    TwoPtRadial fRec;
public:
    SkTwoPointConicalGradient(const SkPoint& start, SkScalar startRadius,
                              const SkPoint& end, SkScalar endRadius,
                              bool flippedGrad, const Descriptor&);


    size_t contextSize() const override;
>>>>>>> miniblink49

    class TwoPointConicalGradientContext : public SkGradientShaderBase::GradientShaderBaseContext {
    public:
        TwoPointConicalGradientContext(const SkTwoPointConicalGradient&, const ContextRec&);
<<<<<<< HEAD
        ~TwoPointConicalGradientContext() { }
=======
        ~TwoPointConicalGradientContext() {}
>>>>>>> miniblink49

        void shadeSpan(int x, int y, SkPMColor dstC[], int count) override;

    private:
        typedef SkGradientShaderBase::GradientShaderBaseContext INHERITED;
    };

<<<<<<< HEAD
    SkShader::GradientType asAGradient(GradientInfo* info) const override;
#if SK_SUPPORT_GPU
    sk_sp<GrFragmentProcessor> asFragmentProcessor(GrContext*,
        const SkMatrix&,
        const SkMatrix*,
        SkFilterQuality,
        SkSourceGammaTreatment) const override;
#endif
=======
    BitmapType asABitmap(SkBitmap* bitmap, SkMatrix* matrix, TileMode* xy) const override;
    SkShader::GradientType asAGradient(GradientInfo* info) const  override;
    bool asFragmentProcessor(GrContext*, const SkPaint&, const SkMatrix&, const SkMatrix*,
                             GrColor*, GrProcessorDataManager*,
                             GrFragmentProcessor**) const override;
>>>>>>> miniblink49
    bool isOpaque() const override;

    SkScalar getCenterX1() const { return SkPoint::Distance(fCenter1, fCenter2); }
    SkScalar getStartRadius() const { return fRadius1; }
    SkScalar getDiffRadius() const { return fRadius2 - fRadius1; }
    const SkPoint& getStartCenter() const { return fCenter1; }
    const SkPoint& getEndCenter() const { return fCenter2; }
    SkScalar getEndRadius() const { return fRadius2; }
    bool isFlippedGrad() const { return fFlippedGrad; }

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkTwoPointConicalGradient)

protected:
    SkTwoPointConicalGradient(SkReadBuffer& buffer);
    void flatten(SkWriteBuffer& buffer) const override;
<<<<<<< HEAD
    size_t onContextSize(const ContextRec&) const override;
=======
>>>>>>> miniblink49
    Context* onCreateContext(const ContextRec&, void* storage) const override;

private:
    SkPoint fCenter1;
    SkPoint fCenter2;
    SkScalar fRadius1;
    SkScalar fRadius2;
    bool fFlippedGrad;

    friend class SkGradientShader;
    typedef SkGradientShaderBase INHERITED;
};

#endif
