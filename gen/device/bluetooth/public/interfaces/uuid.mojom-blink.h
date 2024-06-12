// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_BLUETOOTH_PUBLIC_INTERFACES_UUID_MOJOM_BLINK_H_
#define DEVICE_BLUETOOTH_PUBLIC_INTERFACES_UUID_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/bluetooth/public/interfaces/uuid.mojom-shared.h"
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

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace bluetooth {
namespace mojom {
    namespace blink {
        class UUID;
        using UUIDPtr = mojo::InlinedStructPtr<UUID>;

        class UUID {
        public:
            using DataView = UUIDDataView;
            using Data_ = internal::UUID_Data;

            static UUIDPtr New();

            template <typename U>
            static UUIDPtr From(const U& u)
            {
                return mojo::TypeConverter<UUIDPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, UUID>::Convert(*this);
            }

            UUID();
            ~UUID();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = UUIDPtr>
            UUIDPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, UUID>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    UUID::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    UUID::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String uuid;
        };

        template <typename StructPtrType>
        UUIDPtr UUID::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->uuid = mojo::internal::Clone(uuid);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, UUID>::value>::type*>
        bool UUID::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->uuid, other.uuid))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace bluetooth

namespace mojo {

template <>
struct StructTraits<::bluetooth::mojom::blink::UUID::DataView,
    ::bluetooth::mojom::blink::UUIDPtr> {
    static bool IsNull(const ::bluetooth::mojom::blink::UUIDPtr& input) { return !input; }
    static void SetToNull(::bluetooth::mojom::blink::UUIDPtr* output) { output->reset(); }

    static const decltype(::bluetooth::mojom::blink::UUID::uuid)& uuid(
        const ::bluetooth::mojom::blink::UUIDPtr& input)
    {
        return input->uuid;
    }

    static bool Read(::bluetooth::mojom::blink::UUID::DataView input, ::bluetooth::mojom::blink::UUIDPtr* output);
};

} // namespace mojo

#endif // DEVICE_BLUETOOTH_PUBLIC_INTERFACES_UUID_MOJOM_BLINK_H_