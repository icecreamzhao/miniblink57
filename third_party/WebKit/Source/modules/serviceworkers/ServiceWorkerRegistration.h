// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ServiceWorkerRegistration_h
#define ServiceWorkerRegistration_h

<<<<<<< HEAD
#include "bindings/core/v8/ActiveScriptWrappable.h"
#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "core/dom/ContextLifecycleObserver.h"
#include "core/events/EventTarget.h"
#include "modules/serviceworkers/NavigationPreloadManager.h"
#include "modules/serviceworkers/ServiceWorker.h"
#include "modules/serviceworkers/ServiceWorkerRegistration.h"
#include "platform/Supplementable.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerRegistration.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerRegistrationProxy.h"
#include "wtf/Forward.h"
#include <memory>
=======
#include "core/dom/ActiveDOMObject.h"
#include "core/events/EventTarget.h"
#include "modules/serviceworkers/ServiceWorker.h"
#include "modules/serviceworkers/ServiceWorkerRegistration.h"
#include "platform/Supplementable.h"
#include "public/platform/WebServiceWorkerRegistration.h"
#include "public/platform/WebServiceWorkerRegistrationProxy.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"
>>>>>>> miniblink49

namespace blink {

class ScriptPromise;
<<<<<<< HEAD
class ScriptState;

// The implementation of a service worker registration object in Blink. Actual
// registration representation is in the embedder and this class accesses it
// via WebServiceWorkerRegistration::Handle object.
class ServiceWorkerRegistration final
    : public EventTargetWithInlineData,
      public ActiveScriptWrappable<ServiceWorkerRegistration>,
      public ContextLifecycleObserver,
      public WebServiceWorkerRegistrationProxy,
      public Supplementable<ServiceWorkerRegistration> {
    DEFINE_WRAPPERTYPEINFO();
    USING_GARBAGE_COLLECTED_MIXIN(ServiceWorkerRegistration);
    USING_PRE_FINALIZER(ServiceWorkerRegistration, dispose);

public:
    // Called from CallbackPromiseAdapter.
    using WebType = std::unique_ptr<WebServiceWorkerRegistration::Handle>;
    static ServiceWorkerRegistration* take(
        ScriptPromiseResolver*,
        std::unique_ptr<WebServiceWorkerRegistration::Handle>);

    // ScriptWrappable overrides.
    bool hasPendingActivity() const final;

    // EventTarget overrides.
    const AtomicString& interfaceName() const override;
    ExecutionContext* getExecutionContext() const override
    {
        return ContextLifecycleObserver::getExecutionContext();
    }

    // WebServiceWorkerRegistrationProxy overrides.
    void dispatchUpdateFoundEvent() override;
    void setInstalling(std::unique_ptr<WebServiceWorker::Handle>) override;
    void setWaiting(std::unique_ptr<WebServiceWorker::Handle>) override;
    void setActive(std::unique_ptr<WebServiceWorker::Handle>) override;

    // Returns an existing registration object for the handle if it exists.
    // Otherwise, returns a new registration object.
    static ServiceWorkerRegistration* getOrCreate(
        ExecutionContext*,
        std::unique_ptr<WebServiceWorkerRegistration::Handle>);

    ServiceWorker* installing() { return m_installing; }
    ServiceWorker* waiting() { return m_waiting; }
    ServiceWorker* active() { return m_active; }
    NavigationPreloadManager* navigationPreload();

    String scope() const;

    WebServiceWorkerRegistration* webRegistration()
    {
        return m_handle->registration();
    }

    ScriptPromise update(ScriptState*);
=======
class ScriptPromiseResolver;
class ScriptState;
class WebServiceWorkerProvider;

class ServiceWorkerRegistration final
    : public RefCountedGarbageCollectedEventTargetWithInlineData<ServiceWorkerRegistration>
    , public ActiveDOMObject
    , public WebServiceWorkerRegistrationProxy
    , public HeapSupplementable<ServiceWorkerRegistration> {
    DEFINE_WRAPPERTYPEINFO();
    REFCOUNTED_GARBAGE_COLLECTED_EVENT_TARGET(ServiceWorkerRegistration);
    USING_GARBAGE_COLLECTED_MIXIN(ServiceWorkerRegistration);
public:
    // EventTarget overrides.
    const AtomicString& interfaceName() const override;
    ExecutionContext* executionContext() const override { return ActiveDOMObject::executionContext(); }

    // WebServiceWorkerRegistrationProxy overrides.
    void dispatchUpdateFoundEvent() override;
    void setInstalling(WebServiceWorker*) override;
    void setWaiting(WebServiceWorker*) override;
    void setActive(WebServiceWorker*) override;

    // For CallbackPromiseAdapter.
    typedef WebServiceWorkerRegistration WebType;
    static ServiceWorkerRegistration* from(ExecutionContext*, WebType* registration);
    static ServiceWorkerRegistration* take(ScriptPromiseResolver*, WebType* registration);
    static void dispose(WebType* registration);

    PassRefPtrWillBeRawPtr<ServiceWorker> installing() { return m_installing.get(); }
    PassRefPtrWillBeRawPtr<ServiceWorker> waiting() { return m_waiting.get(); }
    PassRefPtrWillBeRawPtr<ServiceWorker> active() { return m_active.get(); }

    String scope() const;

    WebServiceWorkerRegistration* webRegistration() { return m_outerRegistration.get(); }

    void update(ScriptState*, ExceptionState&);
>>>>>>> miniblink49
    ScriptPromise unregister(ScriptState*);

    DEFINE_ATTRIBUTE_EVENT_LISTENER(updatefound);

    ~ServiceWorkerRegistration() override;

<<<<<<< HEAD
    DECLARE_VIRTUAL_TRACE();

private:
    ServiceWorkerRegistration(
        ExecutionContext*,
        std::unique_ptr<WebServiceWorkerRegistration::Handle>);
    void dispose();

    // ContextLifecycleObserver overrides.
    void contextDestroyed(ExecutionContext*) override;

    // A handle to the registration representation in the embedder.
    std::unique_ptr<WebServiceWorkerRegistration::Handle> m_handle;

    Member<ServiceWorker> m_installing;
    Member<ServiceWorker> m_waiting;
    Member<ServiceWorker> m_active;
    Member<NavigationPreloadManager> m_navigationPreload;
=======
    // Eager finalization needed to promptly release owned WebServiceWorkerRegistration.
    EAGERLY_FINALIZE();
    DECLARE_VIRTUAL_TRACE();

private:
    static ServiceWorkerRegistration* getOrCreate(ExecutionContext*, WebServiceWorkerRegistration*);
    ServiceWorkerRegistration(ExecutionContext*, PassOwnPtr<WebServiceWorkerRegistration>);

    // ActiveDOMObject overrides.
    bool hasPendingActivity() const override;
    void stop() override;

    OwnPtr<WebServiceWorkerRegistration> m_outerRegistration;
    WebServiceWorkerProvider* m_provider;
    RefPtrWillBeMember<ServiceWorker> m_installing;
    RefPtrWillBeMember<ServiceWorker> m_waiting;
    RefPtrWillBeMember<ServiceWorker> m_active;
>>>>>>> miniblink49

    bool m_stopped;
};

class ServiceWorkerRegistrationArray {
<<<<<<< HEAD
    STATIC_ONLY(ServiceWorkerRegistrationArray);

public:
    // Called from CallbackPromiseAdapter.
    using WebType = std::unique_ptr<
        WebVector<std::unique_ptr<WebServiceWorkerRegistration::Handle>>>;
    static HeapVector<Member<ServiceWorkerRegistration>> take(
        ScriptPromiseResolver* resolver,
        WebType webServiceWorkerRegistrations)
    {
        HeapVector<Member<ServiceWorkerRegistration>> registrations;
        for (auto& registration : *webServiceWorkerRegistrations) {
            registrations.push_back(
                ServiceWorkerRegistration::take(resolver, std::move(registration)));
        }
        return registrations;
    }
=======
public:
    typedef WebVector<WebServiceWorkerRegistration*> WebType;
    static HeapVector<Member<ServiceWorkerRegistration>> take(ScriptPromiseResolver* resolver, PassOwnPtr<WebType> webServiceWorkerRegistrations)
    {
        HeapVector<Member<ServiceWorkerRegistration>> registrations;
        for (WebServiceWorkerRegistration* registration : *webServiceWorkerRegistrations)
            registrations.append(ServiceWorkerRegistration::take(resolver, registration));
        return registrations;
    }

    static void dispose(PassOwnPtr<WebType> webServiceWorkerRegistrations)
    {
        for (WebServiceWorkerRegistration* registration : *webServiceWorkerRegistrations)
            ServiceWorkerRegistration::dispose(registration);
    }

private:
    WTF_MAKE_NONCOPYABLE(ServiceWorkerRegistrationArray);
    ServiceWorkerRegistrationArray() = delete;
>>>>>>> miniblink49
};

} // namespace blink

#endif // ServiceWorkerRegistration_h
