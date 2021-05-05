/*
 * (C) 1999-2003 Lars Knoll (knoll@kde.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2013 Intel Corporation. All rights reserved.
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

#include "StylePropertyShorthand.h"

#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/HashMap.h"
#include "wtf/StdLibExtras.h"

namespace blink {

const StylePropertyShorthand& backgroundRepeatShorthand()
{
    static const CSSPropertyID backgroundRepeatProperties[] = {
        CSSPropertyBackgroundRepeatX,
        CSSPropertyBackgroundRepeatY,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, backgroundRepeatLonghands, (CSSPropertyBackgroundRepeat, backgroundRepeatProperties, WTF_ARRAY_LENGTH(backgroundRepeatProperties)));
    return backgroundRepeatLonghands;
}

const StylePropertyShorthand& flexShorthand()
{
    static const CSSPropertyID flexProperties[] = {
        CSSPropertyFlexGrow,
        CSSPropertyFlexShrink,
        CSSPropertyFlexBasis,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, flexLonghands, (CSSPropertyFlex, flexProperties, WTF_ARRAY_LENGTH(flexProperties)));
    return flexLonghands;
}

const StylePropertyShorthand& markerShorthand()
{
    static const CSSPropertyID markerProperties[] = {
        CSSPropertyMarkerStart,
        CSSPropertyMarkerMid,
        CSSPropertyMarkerEnd,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, markerLonghands, (CSSPropertyMarker, markerProperties, WTF_ARRAY_LENGTH(markerProperties)));
    return markerLonghands;
}

const StylePropertyShorthand& flexFlowShorthand()
{
    static const CSSPropertyID flexFlowProperties[] = {
        CSSPropertyFlexDirection,
        CSSPropertyFlexWrap,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, flexFlowLonghands, (CSSPropertyFlexFlow, flexFlowProperties, WTF_ARRAY_LENGTH(flexFlowProperties)));
    return flexFlowLonghands;
}

const StylePropertyShorthand& borderRightShorthand()
{
    static const CSSPropertyID borderRightProperties[] = {
        CSSPropertyBorderRightWidth,
        CSSPropertyBorderRightStyle,
        CSSPropertyBorderRightColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderRightLonghands, (CSSPropertyBorderRight, borderRightProperties, WTF_ARRAY_LENGTH(borderRightProperties)));
    return borderRightLonghands;
}

const StylePropertyShorthand& outlineShorthand()
{
    static const CSSPropertyID outlineProperties[] = {
        CSSPropertyOutlineColor,
        CSSPropertyOutlineStyle,
        CSSPropertyOutlineWidth,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, outlineLonghands, (CSSPropertyOutline, outlineProperties, WTF_ARRAY_LENGTH(outlineProperties)));
    return outlineLonghands;
}

const StylePropertyShorthand& overflowShorthand()
{
    static const CSSPropertyID overflowProperties[] = {
        CSSPropertyOverflowX,
        CSSPropertyOverflowY,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, overflowLonghands, (CSSPropertyOverflow, overflowProperties, WTF_ARRAY_LENGTH(overflowProperties)));
    return overflowLonghands;
}

const StylePropertyShorthand& webkitTextStrokeShorthand()
{
    static const CSSPropertyID webkitTextStrokeProperties[] = {
        CSSPropertyWebkitTextStrokeWidth,
        CSSPropertyWebkitTextStrokeColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitTextStrokeLonghands, (CSSPropertyWebkitTextStroke, webkitTextStrokeProperties, WTF_ARRAY_LENGTH(webkitTextStrokeProperties)));
    return webkitTextStrokeLonghands;
}

const StylePropertyShorthand& pageBreakInsideShorthand()
{
    static const CSSPropertyID pageBreakInsideProperties[] = {
        CSSPropertyBreakInside,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, pageBreakInsideLonghands, (CSSPropertyPageBreakInside, pageBreakInsideProperties, WTF_ARRAY_LENGTH(pageBreakInsideProperties)));
    return pageBreakInsideLonghands;
}

const StylePropertyShorthand& listStyleShorthand()
{
    static const CSSPropertyID listStyleProperties[] = {
        CSSPropertyListStyleType,
        CSSPropertyListStylePosition,
        CSSPropertyListStyleImage,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, listStyleLonghands, (CSSPropertyListStyle, listStyleProperties, WTF_ARRAY_LENGTH(listStyleProperties)));
    return listStyleLonghands;
}

const StylePropertyShorthand& borderStyleShorthand()
{
    static const CSSPropertyID borderStyleProperties[] = {
        CSSPropertyBorderTopStyle,
        CSSPropertyBorderRightStyle,
        CSSPropertyBorderBottomStyle,
        CSSPropertyBorderLeftStyle,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderStyleLonghands, (CSSPropertyBorderStyle, borderStyleProperties, WTF_ARRAY_LENGTH(borderStyleProperties)));
    return borderStyleLonghands;
}

const StylePropertyShorthand& webkitMarginCollapseShorthand()
{
    static const CSSPropertyID webkitMarginCollapseProperties[] = {
        CSSPropertyWebkitMarginBeforeCollapse,
        CSSPropertyWebkitMarginAfterCollapse,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitMarginCollapseLonghands, (CSSPropertyWebkitMarginCollapse, webkitMarginCollapseProperties, WTF_ARRAY_LENGTH(webkitMarginCollapseProperties)));
    return webkitMarginCollapseLonghands;
}

const StylePropertyShorthand& marginShorthand()
{
    static const CSSPropertyID marginProperties[] = {
        CSSPropertyMarginTop,
        CSSPropertyMarginRight,
        CSSPropertyMarginBottom,
        CSSPropertyMarginLeft,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, marginLonghands, (CSSPropertyMargin, marginProperties, WTF_ARRAY_LENGTH(marginProperties)));
    return marginLonghands;
}

const StylePropertyShorthand& pageBreakBeforeShorthand()
{
    static const CSSPropertyID pageBreakBeforeProperties[] = {
        CSSPropertyBreakBefore,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, pageBreakBeforeLonghands, (CSSPropertyPageBreakBefore, pageBreakBeforeProperties, WTF_ARRAY_LENGTH(pageBreakBeforeProperties)));
    return pageBreakBeforeLonghands;
}

const StylePropertyShorthand& borderSpacingShorthand()
{
    static const CSSPropertyID borderSpacingProperties[] = {
        CSSPropertyWebkitBorderHorizontalSpacing,
        CSSPropertyWebkitBorderVerticalSpacing,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderSpacingLonghands, (CSSPropertyBorderSpacing, borderSpacingProperties, WTF_ARRAY_LENGTH(borderSpacingProperties)));
    return borderSpacingLonghands;
}

const StylePropertyShorthand& textDecorationShorthand()
{
    static const CSSPropertyID textDecorationProperties[] = {
        CSSPropertyTextDecorationLine,
        CSSPropertyTextDecorationStyle,
        CSSPropertyTextDecorationColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, textDecorationLonghands, (CSSPropertyTextDecoration, textDecorationProperties, WTF_ARRAY_LENGTH(textDecorationProperties)));
    return textDecorationLonghands;
}

const StylePropertyShorthand& gridGapShorthand()
{
    static const CSSPropertyID gridGapProperties[] = {
        CSSPropertyGridRowGap,
        CSSPropertyGridColumnGap,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, gridGapLonghands, (CSSPropertyGridGap, gridGapProperties, WTF_ARRAY_LENGTH(gridGapProperties)));
    return gridGapLonghands;
}

const StylePropertyShorthand& backgroundShorthand()
{
    static const CSSPropertyID backgroundProperties[] = {
        CSSPropertyBackgroundImage,
        CSSPropertyBackgroundPositionX,
        CSSPropertyBackgroundPositionY,
        CSSPropertyBackgroundSize,
        CSSPropertyBackgroundRepeatX,
        CSSPropertyBackgroundRepeatY,
        CSSPropertyBackgroundAttachment,
        CSSPropertyBackgroundOrigin,
        CSSPropertyBackgroundClip,
        CSSPropertyBackgroundColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, backgroundLonghands, (CSSPropertyBackground, backgroundProperties, WTF_ARRAY_LENGTH(backgroundProperties)));
    return backgroundLonghands;
}

const StylePropertyShorthand& webkitMaskRepeatShorthand()
{
    static const CSSPropertyID webkitMaskRepeatProperties[] = {
        CSSPropertyWebkitMaskRepeatX,
        CSSPropertyWebkitMaskRepeatY,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitMaskRepeatLonghands, (CSSPropertyWebkitMaskRepeat, webkitMaskRepeatProperties, WTF_ARRAY_LENGTH(webkitMaskRepeatProperties)));
    return webkitMaskRepeatLonghands;
}

const StylePropertyShorthand& columnRuleShorthand()
{
    static const CSSPropertyID columnRuleProperties[] = {
        CSSPropertyColumnRuleWidth,
        CSSPropertyColumnRuleStyle,
        CSSPropertyColumnRuleColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, columnRuleLonghands, (CSSPropertyColumnRule, columnRuleProperties, WTF_ARRAY_LENGTH(columnRuleProperties)));
    return columnRuleLonghands;
}

const StylePropertyShorthand& gridShorthand()
{
    static const CSSPropertyID gridProperties[] = {
        CSSPropertyGridTemplateRows,
        CSSPropertyGridTemplateColumns,
        CSSPropertyGridTemplateAreas,
        CSSPropertyGridAutoFlow,
        CSSPropertyGridAutoRows,
        CSSPropertyGridAutoColumns,
        CSSPropertyGridColumnGap,
        CSSPropertyGridRowGap,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, gridLonghands, (CSSPropertyGrid, gridProperties, WTF_ARRAY_LENGTH(gridProperties)));
    return gridLonghands;
}

const StylePropertyShorthand& webkitBorderEndShorthand()
{
    static const CSSPropertyID webkitBorderEndProperties[] = {
        CSSPropertyWebkitBorderEndWidth,
        CSSPropertyWebkitBorderEndStyle,
        CSSPropertyWebkitBorderEndColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitBorderEndLonghands, (CSSPropertyWebkitBorderEnd, webkitBorderEndProperties, WTF_ARRAY_LENGTH(webkitBorderEndProperties)));
    return webkitBorderEndLonghands;
}

const StylePropertyShorthand& borderTopShorthand()
{
    static const CSSPropertyID borderTopProperties[] = {
        CSSPropertyBorderTopWidth,
        CSSPropertyBorderTopStyle,
        CSSPropertyBorderTopColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderTopLonghands, (CSSPropertyBorderTop, borderTopProperties, WTF_ARRAY_LENGTH(borderTopProperties)));
    return borderTopLonghands;
}

const StylePropertyShorthand& webkitColumnBreakAfterShorthand()
{
    static const CSSPropertyID webkitColumnBreakAfterProperties[] = {
        CSSPropertyBreakAfter,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitColumnBreakAfterLonghands, (CSSPropertyWebkitColumnBreakAfter, webkitColumnBreakAfterProperties, WTF_ARRAY_LENGTH(webkitColumnBreakAfterProperties)));
    return webkitColumnBreakAfterLonghands;
}

const StylePropertyShorthand& webkitBorderAfterShorthand()
{
    static const CSSPropertyID webkitBorderAfterProperties[] = {
        CSSPropertyWebkitBorderAfterWidth,
        CSSPropertyWebkitBorderAfterStyle,
        CSSPropertyWebkitBorderAfterColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitBorderAfterLonghands, (CSSPropertyWebkitBorderAfter, webkitBorderAfterProperties, WTF_ARRAY_LENGTH(webkitBorderAfterProperties)));
    return webkitBorderAfterLonghands;
}

const StylePropertyShorthand& gridAreaShorthand()
{
    static const CSSPropertyID gridAreaProperties[] = {
        CSSPropertyGridRowStart,
        CSSPropertyGridColumnStart,
        CSSPropertyGridRowEnd,
        CSSPropertyGridColumnEnd,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, gridAreaLonghands, (CSSPropertyGridArea, gridAreaProperties, WTF_ARRAY_LENGTH(gridAreaProperties)));
    return gridAreaLonghands;
}

const StylePropertyShorthand& fontShorthand()
{
    static const CSSPropertyID fontProperties[] = {
        CSSPropertyFontStyle,
        CSSPropertyFontVariantLigatures,
        CSSPropertyFontVariantCaps,
        CSSPropertyFontVariantNumeric,
        CSSPropertyFontWeight,
        CSSPropertyFontStretch,
        CSSPropertyFontSize,
        CSSPropertyLineHeight,
        CSSPropertyFontFamily,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, fontLonghands, (CSSPropertyFont, fontProperties, WTF_ARRAY_LENGTH(fontProperties)));
    return fontLonghands;
}

const StylePropertyShorthand& transitionShorthand()
{
    static const CSSPropertyID transitionProperties[] = {
        CSSPropertyTransitionProperty,
        CSSPropertyTransitionDuration,
        CSSPropertyTransitionTimingFunction,
        CSSPropertyTransitionDelay,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, transitionLonghands, (CSSPropertyTransition, transitionProperties, WTF_ARRAY_LENGTH(transitionProperties)));
    return transitionLonghands;
}

const StylePropertyShorthand& animationShorthand()
{
    static const CSSPropertyID animationProperties[] = {
        CSSPropertyAnimationName,
        CSSPropertyAnimationDuration,
        CSSPropertyAnimationTimingFunction,
        CSSPropertyAnimationDelay,
        CSSPropertyAnimationIterationCount,
        CSSPropertyAnimationDirection,
        CSSPropertyAnimationFillMode,
        CSSPropertyAnimationPlayState,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, animationLonghands, (CSSPropertyAnimation, animationProperties, WTF_ARRAY_LENGTH(animationProperties)));
    return animationLonghands;
}

const StylePropertyShorthand& webkitBorderBeforeShorthand()
{
    static const CSSPropertyID webkitBorderBeforeProperties[] = {
        CSSPropertyWebkitBorderBeforeWidth,
        CSSPropertyWebkitBorderBeforeStyle,
        CSSPropertyWebkitBorderBeforeColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitBorderBeforeLonghands, (CSSPropertyWebkitBorderBefore, webkitBorderBeforeProperties, WTF_ARRAY_LENGTH(webkitBorderBeforeProperties)));
    return webkitBorderBeforeLonghands;
}

const StylePropertyShorthand& columnsShorthand()
{
    static const CSSPropertyID columnsProperties[] = {
        CSSPropertyColumnWidth,
        CSSPropertyColumnCount,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, columnsLonghands, (CSSPropertyColumns, columnsProperties, WTF_ARRAY_LENGTH(columnsProperties)));
    return columnsLonghands;
}

const StylePropertyShorthand& fontVariantShorthand()
{
    static const CSSPropertyID fontVariantProperties[] = {
        CSSPropertyFontVariantLigatures,
        CSSPropertyFontVariantCaps,
        CSSPropertyFontVariantNumeric,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, fontVariantLonghands, (CSSPropertyFontVariant, fontVariantProperties, WTF_ARRAY_LENGTH(fontVariantProperties)));
    return fontVariantLonghands;
}

const StylePropertyShorthand& paddingShorthand()
{
    static const CSSPropertyID paddingProperties[] = {
        CSSPropertyPaddingTop,
        CSSPropertyPaddingRight,
        CSSPropertyPaddingBottom,
        CSSPropertyPaddingLeft,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, paddingLonghands, (CSSPropertyPadding, paddingProperties, WTF_ARRAY_LENGTH(paddingProperties)));
    return paddingLonghands;
}

const StylePropertyShorthand& webkitMaskPositionShorthand()
{
    static const CSSPropertyID webkitMaskPositionProperties[] = {
        CSSPropertyWebkitMaskPositionX,
        CSSPropertyWebkitMaskPositionY,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitMaskPositionLonghands, (CSSPropertyWebkitMaskPosition, webkitMaskPositionProperties, WTF_ARRAY_LENGTH(webkitMaskPositionProperties)));
    return webkitMaskPositionLonghands;
}

const StylePropertyShorthand& borderLeftShorthand()
{
    static const CSSPropertyID borderLeftProperties[] = {
        CSSPropertyBorderLeftWidth,
        CSSPropertyBorderLeftStyle,
        CSSPropertyBorderLeftColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderLeftLonghands, (CSSPropertyBorderLeft, borderLeftProperties, WTF_ARRAY_LENGTH(borderLeftProperties)));
    return borderLeftLonghands;
}

const StylePropertyShorthand& webkitMaskShorthand()
{
    static const CSSPropertyID webkitMaskProperties[] = {
        CSSPropertyWebkitMaskImage,
        CSSPropertyWebkitMaskPositionX,
        CSSPropertyWebkitMaskPositionY,
        CSSPropertyWebkitMaskSize,
        CSSPropertyWebkitMaskRepeatX,
        CSSPropertyWebkitMaskRepeatY,
        CSSPropertyWebkitMaskOrigin,
        CSSPropertyWebkitMaskClip,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitMaskLonghands, (CSSPropertyWebkitMask, webkitMaskProperties, WTF_ARRAY_LENGTH(webkitMaskProperties)));
    return webkitMaskLonghands;
}

const StylePropertyShorthand& gridColumnShorthand()
{
    static const CSSPropertyID gridColumnProperties[] = {
        CSSPropertyGridColumnStart,
        CSSPropertyGridColumnEnd,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, gridColumnLonghands, (CSSPropertyGridColumn, gridColumnProperties, WTF_ARRAY_LENGTH(gridColumnProperties)));
    return gridColumnLonghands;
}

const StylePropertyShorthand& webkitBorderStartShorthand()
{
    static const CSSPropertyID webkitBorderStartProperties[] = {
        CSSPropertyWebkitBorderStartWidth,
        CSSPropertyWebkitBorderStartStyle,
        CSSPropertyWebkitBorderStartColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitBorderStartLonghands, (CSSPropertyWebkitBorderStart, webkitBorderStartProperties, WTF_ARRAY_LENGTH(webkitBorderStartProperties)));
    return webkitBorderStartLonghands;
}

const StylePropertyShorthand& offsetShorthand()
{
    static const CSSPropertyID offsetProperties[] = {
        CSSPropertyOffsetPath,
        CSSPropertyOffsetDistance,
        CSSPropertyOffsetRotation,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, offsetLonghands, (CSSPropertyOffset, offsetProperties, WTF_ARRAY_LENGTH(offsetProperties)));
    return offsetLonghands;
}

const StylePropertyShorthand& borderColorShorthand()
{
    static const CSSPropertyID borderColorProperties[] = {
        CSSPropertyBorderTopColor,
        CSSPropertyBorderRightColor,
        CSSPropertyBorderBottomColor,
        CSSPropertyBorderLeftColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderColorLonghands, (CSSPropertyBorderColor, borderColorProperties, WTF_ARRAY_LENGTH(borderColorProperties)));
    return borderColorLonghands;
}

const StylePropertyShorthand& webkitColumnBreakBeforeShorthand()
{
    static const CSSPropertyID webkitColumnBreakBeforeProperties[] = {
        CSSPropertyBreakBefore,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitColumnBreakBeforeLonghands, (CSSPropertyWebkitColumnBreakBefore, webkitColumnBreakBeforeProperties, WTF_ARRAY_LENGTH(webkitColumnBreakBeforeProperties)));
    return webkitColumnBreakBeforeLonghands;
}

const StylePropertyShorthand& webkitColumnBreakInsideShorthand()
{
    static const CSSPropertyID webkitColumnBreakInsideProperties[] = {
        CSSPropertyBreakInside,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitColumnBreakInsideLonghands, (CSSPropertyWebkitColumnBreakInside, webkitColumnBreakInsideProperties, WTF_ARRAY_LENGTH(webkitColumnBreakInsideProperties)));
    return webkitColumnBreakInsideLonghands;
}

const StylePropertyShorthand& borderWidthShorthand()
{
    static const CSSPropertyID borderWidthProperties[] = {
        CSSPropertyBorderTopWidth,
        CSSPropertyBorderRightWidth,
        CSSPropertyBorderBottomWidth,
        CSSPropertyBorderLeftWidth,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderWidthLonghands, (CSSPropertyBorderWidth, borderWidthProperties, WTF_ARRAY_LENGTH(borderWidthProperties)));
    return borderWidthLonghands;
}

const StylePropertyShorthand& gridTemplateShorthand()
{
    static const CSSPropertyID gridTemplateProperties[] = {
        CSSPropertyGridTemplateRows,
        CSSPropertyGridTemplateColumns,
        CSSPropertyGridTemplateAreas,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, gridTemplateLonghands, (CSSPropertyGridTemplate, gridTemplateProperties, WTF_ARRAY_LENGTH(gridTemplateProperties)));
    return gridTemplateLonghands;
}

const StylePropertyShorthand& motionShorthand()
{
    static const CSSPropertyID motionProperties[] = {
        CSSPropertyOffsetPath,
        CSSPropertyOffsetDistance,
        CSSPropertyOffsetRotation,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, motionLonghands, (CSSPropertyMotion, motionProperties, WTF_ARRAY_LENGTH(motionProperties)));
    return motionLonghands;
}

const StylePropertyShorthand& backgroundPositionShorthand()
{
    static const CSSPropertyID backgroundPositionProperties[] = {
        CSSPropertyBackgroundPositionX,
        CSSPropertyBackgroundPositionY,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, backgroundPositionLonghands, (CSSPropertyBackgroundPosition, backgroundPositionProperties, WTF_ARRAY_LENGTH(backgroundPositionProperties)));
    return backgroundPositionLonghands;
}

const StylePropertyShorthand& borderShorthand()
{
    static const CSSPropertyID borderProperties[] = {
        CSSPropertyBorderTopColor,
        CSSPropertyBorderTopStyle,
        CSSPropertyBorderTopWidth,
        CSSPropertyBorderRightColor,
        CSSPropertyBorderRightStyle,
        CSSPropertyBorderRightWidth,
        CSSPropertyBorderBottomColor,
        CSSPropertyBorderBottomStyle,
        CSSPropertyBorderBottomWidth,
        CSSPropertyBorderLeftColor,
        CSSPropertyBorderLeftStyle,
        CSSPropertyBorderLeftWidth,
        CSSPropertyBorderImageSource,
        CSSPropertyBorderImageSlice,
        CSSPropertyBorderImageWidth,
        CSSPropertyBorderImageOutset,
        CSSPropertyBorderImageRepeat,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderLonghands, (CSSPropertyBorder, borderProperties, WTF_ARRAY_LENGTH(borderProperties)));
    return borderLonghands;
}

const StylePropertyShorthand& borderBottomShorthand()
{
    static const CSSPropertyID borderBottomProperties[] = {
        CSSPropertyBorderBottomWidth,
        CSSPropertyBorderBottomStyle,
        CSSPropertyBorderBottomColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderBottomLonghands, (CSSPropertyBorderBottom, borderBottomProperties, WTF_ARRAY_LENGTH(borderBottomProperties)));
    return borderBottomLonghands;
}

const StylePropertyShorthand& gridRowShorthand()
{
    static const CSSPropertyID gridRowProperties[] = {
        CSSPropertyGridRowStart,
        CSSPropertyGridRowEnd,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, gridRowLonghands, (CSSPropertyGridRow, gridRowProperties, WTF_ARRAY_LENGTH(gridRowProperties)));
    return gridRowLonghands;
}

const StylePropertyShorthand& pageBreakAfterShorthand()
{
    static const CSSPropertyID pageBreakAfterProperties[] = {
        CSSPropertyBreakAfter,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, pageBreakAfterLonghands, (CSSPropertyPageBreakAfter, pageBreakAfterProperties, WTF_ARRAY_LENGTH(pageBreakAfterProperties)));
    return pageBreakAfterLonghands;
}

const StylePropertyShorthand& borderRadiusShorthand()
{
    static const CSSPropertyID borderRadiusProperties[] = {
        CSSPropertyBorderTopLeftRadius,
        CSSPropertyBorderTopRightRadius,
        CSSPropertyBorderBottomRightRadius,
        CSSPropertyBorderBottomLeftRadius,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderRadiusLonghands, (CSSPropertyBorderRadius, borderRadiusProperties, WTF_ARRAY_LENGTH(borderRadiusProperties)));
    return borderRadiusLonghands;
}

const StylePropertyShorthand& webkitTextEmphasisShorthand()
{
    static const CSSPropertyID webkitTextEmphasisProperties[] = {
        CSSPropertyWebkitTextEmphasisStyle,
        CSSPropertyWebkitTextEmphasisColor,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitTextEmphasisLonghands, (CSSPropertyWebkitTextEmphasis, webkitTextEmphasisProperties, WTF_ARRAY_LENGTH(webkitTextEmphasisProperties)));
    return webkitTextEmphasisLonghands;
}

const StylePropertyShorthand& webkitMaskBoxImageShorthand()
{
    static const CSSPropertyID webkitMaskBoxImageProperties[] = {
        CSSPropertyWebkitMaskBoxImageSource,
        CSSPropertyWebkitMaskBoxImageSlice,
        CSSPropertyWebkitMaskBoxImageWidth,
        CSSPropertyWebkitMaskBoxImageOutset,
        CSSPropertyWebkitMaskBoxImageRepeat,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, webkitMaskBoxImageLonghands, (CSSPropertyWebkitMaskBoxImage, webkitMaskBoxImageProperties, WTF_ARRAY_LENGTH(webkitMaskBoxImageProperties)));
    return webkitMaskBoxImageLonghands;
}

const StylePropertyShorthand& borderImageShorthand()
{
    static const CSSPropertyID borderImageProperties[] = {
        CSSPropertyBorderImageSource,
        CSSPropertyBorderImageSlice,
        CSSPropertyBorderImageWidth,
        CSSPropertyBorderImageOutset,
        CSSPropertyBorderImageRepeat,
    };
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, borderImageLonghands, (CSSPropertyBorderImage, borderImageProperties, WTF_ARRAY_LENGTH(borderImageProperties)));
    return borderImageLonghands;
}

// Returns an empty list if the property is not a shorthand
const StylePropertyShorthand& shorthandForProperty(CSSPropertyID propertyID)
{
    DEFINE_STATIC_LOCAL(StylePropertyShorthand, emptyShorthand, ());
    if (propertyID == CSSPropertyTextDecoration && !RuntimeEnabledFeatures::css3TextDecorationsEnabled())
        return emptyShorthand;
    switch (propertyID) {
    case CSSPropertyBackgroundRepeat:
        return backgroundRepeatShorthand();
    case CSSPropertyFlex:
        return flexShorthand();
    case CSSPropertyMarker:
        return markerShorthand();
    case CSSPropertyFlexFlow:
        return flexFlowShorthand();
    case CSSPropertyBorderRight:
        return borderRightShorthand();
    case CSSPropertyOutline:
        return outlineShorthand();
    case CSSPropertyOverflow:
        return overflowShorthand();
    case CSSPropertyWebkitTextStroke:
        return webkitTextStrokeShorthand();
    case CSSPropertyPageBreakInside:
        return pageBreakInsideShorthand();
    case CSSPropertyListStyle:
        return listStyleShorthand();
    case CSSPropertyBorderStyle:
        return borderStyleShorthand();
    case CSSPropertyWebkitMarginCollapse:
        return webkitMarginCollapseShorthand();
    case CSSPropertyMargin:
        return marginShorthand();
    case CSSPropertyPageBreakBefore:
        return pageBreakBeforeShorthand();
    case CSSPropertyBorderSpacing:
        return borderSpacingShorthand();
    case CSSPropertyTextDecoration:
        return textDecorationShorthand();
    case CSSPropertyGridGap:
        return gridGapShorthand();
    case CSSPropertyBackground:
        return backgroundShorthand();
    case CSSPropertyWebkitMaskRepeat:
        return webkitMaskRepeatShorthand();
    case CSSPropertyColumnRule:
        return columnRuleShorthand();
    case CSSPropertyGrid:
        return gridShorthand();
    case CSSPropertyWebkitBorderEnd:
        return webkitBorderEndShorthand();
    case CSSPropertyBorderTop:
        return borderTopShorthand();
    case CSSPropertyWebkitColumnBreakAfter:
        return webkitColumnBreakAfterShorthand();
    case CSSPropertyWebkitBorderAfter:
        return webkitBorderAfterShorthand();
    case CSSPropertyGridArea:
        return gridAreaShorthand();
    case CSSPropertyFont:
        return fontShorthand();
    case CSSPropertyTransition:
        return transitionShorthand();
    case CSSPropertyAnimation:
        return animationShorthand();
    case CSSPropertyWebkitBorderBefore:
        return webkitBorderBeforeShorthand();
    case CSSPropertyColumns:
        return columnsShorthand();
    case CSSPropertyFontVariant:
        return fontVariantShorthand();
    case CSSPropertyPadding:
        return paddingShorthand();
    case CSSPropertyWebkitMaskPosition:
        return webkitMaskPositionShorthand();
    case CSSPropertyBorderLeft:
        return borderLeftShorthand();
    case CSSPropertyWebkitMask:
        return webkitMaskShorthand();
    case CSSPropertyGridColumn:
        return gridColumnShorthand();
    case CSSPropertyWebkitBorderStart:
        return webkitBorderStartShorthand();
    case CSSPropertyOffset:
        return offsetShorthand();
    case CSSPropertyBorderColor:
        return borderColorShorthand();
    case CSSPropertyWebkitColumnBreakBefore:
        return webkitColumnBreakBeforeShorthand();
    case CSSPropertyWebkitColumnBreakInside:
        return webkitColumnBreakInsideShorthand();
    case CSSPropertyBorderWidth:
        return borderWidthShorthand();
    case CSSPropertyGridTemplate:
        return gridTemplateShorthand();
    case CSSPropertyMotion:
        return motionShorthand();
    case CSSPropertyBackgroundPosition:
        return backgroundPositionShorthand();
    case CSSPropertyBorder:
        return borderShorthand();
    case CSSPropertyBorderBottom:
        return borderBottomShorthand();
    case CSSPropertyGridRow:
        return gridRowShorthand();
    case CSSPropertyPageBreakAfter:
        return pageBreakAfterShorthand();
    case CSSPropertyBorderRadius:
        return borderRadiusShorthand();
    case CSSPropertyWebkitTextEmphasis:
        return webkitTextEmphasisShorthand();
    case CSSPropertyWebkitMaskBoxImage:
        return webkitMaskBoxImageShorthand();
    case CSSPropertyBorderImage:
        return borderImageShorthand();
    default: {
        return emptyShorthand;
    }
    }
}

void getMatchingShorthandsForLonghand(
    CSSPropertyID propertyID, Vector<StylePropertyShorthand, 4>* result)
{
    ASSERT(!result->size());
    switch (propertyID) {
    case CSSPropertyWebkitMaskBoxImageWidth: {
        result->uncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyWebkitMaskBoxImageRepeat: {
        result->uncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyWebkitBorderEndColor: {
        result->uncheckedAppend(webkitBorderEndShorthand());
        break;
    }
    case CSSPropertyFlexWrap: {
        result->uncheckedAppend(flexFlowShorthand());
        break;
    }
    case CSSPropertyWebkitBorderHorizontalSpacing: {
        result->uncheckedAppend(borderSpacingShorthand());
        break;
    }
    case CSSPropertyWebkitBorderEndWidth: {
        result->uncheckedAppend(webkitBorderEndShorthand());
        break;
    }
    case CSSPropertyFlexBasis: {
        result->uncheckedAppend(flexShorthand());
        break;
    }
    case CSSPropertyBorderLeftColor: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderColorShorthand());
        result->uncheckedAppend(borderLeftShorthand());
        break;
    }
    case CSSPropertyColumnCount: {
        result->uncheckedAppend(columnsShorthand());
        break;
    }
    case CSSPropertyWebkitBorderBeforeStyle: {
        result->uncheckedAppend(webkitBorderBeforeShorthand());
        break;
    }
    case CSSPropertyFontStretch: {
        result->uncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyWebkitBorderStartColor: {
        result->uncheckedAppend(webkitBorderStartShorthand());
        break;
    }
    case CSSPropertyFlexShrink: {
        result->uncheckedAppend(flexShorthand());
        break;
    }
    case CSSPropertyTransitionDelay: {
        result->uncheckedAppend(transitionShorthand());
        break;
    }
    case CSSPropertyGridTemplateRows: {
        result->uncheckedAppend(gridShorthand());
        result->uncheckedAppend(gridTemplateShorthand());
        break;
    }
    case CSSPropertyBackgroundClip: {
        result->uncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyWebkitBorderEndStyle: {
        result->uncheckedAppend(webkitBorderEndShorthand());
        break;
    }
    case CSSPropertyTextDecorationColor: {
        result->uncheckedAppend(textDecorationShorthand());
        break;
    }
    case CSSPropertyAnimationName: {
        result->uncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyBackgroundPositionY: {
        result->uncheckedAppend(backgroundShorthand());
        result->uncheckedAppend(backgroundPositionShorthand());
        break;
    }
    case CSSPropertyBackgroundPositionX: {
        result->uncheckedAppend(backgroundShorthand());
        result->uncheckedAppend(backgroundPositionShorthand());
        break;
    }
    case CSSPropertyWebkitMarginAfterCollapse: {
        result->uncheckedAppend(webkitMarginCollapseShorthand());
        break;
    }
    case CSSPropertyOutlineWidth: {
        result->uncheckedAppend(outlineShorthand());
        break;
    }
    case CSSPropertyColumnWidth: {
        result->uncheckedAppend(columnsShorthand());
        break;
    }
    case CSSPropertyColumnRuleWidth: {
        result->uncheckedAppend(columnRuleShorthand());
        break;
    }
    case CSSPropertyWebkitMaskOrigin: {
        result->uncheckedAppend(webkitMaskShorthand());
        break;
    }
    case CSSPropertyBreakAfter: {
        result->uncheckedAppend(webkitColumnBreakAfterShorthand());
        result->uncheckedAppend(pageBreakAfterShorthand());
        break;
    }
    case CSSPropertyOutlineStyle: {
        result->uncheckedAppend(outlineShorthand());
        break;
    }
    case CSSPropertyGridAutoFlow: {
        result->uncheckedAppend(gridShorthand());
        break;
    }
    case CSSPropertyMarkerEnd: {
        result->uncheckedAppend(markerShorthand());
        break;
    }
    case CSSPropertyBackgroundOrigin: {
        result->uncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyBorderRightColor: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderColorShorthand());
        result->uncheckedAppend(borderRightShorthand());
        break;
    }
    case CSSPropertyAnimationDuration: {
        result->uncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyAnimationPlayState: {
        result->uncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyOffsetRotation: {
        result->uncheckedAppend(motionShorthand());
        result->uncheckedAppend(offsetShorthand());
        break;
    }
    case CSSPropertyFontVariantNumeric: {
        result->uncheckedAppend(fontShorthand());
        result->uncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyBorderBottomStyle: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderStyleShorthand());
        result->uncheckedAppend(borderBottomShorthand());
        break;
    }
    case CSSPropertyBorderBottomWidth: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderWidthShorthand());
        result->uncheckedAppend(borderBottomShorthand());
        break;
    }
    case CSSPropertyBorderTopRightRadius: {
        result->uncheckedAppend(borderRadiusShorthand());
        break;
    }
    case CSSPropertyGridRowGap: {
        result->uncheckedAppend(gridShorthand());
        result->uncheckedAppend(gridGapShorthand());
        break;
    }
    case CSSPropertyFontStyle: {
        result->uncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyBorderTopLeftRadius: {
        result->uncheckedAppend(borderRadiusShorthand());
        break;
    }
    case CSSPropertyBorderBottomRightRadius: {
        result->uncheckedAppend(borderRadiusShorthand());
        break;
    }
    case CSSPropertyBorderRightWidth: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderWidthShorthand());
        result->uncheckedAppend(borderRightShorthand());
        break;
    }
    case CSSPropertyWebkitBorderAfterStyle: {
        result->uncheckedAppend(webkitBorderAfterShorthand());
        break;
    }
    case CSSPropertyBorderImageSource: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyBorderRightStyle: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderStyleShorthand());
        result->uncheckedAppend(borderRightShorthand());
        break;
    }
    case CSSPropertyBorderBottomLeftRadius: {
        result->uncheckedAppend(borderRadiusShorthand());
        break;
    }
    case CSSPropertyGridRowEnd: {
        result->uncheckedAppend(gridAreaShorthand());
        result->uncheckedAppend(gridRowShorthand());
        break;
    }
    case CSSPropertyBackgroundAttachment: {
        result->uncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyWebkitMaskBoxImageOutset: {
        result->uncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyBorderLeftWidth: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderWidthShorthand());
        result->uncheckedAppend(borderLeftShorthand());
        break;
    }
    case CSSPropertyPaddingBottom: {
        result->uncheckedAppend(paddingShorthand());
        break;
    }
    case CSSPropertyWebkitMaskPositionX: {
        result->uncheckedAppend(webkitMaskShorthand());
        result->uncheckedAppend(webkitMaskPositionShorthand());
        break;
    }
    case CSSPropertyMarkerStart: {
        result->uncheckedAppend(markerShorthand());
        break;
    }
    case CSSPropertyBackgroundImage: {
        result->uncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyWebkitBorderAfterColor: {
        result->uncheckedAppend(webkitBorderAfterShorthand());
        break;
    }
    case CSSPropertyTextDecorationLine: {
        result->uncheckedAppend(textDecorationShorthand());
        break;
    }
    case CSSPropertyWebkitMaskClip: {
        result->uncheckedAppend(webkitMaskShorthand());
        break;
    }
    case CSSPropertyTextDecorationStyle: {
        result->uncheckedAppend(textDecorationShorthand());
        break;
    }
    case CSSPropertyColumnRuleStyle: {
        result->uncheckedAppend(columnRuleShorthand());
        break;
    }
    case CSSPropertyOffsetPath: {
        result->uncheckedAppend(motionShorthand());
        result->uncheckedAppend(offsetShorthand());
        break;
    }
    case CSSPropertyBorderImageSlice: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyWebkitBorderAfterWidth: {
        result->uncheckedAppend(webkitBorderAfterShorthand());
        break;
    }
    case CSSPropertyBreakInside: {
        result->uncheckedAppend(webkitColumnBreakInsideShorthand());
        result->uncheckedAppend(pageBreakInsideShorthand());
        break;
    }
    case CSSPropertyBorderTopColor: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderColorShorthand());
        result->uncheckedAppend(borderTopShorthand());
        break;
    }
    case CSSPropertyBackgroundColor: {
        result->uncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyOutlineColor: {
        result->uncheckedAppend(outlineShorthand());
        break;
    }
    case CSSPropertyPaddingTop: {
        result->uncheckedAppend(paddingShorthand());
        break;
    }
    case CSSPropertyBorderTopWidth: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderWidthShorthand());
        result->uncheckedAppend(borderTopShorthand());
        break;
    }
    case CSSPropertyGridColumnStart: {
        result->uncheckedAppend(gridAreaShorthand());
        result->uncheckedAppend(gridColumnShorthand());
        break;
    }
    case CSSPropertyMarginBottom: {
        result->uncheckedAppend(marginShorthand());
        break;
    }
    case CSSPropertyListStylePosition: {
        result->uncheckedAppend(listStyleShorthand());
        break;
    }
    case CSSPropertyAnimationIterationCount: {
        result->uncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyWebkitTextEmphasisColor: {
        result->uncheckedAppend(webkitTextEmphasisShorthand());
        break;
    }
    case CSSPropertyWebkitTextEmphasisStyle: {
        result->uncheckedAppend(webkitTextEmphasisShorthand());
        break;
    }
    case CSSPropertyWebkitMaskPositionY: {
        result->uncheckedAppend(webkitMaskShorthand());
        result->uncheckedAppend(webkitMaskPositionShorthand());
        break;
    }
    case CSSPropertyWebkitMaskSize: {
        result->uncheckedAppend(webkitMaskShorthand());
        break;
    }
    case CSSPropertyGridAutoRows: {
        result->uncheckedAppend(gridShorthand());
        break;
    }
    case CSSPropertyMarginTop: {
        result->uncheckedAppend(marginShorthand());
        break;
    }
    case CSSPropertyBorderTopStyle: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderStyleShorthand());
        result->uncheckedAppend(borderTopShorthand());
        break;
    }
    case CSSPropertyBreakBefore: {
        result->uncheckedAppend(webkitColumnBreakBeforeShorthand());
        result->uncheckedAppend(pageBreakBeforeShorthand());
        break;
    }
    case CSSPropertyWebkitBorderBeforeWidth: {
        result->uncheckedAppend(webkitBorderBeforeShorthand());
        break;
    }
    case CSSPropertyBorderImageOutset: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyFontFamily: {
        result->uncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyBorderImageWidth: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyWebkitMaskBoxImageSource: {
        result->uncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyFlexGrow: {
        result->uncheckedAppend(flexShorthand());
        break;
    }
    case CSSPropertyWebkitBorderBeforeColor: {
        result->uncheckedAppend(webkitBorderBeforeShorthand());
        break;
    }
    case CSSPropertyListStyleImage: {
        result->uncheckedAppend(listStyleShorthand());
        break;
    }
    case CSSPropertyWebkitMarginBeforeCollapse: {
        result->uncheckedAppend(webkitMarginCollapseShorthand());
        break;
    }
    case CSSPropertyWebkitMaskImage: {
        result->uncheckedAppend(webkitMaskShorthand());
        break;
    }
    case CSSPropertyAnimationTimingFunction: {
        result->uncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyFontVariantCaps: {
        result->uncheckedAppend(fontShorthand());
        result->uncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyFlexDirection: {
        result->uncheckedAppend(flexFlowShorthand());
        break;
    }
    case CSSPropertyWebkitMaskRepeatY: {
        result->uncheckedAppend(webkitMaskShorthand());
        result->uncheckedAppend(webkitMaskRepeatShorthand());
        break;
    }
    case CSSPropertyWebkitMaskRepeatX: {
        result->uncheckedAppend(webkitMaskShorthand());
        result->uncheckedAppend(webkitMaskRepeatShorthand());
        break;
    }
    case CSSPropertyGridTemplateAreas: {
        result->uncheckedAppend(gridShorthand());
        result->uncheckedAppend(gridTemplateShorthand());
        break;
    }
    case CSSPropertyBorderImageRepeat: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyWebkitBorderStartStyle: {
        result->uncheckedAppend(webkitBorderStartShorthand());
        break;
    }
    case CSSPropertyListStyleType: {
        result->uncheckedAppend(listStyleShorthand());
        break;
    }
    case CSSPropertyOverflowX: {
        result->uncheckedAppend(overflowShorthand());
        break;
    }
    case CSSPropertyFontWeight: {
        result->uncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyTransitionTimingFunction: {
        result->uncheckedAppend(transitionShorthand());
        break;
    }
    case CSSPropertyBorderLeftStyle: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderStyleShorthand());
        result->uncheckedAppend(borderLeftShorthand());
        break;
    }
    case CSSPropertyOverflowY: {
        result->uncheckedAppend(overflowShorthand());
        break;
    }
    case CSSPropertyColumnRuleColor: {
        result->uncheckedAppend(columnRuleShorthand());
        break;
    }
    case CSSPropertyMarkerMid: {
        result->uncheckedAppend(markerShorthand());
        break;
    }
    case CSSPropertyMarginRight: {
        result->uncheckedAppend(marginShorthand());
        break;
    }
    case CSSPropertyWebkitBorderStartWidth: {
        result->uncheckedAppend(webkitBorderStartShorthand());
        break;
    }
    case CSSPropertyAnimationDelay: {
        result->uncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyAnimationFillMode: {
        result->uncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyFontVariantLigatures: {
        result->uncheckedAppend(fontShorthand());
        result->uncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyGridColumnGap: {
        result->uncheckedAppend(gridShorthand());
        result->uncheckedAppend(gridGapShorthand());
        break;
    }
    case CSSPropertyOffsetDistance: {
        result->uncheckedAppend(motionShorthand());
        result->uncheckedAppend(offsetShorthand());
        break;
    }
    case CSSPropertyGridTemplateColumns: {
        result->uncheckedAppend(gridShorthand());
        result->uncheckedAppend(gridTemplateShorthand());
        break;
    }
    case CSSPropertyAnimationDirection: {
        result->uncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyWebkitMaskBoxImageSlice: {
        result->uncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyWebkitTextStrokeColor: {
        result->uncheckedAppend(webkitTextStrokeShorthand());
        break;
    }
    case CSSPropertyLineHeight: {
        result->uncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyPaddingLeft: {
        result->uncheckedAppend(paddingShorthand());
        break;
    }
    case CSSPropertyBackgroundRepeatY: {
        result->uncheckedAppend(backgroundShorthand());
        result->uncheckedAppend(backgroundRepeatShorthand());
        break;
    }
    case CSSPropertyBackgroundRepeatX: {
        result->uncheckedAppend(backgroundShorthand());
        result->uncheckedAppend(backgroundRepeatShorthand());
        break;
    }
    case CSSPropertyBorderBottomColor: {
        result->uncheckedAppend(borderShorthand());
        result->uncheckedAppend(borderColorShorthand());
        result->uncheckedAppend(borderBottomShorthand());
        break;
    }
    case CSSPropertyFontSize: {
        result->uncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyGridColumnEnd: {
        result->uncheckedAppend(gridAreaShorthand());
        result->uncheckedAppend(gridColumnShorthand());
        break;
    }
    case CSSPropertyBackgroundSize: {
        result->uncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyPaddingRight: {
        result->uncheckedAppend(paddingShorthand());
        break;
    }
    case CSSPropertyWebkitBorderVerticalSpacing: {
        result->uncheckedAppend(borderSpacingShorthand());
        break;
    }
    case CSSPropertyGridAutoColumns: {
        result->uncheckedAppend(gridShorthand());
        break;
    }
    case CSSPropertyGridRowStart: {
        result->uncheckedAppend(gridAreaShorthand());
        result->uncheckedAppend(gridRowShorthand());
        break;
    }
    case CSSPropertyTransitionDuration: {
        result->uncheckedAppend(transitionShorthand());
        break;
    }
    case CSSPropertyTransitionProperty: {
        result->uncheckedAppend(transitionShorthand());
        break;
    }
    case CSSPropertyMarginLeft: {
        result->uncheckedAppend(marginShorthand());
        break;
    }
    case CSSPropertyWebkitTextStrokeWidth: {
        result->uncheckedAppend(webkitTextStrokeShorthand());
        break;
    }
    default:
        break;
    }
}

} // namespace blink
