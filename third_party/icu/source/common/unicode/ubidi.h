// Copyright (C) 2016 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html
/*
******************************************************************************
*
*   Copyright (C) 1999-2013, International Business Machines
*   Corporation and others.  All Rights Reserved.
*
******************************************************************************
*   file name:  ubidi.h
*   encoding:   US-ASCII
*   tab size:   8 (not used)
*   indentation:4
*
*   created on: 1999jul27
*   created by: Markus W. Scherer, updated by Matitiahu Allouche
*/

#ifndef UBIDI_H
#define UBIDI_H

typedef uint8_t UBiDiLevel;

enum UBiDiDirection {
    /** Left-to-right text. This is a 0 value.
  * <ul>
  * <li>As return value for <code>ubidi_getDirection()</code>, it means
  *     that the source string contains no right-to-left characters, or
  *     that the source string is empty and the paragraph level is even.
  * <li> As return value for <code>ubidi_getBaseDirection()</code>, it
  *      means that the first strong character of the source string has
  *      a left-to-right direction.
  * </ul>
  * @stable ICU 2.0
  */
    UBIDI_LTR,
    /** Right-to-left text. This is a 1 value.
  * <ul>
  * <li>As return value for <code>ubidi_getDirection()</code>, it means
  *     that the source string contains no left-to-right characters, or
  *     that the source string is empty and the paragraph level is odd.
  * <li> As return value for <code>ubidi_getBaseDirection()</code>, it
  *      means that the first strong character of the source string has
  *      a right-to-left direction.
  * </ul>
  * @stable ICU 2.0
  */
    UBIDI_RTL,
    /** Mixed-directional text.
  * <p>As return value for <code>ubidi_getDirection()</code>, it means
  *    that the source string contains both left-to-right and
  *    right-to-left characters.
  * @stable ICU 2.0
  */
    UBIDI_MIXED,
    /** No strongly directional text.
  * <p>As return value for <code>ubidi_getBaseDirection()</code>, it means
  *    that the source string is missing or empty, or contains neither left-to-right
  *    nor right-to-left characters.
  * @stable ICU 4.6
  */
    UBIDI_NEUTRAL
};

/** @stable ICU 2.0 */
typedef enum UBiDiDirection UBiDiDirection;

/**
* Forward declaration of the <code>UBiDi</code> structure for the declaration of
* the API functions. Its fields are implementation-specific.<p>
* This structure holds information about a paragraph (or multiple paragraphs)
* of text with Bidi-algorithm-related details, or about one line of
* such a paragraph.<p>
* Reordering can be done on a line, or on one or more paragraphs which are
* then interpreted each as one single line.
* @stable ICU 2.0
*/
struct UBiDi;

/** @stable ICU 2.0 */
typedef struct UBiDi UBiDi;

#endif
