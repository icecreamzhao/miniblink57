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

#include "third_party/WebKit/public/platform/site_engagement.mojom.h"

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
namespace mojom {
    const char EngagementClient::Name_[] = "blink::mojom::EngagementClient";

    EngagementClientProxy::EngagementClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void EngagementClientProxy::SetEngagementLevel(
        const url::Origin& in_origin, EngagementLevel in_level)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::EngagementClient_SetEngagementLevel_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kEngagementClient_SetEngagementLevel_Name, size);

        auto params = ::blink::mojom::internal::EngagementClient_SetEngagementLevel_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in EngagementClient.SetEngagementLevel request");
        mojo::internal::Serialize<::blink::mojom::EngagementLevel>(
            in_level, &params->level);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool EngagementClientStubDispatch::Accept(
        EngagementClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kEngagementClient_SetEngagementLevel_Name: {
            internal::EngagementClient_SetEngagementLevel_Params_Data* params = reinterpret_cast<internal::EngagementClient_SetEngagementLevel_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            url::Origin p_origin {};
            EngagementLevel p_level {};
            EngagementClient_SetEngagementLevel_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!input_data_view.ReadLevel(&p_level))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "EngagementClient::SetEngagementLevel deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "EngagementClient::SetEngagementLevel");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetEngagementLevel(
                std::move(p_origin),
                std::move(p_level));
            return true;
        }
        }
        return false;
    }

    // static
    bool EngagementClientStubDispatch::AcceptWithResponder(
        EngagementClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kEngagementClient_SetEngagementLevel_Name: {
            break;
        }
        }
        return false;
    }

    bool EngagementClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "EngagementClient RequestValidator");

        switch (message->header()->name) {
        case internal::kEngagementClient_SetEngagementLevel_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::EngagementClient_SetEngagementLevel_Params_Data>(
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

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif