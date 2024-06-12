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

#include "skia/public/interfaces/image_filter.mojom.h"

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
} // namespace mojom
} // namespace skia

namespace mojo {

// static
bool StructTraits<::skia::mojom::ImageFilter::DataView, ::skia::mojom::ImageFilterPtr>::Read(
    ::skia::mojom::ImageFilter::DataView input,
    ::skia::mojom::ImageFilterPtr* output)
{
    bool success = true;
    ::skia::mojom::ImageFilterPtr result(::skia::mojom::ImageFilter::New());

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