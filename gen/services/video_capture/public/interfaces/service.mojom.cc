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

#include "services/video_capture/public/interfaces/service.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
#include "media/capture/ipc/capture_param_traits.h"
#include "media/capture/ipc/capture_param_traits_macros.h"
#include "media/capture/mojo/video_capture_types_typemap_traits.h"
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
#include "services/video_capture/public/interfaces/capture_settings_traits.h"
#include "services/video_capture/public/interfaces/device_descriptor_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace video_capture {
namespace mojom {
    const char Service::Name_[] = "video_capture::mojom::Service";

    ServiceProxy::ServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ServiceProxy::ConnectToDeviceFactory(
        ::video_capture::mojom::DeviceFactoryRequest in_request)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::Service_ConnectToDeviceFactory_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kService_ConnectToDeviceFactory_Name, size);

        auto params = ::video_capture::mojom::internal::Service_ConnectToDeviceFactory_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::video_capture::mojom::DeviceFactoryRequestDataView>(
            in_request, &params->request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid request in Service.ConnectToDeviceFactory request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ServiceProxy::ConnectToFakeDeviceFactory(
        ::video_capture::mojom::DeviceFactoryRequest in_request)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::Service_ConnectToFakeDeviceFactory_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kService_ConnectToFakeDeviceFactory_Name, size);

        auto params = ::video_capture::mojom::internal::Service_ConnectToFakeDeviceFactory_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::video_capture::mojom::DeviceFactoryRequestDataView>(
            in_request, &params->request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid request in Service.ConnectToFakeDeviceFactory request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool ServiceStubDispatch::Accept(
        Service* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kService_ConnectToDeviceFactory_Name: {
            internal::Service_ConnectToDeviceFactory_Params_Data* params = reinterpret_cast<internal::Service_ConnectToDeviceFactory_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::video_capture::mojom::DeviceFactoryRequest p_request {};
            Service_ConnectToDeviceFactory_ParamsDataView input_data_view(params,
                context);

            p_request = input_data_view.TakeRequest<decltype(p_request)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Service::ConnectToDeviceFactory deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Service::ConnectToDeviceFactory");
            mojo::internal::MessageDispatchContext context(message);
            impl->ConnectToDeviceFactory(
                std::move(p_request));
            return true;
        }
        case internal::kService_ConnectToFakeDeviceFactory_Name: {
            internal::Service_ConnectToFakeDeviceFactory_Params_Data* params = reinterpret_cast<internal::Service_ConnectToFakeDeviceFactory_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::video_capture::mojom::DeviceFactoryRequest p_request {};
            Service_ConnectToFakeDeviceFactory_ParamsDataView input_data_view(params,
                context);

            p_request = input_data_view.TakeRequest<decltype(p_request)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Service::ConnectToFakeDeviceFactory deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Service::ConnectToFakeDeviceFactory");
            mojo::internal::MessageDispatchContext context(message);
            impl->ConnectToFakeDeviceFactory(
                std::move(p_request));
            return true;
        }
        }
        return false;
    }

    // static
    bool ServiceStubDispatch::AcceptWithResponder(
        Service* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kService_ConnectToDeviceFactory_Name: {
            break;
        }
        case internal::kService_ConnectToFakeDeviceFactory_Name: {
            break;
        }
        }
        return false;
    }

    bool ServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Service RequestValidator");

        switch (message->header()->name) {
        case internal::kService_ConnectToDeviceFactory_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Service_ConnectToDeviceFactory_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kService_ConnectToFakeDeviceFactory_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Service_ConnectToFakeDeviceFactory_Params_Data>(
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
} // namespace video_capture

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif