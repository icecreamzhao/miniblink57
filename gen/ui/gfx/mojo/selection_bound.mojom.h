// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_SELECTION_BOUND_MOJOM_H_
#define UI_GFX_MOJO_SELECTION_BOUND_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
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
#include "ui/gfx/mojo/selection_bound.mojom-shared.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace gfx {
namespace mojom {
    class SelectionBound;
    using SelectionBoundPtr = mojo::StructPtr<SelectionBound>;

    class SelectionBound {
    public:
        using DataView = SelectionBoundDataView;
        using Data_ = internal::SelectionBound_Data;

        static SelectionBoundPtr New();

        template <typename U>
        static SelectionBoundPtr From(const U& u)
        {
            return mojo::TypeConverter<SelectionBoundPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, SelectionBound>::Convert(*this);
        }

        SelectionBound();
        ~SelectionBound();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SelectionBoundPtr>
        SelectionBoundPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, SelectionBound>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                SelectionBound::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                SelectionBound::DataView, std::vector<uint8_t>>(
                input, output);
        }

        SelectionBoundType type;
        gfx::PointF edge_top;
        gfx::PointF edge_bottom;
        bool visible;
    };

    template <typename StructPtrType>
    SelectionBoundPtr SelectionBound::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->type = mojo::internal::Clone(type);
        rv->edge_top = mojo::internal::Clone(edge_top);
        rv->edge_bottom = mojo::internal::Clone(edge_bottom);
        rv->visible = mojo::internal::Clone(visible);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, SelectionBound>::value>::type*>
    bool SelectionBound::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->edge_top, other.edge_top))
            return false;
        if (!mojo::internal::Equals(this->edge_bottom, other.edge_bottom))
            return false;
        if (!mojo::internal::Equals(this->visible, other.visible))
            return false;
        return true;
    }

} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::SelectionBound::DataView,
    ::gfx::mojom::SelectionBoundPtr> {
    static bool IsNull(const ::gfx::mojom::SelectionBoundPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::SelectionBoundPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::SelectionBound::type) type(
        const ::gfx::mojom::SelectionBoundPtr& input)
    {
        return input->type;
    }

    static const decltype(::gfx::mojom::SelectionBound::edge_top)& edge_top(
        const ::gfx::mojom::SelectionBoundPtr& input)
    {
        return input->edge_top;
    }

    static const decltype(::gfx::mojom::SelectionBound::edge_bottom)& edge_bottom(
        const ::gfx::mojom::SelectionBoundPtr& input)
    {
        return input->edge_bottom;
    }

    static decltype(::gfx::mojom::SelectionBound::visible) visible(
        const ::gfx::mojom::SelectionBoundPtr& input)
    {
        return input->visible;
    }

    static bool Read(::gfx::mojom::SelectionBound::DataView input, ::gfx::mojom::SelectionBoundPtr* output);
};

} // namespace mojo

#endif // UI_GFX_MOJO_SELECTION_BOUND_MOJOM_H_