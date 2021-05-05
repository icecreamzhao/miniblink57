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

#include "skia/public/interfaces/image_filter.mojom-blink.h"

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
namespace skia {
namespace mojom {
    namespace blink { // static
        ImageFilterPtr ImageFilter::New()
        {
            ImageFilterPtr rv;
            mojo::internal::StructHelper<ImageFilter>::Initialize(&rv);
            return rv;
        }

        ImageFilter::ImageFilter()
            : data()
        {
        }

        ImageFilter::~ImageFilter()
        {
        }
    } // namespace blink
} // namespace mojom
} // namespace skia

namespace mojo {

// static
bool StructTraits<::skia::mojom::blink::ImageFilter::DataView, ::skia::mojom::blink::ImageFilterPtr>::Read(
    ::skia::mojom::blink::ImageFilter::DataView input,
    ::skia::mojom::blink::ImageFilterPtr* output)
{
    bool success = true;
    ::skia::mojom::blink::ImageFilterPtr result(::skia::mojom::blink::ImageFilter::New());

    if (!input.ReadData(&result->data))
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