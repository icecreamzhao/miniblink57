// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef URL_MOJO_ORIGIN_MOJOM_BLINK_H_
#define URL_MOJO_ORIGIN_MOJOM_BLINK_H_

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
#include "url/mojo/origin.mojom-shared.h"

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/platform/weborigin/SecurityOrigin.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace url {
namespace mojom {
    namespace blink {
        class Origin;
        using OriginPtr = mojo::InlinedStructPtr<Origin>;

        class Origin {
        public:
            using DataView = OriginDataView;
            using Data_ = internal::Origin_Data;

            static OriginPtr New();

            template <typename U>
            static OriginPtr From(const U& u)
            {
                return mojo::TypeConverter<OriginPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, Origin>::Convert(*this);
            }

            Origin();
            ~Origin();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = OriginPtr>
            OriginPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, Origin>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Origin::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Origin::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String scheme;
            WTF::String host;
            uint16_t port;
            bool unique;
        };

        template <typename StructPtrType>
        OriginPtr Origin::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->scheme = mojo::internal::Clone(scheme);
            rv->host = mojo::internal::Clone(host);
            rv->port = mojo::internal::Clone(port);
            rv->unique = mojo::internal::Clone(unique);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, Origin>::value>::type*>
        bool Origin::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->scheme, other.scheme))
                return false;
            if (!mojo::internal::Equals(this->host, other.host))
                return false;
            if (!mojo::internal::Equals(this->port, other.port))
                return false;
            if (!mojo::internal::Equals(this->unique, other.unique))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace url

namespace mojo {

template <>
struct StructTraits<::url::mojom::blink::Origin::DataView,
    ::url::mojom::blink::OriginPtr> {
    static bool IsNull(const ::url::mojom::blink::OriginPtr& input) { return !input; }
    static void SetToNull(::url::mojom::blink::OriginPtr* output) { output->reset(); }

    static const decltype(::url::mojom::blink::Origin::scheme)& scheme(
        const ::url::mojom::blink::OriginPtr& input)
    {
        return input->scheme;
    }

    static const decltype(::url::mojom::blink::Origin::host)& host(
        const ::url::mojom::blink::OriginPtr& input)
    {
        return input->host;
    }

    static decltype(::url::mojom::blink::Origin::port) port(
        const ::url::mojom::blink::OriginPtr& input)
    {
        return input->port;
    }

    static decltype(::url::mojom::blink::Origin::unique) unique(
        const ::url::mojom::blink::OriginPtr& input)
    {
        return input->unique;
    }

    static bool Read(::url::mojom::blink::Origin::DataView input, ::url::mojom::blink::OriginPtr* output);
};

} // namespace mojo

#endif // URL_MOJO_ORIGIN_MOJOM_BLINK_H_