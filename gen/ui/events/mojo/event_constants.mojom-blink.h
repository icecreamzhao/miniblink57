// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_EVENT_CONSTANTS_MOJOM_BLINK_H_
#define UI_EVENTS_MOJO_EVENT_CONSTANTS_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "ui/events/mojo/event_constants.mojom-shared.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace ui {
namespace mojom {
    namespace blink {
        using AcceleratorPhase = AcceleratorPhase; // Alias for definition in the parent namespace.
        using EventType = EventType; // Alias for definition in the parent namespace.
        using PointerKind = PointerKind; // Alias for definition in the parent namespace.
        using WheelMode = WheelMode; // Alias for definition in the parent namespace.
        constexpr int32_t kEventFlagNone = 0x00000;
        constexpr int32_t kEventFlagIsSynthesized = 0x00001;
        constexpr int32_t kEventFlagShiftDown = 0x00002;
        constexpr int32_t kEventFlagControlDown = 0x00004;
        constexpr int32_t kEventFlagAltDown = 0x00008;
        constexpr int32_t kEventFlagCommandDown = 0x00010;
        constexpr int32_t kEventFlagAltgrDown = 0x00020;
        constexpr int32_t kEventFlagMod3Down = 0x00040;
        constexpr int32_t kEventFlagNumLockOn = 0x00080;
        constexpr int32_t kEventFlagCapsLockOn = 0x00100;
        constexpr int32_t kEventFlagScrollLockOn = 0x00200;
        constexpr int32_t kEventFlagLeftMouseButton = 0x00400;
        constexpr int32_t kEventFlagMiddleMouseButton = 0x00800;
        constexpr int32_t kEventFlagRightMouseButton = 0x01000;
        constexpr int32_t kEventFlagBackMouseButton = 0x02000;
        constexpr int32_t kEventFlagForwardMouseButton = 0x04000;
        constexpr int32_t kMouseEventFlagIsDoubleClick = 0x08000;
        constexpr int32_t kMouseEventFlagIsTripleClick = 0x10000;
        constexpr int32_t kMouseEventFlagIsNonClient = 0x20000;

    } // namespace blink
} // namespace mojom
} // namespace ui

namespace mojo {

} // namespace mojo

#endif // UI_EVENTS_MOJO_EVENT_CONSTANTS_MOJOM_BLINK_H_