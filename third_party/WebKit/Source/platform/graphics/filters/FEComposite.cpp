/*
 * Copyright (C) 2004, 2005, 2006, 2007 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005 Rob Buis <buis@kde.org>
 * Copyright (C) 2005 Eric Seidel <eric@webkit.org>
 * Copyright (C) 2009 Dirk Schulze <krit@webkit.org>
 * Copyright (C) Research In Motion Limited 2010. All rights reserved.
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

<<<<<<< HEAD
#include "platform/graphics/filters/FEComposite.h"

#include "SkXfermodeImageFilter.h"

#include "platform/graphics/filters/SkiaImageFilterBuilder.h"
#include "platform/graphics/skia/SkiaUtils.h"
=======
#include "config.h"

#include "platform/graphics/filters/FEComposite.h"

#include "SkArithmeticMode.h"
#include "SkXfermodeImageFilter.h"

#include "platform/graphics/filters/SkiaImageFilterBuilder.h"
>>>>>>> miniblink49
#include "platform/text/TextStream.h"

namespace blink {

<<<<<<< HEAD
FEComposite::FEComposite(Filter* filter,
    const CompositeOperationType& type,
    float k1,
    float k2,
    float k3,
    float k4)
=======
FEComposite::FEComposite(Filter* filter, const CompositeOperationType& type, float k1, float k2, float k3, float k4)
>>>>>>> miniblink49
    : FilterEffect(filter)
    , m_type(type)
    , m_k1(k1)
    , m_k2(k2)
    , m_k3(k3)
    , m_k4(k4)
{
}

<<<<<<< HEAD
FEComposite* FEComposite::create(Filter* filter,
    const CompositeOperationType& type,
    float k1,
    float k2,
    float k3,
    float k4)
{
    return new FEComposite(filter, type, k1, k2, k3, k4);
=======
PassRefPtrWillBeRawPtr<FEComposite> FEComposite::create(Filter* filter, const CompositeOperationType& type, float k1, float k2, float k3, float k4)
{
    return adoptRefWillBeNoop(new FEComposite(filter, type, k1, k2, k3, k4));
>>>>>>> miniblink49
}

CompositeOperationType FEComposite::operation() const
{
    return m_type;
}

bool FEComposite::setOperation(CompositeOperationType type)
{
    if (m_type == type)
        return false;
    m_type = type;
    return true;
}

float FEComposite::k1() const
{
    return m_k1;
}

bool FEComposite::setK1(float k1)
{
    if (m_k1 == k1)
        return false;
    m_k1 = k1;
    return true;
}

float FEComposite::k2() const
{
    return m_k2;
}

bool FEComposite::setK2(float k2)
{
    if (m_k2 == k2)
        return false;
    m_k2 = k2;
    return true;
}

float FEComposite::k3() const
{
    return m_k3;
}

bool FEComposite::setK3(float k3)
{
    if (m_k3 == k3)
        return false;
    m_k3 = k3;
    return true;
}

float FEComposite::k4() const
{
    return m_k4;
}

bool FEComposite::setK4(float k4)
{
    if (m_k4 == k4)
        return false;
    m_k4 = k4;
    return true;
}

<<<<<<< HEAD
bool FEComposite::affectsTransparentPixels() const
{
    // When k4 is non-zero (greater than zero with clamping factored in), the
    // arithmetic operation will produce non-transparent output for transparent
    // output.
    return m_type == FECOMPOSITE_OPERATOR_ARITHMETIC && k4() > 0;
}

FloatRect FEComposite::mapInputs(const FloatRect& rect) const
{
    FloatRect input1Rect = inputEffect(1)->mapRect(rect);
    switch (m_type) {
    case FECOMPOSITE_OPERATOR_IN:
        // 'in' has output only in the intersection of both inputs.
        return intersection(input1Rect, inputEffect(0)->mapRect(input1Rect));
    case FECOMPOSITE_OPERATOR_ATOP:
        // 'atop' has output only in the extents of the second input.
        return input1Rect;
    case FECOMPOSITE_OPERATOR_ARITHMETIC:
        // result(i1,i2) = k1*i1*i2 + k2*i1 + k3*i2 + k4
        //
        // (The below is not a complete breakdown of cases.)
        //
        // Arithmetic with non-zero k4 may influence the complete filter primitive
        // region. [k4 > 0 => result(0,0) = k4 => result(a,b) >= k4]
        if (k4() > 0)
            return rect;
        // Additionally, if k2 = 0, input 0 can only appear where input 1 also
        // appears. [k2 = k4 = 0 => result(a,b) = k1*a*b + k3*b = (k1*a + k3)*b]
        // Hence for k2 > 0, both inputs can still appear. (Except if k3 = 0.)
        if (k2() <= 0) {
            // If k3 > 0, output can be produced wherever input 1 is
            // non-transparent.
            if (k3() > 0)
                return input1Rect;
            // If just k1 is positive, output will only be produce where both
            // inputs are non-transparent. Use intersection.
            // [k1 >= 0 and k2 = k3 = k4 = 0 => result(a,b) = k1 * a * b]
            return intersection(input1Rect, inputEffect(0)->mapRect(input1Rect));
        }
    // else fall through to use union
    default:
        break;
    }
    // Take the union of both input effects.
    return unionRect(input1Rect, inputEffect(0)->mapRect(rect));
}

SkBlendMode toBlendMode(CompositeOperationType mode)
{
    switch (mode) {
    case FECOMPOSITE_OPERATOR_OVER:
        return SkBlendMode::kSrcOver;
    case FECOMPOSITE_OPERATOR_IN:
        return SkBlendMode::kSrcIn;
    case FECOMPOSITE_OPERATOR_OUT:
        return SkBlendMode::kSrcOut;
    case FECOMPOSITE_OPERATOR_ATOP:
        return SkBlendMode::kSrcATop;
    case FECOMPOSITE_OPERATOR_XOR:
        return SkBlendMode::kXor;
    case FECOMPOSITE_OPERATOR_LIGHTER:
        return SkBlendMode::kPlus;
    default:
        ASSERT_NOT_REACHED();
        return SkBlendMode::kSrcOver;
    }
}

sk_sp<SkImageFilter> FEComposite::createImageFilter()
{
    return createImageFilterInternal(true);
}

sk_sp<SkImageFilter> FEComposite::createImageFilterWithoutValidation()
{
    return createImageFilterInternal(false);
}

sk_sp<SkImageFilter> FEComposite::createImageFilterInternal(
    bool requiresPMColorValidation)
{
    sk_sp<SkImageFilter> foreground(
        SkiaImageFilterBuilder::build(inputEffect(0), operatingColorSpace(),
            !mayProduceInvalidPreMultipliedPixels()));
    sk_sp<SkImageFilter> background(
        SkiaImageFilterBuilder::build(inputEffect(1), operatingColorSpace(),
            !mayProduceInvalidPreMultipliedPixels()));
    SkImageFilter::CropRect cropRect = getCropRect();

    if (m_type == FECOMPOSITE_OPERATOR_ARITHMETIC) {
        return SkXfermodeImageFilter::MakeArithmetic(
            SkFloatToScalar(m_k1), SkFloatToScalar(m_k2), SkFloatToScalar(m_k3),
            SkFloatToScalar(m_k4), requiresPMColorValidation, std::move(background),
            std::move(foreground), &cropRect);
    }

    return SkXfermodeImageFilter::Make(toBlendMode(m_type), std::move(background),
        std::move(foreground), &cropRect);
}

static TextStream& operator<<(TextStream& ts,
    const CompositeOperationType& type)
=======
FloatRect FEComposite::determineAbsolutePaintRect(const FloatRect& originalRequestedRect)
{
    FloatRect requestedRect = originalRequestedRect;
    if (clipsToBounds())
        requestedRect.intersect(maxEffectRect());

    // We may be called multiple times if result is used more than once. Return
    // quickly if nothing new is required.
    if (absolutePaintRect().contains(enclosingIntRect(requestedRect)))
        return requestedRect;

    // No mapPaintRect required for FEComposite.
    FloatRect input1Rect = inputEffect(1)->determineAbsolutePaintRect(requestedRect);
    FloatRect affectedRect;
    switch (m_type) {
    case FECOMPOSITE_OPERATOR_IN:
        // 'in' has output only in the intersection of both inputs.
        affectedRect = intersection(input1Rect, inputEffect(0)->determineAbsolutePaintRect(input1Rect));
        break;
    case FECOMPOSITE_OPERATOR_ATOP:
        // 'atop' has output only in the extents of the second input.
        // Make sure first input knows where it needs to produce output.
        inputEffect(0)->determineAbsolutePaintRect(input1Rect);
        affectedRect = input1Rect;
        break;
    case FECOMPOSITE_OPERATOR_ARITHMETIC:
        if (k4() > 0) {
            // Make sure first input knows where it needs to produce output.
            inputEffect(0)->determineAbsolutePaintRect(requestedRect);
            // Arithmetic with non-zero k4 may influnce the complete filter primitive
            // region. So we can't optimize the paint region here.
            affectedRect = requestedRect;
            break;
        }
        if (k2() <= 0) {
            // Input 0 does not appear where input 1 is not present.
            FloatRect input0Rect = inputEffect(0)->determineAbsolutePaintRect(input1Rect);
            if (k3() > 0) {
                affectedRect = input1Rect;
            } else {
                // Just k1 is positive. Use intersection.
                affectedRect = intersection(input1Rect, input0Rect);
            }
            break;
        }
        // else fall through to use union
    default:
        // Take the union of both input effects.
        affectedRect = unionRect(input1Rect, inputEffect(0)->determineAbsolutePaintRect(requestedRect));
        break;
    }

    affectedRect.intersect(requestedRect);
    addAbsolutePaintRect(affectedRect);
    return affectedRect;
}

SkXfermode::Mode toXfermode(CompositeOperationType mode)
{
    switch (mode) {
    case FECOMPOSITE_OPERATOR_OVER:
        return SkXfermode::kSrcOver_Mode;
    case FECOMPOSITE_OPERATOR_IN:
        return SkXfermode::kSrcIn_Mode;
    case FECOMPOSITE_OPERATOR_OUT:
        return SkXfermode::kSrcOut_Mode;
    case FECOMPOSITE_OPERATOR_ATOP:
        return SkXfermode::kSrcATop_Mode;
    case FECOMPOSITE_OPERATOR_XOR:
        return SkXfermode::kXor_Mode;
    case FECOMPOSITE_OPERATOR_LIGHTER:
        return SkXfermode::kPlus_Mode;
    default:
        ASSERT_NOT_REACHED();
        return SkXfermode::kSrcOver_Mode;
    }
}

PassRefPtr<SkImageFilter> FEComposite::createImageFilter(SkiaImageFilterBuilder* builder)
{
    return createImageFilterInternal(builder, true);
}

PassRefPtr<SkImageFilter> FEComposite::createImageFilterWithoutValidation(SkiaImageFilterBuilder* builder)
{
    return createImageFilterInternal(builder, false);
}

PassRefPtr<SkImageFilter> FEComposite::createImageFilterInternal(SkiaImageFilterBuilder* builder, bool requiresPMColorValidation)
{
    RefPtr<SkImageFilter> foreground(builder->build(inputEffect(0), operatingColorSpace(), !mayProduceInvalidPreMultipliedPixels()));
    RefPtr<SkImageFilter> background(builder->build(inputEffect(1), operatingColorSpace(), !mayProduceInvalidPreMultipliedPixels()));
    SkImageFilter::CropRect cropRect = getCropRect(builder->cropOffset());
    RefPtr<SkXfermode> mode;
    if (m_type == FECOMPOSITE_OPERATOR_ARITHMETIC)
        mode = adoptRef(SkArithmeticMode::Create(SkFloatToScalar(m_k1), SkFloatToScalar(m_k2), SkFloatToScalar(m_k3), SkFloatToScalar(m_k4), requiresPMColorValidation));
    else
        mode = adoptRef(SkXfermode::Create(toXfermode(m_type)));
    return adoptRef(SkXfermodeImageFilter::Create(mode.get(), background.get(), foreground.get(), &cropRect));
}

static TextStream& operator<<(TextStream& ts, const CompositeOperationType& type)
>>>>>>> miniblink49
{
    switch (type) {
    case FECOMPOSITE_OPERATOR_UNKNOWN:
        ts << "UNKNOWN";
        break;
    case FECOMPOSITE_OPERATOR_OVER:
        ts << "OVER";
        break;
    case FECOMPOSITE_OPERATOR_IN:
        ts << "IN";
        break;
    case FECOMPOSITE_OPERATOR_OUT:
        ts << "OUT";
        break;
    case FECOMPOSITE_OPERATOR_ATOP:
        ts << "ATOP";
        break;
    case FECOMPOSITE_OPERATOR_XOR:
        ts << "XOR";
        break;
    case FECOMPOSITE_OPERATOR_ARITHMETIC:
        ts << "ARITHMETIC";
        break;
    case FECOMPOSITE_OPERATOR_LIGHTER:
        ts << "LIGHTER";
        break;
    }
    return ts;
}

<<<<<<< HEAD
TextStream& FEComposite::externalRepresentation(TextStream& ts,
    int indent) const
=======
TextStream& FEComposite::externalRepresentation(TextStream& ts, int indent) const
>>>>>>> miniblink49
{
    writeIndent(ts, indent);
    ts << "[feComposite";
    FilterEffect::externalRepresentation(ts);
    ts << " operation=\"" << m_type << "\"";
    if (m_type == FECOMPOSITE_OPERATOR_ARITHMETIC)
<<<<<<< HEAD
        ts << " k1=\"" << m_k1 << "\" k2=\"" << m_k2 << "\" k3=\"" << m_k3
           << "\" k4=\"" << m_k4 << "\"";
=======
        ts << " k1=\"" << m_k1 << "\" k2=\"" << m_k2 << "\" k3=\"" << m_k3 << "\" k4=\"" << m_k4 << "\"";
>>>>>>> miniblink49
    ts << "]\n";
    inputEffect(0)->externalRepresentation(ts, indent + 1);
    inputEffect(1)->externalRepresentation(ts, indent + 1);
    return ts;
}

} // namespace blink
