// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/css/parser/CSSTokenizer.h"

namespace blink {
#include "core/CSSTokenizerCodepoints.cpp"
}

#include "core/css/parser/CSSParserIdioms.h"
#include "core/css/parser/CSSParserObserverWrapper.h"
#include "core/css/parser/CSSParserTokenRange.h"
#include "core/html/parser/HTMLParserIdioms.h"
#include "wtf/text/CharacterNames.h"

namespace blink {

CSSTokenizer::CSSTokenizer(const String& string)
    : m_input(string)
{
    // According to the spec, we should perform preprocessing here.
    // See: http://dev.w3.org/csswg/css-syntax/#input-preprocessing
    //
    // However, we can skip this step since:
    // * We're using HTML spaces (which accept \r and \f as a valid white space)
    // * Do not count white spaces
    // * CSSTokenizerInputStream::nextInputChar() replaces NULLs for replacement
    //   characters

    if (string.isEmpty())
        return;

    // To avoid resizing we err on the side of reserving too much space.
    // Most strings we tokenize have about 3.5 to 5 characters per token.
    m_tokens.reserveInitialCapacity(string.length() / 3);

    while (true) {
        CSSParserToken token = nextToken();
        if (token.type() == CommentToken)
            continue;
        if (token.type() == EOFToken)
            return;
        m_tokens.push_back(token);
    }
}

CSSTokenizer::CSSTokenizer(const String& string,
    CSSParserObserverWrapper& wrapper)
    : m_input(string)
{
    if (string.isEmpty())
        return;

    unsigned offset = 0;
    while (true) {
        CSSParserToken token = nextToken();
        if (token.type() == EOFToken)
            break;
        if (token.type() == CommentToken) {
            wrapper.addComment(offset, m_input.offset(), m_tokens.size());
        } else {
            m_tokens.push_back(token);
            wrapper.addToken(offset);
        }
        offset = m_input.offset();
    }

    wrapper.addToken(offset);
    wrapper.finalizeConstruction(m_tokens.begin());
}

CSSParserTokenRange CSSTokenizer::tokenRange()
{
    return m_tokens;
}

unsigned CSSTokenizer::tokenCount()
{
    return m_tokens.size();
}

static bool isNewLine(UChar cc)
{
    // We check \r and \f here, since we have no preprocessing stage
    return (cc == '\r' || cc == '\n' || cc == '\f');
}

// http://dev.w3.org/csswg/css-syntax/#check-if-two-code-points-are-a-valid-escape
static bool twoCharsAreValidEscape(UChar first, UChar second)
{
    return first == '\\' && !isNewLine(second);
}

void CSSTokenizer::reconsume(UChar c)
{
    m_input.pushBack(c);
}

UChar CSSTokenizer::consume()
{
    UChar current = m_input.nextInputChar();
    m_input.advance();
    return current;
}

CSSParserToken CSSTokenizer::whiteSpace(UChar cc)
{
    m_input.advanceUntilNonWhitespace();
    return CSSParserToken(WhitespaceToken);
}

CSSParserToken CSSTokenizer::blockStart(CSSParserTokenType type)
{
    m_blockStack.push_back(type);
    return CSSParserToken(type, CSSParserToken::BlockStart);
}

CSSParserToken CSSTokenizer::blockStart(CSSParserTokenType blockType,
    CSSParserTokenType type,
    StringView name)
{
    m_blockStack.push_back(blockType);
    return CSSParserToken(type, name, CSSParserToken::BlockStart);
}

CSSParserToken CSSTokenizer::blockEnd(CSSParserTokenType type,
    CSSParserTokenType startType)
{
    if (!m_blockStack.isEmpty() && m_blockStack.back() == startType) {
        m_blockStack.pop_back();
        return CSSParserToken(type, CSSParserToken::BlockEnd);
    }
    return CSSParserToken(type);
}

CSSParserToken CSSTokenizer::leftParenthesis(UChar cc)
{
    return blockStart(LeftParenthesisToken);
}

CSSParserToken CSSTokenizer::rightParenthesis(UChar cc)
{
    return blockEnd(RightParenthesisToken, LeftParenthesisToken);
}

CSSParserToken CSSTokenizer::leftBracket(UChar cc)
{
    return blockStart(LeftBracketToken);
}

CSSParserToken CSSTokenizer::rightBracket(UChar cc)
{
    return blockEnd(RightBracketToken, LeftBracketToken);
}

CSSParserToken CSSTokenizer::leftBrace(UChar cc)
{
    return blockStart(LeftBraceToken);
}

CSSParserToken CSSTokenizer::rightBrace(UChar cc)
{
    return blockEnd(RightBraceToken, LeftBraceToken);
}

CSSParserToken CSSTokenizer::plusOrFullStop(UChar cc)
{
    if (nextCharsAreNumber(cc)) {
        reconsume(cc);
        return consumeNumericToken();
    }
    return CSSParserToken(DelimiterToken, cc);
}

CSSParserToken CSSTokenizer::asterisk(UChar cc)
{
    ASSERT(cc == '*');
    if (consumeIfNext('='))
        return CSSParserToken(SubstringMatchToken);
    return CSSParserToken(DelimiterToken, '*');
}

CSSParserToken CSSTokenizer::lessThan(UChar cc)
{
    ASSERT(cc == '<');
    if (m_input.peekWithoutReplacement(0) == '!' && m_input.peekWithoutReplacement(1) == '-' && m_input.peekWithoutReplacement(2) == '-') {
        m_input.advance(3);
        return CSSParserToken(CDOToken);
    }
    return CSSParserToken(DelimiterToken, '<');
}

CSSParserToken CSSTokenizer::comma(UChar cc)
{
    return CSSParserToken(CommaToken);
}

CSSParserToken CSSTokenizer::hyphenMinus(UChar cc)
{
    if (nextCharsAreNumber(cc)) {
        reconsume(cc);
        return consumeNumericToken();
    }
    if (m_input.peekWithoutReplacement(0) == '-' && m_input.peekWithoutReplacement(1) == '>') {
        m_input.advance(2);
        return CSSParserToken(CDCToken);
    }
    if (nextCharsAreIdentifier(cc)) {
        reconsume(cc);
        return consumeIdentLikeToken();
    }
    return CSSParserToken(DelimiterToken, cc);
}

CSSParserToken CSSTokenizer::solidus(UChar cc)
{
    if (consumeIfNext('*')) {
        // These get ignored, but we need a value to return.
        consumeUntilCommentEndFound();
        return CSSParserToken(CommentToken);
    }

    return CSSParserToken(DelimiterToken, cc);
}

CSSParserToken CSSTokenizer::colon(UChar cc)
{
    return CSSParserToken(ColonToken);
}

CSSParserToken CSSTokenizer::semiColon(UChar cc)
{
    return CSSParserToken(SemicolonToken);
}

CSSParserToken CSSTokenizer::hash(UChar cc)
{
    UChar nextChar = m_input.peekWithoutReplacement(0);
    if (isNameCodePoint(nextChar) || twoCharsAreValidEscape(nextChar, m_input.peekWithoutReplacement(1))) {
        HashTokenType type = nextCharsAreIdentifier() ? HashTokenId : HashTokenUnrestricted;
        return CSSParserToken(type, consumeName());
    }

    return CSSParserToken(DelimiterToken, cc);
}

CSSParserToken CSSTokenizer::circumflexAccent(UChar cc)
{
    ASSERT(cc == '^');
    if (consumeIfNext('='))
        return CSSParserToken(PrefixMatchToken);
    return CSSParserToken(DelimiterToken, '^');
}

CSSParserToken CSSTokenizer::dollarSign(UChar cc)
{
    ASSERT(cc == '$');
    if (consumeIfNext('='))
        return CSSParserToken(SuffixMatchToken);
    return CSSParserToken(DelimiterToken, '$');
}

CSSParserToken CSSTokenizer::verticalLine(UChar cc)
{
    ASSERT(cc == '|');
    if (consumeIfNext('='))
        return CSSParserToken(DashMatchToken);
    if (consumeIfNext('|'))
        return CSSParserToken(ColumnToken);
    return CSSParserToken(DelimiterToken, '|');
}

CSSParserToken CSSTokenizer::tilde(UChar cc)
{
    ASSERT(cc == '~');
    if (consumeIfNext('='))
        return CSSParserToken(IncludeMatchToken);
    return CSSParserToken(DelimiterToken, '~');
}

CSSParserToken CSSTokenizer::commercialAt(UChar cc)
{
    ASSERT(cc == '@');
    if (nextCharsAreIdentifier())
        return CSSParserToken(AtKeywordToken, consumeName());
    return CSSParserToken(DelimiterToken, '@');
}

CSSParserToken CSSTokenizer::reverseSolidus(UChar cc)
{
    if (twoCharsAreValidEscape(cc, m_input.peekWithoutReplacement(0))) {
        reconsume(cc);
        return consumeIdentLikeToken();
    }
    return CSSParserToken(DelimiterToken, cc);
}

CSSParserToken CSSTokenizer::asciiDigit(UChar cc)
{
    reconsume(cc);
    return consumeNumericToken();
}

CSSParserToken CSSTokenizer::letterU(UChar cc)
{
    if (m_input.peekWithoutReplacement(0) == '+' && (isASCIIHexDigit(m_input.peekWithoutReplacement(1)) || m_input.peekWithoutReplacement(1) == '?')) {
        m_input.advance();
        return consumeUnicodeRange();
    }
    reconsume(cc);
    return consumeIdentLikeToken();
}

CSSParserToken CSSTokenizer::nameStart(UChar cc)
{
    reconsume(cc);
    return consumeIdentLikeToken();
}

CSSParserToken CSSTokenizer::stringStart(UChar cc)
{
    return consumeStringTokenUntil(cc);
}

CSSParserToken CSSTokenizer::endOfFile(UChar cc)
{
    return CSSParserToken(EOFToken);
}

CSSParserToken CSSTokenizer::nextToken()
{
    // Unlike the HTMLTokenizer, the CSS Syntax spec is written
    // as a stateless, (fixed-size) look-ahead tokenizer.
    // We could move to the stateful model and instead create
    // states for all the "next 3 codepoints are X" cases.
    // State-machine tokenizers are easier to write to handle
    // incremental tokenization of partial sources.
    // However, for now we follow the spec exactly.
    UChar cc = consume();
    CodePoint codePointFunc = 0;

    if (isASCII(cc)) {
        SECURITY_DCHECK(cc < codePointsNumber);
        codePointFunc = codePoints[cc];
    } else {
        codePointFunc = &CSSTokenizer::nameStart;
    }

    if (codePointFunc)
        return ((this)->*(codePointFunc))(cc);
    return CSSParserToken(DelimiterToken, cc);
}

// This method merges the following spec sections for efficiency
// http://www.w3.org/TR/css3-syntax/#consume-a-number
// http://www.w3.org/TR/css3-syntax/#convert-a-string-to-a-number
CSSParserToken CSSTokenizer::consumeNumber()
{
    ASSERT(nextCharsAreNumber());

    NumericValueType type = IntegerValueType;
    NumericSign sign = NoSign;
    unsigned numberLength = 0;

    UChar next = m_input.peekWithoutReplacement(0);
    if (next == '+') {
        ++numberLength;
        sign = PlusSign;
    } else if (next == '-') {
        ++numberLength;
        sign = MinusSign;
    }

    numberLength = m_input.skipWhilePredicate<isASCIIDigit>(numberLength);
    next = m_input.peekWithoutReplacement(numberLength);
    if (next == '.' && isASCIIDigit(m_input.peekWithoutReplacement(numberLength + 1))) {
        type = NumberValueType;
        numberLength = m_input.skipWhilePredicate<isASCIIDigit>(numberLength + 2);
        next = m_input.peekWithoutReplacement(numberLength);
    }

    if (next == 'E' || next == 'e') {
        next = m_input.peekWithoutReplacement(numberLength + 1);
        if (isASCIIDigit(next)) {
            type = NumberValueType;
            numberLength = m_input.skipWhilePredicate<isASCIIDigit>(numberLength + 1);
        } else if ((next == '+' || next == '-') && isASCIIDigit(m_input.peekWithoutReplacement(numberLength + 2))) {
            type = NumberValueType;
            numberLength = m_input.skipWhilePredicate<isASCIIDigit>(numberLength + 3);
        }
    }

    double value = m_input.getDouble(0, numberLength);
    m_input.advance(numberLength);

    return CSSParserToken(NumberToken, value, type, sign);
}

// http://www.w3.org/TR/css3-syntax/#consume-a-numeric-token
CSSParserToken CSSTokenizer::consumeNumericToken()
{
    CSSParserToken token = consumeNumber();
    if (nextCharsAreIdentifier())
        token.convertToDimensionWithUnit(consumeName());
    else if (consumeIfNext('%'))
        token.convertToPercentage();
    return token;
}

// http://dev.w3.org/csswg/css-syntax/#consume-ident-like-token
CSSParserToken CSSTokenizer::consumeIdentLikeToken()
{
    StringView name = consumeName();
    if (consumeIfNext('(')) {
        if (equalIgnoringASCIICase(name, "url")) {
            // The spec is slightly different so as to avoid dropping whitespace
            // tokens, but they wouldn't be used and this is easier.
            m_input.advanceUntilNonWhitespace();
            UChar next = m_input.peekWithoutReplacement(0);
            if (next != '"' && next != '\'')
                return consumeUrlToken();
        }
        return blockStart(LeftParenthesisToken, FunctionToken, name);
    }
    return CSSParserToken(IdentToken, name);
}

// http://dev.w3.org/csswg/css-syntax/#consume-a-string-token
CSSParserToken CSSTokenizer::consumeStringTokenUntil(UChar endingCodePoint)
{
    // Strings without escapes get handled without allocations
    for (unsigned size = 0;; size++) {
        UChar cc = m_input.peekWithoutReplacement(size);
        if (cc == endingCodePoint) {
            unsigned startOffset = m_input.offset();
            m_input.advance(size + 1);
            return CSSParserToken(StringToken, m_input.rangeAt(startOffset, size));
        }
        if (isNewLine(cc)) {
            m_input.advance(size);
            return CSSParserToken(BadStringToken);
        }
        if (cc == '\0' || cc == '\\')
            break;
    }

    StringBuilder output;
    while (true) {
        UChar cc = consume();
        if (cc == endingCodePoint || cc == kEndOfFileMarker)
            return CSSParserToken(StringToken, registerString(output.toString()));
        if (isNewLine(cc)) {
            reconsume(cc);
            return CSSParserToken(BadStringToken);
        }
        if (cc == '\\') {
            if (m_input.nextInputChar() == kEndOfFileMarker)
                continue;
            if (isNewLine(m_input.peekWithoutReplacement(0)))
                consumeSingleWhitespaceIfNext(); // This handles \r\n for us
            else
                output.append(consumeEscape());
        } else {
            output.append(cc);
        }
    }
}

CSSParserToken CSSTokenizer::consumeUnicodeRange()
{
    DCHECK(isASCIIHexDigit(m_input.peekWithoutReplacement(0)) || m_input.peekWithoutReplacement(0) == '?');
    int lengthRemaining = 6;
    UChar32 start = 0;

    while (lengthRemaining && isASCIIHexDigit(m_input.peekWithoutReplacement(0))) {
        start = start * 16 + toASCIIHexValue(consume());
        --lengthRemaining;
    }

    UChar32 end = start;
    if (lengthRemaining && consumeIfNext('?')) {
        do {
            start *= 16;
            end = end * 16 + 0xF;
            --lengthRemaining;
        } while (lengthRemaining && consumeIfNext('?'));
    } else if (m_input.peekWithoutReplacement(0) == '-' && isASCIIHexDigit(m_input.peekWithoutReplacement(1))) {
        m_input.advance();
        lengthRemaining = 6;
        end = 0;
        do {
            end = end * 16 + toASCIIHexValue(consume());
            --lengthRemaining;
        } while (lengthRemaining && isASCIIHexDigit(m_input.peekWithoutReplacement(0)));
    }

    return CSSParserToken(UnicodeRangeToken, start, end);
}

// http://dev.w3.org/csswg/css-syntax/#non-printable-code-point
static bool isNonPrintableCodePoint(UChar cc)
{
    return (cc >= '\0' && cc <= '\x8') || cc == '\xb' || (cc >= '\xe' && cc <= '\x1f') || cc == '\x7f';
}

// http://dev.w3.org/csswg/css-syntax/#consume-url-token
CSSParserToken CSSTokenizer::consumeUrlToken()
{
    m_input.advanceUntilNonWhitespace();

    // URL tokens without escapes get handled without allocations
    for (unsigned size = 0;; size++) {
        UChar cc = m_input.peekWithoutReplacement(size);
        if (cc == ')') {
            unsigned startOffset = m_input.offset();
            m_input.advance(size + 1);
            return CSSParserToken(UrlToken, m_input.rangeAt(startOffset, size));
        }
        if (cc <= ' ' || cc == '\\' || cc == '"' || cc == '\'' || cc == '(' || cc == '\x7f')
            break;
    }

    StringBuilder result;
    while (true) {
        UChar cc = consume();
        if (cc == ')' || cc == kEndOfFileMarker)
            return CSSParserToken(UrlToken, registerString(result.toString()));

        if (isHTMLSpace(cc)) {
            m_input.advanceUntilNonWhitespace();
            if (consumeIfNext(')') || m_input.nextInputChar() == kEndOfFileMarker)
                return CSSParserToken(UrlToken, registerString(result.toString()));
            break;
        }

        if (cc == '"' || cc == '\'' || cc == '(' || isNonPrintableCodePoint(cc))
            break;

        if (cc == '\\') {
            if (twoCharsAreValidEscape(cc, m_input.peekWithoutReplacement(0))) {
                result.append(consumeEscape());
                continue;
            }
            break;
        }

        result.append(cc);
    }

    consumeBadUrlRemnants();
    return CSSParserToken(BadUrlToken);
}

// http://dev.w3.org/csswg/css-syntax/#consume-the-remnants-of-a-bad-url
void CSSTokenizer::consumeBadUrlRemnants()
{
    while (true) {
        UChar cc = consume();
        if (cc == ')' || cc == kEndOfFileMarker)
            return;
        if (twoCharsAreValidEscape(cc, m_input.peekWithoutReplacement(0)))
            consumeEscape();
    }
}

void CSSTokenizer::consumeSingleWhitespaceIfNext()
{
    // We check for \r\n and HTML spaces since we don't do preprocessing
    UChar next = m_input.peekWithoutReplacement(0);
    if (next == '\r' && m_input.peekWithoutReplacement(1) == '\n')
        m_input.advance(2);
    else if (isHTMLSpace(next))
        m_input.advance();
}

void CSSTokenizer::consumeUntilCommentEndFound()
{
    UChar c = consume();
    while (true) {
        if (c == kEndOfFileMarker)
            return;
        if (c != '*') {
            c = consume();
            continue;
        }
        c = consume();
        if (c == '/')
            return;
    }
}

bool CSSTokenizer::consumeIfNext(UChar character)
{
    // Since we're not doing replacement we can't tell the difference from
    // a NUL in the middle and the kEndOfFileMarker, so character must not be
    // NUL.
    DCHECK(character);
    if (m_input.peekWithoutReplacement(0) == character) {
        m_input.advance();
        return true;
    }
    return false;
}

// http://www.w3.org/TR/css3-syntax/#consume-a-name
StringView CSSTokenizer::consumeName()
{
    // Names without escapes get handled without allocations
    for (unsigned size = 0;; ++size) {
        UChar cc = m_input.peekWithoutReplacement(size);
        if (isNameCodePoint(cc))
            continue;
        // peekWithoutReplacement will return NUL when we hit the end of the
        // input. In that case we want to still use the rangeAt() fast path
        // below.
        if (cc == '\0' && m_input.offset() + size < m_input.length())
            break;
        if (cc == '\\')
            break;
        unsigned startOffset = m_input.offset();
        m_input.advance(size);
        return m_input.rangeAt(startOffset, size);
    }

    StringBuilder result;
    while (true) {
        UChar cc = consume();
        if (isNameCodePoint(cc)) {
            result.append(cc);
            continue;
        }
        if (twoCharsAreValidEscape(cc, m_input.peekWithoutReplacement(0))) {
            result.append(consumeEscape());
            continue;
        }
        reconsume(cc);
        return registerString(result.toString());
    }
}

// http://dev.w3.org/csswg/css-syntax/#consume-an-escaped-code-point
UChar32 CSSTokenizer::consumeEscape()
{
    UChar cc = consume();
    ASSERT(!isNewLine(cc));
    if (isASCIIHexDigit(cc)) {
        unsigned consumedHexDigits = 1;
        StringBuilder hexChars;
        hexChars.append(cc);
        while (consumedHexDigits < 6 && isASCIIHexDigit(m_input.peekWithoutReplacement(0))) {
            cc = consume();
            hexChars.append(cc);
            consumedHexDigits++;
        };
        consumeSingleWhitespaceIfNext();
        bool ok = false;
        UChar32 codePoint = hexChars.toString().toUIntStrict(&ok, 16);
        ASSERT(ok);
        if (codePoint == 0 || (0xD800 <= codePoint && codePoint <= 0xDFFF) || codePoint > 0x10FFFF)
            return replacementCharacter;
        return codePoint;
    }

    if (cc == kEndOfFileMarker)
        return replacementCharacter;
    return cc;
}

bool CSSTokenizer::nextTwoCharsAreValidEscape()
{
    return twoCharsAreValidEscape(m_input.peekWithoutReplacement(0),
        m_input.peekWithoutReplacement(1));
}

// http://www.w3.org/TR/css3-syntax/#starts-with-a-number
bool CSSTokenizer::nextCharsAreNumber(UChar first)
{
    UChar second = m_input.peekWithoutReplacement(0);
    if (isASCIIDigit(first))
        return true;
    if (first == '+' || first == '-')
        return ((isASCIIDigit(second)) || (second == '.' && isASCIIDigit(m_input.peekWithoutReplacement(1))));
    if (first == '.')
        return (isASCIIDigit(second));
    return false;
}

bool CSSTokenizer::nextCharsAreNumber()
{
    UChar first = consume();
    bool areNumber = nextCharsAreNumber(first);
    reconsume(first);
    return areNumber;
}

// http://dev.w3.org/csswg/css-syntax/#would-start-an-identifier
bool CSSTokenizer::nextCharsAreIdentifier(UChar first)
{
    UChar second = m_input.peekWithoutReplacement(0);
    if (isNameStartCodePoint(first) || twoCharsAreValidEscape(first, second))
        return true;

    if (first == '-')
        return isNameStartCodePoint(second) || second == '-' || nextTwoCharsAreValidEscape();

    return false;
}

bool CSSTokenizer::nextCharsAreIdentifier()
{
    UChar first = consume();
    bool areIdentifier = nextCharsAreIdentifier(first);
    reconsume(first);
    return areIdentifier;
}

StringView CSSTokenizer::registerString(const String& string)
{
    m_stringPool.push_back(string);
    return string;
}

} // namespace blink
