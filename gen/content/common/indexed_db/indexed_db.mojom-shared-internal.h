// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_INDEXED_DB_INDEXED_DB_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_INDEXED_DB_INDEXED_DB_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/file_path.mojom-shared-internal.h"
#include "mojo/common/string16.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/origin.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace indexed_db {
namespace mojom {
    namespace internal {
        class Key_Data;
        class KeyPath_Data;
        class KeyRange_Data;
        class IndexMetadata_Data;
        class ObjectStoreMetadata_Data;
        class DatabaseMetadata_Data;
        class IndexKeys_Data;
        class FileInfo_Data;
        class BlobInfo_Data;
        class Value_Data;
        class ReturnValue_Data;
        class Observation_Data;
        class ObserverTransaction_Data;
        class ObserverChanges_Data;
        class KeyData_Data;
        class KeyPathData_Data;

        struct CursorDirection_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct DataLoss_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct DatalessKeyType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct OperationType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct PutMode_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct TaskType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct TransactionMode_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)

        class KeyData_Data {
        public:
            // Used to identify Mojom Union Data Classes.
            typedef void MojomUnionDataType;

            KeyData_Data() { }
            // Do nothing in the destructor since it won't be called when it is a
            // non-inlined union.
            ~KeyData_Data() { }

            static KeyData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(KeyData_Data))) KeyData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context,
                bool inlined);

            bool is_null() const { return size == 0; }

            void set_null()
            {
                size = 0U;
                tag = static_cast<KeyData_Tag>(0);
                data.unknown = 0U;
            }

            enum class KeyData_Tag : uint32_t {

                KEY_ARRAY,
                BINARY,
                STRING,
                DATE,
                NUMBER,
                OTHER,
            };

            // A note on layout:
            // "Each non-static data member is allocated as if it were the sole member of
            // a struct." - Section 9.5.2 ISO/IEC 14882:2011 (The C++ Spec)
            union MOJO_ALIGNAS(8) Union_ {
                mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Key_Data>>> f_key_array;
                mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> f_binary;
                mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> f_string;
                double f_date;
                double f_number;
                int32_t f_other;
                uint64_t unknown;
            };

            uint32_t size;
            KeyData_Tag tag;
            Union_ data;
        };
        static_assert(sizeof(KeyData_Data) == mojo::internal::kUnionDataSize,
            "Bad sizeof(KeyData_Data)");

        class KeyPathData_Data {
        public:
            // Used to identify Mojom Union Data Classes.
            typedef void MojomUnionDataType;

            KeyPathData_Data() { }
            // Do nothing in the destructor since it won't be called when it is a
            // non-inlined union.
            ~KeyPathData_Data() { }

            static KeyPathData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(KeyPathData_Data))) KeyPathData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context,
                bool inlined);

            bool is_null() const { return size == 0; }

            void set_null()
            {
                size = 0U;
                tag = static_cast<KeyPathData_Tag>(0);
                data.unknown = 0U;
            }

            enum class KeyPathData_Tag : uint32_t {

                STRING,
                STRING_ARRAY,
            };

            // A note on layout:
            // "Each non-static data member is allocated as if it were the sole member of
            // a struct." - Section 9.5.2 ISO/IEC 14882:2011 (The C++ Spec)
            union MOJO_ALIGNAS(8) Union_ {
                mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> f_string;
                mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data>>> f_string_array;
                uint64_t unknown;
            };

            uint32_t size;
            KeyPathData_Tag tag;
            Union_ data;
        };
        static_assert(sizeof(KeyPathData_Data) == mojo::internal::kUnionDataSize,
            "Bad sizeof(KeyPathData_Data)");
        class Key_Data {
        public:
            static Key_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Key_Data))) Key_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            internal::KeyData_Data data;

        private:
            Key_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Key_Data() = delete;
        };
        static_assert(sizeof(Key_Data) == 24,
            "Bad sizeof(Key_Data)");
        class KeyPath_Data {
        public:
            static KeyPath_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(KeyPath_Data))) KeyPath_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            internal::KeyPathData_Data data;

        private:
            KeyPath_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~KeyPath_Data() = delete;
        };
        static_assert(sizeof(KeyPath_Data) == 24,
            "Bad sizeof(KeyPath_Data)");
        class KeyRange_Data {
        public:
            static KeyRange_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(KeyRange_Data))) KeyRange_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::Key_Data> lower;
            mojo::internal::Pointer<internal::Key_Data> upper;
            uint8_t lower_open : 1;
            uint8_t upper_open : 1;
            uint8_t padfinal_[7];

        private:
            KeyRange_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~KeyRange_Data() = delete;
        };
        static_assert(sizeof(KeyRange_Data) == 32,
            "Bad sizeof(KeyRange_Data)");
        class IndexMetadata_Data {
        public:
            static IndexMetadata_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(IndexMetadata_Data))) IndexMetadata_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t id;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> name;
            mojo::internal::Pointer<internal::KeyPath_Data> key_path;
            uint8_t unique : 1;
            uint8_t multi_entry : 1;
            uint8_t padfinal_[7];

        private:
            IndexMetadata_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~IndexMetadata_Data() = delete;
        };
        static_assert(sizeof(IndexMetadata_Data) == 40,
            "Bad sizeof(IndexMetadata_Data)");
        class ObjectStoreMetadata_Data {
        public:
            static ObjectStoreMetadata_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ObjectStoreMetadata_Data))) ObjectStoreMetadata_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t id;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> name;
            mojo::internal::Pointer<internal::KeyPath_Data> key_path;
            uint8_t auto_increment : 1;
            uint8_t pad3_[7];
            int64_t max_index_id;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::IndexMetadata_Data>>> indexes;

        private:
            ObjectStoreMetadata_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ObjectStoreMetadata_Data() = delete;
        };
        static_assert(sizeof(ObjectStoreMetadata_Data) == 56,
            "Bad sizeof(ObjectStoreMetadata_Data)");
        class DatabaseMetadata_Data {
        public:
            static DatabaseMetadata_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DatabaseMetadata_Data))) DatabaseMetadata_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t id;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> name;
            int64_t version;
            int64_t max_object_store_id;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::ObjectStoreMetadata_Data>>> object_stores;

        private:
            DatabaseMetadata_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DatabaseMetadata_Data() = delete;
        };
        static_assert(sizeof(DatabaseMetadata_Data) == 48,
            "Bad sizeof(DatabaseMetadata_Data)");
        class IndexKeys_Data {
        public:
            static IndexKeys_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(IndexKeys_Data))) IndexKeys_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t index_id;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Key_Data>>> index_keys;

        private:
            IndexKeys_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~IndexKeys_Data() = delete;
        };
        static_assert(sizeof(IndexKeys_Data) == 24,
            "Bad sizeof(IndexKeys_Data)");
        class FileInfo_Data {
        public:
            static FileInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileInfo_Data))) FileInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::FilePath_Data> path;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> name;
            mojo::internal::Pointer<::mojo::common::mojom::internal::Time_Data> last_modified;

        private:
            FileInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileInfo_Data() = delete;
        };
        static_assert(sizeof(FileInfo_Data) == 32,
            "Bad sizeof(FileInfo_Data)");
        class BlobInfo_Data {
        public:
            static BlobInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BlobInfo_Data))) BlobInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> uuid;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> mime_type;
            int64_t size;
            mojo::internal::Pointer<internal::FileInfo_Data> file;

        private:
            BlobInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BlobInfo_Data() = delete;
        };
        static_assert(sizeof(BlobInfo_Data) == 40,
            "Bad sizeof(BlobInfo_Data)");
        class Value_Data {
        public:
            static Value_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Value_Data))) Value_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> bits;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::BlobInfo_Data>>> blob_or_file_info;

        private:
            Value_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Value_Data() = delete;
        };
        static_assert(sizeof(Value_Data) == 24,
            "Bad sizeof(Value_Data)");
        class ReturnValue_Data {
        public:
            static ReturnValue_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ReturnValue_Data))) ReturnValue_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::Value_Data> value;
            mojo::internal::Pointer<internal::Key_Data> primary_key;
            mojo::internal::Pointer<internal::KeyPath_Data> key_path;

        private:
            ReturnValue_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ReturnValue_Data() = delete;
        };
        static_assert(sizeof(ReturnValue_Data) == 32,
            "Bad sizeof(ReturnValue_Data)");
        class Observation_Data {
        public:
            static Observation_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Observation_Data))) Observation_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t object_store_id;
            int32_t type;
            uint8_t pad1_[4];
            mojo::internal::Pointer<internal::KeyRange_Data> key_range;
            mojo::internal::Pointer<internal::Value_Data> value;

        private:
            Observation_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Observation_Data() = delete;
        };
        static_assert(sizeof(Observation_Data) == 40,
            "Bad sizeof(Observation_Data)");
        class ObserverTransaction_Data {
        public:
            static ObserverTransaction_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ObserverTransaction_Data))) ObserverTransaction_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t id;
            mojo::internal::Pointer<mojo::internal::Array_Data<int64_t>> scope;

        private:
            ObserverTransaction_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ObserverTransaction_Data() = delete;
        };
        static_assert(sizeof(ObserverTransaction_Data) == 24,
            "Bad sizeof(ObserverTransaction_Data)");
        class ObserverChanges_Data {
        public:
            static ObserverChanges_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ObserverChanges_Data))) ObserverChanges_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Map_Data<int32_t, mojo::internal::Pointer<mojo::internal::Array_Data<int32_t>>>> observation_index_map;
            mojo::internal::Pointer<mojo::internal::Map_Data<int32_t, mojo::internal::Pointer<internal::ObserverTransaction_Data>>> transaction_map;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Observation_Data>>> observations;

        private:
            ObserverChanges_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ObserverChanges_Data() = delete;
        };
        static_assert(sizeof(ObserverChanges_Data) == 32,
            "Bad sizeof(ObserverChanges_Data)");
        constexpr uint32_t kCallbacks_Error_Name = 0;
        class Callbacks_Error_Params_Data {
        public:
            static Callbacks_Error_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_Error_Params_Data))) Callbacks_Error_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t code;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> message;

        private:
            Callbacks_Error_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_Error_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_Error_Params_Data) == 24,
            "Bad sizeof(Callbacks_Error_Params_Data)");
        constexpr uint32_t kCallbacks_SuccessStringList_Name = 1;
        class Callbacks_SuccessStringList_Params_Data {
        public:
            static Callbacks_SuccessStringList_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_SuccessStringList_Params_Data))) Callbacks_SuccessStringList_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data>>> value;

        private:
            Callbacks_SuccessStringList_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_SuccessStringList_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_SuccessStringList_Params_Data) == 16,
            "Bad sizeof(Callbacks_SuccessStringList_Params_Data)");
        constexpr uint32_t kCallbacks_Blocked_Name = 2;
        class Callbacks_Blocked_Params_Data {
        public:
            static Callbacks_Blocked_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_Blocked_Params_Data))) Callbacks_Blocked_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t existing_version;

        private:
            Callbacks_Blocked_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_Blocked_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_Blocked_Params_Data) == 16,
            "Bad sizeof(Callbacks_Blocked_Params_Data)");
        constexpr uint32_t kCallbacks_UpgradeNeeded_Name = 3;
        class Callbacks_UpgradeNeeded_Params_Data {
        public:
            static Callbacks_UpgradeNeeded_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_UpgradeNeeded_Params_Data))) Callbacks_UpgradeNeeded_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data database;
            int64_t old_version;
            int32_t data_loss;
            uint8_t pad2_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> data_loss_message;
            mojo::internal::Pointer<internal::DatabaseMetadata_Data> db_metadata;

        private:
            Callbacks_UpgradeNeeded_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_UpgradeNeeded_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_UpgradeNeeded_Params_Data) == 48,
            "Bad sizeof(Callbacks_UpgradeNeeded_Params_Data)");
        constexpr uint32_t kCallbacks_SuccessDatabase_Name = 4;
        class Callbacks_SuccessDatabase_Params_Data {
        public:
            static Callbacks_SuccessDatabase_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_SuccessDatabase_Params_Data))) Callbacks_SuccessDatabase_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data database;
            mojo::internal::Pointer<internal::DatabaseMetadata_Data> metadata;

        private:
            Callbacks_SuccessDatabase_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_SuccessDatabase_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_SuccessDatabase_Params_Data) == 24,
            "Bad sizeof(Callbacks_SuccessDatabase_Params_Data)");
        constexpr uint32_t kCallbacks_SuccessCursor_Name = 5;
        class Callbacks_SuccessCursor_Params_Data {
        public:
            static Callbacks_SuccessCursor_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_SuccessCursor_Params_Data))) Callbacks_SuccessCursor_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data cursor;
            mojo::internal::Pointer<internal::Key_Data> key;
            mojo::internal::Pointer<internal::Key_Data> primary_key;
            mojo::internal::Pointer<internal::Value_Data> value;

        private:
            Callbacks_SuccessCursor_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_SuccessCursor_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_SuccessCursor_Params_Data) == 40,
            "Bad sizeof(Callbacks_SuccessCursor_Params_Data)");
        constexpr uint32_t kCallbacks_SuccessValue_Name = 6;
        class Callbacks_SuccessValue_Params_Data {
        public:
            static Callbacks_SuccessValue_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_SuccessValue_Params_Data))) Callbacks_SuccessValue_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ReturnValue_Data> value;

        private:
            Callbacks_SuccessValue_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_SuccessValue_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_SuccessValue_Params_Data) == 16,
            "Bad sizeof(Callbacks_SuccessValue_Params_Data)");
        constexpr uint32_t kCallbacks_SuccessCursorContinue_Name = 7;
        class Callbacks_SuccessCursorContinue_Params_Data {
        public:
            static Callbacks_SuccessCursorContinue_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_SuccessCursorContinue_Params_Data))) Callbacks_SuccessCursorContinue_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::Key_Data> key;
            mojo::internal::Pointer<internal::Key_Data> primary_key;
            mojo::internal::Pointer<internal::Value_Data> value;

        private:
            Callbacks_SuccessCursorContinue_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_SuccessCursorContinue_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_SuccessCursorContinue_Params_Data) == 32,
            "Bad sizeof(Callbacks_SuccessCursorContinue_Params_Data)");
        constexpr uint32_t kCallbacks_SuccessCursorPrefetch_Name = 8;
        class Callbacks_SuccessCursorPrefetch_Params_Data {
        public:
            static Callbacks_SuccessCursorPrefetch_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_SuccessCursorPrefetch_Params_Data))) Callbacks_SuccessCursorPrefetch_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Key_Data>>> keys;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Key_Data>>> primary_keys;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Value_Data>>> values;

        private:
            Callbacks_SuccessCursorPrefetch_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_SuccessCursorPrefetch_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_SuccessCursorPrefetch_Params_Data) == 32,
            "Bad sizeof(Callbacks_SuccessCursorPrefetch_Params_Data)");
        constexpr uint32_t kCallbacks_SuccessArray_Name = 9;
        class Callbacks_SuccessArray_Params_Data {
        public:
            static Callbacks_SuccessArray_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_SuccessArray_Params_Data))) Callbacks_SuccessArray_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::ReturnValue_Data>>> values;

        private:
            Callbacks_SuccessArray_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_SuccessArray_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_SuccessArray_Params_Data) == 16,
            "Bad sizeof(Callbacks_SuccessArray_Params_Data)");
        constexpr uint32_t kCallbacks_SuccessKey_Name = 10;
        class Callbacks_SuccessKey_Params_Data {
        public:
            static Callbacks_SuccessKey_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_SuccessKey_Params_Data))) Callbacks_SuccessKey_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::Key_Data> key;

        private:
            Callbacks_SuccessKey_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_SuccessKey_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_SuccessKey_Params_Data) == 16,
            "Bad sizeof(Callbacks_SuccessKey_Params_Data)");
        constexpr uint32_t kCallbacks_SuccessInteger_Name = 11;
        class Callbacks_SuccessInteger_Params_Data {
        public:
            static Callbacks_SuccessInteger_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_SuccessInteger_Params_Data))) Callbacks_SuccessInteger_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t value;

        private:
            Callbacks_SuccessInteger_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_SuccessInteger_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_SuccessInteger_Params_Data) == 16,
            "Bad sizeof(Callbacks_SuccessInteger_Params_Data)");
        constexpr uint32_t kCallbacks_Success_Name = 12;
        class Callbacks_Success_Params_Data {
        public:
            static Callbacks_Success_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Callbacks_Success_Params_Data))) Callbacks_Success_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Callbacks_Success_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Callbacks_Success_Params_Data() = delete;
        };
        static_assert(sizeof(Callbacks_Success_Params_Data) == 8,
            "Bad sizeof(Callbacks_Success_Params_Data)");
        constexpr uint32_t kDatabaseCallbacks_ForcedClose_Name = 0;
        class DatabaseCallbacks_ForcedClose_Params_Data {
        public:
            static DatabaseCallbacks_ForcedClose_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DatabaseCallbacks_ForcedClose_Params_Data))) DatabaseCallbacks_ForcedClose_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DatabaseCallbacks_ForcedClose_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DatabaseCallbacks_ForcedClose_Params_Data() = delete;
        };
        static_assert(sizeof(DatabaseCallbacks_ForcedClose_Params_Data) == 8,
            "Bad sizeof(DatabaseCallbacks_ForcedClose_Params_Data)");
        constexpr uint32_t kDatabaseCallbacks_VersionChange_Name = 1;
        class DatabaseCallbacks_VersionChange_Params_Data {
        public:
            static DatabaseCallbacks_VersionChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DatabaseCallbacks_VersionChange_Params_Data))) DatabaseCallbacks_VersionChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t old_version;
            int64_t new_version;

        private:
            DatabaseCallbacks_VersionChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DatabaseCallbacks_VersionChange_Params_Data() = delete;
        };
        static_assert(sizeof(DatabaseCallbacks_VersionChange_Params_Data) == 24,
            "Bad sizeof(DatabaseCallbacks_VersionChange_Params_Data)");
        constexpr uint32_t kDatabaseCallbacks_Abort_Name = 2;
        class DatabaseCallbacks_Abort_Params_Data {
        public:
            static DatabaseCallbacks_Abort_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DatabaseCallbacks_Abort_Params_Data))) DatabaseCallbacks_Abort_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int32_t code;
            uint8_t pad1_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> message;

        private:
            DatabaseCallbacks_Abort_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DatabaseCallbacks_Abort_Params_Data() = delete;
        };
        static_assert(sizeof(DatabaseCallbacks_Abort_Params_Data) == 32,
            "Bad sizeof(DatabaseCallbacks_Abort_Params_Data)");
        constexpr uint32_t kDatabaseCallbacks_Complete_Name = 3;
        class DatabaseCallbacks_Complete_Params_Data {
        public:
            static DatabaseCallbacks_Complete_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DatabaseCallbacks_Complete_Params_Data))) DatabaseCallbacks_Complete_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;

        private:
            DatabaseCallbacks_Complete_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DatabaseCallbacks_Complete_Params_Data() = delete;
        };
        static_assert(sizeof(DatabaseCallbacks_Complete_Params_Data) == 16,
            "Bad sizeof(DatabaseCallbacks_Complete_Params_Data)");
        constexpr uint32_t kDatabaseCallbacks_Changes_Name = 4;
        class DatabaseCallbacks_Changes_Params_Data {
        public:
            static DatabaseCallbacks_Changes_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DatabaseCallbacks_Changes_Params_Data))) DatabaseCallbacks_Changes_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ObserverChanges_Data> changes;

        private:
            DatabaseCallbacks_Changes_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DatabaseCallbacks_Changes_Params_Data() = delete;
        };
        static_assert(sizeof(DatabaseCallbacks_Changes_Params_Data) == 16,
            "Bad sizeof(DatabaseCallbacks_Changes_Params_Data)");
        constexpr uint32_t kCursor_Advance_Name = 0;
        class Cursor_Advance_Params_Data {
        public:
            static Cursor_Advance_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Cursor_Advance_Params_Data))) Cursor_Advance_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t count;
            mojo::internal::AssociatedInterface_Data callbacks;
            uint8_t padfinal_[4];

        private:
            Cursor_Advance_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Cursor_Advance_Params_Data() = delete;
        };
        static_assert(sizeof(Cursor_Advance_Params_Data) == 24,
            "Bad sizeof(Cursor_Advance_Params_Data)");
        constexpr uint32_t kCursor_Continue_Name = 1;
        class Cursor_Continue_Params_Data {
        public:
            static Cursor_Continue_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Cursor_Continue_Params_Data))) Cursor_Continue_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::Key_Data> key;
            mojo::internal::Pointer<internal::Key_Data> primary_key;
            mojo::internal::AssociatedInterface_Data callbacks;

        private:
            Cursor_Continue_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Cursor_Continue_Params_Data() = delete;
        };
        static_assert(sizeof(Cursor_Continue_Params_Data) == 32,
            "Bad sizeof(Cursor_Continue_Params_Data)");
        constexpr uint32_t kCursor_Prefetch_Name = 2;
        class Cursor_Prefetch_Params_Data {
        public:
            static Cursor_Prefetch_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Cursor_Prefetch_Params_Data))) Cursor_Prefetch_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t count;
            mojo::internal::AssociatedInterface_Data callbacks;
            uint8_t padfinal_[4];

        private:
            Cursor_Prefetch_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Cursor_Prefetch_Params_Data() = delete;
        };
        static_assert(sizeof(Cursor_Prefetch_Params_Data) == 24,
            "Bad sizeof(Cursor_Prefetch_Params_Data)");
        constexpr uint32_t kCursor_PrefetchReset_Name = 3;
        class Cursor_PrefetchReset_Params_Data {
        public:
            static Cursor_PrefetchReset_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Cursor_PrefetchReset_Params_Data))) Cursor_PrefetchReset_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t used_prefetches;
            int32_t unused_prefetches;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> unused_blob_uuids;

        private:
            Cursor_PrefetchReset_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Cursor_PrefetchReset_Params_Data() = delete;
        };
        static_assert(sizeof(Cursor_PrefetchReset_Params_Data) == 24,
            "Bad sizeof(Cursor_PrefetchReset_Params_Data)");
        constexpr uint32_t kDatabase_CreateObjectStore_Name = 0;
        class Database_CreateObjectStore_Params_Data {
        public:
            static Database_CreateObjectStore_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_CreateObjectStore_Params_Data))) Database_CreateObjectStore_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> name;
            mojo::internal::Pointer<internal::KeyPath_Data> key_path;
            uint8_t auto_increment : 1;
            uint8_t padfinal_[7];

        private:
            Database_CreateObjectStore_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_CreateObjectStore_Params_Data() = delete;
        };
        static_assert(sizeof(Database_CreateObjectStore_Params_Data) == 48,
            "Bad sizeof(Database_CreateObjectStore_Params_Data)");
        constexpr uint32_t kDatabase_DeleteObjectStore_Name = 1;
        class Database_DeleteObjectStore_Params_Data {
        public:
            static Database_DeleteObjectStore_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_DeleteObjectStore_Params_Data))) Database_DeleteObjectStore_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;

        private:
            Database_DeleteObjectStore_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_DeleteObjectStore_Params_Data() = delete;
        };
        static_assert(sizeof(Database_DeleteObjectStore_Params_Data) == 24,
            "Bad sizeof(Database_DeleteObjectStore_Params_Data)");
        constexpr uint32_t kDatabase_RenameObjectStore_Name = 2;
        class Database_RenameObjectStore_Params_Data {
        public:
            static Database_RenameObjectStore_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_RenameObjectStore_Params_Data))) Database_RenameObjectStore_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> new_name;

        private:
            Database_RenameObjectStore_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_RenameObjectStore_Params_Data() = delete;
        };
        static_assert(sizeof(Database_RenameObjectStore_Params_Data) == 32,
            "Bad sizeof(Database_RenameObjectStore_Params_Data)");
        constexpr uint32_t kDatabase_CreateTransaction_Name = 3;
        class Database_CreateTransaction_Params_Data {
        public:
            static Database_CreateTransaction_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_CreateTransaction_Params_Data))) Database_CreateTransaction_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            mojo::internal::Pointer<mojo::internal::Array_Data<int64_t>> object_store_ids;
            int32_t mode;
            uint8_t padfinal_[4];

        private:
            Database_CreateTransaction_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_CreateTransaction_Params_Data() = delete;
        };
        static_assert(sizeof(Database_CreateTransaction_Params_Data) == 32,
            "Bad sizeof(Database_CreateTransaction_Params_Data)");
        constexpr uint32_t kDatabase_Close_Name = 4;
        class Database_Close_Params_Data {
        public:
            static Database_Close_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_Close_Params_Data))) Database_Close_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Database_Close_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_Close_Params_Data() = delete;
        };
        static_assert(sizeof(Database_Close_Params_Data) == 8,
            "Bad sizeof(Database_Close_Params_Data)");
        constexpr uint32_t kDatabase_VersionChangeIgnored_Name = 5;
        class Database_VersionChangeIgnored_Params_Data {
        public:
            static Database_VersionChangeIgnored_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_VersionChangeIgnored_Params_Data))) Database_VersionChangeIgnored_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Database_VersionChangeIgnored_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_VersionChangeIgnored_Params_Data() = delete;
        };
        static_assert(sizeof(Database_VersionChangeIgnored_Params_Data) == 8,
            "Bad sizeof(Database_VersionChangeIgnored_Params_Data)");
        constexpr uint32_t kDatabase_AddObserver_Name = 6;
        class Database_AddObserver_Params_Data {
        public:
            static Database_AddObserver_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_AddObserver_Params_Data))) Database_AddObserver_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int32_t observer_id;
            uint8_t include_transaction : 1;
            uint8_t no_records : 1;
            uint8_t values : 1;
            uint8_t pad4_[1];
            uint16_t operation_types;

        private:
            Database_AddObserver_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_AddObserver_Params_Data() = delete;
        };
        static_assert(sizeof(Database_AddObserver_Params_Data) == 24,
            "Bad sizeof(Database_AddObserver_Params_Data)");
        constexpr uint32_t kDatabase_RemoveObservers_Name = 7;
        class Database_RemoveObservers_Params_Data {
        public:
            static Database_RemoveObservers_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_RemoveObservers_Params_Data))) Database_RemoveObservers_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<int32_t>> observers;

        private:
            Database_RemoveObservers_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_RemoveObservers_Params_Data() = delete;
        };
        static_assert(sizeof(Database_RemoveObservers_Params_Data) == 16,
            "Bad sizeof(Database_RemoveObservers_Params_Data)");
        constexpr uint32_t kDatabase_Get_Name = 8;
        class Database_Get_Params_Data {
        public:
            static Database_Get_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_Get_Params_Data))) Database_Get_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            int64_t index_id;
            mojo::internal::Pointer<internal::KeyRange_Data> key_range;
            uint8_t key_only : 1;
            uint8_t pad4_[3];
            mojo::internal::AssociatedInterface_Data callbacks;
            uint8_t padfinal_[4];

        private:
            Database_Get_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_Get_Params_Data() = delete;
        };
        static_assert(sizeof(Database_Get_Params_Data) == 56,
            "Bad sizeof(Database_Get_Params_Data)");
        constexpr uint32_t kDatabase_GetAll_Name = 9;
        class Database_GetAll_Params_Data {
        public:
            static Database_GetAll_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_GetAll_Params_Data))) Database_GetAll_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            int64_t index_id;
            mojo::internal::Pointer<internal::KeyRange_Data> key_range;
            uint8_t key_only : 1;
            uint8_t pad4_[7];
            int64_t max_count;
            mojo::internal::AssociatedInterface_Data callbacks;

        private:
            Database_GetAll_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_GetAll_Params_Data() = delete;
        };
        static_assert(sizeof(Database_GetAll_Params_Data) == 64,
            "Bad sizeof(Database_GetAll_Params_Data)");
        constexpr uint32_t kDatabase_Put_Name = 10;
        class Database_Put_Params_Data {
        public:
            static Database_Put_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_Put_Params_Data))) Database_Put_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            mojo::internal::Pointer<internal::Value_Data> value;
            mojo::internal::Pointer<internal::Key_Data> key;
            int32_t mode;
            uint8_t pad4_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::IndexKeys_Data>>> index_keys;
            mojo::internal::AssociatedInterface_Data callbacks;

        private:
            Database_Put_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_Put_Params_Data() = delete;
        };
        static_assert(sizeof(Database_Put_Params_Data) == 64,
            "Bad sizeof(Database_Put_Params_Data)");
        constexpr uint32_t kDatabase_SetIndexKeys_Name = 11;
        class Database_SetIndexKeys_Params_Data {
        public:
            static Database_SetIndexKeys_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_SetIndexKeys_Params_Data))) Database_SetIndexKeys_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            mojo::internal::Pointer<internal::Key_Data> primary_key;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::IndexKeys_Data>>> index_keys;

        private:
            Database_SetIndexKeys_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_SetIndexKeys_Params_Data() = delete;
        };
        static_assert(sizeof(Database_SetIndexKeys_Params_Data) == 40,
            "Bad sizeof(Database_SetIndexKeys_Params_Data)");
        constexpr uint32_t kDatabase_SetIndexesReady_Name = 12;
        class Database_SetIndexesReady_Params_Data {
        public:
            static Database_SetIndexesReady_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_SetIndexesReady_Params_Data))) Database_SetIndexesReady_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            mojo::internal::Pointer<mojo::internal::Array_Data<int64_t>> index_ids;

        private:
            Database_SetIndexesReady_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_SetIndexesReady_Params_Data() = delete;
        };
        static_assert(sizeof(Database_SetIndexesReady_Params_Data) == 32,
            "Bad sizeof(Database_SetIndexesReady_Params_Data)");
        constexpr uint32_t kDatabase_OpenCursor_Name = 13;
        class Database_OpenCursor_Params_Data {
        public:
            static Database_OpenCursor_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_OpenCursor_Params_Data))) Database_OpenCursor_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            int64_t index_id;
            mojo::internal::Pointer<internal::KeyRange_Data> key_range;
            int32_t direction;
            uint8_t key_only : 1;
            uint8_t pad5_[3];
            int32_t task_type;
            mojo::internal::AssociatedInterface_Data callbacks;
            uint8_t padfinal_[4];

        private:
            Database_OpenCursor_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_OpenCursor_Params_Data() = delete;
        };
        static_assert(sizeof(Database_OpenCursor_Params_Data) == 64,
            "Bad sizeof(Database_OpenCursor_Params_Data)");
        constexpr uint32_t kDatabase_Count_Name = 14;
        class Database_Count_Params_Data {
        public:
            static Database_Count_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_Count_Params_Data))) Database_Count_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            int64_t index_id;
            mojo::internal::Pointer<internal::KeyRange_Data> key_range;
            mojo::internal::AssociatedInterface_Data callbacks;

        private:
            Database_Count_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_Count_Params_Data() = delete;
        };
        static_assert(sizeof(Database_Count_Params_Data) == 48,
            "Bad sizeof(Database_Count_Params_Data)");
        constexpr uint32_t kDatabase_DeleteRange_Name = 15;
        class Database_DeleteRange_Params_Data {
        public:
            static Database_DeleteRange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_DeleteRange_Params_Data))) Database_DeleteRange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            mojo::internal::Pointer<internal::KeyRange_Data> key_range;
            mojo::internal::AssociatedInterface_Data callbacks;

        private:
            Database_DeleteRange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_DeleteRange_Params_Data() = delete;
        };
        static_assert(sizeof(Database_DeleteRange_Params_Data) == 40,
            "Bad sizeof(Database_DeleteRange_Params_Data)");
        constexpr uint32_t kDatabase_Clear_Name = 16;
        class Database_Clear_Params_Data {
        public:
            static Database_Clear_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_Clear_Params_Data))) Database_Clear_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            mojo::internal::AssociatedInterface_Data callbacks;

        private:
            Database_Clear_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_Clear_Params_Data() = delete;
        };
        static_assert(sizeof(Database_Clear_Params_Data) == 32,
            "Bad sizeof(Database_Clear_Params_Data)");
        constexpr uint32_t kDatabase_CreateIndex_Name = 17;
        class Database_CreateIndex_Params_Data {
        public:
            static Database_CreateIndex_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_CreateIndex_Params_Data))) Database_CreateIndex_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            int64_t index_id;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> name;
            mojo::internal::Pointer<internal::KeyPath_Data> key_path;
            uint8_t unique : 1;
            uint8_t multi_entry : 1;
            uint8_t padfinal_[7];

        private:
            Database_CreateIndex_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_CreateIndex_Params_Data() = delete;
        };
        static_assert(sizeof(Database_CreateIndex_Params_Data) == 56,
            "Bad sizeof(Database_CreateIndex_Params_Data)");
        constexpr uint32_t kDatabase_DeleteIndex_Name = 18;
        class Database_DeleteIndex_Params_Data {
        public:
            static Database_DeleteIndex_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_DeleteIndex_Params_Data))) Database_DeleteIndex_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            int64_t index_id;

        private:
            Database_DeleteIndex_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_DeleteIndex_Params_Data() = delete;
        };
        static_assert(sizeof(Database_DeleteIndex_Params_Data) == 32,
            "Bad sizeof(Database_DeleteIndex_Params_Data)");
        constexpr uint32_t kDatabase_RenameIndex_Name = 19;
        class Database_RenameIndex_Params_Data {
        public:
            static Database_RenameIndex_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_RenameIndex_Params_Data))) Database_RenameIndex_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;
            int64_t object_store_id;
            int64_t index_id;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> new_name;

        private:
            Database_RenameIndex_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_RenameIndex_Params_Data() = delete;
        };
        static_assert(sizeof(Database_RenameIndex_Params_Data) == 40,
            "Bad sizeof(Database_RenameIndex_Params_Data)");
        constexpr uint32_t kDatabase_Abort_Name = 20;
        class Database_Abort_Params_Data {
        public:
            static Database_Abort_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_Abort_Params_Data))) Database_Abort_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;

        private:
            Database_Abort_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_Abort_Params_Data() = delete;
        };
        static_assert(sizeof(Database_Abort_Params_Data) == 16,
            "Bad sizeof(Database_Abort_Params_Data)");
        constexpr uint32_t kDatabase_Commit_Name = 21;
        class Database_Commit_Params_Data {
        public:
            static Database_Commit_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_Commit_Params_Data))) Database_Commit_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t transaction_id;

        private:
            Database_Commit_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_Commit_Params_Data() = delete;
        };
        static_assert(sizeof(Database_Commit_Params_Data) == 16,
            "Bad sizeof(Database_Commit_Params_Data)");
        constexpr uint32_t kDatabase_AckReceivedBlobs_Name = 22;
        class Database_AckReceivedBlobs_Params_Data {
        public:
            static Database_AckReceivedBlobs_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Database_AckReceivedBlobs_Params_Data))) Database_AckReceivedBlobs_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> uuids;

        private:
            Database_AckReceivedBlobs_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Database_AckReceivedBlobs_Params_Data() = delete;
        };
        static_assert(sizeof(Database_AckReceivedBlobs_Params_Data) == 16,
            "Bad sizeof(Database_AckReceivedBlobs_Params_Data)");
        constexpr uint32_t kFactory_GetDatabaseNames_Name = 0;
        class Factory_GetDatabaseNames_Params_Data {
        public:
            static Factory_GetDatabaseNames_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Factory_GetDatabaseNames_Params_Data))) Factory_GetDatabaseNames_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data callbacks;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;

        private:
            Factory_GetDatabaseNames_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Factory_GetDatabaseNames_Params_Data() = delete;
        };
        static_assert(sizeof(Factory_GetDatabaseNames_Params_Data) == 24,
            "Bad sizeof(Factory_GetDatabaseNames_Params_Data)");
        constexpr uint32_t kFactory_Open_Name = 1;
        class Factory_Open_Params_Data {
        public:
            static Factory_Open_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Factory_Open_Params_Data))) Factory_Open_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data callbacks;
            mojo::internal::AssociatedInterface_Data database_callbacks;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> name;
            int64_t version;
            int64_t transaction_id;

        private:
            Factory_Open_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Factory_Open_Params_Data() = delete;
        };
        static_assert(sizeof(Factory_Open_Params_Data) == 56,
            "Bad sizeof(Factory_Open_Params_Data)");
        constexpr uint32_t kFactory_DeleteDatabase_Name = 2;
        class Factory_DeleteDatabase_Params_Data {
        public:
            static Factory_DeleteDatabase_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Factory_DeleteDatabase_Params_Data))) Factory_DeleteDatabase_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data callbacks;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> name;

        private:
            Factory_DeleteDatabase_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Factory_DeleteDatabase_Params_Data() = delete;
        };
        static_assert(sizeof(Factory_DeleteDatabase_Params_Data) == 32,
            "Bad sizeof(Factory_DeleteDatabase_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace indexed_db

#endif // CONTENT_COMMON_INDEXED_DB_INDEXED_DB_MOJOM_SHARED_INTERNAL_H_