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

#include "services/service_manager/public/interfaces/service.mojom.h"

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
    ServiceInfoPtr ServiceInfo::New()
    {
        ServiceInfoPtr rv;
        mojo::internal::StructHelper<ServiceInfo>::Initialize(&rv);
        return rv;
    }

    ServiceInfo::ServiceInfo()
        : identity()
        , interface_provider_specs()
    {
    }

    ServiceInfo::~ServiceInfo()
    {
    }
    const char Service::Name_[] = "service_manager::mojom::Service";

    class Service_OnStart_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Service_OnStart_ForwardToCallback(
            const Service::OnStartCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Service::OnStartCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Service_OnStart_ForwardToCallback);
    };
    bool Service_OnStart_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Service_OnStart_ResponseParams_Data* params = reinterpret_cast<internal::Service_OnStart_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::service_manager::mojom::ConnectorRequest p_connector_request {};
        ::service_manager::mojom::ServiceControlAssociatedRequest p_control_request {};
        Service_OnStart_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_connector_request = input_data_view.TakeConnectorRequest<decltype(p_connector_request)>();
        p_control_request = input_data_view.TakeControlRequest<decltype(p_control_request)>();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Service::OnStart response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_connector_request),
                std::move(p_control_request));
        }
        return true;
    }

    class Service_OnConnect_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Service_OnConnect_ForwardToCallback(
            const Service::OnConnectCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Service::OnConnectCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Service_OnConnect_ForwardToCallback);
    };
    bool Service_OnConnect_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Service_OnConnect_ResponseParams_Data* params = reinterpret_cast<internal::Service_OnConnect_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        Service_OnConnect_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Service::OnConnect response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run();
        }
        return true;
    }

    class Service_OnBindInterface_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Service_OnBindInterface_ForwardToCallback(
            const Service::OnBindInterfaceCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Service::OnBindInterfaceCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Service_OnBindInterface_ForwardToCallback);
    };
    bool Service_OnBindInterface_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Service_OnBindInterface_ResponseParams_Data* params = reinterpret_cast<internal::Service_OnBindInterface_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        Service_OnBindInterface_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Service::OnBindInterface response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run();
        }
        return true;
    }

    ServiceProxy::ServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ServiceProxy::OnStart(
        const ::service_manager::ServiceInfo& in_info, const OnStartCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::service_manager::mojom::internal::Service_OnStart_Params_Data);
        size += mojo::internal::PrepareToSerialize<::service_manager::mojom::ServiceInfoDataView>(
            in_info, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kService_OnStart_Name, size);

        auto params = ::service_manager::mojom::internal::Service_OnStart_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->info)::BaseType* info_ptr;
        mojo::internal::Serialize<::service_manager::mojom::ServiceInfoDataView>(
            in_info, builder.buffer(), &info_ptr, &serialization_context);
        params->info.Set(info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null info in Service.OnStart request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Service_OnStart_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ServiceProxy::OnConnect(
        const ::service_manager::ServiceInfo& in_source_info, ::service_manager::mojom::InterfaceProviderRequest in_interfaces, const OnConnectCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::service_manager::mojom::internal::Service_OnConnect_Params_Data);
        size += mojo::internal::PrepareToSerialize<::service_manager::mojom::ServiceInfoDataView>(
            in_source_info, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kService_OnConnect_Name, size);

        auto params = ::service_manager::mojom::internal::Service_OnConnect_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->source_info)::BaseType* source_info_ptr;
        mojo::internal::Serialize<::service_manager::mojom::ServiceInfoDataView>(
            in_source_info, builder.buffer(), &source_info_ptr, &serialization_context);
        params->source_info.Set(source_info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->source_info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null source_info in Service.OnConnect request");
        mojo::internal::Serialize<::service_manager::mojom::InterfaceProviderRequestDataView>(
            in_interfaces, &params->interfaces, &serialization_context);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Service_OnConnect_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ServiceProxy::OnBindInterface(
        const ::service_manager::ServiceInfo& in_source_info, const std::string& in_interface_name, mojo::ScopedMessagePipeHandle in_interface_pipe, const OnBindInterfaceCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::service_manager::mojom::internal::Service_OnBindInterface_Params_Data);
        size += mojo::internal::PrepareToSerialize<::service_manager::mojom::ServiceInfoDataView>(
            in_source_info, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_interface_name, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kService_OnBindInterface_Name, size);

        auto params = ::service_manager::mojom::internal::Service_OnBindInterface_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->source_info)::BaseType* source_info_ptr;
        mojo::internal::Serialize<::service_manager::mojom::ServiceInfoDataView>(
            in_source_info, builder.buffer(), &source_info_ptr, &serialization_context);
        params->source_info.Set(source_info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->source_info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null source_info in Service.OnBindInterface request");
        typename decltype(params->interface_name)::BaseType* interface_name_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_interface_name, builder.buffer(), &interface_name_ptr, &serialization_context);
        params->interface_name.Set(interface_name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->interface_name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null interface_name in Service.OnBindInterface request");
        mojo::internal::Serialize<mojo::ScopedMessagePipeHandle>(
            in_interface_pipe, &params->interface_pipe, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->interface_pipe),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid interface_pipe in Service.OnBindInterface request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Service_OnBindInterface_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class Service_OnStart_ProxyToResponder {
    public:
        static Service::OnStartCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Service_OnStart_ProxyToResponder> proxy(
                new Service_OnStart_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Service_OnStart_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Service_OnStart_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Service::OnStart() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Service_OnStart_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            ::service_manager::mojom::ConnectorRequest in_connector_request, ::service_manager::mojom::ServiceControlAssociatedRequest in_control_request);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Service_OnStart_ProxyToResponder);
    };

    void Service_OnStart_ProxyToResponder::Run(
        ::service_manager::mojom::ConnectorRequest in_connector_request, ::service_manager::mojom::ServiceControlAssociatedRequest in_control_request)
    {
        size_t size = sizeof(::service_manager::mojom::internal::Service_OnStart_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kService_OnStart_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::service_manager::mojom::internal::Service_OnStart_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::service_manager::mojom::ConnectorRequestDataView>(
            in_connector_request, &params->connector_request, &serialization_context_);
        mojo::internal::Serialize<::service_manager::mojom::ServiceControlAssociatedRequestDataView>(
            in_control_request, &params->control_request, &serialization_context_);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Service_OnConnect_ProxyToResponder {
    public:
        static Service::OnConnectCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Service_OnConnect_ProxyToResponder> proxy(
                new Service_OnConnect_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Service_OnConnect_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Service_OnConnect_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Service::OnConnect() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Service_OnConnect_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run();

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Service_OnConnect_ProxyToResponder);
    };

    void Service_OnConnect_ProxyToResponder::Run()
    {
        size_t size = sizeof(::service_manager::mojom::internal::Service_OnConnect_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kService_OnConnect_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::service_manager::mojom::internal::Service_OnConnect_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Service_OnBindInterface_ProxyToResponder {
    public:
        static Service::OnBindInterfaceCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Service_OnBindInterface_ProxyToResponder> proxy(
                new Service_OnBindInterface_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Service_OnBindInterface_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Service_OnBindInterface_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Service::OnBindInterface() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Service_OnBindInterface_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run();

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Service_OnBindInterface_ProxyToResponder);
    };

    void Service_OnBindInterface_ProxyToResponder::Run()
    {
        size_t size = sizeof(::service_manager::mojom::internal::Service_OnBindInterface_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kService_OnBindInterface_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::service_manager::mojom::internal::Service_OnBindInterface_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }

    // static
    bool ServiceStubDispatch::Accept(
        Service* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kService_OnStart_Name: {
            break;
        }
        case internal::kService_OnConnect_Name: {
            break;
        }
        case internal::kService_OnBindInterface_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool ServiceStubDispatch::AcceptWithResponder(
        Service* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kService_OnStart_Name: {
            internal::Service_OnStart_Params_Data* params = reinterpret_cast<internal::Service_OnStart_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::service_manager::ServiceInfo p_info {};
            Service_OnStart_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadInfo(&p_info))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Service::OnStart deserializer");
                return false;
            }
            Service::OnStartCallback callback = Service_OnStart_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Service::OnStart");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnStart(
                std::move(p_info), std::move(callback));
            return true;
        }
        case internal::kService_OnConnect_Name: {
            internal::Service_OnConnect_Params_Data* params = reinterpret_cast<internal::Service_OnConnect_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::service_manager::ServiceInfo p_source_info {};
            ::service_manager::mojom::InterfaceProviderRequest p_interfaces {};
            Service_OnConnect_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSourceInfo(&p_source_info))
                success = false;
            p_interfaces = input_data_view.TakeInterfaces<decltype(p_interfaces)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Service::OnConnect deserializer");
                return false;
            }
            Service::OnConnectCallback callback = Service_OnConnect_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Service::OnConnect");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnConnect(
                std::move(p_source_info),
                std::move(p_interfaces), std::move(callback));
            return true;
        }
        case internal::kService_OnBindInterface_Name: {
            internal::Service_OnBindInterface_Params_Data* params = reinterpret_cast<internal::Service_OnBindInterface_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::service_manager::ServiceInfo p_source_info {};
            std::string p_interface_name {};
            mojo::ScopedMessagePipeHandle p_interface_pipe {};
            Service_OnBindInterface_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSourceInfo(&p_source_info))
                success = false;
            if (!input_data_view.ReadInterfaceName(&p_interface_name))
                success = false;
            p_interface_pipe = input_data_view.TakeInterfacePipe();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Service::OnBindInterface deserializer");
                return false;
            }
            Service::OnBindInterfaceCallback callback = Service_OnBindInterface_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Service::OnBindInterface");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnBindInterface(
                std::move(p_source_info),
                std::move(p_interface_name),
                std::move(p_interface_pipe), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool ServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Service RequestValidator");

        switch (message->header()->name) {
        case internal::kService_OnStart_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Service_OnStart_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kService_OnConnect_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Service_OnConnect_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kService_OnBindInterface_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Service_OnBindInterface_Params_Data>(
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

    bool ServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Service ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kService_OnStart_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Service_OnStart_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kService_OnConnect_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Service_OnConnect_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kService_OnBindInterface_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Service_OnBindInterface_ResponseParams_Data>(
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
bool StructTraits<::service_manager::mojom::ServiceInfo::DataView, ::service_manager::mojom::ServiceInfoPtr>::Read(
    ::service_manager::mojom::ServiceInfo::DataView input,
    ::service_manager::mojom::ServiceInfoPtr* output)
{
    bool success = true;
    ::service_manager::mojom::ServiceInfoPtr result(::service_manager::mojom::ServiceInfo::New());

    if (!input.ReadIdentity(&result->identity))
        success = false;
    if (!input.ReadInterfaceProviderSpecs(&result->interface_provider_specs))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif