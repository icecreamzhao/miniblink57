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

#include "services/ui/public/interfaces/display_manager.mojom.h"

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
    const char DisplayManagerObserver::Name_[] = "ui::mojom::DisplayManagerObserver";

    DisplayManagerObserverProxy::DisplayManagerObserverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DisplayManagerObserverProxy::OnDisplays(
        std::vector<::ui::mojom::WsDisplayPtr> in_displays, int64_t in_primary_display_id, int64_t in_internal_display_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::DisplayManagerObserver_OnDisplays_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>>(
            in_displays, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDisplayManagerObserver_OnDisplays_Name, size);

        auto params = ::ui::mojom::internal::DisplayManagerObserver_OnDisplays_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->displays)::BaseType* displays_ptr;
        const mojo::internal::ContainerValidateParams displays_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>>(
            in_displays, builder.buffer(), &displays_ptr, &displays_validate_params,
            &serialization_context);
        params->displays.Set(displays_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->displays.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null displays in DisplayManagerObserver.OnDisplays request");
        params->primary_display_id = in_primary_display_id;
        params->internal_display_id = in_internal_display_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayManagerObserverProxy::OnDisplaysChanged(
        std::vector<::ui::mojom::WsDisplayPtr> in_displays)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::DisplayManagerObserver_OnDisplaysChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>>(
            in_displays, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDisplayManagerObserver_OnDisplaysChanged_Name, size);

        auto params = ::ui::mojom::internal::DisplayManagerObserver_OnDisplaysChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->displays)::BaseType* displays_ptr;
        const mojo::internal::ContainerValidateParams displays_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>>(
            in_displays, builder.buffer(), &displays_ptr, &displays_validate_params,
            &serialization_context);
        params->displays.Set(displays_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->displays.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null displays in DisplayManagerObserver.OnDisplaysChanged request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayManagerObserverProxy::OnDisplayRemoved(
        int64_t in_display_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::DisplayManagerObserver_OnDisplayRemoved_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayManagerObserver_OnDisplayRemoved_Name, size);

        auto params = ::ui::mojom::internal::DisplayManagerObserver_OnDisplayRemoved_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->display_id = in_display_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayManagerObserverProxy::OnPrimaryDisplayChanged(
        int64_t in_primary_display_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayManagerObserver_OnPrimaryDisplayChanged_Name, size);

        auto params = ::ui::mojom::internal::DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->primary_display_id = in_primary_display_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DisplayManagerObserverStubDispatch::Accept(
        DisplayManagerObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDisplayManagerObserver_OnDisplays_Name: {
            internal::DisplayManagerObserver_OnDisplays_Params_Data* params = reinterpret_cast<internal::DisplayManagerObserver_OnDisplays_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<::ui::mojom::WsDisplayPtr> p_displays {};
            int64_t p_primary_display_id {};
            int64_t p_internal_display_id {};
            DisplayManagerObserver_OnDisplays_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDisplays(&p_displays))
                success = false;
            p_primary_display_id = input_data_view.primary_display_id();
            p_internal_display_id = input_data_view.internal_display_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayManagerObserver::OnDisplays deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayManagerObserver::OnDisplays");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDisplays(
                std::move(p_displays),
                std::move(p_primary_display_id),
                std::move(p_internal_display_id));
            return true;
        }
        case internal::kDisplayManagerObserver_OnDisplaysChanged_Name: {
            internal::DisplayManagerObserver_OnDisplaysChanged_Params_Data* params = reinterpret_cast<internal::DisplayManagerObserver_OnDisplaysChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<::ui::mojom::WsDisplayPtr> p_displays {};
            DisplayManagerObserver_OnDisplaysChanged_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDisplays(&p_displays))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayManagerObserver::OnDisplaysChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayManagerObserver::OnDisplaysChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDisplaysChanged(
                std::move(p_displays));
            return true;
        }
        case internal::kDisplayManagerObserver_OnDisplayRemoved_Name: {
            internal::DisplayManagerObserver_OnDisplayRemoved_Params_Data* params = reinterpret_cast<internal::DisplayManagerObserver_OnDisplayRemoved_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_display_id {};
            DisplayManagerObserver_OnDisplayRemoved_ParamsDataView input_data_view(params,
                context);

            p_display_id = input_data_view.display_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayManagerObserver::OnDisplayRemoved deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayManagerObserver::OnDisplayRemoved");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDisplayRemoved(
                std::move(p_display_id));
            return true;
        }
        case internal::kDisplayManagerObserver_OnPrimaryDisplayChanged_Name: {
            internal::DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data* params = reinterpret_cast<internal::DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_primary_display_id {};
            DisplayManagerObserver_OnPrimaryDisplayChanged_ParamsDataView input_data_view(params,
                context);

            p_primary_display_id = input_data_view.primary_display_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayManagerObserver::OnPrimaryDisplayChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayManagerObserver::OnPrimaryDisplayChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnPrimaryDisplayChanged(
                std::move(p_primary_display_id));
            return true;
        }
        }
        return false;
    }

    // static
    bool DisplayManagerObserverStubDispatch::AcceptWithResponder(
        DisplayManagerObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDisplayManagerObserver_OnDisplays_Name: {
            break;
        }
        case internal::kDisplayManagerObserver_OnDisplaysChanged_Name: {
            break;
        }
        case internal::kDisplayManagerObserver_OnDisplayRemoved_Name: {
            break;
        }
        case internal::kDisplayManagerObserver_OnPrimaryDisplayChanged_Name: {
            break;
        }
        }
        return false;
    }

    bool DisplayManagerObserverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DisplayManagerObserver RequestValidator");

        switch (message->header()->name) {
        case internal::kDisplayManagerObserver_OnDisplays_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayManagerObserver_OnDisplays_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayManagerObserver_OnDisplaysChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayManagerObserver_OnDisplaysChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayManagerObserver_OnDisplayRemoved_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayManagerObserver_OnDisplayRemoved_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayManagerObserver_OnPrimaryDisplayChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data>(
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

    const char DisplayManager::Name_[] = "ui::mojom::DisplayManager";

    DisplayManagerProxy::DisplayManagerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DisplayManagerProxy::AddObserver(
        DisplayManagerObserverPtr in_observer)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::DisplayManager_AddObserver_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayManager_AddObserver_Name, size);

        auto params = ::ui::mojom::internal::DisplayManager_AddObserver_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::DisplayManagerObserverPtrDataView>(
            in_observer, &params->observer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->observer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid observer in DisplayManager.AddObserver request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DisplayManagerStubDispatch::Accept(
        DisplayManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDisplayManager_AddObserver_Name: {
            internal::DisplayManager_AddObserver_Params_Data* params = reinterpret_cast<internal::DisplayManager_AddObserver_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DisplayManagerObserverPtr p_observer {};
            DisplayManager_AddObserver_ParamsDataView input_data_view(params,
                context);

            p_observer = input_data_view.TakeObserver<decltype(p_observer)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayManager::AddObserver deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayManager::AddObserver");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddObserver(
                std::move(p_observer));
            return true;
        }
        }
        return false;
    }

    // static
    bool DisplayManagerStubDispatch::AcceptWithResponder(
        DisplayManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDisplayManager_AddObserver_Name: {
            break;
        }
        }
        return false;
    }

    bool DisplayManagerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DisplayManager RequestValidator");

        switch (message->header()->name) {
        case internal::kDisplayManager_AddObserver_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayManager_AddObserver_Params_Data>(
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