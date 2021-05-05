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

#include "gpu/ipc/common/sync_token.mojom-blink.h"

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
        SyncTokenPtr SyncToken::New()
        {
            SyncTokenPtr rv;
            mojo::internal::StructHelper<SyncToken>::Initialize(&rv);
            return rv;
        }

        SyncToken::SyncToken()
            : verified_flush()
            , namespace_id()
            , extra_data_field()
            , command_buffer_id()
            , release_count()
        {
        }

        SyncToken::~SyncToken()
        {
        }
        size_t SyncToken::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->verified_flush);
            seed = mojo::internal::WTFHash(seed, this->namespace_id);
            seed = mojo::internal::WTFHash(seed, this->extra_data_field);
            seed = mojo::internal::WTFHash(seed, this->command_buffer_id);
            seed = mojo::internal::WTFHash(seed, this->release_count);
            return seed;
        }
    } // namespace blink
} // namespace mojom
} // namespace gpu

namespace mojo {

// static
bool StructTraits<::gpu::mojom::blink::SyncToken::DataView, ::gpu::mojom::blink::SyncTokenPtr>::Read(
    ::gpu::mojom::blink::SyncToken::DataView input,
    ::gpu::mojom::blink::SyncTokenPtr* output)
{
    bool success = true;
    ::gpu::mojom::blink::SyncTokenPtr result(::gpu::mojom::blink::SyncToken::New());

    result->verified_flush = input.verified_flush();
    if (!input.ReadNamespaceId(&result->namespace_id))
        success = false;
    result->extra_data_field = input.extra_data_field();
    result->command_buffer_id = input.command_buffer_id();
    result->release_count = input.release_count();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif