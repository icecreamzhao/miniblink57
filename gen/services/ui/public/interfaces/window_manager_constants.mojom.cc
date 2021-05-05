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

#include "services/ui/public/interfaces/window_manager_constants.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "cc/ipc/begin_frame_args_struct_traits.h"
#include "cc/ipc/compositor_frame_metadata_struct_traits.h"
#include "cc/ipc/compositor_frame_struct_traits.h"
#include "cc/ipc/filter_operation_struct_traits.h"
#include "cc/ipc/filter_operations_struct_traits.h"
#include "cc/ipc/frame_sink_id_struct_traits.h"
#include "cc/ipc/local_frame_id_struct_traits.h"
#include "cc/ipc/quads_struct_traits.h"
#include "cc/ipc/render_pass_struct_traits.h"
#include "cc/ipc/returned_resource_struct_traits.h"
#include "cc/ipc/selection_struct_traits.h"
#include "cc/ipc/shared_quad_state_struct_traits.h"
#include "cc/ipc/surface_id_struct_traits.h"
#include "cc/ipc/surface_info_struct_traits.h"
#include "cc/ipc/surface_reference_struct_traits.h"
#include "cc/ipc/surface_sequence_struct_traits.h"
#include "cc/ipc/transferable_resource_struct_traits.h"
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "services/ui/public/interfaces/ime/ime_struct_traits.h"
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "ui/events/mojo/event_struct_traits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
#include "ui/gfx/range/mojo/range_struct_traits.h"
namespace ui {
namespace mojom { // static
    FrameDecorationValuesPtr FrameDecorationValues::New()
    {
        FrameDecorationValuesPtr rv;
        mojo::internal::StructHelper<FrameDecorationValues>::Initialize(&rv);
        return rv;
    }

    FrameDecorationValues::FrameDecorationValues()
        : normal_client_area_insets()
        , maximized_client_area_insets()
        , max_title_bar_button_width()
    {
    }

    FrameDecorationValues::~FrameDecorationValues()
    {
    } // static
    WsDisplayPtr WsDisplay::New()
    {
        WsDisplayPtr rv;
        mojo::internal::StructHelper<WsDisplay>::Initialize(&rv);
        return rv;
    }

    WsDisplay::WsDisplay()
        : display()
        , frame_decoration_values()
    {
    }

    WsDisplay::~WsDisplay()
    {
    }
} // namespace mojom
} // namespace ui

namespace mojo {

// static
bool StructTraits<::ui::mojom::FrameDecorationValues::DataView, ::ui::mojom::FrameDecorationValuesPtr>::Read(
    ::ui::mojom::FrameDecorationValues::DataView input,
    ::ui::mojom::FrameDecorationValuesPtr* output)
{
    bool success = true;
    ::ui::mojom::FrameDecorationValuesPtr result(::ui::mojom::FrameDecorationValues::New());

    if (!input.ReadNormalClientAreaInsets(&result->normal_client_area_insets))
        success = false;
    if (!input.ReadMaximizedClientAreaInsets(&result->maximized_client_area_insets))
        success = false;
    result->max_title_bar_button_width = input.max_title_bar_button_width();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::WsDisplay::DataView, ::ui::mojom::WsDisplayPtr>::Read(
    ::ui::mojom::WsDisplay::DataView input,
    ::ui::mojom::WsDisplayPtr* output)
{
    bool success = true;
    ::ui::mojom::WsDisplayPtr result(::ui::mojom::WsDisplay::New());

    if (!input.ReadDisplay(&result->display))
        success = false;
    if (!input.ReadFrameDecorationValues(&result->frame_decoration_values))
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