// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "config.h"
#include "content/web_impl_win/WebClipboardImpl.h"

#include "content/web_impl_win/BitmapColor.h"
#include "content/ui/ClipboardUtil.h"
#include "content/ui/SaveImage.h"
#include "content/browser/PostTaskHelper.h"
#include "third_party/WebKit/public/platform/WebData.h"
#include "third_party/WebKit/public/platform/WebDragData.h"
#include "third_party/WebKit/public/platform/WebImage.h"
#include "third_party/WebKit/public/platform/WebSize.h"
#include "third_party/WebKit/public/platform/WebString.h"
#include "third_party/WebKit/public/platform/WebURL.h"
#include "third_party/WebKit/public/platform/WebVector.h"
#include "third_party/WebKit/Source/wtf/text/CharacterNames.h"
#include "third_party/WebKit/Source/platform/geometry/IntSize.h"
//#include "third_party/WebKit/Source/platform/image-encoders/gdiplus/GDIPlusImageEncoder.h"
//#include "third_party/WebKit/Source/platform/image-encoders/skia/PNGImageEncoder.h"
#include "third_party/WebKit/Source/platform/clipboard/ClipboardMimeTypes.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkCanvas.h"
#include "third_party/skia/include/core/SkData.h"
#include "third_party/skia/include/core/SkImageEncoder.h"
#include "skia/ext/platform_canvas.h"
#include "skia/ext/bitmap_platform_device_win.h"
#include "wtf/text/WTFStringUtil.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
#include "net/FileSystem.h"
#include <windows.h>

#if USING_VC6RT == 1
#define PURE = 0
#endif

#include <shlobj.h>
#include <vector>
#include <gtk/gtk.h>

using blink::WebClipboard;
using blink::WebData;
using blink::WebDragData;
using blink::WebImage;
using blink::WebString;
using blink::WebURL;
using blink::WebVector;

namespace {

void freeData(unsigned int format, HANDLE data)
{
    if (format == CF_BITMAP)
        ::DeleteObject(static_cast<HBITMAP>(data));
    else
        ::GlobalFree(data);
}

template <class str>
void appendEscapedCharForHTMLImpl(typename str::value_type c, str* output)
{
    static const struct {
        char key;
        const char* replacement;
    } kCharsToEscape[] = {
        { '<', "&lt;" },
        { '>', "&gt;" },
        { '&', "&amp;" },
        { '"', "&quot;" },
        { '\'', "&#39;" },
    };
    size_t k;
    for (k = 0; k < arraysize(kCharsToEscape); ++k) {
        if (c == kCharsToEscape[k].key) {
            const char* p = kCharsToEscape[k].replacement;
            while (*p)
                //output->push_back(*p++);
                *output += (*p++);
            break;
        }
    }
    if (k == arraysize(kCharsToEscape))
        //output->push_back(c);
        *output += c;
}

template <class str>
str escapeForHTMLImpl(const str& input)
{
    str result;
    result.reserve(input.size());  // Optimize for no escaping.

    for (typename str::const_iterator i = input.begin(); i != input.end(); ++i)
        appendEscapedCharForHTMLImpl(*i, &result);

    return result;
}

std::string escapeForHTML(const Vector<char>& input)
{
    std::string inputStr(input.data(), input.size());
    return escapeForHTMLImpl(inputStr);
}

std::string escapeForHTML(const std::string input)
{
    return escapeForHTMLImpl(input);
}

std::string URLToMarkup(const blink::WebURL& url, const blink::WebString& title)
{
    std::string markup("<a href=\"");
    markup.append(WTF::ensureStringToUTF8(url.string(), true).data());
    markup.append("\">");
    // TODO(darin): HTML escape this
    markup.append(escapeForHTML(WTF::ensureStringToUTF8(title, true)));
    markup.append("</a>");
    return markup;
}

std::string URLToImageMarkup(const blink::WebURL& url, const blink::WebString& title)
{
    std::string markup("<img src=\"");
    markup.append(escapeForHTML(WTF::ensureStringToUTF8(url.string(), true).data()));
    markup.append("\"");
    if (!title.isEmpty()) {
        markup.append(" alt=\"");
        markup.append(escapeForHTML(WTF::ensureStringToUTF8(title, true)));
        markup.append("\"");
    }
    markup.append("/>");
    return markup;
}

// A scoper to impersonate the anonymous token and revert when leaving scope
class AnonymousImpersonator {
public:
    AnonymousImpersonator() {
        must_revert_ = ::ImpersonateAnonymousToken(::GetCurrentThread());
    }

    ~AnonymousImpersonator() {
        if (must_revert_)
            ::RevertToSelf();
    }

private:
    BOOL must_revert_;
    DISALLOW_COPY_AND_ASSIGN(AnonymousImpersonator);
};

// A scoper to manage acquiring and automatically releasing the clipboard.
class ScopedClipboard {
public:
    ScopedClipboard() : m_isOpened(false) { }

    ~ScopedClipboard()
    {
        if (m_isOpened)
            release();
    }

    bool acquire(HWND owner)
    {
        const int kMaxAttemptsToOpenClipboard = 5;

        if (m_isOpened) {
            notImplemented();
            return false;
        }

        // Attempt to open the clipboard, which will acquire the Windows clipboard
        // lock.  This may fail if another process currently holds this lock.
        // We're willing to try a few times in the hopes of acquiring it.
        //
        // This turns out to be an issue when using remote desktop because the
        // rdpclip.exe process likes to read what we've written to the clipboard and
        // send it to the RDP client.  If we open and close the clipboard in quick
        // succession, we might be trying to open it while rdpclip.exe has it open,
        // See Bug 815425.
        //
        // In fact, we believe we'll only spin this loop over remote desktop.  In
        // normal situations, the user is initiating clipboard operations and there
        // shouldn't be contention.

        for (int attempts = 0; attempts < kMaxAttemptsToOpenClipboard; ++attempts) {
            // If we didn't manage to open the clipboard, sleep a bit and be hopeful.
            if (attempts != 0)
                ::Sleep(5);

            if (::OpenClipboard(owner)) {
                m_isOpened = true;
                return true;
            }
        }

        // We failed to acquire the clipboard.
        return false;
    }

    void release() {
        if (m_isOpened) {
            // Impersonate the anonymous token during the call to CloseClipboard
            // This prevents Windows 8+ capturing the broker's access token which
            // could be accessed by lower-privileges chrome processes leading to
            // a risk of EoP
            AnonymousImpersonator impersonator;
            ::CloseClipboard();
            m_isOpened = false;
        }
        else {
            notImplemented();
        }
    }

private:
    bool m_isOpened;
};

}

namespace content {

WebClipboardImpl::WebClipboardImpl() 
    : m_clipboardOwner(NULL)
{
    m_clipboardOwner = getClipboardWindow();
}

WebClipboardImpl::~WebClipboardImpl()
{
}

uint64 WebClipboardImpl::sequenceNumber(Buffer buffer)
{
    return ::GetClipboardSequenceNumber();
}

bool WebClipboardImpl::isFormatAvailable(Format format, Buffer buffer)
{
    if (FormatPlainText == format)
        return true;
    return false;
//     ClipboardType clipboardType = CLIPBOARD_TYPE_COPY_PASTE;
//     if (!convertBufferType(buffer, &clipboardType))
//         return false;
//     ASSERT(clipboardType == CLIPBOARD_TYPE_COPY_PASTE);
// 
//     switch (format) {
//     case FormatPlainText:
//         return ::IsClipboardFormatAvailable(CF_UNICODETEXT) || ::IsClipboardFormatAvailable(CF_TEXT);
//     case FormatHTML: {
//         return ::IsClipboardFormatAvailable(ClipboardUtil::getHtmlFormatType());
//     }
//     case FormatSmartPaste:
//         return ::IsClipboardFormatAvailable(ClipboardUtil::getWebKitSmartPasteFormatType());
//     case FormatBookmark:
//         return ::IsClipboardFormatAvailable(ClipboardUtil::getUrlWFormatType());
//     default:
//         notImplemented();
//     }
// 
//     return false;
}

blink::WebVector<blink::WebString> WebClipboardImpl::readAvailableTypes(Buffer buffer, bool* containsFilenames) 
{
    ClipboardType clipboardType;
    Vector<WebString> types;
    if (convertBufferType(buffer, &clipboardType))
        readAvailableTypes(clipboardType, &types, containsFilenames);
    
    return types;
}

void WebClipboardImpl::readAvailableTypes(ClipboardType type, Vector<WebString>* types, bool* containsFilenames) const
{
    types->append(WebString::fromUTF8(kMimeTypeText));

//     if (!types || !containsFilenames) {
//         notImplemented();
//         return;
//     }
// 
//     *containsFilenames = false;
//     types->clear();
// 
//     if (::IsClipboardFormatAvailable(CF_TEXT))
//         types->append(WebString::fromUTF8(kMimeTypeText));
//     if (::IsClipboardFormatAvailable(ClipboardUtil::getHtmlFormatType()))
//         types->append(WebString::fromUTF8(kMimeTypeHTML));
//     if (::IsClipboardFormatAvailable(ClipboardUtil::getRtfFormatType()))
//         types->append(WebString::fromUTF8(kMimeTypeRTF));
// 
//     if (::IsClipboardFormatAvailable(CF_DIB)) {
//         types->append(WebString::fromUTF8(kMimeTypePNG));
//         return; // DataObjectItem::createFromPasteboard里只认识png格式。 不返回的话，wangEditor里会出现粘贴不了的问题
//     }
// 
//     if (::IsClipboardFormatAvailable(CF_BITMAP))
//         types->append(WebString::fromUTF8(kMimeTypeBMP));
}

blink::WebString WebClipboardImpl::readPlainText(Buffer buffer)
{
    printf("WebClipboardImpl::readPlainText\n");
    return blink::WebString();

//     ClipboardType clipboardType;
//     if (!convertBufferType(buffer, &clipboardType))
//         return blink::WebString();
// 
//     // Acquire the clipboard.
//     ScopedClipboard clipboard;
//     if (!clipboard.acquire(getClipboardWindow()))
//         return blink::WebString();
// 
//     HANDLE data = ::GetClipboardData(CF_UNICODETEXT);
//     if (!data)
//         return blink::WebString();
// 
//     LPCWSTR dataText = (LPCWSTR)::GlobalLock(data);
//     String text(dataText, wcslen(dataText));
//     ::GlobalUnlock(data);
//     return text;
}

static int getOffsetOfUtf8ToUtf16(const std::string& utf8Str, int offset)
{
    int length = utf8Str.size();
    if (offset >= length)
        offset = length - 1;

    Vector<char> subStr;
    subStr.resize(offset + 1);
    memcpy(subStr.data(), utf8Str.c_str(), offset + 1);

    std::vector<UChar> temp;
    WTF::MByteToWChar(subStr.data(), subStr.size(), &temp, CP_UTF8);
    return temp.size() > 0 ? temp.size() - 1 : 0;
}

blink::WebString WebClipboardImpl::readHTML(Buffer buffer, WebURL* sourceUrl,
    unsigned* fragmentStart,
    unsigned* fragmentEnd)
{
    printf("WebClipboardImpl::readHTML\n");
    return WebString();

//     ClipboardType clipboardType;
//     if (!convertBufferType(buffer, &clipboardType))
//         return blink::WebString();
// 
//     ASSERT(clipboardType == CLIPBOARD_TYPE_COPY_PASTE);
// 
//     std::string srcUrl;
// 
//     *fragmentStart = 0;
//     *fragmentEnd = 0;
// 
//     std::vector<char> utf8CfHtml;
//     {
//         // Acquire the clipboard.
//         ScopedClipboard clipboard;
//         if (!clipboard.acquire(getClipboardWindow()))
//             return WebString();
// 
//         HANDLE data = ::GetClipboardData(ClipboardUtil::getHtmlFormatType());
//         if (!data)
//             return blink::WebString();
// 
//         const char* cfHtml = static_cast<const char*>(::GlobalLock(data));
//         if (!cfHtml)
//             return blink::WebString();
// 
//         int sizeOfHtml = GlobalSize(data);
//         if (0 == sizeOfHtml)
//             return blink::WebString();
// 
//         if (sizeOfHtml > 5 && '\0' == cfHtml[1]) {
//             for (int i = 0; i < sizeOfHtml / 2; ++i) {
//                 if ('\0' == *((const WCHAR*)cfHtml + i)) {
//                     sizeOfHtml = i;
//                     break;
//                 }
//             }
// 
//             WTF::WCharToMByte((const WCHAR*)cfHtml, sizeOfHtml, &utf8CfHtml, CP_UTF8);
//         } else {
//             for (int i = 0; i < sizeOfHtml; ++i) {
//                 if ('\0' == *((const char*)cfHtml + i)) {
//                     sizeOfHtml = i;
//                     break;
//                 }
//             }
// 
//             if (!WTF::isTextUTF8(cfHtml, sizeOfHtml))
//                 WTF::MByteToUtf8(cfHtml, sizeOfHtml, &utf8CfHtml, CP_ACP);
//             else {
//                 utf8CfHtml.resize(sizeOfHtml);
//                 memcpy(&utf8CfHtml[0], cfHtml, sizeOfHtml);
//             }
//         }
// 
//         ::GlobalUnlock(data);
//     }
// 
//     if (0 == utf8CfHtml.size())
//         return blink::WebString();
//     utf8CfHtml.push_back('\0');
// 
//     size_t htmlStart = std::string::npos;
//     size_t startIndex = std::string::npos;
//     size_t endIndex = std::string::npos;
//     ClipboardUtil::cfHtmlExtractMetadata(&utf8CfHtml[0], &srcUrl, &htmlStart, &startIndex, &endIndex);
// 
//     // This might happen if the contents of the clipboard changed and CF_HTML is
//     // no longer available.
//     if (startIndex == std::string::npos || endIndex == std::string::npos || htmlStart == std::string::npos)
//         return blink::WebString();
// 
//     if (startIndex < htmlStart || endIndex < startIndex)
//         return blink::WebString();
// 
//     startIndex -= htmlStart;
//     endIndex -= htmlStart;
// 
//     std::string utf8CfHtmlStart = &utf8CfHtml[0] + htmlStart;
// 
//     startIndex = getOffsetOfUtf8ToUtf16(utf8CfHtmlStart, startIndex);
//     endIndex = getOffsetOfUtf8ToUtf16(utf8CfHtmlStart, endIndex);
// 
//     *fragmentStart = startIndex;
//     *fragmentEnd = endIndex;
// 
//     std::vector<UChar> result;
//     WTF::MByteToWChar(utf8CfHtmlStart.c_str(), utf8CfHtmlStart.size(), &result, CP_UTF8);
// 
//     blink::WebString resultStr;
//     resultStr.assign(&result[0], result.size());
//     return resultStr;
}

blink::WebBlobInfo WebClipboardImpl::readImage(Buffer buffer)
{
    DebugBreak();
    return blink::WebBlobInfo();
}

WebString WebClipboardImpl::readCustomData(Buffer buffer, const WebString& type)
{
    return WebString();
}

void WebClipboardImpl::writeToClipboardInternal(unsigned int format, HANDLE handle)
{
    printf("WebClipboardImpl::writeToClipboardInternal\n");
//     ASSERT(m_clipboardOwner != NULL);
//     if (handle && !::SetClipboardData(format, handle)) {
//         ASSERT(ERROR_CLIPBOARD_NOT_OPEN != GetLastError());
//         freeData(format, handle);
//     }
}

static std::string WebStringToAscii(const WebString& text)
{
    std::string result;
    String textStr = text;
    if (textStr.isNull() || textStr.isEmpty())
        return result;

    if (textStr.is8Bit())
        result = std::string((const char*)textStr.characters8(), textStr.length());
    else {
        std::vector<char> outBuf;
        WTF::WCharToMByte(textStr.characters16(), textStr.length(), &outBuf, CP_UTF8);
        if (outBuf.size() > 0)
            result = std::string(&outBuf[0], outBuf.size());
    }
    return result;
}

static std::string WebStringToUtf8(const WebString& text)
{
    std::string result;
    String textStr = text;
    if (textStr.isNull() || textStr.isEmpty())
        return result;

    std::vector<char> utf8Buffer;
    std::vector<UChar> wcharBuffer;
    if (textStr.is8Bit()) {
        utf8Buffer.resize(textStr.length());
        for (size_t i = 0; i < textStr.length(); ++i) {
            if (WTF::Unicode::noBreakSpaceCharacter == textStr[i]) {
                utf8Buffer[i] = ' ';
            } else
                utf8Buffer[i] = textStr[i];
        }
        WTF::MByteToWChar((const char*)&utf8Buffer[0], utf8Buffer.size(), &wcharBuffer, CP_ACP);
    } else {
        wcharBuffer.resize(textStr.length());
        memcpy(&wcharBuffer[0], textStr.characters16(), textStr.length() * 2);
    }
    
    WTF::WCharToMByte(&wcharBuffer[0], wcharBuffer.size(), &utf8Buffer, CP_UTF8);
    if (utf8Buffer.size() > 0)
        result = std::string(&utf8Buffer[0], utf8Buffer.size());
    return result;
}

void WebClipboardImpl::writeTextInternal(const String& string)
{
    printf("WebClipboardImpl::writeTextInternal 11:%d\n", string.length());

    std::vector<char>* outBuf = new std::vector<char>();
    if (!string.isEmpty()) {
        if (string.is8Bit()) {
            outBuf->resize(string.length());
            memcpy(outBuf->data(), string.characters8(), string.length());
        } else {
            WTF::WCharToMByte((const UChar*)string.characters16(), string.length(), outBuf, CP_UTF8);
        }
    }
    outBuf->push_back(0);
    //printf("WebClipboardImpl::writeTextInternal 22: %d\n", outBuf->size());

    postTaskToUiThread(FROM_HERE, NULL, [outBuf] {
        printf("WebClipboardImpl::writeTextInternal 2\n");
        GtkClipboard* clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
        printf("WebClipboardImpl::writeTextInternal 3: %s\n", outBuf->data());

        gtk_clipboard_set_text(clipboard, (const char*)outBuf->data(), outBuf->size() - 1);
        //gtk_clipboard_set_text(clipboard, (const char*)"aaa", 3);
        delete outBuf;
    });
}

void WebClipboardImpl::clearClipboard()
{
    printf("WebClipboardImpl::clearClipboard\n");
    ::EmptyClipboard();
}

void WebClipboardImpl::writePlainText(const WebString& plainText)
{
    printf("WebClipboardImpl::writePlainText\n");
//     ScopedClipboard clipboard;
//     if (!clipboard.acquire(getClipboardWindow()))
//         return;
// 
//     clearClipboard();
// 
    writeTextInternal(plainText);
}

void WebClipboardImpl::writeHTML(const WebString& htmlText, const WebURL& sourceUrl, const WebString& plainText, bool writeSmartPaste)
{
    printf("WebClipboardImpl::writeHTML 1\n");

    std::string markup = WebStringToUtf8(htmlText);

//     std::string url;
//     WTF::String urlString = sourceUrl.string();
//     if (!urlString.isNull() && !urlString.isEmpty())
//         url = WTFStringToStdString(urlString);

    writeTextInternal(plainText);

//     std::string htmlFragment = ClipboardUtil::htmlToCFHtml(markup, url);
// 
//     HGLOBAL glob = ClipboardUtil::createGlobalData<char>(htmlFragment);
//     writeToClipboardInternal(ClipboardUtil::getHtmlFormatType(), glob);
}

void WebClipboardImpl::writeHTMLInternal(const WebString& htmlText, const WebURL& sourceUrl, const WebString& plainText, bool writeSmartPaste)
{
    printf("WebClipboardImpl::writeHTMLInternal\n");
}

void WebClipboardImpl::writeBitmapFromHandle(HBITMAP sourceHBitmap, const blink::IntSize& size)
{
}

bool WebClipboardImpl::writeBitmapInternal(const SkBitmap& bitmap)
{
    return true;
}

void WebClipboardImpl::writeBookmark(const String& titleData , const String& urlData)
{
    printf("WebClipboardImpl::writeBookmark\n");
//     String bookmark = WTF::ensureUTF16String(titleData);
//     bookmark.append(L'\n');
//     bookmark.append(WTF::ensureUTF16String(urlData));
// 
//     std::string wideBookmark = WTF::WTFStringToStdString(bookmark);
//     HGLOBAL glob = ClipboardUtil::createGlobalData(wideBookmark);
// 
//     writeToClipboardInternal(ClipboardUtil::getUrlWFormatType(), glob);
}

void WebClipboardImpl::writeImage(const WebImage& image, const WebURL& url, const WebString& title)
{
    printf("WebClipboardImpl::writeImage\n");
//     if (saveImage(image, url))
//         return;
// 
//     ScopedClipboard clipboard;
//     if (!clipboard.acquire(getClipboardWindow()))
//         return;
// 
//     clearClipboard();
// 
//     ASSERT(!image.isNull());
//     const SkBitmap& bitmap = image.getSkBitmap();
//     if (!writeBitmapInternal(bitmap))
//         return;
// 
//     //return; // weolar
// 
//     if (!url.isEmpty()) { // chrome的ctrl+c会走writeHTML，而右键复制好像是走copyImageAt，此时会写两个剪切板项
//         //writeBookmark(url.string(), title);
// #if !defined(OS_MACOSX)
//         // When writing the image, we also write the image markup so that pasting
//         // into rich text editors, such as Gmail, reveals the image. We also don't
//         // want to call writeTextInternal(), since some applications (WordPad) don't pick
//         // the image if there is also a text format on the clipboard.
//         // We also don't want to write HTML on a Mac, since Mail.app prefers to use
//         // the image markup over attaching the actual image. See
//         // http://crbug.com/33016 for details.
//         writeHTMLInternal(WebString::fromUTF8(URLToImageMarkup(url, title)), WebURL(), WebString(), false);
// #endif
//     }
}

void WebClipboardImpl::writeDataObject(const WebDragData& data)
{
    printf("WebClipboardImpl::writeDataObject\n");
//     // TODO(dcheng): Properly support text/uri-list here.
//     // Avoid calling the WriteFoo functions if there is no data associated with a
//     // type. This prevents stomping on clipboard contents that might have been
//     // written by extension functions such as chrome.bookmarkManagerPrivate.copy.
// 
//     // DataObject::toWebDragData()
//     clearClipboard();
// 
//     ScopedClipboard clipboard;
//     if (!clipboard.acquire(getClipboardWindow()))
//         return;
// 
//     WebVector<WebDragData::Item> items = data.items();
//     for (size_t i = 0; i < items.size(); ++i) {
//         WebDragData::Item& it = items[i];
// 
//         if (WebDragData::Item::StorageTypeString == it.storageType) {
//             String stringType = it.stringType;
//             if (blink::mimeTypeTextPlain == stringType || blink::mimeTypeTextPlainEtc == stringType) {
//                 writeTextInternal(it.stringData);
//             } else if (blink::mimeTypeTextHTML == stringType) {
//                 //writeHTMLInternal(it.stringData, it.baseURL, WebString(), false);
//             }
//         }
//             
// //         if (!data_object.html.is_null())
// //             writeHTML(ui::CLIPBOARD_TYPE_COPY_PASTE, data_object.html.string(), GURL());
// //         if (!data_object.custom_data.empty())
// //             writeCustomData(ui::CLIPBOARD_TYPE_COPY_PASTE, data_object.custom_data);
//     }
}

bool WebClipboardImpl::convertBufferType(Buffer buffer, ClipboardType* result)
{
//     *result = CLIPBOARD_TYPE_COPY_PASTE;
//     switch (buffer) {
//     case BufferStandard:
//         break;
//     case BufferSelection:
//         // Chrome OS and non-X11 unix builds do not support
//         // the X selection clipboad.
//         // TODO: remove the need for this case, see http://crbug.com/361753
//         return false;
//     default:
//         notImplemented();
//         return false;
//     }
    return true;
}

HWND WebClipboardImpl::getClipboardWindow()
{
    return NULL;
}

}  // namespace content
