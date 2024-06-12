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

#include "skia/public/interfaces/bitmap.mojom-blink.h"

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
        BitmapPtr Bitmap::New()
        {
            BitmapPtr rv;
            mojo::internal::StructHelper<Bitmap>::Initialize(&rv);
            return rv;
        }

        Bitmap::Bitmap()
            : color_type()
            , alpha_type()
            , profile_type()
            , width()
            , height()
            , row_bytes()
            , pixel_data()
        {
        }

        Bitmap::~Bitmap()
        {
        }
    } // namespace blink
} // namespace mojom
} // namespace skia

namespace mojo {

// static
bool StructTraits<::skia::mojom::blink::Bitmap::DataView, ::skia::mojom::blink::BitmapPtr>::Read(
    ::skia::mojom::blink::Bitmap::DataView input,
    ::skia::mojom::blink::BitmapPtr* output)
{
    bool success = true;
    ::skia::mojom::blink::BitmapPtr result(::skia::mojom::blink::Bitmap::New());

    if (!input.ReadColorType(&result->color_type))
        success = false;
    if (!input.ReadAlphaType(&result->alpha_type))
        success = false;
    if (!input.ReadProfileType(&result->profile_type))
        success = false;
    result->width = input.width();
    result->height = input.height();
    result->row_bytes = input.row_bytes();
    if (!input.ReadPixelData(&result->pixel_data))
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