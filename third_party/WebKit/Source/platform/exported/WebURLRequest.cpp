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

<<<<<<< HEAD
#include "public/platform/WebURLRequest.h"

#include "platform/RuntimeEnabledFeatures.h"
#include "platform/network/ResourceRequest.h"
#include "public/platform/WebCachePolicy.h"
=======
#include "config.h"
#include "public/platform/WebURLRequest.h"

#include "platform/exported/WebURLRequestPrivate.h"
#include "platform/network/ResourceRequest.h"
>>>>>>> miniblink49
#include "public/platform/WebHTTPBody.h"
#include "public/platform/WebHTTPHeaderVisitor.h"
#include "public/platform/WebSecurityOrigin.h"
#include "public/platform/WebURL.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
#include "wtf/Noncopyable.h"
#include "wtf/PtrUtil.h"
#include <memory>
=======
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    class ExtraDataContainer : public ResourceRequest::ExtraData {
    public:
        static PassRefPtr<ExtraDataContainer> create(
            WebURLRequest::ExtraData* extraData)
        {
            return adoptRef(new ExtraDataContainer(extraData));
        }

        ~ExtraDataContainer() override { }

        WebURLRequest::ExtraData* getExtraData() const { return m_extraData.get(); }

    private:
        explicit ExtraDataContainer(WebURLRequest::ExtraData* extraData)
            : m_extraData(WTF::wrapUnique(extraData))
        {
        }

        std::unique_ptr<WebURLRequest::ExtraData> m_extraData;
    };

} // namespace

// The purpose of this struct is to permit allocating a ResourceRequest on the
// heap, which is otherwise disallowed by DISALLOW_NEW_EXCEPT_PLACEMENT_NEW
// annotation on ResourceRequest.
struct WebURLRequest::ResourceRequestContainer {
    ResourceRequestContainer() { }
    explicit ResourceRequestContainer(const ResourceRequest& r)
        : resourceRequest(r)
    {
    }

    ResourceRequest resourceRequest;
};

WebURLRequest::~WebURLRequest() { }

WebURLRequest::WebURLRequest()
    : m_ownedResourceRequest(new ResourceRequestContainer())
    , m_resourceRequest(&m_ownedResourceRequest->resourceRequest)
{
}

WebURLRequest::WebURLRequest(const WebURLRequest& r)
    : m_ownedResourceRequest(
        new ResourceRequestContainer(*r.m_resourceRequest))
    , m_resourceRequest(&m_ownedResourceRequest->resourceRequest)
{
}

WebURLRequest::WebURLRequest(const WebURL& url)
    : WebURLRequest()
{
    setURL(url);
}

WebURLRequest& WebURLRequest::operator=(const WebURLRequest& r)
{
    // Copying subclasses that have different m_resourceRequest ownership
    // semantics via this operator is just not supported.
    DCHECK(m_ownedResourceRequest);
    DCHECK(m_resourceRequest);
    if (&r != this)
        *m_resourceRequest = *r.m_resourceRequest;
    return *this;
=======
class ExtraDataContainer : public ResourceRequest::ExtraData {
public:
    static PassRefPtr<ExtraDataContainer> create(WebURLRequest::ExtraData* extraData) { return adoptRef(new ExtraDataContainer(extraData)); }

    ~ExtraDataContainer() override {}

    WebURLRequest::ExtraData* extraData() const { return m_extraData.get(); }

private:
    explicit ExtraDataContainer(WebURLRequest::ExtraData* extraData)
        : m_extraData(adoptPtr(extraData))
    {
    }

    OwnPtr<WebURLRequest::ExtraData> m_extraData;
};

} // namespace

// The standard implementation of WebURLRequestPrivate, which maintains
// ownership of a ResourceRequest instance.
class WebURLRequestPrivateImpl : public WebURLRequestPrivate {
public:
    WebURLRequestPrivateImpl()
    {
        m_resourceRequest = &m_resourceRequestAllocation;
    }

    WebURLRequestPrivateImpl(const WebURLRequestPrivate* p)
        : m_resourceRequestAllocation(*p->m_resourceRequest)
    {
        m_resourceRequest = &m_resourceRequestAllocation;
    }

    virtual void dispose() { delete this; }

private:
    virtual ~WebURLRequestPrivateImpl() { }

    ResourceRequest m_resourceRequestAllocation;
};

void WebURLRequest::initialize()
{
    assign(new WebURLRequestPrivateImpl());
}

void WebURLRequest::reset()
{
    assign(0);
}

void WebURLRequest::assign(const WebURLRequest& r)
{
    if (&r != this)
        assign(r.m_private ? new WebURLRequestPrivateImpl(r.m_private) : 0);
>>>>>>> miniblink49
}

bool WebURLRequest::isNull() const
{
<<<<<<< HEAD
    return m_resourceRequest->isNull();
=======
    return !m_private || m_private->m_resourceRequest->isNull();
>>>>>>> miniblink49
}

WebURL WebURLRequest::url() const
{
<<<<<<< HEAD
    return m_resourceRequest->url();
=======
    return m_private->m_resourceRequest->url();
>>>>>>> miniblink49
}

void WebURLRequest::setURL(const WebURL& url)
{
<<<<<<< HEAD
    m_resourceRequest->setURL(url);
=======
    m_private->m_resourceRequest->setURL(url);
>>>>>>> miniblink49
}

WebURL WebURLRequest::firstPartyForCookies() const
{
<<<<<<< HEAD
    return m_resourceRequest->firstPartyForCookies();
}

void WebURLRequest::setFirstPartyForCookies(
    const WebURL& firstPartyForCookies)
{
    m_resourceRequest->setFirstPartyForCookies(firstPartyForCookies);
=======
    return m_private->m_resourceRequest->firstPartyForCookies();
}

void WebURLRequest::setFirstPartyForCookies(const WebURL& firstPartyForCookies)
{
    m_private->m_resourceRequest->setFirstPartyForCookies(firstPartyForCookies);
>>>>>>> miniblink49
}

WebSecurityOrigin WebURLRequest::requestorOrigin() const
{
<<<<<<< HEAD
    return m_resourceRequest->requestorOrigin();
}

void WebURLRequest::setRequestorOrigin(
    const WebSecurityOrigin& requestorOrigin)
{
    m_resourceRequest->setRequestorOrigin(requestorOrigin);
=======
    return m_private->m_resourceRequest->requestorOrigin();
}

void WebURLRequest::setRequestorOrigin(const WebSecurityOrigin& requestorOrigin)
{
    m_private->m_resourceRequest->setRequestorOrigin(requestorOrigin);
>>>>>>> miniblink49
}

bool WebURLRequest::allowStoredCredentials() const
{
<<<<<<< HEAD
    return m_resourceRequest->allowStoredCredentials();
=======
    return m_private->m_resourceRequest->allowStoredCredentials();
>>>>>>> miniblink49
}

void WebURLRequest::setAllowStoredCredentials(bool allowStoredCredentials)
{
<<<<<<< HEAD
    m_resourceRequest->setAllowStoredCredentials(allowStoredCredentials);
}

WebCachePolicy WebURLRequest::getCachePolicy() const
{
    return m_resourceRequest->getCachePolicy();
}

void WebURLRequest::setCachePolicy(WebCachePolicy cachePolicy)
{
    m_resourceRequest->setCachePolicy(cachePolicy);
=======
    m_private->m_resourceRequest->setAllowStoredCredentials(allowStoredCredentials);
}

WebURLRequest::CachePolicy WebURLRequest::cachePolicy() const
{
    return static_cast<WebURLRequest::CachePolicy>(
        m_private->m_resourceRequest->cachePolicy());
}

void WebURLRequest::setCachePolicy(CachePolicy cachePolicy)
{
    m_private->m_resourceRequest->setCachePolicy(
        static_cast<ResourceRequestCachePolicy>(cachePolicy));
>>>>>>> miniblink49
}

WebString WebURLRequest::httpMethod() const
{
<<<<<<< HEAD
    return m_resourceRequest->httpMethod();
=======
    return m_private->m_resourceRequest->httpMethod();
>>>>>>> miniblink49
}

void WebURLRequest::setHTTPMethod(const WebString& httpMethod)
{
<<<<<<< HEAD
    m_resourceRequest->setHTTPMethod(httpMethod);
=======
    m_private->m_resourceRequest->setHTTPMethod(httpMethod);
>>>>>>> miniblink49
}

WebString WebURLRequest::httpHeaderField(const WebString& name) const
{
<<<<<<< HEAD
    return m_resourceRequest->httpHeaderField(name);
}

void WebURLRequest::setHTTPHeaderField(const WebString& name,
    const WebString& value)
{
    RELEASE_ASSERT(!equalIgnoringCase(name, "referer"));
    m_resourceRequest->setHTTPHeaderField(name, value);
}

void WebURLRequest::setHTTPReferrer(const WebString& webReferrer,
    WebReferrerPolicy referrerPolicy)
{
    // WebString doesn't have the distinction between empty and null. We use
    // the null WTFString for referrer.
    ASSERT(Referrer::noReferrer() == String());
    String referrer = webReferrer.isEmpty() ? Referrer::noReferrer() : String(webReferrer);
    m_resourceRequest->setHTTPReferrer(
        Referrer(referrer, static_cast<ReferrerPolicy>(referrerPolicy)));
}

void WebURLRequest::addHTTPHeaderField(const WebString& name,
    const WebString& value)
{
    m_resourceRequest->addHTTPHeaderField(name, value);
=======
    return m_private->m_resourceRequest->httpHeaderField(name);
}

void WebURLRequest::setHTTPHeaderField(const WebString& name, const WebString& value)
{
    RELEASE_ASSERT(!equalIgnoringCase((WTF::String)name, "referer"));
    m_private->m_resourceRequest->setHTTPHeaderField(name, value);
}

void WebURLRequest::setHTTPReferrer(const WebString& referrer, WebReferrerPolicy referrerPolicy)
{
    m_private->m_resourceRequest->setHTTPReferrer(Referrer(referrer, static_cast<ReferrerPolicy>(referrerPolicy)));
}

void WebURLRequest::addHTTPHeaderField(const WebString& name, const WebString& value)
{
    m_private->m_resourceRequest->addHTTPHeaderField(name, value);
>>>>>>> miniblink49
}

void WebURLRequest::clearHTTPHeaderField(const WebString& name)
{
<<<<<<< HEAD
    m_resourceRequest->clearHTTPHeaderField(name);
=======
    m_private->m_resourceRequest->clearHTTPHeaderField(name);
>>>>>>> miniblink49
}

void WebURLRequest::visitHTTPHeaderFields(WebHTTPHeaderVisitor* visitor) const
{
<<<<<<< HEAD
    const HTTPHeaderMap& map = m_resourceRequest->httpHeaderFields();
=======
    const HTTPHeaderMap& map = m_private->m_resourceRequest->httpHeaderFields();
>>>>>>> miniblink49
    for (HTTPHeaderMap::const_iterator it = map.begin(); it != map.end(); ++it)
        visitor->visitHeader(it->key, it->value);
}

WebHTTPBody WebURLRequest::httpBody() const
{
<<<<<<< HEAD
    // TODO(mkwst): This is wrong, as it means that we're producing the body
    // before any ServiceWorker has a chance to operate, which means we're
    // revealing data to the SW that we ought to be hiding. Baby steps.
    // https://crbug.com/599597
    if (m_resourceRequest->attachedCredential())
        return WebHTTPBody(m_resourceRequest->attachedCredential());
    return WebHTTPBody(m_resourceRequest->httpBody());
=======
    return WebHTTPBody(m_private->m_resourceRequest->httpBody());
>>>>>>> miniblink49
}

void WebURLRequest::setHTTPBody(const WebHTTPBody& httpBody)
{
<<<<<<< HEAD
    m_resourceRequest->setHTTPBody(httpBody);
}

WebHTTPBody WebURLRequest::attachedCredential() const
{
    return WebHTTPBody(m_resourceRequest->attachedCredential());
}

void WebURLRequest::setAttachedCredential(
    const WebHTTPBody& attachedCredential)
{
    m_resourceRequest->setAttachedCredential(attachedCredential);
=======
    m_private->m_resourceRequest->setHTTPBody(httpBody);
>>>>>>> miniblink49
}

bool WebURLRequest::reportUploadProgress() const
{
<<<<<<< HEAD
    return m_resourceRequest->reportUploadProgress();
=======
    return m_private->m_resourceRequest->reportUploadProgress();
>>>>>>> miniblink49
}

void WebURLRequest::setReportUploadProgress(bool reportUploadProgress)
{
<<<<<<< HEAD
    m_resourceRequest->setReportUploadProgress(reportUploadProgress);
=======
    m_private->m_resourceRequest->setReportUploadProgress(reportUploadProgress);
>>>>>>> miniblink49
}

void WebURLRequest::setReportRawHeaders(bool reportRawHeaders)
{
<<<<<<< HEAD
    m_resourceRequest->setReportRawHeaders(reportRawHeaders);
=======
    m_private->m_resourceRequest->setReportRawHeaders(reportRawHeaders);
>>>>>>> miniblink49
}

bool WebURLRequest::reportRawHeaders() const
{
<<<<<<< HEAD
    return m_resourceRequest->reportRawHeaders();
}

WebURLRequest::RequestContext WebURLRequest::getRequestContext() const
{
    return m_resourceRequest->requestContext();
}

WebURLRequest::FrameType WebURLRequest::getFrameType() const
{
    return m_resourceRequest->frameType();
}

WebReferrerPolicy WebURLRequest::getReferrerPolicy() const
{
    return static_cast<WebReferrerPolicy>(m_resourceRequest->getReferrerPolicy());
}

void WebURLRequest::addHTTPOriginIfNeeded(const WebSecurityOrigin& origin)
{
    m_resourceRequest->addHTTPOriginIfNeeded(origin.get());
=======
    return m_private->m_resourceRequest->reportRawHeaders();
}

WebURLRequest::RequestContext WebURLRequest::requestContext() const
{
    return m_private->m_resourceRequest->requestContext();
}

WebURLRequest::FrameType WebURLRequest::frameType() const
{
    return m_private->m_resourceRequest->frameType();
}

WebReferrerPolicy WebURLRequest::referrerPolicy() const
{
    return static_cast<WebReferrerPolicy>(m_private->m_resourceRequest->referrerPolicy());
}

void WebURLRequest::addHTTPOriginIfNeeded(const WebString& origin)
{
    m_private->m_resourceRequest->addHTTPOriginIfNeeded(origin);
>>>>>>> miniblink49
}

bool WebURLRequest::hasUserGesture() const
{
<<<<<<< HEAD
    return m_resourceRequest->hasUserGesture();
=======
    return m_private->m_resourceRequest->hasUserGesture();
>>>>>>> miniblink49
}

void WebURLRequest::setHasUserGesture(bool hasUserGesture)
{
<<<<<<< HEAD
    m_resourceRequest->setHasUserGesture(hasUserGesture);
=======
    m_private->m_resourceRequest->setHasUserGesture(hasUserGesture);
>>>>>>> miniblink49
}

void WebURLRequest::setRequestContext(RequestContext requestContext)
{
<<<<<<< HEAD
    m_resourceRequest->setRequestContext(requestContext);
=======
    m_private->m_resourceRequest->setRequestContext(requestContext);
>>>>>>> miniblink49
}

void WebURLRequest::setFrameType(FrameType frameType)
{
<<<<<<< HEAD
    m_resourceRequest->setFrameType(frameType);
=======
    m_private->m_resourceRequest->setFrameType(frameType);
>>>>>>> miniblink49
}

int WebURLRequest::requestorID() const
{
<<<<<<< HEAD
    return m_resourceRequest->requestorID();
=======
    return m_private->m_resourceRequest->requestorID();
>>>>>>> miniblink49
}

void WebURLRequest::setRequestorID(int requestorID)
{
<<<<<<< HEAD
    m_resourceRequest->setRequestorID(requestorID);
=======
    m_private->m_resourceRequest->setRequestorID(requestorID);
>>>>>>> miniblink49
}

int WebURLRequest::requestorProcessID() const
{
<<<<<<< HEAD
    return m_resourceRequest->requestorProcessID();
=======
    return m_private->m_resourceRequest->requestorProcessID();
>>>>>>> miniblink49
}

void WebURLRequest::setRequestorProcessID(int requestorProcessID)
{
<<<<<<< HEAD
    m_resourceRequest->setRequestorProcessID(requestorProcessID);
=======
    m_private->m_resourceRequest->setRequestorProcessID(requestorProcessID);
>>>>>>> miniblink49
}

int WebURLRequest::appCacheHostID() const
{
<<<<<<< HEAD
    return m_resourceRequest->appCacheHostID();
=======
    return m_private->m_resourceRequest->appCacheHostID();
>>>>>>> miniblink49
}

void WebURLRequest::setAppCacheHostID(int appCacheHostID)
{
<<<<<<< HEAD
    m_resourceRequest->setAppCacheHostID(appCacheHostID);
=======
    m_private->m_resourceRequest->setAppCacheHostID(appCacheHostID);
>>>>>>> miniblink49
}

bool WebURLRequest::downloadToFile() const
{
<<<<<<< HEAD
    return m_resourceRequest->downloadToFile();
=======
    return m_private->m_resourceRequest->downloadToFile();
>>>>>>> miniblink49
}

void WebURLRequest::setDownloadToFile(bool downloadToFile)
{
<<<<<<< HEAD
    m_resourceRequest->setDownloadToFile(downloadToFile);
=======
    m_private->m_resourceRequest->setDownloadToFile(downloadToFile);
>>>>>>> miniblink49
}

bool WebURLRequest::useStreamOnResponse() const
{
<<<<<<< HEAD
    return m_resourceRequest->useStreamOnResponse();
=======
    return m_private->m_resourceRequest->useStreamOnResponse();
>>>>>>> miniblink49
}

void WebURLRequest::setUseStreamOnResponse(bool useStreamOnResponse)
{
<<<<<<< HEAD
    m_resourceRequest->setUseStreamOnResponse(useStreamOnResponse);
}

WebURLRequest::SkipServiceWorker WebURLRequest::skipServiceWorker() const
{
    return m_resourceRequest->skipServiceWorker();
}

void WebURLRequest::setSkipServiceWorker(
    WebURLRequest::SkipServiceWorker skipServiceWorker)
{
    m_resourceRequest->setSkipServiceWorker(skipServiceWorker);
=======
    m_private->m_resourceRequest->setUseStreamOnResponse(useStreamOnResponse);
}

bool WebURLRequest::skipServiceWorker() const
{
    return m_private->m_resourceRequest->skipServiceWorker();
}

void WebURLRequest::setSkipServiceWorker(bool skipServiceWorker)
{
    m_private->m_resourceRequest->setSkipServiceWorker(skipServiceWorker);
>>>>>>> miniblink49
}

bool WebURLRequest::shouldResetAppCache() const
{
<<<<<<< HEAD
    return m_resourceRequest->shouldResetAppCache();
=======
    return m_private->m_resourceRequest->shouldResetAppCache();
>>>>>>> miniblink49
}

void WebURLRequest::setShouldResetAppCache(bool setShouldResetAppCache)
{
<<<<<<< HEAD
    m_resourceRequest->setShouldResetAppCache(setShouldResetAppCache);
}

WebURLRequest::FetchRequestMode WebURLRequest::getFetchRequestMode() const
{
    return m_resourceRequest->fetchRequestMode();
=======
    m_private->m_resourceRequest->setShouldResetAppCache(setShouldResetAppCache);
}

WebURLRequest::FetchRequestMode WebURLRequest::fetchRequestMode() const
{
    return m_private->m_resourceRequest->fetchRequestMode();
>>>>>>> miniblink49
}

void WebURLRequest::setFetchRequestMode(WebURLRequest::FetchRequestMode mode)
{
<<<<<<< HEAD
    return m_resourceRequest->setFetchRequestMode(mode);
}

WebURLRequest::FetchCredentialsMode WebURLRequest::getFetchCredentialsMode()
    const
{
    return m_resourceRequest->fetchCredentialsMode();
}

void WebURLRequest::setFetchCredentialsMode(
    WebURLRequest::FetchCredentialsMode mode)
{
    return m_resourceRequest->setFetchCredentialsMode(mode);
}

WebURLRequest::FetchRedirectMode WebURLRequest::getFetchRedirectMode() const
{
    return m_resourceRequest->fetchRedirectMode();
}

void WebURLRequest::setFetchRedirectMode(
    WebURLRequest::FetchRedirectMode redirect)
{
    return m_resourceRequest->setFetchRedirectMode(redirect);
}

WebURLRequest::PreviewsState WebURLRequest::getPreviewsState() const
{
    return m_resourceRequest->previewsState();
}

void WebURLRequest::setPreviewsState(
    WebURLRequest::PreviewsState previewsState)
{
    return m_resourceRequest->setPreviewsState(previewsState);
}

WebURLRequest::ExtraData* WebURLRequest::getExtraData() const
{
    RefPtr<ResourceRequest::ExtraData> data = m_resourceRequest->getExtraData();
    if (!data)
        return 0;
    return static_cast<ExtraDataContainer*>(data.get())->getExtraData();
=======
    return m_private->m_resourceRequest->setFetchRequestMode(mode);
}

WebURLRequest::FetchCredentialsMode WebURLRequest::fetchCredentialsMode() const
{
    return m_private->m_resourceRequest->fetchCredentialsMode();
}

void WebURLRequest::setFetchCredentialsMode(WebURLRequest::FetchCredentialsMode mode)
{
    return m_private->m_resourceRequest->setFetchCredentialsMode(mode);
}

WebURLRequest::ExtraData* WebURLRequest::extraData() const
{
    RefPtr<ResourceRequest::ExtraData> data = m_private->m_resourceRequest->extraData();
    if (!data)
        return 0;
    return static_cast<ExtraDataContainer*>(data.get())->extraData();
>>>>>>> miniblink49
}

void WebURLRequest::setExtraData(WebURLRequest::ExtraData* extraData)
{
<<<<<<< HEAD
    m_resourceRequest->setExtraData(ExtraDataContainer::create(extraData));
=======
    m_private->m_resourceRequest->setExtraData(ExtraDataContainer::create(extraData));
>>>>>>> miniblink49
}

ResourceRequest& WebURLRequest::toMutableResourceRequest()
{
<<<<<<< HEAD
    DCHECK(m_resourceRequest);
    return *m_resourceRequest;
}

WebURLRequest::Priority WebURLRequest::getPriority() const
{
    return static_cast<WebURLRequest::Priority>(m_resourceRequest->priority());
=======
    ASSERT(m_private);
    ASSERT(m_private->m_resourceRequest);

    return *m_private->m_resourceRequest;
}

WebURLRequest::Priority WebURLRequest::priority() const
{
    return static_cast<WebURLRequest::Priority>(
        m_private->m_resourceRequest->priority());
>>>>>>> miniblink49
}

void WebURLRequest::setPriority(WebURLRequest::Priority priority)
{
<<<<<<< HEAD
    m_resourceRequest->setPriority(static_cast<ResourceLoadPriority>(priority));
=======
    m_private->m_resourceRequest->setPriority(
        static_cast<ResourceLoadPriority>(priority));
>>>>>>> miniblink49
}

bool WebURLRequest::checkForBrowserSideNavigation() const
{
<<<<<<< HEAD
    return m_resourceRequest->checkForBrowserSideNavigation();
=======
    return m_private->m_resourceRequest->checkForBrowserSideNavigation();
>>>>>>> miniblink49
}

void WebURLRequest::setCheckForBrowserSideNavigation(bool check)
{
<<<<<<< HEAD
    m_resourceRequest->setCheckForBrowserSideNavigation(check);
=======
    m_private->m_resourceRequest->setCheckForBrowserSideNavigation(check);
>>>>>>> miniblink49
}

double WebURLRequest::uiStartTime() const
{
<<<<<<< HEAD
    return m_resourceRequest->uiStartTime();
}

void WebURLRequest::setUiStartTime(double timeSeconds)
{
    m_resourceRequest->setUIStartTime(timeSeconds);
}

bool WebURLRequest::isExternalRequest() const
{
    return m_resourceRequest->isExternalRequest();
}

WebURLRequest::LoadingIPCType WebURLRequest::getLoadingIPCType() const
{
    if (RuntimeEnabledFeatures::loadingWithMojoEnabled())
        return WebURLRequest::LoadingIPCType::Mojo;
    return WebURLRequest::LoadingIPCType::ChromeIPC;
}

void WebURLRequest::setNavigationStartTime(double navigationStartSeconds)
{
    m_resourceRequest->setNavigationStartTime(navigationStartSeconds);
}

WebURLRequest::InputToLoadPerfMetricReportPolicy
WebURLRequest::inputPerfMetricReportPolicy() const
{
    return static_cast<WebURLRequest::InputToLoadPerfMetricReportPolicy>(
        m_resourceRequest->inputPerfMetricReportPolicy());
=======
    return m_private->m_resourceRequest->uiStartTime();
}

void WebURLRequest::setUiStartTime(double time)
{
    m_private->m_resourceRequest->setUIStartTime(time);
}

bool WebURLRequest::originatesFromReservedIPRange() const
{
    return m_private->m_resourceRequest->originatesFromReservedIPRange();
}

void WebURLRequest::setOriginatesFromReservedIPRange(bool value)
{
    m_private->m_resourceRequest->setOriginatesFromReservedIPRange(value);
}

WebURLRequest::InputToLoadPerfMetricReportPolicy WebURLRequest::inputPerfMetricReportPolicy() const
{
    return static_cast<WebURLRequest::InputToLoadPerfMetricReportPolicy>(
        m_private->m_resourceRequest->inputPerfMetricReportPolicy());
>>>>>>> miniblink49
}

void WebURLRequest::setInputPerfMetricReportPolicy(
    WebURLRequest::InputToLoadPerfMetricReportPolicy policy)
{
<<<<<<< HEAD
    m_resourceRequest->setInputPerfMetricReportPolicy(
=======
    m_private->m_resourceRequest->setInputPerfMetricReportPolicy(
>>>>>>> miniblink49
        static_cast<blink::InputToLoadPerfMetricReportPolicy>(policy));
}

const ResourceRequest& WebURLRequest::toResourceRequest() const
{
<<<<<<< HEAD
    DCHECK(m_resourceRequest);
    return *m_resourceRequest;
}

WebURLRequest::WebURLRequest(ResourceRequest& r)
    : m_resourceRequest(&r)
{
=======
    ASSERT(m_private);
    ASSERT(m_private->m_resourceRequest);

    return *m_private->m_resourceRequest;
}

void WebURLRequest::assign(WebURLRequestPrivate* p)
{
    // Subclasses may call this directly so a self-assignment check is needed
    // here as well as in the public assign method.
    if (m_private == p)
        return;
    if (m_private)
        m_private->dispose();
    m_private = p;
>>>>>>> miniblink49
}

} // namespace blink
