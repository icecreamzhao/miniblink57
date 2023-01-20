/*
 * Copyright (C) 2008 Alex Mathews <possessedpenguinbob@gmail.com>
 * Copyright (C) 2009 Dirk Schulze <krit@webkit.org>
 * Copyright (C) Research In Motion Limited 2010. All rights reserved.
 * Copyright (C) 2012 University of Szeged
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
#include "platform/graphics/filters/FilterEffect.h"

#include "platform/graphics/filters/Filter.h"
#include "third_party/skia/include/core/SkColorFilter.h"
#include "third_party/skia/include/effects/SkColorFilterImageFilter.h"
=======
#include "config.h"

#include "platform/graphics/filters/FilterEffect.h"

#include "platform/graphics/filters/Filter.h"
>>>>>>> miniblink49

namespace blink {

FilterEffect::FilterEffect(Filter* filter)
    : m_filter(filter)
<<<<<<< HEAD
    , m_clipsToBounds(true)
    , m_originTainted(false)
=======
    , m_hasX(false)
    , m_hasY(false)
    , m_hasWidth(false)
    , m_hasHeight(false)
    , m_clipsToBounds(true)
>>>>>>> miniblink49
    , m_operatingColorSpace(ColorSpaceLinearRGB)
{
    ASSERT(m_filter);
}

<<<<<<< HEAD
FilterEffect::~FilterEffect() { }
=======
FilterEffect::~FilterEffect()
{
}
>>>>>>> miniblink49

DEFINE_TRACE(FilterEffect)
{
    visitor->trace(m_inputEffects);
    visitor->trace(m_filter);
}

<<<<<<< HEAD
FloatRect FilterEffect::absoluteBounds() const
{
    FloatRect computedBounds = getFilter()->filterRegion();
    if (!filterPrimitiveSubregion().isEmpty())
        computedBounds.intersect(filterPrimitiveSubregion());
    return getFilter()->mapLocalRectToAbsoluteRect(computedBounds);
}

FloatRect FilterEffect::mapInputs(const FloatRect& rect) const
{
    if (!m_inputEffects.size()) {
        if (clipsToBounds())
            return absoluteBounds();
        return rect;
    }
    FloatRect inputUnion;
    for (const auto& effect : m_inputEffects)
        inputUnion.unite(effect->mapRect(rect));
    return inputUnion;
}

FloatRect FilterEffect::mapEffect(const FloatRect& rect) const
{
    return rect;
}

FloatRect FilterEffect::applyBounds(const FloatRect& rect) const
{
    // Filters in SVG clip to primitive subregion, while CSS doesn't.
    if (!clipsToBounds())
        return rect;
    FloatRect bounds = absoluteBounds();
    if (affectsTransparentPixels())
        return bounds;
    return intersection(rect, bounds);
}

FloatRect FilterEffect::mapRect(const FloatRect& rect) const
{
    FloatRect result = mapInputs(rect);
    result = mapEffect(result);
    return applyBounds(result);
=======
FloatRect FilterEffect::determineAbsolutePaintRect(const FloatRect& originalRequestedRect)
{
    FloatRect requestedRect = originalRequestedRect;
    // Filters in SVG clip to primitive subregion, while CSS doesn't.
    if (m_clipsToBounds)
        requestedRect.intersect(maxEffectRect());

    // We may be called multiple times if result is used more than once. Return
    // quickly if if nothing new is required.
    if (absolutePaintRect().contains(enclosingIntRect(requestedRect)))
        return requestedRect;

    FloatRect inputRect = mapPaintRect(requestedRect, false);
    FloatRect inputUnion;
    unsigned size = m_inputEffects.size();

    for (unsigned i = 0; i < size; ++i)
        inputUnion.unite(m_inputEffects.at(i)->determineAbsolutePaintRect(inputRect));
    inputUnion = mapPaintRect(inputUnion, true);

    if (affectsTransparentPixels() || !size) {
        inputUnion = requestedRect;
    } else {
        // Rect may have inflated. Re-intersect with request.
        inputUnion.intersect(requestedRect);
    }

    addAbsolutePaintRect(inputUnion);
    return inputUnion;
}

FloatRect FilterEffect::mapRectRecursive(const FloatRect& rect)
{
    FloatRect result;
    if (m_inputEffects.size() > 0) {
        result = m_inputEffects.at(0)->mapRectRecursive(rect);
        for (unsigned i = 1; i < m_inputEffects.size(); ++i)
            result.unite(m_inputEffects.at(i)->mapRectRecursive(rect));
    } else
        result = rect;
    return mapRect(result);
>>>>>>> miniblink49
}

FilterEffect* FilterEffect::inputEffect(unsigned number) const
{
<<<<<<< HEAD
    SECURITY_DCHECK(number < m_inputEffects.size());
    return m_inputEffects.at(number).get();
}

void FilterEffect::clearResult()
{
    for (int i = 0; i < 4; i++)
        m_imageFilters[i] = nullptr;
=======
    ASSERT_WITH_SECURITY_IMPLICATION(number < m_inputEffects.size());
    return m_inputEffects.at(number).get();
}

void FilterEffect::addAbsolutePaintRect(const FloatRect& paintRect)
{
    IntRect intPaintRect(enclosingIntRect(paintRect));
    if (m_absolutePaintRect.contains(intPaintRect))
        return;
    intPaintRect.unite(m_absolutePaintRect);
    // Make sure we are not holding on to a smaller rendering.
    clearResult();
    m_absolutePaintRect = intPaintRect;
}

void FilterEffect::clearResult()
{
    m_absolutePaintRect = IntRect();
    for (int i = 0; i < 4; i++) {
        m_imageFilters[i] = nullptr;
    }
>>>>>>> miniblink49
}

Color FilterEffect::adaptColorToOperatingColorSpace(const Color& deviceColor)
{
    // |deviceColor| is assumed to be DeviceRGB.
    return ColorSpaceUtilities::convertColor(deviceColor, operatingColorSpace());
}

TextStream& FilterEffect::externalRepresentation(TextStream& ts, int) const
{
<<<<<<< HEAD
    // FIXME: We should dump the subRegions of the filter primitives here later.
    // This isn't possible at the moment, because we need more detailed
    // information from the target object.
    return ts;
}

sk_sp<SkImageFilter> FilterEffect::createImageFilter()
=======
    // FIXME: We should dump the subRegions of the filter primitives here later. This isn't
    // possible at the moment, because we need more detailed informations from the target object.
    return ts;
}

FloatRect FilterEffect::determineFilterPrimitiveSubregion(DetermineSubregionFlags flags)
{
    Filter* filter = this->filter();
    ASSERT(filter);

    // FETile, FETurbulence, FEFlood don't have input effects, take the filter region as unite rect.
    FloatRect subregion;
    if (unsigned numberOfInputEffects = inputEffects().size()) {
        subregion = inputEffect(0)->determineFilterPrimitiveSubregion(flags);
        for (unsigned i = 1; i < numberOfInputEffects; ++i)
            subregion.unite(inputEffect(i)->determineFilterPrimitiveSubregion(flags));
    } else {
        subregion = filter->filterRegion();
    }

    // After calling determineFilterPrimitiveSubregion on the target effect, reset the subregion again for <feTile>.
    if (filterEffectType() == FilterEffectTypeTile)
        subregion = filter->filterRegion();

    if (flags & MapRectForward) {
        // mapRect works on absolute rectangles.
        subregion = filter->mapAbsoluteRectToLocalRect(mapRect(
            filter->mapLocalRectToAbsoluteRect(subregion)));
    }

    FloatRect boundaries = effectBoundaries();
    if (hasX())
        subregion.setX(boundaries.x());
    if (hasY())
        subregion.setY(boundaries.y());
    if (hasWidth())
        subregion.setWidth(boundaries.width());
    if (hasHeight())
        subregion.setHeight(boundaries.height());

    setFilterPrimitiveSubregion(subregion);

    FloatRect absoluteSubregion = filter->mapLocalRectToAbsoluteRect(subregion);

    // Clip every filter effect to the filter region.
    if (flags & ClipToFilterRegion) {
        absoluteSubregion.intersect(filter->absoluteFilterRegion());
    }

    setMaxEffectRect(absoluteSubregion);
    return subregion;
}

PassRefPtr<SkImageFilter> FilterEffect::createImageFilter(SkiaImageFilterBuilder* builder)
>>>>>>> miniblink49
{
    return nullptr;
}

<<<<<<< HEAD
sk_sp<SkImageFilter> FilterEffect::createImageFilterWithoutValidation()
{
    return createImageFilter();
}

bool FilterEffect::inputsTaintOrigin() const
{
    for (const Member<FilterEffect>& effect : m_inputEffects) {
        if (effect->originTainted())
            return true;
    }
    return false;
}

sk_sp<SkImageFilter> FilterEffect::createTransparentBlack() const
{
    SkImageFilter::CropRect rect = getCropRect();
    sk_sp<SkColorFilter> colorFilter = SkColorFilter::MakeModeFilter(0, SkBlendMode::kClear);
    return SkColorFilterImageFilter::Make(std::move(colorFilter), nullptr, &rect);
}

SkImageFilter::CropRect FilterEffect::getCropRect() const
{
    if (!filterPrimitiveSubregion().isEmpty()) {
        FloatRect rect = getFilter()->mapLocalRectToAbsoluteRect(filterPrimitiveSubregion());
        return SkImageFilter::CropRect(rect);
    } else {
        return SkImageFilter::CropRect(SkRect::MakeEmpty(), 0);
    }
}

static int getImageFilterIndex(ColorSpace colorSpace,
    bool requiresPMColorValidation)
=======
PassRefPtr<SkImageFilter> FilterEffect::createImageFilterWithoutValidation(SkiaImageFilterBuilder* builder)
{
    return createImageFilter(builder);
}

SkImageFilter::CropRect FilterEffect::getCropRect(const FloatSize& cropOffset) const
{
    FloatRect rect = filter()->filterRegion();
    uint32_t flags = 0;
    FloatRect boundaries = effectBoundaries();
    boundaries.move(cropOffset);
    if (hasX()) {
        rect.setX(boundaries.x());
        flags |= SkImageFilter::CropRect::kHasLeft_CropEdge;
        flags |= SkImageFilter::CropRect::kHasRight_CropEdge;
    }
    if (hasY()) {
        rect.setY(boundaries.y());
        flags |= SkImageFilter::CropRect::kHasTop_CropEdge;
        flags |= SkImageFilter::CropRect::kHasBottom_CropEdge;
    }
    if (hasWidth()) {
        rect.setWidth(boundaries.width());
        flags |= SkImageFilter::CropRect::kHasRight_CropEdge;
    }
    if (hasHeight()) {
        rect.setHeight(boundaries.height());
        flags |= SkImageFilter::CropRect::kHasBottom_CropEdge;
    }
    rect.scale(filter()->scale());
    return SkImageFilter::CropRect(rect, flags);
}

static int getImageFilterIndex(ColorSpace colorSpace, bool requiresPMColorValidation)
>>>>>>> miniblink49
{
    // Map the (colorspace, bool) tuple to an integer index as follows:
    // 0 == linear colorspace, no PM validation
    // 1 == device colorspace, no PM validation
    // 2 == linear colorspace, PM validation
    // 3 == device colorspace, PM validation
    return (colorSpace == ColorSpaceLinearRGB ? 0x1 : 0x0) | (requiresPMColorValidation ? 0x2 : 0x0);
}

<<<<<<< HEAD
SkImageFilter* FilterEffect::getImageFilter(
    ColorSpace colorSpace,
    bool requiresPMColorValidation) const
=======
SkImageFilter* FilterEffect::getImageFilter(ColorSpace colorSpace, bool requiresPMColorValidation) const
>>>>>>> miniblink49
{
    int index = getImageFilterIndex(colorSpace, requiresPMColorValidation);
    return m_imageFilters[index].get();
}

<<<<<<< HEAD
void FilterEffect::setImageFilter(ColorSpace colorSpace,
    bool requiresPMColorValidation,
    sk_sp<SkImageFilter> imageFilter)
{
    int index = getImageFilterIndex(colorSpace, requiresPMColorValidation);
    m_imageFilters[index] = std::move(imageFilter);
=======
void FilterEffect::setImageFilter(ColorSpace colorSpace, bool requiresPMColorValidation, PassRefPtr<SkImageFilter> imageFilter)
{
    int index = getImageFilterIndex(colorSpace, requiresPMColorValidation);
    m_imageFilters[index] = imageFilter;
>>>>>>> miniblink49
}

} // namespace blink
