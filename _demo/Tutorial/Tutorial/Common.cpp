#include "Common.h"

std::string utf16ToUtf8(LPCWSTR lpszSrc)
{
    std::string sResult;
    if (lpszSrc != NULL) {
        int  nUTF8Len = WideCharToMultiByte(CP_UTF8, 0, lpszSrc, -1, NULL, 0, NULL, NULL);
        char* pUTF8 = new char[nUTF8Len + 1];
        if (pUTF8 != NULL) {
            ZeroMemory(pUTF8, nUTF8Len + 1);
            WideCharToMultiByte(CP_UTF8, 0, lpszSrc, -1, pUTF8, nUTF8Len, NULL, NULL);
            sResult = pUTF8;
            delete[] pUTF8;
        }
    }
    return sResult;
}

std::wstring utf8ToUtf16(const std::string& utf8)
{
    std::wstring utf16;
    size_t n = ::MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), utf8.size(), nullptr, 0);
    if (0 == n)
        return L"";
    std::vector<wchar_t> wbuf(n);
    ::MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), utf8.size(), &wbuf[0], n);
    utf16.resize(n + 5);
    utf16.assign(&wbuf[0], n);
    return utf16;
}
