/*
 * Copyright (C) 2004, 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
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

#ifndef TextEncoding_h
#define TextEncoding_h

<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
>>>>>>> miniblink49
#include "wtf/Forward.h"
#include "wtf/WTFExport.h"
#include "wtf/text/TextCodec.h"
#include "wtf/text/Unicode.h"

namespace WTF {

<<<<<<< HEAD
class WTF_EXPORT TextEncoding final {
    USING_FAST_MALLOC(TextEncoding);

public:
    TextEncoding()
        : m_name(0)
    {
    }
=======
class WTF_EXPORT TextEncoding {
public:
    TextEncoding() : m_name(0) { }
>>>>>>> miniblink49
    TextEncoding(const char* name);
    TextEncoding(const String& name);

    bool isValid() const { return m_name; }
    const char* name() const { return m_name; }
    bool usesVisualOrdering() const;
    const TextEncoding& closestByteBasedEquivalent() const;
    const TextEncoding& encodingForFormSubmission() const;

    String decode(const char* str, size_t length) const
    {
        bool ignored;
        return decode(str, length, false, ignored);
    }
<<<<<<< HEAD
    String decode(const char*,
        size_t length,
        bool stopOnError,
        bool& sawError) const;

    CString encode(const String&, UnencodableHandling) const;

    bool isNonByteBasedEncoding() const;

private:
=======
    String decode(const char*, size_t length, bool stopOnError, bool& sawError) const;

    // Encodes the string, but does *not* normalize first.
    CString encode(const String&, UnencodableHandling) const;

    // Applies Unicode NFC normalization, then encodes the normalized string.
    CString normalizeAndEncode(const String&, UnencodableHandling) const;

private:
    bool isNonByteBasedEncoding() const;
>>>>>>> miniblink49
    bool isUTF7Encoding() const;

    const char* m_name;
};

<<<<<<< HEAD
inline bool operator==(const TextEncoding& a, const TextEncoding& b)
{
    return a.name() == b.name();
}
inline bool operator!=(const TextEncoding& a, const TextEncoding& b)
{
    return a.name() != b.name();
}
=======
inline bool operator==(const TextEncoding& a, const TextEncoding& b) { return a.name() == b.name(); }
inline bool operator!=(const TextEncoding& a, const TextEncoding& b) { return a.name() != b.name(); }
>>>>>>> miniblink49

WTF_EXPORT const TextEncoding& ASCIIEncoding();
WTF_EXPORT const TextEncoding& Latin1Encoding();
WTF_EXPORT const TextEncoding& UTF16BigEndianEncoding();
WTF_EXPORT const TextEncoding& UTF16LittleEndianEncoding();
<<<<<<< HEAD
WTF_EXPORT const TextEncoding& UTF32Encoding();
=======
>>>>>>> miniblink49
WTF_EXPORT const TextEncoding& UTF32BigEndianEncoding();
WTF_EXPORT const TextEncoding& UTF32LittleEndianEncoding();
WTF_EXPORT const TextEncoding& UTF8Encoding();
WTF_EXPORT const TextEncoding& WindowsLatin1Encoding();

} // namespace WTF

using WTF::ASCIIEncoding;
using WTF::Latin1Encoding;
using WTF::UTF16BigEndianEncoding;
using WTF::UTF16LittleEndianEncoding;
using WTF::UTF32BigEndianEncoding;
<<<<<<< HEAD
using WTF::UTF32Encoding;
=======
>>>>>>> miniblink49
using WTF::UTF32LittleEndianEncoding;
using WTF::UTF8Encoding;
using WTF::WindowsLatin1Encoding;

#endif // TextEncoding_h
