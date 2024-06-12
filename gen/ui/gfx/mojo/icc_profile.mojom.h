// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_ICC_PROFILE_MOJOM_H_
#define UI_GFX_MOJO_ICC_PROFILE_MOJOM_H_

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
#include "ui/gfx/mojo/color_space.mojom.h"
#include "ui/gfx/mojo/icc_profile.mojom-shared.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace gfx {
namespace mojom {
    class ICCProfile;
    using ICCProfilePtr = mojo::StructPtr<ICCProfile>;

    class ICCProfile {
    public:
        using DataView = ICCProfileDataView;
        using Data_ = internal::ICCProfile_Data;
        using Type = ICCProfile_Type;

        static ICCProfilePtr New();

        template <typename U>
        static ICCProfilePtr From(const U& u)
        {
            return mojo::TypeConverter<ICCProfilePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ICCProfile>::Convert(*this);
        }

        ICCProfile();
        ~ICCProfile();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ICCProfilePtr>
        ICCProfilePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ICCProfile>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ICCProfile::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ICCProfile::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::ColorSpace color_space;
        gfx::ICCProfile::Type type;
        std::string data;
        uint64_t id;
    };

    template <typename StructPtrType>
    ICCProfilePtr ICCProfile::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->color_space = mojo::internal::Clone(color_space);
        rv->type = mojo::internal::Clone(type);
        rv->data = mojo::internal::Clone(data);
        rv->id = mojo::internal::Clone(id);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ICCProfile>::value>::type*>
    bool ICCProfile::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->color_space, other.color_space))
            return false;
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->data, other.data))
            return false;
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        return true;
    }

} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::ICCProfile::DataView,
    ::gfx::mojom::ICCProfilePtr> {
    static bool IsNull(const ::gfx::mojom::ICCProfilePtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::ICCProfilePtr* output) { output->reset(); }

    static const decltype(::gfx::mojom::ICCProfile::color_space)& color_space(
        const ::gfx::mojom::ICCProfilePtr& input)
    {
        return input->color_space;
    }

    static decltype(::gfx::mojom::ICCProfile::type) type(
        const ::gfx::mojom::ICCProfilePtr& input)
    {
        return input->type;
    }

    static const decltype(::gfx::mojom::ICCProfile::data)& data(
        const ::gfx::mojom::ICCProfilePtr& input)
    {
        return input->data;
    }

    static decltype(::gfx::mojom::ICCProfile::id) id(
        const ::gfx::mojom::ICCProfilePtr& input)
    {
        return input->id;
    }

    static bool Read(::gfx::mojom::ICCProfile::DataView input, ::gfx::mojom::ICCProfilePtr* output);
};

} // namespace mojo

#endif // UI_GFX_MOJO_ICC_PROFILE_MOJOM_H_