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

#include "cc/ipc/returned_resource.mojom.h"

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
    ReturnedResourcePtr ReturnedResource::New()
    {
        ReturnedResourcePtr rv;
        mojo::internal::StructHelper<ReturnedResource>::Initialize(&rv);
        return rv;
    }

    ReturnedResource::ReturnedResource()
        : id()
        , sync_token()
        , count()
        , lost()
    {
    }

    ReturnedResource::~ReturnedResource()
    {
    } // static
    ReturnedResourceArrayPtr ReturnedResourceArray::New()
    {
        ReturnedResourceArrayPtr rv;
        mojo::internal::StructHelper<ReturnedResourceArray>::Initialize(&rv);
        return rv;
    }

    ReturnedResourceArray::ReturnedResourceArray()
        : returned_resources()
    {
    }

    ReturnedResourceArray::~ReturnedResourceArray()
    {
    }
} // namespace mojom
} // namespace cc

namespace mojo {

// static
bool StructTraits<::cc::mojom::ReturnedResource::DataView, ::cc::mojom::ReturnedResourcePtr>::Read(
    ::cc::mojom::ReturnedResource::DataView input,
    ::cc::mojom::ReturnedResourcePtr* output)
{
    bool success = true;
    ::cc::mojom::ReturnedResourcePtr result(::cc::mojom::ReturnedResource::New());

    result->id = input.id();
    if (!input.ReadSyncToken(&result->sync_token))
        success = false;
    result->count = input.count();
    result->lost = input.lost();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::cc::mojom::ReturnedResourceArray::DataView, ::cc::mojom::ReturnedResourceArrayPtr>::Read(
    ::cc::mojom::ReturnedResourceArray::DataView input,
    ::cc::mojom::ReturnedResourceArrayPtr* output)
{
    bool success = true;
    ::cc::mojom::ReturnedResourceArrayPtr result(::cc::mojom::ReturnedResourceArray::New());

    if (!input.ReadReturnedResources(&result->returned_resources))
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