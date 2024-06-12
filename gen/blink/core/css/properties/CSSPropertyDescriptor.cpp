// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#include "core/css/properties/CSSPropertyDescriptor.h"

#include "core/css/properties/CSSPropertyAPIBorderRadius.h"
#include "core/css/properties/CSSPropertyAPICaretColor.h"
#include "core/css/properties/CSSPropertyAPIClip.h"
#include "core/css/properties/CSSPropertyAPIColumnGap.h"
#include "core/css/properties/CSSPropertyAPIContain.h"
#include "core/css/properties/CSSPropertyAPIContent.h"
#include "core/css/properties/CSSPropertyAPICursor.h"
#include "core/css/properties/CSSPropertyAPIFlexBasis.h"
#include "core/css/properties/CSSPropertyAPIFontSizeAdjust.h"
#include "core/css/properties/CSSPropertyAPIFontVariantCaps.h"
#include "core/css/properties/CSSPropertyAPIFontVariantLigatures.h"
#include "core/css/properties/CSSPropertyAPIFontVariationSettings.h"
#include "core/css/properties/CSSPropertyAPIGridAutoFlow.h"
#include "core/css/properties/CSSPropertyAPILetterAndWordSpacing.h"
#include "core/css/properties/CSSPropertyAPIOffsetPosition.h"
#include "core/css/properties/CSSPropertyAPIOutlineColor.h"
#include "core/css/properties/CSSPropertyAPIOutlineOffset.h"
#include "core/css/properties/CSSPropertyAPIPage.h"
#include "core/css/properties/CSSPropertyAPIPaintOrder.h"
#include "core/css/properties/CSSPropertyAPIPaintStroke.h"
#include "core/css/properties/CSSPropertyAPIQuotes.h"
#include "core/css/properties/CSSPropertyAPIRotate.h"
#include "core/css/properties/CSSPropertyAPIScale.h"
#include "core/css/properties/CSSPropertyAPIScrollSnapCoordinate.h"
#include "core/css/properties/CSSPropertyAPIShapeMargin.h"
#include "core/css/properties/CSSPropertyAPISize.h"
#include "core/css/properties/CSSPropertyAPIStrokeDasharray.h"
#include "core/css/properties/CSSPropertyAPITabSize.h"
#include "core/css/properties/CSSPropertyAPITextDecorationColor.h"
#include "core/css/properties/CSSPropertyAPITextDecorationSkip.h"
#include "core/css/properties/CSSPropertyAPITextIndent.h"
#include "core/css/properties/CSSPropertyAPITextSizeAdjust.h"
#include "core/css/properties/CSSPropertyAPITextUnderlinePosition.h"
#include "core/css/properties/CSSPropertyAPITransformOrigin.h"
#include "core/css/properties/CSSPropertyAPITranslate.h"
#include "core/css/properties/CSSPropertyAPIVerticalAlign.h"
#include "core/css/properties/CSSPropertyAPIWebkitBoxFlexGroup.h"
#include "core/css/properties/CSSPropertyAPIWebkitHighlight.h"
#include "core/css/properties/CSSPropertyAPIWebkitLineClamp.h"
#include "core/css/properties/CSSPropertyAPIWebkitPadding.h"
#include "core/css/properties/CSSPropertyAPIWebkitTextEmphasisStyle.h"
#include "core/css/properties/CSSPropertyAPIWebkitTransformOriginZ.h"
#include "core/css/properties/CSSPropertyAPIWillChange.h"
#include "core/css/properties/CSSPropertyAPIZIndex.h"
#include "core/css/properties/CSSPropertyAPIZoom.h"

namespace blink {

static_assert(
    std::is_pod<CSSPropertyDescriptor>::value,
    "CSSPropertyDescriptor must be a POD to support using initializer lists.");

static CSSPropertyDescriptor cssPropertyDescriptors[] = {
    // An invalid CSSPropertyDescriptor. When functions are added to
    // CSSPropertyAPI, add a nullptr to represent their function pointers in the
    // struct initaliser.
    { nullptr, false },
    // When functions are added to CSSPropertyAPI, also add them to the struct
    // initaliser below.
    { CSSPropertyAPITextUnderlinePosition::parseSingleValue, true },
    { CSSPropertyAPIWebkitPadding::parseSingleValue, true },
    { CSSPropertyAPIWebkitHighlight::parseSingleValue, true },
    { CSSPropertyAPIFontSizeAdjust::parseSingleValue, true },
    { CSSPropertyAPIZIndex::parseSingleValue, true },
    { CSSPropertyAPIWillChange::parseSingleValue, true },
    { CSSPropertyAPIColumnGap::parseSingleValue, true },
    { CSSPropertyAPIClip::parseSingleValue, true },
    { CSSPropertyAPIPage::parseSingleValue, true },
    { CSSPropertyAPILetterAndWordSpacing::parseSingleValue, true },
    { CSSPropertyAPICursor::parseSingleValue, true },
    { CSSPropertyAPITranslate::parseSingleValue, true },
    { CSSPropertyAPITextDecorationSkip::parseSingleValue, true },
    { CSSPropertyAPIPaintOrder::parseSingleValue, true },
    { CSSPropertyAPIGridAutoFlow::parseSingleValue, true },
    { CSSPropertyAPIRotate::parseSingleValue, true },
    { CSSPropertyAPITextDecorationColor::parseSingleValue, true },
    { CSSPropertyAPITabSize::parseSingleValue, true },
    { CSSPropertyAPIFlexBasis::parseSingleValue, true },
    { CSSPropertyAPIScale::parseSingleValue, true },
    { CSSPropertyAPIScrollSnapCoordinate::parseSingleValue, true },
    { CSSPropertyAPIWebkitTransformOriginZ::parseSingleValue, true },
    { CSSPropertyAPIFontVariationSettings::parseSingleValue, true },
    { CSSPropertyAPIFontVariantCaps::parseSingleValue, true },
    { CSSPropertyAPIOutlineColor::parseSingleValue, true },
    { CSSPropertyAPIWebkitBoxFlexGroup::parseSingleValue, true },
    { CSSPropertyAPIBorderRadius::parseSingleValue, true },
    { CSSPropertyAPITextSizeAdjust::parseSingleValue, true },
    { CSSPropertyAPIFontVariantLigatures::parseSingleValue, true },
    { CSSPropertyAPIWebkitLineClamp::parseSingleValue, true },
    { CSSPropertyAPIContain::parseSingleValue, true },
    { CSSPropertyAPIStrokeDasharray::parseSingleValue, true },
    { CSSPropertyAPIShapeMargin::parseSingleValue, true },
    { CSSPropertyAPIOffsetPosition::parseSingleValue, true },
    { CSSPropertyAPIWebkitTextEmphasisStyle::parseSingleValue, true },
    { CSSPropertyAPITextIndent::parseSingleValue, true },
    { CSSPropertyAPIOutlineOffset::parseSingleValue, true },
    { CSSPropertyAPIVerticalAlign::parseSingleValue, true },
    { CSSPropertyAPICaretColor::parseSingleValue, true },
    { CSSPropertyAPIQuotes::parseSingleValue, true },
    { CSSPropertyAPISize::parseSingleValue, true },
    { CSSPropertyAPIZoom::parseSingleValue, true },
    { CSSPropertyAPITransformOrigin::parseSingleValue, true },
    { CSSPropertyAPIContent::parseSingleValue, true },
    { CSSPropertyAPIPaintStroke::parseSingleValue, true },
};

const CSSPropertyDescriptor& CSSPropertyDescriptor::get(CSSPropertyID id)
{
    // TODO(aazzam): We are currently using hard-coded indexes for
    // cssPropertyDescriptor since we have only implemented a few properties.
    // Later, generate this switch statement, or alternatively return
    // cssPropertyDescriptors[id], and generate the cssPropertyDescriptors array
    // to hold invalid descriptors for methods which haven't been implemented yet.
    switch (id) {
    case CSSPropertyTextUnderlinePosition:
        return cssPropertyDescriptors[1];
    case CSSPropertyWebkitPaddingStart:
    case CSSPropertyWebkitPaddingBefore:
    case CSSPropertyWebkitPaddingEnd:
    case CSSPropertyWebkitPaddingAfter:
        return cssPropertyDescriptors[2];
    case CSSPropertyWebkitHighlight:
        return cssPropertyDescriptors[3];
    case CSSPropertyFontSizeAdjust:
        return cssPropertyDescriptors[4];
    case CSSPropertyZIndex:
        return cssPropertyDescriptors[5];
    case CSSPropertyWillChange:
        return cssPropertyDescriptors[6];
    case CSSPropertyColumnGap:
        return cssPropertyDescriptors[7];
    case CSSPropertyClip:
        return cssPropertyDescriptors[8];
    case CSSPropertyPage:
        return cssPropertyDescriptors[9];
    case CSSPropertyWordSpacing:
    case CSSPropertyLetterSpacing:
        return cssPropertyDescriptors[10];
    case CSSPropertyCursor:
        return cssPropertyDescriptors[11];
    case CSSPropertyTranslate:
        return cssPropertyDescriptors[12];
    case CSSPropertyTextDecorationSkip:
        return cssPropertyDescriptors[13];
    case CSSPropertyPaintOrder:
        return cssPropertyDescriptors[14];
    case CSSPropertyGridAutoFlow:
        return cssPropertyDescriptors[15];
    case CSSPropertyRotate:
        return cssPropertyDescriptors[16];
    case CSSPropertyTextDecorationColor:
        return cssPropertyDescriptors[17];
    case CSSPropertyTabSize:
        return cssPropertyDescriptors[18];
    case CSSPropertyFlexBasis:
        return cssPropertyDescriptors[19];
    case CSSPropertyScale:
        return cssPropertyDescriptors[20];
    case CSSPropertyScrollSnapCoordinate:
        return cssPropertyDescriptors[21];
    case CSSPropertyWebkitTransformOriginZ:
        return cssPropertyDescriptors[22];
    case CSSPropertyFontVariationSettings:
        return cssPropertyDescriptors[23];
    case CSSPropertyFontVariantCaps:
        return cssPropertyDescriptors[24];
    case CSSPropertyOutlineColor:
        return cssPropertyDescriptors[25];
    case CSSPropertyWebkitBoxFlexGroup:
        return cssPropertyDescriptors[26];
    case CSSPropertyBorderBottomLeftRadius:
    case CSSPropertyBorderTopRightRadius:
    case CSSPropertyBorderBottomRightRadius:
    case CSSPropertyBorderTopLeftRadius:
        return cssPropertyDescriptors[27];
    case CSSPropertyTextSizeAdjust:
        return cssPropertyDescriptors[28];
    case CSSPropertyFontVariantLigatures:
        return cssPropertyDescriptors[29];
    case CSSPropertyWebkitLineClamp:
        return cssPropertyDescriptors[30];
    case CSSPropertyContain:
        return cssPropertyDescriptors[31];
    case CSSPropertyStrokeDasharray:
        return cssPropertyDescriptors[32];
    case CSSPropertyShapeMargin:
        return cssPropertyDescriptors[33];
    case CSSPropertyOffsetPosition:
        return cssPropertyDescriptors[34];
    case CSSPropertyWebkitTextEmphasisStyle:
        return cssPropertyDescriptors[35];
    case CSSPropertyTextIndent:
        return cssPropertyDescriptors[36];
    case CSSPropertyOutlineOffset:
        return cssPropertyDescriptors[37];
    case CSSPropertyVerticalAlign:
        return cssPropertyDescriptors[38];
    case CSSPropertyCaretColor:
        return cssPropertyDescriptors[39];
    case CSSPropertyQuotes:
        return cssPropertyDescriptors[40];
    case CSSPropertySize:
        return cssPropertyDescriptors[41];
    case CSSPropertyZoom:
        return cssPropertyDescriptors[42];
    case CSSPropertyTransformOrigin:
        return cssPropertyDescriptors[43];
    case CSSPropertyContent:
        return cssPropertyDescriptors[44];
    case CSSPropertyFill:
    case CSSPropertyStroke:
        return cssPropertyDescriptors[45];
    default:
        return cssPropertyDescriptors[0];
    }
}

} // namespace blink
