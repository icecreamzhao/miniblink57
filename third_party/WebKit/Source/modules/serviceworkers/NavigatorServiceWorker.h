// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NavigatorServiceWorker_h
#define NavigatorServiceWorker_h

#include "core/frame/Navigator.h"
#include "modules/ModulesExport.h"
#include "platform/Supplementable.h"
#include "platform/heap/Handle.h"

namespace blink {

class Document;
class ExceptionState;
class Navigator;
class ServiceWorkerContainer;

<<<<<<< HEAD
class MODULES_EXPORT NavigatorServiceWorker final
    : public GarbageCollected<NavigatorServiceWorker>,
      public Supplement<Navigator> {
    USING_GARBAGE_COLLECTED_MIXIN(NavigatorServiceWorker);

=======
class MODULES_EXPORT NavigatorServiceWorker final : public GarbageCollectedFinalized<NavigatorServiceWorker>, public HeapSupplement<Navigator>, public DOMWindowProperty {
    USING_GARBAGE_COLLECTED_MIXIN(NavigatorServiceWorker);
>>>>>>> miniblink49
public:
    static NavigatorServiceWorker* from(Document&);
    static NavigatorServiceWorker& from(Navigator&);
    static NavigatorServiceWorker* toNavigatorServiceWorker(Navigator&);
<<<<<<< HEAD
    static ServiceWorkerContainer* serviceWorker(ExecutionContext*,
        Navigator&,
        ExceptionState&);
    static ServiceWorkerContainer* serviceWorker(ExecutionContext*,
        Navigator&,
        String& errorMessage);
    void clearServiceWorker();
=======

    virtual ~NavigatorServiceWorker();

    static ServiceWorkerContainer* serviceWorker(Navigator&, ExceptionState&);
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
    explicit NavigatorServiceWorker(Navigator&);
<<<<<<< HEAD
    ServiceWorkerContainer* serviceWorker(LocalFrame*, ExceptionState&);
    ServiceWorkerContainer* serviceWorker(LocalFrame*, String& errorMessage);

    static const char* supplementName();

=======
    ServiceWorkerContainer* serviceWorker(ExceptionState&);

    static const char* supplementName();

    // DOMWindowProperty override.
    void willDetachGlobalObjectFromFrame() override;

>>>>>>> miniblink49
    Member<ServiceWorkerContainer> m_serviceWorker;
};

} // namespace blink

#endif // NavigatorServiceWorker_h
