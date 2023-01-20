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
#include "public/platform/WebURLResponse.h"

=======
#include "config.h"
#include "public/platform/WebURLResponse.h"

#include "platform/exported/WebURLResponsePrivate.h"
>>>>>>> miniblink49
#include "platform/network/ResourceLoadTiming.h"
#include "platform/network/ResourceResponse.h"
#include "public/platform/WebHTTPHeaderVisitor.h"
#include "public/platform/WebHTTPLoadInfo.h"
#include "public/platform/WebString.h"
#include "public/platform/WebURL.h"
#include "public/platform/WebURLLoadTiming.h"
<<<<<<< HEAD
#include "wtf/Allocator.h"
#include "wtf/Assertions.h"
#include "wtf/PtrUtil.h"
#include "wtf/RefPtr.h"
#include <memory>
=======
#include "wtf/RefPtr.h"
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    class ExtraDataContainer : public ResourceResponse::ExtraData {
    public:
        static PassRefPtr<ExtraDataContainer> create(
            WebURLResponse::ExtraData* extraData)
        {
            return adoptRef(new ExtraDataContainer(extraData));
        }

        ~ExtraDataContainer() override { }

        WebURLResponse::ExtraData* getExtraData() const { return m_extraData.get(); }

    private:
        explicit ExtraDataContainer(WebURLResponse::ExtraData* extraData)
            : m_extraData(WTF::wrapUnique(extraData))
        {
        }

        std::unique_ptr<WebURLResponse::ExtraData> m_extraData;
    };

} // namespace

// The purpose of this struct is to permit allocating a ResourceResponse on the
// heap, which is otherwise disallowed by the DISALLOW_NEW_EXCEPT_PLACEMENT_NEW
// annotation on ResourceResponse.
struct WebURLResponse::ResourceResponseContainer {
    ResourceResponseContainer() { }

    explicit ResourceResponseContainer(const ResourceResponse& r)
        : resourceResponse(r)
    {
    }

    ResourceResponse resourceResponse;
};

WebURLResponse::~WebURLResponse() { }

WebURLResponse::WebURLResponse()
    : m_ownedResourceResponse(new ResourceResponseContainer())
    , m_resourceResponse(&m_ownedResourceResponse->resourceResponse)
{
}

WebURLResponse::WebURLResponse(const WebURLResponse& r)
    : m_ownedResourceResponse(
        new ResourceResponseContainer(*r.m_resourceResponse))
    , m_resourceResponse(&m_ownedResourceResponse->resourceResponse)
{
}

WebURLResponse::WebURLResponse(const WebURL& url)
    : WebURLResponse()
{
    setURL(url);
}

WebURLResponse& WebURLResponse::operator=(const WebURLResponse& r)
{
    // Copying subclasses that have different m_resourceResponse ownership
    // semantics via this operator is just not supported.
    DCHECK(m_ownedResourceResponse);
    DCHECK(m_resourceResponse);
    if (&r != this)
        *m_resourceResponse = *r.m_resourceResponse;
    return *this;
=======
class ExtraDataContainer : public ResourceResponse::ExtraData {
public:
    static PassRefPtr<ExtraDataContainer> create(WebURLResponse::ExtraData* extraData) { return adoptRef(new ExtraDataContainer(extraData)); }

    ~ExtraDataContainer() override {}

    WebURLResponse::ExtraData* extraData() const { return m_extraData.get(); }

private:
    explicit ExtraDataContainer(WebURLResponse::ExtraData* extraData)
        : m_extraData(adoptPtr(extraData))
    {
    }

    OwnPtr<WebURLResponse::ExtraData> m_extraData;
};

} // namespace

// The standard implementation of WebURLResponsePrivate, which maintains
// ownership of a ResourceResponse instance.
class WebURLResponsePrivateImpl : public WebURLResponsePrivate {
public:
    WebURLResponsePrivateImpl()
    {
        m_resourceResponse = &m_resourceResponseAllocation;
    }

    WebURLResponsePrivateImpl(const WebURLResponsePrivate* p)
        : m_resourceResponseAllocation(*p->m_resourceResponse)
    {
        m_resourceResponse = &m_resourceResponseAllocation;
    }

    virtual void dispose() { delete this; }

private:
    virtual ~WebURLResponsePrivateImpl() { }

    ResourceResponse m_resourceResponseAllocation;
};

void WebURLResponse::initialize()
{
    assign(new WebURLResponsePrivateImpl());
}

void WebURLResponse::reset()
{
    assign(0);
}

void WebURLResponse::assign(const WebURLResponse& r)
{
    if (&r != this)
        assign(r.m_private ? new WebURLResponsePrivateImpl(r.m_private) : 0);
>>>>>>> miniblink49
}

bool WebURLResponse::isNull() const
{
<<<<<<< HEAD
    return m_resourceResponse->isNull();
=======
    return !m_private || m_private->m_resourceResponse->isNull();
>>>>>>> miniblink49
}

WebURL WebURLResponse::url() const
{
<<<<<<< HEAD
    return m_resourceResponse->url();
=======
    return m_private->m_resourceResponse->url();
>>>>>>> miniblink49
}

void WebURLResponse::setURL(const WebURL& url)
{
<<<<<<< HEAD
    m_resourceResponse->setURL(url);
=======
    m_private->m_resourceResponse->setURL(url);
>>>>>>> miniblink49
}

unsigned WebURLResponse::connectionID() const
{
<<<<<<< HEAD
    return m_resourceResponse->connectionID();
=======
    return m_private->m_resourceResponse->connectionID();
>>>>>>> miniblink49
}

void WebURLResponse::setConnectionID(unsigned connectionID)
{
<<<<<<< HEAD
    m_resourceResponse->setConnectionID(connectionID);
=======
    m_private->m_resourceResponse->setConnectionID(connectionID);
>>>>>>> miniblink49
}

bool WebURLResponse::connectionReused() const
{
<<<<<<< HEAD
    return m_resourceResponse->connectionReused();
=======
    return m_private->m_resourceResponse->connectionReused();
>>>>>>> miniblink49
}

void WebURLResponse::setConnectionReused(bool connectionReused)
{
<<<<<<< HEAD
    m_resourceResponse->setConnectionReused(connectionReused);
=======
    m_private->m_resourceResponse->setConnectionReused(connectionReused);
>>>>>>> miniblink49
}

WebURLLoadTiming WebURLResponse::loadTiming()
{
<<<<<<< HEAD
    return WebURLLoadTiming(m_resourceResponse->resourceLoadTiming());
=======
    return WebURLLoadTiming(m_private->m_resourceResponse->resourceLoadTiming());
>>>>>>> miniblink49
}

void WebURLResponse::setLoadTiming(const WebURLLoadTiming& timing)
{
    RefPtr<ResourceLoadTiming> loadTiming = PassRefPtr<ResourceLoadTiming>(timing);
<<<<<<< HEAD
    m_resourceResponse->setResourceLoadTiming(std::move(loadTiming));
=======
    m_private->m_resourceResponse->setResourceLoadTiming(loadTiming.release());
>>>>>>> miniblink49
}

WebHTTPLoadInfo WebURLResponse::httpLoadInfo()
{
<<<<<<< HEAD
    return WebHTTPLoadInfo(m_resourceResponse->resourceLoadInfo());
=======
    return WebHTTPLoadInfo(m_private->m_resourceResponse->resourceLoadInfo());
>>>>>>> miniblink49
}

void WebURLResponse::setHTTPLoadInfo(const WebHTTPLoadInfo& value)
{
<<<<<<< HEAD
    m_resourceResponse->setResourceLoadInfo(value);
=======
    m_private->m_resourceResponse->setResourceLoadInfo(value);
>>>>>>> miniblink49
}

void WebURLResponse::setResponseTime(long long responseTime)
{
<<<<<<< HEAD
    m_resourceResponse->setResponseTime(static_cast<int64_t>(responseTime));
=======
    m_private->m_resourceResponse->setResponseTime(static_cast<int64>(responseTime));
>>>>>>> miniblink49
}

WebString WebURLResponse::mimeType() const
{
<<<<<<< HEAD
    return m_resourceResponse->mimeType();
=======
    return m_private->m_resourceResponse->mimeType();
>>>>>>> miniblink49
}

void WebURLResponse::setMIMEType(const WebString& mimeType)
{
<<<<<<< HEAD
    m_resourceResponse->setMimeType(mimeType);
=======
    m_private->m_resourceResponse->setMimeType(mimeType);
>>>>>>> miniblink49
}

long long WebURLResponse::expectedContentLength() const
{
<<<<<<< HEAD
    return m_resourceResponse->expectedContentLength();
=======
    return m_private->m_resourceResponse->expectedContentLength();
>>>>>>> miniblink49
}

void WebURLResponse::setExpectedContentLength(long long expectedContentLength)
{
<<<<<<< HEAD
    m_resourceResponse->setExpectedContentLength(expectedContentLength);
=======
    m_private->m_resourceResponse->setExpectedContentLength(expectedContentLength);
>>>>>>> miniblink49
}

WebString WebURLResponse::textEncodingName() const
{
<<<<<<< HEAD
    return m_resourceResponse->textEncodingName();
=======
    return m_private->m_resourceResponse->textEncodingName();
>>>>>>> miniblink49
}

void WebURLResponse::setTextEncodingName(const WebString& textEncodingName)
{
<<<<<<< HEAD
    m_resourceResponse->setTextEncodingName(textEncodingName);
=======
    m_private->m_resourceResponse->setTextEncodingName(textEncodingName);
>>>>>>> miniblink49
}

WebString WebURLResponse::suggestedFileName() const
{
<<<<<<< HEAD
    return m_resourceResponse->suggestedFilename();
=======
    return m_private->m_resourceResponse->suggestedFilename();
>>>>>>> miniblink49
}

void WebURLResponse::setSuggestedFileName(const WebString& suggestedFileName)
{
<<<<<<< HEAD
    m_resourceResponse->setSuggestedFilename(suggestedFileName);
=======
    m_private->m_resourceResponse->setSuggestedFilename(suggestedFileName);
>>>>>>> miniblink49
}

WebURLResponse::HTTPVersion WebURLResponse::httpVersion() const
{
<<<<<<< HEAD
    return static_cast<HTTPVersion>(m_resourceResponse->httpVersion());
=======
    return static_cast<HTTPVersion>(m_private->m_resourceResponse->httpVersion());
>>>>>>> miniblink49
}

void WebURLResponse::setHTTPVersion(HTTPVersion version)
{
<<<<<<< HEAD
    m_resourceResponse->setHTTPVersion(
        static_cast<ResourceResponse::HTTPVersion>(version));
=======
    m_private->m_resourceResponse->setHTTPVersion(static_cast<ResourceResponse::HTTPVersion>(version));
>>>>>>> miniblink49
}

int WebURLResponse::httpStatusCode() const
{
<<<<<<< HEAD
    return m_resourceResponse->httpStatusCode();
=======
    return m_private->m_resourceResponse->httpStatusCode();
>>>>>>> miniblink49
}

void WebURLResponse::setHTTPStatusCode(int httpStatusCode)
{
<<<<<<< HEAD
    m_resourceResponse->setHTTPStatusCode(httpStatusCode);
=======
    m_private->m_resourceResponse->setHTTPStatusCode(httpStatusCode);
>>>>>>> miniblink49
}

WebString WebURLResponse::httpStatusText() const
{
<<<<<<< HEAD
    return m_resourceResponse->httpStatusText();
=======
    return m_private->m_resourceResponse->httpStatusText();
>>>>>>> miniblink49
}

void WebURLResponse::setHTTPStatusText(const WebString& httpStatusText)
{
<<<<<<< HEAD
    m_resourceResponse->setHTTPStatusText(httpStatusText);
=======
    m_private->m_resourceResponse->setHTTPStatusText(httpStatusText);
>>>>>>> miniblink49
}

WebString WebURLResponse::httpHeaderField(const WebString& name) const
{
<<<<<<< HEAD
    return m_resourceResponse->httpHeaderField(name);
}

void WebURLResponse::setHTTPHeaderField(const WebString& name,
    const WebString& value)
{
    m_resourceResponse->setHTTPHeaderField(name, value);
}

void WebURLResponse::addHTTPHeaderField(const WebString& name,
    const WebString& value)
=======
    return m_private->m_resourceResponse->httpHeaderField(name);
}

void WebURLResponse::setHTTPHeaderField(const WebString& name, const WebString& value)
{
    m_private->m_resourceResponse->setHTTPHeaderField(name, value);
}

void WebURLResponse::addHTTPHeaderField(const WebString& name, const WebString& value)
>>>>>>> miniblink49
{
    if (name.isNull() || value.isNull())
        return;

<<<<<<< HEAD
    m_resourceResponse->addHTTPHeaderField(name, value);
=======
    m_private->m_resourceResponse->addHTTPHeaderField(name, value);
>>>>>>> miniblink49
}

void WebURLResponse::clearHTTPHeaderField(const WebString& name)
{
<<<<<<< HEAD
    m_resourceResponse->clearHTTPHeaderField(name);
}

void WebURLResponse::visitHTTPHeaderFields(
    WebHTTPHeaderVisitor* visitor) const
{
    const HTTPHeaderMap& map = m_resourceResponse->httpHeaderFields();
=======
    m_private->m_resourceResponse->clearHTTPHeaderField(name);
}

void WebURLResponse::visitHTTPHeaderFields(WebHTTPHeaderVisitor* visitor) const
{
    const HTTPHeaderMap& map = m_private->m_resourceResponse->httpHeaderFields();
>>>>>>> miniblink49
    for (HTTPHeaderMap::const_iterator it = map.begin(); it != map.end(); ++it)
        visitor->visitHeader(it->key, it->value);
}

double WebURLResponse::lastModifiedDate() const
{
<<<<<<< HEAD
    return static_cast<double>(m_resourceResponse->lastModifiedDate());
=======
    return static_cast<double>(m_private->m_resourceResponse->lastModifiedDate());
>>>>>>> miniblink49
}

void WebURLResponse::setLastModifiedDate(double lastModifiedDate)
{
<<<<<<< HEAD
    m_resourceResponse->setLastModifiedDate(
        static_cast<time_t>(lastModifiedDate));
=======
    m_private->m_resourceResponse->setLastModifiedDate(static_cast<time_t>(lastModifiedDate));
>>>>>>> miniblink49
}

long long WebURLResponse::appCacheID() const
{
<<<<<<< HEAD
    return m_resourceResponse->appCacheID();
=======
    return m_private->m_resourceResponse->appCacheID();
>>>>>>> miniblink49
}

void WebURLResponse::setAppCacheID(long long appCacheID)
{
<<<<<<< HEAD
    m_resourceResponse->setAppCacheID(appCacheID);
=======
    m_private->m_resourceResponse->setAppCacheID(appCacheID);
>>>>>>> miniblink49
}

WebURL WebURLResponse::appCacheManifestURL() const
{
<<<<<<< HEAD
    return m_resourceResponse->appCacheManifestURL();
=======
    return m_private->m_resourceResponse->appCacheManifestURL();
>>>>>>> miniblink49
}

void WebURLResponse::setAppCacheManifestURL(const WebURL& url)
{
<<<<<<< HEAD
    m_resourceResponse->setAppCacheManifestURL(url);
}

void WebURLResponse::setHasMajorCertificateErrors(bool value)
{
    m_resourceResponse->setHasMajorCertificateErrors(value);
}

WebSecurityStyle WebURLResponse::getSecurityStyle() const
{
    return static_cast<WebSecurityStyle>(m_resourceResponse->getSecurityStyle());
}

void WebURLResponse::setSecurityStyle(WebSecurityStyle securityStyle)
{
    m_resourceResponse->setSecurityStyle(
        static_cast<ResourceResponse::SecurityStyle>(securityStyle));
}

void WebURLResponse::setSecurityDetails(
    const WebSecurityDetails& webSecurityDetails)
{
    ResourceResponse::SignedCertificateTimestampList sctList;
    for (const auto& iter : webSecurityDetails.sctList) {
        sctList.push_back(
            static_cast<ResourceResponse::SignedCertificateTimestamp>(iter));
    }
    Vector<String> sanList;
    sanList.append(webSecurityDetails.sanList.data(),
        webSecurityDetails.sanList.size());
    Vector<AtomicString> certificate;
    for (const auto& iter : webSecurityDetails.certificate) {
        AtomicString cert = iter;
        certificate.push_back(cert);
    }
    m_resourceResponse->setSecurityDetails(
        webSecurityDetails.protocol, webSecurityDetails.keyExchange,
        webSecurityDetails.keyExchangeGroup, webSecurityDetails.cipher,
        webSecurityDetails.mac, webSecurityDetails.subjectName, sanList,
        webSecurityDetails.issuer,
        static_cast<time_t>(webSecurityDetails.validFrom),
        static_cast<time_t>(webSecurityDetails.validTo), certificate, sctList);
=======
    m_private->m_resourceResponse->setAppCacheManifestURL(url);
}

WebCString WebURLResponse::securityInfo() const
{
    // FIXME: getSecurityInfo is misnamed.
    return m_private->m_resourceResponse->getSecurityInfo();
}

void WebURLResponse::setSecurityInfo(const WebCString& securityInfo)
{
    m_private->m_resourceResponse->setSecurityInfo(securityInfo);
>>>>>>> miniblink49
}

ResourceResponse& WebURLResponse::toMutableResourceResponse()
{
<<<<<<< HEAD
    return *m_resourceResponse;
=======
    ASSERT(m_private);
    ASSERT(m_private->m_resourceResponse);

    return *m_private->m_resourceResponse;
>>>>>>> miniblink49
}

const ResourceResponse& WebURLResponse::toResourceResponse() const
{
<<<<<<< HEAD
    return *m_resourceResponse;
=======
    ASSERT(m_private);
    ASSERT(m_private->m_resourceResponse);

    return *m_private->m_resourceResponse;
>>>>>>> miniblink49
}

bool WebURLResponse::wasCached() const
{
<<<<<<< HEAD
    return m_resourceResponse->wasCached();
=======
    return m_private->m_resourceResponse->wasCached();
>>>>>>> miniblink49
}

void WebURLResponse::setWasCached(bool value)
{
<<<<<<< HEAD
    m_resourceResponse->setWasCached(value);
=======
    m_private->m_resourceResponse->setWasCached(value);
>>>>>>> miniblink49
}

bool WebURLResponse::wasFetchedViaSPDY() const
{
<<<<<<< HEAD
    return m_resourceResponse->wasFetchedViaSPDY();
=======
    return m_private->m_resourceResponse->wasFetchedViaSPDY();
>>>>>>> miniblink49
}

void WebURLResponse::setWasFetchedViaSPDY(bool value)
{
<<<<<<< HEAD
    m_resourceResponse->setWasFetchedViaSPDY(value);
=======
    m_private->m_resourceResponse->setWasFetchedViaSPDY(value);
>>>>>>> miniblink49
}

bool WebURLResponse::wasNpnNegotiated() const
{
<<<<<<< HEAD
    return m_resourceResponse->wasNpnNegotiated();
=======
    return m_private->m_resourceResponse->wasNpnNegotiated();
>>>>>>> miniblink49
}

void WebURLResponse::setWasNpnNegotiated(bool value)
{
<<<<<<< HEAD
    m_resourceResponse->setWasNpnNegotiated(value);
=======
    m_private->m_resourceResponse->setWasNpnNegotiated(value);
>>>>>>> miniblink49
}

bool WebURLResponse::wasAlternateProtocolAvailable() const
{
<<<<<<< HEAD
    return m_resourceResponse->wasAlternateProtocolAvailable();
=======
    return m_private->m_resourceResponse->wasAlternateProtocolAvailable();
>>>>>>> miniblink49
}

void WebURLResponse::setWasAlternateProtocolAvailable(bool value)
{
<<<<<<< HEAD
    m_resourceResponse->setWasAlternateProtocolAvailable(value);
=======
    m_private->m_resourceResponse->setWasAlternateProtocolAvailable(value);
}

bool WebURLResponse::wasFetchedViaProxy() const
{
    return m_private->m_resourceResponse->wasFetchedViaProxy();
}

void WebURLResponse::setWasFetchedViaProxy(bool value)
{
    m_private->m_resourceResponse->setWasFetchedViaProxy(value);
>>>>>>> miniblink49
}

bool WebURLResponse::wasFetchedViaServiceWorker() const
{
<<<<<<< HEAD
    return m_resourceResponse->wasFetchedViaServiceWorker();
=======
    return m_private->m_resourceResponse->wasFetchedViaServiceWorker();
>>>>>>> miniblink49
}

void WebURLResponse::setWasFetchedViaServiceWorker(bool value)
{
<<<<<<< HEAD
    m_resourceResponse->setWasFetchedViaServiceWorker(value);
}

bool WebURLResponse::wasFetchedViaForeignFetch() const
{
    return m_resourceResponse->wasFetchedViaForeignFetch();
}

void WebURLResponse::setWasFetchedViaForeignFetch(bool value)
{
    m_resourceResponse->setWasFetchedViaForeignFetch(value);
=======
    m_private->m_resourceResponse->setWasFetchedViaServiceWorker(value);
>>>>>>> miniblink49
}

bool WebURLResponse::wasFallbackRequiredByServiceWorker() const
{
<<<<<<< HEAD
    return m_resourceResponse->wasFallbackRequiredByServiceWorker();
=======
    return m_private->m_resourceResponse->wasFallbackRequiredByServiceWorker();
>>>>>>> miniblink49
}

void WebURLResponse::setWasFallbackRequiredByServiceWorker(bool value)
{
<<<<<<< HEAD
    m_resourceResponse->setWasFallbackRequiredByServiceWorker(value);
=======
    m_private->m_resourceResponse->setWasFallbackRequiredByServiceWorker(value);
>>>>>>> miniblink49
}

WebServiceWorkerResponseType WebURLResponse::serviceWorkerResponseType() const
{
<<<<<<< HEAD
    return m_resourceResponse->serviceWorkerResponseType();
}

void WebURLResponse::setServiceWorkerResponseType(
    WebServiceWorkerResponseType value)
{
    m_resourceResponse->setServiceWorkerResponseType(value);
}

void WebURLResponse::setURLListViaServiceWorker(
    const WebVector<WebURL>& urlListViaServiceWorker)
{
    Vector<KURL> urlList(urlListViaServiceWorker.size());
    std::transform(urlListViaServiceWorker.begin(), urlListViaServiceWorker.end(),
        urlList.begin(), [](const WebURL& url) { return url; });
    m_resourceResponse->setURLListViaServiceWorker(urlList);
=======
    return m_private->m_resourceResponse->serviceWorkerResponseType();
}

void WebURLResponse::setServiceWorkerResponseType(WebServiceWorkerResponseType value)
{
    m_private->m_resourceResponse->setServiceWorkerResponseType(value);
>>>>>>> miniblink49
}

WebURL WebURLResponse::originalURLViaServiceWorker() const
{
<<<<<<< HEAD
    return m_resourceResponse->originalURLViaServiceWorker();
}

void WebURLResponse::setMultipartBoundary(const char* bytes, size_t size)
{
    m_resourceResponse->setMultipartBoundary(bytes, size);
}

WebString WebURLResponse::cacheStorageCacheName() const
{
    return m_resourceResponse->cacheStorageCacheName();
}

void WebURLResponse::setCacheStorageCacheName(
    const WebString& cacheStorageCacheName)
{
    m_resourceResponse->setCacheStorageCacheName(cacheStorageCacheName);
}

void WebURLResponse::setCorsExposedHeaderNames(
    const WebVector<WebString>& headerNames)
{
    Vector<String> exposedHeaderNames;
    exposedHeaderNames.append(headerNames.data(), headerNames.size());
    m_resourceResponse->setCorsExposedHeaderNames(exposedHeaderNames);
}

bool WebURLResponse::didServiceWorkerNavigationPreload() const
{
    return m_resourceResponse->didServiceWorkerNavigationPreload();
}

void WebURLResponse::setDidServiceWorkerNavigationPreload(bool value)
{
    m_resourceResponse->setDidServiceWorkerNavigationPreload(value);
=======
    return m_private->m_resourceResponse->originalURLViaServiceWorker();
}

void WebURLResponse::setOriginalURLViaServiceWorker(const WebURL& url)
{
    m_private->m_resourceResponse->setOriginalURLViaServiceWorker(url);
}

bool WebURLResponse::isMultipartPayload() const
{
    return m_private->m_resourceResponse->isMultipartPayload();
}

void WebURLResponse::setIsMultipartPayload(bool value)
{
    m_private->m_resourceResponse->setIsMultipartPayload(value);
>>>>>>> miniblink49
}

WebString WebURLResponse::downloadFilePath() const
{
<<<<<<< HEAD
    return m_resourceResponse->downloadedFilePath();
=======
    return m_private->m_resourceResponse->downloadedFilePath();
>>>>>>> miniblink49
}

void WebURLResponse::setDownloadFilePath(const WebString& downloadFilePath)
{
<<<<<<< HEAD
    m_resourceResponse->setDownloadedFilePath(downloadFilePath);
=======
    m_private->m_resourceResponse->setDownloadedFilePath(downloadFilePath);
>>>>>>> miniblink49
}

WebString WebURLResponse::remoteIPAddress() const
{
<<<<<<< HEAD
    return m_resourceResponse->remoteIPAddress();
=======
    return m_private->m_resourceResponse->remoteIPAddress();
>>>>>>> miniblink49
}

void WebURLResponse::setRemoteIPAddress(const WebString& remoteIPAddress)
{
<<<<<<< HEAD
    m_resourceResponse->setRemoteIPAddress(remoteIPAddress);
=======
    m_private->m_resourceResponse->setRemoteIPAddress(remoteIPAddress);
>>>>>>> miniblink49
}

unsigned short WebURLResponse::remotePort() const
{
<<<<<<< HEAD
    return m_resourceResponse->remotePort();
=======
    return m_private->m_resourceResponse->remotePort();
>>>>>>> miniblink49
}

void WebURLResponse::setRemotePort(unsigned short remotePort)
{
<<<<<<< HEAD
    m_resourceResponse->setRemotePort(remotePort);
}

long long WebURLResponse::encodedDataLengthForTesting() const
{
    return m_resourceResponse->encodedDataLength();
}

void WebURLResponse::setEncodedDataLength(long long length)
{
    m_resourceResponse->setEncodedDataLength(length);
}

long long WebURLResponse::encodedBodyLengthForTesting() const
{
    return m_resourceResponse->encodedBodyLength();
}

void WebURLResponse::addToEncodedBodyLength(long long length)
{
    m_resourceResponse->addToEncodedBodyLength(length);
}

long long WebURLResponse::decodedBodyLengthForTesting() const
{
    return m_resourceResponse->decodedBodyLength();
}

void WebURLResponse::addToDecodedBodyLength(long long bytes)
{
    m_resourceResponse->addToDecodedBodyLength(bytes);
}

WebURLResponse::ExtraData* WebURLResponse::getExtraData() const
{
    RefPtr<ResourceResponse::ExtraData> data = m_resourceResponse->getExtraData();
    if (!data)
        return 0;
    return static_cast<ExtraDataContainer*>(data.get())->getExtraData();
=======
    m_private->m_resourceResponse->setRemotePort(remotePort);
}

WebURLResponse::ExtraData* WebURLResponse::extraData() const
{
    RefPtr<ResourceResponse::ExtraData> data = m_private->m_resourceResponse->extraData();
    if (!data)
        return 0;
    return static_cast<ExtraDataContainer*>(data.get())->extraData();
>>>>>>> miniblink49
}

void WebURLResponse::setExtraData(WebURLResponse::ExtraData* extraData)
{
<<<<<<< HEAD
    m_resourceResponse->setExtraData(ExtraDataContainer::create(extraData));
}

void WebURLResponse::appendRedirectResponse(const WebURLResponse& response)
{
    m_resourceResponse->appendRedirectResponse(response.toResourceResponse());
}

WebURLResponse::WebURLResponse(ResourceResponse& r)
    : m_resourceResponse(&r)
{
=======
    m_private->m_resourceResponse->setExtraData(ExtraDataContainer::create(extraData));
}

void WebURLResponse::assign(WebURLResponsePrivate* p)
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
