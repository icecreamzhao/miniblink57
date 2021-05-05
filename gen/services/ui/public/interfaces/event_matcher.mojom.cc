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

#include "services/ui/public/interfaces/event_matcher.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "cc/ipc/begin_frame_args_struct_traits.h"
#include "cc/ipc/compositor_frame_metadata_struct_traits.h"
#include "cc/ipc/compositor_frame_struct_traits.h"
#include "cc/ipc/filter_operation_struct_traits.h"
#include "cc/ipc/filter_operations_struct_traits.h"
#include "cc/ipc/frame_sink_id_struct_traits.h"
#include "cc/ipc/local_frame_id_struct_traits.h"
#include "cc/ipc/quads_struct_traits.h"
#include "cc/ipc/render_pass_struct_traits.h"
#include "cc/ipc/returned_resource_struct_traits.h"
#include "cc/ipc/selection_struct_traits.h"
#include "cc/ipc/shared_quad_state_struct_traits.h"
#include "cc/ipc/surface_id_struct_traits.h"
#include "cc/ipc/surface_info_struct_traits.h"
#include "cc/ipc/surface_reference_struct_traits.h"
#include "cc/ipc/surface_sequence_struct_traits.h"
#include "cc/ipc/transferable_resource_struct_traits.h"
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "services/ui/public/interfaces/ime/ime_struct_traits.h"
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "ui/events/mojo/event_struct_traits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
#include "ui/gfx/range/mojo/range_struct_traits.h"
namespace ui {
namespace mojom { // static
    KeyEventMatcherPtr KeyEventMatcher::New()
    {
        KeyEventMatcherPtr rv;
        mojo::internal::StructHelper<KeyEventMatcher>::Initialize(&rv);
        return rv;
    }

    KeyEventMatcher::KeyEventMatcher()
        : keyboard_code()
    {
    }

    KeyEventMatcher::~KeyEventMatcher()
    {
    }
    size_t KeyEventMatcher::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->keyboard_code);
        return seed;
    } // static
    PointerKindMatcherPtr PointerKindMatcher::New()
    {
        PointerKindMatcherPtr rv;
        mojo::internal::StructHelper<PointerKindMatcher>::Initialize(&rv);
        return rv;
    }

    PointerKindMatcher::PointerKindMatcher()
        : pointer_kind()
    {
    }

    PointerKindMatcher::~PointerKindMatcher()
    {
    }
    size_t PointerKindMatcher::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->pointer_kind);
        return seed;
    } // static
    PointerLocationMatcherPtr PointerLocationMatcher::New()
    {
        PointerLocationMatcherPtr rv;
        mojo::internal::StructHelper<PointerLocationMatcher>::Initialize(&rv);
        return rv;
    }

    PointerLocationMatcher::PointerLocationMatcher()
        : region()
    {
    }

    PointerLocationMatcher::~PointerLocationMatcher()
    {
    } // static
    EventTypeMatcherPtr EventTypeMatcher::New()
    {
        EventTypeMatcherPtr rv;
        mojo::internal::StructHelper<EventTypeMatcher>::Initialize(&rv);
        return rv;
    }

    EventTypeMatcher::EventTypeMatcher()
        : type()
    {
    }

    EventTypeMatcher::~EventTypeMatcher()
    {
    }
    size_t EventTypeMatcher::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->type);
        return seed;
    } // static
    EventFlagsMatcherPtr EventFlagsMatcher::New()
    {
        EventFlagsMatcherPtr rv;
        mojo::internal::StructHelper<EventFlagsMatcher>::Initialize(&rv);
        return rv;
    }

    EventFlagsMatcher::EventFlagsMatcher()
        : flags()
    {
    }

    EventFlagsMatcher::~EventFlagsMatcher()
    {
    }
    size_t EventFlagsMatcher::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->flags);
        return seed;
    } // static
    EventMatcherPtr EventMatcher::New()
    {
        EventMatcherPtr rv;
        mojo::internal::StructHelper<EventMatcher>::Initialize(&rv);
        return rv;
    }

    EventMatcher::EventMatcher()
        : accelerator_phase()
        , type_matcher()
        , flags_matcher()
        , ignore_flags_matcher()
        , key_matcher()
        , pointer_kind_matcher()
        , pointer_location_matcher()
    {
    }

    EventMatcher::~EventMatcher()
    {
    }
} // namespace mojom
} // namespace ui

namespace mojo {

// static
bool StructTraits<::ui::mojom::KeyEventMatcher::DataView, ::ui::mojom::KeyEventMatcherPtr>::Read(
    ::ui::mojom::KeyEventMatcher::DataView input,
    ::ui::mojom::KeyEventMatcherPtr* output)
{
    bool success = true;
    ::ui::mojom::KeyEventMatcherPtr result(::ui::mojom::KeyEventMatcher::New());

    if (!input.ReadKeyboardCode(&result->keyboard_code))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::PointerKindMatcher::DataView, ::ui::mojom::PointerKindMatcherPtr>::Read(
    ::ui::mojom::PointerKindMatcher::DataView input,
    ::ui::mojom::PointerKindMatcherPtr* output)
{
    bool success = true;
    ::ui::mojom::PointerKindMatcherPtr result(::ui::mojom::PointerKindMatcher::New());

    if (!input.ReadPointerKind(&result->pointer_kind))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::PointerLocationMatcher::DataView, ::ui::mojom::PointerLocationMatcherPtr>::Read(
    ::ui::mojom::PointerLocationMatcher::DataView input,
    ::ui::mojom::PointerLocationMatcherPtr* output)
{
    bool success = true;
    ::ui::mojom::PointerLocationMatcherPtr result(::ui::mojom::PointerLocationMatcher::New());

    if (!input.ReadRegion(&result->region))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::EventTypeMatcher::DataView, ::ui::mojom::EventTypeMatcherPtr>::Read(
    ::ui::mojom::EventTypeMatcher::DataView input,
    ::ui::mojom::EventTypeMatcherPtr* output)
{
    bool success = true;
    ::ui::mojom::EventTypeMatcherPtr result(::ui::mojom::EventTypeMatcher::New());

    if (!input.ReadType(&result->type))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::EventFlagsMatcher::DataView, ::ui::mojom::EventFlagsMatcherPtr>::Read(
    ::ui::mojom::EventFlagsMatcher::DataView input,
    ::ui::mojom::EventFlagsMatcherPtr* output)
{
    bool success = true;
    ::ui::mojom::EventFlagsMatcherPtr result(::ui::mojom::EventFlagsMatcher::New());

    result->flags = input.flags();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::ui::mojom::EventMatcher::DataView, ::ui::mojom::EventMatcherPtr>::Read(
    ::ui::mojom::EventMatcher::DataView input,
    ::ui::mojom::EventMatcherPtr* output)
{
    bool success = true;
    ::ui::mojom::EventMatcherPtr result(::ui::mojom::EventMatcher::New());

    if (!input.ReadAcceleratorPhase(&result->accelerator_phase))
        success = false;
    if (!input.ReadTypeMatcher(&result->type_matcher))
        success = false;
    if (!input.ReadFlagsMatcher(&result->flags_matcher))
        success = false;
    if (!input.ReadIgnoreFlagsMatcher(&result->ignore_flags_matcher))
        success = false;
    if (!input.ReadKeyMatcher(&result->key_matcher))
        success = false;
    if (!input.ReadPointerKindMatcher(&result->pointer_kind_matcher))
        success = false;
    if (!input.ReadPointerLocationMatcher(&result->pointer_location_matcher))
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