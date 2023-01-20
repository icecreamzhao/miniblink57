// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DeviceLightEvent_h
#define DeviceLightEvent_h

#include "modules/EventModules.h"
#include "modules/device_light/DeviceLightEventInit.h"
#include "platform/heap/Handle.h"

namespace blink {

class DeviceLightEvent final : public Event {
    DEFINE_WRAPPERTYPEINFO();
<<<<<<< HEAD

public:
    ~DeviceLightEvent() override;

    static DeviceLightEvent* create(const AtomicString& eventType, double value)
    {
        return new DeviceLightEvent(eventType, value);
    }
    static DeviceLightEvent* create(const AtomicString& eventType,
        const DeviceLightEventInit& initializer)
    {
        return new DeviceLightEvent(eventType, initializer);
=======
public:
    ~DeviceLightEvent() override;

    static PassRefPtrWillBeRawPtr<DeviceLightEvent> create()
    {
        return adoptRefWillBeNoop(new DeviceLightEvent);
    }
    static PassRefPtrWillBeRawPtr<DeviceLightEvent> create(const AtomicString& eventType, double value)
    {
        return adoptRefWillBeNoop(new DeviceLightEvent(eventType, value));
    }
    static PassRefPtrWillBeRawPtr<DeviceLightEvent> create(const AtomicString& eventType, const DeviceLightEventInit& initializer)
    {
        return adoptRefWillBeNoop(new DeviceLightEvent(eventType, initializer));
>>>>>>> miniblink49
    }

    double value() const { return m_value; }

    const AtomicString& interfaceName() const override;

private:
<<<<<<< HEAD
    DeviceLightEvent(const AtomicString& eventType, double value);
    DeviceLightEvent(const AtomicString& eventType,
        const DeviceLightEventInit& initializer);
=======
    DeviceLightEvent();
    DeviceLightEvent(const AtomicString& eventType, double value);
    DeviceLightEvent(const AtomicString& eventType, const DeviceLightEventInit& initializer);
>>>>>>> miniblink49

    double m_value;
};

<<<<<<< HEAD
DEFINE_TYPE_CASTS(DeviceLightEvent,
    Event,
    event,
    event->interfaceName() == EventNames::DeviceLightEvent,
    event.interfaceName() == EventNames::DeviceLightEvent);
=======
DEFINE_TYPE_CASTS(DeviceLightEvent, Event, event, event->interfaceName() == EventNames::DeviceLightEvent, event.interfaceName() == EventNames::DeviceLightEvent);
>>>>>>> miniblink49

} // namespace blink

#endif // DeviceLightEvent_h
