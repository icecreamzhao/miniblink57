// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/graphics/paint/DisplayItem.h"

namespace blink {

struct SameSizeAsDisplayItem {
    virtual ~SameSizeAsDisplayItem() { } // Allocate vtable pointer.
<<<<<<< HEAD
    void* pointer;
    int i;
=======
    void* pointers[2];
    int ints[2]; // Make sure other fields are packed into two ints.
>>>>>>> miniblink49
#ifndef NDEBUG
    WTF::String m_debugString;
#endif
};
<<<<<<< HEAD
static_assert(sizeof(DisplayItem) == sizeof(SameSizeAsDisplayItem),
    "DisplayItem should stay small");
=======
static_assert(sizeof(DisplayItem) == sizeof(SameSizeAsDisplayItem), "DisplayItem should stay small");
>>>>>>> miniblink49

#ifndef NDEBUG

static WTF::String paintPhaseAsDebugString(int paintPhase)
{
    // Must be kept in sync with PaintPhase.
    switch (paintPhase) {
<<<<<<< HEAD
    case 0:
        return "PaintPhaseBlockBackground";
    case 1:
        return "PaintPhaseSelfBlockBackground";
    case 2:
        return "PaintPhaseChildBlockBackgrounds";
    case 3:
        return "PaintPhaseFloat";
    case 4:
        return "PaintPhaseForeground";
    case 5:
        return "PaintPhaseOutline";
    case 6:
        return "PaintPhaseSelfOutline";
    case 7:
        return "PaintPhaseChildOutlines";
    case 8:
        return "PaintPhaseSelection";
    case 9:
        return "PaintPhaseTextClip";
    case 10:
        return "PaintPhaseMask";
    case DisplayItem::kPaintPhaseMax:
        return "PaintPhaseClippingMask";
=======
    case 0: return "PaintPhaseBlockBackground";
    case 1: return "PaintPhaseChildBlockBackground";
    case 2: return "PaintPhaseChildBlockBackgrounds";
    case 3: return "PaintPhaseFloat";
    case 4: return "PaintPhaseForeground";
    case 5: return "PaintPhaseOutline";
    case 6: return "PaintPhaseChildOutlines";
    case 7: return "PaintPhaseSelfOutline";
    case 8: return "PaintPhaseSelection";
    case 9: return "PaintPhaseCollapsedTableBorders";
    case 10: return "PaintPhaseTextClip";
    case 11: return "PaintPhaseMask";
    case DisplayItem::PaintPhaseMax: return "PaintPhaseClippingMask";
>>>>>>> miniblink49
    default:
        ASSERT_NOT_REACHED();
        return "Unknown";
    }
}

<<<<<<< HEAD
#define PAINT_PHASE_BASED_DEBUG_STRINGS(Category)                                                              \
    if (type >= DisplayItem::k##Category##PaintPhaseFirst && type <= DisplayItem::k##Category##PaintPhaseLast) \
        return #Category + paintPhaseAsDebugString(type - DisplayItem::k##Category##PaintPhaseFirst);

#define DEBUG_STRING_CASE(DisplayItemName) \
    case DisplayItem::k##DisplayItemName:  \
        return #DisplayItemName

#define DEFAULT_CASE          \
    default:                  \
        ASSERT_NOT_REACHED(); \
        return "Unknown"

static WTF::String specialDrawingTypeAsDebugString(DisplayItem::Type type)
{
    if (type >= DisplayItem::kTableCollapsedBorderUnalignedBase) {
        if (type <= DisplayItem::kTableCollapsedBorderBase)
            return "TableCollapsedBorderAlignment";
        if (type <= DisplayItem::kTableCollapsedBorderLast) {
            StringBuilder sb;
            sb.append("TableCollapsedBorder");
            if (type & DisplayItem::TableCollapsedBorderTop)
                sb.append("Top");
            if (type & DisplayItem::TableCollapsedBorderRight)
                sb.append("Right");
            if (type & DisplayItem::TableCollapsedBorderBottom)
                sb.append("Bottom");
            if (type & DisplayItem::TableCollapsedBorderLeft)
                sb.append("Left");
            return sb.toString();
        }
    }
=======
#define PAINT_PHASE_BASED_DEBUG_STRINGS(Category) \
    if (type >= DisplayItem::Category##PaintPhaseFirst && type <= DisplayItem::Category##PaintPhaseLast) \
        return #Category + paintPhaseAsDebugString(type - DisplayItem::Category##PaintPhaseFirst);

#define DEBUG_STRING_CASE(DisplayItemName) \
    case DisplayItem::DisplayItemName: return #DisplayItemName

#define DEFAULT_CASE default: ASSERT_NOT_REACHED(); return "Unknown"

static WTF::String specialDrawingTypeAsDebugString(DisplayItem::Type type)
{
>>>>>>> miniblink49
    switch (type) {
        DEBUG_STRING_CASE(BoxDecorationBackground);
        DEBUG_STRING_CASE(Caret);
        DEBUG_STRING_CASE(ColumnRules);
<<<<<<< HEAD
        DEBUG_STRING_CASE(DebugDrawing);
        DEBUG_STRING_CASE(DocumentBackground);
        DEBUG_STRING_CASE(DragImage);
        DEBUG_STRING_CASE(DragCaret);
        DEBUG_STRING_CASE(SVGImage);
        DEBUG_STRING_CASE(LinkHighlight);
        DEBUG_STRING_CASE(ImageAreaFocusRing);
=======
        DEBUG_STRING_CASE(DebugRedFill);
        DEBUG_STRING_CASE(DragImage);
        DEBUG_STRING_CASE(SVGImage);
        DEBUG_STRING_CASE(LinkHighlight);
>>>>>>> miniblink49
        DEBUG_STRING_CASE(PageOverlay);
        DEBUG_STRING_CASE(PageWidgetDelegateBackgroundFallback);
        DEBUG_STRING_CASE(PopupContainerBorder);
        DEBUG_STRING_CASE(PopupListBoxBackground);
        DEBUG_STRING_CASE(PopupListBoxRow);
        DEBUG_STRING_CASE(PrintedContentBackground);
<<<<<<< HEAD
        DEBUG_STRING_CASE(PrintedContentDestinationLocations);
=======
>>>>>>> miniblink49
        DEBUG_STRING_CASE(PrintedContentLineBoundary);
        DEBUG_STRING_CASE(PrintedContentPDFURLRect);
        DEBUG_STRING_CASE(Resizer);
        DEBUG_STRING_CASE(SVGClip);
        DEBUG_STRING_CASE(SVGFilter);
        DEBUG_STRING_CASE(SVGMask);
        DEBUG_STRING_CASE(ScrollbarBackButtonEnd);
        DEBUG_STRING_CASE(ScrollbarBackButtonStart);
        DEBUG_STRING_CASE(ScrollbarBackground);
        DEBUG_STRING_CASE(ScrollbarBackTrack);
        DEBUG_STRING_CASE(ScrollbarCorner);
        DEBUG_STRING_CASE(ScrollbarForwardButtonEnd);
        DEBUG_STRING_CASE(ScrollbarForwardButtonStart);
        DEBUG_STRING_CASE(ScrollbarForwardTrack);
<<<<<<< HEAD
        DEBUG_STRING_CASE(ScrollbarThumb);
        DEBUG_STRING_CASE(ScrollbarTickmarks);
        DEBUG_STRING_CASE(ScrollbarTrackBackground);
        DEBUG_STRING_CASE(ScrollbarCompositedScrollbar);
        DEBUG_STRING_CASE(SelectionTint);
        DEBUG_STRING_CASE(TableCellBackgroundFromColumnGroup);
        DEBUG_STRING_CASE(TableCellBackgroundFromColumn);
        DEBUG_STRING_CASE(TableCellBackgroundFromSection);
        DEBUG_STRING_CASE(TableCellBackgroundFromRow);
        DEBUG_STRING_CASE(TableSectionBoxShadowInset);
        DEBUG_STRING_CASE(TableSectionBoxShadowNormal);
        DEBUG_STRING_CASE(TableRowBoxShadowInset);
        DEBUG_STRING_CASE(TableRowBoxShadowNormal);
        DEBUG_STRING_CASE(VideoBitmap);
        DEBUG_STRING_CASE(WebPlugin);
        DEBUG_STRING_CASE(WebFont);
        DEBUG_STRING_CASE(ReflectionMask);
=======
        DEBUG_STRING_CASE(ScrollbarHorizontal);
        DEBUG_STRING_CASE(ScrollbarThumb);
        DEBUG_STRING_CASE(ScrollbarTickmarks);
        DEBUG_STRING_CASE(ScrollbarTrackBackground);
        DEBUG_STRING_CASE(ScrollbarVertical);
        DEBUG_STRING_CASE(SelectionGap);
        DEBUG_STRING_CASE(SelectionTint);
        DEBUG_STRING_CASE(TableCellBackgroundFromSelfPaintingRow);
        DEBUG_STRING_CASE(VideoBitmap);
        DEBUG_STRING_CASE(WebPlugin);
        DEBUG_STRING_CASE(WebFont);
>>>>>>> miniblink49

        DEFAULT_CASE;
    }
}

static WTF::String drawingTypeAsDebugString(DisplayItem::Type type)
{
    PAINT_PHASE_BASED_DEBUG_STRINGS(Drawing);
    return "Drawing" + specialDrawingTypeAsDebugString(type);
}

<<<<<<< HEAD
static String foreignLayerTypeAsDebugString(DisplayItem::Type type)
{
    switch (type) {
        DEBUG_STRING_CASE(ForeignLayerCanvas);
        DEBUG_STRING_CASE(ForeignLayerPlugin);
        DEBUG_STRING_CASE(ForeignLayerVideo);
        DEFAULT_CASE;
    }
}

=======
>>>>>>> miniblink49
static WTF::String clipTypeAsDebugString(DisplayItem::Type type)
{
    PAINT_PHASE_BASED_DEBUG_STRINGS(ClipBox);
    PAINT_PHASE_BASED_DEBUG_STRINGS(ClipColumnBounds);
    PAINT_PHASE_BASED_DEBUG_STRINGS(ClipLayerFragment);

    switch (type) {
        DEBUG_STRING_CASE(ClipFileUploadControlRect);
        DEBUG_STRING_CASE(ClipFrameToVisibleContentRect);
        DEBUG_STRING_CASE(ClipFrameScrollbars);
        DEBUG_STRING_CASE(ClipLayerBackground);
        DEBUG_STRING_CASE(ClipLayerColumnBounds);
        DEBUG_STRING_CASE(ClipLayerFilter);
        DEBUG_STRING_CASE(ClipLayerForeground);
        DEBUG_STRING_CASE(ClipLayerParent);
        DEBUG_STRING_CASE(ClipLayerOverflowControls);
        DEBUG_STRING_CASE(ClipNodeImage);
        DEBUG_STRING_CASE(ClipPopupListBoxFrame);
<<<<<<< HEAD
        DEBUG_STRING_CASE(ClipScrollbarsToBoxBounds);
        DEBUG_STRING_CASE(ClipSelectionImage);
        DEBUG_STRING_CASE(PageWidgetDelegateClip);
=======
        DEBUG_STRING_CASE(ClipSelectionImage);
        DEBUG_STRING_CASE(PageWidgetDelegateClip);
        DEBUG_STRING_CASE(TransparencyClip);
>>>>>>> miniblink49
        DEBUG_STRING_CASE(ClipPrintedPage);
        DEFAULT_CASE;
    }
}

<<<<<<< HEAD
static String scrollTypeAsDebugString(DisplayItem::Type type)
{
    PAINT_PHASE_BASED_DEBUG_STRINGS(Scroll);
    switch (type) {
        DEBUG_STRING_CASE(ScrollOverflowControls);
        DEFAULT_CASE;
    }
}

=======
>>>>>>> miniblink49
static String transform3DTypeAsDebugString(DisplayItem::Type type)
{
    switch (type) {
        DEBUG_STRING_CASE(Transform3DElementTransform);
        DEFAULT_CASE;
    }
}

WTF::String DisplayItem::typeAsDebugString(Type type)
{
    if (isDrawingType(type))
        return drawingTypeAsDebugString(type);
<<<<<<< HEAD

    if (isForeignLayerType(type))
        return foreignLayerTypeAsDebugString(type);

=======
    if (isCachedType(type))
        return "Cached" + drawingTypeAsDebugString(cachedTypeToDrawingType(type));
>>>>>>> miniblink49
    if (isClipType(type))
        return clipTypeAsDebugString(type);
    if (isEndClipType(type))
        return "End" + clipTypeAsDebugString(endClipTypeToClipType(type));

<<<<<<< HEAD
=======
    if (type == UninitializedType)
        return "UninitializedType";

>>>>>>> miniblink49
    PAINT_PHASE_BASED_DEBUG_STRINGS(FloatClip);
    if (isEndFloatClipType(type))
        return "End" + typeAsDebugString(endFloatClipTypeToFloatClipType(type));

<<<<<<< HEAD
    if (isScrollType(type))
        return scrollTypeAsDebugString(type);
    if (isEndScrollType(type))
        return "End" + scrollTypeAsDebugString(endScrollTypeToScrollType(type));
=======
    PAINT_PHASE_BASED_DEBUG_STRINGS(Scroll);
    if (isEndScrollType(type))
        return "End" + typeAsDebugString(endScrollTypeToScrollType(type));
>>>>>>> miniblink49

    if (isTransform3DType(type))
        return transform3DTypeAsDebugString(type);
    if (isEndTransform3DType(type))
        return "End" + transform3DTypeAsDebugString(endTransform3DTypeToTransform3DType(type));

<<<<<<< HEAD
=======
    PAINT_PHASE_BASED_DEBUG_STRINGS(SubtreeCached);
    PAINT_PHASE_BASED_DEBUG_STRINGS(BeginSubtree);
    PAINT_PHASE_BASED_DEBUG_STRINGS(EndSubtree);

    if (type == UninitializedType)
        return "UninitializedType";

>>>>>>> miniblink49
    switch (type) {
        DEBUG_STRING_CASE(BeginFilter);
        DEBUG_STRING_CASE(EndFilter);
        DEBUG_STRING_CASE(BeginCompositing);
        DEBUG_STRING_CASE(EndCompositing);
        DEBUG_STRING_CASE(BeginTransform);
        DEBUG_STRING_CASE(EndTransform);
        DEBUG_STRING_CASE(BeginClipPath);
        DEBUG_STRING_CASE(EndClipPath);
<<<<<<< HEAD
        DEBUG_STRING_CASE(Subsequence);
        DEBUG_STRING_CASE(EndSubsequence);
        DEBUG_STRING_CASE(UninitializedType);
=======
        DEBUG_STRING_CASE(BeginFixedPosition);
        DEBUG_STRING_CASE(EndFixedPosition);
        DEBUG_STRING_CASE(BeginFixedPositionContainer);
        DEBUG_STRING_CASE(EndFixedPositionContainer);
>>>>>>> miniblink49
        DEFAULT_CASE;
    }
}

WTF::String DisplayItem::asDebugString() const
{
    WTF::StringBuilder stringBuilder;
    stringBuilder.append('{');
    dumpPropertiesAsDebugString(stringBuilder);
    stringBuilder.append('}');
    return stringBuilder.toString();
}

<<<<<<< HEAD
void DisplayItem::dumpPropertiesAsDebugString(
    WTF::StringBuilder& stringBuilder) const
{
    if (!hasValidClient()) {
        stringBuilder.append("validClient: false, originalDebugString: ");
        // This is the original debug string which is in json format.
        stringBuilder.append(clientDebugString());
        return;
    }

    stringBuilder.append(String::format("client: \"%p", &client()));
=======
void DisplayItem::dumpPropertiesAsDebugString(WTF::StringBuilder& stringBuilder) const
{
    stringBuilder.append(String::format("client: \"%p", client()));
>>>>>>> miniblink49
    if (!clientDebugString().isEmpty()) {
        stringBuilder.append(' ');
        stringBuilder.append(clientDebugString());
    }
    stringBuilder.append("\", type: \"");
<<<<<<< HEAD
    stringBuilder.append(typeAsDebugString(getType()));
    stringBuilder.append('"');
    if (m_skippedCache)
        stringBuilder.append(", skippedCache: true");
=======
    stringBuilder.append(typeAsDebugString(type()));
    stringBuilder.append('"');
    if (m_skippedCache)
        stringBuilder.append(", skippedCache: true");
    if (m_scopeContainer)
        stringBuilder.append(String::format(", scope: \"%p,%d\"", m_scopeContainer, m_scopeId));
>>>>>>> miniblink49
}

#endif

} // namespace blink
