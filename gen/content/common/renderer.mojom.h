// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDERER_MOJOM_H_
#define CONTENT_COMMON_RENDERER_MOJOM_H_

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
#include "content/common/renderer.mojom-shared.h"
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
#include "device/bluetooth/bluetooth_uuid.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
#include "ipc/ipc.mojom.h"
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
#include "ui/gfx/mojo/icc_profile.mojom.h"
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
    class Renderer;
    using RendererPtr = mojo::InterfacePtr<Renderer>;
    using RendererPtrInfo = mojo::InterfacePtrInfo<Renderer>;
    using ThreadSafeRendererPtr = mojo::ThreadSafeInterfacePtr<Renderer>;
    using RendererRequest = mojo::InterfaceRequest<Renderer>;
    using RendererAssociatedPtr = mojo::AssociatedInterfacePtr<Renderer>;
    using ThreadSafeRendererAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Renderer>;
    using RendererAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Renderer>;
    using RendererAssociatedRequest = mojo::AssociatedInterfaceRequest<Renderer>;

    class CreateViewParams;
    using CreateViewParamsPtr = mojo::StructPtr<CreateViewParams>;

    class CreateFrameWidgetParams;
    using CreateFrameWidgetParamsPtr = mojo::InlinedStructPtr<CreateFrameWidgetParams>;

    class CreateFrameParams;
    using CreateFrameParamsPtr = mojo::StructPtr<CreateFrameParams>;

    class UpdateScrollbarThemeParams;
    using UpdateScrollbarThemeParamsPtr = mojo::StructPtr<UpdateScrollbarThemeParams>;

    class RendererProxy;

    template <typename ImplRefTraits>
    class RendererStub;

    class RendererRequestValidator;

    class CONTENT_EXPORT Renderer
        : public RendererInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = RendererProxy;

        template <typename ImplRefTraits>
        using Stub_ = RendererStub<ImplRefTraits>;

        using RequestValidator_ = RendererRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kCreateViewMinVersion = 0,
            kCreateFrameMinVersion = 0,
            kCreateFrameProxyMinVersion = 0,
            kOnNetworkConnectionChangedMinVersion = 0,
            kSetWebKitSharedTimersSuspendedMinVersion = 0,
            kUpdateScrollbarThemeMinVersion = 0,
            kOnSystemColorsChangedMinVersion = 0,
            kPurgePluginListCacheMinVersion = 0,
        };
        virtual ~Renderer() { }

        virtual void CreateView(CreateViewParamsPtr params) = 0;

        virtual void CreateFrame(CreateFrameParamsPtr params) = 0;

        virtual void CreateFrameProxy(int32_t routing_id, int32_t render_view_routing_id, int32_t opener_routing_id, int32_t parent_routing_id, const content::FrameReplicationState& replication_state) = 0;

        virtual void OnNetworkConnectionChanged(net::NetworkChangeNotifier::ConnectionType connection_type, double max_bandwidth_mbps) = 0;

        virtual void SetWebKitSharedTimersSuspended(bool suspend) = 0;

        virtual void UpdateScrollbarTheme(UpdateScrollbarThemeParamsPtr params) = 0;

        virtual void OnSystemColorsChanged(int32_t aqua_color_variant, const std::string& highlight_text_color, const std::string& highlight_color) = 0;

        virtual void PurgePluginListCache(bool reload_pages) = 0;
    };

    class CONTENT_EXPORT RendererProxy
        : public Renderer {
    public:
        explicit RendererProxy(mojo::MessageReceiverWithResponder* receiver);
        void CreateView(CreateViewParamsPtr params) override;
        void CreateFrame(CreateFrameParamsPtr params) override;
        void CreateFrameProxy(int32_t routing_id, int32_t render_view_routing_id, int32_t opener_routing_id, int32_t parent_routing_id, const content::FrameReplicationState& replication_state) override;
        void OnNetworkConnectionChanged(net::NetworkChangeNotifier::ConnectionType connection_type, double max_bandwidth_mbps) override;
        void SetWebKitSharedTimersSuspended(bool suspend) override;
        void UpdateScrollbarTheme(UpdateScrollbarThemeParamsPtr params) override;
        void OnSystemColorsChanged(int32_t aqua_color_variant, const std::string& highlight_text_color, const std::string& highlight_color) override;
        void PurgePluginListCache(bool reload_pages) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT RendererStubDispatch {
    public:
        static bool Accept(Renderer* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Renderer* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Renderer>>
    class RendererStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        RendererStub() { }
        ~RendererStub() override { }

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
            return RendererStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RendererStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT RendererRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CONTENT_EXPORT CreateFrameWidgetParams {
    public:
        using DataView = CreateFrameWidgetParamsDataView;
        using Data_ = internal::CreateFrameWidgetParams_Data;

        static CreateFrameWidgetParamsPtr New();

        template <typename U>
        static CreateFrameWidgetParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<CreateFrameWidgetParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CreateFrameWidgetParams>::Convert(*this);
        }

        CreateFrameWidgetParams();
        ~CreateFrameWidgetParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CreateFrameWidgetParamsPtr>
        CreateFrameWidgetParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CreateFrameWidgetParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CreateFrameWidgetParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CreateFrameWidgetParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t routing_id;
        bool hidden;
    };

    class CONTENT_EXPORT CreateViewParams {
    public:
        using DataView = CreateViewParamsDataView;
        using Data_ = internal::CreateViewParams_Data;

        static CreateViewParamsPtr New();

        template <typename U>
        static CreateViewParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<CreateViewParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CreateViewParams>::Convert(*this);
        }

        CreateViewParams();
        ~CreateViewParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CreateViewParamsPtr>
        CreateViewParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CreateViewParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CreateViewParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CreateViewParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        content::RendererPreferences renderer_preferences;
        content::WebPreferences web_preferences;
        int32_t view_id;
        int32_t main_frame_routing_id;
        int32_t main_frame_widget_routing_id;
        int64_t session_storage_namespace_id;
        int32_t opener_frame_route_id;
        bool swapped_out;
        content::FrameReplicationState replicated_frame_state;
        int32_t proxy_routing_id;
        bool hidden;
        bool never_visible;
        bool window_was_created_with_opener;
        content::ResizeParams initial_size;
        bool enable_auto_resize;
        gfx::Size min_size;
        gfx::Size max_size;
        double page_zoom_level;
        gfx::ICCProfile image_decode_color_space;
    };

    class CONTENT_EXPORT CreateFrameParams {
    public:
        using DataView = CreateFrameParamsDataView;
        using Data_ = internal::CreateFrameParams_Data;

        static CreateFrameParamsPtr New();

        template <typename U>
        static CreateFrameParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<CreateFrameParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CreateFrameParams>::Convert(*this);
        }

        CreateFrameParams();
        ~CreateFrameParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CreateFrameParamsPtr>
        CreateFrameParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CreateFrameParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CreateFrameParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CreateFrameParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t routing_id;
        int32_t proxy_routing_id;
        int32_t opener_routing_id;
        int32_t parent_routing_id;
        int32_t previous_sibling_routing_id;
        content::FrameReplicationState replication_state;
        content::FrameOwnerProperties frame_owner_properties;
        CreateFrameWidgetParamsPtr widget_params;

    private:
        DISALLOW_COPY_AND_ASSIGN(CreateFrameParams);
    };

    class CONTENT_EXPORT UpdateScrollbarThemeParams {
    public:
        using DataView = UpdateScrollbarThemeParamsDataView;
        using Data_ = internal::UpdateScrollbarThemeParams_Data;

        static UpdateScrollbarThemeParamsPtr New();

        template <typename U>
        static UpdateScrollbarThemeParamsPtr From(const U& u)
        {
            return mojo::TypeConverter<UpdateScrollbarThemeParamsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, UpdateScrollbarThemeParams>::Convert(*this);
        }

        UpdateScrollbarThemeParams();
        ~UpdateScrollbarThemeParams();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = UpdateScrollbarThemeParamsPtr>
        UpdateScrollbarThemeParamsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, UpdateScrollbarThemeParams>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                UpdateScrollbarThemeParams::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                UpdateScrollbarThemeParams::DataView, std::vector<uint8_t>>(
                input, output);
        }

        float initial_button_delay;
        float autoscroll_button_delay;
        bool jump_on_track_click;
        ::content::mojom::ScrollerStyle preferred_scroller_style;
        bool redraw;
        ::content::mojom::ScrollbarButtonsPlacement button_placement;
    };

    template <typename StructPtrType>
    CreateViewParamsPtr CreateViewParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->renderer_preferences = mojo::internal::Clone(renderer_preferences);
        rv->web_preferences = mojo::internal::Clone(web_preferences);
        rv->view_id = mojo::internal::Clone(view_id);
        rv->main_frame_routing_id = mojo::internal::Clone(main_frame_routing_id);
        rv->main_frame_widget_routing_id = mojo::internal::Clone(main_frame_widget_routing_id);
        rv->session_storage_namespace_id = mojo::internal::Clone(session_storage_namespace_id);
        rv->opener_frame_route_id = mojo::internal::Clone(opener_frame_route_id);
        rv->swapped_out = mojo::internal::Clone(swapped_out);
        rv->replicated_frame_state = mojo::internal::Clone(replicated_frame_state);
        rv->proxy_routing_id = mojo::internal::Clone(proxy_routing_id);
        rv->hidden = mojo::internal::Clone(hidden);
        rv->never_visible = mojo::internal::Clone(never_visible);
        rv->window_was_created_with_opener = mojo::internal::Clone(window_was_created_with_opener);
        rv->initial_size = mojo::internal::Clone(initial_size);
        rv->enable_auto_resize = mojo::internal::Clone(enable_auto_resize);
        rv->min_size = mojo::internal::Clone(min_size);
        rv->max_size = mojo::internal::Clone(max_size);
        rv->page_zoom_level = mojo::internal::Clone(page_zoom_level);
        rv->image_decode_color_space = mojo::internal::Clone(image_decode_color_space);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CreateViewParams>::value>::type*>
    bool CreateViewParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->renderer_preferences, other.renderer_preferences))
            return false;
        if (!mojo::internal::Equals(this->web_preferences, other.web_preferences))
            return false;
        if (!mojo::internal::Equals(this->view_id, other.view_id))
            return false;
        if (!mojo::internal::Equals(this->main_frame_routing_id, other.main_frame_routing_id))
            return false;
        if (!mojo::internal::Equals(this->main_frame_widget_routing_id, other.main_frame_widget_routing_id))
            return false;
        if (!mojo::internal::Equals(this->session_storage_namespace_id, other.session_storage_namespace_id))
            return false;
        if (!mojo::internal::Equals(this->opener_frame_route_id, other.opener_frame_route_id))
            return false;
        if (!mojo::internal::Equals(this->swapped_out, other.swapped_out))
            return false;
        if (!mojo::internal::Equals(this->replicated_frame_state, other.replicated_frame_state))
            return false;
        if (!mojo::internal::Equals(this->proxy_routing_id, other.proxy_routing_id))
            return false;
        if (!mojo::internal::Equals(this->hidden, other.hidden))
            return false;
        if (!mojo::internal::Equals(this->never_visible, other.never_visible))
            return false;
        if (!mojo::internal::Equals(this->window_was_created_with_opener, other.window_was_created_with_opener))
            return false;
        if (!mojo::internal::Equals(this->initial_size, other.initial_size))
            return false;
        if (!mojo::internal::Equals(this->enable_auto_resize, other.enable_auto_resize))
            return false;
        if (!mojo::internal::Equals(this->min_size, other.min_size))
            return false;
        if (!mojo::internal::Equals(this->max_size, other.max_size))
            return false;
        if (!mojo::internal::Equals(this->page_zoom_level, other.page_zoom_level))
            return false;
        if (!mojo::internal::Equals(this->image_decode_color_space, other.image_decode_color_space))
            return false;
        return true;
    }
    template <typename StructPtrType>
    CreateFrameWidgetParamsPtr CreateFrameWidgetParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->routing_id = mojo::internal::Clone(routing_id);
        rv->hidden = mojo::internal::Clone(hidden);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CreateFrameWidgetParams>::value>::type*>
    bool CreateFrameWidgetParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->routing_id, other.routing_id))
            return false;
        if (!mojo::internal::Equals(this->hidden, other.hidden))
            return false;
        return true;
    }
    template <typename StructPtrType>
    CreateFrameParamsPtr CreateFrameParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->routing_id = mojo::internal::Clone(routing_id);
        rv->proxy_routing_id = mojo::internal::Clone(proxy_routing_id);
        rv->opener_routing_id = mojo::internal::Clone(opener_routing_id);
        rv->parent_routing_id = mojo::internal::Clone(parent_routing_id);
        rv->previous_sibling_routing_id = mojo::internal::Clone(previous_sibling_routing_id);
        rv->replication_state = mojo::internal::Clone(replication_state);
        rv->frame_owner_properties = mojo::internal::Clone(frame_owner_properties);
        rv->widget_params = mojo::internal::Clone(widget_params);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CreateFrameParams>::value>::type*>
    bool CreateFrameParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->routing_id, other.routing_id))
            return false;
        if (!mojo::internal::Equals(this->proxy_routing_id, other.proxy_routing_id))
            return false;
        if (!mojo::internal::Equals(this->opener_routing_id, other.opener_routing_id))
            return false;
        if (!mojo::internal::Equals(this->parent_routing_id, other.parent_routing_id))
            return false;
        if (!mojo::internal::Equals(this->previous_sibling_routing_id, other.previous_sibling_routing_id))
            return false;
        if (!mojo::internal::Equals(this->replication_state, other.replication_state))
            return false;
        if (!mojo::internal::Equals(this->frame_owner_properties, other.frame_owner_properties))
            return false;
        if (!mojo::internal::Equals(this->widget_params, other.widget_params))
            return false;
        return true;
    }
    template <typename StructPtrType>
    UpdateScrollbarThemeParamsPtr UpdateScrollbarThemeParams::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->initial_button_delay = mojo::internal::Clone(initial_button_delay);
        rv->autoscroll_button_delay = mojo::internal::Clone(autoscroll_button_delay);
        rv->jump_on_track_click = mojo::internal::Clone(jump_on_track_click);
        rv->preferred_scroller_style = mojo::internal::Clone(preferred_scroller_style);
        rv->redraw = mojo::internal::Clone(redraw);
        rv->button_placement = mojo::internal::Clone(button_placement);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, UpdateScrollbarThemeParams>::value>::type*>
    bool UpdateScrollbarThemeParams::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->initial_button_delay, other.initial_button_delay))
            return false;
        if (!mojo::internal::Equals(this->autoscroll_button_delay, other.autoscroll_button_delay))
            return false;
        if (!mojo::internal::Equals(this->jump_on_track_click, other.jump_on_track_click))
            return false;
        if (!mojo::internal::Equals(this->preferred_scroller_style, other.preferred_scroller_style))
            return false;
        if (!mojo::internal::Equals(this->redraw, other.redraw))
            return false;
        if (!mojo::internal::Equals(this->button_placement, other.button_placement))
            return false;
        return true;
    }

} // namespace mojom
} // namespace content

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::content::mojom::CreateViewParams::DataView,
    ::content::mojom::CreateViewParamsPtr> {
    static bool IsNull(const ::content::mojom::CreateViewParamsPtr& input) { return !input; }
    static void SetToNull(::content::mojom::CreateViewParamsPtr* output) { output->reset(); }

    static const decltype(::content::mojom::CreateViewParams::renderer_preferences)& renderer_preferences(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->renderer_preferences;
    }

    static const decltype(::content::mojom::CreateViewParams::web_preferences)& web_preferences(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->web_preferences;
    }

    static decltype(::content::mojom::CreateViewParams::view_id) view_id(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->view_id;
    }

    static decltype(::content::mojom::CreateViewParams::main_frame_routing_id) main_frame_routing_id(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->main_frame_routing_id;
    }

    static decltype(::content::mojom::CreateViewParams::main_frame_widget_routing_id) main_frame_widget_routing_id(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->main_frame_widget_routing_id;
    }

    static decltype(::content::mojom::CreateViewParams::session_storage_namespace_id) session_storage_namespace_id(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->session_storage_namespace_id;
    }

    static decltype(::content::mojom::CreateViewParams::opener_frame_route_id) opener_frame_route_id(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->opener_frame_route_id;
    }

    static decltype(::content::mojom::CreateViewParams::swapped_out) swapped_out(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->swapped_out;
    }

    static const decltype(::content::mojom::CreateViewParams::replicated_frame_state)& replicated_frame_state(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->replicated_frame_state;
    }

    static decltype(::content::mojom::CreateViewParams::proxy_routing_id) proxy_routing_id(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->proxy_routing_id;
    }

    static decltype(::content::mojom::CreateViewParams::hidden) hidden(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->hidden;
    }

    static decltype(::content::mojom::CreateViewParams::never_visible) never_visible(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->never_visible;
    }

    static decltype(::content::mojom::CreateViewParams::window_was_created_with_opener) window_was_created_with_opener(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->window_was_created_with_opener;
    }

    static const decltype(::content::mojom::CreateViewParams::initial_size)& initial_size(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->initial_size;
    }

    static decltype(::content::mojom::CreateViewParams::enable_auto_resize) enable_auto_resize(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->enable_auto_resize;
    }

    static const decltype(::content::mojom::CreateViewParams::min_size)& min_size(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->min_size;
    }

    static const decltype(::content::mojom::CreateViewParams::max_size)& max_size(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->max_size;
    }

    static decltype(::content::mojom::CreateViewParams::page_zoom_level) page_zoom_level(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->page_zoom_level;
    }

    static const decltype(::content::mojom::CreateViewParams::image_decode_color_space)& image_decode_color_space(
        const ::content::mojom::CreateViewParamsPtr& input)
    {
        return input->image_decode_color_space;
    }

    static bool Read(::content::mojom::CreateViewParams::DataView input, ::content::mojom::CreateViewParamsPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::content::mojom::CreateFrameWidgetParams::DataView,
    ::content::mojom::CreateFrameWidgetParamsPtr> {
    static bool IsNull(const ::content::mojom::CreateFrameWidgetParamsPtr& input) { return !input; }
    static void SetToNull(::content::mojom::CreateFrameWidgetParamsPtr* output) { output->reset(); }

    static decltype(::content::mojom::CreateFrameWidgetParams::routing_id) routing_id(
        const ::content::mojom::CreateFrameWidgetParamsPtr& input)
    {
        return input->routing_id;
    }

    static decltype(::content::mojom::CreateFrameWidgetParams::hidden) hidden(
        const ::content::mojom::CreateFrameWidgetParamsPtr& input)
    {
        return input->hidden;
    }

    static bool Read(::content::mojom::CreateFrameWidgetParams::DataView input, ::content::mojom::CreateFrameWidgetParamsPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::content::mojom::CreateFrameParams::DataView,
    ::content::mojom::CreateFrameParamsPtr> {
    static bool IsNull(const ::content::mojom::CreateFrameParamsPtr& input) { return !input; }
    static void SetToNull(::content::mojom::CreateFrameParamsPtr* output) { output->reset(); }

    static decltype(::content::mojom::CreateFrameParams::routing_id) routing_id(
        const ::content::mojom::CreateFrameParamsPtr& input)
    {
        return input->routing_id;
    }

    static decltype(::content::mojom::CreateFrameParams::proxy_routing_id) proxy_routing_id(
        const ::content::mojom::CreateFrameParamsPtr& input)
    {
        return input->proxy_routing_id;
    }

    static decltype(::content::mojom::CreateFrameParams::opener_routing_id) opener_routing_id(
        const ::content::mojom::CreateFrameParamsPtr& input)
    {
        return input->opener_routing_id;
    }

    static decltype(::content::mojom::CreateFrameParams::parent_routing_id) parent_routing_id(
        const ::content::mojom::CreateFrameParamsPtr& input)
    {
        return input->parent_routing_id;
    }

    static decltype(::content::mojom::CreateFrameParams::previous_sibling_routing_id) previous_sibling_routing_id(
        const ::content::mojom::CreateFrameParamsPtr& input)
    {
        return input->previous_sibling_routing_id;
    }

    static const decltype(::content::mojom::CreateFrameParams::replication_state)& replication_state(
        const ::content::mojom::CreateFrameParamsPtr& input)
    {
        return input->replication_state;
    }

    static const decltype(::content::mojom::CreateFrameParams::frame_owner_properties)& frame_owner_properties(
        const ::content::mojom::CreateFrameParamsPtr& input)
    {
        return input->frame_owner_properties;
    }

    static const decltype(::content::mojom::CreateFrameParams::widget_params)& widget_params(
        const ::content::mojom::CreateFrameParamsPtr& input)
    {
        return input->widget_params;
    }

    static bool Read(::content::mojom::CreateFrameParams::DataView input, ::content::mojom::CreateFrameParamsPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::content::mojom::UpdateScrollbarThemeParams::DataView,
    ::content::mojom::UpdateScrollbarThemeParamsPtr> {
    static bool IsNull(const ::content::mojom::UpdateScrollbarThemeParamsPtr& input) { return !input; }
    static void SetToNull(::content::mojom::UpdateScrollbarThemeParamsPtr* output) { output->reset(); }

    static decltype(::content::mojom::UpdateScrollbarThemeParams::initial_button_delay) initial_button_delay(
        const ::content::mojom::UpdateScrollbarThemeParamsPtr& input)
    {
        return input->initial_button_delay;
    }

    static decltype(::content::mojom::UpdateScrollbarThemeParams::autoscroll_button_delay) autoscroll_button_delay(
        const ::content::mojom::UpdateScrollbarThemeParamsPtr& input)
    {
        return input->autoscroll_button_delay;
    }

    static decltype(::content::mojom::UpdateScrollbarThemeParams::jump_on_track_click) jump_on_track_click(
        const ::content::mojom::UpdateScrollbarThemeParamsPtr& input)
    {
        return input->jump_on_track_click;
    }

    static decltype(::content::mojom::UpdateScrollbarThemeParams::preferred_scroller_style) preferred_scroller_style(
        const ::content::mojom::UpdateScrollbarThemeParamsPtr& input)
    {
        return input->preferred_scroller_style;
    }

    static decltype(::content::mojom::UpdateScrollbarThemeParams::redraw) redraw(
        const ::content::mojom::UpdateScrollbarThemeParamsPtr& input)
    {
        return input->redraw;
    }

    static decltype(::content::mojom::UpdateScrollbarThemeParams::button_placement) button_placement(
        const ::content::mojom::UpdateScrollbarThemeParamsPtr& input)
    {
        return input->button_placement;
    }

    static bool Read(::content::mojom::UpdateScrollbarThemeParams::DataView input, ::content::mojom::UpdateScrollbarThemeParamsPtr* output);
};

} // namespace mojo

#endif // CONTENT_COMMON_RENDERER_MOJOM_H_