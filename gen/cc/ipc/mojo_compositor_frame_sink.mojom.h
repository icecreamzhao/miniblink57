// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_MOJO_COMPOSITOR_FRAME_SINK_MOJOM_H_
#define CC_IPC_MOJO_COMPOSITOR_FRAME_SINK_MOJOM_H_

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
#include "cc/ipc/begin_frame_args.mojom.h"
#include "cc/ipc/compositor_frame.mojom.h"
#include "cc/ipc/frame_sink_id.mojom.h"
#include "cc/ipc/local_frame_id.mojom.h"
#include "cc/ipc/mojo_compositor_frame_sink.mojom-shared.h"
#include "cc/ipc/returned_resource.mojom.h"
#include "cc/ipc/surface_reference.mojom.h"
#include "cc/ipc/surface_sequence.mojom.h"
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
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace cc {
namespace mojom {
    class MojoCompositorFrameSink;
    using MojoCompositorFrameSinkPtr = mojo::InterfacePtr<MojoCompositorFrameSink>;
    using MojoCompositorFrameSinkPtrInfo = mojo::InterfacePtrInfo<MojoCompositorFrameSink>;
    using ThreadSafeMojoCompositorFrameSinkPtr = mojo::ThreadSafeInterfacePtr<MojoCompositorFrameSink>;
    using MojoCompositorFrameSinkRequest = mojo::InterfaceRequest<MojoCompositorFrameSink>;
    using MojoCompositorFrameSinkAssociatedPtr = mojo::AssociatedInterfacePtr<MojoCompositorFrameSink>;
    using ThreadSafeMojoCompositorFrameSinkAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<MojoCompositorFrameSink>;
    using MojoCompositorFrameSinkAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<MojoCompositorFrameSink>;
    using MojoCompositorFrameSinkAssociatedRequest = mojo::AssociatedInterfaceRequest<MojoCompositorFrameSink>;

    class MojoCompositorFrameSinkClient;
    using MojoCompositorFrameSinkClientPtr = mojo::InterfacePtr<MojoCompositorFrameSinkClient>;
    using MojoCompositorFrameSinkClientPtrInfo = mojo::InterfacePtrInfo<MojoCompositorFrameSinkClient>;
    using ThreadSafeMojoCompositorFrameSinkClientPtr = mojo::ThreadSafeInterfacePtr<MojoCompositorFrameSinkClient>;
    using MojoCompositorFrameSinkClientRequest = mojo::InterfaceRequest<MojoCompositorFrameSinkClient>;
    using MojoCompositorFrameSinkClientAssociatedPtr = mojo::AssociatedInterfacePtr<MojoCompositorFrameSinkClient>;
    using ThreadSafeMojoCompositorFrameSinkClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<MojoCompositorFrameSinkClient>;
    using MojoCompositorFrameSinkClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<MojoCompositorFrameSinkClient>;
    using MojoCompositorFrameSinkClientAssociatedRequest = mojo::AssociatedInterfaceRequest<MojoCompositorFrameSinkClient>;

    class MojoCompositorFrameSinkPrivate;
    using MojoCompositorFrameSinkPrivatePtr = mojo::InterfacePtr<MojoCompositorFrameSinkPrivate>;
    using MojoCompositorFrameSinkPrivatePtrInfo = mojo::InterfacePtrInfo<MojoCompositorFrameSinkPrivate>;
    using ThreadSafeMojoCompositorFrameSinkPrivatePtr = mojo::ThreadSafeInterfacePtr<MojoCompositorFrameSinkPrivate>;
    using MojoCompositorFrameSinkPrivateRequest = mojo::InterfaceRequest<MojoCompositorFrameSinkPrivate>;
    using MojoCompositorFrameSinkPrivateAssociatedPtr = mojo::AssociatedInterfacePtr<MojoCompositorFrameSinkPrivate>;
    using ThreadSafeMojoCompositorFrameSinkPrivateAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<MojoCompositorFrameSinkPrivate>;
    using MojoCompositorFrameSinkPrivateAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<MojoCompositorFrameSinkPrivate>;
    using MojoCompositorFrameSinkPrivateAssociatedRequest = mojo::AssociatedInterfaceRequest<MojoCompositorFrameSinkPrivate>;

    class MojoCompositorFrameSinkProxy;

    template <typename ImplRefTraits>
    class MojoCompositorFrameSinkStub;

    class MojoCompositorFrameSinkRequestValidator;

    class MojoCompositorFrameSink
        : public MojoCompositorFrameSinkInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = MojoCompositorFrameSinkProxy;

        template <typename ImplRefTraits>
        using Stub_ = MojoCompositorFrameSinkStub<ImplRefTraits>;

        using RequestValidator_ = MojoCompositorFrameSinkRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kSetNeedsBeginFrameMinVersion = 0,
            kSubmitCompositorFrameMinVersion = 0,
            kEvictFrameMinVersion = 0,
            kRequireMinVersion = 0,
            kSatisfyMinVersion = 0,
        };
        virtual ~MojoCompositorFrameSink() { }

        virtual void SetNeedsBeginFrame(bool needs_begin_frame) = 0;

        virtual void SubmitCompositorFrame(const cc::LocalFrameId& local_frame_id, cc::CompositorFrame frame) = 0;

        virtual void EvictFrame() = 0;

        virtual void Require(const cc::LocalFrameId& local_frame_id, const cc::SurfaceSequence& sequence) = 0;

        virtual void Satisfy(const cc::SurfaceSequence& sequence) = 0;
    };

    class MojoCompositorFrameSinkClientProxy;

    template <typename ImplRefTraits>
    class MojoCompositorFrameSinkClientStub;

    class MojoCompositorFrameSinkClientRequestValidator;

    class MojoCompositorFrameSinkClient
        : public MojoCompositorFrameSinkClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = MojoCompositorFrameSinkClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = MojoCompositorFrameSinkClientStub<ImplRefTraits>;

        using RequestValidator_ = MojoCompositorFrameSinkClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kDidReceiveCompositorFrameAckMinVersion = 0,
            kOnBeginFrameMinVersion = 0,
            kReclaimResourcesMinVersion = 0,
            kWillDrawSurfaceMinVersion = 0,
        };
        virtual ~MojoCompositorFrameSinkClient() { }

        virtual void DidReceiveCompositorFrameAck() = 0;

        virtual void OnBeginFrame(const cc::BeginFrameArgs& args) = 0;

        virtual void ReclaimResources(const cc::ReturnedResourceArray& resources) = 0;

        virtual void WillDrawSurface() = 0;
    };

    class MojoCompositorFrameSinkPrivateProxy;

    template <typename ImplRefTraits>
    class MojoCompositorFrameSinkPrivateStub;

    class MojoCompositorFrameSinkPrivateRequestValidator;

    class MojoCompositorFrameSinkPrivate
        : public MojoCompositorFrameSinkPrivateInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = MojoCompositorFrameSinkPrivateProxy;

        template <typename ImplRefTraits>
        using Stub_ = MojoCompositorFrameSinkPrivateStub<ImplRefTraits>;

        using RequestValidator_ = MojoCompositorFrameSinkPrivateRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kAddChildFrameSinkMinVersion = 0,
            kRemoveChildFrameSinkMinVersion = 0,
        };
        virtual ~MojoCompositorFrameSinkPrivate() { }

        virtual void AddChildFrameSink(const cc::FrameSinkId& child_frame_sink_id) = 0;

        virtual void RemoveChildFrameSink(const cc::FrameSinkId& child_frame_sink_id) = 0;
    };

    class MojoCompositorFrameSinkProxy
        : public MojoCompositorFrameSink {
    public:
        explicit MojoCompositorFrameSinkProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetNeedsBeginFrame(bool needs_begin_frame) override;
        void SubmitCompositorFrame(const cc::LocalFrameId& local_frame_id, cc::CompositorFrame frame) override;
        void EvictFrame() override;
        void Require(const cc::LocalFrameId& local_frame_id, const cc::SurfaceSequence& sequence) override;
        void Satisfy(const cc::SurfaceSequence& sequence) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class MojoCompositorFrameSinkClientProxy
        : public MojoCompositorFrameSinkClient {
    public:
        explicit MojoCompositorFrameSinkClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void DidReceiveCompositorFrameAck() override;
        void OnBeginFrame(const cc::BeginFrameArgs& args) override;
        void ReclaimResources(const cc::ReturnedResourceArray& resources) override;
        void WillDrawSurface() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class MojoCompositorFrameSinkPrivateProxy
        : public MojoCompositorFrameSinkPrivate {
    public:
        explicit MojoCompositorFrameSinkPrivateProxy(mojo::MessageReceiverWithResponder* receiver);
        void AddChildFrameSink(const cc::FrameSinkId& child_frame_sink_id) override;
        void RemoveChildFrameSink(const cc::FrameSinkId& child_frame_sink_id) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class MojoCompositorFrameSinkStubDispatch {
    public:
        static bool Accept(MojoCompositorFrameSink* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(MojoCompositorFrameSink* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<MojoCompositorFrameSink>>
    class MojoCompositorFrameSinkStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        MojoCompositorFrameSinkStub() { }
        ~MojoCompositorFrameSinkStub() override { }

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
            return MojoCompositorFrameSinkStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return MojoCompositorFrameSinkStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class MojoCompositorFrameSinkClientStubDispatch {
    public:
        static bool Accept(MojoCompositorFrameSinkClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(MojoCompositorFrameSinkClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<MojoCompositorFrameSinkClient>>
    class MojoCompositorFrameSinkClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        MojoCompositorFrameSinkClientStub() { }
        ~MojoCompositorFrameSinkClientStub() override { }

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
            return MojoCompositorFrameSinkClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return MojoCompositorFrameSinkClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class MojoCompositorFrameSinkPrivateStubDispatch {
    public:
        static bool Accept(MojoCompositorFrameSinkPrivate* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(MojoCompositorFrameSinkPrivate* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<MojoCompositorFrameSinkPrivate>>
    class MojoCompositorFrameSinkPrivateStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        MojoCompositorFrameSinkPrivateStub() { }
        ~MojoCompositorFrameSinkPrivateStub() override { }

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
            return MojoCompositorFrameSinkPrivateStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return MojoCompositorFrameSinkPrivateStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class MojoCompositorFrameSinkRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class MojoCompositorFrameSinkClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class MojoCompositorFrameSinkPrivateRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace cc

namespace mojo {

} // namespace mojo

#endif // CC_IPC_MOJO_COMPOSITOR_FRAME_SINK_MOJOM_H_