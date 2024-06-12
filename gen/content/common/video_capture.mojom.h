// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_VIDEO_CAPTURE_MOJOM_H_
#define CONTENT_COMMON_VIDEO_CAPTURE_MOJOM_H_

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
#include "content/common/video_capture.mojom-shared.h"
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
#include "media/capture/mojo/video_capture_types.mojom.h"
#include "media/capture/video/video_capture_device_descriptor.h"
#include "media/capture/video_capture_types.h"
#include "media/mojo/interfaces/media_types.mojom.h"
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
#include "ui/gfx/geometry/mojo/geometry.mojom.h"
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
    class VideoCaptureObserver;
    using VideoCaptureObserverPtr = mojo::InterfacePtr<VideoCaptureObserver>;
    using VideoCaptureObserverPtrInfo = mojo::InterfacePtrInfo<VideoCaptureObserver>;
    using ThreadSafeVideoCaptureObserverPtr = mojo::ThreadSafeInterfacePtr<VideoCaptureObserver>;
    using VideoCaptureObserverRequest = mojo::InterfaceRequest<VideoCaptureObserver>;
    using VideoCaptureObserverAssociatedPtr = mojo::AssociatedInterfacePtr<VideoCaptureObserver>;
    using ThreadSafeVideoCaptureObserverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VideoCaptureObserver>;
    using VideoCaptureObserverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VideoCaptureObserver>;
    using VideoCaptureObserverAssociatedRequest = mojo::AssociatedInterfaceRequest<VideoCaptureObserver>;

    class VideoCaptureHost;
    using VideoCaptureHostPtr = mojo::InterfacePtr<VideoCaptureHost>;
    using VideoCaptureHostPtrInfo = mojo::InterfacePtrInfo<VideoCaptureHost>;
    using ThreadSafeVideoCaptureHostPtr = mojo::ThreadSafeInterfacePtr<VideoCaptureHost>;
    using VideoCaptureHostRequest = mojo::InterfaceRequest<VideoCaptureHost>;
    using VideoCaptureHostAssociatedPtr = mojo::AssociatedInterfacePtr<VideoCaptureHost>;
    using ThreadSafeVideoCaptureHostAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VideoCaptureHost>;
    using VideoCaptureHostAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VideoCaptureHost>;
    using VideoCaptureHostAssociatedRequest = mojo::AssociatedInterfaceRequest<VideoCaptureHost>;

    class VideoCaptureObserverProxy;

    template <typename ImplRefTraits>
    class VideoCaptureObserverStub;

    class VideoCaptureObserverRequestValidator;

    class CONTENT_EXPORT VideoCaptureObserver
        : public VideoCaptureObserverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = VideoCaptureObserverProxy;

        template <typename ImplRefTraits>
        using Stub_ = VideoCaptureObserverStub<ImplRefTraits>;

        using RequestValidator_ = VideoCaptureObserverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnStateChangedMinVersion = 0,
            kOnBufferCreatedMinVersion = 0,
            kOnBufferReadyMinVersion = 0,
            kOnBufferDestroyedMinVersion = 0,
        };
        virtual ~VideoCaptureObserver() { }

        virtual void OnStateChanged(VideoCaptureState state) = 0;

        virtual void OnBufferCreated(int32_t buffer_id, mojo::ScopedSharedBufferHandle handle_fd) = 0;

        virtual void OnBufferReady(int32_t buffer_id, ::media::mojom::VideoFrameInfoPtr info) = 0;

        virtual void OnBufferDestroyed(int32_t buffer_id) = 0;
    };

    class VideoCaptureHostProxy;

    template <typename ImplRefTraits>
    class VideoCaptureHostStub;

    class VideoCaptureHostRequestValidator;
    class VideoCaptureHostResponseValidator;

    class CONTENT_EXPORT VideoCaptureHost
        : public VideoCaptureHostInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = VideoCaptureHostProxy;

        template <typename ImplRefTraits>
        using Stub_ = VideoCaptureHostStub<ImplRefTraits>;

        using RequestValidator_ = VideoCaptureHostRequestValidator;
        using ResponseValidator_ = VideoCaptureHostResponseValidator;
        enum MethodMinVersions : uint32_t {
            kStartMinVersion = 0,
            kStopMinVersion = 0,
            kPauseMinVersion = 0,
            kResumeMinVersion = 0,
            kRequestRefreshFrameMinVersion = 0,
            kReleaseBufferMinVersion = 0,
            kGetDeviceSupportedFormatsMinVersion = 0,
            kGetDeviceFormatsInUseMinVersion = 0,
        };
        virtual ~VideoCaptureHost() { }

        virtual void Start(int32_t device_id, int32_t session_id, const media::VideoCaptureParams& params, VideoCaptureObserverPtr observer) = 0;

        virtual void Stop(int32_t device_id) = 0;

        virtual void Pause(int32_t device_id) = 0;

        virtual void Resume(int32_t device_id, int32_t session_id, const media::VideoCaptureParams& params) = 0;

        virtual void RequestRefreshFrame(int32_t device_id) = 0;

        virtual void ReleaseBuffer(int32_t device_id, int32_t buffer_id, double consumer_resource_utilization) = 0;

        using GetDeviceSupportedFormatsCallback = base::Callback<void(const std::vector<media::VideoCaptureFormat>&)>;
        virtual void GetDeviceSupportedFormats(int32_t device_id, int32_t session_id, const GetDeviceSupportedFormatsCallback& callback) = 0;

        using GetDeviceFormatsInUseCallback = base::Callback<void(const std::vector<media::VideoCaptureFormat>&)>;
        virtual void GetDeviceFormatsInUse(int32_t device_id, int32_t session_id, const GetDeviceFormatsInUseCallback& callback) = 0;
    };

    class CONTENT_EXPORT VideoCaptureObserverProxy
        : public VideoCaptureObserver {
    public:
        explicit VideoCaptureObserverProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnStateChanged(VideoCaptureState state) override;
        void OnBufferCreated(int32_t buffer_id, mojo::ScopedSharedBufferHandle handle_fd) override;
        void OnBufferReady(int32_t buffer_id, ::media::mojom::VideoFrameInfoPtr info) override;
        void OnBufferDestroyed(int32_t buffer_id) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT VideoCaptureHostProxy
        : public VideoCaptureHost {
    public:
        explicit VideoCaptureHostProxy(mojo::MessageReceiverWithResponder* receiver);
        void Start(int32_t device_id, int32_t session_id, const media::VideoCaptureParams& params, VideoCaptureObserverPtr observer) override;
        void Stop(int32_t device_id) override;
        void Pause(int32_t device_id) override;
        void Resume(int32_t device_id, int32_t session_id, const media::VideoCaptureParams& params) override;
        void RequestRefreshFrame(int32_t device_id) override;
        void ReleaseBuffer(int32_t device_id, int32_t buffer_id, double consumer_resource_utilization) override;
        void GetDeviceSupportedFormats(int32_t device_id, int32_t session_id, const GetDeviceSupportedFormatsCallback& callback) override;
        void GetDeviceFormatsInUse(int32_t device_id, int32_t session_id, const GetDeviceFormatsInUseCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT VideoCaptureObserverStubDispatch {
    public:
        static bool Accept(VideoCaptureObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(VideoCaptureObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VideoCaptureObserver>>
    class VideoCaptureObserverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        VideoCaptureObserverStub() { }
        ~VideoCaptureObserverStub() override { }

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
            return VideoCaptureObserverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return VideoCaptureObserverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT VideoCaptureHostStubDispatch {
    public:
        static bool Accept(VideoCaptureHost* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(VideoCaptureHost* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VideoCaptureHost>>
    class VideoCaptureHostStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        VideoCaptureHostStub() { }
        ~VideoCaptureHostStub() override { }

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
            return VideoCaptureHostStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return VideoCaptureHostStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT VideoCaptureObserverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT VideoCaptureHostRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT VideoCaptureHostResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace content

namespace mojo {

} // namespace mojo

#endif // CONTENT_COMMON_VIDEO_CAPTURE_MOJOM_H_