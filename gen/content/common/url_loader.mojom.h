// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_URL_LOADER_MOJOM_H_
#define CONTENT_COMMON_URL_LOADER_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "cc/input/selection.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/compositor_frame_metadata.h"
#include "cc/output/filter_operation.h"
#include "cc/output/filter_operations.h"
#include "cc/quads/draw_quad.h"
#include "cc/quads/render_pass.h"
#include "cc/quads/shared_quad_state.h"
#include "cc/resources/returned_resource.h"
#include "cc/resources/transferable_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_reference.h"
#include "cc/surfaces/surface_sequence.h"
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/common/frame_owner_properties.h"
#include "content/common/frame_replication_state.h"
#include "content/common/indexed_db/indexed_db_key.h"
#include "content/common/indexed_db/indexed_db_key_path.h"
#include "content/common/indexed_db/indexed_db_key_range.h"
#include "content/common/indexed_db/indexed_db_metadata.h"
#include "content/common/media/media_devices.h"
#include "content/common/resize_params.h"
#include "content/common/resource_request.h"
#include "content/common/resource_request_completion_status.h"
#include "content/common/service_worker/embedded_worker_start_params.h"
#include "content/common/service_worker/service_worker_status_code.h"
#include "content/common/service_worker/service_worker_types.h"
#include "content/common/url_loader.mojom-shared.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/push_event_payload.h"
#include "content/public/common/referrer.h"
#include "content/public/common/renderer_preferences.h"
#include "content/public/common/resource_response.h"
#include "content/public/common/web_preferences.h"
#include "device/bluetooth/bluetooth_uuid.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
#include "media/base/audio_codecs.h"
#include "media/base/audio_parameters.h"
#include "media/base/buffering_state.h"
#include "media/base/cdm_key_information.h"
#include "media/base/cdm_promise.h"
#include "media/base/channel_layout.h"
#include "media/base/content_decryption_module.h"
#include "media/base/decode_status.h"
#include "media/base/decryptor.h"
#include "media/base/demuxer_stream.h"
#include "media/base/eme_constants.h"
#include "media/base/encryption_scheme.h"
#include "media/base/pipeline_status.h"
#include "media/base/sample_format.h"
#include "media/base/subsample_entry.h"
#include "media/base/video_codecs.h"
#include "media/base/video_types.h"
#include "media/capture/video/video_capture_device_descriptor.h"
#include "media/capture/video_capture_types.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "net/base/network_change_notifier.h"
#include "net/url_request/redirect_info.h"
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/interface_provider_spec.h"
#include "services/service_manager/public/cpp/service_info.h"
#include "services/video_capture/public/cpp/capture_settings.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/modules/indexeddb/WebIDBTypes.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebPopupType.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/base/window_open_disposition.h"
#include "ui/display/display.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/range/range.h"
#include "ui/gfx/range/range_f.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include "url/gurl.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace content {
namespace mojom {
    class URLLoader;
    using URLLoaderPtr = mojo::InterfacePtr<URLLoader>;
    using URLLoaderPtrInfo = mojo::InterfacePtrInfo<URLLoader>;
    using ThreadSafeURLLoaderPtr = mojo::ThreadSafeInterfacePtr<URLLoader>;
    using URLLoaderRequest = mojo::InterfaceRequest<URLLoader>;
    using URLLoaderAssociatedPtr = mojo::AssociatedInterfacePtr<URLLoader>;
    using ThreadSafeURLLoaderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<URLLoader>;
    using URLLoaderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<URLLoader>;
    using URLLoaderAssociatedRequest = mojo::AssociatedInterfaceRequest<URLLoader>;

    class DownloadedTempFile;
    using DownloadedTempFilePtr = mojo::InterfacePtr<DownloadedTempFile>;
    using DownloadedTempFilePtrInfo = mojo::InterfacePtrInfo<DownloadedTempFile>;
    using ThreadSafeDownloadedTempFilePtr = mojo::ThreadSafeInterfacePtr<DownloadedTempFile>;
    using DownloadedTempFileRequest = mojo::InterfaceRequest<DownloadedTempFile>;
    using DownloadedTempFileAssociatedPtr = mojo::AssociatedInterfacePtr<DownloadedTempFile>;
    using ThreadSafeDownloadedTempFileAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DownloadedTempFile>;
    using DownloadedTempFileAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DownloadedTempFile>;
    using DownloadedTempFileAssociatedRequest = mojo::AssociatedInterfaceRequest<DownloadedTempFile>;

    class URLLoaderClient;
    using URLLoaderClientPtr = mojo::InterfacePtr<URLLoaderClient>;
    using URLLoaderClientPtrInfo = mojo::InterfacePtrInfo<URLLoaderClient>;
    using ThreadSafeURLLoaderClientPtr = mojo::ThreadSafeInterfacePtr<URLLoaderClient>;
    using URLLoaderClientRequest = mojo::InterfaceRequest<URLLoaderClient>;
    using URLLoaderClientAssociatedPtr = mojo::AssociatedInterfacePtr<URLLoaderClient>;
    using ThreadSafeURLLoaderClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<URLLoaderClient>;
    using URLLoaderClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<URLLoaderClient>;
    using URLLoaderClientAssociatedRequest = mojo::AssociatedInterfaceRequest<URLLoaderClient>;

    using URLRequest = mojo::NativeStruct;
    using URLRequestPtr = mojo::NativeStructPtr;

    using URLResponseHead = mojo::NativeStruct;
    using URLResponseHeadPtr = mojo::NativeStructPtr;

    using URLRequestRedirectInfo = mojo::NativeStruct;
    using URLRequestRedirectInfoPtr = mojo::NativeStructPtr;

    using URLLoaderStatus = mojo::NativeStruct;
    using URLLoaderStatusPtr = mojo::NativeStructPtr;

    class URLLoaderProxy;

    template <typename ImplRefTraits>
    class URLLoaderStub;

    class URLLoaderRequestValidator;

    class CONTENT_EXPORT URLLoader
        : public URLLoaderInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = URLLoaderProxy;

        template <typename ImplRefTraits>
        using Stub_ = URLLoaderStub<ImplRefTraits>;

        using RequestValidator_ = URLLoaderRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kFollowRedirectMinVersion = 0,
        };
        virtual ~URLLoader() { }

        virtual void FollowRedirect() = 0;
    };

    class DownloadedTempFileProxy;

    template <typename ImplRefTraits>
    class DownloadedTempFileStub;

    class DownloadedTempFileRequestValidator;

    class CONTENT_EXPORT DownloadedTempFile
        : public DownloadedTempFileInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DownloadedTempFileProxy;

        template <typename ImplRefTraits>
        using Stub_ = DownloadedTempFileStub<ImplRefTraits>;

        using RequestValidator_ = DownloadedTempFileRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
        };
        virtual ~DownloadedTempFile() { }
    };

    class URLLoaderClientProxy;

    template <typename ImplRefTraits>
    class URLLoaderClientStub;

    class URLLoaderClientRequestValidator;

    class CONTENT_EXPORT URLLoaderClient
        : public URLLoaderClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = URLLoaderClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = URLLoaderClientStub<ImplRefTraits>;

        using RequestValidator_ = URLLoaderClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnReceiveResponseMinVersion = 0,
            kOnReceiveRedirectMinVersion = 0,
            kOnDataDownloadedMinVersion = 0,
            kOnReceiveCachedMetadataMinVersion = 0,
            kOnTransferSizeUpdatedMinVersion = 0,
            kOnStartLoadingResponseBodyMinVersion = 0,
            kOnCompleteMinVersion = 0,
        };
        virtual ~URLLoaderClient() { }

        virtual void OnReceiveResponse(const content::ResourceResponseHead& head, DownloadedTempFilePtr downloaded_file) = 0;

        virtual void OnReceiveRedirect(const net::RedirectInfo& redirect_info, const content::ResourceResponseHead& head) = 0;

        virtual void OnDataDownloaded(int64_t data_length, int64_t encoded_length) = 0;

        virtual void OnReceiveCachedMetadata(const std::vector<uint8_t>& data) = 0;

        virtual void OnTransferSizeUpdated(int32_t transfer_size_diff) = 0;

        virtual void OnStartLoadingResponseBody(mojo::ScopedDataPipeConsumerHandle body) = 0;

        virtual void OnComplete(const content::ResourceRequestCompletionStatus& completion_status) = 0;
    };

    class CONTENT_EXPORT URLLoaderProxy
        : public URLLoader {
    public:
        explicit URLLoaderProxy(mojo::MessageReceiverWithResponder* receiver);
        void FollowRedirect() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT DownloadedTempFileProxy
        : public DownloadedTempFile {
    public:
        explicit DownloadedTempFileProxy(mojo::MessageReceiverWithResponder* receiver);

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT URLLoaderClientProxy
        : public URLLoaderClient {
    public:
        explicit URLLoaderClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnReceiveResponse(const content::ResourceResponseHead& head, DownloadedTempFilePtr downloaded_file) override;
        void OnReceiveRedirect(const net::RedirectInfo& redirect_info, const content::ResourceResponseHead& head) override;
        void OnDataDownloaded(int64_t data_length, int64_t encoded_length) override;
        void OnReceiveCachedMetadata(const std::vector<uint8_t>& data) override;
        void OnTransferSizeUpdated(int32_t transfer_size_diff) override;
        void OnStartLoadingResponseBody(mojo::ScopedDataPipeConsumerHandle body) override;
        void OnComplete(const content::ResourceRequestCompletionStatus& completion_status) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT URLLoaderStubDispatch {
    public:
        static bool Accept(URLLoader* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(URLLoader* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<URLLoader>>
    class URLLoaderStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        URLLoaderStub() { }
        ~URLLoaderStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return URLLoaderStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return URLLoaderStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT DownloadedTempFileStubDispatch {
    public:
        static bool Accept(DownloadedTempFile* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DownloadedTempFile* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DownloadedTempFile>>
    class DownloadedTempFileStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DownloadedTempFileStub() { }
        ~DownloadedTempFileStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DownloadedTempFileStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DownloadedTempFileStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT URLLoaderClientStubDispatch {
    public:
        static bool Accept(URLLoaderClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(URLLoaderClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<URLLoaderClient>>
    class URLLoaderClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        URLLoaderClientStub() { }
        ~URLLoaderClientStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return URLLoaderClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return URLLoaderClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT URLLoaderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT DownloadedTempFileRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT URLLoaderClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace content

namespace mojo {

} // namespace mojo

#endif // CONTENT_COMMON_URL_LOADER_MOJOM_H_