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

#include "cc/ipc/display_compositor.mojom.h"

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
namespace cc {
namespace mojom {
    const char DisplayPrivate::Name_[] = "cc::mojom::DisplayPrivate";

    DisplayPrivateProxy::DisplayPrivateProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DisplayPrivateProxy::SetDisplayVisible(
        bool in_visible)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::DisplayPrivate_SetDisplayVisible_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayPrivate_SetDisplayVisible_Name, size);

        auto params = ::cc::mojom::internal::DisplayPrivate_SetDisplayVisible_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->visible = in_visible;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayPrivateProxy::ResizeDisplay(
        const gfx::Size& in_size_in_pixel)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::DisplayPrivate_ResizeDisplay_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
            in_size_in_pixel, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDisplayPrivate_ResizeDisplay_Name, size);

        auto params = ::cc::mojom::internal::DisplayPrivate_ResizeDisplay_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->size_in_pixel)::BaseType* size_in_pixel_ptr;
        mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
            in_size_in_pixel, builder.buffer(), &size_in_pixel_ptr, &serialization_context);
        params->size_in_pixel.Set(size_in_pixel_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->size_in_pixel.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null size_in_pixel in DisplayPrivate.ResizeDisplay request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayPrivateProxy::SetDisplayColorSpace(
        const gfx::ColorSpace& in_color_space)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::DisplayPrivate_SetDisplayColorSpace_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::ColorSpaceDataView>(
            in_color_space, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDisplayPrivate_SetDisplayColorSpace_Name, size);

        auto params = ::cc::mojom::internal::DisplayPrivate_SetDisplayColorSpace_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->color_space)::BaseType* color_space_ptr;
        mojo::internal::Serialize<::gfx::mojom::ColorSpaceDataView>(
            in_color_space, builder.buffer(), &color_space_ptr, &serialization_context);
        params->color_space.Set(color_space_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->color_space.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null color_space in DisplayPrivate.SetDisplayColorSpace request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayPrivateProxy::SetOutputIsSecure(
        bool in_secure)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::DisplayPrivate_SetOutputIsSecure_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDisplayPrivate_SetOutputIsSecure_Name, size);

        auto params = ::cc::mojom::internal::DisplayPrivate_SetOutputIsSecure_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->secure = in_secure;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DisplayPrivateStubDispatch::Accept(
        DisplayPrivate* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDisplayPrivate_SetDisplayVisible_Name: {
            internal::DisplayPrivate_SetDisplayVisible_Params_Data* params = reinterpret_cast<internal::DisplayPrivate_SetDisplayVisible_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_visible {};
            DisplayPrivate_SetDisplayVisible_ParamsDataView input_data_view(params,
                context);

            p_visible = input_data_view.visible();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayPrivate::SetDisplayVisible deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayPrivate::SetDisplayVisible");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetDisplayVisible(
                std::move(p_visible));
            return true;
        }
        case internal::kDisplayPrivate_ResizeDisplay_Name: {
            internal::DisplayPrivate_ResizeDisplay_Params_Data* params = reinterpret_cast<internal::DisplayPrivate_ResizeDisplay_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gfx::Size p_size_in_pixel {};
            DisplayPrivate_ResizeDisplay_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSizeInPixel(&p_size_in_pixel))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayPrivate::ResizeDisplay deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayPrivate::ResizeDisplay");
            mojo::internal::MessageDispatchContext context(message);
            impl->ResizeDisplay(
                std::move(p_size_in_pixel));
            return true;
        }
        case internal::kDisplayPrivate_SetDisplayColorSpace_Name: {
            internal::DisplayPrivate_SetDisplayColorSpace_Params_Data* params = reinterpret_cast<internal::DisplayPrivate_SetDisplayColorSpace_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gfx::ColorSpace p_color_space {};
            DisplayPrivate_SetDisplayColorSpace_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadColorSpace(&p_color_space))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayPrivate::SetDisplayColorSpace deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayPrivate::SetDisplayColorSpace");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetDisplayColorSpace(
                std::move(p_color_space));
            return true;
        }
        case internal::kDisplayPrivate_SetOutputIsSecure_Name: {
            internal::DisplayPrivate_SetOutputIsSecure_Params_Data* params = reinterpret_cast<internal::DisplayPrivate_SetOutputIsSecure_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_secure {};
            DisplayPrivate_SetOutputIsSecure_ParamsDataView input_data_view(params,
                context);

            p_secure = input_data_view.secure();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayPrivate::SetOutputIsSecure deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayPrivate::SetOutputIsSecure");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetOutputIsSecure(
                std::move(p_secure));
            return true;
        }
        }
        return false;
    }

    // static
    bool DisplayPrivateStubDispatch::AcceptWithResponder(
        DisplayPrivate* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDisplayPrivate_SetDisplayVisible_Name: {
            break;
        }
        case internal::kDisplayPrivate_ResizeDisplay_Name: {
            break;
        }
        case internal::kDisplayPrivate_SetDisplayColorSpace_Name: {
            break;
        }
        case internal::kDisplayPrivate_SetOutputIsSecure_Name: {
            break;
        }
        }
        return false;
    }

    bool DisplayPrivateRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DisplayPrivate RequestValidator");

        switch (message->header()->name) {
        case internal::kDisplayPrivate_SetDisplayVisible_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayPrivate_SetDisplayVisible_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayPrivate_ResizeDisplay_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayPrivate_ResizeDisplay_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayPrivate_SetDisplayColorSpace_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayPrivate_SetDisplayColorSpace_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayPrivate_SetOutputIsSecure_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayPrivate_SetOutputIsSecure_Params_Data>(
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

    const char DisplayCompositor::Name_[] = "cc::mojom::DisplayCompositor";

    DisplayCompositorProxy::DisplayCompositorProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DisplayCompositorProxy::CreateDisplayCompositorFrameSink(
        const cc::FrameSinkId& in_frame_sink_id, ::gpu::SurfaceHandle in_widget, ::cc::mojom::MojoCompositorFrameSinkRequest in_compositor_frame_sink, ::cc::mojom::MojoCompositorFrameSinkPrivateRequest in_compositor_frame_sink_private, ::cc::mojom::MojoCompositorFrameSinkClientPtr in_compositor_frame_sink_client, DisplayPrivateRequest in_display_private)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::FrameSinkIdDataView>(
            in_frame_sink_id, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::SurfaceHandleDataView>(
            in_widget, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDisplayCompositor_CreateDisplayCompositorFrameSink_Name, size);

        auto params = ::cc::mojom::internal::DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->frame_sink_id)::BaseType* frame_sink_id_ptr;
        mojo::internal::Serialize<::cc::mojom::FrameSinkIdDataView>(
            in_frame_sink_id, builder.buffer(), &frame_sink_id_ptr, &serialization_context);
        params->frame_sink_id.Set(frame_sink_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->frame_sink_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null frame_sink_id in DisplayCompositor.CreateDisplayCompositorFrameSink request");
        typename decltype(params->widget)::BaseType* widget_ptr;
        mojo::internal::Serialize<::gpu::mojom::SurfaceHandleDataView>(
            in_widget, builder.buffer(), &widget_ptr, &serialization_context);
        params->widget.Set(widget_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->widget.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null widget in DisplayCompositor.CreateDisplayCompositorFrameSink request");
        mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkRequestDataView>(
            in_compositor_frame_sink, &params->compositor_frame_sink, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->compositor_frame_sink),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid compositor_frame_sink in DisplayCompositor.CreateDisplayCompositorFrameSink request");
        mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkPrivateRequestDataView>(
            in_compositor_frame_sink_private, &params->compositor_frame_sink_private, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->compositor_frame_sink_private),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid compositor_frame_sink_private in DisplayCompositor.CreateDisplayCompositorFrameSink request");
        mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkClientPtrDataView>(
            in_compositor_frame_sink_client, &params->compositor_frame_sink_client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->compositor_frame_sink_client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid compositor_frame_sink_client in DisplayCompositor.CreateDisplayCompositorFrameSink request");
        mojo::internal::Serialize<::cc::mojom::DisplayPrivateRequestDataView>(
            in_display_private, &params->display_private, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->display_private),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid display_private in DisplayCompositor.CreateDisplayCompositorFrameSink request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DisplayCompositorProxy::CreateOffscreenCompositorFrameSink(
        const cc::FrameSinkId& in_frame_sink_id, ::cc::mojom::MojoCompositorFrameSinkRequest in_compositor_frame_sink, ::cc::mojom::MojoCompositorFrameSinkPrivateRequest in_compositor_frame_sink_private, ::cc::mojom::MojoCompositorFrameSinkClientPtr in_compositor_frame_sink_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::FrameSinkIdDataView>(
            in_frame_sink_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDisplayCompositor_CreateOffscreenCompositorFrameSink_Name, size);

        auto params = ::cc::mojom::internal::DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->frame_sink_id)::BaseType* frame_sink_id_ptr;
        mojo::internal::Serialize<::cc::mojom::FrameSinkIdDataView>(
            in_frame_sink_id, builder.buffer(), &frame_sink_id_ptr, &serialization_context);
        params->frame_sink_id.Set(frame_sink_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->frame_sink_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null frame_sink_id in DisplayCompositor.CreateOffscreenCompositorFrameSink request");
        mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkRequestDataView>(
            in_compositor_frame_sink, &params->compositor_frame_sink, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->compositor_frame_sink),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid compositor_frame_sink in DisplayCompositor.CreateOffscreenCompositorFrameSink request");
        mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkPrivateRequestDataView>(
            in_compositor_frame_sink_private, &params->compositor_frame_sink_private, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->compositor_frame_sink_private),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid compositor_frame_sink_private in DisplayCompositor.CreateOffscreenCompositorFrameSink request");
        mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkClientPtrDataView>(
            in_compositor_frame_sink_client, &params->compositor_frame_sink_client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->compositor_frame_sink_client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid compositor_frame_sink_client in DisplayCompositor.CreateOffscreenCompositorFrameSink request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DisplayCompositorStubDispatch::Accept(
        DisplayCompositor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDisplayCompositor_CreateDisplayCompositorFrameSink_Name: {
            internal::DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data* params = reinterpret_cast<internal::DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::FrameSinkId p_frame_sink_id {};
            ::gpu::SurfaceHandle p_widget {};
            ::cc::mojom::MojoCompositorFrameSinkRequest p_compositor_frame_sink {};
            ::cc::mojom::MojoCompositorFrameSinkPrivateRequest p_compositor_frame_sink_private {};
            ::cc::mojom::MojoCompositorFrameSinkClientPtr p_compositor_frame_sink_client {};
            DisplayPrivateRequest p_display_private {};
            DisplayCompositor_CreateDisplayCompositorFrameSink_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadFrameSinkId(&p_frame_sink_id))
                success = false;
            if (!input_data_view.ReadWidget(&p_widget))
                success = false;
            p_compositor_frame_sink = input_data_view.TakeCompositorFrameSink<decltype(p_compositor_frame_sink)>();
            p_compositor_frame_sink_private = input_data_view.TakeCompositorFrameSinkPrivate<decltype(p_compositor_frame_sink_private)>();
            p_compositor_frame_sink_client = input_data_view.TakeCompositorFrameSinkClient<decltype(p_compositor_frame_sink_client)>();
            p_display_private = input_data_view.TakeDisplayPrivate<decltype(p_display_private)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayCompositor::CreateDisplayCompositorFrameSink deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayCompositor::CreateDisplayCompositorFrameSink");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateDisplayCompositorFrameSink(
                std::move(p_frame_sink_id),
                std::move(p_widget),
                std::move(p_compositor_frame_sink),
                std::move(p_compositor_frame_sink_private),
                std::move(p_compositor_frame_sink_client),
                std::move(p_display_private));
            return true;
        }
        case internal::kDisplayCompositor_CreateOffscreenCompositorFrameSink_Name: {
            internal::DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data* params = reinterpret_cast<internal::DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::FrameSinkId p_frame_sink_id {};
            ::cc::mojom::MojoCompositorFrameSinkRequest p_compositor_frame_sink {};
            ::cc::mojom::MojoCompositorFrameSinkPrivateRequest p_compositor_frame_sink_private {};
            ::cc::mojom::MojoCompositorFrameSinkClientPtr p_compositor_frame_sink_client {};
            DisplayCompositor_CreateOffscreenCompositorFrameSink_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadFrameSinkId(&p_frame_sink_id))
                success = false;
            p_compositor_frame_sink = input_data_view.TakeCompositorFrameSink<decltype(p_compositor_frame_sink)>();
            p_compositor_frame_sink_private = input_data_view.TakeCompositorFrameSinkPrivate<decltype(p_compositor_frame_sink_private)>();
            p_compositor_frame_sink_client = input_data_view.TakeCompositorFrameSinkClient<decltype(p_compositor_frame_sink_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayCompositor::CreateOffscreenCompositorFrameSink deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayCompositor::CreateOffscreenCompositorFrameSink");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateOffscreenCompositorFrameSink(
                std::move(p_frame_sink_id),
                std::move(p_compositor_frame_sink),
                std::move(p_compositor_frame_sink_private),
                std::move(p_compositor_frame_sink_client));
            return true;
        }
        }
        return false;
    }

    // static
    bool DisplayCompositorStubDispatch::AcceptWithResponder(
        DisplayCompositor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDisplayCompositor_CreateDisplayCompositorFrameSink_Name: {
            break;
        }
        case internal::kDisplayCompositor_CreateOffscreenCompositorFrameSink_Name: {
            break;
        }
        }
        return false;
    }

    bool DisplayCompositorRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DisplayCompositor RequestValidator");

        switch (message->header()->name) {
        case internal::kDisplayCompositor_CreateDisplayCompositorFrameSink_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDisplayCompositor_CreateOffscreenCompositorFrameSink_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data>(
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

    const char DisplayCompositorClient::Name_[] = "cc::mojom::DisplayCompositorClient";

    DisplayCompositorClientProxy::DisplayCompositorClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DisplayCompositorClientProxy::OnSurfaceCreated(
        const cc::SurfaceInfo& in_surface_info)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::DisplayCompositorClient_OnSurfaceCreated_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceInfoDataView>(
            in_surface_info, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDisplayCompositorClient_OnSurfaceCreated_Name, size);

        auto params = ::cc::mojom::internal::DisplayCompositorClient_OnSurfaceCreated_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->surface_info)::BaseType* surface_info_ptr;
        mojo::internal::Serialize<::cc::mojom::SurfaceInfoDataView>(
            in_surface_info, builder.buffer(), &surface_info_ptr, &serialization_context);
        params->surface_info.Set(surface_info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->surface_info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null surface_info in DisplayCompositorClient.OnSurfaceCreated request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DisplayCompositorClientStubDispatch::Accept(
        DisplayCompositorClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDisplayCompositorClient_OnSurfaceCreated_Name: {
            internal::DisplayCompositorClient_OnSurfaceCreated_Params_Data* params = reinterpret_cast<internal::DisplayCompositorClient_OnSurfaceCreated_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::SurfaceInfo p_surface_info {};
            DisplayCompositorClient_OnSurfaceCreated_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSurfaceInfo(&p_surface_info))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DisplayCompositorClient::OnSurfaceCreated deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DisplayCompositorClient::OnSurfaceCreated");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnSurfaceCreated(
                std::move(p_surface_info));
            return true;
        }
        }
        return false;
    }

    // static
    bool DisplayCompositorClientStubDispatch::AcceptWithResponder(
        DisplayCompositorClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDisplayCompositorClient_OnSurfaceCreated_Name: {
            break;
        }
        }
        return false;
    }

    bool DisplayCompositorClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DisplayCompositorClient RequestValidator");

        switch (message->header()->name) {
        case internal::kDisplayCompositorClient_OnSurfaceCreated_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DisplayCompositorClient_OnSurfaceCreated_Params_Data>(
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
} // namespace cc

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif