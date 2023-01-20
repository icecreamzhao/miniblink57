// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/device_light/DeviceLightController.h"

#include "core/dom/Document.h"
#include "modules/EventModules.h"
#include "modules/device_light/DeviceLightDispatcher.h"
#include "modules/device_light/DeviceLightEvent.h"
#include "platform/RuntimeEnabledFeatures.h"

namespace blink {

DeviceLightController::DeviceLightController(Document& document)
    : DeviceSingleWindowEventController(document)
<<<<<<< HEAD
    , Supplement<Document>(document)
{
}

DeviceLightController::~DeviceLightController() { }
=======
{
}

DeviceLightController::~DeviceLightController()
{
#if !ENABLE(OILPAN)
    stopUpdating();
#endif
}
>>>>>>> miniblink49

const char* DeviceLightController::supplementName()
{
    return "DeviceLightController";
}

DeviceLightController& DeviceLightController::from(Document& document)
{
<<<<<<< HEAD
    DeviceLightController* controller = static_cast<DeviceLightController*>(
        Supplement<Document>::from(document, supplementName()));
    if (!controller) {
        controller = new DeviceLightController(document);
        Supplement<Document>::provideTo(document, supplementName(), controller);
=======
    DeviceLightController* controller = static_cast<DeviceLightController*>(WillBeHeapSupplement<Document>::from(document, supplementName()));
    if (!controller) {
        controller = new DeviceLightController(document);
        WillBeHeapSupplement<Document>::provideTo(document, supplementName(), adoptPtrWillBeNoop(controller));
>>>>>>> miniblink49
    }
    return *controller;
}

bool DeviceLightController::hasLastData()
{
    return DeviceLightDispatcher::instance().latestDeviceLightData() >= 0;
}

void DeviceLightController::registerWithDispatcher()
{
    DeviceLightDispatcher::instance().addController(this);
}

void DeviceLightController::unregisterWithDispatcher()
{
    DeviceLightDispatcher::instance().removeController(this);
}

<<<<<<< HEAD
Event* DeviceLightController::lastEvent() const
{
    return DeviceLightEvent::create(
        EventTypeNames::devicelight,
=======
PassRefPtrWillBeRawPtr<Event> DeviceLightController::lastEvent() const
{
    return DeviceLightEvent::create(EventTypeNames::devicelight,
>>>>>>> miniblink49
        DeviceLightDispatcher::instance().latestDeviceLightData());
}

bool DeviceLightController::isNullEvent(Event* event) const
{
    DeviceLightEvent* lightEvent = toDeviceLightEvent(event);
    return lightEvent->value() == std::numeric_limits<double>::infinity();
}

const AtomicString& DeviceLightController::eventTypeName() const
{
    return EventTypeNames::devicelight;
}

DEFINE_TRACE(DeviceLightController)
{
    DeviceSingleWindowEventController::trace(visitor);
<<<<<<< HEAD
    Supplement<Document>::trace(visitor);
}

=======
    WillBeHeapSupplement<Document>::trace(visitor);
}


>>>>>>> miniblink49
} // namespace blink
