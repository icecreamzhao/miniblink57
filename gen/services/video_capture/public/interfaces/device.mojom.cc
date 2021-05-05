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

#include "services/video_capture/public/interfaces/device.mojom.h"

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
    const char Device::Name_[] = "video_capture::mojom::Device";

    DeviceProxy::DeviceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DeviceProxy::Start(
        const video_capture::CaptureSettings& in_requested_settings, ::video_capture::mojom::ReceiverPtr in_receiver)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::video_capture::mojom::internal::Device_Start_Params_Data);
        size += mojo::internal::PrepareToSerialize<::video_capture::mojom::CaptureSettingsDataView>(
            in_requested_settings, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDevice_Start_Name, size);

        auto params = ::video_capture::mojom::internal::Device_Start_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->requested_settings)::BaseType* requested_settings_ptr;
        mojo::internal::Serialize<::video_capture::mojom::CaptureSettingsDataView>(
            in_requested_settings, builder.buffer(), &requested_settings_ptr, &serialization_context);
        params->requested_settings.Set(requested_settings_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->requested_settings.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null requested_settings in Device.Start request");
        mojo::internal::Serialize<::video_capture::mojom::ReceiverPtrDataView>(
            in_receiver, &params->receiver, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->receiver),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid receiver in Device.Start request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DeviceStubDispatch::Accept(
        Device* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDevice_Start_Name: {
            internal::Device_Start_Params_Data* params = reinterpret_cast<internal::Device_Start_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            video_capture::CaptureSettings p_requested_settings {};
            ::video_capture::mojom::ReceiverPtr p_receiver {};
            Device_Start_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadRequestedSettings(&p_requested_settings))
                success = false;
            p_receiver = input_data_view.TakeReceiver<decltype(p_receiver)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Device::Start deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Device::Start");
            mojo::internal::MessageDispatchContext context(message);
            impl->Start(
                std::move(p_requested_settings),
                std::move(p_receiver));
            return true;
        }
        }
        return false;
    }

    // static
    bool DeviceStubDispatch::AcceptWithResponder(
        Device* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDevice_Start_Name: {
            break;
        }
        }
        return false;
    }

    bool DeviceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Device RequestValidator");

        switch (message->header()->name) {
        case internal::kDevice_Start_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Device_Start_Params_Data>(
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