// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/serviceworkers/ServiceWorkerRegistration.h"

#include "bindings/core/v8/CallbackPromiseAdapter.h"
#include "bindings/core/v8/ScriptPromise.h"
=======
#include "config.h"
#include "ServiceWorkerRegistration.h"

#include "bindings/core/v8/CallbackPromiseAdapter.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
>>>>>>> miniblink49
#include "bindings/core/v8/ScriptState.h"
#include "core/dom/DOMException.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "core/events/Event.h"
#include "modules/EventTargetModules.h"
#include "modules/serviceworkers/ServiceWorkerContainerClient.h"
#include "modules/serviceworkers/ServiceWorkerError.h"
<<<<<<< HEAD
#include "public/platform/modules/serviceworker/WebServiceWorkerProvider.h"
#include "wtf/PtrUtil.h"
#include <memory>
#include <utility>

namespace blink {

ServiceWorkerRegistration* ServiceWorkerRegistration::take(
    ScriptPromiseResolver* resolver,
    std::unique_ptr<WebServiceWorkerRegistration::Handle> handle)
{
    return getOrCreate(resolver->getExecutionContext(), std::move(handle));
}

bool ServiceWorkerRegistration::hasPendingActivity() const
{
    return !m_stopped;
=======
#include "public/platform/WebServiceWorkerProvider.h"

namespace blink {

static void deleteIfNoExistingOwner(WebServiceWorker* serviceWorker)
{
    if (serviceWorker && !serviceWorker->proxy())
        delete serviceWorker;
>>>>>>> miniblink49
}

const AtomicString& ServiceWorkerRegistration::interfaceName() const
{
    return EventTargetNames::ServiceWorkerRegistration;
}

void ServiceWorkerRegistration::dispatchUpdateFoundEvent()
{
    dispatchEvent(Event::create(EventTypeNames::updatefound));
}

<<<<<<< HEAD
void ServiceWorkerRegistration::setInstalling(
    std::unique_ptr<WebServiceWorker::Handle> handle)
{
    if (!getExecutionContext())
        return;
    m_installing = ServiceWorker::from(getExecutionContext(),
        WTF::wrapUnique(handle.release()));
}

void ServiceWorkerRegistration::setWaiting(
    std::unique_ptr<WebServiceWorker::Handle> handle)
{
    if (!getExecutionContext())
        return;
    m_waiting = ServiceWorker::from(getExecutionContext(),
        WTF::wrapUnique(handle.release()));
}

void ServiceWorkerRegistration::setActive(
    std::unique_ptr<WebServiceWorker::Handle> handle)
{
    if (!getExecutionContext())
        return;
    m_active = ServiceWorker::from(getExecutionContext(),
        WTF::wrapUnique(handle.release()));
}

ServiceWorkerRegistration* ServiceWorkerRegistration::getOrCreate(
    ExecutionContext* executionContext,
    std::unique_ptr<WebServiceWorkerRegistration::Handle> handle)
{
    ASSERT(handle);

    ServiceWorkerRegistration* existingRegistration = static_cast<ServiceWorkerRegistration*>(handle->registration()->proxy());
    if (existingRegistration) {
        ASSERT(existingRegistration->getExecutionContext() == executionContext);
        return existingRegistration;
    }

    return new ServiceWorkerRegistration(executionContext, std::move(handle));
}

NavigationPreloadManager* ServiceWorkerRegistration::navigationPreload()
{
    if (!m_navigationPreload)
        m_navigationPreload = NavigationPreloadManager::create(this);
    return m_navigationPreload;
=======
void ServiceWorkerRegistration::setInstalling(WebServiceWorker* serviceWorker)
{
    if (!executionContext()) {
        deleteIfNoExistingOwner(serviceWorker);
        return;
    }
    m_installing = ServiceWorker::from(executionContext(), serviceWorker);
}

void ServiceWorkerRegistration::setWaiting(WebServiceWorker* serviceWorker)
{
    if (!executionContext()) {
        deleteIfNoExistingOwner(serviceWorker);
        return;
    }
    m_waiting = ServiceWorker::from(executionContext(), serviceWorker);
}

void ServiceWorkerRegistration::setActive(WebServiceWorker* serviceWorker)
{
    if (!executionContext()) {
        deleteIfNoExistingOwner(serviceWorker);
        return;
    }
    m_active = ServiceWorker::from(executionContext(), serviceWorker);
}

ServiceWorkerRegistration* ServiceWorkerRegistration::from(ExecutionContext* executionContext, WebType* registration)
{
    if (!registration)
        return 0;
    return getOrCreate(executionContext, registration);
}

ServiceWorkerRegistration* ServiceWorkerRegistration::take(ScriptPromiseResolver* resolver, WebType* registration)
{
    return from(resolver->scriptState()->executionContext(), registration);
}

void ServiceWorkerRegistration::dispose(WebType* registration)
{
    if (registration && !registration->proxy())
        delete registration;
>>>>>>> miniblink49
}

String ServiceWorkerRegistration::scope() const
{
<<<<<<< HEAD
    return m_handle->registration()->scope().string();
}

ScriptPromise ServiceWorkerRegistration::update(ScriptState* scriptState)
{
    ServiceWorkerContainerClient* client = ServiceWorkerContainerClient::from(getExecutionContext());
    if (!client || !client->provider())
        return ScriptPromise::rejectWithDOMException(
            scriptState,
            DOMException::create(InvalidStateError,
                "Failed to update a ServiceWorkerRegistration: No "
                "associated provider is available."));

    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();
    m_handle->registration()->update(
        client->provider(),
        WTF::makeUnique<
            CallbackPromiseAdapter<void, ServiceWorkerErrorForUpdate>>(resolver));
    return promise;
=======
    return m_outerRegistration->scope().string();
}

void ServiceWorkerRegistration::update(ScriptState* scriptState, ExceptionState& exceptionState)
{
    if (!m_provider) {
        exceptionState.throwDOMException(InvalidStateError, "Failed to update a ServiceWorkerRegistration: No associated provider is available.");
        return;
    }
    m_outerRegistration->update(m_provider);
>>>>>>> miniblink49
}

ScriptPromise ServiceWorkerRegistration::unregister(ScriptState* scriptState)
{
<<<<<<< HEAD
    ServiceWorkerContainerClient* client = ServiceWorkerContainerClient::from(getExecutionContext());
    if (!client || !client->provider())
        return ScriptPromise::rejectWithDOMException(
            scriptState, DOMException::create(InvalidStateError, "Failed to unregister a "
                                                                 "ServiceWorkerRegistration: No "
                                                                 "associated provider is available."));

    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();
    m_handle->registration()->unregister(
        client->provider(),
        WTF::makeUnique<CallbackPromiseAdapter<bool, ServiceWorkerError>>(
            resolver));
    return promise;
}

ServiceWorkerRegistration::ServiceWorkerRegistration(
    ExecutionContext* executionContext,
    std::unique_ptr<WebServiceWorkerRegistration::Handle> handle)
    : ContextLifecycleObserver(executionContext)
    , m_handle(std::move(handle))
    , m_stopped(false)
{
    ASSERT(m_handle);
    ASSERT(!m_handle->registration()->proxy());

    if (!executionContext)
        return;
    m_handle->registration()->setProxy(this);
}

ServiceWorkerRegistration::~ServiceWorkerRegistration() { }

void ServiceWorkerRegistration::dispose()
{
    // Promptly clears a raw reference from content/ to an on-heap object
    // so that content/ doesn't access it in a lazy sweeping phase.
    m_handle.reset();
=======
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    if (!m_provider) {
        resolver->reject(DOMException::create(InvalidStateError, "Failed to unregister a ServiceWorkerRegistration: No associated provider is available."));
        return promise;
    }

    m_outerRegistration->unregister(m_provider, new CallbackPromiseAdapter<bool, ServiceWorkerError>(resolver));
    return promise;
}

ServiceWorkerRegistration* ServiceWorkerRegistration::getOrCreate(ExecutionContext* executionContext, WebServiceWorkerRegistration* outerRegistration)
{
    if (!outerRegistration)
        return 0;

    ServiceWorkerRegistration* existingRegistration = static_cast<ServiceWorkerRegistration*>(outerRegistration->proxy());
    if (existingRegistration) {
        ASSERT(existingRegistration->executionContext() == executionContext);
        return existingRegistration;
    }

    ServiceWorkerRegistration* registration = new ServiceWorkerRegistration(executionContext, adoptPtr(outerRegistration));
    registration->suspendIfNeeded();
    return registration;
}

ServiceWorkerRegistration::ServiceWorkerRegistration(ExecutionContext* executionContext, PassOwnPtr<WebServiceWorkerRegistration> outerRegistration)
    : ActiveDOMObject(executionContext)
    , m_outerRegistration(outerRegistration)
    , m_provider(0)
    , m_stopped(false)
{
    ASSERT(m_outerRegistration);

    if (!executionContext)
        return;
    if (ServiceWorkerContainerClient* client = ServiceWorkerContainerClient::from(executionContext))
        m_provider = client->provider();
    m_outerRegistration->setProxy(this);
}

ServiceWorkerRegistration::~ServiceWorkerRegistration()
{
>>>>>>> miniblink49
}

DEFINE_TRACE(ServiceWorkerRegistration)
{
    visitor->trace(m_installing);
    visitor->trace(m_waiting);
    visitor->trace(m_active);
<<<<<<< HEAD
    visitor->trace(m_navigationPreload);
    EventTargetWithInlineData::trace(visitor);
    ContextLifecycleObserver::trace(visitor);
    Supplementable<ServiceWorkerRegistration>::trace(visitor);
}

void ServiceWorkerRegistration::contextDestroyed(ExecutionContext*)
=======
    RefCountedGarbageCollectedEventTargetWithInlineData<ServiceWorkerRegistration>::trace(visitor);
    HeapSupplementable<ServiceWorkerRegistration>::trace(visitor);
    ActiveDOMObject::trace(visitor);
}

bool ServiceWorkerRegistration::hasPendingActivity() const
{
    return !m_stopped;
}

void ServiceWorkerRegistration::stop()
>>>>>>> miniblink49
{
    if (m_stopped)
        return;
    m_stopped = true;
<<<<<<< HEAD
    m_handle->registration()->proxyStopped();
=======
    m_outerRegistration->proxyStopped();
>>>>>>> miniblink49
}

} // namespace blink
