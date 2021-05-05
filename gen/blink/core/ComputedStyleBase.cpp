// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/ComputedStyleBase.h"
#include "wtf/SizeAssertions.h"

namespace blink {

struct SameSizeAsComputedStyleBase {
    unsigned m_bitfields[2];
};
// If this fails, the packing algorithm in make_computed_style_base.py has
// failed to produce the optimal packed size. To fix, update the algorithm to
// ensure that the buckets are placed so that each takes up at most 1 word.
ASSERT_SIZE(ComputedStyleBase, SameSizeAsComputedStyleBase);

void ComputedStyleBase::inheritFrom(const ComputedStyleBase& inheritParent,
    IsAtShadowBoundary isAtShadowBoundary)
{
    m_listStyleType = inheritParent.m_listStyleType;
    m_pointerEvents = inheritParent.m_pointerEvents;
    m_textAlign = inheritParent.m_textAlign;
    m_whiteSpace = inheritParent.m_whiteSpace;
    m_captionSide = inheritParent.m_captionSide;
    m_writingMode = inheritParent.m_writingMode;
    m_textTransform = inheritParent.m_textTransform;
    m_visibility = inheritParent.m_visibility;
    m_boxDirection = inheritParent.m_boxDirection;
    m_printColorAdjust = inheritParent.m_printColorAdjust;
    m_borderCollapse = inheritParent.m_borderCollapse;
    m_rtlOrdering = inheritParent.m_rtlOrdering;
    m_listStylePosition = inheritParent.m_listStylePosition;
    m_direction = inheritParent.m_direction;
    m_emptyCells = inheritParent.m_emptyCells;
}

void ComputedStyleBase::copyNonInheritedFromCached(
    const ComputedStyleBase& other)
{
    m_unicodeBidi = other.m_unicodeBidi;
    m_floating = other.m_floating;
    m_boxDirectionIsInherited = other.m_boxDirectionIsInherited;
    m_captionSideIsInherited = other.m_captionSideIsInherited;
    m_printColorAdjustIsInherited = other.m_printColorAdjustIsInherited;
    m_borderCollapseIsInherited = other.m_borderCollapseIsInherited;
    m_rtlOrderingIsInherited = other.m_rtlOrderingIsInherited;
    m_whiteSpaceIsInherited = other.m_whiteSpaceIsInherited;
    m_listStylePositionIsInherited = other.m_listStylePositionIsInherited;
    m_pointerEventsIsInherited = other.m_pointerEventsIsInherited;
    m_textTransformIsInherited = other.m_textTransformIsInherited;
    m_emptyCellsIsInherited = other.m_emptyCellsIsInherited;
    m_visibilityIsInherited = other.m_visibilityIsInherited;
}

void ComputedStyleBase::propagateIndependentInheritedProperties(
    const ComputedStyleBase& parentStyle)
{
    if (pointerEventsIsInherited())
        setPointerEvents(parentStyle.pointerEvents());
    if (whiteSpaceIsInherited())
        setWhiteSpace(parentStyle.whiteSpace());
    if (captionSideIsInherited())
        setCaptionSide(parentStyle.captionSide());
    if (textTransformIsInherited())
        setTextTransform(parentStyle.textTransform());
    if (visibilityIsInherited())
        setVisibility(parentStyle.visibility());
    if (boxDirectionIsInherited())
        setBoxDirection(parentStyle.boxDirection());
    if (printColorAdjustIsInherited())
        setPrintColorAdjust(parentStyle.printColorAdjust());
    if (borderCollapseIsInherited())
        setBorderCollapse(parentStyle.borderCollapse());
    if (rtlOrderingIsInherited())
        setRtlOrdering(parentStyle.rtlOrdering());
    if (listStylePositionIsInherited())
        setListStylePosition(parentStyle.listStylePosition());
    if (emptyCellsIsInherited())
        setEmptyCells(parentStyle.emptyCells());
}

} // namespace blink
