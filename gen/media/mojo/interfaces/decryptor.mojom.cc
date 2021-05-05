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

#include "media/mojo/interfaces/decryptor.mojom.h"

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
    const char Decryptor::Name_[] = "media::mojom::Decryptor";

    class Decryptor_Decrypt_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Decryptor_Decrypt_ForwardToCallback(
            const Decryptor::DecryptCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Decryptor::DecryptCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Decryptor_Decrypt_ForwardToCallback);
    };
    bool Decryptor_Decrypt_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Decryptor_Decrypt_ResponseParams_Data* params = reinterpret_cast<internal::Decryptor_Decrypt_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        media::Decryptor::Status p_status {};
        ::media::mojom::DecoderBufferPtr p_buffer {};
        Decryptor_Decrypt_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadBuffer(&p_buffer))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Decryptor::Decrypt response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_buffer));
        }
        return true;
    }

    class Decryptor_InitializeAudioDecoder_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Decryptor_InitializeAudioDecoder_ForwardToCallback(
            const Decryptor::InitializeAudioDecoderCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Decryptor::InitializeAudioDecoderCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Decryptor_InitializeAudioDecoder_ForwardToCallback);
    };
    bool Decryptor_InitializeAudioDecoder_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Decryptor_InitializeAudioDecoder_ResponseParams_Data* params = reinterpret_cast<internal::Decryptor_InitializeAudioDecoder_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        Decryptor_InitializeAudioDecoder_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Decryptor::InitializeAudioDecoder response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    class Decryptor_InitializeVideoDecoder_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Decryptor_InitializeVideoDecoder_ForwardToCallback(
            const Decryptor::InitializeVideoDecoderCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Decryptor::InitializeVideoDecoderCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Decryptor_InitializeVideoDecoder_ForwardToCallback);
    };
    bool Decryptor_InitializeVideoDecoder_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Decryptor_InitializeVideoDecoder_ResponseParams_Data* params = reinterpret_cast<internal::Decryptor_InitializeVideoDecoder_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        Decryptor_InitializeVideoDecoder_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Decryptor::InitializeVideoDecoder response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    class Decryptor_DecryptAndDecodeAudio_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Decryptor_DecryptAndDecodeAudio_ForwardToCallback(
            const Decryptor::DecryptAndDecodeAudioCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Decryptor::DecryptAndDecodeAudioCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Decryptor_DecryptAndDecodeAudio_ForwardToCallback);
    };
    bool Decryptor_DecryptAndDecodeAudio_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Decryptor_DecryptAndDecodeAudio_ResponseParams_Data* params = reinterpret_cast<internal::Decryptor_DecryptAndDecodeAudio_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        media::Decryptor::Status p_status {};
        std::vector<::media::mojom::AudioBufferPtr> p_audio_buffers {};
        Decryptor_DecryptAndDecodeAudio_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadAudioBuffers(&p_audio_buffers))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Decryptor::DecryptAndDecodeAudio response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_audio_buffers));
        }
        return true;
    }

    class Decryptor_DecryptAndDecodeVideo_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Decryptor_DecryptAndDecodeVideo_ForwardToCallback(
            const Decryptor::DecryptAndDecodeVideoCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Decryptor::DecryptAndDecodeVideoCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Decryptor_DecryptAndDecodeVideo_ForwardToCallback);
    };
    bool Decryptor_DecryptAndDecodeVideo_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Decryptor_DecryptAndDecodeVideo_ResponseParams_Data* params = reinterpret_cast<internal::Decryptor_DecryptAndDecodeVideo_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        media::Decryptor::Status p_status {};
        ::media::mojom::VideoFramePtr p_video_frame {};
        Decryptor_DecryptAndDecodeVideo_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadVideoFrame(&p_video_frame))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Decryptor::DecryptAndDecodeVideo response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_video_frame));
        }
        return true;
    }

    DecryptorProxy::DecryptorProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DecryptorProxy::Initialize(
        mojo::ScopedDataPipeConsumerHandle in_receive_pipe, mojo::ScopedDataPipeProducerHandle in_transmit_pipe)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_Initialize_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDecryptor_Initialize_Name, size);

        auto params = ::media::mojom::internal::Decryptor_Initialize_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedDataPipeConsumerHandle>(
            in_receive_pipe, &params->receive_pipe, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->receive_pipe),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid receive_pipe in Decryptor.Initialize request");
        mojo::internal::Serialize<mojo::ScopedDataPipeProducerHandle>(
            in_transmit_pipe, &params->transmit_pipe, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->transmit_pipe),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid transmit_pipe in Decryptor.Initialize request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DecryptorProxy::Decrypt(
        media::Decryptor::StreamType in_stream_type, ::media::mojom::DecoderBufferPtr in_encrypted, const DecryptCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_Decrypt_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::DecoderBufferDataView>(
            in_encrypted, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDecryptor_Decrypt_Name, size);

        auto params = ::media::mojom::internal::Decryptor_Decrypt_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::Decryptor_StreamType>(
            in_stream_type, &params->stream_type);
        typename decltype(params->encrypted)::BaseType* encrypted_ptr;
        mojo::internal::Serialize<::media::mojom::DecoderBufferDataView>(
            in_encrypted, builder.buffer(), &encrypted_ptr, &serialization_context);
        params->encrypted.Set(encrypted_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->encrypted.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null encrypted in Decryptor.Decrypt request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Decryptor_Decrypt_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DecryptorProxy::CancelDecrypt(
        media::Decryptor::StreamType in_stream_type)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_CancelDecrypt_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDecryptor_CancelDecrypt_Name, size);

        auto params = ::media::mojom::internal::Decryptor_CancelDecrypt_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::Decryptor_StreamType>(
            in_stream_type, &params->stream_type);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DecryptorProxy::InitializeAudioDecoder(
        ::media::mojom::AudioDecoderConfigPtr in_config, const InitializeAudioDecoderCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_InitializeAudioDecoder_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::AudioDecoderConfigDataView>(
            in_config, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDecryptor_InitializeAudioDecoder_Name, size);

        auto params = ::media::mojom::internal::Decryptor_InitializeAudioDecoder_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->config)::BaseType* config_ptr;
        mojo::internal::Serialize<::media::mojom::AudioDecoderConfigDataView>(
            in_config, builder.buffer(), &config_ptr, &serialization_context);
        params->config.Set(config_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->config.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null config in Decryptor.InitializeAudioDecoder request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Decryptor_InitializeAudioDecoder_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DecryptorProxy::InitializeVideoDecoder(
        ::media::mojom::VideoDecoderConfigPtr in_config, const InitializeVideoDecoderCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_InitializeVideoDecoder_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::VideoDecoderConfigDataView>(
            in_config, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDecryptor_InitializeVideoDecoder_Name, size);

        auto params = ::media::mojom::internal::Decryptor_InitializeVideoDecoder_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->config)::BaseType* config_ptr;
        mojo::internal::Serialize<::media::mojom::VideoDecoderConfigDataView>(
            in_config, builder.buffer(), &config_ptr, &serialization_context);
        params->config.Set(config_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->config.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null config in Decryptor.InitializeVideoDecoder request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Decryptor_InitializeVideoDecoder_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DecryptorProxy::DecryptAndDecodeAudio(
        ::media::mojom::DecoderBufferPtr in_encrypted, const DecryptAndDecodeAudioCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_DecryptAndDecodeAudio_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::DecoderBufferDataView>(
            in_encrypted, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDecryptor_DecryptAndDecodeAudio_Name, size);

        auto params = ::media::mojom::internal::Decryptor_DecryptAndDecodeAudio_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->encrypted)::BaseType* encrypted_ptr;
        mojo::internal::Serialize<::media::mojom::DecoderBufferDataView>(
            in_encrypted, builder.buffer(), &encrypted_ptr, &serialization_context);
        params->encrypted.Set(encrypted_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->encrypted.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null encrypted in Decryptor.DecryptAndDecodeAudio request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Decryptor_DecryptAndDecodeAudio_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DecryptorProxy::DecryptAndDecodeVideo(
        ::media::mojom::DecoderBufferPtr in_encrypted, const DecryptAndDecodeVideoCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_DecryptAndDecodeVideo_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::DecoderBufferDataView>(
            in_encrypted, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDecryptor_DecryptAndDecodeVideo_Name, size);

        auto params = ::media::mojom::internal::Decryptor_DecryptAndDecodeVideo_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->encrypted)::BaseType* encrypted_ptr;
        mojo::internal::Serialize<::media::mojom::DecoderBufferDataView>(
            in_encrypted, builder.buffer(), &encrypted_ptr, &serialization_context);
        params->encrypted.Set(encrypted_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->encrypted.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null encrypted in Decryptor.DecryptAndDecodeVideo request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Decryptor_DecryptAndDecodeVideo_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DecryptorProxy::ResetDecoder(
        media::Decryptor::StreamType in_stream_type)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_ResetDecoder_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDecryptor_ResetDecoder_Name, size);

        auto params = ::media::mojom::internal::Decryptor_ResetDecoder_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::Decryptor_StreamType>(
            in_stream_type, &params->stream_type);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DecryptorProxy::DeinitializeDecoder(
        media::Decryptor::StreamType in_stream_type)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_DeinitializeDecoder_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDecryptor_DeinitializeDecoder_Name, size);

        auto params = ::media::mojom::internal::Decryptor_DeinitializeDecoder_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::Decryptor_StreamType>(
            in_stream_type, &params->stream_type);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DecryptorProxy::ReleaseSharedBuffer(
        mojo::ScopedSharedBufferHandle in_buffer, uint64_t in_buffer_size)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Decryptor_ReleaseSharedBuffer_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDecryptor_ReleaseSharedBuffer_Name, size);

        auto params = ::media::mojom::internal::Decryptor_ReleaseSharedBuffer_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_buffer, &params->buffer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->buffer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid buffer in Decryptor.ReleaseSharedBuffer request");
        params->buffer_size = in_buffer_size;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class Decryptor_Decrypt_ProxyToResponder {
    public:
        static Decryptor::DecryptCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Decryptor_Decrypt_ProxyToResponder> proxy(
                new Decryptor_Decrypt_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Decryptor_Decrypt_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Decryptor_Decrypt_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Decryptor::Decrypt() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Decryptor_Decrypt_ProxyToResponder(
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
            media::Decryptor::Status in_status, ::media::mojom::DecoderBufferPtr in_buffer);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Decryptor_Decrypt_ProxyToResponder);
    };

    void Decryptor_Decrypt_ProxyToResponder::Run(
        media::Decryptor::Status in_status, ::media::mojom::DecoderBufferPtr in_buffer)
    {
        size_t size = sizeof(::media::mojom::internal::Decryptor_Decrypt_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::DecoderBufferDataView>(
            in_buffer, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDecryptor_Decrypt_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::Decryptor_Decrypt_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::Decryptor_Status>(
            in_status, &params->status);
        typename decltype(params->buffer)::BaseType* buffer_ptr;
        mojo::internal::Serialize<::media::mojom::DecoderBufferDataView>(
            in_buffer, builder.buffer(), &buffer_ptr, &serialization_context_);
        params->buffer.Set(buffer_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Decryptor_InitializeAudioDecoder_ProxyToResponder {
    public:
        static Decryptor::InitializeAudioDecoderCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Decryptor_InitializeAudioDecoder_ProxyToResponder> proxy(
                new Decryptor_InitializeAudioDecoder_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Decryptor_InitializeAudioDecoder_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Decryptor_InitializeAudioDecoder_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Decryptor::InitializeAudioDecoder() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Decryptor_InitializeAudioDecoder_ProxyToResponder(
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
            bool in_success);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Decryptor_InitializeAudioDecoder_ProxyToResponder);
    };

    void Decryptor_InitializeAudioDecoder_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::media::mojom::internal::Decryptor_InitializeAudioDecoder_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDecryptor_InitializeAudioDecoder_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::Decryptor_InitializeAudioDecoder_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Decryptor_InitializeVideoDecoder_ProxyToResponder {
    public:
        static Decryptor::InitializeVideoDecoderCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Decryptor_InitializeVideoDecoder_ProxyToResponder> proxy(
                new Decryptor_InitializeVideoDecoder_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Decryptor_InitializeVideoDecoder_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Decryptor_InitializeVideoDecoder_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Decryptor::InitializeVideoDecoder() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Decryptor_InitializeVideoDecoder_ProxyToResponder(
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
            bool in_success);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Decryptor_InitializeVideoDecoder_ProxyToResponder);
    };

    void Decryptor_InitializeVideoDecoder_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::media::mojom::internal::Decryptor_InitializeVideoDecoder_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDecryptor_InitializeVideoDecoder_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::Decryptor_InitializeVideoDecoder_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Decryptor_DecryptAndDecodeAudio_ProxyToResponder {
    public:
        static Decryptor::DecryptAndDecodeAudioCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Decryptor_DecryptAndDecodeAudio_ProxyToResponder> proxy(
                new Decryptor_DecryptAndDecodeAudio_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Decryptor_DecryptAndDecodeAudio_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Decryptor_DecryptAndDecodeAudio_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Decryptor::DecryptAndDecodeAudio() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Decryptor_DecryptAndDecodeAudio_ProxyToResponder(
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
            media::Decryptor::Status in_status, std::vector<::media::mojom::AudioBufferPtr> in_audio_buffers);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Decryptor_DecryptAndDecodeAudio_ProxyToResponder);
    };

    void Decryptor_DecryptAndDecodeAudio_ProxyToResponder::Run(
        media::Decryptor::Status in_status, std::vector<::media::mojom::AudioBufferPtr> in_audio_buffers)
    {
        size_t size = sizeof(::media::mojom::internal::Decryptor_DecryptAndDecodeAudio_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::media::mojom::AudioBufferDataView>>(
            in_audio_buffers, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDecryptor_DecryptAndDecodeAudio_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::Decryptor_DecryptAndDecodeAudio_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::Decryptor_Status>(
            in_status, &params->status);
        typename decltype(params->audio_buffers)::BaseType* audio_buffers_ptr;
        const mojo::internal::ContainerValidateParams audio_buffers_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::media::mojom::AudioBufferDataView>>(
            in_audio_buffers, builder.buffer(), &audio_buffers_ptr, &audio_buffers_validate_params,
            &serialization_context_);
        params->audio_buffers.Set(audio_buffers_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->audio_buffers.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null audio_buffers in Decryptor.DecryptAndDecodeAudio response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Decryptor_DecryptAndDecodeVideo_ProxyToResponder {
    public:
        static Decryptor::DecryptAndDecodeVideoCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Decryptor_DecryptAndDecodeVideo_ProxyToResponder> proxy(
                new Decryptor_DecryptAndDecodeVideo_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Decryptor_DecryptAndDecodeVideo_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Decryptor_DecryptAndDecodeVideo_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Decryptor::DecryptAndDecodeVideo() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Decryptor_DecryptAndDecodeVideo_ProxyToResponder(
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
            media::Decryptor::Status in_status, ::media::mojom::VideoFramePtr in_video_frame);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Decryptor_DecryptAndDecodeVideo_ProxyToResponder);
    };

    void Decryptor_DecryptAndDecodeVideo_ProxyToResponder::Run(
        media::Decryptor::Status in_status, ::media::mojom::VideoFramePtr in_video_frame)
    {
        size_t size = sizeof(::media::mojom::internal::Decryptor_DecryptAndDecodeVideo_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::VideoFrameDataView>(
            in_video_frame, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDecryptor_DecryptAndDecodeVideo_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::Decryptor_DecryptAndDecodeVideo_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::Decryptor_Status>(
            in_status, &params->status);
        typename decltype(params->video_frame)::BaseType* video_frame_ptr;
        mojo::internal::Serialize<::media::mojom::VideoFrameDataView>(
            in_video_frame, builder.buffer(), &video_frame_ptr, &serialization_context_);
        params->video_frame.Set(video_frame_ptr);
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
    bool DecryptorStubDispatch::Accept(
        Decryptor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDecryptor_Initialize_Name: {
            internal::Decryptor_Initialize_Params_Data* params = reinterpret_cast<internal::Decryptor_Initialize_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedDataPipeConsumerHandle p_receive_pipe {};
            mojo::ScopedDataPipeProducerHandle p_transmit_pipe {};
            Decryptor_Initialize_ParamsDataView input_data_view(params,
                context);

            p_receive_pipe = input_data_view.TakeReceivePipe();
            p_transmit_pipe = input_data_view.TakeTransmitPipe();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::Initialize deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::Initialize");
            mojo::internal::MessageDispatchContext context(message);
            impl->Initialize(
                std::move(p_receive_pipe),
                std::move(p_transmit_pipe));
            return true;
        }
        case internal::kDecryptor_Decrypt_Name: {
            break;
        }
        case internal::kDecryptor_CancelDecrypt_Name: {
            internal::Decryptor_CancelDecrypt_Params_Data* params = reinterpret_cast<internal::Decryptor_CancelDecrypt_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            media::Decryptor::StreamType p_stream_type {};
            Decryptor_CancelDecrypt_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadStreamType(&p_stream_type))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::CancelDecrypt deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::CancelDecrypt");
            mojo::internal::MessageDispatchContext context(message);
            impl->CancelDecrypt(
                std::move(p_stream_type));
            return true;
        }
        case internal::kDecryptor_InitializeAudioDecoder_Name: {
            break;
        }
        case internal::kDecryptor_InitializeVideoDecoder_Name: {
            break;
        }
        case internal::kDecryptor_DecryptAndDecodeAudio_Name: {
            break;
        }
        case internal::kDecryptor_DecryptAndDecodeVideo_Name: {
            break;
        }
        case internal::kDecryptor_ResetDecoder_Name: {
            internal::Decryptor_ResetDecoder_Params_Data* params = reinterpret_cast<internal::Decryptor_ResetDecoder_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            media::Decryptor::StreamType p_stream_type {};
            Decryptor_ResetDecoder_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadStreamType(&p_stream_type))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::ResetDecoder deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::ResetDecoder");
            mojo::internal::MessageDispatchContext context(message);
            impl->ResetDecoder(
                std::move(p_stream_type));
            return true;
        }
        case internal::kDecryptor_DeinitializeDecoder_Name: {
            internal::Decryptor_DeinitializeDecoder_Params_Data* params = reinterpret_cast<internal::Decryptor_DeinitializeDecoder_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            media::Decryptor::StreamType p_stream_type {};
            Decryptor_DeinitializeDecoder_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadStreamType(&p_stream_type))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::DeinitializeDecoder deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::DeinitializeDecoder");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeinitializeDecoder(
                std::move(p_stream_type));
            return true;
        }
        case internal::kDecryptor_ReleaseSharedBuffer_Name: {
            internal::Decryptor_ReleaseSharedBuffer_Params_Data* params = reinterpret_cast<internal::Decryptor_ReleaseSharedBuffer_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedSharedBufferHandle p_buffer {};
            uint64_t p_buffer_size {};
            Decryptor_ReleaseSharedBuffer_ParamsDataView input_data_view(params,
                context);

            p_buffer = input_data_view.TakeBuffer();
            p_buffer_size = input_data_view.buffer_size();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::ReleaseSharedBuffer deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::ReleaseSharedBuffer");
            mojo::internal::MessageDispatchContext context(message);
            impl->ReleaseSharedBuffer(
                std::move(p_buffer),
                std::move(p_buffer_size));
            return true;
        }
        }
        return false;
    }

    // static
    bool DecryptorStubDispatch::AcceptWithResponder(
        Decryptor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDecryptor_Initialize_Name: {
            break;
        }
        case internal::kDecryptor_Decrypt_Name: {
            internal::Decryptor_Decrypt_Params_Data* params = reinterpret_cast<internal::Decryptor_Decrypt_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            media::Decryptor::StreamType p_stream_type {};
            ::media::mojom::DecoderBufferPtr p_encrypted {};
            Decryptor_Decrypt_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadStreamType(&p_stream_type))
                success = false;
            if (!input_data_view.ReadEncrypted(&p_encrypted))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::Decrypt deserializer");
                return false;
            }
            Decryptor::DecryptCallback callback = Decryptor_Decrypt_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::Decrypt");
            mojo::internal::MessageDispatchContext context(message);
            impl->Decrypt(
                std::move(p_stream_type),
                std::move(p_encrypted), std::move(callback));
            return true;
        }
        case internal::kDecryptor_CancelDecrypt_Name: {
            break;
        }
        case internal::kDecryptor_InitializeAudioDecoder_Name: {
            internal::Decryptor_InitializeAudioDecoder_Params_Data* params = reinterpret_cast<internal::Decryptor_InitializeAudioDecoder_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::AudioDecoderConfigPtr p_config {};
            Decryptor_InitializeAudioDecoder_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadConfig(&p_config))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::InitializeAudioDecoder deserializer");
                return false;
            }
            Decryptor::InitializeAudioDecoderCallback callback = Decryptor_InitializeAudioDecoder_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::InitializeAudioDecoder");
            mojo::internal::MessageDispatchContext context(message);
            impl->InitializeAudioDecoder(
                std::move(p_config), std::move(callback));
            return true;
        }
        case internal::kDecryptor_InitializeVideoDecoder_Name: {
            internal::Decryptor_InitializeVideoDecoder_Params_Data* params = reinterpret_cast<internal::Decryptor_InitializeVideoDecoder_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::VideoDecoderConfigPtr p_config {};
            Decryptor_InitializeVideoDecoder_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadConfig(&p_config))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::InitializeVideoDecoder deserializer");
                return false;
            }
            Decryptor::InitializeVideoDecoderCallback callback = Decryptor_InitializeVideoDecoder_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::InitializeVideoDecoder");
            mojo::internal::MessageDispatchContext context(message);
            impl->InitializeVideoDecoder(
                std::move(p_config), std::move(callback));
            return true;
        }
        case internal::kDecryptor_DecryptAndDecodeAudio_Name: {
            internal::Decryptor_DecryptAndDecodeAudio_Params_Data* params = reinterpret_cast<internal::Decryptor_DecryptAndDecodeAudio_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::DecoderBufferPtr p_encrypted {};
            Decryptor_DecryptAndDecodeAudio_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadEncrypted(&p_encrypted))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::DecryptAndDecodeAudio deserializer");
                return false;
            }
            Decryptor::DecryptAndDecodeAudioCallback callback = Decryptor_DecryptAndDecodeAudio_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::DecryptAndDecodeAudio");
            mojo::internal::MessageDispatchContext context(message);
            impl->DecryptAndDecodeAudio(
                std::move(p_encrypted), std::move(callback));
            return true;
        }
        case internal::kDecryptor_DecryptAndDecodeVideo_Name: {
            internal::Decryptor_DecryptAndDecodeVideo_Params_Data* params = reinterpret_cast<internal::Decryptor_DecryptAndDecodeVideo_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::DecoderBufferPtr p_encrypted {};
            Decryptor_DecryptAndDecodeVideo_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadEncrypted(&p_encrypted))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Decryptor::DecryptAndDecodeVideo deserializer");
                return false;
            }
            Decryptor::DecryptAndDecodeVideoCallback callback = Decryptor_DecryptAndDecodeVideo_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Decryptor::DecryptAndDecodeVideo");
            mojo::internal::MessageDispatchContext context(message);
            impl->DecryptAndDecodeVideo(
                std::move(p_encrypted), std::move(callback));
            return true;
        }
        case internal::kDecryptor_ResetDecoder_Name: {
            break;
        }
        case internal::kDecryptor_DeinitializeDecoder_Name: {
            break;
        }
        case internal::kDecryptor_ReleaseSharedBuffer_Name: {
            break;
        }
        }
        return false;
    }

    bool DecryptorRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Decryptor RequestValidator");

        switch (message->header()->name) {
        case internal::kDecryptor_Initialize_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_Initialize_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_Decrypt_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_Decrypt_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_CancelDecrypt_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_CancelDecrypt_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_InitializeAudioDecoder_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_InitializeAudioDecoder_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_InitializeVideoDecoder_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_InitializeVideoDecoder_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_DecryptAndDecodeAudio_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_DecryptAndDecodeAudio_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_DecryptAndDecodeVideo_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_DecryptAndDecodeVideo_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_ResetDecoder_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_ResetDecoder_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_DeinitializeDecoder_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_DeinitializeDecoder_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_ReleaseSharedBuffer_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_ReleaseSharedBuffer_Params_Data>(
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

    bool DecryptorResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Decryptor ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kDecryptor_Decrypt_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_Decrypt_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_InitializeAudioDecoder_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_InitializeAudioDecoder_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_InitializeVideoDecoder_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_InitializeVideoDecoder_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_DecryptAndDecodeAudio_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_DecryptAndDecodeAudio_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDecryptor_DecryptAndDecodeVideo_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Decryptor_DecryptAndDecodeVideo_ResponseParams_Data>(
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