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

#include "content/common/service_worker/service_worker_event_dispatcher.mojom.h"

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
    FetchEventPreloadHandlePtr FetchEventPreloadHandle::New()
    {
        FetchEventPreloadHandlePtr rv;
        mojo::internal::StructHelper<FetchEventPreloadHandle>::Initialize(&rv);
        return rv;
    }

    FetchEventPreloadHandle::FetchEventPreloadHandle()
        : url_loader()
        , url_loader_client_request()
    {
    }

    FetchEventPreloadHandle::~FetchEventPreloadHandle()
    {
    } // static
    ExtendableMessageEventPtr ExtendableMessageEvent::New()
    {
        ExtendableMessageEventPtr rv;
        mojo::internal::StructHelper<ExtendableMessageEvent>::Initialize(&rv);
        return rv;
    }

    ExtendableMessageEvent::ExtendableMessageEvent()
        : message()
        , source_origin()
        , message_ports()
        , new_routing_ids()
        , source()
    {
    }

    ExtendableMessageEvent::~ExtendableMessageEvent()
    {
    }
    const char ServiceWorkerEventDispatcher::Name_[] = "content::mojom::ServiceWorkerEventDispatcher";

    class ServiceWorkerEventDispatcher_DispatchFetchEvent_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ServiceWorkerEventDispatcher_DispatchFetchEvent_ForwardToCallback(
            const ServiceWorkerEventDispatcher::DispatchFetchEventCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ServiceWorkerEventDispatcher::DispatchFetchEventCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchFetchEvent_ForwardToCallback);
    };
    bool ServiceWorkerEventDispatcher_DispatchFetchEvent_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::content::ServiceWorkerStatusCode p_status {};
        base::Time p_dispatch_event_time {};
        ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadDispatchEventTime(&p_dispatch_event_time))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ServiceWorkerEventDispatcher::DispatchFetchEvent response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_dispatch_event_time));
        }
        return true;
    }

    class ServiceWorkerEventDispatcher_DispatchPushEvent_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ServiceWorkerEventDispatcher_DispatchPushEvent_ForwardToCallback(
            const ServiceWorkerEventDispatcher::DispatchPushEventCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ServiceWorkerEventDispatcher::DispatchPushEventCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchPushEvent_ForwardToCallback);
    };
    bool ServiceWorkerEventDispatcher_DispatchPushEvent_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::content::ServiceWorkerStatusCode p_status {};
        base::Time p_dispatch_event_time {};
        ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadDispatchEventTime(&p_dispatch_event_time))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ServiceWorkerEventDispatcher::DispatchPushEvent response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_dispatch_event_time));
        }
        return true;
    }

    class ServiceWorkerEventDispatcher_DispatchSyncEvent_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ServiceWorkerEventDispatcher_DispatchSyncEvent_ForwardToCallback(
            const ServiceWorkerEventDispatcher::DispatchSyncEventCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ServiceWorkerEventDispatcher::DispatchSyncEventCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchSyncEvent_ForwardToCallback);
    };
    bool ServiceWorkerEventDispatcher_DispatchSyncEvent_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::content::ServiceWorkerStatusCode p_status {};
        base::Time p_dispatch_event_time {};
        ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadDispatchEventTime(&p_dispatch_event_time))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ServiceWorkerEventDispatcher::DispatchSyncEvent response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_dispatch_event_time));
        }
        return true;
    }

    class ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ForwardToCallback(
            const ServiceWorkerEventDispatcher::DispatchPaymentRequestEventCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ServiceWorkerEventDispatcher::DispatchPaymentRequestEventCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ForwardToCallback);
    };
    bool ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::content::ServiceWorkerStatusCode p_status {};
        base::Time p_dispatch_event_time {};
        ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadDispatchEventTime(&p_dispatch_event_time))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ServiceWorkerEventDispatcher::DispatchPaymentRequestEvent response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_dispatch_event_time));
        }
        return true;
    }

    class ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ForwardToCallback(
            const ServiceWorkerEventDispatcher::DispatchExtendableMessageEventCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ServiceWorkerEventDispatcher::DispatchExtendableMessageEventCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ForwardToCallback);
    };
    bool ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::content::ServiceWorkerStatusCode p_status {};
        base::Time p_dispatch_event_time {};
        ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadDispatchEventTime(&p_dispatch_event_time))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ServiceWorkerEventDispatcher::DispatchExtendableMessageEvent response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_dispatch_event_time));
        }
        return true;
    }

    ServiceWorkerEventDispatcherProxy::ServiceWorkerEventDispatcherProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ServiceWorkerEventDispatcherProxy::DispatchFetchEvent(
        int32_t in_fetch_event_id, const ::content::ServiceWorkerFetchRequest& in_request, FetchEventPreloadHandlePtr in_preload_handle, const DispatchFetchEventCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::ServiceWorkerFetchRequestDataView>(
            in_request, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::content::mojom::FetchEventPreloadHandleDataView>(
            in_preload_handle, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kServiceWorkerEventDispatcher_DispatchFetchEvent_Name, size);

        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->fetch_event_id = in_fetch_event_id;
        typename decltype(params->request)::BaseType* request_ptr;
        mojo::internal::Serialize<::content::mojom::ServiceWorkerFetchRequestDataView>(
            in_request, builder.buffer(), &request_ptr, &serialization_context);
        params->request.Set(request_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->request.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null request in ServiceWorkerEventDispatcher.DispatchFetchEvent request");
        typename decltype(params->preload_handle)::BaseType* preload_handle_ptr;
        mojo::internal::Serialize<::content::mojom::FetchEventPreloadHandleDataView>(
            in_preload_handle, builder.buffer(), &preload_handle_ptr, &serialization_context);
        params->preload_handle.Set(preload_handle_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ServiceWorkerEventDispatcher_DispatchFetchEvent_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ServiceWorkerEventDispatcherProxy::DispatchPushEvent(
        const ::content::PushEventPayload& in_payload, const DispatchPushEventCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::PushEventPayloadDataView>(
            in_payload, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kServiceWorkerEventDispatcher_DispatchPushEvent_Name, size);

        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->payload)::BaseType* payload_ptr;
        mojo::internal::Serialize<::content::mojom::PushEventPayloadDataView>(
            in_payload, builder.buffer(), &payload_ptr, &serialization_context);
        params->payload.Set(payload_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->payload.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null payload in ServiceWorkerEventDispatcher.DispatchPushEvent request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ServiceWorkerEventDispatcher_DispatchPushEvent_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ServiceWorkerEventDispatcherProxy::DispatchSyncEvent(
        const std::string& in_tag, ::blink::mojom::BackgroundSyncEventLastChance in_last_chance, const DispatchSyncEventCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_tag, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kServiceWorkerEventDispatcher_DispatchSyncEvent_Name, size);

        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->tag)::BaseType* tag_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_tag, builder.buffer(), &tag_ptr, &serialization_context);
        params->tag.Set(tag_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->tag.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null tag in ServiceWorkerEventDispatcher.DispatchSyncEvent request");
        mojo::internal::Serialize<::blink::mojom::BackgroundSyncEventLastChance>(
            in_last_chance, &params->last_chance);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ServiceWorkerEventDispatcher_DispatchSyncEvent_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ServiceWorkerEventDispatcherProxy::DispatchPaymentRequestEvent(
        ::payments::mojom::PaymentAppRequestDataPtr in_data, const DispatchPaymentRequestEventCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data);
        size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentAppRequestDataDataView>(
            in_data, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Name, size);

        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->data)::BaseType* data_ptr;
        mojo::internal::Serialize<::payments::mojom::PaymentAppRequestDataDataView>(
            in_data, builder.buffer(), &data_ptr, &serialization_context);
        params->data.Set(data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null data in ServiceWorkerEventDispatcher.DispatchPaymentRequestEvent request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ServiceWorkerEventDispatcherProxy::DispatchExtendableMessageEvent(
        ExtendableMessageEventPtr in_event, const DispatchExtendableMessageEventCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data);
        size += mojo::internal::PrepareToSerialize<::content::mojom::ExtendableMessageEventDataView>(
            in_event, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Name, size);

        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->event)::BaseType* event_ptr;
        mojo::internal::Serialize<::content::mojom::ExtendableMessageEventDataView>(
            in_event, builder.buffer(), &event_ptr, &serialization_context);
        params->event.Set(event_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->event.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null event in ServiceWorkerEventDispatcher.DispatchExtendableMessageEvent request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class ServiceWorkerEventDispatcher_DispatchFetchEvent_ProxyToResponder {
    public:
        static ServiceWorkerEventDispatcher::DispatchFetchEventCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ServiceWorkerEventDispatcher_DispatchFetchEvent_ProxyToResponder> proxy(
                new ServiceWorkerEventDispatcher_DispatchFetchEvent_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ServiceWorkerEventDispatcher_DispatchFetchEvent_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ServiceWorkerEventDispatcher_DispatchFetchEvent_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ServiceWorkerEventDispatcher::DispatchFetchEvent() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ServiceWorkerEventDispatcher_DispatchFetchEvent_ProxyToResponder(
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
            ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchFetchEvent_ProxyToResponder);
    };

    void ServiceWorkerEventDispatcher_DispatchFetchEvent_ProxyToResponder::Run(
        ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time)
    {
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kServiceWorkerEventDispatcher_DispatchFetchEvent_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::ServiceWorkerEventStatus>(
            in_status, &params->status);
        typename decltype(params->dispatch_event_time)::BaseType* dispatch_event_time_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, builder.buffer(), &dispatch_event_time_ptr, &serialization_context_);
        params->dispatch_event_time.Set(dispatch_event_time_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->dispatch_event_time.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null dispatch_event_time in ServiceWorkerEventDispatcher.DispatchFetchEvent response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ServiceWorkerEventDispatcher_DispatchPushEvent_ProxyToResponder {
    public:
        static ServiceWorkerEventDispatcher::DispatchPushEventCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ServiceWorkerEventDispatcher_DispatchPushEvent_ProxyToResponder> proxy(
                new ServiceWorkerEventDispatcher_DispatchPushEvent_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ServiceWorkerEventDispatcher_DispatchPushEvent_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ServiceWorkerEventDispatcher_DispatchPushEvent_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ServiceWorkerEventDispatcher::DispatchPushEvent() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ServiceWorkerEventDispatcher_DispatchPushEvent_ProxyToResponder(
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
            ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchPushEvent_ProxyToResponder);
    };

    void ServiceWorkerEventDispatcher_DispatchPushEvent_ProxyToResponder::Run(
        ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time)
    {
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kServiceWorkerEventDispatcher_DispatchPushEvent_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::ServiceWorkerEventStatus>(
            in_status, &params->status);
        typename decltype(params->dispatch_event_time)::BaseType* dispatch_event_time_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, builder.buffer(), &dispatch_event_time_ptr, &serialization_context_);
        params->dispatch_event_time.Set(dispatch_event_time_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->dispatch_event_time.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null dispatch_event_time in ServiceWorkerEventDispatcher.DispatchPushEvent response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ServiceWorkerEventDispatcher_DispatchSyncEvent_ProxyToResponder {
    public:
        static ServiceWorkerEventDispatcher::DispatchSyncEventCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ServiceWorkerEventDispatcher_DispatchSyncEvent_ProxyToResponder> proxy(
                new ServiceWorkerEventDispatcher_DispatchSyncEvent_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ServiceWorkerEventDispatcher_DispatchSyncEvent_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ServiceWorkerEventDispatcher_DispatchSyncEvent_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ServiceWorkerEventDispatcher::DispatchSyncEvent() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ServiceWorkerEventDispatcher_DispatchSyncEvent_ProxyToResponder(
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
            ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchSyncEvent_ProxyToResponder);
    };

    void ServiceWorkerEventDispatcher_DispatchSyncEvent_ProxyToResponder::Run(
        ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time)
    {
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kServiceWorkerEventDispatcher_DispatchSyncEvent_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::ServiceWorkerEventStatus>(
            in_status, &params->status);
        typename decltype(params->dispatch_event_time)::BaseType* dispatch_event_time_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, builder.buffer(), &dispatch_event_time_ptr, &serialization_context_);
        params->dispatch_event_time.Set(dispatch_event_time_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->dispatch_event_time.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null dispatch_event_time in ServiceWorkerEventDispatcher.DispatchSyncEvent response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ProxyToResponder {
    public:
        static ServiceWorkerEventDispatcher::DispatchPaymentRequestEventCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ProxyToResponder> proxy(
                new ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ServiceWorkerEventDispatcher::DispatchPaymentRequestEvent() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ProxyToResponder(
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
            ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ProxyToResponder);
    };

    void ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ProxyToResponder::Run(
        ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time)
    {
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::ServiceWorkerEventStatus>(
            in_status, &params->status);
        typename decltype(params->dispatch_event_time)::BaseType* dispatch_event_time_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, builder.buffer(), &dispatch_event_time_ptr, &serialization_context_);
        params->dispatch_event_time.Set(dispatch_event_time_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->dispatch_event_time.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null dispatch_event_time in ServiceWorkerEventDispatcher.DispatchPaymentRequestEvent response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ProxyToResponder {
    public:
        static ServiceWorkerEventDispatcher::DispatchExtendableMessageEventCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ProxyToResponder> proxy(
                new ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ServiceWorkerEventDispatcher::DispatchExtendableMessageEvent() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ProxyToResponder(
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
            ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ProxyToResponder);
    };

    void ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ProxyToResponder::Run(
        ::content::ServiceWorkerStatusCode in_status, base::Time in_dispatch_event_time)
    {
        size_t size = sizeof(::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::ServiceWorkerEventStatus>(
            in_status, &params->status);
        typename decltype(params->dispatch_event_time)::BaseType* dispatch_event_time_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeDataView>(
            in_dispatch_event_time, builder.buffer(), &dispatch_event_time_ptr, &serialization_context_);
        params->dispatch_event_time.Set(dispatch_event_time_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->dispatch_event_time.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null dispatch_event_time in ServiceWorkerEventDispatcher.DispatchExtendableMessageEvent response");
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
    bool ServiceWorkerEventDispatcherStubDispatch::Accept(
        ServiceWorkerEventDispatcher* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kServiceWorkerEventDispatcher_DispatchFetchEvent_Name: {
            break;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchPushEvent_Name: {
            break;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchSyncEvent_Name: {
            break;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Name: {
            break;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool ServiceWorkerEventDispatcherStubDispatch::AcceptWithResponder(
        ServiceWorkerEventDispatcher* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kServiceWorkerEventDispatcher_DispatchFetchEvent_Name: {
            internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_fetch_event_id {};
            ::content::ServiceWorkerFetchRequest p_request {};
            FetchEventPreloadHandlePtr p_preload_handle {};
            ServiceWorkerEventDispatcher_DispatchFetchEvent_ParamsDataView input_data_view(params,
                context);

            p_fetch_event_id = input_data_view.fetch_event_id();
            if (!input_data_view.ReadRequest(&p_request))
                success = false;
            if (!input_data_view.ReadPreloadHandle(&p_preload_handle))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceWorkerEventDispatcher::DispatchFetchEvent deserializer");
                return false;
            }
            ServiceWorkerEventDispatcher::DispatchFetchEventCallback callback = ServiceWorkerEventDispatcher_DispatchFetchEvent_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceWorkerEventDispatcher::DispatchFetchEvent");
            mojo::internal::MessageDispatchContext context(message);
            impl->DispatchFetchEvent(
                std::move(p_fetch_event_id),
                std::move(p_request),
                std::move(p_preload_handle), std::move(callback));
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchPushEvent_Name: {
            internal::ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::content::PushEventPayload p_payload {};
            ServiceWorkerEventDispatcher_DispatchPushEvent_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPayload(&p_payload))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceWorkerEventDispatcher::DispatchPushEvent deserializer");
                return false;
            }
            ServiceWorkerEventDispatcher::DispatchPushEventCallback callback = ServiceWorkerEventDispatcher_DispatchPushEvent_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceWorkerEventDispatcher::DispatchPushEvent");
            mojo::internal::MessageDispatchContext context(message);
            impl->DispatchPushEvent(
                std::move(p_payload), std::move(callback));
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchSyncEvent_Name: {
            internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_tag {};
            ::blink::mojom::BackgroundSyncEventLastChance p_last_chance {};
            ServiceWorkerEventDispatcher_DispatchSyncEvent_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadTag(&p_tag))
                success = false;
            if (!input_data_view.ReadLastChance(&p_last_chance))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceWorkerEventDispatcher::DispatchSyncEvent deserializer");
                return false;
            }
            ServiceWorkerEventDispatcher::DispatchSyncEventCallback callback = ServiceWorkerEventDispatcher_DispatchSyncEvent_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceWorkerEventDispatcher::DispatchSyncEvent");
            mojo::internal::MessageDispatchContext context(message);
            impl->DispatchSyncEvent(
                std::move(p_tag),
                std::move(p_last_chance), std::move(callback));
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Name: {
            internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::payments::mojom::PaymentAppRequestDataPtr p_data {};
            ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadData(&p_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceWorkerEventDispatcher::DispatchPaymentRequestEvent deserializer");
                return false;
            }
            ServiceWorkerEventDispatcher::DispatchPaymentRequestEventCallback callback = ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceWorkerEventDispatcher::DispatchPaymentRequestEvent");
            mojo::internal::MessageDispatchContext context(message);
            impl->DispatchPaymentRequestEvent(
                std::move(p_data), std::move(callback));
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Name: {
            internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data* params = reinterpret_cast<internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ExtendableMessageEventPtr p_event {};
            ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadEvent(&p_event))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ServiceWorkerEventDispatcher::DispatchExtendableMessageEvent deserializer");
                return false;
            }
            ServiceWorkerEventDispatcher::DispatchExtendableMessageEventCallback callback = ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ServiceWorkerEventDispatcher::DispatchExtendableMessageEvent");
            mojo::internal::MessageDispatchContext context(message);
            impl->DispatchExtendableMessageEvent(
                std::move(p_event), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool ServiceWorkerEventDispatcherRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ServiceWorkerEventDispatcher RequestValidator");

        switch (message->header()->name) {
        case internal::kServiceWorkerEventDispatcher_DispatchFetchEvent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchPushEvent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchSyncEvent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data>(
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

    bool ServiceWorkerEventDispatcherResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ServiceWorkerEventDispatcher ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kServiceWorkerEventDispatcher_DispatchFetchEvent_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchPushEvent_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchSyncEvent_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data>(
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
bool StructTraits<::content::mojom::FetchEventPreloadHandle::DataView, ::content::mojom::FetchEventPreloadHandlePtr>::Read(
    ::content::mojom::FetchEventPreloadHandle::DataView input,
    ::content::mojom::FetchEventPreloadHandlePtr* output)
{
    bool success = true;
    ::content::mojom::FetchEventPreloadHandlePtr result(::content::mojom::FetchEventPreloadHandle::New());

    result->url_loader = input.TakeUrlLoader<decltype(result->url_loader)>();
    result->url_loader_client_request = input.TakeUrlLoaderClientRequest<decltype(result->url_loader_client_request)>();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::content::mojom::ExtendableMessageEvent::DataView, ::content::mojom::ExtendableMessageEventPtr>::Read(
    ::content::mojom::ExtendableMessageEvent::DataView input,
    ::content::mojom::ExtendableMessageEventPtr* output)
{
    bool success = true;
    ::content::mojom::ExtendableMessageEventPtr result(::content::mojom::ExtendableMessageEvent::New());

    if (!input.ReadMessage(&result->message))
        success = false;
    if (!input.ReadSourceOrigin(&result->source_origin))
        success = false;
    if (!input.ReadMessagePorts(&result->message_ports))
        success = false;
    if (!input.ReadNewRoutingIds(&result->new_routing_ids))
        success = false;
    if (!input.ReadSource(&result->source))
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