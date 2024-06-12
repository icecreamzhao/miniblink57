// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_REFERRER_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_REFERRER_MOJOM_BLINK_H_

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
#include "third_party/WebKit/public/platform/referrer.mojom-shared.h"
#include "url/mojo/url.mojom-blink.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/platform/weborigin/SecurityOrigin.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebCommon.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/WebSize.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"

namespace blink {
namespace mojom {
    namespace blink {
        using ReferrerPolicy = ReferrerPolicy; // Alias for definition in the parent namespace.
        class Referrer;
        using ReferrerPtr = mojo::StructPtr<Referrer>;

        class BLINK_PLATFORM_EXPORT Referrer {
        public:
            using DataView = ReferrerDataView;
            using Data_ = internal::Referrer_Data;

            static ReferrerPtr New();

            template <typename U>
            static ReferrerPtr From(const U& u)
            {
                return mojo::TypeConverter<ReferrerPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, Referrer>::Convert(*this);
            }

            Referrer();
            ~Referrer();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = ReferrerPtr>
            ReferrerPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, Referrer>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Referrer::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Referrer::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::blink::KURL url;
            ::blink::WebReferrerPolicy policy;
        };

        template <typename StructPtrType>
        ReferrerPtr Referrer::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->url = mojo::internal::Clone(url);
            rv->policy = mojo::internal::Clone(policy);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, Referrer>::value>::type*>
        bool Referrer::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->url, other.url))
                return false;
            if (!mojo::internal::Equals(this->policy, other.policy))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::Referrer::DataView,
    ::blink::mojom::blink::ReferrerPtr> {
    static bool IsNull(const ::blink::mojom::blink::ReferrerPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::ReferrerPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::Referrer::url)& url(
        const ::blink::mojom::blink::ReferrerPtr& input)
    {
        return input->url;
    }

    static decltype(::blink::mojom::blink::Referrer::policy) policy(
        const ::blink::mojom::blink::ReferrerPtr& input)
    {
        return input->policy;
    }

    static bool Read(::blink::mojom::blink::Referrer::DataView input, ::blink::mojom::blink::ReferrerPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_REFERRER_MOJOM_BLINK_H_