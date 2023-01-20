// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PushManager_h
#define PushManager_h

#include "bindings/core/v8/ScriptWrappable.h"
<<<<<<< HEAD
#include "modules/ModulesExport.h"
=======
>>>>>>> miniblink49
#include "platform/heap/Handle.h"

namespace blink {

<<<<<<< HEAD
class ExceptionState;
class PushSubscriptionOptionsInit;
=======
class PushSubscriptionOptions;
>>>>>>> miniblink49
class ScriptPromise;
class ScriptState;
class ServiceWorkerRegistration;

<<<<<<< HEAD
class MODULES_EXPORT PushManager final : public GarbageCollected<PushManager>,
                                         public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

=======
class PushManager final : public GarbageCollected<PushManager>, public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();
>>>>>>> miniblink49
public:
    static PushManager* create(ServiceWorkerRegistration* registration)
    {
        return new PushManager(registration);
    }

<<<<<<< HEAD
    ScriptPromise subscribe(ScriptState*,
        const PushSubscriptionOptionsInit&,
        ExceptionState&);
    ScriptPromise getSubscription(ScriptState*);
    ScriptPromise permissionState(ScriptState*,
        const PushSubscriptionOptionsInit&,
        ExceptionState&);
=======
    ScriptPromise subscribe(ScriptState*, const PushSubscriptionOptions&);
    ScriptPromise getSubscription(ScriptState*);
    ScriptPromise permissionState(ScriptState*, const PushSubscriptionOptions&);
>>>>>>> miniblink49

    DECLARE_TRACE();

private:
    explicit PushManager(ServiceWorkerRegistration*);

    Member<ServiceWorkerRegistration> m_registration;
};

} // namespace blink

#endif // PushManager_h
