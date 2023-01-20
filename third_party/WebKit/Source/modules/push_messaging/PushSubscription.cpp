// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/push_messaging/PushSubscription.h"

#include "bindings/core/v8/CallbackPromiseAdapter.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "bindings/core/v8/V8ObjectBuilder.h"
#include "modules/push_messaging/PushError.h"
<<<<<<< HEAD
#include "modules/push_messaging/PushSubscriptionOptions.h"
=======
>>>>>>> miniblink49
#include "modules/serviceworkers/ServiceWorkerRegistration.h"
#include "public/platform/Platform.h"
#include "public/platform/modules/push_messaging/WebPushProvider.h"
#include "public/platform/modules/push_messaging/WebPushSubscription.h"
<<<<<<< HEAD
#include "wtf/Assertions.h"
#include "wtf/text/Base64.h"
#include <memory>

namespace blink {

PushSubscription* PushSubscription::take(
    ScriptPromiseResolver*,
    std::unique_ptr<WebPushSubscription> pushSubscription,
    ServiceWorkerRegistration* serviceWorkerRegistration)
{
    if (!pushSubscription)
        return nullptr;
    return new PushSubscription(*pushSubscription, serviceWorkerRegistration);
=======
#include "wtf/OwnPtr.h"

namespace blink {

PushSubscription* PushSubscription::take(ScriptPromiseResolver*, WebPushSubscription* pushSubscription, ServiceWorkerRegistration* serviceWorkerRegistration)
{
    OwnPtr<WebPushSubscription> subscription = adoptPtr(pushSubscription);
    return new PushSubscription(subscription->endpoint, serviceWorkerRegistration);
>>>>>>> miniblink49
}

void PushSubscription::dispose(WebPushSubscription* pushSubscription)
{
    if (pushSubscription)
        delete pushSubscription;
}

<<<<<<< HEAD
PushSubscription::PushSubscription(
    const WebPushSubscription& subscription,
    ServiceWorkerRegistration* serviceWorkerRegistration)
    : m_endpoint(subscription.endpoint)
    , m_options(PushSubscriptionOptions::create(subscription.options))
    , m_p256dh(DOMArrayBuffer::create(subscription.p256dh.data(),
          subscription.p256dh.size()))
    , m_auth(DOMArrayBuffer::create(subscription.auth.data(),
          subscription.auth.size()))
=======
PushSubscription::PushSubscription(const KURL& endpoint, ServiceWorkerRegistration* serviceWorkerRegistration)
    : m_endpoint(endpoint)
>>>>>>> miniblink49
    , m_serviceWorkerRegistration(serviceWorkerRegistration)
{
}

<<<<<<< HEAD
PushSubscription::~PushSubscription() { }

DOMArrayBuffer* PushSubscription::getKey(const AtomicString& name) const
{
    if (name == "p256dh")
        return m_p256dh;
    if (name == "auth")
        return m_auth;

    return nullptr;
=======
PushSubscription::~PushSubscription()
{
}

KURL PushSubscription::endpoint() const
{
    return m_endpoint;
>>>>>>> miniblink49
}

ScriptPromise PushSubscription::unsubscribe(ScriptState* scriptState)
{
<<<<<<< HEAD
    ScriptPromiseResolver* resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    WebPushProvider* webPushProvider = Platform::current()->pushProvider();
    DCHECK(webPushProvider);

    webPushProvider->unsubscribe(
        m_serviceWorkerRegistration->webRegistration(),
        WTF::makeUnique<CallbackPromiseAdapter<bool, PushError>>(resolver));
=======
    RefPtrWillBeRawPtr<ScriptPromiseResolver> resolver = ScriptPromiseResolver::create(scriptState);
    ScriptPromise promise = resolver->promise();

    WebPushProvider* webPushProvider = Platform::current()->pushProvider();
    ASSERT(webPushProvider);

    webPushProvider->unsubscribe(m_serviceWorkerRegistration->webRegistration(), new CallbackPromiseAdapter<bool, PushError>(resolver));
>>>>>>> miniblink49
    return promise;
}

ScriptValue PushSubscription::toJSONForBinding(ScriptState* scriptState)
{
<<<<<<< HEAD
    DCHECK(m_p256dh);

    V8ObjectBuilder result(scriptState);
    result.addString("endpoint", endpoint());

    V8ObjectBuilder keys(scriptState);
    keys.add("p256dh",
        WTF::base64URLEncode(static_cast<const char*>(m_p256dh->data()),
            m_p256dh->byteLength()));
    keys.add("auth",
        WTF::base64URLEncode(static_cast<const char*>(m_auth->data()),
            m_auth->byteLength()));
    result.add("keys", keys);

=======
    V8ObjectBuilder result(scriptState);
    result.addString("endpoint", endpoint());

>>>>>>> miniblink49
    return result.scriptValue();
}

DEFINE_TRACE(PushSubscription)
{
<<<<<<< HEAD
    visitor->trace(m_options);
    visitor->trace(m_p256dh);
    visitor->trace(m_auth);
=======
>>>>>>> miniblink49
    visitor->trace(m_serviceWorkerRegistration);
}

} // namespace blink
