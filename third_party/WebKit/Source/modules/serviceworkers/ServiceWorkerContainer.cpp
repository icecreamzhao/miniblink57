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
#include "modules/serviceworkers/ServiceWorkerContainer.h"

#include "bindings/core/v8/CallbackPromiseAdapter.h"
=======
#include "config.h"
#include "modules/serviceworkers/ServiceWorkerContainer.h"

>>>>>>> miniblink49
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/SerializedScriptValue.h"
#include "bindings/core/v8/SerializedScriptValueFactory.h"
<<<<<<< HEAD
#include "bindings/core/v8/V8ThrowException.h"
=======
>>>>>>> miniblink49
#include "core/dom/DOMException.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "core/dom/MessagePort.h"
<<<<<<< HEAD
#include "core/events/MessageEvent.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/UseCounter.h"
#include "core/frame/csp/ContentSecurityPolicy.h"
#include "modules/EventTargetModules.h"
#include "modules/serviceworkers/NavigatorServiceWorker.h"
#include "modules/serviceworkers/ServiceWorker.h"
#include "modules/serviceworkers/ServiceWorkerContainerClient.h"
#include "modules/serviceworkers/ServiceWorkerError.h"
#include "modules/serviceworkers/ServiceWorkerRegistration.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/weborigin/SchemeRegistry.h"
#include "public/platform/WebString.h"
#include "public/platform/WebURL.h"
#include "public/platform/modules/serviceworker/WebServiceWorker.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerProvider.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerRegistration.h"
#include "wtf/PtrUtil.h"
#include <memory>
#include <utility>

namespace blink {

class GetRegistrationCallback : public WebServiceWorkerProvider::
                                    WebServiceWorkerGetRegistrationCallbacks {
public:
    explicit GetRegistrationCallback(ScriptPromiseResolver* resolver)
        : m_resolver(resolver)
    {
    }
    ~GetRegistrationCallback() override { }

    void onSuccess(std::unique_ptr<WebServiceWorkerRegistration::Handle>
            webPassHandle) override
    {
        std::unique_ptr<WebServiceWorkerRegistration::Handle> handle = WTF::wrapUnique(webPassHandle.release());
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        if (!handle) {
=======
#include "core/frame/LocalDOMWindow.h"
#include "modules/EventTargetModules.h"
#include "modules/serviceworkers/ServiceWorker.h"
#include "modules/serviceworkers/ServiceWorkerContainerClient.h"
#include "modules/serviceworkers/ServiceWorkerError.h"
#include "modules/serviceworkers/ServiceWorkerMessageEvent.h"
#include "modules/serviceworkers/ServiceWorkerRegistration.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/weborigin/SchemeRegistry.h"
#include "public/platform/WebServiceWorker.h"
#include "public/platform/WebServiceWorkerProvider.h"
#include "public/platform/WebServiceWorkerRegistration.h"
#include "public/platform/WebString.h"
#include "public/platform/WebURL.h"

namespace blink {

class RegistrationCallback : public WebServiceWorkerProvider::WebServiceWorkerRegistrationCallbacks {
public:
    explicit RegistrationCallback(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_resolver(resolver) { }
    ~RegistrationCallback() override { }

    void onSuccess(WebServiceWorkerRegistration* registration) override
    {
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        m_resolver->resolve(ServiceWorkerRegistration::take(m_resolver.get(), registration));
    }

    // Takes ownership of |errorRaw|.
    void onError(WebServiceWorkerError* errorRaw) override
    {
        OwnPtr<WebServiceWorkerError> error = adoptPtr(errorRaw);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        m_resolver->reject(ServiceWorkerError::take(m_resolver.get(), error.release()));
    }

private:
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
    WTF_MAKE_NONCOPYABLE(RegistrationCallback);
};

class GetRegistrationCallback : public WebServiceWorkerProvider::WebServiceWorkerGetRegistrationCallbacks {
public:
    explicit GetRegistrationCallback(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_resolver(resolver) { }
    ~GetRegistrationCallback() override { }

    void onSuccess(WebServiceWorkerRegistration* registration) override
    {
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        if (!registration) {
>>>>>>> miniblink49
            // Resolve the promise with undefined.
            m_resolver->resolve();
            return;
        }
<<<<<<< HEAD
        m_resolver->resolve(ServiceWorkerRegistration::getOrCreate(
            m_resolver->getExecutionContext(), std::move(handle)));
    }

    void onError(const WebServiceWorkerError& error) override
    {
        if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
            return;
        m_resolver->reject(ServiceWorkerError::take(m_resolver.get(), error));
    }

private:
    Persistent<ScriptPromiseResolver> m_resolver;
    WTF_MAKE_NONCOPYABLE(GetRegistrationCallback);
};

class ServiceWorkerContainer::GetRegistrationForReadyCallback
    : public WebServiceWorkerProvider::
          WebServiceWorkerGetRegistrationForReadyCallbacks {
public:
    explicit GetRegistrationForReadyCallback(ReadyProperty* ready)
        : m_ready(ready)
    {
    }
    ~GetRegistrationForReadyCallback() override { }

    void onSuccess(
        std::unique_ptr<WebServiceWorkerRegistration::Handle> handle) override
    {
        ASSERT(m_ready->getState() == ReadyProperty::Pending);

        if (m_ready->getExecutionContext() && !m_ready->getExecutionContext()->isContextDestroyed()) {
            m_ready->resolve(ServiceWorkerRegistration::getOrCreate(
                m_ready->getExecutionContext(), WTF::wrapUnique(handle.release())));
        }
    }

=======
        m_resolver->resolve(ServiceWorkerRegistration::take(m_resolver.get(), registration));
    }

    // Takes ownership of |errorRaw|.
    void onError(WebServiceWorkerError* errorRaw) override
    {
        OwnPtr<WebServiceWorkerError> error = adoptPtr(errorRaw);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        m_resolver->reject(ServiceWorkerError::take(m_resolver.get(), error.release()));
    }

private:
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
    WTF_MAKE_NONCOPYABLE(GetRegistrationCallback);
};

class GetRegistrationsCallback : public WebServiceWorkerProvider::WebServiceWorkerGetRegistrationsCallbacks {
public:
    explicit GetRegistrationsCallback(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
        : m_resolver(resolver) { }
    ~GetRegistrationsCallback() override { }

    // Takes ownership of |registrationsRaw|.
    void onSuccess(WebVector<WebServiceWorkerRegistration*>* registrationsRaw) override
    {
        OwnPtr<WebVector<WebServiceWorkerRegistration*>> registrations = adoptPtr(registrationsRaw);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        m_resolver->resolve(ServiceWorkerRegistrationArray::take(m_resolver.get(), registrations.release()));
    }

    // Takes ownership of |errorRaw|.
    void onError(WebServiceWorkerError* errorRaw) override
    {
        OwnPtr<WebServiceWorkerError> error = adoptPtr(errorRaw);
        if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
            return;
        m_resolver->reject(ServiceWorkerError::take(m_resolver.get(), error.release()));
    }

private:
    RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
    WTF_MAKE_NONCOPYABLE(GetRegistrationsCallback);
};

class ServiceWorkerContainer::GetRegistrationForReadyCallback : public WebServiceWorkerProvider::WebServiceWorkerGetRegistrationForReadyCallbacks {
public:
    explicit GetRegistrationForReadyCallback(ReadyProperty* ready)
        : m_ready(ready) { }
    ~GetRegistrationForReadyCallback() { }
    void onSuccess(WebServiceWorkerRegistration* registration) override
    {
        ASSERT(registration);
        ASSERT(m_ready->state() == ReadyProperty::Pending);
        if (m_ready->executionContext() && !m_ready->executionContext()->activeDOMObjectsAreStopped())
            m_ready->resolve(ServiceWorkerRegistration::from(m_ready->executionContext(), registration));
    }
>>>>>>> miniblink49
private:
    Persistent<ReadyProperty> m_ready;
    WTF_MAKE_NONCOPYABLE(GetRegistrationForReadyCallback);
};

<<<<<<< HEAD
ServiceWorkerContainer* ServiceWorkerContainer::create(
    ExecutionContext* executionContext,
    NavigatorServiceWorker* navigator)
{
    return new ServiceWorkerContainer(executionContext, navigator);
=======
ServiceWorkerContainer* ServiceWorkerContainer::create(ExecutionContext* executionContext)
{
    return new ServiceWorkerContainer(executionContext);
>>>>>>> miniblink49
}

ServiceWorkerContainer::~ServiceWorkerContainer()
{
    ASSERT(!m_provider);
}

<<<<<<< HEAD
void ServiceWorkerContainer::contextDestroyed(ExecutionContext*)
=======
void ServiceWorkerContainer::willBeDetachedFromFrame()
>>>>>>> miniblink49
{
    if (m_provider) {
        m_provider->setClient(0);
        m_provider = nullptr;
    }
<<<<<<< HEAD
    m_navigator->clearServiceWorker();
=======
>>>>>>> miniblink49
}

DEFINE_TRACE(ServiceWorkerContainer)
{
    visitor->trace(m_controller);
    visitor->trace(m_ready);
<<<<<<< HEAD
    visitor->trace(m_navigator);
    EventTargetWithInlineData::trace(visitor);
    ContextLifecycleObserver::trace(visitor);
}

void ServiceWorkerContainer::registerServiceWorkerImpl(
    ExecutionContext* executionContext,
    const KURL& rawScriptURL,
    const KURL& scope,
    std::unique_ptr<RegistrationCallbacks> callbacks)
{
    if (!m_provider) {
        callbacks->onError(
            WebServiceWorkerError(WebServiceWorkerError::ErrorTypeState,
                "Failed to register a ServiceWorker: The "
                "document is in an invalid state."));
        return;
    }

    RefPtr<SecurityOrigin> documentOrigin = executionContext->getSecurityOrigin();
    String errorMessage;
    // Restrict to secure origins:
    // https://w3c.github.io/webappsec/specs/powerfulfeatures/#settings-privileged
    if (!executionContext->isSecureContext(errorMessage)) {
        callbacks->onError(WebServiceWorkerError(
            WebServiceWorkerError::ErrorTypeSecurity, errorMessage));
        return;
    }

    KURL pageURL = KURL(KURL(), documentOrigin->toString());
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(
            pageURL.protocol())) {
        callbacks->onError(WebServiceWorkerError(
            WebServiceWorkerError::ErrorTypeSecurity,
            String("Failed to register a ServiceWorker: The URL protocol of the "
                   "current origin ('"
                + documentOrigin->toString() + "') is not supported.")));
        return;
    }

    KURL scriptURL = rawScriptURL;
    scriptURL.removeFragmentIdentifier();
    if (!documentOrigin->canRequest(scriptURL)) {
        RefPtr<SecurityOrigin> scriptOrigin = SecurityOrigin::create(scriptURL);
        callbacks->onError(
            WebServiceWorkerError(WebServiceWorkerError::ErrorTypeSecurity,
                String("Failed to register a ServiceWorker: The "
                       "origin of the provided scriptURL ('"
                    + scriptOrigin->toString() + "') does not match the current origin ('" + documentOrigin->toString() + "').")));
        return;
    }
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(
            scriptURL.protocol())) {
        callbacks->onError(WebServiceWorkerError(
            WebServiceWorkerError::ErrorTypeSecurity,
            String("Failed to register a ServiceWorker: The URL protocol of the "
                   "script ('"
                + scriptURL.getString() + "') is not supported.")));
        return;
    }

    KURL patternURL = scope;
    patternURL.removeFragmentIdentifier();

    if (!documentOrigin->canRequest(patternURL)) {
        RefPtr<SecurityOrigin> patternOrigin = SecurityOrigin::create(patternURL);
        callbacks->onError(
            WebServiceWorkerError(WebServiceWorkerError::ErrorTypeSecurity,
                String("Failed to register a ServiceWorker: The "
                       "origin of the provided scope ('"
                    + patternOrigin->toString() + "') does not match the current origin ('" + documentOrigin->toString() + "').")));
        return;
    }
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(
            patternURL.protocol())) {
        callbacks->onError(WebServiceWorkerError(
            WebServiceWorkerError::ErrorTypeSecurity,
            String("Failed to register a ServiceWorker: The URL protocol of the "
                   "scope ('"
                + patternURL.getString() + "') is not supported.")));
        return;
    }

    WebString webErrorMessage;
    if (!m_provider->validateScopeAndScriptURL(patternURL, scriptURL,
            &webErrorMessage)) {
        callbacks->onError(WebServiceWorkerError(
            WebServiceWorkerError::ErrorTypeType,
            WebString::fromUTF8("Failed to register a ServiceWorker: " + webErrorMessage.utf8())));
        return;
    }

    ContentSecurityPolicy* csp = executionContext->contentSecurityPolicy();
    if (csp) {
        if (!(csp->allowRequestWithoutIntegrity(
                  WebURLRequest::RequestContextServiceWorker, scriptURL)
                && csp->allowWorkerContextFromSource(
                    scriptURL, ResourceRequest::RedirectStatus::NoRedirect,
                    ContentSecurityPolicy::SendReport))) {
            callbacks->onError(WebServiceWorkerError(
                WebServiceWorkerError::ErrorTypeSecurity,
                String(
                    "Failed to register a ServiceWorker: The provided scriptURL ('" + scriptURL.getString() + "') violates the Content Security Policy.")));
            return;
        }
    }

    m_provider->registerServiceWorker(patternURL, scriptURL,
        std::move(callbacks));
}

ScriptPromise ServiceWorkerContainer::registerServiceWorker(
    ScriptState* scriptState,
    const String& url,
    const RegistrationOptions& options)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    if (!m_provider) {
        resolver->reject(DOMException::create(InvalidStateError,
            "Failed to register a ServiceWorker: "
            "The document is in an invalid "
            "state."));
        return promise;
    }

    ExecutionContext* executionContext = scriptState->getExecutionContext();
=======
    RefCountedGarbageCollectedEventTargetWithInlineData<ServiceWorkerContainer>::trace(visitor);
    ContextLifecycleObserver::trace(visitor);
}

ScriptPromise ServiceWorkerContainer::registerServiceWorker(ScriptState* scriptState, const String& url, const RegistrationOptions& options)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    if (!m_provider) {
        resolver->reject(DOMException::create(InvalidStateError, "Failed to register a ServiceWorker: The document is in an invalid state."));
        return promise;
    }

    ExecutionContext* executionContext = scriptState->executionContext();
>>>>>>> miniblink49
    // FIXME: May be null due to worker termination: http://crbug.com/413518.
    if (!executionContext)
        return ScriptPromise();

<<<<<<< HEAD
    KURL scriptURL = enteredExecutionContext(scriptState->isolate())->completeURL(url);
    scriptURL.removeFragmentIdentifier();
=======
    RefPtr<SecurityOrigin> documentOrigin = executionContext->securityOrigin();
    String errorMessage;
    // Restrict to secure origins: https://w3c.github.io/webappsec/specs/powerfulfeatures/#settings-privileged
    if (!executionContext->isPrivilegedContext(errorMessage)) {
        resolver->reject(DOMException::create(NotSupportedError, errorMessage));
        return promise;
    }

    KURL pageURL = KURL(KURL(), documentOrigin->toString());
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(pageURL.protocol())) {
        resolver->reject(DOMException::create(SecurityError, "Failed to register a ServiceWorker: The URL protocol of the current origin ('" + documentOrigin->toString() + "') is not supported."));
        return promise;
    }

    KURL scriptURL = callingExecutionContext(scriptState->isolate())->completeURL(url);
    scriptURL.removeFragmentIdentifier();
    if (!documentOrigin->canRequest(scriptURL)) {
        RefPtr<SecurityOrigin> scriptOrigin = SecurityOrigin::create(scriptURL);
        resolver->reject(DOMException::create(SecurityError, "Failed to register a ServiceWorker: The origin of the provided scriptURL ('" + scriptOrigin->toString() + "') does not match the current origin ('" + documentOrigin->toString() + "')."));
        return promise;
    }
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(scriptURL.protocol())) {
        resolver->reject(DOMException::create(SecurityError, "Failed to register a ServiceWorker: The URL protocol of the script ('" + scriptURL.string() + "') is not supported."));
        return promise;
    }
>>>>>>> miniblink49

    KURL patternURL;
    if (options.scope().isNull())
        patternURL = KURL(scriptURL, "./");
    else
<<<<<<< HEAD
        patternURL = enteredExecutionContext(scriptState->isolate())
                         ->completeURL(options.scope());

    registerServiceWorkerImpl(
        executionContext, scriptURL, patternURL,
        WTF::makeUnique<CallbackPromiseAdapter<ServiceWorkerRegistration,
            ServiceWorkerErrorForUpdate>>(
            resolver));
=======
        patternURL = callingExecutionContext(scriptState->isolate())->completeURL(options.scope());
    patternURL.removeFragmentIdentifier();

    if (!documentOrigin->canRequest(patternURL)) {
        RefPtr<SecurityOrigin> patternOrigin = SecurityOrigin::create(patternURL);
        resolver->reject(DOMException::create(SecurityError, "Failed to register a ServiceWorker: The origin of the provided scope ('" + patternOrigin->toString() + "') does not match the current origin ('" + documentOrigin->toString() + "')."));
        return promise;
    }
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(patternURL.protocol())) {
        resolver->reject(DOMException::create(SecurityError, "Failed to register a ServiceWorker: The URL protocol of the scope ('" + patternURL.string() + "') is not supported."));
        return promise;
    }

    m_provider->registerServiceWorker(patternURL, scriptURL, new RegistrationCallback(resolver));
>>>>>>> miniblink49

    return promise;
}

<<<<<<< HEAD
ScriptPromise ServiceWorkerContainer::getRegistration(
    ScriptState* scriptState,
    const String& documentURL)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    if (!m_provider) {
        resolver->reject(DOMException::create(InvalidStateError,
            "Failed to get a "
            "ServiceWorkerRegistration: The "
            "document is in an invalid state."));
        return promise;
    }

    ExecutionContext* executionContext = scriptState->getExecutionContext();
=======
ScriptPromise ServiceWorkerContainer::getRegistration(ScriptState* scriptState, const String& documentURL)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    if (!m_provider) {
        resolver->reject(DOMException::create(InvalidStateError, "Failed to get a ServiceWorkerRegistration: The document is in an invalid state."));
        return promise;
    }

    ExecutionContext* executionContext = scriptState->executionContext();
>>>>>>> miniblink49
    // FIXME: May be null due to worker termination: http://crbug.com/413518.
    if (!executionContext)
        return ScriptPromise();

<<<<<<< HEAD
    RefPtr<SecurityOrigin> documentOrigin = executionContext->getSecurityOrigin();
    String errorMessage;
    if (!executionContext->isSecureContext(errorMessage)) {
        resolver->reject(DOMException::create(SecurityError, errorMessage));
=======
    RefPtr<SecurityOrigin> documentOrigin = executionContext->securityOrigin();
    String errorMessage;
    if (!executionContext->isPrivilegedContext(errorMessage)) {
        resolver->reject(DOMException::create(NotSupportedError, errorMessage));
>>>>>>> miniblink49
        return promise;
    }

    KURL pageURL = KURL(KURL(), documentOrigin->toString());
<<<<<<< HEAD
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(
            pageURL.protocol())) {
        resolver->reject(DOMException::create(
            SecurityError,
            "Failed to get a ServiceWorkerRegistration: The URL protocol of the "
            "current origin ('"
                + documentOrigin->toString() + "') is not supported."));
        return promise;
    }

    KURL completedURL = enteredExecutionContext(scriptState->isolate())->completeURL(documentURL);
    completedURL.removeFragmentIdentifier();
    if (!documentOrigin->canRequest(completedURL)) {
        RefPtr<SecurityOrigin> documentURLOrigin = SecurityOrigin::create(completedURL);
        resolver->reject(
            DOMException::create(SecurityError,
                "Failed to get a ServiceWorkerRegistration: The "
                "origin of the provided documentURL ('"
                    + documentURLOrigin->toString() + "') does not match the current origin ('" + documentOrigin->toString() + "')."));
        return promise;
    }
    m_provider->getRegistration(
        completedURL, WTF::makeUnique<GetRegistrationCallback>(resolver));
=======
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(pageURL.protocol())) {
        resolver->reject(DOMException::create(SecurityError, "Failed to get a ServiceWorkerRegistration: The URL protocol of the current origin ('" + documentOrigin->toString() + "') is not supported."));
        return promise;
    }

    KURL completedURL = callingExecutionContext(scriptState->isolate())->completeURL(documentURL);
    completedURL.removeFragmentIdentifier();
    if (!documentOrigin->canRequest(completedURL)) {
        RefPtr<SecurityOrigin> documentURLOrigin = SecurityOrigin::create(completedURL);
        resolver->reject(DOMException::create(SecurityError, "Failed to get a ServiceWorkerRegistration: The origin of the provided documentURL ('" + documentURLOrigin->toString() + "') does not match the current origin ('" + documentOrigin->toString() + "')."));
        return promise;
    }
    m_provider->getRegistration(completedURL, new GetRegistrationCallback(resolver));
>>>>>>> miniblink49

    return promise;
}

<<<<<<< HEAD
ScriptPromise ServiceWorkerContainer::getRegistrations(
    ScriptState* scriptState)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    if (!m_provider) {
        resolver->reject(
            DOMException::create(InvalidStateError,
                "Failed to get ServiceWorkerRegistration objects: "
                "The document is in an invalid state."));
        return promise;
    }

    ExecutionContext* executionContext = scriptState->getExecutionContext();
    RefPtr<SecurityOrigin> documentOrigin = executionContext->getSecurityOrigin();
    String errorMessage;
    if (!executionContext->isSecureContext(errorMessage)) {
        resolver->reject(DOMException::create(SecurityError, errorMessage));
=======
ScriptPromise ServiceWorkerContainer::getRegistrations(ScriptState* scriptState)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    if (!m_provider) {
        resolver->reject(DOMException::create(InvalidStateError, "Failed to get ServiceWorkerRegistration objects: The document is in an invalid state."));
        return promise;
    }

    ExecutionContext* executionContext = scriptState->executionContext();
    RefPtr<SecurityOrigin> documentOrigin = executionContext->securityOrigin();
    String errorMessage;
    if (!executionContext->isPrivilegedContext(errorMessage)) {
        resolver->reject(DOMException::create(NotSupportedError, errorMessage));
>>>>>>> miniblink49
        return promise;
    }

    KURL pageURL = KURL(KURL(), documentOrigin->toString());
<<<<<<< HEAD
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(
            pageURL.protocol())) {
        resolver->reject(DOMException::create(
            SecurityError,
            "Failed to get ServiceWorkerRegistration objects: The URL protocol of "
            "the current origin ('"
                + documentOrigin->toString() + "') is not supported."));
        return promise;
    }

    m_provider->getRegistrations(
        WTF::makeUnique<CallbackPromiseAdapter<ServiceWorkerRegistrationArray,
            ServiceWorkerError>>(resolver));
=======
    if (!SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(pageURL.protocol())) {
        resolver->reject(DOMException::create(SecurityError, "Failed to get ServiceWorkerRegistration objects: The URL protocol of the current origin ('" + documentOrigin->toString() + "') is not supported."));
        return promise;
    }

    m_provider->getRegistrations(new GetRegistrationsCallback(resolver));
>>>>>>> miniblink49

    return promise;
}

<<<<<<< HEAD
ServiceWorkerContainer::ReadyProperty*
ServiceWorkerContainer::createReadyProperty()
{
    return new ReadyProperty(getExecutionContext(), this, ReadyProperty::Ready);
=======
ServiceWorkerContainer::ReadyProperty* ServiceWorkerContainer::createReadyProperty()
{
    return new ReadyProperty(executionContext(), this, ReadyProperty::Ready);
>>>>>>> miniblink49
}

ScriptPromise ServiceWorkerContainer::ready(ScriptState* callerState)
{
<<<<<<< HEAD
    if (!getExecutionContext())
=======
    if (!executionContext())
>>>>>>> miniblink49
        return ScriptPromise();

    if (!callerState->world().isMainWorld()) {
        // FIXME: Support .ready from isolated worlds when
        // ScriptPromiseProperty can vend Promises in isolated worlds.
<<<<<<< HEAD
        return ScriptPromise::rejectWithDOMException(
            callerState,
            DOMException::create(NotSupportedError,
                "'ready' is only supported in pages."));
=======
        return ScriptPromise::rejectWithDOMException(callerState, DOMException::create(NotSupportedError, "'ready' is only supported in pages."));
>>>>>>> miniblink49
    }

    if (!m_ready) {
        m_ready = createReadyProperty();
<<<<<<< HEAD
        if (m_provider) {
            m_provider->getRegistrationForReady(
                WTF::makeUnique<GetRegistrationForReadyCallback>(m_ready.get()));
        }
=======
        if (m_provider)
            m_provider->getRegistrationForReady(new GetRegistrationForReadyCallback(m_ready.get()));
>>>>>>> miniblink49
    }

    return m_ready->promise(callerState->world());
}

<<<<<<< HEAD
void ServiceWorkerContainer::setController(
    std::unique_ptr<WebServiceWorker::Handle> handle,
    bool shouldNotifyControllerChange)
{
    if (!getExecutionContext())
        return;
    m_controller = ServiceWorker::from(getExecutionContext(),
        WTF::wrapUnique(handle.release()));
    if (m_controller)
        UseCounter::count(getExecutionContext(),
            UseCounter::ServiceWorkerControlledPage);
=======
// If the WebServiceWorker is up for adoption (does not have a
// WebServiceWorkerProxy owner), rejects the adoption by deleting the
// WebServiceWorker.
static void deleteIfNoExistingOwner(WebServiceWorker* serviceWorker)
{
    if (serviceWorker && !serviceWorker->proxy())
        delete serviceWorker;
}

void ServiceWorkerContainer::setController(WebServiceWorker* serviceWorker, bool shouldNotifyControllerChange)
{
    if (!executionContext()) {
        deleteIfNoExistingOwner(serviceWorker);
        return;
    }
    m_controller = ServiceWorker::from(executionContext(), serviceWorker);
>>>>>>> miniblink49
    if (shouldNotifyControllerChange)
        dispatchEvent(Event::create(EventTypeNames::controllerchange));
}

<<<<<<< HEAD
void ServiceWorkerContainer::dispatchMessageEvent(
    std::unique_ptr<WebServiceWorker::Handle> handle,
    const WebString& message,
    const WebMessagePortChannelArray& webChannels)
{
    if (!getExecutionContext() || !getExecutionContext()->executingWindow())
        return;

    MessagePortArray* ports = MessagePort::toMessagePortArray(getExecutionContext(), webChannels);
    RefPtr<SerializedScriptValue> value = SerializedScriptValue::create(message);
    ServiceWorker* source = ServiceWorker::from(
        getExecutionContext(), WTF::wrapUnique(handle.release()));
    dispatchEvent(MessageEvent::create(
        ports, value, getExecutionContext()->getSecurityOrigin()->toString(),
        String() /* lastEventId */, source, String() /* suborigin */));
=======
void ServiceWorkerContainer::dispatchMessageEvent(WebServiceWorker* serviceWorker, const WebString& message, const WebMessagePortChannelArray& webChannels)
{
    if (!executionContext() || !executionContext()->executingWindow())
        return;

    MessagePortArray* ports = MessagePort::toMessagePortArray(executionContext(), webChannels);
    RefPtr<SerializedScriptValue> value = SerializedScriptValueFactory::instance().createFromWire(message);
    RefPtrWillBeRawPtr<ServiceWorker> source = ServiceWorker::from(executionContext(), serviceWorker);
    dispatchEvent(ServiceWorkerMessageEvent::create(ports, value, source, executionContext()->securityOrigin()->toString()));
>>>>>>> miniblink49
}

const AtomicString& ServiceWorkerContainer::interfaceName() const
{
    return EventTargetNames::ServiceWorkerContainer;
}

<<<<<<< HEAD
ServiceWorkerContainer::ServiceWorkerContainer(
    ExecutionContext* executionContext,
    NavigatorServiceWorker* navigator)
    : ContextLifecycleObserver(executionContext)
    , m_provider(0)
    , m_navigator(navigator)
{
=======
ServiceWorkerContainer::ServiceWorkerContainer(ExecutionContext* executionContext)
    : ContextLifecycleObserver(executionContext)
    , m_provider(0)
{

>>>>>>> miniblink49
    if (!executionContext)
        return;

    if (ServiceWorkerContainerClient* client = ServiceWorkerContainerClient::from(executionContext)) {
        m_provider = client->provider();
        if (m_provider)
            m_provider->setClient(this);
    }
}

} // namespace blink
