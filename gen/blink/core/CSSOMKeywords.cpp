// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/css/cssom/CSSOMKeywords.h"

#include "core/css/CSSPropertyIDTemplates.h"
#include "core/css/cssom/CSSKeywordValue.h"
#include "wtf/HashMap.h"

namespace blink {

namespace {

    using KeywordTable = HashMap<CSSPropertyID, Vector<CSSValueID>>;

    KeywordTable createKeywordTable()
    {
        KeywordTable table;

        {
            Vector<CSSValueID> heightKeywords;
            heightKeywords.push_back(CSSValueAuto);
            table.set(CSSPropertyHeight, heightKeywords);
        }
        {
            Vector<CSSValueID> borderImageSourceKeywords;
            borderImageSourceKeywords.push_back(CSSValueNone);
            table.set(CSSPropertyBorderImageSource, borderImageSourceKeywords);
        }
        {
            Vector<CSSValueID> webkitBoxDirectionKeywords;
            webkitBoxDirectionKeywords.push_back(CSSValueNormal);
            webkitBoxDirectionKeywords.push_back(CSSValueReverse);
            table.set(CSSPropertyWebkitBoxDirection, webkitBoxDirectionKeywords);
        }
        {
            Vector<CSSValueID> captionSideKeywords;
            captionSideKeywords.push_back(CSSValueTop);
            captionSideKeywords.push_back(CSSValueBottom);
            captionSideKeywords.push_back(CSSValueLeft);
            captionSideKeywords.push_back(CSSValueRight);
            table.set(CSSPropertyCaptionSide, captionSideKeywords);
        }
        {
            Vector<CSSValueID> webkitPrintColorAdjustKeywords;
            webkitPrintColorAdjustKeywords.push_back(CSSValueEconomy);
            webkitPrintColorAdjustKeywords.push_back(CSSValueExact);
            table.set(CSSPropertyWebkitPrintColorAdjust, webkitPrintColorAdjustKeywords);
        }
        {
            Vector<CSSValueID> transformKeywords;
            transformKeywords.push_back(CSSValueNone);
            table.set(CSSPropertyTransform, transformKeywords);
        }
        {
            Vector<CSSValueID> writingModeKeywords;
            writingModeKeywords.push_back(CSSValueHorizontalTb);
            writingModeKeywords.push_back(CSSValueVerticalRl);
            writingModeKeywords.push_back(CSSValueVerticalLr);
            table.set(CSSPropertyWritingMode, writingModeKeywords);
        }
        {
            Vector<CSSValueID> backgroundImageKeywords;
            backgroundImageKeywords.push_back(CSSValueAuto);
            table.set(CSSPropertyBackgroundImage, backgroundImageKeywords);
        }
        {
            Vector<CSSValueID> borderTopWidthKeywords;
            borderTopWidthKeywords.push_back(CSSValueThin);
            borderTopWidthKeywords.push_back(CSSValueMedium);
            borderTopWidthKeywords.push_back(CSSValueThick);
            table.set(CSSPropertyBorderTopWidth, borderTopWidthKeywords);
        }
        {
            Vector<CSSValueID> bottomKeywords;
            bottomKeywords.push_back(CSSValueAuto);
            table.set(CSSPropertyBottom, bottomKeywords);
        }
        {
            Vector<CSSValueID> borderCollapseKeywords;
            borderCollapseKeywords.push_back(CSSValueSeparate);
            borderCollapseKeywords.push_back(CSSValueCollapse);
            table.set(CSSPropertyBorderCollapse, borderCollapseKeywords);
        }
        {
            Vector<CSSValueID> topKeywords;
            topKeywords.push_back(CSSValueAuto);
            table.set(CSSPropertyTop, topKeywords);
        }
        {
            Vector<CSSValueID> unicodeBidiKeywords;
            unicodeBidiKeywords.push_back(CSSValueNormal);
            unicodeBidiKeywords.push_back(CSSValueEmbed);
            unicodeBidiKeywords.push_back(CSSValueBidiOverride);
            unicodeBidiKeywords.push_back(CSSValueIsolate);
            unicodeBidiKeywords.push_back(CSSValuePlaintext);
            unicodeBidiKeywords.push_back(CSSValueIsolateOverride);
            table.set(CSSPropertyUnicodeBidi, unicodeBidiKeywords);
        }
        {
            Vector<CSSValueID> animationIterationCountKeywords;
            animationIterationCountKeywords.push_back(CSSValueInfinite);
            table.set(CSSPropertyAnimationIterationCount, animationIterationCountKeywords);
        }
        {
            Vector<CSSValueID> floatKeywords;
            floatKeywords.push_back(CSSValueNone);
            floatKeywords.push_back(CSSValueLeft);
            floatKeywords.push_back(CSSValueRight);
            table.set(CSSPropertyFloat, floatKeywords);
        }
        {
            Vector<CSSValueID> webkitRtlOrderingKeywords;
            webkitRtlOrderingKeywords.push_back(CSSValueLogical);
            webkitRtlOrderingKeywords.push_back(CSSValueVisual);
            table.set(CSSPropertyWebkitRtlOrdering, webkitRtlOrderingKeywords);
        }
        {
            Vector<CSSValueID> whiteSpaceKeywords;
            whiteSpaceKeywords.push_back(CSSValueNormal);
            whiteSpaceKeywords.push_back(CSSValuePre);
            whiteSpaceKeywords.push_back(CSSValuePreWrap);
            whiteSpaceKeywords.push_back(CSSValuePreLine);
            whiteSpaceKeywords.push_back(CSSValueNowrap);
            whiteSpaceKeywords.push_back(CSSValueWebkitNowrap);
            table.set(CSSPropertyWhiteSpace, whiteSpaceKeywords);
        }
        {
            Vector<CSSValueID> leftKeywords;
            leftKeywords.push_back(CSSValueAuto);
            table.set(CSSPropertyLeft, leftKeywords);
        }
        {
            Vector<CSSValueID> widthKeywords;
            widthKeywords.push_back(CSSValueAuto);
            table.set(CSSPropertyWidth, widthKeywords);
        }
        {
            Vector<CSSValueID> listStylePositionKeywords;
            listStylePositionKeywords.push_back(CSSValueOutside);
            listStylePositionKeywords.push_back(CSSValueInside);
            table.set(CSSPropertyListStylePosition, listStylePositionKeywords);
        }
        {
            Vector<CSSValueID> pointerEventsKeywords;
            pointerEventsKeywords.push_back(CSSValueNone);
            pointerEventsKeywords.push_back(CSSValueAuto);
            pointerEventsKeywords.push_back(CSSValueStroke);
            pointerEventsKeywords.push_back(CSSValueFill);
            pointerEventsKeywords.push_back(CSSValuePainted);
            pointerEventsKeywords.push_back(CSSValueVisible);
            pointerEventsKeywords.push_back(CSSValueVisibleStroke);
            pointerEventsKeywords.push_back(CSSValueVisibleFill);
            pointerEventsKeywords.push_back(CSSValueVisiblePainted);
            pointerEventsKeywords.push_back(CSSValueBoundingBox);
            pointerEventsKeywords.push_back(CSSValueAll);
            table.set(CSSPropertyPointerEvents, pointerEventsKeywords);
        }
        {
            Vector<CSSValueID> animationDirectionKeywords;
            animationDirectionKeywords.push_back(CSSValueNormal);
            animationDirectionKeywords.push_back(CSSValueReverse);
            animationDirectionKeywords.push_back(CSSValueAlternate);
            animationDirectionKeywords.push_back(CSSValueAlternateReverse);
            table.set(CSSPropertyAnimationDirection, animationDirectionKeywords);
        }
        {
            Vector<CSSValueID> textTransformKeywords;
            textTransformKeywords.push_back(CSSValueCapitalize);
            textTransformKeywords.push_back(CSSValueUppercase);
            textTransformKeywords.push_back(CSSValueLowercase);
            textTransformKeywords.push_back(CSSValueNone);
            table.set(CSSPropertyTextTransform, textTransformKeywords);
        }
        {
            Vector<CSSValueID> rightKeywords;
            rightKeywords.push_back(CSSValueAuto);
            table.set(CSSPropertyRight, rightKeywords);
        }
        {
            Vector<CSSValueID> directionKeywords;
            directionKeywords.push_back(CSSValueLtr);
            directionKeywords.push_back(CSSValueRtl);
            table.set(CSSPropertyDirection, directionKeywords);
        }
        {
            Vector<CSSValueID> emptyCellsKeywords;
            emptyCellsKeywords.push_back(CSSValueShow);
            emptyCellsKeywords.push_back(CSSValueHide);
            table.set(CSSPropertyEmptyCells, emptyCellsKeywords);
        }
        {
            Vector<CSSValueID> listStyleTypeKeywords;
            listStyleTypeKeywords.push_back(CSSValueDisc);
            listStyleTypeKeywords.push_back(CSSValueCircle);
            listStyleTypeKeywords.push_back(CSSValueSquare);
            listStyleTypeKeywords.push_back(CSSValueDecimal);
            listStyleTypeKeywords.push_back(CSSValueDecimalLeadingZero);
            listStyleTypeKeywords.push_back(CSSValueArabicIndic);
            listStyleTypeKeywords.push_back(CSSValueBengali);
            listStyleTypeKeywords.push_back(CSSValueCambodian);
            listStyleTypeKeywords.push_back(CSSValueKhmer);
            listStyleTypeKeywords.push_back(CSSValueDevanagari);
            listStyleTypeKeywords.push_back(CSSValueGujarati);
            listStyleTypeKeywords.push_back(CSSValueGurmukhi);
            listStyleTypeKeywords.push_back(CSSValueKannada);
            listStyleTypeKeywords.push_back(CSSValueLao);
            listStyleTypeKeywords.push_back(CSSValueMalayalam);
            listStyleTypeKeywords.push_back(CSSValueMongolian);
            listStyleTypeKeywords.push_back(CSSValueMyanmar);
            listStyleTypeKeywords.push_back(CSSValueOriya);
            listStyleTypeKeywords.push_back(CSSValuePersian);
            listStyleTypeKeywords.push_back(CSSValueUrdu);
            listStyleTypeKeywords.push_back(CSSValueTelugu);
            listStyleTypeKeywords.push_back(CSSValueTibetan);
            listStyleTypeKeywords.push_back(CSSValueThai);
            listStyleTypeKeywords.push_back(CSSValueLowerRoman);
            listStyleTypeKeywords.push_back(CSSValueUpperRoman);
            listStyleTypeKeywords.push_back(CSSValueLowerGreek);
            listStyleTypeKeywords.push_back(CSSValueLowerAlpha);
            listStyleTypeKeywords.push_back(CSSValueLowerLatin);
            listStyleTypeKeywords.push_back(CSSValueUpperAlpha);
            listStyleTypeKeywords.push_back(CSSValueUpperLatin);
            listStyleTypeKeywords.push_back(CSSValueCjkEarthlyBranch);
            listStyleTypeKeywords.push_back(CSSValueCjkHeavenlyStem);
            listStyleTypeKeywords.push_back(CSSValueEthiopicHalehame);
            listStyleTypeKeywords.push_back(CSSValueEthiopicHalehameAm);
            listStyleTypeKeywords.push_back(CSSValueEthiopicHalehameTiEr);
            listStyleTypeKeywords.push_back(CSSValueEthiopicHalehameTiEt);
            listStyleTypeKeywords.push_back(CSSValueHangul);
            listStyleTypeKeywords.push_back(CSSValueHangulConsonant);
            listStyleTypeKeywords.push_back(CSSValueKoreanHangulFormal);
            listStyleTypeKeywords.push_back(CSSValueKoreanHanjaFormal);
            listStyleTypeKeywords.push_back(CSSValueKoreanHanjaInformal);
            listStyleTypeKeywords.push_back(CSSValueHebrew);
            listStyleTypeKeywords.push_back(CSSValueArmenian);
            listStyleTypeKeywords.push_back(CSSValueLowerArmenian);
            listStyleTypeKeywords.push_back(CSSValueUpperArmenian);
            listStyleTypeKeywords.push_back(CSSValueGeorgian);
            listStyleTypeKeywords.push_back(CSSValueCjkIdeographic);
            listStyleTypeKeywords.push_back(CSSValueSimpChineseFormal);
            listStyleTypeKeywords.push_back(CSSValueSimpChineseInformal);
            listStyleTypeKeywords.push_back(CSSValueTradChineseFormal);
            listStyleTypeKeywords.push_back(CSSValueTradChineseInformal);
            listStyleTypeKeywords.push_back(CSSValueHiragana);
            listStyleTypeKeywords.push_back(CSSValueKatakana);
            listStyleTypeKeywords.push_back(CSSValueHiraganaIroha);
            listStyleTypeKeywords.push_back(CSSValueKatakanaIroha);
            listStyleTypeKeywords.push_back(CSSValueNone);
            table.set(CSSPropertyListStyleType, listStyleTypeKeywords);
        }
        {
            Vector<CSSValueID> textAlignKeywords;
            textAlignKeywords.push_back(CSSValueLeft);
            textAlignKeywords.push_back(CSSValueRight);
            textAlignKeywords.push_back(CSSValueCenter);
            textAlignKeywords.push_back(CSSValueJustify);
            textAlignKeywords.push_back(CSSValueWebkitLeft);
            textAlignKeywords.push_back(CSSValueWebkitRight);
            textAlignKeywords.push_back(CSSValueWebkitCenter);
            textAlignKeywords.push_back(CSSValueStart);
            textAlignKeywords.push_back(CSSValueEnd);
            table.set(CSSPropertyTextAlign, textAlignKeywords);
        }
        {
            Vector<CSSValueID> visibilityKeywords;
            visibilityKeywords.push_back(CSSValueVisible);
            visibilityKeywords.push_back(CSSValueHidden);
            visibilityKeywords.push_back(CSSValueCollapse);
            table.set(CSSPropertyVisibility, visibilityKeywords);
        }
        return table;
    }

    KeywordTable& keywordTable()
    {
        DEFINE_STATIC_LOCAL(KeywordTable, keywordTable, (createKeywordTable()));
        return keywordTable;
    }

} // namespace

bool CSSOMKeywords::validKeywordForProperty(CSSPropertyID id,
    const CSSKeywordValue& keyword)
{
    CSSValueID valueID = keyword.keywordValueID();
    if (valueID == CSSValueInvalid) {
        return false;
    }

    if (valueID == CSSValueInherit || valueID == CSSValueInitial || valueID == CSSValueUnset) {
        // These are css-wide keywords that are valid for all properties.
        return true;
    }

    const KeywordTable::iterator tableIterator = keywordTable().find(id);
    if (tableIterator == keywordTable().end()) {
        return false;
    }

    return tableIterator->value.contains(valueID);
}

} // namespace blink
