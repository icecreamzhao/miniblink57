// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_WEB_RESTRICTIONS_INTERFACES_WEB_RESTRICTIONS_MOJOM_SHARED_H_
#define COMPONENTS_WEB_RESTRICTIONS_INTERFACES_WEB_RESTRICTIONS_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/web_restrictions/interfaces/web_restrictions.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace web_restrictions {
namespace mojom {
    class ClientResultDataView;

} // namespace mojom
} // namespace web_restrictions

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::web_restrictions::mojom::ClientResultDataView> {
        using Data = ::web_restrictions::mojom::internal::ClientResult_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace web_restrictions {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class WebRestrictionsInterfaceBase {
    };

    using WebRestrictionsPtrDataView = mojo::InterfacePtrDataView<WebRestrictionsInterfaceBase>;
    using WebRestrictionsRequestDataView = mojo::InterfaceRequestDataView<WebRestrictionsInterfaceBase>;
    using WebRestrictionsAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WebRestrictionsInterfaceBase>;
    using WebRestrictionsAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WebRestrictionsInterfaceBase>;
    class ClientResultDataView {
    public:
        ClientResultDataView() { }

        ClientResultDataView(
            internal::ClientResult_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIntparamsDataView(
            mojo::MapDataView<mojo::StringDataView, int32_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIntparams(UserType* output)
        {
            auto* pointer = data_->intParams.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, int32_t>>(
                pointer, output, context_);
        }
        inline void GetStringparamsDataView(
            mojo::MapDataView<mojo::StringDataView, mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStringparams(UserType* output)
        {
            auto* pointer = data_->stringParams.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, mojo::StringDataView>>(
                pointer, output, context_);
        }

    private:
        internal::ClientResult_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebRestrictions_GetResult_ParamsDataView {
    public:
        WebRestrictions_GetResult_ParamsDataView() { }

        WebRestrictions_GetResult_ParamsDataView(
            internal::WebRestrictions_GetResult_Params_Data* data,
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
        internal::WebRestrictions_GetResult_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebRestrictions_GetResult_ResponseParamsDataView {
    public:
        WebRestrictions_GetResult_ResponseParamsDataView() { }

        WebRestrictions_GetResult_ResponseParamsDataView(
            internal::WebRestrictions_GetResult_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetReplyDataView(
            ClientResultDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReply(UserType* output)
        {
            auto* pointer = data_->reply.Get();
            return mojo::internal::Deserialize<::web_restrictions::mojom::ClientResultDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebRestrictions_GetResult_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebRestrictions_RequestPermission_ParamsDataView {
    public:
        WebRestrictions_RequestPermission_ParamsDataView() { }

        WebRestrictions_RequestPermission_ParamsDataView(
            internal::WebRestrictions_RequestPermission_Params_Data* data,
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
        internal::WebRestrictions_RequestPermission_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebRestrictions_RequestPermission_ResponseParamsDataView {
    public:
        WebRestrictions_RequestPermission_ResponseParamsDataView() { }

        WebRestrictions_RequestPermission_ResponseParamsDataView(
            internal::WebRestrictions_RequestPermission_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool result() const
        {
            return data_->result;
        }

    private:
        internal::WebRestrictions_RequestPermission_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace web_restrictions

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::web_restrictions::mojom::ClientResultDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::web_restrictions::mojom::ClientResultDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::web_restrictions::mojom::internal::ClientResult_Data);
            decltype(CallWithContext(Traits::intParams, input, custom_context)) in_intParams = CallWithContext(Traits::intParams, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, int32_t>>(
                in_intParams, context);
            decltype(CallWithContext(Traits::stringParams, input, custom_context)) in_stringParams = CallWithContext(Traits::stringParams, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, mojo::StringDataView>>(
                in_stringParams, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::web_restrictions::mojom::internal::ClientResult_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::web_restrictions::mojom::internal::ClientResult_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::intParams, input, custom_context)) in_intParams = CallWithContext(Traits::intParams, input, custom_context);
            typename decltype(result->intParams)::BaseType* intParams_ptr;
            const mojo::internal::ContainerValidateParams intParams_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, int32_t>>(
                in_intParams, buffer, &intParams_ptr, &intParams_validate_params,
                context);
            result->intParams.Set(intParams_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->intParams.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null intParams in ClientResult struct");
            decltype(CallWithContext(Traits::stringParams, input, custom_context)) in_stringParams = CallWithContext(Traits::stringParams, input, custom_context);
            typename decltype(result->stringParams)::BaseType* stringParams_ptr;
            const mojo::internal::ContainerValidateParams stringParams_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
            mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, mojo::StringDataView>>(
                in_stringParams, buffer, &stringParams_ptr, &stringParams_validate_params,
                context);
            result->stringParams.Set(stringParams_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->stringParams.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null stringParams in ClientResult struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::web_restrictions::mojom::internal::ClientResult_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::web_restrictions::mojom::ClientResultDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace web_restrictions {
namespace mojom {

    inline void ClientResultDataView::GetIntparamsDataView(
        mojo::MapDataView<mojo::StringDataView, int32_t>* output)
    {
        auto pointer = data_->intParams.Get();
        *output = mojo::MapDataView<mojo::StringDataView, int32_t>(pointer, context_);
    }
    inline void ClientResultDataView::GetStringparamsDataView(
        mojo::MapDataView<mojo::StringDataView, mojo::StringDataView>* output)
    {
        auto pointer = data_->stringParams.Get();
        *output = mojo::MapDataView<mojo::StringDataView, mojo::StringDataView>(pointer, context_);
    }

    inline void WebRestrictions_GetResult_ParamsDataView::GetUrlDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebRestrictions_GetResult_ResponseParamsDataView::GetReplyDataView(
        ClientResultDataView* output)
    {
        auto pointer = data_->reply.Get();
        *output = ClientResultDataView(pointer, context_);
    }

    inline void WebRestrictions_RequestPermission_ParamsDataView::GetUrlDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace web_restrictions

#endif // COMPONENTS_WEB_RESTRICTIONS_INTERFACES_WEB_RESTRICTIONS_MOJOM_SHARED_H_
