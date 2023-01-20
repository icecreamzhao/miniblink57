// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/battery/NavigatorBattery.h"

#include "core/frame/LocalFrame.h"
#include "modules/battery/BatteryManager.h"

namespace blink {

<<<<<<< HEAD
NavigatorBattery::NavigatorBattery() { }

ScriptPromise NavigatorBattery::getBattery(ScriptState* scriptState,
    Navigator& navigator)
=======
NavigatorBattery::NavigatorBattery()
{
}

ScriptPromise NavigatorBattery::getBattery(ScriptState* scriptState, Navigator& navigator)
>>>>>>> miniblink49
{
    return NavigatorBattery::from(navigator).getBattery(scriptState);
}

ScriptPromise NavigatorBattery::getBattery(ScriptState* scriptState)
{
    if (!m_batteryManager)
<<<<<<< HEAD
        m_batteryManager = BatteryManager::create(scriptState->getExecutionContext());
=======
        m_batteryManager = BatteryManager::create(scriptState->executionContext());
>>>>>>> miniblink49

    return m_batteryManager->startRequest(scriptState);
}

const char* NavigatorBattery::supplementName()
{
    return "NavigatorBattery";
}

NavigatorBattery& NavigatorBattery::from(Navigator& navigator)
{
<<<<<<< HEAD
    NavigatorBattery* supplement = static_cast<NavigatorBattery*>(
        Supplement<Navigator>::from(navigator, supplementName()));
=======
    NavigatorBattery* supplement = static_cast<NavigatorBattery*>(HeapSupplement<Navigator>::from(navigator, supplementName()));
>>>>>>> miniblink49
    if (!supplement) {
        supplement = new NavigatorBattery();
        provideTo(navigator, supplementName(), supplement);
    }
    return *supplement;
}

DEFINE_TRACE(NavigatorBattery)
{
    visitor->trace(m_batteryManager);
<<<<<<< HEAD
    Supplement<Navigator>::trace(visitor);
=======
    HeapSupplement<Navigator>::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
