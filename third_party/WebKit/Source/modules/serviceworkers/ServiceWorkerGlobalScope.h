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
#ifndef ServiceWorkerGlobalScope_h
#define ServiceWorkerGlobalScope_h

<<<<<<< HEAD
#include "bindings/modules/v8/RequestOrUSVString.h"
#include "core/workers/WorkerGlobalScope.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "public/platform/modules/serviceworker/WebServiceWorkerRegistration.h"
#include "wtf/Assertions.h"
#include "wtf/Forward.h"
#include <memory>
=======
#include "bindings/modules/v8/UnionTypesModules.h"
#include "core/workers/WorkerGlobalScope.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/Assertions.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"
>>>>>>> miniblink49

namespace blink {

class Dictionary;
<<<<<<< HEAD
=======
class Request;
>>>>>>> miniblink49
class ScriptPromise;
class ScriptState;
class ServiceWorkerClients;
class ServiceWorkerRegistration;
class ServiceWorkerThread;
<<<<<<< HEAD
class WaitUntilObserver;
=======
class StashedPortCollection;
class WaitUntilObserver;
class WebServiceWorkerRegistration;
>>>>>>> miniblink49
class WorkerThreadStartupData;

typedef RequestOrUSVString RequestInfo;

class MODULES_EXPORT ServiceWorkerGlobalScope final : public WorkerGlobalScope {
    DEFINE_WRAPPERTYPEINFO();
<<<<<<< HEAD

public:
    static ServiceWorkerGlobalScope* create(
        ServiceWorkerThread*,
        std::unique_ptr<WorkerThreadStartupData>);
=======
public:
    static PassRefPtrWillBeRawPtr<ServiceWorkerGlobalScope> create(ServiceWorkerThread*, PassOwnPtr<WorkerThreadStartupData>);
>>>>>>> miniblink49

    ~ServiceWorkerGlobalScope() override;
    bool isServiceWorkerGlobalScope() const override { return true; }

<<<<<<< HEAD
    // Counts an evaluated script and its size. Called for each of the main
    // worker script and imported scripts.
    void countScript(size_t scriptSize, size_t cachedMetadataSize);

    // Called when the main worker script is evaluated.
    void didEvaluateWorkerScript();
=======
    // WorkerGlobalScope
    void didEvaluateWorkerScript() override;
>>>>>>> miniblink49

    // ServiceWorkerGlobalScope.idl
    ServiceWorkerClients* clients();
    ServiceWorkerRegistration* registration();
<<<<<<< HEAD

    ScriptPromise fetch(ScriptState*,
        const RequestInfo&,
        const Dictionary&,
        ExceptionState&);

    ScriptPromise skipWaiting(ScriptState*);

    void setRegistration(std::unique_ptr<WebServiceWorkerRegistration::Handle>);

    // EventTarget
    const AtomicString& interfaceName() const override;

    void dispatchExtendableEvent(Event*, WaitUntilObserver*);
=======
    StashedPortCollection* ports();

    ScriptPromise fetch(ScriptState*, const RequestInfo&, const Dictionary&, ExceptionState&);

    void close(ExceptionState&);

    ScriptPromise skipWaiting(ScriptState*);

    void setRegistration(WebServiceWorkerRegistration*);

    // EventTarget
    bool addEventListener(const AtomicString& eventType, PassRefPtr<EventListener>, bool useCapture = false) override;
    const AtomicString& interfaceName() const override;
    bool dispatchEvent(PassRefPtrWillBeRawPtr<Event>) override;

    void dispatchExtendableEvent(PassRefPtrWillBeRawPtr<Event>, WaitUntilObserver*);
>>>>>>> miniblink49

    DEFINE_ATTRIBUTE_EVENT_LISTENER(install);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(activate);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(fetch);
    DEFINE_ATTRIBUTE_EVENT_LISTENER(message);
<<<<<<< HEAD
    DEFINE_ATTRIBUTE_EVENT_LISTENER(foreignfetch);

    DECLARE_VIRTUAL_TRACE();

protected:
    // EventTarget
    DispatchEventResult dispatchEventInternal(Event*) override;
    bool addEventListenerInternal(
        const AtomicString& eventType,
        EventListener*,
        const AddEventListenerOptionsResolved&) override;

private:
    ServiceWorkerGlobalScope(const KURL&,
        const String& userAgent,
        ServiceWorkerThread*,
        double timeOrigin,
        std::unique_ptr<SecurityOrigin::PrivilegeData>,
        WorkerClients*);
    void importScripts(const Vector<String>& urls, ExceptionState&) override;
    CachedMetadataHandler* createWorkerScriptCachedMetadataHandler(
        const KURL& scriptURL,
        const Vector<char>* metaData) override;
    void exceptionThrown(ErrorEvent*) override;

    Member<ServiceWorkerClients> m_clients;
    Member<ServiceWorkerRegistration> m_registration;
=======
    DEFINE_ATTRIBUTE_EVENT_LISTENER(sync);

    DECLARE_VIRTUAL_TRACE();

private:
    class SkipWaitingCallback;

    ServiceWorkerGlobalScope(const KURL&, const String& userAgent, ServiceWorkerThread*, double timeOrigin, const SecurityOrigin*, PassOwnPtrWillBeRawPtr<WorkerClients>);
    void importScripts(const Vector<String>& urls, ExceptionState&) override;
    PassOwnPtr<CachedMetadataHandler> createWorkerScriptCachedMetadataHandler(const KURL& scriptURL, const Vector<char>* metaData) override;
    void logExceptionToConsole(const String& errorMessage, int scriptId, const String& sourceURL, int lineNumber, int columnNumber, PassRefPtrWillBeRawPtr<ScriptCallStack>) override;
    void scriptLoaded(size_t scriptSize, size_t cachedMetadataSize) override;

    PersistentWillBeMember<ServiceWorkerClients> m_clients;
    PersistentWillBeMember<ServiceWorkerRegistration> m_registration;
    PersistentWillBeMember<StashedPortCollection> m_ports;
>>>>>>> miniblink49
    bool m_didEvaluateScript;
    bool m_hadErrorInTopLevelEventHandler;
    unsigned m_eventNestingLevel;
    size_t m_scriptCount;
    size_t m_scriptTotalSize;
    size_t m_scriptCachedMetadataTotalSize;
};

<<<<<<< HEAD
DEFINE_TYPE_CASTS(ServiceWorkerGlobalScope,
    ExecutionContext,
    context,
    context->isServiceWorkerGlobalScope(),
    context.isServiceWorkerGlobalScope());
=======
DEFINE_TYPE_CASTS(ServiceWorkerGlobalScope, ExecutionContext, context, context->isServiceWorkerGlobalScope(), context.isServiceWorkerGlobalScope());
>>>>>>> miniblink49

} // namespace blink

#endif // ServiceWorkerGlobalScope_h
