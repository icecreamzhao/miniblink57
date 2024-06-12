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

#include "device/usb/public/interfaces/chooser_service.mojom-blink.h"

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
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace device {
namespace usb {
    namespace blink {
        const char ChooserService::Name_[] = "device::usb::ChooserService";

        class ChooserService_GetPermission_ForwardToCallback
            : public mojo::MessageReceiver {
        public:
            ChooserService_GetPermission_ForwardToCallback(
                const ChooserService::GetPermissionCallback& callback,
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
                : callback_(std::move(callback))
                , serialization_context_(std::move(group_controller))
            {
            }
            bool Accept(mojo::Message* message) override;

        private:
            ChooserService::GetPermissionCallback callback_;
            mojo::internal::SerializationContext serialization_context_;
            DISALLOW_COPY_AND_ASSIGN(ChooserService_GetPermission_ForwardToCallback);
        };
        bool ChooserService_GetPermission_ForwardToCallback::Accept(
            mojo::Message* message)
        {
            internal::ChooserService_GetPermission_ResponseParams_Data* params = reinterpret_cast<internal::ChooserService_GetPermission_ResponseParams_Data*>(
                message->mutable_payload());

            (&serialization_context_)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::device::usb::blink::DeviceInfoPtr p_result {};
            ChooserService_GetPermission_ResponseParamsDataView input_data_view(params,
                &serialization_context_);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ChooserService::GetPermission response deserializer");
                return false;
            }
            if (!callback_.is_null()) {
                mojo::internal::MessageDispatchContext context(message);
                std::move(callback_).Run(
                    std::move(p_result));
            }
            return true;
        }

        ChooserServiceProxy::ChooserServiceProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void ChooserServiceProxy::GetPermission(
            WTF::Vector<::device::usb::blink::DeviceFilterPtr> in_device_filters, const GetPermissionCallback& callback)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::usb::internal::ChooserService_GetPermission_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::device::usb::DeviceFilterDataView>>(
                in_device_filters, &serialization_context);
            mojo::internal::RequestMessageBuilder builder(internal::kChooserService_GetPermission_Name, size);

            auto params = ::device::usb::internal::ChooserService_GetPermission_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->device_filters)::BaseType* device_filters_ptr;
            const mojo::internal::ContainerValidateParams device_filters_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::device::usb::DeviceFilterDataView>>(
                in_device_filters, builder.buffer(), &device_filters_ptr, &device_filters_validate_params,
                &serialization_context);
            params->device_filters.Set(device_filters_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->device_filters.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null device_filters in ChooserService.GetPermission request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            mojo::MessageReceiver* responder = new ChooserService_GetPermission_ForwardToCallback(
                std::move(callback), group_controller_);
            if (!receiver_->AcceptWithResponder(builder.message(), responder))
                delete responder;
        }
        class ChooserService_GetPermission_ProxyToResponder {
        public:
            static ChooserService::GetPermissionCallback CreateCallback(
                uint64_t request_id,
                bool is_sync,
                mojo::MessageReceiverWithStatus* responder,
                scoped_refptr<mojo::AssociatedGroupController>
                    group_controller)
            {
                std::unique_ptr<ChooserService_GetPermission_ProxyToResponder> proxy(
                    new ChooserService_GetPermission_ProxyToResponder(
                        request_id, is_sync, responder, group_controller));
                return base::Bind(&ChooserService_GetPermission_ProxyToResponder::Run,
                    base::Passed(&proxy));
            }

            ~ChooserService_GetPermission_ProxyToResponder()
            {
#if DCHECK_IS_ON()
                if (responder_) {
                    // Is the Service destroying the callback without running it
                    // and without first closing the pipe?
                    responder_->DCheckInvalid("The callback passed to "
                                              "ChooserService::GetPermission() was never run.");
                }
#endif
                // If the Callback was dropped then deleting the responder will close
                // the pipe so the calling application knows to stop waiting for a reply.
                delete responder_;
            }

        private:
            ChooserService_GetPermission_ProxyToResponder(
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
                ::device::usb::blink::DeviceInfoPtr in_result);

            uint64_t request_id_;
            bool is_sync_;
            mojo::MessageReceiverWithStatus* responder_;
            // TODO(yzshen): maybe I should use a ref to the original one?
            mojo::internal::SerializationContext serialization_context_;

            DISALLOW_COPY_AND_ASSIGN(ChooserService_GetPermission_ProxyToResponder);
        };

        void ChooserService_GetPermission_ProxyToResponder::Run(
            ::device::usb::blink::DeviceInfoPtr in_result)
        {
            size_t size = sizeof(::device::usb::internal::ChooserService_GetPermission_ResponseParams_Data);
            size += mojo::internal::PrepareToSerialize<::device::usb::DeviceInfoDataView>(
                in_result, &serialization_context_);
            mojo::internal::ResponseMessageBuilder builder(
                internal::kChooserService_GetPermission_Name, size, request_id_,
                is_sync_ ? mojo::Message::kFlagIsSync : 0);
            auto params = ::device::usb::internal::ChooserService_GetPermission_ResponseParams_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->result)::BaseType* result_ptr;
            mojo::internal::Serialize<::device::usb::DeviceInfoDataView>(
                in_result, builder.buffer(), &result_ptr, &serialization_context_);
            params->result.Set(result_ptr);
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
        bool ChooserServiceStubDispatch::Accept(
            ChooserService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kChooserService_GetPermission_Name: {
                break;
            }
            }
            return false;
        }

        // static
        bool ChooserServiceStubDispatch::AcceptWithResponder(
            ChooserService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kChooserService_GetPermission_Name: {
                internal::ChooserService_GetPermission_Params_Data* params = reinterpret_cast<internal::ChooserService_GetPermission_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::Vector<::device::usb::blink::DeviceFilterPtr> p_device_filters {};
                ChooserService_GetPermission_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadDeviceFilters(&p_device_filters))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "ChooserService::GetPermission deserializer");
                    return false;
                }
                ChooserService::GetPermissionCallback callback = ChooserService_GetPermission_ProxyToResponder::CreateCallback(
                    message->request_id(),
                    message->has_flag(mojo::Message::kFlagIsSync), responder,
                    context->group_controller);
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "ChooserService::GetPermission");
                mojo::internal::MessageDispatchContext context(message);
                impl->GetPermission(
                    std::move(p_device_filters), std::move(callback));
                return true;
            }
            }
            return false;
        }

        bool ChooserServiceRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "ChooserService RequestValidator");

            switch (message->header()->name) {
            case internal::kChooserService_GetPermission_Name: {
                if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::ChooserService_GetPermission_Params_Data>(
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

        bool ChooserServiceResponseValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "ChooserService ResponseValidator");

            if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
                return false;
            switch (message->header()->name) {
            case internal::kChooserService_GetPermission_Name: {
                if (!mojo::internal::ValidateMessagePayload<
                        internal::ChooserService_GetPermission_ResponseParams_Data>(
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
} // namespace usb
} // namespace device

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif