// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_MOJOM_H_

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
#include "services/ui/public/interfaces/display/display.mojom-shared.h"
#include "ui/display/display.h"
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
#include <string>
#include <vector>

namespace display {
namespace mojom {
    class Display;
    using DisplayPtr = mojo::StructPtr<Display>;

    class Display {
    public:
        using DataView = DisplayDataView;
        using Data_ = internal::Display_Data;

        static DisplayPtr New();

        template <typename U>
        static DisplayPtr From(const U& u)
        {
            return mojo::TypeConverter<DisplayPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Display>::Convert(*this);
        }

        Display();
        ~Display();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = DisplayPtr>
        DisplayPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Display>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Display::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Display::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int64_t id;
        gfx::Rect bounds;
        gfx::Rect work_area;
        float device_scale_factor;
        Rotation rotation;
        display::Display::TouchSupport touch_support;
        gfx::Size maximum_cursor_size;
    };

    template <typename StructPtrType>
    DisplayPtr Display::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        rv->bounds = mojo::internal::Clone(bounds);
        rv->work_area = mojo::internal::Clone(work_area);
        rv->device_scale_factor = mojo::internal::Clone(device_scale_factor);
        rv->rotation = mojo::internal::Clone(rotation);
        rv->touch_support = mojo::internal::Clone(touch_support);
        rv->maximum_cursor_size = mojo::internal::Clone(maximum_cursor_size);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Display>::value>::type*>
    bool Display::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->bounds, other.bounds))
            return false;
        if (!mojo::internal::Equals(this->work_area, other.work_area))
            return false;
        if (!mojo::internal::Equals(this->device_scale_factor, other.device_scale_factor))
            return false;
        if (!mojo::internal::Equals(this->rotation, other.rotation))
            return false;
        if (!mojo::internal::Equals(this->touch_support, other.touch_support))
            return false;
        if (!mojo::internal::Equals(this->maximum_cursor_size, other.maximum_cursor_size))
            return false;
        return true;
    }

} // namespace mojom
} // namespace display

namespace mojo {

template <>
struct StructTraits<::display::mojom::Display::DataView,
    ::display::mojom::DisplayPtr> {
    static bool IsNull(const ::display::mojom::DisplayPtr& input) { return !input; }
    static void SetToNull(::display::mojom::DisplayPtr* output) { output->reset(); }

    static decltype(::display::mojom::Display::id) id(
        const ::display::mojom::DisplayPtr& input)
    {
        return input->id;
    }

    static const decltype(::display::mojom::Display::bounds)& bounds(
        const ::display::mojom::DisplayPtr& input)
    {
        return input->bounds;
    }

    static const decltype(::display::mojom::Display::work_area)& work_area(
        const ::display::mojom::DisplayPtr& input)
    {
        return input->work_area;
    }

    static decltype(::display::mojom::Display::device_scale_factor) device_scale_factor(
        const ::display::mojom::DisplayPtr& input)
    {
        return input->device_scale_factor;
    }

    static decltype(::display::mojom::Display::rotation) rotation(
        const ::display::mojom::DisplayPtr& input)
    {
        return input->rotation;
    }

    static decltype(::display::mojom::Display::touch_support) touch_support(
        const ::display::mojom::DisplayPtr& input)
    {
        return input->touch_support;
    }

    static const decltype(::display::mojom::Display::maximum_cursor_size)& maximum_cursor_size(
        const ::display::mojom::DisplayPtr& input)
    {
        return input->maximum_cursor_size;
    }

    static bool Read(::display::mojom::Display::DataView input, ::display::mojom::DisplayPtr* output);
};

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_MOJOM_H_