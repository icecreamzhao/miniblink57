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

#include "third_party/WebKit/public/platform/modules/presentation/presentation.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "content/common/bluetooth/web_bluetooth_device_id_struct_traits.h"
#include "content/common/media/media_session_struct_traits.h"
#include "content/public/common/referrer_struct_traits.h"
#include "device/bluetooth/public/interfaces/uuid_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace blink {
namespace mojom { // static
    PresentationSessionInfoPtr PresentationSessionInfo::New()
    {
        PresentationSessionInfoPtr rv;
        mojo::internal::StructHelper<PresentationSessionInfo>::Initialize(&rv);
        return rv;
    }

    PresentationSessionInfo::PresentationSessionInfo()
        : url()
        , id()
    {
    }

    PresentationSessionInfo::~PresentationSessionInfo()
    {
    } // static
    PresentationErrorPtr PresentationError::New()
    {
        PresentationErrorPtr rv;
        mojo::internal::StructHelper<PresentationError>::Initialize(&rv);
        return rv;
    }

    PresentationError::PresentationError()
        : error_type()
        , message()
    {
    }

    PresentationError::~PresentationError()
    {
    }
    size_t PresentationError::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->error_type);
        seed = mojo::internal::Hash(seed, this->message);
        return seed;
    } // static
    ConnectionMessagePtr ConnectionMessage::New()
    {
        ConnectionMessagePtr rv;
        mojo::internal::StructHelper<ConnectionMessage>::Initialize(&rv);
        return rv;
    }

    ConnectionMessage::ConnectionMessage()
        : type()
        , message()
        , data()
    {
    }

    ConnectionMessage::~ConnectionMessage()
    {
    }
    const char PresentationConnection::Name_[] = "blink::mojom::PresentationConnection";

    class PresentationConnection_OnMessage_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PresentationConnection_OnMessage_ForwardToCallback(
            const PresentationConnection::OnMessageCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PresentationConnection::OnMessageCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PresentationConnection_OnMessage_ForwardToCallback);
    };
    bool PresentationConnection_OnMessage_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PresentationConnection_OnMessage_ResponseParams_Data* params = reinterpret_cast<internal::PresentationConnection_OnMessage_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        PresentationConnection_OnMessage_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PresentationConnection::OnMessage response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    PresentationConnectionProxy::PresentationConnectionProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PresentationConnectionProxy::OnMessage(
        ConnectionMessagePtr in_message, const OnMessageCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationConnection_OnMessage_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::ConnectionMessageDataView>(
            in_message, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kPresentationConnection_OnMessage_Name, size);

        auto params = ::blink::mojom::internal::PresentationConnection_OnMessage_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->message)::BaseType* message_ptr;
        mojo::internal::Serialize<::blink::mojom::ConnectionMessageDataView>(
            in_message, builder.buffer(), &message_ptr, &serialization_context);
        params->message.Set(message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message in PresentationConnection.OnMessage request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PresentationConnection_OnMessage_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void PresentationConnectionProxy::DidChangeState(
        PresentationConnectionState in_state)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationConnection_DidChangeState_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPresentationConnection_DidChangeState_Name, size);

        auto params = ::blink::mojom::internal::PresentationConnection_DidChangeState_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::PresentationConnectionState>(
            in_state, &params->state);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class PresentationConnection_OnMessage_ProxyToResponder {
    public:
        static PresentationConnection::OnMessageCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PresentationConnection_OnMessage_ProxyToResponder> proxy(
                new PresentationConnection_OnMessage_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PresentationConnection_OnMessage_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PresentationConnection_OnMessage_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PresentationConnection::OnMessage() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PresentationConnection_OnMessage_ProxyToResponder(
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
            bool in_success);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PresentationConnection_OnMessage_ProxyToResponder);
    };

    void PresentationConnection_OnMessage_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::blink::mojom::internal::PresentationConnection_OnMessage_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPresentationConnection_OnMessage_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::PresentationConnection_OnMessage_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
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
    bool PresentationConnectionStubDispatch::Accept(
        PresentationConnection* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPresentationConnection_OnMessage_Name: {
            break;
        }
        case internal::kPresentationConnection_DidChangeState_Name: {
            internal::PresentationConnection_DidChangeState_Params_Data* params = reinterpret_cast<internal::PresentationConnection_DidChangeState_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationConnectionState p_state {};
            PresentationConnection_DidChangeState_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadState(&p_state))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationConnection::DidChangeState deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationConnection::DidChangeState");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidChangeState(
                std::move(p_state));
            return true;
        }
        }
        return false;
    }

    // static
    bool PresentationConnectionStubDispatch::AcceptWithResponder(
        PresentationConnection* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPresentationConnection_OnMessage_Name: {
            internal::PresentationConnection_OnMessage_Params_Data* params = reinterpret_cast<internal::PresentationConnection_OnMessage_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ConnectionMessagePtr p_message {};
            PresentationConnection_OnMessage_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadMessage(&p_message))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationConnection::OnMessage deserializer");
                return false;
            }
            PresentationConnection::OnMessageCallback callback = PresentationConnection_OnMessage_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationConnection::OnMessage");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnMessage(
                std::move(p_message), std::move(callback));
            return true;
        }
        case internal::kPresentationConnection_DidChangeState_Name: {
            break;
        }
        }
        return false;
    }

    bool PresentationConnectionRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PresentationConnection RequestValidator");

        switch (message->header()->name) {
        case internal::kPresentationConnection_OnMessage_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationConnection_OnMessage_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationConnection_DidChangeState_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationConnection_DidChangeState_Params_Data>(
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

    bool PresentationConnectionResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PresentationConnection ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kPresentationConnection_OnMessage_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationConnection_OnMessage_ResponseParams_Data>(
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
    const char PresentationService::Name_[] = "blink::mojom::PresentationService";

    class PresentationService_StartSession_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PresentationService_StartSession_ForwardToCallback(
            const PresentationService::StartSessionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PresentationService::StartSessionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PresentationService_StartSession_ForwardToCallback);
    };
    bool PresentationService_StartSession_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PresentationService_StartSession_ResponseParams_Data* params = reinterpret_cast<internal::PresentationService_StartSession_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        PresentationSessionInfoPtr p_sessionInfo {};
        PresentationErrorPtr p_error {};
        PresentationService_StartSession_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadSessioninfo(&p_sessionInfo))
            success = false;
        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PresentationService::StartSession response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_sessionInfo),
                std::move(p_error));
        }
        return true;
    }

    class PresentationService_JoinSession_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PresentationService_JoinSession_ForwardToCallback(
            const PresentationService::JoinSessionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PresentationService::JoinSessionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PresentationService_JoinSession_ForwardToCallback);
    };
    bool PresentationService_JoinSession_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PresentationService_JoinSession_ResponseParams_Data* params = reinterpret_cast<internal::PresentationService_JoinSession_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        PresentationSessionInfoPtr p_sessionInfo {};
        PresentationErrorPtr p_error {};
        PresentationService_JoinSession_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadSessioninfo(&p_sessionInfo))
            success = false;
        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PresentationService::JoinSession response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_sessionInfo),
                std::move(p_error));
        }
        return true;
    }

    class PresentationService_SendConnectionMessage_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PresentationService_SendConnectionMessage_ForwardToCallback(
            const PresentationService::SendConnectionMessageCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PresentationService::SendConnectionMessageCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PresentationService_SendConnectionMessage_ForwardToCallback);
    };
    bool PresentationService_SendConnectionMessage_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PresentationService_SendConnectionMessage_ResponseParams_Data* params = reinterpret_cast<internal::PresentationService_SendConnectionMessage_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        PresentationService_SendConnectionMessage_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PresentationService::SendConnectionMessage response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    PresentationServiceProxy::PresentationServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PresentationServiceProxy::SetClient(
        PresentationServiceClientPtr in_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_SetClient_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPresentationService_SetClient_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_SetClient_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::PresentationServiceClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in PresentationService.SetClient request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceProxy::SetDefaultPresentationUrls(
        const std::vector<GURL>& in_presentation_urls)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_SetDefaultPresentationUrls_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::url::mojom::UrlDataView>>(
            in_presentation_urls, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationService_SetDefaultPresentationUrls_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_SetDefaultPresentationUrls_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->presentation_urls)::BaseType* presentation_urls_ptr;
        const mojo::internal::ContainerValidateParams presentation_urls_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::url::mojom::UrlDataView>>(
            in_presentation_urls, builder.buffer(), &presentation_urls_ptr, &presentation_urls_validate_params,
            &serialization_context);
        params->presentation_urls.Set(presentation_urls_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->presentation_urls.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null presentation_urls in PresentationService.SetDefaultPresentationUrls request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceProxy::ListenForScreenAvailability(
        const GURL& in_availability_url)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_ListenForScreenAvailability_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_availability_url, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationService_ListenForScreenAvailability_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_ListenForScreenAvailability_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->availability_url)::BaseType* availability_url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_availability_url, builder.buffer(), &availability_url_ptr, &serialization_context);
        params->availability_url.Set(availability_url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->availability_url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null availability_url in PresentationService.ListenForScreenAvailability request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceProxy::StopListeningForScreenAvailability(
        const GURL& in_availability_url)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_StopListeningForScreenAvailability_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_availability_url, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationService_StopListeningForScreenAvailability_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_StopListeningForScreenAvailability_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->availability_url)::BaseType* availability_url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_availability_url, builder.buffer(), &availability_url_ptr, &serialization_context);
        params->availability_url.Set(availability_url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->availability_url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null availability_url in PresentationService.StopListeningForScreenAvailability request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceProxy::StartSession(
        const std::vector<GURL>& in_presentation_urls, const StartSessionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_StartSession_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::url::mojom::UrlDataView>>(
            in_presentation_urls, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kPresentationService_StartSession_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_StartSession_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->presentation_urls)::BaseType* presentation_urls_ptr;
        const mojo::internal::ContainerValidateParams presentation_urls_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::url::mojom::UrlDataView>>(
            in_presentation_urls, builder.buffer(), &presentation_urls_ptr, &presentation_urls_validate_params,
            &serialization_context);
        params->presentation_urls.Set(presentation_urls_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->presentation_urls.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null presentation_urls in PresentationService.StartSession request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PresentationService_StartSession_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void PresentationServiceProxy::JoinSession(
        const std::vector<GURL>& in_presentation_urls, const base::Optional<std::string>& in_presentation_id, const JoinSessionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_JoinSession_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::url::mojom::UrlDataView>>(
            in_presentation_urls, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_presentation_id, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kPresentationService_JoinSession_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_JoinSession_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->presentation_urls)::BaseType* presentation_urls_ptr;
        const mojo::internal::ContainerValidateParams presentation_urls_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::url::mojom::UrlDataView>>(
            in_presentation_urls, builder.buffer(), &presentation_urls_ptr, &presentation_urls_validate_params,
            &serialization_context);
        params->presentation_urls.Set(presentation_urls_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->presentation_urls.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null presentation_urls in PresentationService.JoinSession request");
        typename decltype(params->presentation_id)::BaseType* presentation_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_presentation_id, builder.buffer(), &presentation_id_ptr, &serialization_context);
        params->presentation_id.Set(presentation_id_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PresentationService_JoinSession_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void PresentationServiceProxy::SetPresentationConnection(
        PresentationSessionInfoPtr in_sessionInfo, PresentationConnectionPtr in_controller_connection_ptr, PresentationConnectionRequest in_receiver_connection_request)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_SetPresentationConnection_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationService_SetPresentationConnection_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_SetPresentationConnection_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->sessionInfo)::BaseType* sessionInfo_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, builder.buffer(), &sessionInfo_ptr, &serialization_context);
        params->sessionInfo.Set(sessionInfo_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->sessionInfo.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null sessionInfo in PresentationService.SetPresentationConnection request");
        mojo::internal::Serialize<::blink::mojom::PresentationConnectionPtrDataView>(
            in_controller_connection_ptr, &params->controller_connection_ptr, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->controller_connection_ptr),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid controller_connection_ptr in PresentationService.SetPresentationConnection request");
        mojo::internal::Serialize<::blink::mojom::PresentationConnectionRequestDataView>(
            in_receiver_connection_request, &params->receiver_connection_request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->receiver_connection_request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid receiver_connection_request in PresentationService.SetPresentationConnection request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceProxy::SendConnectionMessage(
        PresentationSessionInfoPtr in_sessionInfo, ConnectionMessagePtr in_message_request, const SendConnectionMessageCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_SendConnectionMessage_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::ConnectionMessageDataView>(
            in_message_request, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kPresentationService_SendConnectionMessage_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_SendConnectionMessage_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->sessionInfo)::BaseType* sessionInfo_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, builder.buffer(), &sessionInfo_ptr, &serialization_context);
        params->sessionInfo.Set(sessionInfo_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->sessionInfo.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null sessionInfo in PresentationService.SendConnectionMessage request");
        typename decltype(params->message_request)::BaseType* message_request_ptr;
        mojo::internal::Serialize<::blink::mojom::ConnectionMessageDataView>(
            in_message_request, builder.buffer(), &message_request_ptr, &serialization_context);
        params->message_request.Set(message_request_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message_request.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message_request in PresentationService.SendConnectionMessage request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PresentationService_SendConnectionMessage_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void PresentationServiceProxy::CloseConnection(
        const GURL& in_presentation_url, const std::string& in_presentation_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_CloseConnection_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_presentation_url, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_presentation_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationService_CloseConnection_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_CloseConnection_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->presentation_url)::BaseType* presentation_url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_presentation_url, builder.buffer(), &presentation_url_ptr, &serialization_context);
        params->presentation_url.Set(presentation_url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->presentation_url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null presentation_url in PresentationService.CloseConnection request");
        typename decltype(params->presentation_id)::BaseType* presentation_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_presentation_id, builder.buffer(), &presentation_id_ptr, &serialization_context);
        params->presentation_id.Set(presentation_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->presentation_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null presentation_id in PresentationService.CloseConnection request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceProxy::Terminate(
        const GURL& in_presentation_url, const std::string& in_presentation_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_Terminate_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_presentation_url, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_presentation_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationService_Terminate_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_Terminate_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->presentation_url)::BaseType* presentation_url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_presentation_url, builder.buffer(), &presentation_url_ptr, &serialization_context);
        params->presentation_url.Set(presentation_url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->presentation_url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null presentation_url in PresentationService.Terminate request");
        typename decltype(params->presentation_id)::BaseType* presentation_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_presentation_id, builder.buffer(), &presentation_id_ptr, &serialization_context);
        params->presentation_id.Set(presentation_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->presentation_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null presentation_id in PresentationService.Terminate request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceProxy::ListenForConnectionMessages(
        PresentationSessionInfoPtr in_sessionInfo)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationService_ListenForConnectionMessages_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationService_ListenForConnectionMessages_Name, size);

        auto params = ::blink::mojom::internal::PresentationService_ListenForConnectionMessages_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->sessionInfo)::BaseType* sessionInfo_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, builder.buffer(), &sessionInfo_ptr, &serialization_context);
        params->sessionInfo.Set(sessionInfo_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->sessionInfo.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null sessionInfo in PresentationService.ListenForConnectionMessages request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class PresentationService_StartSession_ProxyToResponder {
    public:
        static PresentationService::StartSessionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PresentationService_StartSession_ProxyToResponder> proxy(
                new PresentationService_StartSession_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PresentationService_StartSession_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PresentationService_StartSession_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PresentationService::StartSession() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PresentationService_StartSession_ProxyToResponder(
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
            PresentationSessionInfoPtr in_sessionInfo, PresentationErrorPtr in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PresentationService_StartSession_ProxyToResponder);
    };

    void PresentationService_StartSession_ProxyToResponder::Run(
        PresentationSessionInfoPtr in_sessionInfo, PresentationErrorPtr in_error)
    {
        size_t size = sizeof(::blink::mojom::internal::PresentationService_StartSession_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationErrorDataView>(
            in_error, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPresentationService_StartSession_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::PresentationService_StartSession_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->sessionInfo)::BaseType* sessionInfo_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, builder.buffer(), &sessionInfo_ptr, &serialization_context_);
        params->sessionInfo.Set(sessionInfo_ptr);
        typename decltype(params->error)::BaseType* error_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationErrorDataView>(
            in_error, builder.buffer(), &error_ptr, &serialization_context_);
        params->error.Set(error_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class PresentationService_JoinSession_ProxyToResponder {
    public:
        static PresentationService::JoinSessionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PresentationService_JoinSession_ProxyToResponder> proxy(
                new PresentationService_JoinSession_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PresentationService_JoinSession_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PresentationService_JoinSession_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PresentationService::JoinSession() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PresentationService_JoinSession_ProxyToResponder(
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
            PresentationSessionInfoPtr in_sessionInfo, PresentationErrorPtr in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PresentationService_JoinSession_ProxyToResponder);
    };

    void PresentationService_JoinSession_ProxyToResponder::Run(
        PresentationSessionInfoPtr in_sessionInfo, PresentationErrorPtr in_error)
    {
        size_t size = sizeof(::blink::mojom::internal::PresentationService_JoinSession_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationErrorDataView>(
            in_error, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPresentationService_JoinSession_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::PresentationService_JoinSession_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->sessionInfo)::BaseType* sessionInfo_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, builder.buffer(), &sessionInfo_ptr, &serialization_context_);
        params->sessionInfo.Set(sessionInfo_ptr);
        typename decltype(params->error)::BaseType* error_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationErrorDataView>(
            in_error, builder.buffer(), &error_ptr, &serialization_context_);
        params->error.Set(error_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class PresentationService_SendConnectionMessage_ProxyToResponder {
    public:
        static PresentationService::SendConnectionMessageCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PresentationService_SendConnectionMessage_ProxyToResponder> proxy(
                new PresentationService_SendConnectionMessage_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PresentationService_SendConnectionMessage_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PresentationService_SendConnectionMessage_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PresentationService::SendConnectionMessage() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PresentationService_SendConnectionMessage_ProxyToResponder(
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
            bool in_success);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PresentationService_SendConnectionMessage_ProxyToResponder);
    };

    void PresentationService_SendConnectionMessage_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::blink::mojom::internal::PresentationService_SendConnectionMessage_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPresentationService_SendConnectionMessage_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::PresentationService_SendConnectionMessage_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
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
    bool PresentationServiceStubDispatch::Accept(
        PresentationService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPresentationService_SetClient_Name: {
            internal::PresentationService_SetClient_Params_Data* params = reinterpret_cast<internal::PresentationService_SetClient_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationServiceClientPtr p_client {};
            PresentationService_SetClient_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::SetClient deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::SetClient");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetClient(
                std::move(p_client));
            return true;
        }
        case internal::kPresentationService_SetDefaultPresentationUrls_Name: {
            internal::PresentationService_SetDefaultPresentationUrls_Params_Data* params = reinterpret_cast<internal::PresentationService_SetDefaultPresentationUrls_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<GURL> p_presentation_urls {};
            PresentationService_SetDefaultPresentationUrls_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPresentationUrls(&p_presentation_urls))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::SetDefaultPresentationUrls deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::SetDefaultPresentationUrls");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetDefaultPresentationUrls(
                std::move(p_presentation_urls));
            return true;
        }
        case internal::kPresentationService_ListenForScreenAvailability_Name: {
            internal::PresentationService_ListenForScreenAvailability_Params_Data* params = reinterpret_cast<internal::PresentationService_ListenForScreenAvailability_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GURL p_availability_url {};
            PresentationService_ListenForScreenAvailability_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadAvailabilityUrl(&p_availability_url))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::ListenForScreenAvailability deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::ListenForScreenAvailability");
            mojo::internal::MessageDispatchContext context(message);
            impl->ListenForScreenAvailability(
                std::move(p_availability_url));
            return true;
        }
        case internal::kPresentationService_StopListeningForScreenAvailability_Name: {
            internal::PresentationService_StopListeningForScreenAvailability_Params_Data* params = reinterpret_cast<internal::PresentationService_StopListeningForScreenAvailability_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GURL p_availability_url {};
            PresentationService_StopListeningForScreenAvailability_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadAvailabilityUrl(&p_availability_url))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::StopListeningForScreenAvailability deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::StopListeningForScreenAvailability");
            mojo::internal::MessageDispatchContext context(message);
            impl->StopListeningForScreenAvailability(
                std::move(p_availability_url));
            return true;
        }
        case internal::kPresentationService_StartSession_Name: {
            break;
        }
        case internal::kPresentationService_JoinSession_Name: {
            break;
        }
        case internal::kPresentationService_SetPresentationConnection_Name: {
            internal::PresentationService_SetPresentationConnection_Params_Data* params = reinterpret_cast<internal::PresentationService_SetPresentationConnection_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationSessionInfoPtr p_sessionInfo {};
            PresentationConnectionPtr p_controller_connection_ptr {};
            PresentationConnectionRequest p_receiver_connection_request {};
            PresentationService_SetPresentationConnection_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessioninfo(&p_sessionInfo))
                success = false;
            p_controller_connection_ptr = input_data_view.TakeControllerConnectionPtr<decltype(p_controller_connection_ptr)>();
            p_receiver_connection_request = input_data_view.TakeReceiverConnectionRequest<decltype(p_receiver_connection_request)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::SetPresentationConnection deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::SetPresentationConnection");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetPresentationConnection(
                std::move(p_sessionInfo),
                std::move(p_controller_connection_ptr),
                std::move(p_receiver_connection_request));
            return true;
        }
        case internal::kPresentationService_SendConnectionMessage_Name: {
            break;
        }
        case internal::kPresentationService_CloseConnection_Name: {
            internal::PresentationService_CloseConnection_Params_Data* params = reinterpret_cast<internal::PresentationService_CloseConnection_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GURL p_presentation_url {};
            std::string p_presentation_id {};
            PresentationService_CloseConnection_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPresentationUrl(&p_presentation_url))
                success = false;
            if (!input_data_view.ReadPresentationId(&p_presentation_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::CloseConnection deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::CloseConnection");
            mojo::internal::MessageDispatchContext context(message);
            impl->CloseConnection(
                std::move(p_presentation_url),
                std::move(p_presentation_id));
            return true;
        }
        case internal::kPresentationService_Terminate_Name: {
            internal::PresentationService_Terminate_Params_Data* params = reinterpret_cast<internal::PresentationService_Terminate_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GURL p_presentation_url {};
            std::string p_presentation_id {};
            PresentationService_Terminate_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPresentationUrl(&p_presentation_url))
                success = false;
            if (!input_data_view.ReadPresentationId(&p_presentation_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::Terminate deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::Terminate");
            mojo::internal::MessageDispatchContext context(message);
            impl->Terminate(
                std::move(p_presentation_url),
                std::move(p_presentation_id));
            return true;
        }
        case internal::kPresentationService_ListenForConnectionMessages_Name: {
            internal::PresentationService_ListenForConnectionMessages_Params_Data* params = reinterpret_cast<internal::PresentationService_ListenForConnectionMessages_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationSessionInfoPtr p_sessionInfo {};
            PresentationService_ListenForConnectionMessages_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessioninfo(&p_sessionInfo))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::ListenForConnectionMessages deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::ListenForConnectionMessages");
            mojo::internal::MessageDispatchContext context(message);
            impl->ListenForConnectionMessages(
                std::move(p_sessionInfo));
            return true;
        }
        }
        return false;
    }

    // static
    bool PresentationServiceStubDispatch::AcceptWithResponder(
        PresentationService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPresentationService_SetClient_Name: {
            break;
        }
        case internal::kPresentationService_SetDefaultPresentationUrls_Name: {
            break;
        }
        case internal::kPresentationService_ListenForScreenAvailability_Name: {
            break;
        }
        case internal::kPresentationService_StopListeningForScreenAvailability_Name: {
            break;
        }
        case internal::kPresentationService_StartSession_Name: {
            internal::PresentationService_StartSession_Params_Data* params = reinterpret_cast<internal::PresentationService_StartSession_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<GURL> p_presentation_urls {};
            PresentationService_StartSession_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPresentationUrls(&p_presentation_urls))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::StartSession deserializer");
                return false;
            }
            PresentationService::StartSessionCallback callback = PresentationService_StartSession_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::StartSession");
            mojo::internal::MessageDispatchContext context(message);
            impl->StartSession(
                std::move(p_presentation_urls), std::move(callback));
            return true;
        }
        case internal::kPresentationService_JoinSession_Name: {
            internal::PresentationService_JoinSession_Params_Data* params = reinterpret_cast<internal::PresentationService_JoinSession_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<GURL> p_presentation_urls {};
            base::Optional<std::string> p_presentation_id {};
            PresentationService_JoinSession_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPresentationUrls(&p_presentation_urls))
                success = false;
            if (!input_data_view.ReadPresentationId(&p_presentation_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::JoinSession deserializer");
                return false;
            }
            PresentationService::JoinSessionCallback callback = PresentationService_JoinSession_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::JoinSession");
            mojo::internal::MessageDispatchContext context(message);
            impl->JoinSession(
                std::move(p_presentation_urls),
                std::move(p_presentation_id), std::move(callback));
            return true;
        }
        case internal::kPresentationService_SetPresentationConnection_Name: {
            break;
        }
        case internal::kPresentationService_SendConnectionMessage_Name: {
            internal::PresentationService_SendConnectionMessage_Params_Data* params = reinterpret_cast<internal::PresentationService_SendConnectionMessage_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationSessionInfoPtr p_sessionInfo {};
            ConnectionMessagePtr p_message_request {};
            PresentationService_SendConnectionMessage_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessioninfo(&p_sessionInfo))
                success = false;
            if (!input_data_view.ReadMessageRequest(&p_message_request))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationService::SendConnectionMessage deserializer");
                return false;
            }
            PresentationService::SendConnectionMessageCallback callback = PresentationService_SendConnectionMessage_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationService::SendConnectionMessage");
            mojo::internal::MessageDispatchContext context(message);
            impl->SendConnectionMessage(
                std::move(p_sessionInfo),
                std::move(p_message_request), std::move(callback));
            return true;
        }
        case internal::kPresentationService_CloseConnection_Name: {
            break;
        }
        case internal::kPresentationService_Terminate_Name: {
            break;
        }
        case internal::kPresentationService_ListenForConnectionMessages_Name: {
            break;
        }
        }
        return false;
    }

    bool PresentationServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PresentationService RequestValidator");

        switch (message->header()->name) {
        case internal::kPresentationService_SetClient_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_SetClient_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_SetDefaultPresentationUrls_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_SetDefaultPresentationUrls_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_ListenForScreenAvailability_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_ListenForScreenAvailability_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_StopListeningForScreenAvailability_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_StopListeningForScreenAvailability_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_StartSession_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_StartSession_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_JoinSession_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_JoinSession_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_SetPresentationConnection_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_SetPresentationConnection_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_SendConnectionMessage_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_SendConnectionMessage_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_CloseConnection_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_CloseConnection_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_Terminate_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_Terminate_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_ListenForConnectionMessages_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_ListenForConnectionMessages_Params_Data>(
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

    bool PresentationServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PresentationService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kPresentationService_StartSession_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_StartSession_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_JoinSession_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_JoinSession_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationService_SendConnectionMessage_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationService_SendConnectionMessage_ResponseParams_Data>(
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
    const char PresentationServiceClient::Name_[] = "blink::mojom::PresentationServiceClient";

    PresentationServiceClientProxy::PresentationServiceClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PresentationServiceClientProxy::OnScreenAvailabilityNotSupported(
        const GURL& in_url)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_url, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationServiceClient_OnScreenAvailabilityNotSupported_Name, size);

        auto params = ::blink::mojom::internal::PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in PresentationServiceClient.OnScreenAvailabilityNotSupported request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceClientProxy::OnScreenAvailabilityUpdated(
        const GURL& in_url, bool in_available)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_url, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationServiceClient_OnScreenAvailabilityUpdated_Name, size);

        auto params = ::blink::mojom::internal::PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in PresentationServiceClient.OnScreenAvailabilityUpdated request");
        params->available = in_available;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceClientProxy::OnDefaultSessionStarted(
        PresentationSessionInfoPtr in_sessionInfo)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationServiceClient_OnDefaultSessionStarted_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationServiceClient_OnDefaultSessionStarted_Name, size);

        auto params = ::blink::mojom::internal::PresentationServiceClient_OnDefaultSessionStarted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->sessionInfo)::BaseType* sessionInfo_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, builder.buffer(), &sessionInfo_ptr, &serialization_context);
        params->sessionInfo.Set(sessionInfo_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->sessionInfo.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null sessionInfo in PresentationServiceClient.OnDefaultSessionStarted request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceClientProxy::OnConnectionStateChanged(
        PresentationSessionInfoPtr in_connection, PresentationConnectionState in_newState)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationServiceClient_OnConnectionStateChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_connection, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationServiceClient_OnConnectionStateChanged_Name, size);

        auto params = ::blink::mojom::internal::PresentationServiceClient_OnConnectionStateChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->connection)::BaseType* connection_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_connection, builder.buffer(), &connection_ptr, &serialization_context);
        params->connection.Set(connection_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->connection.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null connection in PresentationServiceClient.OnConnectionStateChanged request");
        mojo::internal::Serialize<::blink::mojom::PresentationConnectionState>(
            in_newState, &params->newState);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceClientProxy::OnConnectionClosed(
        PresentationSessionInfoPtr in_connection, PresentationConnectionCloseReason in_reason, const std::string& in_message)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationServiceClient_OnConnectionClosed_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_connection, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_message, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationServiceClient_OnConnectionClosed_Name, size);

        auto params = ::blink::mojom::internal::PresentationServiceClient_OnConnectionClosed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->connection)::BaseType* connection_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_connection, builder.buffer(), &connection_ptr, &serialization_context);
        params->connection.Set(connection_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->connection.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null connection in PresentationServiceClient.OnConnectionClosed request");
        mojo::internal::Serialize<::blink::mojom::PresentationConnectionCloseReason>(
            in_reason, &params->reason);
        typename decltype(params->message)::BaseType* message_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_message, builder.buffer(), &message_ptr, &serialization_context);
        params->message.Set(message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message in PresentationServiceClient.OnConnectionClosed request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceClientProxy::OnConnectionMessagesReceived(
        PresentationSessionInfoPtr in_sessionInfo, std::vector<ConnectionMessagePtr> in_messages)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationServiceClient_OnConnectionMessagesReceived_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::ConnectionMessageDataView>>(
            in_messages, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationServiceClient_OnConnectionMessagesReceived_Name, size);

        auto params = ::blink::mojom::internal::PresentationServiceClient_OnConnectionMessagesReceived_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->sessionInfo)::BaseType* sessionInfo_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, builder.buffer(), &sessionInfo_ptr, &serialization_context);
        params->sessionInfo.Set(sessionInfo_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->sessionInfo.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null sessionInfo in PresentationServiceClient.OnConnectionMessagesReceived request");
        typename decltype(params->messages)::BaseType* messages_ptr;
        const mojo::internal::ContainerValidateParams messages_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::ConnectionMessageDataView>>(
            in_messages, builder.buffer(), &messages_ptr, &messages_validate_params,
            &serialization_context);
        params->messages.Set(messages_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->messages.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null messages in PresentationServiceClient.OnConnectionMessagesReceived request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PresentationServiceClientProxy::OnReceiverConnectionAvailable(
        PresentationSessionInfoPtr in_sessionInfo, PresentationConnectionPtr in_controller_connection_ptr, PresentationConnectionRequest in_receiver_connection_request)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPresentationServiceClient_OnReceiverConnectionAvailable_Name, size);

        auto params = ::blink::mojom::internal::PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->sessionInfo)::BaseType* sessionInfo_ptr;
        mojo::internal::Serialize<::blink::mojom::PresentationSessionInfoDataView>(
            in_sessionInfo, builder.buffer(), &sessionInfo_ptr, &serialization_context);
        params->sessionInfo.Set(sessionInfo_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->sessionInfo.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null sessionInfo in PresentationServiceClient.OnReceiverConnectionAvailable request");
        mojo::internal::Serialize<::blink::mojom::PresentationConnectionPtrDataView>(
            in_controller_connection_ptr, &params->controller_connection_ptr, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->controller_connection_ptr),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid controller_connection_ptr in PresentationServiceClient.OnReceiverConnectionAvailable request");
        mojo::internal::Serialize<::blink::mojom::PresentationConnectionRequestDataView>(
            in_receiver_connection_request, &params->receiver_connection_request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->receiver_connection_request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid receiver_connection_request in PresentationServiceClient.OnReceiverConnectionAvailable request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool PresentationServiceClientStubDispatch::Accept(
        PresentationServiceClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPresentationServiceClient_OnScreenAvailabilityNotSupported_Name: {
            internal::PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data* params = reinterpret_cast<internal::PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GURL p_url {};
            PresentationServiceClient_OnScreenAvailabilityNotSupported_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationServiceClient::OnScreenAvailabilityNotSupported deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationServiceClient::OnScreenAvailabilityNotSupported");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnScreenAvailabilityNotSupported(
                std::move(p_url));
            return true;
        }
        case internal::kPresentationServiceClient_OnScreenAvailabilityUpdated_Name: {
            internal::PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data* params = reinterpret_cast<internal::PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GURL p_url {};
            bool p_available {};
            PresentationServiceClient_OnScreenAvailabilityUpdated_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            p_available = input_data_view.available();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationServiceClient::OnScreenAvailabilityUpdated deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationServiceClient::OnScreenAvailabilityUpdated");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnScreenAvailabilityUpdated(
                std::move(p_url),
                std::move(p_available));
            return true;
        }
        case internal::kPresentationServiceClient_OnDefaultSessionStarted_Name: {
            internal::PresentationServiceClient_OnDefaultSessionStarted_Params_Data* params = reinterpret_cast<internal::PresentationServiceClient_OnDefaultSessionStarted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationSessionInfoPtr p_sessionInfo {};
            PresentationServiceClient_OnDefaultSessionStarted_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessioninfo(&p_sessionInfo))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationServiceClient::OnDefaultSessionStarted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationServiceClient::OnDefaultSessionStarted");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDefaultSessionStarted(
                std::move(p_sessionInfo));
            return true;
        }
        case internal::kPresentationServiceClient_OnConnectionStateChanged_Name: {
            internal::PresentationServiceClient_OnConnectionStateChanged_Params_Data* params = reinterpret_cast<internal::PresentationServiceClient_OnConnectionStateChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationSessionInfoPtr p_connection {};
            PresentationConnectionState p_newState {};
            PresentationServiceClient_OnConnectionStateChanged_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadConnection(&p_connection))
                success = false;
            if (!input_data_view.ReadNewstate(&p_newState))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationServiceClient::OnConnectionStateChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationServiceClient::OnConnectionStateChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnConnectionStateChanged(
                std::move(p_connection),
                std::move(p_newState));
            return true;
        }
        case internal::kPresentationServiceClient_OnConnectionClosed_Name: {
            internal::PresentationServiceClient_OnConnectionClosed_Params_Data* params = reinterpret_cast<internal::PresentationServiceClient_OnConnectionClosed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationSessionInfoPtr p_connection {};
            PresentationConnectionCloseReason p_reason {};
            std::string p_message {};
            PresentationServiceClient_OnConnectionClosed_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadConnection(&p_connection))
                success = false;
            if (!input_data_view.ReadReason(&p_reason))
                success = false;
            if (!input_data_view.ReadMessage(&p_message))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationServiceClient::OnConnectionClosed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationServiceClient::OnConnectionClosed");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnConnectionClosed(
                std::move(p_connection),
                std::move(p_reason),
                std::move(p_message));
            return true;
        }
        case internal::kPresentationServiceClient_OnConnectionMessagesReceived_Name: {
            internal::PresentationServiceClient_OnConnectionMessagesReceived_Params_Data* params = reinterpret_cast<internal::PresentationServiceClient_OnConnectionMessagesReceived_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationSessionInfoPtr p_sessionInfo {};
            std::vector<ConnectionMessagePtr> p_messages {};
            PresentationServiceClient_OnConnectionMessagesReceived_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessioninfo(&p_sessionInfo))
                success = false;
            if (!input_data_view.ReadMessages(&p_messages))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationServiceClient::OnConnectionMessagesReceived deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationServiceClient::OnConnectionMessagesReceived");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnConnectionMessagesReceived(
                std::move(p_sessionInfo),
                std::move(p_messages));
            return true;
        }
        case internal::kPresentationServiceClient_OnReceiverConnectionAvailable_Name: {
            internal::PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data* params = reinterpret_cast<internal::PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PresentationSessionInfoPtr p_sessionInfo {};
            PresentationConnectionPtr p_controller_connection_ptr {};
            PresentationConnectionRequest p_receiver_connection_request {};
            PresentationServiceClient_OnReceiverConnectionAvailable_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessioninfo(&p_sessionInfo))
                success = false;
            p_controller_connection_ptr = input_data_view.TakeControllerConnectionPtr<decltype(p_controller_connection_ptr)>();
            p_receiver_connection_request = input_data_view.TakeReceiverConnectionRequest<decltype(p_receiver_connection_request)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PresentationServiceClient::OnReceiverConnectionAvailable deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PresentationServiceClient::OnReceiverConnectionAvailable");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnReceiverConnectionAvailable(
                std::move(p_sessionInfo),
                std::move(p_controller_connection_ptr),
                std::move(p_receiver_connection_request));
            return true;
        }
        }
        return false;
    }

    // static
    bool PresentationServiceClientStubDispatch::AcceptWithResponder(
        PresentationServiceClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPresentationServiceClient_OnScreenAvailabilityNotSupported_Name: {
            break;
        }
        case internal::kPresentationServiceClient_OnScreenAvailabilityUpdated_Name: {
            break;
        }
        case internal::kPresentationServiceClient_OnDefaultSessionStarted_Name: {
            break;
        }
        case internal::kPresentationServiceClient_OnConnectionStateChanged_Name: {
            break;
        }
        case internal::kPresentationServiceClient_OnConnectionClosed_Name: {
            break;
        }
        case internal::kPresentationServiceClient_OnConnectionMessagesReceived_Name: {
            break;
        }
        case internal::kPresentationServiceClient_OnReceiverConnectionAvailable_Name: {
            break;
        }
        }
        return false;
    }

    bool PresentationServiceClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PresentationServiceClient RequestValidator");

        switch (message->header()->name) {
        case internal::kPresentationServiceClient_OnScreenAvailabilityNotSupported_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationServiceClient_OnScreenAvailabilityUpdated_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationServiceClient_OnDefaultSessionStarted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationServiceClient_OnDefaultSessionStarted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationServiceClient_OnConnectionStateChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationServiceClient_OnConnectionStateChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationServiceClient_OnConnectionClosed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationServiceClient_OnConnectionClosed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationServiceClient_OnConnectionMessagesReceived_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationServiceClient_OnConnectionMessagesReceived_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPresentationServiceClient_OnReceiverConnectionAvailable_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data>(
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
} // namespace blink

namespace mojo {

// static
bool StructTraits<::blink::mojom::PresentationSessionInfo::DataView, ::blink::mojom::PresentationSessionInfoPtr>::Read(
    ::blink::mojom::PresentationSessionInfo::DataView input,
    ::blink::mojom::PresentationSessionInfoPtr* output)
{
    bool success = true;
    ::blink::mojom::PresentationSessionInfoPtr result(::blink::mojom::PresentationSessionInfo::New());

    if (!input.ReadUrl(&result->url))
        success = false;
    if (!input.ReadId(&result->id))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::PresentationError::DataView, ::blink::mojom::PresentationErrorPtr>::Read(
    ::blink::mojom::PresentationError::DataView input,
    ::blink::mojom::PresentationErrorPtr* output)
{
    bool success = true;
    ::blink::mojom::PresentationErrorPtr result(::blink::mojom::PresentationError::New());

    if (!input.ReadErrorType(&result->error_type))
        success = false;
    if (!input.ReadMessage(&result->message))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::ConnectionMessage::DataView, ::blink::mojom::ConnectionMessagePtr>::Read(
    ::blink::mojom::ConnectionMessage::DataView input,
    ::blink::mojom::ConnectionMessagePtr* output)
{
    bool success = true;
    ::blink::mojom::ConnectionMessagePtr result(::blink::mojom::ConnectionMessage::New());

    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadMessage(&result->message))
        success = false;
    if (!input.ReadData(&result->data))
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