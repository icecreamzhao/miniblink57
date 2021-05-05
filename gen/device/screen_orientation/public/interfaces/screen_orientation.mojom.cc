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

#include "device/screen_orientation/public/interfaces/screen_orientation.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/public/platform/modules/screen_orientation/WebScreenOrientationEnumTraits.h"
namespace device {
namespace mojom {
    const char ScreenOrientation::Name_[] = "device::mojom::ScreenOrientation";

    class ScreenOrientation_LockOrientation_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ScreenOrientation_LockOrientation_ForwardToCallback(
            const ScreenOrientation::LockOrientationCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ScreenOrientation::LockOrientationCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ScreenOrientation_LockOrientation_ForwardToCallback);
    };
    bool ScreenOrientation_LockOrientation_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ScreenOrientation_LockOrientation_ResponseParams_Data* params = reinterpret_cast<internal::ScreenOrientation_LockOrientation_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::device::mojom::ScreenOrientationLockResult p_result {};
        ScreenOrientation_LockOrientation_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ScreenOrientation::LockOrientation response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result));
        }
        return true;
    }

    ScreenOrientationProxy::ScreenOrientationProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ScreenOrientationProxy::LockOrientation(
        ::blink::WebScreenOrientationLockType in_orientation, const LockOrientationCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::ScreenOrientation_LockOrientation_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kScreenOrientation_LockOrientation_Name, size);

        auto params = ::device::mojom::internal::ScreenOrientation_LockOrientation_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::mojom::ScreenOrientationLockType>(
            in_orientation, &params->orientation);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ScreenOrientation_LockOrientation_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ScreenOrientationProxy::UnlockOrientation()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::ScreenOrientation_UnlockOrientation_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kScreenOrientation_UnlockOrientation_Name, size);

        auto params = ::device::mojom::internal::ScreenOrientation_UnlockOrientation_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class ScreenOrientation_LockOrientation_ProxyToResponder {
    public:
        static ScreenOrientation::LockOrientationCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ScreenOrientation_LockOrientation_ProxyToResponder> proxy(
                new ScreenOrientation_LockOrientation_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ScreenOrientation_LockOrientation_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ScreenOrientation_LockOrientation_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ScreenOrientation::LockOrientation() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ScreenOrientation_LockOrientation_ProxyToResponder(
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
            ::device::mojom::ScreenOrientationLockResult in_result);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ScreenOrientation_LockOrientation_ProxyToResponder);
    };

    void ScreenOrientation_LockOrientation_ProxyToResponder::Run(
        ::device::mojom::ScreenOrientationLockResult in_result)
    {
        size_t size = sizeof(::device::mojom::internal::ScreenOrientation_LockOrientation_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kScreenOrientation_LockOrientation_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::device::mojom::internal::ScreenOrientation_LockOrientation_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::mojom::ScreenOrientationLockResult>(
            in_result, &params->result);
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
    bool ScreenOrientationStubDispatch::Accept(
        ScreenOrientation* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kScreenOrientation_LockOrientation_Name: {
            break;
        }
        case internal::kScreenOrientation_UnlockOrientation_Name: {
            internal::ScreenOrientation_UnlockOrientation_Params_Data* params = reinterpret_cast<internal::ScreenOrientation_UnlockOrientation_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ScreenOrientation_UnlockOrientation_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ScreenOrientation::UnlockOrientation deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ScreenOrientation::UnlockOrientation");
            mojo::internal::MessageDispatchContext context(message);
            impl->UnlockOrientation();
            return true;
        }
        }
        return false;
    }

    // static
    bool ScreenOrientationStubDispatch::AcceptWithResponder(
        ScreenOrientation* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kScreenOrientation_LockOrientation_Name: {
            internal::ScreenOrientation_LockOrientation_Params_Data* params = reinterpret_cast<internal::ScreenOrientation_LockOrientation_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::blink::WebScreenOrientationLockType p_orientation {};
            ScreenOrientation_LockOrientation_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOrientation(&p_orientation))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ScreenOrientation::LockOrientation deserializer");
                return false;
            }
            ScreenOrientation::LockOrientationCallback callback = ScreenOrientation_LockOrientation_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ScreenOrientation::LockOrientation");
            mojo::internal::MessageDispatchContext context(message);
            impl->LockOrientation(
                std::move(p_orientation), std::move(callback));
            return true;
        }
        case internal::kScreenOrientation_UnlockOrientation_Name: {
            break;
        }
        }
        return false;
    }

    bool ScreenOrientationRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ScreenOrientation RequestValidator");

        switch (message->header()->name) {
        case internal::kScreenOrientation_LockOrientation_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ScreenOrientation_LockOrientation_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kScreenOrientation_UnlockOrientation_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ScreenOrientation_UnlockOrientation_Params_Data>(
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

    bool ScreenOrientationResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ScreenOrientation ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kScreenOrientation_LockOrientation_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ScreenOrientation_LockOrientation_ResponseParams_Data>(
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
    const char ScreenOrientationListener::Name_[] = "device::mojom::ScreenOrientationListener";

    ScreenOrientationListenerProxy::ScreenOrientationListenerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ScreenOrientationListenerProxy::Start()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::ScreenOrientationListener_Start_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kScreenOrientationListener_Start_Name, size);

        auto params = ::device::mojom::internal::ScreenOrientationListener_Start_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ScreenOrientationListenerProxy::Stop()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::ScreenOrientationListener_Stop_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kScreenOrientationListener_Stop_Name, size);

        auto params = ::device::mojom::internal::ScreenOrientationListener_Stop_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool ScreenOrientationListenerStubDispatch::Accept(
        ScreenOrientationListener* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kScreenOrientationListener_Start_Name: {
            internal::ScreenOrientationListener_Start_Params_Data* params = reinterpret_cast<internal::ScreenOrientationListener_Start_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ScreenOrientationListener_Start_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ScreenOrientationListener::Start deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ScreenOrientationListener::Start");
            mojo::internal::MessageDispatchContext context(message);
            impl->Start();
            return true;
        }
        case internal::kScreenOrientationListener_Stop_Name: {
            internal::ScreenOrientationListener_Stop_Params_Data* params = reinterpret_cast<internal::ScreenOrientationListener_Stop_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ScreenOrientationListener_Stop_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ScreenOrientationListener::Stop deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ScreenOrientationListener::Stop");
            mojo::internal::MessageDispatchContext context(message);
            impl->Stop();
            return true;
        }
        }
        return false;
    }

    // static
    bool ScreenOrientationListenerStubDispatch::AcceptWithResponder(
        ScreenOrientationListener* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kScreenOrientationListener_Start_Name: {
            break;
        }
        case internal::kScreenOrientationListener_Stop_Name: {
            break;
        }
        }
        return false;
    }

    bool ScreenOrientationListenerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ScreenOrientationListener RequestValidator");

        switch (message->header()->name) {
        case internal::kScreenOrientationListener_Start_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ScreenOrientationListener_Start_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kScreenOrientationListener_Stop_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ScreenOrientationListener_Stop_Params_Data>(
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
} // namespace device

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif