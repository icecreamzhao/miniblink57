// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_REFERRER_MOJOM_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_REFERRER_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/referrer.h"
#include "device/bluetooth/bluetooth_uuid.h"
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
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/referrer.mojom-shared.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include "url/mojo/url.mojom.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace blink {
namespace mojom {
    class Referrer;
    using ReferrerPtr = mojo::StructPtr<Referrer>;

    class CONTENT_EXPORT Referrer {
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
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Referrer::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Referrer::DataView, std::vector<uint8_t>>(
                input, output);
        }

        GURL url;
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

} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::blink::mojom::Referrer::DataView,
    ::blink::mojom::ReferrerPtr> {
    static bool IsNull(const ::blink::mojom::ReferrerPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::ReferrerPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::Referrer::url)& url(
        const ::blink::mojom::ReferrerPtr& input)
    {
        return input->url;
    }

    static decltype(::blink::mojom::Referrer::policy) policy(
        const ::blink::mojom::ReferrerPtr& input)
    {
        return input->policy;
    }

    static bool Read(::blink::mojom::Referrer::DataView input, ::blink::mojom::ReferrerPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_REFERRER_MOJOM_H_