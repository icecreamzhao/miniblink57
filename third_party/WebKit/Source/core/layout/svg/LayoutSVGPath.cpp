/*
 * Copyright (C) 2004, 2005, 2007 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005, 2008 Rob Buis <buis@kde.org>
 * Copyright (C) 2005, 2007 Eric Seidel <eric@webkit.org>
 * Copyright (C) 2009 Google, Inc.
 * Copyright (C) 2009 Dirk Schulze <krit@webkit.org>
 * Copyright (C) Research In Motion Limited 2010. All rights reserved.
 * Copyright (C) 2009 Jeff Schiller <codedread@gmail.com>
 * Copyright (C) 2011 Renata Hodovan <reni@webkit.org>
 * Copyright (C) 2011 University of Szeged
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

#include "core/layout/svg/LayoutSVGPath.h"

#include "core/layout/svg/LayoutSVGResourceMarker.h"
#include "core/layout/svg/SVGResources.h"
#include "core/layout/svg/SVGResourcesCache.h"
#include "core/svg/SVGGeometryElement.h"
#include "wtf/MathExtras.h"

namespace blink {

LayoutSVGPath::LayoutSVGPath(SVGGeometryElement* node)
    : LayoutSVGShape(node)
{
}

LayoutSVGPath::~LayoutSVGPath() { }

void LayoutSVGPath::updateShapeFromElement()
{
    LayoutSVGShape::updateShapeFromElement();
    processMarkerPositions();

    m_strokeBoundingBox = calculateUpdatedStrokeBoundingBox();
    if (element())
        element()->setNeedsResizeObserverUpdate();
}

FloatRect LayoutSVGPath::hitTestStrokeBoundingBox() const
{
    const SVGComputedStyle& svgStyle = style()->svgStyle();
    if (svgStyle.hasStroke())
        return m_strokeBoundingBox;

    // Implementation of
    // http://dev.w3.org/fxtf/css-masking-1/#compute-stroke-bounding-box
    // except that we ignore whether the stroke is none.

    FloatRect box = m_fillBoundingBox;

    const float strokeWidth = this->strokeWidth();
    if (strokeWidth <= 0)
        return box;

    float delta = strokeWidth / 2;

    if (svgStyle.hasMiterJoinStyle()) {
        const float miter = svgStyle.strokeMiterLimit();
        if (miter < M_SQRT2 && svgStyle.hasSquareCapStyle())
            delta *= M_SQRT2;
        else
            delta *= miter;
    } else if (svgStyle.hasSquareCapStyle()) {
        delta *= M_SQRT2;
    }

    box.inflate(delta);
    return box;
}

FloatRect LayoutSVGPath::calculateUpdatedStrokeBoundingBox() const
{
    FloatRect strokeBoundingBox = m_strokeBoundingBox;
    if (!m_markerPositions.isEmpty())
        strokeBoundingBox.unite(markerRect(strokeWidth()));
    return strokeBoundingBox;
}

FloatRect LayoutSVGPath::markerRect(float strokeWidth) const
{
    ASSERT(!m_markerPositions.isEmpty());

    SVGResources* resources = SVGResourcesCache::cachedResourcesForLayoutObject(this);
    ASSERT(resources);

    LayoutSVGResourceMarker* markerStart = resources->markerStart();
    LayoutSVGResourceMarker* markerMid = resources->markerMid();
    LayoutSVGResourceMarker* markerEnd = resources->markerEnd();
    ASSERT(markerStart || markerMid || markerEnd);

    FloatRect boundaries;
    unsigned size = m_markerPositions.size();
    for (unsigned i = 0; i < size; ++i) {
        if (LayoutSVGResourceMarker* marker = SVGMarkerData::markerForType(
                m_markerPositions[i].type, markerStart, markerMid, markerEnd))
            boundaries.unite(marker->markerBoundaries(marker->markerTransformation(
                m_markerPositions[i].origin, m_markerPositions[i].angle,
                strokeWidth)));
    }
    return boundaries;
}

bool LayoutSVGPath::shouldGenerateMarkerPositions() const
{
    if (!style()->svgStyle().hasMarkers())
        return false;

    if (!SVGResources::supportsMarkers(*toSVGGraphicsElement(element())))
        return false;

    SVGResources* resources = SVGResourcesCache::cachedResourcesForLayoutObject(this);
    if (!resources)
        return false;

    return resources->markerStart() || resources->markerMid() || resources->markerEnd();
}

void LayoutSVGPath::processMarkerPositions()
{
    m_markerPositions.clear();

    if (!shouldGenerateMarkerPositions())
        return;

    SVGResources* resources = SVGResourcesCache::cachedResourcesForLayoutObject(this);
    ASSERT(resources);

    LayoutSVGResourceMarker* markerStart = resources->markerStart();

    SVGMarkerData markerData(
        m_markerPositions,
        markerStart ? markerStart->orientType() == SVGMarkerOrientAutoStartReverse
                    : false);
    path().apply(&markerData, SVGMarkerData::updateFromPathElement);
    markerData.pathIsDone();
}

} // namespace blink
