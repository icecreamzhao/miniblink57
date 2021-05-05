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

#include "media/mojo/interfaces/audio_decoder.mojom.h"

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
    const char AudioDecoder::Name_[] = "media::mojom::AudioDecoder";

    class AudioDecoder_Initialize_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        AudioDecoder_Initialize_ForwardToCallback(
            const AudioDecoder::InitializeCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        AudioDecoder::InitializeCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(AudioDecoder_Initialize_ForwardToCallback);
    };
    bool AudioDecoder_Initialize_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::AudioDecoder_Initialize_ResponseParams_Data* params = reinterpret_cast<internal::AudioDecoder_Initialize_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        bool p_needs_bitstream_conversion {};
        AudioDecoder_Initialize_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        p_needs_bitstream_conversion = input_data_view.needs_bitstream_conversion();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "AudioDecoder::Initialize response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success),
                std::move(p_needs_bitstream_conversion));
        }
        return true;
    }

    class AudioDecoder_Decode_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        AudioDecoder_Decode_ForwardToCallback(
            const AudioDecoder::DecodeCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        AudioDecoder::DecodeCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(AudioDecoder_Decode_ForwardToCallback);
    };
    bool AudioDecoder_Decode_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::AudioDecoder_Decode_ResponseParams_Data* params = reinterpret_cast<internal::AudioDecoder_Decode_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        media::DecodeStatus p_status {};
        AudioDecoder_Decode_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "AudioDecoder::Decode response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class AudioDecoder_Reset_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        AudioDecoder_Reset_ForwardToCallback(
            const AudioDecoder::ResetCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        AudioDecoder::ResetCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(AudioDecoder_Reset_ForwardToCallback);
    };
    bool AudioDecoder_Reset_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::AudioDecoder_Reset_ResponseParams_Data* params = reinterpret_cast<internal::AudioDecoder_Reset_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        AudioDecoder_Reset_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "AudioDecoder::Reset response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run();
        }
        return true;
    }

    AudioDecoderProxy::AudioDecoderProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void AudioDecoderProxy::Construct(
        AudioDecoderClientAssociatedPtrInfo in_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::AudioDecoder_Construct_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAudioDecoder_Construct_Name, size);

        auto params = ::media::mojom::internal::AudioDecoder_Construct_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::AudioDecoderClientAssociatedPtrInfoDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid client in AudioDecoder.Construct request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AudioDecoderProxy::Initialize(
        ::media::mojom::AudioDecoderConfigPtr in_config, int32_t in_cdm_id, const InitializeCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::AudioDecoder_Initialize_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::AudioDecoderConfigDataView>(
            in_config, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kAudioDecoder_Initialize_Name, size);

        auto params = ::media::mojom::internal::AudioDecoder_Initialize_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->config)::BaseType* config_ptr;
        mojo::internal::Serialize<::media::mojom::AudioDecoderConfigDataView>(
            in_config, builder.buffer(), &config_ptr, &serialization_context);
        params->config.Set(config_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->config.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null config in AudioDecoder.Initialize request");
        params->cdm_id = in_cdm_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new AudioDecoder_Initialize_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void AudioDecoderProxy::SetDataSource(
        mojo::ScopedDataPipeConsumerHandle in_receive_pipe)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::AudioDecoder_SetDataSource_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAudioDecoder_SetDataSource_Name, size);

        auto params = ::media::mojom::internal::AudioDecoder_SetDataSource_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedDataPipeConsumerHandle>(
            in_receive_pipe, &params->receive_pipe, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->receive_pipe),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid receive_pipe in AudioDecoder.SetDataSource request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AudioDecoderProxy::Decode(
        ::media::mojom::DecoderBufferPtr in_buffer, const DecodeCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::AudioDecoder_Decode_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::DecoderBufferDataView>(
            in_buffer, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kAudioDecoder_Decode_Name, size);

        auto params = ::media::mojom::internal::AudioDecoder_Decode_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->buffer)::BaseType* buffer_ptr;
        mojo::internal::Serialize<::media::mojom::DecoderBufferDataView>(
            in_buffer, builder.buffer(), &buffer_ptr, &serialization_context);
        params->buffer.Set(buffer_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->buffer.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null buffer in AudioDecoder.Decode request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new AudioDecoder_Decode_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void AudioDecoderProxy::Reset(
        const ResetCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::AudioDecoder_Reset_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kAudioDecoder_Reset_Name, size);

        auto params = ::media::mojom::internal::AudioDecoder_Reset_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new AudioDecoder_Reset_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class AudioDecoder_Initialize_ProxyToResponder {
    public:
        static AudioDecoder::InitializeCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<AudioDecoder_Initialize_ProxyToResponder> proxy(
                new AudioDecoder_Initialize_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&AudioDecoder_Initialize_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~AudioDecoder_Initialize_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "AudioDecoder::Initialize() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        AudioDecoder_Initialize_ProxyToResponder(
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
            bool in_success, bool in_needs_bitstream_conversion);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(AudioDecoder_Initialize_ProxyToResponder);
    };

    void AudioDecoder_Initialize_ProxyToResponder::Run(
        bool in_success, bool in_needs_bitstream_conversion)
    {
        size_t size = sizeof(::media::mojom::internal::AudioDecoder_Initialize_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kAudioDecoder_Initialize_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::AudioDecoder_Initialize_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
        params->needs_bitstream_conversion = in_needs_bitstream_conversion;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class AudioDecoder_Decode_ProxyToResponder {
    public:
        static AudioDecoder::DecodeCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<AudioDecoder_Decode_ProxyToResponder> proxy(
                new AudioDecoder_Decode_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&AudioDecoder_Decode_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~AudioDecoder_Decode_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "AudioDecoder::Decode() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        AudioDecoder_Decode_ProxyToResponder(
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
            media::DecodeStatus in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(AudioDecoder_Decode_ProxyToResponder);
    };

    void AudioDecoder_Decode_ProxyToResponder::Run(
        media::DecodeStatus in_status)
    {
        size_t size = sizeof(::media::mojom::internal::AudioDecoder_Decode_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kAudioDecoder_Decode_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::AudioDecoder_Decode_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::DecodeStatus>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class AudioDecoder_Reset_ProxyToResponder {
    public:
        static AudioDecoder::ResetCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<AudioDecoder_Reset_ProxyToResponder> proxy(
                new AudioDecoder_Reset_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&AudioDecoder_Reset_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~AudioDecoder_Reset_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "AudioDecoder::Reset() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        AudioDecoder_Reset_ProxyToResponder(
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

        void Run();

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(AudioDecoder_Reset_ProxyToResponder);
    };

    void AudioDecoder_Reset_ProxyToResponder::Run()
    {
        size_t size = sizeof(::media::mojom::internal::AudioDecoder_Reset_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kAudioDecoder_Reset_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::AudioDecoder_Reset_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
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
    bool AudioDecoderStubDispatch::Accept(
        AudioDecoder* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kAudioDecoder_Construct_Name: {
            internal::AudioDecoder_Construct_Params_Data* params = reinterpret_cast<internal::AudioDecoder_Construct_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AudioDecoderClientAssociatedPtrInfo p_client {};
            AudioDecoder_Construct_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AudioDecoder::Construct deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AudioDecoder::Construct");
            mojo::internal::MessageDispatchContext context(message);
            impl->Construct(
                std::move(p_client));
            return true;
        }
        case internal::kAudioDecoder_Initialize_Name: {
            break;
        }
        case internal::kAudioDecoder_SetDataSource_Name: {
            internal::AudioDecoder_SetDataSource_Params_Data* params = reinterpret_cast<internal::AudioDecoder_SetDataSource_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedDataPipeConsumerHandle p_receive_pipe {};
            AudioDecoder_SetDataSource_ParamsDataView input_data_view(params,
                context);

            p_receive_pipe = input_data_view.TakeReceivePipe();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AudioDecoder::SetDataSource deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AudioDecoder::SetDataSource");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetDataSource(
                std::move(p_receive_pipe));
            return true;
        }
        case internal::kAudioDecoder_Decode_Name: {
            break;
        }
        case internal::kAudioDecoder_Reset_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool AudioDecoderStubDispatch::AcceptWithResponder(
        AudioDecoder* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kAudioDecoder_Construct_Name: {
            break;
        }
        case internal::kAudioDecoder_Initialize_Name: {
            internal::AudioDecoder_Initialize_Params_Data* params = reinterpret_cast<internal::AudioDecoder_Initialize_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::AudioDecoderConfigPtr p_config {};
            int32_t p_cdm_id {};
            AudioDecoder_Initialize_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadConfig(&p_config))
                success = false;
            p_cdm_id = input_data_view.cdm_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AudioDecoder::Initialize deserializer");
                return false;
            }
            AudioDecoder::InitializeCallback callback = AudioDecoder_Initialize_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AudioDecoder::Initialize");
            mojo::internal::MessageDispatchContext context(message);
            impl->Initialize(
                std::move(p_config),
                std::move(p_cdm_id), std::move(callback));
            return true;
        }
        case internal::kAudioDecoder_SetDataSource_Name: {
            break;
        }
        case internal::kAudioDecoder_Decode_Name: {
            internal::AudioDecoder_Decode_Params_Data* params = reinterpret_cast<internal::AudioDecoder_Decode_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::DecoderBufferPtr p_buffer {};
            AudioDecoder_Decode_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadBuffer(&p_buffer))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AudioDecoder::Decode deserializer");
                return false;
            }
            AudioDecoder::DecodeCallback callback = AudioDecoder_Decode_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AudioDecoder::Decode");
            mojo::internal::MessageDispatchContext context(message);
            impl->Decode(
                std::move(p_buffer), std::move(callback));
            return true;
        }
        case internal::kAudioDecoder_Reset_Name: {
            internal::AudioDecoder_Reset_Params_Data* params = reinterpret_cast<internal::AudioDecoder_Reset_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AudioDecoder_Reset_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AudioDecoder::Reset deserializer");
                return false;
            }
            AudioDecoder::ResetCallback callback = AudioDecoder_Reset_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AudioDecoder::Reset");
            mojo::internal::MessageDispatchContext context(message);
            impl->Reset(std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool AudioDecoderRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AudioDecoder RequestValidator");

        switch (message->header()->name) {
        case internal::kAudioDecoder_Construct_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioDecoder_Construct_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAudioDecoder_Initialize_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioDecoder_Initialize_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAudioDecoder_SetDataSource_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioDecoder_SetDataSource_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAudioDecoder_Decode_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioDecoder_Decode_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAudioDecoder_Reset_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioDecoder_Reset_Params_Data>(
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

    bool AudioDecoderResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AudioDecoder ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kAudioDecoder_Initialize_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioDecoder_Initialize_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAudioDecoder_Decode_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioDecoder_Decode_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAudioDecoder_Reset_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioDecoder_Reset_ResponseParams_Data>(
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
    const char AudioDecoderClient::Name_[] = "media::mojom::AudioDecoderClient";

    AudioDecoderClientProxy::AudioDecoderClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void AudioDecoderClientProxy::OnBufferDecoded(
        ::media::mojom::AudioBufferPtr in_buffer)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::AudioDecoderClient_OnBufferDecoded_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::AudioBufferDataView>(
            in_buffer, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAudioDecoderClient_OnBufferDecoded_Name, size);

        auto params = ::media::mojom::internal::AudioDecoderClient_OnBufferDecoded_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->buffer)::BaseType* buffer_ptr;
        mojo::internal::Serialize<::media::mojom::AudioBufferDataView>(
            in_buffer, builder.buffer(), &buffer_ptr, &serialization_context);
        params->buffer.Set(buffer_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->buffer.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null buffer in AudioDecoderClient.OnBufferDecoded request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool AudioDecoderClientStubDispatch::Accept(
        AudioDecoderClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kAudioDecoderClient_OnBufferDecoded_Name: {
            internal::AudioDecoderClient_OnBufferDecoded_Params_Data* params = reinterpret_cast<internal::AudioDecoderClient_OnBufferDecoded_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::AudioBufferPtr p_buffer {};
            AudioDecoderClient_OnBufferDecoded_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadBuffer(&p_buffer))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AudioDecoderClient::OnBufferDecoded deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AudioDecoderClient::OnBufferDecoded");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnBufferDecoded(
                std::move(p_buffer));
            return true;
        }
        }
        return false;
    }

    // static
    bool AudioDecoderClientStubDispatch::AcceptWithResponder(
        AudioDecoderClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kAudioDecoderClient_OnBufferDecoded_Name: {
            break;
        }
        }
        return false;
    }

    bool AudioDecoderClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AudioDecoderClient RequestValidator");

        switch (message->header()->name) {
        case internal::kAudioDecoderClient_OnBufferDecoded_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AudioDecoderClient_OnBufferDecoded_Params_Data>(
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