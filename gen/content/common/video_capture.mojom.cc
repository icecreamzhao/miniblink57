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

#include "content/common/video_capture.mojom.h"

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
    const char VideoCaptureObserver::Name_[] = "content::mojom::VideoCaptureObserver";

    VideoCaptureObserverProxy::VideoCaptureObserverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void VideoCaptureObserverProxy::OnStateChanged(
        VideoCaptureState in_state)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureObserver_OnStateChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureObserver_OnStateChanged_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureObserver_OnStateChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::content::mojom::VideoCaptureState>(
            in_state, &params->state);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoCaptureObserverProxy::OnBufferCreated(
        int32_t in_buffer_id, mojo::ScopedSharedBufferHandle in_handle_fd)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureObserver_OnBufferCreated_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureObserver_OnBufferCreated_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureObserver_OnBufferCreated_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->buffer_id = in_buffer_id;
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_handle_fd, &params->handle_fd, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->handle_fd),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid handle_fd in VideoCaptureObserver.OnBufferCreated request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoCaptureObserverProxy::OnBufferReady(
        int32_t in_buffer_id, ::media::mojom::VideoFrameInfoPtr in_info)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureObserver_OnBufferReady_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::VideoFrameInfoDataView>(
            in_info, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureObserver_OnBufferReady_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureObserver_OnBufferReady_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->buffer_id = in_buffer_id;
        typename decltype(params->info)::BaseType* info_ptr;
        mojo::internal::Serialize<::media::mojom::VideoFrameInfoDataView>(
            in_info, builder.buffer(), &info_ptr, &serialization_context);
        params->info.Set(info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null info in VideoCaptureObserver.OnBufferReady request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoCaptureObserverProxy::OnBufferDestroyed(
        int32_t in_buffer_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureObserver_OnBufferDestroyed_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureObserver_OnBufferDestroyed_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureObserver_OnBufferDestroyed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->buffer_id = in_buffer_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool VideoCaptureObserverStubDispatch::Accept(
        VideoCaptureObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kVideoCaptureObserver_OnStateChanged_Name: {
            internal::VideoCaptureObserver_OnStateChanged_Params_Data* params = reinterpret_cast<internal::VideoCaptureObserver_OnStateChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VideoCaptureState p_state {};
            VideoCaptureObserver_OnStateChanged_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadState(&p_state))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureObserver::OnStateChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureObserver::OnStateChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnStateChanged(
                std::move(p_state));
            return true;
        }
        case internal::kVideoCaptureObserver_OnBufferCreated_Name: {
            internal::VideoCaptureObserver_OnBufferCreated_Params_Data* params = reinterpret_cast<internal::VideoCaptureObserver_OnBufferCreated_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_buffer_id {};
            mojo::ScopedSharedBufferHandle p_handle_fd {};
            VideoCaptureObserver_OnBufferCreated_ParamsDataView input_data_view(params,
                context);

            p_buffer_id = input_data_view.buffer_id();
            p_handle_fd = input_data_view.TakeHandleFd();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureObserver::OnBufferCreated deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureObserver::OnBufferCreated");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnBufferCreated(
                std::move(p_buffer_id),
                std::move(p_handle_fd));
            return true;
        }
        case internal::kVideoCaptureObserver_OnBufferReady_Name: {
            internal::VideoCaptureObserver_OnBufferReady_Params_Data* params = reinterpret_cast<internal::VideoCaptureObserver_OnBufferReady_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_buffer_id {};
            ::media::mojom::VideoFrameInfoPtr p_info {};
            VideoCaptureObserver_OnBufferReady_ParamsDataView input_data_view(params,
                context);

            p_buffer_id = input_data_view.buffer_id();
            if (!input_data_view.ReadInfo(&p_info))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureObserver::OnBufferReady deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureObserver::OnBufferReady");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnBufferReady(
                std::move(p_buffer_id),
                std::move(p_info));
            return true;
        }
        case internal::kVideoCaptureObserver_OnBufferDestroyed_Name: {
            internal::VideoCaptureObserver_OnBufferDestroyed_Params_Data* params = reinterpret_cast<internal::VideoCaptureObserver_OnBufferDestroyed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_buffer_id {};
            VideoCaptureObserver_OnBufferDestroyed_ParamsDataView input_data_view(params,
                context);

            p_buffer_id = input_data_view.buffer_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureObserver::OnBufferDestroyed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureObserver::OnBufferDestroyed");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnBufferDestroyed(
                std::move(p_buffer_id));
            return true;
        }
        }
        return false;
    }

    // static
    bool VideoCaptureObserverStubDispatch::AcceptWithResponder(
        VideoCaptureObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kVideoCaptureObserver_OnStateChanged_Name: {
            break;
        }
        case internal::kVideoCaptureObserver_OnBufferCreated_Name: {
            break;
        }
        case internal::kVideoCaptureObserver_OnBufferReady_Name: {
            break;
        }
        case internal::kVideoCaptureObserver_OnBufferDestroyed_Name: {
            break;
        }
        }
        return false;
    }

    bool VideoCaptureObserverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VideoCaptureObserver RequestValidator");

        switch (message->header()->name) {
        case internal::kVideoCaptureObserver_OnStateChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureObserver_OnStateChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureObserver_OnBufferCreated_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureObserver_OnBufferCreated_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureObserver_OnBufferReady_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureObserver_OnBufferReady_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureObserver_OnBufferDestroyed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureObserver_OnBufferDestroyed_Params_Data>(
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

    const char VideoCaptureHost::Name_[] = "content::mojom::VideoCaptureHost";

    class VideoCaptureHost_GetDeviceSupportedFormats_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        VideoCaptureHost_GetDeviceSupportedFormats_ForwardToCallback(
            const VideoCaptureHost::GetDeviceSupportedFormatsCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        VideoCaptureHost::GetDeviceSupportedFormatsCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(VideoCaptureHost_GetDeviceSupportedFormats_ForwardToCallback);
    };
    bool VideoCaptureHost_GetDeviceSupportedFormats_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data* params = reinterpret_cast<internal::VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<media::VideoCaptureFormat> p_formats_supported {};
        VideoCaptureHost_GetDeviceSupportedFormats_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadFormatsSupported(&p_formats_supported))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VideoCaptureHost::GetDeviceSupportedFormats response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_formats_supported));
        }
        return true;
    }

    class VideoCaptureHost_GetDeviceFormatsInUse_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        VideoCaptureHost_GetDeviceFormatsInUse_ForwardToCallback(
            const VideoCaptureHost::GetDeviceFormatsInUseCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        VideoCaptureHost::GetDeviceFormatsInUseCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(VideoCaptureHost_GetDeviceFormatsInUse_ForwardToCallback);
    };
    bool VideoCaptureHost_GetDeviceFormatsInUse_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data* params = reinterpret_cast<internal::VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<media::VideoCaptureFormat> p_formats_in_use {};
        VideoCaptureHost_GetDeviceFormatsInUse_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadFormatsInUse(&p_formats_in_use))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VideoCaptureHost::GetDeviceFormatsInUse response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_formats_in_use));
        }
        return true;
    }

    VideoCaptureHostProxy::VideoCaptureHostProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void VideoCaptureHostProxy::Start(
        int32_t in_device_id, int32_t in_session_id, const media::VideoCaptureParams& in_params, VideoCaptureObserverPtr in_observer)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_Start_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::VideoCaptureParamsDataView>(
            in_params, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureHost_Start_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureHost_Start_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->device_id = in_device_id;
        params->session_id = in_session_id;
        typename decltype(params->params)::BaseType* params_ptr;
        mojo::internal::Serialize<::media::mojom::VideoCaptureParamsDataView>(
            in_params, builder.buffer(), &params_ptr, &serialization_context);
        params->params.Set(params_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->params.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null params in VideoCaptureHost.Start request");
        mojo::internal::Serialize<::content::mojom::VideoCaptureObserverPtrDataView>(
            in_observer, &params->observer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->observer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid observer in VideoCaptureHost.Start request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoCaptureHostProxy::Stop(
        int32_t in_device_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_Stop_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureHost_Stop_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureHost_Stop_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->device_id = in_device_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoCaptureHostProxy::Pause(
        int32_t in_device_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_Pause_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureHost_Pause_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureHost_Pause_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->device_id = in_device_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoCaptureHostProxy::Resume(
        int32_t in_device_id, int32_t in_session_id, const media::VideoCaptureParams& in_params)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_Resume_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::VideoCaptureParamsDataView>(
            in_params, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureHost_Resume_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureHost_Resume_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->device_id = in_device_id;
        params->session_id = in_session_id;
        typename decltype(params->params)::BaseType* params_ptr;
        mojo::internal::Serialize<::media::mojom::VideoCaptureParamsDataView>(
            in_params, builder.buffer(), &params_ptr, &serialization_context);
        params->params.Set(params_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->params.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null params in VideoCaptureHost.Resume request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoCaptureHostProxy::RequestRefreshFrame(
        int32_t in_device_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_RequestRefreshFrame_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureHost_RequestRefreshFrame_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureHost_RequestRefreshFrame_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->device_id = in_device_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoCaptureHostProxy::ReleaseBuffer(
        int32_t in_device_id, int32_t in_buffer_id, double in_consumer_resource_utilization)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_ReleaseBuffer_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVideoCaptureHost_ReleaseBuffer_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureHost_ReleaseBuffer_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->device_id = in_device_id;
        params->buffer_id = in_buffer_id;
        params->consumer_resource_utilization = in_consumer_resource_utilization;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VideoCaptureHostProxy::GetDeviceSupportedFormats(
        int32_t in_device_id, int32_t in_session_id, const GetDeviceSupportedFormatsCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_GetDeviceSupportedFormats_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kVideoCaptureHost_GetDeviceSupportedFormats_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureHost_GetDeviceSupportedFormats_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->device_id = in_device_id;
        params->session_id = in_session_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new VideoCaptureHost_GetDeviceSupportedFormats_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void VideoCaptureHostProxy::GetDeviceFormatsInUse(
        int32_t in_device_id, int32_t in_session_id, const GetDeviceFormatsInUseCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_GetDeviceFormatsInUse_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kVideoCaptureHost_GetDeviceFormatsInUse_Name, size);

        auto params = ::content::mojom::internal::VideoCaptureHost_GetDeviceFormatsInUse_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->device_id = in_device_id;
        params->session_id = in_session_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new VideoCaptureHost_GetDeviceFormatsInUse_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class VideoCaptureHost_GetDeviceSupportedFormats_ProxyToResponder {
    public:
        static VideoCaptureHost::GetDeviceSupportedFormatsCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<VideoCaptureHost_GetDeviceSupportedFormats_ProxyToResponder> proxy(
                new VideoCaptureHost_GetDeviceSupportedFormats_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&VideoCaptureHost_GetDeviceSupportedFormats_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~VideoCaptureHost_GetDeviceSupportedFormats_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "VideoCaptureHost::GetDeviceSupportedFormats() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        VideoCaptureHost_GetDeviceSupportedFormats_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            const std::vector<media::VideoCaptureFormat>& in_formats_supported);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(VideoCaptureHost_GetDeviceSupportedFormats_ProxyToResponder);
    };

    void VideoCaptureHost_GetDeviceSupportedFormats_ProxyToResponder::Run(
        const std::vector<media::VideoCaptureFormat>& in_formats_supported)
    {
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>>(
            in_formats_supported, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kVideoCaptureHost_GetDeviceSupportedFormats_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->formats_supported)::BaseType* formats_supported_ptr;
        const mojo::internal::ContainerValidateParams formats_supported_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>>(
            in_formats_supported, builder.buffer(), &formats_supported_ptr, &formats_supported_validate_params,
            &serialization_context_);
        params->formats_supported.Set(formats_supported_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->formats_supported.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null formats_supported in VideoCaptureHost.GetDeviceSupportedFormats response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class VideoCaptureHost_GetDeviceFormatsInUse_ProxyToResponder {
    public:
        static VideoCaptureHost::GetDeviceFormatsInUseCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<VideoCaptureHost_GetDeviceFormatsInUse_ProxyToResponder> proxy(
                new VideoCaptureHost_GetDeviceFormatsInUse_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&VideoCaptureHost_GetDeviceFormatsInUse_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~VideoCaptureHost_GetDeviceFormatsInUse_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "VideoCaptureHost::GetDeviceFormatsInUse() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        VideoCaptureHost_GetDeviceFormatsInUse_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            const std::vector<media::VideoCaptureFormat>& in_formats_in_use);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(VideoCaptureHost_GetDeviceFormatsInUse_ProxyToResponder);
    };

    void VideoCaptureHost_GetDeviceFormatsInUse_ProxyToResponder::Run(
        const std::vector<media::VideoCaptureFormat>& in_formats_in_use)
    {
        size_t size = sizeof(::content::mojom::internal::VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>>(
            in_formats_in_use, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kVideoCaptureHost_GetDeviceFormatsInUse_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->formats_in_use)::BaseType* formats_in_use_ptr;
        const mojo::internal::ContainerValidateParams formats_in_use_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::media::mojom::VideoCaptureFormatDataView>>(
            in_formats_in_use, builder.buffer(), &formats_in_use_ptr, &formats_in_use_validate_params,
            &serialization_context_);
        params->formats_in_use.Set(formats_in_use_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->formats_in_use.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null formats_in_use in VideoCaptureHost.GetDeviceFormatsInUse response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }

    // static
    bool VideoCaptureHostStubDispatch::Accept(
        VideoCaptureHost* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kVideoCaptureHost_Start_Name: {
            internal::VideoCaptureHost_Start_Params_Data* params = reinterpret_cast<internal::VideoCaptureHost_Start_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_device_id {};
            int32_t p_session_id {};
            media::VideoCaptureParams p_params {};
            VideoCaptureObserverPtr p_observer {};
            VideoCaptureHost_Start_ParamsDataView input_data_view(params,
                context);

            p_device_id = input_data_view.device_id();
            p_session_id = input_data_view.session_id();
            if (!input_data_view.ReadParams(&p_params))
                success = false;
            p_observer = input_data_view.TakeObserver<decltype(p_observer)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureHost::Start deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureHost::Start");
            mojo::internal::MessageDispatchContext context(message);
            impl->Start(
                std::move(p_device_id),
                std::move(p_session_id),
                std::move(p_params),
                std::move(p_observer));
            return true;
        }
        case internal::kVideoCaptureHost_Stop_Name: {
            internal::VideoCaptureHost_Stop_Params_Data* params = reinterpret_cast<internal::VideoCaptureHost_Stop_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_device_id {};
            VideoCaptureHost_Stop_ParamsDataView input_data_view(params,
                context);

            p_device_id = input_data_view.device_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureHost::Stop deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureHost::Stop");
            mojo::internal::MessageDispatchContext context(message);
            impl->Stop(
                std::move(p_device_id));
            return true;
        }
        case internal::kVideoCaptureHost_Pause_Name: {
            internal::VideoCaptureHost_Pause_Params_Data* params = reinterpret_cast<internal::VideoCaptureHost_Pause_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_device_id {};
            VideoCaptureHost_Pause_ParamsDataView input_data_view(params,
                context);

            p_device_id = input_data_view.device_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureHost::Pause deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureHost::Pause");
            mojo::internal::MessageDispatchContext context(message);
            impl->Pause(
                std::move(p_device_id));
            return true;
        }
        case internal::kVideoCaptureHost_Resume_Name: {
            internal::VideoCaptureHost_Resume_Params_Data* params = reinterpret_cast<internal::VideoCaptureHost_Resume_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_device_id {};
            int32_t p_session_id {};
            media::VideoCaptureParams p_params {};
            VideoCaptureHost_Resume_ParamsDataView input_data_view(params,
                context);

            p_device_id = input_data_view.device_id();
            p_session_id = input_data_view.session_id();
            if (!input_data_view.ReadParams(&p_params))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureHost::Resume deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureHost::Resume");
            mojo::internal::MessageDispatchContext context(message);
            impl->Resume(
                std::move(p_device_id),
                std::move(p_session_id),
                std::move(p_params));
            return true;
        }
        case internal::kVideoCaptureHost_RequestRefreshFrame_Name: {
            internal::VideoCaptureHost_RequestRefreshFrame_Params_Data* params = reinterpret_cast<internal::VideoCaptureHost_RequestRefreshFrame_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_device_id {};
            VideoCaptureHost_RequestRefreshFrame_ParamsDataView input_data_view(params,
                context);

            p_device_id = input_data_view.device_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureHost::RequestRefreshFrame deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureHost::RequestRefreshFrame");
            mojo::internal::MessageDispatchContext context(message);
            impl->RequestRefreshFrame(
                std::move(p_device_id));
            return true;
        }
        case internal::kVideoCaptureHost_ReleaseBuffer_Name: {
            internal::VideoCaptureHost_ReleaseBuffer_Params_Data* params = reinterpret_cast<internal::VideoCaptureHost_ReleaseBuffer_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_device_id {};
            int32_t p_buffer_id {};
            double p_consumer_resource_utilization {};
            VideoCaptureHost_ReleaseBuffer_ParamsDataView input_data_view(params,
                context);

            p_device_id = input_data_view.device_id();
            p_buffer_id = input_data_view.buffer_id();
            p_consumer_resource_utilization = input_data_view.consumer_resource_utilization();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureHost::ReleaseBuffer deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureHost::ReleaseBuffer");
            mojo::internal::MessageDispatchContext context(message);
            impl->ReleaseBuffer(
                std::move(p_device_id),
                std::move(p_buffer_id),
                std::move(p_consumer_resource_utilization));
            return true;
        }
        case internal::kVideoCaptureHost_GetDeviceSupportedFormats_Name: {
            break;
        }
        case internal::kVideoCaptureHost_GetDeviceFormatsInUse_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool VideoCaptureHostStubDispatch::AcceptWithResponder(
        VideoCaptureHost* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kVideoCaptureHost_Start_Name: {
            break;
        }
        case internal::kVideoCaptureHost_Stop_Name: {
            break;
        }
        case internal::kVideoCaptureHost_Pause_Name: {
            break;
        }
        case internal::kVideoCaptureHost_Resume_Name: {
            break;
        }
        case internal::kVideoCaptureHost_RequestRefreshFrame_Name: {
            break;
        }
        case internal::kVideoCaptureHost_ReleaseBuffer_Name: {
            break;
        }
        case internal::kVideoCaptureHost_GetDeviceSupportedFormats_Name: {
            internal::VideoCaptureHost_GetDeviceSupportedFormats_Params_Data* params = reinterpret_cast<internal::VideoCaptureHost_GetDeviceSupportedFormats_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_device_id {};
            int32_t p_session_id {};
            VideoCaptureHost_GetDeviceSupportedFormats_ParamsDataView input_data_view(params,
                context);

            p_device_id = input_data_view.device_id();
            p_session_id = input_data_view.session_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureHost::GetDeviceSupportedFormats deserializer");
                return false;
            }
            VideoCaptureHost::GetDeviceSupportedFormatsCallback callback = VideoCaptureHost_GetDeviceSupportedFormats_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureHost::GetDeviceSupportedFormats");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetDeviceSupportedFormats(
                std::move(p_device_id),
                std::move(p_session_id), std::move(callback));
            return true;
        }
        case internal::kVideoCaptureHost_GetDeviceFormatsInUse_Name: {
            internal::VideoCaptureHost_GetDeviceFormatsInUse_Params_Data* params = reinterpret_cast<internal::VideoCaptureHost_GetDeviceFormatsInUse_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_device_id {};
            int32_t p_session_id {};
            VideoCaptureHost_GetDeviceFormatsInUse_ParamsDataView input_data_view(params,
                context);

            p_device_id = input_data_view.device_id();
            p_session_id = input_data_view.session_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VideoCaptureHost::GetDeviceFormatsInUse deserializer");
                return false;
            }
            VideoCaptureHost::GetDeviceFormatsInUseCallback callback = VideoCaptureHost_GetDeviceFormatsInUse_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VideoCaptureHost::GetDeviceFormatsInUse");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetDeviceFormatsInUse(
                std::move(p_device_id),
                std::move(p_session_id), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool VideoCaptureHostRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VideoCaptureHost RequestValidator");

        switch (message->header()->name) {
        case internal::kVideoCaptureHost_Start_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_Start_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureHost_Stop_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_Stop_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureHost_Pause_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_Pause_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureHost_Resume_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_Resume_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureHost_RequestRefreshFrame_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_RequestRefreshFrame_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureHost_ReleaseBuffer_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_ReleaseBuffer_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureHost_GetDeviceSupportedFormats_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_GetDeviceSupportedFormats_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureHost_GetDeviceFormatsInUse_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_GetDeviceFormatsInUse_Params_Data>(
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

    bool VideoCaptureHostResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VideoCaptureHost ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kVideoCaptureHost_GetDeviceSupportedFormats_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_GetDeviceSupportedFormats_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVideoCaptureHost_GetDeviceFormatsInUse_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VideoCaptureHost_GetDeviceFormatsInUse_ResponseParams_Data>(
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