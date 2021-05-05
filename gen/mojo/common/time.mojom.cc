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

#include "mojo/common/time.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace mojo {
namespace common {
    namespace mojom { // static
        TimeDeltaPtr TimeDelta::New()
        {
            TimeDeltaPtr rv;
            mojo::internal::StructHelper<TimeDelta>::Initialize(&rv);
            return rv;
        }

        TimeDelta::TimeDelta()
            : microseconds()
        {
        }

        TimeDelta::~TimeDelta()
        {
        }
    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {

// static
bool StructTraits<::mojo::common::mojom::TimeDelta::DataView, ::mojo::common::mojom::TimeDeltaPtr>::Read(
    ::mojo::common::mojom::TimeDelta::DataView input,
    ::mojo::common::mojom::TimeDeltaPtr* output)
{
    bool success = true;
    ::mojo::common::mojom::TimeDeltaPtr result(::mojo::common::mojom::TimeDelta::New());

    result->microseconds = input.microseconds();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif