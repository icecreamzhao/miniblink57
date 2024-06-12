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

#include "services/ui/public/interfaces/user_activity_monitor.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "cc/ipc/begin_frame_args_struct_traits.h"
#include "cc/ipc/compositor_frame_metadata_struct_traits.h"
#include "cc/ipc/compositor_frame_struct_traits.h"
#include "cc/ipc/filter_operation_struct_traits.h"
#include "cc/ipc/filter_operations_struct_traits.h"
#include "cc/ipc/frame_sink_id_struct_traits.h"
#include "cc/ipc/local_frame_id_struct_traits.h"
#include "cc/ipc/quads_struct_traits.h"
#include "cc/ipc/render_pass_struct_traits.h"
#include "cc/ipc/returned_resource_struct_traits.h"
#include "cc/ipc/selection_struct_traits.h"
#include "cc/ipc/shared_quad_state_struct_traits.h"
#include "cc/ipc/surface_id_struct_traits.h"
#include "cc/ipc/surface_info_struct_traits.h"
#include "cc/ipc/surface_reference_struct_traits.h"
#include "cc/ipc/surface_sequence_struct_traits.h"
#include "cc/ipc/transferable_resource_struct_traits.h"
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "services/ui/public/interfaces/ime/ime_struct_traits.h"
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "ui/events/mojo/event_struct_traits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
#include "ui/gfx/range/mojo/range_struct_traits.h"
namespace ui {
namespace mojom {
    const char UserActivityObserver::Name_[] = "ui::mojom::UserActivityObserver";

    UserActivityObserverProxy::UserActivityObserverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void UserActivityObserverProxy::OnUserActivity()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::UserActivityObserver_OnUserActivity_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kUserActivityObserver_OnUserActivity_Name, size);

        auto params = ::ui::mojom::internal::UserActivityObserver_OnUserActivity_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool UserActivityObserverStubDispatch::Accept(
        UserActivityObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kUserActivityObserver_OnUserActivity_Name: {
            internal::UserActivityObserver_OnUserActivity_Params_Data* params = reinterpret_cast<internal::UserActivityObserver_OnUserActivity_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            UserActivityObserver_OnUserActivity_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "UserActivityObserver::OnUserActivity deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "UserActivityObserver::OnUserActivity");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnUserActivity();
            return true;
        }
        }
        return false;
    }

    // static
    bool UserActivityObserverStubDispatch::AcceptWithResponder(
        UserActivityObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kUserActivityObserver_OnUserActivity_Name: {
            break;
        }
        }
        return false;
    }

    bool UserActivityObserverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "UserActivityObserver RequestValidator");

        switch (message->header()->name) {
        case internal::kUserActivityObserver_OnUserActivity_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::UserActivityObserver_OnUserActivity_Params_Data>(
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

    const char UserIdleObserver::Name_[] = "ui::mojom::UserIdleObserver";

    UserIdleObserverProxy::UserIdleObserverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void UserIdleObserverProxy::OnUserIdleStateChanged(
        UserIdleObserver::IdleState in_new_state)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::UserIdleObserver_OnUserIdleStateChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kUserIdleObserver_OnUserIdleStateChanged_Name, size);

        auto params = ::ui::mojom::internal::UserIdleObserver_OnUserIdleStateChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::UserIdleObserver_IdleState>(
            in_new_state, &params->new_state);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool UserIdleObserverStubDispatch::Accept(
        UserIdleObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kUserIdleObserver_OnUserIdleStateChanged_Name: {
            internal::UserIdleObserver_OnUserIdleStateChanged_Params_Data* params = reinterpret_cast<internal::UserIdleObserver_OnUserIdleStateChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            UserIdleObserver::IdleState p_new_state {};
            UserIdleObserver_OnUserIdleStateChanged_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadNewState(&p_new_state))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "UserIdleObserver::OnUserIdleStateChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "UserIdleObserver::OnUserIdleStateChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnUserIdleStateChanged(
                std::move(p_new_state));
            return true;
        }
        }
        return false;
    }

    // static
    bool UserIdleObserverStubDispatch::AcceptWithResponder(
        UserIdleObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kUserIdleObserver_OnUserIdleStateChanged_Name: {
            break;
        }
        }
        return false;
    }

    bool UserIdleObserverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "UserIdleObserver RequestValidator");

        switch (message->header()->name) {
        case internal::kUserIdleObserver_OnUserIdleStateChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::UserIdleObserver_OnUserIdleStateChanged_Params_Data>(
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

    const char UserActivityMonitor::Name_[] = "ui::mojom::UserActivityMonitor";

    UserActivityMonitorProxy::UserActivityMonitorProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void UserActivityMonitorProxy::AddUserActivityObserver(
        uint32_t in_delay_between_notify_secs, UserActivityObserverPtr in_observer)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::UserActivityMonitor_AddUserActivityObserver_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kUserActivityMonitor_AddUserActivityObserver_Name, size);

        auto params = ::ui::mojom::internal::UserActivityMonitor_AddUserActivityObserver_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->delay_between_notify_secs = in_delay_between_notify_secs;
        mojo::internal::Serialize<::ui::mojom::UserActivityObserverPtrDataView>(
            in_observer, &params->observer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->observer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid observer in UserActivityMonitor.AddUserActivityObserver request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void UserActivityMonitorProxy::AddUserIdleObserver(
        uint32_t in_idle_time_in_minutes, UserIdleObserverPtr in_observer)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::UserActivityMonitor_AddUserIdleObserver_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kUserActivityMonitor_AddUserIdleObserver_Name, size);

        auto params = ::ui::mojom::internal::UserActivityMonitor_AddUserIdleObserver_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->idle_time_in_minutes = in_idle_time_in_minutes;
        mojo::internal::Serialize<::ui::mojom::UserIdleObserverPtrDataView>(
            in_observer, &params->observer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->observer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid observer in UserActivityMonitor.AddUserIdleObserver request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool UserActivityMonitorStubDispatch::Accept(
        UserActivityMonitor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kUserActivityMonitor_AddUserActivityObserver_Name: {
            internal::UserActivityMonitor_AddUserActivityObserver_Params_Data* params = reinterpret_cast<internal::UserActivityMonitor_AddUserActivityObserver_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_delay_between_notify_secs {};
            UserActivityObserverPtr p_observer {};
            UserActivityMonitor_AddUserActivityObserver_ParamsDataView input_data_view(params,
                context);

            p_delay_between_notify_secs = input_data_view.delay_between_notify_secs();
            p_observer = input_data_view.TakeObserver<decltype(p_observer)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "UserActivityMonitor::AddUserActivityObserver deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "UserActivityMonitor::AddUserActivityObserver");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddUserActivityObserver(
                std::move(p_delay_between_notify_secs),
                std::move(p_observer));
            return true;
        }
        case internal::kUserActivityMonitor_AddUserIdleObserver_Name: {
            internal::UserActivityMonitor_AddUserIdleObserver_Params_Data* params = reinterpret_cast<internal::UserActivityMonitor_AddUserIdleObserver_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_idle_time_in_minutes {};
            UserIdleObserverPtr p_observer {};
            UserActivityMonitor_AddUserIdleObserver_ParamsDataView input_data_view(params,
                context);

            p_idle_time_in_minutes = input_data_view.idle_time_in_minutes();
            p_observer = input_data_view.TakeObserver<decltype(p_observer)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "UserActivityMonitor::AddUserIdleObserver deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "UserActivityMonitor::AddUserIdleObserver");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddUserIdleObserver(
                std::move(p_idle_time_in_minutes),
                std::move(p_observer));
            return true;
        }
        }
        return false;
    }

    // static
    bool UserActivityMonitorStubDispatch::AcceptWithResponder(
        UserActivityMonitor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kUserActivityMonitor_AddUserActivityObserver_Name: {
            break;
        }
        case internal::kUserActivityMonitor_AddUserIdleObserver_Name: {
            break;
        }
        }
        return false;
    }

    bool UserActivityMonitorRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "UserActivityMonitor RequestValidator");

        switch (message->header()->name) {
        case internal::kUserActivityMonitor_AddUserActivityObserver_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::UserActivityMonitor_AddUserActivityObserver_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kUserActivityMonitor_AddUserIdleObserver_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::UserActivityMonitor_AddUserIdleObserver_Params_Data>(
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
} // namespace ui

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif