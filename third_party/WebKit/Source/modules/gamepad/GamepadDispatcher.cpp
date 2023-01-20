// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/gamepad/GamepadDispatcher.h"

#include "modules/gamepad/NavigatorGamepad.h"
#include "public/platform/Platform.h"
<<<<<<< HEAD
=======
#include "wtf/TemporaryChange.h"
>>>>>>> miniblink49

namespace blink {

GamepadDispatcher& GamepadDispatcher::instance()
{
<<<<<<< HEAD
    DEFINE_STATIC_LOCAL(GamepadDispatcher, gamepadDispatcher,
        (new GamepadDispatcher));
    return gamepadDispatcher;
=======
    DEFINE_STATIC_LOCAL(Persistent<GamepadDispatcher>, gamepadDispatcher, (new GamepadDispatcher()));
    return *gamepadDispatcher;
>>>>>>> miniblink49
}

void GamepadDispatcher::sampleGamepads(WebGamepads& gamepads)
{
    Platform::current()->sampleGamepads(gamepads);
}

<<<<<<< HEAD
GamepadDispatcher::GamepadDispatcher() { }

GamepadDispatcher::~GamepadDispatcher() { }
=======
GamepadDispatcher::GamepadDispatcher()
{
}

GamepadDispatcher::~GamepadDispatcher()
{
}
>>>>>>> miniblink49

DEFINE_TRACE(GamepadDispatcher)
{
    PlatformEventDispatcher::trace(visitor);
}

<<<<<<< HEAD
void GamepadDispatcher::didConnectGamepad(unsigned index,
    const WebGamepad& gamepad)
=======
void GamepadDispatcher::didConnectGamepad(unsigned index, const WebGamepad& gamepad)
>>>>>>> miniblink49
{
    dispatchDidConnectOrDisconnectGamepad(index, gamepad, true);
}

<<<<<<< HEAD
void GamepadDispatcher::didDisconnectGamepad(unsigned index,
    const WebGamepad& gamepad)
=======
void GamepadDispatcher::didDisconnectGamepad(unsigned index, const WebGamepad& gamepad)
>>>>>>> miniblink49
{
    dispatchDidConnectOrDisconnectGamepad(index, gamepad, false);
}

<<<<<<< HEAD
void GamepadDispatcher::dispatchDidConnectOrDisconnectGamepad(
    unsigned index,
    const WebGamepad& gamepad,
    bool connected)
=======
void GamepadDispatcher::dispatchDidConnectOrDisconnectGamepad(unsigned index, const WebGamepad& gamepad, bool connected)
>>>>>>> miniblink49
{
    ASSERT(index < WebGamepads::itemsLengthCap);
    ASSERT(connected == gamepad.connected);

    m_latestChange.pad = gamepad;
    m_latestChange.index = index;
    notifyControllers();
}

void GamepadDispatcher::startListening()
{
<<<<<<< HEAD
    Platform::current()->startListening(WebPlatformEventTypeGamepad, this);
=======
    Platform::current()->startListening(WebPlatformEventGamepad, this);
>>>>>>> miniblink49
}

void GamepadDispatcher::stopListening()
{
<<<<<<< HEAD
    Platform::current()->stopListening(WebPlatformEventTypeGamepad);
=======
    Platform::current()->stopListening(WebPlatformEventGamepad);
>>>>>>> miniblink49
}

} // namespace blink
