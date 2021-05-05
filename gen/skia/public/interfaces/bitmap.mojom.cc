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

#include "skia/public/interfaces/bitmap.mojom.h"

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
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
namespace skia {
namespace mojom { // static
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
} // namespace mojom
} // namespace skia

namespace mojo {

// static
bool StructTraits<::skia::mojom::Bitmap::DataView, ::skia::mojom::BitmapPtr>::Read(
    ::skia::mojom::Bitmap::DataView input,
    ::skia::mojom::BitmapPtr* output)
{
    bool success = true;
    ::skia::mojom::BitmapPtr result(::skia::mojom::Bitmap::New());

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