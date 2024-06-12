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

#include "mojo/common/unguessable_token.mojom-blink.h"

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
namespace mojo {
namespace common {
    namespace mojom {
        namespace blink { // static
            UnguessableTokenPtr UnguessableToken::New()
            {
                UnguessableTokenPtr rv;
                mojo::internal::StructHelper<UnguessableToken>::Initialize(&rv);
                return rv;
            }

            UnguessableToken::UnguessableToken()
                : high()
                , low()
            {
            }

            UnguessableToken::~UnguessableToken()
            {
            }
            size_t UnguessableToken::Hash(size_t seed) const
            {
                seed = mojo::internal::WTFHash(seed, this->high);
                seed = mojo::internal::WTFHash(seed, this->low);
                return seed;
            }
        } // namespace blink
    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {

// static
bool StructTraits<::mojo::common::mojom::blink::UnguessableToken::DataView, ::mojo::common::mojom::blink::UnguessableTokenPtr>::Read(
    ::mojo::common::mojom::blink::UnguessableToken::DataView input,
    ::mojo::common::mojom::blink::UnguessableTokenPtr* output)
{
    bool success = true;
    ::mojo::common::mojom::blink::UnguessableTokenPtr result(::mojo::common::mojom::blink::UnguessableToken::New());

    result->high = input.high();
    result->low = input.low();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif