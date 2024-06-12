// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_LEVELDB_PUBLIC_INTERFACES_LEVELDB_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_LEVELDB_PUBLIC_INTERFACES_LEVELDB_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "components/filesystem/public/interfaces/directory.mojom-shared-internal.h"
#include "mojo/common/unguessable_token.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace leveldb {
namespace mojom {
    namespace internal {
        class BatchedOperation_Data;
        class KeyValue_Data;
        class OpenOptions_Data;

        struct DatabaseError_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
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

        struct BatchOperationType_Data {
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
        class BatchedOperation_Data {
        public:
            static BatchedOperation_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BatchedOperation_Data))) BatchedOperation_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            BatchedOperation_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BatchedOperation_Data() = delete;
        };
        static_assert(sizeof(BatchedOperation_Data) == 32,
            "Bad sizeof(BatchedOperation_Data)");
        class KeyValue_Data {
        public:
            static KeyValue_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(KeyValue_Data))) KeyValue_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            KeyValue_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~KeyValue_Data() = delete;
        };
        static_assert(sizeof(KeyValue_Data) == 24,
            "Bad sizeof(KeyValue_Data)");
        class OpenOptions_Data {
        public:
            static OpenOptions_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OpenOptions_Data))) OpenOptions_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t create_if_missing : 1;
            uint8_t error_if_exists : 1;
            uint8_t paranoid_checks : 1;
            uint8_t pad2_[3];
            int32_t max_open_files;
            uint64_t write_buffer_size;

        private:
            OpenOptions_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OpenOptions_Data() = delete;
        };
        static_assert(sizeof(OpenOptions_Data) == 24,
            "Bad sizeof(OpenOptions_Data)");
        constexpr uint32_t kLevelDBService_Open_Name = 0;
        class LevelDBService_Open_Params_Data {
        public:
            static LevelDBService_Open_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBService_Open_Params_Data))) LevelDBService_Open_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data directory;
            mojo::internal::Pointer<mojo::internal::String_Data> dbname;
            mojo::internal::AssociatedInterfaceRequest_Data database;
            uint8_t padfinal_[4];

        private:
            LevelDBService_Open_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBService_Open_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBService_Open_Params_Data) == 32,
            "Bad sizeof(LevelDBService_Open_Params_Data)");
        class LevelDBService_Open_ResponseParams_Data {
        public:
            static LevelDBService_Open_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBService_Open_ResponseParams_Data))) LevelDBService_Open_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            LevelDBService_Open_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBService_Open_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBService_Open_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBService_Open_ResponseParams_Data)");
        constexpr uint32_t kLevelDBService_OpenWithOptions_Name = 1;
        class LevelDBService_OpenWithOptions_Params_Data {
        public:
            static LevelDBService_OpenWithOptions_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBService_OpenWithOptions_Params_Data))) LevelDBService_OpenWithOptions_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::OpenOptions_Data> options;
            mojo::internal::Interface_Data directory;
            mojo::internal::Pointer<mojo::internal::String_Data> dbname;
            mojo::internal::AssociatedInterfaceRequest_Data database;
            uint8_t padfinal_[4];

        private:
            LevelDBService_OpenWithOptions_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBService_OpenWithOptions_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBService_OpenWithOptions_Params_Data) == 40,
            "Bad sizeof(LevelDBService_OpenWithOptions_Params_Data)");
        class LevelDBService_OpenWithOptions_ResponseParams_Data {
        public:
            static LevelDBService_OpenWithOptions_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBService_OpenWithOptions_ResponseParams_Data))) LevelDBService_OpenWithOptions_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            LevelDBService_OpenWithOptions_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBService_OpenWithOptions_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBService_OpenWithOptions_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBService_OpenWithOptions_ResponseParams_Data)");
        constexpr uint32_t kLevelDBService_OpenInMemory_Name = 2;
        class LevelDBService_OpenInMemory_Params_Data {
        public:
            static LevelDBService_OpenInMemory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBService_OpenInMemory_Params_Data))) LevelDBService_OpenInMemory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterfaceRequest_Data database;
            uint8_t padfinal_[4];

        private:
            LevelDBService_OpenInMemory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBService_OpenInMemory_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBService_OpenInMemory_Params_Data) == 16,
            "Bad sizeof(LevelDBService_OpenInMemory_Params_Data)");
        class LevelDBService_OpenInMemory_ResponseParams_Data {
        public:
            static LevelDBService_OpenInMemory_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBService_OpenInMemory_ResponseParams_Data))) LevelDBService_OpenInMemory_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            LevelDBService_OpenInMemory_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBService_OpenInMemory_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBService_OpenInMemory_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBService_OpenInMemory_ResponseParams_Data)");
        constexpr uint32_t kLevelDBService_Destroy_Name = 3;
        class LevelDBService_Destroy_Params_Data {
        public:
            static LevelDBService_Destroy_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBService_Destroy_Params_Data))) LevelDBService_Destroy_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data directory;
            mojo::internal::Pointer<mojo::internal::String_Data> dbname;

        private:
            LevelDBService_Destroy_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBService_Destroy_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBService_Destroy_Params_Data) == 24,
            "Bad sizeof(LevelDBService_Destroy_Params_Data)");
        class LevelDBService_Destroy_ResponseParams_Data {
        public:
            static LevelDBService_Destroy_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBService_Destroy_ResponseParams_Data))) LevelDBService_Destroy_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            LevelDBService_Destroy_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBService_Destroy_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBService_Destroy_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBService_Destroy_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_Put_Name = 0;
        class LevelDBDatabase_Put_Params_Data {
        public:
            static LevelDBDatabase_Put_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_Put_Params_Data))) LevelDBDatabase_Put_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            LevelDBDatabase_Put_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_Put_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_Put_Params_Data) == 24,
            "Bad sizeof(LevelDBDatabase_Put_Params_Data)");
        class LevelDBDatabase_Put_ResponseParams_Data {
        public:
            static LevelDBDatabase_Put_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_Put_ResponseParams_Data))) LevelDBDatabase_Put_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            LevelDBDatabase_Put_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_Put_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_Put_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBDatabase_Put_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_Delete_Name = 1;
        class LevelDBDatabase_Delete_Params_Data {
        public:
            static LevelDBDatabase_Delete_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_Delete_Params_Data))) LevelDBDatabase_Delete_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;

        private:
            LevelDBDatabase_Delete_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_Delete_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_Delete_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_Delete_Params_Data)");
        class LevelDBDatabase_Delete_ResponseParams_Data {
        public:
            static LevelDBDatabase_Delete_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_Delete_ResponseParams_Data))) LevelDBDatabase_Delete_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            LevelDBDatabase_Delete_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_Delete_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_Delete_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBDatabase_Delete_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_DeletePrefixed_Name = 2;
        class LevelDBDatabase_DeletePrefixed_Params_Data {
        public:
            static LevelDBDatabase_DeletePrefixed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_DeletePrefixed_Params_Data))) LevelDBDatabase_DeletePrefixed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key_prefix;

        private:
            LevelDBDatabase_DeletePrefixed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_DeletePrefixed_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_DeletePrefixed_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_DeletePrefixed_Params_Data)");
        class LevelDBDatabase_DeletePrefixed_ResponseParams_Data {
        public:
            static LevelDBDatabase_DeletePrefixed_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_DeletePrefixed_ResponseParams_Data))) LevelDBDatabase_DeletePrefixed_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            LevelDBDatabase_DeletePrefixed_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_DeletePrefixed_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_DeletePrefixed_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBDatabase_DeletePrefixed_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_Write_Name = 3;
        class LevelDBDatabase_Write_Params_Data {
        public:
            static LevelDBDatabase_Write_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_Write_Params_Data))) LevelDBDatabase_Write_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::BatchedOperation_Data>>> operations;

        private:
            LevelDBDatabase_Write_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_Write_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_Write_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_Write_Params_Data)");
        class LevelDBDatabase_Write_ResponseParams_Data {
        public:
            static LevelDBDatabase_Write_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_Write_ResponseParams_Data))) LevelDBDatabase_Write_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            LevelDBDatabase_Write_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_Write_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_Write_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBDatabase_Write_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_Get_Name = 4;
        class LevelDBDatabase_Get_Params_Data {
        public:
            static LevelDBDatabase_Get_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_Get_Params_Data))) LevelDBDatabase_Get_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;

        private:
            LevelDBDatabase_Get_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_Get_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_Get_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_Get_Params_Data)");
        class LevelDBDatabase_Get_ResponseParams_Data {
        public:
            static LevelDBDatabase_Get_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_Get_ResponseParams_Data))) LevelDBDatabase_Get_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            LevelDBDatabase_Get_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_Get_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_Get_ResponseParams_Data) == 24,
            "Bad sizeof(LevelDBDatabase_Get_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_GetPrefixed_Name = 5;
        class LevelDBDatabase_GetPrefixed_Params_Data {
        public:
            static LevelDBDatabase_GetPrefixed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_GetPrefixed_Params_Data))) LevelDBDatabase_GetPrefixed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key_prefix;

        private:
            LevelDBDatabase_GetPrefixed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_GetPrefixed_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_GetPrefixed_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_GetPrefixed_Params_Data)");
        class LevelDBDatabase_GetPrefixed_ResponseParams_Data {
        public:
            static LevelDBDatabase_GetPrefixed_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_GetPrefixed_ResponseParams_Data))) LevelDBDatabase_GetPrefixed_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::KeyValue_Data>>> data;

        private:
            LevelDBDatabase_GetPrefixed_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_GetPrefixed_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_GetPrefixed_ResponseParams_Data) == 24,
            "Bad sizeof(LevelDBDatabase_GetPrefixed_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_GetSnapshot_Name = 6;
        class LevelDBDatabase_GetSnapshot_Params_Data {
        public:
            static LevelDBDatabase_GetSnapshot_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_GetSnapshot_Params_Data))) LevelDBDatabase_GetSnapshot_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            LevelDBDatabase_GetSnapshot_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_GetSnapshot_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_GetSnapshot_Params_Data) == 8,
            "Bad sizeof(LevelDBDatabase_GetSnapshot_Params_Data)");
        class LevelDBDatabase_GetSnapshot_ResponseParams_Data {
        public:
            static LevelDBDatabase_GetSnapshot_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_GetSnapshot_ResponseParams_Data))) LevelDBDatabase_GetSnapshot_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> snapshot;

        private:
            LevelDBDatabase_GetSnapshot_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_GetSnapshot_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_GetSnapshot_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBDatabase_GetSnapshot_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_ReleaseSnapshot_Name = 7;
        class LevelDBDatabase_ReleaseSnapshot_Params_Data {
        public:
            static LevelDBDatabase_ReleaseSnapshot_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_ReleaseSnapshot_Params_Data))) LevelDBDatabase_ReleaseSnapshot_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> snapshot;

        private:
            LevelDBDatabase_ReleaseSnapshot_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_ReleaseSnapshot_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_ReleaseSnapshot_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_ReleaseSnapshot_Params_Data)");
        constexpr uint32_t kLevelDBDatabase_GetFromSnapshot_Name = 8;
        class LevelDBDatabase_GetFromSnapshot_Params_Data {
        public:
            static LevelDBDatabase_GetFromSnapshot_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_GetFromSnapshot_Params_Data))) LevelDBDatabase_GetFromSnapshot_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> snapshot;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;

        private:
            LevelDBDatabase_GetFromSnapshot_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_GetFromSnapshot_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_GetFromSnapshot_Params_Data) == 24,
            "Bad sizeof(LevelDBDatabase_GetFromSnapshot_Params_Data)");
        class LevelDBDatabase_GetFromSnapshot_ResponseParams_Data {
        public:
            static LevelDBDatabase_GetFromSnapshot_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_GetFromSnapshot_ResponseParams_Data))) LevelDBDatabase_GetFromSnapshot_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            LevelDBDatabase_GetFromSnapshot_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_GetFromSnapshot_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_GetFromSnapshot_ResponseParams_Data) == 24,
            "Bad sizeof(LevelDBDatabase_GetFromSnapshot_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_NewIterator_Name = 9;
        class LevelDBDatabase_NewIterator_Params_Data {
        public:
            static LevelDBDatabase_NewIterator_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_NewIterator_Params_Data))) LevelDBDatabase_NewIterator_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            LevelDBDatabase_NewIterator_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_NewIterator_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_NewIterator_Params_Data) == 8,
            "Bad sizeof(LevelDBDatabase_NewIterator_Params_Data)");
        class LevelDBDatabase_NewIterator_ResponseParams_Data {
        public:
            static LevelDBDatabase_NewIterator_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_NewIterator_ResponseParams_Data))) LevelDBDatabase_NewIterator_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> iterator;

        private:
            LevelDBDatabase_NewIterator_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_NewIterator_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_NewIterator_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBDatabase_NewIterator_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_NewIteratorFromSnapshot_Name = 10;
        class LevelDBDatabase_NewIteratorFromSnapshot_Params_Data {
        public:
            static LevelDBDatabase_NewIteratorFromSnapshot_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_NewIteratorFromSnapshot_Params_Data))) LevelDBDatabase_NewIteratorFromSnapshot_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> snapshot;

        private:
            LevelDBDatabase_NewIteratorFromSnapshot_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_NewIteratorFromSnapshot_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_NewIteratorFromSnapshot_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_NewIteratorFromSnapshot_Params_Data)");
        class LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data {
        public:
            static LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data))) LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> iterator;

        private:
            LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_ReleaseIterator_Name = 11;
        class LevelDBDatabase_ReleaseIterator_Params_Data {
        public:
            static LevelDBDatabase_ReleaseIterator_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_ReleaseIterator_Params_Data))) LevelDBDatabase_ReleaseIterator_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> iterator;

        private:
            LevelDBDatabase_ReleaseIterator_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_ReleaseIterator_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_ReleaseIterator_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_ReleaseIterator_Params_Data)");
        constexpr uint32_t kLevelDBDatabase_IteratorSeekToFirst_Name = 12;
        class LevelDBDatabase_IteratorSeekToFirst_Params_Data {
        public:
            static LevelDBDatabase_IteratorSeekToFirst_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorSeekToFirst_Params_Data))) LevelDBDatabase_IteratorSeekToFirst_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> iterator;

        private:
            LevelDBDatabase_IteratorSeekToFirst_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorSeekToFirst_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorSeekToFirst_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_IteratorSeekToFirst_Params_Data)");
        class LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data {
        public:
            static LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data))) LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t valid : 1;
            uint8_t pad0_[3];
            int32_t status;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data) == 32,
            "Bad sizeof(LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_IteratorSeekToLast_Name = 13;
        class LevelDBDatabase_IteratorSeekToLast_Params_Data {
        public:
            static LevelDBDatabase_IteratorSeekToLast_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorSeekToLast_Params_Data))) LevelDBDatabase_IteratorSeekToLast_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> iterator;

        private:
            LevelDBDatabase_IteratorSeekToLast_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorSeekToLast_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorSeekToLast_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_IteratorSeekToLast_Params_Data)");
        class LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data {
        public:
            static LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data))) LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t valid : 1;
            uint8_t pad0_[3];
            int32_t status;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data) == 32,
            "Bad sizeof(LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_IteratorSeek_Name = 14;
        class LevelDBDatabase_IteratorSeek_Params_Data {
        public:
            static LevelDBDatabase_IteratorSeek_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorSeek_Params_Data))) LevelDBDatabase_IteratorSeek_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> iterator;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> target;

        private:
            LevelDBDatabase_IteratorSeek_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorSeek_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorSeek_Params_Data) == 24,
            "Bad sizeof(LevelDBDatabase_IteratorSeek_Params_Data)");
        class LevelDBDatabase_IteratorSeek_ResponseParams_Data {
        public:
            static LevelDBDatabase_IteratorSeek_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorSeek_ResponseParams_Data))) LevelDBDatabase_IteratorSeek_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t valid : 1;
            uint8_t pad0_[3];
            int32_t status;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            LevelDBDatabase_IteratorSeek_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorSeek_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorSeek_ResponseParams_Data) == 32,
            "Bad sizeof(LevelDBDatabase_IteratorSeek_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_IteratorNext_Name = 15;
        class LevelDBDatabase_IteratorNext_Params_Data {
        public:
            static LevelDBDatabase_IteratorNext_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorNext_Params_Data))) LevelDBDatabase_IteratorNext_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> iterator;

        private:
            LevelDBDatabase_IteratorNext_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorNext_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorNext_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_IteratorNext_Params_Data)");
        class LevelDBDatabase_IteratorNext_ResponseParams_Data {
        public:
            static LevelDBDatabase_IteratorNext_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorNext_ResponseParams_Data))) LevelDBDatabase_IteratorNext_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t valid : 1;
            uint8_t pad0_[3];
            int32_t status;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            LevelDBDatabase_IteratorNext_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorNext_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorNext_ResponseParams_Data) == 32,
            "Bad sizeof(LevelDBDatabase_IteratorNext_ResponseParams_Data)");
        constexpr uint32_t kLevelDBDatabase_IteratorPrev_Name = 16;
        class LevelDBDatabase_IteratorPrev_Params_Data {
        public:
            static LevelDBDatabase_IteratorPrev_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorPrev_Params_Data))) LevelDBDatabase_IteratorPrev_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> iterator;

        private:
            LevelDBDatabase_IteratorPrev_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorPrev_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorPrev_Params_Data) == 16,
            "Bad sizeof(LevelDBDatabase_IteratorPrev_Params_Data)");
        class LevelDBDatabase_IteratorPrev_ResponseParams_Data {
        public:
            static LevelDBDatabase_IteratorPrev_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBDatabase_IteratorPrev_ResponseParams_Data))) LevelDBDatabase_IteratorPrev_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t valid : 1;
            uint8_t pad0_[3];
            int32_t status;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            LevelDBDatabase_IteratorPrev_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBDatabase_IteratorPrev_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBDatabase_IteratorPrev_ResponseParams_Data) == 32,
            "Bad sizeof(LevelDBDatabase_IteratorPrev_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace leveldb

#endif // COMPONENTS_LEVELDB_PUBLIC_INTERFACES_LEVELDB_MOJOM_SHARED_INTERNAL_H_