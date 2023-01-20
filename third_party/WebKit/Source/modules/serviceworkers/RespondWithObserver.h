// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef RespondWithObserver_h
#define RespondWithObserver_h

#include "core/dom/ContextLifecycleObserver.h"
<<<<<<< HEAD
#include "core/events/EventTarget.h"
#include "modules/ModulesExport.h"
#include "modules/serviceworkers/WaitUntilObserver.h"
#include "platform/heap/Handle.h"
#include "public/platform/WebURLRequest.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerResponseError.h"
=======
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "public/platform/WebServiceWorkerResponseError.h"
#include "public/platform/WebURLRequest.h"
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

// This class observes the service worker's handling of a FetchEvent and
// notifies the client.
<<<<<<< HEAD
class MODULES_EXPORT RespondWithObserver
    : public GarbageCollectedFinalized<RespondWithObserver>,
      public ContextLifecycleObserver {
    USING_GARBAGE_COLLECTED_MIXIN(RespondWithObserver);

public:
    virtual ~RespondWithObserver();

    static RespondWithObserver* create(ExecutionContext*,
        int fetchEventID,
        const KURL& requestURL,
        WebURLRequest::FetchRequestMode,
        WebURLRequest::FetchRedirectMode,
        WebURLRequest::FrameType,
        WebURLRequest::RequestContext,
        WaitUntilObserver*);

    void contextDestroyed(ExecutionContext*) override;

    void willDispatchEvent();
    void didDispatchEvent(DispatchEventResult dispatchResult);

    // Observes the promise and delays calling didHandleFetchEvent() until the
    // given promise is resolved or rejected.
    void respondWith(ScriptState*, ScriptPromise, ExceptionState&);

    void responseWasRejected(WebServiceWorkerResponseError);
    virtual void responseWasFulfilled(const ScriptValue&);

    DECLARE_VIRTUAL_TRACE();

protected:
    RespondWithObserver(ExecutionContext*,
        int fetchEventID,
        const KURL& requestURL,
        WebURLRequest::FetchRequestMode,
        WebURLRequest::FetchRedirectMode,
        WebURLRequest::FrameType,
        WebURLRequest::RequestContext,
        WaitUntilObserver*);

private:
    class ThenFunction;

    const int m_fetchEventID;
    const KURL m_requestURL;
    const WebURLRequest::FetchRequestMode m_requestMode;
    const WebURLRequest::FetchRedirectMode m_redirectMode;
    const WebURLRequest::FrameType m_frameType;
    const WebURLRequest::RequestContext m_requestContext;

    double m_eventDispatchTime = 0;

    enum State { Initial,
        Pending,
        Done };
    State m_state;

    // RespondWith should ensure the ExtendableEvent is alive until the promise
    // passed to RespondWith is resolved. The lifecycle of the ExtendableEvent
    // is controlled by WaitUntilObserver, so not only
    // WaitUntilObserver::ThenFunction but RespondWith needs to have a strong
    // reference to the WaitUntilObserver.
    Member<WaitUntilObserver> m_observer;
=======
class MODULES_EXPORT RespondWithObserver final : public GarbageCollectedFinalized<RespondWithObserver>, public ContextLifecycleObserver {
    WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(RespondWithObserver);
public:
    static RespondWithObserver* create(ExecutionContext*, int eventID, WebURLRequest::FetchRequestMode, WebURLRequest::FrameType);

    void contextDestroyed() override;

    void didDispatchEvent(bool defaultPrevented);

    // Observes the promise and delays calling didHandleFetchEvent() until the
    // given promise is resolved or rejected.
    void respondWith(ScriptState*, const ScriptValue&, ExceptionState&);

    void responseWasRejected(WebServiceWorkerResponseError);
    void responseWasFulfilled(const ScriptValue&);

    DECLARE_VIRTUAL_TRACE();

private:
    class ThenFunction;

    RespondWithObserver(ExecutionContext*, int eventID, WebURLRequest::FetchRequestMode, WebURLRequest::FrameType);

    int m_eventID;
    WebURLRequest::FetchRequestMode m_requestMode;
    WebURLRequest::FrameType m_frameType;

    enum State { Initial, Pending, Done };
    State m_state;
>>>>>>> miniblink49
};

} // namespace blink

#endif // RespondWithObserver_h
