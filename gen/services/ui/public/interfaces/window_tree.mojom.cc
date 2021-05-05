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

#include "services/ui/public/interfaces/window_tree.mojom.h"

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
namespace mojom {
    const char WindowTree::Name_[] = "ui::mojom::WindowTree";

    class WindowTree_GetWindowTree_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        WindowTree_GetWindowTree_ForwardToCallback(
            const WindowTree::GetWindowTreeCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        WindowTree::GetWindowTreeCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(WindowTree_GetWindowTree_ForwardToCallback);
    };
    bool WindowTree_GetWindowTree_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::WindowTree_GetWindowTree_ResponseParams_Data* params = reinterpret_cast<internal::WindowTree_GetWindowTree_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<::ui::mojom::WindowDataPtr> p_windows {};
        WindowTree_GetWindowTree_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadWindows(&p_windows))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WindowTree::GetWindowTree response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_windows));
        }
        return true;
    }

    class WindowTree_Embed_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        WindowTree_Embed_ForwardToCallback(
            const WindowTree::EmbedCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        WindowTree::EmbedCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(WindowTree_Embed_ForwardToCallback);
    };
    bool WindowTree_Embed_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::WindowTree_Embed_ResponseParams_Data* params = reinterpret_cast<internal::WindowTree_Embed_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        WindowTree_Embed_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WindowTree::Embed response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    class WindowTree_GetCursorLocationMemory_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        WindowTree_GetCursorLocationMemory_ForwardToCallback(
            const WindowTree::GetCursorLocationMemoryCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        WindowTree::GetCursorLocationMemoryCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(WindowTree_GetCursorLocationMemory_ForwardToCallback);
    };
    bool WindowTree_GetCursorLocationMemory_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::WindowTree_GetCursorLocationMemory_ResponseParams_Data* params = reinterpret_cast<internal::WindowTree_GetCursorLocationMemory_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        mojo::ScopedSharedBufferHandle p_cursor_buffer {};
        WindowTree_GetCursorLocationMemory_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_cursor_buffer = input_data_view.TakeCursorBuffer();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WindowTree::GetCursorLocationMemory response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_cursor_buffer));
        }
        return true;
    }

    WindowTreeProxy::WindowTreeProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void WindowTreeProxy::NewWindow(
        uint32_t in_change_id, uint32_t in_window_id, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& in_properties)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_NewWindow_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_properties, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_NewWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_NewWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        typename decltype(params->properties)::BaseType* properties_ptr;
        const mojo::internal::ContainerValidateParams properties_validate_params(
            new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
        mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_properties, builder.buffer(), &properties_ptr, &properties_validate_params,
            &serialization_context);
        params->properties.Set(properties_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::NewTopLevelWindow(
        uint32_t in_change_id, uint32_t in_window_id, const std::unordered_map<std::string, std::vector<uint8_t>>& in_properties)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_NewTopLevelWindow_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_properties, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_NewTopLevelWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_NewTopLevelWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
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
            "null properties in WindowTree.NewTopLevelWindow request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::DeleteWindow(
        uint32_t in_change_id, uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_DeleteWindow_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_DeleteWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_DeleteWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetCapture(
        uint32_t in_change_id, uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetCapture_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetCapture_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetCapture_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::ReleaseCapture(
        uint32_t in_change_id, uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_ReleaseCapture_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_ReleaseCapture_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_ReleaseCapture_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::StartPointerWatcher(
        bool in_want_moves)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_StartPointerWatcher_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_StartPointerWatcher_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_StartPointerWatcher_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->want_moves = in_want_moves;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::StopPointerWatcher()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_StopPointerWatcher_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_StopPointerWatcher_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_StopPointerWatcher_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetWindowBounds(
        uint32_t in_change_id, uint32_t in_window_id, const gfx::Rect& in_bounds)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetWindowBounds_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
            in_bounds, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetWindowBounds_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetWindowBounds_Params_Data::New(builder.buffer());
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
            "null bounds in WindowTree.SetWindowBounds request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetClientArea(
        uint32_t in_window_id, const gfx::Insets& in_insets, const base::Optional<std::vector<gfx::Rect>>& in_additional_client_areas)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetClientArea_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::InsetsDataView>(
            in_insets, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gfx::mojom::RectDataView>>(
            in_additional_client_areas, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetClientArea_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetClientArea_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        typename decltype(params->insets)::BaseType* insets_ptr;
        mojo::internal::Serialize<::gfx::mojom::InsetsDataView>(
            in_insets, builder.buffer(), &insets_ptr, &serialization_context);
        params->insets.Set(insets_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->insets.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null insets in WindowTree.SetClientArea request");
        typename decltype(params->additional_client_areas)::BaseType* additional_client_areas_ptr;
        const mojo::internal::ContainerValidateParams additional_client_areas_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::gfx::mojom::RectDataView>>(
            in_additional_client_areas, builder.buffer(), &additional_client_areas_ptr, &additional_client_areas_validate_params,
            &serialization_context);
        params->additional_client_areas.Set(additional_client_areas_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetHitTestMask(
        uint32_t in_window_id, const base::Optional<gfx::Rect>& in_mask)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetHitTestMask_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
            in_mask, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetHitTestMask_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetHitTestMask_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        typename decltype(params->mask)::BaseType* mask_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectDataView>(
            in_mask, builder.buffer(), &mask_ptr, &serialization_context);
        params->mask.Set(mask_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetCanAcceptDrops(
        uint32_t in_window_id, bool in_accepts_drops)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetCanAcceptDrops_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetCanAcceptDrops_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetCanAcceptDrops_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        params->accepts_drops = in_accepts_drops;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetWindowVisibility(
        uint32_t in_change_id, uint32_t in_window_id, bool in_visible)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetWindowVisibility_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetWindowVisibility_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetWindowVisibility_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        params->visible = in_visible;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetWindowProperty(
        uint32_t in_change_id, uint32_t in_window_id, const std::string& in_name, const base::Optional<std::vector<uint8_t>>& in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetWindowProperty_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_name, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetWindowProperty_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetWindowProperty_Params_Data::New(builder.buffer());
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
            "null name in WindowTree.SetWindowProperty request");
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

    void WindowTreeProxy::SetWindowOpacity(
        uint32_t in_change_id, uint32_t in_window_id, float in_opacity)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetWindowOpacity_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetWindowOpacity_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetWindowOpacity_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        params->opacity = in_opacity;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::AttachCompositorFrameSink(
        uint32_t in_window_id, ::cc::mojom::MojoCompositorFrameSinkRequest in_compositor_frame_sink, ::cc::mojom::MojoCompositorFrameSinkClientPtr in_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_AttachCompositorFrameSink_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_AttachCompositorFrameSink_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_AttachCompositorFrameSink_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkRequestDataView>(
            in_compositor_frame_sink, &params->compositor_frame_sink, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->compositor_frame_sink),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid compositor_frame_sink in WindowTree.AttachCompositorFrameSink request");
        mojo::internal::Serialize<::cc::mojom::MojoCompositorFrameSinkClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in WindowTree.AttachCompositorFrameSink request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::AddWindow(
        uint32_t in_change_id, uint32_t in_parent, uint32_t in_child)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_AddWindow_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_AddWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_AddWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->parent = in_parent;
        params->child = in_child;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::RemoveWindowFromParent(
        uint32_t in_change_id, uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_RemoveWindowFromParent_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_RemoveWindowFromParent_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_RemoveWindowFromParent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::AddTransientWindow(
        uint32_t in_change_id, uint32_t in_window_id, uint32_t in_transient_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_AddTransientWindow_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_AddTransientWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_AddTransientWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        params->transient_window_id = in_transient_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::RemoveTransientWindowFromParent(
        uint32_t in_change_id, uint32_t in_transient_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_RemoveTransientWindowFromParent_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_RemoveTransientWindowFromParent_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_RemoveTransientWindowFromParent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->transient_window_id = in_transient_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetModal(
        uint32_t in_change_id, uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetModal_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetModal_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetModal_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::ReorderWindow(
        uint32_t in_change_id, uint32_t in_window_id, uint32_t in_relative_window_id, ::ui::mojom::OrderDirection in_direction)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_ReorderWindow_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_ReorderWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_ReorderWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        params->relative_window_id = in_relative_window_id;
        mojo::internal::Serialize<::ui::mojom::OrderDirection>(
            in_direction, &params->direction);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::GetWindowTree(
        uint32_t in_window_id, const GetWindowTreeCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_GetWindowTree_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kWindowTree_GetWindowTree_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_GetWindowTree_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new WindowTree_GetWindowTree_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void WindowTreeProxy::Embed(
        uint32_t in_window_id, WindowTreeClientPtr in_client, uint32_t in_embed_flags, const EmbedCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_Embed_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kWindowTree_Embed_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_Embed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        mojo::internal::Serialize<::ui::mojom::WindowTreeClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in WindowTree.Embed request");
        params->embed_flags = in_embed_flags;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new WindowTree_Embed_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void WindowTreeProxy::SetFocus(
        uint32_t in_change_id, uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetFocus_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetFocus_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetFocus_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetCanFocus(
        uint32_t in_window_id, bool in_can_focus)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetCanFocus_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetCanFocus_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetCanFocus_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        params->can_focus = in_can_focus;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetPredefinedCursor(
        uint32_t in_change_id, uint32_t in_window_id, ::ui::mojom::Cursor in_cursor_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetPredefinedCursor_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetPredefinedCursor_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetPredefinedCursor_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        mojo::internal::Serialize<::ui::mojom::Cursor>(
            in_cursor_id, &params->cursor_id);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetWindowTextInputState(
        uint32_t in_window_id, ::mojo::TextInputStatePtr in_state)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetWindowTextInputState_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::TextInputStateDataView>(
            in_state, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetWindowTextInputState_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetWindowTextInputState_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        typename decltype(params->state)::BaseType* state_ptr;
        mojo::internal::Serialize<::mojo::TextInputStateDataView>(
            in_state, builder.buffer(), &state_ptr, &serialization_context);
        params->state.Set(state_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->state.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null state in WindowTree.SetWindowTextInputState request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetImeVisibility(
        uint32_t in_window_id, bool in_visible, ::mojo::TextInputStatePtr in_state)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetImeVisibility_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::TextInputStateDataView>(
            in_state, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetImeVisibility_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetImeVisibility_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        params->visible = in_visible;
        typename decltype(params->state)::BaseType* state_ptr;
        mojo::internal::Serialize<::mojo::TextInputStateDataView>(
            in_state, builder.buffer(), &state_ptr, &serialization_context);
        params->state.Set(state_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::SetCanAcceptEvents(
        uint32_t in_window_id, bool in_accept_events)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_SetCanAcceptEvents_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_SetCanAcceptEvents_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_SetCanAcceptEvents_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        params->accept_events = in_accept_events;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::OnWindowInputEventAck(
        uint32_t in_event_id, ::ui::mojom::EventResult in_result)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_OnWindowInputEventAck_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_OnWindowInputEventAck_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_OnWindowInputEventAck_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->event_id = in_event_id;
        mojo::internal::Serialize<::ui::mojom::EventResult>(
            in_result, &params->result);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::DeactivateWindow(
        uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_DeactivateWindow_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_DeactivateWindow_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_DeactivateWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::GetWindowManagerClient(
        ::ui::mojom::WindowManagerClientAssociatedRequest in_internal)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_GetWindowManagerClient_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_GetWindowManagerClient_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_GetWindowManagerClient_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::WindowManagerClientAssociatedRequestDataView>(
            in_internal, &params->internal, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->internal),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid internal in WindowTree.GetWindowManagerClient request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::GetCursorLocationMemory(
        const GetCursorLocationMemoryCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_GetCursorLocationMemory_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kWindowTree_GetCursorLocationMemory_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_GetCursorLocationMemory_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new WindowTree_GetCursorLocationMemory_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void WindowTreeProxy::PerformWindowMove(
        uint32_t in_change_id, uint32_t in_window_id, ::ui::mojom::MoveLoopSource in_source, const gfx::Point& in_cursor)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_PerformWindowMove_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointDataView>(
            in_cursor, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_PerformWindowMove_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_PerformWindowMove_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->window_id = in_window_id;
        mojo::internal::Serialize<::ui::mojom::MoveLoopSource>(
            in_source, &params->source);
        typename decltype(params->cursor)::BaseType* cursor_ptr;
        mojo::internal::Serialize<::gfx::mojom::PointDataView>(
            in_cursor, builder.buffer(), &cursor_ptr, &serialization_context);
        params->cursor.Set(cursor_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->cursor.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null cursor in WindowTree.PerformWindowMove request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::CancelWindowMove(
        uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_CancelWindowMove_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_CancelWindowMove_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_CancelWindowMove_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::PerformDragDrop(
        uint32_t in_change_id, uint32_t in_source_window_id, const std::unordered_map<std::string, std::vector<uint8_t>>& in_drag_data, uint32_t in_drag_operation)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_PerformDragDrop_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_drag_data, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_PerformDragDrop_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_PerformDragDrop_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->source_window_id = in_source_window_id;
        typename decltype(params->drag_data)::BaseType* drag_data_ptr;
        const mojo::internal::ContainerValidateParams drag_data_validate_params(
            new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
        mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_drag_data, builder.buffer(), &drag_data_ptr, &drag_data_validate_params,
            &serialization_context);
        params->drag_data.Set(drag_data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->drag_data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null drag_data in WindowTree.PerformDragDrop request");
        params->drag_operation = in_drag_operation;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeProxy::CancelDragDrop(
        uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTree_CancelDragDrop_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTree_CancelDragDrop_Name, size);

        auto params = ::ui::mojom::internal::WindowTree_CancelDragDrop_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class WindowTree_GetWindowTree_ProxyToResponder {
    public:
        static WindowTree::GetWindowTreeCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<WindowTree_GetWindowTree_ProxyToResponder> proxy(
                new WindowTree_GetWindowTree_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&WindowTree_GetWindowTree_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~WindowTree_GetWindowTree_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "WindowTree::GetWindowTree() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        WindowTree_GetWindowTree_ProxyToResponder(
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
            std::vector<::ui::mojom::WindowDataPtr> in_windows);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(WindowTree_GetWindowTree_ProxyToResponder);
    };

    void WindowTree_GetWindowTree_ProxyToResponder::Run(
        std::vector<::ui::mojom::WindowDataPtr> in_windows)
    {
        size_t size = sizeof(::ui::mojom::internal::WindowTree_GetWindowTree_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::ui::mojom::WindowDataDataView>>(
            in_windows, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kWindowTree_GetWindowTree_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::WindowTree_GetWindowTree_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->windows)::BaseType* windows_ptr;
        const mojo::internal::ContainerValidateParams windows_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::ui::mojom::WindowDataDataView>>(
            in_windows, builder.buffer(), &windows_ptr, &windows_validate_params,
            &serialization_context_);
        params->windows.Set(windows_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->windows.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null windows in WindowTree.GetWindowTree response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class WindowTree_Embed_ProxyToResponder {
    public:
        static WindowTree::EmbedCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<WindowTree_Embed_ProxyToResponder> proxy(
                new WindowTree_Embed_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&WindowTree_Embed_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~WindowTree_Embed_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "WindowTree::Embed() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        WindowTree_Embed_ProxyToResponder(
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

        DISALLOW_COPY_AND_ASSIGN(WindowTree_Embed_ProxyToResponder);
    };

    void WindowTree_Embed_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::ui::mojom::internal::WindowTree_Embed_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kWindowTree_Embed_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::WindowTree_Embed_ResponseParams_Data::New(builder.buffer());
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
    class WindowTree_GetCursorLocationMemory_ProxyToResponder {
    public:
        static WindowTree::GetCursorLocationMemoryCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<WindowTree_GetCursorLocationMemory_ProxyToResponder> proxy(
                new WindowTree_GetCursorLocationMemory_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&WindowTree_GetCursorLocationMemory_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~WindowTree_GetCursorLocationMemory_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "WindowTree::GetCursorLocationMemory() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        WindowTree_GetCursorLocationMemory_ProxyToResponder(
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
            mojo::ScopedSharedBufferHandle in_cursor_buffer);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(WindowTree_GetCursorLocationMemory_ProxyToResponder);
    };

    void WindowTree_GetCursorLocationMemory_ProxyToResponder::Run(
        mojo::ScopedSharedBufferHandle in_cursor_buffer)
    {
        size_t size = sizeof(::ui::mojom::internal::WindowTree_GetCursorLocationMemory_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kWindowTree_GetCursorLocationMemory_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::WindowTree_GetCursorLocationMemory_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_cursor_buffer, &params->cursor_buffer, &serialization_context_);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->cursor_buffer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid cursor_buffer in WindowTree.GetCursorLocationMemory response");
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
    bool WindowTreeStubDispatch::Accept(
        WindowTree* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kWindowTree_NewWindow_Name: {
            internal::WindowTree_NewWindow_Params_Data* params = reinterpret_cast<internal::WindowTree_NewWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>> p_properties {};
            WindowTree_NewWindow_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadProperties(&p_properties))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::NewWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::NewWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->NewWindow(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_properties));
            return true;
        }
        case internal::kWindowTree_NewTopLevelWindow_Name: {
            internal::WindowTree_NewTopLevelWindow_Params_Data* params = reinterpret_cast<internal::WindowTree_NewTopLevelWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            std::unordered_map<std::string, std::vector<uint8_t>> p_properties {};
            WindowTree_NewTopLevelWindow_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadProperties(&p_properties))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::NewTopLevelWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::NewTopLevelWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->NewTopLevelWindow(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_properties));
            return true;
        }
        case internal::kWindowTree_DeleteWindow_Name: {
            internal::WindowTree_DeleteWindow_Params_Data* params = reinterpret_cast<internal::WindowTree_DeleteWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            WindowTree_DeleteWindow_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::DeleteWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::DeleteWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeleteWindow(
                std::move(p_change_id),
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTree_SetCapture_Name: {
            internal::WindowTree_SetCapture_Params_Data* params = reinterpret_cast<internal::WindowTree_SetCapture_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            WindowTree_SetCapture_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetCapture deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetCapture");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetCapture(
                std::move(p_change_id),
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTree_ReleaseCapture_Name: {
            internal::WindowTree_ReleaseCapture_Params_Data* params = reinterpret_cast<internal::WindowTree_ReleaseCapture_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            WindowTree_ReleaseCapture_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::ReleaseCapture deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::ReleaseCapture");
            mojo::internal::MessageDispatchContext context(message);
            impl->ReleaseCapture(
                std::move(p_change_id),
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTree_StartPointerWatcher_Name: {
            internal::WindowTree_StartPointerWatcher_Params_Data* params = reinterpret_cast<internal::WindowTree_StartPointerWatcher_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_want_moves {};
            WindowTree_StartPointerWatcher_ParamsDataView input_data_view(params,
                context);

            p_want_moves = input_data_view.want_moves();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::StartPointerWatcher deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::StartPointerWatcher");
            mojo::internal::MessageDispatchContext context(message);
            impl->StartPointerWatcher(
                std::move(p_want_moves));
            return true;
        }
        case internal::kWindowTree_StopPointerWatcher_Name: {
            internal::WindowTree_StopPointerWatcher_Params_Data* params = reinterpret_cast<internal::WindowTree_StopPointerWatcher_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WindowTree_StopPointerWatcher_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::StopPointerWatcher deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::StopPointerWatcher");
            mojo::internal::MessageDispatchContext context(message);
            impl->StopPointerWatcher();
            return true;
        }
        case internal::kWindowTree_SetWindowBounds_Name: {
            internal::WindowTree_SetWindowBounds_Params_Data* params = reinterpret_cast<internal::WindowTree_SetWindowBounds_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            gfx::Rect p_bounds {};
            WindowTree_SetWindowBounds_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadBounds(&p_bounds))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetWindowBounds deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetWindowBounds");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetWindowBounds(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_bounds));
            return true;
        }
        case internal::kWindowTree_SetClientArea_Name: {
            internal::WindowTree_SetClientArea_Params_Data* params = reinterpret_cast<internal::WindowTree_SetClientArea_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            gfx::Insets p_insets {};
            base::Optional<std::vector<gfx::Rect>> p_additional_client_areas {};
            WindowTree_SetClientArea_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadInsets(&p_insets))
                success = false;
            if (!input_data_view.ReadAdditionalClientAreas(&p_additional_client_areas))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetClientArea deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetClientArea");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetClientArea(
                std::move(p_window_id),
                std::move(p_insets),
                std::move(p_additional_client_areas));
            return true;
        }
        case internal::kWindowTree_SetHitTestMask_Name: {
            internal::WindowTree_SetHitTestMask_Params_Data* params = reinterpret_cast<internal::WindowTree_SetHitTestMask_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            base::Optional<gfx::Rect> p_mask {};
            WindowTree_SetHitTestMask_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadMask(&p_mask))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetHitTestMask deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetHitTestMask");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetHitTestMask(
                std::move(p_window_id),
                std::move(p_mask));
            return true;
        }
        case internal::kWindowTree_SetCanAcceptDrops_Name: {
            internal::WindowTree_SetCanAcceptDrops_Params_Data* params = reinterpret_cast<internal::WindowTree_SetCanAcceptDrops_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            bool p_accepts_drops {};
            WindowTree_SetCanAcceptDrops_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_accepts_drops = input_data_view.accepts_drops();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetCanAcceptDrops deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetCanAcceptDrops");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetCanAcceptDrops(
                std::move(p_window_id),
                std::move(p_accepts_drops));
            return true;
        }
        case internal::kWindowTree_SetWindowVisibility_Name: {
            internal::WindowTree_SetWindowVisibility_Params_Data* params = reinterpret_cast<internal::WindowTree_SetWindowVisibility_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            bool p_visible {};
            WindowTree_SetWindowVisibility_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            p_visible = input_data_view.visible();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetWindowVisibility deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetWindowVisibility");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetWindowVisibility(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_visible));
            return true;
        }
        case internal::kWindowTree_SetWindowProperty_Name: {
            internal::WindowTree_SetWindowProperty_Params_Data* params = reinterpret_cast<internal::WindowTree_SetWindowProperty_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            std::string p_name {};
            base::Optional<std::vector<uint8_t>> p_value {};
            WindowTree_SetWindowProperty_ParamsDataView input_data_view(params,
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
                    "WindowTree::SetWindowProperty deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetWindowProperty");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetWindowProperty(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_name),
                std::move(p_value));
            return true;
        }
        case internal::kWindowTree_SetWindowOpacity_Name: {
            internal::WindowTree_SetWindowOpacity_Params_Data* params = reinterpret_cast<internal::WindowTree_SetWindowOpacity_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            float p_opacity {};
            WindowTree_SetWindowOpacity_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            p_opacity = input_data_view.opacity();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetWindowOpacity deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetWindowOpacity");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetWindowOpacity(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_opacity));
            return true;
        }
        case internal::kWindowTree_AttachCompositorFrameSink_Name: {
            internal::WindowTree_AttachCompositorFrameSink_Params_Data* params = reinterpret_cast<internal::WindowTree_AttachCompositorFrameSink_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            ::cc::mojom::MojoCompositorFrameSinkRequest p_compositor_frame_sink {};
            ::cc::mojom::MojoCompositorFrameSinkClientPtr p_client {};
            WindowTree_AttachCompositorFrameSink_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_compositor_frame_sink = input_data_view.TakeCompositorFrameSink<decltype(p_compositor_frame_sink)>();
            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::AttachCompositorFrameSink deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::AttachCompositorFrameSink");
            mojo::internal::MessageDispatchContext context(message);
            impl->AttachCompositorFrameSink(
                std::move(p_window_id),
                std::move(p_compositor_frame_sink),
                std::move(p_client));
            return true;
        }
        case internal::kWindowTree_AddWindow_Name: {
            internal::WindowTree_AddWindow_Params_Data* params = reinterpret_cast<internal::WindowTree_AddWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_parent {};
            uint32_t p_child {};
            WindowTree_AddWindow_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_parent = input_data_view.parent();
            p_child = input_data_view.child();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::AddWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::AddWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddWindow(
                std::move(p_change_id),
                std::move(p_parent),
                std::move(p_child));
            return true;
        }
        case internal::kWindowTree_RemoveWindowFromParent_Name: {
            internal::WindowTree_RemoveWindowFromParent_Params_Data* params = reinterpret_cast<internal::WindowTree_RemoveWindowFromParent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            WindowTree_RemoveWindowFromParent_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::RemoveWindowFromParent deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::RemoveWindowFromParent");
            mojo::internal::MessageDispatchContext context(message);
            impl->RemoveWindowFromParent(
                std::move(p_change_id),
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTree_AddTransientWindow_Name: {
            internal::WindowTree_AddTransientWindow_Params_Data* params = reinterpret_cast<internal::WindowTree_AddTransientWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            uint32_t p_transient_window_id {};
            WindowTree_AddTransientWindow_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            p_transient_window_id = input_data_view.transient_window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::AddTransientWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::AddTransientWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddTransientWindow(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_transient_window_id));
            return true;
        }
        case internal::kWindowTree_RemoveTransientWindowFromParent_Name: {
            internal::WindowTree_RemoveTransientWindowFromParent_Params_Data* params = reinterpret_cast<internal::WindowTree_RemoveTransientWindowFromParent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_transient_window_id {};
            WindowTree_RemoveTransientWindowFromParent_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_transient_window_id = input_data_view.transient_window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::RemoveTransientWindowFromParent deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::RemoveTransientWindowFromParent");
            mojo::internal::MessageDispatchContext context(message);
            impl->RemoveTransientWindowFromParent(
                std::move(p_change_id),
                std::move(p_transient_window_id));
            return true;
        }
        case internal::kWindowTree_SetModal_Name: {
            internal::WindowTree_SetModal_Params_Data* params = reinterpret_cast<internal::WindowTree_SetModal_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            WindowTree_SetModal_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetModal deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetModal");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetModal(
                std::move(p_change_id),
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTree_ReorderWindow_Name: {
            internal::WindowTree_ReorderWindow_Params_Data* params = reinterpret_cast<internal::WindowTree_ReorderWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            uint32_t p_relative_window_id {};
            ::ui::mojom::OrderDirection p_direction {};
            WindowTree_ReorderWindow_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            p_relative_window_id = input_data_view.relative_window_id();
            if (!input_data_view.ReadDirection(&p_direction))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::ReorderWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::ReorderWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->ReorderWindow(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_relative_window_id),
                std::move(p_direction));
            return true;
        }
        case internal::kWindowTree_GetWindowTree_Name: {
            break;
        }
        case internal::kWindowTree_Embed_Name: {
            break;
        }
        case internal::kWindowTree_SetFocus_Name: {
            internal::WindowTree_SetFocus_Params_Data* params = reinterpret_cast<internal::WindowTree_SetFocus_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            WindowTree_SetFocus_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetFocus deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetFocus");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetFocus(
                std::move(p_change_id),
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTree_SetCanFocus_Name: {
            internal::WindowTree_SetCanFocus_Params_Data* params = reinterpret_cast<internal::WindowTree_SetCanFocus_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            bool p_can_focus {};
            WindowTree_SetCanFocus_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_can_focus = input_data_view.can_focus();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetCanFocus deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetCanFocus");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetCanFocus(
                std::move(p_window_id),
                std::move(p_can_focus));
            return true;
        }
        case internal::kWindowTree_SetPredefinedCursor_Name: {
            internal::WindowTree_SetPredefinedCursor_Params_Data* params = reinterpret_cast<internal::WindowTree_SetPredefinedCursor_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            ::ui::mojom::Cursor p_cursor_id {};
            WindowTree_SetPredefinedCursor_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadCursorId(&p_cursor_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetPredefinedCursor deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetPredefinedCursor");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetPredefinedCursor(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_cursor_id));
            return true;
        }
        case internal::kWindowTree_SetWindowTextInputState_Name: {
            internal::WindowTree_SetWindowTextInputState_Params_Data* params = reinterpret_cast<internal::WindowTree_SetWindowTextInputState_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            ::mojo::TextInputStatePtr p_state {};
            WindowTree_SetWindowTextInputState_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadState(&p_state))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetWindowTextInputState deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetWindowTextInputState");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetWindowTextInputState(
                std::move(p_window_id),
                std::move(p_state));
            return true;
        }
        case internal::kWindowTree_SetImeVisibility_Name: {
            internal::WindowTree_SetImeVisibility_Params_Data* params = reinterpret_cast<internal::WindowTree_SetImeVisibility_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            bool p_visible {};
            ::mojo::TextInputStatePtr p_state {};
            WindowTree_SetImeVisibility_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_visible = input_data_view.visible();
            if (!input_data_view.ReadState(&p_state))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetImeVisibility deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetImeVisibility");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetImeVisibility(
                std::move(p_window_id),
                std::move(p_visible),
                std::move(p_state));
            return true;
        }
        case internal::kWindowTree_SetCanAcceptEvents_Name: {
            internal::WindowTree_SetCanAcceptEvents_Params_Data* params = reinterpret_cast<internal::WindowTree_SetCanAcceptEvents_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            bool p_accept_events {};
            WindowTree_SetCanAcceptEvents_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_accept_events = input_data_view.accept_events();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::SetCanAcceptEvents deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::SetCanAcceptEvents");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetCanAcceptEvents(
                std::move(p_window_id),
                std::move(p_accept_events));
            return true;
        }
        case internal::kWindowTree_OnWindowInputEventAck_Name: {
            internal::WindowTree_OnWindowInputEventAck_Params_Data* params = reinterpret_cast<internal::WindowTree_OnWindowInputEventAck_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_event_id {};
            ::ui::mojom::EventResult p_result {};
            WindowTree_OnWindowInputEventAck_ParamsDataView input_data_view(params,
                context);

            p_event_id = input_data_view.event_id();
            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::OnWindowInputEventAck deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::OnWindowInputEventAck");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowInputEventAck(
                std::move(p_event_id),
                std::move(p_result));
            return true;
        }
        case internal::kWindowTree_DeactivateWindow_Name: {
            internal::WindowTree_DeactivateWindow_Params_Data* params = reinterpret_cast<internal::WindowTree_DeactivateWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowTree_DeactivateWindow_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::DeactivateWindow deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::DeactivateWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeactivateWindow(
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTree_GetWindowManagerClient_Name: {
            internal::WindowTree_GetWindowManagerClient_Params_Data* params = reinterpret_cast<internal::WindowTree_GetWindowManagerClient_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::ui::mojom::WindowManagerClientAssociatedRequest p_internal {};
            WindowTree_GetWindowManagerClient_ParamsDataView input_data_view(params,
                context);

            p_internal = input_data_view.TakeInternal<decltype(p_internal)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::GetWindowManagerClient deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::GetWindowManagerClient");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetWindowManagerClient(
                std::move(p_internal));
            return true;
        }
        case internal::kWindowTree_GetCursorLocationMemory_Name: {
            break;
        }
        case internal::kWindowTree_PerformWindowMove_Name: {
            internal::WindowTree_PerformWindowMove_Params_Data* params = reinterpret_cast<internal::WindowTree_PerformWindowMove_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_window_id {};
            ::ui::mojom::MoveLoopSource p_source {};
            gfx::Point p_cursor {};
            WindowTree_PerformWindowMove_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadSource(&p_source))
                success = false;
            if (!input_data_view.ReadCursor(&p_cursor))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::PerformWindowMove deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::PerformWindowMove");
            mojo::internal::MessageDispatchContext context(message);
            impl->PerformWindowMove(
                std::move(p_change_id),
                std::move(p_window_id),
                std::move(p_source),
                std::move(p_cursor));
            return true;
        }
        case internal::kWindowTree_CancelWindowMove_Name: {
            internal::WindowTree_CancelWindowMove_Params_Data* params = reinterpret_cast<internal::WindowTree_CancelWindowMove_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowTree_CancelWindowMove_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::CancelWindowMove deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::CancelWindowMove");
            mojo::internal::MessageDispatchContext context(message);
            impl->CancelWindowMove(
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTree_PerformDragDrop_Name: {
            internal::WindowTree_PerformDragDrop_Params_Data* params = reinterpret_cast<internal::WindowTree_PerformDragDrop_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            uint32_t p_source_window_id {};
            std::unordered_map<std::string, std::vector<uint8_t>> p_drag_data {};
            uint32_t p_drag_operation {};
            WindowTree_PerformDragDrop_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_source_window_id = input_data_view.source_window_id();
            if (!input_data_view.ReadDragData(&p_drag_data))
                success = false;
            p_drag_operation = input_data_view.drag_operation();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::PerformDragDrop deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::PerformDragDrop");
            mojo::internal::MessageDispatchContext context(message);
            impl->PerformDragDrop(
                std::move(p_change_id),
                std::move(p_source_window_id),
                std::move(p_drag_data),
                std::move(p_drag_operation));
            return true;
        }
        case internal::kWindowTree_CancelDragDrop_Name: {
            internal::WindowTree_CancelDragDrop_Params_Data* params = reinterpret_cast<internal::WindowTree_CancelDragDrop_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowTree_CancelDragDrop_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::CancelDragDrop deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::CancelDragDrop");
            mojo::internal::MessageDispatchContext context(message);
            impl->CancelDragDrop(
                std::move(p_window_id));
            return true;
        }
        }
        return false;
    }

    // static
    bool WindowTreeStubDispatch::AcceptWithResponder(
        WindowTree* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kWindowTree_NewWindow_Name: {
            break;
        }
        case internal::kWindowTree_NewTopLevelWindow_Name: {
            break;
        }
        case internal::kWindowTree_DeleteWindow_Name: {
            break;
        }
        case internal::kWindowTree_SetCapture_Name: {
            break;
        }
        case internal::kWindowTree_ReleaseCapture_Name: {
            break;
        }
        case internal::kWindowTree_StartPointerWatcher_Name: {
            break;
        }
        case internal::kWindowTree_StopPointerWatcher_Name: {
            break;
        }
        case internal::kWindowTree_SetWindowBounds_Name: {
            break;
        }
        case internal::kWindowTree_SetClientArea_Name: {
            break;
        }
        case internal::kWindowTree_SetHitTestMask_Name: {
            break;
        }
        case internal::kWindowTree_SetCanAcceptDrops_Name: {
            break;
        }
        case internal::kWindowTree_SetWindowVisibility_Name: {
            break;
        }
        case internal::kWindowTree_SetWindowProperty_Name: {
            break;
        }
        case internal::kWindowTree_SetWindowOpacity_Name: {
            break;
        }
        case internal::kWindowTree_AttachCompositorFrameSink_Name: {
            break;
        }
        case internal::kWindowTree_AddWindow_Name: {
            break;
        }
        case internal::kWindowTree_RemoveWindowFromParent_Name: {
            break;
        }
        case internal::kWindowTree_AddTransientWindow_Name: {
            break;
        }
        case internal::kWindowTree_RemoveTransientWindowFromParent_Name: {
            break;
        }
        case internal::kWindowTree_SetModal_Name: {
            break;
        }
        case internal::kWindowTree_ReorderWindow_Name: {
            break;
        }
        case internal::kWindowTree_GetWindowTree_Name: {
            internal::WindowTree_GetWindowTree_Params_Data* params = reinterpret_cast<internal::WindowTree_GetWindowTree_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowTree_GetWindowTree_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::GetWindowTree deserializer");
                return false;
            }
            WindowTree::GetWindowTreeCallback callback = WindowTree_GetWindowTree_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::GetWindowTree");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetWindowTree(
                std::move(p_window_id), std::move(callback));
            return true;
        }
        case internal::kWindowTree_Embed_Name: {
            internal::WindowTree_Embed_Params_Data* params = reinterpret_cast<internal::WindowTree_Embed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowTreeClientPtr p_client {};
            uint32_t p_embed_flags {};
            WindowTree_Embed_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_client = input_data_view.TakeClient<decltype(p_client)>();
            p_embed_flags = input_data_view.embed_flags();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::Embed deserializer");
                return false;
            }
            WindowTree::EmbedCallback callback = WindowTree_Embed_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::Embed");
            mojo::internal::MessageDispatchContext context(message);
            impl->Embed(
                std::move(p_window_id),
                std::move(p_client),
                std::move(p_embed_flags), std::move(callback));
            return true;
        }
        case internal::kWindowTree_SetFocus_Name: {
            break;
        }
        case internal::kWindowTree_SetCanFocus_Name: {
            break;
        }
        case internal::kWindowTree_SetPredefinedCursor_Name: {
            break;
        }
        case internal::kWindowTree_SetWindowTextInputState_Name: {
            break;
        }
        case internal::kWindowTree_SetImeVisibility_Name: {
            break;
        }
        case internal::kWindowTree_SetCanAcceptEvents_Name: {
            break;
        }
        case internal::kWindowTree_OnWindowInputEventAck_Name: {
            break;
        }
        case internal::kWindowTree_DeactivateWindow_Name: {
            break;
        }
        case internal::kWindowTree_GetWindowManagerClient_Name: {
            break;
        }
        case internal::kWindowTree_GetCursorLocationMemory_Name: {
            internal::WindowTree_GetCursorLocationMemory_Params_Data* params = reinterpret_cast<internal::WindowTree_GetCursorLocationMemory_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WindowTree_GetCursorLocationMemory_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTree::GetCursorLocationMemory deserializer");
                return false;
            }
            WindowTree::GetCursorLocationMemoryCallback callback = WindowTree_GetCursorLocationMemory_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTree::GetCursorLocationMemory");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetCursorLocationMemory(std::move(callback));
            return true;
        }
        case internal::kWindowTree_PerformWindowMove_Name: {
            break;
        }
        case internal::kWindowTree_CancelWindowMove_Name: {
            break;
        }
        case internal::kWindowTree_PerformDragDrop_Name: {
            break;
        }
        case internal::kWindowTree_CancelDragDrop_Name: {
            break;
        }
        }
        return false;
    }

    bool WindowTreeRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowTree RequestValidator");

        switch (message->header()->name) {
        case internal::kWindowTree_NewWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_NewWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_NewTopLevelWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_NewTopLevelWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_DeleteWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_DeleteWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetCapture_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetCapture_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_ReleaseCapture_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_ReleaseCapture_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_StartPointerWatcher_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_StartPointerWatcher_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_StopPointerWatcher_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_StopPointerWatcher_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetWindowBounds_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetWindowBounds_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetClientArea_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetClientArea_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetHitTestMask_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetHitTestMask_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetCanAcceptDrops_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetCanAcceptDrops_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetWindowVisibility_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetWindowVisibility_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetWindowProperty_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetWindowProperty_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetWindowOpacity_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetWindowOpacity_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_AttachCompositorFrameSink_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_AttachCompositorFrameSink_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_AddWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_AddWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_RemoveWindowFromParent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_RemoveWindowFromParent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_AddTransientWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_AddTransientWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_RemoveTransientWindowFromParent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_RemoveTransientWindowFromParent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetModal_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetModal_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_ReorderWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_ReorderWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_GetWindowTree_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_GetWindowTree_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_Embed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_Embed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetFocus_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetFocus_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetCanFocus_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetCanFocus_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetPredefinedCursor_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetPredefinedCursor_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetWindowTextInputState_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetWindowTextInputState_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetImeVisibility_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetImeVisibility_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_SetCanAcceptEvents_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_SetCanAcceptEvents_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_OnWindowInputEventAck_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_OnWindowInputEventAck_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_DeactivateWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_DeactivateWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_GetWindowManagerClient_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_GetWindowManagerClient_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_GetCursorLocationMemory_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_GetCursorLocationMemory_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_PerformWindowMove_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_PerformWindowMove_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_CancelWindowMove_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_CancelWindowMove_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_PerformDragDrop_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_PerformDragDrop_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_CancelDragDrop_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_CancelDragDrop_Params_Data>(
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

    bool WindowTreeResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowTree ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kWindowTree_GetWindowTree_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_GetWindowTree_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_Embed_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_Embed_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTree_GetCursorLocationMemory_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTree_GetCursorLocationMemory_ResponseParams_Data>(
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
    const char WindowTreeClient::Name_[] = "ui::mojom::WindowTreeClient";

    class WindowTreeClient_OnDragEnter_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        WindowTreeClient_OnDragEnter_ForwardToCallback(
            const WindowTreeClient::OnDragEnterCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        WindowTreeClient::OnDragEnterCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(WindowTreeClient_OnDragEnter_ForwardToCallback);
    };
    bool WindowTreeClient_OnDragEnter_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::WindowTreeClient_OnDragEnter_ResponseParams_Data* params = reinterpret_cast<internal::WindowTreeClient_OnDragEnter_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint32_t p_supported_op_bitmask {};
        WindowTreeClient_OnDragEnter_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_supported_op_bitmask = input_data_view.supported_op_bitmask();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WindowTreeClient::OnDragEnter response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_supported_op_bitmask));
        }
        return true;
    }

    class WindowTreeClient_OnDragOver_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        WindowTreeClient_OnDragOver_ForwardToCallback(
            const WindowTreeClient::OnDragOverCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        WindowTreeClient::OnDragOverCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(WindowTreeClient_OnDragOver_ForwardToCallback);
    };
    bool WindowTreeClient_OnDragOver_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::WindowTreeClient_OnDragOver_ResponseParams_Data* params = reinterpret_cast<internal::WindowTreeClient_OnDragOver_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint32_t p_supported_op_bitmask {};
        WindowTreeClient_OnDragOver_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_supported_op_bitmask = input_data_view.supported_op_bitmask();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WindowTreeClient::OnDragOver response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_supported_op_bitmask));
        }
        return true;
    }

    class WindowTreeClient_OnCompleteDrop_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        WindowTreeClient_OnCompleteDrop_ForwardToCallback(
            const WindowTreeClient::OnCompleteDropCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        WindowTreeClient::OnCompleteDropCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(WindowTreeClient_OnCompleteDrop_ForwardToCallback);
    };
    bool WindowTreeClient_OnCompleteDrop_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::WindowTreeClient_OnCompleteDrop_ResponseParams_Data* params = reinterpret_cast<internal::WindowTreeClient_OnCompleteDrop_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint32_t p_action_taken {};
        WindowTreeClient_OnCompleteDrop_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_action_taken = input_data_view.action_taken();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "WindowTreeClient::OnCompleteDrop response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_action_taken));
        }
        return true;
    }

    WindowTreeClientProxy::WindowTreeClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void WindowTreeClientProxy::OnEmbed(
        uint16_t in_connection_id, ::ui::mojom::WindowDataPtr in_root, WindowTreePtr in_tree, int64_t in_display_id, uint32_t in_focused_window, bool in_parent_drawn)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnEmbed_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::WindowDataDataView>(
            in_root, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnEmbed_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnEmbed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->connection_id = in_connection_id;
        typename decltype(params->root)::BaseType* root_ptr;
        mojo::internal::Serialize<::ui::mojom::WindowDataDataView>(
            in_root, builder.buffer(), &root_ptr, &serialization_context);
        params->root.Set(root_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->root.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null root in WindowTreeClient.OnEmbed request");
        mojo::internal::Serialize<::ui::mojom::WindowTreePtrDataView>(
            in_tree, &params->tree, &serialization_context);
        params->display_id = in_display_id;
        params->focused_window = in_focused_window;
        params->parent_drawn = in_parent_drawn;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnEmbeddedAppDisconnected(
        uint32_t in_window)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnEmbeddedAppDisconnected_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnUnembed(
        uint32_t in_window)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnUnembed_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnUnembed_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnUnembed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnCaptureChanged(
        uint32_t in_new_capture, uint32_t in_old_capture)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnCaptureChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnCaptureChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnCaptureChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->new_capture = in_new_capture;
        params->old_capture = in_old_capture;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnTopLevelCreated(
        uint32_t in_change_id, ::ui::mojom::WindowDataPtr in_data, int64_t in_display_id, bool in_parent_drawn)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnTopLevelCreated_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::WindowDataDataView>(
            in_data, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnTopLevelCreated_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnTopLevelCreated_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        typename decltype(params->data)::BaseType* data_ptr;
        mojo::internal::Serialize<::ui::mojom::WindowDataDataView>(
            in_data, builder.buffer(), &data_ptr, &serialization_context);
        params->data.Set(data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null data in WindowTreeClient.OnTopLevelCreated request");
        params->display_id = in_display_id;
        params->parent_drawn = in_parent_drawn;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowBoundsChanged(
        uint32_t in_window, const gfx::Rect& in_old_bounds, const gfx::Rect& in_new_bounds)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowBoundsChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
            in_old_bounds, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
            in_new_bounds, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowBoundsChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowBoundsChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        typename decltype(params->old_bounds)::BaseType* old_bounds_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectDataView>(
            in_old_bounds, builder.buffer(), &old_bounds_ptr, &serialization_context);
        params->old_bounds.Set(old_bounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->old_bounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null old_bounds in WindowTreeClient.OnWindowBoundsChanged request");
        typename decltype(params->new_bounds)::BaseType* new_bounds_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectDataView>(
            in_new_bounds, builder.buffer(), &new_bounds_ptr, &serialization_context);
        params->new_bounds.Set(new_bounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->new_bounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null new_bounds in WindowTreeClient.OnWindowBoundsChanged request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnClientAreaChanged(
        uint32_t in_window_id, const gfx::Insets& in_new_client_area, const std::vector<gfx::Rect>& in_new_additional_client_areas)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnClientAreaChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::InsetsDataView>(
            in_new_client_area, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gfx::mojom::RectDataView>>(
            in_new_additional_client_areas, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnClientAreaChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnClientAreaChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        typename decltype(params->new_client_area)::BaseType* new_client_area_ptr;
        mojo::internal::Serialize<::gfx::mojom::InsetsDataView>(
            in_new_client_area, builder.buffer(), &new_client_area_ptr, &serialization_context);
        params->new_client_area.Set(new_client_area_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->new_client_area.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null new_client_area in WindowTreeClient.OnClientAreaChanged request");
        typename decltype(params->new_additional_client_areas)::BaseType* new_additional_client_areas_ptr;
        const mojo::internal::ContainerValidateParams new_additional_client_areas_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::gfx::mojom::RectDataView>>(
            in_new_additional_client_areas, builder.buffer(), &new_additional_client_areas_ptr, &new_additional_client_areas_validate_params,
            &serialization_context);
        params->new_additional_client_areas.Set(new_additional_client_areas_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->new_additional_client_areas.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null new_additional_client_areas in WindowTreeClient.OnClientAreaChanged request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnTransientWindowAdded(
        uint32_t in_window_id, uint32_t in_transient_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnTransientWindowAdded_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnTransientWindowAdded_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnTransientWindowAdded_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        params->transient_window_id = in_transient_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnTransientWindowRemoved(
        uint32_t in_window_id, uint32_t in_transient_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnTransientWindowRemoved_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnTransientWindowRemoved_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnTransientWindowRemoved_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        params->transient_window_id = in_transient_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowHierarchyChanged(
        uint32_t in_window, uint32_t in_old_parent, uint32_t in_new_parent, std::vector<::ui::mojom::WindowDataPtr> in_windows)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowHierarchyChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::ui::mojom::WindowDataDataView>>(
            in_windows, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowHierarchyChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowHierarchyChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        params->old_parent = in_old_parent;
        params->new_parent = in_new_parent;
        typename decltype(params->windows)::BaseType* windows_ptr;
        const mojo::internal::ContainerValidateParams windows_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::ui::mojom::WindowDataDataView>>(
            in_windows, builder.buffer(), &windows_ptr, &windows_validate_params,
            &serialization_context);
        params->windows.Set(windows_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->windows.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null windows in WindowTreeClient.OnWindowHierarchyChanged request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowReordered(
        uint32_t in_window_id, uint32_t in_relative_window_id, ::ui::mojom::OrderDirection in_direction)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowReordered_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowReordered_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowReordered_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        params->relative_window_id = in_relative_window_id;
        mojo::internal::Serialize<::ui::mojom::OrderDirection>(
            in_direction, &params->direction);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowDeleted(
        uint32_t in_window)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowDeleted_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowDeleted_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowDeleted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowVisibilityChanged(
        uint32_t in_window, bool in_visible)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowVisibilityChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowVisibilityChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowVisibilityChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        params->visible = in_visible;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowOpacityChanged(
        uint32_t in_window, float in_old_opacity, float in_new_opacity)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowOpacityChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowOpacityChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowOpacityChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        params->old_opacity = in_old_opacity;
        params->new_opacity = in_new_opacity;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowParentDrawnStateChanged(
        uint32_t in_window, bool in_drawn)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowParentDrawnStateChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        params->drawn = in_drawn;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowSharedPropertyChanged(
        uint32_t in_window, const std::string& in_name, const base::Optional<std::vector<uint8_t>>& in_new_data)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_name, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_new_data, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowSharedPropertyChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        typename decltype(params->name)::BaseType* name_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_name, builder.buffer(), &name_ptr, &serialization_context);
        params->name.Set(name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null name in WindowTreeClient.OnWindowSharedPropertyChanged request");
        typename decltype(params->new_data)::BaseType* new_data_ptr;
        const mojo::internal::ContainerValidateParams new_data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_new_data, builder.buffer(), &new_data_ptr, &new_data_validate_params,
            &serialization_context);
        params->new_data.Set(new_data_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowInputEvent(
        uint32_t in_event_id, uint32_t in_window, std::unique_ptr<ui::Event> in_event, bool in_matches_pointer_watcher)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowInputEvent_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::EventDataView>(
            in_event, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowInputEvent_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowInputEvent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->event_id = in_event_id;
        params->window = in_window;
        typename decltype(params->event)::BaseType* event_ptr;
        mojo::internal::Serialize<::ui::mojom::EventDataView>(
            in_event, builder.buffer(), &event_ptr, &serialization_context);
        params->event.Set(event_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->event.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null event in WindowTreeClient.OnWindowInputEvent request");
        params->matches_pointer_watcher = in_matches_pointer_watcher;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnPointerEventObserved(
        std::unique_ptr<ui::Event> in_event, uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnPointerEventObserved_Params_Data);
        size += mojo::internal::PrepareToSerialize<::ui::mojom::EventDataView>(
            in_event, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnPointerEventObserved_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnPointerEventObserved_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->event)::BaseType* event_ptr;
        mojo::internal::Serialize<::ui::mojom::EventDataView>(
            in_event, builder.buffer(), &event_ptr, &serialization_context);
        params->event.Set(event_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->event.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null event in WindowTreeClient.OnPointerEventObserved request");
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowFocused(
        uint32_t in_focused_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowFocused_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowFocused_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowFocused_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->focused_window_id = in_focused_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnWindowPredefinedCursorChanged(
        uint32_t in_window_id, ::ui::mojom::Cursor in_cursor_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowPredefinedCursorChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data::New(builder.buffer());
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

    void WindowTreeClientProxy::OnWindowSurfaceChanged(
        uint32_t in_window_id, const cc::SurfaceInfo& in_surface_info)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnWindowSurfaceChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceInfoDataView>(
            in_surface_info, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnWindowSurfaceChanged_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnWindowSurfaceChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        typename decltype(params->surface_info)::BaseType* surface_info_ptr;
        mojo::internal::Serialize<::cc::mojom::SurfaceInfoDataView>(
            in_surface_info, builder.buffer(), &surface_info_ptr, &serialization_context);
        params->surface_info.Set(surface_info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->surface_info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null surface_info in WindowTreeClient.OnWindowSurfaceChanged request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnDragDropStart(
        const std::unordered_map<std::string, std::vector<uint8_t>>& in_drag_data)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnDragDropStart_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_drag_data, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnDragDropStart_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnDragDropStart_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->drag_data)::BaseType* drag_data_ptr;
        const mojo::internal::ContainerValidateParams drag_data_validate_params(
            new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
        mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
            in_drag_data, builder.buffer(), &drag_data_ptr, &drag_data_validate_params,
            &serialization_context);
        params->drag_data.Set(drag_data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->drag_data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null drag_data in WindowTreeClient.OnDragDropStart request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnDragEnter(
        uint32_t in_window, uint32_t in_key_state, const gfx::Point& in_screen_position, uint32_t in_effect_bitmask, const OnDragEnterCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnDragEnter_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointDataView>(
            in_screen_position, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kWindowTreeClient_OnDragEnter_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnDragEnter_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        params->key_state = in_key_state;
        typename decltype(params->screen_position)::BaseType* screen_position_ptr;
        mojo::internal::Serialize<::gfx::mojom::PointDataView>(
            in_screen_position, builder.buffer(), &screen_position_ptr, &serialization_context);
        params->screen_position.Set(screen_position_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->screen_position.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null screen_position in WindowTreeClient.OnDragEnter request");
        params->effect_bitmask = in_effect_bitmask;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new WindowTreeClient_OnDragEnter_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void WindowTreeClientProxy::OnDragOver(
        uint32_t in_window, uint32_t in_key_state, const gfx::Point& in_screen_position, uint32_t in_effect_bitmask, const OnDragOverCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnDragOver_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointDataView>(
            in_screen_position, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kWindowTreeClient_OnDragOver_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnDragOver_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        params->key_state = in_key_state;
        typename decltype(params->screen_position)::BaseType* screen_position_ptr;
        mojo::internal::Serialize<::gfx::mojom::PointDataView>(
            in_screen_position, builder.buffer(), &screen_position_ptr, &serialization_context);
        params->screen_position.Set(screen_position_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->screen_position.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null screen_position in WindowTreeClient.OnDragOver request");
        params->effect_bitmask = in_effect_bitmask;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new WindowTreeClient_OnDragOver_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void WindowTreeClientProxy::OnDragLeave(
        uint32_t in_window)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnDragLeave_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnDragLeave_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnDragLeave_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnCompleteDrop(
        uint32_t in_window, uint32_t in_key_state, const gfx::Point& in_screen_position, uint32_t in_effect_bitmask, const OnCompleteDropCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnCompleteDrop_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointDataView>(
            in_screen_position, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kWindowTreeClient_OnCompleteDrop_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnCompleteDrop_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        params->key_state = in_key_state;
        typename decltype(params->screen_position)::BaseType* screen_position_ptr;
        mojo::internal::Serialize<::gfx::mojom::PointDataView>(
            in_screen_position, builder.buffer(), &screen_position_ptr, &serialization_context);
        params->screen_position.Set(screen_position_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->screen_position.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null screen_position in WindowTreeClient.OnCompleteDrop request");
        params->effect_bitmask = in_effect_bitmask;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new WindowTreeClient_OnCompleteDrop_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void WindowTreeClientProxy::OnPerformDragDropCompleted(
        uint32_t in_window, bool in_success, uint32_t in_action_taken)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnPerformDragDropCompleted_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnPerformDragDropCompleted_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnPerformDragDropCompleted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window = in_window;
        params->success = in_success;
        params->action_taken = in_action_taken;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnDragDropDone()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnDragDropDone_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnDragDropDone_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnDragDropDone_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::OnChangeCompleted(
        uint32_t in_change_id, bool in_success)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnChangeCompleted_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_OnChangeCompleted_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_OnChangeCompleted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->change_id = in_change_id;
        params->success = in_success;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::RequestClose(
        uint32_t in_window_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_RequestClose_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_RequestClose_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_RequestClose_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->window_id = in_window_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void WindowTreeClientProxy::GetWindowManager(
        ::ui::mojom::WindowManagerAssociatedRequest in_internal)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_GetWindowManager_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeClient_GetWindowManager_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeClient_GetWindowManager_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::WindowManagerAssociatedRequestDataView>(
            in_internal, &params->internal, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->internal),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid internal in WindowTreeClient.GetWindowManager request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class WindowTreeClient_OnDragEnter_ProxyToResponder {
    public:
        static WindowTreeClient::OnDragEnterCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<WindowTreeClient_OnDragEnter_ProxyToResponder> proxy(
                new WindowTreeClient_OnDragEnter_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&WindowTreeClient_OnDragEnter_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~WindowTreeClient_OnDragEnter_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "WindowTreeClient::OnDragEnter() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        WindowTreeClient_OnDragEnter_ProxyToResponder(
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
            uint32_t in_supported_op_bitmask);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(WindowTreeClient_OnDragEnter_ProxyToResponder);
    };

    void WindowTreeClient_OnDragEnter_ProxyToResponder::Run(
        uint32_t in_supported_op_bitmask)
    {
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnDragEnter_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kWindowTreeClient_OnDragEnter_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::WindowTreeClient_OnDragEnter_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->supported_op_bitmask = in_supported_op_bitmask;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class WindowTreeClient_OnDragOver_ProxyToResponder {
    public:
        static WindowTreeClient::OnDragOverCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<WindowTreeClient_OnDragOver_ProxyToResponder> proxy(
                new WindowTreeClient_OnDragOver_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&WindowTreeClient_OnDragOver_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~WindowTreeClient_OnDragOver_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "WindowTreeClient::OnDragOver() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        WindowTreeClient_OnDragOver_ProxyToResponder(
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
            uint32_t in_supported_op_bitmask);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(WindowTreeClient_OnDragOver_ProxyToResponder);
    };

    void WindowTreeClient_OnDragOver_ProxyToResponder::Run(
        uint32_t in_supported_op_bitmask)
    {
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnDragOver_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kWindowTreeClient_OnDragOver_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::WindowTreeClient_OnDragOver_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->supported_op_bitmask = in_supported_op_bitmask;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class WindowTreeClient_OnCompleteDrop_ProxyToResponder {
    public:
        static WindowTreeClient::OnCompleteDropCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<WindowTreeClient_OnCompleteDrop_ProxyToResponder> proxy(
                new WindowTreeClient_OnCompleteDrop_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&WindowTreeClient_OnCompleteDrop_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~WindowTreeClient_OnCompleteDrop_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "WindowTreeClient::OnCompleteDrop() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        WindowTreeClient_OnCompleteDrop_ProxyToResponder(
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
            uint32_t in_action_taken);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(WindowTreeClient_OnCompleteDrop_ProxyToResponder);
    };

    void WindowTreeClient_OnCompleteDrop_ProxyToResponder::Run(
        uint32_t in_action_taken)
    {
        size_t size = sizeof(::ui::mojom::internal::WindowTreeClient_OnCompleteDrop_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kWindowTreeClient_OnCompleteDrop_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::ui::mojom::internal::WindowTreeClient_OnCompleteDrop_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->action_taken = in_action_taken;
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
    bool WindowTreeClientStubDispatch::Accept(
        WindowTreeClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kWindowTreeClient_OnEmbed_Name: {
            internal::WindowTreeClient_OnEmbed_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnEmbed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint16_t p_connection_id {};
            ::ui::mojom::WindowDataPtr p_root {};
            WindowTreePtr p_tree {};
            int64_t p_display_id {};
            uint32_t p_focused_window {};
            bool p_parent_drawn {};
            WindowTreeClient_OnEmbed_ParamsDataView input_data_view(params,
                context);

            p_connection_id = input_data_view.connection_id();
            if (!input_data_view.ReadRoot(&p_root))
                success = false;
            p_tree = input_data_view.TakeTree<decltype(p_tree)>();
            p_display_id = input_data_view.display_id();
            p_focused_window = input_data_view.focused_window();
            p_parent_drawn = input_data_view.parent_drawn();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnEmbed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnEmbed");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnEmbed(
                std::move(p_connection_id),
                std::move(p_root),
                std::move(p_tree),
                std::move(p_display_id),
                std::move(p_focused_window),
                std::move(p_parent_drawn));
            return true;
        }
        case internal::kWindowTreeClient_OnEmbeddedAppDisconnected_Name: {
            internal::WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            WindowTreeClient_OnEmbeddedAppDisconnected_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnEmbeddedAppDisconnected deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnEmbeddedAppDisconnected");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnEmbeddedAppDisconnected(
                std::move(p_window));
            return true;
        }
        case internal::kWindowTreeClient_OnUnembed_Name: {
            internal::WindowTreeClient_OnUnembed_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnUnembed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            WindowTreeClient_OnUnembed_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnUnembed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnUnembed");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnUnembed(
                std::move(p_window));
            return true;
        }
        case internal::kWindowTreeClient_OnCaptureChanged_Name: {
            internal::WindowTreeClient_OnCaptureChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnCaptureChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_new_capture {};
            uint32_t p_old_capture {};
            WindowTreeClient_OnCaptureChanged_ParamsDataView input_data_view(params,
                context);

            p_new_capture = input_data_view.new_capture();
            p_old_capture = input_data_view.old_capture();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnCaptureChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnCaptureChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnCaptureChanged(
                std::move(p_new_capture),
                std::move(p_old_capture));
            return true;
        }
        case internal::kWindowTreeClient_OnTopLevelCreated_Name: {
            internal::WindowTreeClient_OnTopLevelCreated_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnTopLevelCreated_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            ::ui::mojom::WindowDataPtr p_data {};
            int64_t p_display_id {};
            bool p_parent_drawn {};
            WindowTreeClient_OnTopLevelCreated_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            if (!input_data_view.ReadData(&p_data))
                success = false;
            p_display_id = input_data_view.display_id();
            p_parent_drawn = input_data_view.parent_drawn();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnTopLevelCreated deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnTopLevelCreated");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnTopLevelCreated(
                std::move(p_change_id),
                std::move(p_data),
                std::move(p_display_id),
                std::move(p_parent_drawn));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowBoundsChanged_Name: {
            internal::WindowTreeClient_OnWindowBoundsChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowBoundsChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            gfx::Rect p_old_bounds {};
            gfx::Rect p_new_bounds {};
            WindowTreeClient_OnWindowBoundsChanged_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            if (!input_data_view.ReadOldBounds(&p_old_bounds))
                success = false;
            if (!input_data_view.ReadNewBounds(&p_new_bounds))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowBoundsChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowBoundsChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowBoundsChanged(
                std::move(p_window),
                std::move(p_old_bounds),
                std::move(p_new_bounds));
            return true;
        }
        case internal::kWindowTreeClient_OnClientAreaChanged_Name: {
            internal::WindowTreeClient_OnClientAreaChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnClientAreaChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            gfx::Insets p_new_client_area {};
            std::vector<gfx::Rect> p_new_additional_client_areas {};
            WindowTreeClient_OnClientAreaChanged_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadNewClientArea(&p_new_client_area))
                success = false;
            if (!input_data_view.ReadNewAdditionalClientAreas(&p_new_additional_client_areas))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnClientAreaChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnClientAreaChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnClientAreaChanged(
                std::move(p_window_id),
                std::move(p_new_client_area),
                std::move(p_new_additional_client_areas));
            return true;
        }
        case internal::kWindowTreeClient_OnTransientWindowAdded_Name: {
            internal::WindowTreeClient_OnTransientWindowAdded_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnTransientWindowAdded_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            uint32_t p_transient_window_id {};
            WindowTreeClient_OnTransientWindowAdded_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_transient_window_id = input_data_view.transient_window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnTransientWindowAdded deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnTransientWindowAdded");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnTransientWindowAdded(
                std::move(p_window_id),
                std::move(p_transient_window_id));
            return true;
        }
        case internal::kWindowTreeClient_OnTransientWindowRemoved_Name: {
            internal::WindowTreeClient_OnTransientWindowRemoved_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnTransientWindowRemoved_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            uint32_t p_transient_window_id {};
            WindowTreeClient_OnTransientWindowRemoved_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_transient_window_id = input_data_view.transient_window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnTransientWindowRemoved deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnTransientWindowRemoved");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnTransientWindowRemoved(
                std::move(p_window_id),
                std::move(p_transient_window_id));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowHierarchyChanged_Name: {
            internal::WindowTreeClient_OnWindowHierarchyChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowHierarchyChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            uint32_t p_old_parent {};
            uint32_t p_new_parent {};
            std::vector<::ui::mojom::WindowDataPtr> p_windows {};
            WindowTreeClient_OnWindowHierarchyChanged_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            p_old_parent = input_data_view.old_parent();
            p_new_parent = input_data_view.new_parent();
            if (!input_data_view.ReadWindows(&p_windows))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowHierarchyChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowHierarchyChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowHierarchyChanged(
                std::move(p_window),
                std::move(p_old_parent),
                std::move(p_new_parent),
                std::move(p_windows));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowReordered_Name: {
            internal::WindowTreeClient_OnWindowReordered_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowReordered_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            uint32_t p_relative_window_id {};
            ::ui::mojom::OrderDirection p_direction {};
            WindowTreeClient_OnWindowReordered_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            p_relative_window_id = input_data_view.relative_window_id();
            if (!input_data_view.ReadDirection(&p_direction))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowReordered deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowReordered");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowReordered(
                std::move(p_window_id),
                std::move(p_relative_window_id),
                std::move(p_direction));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowDeleted_Name: {
            internal::WindowTreeClient_OnWindowDeleted_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowDeleted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            WindowTreeClient_OnWindowDeleted_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowDeleted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowDeleted");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowDeleted(
                std::move(p_window));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowVisibilityChanged_Name: {
            internal::WindowTreeClient_OnWindowVisibilityChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowVisibilityChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            bool p_visible {};
            WindowTreeClient_OnWindowVisibilityChanged_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            p_visible = input_data_view.visible();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowVisibilityChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowVisibilityChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowVisibilityChanged(
                std::move(p_window),
                std::move(p_visible));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowOpacityChanged_Name: {
            internal::WindowTreeClient_OnWindowOpacityChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowOpacityChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            float p_old_opacity {};
            float p_new_opacity {};
            WindowTreeClient_OnWindowOpacityChanged_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            p_old_opacity = input_data_view.old_opacity();
            p_new_opacity = input_data_view.new_opacity();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowOpacityChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowOpacityChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowOpacityChanged(
                std::move(p_window),
                std::move(p_old_opacity),
                std::move(p_new_opacity));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowParentDrawnStateChanged_Name: {
            internal::WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            bool p_drawn {};
            WindowTreeClient_OnWindowParentDrawnStateChanged_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            p_drawn = input_data_view.drawn();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowParentDrawnStateChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowParentDrawnStateChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowParentDrawnStateChanged(
                std::move(p_window),
                std::move(p_drawn));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowSharedPropertyChanged_Name: {
            internal::WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            std::string p_name {};
            base::Optional<std::vector<uint8_t>> p_new_data {};
            WindowTreeClient_OnWindowSharedPropertyChanged_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            if (!input_data_view.ReadName(&p_name))
                success = false;
            if (!input_data_view.ReadNewData(&p_new_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowSharedPropertyChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowSharedPropertyChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowSharedPropertyChanged(
                std::move(p_window),
                std::move(p_name),
                std::move(p_new_data));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowInputEvent_Name: {
            internal::WindowTreeClient_OnWindowInputEvent_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowInputEvent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_event_id {};
            uint32_t p_window {};
            std::unique_ptr<ui::Event> p_event {};
            bool p_matches_pointer_watcher {};
            WindowTreeClient_OnWindowInputEvent_ParamsDataView input_data_view(params,
                context);

            p_event_id = input_data_view.event_id();
            p_window = input_data_view.window();
            if (!input_data_view.ReadEvent(&p_event))
                success = false;
            p_matches_pointer_watcher = input_data_view.matches_pointer_watcher();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowInputEvent deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowInputEvent");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowInputEvent(
                std::move(p_event_id),
                std::move(p_window),
                std::move(p_event),
                std::move(p_matches_pointer_watcher));
            return true;
        }
        case internal::kWindowTreeClient_OnPointerEventObserved_Name: {
            internal::WindowTreeClient_OnPointerEventObserved_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnPointerEventObserved_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::unique_ptr<ui::Event> p_event {};
            uint32_t p_window_id {};
            WindowTreeClient_OnPointerEventObserved_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadEvent(&p_event))
                success = false;
            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnPointerEventObserved deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnPointerEventObserved");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnPointerEventObserved(
                std::move(p_event),
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowFocused_Name: {
            internal::WindowTreeClient_OnWindowFocused_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowFocused_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_focused_window_id {};
            WindowTreeClient_OnWindowFocused_ParamsDataView input_data_view(params,
                context);

            p_focused_window_id = input_data_view.focused_window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowFocused deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowFocused");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowFocused(
                std::move(p_focused_window_id));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowPredefinedCursorChanged_Name: {
            internal::WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            ::ui::mojom::Cursor p_cursor_id {};
            WindowTreeClient_OnWindowPredefinedCursorChanged_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadCursorId(&p_cursor_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowPredefinedCursorChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowPredefinedCursorChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowPredefinedCursorChanged(
                std::move(p_window_id),
                std::move(p_cursor_id));
            return true;
        }
        case internal::kWindowTreeClient_OnWindowSurfaceChanged_Name: {
            internal::WindowTreeClient_OnWindowSurfaceChanged_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnWindowSurfaceChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            cc::SurfaceInfo p_surface_info {};
            WindowTreeClient_OnWindowSurfaceChanged_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!input_data_view.ReadSurfaceInfo(&p_surface_info))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnWindowSurfaceChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnWindowSurfaceChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWindowSurfaceChanged(
                std::move(p_window_id),
                std::move(p_surface_info));
            return true;
        }
        case internal::kWindowTreeClient_OnDragDropStart_Name: {
            internal::WindowTreeClient_OnDragDropStart_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnDragDropStart_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::unordered_map<std::string, std::vector<uint8_t>> p_drag_data {};
            WindowTreeClient_OnDragDropStart_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDragData(&p_drag_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnDragDropStart deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnDragDropStart");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDragDropStart(
                std::move(p_drag_data));
            return true;
        }
        case internal::kWindowTreeClient_OnDragEnter_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnDragOver_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnDragLeave_Name: {
            internal::WindowTreeClient_OnDragLeave_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnDragLeave_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            WindowTreeClient_OnDragLeave_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnDragLeave deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnDragLeave");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDragLeave(
                std::move(p_window));
            return true;
        }
        case internal::kWindowTreeClient_OnCompleteDrop_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnPerformDragDropCompleted_Name: {
            internal::WindowTreeClient_OnPerformDragDropCompleted_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnPerformDragDropCompleted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            bool p_success {};
            uint32_t p_action_taken {};
            WindowTreeClient_OnPerformDragDropCompleted_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            p_success = input_data_view.success();
            p_action_taken = input_data_view.action_taken();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnPerformDragDropCompleted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnPerformDragDropCompleted");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnPerformDragDropCompleted(
                std::move(p_window),
                std::move(p_success),
                std::move(p_action_taken));
            return true;
        }
        case internal::kWindowTreeClient_OnDragDropDone_Name: {
            internal::WindowTreeClient_OnDragDropDone_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnDragDropDone_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WindowTreeClient_OnDragDropDone_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnDragDropDone deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnDragDropDone");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDragDropDone();
            return true;
        }
        case internal::kWindowTreeClient_OnChangeCompleted_Name: {
            internal::WindowTreeClient_OnChangeCompleted_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnChangeCompleted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_change_id {};
            bool p_success {};
            WindowTreeClient_OnChangeCompleted_ParamsDataView input_data_view(params,
                context);

            p_change_id = input_data_view.change_id();
            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnChangeCompleted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnChangeCompleted");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnChangeCompleted(
                std::move(p_change_id),
                std::move(p_success));
            return true;
        }
        case internal::kWindowTreeClient_RequestClose_Name: {
            internal::WindowTreeClient_RequestClose_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_RequestClose_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window_id {};
            WindowTreeClient_RequestClose_ParamsDataView input_data_view(params,
                context);

            p_window_id = input_data_view.window_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::RequestClose deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::RequestClose");
            mojo::internal::MessageDispatchContext context(message);
            impl->RequestClose(
                std::move(p_window_id));
            return true;
        }
        case internal::kWindowTreeClient_GetWindowManager_Name: {
            internal::WindowTreeClient_GetWindowManager_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_GetWindowManager_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::ui::mojom::WindowManagerAssociatedRequest p_internal {};
            WindowTreeClient_GetWindowManager_ParamsDataView input_data_view(params,
                context);

            p_internal = input_data_view.TakeInternal<decltype(p_internal)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::GetWindowManager deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::GetWindowManager");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetWindowManager(
                std::move(p_internal));
            return true;
        }
        }
        return false;
    }

    // static
    bool WindowTreeClientStubDispatch::AcceptWithResponder(
        WindowTreeClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kWindowTreeClient_OnEmbed_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnEmbeddedAppDisconnected_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnUnembed_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnCaptureChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnTopLevelCreated_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowBoundsChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnClientAreaChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnTransientWindowAdded_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnTransientWindowRemoved_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowHierarchyChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowReordered_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowDeleted_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowVisibilityChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowOpacityChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowParentDrawnStateChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowSharedPropertyChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowInputEvent_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnPointerEventObserved_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowFocused_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowPredefinedCursorChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnWindowSurfaceChanged_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnDragDropStart_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnDragEnter_Name: {
            internal::WindowTreeClient_OnDragEnter_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnDragEnter_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            uint32_t p_key_state {};
            gfx::Point p_screen_position {};
            uint32_t p_effect_bitmask {};
            WindowTreeClient_OnDragEnter_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            p_key_state = input_data_view.key_state();
            if (!input_data_view.ReadScreenPosition(&p_screen_position))
                success = false;
            p_effect_bitmask = input_data_view.effect_bitmask();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnDragEnter deserializer");
                return false;
            }
            WindowTreeClient::OnDragEnterCallback callback = WindowTreeClient_OnDragEnter_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnDragEnter");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDragEnter(
                std::move(p_window),
                std::move(p_key_state),
                std::move(p_screen_position),
                std::move(p_effect_bitmask), std::move(callback));
            return true;
        }
        case internal::kWindowTreeClient_OnDragOver_Name: {
            internal::WindowTreeClient_OnDragOver_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnDragOver_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            uint32_t p_key_state {};
            gfx::Point p_screen_position {};
            uint32_t p_effect_bitmask {};
            WindowTreeClient_OnDragOver_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            p_key_state = input_data_view.key_state();
            if (!input_data_view.ReadScreenPosition(&p_screen_position))
                success = false;
            p_effect_bitmask = input_data_view.effect_bitmask();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnDragOver deserializer");
                return false;
            }
            WindowTreeClient::OnDragOverCallback callback = WindowTreeClient_OnDragOver_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnDragOver");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDragOver(
                std::move(p_window),
                std::move(p_key_state),
                std::move(p_screen_position),
                std::move(p_effect_bitmask), std::move(callback));
            return true;
        }
        case internal::kWindowTreeClient_OnDragLeave_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnCompleteDrop_Name: {
            internal::WindowTreeClient_OnCompleteDrop_Params_Data* params = reinterpret_cast<internal::WindowTreeClient_OnCompleteDrop_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_window {};
            uint32_t p_key_state {};
            gfx::Point p_screen_position {};
            uint32_t p_effect_bitmask {};
            WindowTreeClient_OnCompleteDrop_ParamsDataView input_data_view(params,
                context);

            p_window = input_data_view.window();
            p_key_state = input_data_view.key_state();
            if (!input_data_view.ReadScreenPosition(&p_screen_position))
                success = false;
            p_effect_bitmask = input_data_view.effect_bitmask();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeClient::OnCompleteDrop deserializer");
                return false;
            }
            WindowTreeClient::OnCompleteDropCallback callback = WindowTreeClient_OnCompleteDrop_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeClient::OnCompleteDrop");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnCompleteDrop(
                std::move(p_window),
                std::move(p_key_state),
                std::move(p_screen_position),
                std::move(p_effect_bitmask), std::move(callback));
            return true;
        }
        case internal::kWindowTreeClient_OnPerformDragDropCompleted_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnDragDropDone_Name: {
            break;
        }
        case internal::kWindowTreeClient_OnChangeCompleted_Name: {
            break;
        }
        case internal::kWindowTreeClient_RequestClose_Name: {
            break;
        }
        case internal::kWindowTreeClient_GetWindowManager_Name: {
            break;
        }
        }
        return false;
    }

    bool WindowTreeClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowTreeClient RequestValidator");

        switch (message->header()->name) {
        case internal::kWindowTreeClient_OnEmbed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnEmbed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnEmbeddedAppDisconnected_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnUnembed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnUnembed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnCaptureChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnCaptureChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnTopLevelCreated_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnTopLevelCreated_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowBoundsChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowBoundsChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnClientAreaChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnClientAreaChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnTransientWindowAdded_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnTransientWindowAdded_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnTransientWindowRemoved_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnTransientWindowRemoved_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowHierarchyChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowHierarchyChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowReordered_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowReordered_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowDeleted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowDeleted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowVisibilityChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowVisibilityChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowOpacityChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowOpacityChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowParentDrawnStateChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowSharedPropertyChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowInputEvent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowInputEvent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnPointerEventObserved_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnPointerEventObserved_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowFocused_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowFocused_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowPredefinedCursorChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnWindowSurfaceChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnWindowSurfaceChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnDragDropStart_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnDragDropStart_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnDragEnter_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnDragEnter_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnDragOver_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnDragOver_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnDragLeave_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnDragLeave_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnCompleteDrop_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnCompleteDrop_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnPerformDragDropCompleted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnPerformDragDropCompleted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnDragDropDone_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnDragDropDone_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnChangeCompleted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnChangeCompleted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_RequestClose_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_RequestClose_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_GetWindowManager_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_GetWindowManager_Params_Data>(
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

    bool WindowTreeClientResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowTreeClient ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kWindowTreeClient_OnDragEnter_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnDragEnter_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnDragOver_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnDragOver_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kWindowTreeClient_OnCompleteDrop_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeClient_OnCompleteDrop_ResponseParams_Data>(
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
    const char WindowTreeFactory::Name_[] = "ui::mojom::WindowTreeFactory";

    WindowTreeFactoryProxy::WindowTreeFactoryProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void WindowTreeFactoryProxy::CreateWindowTree(
        WindowTreeRequest in_tree_request, WindowTreeClientPtr in_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::WindowTreeFactory_CreateWindowTree_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kWindowTreeFactory_CreateWindowTree_Name, size);

        auto params = ::ui::mojom::internal::WindowTreeFactory_CreateWindowTree_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::ui::mojom::WindowTreeRequestDataView>(
            in_tree_request, &params->tree_request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->tree_request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid tree_request in WindowTreeFactory.CreateWindowTree request");
        mojo::internal::Serialize<::ui::mojom::WindowTreeClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in WindowTreeFactory.CreateWindowTree request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool WindowTreeFactoryStubDispatch::Accept(
        WindowTreeFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kWindowTreeFactory_CreateWindowTree_Name: {
            internal::WindowTreeFactory_CreateWindowTree_Params_Data* params = reinterpret_cast<internal::WindowTreeFactory_CreateWindowTree_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            WindowTreeRequest p_tree_request {};
            WindowTreeClientPtr p_client {};
            WindowTreeFactory_CreateWindowTree_ParamsDataView input_data_view(params,
                context);

            p_tree_request = input_data_view.TakeTreeRequest<decltype(p_tree_request)>();
            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "WindowTreeFactory::CreateWindowTree deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "WindowTreeFactory::CreateWindowTree");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateWindowTree(
                std::move(p_tree_request),
                std::move(p_client));
            return true;
        }
        }
        return false;
    }

    // static
    bool WindowTreeFactoryStubDispatch::AcceptWithResponder(
        WindowTreeFactory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kWindowTreeFactory_CreateWindowTree_Name: {
            break;
        }
        }
        return false;
    }

    bool WindowTreeFactoryRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "WindowTreeFactory RequestValidator");

        switch (message->header()->name) {
        case internal::kWindowTreeFactory_CreateWindowTree_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::WindowTreeFactory_CreateWindowTree_Params_Data>(
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

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif