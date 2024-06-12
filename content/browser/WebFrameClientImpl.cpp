
#include "content/browser/WebFrameClientImpl.h"
#include "content/browser/WebPage.h"
#include "content/browser/WebPageImpl.h"
#include "content/ui/ContextMeun.h"
#include "content/web_impl_win/WebMediaPlayerImpl.h"
#include "content/web_impl_win/npapi/WebPluginImpl.h"
#include "content/OrigChromeMgr.h"
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
#include "wke/wkeWebView.h"
#include "wke/wkeJsBind.h"
#endif
#include "third_party/WebKit/public/web/WebFrameClient.h"
#include "third_party/WebKit/public/web/WebDocument.h"
#include "third_party/WebKit/public/web/WebUserGestureIndicator.h"
//#include "third_party/WebKit/public/web/WebGeolocationClient.h"
//#include "third_party/WebKit/public/web/WebGeolocationPosition.h"
#include "third_party/WebKit/public/platform/WebURLLoader.h"
#include "third_party/WebKit/Source/web/WebLocalFrameImpl.h"
#include "third_party/WebKit/Source/web/WebViewImpl.h"
#include "third_party/WebKit/Source/platform/Language.h"
#include "third_party/WebKit/Source/core/frame/Settings.h"
#include "third_party/WebKit/Source/core/page/Page.h"
#include "third_party/WebKit/Source/wtf/text/WTFStringUtil.h"

#include "net/RequestExtraData.h"
#include "net/cookies/WebCookieJarCurlImpl.h"
#include "net/DataURL.h"

#include "wke/wkeGlobalVar.h"
//#include "node/nodeblink.h"

#include "media/blink/url_index.h"

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
namespace wke {
class CWebView;
}
#endif

namespace content {

WebFrameClientImpl::WebFrameClientImpl()
{
    m_loading = false;
    m_loadFailed = false;
    m_loaded = false;
    m_documentReady = false;
    m_webPage = nullptr;
    m_menu = nullptr;
    m_frame = nullptr;
    m_webGeolocationClientImpl = nullptr;
}

// class WebGeolocationClientImpl : public blink::WebGeolocationClient {
// public:
//     virtual ~WebGeolocationClientImpl() {}
// 
//     virtual void startUpdating() override
//     {
//     }
// 
//     virtual void stopUpdating() override
//     {
//     }
// 
//     virtual void setEnableHighAccuracy(bool) override
//     {
//     }
// 
//     virtual bool lastPosition(blink::WebGeolocationPosition& pos) override
//     {
//         if (!wke::g_geoPos)
//             return false;
// 
//         pos.assign(
//             wke::g_geoPos->timestamp,
//             wke::g_geoPos->latitude,
//             wke::g_geoPos->longitude,
//             wke::g_geoPos->accuracy,
//             wke::g_geoPos->providesAltitude,
//             wke::g_geoPos->altitude,
//             wke::g_geoPos->providesAltitudeAccuracy,
//             wke::g_geoPos->altitudeAccuracy,
//             wke::g_geoPos->providesHeading,
//             wke::g_geoPos->heading,
//             wke::g_geoPos->providesSpeed,
//             wke::g_geoPos->speed
//         );
// 
//         return true;
//     }
// 
//     virtual void requestPermission(const blink::WebGeolocationPermissionRequest&) override
//     {
//     }
// 
//     virtual void cancelPermissionRequest(const blink::WebGeolocationPermissionRequest&) override
//     {
//     }
// 
//     virtual void setController(blink::WebGeolocationController*)  override
//     {
//     }
// };

WebFrameClientImpl::~WebFrameClientImpl()
{
    RELEASE_ASSERT(0 == m_unusedFrames.size());
#if defined(OS_WIN)
    if (m_menu)
        delete m_menu;
//     if (m_webGeolocationClientImpl)
//       delete m_webGeolocationClientImpl;
#endif
}

void WebFrameClientImpl::didAddMessageToConsole(const WebConsoleMessage& message,
    const WebString& sourceName, unsigned sourceLine, const WebString& stackTrace)
{
//     WTF::String outstr(L"console:");
// 
//     outstr.append((WTF::String)(message.text));
//     outstr.append(L" ;sourceName:");
//     outstr.append(sourceName);
// 
//     outstr.append(L" ;sourceLine:");
//     outstr.append(String::number(sourceLine));
//     outstr.append(L" \n");
//     OutputDebugStringW(outstr.charactersWithNullTermination().data());

    WTF::String outstr;
    outstr.append(String::format("Console:[%d],[", sourceLine));
    outstr.append(message.text);
    outstr.append("],[");
    outstr.append(sourceName);
    outstr.append("]\n");

    if (WTF::kNotFound != outstr.find("__callstack__") && 0 != stackTrace.length()) {
        outstr.append("stackTrace:");
        outstr.append(stackTrace);
        outstr.append("\n");
    }

    if (wke::g_consoleOutputEnable) {
#if defined(OS_WIN)
        Vector<UChar> utf16 = WTF::ensureUTF16UChar(outstr, true);
        OutputDebugStringW(utf16.data());
#else
        Vector<char> utf8Str = WTF::ensureStringToUTF8(outstr, true);
        OutputDebugStringA(utf8Str.data());
#endif
    }

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    wke::CWebViewHandler& handler = m_webPage->wkeHandler();
    if (handler.consoleCallback && m_webPage->getState() == pageInited) {
        wke::CString text(message.text);
        wke::CString sourceNameStr(sourceName);
        wke::CString stackTraceStr(stackTrace);
        handler.consoleCallback(m_webPage->wkeWebView(), handler.consoleCallbackParam,
            (wkeConsoleLevel)message.level, &text, &sourceNameStr, sourceLine, &stackTraceStr);
    }
#endif
}

void WebFrameClientImpl::setWebPage(WebPage* webPage)
{
    m_webPage = webPage;
}

WebPage* WebFrameClientImpl::webPage()
{
    return m_webPage;
}

WebLocalFrame* WebFrameClientImpl::createChildFrame(WebLocalFrame* parent, WebTreeScopeType, const WebString& frameName, const WebString& uniqueName, WebSandboxFlags sandboxFlags, const WebFrameOwnerProperties&)
{
    WebLocalFrameImpl* webLocalFrameImpl = WebLocalFrameImpl::create(WebTreeScopeType::Document, this, parent);
    parent->appendChild(webLocalFrameImpl);
    if (WTF::kNotFound == m_unusedFrames.find(webLocalFrameImpl))
        m_unusedFrames.append(webLocalFrameImpl);

    return webLocalFrameImpl; // TODO delete;
}

void WebFrameClientImpl::frameDetached(WebLocalFrame* child, DetachType)
{
    if (WebFrame* parent = child->parent())
        parent->removeChild(child);

    // |frame| is invalid after here.  Be sure to clear frame_ as well, since this
    // object may not be deleted immediately and other methods may try to access
    // it.
    size_t findChildIt = m_unusedFrames.find(child);
    if (WTF::kNotFound != findChildIt)
        m_unusedFrames.remove(findChildIt);
    child->close();
}

//blink::WebPluginPlaceholder* WebFrameClientImpl::createPluginPlaceholder(WebLocalFrame*, const blink::WebPluginParams&) { return 0; }

blink::WebPlugin* WebFrameClientImpl::createPlugin(WebLocalFrame* frame, const WebPluginParams& params)
{
#if defined(OS_WIN) 
    WebPluginParams newParam = params;
    Vector<String> paramNames;
    Vector<String> paramValues;

    bool isWmode = false;
    for (size_t i = 0; i < newParam.attributeNames.size(); i++) {
        if (String(newParam.attributeNames[i]).lower() == "wmode") {
            isWmode = true;

            paramNames.append(newParam.attributeNames[i]);
            if (String(newParam.attributeValues[i]).lower() != "opaque" &&
                String(newParam.attributeValues[i]).lower() != "transparent") {
                paramValues.append("transparent");
            } else
                paramValues.append(newParam.attributeValues[i]);
        } else {
            paramNames.append(newParam.attributeNames[i]);
            paramValues.append(newParam.attributeValues[i]);
        }
    }
    if (!isWmode) {
        paramNames.append("wmode");
        paramValues.append("transparent");
    }

    newParam.attributeNames = WebVector<WebString>(paramNames);
    newParam.attributeValues = WebVector<WebString>(paramValues);  

    PassRefPtr<WebPluginImpl> plugin = adoptRef(new WebPluginImpl(frame, newParam));
    plugin->setParentPlatformPluginWidget(m_webPage->getHWND());
    plugin->setHwndRenderOffset(m_webPage->getHwndRenderOffset());
    plugin->setWkeWebView(m_webPage->wkeWebView());

    return plugin.leakRef();
#else
    return nullptr;
#endif
}

WebMediaPlayer* WebFrameClientImpl::createMediaPlayer(const WebMediaPlayerSource& source,
    WebMediaPlayerClient* client,
    WebMediaPlayerEncryptedMediaClient* encrypt,
    WebContentDecryptionModule* module,
    const WebString& sinkId)
{
#if defined(OS_WIN) 
    if (!m_urlIndex.get() || m_urlIndex->frame() != m_frame)
        m_urlIndex.reset(new media::UrlIndex(m_frame));

    return OrigChromeMgr::createWebMediaPlayer(m_frame, source, client, encrypt, module, sinkId, m_urlIndex);
#else
    return nullptr;
#endif
}

blink::WebApplicationCacheHost* WebFrameClientImpl::createApplicationCacheHost(WebApplicationCacheHostClient*) { return 0; }

blink::WebServiceWorkerProvider* WebFrameClientImpl::createServiceWorkerProvider() { return 0; }

blink::WebWorkerContentSettingsClientProxy* WebFrameClientImpl::createWorkerContentSettingsClientProxy() { return 0; }

// Create a new WebPopupMenu. In the "createExternalPopupMenu" form, the
// client is responsible for rendering the contents of the popup menu.
WebExternalPopupMenu* WebFrameClientImpl::createExternalPopupMenu(const WebPopupMenuInfo&, WebExternalPopupMenuClient*)
{
    return 0;
}

WebCookieJar* WebFrameClientImpl::cookieJar()
{
    PassRefPtr<net::PageNetExtraData> extra = m_webPage->getPageNetExtraData();
    if (extra && extra->getCookieJar())
        return extra->getCookieJar();

    net::WebURLLoaderManager* manager = net::WebURLLoaderManager::sharedInstance();
    if (!manager)
        return nullptr;

    net::WebCookieJarImpl* result = manager->getShareCookieJar();
    return result;
}

void WebFrameClientImpl::resetLoadState()
{
    m_loadFailed = false;
    m_loaded = false;
    m_documentReady = false;
    m_loading = true;

    //OutputDebugStringA("WebFrameClientImpl::resetLoadState\n");
}

void WebFrameClientImpl::onLoadingStateChange(bool isLoading, bool toDifferentDocument)
{
    m_loading = isLoading;

    if (!m_webPage)
        return;
    WebViewImpl* webview = m_webPage->webViewImpl();
    if (!webview || !webview->client())
        return;

    bool canGoBack = webview->client()->historyBackListCount() > 0;
    bool canGoForward = webview->client()->historyForwardListCount() > 0;
}

void WebFrameClientImpl::didStartLoading(bool toDifferentDocument)
{
    resetLoadState();
    onLoadingStateChange(true, toDifferentDocument);
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    wke::CWebViewHandler& handler = m_webPage->wkeHandler();
    if (handler.otherLoadCallback && m_webPage->getState() == pageInited) {
        wkeTempCallbackInfo* tempInfo = wkeGetTempCallbackInfo(m_webPage->wkeWebView());
        tempInfo->size = sizeof(wkeTempCallbackInfo);
        tempInfo->frame = nullptr;
        handler.otherLoadCallback(m_webPage->wkeWebView(), handler.otherLoadCallbackParam,
            WKE_DID_START_LOADING, tempInfo);
    }
#endif
}

void WebFrameClientImpl::didStopLoading()
{
    onLoadingStateChange(false, true);
}

void WebFrameClientImpl::didChangeLoadProgress(double loadProgress)
{
    onLoadingStateChange(loadProgress != 1.0, true);
}

void WebFrameClientImpl::willSendSubmitEvent(const WebFormElement&) { }
void WebFrameClientImpl::willSubmitForm(const WebFormElement&) { }

void WebFrameClientImpl::didCreateDataSource(WebLocalFrame*, WebDataSource* dataSource)
{
    //dataSource->setNavigationStartTime(WTF::monotonicallyIncreasingTime());
}

void WebFrameClientImpl::didStartProvisionalLoad(WebLocalFrame* localFrame)
{
    resetLoadState();

    if (localFrame && localFrame->parent())
        m_webPage->didStartProvisionalLoad();
}

void WebFrameClientImpl::didReceiveServerRedirectForProvisionalLoad(WebLocalFrame*) { }

void WebFrameClientImpl::didFailProvisionalLoad(WebLocalFrame* frame, const WebURLError& error, WebHistoryCommitType type)
{
    m_loadFailed = true;

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    wke::CWebViewHandler& handler = m_webPage->wkeHandler();
    if (handler.loadingFinishCallback && m_webPage->getState() == pageInited) {
        wkeLoadingResult result = WKE_LOADING_FAILED;
        String failedReasonStr = String::format("error reason: %d, ", error.reason);
        failedReasonStr.append(error.localizedDescription);
        wke::CString failedReason(failedReasonStr);
        wke::CString url(error.domain); // error is set in WebURLLoaderManager::downloadOnIoThread

        if (error.isCancellation)
            result = WKE_LOADING_CANCELED;

        handler.loadingFinishCallback(m_webPage->wkeWebView(), handler.loadingFinishCallbackParam, &url, result, &failedReason);
    }
#endif
}

static wkeWebFrameHandle frameIdToWkeFrame(WebPage* webPage, WebLocalFrame* frame)
{
    wkeWebFrameHandle result = (wkeWebFrameHandle)(webPage->getFrameIdByBlinkFrame(frame) - WebPage::getFirstFrameId() + 1);
    return result;
}

void WebFrameClientImpl::didCommitProvisionalLoad(WebLocalFrame* frame, const WebHistoryItem& history, WebHistoryCommitType type)
{
    //if (!frame->parent())
        m_webPage->didCommitProvisionalLoad(frame, history, type, false);

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    wke::CWebViewHandler& handler = m_webPage->wkeHandler();
    String url = history.urlString();
    wke::CString string(url);

    if (m_webPage->wkeWebView() && !frame->parent())
        m_webPage->wkeWebView()->onUrlChanged(&string);

    if (handler.urlChangedCallback && m_webPage->getState() == pageInited)
        handler.urlChangedCallback(m_webPage->wkeWebView(), handler.urlChangedCallbackParam, &string);

    if (handler.urlChangedCallback2 && m_webPage->getState() == pageInited)
        handler.urlChangedCallback2(m_webPage->wkeWebView(), handler.urlChangedCallback2Param, frameIdToWkeFrame(m_webPage, frame), &string);

    if (handler.otherLoadCallback && m_webPage->getState() == pageInited) {
        wkeTempCallbackInfo* tempInfo = wkeGetTempCallbackInfo(m_webPage->wkeWebView());
        tempInfo->size = sizeof(wkeTempCallbackInfo);
        tempInfo->frame = frameIdToWkeFrame(m_webPage, frame);
        handler.otherLoadCallback(m_webPage->wkeWebView(), handler.otherLoadCallbackParam,
            WKE_DID_NAVIGATE, tempInfo);
    }
#endif    
}

WebHistoryItem WebFrameClientImpl::historyItemForNewChildFrame()
{
    return m_webPage->historyItemForNewChildFrame(m_frame);
}

void WebFrameClientImpl::didCreateNewDocument(WebLocalFrame* frame)
{
}

void WebFrameClientImpl::didClearWindowObject(WebLocalFrame* frame) { }

void WebFrameClientImpl::didCreateDocumentElement(WebLocalFrame* frame) { }

void WebFrameClientImpl::didReceiveTitle(WebLocalFrame* frame, const WebString& title, WebTextDirection direction)
{
    if (frame == m_webPage->mainFrame()) {
        m_title = title;
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
        wke::CWebViewHandler& handler = m_webPage->wkeHandler();
        if (handler.titleChangedCallback && m_webPage->getState() == pageInited) {
            wke::CString string(title);
            handler.titleChangedCallback(m_webPage->wkeWebView(), handler.titleChangedCallbackParam, &string);
        }
#endif
    }
}

void WebFrameClientImpl::didChangeIcon(WebLocalFrame*, WebIconURL::Type) { }

void WebFrameClientImpl::didFinishDocumentLoad(WebLocalFrame* frame)
{
    m_documentReady = true;

    m_webPage->onDocumentReady();

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    wke::CWebViewHandler& handler = m_webPage->wkeHandler();
    if (handler.documentReadyCallback && m_webPage->getState() == pageInited)
        handler.documentReadyCallback(m_webPage->wkeWebView(), handler.documentReadyCallbackParam);
    if (handler.documentReady2Callback && m_webPage->getState() == pageInited)
        handler.documentReady2Callback(m_webPage->wkeWebView(), handler.documentReady2CallbackParam, frameIdToWkeFrame(m_webPage, frame));
#endif

    //OutputDebugStringA("WebFrameClientImpl::didFinishDocumentLoad\n");
}

void WebFrameClientImpl::didHandleOnloadEvents(WebLocalFrame*) { }

void WebFrameClientImpl::didFailLoad(WebLocalFrame* frame, const WebURLError& error, WebHistoryCommitType type)
{
    m_loadFailed = true;

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    wke::CWebViewHandler& handler = m_webPage->wkeHandler();
    if (handler.loadingFinishCallback && m_webPage->getState() == pageInited) {
        wkeLoadingResult result = WKE_LOADING_FAILED;
        String failedReasonStr = String::format("error reason: %d, ", error.reason);
        failedReasonStr.append(error.localizedDescription);
        wke::CString failedReason(failedReasonStr);
        wke::CString url(error.unreachableURL.string());

        if (error.isCancellation)
            result = WKE_LOADING_CANCELED;

        handler.loadingFinishCallback(m_webPage->wkeWebView(), handler.loadingFinishCallbackParam, &url, result, &failedReason);
    }
#endif

    //OutputDebugStringA("WebFrameClientImpl::didFailLoad\n");
}

void WebFrameClientImpl::didFinishLoad(WebLocalFrame* frame)
{
    m_loaded = true;

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    wke::CWebViewHandler& handler = m_webPage->wkeHandler();
    if (handler.loadingFinishCallback && m_webPage->getState() == pageInited) {
        wkeLoadingResult result = WKE_LOADING_SUCCEEDED;
        wke::CString url(frame->document().url().string());

        wkeTempCallbackInfo* tempInfo = wkeGetTempCallbackInfo(m_webPage->wkeWebView());
        tempInfo->size = sizeof(wkeTempCallbackInfo);
        tempInfo->frame = frameIdToWkeFrame(m_webPage, frame);
        handler.loadingFinishCallback(m_webPage->wkeWebView(), handler.loadingFinishCallbackParam, &url, result, NULL);
    }
#endif

    //OutputDebugStringA("WebFrameClientImpl::didFinishLoad\n");
}

void WebFrameClientImpl::didNavigateWithinPage(WebLocalFrame* frame, const WebHistoryItem& history, WebHistoryCommitType type, bool contentInitiated)
{    
    m_webPage->didCommitProvisionalLoad(frame, history, type, true);

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    wke::CWebViewHandler& handler = m_webPage->wkeHandler();
    String url = history.urlString();
    wke::CString string(url);

    if (m_webPage->wkeWebView() && !frame->parent())
        m_webPage->wkeWebView()->onUrlChanged(&string);

    if (handler.urlChangedCallback && m_webPage->getState() == pageInited)
        handler.urlChangedCallback(m_webPage->wkeWebView(), handler.urlChangedCallbackParam, &string);

    if (handler.urlChangedCallback2 && m_webPage->getState() == pageInited)
        handler.urlChangedCallback2(m_webPage->wkeWebView(), handler.urlChangedCallback2Param, frameIdToWkeFrame(m_webPage, frame), &string);

    if (handler.otherLoadCallback && m_webPage->getState() == pageInited) {
        wkeTempCallbackInfo* tempInfo = wkeGetTempCallbackInfo(m_webPage->wkeWebView());
        tempInfo->size = sizeof(wkeTempCallbackInfo);
        tempInfo->frame = frameIdToWkeFrame(m_webPage, frame);
        handler.otherLoadCallback(m_webPage->wkeWebView(), handler.otherLoadCallbackParam,
            WKE_DID_NAVIGATE_IN_PAGE, tempInfo);
    }
#endif 
}

void WebFrameClientImpl::didUpdateCurrentHistoryItem()
{
    //OutputDebugStringA("didUpdateCurrentHistoryItem\n");
}

void WebFrameClientImpl::didChangeManifest() { }

//void WebFrameClientImpl::didChangeDefaultPresentation(WebLocalFrame*) { }
void WebFrameClientImpl::didChangeThemeColor() { }

void WebFrameClientImpl::dispatchLoad()
{
    OutputDebugStringA("WebFrameClientImpl::dispatchLoad\n");
}

WebNavigationPolicy WebFrameClientImpl::decidePolicyForNavigation(const NavigationPolicyInfo& info)
{
    if (!m_webPage)
        return info.defaultPolicy;

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    if (m_webPage->wkeHandler().navigationCallback && m_webPage->getState() == pageInited) {
        wkeNavigationType navigationType = WKE_NAVIGATION_TYPE_OTHER;
        switch (info.navigationType) {
        case blink::WebNavigationTypeLinkClicked:
            navigationType = WKE_NAVIGATION_TYPE_LINKCLICK;
            break;
        case blink::WebNavigationTypeFormSubmitted:
            navigationType = WKE_NAVIGATION_TYPE_FORMSUBMITTE;
            break;
        case blink::WebNavigationTypeBackForward:
            navigationType = WKE_NAVIGATION_TYPE_BACKFORWARD;
            break;
        case blink::WebNavigationTypeReload:
            navigationType = WKE_NAVIGATION_TYPE_RELOAD;
            break;
        case blink::WebNavigationTypeFormResubmitted:
            navigationType = WKE_NAVIGATION_TYPE_FORMRESUBMITT;
            break;
        case blink::WebNavigationTypeOther:
            navigationType = WKE_NAVIGATION_TYPE_OTHER;
            break;
        }

        // WebString::utf8�ں���utf������ʱ���ᵱ��latin��ת��
        WebString url16 = info.urlRequest.url().string();
        wke::CString url(url16);

        wkeWebView webView = m_webPage->wkeWebView();
        wkeTempCallbackInfo* tempInfo = wkeGetTempCallbackInfo(webView);
        tempInfo->size = sizeof(wkeTempCallbackInfo);
        tempInfo->frame = frameIdToWkeFrame(m_webPage, m_frame);

        bool ok = m_webPage->wkeHandler().navigationCallback(webView, m_webPage->wkeHandler().navigationCallbackParam, navigationType, &url);
        if (!ok)
            return WebNavigationPolicyIgnore;
		info.urlRequest.setURL(WebURL(KURL(blink::ParsedURLString, url.string())));
    }
#endif
    return info.defaultPolicy;
}

// void WebFrameClientImpl::willRequestResource(WebLocalFrame*, const WebCachedURLRequest&)
// {
// 
// }

void WebFrameClientImpl::didDispatchPingLoader(const WebURL& url) {}

static void setRequestHead(WebLocalFrame* webFrame, WebPage* webPage, WebURLRequest& request)
{
    request.addHTTPHeaderField("Accept-Language", webPage->webPageImpl()->acceptLanguages());

    request.addHTTPHeaderField("Upgrade-Insecure-Requests", "1");
    request.addHTTPHeaderField("Connection", "keep-alive");
    request.addHTTPHeaderField("Accept-Encoding", "deflate, gzip");

    String ua = request.httpHeaderField("user-agent");
    if (ua.isEmpty())
        request.addHTTPHeaderField("user-agent", AtomicString(String(blink::Platform::current()->userAgent())));

    //     request.addHTTPHeaderField("Cache-Control", "max-age=0");

    //     WebViewImpl* viewImpl = m_webPage->webViewImpl();
    //     if (!viewImpl)
    //         return;
    //     Page* page = viewImpl->page();
    //     if (!page)
    //         return;
    // 
    //     Settings& setting = page->settings();
    //     headerFieldValue = "GBK"; // setting.defaultTextEncodingName();
    //     headerFieldValue.append(",utf-8;q=0.7,*;q=0.3");
    //     value = headerFieldValue.latin1().data();
    //     request.addHTTPHeaderField("Accept-Charset", WebString::fromLatin1((const WebLChar*)value.data(), value.length()));

    // Set the first party for cookies url if it has not been set yet (new
    // requests). For redirects, it is updated by WebURLLoaderImpl.
    if (request.firstPartyForCookies().isEmpty()) {
        if (request.getFrameType() == blink::WebURLRequest::FrameTypeTopLevel) {
            request.setFirstPartyForCookies(request.url());
        } else if (webFrame) {
            // TODO(nasko): When the top-level frame is remote, there is no document.
            // This is broken and should be fixed to propagate the first party.
            WebFrame* top = webFrame->top();
            if (!top)
                top = webFrame;
            if (top->isWebLocalFrame())
                request.setFirstPartyForCookies(webFrame->top()->document().firstPartyForCookies());
        }
    }

    const char kDefaultAcceptHeader[] = "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8";
    const char kAcceptHeader[] = "Accept";

    //     WebDataSource* provisionalDataSource = webFrame->provisionalDataSource();
    //     WebDataSource* dataSource = provisionalDataSource ? provisionalDataSource : webFrame->dataSource();

    // The request's extra data may indicate that we should set a custom user
    // agent. This needs to be done here, after WebKit is through with setting the
    // user agent on its own. Similarly, it may indicate that we should set an
    // X-Requested-With header. This must be done here to avoid breaking CORS
    // checks.
    // PlzNavigate: there may also be a stream url associated with the request.

    // Add the default accept header for frame request if it has not been set
    // already.
    if ((request.getFrameType() == blink::WebURLRequest::FrameTypeTopLevel ||
        request.getFrameType() == blink::WebURLRequest::FrameTypeNested) && request.httpHeaderField(WebString::fromUTF8(kAcceptHeader)).isEmpty()) {
        request.setHTTPHeaderField(WebString::fromUTF8(kAcceptHeader), WebString::fromUTF8(kDefaultAcceptHeader));
    }

    // Add an empty HTTP origin header for non GET methods if none is currently
    // present.
    //request.addHTTPOriginIfNeeded(blink::WebSecurityOrigin());

    // This is an instance where we embed a copy of the routing id
    // into the data portion of the message. This can cause problems if we
    // don't register this id on the browser side, since the download manager
    // expects to find a RenderViewHost based off the id.
    request.setHasUserGesture(blink::WebUserGestureIndicator::isProcessingUserGesture());

}

void WebFrameClientImpl::willSendRequest(WebLocalFrame* webFrame, WebURLRequest& request)
{
    if (request.getExtraData()) // ResourceLoader::willSendRequest���ߵ���
        return;

//     blink::Frame* blinkFrame = blink::toCoreFrame(webFrame);
//     blink::Settings* settings = blinkFrame->settings();
//     settings->setLoadsImagesAutomatically(true);

    net::RequestExtraData* requestExtraData = new net::RequestExtraData();

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    requestExtraData->page = m_webPage;
#endif

    requestExtraData->setFrame(webFrame); // ����ģʽ����Ҫ�˶���
    request.setExtraData(requestExtraData);

    setRequestHead(webFrame, m_webPage, request);
}

void WebFrameClientImpl::didReceiveResponse(const WebURLResponse&)
{

}

//void WebFrameClientImpl::didChangeResourcePriority(WebLocalFrame* webFrame, unsigned identifier, const WebURLRequest::Priority& priority, int) {}

void WebFrameClientImpl::runModalAlertDialog(const WebString& message)
{
#if defined(OS_WIN)
    bool needCall = true;
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    if (m_webPage->wkeHandler().alertBoxCallback && m_webPage->getState() == pageInited) {
        needCall = false;
        wke::CString wkeMsg(message);
        m_webPage->wkeHandler().alertBoxCallback(m_webPage->wkeWebView(), m_webPage->wkeHandler().alertBoxCallbackParam, &wkeMsg);
    }
#endif

    if (!needCall)
        return;

    Vector<UChar> text = WTF::ensureUTF16UChar(message, true);
    ::MessageBoxW(nullptr, text.data(), L"Miniblink Alert", 0);
#endif
}

bool WebFrameClientImpl::runModalConfirmDialog(const WebString& message)
{
#if defined(OS_WIN)
    bool needCall = true;
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    if (m_webPage->wkeHandler().confirmBoxCallback && m_webPage->getState() == pageInited) {
        needCall = false;
        wke::CString wkeMsg(message);
        return m_webPage->wkeHandler().confirmBoxCallback(m_webPage->wkeWebView(), m_webPage->wkeHandler().confirmBoxCallbackParam, &wkeMsg);
    }
#endif

    if (!needCall)
        return false;

    Vector<UChar> text = WTF::ensureUTF16UChar(message, true);
    int result = ::MessageBoxW(NULL, text.data(), L"Miniblink Confirm", MB_OKCANCEL);
    return result == IDOK;
#else
    return true;
#endif
}

bool WebFrameClientImpl::runModalPromptDialog(const WebString& message, const WebString& defaultValue, WebString* actualValue)
{
#if defined(OS_WIN)
    bool needCall = true;
    bool result = false;
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    if (m_webPage->wkeHandler().promptBoxCallback && m_webPage->getState() == pageInited) {
        needCall = false;
        wke::CString wkeMsg(message);
        wke::CString defaultResult(defaultValue);
        wke::CString resultString("", 0, true);
        result = m_webPage->wkeHandler().promptBoxCallback(m_webPage->wkeWebView(),
            m_webPage->wkeHandler().promptBoxCallbackParam, &wkeMsg, &defaultResult, &resultString);

        const wchar_t* resultStringW = resultString.stringW();
        actualValue->assign(resultStringW, wcslen(resultStringW));
        return result;
    }
#endif

    if (!needCall)
        return false;

    Vector<UChar> text = WTF::ensureUTF16UChar(message, true);
    int resultOk = ::MessageBoxW(NULL, text.data(), L"Miniblink Prompt", MB_OKCANCEL);
    return resultOk == IDOK;
#else
    return true;
#endif
}

bool WebFrameClientImpl::runModalBeforeUnloadDialog(bool isReload)
{
    return true;
}

void WebFrameClientImpl::showContextMenu(const blink::WebContextMenuData& data)
{
#if defined(OS_WIN)
    if (!m_menu)
        m_menu = new ContextMenu(m_webPage);

//     blink::WebDocument doc = data.node.document();
//     blink::WebLocalFrame* frmae = doc.frame();
    int64_t frameId = 0;
    if (m_frame)
        frameId = WebPageImpl::getFrameIdByBlinkFrame(m_frame);

    if (m_webPage->getContextMenuEnabled())
        m_menu->show(data, frameId);
#endif
}

// void WebFrameClientImpl::clearContextMenu()
// {
// 
// }

void WebFrameClientImpl::didCreateScriptContext(WebLocalFrame* frame, v8::Local<v8::Context> context, int worldId)
{
    v8::V8::SetCaptureStackTraceForUncaughtExceptions(true, 50, v8::StackTrace::kDetailed);

    int extensionGroup = 0;
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    if (frame->top() == frame)
        wke::onCreateGlobalObjectInMainFrame(this, frame, context, extensionGroup, worldId);
    else
        wke::onCreateGlobalObjectInSubFrame(this, frame, context, extensionGroup, worldId);

    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    if (m_webPage->wkeHandler().didCreateScriptContextCallback && m_webPage->getState() == pageInited)
        m_webPage->wkeHandler().didCreateScriptContextCallback(m_webPage->wkeWebView(), m_webPage->wkeHandler().didCreateScriptContextCallbackParam,
            frameIdToWkeFrame(m_webPage, frame), &context, extensionGroup, worldId);
#endif
#if ENABLE_NODEJS
    if (isNodejsEnable()) {        
        NodeBindingInMbCore* nodebinding = nodeBindNodejsOnDidCreateScriptContext(m_webPage->wkeWebView(), frameIdToWkeFrame(m_webPage, frame), &context);
        m_nodebindings.add(frame, nodebinding);
    }
#endif
}

void WebFrameClientImpl::willReleaseScriptContext(WebLocalFrame* frame, v8::Local<v8::Context> context, int worldId)
{
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    if (frame->top() == frame) {
        wke::onReleaseGlobalObject(this, frame, context, worldId);
        m_webPage->disablePaint();
    }

    wke::AutoDisableFreeV8TempObejct autoDisableFreeV8TempObejct;
    if (m_webPage->wkeHandler().willReleaseScriptContextCallback && m_webPage->getState() == pageInited)
        m_webPage->wkeHandler().willReleaseScriptContextCallback(m_webPage->wkeWebView(), m_webPage->wkeHandler().willReleaseScriptContextCallbackParam,
            frameIdToWkeFrame(m_webPage, frame), &context, worldId);
#endif

#if ENABLE_NODEJS
    if (isNodejsEnable()) {
        WTF::HashMap<WebFrame *, NodeBindingInMbCore*>::iterator it = m_nodebindings.find(frame);
        if (it != m_nodebindings.end()) {
            NodeBindingInMbCore* nodebinding = it->value;
            nodeWillReleaseScriptContext(nodebinding);
        }
    }
#endif
}

class WebURLLoaderClientWrapped : public blink::WebURLLoaderClient {
public:
    WebURLLoaderClientWrapped(WebFrameClientImpl* frameClient, 
        WebPage* webPage, blink::WebLocalFrame* frame, const WebString& downloadName, const blink::KURL& kurl)
    {
        m_frameClient = frameClient;
        m_webPage = webPage;
        m_frame = frame;
        m_downloadName = downloadName;
        m_kurl = kurl;
    }

    bool willFollowRedirect(WebURLRequest& request, const WebURLResponse& redirectResponse) override
    {
        if (request.getExtraData()) // ResourceLoader::willSendRequest���ߵ���
            return true;

        String downloadName = m_downloadName;
        if (!downloadName.isNull() && !m_downloadName.isEmpty())
            downloadName.insert("attachment; filename=", 0);

        net::RequestExtraData* requestExtraData = new net::RequestExtraData();
        requestExtraData->setIsDownload(downloadName);

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
        requestExtraData->page = m_webPage;
#endif
        requestExtraData->setFrame(m_frame); // ����ģʽ����Ҫ�˶���
        request.setExtraData(requestExtraData);
        setRequestHead(m_frame, m_webPage, request);

        return true;
    }

    void didSendData(unsigned long long bytesSent, unsigned long long totalBytesToBeSent) override 
    {
        OutputDebugStringA("WebURLLoaderClientWrapped::didSendData\n");
    }

    void didReceiveResponse(const WebURLResponse&) override 
    {
        OutputDebugStringA("WebURLLoaderClientWrapped::didReceiveResponse\n");
    }

    void didReceiveResponse(const WebURLResponse&, std::unique_ptr<WebDataConsumerHandle> handle) override
    {
        OutputDebugStringA("WebURLLoaderClientWrapped::didReceiveResponse\n");
    }

    void didReceiveData(const char* data, int length) override
    {
        m_cacheData.append(data, length);
    }

    void didReceiveCachedMetadata(const char* data, int length) override {};

    void didFinishLoading(double finishTime, int64_t totalEncodedDataLength, int64_t totalEncodedBodyLength) override
    {
        dataBindDispatch(m_webPage, m_kurl, m_downloadName, &m_cacheData);
        delete this;
    }

    void didFail(const WebURLError&, int64_t totalEncodedDataLength, int64_t totalEncodedBodyLength) override
    {
        delete this;
    }

    void didDownloadData(int, int) override {};

    static void dataBindDispatch(WebPage* webPage, const blink::KURL& kurl, const String& downloadName, const Vector<char>* data)
    {
        wkeNetJobDataBind dataBind = { 0 };
        wkeDownload2Callback cb = webPage->wkeHandler().download2Callback;
        if (!cb)
            return;

        String mimeType;
        String charset;
        Vector<char> urlData;
        const Vector<char>* dataPtr = data;
        if (!data) {
            bool b = net::parseDataURL(kurl, mimeType, charset, urlData);
            if (!b || 0 == urlData.size())
                return;
            dataPtr = &urlData;
        }

        String disposition = downloadName;
        if (!disposition.isNull() && !disposition.isEmpty())
            disposition.insert("attachment; filename=", 0);
        else
            disposition = "attachment; filename=unknow.dat";
        Vector<char> dispositionBuf = WTF::ensureStringToUTF8(disposition, true);

        size_t expectedContentLength = 0;
        void* param = webPage->wkeHandler().download2CallbackParam;

        Vector<char> urlBuf = WTF::ensureStringToUTF8(kurl.string(), true);
        wkeDownloadOpt opt = cb(webPage->wkeWebView(), param, expectedContentLength, urlBuf.data(), "", dispositionBuf.data(), nullptr, &dataBind);
        if (kWkeDownloadOptCacheData != opt)
            return;

        if (dataBind.recvCallback)
            dataBind.recvCallback(dataBind.param, nullptr, dataPtr->data(), dataPtr->size());

        if (dataBind.finishCallback)
            dataBind.finishCallback(dataBind.param, nullptr, WKE_LOADING_SUCCEEDED);
    }

private:
    WebFrameClientImpl* m_frameClient;
    WebPage* m_webPage;
    blink::WebLocalFrame* m_frame;
    String m_downloadName;
    blink::KURL m_kurl;

    Vector<char> m_cacheData;
};

void WebFrameClientImpl::loadURLExternally(const WebURLRequest& request, WebNavigationPolicy, const WebString& downloadName, bool shouldReplaceCurrentEntry)
{
    blink::KURL kurl = request.url();
    if (kurl.protocolIsData()) {
        WebURLLoaderClientWrapped::dataBindDispatch(m_webPage, kurl, downloadName, nullptr);
        return;
    }

    blink::WebURLLoader* loader;
    loader = Platform::current()->createURLLoader();

    wkeDownload2Callback cb = m_webPage->wkeHandler().download2Callback;
    void* param = m_webPage->wkeHandler().download2CallbackParam;

    blink::WebURLRequest requestWrapped(request);
    WebURLLoaderClientWrapped* clientWrapped = new WebURLLoaderClientWrapped(this, m_webPage, m_frame, downloadName, kurl);
    clientWrapped->willFollowRedirect(requestWrapped, blink::WebURLResponse());
    loader->loadAsynchronously(requestWrapped, clientWrapped);
}

// WebGeolocationClient* WebFrameClientImpl::geolocationClient()
// {
//     if (!m_webGeolocationClientImpl)
//         m_webGeolocationClientImpl = new WebGeolocationClientImpl();
//     return m_webGeolocationClientImpl;
// }

} // namespace blink