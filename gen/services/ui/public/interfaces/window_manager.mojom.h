// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_MOJOM_H_

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
#include "services/ui/public/interfaces/cursor.mojom.h"
#include "services/ui/public/interfaces/display/display.mojom.h"
#include "services/ui/public/interfaces/event_matcher.mojom.h"
#include "services/ui/public/interfaces/window_manager.mojom-shared.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom.h"
#include "services/ui/public/interfaces/window_tree_constants.mojom.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/display/display.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/events/mojo/event.mojom.h"
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
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    class WindowManager;
    using WindowManagerPtr = mojo::InterfacePtr<WindowManager>;
    using WindowManagerPtrInfo = mojo::InterfacePtrInfo<WindowManager>;
    using ThreadSafeWindowManagerPtr = mojo::ThreadSafeInterfacePtr<WindowManager>;
    using WindowManagerRequest = mojo::InterfaceRequest<WindowManager>;
    using WindowManagerAssociatedPtr = mojo::AssociatedInterfacePtr<WindowManager>;
    using ThreadSafeWindowManagerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WindowManager>;
    using WindowManagerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WindowManager>;
    using WindowManagerAssociatedRequest = mojo::AssociatedInterfaceRequest<WindowManager>;

    class WindowManagerClient;
    using WindowManagerClientPtr = mojo::InterfacePtr<WindowManagerClient>;
    using WindowManagerClientPtrInfo = mojo::InterfacePtrInfo<WindowManagerClient>;
    using ThreadSafeWindowManagerClientPtr = mojo::ThreadSafeInterfacePtr<WindowManagerClient>;
    using WindowManagerClientRequest = mojo::InterfaceRequest<WindowManagerClient>;
    using WindowManagerClientAssociatedPtr = mojo::AssociatedInterfacePtr<WindowManagerClient>;
    using ThreadSafeWindowManagerClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WindowManagerClient>;
    using WindowManagerClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WindowManagerClient>;
    using WindowManagerClientAssociatedRequest = mojo::AssociatedInterfaceRequest<WindowManagerClient>;

    class Accelerator;
    using AcceleratorPtr = mojo::StructPtr<Accelerator>;

    class WindowManagerProxy;

    template <typename ImplRefTraits>
    class WindowManagerStub;

    class WindowManagerRequestValidator;

    class WindowManager
        : public WindowManagerInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = WindowManagerProxy;

        template <typename ImplRefTraits>
        using Stub_ = WindowManagerStub<ImplRefTraits>;

        using RequestValidator_ = WindowManagerRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnConnectMinVersion = 0,
            kWmNewDisplayAddedMinVersion = 0,
            kWmDisplayRemovedMinVersion = 0,
            kWmDisplayModifiedMinVersion = 0,
            kWmSetBoundsMinVersion = 0,
            kWmSetPropertyMinVersion = 0,
            kWmCreateTopLevelWindowMinVersion = 0,
            kWmClientJankinessChangedMinVersion = 0,
            kWmPerformMoveLoopMinVersion = 0,
            kWmCancelMoveLoopMinVersion = 0,
            kWmDeactivateWindowMinVersion = 0,
            kOnAcceleratorMinVersion = 0,
        };
        static const char kBounds_InitProperty[];
        static const char kContainerId_InitProperty[];
        static const char kDisableImmersive_InitProperty[];
        static const char kDisplayId_InitProperty[];
        static const char kRemoveStandardFrame_InitProperty[];
        static const char kWindowType_InitProperty[];
        static const char kAlwaysOnTop_Property[];
        static const char kAppIcon_Property[];
        static const char kAppID_Property[];
        static const char kExcludeFromMru_Property[];
        static const char kName_Property[];
        static const char kPanelAttached_Property[];
        static const char kPreferredSize_Property[];
        static const char kRenderParentTitleArea_Property[];
        static const char kResizeBehavior_Property[];
        static const char kRestoreBounds_Property[];
        static const char kShelfItemType_Property[];
        static const char kShowState_Property[];
        static const char kWindowIcon_Property[];
        static const char kWindowIgnoredByShelf_Property[];
        static const char kWindowTitle_Property[];
        static const char kShadowStyle_Property[];
        virtual ~WindowManager() { }

        virtual void OnConnect(uint16_t client_id) = 0;

        virtual void WmNewDisplayAdded(const display::Display& display, ::ui::mojom::WindowDataPtr root, bool parent_drawn) = 0;

        virtual void WmDisplayRemoved(int64_t display_id) = 0;

        virtual void WmDisplayModified(const display::Display& display) = 0;

        virtual void WmSetBounds(uint32_t change_id, uint32_t window_id, const gfx::Rect& bounds) = 0;

        virtual void WmSetProperty(uint32_t change_id, uint32_t window_id, const std::string& name, const base::Optional<std::vector<uint8_t>>& value) = 0;

        virtual void WmCreateTopLevelWindow(uint32_t change_id, uint16_t requesting_client_id, const std::unordered_map<std::string, std::vector<uint8_t>>& properties) = 0;

        virtual void WmClientJankinessChanged(uint16_t client_id, bool janky) = 0;

        virtual void WmPerformMoveLoop(uint32_t change_id, uint32_t window_id, ::ui::mojom::MoveLoopSource source, const gfx::Point& cursor_location) = 0;

        virtual void WmCancelMoveLoop(uint32_t change_id) = 0;

        virtual void WmDeactivateWindow(uint32_t window_id) = 0;

        virtual void OnAccelerator(uint32_t ack_id, uint32_t accelerator_id, std::unique_ptr<ui::Event> event) = 0;
    };

    class WindowManagerClientProxy;

    template <typename ImplRefTraits>
    class WindowManagerClientStub;

    class WindowManagerClientRequestValidator;
    class WindowManagerClientResponseValidator;

    class WindowManagerClient
        : public WindowManagerClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = WindowManagerClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = WindowManagerClientStub<ImplRefTraits>;

        using RequestValidator_ = WindowManagerClientRequestValidator;
        using ResponseValidator_ = WindowManagerClientResponseValidator;
        enum MethodMinVersions : uint32_t {
            kAddActivationParentMinVersion = 0,
            kRemoveActivationParentMinVersion = 0,
            kActivateNextWindowMinVersion = 0,
            kSetUnderlaySurfaceOffsetAndExtendedHitAreaMinVersion = 0,
            kAddAcceleratorsMinVersion = 0,
            kRemoveAcceleratorMinVersion = 0,
            kWmResponseMinVersion = 0,
            kWmRequestCloseMinVersion = 0,
            kWmSetFrameDecorationValuesMinVersion = 0,
            kWmSetNonClientCursorMinVersion = 0,
            kOnWmCreatedTopLevelWindowMinVersion = 0,
            kOnAcceleratorAckMinVersion = 0,
        };
        virtual ~WindowManagerClient() { }

        virtual void AddActivationParent(uint32_t window_id) = 0;

        virtual void RemoveActivationParent(uint32_t window_id) = 0;

        virtual void ActivateNextWindow() = 0;

        virtual void SetUnderlaySurfaceOffsetAndExtendedHitArea(uint32_t window_id, int32_t x_offset, int32_t y_offset, const gfx::Insets& hit_area) = 0;

        using AddAcceleratorsCallback = base::Callback<void(bool)>;
        virtual void AddAccelerators(std::vector<AcceleratorPtr> accelerators, const AddAcceleratorsCallback& callback) = 0;

        virtual void RemoveAccelerator(uint32_t id) = 0;

        virtual void WmResponse(uint32_t change_id, bool response) = 0;

        virtual void WmRequestClose(uint32_t window_id) = 0;

        virtual void WmSetFrameDecorationValues(::ui::mojom::FrameDecorationValuesPtr values) = 0;

        virtual void WmSetNonClientCursor(uint32_t window_id, ::ui::mojom::Cursor cursor_id) = 0;

        virtual void OnWmCreatedTopLevelWindow(uint32_t change_id, uint32_t window_id) = 0;

        virtual void OnAcceleratorAck(uint32_t ack_id, ::ui::mojom::EventResult event_result) = 0;
    };

    class WindowManagerProxy
        : public WindowManager {
    public:
        explicit WindowManagerProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnConnect(uint16_t client_id) override;
        void WmNewDisplayAdded(const display::Display& display, ::ui::mojom::WindowDataPtr root, bool parent_drawn) override;
        void WmDisplayRemoved(int64_t display_id) override;
        void WmDisplayModified(const display::Display& display) override;
        void WmSetBounds(uint32_t change_id, uint32_t window_id, const gfx::Rect& bounds) override;
        void WmSetProperty(uint32_t change_id, uint32_t window_id, const std::string& name, const base::Optional<std::vector<uint8_t>>& value) override;
        void WmCreateTopLevelWindow(uint32_t change_id, uint16_t requesting_client_id, const std::unordered_map<std::string, std::vector<uint8_t>>& properties) override;
        void WmClientJankinessChanged(uint16_t client_id, bool janky) override;
        void WmPerformMoveLoop(uint32_t change_id, uint32_t window_id, ::ui::mojom::MoveLoopSource source, const gfx::Point& cursor_location) override;
        void WmCancelMoveLoop(uint32_t change_id) override;
        void WmDeactivateWindow(uint32_t window_id) override;
        void OnAccelerator(uint32_t ack_id, uint32_t accelerator_id, std::unique_ptr<ui::Event> event) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class WindowManagerClientProxy
        : public WindowManagerClient {
    public:
        explicit WindowManagerClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void AddActivationParent(uint32_t window_id) override;
        void RemoveActivationParent(uint32_t window_id) override;
        void ActivateNextWindow() override;
        void SetUnderlaySurfaceOffsetAndExtendedHitArea(uint32_t window_id, int32_t x_offset, int32_t y_offset, const gfx::Insets& hit_area) override;
        void AddAccelerators(std::vector<AcceleratorPtr> accelerators, const AddAcceleratorsCallback& callback) override;
        void RemoveAccelerator(uint32_t id) override;
        void WmResponse(uint32_t change_id, bool response) override;
        void WmRequestClose(uint32_t window_id) override;
        void WmSetFrameDecorationValues(::ui::mojom::FrameDecorationValuesPtr values) override;
        void WmSetNonClientCursor(uint32_t window_id, ::ui::mojom::Cursor cursor_id) override;
        void OnWmCreatedTopLevelWindow(uint32_t change_id, uint32_t window_id) override;
        void OnAcceleratorAck(uint32_t ack_id, ::ui::mojom::EventResult event_result) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class WindowManagerStubDispatch {
    public:
        static bool Accept(WindowManager* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(WindowManager* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WindowManager>>
    class WindowManagerStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        WindowManagerStub() { }
        ~WindowManagerStub() override { }

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
            return WindowManagerStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return WindowManagerStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class WindowManagerClientStubDispatch {
    public:
        static bool Accept(WindowManagerClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(WindowManagerClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WindowManagerClient>>
    class WindowManagerClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        WindowManagerClientStub() { }
        ~WindowManagerClientStub() override { }

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
            return WindowManagerClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return WindowManagerClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class WindowManagerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class WindowManagerClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class WindowManagerClientResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class Accelerator {
    public:
        using DataView = AcceleratorDataView;
        using Data_ = internal::Accelerator_Data;

        static AcceleratorPtr New();

        template <typename U>
        static AcceleratorPtr From(const U& u)
        {
            return mojo::TypeConverter<AcceleratorPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Accelerator>::Convert(*this);
        }

        Accelerator();
        ~Accelerator();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = AcceleratorPtr>
        AcceleratorPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Accelerator>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Accelerator::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Accelerator::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t id;
        ::ui::mojom::EventMatcherPtr event_matcher;

    private:
        DISALLOW_COPY_AND_ASSIGN(Accelerator);
    };

    template <typename StructPtrType>
    AcceleratorPtr Accelerator::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        rv->event_matcher = mojo::internal::Clone(event_matcher);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Accelerator>::value>::type*>
    bool Accelerator::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->event_matcher, other.event_matcher))
            return false;
        return true;
    }

} // namespace mojom
} // namespace ui

namespace mojo {

template <>
struct StructTraits<::ui::mojom::Accelerator::DataView,
    ::ui::mojom::AcceleratorPtr> {
    static bool IsNull(const ::ui::mojom::AcceleratorPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::AcceleratorPtr* output) { output->reset(); }

    static decltype(::ui::mojom::Accelerator::id) id(
        const ::ui::mojom::AcceleratorPtr& input)
    {
        return input->id;
    }

    static const decltype(::ui::mojom::Accelerator::event_matcher)& event_matcher(
        const ::ui::mojom::AcceleratorPtr& input)
    {
        return input->event_matcher;
    }

    static bool Read(::ui::mojom::Accelerator::DataView input, ::ui::mojom::AcceleratorPtr* output);
};

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_MOJOM_H_