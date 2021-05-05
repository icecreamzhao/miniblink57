// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_INDEXED_DB_INDEXED_DB_MOJOM_H_
#define CONTENT_COMMON_INDEXED_DB_INDEXED_DB_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "cc/input/selection.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/compositor_frame_metadata.h"
#include "cc/output/filter_operation.h"
#include "cc/output/filter_operations.h"
#include "cc/quads/draw_quad.h"
#include "cc/quads/render_pass.h"
#include "cc/quads/shared_quad_state.h"
#include "cc/resources/returned_resource.h"
#include "cc/resources/transferable_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_reference.h"
#include "cc/surfaces/surface_sequence.h"
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/common/frame_owner_properties.h"
#include "content/common/frame_replication_state.h"
#include "content/common/indexed_db/indexed_db.mojom-shared.h"
#include "content/common/indexed_db/indexed_db_key.h"
#include "content/common/indexed_db/indexed_db_key_path.h"
#include "content/common/indexed_db/indexed_db_key_range.h"
#include "content/common/indexed_db/indexed_db_metadata.h"
#include "content/common/media/media_devices.h"
#include "content/common/resize_params.h"
#include "content/common/resource_request.h"
#include "content/common/resource_request_completion_status.h"
#include "content/common/service_worker/embedded_worker_start_params.h"
#include "content/common/service_worker/service_worker_status_code.h"
#include "content/common/service_worker/service_worker_types.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/push_event_payload.h"
#include "content/public/common/referrer.h"
#include "content/public/common/renderer_preferences.h"
#include "content/public/common/resource_response.h"
#include "content/public/common/web_preferences.h"
#include "device/bluetooth/bluetooth_uuid.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
#include "media/base/audio_codecs.h"
#include "media/base/audio_parameters.h"
#include "media/base/buffering_state.h"
#include "media/base/cdm_key_information.h"
#include "media/base/cdm_promise.h"
#include "media/base/channel_layout.h"
#include "media/base/content_decryption_module.h"
#include "media/base/decode_status.h"
#include "media/base/decryptor.h"
#include "media/base/demuxer_stream.h"
#include "media/base/eme_constants.h"
#include "media/base/encryption_scheme.h"
#include "media/base/pipeline_status.h"
#include "media/base/sample_format.h"
#include "media/base/subsample_entry.h"
#include "media/base/video_codecs.h"
#include "media/base/video_types.h"
#include "media/capture/video/video_capture_device_descriptor.h"
#include "media/capture/video_capture_types.h"
#include "mojo/common/file_path.mojom.h"
#include "mojo/common/string16.mojom.h"
#include "mojo/common/time.mojom.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "net/base/network_change_notifier.h"
#include "net/url_request/redirect_info.h"
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/interface_provider_spec.h"
#include "services/service_manager/public/cpp/service_info.h"
#include "services/video_capture/public/cpp/capture_settings.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/modules/indexeddb/WebIDBTypes.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebPopupType.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/base/window_open_disposition.h"
#include "ui/display/display.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/range/range.h"
#include "ui/gfx/range/range_f.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include "url/gurl.h"
#include "url/mojo/origin.mojom.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace indexed_db {
namespace mojom {
    class Callbacks;
    using CallbacksPtr = mojo::InterfacePtr<Callbacks>;
    using CallbacksPtrInfo = mojo::InterfacePtrInfo<Callbacks>;
    using ThreadSafeCallbacksPtr = mojo::ThreadSafeInterfacePtr<Callbacks>;
    using CallbacksRequest = mojo::InterfaceRequest<Callbacks>;
    using CallbacksAssociatedPtr = mojo::AssociatedInterfacePtr<Callbacks>;
    using ThreadSafeCallbacksAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Callbacks>;
    using CallbacksAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Callbacks>;
    using CallbacksAssociatedRequest = mojo::AssociatedInterfaceRequest<Callbacks>;

    class DatabaseCallbacks;
    using DatabaseCallbacksPtr = mojo::InterfacePtr<DatabaseCallbacks>;
    using DatabaseCallbacksPtrInfo = mojo::InterfacePtrInfo<DatabaseCallbacks>;
    using ThreadSafeDatabaseCallbacksPtr = mojo::ThreadSafeInterfacePtr<DatabaseCallbacks>;
    using DatabaseCallbacksRequest = mojo::InterfaceRequest<DatabaseCallbacks>;
    using DatabaseCallbacksAssociatedPtr = mojo::AssociatedInterfacePtr<DatabaseCallbacks>;
    using ThreadSafeDatabaseCallbacksAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DatabaseCallbacks>;
    using DatabaseCallbacksAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DatabaseCallbacks>;
    using DatabaseCallbacksAssociatedRequest = mojo::AssociatedInterfaceRequest<DatabaseCallbacks>;

    class Cursor;
    using CursorPtr = mojo::InterfacePtr<Cursor>;
    using CursorPtrInfo = mojo::InterfacePtrInfo<Cursor>;
    using ThreadSafeCursorPtr = mojo::ThreadSafeInterfacePtr<Cursor>;
    using CursorRequest = mojo::InterfaceRequest<Cursor>;
    using CursorAssociatedPtr = mojo::AssociatedInterfacePtr<Cursor>;
    using ThreadSafeCursorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Cursor>;
    using CursorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Cursor>;
    using CursorAssociatedRequest = mojo::AssociatedInterfaceRequest<Cursor>;

    class Database;
    using DatabasePtr = mojo::InterfacePtr<Database>;
    using DatabasePtrInfo = mojo::InterfacePtrInfo<Database>;
    using ThreadSafeDatabasePtr = mojo::ThreadSafeInterfacePtr<Database>;
    using DatabaseRequest = mojo::InterfaceRequest<Database>;
    using DatabaseAssociatedPtr = mojo::AssociatedInterfacePtr<Database>;
    using ThreadSafeDatabaseAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Database>;
    using DatabaseAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Database>;
    using DatabaseAssociatedRequest = mojo::AssociatedInterfaceRequest<Database>;

    class Factory;
    using FactoryPtr = mojo::InterfacePtr<Factory>;
    using FactoryPtrInfo = mojo::InterfacePtrInfo<Factory>;
    using ThreadSafeFactoryPtr = mojo::ThreadSafeInterfacePtr<Factory>;
    using FactoryRequest = mojo::InterfaceRequest<Factory>;
    using FactoryAssociatedPtr = mojo::AssociatedInterfacePtr<Factory>;
    using ThreadSafeFactoryAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Factory>;
    using FactoryAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Factory>;
    using FactoryAssociatedRequest = mojo::AssociatedInterfaceRequest<Factory>;

    class Key;
    using KeyPtr = mojo::StructPtr<Key>;

    class KeyPath;
    using KeyPathPtr = mojo::StructPtr<KeyPath>;

    class KeyRange;
    using KeyRangePtr = mojo::StructPtr<KeyRange>;

    class IndexMetadata;
    using IndexMetadataPtr = mojo::StructPtr<IndexMetadata>;

    class ObjectStoreMetadata;
    using ObjectStoreMetadataPtr = mojo::StructPtr<ObjectStoreMetadata>;

    class DatabaseMetadata;
    using DatabaseMetadataPtr = mojo::StructPtr<DatabaseMetadata>;

    class IndexKeys;
    using IndexKeysPtr = mojo::StructPtr<IndexKeys>;

    class FileInfo;
    using FileInfoPtr = mojo::StructPtr<FileInfo>;

    class BlobInfo;
    using BlobInfoPtr = mojo::StructPtr<BlobInfo>;

    class Value;
    using ValuePtr = mojo::StructPtr<Value>;

    class ReturnValue;
    using ReturnValuePtr = mojo::StructPtr<ReturnValue>;

    class Observation;
    using ObservationPtr = mojo::StructPtr<Observation>;

    class ObserverTransaction;
    using ObserverTransactionPtr = mojo::StructPtr<ObserverTransaction>;

    class ObserverChanges;
    using ObserverChangesPtr = mojo::StructPtr<ObserverChanges>;

    class KeyData;

    typedef mojo::StructPtr<KeyData> KeyDataPtr;

    class KeyPathData;

    typedef mojo::StructPtr<KeyPathData> KeyPathDataPtr;

    class CallbacksProxy;

    template <typename ImplRefTraits>
    class CallbacksStub;

    class CallbacksRequestValidator;

    class CONTENT_EXPORT Callbacks
        : public CallbacksInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = CallbacksProxy;

        template <typename ImplRefTraits>
        using Stub_ = CallbacksStub<ImplRefTraits>;

        using RequestValidator_ = CallbacksRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kErrorMinVersion = 0,
            kSuccessStringListMinVersion = 0,
            kBlockedMinVersion = 0,
            kUpgradeNeededMinVersion = 0,
            kSuccessDatabaseMinVersion = 0,
            kSuccessCursorMinVersion = 0,
            kSuccessValueMinVersion = 0,
            kSuccessCursorContinueMinVersion = 0,
            kSuccessCursorPrefetchMinVersion = 0,
            kSuccessArrayMinVersion = 0,
            kSuccessKeyMinVersion = 0,
            kSuccessIntegerMinVersion = 0,
            kSuccessMinVersion = 0,
        };
        virtual ~Callbacks() { }

        virtual void Error(int32_t code, const base::string16& message) = 0;

        virtual void SuccessStringList(const std::vector<base::string16>& value) = 0;

        virtual void Blocked(int64_t existing_version) = 0;

        virtual void UpgradeNeeded(DatabaseAssociatedPtrInfo database, int64_t old_version, blink::WebIDBDataLoss data_loss, const std::string& data_loss_message, const content::IndexedDBDatabaseMetadata& db_metadata) = 0;

        virtual void SuccessDatabase(DatabaseAssociatedPtrInfo database, const content::IndexedDBDatabaseMetadata& metadata) = 0;

        virtual void SuccessCursor(CursorAssociatedPtrInfo cursor, const content::IndexedDBKey& key, const content::IndexedDBKey& primary_key, ValuePtr value) = 0;

        virtual void SuccessValue(ReturnValuePtr value) = 0;

        virtual void SuccessCursorContinue(const content::IndexedDBKey& key, const content::IndexedDBKey& primary_key, ValuePtr value) = 0;

        virtual void SuccessCursorPrefetch(const std::vector<content::IndexedDBKey>& keys, const std::vector<content::IndexedDBKey>& primary_keys, std::vector<ValuePtr> values) = 0;

        virtual void SuccessArray(std::vector<ReturnValuePtr> values) = 0;

        virtual void SuccessKey(const content::IndexedDBKey& key) = 0;

        virtual void SuccessInteger(int64_t value) = 0;

        virtual void Success() = 0;
    };

    class DatabaseCallbacksProxy;

    template <typename ImplRefTraits>
    class DatabaseCallbacksStub;

    class DatabaseCallbacksRequestValidator;

    class CONTENT_EXPORT DatabaseCallbacks
        : public DatabaseCallbacksInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DatabaseCallbacksProxy;

        template <typename ImplRefTraits>
        using Stub_ = DatabaseCallbacksStub<ImplRefTraits>;

        using RequestValidator_ = DatabaseCallbacksRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kForcedCloseMinVersion = 0,
            kVersionChangeMinVersion = 0,
            kAbortMinVersion = 0,
            kCompleteMinVersion = 0,
            kChangesMinVersion = 0,
        };
        virtual ~DatabaseCallbacks() { }

        virtual void ForcedClose() = 0;

        virtual void VersionChange(int64_t old_version, int64_t new_version) = 0;

        virtual void Abort(int64_t transaction_id, int32_t code, const base::string16& message) = 0;

        virtual void Complete(int64_t transaction_id) = 0;

        virtual void Changes(ObserverChangesPtr changes) = 0;
    };

    class CursorProxy;

    template <typename ImplRefTraits>
    class CursorStub;

    class CursorRequestValidator;

    class CONTENT_EXPORT Cursor
        : public CursorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = CursorProxy;

        template <typename ImplRefTraits>
        using Stub_ = CursorStub<ImplRefTraits>;

        using RequestValidator_ = CursorRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kAdvanceMinVersion = 0,
            kContinueMinVersion = 0,
            kPrefetchMinVersion = 0,
            kPrefetchResetMinVersion = 0,
        };
        virtual ~Cursor() { }

        virtual void Advance(uint32_t count, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void Continue(const content::IndexedDBKey& key, const content::IndexedDBKey& primary_key, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void Prefetch(int32_t count, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void PrefetchReset(int32_t used_prefetches, int32_t unused_prefetches, const std::vector<std::string>& unused_blob_uuids) = 0;
    };

    class DatabaseProxy;

    template <typename ImplRefTraits>
    class DatabaseStub;

    class DatabaseRequestValidator;

    class CONTENT_EXPORT Database
        : public DatabaseInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DatabaseProxy;

        template <typename ImplRefTraits>
        using Stub_ = DatabaseStub<ImplRefTraits>;

        using RequestValidator_ = DatabaseRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kCreateObjectStoreMinVersion = 0,
            kDeleteObjectStoreMinVersion = 0,
            kRenameObjectStoreMinVersion = 0,
            kCreateTransactionMinVersion = 0,
            kCloseMinVersion = 0,
            kVersionChangeIgnoredMinVersion = 0,
            kAddObserverMinVersion = 0,
            kRemoveObserversMinVersion = 0,
            kGetMinVersion = 0,
            kGetAllMinVersion = 0,
            kPutMinVersion = 0,
            kSetIndexKeysMinVersion = 0,
            kSetIndexesReadyMinVersion = 0,
            kOpenCursorMinVersion = 0,
            kCountMinVersion = 0,
            kDeleteRangeMinVersion = 0,
            kClearMinVersion = 0,
            kCreateIndexMinVersion = 0,
            kDeleteIndexMinVersion = 0,
            kRenameIndexMinVersion = 0,
            kAbortMinVersion = 0,
            kCommitMinVersion = 0,
            kAckReceivedBlobsMinVersion = 0,
        };
        virtual ~Database() { }

        virtual void CreateObjectStore(int64_t transaction_id, int64_t object_store_id, const base::string16& name, const content::IndexedDBKeyPath& key_path, bool auto_increment) = 0;

        virtual void DeleteObjectStore(int64_t transaction_id, int64_t object_store_id) = 0;

        virtual void RenameObjectStore(int64_t transaction_id, int64_t object_store_id, const base::string16& new_name) = 0;

        virtual void CreateTransaction(int64_t transaction_id, const std::vector<int64_t>& object_store_ids, blink::WebIDBTransactionMode mode) = 0;

        virtual void Close() = 0;

        virtual void VersionChangeIgnored() = 0;

        virtual void AddObserver(int64_t transaction_id, int32_t observer_id, bool include_transaction, bool no_records, bool values, uint16_t operation_types) = 0;

        virtual void RemoveObservers(const std::vector<int32_t>& observers) = 0;

        virtual void Get(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const content::IndexedDBKeyRange& key_range, bool key_only, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void GetAll(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const content::IndexedDBKeyRange& key_range, bool key_only, int64_t max_count, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void Put(int64_t transaction_id, int64_t object_store_id, ValuePtr value, const content::IndexedDBKey& key, blink::WebIDBPutMode mode, const std::vector<content::IndexedDBIndexKeys>& index_keys, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void SetIndexKeys(int64_t transaction_id, int64_t object_store_id, const content::IndexedDBKey& primary_key, const std::vector<content::IndexedDBIndexKeys>& index_keys) = 0;

        virtual void SetIndexesReady(int64_t transaction_id, int64_t object_store_id, const std::vector<int64_t>& index_ids) = 0;

        virtual void OpenCursor(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const content::IndexedDBKeyRange& key_range, blink::WebIDBCursorDirection direction, bool key_only, blink::WebIDBTaskType task_type, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void Count(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const content::IndexedDBKeyRange& key_range, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void DeleteRange(int64_t transaction_id, int64_t object_store_id, const content::IndexedDBKeyRange& key_range, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void Clear(int64_t transaction_id, int64_t object_store_id, CallbacksAssociatedPtrInfo callbacks) = 0;

        virtual void CreateIndex(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const base::string16& name, const content::IndexedDBKeyPath& key_path, bool unique, bool multi_entry) = 0;

        virtual void DeleteIndex(int64_t transaction_id, int64_t object_store_id, int64_t index_id) = 0;

        virtual void RenameIndex(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const base::string16& new_name) = 0;

        virtual void Abort(int64_t transaction_id) = 0;

        virtual void Commit(int64_t transaction_id) = 0;

        virtual void AckReceivedBlobs(const std::vector<std::string>& uuids) = 0;
    };

    class FactoryProxy;

    template <typename ImplRefTraits>
    class FactoryStub;

    class FactoryRequestValidator;

    class CONTENT_EXPORT Factory
        : public FactoryInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = FactoryProxy;

        template <typename ImplRefTraits>
        using Stub_ = FactoryStub<ImplRefTraits>;

        using RequestValidator_ = FactoryRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kGetDatabaseNamesMinVersion = 0,
            kOpenMinVersion = 0,
            kDeleteDatabaseMinVersion = 0,
        };
        virtual ~Factory() { }

        virtual void GetDatabaseNames(CallbacksAssociatedPtrInfo callbacks, const url::Origin& origin) = 0;

        virtual void Open(CallbacksAssociatedPtrInfo callbacks, DatabaseCallbacksAssociatedPtrInfo database_callbacks, const url::Origin& origin, const base::string16& name, int64_t version, int64_t transaction_id) = 0;

        virtual void DeleteDatabase(CallbacksAssociatedPtrInfo callbacks, const url::Origin& origin, const base::string16& name) = 0;
    };

    class CONTENT_EXPORT CallbacksProxy
        : public Callbacks {
    public:
        explicit CallbacksProxy(mojo::MessageReceiverWithResponder* receiver);
        void Error(int32_t code, const base::string16& message) override;
        void SuccessStringList(const std::vector<base::string16>& value) override;
        void Blocked(int64_t existing_version) override;
        void UpgradeNeeded(DatabaseAssociatedPtrInfo database, int64_t old_version, blink::WebIDBDataLoss data_loss, const std::string& data_loss_message, const content::IndexedDBDatabaseMetadata& db_metadata) override;
        void SuccessDatabase(DatabaseAssociatedPtrInfo database, const content::IndexedDBDatabaseMetadata& metadata) override;
        void SuccessCursor(CursorAssociatedPtrInfo cursor, const content::IndexedDBKey& key, const content::IndexedDBKey& primary_key, ValuePtr value) override;
        void SuccessValue(ReturnValuePtr value) override;
        void SuccessCursorContinue(const content::IndexedDBKey& key, const content::IndexedDBKey& primary_key, ValuePtr value) override;
        void SuccessCursorPrefetch(const std::vector<content::IndexedDBKey>& keys, const std::vector<content::IndexedDBKey>& primary_keys, std::vector<ValuePtr> values) override;
        void SuccessArray(std::vector<ReturnValuePtr> values) override;
        void SuccessKey(const content::IndexedDBKey& key) override;
        void SuccessInteger(int64_t value) override;
        void Success() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT DatabaseCallbacksProxy
        : public DatabaseCallbacks {
    public:
        explicit DatabaseCallbacksProxy(mojo::MessageReceiverWithResponder* receiver);
        void ForcedClose() override;
        void VersionChange(int64_t old_version, int64_t new_version) override;
        void Abort(int64_t transaction_id, int32_t code, const base::string16& message) override;
        void Complete(int64_t transaction_id) override;
        void Changes(ObserverChangesPtr changes) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT CursorProxy
        : public Cursor {
    public:
        explicit CursorProxy(mojo::MessageReceiverWithResponder* receiver);
        void Advance(uint32_t count, CallbacksAssociatedPtrInfo callbacks) override;
        void Continue(const content::IndexedDBKey& key, const content::IndexedDBKey& primary_key, CallbacksAssociatedPtrInfo callbacks) override;
        void Prefetch(int32_t count, CallbacksAssociatedPtrInfo callbacks) override;
        void PrefetchReset(int32_t used_prefetches, int32_t unused_prefetches, const std::vector<std::string>& unused_blob_uuids) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT DatabaseProxy
        : public Database {
    public:
        explicit DatabaseProxy(mojo::MessageReceiverWithResponder* receiver);
        void CreateObjectStore(int64_t transaction_id, int64_t object_store_id, const base::string16& name, const content::IndexedDBKeyPath& key_path, bool auto_increment) override;
        void DeleteObjectStore(int64_t transaction_id, int64_t object_store_id) override;
        void RenameObjectStore(int64_t transaction_id, int64_t object_store_id, const base::string16& new_name) override;
        void CreateTransaction(int64_t transaction_id, const std::vector<int64_t>& object_store_ids, blink::WebIDBTransactionMode mode) override;
        void Close() override;
        void VersionChangeIgnored() override;
        void AddObserver(int64_t transaction_id, int32_t observer_id, bool include_transaction, bool no_records, bool values, uint16_t operation_types) override;
        void RemoveObservers(const std::vector<int32_t>& observers) override;
        void Get(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const content::IndexedDBKeyRange& key_range, bool key_only, CallbacksAssociatedPtrInfo callbacks) override;
        void GetAll(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const content::IndexedDBKeyRange& key_range, bool key_only, int64_t max_count, CallbacksAssociatedPtrInfo callbacks) override;
        void Put(int64_t transaction_id, int64_t object_store_id, ValuePtr value, const content::IndexedDBKey& key, blink::WebIDBPutMode mode, const std::vector<content::IndexedDBIndexKeys>& index_keys, CallbacksAssociatedPtrInfo callbacks) override;
        void SetIndexKeys(int64_t transaction_id, int64_t object_store_id, const content::IndexedDBKey& primary_key, const std::vector<content::IndexedDBIndexKeys>& index_keys) override;
        void SetIndexesReady(int64_t transaction_id, int64_t object_store_id, const std::vector<int64_t>& index_ids) override;
        void OpenCursor(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const content::IndexedDBKeyRange& key_range, blink::WebIDBCursorDirection direction, bool key_only, blink::WebIDBTaskType task_type, CallbacksAssociatedPtrInfo callbacks) override;
        void Count(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const content::IndexedDBKeyRange& key_range, CallbacksAssociatedPtrInfo callbacks) override;
        void DeleteRange(int64_t transaction_id, int64_t object_store_id, const content::IndexedDBKeyRange& key_range, CallbacksAssociatedPtrInfo callbacks) override;
        void Clear(int64_t transaction_id, int64_t object_store_id, CallbacksAssociatedPtrInfo callbacks) override;
        void CreateIndex(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const base::string16& name, const content::IndexedDBKeyPath& key_path, bool unique, bool multi_entry) override;
        void DeleteIndex(int64_t transaction_id, int64_t object_store_id, int64_t index_id) override;
        void RenameIndex(int64_t transaction_id, int64_t object_store_id, int64_t index_id, const base::string16& new_name) override;
        void Abort(int64_t transaction_id) override;
        void Commit(int64_t transaction_id) override;
        void AckReceivedBlobs(const std::vector<std::string>& uuids) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class CONTENT_EXPORT FactoryProxy
        : public Factory {
    public:
        explicit FactoryProxy(mojo::MessageReceiverWithResponder* receiver);
        void GetDatabaseNames(CallbacksAssociatedPtrInfo callbacks, const url::Origin& origin) override;
        void Open(CallbacksAssociatedPtrInfo callbacks, DatabaseCallbacksAssociatedPtrInfo database_callbacks, const url::Origin& origin, const base::string16& name, int64_t version, int64_t transaction_id) override;
        void DeleteDatabase(CallbacksAssociatedPtrInfo callbacks, const url::Origin& origin, const base::string16& name) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT CallbacksStubDispatch {
    public:
        static bool Accept(Callbacks* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Callbacks* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Callbacks>>
    class CallbacksStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        CallbacksStub() { }
        ~CallbacksStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return CallbacksStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return CallbacksStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT DatabaseCallbacksStubDispatch {
    public:
        static bool Accept(DatabaseCallbacks* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DatabaseCallbacks* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DatabaseCallbacks>>
    class DatabaseCallbacksStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DatabaseCallbacksStub() { }
        ~DatabaseCallbacksStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DatabaseCallbacksStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DatabaseCallbacksStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT CursorStubDispatch {
    public:
        static bool Accept(Cursor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Cursor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Cursor>>
    class CursorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        CursorStub() { }
        ~CursorStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return CursorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return CursorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT DatabaseStubDispatch {
    public:
        static bool Accept(Database* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Database* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Database>>
    class DatabaseStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DatabaseStub() { }
        ~DatabaseStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DatabaseStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DatabaseStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT FactoryStubDispatch {
    public:
        static bool Accept(Factory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Factory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Factory>>
    class FactoryStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        FactoryStub() { }
        ~FactoryStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return FactoryStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return FactoryStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT CallbacksRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT DatabaseCallbacksRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT CursorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT DatabaseRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT FactoryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CONTENT_EXPORT KeyData {
    public:
        using DataView = KeyDataDataView;
        using Data_ = internal::KeyData_Data;
        using Tag = Data_::KeyData_Tag;

        static KeyDataPtr New();

        template <typename U>
        static KeyDataPtr From(const U& u)
        {
            return mojo::TypeConverter<KeyDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, KeyData>::Convert(*this);
        }

        KeyData();
        ~KeyData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename UnionPtrType = KeyDataPtr>
        KeyDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, KeyData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        Tag which() const
        {
            return tag_;
        }

        bool is_key_array() const { return tag_ == Tag::KEY_ARRAY; }

        std::vector<content::IndexedDBKey>& get_key_array() const
        {
            DCHECK(tag_ == Tag::KEY_ARRAY);
            return *(data_.key_array);
        }

        void set_key_array(const std::vector<content::IndexedDBKey>& key_array);
        bool is_binary() const { return tag_ == Tag::BINARY; }

        std::vector<uint8_t>& get_binary() const
        {
            DCHECK(tag_ == Tag::BINARY);
            return *(data_.binary);
        }

        void set_binary(const std::vector<uint8_t>& binary);
        bool is_string() const { return tag_ == Tag::STRING; }

        base::string16& get_string() const
        {
            DCHECK(tag_ == Tag::STRING);
            return *(data_.string);
        }

        void set_string(const base::string16& string);
        bool is_date() const { return tag_ == Tag::DATE; }

        double get_date() const
        {
            DCHECK(tag_ == Tag::DATE);
            return data_.date;
        }

        void set_date(double date);
        bool is_number() const { return tag_ == Tag::NUMBER; }

        double get_number() const
        {
            DCHECK(tag_ == Tag::NUMBER);
            return data_.number;
        }

        void set_number(double number);
        bool is_other() const { return tag_ == Tag::OTHER; }

        DatalessKeyType get_other() const
        {
            DCHECK(tag_ == Tag::OTHER);
            return data_.other;
        }

        void set_other(DatalessKeyType other);

    private:
        friend class mojo::internal::UnionAccessor<KeyData>;
        union Union_ {
            Union_() { }
            ~Union_() { }
            std::vector<content::IndexedDBKey>* key_array;
            std::vector<uint8_t>* binary;
            base::string16* string;
            double date;
            double number;
            DatalessKeyType other;
        };
        void SwitchActive(Tag new_active);
        void SetActive(Tag new_active);
        void DestroyActive();
        Tag tag_;
        Union_ data_;
    };
    class CONTENT_EXPORT KeyPathData {
    public:
        using DataView = KeyPathDataDataView;
        using Data_ = internal::KeyPathData_Data;
        using Tag = Data_::KeyPathData_Tag;

        static KeyPathDataPtr New();

        template <typename U>
        static KeyPathDataPtr From(const U& u)
        {
            return mojo::TypeConverter<KeyPathDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, KeyPathData>::Convert(*this);
        }

        KeyPathData();
        ~KeyPathData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename UnionPtrType = KeyPathDataPtr>
        KeyPathDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, KeyPathData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        Tag which() const
        {
            return tag_;
        }

        bool is_string() const { return tag_ == Tag::STRING; }

        base::string16& get_string() const
        {
            DCHECK(tag_ == Tag::STRING);
            return *(data_.string);
        }

        void set_string(const base::string16& string);
        bool is_string_array() const { return tag_ == Tag::STRING_ARRAY; }

        std::vector<base::string16>& get_string_array() const
        {
            DCHECK(tag_ == Tag::STRING_ARRAY);
            return *(data_.string_array);
        }

        void set_string_array(const std::vector<base::string16>& string_array);

    private:
        friend class mojo::internal::UnionAccessor<KeyPathData>;
        union Union_ {
            Union_() { }
            ~Union_() { }
            base::string16* string;
            std::vector<base::string16>* string_array;
        };
        void SwitchActive(Tag new_active);
        void SetActive(Tag new_active);
        void DestroyActive();
        Tag tag_;
        Union_ data_;
    };

    class CONTENT_EXPORT Key {
    public:
        using DataView = KeyDataView;
        using Data_ = internal::Key_Data;

        static KeyPtr New();

        template <typename U>
        static KeyPtr From(const U& u)
        {
            return mojo::TypeConverter<KeyPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Key>::Convert(*this);
        }

        Key();
        ~Key();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = KeyPtr>
        KeyPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Key>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Key::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Key::DataView, std::vector<uint8_t>>(
                input, output);
        }

        KeyDataPtr data;

    private:
        DISALLOW_COPY_AND_ASSIGN(Key);
    };

    class CONTENT_EXPORT KeyPath {
    public:
        using DataView = KeyPathDataView;
        using Data_ = internal::KeyPath_Data;

        static KeyPathPtr New();

        template <typename U>
        static KeyPathPtr From(const U& u)
        {
            return mojo::TypeConverter<KeyPathPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, KeyPath>::Convert(*this);
        }

        KeyPath();
        ~KeyPath();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = KeyPathPtr>
        KeyPathPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, KeyPath>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                KeyPath::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                KeyPath::DataView, std::vector<uint8_t>>(
                input, output);
        }

        KeyPathDataPtr data;

    private:
        DISALLOW_COPY_AND_ASSIGN(KeyPath);
    };

    class CONTENT_EXPORT KeyRange {
    public:
        using DataView = KeyRangeDataView;
        using Data_ = internal::KeyRange_Data;

        static KeyRangePtr New();

        template <typename U>
        static KeyRangePtr From(const U& u)
        {
            return mojo::TypeConverter<KeyRangePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, KeyRange>::Convert(*this);
        }

        KeyRange();
        ~KeyRange();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = KeyRangePtr>
        KeyRangePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, KeyRange>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                KeyRange::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                KeyRange::DataView, std::vector<uint8_t>>(
                input, output);
        }

        content::IndexedDBKey lower;
        content::IndexedDBKey upper;
        bool lower_open;
        bool upper_open;
    };

    class CONTENT_EXPORT IndexMetadata {
    public:
        using DataView = IndexMetadataDataView;
        using Data_ = internal::IndexMetadata_Data;

        static IndexMetadataPtr New();

        template <typename U>
        static IndexMetadataPtr From(const U& u)
        {
            return mojo::TypeConverter<IndexMetadataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, IndexMetadata>::Convert(*this);
        }

        IndexMetadata();
        ~IndexMetadata();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = IndexMetadataPtr>
        IndexMetadataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, IndexMetadata>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                IndexMetadata::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                IndexMetadata::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int64_t id;
        base::string16 name;
        content::IndexedDBKeyPath key_path;
        bool unique;
        bool multi_entry;
    };

    class CONTENT_EXPORT ObjectStoreMetadata {
    public:
        using DataView = ObjectStoreMetadataDataView;
        using Data_ = internal::ObjectStoreMetadata_Data;

        static ObjectStoreMetadataPtr New();

        template <typename U>
        static ObjectStoreMetadataPtr From(const U& u)
        {
            return mojo::TypeConverter<ObjectStoreMetadataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ObjectStoreMetadata>::Convert(*this);
        }

        ObjectStoreMetadata();
        ~ObjectStoreMetadata();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ObjectStoreMetadataPtr>
        ObjectStoreMetadataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ObjectStoreMetadata>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ObjectStoreMetadata::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ObjectStoreMetadata::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int64_t id;
        base::string16 name;
        content::IndexedDBKeyPath key_path;
        bool auto_increment;
        int64_t max_index_id;
        std::vector<content::IndexedDBIndexMetadata> indexes;
    };

    class CONTENT_EXPORT DatabaseMetadata {
    public:
        using DataView = DatabaseMetadataDataView;
        using Data_ = internal::DatabaseMetadata_Data;

        static DatabaseMetadataPtr New();

        template <typename U>
        static DatabaseMetadataPtr From(const U& u)
        {
            return mojo::TypeConverter<DatabaseMetadataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, DatabaseMetadata>::Convert(*this);
        }

        DatabaseMetadata();
        ~DatabaseMetadata();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = DatabaseMetadataPtr>
        DatabaseMetadataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, DatabaseMetadata>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                DatabaseMetadata::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                DatabaseMetadata::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int64_t id;
        base::string16 name;
        int64_t version;
        int64_t max_object_store_id;
        std::vector<content::IndexedDBObjectStoreMetadata> object_stores;
    };

    class CONTENT_EXPORT IndexKeys {
    public:
        using DataView = IndexKeysDataView;
        using Data_ = internal::IndexKeys_Data;

        static IndexKeysPtr New();

        template <typename U>
        static IndexKeysPtr From(const U& u)
        {
            return mojo::TypeConverter<IndexKeysPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, IndexKeys>::Convert(*this);
        }

        IndexKeys();
        ~IndexKeys();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = IndexKeysPtr>
        IndexKeysPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, IndexKeys>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                IndexKeys::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                IndexKeys::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int64_t index_id;
        std::vector<content::IndexedDBKey> index_keys;
    };

    class CONTENT_EXPORT FileInfo {
    public:
        using DataView = FileInfoDataView;
        using Data_ = internal::FileInfo_Data;

        static FileInfoPtr New();

        template <typename U>
        static FileInfoPtr From(const U& u)
        {
            return mojo::TypeConverter<FileInfoPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FileInfo>::Convert(*this);
        }

        FileInfo();
        ~FileInfo();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FileInfoPtr>
        FileInfoPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FileInfo>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FileInfo::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FileInfo::DataView, std::vector<uint8_t>>(
                input, output);
        }

        base::FilePath path;
        base::string16 name;
        base::Time last_modified;
    };

    class CONTENT_EXPORT BlobInfo {
    public:
        using DataView = BlobInfoDataView;
        using Data_ = internal::BlobInfo_Data;

        static BlobInfoPtr New();

        template <typename U>
        static BlobInfoPtr From(const U& u)
        {
            return mojo::TypeConverter<BlobInfoPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, BlobInfo>::Convert(*this);
        }

        BlobInfo();
        ~BlobInfo();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = BlobInfoPtr>
        BlobInfoPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, BlobInfo>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                BlobInfo::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                BlobInfo::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string uuid;
        base::string16 mime_type;
        int64_t size;
        FileInfoPtr file;

    private:
        DISALLOW_COPY_AND_ASSIGN(BlobInfo);
    };

    class CONTENT_EXPORT Value {
    public:
        using DataView = ValueDataView;
        using Data_ = internal::Value_Data;

        static ValuePtr New();

        template <typename U>
        static ValuePtr From(const U& u)
        {
            return mojo::TypeConverter<ValuePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Value>::Convert(*this);
        }

        Value();
        ~Value();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ValuePtr>
        ValuePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Value>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Value::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Value::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string bits;
        std::vector<BlobInfoPtr> blob_or_file_info;

    private:
        DISALLOW_COPY_AND_ASSIGN(Value);
    };

    class CONTENT_EXPORT ReturnValue {
    public:
        using DataView = ReturnValueDataView;
        using Data_ = internal::ReturnValue_Data;

        static ReturnValuePtr New();

        template <typename U>
        static ReturnValuePtr From(const U& u)
        {
            return mojo::TypeConverter<ReturnValuePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ReturnValue>::Convert(*this);
        }

        ReturnValue();
        ~ReturnValue();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ReturnValuePtr>
        ReturnValuePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ReturnValue>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ReturnValue::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ReturnValue::DataView, std::vector<uint8_t>>(
                input, output);
        }

        ValuePtr value;
        content::IndexedDBKey primary_key;
        content::IndexedDBKeyPath key_path;

    private:
        DISALLOW_COPY_AND_ASSIGN(ReturnValue);
    };

    class CONTENT_EXPORT Observation {
    public:
        using DataView = ObservationDataView;
        using Data_ = internal::Observation_Data;

        static ObservationPtr New();

        template <typename U>
        static ObservationPtr From(const U& u)
        {
            return mojo::TypeConverter<ObservationPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Observation>::Convert(*this);
        }

        Observation();
        ~Observation();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ObservationPtr>
        ObservationPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Observation>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Observation::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Observation::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int64_t object_store_id;
        blink::WebIDBOperationType type;
        content::IndexedDBKeyRange key_range;
        ValuePtr value;

    private:
        DISALLOW_COPY_AND_ASSIGN(Observation);
    };

    class CONTENT_EXPORT ObserverTransaction {
    public:
        using DataView = ObserverTransactionDataView;
        using Data_ = internal::ObserverTransaction_Data;

        static ObserverTransactionPtr New();

        template <typename U>
        static ObserverTransactionPtr From(const U& u)
        {
            return mojo::TypeConverter<ObserverTransactionPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ObserverTransaction>::Convert(*this);
        }

        ObserverTransaction();
        ~ObserverTransaction();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ObserverTransactionPtr>
        ObserverTransactionPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ObserverTransaction>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ObserverTransaction::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ObserverTransaction::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int64_t id;
        std::vector<int64_t> scope;
    };

    class CONTENT_EXPORT ObserverChanges {
    public:
        using DataView = ObserverChangesDataView;
        using Data_ = internal::ObserverChanges_Data;

        static ObserverChangesPtr New();

        template <typename U>
        static ObserverChangesPtr From(const U& u)
        {
            return mojo::TypeConverter<ObserverChangesPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ObserverChanges>::Convert(*this);
        }

        ObserverChanges();
        ~ObserverChanges();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ObserverChangesPtr>
        ObserverChangesPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ObserverChanges>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ObserverChanges::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ObserverChanges::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::unordered_map<int32_t, std::vector<int32_t>> observation_index_map;
        std::unordered_map<int32_t, ObserverTransactionPtr> transaction_map;
        std::vector<ObservationPtr> observations;

    private:
        DISALLOW_COPY_AND_ASSIGN(ObserverChanges);
    };

    template <typename UnionPtrType>
    KeyDataPtr KeyData::Clone() const
    {
        // Use UnionPtrType to prevent the compiler from trying to compile this
        // without being asked.
        UnionPtrType rv(New());
        switch (tag_) {
        case Tag::KEY_ARRAY:
            rv->set_key_array(mojo::internal::Clone(*data_.key_array));
            break;
        case Tag::BINARY:
            rv->set_binary(mojo::internal::Clone(*data_.binary));
            break;
        case Tag::STRING:
            rv->set_string(mojo::internal::Clone(*data_.string));
            break;
        case Tag::DATE:
            rv->set_date(mojo::internal::Clone(data_.date));
            break;
        case Tag::NUMBER:
            rv->set_number(mojo::internal::Clone(data_.number));
            break;
        case Tag::OTHER:
            rv->set_other(mojo::internal::Clone(data_.other));
            break;
        };
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, KeyData>::value>::type*>
    bool KeyData::Equals(const T& other) const
    {
        if (tag_ != other.which())
            return false;

        switch (tag_) {
        case Tag::KEY_ARRAY:
            return mojo::internal::Equals(*(data_.key_array), *(other.data_.key_array));
        case Tag::BINARY:
            return mojo::internal::Equals(*(data_.binary), *(other.data_.binary));
        case Tag::STRING:
            return mojo::internal::Equals(*(data_.string), *(other.data_.string));
        case Tag::DATE:
            return mojo::internal::Equals(data_.date, other.data_.date);
        case Tag::NUMBER:
            return mojo::internal::Equals(data_.number, other.data_.number);
        case Tag::OTHER:
            return mojo::internal::Equals(data_.other, other.data_.other);
        };

        return false;
    }
    template <typename UnionPtrType>
    KeyPathDataPtr KeyPathData::Clone() const
    {
        // Use UnionPtrType to prevent the compiler from trying to compile this
        // without being asked.
        UnionPtrType rv(New());
        switch (tag_) {
        case Tag::STRING:
            rv->set_string(mojo::internal::Clone(*data_.string));
            break;
        case Tag::STRING_ARRAY:
            rv->set_string_array(mojo::internal::Clone(*data_.string_array));
            break;
        };
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, KeyPathData>::value>::type*>
    bool KeyPathData::Equals(const T& other) const
    {
        if (tag_ != other.which())
            return false;

        switch (tag_) {
        case Tag::STRING:
            return mojo::internal::Equals(*(data_.string), *(other.data_.string));
        case Tag::STRING_ARRAY:
            return mojo::internal::Equals(*(data_.string_array), *(other.data_.string_array));
        };

        return false;
    }
    template <typename StructPtrType>
    KeyPtr Key::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->data = mojo::internal::Clone(data);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Key>::value>::type*>
    bool Key::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->data, other.data))
            return false;
        return true;
    }
    template <typename StructPtrType>
    KeyPathPtr KeyPath::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->data = mojo::internal::Clone(data);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, KeyPath>::value>::type*>
    bool KeyPath::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->data, other.data))
            return false;
        return true;
    }
    template <typename StructPtrType>
    KeyRangePtr KeyRange::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->lower = mojo::internal::Clone(lower);
        rv->upper = mojo::internal::Clone(upper);
        rv->lower_open = mojo::internal::Clone(lower_open);
        rv->upper_open = mojo::internal::Clone(upper_open);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, KeyRange>::value>::type*>
    bool KeyRange::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->lower, other.lower))
            return false;
        if (!mojo::internal::Equals(this->upper, other.upper))
            return false;
        if (!mojo::internal::Equals(this->lower_open, other.lower_open))
            return false;
        if (!mojo::internal::Equals(this->upper_open, other.upper_open))
            return false;
        return true;
    }
    template <typename StructPtrType>
    IndexMetadataPtr IndexMetadata::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        rv->name = mojo::internal::Clone(name);
        rv->key_path = mojo::internal::Clone(key_path);
        rv->unique = mojo::internal::Clone(unique);
        rv->multi_entry = mojo::internal::Clone(multi_entry);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, IndexMetadata>::value>::type*>
    bool IndexMetadata::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->key_path, other.key_path))
            return false;
        if (!mojo::internal::Equals(this->unique, other.unique))
            return false;
        if (!mojo::internal::Equals(this->multi_entry, other.multi_entry))
            return false;
        return true;
    }
    template <typename StructPtrType>
    ObjectStoreMetadataPtr ObjectStoreMetadata::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        rv->name = mojo::internal::Clone(name);
        rv->key_path = mojo::internal::Clone(key_path);
        rv->auto_increment = mojo::internal::Clone(auto_increment);
        rv->max_index_id = mojo::internal::Clone(max_index_id);
        rv->indexes = mojo::internal::Clone(indexes);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ObjectStoreMetadata>::value>::type*>
    bool ObjectStoreMetadata::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->key_path, other.key_path))
            return false;
        if (!mojo::internal::Equals(this->auto_increment, other.auto_increment))
            return false;
        if (!mojo::internal::Equals(this->max_index_id, other.max_index_id))
            return false;
        if (!mojo::internal::Equals(this->indexes, other.indexes))
            return false;
        return true;
    }
    template <typename StructPtrType>
    DatabaseMetadataPtr DatabaseMetadata::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        rv->name = mojo::internal::Clone(name);
        rv->version = mojo::internal::Clone(version);
        rv->max_object_store_id = mojo::internal::Clone(max_object_store_id);
        rv->object_stores = mojo::internal::Clone(object_stores);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, DatabaseMetadata>::value>::type*>
    bool DatabaseMetadata::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->version, other.version))
            return false;
        if (!mojo::internal::Equals(this->max_object_store_id, other.max_object_store_id))
            return false;
        if (!mojo::internal::Equals(this->object_stores, other.object_stores))
            return false;
        return true;
    }
    template <typename StructPtrType>
    IndexKeysPtr IndexKeys::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->index_id = mojo::internal::Clone(index_id);
        rv->index_keys = mojo::internal::Clone(index_keys);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, IndexKeys>::value>::type*>
    bool IndexKeys::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->index_id, other.index_id))
            return false;
        if (!mojo::internal::Equals(this->index_keys, other.index_keys))
            return false;
        return true;
    }
    template <typename StructPtrType>
    FileInfoPtr FileInfo::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->path = mojo::internal::Clone(path);
        rv->name = mojo::internal::Clone(name);
        rv->last_modified = mojo::internal::Clone(last_modified);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FileInfo>::value>::type*>
    bool FileInfo::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->path, other.path))
            return false;
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->last_modified, other.last_modified))
            return false;
        return true;
    }
    template <typename StructPtrType>
    BlobInfoPtr BlobInfo::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->uuid = mojo::internal::Clone(uuid);
        rv->mime_type = mojo::internal::Clone(mime_type);
        rv->size = mojo::internal::Clone(size);
        rv->file = mojo::internal::Clone(file);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, BlobInfo>::value>::type*>
    bool BlobInfo::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->uuid, other.uuid))
            return false;
        if (!mojo::internal::Equals(this->mime_type, other.mime_type))
            return false;
        if (!mojo::internal::Equals(this->size, other.size))
            return false;
        if (!mojo::internal::Equals(this->file, other.file))
            return false;
        return true;
    }
    template <typename StructPtrType>
    ValuePtr Value::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->bits = mojo::internal::Clone(bits);
        rv->blob_or_file_info = mojo::internal::Clone(blob_or_file_info);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Value>::value>::type*>
    bool Value::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->bits, other.bits))
            return false;
        if (!mojo::internal::Equals(this->blob_or_file_info, other.blob_or_file_info))
            return false;
        return true;
    }
    template <typename StructPtrType>
    ReturnValuePtr ReturnValue::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->value = mojo::internal::Clone(value);
        rv->primary_key = mojo::internal::Clone(primary_key);
        rv->key_path = mojo::internal::Clone(key_path);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ReturnValue>::value>::type*>
    bool ReturnValue::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        if (!mojo::internal::Equals(this->primary_key, other.primary_key))
            return false;
        if (!mojo::internal::Equals(this->key_path, other.key_path))
            return false;
        return true;
    }
    template <typename StructPtrType>
    ObservationPtr Observation::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->object_store_id = mojo::internal::Clone(object_store_id);
        rv->type = mojo::internal::Clone(type);
        rv->key_range = mojo::internal::Clone(key_range);
        rv->value = mojo::internal::Clone(value);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Observation>::value>::type*>
    bool Observation::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->object_store_id, other.object_store_id))
            return false;
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->key_range, other.key_range))
            return false;
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        return true;
    }
    template <typename StructPtrType>
    ObserverTransactionPtr ObserverTransaction::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        rv->scope = mojo::internal::Clone(scope);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ObserverTransaction>::value>::type*>
    bool ObserverTransaction::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->scope, other.scope))
            return false;
        return true;
    }
    template <typename StructPtrType>
    ObserverChangesPtr ObserverChanges::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->observation_index_map = mojo::internal::Clone(observation_index_map);
        rv->transaction_map = mojo::internal::Clone(transaction_map);
        rv->observations = mojo::internal::Clone(observations);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ObserverChanges>::value>::type*>
    bool ObserverChanges::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->observation_index_map, other.observation_index_map))
            return false;
        if (!mojo::internal::Equals(this->transaction_map, other.transaction_map))
            return false;
        if (!mojo::internal::Equals(this->observations, other.observations))
            return false;
        return true;
    }

} // namespace mojom
} // namespace indexed_db

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::Key::DataView,
    ::indexed_db::mojom::KeyPtr> {
    static bool IsNull(const ::indexed_db::mojom::KeyPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::KeyPtr* output) { output->reset(); }

    static const decltype(::indexed_db::mojom::Key::data)& data(
        const ::indexed_db::mojom::KeyPtr& input)
    {
        return input->data;
    }

    static bool Read(::indexed_db::mojom::Key::DataView input, ::indexed_db::mojom::KeyPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::KeyPath::DataView,
    ::indexed_db::mojom::KeyPathPtr> {
    static bool IsNull(const ::indexed_db::mojom::KeyPathPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::KeyPathPtr* output) { output->reset(); }

    static const decltype(::indexed_db::mojom::KeyPath::data)& data(
        const ::indexed_db::mojom::KeyPathPtr& input)
    {
        return input->data;
    }

    static bool Read(::indexed_db::mojom::KeyPath::DataView input, ::indexed_db::mojom::KeyPathPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::KeyRange::DataView,
    ::indexed_db::mojom::KeyRangePtr> {
    static bool IsNull(const ::indexed_db::mojom::KeyRangePtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::KeyRangePtr* output) { output->reset(); }

    static const decltype(::indexed_db::mojom::KeyRange::lower)& lower(
        const ::indexed_db::mojom::KeyRangePtr& input)
    {
        return input->lower;
    }

    static const decltype(::indexed_db::mojom::KeyRange::upper)& upper(
        const ::indexed_db::mojom::KeyRangePtr& input)
    {
        return input->upper;
    }

    static decltype(::indexed_db::mojom::KeyRange::lower_open) lower_open(
        const ::indexed_db::mojom::KeyRangePtr& input)
    {
        return input->lower_open;
    }

    static decltype(::indexed_db::mojom::KeyRange::upper_open) upper_open(
        const ::indexed_db::mojom::KeyRangePtr& input)
    {
        return input->upper_open;
    }

    static bool Read(::indexed_db::mojom::KeyRange::DataView input, ::indexed_db::mojom::KeyRangePtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::IndexMetadata::DataView,
    ::indexed_db::mojom::IndexMetadataPtr> {
    static bool IsNull(const ::indexed_db::mojom::IndexMetadataPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::IndexMetadataPtr* output) { output->reset(); }

    static decltype(::indexed_db::mojom::IndexMetadata::id) id(
        const ::indexed_db::mojom::IndexMetadataPtr& input)
    {
        return input->id;
    }

    static const decltype(::indexed_db::mojom::IndexMetadata::name)& name(
        const ::indexed_db::mojom::IndexMetadataPtr& input)
    {
        return input->name;
    }

    static const decltype(::indexed_db::mojom::IndexMetadata::key_path)& key_path(
        const ::indexed_db::mojom::IndexMetadataPtr& input)
    {
        return input->key_path;
    }

    static decltype(::indexed_db::mojom::IndexMetadata::unique) unique(
        const ::indexed_db::mojom::IndexMetadataPtr& input)
    {
        return input->unique;
    }

    static decltype(::indexed_db::mojom::IndexMetadata::multi_entry) multi_entry(
        const ::indexed_db::mojom::IndexMetadataPtr& input)
    {
        return input->multi_entry;
    }

    static bool Read(::indexed_db::mojom::IndexMetadata::DataView input, ::indexed_db::mojom::IndexMetadataPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::ObjectStoreMetadata::DataView,
    ::indexed_db::mojom::ObjectStoreMetadataPtr> {
    static bool IsNull(const ::indexed_db::mojom::ObjectStoreMetadataPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::ObjectStoreMetadataPtr* output) { output->reset(); }

    static decltype(::indexed_db::mojom::ObjectStoreMetadata::id) id(
        const ::indexed_db::mojom::ObjectStoreMetadataPtr& input)
    {
        return input->id;
    }

    static const decltype(::indexed_db::mojom::ObjectStoreMetadata::name)& name(
        const ::indexed_db::mojom::ObjectStoreMetadataPtr& input)
    {
        return input->name;
    }

    static const decltype(::indexed_db::mojom::ObjectStoreMetadata::key_path)& key_path(
        const ::indexed_db::mojom::ObjectStoreMetadataPtr& input)
    {
        return input->key_path;
    }

    static decltype(::indexed_db::mojom::ObjectStoreMetadata::auto_increment) auto_increment(
        const ::indexed_db::mojom::ObjectStoreMetadataPtr& input)
    {
        return input->auto_increment;
    }

    static decltype(::indexed_db::mojom::ObjectStoreMetadata::max_index_id) max_index_id(
        const ::indexed_db::mojom::ObjectStoreMetadataPtr& input)
    {
        return input->max_index_id;
    }

    static const decltype(::indexed_db::mojom::ObjectStoreMetadata::indexes)& indexes(
        const ::indexed_db::mojom::ObjectStoreMetadataPtr& input)
    {
        return input->indexes;
    }

    static bool Read(::indexed_db::mojom::ObjectStoreMetadata::DataView input, ::indexed_db::mojom::ObjectStoreMetadataPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::DatabaseMetadata::DataView,
    ::indexed_db::mojom::DatabaseMetadataPtr> {
    static bool IsNull(const ::indexed_db::mojom::DatabaseMetadataPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::DatabaseMetadataPtr* output) { output->reset(); }

    static decltype(::indexed_db::mojom::DatabaseMetadata::id) id(
        const ::indexed_db::mojom::DatabaseMetadataPtr& input)
    {
        return input->id;
    }

    static const decltype(::indexed_db::mojom::DatabaseMetadata::name)& name(
        const ::indexed_db::mojom::DatabaseMetadataPtr& input)
    {
        return input->name;
    }

    static decltype(::indexed_db::mojom::DatabaseMetadata::version) version(
        const ::indexed_db::mojom::DatabaseMetadataPtr& input)
    {
        return input->version;
    }

    static decltype(::indexed_db::mojom::DatabaseMetadata::max_object_store_id) max_object_store_id(
        const ::indexed_db::mojom::DatabaseMetadataPtr& input)
    {
        return input->max_object_store_id;
    }

    static const decltype(::indexed_db::mojom::DatabaseMetadata::object_stores)& object_stores(
        const ::indexed_db::mojom::DatabaseMetadataPtr& input)
    {
        return input->object_stores;
    }

    static bool Read(::indexed_db::mojom::DatabaseMetadata::DataView input, ::indexed_db::mojom::DatabaseMetadataPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::IndexKeys::DataView,
    ::indexed_db::mojom::IndexKeysPtr> {
    static bool IsNull(const ::indexed_db::mojom::IndexKeysPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::IndexKeysPtr* output) { output->reset(); }

    static decltype(::indexed_db::mojom::IndexKeys::index_id) index_id(
        const ::indexed_db::mojom::IndexKeysPtr& input)
    {
        return input->index_id;
    }

    static const decltype(::indexed_db::mojom::IndexKeys::index_keys)& index_keys(
        const ::indexed_db::mojom::IndexKeysPtr& input)
    {
        return input->index_keys;
    }

    static bool Read(::indexed_db::mojom::IndexKeys::DataView input, ::indexed_db::mojom::IndexKeysPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::FileInfo::DataView,
    ::indexed_db::mojom::FileInfoPtr> {
    static bool IsNull(const ::indexed_db::mojom::FileInfoPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::FileInfoPtr* output) { output->reset(); }

    static const decltype(::indexed_db::mojom::FileInfo::path)& path(
        const ::indexed_db::mojom::FileInfoPtr& input)
    {
        return input->path;
    }

    static const decltype(::indexed_db::mojom::FileInfo::name)& name(
        const ::indexed_db::mojom::FileInfoPtr& input)
    {
        return input->name;
    }

    static const decltype(::indexed_db::mojom::FileInfo::last_modified)& last_modified(
        const ::indexed_db::mojom::FileInfoPtr& input)
    {
        return input->last_modified;
    }

    static bool Read(::indexed_db::mojom::FileInfo::DataView input, ::indexed_db::mojom::FileInfoPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::BlobInfo::DataView,
    ::indexed_db::mojom::BlobInfoPtr> {
    static bool IsNull(const ::indexed_db::mojom::BlobInfoPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::BlobInfoPtr* output) { output->reset(); }

    static const decltype(::indexed_db::mojom::BlobInfo::uuid)& uuid(
        const ::indexed_db::mojom::BlobInfoPtr& input)
    {
        return input->uuid;
    }

    static const decltype(::indexed_db::mojom::BlobInfo::mime_type)& mime_type(
        const ::indexed_db::mojom::BlobInfoPtr& input)
    {
        return input->mime_type;
    }

    static decltype(::indexed_db::mojom::BlobInfo::size) size(
        const ::indexed_db::mojom::BlobInfoPtr& input)
    {
        return input->size;
    }

    static const decltype(::indexed_db::mojom::BlobInfo::file)& file(
        const ::indexed_db::mojom::BlobInfoPtr& input)
    {
        return input->file;
    }

    static bool Read(::indexed_db::mojom::BlobInfo::DataView input, ::indexed_db::mojom::BlobInfoPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::Value::DataView,
    ::indexed_db::mojom::ValuePtr> {
    static bool IsNull(const ::indexed_db::mojom::ValuePtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::ValuePtr* output) { output->reset(); }

    static const decltype(::indexed_db::mojom::Value::bits)& bits(
        const ::indexed_db::mojom::ValuePtr& input)
    {
        return input->bits;
    }

    static const decltype(::indexed_db::mojom::Value::blob_or_file_info)& blob_or_file_info(
        const ::indexed_db::mojom::ValuePtr& input)
    {
        return input->blob_or_file_info;
    }

    static bool Read(::indexed_db::mojom::Value::DataView input, ::indexed_db::mojom::ValuePtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::ReturnValue::DataView,
    ::indexed_db::mojom::ReturnValuePtr> {
    static bool IsNull(const ::indexed_db::mojom::ReturnValuePtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::ReturnValuePtr* output) { output->reset(); }

    static const decltype(::indexed_db::mojom::ReturnValue::value)& value(
        const ::indexed_db::mojom::ReturnValuePtr& input)
    {
        return input->value;
    }

    static const decltype(::indexed_db::mojom::ReturnValue::primary_key)& primary_key(
        const ::indexed_db::mojom::ReturnValuePtr& input)
    {
        return input->primary_key;
    }

    static const decltype(::indexed_db::mojom::ReturnValue::key_path)& key_path(
        const ::indexed_db::mojom::ReturnValuePtr& input)
    {
        return input->key_path;
    }

    static bool Read(::indexed_db::mojom::ReturnValue::DataView input, ::indexed_db::mojom::ReturnValuePtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::Observation::DataView,
    ::indexed_db::mojom::ObservationPtr> {
    static bool IsNull(const ::indexed_db::mojom::ObservationPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::ObservationPtr* output) { output->reset(); }

    static decltype(::indexed_db::mojom::Observation::object_store_id) object_store_id(
        const ::indexed_db::mojom::ObservationPtr& input)
    {
        return input->object_store_id;
    }

    static decltype(::indexed_db::mojom::Observation::type) type(
        const ::indexed_db::mojom::ObservationPtr& input)
    {
        return input->type;
    }

    static const decltype(::indexed_db::mojom::Observation::key_range)& key_range(
        const ::indexed_db::mojom::ObservationPtr& input)
    {
        return input->key_range;
    }

    static const decltype(::indexed_db::mojom::Observation::value)& value(
        const ::indexed_db::mojom::ObservationPtr& input)
    {
        return input->value;
    }

    static bool Read(::indexed_db::mojom::Observation::DataView input, ::indexed_db::mojom::ObservationPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::ObserverTransaction::DataView,
    ::indexed_db::mojom::ObserverTransactionPtr> {
    static bool IsNull(const ::indexed_db::mojom::ObserverTransactionPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::ObserverTransactionPtr* output) { output->reset(); }

    static decltype(::indexed_db::mojom::ObserverTransaction::id) id(
        const ::indexed_db::mojom::ObserverTransactionPtr& input)
    {
        return input->id;
    }

    static const decltype(::indexed_db::mojom::ObserverTransaction::scope)& scope(
        const ::indexed_db::mojom::ObserverTransactionPtr& input)
    {
        return input->scope;
    }

    static bool Read(::indexed_db::mojom::ObserverTransaction::DataView input, ::indexed_db::mojom::ObserverTransactionPtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::indexed_db::mojom::ObserverChanges::DataView,
    ::indexed_db::mojom::ObserverChangesPtr> {
    static bool IsNull(const ::indexed_db::mojom::ObserverChangesPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::ObserverChangesPtr* output) { output->reset(); }

    static const decltype(::indexed_db::mojom::ObserverChanges::observation_index_map)& observation_index_map(
        const ::indexed_db::mojom::ObserverChangesPtr& input)
    {
        return input->observation_index_map;
    }

    static const decltype(::indexed_db::mojom::ObserverChanges::transaction_map)& transaction_map(
        const ::indexed_db::mojom::ObserverChangesPtr& input)
    {
        return input->transaction_map;
    }

    static const decltype(::indexed_db::mojom::ObserverChanges::observations)& observations(
        const ::indexed_db::mojom::ObserverChangesPtr& input)
    {
        return input->observations;
    }

    static bool Read(::indexed_db::mojom::ObserverChanges::DataView input, ::indexed_db::mojom::ObserverChangesPtr* output);
};

template <>
struct CONTENT_EXPORT UnionTraits<::indexed_db::mojom::KeyData::DataView,
    ::indexed_db::mojom::KeyDataPtr> {
    static bool IsNull(const ::indexed_db::mojom::KeyDataPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::KeyDataPtr* output) { output->reset(); }

    static ::indexed_db::mojom::KeyData::Tag GetTag(const ::indexed_db::mojom::KeyDataPtr& input)
    {
        return input->which();
    }

    static const std::vector<content::IndexedDBKey>& key_array(const ::indexed_db::mojom::KeyDataPtr& input)
    {
        return input->get_key_array();
    }

    static const std::vector<uint8_t>& binary(const ::indexed_db::mojom::KeyDataPtr& input)
    {
        return input->get_binary();
    }

    static const base::string16& string(const ::indexed_db::mojom::KeyDataPtr& input)
    {
        return input->get_string();
    }

    static double date(const ::indexed_db::mojom::KeyDataPtr& input)
    {
        return input->get_date();
    }

    static double number(const ::indexed_db::mojom::KeyDataPtr& input)
    {
        return input->get_number();
    }

    static ::indexed_db::mojom::DatalessKeyType other(const ::indexed_db::mojom::KeyDataPtr& input)
    {
        return input->get_other();
    }

    static bool Read(::indexed_db::mojom::KeyData::DataView input, ::indexed_db::mojom::KeyDataPtr* output);
};

template <>
struct CONTENT_EXPORT UnionTraits<::indexed_db::mojom::KeyPathData::DataView,
    ::indexed_db::mojom::KeyPathDataPtr> {
    static bool IsNull(const ::indexed_db::mojom::KeyPathDataPtr& input) { return !input; }
    static void SetToNull(::indexed_db::mojom::KeyPathDataPtr* output) { output->reset(); }

    static ::indexed_db::mojom::KeyPathData::Tag GetTag(const ::indexed_db::mojom::KeyPathDataPtr& input)
    {
        return input->which();
    }

    static const base::string16& string(const ::indexed_db::mojom::KeyPathDataPtr& input)
    {
        return input->get_string();
    }

    static const std::vector<base::string16>& string_array(const ::indexed_db::mojom::KeyPathDataPtr& input)
    {
        return input->get_string_array();
    }

    static bool Read(::indexed_db::mojom::KeyPathData::DataView input, ::indexed_db::mojom::KeyPathDataPtr* output);
};

} // namespace mojo

#endif // CONTENT_COMMON_INDEXED_DB_INDEXED_DB_MOJOM_H_