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

#include "media/mojo/interfaces/media_service.mojom.h"

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
    const char MediaService::Name_[] = "media::mojom::MediaService";

    MediaServiceProxy::MediaServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void MediaServiceProxy::CreateInterfaceFactory(
        ::media::mojom::InterfaceFactoryRequest in_factory, ::service_manager::mojom::InterfaceProviderPtr in_host_interfaces)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::MediaService_CreateInterfaceFactory_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kMediaService_CreateInterfaceFactory_Name, size);

        auto params = ::media::mojom::internal::MediaService_CreateInterfaceFactory_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::InterfaceFactoryRequestDataView>(
            in_factory, &params->factory, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->factory),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid factory in MediaService.CreateInterfaceFactory request");
        mojo::internal::Serialize<::service_manager::mojom::InterfaceProviderPtrDataView>(
            in_host_interfaces, &params->host_interfaces, &serialization_context);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool MediaServiceStubDispatch::Accept(
        MediaService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kMediaService_CreateInterfaceFactory_Name: {
            internal::MediaService_CreateInterfaceFactory_Params_Data* params = reinterpret_cast<internal::MediaService_CreateInterfaceFactory_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::media::mojom::InterfaceFactoryRequest p_factory {};
            ::service_manager::mojom::InterfaceProviderPtr p_host_interfaces {};
            MediaService_CreateInterfaceFactory_ParamsDataView input_data_view(params,
                context);

            p_factory = input_data_view.TakeFactory<decltype(p_factory)>();
            p_host_interfaces = input_data_view.TakeHostInterfaces<decltype(p_host_interfaces)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "MediaService::CreateInterfaceFactory deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "MediaService::CreateInterfaceFactory");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateInterfaceFactory(
                std::move(p_factory),
                std::move(p_host_interfaces));
            return true;
        }
        }
        return false;
    }

    // static
    bool MediaServiceStubDispatch::AcceptWithResponder(
        MediaService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kMediaService_CreateInterfaceFactory_Name: {
            break;
        }
        }
        return false;
    }

    bool MediaServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "MediaService RequestValidator");

        switch (message->header()->name) {
        case internal::kMediaService_CreateInterfaceFactory_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::MediaService_CreateInterfaceFactory_Params_Data>(
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