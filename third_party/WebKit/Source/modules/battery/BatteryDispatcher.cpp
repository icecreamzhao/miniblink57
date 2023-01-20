// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/battery/BatteryDispatcher.h"

#include "platform/mojo/MojoHelper.h"
#include "public/platform/InterfaceProvider.h"
#include "public/platform/Platform.h"
#include "wtf/Assertions.h"
=======
#include "config.h"
#include "modules/battery/BatteryDispatcher.h"

#include "modules/battery/BatteryStatus.h"
#include "public/platform/Platform.h"
>>>>>>> miniblink49

namespace blink {

BatteryDispatcher& BatteryDispatcher::instance()
{
<<<<<<< HEAD
    DEFINE_STATIC_LOCAL(BatteryDispatcher, batteryDispatcher,
        (new BatteryDispatcher));
    return batteryDispatcher;
}

BatteryDispatcher::BatteryDispatcher()
    : m_hasLatestData(false)
{
}

void BatteryDispatcher::queryNextStatus()
{
    m_monitor->QueryNextStatus(convertToBaseCallback(
        WTF::bind(&BatteryDispatcher::onDidChange, wrapPersistent(this))));
}

void BatteryDispatcher::onDidChange(
    device::blink::BatteryStatusPtr batteryStatus)
{
    queryNextStatus();

    DCHECK(batteryStatus);

    updateBatteryStatus(
        BatteryStatus(batteryStatus->charging, batteryStatus->charging_time,
            batteryStatus->discharging_time, batteryStatus->level));
}

void BatteryDispatcher::updateBatteryStatus(
    const BatteryStatus& batteryStatus)
{
    m_batteryStatus = batteryStatus;
    m_hasLatestData = true;
    notifyControllers();
}

void BatteryDispatcher::startListening()
{
    DCHECK(!m_monitor.is_bound());
    Platform::current()->interfaceProvider()->getInterface(
        mojo::MakeRequest(&m_monitor));
    queryNextStatus();
=======
    DEFINE_STATIC_LOCAL(Persistent<BatteryDispatcher>, batteryDispatcher, (new BatteryDispatcher()));
    return *batteryDispatcher;
}

BatteryDispatcher::BatteryDispatcher()
{
}

BatteryDispatcher::~BatteryDispatcher()
{
}

DEFINE_TRACE(BatteryDispatcher)
{
    visitor->trace(m_batteryStatus);
    PlatformEventDispatcher::trace(visitor);
}

void BatteryDispatcher::updateBatteryStatus(const WebBatteryStatus& batteryStatus)
{
    m_batteryStatus = BatteryStatus::create(batteryStatus.charging, batteryStatus.chargingTime, batteryStatus.dischargingTime, batteryStatus.level);
    notifyControllers();
}

BatteryStatus* BatteryDispatcher::latestData()
{
    return m_batteryStatus.get();
}

void BatteryDispatcher::startListening()
{
    Platform::current()->startListening(WebPlatformEventBattery, this);
>>>>>>> miniblink49
}

void BatteryDispatcher::stopListening()
{
<<<<<<< HEAD
    m_monitor.reset();
    m_hasLatestData = false;
=======
    Platform::current()->stopListening(WebPlatformEventBattery);
    m_batteryStatus.clear();
>>>>>>> miniblink49
}

} // namespace blink
