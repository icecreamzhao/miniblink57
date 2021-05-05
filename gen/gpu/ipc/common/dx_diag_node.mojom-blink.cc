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

#include "gpu/ipc/common/dx_diag_node.mojom-blink.h"

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
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
namespace gpu {
namespace mojom {
    namespace blink { // static
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
    } // namespace blink
} // namespace mojom
} // namespace gpu

namespace mojo {

// static
bool StructTraits<::gpu::mojom::blink::DxDiagNode::DataView, ::gpu::mojom::blink::DxDiagNodePtr>::Read(
    ::gpu::mojom::blink::DxDiagNode::DataView input,
    ::gpu::mojom::blink::DxDiagNodePtr* output)
{
    bool success = true;
    ::gpu::mojom::blink::DxDiagNodePtr result(::gpu::mojom::blink::DxDiagNode::New());

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