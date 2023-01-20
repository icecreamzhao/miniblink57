/*
    Copyright (C) 2004, 2005, 2006, 2007, 2008 Apple Inc. All rights reserved.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef SegmentedString_h
#define SegmentedString_h

#include "platform/PlatformExport.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
=======
>>>>>>> miniblink49
#include "wtf/Deque.h"
#include "wtf/text/StringBuilder.h"
#include "wtf/text/TextPosition.h"
#include "wtf/text/WTFString.h"

namespace blink {

class SegmentedString;

class PLATFORM_EXPORT SegmentedSubstring {
<<<<<<< HEAD
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

=======
>>>>>>> miniblink49
public:
    SegmentedSubstring()
        : m_length(0)
        , m_doNotExcludeLineNumbers(true)
        , m_is8Bit(false)
    {
        m_data.string16Ptr = 0;
    }

    SegmentedSubstring(const String& str)
        : m_length(str.length())
        , m_doNotExcludeLineNumbers(true)
        , m_string(str)
    {
        if (m_length) {
            if (m_string.is8Bit()) {
                m_is8Bit = true;
                m_data.string8Ptr = m_string.characters8();
            } else {
                m_is8Bit = false;
                m_data.string16Ptr = m_string.characters16();
            }
        } else {
            m_is8Bit = false;
<<<<<<< HEAD
            m_data.string8Ptr = nullptr;
        }
    }

    void clear()
    {
        m_length = 0;
        m_data.string16Ptr = nullptr;
        m_is8Bit = false;
    }
=======
        }
    }

    void clear() { m_length = 0; m_data.string16Ptr = 0; m_is8Bit = false;}
>>>>>>> miniblink49

    bool is8Bit() { return m_is8Bit; }

    bool excludeLineNumbers() const { return !m_doNotExcludeLineNumbers; }
    bool doNotExcludeLineNumbers() const { return m_doNotExcludeLineNumbers; }

    void setExcludeLineNumbers() { m_doNotExcludeLineNumbers = false; }

<<<<<<< HEAD
    int numberOfCharactersConsumed() const
    {
        return m_string.length() - m_length;
    }
=======
    int numberOfCharactersConsumed() const { return m_string.length() - m_length; }
>>>>>>> miniblink49

    void appendTo(StringBuilder& builder) const
    {
        int offset = m_string.length() - m_length;

        if (!offset) {
            if (m_length)
                builder.append(m_string);
        } else {
            builder.append(m_string.substring(offset, m_length));
        }
    }

<<<<<<< HEAD
    bool pushIfPossible(UChar c)
    {
        if (!m_length)
            return false;

        if (m_is8Bit) {
            if (m_data.string8Ptr == m_string.characters8())
                return false;

            if (*(m_data.string8Ptr - 1) != c)
                return false;

            --m_data.string8Ptr;
            ++m_length;
            return true;
        }

        if (m_data.string16Ptr == m_string.characters16())
            return false;

        if (*(m_data.string16Ptr - 1) != c)
            return false;

        --m_data.string16Ptr;
        ++m_length;
        return true;
    }

    UChar getCurrentChar8() { return *m_data.string8Ptr; }

=======
    UChar getCurrentChar8()
    {
        return *m_data.string8Ptr;
    }

>>>>>>> miniblink49
    UChar getCurrentChar16()
    {
        return m_data.string16Ptr ? *m_data.string16Ptr : 0;
    }

    UChar incrementAndGetCurrentChar8()
    {
        ASSERT(m_data.string8Ptr);
        return *++m_data.string8Ptr;
    }

    UChar incrementAndGetCurrentChar16()
    {
        ASSERT(m_data.string16Ptr);
        return *++m_data.string16Ptr;
    }

    String currentSubString(unsigned length)
    {
        int offset = m_string.length() - m_length;
        return m_string.substring(offset, length);
    }

    ALWAYS_INLINE UChar getCurrentChar()
    {
        ASSERT(m_length);
        if (is8Bit())
            return getCurrentChar8();
        return getCurrentChar16();
    }

    ALWAYS_INLINE UChar incrementAndGetCurrentChar()
    {
        ASSERT(m_length);
        if (is8Bit())
            return incrementAndGetCurrentChar8();
        return incrementAndGetCurrentChar16();
    }

<<<<<<< HEAD
    ALWAYS_INLINE bool haveOneCharacterLeft() const { return m_length == 1; }

    ALWAYS_INLINE void decrementLength() { --m_length; }

    ALWAYS_INLINE int length() const { return m_length; }

private:
=======
public:
>>>>>>> miniblink49
    union {
        const LChar* string8Ptr;
        const UChar* string16Ptr;
    } m_data;
    int m_length;
<<<<<<< HEAD
=======

private:
>>>>>>> miniblink49
    bool m_doNotExcludeLineNumbers;
    bool m_is8Bit;
    String m_string;
};

class PLATFORM_EXPORT SegmentedString {
<<<<<<< HEAD
    DISALLOW_NEW();

public:
    SegmentedString()
        : m_currentChar(0)
=======
public:
    SegmentedString()
        : m_pushedChar1(0)
        , m_pushedChar2(0)
        , m_currentChar(0)
>>>>>>> miniblink49
        , m_numberOfCharactersConsumedPriorToCurrentString(0)
        , m_numberOfCharactersConsumedPriorToCurrentLine(0)
        , m_currentLine(0)
        , m_closed(false)
        , m_empty(true)
        , m_fastPathFlags(NoFastPath)
        , m_advanceFunc(&SegmentedString::advanceEmpty)
        , m_advanceAndUpdateLineNumberFunc(&SegmentedString::advanceEmpty)
    {
    }

    SegmentedString(const String& str)
<<<<<<< HEAD
        : m_currentString(str)
=======
        : m_pushedChar1(0)
        , m_pushedChar2(0)
        , m_currentString(str)
>>>>>>> miniblink49
        , m_currentChar(0)
        , m_numberOfCharactersConsumedPriorToCurrentString(0)
        , m_numberOfCharactersConsumedPriorToCurrentLine(0)
        , m_currentLine(0)
        , m_closed(false)
        , m_empty(!str.length())
        , m_fastPathFlags(NoFastPath)
    {
<<<<<<< HEAD
        if (m_currentString.length())
=======
        if (m_currentString.m_length)
>>>>>>> miniblink49
            m_currentChar = m_currentString.getCurrentChar();
        updateAdvanceFunctionPointers();
    }

    void clear();
    void close();

    void append(const SegmentedString&);
<<<<<<< HEAD
    enum class PrependType {
        NewInput = 0,
        Unconsume = 1,
    };
    void prepend(const SegmentedString&, PrependType);

    bool excludeLineNumbers() const
    {
        return m_currentString.excludeLineNumbers();
    }
    void setExcludeLineNumbers();

    void push(UChar);
=======
    void prepend(const SegmentedString&);

    bool excludeLineNumbers() const { return m_currentString.excludeLineNumbers(); }
    void setExcludeLineNumbers();

    void push(UChar c)
    {
        if (!m_pushedChar1) {
            m_pushedChar1 = c;
            m_currentChar = m_pushedChar1 ? m_pushedChar1 : m_currentString.getCurrentChar();
            updateSlowCaseFunctionPointers();
        } else {
            ASSERT(!m_pushedChar2);
            m_pushedChar2 = c;
        }
    }
>>>>>>> miniblink49

    bool isEmpty() const { return m_empty; }
    unsigned length() const;

    bool isClosed() const { return m_closed; }

    enum LookAheadResult {
        DidNotMatch,
        DidMatch,
        NotEnoughCharacters,
    };

<<<<<<< HEAD
    LookAheadResult lookAhead(const String& string)
    {
        return lookAheadInline(string, TextCaseSensitive);
    }
    LookAheadResult lookAheadIgnoringCase(const String& string)
    {
        return lookAheadInline(string, TextCaseASCIIInsensitive);
    }
=======
    LookAheadResult lookAhead(const String& string) { return lookAheadInline(string, TextCaseSensitive); }
    LookAheadResult lookAheadIgnoringCase(const String& string) { return lookAheadInline(string, TextCaseInsensitive); }
>>>>>>> miniblink49

    void advance()
    {
        if (m_fastPathFlags & Use8BitAdvance) {
<<<<<<< HEAD
            m_currentChar = m_currentString.incrementAndGetCurrentChar8();
            decrementAndCheckLength();
=======
            ASSERT(!m_pushedChar1);
            bool haveOneCharacterLeft = (--m_currentString.m_length == 1);
            m_currentChar = m_currentString.incrementAndGetCurrentChar8();

            if (!haveOneCharacterLeft)
                return;

            updateSlowCaseFunctionPointers();

>>>>>>> miniblink49
            return;
        }

        (this->*m_advanceFunc)();
    }

    inline void advanceAndUpdateLineNumber()
    {
        if (m_fastPathFlags & Use8BitAdvance) {
<<<<<<< HEAD
            bool haveNewLine = (m_currentChar == '\n') & !!(m_fastPathFlags & Use8BitAdvanceAndUpdateLineNumbers);
            m_currentChar = m_currentString.incrementAndGetCurrentChar8();
            decrementAndCheckLength();

            if (haveNewLine) {
                ++m_currentLine;
                m_numberOfCharactersConsumedPriorToCurrentLine = m_numberOfCharactersConsumedPriorToCurrentString + m_currentString.numberOfCharactersConsumed();
            }

=======
            ASSERT(!m_pushedChar1);

            bool haveNewLine = (m_currentChar == '\n') & !!(m_fastPathFlags & Use8BitAdvanceAndUpdateLineNumbers);
            bool haveOneCharacterLeft = (--m_currentString.m_length == 1);

            m_currentChar = m_currentString.incrementAndGetCurrentChar8();

            if (!(haveNewLine | haveOneCharacterLeft))
                return;

            if (haveNewLine) {
                ++m_currentLine;
                m_numberOfCharactersConsumedPriorToCurrentLine =  m_numberOfCharactersConsumedPriorToCurrentString + m_currentString.numberOfCharactersConsumed();
            }

            if (haveOneCharacterLeft)
                updateSlowCaseFunctionPointers();

>>>>>>> miniblink49
            return;
        }

        (this->*m_advanceAndUpdateLineNumberFunc)();
    }

    void advanceAndASSERT(UChar expectedCharacter)
    {
<<<<<<< HEAD
        DCHECK_EQ(expectedCharacter, currentChar());
=======
        ASSERT_UNUSED(expectedCharacter, currentChar() == expectedCharacter);
>>>>>>> miniblink49
        advance();
    }

    void advanceAndASSERTIgnoringCase(UChar expectedCharacter)
    {
<<<<<<< HEAD
        DCHECK_EQ(WTF::Unicode::foldCase(currentChar()),
            WTF::Unicode::foldCase(expectedCharacter));
=======
        ASSERT_UNUSED(expectedCharacter, WTF::Unicode::foldCase(currentChar()) == WTF::Unicode::foldCase(expectedCharacter));
>>>>>>> miniblink49
        advance();
    }

    void advancePastNonNewline()
    {
        ASSERT(currentChar() != '\n');
        advance();
    }

    void advancePastNewlineAndUpdateLineNumber()
    {
        ASSERT(currentChar() == '\n');
<<<<<<< HEAD
        if (m_currentString.length() > 1) {
=======
        if (!m_pushedChar1 && m_currentString.m_length > 1) {
>>>>>>> miniblink49
            int newLineFlag = m_currentString.doNotExcludeLineNumbers();
            m_currentLine += newLineFlag;
            if (newLineFlag)
                m_numberOfCharactersConsumedPriorToCurrentLine = numberOfCharactersConsumed() + 1;
            decrementAndCheckLength();
            m_currentChar = m_currentString.incrementAndGetCurrentChar();
            return;
        }
        advanceAndUpdateLineNumberSlowCase();
    }

    // Writes the consumed characters into consumedCharacters, which must
    // have space for at least |count| characters.
    void advance(unsigned count, UChar* consumedCharacters);

<<<<<<< HEAD
    int numberOfCharactersConsumed() const
    {
        int numberOfPushedCharacters = 0;
=======
    bool escaped() const { return m_pushedChar1; }

    int numberOfCharactersConsumed() const
    {
        int numberOfPushedCharacters = 0;
        if (m_pushedChar1) {
            ++numberOfPushedCharacters;
            if (m_pushedChar2)
                ++numberOfPushedCharacters;
        }
>>>>>>> miniblink49
        return m_numberOfCharactersConsumedPriorToCurrentString + m_currentString.numberOfCharactersConsumed() - numberOfPushedCharacters;
    }

    String toString() const;

    UChar currentChar() const { return m_currentChar; }

    // The method is moderately slow, comparing to currentLine method.
    OrdinalNumber currentColumn() const;
    OrdinalNumber currentLine() const;
<<<<<<< HEAD
    // Sets value of line/column variables. Column is specified indirectly by a
    // parameter columnAftreProlog which is a value of column that we should get
    // after a prolog (first prologLength characters) has been consumed.
    void setCurrentPosition(OrdinalNumber line,
        OrdinalNumber columnAftreProlog,
        int prologLength);
=======
    // Sets value of line/column variables. Column is specified indirectly by a parameter columnAftreProlog
    // which is a value of column that we should get after a prolog (first prologLength characters) has been consumed.
    void setCurrentPosition(OrdinalNumber line, OrdinalNumber columnAftreProlog, int prologLength);
>>>>>>> miniblink49

private:
    enum FastPathFlags {
        NoFastPath = 0,
        Use8BitAdvanceAndUpdateLineNumbers = 1 << 0,
        Use8BitAdvance = 1 << 1,
    };

    void append(const SegmentedSubstring&);
<<<<<<< HEAD
    void prepend(const SegmentedSubstring&, PrependType);
=======
    void prepend(const SegmentedSubstring&);
>>>>>>> miniblink49

    void advance8();
    void advance16();
    void advanceAndUpdateLineNumber8();
    void advanceAndUpdateLineNumber16();
    void advanceSlowCase();
    void advanceAndUpdateLineNumberSlowCase();
    void advanceEmpty();
    void advanceSubstring();

    void updateSlowCaseFunctionPointers();

    void decrementAndCheckLength()
    {
<<<<<<< HEAD
        ASSERT(m_currentString.length() > 1);
        m_currentString.decrementLength();
        if (m_currentString.haveOneCharacterLeft())
=======
        ASSERT(m_currentString.m_length > 1);
        if (--m_currentString.m_length == 1)
>>>>>>> miniblink49
            updateSlowCaseFunctionPointers();
    }

    void updateAdvanceFunctionPointers()
    {
<<<<<<< HEAD
        if (m_currentString.length() > 1) {
=======
        if ((m_currentString.m_length > 1) && !m_pushedChar1) {
>>>>>>> miniblink49
            if (m_currentString.is8Bit()) {
                m_advanceFunc = &SegmentedString::advance8;
                m_fastPathFlags = Use8BitAdvance;
                if (m_currentString.doNotExcludeLineNumbers()) {
                    m_advanceAndUpdateLineNumberFunc = &SegmentedString::advanceAndUpdateLineNumber8;
                    m_fastPathFlags |= Use8BitAdvanceAndUpdateLineNumbers;
                } else {
                    m_advanceAndUpdateLineNumberFunc = &SegmentedString::advance8;
                }
                return;
            }

            m_advanceFunc = &SegmentedString::advance16;
            m_fastPathFlags = NoFastPath;
            if (m_currentString.doNotExcludeLineNumbers())
                m_advanceAndUpdateLineNumberFunc = &SegmentedString::advanceAndUpdateLineNumber16;
            else
                m_advanceAndUpdateLineNumberFunc = &SegmentedString::advance16;
            return;
        }

<<<<<<< HEAD
        if (!m_currentString.length() && !isComposite()) {
=======
        if (!m_currentString.m_length && !isComposite()) {
>>>>>>> miniblink49
            m_advanceFunc = &SegmentedString::advanceEmpty;
            m_fastPathFlags = NoFastPath;
            m_advanceAndUpdateLineNumberFunc = &SegmentedString::advanceEmpty;
        }

        updateSlowCaseFunctionPointers();
    }

<<<<<<< HEAD
    inline LookAheadResult lookAheadInline(const String& string,
        TextCaseSensitivity caseSensitivity)
    {
        if (string.length() <= static_cast<unsigned>(m_currentString.length())) {
=======
    inline LookAheadResult lookAheadInline(const String& string, TextCaseSensitivity caseSensitivity)
    {
        if (!m_pushedChar1 && string.length() <= static_cast<unsigned>(m_currentString.m_length)) {
>>>>>>> miniblink49
            String currentSubstring = m_currentString.currentSubString(string.length());
            if (currentSubstring.startsWith(string, caseSensitivity))
                return DidMatch;
            return DidNotMatch;
        }
        return lookAheadSlowCase(string, caseSensitivity);
    }

<<<<<<< HEAD
    LookAheadResult lookAheadSlowCase(const String& string,
        TextCaseSensitivity caseSensitivity)
=======
    LookAheadResult lookAheadSlowCase(const String& string, TextCaseSensitivity caseSensitivity)
>>>>>>> miniblink49
    {
        unsigned count = string.length();
        if (count > length())
            return NotEnoughCharacters;
        UChar* consumedCharacters;
        String consumedString = String::createUninitialized(count, consumedCharacters);
        advance(count, consumedCharacters);
        LookAheadResult result = DidNotMatch;
        if (consumedString.startsWith(string, caseSensitivity))
            result = DidMatch;
<<<<<<< HEAD
        prepend(SegmentedString(consumedString), PrependType::Unconsume);
=======
        prepend(SegmentedString(consumedString));
>>>>>>> miniblink49
        return result;
    }

    bool isComposite() const { return !m_substrings.isEmpty(); }

<<<<<<< HEAD
=======
    UChar m_pushedChar1;
    UChar m_pushedChar2;
>>>>>>> miniblink49
    SegmentedSubstring m_currentString;
    UChar m_currentChar;
    int m_numberOfCharactersConsumedPriorToCurrentString;
    int m_numberOfCharactersConsumedPriorToCurrentLine;
    int m_currentLine;
    Deque<SegmentedSubstring> m_substrings;
    bool m_closed;
    bool m_empty;
    unsigned char m_fastPathFlags;
    void (SegmentedString::*m_advanceFunc)();
    void (SegmentedString::*m_advanceAndUpdateLineNumberFunc)();
};

<<<<<<< HEAD
} // namespace blink
=======
}
>>>>>>> miniblink49

#endif
