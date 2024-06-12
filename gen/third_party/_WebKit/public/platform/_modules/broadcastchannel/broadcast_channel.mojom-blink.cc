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

#include "third_party/WebKit/public/platform/modules/broadcastchannel/broadcast_channel.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/BluetoothStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/GeometryStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/KURLStructTraits.h"
#include "third_party/WebKit/Source/platform/mojo/SecurityOriginStructTraits.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
namespace blink {
namespace mojom {
    namespace blink {
        const char BroadcastChannelClient::Name_[] = "blink::mojom::BroadcastChannelClient";

        BroadcastChannelClientProxy::BroadcastChannelClientProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void BroadcastChannelClientProxy::OnMessage(
            const WTF::Vector<uint8_t>& in_message)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::BroadcastChannelClient_OnMessage_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_message, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kBroadcastChannelClient_OnMessage_Name, size);

            auto params = ::blink::mojom::internal::BroadcastChannelClient_OnMessage_Params_Data::New(builder.buffer());
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
                "null message in BroadcastChannelClient.OnMessage request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool BroadcastChannelClientStubDispatch::Accept(
            BroadcastChannelClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kBroadcastChannelClient_OnMessage_Name: {
                internal::BroadcastChannelClient_OnMessage_Params_Data* params = reinterpret_cast<internal::BroadcastChannelClient_OnMessage_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::Vector<uint8_t> p_message {};
                BroadcastChannelClient_OnMessage_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadMessage(&p_message))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "BroadcastChannelClient::OnMessage deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "BroadcastChannelClient::OnMessage");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnMessage(
                    std::move(p_message));
                return true;
            }
            }
            return false;
        }

        // static
        bool BroadcastChannelClientStubDispatch::AcceptWithResponder(
            BroadcastChannelClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kBroadcastChannelClient_OnMessage_Name: {
                break;
            }
            }
            return false;
        }

        bool BroadcastChannelClientRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "BroadcastChannelClient RequestValidator");

            switch (message->header()->name) {
            case internal::kBroadcastChannelClient_OnMessage_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::BroadcastChannelClient_OnMessage_Params_Data>(
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

        const char BroadcastChannelProvider::Name_[] = "blink::mojom::BroadcastChannelProvider";

        BroadcastChannelProviderProxy::BroadcastChannelProviderProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void BroadcastChannelProviderProxy::ConnectToChannel(
            const RefPtr<::blink::SecurityOrigin>& in_origin, const WTF::String& in_name, BroadcastChannelClientAssociatedPtrInfo in_receiver, BroadcastChannelClientAssociatedRequest in_sender)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::BroadcastChannelProvider_ConnectToChannel_Params_Data);
            size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
                in_origin, &serialization_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kBroadcastChannelProvider_ConnectToChannel_Name, size);

            auto params = ::blink::mojom::internal::BroadcastChannelProvider_ConnectToChannel_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->origin)::BaseType* origin_ptr;
            mojo::internal::Serialize<::url::mojom::OriginDataView>(
                in_origin, builder.buffer(), &origin_ptr, &serialization_context);
            params->origin.Set(origin_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->origin.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null origin in BroadcastChannelProvider.ConnectToChannel request");
            typename decltype(params->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, builder.buffer(), &name_ptr, &serialization_context);
            params->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in BroadcastChannelProvider.ConnectToChannel request");
            mojo::internal::Serialize<::blink::mojom::BroadcastChannelClientAssociatedPtrInfoDataView>(
                in_receiver, &params->receiver, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->receiver),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
                "invalid receiver in BroadcastChannelProvider.ConnectToChannel request");
            mojo::internal::Serialize<::blink::mojom::BroadcastChannelClientAssociatedRequestDataView>(
                in_sender, &params->sender, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->sender),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
                "invalid sender in BroadcastChannelProvider.ConnectToChannel request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool BroadcastChannelProviderStubDispatch::Accept(
            BroadcastChannelProvider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kBroadcastChannelProvider_ConnectToChannel_Name: {
                internal::BroadcastChannelProvider_ConnectToChannel_Params_Data* params = reinterpret_cast<internal::BroadcastChannelProvider_ConnectToChannel_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                RefPtr<::blink::SecurityOrigin> p_origin {};
                WTF::String p_name {};
                BroadcastChannelClientAssociatedPtrInfo p_receiver {};
                BroadcastChannelClientAssociatedRequest p_sender {};
                BroadcastChannelProvider_ConnectToChannel_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadOrigin(&p_origin))
                    success = false;
                if (!input_data_view.ReadName(&p_name))
                    success = false;
                p_receiver = input_data_view.TakeReceiver<decltype(p_receiver)>();
                p_sender = input_data_view.TakeSender<decltype(p_sender)>();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "BroadcastChannelProvider::ConnectToChannel deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "BroadcastChannelProvider::ConnectToChannel");
                mojo::internal::MessageDispatchContext context(message);
                impl->ConnectToChannel(
                    std::move(p_origin),
                    std::move(p_name),
                    std::move(p_receiver),
                    std::move(p_sender));
                return true;
            }
            }
            return false;
        }

        // static
        bool BroadcastChannelProviderStubDispatch::AcceptWithResponder(
            BroadcastChannelProvider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kBroadcastChannelProvider_ConnectToChannel_Name: {
                break;
            }
            }
            return false;
        }

        bool BroadcastChannelProviderRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "BroadcastChannelProvider RequestValidator");

            switch (message->header()->name) {
            case internal::kBroadcastChannelProvider_ConnectToChannel_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::BroadcastChannelProvider_ConnectToChannel_Params_Data>(
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