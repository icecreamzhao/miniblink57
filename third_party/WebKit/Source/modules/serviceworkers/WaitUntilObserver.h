// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WaitUntilObserver_h
#define WaitUntilObserver_h

<<<<<<< HEAD
=======
#include "core/dom/ContextLifecycleObserver.h"
>>>>>>> miniblink49
#include "modules/ModulesExport.h"
#include "modules/serviceworkers/ServiceWorkerGlobalScopeClient.h"
#include "platform/Timer.h"
#include "wtf/Forward.h"
<<<<<<< HEAD
=======
#include "wtf/RefCounted.h"
>>>>>>> miniblink49

namespace blink {

class ExceptionState;
class ExecutionContext;
<<<<<<< HEAD
class ScriptPromise;
=======
>>>>>>> miniblink49
class ScriptState;
class ScriptValue;

// Created for each ExtendableEvent instance.
<<<<<<< HEAD
class MODULES_EXPORT WaitUntilObserver final
    : public GarbageCollectedFinalized<WaitUntilObserver> {
public:
    enum EventType {
        Activate,
        Fetch,
        Install,
        Message,
        NotificationClick,
        NotificationClose,
        PaymentRequest,
=======
class MODULES_EXPORT WaitUntilObserver final : public GarbageCollectedFinalized<WaitUntilObserver>, public ContextLifecycleObserver {
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(WaitUntilObserver);
public:
    enum EventType {
        Activate,
        Install,
        NotificationClick,
>>>>>>> miniblink49
        Push,
        Sync
    };

    static WaitUntilObserver* create(ExecutionContext*, EventType, int eventID);

    // Must be called before and after dispatching the event.
    void willDispatchEvent();
    void didDispatchEvent(bool errorOccurred);

    // Observes the promise and delays calling the continuation until
    // the given promise is resolved or rejected.
<<<<<<< HEAD
    void waitUntil(ScriptState*, ScriptPromise, ExceptionState&);

    // These methods can be called when the lifecycle of ExtendableEvent
    // observed by this WaitUntilObserver should be extended by other reason
    // than ExtendableEvent.waitUntil.
    // Note: There is no need to call decrementPendingActivity() after the context
    // is being destroyed.
    void incrementPendingActivity();
    void decrementPendingActivity();
=======
    void waitUntil(ScriptState*, const ScriptValue&, ExceptionState&);
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
    friend class InternalsServiceWorker;
    class ThenFunction;

    WaitUntilObserver(ExecutionContext*, EventType, int eventID);

    void reportError(const ScriptValue&);

<<<<<<< HEAD
    void consumeWindowInteraction(TimerBase*);

    Member<ExecutionContext> m_executionContext;
    EventType m_type;
    int m_eventID;
    int m_pendingActivity = 0;
    bool m_hasError = false;
    bool m_eventDispatched = false;
    double m_eventDispatchTime = 0;
    TaskRunnerTimer<WaitUntilObserver> m_consumeWindowInteractionTimer;
=======
    void incrementPendingActivity();
    void decrementPendingActivity();

    void consumeWindowInteraction(Timer<WaitUntilObserver>*);

    EventType m_type;
    int m_eventID;
    int m_pendingActivity;
    bool m_hasError;
    bool m_eventDispatched;
    Timer<WaitUntilObserver> m_consumeWindowInteractionTimer;
>>>>>>> miniblink49
};

} // namespace blink

#endif // WaitUntilObserver_h
