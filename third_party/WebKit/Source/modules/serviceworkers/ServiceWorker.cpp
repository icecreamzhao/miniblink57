/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
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
#include "modules/serviceworkers/ServiceWorker.h"
=======
#include "config.h"
#include "ServiceWorker.h"
>>>>>>> miniblink49

#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/MessagePort.h"
#include "core/events/Event.h"
#include "modules/EventTargetModules.h"
<<<<<<< HEAD
#include "modules/serviceworkers/ServiceWorkerContainerClient.h"
#include "public/platform/WebMessagePortChannel.h"
#include "public/platform/WebSecurityOrigin.h"
#include "public/platform/WebString.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerState.h"
#include <memory>
=======
#include "public/platform/WebMessagePortChannel.h"
#include "public/platform/WebServiceWorkerState.h"
#include "public/platform/WebString.h"
>>>>>>> miniblink49

namespace blink {

const AtomicString& ServiceWorker::interfaceName() const
{
    return EventTargetNames::ServiceWorker;
}

<<<<<<< HEAD
void ServiceWorker::postMessage(ExecutionContext* context,
    PassRefPtr<SerializedScriptValue> message,
    const MessagePortArray& ports,
    ExceptionState& exceptionState)
{
    ServiceWorkerContainerClient* client = ServiceWorkerContainerClient::from(getExecutionContext());
    if (!client || !client->provider()) {
        exceptionState.throwDOMException(
            InvalidStateError,
            "Failed to post a message: No associated provider is available.");
        return;
    }

    // Disentangle the port in preparation for sending it to the remote context.
    std::unique_ptr<MessagePortChannelArray> channels = MessagePort::disentanglePorts(context, ports, exceptionState);
    if (exceptionState.hadException())
        return;
    if (m_handle->serviceWorker()->state() == WebServiceWorkerStateRedundant) {
        exceptionState.throwDOMException(InvalidStateError,
            "ServiceWorker is in redundant state.");
=======
void ServiceWorker::postMessage(ExecutionContext* context, PassRefPtr<SerializedScriptValue> message, const MessagePortArray* ports, ExceptionState& exceptionState)
{
    // Disentangle the port in preparation for sending it to the remote context.
    OwnPtr<MessagePortChannelArray> channels = MessagePort::disentanglePorts(context, ports, exceptionState);
    if (exceptionState.hadException())
        return;
    if (m_outerWorker->state() == WebServiceWorkerStateRedundant) {
        exceptionState.throwDOMException(InvalidStateError, "ServiceWorker is in redundant state.");
>>>>>>> miniblink49
        return;
    }

    WebString messageString = message->toWireString();
<<<<<<< HEAD
    std::unique_ptr<WebMessagePortChannelArray> webChannels = MessagePort::toWebMessagePortChannelArray(std::move(channels));
    m_handle->serviceWorker()->postMessage(
        client->provider(), messageString,
        WebSecurityOrigin(getExecutionContext()->getSecurityOrigin()),
        webChannels.release());
=======
    OwnPtr<WebMessagePortChannelArray> webChannels = MessagePort::toWebMessagePortChannelArray(channels.release());
    m_outerWorker->postMessage(messageString, webChannels.leakPtr());
>>>>>>> miniblink49
}

void ServiceWorker::internalsTerminate()
{
<<<<<<< HEAD
    m_handle->serviceWorker()->terminate();
=======
    m_outerWorker->terminate();
>>>>>>> miniblink49
}

void ServiceWorker::dispatchStateChangeEvent()
{
    this->dispatchEvent(Event::create(EventTypeNames::statechange));
}

String ServiceWorker::scriptURL() const
{
<<<<<<< HEAD
    return m_handle->serviceWorker()->url().string();
=======
    return m_outerWorker->url().string();
>>>>>>> miniblink49
}

String ServiceWorker::state() const
{
<<<<<<< HEAD
    switch (m_handle->serviceWorker()->state()) {
=======
    switch (m_outerWorker->state()) {
>>>>>>> miniblink49
    case WebServiceWorkerStateUnknown:
        // The web platform should never see this internal state
        ASSERT_NOT_REACHED();
        return "unknown";
    case WebServiceWorkerStateInstalling:
        return "installing";
    case WebServiceWorkerStateInstalled:
        return "installed";
    case WebServiceWorkerStateActivating:
        return "activating";
    case WebServiceWorkerStateActivated:
        return "activated";
    case WebServiceWorkerStateRedundant:
        return "redundant";
    default:
        ASSERT_NOT_REACHED();
        return nullAtom;
    }
}

<<<<<<< HEAD
ServiceWorker* ServiceWorker::from(
    ExecutionContext* executionContext,
    std::unique_ptr<WebServiceWorker::Handle> handle)
{
    return getOrCreate(executionContext, std::move(handle));
=======
PassRefPtrWillBeRawPtr<ServiceWorker> ServiceWorker::from(ExecutionContext* executionContext, WebType* worker)
{
    if (!worker)
        return nullptr;

    RefPtrWillBeRawPtr<ServiceWorker> serviceWorker = getOrCreate(executionContext, worker);
    return serviceWorker.release();
>>>>>>> miniblink49
}

bool ServiceWorker::hasPendingActivity() const
{
<<<<<<< HEAD
    if (m_wasStopped)
        return false;
    return m_handle->serviceWorker()->state() != WebServiceWorkerStateRedundant;
}

void ServiceWorker::contextDestroyed(ExecutionContext*)
=======
    if (AbstractWorker::hasPendingActivity())
        return true;
    if (m_wasStopped)
        return false;
    return m_outerWorker->state() != WebServiceWorkerStateRedundant;
}

void ServiceWorker::stop()
>>>>>>> miniblink49
{
    m_wasStopped = true;
}

<<<<<<< HEAD
ServiceWorker* ServiceWorker::getOrCreate(
    ExecutionContext* executionContext,
    std::unique_ptr<WebServiceWorker::Handle> handle)
{
    if (!handle)
        return nullptr;

    ServiceWorker* existingWorker = static_cast<ServiceWorker*>(handle->serviceWorker()->proxy());
    if (existingWorker) {
        ASSERT(existingWorker->getExecutionContext() == executionContext);
        return existingWorker;
    }

    return new ServiceWorker(executionContext, std::move(handle));
}

ServiceWorker::ServiceWorker(ExecutionContext* executionContext,
    std::unique_ptr<WebServiceWorker::Handle> handle)
    : AbstractWorker(executionContext)
    , m_handle(std::move(handle))
    , m_wasStopped(false)
{
    ASSERT(m_handle);
    m_handle->serviceWorker()->setProxy(this);
}

ServiceWorker::~ServiceWorker() { }

DEFINE_TRACE(ServiceWorker)
{
    AbstractWorker::trace(visitor);
=======
PassRefPtrWillBeRawPtr<ServiceWorker> ServiceWorker::getOrCreate(ExecutionContext* executionContext, WebType* outerWorker)
{
    if (!outerWorker)
        return nullptr;

    ServiceWorker* existingServiceWorker = static_cast<ServiceWorker*>(outerWorker->proxy());
    if (existingServiceWorker) {
        ASSERT(existingServiceWorker->executionContext() == executionContext);
        return existingServiceWorker;
    }

    RefPtrWillBeRawPtr<ServiceWorker> worker = adoptRefWillBeNoop(new ServiceWorker(executionContext, adoptPtr(outerWorker)));
    worker->suspendIfNeeded();
    return worker.release();
}

ServiceWorker::ServiceWorker(ExecutionContext* executionContext, PassOwnPtr<WebServiceWorker> worker)
    : AbstractWorker(executionContext)
    , m_outerWorker(worker)
    , m_wasStopped(false)
{
    ASSERT(m_outerWorker);
    m_outerWorker->setProxy(this);
}

ServiceWorker::~ServiceWorker()
{
>>>>>>> miniblink49
}

} // namespace blink
