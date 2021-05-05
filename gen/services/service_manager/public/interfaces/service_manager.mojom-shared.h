// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MANAGER_MOJOM_SHARED_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MANAGER_MOJOM_SHARED_H_

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
#include "services/service_manager/public/interfaces/service_manager.mojom-shared-internal.h"

namespace service_manager {
namespace mojom {
    class RunningServiceInfoDataView;

} // namespace mojom
} // namespace service_manager

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::service_manager::mojom::RunningServiceInfoDataView> {
        using Data = ::service_manager::mojom::internal::RunningServiceInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace service_manager {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ServiceManagerListenerInterfaceBase {
    };

    using ServiceManagerListenerPtrDataView = mojo::InterfacePtrDataView<ServiceManagerListenerInterfaceBase>;
    using ServiceManagerListenerRequestDataView = mojo::InterfaceRequestDataView<ServiceManagerListenerInterfaceBase>;
    using ServiceManagerListenerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ServiceManagerListenerInterfaceBase>;
    using ServiceManagerListenerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ServiceManagerListenerInterfaceBase>;
    class ServiceManagerInterfaceBase {
    };

    using ServiceManagerPtrDataView = mojo::InterfacePtrDataView<ServiceManagerInterfaceBase>;
    using ServiceManagerRequestDataView = mojo::InterfaceRequestDataView<ServiceManagerInterfaceBase>;
    using ServiceManagerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ServiceManagerInterfaceBase>;
    using ServiceManagerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ServiceManagerInterfaceBase>;
    class RunningServiceInfoDataView {
    public:
        RunningServiceInfoDataView() { }

        RunningServiceInfoDataView(
            internal::RunningServiceInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t id() const
        {
            return data_->id;
        }
        inline void GetIdentityDataView(
            ::service_manager::mojom::IdentityDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIdentity(UserType* output)
        {
            auto* pointer = data_->identity.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::IdentityDataView>(
                pointer, output, context_);
        }
        uint32_t pid() const
        {
            return data_->pid;
        }

    private:
        internal::RunningServiceInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceManagerListener_OnInit_ParamsDataView {
    public:
        ServiceManagerListener_OnInit_ParamsDataView() { }

        ServiceManagerListener_OnInit_ParamsDataView(
            internal::ServiceManagerListener_OnInit_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRunningServicesDataView(
            mojo::ArrayDataView<RunningServiceInfoDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRunningServices(UserType* output)
        {
            auto* pointer = data_->running_services.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::service_manager::mojom::RunningServiceInfoDataView>>(
                pointer, output, context_);
        }

    private:
        internal::ServiceManagerListener_OnInit_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceManagerListener_OnServiceCreated_ParamsDataView {
    public:
        ServiceManagerListener_OnServiceCreated_ParamsDataView() { }

        ServiceManagerListener_OnServiceCreated_ParamsDataView(
            internal::ServiceManagerListener_OnServiceCreated_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetServiceDataView(
            RunningServiceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadService(UserType* output)
        {
            auto* pointer = data_->service.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::RunningServiceInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceManagerListener_OnServiceCreated_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceManagerListener_OnServiceStarted_ParamsDataView {
    public:
        ServiceManagerListener_OnServiceStarted_ParamsDataView() { }

        ServiceManagerListener_OnServiceStarted_ParamsDataView(
            internal::ServiceManagerListener_OnServiceStarted_Params_Data* data,
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
        uint32_t pid() const
        {
            return data_->pid;
        }

    private:
        internal::ServiceManagerListener_OnServiceStarted_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceManagerListener_OnServiceFailedToStart_ParamsDataView {
    public:
        ServiceManagerListener_OnServiceFailedToStart_ParamsDataView() { }

        ServiceManagerListener_OnServiceFailedToStart_ParamsDataView(
            internal::ServiceManagerListener_OnServiceFailedToStart_Params_Data* data,
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

    private:
        internal::ServiceManagerListener_OnServiceFailedToStart_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceManagerListener_OnServiceStopped_ParamsDataView {
    public:
        ServiceManagerListener_OnServiceStopped_ParamsDataView() { }

        ServiceManagerListener_OnServiceStopped_ParamsDataView(
            internal::ServiceManagerListener_OnServiceStopped_Params_Data* data,
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

    private:
        internal::ServiceManagerListener_OnServiceStopped_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceManager_AddListener_ParamsDataView {
    public:
        ServiceManager_AddListener_ParamsDataView() { }

        ServiceManager_AddListener_ParamsDataView(
            internal::ServiceManager_AddListener_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeListener()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::ServiceManagerListenerPtrDataView>(
                &data_->listener, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::ServiceManager_AddListener_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace service_manager

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::service_manager::mojom::RunningServiceInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::service_manager::mojom::RunningServiceInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::service_manager::mojom::internal::RunningServiceInfo_Data);
            decltype(CallWithContext(Traits::identity, input, custom_context)) in_identity = CallWithContext(Traits::identity, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::service_manager::mojom::IdentityDataView>(
                in_identity, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::service_manager::mojom::internal::RunningServiceInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::service_manager::mojom::internal::RunningServiceInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            decltype(CallWithContext(Traits::identity, input, custom_context)) in_identity = CallWithContext(Traits::identity, input, custom_context);
            typename decltype(result->identity)::BaseType* identity_ptr;
            mojo::internal::Serialize<::service_manager::mojom::IdentityDataView>(
                in_identity, buffer, &identity_ptr, context);
            result->identity.Set(identity_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->identity.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null identity in RunningServiceInfo struct");
            result->pid = CallWithContext(Traits::pid, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::service_manager::mojom::internal::RunningServiceInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::service_manager::mojom::RunningServiceInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace service_manager {
namespace mojom {

    inline void RunningServiceInfoDataView::GetIdentityDataView(
        ::service_manager::mojom::IdentityDataView* output)
    {
        auto pointer = data_->identity.Get();
        *output = ::service_manager::mojom::IdentityDataView(pointer, context_);
    }

    inline void ServiceManagerListener_OnInit_ParamsDataView::GetRunningServicesDataView(
        mojo::ArrayDataView<RunningServiceInfoDataView>* output)
    {
        auto pointer = data_->running_services.Get();
        *output = mojo::ArrayDataView<RunningServiceInfoDataView>(pointer, context_);
    }

    inline void ServiceManagerListener_OnServiceCreated_ParamsDataView::GetServiceDataView(
        RunningServiceInfoDataView* output)
    {
        auto pointer = data_->service.Get();
        *output = RunningServiceInfoDataView(pointer, context_);
    }

    inline void ServiceManagerListener_OnServiceStarted_ParamsDataView::GetIdentityDataView(
        ::service_manager::mojom::IdentityDataView* output)
    {
        auto pointer = data_->identity.Get();
        *output = ::service_manager::mojom::IdentityDataView(pointer, context_);
    }

    inline void ServiceManagerListener_OnServiceFailedToStart_ParamsDataView::GetIdentityDataView(
        ::service_manager::mojom::IdentityDataView* output)
    {
        auto pointer = data_->identity.Get();
        *output = ::service_manager::mojom::IdentityDataView(pointer, context_);
    }

    inline void ServiceManagerListener_OnServiceStopped_ParamsDataView::GetIdentityDataView(
        ::service_manager::mojom::IdentityDataView* output)
    {
        auto pointer = data_->identity.Get();
        *output = ::service_manager::mojom::IdentityDataView(pointer, context_);
    }

} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MANAGER_MOJOM_SHARED_H_
