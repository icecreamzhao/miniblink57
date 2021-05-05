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

#include "media/mojo/interfaces/video_decoder.mojom.h"

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
namespace mojom { // static
    CommandBufferIdPtr CommandBufferId::New()
    {
        CommandBufferIdPtr rv;
        mojo::internal::StructHelper<CommandBufferId>::Initialize(&rv);
        return rv;
    }

    CommandBufferId::CommandBufferId()
        : channel_token()
        , route_id()
    {
    }

    CommandBufferId::~CommandBufferId()
    {
    }
    const char VideoDecoder::Name_[] = "media::mojom::VideoDecoder";

    class VideoDecoder_Initialize_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        VideoDecoder_Initialize_ForwardToCallback(
            const VideoDecoder::InitializeCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        VideoDecoder::InitializeCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(VideoDecoder_Initialize_ForwardToCallback);
    };
    bool VideoDecoder_Initialize_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::VideoDecoder_Initialize_ResponseParams_Data* params = reinterpret_cast<internal::VideoDecoder_Initialize_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        bool p_needs_bitstream_conversion {};
        int32_t p_max_decode_requests {};
        VideoDecoder_Initialize_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        p_needs_bitstream_conversion = input_data_view.needs_bitstream_conversion();
        p_max_decode_requests = input_data_view.max_decode_requests();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VideoDecoder::Initialize response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success),
                std::move(p_needs_bitstream_conversion),
                std::move(p_max_decode_requests));
        }
        return true;
    }

    class VideoDecoder_Decode_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        VideoDecoder_Decode_ForwardToCallback(
            const VideoDecoder::DecodeCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        VideoDecoder::DecodeCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(VideoDecoder_Decode_ForwardToCallback);
    };
    bool VideoDecoder_Decode_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::VideoDecoder_Decode_ResponseParams_Data* params = reinterpret_cast<internal::VideoDecoder_Decode_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        media::DecodeStatus p_status {};
        VideoDecoder_Decode_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VideoDecoder::Decode response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class VideoDecoder_Reset_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        VideoDecoder_Reset_ForwardToCallback(
            const VideoDecoder::ResetCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        VideoDecoder::ResetCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(VideoDecoder_Reset_ForwardToCallback);
    };
    bool VideoDecoder_Reset_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::VideoDecoder_Reset_ResponseParams_Data* params = reinterpret_cast<internal::VideoDecoder_Reset_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        VideoDecoder_Reset_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VideoDecoder::Reset response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run();
        }
        return true;
    }

    VideoDecoderProxy::VideoDecoderProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void VideoDecoderProxy::Construct(
        VideoDecoderClientAssociatedPtrInfo in_client, mojo::ScopedDataPipeConsumerHandle in_decoder_buffer_pipe, CommandBufferIdPtr in_command_buffer_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::VideoDecoder_Construct_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::CommandBufferIdDataView>(
            in_command_buffer_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVideoDecoder_Construct_Name, size);

        auto params = ::media::mojom::internal::VideoDecoder_Construct_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::VideoDecoderClientAssociatedPtrInfoDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid client in VideoDecoder.Construct request");
        mojo::internal::Serialize<mojo::ScopedDataPipeConsumerHandle>(
            in_decoder_buffer_pipe, &params->decoder_buffer_pipe, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->decoder_buffer_pipe),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid decoder_buffer_pipe in VideoDecoder.Construct request");
        typename decltype(params->command_buffer_id)::BaseType* command_buffer_id_ptr;
        mojo::internal::Serialize<::media::mojom::CommandBufferIdDataView>(
            in_command_buffer_id, builder.buffer(), &command_buffer_id_ptr, &serialization_context);
        params->command_buffer_id.Set(command_buffer_id_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoDecoderProxy::Initialize(
        ::media::mojom::VideoDecoderConfigPtr in_config, bool in_low_delay, const InitializeCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::VideoDecoder_Initialize_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::VideoDecoderConfigDataView>(
            in_config, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kVideoDecoder_Initialize_Name, size);

        auto params = ::media::mojom::internal::VideoDecoder_Initialize_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->config)::BaseType* config_ptr;
        mojo::internal::Serialize<::media::mojom::VideoDecoderConfigDataView>(
            in_config, builder.buffer(), &config_ptr, &serialization_context);
        params->config.Set(config_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->config.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null config in VideoDecoder.Initialize request");
        params->low_delay = in_low_delay;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new VideoDecoder_Initialize_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void VideoDecoderProxy::Decode(
        ::media::mojom::DecoderBufferPtr in_buffer, const DecodeCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::VideoDecoder_Decode_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::DecoderBufferDataView>(
            in_buffer, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kVideoDecoder_Decode_Name, size);

        auto params = ::media::mojom::internal::VideoDecoder_Decode_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->buffer)::BaseType* buffer_ptr;
        mojo::internal::Serialize<::media::mojom::DecoderBufferDataView>(
            in_buffer, builder.buffer(), &buffer_ptr, &serialization_context);
        params->buffer.Set(buffer_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->buffer.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null buffer in VideoDecoder.Decode request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new VideoDecoder_Decode_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void VideoDecoderProxy::Reset(
        const ResetCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::VideoDecoder_Reset_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kVideoDecoder_Reset_Name, size);

        auto params = ::media::mojom::internal::VideoDecoder_Reset_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new VideoDecoder_Reset_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class VideoDecoder_Initialize_ProxyToResponder {
    public:
        static VideoDecoder::InitializeCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<VideoDecoder_Initialize_ProxyToResponder> proxy(
                new VideoDecoder_Initialize_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&VideoDecoder_Initialize_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~VideoDecoder_Initialize_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "VideoDecoder::Initialize() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        VideoDecoder_Initialize_ProxyToResponder(
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
            bool in_success, bool in_needs_bitstream_conversion, int32_t in_max_decode_requests);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(VideoDecoder_Initialize_ProxyToResponder);
    };

    void VideoDecoder_Initialize_ProxyToResponder::Run(
        bool in_success, bool in_needs_bitstream_conversion, int32_t in_max_decode_requests)
    {
        size_t size = sizeof(::media::mojom::internal::VideoDecoder_Initialize_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kVideoDecoder_Initialize_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::VideoDecoder_Initialize_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
        params->needs_bitstream_conversion = in_needs_bitstream_conversion;
        params->max_decode_requests = in_max_decode_requests;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class VideoDecoder_Decode_ProxyToResponder {
    public:
        static VideoDecoder::DecodeCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<VideoDecoder_Decode_ProxyToResponder> proxy(
                new VideoDecoder_Decode_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&VideoDecoder_Decode_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~VideoDecoder_Decode_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "VideoDecoder::Decode() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        VideoDecoder_Decode_ProxyToResponder(
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

        DISALLOW_COPY_AND_ASSIGN(VideoDecoder_Decode_ProxyToResponder);
    };

    void VideoDecoder_Decode_ProxyToResponder::Run(
        media::DecodeStatus in_status)
    {
        size_t size = sizeof(::media::mojom::internal::VideoDecoder_Decode_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kVideoDecoder_Decode_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::VideoDecoder_Decode_ResponseParams_Data::New(builder.buffer());
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
    class VideoDecoder_Reset_ProxyToResponder {
    public:
        static VideoDecoder::ResetCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<VideoDecoder_Reset_ProxyToResponder> proxy(
                new VideoDecoder_Reset_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&VideoDecoder_Reset_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~VideoDecoder_Reset_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "VideoDecoder::Reset() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        VideoDecoder_Reset_ProxyToResponder(
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

        DISALLOW_COPY_AND_ASSIGN(VideoDecoder_Reset_ProxyToResponder);
    };

    void VideoDecoder_Reset_ProxyToResponder::Run()
    {
        size_t size = sizeof(::media::mojom::internal::VideoDecoder_Reset_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kVideoDecoder_Reset_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::VideoDecoder_Reset_ResponseParams_Data::New(builder.buffer());
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
    bool VideoDecoderStubDispatch::Accept(
        VideoDecoder* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kVideoDecoder_Construct_Name: {
            internal::VideoDecoder_Construct_Params_Data* params = reinterpret_cast<internal::VideoDecoder_Construct_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VideoDecoderClientAssociatedPtrInfo p_client {};
            mojo::ScopedDataPipeConsumerHandle p_decoder_buffer_pipe {};
            CommandBufferIdPtr p_command_buffer_id {};
            VideoDecoder_Construct_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            p_decoder_buffer_pipe = input_data_view.TakeDecoderBufferPipe();
            if (!input_data_view.ReadCommandBufferId(&p_command_buffer_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoDecoder::Construct deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoDecoder::Construct");
            mojo::internal::MessageDispatchContext context(message);
            impl->Construct(
                std::move(p_client),
                std::move(p_decoder_buffer_pipe),
                std::move(p_command_buffer_id));
            return true;
        }
        case internal::kVideoDecoder_Initialize_Name: {
            break;
        }
        case internal::kVideoDecoder_Decode_Name: {
            break;
        }
        case internal::kVideoDecoder_Reset_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool VideoDecoderStubDispatch::AcceptWithResponder(
        VideoDecoder* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kVideoDecoder_Construct_Name: {
            break;
        }
        case internal::kVideoDecoder_Initialize_Name: {
            internal::VideoDecoder_Initialize_Params_Data* params = reinterpret_cast<internal::VideoDecoder_Initialize_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::VideoDecoderConfigPtr p_config {};
            bool p_low_delay {};
            VideoDecoder_Initialize_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadConfig(&p_config))
                success = false;
            p_low_delay = input_data_view.low_delay();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoDecoder::Initialize deserializer");
                return false;
            }
            VideoDecoder::InitializeCallback callback = VideoDecoder_Initialize_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoDecoder::Initialize");
            mojo::internal::MessageDispatchContext context(message);
            impl->Initialize(
                std::move(p_config),
                std::move(p_low_delay), std::move(callback));
            return true;
        }
        case internal::kVideoDecoder_Decode_Name: {
            internal::VideoDecoder_Decode_Params_Data* params = reinterpret_cast<internal::VideoDecoder_Decode_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::DecoderBufferPtr p_buffer {};
            VideoDecoder_Decode_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadBuffer(&p_buffer))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoDecoder::Decode deserializer");
                return false;
            }
            VideoDecoder::DecodeCallback callback = VideoDecoder_Decode_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoDecoder::Decode");
            mojo::internal::MessageDispatchContext context(message);
            impl->Decode(
                std::move(p_buffer), std::move(callback));
            return true;
        }
        case internal::kVideoDecoder_Reset_Name: {
            internal::VideoDecoder_Reset_Params_Data* params = reinterpret_cast<internal::VideoDecoder_Reset_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VideoDecoder_Reset_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoDecoder::Reset deserializer");
                return false;
            }
            VideoDecoder::ResetCallback callback = VideoDecoder_Reset_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoDecoder::Reset");
            mojo::internal::MessageDispatchContext context(message);
            impl->Reset(std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool VideoDecoderRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VideoDecoder RequestValidator");

        switch (message->header()->name) {
        case internal::kVideoDecoder_Construct_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoDecoder_Construct_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoDecoder_Initialize_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoDecoder_Initialize_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoDecoder_Decode_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoDecoder_Decode_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoDecoder_Reset_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoDecoder_Reset_Params_Data>(
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

    bool VideoDecoderResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VideoDecoder ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kVideoDecoder_Initialize_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoDecoder_Initialize_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoDecoder_Decode_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoDecoder_Decode_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoDecoder_Reset_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoDecoder_Reset_ResponseParams_Data>(
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
    const char VideoDecoderClient::Name_[] = "media::mojom::VideoDecoderClient";

    VideoDecoderClientProxy::VideoDecoderClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void VideoDecoderClientProxy::OnVideoFrameDecoded(
        ::media::mojom::VideoFramePtr in_frame)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::VideoDecoderClient_OnVideoFrameDecoded_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::VideoFrameDataView>(
            in_frame, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVideoDecoderClient_OnVideoFrameDecoded_Name, size);

        auto params = ::media::mojom::internal::VideoDecoderClient_OnVideoFrameDecoded_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->frame)::BaseType* frame_ptr;
        mojo::internal::Serialize<::media::mojom::VideoFrameDataView>(
            in_frame, builder.buffer(), &frame_ptr, &serialization_context);
        params->frame.Set(frame_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->frame.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null frame in VideoDecoderClient.OnVideoFrameDecoded request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool VideoDecoderClientStubDispatch::Accept(
        VideoDecoderClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kVideoDecoderClient_OnVideoFrameDecoded_Name: {
            internal::VideoDecoderClient_OnVideoFrameDecoded_Params_Data* params = reinterpret_cast<internal::VideoDecoderClient_OnVideoFrameDecoded_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::VideoFramePtr p_frame {};
            VideoDecoderClient_OnVideoFrameDecoded_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadFrame(&p_frame))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoDecoderClient::OnVideoFrameDecoded deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoDecoderClient::OnVideoFrameDecoded");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnVideoFrameDecoded(
                std::move(p_frame));
            return true;
        }
        }
        return false;
    }

    // static
    bool VideoDecoderClientStubDispatch::AcceptWithResponder(
        VideoDecoderClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kVideoDecoderClient_OnVideoFrameDecoded_Name: {
            break;
        }
        }
        return false;
    }

    bool VideoDecoderClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VideoDecoderClient RequestValidator");

        switch (message->header()->name) {
        case internal::kVideoDecoderClient_OnVideoFrameDecoded_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoDecoderClient_OnVideoFrameDecoded_Params_Data>(
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

// static
bool StructTraits<::media::mojom::CommandBufferId::DataView, ::media::mojom::CommandBufferIdPtr>::Read(
    ::media::mojom::CommandBufferId::DataView input,
    ::media::mojom::CommandBufferIdPtr* output)
{
    bool success = true;
    ::media::mojom::CommandBufferIdPtr result(::media::mojom::CommandBufferId::New());

    if (!input.ReadChannelToken(&result->channel_token))
        success = false;
    result->route_id = input.route_id();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif