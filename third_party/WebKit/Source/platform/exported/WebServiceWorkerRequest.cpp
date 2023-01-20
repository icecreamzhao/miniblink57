// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "public/platform/modules/serviceworker/WebServiceWorkerRequest.h"
=======
#include "config.h"
#include "public/platform/WebServiceWorkerRequest.h"
>>>>>>> miniblink49

#include "platform/blob/BlobData.h"
#include "platform/weborigin/KURL.h"
#include "public/platform/WebHTTPHeaderVisitor.h"
<<<<<<< HEAD
#include "public/platform/WebString.h"
#include "public/platform/WebURLRequest.h"
#include "wtf/RefCounted.h"

namespace blink {

class WebServiceWorkerRequestPrivate
    : public RefCounted<WebServiceWorkerRequestPrivate> {
public:
    WebServiceWorkerRequestPrivate()
        : m_mode(WebURLRequest::FetchRequestModeNoCORS)
        , m_isMainResourceLoad(false)
        , m_credentialsMode(WebURLRequest::FetchCredentialsModeOmit)
        , m_redirectMode(WebURLRequest::FetchRedirectModeFollow)
        , m_requestContext(WebURLRequest::RequestContextUnspecified)
        , m_frameType(WebURLRequest::FrameTypeNone)
        , m_clientId(WebString())
=======
#include "public/platform/WebURLRequest.h"

namespace blink {

class WebServiceWorkerRequestPrivate : public RefCounted<WebServiceWorkerRequestPrivate> {
public:
    WebServiceWorkerRequestPrivate()
        : m_mode(WebURLRequest::FetchRequestModeNoCORS)
        , m_credentialsMode(WebURLRequest::FetchCredentialsModeOmit)
        , m_requestContext(WebURLRequest::RequestContextUnspecified)
        , m_frameType(WebURLRequest::FrameTypeNone)
>>>>>>> miniblink49
        , m_isReload(false)
    {
    }
    WebURL m_url;
    WebString m_method;
    HTTPHeaderMap m_headers;
    RefPtr<BlobDataHandle> blobDataHandle;
    Referrer m_referrer;
    WebURLRequest::FetchRequestMode m_mode;
<<<<<<< HEAD
    bool m_isMainResourceLoad;
    WebURLRequest::FetchCredentialsMode m_credentialsMode;
    WebURLRequest::FetchRedirectMode m_redirectMode;
    WebURLRequest::RequestContext m_requestContext;
    WebURLRequest::FrameType m_frameType;
    WebString m_clientId;
=======
    WebURLRequest::FetchCredentialsMode m_credentialsMode;
    WebURLRequest::RequestContext m_requestContext;
    WebURLRequest::FrameType m_frameType;
>>>>>>> miniblink49
    bool m_isReload;
};

WebServiceWorkerRequest::WebServiceWorkerRequest()
    : m_private(adoptRef(new WebServiceWorkerRequestPrivate))
{
}

void WebServiceWorkerRequest::reset()
{
    m_private.reset();
}

void WebServiceWorkerRequest::assign(const WebServiceWorkerRequest& other)
{
    m_private = other.m_private;
}

void WebServiceWorkerRequest::setURL(const WebURL& url)
{
    m_private->m_url = url;
}

WebURL WebServiceWorkerRequest::url() const
{
    return m_private->m_url;
}

void WebServiceWorkerRequest::setMethod(const WebString& method)
{
    m_private->m_method = method;
}

WebString WebServiceWorkerRequest::method() const
{
    return m_private->m_method;
}

<<<<<<< HEAD
void WebServiceWorkerRequest::setHeader(const WebString& key,
    const WebString& value)
{
    if (equalIgnoringCase(key, "referer"))
=======
void WebServiceWorkerRequest::setHeader(const WebString& key, const WebString& value)
{
    if (equalIgnoringCase((String)key, "referer"))
>>>>>>> miniblink49
        return;
    m_private->m_headers.set(key, value);
}

<<<<<<< HEAD
void WebServiceWorkerRequest::appendHeader(const WebString& key,
    const WebString& value)
{
    if (equalIgnoringCase(key, "referer"))
=======
void WebServiceWorkerRequest::appendHeader(const WebString& key, const WebString& value)
{
    if (equalIgnoringCase((String)key, "referer"))
>>>>>>> miniblink49
        return;
    HTTPHeaderMap::AddResult result = m_private->m_headers.add(key, value);
    if (!result.isNewEntry)
        result.storedValue->value = result.storedValue->value + ", " + String(value);
}

<<<<<<< HEAD
void WebServiceWorkerRequest::visitHTTPHeaderFields(
    WebHTTPHeaderVisitor* headerVisitor) const
{
    for (HTTPHeaderMap::const_iterator i = m_private->m_headers.begin(),
                                       end = m_private->m_headers.end();
         i != end; ++i)
=======
void WebServiceWorkerRequest::visitHTTPHeaderFields(WebHTTPHeaderVisitor* headerVisitor) const
{
    for (HTTPHeaderMap::const_iterator i = m_private->m_headers.begin(), end = m_private->m_headers.end(); i != end; ++i)
>>>>>>> miniblink49
        headerVisitor->visitHeader(i->key, i->value);
}

const HTTPHeaderMap& WebServiceWorkerRequest::headers() const
{
    return m_private->m_headers;
}

void WebServiceWorkerRequest::setBlob(const WebString& uuid, long long size)
{
    m_private->blobDataHandle = BlobDataHandle::create(uuid, String(), size);
}

PassRefPtr<BlobDataHandle> WebServiceWorkerRequest::blobDataHandle() const
{
    return m_private->blobDataHandle;
}

<<<<<<< HEAD
void WebServiceWorkerRequest::setReferrer(const WebString& webReferrer,
    WebReferrerPolicy referrerPolicy)
{
    // WebString doesn't have the distinction between empty and null. We use
    // the null WTFString for referrer.
    ASSERT(Referrer::noReferrer() == String());
    String referrer = webReferrer.isEmpty() ? Referrer::noReferrer() : String(webReferrer);
=======
void WebServiceWorkerRequest::setReferrer(const WebString& referrer, WebReferrerPolicy referrerPolicy)
{
>>>>>>> miniblink49
    m_private->m_referrer = Referrer(referrer, static_cast<ReferrerPolicy>(referrerPolicy));
}

WebURL WebServiceWorkerRequest::referrerUrl() const
{
    return KURL(ParsedURLString, m_private->m_referrer.referrer);
}

<<<<<<< HEAD
WebReferrerPolicy WebServiceWorkerRequest::getReferrerPolicy() const
=======
WebReferrerPolicy WebServiceWorkerRequest::referrerPolicy() const
>>>>>>> miniblink49
{
    return static_cast<WebReferrerPolicy>(m_private->m_referrer.referrerPolicy);
}

const Referrer& WebServiceWorkerRequest::referrer() const
{
    return m_private->m_referrer;
}

void WebServiceWorkerRequest::setMode(WebURLRequest::FetchRequestMode mode)
{
    m_private->m_mode = mode;
}

WebURLRequest::FetchRequestMode WebServiceWorkerRequest::mode() const
{
    return m_private->m_mode;
}

<<<<<<< HEAD
void WebServiceWorkerRequest::setIsMainResourceLoad(bool isMainResourceLoad)
{
    m_private->m_isMainResourceLoad = isMainResourceLoad;
}

bool WebServiceWorkerRequest::isMainResourceLoad() const
{
    return m_private->m_isMainResourceLoad;
}

void WebServiceWorkerRequest::setCredentialsMode(
    WebURLRequest::FetchCredentialsMode credentialsMode)
=======
void WebServiceWorkerRequest::setCredentialsMode(WebURLRequest::FetchCredentialsMode credentialsMode)
>>>>>>> miniblink49
{
    m_private->m_credentialsMode = credentialsMode;
}

<<<<<<< HEAD
WebURLRequest::FetchCredentialsMode WebServiceWorkerRequest::credentialsMode()
    const
=======
WebURLRequest::FetchCredentialsMode WebServiceWorkerRequest::credentialsMode() const
>>>>>>> miniblink49
{
    return m_private->m_credentialsMode;
}

<<<<<<< HEAD
void WebServiceWorkerRequest::setRedirectMode(
    WebURLRequest::FetchRedirectMode redirectMode)
{
    m_private->m_redirectMode = redirectMode;
}

WebURLRequest::FetchRedirectMode WebServiceWorkerRequest::redirectMode() const
{
    return m_private->m_redirectMode;
}

void WebServiceWorkerRequest::setRequestContext(
    WebURLRequest::RequestContext requestContext)
=======
void WebServiceWorkerRequest::setRequestContext(WebURLRequest::RequestContext requestContext)
>>>>>>> miniblink49
{
    m_private->m_requestContext = requestContext;
}

WebURLRequest::RequestContext WebServiceWorkerRequest::requestContext() const
{
    return m_private->m_requestContext;
}

void WebServiceWorkerRequest::setFrameType(WebURLRequest::FrameType frameType)
{
    m_private->m_frameType = frameType;
}

WebURLRequest::FrameType WebServiceWorkerRequest::frameType() const
{
    return m_private->m_frameType;
}

<<<<<<< HEAD
void WebServiceWorkerRequest::setClientId(const WebString& clientId)
{
    m_private->m_clientId = clientId;
}

WebString WebServiceWorkerRequest::clientId() const
{
    return m_private->m_clientId;
}

=======
>>>>>>> miniblink49
void WebServiceWorkerRequest::setIsReload(bool isReload)
{
    m_private->m_isReload = isReload;
}

bool WebServiceWorkerRequest::isReload() const
{
    return m_private->m_isReload;
}

} // namespace blink
