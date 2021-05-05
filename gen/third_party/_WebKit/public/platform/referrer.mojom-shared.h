// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_REFERRER_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_REFERRER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/referrer.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared.h"

namespace blink {
namespace mojom {
    class ReferrerDataView;

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::blink::mojom::ReferrerDataView> {
        using Data = ::blink::mojom::internal::Referrer_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class ReferrerPolicy : int32_t {
        ALWAYS,
        DEFAULT,
        NO_REFERRER_WHEN_DOWNGRADE,
        NEVER,
        ORIGIN,
        ORIGIN_WHEN_CROSS_ORIGIN,
        NO_REFERRER_WHEN_DOWNGRADE_ORIGIN_WHEN_CROSS_ORIGIN,
    };

    inline std::ostream& operator<<(std::ostream& os, ReferrerPolicy value)
    {
        switch (value) {
        case ReferrerPolicy::ALWAYS:
            return os << "ReferrerPolicy::ALWAYS";
        case ReferrerPolicy::DEFAULT:
            return os << "ReferrerPolicy::DEFAULT";
        case ReferrerPolicy::NO_REFERRER_WHEN_DOWNGRADE:
            return os << "ReferrerPolicy::NO_REFERRER_WHEN_DOWNGRADE";
        case ReferrerPolicy::NEVER:
            return os << "ReferrerPolicy::NEVER";
        case ReferrerPolicy::ORIGIN:
            return os << "ReferrerPolicy::ORIGIN";
        case ReferrerPolicy::ORIGIN_WHEN_CROSS_ORIGIN:
            return os << "ReferrerPolicy::ORIGIN_WHEN_CROSS_ORIGIN";
        case ReferrerPolicy::NO_REFERRER_WHEN_DOWNGRADE_ORIGIN_WHEN_CROSS_ORIGIN:
            return os << "ReferrerPolicy::NO_REFERRER_WHEN_DOWNGRADE_ORIGIN_WHEN_CROSS_ORIGIN";
        default:
            return os << "Unknown ReferrerPolicy value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ReferrerPolicy value)
    {
        return internal::ReferrerPolicy_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class ReferrerDataView {
    public:
        ReferrerDataView() { }

        ReferrerDataView(
            internal::Referrer_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPolicy(UserType* output) const
        {
            auto data_value = data_->policy;
            return mojo::internal::Deserialize<::blink::mojom::ReferrerPolicy>(
                data_value, output);
        }

        ReferrerPolicy policy() const
        {
            return static_cast<ReferrerPolicy>(data_->policy);
        }

    private:
        internal::Referrer_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::ReferrerPolicy>
    : public mojo::internal::EnumHashImpl<::blink::mojom::ReferrerPolicy> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::ReferrerPolicy, ::blink::mojom::ReferrerPolicy> {
    static ::blink::mojom::ReferrerPolicy ToMojom(::blink::mojom::ReferrerPolicy input) { return input; }
    static bool FromMojom(::blink::mojom::ReferrerPolicy input, ::blink::mojom::ReferrerPolicy* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::ReferrerPolicy, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::ReferrerPolicy, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::ReferrerPolicy>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::ReferrerDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::ReferrerDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::Referrer_Data);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_url, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::Referrer_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::Referrer_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            typename decltype(result->url)::BaseType* url_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_url, buffer, &url_ptr, context);
            result->url.Set(url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null url in Referrer struct");
            mojo::internal::Serialize<::blink::mojom::ReferrerPolicy>(
                CallWithContext(Traits::policy, input, custom_context), &result->policy);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::Referrer_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::ReferrerDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void ReferrerDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_REFERRER_MOJOM_SHARED_H_
