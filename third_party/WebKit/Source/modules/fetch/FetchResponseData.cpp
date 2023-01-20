// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/fetch/FetchResponseData.h"

#include "bindings/core/v8/ScriptState.h"
#include "core/dom/DOMArrayBuffer.h"
#include "core/fetch/FetchUtils.h"
#include "modules/fetch/BodyStreamBuffer.h"
#include "modules/fetch/FetchHeaderList.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerResponse.h"
#include "wtf/PtrUtil.h"
=======
#include "config.h"
#include "modules/fetch/FetchResponseData.h"

#include "core/dom/DOMArrayBuffer.h"
#include "core/fetch/CrossOriginAccessControl.h"
#include "modules/fetch/BodyStreamBuffer.h"
#include "modules/fetch/DataConsumerHandleUtil.h"
#include "modules/fetch/DataConsumerTee.h"
#include "modules/fetch/FetchHeaderList.h"
#include "public/platform/WebServiceWorkerResponse.h"
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    WebServiceWorkerResponseType fetchTypeToWebType(
        FetchResponseData::Type fetchType)
    {
        WebServiceWorkerResponseType webType = WebServiceWorkerResponseTypeDefault;
        switch (fetchType) {
        case FetchResponseData::BasicType:
            webType = WebServiceWorkerResponseTypeBasic;
            break;
        case FetchResponseData::CORSType:
            webType = WebServiceWorkerResponseTypeCORS;
            break;
        case FetchResponseData::DefaultType:
            webType = WebServiceWorkerResponseTypeDefault;
            break;
        case FetchResponseData::ErrorType:
            webType = WebServiceWorkerResponseTypeError;
            break;
        case FetchResponseData::OpaqueType:
            webType = WebServiceWorkerResponseTypeOpaque;
            break;
        case FetchResponseData::OpaqueRedirectType:
            webType = WebServiceWorkerResponseTypeOpaqueRedirect;
            break;
        }
        return webType;
    }

    WebVector<WebString> headerSetToWebVector(const HTTPHeaderSet& headers)
    {
        // Can't just pass *headers to the WebVector constructor because HashSet
        // iterators are not stl iterator compatible.
        WebVector<WebString> result(static_cast<size_t>(headers.size()));
        int idx = 0;
        for (const auto& header : headers)
            result[idx++] = header;
        return result;
    }
=======
WebServiceWorkerResponseType fetchTypeToWebType(FetchResponseData::Type fetchType)
{
    WebServiceWorkerResponseType webType = WebServiceWorkerResponseTypeDefault;
    switch (fetchType) {
    case FetchResponseData::BasicType:
        webType = WebServiceWorkerResponseTypeBasic;
        break;
    case FetchResponseData::CORSType:
        webType = WebServiceWorkerResponseTypeCORS;
        break;
    case FetchResponseData::DefaultType:
        webType = WebServiceWorkerResponseTypeDefault;
        break;
    case FetchResponseData::ErrorType:
        webType = WebServiceWorkerResponseTypeError;
        break;
    case FetchResponseData::OpaqueType:
        webType = WebServiceWorkerResponseTypeOpaque;
        break;
    }
    return webType;
}
>>>>>>> miniblink49

} // namespace

FetchResponseData* FetchResponseData::create()
{
    // "Unless stated otherwise, a response's url is null, status is 200, status
    // message is `OK`, header list is an empty header list, and body is null."
    return new FetchResponseData(DefaultType, 200, "OK");
}

FetchResponseData* FetchResponseData::createNetworkErrorResponse()
{
    // "A network error is a response whose status is always 0, status message
    // is always the empty byte sequence, header list is aways an empty list,
    // and body is always null."
    return new FetchResponseData(ErrorType, 0, "");
}

<<<<<<< HEAD
FetchResponseData* FetchResponseData::createWithBuffer(
    BodyStreamBuffer* buffer)
=======
FetchResponseData* FetchResponseData::createWithBuffer(BodyStreamBuffer* buffer)
>>>>>>> miniblink49
{
    FetchResponseData* response = FetchResponseData::create();
    response->m_buffer = buffer;
    return response;
}

<<<<<<< HEAD
FetchResponseData* FetchResponseData::createBasicFilteredResponse() const
{
    DCHECK_EQ(m_type, DefaultType);
=======
FetchResponseData* FetchResponseData::createBasicFilteredResponse()
{
>>>>>>> miniblink49
    // "A basic filtered response is a filtered response whose type is |basic|,
    // header list excludes any headers in internal response's header list whose
    // name is `Set-Cookie` or `Set-Cookie2`."
    FetchResponseData* response = new FetchResponseData(BasicType, m_status, m_statusMessage);
<<<<<<< HEAD
    response->setURLList(m_urlList);
    for (size_t i = 0; i < m_headerList->size(); ++i) {
        const FetchHeaderList::Header* header = m_headerList->list()[i].get();
        if (FetchUtils::isForbiddenResponseHeaderName(header->first))
=======
    response->m_url = m_url;
    for (size_t i = 0; i < m_headerList->size(); ++i) {
        const FetchHeaderList::Header* header = m_headerList->list()[i].get();
        if (header->first == "set-cookie" || header->first == "set-cookie2")
>>>>>>> miniblink49
            continue;
        response->m_headerList->append(header->first, header->second);
    }
    response->m_buffer = m_buffer;
    response->m_mimeType = m_mimeType;
<<<<<<< HEAD
    response->m_internalResponse = const_cast<FetchResponseData*>(this);
    return response;
}

FetchResponseData* FetchResponseData::createCORSFilteredResponse() const
{
    DCHECK_EQ(m_type, DefaultType);
    HTTPHeaderSet accessControlExposeHeaderSet;
    String accessControlExposeHeaders;
    if (m_headerList->get(HTTPNames::Access_Control_Expose_Headers,
            accessControlExposeHeaders))
        parseAccessControlExposeHeadersAllowList(accessControlExposeHeaders,
            accessControlExposeHeaderSet);
    return createCORSFilteredResponse(accessControlExposeHeaderSet);
}

FetchResponseData* FetchResponseData::createCORSFilteredResponse(
    const HTTPHeaderSet& exposedHeaders) const
{
    DCHECK_EQ(m_type, DefaultType);
=======
    response->m_internalResponse = this;
    return response;
}

FetchResponseData* FetchResponseData::createCORSFilteredResponse()
{
>>>>>>> miniblink49
    // "A CORS filtered response is a filtered response whose type is |CORS|,
    // header list excludes all headers in internal response's header list,
    // except those whose name is either one of `Cache-Control`,
    // `Content-Language`, `Content-Type`, `Expires`, `Last-Modified`, and
    // `Pragma`, and except those whose name is one of the values resulting from
    // parsing `Access-Control-Expose-Headers` in internal response's header
    // list."
    FetchResponseData* response = new FetchResponseData(CORSType, m_status, m_statusMessage);
<<<<<<< HEAD
    response->setURLList(m_urlList);
    for (size_t i = 0; i < m_headerList->size(); ++i) {
        const FetchHeaderList::Header* header = m_headerList->list()[i].get();
        const String& name = header->first;
        const bool explicitlyExposed = exposedHeaders.contains(name);
        if (isOnAccessControlResponseHeaderWhitelist(name) || (explicitlyExposed && !FetchUtils::isForbiddenResponseHeaderName(name))) {
            if (explicitlyExposed)
                response->m_corsExposedHeaderNames.add(name);
            response->m_headerList->append(name, header->second);
        }
    }
    response->m_buffer = m_buffer;
    response->m_mimeType = m_mimeType;
    response->m_internalResponse = const_cast<FetchResponseData*>(this);
    return response;
}

FetchResponseData* FetchResponseData::createOpaqueFilteredResponse() const
{
    DCHECK_EQ(m_type, DefaultType);
    // "An opaque filtered response is a filtered response whose type is
    // 'opaque', url list is the empty list, status is 0, status message is the
    // empty byte sequence, header list is the empty list, body is null, and
    // cache state is 'none'."
    //
    // https://fetch.spec.whatwg.org/#concept-filtered-response-opaque
    FetchResponseData* response = new FetchResponseData(OpaqueType, 0, "");
    response->m_internalResponse = const_cast<FetchResponseData*>(this);
    return response;
}

FetchResponseData* FetchResponseData::createOpaqueRedirectFilteredResponse()
    const
{
    DCHECK_EQ(m_type, DefaultType);
    // "An opaque filtered response is a filtered response whose type is
    // 'opaqueredirect', status is 0, status message is the empty byte sequence,
    // header list is the empty list, body is null, and cache state is 'none'."
    //
    // https://fetch.spec.whatwg.org/#concept-filtered-response-opaque-redirect
    FetchResponseData* response = new FetchResponseData(OpaqueRedirectType, 0, "");
    response->setURLList(m_urlList);
    response->m_internalResponse = const_cast<FetchResponseData*>(this);
    return response;
}

const KURL* FetchResponseData::url() const
{
    // "A response has an associated url. It is a pointer to the last response URL
    // in response’s url list and null if response’s url list is the empty list."
    if (m_urlList.isEmpty())
        return nullptr;
    return &m_urlList.back();
}

=======
    response->m_url = m_url;
    HTTPHeaderSet accessControlExposeHeaderSet;
    String accessControlExposeHeaders;
    if (m_headerList->get("access-control-expose-headers", accessControlExposeHeaders))
        parseAccessControlExposeHeadersAllowList(accessControlExposeHeaders, accessControlExposeHeaderSet);
    for (size_t i = 0; i < m_headerList->size(); ++i) {
        const FetchHeaderList::Header* header = m_headerList->list()[i].get();
        if (!isOnAccessControlResponseHeaderWhitelist(header->first) && !accessControlExposeHeaderSet.contains(header->first))
            continue;
        response->m_headerList->append(header->first, header->second);
    }
    response->m_buffer = m_buffer;
    response->m_mimeType = m_mimeType;
    response->m_internalResponse = this;
    return response;
}

FetchResponseData* FetchResponseData::createOpaqueFilteredResponse()
{
    // "An opaque filtered response is a filtered response whose type is
    // |opaque|, status is 0, status message is the empty byte sequence, header
    // list is an empty list, and body is null."
    FetchResponseData* response = new FetchResponseData(OpaqueType, 0, "");
    response->m_internalResponse = this;
    return response;
}

>>>>>>> miniblink49
String FetchResponseData::mimeType() const
{
    return m_mimeType;
}

BodyStreamBuffer* FetchResponseData::internalBuffer() const
{
    if (m_internalResponse) {
        return m_internalResponse->m_buffer;
    }
    return m_buffer;
}

String FetchResponseData::internalMIMEType() const
{
    if (m_internalResponse) {
        return m_internalResponse->mimeType();
    }
    return m_mimeType;
}

<<<<<<< HEAD
void FetchResponseData::setURLList(const Vector<KURL>& urlList)
{
    m_urlList = urlList;
}

const Vector<KURL>& FetchResponseData::internalURLList() const
{
    if (m_internalResponse) {
        return m_internalResponse->m_urlList;
    }
    return m_urlList;
}

FetchResponseData* FetchResponseData::clone(ScriptState* scriptState)
=======
FetchResponseData* FetchResponseData::clone(ExecutionContext* executionContext)
>>>>>>> miniblink49
{
    FetchResponseData* newResponse = create();
    newResponse->m_type = m_type;
    if (m_terminationReason) {
<<<<<<< HEAD
        newResponse->m_terminationReason = WTF::wrapUnique(new TerminationReason);
        *newResponse->m_terminationReason = *m_terminationReason;
    }
    newResponse->setURLList(m_urlList);
=======
        newResponse->m_terminationReason = adoptPtr(new TerminationReason);
        *newResponse->m_terminationReason = *m_terminationReason;
    }
    newResponse->m_url = m_url;
>>>>>>> miniblink49
    newResponse->m_status = m_status;
    newResponse->m_statusMessage = m_statusMessage;
    newResponse->m_headerList = m_headerList->clone();
    newResponse->m_mimeType = m_mimeType;
<<<<<<< HEAD
    newResponse->m_responseTime = m_responseTime;
    newResponse->m_cacheStorageCacheName = m_cacheStorageCacheName;
    newResponse->m_corsExposedHeaderNames = m_corsExposedHeaderNames;
=======
>>>>>>> miniblink49

    switch (m_type) {
    case BasicType:
    case CORSType:
        ASSERT(m_internalResponse);
        ASSERT(m_buffer == m_internalResponse->m_buffer);
        ASSERT(m_internalResponse->m_type == DefaultType);
<<<<<<< HEAD
        newResponse->m_internalResponse = m_internalResponse->clone(scriptState);
=======
        newResponse->m_internalResponse = m_internalResponse->clone(executionContext);
>>>>>>> miniblink49
        m_buffer = m_internalResponse->m_buffer;
        newResponse->m_buffer = newResponse->m_internalResponse->m_buffer;
        break;
    case DefaultType: {
        ASSERT(!m_internalResponse);
<<<<<<< HEAD
        if (m_buffer) {
            BodyStreamBuffer* new1 = nullptr;
            BodyStreamBuffer* new2 = nullptr;
            m_buffer->tee(&new1, &new2);
            m_buffer = new1;
            newResponse->m_buffer = new2;
        }
=======
        if (!m_buffer)
            return newResponse;

        OwnPtr<WebDataConsumerHandle> handle1;
        OwnPtr<WebDataConsumerHandle> handle2;
        DataConsumerTee::create(executionContext, m_buffer->releaseHandle(), &handle1, &handle2);
        m_buffer = BodyStreamBuffer::create(createFetchDataConsumerHandleFromWebHandle(handle1.release()));
        newResponse->m_buffer = BodyStreamBuffer::create(createFetchDataConsumerHandleFromWebHandle(handle2.release()));
>>>>>>> miniblink49
        break;
    }
    case ErrorType:
        ASSERT(!m_internalResponse);
        ASSERT(!m_buffer);
        break;
    case OpaqueType:
<<<<<<< HEAD
    case OpaqueRedirectType:
        ASSERT(m_internalResponse);
        ASSERT(!m_buffer);
        ASSERT(m_internalResponse->m_type == DefaultType);
        newResponse->m_internalResponse = m_internalResponse->clone(scriptState);
=======
        ASSERT(m_internalResponse);
        ASSERT(!m_buffer);
        ASSERT(m_internalResponse->m_type == DefaultType);
        newResponse->m_internalResponse = m_internalResponse->clone(executionContext);
>>>>>>> miniblink49
        break;
    }
    return newResponse;
}

<<<<<<< HEAD
void FetchResponseData::populateWebServiceWorkerResponse(
    WebServiceWorkerResponse& response)
=======
void FetchResponseData::populateWebServiceWorkerResponse(WebServiceWorkerResponse& response)
>>>>>>> miniblink49
{
    if (m_internalResponse) {
        m_internalResponse->populateWebServiceWorkerResponse(response);
        response.setResponseType(fetchTypeToWebType(m_type));
<<<<<<< HEAD
        response.setCorsExposedHeaderNames(
            headerSetToWebVector(m_corsExposedHeaderNames));
        return;
    }
    response.setURLList(m_urlList);
    response.setStatus(status());
    response.setStatusText(statusMessage());
    response.setResponseType(fetchTypeToWebType(m_type));
    response.setResponseTime(responseTime());
    response.setCacheStorageCacheName(cacheStorageCacheName());
    response.setCorsExposedHeaderNames(
        headerSetToWebVector(m_corsExposedHeaderNames));
=======
        return;
    }

    response.setURL(url());
    response.setStatus(status());
    response.setStatusText(statusMessage());
    response.setResponseType(fetchTypeToWebType(m_type));
>>>>>>> miniblink49
    for (size_t i = 0; i < headerList()->size(); ++i) {
        const FetchHeaderList::Header* header = headerList()->list()[i].get();
        response.appendHeader(header->first, header->second);
    }
}

<<<<<<< HEAD
FetchResponseData::FetchResponseData(Type type,
    unsigned short status,
    AtomicString statusMessage)
=======
FetchResponseData::FetchResponseData(Type type, unsigned short status, AtomicString statusMessage)
>>>>>>> miniblink49
    : m_type(type)
    , m_status(status)
    , m_statusMessage(statusMessage)
    , m_headerList(FetchHeaderList::create())
<<<<<<< HEAD
    , m_responseTime(0)
=======
>>>>>>> miniblink49
{
}

void FetchResponseData::replaceBodyStreamBuffer(BodyStreamBuffer* buffer)
{
    if (m_type == BasicType || m_type == CORSType) {
        ASSERT(m_internalResponse);
        m_internalResponse->m_buffer = buffer;
        m_buffer = buffer;
    } else if (m_type == DefaultType) {
        ASSERT(!m_internalResponse);
        m_buffer = buffer;
    }
}

DEFINE_TRACE(FetchResponseData)
{
    visitor->trace(m_headerList);
    visitor->trace(m_internalResponse);
    visitor->trace(m_buffer);
}

} // namespace blink
