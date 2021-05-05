
#include "net/WebURLLoaderWinINet.h"
#include "config.h"
#include "content/web_impl_win/CurrentTimeImpl.h"
#include "content/web_impl_win/WebCookieJarImpl.h"
#include "content/web_impl_win/WebURLLoaderImpl.h"
#include "net/DataURL.h"
#include "third_party/WebKit/Source/platform/WebTaskRunner.h"
#include "third_party/WebKit/Source/platform/network/HTTPHeaderMap.h"
#include "third_party/WebKit/Source/platform/network/HTTPParsers.h"
#include "third_party/WebKit/Source/platform/network/ResourceRequest.h"
#include "third_party/WebKit/Source/platform/network/mime/MIMETypeRegistry.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/wtf/CurrentTime.h"
#include "third_party/WebKit/Source/wtf/text/WTFStringUtil.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include "third_party/WebKit/public/platform/WebHTTPHeaderVisitor.h"
#include "third_party/WebKit/public/platform/WebThread.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"
#include "third_party/WebKit/public/platform/WebURLError.h"
#include "third_party/WebKit/public/platform/WebURLLoaderClient.h"
#include "third_party/WebKit/public/platform/WebURLRequest.h"
#include "third_party/WebKit/public/platform/WebURLResponse.h"
#include <windows.h>
#include <wininet.h>

namespace net {

class BlinkSynchronousLoader : public blink::WebURLLoaderClient {
    WTF_MAKE_NONCOPYABLE(BlinkSynchronousLoader);

public:
    BlinkSynchronousLoader(WebURLError&, WebURLResponse&, Vector<char>&);
    ~BlinkSynchronousLoader();

    //HINTERNET internetHandle() const { return m_internetHandle; }

    virtual void didReceiveResponse(WebURLLoader*, const WebURLResponse&);
    virtual void didReceiveData(WebURLLoader*, const char* data, int dataLength, int encodedDataLength);
    virtual void didFinishLoading(WebURLLoader* loader, double finishTime, int64_t totalEncodedDataLength);
    virtual void didFail(WebURLLoader*, const WebURLError&);

private:
    WebURLError& m_error;
    WebURLResponse& m_response;
    Vector<char>& m_data;
    //HINTERNET m_internetHandle;
};

static inline HINTERNET createInternetHandle(const blink::WebString& userAgent, bool asynchronous)
{
    WTF::String userAgentString = userAgent;
    userAgentString = String::fromUTF8(userAgentString.utf8());
    HINTERNET internetHandle = InternetOpenW((LPCWSTR)userAgentString.charactersWithNullTermination().data(),
        INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, asynchronous ? INTERNET_FLAG_ASYNC : 0);

    if (asynchronous)
        InternetSetStatusCallback(internetHandle, &WebURLLoaderWinINet::internetStatusCallback);

    return internetHandle;
}

BlinkSynchronousLoader::BlinkSynchronousLoader(WebURLError& error, WebURLResponse& response, Vector<char>& data)
    : m_error(error)
    , m_response(response)
    , m_data(data)
{
}

BlinkSynchronousLoader::~BlinkSynchronousLoader()
{
    //InternetCloseHandle(m_internetHandle);
}

void BlinkSynchronousLoader::didReceiveResponse(WebURLLoader*, const WebURLResponse& response)
{
    m_response = response;
}

void BlinkSynchronousLoader::didReceiveData(WebURLLoader*, const char* data, int dataLength, int encodedDataLength)
{
    m_data.append(data, dataLength);
}

void BlinkSynchronousLoader::didFinishLoading(WebURLLoader* loader, double finishTime, int64_t totalEncodedDataLength)
{
}

void BlinkSynchronousLoader::didFail(WebURLLoader*, const WebURLError& error)
{
    m_error = error;
}

//////////////////////////////////////////////////////////////////////////

class ActivatingLoaderCheck {
public:
    ActivatingLoaderCheck()
    {
        InitializeCriticalSection(&m_ctivatingLoaderMutex);
    }

    void addActivatingLoader(WebURLLoaderWinINet* loader)
    {
        EnterCriticalSection(&m_ctivatingLoaderMutex);
        m_activatingLoader.add(loader);
        LeaveCriticalSection(&m_ctivatingLoaderMutex);
    }

    void removeActivatingLoader(WebURLLoaderWinINet* loader)
    {
        EnterCriticalSection(&m_ctivatingLoaderMutex);
        m_activatingLoader.remove(loader);
        LeaveCriticalSection(&m_ctivatingLoaderMutex);
    }

    bool isActivating(WebURLLoaderWinINet* loader)
    {
        EnterCriticalSection(&m_ctivatingLoaderMutex);
        bool isActivating = m_activatingLoader.contains(loader);
        LeaveCriticalSection(&m_ctivatingLoaderMutex);
        return isActivating;
    }

    void testPrint()
    {
#ifdef _DEBUG
        auto it = m_activatingLoader.begin();
        for (; it != m_activatingLoader.end(); ++it) {
            WTF::String outstr = String::format("ActivatingLoaderCheck::testPrint: %p\n", *it);
            OutputDebugStringW(outstr.charactersWithNullTermination().data());
        }
#endif
    }

private:
    WTF::HashSet<WebURLLoaderWinINet*> m_activatingLoader;
    CRITICAL_SECTION m_ctivatingLoaderMutex;
};
static ActivatingLoaderCheck* gActivatingLoaderCheck = nullptr;

static void loadFileAsyncTask(int loaderHandle)
{
    WebURLLoaderWinINet* loader = (WebURLLoaderWinINet*)loaderHandle;
    if (!gActivatingLoaderCheck->isActivating(loader))
        return;
    if (!loader || !loader->firstRequest())
        return;

    blink::KURL url = (blink::KURL)loader->firstRequest()->url();
    loader->fileLoadImpl(url);
}

void WebURLLoaderWinINet::init(bool asynchronously)
{
    if (asynchronously)
        m_ref = 1;
    m_request = nullptr;
    m_client = nullptr;
    m_requestCanceled = false;

    if (asynchronously)
        m_internetHandle = nullptr;
    m_connectHandle = nullptr;
    m_requestHandle = nullptr;
    m_sentEndRequest = false;
    m_formData.clear();
    m_bytesRemainingToWrite = 0;
    m_hasReceivedResponse = false;
    m_totalEncodedDataLength = 0;
    m_hadDestroied = nullptr;
    m_loadSynchronously = false;
    m_debugRedirectPath = nullptr;
}

WebURLLoaderWinINet::WebURLLoaderWinINet(content::WebURLLoaderImpl* loader)
    : m_loader(loader)
{
    ASSERT(isMainThread());
    if (nullptr == gActivatingLoaderCheck)
        gActivatingLoaderCheck = new ActivatingLoaderCheck();
    gActivatingLoaderCheck->addActivatingLoader(this);

    m_ref = 1;
    init(true);
}

WebURLLoaderWinINet::~WebURLLoaderWinINet()
{
    ASSERT(isMainThread());

    if (m_hadDestroied)
        *m_hadDestroied = true;
    m_hadDestroied = nullptr;

    if (m_request)
        delete m_request;
    m_request = nullptr;

    if (m_debugRedirectPath)
        delete m_debugRedirectPath;
    m_debugRedirectPath = nullptr;

    if (!gActivatingLoaderCheck->isActivating(this))
        DebugBreak();
    gActivatingLoaderCheck->removeActivatingLoader(this);

    if (gActivatingLoaderCheck->isActivating(this))
        DebugBreak();

    if (m_loader)
        m_loader->onWinINetWillBeDelete();
    m_loader = nullptr;
}

void WebURLLoaderWinINet::onLoaderWillBeDelete()
{
    m_loader = nullptr;
}

void WebURLLoaderWinINet::ref()
{
    ++m_ref;
}

void WebURLLoaderWinINet::deref()
{
    --m_ref;
    if (0 > m_ref)
        delete this;
}

static void callOnRedirect(void* context)
{
    ASSERT(isMainThread());

    WebURLLoaderWinINet* handle = static_cast<WebURLLoaderWinINet*>(context);
    if (!gActivatingLoaderCheck->isActivating(handle))
        return;

    handle->onRedirect();
}

static void callOnRequestComplete(void* context)
{
    ASSERT(isMainThread());
    WebURLLoaderWinINet* handle = static_cast<WebURLLoaderWinINet*>(context);
    if (!gActivatingLoaderCheck->isActivating(handle))
        return;

    handle->onRequestComplete();
}

void WebURLLoaderWinINet::onRedirect()
{
    if (nullptr == m_requestHandle || m_redirectUrl.isNull() || m_redirectUrl.isEmpty())
        return;

    blink::WebURLRequest newRequest(*firstRequest());
    newRequest.setURL(blink::KURL(blink::ParsedURLString, m_redirectUrl));

    String redirectUrl = (String)firstRequest()->url().string();
    blink::WebURLResponse response(firstRequest()->url());

    if (m_client && m_loader)
        m_client->willFollowRedirect(newRequest, response);
}

static String queryHTTPHeader(HINTERNET requestHandle, DWORD infoLevel)
{
    DWORD bufferSize = 0;
    HttpQueryInfoW(requestHandle, infoLevel, 0, &bufferSize, 0);
    if (0 == bufferSize)
        return String();

    Vector<UChar> characters((bufferSize + 1) / sizeof(UChar));
    if (!HttpQueryInfoW(requestHandle, infoLevel, characters.data(), &bufferSize, 0))
        return String();

    if (0 == bufferSize || (bufferSize / sizeof(UChar)) > characters.size() - 1)
        return String();

    if (0 == characters.at(bufferSize / sizeof(UChar) - 1))
        characters.pop_back(); // Remove NullTermination.
    return String(characters.data(), bufferSize / sizeof(UChar));
}

void WebURLLoaderWinINet::internetStatusCallback(HINTERNET internetHandle, DWORD_PTR context, DWORD internetStatus,
    LPVOID statusInformation, DWORD statusInformationLength)
{
    WebURLLoaderWinINet* handle = reinterpret_cast<WebURLLoaderWinINet*>(context);
    if (!gActivatingLoaderCheck->isActivating(handle)) {
        return;
    }

    switch (internetStatus) {
    case INTERNET_STATUS_REDIRECT: {
        String redirectUrl(static_cast<UChar*>(statusInformation), statusInformationLength);
        ASSERT(redirectUrl.containsOnlyASCII());
        if (redirectUrl.containsOnlyASCII()) {
            handle->m_redirectUrl = String::fromUTF8(redirectUrl.utf8());
            WTF::internal::callOnMainThread(callOnRedirect, handle);
        }
    } break;

    case INTERNET_STATUS_REQUEST_COMPLETE:
        WTF::internal::callOnMainThread(callOnRequestComplete, handle);
        break;

    default:
        break;
    }
}

static HINTERNET asynchronousInternetHandle(const blink::WebString& userAgent)
{
    static HINTERNET internetHandle = createInternetHandle(userAgent, true);
    return internetHandle;
}

static void respondError(WebURLLoader* loader, blink::WebURLLoaderClient* client, const Vector<UChar>& host)
{
    blink::WebURLError error;
    blink::WebString domain((const blink::WebUChar*)host.data(), host.size());
    error.reason = GetLastError();
    if (0 == error.reason)
        error.reason = -1;
    error.domain = domain;
    client->didFail(error, 0, 0);
}

static void appendCharToVector(Vector<char>& buffer, const char* characters)
{
    buffer.append(characters, strlen(characters));
}

class HeaderFlattenerForWinINet : public blink::WebHTTPHeaderVisitor {
public:
    explicit HeaderFlattenerForWinINet()
        : m_hasAcceptHeader(false)
    {
    }

    virtual void visitHeader(const blink::WebString& name, const blink::WebString& value) override
    {
        String nameString = (String)name;
        // Headers are latin1.
        CString nameLatin1 = ((String)name).latin1();
        CString valueLatin1 = ((String)value).latin1();

        // Skip over referrer headers found in the header map because we already
        // pulled it out as a separate parameter.
        if (equalIgnoringCase(nameString, "referer"))
            return;

        if (equalIgnoringCase(nameString, "accept"))
            m_hasAcceptHeader = true;

        if (!m_buffer.isEmpty())
            appendCharToVector(m_buffer, "\r\n");

        Vector<char> headBuffer;
        headBuffer.append(nameLatin1.data(), nameLatin1.length());
        appendCharToVector(headBuffer, ": ");
        headBuffer.append(valueLatin1.data(), valueLatin1.length());
        appendCharToVector(m_buffer, "\r\n");

        m_buffer.append(headBuffer.data(), headBuffer.size());

        ::HttpAddRequestHeadersA(m_requestHandle, headBuffer.data(), headBuffer.size(), HTTP_ADDREQ_FLAG_ADD);
    }

    const Vector<char>& getBuffer()
    {
        // In some cases, WebKit doesn't add an Accept header, but not having the
        // header confuses some web servers.  See bug 808613.
        if (!m_hasAcceptHeader) {
            if (!m_buffer.isEmpty())
                appendCharToVector(m_buffer, "\r\n");
            appendCharToVector(m_buffer, "Accept: */*");
            m_hasAcceptHeader = true;
        }
        //////////////////////////////////////////////////////////////////////////
        if (0) {
            m_buffer.clear();
            appendCharToVector(m_buffer, "Accept: application/json\r\n");
            appendCharToVector(m_buffer, "Accept-Encoding: gzip, deflate, sdch\r\n");
            appendCharToVector(m_buffer, "Accept-Language: zh-CN,zh;q=0.8\r\n");
            appendCharToVector(m_buffer, "Cache-Control: max-age=0\r\n");
            appendCharToVector(m_buffer, "Connection: keep-alive\r\n");
            appendCharToVector(m_buffer, "Content-type: application/x-www-form-urlencoded\r\n");
            appendCharToVector(m_buffer, "Cookie: thw=cn; cna=0HPkDkDX3iACAQ4RFiGYxTsB; mt=ci%3D-1_0; v=0; t=acd3103ffe7d89a5cd6e0fa964e6cbd5; cookie2=1ca76a27cf872d56513c6bbca1aca103; _m_h5_tk=9d1966de39921a2d9a8bde4c1748a930_1454063448988; _m_h5_tk_enc=9a9f8efaa765b5ac1a2200d8a7177a82; l=Ag4O1L0KagpYtzZdaMd8Ktei3urQj9KJ; isg=53115EA927420DA8DFA1278715531EE2\r\n");
            appendCharToVector(m_buffer, "Host: api.m.taobao.com\r\n");
            appendCharToVector(m_buffer, "Origin: https://m.taobao.com\r\n");
            appendCharToVector(m_buffer, "Referer: https://m.taobao.com/\r\n");
            appendCharToVector(m_buffer, "User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.99 Safari/537.36 LBBROWSER\r\n");
            appendCharToVector(m_buffer, "\r\n");
        }
        //////////////////////////////////////////////////////////////////////////
        return m_buffer;
    }

    HINTERNET m_requestHandle;

private:
    Vector<char> m_buffer;
    bool m_hasAcceptHeader;
};

bool testHttpDownload(KURL url, Vector<char>& buffer)
{
    HINTERNET hInternet;
    hInternet = InternetOpen(L"", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (hInternet == NULL)
        return false;

    // 建立连接
    HINTERNET hConnect = nullptr;
    ;
    hConnect = InternetConnect(hInternet, L"x5.imtt.qq.com", 80,
        L"", L"", INTERNET_SERVICE_HTTP, INTERNET_FLAG_PASSIVE, 0);

    if (hInternet == NULL) {
        InternetCloseHandle(hInternet);
        return false;
    }

    HINTERNET httpFile;
    httpFile = HttpOpenRequest(hConnect, L"GET", L"0072811/web_oa/opendoc.xml", HTTP_VERSION, NULL, 0, INTERNET_FLAG_NO_UI | INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_RELOAD, 1);
    if (httpFile == NULL) {
        InternetCloseHandle(hConnect);
        InternetCloseHandle(hInternet);
        return false;
    }

    HttpSendRequest(httpFile, NULL, NULL, 0, 0);

    DWORD bytesWritten = 4;
    const char* writeData = "aaaa";
    BOOL b = InternetWriteFile(httpFile, writeData, 4, &bytesWritten);

    //HINTERNET httpFile = InternetOpenUrl(hInternet, L"http://x5.imtt.qq.com/0072811/web_oa/opendoc.xml", NULL, 0, INTERNET_FLAG_RELOAD, 0);

    const DWORD bufLen = 1024;
    DWORD bufRead = 0;

    Vector<char> tempBuffer;
    tempBuffer.resize(bufLen);
    while (true) {
        BOOL b = InternetReadFile(httpFile, tempBuffer.data(), bufLen, &bufRead);
        if (bufRead == 0 /* buffers.dwBufferLength == 0*/)
            break;
        buffer.append(tempBuffer.data(), bufRead);
    }

    InternetCloseHandle(httpFile);
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);

    return true;
}

// WebURLLoader methods:
void WebURLLoaderWinINet::loadSynchronously(
    const blink::WebURLRequest& request,
    blink::WebURLResponse& response,
    blink::WebURLError& error,
    blink::WebData& data)
{
    Vector<char> buffer;
#if 1
    BlinkSynchronousLoader loader(error, response, buffer);
    m_internetHandle = createInternetHandle(blink::Platform::current()->userAgent(), false);
    ref();
    start(request, &loader, false); // 执行完后本类被析构了
    ASSERT(m_ref == 1);
#else
    testHttpDownload(request.url(), buffer);
    response.setURL(request.url());
    response.setHTTPStatusCode(200);
    response.setMIMEType(WebString::fromUTF8("text/xml; charset=UTF-8"));
    response.setHTTPStatusText(WebString::fromUTF8("ok"));
#endif
    data.assign(buffer.data(), buffer.size());
    deref();
}

void WebURLLoaderWinINet::loadAsynchronously(
    const blink::WebURLRequest& request,
    blink::WebURLLoaderClient* client)
{
    bool b = start(request, client, true);
    if (b) {
        ASSERT(1 == m_ref);
    }
}

// false 表示中断了，true表示还需要继续接收回调数据
bool WebURLLoaderWinINet::start(const blink::WebURLRequest& request, blink::WebURLLoaderClient* client, bool asynchronously)
{
    init(asynchronously);
    m_loadSynchronously = !asynchronously;
    m_request = new blink::WebURLRequest(request);
    m_client = client;

    blink::KURL url = (blink::KURL)request.url();
    Vector<UChar> host = WTF::ensureStringToUChars(url.host());

    if (!url.isValid() || !url.protocolIsData()) {
        //         WTF::String outstr = String::format("WebURLLoaderWinINet.loadAsynchronously: %p %ws\n", this, WTF::ensureStringToUChars(url.string()).data());
        //         OutputDebugStringW(outstr.charactersWithNullTermination().data());
    }

    //////////////////////////////////////////////////////////////////////////
    //     if (WTF::kNotFound != url.string().find("jquery.min.js?v=2.1.4")) {
    //         m_debugRedirectPath = new blink::KURL(ParsedURLString, "file:///C:/Users/Administrator/Desktop/test/jquery.min.js");
    //     }
    //     else if (WTF::kNotFound != url.string().find("login_d7fcda6b"))
    //         m_debugRedirectPath = new blink::KURL(ParsedURLString, "file:///C:/Users/Administrator/Desktop/test/baiduyun/login_files/login_d7fcda6b.js");
    //     else if (WTF::kNotFound != url.string().find("base_2a251972"))
    //         m_debugRedirectPath = new blink::KURL(ParsedURLString, "file:///C:/Users/Administrator/Desktop/test/baiduyun/login_files/base_2a251972.js");
    //////////////////////////////////////////////////////////////////////////

    if (url.isLocalFile() || url.protocolIsData()) {
        if (m_loadSynchronously) {
            fileLoadImpl(url);
            return false;
        } else
            blink::Platform::current()->currentThread()->getWebTaskRunner()->postTask(BLINK_FROM_HERE, WTF::bind(loadFileAsyncTask, (int)(this)));
        return true;
    }

    if (!m_internetHandle)
        m_internetHandle = asynchronousInternetHandle(blink::Platform::current()->userAgent());
    if (!m_internetHandle) {
        respondError(m_loader, client, host);
        deref();
        return false;
    }

    DWORD flags = INTERNET_FLAG_KEEP_CONNECTION
        //| INTERNET_FLAG_NO_COOKIES // TODO
        | INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS
        | INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP
        | INTERNET_FLAG_DONT_CACHE
        | INTERNET_FLAG_RELOAD;
    if (url.protocolIs("https"))
        flags |= INTERNET_FLAG_SECURE;

    int port = url.port();
    if (0 == port) {
        if (url.protocolIs("http"))
            port = INTERNET_DEFAULT_HTTP_PORT;
        else if (url.protocolIs("https"))
            port = INTERNET_DEFAULT_HTTPS_PORT;
    }

    m_connectHandle = InternetConnectW(m_internetHandle, host.data(), port, 0, 0, INTERNET_SERVICE_HTTP, flags, reinterpret_cast<DWORD_PTR>(this));
    if (!m_connectHandle) {
        respondError(m_loader, client, host);
        deref();
        return false;
    }

    String urlStr = url.path();
    String urlQuery = url.query();

    if (!urlQuery.isEmpty()) {
        urlStr.append('?');
        urlStr.append(urlQuery);
    }

    Vector<UChar> httpMethod = WTF::ensureStringToUChars(request.httpMethod());
    Vector<UChar> httpReferrer = WTF::ensureStringToUChars(request.httpHeaderField(blink::WebString::fromUTF8("Referer")));
    Vector<UChar> httpAcceptField = WTF::ensureStringToUChars(request.httpHeaderField(blink::WebString::fromUTF8("Accept")));

    //LPCWSTR httpAccept[] = { L"*/*", 0 };
    LPCWSTR httpAccept[] = { httpAcceptField.data(), 0 };

    m_requestHandle = HttpOpenRequestW(m_connectHandle, (LPCWSTR)httpMethod.data(), (LPCWSTR)WTF::ensureStringToUChars(urlStr).data(),
        0, (LPCWSTR)httpReferrer.data(), httpAccept, flags, reinterpret_cast<DWORD_PTR>(this));

    if (!m_requestHandle) {
        InternetCloseHandle(m_connectHandle);
        m_connectHandle = 0;
        respondError(m_loader, client, host);
        deref();
        return false;
    }

    if (!request.httpBody().isNull()) {
        //         WTF::PassRefPtr<blink::FormData> formData = request.httpBody();
        //         if (formData) {
        //             formData->flatten(m_formData);
        //             m_bytesRemainingToWrite = m_formData.size();
        //         }
        DebugBreak();
    }

#if 1
    HeaderFlattenerForWinINet flattener;
    flattener.m_requestHandle = m_requestHandle;
    request.visitHTTPHeaderFields(&flattener);
    Vector<char> httpHeaders = flattener.getBuffer();

    INTERNET_BUFFERSA internetBuffers = { 0 };
    internetBuffers.dwStructSize = sizeof(internetBuffers);
    internetBuffers.lpcszHeader = (LPCSTR)httpHeaders.data();
    internetBuffers.dwHeadersLength = httpHeaders.size();
    internetBuffers.dwBufferTotal = m_bytesRemainingToWrite;
    internetBuffers.lpvBuffer = m_formData.data();

    HttpSendRequestExA(m_requestHandle, &internetBuffers, 0, 0, reinterpret_cast<DWORD_PTR>(this));
#endif
    if (m_loadSynchronously) {
        while (onRequestComplete()) {
            // Loop until finished.
        }
        return false;
    }
    return true;
}

bool WebURLLoaderWinINet::onRequestComplete()
{
    if (0xfeeefeee == (unsigned int)m_request) { // weolar
        gActivatingLoaderCheck->testPrint();
        DebugBreak();
    }

    if (!m_internetHandle || (!m_requestHandle && !m_connectHandle)) {
        deref(); // balances ref in start
        return false;
    }

    if (m_bytesRemainingToWrite) {
        DWORD bytesWritten;
        const char* writeData = m_formData.data() + (m_formData.size() - m_bytesRemainingToWrite);
        BOOL b = InternetWriteFile(m_requestHandle, writeData, m_bytesRemainingToWrite, &bytesWritten);
        if (!b) {
            DWORD dwError;
            Vector<wchar_t> errorBuf;
            DWORD dwBufferLength = 200;
            errorBuf.resize(dwBufferLength);
            b = ::InternetGetLastResponseInfo(&dwError, errorBuf.data(), &dwBufferLength);
            OutputDebugStringW(errorBuf.data());
            OutputDebugStringA("\n");
        }
        m_bytesRemainingToWrite -= bytesWritten;
        //         if (m_bytesRemainingToWrite)
        //             return true;
        m_formData.clear();
    }

    if (!m_sentEndRequest) {
        HttpEndRequestW(m_requestHandle, 0, 0, reinterpret_cast<DWORD_PTR>(this));
        m_sentEndRequest = true;
        return true;
    }

    static const int bufferSize = 32768;
    WTF::Vector<char> buffer;
    buffer.resize(bufferSize + 2);
    INTERNET_BUFFERSA buffers = { 0 };
    buffers.dwStructSize = sizeof(INTERNET_BUFFERSA);
    buffers.lpvBuffer = buffer.data();
    buffers.dwBufferLength = bufferSize;

    BOOL ok = FALSE;
    while ((ok = InternetReadFileExA(m_requestHandle, &buffers, m_loadSynchronously ? IRF_SYNC : IRF_NO_WAIT, reinterpret_cast<DWORD_PTR>(this))) && buffers.dwBufferLength) {
        ASSERT(buffers.dwBufferLength <= bufferSize);

        if (!m_hasReceivedResponse) {
            m_hasReceivedResponse = true;

            blink::WebURLResponse response(firstRequest()->url());

            WTF::String httpStatusText = queryHTTPHeader(m_requestHandle, HTTP_QUERY_STATUS_TEXT);
            if (!httpStatusText.isNull())
                response.setHTTPStatusText(httpStatusText);

            WTF::String httpStatusCode = queryHTTPHeader(m_requestHandle, HTTP_QUERY_STATUS_CODE);
            if (!httpStatusCode.isNull())
                response.setHTTPStatusCode(httpStatusCode.toInt());

            WTF::String httpContentLength = queryHTTPHeader(m_requestHandle, HTTP_QUERY_CONTENT_LENGTH);
            if (!httpContentLength.isNull())
                response.setExpectedContentLength(httpContentLength.toInt());

            WTF::String httpContentType = queryHTTPHeader(m_requestHandle, HTTP_QUERY_CONTENT_TYPE);
            if (!httpContentType.isNull()) {
                response.setMIMEType(blink::extractMIMETypeFromMediaType(WTF::AtomicString(httpContentType)));
                response.setTextEncodingName(blink::extractCharsetFromMediaType(WTF::AtomicString(httpContentType)));

                blink::WebUChar kContentType[] = L"Content-Type";
                blink::WebString kContentTypeString(kContentType, sizeof(kContentType) / sizeof(blink::WebUChar) - 1);
                response.setHTTPHeaderField(kContentTypeString, blink::WebString(httpContentType));
            }

            WTF::String rawHeadersCrlf = queryHTTPHeader(m_requestHandle, HTTP_QUERY_RAW_HEADERS_CRLF);
            content::WebCookieJarImpl::inst()->setToRecordFromRawHeads(m_request->url(), rawHeadersCrlf);

            WTF::String cookies = queryHTTPHeader(m_requestHandle, HTTP_QUERY_COOKIE);

            //String url = (String)(m_request->url().string());
            //String cookies = content::WebCookieJarImpl::inst()->cookies(m_request->url(), m_request->url());
            // ::InternetSetCookieA(WTF::ensureStringToUTF8(url).data(), NULL, WTF::ensureStringToUTF8(cookies).data());

            if (m_client && m_loader) {
                bool hadDestroied = false;
                m_hadDestroied = &hadDestroied;
                m_client->didReceiveResponse(response, nullptr);
                if (hadDestroied || !gActivatingLoaderCheck->isActivating(this)) // 有可能在didReceiveResponse把整个类析构掉
                    return false;
            }
        }

        m_totalEncodedDataLength += buffers.dwBufferLength;

        // FIXME: https://bugs.webkit.org/show_bug.cgi?id=19793
        // -1 means we do not provide any data about transfer size to inspector so it would use
        // Content-Length headers or content size to show transfer size.
        bool hadDestroied = false;
        m_hadDestroied = &hadDestroied;
        if (m_client && m_loader && !m_debugRedirectPath)
            m_client->didReceiveData(buffer.data(), buffers.dwBufferLength);
        if (hadDestroied || !gActivatingLoaderCheck->isActivating(this))
            return false;

        buffers.dwBufferLength = bufferSize;
    }

    if (!ok && GetLastError() == ERROR_IO_PENDING) {
        //         String urlTest = m_request->url().string();
        //         String out = String::format("WebURLLoaderWinINet::onRequestComplete not complete:");
        //         out.append(urlTest);
        //         out.append("\n");
        //         OutputDebugStringW(out.charactersWithNullTermination().data());
        return true;
    }

    if (m_debugRedirectPath)
        fileLoadImpl(*m_debugRedirectPath);

    if (0xfeeefeee == (unsigned int)m_request) { // weolar
        gActivatingLoaderCheck->testPrint();
        DebugBreak();
    }

    InternetCloseHandle(m_requestHandle);
    InternetCloseHandle(m_connectHandle);
    m_requestHandle = 0;
    m_connectHandle = 0;

    if (m_client && m_loader) {
        if (0 == m_totalEncodedDataLength || !m_hasReceivedResponse) {
            blink::WebURLError error;
            error.reason = GetLastError();
            if (0 == error.reason)
                error.reason = -1;
            error.domain = blink::WebString(m_request->url().string());
            error.localizedDescription = blink::WebString::fromUTF8("Url request fail, data length is null\n");
            m_client->didFail(error, 0, 0);
            return false;
        }

        //         String urlTest = m_request->url().string();
        //         String out = String::format("WebURLLoaderWinINet::onRequestComplete:");
        //         out.append(urlTest);
        //         out.append("\n");
        //         OutputDebugStringW(out.charactersWithNullTermination().data());
        //
        //         if (WTF::kNotFound != urlTest.find("bootstrap.min.js")) {
        //             OutputDebugStringA("\n");
        //         }

        m_client->didFinishLoading(WTF::currentTime(), m_totalEncodedDataLength, 0);
    }

    return false;
}

void WebURLLoaderWinINet::fileLoadImpl(const blink::KURL& url)
{
    if (requestCanceled()) {
        deref();
        return;
    }

    //RefPtr<WebURLLoaderWinINet> protector(this);
    if (url.protocolIsData()) {
        if (m_client && m_loader)
            net::handleDataURL(m_loader, m_client, url);
        deref();
        return;
    }

    Vector<UChar> fileNameVec = WTF::ensureStringToUChars(url.fileSystemPath());
    String fileName(fileNameVec.data(), fileNameVec.size());
    if (L'/' == fileName[0])
        fileName.remove(0);

    HANDLE fileHandle = ::CreateFileW((LPCWSTR)fileName.charactersWithNullTermination().data(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    if (fileHandle == INVALID_HANDLE_VALUE) {
        blink::WebURLError error;
        error.reason = GetLastError();
        if (0 == error.reason)
            error.reason = -1;
        error.domain = blink::WebString(fileNameVec.data(), fileNameVec.size());
        error.localizedDescription = blink::WebString::fromUTF8("fileLoadImpl -> CreateFileW fail\n");
        if (m_client && m_loader)
            m_client->didFail(error, 0, 0);
        return;
    }

    blink::WebURLResponse response;
    //response.initialize();
    response.setURL(blink::WebURL(url));
    response.setHTTPStatusCode(200);
    response.setHTTPStatusText(WebString::fromUTF8("ok"));

    int dotPos = fileName.reverseFind('.');
    int slashPos = fileName.reverseFind('/');

    if (slashPos < dotPos && dotPos != -1) {
        String ext = fileName.substring(dotPos + 1);
        response.setMIMEType(blink::MIMETypeRegistry::getMIMETypeForExtension(ext));
    }

    if (m_client && m_loader && !m_debugRedirectPath)
        m_client->didReceiveResponse(response, nullptr);

    bool result = false;
    DWORD bytesRead = 0;
    int64_t totalEncodedDataLength = 0;

    do {
        const int bufferSize = 8192;
        WTF::Vector<char> buffer;
        buffer.resize(bufferSize);
        result = ::ReadFile(fileHandle, buffer.data(), bufferSize, &bytesRead, 0);
        // FIXME: https://bugs.webkit.org/show_bug.cgi?id=19793
        // -1 means we do not provide any data about transfer size to inspector so it would use
        // Content-Length headers or content size to show transfer size.
        if (result && bytesRead) {
            if (m_client && m_loader)
                m_client->didReceiveData(buffer.data(), bytesRead);
            totalEncodedDataLength += bytesRead;
        }
        // Check for end of file.
    } while (result && bytesRead);

    ::CloseHandle(fileHandle);

    if (m_client && m_loader && !m_debugRedirectPath)
        m_client->didFinishLoading(WTF::currentTime(), totalEncodedDataLength, 0);
    deref();
}

void WebURLLoaderWinINet::cancel()
{
    if (m_requestHandle) {
        m_internetHandle = 0;
        InternetCloseHandle(m_requestHandle);
        InternetCloseHandle(m_connectHandle);
        m_requestHandle = 0;
        m_connectHandle = 0;
    } else
        m_requestCanceled = true;

    m_client = nullptr;
    m_loader = nullptr;
}

void WebURLLoaderWinINet::setDefersLoading(bool value)
{
}

void WebURLLoaderWinINet::didChangePriority(blink::WebURLRequest::Priority new_priority,
    int intra_priority_value)
{
}

} // namespace content