
#include "wtf/text/WTFStringUtil.h"
#include "wtf/text/UTF8.h"

namespace WTF {

String ensureUTF16String(const String& string)
{
    if (string.isNull() || string.isEmpty())
        return String(L"");
    if (!string.is8Bit())
        return String(string.characters16(), string.length());

    const LChar* stringStart = string.characters8();
    size_t length = string.length();
    if (charactersAreAllASCII(stringStart, length))
        return String::make16BitFrom8BitSource(stringStart, length);

    Vector<UChar, 1024> buffer(length);
    UChar* bufferStart = buffer.data();

    UChar* bufferCurrent = bufferStart;
    const char* stringCurrent = reinterpret_cast<const char*>(stringStart);
    if (WTF::Unicode::convertUTF8ToUTF16(&stringCurrent, reinterpret_cast<const char*>(stringStart + length),
            &bufferCurrent, bufferCurrent + buffer.size())
        != WTF::Unicode::conversionOK)
        return String();

    unsigned utf16Length = bufferCurrent - bufferStart;
    ASSERT(utf16Length < length);
    return StringImpl::create(bufferStart, utf16Length);
}

Vector<UChar> ensureUTF16UChar(const String& string)
{
    String out = ensureUTF16String(string);
    return out.charactersWithNullTermination();
}

// 如果string里是8bit的话，必须是utf8编码
Vector<UChar> ensureStringToUChars(const String& string)
{
    if (string.isNull() || string.isEmpty())
        return Vector<UChar>();

    if (!string.is8Bit())
        return string.charactersWithNullTermination();

    //ASSERT(WTF::Unicode::isLegalUTF8(string.characters8(), string.length()));
    if (string.containsOnlyASCII())
        return string.charactersWithNullTermination();

    String retVal = String::fromUTF8(string.characters8(), string.length());
    if (retVal.isNull() || retVal.isEmpty())
        return Vector<UChar>();

    ASSERT(!retVal.is8Bit());
    return retVal.charactersWithNullTermination();
}

Vector<char> ensureStringToUTF8(const String& string)
{
    Vector<char> out;
    if (string.isNull() || string.isEmpty())
        return out;
    if (string.is8Bit()) {
        out.resize(string.length());
        memcpy(out.data(), string.characters8(), string.length());
        out.append('\0');
    } else {
        CString utf8 = string.utf8();
        out.resize(utf8.length());
        memcpy(out.data(), utf8.data(), utf8.length());
    }

    return out;
}

String ensureStringToUTF8String(const String& string)
{
    Vector<char> out = ensureStringToUTF8(string);
    return String(out.data(), out.size());
}

static bool isWhiteSpace(UChar c)
{
    return L' ' == c || L'\r' == c || L'\n' == c;
}

void stringTrim(String& stringInOut, bool leftTrim, bool rightTrim)
{
    if (stringInOut.isNull() || stringInOut.isEmpty())
        return;

    if (leftTrim) {
        while (!stringInOut.isNull() && !stringInOut.isEmpty()) {
            UChar c = stringInOut[0];
            if (!isWhiteSpace(c))
                break;

            stringInOut.remove(0);
        }
    }

    if (rightTrim) {
        while (!stringInOut.isNull() && !stringInOut.isEmpty()) {
            UChar c = stringInOut[stringInOut.length() - 1];
            if (!isWhiteSpace(c))
                break;

            stringInOut.remove(stringInOut.length() - 1);
        }
    }
}

bool splitStringToVector(const String& strData, const char strSplit, bool needTrim, WTF::Vector<String>& out)
{
    ASSERT(strData.is8Bit());
    size_t nIndex = WTF::kNotFound;
    size_t nStartIndex = 0;
    size_t nCount = 0;
    String strItem;
    String strBuf = strData;

    out.clear();
    strBuf = strData;

    do {
        nIndex = strBuf.find(strSplit, nStartIndex);
        if (WTF::kNotFound == nIndex) {
            if (nStartIndex <= strBuf.length()) {
                nCount = strBuf.length() - nStartIndex;
                strItem = strBuf.substring(nStartIndex, nCount);
                if (strItem.isNull() || strItem.isEmpty())
                    continue;
                stringTrim(strItem, needTrim, needTrim);

                out.append(strItem);
            }
            break;
        }

        nCount = nIndex - nStartIndex;
        strItem = strBuf.substring(nStartIndex, nCount);
        stringTrim(strItem, needTrim, needTrim);
        out.append(strItem);

        nStartIndex = nIndex + 1;
        if (nStartIndex > strBuf.length())
            break;
    } while (nIndex != WTF::kNotFound);

    return true;
}

} // WTF