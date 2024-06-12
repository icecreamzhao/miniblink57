// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "services/ui/public/interfaces/display/display.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
namespace display {
namespace mojom { // static
    DisplayPtr Display::New()
    {
        DisplayPtr rv;
        mojo::internal::StructHelper<Display>::Initialize(&rv);
        return rv;
    }

    Display::Display()
        : id()
        , bounds()
        , work_area()
        , device_scale_factor()
        , rotation()
        , touch_support()
        , maximum_cursor_size()
    {
    }

    Display::~Display()
    {
    }
} // namespace mojom
} // namespace display

namespace mojo {

// static
bool StructTraits<::display::mojom::Display::DataView, ::display::mojom::DisplayPtr>::Read(
    ::display::mojom::Display::DataView input,
    ::display::mojom::DisplayPtr* output)
{
    bool success = true;
    ::display::mojom::DisplayPtr result(::display::mojom::Display::New());

    result->id = input.id();
    if (!input.ReadBounds(&result->bounds))
        success = false;
    if (!input.ReadWorkArea(&result->work_area))
        success = false;
    result->device_scale_factor = input.device_scale_factor();
    if (!input.ReadRotation(&result->rotation))
        success = false;
    if (!input.ReadTouchSupport(&result->touch_support))
        success = false;
    if (!input.ReadMaximumCursorSize(&result->maximum_cursor_size))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif