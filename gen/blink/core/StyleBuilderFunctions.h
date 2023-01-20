// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef StyleBuilderFunctions_h
#define StyleBuilderFunctions_h

#include "core/css/resolver/StyleBuilderConverter.h"

namespace blink {

class CSSValue;
class StyleResolverState;

class StyleBuilderFunctions {
public:
    static void applyInitialCSSPropertyWebkitMaskBoxImageWidth(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskBoxImageWidth(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskBoxImageWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertySize(StyleResolverState&);
    static void applyInheritCSSPropertySize(StyleResolverState&);
    static void applyValueCSSPropertySize(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyVectorEffect(StyleResolverState&);
    static void applyInheritCSSPropertyVectorEffect(StyleResolverState&);
    static void applyValueCSSPropertyVectorEffect(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFillRule(StyleResolverState&);
    static void applyInheritCSSPropertyFillRule(StyleResolverState&);
    static void applyValueCSSPropertyFillRule(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontVariantNumeric(StyleResolverState&);
    static void applyInheritCSSPropertyFontVariantNumeric(StyleResolverState&);
    static void applyValueCSSPropertyFontVariantNumeric(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyCx(StyleResolverState&);
    static void applyInheritCSSPropertyCx(StyleResolverState&);
    static void applyValueCSSPropertyCx(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyCy(StyleResolverState&);
    static void applyInheritCSSPropertyCy(StyleResolverState&);
    static void applyValueCSSPropertyCy(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTransitionDelay(StyleResolverState&);
    static void applyInheritCSSPropertyTransitionDelay(StyleResolverState&);
    static void applyValueCSSPropertyTransitionDelay(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyShapeOutside(StyleResolverState&);
    static void applyInheritCSSPropertyShapeOutside(StyleResolverState&);
    static void applyValueCSSPropertyShapeOutside(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextDecorationColor(StyleResolverState&);
    static void applyInheritCSSPropertyTextDecorationColor(StyleResolverState&);
    static void applyValueCSSPropertyTextDecorationColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAnimationName(StyleResolverState&);
    static void applyInheritCSSPropertyAnimationName(StyleResolverState&);
    static void applyValueCSSPropertyAnimationName(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitHyphenateCharacter(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitHyphenateCharacter(StyleResolverState&);
    static void applyValueCSSPropertyWebkitHyphenateCharacter(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxPack(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxPack(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxPack(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMarginBottomCollapse(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMarginBottomCollapse(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMarginBottomCollapse(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOutlineWidth(StyleResolverState&);
    static void applyInheritCSSPropertyOutlineWidth(StyleResolverState&);
    static void applyValueCSSPropertyOutlineWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColumnRuleWidth(StyleResolverState&);
    static void applyInheritCSSPropertyColumnRuleWidth(StyleResolverState&);
    static void applyValueCSSPropertyColumnRuleWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStrokeOpacity(StyleResolverState&);
    static void applyInheritCSSPropertyStrokeOpacity(StyleResolverState&);
    static void applyValueCSSPropertyStrokeOpacity(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOffsetRotate(StyleResolverState&);
    static void applyInheritCSSPropertyOffsetRotate(StyleResolverState&);
    static void applyValueCSSPropertyOffsetRotate(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontFamily(StyleResolverState&);
    static void applyInheritCSSPropertyFontFamily(StyleResolverState&);
    static void applyValueCSSPropertyFontFamily(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxFlex(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxFlex(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxFlex(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAnimationDuration(StyleResolverState&);
    static void applyInheritCSSPropertyAnimationDuration(StyleResolverState&);
    static void applyValueCSSPropertyAnimationDuration(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAnimationPlayState(StyleResolverState&);
    static void applyInheritCSSPropertyAnimationPlayState(StyleResolverState&);
    static void applyValueCSSPropertyAnimationPlayState(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskComposite(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskComposite(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskComposite(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyContain(StyleResolverState&);
    static void applyInheritCSSPropertyContain(StyleResolverState&);
    static void applyValueCSSPropertyContain(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskImage(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskImage(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskImage(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderBottomStyle(StyleResolverState&);
    static void applyInheritCSSPropertyBorderBottomStyle(StyleResolverState&);
    static void applyValueCSSPropertyBorderBottomStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyHeight(StyleResolverState&);
    static void applyInheritCSSPropertyHeight(StyleResolverState&);
    static void applyValueCSSPropertyHeight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderImageSource(StyleResolverState&);
    static void applyInheritCSSPropertyBorderImageSource(StyleResolverState&);
    static void applyValueCSSPropertyBorderImageSource(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyPaintOrder(StyleResolverState&);
    static void applyInheritCSSPropertyPaintOrder(StyleResolverState&);
    static void applyValueCSSPropertyPaintOrder(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextRendering(StyleResolverState&);
    static void applyInheritCSSPropertyTextRendering(StyleResolverState&);
    static void applyValueCSSPropertyTextRendering(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderBottomLeftRadius(StyleResolverState&);
    static void applyInheritCSSPropertyBorderBottomLeftRadius(StyleResolverState&);
    static void applyValueCSSPropertyBorderBottomLeftRadius(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColorInterpolation(StyleResolverState&);
    static void applyInheritCSSPropertyColorInterpolation(StyleResolverState&);
    static void applyValueCSSPropertyColorInterpolation(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskPositionY(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskPositionY(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskPositionY(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskPositionX(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskPositionX(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskPositionX(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontVariationSettings(StyleResolverState&);
    static void applyInheritCSSPropertyFontVariationSettings(StyleResolverState&);
    static void applyValueCSSPropertyFontVariationSettings(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextDecorationLine(StyleResolverState&);
    static void applyInheritCSSPropertyTextDecorationLine(StyleResolverState&);
    static void applyValueCSSPropertyTextDecorationLine(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyContent(StyleResolverState&);
    static void applyInheritCSSPropertyContent(StyleResolverState&);
    static void applyValueCSSPropertyContent(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFilter(StyleResolverState&);
    static void applyInheritCSSPropertyFilter(StyleResolverState&);
    static void applyValueCSSPropertyFilter(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyShapeMargin(StyleResolverState&);
    static void applyInheritCSSPropertyShapeMargin(StyleResolverState&);
    static void applyValueCSSPropertyShapeMargin(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOutlineColor(StyleResolverState&);
    static void applyInheritCSSPropertyOutlineColor(StyleResolverState&);
    static void applyValueCSSPropertyOutlineColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyScrollSnapType(StyleResolverState&);
    static void applyInheritCSSPropertyScrollSnapType(StyleResolverState&);
    static void applyValueCSSPropertyScrollSnapType(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyImageRendering(StyleResolverState&);
    static void applyInheritCSSPropertyImageRendering(StyleResolverState&);
    static void applyValueCSSPropertyImageRendering(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTextEmphasisStyle(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTextEmphasisStyle(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTextEmphasisStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyPaddingBottom(StyleResolverState&);
    static void applyInheritCSSPropertyPaddingBottom(StyleResolverState&);
    static void applyValueCSSPropertyPaddingBottom(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyQuotes(StyleResolverState&);
    static void applyInheritCSSPropertyQuotes(StyleResolverState&);
    static void applyValueCSSPropertyQuotes(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridAutoRows(StyleResolverState&);
    static void applyInheritCSSPropertyGridAutoRows(StyleResolverState&);
    static void applyValueCSSPropertyGridAutoRows(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyClipPath(StyleResolverState&);
    static void applyInheritCSSPropertyClipPath(StyleResolverState&);
    static void applyValueCSSPropertyClipPath(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBreakBefore(StyleResolverState&);
    static void applyInheritCSSPropertyBreakBefore(StyleResolverState&);
    static void applyValueCSSPropertyBreakBefore(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTextFillColor(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTextFillColor(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTextFillColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyObjectFit(StyleResolverState&);
    static void applyInheritCSSPropertyObjectFit(StyleResolverState&);
    static void applyValueCSSPropertyObjectFit(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStopOpacity(StyleResolverState&);
    static void applyInheritCSSPropertyStopOpacity(StyleResolverState&);
    static void applyValueCSSPropertyStopOpacity(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxReflect(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxReflect(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxReflect(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderTopRightRadius(StyleResolverState&);
    static void applyInheritCSSPropertyBorderTopRightRadius(StyleResolverState&);
    static void applyValueCSSPropertyBorderTopRightRadius(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxDirection(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxDirection(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxDirection(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitUserModify(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitUserModify(StyleResolverState&);
    static void applyValueCSSPropertyWebkitUserModify(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxDecorationBreak(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxDecorationBreak(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxDecorationBreak(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontKerning(StyleResolverState&);
    static void applyInheritCSSPropertyFontKerning(StyleResolverState&);
    static void applyValueCSSPropertyFontKerning(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontWeight(StyleResolverState&);
    static void applyInheritCSSPropertyFontWeight(StyleResolverState&);
    static void applyValueCSSPropertyFontWeight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyShapeImageThreshold(StyleResolverState&);
    static void applyInheritCSSPropertyShapeImageThreshold(StyleResolverState&);
    static void applyValueCSSPropertyShapeImageThreshold(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyRy(StyleResolverState&);
    static void applyInheritCSSPropertyRy(StyleResolverState&);
    static void applyValueCSSPropertyRy(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyRx(StyleResolverState&);
    static void applyInheritCSSPropertyRx(StyleResolverState&);
    static void applyValueCSSPropertyRx(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMarginRight(StyleResolverState&);
    static void applyInheritCSSPropertyMarginRight(StyleResolverState&);
    static void applyValueCSSPropertyMarginRight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitFontSmoothing(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitFontSmoothing(StyleResolverState&);
    static void applyValueCSSPropertyWebkitFontSmoothing(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAnimationDelay(StyleResolverState&);
    static void applyInheritCSSPropertyAnimationDelay(StyleResolverState&);
    static void applyValueCSSPropertyAnimationDelay(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBreakAfter(StyleResolverState&);
    static void applyInheritCSSPropertyBreakAfter(StyleResolverState&);
    static void applyValueCSSPropertyBreakAfter(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOpacity(StyleResolverState&);
    static void applyInheritCSSPropertyOpacity(StyleResolverState&);
    static void applyValueCSSPropertyOpacity(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyDominantBaseline(StyleResolverState&);
    static void applyInheritCSSPropertyDominantBaseline(StyleResolverState&);
    static void applyValueCSSPropertyDominantBaseline(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskBoxImageOutset(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskBoxImageOutset(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskBoxImageOutset(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAlignSelf(StyleResolverState&);
    static void applyInheritCSSPropertyAlignSelf(StyleResolverState&);
    static void applyValueCSSPropertyAlignSelf(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyClear(StyleResolverState&);
    static void applyInheritCSSPropertyClear(StyleResolverState&);
    static void applyValueCSSPropertyClear(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyPaddingRight(StyleResolverState&);
    static void applyInheritCSSPropertyPaddingRight(StyleResolverState&);
    static void applyValueCSSPropertyPaddingRight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextCombineUpright(StyleResolverState&);
    static void applyInheritCSSPropertyTextCombineUpright(StyleResolverState&);
    static void applyValueCSSPropertyTextCombineUpright(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTransitionProperty(StyleResolverState&);
    static void applyInheritCSSPropertyTransitionProperty(StyleResolverState&);
    static void applyValueCSSPropertyTransitionProperty(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTransformStyle(StyleResolverState&);
    static void applyInheritCSSPropertyTransformStyle(StyleResolverState&);
    static void applyValueCSSPropertyTransformStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBorderHorizontalSpacing(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBorderHorizontalSpacing(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBorderHorizontalSpacing(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTapHighlightColor(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTapHighlightColor(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTapHighlightColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyCaptionSide(StyleResolverState&);
    static void applyInheritCSSPropertyCaptionSide(StyleResolverState&);
    static void applyValueCSSPropertyCaptionSide(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColumnCount(StyleResolverState&);
    static void applyInheritCSSPropertyColumnCount(StyleResolverState&);
    static void applyValueCSSPropertyColumnCount(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitPrintColorAdjust(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitPrintColorAdjust(StyleResolverState&);
    static void applyValueCSSPropertyWebkitPrintColorAdjust(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStrokeDasharray(StyleResolverState&);
    static void applyInheritCSSPropertyStrokeDasharray(StyleResolverState&);
    static void applyValueCSSPropertyStrokeDasharray(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFlexBasis(StyleResolverState&);
    static void applyInheritCSSPropertyFlexBasis(StyleResolverState&);
    static void applyValueCSSPropertyFlexBasis(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWidows(StyleResolverState&);
    static void applyInheritCSSPropertyWidows(StyleResolverState&);
    static void applyValueCSSPropertyWidows(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitRubyPosition(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitRubyPosition(StyleResolverState&);
    static void applyValueCSSPropertyWebkitRubyPosition(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFlexShrink(StyleResolverState&);
    static void applyInheritCSSPropertyFlexShrink(StyleResolverState&);
    static void applyValueCSSPropertyFlexShrink(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTransformOriginY(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTransformOriginY(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTransformOriginY(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTransformOriginX(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTransformOriginX(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTransformOriginX(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridTemplateRows(StyleResolverState&);
    static void applyInheritCSSPropertyGridTemplateRows(StyleResolverState&);
    static void applyValueCSSPropertyGridTemplateRows(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTransform(StyleResolverState&);
    static void applyInheritCSSPropertyTransform(StyleResolverState&);
    static void applyValueCSSPropertyTransform(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskOrigin(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskOrigin(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskOrigin(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyScrollBehavior(StyleResolverState&);
    static void applyInheritCSSPropertyScrollBehavior(StyleResolverState&);
    static void applyValueCSSPropertyScrollBehavior(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTextStrokeColor(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTextStrokeColor(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTextStrokeColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFill(StyleResolverState&);
    static void applyInheritCSSPropertyFill(StyleResolverState&);
    static void applyValueCSSPropertyFill(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridAutoFlow(StyleResolverState&);
    static void applyInheritCSSPropertyGridAutoFlow(StyleResolverState&);
    static void applyValueCSSPropertyGridAutoFlow(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTextEmphasisPosition(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTextEmphasisPosition(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTextEmphasisPosition(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStopColor(StyleResolverState&);
    static void applyInheritCSSPropertyStopColor(StyleResolverState&);
    static void applyValueCSSPropertyStopColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitLineClamp(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitLineClamp(StyleResolverState&);
    static void applyValueCSSPropertyWebkitLineClamp(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyJustifySelf(StyleResolverState&);
    static void applyInheritCSSPropertyJustifySelf(StyleResolverState&);
    static void applyValueCSSPropertyJustifySelf(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextJustify(StyleResolverState&);
    static void applyInheritCSSPropertyTextJustify(StyleResolverState&);
    static void applyValueCSSPropertyTextJustify(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyZoom(StyleResolverState&);
    static void applyInheritCSSPropertyZoom(StyleResolverState&);
    static void applyValueCSSPropertyZoom(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskBoxImageRepeat(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskBoxImageRepeat(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskBoxImageRepeat(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWordSpacing(StyleResolverState&);
    static void applyInheritCSSPropertyWordSpacing(StyleResolverState&);
    static void applyValueCSSPropertyWordSpacing(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyPerspectiveOrigin(StyleResolverState&);
    static void applyInheritCSSPropertyPerspectiveOrigin(StyleResolverState&);
    static void applyValueCSSPropertyPerspectiveOrigin(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextAnchor(StyleResolverState&);
    static void applyInheritCSSPropertyTextAnchor(StyleResolverState&);
    static void applyValueCSSPropertyTextAnchor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontStyle(StyleResolverState&);
    static void applyInheritCSSPropertyFontStyle(StyleResolverState&);
    static void applyValueCSSPropertyFontStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderBottomRightRadius(StyleResolverState&);
    static void applyInheritCSSPropertyBorderBottomRightRadius(StyleResolverState&);
    static void applyValueCSSPropertyBorderBottomRightRadius(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderRightWidth(StyleResolverState&);
    static void applyInheritCSSPropertyBorderRightWidth(StyleResolverState&);
    static void applyValueCSSPropertyBorderRightWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderTopLeftRadius(StyleResolverState&);
    static void applyInheritCSSPropertyBorderTopLeftRadius(StyleResolverState&);
    static void applyValueCSSPropertyBorderTopLeftRadius(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWritingMode(StyleResolverState&);
    static void applyInheritCSSPropertyWritingMode(StyleResolverState&);
    static void applyValueCSSPropertyWritingMode(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundAttachment(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundAttachment(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundAttachment(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTextSecurity(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTextSecurity(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTextSecurity(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderLeftWidth(StyleResolverState&);
    static void applyInheritCSSPropertyBorderLeftWidth(StyleResolverState&);
    static void applyValueCSSPropertyBorderLeftWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitLineBreak(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitLineBreak(StyleResolverState&);
    static void applyValueCSSPropertyWebkitLineBreak(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundImage(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundImage(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundImage(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskClip(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskClip(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskClip(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyCounterReset(StyleResolverState&);
    static void applyInheritCSSPropertyCounterReset(StyleResolverState&);
    static void applyValueCSSPropertyCounterReset(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderImageSlice(StyleResolverState&);
    static void applyInheritCSSPropertyBorderImageSlice(StyleResolverState&);
    static void applyValueCSSPropertyBorderImageSlice(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyIsolation(StyleResolverState&);
    static void applyInheritCSSPropertyIsolation(StyleResolverState&);
    static void applyValueCSSPropertyIsolation(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFillOpacity(StyleResolverState&);
    static void applyInheritCSSPropertyFillOpacity(StyleResolverState&);
    static void applyValueCSSPropertyFillOpacity(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderTopWidth(StyleResolverState&);
    static void applyInheritCSSPropertyBorderTopWidth(StyleResolverState&);
    static void applyValueCSSPropertyBorderTopWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBottom(StyleResolverState&);
    static void applyInheritCSSPropertyBottom(StyleResolverState&);
    static void applyValueCSSPropertyBottom(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderCollapse(StyleResolverState&);
    static void applyInheritCSSPropertyBorderCollapse(StyleResolverState&);
    static void applyValueCSSPropertyBorderCollapse(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTop(StyleResolverState&);
    static void applyInheritCSSPropertyTop(StyleResolverState&);
    static void applyValueCSSPropertyTop(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyScrollSnapPointsX(StyleResolverState&);
    static void applyInheritCSSPropertyScrollSnapPointsX(StyleResolverState&);
    static void applyValueCSSPropertyScrollSnapPointsX(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyScrollSnapPointsY(StyleResolverState&);
    static void applyInheritCSSPropertyScrollSnapPointsY(StyleResolverState&);
    static void applyValueCSSPropertyScrollSnapPointsY(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyUnicodeBidi(StyleResolverState&);
    static void applyInheritCSSPropertyUnicodeBidi(StyleResolverState&);
    static void applyValueCSSPropertyUnicodeBidi(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAnimationIterationCount(StyleResolverState&);
    static void applyInheritCSSPropertyAnimationIterationCount(StyleResolverState&);
    static void applyValueCSSPropertyAnimationIterationCount(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitWritingMode(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitWritingMode(StyleResolverState&);
    static void applyValueCSSPropertyWebkitWritingMode(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFloat(StyleResolverState&);
    static void applyInheritCSSPropertyFloat(StyleResolverState&);
    static void applyValueCSSPropertyFloat(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWordWrap(StyleResolverState&);
    static void applyInheritCSSPropertyWordWrap(StyleResolverState&);
    static void applyValueCSSPropertyWordWrap(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTransformOrigin(StyleResolverState&);
    static void applyInheritCSSPropertyTransformOrigin(StyleResolverState&);
    static void applyValueCSSPropertyTransformOrigin(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitRtlOrdering(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitRtlOrdering(StyleResolverState&);
    static void applyValueCSSPropertyWebkitRtlOrdering(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMarginTop(StyleResolverState&);
    static void applyInheritCSSPropertyMarginTop(StyleResolverState&);
    static void applyValueCSSPropertyMarginTop(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMaxWidth(StyleResolverState&);
    static void applyInheritCSSPropertyMaxWidth(StyleResolverState&);
    static void applyValueCSSPropertyMaxWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextIndent(StyleResolverState&);
    static void applyInheritCSSPropertyTextIndent(StyleResolverState&);
    static void applyValueCSSPropertyTextIndent(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextShadow(StyleResolverState&);
    static void applyInheritCSSPropertyTextShadow(StyleResolverState&);
    static void applyValueCSSPropertyTextShadow(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderImageOutset(StyleResolverState&);
    static void applyInheritCSSPropertyBorderImageOutset(StyleResolverState&);
    static void applyValueCSSPropertyBorderImageOutset(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontVariantCaps(StyleResolverState&);
    static void applyInheritCSSPropertyFontVariantCaps(StyleResolverState&);
    static void applyValueCSSPropertyFontVariantCaps(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxOrdinalGroup(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxOrdinalGroup(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxOrdinalGroup(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderImageRepeat(StyleResolverState&);
    static void applyInheritCSSPropertyBorderImageRepeat(StyleResolverState&);
    static void applyValueCSSPropertyBorderImageRepeat(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColumnFill(StyleResolverState&);
    static void applyInheritCSSPropertyColumnFill(StyleResolverState&);
    static void applyValueCSSPropertyColumnFill(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTransitionTimingFunction(StyleResolverState&);
    static void applyInheritCSSPropertyTransitionTimingFunction(StyleResolverState&);
    static void applyValueCSSPropertyTransitionTimingFunction(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOverflowX(StyleResolverState&);
    static void applyInheritCSSPropertyOverflowX(StyleResolverState&);
    static void applyValueCSSPropertyOverflowX(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOverflowY(StyleResolverState&);
    static void applyInheritCSSPropertyOverflowY(StyleResolverState&);
    static void applyValueCSSPropertyOverflowY(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColumnRuleColor(StyleResolverState&);
    static void applyInheritCSSPropertyColumnRuleColor(StyleResolverState&);
    static void applyValueCSSPropertyColumnRuleColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyHyphens(StyleResolverState&);
    static void applyInheritCSSPropertyHyphens(StyleResolverState&);
    static void applyValueCSSPropertyHyphens(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridTemplateColumns(StyleResolverState&);
    static void applyInheritCSSPropertyGridTemplateColumns(StyleResolverState&);
    static void applyValueCSSPropertyGridTemplateColumns(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextSizeAdjust(StyleResolverState&);
    static void applyInheritCSSPropertyTextSizeAdjust(StyleResolverState&);
    static void applyValueCSSPropertyTextSizeAdjust(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyPerspective(StyleResolverState&);
    static void applyInheritCSSPropertyPerspective(StyleResolverState&);
    static void applyValueCSSPropertyPerspective(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyUserSelect(StyleResolverState&);
    static void applyInheritCSSPropertyUserSelect(StyleResolverState&);
    static void applyValueCSSPropertyUserSelect(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyLineHeight(StyleResolverState&);
    static void applyInheritCSSPropertyLineHeight(StyleResolverState&);
    static void applyValueCSSPropertyLineHeight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColumnGap(StyleResolverState&);
    static void applyInheritCSSPropertyColumnGap(StyleResolverState&);
    static void applyValueCSSPropertyColumnGap(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMaskSourceType(StyleResolverState&);
    static void applyInheritCSSPropertyMaskSourceType(StyleResolverState&);
    static void applyValueCSSPropertyMaskSourceType(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertySnapHeight(StyleResolverState&);
    static void applyInheritCSSPropertySnapHeight(StyleResolverState&);
    static void applyValueCSSPropertySnapHeight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundRepeatY(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundRepeatY(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundRepeatY(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOrder(StyleResolverState&);
    static void applyInheritCSSPropertyOrder(StyleResolverState&);
    static void applyValueCSSPropertyOrder(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxAlign(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxAlign(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxAlign(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyScale(StyleResolverState&);
    static void applyInheritCSSPropertyScale(StyleResolverState&);
    static void applyValueCSSPropertyScale(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridAutoColumns(StyleResolverState&);
    static void applyInheritCSSPropertyGridAutoColumns(StyleResolverState&);
    static void applyValueCSSPropertyGridAutoColumns(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridRowStart(StyleResolverState&);
    static void applyInheritCSSPropertyGridRowStart(StyleResolverState&);
    static void applyValueCSSPropertyGridRowStart(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTransitionDuration(StyleResolverState&);
    static void applyInheritCSSPropertyTransitionDuration(StyleResolverState&);
    static void applyValueCSSPropertyTransitionDuration(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTextStrokeWidth(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTextStrokeWidth(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTextStrokeWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStrokeDashoffset(StyleResolverState&);
    static void applyInheritCSSPropertyStrokeDashoffset(StyleResolverState&);
    static void applyValueCSSPropertyStrokeDashoffset(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyPosition(StyleResolverState&);
    static void applyInheritCSSPropertyPosition(StyleResolverState&);
    static void applyValueCSSPropertyPosition(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitAppRegion(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitAppRegion(StyleResolverState&);
    static void applyValueCSSPropertyWebkitAppRegion(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontStretch(StyleResolverState&);
    static void applyInheritCSSPropertyFontStretch(StyleResolverState&);
    static void applyValueCSSPropertyFontStretch(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMixBlendMode(StyleResolverState&);
    static void applyInheritCSSPropertyMixBlendMode(StyleResolverState&);
    static void applyValueCSSPropertyMixBlendMode(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBaselineShift(StyleResolverState&);
    static void applyInheritCSSPropertyBaselineShift(StyleResolverState&);
    static void applyValueCSSPropertyBaselineShift(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyPaddingLeft(StyleResolverState&);
    static void applyInheritCSSPropertyPaddingLeft(StyleResolverState&);
    static void applyValueCSSPropertyPaddingLeft(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWhiteSpace(StyleResolverState&);
    static void applyInheritCSSPropertyWhiteSpace(StyleResolverState&);
    static void applyValueCSSPropertyWhiteSpace(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundClip(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundClip(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundClip(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOverflowWrap(StyleResolverState&);
    static void applyInheritCSSPropertyOverflowWrap(StyleResolverState&);
    static void applyValueCSSPropertyOverflowWrap(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyVerticalAlign(StyleResolverState&);
    static void applyInheritCSSPropertyVerticalAlign(StyleResolverState&);
    static void applyValueCSSPropertyVerticalAlign(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitLocale(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitLocale(StyleResolverState&);
    static void applyValueCSSPropertyWebkitLocale(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMarginAfterCollapse(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMarginAfterCollapse(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMarginAfterCollapse(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOffsetPosition(StyleResolverState&);
    static void applyInheritCSSPropertyOffsetPosition(StyleResolverState&);
    static void applyValueCSSPropertyOffsetPosition(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackdropFilter(StyleResolverState&);
    static void applyInheritCSSPropertyBackdropFilter(StyleResolverState&);
    static void applyValueCSSPropertyBackdropFilter(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOutlineStyle(StyleResolverState&);
    static void applyInheritCSSPropertyOutlineStyle(StyleResolverState&);
    static void applyValueCSSPropertyOutlineStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMarkerEnd(StyleResolverState&);
    static void applyInheritCSSPropertyMarkerEnd(StyleResolverState&);
    static void applyValueCSSPropertyMarkerEnd(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderRightColor(StyleResolverState&);
    static void applyInheritCSSPropertyBorderRightColor(StyleResolverState&);
    static void applyValueCSSPropertyBorderRightColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxLines(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxLines(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxLines(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOffsetAnchor(StyleResolverState&);
    static void applyInheritCSSPropertyOffsetAnchor(StyleResolverState&);
    static void applyValueCSSPropertyOffsetAnchor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColumnSpan(StyleResolverState&);
    static void applyInheritCSSPropertyColumnSpan(StyleResolverState&);
    static void applyValueCSSPropertyColumnSpan(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTableLayout(StyleResolverState&);
    static void applyInheritCSSPropertyTableLayout(StyleResolverState&);
    static void applyValueCSSPropertyTableLayout(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridRowGap(StyleResolverState&);
    static void applyInheritCSSPropertyGridRowGap(StyleResolverState&);
    static void applyValueCSSPropertyGridRowGap(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderRightStyle(StyleResolverState&);
    static void applyInheritCSSPropertyBorderRightStyle(StyleResolverState&);
    static void applyValueCSSPropertyBorderRightStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridRowEnd(StyleResolverState&);
    static void applyInheritCSSPropertyGridRowEnd(StyleResolverState&);
    static void applyValueCSSPropertyGridRowEnd(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextUnderlinePosition(StyleResolverState&);
    static void applyInheritCSSPropertyTextUnderlinePosition(StyleResolverState&);
    static void applyValueCSSPropertyTextUnderlinePosition(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackfaceVisibility(StyleResolverState&);
    static void applyInheritCSSPropertyBackfaceVisibility(StyleResolverState&);
    static void applyValueCSSPropertyBackfaceVisibility(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyLeft(StyleResolverState&);
    static void applyInheritCSSPropertyLeft(StyleResolverState&);
    static void applyValueCSSPropertyLeft(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWidth(StyleResolverState&);
    static void applyInheritCSSPropertyWidth(StyleResolverState&);
    static void applyValueCSSPropertyWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColumnRuleStyle(StyleResolverState&);
    static void applyInheritCSSPropertyColumnRuleStyle(StyleResolverState&);
    static void applyValueCSSPropertyColumnRuleStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOffsetPath(StyleResolverState&);
    static void applyInheritCSSPropertyOffsetPath(StyleResolverState&);
    static void applyValueCSSPropertyOffsetPath(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextDecorationSkip(StyleResolverState&);
    static void applyInheritCSSPropertyTextDecorationSkip(StyleResolverState&);
    static void applyValueCSSPropertyTextDecorationSkip(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBreakInside(StyleResolverState&);
    static void applyInheritCSSPropertyBreakInside(StyleResolverState&);
    static void applyValueCSSPropertyBreakInside(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskBoxImageSource(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskBoxImageSource(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskBoxImageSource(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontFeatureSettings(StyleResolverState&);
    static void applyInheritCSSPropertyFontFeatureSettings(StyleResolverState&);
    static void applyValueCSSPropertyFontFeatureSettings(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStrokeMiterlimit(StyleResolverState&);
    static void applyInheritCSSPropertyStrokeMiterlimit(StyleResolverState&);
    static void applyValueCSSPropertyStrokeMiterlimit(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOverflowAnchor(StyleResolverState&);
    static void applyInheritCSSPropertyOverflowAnchor(StyleResolverState&);
    static void applyValueCSSPropertyOverflowAnchor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridColumnStart(StyleResolverState&);
    static void applyInheritCSSPropertyGridColumnStart(StyleResolverState&);
    static void applyValueCSSPropertyGridColumnStart(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMarginBottom(StyleResolverState&);
    static void applyInheritCSSPropertyMarginBottom(StyleResolverState&);
    static void applyValueCSSPropertyMarginBottom(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyListStylePosition(StyleResolverState&);
    static void applyInheritCSSPropertyListStylePosition(StyleResolverState&);
    static void applyValueCSSPropertyListStylePosition(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOutlineOffset(StyleResolverState&);
    static void applyInheritCSSPropertyOutlineOffset(StyleResolverState&);
    static void applyValueCSSPropertyOutlineOffset(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyShapeRendering(StyleResolverState&);
    static void applyInheritCSSPropertyShapeRendering(StyleResolverState&);
    static void applyValueCSSPropertyShapeRendering(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskSize(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskSize(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskSize(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyJustifyItems(StyleResolverState&);
    static void applyInheritCSSPropertyJustifyItems(StyleResolverState&);
    static void applyValueCSSPropertyJustifyItems(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyRotate(StyleResolverState&);
    static void applyInheritCSSPropertyRotate(StyleResolverState&);
    static void applyValueCSSPropertyRotate(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColorRendering(StyleResolverState&);
    static void applyInheritCSSPropertyColorRendering(StyleResolverState&);
    static void applyValueCSSPropertyColorRendering(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStrokeLinejoin(StyleResolverState&);
    static void applyInheritCSSPropertyStrokeLinejoin(StyleResolverState&);
    static void applyValueCSSPropertyStrokeLinejoin(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderImageWidth(StyleResolverState&);
    static void applyInheritCSSPropertyBorderImageWidth(StyleResolverState&);
    static void applyValueCSSPropertyBorderImageWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFlexGrow(StyleResolverState&);
    static void applyInheritCSSPropertyFlexGrow(StyleResolverState&);
    static void applyValueCSSPropertyFlexGrow(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMask(StyleResolverState&);
    static void applyInheritCSSPropertyMask(StyleResolverState&);
    static void applyValueCSSPropertyMask(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMarginBeforeCollapse(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMarginBeforeCollapse(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMarginBeforeCollapse(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitAppearance(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitAppearance(StyleResolverState&);
    static void applyValueCSSPropertyWebkitAppearance(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAnimationTimingFunction(StyleResolverState&);
    static void applyInheritCSSPropertyAnimationTimingFunction(StyleResolverState&);
    static void applyValueCSSPropertyAnimationTimingFunction(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyPointerEvents(StyleResolverState&);
    static void applyInheritCSSPropertyPointerEvents(StyleResolverState&);
    static void applyValueCSSPropertyPointerEvents(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxOrient(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxOrient(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxOrient(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStrokeLinecap(StyleResolverState&);
    static void applyInheritCSSPropertyStrokeLinecap(StyleResolverState&);
    static void applyValueCSSPropertyStrokeLinecap(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderLeftStyle(StyleResolverState&);
    static void applyInheritCSSPropertyBorderLeftStyle(StyleResolverState&);
    static void applyValueCSSPropertyBorderLeftStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitUserDrag(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitUserDrag(StyleResolverState&);
    static void applyValueCSSPropertyWebkitUserDrag(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridTemplateAreas(StyleResolverState&);
    static void applyInheritCSSPropertyGridTemplateAreas(StyleResolverState&);
    static void applyValueCSSPropertyGridTemplateAreas(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontVariantLigatures(StyleResolverState&);
    static void applyInheritCSSPropertyFontVariantLigatures(StyleResolverState&);
    static void applyValueCSSPropertyFontVariantLigatures(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMarkerMid(StyleResolverState&);
    static void applyInheritCSSPropertyMarkerMid(StyleResolverState&);
    static void applyValueCSSPropertyMarkerMid(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTextCombine(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTextCombine(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTextCombine(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyX(StyleResolverState&);
    static void applyInheritCSSPropertyX(StyleResolverState&);
    static void applyValueCSSPropertyX(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyY(StyleResolverState&);
    static void applyInheritCSSPropertyY(StyleResolverState&);
    static void applyValueCSSPropertyY(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyR(StyleResolverState&);
    static void applyInheritCSSPropertyR(StyleResolverState&);
    static void applyValueCSSPropertyR(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyResize(StyleResolverState&);
    static void applyInheritCSSPropertyResize(StyleResolverState&);
    static void applyValueCSSPropertyResize(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOffsetDistance(StyleResolverState&);
    static void applyInheritCSSPropertyOffsetDistance(StyleResolverState&);
    static void applyValueCSSPropertyOffsetDistance(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyLetterSpacing(StyleResolverState&);
    static void applyInheritCSSPropertyLetterSpacing(StyleResolverState&);
    static void applyValueCSSPropertyLetterSpacing(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTransformOriginZ(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTransformOriginZ(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTransformOriginZ(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAnimationDirection(StyleResolverState&);
    static void applyInheritCSSPropertyAnimationDirection(StyleResolverState&);
    static void applyValueCSSPropertyAnimationDirection(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTextOrientation(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTextOrientation(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTextOrientation(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyD(StyleResolverState&);
    static void applyInheritCSSPropertyD(StyleResolverState&);
    static void applyValueCSSPropertyD(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColorInterpolationFilters(StyleResolverState&);
    static void applyInheritCSSPropertyColorInterpolationFilters(StyleResolverState&);
    static void applyValueCSSPropertyColorInterpolationFilters(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextTransform(StyleResolverState&);
    static void applyInheritCSSPropertyTextTransform(StyleResolverState&);
    static void applyValueCSSPropertyTextTransform(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyRight(StyleResolverState&);
    static void applyInheritCSSPropertyRight(StyleResolverState&);
    static void applyValueCSSPropertyRight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridColumnEnd(StyleResolverState&);
    static void applyInheritCSSPropertyGridColumnEnd(StyleResolverState&);
    static void applyValueCSSPropertyGridColumnEnd(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundSize(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundSize(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundSize(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyScrollSnapCoordinate(StyleResolverState&);
    static void applyInheritCSSPropertyScrollSnapCoordinate(StyleResolverState&);
    static void applyValueCSSPropertyScrollSnapCoordinate(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAlignContent(StyleResolverState&);
    static void applyInheritCSSPropertyAlignContent(StyleResolverState&);
    static void applyValueCSSPropertyAlignContent(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyDirection(StyleResolverState&);
    static void applyInheritCSSPropertyDirection(StyleResolverState&);
    static void applyValueCSSPropertyDirection(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextOrientation(StyleResolverState&);
    static void applyInheritCSSPropertyTextOrientation(StyleResolverState&);
    static void applyValueCSSPropertyTextOrientation(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyClip(StyleResolverState&);
    static void applyInheritCSSPropertyClip(StyleResolverState&);
    static void applyValueCSSPropertyClip(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAnimationFillMode(StyleResolverState&);
    static void applyInheritCSSPropertyAnimationFillMode(StyleResolverState&);
    static void applyValueCSSPropertyAnimationFillMode(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColor(StyleResolverState&);
    static void applyInheritCSSPropertyColor(StyleResolverState&);
    static void applyValueCSSPropertyColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBorderImage(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBorderImage(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBorderImage(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTouchAction(StyleResolverState&);
    static void applyInheritCSSPropertyTouchAction(StyleResolverState&);
    static void applyValueCSSPropertyTouchAction(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBorderVerticalSpacing(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBorderVerticalSpacing(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBorderVerticalSpacing(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMarginLeft(StyleResolverState&);
    static void applyInheritCSSPropertyMarginLeft(StyleResolverState&);
    static void applyValueCSSPropertyMarginLeft(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFlexWrap(StyleResolverState&);
    static void applyInheritCSSPropertyFlexWrap(StyleResolverState&);
    static void applyValueCSSPropertyFlexWrap(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMinHeight(StyleResolverState&);
    static void applyInheritCSSPropertyMinHeight(StyleResolverState&);
    static void applyValueCSSPropertyMinHeight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderLeftColor(StyleResolverState&);
    static void applyInheritCSSPropertyBorderLeftColor(StyleResolverState&);
    static void applyValueCSSPropertyBorderLeftColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFloodColor(StyleResolverState&);
    static void applyInheritCSSPropertyFloodColor(StyleResolverState&);
    static void applyValueCSSPropertyFloodColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMaxHeight(StyleResolverState&);
    static void applyInheritCSSPropertyMaxHeight(StyleResolverState&);
    static void applyValueCSSPropertyMaxHeight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStroke(StyleResolverState&);
    static void applyInheritCSSPropertyStroke(StyleResolverState&);
    static void applyValueCSSPropertyStroke(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWillChange(StyleResolverState&);
    static void applyInheritCSSPropertyWillChange(StyleResolverState&);
    static void applyValueCSSPropertyWillChange(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBufferedRendering(StyleResolverState&);
    static void applyInheritCSSPropertyBufferedRendering(StyleResolverState&);
    static void applyValueCSSPropertyBufferedRendering(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskBoxImageSlice(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskBoxImageSlice(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskBoxImageSlice(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOrphans(StyleResolverState&);
    static void applyInheritCSSPropertyOrphans(StyleResolverState&);
    static void applyValueCSSPropertyOrphans(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundPositionY(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundPositionY(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundPositionY(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundPositionX(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundPositionX(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundPositionX(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAlignmentBaseline(StyleResolverState&);
    static void applyInheritCSSPropertyAlignmentBaseline(StyleResolverState&);
    static void applyValueCSSPropertyAlignmentBaseline(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMinWidth(StyleResolverState&);
    static void applyInheritCSSPropertyMinWidth(StyleResolverState&);
    static void applyValueCSSPropertyMinWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMaskType(StyleResolverState&);
    static void applyInheritCSSPropertyMaskType(StyleResolverState&);
    static void applyValueCSSPropertyMaskType(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundOrigin(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundOrigin(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundOrigin(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitPerspectiveOriginY(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitPerspectiveOriginY(StyleResolverState&);
    static void applyValueCSSPropertyWebkitPerspectiveOriginY(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextAlignLast(StyleResolverState&);
    static void applyInheritCSSPropertyTextAlignLast(StyleResolverState&);
    static void applyValueCSSPropertyTextAlignLast(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMarginTopCollapse(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMarginTopCollapse(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMarginTopCollapse(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyCaretColor(StyleResolverState&);
    static void applyInheritCSSPropertyCaretColor(StyleResolverState&);
    static void applyValueCSSPropertyCaretColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyColumnWidth(StyleResolverState&);
    static void applyInheritCSSPropertyColumnWidth(StyleResolverState&);
    static void applyValueCSSPropertyColumnWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyCursor(StyleResolverState&);
    static void applyInheritCSSPropertyCursor(StyleResolverState&);
    static void applyValueCSSPropertyCursor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTabSize(StyleResolverState&);
    static void applyInheritCSSPropertyTabSize(StyleResolverState&);
    static void applyValueCSSPropertyTabSize(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyOffsetRotation(StyleResolverState&);
    static void applyInheritCSSPropertyOffsetRotation(StyleResolverState&);
    static void applyValueCSSPropertyOffsetRotation(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyCounterIncrement(StyleResolverState&);
    static void applyInheritCSSPropertyCounterIncrement(StyleResolverState&);
    static void applyValueCSSPropertyCounterIncrement(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderBottomWidth(StyleResolverState&);
    static void applyInheritCSSPropertyBorderBottomWidth(StyleResolverState&);
    static void applyValueCSSPropertyBorderBottomWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitHighlight(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitHighlight(StyleResolverState&);
    static void applyValueCSSPropertyWebkitHighlight(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyEmptyCells(StyleResolverState&);
    static void applyInheritCSSPropertyEmptyCells(StyleResolverState&);
    static void applyValueCSSPropertyEmptyCells(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextOverflow(StyleResolverState&);
    static void applyInheritCSSPropertyTextOverflow(StyleResolverState&);
    static void applyValueCSSPropertyTextOverflow(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBoxSizing(StyleResolverState&);
    static void applyInheritCSSPropertyBoxSizing(StyleResolverState&);
    static void applyValueCSSPropertyBoxSizing(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyStrokeWidth(StyleResolverState&);
    static void applyInheritCSSPropertyStrokeWidth(StyleResolverState&);
    static void applyValueCSSPropertyStrokeWidth(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundBlendMode(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundBlendMode(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundBlendMode(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyMarkerStart(StyleResolverState&);
    static void applyInheritCSSPropertyMarkerStart(StyleResolverState&);
    static void applyValueCSSPropertyMarkerStart(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextDecorationStyle(StyleResolverState&);
    static void applyInheritCSSPropertyTextDecorationStyle(StyleResolverState&);
    static void applyValueCSSPropertyTextDecorationStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundRepeatX(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundRepeatX(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundRepeatX(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTranslate(StyleResolverState&);
    static void applyInheritCSSPropertyTranslate(StyleResolverState&);
    static void applyValueCSSPropertyTranslate(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderTopColor(StyleResolverState&);
    static void applyInheritCSSPropertyBorderTopColor(StyleResolverState&);
    static void applyValueCSSPropertyBorderTopColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBackgroundColor(StyleResolverState&);
    static void applyInheritCSSPropertyBackgroundColor(StyleResolverState&);
    static void applyValueCSSPropertyBackgroundColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyPaddingTop(StyleResolverState&);
    static void applyInheritCSSPropertyPaddingTop(StyleResolverState&);
    static void applyValueCSSPropertyPaddingTop(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitTextEmphasisColor(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitTextEmphasisColor(StyleResolverState&);
    static void applyValueCSSPropertyWebkitTextEmphasisColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyDisplay(StyleResolverState&);
    static void applyInheritCSSPropertyDisplay(StyleResolverState&);
    static void applyValueCSSPropertyDisplay(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWordBreak(StyleResolverState&);
    static void applyInheritCSSPropertyWordBreak(StyleResolverState&);
    static void applyValueCSSPropertyWordBreak(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderTopStyle(StyleResolverState&);
    static void applyInheritCSSPropertyBorderTopStyle(StyleResolverState&);
    static void applyValueCSSPropertyBorderTopStyle(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyJustifyContent(StyleResolverState&);
    static void applyInheritCSSPropertyJustifyContent(StyleResolverState&);
    static void applyValueCSSPropertyJustifyContent(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBoxShadow(StyleResolverState&);
    static void applyInheritCSSPropertyBoxShadow(StyleResolverState&);
    static void applyValueCSSPropertyBoxShadow(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertySpeak(StyleResolverState&);
    static void applyInheritCSSPropertySpeak(StyleResolverState&);
    static void applyValueCSSPropertySpeak(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyZIndex(StyleResolverState&);
    static void applyInheritCSSPropertyZIndex(StyleResolverState&);
    static void applyValueCSSPropertyZIndex(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyListStyleImage(StyleResolverState&);
    static void applyInheritCSSPropertyListStyleImage(StyleResolverState&);
    static void applyValueCSSPropertyListStyleImage(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFloodOpacity(StyleResolverState&);
    static void applyInheritCSSPropertyFloodOpacity(StyleResolverState&);
    static void applyValueCSSPropertyFloodOpacity(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyClipRule(StyleResolverState&);
    static void applyInheritCSSPropertyClipRule(StyleResolverState&);
    static void applyValueCSSPropertyClipRule(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFlexDirection(StyleResolverState&);
    static void applyInheritCSSPropertyFlexDirection(StyleResolverState&);
    static void applyValueCSSPropertyFlexDirection(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyLightingColor(StyleResolverState&);
    static void applyInheritCSSPropertyLightingColor(StyleResolverState&);
    static void applyValueCSSPropertyLightingColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskRepeatY(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskRepeatY(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskRepeatY(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitMaskRepeatX(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitMaskRepeatX(StyleResolverState&);
    static void applyValueCSSPropertyWebkitMaskRepeatX(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyListStyleType(StyleResolverState&);
    static void applyInheritCSSPropertyListStyleType(StyleResolverState&);
    static void applyValueCSSPropertyListStyleType(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyImageOrientation(StyleResolverState&);
    static void applyInheritCSSPropertyImageOrientation(StyleResolverState&);
    static void applyValueCSSPropertyImageOrientation(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyTextAlign(StyleResolverState&);
    static void applyInheritCSSPropertyTextAlign(StyleResolverState&);
    static void applyValueCSSPropertyTextAlign(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyAlignItems(StyleResolverState&);
    static void applyInheritCSSPropertyAlignItems(StyleResolverState&);
    static void applyValueCSSPropertyAlignItems(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyObjectPosition(StyleResolverState&);
    static void applyInheritCSSPropertyObjectPosition(StyleResolverState&);
    static void applyValueCSSPropertyObjectPosition(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyGridColumnGap(StyleResolverState&);
    static void applyInheritCSSPropertyGridColumnGap(StyleResolverState&);
    static void applyValueCSSPropertyGridColumnGap(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyScrollSnapDestination(StyleResolverState&);
    static void applyInheritCSSPropertyScrollSnapDestination(StyleResolverState&);
    static void applyValueCSSPropertyScrollSnapDestination(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitBoxFlexGroup(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitBoxFlexGroup(StyleResolverState&);
    static void applyValueCSSPropertyWebkitBoxFlexGroup(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyWebkitPerspectiveOriginX(StyleResolverState&);
    static void applyInheritCSSPropertyWebkitPerspectiveOriginX(StyleResolverState&);
    static void applyValueCSSPropertyWebkitPerspectiveOriginX(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontSizeAdjust(StyleResolverState&);
    static void applyInheritCSSPropertyFontSizeAdjust(StyleResolverState&);
    static void applyValueCSSPropertyFontSizeAdjust(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyBorderBottomColor(StyleResolverState&);
    static void applyInheritCSSPropertyBorderBottomColor(StyleResolverState&);
    static void applyValueCSSPropertyBorderBottomColor(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyFontSize(StyleResolverState&);
    static void applyInheritCSSPropertyFontSize(StyleResolverState&);
    static void applyValueCSSPropertyFontSize(StyleResolverState&, const CSSValue&);

    static void applyInitialCSSPropertyVisibility(StyleResolverState&);
    static void applyInheritCSSPropertyVisibility(StyleResolverState&);
    static void applyValueCSSPropertyVisibility(StyleResolverState&, const CSSValue&);

    static void applyValueCSSPropertyVariable(StyleResolverState&,
        const CSSValue&);
};

} // namespace blink

#endif
