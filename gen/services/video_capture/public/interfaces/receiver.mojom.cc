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

#include "services/video_capture/public/interfaces/receiver.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
#include "media/capture/ipc/capture_param_traits.h"
#include "media/capture/ipc/capture_param_traits_macros.h"
#include "media/capture/mojo/video_capture_types_typemap_traits.h"
#include "media/mojo/interfaces/pipeline_statistics_struct_traits.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/service_manager/public/cpp/identity_struct_traits.h"
#include "services/service_manager/public/cpp/interface_provider_spec_struct_traits.h"
#include "services/service_manager/public/cpp/service_info_struct_traits.h"
#include "services/video_capture/public/interfaces/capture_settings_traits.h"
#include "services/video_capture/public/interfaces/device_descriptor_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace video_capture {
namespace mojom {
    const char Receiver::Name_[] = "video_capture::mojom::Receiver";

    ReceiverProxy::ReceiverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ReceiverProxy::OnIncomingCapturedVideoFrame(
        ::media::mojom::VideoFramePtr in_frame)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::Receiver_OnIncomingCapturedVideoFrame_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::VideoFrameDataView>(
            in_frame, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kReceiver_OnIncomingCapturedVideoFrame_Name, size);

        auto params = ::video_capture::mojom::internal::Receiver_OnIncomingCapturedVideoFrame_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->frame)::BaseType* frame_ptr;
        mojo::internal::Serialize<::media::mojom::VideoFrameDataView>(
            in_frame, builder.buffer(), &frame_ptr, &serialization_context);
        params->frame.Set(frame_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->frame.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null frame in Receiver.OnIncomingCapturedVideoFrame request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ReceiverProxy::OnError()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::Receiver_OnError_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kReceiver_OnError_Name, size);

        auto params = ::video_capture::mojom::internal::Receiver_OnError_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ReceiverProxy::OnLog(
        const std::string& in_message)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::Receiver_OnLog_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_message, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kReceiver_OnLog_Name, size);

        auto params = ::video_capture::mojom::internal::Receiver_OnLog_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->message)::BaseType* message_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_message, builder.buffer(), &message_ptr, &serialization_context);
        params->message.Set(message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message in Receiver.OnLog request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ReceiverProxy::OnBufferDestroyed(
        int32_t in_buffer_id_to_drop)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::Receiver_OnBufferDestroyed_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kReceiver_OnBufferDestroyed_Name, size);

        auto params = ::video_capture::mojom::internal::Receiver_OnBufferDestroyed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->buffer_id_to_drop = in_buffer_id_to_drop;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool ReceiverStubDispatch::Accept(
        Receiver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kReceiver_OnIncomingCapturedVideoFrame_Name: {
            internal::Receiver_OnIncomingCapturedVideoFrame_Params_Data* params = reinterpret_cast<internal::Receiver_OnIncomingCapturedVideoFrame_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::VideoFramePtr p_frame {};
            Receiver_OnIncomingCapturedVideoFrame_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadFrame(&p_frame))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Receiver::OnIncomingCapturedVideoFrame deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Receiver::OnIncomingCapturedVideoFrame");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnIncomingCapturedVideoFrame(
                std::move(p_frame));
            return true;
        }
        case internal::kReceiver_OnError_Name: {
            internal::Receiver_OnError_Params_Data* params = reinterpret_cast<internal::Receiver_OnError_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Receiver_OnError_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Receiver::OnError deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Receiver::OnError");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnError();
            return true;
        }
        case internal::kReceiver_OnLog_Name: {
            internal::Receiver_OnLog_Params_Data* params = reinterpret_cast<internal::Receiver_OnLog_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_message {};
            Receiver_OnLog_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadMessage(&p_message))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Receiver::OnLog deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Receiver::OnLog");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnLog(
                std::move(p_message));
            return true;
        }
        case internal::kReceiver_OnBufferDestroyed_Name: {
            internal::Receiver_OnBufferDestroyed_Params_Data* params = reinterpret_cast<internal::Receiver_OnBufferDestroyed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_buffer_id_to_drop {};
            Receiver_OnBufferDestroyed_ParamsDataView input_data_view(params,
                context);

            p_buffer_id_to_drop = input_data_view.buffer_id_to_drop();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Receiver::OnBufferDestroyed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Receiver::OnBufferDestroyed");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnBufferDestroyed(
                std::move(p_buffer_id_to_drop));
            return true;
        }
        }
        return false;
    }

    // static
    bool ReceiverStubDispatch::AcceptWithResponder(
        Receiver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kReceiver_OnIncomingCapturedVideoFrame_Name: {
            break;
        }
        case internal::kReceiver_OnError_Name: {
            break;
        }
        case internal::kReceiver_OnLog_Name: {
            break;
        }
        case internal::kReceiver_OnBufferDestroyed_Name: {
            break;
        }
        }
        return false;
    }

    bool ReceiverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Receiver RequestValidator");

        switch (message->header()->name) {
        case internal::kReceiver_OnIncomingCapturedVideoFrame_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Receiver_OnIncomingCapturedVideoFrame_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kReceiver_OnError_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Receiver_OnError_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kReceiver_OnLog_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Receiver_OnLog_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kReceiver_OnBufferDestroyed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Receiver_OnBufferDestroyed_Params_Data>(
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
} // namespace video_capture

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif