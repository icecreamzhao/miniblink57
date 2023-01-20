// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/device_light/DeviceLightEvent.h"

namespace blink {

<<<<<<< HEAD
DeviceLightEvent::~DeviceLightEvent() { }

DeviceLightEvent::DeviceLightEvent(const AtomicString& eventType, double value)
    // The DeviceLightEvent bubbles but is not cancelable.
    : Event(eventType, true, false)
=======
DeviceLightEvent::~DeviceLightEvent()
{
}

DeviceLightEvent::DeviceLightEvent()
    : m_value(std::numeric_limits<double>::infinity())
{
}

DeviceLightEvent::DeviceLightEvent(const AtomicString& eventType, double value)
    : Event(eventType, true, false) // The DeviceLightEvent bubbles but is not cancelable.
>>>>>>> miniblink49
    , m_value(value)
{
}

<<<<<<< HEAD
DeviceLightEvent::DeviceLightEvent(const AtomicString& eventType,
    const DeviceLightEventInit& initializer)
    : Event(eventType, initializer)
    , m_value(initializer.hasValue()
              ? initializer.value()
              : std::numeric_limits<double>::infinity())
=======
DeviceLightEvent::DeviceLightEvent(const AtomicString& eventType, const DeviceLightEventInit& initializer)
    : Event(eventType, initializer)
    , m_value(initializer.hasValue() ? initializer.value() : std::numeric_limits<double>::infinity())
>>>>>>> miniblink49
{
    setCanBubble(true);
}

const AtomicString& DeviceLightEvent::interfaceName() const
{
    return EventNames::DeviceLightEvent;
}

} // namespace blink
<<<<<<< HEAD
=======




>>>>>>> miniblink49
