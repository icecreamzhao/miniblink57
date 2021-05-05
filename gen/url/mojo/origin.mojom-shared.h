// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef URL_MOJO_ORIGIN_MOJOM_SHARED_H_
#define URL_MOJO_ORIGIN_MOJOM_SHARED_H_

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
#include "url/mojo/origin.mojom-shared-internal.h"

namespace url {
namespace mojom {
    class OriginDataView;

} // namespace mojom
} // namespace url

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::url::mojom::OriginDataView> {
        using Data = ::url::mojom::internal::Origin_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace url {
namespace mojom {
    class OriginDataView {
    public:
        OriginDataView() { }

        OriginDataView(
            internal::Origin_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSchemeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadScheme(UserType* output)
        {
            auto* pointer = data_->scheme.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetHostDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHost(UserType* output)
        {
            auto* pointer = data_->host.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        uint16_t port() const
        {
            return data_->port;
        }
        bool unique() const
        {
            return data_->unique;
        }

    private:
        internal::Origin_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace url

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::url::mojom::OriginDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::url::mojom::OriginDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::url::mojom::internal::Origin_Data);
            decltype(CallWithContext(Traits::scheme, input, custom_context)) in_scheme = CallWithContext(Traits::scheme, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_scheme, context);
            decltype(CallWithContext(Traits::host, input, custom_context)) in_host = CallWithContext(Traits::host, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_host, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::url::mojom::internal::Origin_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::url::mojom::internal::Origin_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::scheme, input, custom_context)) in_scheme = CallWithContext(Traits::scheme, input, custom_context);
            typename decltype(result->scheme)::BaseType* scheme_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_scheme, buffer, &scheme_ptr, context);
            result->scheme.Set(scheme_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->scheme.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null scheme in Origin struct");
            decltype(CallWithContext(Traits::host, input, custom_context)) in_host = CallWithContext(Traits::host, input, custom_context);
            typename decltype(result->host)::BaseType* host_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_host, buffer, &host_ptr, context);
            result->host.Set(host_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->host.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null host in Origin struct");
            result->port = CallWithContext(Traits::port, input, custom_context);
            result->unique = CallWithContext(Traits::unique, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::url::mojom::internal::Origin_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::url::mojom::OriginDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace url {
namespace mojom {

    inline void OriginDataView::GetSchemeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->scheme.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void OriginDataView::GetHostDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->host.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace url

#endif // URL_MOJO_ORIGIN_MOJOM_SHARED_H_
