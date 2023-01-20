// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/screen_orientation/ScreenScreenOrientation.h"

#include "bindings/core/v8/ScriptState.h"
#include "core/frame/Screen.h"
#include "modules/screen_orientation/ScreenOrientation.h"

namespace blink {

// static
ScreenScreenOrientation& ScreenScreenOrientation::from(Screen& screen)
{
<<<<<<< HEAD
    ScreenScreenOrientation* supplement = static_cast<ScreenScreenOrientation*>(
        Supplement<Screen>::from(screen, supplementName()));
=======
    ScreenScreenOrientation* supplement = static_cast<ScreenScreenOrientation*>(HeapSupplement<Screen>::from(screen, supplementName()));
>>>>>>> miniblink49
    if (!supplement) {
        supplement = new ScreenScreenOrientation();
        provideTo(screen, supplementName(), supplement);
    }
    return *supplement;
}

// static
<<<<<<< HEAD
ScreenOrientation* ScreenScreenOrientation::orientation(ScriptState* state,
    Screen& screen)
=======
ScreenOrientation* ScreenScreenOrientation::orientation(ScriptState* state, Screen& screen)
>>>>>>> miniblink49
{
    ScreenScreenOrientation& self = ScreenScreenOrientation::from(screen);
    if (!screen.frame())
        return nullptr;

    if (!self.m_orientation)
        self.m_orientation = ScreenOrientation::create(screen.frame());

    return self.m_orientation;
}

const char* ScreenScreenOrientation::supplementName()
{
    return "ScreenScreenOrientation";
}

DEFINE_TRACE(ScreenScreenOrientation)
{
    visitor->trace(m_orientation);
<<<<<<< HEAD
    Supplement<Screen>::trace(visitor);
=======
    HeapSupplement<Screen>::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
