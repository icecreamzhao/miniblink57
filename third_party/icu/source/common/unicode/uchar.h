/*
**********************************************************************
*   Copyright (C) 1997-2014, International Business Machines
*   Corporation and others.  All Rights Reserved.
**********************************************************************
*
* File UCHAR.H
*
* Modification History:
*
*   Date        Name        Description
*   04/02/97    aliu        Creation.
*   03/29/99    helena      Updated for C APIs.
*   4/15/99     Madhu       Updated for C Implementation and Javadoc
*   5/20/99     Madhu       Added the function u_getVersion()
*   8/19/1999   srl         Upgraded scripts to Unicode 3.0
*   8/27/1999   schererm    UCharDirection constants: U_...
*   11/11/1999  weiv        added u_isalnum(), cleaned comments
*   01/11/2000  helena      Renamed u_getVersion to u_getUnicodeVersion().
******************************************************************************
*/

#ifndef UCHAR_H
#define UCHAR_H

#include "umachine.h"

int8_t u_charType(UChar32 c);

/** The lowest Unicode code point value. Code points are non-negative. @stable ICU 2.0 */
#define UCHAR_MIN_VALUE 0

/**
* The highest Unicode code point value (scalar value) according to
* The Unicode Standard. This is a 21-bit value (20.1 bits, rounded up).
* For a single character, UChar32 is a simple type that can hold any code point value.
*
* @see UChar32
* @stable ICU 2.0
*/
#define UCHAR_MAX_VALUE 0x10ffff

/**
* Get a single-bit bit set (a flag) from a bit number 0..31.
* @stable ICU 2.1
*/
#define U_MASK(x) ((uint32_t)1 << (x))

/* constants and macros for access to the data ------------------------------ */

/* getting a uint32_t properties word from the data */
#define GET_PROPS(c, result) ((result) = UTRIE2_GET16(&propsTrie, c));

#define U_GET_GC_MASK(c) U_MASK(u_charType(c))

/**
* Data for enumerated Unicode general category types.
* See http://www.unicode.org/Public/UNIDATA/UnicodeData.html .
* @stable ICU 2.0
*/
typedef enum UCharCategory {
    /*
    * Note: UCharCategory constants and their API comments are parsed by preparseucd.py.
    * It matches pairs of lines like
    *     / ** <Unicode 2-letter General_Category value> comment... * /
    *     U_<[A-Z_]+> = <integer>,
    */

    /** Non-category for unassigned and non-character code points. @stable ICU 2.0 */
    U_UNASSIGNED = 0,
    /** Cn "Other, Not Assigned (no characters in [UnicodeData.txt] have this property)" (same as U_UNASSIGNED!) @stable ICU 2.0 */
    U_GENERAL_OTHER_TYPES = 0,
    /** Lu @stable ICU 2.0 */
    U_UPPERCASE_LETTER = 1,
    /** Ll @stable ICU 2.0 */
    U_LOWERCASE_LETTER = 2,
    /** Lt @stable ICU 2.0 */
    U_TITLECASE_LETTER = 3,
    /** Lm @stable ICU 2.0 */
    U_MODIFIER_LETTER = 4,
    /** Lo @stable ICU 2.0 */
    U_OTHER_LETTER = 5,
    /** Mn @stable ICU 2.0 */
    U_NON_SPACING_MARK = 6,
    /** Me @stable ICU 2.0 */
    U_ENCLOSING_MARK = 7,
    /** Mc @stable ICU 2.0 */
    U_COMBINING_SPACING_MARK = 8,
    /** Nd @stable ICU 2.0 */
    U_DECIMAL_DIGIT_NUMBER = 9,
    /** Nl @stable ICU 2.0 */
    U_LETTER_NUMBER = 10,
    /** No @stable ICU 2.0 */
    U_OTHER_NUMBER = 11,
    /** Zs @stable ICU 2.0 */
    U_SPACE_SEPARATOR = 12,
    /** Zl @stable ICU 2.0 */
    U_LINE_SEPARATOR = 13,
    /** Zp @stable ICU 2.0 */
    U_PARAGRAPH_SEPARATOR = 14,
    /** Cc @stable ICU 2.0 */
    U_CONTROL_CHAR = 15,
    /** Cf @stable ICU 2.0 */
    U_FORMAT_CHAR = 16,
    /** Co @stable ICU 2.0 */
    U_PRIVATE_USE_CHAR = 17,
    /** Cs @stable ICU 2.0 */
    U_SURROGATE = 18,
    /** Pd @stable ICU 2.0 */
    U_DASH_PUNCTUATION = 19,
    /** Ps @stable ICU 2.0 */
    U_START_PUNCTUATION = 20,
    /** Pe @stable ICU 2.0 */
    U_END_PUNCTUATION = 21,
    /** Pc @stable ICU 2.0 */
    U_CONNECTOR_PUNCTUATION = 22,
    /** Po @stable ICU 2.0 */
    U_OTHER_PUNCTUATION = 23,
    /** Sm @stable ICU 2.0 */
    U_MATH_SYMBOL = 24,
    /** Sc @stable ICU 2.0 */
    U_CURRENCY_SYMBOL = 25,
    /** Sk @stable ICU 2.0 */
    U_MODIFIER_SYMBOL = 26,
    /** So @stable ICU 2.0 */
    U_OTHER_SYMBOL = 27,
    /** Pi @stable ICU 2.0 */
    U_INITIAL_PUNCTUATION = 28,
    /** Pf @stable ICU 2.0 */
    U_FINAL_PUNCTUATION = 29,
    /** One higher than the last enum UCharCategory constant. @stable ICU 2.0 */
    U_CHAR_CATEGORY_COUNT
} UCharCategory;

#define U_GC_MN_MASK U_MASK(U_NON_SPACING_MARK)
#define U_GC_ME_MASK U_MASK(U_ENCLOSING_MARK)
#define U_GC_MC_MASK U_MASK(U_COMBINING_SPACING_MARK)

/** Mask constant for multiple UCharCategory bits (M Marks). @stable ICU 2.1 */
#define U_GC_M_MASK (U_GC_MN_MASK | U_GC_ME_MASK | U_GC_MC_MASK)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_LM_MASK U_MASK(U_MODIFIER_LETTER)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_SK_MASK U_MASK(U_MODIFIER_SYMBOL)


#define U_GC_CN_MASK    U_MASK(U_GENERAL_OTHER_TYPES)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_LU_MASK    U_MASK(U_UPPERCASE_LETTER)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_LL_MASK    U_MASK(U_LOWERCASE_LETTER)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_LT_MASK    U_MASK(U_TITLECASE_LETTER)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_LM_MASK    U_MASK(U_MODIFIER_LETTER)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_LO_MASK    U_MASK(U_OTHER_LETTER)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_MN_MASK    U_MASK(U_NON_SPACING_MARK)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_ME_MASK    U_MASK(U_ENCLOSING_MARK)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_MC_MASK    U_MASK(U_COMBINING_SPACING_MARK)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_ND_MASK    U_MASK(U_DECIMAL_DIGIT_NUMBER)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_NL_MASK    U_MASK(U_LETTER_NUMBER)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_NO_MASK    U_MASK(U_OTHER_NUMBER)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_ZS_MASK    U_MASK(U_SPACE_SEPARATOR)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_ZL_MASK    U_MASK(U_LINE_SEPARATOR)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_ZP_MASK    U_MASK(U_PARAGRAPH_SEPARATOR)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_CC_MASK    U_MASK(U_CONTROL_CHAR)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_CF_MASK    U_MASK(U_FORMAT_CHAR)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_CO_MASK    U_MASK(U_PRIVATE_USE_CHAR)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_CS_MASK    U_MASK(U_SURROGATE)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_PD_MASK    U_MASK(U_DASH_PUNCTUATION)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_PS_MASK    U_MASK(U_START_PUNCTUATION)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_PE_MASK    U_MASK(U_END_PUNCTUATION)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_PC_MASK    U_MASK(U_CONNECTOR_PUNCTUATION)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_PO_MASK    U_MASK(U_OTHER_PUNCTUATION)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_SM_MASK    U_MASK(U_MATH_SYMBOL)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_SC_MASK    U_MASK(U_CURRENCY_SYMBOL)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_SK_MASK    U_MASK(U_MODIFIER_SYMBOL)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_SO_MASK    U_MASK(U_OTHER_SYMBOL)

/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_PI_MASK    U_MASK(U_INITIAL_PUNCTUATION)
/** Mask constant for a UCharCategory. @stable ICU 2.1 */
#define U_GC_PF_MASK    U_MASK(U_FINAL_PUNCTUATION)


/** Mask constant for multiple UCharCategory bits (L Letters). @stable ICU 2.1 */
#define U_GC_L_MASK \
            (U_GC_LU_MASK|U_GC_LL_MASK|U_GC_LT_MASK|U_GC_LM_MASK|U_GC_LO_MASK)

/** Mask constant for multiple UCharCategory bits (N Numbers). @stable ICU 2.1 */
#define U_GC_N_MASK (U_GC_ND_MASK|U_GC_NL_MASK|U_GC_NO_MASK)

/**
* Line Break constants.
*
* @see UCHAR_LINE_BREAK
* @stable ICU 2.2
*/
typedef enum ULineBreak {
    /*
  * Note: ULineBreak constants are parsed by preparseucd.py.
  * It matches lines like
  *     U_LB_<Unicode Line_Break value name>
  */

    U_LB_UNKNOWN = 0, /*[XX]*/
    U_LB_AMBIGUOUS = 1, /*[AI]*/
    U_LB_ALPHABETIC = 2, /*[AL]*/
    U_LB_BREAK_BOTH = 3, /*[B2]*/
    U_LB_BREAK_AFTER = 4, /*[BA]*/
    U_LB_BREAK_BEFORE = 5, /*[BB]*/
    U_LB_MANDATORY_BREAK = 6, /*[BK]*/
    U_LB_CONTINGENT_BREAK = 7, /*[CB]*/
    U_LB_CLOSE_PUNCTUATION = 8, /*[CL]*/
    U_LB_COMBINING_MARK = 9, /*[CM]*/
    U_LB_CARRIAGE_RETURN = 10, /*[CR]*/
    U_LB_EXCLAMATION = 11, /*[EX]*/
    U_LB_GLUE = 12, /*[GL]*/
    U_LB_HYPHEN = 13, /*[HY]*/
    U_LB_IDEOGRAPHIC = 14, /*[ID]*/
    /** Renamed from the misspelled "inseperable" in Unicode 4.0.1/ICU 3.0 @stable ICU 3.0 */
    U_LB_INSEPARABLE = 15, /*[IN]*/
    U_LB_INSEPERABLE = U_LB_INSEPARABLE,
    U_LB_INFIX_NUMERIC = 16, /*[IS]*/
    U_LB_LINE_FEED = 17, /*[LF]*/
    U_LB_NONSTARTER = 18, /*[NS]*/
    U_LB_NUMERIC = 19, /*[NU]*/
    U_LB_OPEN_PUNCTUATION = 20, /*[OP]*/
    U_LB_POSTFIX_NUMERIC = 21, /*[PO]*/
    U_LB_PREFIX_NUMERIC = 22, /*[PR]*/
    U_LB_QUOTATION = 23, /*[QU]*/
    U_LB_COMPLEX_CONTEXT = 24, /*[SA]*/
    U_LB_SURROGATE = 25, /*[SG]*/
    U_LB_SPACE = 26, /*[SP]*/
    U_LB_BREAK_SYMBOLS = 27, /*[SY]*/
    U_LB_ZWSPACE = 28, /*[ZW]*/
    /** @stable ICU 2.6 */
    U_LB_NEXT_LINE = 29,
    /*[NL]*/ /* from here on: new in Unicode 4/ICU 2.6 */
    /** @stable ICU 2.6 */
    U_LB_WORD_JOINER = 30, /*[WJ]*/
    /** @stable ICU 3.4 */
    U_LB_H2 = 31,
    /*[H2]*/ /* from here on: new in Unicode 4.1/ICU 3.4 */
    /** @stable ICU 3.4 */
    U_LB_H3 = 32, /*[H3]*/
    /** @stable ICU 3.4 */
    U_LB_JL = 33, /*[JL]*/
    /** @stable ICU 3.4 */
    U_LB_JT = 34, /*[JT]*/
    /** @stable ICU 3.4 */
    U_LB_JV = 35, /*[JV]*/
    /** @stable ICU 4.4 */
    U_LB_CLOSE_PARENTHESIS = 36,
    /*[CP]*/ /* new in Unicode 5.2/ICU 4.4 */
    /** @stable ICU 49 */
    U_LB_CONDITIONAL_JAPANESE_STARTER = 37,
    /*[CJ]*/ /* new in Unicode 6.1/ICU 49 */
    /** @stable ICU 49 */
    U_LB_HEBREW_LETTER = 38,
    /*[HL]*/ /* new in Unicode 6.1/ICU 49 */
    /** @stable ICU 50 */
    U_LB_REGIONAL_INDICATOR = 39,
    /*[RI]*/ /* new in Unicode 6.2/ICU 50 */
    /** @stable ICU 58 */
    U_LB_E_BASE = 40,
    /*[EB]*/ /* from here on: new in Unicode 9.0/ICU 58 */
    /** @stable ICU 58 */
    U_LB_E_MODIFIER = 41, /*[EM]*/
    /** @stable ICU 58 */
    U_LB_ZWJ = 42, /*[ZWJ]*/
#ifndef U_HIDE_DEPRECATED_API
    /**
                               * One more than the highest normal ULineBreak value.
                               * The highest value is available via u_getIntPropertyMaxValue(UCHAR_LINE_BREAK).
                               *
                               * @deprecated ICU 58 The numeric value may change over time, see ICU ticket #12420.
                               */
    U_LB_COUNT = 43
#endif // U_HIDE_DEPRECATED_API
} ULineBreak;

/**
* Append a code point to a string, overwriting 1 or 2 code units.
* The offset points to the current end of the string contents
* and is advanced (post-increment).
* "Safe" macro, checks for a valid code point.
* If a surrogate pair is written, checks for sufficient space in the string.
* If the code point is not valid or a trail surrogate does not fit,
* then isError is set to TRUE.
*
* @param s const UChar * string buffer
* @param i string offset, must be i<capacity
* @param capacity size of the string buffer
* @param c code point to append
* @param isError output UBool set to TRUE if an error occurs, otherwise not modified
* @see U16_APPEND_UNSAFE
* @stable ICU 2.4
*/
#define U16_APPEND(s, i, capacity, c, isError)                          \
    {                                                                   \
        if ((uint32_t)(c) <= 0xffff) {                                  \
            (s)[(i)++] = (uint16_t)(c);                                 \
        } else if ((uint32_t)(c) <= 0x10ffff && (i) + 1 < (capacity)) { \
            (s)[(i)++] = (uint16_t)(((c) >> 10) + 0xd7c0);              \
            (s)[(i)++] = (uint16_t)(((c)&0x3ff) | 0xdc00);              \
        } else /* c>0x10ffff or not enough space */ {                   \
            (isError) = TRUE;                                           \
        }                                                               \
    }

#endif // UCHAR_H