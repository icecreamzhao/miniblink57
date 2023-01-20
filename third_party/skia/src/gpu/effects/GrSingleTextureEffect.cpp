/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "effects/GrSingleTextureEffect.h"

<<<<<<< HEAD
GrSingleTextureEffect::GrSingleTextureEffect(GrTexture* texture,
    const SkMatrix& m,
    GrCoordSet coordSet)
    : fCoordTransform(coordSet, m, texture, GrTextureParams::kNone_FilterMode)
    , fTextureAccess(texture)
{
=======
GrSingleTextureEffect::GrSingleTextureEffect(GrProcessorDataManager* procDataManager,
                                             GrTexture* texture,
                                             const SkMatrix& m,
                                             GrCoordSet coordSet)
    : fCoordTransform(coordSet, m, texture, GrTextureParams::kNone_FilterMode)
    , fTextureAccess(texture) {
>>>>>>> miniblink49
    this->addCoordTransform(&fCoordTransform);
    this->addTextureAccess(&fTextureAccess);
}

<<<<<<< HEAD
GrSingleTextureEffect::GrSingleTextureEffect(GrTexture* texture,
    const SkMatrix& m,
    GrTextureParams::FilterMode filterMode,
    GrCoordSet coordSet)
    : fCoordTransform(coordSet, m, texture, filterMode)
    , fTextureAccess(texture, filterMode)
{
=======
GrSingleTextureEffect::GrSingleTextureEffect(GrProcessorDataManager* procDataManager,
                                             GrTexture* texture,
                                             const SkMatrix& m,
                                             GrTextureParams::FilterMode filterMode,
                                             GrCoordSet coordSet)
    : fCoordTransform(coordSet, m, texture, filterMode)
    , fTextureAccess(texture, filterMode) {
>>>>>>> miniblink49
    this->addCoordTransform(&fCoordTransform);
    this->addTextureAccess(&fTextureAccess);
}

<<<<<<< HEAD
GrSingleTextureEffect::GrSingleTextureEffect(GrTexture* texture,
    const SkMatrix& m,
    const GrTextureParams& params,
    GrCoordSet coordSet)
    : fCoordTransform(coordSet, m, texture, params.filterMode())
    , fTextureAccess(texture, params)
{
=======
GrSingleTextureEffect::GrSingleTextureEffect(GrProcessorDataManager* procDataManager,
                                             GrTexture* texture,
                                             const SkMatrix& m,
                                             const GrTextureParams& params,
                                             GrCoordSet coordSet)
    : fCoordTransform(coordSet, m, texture, params.filterMode())
    , fTextureAccess(texture, params) {
>>>>>>> miniblink49
    this->addCoordTransform(&fCoordTransform);
    this->addTextureAccess(&fTextureAccess);
}

<<<<<<< HEAD
GrSingleTextureEffect::~GrSingleTextureEffect()
{
=======
GrSingleTextureEffect::~GrSingleTextureEffect() {
>>>>>>> miniblink49
}
