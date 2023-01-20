// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/device_orientation/DeviceOrientationController.h"

#include "core/dom/Document.h"
#include "core/frame/Deprecation.h"
#include "core/frame/HostsUsingFeatures.h"
#include "core/frame/Settings.h"
=======
#include "config.h"
#include "modules/device_orientation/DeviceOrientationController.h"

#include "core/dom/Document.h"
#include "core/frame/Settings.h"
#include "core/frame/UseCounter.h"
>>>>>>> miniblink49
#include "modules/EventModules.h"
#include "modules/device_orientation/DeviceOrientationData.h"
#include "modules/device_orientation/DeviceOrientationDispatcher.h"
#include "modules/device_orientation/DeviceOrientationEvent.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/Platform.h"
<<<<<<< HEAD
#include "wtf/Assertions.h"
=======
>>>>>>> miniblink49

namespace blink {

DeviceOrientationController::DeviceOrientationController(Document& document)
    : DeviceSingleWindowEventController(document)
<<<<<<< HEAD
    , Supplement<Document>(document)
{
}

DeviceOrientationController::~DeviceOrientationController() { }
=======
{
}

DeviceOrientationController::~DeviceOrientationController()
{
#if !ENABLE(OILPAN)
    stopUpdating();
#endif
}
>>>>>>> miniblink49

void DeviceOrientationController::didUpdateData()
{
    if (m_overrideOrientationData)
        return;
    dispatchDeviceEvent(lastEvent());
}

const char* DeviceOrientationController::supplementName()
{
    return "DeviceOrientationController";
}

<<<<<<< HEAD
DeviceOrientationController& DeviceOrientationController::from(
    Document& document)
{
    DeviceOrientationController* controller = static_cast<DeviceOrientationController*>(
        Supplement<Document>::from(document, supplementName()));
    if (!controller) {
        controller = new DeviceOrientationController(document);
        Supplement<Document>::provideTo(document, supplementName(), controller);
=======
DeviceOrientationController& DeviceOrientationController::from(Document& document)
{
    DeviceOrientationController* controller = static_cast<DeviceOrientationController*>(WillBeHeapSupplement<Document>::from(document, supplementName()));
    if (!controller) {
        controller = new DeviceOrientationController(document);
        WillBeHeapSupplement<Document>::provideTo(document, supplementName(), adoptPtrWillBeNoop(controller));
>>>>>>> miniblink49
    }
    return *controller;
}

<<<<<<< HEAD
void DeviceOrientationController::didAddEventListener(
    LocalDOMWindow* window,
    const AtomicString& eventType)
=======
void DeviceOrientationController::didAddEventListener(LocalDOMWindow* window, const AtomicString& eventType)
>>>>>>> miniblink49
{
    if (eventType != eventTypeName())
        return;

    if (document().frame()) {
<<<<<<< HEAD
        if (document().isSecureContext()) {
            UseCounter::count(document().frame(),
                UseCounter::DeviceOrientationSecureOrigin);
        } else {
            Deprecation::countDeprecation(
                document().frame(), UseCounter::DeviceOrientationInsecureOrigin);
            HostsUsingFeatures::countAnyWorld(
                document(),
                HostsUsingFeatures::Feature::DeviceOrientationInsecureHost);
            if (document()
                    .frame()
                    ->settings()
                    ->getStrictPowerfulFeatureRestrictions())
=======
        String errorMessage;
        if (document().isPrivilegedContext(errorMessage)) {
            UseCounter::count(document().frame(), UseCounter::DeviceOrientationSecureOrigin);
        } else {
            UseCounter::count(document().frame(), UseCounter::DeviceOrientationInsecureOrigin);
            if (document().frame()->settings()->strictPowerfulFeatureRestrictions())
>>>>>>> miniblink49
                return;
        }
    }

    if (!m_hasEventListener)
<<<<<<< HEAD
        Platform::current()->recordRapporURL("DeviceSensors.DeviceOrientation",
            WebURL(document().url()));
=======
        Platform::current()->recordRapporURL("DeviceSensors.DeviceOrientation", WebURL(document().url()));
>>>>>>> miniblink49

    DeviceSingleWindowEventController::didAddEventListener(window, eventType);
}

DeviceOrientationData* DeviceOrientationController::lastData() const
{
<<<<<<< HEAD
    return m_overrideOrientationData
        ? m_overrideOrientationData.get()
        : dispatcherInstance().latestDeviceOrientationData();
=======
    return m_overrideOrientationData ? m_overrideOrientationData.get() : DeviceOrientationDispatcher::instance().latestDeviceOrientationData();
>>>>>>> miniblink49
}

bool DeviceOrientationController::hasLastData()
{
    return lastData();
}

void DeviceOrientationController::registerWithDispatcher()
{
<<<<<<< HEAD
    dispatcherInstance().addController(this);
=======
    DeviceOrientationDispatcher::instance().addController(this);
>>>>>>> miniblink49
}

void DeviceOrientationController::unregisterWithDispatcher()
{
<<<<<<< HEAD
    dispatcherInstance().removeController(this);
}

Event* DeviceOrientationController::lastEvent() const
=======
    DeviceOrientationDispatcher::instance().removeController(this);
}

PassRefPtrWillBeRawPtr<Event> DeviceOrientationController::lastEvent() const
>>>>>>> miniblink49
{
    return DeviceOrientationEvent::create(eventTypeName(), lastData());
}

bool DeviceOrientationController::isNullEvent(Event* event) const
{
    DeviceOrientationEvent* orientationEvent = toDeviceOrientationEvent(event);
    return !orientationEvent->orientation()->canProvideEventData();
}

const AtomicString& DeviceOrientationController::eventTypeName() const
{
    return EventTypeNames::deviceorientation;
}

<<<<<<< HEAD
void DeviceOrientationController::setOverride(
    DeviceOrientationData* deviceOrientationData)
{
    DCHECK(deviceOrientationData);
=======
void DeviceOrientationController::setOverride(DeviceOrientationData* deviceOrientationData)
{
    ASSERT(deviceOrientationData);
>>>>>>> miniblink49
    m_overrideOrientationData = deviceOrientationData;
    dispatchDeviceEvent(lastEvent());
}

void DeviceOrientationController::clearOverride()
{
    if (!m_overrideOrientationData)
        return;
    m_overrideOrientationData.clear();
    if (lastData())
        didUpdateData();
}

<<<<<<< HEAD
DeviceOrientationDispatcher& DeviceOrientationController::dispatcherInstance()
    const
{
    return DeviceOrientationDispatcher::instance(false);
}

=======
>>>>>>> miniblink49
DEFINE_TRACE(DeviceOrientationController)
{
    visitor->trace(m_overrideOrientationData);
    DeviceSingleWindowEventController::trace(visitor);
<<<<<<< HEAD
    Supplement<Document>::trace(visitor);
=======
    WillBeHeapSupplement<Document>::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
