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

#include "services/service_manager/public/interfaces/interface_provider.mojom-blink.h"

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
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
namespace service_manager {
namespace mojom {
    namespace blink {
        const char InterfaceProvider::Name_[] = "service_manager::mojom::InterfaceProvider";

        InterfaceProviderProxy::InterfaceProviderProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void InterfaceProviderProxy::GetInterface(
            const WTF::String& in_interface_name, mojo::ScopedMessagePipeHandle in_pipe)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::service_manager::mojom::internal::InterfaceProvider_GetInterface_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_interface_name, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kInterfaceProvider_GetInterface_Name, size);

            auto params = ::service_manager::mojom::internal::InterfaceProvider_GetInterface_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            typename decltype(params->interface_name)::BaseType* interface_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_interface_name, builder.buffer(), &interface_name_ptr, &serialization_context);
            params->interface_name.Set(interface_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->interface_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null interface_name in InterfaceProvider.GetInterface request");
            mojo::internal::Serialize<mojo::ScopedMessagePipeHandle>(
                in_pipe, &params->pipe, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->pipe),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid pipe in InterfaceProvider.GetInterface request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool InterfaceProviderStubDispatch::Accept(
            InterfaceProvider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kInterfaceProvider_GetInterface_Name: {
                internal::InterfaceProvider_GetInterface_Params_Data* params = reinterpret_cast<internal::InterfaceProvider_GetInterface_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                WTF::String p_interface_name {};
                mojo::ScopedMessagePipeHandle p_pipe {};
                InterfaceProvider_GetInterface_ParamsDataView input_data_view(params,
                    context);

                if (!input_data_view.ReadInterfaceName(&p_interface_name))
                    success = false;
                p_pipe = input_data_view.TakePipe();
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "InterfaceProvider::GetInterface deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "InterfaceProvider::GetInterface");
                mojo::internal::MessageDispatchContext context(message);
                impl->GetInterface(
                    std::move(p_interface_name),
                    std::move(p_pipe));
                return true;
            }
            }
            return false;
        }

        // static
        bool InterfaceProviderStubDispatch::AcceptWithResponder(
            InterfaceProvider* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kInterfaceProvider_GetInterface_Name: {
                break;
            }
            }
            return false;
        }

        bool InterfaceProviderRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "InterfaceProvider RequestValidator");

            switch (message->header()->name) {
            case internal::kInterfaceProvider_GetInterface_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::InterfaceProvider_GetInterface_Params_Data>(
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
} // namespace service_manager

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif