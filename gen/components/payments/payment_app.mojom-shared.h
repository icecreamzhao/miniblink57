// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PAYMENTS_PAYMENT_APP_MOJOM_SHARED_H_
#define COMPONENTS_PAYMENTS_PAYMENT_APP_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/payments/payment_app.mojom-shared-internal.h"
#include "components/payments/payment_request.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "url/mojo/url.mojom-shared.h"

namespace payments {
namespace mojom {
    class PaymentAppOptionDataView;

    class PaymentAppManifestDataView;

    class PaymentAppRequestDataDataView;

} // namespace mojom
} // namespace payments

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentAppOptionDataView> {
        using Data = ::payments::mojom::internal::PaymentAppOption_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentAppManifestDataView> {
        using Data = ::payments::mojom::internal::PaymentAppManifest_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentAppRequestDataDataView> {
        using Data = ::payments::mojom::internal::PaymentAppRequestData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace payments {
namespace mojom {

    enum class PaymentAppManifestError : int32_t {
        NONE,
        NOT_IMPLEMENTED,
        NO_ACTIVE_WORKER,
        MANIFEST_STORAGE_OPERATION_FAILED,
    };

    inline std::ostream& operator<<(std::ostream& os, PaymentAppManifestError value)
    {
        switch (value) {
        case PaymentAppManifestError::NONE:
            return os << "PaymentAppManifestError::NONE";
        case PaymentAppManifestError::NOT_IMPLEMENTED:
            return os << "PaymentAppManifestError::NOT_IMPLEMENTED";
        case PaymentAppManifestError::NO_ACTIVE_WORKER:
            return os << "PaymentAppManifestError::NO_ACTIVE_WORKER";
        case PaymentAppManifestError::MANIFEST_STORAGE_OPERATION_FAILED:
            return os << "PaymentAppManifestError::MANIFEST_STORAGE_OPERATION_FAILED";
        default:
            return os << "Unknown PaymentAppManifestError value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PaymentAppManifestError value)
    {
        return internal::PaymentAppManifestError_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class PaymentAppManagerInterfaceBase {
    };

    using PaymentAppManagerPtrDataView = mojo::InterfacePtrDataView<PaymentAppManagerInterfaceBase>;
    using PaymentAppManagerRequestDataView = mojo::InterfaceRequestDataView<PaymentAppManagerInterfaceBase>;
    using PaymentAppManagerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PaymentAppManagerInterfaceBase>;
    using PaymentAppManagerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PaymentAppManagerInterfaceBase>;
    class PaymentAppOptionDataView {
    public:
        PaymentAppOptionDataView() { }

        PaymentAppOptionDataView(
            internal::PaymentAppOption_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetIconDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIcon(UserType* output)
        {
            auto* pointer = data_->icon.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetEnabledMethodsDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEnabledMethods(UserType* output)
        {
            auto* pointer = data_->enabled_methods.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }

    private:
        internal::PaymentAppOption_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentAppManifestDataView {
    public:
        PaymentAppManifestDataView() { }

        PaymentAppManifestDataView(
            internal::PaymentAppManifest_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetIconDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIcon(UserType* output)
        {
            auto* pointer = data_->icon.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetOptionsDataView(
            mojo::ArrayDataView<PaymentAppOptionDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
        {
            auto* pointer = data_->options.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::PaymentAppOptionDataView>>(
                pointer, output, context_);
        }

    private:
        internal::PaymentAppManifest_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentAppRequestDataDataView {
    public:
        PaymentAppRequestDataDataView() { }

        PaymentAppRequestDataDataView(
            internal::PaymentAppRequestData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOriginDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetMethoddataDataView(
            mojo::ArrayDataView<::payments::mojom::PaymentMethodDataDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMethoddata(UserType* output)
        {
            auto* pointer = data_->methodData.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::PaymentMethodDataDataView>>(
                pointer, output, context_);
        }
        inline void GetTotalDataView(
            ::payments::mojom::PaymentItemDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTotal(UserType* output)
        {
            auto* pointer = data_->total.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentItemDataView>(
                pointer, output, context_);
        }
        inline void GetModifiersDataView(
            mojo::ArrayDataView<::payments::mojom::PaymentDetailsModifierDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadModifiers(UserType* output)
        {
            auto* pointer = data_->modifiers.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::PaymentDetailsModifierDataView>>(
                pointer, output, context_);
        }
        inline void GetOptionidDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptionid(UserType* output)
        {
            auto* pointer = data_->optionId.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentAppRequestData_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentAppManager_Init_ParamsDataView {
    public:
        PaymentAppManager_Init_ParamsDataView() { }

        PaymentAppManager_Init_ParamsDataView(
            internal::PaymentAppManager_Init_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetServiceWorkerScopeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadServiceWorkerScope(UserType* output)
        {
            auto* pointer = data_->service_worker_scope.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentAppManager_Init_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentAppManager_SetManifest_ParamsDataView {
    public:
        PaymentAppManager_SetManifest_ParamsDataView() { }

        PaymentAppManager_SetManifest_ParamsDataView(
            internal::PaymentAppManager_SetManifest_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPaymentAppManifestDataView(
            PaymentAppManifestDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPaymentAppManifest(UserType* output)
        {
            auto* pointer = data_->payment_app_manifest.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentAppManifestDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentAppManager_SetManifest_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentAppManager_SetManifest_ResponseParamsDataView {
    public:
        PaymentAppManager_SetManifest_ResponseParamsDataView() { }

        PaymentAppManager_SetManifest_ResponseParamsDataView(
            internal::PaymentAppManager_SetManifest_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::payments::mojom::PaymentAppManifestError>(
                data_value, output);
        }

        PaymentAppManifestError error() const
        {
            return static_cast<PaymentAppManifestError>(data_->error);
        }

    private:
        internal::PaymentAppManager_SetManifest_ResponseParams_Data* data_ = nullptr;
    };

    class PaymentAppManager_GetManifest_ParamsDataView {
    public:
        PaymentAppManager_GetManifest_ParamsDataView() { }

        PaymentAppManager_GetManifest_ParamsDataView(
            internal::PaymentAppManager_GetManifest_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PaymentAppManager_GetManifest_Params_Data* data_ = nullptr;
    };

    class PaymentAppManager_GetManifest_ResponseParamsDataView {
    public:
        PaymentAppManager_GetManifest_ResponseParamsDataView() { }

        PaymentAppManager_GetManifest_ResponseParamsDataView(
            internal::PaymentAppManager_GetManifest_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPaymentAppManifestDataView(
            PaymentAppManifestDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPaymentAppManifest(UserType* output)
        {
            auto* pointer = data_->payment_app_manifest.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentAppManifestDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::payments::mojom::PaymentAppManifestError>(
                data_value, output);
        }

        PaymentAppManifestError error() const
        {
            return static_cast<PaymentAppManifestError>(data_->error);
        }

    private:
        internal::PaymentAppManager_GetManifest_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace payments

namespace std {

template <>
struct hash<::payments::mojom::PaymentAppManifestError>
    : public mojo::internal::EnumHashImpl<::payments::mojom::PaymentAppManifestError> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::payments::mojom::PaymentAppManifestError, ::payments::mojom::PaymentAppManifestError> {
    static ::payments::mojom::PaymentAppManifestError ToMojom(::payments::mojom::PaymentAppManifestError input) { return input; }
    static bool FromMojom(::payments::mojom::PaymentAppManifestError input, ::payments::mojom::PaymentAppManifestError* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentAppManifestError, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::PaymentAppManifestError, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::PaymentAppManifestError>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentAppOptionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentAppOptionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentAppOption_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::icon, input, custom_context)) in_icon = CallWithContext(Traits::icon, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_icon, context);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_id, context);
            decltype(CallWithContext(Traits::enabled_methods, input, custom_context)) in_enabled_methods = CallWithContext(Traits::enabled_methods, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_enabled_methods, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentAppOption_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentAppOption_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in PaymentAppOption struct");
            decltype(CallWithContext(Traits::icon, input, custom_context)) in_icon = CallWithContext(Traits::icon, input, custom_context);
            typename decltype(result->icon)::BaseType* icon_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_icon, buffer, &icon_ptr, context);
            result->icon.Set(icon_ptr);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            typename decltype(result->id)::BaseType* id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_id, buffer, &id_ptr, context);
            result->id.Set(id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null id in PaymentAppOption struct");
            decltype(CallWithContext(Traits::enabled_methods, input, custom_context)) in_enabled_methods = CallWithContext(Traits::enabled_methods, input, custom_context);
            typename decltype(result->enabled_methods)::BaseType* enabled_methods_ptr;
            const mojo::internal::ContainerValidateParams enabled_methods_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_enabled_methods, buffer, &enabled_methods_ptr, &enabled_methods_validate_params,
                context);
            result->enabled_methods.Set(enabled_methods_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->enabled_methods.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null enabled_methods in PaymentAppOption struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentAppOption_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentAppOptionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentAppManifestDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentAppManifestDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentAppManifest_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::icon, input, custom_context)) in_icon = CallWithContext(Traits::icon, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_icon, context);
            decltype(CallWithContext(Traits::options, input, custom_context)) in_options = CallWithContext(Traits::options, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::PaymentAppOptionDataView>>(
                in_options, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentAppManifest_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentAppManifest_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in PaymentAppManifest struct");
            decltype(CallWithContext(Traits::icon, input, custom_context)) in_icon = CallWithContext(Traits::icon, input, custom_context);
            typename decltype(result->icon)::BaseType* icon_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_icon, buffer, &icon_ptr, context);
            result->icon.Set(icon_ptr);
            decltype(CallWithContext(Traits::options, input, custom_context)) in_options = CallWithContext(Traits::options, input, custom_context);
            typename decltype(result->options)::BaseType* options_ptr;
            const mojo::internal::ContainerValidateParams options_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::PaymentAppOptionDataView>>(
                in_options, buffer, &options_ptr, &options_validate_params,
                context);
            result->options.Set(options_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->options.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null options in PaymentAppManifest struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentAppManifest_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentAppManifestDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentAppRequestDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentAppRequestDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentAppRequestData_Data);
            decltype(CallWithContext(Traits::origin, input, custom_context)) in_origin = CallWithContext(Traits::origin, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_origin, context);
            decltype(CallWithContext(Traits::methodData, input, custom_context)) in_methodData = CallWithContext(Traits::methodData, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::PaymentMethodDataDataView>>(
                in_methodData, context);
            decltype(CallWithContext(Traits::total, input, custom_context)) in_total = CallWithContext(Traits::total, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentItemDataView>(
                in_total, context);
            decltype(CallWithContext(Traits::modifiers, input, custom_context)) in_modifiers = CallWithContext(Traits::modifiers, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::PaymentDetailsModifierDataView>>(
                in_modifiers, context);
            decltype(CallWithContext(Traits::optionId, input, custom_context)) in_optionId = CallWithContext(Traits::optionId, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_optionId, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentAppRequestData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentAppRequestData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::origin, input, custom_context)) in_origin = CallWithContext(Traits::origin, input, custom_context);
            typename decltype(result->origin)::BaseType* origin_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_origin, buffer, &origin_ptr, context);
            result->origin.Set(origin_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->origin.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null origin in PaymentAppRequestData struct");
            decltype(CallWithContext(Traits::methodData, input, custom_context)) in_methodData = CallWithContext(Traits::methodData, input, custom_context);
            typename decltype(result->methodData)::BaseType* methodData_ptr;
            const mojo::internal::ContainerValidateParams methodData_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::PaymentMethodDataDataView>>(
                in_methodData, buffer, &methodData_ptr, &methodData_validate_params,
                context);
            result->methodData.Set(methodData_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->methodData.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null methodData in PaymentAppRequestData struct");
            decltype(CallWithContext(Traits::total, input, custom_context)) in_total = CallWithContext(Traits::total, input, custom_context);
            typename decltype(result->total)::BaseType* total_ptr;
            mojo::internal::Serialize<::payments::mojom::PaymentItemDataView>(
                in_total, buffer, &total_ptr, context);
            result->total.Set(total_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->total.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null total in PaymentAppRequestData struct");
            decltype(CallWithContext(Traits::modifiers, input, custom_context)) in_modifiers = CallWithContext(Traits::modifiers, input, custom_context);
            typename decltype(result->modifiers)::BaseType* modifiers_ptr;
            const mojo::internal::ContainerValidateParams modifiers_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::PaymentDetailsModifierDataView>>(
                in_modifiers, buffer, &modifiers_ptr, &modifiers_validate_params,
                context);
            result->modifiers.Set(modifiers_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->modifiers.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null modifiers in PaymentAppRequestData struct");
            decltype(CallWithContext(Traits::optionId, input, custom_context)) in_optionId = CallWithContext(Traits::optionId, input, custom_context);
            typename decltype(result->optionId)::BaseType* optionId_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_optionId, buffer, &optionId_ptr, context);
            result->optionId.Set(optionId_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->optionId.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null optionId in PaymentAppRequestData struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentAppRequestData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentAppRequestDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace payments {
namespace mojom {

    inline void PaymentAppOptionDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAppOptionDataView::GetIconDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->icon.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAppOptionDataView::GetIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAppOptionDataView::GetEnabledMethodsDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->enabled_methods.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }

    inline void PaymentAppManifestDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAppManifestDataView::GetIconDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->icon.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAppManifestDataView::GetOptionsDataView(
        mojo::ArrayDataView<PaymentAppOptionDataView>* output)
    {
        auto pointer = data_->options.Get();
        *output = mojo::ArrayDataView<PaymentAppOptionDataView>(pointer, context_);
    }

    inline void PaymentAppRequestDataDataView::GetOriginDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void PaymentAppRequestDataDataView::GetMethoddataDataView(
        mojo::ArrayDataView<::payments::mojom::PaymentMethodDataDataView>* output)
    {
        auto pointer = data_->methodData.Get();
        *output = mojo::ArrayDataView<::payments::mojom::PaymentMethodDataDataView>(pointer, context_);
    }
    inline void PaymentAppRequestDataDataView::GetTotalDataView(
        ::payments::mojom::PaymentItemDataView* output)
    {
        auto pointer = data_->total.Get();
        *output = ::payments::mojom::PaymentItemDataView(pointer, context_);
    }
    inline void PaymentAppRequestDataDataView::GetModifiersDataView(
        mojo::ArrayDataView<::payments::mojom::PaymentDetailsModifierDataView>* output)
    {
        auto pointer = data_->modifiers.Get();
        *output = mojo::ArrayDataView<::payments::mojom::PaymentDetailsModifierDataView>(pointer, context_);
    }
    inline void PaymentAppRequestDataDataView::GetOptionidDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->optionId.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PaymentAppManager_Init_ParamsDataView::GetServiceWorkerScopeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->service_worker_scope.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PaymentAppManager_SetManifest_ParamsDataView::GetPaymentAppManifestDataView(
        PaymentAppManifestDataView* output)
    {
        auto pointer = data_->payment_app_manifest.Get();
        *output = PaymentAppManifestDataView(pointer, context_);
    }

    inline void PaymentAppManager_GetManifest_ResponseParamsDataView::GetPaymentAppManifestDataView(
        PaymentAppManifestDataView* output)
    {
        auto pointer = data_->payment_app_manifest.Get();
        *output = PaymentAppManifestDataView(pointer, context_);
    }

} // namespace mojom
} // namespace payments

#endif // COMPONENTS_PAYMENTS_PAYMENT_APP_MOJOM_SHARED_H_
