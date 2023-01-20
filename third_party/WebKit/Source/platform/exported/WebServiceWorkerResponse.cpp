// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "public/platform/modules/serviceworker/WebServiceWorkerResponse.h"
=======
#include "config.h"
#include "public/platform/WebServiceWorkerResponse.h"
>>>>>>> miniblink49

#include "platform/blob/BlobData.h"
#include "platform/network/HTTPHeaderMap.h"
#include "public/platform/WebHTTPHeaderVisitor.h"
#include "wtf/HashMap.h"
<<<<<<< HEAD
#include "wtf/RefCounted.h"

namespace blink {

class WebServiceWorkerResponsePrivate
    : public RefCounted<WebServiceWorkerResponsePrivate> {
=======

namespace blink {

class WebServiceWorkerResponsePrivate : public RefCounted<WebServiceWorkerResponsePrivate> {
>>>>>>> miniblink49
public:
    WebServiceWorkerResponsePrivate()
        : status(0)
        , responseType(WebServiceWorkerResponseTypeDefault)
        , error(WebServiceWorkerResponseErrorUnknown)
<<<<<<< HEAD
        , responseTime(0)
    {
    }
    WebVector<WebURL> urlList;
=======
    {
    }
    WebURL url;
>>>>>>> miniblink49
    unsigned short status;
    WebString statusText;
    WebServiceWorkerResponseType responseType;
    HTTPHeaderMap headers;
    RefPtr<BlobDataHandle> blobDataHandle;
    WebURL streamURL;
    WebServiceWorkerResponseError error;
<<<<<<< HEAD
    int64_t responseTime;
    WebString cacheStorageCacheName;
    WebVector<WebString> corsExposedHeaderNames;
=======
>>>>>>> miniblink49
};

WebServiceWorkerResponse::WebServiceWorkerResponse()
    : m_private(adoptRef(new WebServiceWorkerResponsePrivate))
{
}

void WebServiceWorkerResponse::reset()
{
    m_private.reset();
}

void WebServiceWorkerResponse::assign(const WebServiceWorkerResponse& other)
{
    m_private = other.m_private;
}

<<<<<<< HEAD
void WebServiceWorkerResponse::setURLList(const WebVector<WebURL>& urlList)
{
    m_private->urlList = urlList;
}

const WebVector<WebURL>& WebServiceWorkerResponse::urlList() const
{
    return m_private->urlList;
=======
void WebServiceWorkerResponse::setURL(const WebURL& url)
{
    m_private->url = url;
}

WebURL WebServiceWorkerResponse::url() const
{
    return m_private->url;
>>>>>>> miniblink49
}

void WebServiceWorkerResponse::setStatus(unsigned short status)
{
    m_private->status = status;
}

unsigned short WebServiceWorkerResponse::status() const
{
    return m_private->status;
}

void WebServiceWorkerResponse::setStatusText(const WebString& statusText)
{
    m_private->statusText = statusText;
}

WebString WebServiceWorkerResponse::statusText() const
{
    return m_private->statusText;
}

<<<<<<< HEAD
void WebServiceWorkerResponse::setResponseType(
    WebServiceWorkerResponseType responseType)
=======
void WebServiceWorkerResponse::setResponseType(WebServiceWorkerResponseType responseType)
>>>>>>> miniblink49
{
    m_private->responseType = responseType;
}

WebServiceWorkerResponseType WebServiceWorkerResponse::responseType() const
{
    return m_private->responseType;
}

<<<<<<< HEAD
void WebServiceWorkerResponse::setHeader(const WebString& key,
    const WebString& value)
=======
void WebServiceWorkerResponse::setHeader(const WebString& key, const WebString& value)
>>>>>>> miniblink49
{
    m_private->headers.set(key, value);
}

<<<<<<< HEAD
void WebServiceWorkerResponse::appendHeader(const WebString& key,
    const WebString& value)
=======
void WebServiceWorkerResponse::appendHeader(const WebString& key, const WebString& value)
>>>>>>> miniblink49
{
    HTTPHeaderMap::AddResult addResult = m_private->headers.add(key, value);
    if (!addResult.isNewEntry)
        addResult.storedValue->value = addResult.storedValue->value + ", " + String(value);
}

WebVector<WebString> WebServiceWorkerResponse::getHeaderKeys() const
{
    Vector<String> keys;
<<<<<<< HEAD
    for (HTTPHeaderMap::const_iterator it = m_private->headers.begin(),
                                       end = m_private->headers.end();
         it != end; ++it)
        keys.push_back(it->key);
=======
    for (HTTPHeaderMap::const_iterator it = m_private->headers.begin(), end = m_private->headers.end(); it != end; ++it)
        keys.append(it->key);
>>>>>>> miniblink49

    return keys;
}

WebString WebServiceWorkerResponse::getHeader(const WebString& key) const
{
    return m_private->headers.get(key);
}

<<<<<<< HEAD
void WebServiceWorkerResponse::visitHTTPHeaderFields(
    WebHTTPHeaderVisitor* headerVisitor) const
{
    for (HTTPHeaderMap::const_iterator i = m_private->headers.begin(),
                                       end = m_private->headers.end();
         i != end; ++i)
=======
void WebServiceWorkerResponse::visitHTTPHeaderFields(WebHTTPHeaderVisitor* headerVisitor) const
{
    for (HTTPHeaderMap::const_iterator i = m_private->headers.begin(), end = m_private->headers.end(); i != end; ++i)
>>>>>>> miniblink49
        headerVisitor->visitHeader(i->key, i->value);
}

void WebServiceWorkerResponse::setBlob(const WebString& uuid, uint64_t size)
{
    m_private->blobDataHandle = BlobDataHandle::create(uuid, String(), size);
}

WebString WebServiceWorkerResponse::blobUUID() const
{
    if (!m_private->blobDataHandle)
        return WebString();
    return m_private->blobDataHandle->uuid();
}

uint64_t WebServiceWorkerResponse::blobSize() const
{
    if (!m_private->blobDataHandle)
        return 0;
    return m_private->blobDataHandle->size();
}

<<<<<<< HEAD
=======
const HTTPHeaderMap& WebServiceWorkerResponse::headers() const
{
    return m_private->headers;
}

void WebServiceWorkerResponse::setBlobDataHandle(PassRefPtr<BlobDataHandle> blobDataHandle)
{
    m_private->blobDataHandle = blobDataHandle;
}

PassRefPtr<BlobDataHandle> WebServiceWorkerResponse::blobDataHandle() const
{
    return m_private->blobDataHandle;
}

>>>>>>> miniblink49
void WebServiceWorkerResponse::setStreamURL(const WebURL& url)
{
    m_private->streamURL = url;
}

WebURL WebServiceWorkerResponse::streamURL() const
{
    return m_private->streamURL;
}

void WebServiceWorkerResponse::setError(WebServiceWorkerResponseError error)
{
    m_private->error = error;
}

WebServiceWorkerResponseError WebServiceWorkerResponse::error() const
{
    return m_private->error;
}

<<<<<<< HEAD
void WebServiceWorkerResponse::setResponseTime(int64_t time)
{
    m_private->responseTime = time;
}

int64_t WebServiceWorkerResponse::responseTime() const
{
    return m_private->responseTime;
}

void WebServiceWorkerResponse::setCacheStorageCacheName(
    const WebString& cacheStorageCacheName)
{
    m_private->cacheStorageCacheName = cacheStorageCacheName;
}

WebString WebServiceWorkerResponse::cacheStorageCacheName() const
{
    return m_private->cacheStorageCacheName;
}

void WebServiceWorkerResponse::setCorsExposedHeaderNames(
    const WebVector<WebString>& headerNames)
{
    m_private->corsExposedHeaderNames = headerNames;
}

WebVector<WebString> WebServiceWorkerResponse::corsExposedHeaderNames() const
{
    return m_private->corsExposedHeaderNames;
}

const HTTPHeaderMap& WebServiceWorkerResponse::headers() const
{
    return m_private->headers;
}

void WebServiceWorkerResponse::setBlobDataHandle(
    PassRefPtr<BlobDataHandle> blobDataHandle)
{
    m_private->blobDataHandle = blobDataHandle;
}

PassRefPtr<BlobDataHandle> WebServiceWorkerResponse::blobDataHandle() const
{
    return m_private->blobDataHandle;
}

=======
>>>>>>> miniblink49
} // namespace blink
