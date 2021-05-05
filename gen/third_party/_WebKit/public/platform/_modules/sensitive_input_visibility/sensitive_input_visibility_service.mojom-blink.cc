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

#include "third_party/WebKit/public/platform/modules/sensitive_input_visibility/sensitive_input_visibility_service.mojom-blink.h"

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
        const char SensitiveInputVisibilityService::Name_[] = "blink::mojom::SensitiveInputVisibilityService";

        SensitiveInputVisibilityServiceProxy::SensitiveInputVisibilityServiceProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void SensitiveInputVisibilityServiceProxy::PasswordFieldVisibleInInsecureContext()
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kSensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Name, size);

            auto params = ::blink::mojom::internal::SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        void SensitiveInputVisibilityServiceProxy::AllPasswordFieldsInInsecureContextInvisible()
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::blink::mojom::internal::SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data);
            mojo::internal::MessageBuilder builder(internal::kSensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Name, size);

            auto params = ::blink::mojom::internal::SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool SensitiveInputVisibilityServiceStubDispatch::Accept(
            SensitiveInputVisibilityService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kSensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Name: {
                internal::SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data* params = reinterpret_cast<internal::SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "SensitiveInputVisibilityService::PasswordFieldVisibleInInsecureContext deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "SensitiveInputVisibilityService::PasswordFieldVisibleInInsecureContext");
                mojo::internal::MessageDispatchContext context(message);
                impl->PasswordFieldVisibleInInsecureContext();
                return true;
            }
            case internal::kSensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Name: {
                internal::SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data* params = reinterpret_cast<internal::SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_ParamsDataView input_data_view(params,
                    context);

                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "SensitiveInputVisibilityService::AllPasswordFieldsInInsecureContextInvisible deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "SensitiveInputVisibilityService::AllPasswordFieldsInInsecureContextInvisible");
                mojo::internal::MessageDispatchContext context(message);
                impl->AllPasswordFieldsInInsecureContextInvisible();
                return true;
            }
            }
            return false;
        }

        // static
        bool SensitiveInputVisibilityServiceStubDispatch::AcceptWithResponder(
            SensitiveInputVisibilityService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kSensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Name: {
                break;
            }
            case internal::kSensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Name: {
                break;
            }
            }
            return false;
        }

        bool SensitiveInputVisibilityServiceRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "SensitiveInputVisibilityService RequestValidator");

            switch (message->header()->name) {
            case internal::kSensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data>(
                        message, &validation_context)) {
                    return false;
                }
                return true;
            }
            case internal::kSensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data>(
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