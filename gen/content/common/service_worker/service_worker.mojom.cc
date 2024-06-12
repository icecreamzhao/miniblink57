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

#include "content/common/service_worker/service_worker.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "cc/ipc/begin_frame_args_struct_traits.h"
#include "cc/ipc/compositor_frame_metadata_struct_traits.h"
#include "cc/ipc/compositor_frame_struct_traits.h"
#include "cc/ipc/filter_operation_struct_traits.h"
#include "cc/ipc/filter_operations_struct_traits.h"
#include "cc/ipc/frame_sink_id_struct_traits.h"
#include "cc/ipc/local_frame_id_struct_traits.h"
#include "cc/ipc/quads_struct_traits.h"
#include "cc/ipc/render_pass_struct_traits.h"
#include "cc/ipc/returned_resource_struct_traits.h"
#include "cc/ipc/selection_struct_traits.h"
#include "cc/ipc/shared_quad_state_struct_traits.h"
#include "cc/ipc/surface_id_struct_traits.h"
#include "cc/ipc/surface_info_struct_traits.h"
#include "cc/ipc/surface_reference_struct_traits.h"
#include "cc/ipc/surface_sequence_struct_traits.h"
#include "cc/ipc/transferable_resource_struct_traits.h"
#include "content/common/bluetooth/web_bluetooth_device_id_struct_traits.h"
#include "content/common/frame_messages.h"
#include "content/common/indexed_db/indexed_db_enum_traits.h"
#include "content/common/indexed_db/indexed_db_struct_traits.h"
#include "content/common/media/media_devices_param_traits.h"
#include "content/common/media/media_session_struct_traits.h"
#include "content/common/resource_messages.h"
#include "content/common/service_worker/embedded_worker_messages.h"
#include "content/common/service_worker/service_worker_messages.h"
#include "content/common/service_worker/service_worker_status_code_traits.h"
#include "content/common/service_worker/service_worker_types_traits.h"
#include "content/common/view_messages.h"
#include "content/public/common/common_param_traits.h"
#include "content/public/common/common_param_traits_macros.h"
#include "content/public/common/referrer_struct_traits.h"
#include "device/bluetooth/public/interfaces/uuid_struct_traits.h"
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
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
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "services/ui/public/interfaces/ime/ime_struct_traits.h"
#include "services/video_capture/public/interfaces/capture_settings_traits.h"
#include "services/video_capture/public/interfaces/device_descriptor_struct_traits.h"
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
#include "ui/base/mojo/window_open_disposition_enum_traits.h"
#include "ui/events/mojo/event_struct_traits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
#include "ui/gfx/range/mojo/range_struct_traits.h"
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace content {
namespace mojom {
    const char ServiceWorkerDispatcherHost::Name_[] = "content::mojom::ServiceWorkerDispatcherHost";

    ServiceWorkerDispatcherHostProxy::ServiceWorkerDispatcherHostProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ServiceWorkerDispatcherHostProxy::OnProviderCreated(
        int32_t in_provider_id, int32_t in_route_id, ::content::ServiceWorkerProviderType in_provider_type, bool in_is_parent_frame_secure)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kServiceWorkerDispatcherHost_OnProviderCreated_Name, size);

        auto params = ::content::mojom::internal::ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->provider_id = in_provider_id;
        params->route_id = in_route_id;
        mojo::internal::Serialize<::content::mojom::ServiceWorkerProviderType>(
            in_provider_type, &params->provider_type);
        params->is_parent_frame_secure = in_is_parent_frame_secure;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ServiceWorkerDispatcherHostProxy::OnProviderDestroyed(
        int32_t in_provider_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kServiceWorkerDispatcherHost_OnProviderDestroyed_Name, size);

        auto params = ::content::mojom::internal::ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->provider_id = in_provider_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ServiceWorkerDispatcherHostProxy::OnSetHostedVersionId(
        int32_t in_provider_id, int64_t in_version_id, int32_t in_embedded_worker_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kServiceWorkerDispatcherHost_OnSetHostedVersionId_Name, size);

        auto params = ::content::mojom::internal::ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->provider_id = in_provider_id;
        params->version_id = in_version_id;
        params->embedded_worker_id = in_embedded_worker_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool ServiceWorkerDispatcherHostStubDispatch::Accept(
        ServiceWorkerDispatcherHost* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kServiceWorkerDispatcherHost_OnProviderCreated_Name: {
            internal::ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data* params = reinterpret_cast<internal::ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_provider_id {};
            int32_t p_route_id {};
            ::content::ServiceWorkerProviderType p_provider_type {};
            bool p_is_parent_frame_secure {};
            ServiceWorkerDispatcherHost_OnProviderCreated_ParamsDataView input_data_view(params,
                context);

            p_provider_id = input_data_view.provider_id();
            p_route_id = input_data_view.route_id();
            if (!input_data_view.ReadProviderType(&p_provider_type))
                success = false;
            p_is_parent_frame_secure = input_data_view.is_parent_frame_secure();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceWorkerDispatcherHost::OnProviderCreated deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceWorkerDispatcherHost::OnProviderCreated");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnProviderCreated(
                std::move(p_provider_id),
                std::move(p_route_id),
                std::move(p_provider_type),
                std::move(p_is_parent_frame_secure));
            return true;
        }
        case internal::kServiceWorkerDispatcherHost_OnProviderDestroyed_Name: {
            internal::ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data* params = reinterpret_cast<internal::ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_provider_id {};
            ServiceWorkerDispatcherHost_OnProviderDestroyed_ParamsDataView input_data_view(params,
                context);

            p_provider_id = input_data_view.provider_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceWorkerDispatcherHost::OnProviderDestroyed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceWorkerDispatcherHost::OnProviderDestroyed");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnProviderDestroyed(
                std::move(p_provider_id));
            return true;
        }
        case internal::kServiceWorkerDispatcherHost_OnSetHostedVersionId_Name: {
            internal::ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data* params = reinterpret_cast<internal::ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_provider_id {};
            int64_t p_version_id {};
            int32_t p_embedded_worker_id {};
            ServiceWorkerDispatcherHost_OnSetHostedVersionId_ParamsDataView input_data_view(params,
                context);

            p_provider_id = input_data_view.provider_id();
            p_version_id = input_data_view.version_id();
            p_embedded_worker_id = input_data_view.embedded_worker_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceWorkerDispatcherHost::OnSetHostedVersionId deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceWorkerDispatcherHost::OnSetHostedVersionId");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnSetHostedVersionId(
                std::move(p_provider_id),
                std::move(p_version_id),
                std::move(p_embedded_worker_id));
            return true;
        }
        }
        return false;
    }

    // static
    bool ServiceWorkerDispatcherHostStubDispatch::AcceptWithResponder(
        ServiceWorkerDispatcherHost* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kServiceWorkerDispatcherHost_OnProviderCreated_Name: {
            break;
        }
        case internal::kServiceWorkerDispatcherHost_OnProviderDestroyed_Name: {
            break;
        }
        case internal::kServiceWorkerDispatcherHost_OnSetHostedVersionId_Name: {
            break;
        }
        }
        return false;
    }

    bool ServiceWorkerDispatcherHostRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ServiceWorkerDispatcherHost RequestValidator");

        switch (message->header()->name) {
        case internal::kServiceWorkerDispatcherHost_OnProviderCreated_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerDispatcherHost_OnProviderDestroyed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerDispatcherHost_OnSetHostedVersionId_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data>(
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
} // namespace content

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif