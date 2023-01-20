/*
 * (C) 1999 Lars Knoll (knoll@kde.org)
<<<<<<< HEAD
 * Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2012, 2013 Apple Inc.
 * All rights reserved.
=======
 * Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2012, 2013 Apple Inc. All rights reserved.
>>>>>>> miniblink49
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef WTFString_h
#define WTFString_h

// This file would be called String.h, but that conflicts with <string.h>
// on systems without case-sensitive file systems.

<<<<<<< HEAD
#include "wtf/Allocator.h"
#include "wtf/Compiler.h"
=======
>>>>>>> miniblink49
#include "wtf/HashTableDeletedValueType.h"
#include "wtf/WTFExport.h"
#include "wtf/text/ASCIIFastPath.h"
#include "wtf/text/StringImpl.h"
#include "wtf/text/StringView.h"
#include <algorithm>
<<<<<<< HEAD
#include <iosfwd>
=======
>>>>>>> miniblink49

#ifdef __OBJC__
#include <objc/objc.h>
#endif

namespace WTF {

class CString;
struct StringHash;

<<<<<<< HEAD
=======
// Declarations of string operations

WTF_EXPORT int charactersToIntStrict(const LChar*, size_t, bool* ok = 0, int base = 10);
WTF_EXPORT int charactersToIntStrict(const UChar*, size_t, bool* ok = 0, int base = 10);
WTF_EXPORT unsigned charactersToUIntStrict(const LChar*, size_t, bool* ok = 0, int base = 10);
WTF_EXPORT unsigned charactersToUIntStrict(const UChar*, size_t, bool* ok = 0, int base = 10);
WTF_EXPORT int64_t charactersToInt64Strict(const LChar*, size_t, bool* ok = 0, int base = 10);
WTF_EXPORT int64_t charactersToInt64Strict(const UChar*, size_t, bool* ok = 0, int base = 10);
WTF_EXPORT uint64_t charactersToUInt64Strict(const LChar*, size_t, bool* ok = 0, int base = 10);
WTF_EXPORT uint64_t charactersToUInt64Strict(const UChar*, size_t, bool* ok = 0, int base = 10);

WTF_EXPORT int charactersToInt(const LChar*, size_t, bool* ok = 0); // ignores trailing garbage
WTF_EXPORT int charactersToInt(const UChar*, size_t, bool* ok = 0); // ignores trailing garbage
WTF_EXPORT unsigned charactersToUInt(const LChar*, size_t, bool* ok = 0); // ignores trailing garbage
WTF_EXPORT unsigned charactersToUInt(const UChar*, size_t, bool* ok = 0); // ignores trailing garbage
WTF_EXPORT int64_t charactersToInt64(const LChar*, size_t, bool* ok = 0); // ignores trailing garbage
WTF_EXPORT int64_t charactersToInt64(const UChar*, size_t, bool* ok = 0); // ignores trailing garbage
WTF_EXPORT uint64_t charactersToUInt64(const LChar*, size_t, bool* ok = 0); // ignores trailing garbage
WTF_EXPORT uint64_t charactersToUInt64(const UChar*, size_t, bool* ok = 0); // ignores trailing garbage

// FIXME: Like the strict functions above, these give false for "ok" when there is trailing garbage.
// Like the non-strict functions above, these return the value when there is trailing garbage.
// It would be better if these were more consistent with the above functions instead.
WTF_EXPORT double charactersToDouble(const LChar*, size_t, bool* ok = 0);
WTF_EXPORT double charactersToDouble(const UChar*, size_t, bool* ok = 0);
WTF_EXPORT float charactersToFloat(const LChar*, size_t, bool* ok = 0);
WTF_EXPORT float charactersToFloat(const UChar*, size_t, bool* ok = 0);
WTF_EXPORT float charactersToFloat(const LChar*, size_t, size_t& parsedLength);
WTF_EXPORT float charactersToFloat(const UChar*, size_t, size_t& parsedLength);

enum TrailingZerosTruncatingPolicy {
    KeepTrailingZeros,
    TruncateTrailingZeros
};

>>>>>>> miniblink49
enum UTF8ConversionMode {
    LenientUTF8Conversion,
    StrictUTF8Conversion,
    StrictUTF8ConversionReplacingUnpairedSurrogatesWithFFFD
};

<<<<<<< HEAD
#define DISPATCH_CASE_OP(caseSensitivity, op, args)         \
    ((caseSensitivity == TextCaseSensitive)                 \
            ? op args                                       \
            : (caseSensitivity == TextCaseASCIIInsensitive) \
                ? op##IgnoringASCIICase args                \
                : op##IgnoringCase args)
=======
template<bool isSpecialCharacter(UChar), typename CharacterType>
bool isAllSpecialCharacters(const CharacterType*, size_t);
>>>>>>> miniblink49

// You can find documentation about this class in this doc:
// https://docs.google.com/document/d/1kOCUlJdh2WJMJGDf-WoEQhmnjKLaOYRbiHz5TiGJl14/edit?usp=sharing
class WTF_EXPORT String {
<<<<<<< HEAD
    USING_FAST_MALLOC(String);

=======
>>>>>>> miniblink49
public:
    // Construct a null string, distinguishable from an empty string.
    String() { }

    // Construct a string with UTF-16 data.
    String(const UChar* characters, unsigned length);

    // Construct a string by copying the contents of a vector.
    // This method will never create a null string. Vectors with size() == 0
    // will return the empty string.
    // NOTE: This is different from String(vector.data(), vector.size())
    // which will sometimes return a null string when vector.data() is null
    // which can only occur for vectors without inline capacity.
    // See: https://bugs.webkit.org/show_bug.cgi?id=109792
<<<<<<< HEAD
    template <size_t inlineCapacity>
=======
    template<size_t inlineCapacity>
>>>>>>> miniblink49
    explicit String(const Vector<UChar, inlineCapacity>&);

    // Construct a string with UTF-16 data, from a null-terminated source.
    String(const UChar*);
<<<<<<< HEAD
//     String(const char16_t* chars)
//         : String(reinterpret_cast<const UChar*>(chars))
//     {
//     }
=======
>>>>>>> miniblink49

    // Construct a string with latin1 data.
    String(const LChar* characters, unsigned length);
    String(const char* characters, unsigned length);

    // Construct a string with latin1 data, from a null-terminated source.
    String(const LChar* characters);
    String(const char* characters);

    // Construct a string referencing an existing StringImpl.
<<<<<<< HEAD
    String(StringImpl* impl)
        : m_impl(impl)
    {
    }
    String(PassRefPtr<StringImpl> impl)
        : m_impl(impl)
    {
    }

    void swap(String& o) { m_impl.swap(o.m_impl); }

    template <typename CharType>
=======
    String(StringImpl* impl) : m_impl(impl) { }
    String(PassRefPtr<StringImpl> impl) : m_impl(impl) { }

    void swap(String& o) { m_impl.swap(o.m_impl); }

    template<typename CharType>
>>>>>>> miniblink49
    static String adopt(StringBuffer<CharType>& buffer)
    {
        if (!buffer.length())
            return StringImpl::empty();
        return String(buffer.release());
    }

<<<<<<< HEAD
=======
	template<size_t inlineCapacity>
	static String adopt(Vector<LChar, inlineCapacity>& vector)
	{
		if (size_t size = vector.size()) {
			ASSERT(vector.data());
			if (size > std::numeric_limits<unsigned>::max())
				CRASH();
			String ret(vector.data(), size);
			vector.clear();
			return ret;
		}
		return StringImpl::empty();
	}

>>>>>>> miniblink49
    bool isNull() const { return !m_impl; }
    bool isEmpty() const { return !m_impl || !m_impl->length(); }

    StringImpl* impl() const { return m_impl.get(); }
    PassRefPtr<StringImpl> releaseImpl() { return m_impl.release(); }

    unsigned length() const
    {
        if (!m_impl)
            return 0;
        return m_impl->length();
    }

    const LChar* characters8() const
    {
        if (!m_impl)
            return 0;
<<<<<<< HEAD
        DCHECK(m_impl->is8Bit());
=======
        ASSERT(m_impl->is8Bit());
>>>>>>> miniblink49
        return m_impl->characters8();
    }

    const UChar* characters16() const
    {
        if (!m_impl)
            return 0;
<<<<<<< HEAD
        DCHECK(!m_impl->is8Bit());
=======
        ASSERT(!m_impl->is8Bit());
>>>>>>> miniblink49
        return m_impl->characters16();
    }

    // Return characters8() or characters16() depending on CharacterType.
    template <typename CharacterType>
    inline const CharacterType* getCharacters() const;

    bool is8Bit() const { return m_impl->is8Bit(); }

<<<<<<< HEAD
=======
    unsigned sizeInBytes() const
    {
        if (!m_impl)
            return 0;
        return m_impl->length() * (is8Bit() ? sizeof(LChar) : sizeof(UChar));
    }

>>>>>>> miniblink49
    CString ascii() const;
    CString latin1() const;
    CString utf8(UTF8ConversionMode = LenientUTF8Conversion) const;

    UChar operator[](unsigned index) const
    {
        if (!m_impl || index >= m_impl->length())
            return 0;
        return (*m_impl)[index];
    }

    static String number(int);
    static String number(unsigned);
    static String number(long);
    static String number(unsigned long);
    static String number(long long);
    static String number(unsigned long long);

<<<<<<< HEAD
    static String number(double, unsigned precision = 6);
=======
    static String number(double, unsigned precision = 6, TrailingZerosTruncatingPolicy = TruncateTrailingZeros);
>>>>>>> miniblink49

    // Number to String conversion following the ECMAScript definition.
    static String numberToStringECMAScript(double);
    static String numberToStringFixedWidth(double, unsigned decimalPlaces);

<<<<<<< HEAD
    // Find characters.
    size_t find(UChar c, unsigned start = 0) const
    {
        return m_impl ? m_impl->find(c, start) : kNotFound;
    }
    size_t find(LChar c, unsigned start = 0) const
    {
        return m_impl ? m_impl->find(c, start) : kNotFound;
    }
    size_t find(char c, unsigned start = 0) const
    {
        return find(static_cast<LChar>(c), start);
    }
    size_t find(CharacterMatchFunctionPtr matchFunction,
        unsigned start = 0) const
    {
        return m_impl ? m_impl->find(matchFunction, start) : kNotFound;
    }

    // Find substrings.
    size_t find(const StringView& value,
        unsigned start = 0,
        TextCaseSensitivity caseSensitivity = TextCaseSensitive) const
    {
        return m_impl
            ? DISPATCH_CASE_OP(caseSensitivity, m_impl->find, (value, start))
            : kNotFound;
    }

    // Unicode aware case insensitive string matching. Non-ASCII characters might
    // match to ASCII characters. This function is rarely used to implement web
    // platform features.
    size_t findIgnoringCase(const StringView& value, unsigned start = 0) const
    {
        return m_impl ? m_impl->findIgnoringCase(value, start) : kNotFound;
    }

    // ASCII case insensitive string matching.
    size_t findIgnoringASCIICase(const StringView& value, unsigned start = 0) const
    {
        return m_impl ? m_impl->findIgnoringASCIICase(value, start) : kNotFound;
    }

    bool contains(char c) const { return find(c) != kNotFound; }
    bool contains(const StringView& value, TextCaseSensitivity caseSensitivity = TextCaseSensitive) const
    {
        return find(value, 0, caseSensitivity) != kNotFound;
    }

    // Find the last instance of a single character or string.
    size_t reverseFind(UChar c, unsigned start = UINT_MAX) const
    {
        return m_impl ? m_impl->reverseFind(c, start) : kNotFound;
    }
    size_t reverseFind(const StringView& value, unsigned start = UINT_MAX) const
    {
        return m_impl ? m_impl->reverseFind(value, start) : kNotFound;
    }

    UChar32 characterStartingAt(unsigned) const;

    bool startsWith(const StringView& prefix, TextCaseSensitivity caseSensitivity = TextCaseSensitive) const
    {
        return m_impl
            ? DISPATCH_CASE_OP(caseSensitivity, m_impl->startsWith, (prefix))
            : prefix.isEmpty();
    }
    bool startsWith(UChar character) const
    {
        return m_impl ? m_impl->startsWith(character) : false;
    }

    bool endsWith(const StringView& suffix, TextCaseSensitivity caseSensitivity = TextCaseSensitive) const
    {
        return m_impl
            ? DISPATCH_CASE_OP(caseSensitivity, m_impl->endsWith, (suffix))
            : suffix.isEmpty();
    }
    bool endsWith(UChar character) const
    {
        return m_impl ? m_impl->endsWith(character) : false;
    }

    void append(const StringView&);
    void append(LChar);
    void append(char c) { append(static_cast<LChar>(c)); }
    void append(UChar);
    void insert(const StringView&, unsigned pos);

    // TODO(esprehn): replace strangely both modifies this String *and* return a
    // value. It should only do one of those.
    String& replace(UChar pattern, UChar replacement)
    {
        if (m_impl)
            m_impl = m_impl->replace(pattern, replacement);
        return *this;
    }
    String& replace(UChar pattern, const StringView& replacement)
    {
        if (m_impl)
            m_impl = m_impl->replace(pattern, replacement);
        return *this;
    }
    String& replace(const StringView& pattern, const StringView& replacement)
    {
        if (m_impl)
            m_impl = m_impl->replace(pattern, replacement);
        return *this;
    }
    String& replace(unsigned index, unsigned lengthToReplace, const StringView& replacement)
    {
        if (m_impl)
            m_impl = m_impl->replace(index, lengthToReplace, replacement);
        return *this;
    }

    void fill(UChar c)
    {
        if (m_impl)
            m_impl = m_impl->fill(c);
    }

    void ensure16Bit();

    void truncate(unsigned length);
    void remove(unsigned start, unsigned length = 1);
=======
    // Find a single character or string, also with match function & latin1 forms.
    size_t find(UChar c, unsigned start = 0) const
        { return m_impl ? m_impl->find(c, start) : kNotFound; }
    size_t find(LChar c, unsigned start = 0) const
        { return m_impl ? m_impl->find(c, start) : kNotFound; }
    size_t find(char c, unsigned start = 0) const { return find(static_cast<LChar>(c), start); }

    size_t find(const String& str) const
        { return m_impl ? m_impl->find(str.impl()) : kNotFound; }
    size_t find(const String& str, unsigned start) const
        { return m_impl ? m_impl->find(str.impl(), start) : kNotFound; }

    size_t find(CharacterMatchFunctionPtr matchFunction, unsigned start = 0) const
        { return m_impl ? m_impl->find(matchFunction, start) : kNotFound; }
    size_t find(const LChar* str, unsigned start = 0) const
        { return m_impl ? m_impl->find(str, start) : kNotFound; }

    size_t findNextLineStart(unsigned start = 0) const
        { return m_impl ? m_impl->findNextLineStart(start) : kNotFound; }

    // Find the last instance of a single character or string.
    size_t reverseFind(UChar c, unsigned start = UINT_MAX) const
        { return m_impl ? m_impl->reverseFind(c, start) : kNotFound; }
    size_t reverseFind(const String& str, unsigned start = UINT_MAX) const
        { return m_impl ? m_impl->reverseFind(str.impl(), start) : kNotFound; }

    // Case insensitive string matching.
    size_t findIgnoringCase(const LChar* str, unsigned start = 0) const
        { return m_impl ? m_impl->findIgnoringCase(str, start) : kNotFound; }
    size_t findIgnoringCase(const String& str, unsigned start = 0) const
        { return m_impl ? m_impl->findIgnoringCase(str.impl(), start) : kNotFound; }
    size_t reverseFindIgnoringCase(const String& str, unsigned start = UINT_MAX) const
        { return m_impl ? m_impl->reverseFindIgnoringCase(str.impl(), start) : kNotFound; }

    // Wrappers for find & reverseFind adding dynamic sensitivity check.
    size_t find(const LChar* str, unsigned start, TextCaseSensitivity caseSensitivity) const
        { return (caseSensitivity == TextCaseSensitive) ? find(str, start) : findIgnoringCase(str, start); }
    size_t find(const String& str, unsigned start, TextCaseSensitivity caseSensitivity) const
        { return (caseSensitivity == TextCaseSensitive) ? find(str, start) : findIgnoringCase(str, start); }
    size_t reverseFind(const String& str, unsigned start, TextCaseSensitivity caseSensitivity) const
        { return (caseSensitivity == TextCaseSensitive) ? reverseFind(str, start) : reverseFindIgnoringCase(str, start); }

    Vector<UChar> charactersWithNullTermination() const;
    unsigned copyTo(UChar* buffer, unsigned pos, unsigned maxLength) const;

    template<size_t inlineCapacity>
    void appendTo(Vector<UChar, inlineCapacity>&, unsigned pos = 0, unsigned len = UINT_MAX) const;

    template<typename BufferType>
    void appendTo(BufferType&, unsigned pos = 0, unsigned len = UINT_MAX) const;

    template<size_t inlineCapacity>
    void prependTo(Vector<UChar, inlineCapacity>&, unsigned pos = 0, unsigned len = UINT_MAX) const;

    UChar32 characterStartingAt(unsigned) const;
    template<typename CharacterType>
    bool contains(CharacterType c) const { return find(c) != kNotFound; }
    bool contains(const LChar* str, TextCaseSensitivity caseSensitivity = TextCaseSensitive) const { return find(str, 0, caseSensitivity) != kNotFound; }
    bool contains(const String& str, TextCaseSensitivity caseSensitivity = TextCaseSensitive) const { return find(str, 0, caseSensitivity) != kNotFound; }

    bool startsWith(const String& s, TextCaseSensitivity caseSensitivity = TextCaseSensitive) const
        { return m_impl ? m_impl->startsWith(s.impl(), caseSensitivity) : s.isEmpty(); }
    bool startsWith(UChar character) const
        { return m_impl ? m_impl->startsWith(character) : false; }
    template<unsigned matchLength>
    bool startsWith(const char (&prefix)[matchLength], TextCaseSensitivity caseSensitivity = TextCaseSensitive) const
        { return m_impl ? m_impl->startsWith<matchLength>(prefix, caseSensitivity) : !matchLength; }

    bool endsWith(const String& s, TextCaseSensitivity caseSensitivity = TextCaseSensitive) const
        { return m_impl ? m_impl->endsWith(s.impl(), caseSensitivity) : s.isEmpty(); }
    bool endsWith(UChar character) const
        { return m_impl ? m_impl->endsWith(character) : false; }
    template<unsigned matchLength>
    bool endsWith(const char (&prefix)[matchLength], TextCaseSensitivity caseSensitivity = TextCaseSensitive) const
        { return m_impl ? m_impl->endsWith<matchLength>(prefix, caseSensitivity) : !matchLength; }

    void append(const String&);
    void append(LChar);
    void append(char c) { append(static_cast<LChar>(c)); }
    void append(UChar);
    void append(const LChar*, unsigned length);
    void append(const char* charactersToAppend, unsigned length) { append(reinterpret_cast<const LChar*>(charactersToAppend), length); }
    void append(const UChar*, unsigned length);
    void insert(const String&, unsigned pos);
    void insert(const LChar*, unsigned length, unsigned pos);
    void insert(const UChar*, unsigned length, unsigned pos);

    String& replace(UChar a, UChar b) { if (m_impl) m_impl = m_impl->replace(a, b); return *this; }
    String& replace(UChar a, const String& b) { if (m_impl) m_impl = m_impl->replace(a, b.impl()); return *this; }
    String& replace(const String& a, const String& b) { if (m_impl) m_impl = m_impl->replace(a.impl(), b.impl()); return *this; }
    String& replace(unsigned index, unsigned len, const String& b) { if (m_impl) m_impl = m_impl->replace(index, len, b.impl()); return *this; }

    template<unsigned charactersCount>
    ALWAYS_INLINE String& replaceWithLiteral(UChar a, const char (&characters)[charactersCount])
    {
        if (m_impl)
            m_impl = m_impl->replace(a, characters, charactersCount - 1);

        return *this;
    }

    void fill(UChar c) { if (m_impl) m_impl = m_impl->fill(c); }

    void ensure16Bit();

    void truncate(unsigned len);
    void remove(unsigned pos, int len = 1);
>>>>>>> miniblink49

    String substring(unsigned pos, unsigned len = UINT_MAX) const;
    String left(unsigned len) const { return substring(0, len); }
    String right(unsigned len) const { return substring(length() - len, len); }

<<<<<<< HEAD
    // Returns a lowercase/uppercase version of the string. These functions might
    // convert non-ASCII characters to ASCII characters. For example, lower() for
    // U+212A is 'k', upper() for U+017F is 'S'.
    // These functions are rarely used to implement web platform features.
=======
    StringView createView() const { return StringView(impl()); }
    StringView createView(unsigned offset, unsigned length) const { return StringView(impl(), offset, length); }

    // Returns a lowercase/uppercase version of the string
>>>>>>> miniblink49
    String lower() const;
    String upper() const;

    String lower(const AtomicString& localeIdentifier) const;
    String upper(const AtomicString& localeIdentifier) const;

    String stripWhiteSpace() const;
    String stripWhiteSpace(IsWhiteSpaceFunctionPtr) const;
<<<<<<< HEAD
    String simplifyWhiteSpace(StripBehavior = StripExtraWhiteSpace) const;
    String simplifyWhiteSpace(IsWhiteSpaceFunctionPtr, StripBehavior = StripExtraWhiteSpace) const;

    String removeCharacters(CharacterMatchFunctionPtr) const;
    template <bool isSpecialCharacter(UChar)>
    bool isAllSpecialCharacters() const;
=======
    String simplifyWhiteSpace(StripBehavior stripBehavior = StripExtraWhiteSpace) const;
    String simplifyWhiteSpace(IsWhiteSpaceFunctionPtr, StripBehavior stripBehavior = StripExtraWhiteSpace) const;

    String removeCharacters(CharacterMatchFunctionPtr) const;
    template<bool isSpecialCharacter(UChar)> bool isAllSpecialCharacters() const;
>>>>>>> miniblink49

    // Return the string with case folded for case insensitive comparison.
    String foldCase() const;

<<<<<<< HEAD
    // Takes a printf format and args and prints into a String.
    PRINTF_FORMAT(1, 2)
    static String format(const char* format, ...);
=======
    static String format(const char *, ...) WTF_ATTRIBUTE_PRINTF(1, 2);
>>>>>>> miniblink49

    // Returns an uninitialized string. The characters needs to be written
    // into the buffer returned in data before the returned string is used.
    // Failure to do this will have unpredictable results.
<<<<<<< HEAD
    static String createUninitialized(unsigned length, UChar*& data)
    {
        return StringImpl::createUninitialized(length, data);
    }
    static String createUninitialized(unsigned length, LChar*& data)
    {
        return StringImpl::createUninitialized(length, data);
    }

    void split(const StringView& separator,
        bool allowEmptyEntries,
        Vector<String>& result) const;
    void split(const StringView& separator, Vector<String>& result) const
    {
        split(separator, false, result);
    }
    void split(UChar separator,
        bool allowEmptyEntries,
        Vector<String>& result) const;
=======
    static String createUninitialized(unsigned length, UChar*& data) { return StringImpl::createUninitialized(length, data); }
    static String createUninitialized(unsigned length, LChar*& data) { return StringImpl::createUninitialized(length, data); }

    void split(const String& separator, bool allowEmptyEntries, Vector<String>& result) const;
    void split(const String& separator, Vector<String>& result) const
    {
        split(separator, false, result);
    }
    void split(UChar separator, bool allowEmptyEntries, Vector<String>& result) const;
>>>>>>> miniblink49
    void split(UChar separator, Vector<String>& result) const
    {
        split(separator, false, result);
    }

<<<<<<< HEAD
    // Copy characters out of the string. See StringImpl.h for detailed docs.
    unsigned copyTo(UChar* buffer, unsigned start, unsigned maxLength) const
    {
        return m_impl ? m_impl->copyTo(buffer, start, maxLength) : 0;
    }
    Vector<UChar> charactersWithNullTermination() const;
    template <typename BufferType>
    void appendTo(BufferType&,
        unsigned start = 0,
        unsigned length = UINT_MAX) const;
    template <typename BufferType>
    void prependTo(BufferType&,
        unsigned start = 0,
        unsigned length = UINT_MAX) const;

    // Convert the string into a number.

=======
>>>>>>> miniblink49
    int toIntStrict(bool* ok = 0, int base = 10) const;
    unsigned toUIntStrict(bool* ok = 0, int base = 10) const;
    int64_t toInt64Strict(bool* ok = 0, int base = 10) const;
    uint64_t toUInt64Strict(bool* ok = 0, int base = 10) const;

    int toInt(bool* ok = 0) const;
    unsigned toUInt(bool* ok = 0) const;
    int64_t toInt64(bool* ok = 0) const;
    uint64_t toUInt64(bool* ok = 0) const;

<<<<<<< HEAD
    // FIXME: Like the strict functions above, these give false for "ok" when
    // there is trailing garbage.  Like the non-strict functions above, these
    // return the value when there is trailing garbage.  It would be better if
    // these were more consistent with the above functions instead.
=======
    // FIXME: Like the strict functions above, these give false for "ok" when there is trailing garbage.
    // Like the non-strict functions above, these return the value when there is trailing garbage.
    // It would be better if these were more consistent with the above functions instead.
>>>>>>> miniblink49
    double toDouble(bool* ok = 0) const;
    float toFloat(bool* ok = 0) const;

    String isolatedCopy() const;
    bool isSafeToSendToAnotherThread() const;

<<<<<<< HEAD
#ifdef __OBJC__
    String(NSString*);

    // This conversion maps null string to "", which loses the meaning of null
    // string, but we need this mapping because AppKit crashes when passed nil
    // NSStrings.
    operator NSString*() const
    {
        if (!m_impl)
            return @"";
        return *m_impl;
    }
#endif

    static String make8BitFrom16BitSource(const UChar*, size_t);
    template <size_t inlineCapacity>
=======
#if USE(CF)
    String(CFStringRef);
    RetainPtr<CFStringRef> createCFString() const;
#endif

#ifdef __OBJC__
    String(NSString*);

    // This conversion maps NULL to "", which loses the meaning of NULL, but we
    // need this mapping because AppKit crashes when passed nil NSStrings.
    operator NSString*() const { if (!m_impl) return @""; return *m_impl; }
#endif

    static String make8BitFrom16BitSource(const UChar*, size_t);
    template<size_t inlineCapacity>
>>>>>>> miniblink49
    static String make8BitFrom16BitSource(const Vector<UChar, inlineCapacity>& buffer)
    {
        return make8BitFrom16BitSource(buffer.data(), buffer.size());
    }

    static String make16BitFrom8BitSource(const LChar*, size_t);

    // String::fromUTF8 will return a null string if
    // the input data contains invalid UTF-8 sequences.
    static String fromUTF8(const LChar*, size_t);
    static String fromUTF8(const LChar*);
<<<<<<< HEAD
    static String fromUTF8(const char* s, size_t length)
    {
        return fromUTF8(reinterpret_cast<const LChar*>(s), length);
    }
    static String fromUTF8(const char* s)
    {
        return fromUTF8(reinterpret_cast<const LChar*>(s));
    }
    static String fromUTF8(const CString&);

    // Tries to convert the passed in string to UTF-8, but will fall back to
    // Latin-1 if the string is not valid UTF-8.
    static String fromUTF8WithLatin1Fallback(const LChar*, size_t);
    static String fromUTF8WithLatin1Fallback(const char* s, size_t length)
    {
        return fromUTF8WithLatin1Fallback(reinterpret_cast<const LChar*>(s), length);
    }

    bool containsOnlyASCII() const
    {
        return !m_impl || m_impl->containsOnlyASCII();
    }
    bool containsOnlyLatin1() const;
    bool containsOnlyWhitespace() const
    {
        return !m_impl || m_impl->containsOnlyWhitespace();
    }

    size_t charactersSizeInBytes() const
    {
        return m_impl ? m_impl->charactersSizeInBytes() : 0;
    }

    // Hash table deleted values, which are only constructed and never copied or
    // destroyed.
    String(WTF::HashTableDeletedValueType)
        : m_impl(WTF::HashTableDeletedValue)
    {
    }
    bool isHashTableDeletedValue() const
    {
        return m_impl.isHashTableDeletedValue();
    }

#ifndef NDEBUG
    // For use in the debugger.
    void show() const;
#endif

private:
    typedef struct ImplicitConversionFromWTFStringToBoolDisallowed*(
        String::*UnspecifiedBoolType);
    operator UnspecifiedBoolType() const;

    template <typename CharacterType>
=======
    static String fromUTF8(const char* s, size_t length) { return fromUTF8(reinterpret_cast<const LChar*>(s), length); }
    static String fromUTF8(const char* s) { return fromUTF8(reinterpret_cast<const LChar*>(s)); }
    static String fromUTF8(const CString&);

    // Tries to convert the passed in string to UTF-8, but will fall back to Latin-1 if the string is not valid UTF-8.
    static String fromUTF8WithLatin1Fallback(const LChar*, size_t);
    static String fromUTF8WithLatin1Fallback(const char* s, size_t length) { return fromUTF8WithLatin1Fallback(reinterpret_cast<const LChar*>(s), length); }

    bool containsOnlyASCII() const;
    bool containsOnlyLatin1() const;
    bool containsOnlyWhitespace() const { return !m_impl || m_impl->containsOnlyWhitespace(); }

    // Hash table deleted values, which are only constructed and never copied or destroyed.
    String(WTF::HashTableDeletedValueType) : m_impl(WTF::HashTableDeletedValue) { }
    bool isHashTableDeletedValue() const { return m_impl.isHashTableDeletedValue(); }

#ifndef NDEBUG
    void show() const;
#endif

    // Workaround for a compiler bug. Use operator[] instead.
    UChar characterAt(unsigned index) const
    {
        if (!m_impl || index >= m_impl->length())
            return 0;
        return (*m_impl)[index];
    }

private:
    typedef struct ImplicitConversionFromWTFStringToBoolDisallowed* (String::*UnspecifiedBoolType);
    operator UnspecifiedBoolType() const;

    template <typename CharacterType>
    void removeInternal(const CharacterType*, unsigned, int);

    template <typename CharacterType>
>>>>>>> miniblink49
    void appendInternal(CharacterType);

    RefPtr<StringImpl> m_impl;
};

<<<<<<< HEAD
#undef DISPATCH_CASE_OP

inline bool operator==(const String& a, const String& b)
{
    // We don't use equalStringView here since we want the isAtomic() fast path
    // inside WTF::equal.
    return equal(a.impl(), b.impl());
}
inline bool operator==(const String& a, const char* b)
{
    return equalStringView(a, b);
}
inline bool operator==(const char* a, const String& b)
{
    return b == a;
}

inline bool operator!=(const String& a, const String& b)
{
    return !(a == b);
}
inline bool operator!=(const String& a, const char* b)
{
    return !(a == b);
}
inline bool operator!=(const char* a, const String& b)
{
    return !(a == b);
}

inline bool equalPossiblyIgnoringCase(const String& a,
    const String& b,
    bool ignoreCase)
=======
inline bool operator==(const String& a, const String& b) { return equal(a.impl(), b.impl()); }
inline bool operator==(const String& a, const LChar* b) { return equal(a.impl(), b); }
inline bool operator==(const String& a, const char* b) { return equal(a.impl(), reinterpret_cast<const LChar*>(b)); }
inline bool operator==(const LChar* a, const String& b) { return equal(a, b.impl()); }
inline bool operator==(const char* a, const String& b) { return equal(reinterpret_cast<const LChar*>(a), b.impl()); }
template<size_t inlineCapacity>
inline bool operator==(const Vector<char, inlineCapacity>& a, const String& b) { return equal(b.impl(), a.data(), a.size()); }
template<size_t inlineCapacity>
inline bool operator==(const String& a, const Vector<char, inlineCapacity>& b) { return b == a; }


inline bool operator!=(const String& a, const String& b) { return !equal(a.impl(), b.impl()); }
inline bool operator!=(const String& a, const LChar* b) { return !equal(a.impl(), b); }
inline bool operator!=(const String& a, const char* b) { return !equal(a.impl(), reinterpret_cast<const LChar*>(b)); }
inline bool operator!=(const LChar* a, const String& b) { return !equal(a, b.impl()); }
inline bool operator!=(const char* a, const String& b) { return !equal(reinterpret_cast<const LChar*>(a), b.impl()); }
template<size_t inlineCapacity>
inline bool operator!=(const Vector<char, inlineCapacity>& a, const String& b) { return !(a == b); }
template<size_t inlineCapacity>
inline bool operator!=(const String& a, const Vector<char, inlineCapacity>& b) { return b != a; }

inline bool equalIgnoringCase(const String& a, const String& b) { return equalIgnoringCase(a.impl(), b.impl()); }
inline bool equalIgnoringCase(const String& a, const LChar* b) { return equalIgnoringCase(a.impl(), b); }
inline bool equalIgnoringCase(const String& a, const char* b) { return equalIgnoringCase(a.impl(), reinterpret_cast<const LChar*>(b)); }
inline bool equalIgnoringCase(const LChar* a, const String& b) { return equalIgnoringCase(a, b.impl()); }
inline bool equalIgnoringCase(const char* a, const String& b) { return equalIgnoringCase(reinterpret_cast<const LChar*>(a), b.impl()); }

inline bool equalPossiblyIgnoringCase(const String& a, const String& b, bool ignoreCase)
>>>>>>> miniblink49
{
    return ignoreCase ? equalIgnoringCase(a, b) : (a == b);
}

<<<<<<< HEAD
inline bool equalIgnoringNullity(const String& a, const String& b)
{
    return equalIgnoringNullity(a.impl(), b.impl());
}

template <size_t inlineCapacity>
inline bool equalIgnoringNullity(const Vector<UChar, inlineCapacity>& a,
    const String& b)
{
    return equalIgnoringNullity(a, b.impl());
}

inline bool operator!(const String& str)
{
    return str.isNull();
}

inline void swap(String& a, String& b)
{
    a.swap(b);
}

// Definitions of string operations

template <size_t inlineCapacity>
String::String(const Vector<UChar, inlineCapacity>& vector)
    : m_impl(vector.size() ? StringImpl::create(vector.data(), vector.size())
                           : StringImpl::empty())
{
}

template <>
inline const LChar* String::getCharacters<LChar>() const
{
    DCHECK(is8Bit());
    return characters8();
}

template <>
inline const UChar* String::getCharacters<UChar>() const
{
    DCHECK(!is8Bit());
=======
inline bool equalIgnoringNullity(const String& a, const String& b) { return equalIgnoringNullity(a.impl(), b.impl()); }

template<size_t inlineCapacity>
inline bool equalIgnoringNullity(const Vector<UChar, inlineCapacity>& a, const String& b) { return equalIgnoringNullity(a, b.impl()); }

inline bool operator!(const String& str) { return str.isNull(); }

inline void swap(String& a, String& b) { a.swap(b); }

// Definitions of string operations

template<size_t inlineCapacity>
String::String(const Vector<UChar, inlineCapacity>& vector)
    : m_impl(vector.size() ? StringImpl::create(vector.data(), vector.size()) : StringImpl::empty())
{
}

template<>
inline const LChar* String::getCharacters<LChar>() const
{
    ASSERT(is8Bit());
    return characters8();
}

template<>
inline const UChar* String::getCharacters<UChar>() const
{
    ASSERT(!is8Bit());
>>>>>>> miniblink49
    return characters16();
}

inline bool String::containsOnlyLatin1() const
{
    if (isEmpty())
        return true;

    if (is8Bit())
        return true;

    const UChar* characters = characters16();
    UChar ored = 0;
    for (size_t i = 0; i < m_impl->length(); ++i)
        ored |= characters[i];
    return !(ored & 0xFF00);
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifdef __OBJC__
// This is for situations in WebKit where the long standing behavior has been
// "nil if empty", so we try to maintain longstanding behavior for the sake of
// entrenched clients
<<<<<<< HEAD
inline NSString* nsStringNilIfEmpty(const String& str)
{
    return str.isEmpty() ? nil : (NSString*)str;
}
#endif

=======
inline NSString* nsStringNilIfEmpty(const String& str) {  return str.isEmpty() ? nil : (NSString*)str; }
#endif

inline bool String::containsOnlyASCII() const
{
    if (isEmpty())
        return true;

    if (is8Bit())
        return charactersAreAllASCII(characters8(), m_impl->length());

    return charactersAreAllASCII(characters16(), m_impl->length());
}

>>>>>>> miniblink49
WTF_EXPORT int codePointCompare(const String&, const String&);

inline bool codePointCompareLessThan(const String& a, const String& b)
{
    return codePointCompare(a.impl(), b.impl()) < 0;
}

<<<<<<< HEAD
WTF_EXPORT int codePointCompareIgnoringASCIICase(const String&, const char*);

template <bool isSpecialCharacter(UChar)>
inline bool String::isAllSpecialCharacters() const
{
    return StringView(*this).isAllSpecialCharacters<isSpecialCharacter>();
}

template <typename BufferType>
void String::appendTo(BufferType& result,
    unsigned position,
    unsigned length) const
{
    if (!m_impl)
        return;
    m_impl->appendTo(result, position, length);
}

template <typename BufferType>
void String::prependTo(BufferType& result,
    unsigned position,
    unsigned length) const
{
    if (!m_impl)
        return;
    m_impl->prependTo(result, position, length);
}

// StringHash is the default hash for String
template <typename T>
struct DefaultHash;
template <>
struct DefaultHash<String> {
=======
template<size_t inlineCapacity>
inline void append(Vector<UChar, inlineCapacity>& vector, const String& string)
{
    unsigned length = string.length();
    if (!length)
        return;
    if (string.is8Bit()) {
        const LChar* characters8 = string.characters8();
        vector.reserveCapacity(vector.size() + length);
        for (size_t i = 0; i < length; ++i)
            vector.uncheckedAppend(characters8[i]);
    } else {
        vector.append(string.characters16(), length);
    }
}

template<bool isSpecialCharacter(UChar), typename CharacterType>
inline bool isAllSpecialCharacters(const CharacterType* characters, size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        if (!isSpecialCharacter(characters[i]))
            return false;
    }
    return true;
}

template<bool isSpecialCharacter(UChar)>
inline bool String::isAllSpecialCharacters() const
{
    size_t len = length();

    if (!len)
        return true;

    if (is8Bit())
        return WTF::isAllSpecialCharacters<isSpecialCharacter, LChar>(characters8(), len);
    return WTF::isAllSpecialCharacters<isSpecialCharacter, UChar>(characters16(), len);
}

template<size_t inlineCapacity>
inline void String::appendTo(Vector<UChar, inlineCapacity>& result, unsigned pos, unsigned len) const
{
    unsigned numberOfCharactersToCopy = std::min(len, length() - pos);
    if (!numberOfCharactersToCopy)
        return;
    result.reserveCapacity(result.size() + numberOfCharactersToCopy);
    if (is8Bit()) {
        const LChar* characters8 = m_impl->characters8();
        for (size_t i = 0; i < numberOfCharactersToCopy; ++i)
            result.uncheckedAppend(characters8[pos + i]);
    } else {
        const UChar* characters16 = m_impl->characters16();
        result.append(characters16 + pos, numberOfCharactersToCopy);
    }
}

template<typename BufferType>
inline void String::appendTo(BufferType& result, unsigned pos, unsigned len) const
{
    unsigned numberOfCharactersToCopy = std::min(len, length() - pos);
    if (!numberOfCharactersToCopy)
        return;
    if (is8Bit())
        result.append(m_impl->characters8() + pos, numberOfCharactersToCopy);
    else
        result.append(m_impl->characters16() + pos, numberOfCharactersToCopy);
}

template<size_t inlineCapacity>
inline void String::prependTo(Vector<UChar, inlineCapacity>& result, unsigned pos, unsigned len) const
{
    unsigned numberOfCharactersToCopy = std::min(len, length() - pos);
    if (!numberOfCharactersToCopy)
        return;
    if (is8Bit()) {
        size_t oldSize = result.size();
        result.resize(oldSize + numberOfCharactersToCopy);
        memmove(result.data() + numberOfCharactersToCopy, result.data(), oldSize * sizeof(UChar));
        StringImpl::copyChars(result.data(), m_impl->characters8() + pos, numberOfCharactersToCopy);
    } else {
        result.prepend(m_impl->characters16() + pos, numberOfCharactersToCopy);
    }
}

// StringHash is the default hash for String
template<typename T> struct DefaultHash;
template<> struct DefaultHash<String> {
>>>>>>> miniblink49
    typedef StringHash Hash;
};

// Shared global empty string.
WTF_EXPORT const String& emptyString();
WTF_EXPORT const String& emptyString16Bit();
WTF_EXPORT extern const String& xmlnsWithColon;

<<<<<<< HEAD
// Pretty printer for gtest and base/logging.*.  It prepends and appends
// double-quotes, and escapes chracters other than ASCII printables.
WTF_EXPORT std::ostream& operator<<(std::ostream&, const String&);

inline StringView::StringView(const String& string,
    unsigned offset,
    unsigned length)
    : StringView(string.impl(), offset, length)
{
}
inline StringView::StringView(const String& string, unsigned offset)
    : StringView(string.impl(), offset)
{
}
inline StringView::StringView(const String& string)
    : StringView(string.impl())
{
}

=======
>>>>>>> miniblink49
} // namespace WTF

WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(String);

using WTF::CString;
<<<<<<< HEAD
=======
using WTF::KeepTrailingZeros;
>>>>>>> miniblink49
using WTF::StrictUTF8Conversion;
using WTF::StrictUTF8ConversionReplacingUnpairedSurrogatesWithFFFD;
using WTF::String;
using WTF::emptyString;
using WTF::emptyString16Bit;
<<<<<<< HEAD
using WTF::charactersAreAllASCII;
using WTF::equal;
using WTF::find;
using WTF::isSpaceOrNewline;
=======
using WTF::append;
using WTF::charactersAreAllASCII;
using WTF::charactersToIntStrict;
using WTF::charactersToUIntStrict;
using WTF::charactersToInt64Strict;
using WTF::charactersToUInt64Strict;
using WTF::charactersToInt;
using WTF::charactersToUInt;
using WTF::charactersToInt64;
using WTF::charactersToUInt64;
using WTF::charactersToDouble;
using WTF::charactersToFloat;
using WTF::equal;
using WTF::equalIgnoringCase;
using WTF::find;
using WTF::isAllSpecialCharacters;
using WTF::isSpaceOrNewline;
using WTF::reverseFind;
>>>>>>> miniblink49

#include "wtf/text/AtomicString.h"
#endif // WTFString_h
