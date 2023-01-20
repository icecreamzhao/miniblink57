// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PresentationAvailability_h
#define PresentationAvailability_h

<<<<<<< HEAD
#include "bindings/core/v8/ActiveScriptWrappable.h"
#include "core/dom/SuspendableObject.h"
#include "core/events/EventTarget.h"
#include "core/page/PageVisibilityObserver.h"
#include "modules/ModulesExport.h"
#include "modules/presentation/PresentationPromiseProperty.h"
#include "platform/weborigin/KURL.h"
#include "public/platform/WebURL.h"
#include "public/platform/WebVector.h"
#include "public/platform/modules/presentation/WebPresentationAvailabilityObserver.h"
#include "wtf/Vector.h"
=======
#include "core/dom/ActiveDOMObject.h"
#include "core/dom/DocumentVisibilityObserver.h"
#include "core/events/EventTarget.h"
#include "public/platform/modules/presentation/WebPresentationAvailabilityObserver.h"
>>>>>>> miniblink49

namespace blink {

class ExecutionContext;
<<<<<<< HEAD

// Expose whether there is a presentation display available for |url|. The
// object will be initialized with a default value passed via ::take() and will
// then subscribe to receive callbacks if the status for |url| were to
// change. The object will only listen to changes when required.
class MODULES_EXPORT PresentationAvailability final
    : public EventTargetWithInlineData,
      public ActiveScriptWrappable<PresentationAvailability>,
      public SuspendableObject,
      public PageVisibilityObserver,
      public WebPresentationAvailabilityObserver {
    USING_GARBAGE_COLLECTED_MIXIN(PresentationAvailability);
    DEFINE_WRAPPERTYPEINFO();

public:
    static PresentationAvailability* take(PresentationAvailabilityProperty*,
        const WTF::Vector<KURL>&,
        bool);
=======
class ScriptPromiseResolver;

// Expose whether there is a presentation display available. The object will be
// initialized with a default value passed via ::take() and will then subscribe
// to receive callbacks if the status were to change. The object will only
// listen to changes when required.
class PresentationAvailability final
    : public RefCountedGarbageCollectedEventTargetWithInlineData<PresentationAvailability>
    , public ActiveDOMObject
    , public DocumentVisibilityObserver
    , public WebPresentationAvailabilityObserver {
    REFCOUNTED_GARBAGE_COLLECTED_EVENT_TARGET(PresentationAvailability);
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(PresentationAvailability);
    DEFINE_WRAPPERTYPEINFO();
public:
    static PresentationAvailability* take(ScriptPromiseResolver*, bool);
>>>>>>> miniblink49
    ~PresentationAvailability() override;

    // EventTarget implementation.
    const AtomicString& interfaceName() const override;
<<<<<<< HEAD
    ExecutionContext* getExecutionContext() const override;

    // WebPresentationAvailabilityObserver implementation.
    void availabilityChanged(bool) override;
    const WebVector<WebURL>& urls() const override;

    // ScriptWrappable implementation.
    bool hasPendingActivity() const final;

    // SuspendableObject implementation.
    void suspend() override;
    void resume() override;
    void contextDestroyed(ExecutionContext*) override;

    // PageVisibilityObserver implementation.
    void pageVisibilityChanged() override;
=======
    ExecutionContext* executionContext() const override;

    // WebPresentationAvailabilityObserver implementation.
    void availabilityChanged(bool) override;

    // ActiveDOMObject implementation.
    bool hasPendingActivity() const override;
    void suspend() override;
    void resume() override;
    void stop() override;

    // DocumentVisibilityObserver implementation.
    void didChangeVisibilityState(PageVisibilityState) override;
>>>>>>> miniblink49

    bool value() const;

    DEFINE_ATTRIBUTE_EVENT_LISTENER(change);

    DECLARE_VIRTUAL_TRACE();

<<<<<<< HEAD
protected:
    // EventTarget implementation.
    void addedEventListener(const AtomicString& eventType,
        RegisteredEventListener&) override;

private:
    // Current state of the SuspendableObject. It is Active when created. It
=======
private:
    // Current state of the ActiveDOMObject. It is Active when created. It
>>>>>>> miniblink49
    // becomes Suspended when suspend() is called and moves back to Active if
    // resume() is called. It becomes Inactive when stop() is called or at
    // destruction time.
    enum class State : char {
        Active,
        Suspended,
        Inactive,
    };

<<<<<<< HEAD
    PresentationAvailability(ExecutionContext*, const WTF::Vector<KURL>&, bool);
=======
    PresentationAvailability(ExecutionContext*, bool);
>>>>>>> miniblink49

    void setState(State);
    void updateListening();

<<<<<<< HEAD
    WebVector<WebURL> m_urls;
=======
>>>>>>> miniblink49
    bool m_value;
    State m_state;
};

} // namespace blink

#endif // PresentationAvailability_h
