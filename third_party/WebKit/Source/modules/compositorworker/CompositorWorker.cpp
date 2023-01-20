// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/compositorworker/CompositorWorker.h"

#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/CompositorProxyClient.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/frame/LocalFrame.h"
#include "core/page/ChromeClient.h"
#include "core/workers/WorkerClients.h"
#include "modules/EventTargetModules.h"
#include "modules/compositorworker/CompositorWorkerMessagingProxy.h"
#include "modules/compositorworker/CompositorWorkerThread.h"
=======
#include "config.h"
#include "modules/compositorworker/CompositorWorker.h"

#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/workers/WorkerClients.h"
#include "modules/EventTargetModules.h"
#include "modules/compositorworker/CompositorWorkerMessagingProxy.h"
#include "wtf/MainThread.h"
>>>>>>> miniblink49

namespace blink {

inline CompositorWorker::CompositorWorker(ExecutionContext* context)
    : InProcessWorkerBase(context)
{
}

<<<<<<< HEAD
CompositorWorker* CompositorWorker::create(ExecutionContext* context,
    const String& url,
    ExceptionState& exceptionState)
=======
PassRefPtrWillBeRawPtr<CompositorWorker> CompositorWorker::create(ExecutionContext* context, const String& url, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    ASSERT(isMainThread());
    Document* document = toDocument(context);
    if (!document->page()) {
<<<<<<< HEAD
        exceptionState.throwDOMException(InvalidAccessError,
            "The context provided is invalid.");
        return nullptr;
    }
    CompositorWorker* worker = new CompositorWorker(context);

    // Ensure the compositor worker backing thread is ready before we try to
    // initialize the CompositorWorker so that we can construct oilpan
    // objects on the compositor thread referenced from the worker clients.
    CompositorWorkerThread::ensureSharedBackingThread();

    if (worker->initialize(context, url, exceptionState))
        return worker;
=======
        exceptionState.throwDOMException(InvalidAccessError, "The context provided is invalid.");
        return nullptr;
    }
    RefPtrWillBeRawPtr<CompositorWorker> worker = adoptRefWillBeNoop(new CompositorWorker(context));
    if (worker->initialize(context, url, exceptionState))
        return worker.release();
>>>>>>> miniblink49
    return nullptr;
}

CompositorWorker::~CompositorWorker()
{
    ASSERT(isMainThread());
}

const AtomicString& CompositorWorker::interfaceName() const
{
    return EventTargetNames::CompositorWorker;
}

<<<<<<< HEAD
InProcessWorkerMessagingProxy*
CompositorWorker::createInProcessWorkerMessagingProxy(
    ExecutionContext* context)
{
    Document* document = toDocument(context);
    WorkerClients* workerClients = WorkerClients::create();
    provideCompositorProxyClientTo(
        workerClients,
        document->frame()->chromeClient().createCompositorProxyClient(
            document->frame()));
    return new CompositorWorkerMessagingProxy(this, workerClients);
=======
WorkerGlobalScopeProxy* CompositorWorker::createWorkerGlobalScopeProxy(ExecutionContext* worker)
{
    ASSERT(executionContext()->isDocument());
    return new CompositorWorkerMessagingProxy(this);
>>>>>>> miniblink49
}

} // namespace blink
