// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef Body_h
#define Body_h

<<<<<<< HEAD
#include "bindings/core/v8/ActiveScriptWrappable.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/ScriptWrappable.h"
#include "core/dom/ContextLifecycleObserver.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"
=======
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "bindings/core/v8/ScriptWrappable.h"
#include "core/dom/ActiveDOMObject.h"
#include "core/dom/DOMArrayBuffer.h"
#include "modules/ModulesExport.h"
#include "modules/fetch/FetchDataConsumerHandle.h"
#include "modules/fetch/FetchDataLoader.h"
#include "platform/blob/BlobData.h"
#include "platform/heap/Handle.h"
#include "wtf/RefPtr.h"
>>>>>>> miniblink49

namespace blink {

class BodyStreamBuffer;
<<<<<<< HEAD
class ExecutionContext;
class ScriptState;

// This class represents Body mix-in defined in the fetch spec
// https://fetch.spec.whatwg.org/#body-mixin.
//
// Note: This class has body stream and its predicate whereas in the current
// spec only Response has it and Request has a byte stream defined in the
// Encoding spec. The spec should be fixed shortly to be aligned with this
// implementation.
class MODULES_EXPORT Body : public GarbageCollected<Body>,
                            public ScriptWrappable,
                            public ActiveScriptWrappable<Body>,
                            public ContextClient {
    WTF_MAKE_NONCOPYABLE(Body);
    DEFINE_WRAPPERTYPEINFO();
    USING_GARBAGE_COLLECTED_MIXIN(Body);

public:
    explicit Body(ExecutionContext*);
=======
class DrainingBodyStreamBuffer;
class BodyStreamSource;
class DOMException;
class ReadableByteStream;
class ScriptState;

class MODULES_EXPORT Body
    : public GarbageCollectedFinalized<Body>
    , public ScriptWrappable
    , public ActiveDOMObject
    , public FetchDataLoader::Client {
    DEFINE_WRAPPERTYPEINFO();
    USING_GARBAGE_COLLECTED_MIXIN(Body);
public:
    class ReadableStreamSource;
    enum ResponseType {
        ResponseUnknown,
        ResponseAsArrayBuffer,
        ResponseAsBlob,
        ResponseAsFormData,
        ResponseAsJSON,
        ResponseAsText
    };
    enum LockBodyOption {
        LockBodyOptionNone,
        // Setting "body passed" flag in addition to acquiring a lock.
        PassBody,
    };
    explicit Body(ExecutionContext*);
    ~Body() override { }
>>>>>>> miniblink49

    ScriptPromise arrayBuffer(ScriptState*);
    ScriptPromise blob(ScriptState*);
    ScriptPromise formData(ScriptState*);
    ScriptPromise json(ScriptState*);
    ScriptPromise text(ScriptState*);
<<<<<<< HEAD
    ScriptValue bodyWithUseCounter(ScriptState*);
    virtual BodyStreamBuffer* bodyBuffer() = 0;
    virtual const BodyStreamBuffer* bodyBuffer() const = 0;

    virtual bool bodyUsed();
    bool isBodyLocked();

    // ScriptWrappable override.
    bool hasPendingActivity() const override;

    DEFINE_INLINE_VIRTUAL_TRACE() { ContextClient::trace(visitor); }

private:
    virtual String mimeType() const = 0;

    // Body consumption algorithms will reject with a TypeError in a number of
    // error conditions. This method wraps those up into one call which returns
    // an empty ScriptPromise if the consumption may proceed, and a
    // ScriptPromise rejected with a TypeError if it ought to be blocked.
    ScriptPromise rejectInvalidConsumption(ScriptState*);
=======
    ReadableByteStream* body();

    bool bodyUsed() const;
    void lockBody(LockBodyOption = LockBodyOptionNone);

    // Creates a DrainingBodyStreamBuffer to access body data.
    // Returns nullptr if underlying BodyStreamBuffer is null.
    PassOwnPtr<DrainingBodyStreamBuffer> createDrainingStream();

    // ActiveDOMObject override.
    bool hasPendingActivity() const override;

    DECLARE_VIRTUAL_TRACE();

protected:
    // Sets |m_stream| to a newly created stream from |buffer|.
    // |buffer| can be null.
    // This is called when the underlying buffer is set/modified.
    // TODO(hiroshige): Merge FetchRequest/ResponseData::buffer() and
    // integrate Body::setBody(), Request/Response::refreshBody(),
    // FetchRequestData::setBuffer() and
    // FetchResponseData::replaceBodyStreamBuffer().
    void setBody(BodyStreamBuffer* /* buffer */);

private:
    ScriptPromise readAsync(ScriptState*, ResponseType);
    void resolveWithEmptyDataSynchronously();
    void readAsyncFromDrainingBodyStreamBuffer(PassOwnPtr<DrainingBodyStreamBuffer>, const String& mimeType);
    void resolveJSON(const String&);

    // FetchDataLoader::Client functions.
    void didFetchDataLoadFailed() override;
    void didFetchDataLoadedBlobHandle(PassRefPtr<BlobDataHandle>) override;
    void didFetchDataLoadedArrayBuffer(PassRefPtr<DOMArrayBuffer>) override;
    void didFetchDataLoadedString(const String&) override;

    virtual String mimeType() const = 0;

    bool m_bodyUsed;
    ResponseType m_responseType;
    RefPtrWillBeMember<ScriptPromiseResolver> m_resolver;
    Member<ReadableStreamSource> m_streamSource;
    Member<ReadableByteStream> m_stream;
>>>>>>> miniblink49
};

} // namespace blink

#endif // Body_h
