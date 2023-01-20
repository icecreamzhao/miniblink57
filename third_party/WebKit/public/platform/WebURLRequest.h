/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebURLRequest_h
#define WebURLRequest_h

<<<<<<< HEAD
#include "WebAddressSpace.h"
#include "WebCommon.h"
#include "WebHTTPBody.h"
#include "WebReferrerPolicy.h"
#include <memory>
=======
#include "WebCommon.h"
#include "WebHTTPBody.h"
#include "WebReferrerPolicy.h"
>>>>>>> miniblink49

namespace blink {

class ResourceRequest;
class WebHTTPBody;
class WebHTTPHeaderVisitor;
class WebSecurityOrigin;
class WebString;
class WebURL;
<<<<<<< HEAD
enum class WebCachePolicy;

class WebURLRequest {
public:
=======
class WebURLRequestPrivate;

class WebURLRequest {
public:
    enum CachePolicy {
        UseProtocolCachePolicy, // normal load
        ReloadIgnoringCacheData, // reload
        ReturnCacheDataElseLoad, // back/forward or encoding change - allow stale data
        ReturnCacheDataDontLoad, // results of a post - allow stale data and only use cache
        ReloadBypassingCache, // end-to-end reload
    };

>>>>>>> miniblink49
    enum Priority {
        PriorityUnresolved = -1,
        PriorityVeryLow,
        PriorityLow,
        PriorityMedium,
        PriorityHigh,
        PriorityVeryHigh,
    };

<<<<<<< HEAD
    // Corresponds to Fetch's "context":
    // http://fetch.spec.whatwg.org/#concept-request-context
=======
    // Corresponds to Fetch's "context": http://fetch.spec.whatwg.org/#concept-request-context
>>>>>>> miniblink49
    enum RequestContext {
        RequestContextUnspecified = 0,
        RequestContextAudio,
        RequestContextBeacon,
        RequestContextCSPReport,
        RequestContextDownload,
        RequestContextEmbed,
        RequestContextEventSource,
        RequestContextFavicon,
        RequestContextFetch,
        RequestContextFont,
        RequestContextForm,
        RequestContextFrame,
        RequestContextHyperlink,
        RequestContextIframe,
        RequestContextImage,
        RequestContextImageSet,
        RequestContextImport,
        RequestContextInternal,
        RequestContextLocation,
        RequestContextManifest,
        RequestContextObject,
        RequestContextPing,
        RequestContextPlugin,
        RequestContextPrefetch,
        RequestContextScript,
        RequestContextServiceWorker,
        RequestContextSharedWorker,
        RequestContextSubresource,
        RequestContextStyle,
        RequestContextTrack,
        RequestContextVideo,
        RequestContextWorker,
        RequestContextXMLHttpRequest,
        RequestContextXSLT
    };

<<<<<<< HEAD
    // Corresponds to Fetch's "context frame type":
    // http://fetch.spec.whatwg.org/#concept-request-context-frame-type
=======
    // Corresponds to Fetch's "context frame type": http://fetch.spec.whatwg.org/#concept-request-context-frame-type
>>>>>>> miniblink49
    enum FrameType {
        FrameTypeAuxiliary,
        FrameTypeNested,
        FrameTypeNone,
        FrameTypeTopLevel
    };

    enum FetchRequestMode {
        FetchRequestModeSameOrigin,
        FetchRequestModeNoCORS,
        FetchRequestModeCORS,
<<<<<<< HEAD
        FetchRequestModeCORSWithForcedPreflight,
        FetchRequestModeNavigate
=======
        FetchRequestModeCORSWithForcedPreflight
>>>>>>> miniblink49
    };

    enum FetchCredentialsMode {
        FetchCredentialsModeOmit,
        FetchCredentialsModeSameOrigin,
<<<<<<< HEAD
        FetchCredentialsModeInclude,
        FetchCredentialsModePassword
    };

    enum FetchRedirectMode {
        FetchRedirectModeFollow,
        FetchRedirectModeError,
        FetchRedirectModeManual
=======
        FetchCredentialsModeInclude
>>>>>>> miniblink49
    };

    // Used to report performance metrics timed from the UI action that
    // triggered them (as opposed to navigation start time used in the
    // Navigation Timing API).
    enum InputToLoadPerfMetricReportPolicy {
        NoReport, // Don't report metrics for this WebURLRequest.
        ReportLink, // Report metrics with UI action link clicked.
        ReportIntent, // Report metrics with UI action displayed intent.
    };

<<<<<<< HEAD
    // The Previews state which determines whether to request a Preview version of
    // the resource.
    enum PreviewsState {
        PreviewsUnspecified = 0, // Let the browser process decide whether or
        // not to request Preview types.
        ServerLoFiOn = 1 << 0, // Request a Lo-Fi version of the resource
        // from the server.
        ClientLoFiOn = 1 << 1, // Request a Lo-Fi version of the resource
        // from the client.
        PreviewsNoTransform = 1 << 2, // Explicitly forbid Previews
        // transformations.
        PreviewsOff = 1 << 3, // Request a normal (non-Preview) version of
        // the resource. Server transformations may
        // still happen if the page is heavy.
        PreviewsStateLast = PreviewsOff
    };

    // Indicates which types of ServiceWorkers should skip handling this request.
    enum class SkipServiceWorker {
        // Request can be handled both by a controlling same-origin worker and
        // a cross-origin foreign fetch service worker.
        None,
        // Request should not be handled by a same-origin controlling worker,
        // but can be intercepted by a foreign fetch service worker.
        Controlling,
        // Request should skip all possible service workers.
        All
    };

    enum class LoadingIPCType {
        ChromeIPC,
        Mojo,
    };

=======
>>>>>>> miniblink49
    class ExtraData {
    public:
        virtual ~ExtraData() { }
    };

<<<<<<< HEAD
    BLINK_PLATFORM_EXPORT ~WebURLRequest();
    BLINK_PLATFORM_EXPORT WebURLRequest();
    BLINK_PLATFORM_EXPORT WebURLRequest(const WebURLRequest&);
    BLINK_PLATFORM_EXPORT explicit WebURLRequest(const WebURL&);
    BLINK_PLATFORM_EXPORT WebURLRequest& operator=(const WebURLRequest&);
=======
    ~WebURLRequest() { reset(); }

    WebURLRequest() : m_private(0) { }
    WebURLRequest(const WebURLRequest& r) : m_private(0) { assign(r); }
    WebURLRequest& operator=(const WebURLRequest& r)
    {
        assign(r);
        return *this;
    }

    explicit WebURLRequest(const WebURL& url) : m_private(0)
    {
        initialize();
        setURL(url);
    }

    BLINK_PLATFORM_EXPORT void initialize();
    BLINK_PLATFORM_EXPORT void reset();
    BLINK_PLATFORM_EXPORT void assign(const WebURLRequest&);
>>>>>>> miniblink49

    BLINK_PLATFORM_EXPORT bool isNull() const;

    BLINK_PLATFORM_EXPORT WebURL url() const;
    BLINK_PLATFORM_EXPORT void setURL(const WebURL&);

    // Used to implement third-party cookie blocking.
    BLINK_PLATFORM_EXPORT WebURL firstPartyForCookies() const;
    BLINK_PLATFORM_EXPORT void setFirstPartyForCookies(const WebURL&);

    // The origin of the execution context which originated the request. Used to
    // implement First-Party-Only cookie restrictions.
    BLINK_PLATFORM_EXPORT WebSecurityOrigin requestorOrigin() const;
    BLINK_PLATFORM_EXPORT void setRequestorOrigin(const WebSecurityOrigin&);

    // Controls whether user name, password, and cookies may be sent with the
    // request. (If false, this overrides allowCookies.)
    BLINK_PLATFORM_EXPORT bool allowStoredCredentials() const;
    BLINK_PLATFORM_EXPORT void setAllowStoredCredentials(bool);

<<<<<<< HEAD
    BLINK_PLATFORM_EXPORT WebCachePolicy getCachePolicy() const;
    BLINK_PLATFORM_EXPORT void setCachePolicy(WebCachePolicy);
=======
    BLINK_PLATFORM_EXPORT CachePolicy cachePolicy() const;
    BLINK_PLATFORM_EXPORT void setCachePolicy(CachePolicy);
>>>>>>> miniblink49

    BLINK_PLATFORM_EXPORT WebString httpMethod() const;
    BLINK_PLATFORM_EXPORT void setHTTPMethod(const WebString&);

    BLINK_PLATFORM_EXPORT WebString httpHeaderField(const WebString& name) const;
<<<<<<< HEAD
    // It's not possible to set the referrer header using this method. Use
    // setHTTPReferrer instead.
    BLINK_PLATFORM_EXPORT void setHTTPHeaderField(const WebString& name,
        const WebString& value);
    BLINK_PLATFORM_EXPORT void setHTTPReferrer(const WebString& referrer,
        WebReferrerPolicy);
    BLINK_PLATFORM_EXPORT void addHTTPHeaderField(const WebString& name,
        const WebString& value);
=======
    // It's not possible to set the referrer header using this method. Use setHTTPReferrer instead.
    BLINK_PLATFORM_EXPORT void setHTTPHeaderField(const WebString& name, const WebString& value);
    BLINK_PLATFORM_EXPORT void setHTTPReferrer(const WebString& referrer, WebReferrerPolicy);
    BLINK_PLATFORM_EXPORT void addHTTPHeaderField(const WebString& name, const WebString& value);
>>>>>>> miniblink49
    BLINK_PLATFORM_EXPORT void clearHTTPHeaderField(const WebString& name);
    BLINK_PLATFORM_EXPORT void visitHTTPHeaderFields(WebHTTPHeaderVisitor*) const;

    BLINK_PLATFORM_EXPORT WebHTTPBody httpBody() const;
    BLINK_PLATFORM_EXPORT void setHTTPBody(const WebHTTPBody&);

<<<<<<< HEAD
    BLINK_PLATFORM_EXPORT WebHTTPBody attachedCredential() const;
    BLINK_PLATFORM_EXPORT void setAttachedCredential(const WebHTTPBody&);

=======
>>>>>>> miniblink49
    // Controls whether upload progress events are generated when a request
    // has a body.
    BLINK_PLATFORM_EXPORT bool reportUploadProgress() const;
    BLINK_PLATFORM_EXPORT void setReportUploadProgress(bool);

    // Controls whether actual headers sent and received for request are
    // collected and reported.
    BLINK_PLATFORM_EXPORT bool reportRawHeaders() const;
    BLINK_PLATFORM_EXPORT void setReportRawHeaders(bool);

<<<<<<< HEAD
    BLINK_PLATFORM_EXPORT RequestContext getRequestContext() const;
    BLINK_PLATFORM_EXPORT void setRequestContext(RequestContext);

    BLINK_PLATFORM_EXPORT FrameType getFrameType() const;
    BLINK_PLATFORM_EXPORT void setFrameType(FrameType);

    BLINK_PLATFORM_EXPORT WebReferrerPolicy getReferrerPolicy() const;

    // Adds an HTTP origin header if it is empty and the HTTP method of the
    // request requires it.
    BLINK_PLATFORM_EXPORT void addHTTPOriginIfNeeded(const WebSecurityOrigin&);
=======
    BLINK_PLATFORM_EXPORT RequestContext requestContext() const;
    BLINK_PLATFORM_EXPORT void setRequestContext(RequestContext);

    BLINK_PLATFORM_EXPORT FrameType frameType() const;
    BLINK_PLATFORM_EXPORT void setFrameType(FrameType);

    BLINK_PLATFORM_EXPORT WebReferrerPolicy referrerPolicy() const;

    // Adds an HTTP origin header if it is empty and the HTTP method of the
    // request requires it.
    BLINK_PLATFORM_EXPORT void addHTTPOriginIfNeeded(const WebString& origin);
>>>>>>> miniblink49

    // True if the request was user initiated.
    BLINK_PLATFORM_EXPORT bool hasUserGesture() const;
    BLINK_PLATFORM_EXPORT void setHasUserGesture(bool);

    // A consumer controlled value intended to be used to identify the
    // requestor.
    BLINK_PLATFORM_EXPORT int requestorID() const;
    BLINK_PLATFORM_EXPORT void setRequestorID(int);

    // A consumer controlled value intended to be used to identify the
    // process of the requestor.
    BLINK_PLATFORM_EXPORT int requestorProcessID() const;
    BLINK_PLATFORM_EXPORT void setRequestorProcessID(int);

    // Allows the request to be matched up with its app cache host.
    BLINK_PLATFORM_EXPORT int appCacheHostID() const;
    BLINK_PLATFORM_EXPORT void setAppCacheHostID(int);

    // If true, the response body will be downloaded to a file managed by the
    // WebURLLoader. See WebURLResponse::downloadedFilePath.
    BLINK_PLATFORM_EXPORT bool downloadToFile() const;
    BLINK_PLATFORM_EXPORT void setDownloadToFile(bool);

    // True if the requestor wants to receive the response body as a stream.
    BLINK_PLATFORM_EXPORT bool useStreamOnResponse() const;
    BLINK_PLATFORM_EXPORT void setUseStreamOnResponse(bool);

    // True if the request should not be handled by the ServiceWorker.
<<<<<<< HEAD
    BLINK_PLATFORM_EXPORT SkipServiceWorker skipServiceWorker() const;
    BLINK_PLATFORM_EXPORT void setSkipServiceWorker(SkipServiceWorker);
=======
    BLINK_PLATFORM_EXPORT bool skipServiceWorker() const;
    BLINK_PLATFORM_EXPORT void setSkipServiceWorker(bool);
>>>>>>> miniblink49

    // True if corresponding AppCache group should be resetted.
    BLINK_PLATFORM_EXPORT bool shouldResetAppCache() const;
    BLINK_PLATFORM_EXPORT void setShouldResetAppCache(bool);

    // The request mode which will be passed to the ServiceWorker.
<<<<<<< HEAD
    BLINK_PLATFORM_EXPORT FetchRequestMode getFetchRequestMode() const;
    BLINK_PLATFORM_EXPORT void setFetchRequestMode(FetchRequestMode);

    // The credentials mode which will be passed to the ServiceWorker.
    BLINK_PLATFORM_EXPORT FetchCredentialsMode getFetchCredentialsMode() const;
    BLINK_PLATFORM_EXPORT void setFetchCredentialsMode(FetchCredentialsMode);

    // The redirect mode which is used in Fetch API.
    BLINK_PLATFORM_EXPORT FetchRedirectMode getFetchRedirectMode() const;
    BLINK_PLATFORM_EXPORT void setFetchRedirectMode(FetchRedirectMode);

    // The PreviewsState which determines whether to request a Preview version of
    // the resource. The PreviewsState is a bitmask of potentially several
    // Previews optimizations.
    BLINK_PLATFORM_EXPORT PreviewsState getPreviewsState() const;
    BLINK_PLATFORM_EXPORT void setPreviewsState(PreviewsState);

=======
    BLINK_PLATFORM_EXPORT FetchRequestMode fetchRequestMode() const;
    BLINK_PLATFORM_EXPORT void setFetchRequestMode(FetchRequestMode);

    // The credentials mode which will be passed to the ServiceWorker.
    BLINK_PLATFORM_EXPORT FetchCredentialsMode fetchCredentialsMode() const;
    BLINK_PLATFORM_EXPORT void setFetchCredentialsMode(FetchCredentialsMode);

>>>>>>> miniblink49
    // Extra data associated with the underlying resource request. Resource
    // requests can be copied. If non-null, each copy of a resource requests
    // holds a pointer to the extra data, and the extra data pointer will be
    // deleted when the last resource request is destroyed. Setting the extra
    // data pointer will cause the underlying resource request to be
    // dissociated from any existing non-null extra data pointer.
<<<<<<< HEAD
    BLINK_PLATFORM_EXPORT ExtraData* getExtraData() const;
    BLINK_PLATFORM_EXPORT void setExtraData(ExtraData*);

    BLINK_PLATFORM_EXPORT Priority getPriority() const;
=======
    BLINK_PLATFORM_EXPORT ExtraData* extraData() const;
    BLINK_PLATFORM_EXPORT void setExtraData(ExtraData*);

    BLINK_PLATFORM_EXPORT Priority priority() const;
>>>>>>> miniblink49
    BLINK_PLATFORM_EXPORT void setPriority(Priority);

    // PlzNavigate: whether the FrameLoader should try to send the request to
    // the browser (if browser-side navigations are enabled).
    // Note: WebURLRequests created by RenderFrameImpl::OnCommitNavigation must
    // not be sent to the browser.
    BLINK_PLATFORM_EXPORT bool checkForBrowserSideNavigation() const;
    BLINK_PLATFORM_EXPORT void setCheckForBrowserSideNavigation(bool);

    // This is used to report navigation metrics starting from the UI action
    // that triggered the navigation (which can be different from the navigation
    // start time used in the Navigation Timing API).
    BLINK_PLATFORM_EXPORT double uiStartTime() const;
    BLINK_PLATFORM_EXPORT void setUiStartTime(double);
<<<<<<< HEAD
    BLINK_PLATFORM_EXPORT WebURLRequest::InputToLoadPerfMetricReportPolicy
    inputPerfMetricReportPolicy() const;
    BLINK_PLATFORM_EXPORT void setInputPerfMetricReportPolicy(
        WebURLRequest::InputToLoadPerfMetricReportPolicy);

    // https://mikewest.github.io/cors-rfc1918/#external-request
    BLINK_PLATFORM_EXPORT bool isExternalRequest() const;

    BLINK_PLATFORM_EXPORT LoadingIPCType getLoadingIPCType() const;

    BLINK_PLATFORM_EXPORT void setNavigationStartTime(double);
=======
    BLINK_PLATFORM_EXPORT WebURLRequest::InputToLoadPerfMetricReportPolicy inputPerfMetricReportPolicy() const;
    BLINK_PLATFORM_EXPORT void setInputPerfMetricReportPolicy(WebURLRequest::InputToLoadPerfMetricReportPolicy);

    // Does the request originate from a SecurityContext hosted in a reserved
    // (RFC1918) IP range?
    BLINK_PLATFORM_EXPORT bool originatesFromReservedIPRange() const;
    BLINK_PLATFORM_EXPORT void setOriginatesFromReservedIPRange(bool);
>>>>>>> miniblink49

#if INSIDE_BLINK
    BLINK_PLATFORM_EXPORT ResourceRequest& toMutableResourceRequest();
    BLINK_PLATFORM_EXPORT const ResourceRequest& toResourceRequest() const;
<<<<<<< HEAD

protected:
    // Permit subclasses to set arbitrary ResourceRequest pointer as
    // |m_resourceRequest|. |m_ownedResourceRequest| is not set in this case.
    BLINK_PLATFORM_EXPORT explicit WebURLRequest(ResourceRequest&);
#endif

private:
    struct ResourceRequestContainer;

    // If this instance owns a ResourceRequest then |m_ownedResourceRequest|
    // is non-null and |m_resourceRequest| points to the ResourceRequest
    // instance it contains.
    std::unique_ptr<ResourceRequestContainer> m_ownedResourceRequest;

    // Should never be null.
    ResourceRequest* m_resourceRequest;
=======
#endif

protected:
    BLINK_PLATFORM_EXPORT void assign(WebURLRequestPrivate*);

private:
    WebURLRequestPrivate* m_private;
>>>>>>> miniblink49
};

} // namespace blink

#endif
