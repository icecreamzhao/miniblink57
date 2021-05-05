// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "services/ui/public/interfaces/window_manager.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "cc/ipc/begin_frame_args_struct_traits.h"
#include "cc/ipc/compositor_frame_metadata_struct_traits.h"
#include "cc/ipc/compositor_frame_struct_traits.h"
#include "cc/ipc/filter_operation_struct_traits.h"
#include "cc/ipc/filter_operations_struct_traits.h"
#include "cc/ipc/frame_sink_id_struct_traits.h"
#include "cc/ipc/local_frame_id_struct_traits.h"
#include "cc/ipc/quads_struct_traits.h"
#include "cc/ipc/render_pass_struct_traits.h"
#include "cc/ipc/returned_resource_struct_traits.h"
#include "cc/ipc/selection_struct_traits.h"
#include "cc/ipc/shared_quad_state_struct_traits.h"
#include "cc/ipc/surface_id_struct_traits.h"
#include "cc/ipc/surface_info_struct_traits.h"
#include "cc/ipc/surface_reference_struct_traits.h"
#include "cc/ipc/surface_sequence_struct_traits.h"
#include "cc/ipc/transferable_resource_struct_traits.h"
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "services/ui/public/interfaces/ime/ime_struct_traits.h"
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "ui/events/mojo/event_struct_traits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
#include "ui/gfx/range/mojo/range_struct_traits.h"
namespace ui {
namespace mojom { // static
    AcceleratorPtr Accelerator::New()
    {
        AcceleratorPtr rv;
        mojo::internal::StructHelper<Accelerator>::Initialize(&rv);
        return rv;
    }

    Accelerator::Accelerator()
        : id()
        , event_matcher()
    {
    }

    Accelerator::~Accelerator()
    {
    }
    const char WindowManager::Name_[] = "ui::mojom::WindowManager";
    const char WindowManager::kBounds_InitProperty[] = "init:bounds";
    const char WindowManager::kContainerId_InitProperty[] = "init:container_id";
    const char WindowManager::kDisableImmersive_InitProperty[] = "init:disable_immersive";
    const char WindowManager::kDisplayId_InitProperty[] = "init:display_id";
    const char WindowManager::kRemoveStandardFrame_InitProperty[] = "init:remove-standard-frame";
    const char WindowManager::kWindowType_InitProperty[] = "init:window-type";
    const char WindowManager::kAlwaysOnTop_Property[] = "prop:always_on_top";
    const char WindowManager::kAppIcon_Property[] = "prop:app-icon";
    const char WindowManager::kAppID_Property[] = "prop:app-id";
    const char WindowManager::kExcludeFromMru_Property[] = "prop:exclude_from_mru";
    const char WindowManager::kName_Property[] = "prop:name";
    const char WindowManager::kPanelAttached_Property[] = "prop:panel-attached";
    const char WindowManager::kPreferredSize_Property[] = "prop:preferred-size";
    const char WindowManager::kRenderParentTitleArea_Property[] = "render-parent-non-client-area";
    const char WindowManager::kResizeBehavior_Property[] = "prop:resize-behavior";
    const char WindowManager::kRestoreBounds_Property[] = "prop:restore-bounds";
    const char WindowManager::kShelfItemType_Property[] = "prop:shelf-item-type";
    const char WindowManager::kShowState_Property[] = "prop:show-state";
    const char WindowManager::kWindowIcon_Property[] = "prop:window-icon";
    const char WindowManager::kWindowIgnoredByShelf_Property[] = "prop:window-ignored-by-shelf";
    const char WindowManager::kWindowTitle_Property[] = "prop:window-title";
    const char WindowManager::kShadowStyle_Property[] = "prop:shadow-style";

    WindowManagerProxy::WindowManagerProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void WindowManagerProxy::OnConnect(
        uint16_t in_client_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_OnConnect_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_OnConnect_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_OnConnect_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->client_id = in_client_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmNewDisplayAdded(
        const display::Display& in_display, ::ui::mojom::WindowDataPtr in_root, bool in_parent_drawn)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmNewDisplayAdded_Params_Data);
        size += mojo::internal::PrepareToSerialize<::display::mojom::DisplayDataView>(
            in_display, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::WindowDataDataView>(
            in_root, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmNewDisplayAdded_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmNewDisplayAdded_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->display)::BaseType* display_ptr;
        mojo::internal::Serialize<::display::mojom::DisplayDataView>(
            in_display, builder.buffer(), &display_ptr, &serialization_context);
        params->display.Set(display_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->display.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null display in WindowManager.WmNewDisplayAdded request");
        typename decltype(params->root)::BaseType* root_ptr;
        mojo::internal::Serialize<::ui::mojom::WindowDataDataView>(
            in_root, builder.buffer(), &root_ptr, &serialization_context);
        params->root.Set(root_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->root.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null root in WindowManager.WmNewDisplayAdded request");
        params->parent_drawn = in_parent_drawn;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmDisplayRemoved(
        int64_t in_display_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmDisplayRemoved_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmDisplayRemoved_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmDisplayRemoved_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->display_id = in_display_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmDisplayModified(
        const display::Display& in_display)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmDisplayModified_Params_Data);
        size += mojo::internal::PrepareToSerialize<::display::mojom::DisplayDataView>(
            in_display, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmDisplayModified_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmDisplayModified_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->display)::BaseType* display_ptr;
        mojo::internal::Serialize<::display::mojom::DisplayDataView>(
            in_display, builder.buffer(), &display_ptr, &serialization_context);
        params->display.Set(display_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->display.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null display in WindowManager.WmDisplayModified request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmSetBounds(
        uint32_t in_change_id, uint32_t in_window_id, const gfx::Rect& in_bounds)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmSetBounds_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
            in_bounds, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmSetBounds_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmSetBounds_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        typename decltype(params->bounds)::BaseType* bounds_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectDataView>(
            in_bounds, builder.buffer(), &bounds_ptr, &serialization_context);
        params->bounds.Set(bounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->bounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null bounds in WindowManager.WmSetBounds request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmSetProperty(
        uint32_t in_change_id, uint32_t in_window_id, const std::string& in_name, const base::Optional<std::vector<uint8_t>>& in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmSetProperty_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_name, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmSetProperty_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmSetProperty_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        typename decltype(params->name)::BaseType* name_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_name, builder.buffer(), &name_ptr, &serialization_context);
        params->name.Set(name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null name in WindowManager.WmSetProperty request");
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context);
        params->value.Set(value_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmCreateTopLevelWindow(
        uint32_t in_change_id, uint16_t in_requesting_client_id, const std::unordered_map<std::string, std::vector<uint8_t>>& in_properties)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmCreateTopLevelWindow_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_properties, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmCreateTopLevelWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmCreateTopLevelWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->requesting_client_id = in_requesting_client_id;
        typename decltype(params->properties)::BaseType* properties_ptr;
        const mojo::internal::ContainerValidateParams properties_validate_params(
            new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
        mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_properties, builder.buffer(), &properties_ptr, &properties_validate_params,
            &serialization_context);
        params->properties.Set(properties_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->properties.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null properties in WindowManager.WmCreateTopLevelWindow request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmClientJankinessChanged(
        uint16_t in_client_id, bool in_janky)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmClientJankinessChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmClientJankinessChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmClientJankinessChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->client_id = in_client_id;
        params->janky = in_janky;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmPerformMoveLoop(
        uint32_t in_change_id, uint32_t in_window_id, ::ui::mojom::MoveLoopSource in_source, const gfx::Point& in_cursor_location)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmPerformMoveLoop_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointDataView>(
            in_cursor_location, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmPerformMoveLoop_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmPerformMoveLoop_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        mojo::internal::Serialize<::ui::mojom::MoveLoopSource>(
            in_source, &params->source);
        typename decltype(params->cursor_location)::BaseType* cursor_location_ptr;
        mojo::internal::Serialize<::gfx::mojom::PointDataView>(
            in_cursor_location, builder.buffer(), &cursor_location_ptr, &serialization_context);
        params->cursor_location.Set(cursor_location_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->cursor_location.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null cursor_location in WindowManager.WmPerformMoveLoop request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmCancelMoveLoop(
        uint32_t in_change_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmCancelMoveLoop_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmCancelMoveLoop_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmCancelMoveLoop_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::WmDeactivateWindow(
        uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_WmDeactivateWindow_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_WmDeactivateWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_WmDeactivateWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerProxy::OnAccelerator(
        uint32_t in_ack_id, uint32_t in_accelerator_id, std::unique_ptr<ui::Event> in_event)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManager_OnAccelerator_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::EventDataView>(
            in_event, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowManager_OnAccelerator_Name, size);

        auto params = ::ui::mojom::internal::WindowManager_OnAccelerator_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->ack_id = in_ack_id;
        params->accelerator_id = in_accelerator_id;
        typename decltype(params->event)::BaseType* event_ptr;
        mojo::internal::Serialize<::ui::mojom::EventDataView>(
            in_event, builder.buffer(), &event_ptr, &serialization_context);
        params->event.Set(event_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->event.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null event in WindowManager.OnAccelerator request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool WindowManagerStubDispatch::Accept(
        WindowManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kWindowManager_OnConnect_Name: {
            internal::WindowManager_OnConnect_Params_Data* params = reinterpret_cast<internal::WindowManager_OnConnect_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint16_t p_client_id {};
            WindowManager_OnConnect_ParamsDataView input_data_view(params,
                context);

            p_client_id = input_data_view.client_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::OnConnect deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::OnConnect");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnConnect(
                std::move(p_client_id));
            return true;
        }
        case internal::kWindowManager_WmNewDisplayAdded_Name: {
            internal::WindowManager_WmNewDisplayAdded_Params_Data* params = reinterpret_cast<internal::WindowManager_WmNewDisplayAdded_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            display::Display p_display {};
            ::ui::mojom::WindowDataPtr p_root {};
            bool p_parent_drawn {};
            WindowManager_WmNewDisplayAdded_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDisplay(&p_display))
                success = false;
            if (!input_data_view.ReadRoot(&p_root))
                success = false;
            p_parent_drawn = input_data_view.parent_drawn();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmNewDisplayAdded deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmNewDisplayAdded");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmNewDisplayAdded(
                std::move(p_display),
                std::move(p_root),
                std::move(p_parent_drawn));
            return true;
        }
        case internal::kWindowManager_WmDisplayRemoved_Name: {
            internal::WindowManager_WmDisplayRemoved_Params_Data* params = reinterpret_cast<internal::WindowManager_WmDisplayRemoved_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_display_id {};
            WindowManager_WmDisplayRemoved_ParamsDataView input_data_view(params,
                context);

            p_display_id = input_data_view.display_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmDisplayRemoved deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmDisplayRemoved");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmDisplayRemoved(
                std::move(p_display_id));
            return true;
        }
        case internal::kWindowManager_WmDisplayModified_Name: {
            internal::WindowManager_WmDisplayModified_Params_Data* params = reinterpret_cast<internal::WindowManager_WmDisplayModified_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            display::Display p_display {};
            WindowManager_WmDisplayModified_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDisplay(&p_display))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmDisplayModified deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmDisplayModified");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmDisplayModified(
                std::move(p_display));
            return true;
        }
        case internal::kWindowManager_WmSetBounds_Name: {
            internal::WindowManager_WmSetBounds_Params_Data* params = reinterpret_cast<internal::WindowManager_WmSetBounds_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            gfx::Rect p_bounds {};
            WindowManager_WmSetBounds_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadBounds(&p_bounds))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmSetBounds deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmSetBounds");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmSetBounds(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_bounds));
            return true;
        }
        case internal::kWindowManager_WmSetProperty_Name: {
            internal::WindowManager_WmSetProperty_Params_Data* params = reinterpret_cast<internal::WindowManager_WmSetProperty_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            std::string p_name {};
            base::Optional<std::vector<uint8_t>> p_value {};
            WindowManager_WmSetProperty_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadName(&p_name))
                success = false;
            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmSetProperty deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmSetProperty");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmSetProperty(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_name),
                std::move(p_value));
            return true;
        }
        case internal::kWindowManager_WmCreateTopLevelWindow_Name: {
            internal::WindowManager_WmCreateTopLevelWindow_Params_Data* params = reinterpret_cast<internal::WindowManager_WmCreateTopLevelWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint16_t p_requesting_client_id {};
            std::unordered_map<std::string, std::vector<uint8_t>> p_properties {};
            WindowManager_WmCreateTopLevelWindow_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_requesting_client_id = input_data_view.requesting_client_id();
            if (!input_data_view.ReadProperties(&p_properties))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmCreateTopLevelWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmCreateTopLevelWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmCreateTopLevelWindow(
                std::move(p_change_id),
                std::move(p_requesting_client_id),
                std::move(p_properties));
            return true;
        }
        case internal::kWindowManager_WmClientJankinessChanged_Name: {
            internal::WindowManager_WmClientJankinessChanged_Params_Data* params = reinterpret_cast<internal::WindowManager_WmClientJankinessChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint16_t p_client_id {};
            bool p_janky {};
            WindowManager_WmClientJankinessChanged_ParamsDataView input_data_view(params,
                context);

            p_client_id = input_data_view.client_id();
            p_janky = input_data_view.janky();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmClientJankinessChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmClientJankinessChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmClientJankinessChanged(
                std::move(p_client_id),
                std::move(p_janky));
            return true;
        }
        case internal::kWindowManager_WmPerformMoveLoop_Name: {
            internal::WindowManager_WmPerformMoveLoop_Params_Data* params = reinterpret_cast<internal::WindowManager_WmPerformMoveLoop_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            ::ui::mojom::MoveLoopSource p_source {};
            gfx::Point p_cursor_location {};
            WindowManager_WmPerformMoveLoop_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadSource(&p_source))
                success = false;
            if (!input_data_view.ReadCursorLocation(&p_cursor_location))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmPerformMoveLoop deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmPerformMoveLoop");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmPerformMoveLoop(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_source),
                std::move(p_cursor_location));
            return true;
        }
        case internal::kWindowManager_WmCancelMoveLoop_Name: {
            internal::WindowManager_WmCancelMoveLoop_Params_Data* params = reinterpret_cast<internal::WindowManager_WmCancelMoveLoop_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            WindowManager_WmCancelMoveLoop_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmCancelMoveLoop deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmCancelMoveLoop");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmCancelMoveLoop(
                std::move(p_change_id));
            return true;
        }
        case internal::kWindowManager_WmDeactivateWindow_Name: {
            internal::WindowManager_WmDeactivateWindow_Params_Data* params = reinterpret_cast<internal::WindowManager_WmDeactivateWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowManager_WmDeactivateWindow_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::WmDeactivateWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::WmDeactivateWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmDeactivateWindow(
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowManager_OnAccelerator_Name: {
            internal::WindowManager_OnAccelerator_Params_Data* params = reinterpret_cast<internal::WindowManager_OnAccelerator_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_ack_id {};
            uint32_t p_accelerator_id {};
            std::unique_ptr<ui::Event> p_event {};
            WindowManager_OnAccelerator_ParamsDataView input_data_view(params,
                context);

            p_ack_id = input_data_view.ack_id();
            p_accelerator_id = input_data_view.accelerator_id();
            if (!input_data_view.ReadEvent(&p_event))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManager::OnAccelerator deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManager::OnAccelerator");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnAccelerator(
                std::move(p_ack_id),
                std::move(p_accelerator_id),
                std::move(p_event));
            return true;
        }
        }
        return false;
    }

    // static
    bool WindowManagerStubDispatch::AcceptWithResponder(
        WindowManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kWindowManager_OnConnect_Name: {
            break;
        }
        case internal::kWindowManager_WmNewDisplayAdded_Name: {
            break;
        }
        case internal::kWindowManager_WmDisplayRemoved_Name: {
            break;
        }
        case internal::kWindowManager_WmDisplayModified_Name: {
            break;
        }
        case internal::kWindowManager_WmSetBounds_Name: {
            break;
        }
        case internal::kWindowManager_WmSetProperty_Name: {
            break;
        }
        case internal::kWindowManager_WmCreateTopLevelWindow_Name: {
            break;
        }
        case internal::kWindowManager_WmClientJankinessChanged_Name: {
            break;
        }
        case internal::kWindowManager_WmPerformMoveLoop_Name: {
            break;
        }
        case internal::kWindowManager_WmCancelMoveLoop_Name: {
            break;
        }
        case internal::kWindowManager_WmDeactivateWindow_Name: {
            break;
        }
        case internal::kWindowManager_OnAccelerator_Name: {
            break;
        }
        }
        return false;
    }

    bool WindowManagerRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowManager RequestValidator");

        switch (message->header()->name) {
        case internal::kWindowManager_OnConnect_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_OnConnect_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmNewDisplayAdded_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmNewDisplayAdded_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmDisplayRemoved_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmDisplayRemoved_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmDisplayModified_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmDisplayModified_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmSetBounds_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmSetBounds_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmSetProperty_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmSetProperty_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmCreateTopLevelWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmCreateTopLevelWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmClientJankinessChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmClientJankinessChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmPerformMoveLoop_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmPerformMoveLoop_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmCancelMoveLoop_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmCancelMoveLoop_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_WmDeactivateWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_WmDeactivateWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManager_OnAccelerator_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManager_OnAccelerator_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    const char WindowManagerClient::Name_[] = "ui::mojom::WindowManagerClient";

    class WindowManagerClient_AddAccelerators_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        WindowManagerClient_AddAccelerators_ForwardToCallback(
            const WindowManagerClient::AddAcceleratorsCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        WindowManagerClient::AddAcceleratorsCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(WindowManagerClient_AddAccelerators_ForwardToCallback);
    };
    bool WindowManagerClient_AddAccelerators_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::WindowManagerClient_AddAccelerators_ResponseParams_Data* params = reinterpret_cast<internal::WindowManagerClient_AddAccelerators_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        WindowManagerClient_AddAccelerators_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WindowManagerClient::AddAccelerators response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    WindowManagerClientProxy::WindowManagerClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void WindowManagerClientProxy::AddActivationParent(
        uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_AddActivationParent_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_AddActivationParent_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_AddActivationParent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::RemoveActivationParent(
        uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_RemoveActivationParent_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_RemoveActivationParent_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_RemoveActivationParent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::ActivateNextWindow()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_ActivateNextWindow_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_ActivateNextWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_ActivateNextWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::SetUnderlaySurfaceOffsetAndExtendedHitArea(
        uint32_t in_window_id, int32_t in_x_offset, int32_t in_y_offset, const gfx::Insets& in_hit_area)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::InsetsDataView>(
            in_hit_area, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        params->x_offset = in_x_offset;
        params->y_offset = in_y_offset;
        typename decltype(params->hit_area)::BaseType* hit_area_ptr;
        mojo::internal::Serialize<::gfx::mojom::InsetsDataView>(
            in_hit_area, builder.buffer(), &hit_area_ptr, &serialization_context);
        params->hit_area.Set(hit_area_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->hit_area.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null hit_area in WindowManagerClient.SetUnderlaySurfaceOffsetAndExtendedHitArea request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::AddAccelerators(
        std::vector<AcceleratorPtr> in_accelerators, const AddAcceleratorsCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_AddAccelerators_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::ui::mojom::AcceleratorDataView>>(
            in_accelerators, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kWindowManagerClient_AddAccelerators_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_AddAccelerators_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->accelerators)::BaseType* accelerators_ptr;
        const mojo::internal::ContainerValidateParams accelerators_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::ui::mojom::AcceleratorDataView>>(
            in_accelerators, builder.buffer(), &accelerators_ptr, &accelerators_validate_params,
            &serialization_context);
        params->accelerators.Set(accelerators_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->accelerators.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null accelerators in WindowManagerClient.AddAccelerators request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new WindowManagerClient_AddAccelerators_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void WindowManagerClientProxy::RemoveAccelerator(
        uint32_t in_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_RemoveAccelerator_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_RemoveAccelerator_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_RemoveAccelerator_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->id = in_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::WmResponse(
        uint32_t in_change_id, bool in_response)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_WmResponse_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_WmResponse_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_WmResponse_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->response = in_response;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::WmRequestClose(
        uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_WmRequestClose_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_WmRequestClose_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_WmRequestClose_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::WmSetFrameDecorationValues(
        ::ui::mojom::FrameDecorationValuesPtr in_values)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_WmSetFrameDecorationValues_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::FrameDecorationValuesDataView>(
            in_values, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_WmSetFrameDecorationValues_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_WmSetFrameDecorationValues_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->values)::BaseType* values_ptr;
        mojo::internal::Serialize<::ui::mojom::FrameDecorationValuesDataView>(
            in_values, builder.buffer(), &values_ptr, &serialization_context);
        params->values.Set(values_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->values.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null values in WindowManagerClient.WmSetFrameDecorationValues request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::WmSetNonClientCursor(
        uint32_t in_window_id, ::ui::mojom::Cursor in_cursor_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_WmSetNonClientCursor_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_WmSetNonClientCursor_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_WmSetNonClientCursor_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        mojo::internal::Serialize<::ui::mojom::Cursor>(
            in_cursor_id, &params->cursor_id);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::OnWmCreatedTopLevelWindow(
        uint32_t in_change_id, uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_OnWmCreatedTopLevelWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowManagerClientProxy::OnAcceleratorAck(
        uint32_t in_ack_id, ::ui::mojom::EventResult in_event_result)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_OnAcceleratorAck_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowManagerClient_OnAcceleratorAck_Name, size);

        auto params = ::ui::mojom::internal::WindowManagerClient_OnAcceleratorAck_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->ack_id = in_ack_id;
        mojo::internal::Serialize<::ui::mojom::EventResult>(
            in_event_result, &params->event_result);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class WindowManagerClient_AddAccelerators_ProxyToResponder {
    public:
        static WindowManagerClient::AddAcceleratorsCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<WindowManagerClient_AddAccelerators_ProxyToResponder> proxy(
                new WindowManagerClient_AddAccelerators_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&WindowManagerClient_AddAccelerators_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~WindowManagerClient_AddAccelerators_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "WindowManagerClient::AddAccelerators() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        WindowManagerClient_AddAccelerators_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            bool in_success);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(WindowManagerClient_AddAccelerators_ProxyToResponder);
    };

    void WindowManagerClient_AddAccelerators_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::ui::mojom::internal::WindowManagerClient_AddAccelerators_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kWindowManagerClient_AddAccelerators_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::WindowManagerClient_AddAccelerators_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }

    // static
    bool WindowManagerClientStubDispatch::Accept(
        WindowManagerClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kWindowManagerClient_AddActivationParent_Name: {
            internal::WindowManagerClient_AddActivationParent_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_AddActivationParent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowManagerClient_AddActivationParent_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::AddActivationParent deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::AddActivationParent");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddActivationParent(
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowManagerClient_RemoveActivationParent_Name: {
            internal::WindowManagerClient_RemoveActivationParent_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_RemoveActivationParent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowManagerClient_RemoveActivationParent_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::RemoveActivationParent deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::RemoveActivationParent");
            mojo::internal::MessageDispatchContext context(message);
            impl->RemoveActivationParent(
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowManagerClient_ActivateNextWindow_Name: {
            internal::WindowManagerClient_ActivateNextWindow_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_ActivateNextWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WindowManagerClient_ActivateNextWindow_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::ActivateNextWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::ActivateNextWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->ActivateNextWindow();
            return true;
        }
        case internal::kWindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Name: {
            internal::WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            int32_t p_x_offset {};
            int32_t p_y_offset {};
            gfx::Insets p_hit_area {};
            WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_x_offset = input_data_view.x_offset();
            p_y_offset = input_data_view.y_offset();
            if (!input_data_view.ReadHitArea(&p_hit_area))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::SetUnderlaySurfaceOffsetAndExtendedHitArea deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::SetUnderlaySurfaceOffsetAndExtendedHitArea");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetUnderlaySurfaceOffsetAndExtendedHitArea(
                std::move(p_window_id),
                std::move(p_x_offset),
                std::move(p_y_offset),
                std::move(p_hit_area));
            return true;
        }
        case internal::kWindowManagerClient_AddAccelerators_Name: {
            break;
        }
        case internal::kWindowManagerClient_RemoveAccelerator_Name: {
            internal::WindowManagerClient_RemoveAccelerator_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_RemoveAccelerator_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_id {};
            WindowManagerClient_RemoveAccelerator_ParamsDataView input_data_view(params,
                context);

            p_id = input_data_view.id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::RemoveAccelerator deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::RemoveAccelerator");
            mojo::internal::MessageDispatchContext context(message);
            impl->RemoveAccelerator(
                std::move(p_id));
            return true;
        }
        case internal::kWindowManagerClient_WmResponse_Name: {
            internal::WindowManagerClient_WmResponse_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_WmResponse_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            bool p_response {};
            WindowManagerClient_WmResponse_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_response = input_data_view.response();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::WmResponse deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::WmResponse");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmResponse(
                std::move(p_change_id),
                std::move(p_response));
            return true;
        }
        case internal::kWindowManagerClient_WmRequestClose_Name: {
            internal::WindowManagerClient_WmRequestClose_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_WmRequestClose_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowManagerClient_WmRequestClose_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::WmRequestClose deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::WmRequestClose");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmRequestClose(
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowManagerClient_WmSetFrameDecorationValues_Name: {
            internal::WindowManagerClient_WmSetFrameDecorationValues_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_WmSetFrameDecorationValues_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::ui::mojom::FrameDecorationValuesPtr p_values {};
            WindowManagerClient_WmSetFrameDecorationValues_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadValues(&p_values))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::WmSetFrameDecorationValues deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::WmSetFrameDecorationValues");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmSetFrameDecorationValues(
                std::move(p_values));
            return true;
        }
        case internal::kWindowManagerClient_WmSetNonClientCursor_Name: {
            internal::WindowManagerClient_WmSetNonClientCursor_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_WmSetNonClientCursor_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            ::ui::mojom::Cursor p_cursor_id {};
            WindowManagerClient_WmSetNonClientCursor_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadCursorId(&p_cursor_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::WmSetNonClientCursor deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::WmSetNonClientCursor");
            mojo::internal::MessageDispatchContext context(message);
            impl->WmSetNonClientCursor(
                std::move(p_window_id),
                std::move(p_cursor_id));
            return true;
        }
        case internal::kWindowManagerClient_OnWmCreatedTopLevelWindow_Name: {
            internal::WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            WindowManagerClient_OnWmCreatedTopLevelWindow_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::OnWmCreatedTopLevelWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::OnWmCreatedTopLevelWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWmCreatedTopLevelWindow(
                std::move(p_change_id),
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowManagerClient_OnAcceleratorAck_Name: {
            internal::WindowManagerClient_OnAcceleratorAck_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_OnAcceleratorAck_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_ack_id {};
            ::ui::mojom::EventResult p_event_result {};
            WindowManagerClient_OnAcceleratorAck_ParamsDataView input_data_view(params,
                context);

            p_ack_id = input_data_view.ack_id();
            if (!input_data_view.ReadEventResult(&p_event_result))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::OnAcceleratorAck deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::OnAcceleratorAck");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnAcceleratorAck(
                std::move(p_ack_id),
                std::move(p_event_result));
            return true;
        }
        }
        return false;
    }

    // static
    bool WindowManagerClientStubDispatch::AcceptWithResponder(
        WindowManagerClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kWindowManagerClient_AddActivationParent_Name: {
            break;
        }
        case internal::kWindowManagerClient_RemoveActivationParent_Name: {
            break;
        }
        case internal::kWindowManagerClient_ActivateNextWindow_Name: {
            break;
        }
        case internal::kWindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Name: {
            break;
        }
        case internal::kWindowManagerClient_AddAccelerators_Name: {
            internal::WindowManagerClient_AddAccelerators_Params_Data* params = reinterpret_cast<internal::WindowManagerClient_AddAccelerators_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<AcceleratorPtr> p_accelerators {};
            WindowManagerClient_AddAccelerators_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadAccelerators(&p_accelerators))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowManagerClient::AddAccelerators deserializer");
                return false;
            }
            WindowManagerClient::AddAcceleratorsCallback callback = WindowManagerClient_AddAccelerators_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowManagerClient::AddAccelerators");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddAccelerators(
                std::move(p_accelerators), std::move(callback));
            return true;
        }
        case internal::kWindowManagerClient_RemoveAccelerator_Name: {
            break;
        }
        case internal::kWindowManagerClient_WmResponse_Name: {
            break;
        }
        case internal::kWindowManagerClient_WmRequestClose_Name: {
            break;
        }
        case internal::kWindowManagerClient_WmSetFrameDecorationValues_Name: {
            break;
        }
        case internal::kWindowManagerClient_WmSetNonClientCursor_Name: {
            break;
        }
        case internal::kWindowManagerClient_OnWmCreatedTopLevelWindow_Name: {
            break;
        }
        case internal::kWindowManagerClient_OnAcceleratorAck_Name: {
            break;
        }
        }
        return false;
    }

    bool WindowManagerClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowManagerClient RequestValidator");

        switch (message->header()->name) {
        case internal::kWindowManagerClient_AddActivationParent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_AddActivationParent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_RemoveActivationParent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_RemoveActivationParent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_ActivateNextWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_ActivateNextWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_AddAccelerators_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_AddAccelerators_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_RemoveAccelerator_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_RemoveAccelerator_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_WmResponse_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_WmResponse_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_WmRequestClose_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_WmRequestClose_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_WmSetFrameDecorationValues_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_WmSetFrameDecorationValues_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_WmSetNonClientCursor_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_WmSetNonClientCursor_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_OnWmCreatedTopLevelWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowManagerClient_OnAcceleratorAck_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_OnAcceleratorAck_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    bool WindowManagerClientResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowManagerClient ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kWindowManagerClient_AddAccelerators_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowManagerClient_AddAccelerators_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }
} // namespace mojom
} // namespace ui

namespace mojo {

// static
bool StructTraits<::ui::mojom::Accelerator::DataView, ::ui::mojom::AcceleratorPtr>::Read(
    ::ui::mojom::Accelerator::DataView input,
    ::ui::mojom::AcceleratorPtr* output)
{
    bool success = true;
    ::ui::mojom::AcceleratorPtr result(::ui::mojom::Accelerator::New());

    result->id = input.id();
    if (!input.ReadEventMatcher(&result->event_matcher))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif