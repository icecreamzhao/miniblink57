/*
 * Copyright (C) 2011 Google Inc.  All rights reserved.
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

#ifndef WorkerWebSocketChannel_h
#define WorkerWebSocketChannel_h

<<<<<<< HEAD
#include "bindings/core/v8/SourceLocation.h"
#include "core/workers/WorkerThreadLifecycleObserver.h"
#include "modules/websockets/WebSocketChannel.h"
#include "modules/websockets/WebSocketChannelClient.h"
#include "platform/heap/Handle.h"
#include "public/platform/WebTraceLocation.h"
#include "wtf/Assertions.h"
#include "wtf/Forward.h"
#include "wtf/RefPtr.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"
#include <memory>
=======
#include "core/frame/ConsoleTypes.h"
#include "modules/websockets/WebSocketChannel.h"
#include "modules/websockets/WebSocketChannelClient.h"
#include "platform/heap/Handle.h"
#include "wtf/Assertions.h"
#include "wtf/Forward.h"
#include "wtf/OwnPtr.h"
#include "wtf/RefPtr.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"
>>>>>>> miniblink49
#include <stdint.h>

namespace blink {

class BlobDataHandle;
class KURL;
class ExecutionContext;
<<<<<<< HEAD
=======
class ExecutionContextTask;
>>>>>>> miniblink49
class WebSocketChannelSyncHelper;
class WorkerGlobalScope;
class WorkerLoaderProxy;

class WorkerWebSocketChannel final : public WebSocketChannel {
    WTF_MAKE_NONCOPYABLE(WorkerWebSocketChannel);
<<<<<<< HEAD

public:
    static WebSocketChannel* create(WorkerGlobalScope& workerGlobalScope,
        WebSocketChannelClient* client,
        std::unique_ptr<SourceLocation> location)
    {
        return new WorkerWebSocketChannel(workerGlobalScope, client,
            std::move(location));
=======
public:
    static WebSocketChannel* create(WorkerGlobalScope& workerGlobalScope, WebSocketChannelClient* client, const String& sourceURL, unsigned lineNumber)
    {
        return new WorkerWebSocketChannel(workerGlobalScope, client, sourceURL, lineNumber);
>>>>>>> miniblink49
    }
    ~WorkerWebSocketChannel() override;

    // WebSocketChannel functions.
    bool connect(const KURL&, const String& protocol) override;
    void send(const CString&) override;
<<<<<<< HEAD
    void send(const DOMArrayBuffer&,
        unsigned byteOffset,
        unsigned byteLength) override;
    void send(PassRefPtr<BlobDataHandle>) override;
    void sendTextAsCharVector(std::unique_ptr<Vector<char>>) override
    {
        NOTREACHED();
    }
    void sendBinaryAsCharVector(std::unique_ptr<Vector<char>>) override
    {
        NOTREACHED();
    }
    void close(int code, const String& reason) override;
    void fail(const String& reason,
        MessageLevel,
        std::unique_ptr<SourceLocation>) override;
=======
    void send(const DOMArrayBuffer&, unsigned byteOffset, unsigned byteLength) override;
    void send(PassRefPtr<BlobDataHandle>) override;
    void sendTextAsCharVector(PassOwnPtr<Vector<char>>) override
    {
        ASSERT_NOT_REACHED();
    }
    void sendBinaryAsCharVector(PassOwnPtr<Vector<char>>) override
    {
        ASSERT_NOT_REACHED();
    }
    void close(int code, const String& reason) override;
    void fail(const String& reason, MessageLevel, const String&, unsigned) override;
>>>>>>> miniblink49
    void disconnect() override; // Will suppress didClose().

    DECLARE_VIRTUAL_TRACE();

    class Bridge;
<<<<<<< HEAD
    // Allocated and used in the main thread.
    class Peer final : public GarbageCollectedFinalized<Peer>,
                       public WebSocketChannelClient,
                       public WorkerThreadLifecycleObserver {
        USING_GARBAGE_COLLECTED_MIXIN(Peer);
        WTF_MAKE_NONCOPYABLE(Peer);

    public:
        Peer(Bridge*, PassRefPtr<WorkerLoaderProxy>, WorkerThreadLifecycleContext*);
        ~Peer() override;

        // SourceLocation parameter may be shown when the connection fails.
        bool initialize(std::unique_ptr<SourceLocation>, ExecutionContext*);

        bool connect(const KURL&, const String& protocol);
        void sendTextAsCharVector(std::unique_ptr<Vector<char>>);
        void sendBinaryAsCharVector(std::unique_ptr<Vector<char>>);
        void sendBlob(PassRefPtr<BlobDataHandle>);
        void close(int code, const String& reason);
        void fail(const String& reason,
            MessageLevel,
            std::unique_ptr<SourceLocation>);
        void disconnect();

        DECLARE_VIRTUAL_TRACE();
        // Promptly clear connection to bridge + loader proxy.
        EAGERLY_FINALIZE();

        // WebSocketChannelClient functions.
        void didConnect(const String& subprotocol,
            const String& extensions) override;
        void didReceiveTextMessage(const String& payload) override;
        void didReceiveBinaryMessage(std::unique_ptr<Vector<char>>) override;
        void didConsumeBufferedAmount(uint64_t) override;
        void didStartClosingHandshake() override;
        void didClose(ClosingHandshakeCompletionStatus,
            unsigned short code,
            const String& reason) override;
        void didError() override;

        // WorkerThreadLifecycleObserver function.
        void contextDestroyed(WorkerThreadLifecycleContext*) override;

    private:
        CrossThreadWeakPersistent<Bridge> m_bridge;
        RefPtr<WorkerLoaderProxy> m_loaderProxy;
        Member<WebSocketChannel> m_mainWebSocketChannel;
=======
    // Allocated in the worker thread, but used in the main thread.
    class Peer final : public GarbageCollectedFinalized<Peer>, public WebSocketChannelClient {
        USING_GARBAGE_COLLECTED_MIXIN(Peer);
        WTF_MAKE_NONCOPYABLE(Peer);
    public:
        Peer(Bridge*, PassRefPtr<WorkerLoaderProxy>, WebSocketChannelSyncHelper*);
        ~Peer() override;

        // sourceURLAtConnection and lineNumberAtConnection parameters may
        // be shown when the connection fails.
        void initialize(const String& sourceURLAtConnection, unsigned lineNumberAtConnection, ExecutionContext*);

        void connect(const KURL&, const String& protocol);
        void sendTextAsCharVector(PassOwnPtr<Vector<char>>);
        void sendBinaryAsCharVector(PassOwnPtr<Vector<char>>);
        void sendBlob(PassRefPtr<BlobDataHandle>);
        void close(int code, const String& reason);
        void fail(const String& reason, MessageLevel, const String& sourceURL, unsigned lineNumber);
        void disconnect();

        DECLARE_VIRTUAL_TRACE();

        // WebSocketChannelClient functions.
        void didConnect(const String& subprotocol, const String& extensions) override;
        void didReceiveTextMessage(const String& payload) override;
        void didReceiveBinaryMessage(PassOwnPtr<Vector<char>>) override;
        void didConsumeBufferedAmount(uint64_t) override;
        void didStartClosingHandshake() override;
        void didClose(ClosingHandshakeCompletionStatus, unsigned short code, const String& reason) override;
        void didError() override;

    private:
        Member<Bridge> m_bridge;
        RefPtr<WorkerLoaderProxy> m_loaderProxy;
        Member<WebSocketChannel> m_mainWebSocketChannel;
        Member<WebSocketChannelSyncHelper> m_syncHelper;
>>>>>>> miniblink49
    };

    // Bridge for Peer. Running on the worker thread.
    class Bridge final : public GarbageCollectedFinalized<Bridge> {
        WTF_MAKE_NONCOPYABLE(Bridge);
<<<<<<< HEAD

    public:
        Bridge(WebSocketChannelClient*, WorkerGlobalScope&);
        ~Bridge();

        // SourceLocation parameter may be shown when the connection fails.
        bool connect(std::unique_ptr<SourceLocation>,
            const KURL&,
            const String& protocol);

=======
    public:
        Bridge(WebSocketChannelClient*, WorkerGlobalScope&);
        ~Bridge();
        // sourceURLAtConnection and lineNumberAtConnection parameters may
        // be shown when the connection fails.
        void initialize(const String& sourceURLAtConnection, unsigned lineNumberAtConnection);
        bool connect(const KURL&, const String& protocol);
>>>>>>> miniblink49
        void send(const CString& message);
        void send(const DOMArrayBuffer&, unsigned byteOffset, unsigned byteLength);
        void send(PassRefPtr<BlobDataHandle>);
        void close(int code, const String& reason);
<<<<<<< HEAD
        void fail(const String& reason,
            MessageLevel,
            std::unique_ptr<SourceLocation>);
        void disconnect();

        void connectOnMainThread(std::unique_ptr<SourceLocation>,
            WorkerThreadLifecycleContext*,
            const KURL&,
            const String& protocol,
            WebSocketChannelSyncHelper*,
            ExecutionContext*);

=======
        void fail(const String& reason, MessageLevel, const String& sourceURL, unsigned lineNumber);
        void disconnect();

>>>>>>> miniblink49
        // Returns null when |disconnect| has already been called.
        WebSocketChannelClient* client() { return m_client; }

        DECLARE_TRACE();
<<<<<<< HEAD
        // Promptly clear connection to peer + loader proxy.
        EAGERLY_FINALIZE();

    private:
        Member<WebSocketChannelClient> m_client;
        Member<WorkerGlobalScope> m_workerGlobalScope;
        RefPtr<WorkerLoaderProxy> m_loaderProxy;
        CrossThreadPersistent<Peer> m_peer;
    };

private:
    WorkerWebSocketChannel(WorkerGlobalScope&,
        WebSocketChannelClient*,
        std::unique_ptr<SourceLocation>);

    Member<Bridge> m_bridge;
    std::unique_ptr<SourceLocation> m_locationAtConnection;
=======

    private:
        // Returns false if shutdown event is received before method completion.
        bool waitForMethodCompletion(PassOwnPtr<ExecutionContextTask>);

        Member<WebSocketChannelClient> m_client;
        RefPtrWillBeMember<WorkerGlobalScope> m_workerGlobalScope;
        RefPtr<WorkerLoaderProxy> m_loaderProxy;
        Member<WebSocketChannelSyncHelper> m_syncHelper;
        Member<Peer> m_peer;
    };

private:
    WorkerWebSocketChannel(WorkerGlobalScope&, WebSocketChannelClient*, const String& sourceURL, unsigned lineNumber);

    Member<Bridge> m_bridge;
    String m_sourceURLAtConnection;
    unsigned m_lineNumberAtConnection;
>>>>>>> miniblink49
};

} // namespace blink

#endif // WorkerWebSocketChannel_h
