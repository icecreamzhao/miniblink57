
#ifndef common_StringUtil_h
#define common_StringUtil_h

#include <string>
#include <vector>

#if defined(WIN32)
typedef wchar_t WCHAR;
namespace base {
typedef std::wstring string16;
}
#else
#include "base/strings/string16.h"
typedef char16_t WCHAR;
#endif

namespace common {

std::string utf16ToUtf8(const WCHAR* lpszSrc);
std::string utf16ToMulByte(const WCHAR* lpszSrc, unsigned int codepage);

base::string16 utf8ToUtf16(const std::string& utf8);
base::string16 mulByteToUtf16(const std::string& str, unsigned int codepage);
bool isTextUTF8(const char *str, size_t length);

std::string base64Encode(const unsigned char* bytesToEncode, unsigned int inLen);
std::vector<unsigned char> base64Decode(const std::string& encodedString);

base::string16 createPathFromDllPath(const base::string16& fileName);

bool isLocalDebugMachine();

void setPluginDirectory(const base::string16& dir);
base::string16 getPluginDirectory();

// static std::string hashString(const std::string& str, const std::string& key)
// {
//     std::string result;
//     for (size_t i = 0; i < str.size(); ++i) {
//         result += str[i] ^ (key[i % key.size()]);
//     }
//     return result;
// }

unsigned int hashStringA(const std::string& p);
unsigned int hashStringW(const base::string16& p);

}

#endif // base_StringUtil_h