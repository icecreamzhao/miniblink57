// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ServiceWorkerRegistrationSync_h
#define ServiceWorkerRegistrationSync_h

<<<<<<< HEAD
#include "modules/serviceworkers/ServiceWorkerRegistration.h"
=======
>>>>>>> miniblink49
#include "platform/Supplementable.h"
#include "platform/heap/Handle.h"

namespace blink {

class SyncManager;
<<<<<<< HEAD
class ServiceWorkerRegistration;

class ServiceWorkerRegistrationSync final
    : public GarbageCollectedFinalized<ServiceWorkerRegistrationSync>,
      public Supplement<ServiceWorkerRegistration> {
    USING_GARBAGE_COLLECTED_MIXIN(ServiceWorkerRegistrationSync);
    WTF_MAKE_NONCOPYABLE(ServiceWorkerRegistrationSync);

=======
class PeriodicSyncManager;
class ServiceWorkerRegistration;

class ServiceWorkerRegistrationSync final : public GarbageCollectedFinalized<ServiceWorkerRegistrationSync>, public HeapSupplement<ServiceWorkerRegistration> {
    USING_GARBAGE_COLLECTED_MIXIN(ServiceWorkerRegistrationSync);
    WTF_MAKE_NONCOPYABLE(ServiceWorkerRegistrationSync);
>>>>>>> miniblink49
public:
    virtual ~ServiceWorkerRegistrationSync();
    static ServiceWorkerRegistrationSync& from(ServiceWorkerRegistration&);

    static SyncManager* sync(ServiceWorkerRegistration&);
<<<<<<< HEAD
    SyncManager* sync();
=======
    static PeriodicSyncManager* periodicSync(ServiceWorkerRegistration&);
    SyncManager* sync();
    PeriodicSyncManager* periodicSync();
>>>>>>> miniblink49

    DECLARE_VIRTUAL_TRACE();

private:
    explicit ServiceWorkerRegistrationSync(ServiceWorkerRegistration*);
    static const char* supplementName();

    Member<ServiceWorkerRegistration> m_registration;
    Member<SyncManager> m_syncManager;
<<<<<<< HEAD
=======
    Member<PeriodicSyncManager> m_periodicSyncManager;
>>>>>>> miniblink49
};

} // namespace blink

#endif // ServiceWorkerRegistrationSync_h
