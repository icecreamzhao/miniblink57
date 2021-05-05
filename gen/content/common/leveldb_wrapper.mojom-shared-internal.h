// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_LEVELDB_WRAPPER_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_LEVELDB_WRAPPER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "components/leveldb/public/interfaces/leveldb.mojom-shared-internal.h"
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
namespace content {
namespace mojom {
    namespace internal {
        class KeyValue_Data;

#pragma pack(push, 1)
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
        constexpr uint32_t kLevelDBObserver_KeyAdded_Name = 0;
        class LevelDBObserver_KeyAdded_Params_Data {
        public:
            static LevelDBObserver_KeyAdded_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBObserver_KeyAdded_Params_Data))) LevelDBObserver_KeyAdded_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;
            mojo::internal::Pointer<mojo::internal::String_Data> source;

        private:
            LevelDBObserver_KeyAdded_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBObserver_KeyAdded_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBObserver_KeyAdded_Params_Data) == 32,
            "Bad sizeof(LevelDBObserver_KeyAdded_Params_Data)");
        constexpr uint32_t kLevelDBObserver_KeyChanged_Name = 1;
        class LevelDBObserver_KeyChanged_Params_Data {
        public:
            static LevelDBObserver_KeyChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBObserver_KeyChanged_Params_Data))) LevelDBObserver_KeyChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> new_value;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> old_value;
            mojo::internal::Pointer<mojo::internal::String_Data> source;

        private:
            LevelDBObserver_KeyChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBObserver_KeyChanged_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBObserver_KeyChanged_Params_Data) == 40,
            "Bad sizeof(LevelDBObserver_KeyChanged_Params_Data)");
        constexpr uint32_t kLevelDBObserver_KeyDeleted_Name = 2;
        class LevelDBObserver_KeyDeleted_Params_Data {
        public:
            static LevelDBObserver_KeyDeleted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBObserver_KeyDeleted_Params_Data))) LevelDBObserver_KeyDeleted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> old_value;
            mojo::internal::Pointer<mojo::internal::String_Data> source;

        private:
            LevelDBObserver_KeyDeleted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBObserver_KeyDeleted_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBObserver_KeyDeleted_Params_Data) == 32,
            "Bad sizeof(LevelDBObserver_KeyDeleted_Params_Data)");
        constexpr uint32_t kLevelDBObserver_AllDeleted_Name = 3;
        class LevelDBObserver_AllDeleted_Params_Data {
        public:
            static LevelDBObserver_AllDeleted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBObserver_AllDeleted_Params_Data))) LevelDBObserver_AllDeleted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> source;

        private:
            LevelDBObserver_AllDeleted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBObserver_AllDeleted_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBObserver_AllDeleted_Params_Data) == 16,
            "Bad sizeof(LevelDBObserver_AllDeleted_Params_Data)");
        constexpr uint32_t kLevelDBWrapperGetAllCallback_Complete_Name = 0;
        class LevelDBWrapperGetAllCallback_Complete_Params_Data {
        public:
            static LevelDBWrapperGetAllCallback_Complete_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapperGetAllCallback_Complete_Params_Data))) LevelDBWrapperGetAllCallback_Complete_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            LevelDBWrapperGetAllCallback_Complete_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapperGetAllCallback_Complete_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapperGetAllCallback_Complete_Params_Data) == 16,
            "Bad sizeof(LevelDBWrapperGetAllCallback_Complete_Params_Data)");
        constexpr uint32_t kLevelDBWrapper_AddObserver_Name = 0;
        class LevelDBWrapper_AddObserver_Params_Data {
        public:
            static LevelDBWrapper_AddObserver_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_AddObserver_Params_Data))) LevelDBWrapper_AddObserver_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data observer;

        private:
            LevelDBWrapper_AddObserver_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_AddObserver_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_AddObserver_Params_Data) == 16,
            "Bad sizeof(LevelDBWrapper_AddObserver_Params_Data)");
        constexpr uint32_t kLevelDBWrapper_Put_Name = 1;
        class LevelDBWrapper_Put_Params_Data {
        public:
            static LevelDBWrapper_Put_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_Put_Params_Data))) LevelDBWrapper_Put_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;
            mojo::internal::Pointer<mojo::internal::String_Data> source;

        private:
            LevelDBWrapper_Put_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_Put_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_Put_Params_Data) == 32,
            "Bad sizeof(LevelDBWrapper_Put_Params_Data)");
        class LevelDBWrapper_Put_ResponseParams_Data {
        public:
            static LevelDBWrapper_Put_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_Put_ResponseParams_Data))) LevelDBWrapper_Put_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            LevelDBWrapper_Put_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_Put_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_Put_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBWrapper_Put_ResponseParams_Data)");
        constexpr uint32_t kLevelDBWrapper_Delete_Name = 2;
        class LevelDBWrapper_Delete_Params_Data {
        public:
            static LevelDBWrapper_Delete_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_Delete_Params_Data))) LevelDBWrapper_Delete_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;
            mojo::internal::Pointer<mojo::internal::String_Data> source;

        private:
            LevelDBWrapper_Delete_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_Delete_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_Delete_Params_Data) == 24,
            "Bad sizeof(LevelDBWrapper_Delete_Params_Data)");
        class LevelDBWrapper_Delete_ResponseParams_Data {
        public:
            static LevelDBWrapper_Delete_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_Delete_ResponseParams_Data))) LevelDBWrapper_Delete_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            LevelDBWrapper_Delete_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_Delete_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_Delete_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBWrapper_Delete_ResponseParams_Data)");
        constexpr uint32_t kLevelDBWrapper_DeleteAll_Name = 3;
        class LevelDBWrapper_DeleteAll_Params_Data {
        public:
            static LevelDBWrapper_DeleteAll_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_DeleteAll_Params_Data))) LevelDBWrapper_DeleteAll_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> source;

        private:
            LevelDBWrapper_DeleteAll_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_DeleteAll_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_DeleteAll_Params_Data) == 16,
            "Bad sizeof(LevelDBWrapper_DeleteAll_Params_Data)");
        class LevelDBWrapper_DeleteAll_ResponseParams_Data {
        public:
            static LevelDBWrapper_DeleteAll_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_DeleteAll_ResponseParams_Data))) LevelDBWrapper_DeleteAll_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            LevelDBWrapper_DeleteAll_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_DeleteAll_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_DeleteAll_ResponseParams_Data) == 16,
            "Bad sizeof(LevelDBWrapper_DeleteAll_ResponseParams_Data)");
        constexpr uint32_t kLevelDBWrapper_Get_Name = 4;
        class LevelDBWrapper_Get_Params_Data {
        public:
            static LevelDBWrapper_Get_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_Get_Params_Data))) LevelDBWrapper_Get_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> key;

        private:
            LevelDBWrapper_Get_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_Get_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_Get_Params_Data) == 16,
            "Bad sizeof(LevelDBWrapper_Get_Params_Data)");
        class LevelDBWrapper_Get_ResponseParams_Data {
        public:
            static LevelDBWrapper_Get_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_Get_ResponseParams_Data))) LevelDBWrapper_Get_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t pad0_[7];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            LevelDBWrapper_Get_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_Get_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_Get_ResponseParams_Data) == 24,
            "Bad sizeof(LevelDBWrapper_Get_ResponseParams_Data)");
        constexpr uint32_t kLevelDBWrapper_GetAll_Name = 5;
        class LevelDBWrapper_GetAll_Params_Data {
        public:
            static LevelDBWrapper_GetAll_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_GetAll_Params_Data))) LevelDBWrapper_GetAll_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data complete_callback;

        private:
            LevelDBWrapper_GetAll_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_GetAll_Params_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_GetAll_Params_Data) == 16,
            "Bad sizeof(LevelDBWrapper_GetAll_Params_Data)");
        class LevelDBWrapper_GetAll_ResponseParams_Data {
        public:
            static LevelDBWrapper_GetAll_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LevelDBWrapper_GetAll_ResponseParams_Data))) LevelDBWrapper_GetAll_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::KeyValue_Data>>> data;

        private:
            LevelDBWrapper_GetAll_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LevelDBWrapper_GetAll_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LevelDBWrapper_GetAll_ResponseParams_Data) == 24,
            "Bad sizeof(LevelDBWrapper_GetAll_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_LEVELDB_WRAPPER_MOJOM_SHARED_INTERNAL_H_