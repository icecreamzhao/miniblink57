// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_MOJOM_H_

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
#include "cc/ipc/mojo_compositor_frame_sink.mojom.h"
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
#include "services/ui/public/interfaces/event_matcher.mojom.h"
#include "services/ui/public/interfaces/mus_constants.mojom.h"
#include "services/ui/public/interfaces/window_manager.mojom.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom.h"
#include "services/ui/public/interfaces/window_tree.mojom-shared.h"
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
#include "ui/platform_window/mojo/text_input_state.mojom.h"
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    class WindowTree;
    using WindowTreePtr = mojo::InterfacePtr<WindowTree>;
    using WindowTreePtrInfo = mojo::InterfacePtrInfo<WindowTree>;
    using ThreadSafeWindowTreePtr = mojo::ThreadSafeInterfacePtr<WindowTree>;
    using WindowTreeRequest = mojo::InterfaceRequest<WindowTree>;
    using WindowTreeAssociatedPtr = mojo::AssociatedInterfacePtr<WindowTree>;
    using ThreadSafeWindowTreeAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WindowTree>;
    using WindowTreeAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WindowTree>;
    using WindowTreeAssociatedRequest = mojo::AssociatedInterfaceRequest<WindowTree>;

    class WindowTreeClient;
    using WindowTreeClientPtr = mojo::InterfacePtr<WindowTreeClient>;
    using WindowTreeClientPtrInfo = mojo::InterfacePtrInfo<WindowTreeClient>;
    using ThreadSafeWindowTreeClientPtr = mojo::ThreadSafeInterfacePtr<WindowTreeClient>;
    using WindowTreeClientRequest = mojo::InterfaceRequest<WindowTreeClient>;
    using WindowTreeClientAssociatedPtr = mojo::AssociatedInterfacePtr<WindowTreeClient>;
    using ThreadSafeWindowTreeClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WindowTreeClient>;
    using WindowTreeClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WindowTreeClient>;
    using WindowTreeClientAssociatedRequest = mojo::AssociatedInterfaceRequest<WindowTreeClient>;

    class WindowTreeFactory;
    using WindowTreeFactoryPtr = mojo::InterfacePtr<WindowTreeFactory>;
    using WindowTreeFactoryPtrInfo = mojo::InterfacePtrInfo<WindowTreeFactory>;
    using ThreadSafeWindowTreeFactoryPtr = mojo::ThreadSafeInterfacePtr<WindowTreeFactory>;
    using WindowTreeFactoryRequest = mojo::InterfaceRequest<WindowTreeFactory>;
    using WindowTreeFactoryAssociatedPtr = mojo::AssociatedInterfacePtr<WindowTreeFactory>;
    using ThreadSafeWindowTreeFactoryAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WindowTreeFactory>;
    using WindowTreeFactoryAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WindowTreeFactory>;
    using WindowTreeFactoryAssociatedRequest = mojo::AssociatedInterfaceRequest<WindowTreeFactory>;

    class WindowTreeProxy;

    template <typename ImplRefTraits>
    class WindowTreeStub;

    class WindowTreeRequestValidator;
    class WindowTreeResponseValidator;

    class WindowTree
        : public WindowTreeInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = WindowTreeProxy;

        template <typename ImplRefTraits>
        using Stub_ = WindowTreeStub<ImplRefTraits>;

        using RequestValidator_ = WindowTreeRequestValidator;
        using ResponseValidator_ = WindowTreeResponseValidator;
        enum MethodMinVersions : uint32_t {
            kNewWindowMinVersion = 0,
            kNewTopLevelWindowMinVersion = 0,
            kDeleteWindowMinVersion = 0,
            kSetCaptureMinVersion = 0,
            kReleaseCaptureMinVersion = 0,
            kStartPointerWatcherMinVersion = 0,
            kStopPointerWatcherMinVersion = 0,
            kSetWindowBoundsMinVersion = 0,
            kSetClientAreaMinVersion = 0,
            kSetHitTestMaskMinVersion = 0,
            kSetCanAcceptDropsMinVersion = 0,
            kSetWindowVisibilityMinVersion = 0,
            kSetWindowPropertyMinVersion = 0,
            kSetWindowOpacityMinVersion = 0,
            kAttachCompositorFrameSinkMinVersion = 0,
            kAddWindowMinVersion = 0,
            kRemoveWindowFromParentMinVersion = 0,
            kAddTransientWindowMinVersion = 0,
            kRemoveTransientWindowFromParentMinVersion = 0,
            kSetModalMinVersion = 0,
            kReorderWindowMinVersion = 0,
            kGetWindowTreeMinVersion = 0,
            kEmbedMinVersion = 0,
            kSetFocusMinVersion = 0,
            kSetCanFocusMinVersion = 0,
            kSetPredefinedCursorMinVersion = 0,
            kSetWindowTextInputStateMinVersion = 0,
            kSetImeVisibilityMinVersion = 0,
            kSetCanAcceptEventsMinVersion = 0,
            kOnWindowInputEventAckMinVersion = 0,
            kDeactivateWindowMinVersion = 0,
            kGetWindowManagerClientMinVersion = 0,
            kGetCursorLocationMemoryMinVersion = 0,
            kPerformWindowMoveMinVersion = 0,
            kCancelWindowMoveMinVersion = 0,
            kPerformDragDropMinVersion = 0,
            kCancelDragDropMinVersion = 0,
        };
        virtual ~WindowTree() { }

        virtual void NewWindow(uint32_t change_id, uint32_t window_id, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& properties) = 0;

        virtual void NewTopLevelWindow(uint32_t change_id, uint32_t window_id, const std::unordered_map<std::string, std::vector<uint8_t>>& properties) = 0;

        virtual void DeleteWindow(uint32_t change_id, uint32_t window_id) = 0;

        virtual void SetCapture(uint32_t change_id, uint32_t window_id) = 0;

        virtual void ReleaseCapture(uint32_t change_id, uint32_t window_id) = 0;

        virtual void StartPointerWatcher(bool want_moves) = 0;

        virtual void StopPointerWatcher() = 0;

        virtual void SetWindowBounds(uint32_t change_id, uint32_t window_id, const gfx::Rect& bounds) = 0;

        virtual void SetClientArea(uint32_t window_id, const gfx::Insets& insets, const base::Optional<std::vector<gfx::Rect>>& additional_client_areas) = 0;

        virtual void SetHitTestMask(uint32_t window_id, const base::Optional<gfx::Rect>& mask) = 0;

        virtual void SetCanAcceptDrops(uint32_t window_id, bool accepts_drops) = 0;

        virtual void SetWindowVisibility(uint32_t change_id, uint32_t window_id, bool visible) = 0;

        virtual void SetWindowProperty(uint32_t change_id, uint32_t window_id, const std::string& name, const base::Optional<std::vector<uint8_t>>& value) = 0;

        virtual void SetWindowOpacity(uint32_t change_id, uint32_t window_id, float opacity) = 0;

        virtual void AttachCompositorFrameSink(uint32_t window_id, ::cc::mojom::MojoCompositorFrameSinkRequest compositor_frame_sink, ::cc::mojom::MojoCompositorFrameSinkClientPtr client) = 0;

        virtual void AddWindow(uint32_t change_id, uint32_t parent, uint32_t child) = 0;

        virtual void RemoveWindowFromParent(uint32_t change_id, uint32_t window_id) = 0;

        virtual void AddTransientWindow(uint32_t change_id, uint32_t window_id, uint32_t transient_window_id) = 0;

        virtual void RemoveTransientWindowFromParent(uint32_t change_id, uint32_t transient_window_id) = 0;

        virtual void SetModal(uint32_t change_id, uint32_t window_id) = 0;

        virtual void ReorderWindow(uint32_t change_id, uint32_t window_id, uint32_t relative_window_id, ::ui::mojom::OrderDirection direction) = 0;

        using GetWindowTreeCallback = base::Callback<void(std::vector<::ui::mojom::WindowDataPtr>)>;
        virtual void GetWindowTree(uint32_t window_id, const GetWindowTreeCallback& callback) = 0;

        using EmbedCallback = base::Callback<void(bool)>;
        virtual void Embed(uint32_t window_id, WindowTreeClientPtr client, uint32_t embed_flags, const EmbedCallback& callback) = 0;

        virtual void SetFocus(uint32_t change_id, uint32_t window_id) = 0;

        virtual void SetCanFocus(uint32_t window_id, bool can_focus) = 0;

        virtual void SetPredefinedCursor(uint32_t change_id, uint32_t window_id, ::ui::mojom::Cursor cursor_id) = 0;

        virtual void SetWindowTextInputState(uint32_t window_id, ::mojo::TextInputStatePtr state) = 0;

        virtual void SetImeVisibility(uint32_t window_id, bool visible, ::mojo::TextInputStatePtr state) = 0;

        virtual void SetCanAcceptEvents(uint32_t window_id, bool accept_events) = 0;

        virtual void OnWindowInputEventAck(uint32_t event_id, ::ui::mojom::EventResult result) = 0;

        virtual void DeactivateWindow(uint32_t window_id) = 0;

        virtual void GetWindowManagerClient(::ui::mojom::WindowManagerClientAssociatedRequest internal) = 0;

        using GetCursorLocationMemoryCallback = base::Callback<void(mojo::ScopedSharedBufferHandle)>;
        virtual void GetCursorLocationMemory(const GetCursorLocationMemoryCallback& callback) = 0;

        virtual void PerformWindowMove(uint32_t change_id, uint32_t window_id, ::ui::mojom::MoveLoopSource source, const gfx::Point& cursor) = 0;

        virtual void CancelWindowMove(uint32_t window_id) = 0;

        virtual void PerformDragDrop(uint32_t change_id, uint32_t source_window_id, const std::unordered_map<std::string, std::vector<uint8_t>>& drag_data, uint32_t drag_operation) = 0;

        virtual void CancelDragDrop(uint32_t window_id) = 0;
    };

    class WindowTreeClientProxy;

    template <typename ImplRefTraits>
    class WindowTreeClientStub;

    class WindowTreeClientRequestValidator;
    class WindowTreeClientResponseValidator;

    class WindowTreeClient
        : public WindowTreeClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = WindowTreeClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = WindowTreeClientStub<ImplRefTraits>;

        using RequestValidator_ = WindowTreeClientRequestValidator;
        using ResponseValidator_ = WindowTreeClientResponseValidator;
        enum MethodMinVersions : uint32_t {
            kOnEmbedMinVersion = 0,
            kOnEmbeddedAppDisconnectedMinVersion = 0,
            kOnUnembedMinVersion = 0,
            kOnCaptureChangedMinVersion = 0,
            kOnTopLevelCreatedMinVersion = 0,
            kOnWindowBoundsChangedMinVersion = 0,
            kOnClientAreaChangedMinVersion = 0,
            kOnTransientWindowAddedMinVersion = 0,
            kOnTransientWindowRemovedMinVersion = 0,
            kOnWindowHierarchyChangedMinVersion = 0,
            kOnWindowReorderedMinVersion = 0,
            kOnWindowDeletedMinVersion = 0,
            kOnWindowVisibilityChangedMinVersion = 0,
            kOnWindowOpacityChangedMinVersion = 0,
            kOnWindowParentDrawnStateChangedMinVersion = 0,
            kOnWindowSharedPropertyChangedMinVersion = 0,
            kOnWindowInputEventMinVersion = 0,
            kOnPointerEventObservedMinVersion = 0,
            kOnWindowFocusedMinVersion = 0,
            kOnWindowPredefinedCursorChangedMinVersion = 0,
            kOnWindowSurfaceChangedMinVersion = 0,
            kOnDragDropStartMinVersion = 0,
            kOnDragEnterMinVersion = 0,
            kOnDragOverMinVersion = 0,
            kOnDragLeaveMinVersion = 0,
            kOnCompleteDropMinVersion = 0,
            kOnPerformDragDropCompletedMinVersion = 0,
            kOnDragDropDoneMinVersion = 0,
            kOnChangeCompletedMinVersion = 0,
            kRequestCloseMinVersion = 0,
            kGetWindowManagerMinVersion = 0,
        };
        virtual ~WindowTreeClient() { }

        virtual void OnEmbed(uint16_t connection_id, ::ui::mojom::WindowDataPtr root, WindowTreePtr tree, int64_t display_id, uint32_t focused_window, bool parent_drawn) = 0;

        virtual void OnEmbeddedAppDisconnected(uint32_t window) = 0;

        virtual void OnUnembed(uint32_t window) = 0;

        virtual void OnCaptureChanged(uint32_t new_capture, uint32_t old_capture) = 0;

        virtual void OnTopLevelCreated(uint32_t change_id, ::ui::mojom::WindowDataPtr data, int64_t display_id, bool parent_drawn) = 0;

        virtual void OnWindowBoundsChanged(uint32_t window, const gfx::Rect& old_bounds, const gfx::Rect& new_bounds) = 0;

        virtual void OnClientAreaChanged(uint32_t window_id, const gfx::Insets& new_client_area, const std::vector<gfx::Rect>& new_additional_client_areas) = 0;

        virtual void OnTransientWindowAdded(uint32_t window_id, uint32_t transient_window_id) = 0;

        virtual void OnTransientWindowRemoved(uint32_t window_id, uint32_t transient_window_id) = 0;

        virtual void OnWindowHierarchyChanged(uint32_t window, uint32_t old_parent, uint32_t new_parent, std::vector<::ui::mojom::WindowDataPtr> windows) = 0;

        virtual void OnWindowReordered(uint32_t window_id, uint32_t relative_window_id, ::ui::mojom::OrderDirection direction) = 0;

        virtual void OnWindowDeleted(uint32_t window) = 0;

        virtual void OnWindowVisibilityChanged(uint32_t window, bool visible) = 0;

        virtual void OnWindowOpacityChanged(uint32_t window, float old_opacity, float new_opacity) = 0;

        virtual void OnWindowParentDrawnStateChanged(uint32_t window, bool drawn) = 0;

        virtual void OnWindowSharedPropertyChanged(uint32_t window, const std::string& name, const base::Optional<std::vector<uint8_t>>& new_data) = 0;

        virtual void OnWindowInputEvent(uint32_t event_id, uint32_t window, std::unique_ptr<ui::Event> event, bool matches_pointer_watcher) = 0;

        virtual void OnPointerEventObserved(std::unique_ptr<ui::Event> event, uint32_t window_id) = 0;

        virtual void OnWindowFocused(uint32_t focused_window_id) = 0;

        virtual void OnWindowPredefinedCursorChanged(uint32_t window_id, ::ui::mojom::Cursor cursor_id) = 0;

        virtual void OnWindowSurfaceChanged(uint32_t window_id, const cc::SurfaceInfo& surface_info) = 0;

        virtual void OnDragDropStart(const std::unordered_map<std::string, std::vector<uint8_t>>& drag_data) = 0;

        using OnDragEnterCallback = base::Callback<void(uint32_t)>;
        virtual void OnDragEnter(uint32_t window, uint32_t key_state, const gfx::Point& screen_position, uint32_t effect_bitmask, const OnDragEnterCallback& callback) = 0;

        using OnDragOverCallback = base::Callback<void(uint32_t)>;
        virtual void OnDragOver(uint32_t window, uint32_t key_state, const gfx::Point& screen_position, uint32_t effect_bitmask, const OnDragOverCallback& callback) = 0;

        virtual void OnDragLeave(uint32_t window) = 0;

        using OnCompleteDropCallback = base::Callback<void(uint32_t)>;
        virtual void OnCompleteDrop(uint32_t window, uint32_t key_state, const gfx::Point& screen_position, uint32_t effect_bitmask, const OnCompleteDropCallback& callback) = 0;

        virtual void OnPerformDragDropCompleted(uint32_t window, bool success, uint32_t action_taken) = 0;

        virtual void OnDragDropDone() = 0;

        virtual void OnChangeCompleted(uint32_t change_id, bool success) = 0;

        virtual void RequestClose(uint32_t window_id) = 0;

        virtual void GetWindowManager(::ui::mojom::WindowManagerAssociatedRequest internal) = 0;
    };

    class WindowTreeFactoryProxy;

    template <typename ImplRefTraits>
    class WindowTreeFactoryStub;

    class WindowTreeFactoryRequestValidator;

    class WindowTreeFactory
        : public WindowTreeFactoryInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = WindowTreeFactoryProxy;

        template <typename ImplRefTraits>
        using Stub_ = WindowTreeFactoryStub<ImplRefTraits>;

        using RequestValidator_ = WindowTreeFactoryRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kCreateWindowTreeMinVersion = 0,
        };
        virtual ~WindowTreeFactory() { }

        virtual void CreateWindowTree(WindowTreeRequest tree_request, WindowTreeClientPtr client) = 0;
    };

    class WindowTreeProxy
        : public WindowTree {
    public:
        explicit WindowTreeProxy(mojo::MessageReceiverWithResponder* receiver);
        void NewWindow(uint32_t change_id, uint32_t window_id, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& properties) override;
        void NewTopLevelWindow(uint32_t change_id, uint32_t window_id, const std::unordered_map<std::string, std::vector<uint8_t>>& properties) override;
        void DeleteWindow(uint32_t change_id, uint32_t window_id) override;
        void SetCapture(uint32_t change_id, uint32_t window_id) override;
        void ReleaseCapture(uint32_t change_id, uint32_t window_id) override;
        void StartPointerWatcher(bool want_moves) override;
        void StopPointerWatcher() override;
        void SetWindowBounds(uint32_t change_id, uint32_t window_id, const gfx::Rect& bounds) override;
        void SetClientArea(uint32_t window_id, const gfx::Insets& insets, const base::Optional<std::vector<gfx::Rect>>& additional_client_areas) override;
        void SetHitTestMask(uint32_t window_id, const base::Optional<gfx::Rect>& mask) override;
        void SetCanAcceptDrops(uint32_t window_id, bool accepts_drops) override;
        void SetWindowVisibility(uint32_t change_id, uint32_t window_id, bool visible) override;
        void SetWindowProperty(uint32_t change_id, uint32_t window_id, const std::string& name, const base::Optional<std::vector<uint8_t>>& value) override;
        void SetWindowOpacity(uint32_t change_id, uint32_t window_id, float opacity) override;
        void AttachCompositorFrameSink(uint32_t window_id, ::cc::mojom::MojoCompositorFrameSinkRequest compositor_frame_sink, ::cc::mojom::MojoCompositorFrameSinkClientPtr client) override;
        void AddWindow(uint32_t change_id, uint32_t parent, uint32_t child) override;
        void RemoveWindowFromParent(uint32_t change_id, uint32_t window_id) override;
        void AddTransientWindow(uint32_t change_id, uint32_t window_id, uint32_t transient_window_id) override;
        void RemoveTransientWindowFromParent(uint32_t change_id, uint32_t transient_window_id) override;
        void SetModal(uint32_t change_id, uint32_t window_id) override;
        void ReorderWindow(uint32_t change_id, uint32_t window_id, uint32_t relative_window_id, ::ui::mojom::OrderDirection direction) override;
        void GetWindowTree(uint32_t window_id, const GetWindowTreeCallback& callback) override;
        void Embed(uint32_t window_id, WindowTreeClientPtr client, uint32_t embed_flags, const EmbedCallback& callback) override;
        void SetFocus(uint32_t change_id, uint32_t window_id) override;
        void SetCanFocus(uint32_t window_id, bool can_focus) override;
        void SetPredefinedCursor(uint32_t change_id, uint32_t window_id, ::ui::mojom::Cursor cursor_id) override;
        void SetWindowTextInputState(uint32_t window_id, ::mojo::TextInputStatePtr state) override;
        void SetImeVisibility(uint32_t window_id, bool visible, ::mojo::TextInputStatePtr state) override;
        void SetCanAcceptEvents(uint32_t window_id, bool accept_events) override;
        void OnWindowInputEventAck(uint32_t event_id, ::ui::mojom::EventResult result) override;
        void DeactivateWindow(uint32_t window_id) override;
        void GetWindowManagerClient(::ui::mojom::WindowManagerClientAssociatedRequest internal) override;
        void GetCursorLocationMemory(const GetCursorLocationMemoryCallback& callback) override;
        void PerformWindowMove(uint32_t change_id, uint32_t window_id, ::ui::mojom::MoveLoopSource source, const gfx::Point& cursor) override;
        void CancelWindowMove(uint32_t window_id) override;
        void PerformDragDrop(uint32_t change_id, uint32_t source_window_id, const std::unordered_map<std::string, std::vector<uint8_t>>& drag_data, uint32_t drag_operation) override;
        void CancelDragDrop(uint32_t window_id) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class WindowTreeClientProxy
        : public WindowTreeClient {
    public:
        explicit WindowTreeClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnEmbed(uint16_t connection_id, ::ui::mojom::WindowDataPtr root, WindowTreePtr tree, int64_t display_id, uint32_t focused_window, bool parent_drawn) override;
        void OnEmbeddedAppDisconnected(uint32_t window) override;
        void OnUnembed(uint32_t window) override;
        void OnCaptureChanged(uint32_t new_capture, uint32_t old_capture) override;
        void OnTopLevelCreated(uint32_t change_id, ::ui::mojom::WindowDataPtr data, int64_t display_id, bool parent_drawn) override;
        void OnWindowBoundsChanged(uint32_t window, const gfx::Rect& old_bounds, const gfx::Rect& new_bounds) override;
        void OnClientAreaChanged(uint32_t window_id, const gfx::Insets& new_client_area, const std::vector<gfx::Rect>& new_additional_client_areas) override;
        void OnTransientWindowAdded(uint32_t window_id, uint32_t transient_window_id) override;
        void OnTransientWindowRemoved(uint32_t window_id, uint32_t transient_window_id) override;
        void OnWindowHierarchyChanged(uint32_t window, uint32_t old_parent, uint32_t new_parent, std::vector<::ui::mojom::WindowDataPtr> windows) override;
        void OnWindowReordered(uint32_t window_id, uint32_t relative_window_id, ::ui::mojom::OrderDirection direction) override;
        void OnWindowDeleted(uint32_t window) override;
        void OnWindowVisibilityChanged(uint32_t window, bool visible) override;
        void OnWindowOpacityChanged(uint32_t window, float old_opacity, float new_opacity) override;
        void OnWindowParentDrawnStateChanged(uint32_t window, bool drawn) override;
        void OnWindowSharedPropertyChanged(uint32_t window, const std::string& name, const base::Optional<std::vector<uint8_t>>& new_data) override;
        void OnWindowInputEvent(uint32_t event_id, uint32_t window, std::unique_ptr<ui::Event> event, bool matches_pointer_watcher) override;
        void OnPointerEventObserved(std::unique_ptr<ui::Event> event, uint32_t window_id) override;
        void OnWindowFocused(uint32_t focused_window_id) override;
        void OnWindowPredefinedCursorChanged(uint32_t window_id, ::ui::mojom::Cursor cursor_id) override;
        void OnWindowSurfaceChanged(uint32_t window_id, const cc::SurfaceInfo& surface_info) override;
        void OnDragDropStart(const std::unordered_map<std::string, std::vector<uint8_t>>& drag_data) override;
        void OnDragEnter(uint32_t window, uint32_t key_state, const gfx::Point& screen_position, uint32_t effect_bitmask, const OnDragEnterCallback& callback) override;
        void OnDragOver(uint32_t window, uint32_t key_state, const gfx::Point& screen_position, uint32_t effect_bitmask, const OnDragOverCallback& callback) override;
        void OnDragLeave(uint32_t window) override;
        void OnCompleteDrop(uint32_t window, uint32_t key_state, const gfx::Point& screen_position, uint32_t effect_bitmask, const OnCompleteDropCallback& callback) override;
        void OnPerformDragDropCompleted(uint32_t window, bool success, uint32_t action_taken) override;
        void OnDragDropDone() override;
        void OnChangeCompleted(uint32_t change_id, bool success) override;
        void RequestClose(uint32_t window_id) override;
        void GetWindowManager(::ui::mojom::WindowManagerAssociatedRequest internal) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class WindowTreeFactoryProxy
        : public WindowTreeFactory {
    public:
        explicit WindowTreeFactoryProxy(mojo::MessageReceiverWithResponder* receiver);
        void CreateWindowTree(WindowTreeRequest tree_request, WindowTreeClientPtr client) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class WindowTreeStubDispatch {
    public:
        static bool Accept(WindowTree* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(WindowTree* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WindowTree>>
    class WindowTreeStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        WindowTreeStub() { }
        ~WindowTreeStub() override { }

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
            return WindowTreeStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return WindowTreeStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class WindowTreeClientStubDispatch {
    public:
        static bool Accept(WindowTreeClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(WindowTreeClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WindowTreeClient>>
    class WindowTreeClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        WindowTreeClientStub() { }
        ~WindowTreeClientStub() override { }

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
            return WindowTreeClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return WindowTreeClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class WindowTreeFactoryStubDispatch {
    public:
        static bool Accept(WindowTreeFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(WindowTreeFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WindowTreeFactory>>
    class WindowTreeFactoryStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        WindowTreeFactoryStub() { }
        ~WindowTreeFactoryStub() override { }

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
            return WindowTreeFactoryStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return WindowTreeFactoryStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class WindowTreeRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class WindowTreeClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class WindowTreeFactoryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class WindowTreeResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class WindowTreeClientResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace ui

namespace mojo {

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_MOJOM_H_