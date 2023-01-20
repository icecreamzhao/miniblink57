// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/push_messaging/ServiceWorkerRegistrationPush.h"

#include "modules/push_messaging/PushManager.h"
#include "modules/serviceworkers/ServiceWorkerRegistration.h"

namespace blink {

<<<<<<< HEAD
ServiceWorkerRegistrationPush::ServiceWorkerRegistrationPush(
    ServiceWorkerRegistration* registration)
=======
ServiceWorkerRegistrationPush::ServiceWorkerRegistrationPush(ServiceWorkerRegistration* registration)
>>>>>>> miniblink49
    : m_registration(registration)
{
}

<<<<<<< HEAD
ServiceWorkerRegistrationPush::~ServiceWorkerRegistrationPush() { }
=======
ServiceWorkerRegistrationPush::~ServiceWorkerRegistrationPush()
{
}
>>>>>>> miniblink49

const char* ServiceWorkerRegistrationPush::supplementName()
{
    return "ServiceWorkerRegistrationPush";
}

<<<<<<< HEAD
ServiceWorkerRegistrationPush& ServiceWorkerRegistrationPush::from(
    ServiceWorkerRegistration& registration)
{
    ServiceWorkerRegistrationPush* supplement = static_cast<ServiceWorkerRegistrationPush*>(
        Supplement<ServiceWorkerRegistration>::from(registration,
            supplementName()));
=======
ServiceWorkerRegistrationPush& ServiceWorkerRegistrationPush::from(ServiceWorkerRegistration& registration)
{
    ServiceWorkerRegistrationPush* supplement = static_cast<ServiceWorkerRegistrationPush*>(HeapSupplement<ServiceWorkerRegistration>::from(registration, supplementName()));
>>>>>>> miniblink49
    if (!supplement) {
        supplement = new ServiceWorkerRegistrationPush(&registration);
        provideTo(registration, supplementName(), supplement);
    }
    return *supplement;
}

<<<<<<< HEAD
PushManager* ServiceWorkerRegistrationPush::pushManager(
    ServiceWorkerRegistration& registration)
=======
PushManager* ServiceWorkerRegistrationPush::pushManager(ServiceWorkerRegistration& registration)
>>>>>>> miniblink49
{
    return ServiceWorkerRegistrationPush::from(registration).pushManager();
}

PushManager* ServiceWorkerRegistrationPush::pushManager()
{
    if (!m_pushManager)
        m_pushManager = PushManager::create(m_registration);
    return m_pushManager.get();
}

DEFINE_TRACE(ServiceWorkerRegistrationPush)
{
    visitor->trace(m_registration);
    visitor->trace(m_pushManager);
<<<<<<< HEAD
    Supplement<ServiceWorkerRegistration>::trace(visitor);
=======
    HeapSupplement<ServiceWorkerRegistration>::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
