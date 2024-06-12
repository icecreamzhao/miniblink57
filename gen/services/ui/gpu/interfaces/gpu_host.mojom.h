// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_GPU_INTERFACES_GPU_HOST_MOJOM_H_
#define SERVICES_UI_GPU_INTERFACES_GPU_HOST_MOJOM_H_

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
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/constants.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/gpu_info.mojom.h"
#include "gpu/ipc/common/surface_handle.h"
#include "gpu/ipc/common/surface_handle.mojom.h"
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
#include "services/ui/gpu/interfaces/context_lost_reason.mojom.h"
#include "services/ui/gpu/interfaces/gpu_host.mojom-shared.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
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
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    class GpuHost;
    using GpuHostPtr = mojo::InterfacePtr<GpuHost>;
    using GpuHostPtrInfo = mojo::InterfacePtrInfo<GpuHost>;
    using ThreadSafeGpuHostPtr = mojo::ThreadSafeInterfacePtr<GpuHost>;
    using GpuHostRequest = mojo::InterfaceRequest<GpuHost>;
    using GpuHostAssociatedPtr = mojo::AssociatedInterfacePtr<GpuHost>;
    using ThreadSafeGpuHostAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<GpuHost>;
    using GpuHostAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<GpuHost>;
    using GpuHostAssociatedRequest = mojo::AssociatedInterfaceRequest<GpuHost>;

    class GpuHostProxy;

    template <typename ImplRefTraits>
    class GpuHostStub;

    class GpuHostRequestValidator;

    class GpuHost
        : public GpuHostInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = GpuHostProxy;

        template <typename ImplRefTraits>
        using Stub_ = GpuHostStub<ImplRefTraits>;

        using RequestValidator_ = GpuHostRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kDidInitializeMinVersion = 0,
            kDidCreateOffscreenContextMinVersion = 0,
            kDidDestroyOffscreenContextMinVersion = 0,
            kDidDestroyChannelMinVersion = 0,
            kDidLoseContextMinVersion = 0,
            kSetChildSurfaceMinVersion = 0,
            kStoreShaderToDiskMinVersion = 0,
        };
        virtual ~GpuHost() { }

        virtual void DidInitialize(const gpu::GPUInfo& gpu_info) = 0;

        virtual void DidCreateOffscreenContext(const GURL& url) = 0;

        virtual void DidDestroyOffscreenContext(const GURL& url) = 0;

        virtual void DidDestroyChannel(int32_t client_id) = 0;

        virtual void DidLoseContext(bool offscreen, gpu::error::ContextLostReason reason, const GURL& active_url) = 0;

        virtual void SetChildSurface(::gpu::SurfaceHandle parent, ::gpu::SurfaceHandle child) = 0;

        virtual void StoreShaderToDisk(int32_t client_id, const std::string& key, const std::string& shader) = 0;
    };

    class GpuHostProxy
        : public GpuHost {
    public:
        explicit GpuHostProxy(mojo::MessageReceiverWithResponder* receiver);
        void DidInitialize(const gpu::GPUInfo& gpu_info) override;
        void DidCreateOffscreenContext(const GURL& url) override;
        void DidDestroyOffscreenContext(const GURL& url) override;
        void DidDestroyChannel(int32_t client_id) override;
        void DidLoseContext(bool offscreen, gpu::error::ContextLostReason reason, const GURL& active_url) override;
        void SetChildSurface(::gpu::SurfaceHandle parent, ::gpu::SurfaceHandle child) override;
        void StoreShaderToDisk(int32_t client_id, const std::string& key, const std::string& shader) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class GpuHostStubDispatch {
    public:
        static bool Accept(GpuHost* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(GpuHost* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<GpuHost>>
    class GpuHostStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        GpuHostStub() { }
        ~GpuHostStub() override { }

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
            return GpuHostStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return GpuHostStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class GpuHostRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace ui

namespace mojo {

} // namespace mojo

#endif // SERVICES_UI_GPU_INTERFACES_GPU_HOST_MOJOM_H_