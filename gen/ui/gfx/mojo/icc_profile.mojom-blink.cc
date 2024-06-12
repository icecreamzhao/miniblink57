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

#include "ui/gfx/mojo/icc_profile.mojom-blink.h"

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
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
namespace gfx {
namespace mojom {
    namespace blink { // static
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
        size_t ICCProfile::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->color_space);
            seed = mojo::internal::WTFHash(seed, this->type);
            seed = mojo::internal::WTFHash(seed, this->data);
            seed = mojo::internal::WTFHash(seed, this->id);
            return seed;
        }
    } // namespace blink
} // namespace mojom
} // namespace gfx

namespace mojo {

// static
bool StructTraits<::gfx::mojom::blink::ICCProfile::DataView, ::gfx::mojom::blink::ICCProfilePtr>::Read(
    ::gfx::mojom::blink::ICCProfile::DataView input,
    ::gfx::mojom::blink::ICCProfilePtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::ICCProfilePtr result(::gfx::mojom::blink::ICCProfile::New());

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