// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_LEVELDB_PUBLIC_INTERFACES_LEVELDB_MOJOM_SHARED_H_
#define COMPONENTS_LEVELDB_PUBLIC_INTERFACES_LEVELDB_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/filesystem/public/interfaces/directory.mojom-shared.h"
#include "components/leveldb/public/interfaces/leveldb.mojom-shared-internal.h"
#include "mojo/common/unguessable_token.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace leveldb {
namespace mojom {
    class BatchedOperationDataView;

    class KeyValueDataView;

    class OpenOptionsDataView;

} // namespace mojom
} // namespace leveldb

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::leveldb::mojom::BatchedOperationDataView> {
        using Data = ::leveldb::mojom::internal::BatchedOperation_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::leveldb::mojom::KeyValueDataView> {
        using Data = ::leveldb::mojom::internal::KeyValue_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::leveldb::mojom::OpenOptionsDataView> {
        using Data = ::leveldb::mojom::internal::OpenOptions_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace leveldb {
namespace mojom {

    enum class DatabaseError : int32_t {
        OK,
        NOT_FOUND,
        CORRUPTION,
        NOT_SUPPORTED,
        INVALID_ARGUMENT,
        IO_ERROR,
    };

    inline std::ostream& operator<<(std::ostream& os, DatabaseError value)
    {
        switch (value) {
        case DatabaseError::OK:
            return os << "DatabaseError::OK";
        case DatabaseError::NOT_FOUND:
            return os << "DatabaseError::NOT_FOUND";
        case DatabaseError::CORRUPTION:
            return os << "DatabaseError::CORRUPTION";
        case DatabaseError::NOT_SUPPORTED:
            return os << "DatabaseError::NOT_SUPPORTED";
        case DatabaseError::INVALID_ARGUMENT:
            return os << "DatabaseError::INVALID_ARGUMENT";
        case DatabaseError::IO_ERROR:
            return os << "DatabaseError::IO_ERROR";
        default:
            return os << "Unknown DatabaseError value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(DatabaseError value)
    {
        return internal::DatabaseError_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class BatchOperationType : int32_t {
        PUT_KEY,
        DELETE_KEY,
        DELETE_PREFIXED_KEY,
    };

    inline std::ostream& operator<<(std::ostream& os, BatchOperationType value)
    {
        switch (value) {
        case BatchOperationType::PUT_KEY:
            return os << "BatchOperationType::PUT_KEY";
        case BatchOperationType::DELETE_KEY:
            return os << "BatchOperationType::DELETE_KEY";
        case BatchOperationType::DELETE_PREFIXED_KEY:
            return os << "BatchOperationType::DELETE_PREFIXED_KEY";
        default:
            return os << "Unknown BatchOperationType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BatchOperationType value)
    {
        return internal::BatchOperationType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class LevelDBServiceInterfaceBase {
    };

    using LevelDBServicePtrDataView = mojo::InterfacePtrDataView<LevelDBServiceInterfaceBase>;
    using LevelDBServiceRequestDataView = mojo::InterfaceRequestDataView<LevelDBServiceInterfaceBase>;
    using LevelDBServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<LevelDBServiceInterfaceBase>;
    using LevelDBServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<LevelDBServiceInterfaceBase>;
    class LevelDBDatabaseInterfaceBase {
    };

    using LevelDBDatabasePtrDataView = mojo::InterfacePtrDataView<LevelDBDatabaseInterfaceBase>;
    using LevelDBDatabaseRequestDataView = mojo::InterfaceRequestDataView<LevelDBDatabaseInterfaceBase>;
    using LevelDBDatabaseAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<LevelDBDatabaseInterfaceBase>;
    using LevelDBDatabaseAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<LevelDBDatabaseInterfaceBase>;
    class BatchedOperationDataView {
    public:
        BatchedOperationDataView() { }

        BatchedOperationDataView(
            internal::BatchedOperation_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::leveldb::mojom::BatchOperationType>(
                data_value, output);
        }

        BatchOperationType type() const
        {
            return static_cast<BatchOperationType>(data_->type);
        }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::BatchedOperation_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class KeyValueDataView {
    public:
        KeyValueDataView() { }

        KeyValueDataView(
            internal::KeyValue_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::KeyValue_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class OpenOptionsDataView {
    public:
        OpenOptionsDataView() { }

        OpenOptionsDataView(
            internal::OpenOptions_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool create_if_missing() const
        {
            return data_->create_if_missing;
        }
        bool error_if_exists() const
        {
            return data_->error_if_exists;
        }
        bool paranoid_checks() const
        {
            return data_->paranoid_checks;
        }
        uint64_t write_buffer_size() const
        {
            return data_->write_buffer_size;
        }
        int32_t max_open_files() const
        {
            return data_->max_open_files;
        }

    private:
        internal::OpenOptions_Data* data_ = nullptr;
    };

    class LevelDBService_Open_ParamsDataView {
    public:
        LevelDBService_Open_ParamsDataView() { }

        LevelDBService_Open_ParamsDataView(
            internal::LevelDBService_Open_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeDirectory()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::filesystem::mojom::DirectoryPtrDataView>(
                &data_->directory, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetDbnameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDbname(UserType* output)
        {
            auto* pointer = data_->dbname.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeDatabase()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::leveldb::mojom::LevelDBDatabaseAssociatedRequestDataView>(
                &data_->database, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::LevelDBService_Open_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBService_Open_ResponseParamsDataView {
    public:
        LevelDBService_Open_ResponseParamsDataView() { }

        LevelDBService_Open_ResponseParamsDataView(
            internal::LevelDBService_Open_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }

    private:
        internal::LevelDBService_Open_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBService_OpenWithOptions_ParamsDataView {
    public:
        LevelDBService_OpenWithOptions_ParamsDataView() { }

        LevelDBService_OpenWithOptions_ParamsDataView(
            internal::LevelDBService_OpenWithOptions_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOptionsDataView(
            OpenOptionsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
        {
            auto* pointer = data_->options.Get();
            return mojo::internal::Deserialize<::leveldb::mojom::OpenOptionsDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeDirectory()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::filesystem::mojom::DirectoryPtrDataView>(
                &data_->directory, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetDbnameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDbname(UserType* output)
        {
            auto* pointer = data_->dbname.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeDatabase()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::leveldb::mojom::LevelDBDatabaseAssociatedRequestDataView>(
                &data_->database, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::LevelDBService_OpenWithOptions_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBService_OpenWithOptions_ResponseParamsDataView {
    public:
        LevelDBService_OpenWithOptions_ResponseParamsDataView() { }

        LevelDBService_OpenWithOptions_ResponseParamsDataView(
            internal::LevelDBService_OpenWithOptions_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }

    private:
        internal::LevelDBService_OpenWithOptions_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBService_OpenInMemory_ParamsDataView {
    public:
        LevelDBService_OpenInMemory_ParamsDataView() { }

        LevelDBService_OpenInMemory_ParamsDataView(
            internal::LevelDBService_OpenInMemory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeDatabase()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::leveldb::mojom::LevelDBDatabaseAssociatedRequestDataView>(
                &data_->database, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::LevelDBService_OpenInMemory_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBService_OpenInMemory_ResponseParamsDataView {
    public:
        LevelDBService_OpenInMemory_ResponseParamsDataView() { }

        LevelDBService_OpenInMemory_ResponseParamsDataView(
            internal::LevelDBService_OpenInMemory_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }

    private:
        internal::LevelDBService_OpenInMemory_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBService_Destroy_ParamsDataView {
    public:
        LevelDBService_Destroy_ParamsDataView() { }

        LevelDBService_Destroy_ParamsDataView(
            internal::LevelDBService_Destroy_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeDirectory()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::filesystem::mojom::DirectoryPtrDataView>(
                &data_->directory, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetDbnameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDbname(UserType* output)
        {
            auto* pointer = data_->dbname.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBService_Destroy_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBService_Destroy_ResponseParamsDataView {
    public:
        LevelDBService_Destroy_ResponseParamsDataView() { }

        LevelDBService_Destroy_ResponseParamsDataView(
            internal::LevelDBService_Destroy_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }

    private:
        internal::LevelDBService_Destroy_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBDatabase_Put_ParamsDataView {
    public:
        LevelDBDatabase_Put_ParamsDataView() { }

        LevelDBDatabase_Put_ParamsDataView(
            internal::LevelDBDatabase_Put_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_Put_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_Put_ResponseParamsDataView {
    public:
        LevelDBDatabase_Put_ResponseParamsDataView() { }

        LevelDBDatabase_Put_ResponseParamsDataView(
            internal::LevelDBDatabase_Put_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }

    private:
        internal::LevelDBDatabase_Put_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBDatabase_Delete_ParamsDataView {
    public:
        LevelDBDatabase_Delete_ParamsDataView() { }

        LevelDBDatabase_Delete_ParamsDataView(
            internal::LevelDBDatabase_Delete_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_Delete_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_Delete_ResponseParamsDataView {
    public:
        LevelDBDatabase_Delete_ResponseParamsDataView() { }

        LevelDBDatabase_Delete_ResponseParamsDataView(
            internal::LevelDBDatabase_Delete_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }

    private:
        internal::LevelDBDatabase_Delete_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBDatabase_DeletePrefixed_ParamsDataView {
    public:
        LevelDBDatabase_DeletePrefixed_ParamsDataView() { }

        LevelDBDatabase_DeletePrefixed_ParamsDataView(
            internal::LevelDBDatabase_DeletePrefixed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyPrefixDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKeyPrefix(UserType* output)
        {
            auto* pointer = data_->key_prefix.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_DeletePrefixed_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_DeletePrefixed_ResponseParamsDataView {
    public:
        LevelDBDatabase_DeletePrefixed_ResponseParamsDataView() { }

        LevelDBDatabase_DeletePrefixed_ResponseParamsDataView(
            internal::LevelDBDatabase_DeletePrefixed_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }

    private:
        internal::LevelDBDatabase_DeletePrefixed_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBDatabase_Write_ParamsDataView {
    public:
        LevelDBDatabase_Write_ParamsDataView() { }

        LevelDBDatabase_Write_ParamsDataView(
            internal::LevelDBDatabase_Write_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOperationsDataView(
            mojo::ArrayDataView<BatchedOperationDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOperations(UserType* output)
        {
            auto* pointer = data_->operations.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::leveldb::mojom::BatchedOperationDataView>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_Write_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_Write_ResponseParamsDataView {
    public:
        LevelDBDatabase_Write_ResponseParamsDataView() { }

        LevelDBDatabase_Write_ResponseParamsDataView(
            internal::LevelDBDatabase_Write_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }

    private:
        internal::LevelDBDatabase_Write_ResponseParams_Data* data_ = nullptr;
    };

    class LevelDBDatabase_Get_ParamsDataView {
    public:
        LevelDBDatabase_Get_ParamsDataView() { }

        LevelDBDatabase_Get_ParamsDataView(
            internal::LevelDBDatabase_Get_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_Get_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_Get_ResponseParamsDataView {
    public:
        LevelDBDatabase_Get_ResponseParamsDataView() { }

        LevelDBDatabase_Get_ResponseParamsDataView(
            internal::LevelDBDatabase_Get_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_Get_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_GetPrefixed_ParamsDataView {
    public:
        LevelDBDatabase_GetPrefixed_ParamsDataView() { }

        LevelDBDatabase_GetPrefixed_ParamsDataView(
            internal::LevelDBDatabase_GetPrefixed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyPrefixDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKeyPrefix(UserType* output)
        {
            auto* pointer = data_->key_prefix.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_GetPrefixed_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_GetPrefixed_ResponseParamsDataView {
    public:
        LevelDBDatabase_GetPrefixed_ResponseParamsDataView() { }

        LevelDBDatabase_GetPrefixed_ResponseParamsDataView(
            internal::LevelDBDatabase_GetPrefixed_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<KeyValueDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::leveldb::mojom::KeyValueDataView>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_GetPrefixed_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_GetSnapshot_ParamsDataView {
    public:
        LevelDBDatabase_GetSnapshot_ParamsDataView() { }

        LevelDBDatabase_GetSnapshot_ParamsDataView(
            internal::LevelDBDatabase_GetSnapshot_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::LevelDBDatabase_GetSnapshot_Params_Data* data_ = nullptr;
    };

    class LevelDBDatabase_GetSnapshot_ResponseParamsDataView {
    public:
        LevelDBDatabase_GetSnapshot_ResponseParamsDataView() { }

        LevelDBDatabase_GetSnapshot_ResponseParamsDataView(
            internal::LevelDBDatabase_GetSnapshot_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSnapshotDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSnapshot(UserType* output)
        {
            auto* pointer = data_->snapshot.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_GetSnapshot_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_ReleaseSnapshot_ParamsDataView {
    public:
        LevelDBDatabase_ReleaseSnapshot_ParamsDataView() { }

        LevelDBDatabase_ReleaseSnapshot_ParamsDataView(
            internal::LevelDBDatabase_ReleaseSnapshot_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSnapshotDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSnapshot(UserType* output)
        {
            auto* pointer = data_->snapshot.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_ReleaseSnapshot_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_GetFromSnapshot_ParamsDataView {
    public:
        LevelDBDatabase_GetFromSnapshot_ParamsDataView() { }

        LevelDBDatabase_GetFromSnapshot_ParamsDataView(
            internal::LevelDBDatabase_GetFromSnapshot_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSnapshotDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSnapshot(UserType* output)
        {
            auto* pointer = data_->snapshot.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_GetFromSnapshot_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_GetFromSnapshot_ResponseParamsDataView {
    public:
        LevelDBDatabase_GetFromSnapshot_ResponseParamsDataView() { }

        LevelDBDatabase_GetFromSnapshot_ResponseParamsDataView(
            internal::LevelDBDatabase_GetFromSnapshot_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_GetFromSnapshot_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_NewIterator_ParamsDataView {
    public:
        LevelDBDatabase_NewIterator_ParamsDataView() { }

        LevelDBDatabase_NewIterator_ParamsDataView(
            internal::LevelDBDatabase_NewIterator_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::LevelDBDatabase_NewIterator_Params_Data* data_ = nullptr;
    };

    class LevelDBDatabase_NewIterator_ResponseParamsDataView {
    public:
        LevelDBDatabase_NewIterator_ResponseParamsDataView() { }

        LevelDBDatabase_NewIterator_ResponseParamsDataView(
            internal::LevelDBDatabase_NewIterator_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIteratorDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIterator(UserType* output)
        {
            auto* pointer = data_->iterator.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_NewIterator_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_NewIteratorFromSnapshot_ParamsDataView {
    public:
        LevelDBDatabase_NewIteratorFromSnapshot_ParamsDataView() { }

        LevelDBDatabase_NewIteratorFromSnapshot_ParamsDataView(
            internal::LevelDBDatabase_NewIteratorFromSnapshot_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSnapshotDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSnapshot(UserType* output)
        {
            auto* pointer = data_->snapshot.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_NewIteratorFromSnapshot_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_NewIteratorFromSnapshot_ResponseParamsDataView {
    public:
        LevelDBDatabase_NewIteratorFromSnapshot_ResponseParamsDataView() { }

        LevelDBDatabase_NewIteratorFromSnapshot_ResponseParamsDataView(
            internal::LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIteratorDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIterator(UserType* output)
        {
            auto* pointer = data_->iterator.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_ReleaseIterator_ParamsDataView {
    public:
        LevelDBDatabase_ReleaseIterator_ParamsDataView() { }

        LevelDBDatabase_ReleaseIterator_ParamsDataView(
            internal::LevelDBDatabase_ReleaseIterator_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIteratorDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIterator(UserType* output)
        {
            auto* pointer = data_->iterator.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_ReleaseIterator_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorSeekToFirst_ParamsDataView {
    public:
        LevelDBDatabase_IteratorSeekToFirst_ParamsDataView() { }

        LevelDBDatabase_IteratorSeekToFirst_ParamsDataView(
            internal::LevelDBDatabase_IteratorSeekToFirst_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIteratorDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIterator(UserType* output)
        {
            auto* pointer = data_->iterator.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorSeekToFirst_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorSeekToFirst_ResponseParamsDataView {
    public:
        LevelDBDatabase_IteratorSeekToFirst_ResponseParamsDataView() { }

        LevelDBDatabase_IteratorSeekToFirst_ResponseParamsDataView(
            internal::LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool valid() const
        {
            return data_->valid;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorSeekToLast_ParamsDataView {
    public:
        LevelDBDatabase_IteratorSeekToLast_ParamsDataView() { }

        LevelDBDatabase_IteratorSeekToLast_ParamsDataView(
            internal::LevelDBDatabase_IteratorSeekToLast_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIteratorDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIterator(UserType* output)
        {
            auto* pointer = data_->iterator.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorSeekToLast_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorSeekToLast_ResponseParamsDataView {
    public:
        LevelDBDatabase_IteratorSeekToLast_ResponseParamsDataView() { }

        LevelDBDatabase_IteratorSeekToLast_ResponseParamsDataView(
            internal::LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool valid() const
        {
            return data_->valid;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorSeek_ParamsDataView {
    public:
        LevelDBDatabase_IteratorSeek_ParamsDataView() { }

        LevelDBDatabase_IteratorSeek_ParamsDataView(
            internal::LevelDBDatabase_IteratorSeek_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIteratorDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIterator(UserType* output)
        {
            auto* pointer = data_->iterator.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }
        inline void GetTargetDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTarget(UserType* output)
        {
            auto* pointer = data_->target.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorSeek_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorSeek_ResponseParamsDataView {
    public:
        LevelDBDatabase_IteratorSeek_ResponseParamsDataView() { }

        LevelDBDatabase_IteratorSeek_ResponseParamsDataView(
            internal::LevelDBDatabase_IteratorSeek_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool valid() const
        {
            return data_->valid;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorSeek_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorNext_ParamsDataView {
    public:
        LevelDBDatabase_IteratorNext_ParamsDataView() { }

        LevelDBDatabase_IteratorNext_ParamsDataView(
            internal::LevelDBDatabase_IteratorNext_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIteratorDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIterator(UserType* output)
        {
            auto* pointer = data_->iterator.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorNext_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorNext_ResponseParamsDataView {
    public:
        LevelDBDatabase_IteratorNext_ResponseParamsDataView() { }

        LevelDBDatabase_IteratorNext_ResponseParamsDataView(
            internal::LevelDBDatabase_IteratorNext_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool valid() const
        {
            return data_->valid;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorNext_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorPrev_ParamsDataView {
    public:
        LevelDBDatabase_IteratorPrev_ParamsDataView() { }

        LevelDBDatabase_IteratorPrev_ParamsDataView(
            internal::LevelDBDatabase_IteratorPrev_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIteratorDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIterator(UserType* output)
        {
            auto* pointer = data_->iterator.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorPrev_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class LevelDBDatabase_IteratorPrev_ResponseParamsDataView {
    public:
        LevelDBDatabase_IteratorPrev_ResponseParamsDataView() { }

        LevelDBDatabase_IteratorPrev_ResponseParamsDataView(
            internal::LevelDBDatabase_IteratorPrev_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool valid() const
        {
            return data_->valid;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::leveldb::mojom::DatabaseError>(
                data_value, output);
        }

        DatabaseError status() const
        {
            return static_cast<DatabaseError>(data_->status);
        }
        inline void GetKeyDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::LevelDBDatabase_IteratorPrev_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace leveldb

namespace std {

template <>
struct hash<::leveldb::mojom::DatabaseError>
    : public mojo::internal::EnumHashImpl<::leveldb::mojom::DatabaseError> {
};

template <>
struct hash<::leveldb::mojom::BatchOperationType>
    : public mojo::internal::EnumHashImpl<::leveldb::mojom::BatchOperationType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::leveldb::mojom::DatabaseError, ::leveldb::mojom::DatabaseError> {
    static ::leveldb::mojom::DatabaseError ToMojom(::leveldb::mojom::DatabaseError input) { return input; }
    static bool FromMojom(::leveldb::mojom::DatabaseError input, ::leveldb::mojom::DatabaseError* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::leveldb::mojom::DatabaseError, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::leveldb::mojom::DatabaseError, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::leveldb::mojom::DatabaseError>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::leveldb::mojom::BatchOperationType, ::leveldb::mojom::BatchOperationType> {
    static ::leveldb::mojom::BatchOperationType ToMojom(::leveldb::mojom::BatchOperationType input) { return input; }
    static bool FromMojom(::leveldb::mojom::BatchOperationType input, ::leveldb::mojom::BatchOperationType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::leveldb::mojom::BatchOperationType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::leveldb::mojom::BatchOperationType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::leveldb::mojom::BatchOperationType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::leveldb::mojom::BatchedOperationDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::leveldb::mojom::BatchedOperationDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::leveldb::mojom::internal::BatchedOperation_Data);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_key, context);
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_value, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::leveldb::mojom::internal::BatchedOperation_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::leveldb::mojom::internal::BatchedOperation_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::leveldb::mojom::BatchOperationType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            typename decltype(result->key)::BaseType* key_ptr;
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_key, buffer, &key_ptr, &key_validate_params,
                context);
            result->key.Set(key_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->key.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null key in BatchedOperation struct");
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            typename decltype(result->value)::BaseType* value_ptr;
            const mojo::internal::ContainerValidateParams value_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_value, buffer, &value_ptr, &value_validate_params,
                context);
            result->value.Set(value_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::leveldb::mojom::internal::BatchedOperation_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::leveldb::mojom::BatchedOperationDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::leveldb::mojom::KeyValueDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::leveldb::mojom::KeyValueDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::leveldb::mojom::internal::KeyValue_Data);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_key, context);
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_value, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::leveldb::mojom::internal::KeyValue_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::leveldb::mojom::internal::KeyValue_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            typename decltype(result->key)::BaseType* key_ptr;
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_key, buffer, &key_ptr, &key_validate_params,
                context);
            result->key.Set(key_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->key.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null key in KeyValue struct");
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            typename decltype(result->value)::BaseType* value_ptr;
            const mojo::internal::ContainerValidateParams value_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_value, buffer, &value_ptr, &value_validate_params,
                context);
            result->value.Set(value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null value in KeyValue struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::leveldb::mojom::internal::KeyValue_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::leveldb::mojom::KeyValueDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::leveldb::mojom::OpenOptionsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::leveldb::mojom::OpenOptionsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::leveldb::mojom::internal::OpenOptions_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::leveldb::mojom::internal::OpenOptions_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::leveldb::mojom::internal::OpenOptions_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->create_if_missing = CallWithContext(Traits::create_if_missing, input, custom_context);
            result->error_if_exists = CallWithContext(Traits::error_if_exists, input, custom_context);
            result->paranoid_checks = CallWithContext(Traits::paranoid_checks, input, custom_context);
            result->write_buffer_size = CallWithContext(Traits::write_buffer_size, input, custom_context);
            result->max_open_files = CallWithContext(Traits::max_open_files, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::leveldb::mojom::internal::OpenOptions_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::leveldb::mojom::OpenOptionsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace leveldb {
namespace mojom {

    inline void BatchedOperationDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void BatchedOperationDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void KeyValueDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void KeyValueDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBService_Open_ParamsDataView::GetDbnameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->dbname.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBService_OpenWithOptions_ParamsDataView::GetOptionsDataView(
        OpenOptionsDataView* output)
    {
        auto pointer = data_->options.Get();
        *output = OpenOptionsDataView(pointer, context_);
    }
    inline void LevelDBService_OpenWithOptions_ParamsDataView::GetDbnameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->dbname.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBService_Destroy_ParamsDataView::GetDbnameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->dbname.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void LevelDBDatabase_Put_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBDatabase_Put_ParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_Delete_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_DeletePrefixed_ParamsDataView::GetKeyPrefixDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key_prefix.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_Write_ParamsDataView::GetOperationsDataView(
        mojo::ArrayDataView<BatchedOperationDataView>* output)
    {
        auto pointer = data_->operations.Get();
        *output = mojo::ArrayDataView<BatchedOperationDataView>(pointer, context_);
    }

    inline void LevelDBDatabase_Get_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_Get_ResponseParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_GetPrefixed_ParamsDataView::GetKeyPrefixDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key_prefix.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_GetPrefixed_ResponseParamsDataView::GetDataDataView(
        mojo::ArrayDataView<KeyValueDataView>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<KeyValueDataView>(pointer, context_);
    }

    inline void LevelDBDatabase_GetSnapshot_ResponseParamsDataView::GetSnapshotDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->snapshot.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_ReleaseSnapshot_ParamsDataView::GetSnapshotDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->snapshot.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_GetFromSnapshot_ParamsDataView::GetSnapshotDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->snapshot.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }
    inline void LevelDBDatabase_GetFromSnapshot_ParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_GetFromSnapshot_ResponseParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_NewIterator_ResponseParamsDataView::GetIteratorDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->iterator.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_NewIteratorFromSnapshot_ParamsDataView::GetSnapshotDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->snapshot.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_NewIteratorFromSnapshot_ResponseParamsDataView::GetIteratorDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->iterator.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_ReleaseIterator_ParamsDataView::GetIteratorDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->iterator.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorSeekToFirst_ParamsDataView::GetIteratorDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->iterator.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorSeekToFirst_ResponseParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBDatabase_IteratorSeekToFirst_ResponseParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorSeekToLast_ParamsDataView::GetIteratorDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->iterator.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorSeekToLast_ResponseParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBDatabase_IteratorSeekToLast_ResponseParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorSeek_ParamsDataView::GetIteratorDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->iterator.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }
    inline void LevelDBDatabase_IteratorSeek_ParamsDataView::GetTargetDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->target.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorSeek_ResponseParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBDatabase_IteratorSeek_ResponseParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorNext_ParamsDataView::GetIteratorDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->iterator.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorNext_ResponseParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBDatabase_IteratorNext_ResponseParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorPrev_ParamsDataView::GetIteratorDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->iterator.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void LevelDBDatabase_IteratorPrev_ResponseParamsDataView::GetKeyDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }
    inline void LevelDBDatabase_IteratorPrev_ResponseParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

} // namespace mojom
} // namespace leveldb

#endif // COMPONENTS_LEVELDB_PUBLIC_INTERFACES_LEVELDB_MOJOM_SHARED_H_
