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

#include "ui/events/mojo/latency_info.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "ui/events/mojo/event_struct_traits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
namespace ui {
namespace mojom { // static
    LatencyComponentIdPtr LatencyComponentId::New()
    {
        LatencyComponentIdPtr rv;
        mojo::internal::StructHelper<LatencyComponentId>::Initialize(&rv);
        return rv;
    }

    LatencyComponentId::LatencyComponentId()
        : type()
        , id()
    {
    }

    LatencyComponentId::~LatencyComponentId()
    {
    } // static
    LatencyComponentPtr LatencyComponent::New()
    {
        LatencyComponentPtr rv;
        mojo::internal::StructHelper<LatencyComponent>::Initialize(&rv);
        return rv;
    }

    LatencyComponent::LatencyComponent()
        : sequence_number()
        , event_time()
        , event_count()
    {
    }

    LatencyComponent::~LatencyComponent()
    {
    } // static
    LatencyComponentPairPtr LatencyComponentPair::New()
    {
        LatencyComponentPairPtr rv;
        mojo::internal::StructHelper<LatencyComponentPair>::Initialize(&rv);
        return rv;
    }

    LatencyComponentPair::LatencyComponentPair()
        : key()
        , value()
    {
    }

    LatencyComponentPair::~LatencyComponentPair()
    {
    } // static
    LatencyInfoPtr LatencyInfo::New()
    {
        LatencyInfoPtr rv;
        mojo::internal::StructHelper<LatencyInfo>::Initialize(&rv);
        return rv;
    }

    LatencyInfo::LatencyInfo()
        : trace_name()
        , latency_components()
        , input_coordinates()
        , trace_id()
        , coalesced()
        , terminated()
    {
    }

    LatencyInfo::~LatencyInfo()
    {
    }
} // namespace mojom
} // namespace ui

namespace mojo {

// static
bool StructTraits<::ui::mojom::LatencyComponentId::DataView, ::ui::mojom::LatencyComponentIdPtr>::Read(
    ::ui::mojom::LatencyComponentId::DataView input,
    ::ui::mojom::LatencyComponentIdPtr* output)
{
    bool success = true;
    ::ui::mojom::LatencyComponentIdPtr result(::ui::mojom::LatencyComponentId::New());

    if (!input.ReadType(&result->type))
        success = false;
    result->id = input.id();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::LatencyComponent::DataView, ::ui::mojom::LatencyComponentPtr>::Read(
    ::ui::mojom::LatencyComponent::DataView input,
    ::ui::mojom::LatencyComponentPtr* output)
{
    bool success = true;
    ::ui::mojom::LatencyComponentPtr result(::ui::mojom::LatencyComponent::New());

    result->sequence_number = input.sequence_number();
    if (!input.ReadEventTime(&result->event_time))
        success = false;
    result->event_count = input.event_count();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::LatencyComponentPair::DataView, ::ui::mojom::LatencyComponentPairPtr>::Read(
    ::ui::mojom::LatencyComponentPair::DataView input,
    ::ui::mojom::LatencyComponentPairPtr* output)
{
    bool success = true;
    ::ui::mojom::LatencyComponentPairPtr result(::ui::mojom::LatencyComponentPair::New());

    if (!input.ReadKey(&result->key))
        success = false;
    if (!input.ReadValue(&result->value))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::LatencyInfo::DataView, ::ui::mojom::LatencyInfoPtr>::Read(
    ::ui::mojom::LatencyInfo::DataView input,
    ::ui::mojom::LatencyInfoPtr* output)
{
    bool success = true;
    ::ui::mojom::LatencyInfoPtr result(::ui::mojom::LatencyInfo::New());

    if (!input.ReadTraceName(&result->trace_name))
        success = false;
    if (!input.ReadLatencyComponents(&result->latency_components))
        success = false;
    if (!input.ReadInputCoordinates(&result->input_coordinates))
        success = false;
    result->trace_id = input.trace_id();
    result->coalesced = input.coalesced();
    result->terminated = input.terminated();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif