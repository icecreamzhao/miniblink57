// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BatteryDispatcher_h
#define BatteryDispatcher_h

#include "core/frame/PlatformEventDispatcher.h"
<<<<<<< HEAD
#include "device/battery/battery_monitor.mojom-blink.h"
#include "modules/ModulesExport.h"
#include "modules/battery/BatteryManager.h"
#include "modules/battery/battery_status.h"

namespace blink {

class MODULES_EXPORT BatteryDispatcher final
    : public GarbageCollectedFinalized<BatteryDispatcher>,
      public PlatformEventDispatcher {
    USING_GARBAGE_COLLECTED_MIXIN(BatteryDispatcher);
    WTF_MAKE_NONCOPYABLE(BatteryDispatcher);

public:
    static BatteryDispatcher& instance();

    const BatteryStatus* latestData() const
    {
        return m_hasLatestData ? &m_batteryStatus : nullptr;
    }
=======
#include "modules/battery/BatteryManager.h"
#include "modules/battery/BatteryStatus.h"
#include "public/platform/WebBatteryStatusListener.h"

namespace blink {

class WebBatteryStatus;

class BatteryDispatcher final : public GarbageCollectedFinalized<BatteryDispatcher>, public PlatformEventDispatcher, public WebBatteryStatusListener {
    USING_GARBAGE_COLLECTED_MIXIN(BatteryDispatcher);
public:
    static BatteryDispatcher& instance();
    ~BatteryDispatcher() override;

    BatteryStatus* latestData();

    // Inherited from WebBatteryStatusListener.
    void updateBatteryStatus(const WebBatteryStatus&) override;

    DECLARE_VIRTUAL_TRACE();
>>>>>>> miniblink49

private:
    BatteryDispatcher();

<<<<<<< HEAD
    void queryNextStatus();
    void onDidChange(device::blink::BatteryStatusPtr);
    void updateBatteryStatus(const BatteryStatus&);

=======
>>>>>>> miniblink49
    // Inherited from PlatformEventDispatcher.
    void startListening() override;
    void stopListening() override;

<<<<<<< HEAD
    device::blink::BatteryMonitorPtr m_monitor;
    BatteryStatus m_batteryStatus;
    bool m_hasLatestData;
=======
    Member<BatteryStatus> m_batteryStatus;
>>>>>>> miniblink49
};

} // namespace blink

#endif // BatteryDispatcher_h
