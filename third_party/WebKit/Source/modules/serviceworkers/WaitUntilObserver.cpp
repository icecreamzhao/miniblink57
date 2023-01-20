// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/serviceworkers/WaitUntilObserver.h"

#include "bindings/core/v8/ScriptFunction.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/V8Binding.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "modules/serviceworkers/ServiceWorkerGlobalScope.h"
#include "platform/LayoutTestSupport.h"
<<<<<<< HEAD
#include "public/platform/Platform.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerEventResult.h"
#include "wtf/Assertions.h"
=======
#include "platform/NotImplemented.h"
#include "public/platform/WebServiceWorkerEventResult.h"
#include "wtf/Assertions.h"
#include "wtf/RefCounted.h"
#include "wtf/RefPtr.h"
>>>>>>> miniblink49
#include <v8.h>

namespace blink {

namespace {

<<<<<<< HEAD
    // Timeout before a service worker that was given window interaction
    // permission loses them. The unit is seconds.
    const unsigned kWindowInteractionTimeout = 10;
    const unsigned kWindowInteractionTimeoutForTest = 1;

    unsigned windowInteractionTimeout()
    {
        return LayoutTestSupport::isRunningLayoutTest()
            ? kWindowInteractionTimeoutForTest
            : kWindowInteractionTimeout;
    }
=======
// Timeout before a service worker that was given window interaction
// permission loses them. The unit is seconds.
const unsigned kWindowInteractionTimeout = 10;
const unsigned kWindowInteractionTimeoutForTest = 1;

unsigned windowInteractionTimeout()
{
    return LayoutTestSupport::isRunningLayoutTest()
        ? kWindowInteractionTimeoutForTest : kWindowInteractionTimeout;
}
>>>>>>> miniblink49

} // anonymous namespace

class WaitUntilObserver::ThenFunction final : public ScriptFunction {
public:
    enum ResolveType {
        Fulfilled,
        Rejected,
    };

<<<<<<< HEAD
    static v8::Local<v8::Function> createFunction(ScriptState* scriptState,
        WaitUntilObserver* observer,
        ResolveType type)
=======
    static v8::Local<v8::Function> createFunction(ScriptState* scriptState, WaitUntilObserver* observer, ResolveType type)
>>>>>>> miniblink49
    {
        ThenFunction* self = new ThenFunction(scriptState, observer, type);
        return self->bindToV8Function();
    }

    DEFINE_INLINE_VIRTUAL_TRACE()
    {
        visitor->trace(m_observer);
        ScriptFunction::trace(visitor);
    }

private:
<<<<<<< HEAD
    ThenFunction(ScriptState* scriptState,
        WaitUntilObserver* observer,
        ResolveType type)
=======
    ThenFunction(ScriptState* scriptState, WaitUntilObserver* observer, ResolveType type)
>>>>>>> miniblink49
        : ScriptFunction(scriptState)
        , m_observer(observer)
        , m_resolveType(type)
    {
    }

    ScriptValue call(ScriptValue value) override
    {
        ASSERT(m_observer);
        ASSERT(m_resolveType == Fulfilled || m_resolveType == Rejected);
        if (m_resolveType == Rejected) {
            m_observer->reportError(value);
<<<<<<< HEAD
            value = ScriptPromise::reject(value.getScriptState(), value).getScriptValue();
=======
            value = ScriptPromise::reject(value.scriptState(), value).scriptValue();
>>>>>>> miniblink49
        }
        m_observer->decrementPendingActivity();
        m_observer = nullptr;
        return value;
    }

    Member<WaitUntilObserver> m_observer;
    ResolveType m_resolveType;
};

<<<<<<< HEAD
WaitUntilObserver* WaitUntilObserver::create(ExecutionContext* context,
    EventType type,
    int eventID)
=======
WaitUntilObserver* WaitUntilObserver::create(ExecutionContext* context, EventType type, int eventID)
>>>>>>> miniblink49
{
    return new WaitUntilObserver(context, type, eventID);
}

void WaitUntilObserver::willDispatchEvent()
{
<<<<<<< HEAD
    m_eventDispatchTime = WTF::currentTime();
=======
>>>>>>> miniblink49
    // When handling a notificationclick event, we want to allow one window to
    // be focused or opened. These calls are allowed between the call to
    // willDispatchEvent() and the last call to decrementPendingActivity(). If
    // waitUntil() isn't called, that means between willDispatchEvent() and
    // didDispatchEvent().
    if (m_type == NotificationClick)
<<<<<<< HEAD
        m_executionContext->allowWindowInteraction();
=======
        executionContext()->allowWindowInteraction();
>>>>>>> miniblink49

    incrementPendingActivity();
}

void WaitUntilObserver::didDispatchEvent(bool errorOccurred)
{
    if (errorOccurred)
        m_hasError = true;
    decrementPendingActivity();
    m_eventDispatched = true;
}

<<<<<<< HEAD
void WaitUntilObserver::waitUntil(ScriptState* scriptState,
    ScriptPromise scriptPromise,
    ExceptionState& exceptionState)
{
    if (m_eventDispatched) {
        exceptionState.throwDOMException(InvalidStateError,
            "The event handler is already finished.");
        return;
    }

    if (!m_executionContext)
=======
void WaitUntilObserver::waitUntil(ScriptState* scriptState, const ScriptValue& value, ExceptionState& exceptionState)
{
    if (m_eventDispatched) {
        exceptionState.throwDOMException(InvalidStateError, "The event handler is already finished.");
        return;
    }

    if (!executionContext())
>>>>>>> miniblink49
        return;

    // When handling a notificationclick event, we want to allow one window to
    // be focused or opened. See comments in ::willDispatchEvent(). When
    // waitUntil() is being used, opening or closing a window must happen in a
    // timeframe specified by windowInteractionTimeout(), otherwise the calls
    // will fail.
    if (m_type == NotificationClick)
<<<<<<< HEAD
        m_consumeWindowInteractionTimer.startOneShot(windowInteractionTimeout(),
            BLINK_FROM_HERE);

    incrementPendingActivity();
    scriptPromise.then(
=======
        m_consumeWindowInteractionTimer.startOneShot(windowInteractionTimeout(), FROM_HERE);

    incrementPendingActivity();
    ScriptPromise::cast(scriptState, value).then(
>>>>>>> miniblink49
        ThenFunction::createFunction(scriptState, this, ThenFunction::Fulfilled),
        ThenFunction::createFunction(scriptState, this, ThenFunction::Rejected));
}

<<<<<<< HEAD
WaitUntilObserver::WaitUntilObserver(ExecutionContext* context,
    EventType type,
    int eventID)
    : m_executionContext(context)
    , m_type(type)
    , m_eventID(eventID)
    , m_consumeWindowInteractionTimer(
          Platform::current()->currentThread()->getWebTaskRunner(),
          this,
          &WaitUntilObserver::consumeWindowInteraction)
=======
WaitUntilObserver::WaitUntilObserver(ExecutionContext* context, EventType type, int eventID)
    : ContextLifecycleObserver(context)
    , m_type(type)
    , m_eventID(eventID)
    , m_pendingActivity(0)
    , m_hasError(false)
    , m_eventDispatched(false)
    , m_consumeWindowInteractionTimer(this, &WaitUntilObserver::consumeWindowInteraction)
>>>>>>> miniblink49
{
}

void WaitUntilObserver::reportError(const ScriptValue& value)
{
    // FIXME: Propagate error message to the client for onerror handling.
<<<<<<< HEAD
    NOTIMPLEMENTED();
=======
    notImplemented();
>>>>>>> miniblink49

    m_hasError = true;
}

void WaitUntilObserver::incrementPendingActivity()
{
    ++m_pendingActivity;
}

void WaitUntilObserver::decrementPendingActivity()
{
    ASSERT(m_pendingActivity > 0);
<<<<<<< HEAD
    if (!m_executionContext || (!m_hasError && --m_pendingActivity))
        return;

    ServiceWorkerGlobalScopeClient* client = ServiceWorkerGlobalScopeClient::from(m_executionContext);
    WebServiceWorkerEventResult result = m_hasError ? WebServiceWorkerEventResultRejected
                                                    : WebServiceWorkerEventResultCompleted;
    switch (m_type) {
    case Activate:
        client->didHandleActivateEvent(m_eventID, result, m_eventDispatchTime);
        break;
    case Fetch:
        client->didHandleFetchEvent(m_eventID, result, m_eventDispatchTime);
        break;
    case Install:
        client->didHandleInstallEvent(m_eventID, result, m_eventDispatchTime);
        break;
    case Message:
        client->didHandleExtendableMessageEvent(m_eventID, result,
            m_eventDispatchTime);
        break;
    case NotificationClick:
        client->didHandleNotificationClickEvent(m_eventID, result,
            m_eventDispatchTime);
        m_consumeWindowInteractionTimer.stop();
        consumeWindowInteraction(nullptr);
        break;
    case NotificationClose:
        client->didHandleNotificationCloseEvent(m_eventID, result,
            m_eventDispatchTime);
        break;
    case Push:
        client->didHandlePushEvent(m_eventID, result, m_eventDispatchTime);
        break;
    case Sync:
        client->didHandleSyncEvent(m_eventID, result, m_eventDispatchTime);
        break;
    case PaymentRequest:
        client->didHandlePaymentRequestEvent(m_eventID, result,
            m_eventDispatchTime);
        break;
    }
    m_executionContext = nullptr;
}

void WaitUntilObserver::consumeWindowInteraction(TimerBase*)
{
    if (!m_executionContext)
        return;
    m_executionContext->consumeWindowInteraction();
=======
    if (!executionContext() || (!m_hasError && --m_pendingActivity))
        return;

    ServiceWorkerGlobalScopeClient* client = ServiceWorkerGlobalScopeClient::from(executionContext());
    WebServiceWorkerEventResult result = m_hasError ? WebServiceWorkerEventResultRejected : WebServiceWorkerEventResultCompleted;
    switch (m_type) {
    case Activate:
        client->didHandleActivateEvent(m_eventID, result);
        break;
    case Install:
        client->didHandleInstallEvent(m_eventID, result);
        break;
    case NotificationClick:
        client->didHandleNotificationClickEvent(m_eventID, result);
        m_consumeWindowInteractionTimer.stop();
        consumeWindowInteraction(nullptr);
        break;
    case Push:
        client->didHandlePushEvent(m_eventID, result);
        break;
    case Sync:
        client->didHandleSyncEvent(m_eventID, result);
        break;
    }
    setContext(nullptr);
}

void WaitUntilObserver::consumeWindowInteraction(Timer<WaitUntilObserver>*)
{
    if (!executionContext())
        return;
    executionContext()->consumeWindowInteraction();
>>>>>>> miniblink49
}

DEFINE_TRACE(WaitUntilObserver)
{
<<<<<<< HEAD
    visitor->trace(m_executionContext);
=======
    ContextLifecycleObserver::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
