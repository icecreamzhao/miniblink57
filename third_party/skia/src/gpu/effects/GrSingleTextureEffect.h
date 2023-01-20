/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrSingleTextureEffect_DEFINED
#define GrSingleTextureEffect_DEFINED

<<<<<<< HEAD
#include "GrCoordTransform.h"
#include "GrFragmentProcessor.h"
=======
#include "GrFragmentProcessor.h"
#include "GrCoordTransform.h"
>>>>>>> miniblink49
#include "GrInvariantOutput.h"
#include "SkMatrix.h"

class GrTexture;

/**
 * A base class for effects that draw a single texture with a texture matrix. This effect has no
 * backend implementations. One must be provided by the subclass.
 */
class GrSingleTextureEffect : public GrFragmentProcessor {
public:
<<<<<<< HEAD
    ~GrSingleTextureEffect() override;

    SkString dumpInfo() const override
    {
        SkString str;
        str.appendf("Texture: %d", fTextureAccess.getTexture()->getUniqueID());
        return str;
    }

protected:
    /** unfiltered, clamp mode */
    GrSingleTextureEffect(GrTexture*, const SkMatrix&, GrCoordSet = kLocal_GrCoordSet);
    /** clamp mode */
    GrSingleTextureEffect(GrTexture*, const SkMatrix&, GrTextureParams::FilterMode filterMode,
        GrCoordSet = kLocal_GrCoordSet);
    GrSingleTextureEffect(GrTexture*,
        const SkMatrix&,
        const GrTextureParams&,
        GrCoordSet = kLocal_GrCoordSet);
=======
    virtual ~GrSingleTextureEffect();

protected:
    /** unfiltered, clamp mode */
    GrSingleTextureEffect(GrProcessorDataManager*, GrTexture*, const SkMatrix&,
                          GrCoordSet = kLocal_GrCoordSet);
    /** clamp mode */
    GrSingleTextureEffect(GrProcessorDataManager*, GrTexture*, const SkMatrix&,
                          GrTextureParams::FilterMode filterMode,
                          GrCoordSet = kLocal_GrCoordSet);
    GrSingleTextureEffect(GrProcessorDataManager*,
                          GrTexture*,
                          const SkMatrix&,
                          const GrTextureParams&,
                          GrCoordSet = kLocal_GrCoordSet);
>>>>>>> miniblink49

    /**
     * Can be used as a helper to implement subclass onComputeInvariantOutput(). It assumes that
     * the subclass output color will be a modulation of the input color with a value read from the
     * texture.
     */
<<<<<<< HEAD
    void updateInvariantOutputForModulation(GrInvariantOutput* inout) const
    {
=======
    void updateInvariantOutputForModulation(GrInvariantOutput* inout) const {
>>>>>>> miniblink49
        if (GrPixelConfigIsAlphaOnly(this->texture(0)->config())) {
            inout->mulByUnknownSingleComponent();
        } else if (GrPixelConfigIsOpaque(this->texture(0)->config())) {
            inout->mulByUnknownOpaqueFourComponents();
        } else {
            inout->mulByUnknownFourComponents();
        }
    }

private:
    GrCoordTransform fCoordTransform;
<<<<<<< HEAD
    GrTextureAccess fTextureAccess;
=======
    GrTextureAccess  fTextureAccess;
>>>>>>> miniblink49

    typedef GrFragmentProcessor INHERITED;
};

#endif
