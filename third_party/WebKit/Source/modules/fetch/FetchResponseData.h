// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FetchResponseData_h
#define FetchResponseData_h

<<<<<<< HEAD
#include "core/fetch/CrossOriginAccessControl.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "platform/weborigin/KURL.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerRequest.h"
#include "wtf/PassRefPtr.h"
#include "wtf/Vector.h"
#include "wtf/text/AtomicString.h"
#include <memory>
=======
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "platform/weborigin/KURL.h"
#include "public/platform/WebServiceWorkerRequest.h"
#include "wtf/PassRefPtr.h"
#include "wtf/text/AtomicString.h"
>>>>>>> miniblink49

namespace blink {

class BodyStreamBuffer;
<<<<<<< HEAD
class FetchHeaderList;
class ScriptState;
class WebServiceWorkerResponse;

class MODULES_EXPORT FetchResponseData final
    : public GarbageCollectedFinalized<FetchResponseData> {
    WTF_MAKE_NONCOPYABLE(FetchResponseData);

public:
    // "A response has an associated type which is one of basic, CORS, default,
    // error, opaque, and opaqueredirect. Unless stated otherwise, it is
    // default."
    enum Type {
        BasicType,
        CORSType,
        DefaultType,
        ErrorType,
        OpaqueType,
        OpaqueRedirectType
    };
    // "A response can have an associated termination reason which is one of
    // end-user abort, fatal, and timeout."
    enum TerminationReason {
        EndUserAbortTermination,
        FatalTermination,
        TimeoutTermination
    };
=======
class ExecutionContext;
class FetchHeaderList;
class WebServiceWorkerResponse;

class MODULES_EXPORT FetchResponseData final : public GarbageCollectedFinalized<FetchResponseData> {
    WTF_MAKE_NONCOPYABLE(FetchResponseData);
public:
    // "A response has an associated type which is one of basic, CORS, default,
    // error, and opaque. Unless stated otherwise, it is default."
    enum Type { BasicType, CORSType, DefaultType, ErrorType, OpaqueType };
    // "A response can have an associated termination reason which is one of
    // end-user abort, fatal, and timeout."
    enum TerminationReason { EndUserAbortTermination, FatalTermination, TimeoutTermination };
>>>>>>> miniblink49

    static FetchResponseData* create();
    static FetchResponseData* createNetworkErrorResponse();
    static FetchResponseData* createWithBuffer(BodyStreamBuffer*);

<<<<<<< HEAD
    FetchResponseData* createBasicFilteredResponse() const;
    // Creates a CORS filtered response, settings the response's cors exposed
    // header names list to the result of parsing the
    // Access-Control-Expose-Headers header.
    FetchResponseData* createCORSFilteredResponse() const;
    // Creates a CORS filtered response with an explicit set of exposed header
    // names.
    FetchResponseData* createCORSFilteredResponse(
        const HTTPHeaderSet& exposedHeaders) const;
    FetchResponseData* createOpaqueFilteredResponse() const;
    FetchResponseData* createOpaqueRedirectFilteredResponse() const;

    FetchResponseData* internalResponse() { return m_internalResponse; }
    const FetchResponseData* internalResponse() const
    {
        return m_internalResponse;
    }

    FetchResponseData* clone(ScriptState*);

    Type getType() const { return m_type; }
    const KURL* url() const;
=======
    FetchResponseData* createBasicFilteredResponse();
    FetchResponseData* createCORSFilteredResponse();
    FetchResponseData* createOpaqueFilteredResponse();

    FetchResponseData* clone(ExecutionContext*);

    Type type() const { return m_type; }
    const KURL& url() const { return m_url; }
>>>>>>> miniblink49
    unsigned short status() const { return m_status; }
    AtomicString statusMessage() const { return m_statusMessage; }
    FetchHeaderList* headerList() const { return m_headerList.get(); }
    BodyStreamBuffer* buffer() const { return m_buffer; }
    String mimeType() const;
<<<<<<< HEAD
    // Returns the BodyStreamBuffer of |m_internalResponse| if any. Otherwise,
    // returns |m_buffer|.
    BodyStreamBuffer* internalBuffer() const;
    String internalMIMEType() const;
    int64_t responseTime() const { return m_responseTime; }
    String cacheStorageCacheName() const { return m_cacheStorageCacheName; }
    const HTTPHeaderSet& corsExposedHeaderNames() const
    {
        return m_corsExposedHeaderNames;
    }

    void setURLList(const Vector<KURL>&);
    const Vector<KURL>& urlList() const { return m_urlList; }
    const Vector<KURL>& internalURLList() const;

    void setStatus(unsigned short status) { m_status = status; }
    void setStatusMessage(AtomicString statusMessage)
    {
        m_statusMessage = statusMessage;
    }
    void setMIMEType(const String& type) { m_mimeType = type; }
    void setResponseTime(int64_t responseTime) { m_responseTime = responseTime; }
    void setCacheStorageCacheName(const String& cacheStorageCacheName)
    {
        m_cacheStorageCacheName = cacheStorageCacheName;
    }
    void setCorsExposedHeaderNames(const HTTPHeaderSet& headerNames)
    {
        m_corsExposedHeaderNames = headerNames;
    }
=======
    BodyStreamBuffer* internalBuffer() const;
    String internalMIMEType() const;

    void setURL(const KURL& url) { m_url = url; }
    void setStatus(unsigned short status) { m_status = status; }
    void setStatusMessage(AtomicString statusMessage) { m_statusMessage = statusMessage; }
    void setMIMEType(const String& type) { m_mimeType = type; }
>>>>>>> miniblink49

    // If the type is Default, replaces |m_buffer|.
    // If the type is Basic or CORS, replaces |m_buffer| and
    // |m_internalResponse->m_buffer|.
    // If the type is Error or Opaque, does nothing.
<<<<<<< HEAD
    // Call Response::refreshBody after calling this function.
    void replaceBodyStreamBuffer(BodyStreamBuffer*);

    // Does not call response.setBlobDataHandle().
    void populateWebServiceWorkerResponse(
        WebServiceWorkerResponse& /* response */);
=======
    void replaceBodyStreamBuffer(BodyStreamBuffer*);

    // Does not call response.setBlobDataHandle().
    void populateWebServiceWorkerResponse(WebServiceWorkerResponse& /* response */);
>>>>>>> miniblink49

    DECLARE_TRACE();

private:
    FetchResponseData(Type, unsigned short, AtomicString);

    Type m_type;
<<<<<<< HEAD
    std::unique_ptr<TerminationReason> m_terminationReason;
    Vector<KURL> m_urlList;
=======
    OwnPtr<TerminationReason> m_terminationReason;
    KURL m_url;
>>>>>>> miniblink49
    unsigned short m_status;
    AtomicString m_statusMessage;
    Member<FetchHeaderList> m_headerList;
    Member<FetchResponseData> m_internalResponse;
    Member<BodyStreamBuffer> m_buffer;
    String m_mimeType;
<<<<<<< HEAD
    int64_t m_responseTime;
    String m_cacheStorageCacheName;
    HTTPHeaderSet m_corsExposedHeaderNames;
=======
>>>>>>> miniblink49
};

} // namespace blink

#endif // FetchResponseData_h
