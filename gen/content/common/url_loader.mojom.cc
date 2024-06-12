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

#include "content/common/url_loader.mojom.h"

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
    const char URLLoader::Name_[] = "content::mojom::URLLoader";

    URLLoaderProxy::URLLoaderProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void URLLoaderProxy::FollowRedirect()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoader_FollowRedirect_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kURLLoader_FollowRedirect_Name, size);

        auto params = ::content::mojom::internal::URLLoader_FollowRedirect_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool URLLoaderStubDispatch::Accept(
        URLLoader* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kURLLoader_FollowRedirect_Name: {
            internal::URLLoader_FollowRedirect_Params_Data* params = reinterpret_cast<internal::URLLoader_FollowRedirect_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            URLLoader_FollowRedirect_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoader::FollowRedirect deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoader::FollowRedirect");
            mojo::internal::MessageDispatchContext context(message);
            impl->FollowRedirect();
            return true;
        }
        }
        return false;
    }

    // static
    bool URLLoaderStubDispatch::AcceptWithResponder(
        URLLoader* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kURLLoader_FollowRedirect_Name: {
            break;
        }
        }
        return false;
    }

    bool URLLoaderRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "URLLoader RequestValidator");

        switch (message->header()->name) {
        case internal::kURLLoader_FollowRedirect_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoader_FollowRedirect_Params_Data>(
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

    const char DownloadedTempFile::Name_[] = "content::mojom::DownloadedTempFile";

    DownloadedTempFileProxy::DownloadedTempFileProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    // static
    bool DownloadedTempFileStubDispatch::Accept(
        DownloadedTempFile* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        return false;
    }

    // static
    bool DownloadedTempFileStubDispatch::AcceptWithResponder(
        DownloadedTempFile* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        return false;
    }

    bool DownloadedTempFileRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DownloadedTempFile RequestValidator");

        switch (message->header()->name) {
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    const char URLLoaderClient::Name_[] = "content::mojom::URLLoaderClient";

    URLLoaderClientProxy::URLLoaderClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void URLLoaderClientProxy::OnReceiveResponse(
        const content::ResourceResponseHead& in_head, DownloadedTempFilePtr in_downloaded_file)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderClient_OnReceiveResponse_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::URLResponseHeadDataView>(
            in_head, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kURLLoaderClient_OnReceiveResponse_Name, size);

        auto params = ::content::mojom::internal::URLLoaderClient_OnReceiveResponse_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->head)::BaseType* head_ptr;
        mojo::internal::Serialize<::content::mojom::URLResponseHeadDataView>(
            in_head, builder.buffer(), &head_ptr, &serialization_context);
        params->head.Set(head_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->head.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null head in URLLoaderClient.OnReceiveResponse request");
        mojo::internal::Serialize<::content::mojom::DownloadedTempFilePtrDataView>(
            in_downloaded_file, &params->downloaded_file, &serialization_context);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void URLLoaderClientProxy::OnReceiveRedirect(
        const net::RedirectInfo& in_redirect_info, const content::ResourceResponseHead& in_head)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderClient_OnReceiveRedirect_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::URLRequestRedirectInfoDataView>(
            in_redirect_info, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::content::mojom::URLResponseHeadDataView>(
            in_head, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kURLLoaderClient_OnReceiveRedirect_Name, size);

        auto params = ::content::mojom::internal::URLLoaderClient_OnReceiveRedirect_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->redirect_info)::BaseType* redirect_info_ptr;
        mojo::internal::Serialize<::content::mojom::URLRequestRedirectInfoDataView>(
            in_redirect_info, builder.buffer(), &redirect_info_ptr, &serialization_context);
        params->redirect_info.Set(redirect_info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->redirect_info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null redirect_info in URLLoaderClient.OnReceiveRedirect request");
        typename decltype(params->head)::BaseType* head_ptr;
        mojo::internal::Serialize<::content::mojom::URLResponseHeadDataView>(
            in_head, builder.buffer(), &head_ptr, &serialization_context);
        params->head.Set(head_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->head.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null head in URLLoaderClient.OnReceiveRedirect request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void URLLoaderClientProxy::OnDataDownloaded(
        int64_t in_data_length, int64_t in_encoded_length)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderClient_OnDataDownloaded_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kURLLoaderClient_OnDataDownloaded_Name, size);

        auto params = ::content::mojom::internal::URLLoaderClient_OnDataDownloaded_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->data_length = in_data_length;
        params->encoded_length = in_encoded_length;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void URLLoaderClientProxy::OnReceiveCachedMetadata(
        const std::vector<uint8_t>& in_data)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderClient_OnReceiveCachedMetadata_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_data, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kURLLoaderClient_OnReceiveCachedMetadata_Name, size);

        auto params = ::content::mojom::internal::URLLoaderClient_OnReceiveCachedMetadata_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
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
            "null data in URLLoaderClient.OnReceiveCachedMetadata request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void URLLoaderClientProxy::OnTransferSizeUpdated(
        int32_t in_transfer_size_diff)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderClient_OnTransferSizeUpdated_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kURLLoaderClient_OnTransferSizeUpdated_Name, size);

        auto params = ::content::mojom::internal::URLLoaderClient_OnTransferSizeUpdated_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transfer_size_diff = in_transfer_size_diff;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void URLLoaderClientProxy::OnStartLoadingResponseBody(
        mojo::ScopedDataPipeConsumerHandle in_body)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderClient_OnStartLoadingResponseBody_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kURLLoaderClient_OnStartLoadingResponseBody_Name, size);

        auto params = ::content::mojom::internal::URLLoaderClient_OnStartLoadingResponseBody_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedDataPipeConsumerHandle>(
            in_body, &params->body, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->body),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid body in URLLoaderClient.OnStartLoadingResponseBody request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void URLLoaderClientProxy::OnComplete(
        const content::ResourceRequestCompletionStatus& in_completion_status)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::URLLoaderClient_OnComplete_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::URLLoaderStatusDataView>(
            in_completion_status, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kURLLoaderClient_OnComplete_Name, size);

        auto params = ::content::mojom::internal::URLLoaderClient_OnComplete_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->completion_status)::BaseType* completion_status_ptr;
        mojo::internal::Serialize<::content::mojom::URLLoaderStatusDataView>(
            in_completion_status, builder.buffer(), &completion_status_ptr, &serialization_context);
        params->completion_status.Set(completion_status_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->completion_status.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null completion_status in URLLoaderClient.OnComplete request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool URLLoaderClientStubDispatch::Accept(
        URLLoaderClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kURLLoaderClient_OnReceiveResponse_Name: {
            internal::URLLoaderClient_OnReceiveResponse_Params_Data* params = reinterpret_cast<internal::URLLoaderClient_OnReceiveResponse_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            content::ResourceResponseHead p_head {};
            DownloadedTempFilePtr p_downloaded_file {};
            URLLoaderClient_OnReceiveResponse_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadHead(&p_head))
                success = false;
            p_downloaded_file = input_data_view.TakeDownloadedFile<decltype(p_downloaded_file)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoaderClient::OnReceiveResponse deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoaderClient::OnReceiveResponse");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnReceiveResponse(
                std::move(p_head),
                std::move(p_downloaded_file));
            return true;
        }
        case internal::kURLLoaderClient_OnReceiveRedirect_Name: {
            internal::URLLoaderClient_OnReceiveRedirect_Params_Data* params = reinterpret_cast<internal::URLLoaderClient_OnReceiveRedirect_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            net::RedirectInfo p_redirect_info {};
            content::ResourceResponseHead p_head {};
            URLLoaderClient_OnReceiveRedirect_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadRedirectInfo(&p_redirect_info))
                success = false;
            if (!input_data_view.ReadHead(&p_head))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoaderClient::OnReceiveRedirect deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoaderClient::OnReceiveRedirect");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnReceiveRedirect(
                std::move(p_redirect_info),
                std::move(p_head));
            return true;
        }
        case internal::kURLLoaderClient_OnDataDownloaded_Name: {
            internal::URLLoaderClient_OnDataDownloaded_Params_Data* params = reinterpret_cast<internal::URLLoaderClient_OnDataDownloaded_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_data_length {};
            int64_t p_encoded_length {};
            URLLoaderClient_OnDataDownloaded_ParamsDataView input_data_view(params,
                context);

            p_data_length = input_data_view.data_length();
            p_encoded_length = input_data_view.encoded_length();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoaderClient::OnDataDownloaded deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoaderClient::OnDataDownloaded");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDataDownloaded(
                std::move(p_data_length),
                std::move(p_encoded_length));
            return true;
        }
        case internal::kURLLoaderClient_OnReceiveCachedMetadata_Name: {
            internal::URLLoaderClient_OnReceiveCachedMetadata_Params_Data* params = reinterpret_cast<internal::URLLoaderClient_OnReceiveCachedMetadata_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_data {};
            URLLoaderClient_OnReceiveCachedMetadata_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadData(&p_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoaderClient::OnReceiveCachedMetadata deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoaderClient::OnReceiveCachedMetadata");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnReceiveCachedMetadata(
                std::move(p_data));
            return true;
        }
        case internal::kURLLoaderClient_OnTransferSizeUpdated_Name: {
            internal::URLLoaderClient_OnTransferSizeUpdated_Params_Data* params = reinterpret_cast<internal::URLLoaderClient_OnTransferSizeUpdated_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_transfer_size_diff {};
            URLLoaderClient_OnTransferSizeUpdated_ParamsDataView input_data_view(params,
                context);

            p_transfer_size_diff = input_data_view.transfer_size_diff();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoaderClient::OnTransferSizeUpdated deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoaderClient::OnTransferSizeUpdated");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnTransferSizeUpdated(
                std::move(p_transfer_size_diff));
            return true;
        }
        case internal::kURLLoaderClient_OnStartLoadingResponseBody_Name: {
            internal::URLLoaderClient_OnStartLoadingResponseBody_Params_Data* params = reinterpret_cast<internal::URLLoaderClient_OnStartLoadingResponseBody_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedDataPipeConsumerHandle p_body {};
            URLLoaderClient_OnStartLoadingResponseBody_ParamsDataView input_data_view(params,
                context);

            p_body = input_data_view.TakeBody();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoaderClient::OnStartLoadingResponseBody deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoaderClient::OnStartLoadingResponseBody");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnStartLoadingResponseBody(
                std::move(p_body));
            return true;
        }
        case internal::kURLLoaderClient_OnComplete_Name: {
            internal::URLLoaderClient_OnComplete_Params_Data* params = reinterpret_cast<internal::URLLoaderClient_OnComplete_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            content::ResourceRequestCompletionStatus p_completion_status {};
            URLLoaderClient_OnComplete_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadCompletionStatus(&p_completion_status))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "URLLoaderClient::OnComplete deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "URLLoaderClient::OnComplete");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnComplete(
                std::move(p_completion_status));
            return true;
        }
        }
        return false;
    }

    // static
    bool URLLoaderClientStubDispatch::AcceptWithResponder(
        URLLoaderClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kURLLoaderClient_OnReceiveResponse_Name: {
            break;
        }
        case internal::kURLLoaderClient_OnReceiveRedirect_Name: {
            break;
        }
        case internal::kURLLoaderClient_OnDataDownloaded_Name: {
            break;
        }
        case internal::kURLLoaderClient_OnReceiveCachedMetadata_Name: {
            break;
        }
        case internal::kURLLoaderClient_OnTransferSizeUpdated_Name: {
            break;
        }
        case internal::kURLLoaderClient_OnStartLoadingResponseBody_Name: {
            break;
        }
        case internal::kURLLoaderClient_OnComplete_Name: {
            break;
        }
        }
        return false;
    }

    bool URLLoaderClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "URLLoaderClient RequestValidator");

        switch (message->header()->name) {
        case internal::kURLLoaderClient_OnReceiveResponse_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderClient_OnReceiveResponse_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kURLLoaderClient_OnReceiveRedirect_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderClient_OnReceiveRedirect_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kURLLoaderClient_OnDataDownloaded_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderClient_OnDataDownloaded_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kURLLoaderClient_OnReceiveCachedMetadata_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderClient_OnReceiveCachedMetadata_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kURLLoaderClient_OnTransferSizeUpdated_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderClient_OnTransferSizeUpdated_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kURLLoaderClient_OnStartLoadingResponseBody_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderClient_OnStartLoadingResponseBody_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kURLLoaderClient_OnComplete_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::URLLoaderClient_OnComplete_Params_Data>(
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