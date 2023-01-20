/*
 * Copyright (C) 2004, 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
 * Copyright (C) 2006 Alexey Proskuryakov <ap@nypop.com>
 * Copyright (C) 2007-2009 Torch Mobile, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "wtf/text/TextEncoding.h"

#include "wtf/StdLibExtras.h"
#include "wtf/Threading.h"
#include "wtf/text/CString.h"
#include "wtf/text/TextEncodingRegistry.h"
#include "wtf/text/WTFString.h"
#include <memory>
=======
#include "config.h"
#include "wtf/text/TextEncoding.h"

#include "wtf/text/TextEncodingRegistry.h"
//#include <unicode/unorm.h>
#include "wtf/OwnPtr.h"
#include "wtf/StdLibExtras.h"
#include "wtf/Threading.h"
#include "wtf/text/CString.h"
#include "wtf/text/WTFString.h"
>>>>>>> miniblink49

namespace WTF {

static const TextEncoding& UTF7Encoding()
{
<<<<<<< HEAD
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding, globalUTF7Encoding,
        new TextEncoding("UTF-7"));
=======
    AtomicallyInitializedStaticReference(const TextEncoding, globalUTF7Encoding, new TextEncoding("UTF-7"));
>>>>>>> miniblink49
    return globalUTF7Encoding;
}

TextEncoding::TextEncoding(const char* name)
    : m_name(atomicCanonicalTextEncodingName(name))
{
    // Aliases are valid, but not "replacement" itself.
    if (m_name && isReplacementEncoding(name))
        m_name = 0;
}

TextEncoding::TextEncoding(const String& name)
    : m_name(atomicCanonicalTextEncodingName(name))
{
    // Aliases are valid, but not "replacement" itself.
    if (m_name && isReplacementEncoding(name))
        m_name = 0;
}

<<<<<<< HEAD
String TextEncoding::decode(const char* data,
    size_t length,
    bool stopOnError,
    bool& sawError) const
=======
String TextEncoding::decode(const char* data, size_t length, bool stopOnError, bool& sawError) const
>>>>>>> miniblink49
{
    if (!m_name)
        return String();

<<<<<<< HEAD
    return newTextCodec(*this)->decode(data, length, DataEOF, stopOnError,
        sawError);
}

CString TextEncoding::encode(const String& string,
    UnencodableHandling handling) const
=======
    return newTextCodec(*this)->decode(data, length, DataEOF, stopOnError, sawError);
}

CString TextEncoding::encode(const String& string, UnencodableHandling handling) const
>>>>>>> miniblink49
{
    if (!m_name)
        return CString();

    if (string.isEmpty())
        return "";

<<<<<<< HEAD
    std::unique_ptr<TextCodec> textCodec = newTextCodec(*this);
=======
    OwnPtr<TextCodec> textCodec = newTextCodec(*this);
>>>>>>> miniblink49
    CString encodedString;
    if (string.is8Bit())
        encodedString = textCodec->encode(string.characters8(), string.length(), handling);
    else
        encodedString = textCodec->encode(string.characters16(), string.length(), handling);
    return encodedString;
}

<<<<<<< HEAD
=======
CString TextEncoding::normalizeAndEncode(const String& string, UnencodableHandling handling) const
{
    if (!m_name)
        return CString();

    if (string.isEmpty())
        return "";

    // Text exclusively containing Latin-1 characters (U+0000..U+00FF) is left
    // unaffected by NFC. This is effectively the same as saying that all
    // Latin-1 text is already normalized to NFC.
    // Source: http://unicode.org/reports/tr15/
    if (string.is8Bit())
        return newTextCodec(*this)->encode(string.characters8(), string.length(), handling);

    const UChar* source = string.characters16();
    size_t length = string.length();

    Vector<UChar> normalizedCharacters;

#ifdef MINIBLINK_NOT_IMPLEMENTED
    UErrorCode err = U_ZERO_ERROR;
    if (unorm_quickCheck(source, length, UNORM_NFC, &err) != UNORM_YES) {
        // First try using the length of the original string, since normalization to NFC rarely increases length.
        normalizedCharacters.grow(length);
        int32_t normalizedLength = unorm_normalize(source, length, UNORM_NFC, 0, normalizedCharacters.data(), length, &err);
        if (err == U_BUFFER_OVERFLOW_ERROR) {
            err = U_ZERO_ERROR;
            normalizedCharacters.resize(normalizedLength);
            normalizedLength = unorm_normalize(source, length, UNORM_NFC, 0, normalizedCharacters.data(), normalizedLength, &err);
        }
        ASSERT(U_SUCCESS(err));

        source = normalizedCharacters.data();
        length = normalizedLength;
    }
#endif // MINIBLINK_NOT_IMPLEMENTED

    return newTextCodec(*this)->encode(source, length, handling);
}

>>>>>>> miniblink49
bool TextEncoding::usesVisualOrdering() const
{
    if (noExtendedTextEncodingNameUsed())
        return false;

    static const char* const a = atomicCanonicalTextEncodingName("ISO-8859-8");
    return m_name == a;
}

bool TextEncoding::isNonByteBasedEncoding() const
{
    if (noExtendedTextEncodingNameUsed()) {
<<<<<<< HEAD
        return *this == UTF16LittleEndianEncoding() || *this == UTF16BigEndianEncoding();
    }

    return *this == UTF16LittleEndianEncoding() || *this == UTF16BigEndianEncoding() || *this == UTF32Encoding() || *this == UTF32BigEndianEncoding() || *this == UTF32LittleEndianEncoding();
=======
        return *this == UTF16LittleEndianEncoding()
            || *this == UTF16BigEndianEncoding();
    }

    return *this == UTF16LittleEndianEncoding()
        || *this == UTF16BigEndianEncoding()
        || *this == UTF32BigEndianEncoding()
        || *this == UTF32LittleEndianEncoding();
>>>>>>> miniblink49
}

bool TextEncoding::isUTF7Encoding() const
{
    if (noExtendedTextEncodingNameUsed())
        return false;

    return *this == UTF7Encoding();
}

const TextEncoding& TextEncoding::closestByteBasedEquivalent() const
{
    if (isNonByteBasedEncoding())
        return UTF8Encoding();
    return *this;
}

// HTML5 specifies that UTF-8 be used in form submission when a form is
// is a part of a document in UTF-16 probably because UTF-16 is not a
// byte-based encoding and can contain 0x00. By extension, the same
// should be done for UTF-32. In case of UTF-7, it is a byte-based encoding,
// but it's fraught with problems and we'd rather steer clear of it.
const TextEncoding& TextEncoding::encodingForFormSubmission() const
{
    if (isNonByteBasedEncoding() || isUTF7Encoding())
        return UTF8Encoding();
    return *this;
}

const TextEncoding& ASCIIEncoding()
{
<<<<<<< HEAD
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding, globalASCIIEncoding,
        new TextEncoding("ASCII"));
=======
    AtomicallyInitializedStaticReference(const TextEncoding, globalASCIIEncoding, new TextEncoding("ASCII"));
>>>>>>> miniblink49
    return globalASCIIEncoding;
}

const TextEncoding& Latin1Encoding()
{
<<<<<<< HEAD
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding, globalLatin1Encoding,
        new TextEncoding("latin1"));
=======
    AtomicallyInitializedStaticReference(const TextEncoding, globalLatin1Encoding, new TextEncoding("latin1"));
>>>>>>> miniblink49
    return globalLatin1Encoding;
}

const TextEncoding& UTF16BigEndianEncoding()
{
<<<<<<< HEAD
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding,
        globalUTF16BigEndianEncoding,
        new TextEncoding("UTF-16BE"));
=======
    AtomicallyInitializedStaticReference(const TextEncoding, globalUTF16BigEndianEncoding, new TextEncoding("UTF-16BE"));
>>>>>>> miniblink49
    return globalUTF16BigEndianEncoding;
}

const TextEncoding& UTF16LittleEndianEncoding()
{
<<<<<<< HEAD
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding,
        globalUTF16LittleEndianEncoding,
        new TextEncoding("UTF-16LE"));
    return globalUTF16LittleEndianEncoding;
}

// UTF-32 is UTF-32LE with an implicit BOM.
const TextEncoding& UTF32Encoding()
{
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding, globalUTF32Encoding,
        new TextEncoding("UTF-32"));
    return globalUTF32Encoding;
}

const TextEncoding& UTF32BigEndianEncoding()
{
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding,
        globalUTF32BigEndianEncoding,
        new TextEncoding("UTF-32BE"));
=======
    AtomicallyInitializedStaticReference(const TextEncoding, globalUTF16LittleEndianEncoding, new TextEncoding("UTF-16LE"));
    return globalUTF16LittleEndianEncoding;
}

const TextEncoding& UTF32BigEndianEncoding()
{
    AtomicallyInitializedStaticReference(const TextEncoding, globalUTF32BigEndianEncoding, new TextEncoding("UTF-32BE"));
>>>>>>> miniblink49
    return globalUTF32BigEndianEncoding;
}

const TextEncoding& UTF32LittleEndianEncoding()
{
<<<<<<< HEAD
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding,
        globalUTF32LittleEndianEncoding,
        new TextEncoding("UTF-32LE"));
=======
    AtomicallyInitializedStaticReference(const TextEncoding, globalUTF32LittleEndianEncoding, new TextEncoding("UTF-32LE"));
>>>>>>> miniblink49
    return globalUTF32LittleEndianEncoding;
}

const TextEncoding& UTF8Encoding()
{
<<<<<<< HEAD
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding, globalUTF8Encoding,
        new TextEncoding("UTF-8"));
    DCHECK(globalUTF8Encoding.isValid());
=======
    AtomicallyInitializedStaticReference(const TextEncoding, globalUTF8Encoding, new TextEncoding("UTF-8"));
    ASSERT(globalUTF8Encoding.isValid());
>>>>>>> miniblink49
    return globalUTF8Encoding;
}

const TextEncoding& WindowsLatin1Encoding()
{
<<<<<<< HEAD
    DEFINE_THREAD_SAFE_STATIC_LOCAL(const TextEncoding,
        globalWindowsLatin1Encoding,
        new TextEncoding("WinLatin1"));
=======
    AtomicallyInitializedStaticReference(const TextEncoding, globalWindowsLatin1Encoding, new TextEncoding("WinLatin1"));
>>>>>>> miniblink49
    return globalWindowsLatin1Encoding;
}

} // namespace WTF
