// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_STRING16_MOJOM_BLINK_H_
#define MOJO_COMMON_STRING16_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/common/string16.mojom-shared.h"
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

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace mojo {
namespace common {
    namespace mojom {
        namespace blink {
            class String16;
            using String16Ptr = mojo::StructPtr<String16>;

            class String16 {
            public:
                using DataView = String16DataView;
                using Data_ = internal::String16_Data;

                static String16Ptr New();

                template <typename U>
                static String16Ptr From(const U& u)
                {
                    return mojo::TypeConverter<String16Ptr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, String16>::Convert(*this);
                }

                String16();
                ~String16();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = String16Ptr>
                String16Ptr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, String16>::value>::type* = nullptr>
                bool Equals(const T& other) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        String16::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        String16::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                WTF::Vector<uint16_t> data;
            };

            template <typename StructPtrType>
            String16Ptr String16::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->data = mojo::internal::Clone(data);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, String16>::value>::type*>
            bool String16::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->data, other.data))
                    return false;
                return true;
            }

        } // namespace blink
    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {

template <>
struct StructTraits<::mojo::common::mojom::blink::String16::DataView,
    ::mojo::common::mojom::blink::String16Ptr> {
    static bool IsNull(const ::mojo::common::mojom::blink::String16Ptr& input) { return !input; }
    static void SetToNull(::mojo::common::mojom::blink::String16Ptr* output) { output->reset(); }

    static const decltype(::mojo::common::mojom::blink::String16::data)& data(
        const ::mojo::common::mojom::blink::String16Ptr& input)
    {
        return input->data;
    }

    static bool Read(::mojo::common::mojom::blink::String16::DataView input, ::mojo::common::mojom::blink::String16Ptr* output);
};

} // namespace mojo

#endif // MOJO_COMMON_STRING16_MOJOM_BLINK_H_