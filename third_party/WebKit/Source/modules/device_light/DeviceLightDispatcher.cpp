// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/device_light/DeviceLightDispatcher.h"

#include "modules/device_light/DeviceLightController.h"
#include "public/platform/Platform.h"

namespace blink {

DeviceLightDispatcher& DeviceLightDispatcher::instance()
{
<<<<<<< HEAD
    DEFINE_STATIC_LOCAL(DeviceLightDispatcher, deviceLightDispatcher,
        (new DeviceLightDispatcher));
    return deviceLightDispatcher;
=======
    DEFINE_STATIC_LOCAL(Persistent<DeviceLightDispatcher>, deviceLightDispatcher, (new DeviceLightDispatcher()));
    return *deviceLightDispatcher;
>>>>>>> miniblink49
}

DeviceLightDispatcher::DeviceLightDispatcher()
    : m_lastDeviceLightData(-1)
{
}

<<<<<<< HEAD
DeviceLightDispatcher::~DeviceLightDispatcher() { }
=======
DeviceLightDispatcher::~DeviceLightDispatcher()
{
}
>>>>>>> miniblink49

DEFINE_TRACE(DeviceLightDispatcher)
{
    PlatformEventDispatcher::trace(visitor);
}

void DeviceLightDispatcher::startListening()
{
<<<<<<< HEAD
    Platform::current()->startListening(WebPlatformEventTypeDeviceLight, this);
=======
    Platform::current()->startListening(WebPlatformEventDeviceLight, this);
>>>>>>> miniblink49
}

void DeviceLightDispatcher::stopListening()
{
<<<<<<< HEAD
    Platform::current()->stopListening(WebPlatformEventTypeDeviceLight);
=======
    Platform::current()->stopListening(WebPlatformEventDeviceLight);
>>>>>>> miniblink49
    m_lastDeviceLightData = -1;
}

void DeviceLightDispatcher::didChangeDeviceLight(double value)
{
    m_lastDeviceLightData = value;
    notifyControllers();
}

double DeviceLightDispatcher::latestDeviceLightData() const
{
    return m_lastDeviceLightData;
}

} // namespace blink
