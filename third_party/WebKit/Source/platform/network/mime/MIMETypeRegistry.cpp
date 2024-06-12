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

// https://opensource.apple.com/source/Libc/Libc-262/gen/fnmatch.c.auto.html
// https://www.cnblogs.com/oloroso/p/6861576.html
#define	EOS	'\0'

#define RANGE_MATCH     1
#define RANGE_NOMATCH   0
#define RANGE_ERROR     (-1)

#define	FNM_NOMATCH	1	/* Match failed. */

#define	FNM_NOESCAPE	0x01	/* ���÷�б�ܽ���ת�� */
#define	FNM_PATHNAME	0x02	/* б��ֻ�ܱ�б��ƥ��(�����ܱ�*����?ƥ��) */
#define	FNM_PERIOD	0x04	/* Period must be matched by period. */
/*��������־�����ˣ�string �����ʼ��ű���ƥ�� pattern ��ĵ�š�
һ����ű���Ϊ����ʼ��ţ��������string ��һ���ַ����������ͬʱ��
���� FNM_PATHNAME��������б�ܺ���ĵ�š�
*/
#define	FNM_LEADING_DIR	0x08	/* Ignore /<tail> after Imatch. */
/*��������־(GNU ��չ)�����ˣ�ģʽ����ƥ�������б��֮��� string
�ĳ�ʼƬ�ϡ������־��Ҫ�Ǹ� glibc �ڲ�ʹ�ò���ֻ��һ��������ʵ�֡�
��ֻƥ��Ŀ¼·�����֣���ƥ�䵽�����ļ���
*/
#define	FNM_CASEFOLD	0x10	/* ģʽƥ����Դ�Сд. */
#define FNM_PREFIX_DIRS	0x20	/* Directory prefixes of pattern match too. */

// �ַ���Χƥ��
// pattern������ [a-x]*** ��ʽ���ַ���
// ƥ��ʧ�ܻ�ƥ�䵽EOS����(Ҳ��ʧ��)������NULL
// �ɹ�����ƥ�䴮����һ��ƥ��ɷ��׵�ַ
static const char* rangematch(const char *pattern, char test, int flags)
{
    // �˴�û�ж�c���г�ʼ�������ܳ����⣨ջ�ϱ���Ĭ��ֵδ����
    int negate, ok;
    char c, c2;

    /*
    * A bracket expression starting with an unquoted circumflex
    * character produces unspecified results
    * �������� ^ �ַ���ʼ�ķ����ű��ʽ��������δָ���Ľ��
    * (IEEE 1003.2-1992,3.13.2).  ��ʵ�ֽ�����Ϊ '!',����������ʽ�﷨����һ��.
    * J.T. Conklin (conklin@ngai.kaleida.com)
    */
    // ��ⷽ���ű��ʽ�е�һ���ַ�
    // ���Ϊ!����^����Ժ���ƥ��Ľ��ȡ��
    if ((negate = (*pattern == '!' || *pattern == '^'))){
        ++pattern;
    }

    // ���Դ�Сд����תΪСд����
    if (flags & FNM_CASEFOLD){
        test = WTF::toASCIILower((unsigned char)test);
    }
    // ѭ���������ű��ʽ����
    for (ok = 0; (c = *pattern++) != ']';) {
        // ���û�н���ת�壬��ȡ�ַ�
        if (c == '\\' && !(flags & FNM_NOESCAPE)){
            c = *pattern++;
        }
        // ƥ�����
        if (c == EOS){
            return (NULL);
        }
        // ���Դ�Сд����תΪСд
        if (flags & FNM_CASEFOLD){
            c = WTF::toASCIILower((unsigned char)c);
        }
        // �����ǰƥ����c ����һ����'-'�����ȡ'-'�����һ���ַ�
        // ���磬ƥ�䴮Ϊ [a-x] ��ǰcΪa,��c2Ϊx����ʾƥ��a-x֮���ַ�
        if (*pattern == '-'
            && (c2 = *(pattern + 1)) != EOS && c2 != ']') {
            pattern += 2;
            // �ж��Ƿ���Ҫת��
            if (c2 == '\\' && !(flags & FNM_NOESCAPE)){
                c2 = *pattern++;
            }
            if (c2 == EOS){
                return (NULL);
            }
            // �ж��Ƿ����ִ�Сд
            if (flags & FNM_CASEFOLD){
                c2 = WTF::toASCIILower((unsigned char)c2);
            }
            // �ж�test�Ƿ�λ�� [c,c2]����
            if ((unsigned char)c <= (unsigned char)test &&
                (unsigned char)test <= (unsigned char)c2){
                ok = 1;
            }
        }
        else if (c == test){
            ok = 1;
        }
    }
    // ����ƥ����
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
        // ���ȡƥ���ַ����еĳɷ�(��Ϊ*?��range����)
        switch (c = *pattern++) {
        case EOS:   // û��ƥ�䴮�����
                    // �������'/'����Ĳ��֣���ƥ��ɹ�
            if ((flags & FNM_LEADING_DIR) && *string == '/') {
                return (0);
            }
            // ���stringҲ�ǿմ�����ƥ��ɹ�
            return (*string == EOS ? 0 : FNM_NOMATCH);
        case '?':   // ƥ�䵥�������ַ�
                    // stringΪ������ƥ��
            if (*string == EOS) {
                return (FNM_NOMATCH);
            }
            // �ж�'/'�Ƿ�ֻ����'/'����ƥ��
            if (*string == '/' && (flags & FNM_PATHNAME)) {
                return (FNM_NOMATCH);
            }
            // �ж��Ƿ�string�е���ʼ'.'����ƥ��pattern�е�'.'����'?'����ƥ��'.'��
            if (*string == '.' && (flags & FNM_PERIOD) &&
                (string == stringstart ||
                    ((flags & FNM_PATHNAME) && *(string - 1) == '/'))) {
                return (FNM_NOMATCH);
            }
            // ƥ��ɹ���ƥ��string����һ���ַ�
            ++string;
            break;
        case '*':   // ƥ�䵥�����������ַ�
            c = *pattern;
            /* ���'*'����һ�� */
            while (c == '*') {
                c = *++pattern;
            }
            // �ж��Ƿ���Ҫ��'.'���д���
            if (*string == '.' && (flags & FNM_PERIOD) &&
                (string == stringstart ||
                    ((flags & FNM_PATHNAME) && *(string - 1) == '/'))) {
                return (FNM_NOMATCH);
            }

            /* �Ż� * ��ƥ�䴮��β������ /. ֮ǰ��ƥ��*/
            if (c == EOS) {  // �ڽ�β
                             // �ж� * �Ƿ�ƥ��б��
                if (flags & FNM_PATHNAME) {
                    // ��ƥ��б�ܣ����ж��Ƿ����'/'֮�󲿷�
                    return ((flags & FNM_LEADING_DIR) ||
                        ((strchr(string, '/') == NULL) ? 0 : FNM_NOMATCH));
                } else {
                    return (0);
                }
            } else if (c == '/' && flags & FNM_PATHNAME) { // �� /. ֮ǰ
                                                           // ���string��û�� '/'��ƥ��ʧ��
                if ((string = strchr(string, '/')) == NULL) {
                    return (FNM_NOMATCH);
                }
                break;
            }

            /* ����������£��ݹ�ƥ�� */
            while ((test = *string) != EOS) {
                // ����'.'�������⴦������ƥ�䣨��ֻ���ж�'/'ƥ�������
                if (!fnmatch(pattern, string, flags & ~FNM_PERIOD)) {
                    return (0); // ƥ��ɹ�
                }
                // �� '/'���д���б��ֻƥ��б�ܣ���ƥ��ʧ�ܣ�
                if (test == '/' && flags & FNM_PATHNAME) {
                    break;
                }
                ++string;
            }
            // ����ƥ��ʧ�ܣ���*û��ƥ��ɹ�,'.'��'/'�ϵ�ƥ��û�гɹ���
            return (FNM_NOMATCH);
        case '[':   // range ��Χƥ��
            if (*string == EOS) {
                return (FNM_NOMATCH);   // �մ�ƥ��ʧ��
            }
            if (*string == '/' && flags & FNM_PATHNAME) {
                return (FNM_NOMATCH);   // '/'ƥ��ʧ��
            }
            if ((pattern =
                rangematch(pattern, *string, flags)) == NULL) {
                return (FNM_NOMATCH);   // ��Χƥ��ʧ��
            }
            ++string;
            break;
        case '\\':  // б��ƥ�䣨�ж��Ƿ���Ҫת�壩
            if (!(flags & FNM_NOESCAPE)) {
                if ((c = *pattern++) == EOS) {
                    c = '\\';
                    --pattern;
                }
            }
            /* ���������֣���ֱ��ƥ�䵥���ַ� */
        default:
            if (c == *string) {
                ;   // ֱ��ƥ������
            } else if ((flags & FNM_CASEFOLD) &&
                (WTF::toASCIILower((unsigned char)c) ==
                    WTF::toASCIILower((unsigned char)*string))) {
                ;   // ���Դ�Сдƥ��ɹ�
            } else if ((flags & FNM_PREFIX_DIRS) && *string == EOS &&
                ((c == '/' && string != stringstart) ||
                    (string == stringstart + 1 && *stringstart == '/'))) {
                return (0); // ƥ��ɹ�
            } else {
                return (FNM_NOMATCH); // ƥ��ʧ��
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
    if ("text/html" == mimeType)
        return true;
    if ("text/vnd.wap.wml" == mimeType)
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
