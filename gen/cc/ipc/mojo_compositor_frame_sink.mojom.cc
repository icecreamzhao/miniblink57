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

#include "cc/ipc/mojo_compositor_frame_sink.mojom.h"

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
    const char MojoCompositorFrameSink::Name_[] = "cc::mojom::MojoCompositorFrameSink";

    MojoCompositorFrameSinkProxy::MojoCompositorFrameSinkProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void MojoCompositorFrameSinkProxy::SetNeedsBeginFrame(
        bool in_needs_begin_frame)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSink_SetNeedsBeginFrame_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->needs_begin_frame = in_needs_begin_frame;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MojoCompositorFrameSinkProxy::SubmitCompositorFrame(
        const cc::LocalFrameId& in_local_frame_id, cc::CompositorFrame in_frame)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::LocalFrameIdDataView>(
            in_local_frame_id, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::CompositorFrameDataView>(
            in_frame, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSink_SubmitCompositorFrame_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->local_frame_id)::BaseType* local_frame_id_ptr;
        mojo::internal::Serialize<::cc::mojom::LocalFrameIdDataView>(
            in_local_frame_id, builder.buffer(), &local_frame_id_ptr, &serialization_context);
        params->local_frame_id.Set(local_frame_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->local_frame_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null local_frame_id in MojoCompositorFrameSink.SubmitCompositorFrame request");
        typename decltype(params->frame)::BaseType* frame_ptr;
        mojo::internal::Serialize<::cc::mojom::CompositorFrameDataView>(
            in_frame, builder.buffer(), &frame_ptr, &serialization_context);
        params->frame.Set(frame_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->frame.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null frame in MojoCompositorFrameSink.SubmitCompositorFrame request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MojoCompositorFrameSinkProxy::EvictFrame()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSink_EvictFrame_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSink_EvictFrame_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSink_EvictFrame_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MojoCompositorFrameSinkProxy::Require(
        const cc::LocalFrameId& in_local_frame_id, const cc::SurfaceSequence& in_sequence)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSink_Require_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::LocalFrameIdDataView>(
            in_local_frame_id, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceSequenceDataView>(
            in_sequence, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSink_Require_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSink_Require_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->local_frame_id)::BaseType* local_frame_id_ptr;
        mojo::internal::Serialize<::cc::mojom::LocalFrameIdDataView>(
            in_local_frame_id, builder.buffer(), &local_frame_id_ptr, &serialization_context);
        params->local_frame_id.Set(local_frame_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->local_frame_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null local_frame_id in MojoCompositorFrameSink.Require request");
        typename decltype(params->sequence)::BaseType* sequence_ptr;
        mojo::internal::Serialize<::cc::mojom::SurfaceSequenceDataView>(
            in_sequence, builder.buffer(), &sequence_ptr, &serialization_context);
        params->sequence.Set(sequence_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->sequence.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null sequence in MojoCompositorFrameSink.Require request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MojoCompositorFrameSinkProxy::Satisfy(
        const cc::SurfaceSequence& in_sequence)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSink_Satisfy_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceSequenceDataView>(
            in_sequence, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSink_Satisfy_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSink_Satisfy_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->sequence)::BaseType* sequence_ptr;
        mojo::internal::Serialize<::cc::mojom::SurfaceSequenceDataView>(
            in_sequence, builder.buffer(), &sequence_ptr, &serialization_context);
        params->sequence.Set(sequence_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->sequence.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null sequence in MojoCompositorFrameSink.Satisfy request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool MojoCompositorFrameSinkStubDispatch::Accept(
        MojoCompositorFrameSink* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kMojoCompositorFrameSink_SetNeedsBeginFrame_Name: {
            internal::MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_needs_begin_frame {};
            MojoCompositorFrameSink_SetNeedsBeginFrame_ParamsDataView input_data_view(params,
                context);

            p_needs_begin_frame = input_data_view.needs_begin_frame();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSink::SetNeedsBeginFrame deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSink::SetNeedsBeginFrame");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetNeedsBeginFrame(
                std::move(p_needs_begin_frame));
            return true;
        }
        case internal::kMojoCompositorFrameSink_SubmitCompositorFrame_Name: {
            internal::MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::LocalFrameId p_local_frame_id {};
            cc::CompositorFrame p_frame {};
            MojoCompositorFrameSink_SubmitCompositorFrame_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadLocalFrameId(&p_local_frame_id))
                success = false;
            if (!input_data_view.ReadFrame(&p_frame))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSink::SubmitCompositorFrame deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSink::SubmitCompositorFrame");
            mojo::internal::MessageDispatchContext context(message);
            impl->SubmitCompositorFrame(
                std::move(p_local_frame_id),
                std::move(p_frame));
            return true;
        }
        case internal::kMojoCompositorFrameSink_EvictFrame_Name: {
            internal::MojoCompositorFrameSink_EvictFrame_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSink_EvictFrame_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            MojoCompositorFrameSink_EvictFrame_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSink::EvictFrame deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSink::EvictFrame");
            mojo::internal::MessageDispatchContext context(message);
            impl->EvictFrame();
            return true;
        }
        case internal::kMojoCompositorFrameSink_Require_Name: {
            internal::MojoCompositorFrameSink_Require_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSink_Require_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::LocalFrameId p_local_frame_id {};
            cc::SurfaceSequence p_sequence {};
            MojoCompositorFrameSink_Require_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadLocalFrameId(&p_local_frame_id))
                success = false;
            if (!input_data_view.ReadSequence(&p_sequence))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSink::Require deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSink::Require");
            mojo::internal::MessageDispatchContext context(message);
            impl->Require(
                std::move(p_local_frame_id),
                std::move(p_sequence));
            return true;
        }
        case internal::kMojoCompositorFrameSink_Satisfy_Name: {
            internal::MojoCompositorFrameSink_Satisfy_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSink_Satisfy_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::SurfaceSequence p_sequence {};
            MojoCompositorFrameSink_Satisfy_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSequence(&p_sequence))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSink::Satisfy deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSink::Satisfy");
            mojo::internal::MessageDispatchContext context(message);
            impl->Satisfy(
                std::move(p_sequence));
            return true;
        }
        }
        return false;
    }

    // static
    bool MojoCompositorFrameSinkStubDispatch::AcceptWithResponder(
        MojoCompositorFrameSink* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kMojoCompositorFrameSink_SetNeedsBeginFrame_Name: {
            break;
        }
        case internal::kMojoCompositorFrameSink_SubmitCompositorFrame_Name: {
            break;
        }
        case internal::kMojoCompositorFrameSink_EvictFrame_Name: {
            break;
        }
        case internal::kMojoCompositorFrameSink_Require_Name: {
            break;
        }
        case internal::kMojoCompositorFrameSink_Satisfy_Name: {
            break;
        }
        }
        return false;
    }

    bool MojoCompositorFrameSinkRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "MojoCompositorFrameSink RequestValidator");

        switch (message->header()->name) {
        case internal::kMojoCompositorFrameSink_SetNeedsBeginFrame_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSink_SetNeedsBeginFrame_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMojoCompositorFrameSink_SubmitCompositorFrame_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSink_SubmitCompositorFrame_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMojoCompositorFrameSink_EvictFrame_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSink_EvictFrame_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMojoCompositorFrameSink_Require_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSink_Require_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMojoCompositorFrameSink_Satisfy_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSink_Satisfy_Params_Data>(
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

    const char MojoCompositorFrameSinkClient::Name_[] = "cc::mojom::MojoCompositorFrameSinkClient";

    MojoCompositorFrameSinkClientProxy::MojoCompositorFrameSinkClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void MojoCompositorFrameSinkClientProxy::DidReceiveCompositorFrameAck()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MojoCompositorFrameSinkClientProxy::OnBeginFrame(
        const cc::BeginFrameArgs& in_args)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::BeginFrameArgsDataView>(
            in_args, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSinkClient_OnBeginFrame_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->args)::BaseType* args_ptr;
        mojo::internal::Serialize<::cc::mojom::BeginFrameArgsDataView>(
            in_args, builder.buffer(), &args_ptr, &serialization_context);
        params->args.Set(args_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->args.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null args in MojoCompositorFrameSinkClient.OnBeginFrame request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MojoCompositorFrameSinkClientProxy::ReclaimResources(
        const cc::ReturnedResourceArray& in_resources)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSinkClient_ReclaimResources_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::ReturnedResourceArrayDataView>(
            in_resources, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSinkClient_ReclaimResources_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSinkClient_ReclaimResources_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->resources)::BaseType* resources_ptr;
        mojo::internal::Serialize<::cc::mojom::ReturnedResourceArrayDataView>(
            in_resources, builder.buffer(), &resources_ptr, &serialization_context);
        params->resources.Set(resources_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->resources.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null resources in MojoCompositorFrameSinkClient.ReclaimResources request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MojoCompositorFrameSinkClientProxy::WillDrawSurface()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSinkClient_WillDrawSurface_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool MojoCompositorFrameSinkClientStubDispatch::Accept(
        MojoCompositorFrameSinkClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kMojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Name: {
            internal::MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSinkClient::DidReceiveCompositorFrameAck deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSinkClient::DidReceiveCompositorFrameAck");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidReceiveCompositorFrameAck();
            return true;
        }
        case internal::kMojoCompositorFrameSinkClient_OnBeginFrame_Name: {
            internal::MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::BeginFrameArgs p_args {};
            MojoCompositorFrameSinkClient_OnBeginFrame_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadArgs(&p_args))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSinkClient::OnBeginFrame deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSinkClient::OnBeginFrame");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnBeginFrame(
                std::move(p_args));
            return true;
        }
        case internal::kMojoCompositorFrameSinkClient_ReclaimResources_Name: {
            internal::MojoCompositorFrameSinkClient_ReclaimResources_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSinkClient_ReclaimResources_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::ReturnedResourceArray p_resources {};
            MojoCompositorFrameSinkClient_ReclaimResources_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadResources(&p_resources))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSinkClient::ReclaimResources deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSinkClient::ReclaimResources");
            mojo::internal::MessageDispatchContext context(message);
            impl->ReclaimResources(
                std::move(p_resources));
            return true;
        }
        case internal::kMojoCompositorFrameSinkClient_WillDrawSurface_Name: {
            internal::MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            MojoCompositorFrameSinkClient_WillDrawSurface_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSinkClient::WillDrawSurface deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSinkClient::WillDrawSurface");
            mojo::internal::MessageDispatchContext context(message);
            impl->WillDrawSurface();
            return true;
        }
        }
        return false;
    }

    // static
    bool MojoCompositorFrameSinkClientStubDispatch::AcceptWithResponder(
        MojoCompositorFrameSinkClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kMojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Name: {
            break;
        }
        case internal::kMojoCompositorFrameSinkClient_OnBeginFrame_Name: {
            break;
        }
        case internal::kMojoCompositorFrameSinkClient_ReclaimResources_Name: {
            break;
        }
        case internal::kMojoCompositorFrameSinkClient_WillDrawSurface_Name: {
            break;
        }
        }
        return false;
    }

    bool MojoCompositorFrameSinkClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "MojoCompositorFrameSinkClient RequestValidator");

        switch (message->header()->name) {
        case internal::kMojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSinkClient_DidReceiveCompositorFrameAck_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMojoCompositorFrameSinkClient_OnBeginFrame_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSinkClient_OnBeginFrame_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMojoCompositorFrameSinkClient_ReclaimResources_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSinkClient_ReclaimResources_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMojoCompositorFrameSinkClient_WillDrawSurface_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSinkClient_WillDrawSurface_Params_Data>(
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

    const char MojoCompositorFrameSinkPrivate::Name_[] = "cc::mojom::MojoCompositorFrameSinkPrivate";

    MojoCompositorFrameSinkPrivateProxy::MojoCompositorFrameSinkPrivateProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void MojoCompositorFrameSinkPrivateProxy::AddChildFrameSink(
        const cc::FrameSinkId& in_child_frame_sink_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::FrameSinkIdDataView>(
            in_child_frame_sink_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSinkPrivate_AddChildFrameSink_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->child_frame_sink_id)::BaseType* child_frame_sink_id_ptr;
        mojo::internal::Serialize<::cc::mojom::FrameSinkIdDataView>(
            in_child_frame_sink_id, builder.buffer(), &child_frame_sink_id_ptr, &serialization_context);
        params->child_frame_sink_id.Set(child_frame_sink_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->child_frame_sink_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null child_frame_sink_id in MojoCompositorFrameSinkPrivate.AddChildFrameSink request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MojoCompositorFrameSinkPrivateProxy::RemoveChildFrameSink(
        const cc::FrameSinkId& in_child_frame_sink_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::cc::mojom::internal::MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::FrameSinkIdDataView>(
            in_child_frame_sink_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kMojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Name, size);

        auto params = ::cc::mojom::internal::MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->child_frame_sink_id)::BaseType* child_frame_sink_id_ptr;
        mojo::internal::Serialize<::cc::mojom::FrameSinkIdDataView>(
            in_child_frame_sink_id, builder.buffer(), &child_frame_sink_id_ptr, &serialization_context);
        params->child_frame_sink_id.Set(child_frame_sink_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->child_frame_sink_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null child_frame_sink_id in MojoCompositorFrameSinkPrivate.RemoveChildFrameSink request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool MojoCompositorFrameSinkPrivateStubDispatch::Accept(
        MojoCompositorFrameSinkPrivate* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kMojoCompositorFrameSinkPrivate_AddChildFrameSink_Name: {
            internal::MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::FrameSinkId p_child_frame_sink_id {};
            MojoCompositorFrameSinkPrivate_AddChildFrameSink_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadChildFrameSinkId(&p_child_frame_sink_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSinkPrivate::AddChildFrameSink deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSinkPrivate::AddChildFrameSink");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddChildFrameSink(
                std::move(p_child_frame_sink_id));
            return true;
        }
        case internal::kMojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Name: {
            internal::MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data* params = reinterpret_cast<internal::MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            cc::FrameSinkId p_child_frame_sink_id {};
            MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadChildFrameSinkId(&p_child_frame_sink_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MojoCompositorFrameSinkPrivate::RemoveChildFrameSink deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MojoCompositorFrameSinkPrivate::RemoveChildFrameSink");
            mojo::internal::MessageDispatchContext context(message);
            impl->RemoveChildFrameSink(
                std::move(p_child_frame_sink_id));
            return true;
        }
        }
        return false;
    }

    // static
    bool MojoCompositorFrameSinkPrivateStubDispatch::AcceptWithResponder(
        MojoCompositorFrameSinkPrivate* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kMojoCompositorFrameSinkPrivate_AddChildFrameSink_Name: {
            break;
        }
        case internal::kMojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Name: {
            break;
        }
        }
        return false;
    }

    bool MojoCompositorFrameSinkPrivateRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "MojoCompositorFrameSinkPrivate RequestValidator");

        switch (message->header()->name) {
        case internal::kMojoCompositorFrameSinkPrivate_AddChildFrameSink_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSinkPrivate_AddChildFrameSink_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MojoCompositorFrameSinkPrivate_RemoveChildFrameSink_Params_Data>(
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