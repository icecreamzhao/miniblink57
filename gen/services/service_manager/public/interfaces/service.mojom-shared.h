// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_H_

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
#include "services/service_manager/public/interfaces/connector.mojom-shared.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared.h"
#include "services/service_manager/public/interfaces/interface_provider_spec.mojom-shared.h"
#include "services/service_manager/public/interfaces/service.mojom-shared-internal.h"
#include "services/service_manager/public/interfaces/service_control.mojom-shared.h"

namespace service_manager {
namespace mojom {
    class ServiceInfoDataView;

} // namespace mojom
} // namespace service_manager

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::service_manager::mojom::ServiceInfoDataView> {
        using Data = ::service_manager::mojom::internal::ServiceInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace service_manager {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ServiceInterfaceBase {
    };

    using ServicePtrDataView = mojo::InterfacePtrDataView<ServiceInterfaceBase>;
    using ServiceRequestDataView = mojo::InterfaceRequestDataView<ServiceInterfaceBase>;
    using ServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ServiceInterfaceBase>;
    using ServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ServiceInterfaceBase>;
    class ServiceInfoDataView {
    public:
        ServiceInfoDataView() { }

        ServiceInfoDataView(
            internal::ServiceInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIdentityDataView(
            ::service_manager::mojom::IdentityDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIdentity(UserType* output)
        {
            auto* pointer = data_->identity.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::IdentityDataView>(
                pointer, output, context_);
        }
        inline void GetInterfaceProviderSpecsDataView(
            mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInterfaceProviderSpecs(UserType* output)
        {
            auto* pointer = data_->interface_provider_specs.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>>(
                pointer, output, context_);
        }

    private:
        internal::ServiceInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Service_OnStart_ParamsDataView {
    public:
        Service_OnStart_ParamsDataView() { }

        Service_OnStart_ParamsDataView(
            internal::Service_OnStart_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInfoDataView(
            ServiceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInfo(UserType* output)
        {
            auto* pointer = data_->info.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::ServiceInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::Service_OnStart_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Service_OnStart_ResponseParamsDataView {
    public:
        Service_OnStart_ResponseParamsDataView() { }

        Service_OnStart_ResponseParamsDataView(
            internal::Service_OnStart_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeConnectorRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::ConnectorRequestDataView>(
                &data_->connector_request, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeControlRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::ServiceControlAssociatedRequestDataView>(
                &data_->control_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Service_OnStart_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Service_OnConnect_ParamsDataView {
    public:
        Service_OnConnect_ParamsDataView() { }

        Service_OnConnect_ParamsDataView(
            internal::Service_OnConnect_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSourceInfoDataView(
            ServiceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSourceInfo(UserType* output)
        {
            auto* pointer = data_->source_info.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::ServiceInfoDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeInterfaces()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::InterfaceProviderRequestDataView>(
                &data_->interfaces, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Service_OnConnect_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Service_OnConnect_ResponseParamsDataView {
    public:
        Service_OnConnect_ResponseParamsDataView() { }

        Service_OnConnect_ResponseParamsDataView(
            internal::Service_OnConnect_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Service_OnConnect_ResponseParams_Data* data_ = nullptr;
    };

    class Service_OnBindInterface_ParamsDataView {
    public:
        Service_OnBindInterface_ParamsDataView() { }

        Service_OnBindInterface_ParamsDataView(
            internal::Service_OnBindInterface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSourceInfoDataView(
            ServiceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSourceInfo(UserType* output)
        {
            auto* pointer = data_->source_info.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::ServiceInfoDataView>(
                pointer, output, context_);
        }
        inline void GetInterfaceNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInterfaceName(UserType* output)
        {
            auto* pointer = data_->interface_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        mojo::ScopedMessagePipeHandle TakeInterfacePipe()
        {
            mojo::ScopedMessagePipeHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedMessagePipeHandle>(
                &data_->interface_pipe, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Service_OnBindInterface_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Service_OnBindInterface_ResponseParamsDataView {
    public:
        Service_OnBindInterface_ResponseParamsDataView() { }

        Service_OnBindInterface_ResponseParamsDataView(
            internal::Service_OnBindInterface_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Service_OnBindInterface_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace service_manager

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::service_manager::mojom::ServiceInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::service_manager::mojom::ServiceInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::service_manager::mojom::internal::ServiceInfo_Data);
            decltype(CallWithContext(Traits::identity, input, custom_context)) in_identity = CallWithContext(Traits::identity, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::service_manager::mojom::IdentityDataView>(
                in_identity, context);
            decltype(CallWithContext(Traits::interface_provider_specs, input, custom_context)) in_interface_provider_specs = CallWithContext(Traits::interface_provider_specs, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>>(
                in_interface_provider_specs, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::service_manager::mojom::internal::ServiceInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::service_manager::mojom::internal::ServiceInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::identity, input, custom_context)) in_identity = CallWithContext(Traits::identity, input, custom_context);
            typename decltype(result->identity)::BaseType* identity_ptr;
            mojo::internal::Serialize<::service_manager::mojom::IdentityDataView>(
                in_identity, buffer, &identity_ptr, context);
            result->identity.Set(identity_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->identity.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null identity in ServiceInfo struct");
            decltype(CallWithContext(Traits::interface_provider_specs, input, custom_context)) in_interface_provider_specs = CallWithContext(Traits::interface_provider_specs, input, custom_context);
            typename decltype(result->interface_provider_specs)::BaseType* interface_provider_specs_ptr;
            const mojo::internal::ContainerValidateParams interface_provider_specs_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>>(
                in_interface_provider_specs, buffer, &interface_provider_specs_ptr, &interface_provider_specs_validate_params,
                context);
            result->interface_provider_specs.Set(interface_provider_specs_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->interface_provider_specs.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null interface_provider_specs in ServiceInfo struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::service_manager::mojom::internal::ServiceInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::service_manager::mojom::ServiceInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace service_manager {
namespace mojom {

    inline void ServiceInfoDataView::GetIdentityDataView(
        ::service_manager::mojom::IdentityDataView* output)
    {
        auto pointer = data_->identity.Get();
        *output = ::service_manager::mojom::IdentityDataView(pointer, context_);
    }
    inline void ServiceInfoDataView::GetInterfaceProviderSpecsDataView(
        mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>* output)
    {
        auto pointer = data_->interface_provider_specs.Get();
        *output = mojo::MapDataView<mojo::StringDataView, ::service_manager::mojom::InterfaceProviderSpecDataView>(pointer, context_);
    }

    inline void Service_OnStart_ParamsDataView::GetInfoDataView(
        ServiceInfoDataView* output)
    {
        auto pointer = data_->info.Get();
        *output = ServiceInfoDataView(pointer, context_);
    }

    inline void Service_OnConnect_ParamsDataView::GetSourceInfoDataView(
        ServiceInfoDataView* output)
    {
        auto pointer = data_->source_info.Get();
        *output = ServiceInfoDataView(pointer, context_);
    }

    inline void Service_OnBindInterface_ParamsDataView::GetSourceInfoDataView(
        ServiceInfoDataView* output)
    {
        auto pointer = data_->source_info.Get();
        *output = ServiceInfoDataView(pointer, context_);
    }
    inline void Service_OnBindInterface_ParamsDataView::GetInterfaceNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->interface_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_H_
