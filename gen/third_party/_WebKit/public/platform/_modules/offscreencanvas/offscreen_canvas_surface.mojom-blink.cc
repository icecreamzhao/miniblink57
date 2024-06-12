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

#include "third_party/WebKit/public/platform/modules/offscreencanvas/offscreen_canvas_surface.mojom-blink.h"

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
#include "cc/ipc/surface_sequence_struct_traits.h"
#include "cc/ipc/transferable_resource_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
namespace blink {
namespace mojom {
    namespace blink {
        const char OffscreenCanvasSurface::Name_[] = "blink::mojom::OffscreenCanvasSurface";

        OffscreenCanvasSurfaceProxy::OffscreenCanvasSurfaceProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void OffscreenCanvasSurfaceProxy::Require(
            const cc::SurfaceId& in_surface_id, const cc::SurfaceSequence& in_sequence)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::OffscreenCanvasSurface_Require_Params_Data);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceIdDataView>(
                in_surface_id, &serialization_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceSequenceDataView>(
                in_sequence, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kOffscreenCanvasSurface_Require_Name, size);

            auto params = ::blink::mojom::internal::OffscreenCanvasSurface_Require_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->surface_id)::BaseType* surface_id_ptr;
            mojo::internal::Serialize<::cc::mojom::SurfaceIdDataView>(
                in_surface_id, builder.buffer(), &surface_id_ptr, &serialization_context);
            params->surface_id.Set(surface_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->surface_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null surface_id in OffscreenCanvasSurface.Require request");
            typename decltype(params->sequence)::BaseType* sequence_ptr;
            mojo::internal::Serialize<::cc::mojom::SurfaceSequenceDataView>(
                in_sequence, builder.buffer(), &sequence_ptr, &serialization_context);
            params->sequence.Set(sequence_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->sequence.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null sequence in OffscreenCanvasSurface.Require request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void OffscreenCanvasSurfaceProxy::Satisfy(
            const cc::SurfaceSequence& in_sequence)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::OffscreenCanvasSurface_Satisfy_Params_Data);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceSequenceDataView>(
                in_sequence, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kOffscreenCanvasSurface_Satisfy_Name, size);

            auto params = ::blink::mojom::internal::OffscreenCanvasSurface_Satisfy_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->sequence)::BaseType* sequence_ptr;
            mojo::internal::Serialize<::cc::mojom::SurfaceSequenceDataView>(
                in_sequence, builder.buffer(), &sequence_ptr, &serialization_context);
            params->sequence.Set(sequence_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->sequence.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null sequence in OffscreenCanvasSurface.Satisfy request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool OffscreenCanvasSurfaceStubDispatch::Accept(
            OffscreenCanvasSurface* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kOffscreenCanvasSurface_Require_Name: {
                internal::OffscreenCanvasSurface_Require_Params_Data* params = reinterpret_cast<internal::OffscreenCanvasSurface_Require_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                cc::SurfaceId p_surface_id {};
                cc::SurfaceSequence p_sequence {};
                OffscreenCanvasSurface_Require_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadSurfaceId(&p_surface_id))
                    success = false;
                if (!input_data_view.ReadSequence(&p_sequence))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "OffscreenCanvasSurface::Require deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "OffscreenCanvasSurface::Require");
                mojo::internal::MessageDispatchContext context(message);
                impl->Require(
                    std::move(p_surface_id),
                    std::move(p_sequence));
                return true;
            }
            case internal::kOffscreenCanvasSurface_Satisfy_Name: {
                internal::OffscreenCanvasSurface_Satisfy_Params_Data* params = reinterpret_cast<internal::OffscreenCanvasSurface_Satisfy_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                cc::SurfaceSequence p_sequence {};
                OffscreenCanvasSurface_Satisfy_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadSequence(&p_sequence))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "OffscreenCanvasSurface::Satisfy deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "OffscreenCanvasSurface::Satisfy");
                mojo::internal::MessageDispatchContext context(message);
                impl->Satisfy(
                    std::move(p_sequence));
                return true;
            }
            }
            return false;
        }

        // static
        bool OffscreenCanvasSurfaceStubDispatch::AcceptWithResponder(
            OffscreenCanvasSurface* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kOffscreenCanvasSurface_Require_Name: {
                break;
            }
            case internal::kOffscreenCanvasSurface_Satisfy_Name: {
                break;
            }
            }
            return false;
        }

        bool OffscreenCanvasSurfaceRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "OffscreenCanvasSurface RequestValidator");

            switch (message->header()->name) {
            case internal::kOffscreenCanvasSurface_Require_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::OffscreenCanvasSurface_Require_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kOffscreenCanvasSurface_Satisfy_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::OffscreenCanvasSurface_Satisfy_Params_Data>(
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

        const char OffscreenCanvasSurfaceClient::Name_[] = "blink::mojom::OffscreenCanvasSurfaceClient";

        OffscreenCanvasSurfaceClientProxy::OffscreenCanvasSurfaceClientProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void OffscreenCanvasSurfaceClientProxy::OnSurfaceCreated(
            const cc::SurfaceInfo& in_surface_info)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceInfoDataView>(
                in_surface_info, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kOffscreenCanvasSurfaceClient_OnSurfaceCreated_Name, size);

            auto params = ::blink::mojom::internal::OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->surface_info)::BaseType* surface_info_ptr;
            mojo::internal::Serialize<::cc::mojom::SurfaceInfoDataView>(
                in_surface_info, builder.buffer(), &surface_info_ptr, &serialization_context);
            params->surface_info.Set(surface_info_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->surface_info.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null surface_info in OffscreenCanvasSurfaceClient.OnSurfaceCreated request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool OffscreenCanvasSurfaceClientStubDispatch::Accept(
            OffscreenCanvasSurfaceClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kOffscreenCanvasSurfaceClient_OnSurfaceCreated_Name: {
                internal::OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data* params = reinterpret_cast<internal::OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                cc::SurfaceInfo p_surface_info {};
                OffscreenCanvasSurfaceClient_OnSurfaceCreated_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadSurfaceInfo(&p_surface_info))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "OffscreenCanvasSurfaceClient::OnSurfaceCreated deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "OffscreenCanvasSurfaceClient::OnSurfaceCreated");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnSurfaceCreated(
                    std::move(p_surface_info));
                return true;
            }
            }
            return false;
        }

        // static
        bool OffscreenCanvasSurfaceClientStubDispatch::AcceptWithResponder(
            OffscreenCanvasSurfaceClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kOffscreenCanvasSurfaceClient_OnSurfaceCreated_Name: {
                break;
            }
            }
            return false;
        }

        bool OffscreenCanvasSurfaceClientRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "OffscreenCanvasSurfaceClient RequestValidator");

            switch (message->header()->name) {
            case internal::kOffscreenCanvasSurfaceClient_OnSurfaceCreated_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data>(
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

        const char OffscreenCanvasSurfaceFactory::Name_[] = "blink::mojom::OffscreenCanvasSurfaceFactory";

        OffscreenCanvasSurfaceFactoryProxy::OffscreenCanvasSurfaceFactoryProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void OffscreenCanvasSurfaceFactoryProxy::CreateOffscreenCanvasSurface(
            const cc::FrameSinkId& in_frame_sink_id, OffscreenCanvasSurfaceClientPtr in_client, OffscreenCanvasSurfaceRequest in_service)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::FrameSinkIdDataView>(
                in_frame_sink_id, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kOffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Name, size);

            auto params = ::blink::mojom::internal::OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->frame_sink_id)::BaseType* frame_sink_id_ptr;
            mojo::internal::Serialize<::cc::mojom::FrameSinkIdDataView>(
                in_frame_sink_id, builder.buffer(), &frame_sink_id_ptr, &serialization_context);
            params->frame_sink_id.Set(frame_sink_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->frame_sink_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null frame_sink_id in OffscreenCanvasSurfaceFactory.CreateOffscreenCanvasSurface request");
            mojo::internal::Serialize<::blink::mojom::OffscreenCanvasSurfaceClientPtrDataView>(
                in_client, &params->client, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->client),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid client in OffscreenCanvasSurfaceFactory.CreateOffscreenCanvasSurface request");
            mojo::internal::Serialize<::blink::mojom::OffscreenCanvasSurfaceRequestDataView>(
                in_service, &params->service, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->service),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid service in OffscreenCanvasSurfaceFactory.CreateOffscreenCanvasSurface request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool OffscreenCanvasSurfaceFactoryStubDispatch::Accept(
            OffscreenCanvasSurfaceFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kOffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Name: {
                internal::OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data* params = reinterpret_cast<internal::OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                cc::FrameSinkId p_frame_sink_id {};
                OffscreenCanvasSurfaceClientPtr p_client {};
                OffscreenCanvasSurfaceRequest p_service {};
                OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadFrameSinkId(&p_frame_sink_id))
                    success = false;
                p_client = input_data_view.TakeClient<decltype(p_client)>();
                p_service = input_data_view.TakeService<decltype(p_service)>();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "OffscreenCanvasSurfaceFactory::CreateOffscreenCanvasSurface deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "OffscreenCanvasSurfaceFactory::CreateOffscreenCanvasSurface");
                mojo::internal::MessageDispatchContext context(message);
                impl->CreateOffscreenCanvasSurface(
                    std::move(p_frame_sink_id),
                    std::move(p_client),
                    std::move(p_service));
                return true;
            }
            }
            return false;
        }

        // static
        bool OffscreenCanvasSurfaceFactoryStubDispatch::AcceptWithResponder(
            OffscreenCanvasSurfaceFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kOffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Name: {
                break;
            }
            }
            return false;
        }

        bool OffscreenCanvasSurfaceFactoryRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "OffscreenCanvasSurfaceFactory RequestValidator");

            switch (message->header()->name) {
            case internal::kOffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data>(
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

        const char OffscreenCanvasCompositorFrameSinkProvider::Name_[] = "blink::mojom::OffscreenCanvasCompositorFrameSinkProvider";

        OffscreenCanvasCompositorFrameSinkProviderProxy::OffscreenCanvasCompositorFrameSinkProviderProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void OffscreenCanvasCompositorFrameSinkProviderProxy::CreateCompositorFrameSink(
            const cc::FrameSinkId& in_frame_sink_id, ::cc::mojom::blink::MojoCompositorFrameSinkClientPtr in_client, ::cc::mojom::blink::MojoCompositorFrameSinkRequest in_sink)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::FrameSinkIdDataView>(
                in_frame_sink_id, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kOffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Name, size);

            auto params = ::blink::mojom::internal::OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->frame_sink_id)::BaseType* frame_sink_id_ptr;
            mojo::internal::Serialize<::cc::mojom::FrameSinkIdDataView>(
                in_frame_sink_id, builder.buffer(), &frame_sink_id_ptr, &serialization_context);
            params->frame_sink_id.Set(frame_sink_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->frame_sink_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null frame_sink_id in OffscreenCanvasCompositorFrameSinkProvider.CreateCompositorFrameSink request");
            mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkClientPtrDataView>(
                in_client, &params->client, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->client),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid client in OffscreenCanvasCompositorFrameSinkProvider.CreateCompositorFrameSink request");
            mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkRequestDataView>(
                in_sink, &params->sink, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->sink),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid sink in OffscreenCanvasCompositorFrameSinkProvider.CreateCompositorFrameSink request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool OffscreenCanvasCompositorFrameSinkProviderStubDispatch::Accept(
            OffscreenCanvasCompositorFrameSinkProvider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kOffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Name: {
                internal::OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data* params = reinterpret_cast<internal::OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                cc::FrameSinkId p_frame_sink_id {};
                ::cc::mojom::blink::MojoCompositorFrameSinkClientPtr p_client {};
                ::cc::mojom::blink::MojoCompositorFrameSinkRequest p_sink {};
                OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadFrameSinkId(&p_frame_sink_id))
                    success = false;
                p_client = input_data_view.TakeClient<decltype(p_client)>();
                p_sink = input_data_view.TakeSink<decltype(p_sink)>();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "OffscreenCanvasCompositorFrameSinkProvider::CreateCompositorFrameSink deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "OffscreenCanvasCompositorFrameSinkProvider::CreateCompositorFrameSink");
                mojo::internal::MessageDispatchContext context(message);
                impl->CreateCompositorFrameSink(
                    std::move(p_frame_sink_id),
                    std::move(p_client),
                    std::move(p_sink));
                return true;
            }
            }
            return false;
        }

        // static
        bool OffscreenCanvasCompositorFrameSinkProviderStubDispatch::AcceptWithResponder(
            OffscreenCanvasCompositorFrameSinkProvider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kOffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Name: {
                break;
            }
            }
            return false;
        }

        bool OffscreenCanvasCompositorFrameSinkProviderRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "OffscreenCanvasCompositorFrameSinkProvider RequestValidator");

            switch (message->header()->name) {
            case internal::kOffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data>(
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
} // namespace blink

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif