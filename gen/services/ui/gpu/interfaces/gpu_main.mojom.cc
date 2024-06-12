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

#include "services/ui/gpu/interfaces/gpu_main.mojom.h"

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
#include "services/ui/gpu/interfaces/context_lost_reason_traits.h"
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
#include "url/mojo/url_gurl_struct_traits.h"
namespace ui {
namespace mojom {
    const char GpuMain::Name_[] = "ui::mojom::GpuMain";

    GpuMainProxy::GpuMainProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void GpuMainProxy::CreateDisplayCompositor(
        ::cc::mojom::DisplayCompositorRequest in_display_compositor, ::cc::mojom::DisplayCompositorClientPtr in_display_compositor_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuMain_CreateDisplayCompositor_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kGpuMain_CreateDisplayCompositor_Name, size);

        auto params = ::ui::mojom::internal::GpuMain_CreateDisplayCompositor_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::cc::mojom::DisplayCompositorRequestDataView>(
            in_display_compositor, &params->display_compositor, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->display_compositor),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid display_compositor in GpuMain.CreateDisplayCompositor request");
        mojo::internal::Serialize<::cc::mojom::DisplayCompositorClientPtrDataView>(
            in_display_compositor_client, &params->display_compositor_client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->display_compositor_client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid display_compositor_client in GpuMain.CreateDisplayCompositor request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void GpuMainProxy::CreateGpuService(
        ::ui::mojom::GpuServiceRequest in_gpu_service, ::ui::mojom::GpuHostPtr in_gpu_host, const gpu::GpuPreferences& in_preferences)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuMain_CreateGpuService_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::GpuPreferencesDataView>(
            in_preferences, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGpuMain_CreateGpuService_Name, size);

        auto params = ::ui::mojom::internal::GpuMain_CreateGpuService_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::GpuServiceRequestDataView>(
            in_gpu_service, &params->gpu_service, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->gpu_service),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid gpu_service in GpuMain.CreateGpuService request");
        mojo::internal::Serialize<::ui::mojom::GpuHostPtrDataView>(
            in_gpu_host, &params->gpu_host, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->gpu_host),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid gpu_host in GpuMain.CreateGpuService request");
        typename decltype(params->preferences)::BaseType* preferences_ptr;
        mojo::internal::Serialize<::gpu::mojom::GpuPreferencesDataView>(
            in_preferences, builder.buffer(), &preferences_ptr, &serialization_context);
        params->preferences.Set(preferences_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->preferences.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null preferences in GpuMain.CreateGpuService request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool GpuMainStubDispatch::Accept(
        GpuMain* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kGpuMain_CreateDisplayCompositor_Name: {
            internal::GpuMain_CreateDisplayCompositor_Params_Data* params = reinterpret_cast<internal::GpuMain_CreateDisplayCompositor_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::cc::mojom::DisplayCompositorRequest p_display_compositor {};
            ::cc::mojom::DisplayCompositorClientPtr p_display_compositor_client {};
            GpuMain_CreateDisplayCompositor_ParamsDataView input_data_view(params,
                context);

            p_display_compositor = input_data_view.TakeDisplayCompositor<decltype(p_display_compositor)>();
            p_display_compositor_client = input_data_view.TakeDisplayCompositorClient<decltype(p_display_compositor_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuMain::CreateDisplayCompositor deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuMain::CreateDisplayCompositor");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateDisplayCompositor(
                std::move(p_display_compositor),
                std::move(p_display_compositor_client));
            return true;
        }
        case internal::kGpuMain_CreateGpuService_Name: {
            internal::GpuMain_CreateGpuService_Params_Data* params = reinterpret_cast<internal::GpuMain_CreateGpuService_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::ui::mojom::GpuServiceRequest p_gpu_service {};
            ::ui::mojom::GpuHostPtr p_gpu_host {};
            gpu::GpuPreferences p_preferences {};
            GpuMain_CreateGpuService_ParamsDataView input_data_view(params,
                context);

            p_gpu_service = input_data_view.TakeGpuService<decltype(p_gpu_service)>();
            p_gpu_host = input_data_view.TakeGpuHost<decltype(p_gpu_host)>();
            if (!input_data_view.ReadPreferences(&p_preferences))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuMain::CreateGpuService deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuMain::CreateGpuService");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateGpuService(
                std::move(p_gpu_service),
                std::move(p_gpu_host),
                std::move(p_preferences));
            return true;
        }
        }
        return false;
    }

    // static
    bool GpuMainStubDispatch::AcceptWithResponder(
        GpuMain* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kGpuMain_CreateDisplayCompositor_Name: {
            break;
        }
        case internal::kGpuMain_CreateGpuService_Name: {
            break;
        }
        }
        return false;
    }

    bool GpuMainRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GpuMain RequestValidator");

        switch (message->header()->name) {
        case internal::kGpuMain_CreateDisplayCompositor_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuMain_CreateDisplayCompositor_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuMain_CreateGpuService_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuMain_CreateGpuService_Params_Data>(
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