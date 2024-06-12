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

#include "third_party/WebKit/public/platform/modules/mediasession/media_session.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "content/common/bluetooth/web_bluetooth_device_id_struct_traits.h"
#include "content/common/media/media_session_struct_traits.h"
#include "content/public/common/referrer_struct_traits.h"
#include "device/bluetooth/public/interfaces/uuid_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace blink {
namespace mojom { // static
    MediaImagePtr MediaImage::New()
    {
        MediaImagePtr rv;
        mojo::internal::StructHelper<MediaImage>::Initialize(&rv);
        return rv;
    }

    MediaImage::MediaImage()
        : src()
        , type()
        , sizes()
    {
    }

    MediaImage::~MediaImage()
    {
    } // static
    MediaMetadataPtr MediaMetadata::New()
    {
        MediaMetadataPtr rv;
        mojo::internal::StructHelper<MediaMetadata>::Initialize(&rv);
        return rv;
    }

    MediaMetadata::MediaMetadata()
        : title()
        , artist()
        , album()
        , artwork()
    {
    }

    MediaMetadata::~MediaMetadata()
    {
    }
    const char MediaSessionClient::Name_[] = "blink::mojom::MediaSessionClient";

    MediaSessionClientProxy::MediaSessionClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void MediaSessionClientProxy::DidReceiveAction(
        MediaSessionAction in_action)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::MediaSessionClient_DidReceiveAction_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMediaSessionClient_DidReceiveAction_Name, size);

        auto params = ::blink::mojom::internal::MediaSessionClient_DidReceiveAction_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::MediaSessionAction>(
            in_action, &params->action);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool MediaSessionClientStubDispatch::Accept(
        MediaSessionClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kMediaSessionClient_DidReceiveAction_Name: {
            internal::MediaSessionClient_DidReceiveAction_Params_Data* params = reinterpret_cast<internal::MediaSessionClient_DidReceiveAction_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            MediaSessionAction p_action {};
            MediaSessionClient_DidReceiveAction_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadAction(&p_action))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MediaSessionClient::DidReceiveAction deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MediaSessionClient::DidReceiveAction");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidReceiveAction(
                std::move(p_action));
            return true;
        }
        }
        return false;
    }

    // static
    bool MediaSessionClientStubDispatch::AcceptWithResponder(
        MediaSessionClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kMediaSessionClient_DidReceiveAction_Name: {
            break;
        }
        }
        return false;
    }

    bool MediaSessionClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "MediaSessionClient RequestValidator");

        switch (message->header()->name) {
        case internal::kMediaSessionClient_DidReceiveAction_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MediaSessionClient_DidReceiveAction_Params_Data>(
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

    const char MediaSessionService::Name_[] = "blink::mojom::MediaSessionService";

    MediaSessionServiceProxy::MediaSessionServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void MediaSessionServiceProxy::SetClient(
        MediaSessionClientPtr in_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::MediaSessionService_SetClient_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMediaSessionService_SetClient_Name, size);

        auto params = ::blink::mojom::internal::MediaSessionService_SetClient_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::MediaSessionClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in MediaSessionService.SetClient request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MediaSessionServiceProxy::SetPlaybackState(
        MediaSessionPlaybackState in_state)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::MediaSessionService_SetPlaybackState_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMediaSessionService_SetPlaybackState_Name, size);

        auto params = ::blink::mojom::internal::MediaSessionService_SetPlaybackState_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::MediaSessionPlaybackState>(
            in_state, &params->state);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MediaSessionServiceProxy::SetMetadata(
        const base::Optional<content::MediaMetadata>& in_metadata)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::MediaSessionService_SetMetadata_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::MediaMetadataDataView>(
            in_metadata, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kMediaSessionService_SetMetadata_Name, size);

        auto params = ::blink::mojom::internal::MediaSessionService_SetMetadata_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->metadata)::BaseType* metadata_ptr;
        mojo::internal::Serialize<::blink::mojom::MediaMetadataDataView>(
            in_metadata, builder.buffer(), &metadata_ptr, &serialization_context);
        params->metadata.Set(metadata_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MediaSessionServiceProxy::EnableAction(
        MediaSessionAction in_action)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::MediaSessionService_EnableAction_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMediaSessionService_EnableAction_Name, size);

        auto params = ::blink::mojom::internal::MediaSessionService_EnableAction_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::MediaSessionAction>(
            in_action, &params->action);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void MediaSessionServiceProxy::DisableAction(
        MediaSessionAction in_action)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::MediaSessionService_DisableAction_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMediaSessionService_DisableAction_Name, size);

        auto params = ::blink::mojom::internal::MediaSessionService_DisableAction_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::MediaSessionAction>(
            in_action, &params->action);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool MediaSessionServiceStubDispatch::Accept(
        MediaSessionService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kMediaSessionService_SetClient_Name: {
            internal::MediaSessionService_SetClient_Params_Data* params = reinterpret_cast<internal::MediaSessionService_SetClient_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            MediaSessionClientPtr p_client {};
            MediaSessionService_SetClient_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MediaSessionService::SetClient deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MediaSessionService::SetClient");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetClient(
                std::move(p_client));
            return true;
        }
        case internal::kMediaSessionService_SetPlaybackState_Name: {
            internal::MediaSessionService_SetPlaybackState_Params_Data* params = reinterpret_cast<internal::MediaSessionService_SetPlaybackState_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            MediaSessionPlaybackState p_state {};
            MediaSessionService_SetPlaybackState_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadState(&p_state))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MediaSessionService::SetPlaybackState deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MediaSessionService::SetPlaybackState");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetPlaybackState(
                std::move(p_state));
            return true;
        }
        case internal::kMediaSessionService_SetMetadata_Name: {
            internal::MediaSessionService_SetMetadata_Params_Data* params = reinterpret_cast<internal::MediaSessionService_SetMetadata_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::Optional<content::MediaMetadata> p_metadata {};
            MediaSessionService_SetMetadata_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadMetadata(&p_metadata))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MediaSessionService::SetMetadata deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MediaSessionService::SetMetadata");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetMetadata(
                std::move(p_metadata));
            return true;
        }
        case internal::kMediaSessionService_EnableAction_Name: {
            internal::MediaSessionService_EnableAction_Params_Data* params = reinterpret_cast<internal::MediaSessionService_EnableAction_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            MediaSessionAction p_action {};
            MediaSessionService_EnableAction_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadAction(&p_action))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MediaSessionService::EnableAction deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MediaSessionService::EnableAction");
            mojo::internal::MessageDispatchContext context(message);
            impl->EnableAction(
                std::move(p_action));
            return true;
        }
        case internal::kMediaSessionService_DisableAction_Name: {
            internal::MediaSessionService_DisableAction_Params_Data* params = reinterpret_cast<internal::MediaSessionService_DisableAction_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            MediaSessionAction p_action {};
            MediaSessionService_DisableAction_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadAction(&p_action))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MediaSessionService::DisableAction deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MediaSessionService::DisableAction");
            mojo::internal::MessageDispatchContext context(message);
            impl->DisableAction(
                std::move(p_action));
            return true;
        }
        }
        return false;
    }

    // static
    bool MediaSessionServiceStubDispatch::AcceptWithResponder(
        MediaSessionService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kMediaSessionService_SetClient_Name: {
            break;
        }
        case internal::kMediaSessionService_SetPlaybackState_Name: {
            break;
        }
        case internal::kMediaSessionService_SetMetadata_Name: {
            break;
        }
        case internal::kMediaSessionService_EnableAction_Name: {
            break;
        }
        case internal::kMediaSessionService_DisableAction_Name: {
            break;
        }
        }
        return false;
    }

    bool MediaSessionServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "MediaSessionService RequestValidator");

        switch (message->header()->name) {
        case internal::kMediaSessionService_SetClient_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MediaSessionService_SetClient_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMediaSessionService_SetPlaybackState_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MediaSessionService_SetPlaybackState_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMediaSessionService_SetMetadata_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MediaSessionService_SetMetadata_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMediaSessionService_EnableAction_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MediaSessionService_EnableAction_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kMediaSessionService_DisableAction_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MediaSessionService_DisableAction_Params_Data>(
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
} // namespace blink

namespace mojo {

// static
bool StructTraits<::blink::mojom::MediaImage::DataView, ::blink::mojom::MediaImagePtr>::Read(
    ::blink::mojom::MediaImage::DataView input,
    ::blink::mojom::MediaImagePtr* output)
{
    bool success = true;
    ::blink::mojom::MediaImagePtr result(::blink::mojom::MediaImage::New());

    if (!input.ReadSrc(&result->src))
        success = false;
    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadSizes(&result->sizes))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::MediaMetadata::DataView, ::blink::mojom::MediaMetadataPtr>::Read(
    ::blink::mojom::MediaMetadata::DataView input,
    ::blink::mojom::MediaMetadataPtr* output)
{
    bool success = true;
    ::blink::mojom::MediaMetadataPtr result(::blink::mojom::MediaMetadata::New());

    if (!input.ReadTitle(&result->title))
        success = false;
    if (!input.ReadArtist(&result->artist))
        success = false;
    if (!input.ReadAlbum(&result->album))
        success = false;
    if (!input.ReadArtwork(&result->artwork))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif