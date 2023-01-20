/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrInvariantOutput.h"

#ifdef SK_DEBUG

<<<<<<< HEAD
void GrInvariantOutput::validate() const
{
=======
void GrInvariantOutput::validate() const {
>>>>>>> miniblink49
    if (fIsSingleComponent) {
        SkASSERT(0 == fValidFlags || kRGBA_GrColorComponentFlags == fValidFlags);
        if (kRGBA_GrColorComponentFlags == fValidFlags) {
            SkASSERT(this->colorComponentsAllEqual());
        }
    }

<<<<<<< HEAD
=======
    SkASSERT(this->validPreMulColor());

>>>>>>> miniblink49
    // If we claim that we are not using the input color we must not be modulating the input.
    SkASSERT(fNonMulStageFound || fWillUseInputColor);
}

<<<<<<< HEAD
bool GrInvariantOutput::colorComponentsAllEqual() const
{
    unsigned colorA = GrColorUnpackA(fColor);
    return (GrColorUnpackR(fColor) == colorA && GrColorUnpackG(fColor) == colorA && GrColorUnpackB(fColor) == colorA);
}

#endif // end DEBUG
=======
bool GrInvariantOutput::colorComponentsAllEqual() const {
    unsigned colorA = GrColorUnpackA(fColor);
    return(GrColorUnpackR(fColor) == colorA &&
           GrColorUnpackG(fColor) == colorA &&
           GrColorUnpackB(fColor) == colorA);
}

bool GrInvariantOutput::validPreMulColor() const {
    if (kA_GrColorComponentFlag & fValidFlags) {
        float c[4];
        GrColorToRGBAFloat(fColor, c);
        if (kR_GrColorComponentFlag & fValidFlags) {
            if (c[0] > c[3]) {
                return false;
            }
        }
        if (kG_GrColorComponentFlag & fValidFlags) {
            if (c[1] > c[3]) {
                return false;
            }
        }
        if (kB_GrColorComponentFlag & fValidFlags) {
            if (c[2] > c[3]) {
                return false;
            }
        }
    }
    return true;
}

#endif // end DEBUG

>>>>>>> miniblink49
