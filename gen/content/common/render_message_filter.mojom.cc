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

#include "content/common/render_message_filter.mojom.h"

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
    CreateNewWindowParamsPtr CreateNewWindowParams::New()
    {
        CreateNewWindowParamsPtr rv;
        mojo::internal::StructHelper<CreateNewWindowParams>::Initialize(&rv);
        return rv;
    }

    CreateNewWindowParams::CreateNewWindowParams()
        : opener_render_frame_id()
        , user_gesture()
        , window_container_type()
        , session_storage_namespace_id()
        , frame_name()
        , opener_url()
        , opener_top_level_frame_url()
        , opener_security_origin()
        , opener_suppressed()
        , disposition()
        , target_url()
        , referrer()
        , features()
    {
    }

    CreateNewWindowParams::~CreateNewWindowParams()
    {
    } // static
    CreateNewWindowReplyPtr CreateNewWindowReply::New()
    {
        CreateNewWindowReplyPtr rv;
        mojo::internal::StructHelper<CreateNewWindowReply>::Initialize(&rv);
        return rv;
    }

    CreateNewWindowReply::CreateNewWindowReply()
        : route_id()
        , main_frame_route_id()
        , main_frame_widget_route_id()
        , cloned_session_storage_namespace_id()
    {
    }

    CreateNewWindowReply::~CreateNewWindowReply()
    {
    }
    size_t CreateNewWindowReply::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->route_id);
        seed = mojo::internal::Hash(seed, this->main_frame_route_id);
        seed = mojo::internal::Hash(seed, this->main_frame_widget_route_id);
        seed = mojo::internal::Hash(seed, this->cloned_session_storage_namespace_id);
        return seed;
    }
    const char RenderMessageFilter::Name_[] = "content::mojom::RenderMessageFilter";
    bool RenderMessageFilter::GenerateRoutingID(int32_t* routing_id)
    {
        NOTREACHED();
        return false;
    }
    bool RenderMessageFilter::CreateNewWindow(CreateNewWindowParamsPtr params, CreateNewWindowReplyPtr* reply)
    {
        NOTREACHED();
        return false;
    }
    bool RenderMessageFilter::CreateNewWidget(int32_t opener_id, blink::WebPopupType popup_type, int32_t* route_id)
    {
        NOTREACHED();
        return false;
    }
    bool RenderMessageFilter::CreateFullscreenWidget(int32_t opener_id, int32_t* route_id)
    {
        NOTREACHED();
        return false;
    }
    class RenderMessageFilter_GenerateRoutingID_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        RenderMessageFilter_GenerateRoutingID_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, int32_t* out_routing_id)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_routing_id_(out_routing_id)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        int32_t* out_routing_id_;
        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_GenerateRoutingID_HandleSyncResponse);
    };
    bool RenderMessageFilter_GenerateRoutingID_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::RenderMessageFilter_GenerateRoutingID_ResponseParams_Data* params = reinterpret_cast<internal::RenderMessageFilter_GenerateRoutingID_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        int32_t p_routing_id {};
        RenderMessageFilter_GenerateRoutingID_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_routing_id = input_data_view.routing_id();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderMessageFilter::GenerateRoutingID response deserializer");
            return false;
        }
        *out_routing_id_ = std::move(p_routing_id);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class RenderMessageFilter_GenerateRoutingID_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        RenderMessageFilter_GenerateRoutingID_ForwardToCallback(
            const RenderMessageFilter::GenerateRoutingIDCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        RenderMessageFilter::GenerateRoutingIDCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_GenerateRoutingID_ForwardToCallback);
    };
    bool RenderMessageFilter_GenerateRoutingID_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::RenderMessageFilter_GenerateRoutingID_ResponseParams_Data* params = reinterpret_cast<internal::RenderMessageFilter_GenerateRoutingID_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        int32_t p_routing_id {};
        RenderMessageFilter_GenerateRoutingID_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_routing_id = input_data_view.routing_id();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderMessageFilter::GenerateRoutingID response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_routing_id));
        }
        return true;
    }
    class RenderMessageFilter_CreateNewWindow_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        RenderMessageFilter_CreateNewWindow_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, CreateNewWindowReplyPtr* out_reply)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_reply_(out_reply)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        CreateNewWindowReplyPtr* out_reply_;
        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_CreateNewWindow_HandleSyncResponse);
    };
    bool RenderMessageFilter_CreateNewWindow_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::RenderMessageFilter_CreateNewWindow_ResponseParams_Data* params = reinterpret_cast<internal::RenderMessageFilter_CreateNewWindow_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CreateNewWindowReplyPtr p_reply {};
        RenderMessageFilter_CreateNewWindow_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadReply(&p_reply))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderMessageFilter::CreateNewWindow response deserializer");
            return false;
        }
        *out_reply_ = std::move(p_reply);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class RenderMessageFilter_CreateNewWindow_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        RenderMessageFilter_CreateNewWindow_ForwardToCallback(
            const RenderMessageFilter::CreateNewWindowCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        RenderMessageFilter::CreateNewWindowCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_CreateNewWindow_ForwardToCallback);
    };
    bool RenderMessageFilter_CreateNewWindow_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::RenderMessageFilter_CreateNewWindow_ResponseParams_Data* params = reinterpret_cast<internal::RenderMessageFilter_CreateNewWindow_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CreateNewWindowReplyPtr p_reply {};
        RenderMessageFilter_CreateNewWindow_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadReply(&p_reply))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderMessageFilter::CreateNewWindow response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_reply));
        }
        return true;
    }
    class RenderMessageFilter_CreateNewWidget_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        RenderMessageFilter_CreateNewWidget_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, int32_t* out_route_id)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_route_id_(out_route_id)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        int32_t* out_route_id_;
        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_CreateNewWidget_HandleSyncResponse);
    };
    bool RenderMessageFilter_CreateNewWidget_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::RenderMessageFilter_CreateNewWidget_ResponseParams_Data* params = reinterpret_cast<internal::RenderMessageFilter_CreateNewWidget_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        int32_t p_route_id {};
        RenderMessageFilter_CreateNewWidget_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_route_id = input_data_view.route_id();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderMessageFilter::CreateNewWidget response deserializer");
            return false;
        }
        *out_route_id_ = std::move(p_route_id);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class RenderMessageFilter_CreateNewWidget_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        RenderMessageFilter_CreateNewWidget_ForwardToCallback(
            const RenderMessageFilter::CreateNewWidgetCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        RenderMessageFilter::CreateNewWidgetCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_CreateNewWidget_ForwardToCallback);
    };
    bool RenderMessageFilter_CreateNewWidget_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::RenderMessageFilter_CreateNewWidget_ResponseParams_Data* params = reinterpret_cast<internal::RenderMessageFilter_CreateNewWidget_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        int32_t p_route_id {};
        RenderMessageFilter_CreateNewWidget_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_route_id = input_data_view.route_id();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderMessageFilter::CreateNewWidget response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_route_id));
        }
        return true;
    }
    class RenderMessageFilter_CreateFullscreenWidget_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        RenderMessageFilter_CreateFullscreenWidget_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, int32_t* out_route_id)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_route_id_(out_route_id)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        int32_t* out_route_id_;
        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_CreateFullscreenWidget_HandleSyncResponse);
    };
    bool RenderMessageFilter_CreateFullscreenWidget_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data* params = reinterpret_cast<internal::RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        int32_t p_route_id {};
        RenderMessageFilter_CreateFullscreenWidget_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_route_id = input_data_view.route_id();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderMessageFilter::CreateFullscreenWidget response deserializer");
            return false;
        }
        *out_route_id_ = std::move(p_route_id);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class RenderMessageFilter_CreateFullscreenWidget_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        RenderMessageFilter_CreateFullscreenWidget_ForwardToCallback(
            const RenderMessageFilter::CreateFullscreenWidgetCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        RenderMessageFilter::CreateFullscreenWidgetCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_CreateFullscreenWidget_ForwardToCallback);
    };
    bool RenderMessageFilter_CreateFullscreenWidget_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data* params = reinterpret_cast<internal::RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        int32_t p_route_id {};
        RenderMessageFilter_CreateFullscreenWidget_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_route_id = input_data_view.route_id();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderMessageFilter::CreateFullscreenWidget response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_route_id));
        }
        return true;
    }

    RenderMessageFilterProxy::RenderMessageFilterProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }
    bool RenderMessageFilterProxy::GenerateRoutingID(
        int32_t* param_routing_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_GenerateRoutingID_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kRenderMessageFilter_GenerateRoutingID_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::content::mojom::internal::RenderMessageFilter_GenerateRoutingID_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new RenderMessageFilter_GenerateRoutingID_HandleSyncResponse(
            group_controller_, &result, param_routing_id);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void RenderMessageFilterProxy::GenerateRoutingID(
        const GenerateRoutingIDCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_GenerateRoutingID_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kRenderMessageFilter_GenerateRoutingID_Name, size);

        auto params = ::content::mojom::internal::RenderMessageFilter_GenerateRoutingID_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new RenderMessageFilter_GenerateRoutingID_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool RenderMessageFilterProxy::CreateNewWindow(
        CreateNewWindowParamsPtr param_params, CreateNewWindowReplyPtr* param_reply)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_CreateNewWindow_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::CreateNewWindowParamsDataView>(
            param_params, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kRenderMessageFilter_CreateNewWindow_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::content::mojom::internal::RenderMessageFilter_CreateNewWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->params)::BaseType* params_ptr;
        mojo::internal::Serialize<::content::mojom::CreateNewWindowParamsDataView>(
            param_params, builder.buffer(), &params_ptr, &serialization_context);
        params->params.Set(params_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->params.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null params in RenderMessageFilter.CreateNewWindow request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new RenderMessageFilter_CreateNewWindow_HandleSyncResponse(
            group_controller_, &result, param_reply);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void RenderMessageFilterProxy::CreateNewWindow(
        CreateNewWindowParamsPtr in_params, const CreateNewWindowCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_CreateNewWindow_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::CreateNewWindowParamsDataView>(
            in_params, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kRenderMessageFilter_CreateNewWindow_Name, size);

        auto params = ::content::mojom::internal::RenderMessageFilter_CreateNewWindow_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->params)::BaseType* params_ptr;
        mojo::internal::Serialize<::content::mojom::CreateNewWindowParamsDataView>(
            in_params, builder.buffer(), &params_ptr, &serialization_context);
        params->params.Set(params_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->params.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null params in RenderMessageFilter.CreateNewWindow request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new RenderMessageFilter_CreateNewWindow_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool RenderMessageFilterProxy::CreateNewWidget(
        int32_t param_opener_id, blink::WebPopupType param_popup_type, int32_t* param_route_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_CreateNewWidget_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kRenderMessageFilter_CreateNewWidget_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::content::mojom::internal::RenderMessageFilter_CreateNewWidget_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->opener_id = param_opener_id;
        mojo::internal::Serialize<::content::mojom::WebPopupType>(
            param_popup_type, &params->popup_type);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new RenderMessageFilter_CreateNewWidget_HandleSyncResponse(
            group_controller_, &result, param_route_id);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void RenderMessageFilterProxy::CreateNewWidget(
        int32_t in_opener_id, blink::WebPopupType in_popup_type, const CreateNewWidgetCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_CreateNewWidget_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kRenderMessageFilter_CreateNewWidget_Name, size);

        auto params = ::content::mojom::internal::RenderMessageFilter_CreateNewWidget_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->opener_id = in_opener_id;
        mojo::internal::Serialize<::content::mojom::WebPopupType>(
            in_popup_type, &params->popup_type);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new RenderMessageFilter_CreateNewWidget_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool RenderMessageFilterProxy::CreateFullscreenWidget(
        int32_t param_opener_id, int32_t* param_route_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_CreateFullscreenWidget_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kRenderMessageFilter_CreateFullscreenWidget_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::content::mojom::internal::RenderMessageFilter_CreateFullscreenWidget_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->opener_id = param_opener_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new RenderMessageFilter_CreateFullscreenWidget_HandleSyncResponse(
            group_controller_, &result, param_route_id);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void RenderMessageFilterProxy::CreateFullscreenWidget(
        int32_t in_opener_id, const CreateFullscreenWidgetCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_CreateFullscreenWidget_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kRenderMessageFilter_CreateFullscreenWidget_Name, size);

        auto params = ::content::mojom::internal::RenderMessageFilter_CreateFullscreenWidget_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->opener_id = in_opener_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new RenderMessageFilter_CreateFullscreenWidget_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void RenderMessageFilterProxy::AllocatedSharedBitmap(
        mojo::ScopedSharedBufferHandle in_buffer, const gpu::Mailbox& in_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_AllocatedSharedBitmap_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::MailboxDataView>(
            in_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRenderMessageFilter_AllocatedSharedBitmap_Name, size);

        auto params = ::content::mojom::internal::RenderMessageFilter_AllocatedSharedBitmap_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_buffer, &params->buffer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->buffer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid buffer in RenderMessageFilter.AllocatedSharedBitmap request");
        typename decltype(params->id)::BaseType* id_ptr;
        mojo::internal::Serialize<::gpu::mojom::MailboxDataView>(
            in_id, builder.buffer(), &id_ptr, &serialization_context);
        params->id.Set(id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null id in RenderMessageFilter.AllocatedSharedBitmap request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RenderMessageFilterProxy::DeletedSharedBitmap(
        const gpu::Mailbox& in_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_DeletedSharedBitmap_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gpu::mojom::MailboxDataView>(
            in_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRenderMessageFilter_DeletedSharedBitmap_Name, size);

        auto params = ::content::mojom::internal::RenderMessageFilter_DeletedSharedBitmap_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->id)::BaseType* id_ptr;
        mojo::internal::Serialize<::gpu::mojom::MailboxDataView>(
            in_id, builder.buffer(), &id_ptr, &serialization_context);
        params->id.Set(id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null id in RenderMessageFilter.DeletedSharedBitmap request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class RenderMessageFilter_GenerateRoutingID_ProxyToResponder {
    public:
        static RenderMessageFilter::GenerateRoutingIDCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<RenderMessageFilter_GenerateRoutingID_ProxyToResponder> proxy(
                new RenderMessageFilter_GenerateRoutingID_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&RenderMessageFilter_GenerateRoutingID_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~RenderMessageFilter_GenerateRoutingID_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "RenderMessageFilter::GenerateRoutingID() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        RenderMessageFilter_GenerateRoutingID_ProxyToResponder(
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
            int32_t in_routing_id);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_GenerateRoutingID_ProxyToResponder);
    };

    void RenderMessageFilter_GenerateRoutingID_ProxyToResponder::Run(
        int32_t in_routing_id)
    {
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_GenerateRoutingID_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kRenderMessageFilter_GenerateRoutingID_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::RenderMessageFilter_GenerateRoutingID_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->routing_id = in_routing_id;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class RenderMessageFilter_CreateNewWindow_ProxyToResponder {
    public:
        static RenderMessageFilter::CreateNewWindowCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<RenderMessageFilter_CreateNewWindow_ProxyToResponder> proxy(
                new RenderMessageFilter_CreateNewWindow_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&RenderMessageFilter_CreateNewWindow_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~RenderMessageFilter_CreateNewWindow_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "RenderMessageFilter::CreateNewWindow() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        RenderMessageFilter_CreateNewWindow_ProxyToResponder(
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
            CreateNewWindowReplyPtr in_reply);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_CreateNewWindow_ProxyToResponder);
    };

    void RenderMessageFilter_CreateNewWindow_ProxyToResponder::Run(
        CreateNewWindowReplyPtr in_reply)
    {
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_CreateNewWindow_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::CreateNewWindowReplyDataView>(
            in_reply, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kRenderMessageFilter_CreateNewWindow_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::RenderMessageFilter_CreateNewWindow_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->reply)::BaseType* reply_ptr;
        mojo::internal::Serialize<::content::mojom::CreateNewWindowReplyDataView>(
            in_reply, builder.buffer(), &reply_ptr, &serialization_context_);
        params->reply.Set(reply_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->reply.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null reply in RenderMessageFilter.CreateNewWindow response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class RenderMessageFilter_CreateNewWidget_ProxyToResponder {
    public:
        static RenderMessageFilter::CreateNewWidgetCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<RenderMessageFilter_CreateNewWidget_ProxyToResponder> proxy(
                new RenderMessageFilter_CreateNewWidget_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&RenderMessageFilter_CreateNewWidget_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~RenderMessageFilter_CreateNewWidget_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "RenderMessageFilter::CreateNewWidget() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        RenderMessageFilter_CreateNewWidget_ProxyToResponder(
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
            int32_t in_route_id);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_CreateNewWidget_ProxyToResponder);
    };

    void RenderMessageFilter_CreateNewWidget_ProxyToResponder::Run(
        int32_t in_route_id)
    {
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_CreateNewWidget_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kRenderMessageFilter_CreateNewWidget_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::RenderMessageFilter_CreateNewWidget_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->route_id = in_route_id;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class RenderMessageFilter_CreateFullscreenWidget_ProxyToResponder {
    public:
        static RenderMessageFilter::CreateFullscreenWidgetCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<RenderMessageFilter_CreateFullscreenWidget_ProxyToResponder> proxy(
                new RenderMessageFilter_CreateFullscreenWidget_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&RenderMessageFilter_CreateFullscreenWidget_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~RenderMessageFilter_CreateFullscreenWidget_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "RenderMessageFilter::CreateFullscreenWidget() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        RenderMessageFilter_CreateFullscreenWidget_ProxyToResponder(
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
            int32_t in_route_id);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(RenderMessageFilter_CreateFullscreenWidget_ProxyToResponder);
    };

    void RenderMessageFilter_CreateFullscreenWidget_ProxyToResponder::Run(
        int32_t in_route_id)
    {
        size_t size = sizeof(::content::mojom::internal::RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kRenderMessageFilter_CreateFullscreenWidget_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->route_id = in_route_id;
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
    bool RenderMessageFilterStubDispatch::Accept(
        RenderMessageFilter* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRenderMessageFilter_GenerateRoutingID_Name: {
            break;
        }
        case internal::kRenderMessageFilter_CreateNewWindow_Name: {
            break;
        }
        case internal::kRenderMessageFilter_CreateNewWidget_Name: {
            break;
        }
        case internal::kRenderMessageFilter_CreateFullscreenWidget_Name: {
            break;
        }
        case internal::kRenderMessageFilter_AllocatedSharedBitmap_Name: {
            internal::RenderMessageFilter_AllocatedSharedBitmap_Params_Data* params = reinterpret_cast<internal::RenderMessageFilter_AllocatedSharedBitmap_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            mojo::ScopedSharedBufferHandle p_buffer {};
            gpu::Mailbox p_id {};
            RenderMessageFilter_AllocatedSharedBitmap_ParamsDataView input_data_view(params,
                context);

            p_buffer = input_data_view.TakeBuffer();
            if (!input_data_view.ReadId(&p_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RenderMessageFilter::AllocatedSharedBitmap deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RenderMessageFilter::AllocatedSharedBitmap");
            mojo::internal::MessageDispatchContext context(message);
            impl->AllocatedSharedBitmap(
                std::move(p_buffer),
                std::move(p_id));
            return true;
        }
        case internal::kRenderMessageFilter_DeletedSharedBitmap_Name: {
            internal::RenderMessageFilter_DeletedSharedBitmap_Params_Data* params = reinterpret_cast<internal::RenderMessageFilter_DeletedSharedBitmap_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gpu::Mailbox p_id {};
            RenderMessageFilter_DeletedSharedBitmap_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadId(&p_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RenderMessageFilter::DeletedSharedBitmap deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RenderMessageFilter::DeletedSharedBitmap");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeletedSharedBitmap(
                std::move(p_id));
            return true;
        }
        }
        return false;
    }

    // static
    bool RenderMessageFilterStubDispatch::AcceptWithResponder(
        RenderMessageFilter* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRenderMessageFilter_GenerateRoutingID_Name: {
            internal::RenderMessageFilter_GenerateRoutingID_Params_Data* params = reinterpret_cast<internal::RenderMessageFilter_GenerateRoutingID_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RenderMessageFilter_GenerateRoutingID_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RenderMessageFilter::GenerateRoutingID deserializer");
                return false;
            }
            RenderMessageFilter::GenerateRoutingIDCallback callback = RenderMessageFilter_GenerateRoutingID_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RenderMessageFilter::GenerateRoutingID");
            mojo::internal::MessageDispatchContext context(message);
            impl->GenerateRoutingID(std::move(callback));
            return true;
        }
        case internal::kRenderMessageFilter_CreateNewWindow_Name: {
            internal::RenderMessageFilter_CreateNewWindow_Params_Data* params = reinterpret_cast<internal::RenderMessageFilter_CreateNewWindow_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            CreateNewWindowParamsPtr p_params {};
            RenderMessageFilter_CreateNewWindow_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadParams(&p_params))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RenderMessageFilter::CreateNewWindow deserializer");
                return false;
            }
            RenderMessageFilter::CreateNewWindowCallback callback = RenderMessageFilter_CreateNewWindow_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RenderMessageFilter::CreateNewWindow");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateNewWindow(
                std::move(p_params), std::move(callback));
            return true;
        }
        case internal::kRenderMessageFilter_CreateNewWidget_Name: {
            internal::RenderMessageFilter_CreateNewWidget_Params_Data* params = reinterpret_cast<internal::RenderMessageFilter_CreateNewWidget_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_opener_id {};
            blink::WebPopupType p_popup_type {};
            RenderMessageFilter_CreateNewWidget_ParamsDataView input_data_view(params,
                context);

            p_opener_id = input_data_view.opener_id();
            if (!input_data_view.ReadPopupType(&p_popup_type))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RenderMessageFilter::CreateNewWidget deserializer");
                return false;
            }
            RenderMessageFilter::CreateNewWidgetCallback callback = RenderMessageFilter_CreateNewWidget_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RenderMessageFilter::CreateNewWidget");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateNewWidget(
                std::move(p_opener_id),
                std::move(p_popup_type), std::move(callback));
            return true;
        }
        case internal::kRenderMessageFilter_CreateFullscreenWidget_Name: {
            internal::RenderMessageFilter_CreateFullscreenWidget_Params_Data* params = reinterpret_cast<internal::RenderMessageFilter_CreateFullscreenWidget_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_opener_id {};
            RenderMessageFilter_CreateFullscreenWidget_ParamsDataView input_data_view(params,
                context);

            p_opener_id = input_data_view.opener_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RenderMessageFilter::CreateFullscreenWidget deserializer");
                return false;
            }
            RenderMessageFilter::CreateFullscreenWidgetCallback callback = RenderMessageFilter_CreateFullscreenWidget_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RenderMessageFilter::CreateFullscreenWidget");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateFullscreenWidget(
                std::move(p_opener_id), std::move(callback));
            return true;
        }
        case internal::kRenderMessageFilter_AllocatedSharedBitmap_Name: {
            break;
        }
        case internal::kRenderMessageFilter_DeletedSharedBitmap_Name: {
            break;
        }
        }
        return false;
    }

    bool RenderMessageFilterRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "RenderMessageFilter RequestValidator");

        switch (message->header()->name) {
        case internal::kRenderMessageFilter_GenerateRoutingID_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_GenerateRoutingID_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderMessageFilter_CreateNewWindow_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_CreateNewWindow_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderMessageFilter_CreateNewWidget_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_CreateNewWidget_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderMessageFilter_CreateFullscreenWidget_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_CreateFullscreenWidget_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderMessageFilter_AllocatedSharedBitmap_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_AllocatedSharedBitmap_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderMessageFilter_DeletedSharedBitmap_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_DeletedSharedBitmap_Params_Data>(
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

    bool RenderMessageFilterResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "RenderMessageFilter ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kRenderMessageFilter_GenerateRoutingID_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_GenerateRoutingID_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderMessageFilter_CreateNewWindow_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_CreateNewWindow_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderMessageFilter_CreateNewWidget_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_CreateNewWidget_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderMessageFilter_CreateFullscreenWidget_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data>(
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
bool StructTraits<::content::mojom::CreateNewWindowParams::DataView, ::content::mojom::CreateNewWindowParamsPtr>::Read(
    ::content::mojom::CreateNewWindowParams::DataView input,
    ::content::mojom::CreateNewWindowParamsPtr* output)
{
    bool success = true;
    ::content::mojom::CreateNewWindowParamsPtr result(::content::mojom::CreateNewWindowParams::New());

    result->opener_render_frame_id = input.opener_render_frame_id();
    result->user_gesture = input.user_gesture();
    if (!input.ReadWindowContainerType(&result->window_container_type))
        success = false;
    result->session_storage_namespace_id = input.session_storage_namespace_id();
    if (!input.ReadFrameName(&result->frame_name))
        success = false;
    if (!input.ReadOpenerUrl(&result->opener_url))
        success = false;
    if (!input.ReadOpenerTopLevelFrameUrl(&result->opener_top_level_frame_url))
        success = false;
    if (!input.ReadOpenerSecurityOrigin(&result->opener_security_origin))
        success = false;
    result->opener_suppressed = input.opener_suppressed();
    if (!input.ReadDisposition(&result->disposition))
        success = false;
    if (!input.ReadTargetUrl(&result->target_url))
        success = false;
    if (!input.ReadReferrer(&result->referrer))
        success = false;
    if (!input.ReadFeatures(&result->features))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::content::mojom::CreateNewWindowReply::DataView, ::content::mojom::CreateNewWindowReplyPtr>::Read(
    ::content::mojom::CreateNewWindowReply::DataView input,
    ::content::mojom::CreateNewWindowReplyPtr* output)
{
    bool success = true;
    ::content::mojom::CreateNewWindowReplyPtr result(::content::mojom::CreateNewWindowReply::New());

    result->route_id = input.route_id();
    result->main_frame_route_id = input.main_frame_route_id();
    result->main_frame_widget_route_id = input.main_frame_widget_route_id();
    result->cloned_session_storage_namespace_id = input.cloned_session_storage_namespace_id();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif