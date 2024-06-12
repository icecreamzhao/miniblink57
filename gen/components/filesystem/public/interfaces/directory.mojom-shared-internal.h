// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_DIRECTORY_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_DIRECTORY_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "components/filesystem/public/interfaces/file.mojom-shared-internal.h"
#include "components/filesystem/public/interfaces/types.mojom-shared-internal.h"
#include "mojo/common/file.mojom-shared-internal.h"
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
namespace filesystem {
namespace mojom {
    namespace internal {
        class FileOpenDetails_Data;
        class FileOpenResult_Data;

#pragma pack(push, 1)
        class FileOpenDetails_Data {
        public:
            static FileOpenDetails_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileOpenDetails_Data))) FileOpenDetails_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;
            uint32_t open_flags;
            uint8_t padfinal_[4];

        private:
            FileOpenDetails_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileOpenDetails_Data() = delete;
        };
        static_assert(sizeof(FileOpenDetails_Data) == 24,
            "Bad sizeof(FileOpenDetails_Data)");
        class FileOpenResult_Data {
        public:
            static FileOpenResult_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileOpenResult_Data))) FileOpenResult_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;
            int32_t error;
            uint8_t pad1_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::File_Data> file_handle;

        private:
            FileOpenResult_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileOpenResult_Data() = delete;
        };
        static_assert(sizeof(FileOpenResult_Data) == 32,
            "Bad sizeof(FileOpenResult_Data)");
        constexpr uint32_t kDirectory_Read_Name = 0;
        class Directory_Read_Params_Data {
        public:
            static Directory_Read_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Read_Params_Data))) Directory_Read_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Directory_Read_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Read_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_Read_Params_Data) == 8,
            "Bad sizeof(Directory_Read_Params_Data)");
        class Directory_Read_ResponseParams_Data {
        public:
            static Directory_Read_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Read_ResponseParams_Data))) Directory_Read_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::filesystem::mojom::internal::DirectoryEntry_Data>>> directory_contents;

        private:
            Directory_Read_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Read_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_Read_ResponseParams_Data) == 24,
            "Bad sizeof(Directory_Read_ResponseParams_Data)");
        constexpr uint32_t kDirectory_OpenFile_Name = 1;
        class Directory_OpenFile_Params_Data {
        public:
            static Directory_OpenFile_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_OpenFile_Params_Data))) Directory_OpenFile_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;
            mojo::internal::Handle_Data file;
            uint32_t open_flags;

        private:
            Directory_OpenFile_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_OpenFile_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_OpenFile_Params_Data) == 24,
            "Bad sizeof(Directory_OpenFile_Params_Data)");
        class Directory_OpenFile_ResponseParams_Data {
        public:
            static Directory_OpenFile_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_OpenFile_ResponseParams_Data))) Directory_OpenFile_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            Directory_OpenFile_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_OpenFile_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_OpenFile_ResponseParams_Data) == 16,
            "Bad sizeof(Directory_OpenFile_ResponseParams_Data)");
        constexpr uint32_t kDirectory_OpenFileHandle_Name = 2;
        class Directory_OpenFileHandle_Params_Data {
        public:
            static Directory_OpenFileHandle_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_OpenFileHandle_Params_Data))) Directory_OpenFileHandle_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;
            uint32_t open_flags;
            uint8_t padfinal_[4];

        private:
            Directory_OpenFileHandle_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_OpenFileHandle_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_OpenFileHandle_Params_Data) == 24,
            "Bad sizeof(Directory_OpenFileHandle_Params_Data)");
        class Directory_OpenFileHandle_ResponseParams_Data {
        public:
            static Directory_OpenFileHandle_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_OpenFileHandle_ResponseParams_Data))) Directory_OpenFileHandle_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::File_Data> file_handle;

        private:
            Directory_OpenFileHandle_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_OpenFileHandle_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_OpenFileHandle_ResponseParams_Data) == 24,
            "Bad sizeof(Directory_OpenFileHandle_ResponseParams_Data)");
        constexpr uint32_t kDirectory_OpenFileHandles_Name = 3;
        class Directory_OpenFileHandles_Params_Data {
        public:
            static Directory_OpenFileHandles_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_OpenFileHandles_Params_Data))) Directory_OpenFileHandles_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::FileOpenDetails_Data>>> files;

        private:
            Directory_OpenFileHandles_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_OpenFileHandles_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_OpenFileHandles_Params_Data) == 16,
            "Bad sizeof(Directory_OpenFileHandles_Params_Data)");
        class Directory_OpenFileHandles_ResponseParams_Data {
        public:
            static Directory_OpenFileHandles_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_OpenFileHandles_ResponseParams_Data))) Directory_OpenFileHandles_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::FileOpenResult_Data>>> results;

        private:
            Directory_OpenFileHandles_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_OpenFileHandles_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_OpenFileHandles_ResponseParams_Data) == 16,
            "Bad sizeof(Directory_OpenFileHandles_ResponseParams_Data)");
        constexpr uint32_t kDirectory_OpenDirectory_Name = 4;
        class Directory_OpenDirectory_Params_Data {
        public:
            static Directory_OpenDirectory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_OpenDirectory_Params_Data))) Directory_OpenDirectory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;
            mojo::internal::Handle_Data directory;
            uint32_t open_flags;

        private:
            Directory_OpenDirectory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_OpenDirectory_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_OpenDirectory_Params_Data) == 24,
            "Bad sizeof(Directory_OpenDirectory_Params_Data)");
        class Directory_OpenDirectory_ResponseParams_Data {
        public:
            static Directory_OpenDirectory_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_OpenDirectory_ResponseParams_Data))) Directory_OpenDirectory_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            Directory_OpenDirectory_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_OpenDirectory_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_OpenDirectory_ResponseParams_Data) == 16,
            "Bad sizeof(Directory_OpenDirectory_ResponseParams_Data)");
        constexpr uint32_t kDirectory_Rename_Name = 5;
        class Directory_Rename_Params_Data {
        public:
            static Directory_Rename_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Rename_Params_Data))) Directory_Rename_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;
            mojo::internal::Pointer<mojo::internal::String_Data> new_path;

        private:
            Directory_Rename_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Rename_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_Rename_Params_Data) == 24,
            "Bad sizeof(Directory_Rename_Params_Data)");
        class Directory_Rename_ResponseParams_Data {
        public:
            static Directory_Rename_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Rename_ResponseParams_Data))) Directory_Rename_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            Directory_Rename_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Rename_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_Rename_ResponseParams_Data) == 16,
            "Bad sizeof(Directory_Rename_ResponseParams_Data)");
        constexpr uint32_t kDirectory_Delete_Name = 6;
        class Directory_Delete_Params_Data {
        public:
            static Directory_Delete_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Delete_Params_Data))) Directory_Delete_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;
            uint32_t delete_flags;
            uint8_t padfinal_[4];

        private:
            Directory_Delete_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Delete_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_Delete_Params_Data) == 24,
            "Bad sizeof(Directory_Delete_Params_Data)");
        class Directory_Delete_ResponseParams_Data {
        public:
            static Directory_Delete_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Delete_ResponseParams_Data))) Directory_Delete_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            Directory_Delete_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Delete_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_Delete_ResponseParams_Data) == 16,
            "Bad sizeof(Directory_Delete_ResponseParams_Data)");
        constexpr uint32_t kDirectory_Exists_Name = 7;
        class Directory_Exists_Params_Data {
        public:
            static Directory_Exists_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Exists_Params_Data))) Directory_Exists_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;

        private:
            Directory_Exists_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Exists_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_Exists_Params_Data) == 16,
            "Bad sizeof(Directory_Exists_Params_Data)");
        class Directory_Exists_ResponseParams_Data {
        public:
            static Directory_Exists_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Exists_ResponseParams_Data))) Directory_Exists_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t exists : 1;
            uint8_t padfinal_[3];

        private:
            Directory_Exists_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Exists_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_Exists_ResponseParams_Data) == 16,
            "Bad sizeof(Directory_Exists_ResponseParams_Data)");
        constexpr uint32_t kDirectory_IsWritable_Name = 8;
        class Directory_IsWritable_Params_Data {
        public:
            static Directory_IsWritable_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_IsWritable_Params_Data))) Directory_IsWritable_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;

        private:
            Directory_IsWritable_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_IsWritable_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_IsWritable_Params_Data) == 16,
            "Bad sizeof(Directory_IsWritable_Params_Data)");
        class Directory_IsWritable_ResponseParams_Data {
        public:
            static Directory_IsWritable_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_IsWritable_ResponseParams_Data))) Directory_IsWritable_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t is_writable : 1;
            uint8_t padfinal_[3];

        private:
            Directory_IsWritable_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_IsWritable_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_IsWritable_ResponseParams_Data) == 16,
            "Bad sizeof(Directory_IsWritable_ResponseParams_Data)");
        constexpr uint32_t kDirectory_Flush_Name = 9;
        class Directory_Flush_Params_Data {
        public:
            static Directory_Flush_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Flush_Params_Data))) Directory_Flush_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Directory_Flush_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Flush_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_Flush_Params_Data) == 8,
            "Bad sizeof(Directory_Flush_Params_Data)");
        class Directory_Flush_ResponseParams_Data {
        public:
            static Directory_Flush_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Flush_ResponseParams_Data))) Directory_Flush_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            Directory_Flush_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Flush_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_Flush_ResponseParams_Data) == 16,
            "Bad sizeof(Directory_Flush_ResponseParams_Data)");
        constexpr uint32_t kDirectory_StatFile_Name = 10;
        class Directory_StatFile_Params_Data {
        public:
            static Directory_StatFile_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_StatFile_Params_Data))) Directory_StatFile_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;

        private:
            Directory_StatFile_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_StatFile_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_StatFile_Params_Data) == 16,
            "Bad sizeof(Directory_StatFile_Params_Data)");
        class Directory_StatFile_ResponseParams_Data {
        public:
            static Directory_StatFile_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_StatFile_ResponseParams_Data))) Directory_StatFile_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::filesystem::mojom::internal::FileInformation_Data> file_information;

        private:
            Directory_StatFile_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_StatFile_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_StatFile_ResponseParams_Data) == 24,
            "Bad sizeof(Directory_StatFile_ResponseParams_Data)");
        constexpr uint32_t kDirectory_Clone_Name = 11;
        class Directory_Clone_Params_Data {
        public:
            static Directory_Clone_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_Clone_Params_Data))) Directory_Clone_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data directory;
            uint8_t padfinal_[4];

        private:
            Directory_Clone_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_Clone_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_Clone_Params_Data) == 16,
            "Bad sizeof(Directory_Clone_Params_Data)");
        constexpr uint32_t kDirectory_ReadEntireFile_Name = 12;
        class Directory_ReadEntireFile_Params_Data {
        public:
            static Directory_ReadEntireFile_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_ReadEntireFile_Params_Data))) Directory_ReadEntireFile_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;

        private:
            Directory_ReadEntireFile_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_ReadEntireFile_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_ReadEntireFile_Params_Data) == 16,
            "Bad sizeof(Directory_ReadEntireFile_Params_Data)");
        class Directory_ReadEntireFile_ResponseParams_Data {
        public:
            static Directory_ReadEntireFile_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_ReadEntireFile_ResponseParams_Data))) Directory_ReadEntireFile_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            Directory_ReadEntireFile_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_ReadEntireFile_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_ReadEntireFile_ResponseParams_Data) == 24,
            "Bad sizeof(Directory_ReadEntireFile_ResponseParams_Data)");
        constexpr uint32_t kDirectory_WriteFile_Name = 13;
        class Directory_WriteFile_Params_Data {
        public:
            static Directory_WriteFile_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_WriteFile_Params_Data))) Directory_WriteFile_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> path;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            Directory_WriteFile_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_WriteFile_Params_Data() = delete;
        };
        static_assert(sizeof(Directory_WriteFile_Params_Data) == 24,
            "Bad sizeof(Directory_WriteFile_Params_Data)");
        class Directory_WriteFile_ResponseParams_Data {
        public:
            static Directory_WriteFile_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Directory_WriteFile_ResponseParams_Data))) Directory_WriteFile_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            Directory_WriteFile_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Directory_WriteFile_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Directory_WriteFile_ResponseParams_Data) == 16,
            "Bad sizeof(Directory_WriteFile_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace filesystem

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_DIRECTORY_MOJOM_SHARED_INTERNAL_H_