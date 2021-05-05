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

#include "services/service_manager/public/interfaces/connector.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
namespace service_manager {
namespace mojom {
    namespace blink {
        const char kRootUserID[] = "505C0EE9-3013-43C0-82B0-A84F50CF8D84";
        const char kInheritUserID[] = "D26290E4-4485-4EAE-81A2-66D1EEB40A9D"; // static
        IdentityPtr Identity::New()
        {
            IdentityPtr rv;
            mojo::internal::StructHelper<Identity>::Initialize(&rv);
            return rv;
        }

        Identity::Identity()
            : name()
            , user_id()
            , instance()
        {
        }

        Identity::~Identity()
        {
        }
        size_t Identity::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->name);
            seed = mojo::internal::WTFHash(seed, this->user_id);
            seed = mojo::internal::WTFHash(seed, this->instance);
            return seed;
        }
        const char PIDReceiver::Name_[] = "service_manager::mojom::PIDReceiver";

        PIDReceiverProxy::PIDReceiverProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void PIDReceiverProxy::SetPID(
            uint32_t in_pid)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::service_manager::mojom::internal::PIDReceiver_SetPID_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kPIDReceiver_SetPID_Name, size);

            auto params = ::service_manager::mojom::internal::PIDReceiver_SetPID_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->pid = in_pid;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool PIDReceiverStubDispatch::Accept(
            PIDReceiver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kPIDReceiver_SetPID_Name: {
                internal::PIDReceiver_SetPID_Params_Data* params = reinterpret_cast<internal::PIDReceiver_SetPID_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint32_t p_pid {};
                PIDReceiver_SetPID_ParamsDataView input_data_view(params,
                    context);

                p_pid = input_data_view.pid();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "PIDReceiver::SetPID deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "PIDReceiver::SetPID");
                mojo::internal::MessageDispatchContext context(message);
                impl->SetPID(
                    std::move(p_pid));
                return true;
            }
            }
            return false;
        }

        // static
        bool PIDReceiverStubDispatch::AcceptWithResponder(
            PIDReceiver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kPIDReceiver_SetPID_Name: {
                break;
            }
            }
            return false;
        }

        bool PIDReceiverRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "PIDReceiver RequestValidator");

            switch (message->header()->name) {
            case internal::kPIDReceiver_SetPID_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::PIDReceiver_SetPID_Params_Data>(
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

        const char Connector::Name_[] = "service_manager::mojom::Connector";

        class Connector_Connect_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Connector_Connect_ForwardToCallback(
                const Connector::ConnectCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Connector::ConnectCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Connector_Connect_ForwardToCallback);
        };
        bool Connector_Connect_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Connector_Connect_ResponseParams_Data* params = reinterpret_cast<internal::Connector_Connect_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ConnectResult p_result {};
            WTF::String p_user_id {};
            Connector_Connect_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!input_data_view.ReadUserId(&p_user_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Connector::Connect response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result),
                    std::move(p_user_id));
            }
            return true;
        }

        class Connector_BindInterface_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            Connector_BindInterface_ForwardToCallback(
                const Connector::BindInterfaceCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            Connector::BindInterfaceCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(Connector_BindInterface_ForwardToCallback);
        };
        bool Connector_BindInterface_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::Connector_BindInterface_ResponseParams_Data* params = reinterpret_cast<internal::Connector_BindInterface_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ConnectResult p_result {};
            WTF::String p_user_id {};
            Connector_BindInterface_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!input_data_view.ReadUserId(&p_user_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Connector::BindInterface response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result),
                    std::move(p_user_id));
            }
            return true;
        }

        ConnectorProxy::ConnectorProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void ConnectorProxy::StartService(
            IdentityPtr in_name, mojo::ScopedMessagePipeHandle in_service, PIDReceiverRequest in_pid_receiver_request)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::service_manager::mojom::internal::Connector_StartService_Params_Data);
            size += mojo::internal::PrepareToSerialize<::service_manager::mojom::IdentityDataView>(
                in_name, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kConnector_StartService_Name, size);

            auto params = ::service_manager::mojom::internal::Connector_StartService_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->name)::BaseType* name_ptr;
            mojo::internal::Serialize<::service_manager::mojom::IdentityDataView>(
                in_name, builder.buffer(), &name_ptr, &serialization_context);
            params->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in Connector.StartService request");
            mojo::internal::Serialize<mojo::ScopedMessagePipeHandle>(
                in_service, &params->service, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->service),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid service in Connector.StartService request");
            mojo::internal::Serialize<::service_manager::mojom::PIDReceiverRequestDataView>(
                in_pid_receiver_request, &params->pid_receiver_request, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->pid_receiver_request),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid pid_receiver_request in Connector.StartService request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void ConnectorProxy::Connect(
            IdentityPtr in_target, ::service_manager::mojom::blink::InterfaceProviderRequest in_remote_interfaces, const ConnectCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::service_manager::mojom::internal::Connector_Connect_Params_Data);
            size += mojo::internal::PrepareToSerialize<::service_manager::mojom::IdentityDataView>(
                in_target, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kConnector_Connect_Name, size);

            auto params = ::service_manager::mojom::internal::Connector_Connect_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->target)::BaseType* target_ptr;
            mojo::internal::Serialize<::service_manager::mojom::IdentityDataView>(
                in_target, builder.buffer(), &target_ptr, &serialization_context);
            params->target.Set(target_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->target.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null target in Connector.Connect request");
            mojo::internal::Serialize<::service_manager::mojom::InterfaceProviderRequestDataView>(
                in_remote_interfaces, &params->remote_interfaces, &serialization_context);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Connector_Connect_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void ConnectorProxy::BindInterface(
            IdentityPtr in_target, const WTF::String& in_interface_name, mojo::ScopedMessagePipeHandle in_interface_pipe, const BindInterfaceCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::service_manager::mojom::internal::Connector_BindInterface_Params_Data);
            size += mojo::internal::PrepareToSerialize<::service_manager::mojom::IdentityDataView>(
                in_target, &serialization_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_interface_name, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kConnector_BindInterface_Name, size);

            auto params = ::service_manager::mojom::internal::Connector_BindInterface_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->target)::BaseType* target_ptr;
            mojo::internal::Serialize<::service_manager::mojom::IdentityDataView>(
                in_target, builder.buffer(), &target_ptr, &serialization_context);
            params->target.Set(target_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->target.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null target in Connector.BindInterface request");
            typename decltype(params->interface_name)::BaseType* interface_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_interface_name, builder.buffer(), &interface_name_ptr, &serialization_context);
            params->interface_name.Set(interface_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->interface_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null interface_name in Connector.BindInterface request");
            mojo::internal::Serialize<mojo::ScopedMessagePipeHandle>(
                in_interface_pipe, &params->interface_pipe, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->interface_pipe),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid interface_pipe in Connector.BindInterface request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new Connector_BindInterface_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }

        void ConnectorProxy::Clone(
            ConnectorRequest in_request)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::service_manager::mojom::internal::Connector_Clone_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kConnector_Clone_Name, size);

            auto params = ::service_manager::mojom::internal::Connector_Clone_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::service_manager::mojom::ConnectorRequestDataView>(
                in_request, &params->request, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->request),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid request in Connector.Clone request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }
        class Connector_Connect_ProxyToResponder {
        public:
            static Connector::ConnectCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Connector_Connect_ProxyToResponder> proxy(
                    new Connector_Connect_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Connector_Connect_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Connector_Connect_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Connector::Connect() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Connector_Connect_ProxyToResponder(
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
                ConnectResult in_result, const WTF::String& in_user_id);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Connector_Connect_ProxyToResponder);
        };

        void Connector_Connect_ProxyToResponder::Run(
            ConnectResult in_result, const WTF::String& in_user_id)
        {
            size_t size = sizeof(::service_manager::mojom::internal::Connector_Connect_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_user_id, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kConnector_Connect_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::service_manager::mojom::internal::Connector_Connect_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::service_manager::mojom::ConnectResult>(
                in_result, &params->result);
            typename decltype(params->user_id)::BaseType* user_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_user_id, builder.buffer(), &user_id_ptr, &serialization_context_);
            params->user_id.Set(user_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->user_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null user_id in Connector.Connect response");
            (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
            bool ok = responder_->Accept(builder.message());
            ALLOW_UNUSED_LOCAL(ok);
            // TODO(darin): !ok returned here indicates a malformed message, and that may
            // be good reason to close the connection. However, we don't have a way to do
            // that from here. We should add a way.
            delete responder_;
            responder_ = nullptr;
        }
        class Connector_BindInterface_ProxyToResponder {
        public:
            static Connector::BindInterfaceCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<Connector_BindInterface_ProxyToResponder> proxy(
                    new Connector_BindInterface_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&Connector_BindInterface_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~Connector_BindInterface_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "Connector::BindInterface() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            Connector_BindInterface_ProxyToResponder(
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
                ConnectResult in_result, const WTF::String& in_user_id);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(Connector_BindInterface_ProxyToResponder);
        };

        void Connector_BindInterface_ProxyToResponder::Run(
            ConnectResult in_result, const WTF::String& in_user_id)
        {
            size_t size = sizeof(::service_manager::mojom::internal::Connector_BindInterface_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_user_id, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kConnector_BindInterface_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::service_manager::mojom::internal::Connector_BindInterface_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::service_manager::mojom::ConnectResult>(
                in_result, &params->result);
            typename decltype(params->user_id)::BaseType* user_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_user_id, builder.buffer(), &user_id_ptr, &serialization_context_);
            params->user_id.Set(user_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->user_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null user_id in Connector.BindInterface response");
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
        bool ConnectorStubDispatch::Accept(
            Connector* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kConnector_StartService_Name: {
                internal::Connector_StartService_Params_Data* params = reinterpret_cast<internal::Connector_StartService_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                IdentityPtr p_name {};
                mojo::ScopedMessagePipeHandle p_service {};
                PIDReceiverRequest p_pid_receiver_request {};
                Connector_StartService_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadName(&p_name))
                    success = false;
                p_service = input_data_view.TakeService();
                p_pid_receiver_request = input_data_view.TakePidReceiverRequest<decltype(p_pid_receiver_request)>();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Connector::StartService deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Connector::StartService");
                mojo::internal::MessageDispatchContext context(message);
                impl->StartService(
                    std::move(p_name),
                    std::move(p_service),
                    std::move(p_pid_receiver_request));
                return true;
            }
            case internal::kConnector_Connect_Name: {
                break;
            }
            case internal::kConnector_BindInterface_Name: {
                break;
            }
            case internal::kConnector_Clone_Name: {
                internal::Connector_Clone_Params_Data* params = reinterpret_cast<internal::Connector_Clone_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                ConnectorRequest p_request {};
                Connector_Clone_ParamsDataView input_data_view(params,
                    context);

                p_request = input_data_view.TakeRequest<decltype(p_request)>();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Connector::Clone deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Connector::Clone");
                mojo::internal::MessageDispatchContext context(message);
                impl->Clone(
                    std::move(p_request));
                return true;
            }
            }
            return false;
        }

        // static
        bool ConnectorStubDispatch::AcceptWithResponder(
            Connector* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kConnector_StartService_Name: {
                break;
            }
            case internal::kConnector_Connect_Name: {
                internal::Connector_Connect_Params_Data* params = reinterpret_cast<internal::Connector_Connect_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                IdentityPtr p_target {};
                ::service_manager::mojom::blink::InterfaceProviderRequest p_remote_interfaces {};
                Connector_Connect_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadTarget(&p_target))
                    success = false;
                p_remote_interfaces = input_data_view.TakeRemoteInterfaces<decltype(p_remote_interfaces)>();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Connector::Connect deserializer");
                    return false;
                }
                Connector::ConnectCallback callback = Connector_Connect_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Connector::Connect");
                mojo::internal::MessageDispatchContext context(message);
                impl->Connect(
                    std::move(p_target),
                    std::move(p_remote_interfaces), std::move(callback));
                return true;
            }
            case internal::kConnector_BindInterface_Name: {
                internal::Connector_BindInterface_Params_Data* params = reinterpret_cast<internal::Connector_BindInterface_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                IdentityPtr p_target {};
                WTF::String p_interface_name {};
                mojo::ScopedMessagePipeHandle p_interface_pipe {};
                Connector_BindInterface_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadTarget(&p_target))
                    success = false;
                if (!input_data_view.ReadInterfaceName(&p_interface_name))
                    success = false;
                p_interface_pipe = input_data_view.TakeInterfacePipe();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "Connector::BindInterface deserializer");
                    return false;
                }
                Connector::BindInterfaceCallback callback = Connector_BindInterface_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "Connector::BindInterface");
                mojo::internal::MessageDispatchContext context(message);
                impl->BindInterface(
                    std::move(p_target),
                    std::move(p_interface_name),
                    std::move(p_interface_pipe), std::move(callback));
                return true;
            }
            case internal::kConnector_Clone_Name: {
                break;
            }
            }
            return false;
        }

        bool ConnectorRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Connector RequestValidator");

            switch (message->header()->name) {
            case internal::kConnector_StartService_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Connector_StartService_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kConnector_Connect_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Connector_Connect_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kConnector_BindInterface_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Connector_BindInterface_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kConnector_Clone_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Connector_Clone_Params_Data>(
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

        bool ConnectorResponseValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "Connector ResponseValidator");

            if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
                return false;
            switch (message->header()->name) {
            case internal::kConnector_Connect_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Connector_Connect_ResponseParams_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kConnector_BindInterface_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::Connector_BindInterface_ResponseParams_Data>(
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
    } // namespace blink
} // namespace mojom
} // namespace service_manager

namespace mojo {

// static
bool StructTraits<::service_manager::mojom::blink::Identity::DataView, ::service_manager::mojom::blink::IdentityPtr>::Read(
    ::service_manager::mojom::blink::Identity::DataView input,
    ::service_manager::mojom::blink::IdentityPtr* output)
{
    bool success = true;
    ::service_manager::mojom::blink::IdentityPtr result(::service_manager::mojom::blink::Identity::New());

    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadUserId(&result->user_id))
        success = false;
    if (!input.ReadInstance(&result->instance))
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