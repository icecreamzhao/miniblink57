// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_USER_ACTIVITY_MONITOR_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_USER_ACTIVITY_MONITOR_MOJOM_H_

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
#include "services/ui/public/interfaces/user_activity_monitor.mojom-shared.h"
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
    class UserActivityObserver;
    using UserActivityObserverPtr = mojo::InterfacePtr<UserActivityObserver>;
    using UserActivityObserverPtrInfo = mojo::InterfacePtrInfo<UserActivityObserver>;
    using ThreadSafeUserActivityObserverPtr = mojo::ThreadSafeInterfacePtr<UserActivityObserver>;
    using UserActivityObserverRequest = mojo::InterfaceRequest<UserActivityObserver>;
    using UserActivityObserverAssociatedPtr = mojo::AssociatedInterfacePtr<UserActivityObserver>;
    using ThreadSafeUserActivityObserverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<UserActivityObserver>;
    using UserActivityObserverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<UserActivityObserver>;
    using UserActivityObserverAssociatedRequest = mojo::AssociatedInterfaceRequest<UserActivityObserver>;

    class UserIdleObserver;
    using UserIdleObserverPtr = mojo::InterfacePtr<UserIdleObserver>;
    using UserIdleObserverPtrInfo = mojo::InterfacePtrInfo<UserIdleObserver>;
    using ThreadSafeUserIdleObserverPtr = mojo::ThreadSafeInterfacePtr<UserIdleObserver>;
    using UserIdleObserverRequest = mojo::InterfaceRequest<UserIdleObserver>;
    using UserIdleObserverAssociatedPtr = mojo::AssociatedInterfacePtr<UserIdleObserver>;
    using ThreadSafeUserIdleObserverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<UserIdleObserver>;
    using UserIdleObserverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<UserIdleObserver>;
    using UserIdleObserverAssociatedRequest = mojo::AssociatedInterfaceRequest<UserIdleObserver>;

    class UserActivityMonitor;
    using UserActivityMonitorPtr = mojo::InterfacePtr<UserActivityMonitor>;
    using UserActivityMonitorPtrInfo = mojo::InterfacePtrInfo<UserActivityMonitor>;
    using ThreadSafeUserActivityMonitorPtr = mojo::ThreadSafeInterfacePtr<UserActivityMonitor>;
    using UserActivityMonitorRequest = mojo::InterfaceRequest<UserActivityMonitor>;
    using UserActivityMonitorAssociatedPtr = mojo::AssociatedInterfacePtr<UserActivityMonitor>;
    using ThreadSafeUserActivityMonitorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<UserActivityMonitor>;
    using UserActivityMonitorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<UserActivityMonitor>;
    using UserActivityMonitorAssociatedRequest = mojo::AssociatedInterfaceRequest<UserActivityMonitor>;

    class UserActivityObserverProxy;

    template <typename ImplRefTraits>
    class UserActivityObserverStub;

    class UserActivityObserverRequestValidator;

    class UserActivityObserver
        : public UserActivityObserverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = UserActivityObserverProxy;

        template <typename ImplRefTraits>
        using Stub_ = UserActivityObserverStub<ImplRefTraits>;

        using RequestValidator_ = UserActivityObserverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnUserActivityMinVersion = 0,
        };
        virtual ~UserActivityObserver() { }

        virtual void OnUserActivity() = 0;
    };

    class UserIdleObserverProxy;

    template <typename ImplRefTraits>
    class UserIdleObserverStub;

    class UserIdleObserverRequestValidator;

    class UserIdleObserver
        : public UserIdleObserverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = UserIdleObserverProxy;

        template <typename ImplRefTraits>
        using Stub_ = UserIdleObserverStub<ImplRefTraits>;

        using RequestValidator_ = UserIdleObserverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnUserIdleStateChangedMinVersion = 0,
        };
        using IdleState = UserIdleObserver_IdleState;
        virtual ~UserIdleObserver() { }

        virtual void OnUserIdleStateChanged(UserIdleObserver::IdleState new_state) = 0;
    };

    class UserActivityMonitorProxy;

    template <typename ImplRefTraits>
    class UserActivityMonitorStub;

    class UserActivityMonitorRequestValidator;

    class UserActivityMonitor
        : public UserActivityMonitorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = UserActivityMonitorProxy;

        template <typename ImplRefTraits>
        using Stub_ = UserActivityMonitorStub<ImplRefTraits>;

        using RequestValidator_ = UserActivityMonitorRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kAddUserActivityObserverMinVersion = 0,
            kAddUserIdleObserverMinVersion = 0,
        };
        virtual ~UserActivityMonitor() { }

        virtual void AddUserActivityObserver(uint32_t delay_between_notify_secs, UserActivityObserverPtr observer) = 0;

        virtual void AddUserIdleObserver(uint32_t idle_time_in_minutes, UserIdleObserverPtr observer) = 0;
    };

    class UserActivityObserverProxy
        : public UserActivityObserver {
    public:
        explicit UserActivityObserverProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnUserActivity() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class UserIdleObserverProxy
        : public UserIdleObserver {
    public:
        explicit UserIdleObserverProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnUserIdleStateChanged(UserIdleObserver::IdleState new_state) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class UserActivityMonitorProxy
        : public UserActivityMonitor {
    public:
        explicit UserActivityMonitorProxy(mojo::MessageReceiverWithResponder* receiver);
        void AddUserActivityObserver(uint32_t delay_between_notify_secs, UserActivityObserverPtr observer) override;
        void AddUserIdleObserver(uint32_t idle_time_in_minutes, UserIdleObserverPtr observer) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class UserActivityObserverStubDispatch {
    public:
        static bool Accept(UserActivityObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(UserActivityObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<UserActivityObserver>>
    class UserActivityObserverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        UserActivityObserverStub() { }
        ~UserActivityObserverStub() override { }

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
            return UserActivityObserverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return UserActivityObserverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class UserIdleObserverStubDispatch {
    public:
        static bool Accept(UserIdleObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(UserIdleObserver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<UserIdleObserver>>
    class UserIdleObserverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        UserIdleObserverStub() { }
        ~UserIdleObserverStub() override { }

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
            return UserIdleObserverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return UserIdleObserverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class UserActivityMonitorStubDispatch {
    public:
        static bool Accept(UserActivityMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(UserActivityMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<UserActivityMonitor>>
    class UserActivityMonitorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        UserActivityMonitorStub() { }
        ~UserActivityMonitorStub() override { }

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
            return UserActivityMonitorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return UserActivityMonitorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class UserActivityObserverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class UserIdleObserverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class UserActivityMonitorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace ui

namespace mojo {

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_USER_ACTIVITY_MONITOR_MOJOM_H_