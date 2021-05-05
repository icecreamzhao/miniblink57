// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDER_MESSAGE_FILTER_MOJOM_H_
#define CONTENT_COMMON_RENDER_MESSAGE_FILTER_MOJOM_H_

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
#include "content/common/native_types.mojom.h"
#include "content/common/render_message_filter.mojom-shared.h"
#include "content/common/resize_params.h"
#include "content/common/resource_request.h"
#include "content/common/resource_request_completion_status.h"
#include "content/common/service_worker/embedded_worker_start_params.h"
#include "content/common/service_worker/service_worker_status_code.h"
#include "content/common/service_worker/service_worker_types.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/push_event_payload.h"
#include "content/public/common/referrer.h"
#include "content/public/common/renderer_preferences.h"
#include "content/public/common/resource_response.h"
#include "content/public/common/web_preferences.h"
#include "content/public/common/window_container_type.mojom.h"
#include "device/bluetooth/bluetooth_uuid.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/mailbox.mojom.h"
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
#include "third_party/WebKit/public/platform/referrer.mojom.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebPopupType.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "third_party/WebKit/public/web/window_features.mojom.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/base/mojo/window_open_disposition.mojom.h"
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
#include "url/mojo/url.mojom.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace content {
namespace mojom {
    class RenderMessageFilter;
    using RenderMessageFilterPtr = mojo::InterfacePtr<RenderMessageFilter>;
    using RenderMessageFilterPtrInfo = mojo::InterfacePtrInfo<RenderMessageFilter>;
    using ThreadSafeRenderMessageFilterPtr = mojo::ThreadSafeInterfacePtr<RenderMessageFilter>;
    using RenderMessageFilterRequest = mojo::InterfaceRequest<RenderMessageFilter>;
    using RenderMessageFilterAssociatedPtr = mojo::AssociatedInterfacePtr<RenderMessageFilter>;
    using ThreadSafeRenderMessageFilterAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<RenderMessageFilter>;
    using RenderMessageFilterAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<RenderMessageFilter>;
    using RenderMessageFilterAssociatedRequest = mojo::AssociatedInterfaceRequest<RenderMessageFilter>;

    class CreateNewWindowParams;
    using CreateNewWindowParamsPtr = mojo::StructPtr<CreateNewWindowParams>;

    class CreateNewWindowReply;
    using CreateNewWindowReplyPtr = mojo::InlinedStructPtr<CreateNewWindowReply>;

    class RenderMessageFilterProxy;

    template <typename ImplRefTraits>
    class RenderMessageFilterStub;

    class RenderMessageFilterRequestValidator;
    class RenderMessageFilterResponseValidator;

    class CONTENT_EXPORT RenderMessageFilter
        : public RenderMessageFilterInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = RenderMessageFilterProxy;

        template <typename ImplRefTraits>
        using Stub_ = RenderMessageFilterStub<ImplRefTraits>;

        using RequestValidator_ = RenderMessageFilterRequestValidator;
        using ResponseValidator_ = RenderMessageFilterResponseValidator;
        enum MethodMinVersions : uint32_t {
            kGenerateRoutingIDMinVersion = 0,
            kCreateNewWindowMinVersion = 0,
            kCreateNewWidgetMinVersion = 0,
            kCreateFullscreenWidgetMinVersion = 0,
            kAllocatedSharedBitmapMinVersion = 0,
            kDeletedSharedBitmapMinVersion = 0,
        };
        virtual ~RenderMessageFilter() { }

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool GenerateRoutingID(int32_t* routing_id);

        using GenerateRoutingIDCallback = base::Callback<void(int32_t)>;
        virtual void GenerateRoutingID(const GenerateRoutingIDCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool CreateNewWindow(CreateNewWindowParamsPtr params, CreateNewWindowReplyPtr* reply);

        using CreateNewWindowCallback = base::Callback<void(CreateNewWindowReplyPtr)>;
        virtual void CreateNewWindow(CreateNewWindowParamsPtr params, const CreateNewWindowCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool CreateNewWidget(int32_t opener_id, blink::WebPopupType popup_type, int32_t* route_id);

        using CreateNewWidgetCallback = base::Callback<void(int32_t)>;
        virtual void CreateNewWidget(int32_t opener_id, blink::WebPopupType popup_type, const CreateNewWidgetCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool CreateFullscreenWidget(int32_t opener_id, int32_t* route_id);

        using CreateFullscreenWidgetCallback = base::Callback<void(int32_t)>;
        virtual void CreateFullscreenWidget(int32_t opener_id, const CreateFullscreenWidgetCallback& callback) = 0;

        virtual void AllocatedSharedBitmap(mojo::ScopedSharedBufferHandle buffer, const gpu::Mailbox& id) = 0;

        virtual void DeletedSharedBitmap(const gpu::Mailbox& id) = 0;
    };

    class CONTENT_EXPORT RenderMessageFilterProxy
        : public RenderMessageFilter {
    public:
        explicit RenderMessageFilterProxy(mojo::MessageReceiverWithResponder* receiver);
        bool GenerateRoutingID(int32_t* routing_id) override;
        void GenerateRoutingID(const GenerateRoutingIDCallback& callback) override;
        bool CreateNewWindow(CreateNewWindowParamsPtr params, CreateNewWindowReplyPtr* reply) override;
        void CreateNewWindow(CreateNewWindowParamsPtr params, const CreateNewWindowCallback& callback) override;
        bool CreateNewWidget(int32_t opener_id, blink::WebPopupType popup_type, int32_t* route_id) override;
        void CreateNewWidget(int32_t opener_id, blink::WebPopupType popup_type, const CreateNewWidgetCallback& callback) override;
        bool CreateFullscreenWidget(int32_t opener_id, int32_t* route_id) override;
        void CreateFullscreenWidget(int32_t opener_id, const CreateFullscreenWidgetCallback& callback) override;
        void AllocatedSharedBitmap(mojo::ScopedSharedBufferHandle buffer, const gpu::Mailbox& id) override;
        void DeletedSharedBitmap(const gpu::Mailbox& id) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT RenderMessageFilterStubDispatch {
    public:
        static bool Accept(RenderMessageFilter* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(RenderMessageFilter* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<RenderMessageFilter>>
    class RenderMessageFilterStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        RenderMessageFilterStub() { }
        ~RenderMessageFilterStub() override { }

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
            return RenderMessageFilterStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RenderMessageFilterStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT RenderMessageFilterRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT RenderMessageFilterResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CONTENT_EXPORT CreateNewWindowReply {
    public:
        using DataView = CreateNewWindowReplyDataView;
        using Data_ = internal::CreateNewWindowReply_Data;

        static CreateNewWindowReplyPtr New();

        template <typename U>
        static CreateNewWindowReplyPtr From(const U& u)
        {
            return mojo::TypeConverter<CreateNewWindowReplyPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CreateNewWindowReply>::Convert(*this);
        }

        CreateNewWindowReply();
        ~CreateNewWindowReply();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CreateNewWindowReplyPtr>
        CreateNewWindowReplyPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CreateNewWindowReply>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CreateNewWindowReply::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CreateNewWindowReply::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t route_id;
        int32_t main_frame_route_id;
        int32_t main_frame_widget_route_id;
        int64_t cloned_session_storage_namespace_id;
    };

    class CONTENT_EXPORT CreateNewWindowParams {
    public:
        using DataView = CreateNewWindowParamsDataView;
        using Data_ = internal::CreateNewWindowParams_Data;

        static CreateNewWindowParamsPtr New();

        template <typename U>
        static CreateNewWindowParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<CreateNewWindowParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CreateNewWindowParams>::Convert(*this);
        }

        CreateNewWindowParams();
        ~CreateNewWindowParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CreateNewWindowParamsPtr>
        CreateNewWindowParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CreateNewWindowParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CreateNewWindowParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CreateNewWindowParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t opener_render_frame_id;
        bool user_gesture;
        ::content::mojom::WindowContainerType window_container_type;
        int64_t session_storage_namespace_id;
        std::string frame_name;
        GURL opener_url;
        GURL opener_top_level_frame_url;
        GURL opener_security_origin;
        bool opener_suppressed;
        WindowOpenDisposition disposition;
        GURL target_url;
        content::Referrer referrer;
        ::blink::WebWindowFeatures features;
    };

    template <typename StructPtrType>
    CreateNewWindowParamsPtr CreateNewWindowParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->opener_render_frame_id = mojo::internal::Clone(opener_render_frame_id);
        rv->user_gesture = mojo::internal::Clone(user_gesture);
        rv->window_container_type = mojo::internal::Clone(window_container_type);
        rv->session_storage_namespace_id = mojo::internal::Clone(session_storage_namespace_id);
        rv->frame_name = mojo::internal::Clone(frame_name);
        rv->opener_url = mojo::internal::Clone(opener_url);
        rv->opener_top_level_frame_url = mojo::internal::Clone(opener_top_level_frame_url);
        rv->opener_security_origin = mojo::internal::Clone(opener_security_origin);
        rv->opener_suppressed = mojo::internal::Clone(opener_suppressed);
        rv->disposition = mojo::internal::Clone(disposition);
        rv->target_url = mojo::internal::Clone(target_url);
        rv->referrer = mojo::internal::Clone(referrer);
        rv->features = mojo::internal::Clone(features);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CreateNewWindowParams>::value>::type*>
    bool CreateNewWindowParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->opener_render_frame_id, other.opener_render_frame_id))
            return false;
        if (!mojo::internal::Equals(this->user_gesture, other.user_gesture))
            return false;
        if (!mojo::internal::Equals(this->window_container_type, other.window_container_type))
            return false;
        if (!mojo::internal::Equals(this->session_storage_namespace_id, other.session_storage_namespace_id))
            return false;
        if (!mojo::internal::Equals(this->frame_name, other.frame_name))
            return false;
        if (!mojo::internal::Equals(this->opener_url, other.opener_url))
            return false;
        if (!mojo::internal::Equals(this->opener_top_level_frame_url, other.opener_top_level_frame_url))
            return false;
        if (!mojo::internal::Equals(this->opener_security_origin, other.opener_security_origin))
            return false;
        if (!mojo::internal::Equals(this->opener_suppressed, other.opener_suppressed))
            return false;
        if (!mojo::internal::Equals(this->disposition, other.disposition))
            return false;
        if (!mojo::internal::Equals(this->target_url, other.target_url))
            return false;
        if (!mojo::internal::Equals(this->referrer, other.referrer))
            return false;
        if (!mojo::internal::Equals(this->features, other.features))
            return false;
        return true;
    }
    template <typename StructPtrType>
    CreateNewWindowReplyPtr CreateNewWindowReply::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->route_id = mojo::internal::Clone(route_id);
        rv->main_frame_route_id = mojo::internal::Clone(main_frame_route_id);
        rv->main_frame_widget_route_id = mojo::internal::Clone(main_frame_widget_route_id);
        rv->cloned_session_storage_namespace_id = mojo::internal::Clone(cloned_session_storage_namespace_id);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CreateNewWindowReply>::value>::type*>
    bool CreateNewWindowReply::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->route_id, other.route_id))
            return false;
        if (!mojo::internal::Equals(this->main_frame_route_id, other.main_frame_route_id))
            return false;
        if (!mojo::internal::Equals(this->main_frame_widget_route_id, other.main_frame_widget_route_id))
            return false;
        if (!mojo::internal::Equals(this->cloned_session_storage_namespace_id, other.cloned_session_storage_namespace_id))
            return false;
        return true;
    }

} // namespace mojom
} // namespace content

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::content::mojom::CreateNewWindowParams::DataView,
    ::content::mojom::CreateNewWindowParamsPtr> {
    static bool IsNull(const ::content::mojom::CreateNewWindowParamsPtr& input) { return !input; }
    static void SetToNull(::content::mojom::CreateNewWindowParamsPtr* output) { output->reset(); }

    static decltype(::content::mojom::CreateNewWindowParams::opener_render_frame_id) opener_render_frame_id(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->opener_render_frame_id;
    }

    static decltype(::content::mojom::CreateNewWindowParams::user_gesture) user_gesture(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->user_gesture;
    }

    static decltype(::content::mojom::CreateNewWindowParams::window_container_type) window_container_type(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->window_container_type;
    }

    static decltype(::content::mojom::CreateNewWindowParams::session_storage_namespace_id) session_storage_namespace_id(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->session_storage_namespace_id;
    }

    static const decltype(::content::mojom::CreateNewWindowParams::frame_name)& frame_name(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->frame_name;
    }

    static const decltype(::content::mojom::CreateNewWindowParams::opener_url)& opener_url(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->opener_url;
    }

    static const decltype(::content::mojom::CreateNewWindowParams::opener_top_level_frame_url)& opener_top_level_frame_url(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->opener_top_level_frame_url;
    }

    static const decltype(::content::mojom::CreateNewWindowParams::opener_security_origin)& opener_security_origin(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->opener_security_origin;
    }

    static decltype(::content::mojom::CreateNewWindowParams::opener_suppressed) opener_suppressed(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->opener_suppressed;
    }

    static decltype(::content::mojom::CreateNewWindowParams::disposition) disposition(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->disposition;
    }

    static const decltype(::content::mojom::CreateNewWindowParams::target_url)& target_url(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->target_url;
    }

    static const decltype(::content::mojom::CreateNewWindowParams::referrer)& referrer(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->referrer;
    }

    static const decltype(::content::mojom::CreateNewWindowParams::features)& features(
        const ::content::mojom::CreateNewWindowParamsPtr& input)
    {
        return input->features;
    }

    static bool Read(::content::mojom::CreateNewWindowParams::DataView input, ::content::mojom::CreateNewWindowParamsPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::content::mojom::CreateNewWindowReply::DataView,
    ::content::mojom::CreateNewWindowReplyPtr> {
    static bool IsNull(const ::content::mojom::CreateNewWindowReplyPtr& input) { return !input; }
    static void SetToNull(::content::mojom::CreateNewWindowReplyPtr* output) { output->reset(); }

    static decltype(::content::mojom::CreateNewWindowReply::route_id) route_id(
        const ::content::mojom::CreateNewWindowReplyPtr& input)
    {
        return input->route_id;
    }

    static decltype(::content::mojom::CreateNewWindowReply::main_frame_route_id) main_frame_route_id(
        const ::content::mojom::CreateNewWindowReplyPtr& input)
    {
        return input->main_frame_route_id;
    }

    static decltype(::content::mojom::CreateNewWindowReply::main_frame_widget_route_id) main_frame_widget_route_id(
        const ::content::mojom::CreateNewWindowReplyPtr& input)
    {
        return input->main_frame_widget_route_id;
    }

    static decltype(::content::mojom::CreateNewWindowReply::cloned_session_storage_namespace_id) cloned_session_storage_namespace_id(
        const ::content::mojom::CreateNewWindowReplyPtr& input)
    {
        return input->cloned_session_storage_namespace_id;
    }

    static bool Read(::content::mojom::CreateNewWindowReply::DataView input, ::content::mojom::CreateNewWindowReplyPtr* output);
};

} // namespace mojo

#endif // CONTENT_COMMON_RENDER_MESSAGE_FILTER_MOJOM_H_