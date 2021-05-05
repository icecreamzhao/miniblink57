// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef URL_MOJO_URL_MOJOM_SHARED_H_
#define URL_MOJO_URL_MOJOM_SHARED_H_

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
#include "url/mojo/url.mojom-shared-internal.h"

namespace url {
namespace mojom {
    class UrlDataView;

} // namespace mojom
} // namespace url

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::url::mojom::UrlDataView> {
        using Data = ::url::mojom::internal::Url_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace url {
namespace mojom {
    class UrlDataView {
    public:
        UrlDataView() { }

        UrlDataView(
            internal::Url_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUrlDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Url_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace url

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::url::mojom::UrlDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::url::mojom::UrlDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::url::mojom::internal::Url_Data);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_url, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::url::mojom::internal::Url_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::url::mojom::internal::Url_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            typename decltype(result->url)::BaseType* url_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_url, buffer, &url_ptr, context);
            result->url.Set(url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null url in Url struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::url::mojom::internal::Url_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::url::mojom::UrlDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace url {
namespace mojom {

    inline void UrlDataView::GetUrlDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace url

#endif // URL_MOJO_URL_MOJOM_SHARED_H_
