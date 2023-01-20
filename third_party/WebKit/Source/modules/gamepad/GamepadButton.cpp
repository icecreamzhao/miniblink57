// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/gamepad/Gamepad.h"

namespace blink {

GamepadButton* GamepadButton::create()
{
    return new GamepadButton();
}

GamepadButton::GamepadButton()
    : m_value(0.)
    , m_pressed(false)
<<<<<<< HEAD
    , m_touched(false)
=======
>>>>>>> miniblink49
{
}

} // namespace blink
