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

#include "cc/ipc/compositor_frame_metadata.mojom.h"

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
namespace cc {
namespace mojom { // static
    CompositorFrameMetadataPtr CompositorFrameMetadata::New()
    {
        CompositorFrameMetadataPtr rv;
        mojo::internal::StructHelper<CompositorFrameMetadata>::Initialize(&rv);
        return rv;
    }

    CompositorFrameMetadata::CompositorFrameMetadata()
        : device_scale_factor()
        , root_scroll_offset()
        , page_scale_factor()
        , scrollable_viewport_size()
        , root_layer_size()
        , min_page_scale_factor()
        , max_page_scale_factor()
        , root_overflow_x_hidden()
        , root_overflow_y_hidden()
        , may_contain_video()
        , is_resourceless_software_draw_with_scroll_or_animation()
        , top_controls_height()
        , top_controls_shown_ratio()
        , bottom_controls_height()
        , bottom_controls_shown_ratio()
        , root_background_color()
        , selection()
        , latency_info()
        , referenced_surfaces()
    {
    }

    CompositorFrameMetadata::~CompositorFrameMetadata()
    {
    }
} // namespace mojom
} // namespace cc

namespace mojo {

// static
bool StructTraits<::cc::mojom::CompositorFrameMetadata::DataView, ::cc::mojom::CompositorFrameMetadataPtr>::Read(
    ::cc::mojom::CompositorFrameMetadata::DataView input,
    ::cc::mojom::CompositorFrameMetadataPtr* output)
{
    bool success = true;
    ::cc::mojom::CompositorFrameMetadataPtr result(::cc::mojom::CompositorFrameMetadata::New());

    result->device_scale_factor = input.device_scale_factor();
    if (!input.ReadRootScrollOffset(&result->root_scroll_offset))
        success = false;
    result->page_scale_factor = input.page_scale_factor();
    if (!input.ReadScrollableViewportSize(&result->scrollable_viewport_size))
        success = false;
    if (!input.ReadRootLayerSize(&result->root_layer_size))
        success = false;
    result->min_page_scale_factor = input.min_page_scale_factor();
    result->max_page_scale_factor = input.max_page_scale_factor();
    result->root_overflow_x_hidden = input.root_overflow_x_hidden();
    result->root_overflow_y_hidden = input.root_overflow_y_hidden();
    result->may_contain_video = input.may_contain_video();
    result->is_resourceless_software_draw_with_scroll_or_animation = input.is_resourceless_software_draw_with_scroll_or_animation();
    result->top_controls_height = input.top_controls_height();
    result->top_controls_shown_ratio = input.top_controls_shown_ratio();
    result->bottom_controls_height = input.bottom_controls_height();
    result->bottom_controls_shown_ratio = input.bottom_controls_shown_ratio();
    result->root_background_color = input.root_background_color();
    if (!input.ReadSelection(&result->selection))
        success = false;
    if (!input.ReadLatencyInfo(&result->latency_info))
        success = false;
    if (!input.ReadReferencedSurfaces(&result->referenced_surfaces))
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