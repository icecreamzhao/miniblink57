// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_CONSTANTS_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_CONSTANTS_MOJOM_H_

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
#include "services/ui/public/interfaces/display/display.mojom.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom-shared.h"
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
    constexpr int32_t kResizeBehaviorNone = 0;
    constexpr int32_t kResizeBehaviorCanResize = 1;
    constexpr int32_t kResizeBehaviorCanMaximize = 2;
    constexpr int32_t kResizeBehaviorCanMinimize = 4;
    class FrameDecorationValues;
    using FrameDecorationValuesPtr = mojo::StructPtr<FrameDecorationValues>;

    class WsDisplay;
    using WsDisplayPtr = mojo::StructPtr<WsDisplay>;

    class FrameDecorationValues {
    public:
        using DataView = FrameDecorationValuesDataView;
        using Data_ = internal::FrameDecorationValues_Data;

        static FrameDecorationValuesPtr New();

        template <typename U>
        static FrameDecorationValuesPtr From(const U& u)
        {
            return mojo::TypeConverter<FrameDecorationValuesPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FrameDecorationValues>::Convert(*this);
        }

        FrameDecorationValues();
        ~FrameDecorationValues();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FrameDecorationValuesPtr>
        FrameDecorationValuesPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FrameDecorationValues>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FrameDecorationValues::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FrameDecorationValues::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::Insets normal_client_area_insets;
        gfx::Insets maximized_client_area_insets;
        uint32_t max_title_bar_button_width;
    };

    class WsDisplay {
    public:
        using DataView = WsDisplayDataView;
        using Data_ = internal::WsDisplay_Data;

        static WsDisplayPtr New();

        template <typename U>
        static WsDisplayPtr From(const U& u)
        {
            return mojo::TypeConverter<WsDisplayPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, WsDisplay>::Convert(*this);
        }

        WsDisplay();
        ~WsDisplay();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = WsDisplayPtr>
        WsDisplayPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, WsDisplay>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                WsDisplay::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                WsDisplay::DataView, std::vector<uint8_t>>(
                input, output);
        }

        display::Display display;
        FrameDecorationValuesPtr frame_decoration_values;

    private:
        DISALLOW_COPY_AND_ASSIGN(WsDisplay);
    };

    template <typename StructPtrType>
    FrameDecorationValuesPtr FrameDecorationValues::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->normal_client_area_insets = mojo::internal::Clone(normal_client_area_insets);
        rv->maximized_client_area_insets = mojo::internal::Clone(maximized_client_area_insets);
        rv->max_title_bar_button_width = mojo::internal::Clone(max_title_bar_button_width);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FrameDecorationValues>::value>::type*>
    bool FrameDecorationValues::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->normal_client_area_insets, other.normal_client_area_insets))
            return false;
        if (!mojo::internal::Equals(this->maximized_client_area_insets, other.maximized_client_area_insets))
            return false;
        if (!mojo::internal::Equals(this->max_title_bar_button_width, other.max_title_bar_button_width))
            return false;
        return true;
    }
    template <typename StructPtrType>
    WsDisplayPtr WsDisplay::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->display = mojo::internal::Clone(display);
        rv->frame_decoration_values = mojo::internal::Clone(frame_decoration_values);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, WsDisplay>::value>::type*>
    bool WsDisplay::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->display, other.display))
            return false;
        if (!mojo::internal::Equals(this->frame_decoration_values, other.frame_decoration_values))
            return false;
        return true;
    }

} // namespace mojom
} // namespace ui

namespace mojo {

template <>
struct StructTraits<::ui::mojom::FrameDecorationValues::DataView,
    ::ui::mojom::FrameDecorationValuesPtr> {
    static bool IsNull(const ::ui::mojom::FrameDecorationValuesPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::FrameDecorationValuesPtr* output) { output->reset(); }

    static const decltype(::ui::mojom::FrameDecorationValues::normal_client_area_insets)& normal_client_area_insets(
        const ::ui::mojom::FrameDecorationValuesPtr& input)
    {
        return input->normal_client_area_insets;
    }

    static const decltype(::ui::mojom::FrameDecorationValues::maximized_client_area_insets)& maximized_client_area_insets(
        const ::ui::mojom::FrameDecorationValuesPtr& input)
    {
        return input->maximized_client_area_insets;
    }

    static decltype(::ui::mojom::FrameDecorationValues::max_title_bar_button_width) max_title_bar_button_width(
        const ::ui::mojom::FrameDecorationValuesPtr& input)
    {
        return input->max_title_bar_button_width;
    }

    static bool Read(::ui::mojom::FrameDecorationValues::DataView input, ::ui::mojom::FrameDecorationValuesPtr* output);
};

template <>
struct StructTraits<::ui::mojom::WsDisplay::DataView,
    ::ui::mojom::WsDisplayPtr> {
    static bool IsNull(const ::ui::mojom::WsDisplayPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::WsDisplayPtr* output) { output->reset(); }

    static const decltype(::ui::mojom::WsDisplay::display)& display(
        const ::ui::mojom::WsDisplayPtr& input)
    {
        return input->display;
    }

    static const decltype(::ui::mojom::WsDisplay::frame_decoration_values)& frame_decoration_values(
        const ::ui::mojom::WsDisplayPtr& input)
    {
        return input->frame_decoration_values;
    }

    static bool Read(::ui::mojom::WsDisplay::DataView input, ::ui::mojom::WsDisplayPtr* output);
};

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_CONSTANTS_MOJOM_H_