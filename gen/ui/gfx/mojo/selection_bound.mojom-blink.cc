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

#include "ui/gfx/mojo/selection_bound.mojom-blink.h"

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
        SelectionBoundPtr SelectionBound::New()
        {
            SelectionBoundPtr rv;
            mojo::internal::StructHelper<SelectionBound>::Initialize(&rv);
            return rv;
        }

        SelectionBound::SelectionBound()
            : type()
            , edge_top()
            , edge_bottom()
            , visible()
        {
        }

        SelectionBound::~SelectionBound()
        {
        }
        size_t SelectionBound::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->type);
            seed = mojo::internal::WTFHash(seed, this->edge_top);
            seed = mojo::internal::WTFHash(seed, this->edge_bottom);
            seed = mojo::internal::WTFHash(seed, this->visible);
            return seed;
        }
    } // namespace blink
} // namespace mojom
} // namespace gfx

namespace mojo {

// static
bool StructTraits<::gfx::mojom::blink::SelectionBound::DataView, ::gfx::mojom::blink::SelectionBoundPtr>::Read(
    ::gfx::mojom::blink::SelectionBound::DataView input,
    ::gfx::mojom::blink::SelectionBoundPtr* output)
{
    bool success = true;
    ::gfx::mojom::blink::SelectionBoundPtr result(::gfx::mojom::blink::SelectionBound::New());

    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadEdgeTop(&result->edge_top))
        success = false;
    if (!input.ReadEdgeBottom(&result->edge_bottom))
        success = false;
    result->visible = input.visible();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif