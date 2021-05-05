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

#include "content/common/renderer.mojom.h"

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
#include "content/common/bluetooth/web_bluetooth_device_id_struct_traits.h"
#include "content/common/frame_messages.h"
#include "content/common/indexed_db/indexed_db_enum_traits.h"
#include "content/common/indexed_db/indexed_db_struct_traits.h"
#include "content/common/media/media_devices_param_traits.h"
#include "content/common/media/media_session_struct_traits.h"
#include "content/common/resource_messages.h"
#include "content/common/service_worker/embedded_worker_messages.h"
#include "content/common/service_worker/service_worker_messages.h"
#include "content/common/service_worker/service_worker_status_code_traits.h"
#include "content/common/service_worker/service_worker_types_traits.h"
#include "content/common/view_messages.h"
#include "content/public/common/common_param_traits.h"
#include "content/public/common/common_param_traits_macros.h"
#include "content/public/common/referrer_struct_traits.h"
#include "device/bluetooth/public/interfaces/uuid_struct_traits.h"
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
#include "media/capture/ipc/capture_param_traits.h"
#include "media/capture/ipc/capture_param_traits_macros.h"
#include "media/capture/mojo/video_capture_types_typemap_traits.h"
#include "media/mojo/interfaces/pipeline_statistics_struct_traits.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/service_manager/public/cpp/identity_struct_traits.h"
#include "services/service_manager/public/cpp/interface_provider_spec_struct_traits.h"
#include "services/service_manager/public/cpp/service_info_struct_traits.h"
#include "services/ui/public/interfaces/display/display_struct_traits.h"
#include "services/ui/public/interfaces/ime/ime_struct_traits.h"
#include "services/video_capture/public/interfaces/capture_settings_traits.h"
#include "services/video_capture/public/interfaces/device_descriptor_struct_traits.h"
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
#include "ui/base/mojo/window_open_disposition_enum_traits.h"
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
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace content {
namespace mojom { // static
    CreateViewParamsPtr CreateViewParams::New()
    {
        CreateViewParamsPtr rv;
        mojo::internal::StructHelper<CreateViewParams>::Initialize(&rv);
        return rv;
    }

    CreateViewParams::CreateViewParams()
        : renderer_preferences()
        , web_preferences()
        , view_id(::IPC::mojom::kRoutingIdNone)
        , main_frame_routing_id(::IPC::mojom::kRoutingIdNone)
        , main_frame_widget_routing_id(::IPC::mojom::kRoutingIdNone)
        , session_storage_namespace_id()
        , opener_frame_route_id(::IPC::mojom::kRoutingIdNone)
        , swapped_out()
        , replicated_frame_state()
        , proxy_routing_id(::IPC::mojom::kRoutingIdNone)
        , hidden()
        , never_visible()
        , window_was_created_with_opener()
        , initial_size()
        , enable_auto_resize()
        , min_size()
        , max_size()
        , page_zoom_level()
        , image_decode_color_space()
    {
    }

    CreateViewParams::~CreateViewParams()
    {
    } // static
    CreateFrameWidgetParamsPtr CreateFrameWidgetParams::New()
    {
        CreateFrameWidgetParamsPtr rv;
        mojo::internal::StructHelper<CreateFrameWidgetParams>::Initialize(&rv);
        return rv;
    }

    CreateFrameWidgetParams::CreateFrameWidgetParams()
        : routing_id()
        , hidden()
    {
    }

    CreateFrameWidgetParams::~CreateFrameWidgetParams()
    {
    }
    size_t CreateFrameWidgetParams::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->routing_id);
        seed = mojo::internal::Hash(seed, this->hidden);
        return seed;
    } // static
    CreateFrameParamsPtr CreateFrameParams::New()
    {
        CreateFrameParamsPtr rv;
        mojo::internal::StructHelper<CreateFrameParams>::Initialize(&rv);
        return rv;
    }

    CreateFrameParams::CreateFrameParams()
        : routing_id()
        , proxy_routing_id()
        , opener_routing_id()
        , parent_routing_id()
        , previous_sibling_routing_id()
        , replication_state()
        , frame_owner_properties()
        , widget_params()
    {
    }

    CreateFrameParams::~CreateFrameParams()
    {
    } // static
    UpdateScrollbarThemeParamsPtr UpdateScrollbarThemeParams::New()
    {
        UpdateScrollbarThemeParamsPtr rv;
        mojo::internal::StructHelper<UpdateScrollbarThemeParams>::Initialize(&rv);
        return rv;
    }

    UpdateScrollbarThemeParams::UpdateScrollbarThemeParams()
        : initial_button_delay()
        , autoscroll_button_delay()
        , jump_on_track_click()
        , preferred_scroller_style()
        , redraw()
        , button_placement()
    {
    }

    UpdateScrollbarThemeParams::~UpdateScrollbarThemeParams()
    {
    }
    size_t UpdateScrollbarThemeParams::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->initial_button_delay);
        seed = mojo::internal::Hash(seed, this->autoscroll_button_delay);
        seed = mojo::internal::Hash(seed, this->jump_on_track_click);
        seed = mojo::internal::Hash(seed, this->preferred_scroller_style);
        seed = mojo::internal::Hash(seed, this->redraw);
        seed = mojo::internal::Hash(seed, this->button_placement);
        return seed;
    }
    const char Renderer::Name_[] = "content::mojom::Renderer";

    RendererProxy::RendererProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void RendererProxy::CreateView(
        CreateViewParamsPtr in_params)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::Renderer_CreateView_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::CreateViewParamsDataView>(
            in_params, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRenderer_CreateView_Name, size);

        auto params = ::content::mojom::internal::Renderer_CreateView_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->params)::BaseType* params_ptr;
        mojo::internal::Serialize<::content::mojom::CreateViewParamsDataView>(
            in_params, builder.buffer(), &params_ptr, &serialization_context);
        params->params.Set(params_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->params.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null params in Renderer.CreateView request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::CreateFrame(
        CreateFrameParamsPtr in_params)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::Renderer_CreateFrame_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::CreateFrameParamsDataView>(
            in_params, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRenderer_CreateFrame_Name, size);

        auto params = ::content::mojom::internal::Renderer_CreateFrame_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->params)::BaseType* params_ptr;
        mojo::internal::Serialize<::content::mojom::CreateFrameParamsDataView>(
            in_params, builder.buffer(), &params_ptr, &serialization_context);
        params->params.Set(params_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->params.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null params in Renderer.CreateFrame request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::CreateFrameProxy(
        int32_t in_routing_id, int32_t in_render_view_routing_id, int32_t in_opener_routing_id, int32_t in_parent_routing_id, const content::FrameReplicationState& in_replication_state)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::Renderer_CreateFrameProxy_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::FrameReplicationStateDataView>(
            in_replication_state, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRenderer_CreateFrameProxy_Name, size);

        auto params = ::content::mojom::internal::Renderer_CreateFrameProxy_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->routing_id = in_routing_id;
        params->render_view_routing_id = in_render_view_routing_id;
        params->opener_routing_id = in_opener_routing_id;
        params->parent_routing_id = in_parent_routing_id;
        typename decltype(params->replication_state)::BaseType* replication_state_ptr;
        mojo::internal::Serialize<::content::mojom::FrameReplicationStateDataView>(
            in_replication_state, builder.buffer(), &replication_state_ptr, &serialization_context);
        params->replication_state.Set(replication_state_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->replication_state.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null replication_state in Renderer.CreateFrameProxy request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::OnNetworkConnectionChanged(
        net::NetworkChangeNotifier::ConnectionType in_connection_type, double in_max_bandwidth_mbps)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::Renderer_OnNetworkConnectionChanged_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRenderer_OnNetworkConnectionChanged_Name, size);

        auto params = ::content::mojom::internal::Renderer_OnNetworkConnectionChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::content::mojom::NetworkConnectionType>(
            in_connection_type, &params->connection_type);
        params->max_bandwidth_mbps = in_max_bandwidth_mbps;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::SetWebKitSharedTimersSuspended(
        bool in_suspend)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::Renderer_SetWebKitSharedTimersSuspended_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRenderer_SetWebKitSharedTimersSuspended_Name, size);

        auto params = ::content::mojom::internal::Renderer_SetWebKitSharedTimersSuspended_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->suspend = in_suspend;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::UpdateScrollbarTheme(
        UpdateScrollbarThemeParamsPtr in_params)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::Renderer_UpdateScrollbarTheme_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::UpdateScrollbarThemeParamsDataView>(
            in_params, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRenderer_UpdateScrollbarTheme_Name, size);

        auto params = ::content::mojom::internal::Renderer_UpdateScrollbarTheme_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->params)::BaseType* params_ptr;
        mojo::internal::Serialize<::content::mojom::UpdateScrollbarThemeParamsDataView>(
            in_params, builder.buffer(), &params_ptr, &serialization_context);
        params->params.Set(params_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->params.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null params in Renderer.UpdateScrollbarTheme request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::OnSystemColorsChanged(
        int32_t in_aqua_color_variant, const std::string& in_highlight_text_color, const std::string& in_highlight_color)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::Renderer_OnSystemColorsChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_highlight_text_color, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_highlight_color, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRenderer_OnSystemColorsChanged_Name, size);

        auto params = ::content::mojom::internal::Renderer_OnSystemColorsChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->aqua_color_variant = in_aqua_color_variant;
        typename decltype(params->highlight_text_color)::BaseType* highlight_text_color_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_highlight_text_color, builder.buffer(), &highlight_text_color_ptr, &serialization_context);
        params->highlight_text_color.Set(highlight_text_color_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->highlight_text_color.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null highlight_text_color in Renderer.OnSystemColorsChanged request");
        typename decltype(params->highlight_color)::BaseType* highlight_color_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_highlight_color, builder.buffer(), &highlight_color_ptr, &serialization_context);
        params->highlight_color.Set(highlight_color_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->highlight_color.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null highlight_color in Renderer.OnSystemColorsChanged request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::PurgePluginListCache(
        bool in_reload_pages)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::Renderer_PurgePluginListCache_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRenderer_PurgePluginListCache_Name, size);

        auto params = ::content::mojom::internal::Renderer_PurgePluginListCache_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->reload_pages = in_reload_pages;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool RendererStubDispatch::Accept(
        Renderer* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRenderer_CreateView_Name: {
            internal::Renderer_CreateView_Params_Data* params = reinterpret_cast<internal::Renderer_CreateView_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            CreateViewParamsPtr p_params {};
            Renderer_CreateView_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadParams(&p_params))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::CreateView deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::CreateView");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateView(
                std::move(p_params));
            return true;
        }
        case internal::kRenderer_CreateFrame_Name: {
            internal::Renderer_CreateFrame_Params_Data* params = reinterpret_cast<internal::Renderer_CreateFrame_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            CreateFrameParamsPtr p_params {};
            Renderer_CreateFrame_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadParams(&p_params))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::CreateFrame deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::CreateFrame");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateFrame(
                std::move(p_params));
            return true;
        }
        case internal::kRenderer_CreateFrameProxy_Name: {
            internal::Renderer_CreateFrameProxy_Params_Data* params = reinterpret_cast<internal::Renderer_CreateFrameProxy_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_routing_id {};
            int32_t p_render_view_routing_id {};
            int32_t p_opener_routing_id {};
            int32_t p_parent_routing_id {};
            content::FrameReplicationState p_replication_state {};
            Renderer_CreateFrameProxy_ParamsDataView input_data_view(params,
                context);

            p_routing_id = input_data_view.routing_id();
            p_render_view_routing_id = input_data_view.render_view_routing_id();
            p_opener_routing_id = input_data_view.opener_routing_id();
            p_parent_routing_id = input_data_view.parent_routing_id();
            if (!input_data_view.ReadReplicationState(&p_replication_state))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::CreateFrameProxy deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::CreateFrameProxy");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateFrameProxy(
                std::move(p_routing_id),
                std::move(p_render_view_routing_id),
                std::move(p_opener_routing_id),
                std::move(p_parent_routing_id),
                std::move(p_replication_state));
            return true;
        }
        case internal::kRenderer_OnNetworkConnectionChanged_Name: {
            internal::Renderer_OnNetworkConnectionChanged_Params_Data* params = reinterpret_cast<internal::Renderer_OnNetworkConnectionChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            net::NetworkChangeNotifier::ConnectionType p_connection_type {};
            double p_max_bandwidth_mbps {};
            Renderer_OnNetworkConnectionChanged_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadConnectionType(&p_connection_type))
                success = false;
            p_max_bandwidth_mbps = input_data_view.max_bandwidth_mbps();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::OnNetworkConnectionChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::OnNetworkConnectionChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnNetworkConnectionChanged(
                std::move(p_connection_type),
                std::move(p_max_bandwidth_mbps));
            return true;
        }
        case internal::kRenderer_SetWebKitSharedTimersSuspended_Name: {
            internal::Renderer_SetWebKitSharedTimersSuspended_Params_Data* params = reinterpret_cast<internal::Renderer_SetWebKitSharedTimersSuspended_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_suspend {};
            Renderer_SetWebKitSharedTimersSuspended_ParamsDataView input_data_view(params,
                context);

            p_suspend = input_data_view.suspend();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::SetWebKitSharedTimersSuspended deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::SetWebKitSharedTimersSuspended");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetWebKitSharedTimersSuspended(
                std::move(p_suspend));
            return true;
        }
        case internal::kRenderer_UpdateScrollbarTheme_Name: {
            internal::Renderer_UpdateScrollbarTheme_Params_Data* params = reinterpret_cast<internal::Renderer_UpdateScrollbarTheme_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            UpdateScrollbarThemeParamsPtr p_params {};
            Renderer_UpdateScrollbarTheme_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadParams(&p_params))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::UpdateScrollbarTheme deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::UpdateScrollbarTheme");
            mojo::internal::MessageDispatchContext context(message);
            impl->UpdateScrollbarTheme(
                std::move(p_params));
            return true;
        }
        case internal::kRenderer_OnSystemColorsChanged_Name: {
            internal::Renderer_OnSystemColorsChanged_Params_Data* params = reinterpret_cast<internal::Renderer_OnSystemColorsChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_aqua_color_variant {};
            std::string p_highlight_text_color {};
            std::string p_highlight_color {};
            Renderer_OnSystemColorsChanged_ParamsDataView input_data_view(params,
                context);

            p_aqua_color_variant = input_data_view.aqua_color_variant();
            if (!input_data_view.ReadHighlightTextColor(&p_highlight_text_color))
                success = false;
            if (!input_data_view.ReadHighlightColor(&p_highlight_color))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::OnSystemColorsChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::OnSystemColorsChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnSystemColorsChanged(
                std::move(p_aqua_color_variant),
                std::move(p_highlight_text_color),
                std::move(p_highlight_color));
            return true;
        }
        case internal::kRenderer_PurgePluginListCache_Name: {
            internal::Renderer_PurgePluginListCache_Params_Data* params = reinterpret_cast<internal::Renderer_PurgePluginListCache_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_reload_pages {};
            Renderer_PurgePluginListCache_ParamsDataView input_data_view(params,
                context);

            p_reload_pages = input_data_view.reload_pages();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::PurgePluginListCache deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::PurgePluginListCache");
            mojo::internal::MessageDispatchContext context(message);
            impl->PurgePluginListCache(
                std::move(p_reload_pages));
            return true;
        }
        }
        return false;
    }

    // static
    bool RendererStubDispatch::AcceptWithResponder(
        Renderer* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRenderer_CreateView_Name: {
            break;
        }
        case internal::kRenderer_CreateFrame_Name: {
            break;
        }
        case internal::kRenderer_CreateFrameProxy_Name: {
            break;
        }
        case internal::kRenderer_OnNetworkConnectionChanged_Name: {
            break;
        }
        case internal::kRenderer_SetWebKitSharedTimersSuspended_Name: {
            break;
        }
        case internal::kRenderer_UpdateScrollbarTheme_Name: {
            break;
        }
        case internal::kRenderer_OnSystemColorsChanged_Name: {
            break;
        }
        case internal::kRenderer_PurgePluginListCache_Name: {
            break;
        }
        }
        return false;
    }

    bool RendererRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Renderer RequestValidator");

        switch (message->header()->name) {
        case internal::kRenderer_CreateView_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_CreateView_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_CreateFrame_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_CreateFrame_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_CreateFrameProxy_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_CreateFrameProxy_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_OnNetworkConnectionChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_OnNetworkConnectionChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_SetWebKitSharedTimersSuspended_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_SetWebKitSharedTimersSuspended_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_UpdateScrollbarTheme_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_UpdateScrollbarTheme_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_OnSystemColorsChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_OnSystemColorsChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_PurgePluginListCache_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_PurgePluginListCache_Params_Data>(
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
} // namespace content

namespace mojo {

// static
bool StructTraits<::content::mojom::CreateViewParams::DataView, ::content::mojom::CreateViewParamsPtr>::Read(
    ::content::mojom::CreateViewParams::DataView input,
    ::content::mojom::CreateViewParamsPtr* output)
{
    bool success = true;
    ::content::mojom::CreateViewParamsPtr result(::content::mojom::CreateViewParams::New());

    if (!input.ReadRendererPreferences(&result->renderer_preferences))
        success = false;
    if (!input.ReadWebPreferences(&result->web_preferences))
        success = false;
    result->view_id = input.view_id();
    result->main_frame_routing_id = input.main_frame_routing_id();
    result->main_frame_widget_routing_id = input.main_frame_widget_routing_id();
    result->session_storage_namespace_id = input.session_storage_namespace_id();
    result->opener_frame_route_id = input.opener_frame_route_id();
    result->swapped_out = input.swapped_out();
    if (!input.ReadReplicatedFrameState(&result->replicated_frame_state))
        success = false;
    result->proxy_routing_id = input.proxy_routing_id();
    result->hidden = input.hidden();
    result->never_visible = input.never_visible();
    result->window_was_created_with_opener = input.window_was_created_with_opener();
    if (!input.ReadInitialSize(&result->initial_size))
        success = false;
    result->enable_auto_resize = input.enable_auto_resize();
    if (!input.ReadMinSize(&result->min_size))
        success = false;
    if (!input.ReadMaxSize(&result->max_size))
        success = false;
    result->page_zoom_level = input.page_zoom_level();
    if (!input.ReadImageDecodeColorSpace(&result->image_decode_color_space))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::content::mojom::CreateFrameWidgetParams::DataView, ::content::mojom::CreateFrameWidgetParamsPtr>::Read(
    ::content::mojom::CreateFrameWidgetParams::DataView input,
    ::content::mojom::CreateFrameWidgetParamsPtr* output)
{
    bool success = true;
    ::content::mojom::CreateFrameWidgetParamsPtr result(::content::mojom::CreateFrameWidgetParams::New());

    result->routing_id = input.routing_id();
    result->hidden = input.hidden();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::content::mojom::CreateFrameParams::DataView, ::content::mojom::CreateFrameParamsPtr>::Read(
    ::content::mojom::CreateFrameParams::DataView input,
    ::content::mojom::CreateFrameParamsPtr* output)
{
    bool success = true;
    ::content::mojom::CreateFrameParamsPtr result(::content::mojom::CreateFrameParams::New());

    result->routing_id = input.routing_id();
    result->proxy_routing_id = input.proxy_routing_id();
    result->opener_routing_id = input.opener_routing_id();
    result->parent_routing_id = input.parent_routing_id();
    result->previous_sibling_routing_id = input.previous_sibling_routing_id();
    if (!input.ReadReplicationState(&result->replication_state))
        success = false;
    if (!input.ReadFrameOwnerProperties(&result->frame_owner_properties))
        success = false;
    if (!input.ReadWidgetParams(&result->widget_params))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::content::mojom::UpdateScrollbarThemeParams::DataView, ::content::mojom::UpdateScrollbarThemeParamsPtr>::Read(
    ::content::mojom::UpdateScrollbarThemeParams::DataView input,
    ::content::mojom::UpdateScrollbarThemeParamsPtr* output)
{
    bool success = true;
    ::content::mojom::UpdateScrollbarThemeParamsPtr result(::content::mojom::UpdateScrollbarThemeParams::New());

    result->initial_button_delay = input.initial_button_delay();
    result->autoscroll_button_delay = input.autoscroll_button_delay();
    result->jump_on_track_click = input.jump_on_track_click();
    if (!input.ReadPreferredScrollerStyle(&result->preferred_scroller_style))
        success = false;
    result->redraw = input.redraw();
    if (!input.ReadButtonPlacement(&result->button_placement))
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