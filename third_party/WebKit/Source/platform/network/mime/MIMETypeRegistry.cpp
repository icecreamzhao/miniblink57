// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "platform/network/mime/MIMETypeRegistry.h"

#include "base/files/file_path.h"
#include "base/strings/string_util.h"
//#include "components/mime_util/mime_util.h"
//#include "media/base/mime_util.h"
//#include "media/filters/stream_parser_factory.h"
//#include "net/base/mime_util.h"
#include "public/platform/FilePathConversion.h"
//#include "public/platform/InterfaceProvider.h"
#include "public/platform/Platform.h"
//#include "public/platform/mime_registry.mojom-blink.h"
#include "wtf/text/WTFString.h"
#include "include/v8-version.h"

// https://opensource.apple.com/source/Libc/Libc-262/gen/fnmatch.c.auto.html
// https://www.cnblogs.com/oloroso/p/6861576.html
#define	EOS	'\0'

#define RANGE_MATCH     1
#define RANGE_NOMATCH   0
#define RANGE_ERROR     (-1)

#define	FNM_NOMATCH	1	/* Match failed. */

#define	FNM_NOESCAPE	0x01	/* 禁用反斜杠进行转义 */
#define	FNM_PATHNAME	0x02	/* 斜杠只能被斜杠匹配(即不能被*或者?匹配) */
#define	FNM_PERIOD	0x04	/* Period must be matched by period. */
/*如果这个标志设置了，string 里的起始点号必须匹配 pattern 里的点号。
一个点号被认为是起始点号，如果它是string 第一个字符，或者如果同时设
置了 FNM_PATHNAME，紧跟在斜杠后面的点号。
*/
#define	FNM_LEADING_DIR	0x08	/* Ignore /<tail> after Imatch. */
/*如果这个标志(GNU 扩展)设置了，模式必须匹配跟随在斜杠之后的 string
的初始片断。这个标志主要是给 glibc 内部使用并且只在一定条件下实现。
即只匹配目录路径部分，不匹配到具体文件名
*/
#define	FNM_CASEFOLD	0x10	/* 模式匹配忽略大小写. */
#define FNM_PREFIX_DIRS	0x20	/* Directory prefixes of pattern match too. */

// 字符范围匹配
// pattern传入如 [a-x]*** 形式的字符串
// 匹配失败或匹配到EOS结束(也是失败)，返回NULL
// 成功返回匹配串的下一个匹配成分首地址
static const char* rangematch(const char *pattern, char test, int flags)
{
    // 此处没有对c进行初始化，可能出问题（栈上变量默认值未定）
    int negate, ok;
    char c, c2;

    /*
    * A bracket expression starting with an unquoted circumflex
    * character produces unspecified results
    * 以无引号 ^ 字符开始的方括号表达式，将产生未指定的结果
    * (IEEE 1003.2-1992,3.13.2).  此实现将其视为 '!',以与正则表达式语法保持一致.
    * J.T. Conklin (conklin@ngai.kaleida.com)
    */
    // 检测方括号表达式中第一个字符
    // 如果为!或者^，则对后面匹配的结果取反
    if ((negate = (*pattern == '!' || *pattern == '^'))){
        ++pattern;
    }

    // 忽略大小写，则转为小写处理
    if (flags & FNM_CASEFOLD){
        test = WTF::toASCIILower((unsigned char)test);
    }
    // 循环到方括号表达式结束
    for (ok = 0; (c = *pattern++) != ']';) {
        // 如果没有禁用转义，获取字符
        if (c == '\\' && !(flags & FNM_NOESCAPE)){
            c = *pattern++;
        }
        // 匹配结束
        if (c == EOS){
            return (NULL);
        }
        // 忽略大小写，则转为小写
        if (flags & FNM_CASEFOLD){
            c = WTF::toASCIILower((unsigned char)c);
        }
        // 如果当前匹配项c 的下一个是'-'，则获取'-'后面的一个字符
        // 例如，匹配串为 [a-x] 当前c为a,则c2为x，表示匹配a-x之间字符
        if (*pattern == '-'
            && (c2 = *(pattern + 1)) != EOS && c2 != ']') {
            pattern += 2;
            // 判断是否需要转义
            if (c2 == '\\' && !(flags & FNM_NOESCAPE)){
                c2 = *pattern++;
            }
            if (c2 == EOS){
                return (NULL);
            }
            // 判断是否区分大小写
            if (flags & FNM_CASEFOLD){
                c2 = WTF::toASCIILower((unsigned char)c2);
            }
            // 判断test是否位于 [c,c2]区间
            if ((unsigned char)c <= (unsigned char)test &&
                (unsigned char)test <= (unsigned char)c2){
                ok = 1;
            }
        }
        else if (c == test){
            ok = 1;
        }
    }
    // 返回匹配结果
    return (ok == negate ? NULL : pattern);
}


int fnmatch(const char* pattern, const char* string, int flags)
{
    const char* stringstart;
    char c, test;

    for (int i = 0; 0 != string[i]; ++i) {
        if (' ' != string[i]) {
            string = string + i;
            break;
        }
    }

    for (stringstart = string;;) {
        // 逐个取匹配字符串中的成分(分为*?和range三种)
        switch (c = *pattern++) {
        case EOS:   // 没有匹配串的情况
                    // 如果忽略'/'后面的部分，则匹配成功
            if ((flags & FNM_LEADING_DIR) && *string == '/') {
                return (0);
            }
            // 如果string也是空串，则匹配成功
            return (*string == EOS ? 0 : FNM_NOMATCH);
        case '?':   // 匹配单个任意字符
                    // string为空则不能匹配
            if (*string == EOS) {
                return (FNM_NOMATCH);
            }
            // 判断'/'是否只能由'/'进行匹配
            if (*string == '/' && (flags & FNM_PATHNAME)) {
                return (FNM_NOMATCH);
            }
            // 判断是否string中的起始'.'必须匹配pattern中的'.'（即'?'不能匹配'.'）
            if (*string == '.' && (flags & FNM_PERIOD) &&
                (string == stringstart ||
                    ((flags & FNM_PATHNAME) && *(string - 1) == '/'))) {
                return (FNM_NOMATCH);
            }
            // 匹配成功则匹配string的下一个字符
            ++string;
            break;
        case '*':   // 匹配单个或多个任意字符
            c = *pattern;
            /* 多个'*'当做一个 */
            while (c == '*') {
                c = *++pattern;
            }
            // 判断是否需要对'.'进行处理
            if (*string == '.' && (flags & FNM_PERIOD) &&
                (string == stringstart ||
                    ((flags & FNM_PATHNAME) && *(string - 1) == '/'))) {
                return (FNM_NOMATCH);
            }

            /* 优化 * 在匹配串结尾或者在 /. 之前的匹配*/
            if (c == EOS) {  // 在结尾
                             // 判断 * 是否不匹配斜杠
                if (flags & FNM_PATHNAME) {
                    // 不匹配斜杠，则判断是否忽略'/'之后部分
                    return ((flags & FNM_LEADING_DIR) ||
                        ((strchr(string, '/') == NULL) ? 0 : FNM_NOMATCH));
                } else {
                    return (0);
                }
            } else if (c == '/' && flags & FNM_PATHNAME) { // 在 /. 之前
                                                           // 如果string后没有 '/'则匹配失败
                if ((string = strchr(string, '/')) == NULL) {
                    return (FNM_NOMATCH);
                }
                break;
            }

            /* 非特殊情况下，递归匹配 */
            while ((test = *string) != EOS) {
                // 不对'.'进行特殊处理，进行匹配（则只需判断'/'匹配情况）
                if (!fnmatch(pattern, string, flags & ~FNM_PERIOD)) {
                    return (0); // 匹配成功
                }
                // 对 '/'进行处理（斜杠只匹配斜杠，则匹配失败）
                if (test == '/' && flags & FNM_PATHNAME) {
                    break;
                }
                ++string;
            }
            // 返回匹配失败（即*没有匹配成功,'.'和'/'上的匹配没有成功）
            return (FNM_NOMATCH);
        case '[':   // range 范围匹配
            if (*string == EOS) {
                return (FNM_NOMATCH);   // 空串匹配失败
            }
            if (*string == '/' && flags & FNM_PATHNAME) {
                return (FNM_NOMATCH);   // '/'匹配失败
            }
            if ((pattern =
                rangematch(pattern, *string, flags)) == NULL) {
                return (FNM_NOMATCH);   // 范围匹配失败
            }
            ++string;
            break;
        case '\\':  // 斜杠匹配（判断是否需要转义）
            if (!(flags & FNM_NOESCAPE)) {
                if ((c = *pattern++) == EOS) {
                    c = '\\';
                    --pattern;
                }
            }
            /* 非上述部分，则直接匹配单个字符 */
        default:
            if (c == *string) {
                ;   // 直接匹配上了
            } else if ((flags & FNM_CASEFOLD) &&
                (WTF::toASCIILower((unsigned char)c) ==
                    WTF::toASCIILower((unsigned char)*string))) {
                ;   // 忽略大小写匹配成功
            } else if ((flags & FNM_PREFIX_DIRS) && *string == EOS &&
                ((c == '/' && string != stringstart) ||
                    (string == stringstart + 1 && *stringstart == '/'))) {
                return (0); // 匹配成功
            } else {
                return (FNM_NOMATCH); // 匹配失败
            }
            string++;
            break;
        }
    }
    /* NOTREACHED */
}

namespace blink {

namespace {

    struct MimeRegistryPtrHolder {
    public:
        MimeRegistryPtrHolder()
        {
            //     Platform::current()->interfaceProvider()->getInterface(
            //         mojo::MakeRequest(&mimeRegistry));
        }
        ~MimeRegistryPtrHolder() { }

        //mojom::blink::MimeRegistryPtr mimeRegistry;
    };

    static WTF::String checkAndEnsureBit8String(const blink::WebString& ext)
    {
        if (ext.isNull() || ext.isEmpty())
            return WTF::String();

        WTF::String extension = ext;
        if (!extension.is8Bit()) {
            CString utf8String = extension.utf8();
            extension = WTF::String(utf8String.data(), utf8String.length());
        }

        return extension;
    }

    std::string ToASCIIOrEmpty(const WebString& string)
    {
        return string.containsOnlyASCII() ? string.ascii() : std::string();
    }

    template <typename CHARTYPE, typename SIZETYPE>
    std::string ToLowerASCIIInternal(CHARTYPE* str, SIZETYPE length)
    {
        std::string lowerASCII;
        lowerASCII.reserve(length);
        for (CHARTYPE* p = str; p < str + length; p++)
            lowerASCII.push_back(base::ToLowerASCII(static_cast<char>(*p)));
        return lowerASCII;
    }

    // Does the same as ToASCIIOrEmpty, but also makes the chars lower.
    std::string ToLowerASCIIOrEmpty(const String& str)
    {
        if (str.isEmpty() || !str.containsOnlyASCII())
            return std::string();
        if (str.is8Bit())
            return ToLowerASCIIInternal(str.characters8(), str.length());
        return ToLowerASCIIInternal(str.characters16(), str.length());
    }

    // #define STATIC_ASSERT_ENUM(a, b)                            \
//   static_assert(static_cast<int>(a) == static_cast<int>(b), \
//                 "mismatching enums: " #a)
    // STATIC_ASSERT_ENUM(MIMETypeRegistry::IsNotSupported, media::IsNotSupported);
    // STATIC_ASSERT_ENUM(MIMETypeRegistry::IsSupported, media::IsSupported);
    // STATIC_ASSERT_ENUM(MIMETypeRegistry::MayBeSupported, media::MayBeSupported);

} // namespace

String MIMETypeRegistry::getMIMETypeForExtension(const String& ext)
{
    // The sandbox restricts our access to the registry, so we need to proxy
    // these calls over to the browser process.
    //   DEFINE_STATIC_LOCAL(MimeRegistryPtrHolder, registryHolder, ());
    //   String mimeType;
    //   if (!registryHolder.mimeRegistry->GetMimeTypeFromExtension(ext, &mimeType))
    //     return String();
    //   return mimeType;
    ASSERT(isMainThread());

    if (ext.isNull() || ext.isEmpty())
        return blink::WebString();

    WTF::String extension = ext;
    if (!extension.is8Bit()) {
        CString utf8String = extension.utf8();
        extension = WTF::String(utf8String.data(), utf8String.length() - 1);
    }

    static WTF::HashMap<WTF::String, WTF::String> mimetypeMap;
    if (mimetypeMap.isEmpty()) {
        //fill with initial values
        mimetypeMap.add("txt", "text/plain");
        mimetypeMap.add("pdf", "application/pdf");
        mimetypeMap.add("ps", "application/postscript");
        mimetypeMap.add("html", "text/html");
        mimetypeMap.add("htm", "text/html");
        mimetypeMap.add("xml", "text/xml");
        mimetypeMap.add("xsl", "text/xsl");
        mimetypeMap.add("js", "application/x-javascript");
        mimetypeMap.add("xhtml", "application/xhtml+xml");
        mimetypeMap.add("rss", "application/rss+xml");
        mimetypeMap.add("webarchive", "application/x-webarchive");
        mimetypeMap.add("svg", "image/svg+xml");
        mimetypeMap.add("svgz", "image/svg+xml");
        mimetypeMap.add("jpg", "image/jpeg");
        mimetypeMap.add("jpeg", "image/jpeg");
        mimetypeMap.add("png", "image/png");
        mimetypeMap.add("gif", "image/gif");
        mimetypeMap.add("tif", "image/tiff");
        mimetypeMap.add("tiff", "image/tiff");
        mimetypeMap.add("ico", "image/ico");
        mimetypeMap.add("cur", "image/ico");
        mimetypeMap.add("bmp", "image/bmp");
        mimetypeMap.add("wml", "text/vnd.wap.wml");
        mimetypeMap.add("wmlc", "application/vnd.wap.wmlc");
    }
    WTF::String result = mimetypeMap.get(extension);
    return result;
}

String MIMETypeRegistry::getWellKnownMIMETypeForExtension(const String& ext)
{
    // This method must be thread safe and should not consult the OS/registry.
    //   std::string mimeType;
    //   net::GetWellKnownMimeTypeFromExtension(WebStringToFilePath(ext).value(),
    //                                          &mimeType);
    //   return String::fromUTF8(mimeType.data(), mimeType.length());
    ASSERT(isMainThread());

    if (ext.isNull() || ext.isEmpty())
        return blink::WebString();

    WTF::String extension = ext;
    if (!extension.is8Bit()) {
        CString utf8String = extension.utf8();
        extension = WTF::String(utf8String.data(), utf8String.length() - 1);
    }

    static WTF::HashMap<WTF::String, WTF::String> mimetypeMap;
    if (mimetypeMap.isEmpty()) {
        //fill with initial values
        mimetypeMap.add("txt", "text/plain");
        mimetypeMap.add("pdf", "application/pdf");
        mimetypeMap.add("ps", "application/postscript");
        mimetypeMap.add("html", "text/html");
        mimetypeMap.add("htm", "text/html");
        mimetypeMap.add("xml", "text/xml");
        mimetypeMap.add("xsl", "text/xsl");
        mimetypeMap.add("js", "application/x-javascript");
        mimetypeMap.add("xhtml", "application/xhtml+xml");
        mimetypeMap.add("rss", "application/rss+xml");
        mimetypeMap.add("webarchive", "application/x-webarchive");
        mimetypeMap.add("svg", "image/svg+xml");
        mimetypeMap.add("svgz", "image/svg+xml");
        mimetypeMap.add("jpg", "image/jpeg");
        mimetypeMap.add("jpeg", "image/jpeg");
        mimetypeMap.add("png", "image/png");
        mimetypeMap.add("gif", "image/gif");
        mimetypeMap.add("tif", "image/tiff");
        mimetypeMap.add("tiff", "image/tiff");
        mimetypeMap.add("ico", "image/ico");
        mimetypeMap.add("cur", "image/ico");
        mimetypeMap.add("bmp", "image/bmp");
        mimetypeMap.add("wml", "text/vnd.wap.wml");
        mimetypeMap.add("wmlc", "application/vnd.wap.wmlc");
    }
    WTF::String result = mimetypeMap.get(extension);
    return result;
}

String MIMETypeRegistry::getMIMETypeForPath(const String& path)
{
    int pos = path.reverseFind('.');
    if (pos < 0)
        return "application/octet-stream";
    String extension = path.substring(pos + 1);
    String mimeType = getMIMETypeForExtension(extension);
    return mimeType.isEmpty() ? "application/octet-stream" : mimeType;
}

bool MIMETypeRegistry::isSupportedMIMEType(const String& mimeType)
{
    //return mime_util::IsSupportedMimeType(ToLowerASCIIOrEmpty(mimeType));
    if ("text/html" == mimeType || "text/vnd.wap.wml" == mimeType || "application/xhtml+xml" == mimeType)
        return true;
    return false;
}

bool MIMETypeRegistry::isSupportedImageMIMEType(const String& mimeType)
{
    //return mime_util::IsSupportedImageMimeType(ToLowerASCIIOrEmpty(mimeType));
    WTF::String extension = checkAndEnsureBit8String(mimeType);
    if (extension.isEmpty())
        return false;

    static WTF::HashSet<WTF::String>* supportedImageResourceMIMETypes;
    if (!supportedImageResourceMIMETypes) {
        supportedImageResourceMIMETypes = new WTF::HashSet<WTF::String>();
        static const char* types[] = {
            //"image/svg+xml",
            "image/jpeg",
            "image/png",
            "image/tiff",
            //"application/x-javascript",
            "image/ico",
            "image/bmp",
            "image/gif",
        };
        for (size_t i = 0; i < WTF_ARRAY_LENGTH(types); ++i)
            supportedImageResourceMIMETypes->add(types[i]);
    }

    return supportedImageResourceMIMETypes->contains(extension);
}

bool MIMETypeRegistry::isSupportedImageResourceMIMEType(const String& mimeType)
{
    return isSupportedImageMIMEType(mimeType);
}

bool MIMETypeRegistry::isSupportedImagePrefixedMIMEType(const String& mimeType)
{
    //   std::string asciiMimeType = ToLowerASCIIOrEmpty(mimeType);
    //   return (mime_util::IsSupportedImageMimeType(asciiMimeType) ||
    //           (base::StartsWith(asciiMimeType, "image/",
    //                             base::CompareCase::SENSITIVE) &&
    //            mime_util::IsSupportedNonImageMimeType(asciiMimeType)));

//     return Platform::current()->getMimeRegistry()->supportsImagePrefixedMIMEType(mimeType.lower())
//         != WebMimeRegistry::IsNotSupported;

    return isSupportedImageMIMEType(mimeType) || (mimeType.startsWith("image/") && isSupportedNonImageMIMEType(mimeType));
}

bool MIMETypeRegistry::isSupportedImageMIMETypeForEncoding(
    const String& mimeType)
{
    if (equalIgnoringCase(mimeType, "image/jpeg") || equalIgnoringCase(mimeType, "image/png"))
        return true;
    if (equalIgnoringCase(mimeType, "image/webp"))
        return true;
    return false;
}

bool MIMETypeRegistry::isSupportedJavaScriptMIMEType(const String& mimeType)
{
    //   return mime_util::IsSupportedJavascriptMimeType(
    //       ToLowerASCIIOrEmpty(mimeType));
    WTF::String extension = checkAndEnsureBit8String(mimeType);
    if (extension.isEmpty())
        return false;

    static WTF::HashSet<WTF::String>* supportedJavaScriptMIMETypes;
    if (!supportedJavaScriptMIMETypes) {
        supportedJavaScriptMIMETypes = new WTF::HashSet<WTF::String>();
        /*
    Mozilla 1.8 and WinIE 7 both accept text/javascript and text/ecmascript.
    Mozilla 1.8 accepts application/javascript, application/ecmascript, and application/x-javascript, but WinIE 7 doesn't.
    WinIE 7 accepts text/javascript1.1 - text/javascript1.3, text/jscript, and text/livescript, but Mozilla 1.8 doesn't.
    Mozilla 1.8 allows leading and trailing whitespace, but WinIE 7 doesn't.
    Mozilla 1.8 and WinIE 7 both accept the empty string, but neither accept a whitespace-only string.
    We want to accept all the values that either of these browsers accept, but not other values.
    */
        static const char* types[] = {
            "text/javascript",
            "text/ecmascript",
            "application/javascript",
            "application/ecmascript",
            "application/x-javascript",
            "text/javascript1.1",
            "text/javascript1.2",
            "text/javascript1.3",
            "text/jscript",
            "text/livescript",
#if V8_MAJOR_VERSION >= 7
            "module",
#endif
        };
        for (size_t i = 0; i < WTF_ARRAY_LENGTH(types); ++i)
            supportedJavaScriptMIMETypes->add(types[i]);
    }

    return supportedJavaScriptMIMETypes->contains(extension);
}

bool MIMETypeRegistry::isSupportedNonImageMIMEType(const String& mimeType)
{
    //return mime_util::IsSupportedNonImageMimeType(ToLowerASCIIOrEmpty(mimeType));
    WTF::String extension = checkAndEnsureBit8String(mimeType);
    if (extension.isEmpty())
        return false;

    static HashSet<String>* supportedNonImageMIMETypes;

    if (!supportedNonImageMIMETypes) {
        supportedNonImageMIMETypes = new HashSet<String>();

        static const char* types[] = {
            "text/html",
            "text/xml",
            "text/xsl",
            "text/plain",
            "text/",
            "application/xml",
            "application/xhtml+xml",
            "application/vnd.wap.xhtml+xml",
            "application/rss+xml",
            "application/atom+xml",
            "application/json",
            //#if ENABLE(SVG)
            "image/svg+xml",
            //#endif
            "application/x-ftp-directory",
            "multipart/x-mixed-replace"
            // Note: ADDING a new type here will probably render it as HTML. This can
            // result in cross-site scripting.
        };
        //COMPILE_ASSERT(sizeof(types) / sizeof(types[0]) <= 16, "nonimage_mime_types_must_be_less_than_or_equal_to_16");

        for (size_t i = 0; i < WTF_ARRAY_LENGTH(types); ++i)
            supportedNonImageMIMETypes->add(types[i]);
    }

    return supportedNonImageMIMETypes->contains(extension);
}

bool MIMETypeRegistry::isSupportedMediaMIMEType(const String& mimeType, const String& codecs)
{
    return supportsMediaMIMEType(mimeType, codecs) != IsNotSupported;
}

static HashSet<String>& mimeTypeMediaCache()
{
    static HashSet<String>* cache = nullptr;
    if (!cache) {
        cache = new HashSet<String>();
        const char* mimeTypes[] = {
            "video/mp4",
            "audio/mp4",
            "audio/mpeg",
            "video/mpeg",
            "audio/mp3",
            "video/mp3",
        };
        for (auto& type : mimeTypes)
            cache->add(type);
    }

    return *cache;
}

static bool supportsCodecs(const String& codecs)
{
    static Vector<const char*>* supportedCodecs = nullptr;
    if (!supportedCodecs) {
        supportedCodecs = new Vector<const char*>();
        supportedCodecs->append("avc*");
        supportedCodecs->append("mp4a*");
        supportedCodecs->append("mpeg");
        supportedCodecs->append("x-h264");
    }
    Vector<String> codecEntries;
    codecs.split(',', false, codecEntries);

    for (String codec : codecEntries) {
        bool isCodecSupported = false;

        // If the codec is named like a mimetype (eg: video/avc) remove the "video/" part.
        size_t slashIndex = codec.find('/');
        if (slashIndex != WTF::kNotFound)
            codec = codec.substring(slashIndex + 1);

        CString codecData = codec.utf8();
        for (size_t i = 0; i < supportedCodecs->size(); ++i) {
            const char* pattern = supportedCodecs->at(i);
            isCodecSupported = !fnmatch(pattern, codecData.data(), 0);
            if (isCodecSupported)
                break;
        }
        if (!isCodecSupported)
            return false;
    }

    return true;
}

MIMETypeRegistry::SupportsType MIMETypeRegistry::supportsMediaMIMEType(
    const String& mimeType,
    const String& codecs)
{
    //   const std::string asciiMimeType = ToLowerASCIIOrEmpty(mimeType);
    //   std::vector<std::string> codecVector;
    //   media::ParseCodecString(ToASCIIOrEmpty(codecs), &codecVector, false);
    //   return static_cast<SupportsType>(media::IsSupportedMediaFormat(asciiMimeType, codecVector));

    MIMETypeRegistry::SupportsType result = IsNotSupported;
    // Spec says we should not return "probably" if the typeCodecs string is empty.
    if (mimeTypeMediaCache().contains(mimeType)) {
        if (codecs.isEmpty())
            result = MayBeSupported;
        else
            result = supportsCodecs(codecs) ? IsSupported : IsNotSupported;
    }

    return result;
}

bool MIMETypeRegistry::isSupportedMediaSourceMIMEType(const String& mimeType, const String& codecs)
{
    //   const std::string asciiMimeType = ToLowerASCIIOrEmpty(mimeType);
    //   if (asciiMimeType.empty())
    //     return false;
    //   std::vector<std::string> parsedCodecIds;
    //   media::ParseCodecString(ToASCIIOrEmpty(codecs), &parsedCodecIds, false);
    //   return static_cast<MIMETypeRegistry::SupportsType>(media::StreamParserFactory::IsTypeSupported(asciiMimeType, parsedCodecIds));
    MIMETypeRegistry::SupportsType result = supportsMediaMIMEType(mimeType, codecs);
    return result == IsSupported || result == MayBeSupported;
}

bool MIMETypeRegistry::isJavaAppletMIMEType(const String& mimeType)
{
    // Since this set is very limited and is likely to remain so we won't bother
    // with the overhead of using a hash set.  Any of the MIME types below may be
    // followed by any number of specific versions of the JVM, which is why we use
    // startsWith()
    return mimeType.startsWith("application/x-java-applet",
               TextCaseASCIIInsensitive)
        || mimeType.startsWith("application/x-java-bean",
            TextCaseASCIIInsensitive)
        || mimeType.startsWith("application/x-java-vm", TextCaseASCIIInsensitive);
}

bool MIMETypeRegistry::isSupportedStyleSheetMIMEType(const String& mimeType)
{
    return equalIgnoringCase(mimeType, "text/css");
}

bool MIMETypeRegistry::isSupportedFontMIMEType(const String& mimeType)
{
    static const unsigned fontLen = 5;
    if (!mimeType.startsWith("font/", TextCaseASCIIInsensitive))
        return false;
    String subType = mimeType.substring(fontLen).lower();
    return subType == "woff" || subType == "woff2" || subType == "otf" || subType == "ttf" || subType == "sfnt";
}

bool MIMETypeRegistry::isSupportedTextTrackMIMEType(const String& mimeType)
{
    return equalIgnoringCase(mimeType, "text/vtt");
}

} // namespace blink
