// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef URL_MOJO_URL_MOJOM_BLINK_H_
#define URL_MOJO_URL_MOJOM_BLINK_H_

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
#include "url/mojo/url.mojom-shared.h"

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace url {
namespace mojom {
    namespace blink {
        class Url;
        using UrlPtr = mojo::InlinedStructPtr<Url>;

        class Url {
        public:
            using DataView = UrlDataView;
            using Data_ = internal::Url_Data;

            static UrlPtr New();

            template <typename U>
            static UrlPtr From(const U& u)
            {
                return mojo::TypeConverter<UrlPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, Url>::Convert(*this);
            }

            Url();
            ~Url();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = UrlPtr>
            UrlPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, Url>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Url::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Url::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String url;
        };

        template <typename StructPtrType>
        UrlPtr Url::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->url = mojo::internal::Clone(url);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, Url>::value>::type*>
        bool Url::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->url, other.url))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace url

namespace mojo {

template <>
struct StructTraits<::url::mojom::blink::Url::DataView,
    ::url::mojom::blink::UrlPtr> {
    static bool IsNull(const ::url::mojom::blink::UrlPtr& input) { return !input; }
    static void SetToNull(::url::mojom::blink::UrlPtr* output) { output->reset(); }

    static const decltype(::url::mojom::blink::Url::url)& url(
        const ::url::mojom::blink::UrlPtr& input)
    {
        return input->url;
    }

    static bool Read(::url::mojom::blink::Url::DataView input, ::url::mojom::blink::UrlPtr* output);
};

} // namespace mojo

#endif // URL_MOJO_URL_MOJOM_BLINK_H_