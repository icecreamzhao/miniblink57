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

#include "device/power_monitor/public/interfaces/power_monitor.mojom.h"

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
namespace device {
namespace mojom {
    const char PowerMonitor::Name_[] = "device::mojom::PowerMonitor";

    PowerMonitorProxy::PowerMonitorProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PowerMonitorProxy::SetClient(
        PowerMonitorClientPtr in_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::PowerMonitor_SetClient_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPowerMonitor_SetClient_Name, size);

        auto params = ::device::mojom::internal::PowerMonitor_SetClient_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::mojom::PowerMonitorClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in PowerMonitor.SetClient request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool PowerMonitorStubDispatch::Accept(
        PowerMonitor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPowerMonitor_SetClient_Name: {
            internal::PowerMonitor_SetClient_Params_Data* params = reinterpret_cast<internal::PowerMonitor_SetClient_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PowerMonitorClientPtr p_client {};
            PowerMonitor_SetClient_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PowerMonitor::SetClient deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PowerMonitor::SetClient");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetClient(
                std::move(p_client));
            return true;
        }
        }
        return false;
    }

    // static
    bool PowerMonitorStubDispatch::AcceptWithResponder(
        PowerMonitor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPowerMonitor_SetClient_Name: {
            break;
        }
        }
        return false;
    }

    bool PowerMonitorRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PowerMonitor RequestValidator");

        switch (message->header()->name) {
        case internal::kPowerMonitor_SetClient_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PowerMonitor_SetClient_Params_Data>(
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

    const char PowerMonitorClient::Name_[] = "device::mojom::PowerMonitorClient";

    PowerMonitorClientProxy::PowerMonitorClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PowerMonitorClientProxy::PowerStateChange(
        bool in_on_battery_power)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::PowerMonitorClient_PowerStateChange_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPowerMonitorClient_PowerStateChange_Name, size);

        auto params = ::device::mojom::internal::PowerMonitorClient_PowerStateChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->on_battery_power = in_on_battery_power;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PowerMonitorClientProxy::Suspend()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::PowerMonitorClient_Suspend_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPowerMonitorClient_Suspend_Name, size);

        auto params = ::device::mojom::internal::PowerMonitorClient_Suspend_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PowerMonitorClientProxy::Resume()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::PowerMonitorClient_Resume_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPowerMonitorClient_Resume_Name, size);

        auto params = ::device::mojom::internal::PowerMonitorClient_Resume_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool PowerMonitorClientStubDispatch::Accept(
        PowerMonitorClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPowerMonitorClient_PowerStateChange_Name: {
            internal::PowerMonitorClient_PowerStateChange_Params_Data* params = reinterpret_cast<internal::PowerMonitorClient_PowerStateChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_on_battery_power {};
            PowerMonitorClient_PowerStateChange_ParamsDataView input_data_view(params,
                context);

            p_on_battery_power = input_data_view.on_battery_power();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PowerMonitorClient::PowerStateChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PowerMonitorClient::PowerStateChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->PowerStateChange(
                std::move(p_on_battery_power));
            return true;
        }
        case internal::kPowerMonitorClient_Suspend_Name: {
            internal::PowerMonitorClient_Suspend_Params_Data* params = reinterpret_cast<internal::PowerMonitorClient_Suspend_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PowerMonitorClient_Suspend_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PowerMonitorClient::Suspend deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PowerMonitorClient::Suspend");
            mojo::internal::MessageDispatchContext context(message);
            impl->Suspend();
            return true;
        }
        case internal::kPowerMonitorClient_Resume_Name: {
            internal::PowerMonitorClient_Resume_Params_Data* params = reinterpret_cast<internal::PowerMonitorClient_Resume_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PowerMonitorClient_Resume_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PowerMonitorClient::Resume deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PowerMonitorClient::Resume");
            mojo::internal::MessageDispatchContext context(message);
            impl->Resume();
            return true;
        }
        }
        return false;
    }

    // static
    bool PowerMonitorClientStubDispatch::AcceptWithResponder(
        PowerMonitorClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPowerMonitorClient_PowerStateChange_Name: {
            break;
        }
        case internal::kPowerMonitorClient_Suspend_Name: {
            break;
        }
        case internal::kPowerMonitorClient_Resume_Name: {
            break;
        }
        }
        return false;
    }

    bool PowerMonitorClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PowerMonitorClient RequestValidator");

        switch (message->header()->name) {
        case internal::kPowerMonitorClient_PowerStateChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PowerMonitorClient_PowerStateChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPowerMonitorClient_Suspend_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PowerMonitorClient_Suspend_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPowerMonitorClient_Resume_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PowerMonitorClient_Resume_Params_Data>(
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