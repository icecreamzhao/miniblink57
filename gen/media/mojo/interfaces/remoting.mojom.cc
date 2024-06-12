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

#include "media/mojo/interfaces/remoting.mojom.h"

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
namespace media {
namespace mojom {
    const char RemoterFactory::Name_[] = "media::mojom::RemoterFactory";

    RemoterFactoryProxy::RemoterFactoryProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void RemoterFactoryProxy::Create(
        RemotingSourcePtr in_source, RemoterRequest in_remoter)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemoterFactory_Create_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemoterFactory_Create_Name, size);

        auto params = ::media::mojom::internal::RemoterFactory_Create_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::RemotingSourcePtrDataView>(
            in_source, &params->source, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->source),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid source in RemoterFactory.Create request");
        mojo::internal::Serialize<::media::mojom::RemoterRequestDataView>(
            in_remoter, &params->remoter, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->remoter),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid remoter in RemoterFactory.Create request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool RemoterFactoryStubDispatch::Accept(
        RemoterFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRemoterFactory_Create_Name: {
            internal::RemoterFactory_Create_Params_Data* params = reinterpret_cast<internal::RemoterFactory_Create_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RemotingSourcePtr p_source {};
            RemoterRequest p_remoter {};
            RemoterFactory_Create_ParamsDataView input_data_view(params,
                context);

            p_source = input_data_view.TakeSource<decltype(p_source)>();
            p_remoter = input_data_view.TakeRemoter<decltype(p_remoter)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemoterFactory::Create deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemoterFactory::Create");
            mojo::internal::MessageDispatchContext context(message);
            impl->Create(
                std::move(p_source),
                std::move(p_remoter));
            return true;
        }
        }
        return false;
    }

    // static
    bool RemoterFactoryStubDispatch::AcceptWithResponder(
        RemoterFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRemoterFactory_Create_Name: {
            break;
        }
        }
        return false;
    }

    bool RemoterFactoryRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "RemoterFactory RequestValidator");

        switch (message->header()->name) {
        case internal::kRemoterFactory_Create_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemoterFactory_Create_Params_Data>(
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

    const char RemotingDataStreamSender::Name_[] = "media::mojom::RemotingDataStreamSender";

    RemotingDataStreamSenderProxy::RemotingDataStreamSenderProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void RemotingDataStreamSenderProxy::ConsumeDataChunk(
        uint32_t in_offset, uint32_t in_size, uint32_t in_total_payload_size)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemotingDataStreamSender_ConsumeDataChunk_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemotingDataStreamSender_ConsumeDataChunk_Name, size);

        auto params = ::media::mojom::internal::RemotingDataStreamSender_ConsumeDataChunk_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->offset = in_offset;
        params->size = in_size;
        params->total_payload_size = in_total_payload_size;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemotingDataStreamSenderProxy::SendFrame()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemotingDataStreamSender_SendFrame_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemotingDataStreamSender_SendFrame_Name, size);

        auto params = ::media::mojom::internal::RemotingDataStreamSender_SendFrame_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemotingDataStreamSenderProxy::CancelInFlightData()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemotingDataStreamSender_CancelInFlightData_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemotingDataStreamSender_CancelInFlightData_Name, size);

        auto params = ::media::mojom::internal::RemotingDataStreamSender_CancelInFlightData_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool RemotingDataStreamSenderStubDispatch::Accept(
        RemotingDataStreamSender* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRemotingDataStreamSender_ConsumeDataChunk_Name: {
            internal::RemotingDataStreamSender_ConsumeDataChunk_Params_Data* params = reinterpret_cast<internal::RemotingDataStreamSender_ConsumeDataChunk_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_offset {};
            uint32_t p_size {};
            uint32_t p_total_payload_size {};
            RemotingDataStreamSender_ConsumeDataChunk_ParamsDataView input_data_view(params,
                context);

            p_offset = input_data_view.offset();
            p_size = input_data_view.size();
            p_total_payload_size = input_data_view.total_payload_size();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemotingDataStreamSender::ConsumeDataChunk deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemotingDataStreamSender::ConsumeDataChunk");
            mojo::internal::MessageDispatchContext context(message);
            impl->ConsumeDataChunk(
                std::move(p_offset),
                std::move(p_size),
                std::move(p_total_payload_size));
            return true;
        }
        case internal::kRemotingDataStreamSender_SendFrame_Name: {
            internal::RemotingDataStreamSender_SendFrame_Params_Data* params = reinterpret_cast<internal::RemotingDataStreamSender_SendFrame_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RemotingDataStreamSender_SendFrame_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemotingDataStreamSender::SendFrame deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemotingDataStreamSender::SendFrame");
            mojo::internal::MessageDispatchContext context(message);
            impl->SendFrame();
            return true;
        }
        case internal::kRemotingDataStreamSender_CancelInFlightData_Name: {
            internal::RemotingDataStreamSender_CancelInFlightData_Params_Data* params = reinterpret_cast<internal::RemotingDataStreamSender_CancelInFlightData_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RemotingDataStreamSender_CancelInFlightData_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemotingDataStreamSender::CancelInFlightData deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemotingDataStreamSender::CancelInFlightData");
            mojo::internal::MessageDispatchContext context(message);
            impl->CancelInFlightData();
            return true;
        }
        }
        return false;
    }

    // static
    bool RemotingDataStreamSenderStubDispatch::AcceptWithResponder(
        RemotingDataStreamSender* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRemotingDataStreamSender_ConsumeDataChunk_Name: {
            break;
        }
        case internal::kRemotingDataStreamSender_SendFrame_Name: {
            break;
        }
        case internal::kRemotingDataStreamSender_CancelInFlightData_Name: {
            break;
        }
        }
        return false;
    }

    bool RemotingDataStreamSenderRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "RemotingDataStreamSender RequestValidator");

        switch (message->header()->name) {
        case internal::kRemotingDataStreamSender_ConsumeDataChunk_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemotingDataStreamSender_ConsumeDataChunk_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemotingDataStreamSender_SendFrame_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemotingDataStreamSender_SendFrame_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemotingDataStreamSender_CancelInFlightData_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemotingDataStreamSender_CancelInFlightData_Params_Data>(
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

    const char Remoter::Name_[] = "media::mojom::Remoter";

    RemoterProxy::RemoterProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void RemoterProxy::Start()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Remoter_Start_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemoter_Start_Name, size);

        auto params = ::media::mojom::internal::Remoter_Start_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemoterProxy::StartDataStreams(
        mojo::ScopedDataPipeConsumerHandle in_audio_pipe, mojo::ScopedDataPipeConsumerHandle in_video_pipe, RemotingDataStreamSenderRequest in_audio_sender, RemotingDataStreamSenderRequest in_video_sender)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Remoter_StartDataStreams_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemoter_StartDataStreams_Name, size);

        auto params = ::media::mojom::internal::Remoter_StartDataStreams_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedDataPipeConsumerHandle>(
            in_audio_pipe, &params->audio_pipe, &serialization_context);
        mojo::internal::Serialize<mojo::ScopedDataPipeConsumerHandle>(
            in_video_pipe, &params->video_pipe, &serialization_context);
        mojo::internal::Serialize<::media::mojom::RemotingDataStreamSenderRequestDataView>(
            in_audio_sender, &params->audio_sender, &serialization_context);
        mojo::internal::Serialize<::media::mojom::RemotingDataStreamSenderRequestDataView>(
            in_video_sender, &params->video_sender, &serialization_context);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemoterProxy::Stop(
        RemotingStopReason in_reason)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Remoter_Stop_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemoter_Stop_Name, size);

        auto params = ::media::mojom::internal::Remoter_Stop_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::RemotingStopReason>(
            in_reason, &params->reason);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemoterProxy::SendMessageToSink(
        const std::vector<uint8_t>& in_message)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Remoter_SendMessageToSink_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_message, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRemoter_SendMessageToSink_Name, size);

        auto params = ::media::mojom::internal::Remoter_SendMessageToSink_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->message)::BaseType* message_ptr;
        const mojo::internal::ContainerValidateParams message_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_message, builder.buffer(), &message_ptr, &message_validate_params,
            &serialization_context);
        params->message.Set(message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message in Remoter.SendMessageToSink request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool RemoterStubDispatch::Accept(
        Remoter* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRemoter_Start_Name: {
            internal::Remoter_Start_Params_Data* params = reinterpret_cast<internal::Remoter_Start_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Remoter_Start_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Remoter::Start deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Remoter::Start");
            mojo::internal::MessageDispatchContext context(message);
            impl->Start();
            return true;
        }
        case internal::kRemoter_StartDataStreams_Name: {
            internal::Remoter_StartDataStreams_Params_Data* params = reinterpret_cast<internal::Remoter_StartDataStreams_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedDataPipeConsumerHandle p_audio_pipe {};
            mojo::ScopedDataPipeConsumerHandle p_video_pipe {};
            RemotingDataStreamSenderRequest p_audio_sender {};
            RemotingDataStreamSenderRequest p_video_sender {};
            Remoter_StartDataStreams_ParamsDataView input_data_view(params,
                context);

            p_audio_pipe = input_data_view.TakeAudioPipe();
            p_video_pipe = input_data_view.TakeVideoPipe();
            p_audio_sender = input_data_view.TakeAudioSender<decltype(p_audio_sender)>();
            p_video_sender = input_data_view.TakeVideoSender<decltype(p_video_sender)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Remoter::StartDataStreams deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Remoter::StartDataStreams");
            mojo::internal::MessageDispatchContext context(message);
            impl->StartDataStreams(
                std::move(p_audio_pipe),
                std::move(p_video_pipe),
                std::move(p_audio_sender),
                std::move(p_video_sender));
            return true;
        }
        case internal::kRemoter_Stop_Name: {
            internal::Remoter_Stop_Params_Data* params = reinterpret_cast<internal::Remoter_Stop_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RemotingStopReason p_reason {};
            Remoter_Stop_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadReason(&p_reason))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Remoter::Stop deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Remoter::Stop");
            mojo::internal::MessageDispatchContext context(message);
            impl->Stop(
                std::move(p_reason));
            return true;
        }
        case internal::kRemoter_SendMessageToSink_Name: {
            internal::Remoter_SendMessageToSink_Params_Data* params = reinterpret_cast<internal::Remoter_SendMessageToSink_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_message {};
            Remoter_SendMessageToSink_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadMessage(&p_message))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Remoter::SendMessageToSink deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Remoter::SendMessageToSink");
            mojo::internal::MessageDispatchContext context(message);
            impl->SendMessageToSink(
                std::move(p_message));
            return true;
        }
        }
        return false;
    }

    // static
    bool RemoterStubDispatch::AcceptWithResponder(
        Remoter* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRemoter_Start_Name: {
            break;
        }
        case internal::kRemoter_StartDataStreams_Name: {
            break;
        }
        case internal::kRemoter_Stop_Name: {
            break;
        }
        case internal::kRemoter_SendMessageToSink_Name: {
            break;
        }
        }
        return false;
    }

    bool RemoterRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Remoter RequestValidator");

        switch (message->header()->name) {
        case internal::kRemoter_Start_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Remoter_Start_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemoter_StartDataStreams_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Remoter_StartDataStreams_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemoter_Stop_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Remoter_Stop_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemoter_SendMessageToSink_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Remoter_SendMessageToSink_Params_Data>(
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

    const char RemotingSource::Name_[] = "media::mojom::RemotingSource";

    RemotingSourceProxy::RemotingSourceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void RemotingSourceProxy::OnSinkAvailable(
        RemotingSinkCapabilities in_capabilities)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemotingSource_OnSinkAvailable_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemotingSource_OnSinkAvailable_Name, size);

        auto params = ::media::mojom::internal::RemotingSource_OnSinkAvailable_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::RemotingSinkCapabilities>(
            in_capabilities, &params->capabilities);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemotingSourceProxy::OnSinkGone()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemotingSource_OnSinkGone_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemotingSource_OnSinkGone_Name, size);

        auto params = ::media::mojom::internal::RemotingSource_OnSinkGone_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemotingSourceProxy::OnStarted()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemotingSource_OnStarted_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemotingSource_OnStarted_Name, size);

        auto params = ::media::mojom::internal::RemotingSource_OnStarted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemotingSourceProxy::OnStartFailed(
        RemotingStartFailReason in_reason)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemotingSource_OnStartFailed_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemotingSource_OnStartFailed_Name, size);

        auto params = ::media::mojom::internal::RemotingSource_OnStartFailed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::RemotingStartFailReason>(
            in_reason, &params->reason);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemotingSourceProxy::OnMessageFromSink(
        const std::vector<uint8_t>& in_message)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemotingSource_OnMessageFromSink_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_message, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRemotingSource_OnMessageFromSink_Name, size);

        auto params = ::media::mojom::internal::RemotingSource_OnMessageFromSink_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->message)::BaseType* message_ptr;
        const mojo::internal::ContainerValidateParams message_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_message, builder.buffer(), &message_ptr, &message_validate_params,
            &serialization_context);
        params->message.Set(message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message in RemotingSource.OnMessageFromSink request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RemotingSourceProxy::OnStopped(
        RemotingStopReason in_reason)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RemotingSource_OnStopped_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRemotingSource_OnStopped_Name, size);

        auto params = ::media::mojom::internal::RemotingSource_OnStopped_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::RemotingStopReason>(
            in_reason, &params->reason);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool RemotingSourceStubDispatch::Accept(
        RemotingSource* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRemotingSource_OnSinkAvailable_Name: {
            internal::RemotingSource_OnSinkAvailable_Params_Data* params = reinterpret_cast<internal::RemotingSource_OnSinkAvailable_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RemotingSinkCapabilities p_capabilities {};
            RemotingSource_OnSinkAvailable_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadCapabilities(&p_capabilities))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemotingSource::OnSinkAvailable deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemotingSource::OnSinkAvailable");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnSinkAvailable(
                std::move(p_capabilities));
            return true;
        }
        case internal::kRemotingSource_OnSinkGone_Name: {
            internal::RemotingSource_OnSinkGone_Params_Data* params = reinterpret_cast<internal::RemotingSource_OnSinkGone_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RemotingSource_OnSinkGone_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemotingSource::OnSinkGone deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemotingSource::OnSinkGone");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnSinkGone();
            return true;
        }
        case internal::kRemotingSource_OnStarted_Name: {
            internal::RemotingSource_OnStarted_Params_Data* params = reinterpret_cast<internal::RemotingSource_OnStarted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RemotingSource_OnStarted_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemotingSource::OnStarted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemotingSource::OnStarted");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnStarted();
            return true;
        }
        case internal::kRemotingSource_OnStartFailed_Name: {
            internal::RemotingSource_OnStartFailed_Params_Data* params = reinterpret_cast<internal::RemotingSource_OnStartFailed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RemotingStartFailReason p_reason {};
            RemotingSource_OnStartFailed_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadReason(&p_reason))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemotingSource::OnStartFailed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemotingSource::OnStartFailed");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnStartFailed(
                std::move(p_reason));
            return true;
        }
        case internal::kRemotingSource_OnMessageFromSink_Name: {
            internal::RemotingSource_OnMessageFromSink_Params_Data* params = reinterpret_cast<internal::RemotingSource_OnMessageFromSink_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_message {};
            RemotingSource_OnMessageFromSink_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadMessage(&p_message))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemotingSource::OnMessageFromSink deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemotingSource::OnMessageFromSink");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnMessageFromSink(
                std::move(p_message));
            return true;
        }
        case internal::kRemotingSource_OnStopped_Name: {
            internal::RemotingSource_OnStopped_Params_Data* params = reinterpret_cast<internal::RemotingSource_OnStopped_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RemotingStopReason p_reason {};
            RemotingSource_OnStopped_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadReason(&p_reason))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RemotingSource::OnStopped deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RemotingSource::OnStopped");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnStopped(
                std::move(p_reason));
            return true;
        }
        }
        return false;
    }

    // static
    bool RemotingSourceStubDispatch::AcceptWithResponder(
        RemotingSource* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRemotingSource_OnSinkAvailable_Name: {
            break;
        }
        case internal::kRemotingSource_OnSinkGone_Name: {
            break;
        }
        case internal::kRemotingSource_OnStarted_Name: {
            break;
        }
        case internal::kRemotingSource_OnStartFailed_Name: {
            break;
        }
        case internal::kRemotingSource_OnMessageFromSink_Name: {
            break;
        }
        case internal::kRemotingSource_OnStopped_Name: {
            break;
        }
        }
        return false;
    }

    bool RemotingSourceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "RemotingSource RequestValidator");

        switch (message->header()->name) {
        case internal::kRemotingSource_OnSinkAvailable_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemotingSource_OnSinkAvailable_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemotingSource_OnSinkGone_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemotingSource_OnSinkGone_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemotingSource_OnStarted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemotingSource_OnStarted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemotingSource_OnStartFailed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemotingSource_OnStartFailed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemotingSource_OnMessageFromSink_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemotingSource_OnMessageFromSink_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRemotingSource_OnStopped_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RemotingSource_OnStopped_Params_Data>(
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
} // namespace media

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif