// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ServiceWorkerClients_h
#define ServiceWorkerClients_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "modules/serviceworkers/ClientQueryOptions.h"
#include "platform/heap/Handle.h"
<<<<<<< HEAD
#include "public/platform/modules/serviceworker/WebServiceWorkerClientsInfo.h"
=======
#include "public/platform/WebServiceWorkerClientsInfo.h"
>>>>>>> miniblink49

namespace blink {

class ScriptPromise;
class ScriptState;

<<<<<<< HEAD
class ServiceWorkerClients final
    : public GarbageCollected<ServiceWorkerClients>,
      public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

=======
class ServiceWorkerClients final : public GarbageCollected<ServiceWorkerClients>, public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();
>>>>>>> miniblink49
public:
    static ServiceWorkerClients* create();

    // Clients.idl
<<<<<<< HEAD
    ScriptPromise get(ScriptState*, const String& id);
=======
>>>>>>> miniblink49
    ScriptPromise matchAll(ScriptState*, const ClientQueryOptions&);
    ScriptPromise openWindow(ScriptState*, const String& url);
    ScriptPromise claim(ScriptState*);

    DEFINE_INLINE_TRACE() { }

private:
    ServiceWorkerClients();
};

} // namespace blink

#endif // ServiceWorkerClients_h
