// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_OZONE_EVDEV_TOUCH_DEBUG_BUFFER_H_
#define UI_EVENTS_OZONE_EVDEV_TOUCH_DEBUG_BUFFER_H_

#include <linux/input.h>
#include <stddef.h>

#include <string>
#include <vector>

#include "base/memory/scoped_ptr.h"
#include "ui/events/ozone/evdev/events_ozone_evdev_export.h"

namespace ui {

class EventDeviceInfo;

class EVENTS_OZONE_EVDEV_EXPORT TouchEventLogEvdev {
public:
    TouchEventLogEvdev();
    ~TouchEventLogEvdev();

    void Initialize(const EventDeviceInfo& devinfo);
    void ProcessEvent(size_t cur_slot, const input_event* ev);

    void DumpLog(const char* filename);

private:
    struct TouchEvent {
        struct input_event ev;
        int slot;
    };
    const int kDebugBufferSize = 65536;
    scoped_ptr<TouchEvent[]> logged_events_;
    int debug_buffer_tail_ = 0;

    std::string device_name_;

    struct AbsAxisData {
        AbsAxisData(int code, const input_absinfo& info);
        AbsAxisData(const AbsAxisData& other);
        ~AbsAxisData();

        int code;
        input_absinfo info;
    };

    std::vector<AbsAxisData> axes_;
};

} // namespace ui

#endif // UI_EVENTS_OZONE_EVDEV_TOUCH_EVDEV_BUFFER_H_
