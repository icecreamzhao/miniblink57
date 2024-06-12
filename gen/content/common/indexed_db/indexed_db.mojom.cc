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

#include "content/common/indexed_db/indexed_db.mojom.h"

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
namespace indexed_db {
namespace mojom { // static
    KeyPtr Key::New()
    {
        KeyPtr rv;
        mojo::internal::StructHelper<Key>::Initialize(&rv);
        return rv;
    }

    Key::Key()
        : data()
    {
    }

    Key::~Key()
    {
    } // static
    KeyPathPtr KeyPath::New()
    {
        KeyPathPtr rv;
        mojo::internal::StructHelper<KeyPath>::Initialize(&rv);
        return rv;
    }

    KeyPath::KeyPath()
        : data()
    {
    }

    KeyPath::~KeyPath()
    {
    } // static
    KeyRangePtr KeyRange::New()
    {
        KeyRangePtr rv;
        mojo::internal::StructHelper<KeyRange>::Initialize(&rv);
        return rv;
    }

    KeyRange::KeyRange()
        : lower()
        , upper()
        , lower_open()
        , upper_open()
    {
    }

    KeyRange::~KeyRange()
    {
    } // static
    IndexMetadataPtr IndexMetadata::New()
    {
        IndexMetadataPtr rv;
        mojo::internal::StructHelper<IndexMetadata>::Initialize(&rv);
        return rv;
    }

    IndexMetadata::IndexMetadata()
        : id()
        , name()
        , key_path()
        , unique()
        , multi_entry()
    {
    }

    IndexMetadata::~IndexMetadata()
    {
    } // static
    ObjectStoreMetadataPtr ObjectStoreMetadata::New()
    {
        ObjectStoreMetadataPtr rv;
        mojo::internal::StructHelper<ObjectStoreMetadata>::Initialize(&rv);
        return rv;
    }

    ObjectStoreMetadata::ObjectStoreMetadata()
        : id()
        , name()
        , key_path()
        , auto_increment()
        , max_index_id()
        , indexes()
    {
    }

    ObjectStoreMetadata::~ObjectStoreMetadata()
    {
    } // static
    DatabaseMetadataPtr DatabaseMetadata::New()
    {
        DatabaseMetadataPtr rv;
        mojo::internal::StructHelper<DatabaseMetadata>::Initialize(&rv);
        return rv;
    }

    DatabaseMetadata::DatabaseMetadata()
        : id()
        , name()
        , version()
        , max_object_store_id()
        , object_stores()
    {
    }

    DatabaseMetadata::~DatabaseMetadata()
    {
    } // static
    IndexKeysPtr IndexKeys::New()
    {
        IndexKeysPtr rv;
        mojo::internal::StructHelper<IndexKeys>::Initialize(&rv);
        return rv;
    }

    IndexKeys::IndexKeys()
        : index_id()
        , index_keys()
    {
    }

    IndexKeys::~IndexKeys()
    {
    } // static
    FileInfoPtr FileInfo::New()
    {
        FileInfoPtr rv;
        mojo::internal::StructHelper<FileInfo>::Initialize(&rv);
        return rv;
    }

    FileInfo::FileInfo()
        : path()
        , name()
        , last_modified()
    {
    }

    FileInfo::~FileInfo()
    {
    } // static
    BlobInfoPtr BlobInfo::New()
    {
        BlobInfoPtr rv;
        mojo::internal::StructHelper<BlobInfo>::Initialize(&rv);
        return rv;
    }

    BlobInfo::BlobInfo()
        : uuid()
        , mime_type()
        , size()
        , file()
    {
    }

    BlobInfo::~BlobInfo()
    {
    } // static
    ValuePtr Value::New()
    {
        ValuePtr rv;
        mojo::internal::StructHelper<Value>::Initialize(&rv);
        return rv;
    }

    Value::Value()
        : bits()
        , blob_or_file_info()
    {
    }

    Value::~Value()
    {
    } // static
    ReturnValuePtr ReturnValue::New()
    {
        ReturnValuePtr rv;
        mojo::internal::StructHelper<ReturnValue>::Initialize(&rv);
        return rv;
    }

    ReturnValue::ReturnValue()
        : value()
        , primary_key()
        , key_path()
    {
    }

    ReturnValue::~ReturnValue()
    {
    } // static
    ObservationPtr Observation::New()
    {
        ObservationPtr rv;
        mojo::internal::StructHelper<Observation>::Initialize(&rv);
        return rv;
    }

    Observation::Observation()
        : object_store_id()
        , type()
        , key_range()
        , value()
    {
    }

    Observation::~Observation()
    {
    } // static
    ObserverTransactionPtr ObserverTransaction::New()
    {
        ObserverTransactionPtr rv;
        mojo::internal::StructHelper<ObserverTransaction>::Initialize(&rv);
        return rv;
    }

    ObserverTransaction::ObserverTransaction()
        : id()
        , scope()
    {
    }

    ObserverTransaction::~ObserverTransaction()
    {
    } // static
    ObserverChangesPtr ObserverChanges::New()
    {
        ObserverChangesPtr rv;
        mojo::internal::StructHelper<ObserverChanges>::Initialize(&rv);
        return rv;
    }

    ObserverChanges::ObserverChanges()
        : observation_index_map()
        , transaction_map()
        , observations()
    {
    }

    ObserverChanges::~ObserverChanges()
    {
    } // static
    KeyDataPtr KeyData::New()
    {
        KeyDataPtr rv;
        mojo::internal::StructHelper<KeyData>::Initialize(&rv);
        return rv;
    }

    KeyData::KeyData()
    {
        // TODO(azani): Implement default values here when/if we support them.
        // TODO(azani): Set to UNKNOWN when unknown is implemented.
        SetActive(static_cast<Tag>(0));
    }

    KeyData::~KeyData()
    {
        DestroyActive();
    }

    void KeyData::set_key_array(const std::vector<content::IndexedDBKey>& key_array)
    {
        SwitchActive(Tag::KEY_ARRAY);

        *(data_.key_array) = std::move(key_array);
    }
    void KeyData::set_binary(const std::vector<uint8_t>& binary)
    {
        SwitchActive(Tag::BINARY);

        *(data_.binary) = std::move(binary);
    }
    void KeyData::set_string(const base::string16& string)
    {
        SwitchActive(Tag::STRING);

        *(data_.string) = std::move(string);
    }
    void KeyData::set_date(double date)
    {
        SwitchActive(Tag::DATE);

        data_.date = date;
    }
    void KeyData::set_number(double number)
    {
        SwitchActive(Tag::NUMBER);

        data_.number = number;
    }
    void KeyData::set_other(DatalessKeyType other)
    {
        SwitchActive(Tag::OTHER);

        data_.other = other;
    }

    void KeyData::SwitchActive(Tag new_active)
    {
        if (new_active == tag_) {
            return;
        }

        DestroyActive();
        SetActive(new_active);
    }

    void KeyData::SetActive(Tag new_active)
    {
        switch (new_active) {

        case Tag::KEY_ARRAY:

            data_.key_array = new std::vector<content::IndexedDBKey>();
            break;
        case Tag::BINARY:

            data_.binary = new std::vector<uint8_t>();
            break;
        case Tag::STRING:

            data_.string = new base::string16();
            break;
        case Tag::DATE:

            break;
        case Tag::NUMBER:

            break;
        case Tag::OTHER:

            break;
        }

        tag_ = new_active;
    }

    void KeyData::DestroyActive()
    {
        switch (tag_) {

        case Tag::KEY_ARRAY:

            delete data_.key_array;
            break;
        case Tag::BINARY:

            delete data_.binary;
            break;
        case Tag::STRING:

            delete data_.string;
            break;
        case Tag::DATE:

            break;
        case Tag::NUMBER:

            break;
        case Tag::OTHER:

            break;
        }
    } // static
    KeyPathDataPtr KeyPathData::New()
    {
        KeyPathDataPtr rv;
        mojo::internal::StructHelper<KeyPathData>::Initialize(&rv);
        return rv;
    }

    KeyPathData::KeyPathData()
    {
        // TODO(azani): Implement default values here when/if we support them.
        // TODO(azani): Set to UNKNOWN when unknown is implemented.
        SetActive(static_cast<Tag>(0));
    }

    KeyPathData::~KeyPathData()
    {
        DestroyActive();
    }

    void KeyPathData::set_string(const base::string16& string)
    {
        SwitchActive(Tag::STRING);

        *(data_.string) = std::move(string);
    }
    void KeyPathData::set_string_array(const std::vector<base::string16>& string_array)
    {
        SwitchActive(Tag::STRING_ARRAY);

        *(data_.string_array) = std::move(string_array);
    }

    void KeyPathData::SwitchActive(Tag new_active)
    {
        if (new_active == tag_) {
            return;
        }

        DestroyActive();
        SetActive(new_active);
    }

    void KeyPathData::SetActive(Tag new_active)
    {
        switch (new_active) {

        case Tag::STRING:

            data_.string = new base::string16();
            break;
        case Tag::STRING_ARRAY:

            data_.string_array = new std::vector<base::string16>();
            break;
        }

        tag_ = new_active;
    }

    void KeyPathData::DestroyActive()
    {
        switch (tag_) {

        case Tag::STRING:

            delete data_.string;
            break;
        case Tag::STRING_ARRAY:

            delete data_.string_array;
            break;
        }
    }
    const char Callbacks::Name_[] = "indexed_db::mojom::Callbacks";

    CallbacksProxy::CallbacksProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void CallbacksProxy::Error(
        int32_t in_code, const base::string16& in_message)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_Error_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_message, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_Error_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_Error_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->code = in_code;
        typename decltype(params->message)::BaseType* message_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_message, builder.buffer(), &message_ptr, &serialization_context);
        params->message.Set(message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message in Callbacks.Error request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::SuccessStringList(
        const std::vector<base::string16>& in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_SuccessStringList_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::mojo::common::mojom::String16DataView>>(
            in_value, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_SuccessStringList_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_SuccessStringList_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::mojo::common::mojom::String16DataView>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in Callbacks.SuccessStringList request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::Blocked(
        int64_t in_existing_version)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_Blocked_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_Blocked_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_Blocked_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->existing_version = in_existing_version;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::UpgradeNeeded(
        DatabaseAssociatedPtrInfo in_database, int64_t in_old_version, blink::WebIDBDataLoss in_data_loss, const std::string& in_data_loss_message, const content::IndexedDBDatabaseMetadata& in_db_metadata)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_UpgradeNeeded_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_data_loss_message, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::DatabaseMetadataDataView>(
            in_db_metadata, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_UpgradeNeeded_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_UpgradeNeeded_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::indexed_db::mojom::DatabaseAssociatedPtrInfoDataView>(
            in_database, &params->database, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->database),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid database in Callbacks.UpgradeNeeded request");
        params->old_version = in_old_version;
        mojo::internal::Serialize<::indexed_db::mojom::DataLoss>(
            in_data_loss, &params->data_loss);
        typename decltype(params->data_loss_message)::BaseType* data_loss_message_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_data_loss_message, builder.buffer(), &data_loss_message_ptr, &serialization_context);
        params->data_loss_message.Set(data_loss_message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->data_loss_message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null data_loss_message in Callbacks.UpgradeNeeded request");
        typename decltype(params->db_metadata)::BaseType* db_metadata_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::DatabaseMetadataDataView>(
            in_db_metadata, builder.buffer(), &db_metadata_ptr, &serialization_context);
        params->db_metadata.Set(db_metadata_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->db_metadata.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null db_metadata in Callbacks.UpgradeNeeded request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::SuccessDatabase(
        DatabaseAssociatedPtrInfo in_database, const content::IndexedDBDatabaseMetadata& in_metadata)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_SuccessDatabase_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::DatabaseMetadataDataView>(
            in_metadata, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_SuccessDatabase_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_SuccessDatabase_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::indexed_db::mojom::DatabaseAssociatedPtrInfoDataView>(
            in_database, &params->database, &serialization_context);
        typename decltype(params->metadata)::BaseType* metadata_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::DatabaseMetadataDataView>(
            in_metadata, builder.buffer(), &metadata_ptr, &serialization_context);
        params->metadata.Set(metadata_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->metadata.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null metadata in Callbacks.SuccessDatabase request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::SuccessCursor(
        CursorAssociatedPtrInfo in_cursor, const content::IndexedDBKey& in_key, const content::IndexedDBKey& in_primary_key, ValuePtr in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_SuccessCursor_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyDataView>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyDataView>(
            in_primary_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::ValueDataView>(
            in_value, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_SuccessCursor_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_SuccessCursor_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::indexed_db::mojom::CursorAssociatedPtrInfoDataView>(
            in_cursor, &params->cursor, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->cursor),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid cursor in Callbacks.SuccessCursor request");
        typename decltype(params->key)::BaseType* key_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyDataView>(
            in_key, builder.buffer(), &key_ptr, &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in Callbacks.SuccessCursor request");
        typename decltype(params->primary_key)::BaseType* primary_key_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyDataView>(
            in_primary_key, builder.buffer(), &primary_key_ptr, &serialization_context);
        params->primary_key.Set(primary_key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->primary_key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null primary_key in Callbacks.SuccessCursor request");
        typename decltype(params->value)::BaseType* value_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::ValueDataView>(
            in_value, builder.buffer(), &value_ptr, &serialization_context);
        params->value.Set(value_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::SuccessValue(
        ReturnValuePtr in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_SuccessValue_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::ReturnValueDataView>(
            in_value, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_SuccessValue_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_SuccessValue_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->value)::BaseType* value_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::ReturnValueDataView>(
            in_value, builder.buffer(), &value_ptr, &serialization_context);
        params->value.Set(value_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::SuccessCursorContinue(
        const content::IndexedDBKey& in_key, const content::IndexedDBKey& in_primary_key, ValuePtr in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_SuccessCursorContinue_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyDataView>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyDataView>(
            in_primary_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::ValueDataView>(
            in_value, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_SuccessCursorContinue_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_SuccessCursorContinue_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyDataView>(
            in_key, builder.buffer(), &key_ptr, &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in Callbacks.SuccessCursorContinue request");
        typename decltype(params->primary_key)::BaseType* primary_key_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyDataView>(
            in_primary_key, builder.buffer(), &primary_key_ptr, &serialization_context);
        params->primary_key.Set(primary_key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->primary_key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null primary_key in Callbacks.SuccessCursorContinue request");
        typename decltype(params->value)::BaseType* value_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::ValueDataView>(
            in_value, builder.buffer(), &value_ptr, &serialization_context);
        params->value.Set(value_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::SuccessCursorPrefetch(
        const std::vector<content::IndexedDBKey>& in_keys, const std::vector<content::IndexedDBKey>& in_primary_keys, std::vector<ValuePtr> in_values)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_SuccessCursorPrefetch_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::indexed_db::mojom::KeyDataView>>(
            in_keys, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::indexed_db::mojom::KeyDataView>>(
            in_primary_keys, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::indexed_db::mojom::ValueDataView>>(
            in_values, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_SuccessCursorPrefetch_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_SuccessCursorPrefetch_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->keys)::BaseType* keys_ptr;
        const mojo::internal::ContainerValidateParams keys_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::indexed_db::mojom::KeyDataView>>(
            in_keys, builder.buffer(), &keys_ptr, &keys_validate_params,
            &serialization_context);
        params->keys.Set(keys_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->keys.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null keys in Callbacks.SuccessCursorPrefetch request");
        typename decltype(params->primary_keys)::BaseType* primary_keys_ptr;
        const mojo::internal::ContainerValidateParams primary_keys_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::indexed_db::mojom::KeyDataView>>(
            in_primary_keys, builder.buffer(), &primary_keys_ptr, &primary_keys_validate_params,
            &serialization_context);
        params->primary_keys.Set(primary_keys_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->primary_keys.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null primary_keys in Callbacks.SuccessCursorPrefetch request");
        typename decltype(params->values)::BaseType* values_ptr;
        const mojo::internal::ContainerValidateParams values_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::indexed_db::mojom::ValueDataView>>(
            in_values, builder.buffer(), &values_ptr, &values_validate_params,
            &serialization_context);
        params->values.Set(values_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->values.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null values in Callbacks.SuccessCursorPrefetch request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::SuccessArray(
        std::vector<ReturnValuePtr> in_values)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_SuccessArray_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::indexed_db::mojom::ReturnValueDataView>>(
            in_values, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_SuccessArray_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_SuccessArray_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->values)::BaseType* values_ptr;
        const mojo::internal::ContainerValidateParams values_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::indexed_db::mojom::ReturnValueDataView>>(
            in_values, builder.buffer(), &values_ptr, &values_validate_params,
            &serialization_context);
        params->values.Set(values_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->values.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null values in Callbacks.SuccessArray request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::SuccessKey(
        const content::IndexedDBKey& in_key)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_SuccessKey_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyDataView>(
            in_key, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_SuccessKey_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_SuccessKey_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyDataView>(
            in_key, builder.buffer(), &key_ptr, &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in Callbacks.SuccessKey request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::SuccessInteger(
        int64_t in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_SuccessInteger_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_SuccessInteger_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_SuccessInteger_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->value = in_value;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CallbacksProxy::Success()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Callbacks_Success_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kCallbacks_Success_Name, size);

        auto params = ::indexed_db::mojom::internal::Callbacks_Success_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool CallbacksStubDispatch::Accept(
        Callbacks* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kCallbacks_Error_Name: {
            internal::Callbacks_Error_Params_Data* params = reinterpret_cast<internal::Callbacks_Error_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_code {};
            base::string16 p_message {};
            Callbacks_Error_ParamsDataView input_data_view(params,
                context);

            p_code = input_data_view.code();
            if (!input_data_view.ReadMessage(&p_message))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::Error deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::Error");
            mojo::internal::MessageDispatchContext context(message);
            impl->Error(
                std::move(p_code),
                std::move(p_message));
            return true;
        }
        case internal::kCallbacks_SuccessStringList_Name: {
            internal::Callbacks_SuccessStringList_Params_Data* params = reinterpret_cast<internal::Callbacks_SuccessStringList_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<base::string16> p_value {};
            Callbacks_SuccessStringList_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::SuccessStringList deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::SuccessStringList");
            mojo::internal::MessageDispatchContext context(message);
            impl->SuccessStringList(
                std::move(p_value));
            return true;
        }
        case internal::kCallbacks_Blocked_Name: {
            internal::Callbacks_Blocked_Params_Data* params = reinterpret_cast<internal::Callbacks_Blocked_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_existing_version {};
            Callbacks_Blocked_ParamsDataView input_data_view(params,
                context);

            p_existing_version = input_data_view.existing_version();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::Blocked deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::Blocked");
            mojo::internal::MessageDispatchContext context(message);
            impl->Blocked(
                std::move(p_existing_version));
            return true;
        }
        case internal::kCallbacks_UpgradeNeeded_Name: {
            internal::Callbacks_UpgradeNeeded_Params_Data* params = reinterpret_cast<internal::Callbacks_UpgradeNeeded_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DatabaseAssociatedPtrInfo p_database {};
            int64_t p_old_version {};
            blink::WebIDBDataLoss p_data_loss {};
            std::string p_data_loss_message {};
            content::IndexedDBDatabaseMetadata p_db_metadata {};
            Callbacks_UpgradeNeeded_ParamsDataView input_data_view(params,
                context);

            p_database = input_data_view.TakeDatabase<decltype(p_database)>();
            p_old_version = input_data_view.old_version();
            if (!input_data_view.ReadDataLoss(&p_data_loss))
                success = false;
            if (!input_data_view.ReadDataLossMessage(&p_data_loss_message))
                success = false;
            if (!input_data_view.ReadDbMetadata(&p_db_metadata))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::UpgradeNeeded deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::UpgradeNeeded");
            mojo::internal::MessageDispatchContext context(message);
            impl->UpgradeNeeded(
                std::move(p_database),
                std::move(p_old_version),
                std::move(p_data_loss),
                std::move(p_data_loss_message),
                std::move(p_db_metadata));
            return true;
        }
        case internal::kCallbacks_SuccessDatabase_Name: {
            internal::Callbacks_SuccessDatabase_Params_Data* params = reinterpret_cast<internal::Callbacks_SuccessDatabase_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DatabaseAssociatedPtrInfo p_database {};
            content::IndexedDBDatabaseMetadata p_metadata {};
            Callbacks_SuccessDatabase_ParamsDataView input_data_view(params,
                context);

            p_database = input_data_view.TakeDatabase<decltype(p_database)>();
            if (!input_data_view.ReadMetadata(&p_metadata))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::SuccessDatabase deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::SuccessDatabase");
            mojo::internal::MessageDispatchContext context(message);
            impl->SuccessDatabase(
                std::move(p_database),
                std::move(p_metadata));
            return true;
        }
        case internal::kCallbacks_SuccessCursor_Name: {
            internal::Callbacks_SuccessCursor_Params_Data* params = reinterpret_cast<internal::Callbacks_SuccessCursor_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            CursorAssociatedPtrInfo p_cursor {};
            content::IndexedDBKey p_key {};
            content::IndexedDBKey p_primary_key {};
            ValuePtr p_value {};
            Callbacks_SuccessCursor_ParamsDataView input_data_view(params,
                context);

            p_cursor = input_data_view.TakeCursor<decltype(p_cursor)>();
            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadPrimaryKey(&p_primary_key))
                success = false;
            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::SuccessCursor deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::SuccessCursor");
            mojo::internal::MessageDispatchContext context(message);
            impl->SuccessCursor(
                std::move(p_cursor),
                std::move(p_key),
                std::move(p_primary_key),
                std::move(p_value));
            return true;
        }
        case internal::kCallbacks_SuccessValue_Name: {
            internal::Callbacks_SuccessValue_Params_Data* params = reinterpret_cast<internal::Callbacks_SuccessValue_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ReturnValuePtr p_value {};
            Callbacks_SuccessValue_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::SuccessValue deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::SuccessValue");
            mojo::internal::MessageDispatchContext context(message);
            impl->SuccessValue(
                std::move(p_value));
            return true;
        }
        case internal::kCallbacks_SuccessCursorContinue_Name: {
            internal::Callbacks_SuccessCursorContinue_Params_Data* params = reinterpret_cast<internal::Callbacks_SuccessCursorContinue_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            content::IndexedDBKey p_key {};
            content::IndexedDBKey p_primary_key {};
            ValuePtr p_value {};
            Callbacks_SuccessCursorContinue_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadPrimaryKey(&p_primary_key))
                success = false;
            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::SuccessCursorContinue deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::SuccessCursorContinue");
            mojo::internal::MessageDispatchContext context(message);
            impl->SuccessCursorContinue(
                std::move(p_key),
                std::move(p_primary_key),
                std::move(p_value));
            return true;
        }
        case internal::kCallbacks_SuccessCursorPrefetch_Name: {
            internal::Callbacks_SuccessCursorPrefetch_Params_Data* params = reinterpret_cast<internal::Callbacks_SuccessCursorPrefetch_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<content::IndexedDBKey> p_keys {};
            std::vector<content::IndexedDBKey> p_primary_keys {};
            std::vector<ValuePtr> p_values {};
            Callbacks_SuccessCursorPrefetch_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKeys(&p_keys))
                success = false;
            if (!input_data_view.ReadPrimaryKeys(&p_primary_keys))
                success = false;
            if (!input_data_view.ReadValues(&p_values))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::SuccessCursorPrefetch deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::SuccessCursorPrefetch");
            mojo::internal::MessageDispatchContext context(message);
            impl->SuccessCursorPrefetch(
                std::move(p_keys),
                std::move(p_primary_keys),
                std::move(p_values));
            return true;
        }
        case internal::kCallbacks_SuccessArray_Name: {
            internal::Callbacks_SuccessArray_Params_Data* params = reinterpret_cast<internal::Callbacks_SuccessArray_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<ReturnValuePtr> p_values {};
            Callbacks_SuccessArray_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadValues(&p_values))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::SuccessArray deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::SuccessArray");
            mojo::internal::MessageDispatchContext context(message);
            impl->SuccessArray(
                std::move(p_values));
            return true;
        }
        case internal::kCallbacks_SuccessKey_Name: {
            internal::Callbacks_SuccessKey_Params_Data* params = reinterpret_cast<internal::Callbacks_SuccessKey_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            content::IndexedDBKey p_key {};
            Callbacks_SuccessKey_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::SuccessKey deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::SuccessKey");
            mojo::internal::MessageDispatchContext context(message);
            impl->SuccessKey(
                std::move(p_key));
            return true;
        }
        case internal::kCallbacks_SuccessInteger_Name: {
            internal::Callbacks_SuccessInteger_Params_Data* params = reinterpret_cast<internal::Callbacks_SuccessInteger_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_value {};
            Callbacks_SuccessInteger_ParamsDataView input_data_view(params,
                context);

            p_value = input_data_view.value();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::SuccessInteger deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::SuccessInteger");
            mojo::internal::MessageDispatchContext context(message);
            impl->SuccessInteger(
                std::move(p_value));
            return true;
        }
        case internal::kCallbacks_Success_Name: {
            internal::Callbacks_Success_Params_Data* params = reinterpret_cast<internal::Callbacks_Success_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Callbacks_Success_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Callbacks::Success deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Callbacks::Success");
            mojo::internal::MessageDispatchContext context(message);
            impl->Success();
            return true;
        }
        }
        return false;
    }

    // static
    bool CallbacksStubDispatch::AcceptWithResponder(
        Callbacks* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kCallbacks_Error_Name: {
            break;
        }
        case internal::kCallbacks_SuccessStringList_Name: {
            break;
        }
        case internal::kCallbacks_Blocked_Name: {
            break;
        }
        case internal::kCallbacks_UpgradeNeeded_Name: {
            break;
        }
        case internal::kCallbacks_SuccessDatabase_Name: {
            break;
        }
        case internal::kCallbacks_SuccessCursor_Name: {
            break;
        }
        case internal::kCallbacks_SuccessValue_Name: {
            break;
        }
        case internal::kCallbacks_SuccessCursorContinue_Name: {
            break;
        }
        case internal::kCallbacks_SuccessCursorPrefetch_Name: {
            break;
        }
        case internal::kCallbacks_SuccessArray_Name: {
            break;
        }
        case internal::kCallbacks_SuccessKey_Name: {
            break;
        }
        case internal::kCallbacks_SuccessInteger_Name: {
            break;
        }
        case internal::kCallbacks_Success_Name: {
            break;
        }
        }
        return false;
    }

    bool CallbacksRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Callbacks RequestValidator");

        switch (message->header()->name) {
        case internal::kCallbacks_Error_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_Error_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_SuccessStringList_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_SuccessStringList_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_Blocked_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_Blocked_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_UpgradeNeeded_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_UpgradeNeeded_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_SuccessDatabase_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_SuccessDatabase_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_SuccessCursor_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_SuccessCursor_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_SuccessValue_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_SuccessValue_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_SuccessCursorContinue_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_SuccessCursorContinue_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_SuccessCursorPrefetch_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_SuccessCursorPrefetch_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_SuccessArray_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_SuccessArray_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_SuccessKey_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_SuccessKey_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_SuccessInteger_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_SuccessInteger_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCallbacks_Success_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Callbacks_Success_Params_Data>(
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

    const char DatabaseCallbacks::Name_[] = "indexed_db::mojom::DatabaseCallbacks";

    DatabaseCallbacksProxy::DatabaseCallbacksProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DatabaseCallbacksProxy::ForcedClose()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::DatabaseCallbacks_ForcedClose_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabaseCallbacks_ForcedClose_Name, size);

        auto params = ::indexed_db::mojom::internal::DatabaseCallbacks_ForcedClose_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseCallbacksProxy::VersionChange(
        int64_t in_old_version, int64_t in_new_version)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::DatabaseCallbacks_VersionChange_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabaseCallbacks_VersionChange_Name, size);

        auto params = ::indexed_db::mojom::internal::DatabaseCallbacks_VersionChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->old_version = in_old_version;
        params->new_version = in_new_version;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseCallbacksProxy::Abort(
        int64_t in_transaction_id, int32_t in_code, const base::string16& in_message)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::DatabaseCallbacks_Abort_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_message, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabaseCallbacks_Abort_Name, size);

        auto params = ::indexed_db::mojom::internal::DatabaseCallbacks_Abort_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->code = in_code;
        typename decltype(params->message)::BaseType* message_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_message, builder.buffer(), &message_ptr, &serialization_context);
        params->message.Set(message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message in DatabaseCallbacks.Abort request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseCallbacksProxy::Complete(
        int64_t in_transaction_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::DatabaseCallbacks_Complete_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabaseCallbacks_Complete_Name, size);

        auto params = ::indexed_db::mojom::internal::DatabaseCallbacks_Complete_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseCallbacksProxy::Changes(
        ObserverChangesPtr in_changes)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::DatabaseCallbacks_Changes_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::ObserverChangesDataView>(
            in_changes, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabaseCallbacks_Changes_Name, size);

        auto params = ::indexed_db::mojom::internal::DatabaseCallbacks_Changes_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->changes)::BaseType* changes_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::ObserverChangesDataView>(
            in_changes, builder.buffer(), &changes_ptr, &serialization_context);
        params->changes.Set(changes_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->changes.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null changes in DatabaseCallbacks.Changes request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DatabaseCallbacksStubDispatch::Accept(
        DatabaseCallbacks* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDatabaseCallbacks_ForcedClose_Name: {
            internal::DatabaseCallbacks_ForcedClose_Params_Data* params = reinterpret_cast<internal::DatabaseCallbacks_ForcedClose_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DatabaseCallbacks_ForcedClose_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DatabaseCallbacks::ForcedClose deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DatabaseCallbacks::ForcedClose");
            mojo::internal::MessageDispatchContext context(message);
            impl->ForcedClose();
            return true;
        }
        case internal::kDatabaseCallbacks_VersionChange_Name: {
            internal::DatabaseCallbacks_VersionChange_Params_Data* params = reinterpret_cast<internal::DatabaseCallbacks_VersionChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_old_version {};
            int64_t p_new_version {};
            DatabaseCallbacks_VersionChange_ParamsDataView input_data_view(params,
                context);

            p_old_version = input_data_view.old_version();
            p_new_version = input_data_view.new_version();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DatabaseCallbacks::VersionChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DatabaseCallbacks::VersionChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->VersionChange(
                std::move(p_old_version),
                std::move(p_new_version));
            return true;
        }
        case internal::kDatabaseCallbacks_Abort_Name: {
            internal::DatabaseCallbacks_Abort_Params_Data* params = reinterpret_cast<internal::DatabaseCallbacks_Abort_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int32_t p_code {};
            base::string16 p_message {};
            DatabaseCallbacks_Abort_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_code = input_data_view.code();
            if (!input_data_view.ReadMessage(&p_message))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DatabaseCallbacks::Abort deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DatabaseCallbacks::Abort");
            mojo::internal::MessageDispatchContext context(message);
            impl->Abort(
                std::move(p_transaction_id),
                std::move(p_code),
                std::move(p_message));
            return true;
        }
        case internal::kDatabaseCallbacks_Complete_Name: {
            internal::DatabaseCallbacks_Complete_Params_Data* params = reinterpret_cast<internal::DatabaseCallbacks_Complete_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            DatabaseCallbacks_Complete_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DatabaseCallbacks::Complete deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DatabaseCallbacks::Complete");
            mojo::internal::MessageDispatchContext context(message);
            impl->Complete(
                std::move(p_transaction_id));
            return true;
        }
        case internal::kDatabaseCallbacks_Changes_Name: {
            internal::DatabaseCallbacks_Changes_Params_Data* params = reinterpret_cast<internal::DatabaseCallbacks_Changes_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ObserverChangesPtr p_changes {};
            DatabaseCallbacks_Changes_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadChanges(&p_changes))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "DatabaseCallbacks::Changes deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "DatabaseCallbacks::Changes");
            mojo::internal::MessageDispatchContext context(message);
            impl->Changes(
                std::move(p_changes));
            return true;
        }
        }
        return false;
    }

    // static
    bool DatabaseCallbacksStubDispatch::AcceptWithResponder(
        DatabaseCallbacks* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDatabaseCallbacks_ForcedClose_Name: {
            break;
        }
        case internal::kDatabaseCallbacks_VersionChange_Name: {
            break;
        }
        case internal::kDatabaseCallbacks_Abort_Name: {
            break;
        }
        case internal::kDatabaseCallbacks_Complete_Name: {
            break;
        }
        case internal::kDatabaseCallbacks_Changes_Name: {
            break;
        }
        }
        return false;
    }

    bool DatabaseCallbacksRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "DatabaseCallbacks RequestValidator");

        switch (message->header()->name) {
        case internal::kDatabaseCallbacks_ForcedClose_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DatabaseCallbacks_ForcedClose_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabaseCallbacks_VersionChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DatabaseCallbacks_VersionChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabaseCallbacks_Abort_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DatabaseCallbacks_Abort_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabaseCallbacks_Complete_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DatabaseCallbacks_Complete_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabaseCallbacks_Changes_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::DatabaseCallbacks_Changes_Params_Data>(
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

    const char Cursor::Name_[] = "indexed_db::mojom::Cursor";

    CursorProxy::CursorProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void CursorProxy::Advance(
        uint32_t in_count, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Cursor_Advance_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kCursor_Advance_Name, size);

        auto params = ::indexed_db::mojom::internal::Cursor_Advance_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->count = in_count;
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Cursor.Advance request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CursorProxy::Continue(
        const content::IndexedDBKey& in_key, const content::IndexedDBKey& in_primary_key, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Cursor_Continue_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyDataView>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyDataView>(
            in_primary_key, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCursor_Continue_Name, size);

        auto params = ::indexed_db::mojom::internal::Cursor_Continue_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyDataView>(
            in_key, builder.buffer(), &key_ptr, &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in Cursor.Continue request");
        typename decltype(params->primary_key)::BaseType* primary_key_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyDataView>(
            in_primary_key, builder.buffer(), &primary_key_ptr, &serialization_context);
        params->primary_key.Set(primary_key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->primary_key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null primary_key in Cursor.Continue request");
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Cursor.Continue request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CursorProxy::Prefetch(
        int32_t in_count, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Cursor_Prefetch_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kCursor_Prefetch_Name, size);

        auto params = ::indexed_db::mojom::internal::Cursor_Prefetch_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->count = in_count;
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Cursor.Prefetch request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void CursorProxy::PrefetchReset(
        int32_t in_used_prefetches, int32_t in_unused_prefetches, const std::vector<std::string>& in_unused_blob_uuids)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Cursor_PrefetchReset_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_unused_blob_uuids, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kCursor_PrefetchReset_Name, size);

        auto params = ::indexed_db::mojom::internal::Cursor_PrefetchReset_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->used_prefetches = in_used_prefetches;
        params->unused_prefetches = in_unused_prefetches;
        typename decltype(params->unused_blob_uuids)::BaseType* unused_blob_uuids_ptr;
        const mojo::internal::ContainerValidateParams unused_blob_uuids_validate_params(
            0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
        mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_unused_blob_uuids, builder.buffer(), &unused_blob_uuids_ptr, &unused_blob_uuids_validate_params,
            &serialization_context);
        params->unused_blob_uuids.Set(unused_blob_uuids_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->unused_blob_uuids.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null unused_blob_uuids in Cursor.PrefetchReset request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool CursorStubDispatch::Accept(
        Cursor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kCursor_Advance_Name: {
            internal::Cursor_Advance_Params_Data* params = reinterpret_cast<internal::Cursor_Advance_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            uint32_t p_count {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Cursor_Advance_ParamsDataView input_data_view(params,
                context);

            p_count = input_data_view.count();
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Cursor::Advance deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Cursor::Advance");
            mojo::internal::MessageDispatchContext context(message);
            impl->Advance(
                std::move(p_count),
                std::move(p_callbacks));
            return true;
        }
        case internal::kCursor_Continue_Name: {
            internal::Cursor_Continue_Params_Data* params = reinterpret_cast<internal::Cursor_Continue_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            content::IndexedDBKey p_key {};
            content::IndexedDBKey p_primary_key {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Cursor_Continue_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadPrimaryKey(&p_primary_key))
                success = false;
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Cursor::Continue deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Cursor::Continue");
            mojo::internal::MessageDispatchContext context(message);
            impl->Continue(
                std::move(p_key),
                std::move(p_primary_key),
                std::move(p_callbacks));
            return true;
        }
        case internal::kCursor_Prefetch_Name: {
            internal::Cursor_Prefetch_Params_Data* params = reinterpret_cast<internal::Cursor_Prefetch_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_count {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Cursor_Prefetch_ParamsDataView input_data_view(params,
                context);

            p_count = input_data_view.count();
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Cursor::Prefetch deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Cursor::Prefetch");
            mojo::internal::MessageDispatchContext context(message);
            impl->Prefetch(
                std::move(p_count),
                std::move(p_callbacks));
            return true;
        }
        case internal::kCursor_PrefetchReset_Name: {
            internal::Cursor_PrefetchReset_Params_Data* params = reinterpret_cast<internal::Cursor_PrefetchReset_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_used_prefetches {};
            int32_t p_unused_prefetches {};
            std::vector<std::string> p_unused_blob_uuids {};
            Cursor_PrefetchReset_ParamsDataView input_data_view(params,
                context);

            p_used_prefetches = input_data_view.used_prefetches();
            p_unused_prefetches = input_data_view.unused_prefetches();
            if (!input_data_view.ReadUnusedBlobUuids(&p_unused_blob_uuids))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Cursor::PrefetchReset deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Cursor::PrefetchReset");
            mojo::internal::MessageDispatchContext context(message);
            impl->PrefetchReset(
                std::move(p_used_prefetches),
                std::move(p_unused_prefetches),
                std::move(p_unused_blob_uuids));
            return true;
        }
        }
        return false;
    }

    // static
    bool CursorStubDispatch::AcceptWithResponder(
        Cursor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kCursor_Advance_Name: {
            break;
        }
        case internal::kCursor_Continue_Name: {
            break;
        }
        case internal::kCursor_Prefetch_Name: {
            break;
        }
        case internal::kCursor_PrefetchReset_Name: {
            break;
        }
        }
        return false;
    }

    bool CursorRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Cursor RequestValidator");

        switch (message->header()->name) {
        case internal::kCursor_Advance_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Cursor_Advance_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCursor_Continue_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Cursor_Continue_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCursor_Prefetch_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Cursor_Prefetch_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCursor_PrefetchReset_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Cursor_PrefetchReset_Params_Data>(
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

    const char Database::Name_[] = "indexed_db::mojom::Database";

    DatabaseProxy::DatabaseProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void DatabaseProxy::CreateObjectStore(
        int64_t in_transaction_id, int64_t in_object_store_id, const base::string16& in_name, const content::IndexedDBKeyPath& in_key_path, bool in_auto_increment)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_CreateObjectStore_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_name, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyPathDataView>(
            in_key_path, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_CreateObjectStore_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_CreateObjectStore_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        typename decltype(params->name)::BaseType* name_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_name, builder.buffer(), &name_ptr, &serialization_context);
        params->name.Set(name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null name in Database.CreateObjectStore request");
        typename decltype(params->key_path)::BaseType* key_path_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyPathDataView>(
            in_key_path, builder.buffer(), &key_path_ptr, &serialization_context);
        params->key_path.Set(key_path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_path in Database.CreateObjectStore request");
        params->auto_increment = in_auto_increment;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::DeleteObjectStore(
        int64_t in_transaction_id, int64_t in_object_store_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_DeleteObjectStore_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabase_DeleteObjectStore_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_DeleteObjectStore_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::RenameObjectStore(
        int64_t in_transaction_id, int64_t in_object_store_id, const base::string16& in_new_name)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_RenameObjectStore_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_new_name, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_RenameObjectStore_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_RenameObjectStore_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        typename decltype(params->new_name)::BaseType* new_name_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_new_name, builder.buffer(), &new_name_ptr, &serialization_context);
        params->new_name.Set(new_name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->new_name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null new_name in Database.RenameObjectStore request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::CreateTransaction(
        int64_t in_transaction_id, const std::vector<int64_t>& in_object_store_ids, blink::WebIDBTransactionMode in_mode)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_CreateTransaction_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<int64_t>>(
            in_object_store_ids, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_CreateTransaction_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_CreateTransaction_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        typename decltype(params->object_store_ids)::BaseType* object_store_ids_ptr;
        const mojo::internal::ContainerValidateParams object_store_ids_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<int64_t>>(
            in_object_store_ids, builder.buffer(), &object_store_ids_ptr, &object_store_ids_validate_params,
            &serialization_context);
        params->object_store_ids.Set(object_store_ids_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->object_store_ids.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null object_store_ids in Database.CreateTransaction request");
        mojo::internal::Serialize<::indexed_db::mojom::TransactionMode>(
            in_mode, &params->mode);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::Close()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_Close_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabase_Close_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_Close_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::VersionChangeIgnored()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_VersionChangeIgnored_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabase_VersionChangeIgnored_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_VersionChangeIgnored_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::AddObserver(
        int64_t in_transaction_id, int32_t in_observer_id, bool in_include_transaction, bool in_no_records, bool in_values, uint16_t in_operation_types)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_AddObserver_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabase_AddObserver_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_AddObserver_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->observer_id = in_observer_id;
        params->include_transaction = in_include_transaction;
        params->no_records = in_no_records;
        params->values = in_values;
        params->operation_types = in_operation_types;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::RemoveObservers(
        const std::vector<int32_t>& in_observers)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_RemoveObservers_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<int32_t>>(
            in_observers, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_RemoveObservers_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_RemoveObservers_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->observers)::BaseType* observers_ptr;
        const mojo::internal::ContainerValidateParams observers_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<int32_t>>(
            in_observers, builder.buffer(), &observers_ptr, &observers_validate_params,
            &serialization_context);
        params->observers.Set(observers_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->observers.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null observers in Database.RemoveObservers request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::Get(
        int64_t in_transaction_id, int64_t in_object_store_id, int64_t in_index_id, const content::IndexedDBKeyRange& in_key_range, bool in_key_only, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_Get_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_Get_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_Get_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        params->index_id = in_index_id;
        typename decltype(params->key_range)::BaseType* key_range_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, builder.buffer(), &key_range_ptr, &serialization_context);
        params->key_range.Set(key_range_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_range.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_range in Database.Get request");
        params->key_only = in_key_only;
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Database.Get request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::GetAll(
        int64_t in_transaction_id, int64_t in_object_store_id, int64_t in_index_id, const content::IndexedDBKeyRange& in_key_range, bool in_key_only, int64_t in_max_count, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_GetAll_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_GetAll_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_GetAll_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        params->index_id = in_index_id;
        typename decltype(params->key_range)::BaseType* key_range_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, builder.buffer(), &key_range_ptr, &serialization_context);
        params->key_range.Set(key_range_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_range.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_range in Database.GetAll request");
        params->key_only = in_key_only;
        params->max_count = in_max_count;
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Database.GetAll request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::Put(
        int64_t in_transaction_id, int64_t in_object_store_id, ValuePtr in_value, const content::IndexedDBKey& in_key, blink::WebIDBPutMode in_mode, const std::vector<content::IndexedDBIndexKeys>& in_index_keys, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_Put_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::ValueDataView>(
            in_value, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyDataView>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::indexed_db::mojom::IndexKeysDataView>>(
            in_index_keys, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_Put_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_Put_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        typename decltype(params->value)::BaseType* value_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::ValueDataView>(
            in_value, builder.buffer(), &value_ptr, &serialization_context);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in Database.Put request");
        typename decltype(params->key)::BaseType* key_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyDataView>(
            in_key, builder.buffer(), &key_ptr, &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in Database.Put request");
        mojo::internal::Serialize<::indexed_db::mojom::PutMode>(
            in_mode, &params->mode);
        typename decltype(params->index_keys)::BaseType* index_keys_ptr;
        const mojo::internal::ContainerValidateParams index_keys_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::indexed_db::mojom::IndexKeysDataView>>(
            in_index_keys, builder.buffer(), &index_keys_ptr, &index_keys_validate_params,
            &serialization_context);
        params->index_keys.Set(index_keys_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->index_keys.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null index_keys in Database.Put request");
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Database.Put request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::SetIndexKeys(
        int64_t in_transaction_id, int64_t in_object_store_id, const content::IndexedDBKey& in_primary_key, const std::vector<content::IndexedDBIndexKeys>& in_index_keys)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_SetIndexKeys_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyDataView>(
            in_primary_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::indexed_db::mojom::IndexKeysDataView>>(
            in_index_keys, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_SetIndexKeys_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_SetIndexKeys_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        typename decltype(params->primary_key)::BaseType* primary_key_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyDataView>(
            in_primary_key, builder.buffer(), &primary_key_ptr, &serialization_context);
        params->primary_key.Set(primary_key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->primary_key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null primary_key in Database.SetIndexKeys request");
        typename decltype(params->index_keys)::BaseType* index_keys_ptr;
        const mojo::internal::ContainerValidateParams index_keys_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::indexed_db::mojom::IndexKeysDataView>>(
            in_index_keys, builder.buffer(), &index_keys_ptr, &index_keys_validate_params,
            &serialization_context);
        params->index_keys.Set(index_keys_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->index_keys.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null index_keys in Database.SetIndexKeys request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::SetIndexesReady(
        int64_t in_transaction_id, int64_t in_object_store_id, const std::vector<int64_t>& in_index_ids)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_SetIndexesReady_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<int64_t>>(
            in_index_ids, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_SetIndexesReady_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_SetIndexesReady_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        typename decltype(params->index_ids)::BaseType* index_ids_ptr;
        const mojo::internal::ContainerValidateParams index_ids_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<int64_t>>(
            in_index_ids, builder.buffer(), &index_ids_ptr, &index_ids_validate_params,
            &serialization_context);
        params->index_ids.Set(index_ids_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->index_ids.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null index_ids in Database.SetIndexesReady request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::OpenCursor(
        int64_t in_transaction_id, int64_t in_object_store_id, int64_t in_index_id, const content::IndexedDBKeyRange& in_key_range, blink::WebIDBCursorDirection in_direction, bool in_key_only, blink::WebIDBTaskType in_task_type, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_OpenCursor_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_OpenCursor_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_OpenCursor_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        params->index_id = in_index_id;
        typename decltype(params->key_range)::BaseType* key_range_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, builder.buffer(), &key_range_ptr, &serialization_context);
        params->key_range.Set(key_range_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_range.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_range in Database.OpenCursor request");
        mojo::internal::Serialize<::indexed_db::mojom::CursorDirection>(
            in_direction, &params->direction);
        params->key_only = in_key_only;
        mojo::internal::Serialize<::indexed_db::mojom::TaskType>(
            in_task_type, &params->task_type);
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Database.OpenCursor request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::Count(
        int64_t in_transaction_id, int64_t in_object_store_id, int64_t in_index_id, const content::IndexedDBKeyRange& in_key_range, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_Count_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_Count_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_Count_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        params->index_id = in_index_id;
        typename decltype(params->key_range)::BaseType* key_range_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, builder.buffer(), &key_range_ptr, &serialization_context);
        params->key_range.Set(key_range_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_range.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_range in Database.Count request");
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Database.Count request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::DeleteRange(
        int64_t in_transaction_id, int64_t in_object_store_id, const content::IndexedDBKeyRange& in_key_range, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_DeleteRange_Params_Data);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_DeleteRange_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_DeleteRange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        typename decltype(params->key_range)::BaseType* key_range_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyRangeDataView>(
            in_key_range, builder.buffer(), &key_range_ptr, &serialization_context);
        params->key_range.Set(key_range_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_range.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_range in Database.DeleteRange request");
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Database.DeleteRange request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::Clear(
        int64_t in_transaction_id, int64_t in_object_store_id, CallbacksAssociatedPtrInfo in_callbacks)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_Clear_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabase_Clear_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_Clear_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Database.Clear request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::CreateIndex(
        int64_t in_transaction_id, int64_t in_object_store_id, int64_t in_index_id, const base::string16& in_name, const content::IndexedDBKeyPath& in_key_path, bool in_unique, bool in_multi_entry)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_CreateIndex_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_name, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::indexed_db::mojom::KeyPathDataView>(
            in_key_path, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_CreateIndex_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_CreateIndex_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        params->index_id = in_index_id;
        typename decltype(params->name)::BaseType* name_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_name, builder.buffer(), &name_ptr, &serialization_context);
        params->name.Set(name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null name in Database.CreateIndex request");
        typename decltype(params->key_path)::BaseType* key_path_ptr;
        mojo::internal::Serialize<::indexed_db::mojom::KeyPathDataView>(
            in_key_path, builder.buffer(), &key_path_ptr, &serialization_context);
        params->key_path.Set(key_path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_path in Database.CreateIndex request");
        params->unique = in_unique;
        params->multi_entry = in_multi_entry;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::DeleteIndex(
        int64_t in_transaction_id, int64_t in_object_store_id, int64_t in_index_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_DeleteIndex_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabase_DeleteIndex_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_DeleteIndex_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        params->index_id = in_index_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::RenameIndex(
        int64_t in_transaction_id, int64_t in_object_store_id, int64_t in_index_id, const base::string16& in_new_name)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_RenameIndex_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_new_name, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_RenameIndex_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_RenameIndex_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        params->object_store_id = in_object_store_id;
        params->index_id = in_index_id;
        typename decltype(params->new_name)::BaseType* new_name_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_new_name, builder.buffer(), &new_name_ptr, &serialization_context);
        params->new_name.Set(new_name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->new_name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null new_name in Database.RenameIndex request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::Abort(
        int64_t in_transaction_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_Abort_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabase_Abort_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_Abort_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::Commit(
        int64_t in_transaction_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_Commit_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDatabase_Commit_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_Commit_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->transaction_id = in_transaction_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void DatabaseProxy::AckReceivedBlobs(
        const std::vector<std::string>& in_uuids)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Database_AckReceivedBlobs_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_uuids, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kDatabase_AckReceivedBlobs_Name, size);

        auto params = ::indexed_db::mojom::internal::Database_AckReceivedBlobs_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->uuids)::BaseType* uuids_ptr;
        const mojo::internal::ContainerValidateParams uuids_validate_params(
            0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
        mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_uuids, builder.buffer(), &uuids_ptr, &uuids_validate_params,
            &serialization_context);
        params->uuids.Set(uuids_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->uuids.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null uuids in Database.AckReceivedBlobs request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool DatabaseStubDispatch::Accept(
        Database* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDatabase_CreateObjectStore_Name: {
            internal::Database_CreateObjectStore_Params_Data* params = reinterpret_cast<internal::Database_CreateObjectStore_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            base::string16 p_name {};
            content::IndexedDBKeyPath p_key_path {};
            bool p_auto_increment {};
            Database_CreateObjectStore_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            if (!input_data_view.ReadName(&p_name))
                success = false;
            if (!input_data_view.ReadKeyPath(&p_key_path))
                success = false;
            p_auto_increment = input_data_view.auto_increment();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::CreateObjectStore deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::CreateObjectStore");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateObjectStore(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_name),
                std::move(p_key_path),
                std::move(p_auto_increment));
            return true;
        }
        case internal::kDatabase_DeleteObjectStore_Name: {
            internal::Database_DeleteObjectStore_Params_Data* params = reinterpret_cast<internal::Database_DeleteObjectStore_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            Database_DeleteObjectStore_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::DeleteObjectStore deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::DeleteObjectStore");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeleteObjectStore(
                std::move(p_transaction_id),
                std::move(p_object_store_id));
            return true;
        }
        case internal::kDatabase_RenameObjectStore_Name: {
            internal::Database_RenameObjectStore_Params_Data* params = reinterpret_cast<internal::Database_RenameObjectStore_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            base::string16 p_new_name {};
            Database_RenameObjectStore_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            if (!input_data_view.ReadNewName(&p_new_name))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::RenameObjectStore deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::RenameObjectStore");
            mojo::internal::MessageDispatchContext context(message);
            impl->RenameObjectStore(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_new_name));
            return true;
        }
        case internal::kDatabase_CreateTransaction_Name: {
            internal::Database_CreateTransaction_Params_Data* params = reinterpret_cast<internal::Database_CreateTransaction_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            std::vector<int64_t> p_object_store_ids {};
            blink::WebIDBTransactionMode p_mode {};
            Database_CreateTransaction_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            if (!input_data_view.ReadObjectStoreIds(&p_object_store_ids))
                success = false;
            if (!input_data_view.ReadMode(&p_mode))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::CreateTransaction deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::CreateTransaction");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateTransaction(
                std::move(p_transaction_id),
                std::move(p_object_store_ids),
                std::move(p_mode));
            return true;
        }
        case internal::kDatabase_Close_Name: {
            internal::Database_Close_Params_Data* params = reinterpret_cast<internal::Database_Close_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Database_Close_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::Close deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::Close");
            mojo::internal::MessageDispatchContext context(message);
            impl->Close();
            return true;
        }
        case internal::kDatabase_VersionChangeIgnored_Name: {
            internal::Database_VersionChangeIgnored_Params_Data* params = reinterpret_cast<internal::Database_VersionChangeIgnored_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Database_VersionChangeIgnored_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::VersionChangeIgnored deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::VersionChangeIgnored");
            mojo::internal::MessageDispatchContext context(message);
            impl->VersionChangeIgnored();
            return true;
        }
        case internal::kDatabase_AddObserver_Name: {
            internal::Database_AddObserver_Params_Data* params = reinterpret_cast<internal::Database_AddObserver_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int32_t p_observer_id {};
            bool p_include_transaction {};
            bool p_no_records {};
            bool p_values {};
            uint16_t p_operation_types {};
            Database_AddObserver_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_observer_id = input_data_view.observer_id();
            p_include_transaction = input_data_view.include_transaction();
            p_no_records = input_data_view.no_records();
            p_values = input_data_view.values();
            p_operation_types = input_data_view.operation_types();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::AddObserver deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::AddObserver");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddObserver(
                std::move(p_transaction_id),
                std::move(p_observer_id),
                std::move(p_include_transaction),
                std::move(p_no_records),
                std::move(p_values),
                std::move(p_operation_types));
            return true;
        }
        case internal::kDatabase_RemoveObservers_Name: {
            internal::Database_RemoveObservers_Params_Data* params = reinterpret_cast<internal::Database_RemoveObservers_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<int32_t> p_observers {};
            Database_RemoveObservers_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadObservers(&p_observers))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::RemoveObservers deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::RemoveObservers");
            mojo::internal::MessageDispatchContext context(message);
            impl->RemoveObservers(
                std::move(p_observers));
            return true;
        }
        case internal::kDatabase_Get_Name: {
            internal::Database_Get_Params_Data* params = reinterpret_cast<internal::Database_Get_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            int64_t p_index_id {};
            content::IndexedDBKeyRange p_key_range {};
            bool p_key_only {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Database_Get_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            p_index_id = input_data_view.index_id();
            if (!input_data_view.ReadKeyRange(&p_key_range))
                success = false;
            p_key_only = input_data_view.key_only();
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::Get deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::Get");
            mojo::internal::MessageDispatchContext context(message);
            impl->Get(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_index_id),
                std::move(p_key_range),
                std::move(p_key_only),
                std::move(p_callbacks));
            return true;
        }
        case internal::kDatabase_GetAll_Name: {
            internal::Database_GetAll_Params_Data* params = reinterpret_cast<internal::Database_GetAll_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            int64_t p_index_id {};
            content::IndexedDBKeyRange p_key_range {};
            bool p_key_only {};
            int64_t p_max_count {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Database_GetAll_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            p_index_id = input_data_view.index_id();
            if (!input_data_view.ReadKeyRange(&p_key_range))
                success = false;
            p_key_only = input_data_view.key_only();
            p_max_count = input_data_view.max_count();
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::GetAll deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::GetAll");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetAll(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_index_id),
                std::move(p_key_range),
                std::move(p_key_only),
                std::move(p_max_count),
                std::move(p_callbacks));
            return true;
        }
        case internal::kDatabase_Put_Name: {
            internal::Database_Put_Params_Data* params = reinterpret_cast<internal::Database_Put_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            ValuePtr p_value {};
            content::IndexedDBKey p_key {};
            blink::WebIDBPutMode p_mode {};
            std::vector<content::IndexedDBIndexKeys> p_index_keys {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Database_Put_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadMode(&p_mode))
                success = false;
            if (!input_data_view.ReadIndexKeys(&p_index_keys))
                success = false;
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::Put deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::Put");
            mojo::internal::MessageDispatchContext context(message);
            impl->Put(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_value),
                std::move(p_key),
                std::move(p_mode),
                std::move(p_index_keys),
                std::move(p_callbacks));
            return true;
        }
        case internal::kDatabase_SetIndexKeys_Name: {
            internal::Database_SetIndexKeys_Params_Data* params = reinterpret_cast<internal::Database_SetIndexKeys_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            content::IndexedDBKey p_primary_key {};
            std::vector<content::IndexedDBIndexKeys> p_index_keys {};
            Database_SetIndexKeys_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            if (!input_data_view.ReadPrimaryKey(&p_primary_key))
                success = false;
            if (!input_data_view.ReadIndexKeys(&p_index_keys))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::SetIndexKeys deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::SetIndexKeys");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetIndexKeys(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_primary_key),
                std::move(p_index_keys));
            return true;
        }
        case internal::kDatabase_SetIndexesReady_Name: {
            internal::Database_SetIndexesReady_Params_Data* params = reinterpret_cast<internal::Database_SetIndexesReady_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            std::vector<int64_t> p_index_ids {};
            Database_SetIndexesReady_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            if (!input_data_view.ReadIndexIds(&p_index_ids))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::SetIndexesReady deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::SetIndexesReady");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetIndexesReady(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_index_ids));
            return true;
        }
        case internal::kDatabase_OpenCursor_Name: {
            internal::Database_OpenCursor_Params_Data* params = reinterpret_cast<internal::Database_OpenCursor_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            int64_t p_index_id {};
            content::IndexedDBKeyRange p_key_range {};
            blink::WebIDBCursorDirection p_direction {};
            bool p_key_only {};
            blink::WebIDBTaskType p_task_type {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Database_OpenCursor_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            p_index_id = input_data_view.index_id();
            if (!input_data_view.ReadKeyRange(&p_key_range))
                success = false;
            if (!input_data_view.ReadDirection(&p_direction))
                success = false;
            p_key_only = input_data_view.key_only();
            if (!input_data_view.ReadTaskType(&p_task_type))
                success = false;
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::OpenCursor deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::OpenCursor");
            mojo::internal::MessageDispatchContext context(message);
            impl->OpenCursor(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_index_id),
                std::move(p_key_range),
                std::move(p_direction),
                std::move(p_key_only),
                std::move(p_task_type),
                std::move(p_callbacks));
            return true;
        }
        case internal::kDatabase_Count_Name: {
            internal::Database_Count_Params_Data* params = reinterpret_cast<internal::Database_Count_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            int64_t p_index_id {};
            content::IndexedDBKeyRange p_key_range {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Database_Count_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            p_index_id = input_data_view.index_id();
            if (!input_data_view.ReadKeyRange(&p_key_range))
                success = false;
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::Count deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::Count");
            mojo::internal::MessageDispatchContext context(message);
            impl->Count(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_index_id),
                std::move(p_key_range),
                std::move(p_callbacks));
            return true;
        }
        case internal::kDatabase_DeleteRange_Name: {
            internal::Database_DeleteRange_Params_Data* params = reinterpret_cast<internal::Database_DeleteRange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            content::IndexedDBKeyRange p_key_range {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Database_DeleteRange_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            if (!input_data_view.ReadKeyRange(&p_key_range))
                success = false;
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::DeleteRange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::DeleteRange");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeleteRange(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_key_range),
                std::move(p_callbacks));
            return true;
        }
        case internal::kDatabase_Clear_Name: {
            internal::Database_Clear_Params_Data* params = reinterpret_cast<internal::Database_Clear_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            CallbacksAssociatedPtrInfo p_callbacks {};
            Database_Clear_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::Clear deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::Clear");
            mojo::internal::MessageDispatchContext context(message);
            impl->Clear(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_callbacks));
            return true;
        }
        case internal::kDatabase_CreateIndex_Name: {
            internal::Database_CreateIndex_Params_Data* params = reinterpret_cast<internal::Database_CreateIndex_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            int64_t p_index_id {};
            base::string16 p_name {};
            content::IndexedDBKeyPath p_key_path {};
            bool p_unique {};
            bool p_multi_entry {};
            Database_CreateIndex_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            p_index_id = input_data_view.index_id();
            if (!input_data_view.ReadName(&p_name))
                success = false;
            if (!input_data_view.ReadKeyPath(&p_key_path))
                success = false;
            p_unique = input_data_view.unique();
            p_multi_entry = input_data_view.multi_entry();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::CreateIndex deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::CreateIndex");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateIndex(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_index_id),
                std::move(p_name),
                std::move(p_key_path),
                std::move(p_unique),
                std::move(p_multi_entry));
            return true;
        }
        case internal::kDatabase_DeleteIndex_Name: {
            internal::Database_DeleteIndex_Params_Data* params = reinterpret_cast<internal::Database_DeleteIndex_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            int64_t p_index_id {};
            Database_DeleteIndex_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            p_index_id = input_data_view.index_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::DeleteIndex deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::DeleteIndex");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeleteIndex(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_index_id));
            return true;
        }
        case internal::kDatabase_RenameIndex_Name: {
            internal::Database_RenameIndex_Params_Data* params = reinterpret_cast<internal::Database_RenameIndex_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            int64_t p_object_store_id {};
            int64_t p_index_id {};
            base::string16 p_new_name {};
            Database_RenameIndex_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            p_object_store_id = input_data_view.object_store_id();
            p_index_id = input_data_view.index_id();
            if (!input_data_view.ReadNewName(&p_new_name))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::RenameIndex deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::RenameIndex");
            mojo::internal::MessageDispatchContext context(message);
            impl->RenameIndex(
                std::move(p_transaction_id),
                std::move(p_object_store_id),
                std::move(p_index_id),
                std::move(p_new_name));
            return true;
        }
        case internal::kDatabase_Abort_Name: {
            internal::Database_Abort_Params_Data* params = reinterpret_cast<internal::Database_Abort_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            Database_Abort_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::Abort deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::Abort");
            mojo::internal::MessageDispatchContext context(message);
            impl->Abort(
                std::move(p_transaction_id));
            return true;
        }
        case internal::kDatabase_Commit_Name: {
            internal::Database_Commit_Params_Data* params = reinterpret_cast<internal::Database_Commit_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int64_t p_transaction_id {};
            Database_Commit_ParamsDataView input_data_view(params,
                context);

            p_transaction_id = input_data_view.transaction_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::Commit deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::Commit");
            mojo::internal::MessageDispatchContext context(message);
            impl->Commit(
                std::move(p_transaction_id));
            return true;
        }
        case internal::kDatabase_AckReceivedBlobs_Name: {
            internal::Database_AckReceivedBlobs_Params_Data* params = reinterpret_cast<internal::Database_AckReceivedBlobs_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<std::string> p_uuids {};
            Database_AckReceivedBlobs_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUuids(&p_uuids))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Database::AckReceivedBlobs deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Database::AckReceivedBlobs");
            mojo::internal::MessageDispatchContext context(message);
            impl->AckReceivedBlobs(
                std::move(p_uuids));
            return true;
        }
        }
        return false;
    }

    // static
    bool DatabaseStubDispatch::AcceptWithResponder(
        Database* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDatabase_CreateObjectStore_Name: {
            break;
        }
        case internal::kDatabase_DeleteObjectStore_Name: {
            break;
        }
        case internal::kDatabase_RenameObjectStore_Name: {
            break;
        }
        case internal::kDatabase_CreateTransaction_Name: {
            break;
        }
        case internal::kDatabase_Close_Name: {
            break;
        }
        case internal::kDatabase_VersionChangeIgnored_Name: {
            break;
        }
        case internal::kDatabase_AddObserver_Name: {
            break;
        }
        case internal::kDatabase_RemoveObservers_Name: {
            break;
        }
        case internal::kDatabase_Get_Name: {
            break;
        }
        case internal::kDatabase_GetAll_Name: {
            break;
        }
        case internal::kDatabase_Put_Name: {
            break;
        }
        case internal::kDatabase_SetIndexKeys_Name: {
            break;
        }
        case internal::kDatabase_SetIndexesReady_Name: {
            break;
        }
        case internal::kDatabase_OpenCursor_Name: {
            break;
        }
        case internal::kDatabase_Count_Name: {
            break;
        }
        case internal::kDatabase_DeleteRange_Name: {
            break;
        }
        case internal::kDatabase_Clear_Name: {
            break;
        }
        case internal::kDatabase_CreateIndex_Name: {
            break;
        }
        case internal::kDatabase_DeleteIndex_Name: {
            break;
        }
        case internal::kDatabase_RenameIndex_Name: {
            break;
        }
        case internal::kDatabase_Abort_Name: {
            break;
        }
        case internal::kDatabase_Commit_Name: {
            break;
        }
        case internal::kDatabase_AckReceivedBlobs_Name: {
            break;
        }
        }
        return false;
    }

    bool DatabaseRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Database RequestValidator");

        switch (message->header()->name) {
        case internal::kDatabase_CreateObjectStore_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_CreateObjectStore_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_DeleteObjectStore_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_DeleteObjectStore_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_RenameObjectStore_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_RenameObjectStore_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_CreateTransaction_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_CreateTransaction_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_Close_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_Close_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_VersionChangeIgnored_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_VersionChangeIgnored_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_AddObserver_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_AddObserver_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_RemoveObservers_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_RemoveObservers_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_Get_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_Get_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_GetAll_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_GetAll_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_Put_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_Put_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_SetIndexKeys_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_SetIndexKeys_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_SetIndexesReady_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_SetIndexesReady_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_OpenCursor_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_OpenCursor_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_Count_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_Count_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_DeleteRange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_DeleteRange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_Clear_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_Clear_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_CreateIndex_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_CreateIndex_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_DeleteIndex_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_DeleteIndex_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_RenameIndex_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_RenameIndex_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_Abort_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_Abort_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_Commit_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_Commit_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDatabase_AckReceivedBlobs_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Database_AckReceivedBlobs_Params_Data>(
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

    const char Factory::Name_[] = "indexed_db::mojom::Factory";

    FactoryProxy::FactoryProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void FactoryProxy::GetDatabaseNames(
        CallbacksAssociatedPtrInfo in_callbacks, const url::Origin& in_origin)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Factory_GetDatabaseNames_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kFactory_GetDatabaseNames_Name, size);

        auto params = ::indexed_db::mojom::internal::Factory_GetDatabaseNames_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Factory.GetDatabaseNames request");
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in Factory.GetDatabaseNames request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void FactoryProxy::Open(
        CallbacksAssociatedPtrInfo in_callbacks, DatabaseCallbacksAssociatedPtrInfo in_database_callbacks, const url::Origin& in_origin, const base::string16& in_name, int64_t in_version, int64_t in_transaction_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Factory_Open_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_name, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kFactory_Open_Name, size);

        auto params = ::indexed_db::mojom::internal::Factory_Open_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Factory.Open request");
        mojo::internal::Serialize<::indexed_db::mojom::DatabaseCallbacksAssociatedPtrInfoDataView>(
            in_database_callbacks, &params->database_callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->database_callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid database_callbacks in Factory.Open request");
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in Factory.Open request");
        typename decltype(params->name)::BaseType* name_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_name, builder.buffer(), &name_ptr, &serialization_context);
        params->name.Set(name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null name in Factory.Open request");
        params->version = in_version;
        params->transaction_id = in_transaction_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void FactoryProxy::DeleteDatabase(
        CallbacksAssociatedPtrInfo in_callbacks, const url::Origin& in_origin, const base::string16& in_name)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::indexed_db::mojom::internal::Factory_DeleteDatabase_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_name, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kFactory_DeleteDatabase_Name, size);

        auto params = ::indexed_db::mojom::internal::Factory_DeleteDatabase_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::indexed_db::mojom::CallbacksAssociatedPtrInfoDataView>(
            in_callbacks, &params->callbacks, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->callbacks),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid callbacks in Factory.DeleteDatabase request");
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in Factory.DeleteDatabase request");
        typename decltype(params->name)::BaseType* name_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_name, builder.buffer(), &name_ptr, &serialization_context);
        params->name.Set(name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null name in Factory.DeleteDatabase request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool FactoryStubDispatch::Accept(
        Factory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kFactory_GetDatabaseNames_Name: {
            internal::Factory_GetDatabaseNames_Params_Data* params = reinterpret_cast<internal::Factory_GetDatabaseNames_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            CallbacksAssociatedPtrInfo p_callbacks {};
            url::Origin p_origin {};
            Factory_GetDatabaseNames_ParamsDataView input_data_view(params,
                context);

            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Factory::GetDatabaseNames deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Factory::GetDatabaseNames");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetDatabaseNames(
                std::move(p_callbacks),
                std::move(p_origin));
            return true;
        }
        case internal::kFactory_Open_Name: {
            internal::Factory_Open_Params_Data* params = reinterpret_cast<internal::Factory_Open_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            CallbacksAssociatedPtrInfo p_callbacks {};
            DatabaseCallbacksAssociatedPtrInfo p_database_callbacks {};
            url::Origin p_origin {};
            base::string16 p_name {};
            int64_t p_version {};
            int64_t p_transaction_id {};
            Factory_Open_ParamsDataView input_data_view(params,
                context);

            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            p_database_callbacks = input_data_view.TakeDatabaseCallbacks<decltype(p_database_callbacks)>();
            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!input_data_view.ReadName(&p_name))
                success = false;
            p_version = input_data_view.version();
            p_transaction_id = input_data_view.transaction_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Factory::Open deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Factory::Open");
            mojo::internal::MessageDispatchContext context(message);
            impl->Open(
                std::move(p_callbacks),
                std::move(p_database_callbacks),
                std::move(p_origin),
                std::move(p_name),
                std::move(p_version),
                std::move(p_transaction_id));
            return true;
        }
        case internal::kFactory_DeleteDatabase_Name: {
            internal::Factory_DeleteDatabase_Params_Data* params = reinterpret_cast<internal::Factory_DeleteDatabase_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            CallbacksAssociatedPtrInfo p_callbacks {};
            url::Origin p_origin {};
            base::string16 p_name {};
            Factory_DeleteDatabase_ParamsDataView input_data_view(params,
                context);

            p_callbacks = input_data_view.TakeCallbacks<decltype(p_callbacks)>();
            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!input_data_view.ReadName(&p_name))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Factory::DeleteDatabase deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Factory::DeleteDatabase");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeleteDatabase(
                std::move(p_callbacks),
                std::move(p_origin),
                std::move(p_name));
            return true;
        }
        }
        return false;
    }

    // static
    bool FactoryStubDispatch::AcceptWithResponder(
        Factory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kFactory_GetDatabaseNames_Name: {
            break;
        }
        case internal::kFactory_Open_Name: {
            break;
        }
        case internal::kFactory_DeleteDatabase_Name: {
            break;
        }
        }
        return false;
    }

    bool FactoryRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Factory RequestValidator");

        switch (message->header()->name) {
        case internal::kFactory_GetDatabaseNames_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Factory_GetDatabaseNames_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kFactory_Open_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Factory_Open_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kFactory_DeleteDatabase_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Factory_DeleteDatabase_Params_Data>(
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
} // namespace indexed_db

namespace mojo {

// static
bool StructTraits<::indexed_db::mojom::Key::DataView, ::indexed_db::mojom::KeyPtr>::Read(
    ::indexed_db::mojom::Key::DataView input,
    ::indexed_db::mojom::KeyPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::KeyPtr result(::indexed_db::mojom::Key::New());

    if (!input.ReadData(&result->data))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::KeyPath::DataView, ::indexed_db::mojom::KeyPathPtr>::Read(
    ::indexed_db::mojom::KeyPath::DataView input,
    ::indexed_db::mojom::KeyPathPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::KeyPathPtr result(::indexed_db::mojom::KeyPath::New());

    if (!input.ReadData(&result->data))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::KeyRange::DataView, ::indexed_db::mojom::KeyRangePtr>::Read(
    ::indexed_db::mojom::KeyRange::DataView input,
    ::indexed_db::mojom::KeyRangePtr* output)
{
    bool success = true;
    ::indexed_db::mojom::KeyRangePtr result(::indexed_db::mojom::KeyRange::New());

    if (!input.ReadLower(&result->lower))
        success = false;
    if (!input.ReadUpper(&result->upper))
        success = false;
    result->lower_open = input.lower_open();
    result->upper_open = input.upper_open();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::IndexMetadata::DataView, ::indexed_db::mojom::IndexMetadataPtr>::Read(
    ::indexed_db::mojom::IndexMetadata::DataView input,
    ::indexed_db::mojom::IndexMetadataPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::IndexMetadataPtr result(::indexed_db::mojom::IndexMetadata::New());

    result->id = input.id();
    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadKeyPath(&result->key_path))
        success = false;
    result->unique = input.unique();
    result->multi_entry = input.multi_entry();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::ObjectStoreMetadata::DataView, ::indexed_db::mojom::ObjectStoreMetadataPtr>::Read(
    ::indexed_db::mojom::ObjectStoreMetadata::DataView input,
    ::indexed_db::mojom::ObjectStoreMetadataPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::ObjectStoreMetadataPtr result(::indexed_db::mojom::ObjectStoreMetadata::New());

    result->id = input.id();
    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadKeyPath(&result->key_path))
        success = false;
    result->auto_increment = input.auto_increment();
    result->max_index_id = input.max_index_id();
    if (!input.ReadIndexes(&result->indexes))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::DatabaseMetadata::DataView, ::indexed_db::mojom::DatabaseMetadataPtr>::Read(
    ::indexed_db::mojom::DatabaseMetadata::DataView input,
    ::indexed_db::mojom::DatabaseMetadataPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::DatabaseMetadataPtr result(::indexed_db::mojom::DatabaseMetadata::New());

    result->id = input.id();
    if (!input.ReadName(&result->name))
        success = false;
    result->version = input.version();
    result->max_object_store_id = input.max_object_store_id();
    if (!input.ReadObjectStores(&result->object_stores))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::IndexKeys::DataView, ::indexed_db::mojom::IndexKeysPtr>::Read(
    ::indexed_db::mojom::IndexKeys::DataView input,
    ::indexed_db::mojom::IndexKeysPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::IndexKeysPtr result(::indexed_db::mojom::IndexKeys::New());

    result->index_id = input.index_id();
    if (!input.ReadIndexKeys(&result->index_keys))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::FileInfo::DataView, ::indexed_db::mojom::FileInfoPtr>::Read(
    ::indexed_db::mojom::FileInfo::DataView input,
    ::indexed_db::mojom::FileInfoPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::FileInfoPtr result(::indexed_db::mojom::FileInfo::New());

    if (!input.ReadPath(&result->path))
        success = false;
    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadLastModified(&result->last_modified))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::BlobInfo::DataView, ::indexed_db::mojom::BlobInfoPtr>::Read(
    ::indexed_db::mojom::BlobInfo::DataView input,
    ::indexed_db::mojom::BlobInfoPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::BlobInfoPtr result(::indexed_db::mojom::BlobInfo::New());

    if (!input.ReadUuid(&result->uuid))
        success = false;
    if (!input.ReadMimeType(&result->mime_type))
        success = false;
    result->size = input.size();
    if (!input.ReadFile(&result->file))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::Value::DataView, ::indexed_db::mojom::ValuePtr>::Read(
    ::indexed_db::mojom::Value::DataView input,
    ::indexed_db::mojom::ValuePtr* output)
{
    bool success = true;
    ::indexed_db::mojom::ValuePtr result(::indexed_db::mojom::Value::New());

    if (!input.ReadBits(&result->bits))
        success = false;
    if (!input.ReadBlobOrFileInfo(&result->blob_or_file_info))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::ReturnValue::DataView, ::indexed_db::mojom::ReturnValuePtr>::Read(
    ::indexed_db::mojom::ReturnValue::DataView input,
    ::indexed_db::mojom::ReturnValuePtr* output)
{
    bool success = true;
    ::indexed_db::mojom::ReturnValuePtr result(::indexed_db::mojom::ReturnValue::New());

    if (!input.ReadValue(&result->value))
        success = false;
    if (!input.ReadPrimaryKey(&result->primary_key))
        success = false;
    if (!input.ReadKeyPath(&result->key_path))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::Observation::DataView, ::indexed_db::mojom::ObservationPtr>::Read(
    ::indexed_db::mojom::Observation::DataView input,
    ::indexed_db::mojom::ObservationPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::ObservationPtr result(::indexed_db::mojom::Observation::New());

    result->object_store_id = input.object_store_id();
    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadKeyRange(&result->key_range))
        success = false;
    if (!input.ReadValue(&result->value))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::ObserverTransaction::DataView, ::indexed_db::mojom::ObserverTransactionPtr>::Read(
    ::indexed_db::mojom::ObserverTransaction::DataView input,
    ::indexed_db::mojom::ObserverTransactionPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::ObserverTransactionPtr result(::indexed_db::mojom::ObserverTransaction::New());

    result->id = input.id();
    if (!input.ReadScope(&result->scope))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::indexed_db::mojom::ObserverChanges::DataView, ::indexed_db::mojom::ObserverChangesPtr>::Read(
    ::indexed_db::mojom::ObserverChanges::DataView input,
    ::indexed_db::mojom::ObserverChangesPtr* output)
{
    bool success = true;
    ::indexed_db::mojom::ObserverChangesPtr result(::indexed_db::mojom::ObserverChanges::New());

    if (!input.ReadObservationIndexMap(&result->observation_index_map))
        success = false;
    if (!input.ReadTransactionMap(&result->transaction_map))
        success = false;
    if (!input.ReadObservations(&result->observations))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool UnionTraits<::indexed_db::mojom::KeyData::DataView, ::indexed_db::mojom::KeyDataPtr>::Read(
    ::indexed_db::mojom::KeyData::DataView input,
    ::indexed_db::mojom::KeyDataPtr* output)
{
    *output = ::indexed_db::mojom::KeyData::New();
    ::indexed_db::mojom::KeyDataPtr& result = *output;

    internal::UnionAccessor<::indexed_db::mojom::KeyData> result_acc(result.get());
    switch (input.tag()) {
    case ::indexed_db::mojom::KeyData::Tag::KEY_ARRAY: {
        result_acc.SwitchActive(::indexed_db::mojom::KeyData::Tag::KEY_ARRAY);
        if (!input.ReadKeyArray(result_acc.data()->key_array))
            return false;
        break;
    }
    case ::indexed_db::mojom::KeyData::Tag::BINARY: {
        result_acc.SwitchActive(::indexed_db::mojom::KeyData::Tag::BINARY);
        if (!input.ReadBinary(result_acc.data()->binary))
            return false;
        break;
    }
    case ::indexed_db::mojom::KeyData::Tag::STRING: {
        result_acc.SwitchActive(::indexed_db::mojom::KeyData::Tag::STRING);
        if (!input.ReadString(result_acc.data()->string))
            return false;
        break;
    }
    case ::indexed_db::mojom::KeyData::Tag::DATE: {
        result->set_date(input.date());
        break;
    }
    case ::indexed_db::mojom::KeyData::Tag::NUMBER: {
        result->set_number(input.number());
        break;
    }
    case ::indexed_db::mojom::KeyData::Tag::OTHER: {
        decltype(result->get_other()) result_other;
        if (!input.ReadOther(&result_other))
            return false;
        result->set_other(result_other);
        break;
    }
    default:
        return false;
    }
    return true;
}

// static
bool UnionTraits<::indexed_db::mojom::KeyPathData::DataView, ::indexed_db::mojom::KeyPathDataPtr>::Read(
    ::indexed_db::mojom::KeyPathData::DataView input,
    ::indexed_db::mojom::KeyPathDataPtr* output)
{
    *output = ::indexed_db::mojom::KeyPathData::New();
    ::indexed_db::mojom::KeyPathDataPtr& result = *output;

    internal::UnionAccessor<::indexed_db::mojom::KeyPathData> result_acc(result.get());
    switch (input.tag()) {
    case ::indexed_db::mojom::KeyPathData::Tag::STRING: {
        result_acc.SwitchActive(::indexed_db::mojom::KeyPathData::Tag::STRING);
        if (!input.ReadString(result_acc.data()->string))
            return false;
        break;
    }
    case ::indexed_db::mojom::KeyPathData::Tag::STRING_ARRAY: {
        result_acc.SwitchActive(::indexed_db::mojom::KeyPathData::Tag::STRING_ARRAY);
        if (!input.ReadStringArray(result_acc.data()->string_array))
            return false;
        break;
    }
    default:
        return false;
    }
    return true;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif