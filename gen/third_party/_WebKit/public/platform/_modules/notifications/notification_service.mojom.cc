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

#include "third_party/WebKit/public/platform/modules/notifications/notification_service.mojom.h"

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
namespace mojom {
    const char NotificationService::Name_[] = "blink::mojom::NotificationService";
    bool NotificationService::GetPermissionStatus(const std::string& origin, ::blink::mojom::PermissionStatus* status)
    {
        NOTREACHED();
        return false;
    }
    class NotificationService_GetPermissionStatus_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        NotificationService_GetPermissionStatus_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::blink::mojom::PermissionStatus* out_status)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_status_(out_status)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::blink::mojom::PermissionStatus* out_status_;
        DISALLOW_COPY_AND_ASSIGN(NotificationService_GetPermissionStatus_HandleSyncResponse);
    };
    bool NotificationService_GetPermissionStatus_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::NotificationService_GetPermissionStatus_ResponseParams_Data* params = reinterpret_cast<internal::NotificationService_GetPermissionStatus_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::blink::mojom::PermissionStatus p_status {};
        NotificationService_GetPermissionStatus_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "NotificationService::GetPermissionStatus response deserializer");
            return false;
        }
        *out_status_ = std::move(p_status);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class NotificationService_GetPermissionStatus_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        NotificationService_GetPermissionStatus_ForwardToCallback(
            const NotificationService::GetPermissionStatusCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        NotificationService::GetPermissionStatusCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(NotificationService_GetPermissionStatus_ForwardToCallback);
    };
    bool NotificationService_GetPermissionStatus_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::NotificationService_GetPermissionStatus_ResponseParams_Data* params = reinterpret_cast<internal::NotificationService_GetPermissionStatus_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::blink::mojom::PermissionStatus p_status {};
        NotificationService_GetPermissionStatus_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "NotificationService::GetPermissionStatus response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    NotificationServiceProxy::NotificationServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }
    bool NotificationServiceProxy::GetPermissionStatus(
        const std::string& param_origin, ::blink::mojom::PermissionStatus* param_status)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::NotificationService_GetPermissionStatus_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_origin, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kNotificationService_GetPermissionStatus_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::blink::mojom::internal::NotificationService_GetPermissionStatus_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in NotificationService.GetPermissionStatus request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new NotificationService_GetPermissionStatus_HandleSyncResponse(
            group_controller_, &result, param_status);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void NotificationServiceProxy::GetPermissionStatus(
        const std::string& in_origin, const GetPermissionStatusCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::NotificationService_GetPermissionStatus_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_origin, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kNotificationService_GetPermissionStatus_Name, size);

        auto params = ::blink::mojom::internal::NotificationService_GetPermissionStatus_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in NotificationService.GetPermissionStatus request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new NotificationService_GetPermissionStatus_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class NotificationService_GetPermissionStatus_ProxyToResponder {
    public:
        static NotificationService::GetPermissionStatusCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<NotificationService_GetPermissionStatus_ProxyToResponder> proxy(
                new NotificationService_GetPermissionStatus_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&NotificationService_GetPermissionStatus_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~NotificationService_GetPermissionStatus_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "NotificationService::GetPermissionStatus() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        NotificationService_GetPermissionStatus_ProxyToResponder(
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
            ::blink::mojom::PermissionStatus in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(NotificationService_GetPermissionStatus_ProxyToResponder);
    };

    void NotificationService_GetPermissionStatus_ProxyToResponder::Run(
        ::blink::mojom::PermissionStatus in_status)
    {
        size_t size = sizeof(::blink::mojom::internal::NotificationService_GetPermissionStatus_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kNotificationService_GetPermissionStatus_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::NotificationService_GetPermissionStatus_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::PermissionStatus>(
            in_status, &params->status);
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
    bool NotificationServiceStubDispatch::Accept(
        NotificationService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kNotificationService_GetPermissionStatus_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool NotificationServiceStubDispatch::AcceptWithResponder(
        NotificationService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kNotificationService_GetPermissionStatus_Name: {
            internal::NotificationService_GetPermissionStatus_Params_Data* params = reinterpret_cast<internal::NotificationService_GetPermissionStatus_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_origin {};
            NotificationService_GetPermissionStatus_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "NotificationService::GetPermissionStatus deserializer");
                return false;
            }
            NotificationService::GetPermissionStatusCallback callback = NotificationService_GetPermissionStatus_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "NotificationService::GetPermissionStatus");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetPermissionStatus(
                std::move(p_origin), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool NotificationServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "NotificationService RequestValidator");

        switch (message->header()->name) {
        case internal::kNotificationService_GetPermissionStatus_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::NotificationService_GetPermissionStatus_Params_Data>(
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

    bool NotificationServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "NotificationService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kNotificationService_GetPermissionStatus_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::NotificationService_GetPermissionStatus_ResponseParams_Data>(
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

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif