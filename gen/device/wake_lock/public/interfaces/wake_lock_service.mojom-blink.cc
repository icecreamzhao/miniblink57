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

#include "device/wake_lock/public/interfaces/wake_lock_service.mojom-blink.h"

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
namespace mojom {
    namespace blink {
        const char WakeLockService::Name_[] = "device::mojom::WakeLockService";

        WakeLockServiceProxy::WakeLockServiceProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void WakeLockServiceProxy::RequestWakeLock()
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::WakeLockService_RequestWakeLock_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kWakeLockService_RequestWakeLock_Name, size);

            auto params = ::device::mojom::internal::WakeLockService_RequestWakeLock_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WakeLockServiceProxy::CancelWakeLock()
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::WakeLockService_CancelWakeLock_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kWakeLockService_CancelWakeLock_Name, size);

            auto params = ::device::mojom::internal::WakeLockService_CancelWakeLock_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool WakeLockServiceStubDispatch::Accept(
            WakeLockService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kWakeLockService_RequestWakeLock_Name: {
                internal::WakeLockService_RequestWakeLock_Params_Data* params = reinterpret_cast<internal::WakeLockService_RequestWakeLock_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WakeLockService_RequestWakeLock_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WakeLockService::RequestWakeLock deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WakeLockService::RequestWakeLock");
                mojo::internal::MessageDispatchContext context(message);
                impl->RequestWakeLock();
                return true;
            }
            case internal::kWakeLockService_CancelWakeLock_Name: {
                internal::WakeLockService_CancelWakeLock_Params_Data* params = reinterpret_cast<internal::WakeLockService_CancelWakeLock_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WakeLockService_CancelWakeLock_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WakeLockService::CancelWakeLock deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WakeLockService::CancelWakeLock");
                mojo::internal::MessageDispatchContext context(message);
                impl->CancelWakeLock();
                return true;
            }
            }
            return false;
        }

        // static
        bool WakeLockServiceStubDispatch::AcceptWithResponder(
            WakeLockService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kWakeLockService_RequestWakeLock_Name: {
                break;
            }
            case internal::kWakeLockService_CancelWakeLock_Name: {
                break;
            }
            }
            return false;
        }

        bool WakeLockServiceRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "WakeLockService RequestValidator");

            switch (message->header()->name) {
            case internal::kWakeLockService_RequestWakeLock_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WakeLockService_RequestWakeLock_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWakeLockService_CancelWakeLock_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WakeLockService_CancelWakeLock_Params_Data>(
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
} // namespace device

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif