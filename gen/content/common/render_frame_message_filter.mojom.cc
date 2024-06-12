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

#include "content/common/render_frame_message_filter.mojom.h"

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
namespace mojom {
    const char RenderFrameMessageFilter::Name_[] = "content::mojom::RenderFrameMessageFilter";
    bool RenderFrameMessageFilter::GetCookies(int32_t render_frame_id, const GURL& url, const GURL& first_party_for_cookies, std::string* cookies)
    {
        NOTREACHED();
        return false;
    }
    class RenderFrameMessageFilter_GetCookies_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        RenderFrameMessageFilter_GetCookies_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, std::string* out_cookies)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_cookies_(out_cookies)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        std::string* out_cookies_;
        DISALLOW_COPY_AND_ASSIGN(RenderFrameMessageFilter_GetCookies_HandleSyncResponse);
    };
    bool RenderFrameMessageFilter_GetCookies_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::RenderFrameMessageFilter_GetCookies_ResponseParams_Data* params = reinterpret_cast<internal::RenderFrameMessageFilter_GetCookies_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::string p_cookies {};
        RenderFrameMessageFilter_GetCookies_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadCookies(&p_cookies))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderFrameMessageFilter::GetCookies response deserializer");
            return false;
        }
        *out_cookies_ = std::move(p_cookies);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class RenderFrameMessageFilter_GetCookies_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        RenderFrameMessageFilter_GetCookies_ForwardToCallback(
            const RenderFrameMessageFilter::GetCookiesCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        RenderFrameMessageFilter::GetCookiesCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(RenderFrameMessageFilter_GetCookies_ForwardToCallback);
    };
    bool RenderFrameMessageFilter_GetCookies_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::RenderFrameMessageFilter_GetCookies_ResponseParams_Data* params = reinterpret_cast<internal::RenderFrameMessageFilter_GetCookies_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::string p_cookies {};
        RenderFrameMessageFilter_GetCookies_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadCookies(&p_cookies))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "RenderFrameMessageFilter::GetCookies response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_cookies));
        }
        return true;
    }

    RenderFrameMessageFilterProxy::RenderFrameMessageFilterProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void RenderFrameMessageFilterProxy::SetCookie(
        int32_t in_render_frame_id, const GURL& in_url, const GURL& in_first_party_for_cookies, const std::string& in_cookie)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderFrameMessageFilter_SetCookie_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_url, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_first_party_for_cookies, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_cookie, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRenderFrameMessageFilter_SetCookie_Name, size);

        auto params = ::content::mojom::internal::RenderFrameMessageFilter_SetCookie_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->render_frame_id = in_render_frame_id;
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in RenderFrameMessageFilter.SetCookie request");
        typename decltype(params->first_party_for_cookies)::BaseType* first_party_for_cookies_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_first_party_for_cookies, builder.buffer(), &first_party_for_cookies_ptr, &serialization_context);
        params->first_party_for_cookies.Set(first_party_for_cookies_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->first_party_for_cookies.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null first_party_for_cookies in RenderFrameMessageFilter.SetCookie request");
        typename decltype(params->cookie)::BaseType* cookie_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_cookie, builder.buffer(), &cookie_ptr, &serialization_context);
        params->cookie.Set(cookie_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->cookie.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null cookie in RenderFrameMessageFilter.SetCookie request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    bool RenderFrameMessageFilterProxy::GetCookies(
        int32_t param_render_frame_id, const GURL& param_url, const GURL& param_first_party_for_cookies, std::string* param_cookies)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderFrameMessageFilter_GetCookies_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            param_url, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            param_first_party_for_cookies, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kRenderFrameMessageFilter_GetCookies_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::content::mojom::internal::RenderFrameMessageFilter_GetCookies_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->render_frame_id = param_render_frame_id;
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            param_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in RenderFrameMessageFilter.GetCookies request");
        typename decltype(params->first_party_for_cookies)::BaseType* first_party_for_cookies_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            param_first_party_for_cookies, builder.buffer(), &first_party_for_cookies_ptr, &serialization_context);
        params->first_party_for_cookies.Set(first_party_for_cookies_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->first_party_for_cookies.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null first_party_for_cookies in RenderFrameMessageFilter.GetCookies request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new RenderFrameMessageFilter_GetCookies_HandleSyncResponse(
            group_controller_, &result, param_cookies);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void RenderFrameMessageFilterProxy::GetCookies(
        int32_t in_render_frame_id, const GURL& in_url, const GURL& in_first_party_for_cookies, const GetCookiesCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::RenderFrameMessageFilter_GetCookies_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_url, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_first_party_for_cookies, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kRenderFrameMessageFilter_GetCookies_Name, size);

        auto params = ::content::mojom::internal::RenderFrameMessageFilter_GetCookies_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->render_frame_id = in_render_frame_id;
        typename decltype(params->url)::BaseType* url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_url, builder.buffer(), &url_ptr, &serialization_context);
        params->url.Set(url_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->url.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null url in RenderFrameMessageFilter.GetCookies request");
        typename decltype(params->first_party_for_cookies)::BaseType* first_party_for_cookies_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_first_party_for_cookies, builder.buffer(), &first_party_for_cookies_ptr, &serialization_context);
        params->first_party_for_cookies.Set(first_party_for_cookies_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->first_party_for_cookies.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null first_party_for_cookies in RenderFrameMessageFilter.GetCookies request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new RenderFrameMessageFilter_GetCookies_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class RenderFrameMessageFilter_GetCookies_ProxyToResponder {
    public:
        static RenderFrameMessageFilter::GetCookiesCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<RenderFrameMessageFilter_GetCookies_ProxyToResponder> proxy(
                new RenderFrameMessageFilter_GetCookies_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&RenderFrameMessageFilter_GetCookies_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~RenderFrameMessageFilter_GetCookies_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "RenderFrameMessageFilter::GetCookies() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        RenderFrameMessageFilter_GetCookies_ProxyToResponder(
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
            const std::string& in_cookies);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(RenderFrameMessageFilter_GetCookies_ProxyToResponder);
    };

    void RenderFrameMessageFilter_GetCookies_ProxyToResponder::Run(
        const std::string& in_cookies)
    {
        size_t size = sizeof(::content::mojom::internal::RenderFrameMessageFilter_GetCookies_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_cookies, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kRenderFrameMessageFilter_GetCookies_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::RenderFrameMessageFilter_GetCookies_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->cookies)::BaseType* cookies_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_cookies, builder.buffer(), &cookies_ptr, &serialization_context_);
        params->cookies.Set(cookies_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->cookies.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null cookies in RenderFrameMessageFilter.GetCookies response");
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
    bool RenderFrameMessageFilterStubDispatch::Accept(
        RenderFrameMessageFilter* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRenderFrameMessageFilter_SetCookie_Name: {
            internal::RenderFrameMessageFilter_SetCookie_Params_Data* params = reinterpret_cast<internal::RenderFrameMessageFilter_SetCookie_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_render_frame_id {};
            GURL p_url {};
            GURL p_first_party_for_cookies {};
            std::string p_cookie {};
            RenderFrameMessageFilter_SetCookie_ParamsDataView input_data_view(params,
                context);

            p_render_frame_id = input_data_view.render_frame_id();
            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            if (!input_data_view.ReadFirstPartyForCookies(&p_first_party_for_cookies))
                success = false;
            if (!input_data_view.ReadCookie(&p_cookie))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RenderFrameMessageFilter::SetCookie deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RenderFrameMessageFilter::SetCookie");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetCookie(
                std::move(p_render_frame_id),
                std::move(p_url),
                std::move(p_first_party_for_cookies),
                std::move(p_cookie));
            return true;
        }
        case internal::kRenderFrameMessageFilter_GetCookies_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool RenderFrameMessageFilterStubDispatch::AcceptWithResponder(
        RenderFrameMessageFilter* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRenderFrameMessageFilter_SetCookie_Name: {
            break;
        }
        case internal::kRenderFrameMessageFilter_GetCookies_Name: {
            internal::RenderFrameMessageFilter_GetCookies_Params_Data* params = reinterpret_cast<internal::RenderFrameMessageFilter_GetCookies_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_render_frame_id {};
            GURL p_url {};
            GURL p_first_party_for_cookies {};
            RenderFrameMessageFilter_GetCookies_ParamsDataView input_data_view(params,
                context);

            p_render_frame_id = input_data_view.render_frame_id();
            if (!input_data_view.ReadUrl(&p_url))
                success = false;
            if (!input_data_view.ReadFirstPartyForCookies(&p_first_party_for_cookies))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RenderFrameMessageFilter::GetCookies deserializer");
                return false;
            }
            RenderFrameMessageFilter::GetCookiesCallback callback = RenderFrameMessageFilter_GetCookies_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RenderFrameMessageFilter::GetCookies");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetCookies(
                std::move(p_render_frame_id),
                std::move(p_url),
                std::move(p_first_party_for_cookies), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool RenderFrameMessageFilterRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "RenderFrameMessageFilter RequestValidator");

        switch (message->header()->name) {
        case internal::kRenderFrameMessageFilter_SetCookie_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderFrameMessageFilter_SetCookie_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderFrameMessageFilter_GetCookies_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderFrameMessageFilter_GetCookies_Params_Data>(
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

    bool RenderFrameMessageFilterResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "RenderFrameMessageFilter ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kRenderFrameMessageFilter_GetCookies_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RenderFrameMessageFilter_GetCookies_ResponseParams_Data>(
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

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif