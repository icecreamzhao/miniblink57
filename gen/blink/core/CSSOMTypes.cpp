// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/css/cssom/CSSOMTypes.h"

#include "core/css/CSSPropertyMetadata.h"
#include "core/css/cssom/CSSKeywordValue.h"
#include "core/css/cssom/CSSLengthValue.h"
#include "core/css/cssom/CSSOMKeywords.h"
#include "core/css/cssom/CSSStyleValue.h"

namespace blink {

bool CSSOMTypes::propertyCanTake(CSSPropertyID id,
    const CSSStyleValue& styleValue)
{
    // Shortcut special case.
    if (styleValue.type() == CSSStyleValue::SimpleLengthType || styleValue.type() == CSSStyleValue::CalcLengthType) {
        if (toCSSLengthValue(styleValue).containsPercent() && !CSSPropertyMetadata::propertySupportsPercentage(id)) {
            return false;
        }
    } else if (styleValue.type() == CSSStyleValue::KeywordType) {
        // Keywords are also handled differently.
        return CSSOMKeywords::validKeywordForProperty(
            id, toCSSKeywordValue(styleValue));
    } else if (styleValue.type() == CSSStyleValue::Unknown) {
        // The check happens later in this case.
        return true;
    }

    return CSSOMTypes::propertyCanTakeType(id, styleValue.type());
}

bool CSSOMTypes::propertyCanTakeType(CSSPropertyID id,
    CSSStyleValue::StyleValueType type)
{
    switch (id) {
    case CSSPropertyShapeOutside:
        return (
            type == CSSStyleValue::URLImageType);
    case CSSPropertyHeight:
        return (
            type == CSSStyleValue::SimpleLengthType
            || type == CSSStyleValue::CalcLengthType);
    case CSSPropertyBorderImageSource:
        return (
            type == CSSStyleValue::URLImageType);
    case CSSPropertyContent:
        return (
            type == CSSStyleValue::URLImageType);
    case CSSPropertyTransform:
        return (
            type == CSSStyleValue::TransformType);
    case CSSPropertyBackgroundImage:
        return (
            type == CSSStyleValue::URLImageType);
    case CSSPropertyBorderTopWidth:
        return (
            type == CSSStyleValue::SimpleLengthType
            || type == CSSStyleValue::CalcLengthType);
    case CSSPropertyBottom:
        return (
            type == CSSStyleValue::SimpleLengthType
            || type == CSSStyleValue::CalcLengthType);
    case CSSPropertyTop:
        return (
            type == CSSStyleValue::SimpleLengthType
            || type == CSSStyleValue::CalcLengthType);
    case CSSPropertyLeft:
        return (
            type == CSSStyleValue::SimpleLengthType
            || type == CSSStyleValue::CalcLengthType);
    case CSSPropertyWidth:
        return (
            type == CSSStyleValue::SimpleLengthType
            || type == CSSStyleValue::CalcLengthType);
    case CSSPropertyRight:
        return (
            type == CSSStyleValue::SimpleLengthType
            || type == CSSStyleValue::CalcLengthType);
    case CSSPropertyListStyleImage:
        return (
            type == CSSStyleValue::URLImageType);
    default:
        return false;
    }
}

} // namespace blink
