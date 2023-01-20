/*
 * Copyright (C) 2010 Apple Inc. All rights reserved.
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

<<<<<<< HEAD
#include "wtf/text/StringBuilder.h"

#include "wtf/dtoa.h"
#include "wtf/text/IntegerToStringConversion.h"
#include "wtf/text/WTFString.h"
#include <algorithm>

namespace WTF {

String StringBuilder::toString()
{
    if (!m_length)
        return emptyString();
    if (m_string.isNull()) {
        if (m_is8Bit)
            m_string = String(characters8(), m_length);
        else
            m_string = String(characters16(), m_length);
        clearBuffer();
    }
    return m_string;
}

AtomicString StringBuilder::toAtomicString()
{
    if (!m_length)
        return emptyAtom;
    if (m_string.isNull()) {
        if (m_is8Bit)
            m_string = AtomicString(characters8(), m_length);
        else
            m_string = AtomicString(characters16(), m_length);
        clearBuffer();
    }
    return AtomicString(m_string);
}

String StringBuilder::substring(unsigned start, unsigned length) const
{
    if (start >= m_length)
        return emptyString();
    if (!m_string.isNull())
        return m_string.substring(start, length);
    length = std::min(length, m_length - start);
    if (m_is8Bit)
        return String(characters8() + start, length);
    return String(characters16() + start, length);
}

void StringBuilder::swap(StringBuilder& builder)
{
    std::swap(m_string, builder.m_string);
    std::swap(m_buffer, builder.m_buffer);
    std::swap(m_length, builder.m_length);
    std::swap(m_is8Bit, builder.m_is8Bit);
}

void StringBuilder::clearBuffer()
{
    if (m_is8Bit)
        delete m_buffer8;
    else
        delete m_buffer16;
    m_buffer = nullptr;
}

void StringBuilder::clear()
{
    clearBuffer();
    m_string = String();
    m_length = 0;
    m_is8Bit = true;
}

unsigned StringBuilder::capacity() const
{
    if (!hasBuffer())
        return 0;
    if (m_is8Bit)
        return m_buffer8->capacity();
    return m_buffer16->capacity();
}

void StringBuilder::reserveCapacity(unsigned newCapacity)
{
    if (m_is8Bit)
        ensureBuffer8(newCapacity);
    else
        ensureBuffer16(newCapacity);
=======
#include "config.h"
#include "StringBuilder.h"

#include "IntegerToStringConversion.h"
#include "WTFString.h"
#include "wtf/dtoa.h"

namespace WTF {

static unsigned expandedCapacity(unsigned capacity, unsigned requiredLength)
{
    static const unsigned minimumCapacity = 16;
    return std::max(requiredLength, std::max(minimumCapacity, capacity * 2));
}

void StringBuilder::reifyString()
{
    if (!m_string.isNull()) {
        ASSERT(m_string.length() == m_length);
        return;
    }

    if (!m_length) {
        m_string = StringImpl::empty();
        return;
    }

    ASSERT(m_buffer && m_length <= m_buffer->length());
    if (m_length == m_buffer->length()) {
        m_string = m_buffer.release();
        return;
    }

    if (m_buffer->hasOneRef()) {
        m_buffer->truncateAssumingIsolated(m_length);
        m_string = m_buffer.release();
        return;
    }

    m_string = m_buffer->substring(0, m_length);
}

String StringBuilder::reifySubstring(unsigned position, unsigned length) const
{
    ASSERT(m_string.isNull());
    ASSERT(m_buffer);
    unsigned substringLength = std::min(length, m_length - position);
    return m_buffer->substring(position, substringLength);
>>>>>>> miniblink49
}

void StringBuilder::resize(unsigned newSize)
{
<<<<<<< HEAD
    DCHECK_LE(newSize, m_length);
    m_string = m_string.left(newSize);
    m_length = newSize;
    if (hasBuffer()) {
        if (m_is8Bit)
            m_buffer8->resize(newSize);
        else
            m_buffer16->resize(newSize);
    }
}

void StringBuilder::createBuffer8(unsigned addedSize)
{
    DCHECK(!hasBuffer());
    DCHECK(m_is8Bit);
    m_buffer8 = new Buffer8;
    // createBuffer is called right before appending addedSize more bytes. We
    // want to ensure we have enough space to fit m_string plus the added
    // size.
    //
    // We also ensure that we have at least the initialBufferSize of extra space
    // for appending new bytes to avoid future mallocs for appending short
    // strings or single characters. This is a no-op if m_length == 0 since
    // initialBufferSize() is the same as the inline capacity of the vector.
    // This allows doing append(string); append('\0') without extra mallocs.
    m_buffer8->reserveInitialCapacity(m_length + std::max(addedSize, initialBufferSize()));
    m_length = 0;
    append(m_string);
    m_string = String();
}

void StringBuilder::createBuffer16(unsigned addedSize)
{
    DCHECK(m_is8Bit || !hasBuffer());
    Buffer8 buffer8;
    unsigned length = m_length;
    if (m_buffer8) {
        m_buffer8->swap(buffer8);
        delete m_buffer8;
    }
    m_buffer16 = new Buffer16;
    // See createBuffer8's call to reserveInitialCapacity for why we do this.
    m_buffer16->reserveInitialCapacity(m_length + std::max(addedSize, initialBufferSize()));
    m_is8Bit = false;
    m_length = 0;
    if (!buffer8.isEmpty()) {
        append(buffer8.data(), length);
        return;
    }
    append(m_string);
    m_string = String();
}

=======
    // Check newSize < m_length, hence m_length > 0.
    ASSERT(newSize <= m_length);
    if (newSize == m_length)
        return;
    ASSERT(m_length);

    // If there is a buffer, we only need to duplicate it if it has more than one ref.
    if (m_buffer) {
        m_string = String(); // Clear the string to remove the reference to m_buffer if any before checking the reference count of m_buffer.
        if (!m_buffer->hasOneRef()) {
            if (m_buffer->is8Bit())
                allocateBuffer(m_buffer->characters8(), m_buffer->length());
            else
                allocateBuffer(m_buffer->characters16(), m_buffer->length());
        }
        m_length = newSize;
        return;
    }

    // Since m_length && !m_buffer, the string must be valid in m_string, and m_string.length() > 0.
    ASSERT(!m_string.isEmpty());
    ASSERT(m_length == m_string.length());
    ASSERT(newSize < m_string.length());
    m_length = newSize;
    RefPtr<StringImpl> string = m_string.releaseImpl();
    if (string->hasOneRef()) {
        // If we're the only ones with a reference to the string, we can
        // re-purpose the string as m_buffer and continue mutating it.
        m_buffer = string;
    } else {
        // Otherwise, we need to make a copy of the string so that we don't
        // mutate a String that's held elsewhere.
        m_buffer = string->substring(0, m_length);
    }
}

// Allocate a new 8 bit buffer, copying in currentCharacters (these may come from either m_string
// or m_buffer, neither will be reassigned until the copy has completed).
void StringBuilder::allocateBuffer(const LChar* currentCharacters, unsigned requiredLength)
{
    ASSERT(m_is8Bit);
    // Copy the existing data into a new buffer, set result to point to the end of the existing data.
    RefPtr<StringImpl> buffer = StringImpl::createUninitialized(requiredLength, m_bufferCharacters8);
    memcpy(m_bufferCharacters8, currentCharacters, static_cast<size_t>(m_length) * sizeof(LChar)); // This can't overflow.

    // Update the builder state.
    m_buffer = buffer.release();
    m_string = String();
}

// Allocate a new 16 bit buffer, copying in currentCharacters (these may come from either m_string
// or m_buffer,  neither will be reassigned until the copy has completed).
void StringBuilder::allocateBuffer(const UChar* currentCharacters, unsigned requiredLength)
{
    ASSERT(!m_is8Bit);
    // Copy the existing data into a new buffer, set result to point to the end of the existing data.
    RefPtr<StringImpl> buffer = StringImpl::createUninitialized(requiredLength, m_bufferCharacters16);
    memcpy(m_bufferCharacters16, currentCharacters, static_cast<size_t>(m_length) * sizeof(UChar)); // This can't overflow.

    // Update the builder state.
    m_buffer = buffer.release();
    m_string = String();
}

// Allocate a new 16 bit buffer, copying in currentCharacters (which is 8 bit and may come
// from either m_string or m_buffer, neither will be reassigned until the copy has completed).
void StringBuilder::allocateBufferUpConvert(const LChar* currentCharacters, unsigned requiredLength)
{
    ASSERT(m_is8Bit);
    // Copy the existing data into a new buffer, set result to point to the end of the existing data.
    RefPtr<StringImpl> buffer = StringImpl::createUninitialized(requiredLength, m_bufferCharacters16);
    for (unsigned i = 0; i < m_length; ++i)
        m_bufferCharacters16[i] = currentCharacters[i];

    m_is8Bit = false;

    // Update the builder state.
    m_buffer = buffer.release();
    m_string = String();
}

template <>
void StringBuilder::reallocateBuffer<LChar>(unsigned requiredLength)
{
    // If the buffer has only one ref (by this StringBuilder), reallocate it,
    // otherwise fall back to "allocate and copy" method.
    m_string = String();

    ASSERT(m_is8Bit);
    ASSERT(m_buffer->is8Bit());

    if (m_buffer->hasOneRef()) {
        m_buffer = StringImpl::reallocate(m_buffer.release(), requiredLength);
        m_bufferCharacters8 = const_cast<LChar*>(m_buffer->characters8());
    } else
        allocateBuffer(m_buffer->characters8(), requiredLength);
}

template <>
void StringBuilder::reallocateBuffer<UChar>(unsigned requiredLength)
{
    // If the buffer has only one ref (by this StringBuilder), reallocate it,
    // otherwise fall back to "allocate and copy" method.
    m_string = String();

    if (m_buffer->is8Bit()) {
        allocateBufferUpConvert(m_buffer->characters8(), requiredLength);
    } else if (m_buffer->hasOneRef()) {
        m_buffer = StringImpl::reallocate(m_buffer.release(), requiredLength);
        m_bufferCharacters16 = const_cast<UChar*>(m_buffer->characters16());
    } else
        allocateBuffer(m_buffer->characters16(), requiredLength);
}

void StringBuilder::reserveCapacity(unsigned newCapacity)
{
    if (m_buffer) {
        // If there is already a buffer, then grow if necessary.
        if (newCapacity > m_buffer->length()) {
            if (m_buffer->is8Bit())
                reallocateBuffer<LChar>(newCapacity);
            else
                reallocateBuffer<UChar>(newCapacity);
        }
    } else {
        // Grow the string, if necessary.
        if (newCapacity > m_length) {
            if (!m_length) {
                LChar* nullPlaceholder = 0;
                allocateBuffer(nullPlaceholder, newCapacity);
            } else if (m_string.is8Bit())
                allocateBuffer(m_string.characters8(), newCapacity);
            else
                allocateBuffer(m_string.characters16(), newCapacity);
        }
    }
}

// Make 'length' additional capacity be available in m_buffer, update m_string & m_length,
// return a pointer to the newly allocated storage.
template <typename CharType>
ALWAYS_INLINE CharType* StringBuilder::appendUninitialized(unsigned length)
{
    ASSERT(length);

    // Calculate the new size of the builder after appending.
    unsigned requiredLength = length + m_length;
    RELEASE_ASSERT(requiredLength >= length);

    if ((m_buffer) && (requiredLength <= m_buffer->length())) {
        // If the buffer is valid it must be at least as long as the current builder contents!
        ASSERT(m_buffer->length() >= m_length);
        unsigned currentLength = m_length;
        m_string = String();
        m_length = requiredLength;
        return getBufferCharacters<CharType>() + currentLength;
    }

    return appendUninitializedSlow<CharType>(requiredLength);
}

// Make 'length' additional capacity be available in m_buffer, update m_string & m_length,
// return a pointer to the newly allocated storage.
template <typename CharType>
CharType* StringBuilder::appendUninitializedSlow(unsigned requiredLength)
{
    ASSERT(requiredLength);

    if (m_buffer) {
        // If the buffer is valid it must be at least as long as the current builder contents!
        ASSERT(m_buffer->length() >= m_length);

        reallocateBuffer<CharType>(expandedCapacity(capacity(), requiredLength));
    } else {
        ASSERT(m_string.length() == m_length);
        allocateBuffer(m_length ? m_string.getCharacters<CharType>() : 0, expandedCapacity(capacity(), requiredLength));
    }

    CharType* result = getBufferCharacters<CharType>() + m_length;
    m_length = requiredLength;
    return result;
}

>>>>>>> miniblink49
void StringBuilder::append(const UChar* characters, unsigned length)
{
    if (!length)
        return;
<<<<<<< HEAD
    DCHECK(characters);

    // If there's only one char we use append(UChar) instead since it will
    // check for latin1 and avoid converting to 16bit if possible.
    if (length == 1) {
        append(*characters);
        return;
    }

    ensureBuffer16(length);
    m_buffer16->append(characters, length);
    m_length += length;
=======

    ASSERT(characters);

    if (m_is8Bit) {
        if (length == 1 && !(*characters & ~0xff)) {
            // Append as 8 bit character
            LChar lChar = static_cast<LChar>(*characters);
            append(&lChar, 1);
            return;
        }

        // Calculate the new size of the builder after appending.
        unsigned requiredLength = length + m_length;
        RELEASE_ASSERT(requiredLength >= length);

        if (m_buffer) {
            // If the buffer is valid it must be at least as long as the current builder contents!
            ASSERT(m_buffer->length() >= m_length);

            allocateBufferUpConvert(m_buffer->characters8(), expandedCapacity(capacity(), requiredLength));
        } else {
            ASSERT(m_string.length() == m_length);
            allocateBufferUpConvert(m_string.isNull() ? 0 : m_string.characters8(), expandedCapacity(capacity(), requiredLength));
        }

        memcpy(m_bufferCharacters16 + m_length, characters, static_cast<size_t>(length) * sizeof(UChar));
        m_length = requiredLength;
    } else
        memcpy(appendUninitialized<UChar>(length), characters, static_cast<size_t>(length) * sizeof(UChar));
>>>>>>> miniblink49
}

void StringBuilder::append(const LChar* characters, unsigned length)
{
    if (!length)
        return;
<<<<<<< HEAD
    DCHECK(characters);

    if (m_is8Bit) {
        ensureBuffer8(length);
        m_buffer8->append(characters, length);
        m_length += length;
        return;
    }

    ensureBuffer16(length);
    m_buffer16->append(characters, length);
    m_length += length;
}

template <typename IntegerType>
static void appendIntegerInternal(StringBuilder& builder, IntegerType input)
{
    IntegerToStringConverter<IntegerType> converter(input);
    builder.append(converter.characters8(), converter.length());
=======
    ASSERT(characters);

    if (m_is8Bit) {
        LChar* dest = appendUninitialized<LChar>(length);
        if (length > 8)
            memcpy(dest, characters, static_cast<size_t>(length) * sizeof(LChar));
        else {
            const LChar* end = characters + length;
            while (characters < end)
                *(dest++) = *(characters++);
        }
    } else {
        UChar* dest = appendUninitialized<UChar>(length);
        const LChar* end = characters + length;
        while (characters < end)
            *(dest++) = *(characters++);
    }
>>>>>>> miniblink49
}

void StringBuilder::appendNumber(int number)
{
<<<<<<< HEAD
    appendIntegerInternal(*this, number);
=======
    numberToStringSigned<StringBuilder>(number, this);
>>>>>>> miniblink49
}

void StringBuilder::appendNumber(unsigned number)
{
<<<<<<< HEAD
    appendIntegerInternal(*this, number);
=======
    numberToStringUnsigned<StringBuilder>(number, this);
>>>>>>> miniblink49
}

void StringBuilder::appendNumber(long number)
{
<<<<<<< HEAD
    appendIntegerInternal(*this, number);
=======
    numberToStringSigned<StringBuilder>(number, this);
>>>>>>> miniblink49
}

void StringBuilder::appendNumber(unsigned long number)
{
<<<<<<< HEAD
    appendIntegerInternal(*this, number);
=======
    numberToStringUnsigned<StringBuilder>(number, this);
>>>>>>> miniblink49
}

void StringBuilder::appendNumber(long long number)
{
<<<<<<< HEAD
    appendIntegerInternal(*this, number);
=======
    numberToStringSigned<StringBuilder>(number, this);
>>>>>>> miniblink49
}

void StringBuilder::appendNumber(unsigned long long number)
{
<<<<<<< HEAD
    appendIntegerInternal(*this, number);
}

void StringBuilder::appendNumber(double number, unsigned precision)
{
    NumberToStringBuffer buffer;
    append(numberToFixedPrecisionString(number, precision, buffer));
=======
    numberToStringUnsigned<StringBuilder>(number, this);
}

static void expandLCharToUCharInplace(UChar* buffer, size_t length)
{
    const LChar* sourceEnd = reinterpret_cast<LChar*>(buffer) + length;
    UChar* current = buffer + length;
    while (current != buffer)
        *--current = *--sourceEnd;
}

void StringBuilder::appendNumber(double number, unsigned precision, TrailingZerosTruncatingPolicy trailingZerosTruncatingPolicy)
{
    bool truncateTrailingZeros = trailingZerosTruncatingPolicy == TruncateTrailingZeros;
    size_t numberLength;
    if (m_is8Bit) {
        LChar* dest = appendUninitialized<LChar>(NumberToStringBufferLength);
        const char* result = numberToFixedPrecisionString(number, precision, reinterpret_cast<char*>(dest), truncateTrailingZeros);
        numberLength = strlen(result);
    } else {
        UChar* dest = appendUninitialized<UChar>(NumberToStringBufferLength);
        const char* result = numberToFixedPrecisionString(number, precision, reinterpret_cast<char*>(dest), truncateTrailingZeros);
        numberLength = strlen(result);
        expandLCharToUCharInplace(dest, numberLength);
    }
    ASSERT(m_length >= NumberToStringBufferLength);
    // Remove what appendUninitialized added.
    m_length -= NumberToStringBufferLength;
    ASSERT(numberLength <= NumberToStringBufferLength);
    m_length += numberLength;
}

bool StringBuilder::canShrink() const
{
    // Only shrink the buffer if it's less than 80% full. Need to tune this heuristic!
    return m_buffer && m_buffer->length() > (m_length + (m_length >> 2));
}

void StringBuilder::shrinkToFit()
{
    if (!canShrink())
        return;
    if (m_is8Bit)
        reallocateBuffer<LChar>(m_length);
    else
        reallocateBuffer<UChar>(m_length);
    m_string = m_buffer.release();
>>>>>>> miniblink49
}

} // namespace WTF
