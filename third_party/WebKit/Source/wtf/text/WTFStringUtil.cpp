
#include "wtf/text/WTFStringUtil.h"
#include "wtf/text/UTF8.h"
#include "wtf/text/qt4/UnicodeQt4.h"
#if defined(OS_LINUX)
#include <iconv.h>
#endif

namespace WTF {

static Vector<UChar> iso88959ToUtf16(const char* str, int length)
{
    if (0 == length)
        return Vector<UChar>();

    // https://codereview.stackexchange.com/questions/40780/function-to-convert-iso-8859-1-to-utf-8
    Vector<char, 1024> bufferVector(length * 3);
    char* buffer = bufferVector.data();
    const LChar* characters = (const LChar*)str;
    Unicode::ConversionResult result = Unicode::convertLatin1ToUTF8(&characters, characters + length, &buffer, buffer + bufferVector.size());
    if (Unicode::conversionOK != result)
        return Vector<UChar>();

    String retVal = String::fromUTF8(bufferVector.data(), buffer - bufferVector.data());
    ASSERT(!retVal.is8Bit());
    return retVal.charactersWithNullTermination();
}
    
Vector<UChar> ensureUTF16UChar(const String& string, bool isNullTermination)
{
    if (string.isNull() || string.isEmpty())
        return Vector<UChar>();

    Vector<UChar> out;
    if (!string.is8Bit()) {
        if (isNullTermination)
            return string.charactersWithNullTermination();
        out.append(string.characters16(), string.length());
        return out;
    }

    //RELEASE_ASSERT(isLegalUTF8(string.characters8(), string.length()));
    if (string.containsOnlyASCII()) {
        out = string.charactersWithNullTermination();
        if (!isNullTermination)
            out.pop_back();
        return out;
    }

    String retVal = String::fromUTF8(string.characters8(), string.length());
    if (retVal.isNull() || retVal.isEmpty()) {
        std::vector<UChar> wbuf;
        out = iso88959ToUtf16((LPCSTR)string.characters8(), string.length());
    } else {
        ASSERT(!retVal.is8Bit());
        out = retVal.charactersWithNullTermination();
    }

    if (!isNullTermination)
        out.pop_back();
    return out;
}

String ensureUTF16String(const String& string)
{
    if (string.isNull() || string.isEmpty())
        return String();
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
    if (WTF::Unicode::convertUTF8ToUTF16(&stringCurrent, reinterpret_cast<const char *>(stringStart + length),
        &bufferCurrent, bufferCurrent + buffer.size()) != WTF::Unicode::conversionOK)
        return "";

    unsigned utf16Length = bufferCurrent - bufferStart;
    ASSERT(utf16Length < length);
    return StringImpl::create(bufferStart, utf16Length);
}

Vector<char> ensureStringToUTF8(const String& string, bool isNullTermination)
{
    Vector<char> out;
    if (string.isNull() || string.isEmpty()) {
        if (isNullTermination)
            out.append('\0');
        return out;
    }

    if (string.is8Bit()) {
        out.resize(string.length());
        memcpy(out.data(), string.characters8(), string.length());
    } else {
        CString utf8 = string.utf8();
        size_t len = utf8.length();
        if (0 == len)
            return out;
        
        out.resize(len);
        memcpy(out.data(), utf8.data(), len);
    }

    if (isNullTermination && '\0' != out[out.size() - 1])
        out.append('\0');

    return out;
}

String ensureStringToUTF8String(const String& string)
{
    Vector<char> out = ensureStringToUTF8(string, false);
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

#if defined(OS_LINUX)
// https://docs.oracle.com/cd/E56344_01/html/E54073/gmwlq.html
// https://blog.csdn.net/veryhehe2011/article/details/23272927
// https://blog.csdn.net/smartfox80/article/details/51181700?spm=1001.2101.3001.6650.6
// static int codeConvert(char* from_charset, char* to_charset, char* inbuf, size_t inlen, char* outbuf, size_t outlen)
// {
//     iconv_t cd;
//     char** pin = &inbuf;
//     char** pout = &outbuf;
// 
//     cd = iconv_open(to_charset, from_charset);
//     if (cd == 0)
//         return -1;
// 
//     memset(outbuf, 0, outlen);
// 
//     if (iconv(cd, pin, &inlen, pout, &outlen) == -1)
//         return -1;
//     iconv_close(cd);
//     *pout = '\0';
// 
//     return 0;
// }
//
// static int u2g(char* inbuf, size_t inlen, char* outbuf, size_t outlen)
// {
//     return codeConvert("utf-8", "gb2312", inbuf, inlen, outbuf, outlen);
// }
// 
// static int g2u(char* inbuf, size_t inlen, char* outbuf, size_t outlen)
// {
//     return codeConvert("gb2312", "utf-8", inbuf, inlen, outbuf, outlen);
// }
// 
// bool unicode_to_utf8 (char* inbuf, size_t* inlen, char* outbuf, size_t* outlen)
// {
//     /* 目的编码, TRANSLIT：遇到无法转换的字符就找相近字符替换
//     *           IGNORE ：遇到无法转换字符跳过*/
//     char* encTo = "UTF-8//IGNORE";
//     /* 源编码 */
//     char* encFrom = "UNICODE";
// 
//     /* 获得转换句柄
//     *@param encTo 目标编码方式
//     *@param encFrom 源编码方式
//     *
//     * */
//     iconv_t cd = iconv_open (encTo, encFrom);
//     if (cd == (iconv_t)-1)
//     {
//         perror ("iconv_open");
//     }
// 
//     /* 需要转换的字符串 */
//     printf("inbuf=%s\n", inbuf);
// 
//     /* 打印需要转换的字符串的长度 */
//     printf("inlen=%d\n", *inlen);
// 
// 
//     /* 由于iconv()函数会修改指针，所以要保存源指针 */
//     char* tmpin = inbuf;
//     char* tmpout = outbuf;
//     size_t insize = *inlen;
//     size_t outsize = *outlen;
// 
//     /* 进行转换
//     *@param cd iconv_open()产生的句柄
//     *@param srcstart 需要转换的字符串
//     *@param inlen 存放还有多少字符没有转换
//     *@param tempoutbuf 存放转换后的字符串
//     *@param outlen 存放转换后,tempoutbuf剩余的空间
//     *
//     * */
//     size_t ret = iconv (cd, &tmpin, inlen, &tmpout, outlen);
//     if (ret == -1) {
//         printf ("iconv");
//         return false;
//     }
// 
//     /* 存放转换后的字符串 */
//     printf("outbuf = %s\n", outbuf);
// 
//     //存放转换后outbuf剩余的空间
//     printf("outlen = %d\n", *outlen);
// 
//     int i = 0;
// 
//     for (int i = 0; i < (outsize- (*outlen)); ++i) {
//         //printf("%2c", outbuf[i]);
//         printf("%x\n", outbuf[i]);
//     }
// 
//     /* 关闭句柄 */
//     iconv_close (cd);
// 
//     return true;
// }
// 
// bool utf8_to_unicode(char *inbuf, size_t *inlen, char *outbuf, size_t *outlen)
// {
//     /* 目的编码, TRANSLIT：遇到无法转换的字符就找相近字符替换
//     *           IGNORE ：遇到无法转换字符跳过*/
//     char *encTo = "UNICODE//IGNORE";
//     /* 源编码 */
//     char *encFrom = "UTF-8";
// 
//     /* 获得转换句柄
//     *@param encTo 目标编码方式
//     *@param encFrom 源编码方式
//     *
//     * */
//     iconv_t cd = iconv_open (encTo, encFrom);
//     if (cd == (iconv_t)-1)
//     {
//         perror ("iconv_open");
//     }
// 
//     /* 需要转换的字符串 */
//     printf("inbuf=%s\n", inbuf);
// 
//     /* 打印需要转换的字符串的长度 */
//     printf("inlen=%d\n", *inlen);
// 
//     /* 由于iconv()函数会修改指针，所以要保存源指针 */
//     char *tmpin = inbuf;
//     char *tmpout = outbuf;
//     size_t insize = *inlen;
//     size_t outsize = *outlen;
// 
//     /* 进行转换
//     *@param cd iconv_open()产生的句柄
//     *@param srcstart 需要转换的字符串
//     *@param inlen 存放还有多少字符没有转换
//     *@param tempoutbuf 存放转换后的字符串
//     *@param outlen 存放转换后,tempoutbuf剩余的空间
//     *
//     * */
//     size_t ret = iconv (cd, &tmpin, inlen, &tmpout, outlen);
//     if (ret == -1)
//     {
//         perror ("iconv");
//     }
// 
//     /* 存放转换后的字符串 */
//     printf("outbuf=%s\n", outbuf);
// 
//     //存放转换后outbuf剩余的空间
//     printf("outlen=%d\n", *outlen);
// 
//     int i = 0;
// 
//     for (i=0; i<(outsize- (*outlen)); i++)
//     {
//         //printf("%2c", outbuf[i]);
//         printf("%x\n", outbuf[i]);
//     }
// 
//     /* 关闭句柄 */
//     iconv_close (cd);
// 
//     return 0;
// }
#endif

void MByteToWChar(const char* lpcszStr, size_t cbMultiByte, std::vector<UChar>* out, UINT codePage)
{
    out->clear();
    if (nullptr == lpcszStr || 0 == cbMultiByte)
        return;
#if defined(OS_LINUX)
    out->resize(cbMultiByte * 4 / sizeof(UChar));

    iconv_t cd;
    char* data = (char*)out->data();
    char* pIn = (char*)lpcszStr;
    char** ppIn = &pIn;
    char** ppOut = &data;
    size_t outlen = out->size() * sizeof(UChar);
    size_t oldSize = outlen;

    if (CP_UTF8 == codePage) {
        cd = iconv_open("UTF-16le//IGNORE", "UTF-8");
    } else {
        cd = iconv_open("UTF-16le//IGNORE", "gb2312");
    }
    if (cd == 0)
        return;

    memset(data, 0, outlen);
    if (iconv(cd, ppIn, &cbMultiByte, ppOut, &outlen) == -1)
        return;
    iconv_close(cd);

    size_t len = (((const UChar*)*ppOut) - out->data()) * sizeof(UChar);
    if (len != oldSize - outlen) {
        printf("MByteToWChar fail, len:%zu, oldSize:%zu, %p, %p, outlen: %zu\n", len, oldSize, *ppOut, out->data(), outlen);
        *(int*)1 = 1;
    }

    size_t pre = len % sizeof(UChar);
    len += pre;
    if (len > oldSize)
        len = oldSize;

    out->resize(len / sizeof(UChar));
#else
    DWORD dwMinSize;
    dwMinSize = MultiByteToWideChar(codePage, 0, lpcszStr, cbMultiByte, NULL, 0);
    if (0 == dwMinSize)
        return;

    out->resize(dwMinSize);

    // Convert headers from ASCII to Unicode.
    MultiByteToWideChar(codePage, 0, lpcszStr, cbMultiByte, &out->at(0), dwMinSize);
#endif
}

void WCharToMByte(const UChar* lpWideCharStr, size_t cchWideChar, std::vector<char>* out, UINT codePage)
{
    out->clear();
    if (0 == cchWideChar || nullptr == lpWideCharStr)
        return;

#if defined(OS_LINUX)
    cchWideChar *= sizeof(UChar);
    out->resize(cchWideChar * 4);

    iconv_t cd;
    char* data = out->data();
    char* pIn = (char*)lpWideCharStr;
    char** ppIn = &pIn;
    char** ppOut = &data;
    size_t outlen = out->size();
    size_t oldSize = outlen;

    if (CP_UTF8 == codePage) {
        cd = iconv_open("UTF-8//IGNORE", "UTF-16le");
    } else {
        cd = iconv_open("gb2312//IGNORE", "UTF-16le");
    }
    if (cd == 0)
        return;

    memset(data, 0, outlen);
    if (iconv(cd, ppIn, &cchWideChar, ppOut, &outlen) == -1)
        return;
    iconv_close(cd);

    size_t len = *ppOut - out->data();
    if (len != oldSize - outlen)
        *(int*)1 = 1;
    out->resize(len);
#else
    DWORD dwMinSize;
    dwMinSize = WideCharToMultiByte(codePage, 0, lpWideCharStr, cchWideChar, NULL, 0, NULL, FALSE);
    if (0 == dwMinSize)
        return;

    out->resize(dwMinSize);

    // Convert headers from ASCII to Unicode.
    WideCharToMultiByte(codePage, 0, lpWideCharStr, cchWideChar, &out->at(0), dwMinSize, NULL, FALSE);
#endif
}

void Utf8ToMByte(const char* lpUtf8CharStr, size_t cchUtf8Char, std::vector<char>* out, UINT codePage)
{
    out->resize(0);

    std::vector<UChar> tempBuf;
    MByteToWChar(lpUtf8CharStr, cchUtf8Char, &tempBuf, CP_UTF8);
    if (0 == tempBuf.size())
        return;
    WCharToMByte(&tempBuf[0], tempBuf.size(), out, codePage);
}

void MByteToUtf8(const char* lpMCharStr, size_t cchMChar, std::vector<char>* out, UINT codePage)
{
    out->resize(0);

    std::vector<UChar> tempBuf;
    MByteToWChar(lpMCharStr, cchMChar, &tempBuf, codePage);
    if (0 == tempBuf.size())
        return;
    WCharToMByte(&tempBuf[0], tempBuf.size(), out, CP_UTF8);
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

std::string WTFStringToStdString(const WTF::String& str)
{
    CString utf8 = str.utf8();
    std::string result(utf8.data());
    return result;
}

bool isTextUTF8(const char *str, int length)
{
    int i = 0;
    DWORD nBytes = 0; // UFT8可用1-6个字节编码,ASCII用一个字节
    UCHAR chr = 0;
    bool bAllAscii = true; // 如果全部都是ASCII, 说明不是UTF-8
    for (i = 0; i < length; i++) {
        chr = (UCHAR)* (str + i);

        if ((chr & 0x80) != 0) // 判断是否ASCII编码,如果不是,说明有可能是UTF-8,ASCII用7位编码,但用一个字节存,最高位标记为0,o0xxxxxxx
            bAllAscii = false;

        if (nBytes == 0) { // 如果不是ASCII码,应该是多字节符,计算字节数

            if (chr >= 0x80) {
                if (chr >= 0xFC && chr <= 0xFD)
                    nBytes = 6;
                else if (chr >= 0xF8)
                    nBytes = 5;
                else if (chr >= 0xF0)
                    nBytes = 4;
                else if (chr >= 0xE0)
                    nBytes = 3;
                else if (chr >= 0xC0)
                    nBytes = 2;
                else {
                    return false;
                }
                nBytes--;
            }
        } else { // 多字节符的非首字节,应为 10xxxxxx
            if ((chr & 0xC0) != 0x80)
                return false;
            nBytes--;
        }
    }
    if (nBytes > 0) //违返规则
        return false;

    if (bAllAscii) //如果全部都是ASCII, 说明不是UTF-8
        return false;
    return true;
}


} // WTF