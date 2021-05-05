// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_ACCELERATED_WIDGET_MOJOM_H_
#define UI_GFX_MOJO_ACCELERATED_WIDGET_MOJOM_H_

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
#include "ui/gfx/mojo/accelerated_widget.mojom-shared.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace gfx {
namespace mojom {
    class AcceleratedWidget;
    using AcceleratedWidgetPtr = mojo::InlinedStructPtr<AcceleratedWidget>;

    class AcceleratedWidget {
    public:
        using DataView = AcceleratedWidgetDataView;
        using Data_ = internal::AcceleratedWidget_Data;

        static AcceleratedWidgetPtr New();

        template <typename U>
        static AcceleratedWidgetPtr From(const U& u)
        {
            return mojo::TypeConverter<AcceleratedWidgetPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, AcceleratedWidget>::Convert(*this);
        }

        AcceleratedWidget();
        ~AcceleratedWidget();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = AcceleratedWidgetPtr>
        AcceleratedWidgetPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, AcceleratedWidget>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                AcceleratedWidget::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                AcceleratedWidget::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint64_t widget;
    };

    template <typename StructPtrType>
    AcceleratedWidgetPtr AcceleratedWidget::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->widget = mojo::internal::Clone(widget);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, AcceleratedWidget>::value>::type*>
    bool AcceleratedWidget::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->widget, other.widget))
            return false;
        return true;
    }

} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::AcceleratedWidget::DataView,
    ::gfx::mojom::AcceleratedWidgetPtr> {
    static bool IsNull(const ::gfx::mojom::AcceleratedWidgetPtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::AcceleratedWidgetPtr* output) { output->reset(); }

    static decltype(::gfx::mojom::AcceleratedWidget::widget) widget(
        const ::gfx::mojom::AcceleratedWidgetPtr& input)
    {
        return input->widget;
    }

    static bool Read(::gfx::mojom::AcceleratedWidget::DataView input, ::gfx::mojom::AcceleratedWidgetPtr* output);
};

} // namespace mojo

#endif // UI_GFX_MOJO_ACCELERATED_WIDGET_MOJOM_H_