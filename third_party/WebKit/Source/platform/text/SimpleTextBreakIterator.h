
#ifndef SimpleTextBreakIterator_h
#define SimpleTextBreakIterator_h

#include "wtf/text/qt4/QChar.h"

namespace blink {

//////////////////////////////////////////////////////////////////////////

void TextBreakIterator::reset(const UChar* str, int len)
{
    m_string = str;
    m_length = len;
    m_currentPos = 0;
}

int32_t TextBreakIterator::last()
{
    m_currentPos = m_length;
    return m_currentPos;
}

int32_t TextBreakIterator::following(int32_t position)
{
    m_currentPos = position;
    int32_t ret = next();
    return ret;
}

int32_t TextBreakIterator::preceding(int32_t position)
{
    m_currentPos = position;
    int32_t ret = previous();
    return ret;
}

bool TextBreakIterator::isBoundary(int32_t offset)
{
    UChar c = m_string[m_currentPos + offset];
    if (WTF::Unicode::isSpace(c))
        return true;

    if (c > 255)
        return true;

    return false;
}

int32_t TextBreakIterator::current(void) const
{
    return m_currentPos;
}

//////////////////////////////////////////////////////////////////////////

static bool isAlphaOrNum(UChar c)
{
    return (c <= '9' && c >= '0') || (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}

static bool isWordBreak(UChar c)
{
    //return WTF::Unicode::isSpace(c) || L'\n' == c;
    return !isAlphaOrNum(c);
}

// �ƺ�icu���棬0��next��0��0��previous��-1.

// ��ֵ��ʡ����ĵĻ�һ�־���һ������
struct WordBreakIterator : TextBreakIterator {
    WordBreakIterator()
    {
    }

    ~WordBreakIterator() override
    {
    }

    virtual int first() override
    {
        m_currentPos = 0;
        return m_currentPos;
    }

    // next��previous�㷨���������ֽڽ��紦��012\n4��pos=3��next��4���ɣ�previousҪ������0
    virtual int next() override
    {
        if (m_currentPos >= m_length) {
            m_currentPos = m_length;
            return -1;
        }
        if (m_currentPos < 0) {
            m_currentPos = 0;
            return m_currentPos;
        }

        bool haveSpace = false;

        UChar c = m_string[m_currentPos];
        if (isWordBreak(c)) {
            m_currentPos++;
            return m_currentPos;
        }

        while (m_currentPos < m_length) {
            c = m_string[m_currentPos];

            if (!isWordBreak(c)) {
                m_currentPos++;
                continue;
            }

            break;
        }

        return m_currentPos;
    }

    virtual int previous() override
    {
        if (0 == m_currentPos)
            return -1;

        if (m_currentPos < 0) {
            m_currentPos = 0;
            return m_currentPos;
        }

        if (m_currentPos > m_length) {
            m_currentPos = m_length;
            return m_currentPos;
        }

        UChar c;
        if (m_currentPos == m_length) {
            m_currentPos = m_length - 1;
            c = m_string[m_currentPos];
            if (isWordBreak(c))
                return m_currentPos;
        }

        if (0 == m_currentPos)
            return 0;

        c = m_string[m_currentPos];
        UChar cPrev = m_string[m_currentPos - 1];

        if (isWordBreak(cPrev)) {
            m_currentPos--;
            return m_currentPos;
        }

        if (!isWordBreak(cPrev) && isWordBreak(c)) {
            m_currentPos--;
            c = m_string[m_currentPos];
        }

        while (m_currentPos > 0) {
            c = m_string[m_currentPos];

            if (isWordBreak(c)) {
                return m_currentPos + 1;
            }
            m_currentPos--;
            continue;
        }

        return m_currentPos;
    }
};

struct CharBreakIterator : TextBreakIterator {
    CharBreakIterator()
    {
    }

    ~CharBreakIterator() override
    {
    }

    virtual int first() override
    {
        m_currentPos = 0;
        return m_currentPos;
    }

    virtual int next() override
    {
        if (m_currentPos >= m_length)
            return /*m_length*/ - 1;
        ++m_currentPos;
        return m_currentPos;
    }

    virtual int previous() override
    {
        if (m_currentPos <= 0)
            return -1;
        if (m_currentPos > m_length)
            m_currentPos = m_length - 1;
        --m_currentPos;
        return m_currentPos;
    }
};

struct LineBreakIterator : TextBreakIterator {
    ~LineBreakIterator() override
    {

    }

    virtual int first() override
    {
        m_currentPos = 0;
        return m_currentPos;
    }

    virtual int next() override
    {
        if (m_currentPos >= m_length) {
            return -1;
        }

        ++m_currentPos;
        while (m_currentPos < m_length && !WTF::Unicode::isLineStop(m_string[m_currentPos]))
            ++m_currentPos;
        return m_currentPos;
    }

    virtual int previous() override
    {
        if (m_currentPos <= 0)
            return -1;
        if (m_currentPos > m_length)
            m_currentPos = m_length;
        --m_currentPos;
        while (m_currentPos > 0 && !WTF::Unicode::isLineStop(m_string[m_currentPos]))
            --m_currentPos;
        return m_currentPos;
    }
};

struct SentenceBreakIterator : TextBreakIterator {
    SentenceBreakIterator()
    {
    }

    ~SentenceBreakIterator() override
    {
    }

    virtual int first() override
    {
        m_currentPos = 0;
        return m_currentPos;
    }

    virtual int next() override
    {
        m_currentPos++;
        if (m_currentPos >= m_length) {
            m_currentPos = -1;
            return m_currentPos;
        }       

        bool haveSpace = false;
        while (m_currentPos < m_length) {
            if (haveSpace && !WTF::Unicode::isSentenceStop(m_string[m_currentPos]))
                break;
            if (WTF::Unicode::isSentenceStop(m_string[m_currentPos]))
                haveSpace = true;
            ++m_currentPos;
        }
        return m_currentPos;
    }

    virtual int previous() override
    {
        --m_currentPos;

        if (m_currentPos == 0)
            return m_currentPos;
        
        if (m_currentPos < 0) {
            m_currentPos = -1;
            return m_currentPos;
        }

        bool haveSpace = false;
        while (m_currentPos > 0) {
            if (haveSpace && !WTF::Unicode::isSentenceStop(m_string[m_currentPos]))
                break;
            if (WTF::Unicode::isSentenceStop(m_string[m_currentPos]))
                haveSpace = true;
            --m_currentPos;
        }
        return m_currentPos;
    }
};

} // blink 

#endif // SimpleTextBreakIterator_h