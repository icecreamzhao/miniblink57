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

#include "mojo/common/version.mojom.h"

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
        VersionPtr Version::New()
        {
            VersionPtr rv;
            mojo::internal::StructHelper<Version>::Initialize(&rv);
            return rv;
        }

        Version::Version()
            : components()
        {
        }

        Version::~Version()
        {
        }
    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {

// static
bool StructTraits<::mojo::common::mojom::Version::DataView, ::mojo::common::mojom::VersionPtr>::Read(
    ::mojo::common::mojom::Version::DataView input,
    ::mojo::common::mojom::VersionPtr* output)
{
    bool success = true;
    ::mojo::common::mojom::VersionPtr result(::mojo::common::mojom::Version::New());

    if (!input.ReadComponents(&result->components))
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