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

#include "content/common/leveldb_wrapper.mojom.h"

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
    KeyValuePtr KeyValue::New()
    {
        KeyValuePtr rv;
        mojo::internal::StructHelper<KeyValue>::Initialize(&rv);
        return rv;
    }

    KeyValue::KeyValue()
        : key()
        , value()
    {
    }

    KeyValue::~KeyValue()
    {
    }
    const char LevelDBObserver::Name_[] = "content::mojom::LevelDBObserver";

    LevelDBObserverProxy::LevelDBObserverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void LevelDBObserverProxy::KeyAdded(
        const std::vector<uint8_t>& in_key, const std::vector<uint8_t>& in_value, const std::string& in_source)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBObserver_KeyAdded_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_source, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kLevelDBObserver_KeyAdded_Name, size);

        auto params = ::content::mojom::internal::LevelDBObserver_KeyAdded_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBObserver.KeyAdded request");
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in LevelDBObserver.KeyAdded request");
        typename decltype(params->source)::BaseType* source_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_source, builder.buffer(), &source_ptr, &serialization_context);
        params->source.Set(source_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->source.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null source in LevelDBObserver.KeyAdded request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void LevelDBObserverProxy::KeyChanged(
        const std::vector<uint8_t>& in_key, const std::vector<uint8_t>& in_new_value, const std::vector<uint8_t>& in_old_value, const std::string& in_source)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBObserver_KeyChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_new_value, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_old_value, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_source, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kLevelDBObserver_KeyChanged_Name, size);

        auto params = ::content::mojom::internal::LevelDBObserver_KeyChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBObserver.KeyChanged request");
        typename decltype(params->new_value)::BaseType* new_value_ptr;
        const mojo::internal::ContainerValidateParams new_value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_new_value, builder.buffer(), &new_value_ptr, &new_value_validate_params,
            &serialization_context);
        params->new_value.Set(new_value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->new_value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null new_value in LevelDBObserver.KeyChanged request");
        typename decltype(params->old_value)::BaseType* old_value_ptr;
        const mojo::internal::ContainerValidateParams old_value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_old_value, builder.buffer(), &old_value_ptr, &old_value_validate_params,
            &serialization_context);
        params->old_value.Set(old_value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->old_value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null old_value in LevelDBObserver.KeyChanged request");
        typename decltype(params->source)::BaseType* source_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_source, builder.buffer(), &source_ptr, &serialization_context);
        params->source.Set(source_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->source.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null source in LevelDBObserver.KeyChanged request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void LevelDBObserverProxy::KeyDeleted(
        const std::vector<uint8_t>& in_key, const std::vector<uint8_t>& in_old_value, const std::string& in_source)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBObserver_KeyDeleted_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_old_value, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_source, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kLevelDBObserver_KeyDeleted_Name, size);

        auto params = ::content::mojom::internal::LevelDBObserver_KeyDeleted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBObserver.KeyDeleted request");
        typename decltype(params->old_value)::BaseType* old_value_ptr;
        const mojo::internal::ContainerValidateParams old_value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_old_value, builder.buffer(), &old_value_ptr, &old_value_validate_params,
            &serialization_context);
        params->old_value.Set(old_value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->old_value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null old_value in LevelDBObserver.KeyDeleted request");
        typename decltype(params->source)::BaseType* source_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_source, builder.buffer(), &source_ptr, &serialization_context);
        params->source.Set(source_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->source.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null source in LevelDBObserver.KeyDeleted request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void LevelDBObserverProxy::AllDeleted(
        const std::string& in_source)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBObserver_AllDeleted_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_source, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kLevelDBObserver_AllDeleted_Name, size);

        auto params = ::content::mojom::internal::LevelDBObserver_AllDeleted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->source)::BaseType* source_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_source, builder.buffer(), &source_ptr, &serialization_context);
        params->source.Set(source_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->source.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null source in LevelDBObserver.AllDeleted request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool LevelDBObserverStubDispatch::Accept(
        LevelDBObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kLevelDBObserver_KeyAdded_Name: {
            internal::LevelDBObserver_KeyAdded_Params_Data* params = reinterpret_cast<internal::LevelDBObserver_KeyAdded_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key {};
            std::vector<uint8_t> p_value {};
            std::string p_source {};
            LevelDBObserver_KeyAdded_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!input_data_view.ReadSource(&p_source))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBObserver::KeyAdded deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBObserver::KeyAdded");
            mojo::internal::MessageDispatchContext context(message);
            impl->KeyAdded(
                std::move(p_key),
                std::move(p_value),
                std::move(p_source));
            return true;
        }
        case internal::kLevelDBObserver_KeyChanged_Name: {
            internal::LevelDBObserver_KeyChanged_Params_Data* params = reinterpret_cast<internal::LevelDBObserver_KeyChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key {};
            std::vector<uint8_t> p_new_value {};
            std::vector<uint8_t> p_old_value {};
            std::string p_source {};
            LevelDBObserver_KeyChanged_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadNewValue(&p_new_value))
                success = false;
            if (!input_data_view.ReadOldValue(&p_old_value))
                success = false;
            if (!input_data_view.ReadSource(&p_source))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBObserver::KeyChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBObserver::KeyChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->KeyChanged(
                std::move(p_key),
                std::move(p_new_value),
                std::move(p_old_value),
                std::move(p_source));
            return true;
        }
        case internal::kLevelDBObserver_KeyDeleted_Name: {
            internal::LevelDBObserver_KeyDeleted_Params_Data* params = reinterpret_cast<internal::LevelDBObserver_KeyDeleted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key {};
            std::vector<uint8_t> p_old_value {};
            std::string p_source {};
            LevelDBObserver_KeyDeleted_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadOldValue(&p_old_value))
                success = false;
            if (!input_data_view.ReadSource(&p_source))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBObserver::KeyDeleted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBObserver::KeyDeleted");
            mojo::internal::MessageDispatchContext context(message);
            impl->KeyDeleted(
                std::move(p_key),
                std::move(p_old_value),
                std::move(p_source));
            return true;
        }
        case internal::kLevelDBObserver_AllDeleted_Name: {
            internal::LevelDBObserver_AllDeleted_Params_Data* params = reinterpret_cast<internal::LevelDBObserver_AllDeleted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_source {};
            LevelDBObserver_AllDeleted_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSource(&p_source))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBObserver::AllDeleted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBObserver::AllDeleted");
            mojo::internal::MessageDispatchContext context(message);
            impl->AllDeleted(
                std::move(p_source));
            return true;
        }
        }
        return false;
    }

    // static
    bool LevelDBObserverStubDispatch::AcceptWithResponder(
        LevelDBObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kLevelDBObserver_KeyAdded_Name: {
            break;
        }
        case internal::kLevelDBObserver_KeyChanged_Name: {
            break;
        }
        case internal::kLevelDBObserver_KeyDeleted_Name: {
            break;
        }
        case internal::kLevelDBObserver_AllDeleted_Name: {
            break;
        }
        }
        return false;
    }

    bool LevelDBObserverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "LevelDBObserver RequestValidator");

        switch (message->header()->name) {
        case internal::kLevelDBObserver_KeyAdded_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBObserver_KeyAdded_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBObserver_KeyChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBObserver_KeyChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBObserver_KeyDeleted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBObserver_KeyDeleted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBObserver_AllDeleted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBObserver_AllDeleted_Params_Data>(
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

    const char LevelDBWrapperGetAllCallback::Name_[] = "content::mojom::LevelDBWrapperGetAllCallback";

    LevelDBWrapperGetAllCallbackProxy::LevelDBWrapperGetAllCallbackProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void LevelDBWrapperGetAllCallbackProxy::Complete(
        bool in_success)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapperGetAllCallback_Complete_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kLevelDBWrapperGetAllCallback_Complete_Name, size);

        auto params = ::content::mojom::internal::LevelDBWrapperGetAllCallback_Complete_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool LevelDBWrapperGetAllCallbackStubDispatch::Accept(
        LevelDBWrapperGetAllCallback* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kLevelDBWrapperGetAllCallback_Complete_Name: {
            internal::LevelDBWrapperGetAllCallback_Complete_Params_Data* params = reinterpret_cast<internal::LevelDBWrapperGetAllCallback_Complete_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_success {};
            LevelDBWrapperGetAllCallback_Complete_ParamsDataView input_data_view(params,
                context);

            p_success = input_data_view.success();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBWrapperGetAllCallback::Complete deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBWrapperGetAllCallback::Complete");
            mojo::internal::MessageDispatchContext context(message);
            impl->Complete(
                std::move(p_success));
            return true;
        }
        }
        return false;
    }

    // static
    bool LevelDBWrapperGetAllCallbackStubDispatch::AcceptWithResponder(
        LevelDBWrapperGetAllCallback* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kLevelDBWrapperGetAllCallback_Complete_Name: {
            break;
        }
        }
        return false;
    }

    bool LevelDBWrapperGetAllCallbackRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "LevelDBWrapperGetAllCallback RequestValidator");

        switch (message->header()->name) {
        case internal::kLevelDBWrapperGetAllCallback_Complete_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapperGetAllCallback_Complete_Params_Data>(
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

    const char LevelDBWrapper::Name_[] = "content::mojom::LevelDBWrapper";
    bool LevelDBWrapper::GetAll(LevelDBWrapperGetAllCallbackAssociatedPtrInfo complete_callback, ::leveldb::mojom::DatabaseError* status, std::vector<KeyValuePtr>* data)
    {
        NOTREACHED();
        return false;
    }

    class LevelDBWrapper_Put_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBWrapper_Put_ForwardToCallback(
            const LevelDBWrapper::PutCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBWrapper::PutCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_Put_ForwardToCallback);
    };
    bool LevelDBWrapper_Put_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBWrapper_Put_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBWrapper_Put_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        LevelDBWrapper_Put_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBWrapper::Put response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    class LevelDBWrapper_Delete_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBWrapper_Delete_ForwardToCallback(
            const LevelDBWrapper::DeleteCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBWrapper::DeleteCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_Delete_ForwardToCallback);
    };
    bool LevelDBWrapper_Delete_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBWrapper_Delete_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBWrapper_Delete_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        LevelDBWrapper_Delete_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBWrapper::Delete response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    class LevelDBWrapper_DeleteAll_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBWrapper_DeleteAll_ForwardToCallback(
            const LevelDBWrapper::DeleteAllCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBWrapper::DeleteAllCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_DeleteAll_ForwardToCallback);
    };
    bool LevelDBWrapper_DeleteAll_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBWrapper_DeleteAll_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBWrapper_DeleteAll_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        LevelDBWrapper_DeleteAll_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBWrapper::DeleteAll response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    class LevelDBWrapper_Get_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBWrapper_Get_ForwardToCallback(
            const LevelDBWrapper::GetCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBWrapper::GetCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_Get_ForwardToCallback);
    };
    bool LevelDBWrapper_Get_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBWrapper_Get_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBWrapper_Get_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        std::vector<uint8_t> p_value {};
        LevelDBWrapper_Get_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBWrapper::Get response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success),
                std::move(p_value));
        }
        return true;
    }
    class LevelDBWrapper_GetAll_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        LevelDBWrapper_GetAll_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::leveldb::mojom::DatabaseError* out_status, std::vector<KeyValuePtr>* out_data)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_status_(out_status)
            , out_data_(out_data)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::leveldb::mojom::DatabaseError* out_status_;
        std::vector<KeyValuePtr>* out_data_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_GetAll_HandleSyncResponse);
    };
    bool LevelDBWrapper_GetAll_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::LevelDBWrapper_GetAll_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBWrapper_GetAll_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::leveldb::mojom::DatabaseError p_status {};
        std::vector<KeyValuePtr> p_data {};
        LevelDBWrapper_GetAll_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadData(&p_data))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBWrapper::GetAll response deserializer");
            return false;
        }
        *out_status_ = std::move(p_status);
        *out_data_ = std::move(p_data);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class LevelDBWrapper_GetAll_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBWrapper_GetAll_ForwardToCallback(
            const LevelDBWrapper::GetAllCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBWrapper::GetAllCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_GetAll_ForwardToCallback);
    };
    bool LevelDBWrapper_GetAll_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBWrapper_GetAll_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBWrapper_GetAll_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::leveldb::mojom::DatabaseError p_status {};
        std::vector<KeyValuePtr> p_data {};
        LevelDBWrapper_GetAll_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadData(&p_data))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBWrapper::GetAll response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_data));
        }
        return true;
    }

    LevelDBWrapperProxy::LevelDBWrapperProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void LevelDBWrapperProxy::AddObserver(
        LevelDBObserverAssociatedPtrInfo in_observer)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_AddObserver_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kLevelDBWrapper_AddObserver_Name, size);

        auto params = ::content::mojom::internal::LevelDBWrapper_AddObserver_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::content::mojom::LevelDBObserverAssociatedPtrInfoDataView>(
            in_observer, &params->observer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->observer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid observer in LevelDBWrapper.AddObserver request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void LevelDBWrapperProxy::Put(
        const std::vector<uint8_t>& in_key, const std::vector<uint8_t>& in_value, const std::string& in_source, const PutCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_Put_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_source, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBWrapper_Put_Name, size);

        auto params = ::content::mojom::internal::LevelDBWrapper_Put_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBWrapper.Put request");
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in LevelDBWrapper.Put request");
        typename decltype(params->source)::BaseType* source_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_source, builder.buffer(), &source_ptr, &serialization_context);
        params->source.Set(source_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->source.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null source in LevelDBWrapper.Put request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBWrapper_Put_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBWrapperProxy::Delete(
        const std::vector<uint8_t>& in_key, const std::string& in_source, const DeleteCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_Delete_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_source, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBWrapper_Delete_Name, size);

        auto params = ::content::mojom::internal::LevelDBWrapper_Delete_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBWrapper.Delete request");
        typename decltype(params->source)::BaseType* source_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_source, builder.buffer(), &source_ptr, &serialization_context);
        params->source.Set(source_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->source.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null source in LevelDBWrapper.Delete request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBWrapper_Delete_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBWrapperProxy::DeleteAll(
        const std::string& in_source, const DeleteAllCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_DeleteAll_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_source, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBWrapper_DeleteAll_Name, size);

        auto params = ::content::mojom::internal::LevelDBWrapper_DeleteAll_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->source)::BaseType* source_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_source, builder.buffer(), &source_ptr, &serialization_context);
        params->source.Set(source_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->source.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null source in LevelDBWrapper.DeleteAll request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBWrapper_DeleteAll_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBWrapperProxy::Get(
        const std::vector<uint8_t>& in_key, const GetCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_Get_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBWrapper_Get_Name, size);

        auto params = ::content::mojom::internal::LevelDBWrapper_Get_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBWrapper.Get request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBWrapper_Get_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool LevelDBWrapperProxy::GetAll(
        LevelDBWrapperGetAllCallbackAssociatedPtrInfo param_complete_callback, ::leveldb::mojom::DatabaseError* param_status, std::vector<KeyValuePtr>* param_data)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_GetAll_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBWrapper_GetAll_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::content::mojom::internal::LevelDBWrapper_GetAll_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::content::mojom::LevelDBWrapperGetAllCallbackAssociatedPtrInfoDataView>(
            param_complete_callback, &params->complete_callback, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->complete_callback),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid complete_callback in LevelDBWrapper.GetAll request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new LevelDBWrapper_GetAll_HandleSyncResponse(
            group_controller_, &result, param_status, param_data);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void LevelDBWrapperProxy::GetAll(
        LevelDBWrapperGetAllCallbackAssociatedPtrInfo in_complete_callback, const GetAllCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_GetAll_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBWrapper_GetAll_Name, size);

        auto params = ::content::mojom::internal::LevelDBWrapper_GetAll_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::content::mojom::LevelDBWrapperGetAllCallbackAssociatedPtrInfoDataView>(
            in_complete_callback, &params->complete_callback, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->complete_callback),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid complete_callback in LevelDBWrapper.GetAll request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBWrapper_GetAll_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class LevelDBWrapper_Put_ProxyToResponder {
    public:
        static LevelDBWrapper::PutCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBWrapper_Put_ProxyToResponder> proxy(
                new LevelDBWrapper_Put_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBWrapper_Put_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBWrapper_Put_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBWrapper::Put() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBWrapper_Put_ProxyToResponder(
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

        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_Put_ProxyToResponder);
    };

    void LevelDBWrapper_Put_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_Put_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBWrapper_Put_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::LevelDBWrapper_Put_ResponseParams_Data::New(builder.buffer());
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
    class LevelDBWrapper_Delete_ProxyToResponder {
    public:
        static LevelDBWrapper::DeleteCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBWrapper_Delete_ProxyToResponder> proxy(
                new LevelDBWrapper_Delete_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBWrapper_Delete_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBWrapper_Delete_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBWrapper::Delete() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBWrapper_Delete_ProxyToResponder(
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

        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_Delete_ProxyToResponder);
    };

    void LevelDBWrapper_Delete_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_Delete_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBWrapper_Delete_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::LevelDBWrapper_Delete_ResponseParams_Data::New(builder.buffer());
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
    class LevelDBWrapper_DeleteAll_ProxyToResponder {
    public:
        static LevelDBWrapper::DeleteAllCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBWrapper_DeleteAll_ProxyToResponder> proxy(
                new LevelDBWrapper_DeleteAll_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBWrapper_DeleteAll_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBWrapper_DeleteAll_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBWrapper::DeleteAll() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBWrapper_DeleteAll_ProxyToResponder(
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

        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_DeleteAll_ProxyToResponder);
    };

    void LevelDBWrapper_DeleteAll_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_DeleteAll_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBWrapper_DeleteAll_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::LevelDBWrapper_DeleteAll_ResponseParams_Data::New(builder.buffer());
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
    class LevelDBWrapper_Get_ProxyToResponder {
    public:
        static LevelDBWrapper::GetCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBWrapper_Get_ProxyToResponder> proxy(
                new LevelDBWrapper_Get_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBWrapper_Get_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBWrapper_Get_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBWrapper::Get() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBWrapper_Get_ProxyToResponder(
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
            bool in_success, const std::vector<uint8_t>& in_value);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_Get_ProxyToResponder);
    };

    void LevelDBWrapper_Get_ProxyToResponder::Run(
        bool in_success, const std::vector<uint8_t>& in_value)
    {
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_Get_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBWrapper_Get_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::LevelDBWrapper_Get_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context_);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in LevelDBWrapper.Get response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBWrapper_GetAll_ProxyToResponder {
    public:
        static LevelDBWrapper::GetAllCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBWrapper_GetAll_ProxyToResponder> proxy(
                new LevelDBWrapper_GetAll_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBWrapper_GetAll_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBWrapper_GetAll_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBWrapper::GetAll() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBWrapper_GetAll_ProxyToResponder(
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
            ::leveldb::mojom::DatabaseError in_status, std::vector<KeyValuePtr> in_data);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBWrapper_GetAll_ProxyToResponder);
    };

    void LevelDBWrapper_GetAll_ProxyToResponder::Run(
        ::leveldb::mojom::DatabaseError in_status, std::vector<KeyValuePtr> in_data)
    {
        size_t size = sizeof(::content::mojom::internal::LevelDBWrapper_GetAll_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::content::mojom::KeyValueDataView>>(
            in_data, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBWrapper_GetAll_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::content::mojom::internal::LevelDBWrapper_GetAll_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        typename decltype(params->data)::BaseType* data_ptr;
        const mojo::internal::ContainerValidateParams data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::content::mojom::KeyValueDataView>>(
            in_data, builder.buffer(), &data_ptr, &data_validate_params,
            &serialization_context_);
        params->data.Set(data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null data in LevelDBWrapper.GetAll response");
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
    bool LevelDBWrapperStubDispatch::Accept(
        LevelDBWrapper* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kLevelDBWrapper_AddObserver_Name: {
            internal::LevelDBWrapper_AddObserver_Params_Data* params = reinterpret_cast<internal::LevelDBWrapper_AddObserver_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            LevelDBObserverAssociatedPtrInfo p_observer {};
            LevelDBWrapper_AddObserver_ParamsDataView input_data_view(params,
                context);

            p_observer = input_data_view.TakeObserver<decltype(p_observer)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBWrapper::AddObserver deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBWrapper::AddObserver");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddObserver(
                std::move(p_observer));
            return true;
        }
        case internal::kLevelDBWrapper_Put_Name: {
            break;
        }
        case internal::kLevelDBWrapper_Delete_Name: {
            break;
        }
        case internal::kLevelDBWrapper_DeleteAll_Name: {
            break;
        }
        case internal::kLevelDBWrapper_Get_Name: {
            break;
        }
        case internal::kLevelDBWrapper_GetAll_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool LevelDBWrapperStubDispatch::AcceptWithResponder(
        LevelDBWrapper* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kLevelDBWrapper_AddObserver_Name: {
            break;
        }
        case internal::kLevelDBWrapper_Put_Name: {
            internal::LevelDBWrapper_Put_Params_Data* params = reinterpret_cast<internal::LevelDBWrapper_Put_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key {};
            std::vector<uint8_t> p_value {};
            std::string p_source {};
            LevelDBWrapper_Put_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!input_data_view.ReadSource(&p_source))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBWrapper::Put deserializer");
                return false;
            }
            LevelDBWrapper::PutCallback callback = LevelDBWrapper_Put_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBWrapper::Put");
            mojo::internal::MessageDispatchContext context(message);
            impl->Put(
                std::move(p_key),
                std::move(p_value),
                std::move(p_source), std::move(callback));
            return true;
        }
        case internal::kLevelDBWrapper_Delete_Name: {
            internal::LevelDBWrapper_Delete_Params_Data* params = reinterpret_cast<internal::LevelDBWrapper_Delete_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key {};
            std::string p_source {};
            LevelDBWrapper_Delete_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadSource(&p_source))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBWrapper::Delete deserializer");
                return false;
            }
            LevelDBWrapper::DeleteCallback callback = LevelDBWrapper_Delete_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBWrapper::Delete");
            mojo::internal::MessageDispatchContext context(message);
            impl->Delete(
                std::move(p_key),
                std::move(p_source), std::move(callback));
            return true;
        }
        case internal::kLevelDBWrapper_DeleteAll_Name: {
            internal::LevelDBWrapper_DeleteAll_Params_Data* params = reinterpret_cast<internal::LevelDBWrapper_DeleteAll_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_source {};
            LevelDBWrapper_DeleteAll_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSource(&p_source))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBWrapper::DeleteAll deserializer");
                return false;
            }
            LevelDBWrapper::DeleteAllCallback callback = LevelDBWrapper_DeleteAll_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBWrapper::DeleteAll");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeleteAll(
                std::move(p_source), std::move(callback));
            return true;
        }
        case internal::kLevelDBWrapper_Get_Name: {
            internal::LevelDBWrapper_Get_Params_Data* params = reinterpret_cast<internal::LevelDBWrapper_Get_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key {};
            LevelDBWrapper_Get_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBWrapper::Get deserializer");
                return false;
            }
            LevelDBWrapper::GetCallback callback = LevelDBWrapper_Get_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBWrapper::Get");
            mojo::internal::MessageDispatchContext context(message);
            impl->Get(
                std::move(p_key), std::move(callback));
            return true;
        }
        case internal::kLevelDBWrapper_GetAll_Name: {
            internal::LevelDBWrapper_GetAll_Params_Data* params = reinterpret_cast<internal::LevelDBWrapper_GetAll_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            LevelDBWrapperGetAllCallbackAssociatedPtrInfo p_complete_callback {};
            LevelDBWrapper_GetAll_ParamsDataView input_data_view(params,
                context);

            p_complete_callback = input_data_view.TakeCompleteCallback<decltype(p_complete_callback)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBWrapper::GetAll deserializer");
                return false;
            }
            LevelDBWrapper::GetAllCallback callback = LevelDBWrapper_GetAll_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBWrapper::GetAll");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetAll(
                std::move(p_complete_callback), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool LevelDBWrapperRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "LevelDBWrapper RequestValidator");

        switch (message->header()->name) {
        case internal::kLevelDBWrapper_AddObserver_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_AddObserver_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBWrapper_Put_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_Put_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBWrapper_Delete_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_Delete_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBWrapper_DeleteAll_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_DeleteAll_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBWrapper_Get_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_Get_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBWrapper_GetAll_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_GetAll_Params_Data>(
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

    bool LevelDBWrapperResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "LevelDBWrapper ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kLevelDBWrapper_Put_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_Put_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBWrapper_Delete_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_Delete_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBWrapper_DeleteAll_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_DeleteAll_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBWrapper_Get_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_Get_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBWrapper_GetAll_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBWrapper_GetAll_ResponseParams_Data>(
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
bool StructTraits<::content::mojom::KeyValue::DataView, ::content::mojom::KeyValuePtr>::Read(
    ::content::mojom::KeyValue::DataView input,
    ::content::mojom::KeyValuePtr* output)
{
    bool success = true;
    ::content::mojom::KeyValuePtr result(::content::mojom::KeyValue::New());

    if (!input.ReadKey(&result->key))
        success = false;
    if (!input.ReadValue(&result->value))
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