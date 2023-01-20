/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkEmbossMaskFilter.h"
<<<<<<< HEAD
#include "SkBlurMask.h"
#include "SkBlurMaskFilter.h"
#include "SkEmbossMask.h"
#include "SkReadBuffer.h"
#include "SkString.h"
#include "SkWriteBuffer.h"

sk_sp<SkMaskFilter> SkEmbossMaskFilter::Make(SkScalar blurSigma, const Light& light)
{
    return sk_sp<SkMaskFilter>(new SkEmbossMaskFilter(blurSigma, light));
}

#ifdef SK_SUPPORT_LEGACY_MASKFILTER_PTR
SkMaskFilter* SkBlurMaskFilter::CreateEmboss(const SkScalar direction[3],
    SkScalar ambient, SkScalar specular,
    SkScalar blurRadius)
{
    return SkBlurMaskFilter::CreateEmboss(SkBlurMask::ConvertRadiusToSigma(blurRadius),
        direction, ambient, specular);
}
#endif

sk_sp<SkMaskFilter> SkBlurMaskFilter::MakeEmboss(SkScalar blurSigma, const SkScalar direction[3],
    SkScalar ambient, SkScalar specular)
{
    if (direction == nullptr) {
        return nullptr;
    }

    SkEmbossMaskFilter::Light light;

    memcpy(light.fDirection, direction, sizeof(light.fDirection));
    // ambient should be 0...1 as a scalar
    light.fAmbient = SkUnitScalarClampToByte(ambient);
    // specular should be 0..15.99 as a scalar
    static const SkScalar kSpecularMultiplier = SkIntToScalar(255) / 16;
    light.fSpecular = static_cast<U8CPU>(SkScalarPin(specular, 0, 16) * kSpecularMultiplier + 0.5);

    return SkEmbossMaskFilter::Make(blurSigma, light);
=======
#include "SkBlurMaskFilter.h"
#include "SkBlurMask.h"
#include "SkEmbossMask.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkString.h"

SkEmbossMaskFilter* SkEmbossMaskFilter::Create(SkScalar blurSigma, const Light& light) {
    return SkNEW_ARGS(SkEmbossMaskFilter, (blurSigma, light));
}

static inline int pin2byte(int n) {
    if (n < 0) {
        n = 0;
    } else if (n > 0xFF) {
        n = 0xFF;
    }
    return n;
}

SkMaskFilter* SkBlurMaskFilter::CreateEmboss(const SkScalar direction[3],
                                             SkScalar ambient, SkScalar specular,
                                             SkScalar blurRadius) {
    return SkBlurMaskFilter::CreateEmboss(SkBlurMask::ConvertRadiusToSigma(blurRadius),
                                          direction, ambient, specular);
}

SkMaskFilter* SkBlurMaskFilter::CreateEmboss(SkScalar blurSigma, const SkScalar direction[3],
                                             SkScalar ambient, SkScalar specular) {
    if (direction == NULL) {
        return NULL;
    }

    // ambient should be 0...1 as a scalar
    int am = pin2byte(SkScalarToFixed(ambient) >> 8);

    // specular should be 0..15.99 as a scalar
    int sp = pin2byte(SkScalarToFixed(specular) >> 12);

    SkEmbossMaskFilter::Light   light;

    memcpy(light.fDirection, direction, sizeof(light.fDirection));
    light.fAmbient = SkToU8(am);
    light.fSpecular = SkToU8(sp);

    return SkEmbossMaskFilter::Create(blurSigma, light);
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static void normalize(SkScalar v[3])
{
=======
static void normalize(SkScalar v[3]) {
>>>>>>> miniblink49
    SkScalar mag = SkScalarSquare(v[0]) + SkScalarSquare(v[1]) + SkScalarSquare(v[2]);
    mag = SkScalarSqrt(mag);

    for (int i = 0; i < 3; i++) {
        v[i] /= mag;
    }
}

SkEmbossMaskFilter::SkEmbossMaskFilter(SkScalar blurSigma, const Light& light)
<<<<<<< HEAD
    : fLight(light)
    , fBlurSigma(blurSigma)
{
    normalize(fLight.fDirection);
}

SkMask::Format SkEmbossMaskFilter::getFormat() const
{
=======
    : fLight(light), fBlurSigma(blurSigma) {
    normalize(fLight.fDirection);
}

SkMask::Format SkEmbossMaskFilter::getFormat() const {
>>>>>>> miniblink49
    return SkMask::k3D_Format;
}

bool SkEmbossMaskFilter::filterMask(SkMask* dst, const SkMask& src,
<<<<<<< HEAD
    const SkMatrix& matrix, SkIPoint* margin) const
{
=======
                                    const SkMatrix& matrix, SkIPoint* margin) const {
>>>>>>> miniblink49
    SkScalar sigma = matrix.mapRadius(fBlurSigma);

    if (!SkBlurMask::BoxBlur(dst, src, sigma, kInner_SkBlurStyle, kLow_SkBlurQuality)) {
        return false;
    }

    dst->fFormat = SkMask::k3D_Format;
    if (margin) {
<<<<<<< HEAD
        margin->set(SkScalarCeilToInt(3 * sigma), SkScalarCeilToInt(3 * sigma));
    }

    if (src.fImage == nullptr) {
=======
        margin->set(SkScalarCeilToInt(3*sigma), SkScalarCeilToInt(3*sigma));
    }

    if (src.fImage == NULL) {
>>>>>>> miniblink49
        return true;
    }

    // create a larger buffer for the other two channels (should force fBlur to do this for us)

    {
        uint8_t* alphaPlane = dst->fImage;
<<<<<<< HEAD
        size_t planeSize = dst->computeImageSize();
        if (0 == planeSize) {
            return false; // too big to allocate, abort
=======
        size_t   planeSize = dst->computeImageSize();
        if (0 == planeSize) {
            return false;   // too big to allocate, abort
>>>>>>> miniblink49
        }
        dst->fImage = SkMask::AllocImage(planeSize * 3);
        memcpy(dst->fImage, alphaPlane, planeSize);
        SkMask::FreeImage(alphaPlane);
    }

    // run the light direction through the matrix...
<<<<<<< HEAD
    Light light = fLight;
    matrix.mapVectors((SkVector*)(void*)light.fDirection,
        (SkVector*)(void*)fLight.fDirection, 1);
=======
    Light   light = fLight;
    matrix.mapVectors((SkVector*)(void*)light.fDirection,
                      (SkVector*)(void*)fLight.fDirection, 1);
>>>>>>> miniblink49

    // now restore the length of the XY component
    // cast to SkVector so we can call setLength (this double cast silences alias warnings)
    SkVector* vec = (SkVector*)(void*)light.fDirection;
    vec->setLength(light.fDirection[0],
<<<<<<< HEAD
        light.fDirection[1],
        SkPoint::Length(fLight.fDirection[0], fLight.fDirection[1]));
=======
                   light.fDirection[1],
                   SkPoint::Length(fLight.fDirection[0], fLight.fDirection[1]));
>>>>>>> miniblink49

    SkEmbossMask::Emboss(dst, light);

    // restore original alpha
    memcpy(dst->fImage, src.fImage, src.computeImageSize());

    return true;
}

<<<<<<< HEAD
sk_sp<SkFlattenable> SkEmbossMaskFilter::CreateProc(SkReadBuffer& buffer)
{
=======
SkFlattenable* SkEmbossMaskFilter::CreateProc(SkReadBuffer& buffer) {
>>>>>>> miniblink49
    Light light;
    if (buffer.readByteArray(&light, sizeof(Light))) {
        light.fPad = 0; // for the font-cache lookup to be clean
        const SkScalar sigma = buffer.readScalar();
<<<<<<< HEAD
        return Make(sigma, light);
    }
    return nullptr;
}

void SkEmbossMaskFilter::flatten(SkWriteBuffer& buffer) const
{
    Light tmpLight = fLight;
    tmpLight.fPad = 0; // for the font-cache lookup to be clean
=======
        return Create(sigma, light);
    }
    return NULL;
}

void SkEmbossMaskFilter::flatten(SkWriteBuffer& buffer) const {
    Light tmpLight = fLight;
    tmpLight.fPad = 0;    // for the font-cache lookup to be clean
>>>>>>> miniblink49
    buffer.writeByteArray(&tmpLight, sizeof(tmpLight));
    buffer.writeScalar(fBlurSigma);
}

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
void SkEmbossMaskFilter::toString(SkString* str) const
{
=======
void SkEmbossMaskFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->append("SkEmbossMaskFilter: (");

    str->append("direction: (");
    str->appendScalar(fLight.fDirection[0]);
    str->append(", ");
    str->appendScalar(fLight.fDirection[1]);
    str->append(", ");
    str->appendScalar(fLight.fDirection[2]);
    str->append(") ");

    str->appendf("ambient: %d specular: %d ",
        fLight.fAmbient, fLight.fSpecular);

    str->append("blurSigma: ");
    str->appendScalar(fBlurSigma);
    str->append(")");
}
#endif
