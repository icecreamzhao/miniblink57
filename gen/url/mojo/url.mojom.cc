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

#include "url/mojo/url.mojom.h"

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
#include "url/mojo/url_gurl_struct_traits.h"
namespace url {
namespace mojom { // static
    UrlPtr Url::New()
    {
        UrlPtr rv;
        mojo::internal::StructHelper<Url>::Initialize(&rv);
        return rv;
    }

    Url::Url()
        : url()
    {
    }

    Url::~Url()
    {
    }
} // namespace mojom
} // namespace url

namespace mojo {

// static
bool StructTraits<::url::mojom::Url::DataView, ::url::mojom::UrlPtr>::Read(
    ::url::mojom::Url::DataView input,
    ::url::mojom::UrlPtr* output)
{
    bool success = true;
    ::url::mojom::UrlPtr result(::url::mojom::Url::New());

    if (!input.ReadUrl(&result->url))
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