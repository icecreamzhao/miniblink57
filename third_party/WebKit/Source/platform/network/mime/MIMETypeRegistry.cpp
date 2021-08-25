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

bool MIMETypeRegistry::isSupportedMediaMIMEType(const String& mimeType,
    const String& codecs)
{
    return supportsMediaMIMEType(mimeType, codecs) != IsNotSupported;
}

MIMETypeRegistry::SupportsType MIMETypeRegistry::supportsMediaMIMEType(
    const String& mimeType,
    const String& codecs)
{
    //   const std::string asciiMimeType = ToLowerASCIIOrEmpty(mimeType);
    //   std::vector<std::string> codecVector;
    //   media::ParseCodecString(ToASCIIOrEmpty(codecs), &codecVector, false);
    //   return static_cast<SupportsType>(
    //       media::IsSupportedMediaFormat(asciiMimeType, codecVector));
    return IsNotSupported;
}

bool MIMETypeRegistry::isSupportedMediaSourceMIMEType(const String& mimeType,
    const String& codecs)
{
    //   const std::string asciiMimeType = ToLowerASCIIOrEmpty(mimeType);
    //   if (asciiMimeType.empty())
    //     return false;
    //   std::vector<std::string> parsedCodecIds;
    //   media::ParseCodecString(ToASCIIOrEmpty(codecs), &parsedCodecIds, false);
    //   return static_cast<MIMETypeRegistry::SupportsType>(
    //       media::StreamParserFactory::IsTypeSupported(asciiMimeType,
    //                                                   parsedCodecIds));
    DebugBreak();
    return false;
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
