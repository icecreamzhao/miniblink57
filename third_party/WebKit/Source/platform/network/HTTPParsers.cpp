/*
 * Copyright (C) 2006 Alexey Proskuryakov (ap@webkit.org)
 * Copyright (C) 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
 * Copyright (C) 2009 Torch Mobile Inc. http://www.torchmobile.com/
 * Copyright (C) 2009 Google Inc. All rights reserved.
 * Copyright (C) 2011 Apple Inc. All Rights Reserved.
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
#include "platform/network/HTTPParsers.h"

// #include "net/http/http_response_headers.h"
// #include "net/http/http_util.h"
#include "platform/json/JSONParser.h"
#include "platform/network/ResourceResponse.h"
#include "platform/weborigin/Suborigin.h"
#include "public/platform/WebString.h"
=======
#include "config.h"
#include "platform/network/HTTPParsers.h"

>>>>>>> miniblink49
#include "wtf/DateMath.h"
#include "wtf/MathExtras.h"
#include "wtf/text/CString.h"
#include "wtf/text/CharacterNames.h"
<<<<<<< HEAD
#include "wtf/text/ParsingUtilities.h"
#include "wtf/text/StringBuilder.h"
#include "wtf/text/StringUTF8Adaptor.h"
=======
#include "wtf/text/StringBuilder.h"
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

using namespace WTF;

<<<<<<< HEAD
String trimInputSample(const char* p, size_t len);

namespace blink {

namespace {

    const Vector<AtomicString>& replaceHeaders()
    {
        // The list of response headers that we do not copy from the original
        // response when generating a ResourceResponse for a MIME payload.
        // Note: this is called only on the main thread.
        DEFINE_STATIC_LOCAL(Vector<AtomicString>, headers,
            ({ "content-type", "content-length", "content-disposition",
                "content-range", "range", "set-cookie" }));
        return headers;
    }

    bool isWhitespace(UChar chr)
    {
        return (chr == ' ') || (chr == '\t');
    }

    // true if there is more to parse, after incrementing pos past whitespace.
    // Note: Might return pos == str.length()
    // if |matcher| is nullptr, isWhitespace() is used.
    inline bool skipWhiteSpace(const String& str,
        unsigned& pos,
        CharacterMatchFunctionPtr matcher = nullptr)
    {
        unsigned len = str.length();

        if (matcher) {
            while (pos < len && matcher(str[pos]))
                ++pos;
        } else {
            while (pos < len && isWhitespace(str[pos]))
                ++pos;
        }

        return pos < len;
    }

    // Returns true if the function can match the whole token (case insensitive)
    // incrementing pos on match, otherwise leaving pos unchanged.
    // Note: Might return pos == str.length()
    inline bool skipToken(const String& str, unsigned& pos, const char* token)
    {
        unsigned len = str.length();
        unsigned current = pos;

        while (current < len && *token) {
            if (toASCIILower(str[current]) != *token++)
                return false;
            ++current;
        }

        if (*token)
            return false;

        pos = current;
        return true;
    }

    // True if the expected equals sign is seen and there is more to follow.
    inline bool skipEquals(const String& str, unsigned& pos)
    {
        return skipWhiteSpace(str, pos) && str[pos++] == '=' && skipWhiteSpace(str, pos);
    }

    // True if a value present, incrementing pos to next space or semicolon, if any.
    // Note: might return pos == str.length().
    inline bool skipValue(const String& str, unsigned& pos)
    {
        unsigned start = pos;
        unsigned len = str.length();
        while (pos < len) {
            if (str[pos] == ' ' || str[pos] == '\t' || str[pos] == ';')
                break;
            ++pos;
        }
        return pos != start;
    }

    template <typename CharType>
    inline bool isASCIILowerAlphaOrDigit(CharType c)
    {
        return isASCIILower(c) || isASCIIDigit(c);
    }

    template <typename CharType>
    inline bool isASCIILowerAlphaOrDigitOrHyphen(CharType c)
    {
        return isASCIILowerAlphaOrDigit(c) || c == '-';
    }

    Suborigin::SuboriginPolicyOptions getSuboriginPolicyOptionFromString(
        const String& policyOptionName)
    {
        if (policyOptionName == "'unsafe-postmessage-send'")
            return Suborigin::SuboriginPolicyOptions::UnsafePostMessageSend;

        if (policyOptionName == "'unsafe-postmessage-receive'")
            return Suborigin::SuboriginPolicyOptions::UnsafePostMessageReceive;

        if (policyOptionName == "'unsafe-cookies'")
            return Suborigin::SuboriginPolicyOptions::UnsafeCookies;

        if (policyOptionName == "'unsafe-credentials'")
            return Suborigin::SuboriginPolicyOptions::UnsafeCredentials;

        return Suborigin::SuboriginPolicyOptions::None;
    }

    // suborigin-name = LOWERALPHA *( LOWERALPHA / DIGIT )
    //
    // Does not trim whitespace before or after the suborigin-name.
    const UChar* parseSuboriginName(const UChar* begin,
        const UChar* end,
        String& name,
        WTF::Vector<String>& messages)
    {
        // Parse the name of the suborigin (no spaces, single string)
        if (begin == end) {
            messages.push_back(String("No Suborigin name specified."));
            return nullptr;
        }

        const UChar* position = begin;

        if (!skipExactly<UChar, isASCIILower>(position, end)) {
            messages.push_back("Invalid character \'" + String(position, 1) + "\' in suborigin. First character must be a lower case "
                                                                              "alphabetic character.");
            return nullptr;
        }

        skipWhile<UChar, isASCIILowerAlphaOrDigit>(position, end);
        if (position != end && !isASCIISpace(*position)) {
            messages.push_back("Invalid character \'" + String(position, 1) + "\' in suborigin.");
            return nullptr;
        }

        size_t length = position - begin;
        name = String(begin, length).lower();
        return position;
    }

    const UChar* parseSuboriginPolicyOption(const UChar* begin,
        const UChar* end,
        String& option,
        WTF::Vector<String>& messages)
    {
        const UChar* position = begin;

        if (*position != '\'') {
            messages.push_back("Invalid character \'" + String(position, 1) + "\' in suborigin policy. Suborigin policy options must "
                                                                              "start and end with a single quote.");
            return nullptr;
        }
        position = position + 1;

        skipWhile<UChar, isASCIILowerAlphaOrDigitOrHyphen>(position, end);
        if (position == end || isASCIISpace(*position)) {
            messages.push_back(String("Expected \' to end policy option."));
            return nullptr;
        }

        if (*position != '\'') {
            messages.push_back("Invalid character \'" + String(position, 1) + "\' in suborigin policy.");
            return nullptr;
        }

        ASSERT(position > begin);
        size_t length = (position + 1) - begin;

        option = String(begin, length);
        return position + 1;
    }

} // namespace
=======
namespace blink {

static bool isWhitespace(UChar chr)
{
    return (chr == ' ') || (chr == '\t');
}

// true if there is more to parse, after incrementing pos past whitespace.
// Note: Might return pos == str.length()
static inline bool skipWhiteSpace(const String& str, unsigned& pos, bool fromHttpEquivMeta)
{
    unsigned len = str.length();

    if (fromHttpEquivMeta) {
        while (pos < len && str[pos] <= ' ')
            ++pos;
    } else {
        while (pos < len && isWhitespace(str[pos]))
            ++pos;
    }

    return pos < len;
}

// Returns true if the function can match the whole token (case insensitive)
// incrementing pos on match, otherwise leaving pos unchanged.
// Note: Might return pos == str.length()
static inline bool skipToken(const String& str, unsigned& pos, const char* token)
{
    unsigned len = str.length();
    unsigned current = pos;

    while (current < len && *token) {
        if (toASCIILower(str[current]) != *token++)
            return false;
        ++current;
    }

    if (*token)
        return false;

    pos = current;
    return true;
}

// True if the expected equals sign is seen and there is more to follow.
static inline bool skipEquals(const String& str, unsigned &pos)
{
    return skipWhiteSpace(str, pos, false) && str[pos++] == '=' && skipWhiteSpace(str, pos, false);
}

// True if a value present, incrementing pos to next space or semicolon, if any.
// Note: might return pos == str.length().
static inline bool skipValue(const String& str, unsigned& pos)
{
    unsigned start = pos;
    unsigned len = str.length();
    while (pos < len) {
        if (str[pos] == ' ' || str[pos] == '\t' || str[pos] == ';')
            break;
        ++pos;
    }
    return pos != start;
}
>>>>>>> miniblink49

bool isValidHTTPHeaderValue(const String& name)
{
    // FIXME: This should really match name against
    // field-value in section 4.2 of RFC 2616.

<<<<<<< HEAD
    return name.containsOnlyLatin1() && !name.contains('\r') && !name.contains('\n') && !name.contains('\0');
}

// See RFC 7230, Section 3.2.
// Checks whether |value| matches field-content in RFC 7230.
// link: http://tools.ietf.org/html/rfc7230#section-3.2
bool isValidHTTPFieldContentRFC7230(const String& value)
{
    if (value.isEmpty())
        return false;

    UChar firstCharacter = value[0];
    if (firstCharacter == ' ' || firstCharacter == '\t')
        return false;

    UChar lastCharacter = value[value.length() - 1];
    if (lastCharacter == ' ' || lastCharacter == '\t')
        return false;

    for (unsigned i = 0; i < value.length(); ++i) {
        UChar c = value[i];
        // TODO(mkwst): Extract this character class to a central location,
        // https://crbug.com/527324.
        if (c == 0x7F || c > 0xFF || (c < 0x20 && c != '\t'))
            return false;
    }

    return true;
}

bool IsTokenChar(char c)
{
    return !(c >= 0x7F || c <= 0x20 || c == '(' || c == ')' || c == '<' || c == '>' || c == '@' || c == ',' || c == ';' || c == ':' || c == '\\' || c == '"' || c == '/' || c == '[' || c == ']' || c == '?' || c == '=' || c == '{' || c == '}');
}

// See RFC 7230, Section 3.2.6.
=======
    return name.containsOnlyLatin1() && !name.contains('\r') && !name.contains('\n') && !name.contains(static_cast<UChar>('\0'));
}

// See RFC 2616, Section 2.2.
>>>>>>> miniblink49
bool isValidHTTPToken(const String& characters)
{
    if (characters.isEmpty())
        return false;
    for (unsigned i = 0; i < characters.length(); ++i) {
        UChar c = characters[i];
<<<<<<< HEAD
        if (c > 0x7F || !/*net::HttpUtil::*/ IsTokenChar(c))
            return false;
=======
        if (c <= 0x20 || c >= 0x7F
            || c == '(' || c == ')' || c == '<' || c == '>' || c == '@'
            || c == ',' || c == ';' || c == ':' || c == '\\' || c == '"'
            || c == '/' || c == '[' || c == ']' || c == '?' || c == '='
            || c == '{' || c == '}')
        return false;
>>>>>>> miniblink49
    }
    return true;
}

<<<<<<< HEAD
ContentDispositionType getContentDispositionType(
    const String& contentDisposition)
=======
static const size_t maxInputSampleSize = 128;
static String trimInputSample(const char* p, size_t length)
{
    if (length > maxInputSampleSize)
        return String(p, maxInputSampleSize) + horizontalEllipsisCharacter;
    return String(p, length);
}

ContentDispositionType contentDispositionType(const String& contentDisposition)
>>>>>>> miniblink49
{
    if (contentDisposition.isEmpty())
        return ContentDispositionNone;

    Vector<String> parameters;
    contentDisposition.split(';', parameters);

    if (parameters.isEmpty())
        return ContentDispositionNone;

    String dispositionType = parameters[0];
    dispositionType.stripWhiteSpace();

    if (equalIgnoringCase(dispositionType, "inline"))
        return ContentDispositionInline;

    // Some broken sites just send bogus headers like
    //
    //   Content-Disposition: ; filename="file"
    //   Content-Disposition: filename="file"
    //   Content-Disposition: name="file"
    //
    // without a disposition token... screen those out.
    if (!isValidHTTPToken(dispositionType))
        return ContentDispositionNone;

    // We have a content-disposition of "attachment" or unknown.
    // RFC 2183, section 2.8 says that an unknown disposition
    // value should be treated as "attachment"
    return ContentDispositionAttachment;
}

<<<<<<< HEAD
bool parseHTTPRefresh(const String& refresh,
    CharacterMatchFunctionPtr matcher,
    double& delay,
    String& url)
{
    unsigned len = refresh.length();
    unsigned pos = 0;
    matcher = matcher ? matcher : isWhitespace;

    if (!skipWhiteSpace(refresh, pos, matcher))
        return false;

    while (pos != len && refresh[pos] != ',' && refresh[pos] != ';' && !matcher(refresh[pos]))
=======
bool parseHTTPRefresh(const String& refresh, bool fromHttpEquivMeta, double& delay, String& url)
{
    unsigned len = refresh.length();
    unsigned pos = 0;

    if (!skipWhiteSpace(refresh, pos, fromHttpEquivMeta))
        return false;

    while (pos != len && refresh[pos] != ',' && refresh[pos] != ';')
>>>>>>> miniblink49
        ++pos;

    if (pos == len) { // no URL
        url = String();
        bool ok;
        delay = refresh.stripWhiteSpace().toDouble(&ok);
        return ok;
    } else {
        bool ok;
        delay = refresh.left(pos).stripWhiteSpace().toDouble(&ok);
        if (!ok)
            return false;

<<<<<<< HEAD
        skipWhiteSpace(refresh, pos, matcher);
        if (pos < len && (refresh[pos] == ',' || refresh[pos] == ';'))
            ++pos;
        skipWhiteSpace(refresh, pos, matcher);
        unsigned urlStartPos = pos;
        if (refresh.find("url", urlStartPos, TextCaseASCIIInsensitive) == urlStartPos) {
            urlStartPos += 3;
            skipWhiteSpace(refresh, urlStartPos, matcher);
            if (refresh[urlStartPos] == '=') {
                ++urlStartPos;
                skipWhiteSpace(refresh, urlStartPos, matcher);
=======
        ++pos;
        skipWhiteSpace(refresh, pos, fromHttpEquivMeta);
        unsigned urlStartPos = pos;
        if (refresh.find("url", urlStartPos, TextCaseInsensitive) == urlStartPos) {
            urlStartPos += 3;
            skipWhiteSpace(refresh, urlStartPos, fromHttpEquivMeta);
            if (refresh[urlStartPos] == '=') {
                ++urlStartPos;
                skipWhiteSpace(refresh, urlStartPos, fromHttpEquivMeta);
>>>>>>> miniblink49
            } else {
                urlStartPos = pos; // e.g. "Refresh: 0; url.html"
            }
        }

        unsigned urlEndPos = len;

        if (refresh[urlStartPos] == '"' || refresh[urlStartPos] == '\'') {
            UChar quotationMark = refresh[urlStartPos];
            urlStartPos++;
            while (urlEndPos > urlStartPos) {
                urlEndPos--;
                if (refresh[urlEndPos] == quotationMark)
                    break;
            }

            // https://bugs.webkit.org/show_bug.cgi?id=27868
<<<<<<< HEAD
            // Sometimes there is no closing quote for the end of the URL even though
            // there was an opening quote.  If we looped over the entire alleged URL
            // string back to the opening quote, just go ahead and use everything
=======
            // Sometimes there is no closing quote for the end of the URL even though there was an opening quote.
            // If we looped over the entire alleged URL string back to the opening quote, just go ahead and use everything
>>>>>>> miniblink49
            // after the opening quote instead.
            if (urlEndPos == urlStartPos)
                urlEndPos = len;
        }

<<<<<<< HEAD
        url = refresh.substring(urlStartPos, urlEndPos - urlStartPos)
                  .stripWhiteSpace();
=======
        url = refresh.substring(urlStartPos, urlEndPos - urlStartPos).stripWhiteSpace();
>>>>>>> miniblink49
        return true;
    }
}

double parseDate(const String& value)
{
    return parseDateFromNullTerminatedCharacters(value.utf8().data());
}

<<<<<<< HEAD
AtomicString extractMIMETypeFromMediaType(const AtomicString& mediaType)
{
    unsigned length = mediaType.length();

    unsigned pos = 0;

    while (pos < length) {
        UChar c = mediaType[pos];
        if (c != '\t' && c != ' ')
            break;
        ++pos;
    }

    if (pos == length)
        return mediaType;

    unsigned typeStart = pos;

    unsigned typeEnd = pos;
    while (pos < length) {
        UChar c = mediaType[pos];

        // While RFC 2616 does not allow it, other browsers allow multiple values in
        // the HTTP media type header field, Content-Type. In such cases, the media
        // type string passed here may contain the multiple values separated by
        // commas. For now, this code ignores text after the first comma, which
        // prevents it from simply failing to parse such types altogether.  Later
        // for better compatibility we could consider using the first or last valid
        // MIME type instead.
        // See https://bugs.webkit.org/show_bug.cgi?id=25352 for more discussion.
        if (c == ',' || c == ';')
            break;

        if (c != '\t' && c != ' ')
            typeEnd = pos + 1;

        ++pos;
    }

    return AtomicString(
        mediaType.getString().substring(typeStart, typeEnd - typeStart));
=======
// FIXME: This function doesn't comply with RFC 6266.
// For example, this function doesn't handle the interaction between " and ;
// that arises from quoted-string, nor does this function properly unquote
// attribute values. Further this function appears to process parameter names
// in a case-sensitive manner. (There are likely other bugs as well.)
String filenameFromHTTPContentDisposition(const String& value)
{
    Vector<String> keyValuePairs;
    value.split(';', keyValuePairs);

    unsigned length = keyValuePairs.size();
    for (unsigned i = 0; i < length; i++) {
        size_t valueStartPos = keyValuePairs[i].find('=');
        if (valueStartPos == kNotFound)
            continue;

        String key = keyValuePairs[i].left(valueStartPos).stripWhiteSpace();

        if (key.isEmpty() || key != "filename")
            continue;

        String value = keyValuePairs[i].substring(valueStartPos + 1).stripWhiteSpace();

        // Remove quotes if there are any
        if (value[0] == '\"')
            value = value.substring(1, value.length() - 2);

        return value;
    }

    return String();
}

AtomicString extractMIMETypeFromMediaType(const AtomicString& mediaType)
{
    StringBuilder mimeType;
    unsigned length = mediaType.length();
    mimeType.reserveCapacity(length);
    for (unsigned i = 0; i < length; i++) {
        UChar c = mediaType[i];

        if (c == ';')
            break;

        // While RFC 2616 does not allow it, other browsers allow multiple values in the HTTP media
        // type header field, Content-Type. In such cases, the media type string passed here may contain
        // the multiple values separated by commas. For now, this code ignores text after the first comma,
        // which prevents it from simply failing to parse such types altogether. Later for better
        // compatibility we could consider using the first or last valid MIME type instead.
        // See https://bugs.webkit.org/show_bug.cgi?id=25352 for more discussion.
        if (c == ',')
            break;

        // FIXME: The following is not correct. RFC 2616 allows linear white space before and
        // after the MIME type, but not within the MIME type itself. And linear white space
        // includes only a few specific ASCII characters; a small subset of isSpaceOrNewline.
        // See https://bugs.webkit.org/show_bug.cgi?id=8644 for a bug tracking part of this.
        if (isSpaceOrNewline(c))
            continue;

        mimeType.append(c);
    }

    if (mimeType.length() == length)
        return mediaType;
    return mimeType.toAtomicString();
>>>>>>> miniblink49
}

String extractCharsetFromMediaType(const String& mediaType)
{
    unsigned pos, len;
    findCharsetInMediaType(mediaType, pos, len);
    return mediaType.substring(pos, len);
}

<<<<<<< HEAD
void findCharsetInMediaType(const String& mediaType,
    unsigned& charsetPos,
    unsigned& charsetLen,
    unsigned start)
=======
void findCharsetInMediaType(const String& mediaType, unsigned& charsetPos, unsigned& charsetLen, unsigned start)
>>>>>>> miniblink49
{
    charsetPos = start;
    charsetLen = 0;

    size_t pos = start;
    unsigned length = mediaType.length();

    while (pos < length) {
<<<<<<< HEAD
        pos = mediaType.find("charset", pos, TextCaseASCIIInsensitive);
=======
        pos = mediaType.find("charset", pos, TextCaseInsensitive);
>>>>>>> miniblink49
        if (pos == kNotFound || !pos) {
            charsetLen = 0;
            return;
        }

        // is what we found a beginning of a word?
<<<<<<< HEAD
        if (mediaType[pos - 1] > ' ' && mediaType[pos - 1] != ';') {
=======
        if (mediaType[pos-1] > ' ' && mediaType[pos-1] != ';') {
>>>>>>> miniblink49
            pos += 7;
            continue;
        }

        pos += 7;

        // skip whitespace
        while (pos != length && mediaType[pos] <= ' ')
            ++pos;

<<<<<<< HEAD
        if (mediaType[pos++] != '=') // this "charset" substring wasn't a parameter
            // name, but there may be others
=======
        if (mediaType[pos++] != '=') // this "charset" substring wasn't a parameter name, but there may be others
>>>>>>> miniblink49
            continue;

        while (pos != length && (mediaType[pos] <= ' ' || mediaType[pos] == '"' || mediaType[pos] == '\''))
            ++pos;

<<<<<<< HEAD
        // we don't handle spaces within quoted parameter values, because charset
        // names cannot have any
=======
        // we don't handle spaces within quoted parameter values, because charset names cannot have any
>>>>>>> miniblink49
        unsigned endpos = pos;
        while (pos != length && mediaType[endpos] > ' ' && mediaType[endpos] != '"' && mediaType[endpos] != '\'' && mediaType[endpos] != ';')
            ++endpos;

        charsetPos = pos;
        charsetLen = endpos - pos;
        return;
    }
}

<<<<<<< HEAD
ReflectedXSSDisposition parseXSSProtectionHeader(const String& header,
    String& failureReason,
    unsigned& failurePosition,
    String& reportURL)
{
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidToggle, ("expected 0 or 1"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidSeparator,
        ("expected semicolon"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidEquals,
        ("expected equals sign"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidMode,
        ("invalid mode directive"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidReport,
        ("invalid report directive"));
    DEFINE_STATIC_LOCAL(String, failureReasonDuplicateMode,
        ("duplicate mode directive"));
    DEFINE_STATIC_LOCAL(String, failureReasonDuplicateReport,
        ("duplicate report directive"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidDirective,
        ("unrecognized directive"));

    unsigned pos = 0;

    if (!skipWhiteSpace(header, pos))
=======
ReflectedXSSDisposition parseXSSProtectionHeader(const String& header, String& failureReason, unsigned& failurePosition, String& reportURL)
{
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidToggle, ("expected 0 or 1"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidSeparator, ("expected semicolon"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidEquals, ("expected equals sign"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidMode, ("invalid mode directive"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidReport, ("invalid report directive"));
    DEFINE_STATIC_LOCAL(String, failureReasonDuplicateMode, ("duplicate mode directive"));
    DEFINE_STATIC_LOCAL(String, failureReasonDuplicateReport, ("duplicate report directive"));
    DEFINE_STATIC_LOCAL(String, failureReasonInvalidDirective, ("unrecognized directive"));

    unsigned pos = 0;

    if (!skipWhiteSpace(header, pos, false))
>>>>>>> miniblink49
        return ReflectedXSSUnset;

    if (header[pos] == '0')
        return AllowReflectedXSS;

    if (header[pos++] != '1') {
        failureReason = failureReasonInvalidToggle;
        return ReflectedXSSInvalid;
    }

    ReflectedXSSDisposition result = FilterReflectedXSS;
    bool modeDirectiveSeen = false;
    bool reportDirectiveSeen = false;

    while (1) {
<<<<<<< HEAD
        // At end of previous directive: consume whitespace, semicolon, and
        // whitespace.
        if (!skipWhiteSpace(header, pos))
=======
        // At end of previous directive: consume whitespace, semicolon, and whitespace.
        if (!skipWhiteSpace(header, pos, false))
>>>>>>> miniblink49
            return result;

        if (header[pos++] != ';') {
            failureReason = failureReasonInvalidSeparator;
            failurePosition = pos;
            return ReflectedXSSInvalid;
        }

<<<<<<< HEAD
        if (!skipWhiteSpace(header, pos))
=======
        if (!skipWhiteSpace(header, pos, false))
>>>>>>> miniblink49
            return result;

        // At start of next directive.
        if (skipToken(header, pos, "mode")) {
            if (modeDirectiveSeen) {
                failureReason = failureReasonDuplicateMode;
                failurePosition = pos;
                return ReflectedXSSInvalid;
            }
            modeDirectiveSeen = true;
            if (!skipEquals(header, pos)) {
                failureReason = failureReasonInvalidEquals;
                failurePosition = pos;
                return ReflectedXSSInvalid;
            }
            if (!skipToken(header, pos, "block")) {
                failureReason = failureReasonInvalidMode;
                failurePosition = pos;
                return ReflectedXSSInvalid;
            }
            result = BlockReflectedXSS;
        } else if (skipToken(header, pos, "report")) {
            if (reportDirectiveSeen) {
                failureReason = failureReasonDuplicateReport;
                failurePosition = pos;
                return ReflectedXSSInvalid;
            }
            reportDirectiveSeen = true;
            if (!skipEquals(header, pos)) {
                failureReason = failureReasonInvalidEquals;
                failurePosition = pos;
                return ReflectedXSSInvalid;
            }
            size_t startPos = pos;
            if (!skipValue(header, pos)) {
                failureReason = failureReasonInvalidReport;
                failurePosition = pos;
                return ReflectedXSSInvalid;
            }
            reportURL = header.substring(startPos, pos - startPos);
            failurePosition = startPos; // If later semantic check deems unacceptable.
        } else {
            failureReason = failureReasonInvalidDirective;
            failurePosition = pos;
            return ReflectedXSSInvalid;
        }
    }
}

<<<<<<< HEAD
ContentTypeOptionsDisposition parseContentTypeOptionsHeader(
    const String& header)
=======
ContentTypeOptionsDisposition parseContentTypeOptionsHeader(const String& header)
>>>>>>> miniblink49
{
    if (header.stripWhiteSpace().lower() == "nosniff")
        return ContentTypeOptionsNosniff;
    return ContentTypeOptionsNone;
}

<<<<<<< HEAD
static bool isCacheHeaderSeparator(UChar c)
{
    // See RFC 2616, Section 2.2
    switch (c) {
    case '(':
    case ')':
    case '<':
    case '>':
    case '@':
    case ',':
    case ';':
    case ':':
    case '\\':
    case '"':
    case '/':
    case '[':
    case ']':
    case '?':
    case '=':
    case '{':
    case '}':
    case ' ':
    case '\t':
        return true;
    default:
        return false;
    }
}

static bool isControlCharacter(UChar c)
{
    return c < ' ' || c == 127;
}

static inline String trimToNextSeparator(const String& str)
{
    return str.substring(0, str.find(isCacheHeaderSeparator));
}

static void parseCacheHeader(const String& header,
    Vector<std::pair<String, String>>& result)
{
    const String safeHeader = header.removeCharacters(isControlCharacter);
    unsigned max = safeHeader.length();
    for (unsigned pos = 0; pos < max; /* pos incremented in loop */) {
        size_t nextCommaPosition = safeHeader.find(',', pos);
        size_t nextEqualSignPosition = safeHeader.find('=', pos);
        if (nextEqualSignPosition != kNotFound && (nextEqualSignPosition < nextCommaPosition || nextCommaPosition == kNotFound)) {
            // Get directive name, parse right hand side of equal sign, then add to
            // map
            String directive = trimToNextSeparator(
                safeHeader.substring(pos, nextEqualSignPosition - pos)
                    .stripWhiteSpace());
            pos += nextEqualSignPosition - pos + 1;

            String value = safeHeader.substring(pos, max - pos).stripWhiteSpace();
            if (value[0] == '"') {
                // The value is a quoted string
                size_t nextDoubleQuotePosition = value.find('"', 1);
                if (nextDoubleQuotePosition != kNotFound) {
                    // Store the value as a quoted string without quotes
                    result.push_back(std::pair<String, String>(
                        directive, value.substring(1, nextDoubleQuotePosition - 1).stripWhiteSpace()));
                    pos += (safeHeader.find('"', pos) - pos) + nextDoubleQuotePosition + 1;
                    // Move past next comma, if there is one
                    size_t nextCommaPosition2 = safeHeader.find(',', pos);
                    if (nextCommaPosition2 != kNotFound)
                        pos += nextCommaPosition2 - pos + 1;
                    else
                        return; // Parse error if there is anything left with no comma
                } else {
                    // Parse error; just use the rest as the value
                    result.push_back(std::pair<String, String>(
                        directive,
                        trimToNextSeparator(
                            value.substring(1, value.length() - 1).stripWhiteSpace())));
                    return;
                }
            } else {
                // The value is a token until the next comma
                size_t nextCommaPosition2 = value.find(',');
                if (nextCommaPosition2 != kNotFound) {
                    // The value is delimited by the next comma
                    result.push_back(std::pair<String, String>(
                        directive,
                        trimToNextSeparator(
                            value.substring(0, nextCommaPosition2).stripWhiteSpace())));
                    pos += (safeHeader.find(',', pos) - pos) + 1;
                } else {
                    // The rest is the value; no change to value needed
                    result.push_back(
                        std::pair<String, String>(directive, trimToNextSeparator(value)));
                    return;
                }
            }
        } else if (nextCommaPosition != kNotFound && (nextCommaPosition < nextEqualSignPosition || nextEqualSignPosition == kNotFound)) {
            // Add directive to map with empty string as value
            result.push_back(std::pair<String, String>(
                trimToNextSeparator(safeHeader.substring(pos, nextCommaPosition - pos)
                                        .stripWhiteSpace()),
                ""));
            pos += nextCommaPosition - pos + 1;
        } else {
            // Add last directive to map with empty string as value
            result.push_back(std::pair<String, String>(
                trimToNextSeparator(
                    safeHeader.substring(pos, max - pos).stripWhiteSpace()),
                ""));
            return;
        }
    }
}

CacheControlHeader parseCacheControlDirectives(
    const AtomicString& cacheControlValue,
    const AtomicString& pragmaValue)
{
    CacheControlHeader cacheControlHeader;
    cacheControlHeader.parsed = true;
    cacheControlHeader.maxAge = std::numeric_limits<double>::quiet_NaN();
    cacheControlHeader.staleWhileRevalidate = std::numeric_limits<double>::quiet_NaN();

    static const char noCacheDirective[] = "no-cache";
    static const char noStoreDirective[] = "no-store";
    static const char mustRevalidateDirective[] = "must-revalidate";
    static const char maxAgeDirective[] = "max-age";
    static const char staleWhileRevalidateDirective[] = "stale-while-revalidate";

    if (!cacheControlValue.isEmpty()) {
        Vector<std::pair<String, String>> directives;
        parseCacheHeader(cacheControlValue, directives);

        size_t directivesSize = directives.size();
        for (size_t i = 0; i < directivesSize; ++i) {
            // RFC2616 14.9.1: A no-cache directive with a value is only meaningful
            // for proxy caches.  It should be ignored by a browser level cache.
            if (equalIgnoringCase(directives[i].first, noCacheDirective) && directives[i].second.isEmpty()) {
                cacheControlHeader.containsNoCache = true;
            } else if (equalIgnoringCase(directives[i].first, noStoreDirective)) {
                cacheControlHeader.containsNoStore = true;
            } else if (equalIgnoringCase(directives[i].first,
                           mustRevalidateDirective)) {
                cacheControlHeader.containsMustRevalidate = true;
            } else if (equalIgnoringCase(directives[i].first, maxAgeDirective)) {
                if (!std_isnan(cacheControlHeader.maxAge)) {
                    // First max-age directive wins if there are multiple ones.
                    continue;
                }
                bool ok;
                double maxAge = directives[i].second.toDouble(&ok);
                if (ok)
                    cacheControlHeader.maxAge = maxAge;
            } else if (equalIgnoringCase(directives[i].first,
                           staleWhileRevalidateDirective)) {
                if (!std_isnan(cacheControlHeader.staleWhileRevalidate)) {
                    // First stale-while-revalidate directive wins if there are multiple
                    // ones.
                    continue;
                }
                bool ok;
                double staleWhileRevalidate = directives[i].second.toDouble(&ok);
                if (ok)
                    cacheControlHeader.staleWhileRevalidate = staleWhileRevalidate;
            }
        }
    }

    if (!cacheControlHeader.containsNoCache) {
        // Handle Pragma: no-cache
        // This is deprecated and equivalent to Cache-control: no-cache
        // Don't bother tokenizing the value, it is not important
        cacheControlHeader.containsNoCache = pragmaValue.lower().contains(noCacheDirective);
    }
    return cacheControlHeader;
}

void parseCommaDelimitedHeader(const String& headerValue,
    CommaDelimitedHeaderSet& headerSet)
{
    Vector<String> results;
    headerValue.split(",", results);
    for (auto& value : results)
        headerSet.add(value.stripWhiteSpace(isWhitespace));
}

bool parseSuboriginHeader(const String& header,
    Suborigin* suborigin,
    WTF::Vector<String>& messages)
{
    Vector<String> headers;
    header.split(',', true, headers);

    if (headers.size() > 1)
        messages.push_back(
            "Multiple Suborigin headers found. Ignoring all but the first.");

    Vector<UChar> characters;
    headers[0].appendTo(characters);

    const UChar* position = characters.data();
    const UChar* end = position + characters.size();

    skipWhile<UChar, isASCIISpace>(position, end);

    String name;
    position = parseSuboriginName(position, end, name, messages);
    // For now it is appropriate to simply return false if the name is empty and
    // act as if the header doesn't exist. If suborigin policy options are created
    // that can apply to the empty suborigin, than this will have to change.
    if (!position || name.isEmpty())
        return false;

    suborigin->setName(name);

    while (position < end) {
        skipWhile<UChar, isASCIISpace>(position, end);
        if (position == end)
            return true;

        String optionName;
        position = parseSuboriginPolicyOption(position, end, optionName, messages);

        if (!position) {
            suborigin->clear();
            return false;
        }

        Suborigin::SuboriginPolicyOptions option = getSuboriginPolicyOptionFromString(optionName);
        if (option == Suborigin::SuboriginPolicyOptions::None)
            messages.push_back("Ignoring unknown suborigin policy option " + optionName + ".");
        else
            suborigin->addPolicyOption(option);
    }

    return true;
}

bool parseMultipartHeadersFromBody(const char* bytes,
    size_t size,
    ResourceResponse* response,
    size_t* end)
{
    DCHECK(isMainThread());
    DebugBreak();

    //   int headersEndPos =
    //        net::HttpUtil::LocateEndOfAdditionalHeaders(bytes, size, 0);
    //
    //   if (headersEndPos < 0)
    //     return false;
    //
    //   *end = headersEndPos;
    //
    //   // Eat headers and prepend a status line as is required by
    //   // HttpResponseHeaders.
    //   std::string headers("HTTP/1.1 200 OK\r\n");
    //   headers.append(bytes, headersEndPos);
    //
    //   scoped_refptr<net::HttpResponseHeaders> responseHeaders =
    //       new net::HttpResponseHeaders(
    //           net::HttpUtil::AssembleRawHeaders(headers.data(), headers.length()));
    //
    //   std::string mimeType, charset;
    //   responseHeaders->GetMimeTypeAndCharset(&mimeType, &charset);
    //   response->setMimeType(WebString::fromUTF8(mimeType));
    //   response->setTextEncodingName(WebString::fromUTF8(charset));
    //
    //   // Copy headers listed in replaceHeaders to the response.
    //   for (const AtomicString& header : replaceHeaders()) {
    //     std::string value;
    //     StringUTF8Adaptor adaptor(header);
    //     base::StringPiece headerStringPiece(adaptor.asStringPiece());
    //     size_t iterator = 0;
    //
    //     response->clearHTTPHeaderField(header);
    //     while (responseHeaders->EnumerateHeader(&iterator, headerStringPiece,
    //                                             &value)) {
    //       response->addHTTPHeaderField(header, WebString::fromLatin1(value));
    //     }
    //   }
    return true;
}

// See https://tools.ietf.org/html/draft-ietf-httpbis-jfv-01, Section 4.
std::unique_ptr<JSONArray> parseJSONHeader(const String& header, int maxParseDepth)
{
    StringBuilder sb;
    sb.append("[");
    sb.append(header);
    sb.append("]");
    std::unique_ptr<JSONValue> headerValue = parseJSON(sb.toString(), maxParseDepth);
    return JSONArray::from(std::move(headerValue));
=======
String extractReasonPhraseFromHTTPStatusLine(const String& statusLine)
{
    size_t spacePos = statusLine.find(' ');
    // Remove status code from the status line.
    spacePos = statusLine.find(' ', spacePos + 1);
    return statusLine.substring(spacePos + 1);
}

XFrameOptionsDisposition parseXFrameOptionsHeader(const String& header)
{
    XFrameOptionsDisposition result = XFrameOptionsNone;

    if (header.isEmpty())
        return result;

    Vector<String> headers;
    header.split(',', headers);

    for (size_t i = 0; i < headers.size(); i++) {
        String currentHeader = headers[i].stripWhiteSpace();
        XFrameOptionsDisposition currentValue = XFrameOptionsNone;
        if (equalIgnoringCase(currentHeader, "deny"))
            currentValue = XFrameOptionsDeny;
        else if (equalIgnoringCase(currentHeader, "sameorigin"))
            currentValue = XFrameOptionsSameOrigin;
        else if (equalIgnoringCase(currentHeader, "allowall"))
            currentValue = XFrameOptionsAllowAll;
        else
            currentValue = XFrameOptionsInvalid;

        if (result == XFrameOptionsNone)
            result = currentValue;
        else if (result != currentValue)
            return XFrameOptionsConflict;
    }
    return result;
}

bool parseRange(const String& range, long long& rangeOffset, long long& rangeEnd, long long& rangeSuffixLength)
{
    // The format of "Range" header is defined in RFC 2616 Section 14.35.1.
    // http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.35.1
    // We don't support multiple range requests.

    rangeOffset = rangeEnd = rangeSuffixLength = -1;

    // The "bytes" unit identifier should be present.
    static const char bytesStart[] = "bytes=";
    if (!range.startsWith(bytesStart, TextCaseInsensitive))
        return false;
    String byteRange = range.substring(sizeof(bytesStart) - 1);

    // The '-' character needs to be present.
    int index = byteRange.find('-');
    if (index == -1)
        return false;

    // If the '-' character is at the beginning, the suffix length, which specifies the last N bytes, is provided.
    // Example:
    //     -500
    if (!index) {
        String suffixLengthString = byteRange.substring(index + 1).stripWhiteSpace();
        bool ok;
        long long value = suffixLengthString.toInt64Strict(&ok);
        if (ok)
            rangeSuffixLength = value;
        return true;
    }

    // Otherwise, the first-byte-position and the last-byte-position are provied.
    // Examples:
    //     0-499
    //     500-
    String firstBytePosStr = byteRange.left(index).stripWhiteSpace();
    bool ok;
    long long firstBytePos = firstBytePosStr.toInt64Strict(&ok);
    if (!ok)
        return false;

    String lastBytePosStr = byteRange.substring(index + 1).stripWhiteSpace();
    long long lastBytePos = -1;
    if (!lastBytePosStr.isEmpty()) {
        lastBytePos = lastBytePosStr.toInt64Strict(&ok);
        if (!ok)
            return false;
    }

    if (firstBytePos < 0 || !(lastBytePos == -1 || lastBytePos >= firstBytePos))
        return false;

    rangeOffset = firstBytePos;
    rangeEnd = lastBytePos;
    return true;
}

// HTTP/1.1 - RFC 2616
// http://www.w3.org/Protocols/rfc2616/rfc2616-sec5.html#sec5.1
// Request-Line = Method SP Request-URI SP HTTP-Version CRLF
size_t parseHTTPRequestLine(const char* data, size_t length, String& failureReason, String& method, String& url, HTTPVersion& httpVersion)
{
    method = String();
    url = String();
    httpVersion = Unknown;

    const char* space1 = 0;
    const char* space2 = 0;
    const char* p;
    size_t consumedLength;

    for (p = data, consumedLength = 0; consumedLength < length; p++, consumedLength++) {
        if (*p == ' ') {
            if (!space1)
                space1 = p;
            else if (!space2)
                space2 = p;
        } else if (*p == '\n') {
            break;
        }
    }

    // Haven't finished header line.
    if (consumedLength == length) {
        failureReason = "Incomplete Request Line";
        return 0;
    }

    // RequestLine does not contain 3 parts.
    if (!space1 || !space2) {
        failureReason = "Request Line does not appear to contain: <Method> <Url> <HTTPVersion>.";
        return 0;
    }

    // The line must end with "\r\n".
    const char* end = p + 1;
    if (*(end - 2) != '\r') {
        failureReason = "Request line does not end with CRLF";
        return 0;
    }

    // Request Method.
    method = String(data, space1 - data); // For length subtract 1 for space, but add 1 for data being the first character.

    // Request URI.
    url = String(space1 + 1, space2 - space1 - 1); // For length subtract 1 for space.

    // HTTP Version.
    String httpVersionString(space2 + 1, end - space2 - 3); // For length subtract 1 for space, and 2 for "\r\n".
    if (httpVersionString.length() != 8 || !httpVersionString.startsWith("HTTP/1."))
        httpVersion = Unknown;
    else if (httpVersionString[7] == '0')
        httpVersion = HTTP_1_0;
    else if (httpVersionString[7] == '1')
        httpVersion = HTTP_1_1;
    else
        httpVersion = Unknown;

    return end - data;
>>>>>>> miniblink49
}

static bool parseHTTPHeaderName(const char* s, size_t start, size_t size, String& failureReason, size_t* position, AtomicString* name)
{
    size_t nameBegin = start;
    for (size_t i = start; i < size; ++i) {
        switch (s[i]) {
        case '\r':
            failureReason = "Unexpected CR in name at " + trimInputSample(&s[nameBegin], i - nameBegin);
            return false;
        case '\n':
            failureReason = "Unexpected LF in name at " + trimInputSample(&s[nameBegin], i - nameBegin);
            return false;
        case ':':
            if (i == nameBegin) {
                failureReason = "Header name is missing";
                return false;
            }
            *name = AtomicString::fromUTF8(&s[nameBegin], i - nameBegin);
            if (name->isNull()) {
                failureReason = "Invalid UTF-8 sequence in header name";
                return false;
            }
            *position = i;
            return true;
        default:
            break;
        }
    }
    failureReason = "Unterminated header name";
    return false;
}

<<<<<<< HEAD

=======
>>>>>>> miniblink49
static bool parseHTTPHeaderValue(const char* s, size_t start, size_t size, String& failureReason, size_t* position, AtomicString* value)
{
    size_t i = start;
    for (; i < size && s[i] == ' '; ++i) {
    }
    size_t valueBegin = i;

    for (; i < size && s[i] != '\r'; ++i) {
        if (s[i] == '\n') {
            failureReason = "Unexpected LF in value at " + trimInputSample(&s[valueBegin], i - valueBegin);
            return false;
        }
    }
    if (i == size) {
        failureReason = "Unterminated header value";
        return false;
    }

<<<<<<< HEAD
    ASSERT(i < size&& s[i] == '\r');
=======
    ASSERT(i < size && s[i] == '\r');
>>>>>>> miniblink49
    if (i + 1 >= size || s[i + 1] != '\n') {
        failureReason = "LF doesn't follow CR after value at " + trimInputSample(&s[i + 1], size - i - 1);
        return false;
    }

    *value = AtomicString::fromUTF8(&s[valueBegin], i - valueBegin);
    if (i != valueBegin && value->isNull()) {
        failureReason = "Invalid UTF-8 sequence in header value";
        return false;
    }

    // 2 for strlen("\r\n")
    *position = i + 2;
    return true;
}

// Note that the header is already parsed and re-formatted in chromium side.
// We assume that the input is more restricted than RFC2616.
size_t parseHTTPHeader(const char* s, size_t size, String& failureReason, AtomicString& name, AtomicString& value)
{
    name = nullAtom;
    value = nullAtom;
    if (size >= 1 && s[0] == '\r') {
        if (size >= 2 && s[1] == '\n') {
            // Skip an empty line.
            return 2;
        }
        failureReason = "LF doesn't follow CR at " + trimInputSample(0, size);
        return 0;
    }
    size_t current = 0;
    if (!parseHTTPHeaderName(s, current, size, failureReason, &current, &name)) {
        return 0;
    }
    ASSERT(s[current] == ':');
    ++current;

    if (!parseHTTPHeaderValue(s, current, size, failureReason, &current, &value)) {
        return 0;
    }

    return current;
}

<<<<<<< HEAD
} // namespace blink
=======
size_t parseHTTPRequestBody(const char* data, size_t length, Vector<unsigned char>& body)
{
    body.clear();
    body.append(data, length);

    return length;
}

static bool isCacheHeaderSeparator(UChar c)
{
    // See RFC 2616, Section 2.2
    switch (c) {
    case '(':
    case ')':
    case '<':
    case '>':
    case '@':
    case ',':
    case ';':
    case ':':
    case '\\':
    case '"':
    case '/':
    case '[':
    case ']':
    case '?':
    case '=':
    case '{':
    case '}':
    case ' ':
    case '\t':
        return true;
    default:
        return false;
    }
}

static bool isControlCharacter(UChar c)
{
    return c < ' ' || c == 127;
}

static inline String trimToNextSeparator(const String& str)
{
    return str.substring(0, str.find(isCacheHeaderSeparator));
}

static void parseCacheHeader(const String& header, Vector<pair<String, String>>& result)
{
    const String safeHeader = header.removeCharacters(isControlCharacter);
    unsigned max = safeHeader.length();
    for (unsigned pos = 0; pos < max; /* pos incremented in loop */) {
        size_t nextCommaPosition = safeHeader.find(',', pos);
        size_t nextEqualSignPosition = safeHeader.find('=', pos);
        if (nextEqualSignPosition != kNotFound && (nextEqualSignPosition < nextCommaPosition || nextCommaPosition == kNotFound)) {
            // Get directive name, parse right hand side of equal sign, then add to map
            String directive = trimToNextSeparator(safeHeader.substring(pos, nextEqualSignPosition - pos).stripWhiteSpace());
            pos += nextEqualSignPosition - pos + 1;

            String value = safeHeader.substring(pos, max - pos).stripWhiteSpace();
            if (value[0] == '"') {
                // The value is a quoted string
                size_t nextDoubleQuotePosition = value.find('"', 1);
                if (nextDoubleQuotePosition != kNotFound) {
                    // Store the value as a quoted string without quotes
                    result.append(pair<String, String>(directive, value.substring(1, nextDoubleQuotePosition - 1).stripWhiteSpace()));
                    pos += (safeHeader.find('"', pos) - pos) + nextDoubleQuotePosition + 1;
                    // Move past next comma, if there is one
                    size_t nextCommaPosition2 = safeHeader.find(',', pos);
                    if (nextCommaPosition2 != kNotFound)
                        pos += nextCommaPosition2 - pos + 1;
                    else
                        return; // Parse error if there is anything left with no comma
                } else {
                    // Parse error; just use the rest as the value
                    result.append(pair<String, String>(directive, trimToNextSeparator(value.substring(1, value.length() - 1).stripWhiteSpace())));
                    return;
                }
            } else {
                // The value is a token until the next comma
                size_t nextCommaPosition2 = value.find(',');
                if (nextCommaPosition2 != kNotFound) {
                    // The value is delimited by the next comma
                    result.append(pair<String, String>(directive, trimToNextSeparator(value.substring(0, nextCommaPosition2).stripWhiteSpace())));
                    pos += (safeHeader.find(',', pos) - pos) + 1;
                } else {
                    // The rest is the value; no change to value needed
                    result.append(pair<String, String>(directive, trimToNextSeparator(value)));
                    return;
                }
            }
        } else if (nextCommaPosition != kNotFound && (nextCommaPosition < nextEqualSignPosition || nextEqualSignPosition == kNotFound)) {
            // Add directive to map with empty string as value
            result.append(pair<String, String>(trimToNextSeparator(safeHeader.substring(pos, nextCommaPosition - pos).stripWhiteSpace()), ""));
            pos += nextCommaPosition - pos + 1;
        } else {
            // Add last directive to map with empty string as value
            result.append(pair<String, String>(trimToNextSeparator(safeHeader.substring(pos, max - pos).stripWhiteSpace()), ""));
            return;
        }
    }
}

CacheControlHeader parseCacheControlDirectives(const AtomicString& cacheControlValue, const AtomicString& pragmaValue)
{
    CacheControlHeader cacheControlHeader;
    cacheControlHeader.parsed = true;
    cacheControlHeader.maxAge = std::numeric_limits<double>::quiet_NaN();
    cacheControlHeader.staleWhileRevalidate = std::numeric_limits<double>::quiet_NaN();

    DEFINE_STATIC_LOCAL(const AtomicString, noCacheDirective, ("no-cache", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, noStoreDirective, ("no-store", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, mustRevalidateDirective, ("must-revalidate", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, maxAgeDirective, ("max-age", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, staleWhileRevalidateDirective, ("stale-while-revalidate", AtomicString::ConstructFromLiteral));

    if (!cacheControlValue.isEmpty()) {
        Vector<pair<String, String>> directives;
        parseCacheHeader(cacheControlValue, directives);

        size_t directivesSize = directives.size();
        for (size_t i = 0; i < directivesSize; ++i) {
            // RFC2616 14.9.1: A no-cache directive with a value is only meaningful for proxy caches.
            // It should be ignored by a browser level cache.
            if (equalIgnoringCase(directives[i].first, noCacheDirective) && directives[i].second.isEmpty()) {
                cacheControlHeader.containsNoCache = true;
            } else if (equalIgnoringCase(directives[i].first, noStoreDirective)) {
                cacheControlHeader.containsNoStore = true;
            } else if (equalIgnoringCase(directives[i].first, mustRevalidateDirective)) {
                cacheControlHeader.containsMustRevalidate = true;
            } else if (equalIgnoringCase(directives[i].first, maxAgeDirective)) {
                if (!std::isnan(cacheControlHeader.maxAge)) {
                    // First max-age directive wins if there are multiple ones.
                    continue;
                }
                bool ok;
                double maxAge = directives[i].second.toDouble(&ok);
                if (ok)
                    cacheControlHeader.maxAge = maxAge;
            } else if (equalIgnoringCase(directives[i].first, staleWhileRevalidateDirective)) {
                if (!std::isnan(cacheControlHeader.staleWhileRevalidate)) {
                    // First stale-while-revalidate directive wins if there are multiple ones.
                    continue;
                }
                bool ok;
                double staleWhileRevalidate = directives[i].second.toDouble(&ok);
                if (ok)
                    cacheControlHeader.staleWhileRevalidate = staleWhileRevalidate;
            }
        }
    }

    if (!cacheControlHeader.containsNoCache) {
        // Handle Pragma: no-cache
        // This is deprecated and equivalent to Cache-control: no-cache
        // Don't bother tokenizing the value, it is not important
        cacheControlHeader.containsNoCache = pragmaValue.lower().contains(noCacheDirective);
    }
    return cacheControlHeader;
}

void parseCommaDelimitedHeader(const String& headerValue, CommaDelimitedHeaderSet& headerSet)
{
    Vector<String> results;
    headerValue.split(",", results);
    for (auto& value : results)
        headerSet.add(value.stripWhiteSpace(isWhitespace));
}

}
>>>>>>> miniblink49
