// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_MANAGER_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_MANAGER_MOJOM_H_

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
#include "services/ui/public/interfaces/display_manager.mojom-shared.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom.h"
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
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    class DisplayManagerObserver;
    using DisplayManagerObserverPtr = mojo::InterfacePtr<DisplayManagerObserver>;
    using DisplayManagerObserverPtrInfo = mojo::InterfacePtrInfo<DisplayManagerObserver>;
    using ThreadSafeDisplayManagerObserverPtr = mojo::ThreadSafeInterfacePtr<DisplayManagerObserver>;
    using DisplayManagerObserverRequest = mojo::InterfaceRequest<DisplayManagerObserver>;
    using DisplayManagerObserverAssociatedPtr = mojo::AssociatedInterfacePtr<DisplayManagerObserver>;
    using ThreadSafeDisplayManagerObserverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DisplayManagerObserver>;
    using DisplayManagerObserverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DisplayManagerObserver>;
    using DisplayManagerObserverAssociatedRequest = mojo::AssociatedInterfaceRequest<DisplayManagerObserver>;

    class DisplayManager;
    using DisplayManagerPtr = mojo::InterfacePtr<DisplayManager>;
    using DisplayManagerPtrInfo = mojo::InterfacePtrInfo<DisplayManager>;
    using ThreadSafeDisplayManagerPtr = mojo::ThreadSafeInterfacePtr<DisplayManager>;
    using DisplayManagerRequest = mojo::InterfaceRequest<DisplayManager>;
    using DisplayManagerAssociatedPtr = mojo::AssociatedInterfacePtr<DisplayManager>;
    using ThreadSafeDisplayManagerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DisplayManager>;
    using DisplayManagerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DisplayManager>;
    using DisplayManagerAssociatedRequest = mojo::AssociatedInterfaceRequest<DisplayManager>;

    class DisplayManagerObserverProxy;

    template <typename ImplRefTraits>
    class DisplayManagerObserverStub;

    class DisplayManagerObserverRequestValidator;

    class DisplayManagerObserver
        : public DisplayManagerObserverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DisplayManagerObserverProxy;

        template <typename ImplRefTraits>
        using Stub_ = DisplayManagerObserverStub<ImplRefTraits>;

        using RequestValidator_ = DisplayManagerObserverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnDisplaysMinVersion = 0,
            kOnDisplaysChangedMinVersion = 0,
            kOnDisplayRemovedMinVersion = 0,
            kOnPrimaryDisplayChangedMinVersion = 0,
        };
        virtual ~DisplayManagerObserver() { }

        virtual void OnDisplays(std::vector<::ui::mojom::WsDisplayPtr> displays, int64_t primary_display_id, int64_t internal_display_id) = 0;

        virtual void OnDisplaysChanged(std::vector<::ui::mojom::WsDisplayPtr> displays) = 0;

        virtual void OnDisplayRemoved(int64_t display_id) = 0;

        virtual void OnPrimaryDisplayChanged(int64_t primary_display_id) = 0;
    };

    class DisplayManagerProxy;

    template <typename ImplRefTraits>
    class DisplayManagerStub;

    class DisplayManagerRequestValidator;

    class DisplayManager
        : public DisplayManagerInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DisplayManagerProxy;

        template <typename ImplRefTraits>
        using Stub_ = DisplayManagerStub<ImplRefTraits>;

        using RequestValidator_ = DisplayManagerRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kAddObserverMinVersion = 0,
        };
        virtual ~DisplayManager() { }

        virtual void AddObserver(DisplayManagerObserverPtr observer) = 0;
    };

    class DisplayManagerObserverProxy
        : public DisplayManagerObserver {
    public:
        explicit DisplayManagerObserverProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnDisplays(std::vector<::ui::mojom::WsDisplayPtr> displays, int64_t primary_display_id, int64_t internal_display_id) override;
        void OnDisplaysChanged(std::vector<::ui::mojom::WsDisplayPtr> displays) override;
        void OnDisplayRemoved(int64_t display_id) override;
        void OnPrimaryDisplayChanged(int64_t primary_display_id) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class DisplayManagerProxy
        : public DisplayManager {
    public:
        explicit DisplayManagerProxy(mojo::MessageReceiverWithResponder* receiver);
        void AddObserver(DisplayManagerObserverPtr observer) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class DisplayManagerObserverStubDispatch {
    public:
        static bool Accept(DisplayManagerObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DisplayManagerObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DisplayManagerObserver>>
    class DisplayManagerObserverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DisplayManagerObserverStub() { }
        ~DisplayManagerObserverStub() override { }

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
            return DisplayManagerObserverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DisplayManagerObserverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DisplayManagerStubDispatch {
    public:
        static bool Accept(DisplayManager* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DisplayManager* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DisplayManager>>
    class DisplayManagerStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DisplayManagerStub() { }
        ~DisplayManagerStub() override { }

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
            return DisplayManagerStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DisplayManagerStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DisplayManagerObserverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class DisplayManagerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace ui

namespace mojo {

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_MANAGER_MOJOM_H_