/*
 * Copyright (C) 2004, 2005, 2007 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005, 2007 Rob Buis <buis@kde.org>
 * Copyright (C) 2009 Google, Inc.
 * Copyright (C) 2009 Apple Inc. All rights reserved.
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

#ifndef LayoutSVGViewportContainer_h
#define LayoutSVGViewportContainer_h

#include "core/layout/svg/LayoutSVGContainer.h"

namespace blink {

class SVGSVGElement;

// This is used for non-root <svg> elements which are SVGTransformable thus we
// inherit from LayoutSVGContainer instead of LayoutSVGTransformableContainer.
class LayoutSVGViewportContainer final : public LayoutSVGContainer {
public:
    explicit LayoutSVGViewportContainer(SVGSVGElement*);
    FloatRect viewport() const { return m_viewport; }

    bool isLayoutSizeChanged() const { return m_isLayoutSizeChanged; }

    void setNeedsTransformUpdate() override;

    const char* name() const override { return "LayoutSVGViewportContainer"; }

private:
    bool isOfType(LayoutObjectType type) const override
    {
        return type == LayoutObjectSVGViewportContainer || LayoutSVGContainer::isOfType(type);
    }

    void layout() override;

    AffineTransform localToSVGParentTransform() const override
    {
        return m_localToParentTransform;
    }

    SVGTransformChange calculateLocalTransform() override;

    bool nodeAtFloatPoint(HitTestResult&,
        const FloatPoint& pointInParent,
        HitTestAction) override;

    FloatRect m_viewport;
    mutable AffineTransform m_localToParentTransform;
    bool m_isLayoutSizeChanged : 1;
    bool m_needsTransformUpdate : 1;
};

DEFINE_LAYOUT_OBJECT_TYPE_CASTS(LayoutSVGViewportContainer,
    isSVGViewportContainer());

} // namespace blink

#endif // LayoutSVGViewportContainer_h
