// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/compositorworker/CompositorWorkerGlobalScope.h"

#include "bindings/core/v8/SerializedScriptValue.h"
#include "core/workers/InProcessWorkerObjectProxy.h"
#include "core/workers/WorkerThreadStartupData.h"
#include "modules/EventTargetModules.h"
#include "modules/compositorworker/CompositorWorkerThread.h"
#include "wtf/AutoReset.h"
#include <memory>

namespace blink {

CompositorWorkerGlobalScope* CompositorWorkerGlobalScope::create(
    CompositorWorkerThread* thread,
    std::unique_ptr<WorkerThreadStartupData> startupData,
    double timeOrigin)
{
    // Note: startupData is finalized on return. After the relevant parts has been
    // passed along to the created 'context'.
    CompositorWorkerGlobalScope* context = new CompositorWorkerGlobalScope(
        startupData->m_scriptURL, startupData->m_userAgent, thread, timeOrigin,
        std::move(startupData->m_starterOriginPrivilegeData),
        startupData->m_workerClients);
    context->applyContentSecurityPolicyFromVector(
        *startupData->m_contentSecurityPolicyHeaders);
    if (!startupData->m_referrerPolicy.isNull())
        context->parseAndSetReferrerPolicy(startupData->m_referrerPolicy);
    context->setAddressSpace(startupData->m_addressSpace);
    return context;
}

CompositorWorkerGlobalScope::CompositorWorkerGlobalScope(
    const KURL& url,
    const String& userAgent,
    CompositorWorkerThread* thread,
    double timeOrigin,
    std::unique_ptr<SecurityOrigin::PrivilegeData> starterOriginPrivilegeData,
    WorkerClients* workerClients)
    : WorkerGlobalScope(url,
        userAgent,
        thread,
        timeOrigin,
        std::move(starterOriginPrivilegeData),
        workerClients)
    , m_executingAnimationFrameCallbacks(false)
    , m_callbackCollection(this)
{
    CompositorProxyClient::from(clients())->setGlobalScope(this);
}

CompositorWorkerGlobalScope::~CompositorWorkerGlobalScope() { }

void CompositorWorkerGlobalScope::dispose()
{
    WorkerGlobalScope::dispose();
    CompositorProxyClient::from(clients())->dispose();
=======
#include "config.h"
#include "modules/compositorworker/CompositorWorkerGlobalScope.h"

#include "bindings/core/v8/SerializedScriptValue.h"
#include "core/workers/WorkerObjectProxy.h"
#include "core/workers/WorkerThreadStartupData.h"
#include "modules/EventTargetModules.h"
#include "modules/compositorworker/CompositorWorkerThread.h"

namespace blink {

PassRefPtrWillBeRawPtr<CompositorWorkerGlobalScope> CompositorWorkerGlobalScope::create(CompositorWorkerThread* thread, PassOwnPtr<WorkerThreadStartupData> startupData, double timeOrigin)
{
    // Note: startupData is finalized on return. After the relevant parts has been
    // passed along to the created 'context'.
    RefPtrWillBeRawPtr<CompositorWorkerGlobalScope> context = adoptRefWillBeNoop(new CompositorWorkerGlobalScope(startupData->m_scriptURL, startupData->m_userAgent, thread, timeOrigin, startupData->m_starterOrigin, startupData->m_workerClients.release()));
    context->applyContentSecurityPolicyFromVector(*startupData->m_contentSecurityPolicyHeaders);
    return context.release();
}

CompositorWorkerGlobalScope::CompositorWorkerGlobalScope(const KURL& url, const String& userAgent, CompositorWorkerThread* thread, double timeOrigin, const SecurityOrigin* starterOrigin, PassOwnPtrWillBeRawPtr<WorkerClients> workerClients)
    : WorkerGlobalScope(url, userAgent, thread, timeOrigin, starterOrigin, workerClients)
    , m_callbackCollection(this)
{
}

CompositorWorkerGlobalScope::~CompositorWorkerGlobalScope()
{
>>>>>>> miniblink49
}

DEFINE_TRACE(CompositorWorkerGlobalScope)
{
<<<<<<< HEAD
    visitor->trace(m_callbackCollection);
=======
#if ENABLE(OILPAN)
    visitor->trace(m_callbackCollection);
#endif
>>>>>>> miniblink49
    WorkerGlobalScope::trace(visitor);
}

const AtomicString& CompositorWorkerGlobalScope::interfaceName() const
{
    return EventTargetNames::CompositorWorkerGlobalScope;
}

<<<<<<< HEAD
void CompositorWorkerGlobalScope::postMessage(
    ExecutionContext* executionContext,
    PassRefPtr<SerializedScriptValue> message,
    const MessagePortArray& ports,
    ExceptionState& exceptionState)
{
    // Disentangle the port in preparation for sending it to the remote context.
    std::unique_ptr<MessagePortChannelArray> channels = MessagePort::disentanglePorts(executionContext, ports, exceptionState);
    if (exceptionState.hadException())
        return;
    workerObjectProxy().postMessageToWorkerObject(std::move(message),
        std::move(channels));
}

int CompositorWorkerGlobalScope::requestAnimationFrame(
    FrameRequestCallback* callback)
{
    const bool shouldSignal = !m_executingAnimationFrameCallbacks && m_callbackCollection.isEmpty();
    if (shouldSignal)
        CompositorProxyClient::from(clients())->requestAnimationFrame();
=======
void CompositorWorkerGlobalScope::postMessage(ExecutionContext* executionContext, PassRefPtr<SerializedScriptValue> message, const MessagePortArray* ports, ExceptionState& exceptionState)
{
    // Disentangle the port in preparation for sending it to the remote context.
    OwnPtr<MessagePortChannelArray> channels = MessagePort::disentanglePorts(executionContext, ports, exceptionState);
    if (exceptionState.hadException())
        return;
    thread()->workerObjectProxy().postMessageToWorkerObject(message, channels.release());
}

int CompositorWorkerGlobalScope::requestAnimationFrame(FrameRequestCallback* callback)
{
>>>>>>> miniblink49
    return m_callbackCollection.registerCallback(callback);
}

void CompositorWorkerGlobalScope::cancelAnimationFrame(int id)
{
    m_callbackCollection.cancelCallback(id);
}

<<<<<<< HEAD
bool CompositorWorkerGlobalScope::executeAnimationFrameCallbacks(
    double highResTimeMs)
{
    AutoReset<bool> temporaryChange(&m_executingAnimationFrameCallbacks, true);
    m_callbackCollection.executeCallbacks(highResTimeMs, highResTimeMs);
    return !m_callbackCollection.isEmpty();
}

InProcessWorkerObjectProxy& CompositorWorkerGlobalScope::workerObjectProxy()
    const
{
    return static_cast<CompositorWorkerThread*>(thread())->workerObjectProxy();
=======
void CompositorWorkerGlobalScope::executeAnimationFrameCallbacks(double highResTimeNow)
{
    m_callbackCollection.executeCallbacks(highResTimeNow, highResTimeNow);
}

CompositorWorkerThread* CompositorWorkerGlobalScope::thread() const
{
    return static_cast<CompositorWorkerThread*>(WorkerGlobalScope::thread());
>>>>>>> miniblink49
}

} // namespace blink
