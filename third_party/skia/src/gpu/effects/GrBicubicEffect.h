/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrBicubicTextureEffect_DEFINED
#define GrBicubicTextureEffect_DEFINED

#include "GrSingleTextureEffect.h"
#include "GrTextureDomain.h"
<<<<<<< HEAD
#include "glsl/GrGLSLFragmentProcessor.h"
=======
#include "gl/GrGLProcessor.h"
>>>>>>> miniblink49

class GrGLBicubicEffect;
class GrInvariantOutput;

class GrBicubicEffect : public GrSingleTextureEffect {
public:
    enum {
        kFilterTexelPad = 2, // Given a src rect in texels to be filtered, this number of
<<<<<<< HEAD
        // surrounding texels are needed by the kernel in x and y.
=======
                             // surrounding texels are needed by the kernel in x and y.
>>>>>>> miniblink49
    };
    virtual ~GrBicubicEffect();

    const float* coefficients() const { return fCoefficients; }

    const char* name() const override { return "Bicubic"; }

<<<<<<< HEAD
=======
    void getGLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

    GrGLFragmentProcessor* createGLInstance() const override;

>>>>>>> miniblink49
    const GrTextureDomain& domain() const { return fDomain; }

    /**
     * Create a simple filter effect with custom bicubic coefficients and optional domain.
     */
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrTexture* tex, const SkScalar coefficients[16],
        const SkRect* domain = nullptr)
    {
        if (nullptr == domain) {
            static const SkShader::TileMode kTileModes[] = { SkShader::kClamp_TileMode,
                SkShader::kClamp_TileMode };
            return Make(tex, coefficients, GrCoordTransform::MakeDivByTextureWHMatrix(tex),
                kTileModes);
        } else {
            return sk_sp<GrFragmentProcessor>(
                new GrBicubicEffect(tex, coefficients,
                    GrCoordTransform::MakeDivByTextureWHMatrix(tex), *domain));
=======
    static GrFragmentProcessor* Create(GrProcessorDataManager* procDataManager, GrTexture* tex,
                                       const SkScalar coefficients[16],
                                       const SkRect* domain = NULL) {
        if (NULL == domain) {
            static const SkShader::TileMode kTileModes[] = { SkShader::kClamp_TileMode,
                                                             SkShader::kClamp_TileMode };
            return Create(procDataManager, tex, coefficients,
                          GrCoordTransform::MakeDivByTextureWHMatrix(tex), kTileModes);
        } else {
            return SkNEW_ARGS(GrBicubicEffect, (procDataManager, tex, coefficients,
                                                GrCoordTransform::MakeDivByTextureWHMatrix(tex),
                                                *domain));
>>>>>>> miniblink49
        }
    }

    /**
     * Create a Mitchell filter effect with specified texture matrix and x/y tile modes.
     */
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrTexture* tex, const SkMatrix& matrix,
        const SkShader::TileMode tileModes[2])
    {
        return Make(tex, gMitchellCoefficients, matrix, tileModes);
=======
    static GrFragmentProcessor* Create(GrProcessorDataManager* procDataManager, GrTexture* tex,
                                       const SkMatrix& matrix,
                                       SkShader::TileMode tileModes[2]) {
        return Create(procDataManager, tex, gMitchellCoefficients, matrix, tileModes);
>>>>>>> miniblink49
    }

    /**
     * Create a filter effect with custom bicubic coefficients, the texture matrix, and the x/y
     * tilemodes.
     */
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrTexture* tex, const SkScalar coefficients[16],
        const SkMatrix& matrix,
        const SkShader::TileMode tileModes[2])
    {
        return sk_sp<GrFragmentProcessor>(new GrBicubicEffect(tex, coefficients, matrix,
            tileModes));
=======
    static GrFragmentProcessor* Create(GrProcessorDataManager* procDataManager, GrTexture* tex,
                                       const SkScalar coefficients[16], const SkMatrix& matrix,
                                       const SkShader::TileMode tileModes[2]) {
        return SkNEW_ARGS(GrBicubicEffect, (procDataManager, tex, coefficients, matrix, tileModes));
>>>>>>> miniblink49
    }

    /**
     * Create a Mitchell filter effect with a texture matrix and a domain.
     */
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrTexture* tex, const SkMatrix& matrix,
        const SkRect& domain)
    {
        return sk_sp<GrFragmentProcessor>(new GrBicubicEffect(tex, gMitchellCoefficients, matrix,
            domain));
=======
    static GrFragmentProcessor* Create(GrProcessorDataManager* procDataManager, GrTexture* tex,
                                       const SkMatrix& matrix, const SkRect& domain) {
        return SkNEW_ARGS(GrBicubicEffect, (procDataManager, tex, gMitchellCoefficients, matrix,
                                            domain));
>>>>>>> miniblink49
    }

    /**
     * Determines whether the bicubic effect should be used based on the transformation from the
     * local coords to the device. Returns true if the bicubic effect should be used. filterMode
     * is set to appropriate filtering mode to use regardless of the return result (e.g. when this
     * returns false it may indicate that the best fallback is to use kMipMap, kBilerp, or
     * kNearest).
     */
    static bool ShouldUseBicubic(const SkMatrix& localCoordsToDevice,
<<<<<<< HEAD
        GrTextureParams::FilterMode* filterMode);

private:
    GrBicubicEffect(GrTexture*, const SkScalar coefficients[16], const SkMatrix& matrix,
        const SkShader::TileMode tileModes[2]);
    GrBicubicEffect(GrTexture*, const SkScalar coefficients[16], const SkMatrix& matrix,
        const SkRect& domain);

    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

    void onGetGLSLProcessorKey(const GrGLSLCaps&, GrProcessorKeyBuilder*) const override;

=======
                                 GrTextureParams::FilterMode* filterMode);

private:
    GrBicubicEffect(GrProcessorDataManager*, GrTexture*, const SkScalar coefficients[16],
                    const SkMatrix &matrix, const SkShader::TileMode tileModes[2]);
    GrBicubicEffect(GrProcessorDataManager*, GrTexture*, const SkScalar coefficients[16],
                    const SkMatrix &matrix, const SkRect& domain);
>>>>>>> miniblink49
    bool onIsEqual(const GrFragmentProcessor&) const override;

    void onComputeInvariantOutput(GrInvariantOutput* inout) const override;

<<<<<<< HEAD
    float fCoefficients[16];
=======
    float           fCoefficients[16];
>>>>>>> miniblink49
    GrTextureDomain fDomain;

    GR_DECLARE_FRAGMENT_PROCESSOR_TEST;

    static const SkScalar gMitchellCoefficients[16];

    typedef GrSingleTextureEffect INHERITED;
};

#endif
