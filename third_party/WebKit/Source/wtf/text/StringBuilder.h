/*
 * Copyright (C) 2009, 2010, 2012, 2013 Apple Inc. All rights reserved.
 * Copyright (C) 2012 Google Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef StringBuilder_h
#define StringBuilder_h

#include "wtf/WTFExport.h"
#include "wtf/text/AtomicString.h"
<<<<<<< HEAD
#include "wtf/text/StringView.h"
=======
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace WTF {

class WTF_EXPORT StringBuilder {
<<<<<<< HEAD
=======
    // Disallow copying since it's expensive and we don't want code to do it by accident.
>>>>>>> miniblink49
    WTF_MAKE_NONCOPYABLE(StringBuilder);

public:
    StringBuilder()
<<<<<<< HEAD
        : m_buffer(nullptr)
=======
        : m_bufferCharacters8(0)
>>>>>>> miniblink49
        , m_length(0)
        , m_is8Bit(true)
    {
    }

<<<<<<< HEAD
    ~StringBuilder() { clear(); }

    void append(const UChar*, unsigned length);
    void append(const LChar*, unsigned length);

    ALWAYS_INLINE void append(const char* characters, unsigned length)
    {
        append(reinterpret_cast<const LChar*>(characters), length);
    }

    void append(const StringBuilder& other)
    {
        if (!other.m_length)
            return;

        if (!m_length && !hasBuffer() && !other.m_string.isNull()) {
            m_string = other.m_string;
            m_length = other.m_string.length();
            m_is8Bit = other.m_string.is8Bit();
            return;
        }

        if (other.is8Bit())
            append(other.characters8(), other.m_length);
        else
            append(other.characters16(), other.m_length);
    }

    // NOTE: The semantics of this are different than StringView(..., offset,
    // length) in that an invalid offset or invalid length is a no-op instead of
    // an error.
    // TODO(esprehn): We should probably unify the semantics instead.
    void append(const StringView& string, unsigned offset, unsigned length)
    {
        unsigned extent = offset + length;
        if (extent < offset || extent > string.length())
            return;

        // We can't do this before the above check since StringView's constructor
        // doesn't accept invalid offsets or lengths.
        append(StringView(string, offset, length));
    }

    void append(const StringView& string)
    {
        if (string.isEmpty())
            return;

        // If we're appending to an empty builder, and there is not a buffer
        // (reserveCapacity has not been called), then share the impl if
        // possible.
        //
        // This is important to avoid string copies inside dom operations like
        // Node::textContent when there's only a single Text node child, or
        // inside the parser in the common case when flushing buffered text to
        // a Text node.
        StringImpl* impl = string.sharedImpl();
        if (!m_length && !hasBuffer() && impl) {
            m_string = impl;
            m_length = impl->length();
            m_is8Bit = impl->is8Bit();
=======
    void append(const UChar*, unsigned);
    void append(const LChar*, unsigned);

    ALWAYS_INLINE void append(const char* characters, unsigned length) { append(reinterpret_cast<const LChar*>(characters), length); }

    void append(const String& string)
    {
        if (!string.length())
            return;

        // If we're appending to an empty string, and there is not a buffer (reserveCapacity has not been called)
        // then just retain the string.
        if (!m_length && !m_buffer) {
            m_string = string;
            m_length = string.length();
            m_is8Bit = m_string.is8Bit();
>>>>>>> miniblink49
            return;
        }

        if (string.is8Bit())
            append(string.characters8(), string.length());
        else
            append(string.characters16(), string.length());
    }

<<<<<<< HEAD
    void append(UChar c)
    {
        if (m_is8Bit && c <= 0xFF) {
            append(static_cast<LChar>(c));
            return;
        }
        ensureBuffer16(1);
        m_buffer16->push_back(c);
        ++m_length;
=======
    void append(const StringBuilder& other)
    {
        if (!other.m_length)
            return;

        // If we're appending to an empty string, and there is not a buffer (reserveCapacity has not been called)
        // then just retain the string.
        if (!m_length && !m_buffer && !other.m_string.isNull()) {
            m_string = other.m_string;
            m_length = other.m_length;
            return;
        }

        if (other.is8Bit())
            append(other.characters8(), other.m_length);
        else
            append(other.characters16(), other.m_length);
    }

    void append(const String& string, unsigned offset, unsigned length)
    {
        if (!string.length())
            return;

        unsigned extent = offset + length;
        if (extent < offset || extent > string.length())
            return;

        if (string.is8Bit())
            append(string.characters8() + offset, length);
        else
            append(string.characters16() + offset, length);
    }

    void append(const StringView& string)
    {
        if (!string.length())
            return;

        if (string.is8Bit())
            append(string.characters8(), string.length());
        else
            append(string.characters16(), string.length());
    }

    void append(const char* characters)
    {
        if (characters)
            append(characters, strlen(characters));
    }

    void append(UChar c)
    {
        if (m_buffer && m_length < m_buffer->length() && m_string.isNull()) {
            if (!m_is8Bit) {
                m_bufferCharacters16[m_length++] = c;
                return;
            }

            if (!(c & ~0xff)) {
                m_bufferCharacters8[m_length++] = static_cast<LChar>(c);
                return;
            }
        }
        append(&c, 1);
>>>>>>> miniblink49
    }

    void append(LChar c)
    {
<<<<<<< HEAD
        if (!m_is8Bit) {
            append(static_cast<UChar>(c));
            return;
        }
        ensureBuffer8(1);
        m_buffer8->push_back(c);
        ++m_length;
    }

    void append(char c) { append(static_cast<LChar>(c)); }
=======
        if (m_buffer && m_length < m_buffer->length() && m_string.isNull()) {
            if (m_is8Bit)
                m_bufferCharacters8[m_length++] = c;
            else
                m_bufferCharacters16[m_length++] = c;
        } else
            append(&c, 1);
    }

    void append(char c)
    {
        append(static_cast<LChar>(c));
    }
>>>>>>> miniblink49

    void append(UChar32 c)
    {
        if (U_IS_BMP(c)) {
            append(static_cast<UChar>(c));
            return;
        }
        append(U16_LEAD(c));
        append(U16_TRAIL(c));
    }

<<<<<<< HEAD
=======
    template<unsigned charactersCount>
    ALWAYS_INLINE void appendLiteral(const char (&characters)[charactersCount]) { append(characters, charactersCount - 1); }

>>>>>>> miniblink49
    void appendNumber(int);
    void appendNumber(unsigned);
    void appendNumber(long);
    void appendNumber(unsigned long);
    void appendNumber(long long);
    void appendNumber(unsigned long long);
<<<<<<< HEAD
    void appendNumber(double, unsigned precision = 6);

    String toString();
    AtomicString toAtomicString();
    String substring(unsigned start, unsigned length) const;

    unsigned length() const { return m_length; }
    bool isEmpty() const { return !m_length; }

    unsigned capacity() const;
    void reserveCapacity(unsigned newCapacity);

    // TODO(esprehn): Rename to shrink().
    void resize(unsigned newSize);

    UChar operator[](unsigned i) const
    {
        SECURITY_DCHECK(i < m_length);
=======
    void appendNumber(double, unsigned precision = 6, TrailingZerosTruncatingPolicy = TruncateTrailingZeros);

    String toString()
    {
        shrinkToFit();
        if (m_string.isNull())
            reifyString();
        return m_string;
    }

    String substring(unsigned position, unsigned length) const
    {
        if (!m_length)
            return emptyString();
        if (!m_string.isNull())
            return m_string.substring(position, length);
        return reifySubstring(position, length);
    }

    AtomicString toAtomicString() const
    {
        if (!m_length)
            return emptyAtom;

        // If the buffer is sufficiently over-allocated, make a new AtomicString from a copy so its buffer is not so large.
        if (canShrink()) {
            if (is8Bit())
                return AtomicString(characters8(), length());
            return AtomicString(characters16(), length());
        }

        if (!m_string.isNull())
            return AtomicString(m_string);

        ASSERT(m_buffer);
        return AtomicString(m_buffer.get(), 0, m_length);
    }

    unsigned length() const
    {
        return m_length;
    }

    bool isEmpty() const { return !m_length; }

    void reserveCapacity(unsigned newCapacity);

    unsigned capacity() const
    {
        return m_buffer ? m_buffer->length() : m_length;
    }

    void resize(unsigned newSize);

    bool canShrink() const;

    void shrinkToFit();

    UChar operator[](unsigned i) const
    {
        ASSERT_WITH_SECURITY_IMPLICATION(i < m_length);
>>>>>>> miniblink49
        if (m_is8Bit)
            return characters8()[i];
        return characters16()[i];
    }

    const LChar* characters8() const
    {
<<<<<<< HEAD
        DCHECK(m_is8Bit);
        if (!length())
            return nullptr;
        if (!m_string.isNull())
            return m_string.characters8();
        DCHECK(m_buffer8);
        return m_buffer8->data();
=======
        ASSERT(m_is8Bit);
        if (!m_length)
            return 0;
        if (!m_string.isNull())
            return m_string.characters8();
        ASSERT(m_buffer);
        return m_buffer->characters8();
>>>>>>> miniblink49
    }

    const UChar* characters16() const
    {
<<<<<<< HEAD
        DCHECK(!m_is8Bit);
        if (!length())
            return nullptr;
        if (!m_string.isNull())
            return m_string.characters16();
        DCHECK(m_buffer16);
        return m_buffer16->data();
=======
        ASSERT(!m_is8Bit);
        if (!m_length)
            return 0;
        if (!m_string.isNull())
            return m_string.characters16();
        ASSERT(m_buffer);
        return m_buffer->characters16();
>>>>>>> miniblink49
    }

    bool is8Bit() const { return m_is8Bit; }

<<<<<<< HEAD
    void clear();
    void swap(StringBuilder&);

private:
    static const unsigned kInlineBufferSize = 16;
    static unsigned initialBufferSize() { return kInlineBufferSize; }

    typedef Vector<LChar, kInlineBufferSize> Buffer8;
    typedef Vector<UChar, kInlineBufferSize> Buffer16;

    void ensureBuffer8(unsigned addedSize)
    {
        DCHECK(m_is8Bit);
        if (!hasBuffer())
            createBuffer8(addedSize);
    }

    void ensureBuffer16(unsigned addedSize)
    {
        if (m_is8Bit || !hasBuffer())
            createBuffer16(addedSize);
    }

    void createBuffer8(unsigned addedSize);
    void createBuffer16(unsigned addedSize);
    void clearBuffer();
    bool hasBuffer() const { return m_buffer; }

    String m_string;
    union {
        Buffer8* m_buffer8;
        Buffer16* m_buffer16;
        void* m_buffer;
=======
    void clear()
    {
        m_length = 0;
        m_string = String();
        m_buffer = nullptr;
        m_bufferCharacters8 = 0;
        m_is8Bit = true;
    }

    void swap(StringBuilder& stringBuilder)
    {
        std::swap(m_length, stringBuilder.m_length);
        m_string.swap(stringBuilder.m_string);
        m_buffer.swap(stringBuilder.m_buffer);
        std::swap(m_is8Bit, stringBuilder.m_is8Bit);
        std::swap(m_bufferCharacters8, stringBuilder.m_bufferCharacters8);
    }

private:
    void allocateBuffer(const LChar* currentCharacters, unsigned requiredLength);
    void allocateBuffer(const UChar* currentCharacters, unsigned requiredLength);
    void allocateBufferUpConvert(const LChar* currentCharacters, unsigned requiredLength);
    template <typename CharType>
    void reallocateBuffer(unsigned requiredLength);
    template <typename CharType>
    ALWAYS_INLINE CharType* appendUninitialized(unsigned length);
    template <typename CharType>
    CharType* appendUninitializedSlow(unsigned length);
    template <typename CharType>
    ALWAYS_INLINE CharType * getBufferCharacters();
    void reifyString();
    String reifySubstring(unsigned position, unsigned length) const;

    String m_string; // Pointers first: crbug.com/232031
    RefPtr<StringImpl> m_buffer;
    union {
        LChar* m_bufferCharacters8;
        UChar* m_bufferCharacters16;
>>>>>>> miniblink49
    };
    unsigned m_length;
    bool m_is8Bit;
};

<<<<<<< HEAD
=======
template <>
ALWAYS_INLINE LChar* StringBuilder::getBufferCharacters<LChar>()
{
    ASSERT(m_is8Bit);
    return m_bufferCharacters8;
}

template <>
ALWAYS_INLINE UChar* StringBuilder::getBufferCharacters<UChar>()
{
    ASSERT(!m_is8Bit);
    return m_bufferCharacters16;
}

>>>>>>> miniblink49
template <typename CharType>
bool equal(const StringBuilder& s, const CharType* buffer, unsigned length)
{
    if (s.length() != length)
        return false;

    if (s.is8Bit())
        return equal(s.characters8(), buffer, length);

    return equal(s.characters16(), buffer, length);
}

<<<<<<< HEAD
template <typename CharType>
bool equalIgnoringCase(const StringBuilder& s,
    const CharType* buffer,
    unsigned length)
=======
template<typename CharType>
bool equalIgnoringCase(const StringBuilder& s, const CharType* buffer, unsigned length)
>>>>>>> miniblink49
{
    if (s.length() != length)
        return false;

    if (s.is8Bit())
        return equalIgnoringCase(s.characters8(), buffer, length);

    return equalIgnoringCase(s.characters16(), buffer, length);
}

<<<<<<< HEAD
// Unicode aware case insensitive string matching. Non-ASCII characters might
// match to ASCII characters. This function is rarely used to implement web
// platform features.
inline bool equalIgnoringCase(const StringBuilder& s, const char* string)
{
    return equalIgnoringCase(s, reinterpret_cast<const LChar*>(string),
        strlen(string));
=======
inline bool equalIgnoringCase(const StringBuilder& s, const char* string)
{
    return equalIgnoringCase(s, reinterpret_cast<const LChar*>(string), strlen(string));
>>>>>>> miniblink49
}

template <typename StringType>
bool equal(const StringBuilder& a, const StringType& b)
{
    if (a.length() != b.length())
        return false;

    if (!a.length())
        return true;

    if (a.is8Bit()) {
        if (b.is8Bit())
            return equal(a.characters8(), b.characters8(), a.length());
        return equal(a.characters8(), b.characters16(), a.length());
    }

    if (b.is8Bit())
        return equal(a.characters16(), b.characters8(), a.length());
    return equal(a.characters16(), b.characters16(), a.length());
}

<<<<<<< HEAD
inline bool operator==(const StringBuilder& a, const StringBuilder& b)
{
    return equal(a, b);
}
inline bool operator!=(const StringBuilder& a, const StringBuilder& b)
{
    return !equal(a, b);
}
inline bool operator==(const StringBuilder& a, const String& b)
{
    return equal(a, b);
}
inline bool operator!=(const StringBuilder& a, const String& b)
{
    return !equal(a, b);
}
inline bool operator==(const String& a, const StringBuilder& b)
{
    return equal(b, a);
}
inline bool operator!=(const String& a, const StringBuilder& b)
{
    return !equal(b, a);
}

=======
template <typename StringType>
bool equalIgnoringCase(const StringBuilder& a, const StringType& b)
{
    if (a.length() != b.length())
        return false;

    if (!a.length())
        return true;

    if (a.is8Bit()) {
        if (b.is8Bit())
            return equalIgnoringCase(a.characters8(), b.characters8(), a.length());
        return equalIgnoringCase(a.characters8(), b.characters16(), a.length());
    }

    if (b.is8Bit())
        return equalIgnoringCase(a.characters16(), b.characters8(), a.length());
    return equalIgnoringCase(a.characters16(), b.characters16(), a.length());
}

inline bool operator==(const StringBuilder& a, const StringBuilder& b) { return equal(a, b); }
inline bool operator!=(const StringBuilder& a, const StringBuilder& b) { return !equal(a, b); }
inline bool operator==(const StringBuilder& a, const String& b) { return equal(a, b); }
inline bool operator!=(const StringBuilder& a, const String& b) { return !equal(a, b); }
inline bool operator==(const String& a, const StringBuilder& b) { return equal(b, a); }
inline bool operator!=(const String& a, const StringBuilder& b) { return !equal(b, a); }

>>>>>>> miniblink49
} // namespace WTF

using WTF::StringBuilder;

#endif // StringBuilder_h
