#include "StyleBuilderFunctions.h"

#include "CSSValueKeywords.h"
#include "core/animation/css/CSSAnimationData.h"
#include "core/css/BasicShapeFunctions.h"
#include "core/css/CSSContentDistributionValue.h"
#include "core/css/CSSCustomIdentValue.h"
#include "core/css/CSSPrimitiveValueMappings.h"
#include "core/css/CSSURIValue.h"
#include "core/css/CSSValuePair.h"
#include "core/css/resolver/StyleResolverState.h"

namespace blink {

void StyleBuilderFunctions::applyInitialCSSPropertyVectorEffect(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setVectorEffect(SVGComputedStyle::initialVectorEffect());
}

void StyleBuilderFunctions::applyInheritCSSPropertyVectorEffect(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setVectorEffect(state.parentStyle()->svgStyle().vectorEffect());
}

void StyleBuilderFunctions::applyValueCSSPropertyVectorEffect(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setVectorEffect(toCSSIdentifierValue(value).convertTo<EVectorEffect>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFillRule(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setFillRule(SVGComputedStyle::initialFillRule());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFillRule(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setFillRule(state.parentStyle()->svgStyle().fillRule());
}

void StyleBuilderFunctions::applyValueCSSPropertyFillRule(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setFillRule(toCSSIdentifierValue(value).convertTo<WindRule>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontVariantNumeric(StyleResolverState& state)
{
    state.fontBuilder().setVariantNumeric(FontBuilder::initialVariantNumeric());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontVariantNumeric(StyleResolverState& state)
{
    state.fontBuilder().setVariantNumeric(state.parentFontDescription().variantNumeric());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontVariantNumeric(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setVariantNumeric(StyleBuilderConverter::convertFontVariantNumeric(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyCx(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setCx(SVGComputedStyle::initialCx());
}

void StyleBuilderFunctions::applyInheritCSSPropertyCx(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setCx(state.parentStyle()->svgStyle().cx());
}

void StyleBuilderFunctions::applyValueCSSPropertyCx(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setCx(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyCy(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setCy(SVGComputedStyle::initialCy());
}

void StyleBuilderFunctions::applyInheritCSSPropertyCy(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setCy(state.parentStyle()->svgStyle().cy());
}

void StyleBuilderFunctions::applyValueCSSPropertyCy(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setCy(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyShapeOutside(StyleResolverState& state)
{
    state.style()->setShapeOutside(ComputedStyle::initialShapeOutside());
}

void StyleBuilderFunctions::applyInheritCSSPropertyShapeOutside(StyleResolverState& state)
{
    state.style()->setShapeOutside(state.parentStyle()->shapeOutside());
}

void StyleBuilderFunctions::applyValueCSSPropertyShapeOutside(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setShapeOutside(StyleBuilderConverter::convertShapeValue(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitHyphenateCharacter(StyleResolverState& state)
{
    state.style()->setHyphenationString(ComputedStyle::initialHyphenationString());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitHyphenateCharacter(StyleResolverState& state)
{
    state.style()->setHyphenationString(state.parentStyle()->hyphenationString());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitHyphenateCharacter(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setHyphenationString(StyleBuilderConverter::convertString<CSSValueAuto>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxPack(StyleResolverState& state)
{
    state.style()->setBoxPack(ComputedStyle::initialBoxPack());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxPack(StyleResolverState& state)
{
    state.style()->setBoxPack(state.parentStyle()->boxPack());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxPack(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxPack(toCSSIdentifierValue(value).convertTo<EBoxPack>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMarginBottomCollapse(StyleResolverState& state)
{
    state.style()->setMarginAfterCollapse(ComputedStyle::initialMarginAfterCollapse());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMarginBottomCollapse(StyleResolverState& state)
{
    state.style()->setMarginAfterCollapse(state.parentStyle()->marginAfterCollapse());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMarginBottomCollapse(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMarginAfterCollapse(toCSSIdentifierValue(value).convertTo<EMarginCollapse>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOutlineWidth(StyleResolverState& state)
{
    state.style()->setOutlineWidth(ComputedStyle::initialOutlineWidth());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOutlineWidth(StyleResolverState& state)
{
    state.style()->setOutlineWidth(state.parentStyle()->outlineWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyOutlineWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOutlineWidth(StyleBuilderConverter::convertLineWidth<unsigned short>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyColumnRuleWidth(StyleResolverState& state)
{
    state.style()->setColumnRuleWidth(ComputedStyle::initialColumnRuleWidth());
}

void StyleBuilderFunctions::applyInheritCSSPropertyColumnRuleWidth(StyleResolverState& state)
{
    state.style()->setColumnRuleWidth(state.parentStyle()->columnRuleWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyColumnRuleWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setColumnRuleWidth(StyleBuilderConverter::convertLineWidth<unsigned short>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyStrokeOpacity(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeOpacity(SVGComputedStyle::initialStrokeOpacity());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStrokeOpacity(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeOpacity(state.parentStyle()->svgStyle().strokeOpacity());
}

void StyleBuilderFunctions::applyValueCSSPropertyStrokeOpacity(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setStrokeOpacity(StyleBuilderConverter::convertNumberOrPercentage(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyOffsetRotate(StyleResolverState& state)
{
    state.style()->setOffsetRotate(ComputedStyle::initialOffsetRotate());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOffsetRotate(StyleResolverState& state)
{
    state.style()->setOffsetRotate(state.parentStyle()->offsetRotate());
}

void StyleBuilderFunctions::applyValueCSSPropertyOffsetRotate(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOffsetRotate(StyleBuilderConverter::convertOffsetRotate(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontFamily(StyleResolverState& state)
{
    state.fontBuilder().setFamilyDescription(FontBuilder::initialFamilyDescription());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontFamily(StyleResolverState& state)
{
    state.fontBuilder().setFamilyDescription(state.parentFontDescription().getFamilyDescription());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontFamily(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setFamilyDescription(StyleBuilderConverter::convertFontFamily(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxFlex(StyleResolverState& state)
{
    state.style()->setBoxFlex(ComputedStyle::initialBoxFlex());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxFlex(StyleResolverState& state)
{
    state.style()->setBoxFlex(state.parentStyle()->boxFlex());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxFlex(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxFlex(toCSSPrimitiveValue(value).convertTo<float>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyContain(StyleResolverState& state)
{
    state.style()->setContain(ComputedStyle::initialContain());
}

void StyleBuilderFunctions::applyInheritCSSPropertyContain(StyleResolverState& state)
{
    state.style()->setContain(state.parentStyle()->contain());
}

void StyleBuilderFunctions::applyValueCSSPropertyContain(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setContain(StyleBuilderConverter::convertFlags<Containment>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderBottomStyle(StyleResolverState& state)
{
    state.style()->setBorderBottomStyle(ComputedStyle::initialBorderStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderBottomStyle(StyleResolverState& state)
{
    state.style()->setBorderBottomStyle(state.parentStyle()->borderBottomStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderBottomStyle(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderBottomStyle(toCSSIdentifierValue(value).convertTo<EBorderStyle>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyHeight(StyleResolverState& state)
{
    state.style()->setHeight(ComputedStyle::initialSize());
}

void StyleBuilderFunctions::applyInheritCSSPropertyHeight(StyleResolverState& state)
{
    state.style()->setHeight(state.parentStyle()->height());
}

void StyleBuilderFunctions::applyValueCSSPropertyHeight(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setHeight(StyleBuilderConverter::convertLengthSizing(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderImageSource(StyleResolverState& state)
{
    state.style()->setBorderImageSource(ComputedStyle::initialBorderImageSource());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderImageSource(StyleResolverState& state)
{
    state.style()->setBorderImageSource(state.parentStyle()->borderImageSource());
}

void StyleBuilderFunctions::applyInitialCSSPropertyPaintOrder(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setPaintOrder(SVGComputedStyle::initialPaintOrder());
}

void StyleBuilderFunctions::applyInheritCSSPropertyPaintOrder(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setPaintOrder(state.parentStyle()->svgStyle().paintOrder());
}

void StyleBuilderFunctions::applyValueCSSPropertyPaintOrder(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setPaintOrder(StyleBuilderConverter::convertPaintOrder(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextRendering(StyleResolverState& state)
{
    state.fontBuilder().setTextRendering(FontBuilder::initialTextRendering());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextRendering(StyleResolverState& state)
{
    state.fontBuilder().setTextRendering(state.parentFontDescription().textRendering());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextRendering(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setTextRendering(toCSSIdentifierValue(value).convertTo<TextRenderingMode>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderBottomLeftRadius(StyleResolverState& state)
{
    state.style()->setBorderBottomLeftRadius(ComputedStyle::initialBorderRadius());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderBottomLeftRadius(StyleResolverState& state)
{
    state.style()->setBorderBottomLeftRadius(state.parentStyle()->borderBottomLeftRadius());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderBottomLeftRadius(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderBottomLeftRadius(StyleBuilderConverter::convertRadius(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyColorInterpolation(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setColorInterpolation(SVGComputedStyle::initialColorInterpolation());
}

void StyleBuilderFunctions::applyInheritCSSPropertyColorInterpolation(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setColorInterpolation(state.parentStyle()->svgStyle().colorInterpolation());
}

void StyleBuilderFunctions::applyValueCSSPropertyColorInterpolation(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setColorInterpolation(toCSSIdentifierValue(value).convertTo<EColorInterpolation>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontVariationSettings(StyleResolverState& state)
{
    state.fontBuilder().setVariationSettings(FontBuilder::initialVariationSettings());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontVariationSettings(StyleResolverState& state)
{
    state.fontBuilder().setVariationSettings(state.parentFontDescription().variationSettings());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontVariationSettings(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setVariationSettings(StyleBuilderConverter::convertFontVariationSettings(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextDecorationLine(StyleResolverState& state)
{
    state.style()->setTextDecoration(ComputedStyle::initialTextDecoration());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextDecorationLine(StyleResolverState& state)
{
    state.style()->setTextDecoration(state.parentStyle()->getTextDecoration());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextDecorationLine(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextDecoration(StyleBuilderConverter::convertFlags<TextDecoration>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyFilter(StyleResolverState& state)
{
    state.style()->setFilter(ComputedStyle::initialFilter());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFilter(StyleResolverState& state)
{
    state.style()->setFilter(state.parentStyle()->filter());
}

void StyleBuilderFunctions::applyValueCSSPropertyFilter(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setFilter(StyleBuilderConverter::convertFilterOperations(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyShapeMargin(StyleResolverState& state)
{
    state.style()->setShapeMargin(ComputedStyle::initialShapeMargin());
}

void StyleBuilderFunctions::applyInheritCSSPropertyShapeMargin(StyleResolverState& state)
{
    state.style()->setShapeMargin(state.parentStyle()->shapeMargin());
}

void StyleBuilderFunctions::applyValueCSSPropertyShapeMargin(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setShapeMargin(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyScrollSnapType(StyleResolverState& state)
{
    state.style()->setScrollSnapType(ComputedStyle::initialScrollSnapType());
}

void StyleBuilderFunctions::applyInheritCSSPropertyScrollSnapType(StyleResolverState& state)
{
    state.style()->setScrollSnapType(state.parentStyle()->getScrollSnapType());
}

void StyleBuilderFunctions::applyValueCSSPropertyScrollSnapType(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setScrollSnapType(toCSSIdentifierValue(value).convertTo<ScrollSnapType>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyImageRendering(StyleResolverState& state)
{
    state.style()->setImageRendering(ComputedStyle::initialImageRendering());
}

void StyleBuilderFunctions::applyInheritCSSPropertyImageRendering(StyleResolverState& state)
{
    state.style()->setImageRendering(state.parentStyle()->imageRendering());
}

void StyleBuilderFunctions::applyValueCSSPropertyImageRendering(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setImageRendering(toCSSIdentifierValue(value).convertTo<EImageRendering>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyPaddingBottom(StyleResolverState& state)
{
    state.style()->setPaddingBottom(ComputedStyle::initialPadding());
}

void StyleBuilderFunctions::applyInheritCSSPropertyPaddingBottom(StyleResolverState& state)
{
    state.style()->setPaddingBottom(state.parentStyle()->paddingBottom());
}

void StyleBuilderFunctions::applyValueCSSPropertyPaddingBottom(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPaddingBottom(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyQuotes(StyleResolverState& state)
{
    state.style()->setQuotes(ComputedStyle::initialQuotes());
}

void StyleBuilderFunctions::applyInheritCSSPropertyQuotes(StyleResolverState& state)
{
    state.style()->setQuotes(state.parentStyle()->quotes());
}

void StyleBuilderFunctions::applyValueCSSPropertyQuotes(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setQuotes(StyleBuilderConverter::convertQuotes(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridAutoRows(StyleResolverState& state)
{
    state.style()->setGridAutoRows(ComputedStyle::initialGridAutoRows());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridAutoRows(StyleResolverState& state)
{
    state.style()->setGridAutoRows(state.parentStyle()->gridAutoRows());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridAutoRows(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setGridAutoRows(StyleBuilderConverter::convertGridTrackSizeList(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyClipPath(StyleResolverState& state)
{
    state.style()->setClipPath(ComputedStyle::initialClipPath());
}

void StyleBuilderFunctions::applyInheritCSSPropertyClipPath(StyleResolverState& state)
{
    state.style()->setClipPath(state.parentStyle()->clipPath());
}

void StyleBuilderFunctions::applyValueCSSPropertyClipPath(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setClipPath(StyleBuilderConverter::convertClipPath(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBreakBefore(StyleResolverState& state)
{
    state.style()->setBreakBefore(ComputedStyle::initialBreakBefore());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBreakBefore(StyleResolverState& state)
{
    state.style()->setBreakBefore(state.parentStyle()->breakBefore());
}

void StyleBuilderFunctions::applyValueCSSPropertyBreakBefore(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBreakBefore(toCSSIdentifierValue(value).convertTo<EBreak>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyObjectFit(StyleResolverState& state)
{
    state.style()->setObjectFit(ComputedStyle::initialObjectFit());
}

void StyleBuilderFunctions::applyInheritCSSPropertyObjectFit(StyleResolverState& state)
{
    state.style()->setObjectFit(state.parentStyle()->getObjectFit());
}

void StyleBuilderFunctions::applyValueCSSPropertyObjectFit(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setObjectFit(toCSSIdentifierValue(value).convertTo<ObjectFit>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyStopOpacity(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStopOpacity(SVGComputedStyle::initialStopOpacity());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStopOpacity(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStopOpacity(state.parentStyle()->svgStyle().stopOpacity());
}

void StyleBuilderFunctions::applyValueCSSPropertyStopOpacity(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setStopOpacity(StyleBuilderConverter::convertNumberOrPercentage(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxReflect(StyleResolverState& state)
{
    state.style()->setBoxReflect(ComputedStyle::initialBoxReflect());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxReflect(StyleResolverState& state)
{
    state.style()->setBoxReflect(state.parentStyle()->boxReflect());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxReflect(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxReflect(StyleBuilderConverter::convertBoxReflect(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderTopRightRadius(StyleResolverState& state)
{
    state.style()->setBorderTopRightRadius(ComputedStyle::initialBorderRadius());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderTopRightRadius(StyleResolverState& state)
{
    state.style()->setBorderTopRightRadius(state.parentStyle()->borderTopRightRadius());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderTopRightRadius(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderTopRightRadius(StyleBuilderConverter::convertRadius(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxDirection(StyleResolverState& state)
{
    state.style()->setBoxDirection(ComputedStyle::initialBoxDirection());
    state.style()->setBoxDirectionIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxDirection(StyleResolverState& state)
{
    state.style()->setBoxDirection(state.parentStyle()->boxDirection());
    state.style()->setBoxDirectionIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxDirection(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxDirection(toCSSIdentifierValue(value).convertTo<EBoxDirection>());
    state.style()->setBoxDirectionIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitUserModify(StyleResolverState& state)
{
    state.style()->setUserModify(ComputedStyle::initialUserModify());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitUserModify(StyleResolverState& state)
{
    state.style()->setUserModify(state.parentStyle()->userModify());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitUserModify(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setUserModify(toCSSIdentifierValue(value).convertTo<EUserModify>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxDecorationBreak(StyleResolverState& state)
{
    state.style()->setBoxDecorationBreak(ComputedStyle::initialBoxDecorationBreak());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxDecorationBreak(StyleResolverState& state)
{
    state.style()->setBoxDecorationBreak(state.parentStyle()->boxDecorationBreak());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxDecorationBreak(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxDecorationBreak(toCSSIdentifierValue(value).convertTo<EBoxDecorationBreak>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontKerning(StyleResolverState& state)
{
    state.fontBuilder().setKerning(FontBuilder::initialKerning());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontKerning(StyleResolverState& state)
{
    state.fontBuilder().setKerning(state.parentFontDescription().getKerning());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontKerning(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setKerning(toCSSIdentifierValue(value).convertTo<FontDescription::Kerning>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontWeight(StyleResolverState& state)
{
    state.fontBuilder().setWeight(FontBuilder::initialWeight());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontWeight(StyleResolverState& state)
{
    state.fontBuilder().setWeight(state.parentFontDescription().weight());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontWeight(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setWeight(StyleBuilderConverter::convertFontWeight(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyShapeImageThreshold(StyleResolverState& state)
{
    state.style()->setShapeImageThreshold(ComputedStyle::initialShapeImageThreshold());
}

void StyleBuilderFunctions::applyInheritCSSPropertyShapeImageThreshold(StyleResolverState& state)
{
    state.style()->setShapeImageThreshold(state.parentStyle()->shapeImageThreshold());
}

void StyleBuilderFunctions::applyValueCSSPropertyShapeImageThreshold(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setShapeImageThreshold(toCSSPrimitiveValue(value).convertTo<float>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyRy(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setRy(SVGComputedStyle::initialRy());
}

void StyleBuilderFunctions::applyInheritCSSPropertyRy(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setRy(state.parentStyle()->svgStyle().ry());
}

void StyleBuilderFunctions::applyValueCSSPropertyRy(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setRy(StyleBuilderConverter::convertLengthOrAuto(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyRx(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setRx(SVGComputedStyle::initialRx());
}

void StyleBuilderFunctions::applyInheritCSSPropertyRx(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setRx(state.parentStyle()->svgStyle().rx());
}

void StyleBuilderFunctions::applyValueCSSPropertyRx(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setRx(StyleBuilderConverter::convertLengthOrAuto(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyMarginRight(StyleResolverState& state)
{
    state.style()->setMarginRight(ComputedStyle::initialMargin());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMarginRight(StyleResolverState& state)
{
    state.style()->setMarginRight(state.parentStyle()->marginRight());
}

void StyleBuilderFunctions::applyValueCSSPropertyMarginRight(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMarginRight(StyleBuilderConverter::convertQuirkyLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitFontSmoothing(StyleResolverState& state)
{
    state.fontBuilder().setFontSmoothing(FontBuilder::initialFontSmoothing());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitFontSmoothing(StyleResolverState& state)
{
    state.fontBuilder().setFontSmoothing(state.parentFontDescription().fontSmoothing());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitFontSmoothing(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setFontSmoothing(toCSSIdentifierValue(value).convertTo<FontSmoothingMode>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBreakAfter(StyleResolverState& state)
{
    state.style()->setBreakAfter(ComputedStyle::initialBreakAfter());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBreakAfter(StyleResolverState& state)
{
    state.style()->setBreakAfter(state.parentStyle()->breakAfter());
}

void StyleBuilderFunctions::applyValueCSSPropertyBreakAfter(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBreakAfter(toCSSIdentifierValue(value).convertTo<EBreak>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOpacity(StyleResolverState& state)
{
    state.style()->setOpacity(ComputedStyle::initialOpacity());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOpacity(StyleResolverState& state)
{
    state.style()->setOpacity(state.parentStyle()->opacity());
}

void StyleBuilderFunctions::applyValueCSSPropertyOpacity(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOpacity(toCSSPrimitiveValue(value).convertTo<float>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyDominantBaseline(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setDominantBaseline(SVGComputedStyle::initialDominantBaseline());
}

void StyleBuilderFunctions::applyInheritCSSPropertyDominantBaseline(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setDominantBaseline(state.parentStyle()->svgStyle().dominantBaseline());
}

void StyleBuilderFunctions::applyValueCSSPropertyDominantBaseline(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setDominantBaseline(toCSSIdentifierValue(value).convertTo<EDominantBaseline>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyAlignSelf(StyleResolverState& state)
{
    state.style()->setAlignSelf(ComputedStyle::initialSelfAlignment());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAlignSelf(StyleResolverState& state)
{
    state.style()->setAlignSelf(state.parentStyle()->alignSelf());
}

void StyleBuilderFunctions::applyValueCSSPropertyAlignSelf(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setAlignSelf(StyleBuilderConverter::convertSelfOrDefaultAlignmentData(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyClear(StyleResolverState& state)
{
    state.style()->setClear(ComputedStyle::initialClear());
}

void StyleBuilderFunctions::applyInheritCSSPropertyClear(StyleResolverState& state)
{
    state.style()->setClear(state.parentStyle()->clear());
}

void StyleBuilderFunctions::applyValueCSSPropertyClear(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setClear(toCSSIdentifierValue(value).convertTo<EClear>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyPaddingRight(StyleResolverState& state)
{
    state.style()->setPaddingRight(ComputedStyle::initialPadding());
}

void StyleBuilderFunctions::applyInheritCSSPropertyPaddingRight(StyleResolverState& state)
{
    state.style()->setPaddingRight(state.parentStyle()->paddingRight());
}

void StyleBuilderFunctions::applyValueCSSPropertyPaddingRight(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPaddingRight(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextCombineUpright(StyleResolverState& state)
{
    state.style()->setTextCombine(ComputedStyle::initialTextCombine());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextCombineUpright(StyleResolverState& state)
{
    state.style()->setTextCombine(state.parentStyle()->getTextCombine());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextCombineUpright(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextCombine(toCSSIdentifierValue(value).convertTo<TextCombine>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyTransformStyle(StyleResolverState& state)
{
    state.style()->setTransformStyle3D(ComputedStyle::initialTransformStyle3D());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTransformStyle(StyleResolverState& state)
{
    state.style()->setTransformStyle3D(state.parentStyle()->transformStyle3D());
}

void StyleBuilderFunctions::applyValueCSSPropertyTransformStyle(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTransformStyle3D(toCSSIdentifierValue(value).convertTo<ETransformStyle3D>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBorderHorizontalSpacing(StyleResolverState& state)
{
    state.style()->setHorizontalBorderSpacing(ComputedStyle::initialHorizontalBorderSpacing());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBorderHorizontalSpacing(StyleResolverState& state)
{
    state.style()->setHorizontalBorderSpacing(state.parentStyle()->horizontalBorderSpacing());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBorderHorizontalSpacing(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setHorizontalBorderSpacing(StyleBuilderConverter::convertComputedLength<short>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTapHighlightColor(StyleResolverState& state)
{
    state.style()->setTapHighlightColor(ComputedStyle::initialTapHighlightColor());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTapHighlightColor(StyleResolverState& state)
{
    state.style()->setTapHighlightColor(state.parentStyle()->tapHighlightColor());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTapHighlightColor(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTapHighlightColor(StyleBuilderConverter::convertColor(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyCaptionSide(StyleResolverState& state)
{
    state.style()->setCaptionSide(ComputedStyle::initialCaptionSide());
    state.style()->setCaptionSideIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyCaptionSide(StyleResolverState& state)
{
    state.style()->setCaptionSide(state.parentStyle()->captionSide());
    state.style()->setCaptionSideIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyCaptionSide(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setCaptionSide(toCSSIdentifierValue(value).convertTo<ECaptionSide>());
    state.style()->setCaptionSideIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitPrintColorAdjust(StyleResolverState& state)
{
    state.style()->setPrintColorAdjust(ComputedStyle::initialPrintColorAdjust());
    state.style()->setPrintColorAdjustIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitPrintColorAdjust(StyleResolverState& state)
{
    state.style()->setPrintColorAdjust(state.parentStyle()->printColorAdjust());
    state.style()->setPrintColorAdjustIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitPrintColorAdjust(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPrintColorAdjust(toCSSIdentifierValue(value).convertTo<EPrintColorAdjust>());
    state.style()->setPrintColorAdjustIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyStrokeDasharray(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeDashArray(SVGComputedStyle::initialStrokeDashArray());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStrokeDasharray(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeDashArray(state.parentStyle()->svgStyle().strokeDashArray());
}

void StyleBuilderFunctions::applyValueCSSPropertyStrokeDasharray(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setStrokeDashArray(StyleBuilderConverter::convertStrokeDasharray(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyFlexBasis(StyleResolverState& state)
{
    state.style()->setFlexBasis(ComputedStyle::initialFlexBasis());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFlexBasis(StyleResolverState& state)
{
    state.style()->setFlexBasis(state.parentStyle()->flexBasis());
}

void StyleBuilderFunctions::applyValueCSSPropertyFlexBasis(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setFlexBasis(StyleBuilderConverter::convertLengthOrAuto(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWidows(StyleResolverState& state)
{
    state.style()->setWidows(ComputedStyle::initialWidows());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWidows(StyleResolverState& state)
{
    state.style()->setWidows(state.parentStyle()->widows());
}

void StyleBuilderFunctions::applyValueCSSPropertyWidows(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setWidows(toCSSPrimitiveValue(value).convertTo<short>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitRubyPosition(StyleResolverState& state)
{
    state.style()->setRubyPosition(ComputedStyle::initialRubyPosition());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitRubyPosition(StyleResolverState& state)
{
    state.style()->setRubyPosition(state.parentStyle()->getRubyPosition());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitRubyPosition(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setRubyPosition(toCSSIdentifierValue(value).convertTo<RubyPosition>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFlexShrink(StyleResolverState& state)
{
    state.style()->setFlexShrink(ComputedStyle::initialFlexShrink());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFlexShrink(StyleResolverState& state)
{
    state.style()->setFlexShrink(state.parentStyle()->flexShrink());
}

void StyleBuilderFunctions::applyValueCSSPropertyFlexShrink(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setFlexShrink(toCSSPrimitiveValue(value).convertTo<float>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTransformOriginY(StyleResolverState& state)
{
    state.style()->setTransformOriginY(ComputedStyle::initialTransformOriginY());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTransformOriginY(StyleResolverState& state)
{
    state.style()->setTransformOriginY(state.parentStyle()->transformOriginY());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTransformOriginY(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTransformOriginY(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTransformOriginX(StyleResolverState& state)
{
    state.style()->setTransformOriginX(ComputedStyle::initialTransformOriginX());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTransformOriginX(StyleResolverState& state)
{
    state.style()->setTransformOriginX(state.parentStyle()->transformOriginX());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTransformOriginX(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTransformOriginX(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTransform(StyleResolverState& state)
{
    state.style()->setTransform(ComputedStyle::initialTransform());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTransform(StyleResolverState& state)
{
    state.style()->setTransform(state.parentStyle()->transform());
}

void StyleBuilderFunctions::applyValueCSSPropertyTransform(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTransform(StyleBuilderConverter::convertTransformOperations(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyScrollBehavior(StyleResolverState& state)
{
    state.style()->setScrollBehavior(ComputedStyle::initialScrollBehavior());
}

void StyleBuilderFunctions::applyInheritCSSPropertyScrollBehavior(StyleResolverState& state)
{
    state.style()->setScrollBehavior(state.parentStyle()->getScrollBehavior());
}

void StyleBuilderFunctions::applyValueCSSPropertyScrollBehavior(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setScrollBehavior(toCSSIdentifierValue(value).convertTo<ScrollBehavior>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridAutoFlow(StyleResolverState& state)
{
    state.style()->setGridAutoFlow(ComputedStyle::initialGridAutoFlow());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridAutoFlow(StyleResolverState& state)
{
    state.style()->setGridAutoFlow(state.parentStyle()->getGridAutoFlow());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridAutoFlow(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setGridAutoFlow(StyleBuilderConverter::convertGridAutoFlow(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTextEmphasisPosition(StyleResolverState& state)
{
    state.style()->setTextEmphasisPosition(ComputedStyle::initialTextEmphasisPosition());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTextEmphasisPosition(StyleResolverState& state)
{
    state.style()->setTextEmphasisPosition(state.parentStyle()->getTextEmphasisPosition());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTextEmphasisPosition(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextEmphasisPosition(toCSSIdentifierValue(value).convertTo<TextEmphasisPosition>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyStopColor(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStopColor(SVGComputedStyle::initialStopColor());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStopColor(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStopColor(state.parentStyle()->svgStyle().stopColor());
}

void StyleBuilderFunctions::applyValueCSSPropertyStopColor(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setStopColor(StyleBuilderConverter::convertColor(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitLineClamp(StyleResolverState& state)
{
    state.style()->setLineClamp(ComputedStyle::initialLineClamp());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitLineClamp(StyleResolverState& state)
{
    state.style()->setLineClamp(state.parentStyle()->lineClamp());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitLineClamp(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setLineClamp(toCSSPrimitiveValue(value).convertTo<LineClampValue>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyJustifySelf(StyleResolverState& state)
{
    state.style()->setJustifySelf(ComputedStyle::initialSelfAlignment());
}

void StyleBuilderFunctions::applyInheritCSSPropertyJustifySelf(StyleResolverState& state)
{
    state.style()->setJustifySelf(state.parentStyle()->justifySelf());
}

void StyleBuilderFunctions::applyValueCSSPropertyJustifySelf(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setJustifySelf(StyleBuilderConverter::convertSelfOrDefaultAlignmentData(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextJustify(StyleResolverState& state)
{
    state.style()->setTextJustify(ComputedStyle::initialTextJustify());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextJustify(StyleResolverState& state)
{
    state.style()->setTextJustify(state.parentStyle()->getTextJustify());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextJustify(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextJustify(toCSSIdentifierValue(value).convertTo<TextJustify>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWordSpacing(StyleResolverState& state)
{
    state.style()->setWordSpacing(ComputedStyle::initialLetterWordSpacing());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWordSpacing(StyleResolverState& state)
{
    state.style()->setWordSpacing(state.parentStyle()->wordSpacing());
}

void StyleBuilderFunctions::applyValueCSSPropertyWordSpacing(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setWordSpacing(StyleBuilderConverter::convertSpacing(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyPerspectiveOrigin(StyleResolverState& state)
{
    state.style()->setPerspectiveOrigin(ComputedStyle::initialPerspectiveOrigin());
}

void StyleBuilderFunctions::applyInheritCSSPropertyPerspectiveOrigin(StyleResolverState& state)
{
    state.style()->setPerspectiveOrigin(state.parentStyle()->perspectiveOrigin());
}

void StyleBuilderFunctions::applyValueCSSPropertyPerspectiveOrigin(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPerspectiveOrigin(StyleBuilderConverter::convertPosition(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextAnchor(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setTextAnchor(SVGComputedStyle::initialTextAnchor());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextAnchor(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setTextAnchor(state.parentStyle()->svgStyle().textAnchor());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextAnchor(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setTextAnchor(toCSSIdentifierValue(value).convertTo<ETextAnchor>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontStyle(StyleResolverState& state)
{
    state.fontBuilder().setStyle(FontBuilder::initialStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontStyle(StyleResolverState& state)
{
    state.fontBuilder().setStyle(state.parentFontDescription().style());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontStyle(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setStyle(toCSSIdentifierValue(value).convertTo<FontStyle>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderBottomRightRadius(StyleResolverState& state)
{
    state.style()->setBorderBottomRightRadius(ComputedStyle::initialBorderRadius());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderBottomRightRadius(StyleResolverState& state)
{
    state.style()->setBorderBottomRightRadius(state.parentStyle()->borderBottomRightRadius());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderBottomRightRadius(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderBottomRightRadius(StyleBuilderConverter::convertRadius(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderRightWidth(StyleResolverState& state)
{
    state.style()->setBorderRightWidth(ComputedStyle::initialBorderWidth());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderRightWidth(StyleResolverState& state)
{
    state.style()->setBorderRightWidth(state.parentStyle()->borderRightWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderRightWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderRightWidth(StyleBuilderConverter::convertLineWidth<unsigned>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderTopLeftRadius(StyleResolverState& state)
{
    state.style()->setBorderTopLeftRadius(ComputedStyle::initialBorderRadius());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderTopLeftRadius(StyleResolverState& state)
{
    state.style()->setBorderTopLeftRadius(state.parentStyle()->borderTopLeftRadius());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderTopLeftRadius(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderTopLeftRadius(StyleBuilderConverter::convertRadius(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWritingMode(StyleResolverState& state)
{
    state.style()->setWritingMode(ComputedStyle::initialWritingMode());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWritingMode(StyleResolverState& state)
{
    state.style()->setWritingMode(state.parentStyle()->getWritingMode());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTextSecurity(StyleResolverState& state)
{
    state.style()->setTextSecurity(ComputedStyle::initialTextSecurity());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTextSecurity(StyleResolverState& state)
{
    state.style()->setTextSecurity(state.parentStyle()->textSecurity());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTextSecurity(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextSecurity(toCSSIdentifierValue(value).convertTo<ETextSecurity>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderLeftWidth(StyleResolverState& state)
{
    state.style()->setBorderLeftWidth(ComputedStyle::initialBorderWidth());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderLeftWidth(StyleResolverState& state)
{
    state.style()->setBorderLeftWidth(state.parentStyle()->borderLeftWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderLeftWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderLeftWidth(StyleBuilderConverter::convertLineWidth<unsigned>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitLineBreak(StyleResolverState& state)
{
    state.style()->setLineBreak(ComputedStyle::initialLineBreak());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitLineBreak(StyleResolverState& state)
{
    state.style()->setLineBreak(state.parentStyle()->getLineBreak());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitLineBreak(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setLineBreak(toCSSIdentifierValue(value).convertTo<LineBreak>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyIsolation(StyleResolverState& state)
{
    state.style()->setIsolation(ComputedStyle::initialIsolation());
}

void StyleBuilderFunctions::applyInheritCSSPropertyIsolation(StyleResolverState& state)
{
    state.style()->setIsolation(state.parentStyle()->isolation());
}

void StyleBuilderFunctions::applyValueCSSPropertyIsolation(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setIsolation(toCSSIdentifierValue(value).convertTo<EIsolation>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFillOpacity(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setFillOpacity(SVGComputedStyle::initialFillOpacity());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFillOpacity(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setFillOpacity(state.parentStyle()->svgStyle().fillOpacity());
}

void StyleBuilderFunctions::applyValueCSSPropertyFillOpacity(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setFillOpacity(StyleBuilderConverter::convertNumberOrPercentage(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderTopWidth(StyleResolverState& state)
{
    state.style()->setBorderTopWidth(ComputedStyle::initialBorderWidth());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderTopWidth(StyleResolverState& state)
{
    state.style()->setBorderTopWidth(state.parentStyle()->borderTopWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderTopWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderTopWidth(StyleBuilderConverter::convertLineWidth<unsigned>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBottom(StyleResolverState& state)
{
    state.style()->setBottom(ComputedStyle::initialOffset());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBottom(StyleResolverState& state)
{
    state.style()->setBottom(state.parentStyle()->bottom());
}

void StyleBuilderFunctions::applyValueCSSPropertyBottom(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBottom(StyleBuilderConverter::convertLengthOrAuto(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderCollapse(StyleResolverState& state)
{
    state.style()->setBorderCollapse(ComputedStyle::initialBorderCollapse());
    state.style()->setBorderCollapseIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderCollapse(StyleResolverState& state)
{
    state.style()->setBorderCollapse(state.parentStyle()->borderCollapse());
    state.style()->setBorderCollapseIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderCollapse(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderCollapse(toCSSIdentifierValue(value).convertTo<EBorderCollapse>());
    state.style()->setBorderCollapseIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyTop(StyleResolverState& state)
{
    state.style()->setTop(ComputedStyle::initialOffset());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTop(StyleResolverState& state)
{
    state.style()->setTop(state.parentStyle()->top());
}

void StyleBuilderFunctions::applyValueCSSPropertyTop(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTop(StyleBuilderConverter::convertLengthOrAuto(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyScrollSnapPointsX(StyleResolverState& state)
{
    state.style()->setScrollSnapPointsX(ComputedStyle::initialScrollSnapPointsX());
}

void StyleBuilderFunctions::applyInheritCSSPropertyScrollSnapPointsX(StyleResolverState& state)
{
    state.style()->setScrollSnapPointsX(state.parentStyle()->scrollSnapPointsX());
}

void StyleBuilderFunctions::applyValueCSSPropertyScrollSnapPointsX(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setScrollSnapPointsX(StyleBuilderConverter::convertSnapPoints(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyScrollSnapPointsY(StyleResolverState& state)
{
    state.style()->setScrollSnapPointsY(ComputedStyle::initialScrollSnapPointsY());
}

void StyleBuilderFunctions::applyInheritCSSPropertyScrollSnapPointsY(StyleResolverState& state)
{
    state.style()->setScrollSnapPointsY(state.parentStyle()->scrollSnapPointsY());
}

void StyleBuilderFunctions::applyValueCSSPropertyScrollSnapPointsY(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setScrollSnapPointsY(StyleBuilderConverter::convertSnapPoints(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyUnicodeBidi(StyleResolverState& state)
{
    state.style()->setUnicodeBidi(ComputedStyle::initialUnicodeBidi());
}

void StyleBuilderFunctions::applyInheritCSSPropertyUnicodeBidi(StyleResolverState& state)
{
    state.style()->setUnicodeBidi(state.parentStyle()->getUnicodeBidi());
}

void StyleBuilderFunctions::applyValueCSSPropertyUnicodeBidi(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setUnicodeBidi(toCSSIdentifierValue(value).convertTo<UnicodeBidi>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitWritingMode(StyleResolverState& state)
{
    state.style()->setWritingMode(ComputedStyle::initialWritingMode());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitWritingMode(StyleResolverState& state)
{
    state.style()->setWritingMode(state.parentStyle()->getWritingMode());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFloat(StyleResolverState& state)
{
    state.style()->setFloating(ComputedStyle::initialFloating());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFloat(StyleResolverState& state)
{
    state.style()->setFloating(state.parentStyle()->floating());
}

void StyleBuilderFunctions::applyValueCSSPropertyFloat(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setFloating(toCSSIdentifierValue(value).convertTo<EFloat>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWordWrap(StyleResolverState& state)
{
    state.style()->setOverflowWrap(ComputedStyle::initialOverflowWrap());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWordWrap(StyleResolverState& state)
{
    state.style()->setOverflowWrap(state.parentStyle()->overflowWrap());
}

void StyleBuilderFunctions::applyValueCSSPropertyWordWrap(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOverflowWrap(toCSSIdentifierValue(value).convertTo<EOverflowWrap>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyTransformOrigin(StyleResolverState& state)
{
    state.style()->setTransformOrigin(ComputedStyle::initialTransformOrigin());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTransformOrigin(StyleResolverState& state)
{
    state.style()->setTransformOrigin(state.parentStyle()->transformOrigin());
}

void StyleBuilderFunctions::applyValueCSSPropertyTransformOrigin(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTransformOrigin(StyleBuilderConverter::convertTransformOrigin(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitRtlOrdering(StyleResolverState& state)
{
    state.style()->setRtlOrdering(ComputedStyle::initialRtlOrdering());
    state.style()->setRtlOrderingIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitRtlOrdering(StyleResolverState& state)
{
    state.style()->setRtlOrdering(state.parentStyle()->rtlOrdering());
    state.style()->setRtlOrderingIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitRtlOrdering(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setRtlOrdering(toCSSIdentifierValue(value).convertTo<EOrder>());
    state.style()->setRtlOrderingIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyMarginTop(StyleResolverState& state)
{
    state.style()->setMarginTop(ComputedStyle::initialMargin());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMarginTop(StyleResolverState& state)
{
    state.style()->setMarginTop(state.parentStyle()->marginTop());
}

void StyleBuilderFunctions::applyValueCSSPropertyMarginTop(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMarginTop(StyleBuilderConverter::convertQuirkyLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyMaxWidth(StyleResolverState& state)
{
    state.style()->setMaxWidth(ComputedStyle::initialMaxSize());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMaxWidth(StyleResolverState& state)
{
    state.style()->setMaxWidth(state.parentStyle()->maxWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyMaxWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMaxWidth(StyleBuilderConverter::convertLengthMaxSizing(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextShadow(StyleResolverState& state)
{
    state.style()->setTextShadow(ComputedStyle::initialTextShadow());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextShadow(StyleResolverState& state)
{
    state.style()->setTextShadow(state.parentStyle()->textShadow());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextShadow(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextShadow(StyleBuilderConverter::convertShadowList(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontVariantCaps(StyleResolverState& state)
{
    state.fontBuilder().setVariantCaps(FontBuilder::initialVariantCaps());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontVariantCaps(StyleResolverState& state)
{
    state.fontBuilder().setVariantCaps(state.parentFontDescription().variantCaps());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontVariantCaps(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setVariantCaps(StyleBuilderConverter::convertFontVariantCaps(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxOrdinalGroup(StyleResolverState& state)
{
    state.style()->setBoxOrdinalGroup(ComputedStyle::initialBoxOrdinalGroup());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxOrdinalGroup(StyleResolverState& state)
{
    state.style()->setBoxOrdinalGroup(state.parentStyle()->boxOrdinalGroup());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxOrdinalGroup(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxOrdinalGroup(toCSSPrimitiveValue(value).convertTo<unsigned int>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyColumnFill(StyleResolverState& state)
{
    state.style()->setColumnFill(ComputedStyle::initialColumnFill());
}

void StyleBuilderFunctions::applyInheritCSSPropertyColumnFill(StyleResolverState& state)
{
    state.style()->setColumnFill(state.parentStyle()->getColumnFill());
}

void StyleBuilderFunctions::applyValueCSSPropertyColumnFill(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setColumnFill(toCSSIdentifierValue(value).convertTo<ColumnFill>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOverflowX(StyleResolverState& state)
{
    state.style()->setOverflowX(ComputedStyle::initialOverflowX());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOverflowX(StyleResolverState& state)
{
    state.style()->setOverflowX(state.parentStyle()->overflowX());
}

void StyleBuilderFunctions::applyValueCSSPropertyOverflowX(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOverflowX(toCSSIdentifierValue(value).convertTo<EOverflow>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOverflowY(StyleResolverState& state)
{
    state.style()->setOverflowY(ComputedStyle::initialOverflowY());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOverflowY(StyleResolverState& state)
{
    state.style()->setOverflowY(state.parentStyle()->overflowY());
}

void StyleBuilderFunctions::applyValueCSSPropertyOverflowY(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOverflowY(toCSSIdentifierValue(value).convertTo<EOverflow>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyHyphens(StyleResolverState& state)
{
    state.style()->setHyphens(ComputedStyle::initialHyphens());
}

void StyleBuilderFunctions::applyInheritCSSPropertyHyphens(StyleResolverState& state)
{
    state.style()->setHyphens(state.parentStyle()->getHyphens());
}

void StyleBuilderFunctions::applyValueCSSPropertyHyphens(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setHyphens(toCSSIdentifierValue(value).convertTo<Hyphens>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextSizeAdjust(StyleResolverState& state)
{
    state.style()->setTextSizeAdjust(ComputedStyle::initialTextSizeAdjust());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextSizeAdjust(StyleResolverState& state)
{
    state.style()->setTextSizeAdjust(state.parentStyle()->getTextSizeAdjust());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextSizeAdjust(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextSizeAdjust(StyleBuilderConverter::convertTextSizeAdjust(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyPerspective(StyleResolverState& state)
{
    state.style()->setPerspective(ComputedStyle::initialPerspective());
}

void StyleBuilderFunctions::applyInheritCSSPropertyPerspective(StyleResolverState& state)
{
    state.style()->setPerspective(state.parentStyle()->perspective());
}

void StyleBuilderFunctions::applyValueCSSPropertyPerspective(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPerspective(StyleBuilderConverter::convertPerspective(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyUserSelect(StyleResolverState& state)
{
    state.style()->setUserSelect(ComputedStyle::initialUserSelect());
}

void StyleBuilderFunctions::applyInheritCSSPropertyUserSelect(StyleResolverState& state)
{
    state.style()->setUserSelect(state.parentStyle()->userSelect());
}

void StyleBuilderFunctions::applyValueCSSPropertyUserSelect(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setUserSelect(toCSSIdentifierValue(value).convertTo<EUserSelect>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyLineHeight(StyleResolverState& state)
{
    state.style()->setLineHeight(ComputedStyle::initialLineHeight());
}

void StyleBuilderFunctions::applyInheritCSSPropertyLineHeight(StyleResolverState& state)
{
    state.style()->setLineHeight(state.parentStyle()->specifiedLineHeight());
}

void StyleBuilderFunctions::applyValueCSSPropertyLineHeight(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setLineHeight(StyleBuilderConverter::convertLineHeight(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyOrder(StyleResolverState& state)
{
    state.style()->setOrder(ComputedStyle::initialOrder());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOrder(StyleResolverState& state)
{
    state.style()->setOrder(state.parentStyle()->order());
}

void StyleBuilderFunctions::applyValueCSSPropertyOrder(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOrder(toCSSPrimitiveValue(value).convertTo<int>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxAlign(StyleResolverState& state)
{
    state.style()->setBoxAlign(ComputedStyle::initialBoxAlign());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxAlign(StyleResolverState& state)
{
    state.style()->setBoxAlign(state.parentStyle()->boxAlign());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxAlign(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxAlign(toCSSIdentifierValue(value).convertTo<EBoxAlignment>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyScale(StyleResolverState& state)
{
    state.style()->setScale(ComputedStyle::initialScale());
}

void StyleBuilderFunctions::applyInheritCSSPropertyScale(StyleResolverState& state)
{
    state.style()->setScale(state.parentStyle()->scale());
}

void StyleBuilderFunctions::applyValueCSSPropertyScale(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setScale(StyleBuilderConverter::convertScale(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridAutoColumns(StyleResolverState& state)
{
    state.style()->setGridAutoColumns(ComputedStyle::initialGridAutoColumns());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridAutoColumns(StyleResolverState& state)
{
    state.style()->setGridAutoColumns(state.parentStyle()->gridAutoColumns());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridAutoColumns(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setGridAutoColumns(StyleBuilderConverter::convertGridTrackSizeList(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridRowStart(StyleResolverState& state)
{
    state.style()->setGridRowStart(ComputedStyle::initialGridRowStart());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridRowStart(StyleResolverState& state)
{
    state.style()->setGridRowStart(state.parentStyle()->gridRowStart());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridRowStart(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setGridRowStart(StyleBuilderConverter::convertGridPosition(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTextStrokeWidth(StyleResolverState& state)
{
    state.style()->setTextStrokeWidth(ComputedStyle::initialTextStrokeWidth());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTextStrokeWidth(StyleResolverState& state)
{
    state.style()->setTextStrokeWidth(state.parentStyle()->textStrokeWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTextStrokeWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextStrokeWidth(StyleBuilderConverter::convertTextStrokeWidth(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyStrokeDashoffset(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeDashOffset(SVGComputedStyle::initialStrokeDashOffset());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStrokeDashoffset(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeDashOffset(state.parentStyle()->svgStyle().strokeDashOffset());
}

void StyleBuilderFunctions::applyValueCSSPropertyStrokeDashoffset(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setStrokeDashOffset(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyPosition(StyleResolverState& state)
{
    state.style()->setPosition(ComputedStyle::initialPosition());
}

void StyleBuilderFunctions::applyValueCSSPropertyPosition(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPosition(toCSSIdentifierValue(value).convertTo<EPosition>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontStretch(StyleResolverState& state)
{
    state.fontBuilder().setStretch(FontBuilder::initialStretch());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontStretch(StyleResolverState& state)
{
    state.fontBuilder().setStretch(state.parentFontDescription().stretch());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontStretch(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setStretch(toCSSIdentifierValue(value).convertTo<FontStretch>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyMixBlendMode(StyleResolverState& state)
{
    state.style()->setBlendMode(ComputedStyle::initialBlendMode());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMixBlendMode(StyleResolverState& state)
{
    state.style()->setBlendMode(state.parentStyle()->blendMode());
}

void StyleBuilderFunctions::applyValueCSSPropertyMixBlendMode(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBlendMode(toCSSIdentifierValue(value).convertTo<blink::WebBlendMode>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBaselineShift(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setBaselineShift(SVGComputedStyle::initialBaselineShift());
}

void StyleBuilderFunctions::applyInitialCSSPropertyPaddingLeft(StyleResolverState& state)
{
    state.style()->setPaddingLeft(ComputedStyle::initialPadding());
}

void StyleBuilderFunctions::applyInheritCSSPropertyPaddingLeft(StyleResolverState& state)
{
    state.style()->setPaddingLeft(state.parentStyle()->paddingLeft());
}

void StyleBuilderFunctions::applyValueCSSPropertyPaddingLeft(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPaddingLeft(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWhiteSpace(StyleResolverState& state)
{
    state.style()->setWhiteSpace(ComputedStyle::initialWhiteSpace());
    state.style()->setWhiteSpaceIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWhiteSpace(StyleResolverState& state)
{
    state.style()->setWhiteSpace(state.parentStyle()->whiteSpace());
    state.style()->setWhiteSpaceIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyWhiteSpace(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setWhiteSpace(toCSSIdentifierValue(value).convertTo<EWhiteSpace>());
    state.style()->setWhiteSpaceIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyOverflowWrap(StyleResolverState& state)
{
    state.style()->setOverflowWrap(ComputedStyle::initialOverflowWrap());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOverflowWrap(StyleResolverState& state)
{
    state.style()->setOverflowWrap(state.parentStyle()->overflowWrap());
}

void StyleBuilderFunctions::applyValueCSSPropertyOverflowWrap(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOverflowWrap(toCSSIdentifierValue(value).convertTo<EOverflowWrap>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyVerticalAlign(StyleResolverState& state)
{
    state.style()->setVerticalAlign(ComputedStyle::initialVerticalAlign());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitLocale(StyleResolverState& state)
{
    state.fontBuilder().setLocale(FontBuilder::initialLocale());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitLocale(StyleResolverState& state)
{
    state.fontBuilder().setLocale(state.parentFontDescription().locale());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMarginAfterCollapse(StyleResolverState& state)
{
    state.style()->setMarginAfterCollapse(ComputedStyle::initialMarginAfterCollapse());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMarginAfterCollapse(StyleResolverState& state)
{
    state.style()->setMarginAfterCollapse(state.parentStyle()->marginAfterCollapse());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMarginAfterCollapse(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMarginAfterCollapse(toCSSIdentifierValue(value).convertTo<EMarginCollapse>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOffsetPosition(StyleResolverState& state)
{
    state.style()->setOffsetPosition(ComputedStyle::initialOffsetPosition());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOffsetPosition(StyleResolverState& state)
{
    state.style()->setOffsetPosition(state.parentStyle()->offsetPosition());
}

void StyleBuilderFunctions::applyValueCSSPropertyOffsetPosition(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOffsetPosition(StyleBuilderConverter::convertPositionOrAuto(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackdropFilter(StyleResolverState& state)
{
    state.style()->setBackdropFilter(ComputedStyle::initialBackdropFilter());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackdropFilter(StyleResolverState& state)
{
    state.style()->setBackdropFilter(state.parentStyle()->backdropFilter());
}

void StyleBuilderFunctions::applyValueCSSPropertyBackdropFilter(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBackdropFilter(StyleBuilderConverter::convertFilterOperations(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyMarkerEnd(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMarkerEndResource(SVGComputedStyle::initialMarkerEndResource());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMarkerEnd(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMarkerEndResource(state.parentStyle()->svgStyle().markerEndResource());
}

void StyleBuilderFunctions::applyValueCSSPropertyMarkerEnd(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setMarkerEndResource(StyleBuilderConverter::convertFragmentIdentifier(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxLines(StyleResolverState& state)
{
    state.style()->setBoxLines(ComputedStyle::initialBoxLines());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxLines(StyleResolverState& state)
{
    state.style()->setBoxLines(state.parentStyle()->boxLines());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxLines(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxLines(toCSSIdentifierValue(value).convertTo<EBoxLines>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOffsetAnchor(StyleResolverState& state)
{
    state.style()->setOffsetAnchor(ComputedStyle::initialOffsetAnchor());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOffsetAnchor(StyleResolverState& state)
{
    state.style()->setOffsetAnchor(state.parentStyle()->offsetAnchor());
}

void StyleBuilderFunctions::applyValueCSSPropertyOffsetAnchor(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOffsetAnchor(StyleBuilderConverter::convertPositionOrAuto(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyColumnSpan(StyleResolverState& state)
{
    state.style()->setColumnSpan(ComputedStyle::initialColumnSpan());
}

void StyleBuilderFunctions::applyInheritCSSPropertyColumnSpan(StyleResolverState& state)
{
    state.style()->setColumnSpan(state.parentStyle()->getColumnSpan());
}

void StyleBuilderFunctions::applyValueCSSPropertyColumnSpan(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setColumnSpan(toCSSIdentifierValue(value).convertTo<ColumnSpan>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyTableLayout(StyleResolverState& state)
{
    state.style()->setTableLayout(ComputedStyle::initialTableLayout());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTableLayout(StyleResolverState& state)
{
    state.style()->setTableLayout(state.parentStyle()->tableLayout());
}

void StyleBuilderFunctions::applyValueCSSPropertyTableLayout(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTableLayout(toCSSIdentifierValue(value).convertTo<ETableLayout>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridRowGap(StyleResolverState& state)
{
    state.style()->setGridRowGap(ComputedStyle::initialGridRowGap());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridRowGap(StyleResolverState& state)
{
    state.style()->setGridRowGap(state.parentStyle()->gridRowGap());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridRowGap(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setGridRowGap(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderRightStyle(StyleResolverState& state)
{
    state.style()->setBorderRightStyle(ComputedStyle::initialBorderStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderRightStyle(StyleResolverState& state)
{
    state.style()->setBorderRightStyle(state.parentStyle()->borderRightStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderRightStyle(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderRightStyle(toCSSIdentifierValue(value).convertTo<EBorderStyle>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridRowEnd(StyleResolverState& state)
{
    state.style()->setGridRowEnd(ComputedStyle::initialGridRowEnd());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridRowEnd(StyleResolverState& state)
{
    state.style()->setGridRowEnd(state.parentStyle()->gridRowEnd());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridRowEnd(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setGridRowEnd(StyleBuilderConverter::convertGridPosition(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextUnderlinePosition(StyleResolverState& state)
{
    state.style()->setTextUnderlinePosition(ComputedStyle::initialTextUnderlinePosition());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextUnderlinePosition(StyleResolverState& state)
{
    state.style()->setTextUnderlinePosition(state.parentStyle()->getTextUnderlinePosition());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextUnderlinePosition(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextUnderlinePosition(toCSSIdentifierValue(value).convertTo<TextUnderlinePosition>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackfaceVisibility(StyleResolverState& state)
{
    state.style()->setBackfaceVisibility(ComputedStyle::initialBackfaceVisibility());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackfaceVisibility(StyleResolverState& state)
{
    state.style()->setBackfaceVisibility(state.parentStyle()->backfaceVisibility());
}

void StyleBuilderFunctions::applyValueCSSPropertyBackfaceVisibility(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBackfaceVisibility(toCSSIdentifierValue(value).convertTo<EBackfaceVisibility>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyLeft(StyleResolverState& state)
{
    state.style()->setLeft(ComputedStyle::initialOffset());
}

void StyleBuilderFunctions::applyInheritCSSPropertyLeft(StyleResolverState& state)
{
    state.style()->setLeft(state.parentStyle()->left());
}

void StyleBuilderFunctions::applyValueCSSPropertyLeft(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setLeft(StyleBuilderConverter::convertLengthOrAuto(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWidth(StyleResolverState& state)
{
    state.style()->setWidth(ComputedStyle::initialSize());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWidth(StyleResolverState& state)
{
    state.style()->setWidth(state.parentStyle()->width());
}

void StyleBuilderFunctions::applyValueCSSPropertyWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setWidth(StyleBuilderConverter::convertLengthSizing(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyColumnRuleStyle(StyleResolverState& state)
{
    state.style()->setColumnRuleStyle(ComputedStyle::initialBorderStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyColumnRuleStyle(StyleResolverState& state)
{
    state.style()->setColumnRuleStyle(state.parentStyle()->columnRuleStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyColumnRuleStyle(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setColumnRuleStyle(toCSSIdentifierValue(value).convertTo<EBorderStyle>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOffsetPath(StyleResolverState& state)
{
    state.style()->setOffsetPath(ComputedStyle::initialOffsetPath());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOffsetPath(StyleResolverState& state)
{
    state.style()->setOffsetPath(state.parentStyle()->offsetPath());
}

void StyleBuilderFunctions::applyValueCSSPropertyOffsetPath(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOffsetPath(StyleBuilderConverter::convertPathOrNone(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextDecorationSkip(StyleResolverState& state)
{
    state.style()->setTextDecorationSkip(ComputedStyle::initialTextDecorationSkip());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextDecorationSkip(StyleResolverState& state)
{
    state.style()->setTextDecorationSkip(state.parentStyle()->getTextDecorationSkip());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextDecorationSkip(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextDecorationSkip(StyleBuilderConverter::convertFlags<TextDecorationSkip>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBreakInside(StyleResolverState& state)
{
    state.style()->setBreakInside(ComputedStyle::initialBreakInside());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBreakInside(StyleResolverState& state)
{
    state.style()->setBreakInside(state.parentStyle()->breakInside());
}

void StyleBuilderFunctions::applyValueCSSPropertyBreakInside(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBreakInside(toCSSIdentifierValue(value).convertTo<EBreak>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskBoxImageSource(StyleResolverState& state)
{
    state.style()->setMaskBoxImageSource(ComputedStyle::initialMaskBoxImageSource());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskBoxImageSource(StyleResolverState& state)
{
    state.style()->setMaskBoxImageSource(state.parentStyle()->maskBoxImageSource());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontFeatureSettings(StyleResolverState& state)
{
    state.fontBuilder().setFeatureSettings(FontBuilder::initialFeatureSettings());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontFeatureSettings(StyleResolverState& state)
{
    state.fontBuilder().setFeatureSettings(state.parentFontDescription().featureSettings());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontFeatureSettings(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setFeatureSettings(StyleBuilderConverter::convertFontFeatureSettings(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyStrokeMiterlimit(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeMiterLimit(SVGComputedStyle::initialStrokeMiterLimit());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStrokeMiterlimit(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeMiterLimit(state.parentStyle()->svgStyle().strokeMiterLimit());
}

void StyleBuilderFunctions::applyValueCSSPropertyStrokeMiterlimit(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setStrokeMiterLimit(toCSSPrimitiveValue(value).convertTo<float>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOverflowAnchor(StyleResolverState& state)
{
    state.style()->setOverflowAnchor(ComputedStyle::initialOverflowAnchor());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOverflowAnchor(StyleResolverState& state)
{
    state.style()->setOverflowAnchor(state.parentStyle()->overflowAnchor());
}

void StyleBuilderFunctions::applyValueCSSPropertyOverflowAnchor(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOverflowAnchor(toCSSIdentifierValue(value).convertTo<EOverflowAnchor>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridColumnStart(StyleResolverState& state)
{
    state.style()->setGridColumnStart(ComputedStyle::initialGridColumnStart());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridColumnStart(StyleResolverState& state)
{
    state.style()->setGridColumnStart(state.parentStyle()->gridColumnStart());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridColumnStart(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setGridColumnStart(StyleBuilderConverter::convertGridPosition(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyMarginBottom(StyleResolverState& state)
{
    state.style()->setMarginBottom(ComputedStyle::initialMargin());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMarginBottom(StyleResolverState& state)
{
    state.style()->setMarginBottom(state.parentStyle()->marginBottom());
}

void StyleBuilderFunctions::applyValueCSSPropertyMarginBottom(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMarginBottom(StyleBuilderConverter::convertQuirkyLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyListStylePosition(StyleResolverState& state)
{
    state.style()->setListStylePosition(ComputedStyle::initialListStylePosition());
    state.style()->setListStylePositionIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyListStylePosition(StyleResolverState& state)
{
    state.style()->setListStylePosition(state.parentStyle()->listStylePosition());
    state.style()->setListStylePositionIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyListStylePosition(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setListStylePosition(toCSSIdentifierValue(value).convertTo<EListStylePosition>());
    state.style()->setListStylePositionIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyOutlineOffset(StyleResolverState& state)
{
    state.style()->setOutlineOffset(ComputedStyle::initialOutlineOffset());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOutlineOffset(StyleResolverState& state)
{
    state.style()->setOutlineOffset(state.parentStyle()->outlineOffset());
}

void StyleBuilderFunctions::applyValueCSSPropertyOutlineOffset(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOutlineOffset(StyleBuilderConverter::convertComputedLength<int>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyShapeRendering(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setShapeRendering(SVGComputedStyle::initialShapeRendering());
}

void StyleBuilderFunctions::applyInheritCSSPropertyShapeRendering(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setShapeRendering(state.parentStyle()->svgStyle().shapeRendering());
}

void StyleBuilderFunctions::applyValueCSSPropertyShapeRendering(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setShapeRendering(toCSSIdentifierValue(value).convertTo<EShapeRendering>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyJustifyItems(StyleResolverState& state)
{
    state.style()->setJustifyItems(ComputedStyle::initialSelfAlignment());
}

void StyleBuilderFunctions::applyInheritCSSPropertyJustifyItems(StyleResolverState& state)
{
    state.style()->setJustifyItems(state.parentStyle()->justifyItems());
}

void StyleBuilderFunctions::applyValueCSSPropertyJustifyItems(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setJustifyItems(StyleBuilderConverter::convertSelfOrDefaultAlignmentData(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyRotate(StyleResolverState& state)
{
    state.style()->setRotate(ComputedStyle::initialRotate());
}

void StyleBuilderFunctions::applyInheritCSSPropertyRotate(StyleResolverState& state)
{
    state.style()->setRotate(state.parentStyle()->rotate());
}

void StyleBuilderFunctions::applyValueCSSPropertyRotate(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setRotate(StyleBuilderConverter::convertRotate(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyColorRendering(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setColorRendering(SVGComputedStyle::initialColorRendering());
}

void StyleBuilderFunctions::applyInheritCSSPropertyColorRendering(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setColorRendering(state.parentStyle()->svgStyle().colorRendering());
}

void StyleBuilderFunctions::applyValueCSSPropertyColorRendering(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setColorRendering(toCSSIdentifierValue(value).convertTo<EColorRendering>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyStrokeLinejoin(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setJoinStyle(SVGComputedStyle::initialJoinStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStrokeLinejoin(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setJoinStyle(state.parentStyle()->svgStyle().joinStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyStrokeLinejoin(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setJoinStyle(toCSSIdentifierValue(value).convertTo<LineJoin>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFlexGrow(StyleResolverState& state)
{
    state.style()->setFlexGrow(ComputedStyle::initialFlexGrow());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFlexGrow(StyleResolverState& state)
{
    state.style()->setFlexGrow(state.parentStyle()->flexGrow());
}

void StyleBuilderFunctions::applyValueCSSPropertyFlexGrow(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setFlexGrow(toCSSPrimitiveValue(value).convertTo<float>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyMask(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMaskerResource(SVGComputedStyle::initialMaskerResource());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMask(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMaskerResource(state.parentStyle()->svgStyle().maskerResource());
}

void StyleBuilderFunctions::applyValueCSSPropertyMask(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setMaskerResource(StyleBuilderConverter::convertFragmentIdentifier(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMarginBeforeCollapse(StyleResolverState& state)
{
    state.style()->setMarginBeforeCollapse(ComputedStyle::initialMarginBeforeCollapse());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMarginBeforeCollapse(StyleResolverState& state)
{
    state.style()->setMarginBeforeCollapse(state.parentStyle()->marginBeforeCollapse());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMarginBeforeCollapse(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMarginBeforeCollapse(toCSSIdentifierValue(value).convertTo<EMarginCollapse>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitAppearance(StyleResolverState& state)
{
    state.style()->setAppearance(ComputedStyle::initialAppearance());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitAppearance(StyleResolverState& state)
{
    state.style()->setAppearance(state.parentStyle()->appearance());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitAppearance(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setAppearance(toCSSIdentifierValue(value).convertTo<ControlPart>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyPointerEvents(StyleResolverState& state)
{
    state.style()->setPointerEvents(ComputedStyle::initialPointerEvents());
    state.style()->setPointerEventsIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyPointerEvents(StyleResolverState& state)
{
    state.style()->setPointerEvents(state.parentStyle()->pointerEvents());
    state.style()->setPointerEventsIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyPointerEvents(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPointerEvents(toCSSIdentifierValue(value).convertTo<EPointerEvents>());
    state.style()->setPointerEventsIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxOrient(StyleResolverState& state)
{
    state.style()->setBoxOrient(ComputedStyle::initialBoxOrient());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxOrient(StyleResolverState& state)
{
    state.style()->setBoxOrient(state.parentStyle()->boxOrient());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxOrient(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxOrient(toCSSIdentifierValue(value).convertTo<EBoxOrient>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyStrokeLinecap(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setCapStyle(SVGComputedStyle::initialCapStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStrokeLinecap(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setCapStyle(state.parentStyle()->svgStyle().capStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyStrokeLinecap(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setCapStyle(toCSSIdentifierValue(value).convertTo<LineCap>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderLeftStyle(StyleResolverState& state)
{
    state.style()->setBorderLeftStyle(ComputedStyle::initialBorderStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderLeftStyle(StyleResolverState& state)
{
    state.style()->setBorderLeftStyle(state.parentStyle()->borderLeftStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderLeftStyle(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderLeftStyle(toCSSIdentifierValue(value).convertTo<EBorderStyle>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitUserDrag(StyleResolverState& state)
{
    state.style()->setUserDrag(ComputedStyle::initialUserDrag());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitUserDrag(StyleResolverState& state)
{
    state.style()->setUserDrag(state.parentStyle()->userDrag());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitUserDrag(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setUserDrag(toCSSIdentifierValue(value).convertTo<EUserDrag>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontVariantLigatures(StyleResolverState& state)
{
    state.fontBuilder().setVariantLigatures(FontBuilder::initialVariantLigatures());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontVariantLigatures(StyleResolverState& state)
{
    state.fontBuilder().setVariantLigatures(state.parentFontDescription().getVariantLigatures());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontVariantLigatures(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setVariantLigatures(StyleBuilderConverter::convertFontVariantLigatures(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyMarkerMid(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMarkerMidResource(SVGComputedStyle::initialMarkerMidResource());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMarkerMid(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMarkerMidResource(state.parentStyle()->svgStyle().markerMidResource());
}

void StyleBuilderFunctions::applyValueCSSPropertyMarkerMid(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setMarkerMidResource(StyleBuilderConverter::convertFragmentIdentifier(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTextCombine(StyleResolverState& state)
{
    state.style()->setTextCombine(ComputedStyle::initialTextCombine());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTextCombine(StyleResolverState& state)
{
    state.style()->setTextCombine(state.parentStyle()->getTextCombine());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTextCombine(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextCombine(toCSSIdentifierValue(value).convertTo<TextCombine>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyX(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setX(SVGComputedStyle::initialX());
}

void StyleBuilderFunctions::applyInheritCSSPropertyX(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setX(state.parentStyle()->svgStyle().x());
}

void StyleBuilderFunctions::applyValueCSSPropertyX(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setX(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyY(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setY(SVGComputedStyle::initialY());
}

void StyleBuilderFunctions::applyInheritCSSPropertyY(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setY(state.parentStyle()->svgStyle().y());
}

void StyleBuilderFunctions::applyValueCSSPropertyY(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setY(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyR(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setR(SVGComputedStyle::initialR());
}

void StyleBuilderFunctions::applyInheritCSSPropertyR(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setR(state.parentStyle()->svgStyle().r());
}

void StyleBuilderFunctions::applyValueCSSPropertyR(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setR(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyResize(StyleResolverState& state)
{
    state.style()->setResize(ComputedStyle::initialResize());
}

void StyleBuilderFunctions::applyInheritCSSPropertyResize(StyleResolverState& state)
{
    state.style()->setResize(state.parentStyle()->resize());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOffsetDistance(StyleResolverState& state)
{
    state.style()->setOffsetDistance(ComputedStyle::initialOffsetDistance());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOffsetDistance(StyleResolverState& state)
{
    state.style()->setOffsetDistance(state.parentStyle()->offsetDistance());
}

void StyleBuilderFunctions::applyValueCSSPropertyOffsetDistance(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOffsetDistance(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyLetterSpacing(StyleResolverState& state)
{
    state.style()->setLetterSpacing(ComputedStyle::initialLetterWordSpacing());
}

void StyleBuilderFunctions::applyInheritCSSPropertyLetterSpacing(StyleResolverState& state)
{
    state.style()->setLetterSpacing(state.parentStyle()->letterSpacing());
}

void StyleBuilderFunctions::applyValueCSSPropertyLetterSpacing(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setLetterSpacing(StyleBuilderConverter::convertSpacing(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTransformOriginZ(StyleResolverState& state)
{
    state.style()->setTransformOriginZ(ComputedStyle::initialTransformOriginZ());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTransformOriginZ(StyleResolverState& state)
{
    state.style()->setTransformOriginZ(state.parentStyle()->transformOriginZ());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTransformOriginZ(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTransformOriginZ(StyleBuilderConverter::convertComputedLength<float>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTextOrientation(StyleResolverState& state)
{
    state.style()->setTextOrientation(ComputedStyle::initialTextOrientation());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTextOrientation(StyleResolverState& state)
{
    state.style()->setTextOrientation(state.parentStyle()->getTextOrientation());
}

void StyleBuilderFunctions::applyInitialCSSPropertyD(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setD(SVGComputedStyle::initialD());
}

void StyleBuilderFunctions::applyInheritCSSPropertyD(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setD(state.parentStyle()->svgStyle().d());
}

void StyleBuilderFunctions::applyValueCSSPropertyD(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setD(StyleBuilderConverter::convertPathOrNone(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyColorInterpolationFilters(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setColorInterpolationFilters(SVGComputedStyle::initialColorInterpolationFilters());
}

void StyleBuilderFunctions::applyInheritCSSPropertyColorInterpolationFilters(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setColorInterpolationFilters(state.parentStyle()->svgStyle().colorInterpolationFilters());
}

void StyleBuilderFunctions::applyValueCSSPropertyColorInterpolationFilters(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setColorInterpolationFilters(toCSSIdentifierValue(value).convertTo<EColorInterpolation>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextTransform(StyleResolverState& state)
{
    state.style()->setTextTransform(ComputedStyle::initialTextTransform());
    state.style()->setTextTransformIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextTransform(StyleResolverState& state)
{
    state.style()->setTextTransform(state.parentStyle()->textTransform());
    state.style()->setTextTransformIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyTextTransform(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextTransform(toCSSIdentifierValue(value).convertTo<ETextTransform>());
    state.style()->setTextTransformIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyRight(StyleResolverState& state)
{
    state.style()->setRight(ComputedStyle::initialOffset());
}

void StyleBuilderFunctions::applyInheritCSSPropertyRight(StyleResolverState& state)
{
    state.style()->setRight(state.parentStyle()->right());
}

void StyleBuilderFunctions::applyValueCSSPropertyRight(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setRight(StyleBuilderConverter::convertLengthOrAuto(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridColumnEnd(StyleResolverState& state)
{
    state.style()->setGridColumnEnd(ComputedStyle::initialGridColumnEnd());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridColumnEnd(StyleResolverState& state)
{
    state.style()->setGridColumnEnd(state.parentStyle()->gridColumnEnd());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridColumnEnd(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setGridColumnEnd(StyleBuilderConverter::convertGridPosition(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyScrollSnapCoordinate(StyleResolverState& state)
{
    state.style()->setScrollSnapCoordinate(ComputedStyle::initialScrollSnapCoordinate());
}

void StyleBuilderFunctions::applyInheritCSSPropertyScrollSnapCoordinate(StyleResolverState& state)
{
    state.style()->setScrollSnapCoordinate(state.parentStyle()->scrollSnapCoordinate());
}

void StyleBuilderFunctions::applyValueCSSPropertyScrollSnapCoordinate(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setScrollSnapCoordinate(StyleBuilderConverter::convertSnapCoordinates(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyAlignContent(StyleResolverState& state)
{
    state.style()->setAlignContent(ComputedStyle::initialContentAlignment());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAlignContent(StyleResolverState& state)
{
    state.style()->setAlignContent(state.parentStyle()->alignContent());
}

void StyleBuilderFunctions::applyValueCSSPropertyAlignContent(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setAlignContent(StyleBuilderConverter::convertContentAlignmentData(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyDirection(StyleResolverState& state)
{
    state.style()->setDirection(ComputedStyle::initialDirection());
}

void StyleBuilderFunctions::applyInheritCSSPropertyDirection(StyleResolverState& state)
{
    state.style()->setDirection(state.parentStyle()->direction());
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextOrientation(StyleResolverState& state)
{
    state.style()->setTextOrientation(ComputedStyle::initialTextOrientation());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextOrientation(StyleResolverState& state)
{
    state.style()->setTextOrientation(state.parentStyle()->getTextOrientation());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBorderImage(StyleResolverState& state)
{
    state.style()->setBorderImage(ComputedStyle::initialNinePieceImage());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBorderImage(StyleResolverState& state)
{
    state.style()->setBorderImage(state.parentStyle()->borderImage());
}

void StyleBuilderFunctions::applyInitialCSSPropertyTouchAction(StyleResolverState& state)
{
    state.style()->setTouchAction(ComputedStyle::initialTouchAction());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTouchAction(StyleResolverState& state)
{
    state.style()->setTouchAction(state.parentStyle()->getTouchAction());
}

void StyleBuilderFunctions::applyValueCSSPropertyTouchAction(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTouchAction(StyleBuilderConverter::convertFlags<TouchAction>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBorderVerticalSpacing(StyleResolverState& state)
{
    state.style()->setVerticalBorderSpacing(ComputedStyle::initialVerticalBorderSpacing());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBorderVerticalSpacing(StyleResolverState& state)
{
    state.style()->setVerticalBorderSpacing(state.parentStyle()->verticalBorderSpacing());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBorderVerticalSpacing(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setVerticalBorderSpacing(StyleBuilderConverter::convertComputedLength<short>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyMarginLeft(StyleResolverState& state)
{
    state.style()->setMarginLeft(ComputedStyle::initialMargin());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMarginLeft(StyleResolverState& state)
{
    state.style()->setMarginLeft(state.parentStyle()->marginLeft());
}

void StyleBuilderFunctions::applyValueCSSPropertyMarginLeft(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMarginLeft(StyleBuilderConverter::convertQuirkyLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyFlexWrap(StyleResolverState& state)
{
    state.style()->setFlexWrap(ComputedStyle::initialFlexWrap());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFlexWrap(StyleResolverState& state)
{
    state.style()->setFlexWrap(state.parentStyle()->flexWrap());
}

void StyleBuilderFunctions::applyValueCSSPropertyFlexWrap(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setFlexWrap(toCSSIdentifierValue(value).convertTo<EFlexWrap>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyMinHeight(StyleResolverState& state)
{
    state.style()->setMinHeight(ComputedStyle::initialMinSize());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMinHeight(StyleResolverState& state)
{
    state.style()->setMinHeight(state.parentStyle()->minHeight());
}

void StyleBuilderFunctions::applyValueCSSPropertyMinHeight(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMinHeight(StyleBuilderConverter::convertLengthSizing(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyFloodColor(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setFloodColor(SVGComputedStyle::initialFloodColor());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFloodColor(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setFloodColor(state.parentStyle()->svgStyle().floodColor());
}

void StyleBuilderFunctions::applyValueCSSPropertyFloodColor(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setFloodColor(StyleBuilderConverter::convertColor(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyMaxHeight(StyleResolverState& state)
{
    state.style()->setMaxHeight(ComputedStyle::initialMaxSize());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMaxHeight(StyleResolverState& state)
{
    state.style()->setMaxHeight(state.parentStyle()->maxHeight());
}

void StyleBuilderFunctions::applyValueCSSPropertyMaxHeight(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMaxHeight(StyleBuilderConverter::convertLengthMaxSizing(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBufferedRendering(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setBufferedRendering(SVGComputedStyle::initialBufferedRendering());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBufferedRendering(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setBufferedRendering(state.parentStyle()->svgStyle().bufferedRendering());
}

void StyleBuilderFunctions::applyValueCSSPropertyBufferedRendering(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setBufferedRendering(toCSSIdentifierValue(value).convertTo<EBufferedRendering>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyOrphans(StyleResolverState& state)
{
    state.style()->setOrphans(ComputedStyle::initialOrphans());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOrphans(StyleResolverState& state)
{
    state.style()->setOrphans(state.parentStyle()->orphans());
}

void StyleBuilderFunctions::applyValueCSSPropertyOrphans(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOrphans(toCSSPrimitiveValue(value).convertTo<short>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyAlignmentBaseline(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setAlignmentBaseline(SVGComputedStyle::initialAlignmentBaseline());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAlignmentBaseline(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setAlignmentBaseline(state.parentStyle()->svgStyle().alignmentBaseline());
}

void StyleBuilderFunctions::applyValueCSSPropertyAlignmentBaseline(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setAlignmentBaseline(toCSSIdentifierValue(value).convertTo<EAlignmentBaseline>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyMinWidth(StyleResolverState& state)
{
    state.style()->setMinWidth(ComputedStyle::initialMinSize());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMinWidth(StyleResolverState& state)
{
    state.style()->setMinWidth(state.parentStyle()->minWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyMinWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMinWidth(StyleBuilderConverter::convertLengthSizing(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyMaskType(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMaskType(SVGComputedStyle::initialMaskType());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMaskType(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMaskType(state.parentStyle()->svgStyle().maskType());
}

void StyleBuilderFunctions::applyValueCSSPropertyMaskType(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setMaskType(toCSSIdentifierValue(value).convertTo<EMaskType>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitPerspectiveOriginY(StyleResolverState& state)
{
    state.style()->setPerspectiveOriginY(ComputedStyle::initialPerspectiveOriginY());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitPerspectiveOriginY(StyleResolverState& state)
{
    state.style()->setPerspectiveOriginY(state.parentStyle()->perspectiveOriginY());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitPerspectiveOriginY(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPerspectiveOriginY(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextAlignLast(StyleResolverState& state)
{
    state.style()->setTextAlignLast(ComputedStyle::initialTextAlignLast());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextAlignLast(StyleResolverState& state)
{
    state.style()->setTextAlignLast(state.parentStyle()->getTextAlignLast());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextAlignLast(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextAlignLast(toCSSIdentifierValue(value).convertTo<TextAlignLast>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMarginTopCollapse(StyleResolverState& state)
{
    state.style()->setMarginBeforeCollapse(ComputedStyle::initialMarginBeforeCollapse());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMarginTopCollapse(StyleResolverState& state)
{
    state.style()->setMarginBeforeCollapse(state.parentStyle()->marginBeforeCollapse());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMarginTopCollapse(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMarginBeforeCollapse(toCSSIdentifierValue(value).convertTo<EMarginCollapse>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyTabSize(StyleResolverState& state)
{
    state.style()->setTabSize(ComputedStyle::initialTabSize());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTabSize(StyleResolverState& state)
{
    state.style()->setTabSize(state.parentStyle()->getTabSize());
}

void StyleBuilderFunctions::applyValueCSSPropertyTabSize(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTabSize(StyleBuilderConverter::convertLengthOrTabSpaces(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyOffsetRotation(StyleResolverState& state)
{
    state.style()->setOffsetRotation(ComputedStyle::initialOffsetRotation());
}

void StyleBuilderFunctions::applyInheritCSSPropertyOffsetRotation(StyleResolverState& state)
{
    state.style()->setOffsetRotation(state.parentStyle()->offsetRotation());
}

void StyleBuilderFunctions::applyValueCSSPropertyOffsetRotation(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setOffsetRotation(StyleBuilderConverter::convertOffsetRotate(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderBottomWidth(StyleResolverState& state)
{
    state.style()->setBorderBottomWidth(ComputedStyle::initialBorderWidth());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderBottomWidth(StyleResolverState& state)
{
    state.style()->setBorderBottomWidth(state.parentStyle()->borderBottomWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderBottomWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderBottomWidth(StyleBuilderConverter::convertLineWidth<unsigned>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitHighlight(StyleResolverState& state)
{
    state.style()->setHighlight(ComputedStyle::initialHighlight());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitHighlight(StyleResolverState& state)
{
    state.style()->setHighlight(state.parentStyle()->highlight());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitHighlight(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setHighlight(StyleBuilderConverter::convertString<CSSValueNone>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyEmptyCells(StyleResolverState& state)
{
    state.style()->setEmptyCells(ComputedStyle::initialEmptyCells());
    state.style()->setEmptyCellsIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyEmptyCells(StyleResolverState& state)
{
    state.style()->setEmptyCells(state.parentStyle()->emptyCells());
    state.style()->setEmptyCellsIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyEmptyCells(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setEmptyCells(toCSSIdentifierValue(value).convertTo<EEmptyCells>());
    state.style()->setEmptyCellsIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextOverflow(StyleResolverState& state)
{
    state.style()->setTextOverflow(ComputedStyle::initialTextOverflow());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextOverflow(StyleResolverState& state)
{
    state.style()->setTextOverflow(state.parentStyle()->getTextOverflow());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextOverflow(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextOverflow(toCSSIdentifierValue(value).convertTo<TextOverflow>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBoxSizing(StyleResolverState& state)
{
    state.style()->setBoxSizing(ComputedStyle::initialBoxSizing());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBoxSizing(StyleResolverState& state)
{
    state.style()->setBoxSizing(state.parentStyle()->boxSizing());
}

void StyleBuilderFunctions::applyValueCSSPropertyBoxSizing(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxSizing(toCSSIdentifierValue(value).convertTo<EBoxSizing>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyStrokeWidth(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeWidth(SVGComputedStyle::initialStrokeWidth());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStrokeWidth(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokeWidth(state.parentStyle()->svgStyle().strokeWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyStrokeWidth(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setStrokeWidth(StyleBuilderConverter::convertUnzoomedLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyMarkerStart(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMarkerStartResource(SVGComputedStyle::initialMarkerStartResource());
}

void StyleBuilderFunctions::applyInheritCSSPropertyMarkerStart(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setMarkerStartResource(state.parentStyle()->svgStyle().markerStartResource());
}

void StyleBuilderFunctions::applyValueCSSPropertyMarkerStart(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setMarkerStartResource(StyleBuilderConverter::convertFragmentIdentifier(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextDecorationStyle(StyleResolverState& state)
{
    state.style()->setTextDecorationStyle(ComputedStyle::initialTextDecorationStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextDecorationStyle(StyleResolverState& state)
{
    state.style()->setTextDecorationStyle(state.parentStyle()->getTextDecorationStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyTextDecorationStyle(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTextDecorationStyle(toCSSIdentifierValue(value).convertTo<TextDecorationStyle>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyTranslate(StyleResolverState& state)
{
    state.style()->setTranslate(ComputedStyle::initialTranslate());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTranslate(StyleResolverState& state)
{
    state.style()->setTranslate(state.parentStyle()->translate());
}

void StyleBuilderFunctions::applyValueCSSPropertyTranslate(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setTranslate(StyleBuilderConverter::convertTranslate(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyPaddingTop(StyleResolverState& state)
{
    state.style()->setPaddingTop(ComputedStyle::initialPadding());
}

void StyleBuilderFunctions::applyInheritCSSPropertyPaddingTop(StyleResolverState& state)
{
    state.style()->setPaddingTop(state.parentStyle()->paddingTop());
}

void StyleBuilderFunctions::applyValueCSSPropertyPaddingTop(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPaddingTop(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyDisplay(StyleResolverState& state)
{
    state.style()->setDisplay(ComputedStyle::initialDisplay());
}

void StyleBuilderFunctions::applyInheritCSSPropertyDisplay(StyleResolverState& state)
{
    state.style()->setDisplay(state.parentStyle()->display());
}

void StyleBuilderFunctions::applyValueCSSPropertyDisplay(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setDisplay(toCSSIdentifierValue(value).convertTo<EDisplay>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWordBreak(StyleResolverState& state)
{
    state.style()->setWordBreak(ComputedStyle::initialWordBreak());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWordBreak(StyleResolverState& state)
{
    state.style()->setWordBreak(state.parentStyle()->wordBreak());
}

void StyleBuilderFunctions::applyValueCSSPropertyWordBreak(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setWordBreak(toCSSIdentifierValue(value).convertTo<EWordBreak>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderTopStyle(StyleResolverState& state)
{
    state.style()->setBorderTopStyle(ComputedStyle::initialBorderStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderTopStyle(StyleResolverState& state)
{
    state.style()->setBorderTopStyle(state.parentStyle()->borderTopStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderTopStyle(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderTopStyle(toCSSIdentifierValue(value).convertTo<EBorderStyle>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyJustifyContent(StyleResolverState& state)
{
    state.style()->setJustifyContent(ComputedStyle::initialContentAlignment());
}

void StyleBuilderFunctions::applyInheritCSSPropertyJustifyContent(StyleResolverState& state)
{
    state.style()->setJustifyContent(state.parentStyle()->justifyContent());
}

void StyleBuilderFunctions::applyValueCSSPropertyJustifyContent(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setJustifyContent(StyleBuilderConverter::convertContentAlignmentData(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBoxShadow(StyleResolverState& state)
{
    state.style()->setBoxShadow(ComputedStyle::initialBoxShadow());
}

void StyleBuilderFunctions::applyInheritCSSPropertyBoxShadow(StyleResolverState& state)
{
    state.style()->setBoxShadow(state.parentStyle()->boxShadow());
}

void StyleBuilderFunctions::applyValueCSSPropertyBoxShadow(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxShadow(StyleBuilderConverter::convertShadowList(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertySpeak(StyleResolverState& state)
{
    state.style()->setSpeak(ComputedStyle::initialSpeak());
}

void StyleBuilderFunctions::applyInheritCSSPropertySpeak(StyleResolverState& state)
{
    state.style()->setSpeak(state.parentStyle()->speak());
}

void StyleBuilderFunctions::applyValueCSSPropertySpeak(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setSpeak(toCSSIdentifierValue(value).convertTo<ESpeak>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyListStyleImage(StyleResolverState& state)
{
    state.style()->setListStyleImage(ComputedStyle::initialListStyleImage());
}

void StyleBuilderFunctions::applyInheritCSSPropertyListStyleImage(StyleResolverState& state)
{
    state.style()->setListStyleImage(state.parentStyle()->listStyleImage());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFloodOpacity(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setFloodOpacity(SVGComputedStyle::initialFloodOpacity());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFloodOpacity(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setFloodOpacity(state.parentStyle()->svgStyle().floodOpacity());
}

void StyleBuilderFunctions::applyValueCSSPropertyFloodOpacity(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setFloodOpacity(StyleBuilderConverter::convertNumberOrPercentage(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyClipRule(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setClipRule(SVGComputedStyle::initialClipRule());
}

void StyleBuilderFunctions::applyInheritCSSPropertyClipRule(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setClipRule(state.parentStyle()->svgStyle().clipRule());
}

void StyleBuilderFunctions::applyValueCSSPropertyClipRule(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setClipRule(toCSSIdentifierValue(value).convertTo<WindRule>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyFlexDirection(StyleResolverState& state)
{
    state.style()->setFlexDirection(ComputedStyle::initialFlexDirection());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFlexDirection(StyleResolverState& state)
{
    state.style()->setFlexDirection(state.parentStyle()->flexDirection());
}

void StyleBuilderFunctions::applyValueCSSPropertyFlexDirection(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setFlexDirection(toCSSIdentifierValue(value).convertTo<EFlexDirection>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyLightingColor(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setLightingColor(SVGComputedStyle::initialLightingColor());
}

void StyleBuilderFunctions::applyInheritCSSPropertyLightingColor(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setLightingColor(state.parentStyle()->svgStyle().lightingColor());
}

void StyleBuilderFunctions::applyValueCSSPropertyLightingColor(StyleResolverState& state, const CSSValue& value)
{
    state.style()->accessSVGStyle().setLightingColor(StyleBuilderConverter::convertColor(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyListStyleType(StyleResolverState& state)
{
    state.style()->setListStyleType(ComputedStyle::initialListStyleType());
}

void StyleBuilderFunctions::applyInheritCSSPropertyListStyleType(StyleResolverState& state)
{
    state.style()->setListStyleType(state.parentStyle()->listStyleType());
}

void StyleBuilderFunctions::applyValueCSSPropertyListStyleType(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setListStyleType(toCSSIdentifierValue(value).convertTo<EListStyleType>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyImageOrientation(StyleResolverState& state)
{
    state.style()->setRespectImageOrientation(ComputedStyle::initialRespectImageOrientation());
}

void StyleBuilderFunctions::applyInheritCSSPropertyImageOrientation(StyleResolverState& state)
{
    state.style()->setRespectImageOrientation(state.parentStyle()->respectImageOrientation());
}

void StyleBuilderFunctions::applyValueCSSPropertyImageOrientation(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setRespectImageOrientation(StyleBuilderConverter::convertImageOrientation(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextAlign(StyleResolverState& state)
{
    state.style()->setTextAlign(ComputedStyle::initialTextAlign());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextAlign(StyleResolverState& state)
{
    state.style()->setTextAlign(state.parentStyle()->textAlign());
}

void StyleBuilderFunctions::applyInitialCSSPropertyAlignItems(StyleResolverState& state)
{
    state.style()->setAlignItems(ComputedStyle::initialDefaultAlignment());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAlignItems(StyleResolverState& state)
{
    state.style()->setAlignItems(state.parentStyle()->alignItems());
}

void StyleBuilderFunctions::applyValueCSSPropertyAlignItems(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setAlignItems(StyleBuilderConverter::convertSelfOrDefaultAlignmentData(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyObjectPosition(StyleResolverState& state)
{
    state.style()->setObjectPosition(ComputedStyle::initialObjectPosition());
}

void StyleBuilderFunctions::applyInheritCSSPropertyObjectPosition(StyleResolverState& state)
{
    state.style()->setObjectPosition(state.parentStyle()->objectPosition());
}

void StyleBuilderFunctions::applyValueCSSPropertyObjectPosition(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setObjectPosition(StyleBuilderConverter::convertPosition(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridColumnGap(StyleResolverState& state)
{
    state.style()->setGridColumnGap(ComputedStyle::initialGridColumnGap());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridColumnGap(StyleResolverState& state)
{
    state.style()->setGridColumnGap(state.parentStyle()->gridColumnGap());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridColumnGap(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setGridColumnGap(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyScrollSnapDestination(StyleResolverState& state)
{
    state.style()->setScrollSnapDestination(ComputedStyle::initialScrollSnapDestination());
}

void StyleBuilderFunctions::applyInheritCSSPropertyScrollSnapDestination(StyleResolverState& state)
{
    state.style()->setScrollSnapDestination(state.parentStyle()->scrollSnapDestination());
}

void StyleBuilderFunctions::applyValueCSSPropertyScrollSnapDestination(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setScrollSnapDestination(StyleBuilderConverter::convertPosition(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitBoxFlexGroup(StyleResolverState& state)
{
    state.style()->setBoxFlexGroup(ComputedStyle::initialBoxFlexGroup());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitBoxFlexGroup(StyleResolverState& state)
{
    state.style()->setBoxFlexGroup(state.parentStyle()->boxFlexGroup());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitBoxFlexGroup(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBoxFlexGroup(toCSSPrimitiveValue(value).convertTo<unsigned int>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitPerspectiveOriginX(StyleResolverState& state)
{
    state.style()->setPerspectiveOriginX(ComputedStyle::initialPerspectiveOriginX());
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitPerspectiveOriginX(StyleResolverState& state)
{
    state.style()->setPerspectiveOriginX(state.parentStyle()->perspectiveOriginX());
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitPerspectiveOriginX(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setPerspectiveOriginX(StyleBuilderConverter::convertLength(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontSizeAdjust(StyleResolverState& state)
{
    state.fontBuilder().setSizeAdjust(FontBuilder::initialSizeAdjust());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontSizeAdjust(StyleResolverState& state)
{
    state.fontBuilder().setSizeAdjust(state.parentFontDescription().sizeAdjust());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontSizeAdjust(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setSizeAdjust(StyleBuilderConverter::convertFontSizeAdjust(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyFontSize(StyleResolverState& state)
{
    state.fontBuilder().setSize(FontBuilder::initialSize());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFontSize(StyleResolverState& state)
{
    state.fontBuilder().setSize(state.parentFontDescription().getSize());
}

void StyleBuilderFunctions::applyValueCSSPropertyFontSize(StyleResolverState& state, const CSSValue& value)
{
    state.fontBuilder().setSize(StyleBuilderConverter::convertFontSize(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyVisibility(StyleResolverState& state)
{
    state.style()->setVisibility(ComputedStyle::initialVisibility());
    state.style()->setVisibilityIsInherited(false);
}

void StyleBuilderFunctions::applyInheritCSSPropertyVisibility(StyleResolverState& state)
{
    state.style()->setVisibility(state.parentStyle()->visibility());
    state.style()->setVisibilityIsInherited(true);
}

void StyleBuilderFunctions::applyValueCSSPropertyVisibility(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setVisibility(toCSSIdentifierValue(value).convertTo<EVisibility>());
    state.style()->setVisibilityIsInherited(false);
}

void StyleBuilderFunctions::applyInitialCSSPropertyAnimationDelay(StyleResolverState& state)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.delayList().clear();
    data.delayList().push_back(CSSAnimationData::initialDelay());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAnimationDelay(StyleResolverState& state)
{
    const CSSAnimationData* parentData = state.parentStyle()->animations();
    if (!parentData)
        applyInitialCSSPropertyAnimationDelay(state);
    else
        state.style()->accessAnimations().delayList() = parentData->delayList();
}

void StyleBuilderFunctions::applyValueCSSPropertyAnimationDelay(StyleResolverState& state, const CSSValue& value)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.delayList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.delayList().push_back(CSSToStyleMap::mapAnimationDelay(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyAnimationDirection(StyleResolverState& state)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.directionList().clear();
    data.directionList().push_back(CSSAnimationData::initialDirection());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAnimationDirection(StyleResolverState& state)
{
    const CSSAnimationData* parentData = state.parentStyle()->animations();
    if (!parentData)
        applyInitialCSSPropertyAnimationDirection(state);
    else
        state.style()->accessAnimations().directionList() = parentData->directionList();
}

void StyleBuilderFunctions::applyValueCSSPropertyAnimationDirection(StyleResolverState& state, const CSSValue& value)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.directionList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.directionList().push_back(CSSToStyleMap::mapAnimationDirection(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyAnimationDuration(StyleResolverState& state)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.durationList().clear();
    data.durationList().push_back(CSSAnimationData::initialDuration());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAnimationDuration(StyleResolverState& state)
{
    const CSSAnimationData* parentData = state.parentStyle()->animations();
    if (!parentData)
        applyInitialCSSPropertyAnimationDuration(state);
    else
        state.style()->accessAnimations().durationList() = parentData->durationList();
}

void StyleBuilderFunctions::applyValueCSSPropertyAnimationDuration(StyleResolverState& state, const CSSValue& value)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.durationList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.durationList().push_back(CSSToStyleMap::mapAnimationDuration(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyAnimationFillMode(StyleResolverState& state)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.fillModeList().clear();
    data.fillModeList().push_back(CSSAnimationData::initialFillMode());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAnimationFillMode(StyleResolverState& state)
{
    const CSSAnimationData* parentData = state.parentStyle()->animations();
    if (!parentData)
        applyInitialCSSPropertyAnimationFillMode(state);
    else
        state.style()->accessAnimations().fillModeList() = parentData->fillModeList();
}

void StyleBuilderFunctions::applyValueCSSPropertyAnimationFillMode(StyleResolverState& state, const CSSValue& value)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.fillModeList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.fillModeList().push_back(CSSToStyleMap::mapAnimationFillMode(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyAnimationIterationCount(StyleResolverState& state)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.iterationCountList().clear();
    data.iterationCountList().push_back(CSSAnimationData::initialIterationCount());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAnimationIterationCount(StyleResolverState& state)
{
    const CSSAnimationData* parentData = state.parentStyle()->animations();
    if (!parentData)
        applyInitialCSSPropertyAnimationIterationCount(state);
    else
        state.style()->accessAnimations().iterationCountList() = parentData->iterationCountList();
}

void StyleBuilderFunctions::applyValueCSSPropertyAnimationIterationCount(StyleResolverState& state, const CSSValue& value)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.iterationCountList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.iterationCountList().push_back(CSSToStyleMap::mapAnimationIterationCount(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyAnimationName(StyleResolverState& state)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.nameList().clear();
    data.nameList().push_back(CSSAnimationData::initialName());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAnimationName(StyleResolverState& state)
{
    const CSSAnimationData* parentData = state.parentStyle()->animations();
    if (!parentData)
        applyInitialCSSPropertyAnimationName(state);
    else
        state.style()->accessAnimations().nameList() = parentData->nameList();
}

void StyleBuilderFunctions::applyValueCSSPropertyAnimationName(StyleResolverState& state, const CSSValue& value)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.nameList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.nameList().push_back(CSSToStyleMap::mapAnimationName(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyAnimationPlayState(StyleResolverState& state)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.playStateList().clear();
    data.playStateList().push_back(CSSAnimationData::initialPlayState());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAnimationPlayState(StyleResolverState& state)
{
    const CSSAnimationData* parentData = state.parentStyle()->animations();
    if (!parentData)
        applyInitialCSSPropertyAnimationPlayState(state);
    else
        state.style()->accessAnimations().playStateList() = parentData->playStateList();
}

void StyleBuilderFunctions::applyValueCSSPropertyAnimationPlayState(StyleResolverState& state, const CSSValue& value)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.playStateList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.playStateList().push_back(CSSToStyleMap::mapAnimationPlayState(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyAnimationTimingFunction(StyleResolverState& state)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.timingFunctionList().clear();
    data.timingFunctionList().push_back(CSSAnimationData::initialTimingFunction());
}

void StyleBuilderFunctions::applyInheritCSSPropertyAnimationTimingFunction(StyleResolverState& state)
{
    const CSSAnimationData* parentData = state.parentStyle()->animations();
    if (!parentData)
        applyInitialCSSPropertyAnimationTimingFunction(state);
    else
        state.style()->accessAnimations().timingFunctionList() = parentData->timingFunctionList();
}

void StyleBuilderFunctions::applyValueCSSPropertyAnimationTimingFunction(StyleResolverState& state, const CSSValue& value)
{
    CSSAnimationData& data = state.style()->accessAnimations();
    data.timingFunctionList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.timingFunctionList().push_back(CSSToStyleMap::mapAnimationTimingFunction(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTransitionDelay(StyleResolverState& state)
{
    CSSTransitionData& data = state.style()->accessTransitions();
    data.delayList().clear();
    data.delayList().push_back(CSSTransitionData::initialDelay());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTransitionDelay(StyleResolverState& state)
{
    const CSSTransitionData* parentData = state.parentStyle()->transitions();
    if (!parentData)
        applyInitialCSSPropertyTransitionDelay(state);
    else
        state.style()->accessTransitions().delayList() = parentData->delayList();
}

void StyleBuilderFunctions::applyValueCSSPropertyTransitionDelay(StyleResolverState& state, const CSSValue& value)
{
    CSSTransitionData& data = state.style()->accessTransitions();
    data.delayList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.delayList().push_back(CSSToStyleMap::mapAnimationDelay(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTransitionDuration(StyleResolverState& state)
{
    CSSTransitionData& data = state.style()->accessTransitions();
    data.durationList().clear();
    data.durationList().push_back(CSSTransitionData::initialDuration());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTransitionDuration(StyleResolverState& state)
{
    const CSSTransitionData* parentData = state.parentStyle()->transitions();
    if (!parentData)
        applyInitialCSSPropertyTransitionDuration(state);
    else
        state.style()->accessTransitions().durationList() = parentData->durationList();
}

void StyleBuilderFunctions::applyValueCSSPropertyTransitionDuration(StyleResolverState& state, const CSSValue& value)
{
    CSSTransitionData& data = state.style()->accessTransitions();
    data.durationList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.durationList().push_back(CSSToStyleMap::mapAnimationDuration(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTransitionProperty(StyleResolverState& state)
{
    CSSTransitionData& data = state.style()->accessTransitions();
    data.propertyList().clear();
    data.propertyList().push_back(CSSTransitionData::initialProperty());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTransitionProperty(StyleResolverState& state)
{
    const CSSTransitionData* parentData = state.parentStyle()->transitions();
    if (!parentData)
        applyInitialCSSPropertyTransitionProperty(state);
    else
        state.style()->accessTransitions().propertyList() = parentData->propertyList();
}

void StyleBuilderFunctions::applyValueCSSPropertyTransitionProperty(StyleResolverState& state, const CSSValue& value)
{
    CSSTransitionData& data = state.style()->accessTransitions();
    data.propertyList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.propertyList().push_back(CSSToStyleMap::mapAnimationProperty(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyTransitionTimingFunction(StyleResolverState& state)
{
    CSSTransitionData& data = state.style()->accessTransitions();
    data.timingFunctionList().clear();
    data.timingFunctionList().push_back(CSSTransitionData::initialTimingFunction());
}

void StyleBuilderFunctions::applyInheritCSSPropertyTransitionTimingFunction(StyleResolverState& state)
{
    const CSSTransitionData* parentData = state.parentStyle()->transitions();
    if (!parentData)
        applyInitialCSSPropertyTransitionTimingFunction(state);
    else
        state.style()->accessTransitions().timingFunctionList() = parentData->timingFunctionList();
}

void StyleBuilderFunctions::applyValueCSSPropertyTransitionTimingFunction(StyleResolverState& state, const CSSValue& value)
{
    CSSTransitionData& data = state.style()->accessTransitions();
    data.timingFunctionList().clear();
    for (auto& listValue : toCSSValueList(value))
        data.timingFunctionList().push_back(CSSToStyleMap::mapAnimationTimingFunction(*listValue));
}

void StyleBuilderFunctions::applyInitialCSSPropertyClip(StyleResolverState& state)
{
    state.style()->setHasAutoClip();
}

void StyleBuilderFunctions::applyInheritCSSPropertyClip(StyleResolverState& state)
{
    if (state.parentStyle()->hasAutoClip())
        state.style()->setHasAutoClip();
    else
        state.style()->setClip(state.parentStyle()->clip());
}

void StyleBuilderFunctions::applyValueCSSPropertyClip(StyleResolverState& state, const CSSValue& value)
{
    if (value.isIdentifierValue() && toCSSIdentifierValue(value).getValueID() == CSSValueAuto)
        state.style()->setHasAutoClip();
    else
        state.style()->setClip(StyleBuilderConverter::convertClip(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyColumnCount(StyleResolverState& state)
{
    state.style()->setHasAutoColumnCount();
}

void StyleBuilderFunctions::applyInheritCSSPropertyColumnCount(StyleResolverState& state)
{
    if (state.parentStyle()->hasAutoColumnCount())
        state.style()->setHasAutoColumnCount();
    else
        state.style()->setColumnCount(state.parentStyle()->columnCount());
}

void StyleBuilderFunctions::applyValueCSSPropertyColumnCount(StyleResolverState& state, const CSSValue& value)
{
    if (value.isIdentifierValue() && toCSSIdentifierValue(value).getValueID() == CSSValueAuto)
        state.style()->setHasAutoColumnCount();
    else
        state.style()->setColumnCount(toCSSPrimitiveValue(value).convertTo<unsigned short>());
}

void StyleBuilderFunctions::applyInitialCSSPropertyColumnGap(StyleResolverState& state)
{
    state.style()->setHasNormalColumnGap();
}

void StyleBuilderFunctions::applyInheritCSSPropertyColumnGap(StyleResolverState& state)
{
    if (state.parentStyle()->hasNormalColumnGap())
        state.style()->setHasNormalColumnGap();
    else
        state.style()->setColumnGap(state.parentStyle()->columnGap());
}

void StyleBuilderFunctions::applyValueCSSPropertyColumnGap(StyleResolverState& state, const CSSValue& value)
{
    if (value.isIdentifierValue() && toCSSIdentifierValue(value).getValueID() == CSSValueNormal)
        state.style()->setHasNormalColumnGap();
    else
        state.style()->setColumnGap(StyleBuilderConverter::convertComputedLength<float>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyColumnWidth(StyleResolverState& state)
{
    state.style()->setHasAutoColumnWidth();
}

void StyleBuilderFunctions::applyInheritCSSPropertyColumnWidth(StyleResolverState& state)
{
    if (state.parentStyle()->hasAutoColumnWidth())
        state.style()->setHasAutoColumnWidth();
    else
        state.style()->setColumnWidth(state.parentStyle()->columnWidth());
}

void StyleBuilderFunctions::applyValueCSSPropertyColumnWidth(StyleResolverState& state, const CSSValue& value)
{
    if (value.isIdentifierValue() && toCSSIdentifierValue(value).getValueID() == CSSValueAuto)
        state.style()->setHasAutoColumnWidth();
    else
        state.style()->setColumnWidth(StyleBuilderConverter::convertComputedLength<float>(state, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyZIndex(StyleResolverState& state)
{
    state.style()->setHasAutoZIndex();
}

void StyleBuilderFunctions::applyInheritCSSPropertyZIndex(StyleResolverState& state)
{
    if (state.parentStyle()->hasAutoZIndex())
        state.style()->setHasAutoZIndex();
    else
        state.style()->setZIndex(state.parentStyle()->zIndex());
}

void StyleBuilderFunctions::applyValueCSSPropertyZIndex(StyleResolverState& state, const CSSValue& value)
{
    if (value.isIdentifierValue() && toCSSIdentifierValue(value).getValueID() == CSSValueAuto)
        state.style()->setHasAutoZIndex();
    else
        state.style()->setZIndex(toCSSPrimitiveValue(value).convertTo<int>());
}

static bool lengthMatchesAllSides(const LengthBox& lengthBox,
    const Length& length)
{
    return (lengthBox.left() == length && lengthBox.right() == length && lengthBox.top() == length && lengthBox.bottom() == length);
}

static bool borderImageLengthMatchesAllSides(
    const BorderImageLengthBox& borderImageLengthBox,
    const BorderImageLength& borderImageLength)
{
    return (borderImageLengthBox.left() == borderImageLength && borderImageLengthBox.right() == borderImageLength && borderImageLengthBox.top() == borderImageLength && borderImageLengthBox.bottom() == borderImageLength);
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderImageOutset(StyleResolverState& state)
{
    const NinePieceImage& currentImage = state.style()->borderImage();
    if (borderImageLengthMatchesAllSides(currentImage.outset(),
            BorderImageLength(Length(0, Fixed))))
        return;

    NinePieceImage image(currentImage);
    image.setOutset(Length(0, Fixed));
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderImageOutset(StyleResolverState& state)
{
    NinePieceImage image(state.style()->borderImage());
    image.copyOutsetFrom(state.parentStyle()->borderImage());
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderImageOutset(StyleResolverState& state, const CSSValue& value)
{
    NinePieceImage image(state.style()->borderImage());
    image.setOutset(CSSToStyleMap::mapNinePieceImageQuad(state, value));
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderImageRepeat(StyleResolverState& state)
{
    const NinePieceImage& currentImage = state.style()->borderImage();
    if (currentImage.horizontalRule() == StretchImageRule && currentImage.verticalRule() == StretchImageRule)
        return;

    NinePieceImage image(currentImage);
    image.setHorizontalRule(StretchImageRule);
    image.setVerticalRule(StretchImageRule);
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderImageRepeat(StyleResolverState& state)
{
    NinePieceImage image(state.style()->borderImage());
    image.copyRepeatFrom(state.parentStyle()->borderImage());
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderImageRepeat(StyleResolverState& state, const CSSValue& value)
{
    NinePieceImage image(state.style()->borderImage());
    CSSToStyleMap::mapNinePieceImageRepeat(state, value, image);
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderImageSlice(StyleResolverState& state)
{
    const NinePieceImage& currentImage = state.style()->borderImage();
    if (currentImage.fill() == false && lengthMatchesAllSides(currentImage.imageSlices(), Length(100, Percent)))
        return;

    NinePieceImage image(currentImage);
    image.setImageSlices(LengthBox(Length(100, Percent), Length(100, Percent), Length(100, Percent), Length(100, Percent)));
    image.setFill(false);
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderImageSlice(StyleResolverState& state)
{
    NinePieceImage image(state.style()->borderImage());
    image.copyImageSlicesFrom(state.parentStyle()->borderImage());
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderImageSlice(StyleResolverState& state, const CSSValue& value)
{
    NinePieceImage image(state.style()->borderImage());
    CSSToStyleMap::mapNinePieceImageSlice(state, value, image);
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderImageWidth(StyleResolverState& state)
{
    const NinePieceImage& currentImage = state.style()->borderImage();
    if (borderImageLengthMatchesAllSides(currentImage.borderSlices(),
            BorderImageLength(1.0)))
        return;

    NinePieceImage image(currentImage);
    image.setBorderSlices(1.0);
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderImageWidth(StyleResolverState& state)
{
    NinePieceImage image(state.style()->borderImage());
    image.copyBorderSlicesFrom(state.parentStyle()->borderImage());
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderImageWidth(StyleResolverState& state, const CSSValue& value)
{
    NinePieceImage image(state.style()->borderImage());
    image.setBorderSlices(CSSToStyleMap::mapNinePieceImageQuad(state, value));
    state.style()->setBorderImage(image);
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskBoxImageOutset(StyleResolverState& state)
{
    const NinePieceImage& currentImage = state.style()->maskBoxImage();
    if (borderImageLengthMatchesAllSides(currentImage.outset(),
            BorderImageLength(Length(0, Fixed))))
        return;

    NinePieceImage image(currentImage);
    image.setOutset(Length(0, Fixed));
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskBoxImageOutset(StyleResolverState& state)
{
    NinePieceImage image(state.style()->maskBoxImage());
    image.copyOutsetFrom(state.parentStyle()->maskBoxImage());
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskBoxImageOutset(StyleResolverState& state, const CSSValue& value)
{
    NinePieceImage image(state.style()->maskBoxImage());
    image.setOutset(CSSToStyleMap::mapNinePieceImageQuad(state, value));
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskBoxImageRepeat(StyleResolverState& state)
{
    const NinePieceImage& currentImage = state.style()->maskBoxImage();
    if (currentImage.horizontalRule() == StretchImageRule && currentImage.verticalRule() == StretchImageRule)
        return;

    NinePieceImage image(currentImage);
    image.setHorizontalRule(StretchImageRule);
    image.setVerticalRule(StretchImageRule);
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskBoxImageRepeat(StyleResolverState& state)
{
    NinePieceImage image(state.style()->maskBoxImage());
    image.copyRepeatFrom(state.parentStyle()->maskBoxImage());
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskBoxImageRepeat(StyleResolverState& state, const CSSValue& value)
{
    NinePieceImage image(state.style()->maskBoxImage());
    CSSToStyleMap::mapNinePieceImageRepeat(state, value, image);
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskBoxImageSlice(StyleResolverState& state)
{
    const NinePieceImage& currentImage = state.style()->maskBoxImage();
    // Masks have a different initial value for slices. Preserve the value of 0
    // for backwards compatibility.
    if (currentImage.fill() == true && lengthMatchesAllSides(currentImage.imageSlices(), Length(0, Fixed)))
        return;

    NinePieceImage image(currentImage);
    image.setImageSlices(LengthBox(Length(0, Fixed), Length(0, Fixed), Length(0, Fixed), Length(0, Fixed)));
    image.setFill(true);
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskBoxImageSlice(StyleResolverState& state)
{
    NinePieceImage image(state.style()->maskBoxImage());
    image.copyImageSlicesFrom(state.parentStyle()->maskBoxImage());
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskBoxImageSlice(StyleResolverState& state, const CSSValue& value)
{
    NinePieceImage image(state.style()->maskBoxImage());
    CSSToStyleMap::mapNinePieceImageSlice(state, value, image);
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskBoxImageWidth(StyleResolverState& state)
{
    const NinePieceImage& currentImage = state.style()->maskBoxImage();
    // Masks have a different initial value for widths. Preserve the value of
    // 'auto' for backwards compatibility.
    if (borderImageLengthMatchesAllSides(currentImage.borderSlices(),
            BorderImageLength(Length(Auto))))
        return;

    NinePieceImage image(currentImage);
    image.setBorderSlices(Length(Auto));
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskBoxImageWidth(StyleResolverState& state)
{
    NinePieceImage image(state.style()->maskBoxImage());
    image.copyBorderSlicesFrom(state.parentStyle()->maskBoxImage());
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskBoxImageWidth(StyleResolverState& state, const CSSValue& value)
{
    NinePieceImage image(state.style()->maskBoxImage());
    image.setBorderSlices(CSSToStyleMap::mapNinePieceImageQuad(state, value));
    state.style()->setMaskBoxImage(image);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderImageSource(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setBorderImageSource(state.styleImage(CSSPropertyBorderImageSource, value));
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskBoxImageSource(StyleResolverState& state, const CSSValue& value)
{
    state.style()->setMaskBoxImageSource(state.styleImage(CSSPropertyWebkitMaskBoxImageSource, value));
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundColor(StyleResolverState& state)
{
    StyleColor color = ComputedStyle::initialBackgroundColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBackgroundColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBackgroundColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->backgroundColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBackgroundColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBackgroundColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setBackgroundColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkBackgroundColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderBottomColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderBottomColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBorderBottomColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderBottomColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->borderBottomColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderBottomColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBorderBottomColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderBottomColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderBottomColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkBorderBottomColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderLeftColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderLeftColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBorderLeftColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderLeftColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->borderLeftColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderLeftColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBorderLeftColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderLeftColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderLeftColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkBorderLeftColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderRightColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderRightColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBorderRightColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderRightColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->borderRightColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderRightColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBorderRightColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderRightColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderRightColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkBorderRightColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBorderTopColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderTopColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBorderTopColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyBorderTopColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->borderTopColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderTopColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkBorderTopColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyBorderTopColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setBorderTopColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkBorderTopColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyOutlineColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setOutlineColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkOutlineColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyOutlineColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->outlineColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setOutlineColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkOutlineColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyOutlineColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setOutlineColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkOutlineColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyTextDecorationColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextDecorationColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkTextDecorationColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyTextDecorationColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->textDecorationColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextDecorationColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkTextDecorationColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyTextDecorationColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextDecorationColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkTextDecorationColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyColumnRuleColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setColumnRuleColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkColumnRuleColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyColumnRuleColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->columnRuleColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setColumnRuleColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkColumnRuleColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyColumnRuleColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setColumnRuleColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkColumnRuleColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTextEmphasisColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextEmphasisColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkTextEmphasisColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTextEmphasisColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->textEmphasisColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextEmphasisColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkTextEmphasisColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTextEmphasisColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextEmphasisColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkTextEmphasisColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTextFillColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextFillColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkTextFillColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTextFillColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->textFillColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextFillColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkTextFillColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTextFillColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextFillColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkTextFillColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitTextStrokeColor(StyleResolverState& state)
{
    StyleColor color = StyleColor::currentColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextStrokeColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkTextStrokeColor(color);
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitTextStrokeColor(StyleResolverState& state)
{
    // Visited link style can never explicitly inherit from parent visited link
    // style so no separate getters are needed.
    StyleColor color = state.parentStyle()->textStrokeColor();
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextStrokeColor(color);
    if (state.applyPropertyToVisitedLinkStyle())
        state.style()->setVisitedLinkTextStrokeColor(color);
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitTextStrokeColor(StyleResolverState& state, const CSSValue& value)
{
    if (state.applyPropertyToRegularStyle())
        state.style()->setTextStrokeColor(StyleBuilderConverter::convertStyleColor(state, value));
    if (state.applyPropertyToVisitedLinkStyle()) {
        state.style()->setVisitedLinkTextStrokeColor(
            StyleBuilderConverter::convertStyleColor(state, value, true));
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyCounterIncrement(StyleResolverState& state)
{
    state.style()->clearIncrementDirectives();
}

void StyleBuilderFunctions::applyInheritCSSPropertyCounterIncrement(StyleResolverState& state)
{
    const CounterDirectiveMap* parentMap = state.parentStyle()->counterDirectives();
    if (!parentMap)
        return;

    CounterDirectiveMap& map = state.style()->accessCounterDirectives();
    DCHECK(!parentMap->isEmpty());

    typedef CounterDirectiveMap::const_iterator Iterator;
    Iterator end = parentMap->end();
    for (Iterator it = parentMap->begin(); it != end; ++it) {
        CounterDirectives& directives = map.add(it->key, CounterDirectives()).storedValue->value;
        directives.inheritIncrement(it->value);
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyCounterIncrement(StyleResolverState& state, const CSSValue& value)
{
    state.style()->clearIncrementDirectives();

    if (!value.isValueList()) {
        DCHECK(value.isIdentifierValue());
        DCHECK_EQ(toCSSIdentifierValue(value).getValueID(), CSSValueNone);
        return;
    }

    CounterDirectiveMap& map = state.style()->accessCounterDirectives();

    const CSSValueList& list = toCSSValueList(value);

    for (size_t i = 0; i < list.length(); ++i) {
        const CSSValuePair& pair = toCSSValuePair(list.item(i));
        AtomicString identifier(toCSSCustomIdentValue(pair.first()).value());
        int value = toCSSPrimitiveValue(pair.second()).getIntValue();
        CounterDirectives& directives = map.add(identifier, CounterDirectives()).storedValue->value;
        directives.addIncrementValue(value);
    }
    DCHECK(!map.isEmpty());
}

void StyleBuilderFunctions::applyInitialCSSPropertyCounterReset(StyleResolverState& state)
{
    state.style()->clearResetDirectives();
}

void StyleBuilderFunctions::applyInheritCSSPropertyCounterReset(StyleResolverState& state)
{
    const CounterDirectiveMap* parentMap = state.parentStyle()->counterDirectives();
    if (!parentMap)
        return;

    CounterDirectiveMap& map = state.style()->accessCounterDirectives();
    DCHECK(!parentMap->isEmpty());

    typedef CounterDirectiveMap::const_iterator Iterator;
    Iterator end = parentMap->end();
    for (Iterator it = parentMap->begin(); it != end; ++it) {
        CounterDirectives& directives = map.add(it->key, CounterDirectives()).storedValue->value;
        directives.inheritReset(it->value);
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyCounterReset(StyleResolverState& state, const CSSValue& value)
{
    state.style()->clearResetDirectives();

    if (!value.isValueList()) {
        DCHECK(value.isIdentifierValue());
        DCHECK_EQ(toCSSIdentifierValue(value).getValueID(), CSSValueNone);
        return;
    }

    CounterDirectiveMap& map = state.style()->accessCounterDirectives();

    const CSSValueList& list = toCSSValueList(value);

    for (size_t i = 0; i < list.length(); ++i) {
        const CSSValuePair& pair = toCSSValuePair(list.item(i));
        AtomicString identifier(toCSSCustomIdentValue(pair.first()).value());
        int value = toCSSPrimitiveValue(pair.second()).getIntValue();
        CounterDirectives& directives = map.add(identifier, CounterDirectives()).storedValue->value;
        directives.setResetValue(value);
    }
    DCHECK(!map.isEmpty());
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundAttachment(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setAttachment(FillLayer::initialFillAttachment(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearAttachment();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundAttachment(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isAttachmentSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setAttachment(currParent->attachment());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearAttachment();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundAttachment(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillAttachment(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillAttachment(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearAttachment();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundBlendMode(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setBlendMode(FillLayer::initialFillBlendMode(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearBlendMode();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundBlendMode(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isBlendModeSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setBlendMode(currParent->blendMode());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearBlendMode();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundBlendMode(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillBlendMode(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillBlendMode(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearBlendMode();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundClip(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setClip(FillLayer::initialFillClip(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearClip();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundClip(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isClipSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setClip(currParent->clip());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearClip();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundClip(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillClip(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillClip(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearClip();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundImage(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setImage(FillLayer::initialFillImage(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearImage();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundImage(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isImageSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setImage(currParent->image());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearImage();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundImage(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillImage(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillImage(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearImage();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundOrigin(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setOrigin(FillLayer::initialFillOrigin(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearOrigin();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundOrigin(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isOriginSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setOrigin(currParent->origin());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearOrigin();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundOrigin(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillOrigin(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillOrigin(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearOrigin();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundPositionX(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setXPosition(FillLayer::initialFillXPosition(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearXPosition();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundPositionX(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isXPositionSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setXPosition(currParent->xPosition());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearXPosition();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundPositionX(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillXPosition(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillXPosition(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearXPosition();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundPositionY(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setYPosition(FillLayer::initialFillYPosition(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearYPosition();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundPositionY(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isYPositionSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setYPosition(currParent->yPosition());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearYPosition();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundPositionY(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillYPosition(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillYPosition(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearYPosition();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundRepeatX(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setRepeatX(FillLayer::initialFillRepeatX(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearRepeatX();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundRepeatX(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isRepeatXSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setRepeatX(currParent->repeatX());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearRepeatX();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundRepeatX(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillRepeatX(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillRepeatX(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearRepeatX();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundRepeatY(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setRepeatY(FillLayer::initialFillRepeatY(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearRepeatY();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundRepeatY(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isRepeatYSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setRepeatY(currParent->repeatY());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearRepeatY();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundRepeatY(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillRepeatY(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillRepeatY(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearRepeatY();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyBackgroundSize(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    currChild->setSize(FillLayer::initialFillSize(BackgroundFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearSize();
}

void StyleBuilderFunctions::applyInheritCSSPropertyBackgroundSize(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->backgroundLayers();
    while (currParent && currParent->isSizeSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setSize(currParent->size());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearSize();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyBackgroundSize(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessBackgroundLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillSize(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillSize(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearSize();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyMaskSourceType(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setMaskSourceType(FillLayer::initialFillMaskSourceType(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearMaskSourceType();
}

void StyleBuilderFunctions::applyInheritCSSPropertyMaskSourceType(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isMaskSourceTypeSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setMaskSourceType(currParent->maskSourceType());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearMaskSourceType();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyMaskSourceType(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillMaskSourceType(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillMaskSourceType(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearMaskSourceType();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskClip(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setClip(FillLayer::initialFillClip(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearClip();
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskClip(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isClipSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setClip(currParent->clip());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearClip();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskClip(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillClip(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillClip(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearClip();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskComposite(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setComposite(FillLayer::initialFillComposite(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearComposite();
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskComposite(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isCompositeSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setComposite(currParent->composite());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearComposite();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskComposite(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillComposite(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillComposite(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearComposite();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskImage(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setImage(FillLayer::initialFillImage(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearImage();
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskImage(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isImageSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setImage(currParent->image());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearImage();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskImage(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillImage(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillImage(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearImage();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskOrigin(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setOrigin(FillLayer::initialFillOrigin(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearOrigin();
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskOrigin(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isOriginSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setOrigin(currParent->origin());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearOrigin();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskOrigin(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillOrigin(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillOrigin(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearOrigin();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskPositionX(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setXPosition(FillLayer::initialFillXPosition(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearXPosition();
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskPositionX(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isXPositionSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setXPosition(currParent->xPosition());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearXPosition();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskPositionX(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillXPosition(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillXPosition(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearXPosition();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskPositionY(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setYPosition(FillLayer::initialFillYPosition(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearYPosition();
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskPositionY(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isYPositionSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setYPosition(currParent->yPosition());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearYPosition();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskPositionY(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillYPosition(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillYPosition(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearYPosition();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskRepeatX(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setRepeatX(FillLayer::initialFillRepeatX(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearRepeatX();
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskRepeatX(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isRepeatXSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setRepeatX(currParent->repeatX());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearRepeatX();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskRepeatX(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillRepeatX(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillRepeatX(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearRepeatX();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskRepeatY(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setRepeatY(FillLayer::initialFillRepeatY(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearRepeatY();
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskRepeatY(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isRepeatYSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setRepeatY(currParent->repeatY());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearRepeatY();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskRepeatY(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillRepeatY(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillRepeatY(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearRepeatY();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyWebkitMaskSize(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    currChild->setSize(FillLayer::initialFillSize(MaskFillLayer));
    for (currChild = currChild->next(); currChild; currChild = currChild->next())
        currChild->clearSize();
}

void StyleBuilderFunctions::applyInheritCSSPropertyWebkitMaskSize(StyleResolverState& state)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    const FillLayer* currParent = &state.parentStyle()->maskLayers();
    while (currParent && currParent->isSizeSet()) {
        if (!currChild)
            currChild = prevChild->ensureNext();
        currChild->setSize(currParent->size());
        prevChild = currChild;
        currChild = prevChild->next();
        currParent = currParent->next();
    }

    while (currChild) {
        // Reset any remaining layers to not have the property set.
        currChild->clearSize();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyValueCSSPropertyWebkitMaskSize(StyleResolverState& state, const CSSValue& value)
{
    FillLayer* currChild = &state.style()->accessMaskLayers();
    FillLayer* prevChild = 0;
    if (value.isValueList() && !value.isImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        const CSSValueList& valueList = toCSSValueList(value);
        for (unsigned int i = 0; i < valueList.length(); i++) {
            if (!currChild)
                currChild = prevChild->ensureNext();
            CSSToStyleMap::mapFillSize(state, currChild, valueList.item(i));
            prevChild = currChild;
            currChild = currChild->next();
        }
    } else {
        CSSToStyleMap::mapFillSize(state, currChild, value);
        currChild = currChild->next();
    }
    while (currChild) {
        // Reset all remaining layers to not have the property set.
        currChild->clearSize();
        currChild = currChild->next();
    }
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridTemplateColumns(StyleResolverState& state)
{
    state.style()->setGridTemplateColumns(ComputedStyle::initialGridTemplateColumns());
    state.style()->setNamedGridColumnLines(ComputedStyle::initialNamedGridColumnLines());
    state.style()->setOrderedNamedGridColumnLines(ComputedStyle::initialOrderedNamedGridColumnLines());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridTemplateColumns(StyleResolverState& state)
{
    state.style()->setGridTemplateColumns(state.parentStyle()->gridTemplateColumns());
    state.style()->setNamedGridColumnLines(state.parentStyle()->namedGridColumnLines());
    state.style()->setOrderedNamedGridColumnLines(state.parentStyle()->orderedNamedGridColumnLines());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridTemplateColumns(StyleResolverState& state, const CSSValue& value)
{
    Vector<GridTrackSize> trackSizes;
    Vector<GridTrackSize> autoRepeatTrackSizes;
    NamedGridLinesMap namedGridLines;
    OrderedNamedGridLines orderedNamedGridLines;
    NamedGridLinesMap autoRepeatNamedGridLines;
    OrderedNamedGridLines autoRepeatOrderedNamedGridLines;
    AutoRepeatType autoRepeatType = ComputedStyle::initialGridAutoRepeatType();
    size_t autoRepeatInsertionPoint = ComputedStyle::initialGridAutoRepeatInsertionPoint();
    StyleBuilderConverter::convertGridTrackList(
        value, trackSizes, namedGridLines, orderedNamedGridLines,
        autoRepeatTrackSizes, autoRepeatNamedGridLines,
        autoRepeatOrderedNamedGridLines, autoRepeatInsertionPoint,
        autoRepeatType, state);
    const NamedGridAreaMap& namedGridAreas = state.style()->namedGridArea();
    if (!namedGridAreas.isEmpty()) {
        StyleBuilderConverter::createImplicitNamedGridLinesFromGridArea(
            namedGridAreas, namedGridLines, ForColumns);
    }
    state.style()->setGridTemplateColumns(trackSizes);
    state.style()->setNamedGridColumnLines(namedGridLines);
    state.style()->setOrderedNamedGridColumnLines(orderedNamedGridLines);
    state.style()->setGridAutoRepeatColumns(autoRepeatTrackSizes);
    state.style()->setGridAutoRepeatColumnsInsertionPoint(
        autoRepeatInsertionPoint);
    state.style()->setAutoRepeatNamedGridColumnLines(autoRepeatNamedGridLines);
    state.style()->setAutoRepeatOrderedNamedGridColumnLines(
        autoRepeatOrderedNamedGridLines);
    state.style()->setGridAutoRepeatColumnsType(autoRepeatType);
}

void StyleBuilderFunctions::applyInitialCSSPropertyGridTemplateRows(StyleResolverState& state)
{
    state.style()->setGridTemplateRows(ComputedStyle::initialGridTemplateRows());
    state.style()->setNamedGridRowLines(ComputedStyle::initialNamedGridRowLines());
    state.style()->setOrderedNamedGridRowLines(ComputedStyle::initialOrderedNamedGridRowLines());
}

void StyleBuilderFunctions::applyInheritCSSPropertyGridTemplateRows(StyleResolverState& state)
{
    state.style()->setGridTemplateRows(state.parentStyle()->gridTemplateRows());
    state.style()->setNamedGridRowLines(state.parentStyle()->namedGridRowLines());
    state.style()->setOrderedNamedGridRowLines(state.parentStyle()->orderedNamedGridRowLines());
}

void StyleBuilderFunctions::applyValueCSSPropertyGridTemplateRows(StyleResolverState& state, const CSSValue& value)
{
    Vector<GridTrackSize> trackSizes;
    Vector<GridTrackSize> autoRepeatTrackSizes;
    NamedGridLinesMap namedGridLines;
    OrderedNamedGridLines orderedNamedGridLines;
    NamedGridLinesMap autoRepeatNamedGridLines;
    OrderedNamedGridLines autoRepeatOrderedNamedGridLines;
    AutoRepeatType autoRepeatType = ComputedStyle::initialGridAutoRepeatType();
    size_t autoRepeatInsertionPoint = ComputedStyle::initialGridAutoRepeatInsertionPoint();
    StyleBuilderConverter::convertGridTrackList(
        value, trackSizes, namedGridLines, orderedNamedGridLines,
        autoRepeatTrackSizes, autoRepeatNamedGridLines,
        autoRepeatOrderedNamedGridLines, autoRepeatInsertionPoint,
        autoRepeatType, state);
    const NamedGridAreaMap& namedGridAreas = state.style()->namedGridArea();
    if (!namedGridAreas.isEmpty()) {
        StyleBuilderConverter::createImplicitNamedGridLinesFromGridArea(
            namedGridAreas, namedGridLines, ForRows);
    }
    state.style()->setGridTemplateRows(trackSizes);
    state.style()->setNamedGridRowLines(namedGridLines);
    state.style()->setOrderedNamedGridRowLines(orderedNamedGridLines);
    state.style()->setGridAutoRepeatRows(autoRepeatTrackSizes);
    state.style()->setGridAutoRepeatRowsInsertionPoint(
        autoRepeatInsertionPoint);
    state.style()->setAutoRepeatNamedGridRowLines(autoRepeatNamedGridLines);
    state.style()->setAutoRepeatOrderedNamedGridRowLines(
        autoRepeatOrderedNamedGridLines);
    state.style()->setGridAutoRepeatRowsType(autoRepeatType);
}

void StyleBuilderFunctions::applyInitialCSSPropertyFill(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setFillPaint(
        SVGComputedStyle::initialFillPaintType(),
        SVGComputedStyle::initialFillPaintColor(),
        SVGComputedStyle::initialFillPaintUri(),
        state.applyPropertyToRegularStyle(),
        state.applyPropertyToVisitedLinkStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyFill(StyleResolverState& state)
{
    const SVGComputedStyle& svgParentStyle = state.parentStyle()->svgStyle();
    state.style()->accessSVGStyle().setFillPaint(
        svgParentStyle.fillPaintType(),
        svgParentStyle.fillPaintColor(),
        svgParentStyle.fillPaintUri(),
        state.applyPropertyToRegularStyle(),
        state.applyPropertyToVisitedLinkStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyFill(StyleResolverState& state, const CSSValue& value)
{
    const CSSValue* localValue = &value;
    String url;
    if (value.isValueList()) {
        const CSSValueList& list = toCSSValueList(value);
        DCHECK_EQ(list.length(), 2U);
        url = toCSSURIValue(list.item(0)).value();
        localValue = &list.item(1);
    }

    Color color;
    SVGPaintType paintType = SVG_PAINTTYPE_RGBCOLOR;
    if (localValue->isURIValue()) {
        paintType = SVG_PAINTTYPE_URI;
        url = toCSSURIValue(localValue)->value();
    } else if (localValue->isIdentifierValue() && toCSSIdentifierValue(localValue)->getValueID() == CSSValueNone) {
        paintType = url.isEmpty() ? SVG_PAINTTYPE_NONE : SVG_PAINTTYPE_URI_NONE;
    } else if (localValue->isIdentifierValue() && toCSSIdentifierValue(localValue)->getValueID() == CSSValueCurrentcolor) {
        color = state.style()->color();
        paintType = url.isEmpty() ? SVG_PAINTTYPE_CURRENTCOLOR
                                  : SVG_PAINTTYPE_URI_CURRENTCOLOR;
    } else {
        color = StyleBuilderConverter::convertColor(state, *localValue);
        paintType = url.isEmpty() ? SVG_PAINTTYPE_RGBCOLOR
                                  : SVG_PAINTTYPE_URI_RGBCOLOR;
    }
    state.style()->accessSVGStyle().setFillPaint(paintType, color, url,
        state.applyPropertyToRegularStyle(),
        state.applyPropertyToVisitedLinkStyle());
}

void StyleBuilderFunctions::applyInitialCSSPropertyStroke(StyleResolverState& state)
{
    state.style()->accessSVGStyle().setStrokePaint(
        SVGComputedStyle::initialStrokePaintType(),
        SVGComputedStyle::initialStrokePaintColor(),
        SVGComputedStyle::initialStrokePaintUri(),
        state.applyPropertyToRegularStyle(),
        state.applyPropertyToVisitedLinkStyle());
}

void StyleBuilderFunctions::applyInheritCSSPropertyStroke(StyleResolverState& state)
{
    const SVGComputedStyle& svgParentStyle = state.parentStyle()->svgStyle();
    state.style()->accessSVGStyle().setStrokePaint(
        svgParentStyle.strokePaintType(),
        svgParentStyle.strokePaintColor(),
        svgParentStyle.strokePaintUri(),
        state.applyPropertyToRegularStyle(),
        state.applyPropertyToVisitedLinkStyle());
}

void StyleBuilderFunctions::applyValueCSSPropertyStroke(StyleResolverState& state, const CSSValue& value)
{
    const CSSValue* localValue = &value;
    String url;
    if (value.isValueList()) {
        const CSSValueList& list = toCSSValueList(value);
        DCHECK_EQ(list.length(), 2U);
        url = toCSSURIValue(list.item(0)).value();
        localValue = &list.item(1);
    }

    Color color;
    SVGPaintType paintType = SVG_PAINTTYPE_RGBCOLOR;
    if (localValue->isURIValue()) {
        paintType = SVG_PAINTTYPE_URI;
        url = toCSSURIValue(localValue)->value();
    } else if (localValue->isIdentifierValue() && toCSSIdentifierValue(localValue)->getValueID() == CSSValueNone) {
        paintType = url.isEmpty() ? SVG_PAINTTYPE_NONE : SVG_PAINTTYPE_URI_NONE;
    } else if (localValue->isIdentifierValue() && toCSSIdentifierValue(localValue)->getValueID() == CSSValueCurrentcolor) {
        color = state.style()->color();
        paintType = url.isEmpty() ? SVG_PAINTTYPE_CURRENTCOLOR
                                  : SVG_PAINTTYPE_URI_CURRENTCOLOR;
    } else {
        color = StyleBuilderConverter::convertColor(state, *localValue);
        paintType = url.isEmpty() ? SVG_PAINTTYPE_RGBCOLOR
                                  : SVG_PAINTTYPE_URI_RGBCOLOR;
    }
    state.style()->accessSVGStyle().setStrokePaint(paintType, color, url,
        state.applyPropertyToRegularStyle(),
        state.applyPropertyToVisitedLinkStyle());
}

} // namespace blink
