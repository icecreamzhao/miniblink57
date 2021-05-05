
#ifndef WebFrameClientImpl_h
#define WebFrameClientImpl_h

#include "third_party/WebKit/public/web/WebFrameClient.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"

namespace cef {
class BrowserHostImpl;
class BrowserImpl;
}

using namespace blink;

namespace content {

class WebPage;

class WebFrameClientImpl : public blink::WebFrameClient {
public:
    WebFrameClientImpl();

    virtual void didAddMessageToConsole(const WebConsoleMessage& message, const WebString& sourceName, unsigned sourceLine, const WebString& stackTrace) override;

    virtual WebLocalFrame* createChildFrame(WebLocalFrame* parent,
        WebTreeScopeType,
        const WebString& name,
        const WebString& uniqueName,
        WebSandboxFlags sandboxFlags,
        const WebFrameOwnerProperties&) override;

    virtual void frameDetached(WebLocalFrame* child, DetachType) override;

    void loadURLExternally(WebLocalFrame*, const WebURLRequest&, WebNavigationPolicy, const WebString& downloadName)
    {
        OutputDebugStringA(__FUNCTION__);
    }

    // Navigational notifications ------------------------------------------
    // These notifications bracket any loading that occurs in the WebFrame.
    virtual void didStartLoading(bool toDifferentDocument) override;
    virtual void didStopLoading() override;

    // Notification that some progress was made loading the current frame.
    // loadProgress is a value between 0 (nothing loaded) and 1.0 (frame fully
    // loaded).
    virtual void didChangeLoadProgress(double loadProgress) override;

    // A form submission has been requested, but the page's submit event handler
    // hasn't yet had a chance to run (and possibly alter/interrupt the submit.)
    virtual void willSendSubmitEvent(const WebFormElement&) override;

    // A form submission is about to occur.
    virtual void willSubmitForm(const WebFormElement&) override;

    // A datasource has been created for a new navigation.  The given
    // datasource will become the provisional datasource for the frame.
    virtual void didCreateDataSource(WebLocalFrame*, WebDataSource*) override;

    // A new provisional load has been started.
    virtual void didStartProvisionalLoad(WebLocalFrame* localFrame) override;

    // The provisional load was redirected via a HTTP 3xx response.
    virtual void didReceiveServerRedirectForProvisionalLoad(WebLocalFrame*) override;

    // The provisional load failed. The WebHistoryCommitType is the commit type
    // that would have been used had the load succeeded.
    virtual void didFailProvisionalLoad(WebLocalFrame*, const WebURLError&, WebHistoryCommitType) override;

    // The provisional datasource is now committed.  The first part of the
    // response body has been received, and the encoding of the response
    // body is known.
    virtual void didCommitProvisionalLoad(WebLocalFrame*, const WebHistoryItem&, WebHistoryCommitType) override;

    // The frame's document has just been initialized.
    virtual void didCreateNewDocument(WebLocalFrame* frame) override;

    // The window object for the frame has been cleared of any extra
    // properties that may have been set by script from the previously
    // loaded document.
    virtual void didClearWindowObject(WebLocalFrame* frame) override;

    // The document element has been created.
    virtual void didCreateDocumentElement(WebLocalFrame*) override;

    // The page title is available.
    virtual void didReceiveTitle(WebLocalFrame* frame, const WebString& title, WebTextDirection direction) override;

    // The icon for the page have changed.
    virtual void didChangeIcon(WebLocalFrame*, WebIconURL::Type) override;

    // The frame's document finished loading.
    virtual void didFinishDocumentLoad(WebLocalFrame*) override;

    // The 'load' event was dispatched.
    virtual void didHandleOnloadEvents(WebLocalFrame*) override;

    // The frame's document or one of its subresources failed to load. The
    // WebHistoryCommitType is the commit type that would have been used had the
    // load succeeded.
    virtual void didFailLoad(WebLocalFrame*, const WebURLError&, WebHistoryCommitType) override;

    // The frame's document and all of its subresources succeeded to load.
    virtual void didFinishLoad(WebLocalFrame*) override;

    // The navigation resulted in no change to the documents within the page.
    // For example, the navigation may have just resulted in scrolling to a
    // named anchor or a PopState event may have been dispatched.
    virtual void didNavigateWithinPage(WebLocalFrame*, const WebHistoryItem&, WebHistoryCommitType, bool contentInitiated) override;

    // Called upon update to scroll position, document state, and other
    // non-navigational events related to the data held by WebHistoryItem.
    // WARNING: This method may be called very frequently.
    virtual void didUpdateCurrentHistoryItem() override;

    // The frame's manifest has changed.
    virtual void didChangeManifest() override;

    // The frame's presentation URL has changed.
    //virtual void didChangeDefaultPresentation(WebLocalFrame*) override;

    // The frame's theme color has changed.
    virtual void didChangeThemeColor() override;

    // Called to dispatch a load event for this frame in the FrameOwner of an
    // out-of-process parent frame.
    virtual void dispatchLoad() override;

    // Low-level resource notifications ------------------------------------

    // An element will request a resource.
    //virtual void willRequestResource(WebLocalFrame*, const WebCachedURLRequest&) override;

    // A request is about to be sent out, and the client may modify it.  Request
    // is writable, and changes to the URL, for example, will change the request
    // made.  If this request is the result of a redirect, then redirectResponse
    // will be non-null and contain the response that triggered the redirect.
    virtual void willSendRequest(WebLocalFrame*, WebURLRequest&) override;

    // Response headers have been received for the resource request given
    // by identifier.
    virtual void didReceiveResponse(const WebURLResponse&) override;

    //virtual void didChangeResourcePriority(unsigned identifier, const WebURLRequest::Priority& priority, int) override;

    // Navigational queries ------------------------------------------------
    virtual WebNavigationPolicy decidePolicyForNavigation(const NavigationPolicyInfo& info) override;

    void setWebPage(WebPage* webPage);

    // Services ------------------------------------------------------------

    // A frame specific cookie jar.  May return null, in which case
    // WebKitPlatformSupport::cookieJar() will be called to access cookies.
    virtual WebCookieJar* cookieJar() override;

    bool isLoading() { return m_loading; }

protected:
    void onLoadingStateChange(bool isLoading, bool toDifferentDocument);

    WebPage* m_webPage;
    bool m_loading;
};

} // namespace blink

#endif // WebFrameClientImpl_h