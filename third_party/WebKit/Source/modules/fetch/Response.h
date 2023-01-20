// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef Response_h
#define Response_h

#include "bindings/core/v8/Dictionary.h"
<<<<<<< HEAD
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/ScriptWrappable.h"
=======
#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/modules/v8/UnionTypesModules.h"
>>>>>>> miniblink49
#include "modules/ModulesExport.h"
#include "modules/fetch/Body.h"
#include "modules/fetch/BodyStreamBuffer.h"
#include "modules/fetch/FetchResponseData.h"
#include "modules/fetch/Headers.h"
#include "platform/blob/BlobData.h"
#include "platform/heap/Handle.h"
<<<<<<< HEAD
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"

namespace blink {

class ExceptionState;
class ResponseInit;
class ScriptState;
class WebServiceWorkerResponse;

class MODULES_EXPORT Response final : public Body {
    DEFINE_WRAPPERTYPEINFO();
    WTF_MAKE_NONCOPYABLE(Response);

public:
    // These "create" function which takes a ScriptState* must be called with
    // entering an appropriate V8 context.
    // From Response.idl:
    static Response* create(ScriptState*, ExceptionState&);
    static Response* create(ScriptState*,
        ScriptValue body,
        const Dictionary&,
        ExceptionState&);

    static Response* create(ScriptState*,
        BodyStreamBuffer*,
        const String& contentType,
        const ResponseInit&,
        ExceptionState&);
    static Response* create(ExecutionContext*, FetchResponseData*);
    static Response* create(ScriptState*, const WebServiceWorkerResponse&);

    static Response* createClone(const Response&);

    static Response* error(ScriptState*);
    static Response* redirect(ScriptState*,
        const String& url,
        unsigned short status,
        ExceptionState&);
=======

namespace blink {

class Blob;
class DrainingBodyStreamBuffer;
class DOMArrayBuffer;
class ExceptionState;
class ResponseInit;
class WebServiceWorkerResponse;

typedef BlobOrArrayBufferOrArrayBufferViewOrFormDataOrUSVString BodyInit;

class MODULES_EXPORT Response final : public Body, public BodyStreamBuffer::DrainingStreamNotificationClient {
    DEFINE_WRAPPERTYPEINFO();
    USING_GARBAGE_COLLECTED_MIXIN(Response);
public:
    ~Response() override { }

    // From Response.idl:
    static Response* create(ExecutionContext*, ExceptionState&);
    static Response* create(ExecutionContext*, const BodyInit&, const Dictionary&, ExceptionState&);

    static Response* create(ExecutionContext*, Blob*, const ResponseInit&, ExceptionState&);
    static Response* create(ExecutionContext*, FetchResponseData*);
    static Response* create(ExecutionContext*, const WebServiceWorkerResponse&);

    static Response* createClone(const Response&);

    static Response* error(ExecutionContext*);
    static Response* redirect(ExecutionContext*, const String& url, unsigned short status, ExceptionState&);
>>>>>>> miniblink49

    const FetchResponseData* response() const { return m_response; }

    // From Response.idl:
    String type() const;
    String url() const;
<<<<<<< HEAD
    bool redirected() const;
=======
>>>>>>> miniblink49
    unsigned short status() const;
    bool ok() const;
    String statusText() const;
    Headers* headers() const;

    // From Response.idl:
<<<<<<< HEAD
    // This function must be called with entering an appropriate V8 context.
    Response* clone(ScriptState*, ExceptionState&);

    // ScriptWrappable
    bool hasPendingActivity() const final;

    // Does not call response.setBlobDataHandle().
    void populateWebServiceWorkerResponse(
        WebServiceWorkerResponse& /* response */);

    bool hasBody() const;
    BodyStreamBuffer* bodyBuffer() override { return m_response->buffer(); }
    // Returns the BodyStreamBuffer of |m_response|. This method doesn't check
    // the internal response of |m_response| even if |m_response| has it.
    const BodyStreamBuffer* bodyBuffer() const override
    {
        return m_response->buffer();
    }
    // Returns the BodyStreamBuffer of the internal response of |m_response| if
    // any. Otherwise, returns one of |m_response|.
    BodyStreamBuffer* internalBodyBuffer()
    {
        return m_response->internalBuffer();
    }
    const BodyStreamBuffer* internalBodyBuffer() const
    {
        return m_response->internalBuffer();
    }
    bool bodyUsed() override;
=======
    Response* clone(ExceptionState&);

    // ActiveDOMObject
    bool hasPendingActivity() const override;

    // Does not call response.setBlobDataHandle().
    void populateWebServiceWorkerResponse(WebServiceWorkerResponse& /* response */);

    bool hasBody() const;
>>>>>>> miniblink49

    String mimeType() const override;
    String internalMIMEType() const;

<<<<<<< HEAD
    const Vector<KURL>& internalURLList() const;
=======
    // Do not call leakBuffer() on the returned buffer because
    // hasPendingActivity() assumes didFetchDataLoadFinishedFromDrainingStream()
    // will be called.
    PassOwnPtr<DrainingBodyStreamBuffer> createInternalDrainingStream();
    void didFetchDataLoadFinishedFromDrainingStream() override;

    // Only for tests (null checks and identity checks).
    void* bufferForTest() const;
    void* internalBufferForTest() const;
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
    explicit Response(ExecutionContext*);
    Response(ExecutionContext*, FetchResponseData*);
    Response(ExecutionContext*, FetchResponseData*, Headers*);

<<<<<<< HEAD
    void installBody();
    void refreshBody(ScriptState*);

    const Member<FetchResponseData> m_response;
    const Member<Headers> m_headers;
=======
    void refreshBody();

    const Member<FetchResponseData> m_response;
    const Member<Headers> m_headers;
    bool m_isInternalDrained;
>>>>>>> miniblink49
};

} // namespace blink

#endif // Response_h
