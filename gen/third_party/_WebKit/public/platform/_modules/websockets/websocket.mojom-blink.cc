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

#include "third_party/WebKit/public/platform/modules/websockets/websocket.mojom-blink.h"

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
    namespace blink { // static
        HttpHeaderPtr HttpHeader::New()
        {
            HttpHeaderPtr rv;
            mojo::internal::StructHelper<HttpHeader>::Initialize(&rv);
            return rv;
        }

        HttpHeader::HttpHeader()
            : name()
            , value()
        {
        }

        HttpHeader::~HttpHeader()
        {
        }
        size_t HttpHeader::Hash(size_t seed) const
        {
            seed = mojo::internal::WTFHash(seed, this->name);
            seed = mojo::internal::WTFHash(seed, this->value);
            return seed;
        } // static
        WebSocketHandshakeRequestPtr WebSocketHandshakeRequest::New()
        {
            WebSocketHandshakeRequestPtr rv;
            mojo::internal::StructHelper<WebSocketHandshakeRequest>::Initialize(&rv);
            return rv;
        }

        WebSocketHandshakeRequest::WebSocketHandshakeRequest()
            : url()
            , headers()
            , headers_text()
        {
        }

        WebSocketHandshakeRequest::~WebSocketHandshakeRequest()
        {
        } // static
        WebSocketHandshakeResponsePtr WebSocketHandshakeResponse::New()
        {
            WebSocketHandshakeResponsePtr rv;
            mojo::internal::StructHelper<WebSocketHandshakeResponse>::Initialize(&rv);
            return rv;
        }

        WebSocketHandshakeResponse::WebSocketHandshakeResponse()
            : url()
            , status_code()
            , status_text()
            , headers()
            , headers_text()
        {
        }

        WebSocketHandshakeResponse::~WebSocketHandshakeResponse()
        {
        }
        const char WebSocketClient::Name_[] = "blink::mojom::WebSocketClient";

        WebSocketClientProxy::WebSocketClientProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void WebSocketClientProxy::OnFailChannel(
            const WTF::String& in_reason)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocketClient_OnFailChannel_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_reason, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebSocketClient_OnFailChannel_Name, size);

            auto params = ::blink::mojom::internal::WebSocketClient_OnFailChannel_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->reason)::BaseType* reason_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_reason, builder.buffer(), &reason_ptr, &serialization_context);
            params->reason.Set(reason_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->reason.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null reason in WebSocketClient.OnFailChannel request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketClientProxy::OnStartOpeningHandshake(
            WebSocketHandshakeRequestPtr in_request)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocketClient_OnStartOpeningHandshake_Params_Data);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WebSocketHandshakeRequestDataView>(
                in_request, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebSocketClient_OnStartOpeningHandshake_Name, size);

            auto params = ::blink::mojom::internal::WebSocketClient_OnStartOpeningHandshake_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->request)::BaseType* request_ptr;
            mojo::internal::Serialize<::blink::mojom::WebSocketHandshakeRequestDataView>(
                in_request, builder.buffer(), &request_ptr, &serialization_context);
            params->request.Set(request_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->request.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null request in WebSocketClient.OnStartOpeningHandshake request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketClientProxy::OnFinishOpeningHandshake(
            WebSocketHandshakeResponsePtr in_response)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocketClient_OnFinishOpeningHandshake_Params_Data);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WebSocketHandshakeResponseDataView>(
                in_response, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebSocketClient_OnFinishOpeningHandshake_Name, size);

            auto params = ::blink::mojom::internal::WebSocketClient_OnFinishOpeningHandshake_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->response)::BaseType* response_ptr;
            mojo::internal::Serialize<::blink::mojom::WebSocketHandshakeResponseDataView>(
                in_response, builder.buffer(), &response_ptr, &serialization_context);
            params->response.Set(response_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->response.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null response in WebSocketClient.OnFinishOpeningHandshake request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketClientProxy::OnAddChannelResponse(
            const WTF::String& in_selected_protocol, const WTF::String& in_extensions)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocketClient_OnAddChannelResponse_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_selected_protocol, &serialization_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_extensions, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebSocketClient_OnAddChannelResponse_Name, size);

            auto params = ::blink::mojom::internal::WebSocketClient_OnAddChannelResponse_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->selected_protocol)::BaseType* selected_protocol_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_selected_protocol, builder.buffer(), &selected_protocol_ptr, &serialization_context);
            params->selected_protocol.Set(selected_protocol_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->selected_protocol.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null selected_protocol in WebSocketClient.OnAddChannelResponse request");
            typename decltype(params->extensions)::BaseType* extensions_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_extensions, builder.buffer(), &extensions_ptr, &serialization_context);
            params->extensions.Set(extensions_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->extensions.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null extensions in WebSocketClient.OnAddChannelResponse request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketClientProxy::OnDataFrame(
            bool in_fin, WebSocketMessageType in_type, const WTF::Vector<uint8_t>& in_data)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocketClient_OnDataFrame_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebSocketClient_OnDataFrame_Name, size);

            auto params = ::blink::mojom::internal::WebSocketClient_OnDataFrame_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->fin = in_fin;
            mojo::internal::Serialize<::blink::mojom::WebSocketMessageType>(
                in_type, &params->type);
            typename decltype(params->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, builder.buffer(), &data_ptr, &data_validate_params,
                &serialization_context);
            params->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in WebSocketClient.OnDataFrame request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketClientProxy::OnFlowControl(
            int64_t in_quota)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocketClient_OnFlowControl_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kWebSocketClient_OnFlowControl_Name, size);

            auto params = ::blink::mojom::internal::WebSocketClient_OnFlowControl_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->quota = in_quota;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketClientProxy::OnDropChannel(
            bool in_was_clean, uint16_t in_code, const WTF::String& in_reason)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocketClient_OnDropChannel_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_reason, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebSocketClient_OnDropChannel_Name, size);

            auto params = ::blink::mojom::internal::WebSocketClient_OnDropChannel_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->was_clean = in_was_clean;
            params->code = in_code;
            typename decltype(params->reason)::BaseType* reason_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_reason, builder.buffer(), &reason_ptr, &serialization_context);
            params->reason.Set(reason_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->reason.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null reason in WebSocketClient.OnDropChannel request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketClientProxy::OnClosingHandshake()
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocketClient_OnClosingHandshake_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kWebSocketClient_OnClosingHandshake_Name, size);

            auto params = ::blink::mojom::internal::WebSocketClient_OnClosingHandshake_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool WebSocketClientStubDispatch::Accept(
            WebSocketClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kWebSocketClient_OnFailChannel_Name: {
                internal::WebSocketClient_OnFailChannel_Params_Data* params = reinterpret_cast<internal::WebSocketClient_OnFailChannel_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_reason {};
                WebSocketClient_OnFailChannel_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadReason(&p_reason))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocketClient::OnFailChannel deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocketClient::OnFailChannel");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnFailChannel(
                    std::move(p_reason));
                return true;
            }
            case internal::kWebSocketClient_OnStartOpeningHandshake_Name: {
                internal::WebSocketClient_OnStartOpeningHandshake_Params_Data* params = reinterpret_cast<internal::WebSocketClient_OnStartOpeningHandshake_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WebSocketHandshakeRequestPtr p_request {};
                WebSocketClient_OnStartOpeningHandshake_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadRequest(&p_request))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocketClient::OnStartOpeningHandshake deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocketClient::OnStartOpeningHandshake");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnStartOpeningHandshake(
                    std::move(p_request));
                return true;
            }
            case internal::kWebSocketClient_OnFinishOpeningHandshake_Name: {
                internal::WebSocketClient_OnFinishOpeningHandshake_Params_Data* params = reinterpret_cast<internal::WebSocketClient_OnFinishOpeningHandshake_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WebSocketHandshakeResponsePtr p_response {};
                WebSocketClient_OnFinishOpeningHandshake_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadResponse(&p_response))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocketClient::OnFinishOpeningHandshake deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocketClient::OnFinishOpeningHandshake");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnFinishOpeningHandshake(
                    std::move(p_response));
                return true;
            }
            case internal::kWebSocketClient_OnAddChannelResponse_Name: {
                internal::WebSocketClient_OnAddChannelResponse_Params_Data* params = reinterpret_cast<internal::WebSocketClient_OnAddChannelResponse_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_selected_protocol {};
                WTF::String p_extensions {};
                WebSocketClient_OnAddChannelResponse_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadSelectedProtocol(&p_selected_protocol))
                    success = false;
                if (!input_data_view.ReadExtensions(&p_extensions))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocketClient::OnAddChannelResponse deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocketClient::OnAddChannelResponse");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnAddChannelResponse(
                    std::move(p_selected_protocol),
                    std::move(p_extensions));
                return true;
            }
            case internal::kWebSocketClient_OnDataFrame_Name: {
                internal::WebSocketClient_OnDataFrame_Params_Data* params = reinterpret_cast<internal::WebSocketClient_OnDataFrame_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                bool p_fin {};
                WebSocketMessageType p_type {};
                WTF::Vector<uint8_t> p_data {};
                WebSocketClient_OnDataFrame_ParamsDataView input_data_view(params,
                    context);

                p_fin = input_data_view.fin();
                if (!input_data_view.ReadType(&p_type))
                    success = false;
                if (!input_data_view.ReadData(&p_data))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocketClient::OnDataFrame deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocketClient::OnDataFrame");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnDataFrame(
                    std::move(p_fin),
                    std::move(p_type),
                    std::move(p_data));
                return true;
            }
            case internal::kWebSocketClient_OnFlowControl_Name: {
                internal::WebSocketClient_OnFlowControl_Params_Data* params = reinterpret_cast<internal::WebSocketClient_OnFlowControl_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                int64_t p_quota {};
                WebSocketClient_OnFlowControl_ParamsDataView input_data_view(params,
                    context);

                p_quota = input_data_view.quota();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocketClient::OnFlowControl deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocketClient::OnFlowControl");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnFlowControl(
                    std::move(p_quota));
                return true;
            }
            case internal::kWebSocketClient_OnDropChannel_Name: {
                internal::WebSocketClient_OnDropChannel_Params_Data* params = reinterpret_cast<internal::WebSocketClient_OnDropChannel_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                bool p_was_clean {};
                uint16_t p_code {};
                WTF::String p_reason {};
                WebSocketClient_OnDropChannel_ParamsDataView input_data_view(params,
                    context);

                p_was_clean = input_data_view.was_clean();
                p_code = input_data_view.code();
                if (!input_data_view.ReadReason(&p_reason))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocketClient::OnDropChannel deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocketClient::OnDropChannel");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnDropChannel(
                    std::move(p_was_clean),
                    std::move(p_code),
                    std::move(p_reason));
                return true;
            }
            case internal::kWebSocketClient_OnClosingHandshake_Name: {
                internal::WebSocketClient_OnClosingHandshake_Params_Data* params = reinterpret_cast<internal::WebSocketClient_OnClosingHandshake_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WebSocketClient_OnClosingHandshake_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocketClient::OnClosingHandshake deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocketClient::OnClosingHandshake");
                mojo::internal::MessageDispatchContext context(message);
                impl->OnClosingHandshake();
                return true;
            }
            }
            return false;
        }

        // static
        bool WebSocketClientStubDispatch::AcceptWithResponder(
            WebSocketClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kWebSocketClient_OnFailChannel_Name: {
                break;
            }
            case internal::kWebSocketClient_OnStartOpeningHandshake_Name: {
                break;
            }
            case internal::kWebSocketClient_OnFinishOpeningHandshake_Name: {
                break;
            }
            case internal::kWebSocketClient_OnAddChannelResponse_Name: {
                break;
            }
            case internal::kWebSocketClient_OnDataFrame_Name: {
                break;
            }
            case internal::kWebSocketClient_OnFlowControl_Name: {
                break;
            }
            case internal::kWebSocketClient_OnDropChannel_Name: {
                break;
            }
            case internal::kWebSocketClient_OnClosingHandshake_Name: {
                break;
            }
            }
            return false;
        }

        bool WebSocketClientRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "WebSocketClient RequestValidator");

            switch (message->header()->name) {
            case internal::kWebSocketClient_OnFailChannel_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocketClient_OnFailChannel_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocketClient_OnStartOpeningHandshake_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocketClient_OnStartOpeningHandshake_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocketClient_OnFinishOpeningHandshake_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocketClient_OnFinishOpeningHandshake_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocketClient_OnAddChannelResponse_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocketClient_OnAddChannelResponse_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocketClient_OnDataFrame_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocketClient_OnDataFrame_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocketClient_OnFlowControl_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocketClient_OnFlowControl_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocketClient_OnDropChannel_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocketClient_OnDropChannel_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocketClient_OnClosingHandshake_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocketClient_OnClosingHandshake_Params_Data>(
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

        const char WebSocket::Name_[] = "blink::mojom::WebSocket";

        WebSocketProxy::WebSocketProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void WebSocketProxy::AddChannelRequest(
            const ::blink::KURL& in_url, const WTF::Vector<WTF::String>& in_requested_protocols, const RefPtr<::blink::SecurityOrigin>& in_origin, const ::blink::KURL& in_first_party_for_cookies, const WTF::String& in_user_agent_override, WebSocketClientPtr in_client)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocket_AddChannelRequest_Params_Data);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_url, &serialization_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_requested_protocols, &serialization_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
                in_origin, &serialization_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_first_party_for_cookies, &serialization_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_user_agent_override, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebSocket_AddChannelRequest_Name, size);

            auto params = ::blink::mojom::internal::WebSocket_AddChannelRequest_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->url)::BaseType* url_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_url, builder.buffer(), &url_ptr, &serialization_context);
            params->url.Set(url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null url in WebSocket.AddChannelRequest request");
            typename decltype(params->requested_protocols)::BaseType* requested_protocols_ptr;
            const mojo::internal::ContainerValidateParams requested_protocols_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_requested_protocols, builder.buffer(), &requested_protocols_ptr, &requested_protocols_validate_params,
                &serialization_context);
            params->requested_protocols.Set(requested_protocols_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->requested_protocols.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null requested_protocols in WebSocket.AddChannelRequest request");
            typename decltype(params->origin)::BaseType* origin_ptr;
            mojo::internal::Serialize<::url::mojom::OriginDataView>(
                in_origin, builder.buffer(), &origin_ptr, &serialization_context);
            params->origin.Set(origin_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->origin.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null origin in WebSocket.AddChannelRequest request");
            typename decltype(params->first_party_for_cookies)::BaseType* first_party_for_cookies_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_first_party_for_cookies, builder.buffer(), &first_party_for_cookies_ptr, &serialization_context);
            params->first_party_for_cookies.Set(first_party_for_cookies_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->first_party_for_cookies.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null first_party_for_cookies in WebSocket.AddChannelRequest request");
            typename decltype(params->user_agent_override)::BaseType* user_agent_override_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_user_agent_override, builder.buffer(), &user_agent_override_ptr, &serialization_context);
            params->user_agent_override.Set(user_agent_override_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->user_agent_override.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null user_agent_override in WebSocket.AddChannelRequest request");
            mojo::internal::Serialize<::blink::mojom::WebSocketClientPtrDataView>(
                in_client, &params->client, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->client),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid client in WebSocket.AddChannelRequest request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketProxy::SendFrame(
            bool in_fin, WebSocketMessageType in_type, const WTF::Vector<uint8_t>& in_data)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocket_SendFrame_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebSocket_SendFrame_Name, size);

            auto params = ::blink::mojom::internal::WebSocket_SendFrame_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->fin = in_fin;
            mojo::internal::Serialize<::blink::mojom::WebSocketMessageType>(
                in_type, &params->type);
            typename decltype(params->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, builder.buffer(), &data_ptr, &data_validate_params,
                &serialization_context);
            params->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in WebSocket.SendFrame request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketProxy::SendFlowControl(
            int64_t in_quota)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocket_SendFlowControl_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kWebSocket_SendFlowControl_Name, size);

            auto params = ::blink::mojom::internal::WebSocket_SendFlowControl_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->quota = in_quota;
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void WebSocketProxy::StartClosingHandshake(
            uint16_t in_code, const WTF::String& in_reason)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::WebSocket_StartClosingHandshake_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_reason, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kWebSocket_StartClosingHandshake_Name, size);

            auto params = ::blink::mojom::internal::WebSocket_StartClosingHandshake_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            params->code = in_code;
            typename decltype(params->reason)::BaseType* reason_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_reason, builder.buffer(), &reason_ptr, &serialization_context);
            params->reason.Set(reason_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->reason.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null reason in WebSocket.StartClosingHandshake request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool WebSocketStubDispatch::Accept(
            WebSocket* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kWebSocket_AddChannelRequest_Name: {
                internal::WebSocket_AddChannelRequest_Params_Data* params = reinterpret_cast<internal::WebSocket_AddChannelRequest_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                ::blink::KURL p_url {};
                WTF::Vector<WTF::String> p_requested_protocols {};
                RefPtr<::blink::SecurityOrigin> p_origin {};
                ::blink::KURL p_first_party_for_cookies {};
                WTF::String p_user_agent_override {};
                WebSocketClientPtr p_client {};
                WebSocket_AddChannelRequest_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadUrl(&p_url))
                    success = false;
                if (!input_data_view.ReadRequestedProtocols(&p_requested_protocols))
                    success = false;
                if (!input_data_view.ReadOrigin(&p_origin))
                    success = false;
                if (!input_data_view.ReadFirstPartyForCookies(&p_first_party_for_cookies))
                    success = false;
                if (!input_data_view.ReadUserAgentOverride(&p_user_agent_override))
                    success = false;
                p_client = input_data_view.TakeClient<decltype(p_client)>();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocket::AddChannelRequest deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocket::AddChannelRequest");
                mojo::internal::MessageDispatchContext context(message);
                impl->AddChannelRequest(
                    std::move(p_url),
                    std::move(p_requested_protocols),
                    std::move(p_origin),
                    std::move(p_first_party_for_cookies),
                    std::move(p_user_agent_override),
                    std::move(p_client));
                return true;
            }
            case internal::kWebSocket_SendFrame_Name: {
                internal::WebSocket_SendFrame_Params_Data* params = reinterpret_cast<internal::WebSocket_SendFrame_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                bool p_fin {};
                WebSocketMessageType p_type {};
                WTF::Vector<uint8_t> p_data {};
                WebSocket_SendFrame_ParamsDataView input_data_view(params,
                    context);

                p_fin = input_data_view.fin();
                if (!input_data_view.ReadType(&p_type))
                    success = false;
                if (!input_data_view.ReadData(&p_data))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocket::SendFrame deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocket::SendFrame");
                mojo::internal::MessageDispatchContext context(message);
                impl->SendFrame(
                    std::move(p_fin),
                    std::move(p_type),
                    std::move(p_data));
                return true;
            }
            case internal::kWebSocket_SendFlowControl_Name: {
                internal::WebSocket_SendFlowControl_Params_Data* params = reinterpret_cast<internal::WebSocket_SendFlowControl_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                int64_t p_quota {};
                WebSocket_SendFlowControl_ParamsDataView input_data_view(params,
                    context);

                p_quota = input_data_view.quota();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocket::SendFlowControl deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocket::SendFlowControl");
                mojo::internal::MessageDispatchContext context(message);
                impl->SendFlowControl(
                    std::move(p_quota));
                return true;
            }
            case internal::kWebSocket_StartClosingHandshake_Name: {
                internal::WebSocket_StartClosingHandshake_Params_Data* params = reinterpret_cast<internal::WebSocket_StartClosingHandshake_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                uint16_t p_code {};
                WTF::String p_reason {};
                WebSocket_StartClosingHandshake_ParamsDataView input_data_view(params,
                    context);

                p_code = input_data_view.code();
                if (!input_data_view.ReadReason(&p_reason))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "WebSocket::StartClosingHandshake deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "WebSocket::StartClosingHandshake");
                mojo::internal::MessageDispatchContext context(message);
                impl->StartClosingHandshake(
                    std::move(p_code),
                    std::move(p_reason));
                return true;
            }
            }
            return false;
        }

        // static
        bool WebSocketStubDispatch::AcceptWithResponder(
            WebSocket* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kWebSocket_AddChannelRequest_Name: {
                break;
            }
            case internal::kWebSocket_SendFrame_Name: {
                break;
            }
            case internal::kWebSocket_SendFlowControl_Name: {
                break;
            }
            case internal::kWebSocket_StartClosingHandshake_Name: {
                break;
            }
            }
            return false;
        }

        bool WebSocketRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "WebSocket RequestValidator");

            switch (message->header()->name) {
            case internal::kWebSocket_AddChannelRequest_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocket_AddChannelRequest_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocket_SendFrame_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocket_SendFrame_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocket_SendFlowControl_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocket_SendFlowControl_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kWebSocket_StartClosingHandshake_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::WebSocket_StartClosingHandshake_Params_Data>(
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

// static
bool StructTraits<::blink::mojom::blink::HttpHeader::DataView, ::blink::mojom::blink::HttpHeaderPtr>::Read(
    ::blink::mojom::blink::HttpHeader::DataView input,
    ::blink::mojom::blink::HttpHeaderPtr* output)
{
    bool success = true;
    ::blink::mojom::blink::HttpHeaderPtr result(::blink::mojom::blink::HttpHeader::New());

    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadValue(&result->value))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::blink::WebSocketHandshakeRequest::DataView, ::blink::mojom::blink::WebSocketHandshakeRequestPtr>::Read(
    ::blink::mojom::blink::WebSocketHandshakeRequest::DataView input,
    ::blink::mojom::blink::WebSocketHandshakeRequestPtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WebSocketHandshakeRequestPtr result(::blink::mojom::blink::WebSocketHandshakeRequest::New());

    if (!input.ReadUrl(&result->url))
        success = false;
    if (!input.ReadHeaders(&result->headers))
        success = false;
    if (!input.ReadHeadersText(&result->headers_text))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::blink::WebSocketHandshakeResponse::DataView, ::blink::mojom::blink::WebSocketHandshakeResponsePtr>::Read(
    ::blink::mojom::blink::WebSocketHandshakeResponse::DataView input,
    ::blink::mojom::blink::WebSocketHandshakeResponsePtr* output)
{
    bool success = true;
    ::blink::mojom::blink::WebSocketHandshakeResponsePtr result(::blink::mojom::blink::WebSocketHandshakeResponse::New());

    if (!input.ReadUrl(&result->url))
        success = false;
    result->status_code = input.status_code();
    if (!input.ReadStatusText(&result->status_text))
        success = false;
    if (!input.ReadHeaders(&result->headers))
        success = false;
    if (!input.ReadHeadersText(&result->headers_text))
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