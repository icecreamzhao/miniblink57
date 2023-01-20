// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/battery/BatteryManager.h"

#include "core/dom/DOMException.h"
#include "core/dom/Document.h"
#include "core/events/Event.h"
#include "modules/battery/BatteryDispatcher.h"
#include "wtf/Assertions.h"
=======
#include "config.h"
#include "modules/battery/BatteryManager.h"

#include "core/dom/Document.h"
#include "core/events/Event.h"
#include "modules/battery/BatteryDispatcher.h"
#include "modules/battery/BatteryStatus.h"
>>>>>>> miniblink49

namespace blink {

BatteryManager* BatteryManager::create(ExecutionContext* context)
{
    BatteryManager* batteryManager = new BatteryManager(context);
    batteryManager->suspendIfNeeded();
    return batteryManager;
}

<<<<<<< HEAD
BatteryManager::~BatteryManager() { }

BatteryManager::BatteryManager(ExecutionContext* context)
    : SuspendableObject(context)
    , PlatformEventController(toDocument(context)->page())
=======
BatteryManager::~BatteryManager()
{
#if !ENABLE(OILPAN)
    stopUpdating();
#endif
}

BatteryManager::BatteryManager(ExecutionContext* context)
    : ActiveDOMObject(context)
    , PlatformEventController(toDocument(context)->page())
    , m_batteryStatus(BatteryStatus::create())
>>>>>>> miniblink49
{
}

ScriptPromise BatteryManager::startRequest(ScriptState* scriptState)
{
    if (!m_batteryProperty) {
<<<<<<< HEAD
        m_batteryProperty = new BatteryProperty(scriptState->getExecutionContext(),
            this, BatteryProperty::Ready);

        // If the context is in a stopped state already, do not start updating.
        if (!getExecutionContext() || getExecutionContext()->isContextDestroyed()) {
=======
        m_batteryProperty = new BatteryProperty(scriptState->executionContext(), this, BatteryProperty::Ready);

        // If the context is in a stopped state already, do not start updating.
        if (!executionContext() || executionContext()->activeDOMObjectsAreStopped()) {
>>>>>>> miniblink49
            m_batteryProperty->resolve(this);
        } else {
            m_hasEventListener = true;
            startUpdating();
        }
    }

    return m_batteryProperty->promise(scriptState->world());
}

bool BatteryManager::charging()
{
<<<<<<< HEAD
    return m_batteryStatus.charging();
=======
    return m_batteryStatus->charging();
>>>>>>> miniblink49
}

double BatteryManager::chargingTime()
{
<<<<<<< HEAD
    return m_batteryStatus.charging_time();
=======
    return m_batteryStatus->chargingTime();
>>>>>>> miniblink49
}

double BatteryManager::dischargingTime()
{
<<<<<<< HEAD
    return m_batteryStatus.discharging_time();
=======
    return m_batteryStatus->dischargingTime();
>>>>>>> miniblink49
}

double BatteryManager::level()
{
<<<<<<< HEAD
    return m_batteryStatus.level();
=======
    return m_batteryStatus->level();
>>>>>>> miniblink49
}

void BatteryManager::didUpdateData()
{
<<<<<<< HEAD
    DCHECK(m_batteryProperty);

    BatteryStatus oldStatus = m_batteryStatus;
    m_batteryStatus = *BatteryDispatcher::instance().latestData();

    if (m_batteryProperty->getState() == ScriptPromisePropertyBase::Pending) {
=======
    ASSERT(m_batteryProperty);

    BatteryStatus* oldStatus = m_batteryStatus;
    m_batteryStatus = BatteryDispatcher::instance().latestData();

    if (m_batteryProperty->state() == ScriptPromisePropertyBase::Pending) {
>>>>>>> miniblink49
        m_batteryProperty->resolve(this);
        return;
    }

<<<<<<< HEAD
    Document* document = toDocument(getExecutionContext());
    DCHECK(document);
    if (document->isContextSuspended() || document->isContextDestroyed())
        return;

    if (m_batteryStatus.charging() != oldStatus.charging())
        dispatchEvent(Event::create(EventTypeNames::chargingchange));
    if (m_batteryStatus.charging_time() != oldStatus.charging_time())
        dispatchEvent(Event::create(EventTypeNames::chargingtimechange));
    if (m_batteryStatus.discharging_time() != oldStatus.discharging_time())
        dispatchEvent(Event::create(EventTypeNames::dischargingtimechange));
    if (m_batteryStatus.level() != oldStatus.level())
=======
    Document* document = toDocument(executionContext());
    ASSERT(document);
    if (document->activeDOMObjectsAreSuspended() || document->activeDOMObjectsAreStopped())
        return;

    ASSERT(oldStatus);

    if (m_batteryStatus->charging() != oldStatus->charging())
        dispatchEvent(Event::create(EventTypeNames::chargingchange));
    if (m_batteryStatus->chargingTime() != oldStatus->chargingTime())
        dispatchEvent(Event::create(EventTypeNames::chargingtimechange));
    if (m_batteryStatus->dischargingTime() != oldStatus->dischargingTime())
        dispatchEvent(Event::create(EventTypeNames::dischargingtimechange));
    if (m_batteryStatus->level() != oldStatus->level())
>>>>>>> miniblink49
        dispatchEvent(Event::create(EventTypeNames::levelchange));
}

void BatteryManager::registerWithDispatcher()
{
    BatteryDispatcher::instance().addController(this);
}

void BatteryManager::unregisterWithDispatcher()
{
    BatteryDispatcher::instance().removeController(this);
}

bool BatteryManager::hasLastData()
{
    return BatteryDispatcher::instance().latestData();
}

void BatteryManager::suspend()
{
    m_hasEventListener = false;
    stopUpdating();
}

void BatteryManager::resume()
{
    m_hasEventListener = true;
    startUpdating();
}

<<<<<<< HEAD
void BatteryManager::contextDestroyed(ExecutionContext*)
{
    m_hasEventListener = false;
    m_batteryProperty = nullptr;
=======
void BatteryManager::stop()
{
    m_hasEventListener = false;
    m_batteryProperty.clear();
>>>>>>> miniblink49
    stopUpdating();
}

bool BatteryManager::hasPendingActivity() const
{
    // Prevent V8 from garbage collecting the wrapper object if there are
    // event listeners attached to it.
<<<<<<< HEAD
    return getExecutionContext() && hasEventListeners();
=======
    return hasEventListeners();
>>>>>>> miniblink49
}

DEFINE_TRACE(BatteryManager)
{
    visitor->trace(m_batteryProperty);
<<<<<<< HEAD
    PlatformEventController::trace(visitor);
    EventTargetWithInlineData::trace(visitor);
    SuspendableObject::trace(visitor);
=======
    visitor->trace(m_batteryStatus);
    PlatformEventController::trace(visitor);
    RefCountedGarbageCollectedEventTargetWithInlineData<BatteryManager>::trace(visitor);
    ActiveDOMObject::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
