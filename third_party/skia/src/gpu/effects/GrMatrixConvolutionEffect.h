/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrMatrixConvolutionEffect_DEFINED
#define GrMatrixConvolutionEffect_DEFINED

<<<<<<< HEAD
#include "GrInvariantOutput.h"
#include "GrSingleTextureEffect.h"
=======
#include "GrSingleTextureEffect.h"
#include "GrInvariantOutput.h"
>>>>>>> miniblink49
#include "GrTextureDomain.h"

// A little bit less than the minimum # uniforms required by DX9SM2 (32).
// Allows for a 5x5 kernel (or 25x1, for that matter).
#define MAX_KERNEL_SIZE 25

class GrMatrixConvolutionEffect : public GrSingleTextureEffect {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrTexture* texture,
        const SkIRect& bounds,
        const SkISize& kernelSize,
        const SkScalar* kernel,
        SkScalar gain,
        SkScalar bias,
        const SkIPoint& kernelOffset,
        GrTextureDomain::Mode tileMode,
        bool convolveAlpha)
    {
        return sk_sp<GrFragmentProcessor>(
            new GrMatrixConvolutionEffect(texture, bounds, kernelSize, kernel, gain, bias,
                kernelOffset, tileMode, convolveAlpha));
    }

    static sk_sp<GrFragmentProcessor> MakeGaussian(GrTexture* texture,
        const SkIRect& bounds,
        const SkISize& kernelSize,
        SkScalar gain,
        SkScalar bias,
        const SkIPoint& kernelOffset,
        GrTextureDomain::Mode tileMode,
        bool convolveAlpha,
        SkScalar sigmaX,
        SkScalar sigmaY);
=======
    static GrFragmentProcessor* Create(GrProcessorDataManager* procDataManager,
                                       GrTexture* texture,
                                       const SkIRect& bounds,
                                       const SkISize& kernelSize,
                                       const SkScalar* kernel,
                                       SkScalar gain,
                                       SkScalar bias,
                                       const SkIPoint& kernelOffset,
                                       GrTextureDomain::Mode tileMode,
                                       bool convolveAlpha) {
        return SkNEW_ARGS(GrMatrixConvolutionEffect, (procDataManager,
                                                      texture,
                                                      bounds,
                                                      kernelSize,
                                                      kernel,
                                                      gain,
                                                      bias,
                                                      kernelOffset,
                                                      tileMode,
                                                      convolveAlpha));
    }

    static GrFragmentProcessor* CreateGaussian(GrProcessorDataManager*,
                                               GrTexture* texture,
                                               const SkIRect& bounds,
                                               const SkISize& kernelSize,
                                               SkScalar gain,
                                               SkScalar bias,
                                               const SkIPoint& kernelOffset,
                                               GrTextureDomain::Mode tileMode,
                                               bool convolveAlpha,
                                               SkScalar sigmaX,
                                               SkScalar sigmaY);

    virtual ~GrMatrixConvolutionEffect();
>>>>>>> miniblink49

    const SkIRect& bounds() const { return fBounds; }
    const SkISize& kernelSize() const { return fKernelSize; }
    const float* kernelOffset() const { return fKernelOffset; }
    const float* kernel() const { return fKernel; }
    float gain() const { return fGain; }
    float bias() const { return fBias; }
    bool convolveAlpha() const { return fConvolveAlpha; }
    const GrTextureDomain& domain() const { return fDomain; }

    const char* name() const override { return "MatrixConvolution"; }

<<<<<<< HEAD
private:
    GrMatrixConvolutionEffect(GrTexture*,
        const SkIRect& bounds,
        const SkISize& kernelSize,
        const SkScalar* kernel,
        SkScalar gain,
        SkScalar bias,
        const SkIPoint& kernelOffset,
        GrTextureDomain::Mode tileMode,
        bool convolveAlpha);

    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    bool onIsEqual(const GrFragmentProcessor&) const override;

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override
    {
=======
    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

private:
    GrMatrixConvolutionEffect(GrProcessorDataManager*,
                              GrTexture*,
                              const SkIRect& bounds,
                              const SkISize& kernelSize,
                              const SkScalar* kernel,
                              SkScalar gain,
                              SkScalar bias,
                              const SkIPoint& kernelOffset,
                              GrTextureDomain::Mode tileMode,
                              bool convolveAlpha);

    bool onIsEqual(const GrFragmentProcessor&) const override;

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override {
>>>>>>> miniblink49
        // TODO: Try to do better?
        inout->mulByUnknownFourComponents();
    }

<<<<<<< HEAD
    SkIRect fBounds;
    SkISize fKernelSize;
    float fKernel[MAX_KERNEL_SIZE];
    float fGain;
    float fBias;
    float fKernelOffset[2];
    bool fConvolveAlpha;
=======
    SkIRect         fBounds;
    SkISize         fKernelSize;
    float           fKernel[MAX_KERNEL_SIZE];
    float           fGain;
    float           fBias;
    float           fKernelOffset[2];
    bool            fConvolveAlpha;
>>>>>>> miniblink49
    GrTextureDomain fDomain;

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    typedef GrSingleTextureEffect INHERITED;
};

#endif
