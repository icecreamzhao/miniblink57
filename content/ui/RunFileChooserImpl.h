
#ifndef content_browser_RunFileChooserImpl_h
#define content_browser_RunFileChooserImpl_h

#include "third_party/WebKit/public/web/WebFileChooserParams.h"
#include "third_party/WebKit/public/web/WebFileChooserCompletion.h"
#include "third_party/WebKit/public/platform/WebVector.h"
#include "third_party/WebKit/public/platform/WebString.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include "third_party/WebKit/public/platform/WebFileUtilities.h"
#include "third_party/WebKit/Source/wtf/text/WTFStringUtil.h"
#include "net/ActivatingObjCheck.h"

#include <vector>
#define interface struct

#include <windows.h>
#include <objbase.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <process.h>

namespace content {

#if defined(OS_WIN)

static void appendStringToVector(std::vector<char>* result, const Vector<char>& str)
{
    result->reserve(result->size() + str.size());
    const char* p = str.data();
    const char* end = p + str.size();
    while (p < end) {
        result->push_back(*p);
        ++p;
    }
}

static void appendStringToVector(std::vector<char>* result, const std::vector<char>& str)
{
    result->reserve(result->size() + str.size());
    const char* p = str.data();
    const char* end = p + str.size();
    while (p < end) {
        result->push_back(*p);
        ++p;
    }
}

static void appendStringToVector(std::vector<char>* result, const std::string& str)
{
    Vector<char> strBuf;
    strBuf.resize(str.size());
    memcpy(strBuf.data(), str.c_str(), str.size());
    appendStringToVector(result, strBuf);
}

std::string extentionForMimeType(const Vector<char>& mimeType)
{
    const char* end = mimeType.data() + mimeType.size();
    const char* p = end - 1;
    while (p > mimeType.data()) {
        if ('/' == *p) {
            return std::string(p + 1, end);
        }
        --p;
    }
    return "*";
}

std::string extentionForMimeType(const std::string& mimeType)
{
    Vector<char> mimeTypeBuf;
    mimeTypeBuf.resize(mimeType.size());
    memcpy(mimeTypeBuf.data(), mimeType.c_str(), mimeType.size());
    return extentionForMimeType(mimeTypeBuf);
}


static bool doMatch(const char* pattern, const char* content)
{
    // if we reatch both end of two string, we are done  
    if ('\0' == *pattern && '\0' == *content)
        return true;

    // make sure that the characters after '*' are present in second string.
    // this function assumes that the first string will not contain two
    // consecutive '*'
    if ('*' == *pattern && '\0' != *(pattern + 1) && '\0' == *content)
        return false;

    // if the first string contains '?', or current characters of both   
    // strings match  
    if ('?' == *pattern || *pattern == *content)
        return doMatch(pattern + 1, content + 1);

    // if there is *, then there are two possibilities
    // a) We consider current character of second string
    // b) We ignore current character of second string.
    if ('*' == *pattern)
        return doMatch(pattern + 1, content) || doMatch(pattern, content + 1);
    return false;
}

static bool wildcardMatch(const WTF::String& pattern, const WTF::String& content)
{
    CString patternStr = pattern.utf8();
    CString contentStr = content.utf8();
    bool result = doMatch(patternStr.data(), contentStr.data());
    if (!result)
        result = (WTF::kNotFound != content.find(pattern));

    return result;
}

WTF::HashMap<WTF::String, WTF::String>* m_mimetypeMap = nullptr;

struct MimetypeToExt {
    WTF::String mime;
    WTF::Vector<WTF::String> exts;
};
struct MimetypeToExtMap {
    WTF::Vector<MimetypeToExt*> m_map;
    void add(const char* mine, ...);
};

void MimetypeToExtMap::add(const char* mime, ...)
{
    va_list arg_list;
    va_start(arg_list, mime);

    MimetypeToExt* it = new MimetypeToExt();
    it->mime = mime;

    do {
        const char* ext = va_arg(arg_list, const char*);
        if (!ext)
            break;

        it->exts.append(ext);
    } while (true);
    m_map.append(it);
}

MimetypeToExtMap* m_mimetypeToExtMap = nullptr;

void ensureMimeTypeMap()
{
    if (m_mimetypeMap)
        return;

    m_mimetypeMap = new WTF::HashMap<WTF::String, WTF::String>();
    //fill with initial values
    m_mimetypeMap->add("txt", "text/plain");
    m_mimetypeMap->add("pdf", "application/pdf");
    m_mimetypeMap->add("ps", "application/postscript");
    m_mimetypeMap->add("html", "text/html");
    m_mimetypeMap->add("htm", "text/html");
    m_mimetypeMap->add("xml", "text/xml");
    m_mimetypeMap->add("xsl", "text/xsl");
    m_mimetypeMap->add("xls", "application/xls+vnd.ms-excel");
    m_mimetypeMap->add("js", "application/x-javascript");
    m_mimetypeMap->add("xhtml", "application/xhtml+xml");
    m_mimetypeMap->add("rss", "application/rss+xml");
    m_mimetypeMap->add("webarchive", "application/x-webarchive");
    m_mimetypeMap->add("svg", "image/svg+xml");
    m_mimetypeMap->add("svgz", "image/svg+xml");
    m_mimetypeMap->add("jpg", "image/jpeg");
    m_mimetypeMap->add("jpeg", "image/jpeg");
    m_mimetypeMap->add("png", "image/png");
    m_mimetypeMap->add("gif", "image/gif");
    m_mimetypeMap->add("tif", "image/tiff");
    m_mimetypeMap->add("tiff", "image/tiff");
    m_mimetypeMap->add("ico", "image/ico");
    m_mimetypeMap->add("cur", "image/ico");
    m_mimetypeMap->add("bmp", "image/bmp");
    m_mimetypeMap->add("wml", "text/vnd.wap.wml");
    m_mimetypeMap->add("wmlc", "application/vnd.wap.wmlc");
    m_mimetypeMap->add("swf", "application/x-shockwave-flash");
    m_mimetypeMap->add("mp4", "video/mp4");
    m_mimetypeMap->add("ogg", "video/ogg");
    m_mimetypeMap->add("webm", "video/webm");
    m_mimetypeMap->add("mht", "multipart/related");
    m_mimetypeMap->add("mhtml", "multipart/related");

    m_mimetypeMap->add("hex", "application/hex");
    m_mimetypeMap->add("rbf", "application/rbf");
    m_mimetypeMap->add("bin", "application/bin");
    m_mimetypeMap->add("zip", "application/zip");
    m_mimetypeMap->add("rar", "application/rar");
    m_mimetypeMap->add("doc", "application/doc");
    m_mimetypeMap->add("docx", "application/docx");

    m_mimetypeMap->add("pcx", "image/pcx");
    m_mimetypeMap->add("tga", "image/tga");
    m_mimetypeMap->add("exif", "image/exif");
    m_mimetypeMap->add("fpx", "image/fpx");
    m_mimetypeMap->add("psd", "image/psd");
    m_mimetypeMap->add("cdr", "image/cdr");
    m_mimetypeMap->add("pcd", "image/pcd");
    m_mimetypeMap->add("dxf", "image/dxf");
    m_mimetypeMap->add("ufo", "image/ufo");
    m_mimetypeMap->add("eps", "image/eps");
    m_mimetypeMap->add("ai", "image/ai");
    m_mimetypeMap->add("raw", "image/raw");
    m_mimetypeMap->add("wmf", "image/wmf");
    m_mimetypeMap->add("webp", "image/webp");

    m_mimetypeToExtMap = new MimetypeToExtMap();
    m_mimetypeToExtMap->add("application/rss+xml", "rss", nullptr);
    m_mimetypeToExtMap->add("image/jpeg", "jpeg", nullptr);
    m_mimetypeToExtMap->add("application/pdf", "pdf", nullptr);
    m_mimetypeToExtMap->add("image/ico", "cur", nullptr);
    m_mimetypeToExtMap->add("application/xls+vnd.ms-excel", "xls", nullptr);
    m_mimetypeToExtMap->add("image/svg+xml", "svg", nullptr);
    m_mimetypeToExtMap->add("image/webp", "webp", nullptr);
    m_mimetypeToExtMap->add("application/zip", "zip", nullptr);
    m_mimetypeToExtMap->add("image/svg+xml", "svgz", nullptr);
    m_mimetypeToExtMap->add("image/psd", "psd", nullptr);
    m_mimetypeToExtMap->add("application/x-shockwave-flash", "swf", nullptr);
    m_mimetypeToExtMap->add("image/jpeg", "jpg", "pjp", "jpeg", "pjpeg", "jfif", nullptr);
    m_mimetypeToExtMap->add("multipart/related", "mhtml", nullptr);
    m_mimetypeToExtMap->add("image/bmp", "bmp", "dib", nullptr);
    m_mimetypeToExtMap->add("application/postscript", "ps", nullptr);
    m_mimetypeToExtMap->add("application/vnd.wap.wmlc", "wmlc", nullptr);
    m_mimetypeToExtMap->add("application/x-webarchive", "webarchive", nullptr);
    m_mimetypeToExtMap->add("application/rbf", "rbf", nullptr);
    m_mimetypeToExtMap->add("text/xml", "xml", nullptr);
    m_mimetypeToExtMap->add("image/raw", "raw", nullptr);
    m_mimetypeToExtMap->add("application/docx", "docx", nullptr);
    m_mimetypeToExtMap->add("application/x-javascript", "js", nullptr);
    m_mimetypeToExtMap->add("image/tiff", "tiff", nullptr);
    m_mimetypeToExtMap->add("text/html", "html", nullptr);
    m_mimetypeToExtMap->add("image/png", "png", nullptr);
    m_mimetypeToExtMap->add("image/x-png", "png", nullptr);
    m_mimetypeToExtMap->add("text/html", "htm", nullptr);
    m_mimetypeToExtMap->add("image/tiff", "tif", nullptr);
    m_mimetypeToExtMap->add("video/webm", "webm", nullptr);
    m_mimetypeToExtMap->add("application/rar", "rar", nullptr);
    m_mimetypeToExtMap->add("application/doc", "doc", nullptr);
    m_mimetypeToExtMap->add("image/exif", "exif", nullptr);
    m_mimetypeToExtMap->add("video/ogg", "ogg", nullptr);
    m_mimetypeToExtMap->add("text/plain", "txt", nullptr);
    m_mimetypeToExtMap->add("image/ico", "ico", nullptr);
    m_mimetypeToExtMap->add("application/xhtml+xml", "xhtml", nullptr);
    m_mimetypeToExtMap->add("multipart/related", "mht", nullptr);
    m_mimetypeToExtMap->add("image/eps", "eps", nullptr);
    m_mimetypeToExtMap->add("image/tga", "tga", nullptr);
    m_mimetypeToExtMap->add("text/vnd.wap.wml", "wml", nullptr);
    m_mimetypeToExtMap->add("image/gif", "gif", nullptr);
    m_mimetypeToExtMap->add("image/ai", "ai", nullptr);
    m_mimetypeToExtMap->add("image/cdr", "cdr", nullptr);
    m_mimetypeToExtMap->add("application/hex", "hex", nullptr);
    m_mimetypeToExtMap->add("image/ufo", "ufo", nullptr);
    m_mimetypeToExtMap->add("text/xsl", "xsl", nullptr);
    m_mimetypeToExtMap->add("image/dxf", "dxf", nullptr);
    m_mimetypeToExtMap->add("application/bin", "bin", nullptr);
    m_mimetypeToExtMap->add("image/wmf", "wmf", nullptr);
    m_mimetypeToExtMap->add("image/pcd", "pcd", nullptr);
    m_mimetypeToExtMap->add("video/mp4", "mp4", nullptr);
    m_mimetypeToExtMap->add("image/pcx", "pcx", nullptr);
    m_mimetypeToExtMap->add("image/fpx", "fpx", nullptr);
}

static Vector<blink::WebString> extensionsForMimeType(const blink::WebString& mime)
{
    ASSERT(isMainThread());

    Vector<blink::WebString> result;
    if (mime.isNull() || mime.isEmpty())
        return result;

    String mimeStr = mime;
    if (WTF::kNotFound == mimeStr.find('*') && WTF::kNotFound == mimeStr.find('/')) {
        result.append(mimeStr);
        return result;
    }

    ensureMimeTypeMap();
    for (size_t i = 0; i < m_mimetypeToExtMap->m_map.size(); ++i) {
        MimetypeToExt* it = m_mimetypeToExtMap->m_map[i];
        if (!wildcardMatch(mime, it->mime))
            continue;
        for (size_t j = 0; j < it->exts.size(); ++j) {
            WTF::String ext = it->exts[j];
            result.append(ext);
        }
    }
    return result;
}

static Vector<char> getMimeType(const WebString& mime)
{
    String mimeType = mime;
    if (mimeType.isNull() || mimeType.isEmpty())
        return Vector<char>();

    Vector<blink::WebString> mimeTypes = extensionsForMimeType(mime);

    if (mimeType.isNull() || mimeType.isEmpty()) {
        mimeType = mime;
        if (mimeType[0] == '.')
            mimeType.remove(0);
    }
    Vector<char> mimeTypeBuf = WTF::ensureStringToUTF8(mimeType, false);
    return mimeTypeBuf;
}

static void addForExtensions(const Vector<blink::WebString>& exts, const String& description, std::vector<char>* filter)
{
    if (exts.isEmpty())
        return;

    appendStringToVector(filter, description.utf8().data());
    filter->push_back('\0');

    for (Vector<blink::WebString>::const_iterator it = exts.begin(); it != exts.end(); ++it) {
        std::string str = "*.";
        str += it->utf8().data();
        appendStringToVector(filter, str);
        filter->push_back(';');
    }
    filter->push_back('\0');
}

// static bool runFileChooserTest(const blink::WebFileChooserParams& params, blink::WebFileChooserCompletion* completion)
// {
//     std::vector<wchar_t> fileNameBuf;
//     const int fileNameBufLen = 8192;
//     fileNameBuf.resize(fileNameBufLen);
//     memset(&fileNameBuf[0], 0, sizeof(wchar_t) * fileNameBufLen);
// 
//     OPENFILENAMEW ofn = { 0 };
//     ofn.lStructSize = sizeof(OPENFILENAMEW);
//     ofn.hwndOwner = nullptr;
//     ofn.hInstance = nullptr;
//     ofn.lpstrFilter = L"*/*";
//     ofn.lpstrFile = &fileNameBuf[0];
//     ofn.nMaxFile = fileNameBufLen - 2;
//     ofn.lpstrTitle = L"hahahahahah";
//     ofn.Flags = OFN_EXPLORER | OFN_LONGNAMES | OFN_NOCHANGEDIR;
//     OPENFILENAMEW* ofnPtr = &ofn;
// 
//     bool saveAs = params.saveAs;
//     bool multiSelect = params.multiSelect;
//     BOOL retVal = FALSE;
//     BOOL finish = FALSE;
//     std::function<void(void)>* callback = new std::function<void(void)>([ofnPtr, saveAs, multiSelect, &retVal, &finish] {
//         ofnPtr->hwndOwner = createHideWindow();
//         if (saveAs) {
//             ofnPtr->Flags = OFN_OVERWRITEPROMPT;
//             retVal = ::GetSaveFileNameW(ofnPtr);
//         } else if (multiSelect) {
//             ofnPtr->Flags |= OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_ALLOWMULTISELECT;
//             retVal = ::GetOpenFileNameW(ofnPtr);
//         } else {
//             ofnPtr->Flags |= OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
//             retVal = ::GetOpenFileNameW(ofnPtr);
//         }
//         finish = TRUE;
//     });
// 
//     unsigned int threadIdentifier = 0;
//     HANDLE threadHandle = reinterpret_cast<HANDLE>(_beginthreadex(0, 0, getOpenFileNameThread, callback, 0, &threadIdentifier));
//     while (!finish) {
//         ::Sleep(50);
//     }
//     ::CloseHandle(threadHandle);
// 
//     //////////////////////////////////////////////////////////////////////////
// 
//     blink::WebFileChooserCompletion::SelectedFileInfo info;
//     const std::wstring& filePath = L"C:\\Users\\weo\\Desktop\\1.gif";
// 
//     info.path = String(filePath.c_str());
//     info.displayName = blink::Platform::current()->fileUtilities()->baseName(info.path);
//     const std::wstring& fileSystemURL = L"file:///" + filePath;
//     info.fileSystemURL = blink::KURL(blink::ParsedURLString, String(fileSystemURL.c_str()));
// 
//     long long fileSizeResult = 0;
//     if (!getFileSize(filePath.c_str(), fileSizeResult))
//         fileSizeResult = 0;
//     info.modificationTime = 0;
//     info.length = fileSizeResult;
//     info.isDirectory = ::PathIsDirectoryW(filePath.c_str());
// 
//     blink::WebVector<blink::WebFileChooserCompletion::SelectedFileInfo> wsFileNames((size_t)1);
//     wsFileNames[0] = info;
// 
//     completion->didChooseFile(wsFileNames);
//     return true;
// }

// 现在把所有项都归并到一个项了
static void addForExtensions2(const Vector<blink::WebString>& exts, std::vector<char>* filter)
{
    if (exts.isEmpty())
        return;

    for (Vector<blink::WebString>::const_iterator it = exts.begin(); it != exts.end(); ++it) {
        std::string str = "*.";
        str += it->utf8().data();

        appendStringToVector(filter, str);
        filter->push_back(';');
    }
}

class OpenFileNameWrap {
public:
    OpenFileNameWrap(const blink::WebFileChooserParams& params)
    {
        m_isDirectory = params.directory;

        // image/gif, image/jpeg, image/*
        // Image Files(*.gif;*.jpeg;*.png)\0*.gif;*.jpeg;*.png\0All Files(*.*)\0*.*\0\0
        std::vector<char> filter;

        Vector<blink::WebString> exts;
        for (size_t i = 0; i < params.acceptTypes.size(); ++i) {
            String mimeType = params.acceptTypes[i];
            if (mimeType.isNull() || mimeType.isEmpty())
                continue;
            if ('.' == mimeType[0])
                mimeType.remove(0, 1);
            mimeType = mimeType.lower();

            Vector<blink::WebString> tempExts = extensionsForMimeType(mimeType);

            for (size_t j = 0; j < tempExts.size(); ++j) {
                exts.append(tempExts[j]);
            }
        }

        std::vector<char> filterItem;
        addForExtensions2(exts, &filterItem);

        if (filterItem.size() > 0) {
            appendStringToVector(&filter, "Custom Files(");
            appendStringToVector(&filter, filterItem); // 第一遍是描述
            filter.push_back(')');
            filter.push_back('\0');
            appendStringToVector(&filter, filterItem); // 第二遍是给系统看的
            filter.push_back('\0');
        }

        appendStringToVector(&filter, "All Files");
        filter.push_back('\0');
        appendStringToVector(&filter, "*.*");
        filter.push_back('\0');
        filter.push_back('\0');

        String title = params.title;
        if (title.isEmpty())
            title = L"选择文件(Select File)";

        const int fileNameBufLen = 8192;
        m_fileNameBuf.resize(fileNameBufLen);
        memset(&m_fileNameBuf[0], 0, sizeof(wchar_t) * fileNameBufLen);

//         String initialValue = params.initialValue;
//         Vector<UChar> initialValueBuf;
//         if (!initialValue.isNull() && !initialValue.isEmpty()) {
//             initialValueBuf = WTF::ensureUTF16UChar(initialValue, true);
//             if (initialValueBuf.size() < fileNameBufLen - 1)
//                 wcscpy(&m_fileNameBuf[0], initialValueBuf.data());
//         }

        filter.push_back('\0');

        WTF::MByteToWChar(&filter[0], filter.size() - 1, &m_filterW, CP_UTF8);

        m_titleBuf = WTF::ensureUTF16UChar(title, true);

        memset(&m_ofn, 0, sizeof(OPENFILENAMEW));
        m_ofn.lStructSize = sizeof(OPENFILENAMEW);
        m_ofn.hwndOwner = nullptr;
        m_ofn.hInstance = nullptr;
        m_ofn.lpstrFilter = &m_filterW[0];
        m_ofn.lpstrFile = &m_fileNameBuf[0];
        m_ofn.nMaxFile = fileNameBufLen - 2;
        m_ofn.lpstrTitle = m_titleBuf.data();
        m_ofn.Flags = OFN_EXPLORER | OFN_LONGNAMES | OFN_NOCHANGEDIR;
    }

    OPENFILENAMEW* getInfo()
    {
        return &m_ofn;
    }

    const wchar_t* getFileNameBuf()
    {
        return &m_fileNameBuf[0];
    }

    bool isDirectory() const { return m_isDirectory; }

private:
    OPENFILENAMEW m_ofn;
    std::vector<wchar_t> m_fileNameBuf;
    std::vector<UChar> m_filterW;
    Vector<UChar> m_titleBuf;

    bool m_isDirectory;
};

class ResponseOpenFileInfoTask : public blink::WebThread::Task {
public:
    ResponseOpenFileInfoTask(
        blink::WebFileChooserCompletion* completion,
        int webviewId,
        OpenFileNameWrap* wrap,
        BOOL retVal,
        std::function<void(void)>* completionCallback
    )
    {
        m_completion = completion;
        m_webviewId = webviewId;
        m_wrap = wrap;
        m_retVal = retVal;
        m_completionCallback = completionCallback;
    }

    virtual ~ResponseOpenFileInfoTask()
    {
        delete m_wrap;

        (*m_completionCallback)();
        delete m_completionCallback;
    }

    virtual void run() override
    {
        if (!net::ActivatingObjCheck::inst()->isActivating(m_webviewId))
            return;

        std::vector<std::wstring> selectedFiles;
        std::vector<std::wstring> selectedFilesRef;

        if (m_retVal) {
            // Figure out if the user selected multiple files.  If fileNameBuf is a directory, then multiple files were selected!
            if ((m_wrap->getInfo()->Flags & OFN_ALLOWMULTISELECT) && (::GetFileAttributesW(m_wrap->getFileNameBuf()) & FILE_ATTRIBUTE_DIRECTORY)) {
                std::wstring dirName = m_wrap->getFileNameBuf();
                const wchar_t* p = m_wrap->getFileNameBuf() + wcslen(m_wrap->getFileNameBuf()) + 1;
                while (*p) {
                    selectedFiles.push_back(dirName);
                    selectedFiles.back().append(L"\\");
                    selectedFiles.back().append(p);
                    p += wcslen(p) + 1;
                }
                selectedFilesRef.resize(selectedFiles.size());
                for (size_t i = 0; i < selectedFiles.size(); ++i) {
                    selectedFilesRef[i] = selectedFiles[i];
                }
            } else {
                std::wstring name(m_wrap->getFileNameBuf());
                selectedFilesRef.push_back(name);
            }
        }

        if (0 == selectedFilesRef.size()) {
            m_completion->didChooseFile(blink::WebVector<blink::WebFileChooserCompletion::SelectedFileInfo>());
            return;
        }

        blink::WebVector<blink::WebFileChooserCompletion::SelectedFileInfo> wsFileNames(selectedFilesRef.size());
        for (size_t i = 0; i < selectedFilesRef.size(); ++i) {
            blink::WebFileChooserCompletion::SelectedFileInfo info;
            const std::wstring& filePath = selectedFilesRef[i];

            info.path = String(filePath.c_str());
            //info.displayName = blink::Platform::current()->fileUtilities()->baseName(info.path);
            const std::wstring& fileSystemURL = L"file:///" + filePath;
            if (m_wrap->isDirectory())
                info.path = String(filePath.c_str());
            else
                info.fileSystemURL = blink::KURL(blink::ParsedURLString, String(fileSystemURL.c_str()));

            long long fileSizeResult = 0;
            if (!blink::getFileSize(filePath.c_str(), fileSizeResult))
                fileSizeResult = 0;

            info.modificationTime = 0;
            info.length = fileSizeResult;
            info.isDirectory = ::PathIsDirectoryW(filePath.c_str());

            wsFileNames[i] = info;
        }
        m_completion->didChooseFile(wsFileNames);
    }

private:
    blink::WebFileChooserCompletion* m_completion;
    int m_webviewId;
    OpenFileNameWrap* m_wrap;
    BOOL m_retVal;
    std::function<void(void)>* m_completionCallback;
};

static DWORD __stdcall getOpenFileNameThread(void* param)
{
    std::function<void(void)>* callback = (std::function<void(void)>*)param;
    (*callback)();

    int count = 0;
    MSG msg = { 0 };
    while (true) {
        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            ::TranslateMessage(&msg);
            ::DispatchMessageW(&msg);
        }
        if (++count > 100)
            break;
        ::Sleep(5);
    }

    delete callback;
    return 0;
}

static HWND createHideWindow()
{
    WCHAR* s_fileChooserClassName = L"ChooserClass";
    static bool hasRegister = false;
    if (!hasRegister) {
        WNDCLASS wc = { 0 };
        wc.style = 0;
        wc.lpfnWndProc = ::DefWindowProcW;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = NULL;
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.lpszClassName = s_fileChooserClassName;
        ::RegisterClass(&wc);
        hasRegister = true;
    }

    HWND hWnd = ::CreateWindowW(s_fileChooserClassName, s_fileChooserClassName, WS_OVERLAPPEDWINDOW, 2, 2, 1, 1, NULL, NULL, NULL, NULL);

    ::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    ::ShowWindow(hWnd, SW_HIDE);

    return hWnd;
}

static bool runFileChooserImpl(HWND hWnd, 
    const blink::WebFileChooserParams& params,
    blink::WebFileChooserCompletion* completion, 
    int webviewId, 
    std::function<void(void)>* completionCallback)
{
    //////////////////////////////////////////////////////////////////////////
    //return runFileChooserTest(params, completion);
    //////////////////////////////////////////////////////////////////////////

    OpenFileNameWrap* wrap = new OpenFileNameWrap(params);

    bool saveAs = params.saveAs;
    bool multiSelect = params.multiSelect;

    std::function<void(void)>* callback = new std::function<void(void)>([hWnd, wrap, saveAs, multiSelect, completion, webviewId, completionCallback] {
        BOOL retVal = FALSE;
    HWND hwndOwner = hWnd; //  createHideWindow(); // ::GetActiveWindow();

    if (wrap->isDirectory()) {
        LPITEMIDLIST pil = NULL;
        INITCOMMONCONTROLSEX InitCtrls = { 0 };
        BROWSEINFO bi = { 0 };
        bi.hwndOwner = hwndOwner;
        bi.iImage = 0;
        bi.lParam = NULL;
        bi.lpfn = NULL;
        bi.lpszTitle = L"请选择文件路径";
        bi.pszDisplayName = wrap->getInfo()->lpstrFile;
        bi.ulFlags = BIF_BROWSEINCLUDEFILES;

        //InitCommonControlsEx(&InitCtrls); // 在调用函数SHBrowseForFolder之前需要调用该函数初始化相关环境
        pil = ::SHBrowseForFolder(&bi);
        if (NULL != pil) {
            ::SHGetPathFromIDList(pil, wrap->getInfo()->lpstrFile);//获取用户选择的文件路径
            retVal = TRUE;
        }
    } else {
        wrap->getInfo()->hwndOwner = hwndOwner;

        if (saveAs) {
            wrap->getInfo()->Flags = OFN_OVERWRITEPROMPT;
            retVal = ::GetSaveFileNameW(wrap->getInfo());
        } else if (multiSelect) {
            wrap->getInfo()->Flags |= OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_ALLOWMULTISELECT;
            retVal = ::GetOpenFileNameW(wrap->getInfo());
        } else {
            wrap->getInfo()->Flags |= OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
            retVal = ::GetOpenFileNameW(wrap->getInfo());
        }
    }

    blink::Platform::current()->mainThread()->postTask(FROM_HERE, new ResponseOpenFileInfoTask(completion, webviewId, wrap, retVal, completionCallback));
        });

    DWORD threadId = 0;
    HANDLE threadHandle = CreateThread(0, 0, getOpenFileNameThread, callback, 0, &threadId);
    ::CloseHandle(threadHandle);
    return true;
}

#else
bool runFileChooserImpl(HWND hWnd,
    const blink::WebFileChooserParams& params,
    blink::WebFileChooserCompletion* completion,
    int webviewId,
    std::function<void(void)>* completionCallback)
{
    return false;
}
#endif

}

#endif // content_browser_RunFileChooser_h