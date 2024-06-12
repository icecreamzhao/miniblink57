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

#include "third_party/WebKit/public/web/window_features.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/BluetoothStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/KURLStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/SecurityOriginStructTraits.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
namespace blink {
namespace mojom {
    namespace blink { // static
        WindowFeaturesPtr WindowFeatures::New()
        {
            WindowFeaturesPtr rv;
            mojo::internal::StructHelper<WindowFeatures>::Initialize(&rv);
            return rv;
        }

        WindowFeatures::WindowFeatures()
            : x()
            , has_x(false)
            , y()
            , has_y(false)
            , width()
            , has_width(false)
            , height()
            , has_height(false)
            , menu_bar_visible(true)
            , status_bar_visible(true)
            , tool_bar_visible(true)
            , location_bar_visible(true)
            , scrollbars_visible(true)
            , resizable(true)
            , fullscreen(false)
            , dialog(false)
        {
        }

        WindowFeatures::~WindowFeatures()
        {
        }
    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

// static
bool StructTraits<::blink::mojom::blink::WindowFeatures::DataView, ::blink::mojom::blink::WindowFeaturesPtr>::Read(
    ::blink::mojom::blink::WindowFeatures::DataView input,
    ::blink::mojom::blink::WindowFeaturesPtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WindowFeaturesPtr result(::blink::mojom::blink::WindowFeatures::New());

    result->x = input.x();
    result->has_x = input.has_x();
    result->y = input.y();
    result->has_y = input.has_y();
    result->width = input.width();
    result->has_width = input.has_width();
    result->height = input.height();
    result->has_height = input.has_height();
    result->menu_bar_visible = input.menu_bar_visible();
    result->status_bar_visible = input.status_bar_visible();
    result->tool_bar_visible = input.tool_bar_visible();
    result->location_bar_visible = input.location_bar_visible();
    result->scrollbars_visible = input.scrollbars_visible();
    result->resizable = input.resizable();
    result->fullscreen = input.fullscreen();
    result->dialog = input.dialog();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif