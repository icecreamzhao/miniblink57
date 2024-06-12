// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SHARED_QUAD_STATE_MOJOM_H_
#define CC_IPC_SHARED_QUAD_STATE_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "cc/input/selection.h"
#include "cc/ipc/shared_quad_state.mojom-shared.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/compositor_frame_metadata.h"
#include "cc/output/filter_operation.h"
#include "cc/output/filter_operations.h"
#include "cc/quads/draw_quad.h"
#include "cc/quads/render_pass.h"
#include "cc/quads/shared_quad_state.h"
#include "cc/resources/returned_resource.h"
#include "cc/resources/transferable_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_reference.h"
#include "cc/surfaces/surface_sequence.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/mojo/geometry.mojom.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/mojo/transform.mojom.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace cc {
namespace mojom {
    class SharedQuadState;
    using SharedQuadStatePtr = mojo::StructPtr<SharedQuadState>;

    class SharedQuadState {
    public:
        using DataView = SharedQuadStateDataView;
        using Data_ = internal::SharedQuadState_Data;

        static SharedQuadStatePtr New();

        template <typename U>
        static SharedQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<SharedQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, SharedQuadState>::Convert(*this);
        }

        SharedQuadState();
        ~SharedQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SharedQuadStatePtr>
        SharedQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, SharedQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                SharedQuadState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                SharedQuadState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::Transform quad_to_target_transform;
        gfx::Size quad_layer_bounds;
        gfx::Rect visible_quad_layer_rect;
        gfx::Rect clip_rect;
        bool is_clipped;
        float opacity;
        uint32_t blend_mode;
        int32_t sorting_context_id;
    };

    template <typename StructPtrType>
    SharedQuadStatePtr SharedQuadState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->quad_to_target_transform = mojo::internal::Clone(quad_to_target_transform);
        rv->quad_layer_bounds = mojo::internal::Clone(quad_layer_bounds);
        rv->visible_quad_layer_rect = mojo::internal::Clone(visible_quad_layer_rect);
        rv->clip_rect = mojo::internal::Clone(clip_rect);
        rv->is_clipped = mojo::internal::Clone(is_clipped);
        rv->opacity = mojo::internal::Clone(opacity);
        rv->blend_mode = mojo::internal::Clone(blend_mode);
        rv->sorting_context_id = mojo::internal::Clone(sorting_context_id);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, SharedQuadState>::value>::type*>
    bool SharedQuadState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->quad_to_target_transform, other.quad_to_target_transform))
            return false;
        if (!mojo::internal::Equals(this->quad_layer_bounds, other.quad_layer_bounds))
            return false;
        if (!mojo::internal::Equals(this->visible_quad_layer_rect, other.visible_quad_layer_rect))
            return false;
        if (!mojo::internal::Equals(this->clip_rect, other.clip_rect))
            return false;
        if (!mojo::internal::Equals(this->is_clipped, other.is_clipped))
            return false;
        if (!mojo::internal::Equals(this->opacity, other.opacity))
            return false;
        if (!mojo::internal::Equals(this->blend_mode, other.blend_mode))
            return false;
        if (!mojo::internal::Equals(this->sorting_context_id, other.sorting_context_id))
            return false;
        return true;
    }

} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::SharedQuadState::DataView,
    ::cc::mojom::SharedQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::SharedQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::SharedQuadStatePtr* output) { output->reset(); }

    static const decltype(::cc::mojom::SharedQuadState::quad_to_target_transform)& quad_to_target_transform(
        const ::cc::mojom::SharedQuadStatePtr& input)
    {
        return input->quad_to_target_transform;
    }

    static const decltype(::cc::mojom::SharedQuadState::quad_layer_bounds)& quad_layer_bounds(
        const ::cc::mojom::SharedQuadStatePtr& input)
    {
        return input->quad_layer_bounds;
    }

    static const decltype(::cc::mojom::SharedQuadState::visible_quad_layer_rect)& visible_quad_layer_rect(
        const ::cc::mojom::SharedQuadStatePtr& input)
    {
        return input->visible_quad_layer_rect;
    }

    static const decltype(::cc::mojom::SharedQuadState::clip_rect)& clip_rect(
        const ::cc::mojom::SharedQuadStatePtr& input)
    {
        return input->clip_rect;
    }

    static decltype(::cc::mojom::SharedQuadState::is_clipped) is_clipped(
        const ::cc::mojom::SharedQuadStatePtr& input)
    {
        return input->is_clipped;
    }

    static decltype(::cc::mojom::SharedQuadState::opacity) opacity(
        const ::cc::mojom::SharedQuadStatePtr& input)
    {
        return input->opacity;
    }

    static decltype(::cc::mojom::SharedQuadState::blend_mode) blend_mode(
        const ::cc::mojom::SharedQuadStatePtr& input)
    {
        return input->blend_mode;
    }

    static decltype(::cc::mojom::SharedQuadState::sorting_context_id) sorting_context_id(
        const ::cc::mojom::SharedQuadStatePtr& input)
    {
        return input->sorting_context_id;
    }

    static bool Read(::cc::mojom::SharedQuadState::DataView input, ::cc::mojom::SharedQuadStatePtr* output);
};

} // namespace mojo

#endif // CC_IPC_SHARED_QUAD_STATE_MOJOM_H_