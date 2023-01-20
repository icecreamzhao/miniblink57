// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/serviceworkers/ServiceWorkerClients.h"

#include "bindings/core/v8/CallbackPromiseAdapter.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "core/dom/DOMException.h"
#include "core/dom/ExceptionCode.h"
#include "core/workers/WorkerGlobalScope.h"
#include "core/workers/WorkerLocation.h"
#include "modules/serviceworkers/ServiceWorkerError.h"
#include "modules/serviceworkers/ServiceWorkerGlobalScopeClient.h"
#include "modules/serviceworkers/ServiceWorkerWindowClient.h"
<<<<<<< HEAD
#include "modules/serviceworkers/ServiceWorkerWindowClientCallback.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerClientQueryOptions.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerClientsInfo.h"
#include "wtf/PtrUtil.h"
#include "wtf/RefPtr.h"
#include "wtf/Vector.h"
#include <memory>
#include <utility>
=======
#include "public/platform/WebServiceWorkerClientQueryOptions.h"
#include "public/platform/WebServiceWorkerClientsInfo.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/RefPtr.h"
#include "wtf/Vector.h"
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    class ClientArray {
    public:
        using WebType = const WebServiceWorkerClientsInfo&;
        static HeapVector<Member<ServiceWorkerClient>> take(
            ScriptPromiseResolver*,
            const WebServiceWorkerClientsInfo& webClients)
        {
            HeapVector<Member<ServiceWorkerClient>> clients;
            for (size_t i = 0; i < webClients.clients.size(); ++i) {
                const WebServiceWorkerClientInfo& client = webClients.clients[i];
                if (client.clientType == WebServiceWorkerClientTypeWindow)
                    clients.push_back(ServiceWorkerWindowClient::create(client));
                else
                    clients.push_back(ServiceWorkerClient::create(client));
            }
            return clients;
        }

    private:
        WTF_MAKE_NONCOPYABLE(ClientArray);
        ClientArray() = delete;
    };

    WebServiceWorkerClientType getClientType(const String& type)
    {
        if (type == "window")
            return WebServiceWorkerClientTypeWindow;
        if (type == "worker")
            return WebServiceWorkerClientTypeWorker;
        if (type == "sharedworker")
            return WebServiceWorkerClientTypeSharedWorker;
        if (type == "all")
            return WebServiceWorkerClientTypeAll;
        ASSERT_NOT_REACHED();
        return WebServiceWorkerClientTypeWindow;
    }

    class GetCallback : public WebServiceWorkerClientCallbacks {
    public:
        explicit GetCallback(ScriptPromiseResolver* resolver)
            : m_resolver(resolver)
        {
        }
        ~GetCallback() override { }

        void onSuccess(
            std::unique_ptr<WebServiceWorkerClientInfo> webClient) override
        {
            std::unique_ptr<WebServiceWorkerClientInfo> client = WTF::wrapUnique(webClient.release());
            if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
                return;
            if (!client) {
                // Resolve the promise with undefined.
                m_resolver->resolve();
                return;
            }
            m_resolver->resolve(
                ServiceWorkerClient::take(m_resolver, std::move(client)));
        }

        void onError(const WebServiceWorkerError& error) override
        {
            if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
                return;
            m_resolver->reject(ServiceWorkerError::take(m_resolver.get(), error));
        }

    private:
        Persistent<ScriptPromiseResolver> m_resolver;
        WTF_MAKE_NONCOPYABLE(GetCallback);
    };
=======
class ClientArray {
public:
    typedef WebServiceWorkerClientsInfo WebType;
    static HeapVector<Member<ServiceWorkerClient>> take(ScriptPromiseResolver*, PassOwnPtr<WebType> webClients)
    {
        HeapVector<Member<ServiceWorkerClient>> clients;
        for (size_t i = 0; i < webClients->clients.size(); ++i) {
            const WebServiceWorkerClientInfo& client = webClients->clients[i];
            if (client.clientType == WebServiceWorkerClientTypeWindow)
                clients.append(ServiceWorkerWindowClient::create(client));
            else
                clients.append(ServiceWorkerClient::create(client));
        }
        return clients;
    }

private:
    WTF_MAKE_NONCOPYABLE(ClientArray);
    ClientArray() = delete;
};

WebServiceWorkerClientType getClientType(const String& type)
{
    if (type == "window")
        return WebServiceWorkerClientTypeWindow;
    if (type == "worker")
        return WebServiceWorkerClientTypeWorker;
    if (type == "sharedworker")
        return WebServiceWorkerClientTypeSharedWorker;
    if (type == "all")
        return WebServiceWorkerClientTypeAll;
    ASSERT_NOT_REACHED();
    return WebServiceWorkerClientTypeWindow;
}
>>>>>>> miniblink49

} // namespace

ServiceWorkerClients* ServiceWorkerClients::create()
{
    return new ServiceWorkerClients();
}

<<<<<<< HEAD
ServiceWorkerClients::ServiceWorkerClients() { }

ScriptPromise ServiceWorkerClients::get(ScriptState* scriptState,
    const String& id)
{
    ExecutionContext* executionContext = scriptState->getExecutionContext();
    // TODO(jungkees): May be null due to worker termination:
    // http://crbug.com/413518.
    if (!executionContext)
        return ScriptPromise();

    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    ServiceWorkerGlobalScopeClient::from(executionContext)
        ->getClient(id, WTF::makeUnique<GetCallback>(resolver));
    return promise;
}

ScriptPromise ServiceWorkerClients::matchAll(
    ScriptState* scriptState,
    const ClientQueryOptions& options)
{
    ExecutionContext* executionContext = scriptState->getExecutionContext();
=======
ServiceWorkerClients::ServiceWorkerClients()
{
}

ScriptPromise ServiceWorkerClients::matchAll(ScriptState* scriptState, const ClientQueryOptions& options)
{
    ExecutionContext* executionContext = scriptState->executionContext();
>>>>>>> miniblink49
    // FIXME: May be null due to worker termination: http://crbug.com/413518.
    if (!executionContext)
        return ScriptPromise();

<<<<<<< HEAD
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
=======
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
>>>>>>> miniblink49
    ScriptPromise promise = resolver->promise();

    WebServiceWorkerClientQueryOptions webOptions;
    webOptions.clientType = getClientType(options.type());
    webOptions.includeUncontrolled = options.includeUncontrolled();
<<<<<<< HEAD
    ServiceWorkerGlobalScopeClient::from(executionContext)
        ->getClients(webOptions,
            WTF::makeUnique<
                CallbackPromiseAdapter<ClientArray, ServiceWorkerError>>(
                resolver));
=======
    ServiceWorkerGlobalScopeClient::from(executionContext)->getClients(webOptions, new CallbackPromiseAdapter<ClientArray, ServiceWorkerError>(resolver));
>>>>>>> miniblink49
    return promise;
}

ScriptPromise ServiceWorkerClients::claim(ScriptState* scriptState)
{
<<<<<<< HEAD
    ExecutionContext* executionContext = scriptState->getExecutionContext();
=======
    ExecutionContext* executionContext = scriptState->executionContext();
>>>>>>> miniblink49

    // FIXME: May be null due to worker termination: http://crbug.com/413518.
    if (!executionContext)
        return ScriptPromise();

<<<<<<< HEAD
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    auto callbacks = WTF::makeUnique<CallbackPromiseAdapter<void, ServiceWorkerError>>(
        resolver);
    ServiceWorkerGlobalScopeClient::from(executionContext)
        ->claim(std::move(callbacks));
    return promise;
}

ScriptPromise ServiceWorkerClients::openWindow(ScriptState* scriptState,
    const String& url)
{
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();
    ExecutionContext* context = scriptState->getExecutionContext();

    KURL parsedUrl = KURL(toWorkerGlobalScope(context)->location()->url(), url);
    if (!parsedUrl.isValid()) {
        resolver->reject(V8ThrowException::createTypeError(
            scriptState->isolate(), "'" + url + "' is not a valid URL."));
        return promise;
    }

    if (!context->getSecurityOrigin()->canDisplay(parsedUrl)) {
        resolver->reject(V8ThrowException::createTypeError(
            scriptState->isolate(),
            "'" + parsedUrl.elidedString() + "' cannot be opened."));
=======
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    WebServiceWorkerClientsClaimCallbacks* callbacks = new CallbackPromiseAdapter<void, ServiceWorkerError>(resolver);
    ServiceWorkerGlobalScopeClient::from(executionContext)->claim(callbacks);
    return promise;
}

ScriptPromise ServiceWorkerClients::openWindow(ScriptState* scriptState, const String& url)
{
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();
    ExecutionContext* context = scriptState->executionContext();

    KURL parsedUrl = KURL(toWorkerGlobalScope(context)->location()->url(), url);
    if (!parsedUrl.isValid()) {
        resolver->reject(V8ThrowException::createTypeError(scriptState->isolate(), "'" + url + "' is not a valid URL."));
        return promise;
    }

    if (!context->securityOrigin()->canDisplay(parsedUrl)) {
        resolver->reject(DOMException::create(SecurityError, "'" + parsedUrl.elidedString() + "' cannot be opened."));
>>>>>>> miniblink49
        return promise;
    }

    if (!context->isWindowInteractionAllowed()) {
<<<<<<< HEAD
        resolver->reject(DOMException::create(InvalidAccessError,
            "Not allowed to open a window."));
=======
        resolver->reject(DOMException::create(InvalidAccessError, "Not allowed to open a window."));
>>>>>>> miniblink49
        return promise;
    }
    context->consumeWindowInteraction();

<<<<<<< HEAD
    ServiceWorkerGlobalScopeClient::from(context)->openWindow(
        parsedUrl, WTF::makeUnique<NavigateClientCallback>(resolver));
=======
    ServiceWorkerGlobalScopeClient::from(context)->openWindow(parsedUrl, new CallbackPromiseAdapter<ServiceWorkerWindowClient, ServiceWorkerError>(resolver));
>>>>>>> miniblink49
    return promise;
}

} // namespace blink
