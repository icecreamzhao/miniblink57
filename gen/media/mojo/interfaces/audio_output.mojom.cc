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

#include "media/mojo/interfaces/audio_output.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
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
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace media {
namespace mojom {
    const char AudioOutputStream::Name_[] = "media::mojom::AudioOutputStream";

    AudioOutputStreamProxy::AudioOutputStreamProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void AudioOutputStreamProxy::Close()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::AudioOutputStream_Close_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAudioOutputStream_Close_Name, size);

        auto params = ::media::mojom::internal::AudioOutputStream_Close_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool AudioOutputStreamStubDispatch::Accept(
        AudioOutputStream* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kAudioOutputStream_Close_Name: {
            internal::AudioOutputStream_Close_Params_Data* params = reinterpret_cast<internal::AudioOutputStream_Close_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AudioOutputStream_Close_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AudioOutputStream::Close deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AudioOutputStream::Close");
            mojo::internal::MessageDispatchContext context(message);
            impl->Close();
            return true;
        }
        }
        return false;
    }

    // static
    bool AudioOutputStreamStubDispatch::AcceptWithResponder(
        AudioOutputStream* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kAudioOutputStream_Close_Name: {
            break;
        }
        }
        return false;
    }

    bool AudioOutputStreamRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AudioOutputStream RequestValidator");

        switch (message->header()->name) {
        case internal::kAudioOutputStream_Close_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioOutputStream_Close_Params_Data>(
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

    const char AudioOutput::Name_[] = "media::mojom::AudioOutput";

    class AudioOutput_CreateStream_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        AudioOutput_CreateStream_ForwardToCallback(
            const AudioOutput::CreateStreamCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        AudioOutput::CreateStreamCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(AudioOutput_CreateStream_ForwardToCallback);
    };
    bool AudioOutput_CreateStream_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::AudioOutput_CreateStream_ResponseParams_Data* params = reinterpret_cast<internal::AudioOutput_CreateStream_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        int32_t p_stream_id {};
        AudioOutputStreamPtr p_stream {};
        mojo::ScopedSharedBufferHandle p_shared_buffer {};
        mojo::ScopedHandle p_socket_descriptor {};
        AudioOutput_CreateStream_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_stream_id = input_data_view.stream_id();
        p_stream = input_data_view.TakeStream<decltype(p_stream)>();
        p_shared_buffer = input_data_view.TakeSharedBuffer();
        p_socket_descriptor = input_data_view.TakeSocketDescriptor();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "AudioOutput::CreateStream response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_stream_id),
                std::move(p_stream),
                std::move(p_shared_buffer),
                std::move(p_socket_descriptor));
        }
        return true;
    }

    AudioOutputProxy::AudioOutputProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void AudioOutputProxy::CreateStream(
        int32_t in_stream_id, const media::AudioParameters& in_params, const CreateStreamCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::AudioOutput_CreateStream_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::AudioParametersDataView>(
            in_params, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kAudioOutput_CreateStream_Name, size);

        auto params = ::media::mojom::internal::AudioOutput_CreateStream_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->stream_id = in_stream_id;
        typename decltype(params->params)::BaseType* params_ptr;
        mojo::internal::Serialize<::media::mojom::AudioParametersDataView>(
            in_params, builder.buffer(), &params_ptr, &serialization_context);
        params->params.Set(params_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->params.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null params in AudioOutput.CreateStream request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new AudioOutput_CreateStream_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class AudioOutput_CreateStream_ProxyToResponder {
    public:
        static AudioOutput::CreateStreamCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<AudioOutput_CreateStream_ProxyToResponder> proxy(
                new AudioOutput_CreateStream_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&AudioOutput_CreateStream_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~AudioOutput_CreateStream_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "AudioOutput::CreateStream() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        AudioOutput_CreateStream_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            int32_t in_stream_id, AudioOutputStreamPtr in_stream, mojo::ScopedSharedBufferHandle in_shared_buffer, mojo::ScopedHandle in_socket_descriptor);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(AudioOutput_CreateStream_ProxyToResponder);
    };

    void AudioOutput_CreateStream_ProxyToResponder::Run(
        int32_t in_stream_id, AudioOutputStreamPtr in_stream, mojo::ScopedSharedBufferHandle in_shared_buffer, mojo::ScopedHandle in_socket_descriptor)
    {
        size_t size = sizeof(::media::mojom::internal::AudioOutput_CreateStream_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kAudioOutput_CreateStream_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::AudioOutput_CreateStream_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->stream_id = in_stream_id;
        mojo::internal::Serialize<::media::mojom::AudioOutputStreamPtrDataView>(
            in_stream, &params->stream, &serialization_context_);
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_shared_buffer, &params->shared_buffer, &serialization_context_);
        mojo::internal::Serialize<mojo::ScopedHandle>(
            in_socket_descriptor, &params->socket_descriptor, &serialization_context_);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }

    // static
    bool AudioOutputStubDispatch::Accept(
        AudioOutput* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kAudioOutput_CreateStream_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool AudioOutputStubDispatch::AcceptWithResponder(
        AudioOutput* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kAudioOutput_CreateStream_Name: {
            internal::AudioOutput_CreateStream_Params_Data* params = reinterpret_cast<internal::AudioOutput_CreateStream_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_stream_id {};
            media::AudioParameters p_params {};
            AudioOutput_CreateStream_ParamsDataView input_data_view(params,
                context);

            p_stream_id = input_data_view.stream_id();
            if (!input_data_view.ReadParams(&p_params))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AudioOutput::CreateStream deserializer");
                return false;
            }
            AudioOutput::CreateStreamCallback callback = AudioOutput_CreateStream_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AudioOutput::CreateStream");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateStream(
                std::move(p_stream_id),
                std::move(p_params), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool AudioOutputRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AudioOutput RequestValidator");

        switch (message->header()->name) {
        case internal::kAudioOutput_CreateStream_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioOutput_CreateStream_Params_Data>(
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

    bool AudioOutputResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AudioOutput ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kAudioOutput_CreateStream_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioOutput_CreateStream_ResponseParams_Data>(
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