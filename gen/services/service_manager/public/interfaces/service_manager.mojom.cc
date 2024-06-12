// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "services/service_manager/public/interfaces/service_manager.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/service_manager/public/cpp/identity_struct_traits.h"
#include "services/service_manager/public/cpp/interface_provider_spec_struct_traits.h"
#include "services/service_manager/public/cpp/service_info_struct_traits.h"
namespace service_manager {
namespace mojom { // static
    RunningServiceInfoPtr RunningServiceInfo::New()
    {
        RunningServiceInfoPtr rv;
        mojo::internal::StructHelper<RunningServiceInfo>::Initialize(&rv);
        return rv;
    }

    RunningServiceInfo::RunningServiceInfo()
        : id()
        , identity()
        , pid()
    {
    }

    RunningServiceInfo::~RunningServiceInfo()
    {
    }
    const char ServiceManagerListener::Name_[] = "service_manager::mojom::ServiceManagerListener";

    ServiceManagerListenerProxy::ServiceManagerListenerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ServiceManagerListenerProxy::OnInit(
        std::vector<RunningServiceInfoPtr> in_running_services)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::service_manager::mojom::internal::ServiceManagerListener_OnInit_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::service_manager::mojom::RunningServiceInfoDataView>>(
            in_running_services, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kServiceManagerListener_OnInit_Name, size);

        auto params = ::service_manager::mojom::internal::ServiceManagerListener_OnInit_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->running_services)::BaseType* running_services_ptr;
        const mojo::internal::ContainerValidateParams running_services_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::service_manager::mojom::RunningServiceInfoDataView>>(
            in_running_services, builder.buffer(), &running_services_ptr, &running_services_validate_params,
            &serialization_context);
        params->running_services.Set(running_services_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->running_services.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null running_services in ServiceManagerListener.OnInit request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ServiceManagerListenerProxy::OnServiceCreated(
        RunningServiceInfoPtr in_service)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::service_manager::mojom::internal::ServiceManagerListener_OnServiceCreated_Params_Data);
        size += mojo::internal::PrepareToSerialize<::service_manager::mojom::RunningServiceInfoDataView>(
            in_service, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kServiceManagerListener_OnServiceCreated_Name, size);

        auto params = ::service_manager::mojom::internal::ServiceManagerListener_OnServiceCreated_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->service)::BaseType* service_ptr;
        mojo::internal::Serialize<::service_manager::mojom::RunningServiceInfoDataView>(
            in_service, builder.buffer(), &service_ptr, &serialization_context);
        params->service.Set(service_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->service.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null service in ServiceManagerListener.OnServiceCreated request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ServiceManagerListenerProxy::OnServiceStarted(
        const ::service_manager::Identity& in_identity, uint32_t in_pid)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::service_manager::mojom::internal::ServiceManagerListener_OnServiceStarted_Params_Data);
        size += mojo::internal::PrepareToSerialize<::service_manager::mojom::IdentityDataView>(
            in_identity, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kServiceManagerListener_OnServiceStarted_Name, size);

        auto params = ::service_manager::mojom::internal::ServiceManagerListener_OnServiceStarted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->identity)::BaseType* identity_ptr;
        mojo::internal::Serialize<::service_manager::mojom::IdentityDataView>(
            in_identity, builder.buffer(), &identity_ptr, &serialization_context);
        params->identity.Set(identity_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->identity.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null identity in ServiceManagerListener.OnServiceStarted request");
        params->pid = in_pid;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ServiceManagerListenerProxy::OnServiceFailedToStart(
        const ::service_manager::Identity& in_identity)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::service_manager::mojom::internal::ServiceManagerListener_OnServiceFailedToStart_Params_Data);
        size += mojo::internal::PrepareToSerialize<::service_manager::mojom::IdentityDataView>(
            in_identity, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kServiceManagerListener_OnServiceFailedToStart_Name, size);

        auto params = ::service_manager::mojom::internal::ServiceManagerListener_OnServiceFailedToStart_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->identity)::BaseType* identity_ptr;
        mojo::internal::Serialize<::service_manager::mojom::IdentityDataView>(
            in_identity, builder.buffer(), &identity_ptr, &serialization_context);
        params->identity.Set(identity_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->identity.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null identity in ServiceManagerListener.OnServiceFailedToStart request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ServiceManagerListenerProxy::OnServiceStopped(
        const ::service_manager::Identity& in_identity)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::service_manager::mojom::internal::ServiceManagerListener_OnServiceStopped_Params_Data);
        size += mojo::internal::PrepareToSerialize<::service_manager::mojom::IdentityDataView>(
            in_identity, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kServiceManagerListener_OnServiceStopped_Name, size);

        auto params = ::service_manager::mojom::internal::ServiceManagerListener_OnServiceStopped_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->identity)::BaseType* identity_ptr;
        mojo::internal::Serialize<::service_manager::mojom::IdentityDataView>(
            in_identity, builder.buffer(), &identity_ptr, &serialization_context);
        params->identity.Set(identity_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->identity.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null identity in ServiceManagerListener.OnServiceStopped request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool ServiceManagerListenerStubDispatch::Accept(
        ServiceManagerListener* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kServiceManagerListener_OnInit_Name: {
            internal::ServiceManagerListener_OnInit_Params_Data* params = reinterpret_cast<internal::ServiceManagerListener_OnInit_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<RunningServiceInfoPtr> p_running_services {};
            ServiceManagerListener_OnInit_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadRunningServices(&p_running_services))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceManagerListener::OnInit deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceManagerListener::OnInit");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnInit(
                std::move(p_running_services));
            return true;
        }
        case internal::kServiceManagerListener_OnServiceCreated_Name: {
            internal::ServiceManagerListener_OnServiceCreated_Params_Data* params = reinterpret_cast<internal::ServiceManagerListener_OnServiceCreated_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RunningServiceInfoPtr p_service {};
            ServiceManagerListener_OnServiceCreated_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadService(&p_service))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceManagerListener::OnServiceCreated deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceManagerListener::OnServiceCreated");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnServiceCreated(
                std::move(p_service));
            return true;
        }
        case internal::kServiceManagerListener_OnServiceStarted_Name: {
            internal::ServiceManagerListener_OnServiceStarted_Params_Data* params = reinterpret_cast<internal::ServiceManagerListener_OnServiceStarted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::service_manager::Identity p_identity {};
            uint32_t p_pid {};
            ServiceManagerListener_OnServiceStarted_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadIdentity(&p_identity))
                success = false;
            p_pid = input_data_view.pid();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceManagerListener::OnServiceStarted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceManagerListener::OnServiceStarted");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnServiceStarted(
                std::move(p_identity),
                std::move(p_pid));
            return true;
        }
        case internal::kServiceManagerListener_OnServiceFailedToStart_Name: {
            internal::ServiceManagerListener_OnServiceFailedToStart_Params_Data* params = reinterpret_cast<internal::ServiceManagerListener_OnServiceFailedToStart_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::service_manager::Identity p_identity {};
            ServiceManagerListener_OnServiceFailedToStart_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadIdentity(&p_identity))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceManagerListener::OnServiceFailedToStart deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceManagerListener::OnServiceFailedToStart");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnServiceFailedToStart(
                std::move(p_identity));
            return true;
        }
        case internal::kServiceManagerListener_OnServiceStopped_Name: {
            internal::ServiceManagerListener_OnServiceStopped_Params_Data* params = reinterpret_cast<internal::ServiceManagerListener_OnServiceStopped_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::service_manager::Identity p_identity {};
            ServiceManagerListener_OnServiceStopped_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadIdentity(&p_identity))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceManagerListener::OnServiceStopped deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceManagerListener::OnServiceStopped");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnServiceStopped(
                std::move(p_identity));
            return true;
        }
        }
        return false;
    }

    // static
    bool ServiceManagerListenerStubDispatch::AcceptWithResponder(
        ServiceManagerListener* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kServiceManagerListener_OnInit_Name: {
            break;
        }
        case internal::kServiceManagerListener_OnServiceCreated_Name: {
            break;
        }
        case internal::kServiceManagerListener_OnServiceStarted_Name: {
            break;
        }
        case internal::kServiceManagerListener_OnServiceFailedToStart_Name: {
            break;
        }
        case internal::kServiceManagerListener_OnServiceStopped_Name: {
            break;
        }
        }
        return false;
    }

    bool ServiceManagerListenerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ServiceManagerListener RequestValidator");

        switch (message->header()->name) {
        case internal::kServiceManagerListener_OnInit_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceManagerListener_OnInit_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceManagerListener_OnServiceCreated_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceManagerListener_OnServiceCreated_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceManagerListener_OnServiceStarted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceManagerListener_OnServiceStarted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceManagerListener_OnServiceFailedToStart_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceManagerListener_OnServiceFailedToStart_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceManagerListener_OnServiceStopped_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceManagerListener_OnServiceStopped_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    const char ServiceManager::Name_[] = "service_manager::mojom::ServiceManager";

    ServiceManagerProxy::ServiceManagerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ServiceManagerProxy::AddListener(
        ServiceManagerListenerPtr in_listener)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::service_manager::mojom::internal::ServiceManager_AddListener_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kServiceManager_AddListener_Name, size);

        auto params = ::service_manager::mojom::internal::ServiceManager_AddListener_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::service_manager::mojom::ServiceManagerListenerPtrDataView>(
            in_listener, &params->listener, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->listener),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid listener in ServiceManager.AddListener request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool ServiceManagerStubDispatch::Accept(
        ServiceManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kServiceManager_AddListener_Name: {
            internal::ServiceManager_AddListener_Params_Data* params = reinterpret_cast<internal::ServiceManager_AddListener_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ServiceManagerListenerPtr p_listener {};
            ServiceManager_AddListener_ParamsDataView input_data_view(params,
                context);

            p_listener = input_data_view.TakeListener<decltype(p_listener)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceManager::AddListener deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceManager::AddListener");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddListener(
                std::move(p_listener));
            return true;
        }
        }
        return false;
    }

    // static
    bool ServiceManagerStubDispatch::AcceptWithResponder(
        ServiceManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kServiceManager_AddListener_Name: {
            break;
        }
        }
        return false;
    }

    bool ServiceManagerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ServiceManager RequestValidator");

        switch (message->header()->name) {
        case internal::kServiceManager_AddListener_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceManager_AddListener_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

} // namespace mojom
} // namespace service_manager

namespace mojo {

// static
bool StructTraits<::service_manager::mojom::RunningServiceInfo::DataView, ::service_manager::mojom::RunningServiceInfoPtr>::Read(
    ::service_manager::mojom::RunningServiceInfo::DataView input,
    ::service_manager::mojom::RunningServiceInfoPtr* output)
{
    bool success = true;
    ::service_manager::mojom::RunningServiceInfoPtr result(::service_manager::mojom::RunningServiceInfo::New());

    result->id = input.id();
    if (!input.ReadIdentity(&result->identity))
        success = false;
    result->pid = input.pid();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif