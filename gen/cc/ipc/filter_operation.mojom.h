// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_FILTER_OPERATION_MOJOM_H_
#define CC_IPC_FILTER_OPERATION_MOJOM_H_

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
#include "cc/ipc/filter_operation.mojom-shared.h"
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
#include "skia/public/interfaces/image_filter.mojom.h"
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
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace cc {
namespace mojom {
    class FilterOperation;
    using FilterOperationPtr = mojo::StructPtr<FilterOperation>;

    class FilterOperation {
    public:
        using DataView = FilterOperationDataView;
        using Data_ = internal::FilterOperation_Data;

        static FilterOperationPtr New();

        template <typename U>
        static FilterOperationPtr From(const U& u)
        {
            return mojo::TypeConverter<FilterOperationPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FilterOperation>::Convert(*this);
        }

        FilterOperation();
        ~FilterOperation();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FilterOperationPtr>
        FilterOperationPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FilterOperation>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FilterOperation::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FilterOperation::DataView, std::vector<uint8_t>>(
                input, output);
        }

        FilterType type;
        float amount;
        gfx::Point drop_shadow_offset;
        uint32_t drop_shadow_color;
        sk_sp<SkImageFilter> image_filter;
        base::Optional<std::vector<float>> matrix;
        int32_t zoom_inset;
    };

    template <typename StructPtrType>
    FilterOperationPtr FilterOperation::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->type = mojo::internal::Clone(type);
        rv->amount = mojo::internal::Clone(amount);
        rv->drop_shadow_offset = mojo::internal::Clone(drop_shadow_offset);
        rv->drop_shadow_color = mojo::internal::Clone(drop_shadow_color);
        rv->image_filter = mojo::internal::Clone(image_filter);
        rv->matrix = mojo::internal::Clone(matrix);
        rv->zoom_inset = mojo::internal::Clone(zoom_inset);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FilterOperation>::value>::type*>
    bool FilterOperation::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->amount, other.amount))
            return false;
        if (!mojo::internal::Equals(this->drop_shadow_offset, other.drop_shadow_offset))
            return false;
        if (!mojo::internal::Equals(this->drop_shadow_color, other.drop_shadow_color))
            return false;
        if (!mojo::internal::Equals(this->image_filter, other.image_filter))
            return false;
        if (!mojo::internal::Equals(this->matrix, other.matrix))
            return false;
        if (!mojo::internal::Equals(this->zoom_inset, other.zoom_inset))
            return false;
        return true;
    }

} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::FilterOperation::DataView,
    ::cc::mojom::FilterOperationPtr> {
    static bool IsNull(const ::cc::mojom::FilterOperationPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::FilterOperationPtr* output) { output->reset(); }

    static decltype(::cc::mojom::FilterOperation::type) type(
        const ::cc::mojom::FilterOperationPtr& input)
    {
        return input->type;
    }

    static decltype(::cc::mojom::FilterOperation::amount) amount(
        const ::cc::mojom::FilterOperationPtr& input)
    {
        return input->amount;
    }

    static const decltype(::cc::mojom::FilterOperation::drop_shadow_offset)& drop_shadow_offset(
        const ::cc::mojom::FilterOperationPtr& input)
    {
        return input->drop_shadow_offset;
    }

    static decltype(::cc::mojom::FilterOperation::drop_shadow_color) drop_shadow_color(
        const ::cc::mojom::FilterOperationPtr& input)
    {
        return input->drop_shadow_color;
    }

    static const decltype(::cc::mojom::FilterOperation::image_filter)& image_filter(
        const ::cc::mojom::FilterOperationPtr& input)
    {
        return input->image_filter;
    }

    static const decltype(::cc::mojom::FilterOperation::matrix)& matrix(
        const ::cc::mojom::FilterOperationPtr& input)
    {
        return input->matrix;
    }

    static decltype(::cc::mojom::FilterOperation::zoom_inset) zoom_inset(
        const ::cc::mojom::FilterOperationPtr& input)
    {
        return input->zoom_inset;
    }

    static bool Read(::cc::mojom::FilterOperation::DataView input, ::cc::mojom::FilterOperationPtr* output);
};

} // namespace mojo

#endif // CC_IPC_FILTER_OPERATION_MOJOM_H_