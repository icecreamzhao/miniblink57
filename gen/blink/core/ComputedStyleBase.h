// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ComputedStyleBase_h
#define ComputedStyleBase_h

#include "core/ComputedStyleBaseConstants.h"
#include "core/CoreExport.h"
#include "platform/text/TextDirection.h"
#include "platform/text/UnicodeBidi.h"
#include "platform/text/WritingMode.h"

namespace blink {

// The generated portion of ComputedStyle. For more info, see the header comment
// in ComputedStyle.h.
class CORE_EXPORT ComputedStyleBase {
public:
    ALWAYS_INLINE ComputedStyleBase()
        : m_listStyleType(static_cast<unsigned>(EListStyleType::kDisc))
        , m_pointerEvents(static_cast<unsigned>(EPointerEvents::kAuto))
        , m_textAlign(static_cast<unsigned>(ETextAlign::kStart))
        , m_unicodeBidi(static_cast<unsigned>(UnicodeBidi::kNormal))
        , m_whiteSpace(static_cast<unsigned>(EWhiteSpace::kNormal))
        , m_captionSide(static_cast<unsigned>(ECaptionSide::kTop))
        , m_writingMode(static_cast<unsigned>(WritingMode::kHorizontalTb))
        , m_floating(static_cast<unsigned>(EFloat::kNone))
        , m_textTransform(static_cast<unsigned>(ETextTransform::kNone))
        , m_visibility(static_cast<unsigned>(EVisibility::kVisible))
        , m_boxDirectionIsInherited(static_cast<unsigned>(true))
        , m_boxDirection(static_cast<unsigned>(EBoxDirection::kNormal))
        , m_captionSideIsInherited(static_cast<unsigned>(true))
        , m_printColorAdjustIsInherited(static_cast<unsigned>(true))
        , m_printColorAdjust(static_cast<unsigned>(EPrintColorAdjust::kEconomy))
        , m_borderCollapseIsInherited(static_cast<unsigned>(true))
        , m_borderCollapse(static_cast<unsigned>(EBorderCollapse::kSeparate))
        , m_rtlOrderingIsInherited(static_cast<unsigned>(true))
        , m_rtlOrdering(static_cast<unsigned>(EOrder::kLogical))
        , m_whiteSpaceIsInherited(static_cast<unsigned>(true))
        , m_listStylePositionIsInherited(static_cast<unsigned>(true))
        , m_listStylePosition(static_cast<unsigned>(EListStylePosition::kOutside))
        , m_pointerEventsIsInherited(static_cast<unsigned>(true))
        , m_textTransformIsInherited(static_cast<unsigned>(true))
        , m_direction(static_cast<unsigned>(TextDirection::kLtr))
        , m_emptyCellsIsInherited(static_cast<unsigned>(true))
        , m_emptyCells(static_cast<unsigned>(EEmptyCells::kShow))
        , m_visibilityIsInherited(static_cast<unsigned>(true))
    {
    }
    ~ComputedStyleBase() { }

    ALWAYS_INLINE ComputedStyleBase(const ComputedStyleBase& o)
        : m_listStyleType(o.m_listStyleType)
        , m_pointerEvents(o.m_pointerEvents)
        , m_textAlign(o.m_textAlign)
        , m_unicodeBidi(o.m_unicodeBidi)
        , m_whiteSpace(o.m_whiteSpace)
        , m_captionSide(o.m_captionSide)
        , m_writingMode(o.m_writingMode)
        , m_floating(o.m_floating)
        , m_textTransform(o.m_textTransform)
        , m_visibility(o.m_visibility)
        , m_boxDirectionIsInherited(o.m_boxDirectionIsInherited)
        , m_boxDirection(o.m_boxDirection)
        , m_captionSideIsInherited(o.m_captionSideIsInherited)
        , m_printColorAdjustIsInherited(o.m_printColorAdjustIsInherited)
        , m_printColorAdjust(o.m_printColorAdjust)
        , m_borderCollapseIsInherited(o.m_borderCollapseIsInherited)
        , m_borderCollapse(o.m_borderCollapse)
        , m_rtlOrderingIsInherited(o.m_rtlOrderingIsInherited)
        , m_rtlOrdering(o.m_rtlOrdering)
        , m_whiteSpaceIsInherited(o.m_whiteSpaceIsInherited)
        , m_listStylePositionIsInherited(o.m_listStylePositionIsInherited)
        , m_listStylePosition(o.m_listStylePosition)
        , m_pointerEventsIsInherited(o.m_pointerEventsIsInherited)
        , m_textTransformIsInherited(o.m_textTransformIsInherited)
        , m_direction(o.m_direction)
        , m_emptyCellsIsInherited(o.m_emptyCellsIsInherited)
        , m_emptyCells(o.m_emptyCells)
        , m_visibilityIsInherited(o.m_visibilityIsInherited)
    {
    }

    bool operator==(const ComputedStyleBase& o) const
    {
        return true && m_listStyleType == o.m_listStyleType && m_pointerEvents == o.m_pointerEvents && m_textAlign == o.m_textAlign && m_unicodeBidi == o.m_unicodeBidi && m_whiteSpace == o.m_whiteSpace && m_captionSide == o.m_captionSide && m_writingMode == o.m_writingMode && m_floating == o.m_floating && m_textTransform == o.m_textTransform && m_visibility == o.m_visibility && m_boxDirectionIsInherited == o.m_boxDirectionIsInherited && m_boxDirection == o.m_boxDirection && m_captionSideIsInherited == o.m_captionSideIsInherited && m_printColorAdjustIsInherited == o.m_printColorAdjustIsInherited && m_printColorAdjust == o.m_printColorAdjust && m_borderCollapseIsInherited == o.m_borderCollapseIsInherited && m_borderCollapse == o.m_borderCollapse && m_rtlOrderingIsInherited == o.m_rtlOrderingIsInherited && m_rtlOrdering == o.m_rtlOrdering && m_whiteSpaceIsInherited == o.m_whiteSpaceIsInherited && m_listStylePositionIsInherited == o.m_listStylePositionIsInherited && m_listStylePosition == o.m_listStylePosition && m_pointerEventsIsInherited == o.m_pointerEventsIsInherited && m_textTransformIsInherited == o.m_textTransformIsInherited && m_direction == o.m_direction && m_emptyCellsIsInherited == o.m_emptyCellsIsInherited && m_emptyCells == o.m_emptyCells && m_visibilityIsInherited == o.m_visibilityIsInherited && true;
    }

    bool operator!=(const ComputedStyleBase& o) const { return !(*this == o); }

    inline bool inheritedEqual(const ComputedStyleBase& o) const
    {
        return true && m_listStyleType == o.m_listStyleType && m_pointerEvents == o.m_pointerEvents && m_textAlign == o.m_textAlign && m_whiteSpace == o.m_whiteSpace && m_captionSide == o.m_captionSide && m_writingMode == o.m_writingMode && m_textTransform == o.m_textTransform && m_visibility == o.m_visibility && m_boxDirection == o.m_boxDirection && m_printColorAdjust == o.m_printColorAdjust && m_borderCollapse == o.m_borderCollapse && m_rtlOrdering == o.m_rtlOrdering && m_listStylePosition == o.m_listStylePosition && m_direction == o.m_direction && m_emptyCells == o.m_emptyCells && true;
    }

    inline bool independentInheritedEqual(const ComputedStyleBase& o) const
    {
        return true && m_pointerEvents == o.m_pointerEvents && m_whiteSpace == o.m_whiteSpace && m_captionSide == o.m_captionSide && m_textTransform == o.m_textTransform && m_visibility == o.m_visibility && m_boxDirection == o.m_boxDirection && m_printColorAdjust == o.m_printColorAdjust && m_borderCollapse == o.m_borderCollapse && m_rtlOrdering == o.m_rtlOrdering && m_listStylePosition == o.m_listStylePosition && m_emptyCells == o.m_emptyCells && true;
    }

    inline bool nonIndependentInheritedEqual(const ComputedStyleBase& o) const
    {
        return true && m_listStyleType == o.m_listStyleType && m_textAlign == o.m_textAlign && m_writingMode == o.m_writingMode && m_direction == o.m_direction && true;
    }

    inline bool nonInheritedEqual(const ComputedStyleBase& o) const
    {
        return true && m_unicodeBidi == o.m_unicodeBidi && m_floating == o.m_floating && true;
    }

    void setBitDefaults()
    {
        resetListStyleType();
        resetPointerEvents();
        resetTextAlign();
        resetUnicodeBidi();
        resetWhiteSpace();
        resetCaptionSide();
        resetWritingMode();
        resetFloating();
        resetTextTransform();
        resetVisibility();
        resetBoxDirectionIsInherited();
        resetBoxDirection();
        resetCaptionSideIsInherited();
        resetPrintColorAdjustIsInherited();
        resetPrintColorAdjust();
        resetBorderCollapseIsInherited();
        resetBorderCollapse();
        resetRtlOrderingIsInherited();
        resetRtlOrdering();
        resetWhiteSpaceIsInherited();
        resetListStylePositionIsInherited();
        resetListStylePosition();
        resetPointerEventsIsInherited();
        resetTextTransformIsInherited();
        resetDirection();
        resetEmptyCellsIsInherited();
        resetEmptyCells();
        resetVisibilityIsInherited();
    }

    enum IsAtShadowBoundary {
        AtShadowBoundary,
        NotAtShadowBoundary,
    };
    void inheritFrom(const ComputedStyleBase& inheritParent,
        IsAtShadowBoundary isAtShadowBoundary = NotAtShadowBoundary);

    void copyNonInheritedFromCached(const ComputedStyleBase& other);

    // Copies the values of any independent inherited properties from the parent
    // style that are marked as inherited by this style.
    void propagateIndependentInheritedProperties(
        const ComputedStyleBase& parentStyle);

    // Fields.
    // TODO(sashab): Remove initialFoo() static methods and update callers to
    // use resetFoo(), which can be more efficient.
    // list-style-type
    inline static EListStyleType initialListStyleType() { return EListStyleType::kDisc; }
    EListStyleType listStyleType() const { return static_cast<EListStyleType>(m_listStyleType); }
    void setListStyleType(EListStyleType v) { m_listStyleType = static_cast<unsigned>(v); }
    inline void resetListStyleType() { m_listStyleType = static_cast<unsigned>(EListStyleType::kDisc); }

    // pointer-events
    inline static EPointerEvents initialPointerEvents() { return EPointerEvents::kAuto; }
    EPointerEvents pointerEvents() const { return static_cast<EPointerEvents>(m_pointerEvents); }
    void setPointerEvents(EPointerEvents v) { m_pointerEvents = static_cast<unsigned>(v); }
    inline void resetPointerEvents() { m_pointerEvents = static_cast<unsigned>(EPointerEvents::kAuto); }

    // text-align
    inline static ETextAlign initialTextAlign() { return ETextAlign::kStart; }
    ETextAlign textAlign() const { return static_cast<ETextAlign>(m_textAlign); }
    void setTextAlign(ETextAlign v) { m_textAlign = static_cast<unsigned>(v); }
    inline void resetTextAlign() { m_textAlign = static_cast<unsigned>(ETextAlign::kStart); }

    // unicode-bidi
    inline static UnicodeBidi initialUnicodeBidi() { return UnicodeBidi::kNormal; }
    UnicodeBidi getUnicodeBidi() const { return static_cast<UnicodeBidi>(m_unicodeBidi); }
    void setUnicodeBidi(UnicodeBidi v) { m_unicodeBidi = static_cast<unsigned>(v); }
    inline void resetUnicodeBidi() { m_unicodeBidi = static_cast<unsigned>(UnicodeBidi::kNormal); }

    // white-space
    inline static EWhiteSpace initialWhiteSpace() { return EWhiteSpace::kNormal; }
    EWhiteSpace whiteSpace() const { return static_cast<EWhiteSpace>(m_whiteSpace); }
    void setWhiteSpace(EWhiteSpace v) { m_whiteSpace = static_cast<unsigned>(v); }
    inline void resetWhiteSpace() { m_whiteSpace = static_cast<unsigned>(EWhiteSpace::kNormal); }

    // caption-side
    inline static ECaptionSide initialCaptionSide() { return ECaptionSide::kTop; }
    ECaptionSide captionSide() const { return static_cast<ECaptionSide>(m_captionSide); }
    void setCaptionSide(ECaptionSide v) { m_captionSide = static_cast<unsigned>(v); }
    inline void resetCaptionSide() { m_captionSide = static_cast<unsigned>(ECaptionSide::kTop); }

    // writing-mode
    inline static WritingMode initialWritingMode() { return WritingMode::kHorizontalTb; }
    WritingMode getWritingMode() const { return static_cast<WritingMode>(m_writingMode); }
    void setWritingMode(WritingMode v) { m_writingMode = static_cast<unsigned>(v); }
    inline void resetWritingMode() { m_writingMode = static_cast<unsigned>(WritingMode::kHorizontalTb); }

    // float
    inline static EFloat initialFloating() { return EFloat::kNone; }
    EFloat floating() const { return static_cast<EFloat>(m_floating); }
    void setFloating(EFloat v) { m_floating = static_cast<unsigned>(v); }
    inline void resetFloating() { m_floating = static_cast<unsigned>(EFloat::kNone); }

    // text-transform
    inline static ETextTransform initialTextTransform() { return ETextTransform::kNone; }
    ETextTransform textTransform() const { return static_cast<ETextTransform>(m_textTransform); }
    void setTextTransform(ETextTransform v) { m_textTransform = static_cast<unsigned>(v); }
    inline void resetTextTransform() { m_textTransform = static_cast<unsigned>(ETextTransform::kNone); }

    // visibility
    inline static EVisibility initialVisibility() { return EVisibility::kVisible; }
    EVisibility visibility() const { return static_cast<EVisibility>(m_visibility); }
    void setVisibility(EVisibility v) { m_visibility = static_cast<unsigned>(v); }
    inline void resetVisibility() { m_visibility = static_cast<unsigned>(EVisibility::kVisible); }

    // -webkit-box-direction
    inline static bool initialBoxDirectionIsInherited() { return true; }
    bool boxDirectionIsInherited() const { return static_cast<bool>(m_boxDirectionIsInherited); }
    void setBoxDirectionIsInherited(bool v) { m_boxDirectionIsInherited = static_cast<unsigned>(v); }
    inline void resetBoxDirectionIsInherited() { m_boxDirectionIsInherited = static_cast<unsigned>(true); }

    // -webkit-box-direction
    inline static EBoxDirection initialBoxDirection() { return EBoxDirection::kNormal; }
    EBoxDirection boxDirection() const { return static_cast<EBoxDirection>(m_boxDirection); }
    void setBoxDirection(EBoxDirection v) { m_boxDirection = static_cast<unsigned>(v); }
    inline void resetBoxDirection() { m_boxDirection = static_cast<unsigned>(EBoxDirection::kNormal); }

    // caption-side
    inline static bool initialCaptionSideIsInherited() { return true; }
    bool captionSideIsInherited() const { return static_cast<bool>(m_captionSideIsInherited); }
    void setCaptionSideIsInherited(bool v) { m_captionSideIsInherited = static_cast<unsigned>(v); }
    inline void resetCaptionSideIsInherited() { m_captionSideIsInherited = static_cast<unsigned>(true); }

    // -webkit-print-color-adjust
    inline static bool initialPrintColorAdjustIsInherited() { return true; }
    bool printColorAdjustIsInherited() const { return static_cast<bool>(m_printColorAdjustIsInherited); }
    void setPrintColorAdjustIsInherited(bool v) { m_printColorAdjustIsInherited = static_cast<unsigned>(v); }
    inline void resetPrintColorAdjustIsInherited() { m_printColorAdjustIsInherited = static_cast<unsigned>(true); }

    // -webkit-print-color-adjust
    inline static EPrintColorAdjust initialPrintColorAdjust() { return EPrintColorAdjust::kEconomy; }
    EPrintColorAdjust printColorAdjust() const { return static_cast<EPrintColorAdjust>(m_printColorAdjust); }
    void setPrintColorAdjust(EPrintColorAdjust v) { m_printColorAdjust = static_cast<unsigned>(v); }
    inline void resetPrintColorAdjust() { m_printColorAdjust = static_cast<unsigned>(EPrintColorAdjust::kEconomy); }

    // border-collapse
    inline static bool initialBorderCollapseIsInherited() { return true; }
    bool borderCollapseIsInherited() const { return static_cast<bool>(m_borderCollapseIsInherited); }
    void setBorderCollapseIsInherited(bool v) { m_borderCollapseIsInherited = static_cast<unsigned>(v); }
    inline void resetBorderCollapseIsInherited() { m_borderCollapseIsInherited = static_cast<unsigned>(true); }

    // border-collapse
    inline static EBorderCollapse initialBorderCollapse() { return EBorderCollapse::kSeparate; }
    EBorderCollapse borderCollapse() const { return static_cast<EBorderCollapse>(m_borderCollapse); }
    void setBorderCollapse(EBorderCollapse v) { m_borderCollapse = static_cast<unsigned>(v); }
    inline void resetBorderCollapse() { m_borderCollapse = static_cast<unsigned>(EBorderCollapse::kSeparate); }

    // -webkit-rtl-ordering
    inline static bool initialRtlOrderingIsInherited() { return true; }
    bool rtlOrderingIsInherited() const { return static_cast<bool>(m_rtlOrderingIsInherited); }
    void setRtlOrderingIsInherited(bool v) { m_rtlOrderingIsInherited = static_cast<unsigned>(v); }
    inline void resetRtlOrderingIsInherited() { m_rtlOrderingIsInherited = static_cast<unsigned>(true); }

    // -webkit-rtl-ordering
    inline static EOrder initialRtlOrdering() { return EOrder::kLogical; }
    EOrder rtlOrdering() const { return static_cast<EOrder>(m_rtlOrdering); }
    void setRtlOrdering(EOrder v) { m_rtlOrdering = static_cast<unsigned>(v); }
    inline void resetRtlOrdering() { m_rtlOrdering = static_cast<unsigned>(EOrder::kLogical); }

    // white-space
    inline static bool initialWhiteSpaceIsInherited() { return true; }
    bool whiteSpaceIsInherited() const { return static_cast<bool>(m_whiteSpaceIsInherited); }
    void setWhiteSpaceIsInherited(bool v) { m_whiteSpaceIsInherited = static_cast<unsigned>(v); }
    inline void resetWhiteSpaceIsInherited() { m_whiteSpaceIsInherited = static_cast<unsigned>(true); }

    // list-style-position
    inline static bool initialListStylePositionIsInherited() { return true; }
    bool listStylePositionIsInherited() const { return static_cast<bool>(m_listStylePositionIsInherited); }
    void setListStylePositionIsInherited(bool v) { m_listStylePositionIsInherited = static_cast<unsigned>(v); }
    inline void resetListStylePositionIsInherited() { m_listStylePositionIsInherited = static_cast<unsigned>(true); }

    // list-style-position
    inline static EListStylePosition initialListStylePosition() { return EListStylePosition::kOutside; }
    EListStylePosition listStylePosition() const { return static_cast<EListStylePosition>(m_listStylePosition); }
    void setListStylePosition(EListStylePosition v) { m_listStylePosition = static_cast<unsigned>(v); }
    inline void resetListStylePosition() { m_listStylePosition = static_cast<unsigned>(EListStylePosition::kOutside); }

    // pointer-events
    inline static bool initialPointerEventsIsInherited() { return true; }
    bool pointerEventsIsInherited() const { return static_cast<bool>(m_pointerEventsIsInherited); }
    void setPointerEventsIsInherited(bool v) { m_pointerEventsIsInherited = static_cast<unsigned>(v); }
    inline void resetPointerEventsIsInherited() { m_pointerEventsIsInherited = static_cast<unsigned>(true); }

    // text-transform
    inline static bool initialTextTransformIsInherited() { return true; }
    bool textTransformIsInherited() const { return static_cast<bool>(m_textTransformIsInherited); }
    void setTextTransformIsInherited(bool v) { m_textTransformIsInherited = static_cast<unsigned>(v); }
    inline void resetTextTransformIsInherited() { m_textTransformIsInherited = static_cast<unsigned>(true); }

    // direction
    inline static TextDirection initialDirection() { return TextDirection::kLtr; }
    TextDirection direction() const { return static_cast<TextDirection>(m_direction); }
    void setDirection(TextDirection v) { m_direction = static_cast<unsigned>(v); }
    inline void resetDirection() { m_direction = static_cast<unsigned>(TextDirection::kLtr); }

    // empty-cells
    inline static bool initialEmptyCellsIsInherited() { return true; }
    bool emptyCellsIsInherited() const { return static_cast<bool>(m_emptyCellsIsInherited); }
    void setEmptyCellsIsInherited(bool v) { m_emptyCellsIsInherited = static_cast<unsigned>(v); }
    inline void resetEmptyCellsIsInherited() { m_emptyCellsIsInherited = static_cast<unsigned>(true); }

    // empty-cells
    inline static EEmptyCells initialEmptyCells() { return EEmptyCells::kShow; }
    EEmptyCells emptyCells() const { return static_cast<EEmptyCells>(m_emptyCells); }
    void setEmptyCells(EEmptyCells v) { m_emptyCells = static_cast<unsigned>(v); }
    inline void resetEmptyCells() { m_emptyCells = static_cast<unsigned>(EEmptyCells::kShow); }

    // visibility
    inline static bool initialVisibilityIsInherited() { return true; }
    bool visibilityIsInherited() const { return static_cast<bool>(m_visibilityIsInherited); }
    void setVisibilityIsInherited(bool v) { m_visibilityIsInherited = static_cast<unsigned>(v); }
    inline void resetVisibilityIsInherited() { m_visibilityIsInherited = static_cast<unsigned>(true); }

protected:
    // Storage.
    unsigned m_listStyleType : 6; // EListStyleType
    unsigned m_pointerEvents : 4; // EPointerEvents
    unsigned m_textAlign : 4; // ETextAlign
    unsigned m_unicodeBidi : 3; // UnicodeBidi
    unsigned m_whiteSpace : 3; // EWhiteSpace
    unsigned m_captionSide : 2; // ECaptionSide
    unsigned m_writingMode : 2; // WritingMode
    unsigned m_floating : 2; // EFloat
    unsigned m_textTransform : 2; // ETextTransform
    unsigned m_visibility : 2; // EVisibility
    unsigned m_boxDirectionIsInherited : 1; // bool
    unsigned m_boxDirection : 1; // EBoxDirection
    unsigned m_captionSideIsInherited : 1; // bool
    unsigned m_printColorAdjustIsInherited : 1; // bool
    unsigned m_printColorAdjust : 1; // EPrintColorAdjust
    unsigned m_borderCollapseIsInherited : 1; // bool
    unsigned m_borderCollapse : 1; // EBorderCollapse
    unsigned m_rtlOrderingIsInherited : 1; // bool
    unsigned m_rtlOrdering : 1; // EOrder
    unsigned m_whiteSpaceIsInherited : 1; // bool
    unsigned m_listStylePositionIsInherited : 1; // bool
    unsigned m_listStylePosition : 1; // EListStylePosition
    unsigned m_pointerEventsIsInherited : 1; // bool
    unsigned m_textTransformIsInherited : 1; // bool
    unsigned m_direction : 1; // TextDirection
    unsigned m_emptyCellsIsInherited : 1; // bool
    unsigned m_emptyCells : 1; // EEmptyCells
    unsigned m_visibilityIsInherited : 1; // bool
};

} // namespace blink

#endif // ComputedStyleBase_h
