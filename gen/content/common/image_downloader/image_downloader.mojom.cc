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

#include "content/common/image_downloader/image_downloader.mojom.h"

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
    const char ImageDownloader::Name_[] = "content::mojom::ImageDownloader";

    class ImageDownloader_DownloadImage_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ImageDownloader_DownloadImage_ForwardToCallback(
            const ImageDownloader::DownloadImageCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ImageDownloader::DownloadImageCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ImageDownloader_DownloadImage_ForwardToCallback);
    };
    bool ImageDownloader_DownloadImage_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ImageDownloader_DownloadImage_ResponseParams_Data* params = reinterpret_cast<internal::ImageDownloader_DownloadImage_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        int32_t p_http_status_code {};
        std::vector<SkBitmap> p_images {};
        std::vector<gfx::Size> p_original_image_sizes {};
        ImageDownloader_DownloadImage_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_http_status_code = input_data_view.http_status_code();
        if (!input_data_view.ReadImages(&p_images))
            success = false;
        if (!input_data_view.ReadOriginalImageSizes(&p_original_image_sizes))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ImageDownloader::DownloadImage response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_http_status_code),
                std::move(p_images),
                std::move(p_original_image_sizes));
        }
        return true;
    }

    ImageDownloaderProxy::ImageDownloaderProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ImageDownloaderProxy::DownloadImage(
        const GURL& in_url, bool in_is_favicon, uint32_t in_max_bitmap_size, bool in_bypass_cache, const DownloadImageCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::ImageDownloader_DownloadImage_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_url, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kImageDownloader_DownloadImage_Name, size);

        auto params = ::content::mojom::internal::ImageDownloader_DownloadImage_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in ImageDownloader.DownloadImage request");
        params->is_favicon = in_is_favicon;
        params->max_bitmap_size = in_max_bitmap_size;
        params->bypass_cache = in_bypass_cache;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ImageDownloader_DownloadImage_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class ImageDownloader_DownloadImage_ProxyToResponder {
    public:
        static ImageDownloader::DownloadImageCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ImageDownloader_DownloadImage_ProxyToResponder> proxy(
                new ImageDownloader_DownloadImage_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ImageDownloader_DownloadImage_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ImageDownloader_DownloadImage_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ImageDownloader::DownloadImage() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ImageDownloader_DownloadImage_ProxyToResponder(
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
            int32_t in_http_status_code, const std::vector<SkBitmap>& in_images, const std::vector<gfx::Size>& in_original_image_sizes);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ImageDownloader_DownloadImage_ProxyToResponder);
    };

    void ImageDownloader_DownloadImage_ProxyToResponder::Run(
        int32_t in_http_status_code, const std::vector<SkBitmap>& in_images, const std::vector<gfx::Size>& in_original_image_sizes)
    {
        size_t size = sizeof(::content::mojom::internal::ImageDownloader_DownloadImage_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::skia::mojom::BitmapDataView>>(
            in_images, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gfx::mojom::SizeDataView>>(
            in_original_image_sizes, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kImageDownloader_DownloadImage_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::ImageDownloader_DownloadImage_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->http_status_code = in_http_status_code;
        typename decltype(params->images)::BaseType* images_ptr;
        const mojo::internal::ContainerValidateParams images_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::skia::mojom::BitmapDataView>>(
            in_images, builder.buffer(), &images_ptr, &images_validate_params,
            &serialization_context_);
        params->images.Set(images_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->images.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null images in ImageDownloader.DownloadImage response");
        typename decltype(params->original_image_sizes)::BaseType* original_image_sizes_ptr;
        const mojo::internal::ContainerValidateParams original_image_sizes_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::gfx::mojom::SizeDataView>>(
            in_original_image_sizes, builder.buffer(), &original_image_sizes_ptr, &original_image_sizes_validate_params,
            &serialization_context_);
        params->original_image_sizes.Set(original_image_sizes_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->original_image_sizes.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null original_image_sizes in ImageDownloader.DownloadImage response");
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
    bool ImageDownloaderStubDispatch::Accept(
        ImageDownloader* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kImageDownloader_DownloadImage_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool ImageDownloaderStubDispatch::AcceptWithResponder(
        ImageDownloader* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kImageDownloader_DownloadImage_Name: {
            internal::ImageDownloader_DownloadImage_Params_Data* params = reinterpret_cast<internal::ImageDownloader_DownloadImage_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GURL p_url {};
            bool p_is_favicon {};
            uint32_t p_max_bitmap_size {};
            bool p_bypass_cache {};
            ImageDownloader_DownloadImage_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            p_is_favicon = input_data_view.is_favicon();
            p_max_bitmap_size = input_data_view.max_bitmap_size();
            p_bypass_cache = input_data_view.bypass_cache();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ImageDownloader::DownloadImage deserializer");
                return false;
            }
            ImageDownloader::DownloadImageCallback callback = ImageDownloader_DownloadImage_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ImageDownloader::DownloadImage");
            mojo::internal::MessageDispatchContext context(message);
            impl->DownloadImage(
                std::move(p_url),
                std::move(p_is_favicon),
                std::move(p_max_bitmap_size),
                std::move(p_bypass_cache), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool ImageDownloaderRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ImageDownloader RequestValidator");

        switch (message->header()->name) {
        case internal::kImageDownloader_DownloadImage_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ImageDownloader_DownloadImage_Params_Data>(
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

    bool ImageDownloaderResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ImageDownloader ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kImageDownloader_DownloadImage_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ImageDownloader_DownloadImage_ResponseParams_Data>(
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