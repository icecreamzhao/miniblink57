// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_ICC_PROFILE_MOJOM_BLINK_H_
#define UI_GFX_MOJO_ICC_PROFILE_MOJOM_BLINK_H_

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
#include "ui/gfx/mojo/color_space.mojom-blink.h"
#include "ui/gfx/mojo/icc_profile.mojom-shared.h"

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace gfx {
namespace mojom {
    namespace blink {
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
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    ICCProfile::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    ICCProfile::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::gfx::mojom::blink::ColorSpacePtr color_space;
            ICCProfile::Type type;
            WTF::String data;
            uint64_t id;

        private:
            DISALLOW_COPY_AND_ASSIGN(ICCProfile);
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

    } // namespace blink
} // namespace mojom
} // namespace gfx

namespace mojo {

template <>
struct StructTraits<::gfx::mojom::blink::ICCProfile::DataView,
    ::gfx::mojom::blink::ICCProfilePtr> {
    static bool IsNull(const ::gfx::mojom::blink::ICCProfilePtr& input) { return !input; }
    static void SetToNull(::gfx::mojom::blink::ICCProfilePtr* output) { output->reset(); }

    static const decltype(::gfx::mojom::blink::ICCProfile::color_space)& color_space(
        const ::gfx::mojom::blink::ICCProfilePtr& input)
    {
        return input->color_space;
    }

    static decltype(::gfx::mojom::blink::ICCProfile::type) type(
        const ::gfx::mojom::blink::ICCProfilePtr& input)
    {
        return input->type;
    }

    static const decltype(::gfx::mojom::blink::ICCProfile::data)& data(
        const ::gfx::mojom::blink::ICCProfilePtr& input)
    {
        return input->data;
    }

    static decltype(::gfx::mojom::blink::ICCProfile::id) id(
        const ::gfx::mojom::blink::ICCProfilePtr& input)
    {
        return input->id;
    }

    static bool Read(::gfx::mojom::blink::ICCProfile::DataView input, ::gfx::mojom::blink::ICCProfilePtr* output);
};

} // namespace mojo

#endif // UI_GFX_MOJO_ICC_PROFILE_MOJOM_BLINK_H_