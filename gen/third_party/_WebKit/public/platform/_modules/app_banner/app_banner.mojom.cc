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

#include "third_party/WebKit/public/platform/modules/app_banner/app_banner.mojom.h"

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
    const char AppBannerController::Name_[] = "blink::mojom::AppBannerController";

    class AppBannerController_BannerPromptRequest_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        AppBannerController_BannerPromptRequest_ForwardToCallback(
            const AppBannerController::BannerPromptRequestCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        AppBannerController::BannerPromptRequestCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(AppBannerController_BannerPromptRequest_ForwardToCallback);
    };
    bool AppBannerController_BannerPromptRequest_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::AppBannerController_BannerPromptRequest_ResponseParams_Data* params = reinterpret_cast<internal::AppBannerController_BannerPromptRequest_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        AppBannerPromptReply p_reply {};
        std::string p_referrer {};
        AppBannerController_BannerPromptRequest_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadReply(&p_reply))
            success = false;
        if (!input_data_view.ReadReferrer(&p_referrer))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "AppBannerController::BannerPromptRequest response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_reply),
                std::move(p_referrer));
        }
        return true;
    }

    AppBannerControllerProxy::AppBannerControllerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void AppBannerControllerProxy::BannerPromptRequest(
        AppBannerServicePtr in_service, AppBannerEventRequest in_event, const std::vector<std::string>& in_platform, const BannerPromptRequestCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::AppBannerController_BannerPromptRequest_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_platform, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kAppBannerController_BannerPromptRequest_Name, size);

        auto params = ::blink::mojom::internal::AppBannerController_BannerPromptRequest_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::AppBannerServicePtrDataView>(
            in_service, &params->service, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->service),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid service in AppBannerController.BannerPromptRequest request");
        mojo::internal::Serialize<::blink::mojom::AppBannerEventRequestDataView>(
            in_event, &params->event, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->event),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid event in AppBannerController.BannerPromptRequest request");
        typename decltype(params->platform)::BaseType* platform_ptr;
        const mojo::internal::ContainerValidateParams platform_validate_params(
            0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
        mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_platform, builder.buffer(), &platform_ptr, &platform_validate_params,
            &serialization_context);
        params->platform.Set(platform_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->platform.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null platform in AppBannerController.BannerPromptRequest request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new AppBannerController_BannerPromptRequest_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class AppBannerController_BannerPromptRequest_ProxyToResponder {
    public:
        static AppBannerController::BannerPromptRequestCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<AppBannerController_BannerPromptRequest_ProxyToResponder> proxy(
                new AppBannerController_BannerPromptRequest_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&AppBannerController_BannerPromptRequest_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~AppBannerController_BannerPromptRequest_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "AppBannerController::BannerPromptRequest() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        AppBannerController_BannerPromptRequest_ProxyToResponder(
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
            AppBannerPromptReply in_reply, const std::string& in_referrer);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(AppBannerController_BannerPromptRequest_ProxyToResponder);
    };

    void AppBannerController_BannerPromptRequest_ProxyToResponder::Run(
        AppBannerPromptReply in_reply, const std::string& in_referrer)
    {
        size_t size = sizeof(::blink::mojom::internal::AppBannerController_BannerPromptRequest_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_referrer, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kAppBannerController_BannerPromptRequest_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::AppBannerController_BannerPromptRequest_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::AppBannerPromptReply>(
            in_reply, &params->reply);
        typename decltype(params->referrer)::BaseType* referrer_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_referrer, builder.buffer(), &referrer_ptr, &serialization_context_);
        params->referrer.Set(referrer_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->referrer.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null referrer in AppBannerController.BannerPromptRequest response");
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
    bool AppBannerControllerStubDispatch::Accept(
        AppBannerController* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kAppBannerController_BannerPromptRequest_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool AppBannerControllerStubDispatch::AcceptWithResponder(
        AppBannerController* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kAppBannerController_BannerPromptRequest_Name: {
            internal::AppBannerController_BannerPromptRequest_Params_Data* params = reinterpret_cast<internal::AppBannerController_BannerPromptRequest_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AppBannerServicePtr p_service {};
            AppBannerEventRequest p_event {};
            std::vector<std::string> p_platform {};
            AppBannerController_BannerPromptRequest_ParamsDataView input_data_view(params,
                context);

            p_service = input_data_view.TakeService<decltype(p_service)>();
            p_event = input_data_view.TakeEvent<decltype(p_event)>();
            if (!input_data_view.ReadPlatform(&p_platform))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AppBannerController::BannerPromptRequest deserializer");
                return false;
            }
            AppBannerController::BannerPromptRequestCallback callback = AppBannerController_BannerPromptRequest_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AppBannerController::BannerPromptRequest");
            mojo::internal::MessageDispatchContext context(message);
            impl->BannerPromptRequest(
                std::move(p_service),
                std::move(p_event),
                std::move(p_platform), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool AppBannerControllerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AppBannerController RequestValidator");

        switch (message->header()->name) {
        case internal::kAppBannerController_BannerPromptRequest_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AppBannerController_BannerPromptRequest_Params_Data>(
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

    bool AppBannerControllerResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AppBannerController ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kAppBannerController_BannerPromptRequest_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AppBannerController_BannerPromptRequest_ResponseParams_Data>(
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
    const char AppBannerEvent::Name_[] = "blink::mojom::AppBannerEvent";

    AppBannerEventProxy::AppBannerEventProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void AppBannerEventProxy::BannerAccepted(
        const std::string& in_platform)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::AppBannerEvent_BannerAccepted_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_platform, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAppBannerEvent_BannerAccepted_Name, size);

        auto params = ::blink::mojom::internal::AppBannerEvent_BannerAccepted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->platform)::BaseType* platform_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_platform, builder.buffer(), &platform_ptr, &serialization_context);
        params->platform.Set(platform_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->platform.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null platform in AppBannerEvent.BannerAccepted request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AppBannerEventProxy::BannerDismissed()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::AppBannerEvent_BannerDismissed_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAppBannerEvent_BannerDismissed_Name, size);

        auto params = ::blink::mojom::internal::AppBannerEvent_BannerDismissed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool AppBannerEventStubDispatch::Accept(
        AppBannerEvent* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kAppBannerEvent_BannerAccepted_Name: {
            internal::AppBannerEvent_BannerAccepted_Params_Data* params = reinterpret_cast<internal::AppBannerEvent_BannerAccepted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_platform {};
            AppBannerEvent_BannerAccepted_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPlatform(&p_platform))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AppBannerEvent::BannerAccepted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AppBannerEvent::BannerAccepted");
            mojo::internal::MessageDispatchContext context(message);
            impl->BannerAccepted(
                std::move(p_platform));
            return true;
        }
        case internal::kAppBannerEvent_BannerDismissed_Name: {
            internal::AppBannerEvent_BannerDismissed_Params_Data* params = reinterpret_cast<internal::AppBannerEvent_BannerDismissed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AppBannerEvent_BannerDismissed_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AppBannerEvent::BannerDismissed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AppBannerEvent::BannerDismissed");
            mojo::internal::MessageDispatchContext context(message);
            impl->BannerDismissed();
            return true;
        }
        }
        return false;
    }

    // static
    bool AppBannerEventStubDispatch::AcceptWithResponder(
        AppBannerEvent* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kAppBannerEvent_BannerAccepted_Name: {
            break;
        }
        case internal::kAppBannerEvent_BannerDismissed_Name: {
            break;
        }
        }
        return false;
    }

    bool AppBannerEventRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AppBannerEvent RequestValidator");

        switch (message->header()->name) {
        case internal::kAppBannerEvent_BannerAccepted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AppBannerEvent_BannerAccepted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAppBannerEvent_BannerDismissed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AppBannerEvent_BannerDismissed_Params_Data>(
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

    const char AppBannerService::Name_[] = "blink::mojom::AppBannerService";

    AppBannerServiceProxy::AppBannerServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void AppBannerServiceProxy::DisplayAppBanner()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::AppBannerService_DisplayAppBanner_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAppBannerService_DisplayAppBanner_Name, size);

        auto params = ::blink::mojom::internal::AppBannerService_DisplayAppBanner_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool AppBannerServiceStubDispatch::Accept(
        AppBannerService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kAppBannerService_DisplayAppBanner_Name: {
            internal::AppBannerService_DisplayAppBanner_Params_Data* params = reinterpret_cast<internal::AppBannerService_DisplayAppBanner_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AppBannerService_DisplayAppBanner_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AppBannerService::DisplayAppBanner deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AppBannerService::DisplayAppBanner");
            mojo::internal::MessageDispatchContext context(message);
            impl->DisplayAppBanner();
            return true;
        }
        }
        return false;
    }

    // static
    bool AppBannerServiceStubDispatch::AcceptWithResponder(
        AppBannerService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kAppBannerService_DisplayAppBanner_Name: {
            break;
        }
        }
        return false;
    }

    bool AppBannerServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AppBannerService RequestValidator");

        switch (message->header()->name) {
        case internal::kAppBannerService_DisplayAppBanner_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AppBannerService_DisplayAppBanner_Params_Data>(
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