
#include "content/browser/WebFrameClientImpl.h"
#include "content/browser/WebPage.h"
#include "third_party/WebKit/Source/web/WebLocalFrameImpl.h"
#include "third_party/WebKit/Source/web/WebViewImpl.h"
#include "third_party/WebKit/public/web/WebFrameClient.h"

// #include "cef/include/capi/cef_base_capi.h"
// #include "cef/include/capi/cef_browser_capi.h"
// #include "cef/include/capi/cef_client_capi.h"
// #include "cef/include/internal/cef_ptr.h"
// #include "cef/include/internal/cef_export.h"
// #include "cef/include/cef_app.h"
// #include "cef/include/cef_client.h"
// #include "cef/libcef/common/CommonBase.h"
// #include "cef/libcef/common/CefRequestImpl.h"
// #include "cef/libcef/common/ContentClient.h"
// #include "cef/libcef/common/StringUtil.h"
// #include "cef/libcef/browser/CefFrameHostImpl.h"
// #include "cef/libcef/browser/CefBrowserHostImpl.h"

#include "third_party/WebKit/Source/core/frame/Settings.h"
#include "third_party/WebKit/Source/core/page/Page.h"
#include "third_party/WebKit/Source/platform/Language.h"

#include "content/web_impl_win/WebCookieJarImpl.h"

namespace content {

WebFrameClientImpl::WebFrameClientImpl()
{
    m_loading = false;
}

void WebFrameClientImpl::didAddMessageToConsole(const WebConsoleMessage& message,
    const WebString& sourceName, unsigned sourceLine, const WebString& stackTrace)
{
    WTF::String outstr(L"console:");

    outstr.append((WTF::String)(message.text));
    outstr.append(L" ;sourceName:");
    outstr.append(sourceName);

    outstr.append(L" ;sourceLine:");
    outstr.append(String::number(sourceLine));
    outstr.append(L" \n");
    OutputDebugStringW(outstr.charactersWithNullTermination().data());
}

void WebFrameClientImpl::setWebPage(WebPage* webPage)
{
    m_webPage = webPage;
}

WebLocalFrame* WebFrameClientImpl::createChildFrame(WebLocalFrame* parent,
    WebTreeScopeType,
    const WebString& name,
    const WebString& uniqueName,
    WebSandboxFlags sandboxFlags,
    const WebFrameOwnerProperties&)
{
    WebLocalFrameImpl* webLocalFrameImpl = WebLocalFrameImpl::create(WebTreeScopeType::Document, this, parent);
    parent->appendChild(webLocalFrameImpl);
    return webLocalFrameImpl; // TODO delete;
}

void WebFrameClientImpl::frameDetached(WebLocalFrame* child, DetachType)
{
    child->parent()->removeChild(child);
}

WebCookieJar* WebFrameClientImpl::cookieJar()
{
    return WebCookieJarImpl::inst();
}

void WebFrameClientImpl::onLoadingStateChange(bool isLoading, bool toDifferentDocument)
{
    m_loading = isLoading;

    if (!m_webPage)
        return;
    //     CefBrowserHostImpl* browser = m_webPage->browser();
    //     if (!browser || !browser->client().get())
    //         return;
    //     WebViewImpl* webview = m_webPage->webViewImpl();
    //     if (!webview || !webview->client())
    //         return;
    //
    //     bool canGoBack = webview->client()->historyForwardListCount() > 0;
    //     bool canGoForward = webview->client()->historyBackListCount() > 0;
    //
    //     CefRefPtr<CefLoadHandler> handler = browser->client()->GetLoadHandler();
    //     if (handler.get())
    //         handler->OnLoadingStateChange(browser, isLoading, canGoBack, canGoForward);
}

void WebFrameClientImpl::didStartLoading(bool toDifferentDocument)
{
    onLoadingStateChange(true, toDifferentDocument);
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

void WebFrameClientImpl::didCreateDataSource(WebLocalFrame*, WebDataSource*) { }

void WebFrameClientImpl::didStartProvisionalLoad(WebLocalFrame* localFrame)
{
    //     cef::BrowserImpl* browserImpl = m_cefBrowserHostImpl->m_browserImpl;
    //     cef_load_handler_t* loadHandler = browserImpl->m_loadHandler;
    //
    //     cef::FrameImpl* frame = new cef::FrameImpl(browserImpl, m_webPage, localFrame);
    //     frame->ref();
    //
    //     browserImpl->ref();
    //     loadHandler->on_load_start(loadHandler, browserImpl->cast(), frame->cast());
    //
    //     onLoadingStateChange(m_cefBrowserHostImpl, localFrame->isLoading());
}

void WebFrameClientImpl::didReceiveServerRedirectForProvisionalLoad(WebLocalFrame*) { }

void WebFrameClientImpl::didFailProvisionalLoad(WebLocalFrame*, const WebURLError&, WebHistoryCommitType) { }

void WebFrameClientImpl::didCommitProvisionalLoad(WebLocalFrame* webLocalFrame, const WebHistoryItem&, WebHistoryCommitType)
{
    //onLoadingStateChange(true);
}

void WebFrameClientImpl::didCreateNewDocument(WebLocalFrame* frame) { }

void WebFrameClientImpl::didClearWindowObject(WebLocalFrame* frame) { }

void WebFrameClientImpl::didCreateDocumentElement(WebLocalFrame*) { }

void WebFrameClientImpl::didReceiveTitle(WebLocalFrame* frame, const WebString& title, WebTextDirection direction) { }

void WebFrameClientImpl::didChangeIcon(WebLocalFrame*, WebIconURL::Type) { }

void WebFrameClientImpl::didFinishDocumentLoad(WebLocalFrame*)
{
    //     cef_load_handler_t* loadHandler = m_cefBrowserHostImpl->m_browserImpl->m_loadHandler;
    //     m_cefBrowserHostImpl->m_browserImpl->ref();
    //     loadHandler->on_loading_state_change(loadHandler, &m_cefBrowserHostImpl->m_browserImpl->m_baseClass, false, false, false);
}

void WebFrameClientImpl::didHandleOnloadEvents(WebLocalFrame*) { }

void WebFrameClientImpl::didFailLoad(WebLocalFrame*, const WebURLError&, WebHistoryCommitType) { }

void WebFrameClientImpl::didFinishLoad(WebLocalFrame*) { }

void WebFrameClientImpl::didNavigateWithinPage(WebLocalFrame*, const WebHistoryItem&, WebHistoryCommitType, bool contentInitiated)
{
    //     cef_load_handler_t* loadHandler = m_cefBrowserHostImpl->m_browserImpl->m_loadHandler;
    //     m_cefBrowserHostImpl->m_browserImpl->ref();
    //     loadHandler->on_loading_state_change(loadHandler, &m_cefBrowserHostImpl->m_browserImpl->m_baseClass, false, false, false);
}

void WebFrameClientImpl::didUpdateCurrentHistoryItem() { }

void WebFrameClientImpl::didChangeManifest() { }

//void WebFrameClientImpl::didChangeDefaultPresentation(WebLocalFrame*) { }
void WebFrameClientImpl::didChangeThemeColor() { }

void WebFrameClientImpl::dispatchLoad() { }

WebNavigationPolicy WebFrameClientImpl::decidePolicyForNavigation(const NavigationPolicyInfo& info)
{
    return info.defaultPolicy;
    //     if (!m_webPage || !m_webPage->browser() || !info.frame)
    //         return info.defaultPolicy;
    //
    //     CefRefPtr<CefApp> application = CefContentClient::Get()->application();
    //     if (!application.get())
    //         return info.defaultPolicy;
    //
    //     CefRefPtr<CefRenderProcessHandler> handler = application->GetRenderProcessHandler();
    //     if (!handler.get())
    //         return info.defaultPolicy;
    //
    //     CefStringUTF16 urlSpec;
    //     cef::SetWebStringToCefString(info.urlRequest.url().spec().utf16(), urlSpec);
    //
    //     CefStringUTF16 frameName;
    //     cef::SetWebStringToCefString(info.frame->uniqueName(), frameName);
    //
    //     CefRefPtr<CefFrameHostImpl> framePtr = new CefFrameHostImpl(m_webPage->browser(), info.frame, /*urlSpec,*/ frameName);
    //
    //     CefRefPtr<CefRequest> requestPtr(CefRequest::Create());
    //     CefRequestImpl* requestImpl = static_cast<CefRequestImpl*>(requestPtr.get());
    //     requestImpl->Set(info.urlRequest);
    //     requestImpl->SetReadOnly(true);
    //
    //     cef_navigation_type_t navigation_type = NAVIGATION_OTHER;
    //     switch (info.navigationType) {
    //     case blink::WebNavigationTypeLinkClicked:
    //         navigation_type = NAVIGATION_LINK_CLICKED;
    //         break;
    //     case blink::WebNavigationTypeFormSubmitted:
    //         navigation_type = NAVIGATION_FORM_SUBMITTED;
    //         break;
    //     case blink::WebNavigationTypeBackForward:
    //         navigation_type = NAVIGATION_BACK_FORWARD;
    //         break;
    //     case blink::WebNavigationTypeReload:
    //         navigation_type = NAVIGATION_RELOAD;
    //         break;
    //     case blink::WebNavigationTypeFormResubmitted:
    //         navigation_type = NAVIGATION_FORM_RESUBMITTED;
    //         break;
    //     case blink::WebNavigationTypeOther:
    //         navigation_type = NAVIGATION_OTHER;
    //         break;
    //     }
    //
    //     if (handler->OnBeforeNavigation(((CefBrowser*)m_webPage->browser()), framePtr.get(),
    //         requestPtr.get(), navigation_type, info.isRedirect))
    //         return info.defaultPolicy;
    //
    //     return WebNavigationPolicyIgnore;
}

// void WebFrameClientImpl::willRequestResource(WebLocalFrame*, const WebCachedURLRequest&)
// {
//
// }

void WebFrameClientImpl::willSendRequest(WebLocalFrame*, WebURLRequest& request)
{
    String headerFieldValue = blink::defaultLanguage();
    headerFieldValue.append(",en,*");

    CString value = headerFieldValue.latin1().data();
    request.addHTTPHeaderField("Accept-Language", WebString::fromLatin1((const WebLChar*)value.data(), value.length()));

    WebViewImpl* viewImpl = m_webPage->webViewImpl();
    if (!viewImpl)
        return;
    Page* page = viewImpl->page();
    if (!page)
        return;
    Settings& setting = page->settings();
    headerFieldValue = "GBK"; // setting.defaultTextEncodingName();
    headerFieldValue.append(",utf-8;q=0.7,*;q=0.3");
    value = headerFieldValue.latin1().data();
    request.addHTTPHeaderField("Accept-Charset", WebString::fromLatin1((const WebLChar*)value.data(), value.length()));
}

void WebFrameClientImpl::didReceiveResponse(const WebURLResponse&)
{
}

// void WebFrameClientImpl::didChangeResourcePriority(unsigned identifier, const WebURLRequest::Priority& priority, int)
// {
// }

} // namespace blink