/*
 * Copyright (C) Research In Motion Limited 2011. All rights reserved.
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
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/graphics/filters/FEDropShadow.h"

#include "platform/graphics/filters/FEGaussianBlur.h"
#include "platform/graphics/filters/Filter.h"
#include "platform/graphics/filters/SkiaImageFilterBuilder.h"
#include "platform/text/TextStream.h"
#include "third_party/skia/include/effects/SkDropShadowImageFilter.h"

namespace blink {

<<<<<<< HEAD
FEDropShadow::FEDropShadow(Filter* filter,
    float stdX,
    float stdY,
    float dx,
    float dy,
    const Color& shadowColor,
    float shadowOpacity)
=======
FEDropShadow::FEDropShadow(Filter* filter, float stdX, float stdY, float dx, float dy, const Color& shadowColor, float shadowOpacity)
>>>>>>> miniblink49
    : FilterEffect(filter)
    , m_stdX(stdX)
    , m_stdY(stdY)
    , m_dx(dx)
    , m_dy(dy)
    , m_shadowColor(shadowColor)
    , m_shadowOpacity(shadowOpacity)
{
}

<<<<<<< HEAD
FEDropShadow* FEDropShadow::create(Filter* filter,
    float stdX,
    float stdY,
    float dx,
    float dy,
    const Color& shadowColor,
    float shadowOpacity)
{
    return new FEDropShadow(filter, stdX, stdY, dx, dy, shadowColor,
        shadowOpacity);
}

FloatRect FEDropShadow::mapEffect(const FloatSize& stdDeviation,
    const FloatPoint& offset,
    const FloatRect& rect)
{
    FloatRect offsetRect = rect;
    offsetRect.moveBy(offset);
    FloatRect blurredRect = FEGaussianBlur::mapEffect(stdDeviation, offsetRect);
    return unionRect(blurredRect, rect);
}

FloatRect FEDropShadow::mapEffect(const FloatRect& rect) const
{
    const Filter* filter = this->getFilter();
    DCHECK(filter);
    FloatPoint offset(filter->applyHorizontalScale(m_dx),
        filter->applyVerticalScale(m_dy));
    FloatSize stdError(filter->applyHorizontalScale(m_stdX),
        filter->applyVerticalScale(m_stdY));
    return mapEffect(stdError, offset, rect);
}

sk_sp<SkImageFilter> FEDropShadow::createImageFilter()
{
    sk_sp<SkImageFilter> input(
        SkiaImageFilterBuilder::build(inputEffect(0), operatingColorSpace()));
    float dx = getFilter()->applyHorizontalScale(m_dx);
    float dy = getFilter()->applyVerticalScale(m_dy);
    float stdX = getFilter()->applyHorizontalScale(m_stdX);
    float stdY = getFilter()->applyVerticalScale(m_stdY);
    Color color = adaptColorToOperatingColorSpace(
        m_shadowColor.combineWithAlpha(m_shadowOpacity));
    SkImageFilter::CropRect cropRect = getCropRect();
    return SkDropShadowImageFilter::Make(
        SkFloatToScalar(dx), SkFloatToScalar(dy), SkFloatToScalar(stdX),
        SkFloatToScalar(stdY), color.rgb(),
        SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode,
        std::move(input), &cropRect);
}

TextStream& FEDropShadow::externalRepresentation(TextStream& ts,
    int indent) const
=======
PassRefPtrWillBeRawPtr<FEDropShadow> FEDropShadow::create(Filter* filter, float stdX, float stdY, float dx, float dy, const Color& shadowColor, float shadowOpacity)
{
    return adoptRefWillBeNoop(new FEDropShadow(filter, stdX, stdY, dx, dy, shadowColor, shadowOpacity));
}

FloatRect FEDropShadow::mapRect(const FloatRect& rect, bool forward)
{
    FloatRect result = rect;
    Filter* filter = this->filter();
    ASSERT(filter);

    FloatRect offsetRect = rect;
    if (forward)
        offsetRect.move(filter->applyHorizontalScale(m_dx), filter->applyVerticalScale(m_dy));
    else
        offsetRect.move(-filter->applyHorizontalScale(m_dx), -filter->applyVerticalScale(m_dy));
    result.unite(offsetRect);

    IntSize kernelSize = FEGaussianBlur::calculateKernelSize(filter, FloatPoint(m_stdX, m_stdY));

    // We take the half kernel size and multiply it with three, because we run box blur three times.
    result.inflateX(3 * kernelSize.width() * 0.5f);
    result.inflateY(3 * kernelSize.height() * 0.5f);
    return result;
}

PassRefPtr<SkImageFilter> FEDropShadow::createImageFilter(SkiaImageFilterBuilder* builder)
{
    RefPtr<SkImageFilter> input(builder->build(inputEffect(0), operatingColorSpace()));
    float dx = filter()->applyHorizontalScale(m_dx);
    float dy = filter()->applyVerticalScale(m_dy);
    float stdX = filter()->applyHorizontalScale(m_stdX);
    float stdY = filter()->applyVerticalScale(m_stdY);
    Color color = adaptColorToOperatingColorSpace(m_shadowColor.combineWithAlpha(m_shadowOpacity));
    SkImageFilter::CropRect cropRect = getCropRect(builder->cropOffset());
    return adoptRef(SkDropShadowImageFilter::Create(SkFloatToScalar(dx), SkFloatToScalar(dy), SkFloatToScalar(stdX), SkFloatToScalar(stdY), color.rgb(), SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, input.get(), &cropRect));
}


TextStream& FEDropShadow::externalRepresentation(TextStream& ts, int indent) const
>>>>>>> miniblink49
{
    writeIndent(ts, indent);
    ts << "[feDropShadow";
    FilterEffect::externalRepresentation(ts);
<<<<<<< HEAD
    ts << " stdDeviation=\"" << m_stdX << ", " << m_stdY << "\" dx=\"" << m_dx
       << "\" dy=\"" << m_dy << "\" flood-color=\""
       << m_shadowColor.nameForLayoutTreeAsText() << "\" flood-opacity=\""
       << m_shadowOpacity << "]\n";
=======
    ts << " stdDeviation=\"" << m_stdX << ", " << m_stdY << "\" dx=\"" << m_dx << "\" dy=\"" << m_dy << "\" flood-color=\"" << m_shadowColor.nameForLayoutTreeAsText() <<"\" flood-opacity=\"" << m_shadowOpacity << "]\n";
>>>>>>> miniblink49
    inputEffect(0)->externalRepresentation(ts, indent + 1);
    return ts;
}

} // namespace blink
