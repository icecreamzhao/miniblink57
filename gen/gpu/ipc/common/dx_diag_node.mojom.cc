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

#include "gpu/ipc/common/dx_diag_node.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
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
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
namespace gpu {
namespace mojom { // static
    DxDiagNodePtr DxDiagNode::New()
    {
        DxDiagNodePtr rv;
        mojo::internal::StructHelper<DxDiagNode>::Initialize(&rv);
        return rv;
    }

    DxDiagNode::DxDiagNode()
        : values()
        , children()
    {
    }

    DxDiagNode::~DxDiagNode()
    {
    }
} // namespace mojom
} // namespace gpu

namespace mojo {

// static
bool StructTraits<::gpu::mojom::DxDiagNode::DataView, ::gpu::mojom::DxDiagNodePtr>::Read(
    ::gpu::mojom::DxDiagNode::DataView input,
    ::gpu::mojom::DxDiagNodePtr* output)
{
    bool success = true;
    ::gpu::mojom::DxDiagNodePtr result(::gpu::mojom::DxDiagNode::New());

    if (!input.ReadValues(&result->values))
        success = false;
    if (!input.ReadChildren(&result->children))
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