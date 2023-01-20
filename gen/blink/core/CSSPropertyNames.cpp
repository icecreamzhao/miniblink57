/* C++ code produced by gperf version 3.0.4 */
/* Command-line: gperf --key-positions='*' -P -n -m 50 -D  */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35)      \
    && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40)    \
    && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44)     \
    && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48)     \
    && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52)     \
    && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56)     \
    && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60)     \
    && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65)     \
    && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69)     \
    && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73)     \
    && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77)     \
    && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81)     \
    && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85)     \
    && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89)     \
    && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93)    \
    && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98)     \
    && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102)  \
    && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
    && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
    && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
    && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
    && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
    && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "CSSPropertyNames.h"
#include "core/css/HashTools.h"
#include <string.h>

#include "wtf/ASCIICType.h"
#include "wtf/text/AtomicString.h"
#include "wtf/text/WTFString.h"

#ifdef _MSC_VER
// Disable the warnings from casting a 64-bit pointer to 32-bit long
// warning C4302: 'type cast': truncation from 'char (*)[28]' to 'long'
// warning C4311: 'type cast': pointer truncation from 'char (*)[18]' to 'long'
#pragma warning(disable : 4302 4311)
#endif

namespace blink {
static const char propertyNameStringsPool[] = {
    "animation-delay\0"
    "animation-direction\0"
    "animation-duration\0"
    "animation-fill-mode\0"
    "animation-iteration-count\0"
    "animation-name\0"
    "animation-play-state\0"
    "animation-timing-function\0"
    "transition-delay\0"
    "transition-duration\0"
    "transition-property\0"
    "transition-timing-function\0"
    "color\0"
    "direction\0"
    "font-family\0"
    "font-feature-settings\0"
    "font-kerning\0"
    "font-size\0"
    "font-size-adjust\0"
    "font-stretch\0"
    "font-style\0"
    "font-variant-caps\0"
    "font-variant-ligatures\0"
    "font-variant-numeric\0"
    "font-variation-settings\0"
    "font-weight\0"
    "text-orientation\0"
    "text-rendering\0"
    "-webkit-font-smoothing\0"
    "-webkit-locale\0"
    "-webkit-text-orientation\0"
    "-webkit-writing-mode\0"
    "writing-mode\0"
    "zoom\0"
    "align-content\0"
    "align-items\0"
    "align-self\0"
    "alignment-baseline\0"
    "all\0"
    "animation\0"
    "backdrop-filter\0"
    "backface-visibility\0"
    "background\0"
    "background-attachment\0"
    "background-blend-mode\0"
    "background-clip\0"
    "background-color\0"
    "background-image\0"
    "background-origin\0"
    "background-position\0"
    "background-position-x\0"
    "background-position-y\0"
    "background-repeat\0"
    "background-repeat-x\0"
    "background-repeat-y\0"
    "background-size\0"
    "baseline-shift\0"
    "block-size\0"
    "border\0"
    "border-bottom\0"
    "border-bottom-color\0"
    "border-bottom-left-radius\0"
    "border-bottom-right-radius\0"
    "border-bottom-style\0"
    "border-bottom-width\0"
    "border-collapse\0"
    "border-color\0"
    "border-image\0"
    "border-image-outset\0"
    "border-image-repeat\0"
    "border-image-slice\0"
    "border-image-source\0"
    "border-image-width\0"
    "border-left\0"
    "border-left-color\0"
    "border-left-style\0"
    "border-left-width\0"
    "border-radius\0"
    "border-right\0"
    "border-right-color\0"
    "border-right-style\0"
    "border-right-width\0"
    "border-spacing\0"
    "border-style\0"
    "border-top\0"
    "border-top-color\0"
    "border-top-left-radius\0"
    "border-top-right-radius\0"
    "border-top-style\0"
    "border-top-width\0"
    "border-width\0"
    "bottom\0"
    "box-shadow\0"
    "box-sizing\0"
    "break-after\0"
    "break-before\0"
    "break-inside\0"
    "buffered-rendering\0"
    "caption-side\0"
    "caret-color\0"
    "clear\0"
    "clip\0"
    "clip-path\0"
    "clip-rule\0"
    "color-interpolation\0"
    "color-interpolation-filters\0"
    "color-rendering\0"
    "column-count\0"
    "column-fill\0"
    "column-gap\0"
    "column-rule\0"
    "column-rule-color\0"
    "column-rule-style\0"
    "column-rule-width\0"
    "column-span\0"
    "column-width\0"
    "columns\0"
    "contain\0"
    "content\0"
    "counter-increment\0"
    "counter-reset\0"
    "cursor\0"
    "cx\0"
    "cy\0"
    "d\0"
    "display\0"
    "dominant-baseline\0"
    "empty-cells\0"
    "fill\0"
    "fill-opacity\0"
    "fill-rule\0"
    "filter\0"
    "flex\0"
    "flex-basis\0"
    "flex-direction\0"
    "flex-flow\0"
    "flex-grow\0"
    "flex-shrink\0"
    "flex-wrap\0"
    "float\0"
    "flood-color\0"
    "flood-opacity\0"
    "font\0"
    "font-display\0"
    "font-variant\0"
    "grid\0"
    "grid-area\0"
    "grid-auto-columns\0"
    "grid-auto-flow\0"
    "grid-auto-rows\0"
    "grid-column\0"
    "grid-column-end\0"
    "grid-column-gap\0"
    "grid-column-start\0"
    "grid-gap\0"
    "grid-row\0"
    "grid-row-end\0"
    "grid-row-gap\0"
    "grid-row-start\0"
    "grid-template\0"
    "grid-template-areas\0"
    "grid-template-columns\0"
    "grid-template-rows\0"
    "height\0"
    "hyphens\0"
    "image-orientation\0"
    "image-rendering\0"
    "inline-size\0"
    "isolation\0"
    "justify-content\0"
    "justify-items\0"
    "justify-self\0"
    "left\0"
    "letter-spacing\0"
    "lighting-color\0"
    "line-height\0"
    "list-style\0"
    "list-style-image\0"
    "list-style-position\0"
    "list-style-type\0"
    "margin\0"
    "margin-bottom\0"
    "margin-left\0"
    "margin-right\0"
    "margin-top\0"
    "marker\0"
    "marker-end\0"
    "marker-mid\0"
    "marker-start\0"
    "mask\0"
    "mask-source-type\0"
    "mask-type\0"
    "max-block-size\0"
    "max-height\0"
    "max-inline-size\0"
    "max-width\0"
    "max-zoom\0"
    "min-block-size\0"
    "min-height\0"
    "min-inline-size\0"
    "min-width\0"
    "min-zoom\0"
    "mix-blend-mode\0"
    "motion\0"
    "object-fit\0"
    "object-position\0"
    "offset\0"
    "offset-anchor\0"
    "offset-distance\0"
    "offset-path\0"
    "offset-position\0"
    "offset-rotate\0"
    "offset-rotation\0"
    "opacity\0"
    "order\0"
    "orientation\0"
    "orphans\0"
    "outline\0"
    "outline-color\0"
    "outline-offset\0"
    "outline-style\0"
    "outline-width\0"
    "overflow\0"
    "overflow-anchor\0"
    "overflow-wrap\0"
    "overflow-x\0"
    "overflow-y\0"
    "padding\0"
    "padding-bottom\0"
    "padding-left\0"
    "padding-right\0"
    "padding-top\0"
    "page\0"
    "page-break-after\0"
    "page-break-before\0"
    "page-break-inside\0"
    "paint-order\0"
    "perspective\0"
    "perspective-origin\0"
    "pointer-events\0"
    "position\0"
    "quotes\0"
    "r\0"
    "resize\0"
    "right\0"
    "rotate\0"
    "rx\0"
    "ry\0"
    "scale\0"
    "scroll-behavior\0"
    "scroll-snap-coordinate\0"
    "scroll-snap-destination\0"
    "scroll-snap-points-x\0"
    "scroll-snap-points-y\0"
    "scroll-snap-type\0"
    "shape-image-threshold\0"
    "shape-margin\0"
    "shape-outside\0"
    "shape-rendering\0"
    "size\0"
    "snap-height\0"
    "speak\0"
    "src\0"
    "stop-color\0"
    "stop-opacity\0"
    "stroke\0"
    "stroke-dasharray\0"
    "stroke-dashoffset\0"
    "stroke-linecap\0"
    "stroke-linejoin\0"
    "stroke-miterlimit\0"
    "stroke-opacity\0"
    "stroke-width\0"
    "tab-size\0"
    "table-layout\0"
    "text-align\0"
    "text-align-last\0"
    "text-anchor\0"
    "text-combine-upright\0"
    "text-decoration\0"
    "text-decoration-color\0"
    "text-decoration-line\0"
    "text-decoration-skip\0"
    "text-decoration-style\0"
    "text-indent\0"
    "text-justify\0"
    "text-overflow\0"
    "text-shadow\0"
    "text-size-adjust\0"
    "text-transform\0"
    "text-underline-position\0"
    "top\0"
    "touch-action\0"
    "transform\0"
    "transform-origin\0"
    "transform-style\0"
    "transition\0"
    "translate\0"
    "unicode-bidi\0"
    "unicode-range\0"
    "user-select\0"
    "user-zoom\0"
    "vector-effect\0"
    "vertical-align\0"
    "visibility\0"
    "-webkit-app-region\0"
    "-webkit-appearance\0"
    "-webkit-background-clip\0"
    "-webkit-background-origin\0"
    "-webkit-border-after\0"
    "-webkit-border-after-color\0"
    "-webkit-border-after-style\0"
    "-webkit-border-after-width\0"
    "-webkit-border-before\0"
    "-webkit-border-before-color\0"
    "-webkit-border-before-style\0"
    "-webkit-border-before-width\0"
    "-webkit-border-end\0"
    "-webkit-border-end-color\0"
    "-webkit-border-end-style\0"
    "-webkit-border-end-width\0"
    "-webkit-border-horizontal-spacing\0"
    "-webkit-border-image\0"
    "-webkit-border-start\0"
    "-webkit-border-start-color\0"
    "-webkit-border-start-style\0"
    "-webkit-border-start-width\0"
    "-webkit-border-vertical-spacing\0"
    "-webkit-box-align\0"
    "-webkit-box-decoration-break\0"
    "-webkit-box-direction\0"
    "-webkit-box-flex\0"
    "-webkit-box-flex-group\0"
    "-webkit-box-lines\0"
    "-webkit-box-ordinal-group\0"
    "-webkit-box-orient\0"
    "-webkit-box-pack\0"
    "-webkit-box-reflect\0"
    "-webkit-column-break-after\0"
    "-webkit-column-break-before\0"
    "-webkit-column-break-inside\0"
    "-webkit-font-size-delta\0"
    "-webkit-highlight\0"
    "-webkit-hyphenate-character\0"
    "-webkit-line-break\0"
    "-webkit-line-clamp\0"
    "-webkit-logical-height\0"
    "-webkit-logical-width\0"
    "-webkit-margin-after\0"
    "-webkit-margin-after-collapse\0"
    "-webkit-margin-before\0"
    "-webkit-margin-before-collapse\0"
    "-webkit-margin-bottom-collapse\0"
    "-webkit-margin-collapse\0"
    "-webkit-margin-end\0"
    "-webkit-margin-start\0"
    "-webkit-margin-top-collapse\0"
    "-webkit-mask\0"
    "-webkit-mask-box-image\0"
    "-webkit-mask-box-image-outset\0"
    "-webkit-mask-box-image-repeat\0"
    "-webkit-mask-box-image-slice\0"
    "-webkit-mask-box-image-source\0"
    "-webkit-mask-box-image-width\0"
    "-webkit-mask-clip\0"
    "-webkit-mask-composite\0"
    "-webkit-mask-image\0"
    "-webkit-mask-origin\0"
    "-webkit-mask-position\0"
    "-webkit-mask-position-x\0"
    "-webkit-mask-position-y\0"
    "-webkit-mask-repeat\0"
    "-webkit-mask-repeat-x\0"
    "-webkit-mask-repeat-y\0"
    "-webkit-mask-size\0"
    "-webkit-max-logical-height\0"
    "-webkit-max-logical-width\0"
    "-webkit-min-logical-height\0"
    "-webkit-min-logical-width\0"
    "-webkit-padding-after\0"
    "-webkit-padding-before\0"
    "-webkit-padding-end\0"
    "-webkit-padding-start\0"
    "-webkit-perspective-origin-x\0"
    "-webkit-perspective-origin-y\0"
    "-webkit-print-color-adjust\0"
    "-webkit-rtl-ordering\0"
    "-webkit-ruby-position\0"
    "-webkit-tap-highlight-color\0"
    "-webkit-text-combine\0"
    "-webkit-text-decorations-in-effect\0"
    "-webkit-text-emphasis\0"
    "-webkit-text-emphasis-color\0"
    "-webkit-text-emphasis-position\0"
    "-webkit-text-emphasis-style\0"
    "-webkit-text-fill-color\0"
    "-webkit-text-security\0"
    "-webkit-text-stroke\0"
    "-webkit-text-stroke-color\0"
    "-webkit-text-stroke-width\0"
    "-webkit-transform-origin-x\0"
    "-webkit-transform-origin-y\0"
    "-webkit-transform-origin-z\0"
    "-webkit-user-drag\0"
    "-webkit-user-modify\0"
    "white-space\0"
    "widows\0"
    "width\0"
    "will-change\0"
    "word-break\0"
    "word-spacing\0"
    "word-wrap\0"
    "x\0"
    "y\0"
    "z-index\0"
    "-webkit-animation-delay\0"
    "-webkit-animation-direction\0"
    "-webkit-animation-duration\0"
    "-webkit-animation-fill-mode\0"
    "-webkit-animation-iteration-count\0"
    "-webkit-animation-name\0"
    "-webkit-animation-play-state\0"
    "-webkit-animation-timing-function\0"
    "-webkit-transition-delay\0"
    "-webkit-transition-duration\0"
    "-webkit-transition-property\0"
    "-webkit-transition-timing-function\0"
    "-webkit-font-feature-settings\0"
    "-epub-text-orientation\0"
    "-epub-writing-mode\0"
    "-webkit-align-content\0"
    "-webkit-align-items\0"
    "-webkit-align-self\0"
    "-webkit-animation\0"
    "-webkit-backface-visibility\0"
    "-webkit-background-size\0"
    "-webkit-border-bottom-left-radius\0"
    "-webkit-border-bottom-right-radius\0"
    "-webkit-border-radius\0"
    "-webkit-border-top-left-radius\0"
    "-webkit-border-top-right-radius\0"
    "-webkit-box-shadow\0"
    "-webkit-box-sizing\0"
    "-epub-caption-side\0"
    "-webkit-clip-path\0"
    "-webkit-column-count\0"
    "-webkit-column-gap\0"
    "-webkit-column-rule\0"
    "-webkit-column-rule-color\0"
    "-webkit-column-rule-style\0"
    "-webkit-column-rule-width\0"
    "-webkit-column-span\0"
    "-webkit-column-width\0"
    "-webkit-columns\0"
    "-webkit-filter\0"
    "-webkit-flex\0"
    "-webkit-flex-basis\0"
    "-webkit-flex-direction\0"
    "-webkit-flex-flow\0"
    "-webkit-flex-grow\0"
    "-webkit-flex-shrink\0"
    "-webkit-flex-wrap\0"
    "-webkit-justify-content\0"
    "motion-offset\0"
    "motion-path\0"
    "motion-rotation\0"
    "-webkit-opacity\0"
    "-webkit-order\0"
    "-webkit-perspective\0"
    "-webkit-perspective-origin\0"
    "-webkit-shape-image-threshold\0"
    "-webkit-shape-margin\0"
    "-webkit-shape-outside\0"
    "-webkit-text-size-adjust\0"
    "-epub-text-transform\0"
    "-webkit-transform\0"
    "-webkit-transform-origin\0"
    "-webkit-transform-style\0"
    "-webkit-transition\0"
    "-webkit-user-select\0"
    "-epub-text-combine\0"
    "-epub-text-emphasis\0"
    "-epub-text-emphasis-color\0"
    "-epub-text-emphasis-style\0"
    "-epub-word-break\0"
};

static const unsigned short propertyNameStringsOffsets[] = {
    0,
    16,
    36,
    55,
    75,
    101,
    116,
    137,
    163,
    180,
    200,
    220,
    247,
    253,
    263,
    275,
    297,
    310,
    320,
    337,
    350,
    361,
    379,
    402,
    423,
    447,
    459,
    476,
    491,
    514,
    529,
    554,
    575,
    588,
    593,
    607,
    619,
    630,
    649,
    653,
    663,
    679,
    699,
    710,
    732,
    754,
    770,
    787,
    804,
    822,
    842,
    864,
    886,
    904,
    924,
    944,
    960,
    975,
    986,
    993,
    1007,
    1027,
    1053,
    1080,
    1100,
    1120,
    1136,
    1149,
    1162,
    1182,
    1202,
    1221,
    1241,
    1260,
    1272,
    1290,
    1308,
    1326,
    1340,
    1353,
    1372,
    1391,
    1410,
    1425,
    1438,
    1449,
    1466,
    1489,
    1513,
    1530,
    1547,
    1560,
    1567,
    1578,
    1589,
    1601,
    1614,
    1627,
    1646,
    1659,
    1671,
    1677,
    1682,
    1692,
    1702,
    1722,
    1750,
    1766,
    1779,
    1791,
    1802,
    1814,
    1832,
    1850,
    1868,
    1880,
    1893,
    1901,
    1909,
    1917,
    1935,
    1949,
    1956,
    1959,
    1962,
    1964,
    1972,
    1990,
    2002,
    2007,
    2020,
    2030,
    2037,
    2042,
    2053,
    2068,
    2078,
    2088,
    2100,
    2110,
    2116,
    2128,
    2142,
    2147,
    2160,
    2173,
    2178,
    2188,
    2206,
    2221,
    2236,
    2248,
    2264,
    2280,
    2298,
    2307,
    2316,
    2329,
    2342,
    2357,
    2371,
    2391,
    2413,
    2432,
    2439,
    2447,
    2465,
    2481,
    2493,
    2503,
    2519,
    2533,
    2546,
    2551,
    2566,
    2581,
    2593,
    2604,
    2621,
    2641,
    2657,
    2664,
    2678,
    2690,
    2703,
    2714,
    2721,
    2732,
    2743,
    2756,
    2761,
    2778,
    2788,
    2803,
    2814,
    2830,
    2840,
    2849,
    2864,
    2875,
    2891,
    2901,
    2910,
    2925,
    2932,
    2943,
    2959,
    2966,
    2980,
    2996,
    3008,
    3024,
    3038,
    3054,
    3062,
    3068,
    3080,
    3088,
    3096,
    3110,
    3125,
    3139,
    3153,
    3162,
    3178,
    3192,
    3203,
    3214,
    3222,
    3237,
    3250,
    3264,
    3276,
    3281,
    3298,
    3316,
    3334,
    3346,
    3358,
    3377,
    3392,
    3401,
    3408,
    3410,
    3417,
    3423,
    3430,
    3433,
    3436,
    3442,
    3458,
    3481,
    3505,
    3526,
    3547,
    3564,
    3586,
    3599,
    3613,
    3629,
    3634,
    3646,
    3652,
    3656,
    3667,
    3680,
    3687,
    3704,
    3722,
    3737,
    3753,
    3771,
    3786,
    3799,
    3808,
    3821,
    3832,
    3848,
    3860,
    3881,
    3897,
    3919,
    3940,
    3961,
    3983,
    3995,
    4008,
    4022,
    4034,
    4051,
    4066,
    4090,
    4094,
    4107,
    4117,
    4134,
    4150,
    4161,
    4171,
    4184,
    4198,
    4210,
    4220,
    4234,
    4249,
    4260,
    4279,
    4298,
    4322,
    4348,
    4369,
    4396,
    4423,
    4450,
    4472,
    4500,
    4528,
    4556,
    4575,
    4600,
    4625,
    4650,
    4684,
    4705,
    4726,
    4753,
    4780,
    4807,
    4839,
    4857,
    4886,
    4908,
    4925,
    4948,
    4966,
    4992,
    5011,
    5028,
    5048,
    5075,
    5103,
    5131,
    5155,
    5173,
    5201,
    5220,
    5239,
    5262,
    5284,
    5305,
    5335,
    5357,
    5388,
    5419,
    5443,
    5462,
    5483,
    5511,
    5524,
    5547,
    5577,
    5607,
    5636,
    5666,
    5695,
    5713,
    5736,
    5755,
    5775,
    5797,
    5821,
    5845,
    5865,
    5887,
    5909,
    5927,
    5954,
    5980,
    6007,
    6033,
    6055,
    6078,
    6098,
    6120,
    6149,
    6178,
    6205,
    6226,
    6248,
    6276,
    6297,
    6332,
    6354,
    6382,
    6413,
    6441,
    6465,
    6487,
    6507,
    6533,
    6559,
    6586,
    6613,
    6640,
    6658,
    6678,
    6690,
    6697,
    6703,
    6715,
    6726,
    6739,
    6749,
    6751,
    6753,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6761,
    6785,
    6813,
    6840,
    6868,
    6902,
    6925,
    6954,
    6988,
    7013,
    7041,
    7069,
    7104,
    7104,
    7104,
    7104,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7134,
    7157,
    7176,
    7176,
    7176,
    7198,
    7218,
    7237,
    7237,
    7237,
    7255,
    7255,
    7283,
    7283,
    7283,
    7283,
    7283,
    7283,
    7283,
    7283,
    7283,
    7283,
    7283,
    7283,
    7283,
    7283,
    7307,
    7307,
    7307,
    7307,
    7307,
    7307,
    7341,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7376,
    7398,
    7398,
    7398,
    7398,
    7398,
    7398,
    7398,
    7398,
    7398,
    7429,
    7461,
    7461,
    7461,
    7461,
    7461,
    7480,
    7499,
    7499,
    7499,
    7499,
    7499,
    7518,
    7518,
    7518,
    7518,
    7536,
    7536,
    7536,
    7536,
    7536,
    7557,
    7557,
    7576,
    7596,
    7622,
    7648,
    7674,
    7694,
    7715,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7731,
    7746,
    7759,
    7778,
    7801,
    7819,
    7837,
    7857,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7875,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7899,
    7913,
    7925,
    7925,
    7925,
    7941,
    7957,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7971,
    7991,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8018,
    8048,
    8069,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8091,
    8116,
    8137,
    8137,
    8137,
    8137,
    8155,
    8180,
    8204,
    8223,
    8223,
    8223,
    8223,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8243,
    8262,
    8262,
    8282,
    8308,
    8308,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
    8334,
};

enum {
    TOTAL_KEYWORDS = 485,
    MIN_WORD_LENGTH = 1,
    MAX_WORD_LENGTH = 34,
    MIN_HASH_VALUE = 3,
    MAX_HASH_VALUE = 3374
};

/* maximum key range = 3372, duplicates = 0 */

class CSSPropertyNamesHash {
private:
    static inline unsigned int property_hash_function(const char* str, unsigned int len);

public:
    static const struct Property* findPropertyImpl(const char* str, unsigned int len);
};

inline unsigned int
CSSPropertyNamesHash::property_hash_function(register const char* str, register unsigned int len)
{
    static const unsigned short asso_values[] = {
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 4, 9, 150,
        4, 3, 409, 3, 654, 3, 6, 26, 71, 6,
        3, 3, 96, 4, 3, 62, 3, 218, 101, 4,
        894, 923, 176, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375, 3375,
        3375, 3375, 3375, 3375, 3375, 3375
    };
    register int hval = 0;

    switch (len) {
    default:
        hval += asso_values[(unsigned char)str[33]];
    /*FALLTHROUGH*/
    case 33:
        hval += asso_values[(unsigned char)str[32]];
    /*FALLTHROUGH*/
    case 32:
        hval += asso_values[(unsigned char)str[31]];
    /*FALLTHROUGH*/
    case 31:
        hval += asso_values[(unsigned char)str[30]];
    /*FALLTHROUGH*/
    case 30:
        hval += asso_values[(unsigned char)str[29]];
    /*FALLTHROUGH*/
    case 29:
        hval += asso_values[(unsigned char)str[28]];
    /*FALLTHROUGH*/
    case 28:
        hval += asso_values[(unsigned char)str[27]];
    /*FALLTHROUGH*/
    case 27:
        hval += asso_values[(unsigned char)str[26]];
    /*FALLTHROUGH*/
    case 26:
        hval += asso_values[(unsigned char)str[25]];
    /*FALLTHROUGH*/
    case 25:
        hval += asso_values[(unsigned char)str[24]];
    /*FALLTHROUGH*/
    case 24:
        hval += asso_values[(unsigned char)str[23]];
    /*FALLTHROUGH*/
    case 23:
        hval += asso_values[(unsigned char)str[22]];
    /*FALLTHROUGH*/
    case 22:
        hval += asso_values[(unsigned char)str[21]];
    /*FALLTHROUGH*/
    case 21:
        hval += asso_values[(unsigned char)str[20]];
    /*FALLTHROUGH*/
    case 20:
        hval += asso_values[(unsigned char)str[19]];
    /*FALLTHROUGH*/
    case 19:
        hval += asso_values[(unsigned char)str[18]];
    /*FALLTHROUGH*/
    case 18:
        hval += asso_values[(unsigned char)str[17]];
    /*FALLTHROUGH*/
    case 17:
        hval += asso_values[(unsigned char)str[16]];
    /*FALLTHROUGH*/
    case 16:
        hval += asso_values[(unsigned char)str[15]];
    /*FALLTHROUGH*/
    case 15:
        hval += asso_values[(unsigned char)str[14]];
    /*FALLTHROUGH*/
    case 14:
        hval += asso_values[(unsigned char)str[13]];
    /*FALLTHROUGH*/
    case 13:
        hval += asso_values[(unsigned char)str[12]];
    /*FALLTHROUGH*/
    case 12:
        hval += asso_values[(unsigned char)str[11]];
    /*FALLTHROUGH*/
    case 11:
        hval += asso_values[(unsigned char)str[10]];
    /*FALLTHROUGH*/
    case 10:
        hval += asso_values[(unsigned char)str[9]];
    /*FALLTHROUGH*/
    case 9:
        hval += asso_values[(unsigned char)str[8]];
    /*FALLTHROUGH*/
    case 8:
        hval += asso_values[(unsigned char)str[7]];
    /*FALLTHROUGH*/
    case 7:
        hval += asso_values[(unsigned char)str[6]];
    /*FALLTHROUGH*/
    case 6:
        hval += asso_values[(unsigned char)str[5]];
    /*FALLTHROUGH*/
    case 5:
        hval += asso_values[(unsigned char)str[4]];
    /*FALLTHROUGH*/
    case 4:
        hval += asso_values[(unsigned char)str[3]];
    /*FALLTHROUGH*/
    case 3:
        hval += asso_values[(unsigned char)str[2]];
    /*FALLTHROUGH*/
    case 2:
        hval += asso_values[(unsigned char)str[1]];
    /*FALLTHROUGH*/
    case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
    return hval;
}

struct stringpool_t {
    char stringpool_str0[sizeof("r")];
    char stringpool_str1[sizeof("d")];
    char stringpool_str2[sizeof("grid")];
    char stringpool_str3[sizeof("order")];
    char stringpool_str4[sizeof("rotate")];
    char stringpool_str5[sizeof("motion")];
    char stringpool_str6[sizeof("margin")];
    char stringpool_str7[sizeof("border")];
    char stringpool_str8[sizeof("grid-row")];
    char stringpool_str9[sizeof("bottom")];
    char stringpool_str10[sizeof("grid-area")];
    char stringpool_str11[sizeof("animation")];
    char stringpool_str12[sizeof("orientation")];
    char stringpool_str13[sizeof("grid-row-end")];
    char stringpool_str14[sizeof("writing-mode")];
    char stringpool_str15[sizeof("marker")];
    char stringpool_str16[sizeof("border-image")];
    char stringpool_str17[sizeof("motion-rotation")];
    char stringpool_str18[sizeof("image-rendering")];
    char stringpool_str19[sizeof("animation-name")];
    char stringpool_str20[sizeof("margin-bottom")];
    char stringpool_str21[sizeof("border-bottom")];
    char stringpool_str22[sizeof("image-orientation")];
    char stringpool_str23[sizeof("marker-end")];
    char stringpool_str24[sizeof("marker-mid")];
    char stringpool_str25[sizeof("word-break")];
    char stringpool_str26[sizeof("-webkit-order")];
    char stringpool_str27[sizeof("widows")];
    char stringpool_str28[sizeof("-webkit-animation")];
    char stringpool_str29[sizeof("-webkit-margin-end")];
    char stringpool_str30[sizeof("transition")];
    char stringpool_str31[sizeof("-webkit-border-end")];
    char stringpool_str32[sizeof("-webkit-writing-mode")];
    char stringpool_str33[sizeof("mask")];
    char stringpool_str34[sizeof("stroke")];
    char stringpool_str35[sizeof("-webkit-border-image")];
    char stringpool_str36[sizeof("top")];
    char stringpool_str37[sizeof("grid-row-start")];
    char stringpool_str38[sizeof("-webkit-animation-name")];
    char stringpool_str39[sizeof("page")];
    char stringpool_str40[sizeof("padding")];
    char stringpool_str41[sizeof("grid-gap")];
    char stringpool_str42[sizeof("marker-start")];
    char stringpool_str43[sizeof("word-wrap")];
    char stringpool_str44[sizeof("break-inside")];
    char stringpool_str45[sizeof("margin-top")];
    char stringpool_str46[sizeof("paint-order")];
    char stringpool_str47[sizeof("border-top")];
    char stringpool_str48[sizeof("grid-row-gap")];
    char stringpool_str49[sizeof("-webkit-transition")];
    char stringpool_str50[sizeof("all")];
    char stringpool_str51[sizeof("padding-bottom")];
    char stringpool_str52[sizeof("-webkit-mask")];
    char stringpool_str53[sizeof("-webkit-margin-start")];
    char stringpool_str54[sizeof("isolation")];
    char stringpool_str55[sizeof("translate")];
    char stringpool_str56[sizeof("-webkit-border-start")];
    char stringpool_str57[sizeof("-webkit-rtl-ordering")];
    char stringpool_str58[sizeof("border-image-repeat")];
    char stringpool_str59[sizeof("align-items")];
    char stringpool_str60[sizeof("content")];
    char stringpool_str61[sizeof("contain")];
    char stringpool_str62[sizeof("-webkit-mask-origin")];
    char stringpool_str63[sizeof("-webkit-mask-image")];
    char stringpool_str64[sizeof("direction")];
    char stringpool_str65[sizeof("position")];
    char stringpool_str66[sizeof("-webkit-line-break")];
    char stringpool_str67[sizeof("-webkit-padding-end")];
    char stringpool_str68[sizeof("zoom")];
    char stringpool_str69[sizeof("dominant-baseline")];
    char stringpool_str70[sizeof("speak")];
    char stringpool_str71[sizeof("stroke-linejoin")];
    char stringpool_str72[sizeof("min-zoom")];
    char stringpool_str73[sizeof("grid-template")];
    char stringpool_str74[sizeof("stroke-miterlimit")];
    char stringpool_str75[sizeof("animation-direction")];
    char stringpool_str76[sizeof("src")];
    char stringpool_str77[sizeof("-webkit-align-items")];
    char stringpool_str78[sizeof("padding-top")];
    char stringpool_str79[sizeof("color")];
    char stringpool_str80[sizeof("clear")];
    char stringpool_str81[sizeof("page-break-inside")];
    char stringpool_str82[sizeof("size")];
    char stringpool_str83[sizeof("-webkit-padding-start")];
    char stringpool_str84[sizeof("resize")];
    char stringpool_str85[sizeof("align-content")];
    char stringpool_str86[sizeof("border-color")];
    char stringpool_str87[sizeof("alignment-baseline")];
    char stringpool_str88[sizeof("color-rendering")];
    char stringpool_str89[sizeof("tab-size")];
    char stringpool_str90[sizeof("-webkit-animation-direction")];
    char stringpool_str91[sizeof("-webkit-mask-repeat")];
    char stringpool_str92[sizeof("-webkit-app-region")];
    char stringpool_str93[sizeof("animation-duration")];
    char stringpool_str94[sizeof("grid-template-rows")];
    char stringpool_str95[sizeof("grid-template-areas")];
    char stringpool_str96[sizeof("border-bottom-color")];
    char stringpool_str97[sizeof("scale")];
    char stringpool_str98[sizeof("pointer-events")];
    char stringpool_str99[sizeof("quotes")];
    char stringpool_str100[sizeof("outline")];
    char stringpool_str101[sizeof("-webkit-align-content")];
    char stringpool_str102[sizeof("grid-auto-rows")];
    char stringpool_str103[sizeof("clip")];
    char stringpool_str104[sizeof("border-radius")];
    char stringpool_str105[sizeof("-webkit-border-end-color")];
    char stringpool_str106[sizeof("-webkit-animation-duration")];
    char stringpool_str107[sizeof("-webkit-mask-position")];
    char stringpool_str108[sizeof("inline-size")];
    char stringpool_str109[sizeof("transition-duration")];
    char stringpool_str110[sizeof("caption-side")];
    char stringpool_str111[sizeof("word-spacing")];
    char stringpool_str112[sizeof("border-image-slice")];
    char stringpool_str113[sizeof("border-image-outset")];
    char stringpool_str114[sizeof("min-inline-size")];
    char stringpool_str115[sizeof("border-spacing")];
    char stringpool_str116[sizeof("object-position")];
    char stringpool_str117[sizeof("-webkit-locale")];
    char stringpool_str118[sizeof("-webkit-user-drag")];
    char stringpool_str119[sizeof("border-top-color")];
    char stringpool_str120[sizeof("-epub-writing-mode")];
    char stringpool_str121[sizeof("-webkit-border-radius")];
    char stringpool_str122[sizeof("-webkit-transition-duration")];
    char stringpool_str123[sizeof("-webkit-border-start-color")];
    char stringpool_str124[sizeof("-epub-word-break")];
    char stringpool_str125[sizeof("caret-color")];
    char stringpool_str126[sizeof("stop-color")];
    char stringpool_str127[sizeof("-webkit-mask-size")];
    char stringpool_str128[sizeof("unicode-range")];
    char stringpool_str129[sizeof("unicode-bidi")];
    char stringpool_str130[sizeof("letter-spacing")];
    char stringpool_str131[sizeof("font")];
    char stringpool_str132[sizeof("-webkit-appearance")];
    char stringpool_str133[sizeof("background")];
    char stringpool_str134[sizeof("vertical-align")];
    char stringpool_str135[sizeof("stroke-linecap")];
    char stringpool_str136[sizeof("color-interpolation")];
    char stringpool_str137[sizeof("cursor")];
    char stringpool_str138[sizeof("animation-iteration-count")];
    char stringpool_str139[sizeof("background-origin")];
    char stringpool_str140[sizeof("background-image")];
    char stringpool_str141[sizeof("counter-reset")];
    char stringpool_str142[sizeof("-webkit-line-clamp")];
    char stringpool_str143[sizeof("font-kerning")];
    char stringpool_str144[sizeof("grid-column")];
    char stringpool_str145[sizeof("break-after")];
    char stringpool_str146[sizeof("-webkit-mask-clip")];
    char stringpool_str147[sizeof("user-zoom")];
    char stringpool_str148[sizeof("break-before")];
    char stringpool_str149[sizeof("grid-column-end")];
    char stringpool_str150[sizeof("-webkit-mask-composite")];
    char stringpool_str151[sizeof("left")];
    char stringpool_str152[sizeof("border-collapse")];
    char stringpool_str153[sizeof("border-image-source")];
    char stringpool_str154[sizeof("float")];
    char stringpool_str155[sizeof("filter")];
    char stringpool_str156[sizeof("transform")];
    char stringpool_str157[sizeof("-webkit-animation-iteration-count")];
    char stringpool_str158[sizeof("-webkit-background-origin")];
    char stringpool_str159[sizeof("-webkit-margin-after")];
    char stringpool_str160[sizeof("-webkit-border-after")];
    char stringpool_str161[sizeof("block-size")];
    char stringpool_str162[sizeof("-webkit-margin-before")];
    char stringpool_str163[sizeof("margin-left")];
    char stringpool_str164[sizeof("-webkit-border-before")];
    char stringpool_str165[sizeof("columns")];
    char stringpool_str166[sizeof("border-left")];
    char stringpool_str167[sizeof("transform-origin")];
    char stringpool_str168[sizeof("min-block-size")];
    char stringpool_str169[sizeof("perspective")];
    char stringpool_str170[sizeof("background-blend-mode")];
    char stringpool_str171[sizeof("outline-color")];
    char stringpool_str172[sizeof("background-repeat")];
    char stringpool_str173[sizeof("-webkit-margin-collapse")];
    char stringpool_str174[sizeof("font-variant")];
    char stringpool_str175[sizeof("perspective-origin")];
    char stringpool_str176[sizeof("grid-column-start")];
    char stringpool_str177[sizeof("-webkit-filter")];
    char stringpool_str178[sizeof("-webkit-transform")];
    char stringpool_str179[sizeof("fill")];
    char stringpool_str180[sizeof("column-gap")];
    char stringpool_str181[sizeof("counter-increment")];
    char stringpool_str182[sizeof("-webkit-columns")];
    char stringpool_str183[sizeof("-webkit-margin-bottom-collapse")];
    char stringpool_str184[sizeof("-webkit-transform-origin")];
    char stringpool_str185[sizeof("grid-column-gap")];
    char stringpool_str186[sizeof("-webkit-perspective")];
    char stringpool_str187[sizeof("page-break-after")];
    char stringpool_str188[sizeof("user-select")];
    char stringpool_str189[sizeof("page-break-before")];
    char stringpool_str190[sizeof("object-fit")];
    char stringpool_str191[sizeof("-webkit-padding-after")];
    char stringpool_str192[sizeof("overflow")];
    char stringpool_str193[sizeof("-webkit-perspective-origin")];
    char stringpool_str194[sizeof("background-position")];
    char stringpool_str195[sizeof("-webkit-padding-before")];
    char stringpool_str196[sizeof("padding-left")];
    char stringpool_str197[sizeof("animation-fill-mode")];
    char stringpool_str198[sizeof("-webkit-column-gap")];
    char stringpool_str199[sizeof("clip-rule")];
    char stringpool_str200[sizeof("column-span")];
    char stringpool_str201[sizeof("scroll-snap-destination")];
    char stringpool_str202[sizeof("align-self")];
    char stringpool_str203[sizeof("-webkit-column-break-inside")];
    char stringpool_str204[sizeof("-webkit-user-select")];
    char stringpool_str205[sizeof("-webkit-margin-top-collapse")];
    char stringpool_str206[sizeof("background-color")];
    char stringpool_str207[sizeof("-webkit-animation-fill-mode")];
    char stringpool_str208[sizeof("font-size")];
    char stringpool_str209[sizeof("right")];
    char stringpool_str210[sizeof("width")];
    char stringpool_str211[sizeof("-epub-caption-side")];
    char stringpool_str212[sizeof("background-size")];
    char stringpool_str213[sizeof("-webkit-column-span")];
    char stringpool_str214[sizeof("min-width")];
    char stringpool_str215[sizeof("-webkit-align-self")];
    char stringpool_str216[sizeof("margin-right")];
    char stringpool_str217[sizeof("font-variation-settings")];
    char stringpool_str218[sizeof("border-right")];
    char stringpool_str219[sizeof("-webkit-print-color-adjust")];
    char stringpool_str220[sizeof("border-width")];
    char stringpool_str221[sizeof("overflow-wrap")];
    char stringpool_str222[sizeof("scroll-snap-coordinate")];
    char stringpool_str223[sizeof("border-image-width")];
    char stringpool_str224[sizeof("grid-template-columns")];
    char stringpool_str225[sizeof("flood-color")];
    char stringpool_str226[sizeof("-webkit-background-size")];
    char stringpool_str227[sizeof("border-bottom-width")];
    char stringpool_str228[sizeof("grid-auto-flow")];
    char stringpool_str229[sizeof("-webkit-border-after-color")];
    char stringpool_str230[sizeof("-webkit-border-vertical-spacing")];
    char stringpool_str231[sizeof("-webkit-border-before-color")];
    char stringpool_str232[sizeof("background-clip")];
    char stringpool_str233[sizeof("border-left-color")];
    char stringpool_str234[sizeof("column-rule")];
    char stringpool_str235[sizeof("-webkit-transform-origin-z")];
    char stringpool_str236[sizeof("grid-auto-columns")];
    char stringpool_str237[sizeof("-webkit-border-end-width")];
    char stringpool_str238[sizeof("stroke-width")];
    char stringpool_str239[sizeof("motion-path")];
    char stringpool_str240[sizeof("padding-right")];
    char stringpool_str241[sizeof("backdrop-filter")];
    char stringpool_str242[sizeof("-webkit-background-clip")];
    char stringpool_str243[sizeof("border-top-width")];
    char stringpool_str244[sizeof("-webkit-column-rule")];
    char stringpool_str245[sizeof("-webkit-font-size-delta")];
    char stringpool_str246[sizeof("orphans")];
    char stringpool_str247[sizeof("-webkit-border-start-width")];
    char stringpool_str248[sizeof("column-count")];
    char stringpool_str249[sizeof("border-bottom-left-radius")];
    char stringpool_str250[sizeof("shape-margin")];
    char stringpool_str251[sizeof("shape-rendering")];
    char stringpool_str252[sizeof("animation-timing-function")];
    char stringpool_str253[sizeof("fill-rule")];
    char stringpool_str254[sizeof("font-variant-caps")];
    char stringpool_str255[sizeof("-webkit-column-count")];
    char stringpool_str256[sizeof("offset")];
    char stringpool_str257[sizeof("x")];
    char stringpool_str258[sizeof("-webkit-border-bottom-left-radius")];
    char stringpool_str259[sizeof("rx")];
    char stringpool_str260[sizeof("-webkit-shape-margin")];
    char stringpool_str261[sizeof("-webkit-animation-timing-function")];
    char stringpool_str262[sizeof("transition-timing-function")];
    char stringpool_str263[sizeof("offset-rotate")];
    char stringpool_str264[sizeof("motion-offset")];
    char stringpool_str265[sizeof("font-variant-ligatures")];
    char stringpool_str266[sizeof("border-top-left-radius")];
    char stringpool_str267[sizeof("offset-rotation")];
    char stringpool_str268[sizeof("y")];
    char stringpool_str269[sizeof("text-indent")];
    char stringpool_str270[sizeof("ry")];
    char stringpool_str271[sizeof("border-right-color")];
    char stringpool_str272[sizeof("font-variant-numeric")];
    char stringpool_str273[sizeof("text-rendering")];
    char stringpool_str274[sizeof("text-orientation")];
    char stringpool_str275[sizeof("-webkit-transition-timing-function")];
    char stringpool_str276[sizeof("-webkit-margin-after-collapse")];
    char stringpool_str277[sizeof("font-size-adjust")];
    char stringpool_str278[sizeof("will-change")];
    char stringpool_str279[sizeof("-webkit-border-top-left-radius")];
    char stringpool_str280[sizeof("-webkit-margin-before-collapse")];
    char stringpool_str281[sizeof("outline-width")];
    char stringpool_str282[sizeof("lighting-color")];
    char stringpool_str283[sizeof("-webkit-column-break-after")];
    char stringpool_str284[sizeof("-webkit-box-orient")];
    char stringpool_str285[sizeof("column-rule-color")];
    char stringpool_str286[sizeof("white-space")];
    char stringpool_str287[sizeof("-webkit-column-break-before")];
    char stringpool_str288[sizeof("text-align")];
    char stringpool_str289[sizeof("color-interpolation-filters")];
    char stringpool_str290[sizeof("-webkit-text-orientation")];
    char stringpool_str291[sizeof("column-fill")];
    char stringpool_str292[sizeof("mix-blend-mode")];
    char stringpool_str293[sizeof("border-bottom-right-radius")];
    char stringpool_str294[sizeof("-webkit-logical-width")];
    char stringpool_str295[sizeof("-webkit-column-rule-color")];
    char stringpool_str296[sizeof("animation-delay")];
    char stringpool_str297[sizeof("cx")];
    char stringpool_str298[sizeof("-webkit-min-logical-width")];
    char stringpool_str299[sizeof("-webkit-box-align")];
    char stringpool_str300[sizeof("-webkit-text-stroke")];
    char stringpool_str301[sizeof("offset-position")];
    char stringpool_str302[sizeof("cy")];
    char stringpool_str303[sizeof("-webkit-border-bottom-right-radius")];
    char stringpool_str304[sizeof("clip-path")];
    char stringpool_str305[sizeof("-webkit-mask-box-image")];
    char stringpool_str306[sizeof("text-decoration")];
    char stringpool_str307[sizeof("z-index")];
    char stringpool_str308[sizeof("buffered-rendering")];
    char stringpool_str309[sizeof("border-style")];
    char stringpool_str310[sizeof("font-weight")];
    char stringpool_str311[sizeof("-webkit-animation-delay")];
    char stringpool_str312[sizeof("max-zoom")];
    char stringpool_str313[sizeof("border-top-right-radius")];
    char stringpool_str314[sizeof("transition-delay")];
    char stringpool_str315[sizeof("-webkit-box-lines")];
    char stringpool_str316[sizeof("shape-outside")];
    char stringpool_str317[sizeof("border-bottom-style")];
    char stringpool_str318[sizeof("column-width")];
    char stringpool_str319[sizeof("offset-distance")];
    char stringpool_str320[sizeof("mask-type")];
    char stringpool_str321[sizeof("text-align-last")];
    char stringpool_str322[sizeof("-webkit-clip-path")];
    char stringpool_str323[sizeof("-webkit-text-combine")];
    char stringpool_str324[sizeof("-webkit-box-direction")];
    char stringpool_str325[sizeof("scroll-behavior")];
    char stringpool_str326[sizeof("-webkit-border-top-right-radius")];
    char stringpool_str327[sizeof("-webkit-transition-delay")];
    char stringpool_str328[sizeof("-webkit-border-end-style")];
    char stringpool_str329[sizeof("box-sizing")];
    char stringpool_str330[sizeof("display")];
    char stringpool_str331[sizeof("-webkit-mask-repeat-x")];
    char stringpool_str332[sizeof("text-decoration-line")];
    char stringpool_str333[sizeof("-webkit-shape-outside")];
    char stringpool_str334[sizeof("-webkit-border-after-width")];
    char stringpool_str335[sizeof("-webkit-column-width")];
    char stringpool_str336[sizeof("visibility")];
    char stringpool_str337[sizeof("opacity")];
    char stringpool_str338[sizeof("-webkit-border-before-width")];
    char stringpool_str339[sizeof("border-left-width")];
    char stringpool_str340[sizeof("-webkit-box-decoration-break")];
    char stringpool_str341[sizeof("-webkit-mask-repeat-y")];
    char stringpool_str342[sizeof("border-top-style")];
    char stringpool_str343[sizeof("outline-offset")];
    char stringpool_str344[sizeof("touch-action")];
    char stringpool_str345[sizeof("-webkit-mask-box-image-repeat")];
    char stringpool_str346[sizeof("list-style")];
    char stringpool_str347[sizeof("animation-play-state")];
    char stringpool_str348[sizeof("font-feature-settings")];
    char stringpool_str349[sizeof("-webkit-box-sizing")];
    char stringpool_str350[sizeof("-webkit-font-smoothing")];
    char stringpool_str351[sizeof("-webkit-border-start-style")];
    char stringpool_str352[sizeof("transition-property")];
    char stringpool_str353[sizeof("list-style-image")];
    char stringpool_str354[sizeof("-webkit-mask-position-x")];
    char stringpool_str355[sizeof("-webkit-opacity")];
    char stringpool_str356[sizeof("-webkit-box-pack")];
    char stringpool_str357[sizeof("max-inline-size")];
    char stringpool_str358[sizeof("vector-effect")];
    char stringpool_str359[sizeof("-webkit-mask-position-y")];
    char stringpool_str360[sizeof("background-attachment")];
    char stringpool_str361[sizeof("-webkit-animation-play-state")];
    char stringpool_str362[sizeof("-webkit-font-feature-settings")];
    char stringpool_str363[sizeof("-epub-text-orientation")];
    char stringpool_str364[sizeof("text-decoration-skip")];
    char stringpool_str365[sizeof("-webkit-transition-property")];
    char stringpool_str366[sizeof("stroke-opacity")];
    char stringpool_str367[sizeof("baseline-shift")];
    char stringpool_str368[sizeof("-webkit-text-stroke-color")];
    char stringpool_str369[sizeof("font-stretch")];
    char stringpool_str370[sizeof("table-layout")];
    char stringpool_str371[sizeof("text-decoration-color")];
    char stringpool_str372[sizeof("height")];
    char stringpool_str373[sizeof("-webkit-border-horizontal-spacing")];
    char stringpool_str374[sizeof("min-height")];
    char stringpool_str375[sizeof("stop-opacity")];
    char stringpool_str376[sizeof("border-right-width")];
    char stringpool_str377[sizeof("outline-style")];
    char stringpool_str378[sizeof("-webkit-mask-box-image-slice")];
    char stringpool_str379[sizeof("flex")];
    char stringpool_str380[sizeof("-webkit-mask-box-image-outset")];
    char stringpool_str381[sizeof("-webkit-box-ordinal-group")];
    char stringpool_str382[sizeof("list-style-position")];
    char stringpool_str383[sizeof("-webkit-ruby-position")];
    char stringpool_str384[sizeof("empty-cells")];
    char stringpool_str385[sizeof("flex-grow")];
    char stringpool_str386[sizeof("text-underline-position")];
    char stringpool_str387[sizeof("text-transform")];
    char stringpool_str388[sizeof("line-height")];
    char stringpool_str389[sizeof("max-block-size")];
    char stringpool_str390[sizeof("-epub-text-combine")];
    char stringpool_str391[sizeof("overflow-anchor")];
    char stringpool_str392[sizeof("column-rule-width")];
    char stringpool_str393[sizeof("-webkit-flex")];
    char stringpool_str394[sizeof("background-repeat-x")];
    char stringpool_str395[sizeof("-webkit-flex-grow")];
    char stringpool_str396[sizeof("text-size-adjust")];
    char stringpool_str397[sizeof("background-repeat-y")];
    char stringpool_str398[sizeof("-webkit-transform-origin-x")];
    char stringpool_str399[sizeof("-webkit-column-rule-width")];
    char stringpool_str400[sizeof("font-style")];
    char stringpool_str401[sizeof("flex-wrap")];
    char stringpool_str402[sizeof("snap-height")];
    char stringpool_str403[sizeof("overflow-x")];
    char stringpool_str404[sizeof("-webkit-perspective-origin-x")];
    char stringpool_str405[sizeof("-webkit-transform-origin-y")];
    char stringpool_str406[sizeof("background-position-x")];
    char stringpool_str407[sizeof("text-overflow")];
    char stringpool_str408[sizeof("-webkit-text-size-adjust")];
    char stringpool_str409[sizeof("flex-basis")];
    char stringpool_str410[sizeof("overflow-y")];
    char stringpool_str411[sizeof("-webkit-perspective-origin-y")];
    char stringpool_str412[sizeof("-webkit-mask-box-image-source")];
    char stringpool_str413[sizeof("background-position-y")];
    char stringpool_str414[sizeof("-webkit-flex-wrap")];
    char stringpool_str415[sizeof("flex-direction")];
    char stringpool_str416[sizeof("scroll-snap-type")];
    char stringpool_str417[sizeof("transform-style")];
    char stringpool_str418[sizeof("mask-source-type")];
    char stringpool_str419[sizeof("-webkit-border-after-style")];
    char stringpool_str420[sizeof("-webkit-flex-basis")];
    char stringpool_str421[sizeof("max-width")];
    char stringpool_str422[sizeof("-webkit-border-before-style")];
    char stringpool_str423[sizeof("border-left-style")];
    char stringpool_str424[sizeof("font-display")];
    char stringpool_str425[sizeof("scroll-snap-points-x")];
    char stringpool_str426[sizeof("-webkit-box-reflect")];
    char stringpool_str427[sizeof("-webkit-flex-direction")];
    char stringpool_str428[sizeof("-webkit-transform-style")];
    char stringpool_str429[sizeof("scroll-snap-points-y")];
    char stringpool_str430[sizeof("text-shadow")];
    char stringpool_str431[sizeof("box-shadow")];
    char stringpool_str432[sizeof("offset-path")];
    char stringpool_str433[sizeof("flood-opacity")];
    char stringpool_str434[sizeof("-webkit-logical-height")];
    char stringpool_str435[sizeof("-webkit-user-modify")];
    char stringpool_str436[sizeof("-webkit-box-shadow")];
    char stringpool_str437[sizeof("-webkit-min-logical-height")];
    char stringpool_str438[sizeof("justify-items")];
    char stringpool_str439[sizeof("offset-anchor")];
    char stringpool_str440[sizeof("stroke-dashoffset")];
    char stringpool_str441[sizeof("text-anchor")];
    char stringpool_str442[sizeof("-webkit-text-stroke-width")];
    char stringpool_str443[sizeof("-epub-text-transform")];
    char stringpool_str444[sizeof("fill-opacity")];
    char stringpool_str445[sizeof("-webkit-text-fill-color")];
    char stringpool_str446[sizeof("-webkit-mask-box-image-width")];
    char stringpool_str447[sizeof("border-right-style")];
    char stringpool_str448[sizeof("stroke-dasharray")];
    char stringpool_str449[sizeof("justify-content")];
    char stringpool_str450[sizeof("column-rule-style")];
    char stringpool_str451[sizeof("font-family")];
    char stringpool_str452[sizeof("-webkit-justify-content")];
    char stringpool_str453[sizeof("-webkit-text-emphasis")];
    char stringpool_str454[sizeof("flex-flow")];
    char stringpool_str455[sizeof("-webkit-column-rule-style")];
    char stringpool_str456[sizeof("-webkit-flex-flow")];
    char stringpool_str457[sizeof("-webkit-max-logical-width")];
    char stringpool_str458[sizeof("backface-visibility")];
    char stringpool_str459[sizeof("-webkit-backface-visibility")];
    char stringpool_str460[sizeof("-webkit-text-emphasis-position")];
    char stringpool_str461[sizeof("text-combine-upright")];
    char stringpool_str462[sizeof("-webkit-text-emphasis-color")];
    char stringpool_str463[sizeof("-webkit-highlight")];
    char stringpool_str464[sizeof("-epub-text-emphasis")];
    char stringpool_str465[sizeof("flex-shrink")];
    char stringpool_str466[sizeof("text-decoration-style")];
    char stringpool_str467[sizeof("justify-self")];
    char stringpool_str468[sizeof("-webkit-flex-shrink")];
    char stringpool_str469[sizeof("-webkit-text-decorations-in-effect")];
    char stringpool_str470[sizeof("max-height")];
    char stringpool_str471[sizeof("list-style-type")];
    char stringpool_str472[sizeof("shape-image-threshold")];
    char stringpool_str473[sizeof("-webkit-text-security")];
    char stringpool_str474[sizeof("-webkit-box-flex")];
    char stringpool_str475[sizeof("-webkit-shape-image-threshold")];
    char stringpool_str476[sizeof("-epub-text-emphasis-color")];
    char stringpool_str477[sizeof("hyphens")];
    char stringpool_str478[sizeof("-webkit-tap-highlight-color")];
    char stringpool_str479[sizeof("text-justify")];
    char stringpool_str480[sizeof("-webkit-max-logical-height")];
    char stringpool_str481[sizeof("-webkit-box-flex-group")];
    char stringpool_str482[sizeof("-webkit-text-emphasis-style")];
    char stringpool_str483[sizeof("-epub-text-emphasis-style")];
    char stringpool_str484[sizeof("-webkit-hyphenate-character")];
};
static const struct stringpool_t stringpool_contents = {
    "r",
    "d",
    "grid",
    "order",
    "rotate",
    "motion",
    "margin",
    "border",
    "grid-row",
    "bottom",
    "grid-area",
    "animation",
    "orientation",
    "grid-row-end",
    "writing-mode",
    "marker",
    "border-image",
    "motion-rotation",
    "image-rendering",
    "animation-name",
    "margin-bottom",
    "border-bottom",
    "image-orientation",
    "marker-end",
    "marker-mid",
    "word-break",
    "-webkit-order",
    "widows",
    "-webkit-animation",
    "-webkit-margin-end",
    "transition",
    "-webkit-border-end",
    "-webkit-writing-mode",
    "mask",
    "stroke",
    "-webkit-border-image",
    "top",
    "grid-row-start",
    "-webkit-animation-name",
    "page",
    "padding",
    "grid-gap",
    "marker-start",
    "word-wrap",
    "break-inside",
    "margin-top",
    "paint-order",
    "border-top",
    "grid-row-gap",
    "-webkit-transition",
    "all",
    "padding-bottom",
    "-webkit-mask",
    "-webkit-margin-start",
    "isolation",
    "translate",
    "-webkit-border-start",
    "-webkit-rtl-ordering",
    "border-image-repeat",
    "align-items",
    "content",
    "contain",
    "-webkit-mask-origin",
    "-webkit-mask-image",
    "direction",
    "position",
    "-webkit-line-break",
    "-webkit-padding-end",
    "zoom",
    "dominant-baseline",
    "speak",
    "stroke-linejoin",
    "min-zoom",
    "grid-template",
    "stroke-miterlimit",
    "animation-direction",
    "src",
    "-webkit-align-items",
    "padding-top",
    "color",
    "clear",
    "page-break-inside",
    "size",
    "-webkit-padding-start",
    "resize",
    "align-content",
    "border-color",
    "alignment-baseline",
    "color-rendering",
    "tab-size",
    "-webkit-animation-direction",
    "-webkit-mask-repeat",
    "-webkit-app-region",
    "animation-duration",
    "grid-template-rows",
    "grid-template-areas",
    "border-bottom-color",
    "scale",
    "pointer-events",
    "quotes",
    "outline",
    "-webkit-align-content",
    "grid-auto-rows",
    "clip",
    "border-radius",
    "-webkit-border-end-color",
    "-webkit-animation-duration",
    "-webkit-mask-position",
    "inline-size",
    "transition-duration",
    "caption-side",
    "word-spacing",
    "border-image-slice",
    "border-image-outset",
    "min-inline-size",
    "border-spacing",
    "object-position",
    "-webkit-locale",
    "-webkit-user-drag",
    "border-top-color",
    "-epub-writing-mode",
    "-webkit-border-radius",
    "-webkit-transition-duration",
    "-webkit-border-start-color",
    "-epub-word-break",
    "caret-color",
    "stop-color",
    "-webkit-mask-size",
    "unicode-range",
    "unicode-bidi",
    "letter-spacing",
    "font",
    "-webkit-appearance",
    "background",
    "vertical-align",
    "stroke-linecap",
    "color-interpolation",
    "cursor",
    "animation-iteration-count",
    "background-origin",
    "background-image",
    "counter-reset",
    "-webkit-line-clamp",
    "font-kerning",
    "grid-column",
    "break-after",
    "-webkit-mask-clip",
    "user-zoom",
    "break-before",
    "grid-column-end",
    "-webkit-mask-composite",
    "left",
    "border-collapse",
    "border-image-source",
    "float",
    "filter",
    "transform",
    "-webkit-animation-iteration-count",
    "-webkit-background-origin",
    "-webkit-margin-after",
    "-webkit-border-after",
    "block-size",
    "-webkit-margin-before",
    "margin-left",
    "-webkit-border-before",
    "columns",
    "border-left",
    "transform-origin",
    "min-block-size",
    "perspective",
    "background-blend-mode",
    "outline-color",
    "background-repeat",
    "-webkit-margin-collapse",
    "font-variant",
    "perspective-origin",
    "grid-column-start",
    "-webkit-filter",
    "-webkit-transform",
    "fill",
    "column-gap",
    "counter-increment",
    "-webkit-columns",
    "-webkit-margin-bottom-collapse",
    "-webkit-transform-origin",
    "grid-column-gap",
    "-webkit-perspective",
    "page-break-after",
    "user-select",
    "page-break-before",
    "object-fit",
    "-webkit-padding-after",
    "overflow",
    "-webkit-perspective-origin",
    "background-position",
    "-webkit-padding-before",
    "padding-left",
    "animation-fill-mode",
    "-webkit-column-gap",
    "clip-rule",
    "column-span",
    "scroll-snap-destination",
    "align-self",
    "-webkit-column-break-inside",
    "-webkit-user-select",
    "-webkit-margin-top-collapse",
    "background-color",
    "-webkit-animation-fill-mode",
    "font-size",
    "right",
    "width",
    "-epub-caption-side",
    "background-size",
    "-webkit-column-span",
    "min-width",
    "-webkit-align-self",
    "margin-right",
    "font-variation-settings",
    "border-right",
    "-webkit-print-color-adjust",
    "border-width",
    "overflow-wrap",
    "scroll-snap-coordinate",
    "border-image-width",
    "grid-template-columns",
    "flood-color",
    "-webkit-background-size",
    "border-bottom-width",
    "grid-auto-flow",
    "-webkit-border-after-color",
    "-webkit-border-vertical-spacing",
    "-webkit-border-before-color",
    "background-clip",
    "border-left-color",
    "column-rule",
    "-webkit-transform-origin-z",
    "grid-auto-columns",
    "-webkit-border-end-width",
    "stroke-width",
    "motion-path",
    "padding-right",
    "backdrop-filter",
    "-webkit-background-clip",
    "border-top-width",
    "-webkit-column-rule",
    "-webkit-font-size-delta",
    "orphans",
    "-webkit-border-start-width",
    "column-count",
    "border-bottom-left-radius",
    "shape-margin",
    "shape-rendering",
    "animation-timing-function",
    "fill-rule",
    "font-variant-caps",
    "-webkit-column-count",
    "offset",
    "x",
    "-webkit-border-bottom-left-radius",
    "rx",
    "-webkit-shape-margin",
    "-webkit-animation-timing-function",
    "transition-timing-function",
    "offset-rotate",
    "motion-offset",
    "font-variant-ligatures",
    "border-top-left-radius",
    "offset-rotation",
    "y",
    "text-indent",
    "ry",
    "border-right-color",
    "font-variant-numeric",
    "text-rendering",
    "text-orientation",
    "-webkit-transition-timing-function",
    "-webkit-margin-after-collapse",
    "font-size-adjust",
    "will-change",
    "-webkit-border-top-left-radius",
    "-webkit-margin-before-collapse",
    "outline-width",
    "lighting-color",
    "-webkit-column-break-after",
    "-webkit-box-orient",
    "column-rule-color",
    "white-space",
    "-webkit-column-break-before",
    "text-align",
    "color-interpolation-filters",
    "-webkit-text-orientation",
    "column-fill",
    "mix-blend-mode",
    "border-bottom-right-radius",
    "-webkit-logical-width",
    "-webkit-column-rule-color",
    "animation-delay",
    "cx",
    "-webkit-min-logical-width",
    "-webkit-box-align",
    "-webkit-text-stroke",
    "offset-position",
    "cy",
    "-webkit-border-bottom-right-radius",
    "clip-path",
    "-webkit-mask-box-image",
    "text-decoration",
    "z-index",
    "buffered-rendering",
    "border-style",
    "font-weight",
    "-webkit-animation-delay",
    "max-zoom",
    "border-top-right-radius",
    "transition-delay",
    "-webkit-box-lines",
    "shape-outside",
    "border-bottom-style",
    "column-width",
    "offset-distance",
    "mask-type",
    "text-align-last",
    "-webkit-clip-path",
    "-webkit-text-combine",
    "-webkit-box-direction",
    "scroll-behavior",
    "-webkit-border-top-right-radius",
    "-webkit-transition-delay",
    "-webkit-border-end-style",
    "box-sizing",
    "display",
    "-webkit-mask-repeat-x",
    "text-decoration-line",
    "-webkit-shape-outside",
    "-webkit-border-after-width",
    "-webkit-column-width",
    "visibility",
    "opacity",
    "-webkit-border-before-width",
    "border-left-width",
    "-webkit-box-decoration-break",
    "-webkit-mask-repeat-y",
    "border-top-style",
    "outline-offset",
    "touch-action",
    "-webkit-mask-box-image-repeat",
    "list-style",
    "animation-play-state",
    "font-feature-settings",
    "-webkit-box-sizing",
    "-webkit-font-smoothing",
    "-webkit-border-start-style",
    "transition-property",
    "list-style-image",
    "-webkit-mask-position-x",
    "-webkit-opacity",
    "-webkit-box-pack",
    "max-inline-size",
    "vector-effect",
    "-webkit-mask-position-y",
    "background-attachment",
    "-webkit-animation-play-state",
    "-webkit-font-feature-settings",
    "-epub-text-orientation",
    "text-decoration-skip",
    "-webkit-transition-property",
    "stroke-opacity",
    "baseline-shift",
    "-webkit-text-stroke-color",
    "font-stretch",
    "table-layout",
    "text-decoration-color",
    "height",
    "-webkit-border-horizontal-spacing",
    "min-height",
    "stop-opacity",
    "border-right-width",
    "outline-style",
    "-webkit-mask-box-image-slice",
    "flex",
    "-webkit-mask-box-image-outset",
    "-webkit-box-ordinal-group",
    "list-style-position",
    "-webkit-ruby-position",
    "empty-cells",
    "flex-grow",
    "text-underline-position",
    "text-transform",
    "line-height",
    "max-block-size",
    "-epub-text-combine",
    "overflow-anchor",
    "column-rule-width",
    "-webkit-flex",
    "background-repeat-x",
    "-webkit-flex-grow",
    "text-size-adjust",
    "background-repeat-y",
    "-webkit-transform-origin-x",
    "-webkit-column-rule-width",
    "font-style",
    "flex-wrap",
    "snap-height",
    "overflow-x",
    "-webkit-perspective-origin-x",
    "-webkit-transform-origin-y",
    "background-position-x",
    "text-overflow",
    "-webkit-text-size-adjust",
    "flex-basis",
    "overflow-y",
    "-webkit-perspective-origin-y",
    "-webkit-mask-box-image-source",
    "background-position-y",
    "-webkit-flex-wrap",
    "flex-direction",
    "scroll-snap-type",
    "transform-style",
    "mask-source-type",
    "-webkit-border-after-style",
    "-webkit-flex-basis",
    "max-width",
    "-webkit-border-before-style",
    "border-left-style",
    "font-display",
    "scroll-snap-points-x",
    "-webkit-box-reflect",
    "-webkit-flex-direction",
    "-webkit-transform-style",
    "scroll-snap-points-y",
    "text-shadow",
    "box-shadow",
    "offset-path",
    "flood-opacity",
    "-webkit-logical-height",
    "-webkit-user-modify",
    "-webkit-box-shadow",
    "-webkit-min-logical-height",
    "justify-items",
    "offset-anchor",
    "stroke-dashoffset",
    "text-anchor",
    "-webkit-text-stroke-width",
    "-epub-text-transform",
    "fill-opacity",
    "-webkit-text-fill-color",
    "-webkit-mask-box-image-width",
    "border-right-style",
    "stroke-dasharray",
    "justify-content",
    "column-rule-style",
    "font-family",
    "-webkit-justify-content",
    "-webkit-text-emphasis",
    "flex-flow",
    "-webkit-column-rule-style",
    "-webkit-flex-flow",
    "-webkit-max-logical-width",
    "backface-visibility",
    "-webkit-backface-visibility",
    "-webkit-text-emphasis-position",
    "text-combine-upright",
    "-webkit-text-emphasis-color",
    "-webkit-highlight",
    "-epub-text-emphasis",
    "flex-shrink",
    "text-decoration-style",
    "justify-self",
    "-webkit-flex-shrink",
    "-webkit-text-decorations-in-effect",
    "max-height",
    "list-style-type",
    "shape-image-threshold",
    "-webkit-text-security",
    "-webkit-box-flex",
    "-webkit-shape-image-threshold",
    "-epub-text-emphasis-color",
    "hyphens",
    "-webkit-tap-highlight-color",
    "text-justify",
    "-webkit-max-logical-height",
    "-webkit-box-flex-group",
    "-webkit-text-emphasis-style",
    "-epub-text-emphasis-style",
    "-webkit-hyphenate-character"
};
#define stringpool ((const char*)&stringpool_contents)

static const struct Property property_word_list[] = {
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str0, CSSPropertyR },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str1, CSSPropertyD },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str2, CSSPropertyGrid },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str3, CSSPropertyOrder },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str4, CSSPropertyRotate },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str5, CSSPropertyMotion },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str6, CSSPropertyMargin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str7, CSSPropertyBorder },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str8, CSSPropertyGridRow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str9, CSSPropertyBottom },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str10, CSSPropertyGridArea },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str11, CSSPropertyAnimation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str12, CSSPropertyOrientation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str13, CSSPropertyGridRowEnd },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str14, CSSPropertyWritingMode },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str15, CSSPropertyMarker },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str16, CSSPropertyBorderImage },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str17, CSSPropertyAliasMotionRotation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str18, CSSPropertyImageRendering },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str19, CSSPropertyAnimationName },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str20, CSSPropertyMarginBottom },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str21, CSSPropertyBorderBottom },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str22, CSSPropertyImageOrientation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str23, CSSPropertyMarkerEnd },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str24, CSSPropertyMarkerMid },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str25, CSSPropertyWordBreak },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str26, CSSPropertyAliasWebkitOrder },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str27, CSSPropertyWidows },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str28, CSSPropertyAliasWebkitAnimation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str29, CSSPropertyWebkitMarginEnd },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str30, CSSPropertyTransition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str31, CSSPropertyWebkitBorderEnd },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str32, CSSPropertyWebkitWritingMode },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str33, CSSPropertyMask },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str34, CSSPropertyStroke },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str35, CSSPropertyWebkitBorderImage },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str36, CSSPropertyTop },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str37, CSSPropertyGridRowStart },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str38, CSSPropertyAliasWebkitAnimationName },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str39, CSSPropertyPage },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str40, CSSPropertyPadding },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str41, CSSPropertyGridGap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str42, CSSPropertyMarkerStart },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str43, CSSPropertyWordWrap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str44, CSSPropertyBreakInside },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str45, CSSPropertyMarginTop },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str46, CSSPropertyPaintOrder },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str47, CSSPropertyBorderTop },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str48, CSSPropertyGridRowGap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str49, CSSPropertyAliasWebkitTransition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str50, CSSPropertyAll },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str51, CSSPropertyPaddingBottom },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str52, CSSPropertyWebkitMask },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str53, CSSPropertyWebkitMarginStart },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str54, CSSPropertyIsolation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str55, CSSPropertyTranslate },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str56, CSSPropertyWebkitBorderStart },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str57, CSSPropertyWebkitRtlOrdering },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str58, CSSPropertyBorderImageRepeat },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str59, CSSPropertyAlignItems },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str60, CSSPropertyContent },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str61, CSSPropertyContain },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str62, CSSPropertyWebkitMaskOrigin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str63, CSSPropertyWebkitMaskImage },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str64, CSSPropertyDirection },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str65, CSSPropertyPosition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str66, CSSPropertyWebkitLineBreak },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str67, CSSPropertyWebkitPaddingEnd },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str68, CSSPropertyZoom },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str69, CSSPropertyDominantBaseline },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str70, CSSPropertySpeak },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str71, CSSPropertyStrokeLinejoin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str72, CSSPropertyMinZoom },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str73, CSSPropertyGridTemplate },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str74, CSSPropertyStrokeMiterlimit },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str75, CSSPropertyAnimationDirection },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str76, CSSPropertySrc },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str77, CSSPropertyAliasWebkitAlignItems },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str78, CSSPropertyPaddingTop },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str79, CSSPropertyColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str80, CSSPropertyClear },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str81, CSSPropertyPageBreakInside },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str82, CSSPropertySize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str83, CSSPropertyWebkitPaddingStart },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str84, CSSPropertyResize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str85, CSSPropertyAlignContent },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str86, CSSPropertyBorderColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str87, CSSPropertyAlignmentBaseline },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str88, CSSPropertyColorRendering },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str89, CSSPropertyTabSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str90, CSSPropertyAliasWebkitAnimationDirection },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str91, CSSPropertyWebkitMaskRepeat },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str92, CSSPropertyWebkitAppRegion },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str93, CSSPropertyAnimationDuration },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str94, CSSPropertyGridTemplateRows },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str95, CSSPropertyGridTemplateAreas },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str96, CSSPropertyBorderBottomColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str97, CSSPropertyScale },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str98, CSSPropertyPointerEvents },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str99, CSSPropertyQuotes },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str100, CSSPropertyOutline },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str101, CSSPropertyAliasWebkitAlignContent },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str102, CSSPropertyGridAutoRows },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str103, CSSPropertyClip },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str104, CSSPropertyBorderRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str105, CSSPropertyWebkitBorderEndColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str106, CSSPropertyAliasWebkitAnimationDuration },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str107, CSSPropertyWebkitMaskPosition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str108, CSSPropertyInlineSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str109, CSSPropertyTransitionDuration },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str110, CSSPropertyCaptionSide },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str111, CSSPropertyWordSpacing },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str112, CSSPropertyBorderImageSlice },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str113, CSSPropertyBorderImageOutset },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str114, CSSPropertyMinInlineSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str115, CSSPropertyBorderSpacing },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str116, CSSPropertyObjectPosition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str117, CSSPropertyWebkitLocale },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str118, CSSPropertyWebkitUserDrag },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str119, CSSPropertyBorderTopColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str120, CSSPropertyAliasEpubWritingMode },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str121, CSSPropertyAliasWebkitBorderRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str122, CSSPropertyAliasWebkitTransitionDuration },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str123, CSSPropertyWebkitBorderStartColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str124, CSSPropertyAliasEpubWordBreak },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str125, CSSPropertyCaretColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str126, CSSPropertyStopColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str127, CSSPropertyWebkitMaskSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str128, CSSPropertyUnicodeRange },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str129, CSSPropertyUnicodeBidi },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str130, CSSPropertyLetterSpacing },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str131, CSSPropertyFont },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str132, CSSPropertyWebkitAppearance },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str133, CSSPropertyBackground },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str134, CSSPropertyVerticalAlign },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str135, CSSPropertyStrokeLinecap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str136, CSSPropertyColorInterpolation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str137, CSSPropertyCursor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str138, CSSPropertyAnimationIterationCount },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str139, CSSPropertyBackgroundOrigin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str140, CSSPropertyBackgroundImage },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str141, CSSPropertyCounterReset },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str142, CSSPropertyWebkitLineClamp },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str143, CSSPropertyFontKerning },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str144, CSSPropertyGridColumn },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str145, CSSPropertyBreakAfter },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str146, CSSPropertyWebkitMaskClip },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str147, CSSPropertyUserZoom },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str148, CSSPropertyBreakBefore },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str149, CSSPropertyGridColumnEnd },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str150, CSSPropertyWebkitMaskComposite },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str151, CSSPropertyLeft },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str152, CSSPropertyBorderCollapse },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str153, CSSPropertyBorderImageSource },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str154, CSSPropertyFloat },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str155, CSSPropertyFilter },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str156, CSSPropertyTransform },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str157, CSSPropertyAliasWebkitAnimationIterationCount },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str158, CSSPropertyWebkitBackgroundOrigin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str159, CSSPropertyWebkitMarginAfter },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str160, CSSPropertyWebkitBorderAfter },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str161, CSSPropertyBlockSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str162, CSSPropertyWebkitMarginBefore },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str163, CSSPropertyMarginLeft },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str164, CSSPropertyWebkitBorderBefore },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str165, CSSPropertyColumns },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str166, CSSPropertyBorderLeft },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str167, CSSPropertyTransformOrigin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str168, CSSPropertyMinBlockSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str169, CSSPropertyPerspective },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str170, CSSPropertyBackgroundBlendMode },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str171, CSSPropertyOutlineColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str172, CSSPropertyBackgroundRepeat },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str173, CSSPropertyWebkitMarginCollapse },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str174, CSSPropertyFontVariant },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str175, CSSPropertyPerspectiveOrigin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str176, CSSPropertyGridColumnStart },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str177, CSSPropertyAliasWebkitFilter },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str178, CSSPropertyAliasWebkitTransform },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str179, CSSPropertyFill },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str180, CSSPropertyColumnGap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str181, CSSPropertyCounterIncrement },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str182, CSSPropertyAliasWebkitColumns },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str183, CSSPropertyWebkitMarginBottomCollapse },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str184, CSSPropertyAliasWebkitTransformOrigin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str185, CSSPropertyGridColumnGap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str186, CSSPropertyAliasWebkitPerspective },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str187, CSSPropertyPageBreakAfter },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str188, CSSPropertyUserSelect },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str189, CSSPropertyPageBreakBefore },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str190, CSSPropertyObjectFit },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str191, CSSPropertyWebkitPaddingAfter },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str192, CSSPropertyOverflow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str193, CSSPropertyAliasWebkitPerspectiveOrigin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str194, CSSPropertyBackgroundPosition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str195, CSSPropertyWebkitPaddingBefore },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str196, CSSPropertyPaddingLeft },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str197, CSSPropertyAnimationFillMode },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str198, CSSPropertyAliasWebkitColumnGap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str199, CSSPropertyClipRule },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str200, CSSPropertyColumnSpan },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str201, CSSPropertyScrollSnapDestination },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str202, CSSPropertyAlignSelf },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str203, CSSPropertyWebkitColumnBreakInside },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str204, CSSPropertyAliasWebkitUserSelect },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str205, CSSPropertyWebkitMarginTopCollapse },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str206, CSSPropertyBackgroundColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str207, CSSPropertyAliasWebkitAnimationFillMode },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str208, CSSPropertyFontSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str209, CSSPropertyRight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str210, CSSPropertyWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str211, CSSPropertyAliasEpubCaptionSide },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str212, CSSPropertyBackgroundSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str213, CSSPropertyAliasWebkitColumnSpan },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str214, CSSPropertyMinWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str215, CSSPropertyAliasWebkitAlignSelf },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str216, CSSPropertyMarginRight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str217, CSSPropertyFontVariationSettings },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str218, CSSPropertyBorderRight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str219, CSSPropertyWebkitPrintColorAdjust },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str220, CSSPropertyBorderWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str221, CSSPropertyOverflowWrap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str222, CSSPropertyScrollSnapCoordinate },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str223, CSSPropertyBorderImageWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str224, CSSPropertyGridTemplateColumns },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str225, CSSPropertyFloodColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str226, CSSPropertyAliasWebkitBackgroundSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str227, CSSPropertyBorderBottomWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str228, CSSPropertyGridAutoFlow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str229, CSSPropertyWebkitBorderAfterColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str230, CSSPropertyWebkitBorderVerticalSpacing },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str231, CSSPropertyWebkitBorderBeforeColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str232, CSSPropertyBackgroundClip },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str233, CSSPropertyBorderLeftColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str234, CSSPropertyColumnRule },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str235, CSSPropertyWebkitTransformOriginZ },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str236, CSSPropertyGridAutoColumns },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str237, CSSPropertyWebkitBorderEndWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str238, CSSPropertyStrokeWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str239, CSSPropertyAliasMotionPath },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str240, CSSPropertyPaddingRight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str241, CSSPropertyBackdropFilter },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str242, CSSPropertyWebkitBackgroundClip },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str243, CSSPropertyBorderTopWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str244, CSSPropertyAliasWebkitColumnRule },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str245, CSSPropertyWebkitFontSizeDelta },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str246, CSSPropertyOrphans },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str247, CSSPropertyWebkitBorderStartWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str248, CSSPropertyColumnCount },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str249, CSSPropertyBorderBottomLeftRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str250, CSSPropertyShapeMargin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str251, CSSPropertyShapeRendering },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str252, CSSPropertyAnimationTimingFunction },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str253, CSSPropertyFillRule },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str254, CSSPropertyFontVariantCaps },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str255, CSSPropertyAliasWebkitColumnCount },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str256, CSSPropertyOffset },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str257, CSSPropertyX },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str258, CSSPropertyAliasWebkitBorderBottomLeftRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str259, CSSPropertyRx },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str260, CSSPropertyAliasWebkitShapeMargin },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str261, CSSPropertyAliasWebkitAnimationTimingFunction },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str262, CSSPropertyTransitionTimingFunction },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str263, CSSPropertyOffsetRotate },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str264, CSSPropertyAliasMotionOffset },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str265, CSSPropertyFontVariantLigatures },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str266, CSSPropertyBorderTopLeftRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str267, CSSPropertyOffsetRotation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str268, CSSPropertyY },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str269, CSSPropertyTextIndent },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str270, CSSPropertyRy },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str271, CSSPropertyBorderRightColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str272, CSSPropertyFontVariantNumeric },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str273, CSSPropertyTextRendering },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str274, CSSPropertyTextOrientation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str275, CSSPropertyAliasWebkitTransitionTimingFunction },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str276, CSSPropertyWebkitMarginAfterCollapse },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str277, CSSPropertyFontSizeAdjust },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str278, CSSPropertyWillChange },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str279, CSSPropertyAliasWebkitBorderTopLeftRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str280, CSSPropertyWebkitMarginBeforeCollapse },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str281, CSSPropertyOutlineWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str282, CSSPropertyLightingColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str283, CSSPropertyWebkitColumnBreakAfter },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str284, CSSPropertyWebkitBoxOrient },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str285, CSSPropertyColumnRuleColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str286, CSSPropertyWhiteSpace },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str287, CSSPropertyWebkitColumnBreakBefore },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str288, CSSPropertyTextAlign },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str289, CSSPropertyColorInterpolationFilters },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str290, CSSPropertyWebkitTextOrientation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str291, CSSPropertyColumnFill },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str292, CSSPropertyMixBlendMode },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str293, CSSPropertyBorderBottomRightRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str294, CSSPropertyWebkitLogicalWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str295, CSSPropertyAliasWebkitColumnRuleColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str296, CSSPropertyAnimationDelay },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str297, CSSPropertyCx },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str298, CSSPropertyWebkitMinLogicalWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str299, CSSPropertyWebkitBoxAlign },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str300, CSSPropertyWebkitTextStroke },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str301, CSSPropertyOffsetPosition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str302, CSSPropertyCy },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str303, CSSPropertyAliasWebkitBorderBottomRightRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str304, CSSPropertyClipPath },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str305, CSSPropertyWebkitMaskBoxImage },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str306, CSSPropertyTextDecoration },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str307, CSSPropertyZIndex },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str308, CSSPropertyBufferedRendering },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str309, CSSPropertyBorderStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str310, CSSPropertyFontWeight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str311, CSSPropertyAliasWebkitAnimationDelay },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str312, CSSPropertyMaxZoom },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str313, CSSPropertyBorderTopRightRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str314, CSSPropertyTransitionDelay },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str315, CSSPropertyWebkitBoxLines },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str316, CSSPropertyShapeOutside },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str317, CSSPropertyBorderBottomStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str318, CSSPropertyColumnWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str319, CSSPropertyOffsetDistance },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str320, CSSPropertyMaskType },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str321, CSSPropertyTextAlignLast },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str322, CSSPropertyAliasWebkitClipPath },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str323, CSSPropertyWebkitTextCombine },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str324, CSSPropertyWebkitBoxDirection },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str325, CSSPropertyScrollBehavior },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str326, CSSPropertyAliasWebkitBorderTopRightRadius },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str327, CSSPropertyAliasWebkitTransitionDelay },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str328, CSSPropertyWebkitBorderEndStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str329, CSSPropertyBoxSizing },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str330, CSSPropertyDisplay },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str331, CSSPropertyWebkitMaskRepeatX },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str332, CSSPropertyTextDecorationLine },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str333, CSSPropertyAliasWebkitShapeOutside },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str334, CSSPropertyWebkitBorderAfterWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str335, CSSPropertyAliasWebkitColumnWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str336, CSSPropertyVisibility },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str337, CSSPropertyOpacity },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str338, CSSPropertyWebkitBorderBeforeWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str339, CSSPropertyBorderLeftWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str340, CSSPropertyWebkitBoxDecorationBreak },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str341, CSSPropertyWebkitMaskRepeatY },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str342, CSSPropertyBorderTopStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str343, CSSPropertyOutlineOffset },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str344, CSSPropertyTouchAction },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str345, CSSPropertyWebkitMaskBoxImageRepeat },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str346, CSSPropertyListStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str347, CSSPropertyAnimationPlayState },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str348, CSSPropertyFontFeatureSettings },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str349, CSSPropertyAliasWebkitBoxSizing },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str350, CSSPropertyWebkitFontSmoothing },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str351, CSSPropertyWebkitBorderStartStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str352, CSSPropertyTransitionProperty },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str353, CSSPropertyListStyleImage },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str354, CSSPropertyWebkitMaskPositionX },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str355, CSSPropertyAliasWebkitOpacity },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str356, CSSPropertyWebkitBoxPack },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str357, CSSPropertyMaxInlineSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str358, CSSPropertyVectorEffect },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str359, CSSPropertyWebkitMaskPositionY },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str360, CSSPropertyBackgroundAttachment },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str361, CSSPropertyAliasWebkitAnimationPlayState },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str362, CSSPropertyAliasWebkitFontFeatureSettings },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str363, CSSPropertyAliasEpubTextOrientation },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str364, CSSPropertyTextDecorationSkip },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str365, CSSPropertyAliasWebkitTransitionProperty },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str366, CSSPropertyStrokeOpacity },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str367, CSSPropertyBaselineShift },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str368, CSSPropertyWebkitTextStrokeColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str369, CSSPropertyFontStretch },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str370, CSSPropertyTableLayout },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str371, CSSPropertyTextDecorationColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str372, CSSPropertyHeight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str373, CSSPropertyWebkitBorderHorizontalSpacing },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str374, CSSPropertyMinHeight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str375, CSSPropertyStopOpacity },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str376, CSSPropertyBorderRightWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str377, CSSPropertyOutlineStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str378, CSSPropertyWebkitMaskBoxImageSlice },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str379, CSSPropertyFlex },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str380, CSSPropertyWebkitMaskBoxImageOutset },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str381, CSSPropertyWebkitBoxOrdinalGroup },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str382, CSSPropertyListStylePosition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str383, CSSPropertyWebkitRubyPosition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str384, CSSPropertyEmptyCells },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str385, CSSPropertyFlexGrow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str386, CSSPropertyTextUnderlinePosition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str387, CSSPropertyTextTransform },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str388, CSSPropertyLineHeight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str389, CSSPropertyMaxBlockSize },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str390, CSSPropertyAliasEpubTextCombine },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str391, CSSPropertyOverflowAnchor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str392, CSSPropertyColumnRuleWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str393, CSSPropertyAliasWebkitFlex },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str394, CSSPropertyBackgroundRepeatX },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str395, CSSPropertyAliasWebkitFlexGrow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str396, CSSPropertyTextSizeAdjust },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str397, CSSPropertyBackgroundRepeatY },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str398, CSSPropertyWebkitTransformOriginX },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str399, CSSPropertyAliasWebkitColumnRuleWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str400, CSSPropertyFontStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str401, CSSPropertyFlexWrap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str402, CSSPropertySnapHeight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str403, CSSPropertyOverflowX },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str404, CSSPropertyWebkitPerspectiveOriginX },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str405, CSSPropertyWebkitTransformOriginY },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str406, CSSPropertyBackgroundPositionX },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str407, CSSPropertyTextOverflow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str408, CSSPropertyAliasWebkitTextSizeAdjust },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str409, CSSPropertyFlexBasis },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str410, CSSPropertyOverflowY },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str411, CSSPropertyWebkitPerspectiveOriginY },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str412, CSSPropertyWebkitMaskBoxImageSource },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str413, CSSPropertyBackgroundPositionY },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str414, CSSPropertyAliasWebkitFlexWrap },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str415, CSSPropertyFlexDirection },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str416, CSSPropertyScrollSnapType },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str417, CSSPropertyTransformStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str418, CSSPropertyMaskSourceType },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str419, CSSPropertyWebkitBorderAfterStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str420, CSSPropertyAliasWebkitFlexBasis },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str421, CSSPropertyMaxWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str422, CSSPropertyWebkitBorderBeforeStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str423, CSSPropertyBorderLeftStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str424, CSSPropertyFontDisplay },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str425, CSSPropertyScrollSnapPointsX },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str426, CSSPropertyWebkitBoxReflect },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str427, CSSPropertyAliasWebkitFlexDirection },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str428, CSSPropertyAliasWebkitTransformStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str429, CSSPropertyScrollSnapPointsY },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str430, CSSPropertyTextShadow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str431, CSSPropertyBoxShadow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str432, CSSPropertyOffsetPath },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str433, CSSPropertyFloodOpacity },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str434, CSSPropertyWebkitLogicalHeight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str435, CSSPropertyWebkitUserModify },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str436, CSSPropertyAliasWebkitBoxShadow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str437, CSSPropertyWebkitMinLogicalHeight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str438, CSSPropertyJustifyItems },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str439, CSSPropertyOffsetAnchor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str440, CSSPropertyStrokeDashoffset },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str441, CSSPropertyTextAnchor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str442, CSSPropertyWebkitTextStrokeWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str443, CSSPropertyAliasEpubTextTransform },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str444, CSSPropertyFillOpacity },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str445, CSSPropertyWebkitTextFillColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str446, CSSPropertyWebkitMaskBoxImageWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str447, CSSPropertyBorderRightStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str448, CSSPropertyStrokeDasharray },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str449, CSSPropertyJustifyContent },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str450, CSSPropertyColumnRuleStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str451, CSSPropertyFontFamily },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str452, CSSPropertyAliasWebkitJustifyContent },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str453, CSSPropertyWebkitTextEmphasis },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str454, CSSPropertyFlexFlow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str455, CSSPropertyAliasWebkitColumnRuleStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str456, CSSPropertyAliasWebkitFlexFlow },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str457, CSSPropertyWebkitMaxLogicalWidth },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str458, CSSPropertyBackfaceVisibility },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str459, CSSPropertyAliasWebkitBackfaceVisibility },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str460, CSSPropertyWebkitTextEmphasisPosition },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str461, CSSPropertyTextCombineUpright },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str462, CSSPropertyWebkitTextEmphasisColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str463, CSSPropertyWebkitHighlight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str464, CSSPropertyAliasEpubTextEmphasis },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str465, CSSPropertyFlexShrink },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str466, CSSPropertyTextDecorationStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str467, CSSPropertyJustifySelf },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str468, CSSPropertyAliasWebkitFlexShrink },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str469, CSSPropertyWebkitTextDecorationsInEffect },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str470, CSSPropertyMaxHeight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str471, CSSPropertyListStyleType },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str472, CSSPropertyShapeImageThreshold },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str473, CSSPropertyWebkitTextSecurity },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str474, CSSPropertyWebkitBoxFlex },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str475, CSSPropertyAliasWebkitShapeImageThreshold },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str476, CSSPropertyAliasEpubTextEmphasisColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str477, CSSPropertyHyphens },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str478, CSSPropertyWebkitTapHighlightColor },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str479, CSSPropertyTextJustify },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str480, CSSPropertyWebkitMaxLogicalHeight },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str481, CSSPropertyWebkitBoxFlexGroup },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str482, CSSPropertyWebkitTextEmphasisStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str483, CSSPropertyAliasEpubTextEmphasisStyle },
    { (int)(long)&((struct stringpool_t*)0)->stringpool_str484, CSSPropertyWebkitHyphenateCharacter }
};

static const short lookup[] = {
    -1, -1, -1, 0, 1, -1, -1, -1, -1, -1,
    -1, -1, -1, 2, -1, -1, 3, -1, -1, 4,
    -1, 5, 6, -1, -1, 7, 8, 9, -1, -1,
    10, -1, 11, -1, 12, -1, -1, -1, -1, 13,
    -1, 14, -1, -1, -1, 15, -1, 16, -1, 17,
    18, 19, 20, -1, -1, 21, 22, -1, 23, -1,
    -1, 24, 25, -1, -1, -1, -1, -1, -1, -1,
    26, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    27, -1, -1, -1, -1, -1, 28, -1, -1, 29,
    30, -1, 31, -1, -1, 32, -1, -1, 33, -1,
    34, 35, 36, -1, 37, 38, 39, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 40, -1, 41,
    -1, -1, -1, 42, 43, -1, 44, 45, 46, -1,
    47, -1, 48, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 49, -1, 50, 51, -1, -1,
    -1, -1, 52, -1, 53, 54, 55, 56, -1, 57,
    -1, -1, 58, -1, 59, -1, -1, -1, 60, 61,
    -1, -1, -1, 62, 63, 64, 65, -1, -1, -1,
    -1, -1, 66, -1, 67, -1, -1, -1, 68, -1,
    69, 70, -1, -1, -1, -1, -1, -1, 71, -1,
    -1, -1, -1, 72, -1, 73, -1, 74, -1, -1,
    75, -1, -1, -1, -1, 76, -1, -1, 77, -1,
    -1, -1, 78, -1, -1, -1, -1, -1, -1, -1,
    79, 80, -1, -1, -1, 81, -1, -1, -1, -1,
    -1, -1, -1, -1, 82, -1, -1, -1, -1, 83,
    84, -1, -1, -1, -1, 85, -1, -1, 86, -1,
    87, 88, -1, 89, 90, -1, -1, 91, -1, -1,
    -1, 92, -1, -1, -1, -1, 93, -1, -1, -1,
    94, -1, -1, -1, 95, -1, -1, -1, 96, -1,
    97, -1, 98, 99, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 100, -1, -1, -1, -1, 101,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, 102,
    103, -1, 104, -1, -1, 105, -1, -1, -1, -1,
    106, 107, -1, 108, 109, -1, -1, 110, 111, 112,
    -1, -1, 113, -1, -1, -1, -1, -1, 114, 115,
    -1, -1, -1, 116, -1, -1, 117, 118, -1, -1,
    -1, -1, -1, 119, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 120, -1, -1, 121, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, 122, -1,
    123, -1, -1, -1, 124, -1, 125, 126, -1, 127,
    -1, -1, -1, 128, -1, -1, 129, -1, -1, -1,
    130, -1, -1, -1, -1, -1, -1, -1, 131, -1,
    132, -1, -1, 133, -1, 134, -1, -1, -1, -1,
    -1, -1, -1, 135, 136, -1, -1, -1, -1, 137,
    -1, -1, -1, 138, 139, 140, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    141, -1, -1, -1, 142, 143, -1, 144, -1, -1,
    145, -1, -1, -1, -1, 146, -1, 147, 148, -1,
    149, -1, -1, -1, 150, -1, 151, -1, 152, 153,
    154, -1, 155, -1, -1, -1, 156, 157, 158, -1,
    -1, 159, -1, -1, 160, -1, 161, -1, -1, 162,
    -1, 163, 164, 165, 166, -1, -1, 167, -1, -1,
    -1, 168, -1, 169, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 170, -1, 171, 172, 173,
    -1, -1, 174, -1, 175, 176, 177, -1, -1, -1,
    178, -1, -1, -1, 179, -1, -1, 180, -1, -1,
    -1, -1, -1, 181, -1, -1, -1, 182, -1, 183,
    -1, 184, -1, 185, -1, -1, -1, 186, -1, 187,
    -1, 188, -1, -1, -1, -1, -1, 189, -1, -1,
    -1, -1, 190, -1, -1, -1, 191, 192, 193, -1,
    -1, -1, 194, -1, 195, -1, 196, -1, 197, -1,
    -1, 198, -1, -1, -1, -1, -1, -1, 199, 200,
    -1, -1, -1, -1, -1, 201, -1, -1, -1, -1,
    -1, -1, 202, -1, 203, 204, -1, -1, -1, -1,
    -1, -1, -1, -1, 205, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, 206, -1, -1, -1,
    -1, -1, 207, -1, -1, 208, 209, -1, 210, 211,
    212, -1, -1, 213, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 214, -1, -1, 215, -1, -1, -1,
    -1, 216, -1, 217, 218, 219, 220, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 221, -1, -1,
    222, -1, -1, -1, -1, -1, -1, -1, 223, -1,
    -1, 224, -1, 225, 226, -1, 227, -1, -1, -1,
    -1, -1, -1, -1, 228, -1, -1, 229, -1, -1,
    -1, -1, -1, -1, 230, 231, 232, 233, -1, 234,
    235, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    236, -1, -1, 237, -1, -1, -1, -1, -1, -1,
    -1, 238, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 239, -1, -1, -1, -1, 240, -1, -1, -1,
    241, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    242, 243, -1, 244, -1, -1, -1, 245, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 246, -1, -1, 247, -1,
    -1, 248, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 249, -1, -1, 250, -1, -1, -1, -1, -1,
    251, 252, 253, -1, -1, -1, -1, 254, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 255, -1, -1, -1, 256,
    -1, -1, -1, -1, 257, 258, -1, 259, 260, -1,
    -1, -1, -1, -1, -1, 261, -1, -1, -1, 262,
    -1, 263, -1, 264, -1, 265, 266, 267, -1, -1,
    -1, -1, -1, 268, -1, 269, 270, 271, -1, -1,
    -1, 272, -1, -1, 273, -1, -1, -1, -1, -1,
    274, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 275, 276, 277, -1, -1, -1, 278,
    279, -1, 280, -1, -1, 281, 282, -1, 283, -1,
    -1, 284, 285, -1, -1, 286, 287, -1, -1, -1,
    288, 289, -1, -1, 290, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, 291, -1,
    -1, -1, -1, -1, -1, 292, -1, -1, -1, -1,
    -1, 293, -1, -1, -1, -1, -1, -1, -1, -1,
    294, -1, -1, -1, -1, -1, 295, -1, -1, -1,
    296, -1, -1, -1, 297, 298, -1, 299, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    300, -1, -1, -1, -1, -1, -1, -1, 301, -1,
    -1, -1, -1, 302, -1, 303, -1, -1, -1, -1,
    304, -1, -1, 305, -1, 306, 307, -1, -1, 308,
    309, 310, -1, -1, 311, 312, 313, -1, 314, -1,
    -1, -1, -1, -1, -1, 315, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, 316, -1,
    317, -1, 318, -1, 319, -1, 320, -1, -1, -1,
    -1, -1, -1, 321, 322, -1, -1, 323, 324, -1,
    -1, -1, -1, 325, -1, -1, -1, -1, -1, -1,
    326, -1, 327, -1, -1, -1, -1, 328, -1, 329,
    -1, -1, -1, 330, 331, -1, -1, -1, 332, -1,
    -1, -1, 333, -1, -1, 334, 335, -1, -1, -1,
    -1, 336, 337, 338, -1, 339, -1, -1, -1, -1,
    340, -1, -1, 341, -1, 342, 343, 344, 345, -1,
    -1, -1, -1, -1, 346, -1, -1, 347, -1, 348,
    -1, -1, -1, 349, -1, 350, -1, -1, -1, -1,
    -1, -1, 351, 352, -1, -1, 353, -1, 354, -1,
    -1, -1, -1, -1, -1, -1, 355, -1, -1, 356,
    357, -1, -1, 358, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 359, -1, 360,
    -1, 361, -1, 362, -1, -1, -1, -1, -1, -1,
    -1, -1, 363, -1, -1, 364, -1, 365, -1, -1,
    -1, -1, -1, -1, -1, 366, -1, -1, -1, -1,
    -1, -1, 367, 368, -1, -1, -1, -1, -1, 369,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 370, -1, -1, 371, -1,
    372, -1, -1, -1, -1, -1, -1, -1, -1, 373,
    -1, -1, -1, -1, -1, 374, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, 375,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 376, -1, -1, -1, 377,
    -1, -1, -1, -1, -1, 378, -1, 379, 380, -1,
    381, -1, -1, 382, -1, -1, 383, -1, -1, -1,
    -1, 384, -1, 385, -1, -1, 386, -1, -1, -1,
    -1, -1, 387, 388, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 389, -1, 390, -1, 391, -1, -1,
    392, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 393, -1, -1, -1, 394, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 395, -1, -1,
    396, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 397, -1, -1, -1, 398, -1,
    -1, -1, -1, -1, 399, -1, -1, -1, -1, -1,
    -1, -1, -1, 400, -1, -1, -1, 401, 402, -1,
    -1, -1, -1, -1, 403, 404, -1, 405, -1, 406,
    -1, -1, -1, 407, 408, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    409, -1, -1, 410, 411, 412, -1, -1, 413, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 414, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 415, 416, -1, -1, -1,
    -1, 417, -1, -1, -1, -1, -1, -1, 418, 419,
    -1, -1, -1, -1, 420, 421, -1, 422, -1, 423,
    -1, -1, -1, -1, 424, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, 425, -1,
    -1, -1, -1, -1, -1, 426, -1, -1, -1, 427,
    -1, -1, -1, -1, -1, 428, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 429, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 430, -1, -1,
    431, -1, -1, -1, -1, -1, -1, -1, -1, 432,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 433, -1, -1, -1, -1,
    -1, -1, 434, -1, -1, -1, -1, -1, -1, -1,
    -1, 435, -1, -1, 436, -1, -1, 437, -1, -1,
    -1, -1, -1, -1, 438, -1, -1, -1, -1, 439,
    -1, -1, -1, -1, -1, -1, 440, -1, -1, -1,
    -1, -1, -1, 441, -1, -1, -1, -1, -1, -1,
    -1, 442, -1, -1, 443, -1, -1, -1, -1, 444,
    -1, -1, -1, -1, -1, -1, -1, 445, -1, -1,
    -1, -1, -1, -1, 446, -1, -1, -1, -1, 447,
    -1, -1, -1, -1, 448, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 449, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 450, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 451, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, 452,
    453, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 454, 455, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 456, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 457, -1, 458,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 459, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, 460,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, 461, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 462, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, 463, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, 464, -1,
    -1, 465, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    466, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, 467, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 468, -1, -1, -1, -1,
    469, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 470, -1, -1,
    -1, -1, 471, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 472, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 473, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    474, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 475, -1, -1, -1, -1,
    -1, 476, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 477, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 478, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    479, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, 480,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, 481, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 482, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 483, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 484
};

const struct Property*
CSSPropertyNamesHash::findPropertyImpl(register const char* str, register unsigned int len)
{
    if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH) {
        register int key = property_hash_function(str, len);

        if (key <= MAX_HASH_VALUE && key >= 0) {
            register int index = lookup[key];

            if (index >= 0) {
                register const char* s = property_word_list[index].nameOffset + stringpool;

                if (*str == *s && !strncmp(str + 1, s + 1, len - 1) && s[len] == '\0')
                    return &property_word_list[index];
            }
        }
    }
    return 0;
}

const Property* findProperty(register const char* str, register unsigned int len)
{
    return CSSPropertyNamesHash::findPropertyImpl(str, len);
}

const char* getPropertyName(CSSPropertyID id)
{
    DCHECK(isCSSPropertyIDWithName(id));
    int index = id - firstCSSProperty;
    return propertyNameStringsPool + propertyNameStringsOffsets[index];
}

const AtomicString& getPropertyNameAtomicString(CSSPropertyID id)
{
    DCHECK(isCSSPropertyIDWithName(id));
    int index = id - firstCSSProperty;
    static AtomicString* propertyStrings = new AtomicString[lastUnresolvedCSSProperty]; // Intentionally never destroyed.
    AtomicString& propertyString = propertyStrings[index];
    if (propertyString.isNull())
        propertyString = AtomicString(propertyNameStringsPool + propertyNameStringsOffsets[index]);
    return propertyString;
}

String getPropertyNameString(CSSPropertyID id)
{
    // We share the StringImpl with the AtomicStrings.
    return getPropertyNameAtomicString(id).getString();
}

String getJSPropertyName(CSSPropertyID id)
{
    char result[maxCSSPropertyNameLength + 1];
    const char* cssPropertyName = getPropertyName(id);
    const char* propertyNamePointer = cssPropertyName;
    if (!propertyNamePointer)
        return emptyString();

    char* resultPointer = result;
    while (char character = *propertyNamePointer++) {
        if (character == '-') {
            char nextCharacter = *propertyNamePointer++;
            if (!nextCharacter)
                break;
            character = (propertyNamePointer - 2 != cssPropertyName) ? toASCIIUpper(nextCharacter) : nextCharacter;
        }
        *resultPointer++ = character;
    }
    *resultPointer = '\0';
    return String(result);
}

CSSPropertyID cssPropertyID(const String& string)
{
    return resolveCSSPropertyID(unresolvedCSSPropertyID(string));
}

} // namespace blink
