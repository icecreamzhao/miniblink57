// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/device_orientation/DeviceMotionController.h"

#include "core/dom/Document.h"
#include "core/frame/Deprecation.h"
#include "core/frame/HostsUsingFeatures.h"
#include "core/frame/Settings.h"
=======
#include "config.h"
#include "modules/device_orientation/DeviceMotionController.h"

#include "core/dom/Document.h"
#include "core/frame/Settings.h"
#include "core/frame/UseCounter.h"
>>>>>>> miniblink49
#include "modules/EventModules.h"
#include "modules/device_orientation/DeviceMotionData.h"
#include "modules/device_orientation/DeviceMotionDispatcher.h"
#include "modules/device_orientation/DeviceMotionEvent.h"
#include "platform/weborigin/SecurityOrigin.h"
#include "public/platform/Platform.h"

namespace blink {

DeviceMotionController::DeviceMotionController(Document& document)
    : DeviceSingleWindowEventController(document)
<<<<<<< HEAD
    , Supplement<Document>(document)
{
}

DeviceMotionController::~DeviceMotionController() { }
=======
{
}

DeviceMotionController::~DeviceMotionController()
{
#if !ENABLE(OILPAN)
    stopUpdating();
#endif
}
>>>>>>> miniblink49

const char* DeviceMotionController::supplementName()
{
    return "DeviceMotionController";
}

DeviceMotionController& DeviceMotionController::from(Document& document)
{
<<<<<<< HEAD
    DeviceMotionController* controller = static_cast<DeviceMotionController*>(
        Supplement<Document>::from(document, supplementName()));
    if (!controller) {
        controller = new DeviceMotionController(document);
        Supplement<Document>::provideTo(document, supplementName(), controller);
=======
    DeviceMotionController* controller = static_cast<DeviceMotionController*>(WillBeHeapSupplement<Document>::from(document, supplementName()));
    if (!controller) {
        controller = new DeviceMotionController(document);
        WillBeHeapSupplement<Document>::provideTo(document, supplementName(), adoptPtrWillBeNoop(controller));
>>>>>>> miniblink49
    }
    return *controller;
}

<<<<<<< HEAD
void DeviceMotionController::didAddEventListener(
    LocalDOMWindow* window,
    const AtomicString& eventType)
=======
void DeviceMotionController::didAddEventListener(LocalDOMWindow* window, const AtomicString& eventType)
>>>>>>> miniblink49
{
    if (eventType != eventTypeName())
        return;

    if (document().frame()) {
<<<<<<< HEAD
        if (document().isSecureContext()) {
            UseCounter::count(document().frame(),
                UseCounter::DeviceMotionSecureOrigin);
        } else {
            Deprecation::countDeprecation(document().frame(),
                UseCounter::DeviceMotionInsecureOrigin);
            HostsUsingFeatures::countAnyWorld(
                document(), HostsUsingFeatures::Feature::DeviceMotionInsecureHost);
            if (document()
                    .frame()
                    ->settings()
                    ->getStrictPowerfulFeatureRestrictions())
=======
        String errorMessage;
        if (document().isPrivilegedContext(errorMessage)) {
            UseCounter::count(document().frame(), UseCounter::DeviceMotionSecureOrigin);
        } else {
            UseCounter::count(document().frame(), UseCounter::DeviceMotionInsecureOrigin);
            if (document().frame()->settings()->strictPowerfulFeatureRestrictions())
>>>>>>> miniblink49
                return;
        }
    }

    if (!m_hasEventListener)
<<<<<<< HEAD
        Platform::current()->recordRapporURL("DeviceSensors.DeviceMotion",
            WebURL(document().url()));
=======
        Platform::current()->recordRapporURL("DeviceSensors.DeviceMotion", WebURL(document().url()));
>>>>>>> miniblink49

    DeviceSingleWindowEventController::didAddEventListener(window, eventType);
}

bool DeviceMotionController::hasLastData()
{
    return DeviceMotionDispatcher::instance().latestDeviceMotionData();
}

void DeviceMotionController::registerWithDispatcher()
{
    DeviceMotionDispatcher::instance().addController(this);
}

void DeviceMotionController::unregisterWithDispatcher()
{
    DeviceMotionDispatcher::instance().removeController(this);
}

<<<<<<< HEAD
Event* DeviceMotionController::lastEvent() const
{
    return DeviceMotionEvent::create(
        EventTypeNames::devicemotion,
        DeviceMotionDispatcher::instance().latestDeviceMotionData());
=======
PassRefPtrWillBeRawPtr<Event> DeviceMotionController::lastEvent() const
{
    return DeviceMotionEvent::create(EventTypeNames::devicemotion, DeviceMotionDispatcher::instance().latestDeviceMotionData());
>>>>>>> miniblink49
}

bool DeviceMotionController::isNullEvent(Event* event) const
{
    DeviceMotionEvent* motionEvent = toDeviceMotionEvent(event);
<<<<<<< HEAD
    return !motionEvent->getDeviceMotionData()->canProvideEventData();
=======
    return !motionEvent->deviceMotionData()->canProvideEventData();
>>>>>>> miniblink49
}

const AtomicString& DeviceMotionController::eventTypeName() const
{
    return EventTypeNames::devicemotion;
}

DEFINE_TRACE(DeviceMotionController)
{
    DeviceSingleWindowEventController::trace(visitor);
<<<<<<< HEAD
    Supplement<Document>::trace(visitor);
=======
    WillBeHeapSupplement<Document>::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
