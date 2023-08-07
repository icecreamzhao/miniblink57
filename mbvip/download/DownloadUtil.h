
#ifndef download_DownloadUtil_h
#define download_DownloadUtil_h

#include "mbvip/common/StringUtil.h"
#include "mbvip/common/UrlUtil.h"

static unsigned char fromHex(unsigned char x)
{
    unsigned char y;
    if (x >= 'A' && x <= 'Z')
        y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z')
        y = x - 'a' + 10;
    else if (x >= '0' && x <= '9')
        y = x - '0';
    else
        DebugBreak();
    return y;
}

static std::string urlDecode(const std::string& str)
{
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++) {
        if (str[i] == '+')
            strTemp += ' ';
        else if (str[i] == '%') {
            if (i + 2 >= length)
                break;
            unsigned char high = fromHex((unsigned char)str[++i]);
            unsigned char low = fromHex((unsigned char)str[++i]);
            strTemp += high * 16 + low;
        } else
            strTemp += str[i];
    }
    return strTemp;
}

static base::string16 getSaveNameFromContentDisposition(const std::string& str)
{
    if (0 == str.size())
        return base::string16();

    if (std::string::npos == str.find("attachment"))
        return base::string16();

    if (std::string::npos == str.find("name"))
        return base::string16();

    size_t pos1 = str.find('=');
    if (std::string::npos == pos1)
        return base::string16();
    pos1++;

    size_t pos2 = str.size();
    std::string path = str.substr(pos1, pos2 - pos1);
    if (path.empty())
        return base::string16();

    if ('"' == path[0])
        path.erase(0 , 1);
    if (path.empty())
        return base::string16();

    if ('"' == path[path.size() - 1])
        path.erase(path.size() - 1, 1);
    if (path.empty())
        return base::string16();

    path = urlDecode(path);
    return common::mulByteToUtf16(path, common::isTextUTF8(path.c_str(), path.size()) ? CP_UTF8 : CP_ACP);
}

static base::string16 getSaveName(std::string contentDisposition, std::string url)
{
    base::string16 result = getSaveNameFromContentDisposition(contentDisposition);
    if (!result.empty())
        return result;
    result = UrlUtil::getSaveNameFromUrl(url);

    std::string resultUtf8 = common::utf16ToUtf8(result.c_str());

    const utf8* str = mbUtilDecodeURLEscape(resultUtf8.c_str());
    std::string strUtf8(str);
    result = common::utf8ToUtf16(strUtf8);

    return result;
}

#endif // download_DownloadUtil_h