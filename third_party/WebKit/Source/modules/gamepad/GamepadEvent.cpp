// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/gamepad/GamepadEvent.h"

namespace blink {

<<<<<<< HEAD
GamepadEvent::GamepadEvent(const AtomicString& type,
    bool canBubble,
    bool cancelable,
    Gamepad* gamepad)
=======
GamepadEvent::GamepadEvent()
{
}

GamepadEvent::GamepadEvent(const AtomicString& type, bool canBubble, bool cancelable, Gamepad* gamepad)
>>>>>>> miniblink49
    : Event(type, canBubble, cancelable)
    , m_gamepad(gamepad)
{
}

<<<<<<< HEAD
GamepadEvent::GamepadEvent(const AtomicString& type,
    const GamepadEventInit& initializer)
=======
GamepadEvent::GamepadEvent(const AtomicString& type, const GamepadEventInit& initializer)
>>>>>>> miniblink49
    : Event(type, initializer)
{
    if (initializer.hasGamepad())
        m_gamepad = initializer.gamepad();
}

<<<<<<< HEAD
GamepadEvent::~GamepadEvent() { }
=======
GamepadEvent::~GamepadEvent()
{
}
>>>>>>> miniblink49

const AtomicString& GamepadEvent::interfaceName() const
{
    return EventNames::GamepadEvent;
}

DEFINE_TRACE(GamepadEvent)
{
    visitor->trace(m_gamepad);
    Event::trace(visitor);
}

} // namespace blink
