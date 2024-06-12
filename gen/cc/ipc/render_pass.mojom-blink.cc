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

#include "cc/ipc/render_pass.mojom-blink.h"

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
#include "cc/ipc/surface_sequence_struct_traits.h"
#include "cc/ipc/transferable_resource_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
namespace cc {
namespace mojom {
    namespace blink { // static
        RenderPassPtr RenderPass::New()
        {
            RenderPassPtr rv;
            mojo::internal::StructHelper<RenderPass>::Initialize(&rv);
            return rv;
        }

        RenderPass::RenderPass()
            : id()
            , output_rect()
            , damage_rect()
            , transform_to_root_target()
            , filters()
            , background_filters()
            , has_transparent_background()
            , quad_list()
        {
        }

        RenderPass::~RenderPass()
        {
        }
    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

// static
bool StructTraits<::cc::mojom::blink::RenderPass::DataView, ::cc::mojom::blink::RenderPassPtr>::Read(
    ::cc::mojom::blink::RenderPass::DataView input,
    ::cc::mojom::blink::RenderPassPtr* output)
{
    bool success = true;
    ::cc::mojom::blink::RenderPassPtr result(::cc::mojom::blink::RenderPass::New());

    result->id = input.id();
    if (!input.ReadOutputRect(&result->output_rect))
        success = false;
    if (!input.ReadDamageRect(&result->damage_rect))
        success = false;
    if (!input.ReadTransformToRootTarget(&result->transform_to_root_target))
        success = false;
    if (!input.ReadFilters(&result->filters))
        success = false;
    if (!input.ReadBackgroundFilters(&result->background_filters))
        success = false;
    result->has_transparent_background = input.has_transparent_background();
    if (!input.ReadQuadList(&result->quad_list))
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