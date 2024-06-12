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

#include "ui/events/mojo/latency_info.mojom-blink.h"

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
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
namespace ui {
namespace mojom {
    namespace blink { // static
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
        }
        size_t LatencyComponentId::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->type);
            seed = mojo::internal::WTFHash(seed, this->id);
            return seed;
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
        }
        size_t LatencyComponent::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->sequence_number);
            seed = mojo::internal::WTFHash(seed, this->event_time);
            seed = mojo::internal::WTFHash(seed, this->event_count);
            return seed;
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
        }
        size_t LatencyComponentPair::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->key);
            seed = mojo::internal::WTFHash(seed, this->value);
            return seed;
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
    } // namespace blink
} // namespace mojom
} // namespace ui

namespace mojo {

// static
bool StructTraits<::ui::mojom::blink::LatencyComponentId::DataView, ::ui::mojom::blink::LatencyComponentIdPtr>::Read(
    ::ui::mojom::blink::LatencyComponentId::DataView input,
    ::ui::mojom::blink::LatencyComponentIdPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::LatencyComponentIdPtr result(::ui::mojom::blink::LatencyComponentId::New());

    if (!input.ReadType(&result->type))
        success = false;
    result->id = input.id();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::blink::LatencyComponent::DataView, ::ui::mojom::blink::LatencyComponentPtr>::Read(
    ::ui::mojom::blink::LatencyComponent::DataView input,
    ::ui::mojom::blink::LatencyComponentPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::LatencyComponentPtr result(::ui::mojom::blink::LatencyComponent::New());

    result->sequence_number = input.sequence_number();
    if (!input.ReadEventTime(&result->event_time))
        success = false;
    result->event_count = input.event_count();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::blink::LatencyComponentPair::DataView, ::ui::mojom::blink::LatencyComponentPairPtr>::Read(
    ::ui::mojom::blink::LatencyComponentPair::DataView input,
    ::ui::mojom::blink::LatencyComponentPairPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::LatencyComponentPairPtr result(::ui::mojom::blink::LatencyComponentPair::New());

    if (!input.ReadKey(&result->key))
        success = false;
    if (!input.ReadValue(&result->value))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::blink::LatencyInfo::DataView, ::ui::mojom::blink::LatencyInfoPtr>::Read(
    ::ui::mojom::blink::LatencyInfo::DataView input,
    ::ui::mojom::blink::LatencyInfoPtr* output)
{
    bool success = true;
    ::ui::mojom::blink::LatencyInfoPtr result(::ui::mojom::blink::LatencyInfo::New());

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