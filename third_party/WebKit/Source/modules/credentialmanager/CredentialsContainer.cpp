// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/credentialmanager/CredentialsContainer.h"

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "core/dom/DOMException.h"
<<<<<<< HEAD
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "core/frame/Frame.h"
#include "core/frame/UseCounter.h"
#include "core/page/FrameTree.h"
=======
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
>>>>>>> miniblink49
#include "modules/credentialmanager/Credential.h"
#include "modules/credentialmanager/CredentialManagerClient.h"
#include "modules/credentialmanager/CredentialRequestOptions.h"
#include "modules/credentialmanager/FederatedCredential.h"
#include "modules/credentialmanager/FederatedCredentialRequestOptions.h"
#include "modules/credentialmanager/PasswordCredential.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/Platform.h"
#include "public/platform/WebCredential.h"
#include "public/platform/WebCredentialManagerClient.h"
#include "public/platform/WebCredentialManagerError.h"
#include "public/platform/WebFederatedCredential.h"
#include "public/platform/WebPasswordCredential.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

static void rejectDueToCredentialManagerError(
    ScriptPromiseResolver* resolver,
    WebCredentialManagerError reason)
{
    switch (reason) {
    case WebCredentialManagerDisabledError:
        resolver->reject(DOMException::create(
            InvalidStateError, "The credential manager is disabled."));
        break;
    case WebCredentialManagerPendingRequestError:
        resolver->reject(DOMException::create(InvalidStateError,
            "A 'get()' request is pending."));
        break;
    case WebCredentialManagerUnknownError:
    default:
        resolver->reject(DOMException::create(NotReadableError,
            "An unknown error occurred while "
            "talking to the credential "
            "manager."));
=======

namespace blink {

static void rejectDueToCredentialManagerError(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver, WebCredentialManagerError* reason)
{
    switch (reason->errorType) {
    case WebCredentialManagerError::ErrorTypeDisabled:
        resolver->reject(DOMException::create(InvalidStateError, "The credential manager is disabled."));
        break;
    case WebCredentialManagerError::ErrorTypeUnknown:
    default:
        resolver->reject(DOMException::create(NotReadableError, "An unknown error occured while talking to the credential manager."));
>>>>>>> miniblink49
        break;
    }
}

<<<<<<< HEAD
class NotificationCallbacks
    : public WebCredentialManagerClient::NotificationCallbacks {
    WTF_MAKE_NONCOPYABLE(NotificationCallbacks);

public:
    explicit NotificationCallbacks(ScriptPromiseResolver* resolver)
        : m_resolver(resolver)
    {
    }
=======
class NotificationCallbacks : public WebCredentialManagerClient::NotificationCallbacks {
    WTF_MAKE_NONCOPYABLE(NotificationCallbacks);
public:
    explicit NotificationCallbacks(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver) : m_resolver(resolver) { }
>>>>>>> miniblink49
    ~NotificationCallbacks() override { }

    void onSuccess() override
    {
<<<<<<< HEAD
        Frame* frame = toDocument(m_resolver->getScriptState()->getExecutionContext())
                           ->frame();
        SECURITY_CHECK(!frame || frame == frame->tree().top());

        m_resolver->resolve();
    }

    void onError(WebCredentialManagerError reason) override
=======
        m_resolver->resolve();
    }

    void onError(WebCredentialManagerError* reason) override
>>>>>>> miniblink49
    {
        rejectDueToCredentialManagerError(m_resolver, reason);
    }

private:
<<<<<<< HEAD
    const Persistent<ScriptPromiseResolver> m_resolver;
=======
    const RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
>>>>>>> miniblink49
};

class RequestCallbacks : public WebCredentialManagerClient::RequestCallbacks {
    WTF_MAKE_NONCOPYABLE(RequestCallbacks);
<<<<<<< HEAD

public:
    explicit RequestCallbacks(ScriptPromiseResolver* resolver)
        : m_resolver(resolver)
    {
    }
    ~RequestCallbacks() override { }

    void onSuccess(std::unique_ptr<WebCredential> webCredential) override
    {
        Frame* frame = toDocument(m_resolver->getScriptState()->getExecutionContext())
                           ->frame();
        SECURITY_CHECK(!frame || frame == frame->tree().top());

        std::unique_ptr<WebCredential> credential = WTF::wrapUnique(webCredential.release());
        if (!credential || !frame) {
=======
public:
    explicit RequestCallbacks(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver) : m_resolver(resolver) { }
    ~RequestCallbacks() override { }

    void onSuccess(WebCredential* credential) override
    {
        if (!credential) {
>>>>>>> miniblink49
            m_resolver->resolve();
            return;
        }

        ASSERT(credential->isPasswordCredential() || credential->isFederatedCredential());
<<<<<<< HEAD
        UseCounter::count(m_resolver->getScriptState()->getExecutionContext(),
            UseCounter::CredentialManagerGetReturnedCredential);
        if (credential->isPasswordCredential())
            m_resolver->resolve(PasswordCredential::create(
                static_cast<WebPasswordCredential*>(credential.get())));
        else
            m_resolver->resolve(FederatedCredential::create(
                static_cast<WebFederatedCredential*>(credential.get())));
    }

    void onError(WebCredentialManagerError reason) override
=======
        if (credential->isPasswordCredential())
            m_resolver->resolve(PasswordCredential::create(static_cast<WebPasswordCredential*>(credential)));
        else
            m_resolver->resolve(FederatedCredential::create(static_cast<WebFederatedCredential*>(credential)));
    }

    void onError(WebCredentialManagerError* reason) override
>>>>>>> miniblink49
    {
        rejectDueToCredentialManagerError(m_resolver, reason);
    }

private:
<<<<<<< HEAD
    const Persistent<ScriptPromiseResolver> m_resolver;
};

=======
    const RefPtrWillBePersistent<ScriptPromiseResolver> m_resolver;
};


>>>>>>> miniblink49
CredentialsContainer* CredentialsContainer::create()
{
    return new CredentialsContainer();
}

<<<<<<< HEAD
CredentialsContainer::CredentialsContainer() { }

static bool checkBoilerplate(ScriptPromiseResolver* resolver)
{
    Frame* frame = toDocument(resolver->getScriptState()->getExecutionContext())->frame();
    if (!frame || frame != frame->tree().top()) {
        resolver->reject(DOMException::create(SecurityError,
            "CredentialContainer methods may "
            "only be executed in a top-level "
            "document."));
=======
CredentialsContainer::CredentialsContainer()
{
}

static bool checkBoilerplate(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
{
    CredentialManagerClient* client = CredentialManagerClient::from(resolver->scriptState()->executionContext());
    if (!client) {
        resolver->reject(DOMException::create(InvalidStateError, "Could not establish connection to the credential manager."));
>>>>>>> miniblink49
        return false;
    }

    String errorMessage;
<<<<<<< HEAD
    if (!resolver->getScriptState()->getExecutionContext()->isSecureContext(
            errorMessage)) {
=======
    if (!resolver->scriptState()->executionContext()->isPrivilegedContext(errorMessage)) {
>>>>>>> miniblink49
        resolver->reject(DOMException::create(SecurityError, errorMessage));
        return false;
    }

<<<<<<< HEAD
    CredentialManagerClient* client = CredentialManagerClient::from(
        resolver->getScriptState()->getExecutionContext());
    if (!client) {
        resolver->reject(DOMException::create(
            InvalidStateError,
            "Could not establish connection to the credential manager."));
        return false;
    }

    return true;
}

ScriptPromise CredentialsContainer::get(
    ScriptState* scriptState,
    const CredentialRequestOptions& options)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
=======
    return true;
}

ScriptPromise CredentialsContainer::request(ScriptState* scriptState, const CredentialRequestOptions& options)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
>>>>>>> miniblink49
    ScriptPromise promise = resolver->promise();
    if (!checkBoilerplate(resolver))
        return promise;

    Vector<KURL> providers;
    if (options.hasFederated() && options.federated().hasProviders()) {
<<<<<<< HEAD
        // TODO(mkwst): CredentialRequestOptions::federated() needs to return a
        // reference, not a value.  Because it returns a temporary value now, a for
        // loop that directly references the value generates code that holds a
        // reference to a value that no longer exists by the time the loop starts
        // looping. In order to avoid this crazyness for the moment, we're making a
        // copy of the vector. https://crbug.com/587088
        const Vector<String> providerStrings = options.federated().providers();
        for (const auto& string : providerStrings) {
            KURL url = KURL(KURL(), string);
            if (url.isValid())
                providers.push_back(url);
        }
    }

    UseCounter::count(scriptState->getExecutionContext(),
        options.unmediated()
            ? UseCounter::CredentialManagerGetWithoutUI
            : UseCounter::CredentialManagerGetWithUI);

    CredentialManagerClient::from(scriptState->getExecutionContext())
        ->dispatchGet(options.unmediated(), options.password(), providers,
            new RequestCallbacks(resolver));
    return promise;
}

ScriptPromise CredentialsContainer::store(ScriptState* scriptState,
    Credential* credential)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
=======
        for (const auto& string : options.federated().providers()) {
            KURL url = KURL(KURL(), string);
            if (url.isValid())
                providers.append(url);
        }
    }

    CredentialManagerClient::from(scriptState->executionContext())->dispatchRequest(options.suppressUI(), providers, new RequestCallbacks(resolver));
    return promise;
}

ScriptPromise CredentialsContainer::notifySignedIn(ScriptState* scriptState, Credential* credential)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
>>>>>>> miniblink49
    ScriptPromise promise = resolver->promise();
    if (!checkBoilerplate(resolver))
        return promise;

<<<<<<< HEAD
    auto webCredential = WebCredential::create(credential->getPlatformCredential());
    CredentialManagerClient::from(scriptState->getExecutionContext())
        ->dispatchStore(*webCredential, new NotificationCallbacks(resolver));
    return promise;
}

ScriptPromise CredentialsContainer::requireUserMediation(
    ScriptState* scriptState)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
=======
    CredentialManagerClient::from(scriptState->executionContext())->dispatchSignedIn(WebCredential::create(credential->platformCredential()), new NotificationCallbacks(resolver));
    return promise;
}

ScriptPromise CredentialsContainer::requireUserMediation(ScriptState* scriptState)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
>>>>>>> miniblink49
    ScriptPromise promise = resolver->promise();
    if (!checkBoilerplate(resolver))
        return promise;

<<<<<<< HEAD
    CredentialManagerClient::from(scriptState->getExecutionContext())
        ->dispatchRequireUserMediation(new NotificationCallbacks(resolver));
=======
    CredentialManagerClient::from(scriptState->executionContext())->dispatchRequireUserMediation(new NotificationCallbacks(resolver));
>>>>>>> miniblink49
    return promise;
}

} // namespace blink
