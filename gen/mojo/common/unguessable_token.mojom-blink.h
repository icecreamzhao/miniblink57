// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_UNGUESSABLE_TOKEN_MOJOM_BLINK_H_
#define MOJO_COMMON_UNGUESSABLE_TOKEN_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/common/unguessable_token.mojom-shared.h"
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
            class UnguessableToken;
            using UnguessableTokenPtr = mojo::InlinedStructPtr<UnguessableToken>;

            class UnguessableToken {
            public:
                using DataView = UnguessableTokenDataView;
                using Data_ = internal::UnguessableToken_Data;

                static UnguessableTokenPtr New();

                template <typename U>
                static UnguessableTokenPtr From(const U& u)
                {
                    return mojo::TypeConverter<UnguessableTokenPtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, UnguessableToken>::Convert(*this);
                }

                UnguessableToken();
                ~UnguessableToken();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = UnguessableTokenPtr>
                UnguessableTokenPtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, UnguessableToken>::value>::type* = nullptr>
                bool Equals(const T& other) const;
                size_t Hash(size_t seed) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        UnguessableToken::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        UnguessableToken::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                uint64_t high;
                uint64_t low;
            };

            template <typename StructPtrType>
            UnguessableTokenPtr UnguessableToken::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->high = mojo::internal::Clone(high);
                rv->low = mojo::internal::Clone(low);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, UnguessableToken>::value>::type*>
            bool UnguessableToken::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->high, other.high))
                    return false;
                if (!mojo::internal::Equals(this->low, other.low))
                    return false;
                return true;
            }

        } // namespace blink
    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {

template <>
struct StructTraits<::mojo::common::mojom::blink::UnguessableToken::DataView,
    ::mojo::common::mojom::blink::UnguessableTokenPtr> {
    static bool IsNull(const ::mojo::common::mojom::blink::UnguessableTokenPtr& input) { return !input; }
    static void SetToNull(::mojo::common::mojom::blink::UnguessableTokenPtr* output) { output->reset(); }

    static decltype(::mojo::common::mojom::blink::UnguessableToken::high) high(
        const ::mojo::common::mojom::blink::UnguessableTokenPtr& input)
    {
        return input->high;
    }

    static decltype(::mojo::common::mojom::blink::UnguessableToken::low) low(
        const ::mojo::common::mojom::blink::UnguessableTokenPtr& input)
    {
        return input->low;
    }

    static bool Read(::mojo::common::mojom::blink::UnguessableToken::DataView input, ::mojo::common::mojom::blink::UnguessableTokenPtr* output);
};

} // namespace mojo

#endif // MOJO_COMMON_UNGUESSABLE_TOKEN_MOJOM_BLINK_H_