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

#include "device/bluetooth/public/interfaces/uuid.mojom-blink.h"

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
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace bluetooth {
namespace mojom {
    namespace blink { // static
        UUIDPtr UUID::New()
        {
            UUIDPtr rv;
            mojo::internal::StructHelper<UUID>::Initialize(&rv);
            return rv;
        }

        UUID::UUID()
            : uuid()
        {
        }

        UUID::~UUID()
        {
        }
        size_t UUID::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->uuid);
            return seed;
        }
    } // namespace blink
} // namespace mojom
} // namespace bluetooth

namespace mojo {

// static
bool StructTraits<::bluetooth::mojom::blink::UUID::DataView, ::bluetooth::mojom::blink::UUIDPtr>::Read(
    ::bluetooth::mojom::blink::UUID::DataView input,
    ::bluetooth::mojom::blink::UUIDPtr* output)
{
    bool success = true;
    ::bluetooth::mojom::blink::UUIDPtr result(::bluetooth::mojom::blink::UUID::New());

    if (!input.ReadUuid(&result->uuid))
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