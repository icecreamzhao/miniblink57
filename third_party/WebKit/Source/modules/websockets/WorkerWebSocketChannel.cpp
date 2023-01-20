/*
 * Copyright (C) 2011, 2012 Google Inc.  All rights reserved.
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
#include "modules/websockets/WorkerWebSocketChannel.h"

=======
#include "config.h"
#include "modules/websockets/WorkerWebSocketChannel.h"

#include "bindings/core/v8/ScriptCallStackFactory.h"
#include "core/dom/CrossThreadTask.h"
>>>>>>> miniblink49
#include "core/dom/DOMArrayBuffer.h"
#include "core/dom/Document.h"
#include "core/dom/ExecutionContext.h"
#include "core/dom/ExecutionContextTask.h"
#include "core/fileapi/Blob.h"
<<<<<<< HEAD
=======
#include "core/inspector/ScriptCallFrame.h"
#include "core/inspector/ScriptCallStack.h"
>>>>>>> miniblink49
#include "core/workers/WorkerGlobalScope.h"
#include "core/workers/WorkerLoaderProxy.h"
#include "core/workers/WorkerThread.h"
#include "modules/websockets/DocumentWebSocketChannel.h"
<<<<<<< HEAD
#include "platform/WaitableEvent.h"
#include "platform/heap/SafePoint.h"
#include "public/platform/Platform.h"
#include "wtf/Assertions.h"
#include "wtf/Functional.h"
#include "wtf/PtrUtil.h"
#include "wtf/text/CString.h"
#include "wtf/text/WTFString.h"
#include "net/websocket/WebSocketChannelImpl.h"
#include <memory>
=======
#include "platform/heap/SafePoint.h"
#include "public/platform/Platform.h"
#include "public/platform/WebWaitableEvent.h"
#include "wtf/Assertions.h"
#include "wtf/Functional.h"
#include "wtf/MainThread.h"
#include "wtf/text/CString.h"
#include "wtf/text/WTFString.h"
>>>>>>> miniblink49

namespace blink {

typedef WorkerWebSocketChannel::Bridge Bridge;
typedef WorkerWebSocketChannel::Peer Peer;

// Created and destroyed on the worker thread. All setters of this class are
// called on the main thread, while all getters are called on the worker
// thread. signalWorkerThread() must be called before any getters are called.
<<<<<<< HEAD
class WebSocketChannelSyncHelper {
public:
    WebSocketChannelSyncHelper() { }
    ~WebSocketChannelSyncHelper() { }
=======
class WebSocketChannelSyncHelper : public GarbageCollectedFinalized<WebSocketChannelSyncHelper> {
public:
    static WebSocketChannelSyncHelper* create(PassOwnPtr<WebWaitableEvent> event)
    {
        return new WebSocketChannelSyncHelper(event);
    }

    ~WebSocketChannelSyncHelper()
    {
    }
>>>>>>> miniblink49

    // All setters are called on the main thread.
    void setConnectRequestResult(bool connectRequestResult)
    {
<<<<<<< HEAD
        DCHECK(isMainThread());
        m_connectRequestResult = connectRequestResult;
    }

    // All getters are called on the worker thread.
    bool connectRequestResult() const
    {
        DCHECK(!isMainThread());
=======
        m_connectRequestResult = connectRequestResult;
    }

    // All getter are called on the worker thread.
    bool connectRequestResult() const
    {
>>>>>>> miniblink49
        return m_connectRequestResult;
    }

    // This should be called after all setters are called and before any
    // getters are called.
    void signalWorkerThread()
    {
<<<<<<< HEAD
        DCHECK(isMainThread());
        m_event.signal();
    }

    void wait()
    {
        DCHECK(!isMainThread());
        m_event.wait();
    }

private:
    WaitableEvent m_event;
    bool m_connectRequestResult = false;
};

WorkerWebSocketChannel::WorkerWebSocketChannel(
    WorkerGlobalScope& workerGlobalScope,
    WebSocketChannelClient* client,
    std::unique_ptr<SourceLocation> location)
    : m_bridge(new Bridge(client, workerGlobalScope))
    , m_locationAtConnection(std::move(location))
{
=======
        m_event->signal();
    }
    void wait()
    {
        m_event->wait();
    }

    DEFINE_INLINE_TRACE() { }

private:
    explicit WebSocketChannelSyncHelper(PassOwnPtr<WebWaitableEvent> event)
        : m_event(event)
        , m_connectRequestResult(false)
    {
    }

    OwnPtr<WebWaitableEvent> m_event;
    bool m_connectRequestResult;
};

WorkerWebSocketChannel::WorkerWebSocketChannel(WorkerGlobalScope& workerGlobalScope, WebSocketChannelClient* client, const String& sourceURL, unsigned lineNumber)
    : m_bridge(new Bridge(client, workerGlobalScope))
    , m_sourceURLAtConnection(sourceURL)
    , m_lineNumberAtConnection(lineNumber)
{
    m_bridge->initialize(sourceURL, lineNumber);
>>>>>>> miniblink49
}

WorkerWebSocketChannel::~WorkerWebSocketChannel()
{
<<<<<<< HEAD
    DCHECK(!m_bridge);
=======
    ASSERT(!m_bridge);
>>>>>>> miniblink49
}

bool WorkerWebSocketChannel::connect(const KURL& url, const String& protocol)
{
<<<<<<< HEAD
    DCHECK(m_bridge);
    return m_bridge->connect(m_locationAtConnection->clone(), url, protocol);
=======
    ASSERT(m_bridge);
    return m_bridge->connect(url, protocol);
>>>>>>> miniblink49
}

void WorkerWebSocketChannel::send(const CString& message)
{
<<<<<<< HEAD
    DCHECK(m_bridge);
    m_bridge->send(message);
}

void WorkerWebSocketChannel::send(const DOMArrayBuffer& binaryData,
    unsigned byteOffset,
    unsigned byteLength)
{
    DCHECK(m_bridge);
=======
    ASSERT(m_bridge);
    m_bridge->send(message);
}

void WorkerWebSocketChannel::send(const DOMArrayBuffer& binaryData, unsigned byteOffset, unsigned byteLength)
{
    ASSERT(m_bridge);
>>>>>>> miniblink49
    m_bridge->send(binaryData, byteOffset, byteLength);
}

void WorkerWebSocketChannel::send(PassRefPtr<BlobDataHandle> blobData)
{
<<<<<<< HEAD
    DCHECK(m_bridge);
    m_bridge->send(std::move(blobData));
=======
    ASSERT(m_bridge);
    m_bridge->send(blobData);
>>>>>>> miniblink49
}

void WorkerWebSocketChannel::close(int code, const String& reason)
{
<<<<<<< HEAD
    DCHECK(m_bridge);
    m_bridge->close(code, reason);
}

void WorkerWebSocketChannel::fail(const String& reason,
    MessageLevel level,
    std::unique_ptr<SourceLocation> location)
=======
    ASSERT(m_bridge);
    m_bridge->close(code, reason);
}

void WorkerWebSocketChannel::fail(const String& reason, MessageLevel level, const String& sourceURL, unsigned lineNumber)
>>>>>>> miniblink49
{
    if (!m_bridge)
        return;

<<<<<<< HEAD
    std::unique_ptr<SourceLocation> capturedLocation = SourceLocation::capture();
    if (!capturedLocation->isUnknown()) {
        // If we are in JavaScript context, use the current location instead
        // of passed one - it's more precise.
        m_bridge->fail(reason, level, std::move(capturedLocation));
    } else if (location->isUnknown()) {
        // No information is specified by the caller - use the url
        // and the line number at the connection.
        m_bridge->fail(reason, level, m_locationAtConnection->clone());
    } else {
        // Use the specified information.
        m_bridge->fail(reason, level, std::move(location));
=======
    RefPtrWillBeRawPtr<ScriptCallStack> callStack = createScriptCallStack(1, true);
    if (callStack && callStack->size())  {
        // In order to emulate the ConsoleMessage behavior,
        // we should ignore the specified url and line number if
        // we can get the JavaScript context.
        m_bridge->fail(reason, level, callStack->at(0).sourceURL(), callStack->at(0).lineNumber());
    } else if (sourceURL.isEmpty() && !lineNumber) {
        // No information is specified by the caller - use the url
        // and the line number at the connection.
        m_bridge->fail(reason, level, m_sourceURLAtConnection, m_lineNumberAtConnection);
    } else {
        // Use the specified information.
        m_bridge->fail(reason, level, sourceURL, lineNumber);
>>>>>>> miniblink49
    }
}

void WorkerWebSocketChannel::disconnect()
{
    m_bridge->disconnect();
    m_bridge.clear();
}

DEFINE_TRACE(WorkerWebSocketChannel)
{
    visitor->trace(m_bridge);
    WebSocketChannel::trace(visitor);
}

<<<<<<< HEAD
Peer::Peer(Bridge* bridge,
    PassRefPtr<WorkerLoaderProxy> loaderProxy,
    WorkerThreadLifecycleContext* workerThreadLifecycleContext)
    : WorkerThreadLifecycleObserver(workerThreadLifecycleContext)
    , m_bridge(bridge)
    , m_loaderProxy(loaderProxy)
    , m_mainWebSocketChannel(nullptr)
{
    DCHECK(isMainThread());
=======
Peer::Peer(Bridge* bridge, PassRefPtr<WorkerLoaderProxy> loaderProxy, WebSocketChannelSyncHelper* syncHelper)
    : m_bridge(bridge)
    , m_loaderProxy(loaderProxy)
    , m_mainWebSocketChannel(nullptr)
    , m_syncHelper(syncHelper)
{
    ASSERT(!isMainThread());
>>>>>>> miniblink49
}

Peer::~Peer()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
}

bool Peer::initialize(std::unique_ptr<SourceLocation> location, ExecutionContext* context)
{
    DCHECK(isMainThread());
    if (wasContextDestroyedBeforeObserverCreation())
        return false;
    Document* document = toDocument(context);
    //m_mainWebSocketChannel = DocumentWebSocketChannel::create(document, this, std::move(location));
    m_mainWebSocketChannel = net::WebSocketChannelImpl::create(document, this, location->url(), location->lineNumber());
    return true;
}

bool Peer::connect(const KURL& url, const String& protocol)
{
    DCHECK(isMainThread());
    if (!m_mainWebSocketChannel)
        return false;
    return m_mainWebSocketChannel->connect(url, protocol);
}

void Peer::sendTextAsCharVector(std::unique_ptr<Vector<char>> data)
{
    DCHECK(isMainThread());
    if (m_mainWebSocketChannel)
        m_mainWebSocketChannel->sendTextAsCharVector(std::move(data));
}

void Peer::sendBinaryAsCharVector(std::unique_ptr<Vector<char>> data)
{
    DCHECK(isMainThread());
    if (m_mainWebSocketChannel)
        m_mainWebSocketChannel->sendBinaryAsCharVector(std::move(data));
=======
    ASSERT(!isMainThread());
}

void Peer::initialize(const String& sourceURL, unsigned lineNumber, ExecutionContext* context)
{
    ASSERT(isMainThread());
    Document* document = toDocument(context);
    m_mainWebSocketChannel = DocumentWebSocketChannel::create(document, this, sourceURL, lineNumber);
    m_syncHelper->signalWorkerThread();
}

void Peer::connect(const KURL& url, const String& protocol)
{
    ASSERT(isMainThread());
    ASSERT(m_syncHelper);
    if (!m_mainWebSocketChannel) {
        m_syncHelper->setConnectRequestResult(false);
    } else {
        bool connectRequestResult = m_mainWebSocketChannel->connect(url, protocol);
        m_syncHelper->setConnectRequestResult(connectRequestResult);
    }
    m_syncHelper->signalWorkerThread();
}

void Peer::sendTextAsCharVector(PassOwnPtr<Vector<char>> data)
{
    ASSERT(isMainThread());
    if (m_mainWebSocketChannel)
        m_mainWebSocketChannel->sendTextAsCharVector(data);
}

void Peer::sendBinaryAsCharVector(PassOwnPtr<Vector<char>> data)
{
    ASSERT(isMainThread());
    if (m_mainWebSocketChannel)
        m_mainWebSocketChannel->sendBinaryAsCharVector(data);
>>>>>>> miniblink49
}

void Peer::sendBlob(PassRefPtr<BlobDataHandle> blobData)
{
<<<<<<< HEAD
    DCHECK(isMainThread());
    if (m_mainWebSocketChannel)
        m_mainWebSocketChannel->send(std::move(blobData));
=======
    ASSERT(isMainThread());
    if (m_mainWebSocketChannel)
        m_mainWebSocketChannel->send(blobData);
>>>>>>> miniblink49
}

void Peer::close(int code, const String& reason)
{
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
    ASSERT(m_syncHelper);
>>>>>>> miniblink49
    if (!m_mainWebSocketChannel)
        return;
    m_mainWebSocketChannel->close(code, reason);
}

<<<<<<< HEAD
void Peer::fail(const String& reason,
    MessageLevel level,
    std::unique_ptr<SourceLocation> location)
{
    DCHECK(isMainThread());
    if (!m_mainWebSocketChannel)
        return;
    m_mainWebSocketChannel->fail(reason, level, std::move(location));
=======
void Peer::fail(const String& reason, MessageLevel level, const String& sourceURL, unsigned lineNumber)
{
    ASSERT(isMainThread());
    ASSERT(m_syncHelper);
    if (!m_mainWebSocketChannel)
        return;
    m_mainWebSocketChannel->fail(reason, level, sourceURL, lineNumber);
>>>>>>> miniblink49
}

void Peer::disconnect()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
    if (!m_mainWebSocketChannel)
        return;
    m_mainWebSocketChannel->disconnect();
    m_mainWebSocketChannel = nullptr;
}

static void workerGlobalScopeDidConnect(Bridge* bridge,
    const String& subprotocol,
    const String& extensions)
{
    if (bridge && bridge->client())
=======
    ASSERT(isMainThread());
    ASSERT(m_syncHelper);
    if (m_mainWebSocketChannel) {
        m_mainWebSocketChannel->disconnect();
        m_mainWebSocketChannel = nullptr;
    }
    m_syncHelper->signalWorkerThread();
}

static void workerGlobalScopeDidConnect(Bridge* bridge, const String& subprotocol, const String& extensions, ExecutionContext* context)
{
    ASSERT_UNUSED(context, context->isWorkerGlobalScope());
    if (bridge->client())
>>>>>>> miniblink49
        bridge->client()->didConnect(subprotocol, extensions);
}

void Peer::didConnect(const String& subprotocol, const String& extensions)
{
<<<<<<< HEAD
    DCHECK(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(
        BLINK_FROM_HERE, crossThreadBind(&workerGlobalScopeDidConnect, m_bridge, subprotocol, extensions));
}

static void workerGlobalScopeDidReceiveTextMessage(Bridge* bridge,
    const String& payload)
{
    if (bridge && bridge->client())
=======
    ASSERT(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(createCrossThreadTask(&workerGlobalScopeDidConnect, m_bridge, subprotocol, extensions));
}

static void workerGlobalScopeDidReceiveTextMessage(Bridge* bridge, const String& payload, ExecutionContext* context)
{
    ASSERT_UNUSED(context, context->isWorkerGlobalScope());
    if (bridge->client())
>>>>>>> miniblink49
        bridge->client()->didReceiveTextMessage(payload);
}

void Peer::didReceiveTextMessage(const String& payload)
{
<<<<<<< HEAD
    DCHECK(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(
        BLINK_FROM_HERE, crossThreadBind(&workerGlobalScopeDidReceiveTextMessage, m_bridge, payload));
}

static void workerGlobalScopeDidReceiveBinaryMessage(
    Bridge* bridge,
    std::unique_ptr<Vector<char>> payload)
{
    if (bridge && bridge->client())
        bridge->client()->didReceiveBinaryMessage(std::move(payload));
}

void Peer::didReceiveBinaryMessage(std::unique_ptr<Vector<char>> payload)
{
    DCHECK(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(
        BLINK_FROM_HERE,
        crossThreadBind(&workerGlobalScopeDidReceiveBinaryMessage, m_bridge,
            WTF::passed(std::move(payload))));
}

static void workerGlobalScopeDidConsumeBufferedAmount(Bridge* bridge,
    uint64_t consumed)
{
    if (bridge && bridge->client())
=======
    ASSERT(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(createCrossThreadTask(&workerGlobalScopeDidReceiveTextMessage, m_bridge, payload));
}

static void workerGlobalScopeDidReceiveBinaryMessage(Bridge* bridge, PassOwnPtr<Vector<char>> payload, ExecutionContext* context)
{
    ASSERT_UNUSED(context, context->isWorkerGlobalScope());
    if (bridge->client())
        bridge->client()->didReceiveBinaryMessage(payload);
}

void Peer::didReceiveBinaryMessage(PassOwnPtr<Vector<char>> payload)
{
    ASSERT(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(createCrossThreadTask(&workerGlobalScopeDidReceiveBinaryMessage, m_bridge, payload));
}

static void workerGlobalScopeDidConsumeBufferedAmount(Bridge* bridge, uint64_t consumed, ExecutionContext* context)
{
    ASSERT_UNUSED(context, context->isWorkerGlobalScope());
    if (bridge->client())
>>>>>>> miniblink49
        bridge->client()->didConsumeBufferedAmount(consumed);
}

void Peer::didConsumeBufferedAmount(uint64_t consumed)
{
<<<<<<< HEAD
    DCHECK(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(
        BLINK_FROM_HERE,
        crossThreadBind(&workerGlobalScopeDidConsumeBufferedAmount, m_bridge,
            consumed));
}

static void workerGlobalScopeDidStartClosingHandshake(Bridge* bridge)
{
    if (bridge && bridge->client())
=======
    ASSERT(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(createCrossThreadTask(&workerGlobalScopeDidConsumeBufferedAmount, m_bridge, consumed));
}

static void workerGlobalScopeDidStartClosingHandshake(Bridge* bridge, ExecutionContext* context)
{
    ASSERT_UNUSED(context, context->isWorkerGlobalScope());
    if (bridge->client())
>>>>>>> miniblink49
        bridge->client()->didStartClosingHandshake();
}

void Peer::didStartClosingHandshake()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(
        BLINK_FROM_HERE,
        crossThreadBind(&workerGlobalScopeDidStartClosingHandshake, m_bridge));
}

static void workerGlobalScopeDidClose(
    Bridge* bridge,
    WebSocketChannelClient::ClosingHandshakeCompletionStatus
        closingHandshakeCompletion,
    unsigned short code,
    const String& reason)
{
    if (bridge && bridge->client())
        bridge->client()->didClose(closingHandshakeCompletion, code, reason);
}

void Peer::didClose(ClosingHandshakeCompletionStatus closingHandshakeCompletion,
    unsigned short code,
    const String& reason)
{
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(createCrossThreadTask(&workerGlobalScopeDidStartClosingHandshake, m_bridge));
}

static void workerGlobalScopeDidClose(Bridge* bridge, WebSocketChannelClient::ClosingHandshakeCompletionStatus closingHandshakeCompletion, unsigned short code, const String& reason, ExecutionContext* context)
{
    ASSERT_UNUSED(context, context->isWorkerGlobalScope());
    if (bridge->client())
        bridge->client()->didClose(closingHandshakeCompletion, code, reason);
}

void Peer::didClose(ClosingHandshakeCompletionStatus closingHandshakeCompletion, unsigned short code, const String& reason)
{
    ASSERT(isMainThread());
>>>>>>> miniblink49
    if (m_mainWebSocketChannel) {
        m_mainWebSocketChannel->disconnect();
        m_mainWebSocketChannel = nullptr;
    }
<<<<<<< HEAD
    m_loaderProxy->postTaskToWorkerGlobalScope(
        BLINK_FROM_HERE,
        crossThreadBind(&workerGlobalScopeDidClose, m_bridge,
            closingHandshakeCompletion, code, reason));
}

static void workerGlobalScopeDidError(Bridge* bridge)
{
    if (bridge && bridge->client())
=======
    m_loaderProxy->postTaskToWorkerGlobalScope(createCrossThreadTask(&workerGlobalScopeDidClose, m_bridge, closingHandshakeCompletion, code, reason));
}

static void workerGlobalScopeDidError(Bridge* bridge, ExecutionContext* context)
{
    ASSERT_UNUSED(context, context->isWorkerGlobalScope());
    if (bridge->client())
>>>>>>> miniblink49
        bridge->client()->didError();
}

void Peer::didError()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(
        BLINK_FROM_HERE, crossThreadBind(&workerGlobalScopeDidError, m_bridge));
}

void Peer::contextDestroyed(WorkerThreadLifecycleContext*)
{
    DCHECK(isMainThread());
    if (m_mainWebSocketChannel) {
        m_mainWebSocketChannel->disconnect();
        m_mainWebSocketChannel = nullptr;
    }
    m_bridge = nullptr;
=======
    ASSERT(isMainThread());
    m_loaderProxy->postTaskToWorkerGlobalScope(createCrossThreadTask(&workerGlobalScopeDidError, m_bridge));
>>>>>>> miniblink49
}

DEFINE_TRACE(Peer)
{
<<<<<<< HEAD
    visitor->trace(m_mainWebSocketChannel);
    WebSocketChannelClient::trace(visitor);
    WorkerThreadLifecycleObserver::trace(visitor);
}

Bridge::Bridge(WebSocketChannelClient* client,
    WorkerGlobalScope& workerGlobalScope)
    : m_client(client)
    , m_workerGlobalScope(workerGlobalScope)
    , m_loaderProxy(m_workerGlobalScope->thread()->workerLoaderProxy())
=======
    visitor->trace(m_bridge);
    visitor->trace(m_mainWebSocketChannel);
    visitor->trace(m_syncHelper);
    WebSocketChannelClient::trace(visitor);
}

Bridge::Bridge(WebSocketChannelClient* client, WorkerGlobalScope& workerGlobalScope)
    : m_client(client)
    , m_workerGlobalScope(workerGlobalScope)
    , m_loaderProxy(m_workerGlobalScope->thread()->workerLoaderProxy())
    , m_syncHelper(WebSocketChannelSyncHelper::create(adoptPtr(Platform::current()->createWaitableEvent())))
    , m_peer(new Peer(this, m_loaderProxy, m_syncHelper))
>>>>>>> miniblink49
{
}

Bridge::~Bridge()
{
<<<<<<< HEAD
    DCHECK(!m_peer);
}

void Bridge::connectOnMainThread(
    std::unique_ptr<SourceLocation> location,
    WorkerThreadLifecycleContext* workerThreadLifecycleContext,
    const KURL& url,
    const String& protocol,
    WebSocketChannelSyncHelper* syncHelper,
    ExecutionContext* context)
{
    DCHECK(isMainThread());
    DCHECK(!m_peer);
    Peer* peer = new Peer(this, m_loaderProxy, workerThreadLifecycleContext);
    if (peer->initialize(std::move(location), context)) {
        m_peer = peer;
        syncHelper->setConnectRequestResult(m_peer->connect(url, protocol));
    }
    syncHelper->signalWorkerThread();
}

bool Bridge::connect(std::unique_ptr<SourceLocation> location,
    const KURL& url,
    const String& protocol)
{
    // Wait for completion of the task on the main thread because the mixed
    // content check must synchronously be conducted.
    WebSocketChannelSyncHelper syncHelper;
    m_loaderProxy->postTaskToLoader(
        BLINK_FROM_HERE,
        createCrossThreadTask(
            &Bridge::connectOnMainThread, wrapCrossThreadPersistent(this),
            WTF::passed(location->clone()),
            wrapCrossThreadPersistent(
                m_workerGlobalScope->thread()->getWorkerThreadLifecycleContext()),
            url, protocol, crossThreadUnretained(&syncHelper)));
    syncHelper.wait();
    return syncHelper.connectRequestResult();
=======
    ASSERT(!m_peer);
}

void Bridge::initialize(const String& sourceURL, unsigned lineNumber)
{
    if (!waitForMethodCompletion(createCrossThreadTask(&Peer::initialize, m_peer.get(), sourceURL, lineNumber))) {
        // The worker thread has been signalled to shutdown before method completion.
        disconnect();
    }
}

bool Bridge::connect(const KURL& url, const String& protocol)
{
    if (!m_peer)
        return false;

    if (!waitForMethodCompletion(createCrossThreadTask(&Peer::connect, m_peer.get(), url, protocol)))
        return false;

    return m_syncHelper->connectRequestResult();
>>>>>>> miniblink49
}

void Bridge::send(const CString& message)
{
<<<<<<< HEAD
    DCHECK(m_peer);
    std::unique_ptr<Vector<char>> data = WTF::wrapUnique(new Vector<char>(message.length()));
    if (message.length())
        memcpy(data->data(), static_cast<const char*>(message.data()),
            message.length());

    m_loaderProxy->postTaskToLoader(
        BLINK_FROM_HERE,
        createCrossThreadTask(&Peer::sendTextAsCharVector, m_peer,
            WTF::passed(std::move(data))));
}

void Bridge::send(const DOMArrayBuffer& binaryData,
    unsigned byteOffset,
    unsigned byteLength)
{
    DCHECK(m_peer);
    // ArrayBuffer isn't thread-safe, hence the content of ArrayBuffer is copied
    // into Vector<char>.
    std::unique_ptr<Vector<char>> data = WTF::makeUnique<Vector<char>>(byteLength);
    if (binaryData.byteLength())
        memcpy(data->data(),
            static_cast<const char*>(binaryData.data()) + byteOffset,
            byteLength);

    m_loaderProxy->postTaskToLoader(
        BLINK_FROM_HERE,
        createCrossThreadTask(&Peer::sendBinaryAsCharVector, m_peer,
            WTF::passed(std::move(data))));
=======
    ASSERT(m_peer);
    OwnPtr<Vector<char>> data = adoptPtr(new Vector<char>(message.length()));
    if (message.length())
        memcpy(data->data(), static_cast<const char*>(message.data()), message.length());

    m_loaderProxy->postTaskToLoader(createCrossThreadTask(&Peer::sendTextAsCharVector, m_peer.get(), data.release()));
}

void Bridge::send(const DOMArrayBuffer& binaryData, unsigned byteOffset, unsigned byteLength)
{
    ASSERT(m_peer);
    // ArrayBuffer isn't thread-safe, hence the content of ArrayBuffer is copied into Vector<char>.
    OwnPtr<Vector<char>> data = adoptPtr(new Vector<char>(byteLength));
    if (binaryData.byteLength())
        memcpy(data->data(), static_cast<const char*>(binaryData.data()) + byteOffset, byteLength);

    m_loaderProxy->postTaskToLoader(createCrossThreadTask(&Peer::sendBinaryAsCharVector, m_peer.get(), data.release()));
>>>>>>> miniblink49
}

void Bridge::send(PassRefPtr<BlobDataHandle> data)
{
<<<<<<< HEAD
    DCHECK(m_peer);
    m_loaderProxy->postTaskToLoader(
        BLINK_FROM_HERE,
        createCrossThreadTask(&Peer::sendBlob, m_peer, std::move(data)));
=======
    ASSERT(m_peer);
    m_loaderProxy->postTaskToLoader(createCrossThreadTask(&Peer::sendBlob, m_peer.get(), data));
>>>>>>> miniblink49
}

void Bridge::close(int code, const String& reason)
{
<<<<<<< HEAD
    DCHECK(m_peer);
    m_loaderProxy->postTaskToLoader(
        BLINK_FROM_HERE,
        createCrossThreadTask(&Peer::close, m_peer, code, reason));
}

void Bridge::fail(const String& reason,
    MessageLevel level,
    std::unique_ptr<SourceLocation> location)
{
    DCHECK(m_peer);
    m_loaderProxy->postTaskToLoader(
        BLINK_FROM_HERE, createCrossThreadTask(&Peer::fail, m_peer, reason, level, WTF::passed(location->clone())));
=======
    ASSERT(m_peer);
    m_loaderProxy->postTaskToLoader(createCrossThreadTask(&Peer::close, m_peer.get(), code, reason));
}

void Bridge::fail(const String& reason, MessageLevel level, const String& sourceURL, unsigned lineNumber)
{
    ASSERT(m_peer);
    m_loaderProxy->postTaskToLoader(createCrossThreadTask(&Peer::fail, m_peer.get(), reason, level, sourceURL, lineNumber));
>>>>>>> miniblink49
}

void Bridge::disconnect()
{
    if (!m_peer)
        return;

<<<<<<< HEAD
    m_loaderProxy->postTaskToLoader(
        BLINK_FROM_HERE, createCrossThreadTask(&Peer::disconnect, m_peer));

    m_client = nullptr;
    m_peer = nullptr;
    m_workerGlobalScope.clear();
}

=======
    waitForMethodCompletion(createCrossThreadTask(&Peer::disconnect, m_peer.get()));
    // Here |m_peer| is detached from the main thread and we can delete it.

    m_client = nullptr;
    m_peer = nullptr;
    m_syncHelper = nullptr;
    // We won't use this any more.
    m_workerGlobalScope.clear();
}

// Caller of this function should hold a reference to the bridge, because this function may call WebSocket::didClose() in the end,
// which causes the bridge to get disconnected from the WebSocket and deleted if there is no other reference.
bool Bridge::waitForMethodCompletion(PassOwnPtr<ExecutionContextTask> task)
{
    ASSERT(m_workerGlobalScope);
    ASSERT(m_syncHelper);

    m_loaderProxy->postTaskToLoader(task);

    // We wait for the syncHelper event even if a shutdown event is fired.
    // See https://codereview.chromium.org/267323004/#msg43 for why we need to wait this.
    SafePointScope scope(ThreadState::HeapPointersOnStack);
    m_syncHelper->wait();
    // This is checking whether a shutdown event is fired or not.
    return !m_workerGlobalScope->thread()->terminated();
}

>>>>>>> miniblink49
DEFINE_TRACE(Bridge)
{
    visitor->trace(m_client);
    visitor->trace(m_workerGlobalScope);
<<<<<<< HEAD
=======
    visitor->trace(m_syncHelper);
    visitor->trace(m_peer);
>>>>>>> miniblink49
}

} // namespace blink
