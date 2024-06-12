// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "modules/EventModulesFactory.h"

#include "EventModulesHeaders.h"
#include "core/frame/Deprecation.h"
#include "platform/RuntimeEnabledFeatures.h"

namespace blink {

Event* EventModulesFactory::create(ExecutionContext* executionContext, const String& type)
{
    //   if (type == "DeviceMotionEvent") {
    //     UseCounter::count(executionContext, UseCounter::DocumentCreateEventDeviceMotionEvent);
    //     return DeviceMotionEvent::create();
    //   }
    //   if (type == "DeviceOrientationEvent") {
    //     UseCounter::count(executionContext, UseCounter::DocumentCreateEventDeviceOrientationEvent);
    //     return DeviceOrientationEvent::create();
    //   }
    //   if (type == "IDBVersionChangeEvent") {
    //     UseCounter::count(executionContext, UseCounter::DocumentCreateEventIDBVersionChangeEvent);
    //     return IDBVersionChangeEvent::create();
    //   }
    //   if (type == "StorageEvent") {
    //     UseCounter::count(executionContext, UseCounter::DocumentCreateEventStorageEvent);
    //     return StorageEvent::create();
    //   }
    //   if (type == "WebGLContextEvent") {
    //     UseCounter::count(executionContext, UseCounter::DocumentCreateEventWebGLContextEvent);
    //     return WebGLContextEvent::create();
    //   }
    //   if (type == "CloseEvent") {
    //     UseCounter::count(executionContext, UseCounter::DocumentCreateEventCloseEvent);
    //     return CloseEvent::create();
    //   }
    return nullptr;
}

} // namespace blink
