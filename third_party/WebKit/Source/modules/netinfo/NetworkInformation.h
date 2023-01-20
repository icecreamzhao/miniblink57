// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NetworkInformation_h
#define NetworkInformation_h

<<<<<<< HEAD
#include "bindings/core/v8/ActiveScriptWrappable.h"
#include "core/dom/ContextLifecycleObserver.h"
=======
#include "core/dom/ActiveDOMObject.h"
>>>>>>> miniblink49
#include "core/events/EventTarget.h"
#include "core/page/NetworkStateNotifier.h"
#include "public/platform/WebConnectionType.h"

namespace blink {

class ExecutionContext;

class NetworkInformation final
<<<<<<< HEAD
    : public EventTargetWithInlineData,
      public ActiveScriptWrappable<NetworkInformation>,
      public ContextLifecycleObserver,
      public NetworkStateNotifier::NetworkStateObserver {
    USING_GARBAGE_COLLECTED_MIXIN(NetworkInformation);
    DEFINE_WRAPPERTYPEINFO();

=======
    : public RefCountedGarbageCollectedEventTargetWithInlineData<NetworkInformation>
    , public ActiveDOMObject
    , public NetworkStateNotifier::NetworkStateObserver {
    REFCOUNTED_GARBAGE_COLLECTED_EVENT_TARGET(NetworkInformation);
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(NetworkInformation);
    DEFINE_WRAPPERTYPEINFO();
>>>>>>> miniblink49
public:
    static NetworkInformation* create(ExecutionContext*);
    ~NetworkInformation() override;

    String type() const;
<<<<<<< HEAD
    double downlinkMax() const;

    // NetworkStateObserver overrides.
    void connectionChange(WebConnectionType, double downlinkMaxMbps) override;

    // EventTarget overrides.
    const AtomicString& interfaceName() const override;
    ExecutionContext* getExecutionContext() const override;
    void removeAllEventListeners() override;

    // ScriptWrappable
    bool hasPendingActivity() const final;

    // ContextLifecycleObserver overrides.
    void contextDestroyed(ExecutionContext*) override;

    DECLARE_VIRTUAL_TRACE();

    DEFINE_ATTRIBUTE_EVENT_LISTENER(change);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(typechange); // Deprecated

protected:
    // EventTarget overrides.
    void addedEventListener(const AtomicString& eventType,
        RegisteredEventListener&) final;
    void removedEventListener(const AtomicString& eventType,
        const RegisteredEventListener&) final;
=======

    void connectionTypeChange(WebConnectionType) override;

    // EventTarget overrides.
    const AtomicString& interfaceName() const override;
    ExecutionContext* executionContext() const override;
    bool addEventListener(const AtomicString& eventType, PassRefPtr<EventListener>, bool useCapture = false) override;
    bool removeEventListener(const AtomicString& eventType, PassRefPtr<EventListener>, bool useCapture = false) override;
    void removeAllEventListeners() override;

    // ActiveDOMObject overrides.
    bool hasPendingActivity() const override;
    void stop() override;

    DECLARE_VIRTUAL_TRACE();

    DEFINE_ATTRIBUTE_EVENT_LISTENER(typechange);
>>>>>>> miniblink49

private:
    explicit NetworkInformation(ExecutionContext*);
    void startObserving();
    void stopObserving();

    // Touched only on context thread.
    WebConnectionType m_type;

<<<<<<< HEAD
    // Touched only on context thread.
    double m_downlinkMaxMbps;

    // Whether this object is listening for events from NetworkStateNotifier.
    bool m_observing;

    // Whether ContextLifecycleObserver::contextDestroyed has been called.
=======
    // Whether this object is listening for events from NetworkStateNotifier.
    bool m_observing;

    // Whether ActiveDOMObject::stop has been called.
>>>>>>> miniblink49
    bool m_contextStopped;
};

} // namespace blink

#endif // NetworkInformation_h
