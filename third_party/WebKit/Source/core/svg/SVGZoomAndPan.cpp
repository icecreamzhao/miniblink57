/*
 * Copyright (C) 2004, 2005, 2008 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005, 2006, 2007 Rob Buis <buis@kde.org>
 * Copyright (C) 2014 Samsung Electronics. All rights reserved.
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

#include "core/svg/SVGZoomAndPan.h"

#include "wtf/text/ParsingUtilities.h"

namespace blink {

SVGZoomAndPan::SVGZoomAndPan()
    : m_zoomAndPan(SVGZoomAndPanMagnify)
{
}

void SVGZoomAndPan::resetZoomAndPan()
{
    m_zoomAndPan = SVGZoomAndPanMagnify;
}

bool SVGZoomAndPan::isKnownAttribute(const QualifiedName& attrName)
{
    return attrName == SVGNames::zoomAndPanAttr;
}

template <typename CharType>
static bool parseZoomAndPanInternal(const CharType*& start,
    const CharType* end,
    SVGZoomAndPanType& zoomAndPan)
{
    if (skipToken(start, end, "disable")) {
        zoomAndPan = SVGZoomAndPanDisable;
        return true;
    }
    if (skipToken(start, end, "magnify")) {
        zoomAndPan = SVGZoomAndPanMagnify;
        return true;
    }
    return false;
}

bool SVGZoomAndPan::parseZoomAndPan(const LChar*& start, const LChar* end)
{
    return parseZoomAndPanInternal(start, end, m_zoomAndPan);
}

bool SVGZoomAndPan::parseZoomAndPan(const UChar*& start, const UChar* end)
{
    return parseZoomAndPanInternal(start, end, m_zoomAndPan);
}

} // namespace blink
