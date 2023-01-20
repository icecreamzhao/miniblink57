/*
 * Copyright (C) 2005, 2006, 2007 Apple Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "platform/text/StringTruncator.h"

#include "platform/fonts/Font.h"
#include "platform/text/TextBreakIterator.h"
#include "platform/text/TextRun.h"
#include "wtf/Assertions.h"
#include "wtf/text/CharacterNames.h"

namespace blink {

#define STRING_BUFFER_SIZE 2048

<<<<<<< HEAD
typedef unsigned TruncationFunction(const String&,
    unsigned length,
    unsigned keepCount,
    UChar* buffer);

static inline int textBreakAtOrPreceding(
    const NonSharedCharacterBreakIterator& it,
    int offset)
=======
typedef unsigned TruncationFunction(const String&, unsigned length, unsigned keepCount, UChar* buffer);

static inline int textBreakAtOrPreceding(const NonSharedCharacterBreakIterator& it, int offset)
>>>>>>> miniblink49
{
    if (it.isBreak(offset))
        return offset;

    int result = it.preceding(offset);
    return result == TextBreakDone ? 0 : result;
}

<<<<<<< HEAD
static inline int boundedTextBreakFollowing(
    const NonSharedCharacterBreakIterator& it,
    int offset,
    int length)
=======
static inline int boundedTextBreakFollowing(const NonSharedCharacterBreakIterator& it, int offset, int length)
>>>>>>> miniblink49
{
    int result = it.following(offset);
    return result == TextBreakDone ? length : result;
}

<<<<<<< HEAD
static unsigned centerTruncateToBuffer(const String& string,
    unsigned length,
    unsigned keepCount,
    UChar* buffer)
=======
static unsigned centerTruncateToBuffer(const String& string, unsigned length, unsigned keepCount, UChar* buffer)
>>>>>>> miniblink49
{
    ASSERT(keepCount < length);
    ASSERT(keepCount < STRING_BUFFER_SIZE);

    unsigned omitStart = (keepCount + 1) / 2;
    NonSharedCharacterBreakIterator it(string);
<<<<<<< HEAD
    unsigned omitEnd = boundedTextBreakFollowing(
        it, omitStart + (length - keepCount) - 1, length);
=======
    unsigned omitEnd = boundedTextBreakFollowing(it, omitStart + (length - keepCount) - 1, length);
>>>>>>> miniblink49
    omitStart = textBreakAtOrPreceding(it, omitStart);

    unsigned truncatedLength = omitStart + 1 + (length - omitEnd);
    ASSERT(truncatedLength <= length);

    string.copyTo(buffer, 0, omitStart);
    buffer[omitStart] = horizontalEllipsisCharacter;
    string.copyTo(&buffer[omitStart + 1], omitEnd, length - omitEnd);

    return truncatedLength;
}

<<<<<<< HEAD
static unsigned rightTruncateToBuffer(const String& string,
    unsigned length,
    unsigned keepCount,
    UChar* buffer)
=======
static unsigned rightTruncateToBuffer(const String& string, unsigned length, unsigned keepCount, UChar* buffer)
>>>>>>> miniblink49
{
    ASSERT(keepCount < length);
    ASSERT(keepCount < STRING_BUFFER_SIZE);

    NonSharedCharacterBreakIterator it(string);
    unsigned keepLength = textBreakAtOrPreceding(it, keepCount);
    unsigned truncatedLength = keepLength + 1;

    string.copyTo(buffer, 0, keepLength);
    buffer[keepLength] = horizontalEllipsisCharacter;

    return truncatedLength;
}

static float stringWidth(const Font& renderer, const String& string)
{
    TextRun run(string);
    return renderer.width(run);
}

<<<<<<< HEAD
static float stringWidth(const Font& renderer,
    const UChar* characters,
    unsigned length)
=======
static float stringWidth(const Font& renderer, const UChar* characters, unsigned length)
>>>>>>> miniblink49
{
    TextRun run(characters, length);
    return renderer.width(run);
}

<<<<<<< HEAD
static String truncateString(const String& string,
    float maxWidth,
    const Font& font,
    TruncationFunction truncateToBuffer)
=======
static String truncateString(const String& string, float maxWidth, const Font& font, TruncationFunction truncateToBuffer)
>>>>>>> miniblink49
{
    if (string.isEmpty())
        return string;

    ASSERT(maxWidth >= 0);

    float currentEllipsisWidth = stringWidth(font, &horizontalEllipsisCharacter, 1);

    UChar stringBuffer[STRING_BUFFER_SIZE];
    unsigned truncatedLength;
    unsigned keepCount;
    unsigned length = string.length();

    if (length > STRING_BUFFER_SIZE) {
        keepCount = STRING_BUFFER_SIZE - 1; // need 1 character for the ellipsis
        truncatedLength = centerTruncateToBuffer(string, length, keepCount, stringBuffer);
    } else {
        keepCount = length;
        string.copyTo(stringBuffer, 0, length);
        truncatedLength = length;
    }

    float width = stringWidth(font, stringBuffer, truncatedLength);
    if (width <= maxWidth)
        return string;

    unsigned keepCountForLargestKnownToFit = 0;
    float widthForLargestKnownToFit = currentEllipsisWidth;

    unsigned keepCountForSmallestKnownToNotFit = keepCount;
    float widthForSmallestKnownToNotFit = width;

    if (currentEllipsisWidth >= maxWidth) {
        keepCountForLargestKnownToFit = 1;
        keepCountForSmallestKnownToNotFit = 2;
    }

    while (keepCountForLargestKnownToFit + 1 < keepCountForSmallestKnownToNotFit) {
        ASSERT(widthForLargestKnownToFit <= maxWidth);
        ASSERT(widthForSmallestKnownToNotFit > maxWidth);

<<<<<<< HEAD
        float ratio = (keepCountForSmallestKnownToNotFit - keepCountForLargestKnownToFit) / (widthForSmallestKnownToNotFit - widthForLargestKnownToFit);
=======
        float ratio = (keepCountForSmallestKnownToNotFit - keepCountForLargestKnownToFit)
            / (widthForSmallestKnownToNotFit - widthForLargestKnownToFit);
>>>>>>> miniblink49
        keepCount = static_cast<unsigned>(maxWidth * ratio);

        if (keepCount <= keepCountForLargestKnownToFit) {
            keepCount = keepCountForLargestKnownToFit + 1;
        } else if (keepCount >= keepCountForSmallestKnownToNotFit) {
            keepCount = keepCountForSmallestKnownToNotFit - 1;
        }

        ASSERT(keepCount < length);
        ASSERT(keepCount > 0);
        ASSERT(keepCount < keepCountForSmallestKnownToNotFit);
        ASSERT(keepCount > keepCountForLargestKnownToFit);

        truncatedLength = truncateToBuffer(string, length, keepCount, stringBuffer);

        width = stringWidth(font, stringBuffer, truncatedLength);
        if (width <= maxWidth) {
            keepCountForLargestKnownToFit = keepCount;
            widthForLargestKnownToFit = width;
        } else {
            keepCountForSmallestKnownToNotFit = keepCount;
            widthForSmallestKnownToNotFit = width;
        }
    }

    if (!keepCountForLargestKnownToFit)
        keepCountForLargestKnownToFit = 1;

    if (keepCount != keepCountForLargestKnownToFit) {
        keepCount = keepCountForLargestKnownToFit;
        truncatedLength = truncateToBuffer(string, length, keepCount, stringBuffer);
    }

    return String(stringBuffer, truncatedLength);
}

<<<<<<< HEAD
String StringTruncator::centerTruncate(const String& string,
    float maxWidth,
    const Font& font)
=======
String StringTruncator::centerTruncate(const String& string, float maxWidth, const Font& font)
>>>>>>> miniblink49
{
    return truncateString(string, maxWidth, font, centerTruncateToBuffer);
}

<<<<<<< HEAD
String StringTruncator::rightTruncate(const String& string,
    float maxWidth,
    const Font& font)
=======
String StringTruncator::rightTruncate(const String& string, float maxWidth, const Font& font)
>>>>>>> miniblink49
{
    return truncateString(string, maxWidth, font, rightTruncateToBuffer);
}

float StringTruncator::width(const String& string, const Font& font)
{
    return stringWidth(font, string);
}

} // namespace blink
