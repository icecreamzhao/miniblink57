// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_CONSTANTS_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_CONSTANTS_MOJOM_H_

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
#include "services/ui/public/interfaces/window_tree_constants.mojom-shared.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/display/display.h"
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
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/range/range.h"
#include "ui/gfx/range/range_f.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    constexpr uint32_t kDropEffectNone = 0U;
    constexpr uint32_t kDropEffectMove = 1U;
    constexpr uint32_t kDropEffectCopy = 2U;
    constexpr uint32_t kDropEffectLink = 4U;
    constexpr uint32_t kEmbedFlagEmbedderInterceptsEvents = 0x01U;
    class WindowData;
    using WindowDataPtr = mojo::StructPtr<WindowData>;

    class WindowData {
    public:
        using DataView = WindowDataDataView;
        using Data_ = internal::WindowData_Data;

        static WindowDataPtr New();

        template <typename U>
        static WindowDataPtr From(const U& u)
        {
            return mojo::TypeConverter<WindowDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, WindowData>::Convert(*this);
        }

        WindowData();
        ~WindowData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = WindowDataPtr>
        WindowDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, WindowData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                WindowData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                WindowData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t parent_id;
        uint32_t window_id;
        uint32_t transient_parent_id;
        gfx::Rect bounds;
        std::unordered_map<std::string, std::vector<uint8_t>> properties;
        bool visible;
    };

    template <typename StructPtrType>
    WindowDataPtr WindowData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->parent_id = mojo::internal::Clone(parent_id);
        rv->window_id = mojo::internal::Clone(window_id);
        rv->transient_parent_id = mojo::internal::Clone(transient_parent_id);
        rv->bounds = mojo::internal::Clone(bounds);
        rv->properties = mojo::internal::Clone(properties);
        rv->visible = mojo::internal::Clone(visible);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, WindowData>::value>::type*>
    bool WindowData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->parent_id, other.parent_id))
            return false;
        if (!mojo::internal::Equals(this->window_id, other.window_id))
            return false;
        if (!mojo::internal::Equals(this->transient_parent_id, other.transient_parent_id))
            return false;
        if (!mojo::internal::Equals(this->bounds, other.bounds))
            return false;
        if (!mojo::internal::Equals(this->properties, other.properties))
            return false;
        if (!mojo::internal::Equals(this->visible, other.visible))
            return false;
        return true;
    }

} // namespace mojom
} // namespace ui

namespace mojo {

template <>
struct StructTraits<::ui::mojom::WindowData::DataView,
    ::ui::mojom::WindowDataPtr> {
    static bool IsNull(const ::ui::mojom::WindowDataPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::WindowDataPtr* output) { output->reset(); }

    static decltype(::ui::mojom::WindowData::parent_id) parent_id(
        const ::ui::mojom::WindowDataPtr& input)
    {
        return input->parent_id;
    }

    static decltype(::ui::mojom::WindowData::window_id) window_id(
        const ::ui::mojom::WindowDataPtr& input)
    {
        return input->window_id;
    }

    static decltype(::ui::mojom::WindowData::transient_parent_id) transient_parent_id(
        const ::ui::mojom::WindowDataPtr& input)
    {
        return input->transient_parent_id;
    }

    static const decltype(::ui::mojom::WindowData::bounds)& bounds(
        const ::ui::mojom::WindowDataPtr& input)
    {
        return input->bounds;
    }

    static const decltype(::ui::mojom::WindowData::properties)& properties(
        const ::ui::mojom::WindowDataPtr& input)
    {
        return input->properties;
    }

    static decltype(::ui::mojom::WindowData::visible) visible(
        const ::ui::mojom::WindowDataPtr& input)
    {
        return input->visible;
    }

    static bool Read(::ui::mojom::WindowData::DataView input, ::ui::mojom::WindowDataPtr* output);
};

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_CONSTANTS_MOJOM_H_