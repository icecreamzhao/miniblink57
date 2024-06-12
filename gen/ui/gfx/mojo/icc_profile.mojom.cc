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

#include "ui/gfx/mojo/icc_profile.mojom.h"

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
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
namespace gfx {
namespace mojom { // static
    ICCProfilePtr ICCProfile::New()
    {
        ICCProfilePtr rv;
        mojo::internal::StructHelper<ICCProfile>::Initialize(&rv);
        return rv;
    }

    ICCProfile::ICCProfile()
        : color_space()
        , type()
        , data()
        , id()
    {
    }

    ICCProfile::~ICCProfile()
    {
    }
} // namespace mojom
} // namespace gfx

namespace mojo {

// static
bool StructTraits<::gfx::mojom::ICCProfile::DataView, ::gfx::mojom::ICCProfilePtr>::Read(
    ::gfx::mojom::ICCProfile::DataView input,
    ::gfx::mojom::ICCProfilePtr* output)
{
    bool success = true;
    ::gfx::mojom::ICCProfilePtr result(::gfx::mojom::ICCProfile::New());

    if (!input.ReadColorSpace(&result->color_space))
        success = false;
    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadData(&result->data))
        success = false;
    result->id = input.id();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif