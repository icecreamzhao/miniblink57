#include "WebMimeRegistryImpl.h"
#include "config.h"
#include "third_party/WebKit/public/platform/WebString.h"
#include <wtf/HashMap.h>
#include <wtf/text/StringHash.h>

namespace content {
WebMimeRegistryImpl::WebMimeRegistryImpl() { }
WebMimeRegistryImpl::~WebMimeRegistryImpl() { }

blink::WebMimeRegistry::SupportsType WebMimeRegistryImpl::supportsImagePrefixedMIMEType(const blink::WebString& mimeType)
{
    return blink::WebMimeRegistry::IsNotSupported;
}

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

// WebMimeRegistry methods:
blink::WebMimeRegistry::SupportsType WebMimeRegistryImpl::supportsMIMEType(const blink::WebString& ext)
{
    WTF::String extension = checkAndEnsureBit8String(ext);
    if (extension.isEmpty())
        return blink::WebMimeRegistry::IsNotSupported;

    static WTF::HashSet<WTF::String>* supportedMIMETypes;
    if (!supportedMIMETypes) {
        supportedMIMETypes = new WTF::HashSet<WTF::String>();

        static const char* types[] = {
            "text/plain",
            "text/html",
            "text/xml",
            "application/x-javascript",
            "application/xhtml+xml",
            "image/svg+xml",
            "image/jpeg",
            "image/png",
            "image/tiff",
            "image/ico",
            "image/bmp",
            "image/gif",
        };
        for (size_t i = 0; i < WTF_ARRAY_LENGTH(types); ++i)
            supportedMIMETypes->add(types[i]);
    }

    return supportedMIMETypes->contains(extension) ? blink::WebMimeRegistry::IsSupported : blink::WebMimeRegistry::IsNotSupported;
}

blink::WebMimeRegistry::SupportsType WebMimeRegistryImpl::supportsImageMIMEType(const blink::WebString& ext)
{
    WTF::String extension = checkAndEnsureBit8String(ext);
    if (extension.isEmpty())
        return blink::WebMimeRegistry::IsNotSupported;

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

    return supportedImageResourceMIMETypes->contains(extension) ? blink::WebMimeRegistry::IsSupported : blink::WebMimeRegistry::IsNotSupported;
}

blink::WebMimeRegistry::SupportsType WebMimeRegistryImpl::supportsJavaScriptMIMEType(const blink::WebString& ext)
{
    WTF::String extension = checkAndEnsureBit8String(ext);
    if (extension.isEmpty())
        return blink::WebMimeRegistry::IsNotSupported;

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

    return supportedJavaScriptMIMETypes->contains(extension) ? blink::WebMimeRegistry::IsSupported : blink::WebMimeRegistry::IsNotSupported;
}

blink::WebMimeRegistry::SupportsType WebMimeRegistryImpl::supportsMediaMIMEType(
    const blink::WebString&, const blink::WebString&)
{
    return blink::WebMimeRegistry::IsNotSupported;
}

bool WebMimeRegistryImpl::supportsMediaSourceMIMEType(const blink::WebString&, const blink::WebString&)
{
    return blink::WebMimeRegistry::IsNotSupported;
}

blink::WebMimeRegistry::SupportsType WebMimeRegistryImpl::supportsNonImageMIMEType(const blink::WebString& ext)
{
    WTF::String extension = checkAndEnsureBit8String(ext);
    if (extension.isEmpty())
        return blink::WebMimeRegistry::IsNotSupported;

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

    return supportedNonImageMIMETypes->contains(extension) ? blink::WebMimeRegistry::IsSupported : blink::WebMimeRegistry::IsNotSupported;
}

blink::WebString WebMimeRegistryImpl::mimeTypeForExtension(const blink::WebString& ext)
{
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

blink::WebString WebMimeRegistryImpl::wellKnownMimeTypeForExtension(
    const blink::WebString&)
{
    return blink::WebString();
}

// blink::WebString WebMimeRegistryImpl::mimeTypeFromFile(const blink::WebString&)
// {
//     return blink::WebString();
// }

} // namespace content