// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ComputedStyleBaseConstants_h
#define ComputedStyleBaseConstants_h

namespace blink {

// TODO(sashab): Move these enums to their own namespace, or add a CSS prefix,
// for consistency and to prevent name conflicts.

enum class ETextAlign : unsigned {
    kLeft,
    kRight,
    kCenter,
    kJustify,
    kWebkitLeft,
    kWebkitRight,
    kWebkitCenter,
    kStart,
    kEnd,
};

enum class EVisibility : unsigned {
    kVisible,
    kHidden,
    kCollapse,
};

enum class EBoxDirection : unsigned {
    kNormal,
    kReverse,
};

enum class EPointerEvents : unsigned {
    kNone,
    kAuto,
    kStroke,
    kFill,
    kPainted,
    kVisible,
    kVisibleStroke,
    kVisibleFill,
    kVisiblePainted,
    kBoundingBox,
    kAll,
};

enum class EOrder : unsigned {
    kLogical,
    kVisual,
};

enum class EFloat : unsigned {
    kNone,
    kLeft,
    kRight,
};

enum class ECaptionSide : unsigned {
    kTop,
    kBottom,
    kLeft,
    kRight,
};

enum class EWhiteSpace : unsigned {
    kNormal,
    kPre,
    kPreWrap,
    kPreLine,
    kNowrap,
    kWebkitNowrap,
};

enum class ETextTransform : unsigned {
    kCapitalize,
    kUppercase,
    kLowercase,
    kNone,
};

enum class EEmptyCells : unsigned {
    kShow,
    kHide,
};

enum class EBorderCollapse : unsigned {
    kSeparate,
    kCollapse,
};

enum class EListStylePosition : unsigned {
    kOutside,
    kInside,
};

enum class EListStyleType : unsigned {
    kDisc,
    kCircle,
    kSquare,
    kDecimal,
    kDecimalLeadingZero,
    kArabicIndic,
    kBengali,
    kCambodian,
    kKhmer,
    kDevanagari,
    kGujarati,
    kGurmukhi,
    kKannada,
    kLao,
    kMalayalam,
    kMongolian,
    kMyanmar,
    kOriya,
    kPersian,
    kUrdu,
    kTelugu,
    kTibetan,
    kThai,
    kLowerRoman,
    kUpperRoman,
    kLowerGreek,
    kLowerAlpha,
    kLowerLatin,
    kUpperAlpha,
    kUpperLatin,
    kCjkEarthlyBranch,
    kCjkHeavenlyStem,
    kEthiopicHalehame,
    kEthiopicHalehameAm,
    kEthiopicHalehameTiEr,
    kEthiopicHalehameTiEt,
    kHangul,
    kHangulConsonant,
    kKoreanHangulFormal,
    kKoreanHanjaFormal,
    kKoreanHanjaInformal,
    kHebrew,
    kArmenian,
    kLowerArmenian,
    kUpperArmenian,
    kGeorgian,
    kCjkIdeographic,
    kSimpChineseFormal,
    kSimpChineseInformal,
    kTradChineseFormal,
    kTradChineseInformal,
    kHiragana,
    kKatakana,
    kHiraganaIroha,
    kKatakanaIroha,
    kNone,
};

enum class EPrintColorAdjust : unsigned {
    kEconomy,
    kExact,
};

} // namespace blink

#endif // ComputedStyleBaseConstants_h
