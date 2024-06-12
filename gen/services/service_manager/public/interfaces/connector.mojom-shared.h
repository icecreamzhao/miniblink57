// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_CONNECTOR_MOJOM_SHARED_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_CONNECTOR_MOJOM_SHARED_H_

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
#include "services/service_manager/public/interfaces/connector.mojom-shared-internal.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared.h"

namespace service_manager {
namespace mojom {
    class IdentityDataView;

} // namespace mojom
} // namespace service_manager

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::service_manager::mojom::IdentityDataView> {
        using Data = ::service_manager::mojom::internal::Identity_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace service_manager {
namespace mojom {

    enum class ConnectResult : int32_t {
        SUCCEEDED,
        INVALID_ARGUMENT,
        ACCESS_DENIED,
    };

    inline std::ostream& operator<<(std::ostream& os, ConnectResult value)
    {
        switch (value) {
        case ConnectResult::SUCCEEDED:
            return os << "ConnectResult::SUCCEEDED";
        case ConnectResult::INVALID_ARGUMENT:
            return os << "ConnectResult::INVALID_ARGUMENT";
        case ConnectResult::ACCESS_DENIED:
            return os << "ConnectResult::ACCESS_DENIED";
        default:
            return os << "Unknown ConnectResult value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ConnectResult value)
    {
        return internal::ConnectResult_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class PIDReceiverInterfaceBase {
    };

    using PIDReceiverPtrDataView = mojo::InterfacePtrDataView<PIDReceiverInterfaceBase>;
    using PIDReceiverRequestDataView = mojo::InterfaceRequestDataView<PIDReceiverInterfaceBase>;
    using PIDReceiverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PIDReceiverInterfaceBase>;
    using PIDReceiverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PIDReceiverInterfaceBase>;
    class ConnectorInterfaceBase {
    };

    using ConnectorPtrDataView = mojo::InterfacePtrDataView<ConnectorInterfaceBase>;
    using ConnectorRequestDataView = mojo::InterfaceRequestDataView<ConnectorInterfaceBase>;
    using ConnectorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ConnectorInterfaceBase>;
    using ConnectorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ConnectorInterfaceBase>;
    class IdentityDataView {
    public:
        IdentityDataView() { }

        IdentityDataView(
            internal::Identity_Data* data,
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
        inline void GetUserIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUserId(UserType* output)
        {
            auto* pointer = data_->user_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetInstanceDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInstance(UserType* output)
        {
            auto* pointer = data_->instance.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Identity_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PIDReceiver_SetPID_ParamsDataView {
    public:
        PIDReceiver_SetPID_ParamsDataView() { }

        PIDReceiver_SetPID_ParamsDataView(
            internal::PIDReceiver_SetPID_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t pid() const
        {
            return data_->pid;
        }

    private:
        internal::PIDReceiver_SetPID_Params_Data* data_ = nullptr;
    };

    class Connector_StartService_ParamsDataView {
    public:
        Connector_StartService_ParamsDataView() { }

        Connector_StartService_ParamsDataView(
            internal::Connector_StartService_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            IdentityDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::IdentityDataView>(
                pointer, output, context_);
        }
        mojo::ScopedMessagePipeHandle TakeService()
        {
            mojo::ScopedMessagePipeHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedMessagePipeHandle>(
                &data_->service, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakePidReceiverRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::PIDReceiverRequestDataView>(
                &data_->pid_receiver_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Connector_StartService_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Connector_Connect_ParamsDataView {
    public:
        Connector_Connect_ParamsDataView() { }

        Connector_Connect_ParamsDataView(
            internal::Connector_Connect_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTargetDataView(
            IdentityDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTarget(UserType* output)
        {
            auto* pointer = data_->target.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::IdentityDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeRemoteInterfaces()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::InterfaceProviderRequestDataView>(
                &data_->remote_interfaces, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Connector_Connect_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Connector_Connect_ResponseParamsDataView {
    public:
        Connector_Connect_ResponseParamsDataView() { }

        Connector_Connect_ResponseParamsDataView(
            internal::Connector_Connect_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::service_manager::mojom::ConnectResult>(
                data_value, output);
        }

        ConnectResult result() const
        {
            return static_cast<ConnectResult>(data_->result);
        }
        inline void GetUserIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUserId(UserType* output)
        {
            auto* pointer = data_->user_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Connector_Connect_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Connector_BindInterface_ParamsDataView {
    public:
        Connector_BindInterface_ParamsDataView() { }

        Connector_BindInterface_ParamsDataView(
            internal::Connector_BindInterface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTargetDataView(
            IdentityDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTarget(UserType* output)
        {
            auto* pointer = data_->target.Get();
            return mojo::internal::Deserialize<::service_manager::mojom::IdentityDataView>(
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
        internal::Connector_BindInterface_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Connector_BindInterface_ResponseParamsDataView {
    public:
        Connector_BindInterface_ResponseParamsDataView() { }

        Connector_BindInterface_ResponseParamsDataView(
            internal::Connector_BindInterface_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::service_manager::mojom::ConnectResult>(
                data_value, output);
        }

        ConnectResult result() const
        {
            return static_cast<ConnectResult>(data_->result);
        }
        inline void GetUserIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUserId(UserType* output)
        {
            auto* pointer = data_->user_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Connector_BindInterface_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Connector_Clone_ParamsDataView {
    public:
        Connector_Clone_ParamsDataView() { }

        Connector_Clone_ParamsDataView(
            internal::Connector_Clone_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::ConnectorRequestDataView>(
                &data_->request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Connector_Clone_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace service_manager

namespace std {

template <>
struct hash<::service_manager::mojom::ConnectResult>
    : public mojo::internal::EnumHashImpl<::service_manager::mojom::ConnectResult> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::service_manager::mojom::ConnectResult, ::service_manager::mojom::ConnectResult> {
    static ::service_manager::mojom::ConnectResult ToMojom(::service_manager::mojom::ConnectResult input) { return input; }
    static bool FromMojom(::service_manager::mojom::ConnectResult input, ::service_manager::mojom::ConnectResult* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::service_manager::mojom::ConnectResult, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::service_manager::mojom::ConnectResult, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::service_manager::mojom::ConnectResult>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::service_manager::mojom::IdentityDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::service_manager::mojom::IdentityDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::service_manager::mojom::internal::Identity_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::user_id, input, custom_context)) in_user_id = CallWithContext(Traits::user_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_user_id, context);
            decltype(CallWithContext(Traits::instance, input, custom_context)) in_instance = CallWithContext(Traits::instance, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_instance, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::service_manager::mojom::internal::Identity_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::service_manager::mojom::internal::Identity_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in Identity struct");
            decltype(CallWithContext(Traits::user_id, input, custom_context)) in_user_id = CallWithContext(Traits::user_id, input, custom_context);
            typename decltype(result->user_id)::BaseType* user_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_user_id, buffer, &user_id_ptr, context);
            result->user_id.Set(user_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->user_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null user_id in Identity struct");
            decltype(CallWithContext(Traits::instance, input, custom_context)) in_instance = CallWithContext(Traits::instance, input, custom_context);
            typename decltype(result->instance)::BaseType* instance_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_instance, buffer, &instance_ptr, context);
            result->instance.Set(instance_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->instance.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null instance in Identity struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::service_manager::mojom::internal::Identity_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::service_manager::mojom::IdentityDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace service_manager {
namespace mojom {

    inline void IdentityDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void IdentityDataView::GetUserIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->user_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void IdentityDataView::GetInstanceDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->instance.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Connector_StartService_ParamsDataView::GetNameDataView(
        IdentityDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = IdentityDataView(pointer, context_);
    }

    inline void Connector_Connect_ParamsDataView::GetTargetDataView(
        IdentityDataView* output)
    {
        auto pointer = data_->target.Get();
        *output = IdentityDataView(pointer, context_);
    }

    inline void Connector_Connect_ResponseParamsDataView::GetUserIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->user_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Connector_BindInterface_ParamsDataView::GetTargetDataView(
        IdentityDataView* output)
    {
        auto pointer = data_->target.Get();
        *output = IdentityDataView(pointer, context_);
    }
    inline void Connector_BindInterface_ParamsDataView::GetInterfaceNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->interface_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Connector_BindInterface_ResponseParamsDataView::GetUserIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->user_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_CONNECTOR_MOJOM_SHARED_H_
