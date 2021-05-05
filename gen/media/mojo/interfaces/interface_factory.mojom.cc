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

#include "media/mojo/interfaces/interface_factory.mojom.h"

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
    const char InterfaceFactory::Name_[] = "media::mojom::InterfaceFactory";

    InterfaceFactoryProxy::InterfaceFactoryProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void InterfaceFactoryProxy::CreateAudioDecoder(
        ::media::mojom::AudioDecoderRequest in_audio_decoder)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::InterfaceFactory_CreateAudioDecoder_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kInterfaceFactory_CreateAudioDecoder_Name, size);

        auto params = ::media::mojom::internal::InterfaceFactory_CreateAudioDecoder_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::AudioDecoderRequestDataView>(
            in_audio_decoder, &params->audio_decoder, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->audio_decoder),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid audio_decoder in InterfaceFactory.CreateAudioDecoder request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void InterfaceFactoryProxy::CreateVideoDecoder(
        ::media::mojom::VideoDecoderRequest in_video_decoder)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::InterfaceFactory_CreateVideoDecoder_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kInterfaceFactory_CreateVideoDecoder_Name, size);

        auto params = ::media::mojom::internal::InterfaceFactory_CreateVideoDecoder_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::VideoDecoderRequestDataView>(
            in_video_decoder, &params->video_decoder, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->video_decoder),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid video_decoder in InterfaceFactory.CreateVideoDecoder request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void InterfaceFactoryProxy::CreateRenderer(
        const std::string& in_audio_device_id, ::media::mojom::RendererRequest in_renderer)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::InterfaceFactory_CreateRenderer_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_audio_device_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kInterfaceFactory_CreateRenderer_Name, size);

        auto params = ::media::mojom::internal::InterfaceFactory_CreateRenderer_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->audio_device_id)::BaseType* audio_device_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_audio_device_id, builder.buffer(), &audio_device_id_ptr, &serialization_context);
        params->audio_device_id.Set(audio_device_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->audio_device_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null audio_device_id in InterfaceFactory.CreateRenderer request");
        mojo::internal::Serialize<::media::mojom::RendererRequestDataView>(
            in_renderer, &params->renderer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->renderer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid renderer in InterfaceFactory.CreateRenderer request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void InterfaceFactoryProxy::CreateCdm(
        ::media::mojom::ContentDecryptionModuleRequest in_cdm)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::InterfaceFactory_CreateCdm_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kInterfaceFactory_CreateCdm_Name, size);

        auto params = ::media::mojom::internal::InterfaceFactory_CreateCdm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::ContentDecryptionModuleRequestDataView>(
            in_cdm, &params->cdm, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->cdm),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid cdm in InterfaceFactory.CreateCdm request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool InterfaceFactoryStubDispatch::Accept(
        InterfaceFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kInterfaceFactory_CreateAudioDecoder_Name: {
            internal::InterfaceFactory_CreateAudioDecoder_Params_Data* params = reinterpret_cast<internal::InterfaceFactory_CreateAudioDecoder_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::AudioDecoderRequest p_audio_decoder {};
            InterfaceFactory_CreateAudioDecoder_ParamsDataView input_data_view(params,
                context);

            p_audio_decoder = input_data_view.TakeAudioDecoder<decltype(p_audio_decoder)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "InterfaceFactory::CreateAudioDecoder deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "InterfaceFactory::CreateAudioDecoder");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateAudioDecoder(
                std::move(p_audio_decoder));
            return true;
        }
        case internal::kInterfaceFactory_CreateVideoDecoder_Name: {
            internal::InterfaceFactory_CreateVideoDecoder_Params_Data* params = reinterpret_cast<internal::InterfaceFactory_CreateVideoDecoder_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::VideoDecoderRequest p_video_decoder {};
            InterfaceFactory_CreateVideoDecoder_ParamsDataView input_data_view(params,
                context);

            p_video_decoder = input_data_view.TakeVideoDecoder<decltype(p_video_decoder)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "InterfaceFactory::CreateVideoDecoder deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "InterfaceFactory::CreateVideoDecoder");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateVideoDecoder(
                std::move(p_video_decoder));
            return true;
        }
        case internal::kInterfaceFactory_CreateRenderer_Name: {
            internal::InterfaceFactory_CreateRenderer_Params_Data* params = reinterpret_cast<internal::InterfaceFactory_CreateRenderer_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_audio_device_id {};
            ::media::mojom::RendererRequest p_renderer {};
            InterfaceFactory_CreateRenderer_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadAudioDeviceId(&p_audio_device_id))
                success = false;
            p_renderer = input_data_view.TakeRenderer<decltype(p_renderer)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "InterfaceFactory::CreateRenderer deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "InterfaceFactory::CreateRenderer");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateRenderer(
                std::move(p_audio_device_id),
                std::move(p_renderer));
            return true;
        }
        case internal::kInterfaceFactory_CreateCdm_Name: {
            internal::InterfaceFactory_CreateCdm_Params_Data* params = reinterpret_cast<internal::InterfaceFactory_CreateCdm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::ContentDecryptionModuleRequest p_cdm {};
            InterfaceFactory_CreateCdm_ParamsDataView input_data_view(params,
                context);

            p_cdm = input_data_view.TakeCdm<decltype(p_cdm)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "InterfaceFactory::CreateCdm deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "InterfaceFactory::CreateCdm");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateCdm(
                std::move(p_cdm));
            return true;
        }
        }
        return false;
    }

    // static
    bool InterfaceFactoryStubDispatch::AcceptWithResponder(
        InterfaceFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kInterfaceFactory_CreateAudioDecoder_Name: {
            break;
        }
        case internal::kInterfaceFactory_CreateVideoDecoder_Name: {
            break;
        }
        case internal::kInterfaceFactory_CreateRenderer_Name: {
            break;
        }
        case internal::kInterfaceFactory_CreateCdm_Name: {
            break;
        }
        }
        return false;
    }

    bool InterfaceFactoryRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "InterfaceFactory RequestValidator");

        switch (message->header()->name) {
        case internal::kInterfaceFactory_CreateAudioDecoder_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::InterfaceFactory_CreateAudioDecoder_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kInterfaceFactory_CreateVideoDecoder_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::InterfaceFactory_CreateVideoDecoder_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kInterfaceFactory_CreateRenderer_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::InterfaceFactory_CreateRenderer_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kInterfaceFactory_CreateCdm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::InterfaceFactory_CreateCdm_Params_Data>(
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