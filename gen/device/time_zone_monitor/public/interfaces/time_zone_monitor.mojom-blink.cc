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

#include "device/time_zone_monitor/public/interfaces/time_zone_monitor.mojom-blink.h"

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
        const char TimeZoneMonitor::Name_[] = "device::mojom::TimeZoneMonitor";

        TimeZoneMonitorProxy::TimeZoneMonitorProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void TimeZoneMonitorProxy::AddClient(
            TimeZoneMonitorClientPtr in_client)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::TimeZoneMonitor_AddClient_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kTimeZoneMonitor_AddClient_Name, size);

            auto params = ::device::mojom::internal::TimeZoneMonitor_AddClient_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::device::mojom::TimeZoneMonitorClientPtrDataView>(
                in_client, &params->client, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->client),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid client in TimeZoneMonitor.AddClient request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool TimeZoneMonitorStubDispatch::Accept(
            TimeZoneMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kTimeZoneMonitor_AddClient_Name: {
                internal::TimeZoneMonitor_AddClient_Params_Data* params = reinterpret_cast<internal::TimeZoneMonitor_AddClient_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                TimeZoneMonitorClientPtr p_client {};
                TimeZoneMonitor_AddClient_ParamsDataView input_data_view(params,
                    context);

                p_client = input_data_view.TakeClient<decltype(p_client)>();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "TimeZoneMonitor::AddClient deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "TimeZoneMonitor::AddClient");
                mojo::internal::MessageDispatchContext context(message);
                impl->AddClient(
                    std::move(p_client));
                return true;
            }
            }
            return false;
        }

        // static
        bool TimeZoneMonitorStubDispatch::AcceptWithResponder(
            TimeZoneMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kTimeZoneMonitor_AddClient_Name: {
                break;
            }
            }
            return false;
        }

        bool TimeZoneMonitorRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "TimeZoneMonitor RequestValidator");

            switch (message->header()->name) {
            case internal::kTimeZoneMonitor_AddClient_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::TimeZoneMonitor_AddClient_Params_Data>(
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

        const char TimeZoneMonitorClient::Name_[] = "device::mojom::TimeZoneMonitorClient";

        TimeZoneMonitorClientProxy::TimeZoneMonitorClientProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void TimeZoneMonitorClientProxy::OnTimeZoneChange(
            const WTF::String& in_tz_info)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::device::mojom::internal::TimeZoneMonitorClient_OnTimeZoneChange_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_tz_info, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kTimeZoneMonitorClient_OnTimeZoneChange_Name, size);

            auto params = ::device::mojom::internal::TimeZoneMonitorClient_OnTimeZoneChange_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->tz_info)::BaseType* tz_info_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_tz_info, builder.buffer(), &tz_info_ptr, &serialization_context);
            params->tz_info.Set(tz_info_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->tz_info.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null tz_info in TimeZoneMonitorClient.OnTimeZoneChange request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool TimeZoneMonitorClientStubDispatch::Accept(
            TimeZoneMonitorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kTimeZoneMonitorClient_OnTimeZoneChange_Name: {
                internal::TimeZoneMonitorClient_OnTimeZoneChange_Params_Data* params = reinterpret_cast<internal::TimeZoneMonitorClient_OnTimeZoneChange_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_tz_info {};
                TimeZoneMonitorClient_OnTimeZoneChange_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadTzInfo(&p_tz_info))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "TimeZoneMonitorClient::OnTimeZoneChange deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "TimeZoneMonitorClient::OnTimeZoneChange");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnTimeZoneChange(
                    std::move(p_tz_info));
                return true;
            }
            }
            return false;
        }

        // static
        bool TimeZoneMonitorClientStubDispatch::AcceptWithResponder(
            TimeZoneMonitorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kTimeZoneMonitorClient_OnTimeZoneChange_Name: {
                break;
            }
            }
            return false;
        }

        bool TimeZoneMonitorClientRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "TimeZoneMonitorClient RequestValidator");

            switch (message->header()->name) {
            case internal::kTimeZoneMonitorClient_OnTimeZoneChange_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::TimeZoneMonitorClient_OnTimeZoneChange_Params_Data>(
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