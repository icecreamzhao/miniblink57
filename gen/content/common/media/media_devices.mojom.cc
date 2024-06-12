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

#include "content/common/media/media_devices.mojom.h"

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
namespace mojom {
const char MediaDevicesDispatcherHost::Name_[] = "mojom::MediaDevicesDispatcherHost";

class MediaDevicesDispatcherHost_EnumerateDevices_ForwardToCallback
    : public mojo::MessageReceiver {
public:
    MediaDevicesDispatcherHost_EnumerateDevices_ForwardToCallback(
        const MediaDevicesDispatcherHost::EnumerateDevicesCallback& callback,
        scoped_refptr<mojo::AssociatedGroupController> group_controller)
        : callback_(std::move(callback))
        , serialization_context_(std::move(group_controller))
    {
    }
    bool Accept(mojo::Message* message) override;

private:
    MediaDevicesDispatcherHost::EnumerateDevicesCallback callback_;
    mojo::internal::SerializationContext serialization_context_;
    DISALLOW_COPY_AND_ASSIGN(MediaDevicesDispatcherHost_EnumerateDevices_ForwardToCallback);
};
bool MediaDevicesDispatcherHost_EnumerateDevices_ForwardToCallback::Accept(
    mojo::Message* message)
{
    internal::MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data* params = reinterpret_cast<internal::MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data*>(
        message->mutable_payload());

    (&serialization_context_)->handles.Swap((message)->mutable_handles());
    bool success = true;
    std::vector<std::vector<::content::MediaDeviceInfo>> p_enumeration {};
    MediaDevicesDispatcherHost_EnumerateDevices_ResponseParamsDataView input_data_view(params,
        &serialization_context_);

    if (!input_data_view.ReadEnumeration(&p_enumeration))
        success = false;
    if (!success) {
        ReportValidationErrorForMessage(
            message,
            mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
            "MediaDevicesDispatcherHost::EnumerateDevices response deserializer");
        return false;
    }
    if (!callback_.is_null()) {
        mojo::internal::MessageDispatchContext context(message);
        std::move(callback_).Run(
            std::move(p_enumeration));
    }
    return true;
}

MediaDevicesDispatcherHostProxy::MediaDevicesDispatcherHostProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver)
{
}

void MediaDevicesDispatcherHostProxy::EnumerateDevices(
    bool in_request_audio_input, bool in_request_video_input, bool in_request_audio_output, const url::Origin& in_security_origin, const EnumerateDevicesCallback& callback)
{
    mojo::internal::SerializationContext serialization_context(
        group_controller_);
    size_t size = sizeof(::mojom::internal::MediaDevicesDispatcherHost_EnumerateDevices_Params_Data);
    size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
        in_security_origin, &serialization_context);
    mojo::internal::RequestMessageBuilder builder(internal::kMediaDevicesDispatcherHost_EnumerateDevices_Name, size);

    auto params = ::mojom::internal::MediaDevicesDispatcherHost_EnumerateDevices_Params_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    params->request_audio_input = in_request_audio_input;
    params->request_video_input = in_request_video_input;
    params->request_audio_output = in_request_audio_output;
    typename decltype(params->security_origin)::BaseType* security_origin_ptr;
    mojo::internal::Serialize<::url::mojom::OriginDataView>(
        in_security_origin, builder.buffer(), &security_origin_ptr, &serialization_context);
    params->security_origin.Set(security_origin_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        params->security_origin.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null security_origin in MediaDevicesDispatcherHost.EnumerateDevices request");
    (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
    mojo::MessageReceiver* responder = new MediaDevicesDispatcherHost_EnumerateDevices_ForwardToCallback(
        std::move(callback), group_controller_);
    if (!receiver_->AcceptWithResponder(builder.message(), responder))
        delete responder;
}

void MediaDevicesDispatcherHostProxy::SubscribeDeviceChangeNotifications(
    ::content::MediaDeviceType in_type, uint32_t in_subscription_id, const url::Origin& in_security_origin)
{
    mojo::internal::SerializationContext serialization_context(
        group_controller_);
    size_t size = sizeof(::mojom::internal::MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data);
    size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
        in_security_origin, &serialization_context);
    mojo::internal::MessageBuilder builder(internal::kMediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Name, size);

    auto params = ::mojom::internal::MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    mojo::internal::Serialize<::mojom::MediaDeviceType>(
        in_type, &params->type);
    params->subscription_id = in_subscription_id;
    typename decltype(params->security_origin)::BaseType* security_origin_ptr;
    mojo::internal::Serialize<::url::mojom::OriginDataView>(
        in_security_origin, builder.buffer(), &security_origin_ptr, &serialization_context);
    params->security_origin.Set(security_origin_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        params->security_origin.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null security_origin in MediaDevicesDispatcherHost.SubscribeDeviceChangeNotifications request");
    (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
    bool ok = receiver_->Accept(builder.message());
    // This return value may be ignored as !ok implies the Connector has
    // encountered an error, which will be visible through other means.
    ALLOW_UNUSED_LOCAL(ok);
}

void MediaDevicesDispatcherHostProxy::UnsubscribeDeviceChangeNotifications(
    ::content::MediaDeviceType in_type, uint32_t in_subscription_id)
{
    mojo::internal::SerializationContext serialization_context(
        group_controller_);
    size_t size = sizeof(::mojom::internal::MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data);
    mojo::internal::MessageBuilder builder(internal::kMediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Name, size);

    auto params = ::mojom::internal::MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    mojo::internal::Serialize<::mojom::MediaDeviceType>(
        in_type, &params->type);
    params->subscription_id = in_subscription_id;
    (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
    bool ok = receiver_->Accept(builder.message());
    // This return value may be ignored as !ok implies the Connector has
    // encountered an error, which will be visible through other means.
    ALLOW_UNUSED_LOCAL(ok);
}
class MediaDevicesDispatcherHost_EnumerateDevices_ProxyToResponder {
public:
    static MediaDevicesDispatcherHost::EnumerateDevicesCallback CreateCallback(
        uint64_t request_id,
        bool is_sync,
        mojo::MessageReceiverWithStatus* responder,
        scoped_refptr<mojo::AssociatedGroupController>
            group_controller)
    {
        std::unique_ptr<MediaDevicesDispatcherHost_EnumerateDevices_ProxyToResponder> proxy(
            new MediaDevicesDispatcherHost_EnumerateDevices_ProxyToResponder(
                request_id, is_sync, responder, group_controller));
        return base::Bind(&MediaDevicesDispatcherHost_EnumerateDevices_ProxyToResponder::Run,
            base::Passed(&proxy));
    }

    ~MediaDevicesDispatcherHost_EnumerateDevices_ProxyToResponder()
    {
#if DCHECK_IS_ON()
        if (responder_) {
            // Is the Service destroying the callback without running it
            // and without first closing the pipe?
            responder_->DCheckInvalid("The callback passed to "
                                      "MediaDevicesDispatcherHost::EnumerateDevices() was never run.");
        }
#endif
        // If the Callback was dropped then deleting the responder will close
        // the pipe so the calling application knows to stop waiting for a reply.
        delete responder_;
    }

private:
    MediaDevicesDispatcherHost_EnumerateDevices_ProxyToResponder(
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
        const std::vector<std::vector<::content::MediaDeviceInfo>>& in_enumeration);

    uint64_t request_id_;
    bool is_sync_;
    mojo::MessageReceiverWithStatus* responder_;
    // TODO(yzshen): maybe I should use a ref to the original one?
    mojo::internal::SerializationContext serialization_context_;

    DISALLOW_COPY_AND_ASSIGN(MediaDevicesDispatcherHost_EnumerateDevices_ProxyToResponder);
};

void MediaDevicesDispatcherHost_EnumerateDevices_ProxyToResponder::Run(
    const std::vector<std::vector<::content::MediaDeviceInfo>>& in_enumeration)
{
    size_t size = sizeof(::mojom::internal::MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data);
    size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::ArrayDataView<::mojom::MediaDeviceInfoDataView>>>(
        in_enumeration, &serialization_context_);
    mojo::internal::ResponseMessageBuilder builder(
        internal::kMediaDevicesDispatcherHost_EnumerateDevices_Name, size, request_id_,
        is_sync_ ? mojo::Message::kFlagIsSync : 0);
    auto params = ::mojom::internal::MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    typename decltype(params->enumeration)::BaseType* enumeration_ptr;
    const mojo::internal::ContainerValidateParams enumeration_validate_params(
        0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
    mojo::internal::Serialize<mojo::ArrayDataView<mojo::ArrayDataView<::mojom::MediaDeviceInfoDataView>>>(
        in_enumeration, builder.buffer(), &enumeration_ptr, &enumeration_validate_params,
        &serialization_context_);
    params->enumeration.Set(enumeration_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        params->enumeration.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null enumeration in MediaDevicesDispatcherHost.EnumerateDevices response");
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
bool MediaDevicesDispatcherHostStubDispatch::Accept(
    MediaDevicesDispatcherHost* impl,
    mojo::internal::SerializationContext* context,
    mojo::Message* message)
{
    switch (message->header()->name) {
    case internal::kMediaDevicesDispatcherHost_EnumerateDevices_Name: {
        break;
    }
    case internal::kMediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Name: {
        internal::MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data* params = reinterpret_cast<internal::MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data*>(
            message->mutable_payload());

        (context)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::content::MediaDeviceType p_type {};
        uint32_t p_subscription_id {};
        url::Origin p_security_origin {};
        MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_ParamsDataView input_data_view(params,
            context);

        if (!input_data_view.ReadType(&p_type))
            success = false;
        p_subscription_id = input_data_view.subscription_id();
        if (!input_data_view.ReadSecurityOrigin(&p_security_origin))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "MediaDevicesDispatcherHost::SubscribeDeviceChangeNotifications deserializer");
            return false;
        }
        // A null |impl| means no implementation was bound.
        assert(impl);
        TRACE_EVENT0("mojom", "MediaDevicesDispatcherHost::SubscribeDeviceChangeNotifications");
        mojo::internal::MessageDispatchContext context(message);
        impl->SubscribeDeviceChangeNotifications(
            std::move(p_type),
            std::move(p_subscription_id),
            std::move(p_security_origin));
        return true;
    }
    case internal::kMediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Name: {
        internal::MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data* params = reinterpret_cast<internal::MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data*>(
            message->mutable_payload());

        (context)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::content::MediaDeviceType p_type {};
        uint32_t p_subscription_id {};
        MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_ParamsDataView input_data_view(params,
            context);

        if (!input_data_view.ReadType(&p_type))
            success = false;
        p_subscription_id = input_data_view.subscription_id();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "MediaDevicesDispatcherHost::UnsubscribeDeviceChangeNotifications deserializer");
            return false;
        }
        // A null |impl| means no implementation was bound.
        assert(impl);
        TRACE_EVENT0("mojom", "MediaDevicesDispatcherHost::UnsubscribeDeviceChangeNotifications");
        mojo::internal::MessageDispatchContext context(message);
        impl->UnsubscribeDeviceChangeNotifications(
            std::move(p_type),
            std::move(p_subscription_id));
        return true;
    }
    }
    return false;
}

// static
bool MediaDevicesDispatcherHostStubDispatch::AcceptWithResponder(
    MediaDevicesDispatcherHost* impl,
    mojo::internal::SerializationContext* context,
    mojo::Message* message,
    mojo::MessageReceiverWithStatus* responder)
{
    switch (message->header()->name) {
    case internal::kMediaDevicesDispatcherHost_EnumerateDevices_Name: {
        internal::MediaDevicesDispatcherHost_EnumerateDevices_Params_Data* params = reinterpret_cast<internal::MediaDevicesDispatcherHost_EnumerateDevices_Params_Data*>(
            message->mutable_payload());

        (context)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_request_audio_input {};
        bool p_request_video_input {};
        bool p_request_audio_output {};
        url::Origin p_security_origin {};
        MediaDevicesDispatcherHost_EnumerateDevices_ParamsDataView input_data_view(params,
            context);

        p_request_audio_input = input_data_view.request_audio_input();
        p_request_video_input = input_data_view.request_video_input();
        p_request_audio_output = input_data_view.request_audio_output();
        if (!input_data_view.ReadSecurityOrigin(&p_security_origin))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "MediaDevicesDispatcherHost::EnumerateDevices deserializer");
            return false;
        }
        MediaDevicesDispatcherHost::EnumerateDevicesCallback callback = MediaDevicesDispatcherHost_EnumerateDevices_ProxyToResponder::CreateCallback(
            message->request_id(),
            message->has_flag(mojo::Message::kFlagIsSync), responder,
            context->group_controller);
        // A null |impl| means no implementation was bound.
        assert(impl);
        TRACE_EVENT0("mojom", "MediaDevicesDispatcherHost::EnumerateDevices");
        mojo::internal::MessageDispatchContext context(message);
        impl->EnumerateDevices(
            std::move(p_request_audio_input),
            std::move(p_request_video_input),
            std::move(p_request_audio_output),
            std::move(p_security_origin), std::move(callback));
        return true;
    }
    case internal::kMediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Name: {
        break;
    }
    case internal::kMediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Name: {
        break;
    }
    }
    return false;
}

bool MediaDevicesDispatcherHostRequestValidator::Accept(mojo::Message* message)
{
    if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
        return true;

    mojo::internal::ValidationContext validation_context(
        message->data(), message->data_num_bytes(), message->handles()->size(),
        message, "MediaDevicesDispatcherHost RequestValidator");

    switch (message->header()->name) {
    case internal::kMediaDevicesDispatcherHost_EnumerateDevices_Name: {
        if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                message, &validation_context)) {
            return false;
        }
        if (!mojo::internal::ValidateMessagePayload<
                internal::MediaDevicesDispatcherHost_EnumerateDevices_Params_Data>(
                message, &validation_context)) {
            return false;
        }
        return true;
    }
    case internal::kMediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Name: {
        if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                message, &validation_context)) {
            return false;
        }
        if (!mojo::internal::ValidateMessagePayload<
                internal::MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data>(
                message, &validation_context)) {
            return false;
        }
        return true;
    }
    case internal::kMediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Name: {
        if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                message, &validation_context)) {
            return false;
        }
        if (!mojo::internal::ValidateMessagePayload<
                internal::MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data>(
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

bool MediaDevicesDispatcherHostResponseValidator::Accept(mojo::Message* message)
{
    if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
        return true;

    mojo::internal::ValidationContext validation_context(
        message->data(), message->data_num_bytes(), message->handles()->size(),
        message, "MediaDevicesDispatcherHost ResponseValidator");

    if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
        return false;
    switch (message->header()->name) {
    case internal::kMediaDevicesDispatcherHost_EnumerateDevices_Name: {
        if (!mojo::internal::ValidateMessagePayload<
                internal::MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data>(
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
const char MediaDevicesListener::Name_[] = "mojom::MediaDevicesListener";

MediaDevicesListenerProxy::MediaDevicesListenerProxy(mojo::MessageReceiverWithResponder* receiver)
    : receiver_(receiver)
{
}

void MediaDevicesListenerProxy::OnDevicesChanged(
    ::content::MediaDeviceType in_type, uint32_t in_subscription_id, const std::vector<::content::MediaDeviceInfo>& in_device_infos)
{
    mojo::internal::SerializationContext serialization_context(
        group_controller_);
    size_t size = sizeof(::mojom::internal::MediaDevicesListener_OnDevicesChanged_Params_Data);
    size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::mojom::MediaDeviceInfoDataView>>(
        in_device_infos, &serialization_context);
    mojo::internal::MessageBuilder builder(internal::kMediaDevicesListener_OnDevicesChanged_Name, size);

    auto params = ::mojom::internal::MediaDevicesListener_OnDevicesChanged_Params_Data::New(builder.buffer());
    ALLOW_UNUSED_LOCAL(params);
    mojo::internal::Serialize<::mojom::MediaDeviceType>(
        in_type, &params->type);
    params->subscription_id = in_subscription_id;
    typename decltype(params->device_infos)::BaseType* device_infos_ptr;
    const mojo::internal::ContainerValidateParams device_infos_validate_params(
        0, false, nullptr);
    mojo::internal::Serialize<mojo::ArrayDataView<::mojom::MediaDeviceInfoDataView>>(
        in_device_infos, builder.buffer(), &device_infos_ptr, &device_infos_validate_params,
        &serialization_context);
    params->device_infos.Set(device_infos_ptr);
    MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
        params->device_infos.is_null(),
        mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
        "null device_infos in MediaDevicesListener.OnDevicesChanged request");
    (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
    bool ok = receiver_->Accept(builder.message());
    // This return value may be ignored as !ok implies the Connector has
    // encountered an error, which will be visible through other means.
    ALLOW_UNUSED_LOCAL(ok);
}

// static
bool MediaDevicesListenerStubDispatch::Accept(
    MediaDevicesListener* impl,
    mojo::internal::SerializationContext* context,
    mojo::Message* message)
{
    switch (message->header()->name) {
    case internal::kMediaDevicesListener_OnDevicesChanged_Name: {
        internal::MediaDevicesListener_OnDevicesChanged_Params_Data* params = reinterpret_cast<internal::MediaDevicesListener_OnDevicesChanged_Params_Data*>(
            message->mutable_payload());

        (context)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::content::MediaDeviceType p_type {};
        uint32_t p_subscription_id {};
        std::vector<::content::MediaDeviceInfo> p_device_infos {};
        MediaDevicesListener_OnDevicesChanged_ParamsDataView input_data_view(params,
            context);

        if (!input_data_view.ReadType(&p_type))
            success = false;
        p_subscription_id = input_data_view.subscription_id();
        if (!input_data_view.ReadDeviceInfos(&p_device_infos))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "MediaDevicesListener::OnDevicesChanged deserializer");
            return false;
        }
        // A null |impl| means no implementation was bound.
        assert(impl);
        TRACE_EVENT0("mojom", "MediaDevicesListener::OnDevicesChanged");
        mojo::internal::MessageDispatchContext context(message);
        impl->OnDevicesChanged(
            std::move(p_type),
            std::move(p_subscription_id),
            std::move(p_device_infos));
        return true;
    }
    }
    return false;
}

// static
bool MediaDevicesListenerStubDispatch::AcceptWithResponder(
    MediaDevicesListener* impl,
    mojo::internal::SerializationContext* context,
    mojo::Message* message,
    mojo::MessageReceiverWithStatus* responder)
{
    switch (message->header()->name) {
    case internal::kMediaDevicesListener_OnDevicesChanged_Name: {
        break;
    }
    }
    return false;
}

bool MediaDevicesListenerRequestValidator::Accept(mojo::Message* message)
{
    if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
        return true;

    mojo::internal::ValidationContext validation_context(
        message->data(), message->data_num_bytes(), message->handles()->size(),
        message, "MediaDevicesListener RequestValidator");

    switch (message->header()->name) {
    case internal::kMediaDevicesListener_OnDevicesChanged_Name: {
        if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                message, &validation_context)) {
            return false;
        }
        if (!mojo::internal::ValidateMessagePayload<
                internal::MediaDevicesListener_OnDevicesChanged_Params_Data>(
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

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif