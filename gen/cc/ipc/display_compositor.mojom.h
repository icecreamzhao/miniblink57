// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_DISPLAY_COMPOSITOR_MOJOM_H_
#define CC_IPC_DISPLAY_COMPOSITOR_MOJOM_H_

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
#include "cc/ipc/display_compositor.mojom-shared.h"
#include "cc/ipc/frame_sink_id.mojom.h"
#include "cc/ipc/mojo_compositor_frame_sink.mojom.h"
#include "cc/ipc/surface_id.mojom.h"
#include "cc/ipc/surface_info.mojom.h"
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
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
#include "gpu/ipc/common/surface_handle.mojom.h"
#include "mojo/common/time.mojom.h"
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
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
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
#include "ui/gfx/mojo/color_space.mojom.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace cc {
namespace mojom {
    class DisplayPrivate;
    using DisplayPrivatePtr = mojo::InterfacePtr<DisplayPrivate>;
    using DisplayPrivatePtrInfo = mojo::InterfacePtrInfo<DisplayPrivate>;
    using ThreadSafeDisplayPrivatePtr = mojo::ThreadSafeInterfacePtr<DisplayPrivate>;
    using DisplayPrivateRequest = mojo::InterfaceRequest<DisplayPrivate>;
    using DisplayPrivateAssociatedPtr = mojo::AssociatedInterfacePtr<DisplayPrivate>;
    using ThreadSafeDisplayPrivateAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DisplayPrivate>;
    using DisplayPrivateAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DisplayPrivate>;
    using DisplayPrivateAssociatedRequest = mojo::AssociatedInterfaceRequest<DisplayPrivate>;

    class DisplayCompositor;
    using DisplayCompositorPtr = mojo::InterfacePtr<DisplayCompositor>;
    using DisplayCompositorPtrInfo = mojo::InterfacePtrInfo<DisplayCompositor>;
    using ThreadSafeDisplayCompositorPtr = mojo::ThreadSafeInterfacePtr<DisplayCompositor>;
    using DisplayCompositorRequest = mojo::InterfaceRequest<DisplayCompositor>;
    using DisplayCompositorAssociatedPtr = mojo::AssociatedInterfacePtr<DisplayCompositor>;
    using ThreadSafeDisplayCompositorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DisplayCompositor>;
    using DisplayCompositorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DisplayCompositor>;
    using DisplayCompositorAssociatedRequest = mojo::AssociatedInterfaceRequest<DisplayCompositor>;

    class DisplayCompositorClient;
    using DisplayCompositorClientPtr = mojo::InterfacePtr<DisplayCompositorClient>;
    using DisplayCompositorClientPtrInfo = mojo::InterfacePtrInfo<DisplayCompositorClient>;
    using ThreadSafeDisplayCompositorClientPtr = mojo::ThreadSafeInterfacePtr<DisplayCompositorClient>;
    using DisplayCompositorClientRequest = mojo::InterfaceRequest<DisplayCompositorClient>;
    using DisplayCompositorClientAssociatedPtr = mojo::AssociatedInterfacePtr<DisplayCompositorClient>;
    using ThreadSafeDisplayCompositorClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DisplayCompositorClient>;
    using DisplayCompositorClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DisplayCompositorClient>;
    using DisplayCompositorClientAssociatedRequest = mojo::AssociatedInterfaceRequest<DisplayCompositorClient>;

    class DisplayPrivateProxy;

    template <typename ImplRefTraits>
    class DisplayPrivateStub;

    class DisplayPrivateRequestValidator;

    class DisplayPrivate
        : public DisplayPrivateInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DisplayPrivateProxy;

        template <typename ImplRefTraits>
        using Stub_ = DisplayPrivateStub<ImplRefTraits>;

        using RequestValidator_ = DisplayPrivateRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kSetDisplayVisibleMinVersion = 0,
            kResizeDisplayMinVersion = 0,
            kSetDisplayColorSpaceMinVersion = 0,
            kSetOutputIsSecureMinVersion = 0,
        };
        virtual ~DisplayPrivate() { }

        virtual void SetDisplayVisible(bool visible) = 0;

        virtual void ResizeDisplay(const gfx::Size& size_in_pixel) = 0;

        virtual void SetDisplayColorSpace(const gfx::ColorSpace& color_space) = 0;

        virtual void SetOutputIsSecure(bool secure) = 0;
    };

    class DisplayCompositorProxy;

    template <typename ImplRefTraits>
    class DisplayCompositorStub;

    class DisplayCompositorRequestValidator;

    class DisplayCompositor
        : public DisplayCompositorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DisplayCompositorProxy;

        template <typename ImplRefTraits>
        using Stub_ = DisplayCompositorStub<ImplRefTraits>;

        using RequestValidator_ = DisplayCompositorRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kCreateDisplayCompositorFrameSinkMinVersion = 0,
            kCreateOffscreenCompositorFrameSinkMinVersion = 0,
        };
        virtual ~DisplayCompositor() { }

        virtual void CreateDisplayCompositorFrameSink(const cc::FrameSinkId& frame_sink_id, ::gpu::SurfaceHandle widget, ::cc::mojom::MojoCompositorFrameSinkRequest compositor_frame_sink, ::cc::mojom::MojoCompositorFrameSinkPrivateRequest compositor_frame_sink_private, ::cc::mojom::MojoCompositorFrameSinkClientPtr compositor_frame_sink_client, DisplayPrivateRequest display_private) = 0;

        virtual void CreateOffscreenCompositorFrameSink(const cc::FrameSinkId& frame_sink_id, ::cc::mojom::MojoCompositorFrameSinkRequest compositor_frame_sink, ::cc::mojom::MojoCompositorFrameSinkPrivateRequest compositor_frame_sink_private, ::cc::mojom::MojoCompositorFrameSinkClientPtr compositor_frame_sink_client) = 0;
    };

    class DisplayCompositorClientProxy;

    template <typename ImplRefTraits>
    class DisplayCompositorClientStub;

    class DisplayCompositorClientRequestValidator;

    class DisplayCompositorClient
        : public DisplayCompositorClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DisplayCompositorClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = DisplayCompositorClientStub<ImplRefTraits>;

        using RequestValidator_ = DisplayCompositorClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnSurfaceCreatedMinVersion = 0,
        };
        virtual ~DisplayCompositorClient() { }

        virtual void OnSurfaceCreated(const cc::SurfaceInfo& surface_info) = 0;
    };

    class DisplayPrivateProxy
        : public DisplayPrivate {
    public:
        explicit DisplayPrivateProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetDisplayVisible(bool visible) override;
        void ResizeDisplay(const gfx::Size& size_in_pixel) override;
        void SetDisplayColorSpace(const gfx::ColorSpace& color_space) override;
        void SetOutputIsSecure(bool secure) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class DisplayCompositorProxy
        : public DisplayCompositor {
    public:
        explicit DisplayCompositorProxy(mojo::MessageReceiverWithResponder* receiver);
        void CreateDisplayCompositorFrameSink(const cc::FrameSinkId& frame_sink_id, ::gpu::SurfaceHandle widget, ::cc::mojom::MojoCompositorFrameSinkRequest compositor_frame_sink, ::cc::mojom::MojoCompositorFrameSinkPrivateRequest compositor_frame_sink_private, ::cc::mojom::MojoCompositorFrameSinkClientPtr compositor_frame_sink_client, DisplayPrivateRequest display_private) override;
        void CreateOffscreenCompositorFrameSink(const cc::FrameSinkId& frame_sink_id, ::cc::mojom::MojoCompositorFrameSinkRequest compositor_frame_sink, ::cc::mojom::MojoCompositorFrameSinkPrivateRequest compositor_frame_sink_private, ::cc::mojom::MojoCompositorFrameSinkClientPtr compositor_frame_sink_client) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class DisplayCompositorClientProxy
        : public DisplayCompositorClient {
    public:
        explicit DisplayCompositorClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnSurfaceCreated(const cc::SurfaceInfo& surface_info) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class DisplayPrivateStubDispatch {
    public:
        static bool Accept(DisplayPrivate* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DisplayPrivate* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DisplayPrivate>>
    class DisplayPrivateStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DisplayPrivateStub() { }
        ~DisplayPrivateStub() override { }

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
            return DisplayPrivateStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DisplayPrivateStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DisplayCompositorStubDispatch {
    public:
        static bool Accept(DisplayCompositor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DisplayCompositor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DisplayCompositor>>
    class DisplayCompositorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DisplayCompositorStub() { }
        ~DisplayCompositorStub() override { }

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
            return DisplayCompositorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DisplayCompositorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DisplayCompositorClientStubDispatch {
    public:
        static bool Accept(DisplayCompositorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DisplayCompositorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DisplayCompositorClient>>
    class DisplayCompositorClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DisplayCompositorClientStub() { }
        ~DisplayCompositorClientStub() override { }

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
            return DisplayCompositorClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DisplayCompositorClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DisplayPrivateRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class DisplayCompositorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class DisplayCompositorClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace cc

namespace mojo {

} // namespace mojo

#endif // CC_IPC_DISPLAY_COMPOSITOR_MOJOM_H_