// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_EVENT_CONSTANTS_MOJOM_H_
#define UI_EVENTS_MOJO_EVENT_CONSTANTS_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
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
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/events/mojo/event_constants.mojom-shared.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace ui {
namespace mojom {
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

} // namespace mojom
} // namespace ui

namespace mojo {

} // namespace mojo

#endif // UI_EVENTS_MOJO_EVENT_CONSTANTS_MOJOM_H_