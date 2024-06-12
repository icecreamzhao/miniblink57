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

#include "ui/gfx/range/mojo/range.mojom.h"

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
#include "ui/gfx/range/mojo/range_struct_traits.h"
namespace gfx {
namespace mojom { // static
    RangePtr Range::New()
    {
        RangePtr rv;
        mojo::internal::StructHelper<Range>::Initialize(&rv);
        return rv;
    }

    Range::Range()
        : start()
        , end()
    {
    }

    Range::~Range()
    {
    } // static
    RangeFPtr RangeF::New()
    {
        RangeFPtr rv;
        mojo::internal::StructHelper<RangeF>::Initialize(&rv);
        return rv;
    }

    RangeF::RangeF()
        : start()
        , end()
    {
    }

    RangeF::~RangeF()
    {
    }
} // namespace mojom
} // namespace gfx

namespace mojo {

// static
bool StructTraits<::gfx::mojom::Range::DataView, ::gfx::mojom::RangePtr>::Read(
    ::gfx::mojom::Range::DataView input,
    ::gfx::mojom::RangePtr* output)
{
    bool success = true;
    ::gfx::mojom::RangePtr result(::gfx::mojom::Range::New());

    result->start = input.start();
    result->end = input.end();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::gfx::mojom::RangeF::DataView, ::gfx::mojom::RangeFPtr>::Read(
    ::gfx::mojom::RangeF::DataView input,
    ::gfx::mojom::RangeFPtr* output)
{
    bool success = true;
    ::gfx::mojom::RangeFPtr result(::gfx::mojom::RangeF::New());

    result->start = input.start();
    result->end = input.end();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif