// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/fetch/BodyStreamBuffer.h"

#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ThrowException.h"
#include "core/dom/DOMArrayBuffer.h"
#include "core/dom/DOMTypedArray.h"
#include "core/dom/ExceptionCode.h"
#include "core/streams/ReadableStreamController.h"
#include "core/streams/ReadableStreamOperations.h"
#include "modules/fetch/Body.h"
#include "modules/fetch/ReadableStreamBytesConsumer.h"
#include "platform/blob/BlobData.h"
#include "platform/network/EncodedFormData.h"
#include <memory>

namespace blink {

class BodyStreamBuffer::LoaderClient final
    : public GarbageCollectedFinalized<LoaderClient>,
      public ContextLifecycleObserver,
      public FetchDataLoader::Client {
    WTF_MAKE_NONCOPYABLE(LoaderClient);
    USING_GARBAGE_COLLECTED_MIXIN(LoaderClient);

public:
    LoaderClient(ExecutionContext* executionContext,
        BodyStreamBuffer* buffer,
        FetchDataLoader::Client* client)
        : ContextLifecycleObserver(executionContext)
        , m_buffer(buffer)
        , m_client(client)
    {
    }

    void didFetchDataLoadedBlobHandle(
        PassRefPtr<BlobDataHandle> blobDataHandle) override
    {
        m_buffer->endLoading();
        m_client->didFetchDataLoadedBlobHandle(std::move(blobDataHandle));
    }

    void didFetchDataLoadedArrayBuffer(DOMArrayBuffer* arrayBuffer) override
    {
        m_buffer->endLoading();
        m_client->didFetchDataLoadedArrayBuffer(arrayBuffer);
    }

    void didFetchDataLoadedString(const String& string) override
    {
        m_buffer->endLoading();
        m_client->didFetchDataLoadedString(string);
    }

    void didFetchDataLoadedStream() override
    {
        m_buffer->endLoading();
        m_client->didFetchDataLoadedStream();
    }

    void didFetchDataLoadFailed() override
    {
        m_buffer->endLoading();
        m_client->didFetchDataLoadFailed();
    }

    DEFINE_INLINE_TRACE()
    {
        visitor->trace(m_buffer);
        visitor->trace(m_client);
        ContextLifecycleObserver::trace(visitor);
=======
#include "config.h"
#include "modules/fetch/BodyStreamBuffer.h"

#include "core/dom/DOMArrayBuffer.h"
#include "core/dom/ExceptionCode.h"

namespace blink {

BodyStreamBuffer* BodyStreamBuffer::createEmpty()
{
    return BodyStreamBuffer::create(createFetchDataConsumerHandleFromWebHandle(createDoneDataConsumerHandle()));
}

FetchDataConsumerHandle* BodyStreamBuffer::handle() const
{
    ASSERT(!m_fetchDataLoader);
    ASSERT(!m_drainingStreamNotificationClient);
    return m_handle.get();
}

PassOwnPtr<FetchDataConsumerHandle> BodyStreamBuffer::releaseHandle()
{
    ASSERT(!m_fetchDataLoader);
    ASSERT(!m_drainingStreamNotificationClient);
    return m_handle.release();
}

class LoaderHolder final : public GarbageCollectedFinalized<LoaderHolder>, public ActiveDOMObject, public FetchDataLoader::Client {
    USING_GARBAGE_COLLECTED_MIXIN(LoaderHolder);
public:
    LoaderHolder(ExecutionContext* executionContext, BodyStreamBuffer* buffer, FetchDataLoader* loader, FetchDataLoader::Client* client)
        : ActiveDOMObject(executionContext)
        , m_buffer(buffer)
        , m_loader(loader)
        , m_client(client)
    {
        suspendIfNeeded();
    }

    void start(FetchDataConsumerHandle* handle)
    {
        m_loader->start(handle, this);
    }

    DEFINE_INLINE_VIRTUAL_TRACE()
    {
        visitor->trace(m_buffer);
        visitor->trace(m_loader);
        visitor->trace(m_client);
        ActiveDOMObject::trace(visitor);
>>>>>>> miniblink49
        FetchDataLoader::Client::trace(visitor);
    }

private:
<<<<<<< HEAD
    void contextDestroyed(ExecutionContext*) override { m_buffer->stopLoading(); }

    Member<BodyStreamBuffer> m_buffer;
    Member<FetchDataLoader::Client> m_client;
};

BodyStreamBuffer::BodyStreamBuffer(ScriptState* scriptState,
    BytesConsumer* consumer)
    : UnderlyingSourceBase(scriptState)
    , m_scriptState(scriptState)
    , m_consumer(consumer)
    , m_madeFromReadableStream(false)
{
    v8::Local<v8::Value> bodyValue = ToV8(this, scriptState);
    DCHECK(!bodyValue.IsEmpty());
    DCHECK(bodyValue->IsObject());
    v8::Local<v8::Object> body = bodyValue.As<v8::Object>();

    ScriptValue readableStream = ReadableStreamOperations::createReadableStream(
        scriptState, this,
        ReadableStreamOperations::createCountQueuingStrategy(scriptState, 0));
    DCHECK(!readableStream.isEmpty());
    V8HiddenValue::setHiddenValue(
        scriptState, body,
        V8HiddenValue::internalBodyStream(scriptState->isolate()),
        readableStream.v8Value());
    m_consumer->setClient(this);
    onStateChange();
}

BodyStreamBuffer::BodyStreamBuffer(ScriptState* scriptState, ScriptValue stream)
    : UnderlyingSourceBase(scriptState)
    , m_scriptState(scriptState)
    , m_madeFromReadableStream(true)
{
    DCHECK(ReadableStreamOperations::isReadableStream(scriptState, stream));
    v8::Local<v8::Value> bodyValue = ToV8(this, scriptState);
    DCHECK(!bodyValue.IsEmpty());
    DCHECK(bodyValue->IsObject());
    v8::Local<v8::Object> body = bodyValue.As<v8::Object>();

    V8HiddenValue::setHiddenValue(
        scriptState, body,
        V8HiddenValue::internalBodyStream(scriptState->isolate()),
        stream.v8Value());
}

ScriptValue BodyStreamBuffer::stream()
{
    ScriptState::Scope scope(m_scriptState.get());
    v8::Local<v8::Value> bodyValue = ToV8(this, m_scriptState.get());
    DCHECK(!bodyValue.IsEmpty());
    DCHECK(bodyValue->IsObject());
    v8::Local<v8::Object> body = bodyValue.As<v8::Object>();
    return ScriptValue(
        m_scriptState.get(),
        V8HiddenValue::getHiddenValue(
            m_scriptState.get(), body,
            V8HiddenValue::internalBodyStream(m_scriptState->isolate())));
}

PassRefPtr<BlobDataHandle> BodyStreamBuffer::drainAsBlobDataHandle(
    BytesConsumer::BlobSizePolicy policy)
{
    ASSERT(!isStreamLocked());
    ASSERT(!isStreamDisturbed());
    if (isStreamClosed() || isStreamErrored())
        return nullptr;

    if (m_madeFromReadableStream)
        return nullptr;

    RefPtr<BlobDataHandle> blobDataHandle = m_consumer->drainAsBlobDataHandle(policy);
    if (blobDataHandle) {
        closeAndLockAndDisturb();
        return blobDataHandle.release();
    }
    return nullptr;
}

PassRefPtr<EncodedFormData> BodyStreamBuffer::drainAsFormData()
{
    ASSERT(!isStreamLocked());
    ASSERT(!isStreamDisturbed());
    if (isStreamClosed() || isStreamErrored())
        return nullptr;

    if (m_madeFromReadableStream)
        return nullptr;

    RefPtr<EncodedFormData> formData = m_consumer->drainAsFormData();
    if (formData) {
        closeAndLockAndDisturb();
        return formData.release();
    }
    return nullptr;
}

void BodyStreamBuffer::startLoading(FetchDataLoader* loader,
    FetchDataLoader::Client* client)
{
    ASSERT(!m_loader);
    ASSERT(m_scriptState->contextIsValid());
    m_loader = loader;
    loader->start(
        releaseHandle(),
        new LoaderClient(m_scriptState->getExecutionContext(), this, client));
}

void BodyStreamBuffer::tee(BodyStreamBuffer** branch1,
    BodyStreamBuffer** branch2)
{
    DCHECK(!isStreamLocked());
    DCHECK(!isStreamDisturbed());
    *branch1 = nullptr;
    *branch2 = nullptr;

    if (m_madeFromReadableStream) {
        ScriptValue stream1, stream2;
        ReadableStreamOperations::tee(m_scriptState.get(), stream(), &stream1,
            &stream2);
        *branch1 = new BodyStreamBuffer(m_scriptState.get(), stream1);
        *branch2 = new BodyStreamBuffer(m_scriptState.get(), stream2);
        return;
    }
    BytesConsumer* dest1 = nullptr;
    BytesConsumer* dest2 = nullptr;
    BytesConsumer::tee(m_scriptState->getExecutionContext(), releaseHandle(),
        &dest1, &dest2);
    *branch1 = new BodyStreamBuffer(m_scriptState.get(), dest1);
    *branch2 = new BodyStreamBuffer(m_scriptState.get(), dest2);
}

ScriptPromise BodyStreamBuffer::pull(ScriptState* scriptState)
{
    ASSERT(scriptState == m_scriptState.get());
    if (m_streamNeedsMore)
        return ScriptPromise::castUndefined(scriptState);
    m_streamNeedsMore = true;
    processData();
    return ScriptPromise::castUndefined(scriptState);
}

ScriptPromise BodyStreamBuffer::cancel(ScriptState* scriptState,
    ScriptValue reason)
{
    ASSERT(scriptState == m_scriptState.get());
    close();
    return ScriptPromise::castUndefined(scriptState);
}

void BodyStreamBuffer::onStateChange()
{
    if (!m_consumer || !getExecutionContext() || getExecutionContext()->isContextDestroyed())
        return;

    switch (m_consumer->getPublicState()) {
    case BytesConsumer::PublicState::ReadableOrWaiting:
        break;
    case BytesConsumer::PublicState::Closed:
        close();
        return;
    case BytesConsumer::PublicState::Errored:
        error();
        return;
    }
    processData();
}

bool BodyStreamBuffer::hasPendingActivity() const
{
    if (m_loader)
        return true;
    return UnderlyingSourceBase::hasPendingActivity();
}

void BodyStreamBuffer::contextDestroyed(ExecutionContext* destroyedContext)
{
    cancelConsumer();
    UnderlyingSourceBase::contextDestroyed(destroyedContext);
}

bool BodyStreamBuffer::isStreamReadable()
{
    ScriptState::Scope scope(m_scriptState.get());
    return ReadableStreamOperations::isReadable(m_scriptState.get(), stream());
}

bool BodyStreamBuffer::isStreamClosed()
{
    ScriptState::Scope scope(m_scriptState.get());
    return ReadableStreamOperations::isClosed(m_scriptState.get(), stream());
}

bool BodyStreamBuffer::isStreamErrored()
{
    ScriptState::Scope scope(m_scriptState.get());
    return ReadableStreamOperations::isErrored(m_scriptState.get(), stream());
}

bool BodyStreamBuffer::isStreamLocked()
{
    ScriptState::Scope scope(m_scriptState.get());
    return ReadableStreamOperations::isLocked(m_scriptState.get(), stream());
}

bool BodyStreamBuffer::isStreamDisturbed()
{
    ScriptState::Scope scope(m_scriptState.get());
    return ReadableStreamOperations::isDisturbed(m_scriptState.get(), stream());
}

void BodyStreamBuffer::closeAndLockAndDisturb()
{
    if (isStreamReadable()) {
        // Note that the stream cannot be "draining", because it doesn't have
        // the internal buffer.
        close();
    }

    ScriptState::Scope scope(m_scriptState.get());
    NonThrowableExceptionState exceptionState;
    ScriptValue reader = ReadableStreamOperations::getReader(
        m_scriptState.get(), stream(), exceptionState);
    ReadableStreamOperations::defaultReaderRead(m_scriptState.get(), reader);
}

void BodyStreamBuffer::close()
{
    controller()->close();
    cancelConsumer();
}

void BodyStreamBuffer::error()
{
    {
        ScriptState::Scope scope(m_scriptState.get());
        controller()->error(V8ThrowException::createTypeError(
            m_scriptState->isolate(), "network error"));
    }
    cancelConsumer();
}

void BodyStreamBuffer::cancelConsumer()
{
    if (m_consumer) {
        m_consumer->cancel();
        m_consumer = nullptr;
    }
}

void BodyStreamBuffer::processData()
{
    DCHECK(m_consumer);
    while (m_streamNeedsMore) {
        const char* buffer = nullptr;
        size_t available = 0;
        auto result = m_consumer->beginRead(&buffer, &available);
        if (result == BytesConsumer::Result::ShouldWait)
            return;
        DOMUint8Array* array = nullptr;
        if (result == BytesConsumer::Result::Ok) {
            array = DOMUint8Array::create(
                reinterpret_cast<const unsigned char*>(buffer), available);
            result = m_consumer->endRead(available);
        }
        switch (result) {
        case BytesConsumer::Result::Ok: {
            DCHECK(array);
            // Clear m_streamNeedsMore in order to detect a pull call.
            m_streamNeedsMore = false;
            controller()->enqueue(array);
            // If m_streamNeedsMore is true, it means that pull is called and
            // the stream needs more data even if the desired size is not
            // positive.
            if (!m_streamNeedsMore)
                m_streamNeedsMore = controller()->desiredSize() > 0;
            break;
        }
        case BytesConsumer::Result::ShouldWait:
            NOTREACHED();
            return;
        case BytesConsumer::Result::Done:
            close();
            return;
        case BytesConsumer::Result::Error:
            error();
            return;
        }
    }
}

void BodyStreamBuffer::endLoading()
{
    ASSERT(m_loader);
    m_loader = nullptr;
}

void BodyStreamBuffer::stopLoading()
{
    if (!m_loader)
        return;
    m_loader->cancel();
    m_loader = nullptr;
}

BytesConsumer* BodyStreamBuffer::releaseHandle()
{
    DCHECK(!isStreamLocked());
    DCHECK(!isStreamDisturbed());

    if (m_madeFromReadableStream) {
        ScriptState::Scope scope(m_scriptState.get());
        // We need to have |reader| alive by some means (as written in
        // ReadableStreamDataConsumerHandle). Based on the following facts
        //  - This function is used only from tee and startLoading.
        //  - This branch cannot be taken when called from tee.
        //  - startLoading makes hasPendingActivity return true while loading.
        // , we don't need to keep the reader explicitly.
        NonThrowableExceptionState exceptionState;
        ScriptValue reader = ReadableStreamOperations::getReader(
            m_scriptState.get(), stream(), exceptionState);
        return new ReadableStreamBytesConsumer(m_scriptState.get(), reader);
    }
    // We need to call these before calling closeAndLockAndDisturb.
    const bool isClosed = isStreamClosed();
    const bool isErrored = isStreamErrored();
    BytesConsumer* consumer = m_consumer.release();

    closeAndLockAndDisturb();

    if (isClosed) {
        // Note that the stream cannot be "draining", because it doesn't have
        // the internal buffer.
        return BytesConsumer::createClosed();
    }
    if (isErrored)
        return BytesConsumer::createErrored(BytesConsumer::Error("error"));

    DCHECK(consumer);
    consumer->clearClient();
    return consumer;
=======
    void didFetchDataLoadedBlobHandle(PassRefPtr<BlobDataHandle> blobDataHandle) override
    {
        m_loader.clear();
        if (m_client)
            m_client->didFetchDataLoadedBlobHandle(blobDataHandle);
        m_buffer->didFetchDataLoadFinished();
    }
    void didFetchDataLoadedArrayBuffer(PassRefPtr<DOMArrayBuffer> arrayBuffer) override
    {
        m_loader.clear();
        if (m_client)
            m_client->didFetchDataLoadedArrayBuffer(arrayBuffer);
        m_buffer->didFetchDataLoadFinished();
    }
    void didFetchDataLoadedString(const String& str) override
    {
        m_loader.clear();
        if (m_client)
            m_client->didFetchDataLoadedString(str);
        m_buffer->didFetchDataLoadFinished();
    }
    void didFetchDataLoadedStream() override
    {
        m_loader.clear();
        if (m_client)
            m_client->didFetchDataLoadedStream();
        m_buffer->didFetchDataLoadFinished();
    }
    void didFetchDataLoadFailed() override
    {
        m_loader.clear();
        if (m_client)
            m_client->didFetchDataLoadFailed();
        m_buffer->didFetchDataLoadFinished();
    }

    void stop() override
    {
        if (m_loader) {
            m_loader->cancel();
            m_loader.clear();
            m_buffer->didFetchDataLoadFinished();
        }
    }

    Member<BodyStreamBuffer> m_buffer;
    Member<FetchDataLoader> m_loader;
    Member<FetchDataLoader::Client> m_client;
};

void BodyStreamBuffer::setDrainingStreamNotificationClient(DrainingStreamNotificationClient* client)
{
    ASSERT(!m_fetchDataLoader);
    ASSERT(!m_drainingStreamNotificationClient);
    m_drainingStreamNotificationClient = client;
}

void BodyStreamBuffer::startLoading(ExecutionContext* executionContext, FetchDataLoader* fetchDataLoader, FetchDataLoader::Client* client)
{
    ASSERT(!m_fetchDataLoader);
    auto holder = new LoaderHolder(executionContext, this, fetchDataLoader, client);
    m_fetchDataLoader = holder;
    holder->start(m_handle.get());
}

void BodyStreamBuffer::doDrainingStreamNotification()
{
    ASSERT(!m_fetchDataLoader);
    DrainingStreamNotificationClient* client = m_drainingStreamNotificationClient;
    m_drainingStreamNotificationClient.clear();
    if (client)
        client->didFetchDataLoadFinishedFromDrainingStream();
}

void BodyStreamBuffer::clearDrainingStreamNotification()
{
    ASSERT(!m_fetchDataLoader);
    m_drainingStreamNotificationClient.clear();
}

void BodyStreamBuffer::didFetchDataLoadFinished()
{
    ASSERT(m_fetchDataLoader);
    m_fetchDataLoader.clear();
    doDrainingStreamNotification();
}

DrainingBodyStreamBuffer::~DrainingBodyStreamBuffer()
{
    if (m_buffer)
        m_buffer->doDrainingStreamNotification();
}

void DrainingBodyStreamBuffer::startLoading(ExecutionContext* executionContext, FetchDataLoader* fetchDataLoader, FetchDataLoader::Client* client)
{
    if (!m_buffer)
        return;

    m_buffer->startLoading(executionContext, fetchDataLoader, client);
    m_buffer.clear();
}

BodyStreamBuffer* DrainingBodyStreamBuffer::leakBuffer()
{
    if (!m_buffer)
        return nullptr;

    m_buffer->clearDrainingStreamNotification();
    BodyStreamBuffer* buffer = m_buffer;
    m_buffer.clear();
    return buffer;
}

PassRefPtr<BlobDataHandle> DrainingBodyStreamBuffer::drainAsBlobDataHandle(FetchDataConsumerHandle::Reader::BlobSizePolicy blobSizePolicy)
{
    if (!m_buffer)
        return nullptr;

    RefPtr<BlobDataHandle> blobDataHandle = m_buffer->m_handle->obtainReader(nullptr)->drainAsBlobDataHandle(blobSizePolicy);
    if (!blobDataHandle)
        return nullptr;
    m_buffer->doDrainingStreamNotification();
    m_buffer.clear();
    return blobDataHandle.release();
}

DrainingBodyStreamBuffer::DrainingBodyStreamBuffer(BodyStreamBuffer* buffer, BodyStreamBuffer::DrainingStreamNotificationClient* client)
    : m_buffer(buffer)
{
    ASSERT(client);
    m_buffer->setDrainingStreamNotificationClient(client);
>>>>>>> miniblink49
}

} // namespace blink
