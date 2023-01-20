// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/background_sync/ServiceWorkerRegistrationSync.h"

=======
#include "config.h"
#include "modules/background_sync/ServiceWorkerRegistrationSync.h"

#include "modules/background_sync/PeriodicSyncManager.h"
>>>>>>> miniblink49
#include "modules/background_sync/SyncManager.h"
#include "modules/serviceworkers/ServiceWorkerRegistration.h"

namespace blink {

<<<<<<< HEAD
ServiceWorkerRegistrationSync::ServiceWorkerRegistrationSync(
    ServiceWorkerRegistration* registration)
=======
ServiceWorkerRegistrationSync::ServiceWorkerRegistrationSync(ServiceWorkerRegistration* registration)
>>>>>>> miniblink49
    : m_registration(registration)
{
}

<<<<<<< HEAD
ServiceWorkerRegistrationSync::~ServiceWorkerRegistrationSync() { }
=======
ServiceWorkerRegistrationSync::~ServiceWorkerRegistrationSync()
{
}
>>>>>>> miniblink49

const char* ServiceWorkerRegistrationSync::supplementName()
{
    return "ServiceWorkerRegistrationSync";
}

<<<<<<< HEAD
ServiceWorkerRegistrationSync& ServiceWorkerRegistrationSync::from(
    ServiceWorkerRegistration& registration)
{
    ServiceWorkerRegistrationSync* supplement = static_cast<ServiceWorkerRegistrationSync*>(
        Supplement<ServiceWorkerRegistration>::from(registration,
            supplementName()));
=======
ServiceWorkerRegistrationSync& ServiceWorkerRegistrationSync::from(ServiceWorkerRegistration& registration)
{
    ServiceWorkerRegistrationSync* supplement = static_cast<ServiceWorkerRegistrationSync*>(HeapSupplement<ServiceWorkerRegistration>::from(registration, supplementName()));
>>>>>>> miniblink49
    if (!supplement) {
        supplement = new ServiceWorkerRegistrationSync(&registration);
        provideTo(registration, supplementName(), supplement);
    }
    return *supplement;
}

<<<<<<< HEAD
SyncManager* ServiceWorkerRegistrationSync::sync(
    ServiceWorkerRegistration& registration)
=======
SyncManager* ServiceWorkerRegistrationSync::sync(ServiceWorkerRegistration& registration)
>>>>>>> miniblink49
{
    return ServiceWorkerRegistrationSync::from(registration).sync();
}

SyncManager* ServiceWorkerRegistrationSync::sync()
{
    if (!m_syncManager)
        m_syncManager = SyncManager::create(m_registration);
    return m_syncManager.get();
}

<<<<<<< HEAD
=======
PeriodicSyncManager* ServiceWorkerRegistrationSync::periodicSync(ServiceWorkerRegistration& registration)
{
    return ServiceWorkerRegistrationSync::from(registration).periodicSync();
}

PeriodicSyncManager* ServiceWorkerRegistrationSync::periodicSync()
{
    if (!m_periodicSyncManager)
        m_periodicSyncManager = PeriodicSyncManager::create(m_registration);
    return m_periodicSyncManager.get();
}

>>>>>>> miniblink49
DEFINE_TRACE(ServiceWorkerRegistrationSync)
{
    visitor->trace(m_registration);
    visitor->trace(m_syncManager);
<<<<<<< HEAD
    Supplement<ServiceWorkerRegistration>::trace(visitor);
=======
    visitor->trace(m_periodicSyncManager);
    HeapSupplement<ServiceWorkerRegistration>::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
