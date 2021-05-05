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

#include "services/ui/gpu/interfaces/gpu_host.mojom.h"

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
#include "services/ui/gpu/interfaces/context_lost_reason_traits.h"
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
#include "url/mojo/url_gurl_struct_traits.h"
namespace ui {
namespace mojom {
    const char GpuHost::Name_[] = "ui::mojom::GpuHost";

    GpuHostProxy::GpuHostProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void GpuHostProxy::DidInitialize(
        const gpu::GPUInfo& in_gpu_info)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuHost_DidInitialize_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::GpuInfoDataView>(
            in_gpu_info, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGpuHost_DidInitialize_Name, size);

        auto params = ::ui::mojom::internal::GpuHost_DidInitialize_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->gpu_info)::BaseType* gpu_info_ptr;
        mojo::internal::Serialize<::gpu::mojom::GpuInfoDataView>(
            in_gpu_info, builder.buffer(), &gpu_info_ptr, &serialization_context);
        params->gpu_info.Set(gpu_info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->gpu_info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null gpu_info in GpuHost.DidInitialize request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void GpuHostProxy::DidCreateOffscreenContext(
        const GURL& in_url)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuHost_DidCreateOffscreenContext_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_url, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGpuHost_DidCreateOffscreenContext_Name, size);

        auto params = ::ui::mojom::internal::GpuHost_DidCreateOffscreenContext_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in GpuHost.DidCreateOffscreenContext request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void GpuHostProxy::DidDestroyOffscreenContext(
        const GURL& in_url)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuHost_DidDestroyOffscreenContext_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_url, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGpuHost_DidDestroyOffscreenContext_Name, size);

        auto params = ::ui::mojom::internal::GpuHost_DidDestroyOffscreenContext_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in GpuHost.DidDestroyOffscreenContext request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void GpuHostProxy::DidDestroyChannel(
        int32_t in_client_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuHost_DidDestroyChannel_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kGpuHost_DidDestroyChannel_Name, size);

        auto params = ::ui::mojom::internal::GpuHost_DidDestroyChannel_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->client_id = in_client_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void GpuHostProxy::DidLoseContext(
        bool in_offscreen, gpu::error::ContextLostReason in_reason, const GURL& in_active_url)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuHost_DidLoseContext_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_active_url, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGpuHost_DidLoseContext_Name, size);

        auto params = ::ui::mojom::internal::GpuHost_DidLoseContext_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->offscreen = in_offscreen;
        mojo::internal::Serialize<::ui::mojom::ContextLostReason>(
            in_reason, &params->reason);
        typename decltype(params->active_url)::BaseType* active_url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_active_url, builder.buffer(), &active_url_ptr, &serialization_context);
        params->active_url.Set(active_url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->active_url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null active_url in GpuHost.DidLoseContext request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void GpuHostProxy::SetChildSurface(
        ::gpu::SurfaceHandle in_parent, ::gpu::SurfaceHandle in_child)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuHost_SetChildSurface_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::SurfaceHandleDataView>(
            in_parent, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::SurfaceHandleDataView>(
            in_child, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGpuHost_SetChildSurface_Name, size);

        auto params = ::ui::mojom::internal::GpuHost_SetChildSurface_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->parent)::BaseType* parent_ptr;
        mojo::internal::Serialize<::gpu::mojom::SurfaceHandleDataView>(
            in_parent, builder.buffer(), &parent_ptr, &serialization_context);
        params->parent.Set(parent_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->parent.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null parent in GpuHost.SetChildSurface request");
        typename decltype(params->child)::BaseType* child_ptr;
        mojo::internal::Serialize<::gpu::mojom::SurfaceHandleDataView>(
            in_child, builder.buffer(), &child_ptr, &serialization_context);
        params->child.Set(child_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->child.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null child in GpuHost.SetChildSurface request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void GpuHostProxy::StoreShaderToDisk(
        int32_t in_client_id, const std::string& in_key, const std::string& in_shader)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::ui::mojom::internal::GpuHost_StoreShaderToDisk_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_shader, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGpuHost_StoreShaderToDisk_Name, size);

        auto params = ::ui::mojom::internal::GpuHost_StoreShaderToDisk_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->client_id = in_client_id;
        typename decltype(params->key)::BaseType* key_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_key, builder.buffer(), &key_ptr, &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in GpuHost.StoreShaderToDisk request");
        typename decltype(params->shader)::BaseType* shader_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_shader, builder.buffer(), &shader_ptr, &serialization_context);
        params->shader.Set(shader_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->shader.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null shader in GpuHost.StoreShaderToDisk request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool GpuHostStubDispatch::Accept(
        GpuHost* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kGpuHost_DidInitialize_Name: {
            internal::GpuHost_DidInitialize_Params_Data* params = reinterpret_cast<internal::GpuHost_DidInitialize_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gpu::GPUInfo p_gpu_info {};
            GpuHost_DidInitialize_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadGpuInfo(&p_gpu_info))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuHost::DidInitialize deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuHost::DidInitialize");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidInitialize(
                std::move(p_gpu_info));
            return true;
        }
        case internal::kGpuHost_DidCreateOffscreenContext_Name: {
            internal::GpuHost_DidCreateOffscreenContext_Params_Data* params = reinterpret_cast<internal::GpuHost_DidCreateOffscreenContext_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GURL p_url {};
            GpuHost_DidCreateOffscreenContext_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuHost::DidCreateOffscreenContext deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuHost::DidCreateOffscreenContext");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidCreateOffscreenContext(
                std::move(p_url));
            return true;
        }
        case internal::kGpuHost_DidDestroyOffscreenContext_Name: {
            internal::GpuHost_DidDestroyOffscreenContext_Params_Data* params = reinterpret_cast<internal::GpuHost_DidDestroyOffscreenContext_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GURL p_url {};
            GpuHost_DidDestroyOffscreenContext_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuHost::DidDestroyOffscreenContext deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuHost::DidDestroyOffscreenContext");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidDestroyOffscreenContext(
                std::move(p_url));
            return true;
        }
        case internal::kGpuHost_DidDestroyChannel_Name: {
            internal::GpuHost_DidDestroyChannel_Params_Data* params = reinterpret_cast<internal::GpuHost_DidDestroyChannel_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_client_id {};
            GpuHost_DidDestroyChannel_ParamsDataView input_data_view(params,
                context);

            p_client_id = input_data_view.client_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuHost::DidDestroyChannel deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuHost::DidDestroyChannel");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidDestroyChannel(
                std::move(p_client_id));
            return true;
        }
        case internal::kGpuHost_DidLoseContext_Name: {
            internal::GpuHost_DidLoseContext_Params_Data* params = reinterpret_cast<internal::GpuHost_DidLoseContext_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_offscreen {};
            gpu::error::ContextLostReason p_reason {};
            GURL p_active_url {};
            GpuHost_DidLoseContext_ParamsDataView input_data_view(params,
                context);

            p_offscreen = input_data_view.offscreen();
            if (!input_data_view.ReadReason(&p_reason))
                success = false;
            if (!input_data_view.ReadActiveUrl(&p_active_url))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuHost::DidLoseContext deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuHost::DidLoseContext");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidLoseContext(
                std::move(p_offscreen),
                std::move(p_reason),
                std::move(p_active_url));
            return true;
        }
        case internal::kGpuHost_SetChildSurface_Name: {
            internal::GpuHost_SetChildSurface_Params_Data* params = reinterpret_cast<internal::GpuHost_SetChildSurface_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::gpu::SurfaceHandle p_parent {};
            ::gpu::SurfaceHandle p_child {};
            GpuHost_SetChildSurface_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadParent(&p_parent))
                success = false;
            if (!input_data_view.ReadChild(&p_child))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuHost::SetChildSurface deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuHost::SetChildSurface");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetChildSurface(
                std::move(p_parent),
                std::move(p_child));
            return true;
        }
        case internal::kGpuHost_StoreShaderToDisk_Name: {
            internal::GpuHost_StoreShaderToDisk_Params_Data* params = reinterpret_cast<internal::GpuHost_StoreShaderToDisk_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_client_id {};
            std::string p_key {};
            std::string p_shader {};
            GpuHost_StoreShaderToDisk_ParamsDataView input_data_view(params,
                context);

            p_client_id = input_data_view.client_id();
            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadShader(&p_shader))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GpuHost::StoreShaderToDisk deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GpuHost::StoreShaderToDisk");
            mojo::internal::MessageDispatchContext context(message);
            impl->StoreShaderToDisk(
                std::move(p_client_id),
                std::move(p_key),
                std::move(p_shader));
            return true;
        }
        }
        return false;
    }

    // static
    bool GpuHostStubDispatch::AcceptWithResponder(
        GpuHost* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kGpuHost_DidInitialize_Name: {
            break;
        }
        case internal::kGpuHost_DidCreateOffscreenContext_Name: {
            break;
        }
        case internal::kGpuHost_DidDestroyOffscreenContext_Name: {
            break;
        }
        case internal::kGpuHost_DidDestroyChannel_Name: {
            break;
        }
        case internal::kGpuHost_DidLoseContext_Name: {
            break;
        }
        case internal::kGpuHost_SetChildSurface_Name: {
            break;
        }
        case internal::kGpuHost_StoreShaderToDisk_Name: {
            break;
        }
        }
        return false;
    }

    bool GpuHostRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GpuHost RequestValidator");

        switch (message->header()->name) {
        case internal::kGpuHost_DidInitialize_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuHost_DidInitialize_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuHost_DidCreateOffscreenContext_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuHost_DidCreateOffscreenContext_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuHost_DidDestroyOffscreenContext_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuHost_DidDestroyOffscreenContext_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuHost_DidDestroyChannel_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuHost_DidDestroyChannel_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuHost_DidLoseContext_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuHost_DidLoseContext_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuHost_SetChildSurface_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuHost_SetChildSurface_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGpuHost_StoreShaderToDisk_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GpuHost_StoreShaderToDisk_Params_Data>(
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