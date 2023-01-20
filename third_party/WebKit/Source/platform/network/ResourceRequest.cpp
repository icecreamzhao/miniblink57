/*
 * Copyright (C) 2003, 2006 Apple Computer, Inc.  All rights reserved.
 * Copyright (C) 2009, 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "platform/network/ResourceRequest.h"

#include "platform/HTTPNames.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/network/NetworkUtils.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/WebAddressSpace.h"
#include "public/platform/WebCachePolicy.h"
#include "public/platform/WebURLRequest.h"
#include "wtf/PtrUtil.h"
#include <memory>
=======
#include "config.h"
#include "platform/network/ResourceRequest.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/WebURLRequest.h"

#include "wtf/RefCountedLeakCounter.h"
>>>>>>> miniblink49

namespace blink {

double ResourceRequest::s_defaultTimeoutInterval = INT_MAX;

<<<<<<< HEAD
ResourceRequest::ResourceRequest()
    : ResourceRequest(KURL())
{
}

ResourceRequest::ResourceRequest(const String& urlString)
    : ResourceRequest(KURL(ParsedURLString, urlString))
{
}

ResourceRequest::ResourceRequest(const KURL& url)
    : m_url(url)
    , m_cachePolicy(WebCachePolicy::UseProtocolCachePolicy)
    , m_timeoutInterval(s_defaultTimeoutInterval)
    , m_requestorOrigin(SecurityOrigin::createUnique())
    , m_httpMethod(HTTPNames::GET)
    , m_allowStoredCredentials(true)
    , m_reportUploadProgress(false)
    , m_reportRawHeaders(false)
    , m_hasUserGesture(false)
    , m_downloadToFile(false)
    , m_useStreamOnResponse(false)
    , m_shouldResetAppCache(false)
    , m_skipServiceWorker(WebURLRequest::SkipServiceWorker::None)
    , m_priority(ResourceLoadPriorityLowest)
    , m_intraPriorityValue(0)
    , m_requestorID(0)
    , m_requestorProcessID(0)
    , m_appCacheHostID(0)
    , m_requestContext(WebURLRequest::RequestContextUnspecified)
    , m_frameType(WebURLRequest::FrameTypeNone)
    , m_fetchRequestMode(WebURLRequest::FetchRequestModeNoCORS)
    , m_fetchCredentialsMode(WebURLRequest::FetchCredentialsModeInclude)
    , m_fetchRedirectMode(WebURLRequest::FetchRedirectModeFollow)
    , m_previewsState(WebURLRequest::PreviewsUnspecified)
    , m_referrerPolicy(ReferrerPolicyDefault)
    , m_didSetHTTPReferrer(false)
    , m_checkForBrowserSideNavigation(true)
    , m_uiStartTime(0)
    , m_isExternalRequest(false)
    , m_inputPerfMetricReportPolicy(
          InputToLoadPerfMetricReportPolicy::NoReport)
    , m_redirectStatus(RedirectStatus::NoRedirect)
{
}

ResourceRequest::ResourceRequest(CrossThreadResourceRequestData* data)
    : ResourceRequest(data->m_url)
{
    setCachePolicy(data->m_cachePolicy);
    setTimeoutInterval(data->m_timeoutInterval);
    setFirstPartyForCookies(data->m_firstPartyForCookies);
    setRequestorOrigin(data->m_requestorOrigin);
    setHTTPMethod(AtomicString(data->m_httpMethod));
    setPriority(data->m_priority, data->m_intraPriorityValue);

    m_httpHeaderFields.adopt(std::move(data->m_httpHeaders));

    setHTTPBody(data->m_httpBody);
    setAttachedCredential(data->m_attachedCredential);
    setAllowStoredCredentials(data->m_allowStoredCredentials);
    setReportUploadProgress(data->m_reportUploadProgress);
    setHasUserGesture(data->m_hasUserGesture);
    setDownloadToFile(data->m_downloadToFile);
    setUseStreamOnResponse(data->m_useStreamOnResponse);
    setSkipServiceWorker(data->m_skipServiceWorker);
    setShouldResetAppCache(data->m_shouldResetAppCache);
    setRequestorID(data->m_requestorID);
    setRequestorProcessID(data->m_requestorProcessID);
    setAppCacheHostID(data->m_appCacheHostID);
    setRequestContext(data->m_requestContext);
    setFrameType(data->m_frameType);
    setFetchRequestMode(data->m_fetchRequestMode);
    setFetchCredentialsMode(data->m_fetchCredentialsMode);
    setFetchRedirectMode(data->m_fetchRedirectMode);
    setPreviewsState(data->m_previewsState);
    m_referrerPolicy = data->m_referrerPolicy;
    m_didSetHTTPReferrer = data->m_didSetHTTPReferrer;
    m_checkForBrowserSideNavigation = data->m_checkForBrowserSideNavigation;
    m_uiStartTime = data->m_uiStartTime;
    m_isExternalRequest = data->m_isExternalRequest;
    m_inputPerfMetricReportPolicy = data->m_inputPerfMetricReportPolicy;
    m_redirectStatus = data->m_redirectStatus;
}

ResourceRequest::ResourceRequest(const ResourceRequest&) = default;

ResourceRequest& ResourceRequest::operator=(const ResourceRequest&) = default;

std::unique_ptr<CrossThreadResourceRequestData> ResourceRequest::copyData()
    const
{
    std::unique_ptr<CrossThreadResourceRequestData> data = WTF::makeUnique<CrossThreadResourceRequestData>();
    data->m_url = url().copy();
    data->m_cachePolicy = getCachePolicy();
    data->m_timeoutInterval = timeoutInterval();
    data->m_firstPartyForCookies = firstPartyForCookies().copy();
    data->m_requestorOrigin = requestorOrigin() ? requestorOrigin()->isolatedCopy() : nullptr;
    data->m_httpMethod = httpMethod().getString().isolatedCopy();
=======
PassOwnPtr<ResourceRequest> ResourceRequest::adopt(PassOwnPtr<CrossThreadResourceRequestData> data)
{
    OwnPtr<ResourceRequest> request = adoptPtr(new ResourceRequest());
    request->setURL(data->m_url);
    request->setCachePolicy(data->m_cachePolicy);
    request->setTimeoutInterval(data->m_timeoutInterval);
    request->setFirstPartyForCookies(data->m_firstPartyForCookies);
    request->setRequestorOrigin(data->m_requestorOrigin);
    request->setHTTPMethod(AtomicString(data->m_httpMethod));
    request->setPriority(data->m_priority, data->m_intraPriorityValue);

    request->m_httpHeaderFields.adopt(data->m_httpHeaders.release());

    request->setHTTPBody(data->m_httpBody);
    request->setAllowStoredCredentials(data->m_allowStoredCredentials);
    request->setReportUploadProgress(data->m_reportUploadProgress);
    request->setHasUserGesture(data->m_hasUserGesture);
    request->setDownloadToFile(data->m_downloadToFile);
    request->setUseStreamOnResponse(data->m_useStreamOnResponse);
    request->setSkipServiceWorker(data->m_skipServiceWorker);
    request->setShouldResetAppCache(data->m_shouldResetAppCache);
    request->setRequestorID(data->m_requestorID);
    request->setRequestorProcessID(data->m_requestorProcessID);
    request->setAppCacheHostID(data->m_appCacheHostID);
    request->setRequestContext(data->m_requestContext);
    request->setFrameType(data->m_frameType);
    request->setFetchRequestMode(data->m_fetchRequestMode);
    request->setFetchCredentialsMode(data->m_fetchCredentialsMode);
    request->m_referrerPolicy = data->m_referrerPolicy;
    request->m_didSetHTTPReferrer = data->m_didSetHTTPReferrer;
    request->m_checkForBrowserSideNavigation = data->m_checkForBrowserSideNavigation;
    request->m_uiStartTime = data->m_uiStartTime;
    request->m_originatesFromReservedIPRange = data->m_originatesFromReservedIPRange;
    request->m_inputPerfMetricReportPolicy = data->m_inputPerfMetricReportPolicy;
    request->m_followedRedirect = data->m_followedRedirect;
    return request.release();
}

PassOwnPtr<CrossThreadResourceRequestData> ResourceRequest::copyData() const
{
    OwnPtr<CrossThreadResourceRequestData> data = adoptPtr(new CrossThreadResourceRequestData());
    data->m_url = url().copy();
    data->m_cachePolicy = cachePolicy();
    data->m_timeoutInterval = timeoutInterval();
    data->m_firstPartyForCookies = firstPartyForCookies().copy();
    data->m_requestorOrigin = requestorOrigin() ? requestorOrigin()->isolatedCopy() : nullptr;
    data->m_httpMethod = httpMethod().string().isolatedCopy();
>>>>>>> miniblink49
    data->m_httpHeaders = httpHeaderFields().copyData();
    data->m_priority = priority();
    data->m_intraPriorityValue = m_intraPriorityValue;

    if (m_httpBody)
        data->m_httpBody = m_httpBody->deepCopy();
<<<<<<< HEAD
    if (m_attachedCredential)
        data->m_attachedCredential = m_attachedCredential->deepCopy();
=======
>>>>>>> miniblink49
    data->m_allowStoredCredentials = m_allowStoredCredentials;
    data->m_reportUploadProgress = m_reportUploadProgress;
    data->m_hasUserGesture = m_hasUserGesture;
    data->m_downloadToFile = m_downloadToFile;
    data->m_useStreamOnResponse = m_useStreamOnResponse;
    data->m_skipServiceWorker = m_skipServiceWorker;
    data->m_shouldResetAppCache = m_shouldResetAppCache;
    data->m_requestorID = m_requestorID;
    data->m_requestorProcessID = m_requestorProcessID;
    data->m_appCacheHostID = m_appCacheHostID;
    data->m_requestContext = m_requestContext;
    data->m_frameType = m_frameType;
    data->m_fetchRequestMode = m_fetchRequestMode;
    data->m_fetchCredentialsMode = m_fetchCredentialsMode;
<<<<<<< HEAD
    data->m_fetchRedirectMode = m_fetchRedirectMode;
    data->m_previewsState = m_previewsState;
=======
>>>>>>> miniblink49
    data->m_referrerPolicy = m_referrerPolicy;
    data->m_didSetHTTPReferrer = m_didSetHTTPReferrer;
    data->m_checkForBrowserSideNavigation = m_checkForBrowserSideNavigation;
    data->m_uiStartTime = m_uiStartTime;
<<<<<<< HEAD
    data->m_isExternalRequest = m_isExternalRequest;
    data->m_inputPerfMetricReportPolicy = m_inputPerfMetricReportPolicy;
    data->m_redirectStatus = m_redirectStatus;
    return data;
=======
    data->m_originatesFromReservedIPRange = m_originatesFromReservedIPRange;
    data->m_inputPerfMetricReportPolicy = m_inputPerfMetricReportPolicy;
    data->m_followedRedirect = m_followedRedirect;
    return data.release();
>>>>>>> miniblink49
}

bool ResourceRequest::isEmpty() const
{
    return m_url.isEmpty();
}

bool ResourceRequest::isNull() const
{
    return m_url.isNull();
}

const KURL& ResourceRequest::url() const
{
    return m_url;
}

void ResourceRequest::setURL(const KURL& url)
{
    m_url = url;
}

void ResourceRequest::removeCredentials()
{
    if (m_url.user().isEmpty() && m_url.pass().isEmpty())
        return;

    m_url.setUser(String());
    m_url.setPass(String());
}

<<<<<<< HEAD
WebCachePolicy ResourceRequest::getCachePolicy() const
=======
ResourceRequestCachePolicy ResourceRequest::cachePolicy() const
>>>>>>> miniblink49
{
    return m_cachePolicy;
}

<<<<<<< HEAD
void ResourceRequest::setCachePolicy(WebCachePolicy cachePolicy)
=======
void ResourceRequest::setCachePolicy(ResourceRequestCachePolicy cachePolicy)
>>>>>>> miniblink49
{
    m_cachePolicy = cachePolicy;
}

double ResourceRequest::timeoutInterval() const
{
    return m_timeoutInterval;
}

<<<<<<< HEAD
void ResourceRequest::setTimeoutInterval(double timoutIntervalSeconds)
{
    m_timeoutInterval = timoutIntervalSeconds;
=======
void ResourceRequest::setTimeoutInterval(double timeoutInterval)
{
    m_timeoutInterval = timeoutInterval;
>>>>>>> miniblink49
}

const KURL& ResourceRequest::firstPartyForCookies() const
{
    return m_firstPartyForCookies;
}

<<<<<<< HEAD
void ResourceRequest::setFirstPartyForCookies(
    const KURL& firstPartyForCookies)
=======
void ResourceRequest::setFirstPartyForCookies(const KURL& firstPartyForCookies)
>>>>>>> miniblink49
{
    m_firstPartyForCookies = firstPartyForCookies;
}

PassRefPtr<SecurityOrigin> ResourceRequest::requestorOrigin() const
{
    return m_requestorOrigin;
}

<<<<<<< HEAD
void ResourceRequest::setRequestorOrigin(
    PassRefPtr<SecurityOrigin> requestorOrigin)
=======
void ResourceRequest::setRequestorOrigin(PassRefPtr<SecurityOrigin> requestorOrigin)
>>>>>>> miniblink49
{
    m_requestorOrigin = requestorOrigin;
}

const AtomicString& ResourceRequest::httpMethod() const
{
    return m_httpMethod;
}

void ResourceRequest::setHTTPMethod(const AtomicString& httpMethod)
{
    m_httpMethod = httpMethod;
}

const HTTPHeaderMap& ResourceRequest::httpHeaderFields() const
{
    return m_httpHeaderFields;
}

<<<<<<< HEAD
const AtomicString& ResourceRequest::httpHeaderField(
    const AtomicString& name) const
=======
const AtomicString& ResourceRequest::httpHeaderField(const AtomicString& name) const
>>>>>>> miniblink49
{
    return m_httpHeaderFields.get(name);
}

<<<<<<< HEAD
void ResourceRequest::setHTTPHeaderField(const AtomicString& name,
    const AtomicString& value)
=======
const AtomicString& ResourceRequest::httpHeaderField(const char* name) const
{
    return m_httpHeaderFields.get(name);
}

void ResourceRequest::setHTTPHeaderField(const AtomicString& name, const AtomicString& value)
>>>>>>> miniblink49
{
    m_httpHeaderFields.set(name, value);
}

<<<<<<< HEAD
void ResourceRequest::setHTTPReferrer(const Referrer& referrer)
{
    if (referrer.referrer.isEmpty())
        m_httpHeaderFields.remove(HTTPNames::Referer);
    else
        setHTTPHeaderField(HTTPNames::Referer, referrer.referrer);
=======
void ResourceRequest::setHTTPHeaderField(const char* name, const AtomicString& value)
{
    setHTTPHeaderField(AtomicString(name), value);
}

void ResourceRequest::setHTTPReferrer(const Referrer& referrer)
{
    if (referrer.referrer.isEmpty())
        m_httpHeaderFields.remove("Referer");
    else
        setHTTPHeaderField("Referer", referrer.referrer);
>>>>>>> miniblink49
    m_referrerPolicy = referrer.referrerPolicy;
    m_didSetHTTPReferrer = true;
}

void ResourceRequest::clearHTTPReferrer()
{
<<<<<<< HEAD
    m_httpHeaderFields.remove(HTTPNames::Referer);
=======
    m_httpHeaderFields.remove("Referer");
>>>>>>> miniblink49
    m_referrerPolicy = ReferrerPolicyDefault;
    m_didSetHTTPReferrer = false;
}

<<<<<<< HEAD
void ResourceRequest::setHTTPOrigin(const SecurityOrigin* origin)
{
    setHTTPHeaderField(HTTPNames::Origin, origin->toAtomicString());
    if (origin->hasSuborigin()) {
        setHTTPHeaderField(HTTPNames::Suborigin,
            AtomicString(origin->suborigin()->name()));
    }
}

void ResourceRequest::clearHTTPOrigin()
{
    m_httpHeaderFields.remove(HTTPNames::Origin);
    m_httpHeaderFields.remove(HTTPNames::Suborigin);
}

void ResourceRequest::addHTTPOriginIfNeeded(const SecurityOrigin* origin)
{
    if (needsHTTPOrigin())
        setHTTPOrigin(origin);
}

void ResourceRequest::addHTTPOriginIfNeeded(const String& originString)
{
    if (needsHTTPOrigin())
        setHTTPOrigin(SecurityOrigin::createFromString(originString).get());
=======
void ResourceRequest::clearHTTPOrigin()
{
    m_httpHeaderFields.remove("Origin");
}

void ResourceRequest::addHTTPOriginIfNeeded(const AtomicString& origin)
{
    if (!httpOrigin().isEmpty())
        return; // Request already has an Origin header.

    // Don't send an Origin header for GET or HEAD to avoid privacy issues.
    // For example, if an intranet page has a hyperlink to an external web
    // site, we don't want to include the Origin of the request because it
    // will leak the internal host name. Similar privacy concerns have lead
    // to the widespread suppression of the Referer header at the network
    // layer.
    if (httpMethod() == "GET" || httpMethod() == "HEAD")
        return;

    // For non-GET and non-HEAD methods, always send an Origin header so the
    // server knows we support this feature.

    if (origin.isEmpty()) {
        // If we don't know what origin header to attach, we attach the value
        // for an empty origin.
        setHTTPOrigin(SecurityOrigin::createUnique()->toAtomicString());
        return;
    }
    setHTTPOrigin(origin);
>>>>>>> miniblink49
}

void ResourceRequest::clearHTTPUserAgent()
{
<<<<<<< HEAD
    m_httpHeaderFields.remove(HTTPNames::User_Agent);
}

EncodedFormData* ResourceRequest::httpBody() const
=======
    m_httpHeaderFields.remove("User-Agent");
}

FormData* ResourceRequest::httpBody() const
>>>>>>> miniblink49
{
    return m_httpBody.get();
}

<<<<<<< HEAD
void ResourceRequest::setHTTPBody(PassRefPtr<EncodedFormData> httpBody)
=======
void ResourceRequest::setHTTPBody(PassRefPtr<FormData> httpBody)
>>>>>>> miniblink49
{
    m_httpBody = httpBody;
}

<<<<<<< HEAD
EncodedFormData* ResourceRequest::attachedCredential() const
{
    return m_attachedCredential.get();
}

void ResourceRequest::setAttachedCredential(
    PassRefPtr<EncodedFormData> attachedCredential)
{
    m_attachedCredential = attachedCredential;
}

=======
>>>>>>> miniblink49
bool ResourceRequest::allowStoredCredentials() const
{
    return m_allowStoredCredentials;
}

void ResourceRequest::setAllowStoredCredentials(bool allowCredentials)
{
    m_allowStoredCredentials = allowCredentials;
}

ResourceLoadPriority ResourceRequest::priority() const
{
    return m_priority;
}

<<<<<<< HEAD
void ResourceRequest::setPriority(ResourceLoadPriority priority,
    int intraPriorityValue)
=======
void ResourceRequest::setPriority(ResourceLoadPriority priority, int intraPriorityValue)
>>>>>>> miniblink49
{
    m_priority = priority;
    m_intraPriorityValue = intraPriorityValue;
}

<<<<<<< HEAD
void ResourceRequest::addHTTPHeaderField(const AtomicString& name,
    const AtomicString& value)
=======
void ResourceRequest::addHTTPHeaderField(const AtomicString& name, const AtomicString& value)
>>>>>>> miniblink49
{
    HTTPHeaderMap::AddResult result = m_httpHeaderFields.add(name, value);
    if (!result.isNewEntry)
        result.storedValue->value = result.storedValue->value + ',' + value;
}

void ResourceRequest::addHTTPHeaderFields(const HTTPHeaderMap& headerFields)
{
    HTTPHeaderMap::const_iterator end = headerFields.end();
    for (HTTPHeaderMap::const_iterator it = headerFields.begin(); it != end; ++it)
        addHTTPHeaderField(it->key, it->value);
}

void ResourceRequest::clearHTTPHeaderField(const AtomicString& name)
{
    m_httpHeaderFields.remove(name);
}

<<<<<<< HEAD
void ResourceRequest::setExternalRequestStateFromRequestorAddressSpace(
    WebAddressSpace requestorSpace)
{
    static_assert(WebAddressSpaceLocal < WebAddressSpacePrivate,
        "Local is inside Private");
    static_assert(WebAddressSpaceLocal < WebAddressSpacePublic,
        "Local is inside Public");
    static_assert(WebAddressSpacePrivate < WebAddressSpacePublic,
        "Private is inside Public");

    // TODO(mkwst): This only checks explicit IP addresses. We'll have to move all
    // this up to //net and //content in order to have any real impact on gateway
    // attacks. That turns out to be a TON of work. https://crbug.com/378566
    if (!RuntimeEnabledFeatures::corsRFC1918Enabled()) {
        m_isExternalRequest = false;
        return;
    }

    WebAddressSpace targetSpace = WebAddressSpacePublic;
    if (NetworkUtils::isReservedIPAddress(m_url.host()))
        targetSpace = WebAddressSpacePrivate;
    if (SecurityOrigin::create(m_url)->isLocalhost())
        targetSpace = WebAddressSpaceLocal;

    m_isExternalRequest = requestorSpace > targetSpace;
}

void ResourceRequest::setNavigationStartTime(double navigationStart)
{
    m_navigationStart = navigationStart;
=======
bool equalIgnoringHeaderFields(const ResourceRequest& a, const ResourceRequest& b)
{
    if (a.url() != b.url())
        return false;

    if (a.cachePolicy() != b.cachePolicy())
        return false;

    if (a.timeoutInterval() != b.timeoutInterval())
        return false;

    if (a.firstPartyForCookies() != b.firstPartyForCookies())
        return false;

    if (a.httpMethod() != b.httpMethod())
        return false;

    if (a.allowStoredCredentials() != b.allowStoredCredentials())
        return false;

    if (a.priority() != b.priority())
        return false;

    if (a.referrerPolicy() != b.referrerPolicy())
        return false;

    FormData* formDataA = a.httpBody();
    FormData* formDataB = b.httpBody();

    if (!formDataA)
        return !formDataB;
    if (!formDataB)
        return !formDataA;

    if (*formDataA != *formDataB)
        return false;

    return true;
}

bool ResourceRequest::compare(const ResourceRequest& a, const ResourceRequest& b)
{
    if (!equalIgnoringHeaderFields(a, b))
        return false;

    if (a.httpHeaderFields() != b.httpHeaderFields())
        return false;

    return true;
>>>>>>> miniblink49
}

bool ResourceRequest::isConditional() const
{
<<<<<<< HEAD
    return (m_httpHeaderFields.contains(HTTPNames::If_Match) || m_httpHeaderFields.contains(HTTPNames::If_Modified_Since) || m_httpHeaderFields.contains(HTTPNames::If_None_Match) || m_httpHeaderFields.contains(HTTPNames::If_Range) || m_httpHeaderFields.contains(HTTPNames::If_Unmodified_Since));
=======
    return (m_httpHeaderFields.contains("If-Match")
        || m_httpHeaderFields.contains("If-Modified-Since")
        || m_httpHeaderFields.contains("If-None-Match")
        || m_httpHeaderFields.contains("If-Range")
        || m_httpHeaderFields.contains("If-Unmodified-Since"));
>>>>>>> miniblink49
}

void ResourceRequest::setHasUserGesture(bool hasUserGesture)
{
    m_hasUserGesture |= hasUserGesture;
}

<<<<<<< HEAD
const CacheControlHeader& ResourceRequest::cacheControlHeader() const
{
    if (!m_cacheControlHeaderCache.parsed)
        m_cacheControlHeaderCache = parseCacheControlDirectives(
            m_httpHeaderFields.get(HTTPNames::Cache_Control),
            m_httpHeaderFields.get(HTTPNames::Pragma));
=======
static const AtomicString& cacheControlHeaderString()
{
    DEFINE_STATIC_LOCAL(const AtomicString, cacheControlHeader, ("cache-control", AtomicString::ConstructFromLiteral));
    return cacheControlHeader;
}

static const AtomicString& pragmaHeaderString()
{
    DEFINE_STATIC_LOCAL(const AtomicString, pragmaHeader, ("pragma", AtomicString::ConstructFromLiteral));
    return pragmaHeader;
}

const CacheControlHeader& ResourceRequest::cacheControlHeader() const
{
    if (!m_cacheControlHeaderCache.parsed)
        m_cacheControlHeaderCache = parseCacheControlDirectives(m_httpHeaderFields.get(cacheControlHeaderString()), m_httpHeaderFields.get(pragmaHeaderString()));
>>>>>>> miniblink49
    return m_cacheControlHeaderCache;
}

bool ResourceRequest::cacheControlContainsNoCache() const
{
    return cacheControlHeader().containsNoCache;
}

bool ResourceRequest::cacheControlContainsNoStore() const
{
    return cacheControlHeader().containsNoStore;
}

bool ResourceRequest::hasCacheValidatorFields() const
{
<<<<<<< HEAD
    return !m_httpHeaderFields.get(HTTPNames::Last_Modified).isEmpty() || !m_httpHeaderFields.get(HTTPNames::ETag).isEmpty();
}

bool ResourceRequest::needsHTTPOrigin() const
{
    if (!httpOrigin().isEmpty())
        return false; // Request already has an Origin header.

    // Don't send an Origin header for GET or HEAD to avoid privacy issues.
    // For example, if an intranet page has a hyperlink to an external web
    // site, we don't want to include the Origin of the request because it
    // will leak the internal host name. Similar privacy concerns have lead
    // to the widespread suppression of the Referer header at the network
    // layer.
    if (httpMethod() == HTTPNames::GET || httpMethod() == HTTPNames::HEAD)
        return false;

    // For non-GET and non-HEAD methods, always send an Origin header so the
    // server knows we support this feature.
    return true;
=======
    DEFINE_STATIC_LOCAL(const AtomicString, lastModifiedHeader, ("last-modified", AtomicString::ConstructFromLiteral));
    DEFINE_STATIC_LOCAL(const AtomicString, eTagHeader, ("etag", AtomicString::ConstructFromLiteral));
    return !m_httpHeaderFields.get(lastModifiedHeader).isEmpty() || !m_httpHeaderFields.get(eTagHeader).isEmpty();
}

#ifndef NDEBUG
DEFINE_DEBUG_ONLY_GLOBAL(WTF::RefCountedLeakCounter, resourceRequestExtraDataCounter, ("ResourceRequestExtraData"));
#endif

ResourceRequest::ExtraData::ExtraData()
{
#ifndef NDEBUG
    resourceRequestExtraDataCounter.increment();
#endif
}

ResourceRequest::ExtraData::~ExtraData()
{
#ifndef NDEBUG
    resourceRequestExtraDataCounter.decrement();
#endif
}

void ResourceRequest::initialize(const KURL& url)
{
    m_url = url;
    m_cachePolicy = UseProtocolCachePolicy;
    m_timeoutInterval = s_defaultTimeoutInterval;
    m_httpMethod = "GET";
    m_allowStoredCredentials = true;
    m_reportUploadProgress = false;
    m_reportRawHeaders = false;
    m_hasUserGesture = false;
    m_downloadToFile = false;
    m_useStreamOnResponse = false;
    m_skipServiceWorker = false;
    m_shouldResetAppCache = false;
    m_priority = ResourceLoadPriorityLowest;
    m_intraPriorityValue = 0;
    m_requestorID = 0;
    m_requestorProcessID = 0;
    m_appCacheHostID = 0;
    m_requestContext = WebURLRequest::RequestContextUnspecified;
    m_frameType = WebURLRequest::FrameTypeNone;
    m_fetchRequestMode = WebURLRequest::FetchRequestModeNoCORS;
    // Contrary to the Fetch spec, we default to same-origin mode here, and deal
    // with CORS modes in updateRequestForAccessControl if we're called in a
    // context which requires it.
    m_fetchCredentialsMode = WebURLRequest::FetchCredentialsModeSameOrigin;
    m_referrerPolicy = ReferrerPolicyDefault;
    m_didSetHTTPReferrer = false;
    m_checkForBrowserSideNavigation = true;
    m_uiStartTime = 0;
    m_originatesFromReservedIPRange = false;
    m_inputPerfMetricReportPolicy = InputToLoadPerfMetricReportPolicy::NoReport;
    m_followedRedirect = false;
>>>>>>> miniblink49
}

} // namespace blink
