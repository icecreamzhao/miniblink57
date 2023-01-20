// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BodyStreamBuffer_h
#define BodyStreamBuffer_h

<<<<<<< HEAD
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptValue.h"
#include "core/dom/DOMException.h"
#include "core/streams/UnderlyingSourceBase.h"
#include "modules/ModulesExport.h"
#include "modules/fetch/BytesConsumer.h"
#include "modules/fetch/FetchDataLoader.h"
#include "platform/heap/Handle.h"
#include "public/platform/WebDataConsumerHandle.h"
#include <memory>

namespace blink {

class EncodedFormData;
class ScriptState;

class MODULES_EXPORT BodyStreamBuffer final : public UnderlyingSourceBase,
                                              public BytesConsumer::Client {
    WTF_MAKE_NONCOPYABLE(BodyStreamBuffer);
    USING_GARBAGE_COLLECTED_MIXIN(BodyStreamBuffer);

public:
    // |consumer| must not have a client.
    // This function must be called with entering an appropriate V8 context.
    BodyStreamBuffer(ScriptState*, BytesConsumer* /* consumer */);
    // |ReadableStreamOperations::isReadableStream(stream)| must hold.
    // This function must be called with entering an appropriate V8 context.
    BodyStreamBuffer(ScriptState*, ScriptValue stream);

    ScriptValue stream();

    // Callable only when neither locked nor disturbed.
    PassRefPtr<BlobDataHandle> drainAsBlobDataHandle(
        BytesConsumer::BlobSizePolicy);
    PassRefPtr<EncodedFormData> drainAsFormData();
    void startLoading(FetchDataLoader*, FetchDataLoader::Client* /* client */);
    void tee(BodyStreamBuffer**, BodyStreamBuffer**);

    // UnderlyingSourceBase
    ScriptPromise pull(ScriptState*) override;
    ScriptPromise cancel(ScriptState*, ScriptValue reason) override;
    bool hasPendingActivity() const override;
    void contextDestroyed(ExecutionContext*) override;

    // BytesConsumer::Client
    void onStateChange() override;

    bool isStreamReadable();
    bool isStreamClosed();
    bool isStreamErrored();
    bool isStreamLocked();
    bool isStreamDisturbed();
    void closeAndLockAndDisturb();
    ScriptState* scriptState() { return m_scriptState.get(); }

    DEFINE_INLINE_TRACE()
    {
        visitor->trace(m_consumer);
        visitor->trace(m_loader);
        UnderlyingSourceBase::trace(visitor);
    }

private:
    class LoaderClient;

    BytesConsumer* releaseHandle();
    void close();
    void error();
    void cancelConsumer();
    void processData();
    void endLoading();
    void stopLoading();

    RefPtr<ScriptState> m_scriptState;
    Member<BytesConsumer> m_consumer;
    // We need this member to keep it alive while loading.
    Member<FetchDataLoader> m_loader;
    bool m_streamNeedsMore = false;
    bool m_madeFromReadableStream;
=======
#include "core/dom/DOMException.h"
#include "modules/ModulesExport.h"
#include "modules/fetch/DataConsumerHandleUtil.h"
#include "modules/fetch/FetchDataConsumerHandle.h"
#include "modules/fetch/FetchDataLoader.h"
#include "platform/blob/BlobData.h"
#include "platform/heap/Heap.h"
#include "public/platform/WebDataConsumerHandle.h"
#include "wtf/Deque.h"
#include "wtf/RefPtr.h"
#include "wtf/text/WTFString.h"

namespace blink {

class DrainingBodyStreamBuffer;

class MODULES_EXPORT BodyStreamBuffer final : public GarbageCollectedFinalized<BodyStreamBuffer> {
public:
    static BodyStreamBuffer* create(PassOwnPtr<FetchDataConsumerHandle> handle) { return new BodyStreamBuffer(handle); }
    static BodyStreamBuffer* createEmpty();

    FetchDataConsumerHandle* handle() const;
    PassOwnPtr<FetchDataConsumerHandle> releaseHandle();

    class MODULES_EXPORT DrainingStreamNotificationClient : public GarbageCollectedMixin {
    public:
        virtual ~DrainingStreamNotificationClient() { }
        // Called after FetchDataLoader::Client methods.
        virtual void didFetchDataLoadFinishedFromDrainingStream() = 0;
    };

    DEFINE_INLINE_TRACE()
    {
        visitor->trace(m_fetchDataLoader);
        visitor->trace(m_drainingStreamNotificationClient);
    }

    void didFetchDataLoadFinished();

private:
    explicit BodyStreamBuffer(PassOwnPtr<FetchDataConsumerHandle> handle) : m_handle(handle) { }

    void setDrainingStreamNotificationClient(DrainingStreamNotificationClient*);

    void startLoading(ExecutionContext*, FetchDataLoader*, FetchDataLoader::Client*);
    // Call DrainingStreamNotificationClient.
    void doDrainingStreamNotification();
    // Clear DrainingStreamNotificationClient without calling.
    void clearDrainingStreamNotification();

    friend class DrainingBodyStreamBuffer;

    OwnPtr<FetchDataConsumerHandle> m_handle;
    Member<FetchDataLoader::Client> m_fetchDataLoader;
    Member<DrainingStreamNotificationClient> m_drainingStreamNotificationClient;
};

// DrainingBodyStreamBuffer wraps BodyStreamBuffer returned from
// Body::createDrainingStream() and calls DrainingStreamNotificationClient
// callbacks unless leakBuffer() is called:
// - If startLoading() is called, the callback is called after loading finished.
// - If drainAsBlobDataHandle() is called, the callback is called immediately.
// - If leakBuffer() is called, the callback is no longer called.
// Any calls to DrainingBodyStreamBuffer methods after a call to either of
// methods above is no-op.
// After calling one of the methods above, we don't have to keep
// DrainingBodyStreamBuffer alive.
// If DrainingBodyStreamBuffer is destructed before any of above is called,
// the callback is called at destruction.
class MODULES_EXPORT DrainingBodyStreamBuffer final {
public:
    static PassOwnPtr<DrainingBodyStreamBuffer> create(BodyStreamBuffer* buffer, BodyStreamBuffer::DrainingStreamNotificationClient* client)
    {
        return adoptPtr(new DrainingBodyStreamBuffer(buffer, client));
    }
    ~DrainingBodyStreamBuffer();
    void startLoading(ExecutionContext*, FetchDataLoader*, FetchDataLoader::Client*);
    BodyStreamBuffer* leakBuffer();
    PassRefPtr<BlobDataHandle> drainAsBlobDataHandle(FetchDataConsumerHandle::Reader::BlobSizePolicy);

private:
    DrainingBodyStreamBuffer(BodyStreamBuffer*, BodyStreamBuffer::DrainingStreamNotificationClient*);

    Persistent<BodyStreamBuffer> m_buffer;
>>>>>>> miniblink49
};

} // namespace blink

#endif // BodyStreamBuffer_h
