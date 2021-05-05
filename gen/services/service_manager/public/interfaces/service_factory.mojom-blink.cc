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

#include "services/service_manager/public/interfaces/service_factory.mojom-blink.h"

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
        const char ServiceFactory::Name_[] = "service_manager::mojom::ServiceFactory";

        ServiceFactoryProxy::ServiceFactoryProxy(mojo::MessageReceiverWithResponder* receiver)
            : receiver_(receiver)
        {
        }

        void ServiceFactoryProxy::CreateService(
            ::service_manager::mojom::blink::ServiceRequest in_service, const WTF::String& in_name)
        {
            mojo::internal::SerializationContext serialization_context(
                group_controller_);
            size_t size = sizeof(::service_manager::mojom::internal::ServiceFactory_CreateService_Params_Data);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, &serialization_context);
            mojo::internal::MessageBuilder builder(internal::kServiceFactory_CreateService_Name, size);

            auto params = ::service_manager::mojom::internal::ServiceFactory_CreateService_Params_Data::New(builder.buffer());
            ALLOW_UNUSED_LOCAL(params);
            mojo::internal::Serialize<::service_manager::mojom::ServiceRequestDataView>(
                in_service, &params->service, &serialization_context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(params->service),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid service in ServiceFactory.CreateService request");
            typename decltype(params->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, builder.buffer(), &name_ptr, &serialization_context);
            params->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                params->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in ServiceFactory.CreateService request");
            (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
            bool ok = receiver_->Accept(builder.message());
            // This return value may be ignored as !ok implies the Connector has
            // encountered an error, which will be visible through other means.
            ALLOW_UNUSED_LOCAL(ok);
        }

        // static
        bool ServiceFactoryStubDispatch::Accept(
            ServiceFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message)
        {
            switch (message->header()->name) {
            case internal::kServiceFactory_CreateService_Name: {
                internal::ServiceFactory_CreateService_Params_Data* params = reinterpret_cast<internal::ServiceFactory_CreateService_Params_Data*>(
                    message->mutable_payload());

                (context)->handles.Swap((message)->mutable_handles());
                bool success = true;
                ::service_manager::mojom::blink::ServiceRequest p_service {};
                WTF::String p_name {};
                ServiceFactory_CreateService_ParamsDataView input_data_view(params,
                    context);

                p_service = input_data_view.TakeService<decltype(p_service)>();
                if (!input_data_view.ReadName(&p_name))
                    success = false;
                if (!success) {
                    ReportValidationErrorForMessage(
                        message,
                        mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                        "ServiceFactory::CreateService deserializer");
                    return false;
                }
                // A null |impl| means no implementation was bound.
                assert(impl);
                TRACE_EVENT0("mojom", "ServiceFactory::CreateService");
                mojo::internal::MessageDispatchContext context(message);
                impl->CreateService(
                    std::move(p_service),
                    std::move(p_name));
                return true;
            }
            }
            return false;
        }

        // static
        bool ServiceFactoryStubDispatch::AcceptWithResponder(
            ServiceFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder)
        {
            switch (message->header()->name) {
            case internal::kServiceFactory_CreateService_Name: {
                break;
            }
            }
            return false;
        }

        bool ServiceFactoryRequestValidator::Accept(mojo::Message* message)
        {
            if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
                return true;

            mojo::internal::ValidationContext validation_context(
                message->data(), message->data_num_bytes(), message->handles()->size(),
                message, "ServiceFactory RequestValidator");

            switch (message->header()->name) {
            case internal::kServiceFactory_CreateService_Name: {
                if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                        message, &validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateMessagePayload<
                        internal::ServiceFactory_CreateService_Params_Data>(
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