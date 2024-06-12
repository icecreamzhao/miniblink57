// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

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

#pragma pack(push, 1)
        constexpr uint32_t kFile_Close_Name = 0;
        class File_Close_Params_Data {
        public:
            static File_Close_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Close_Params_Data))) File_Close_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            File_Close_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Close_Params_Data() = delete;
        };
        static_assert(sizeof(File_Close_Params_Data) == 8,
            "Bad sizeof(File_Close_Params_Data)");
        class File_Close_ResponseParams_Data {
        public:
            static File_Close_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Close_ResponseParams_Data))) File_Close_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t err;
            uint8_t padfinal_[4];

        private:
            File_Close_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Close_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Close_ResponseParams_Data) == 16,
            "Bad sizeof(File_Close_ResponseParams_Data)");
        constexpr uint32_t kFile_Read_Name = 1;
        class File_Read_Params_Data {
        public:
            static File_Read_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Read_Params_Data))) File_Read_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t num_bytes_to_read;
            int32_t whence;
            int64_t offset;

        private:
            File_Read_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Read_Params_Data() = delete;
        };
        static_assert(sizeof(File_Read_Params_Data) == 24,
            "Bad sizeof(File_Read_Params_Data)");
        class File_Read_ResponseParams_Data {
        public:
            static File_Read_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Read_ResponseParams_Data))) File_Read_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> bytes_read;

        private:
            File_Read_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Read_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Read_ResponseParams_Data) == 24,
            "Bad sizeof(File_Read_ResponseParams_Data)");
        constexpr uint32_t kFile_Write_Name = 2;
        class File_Write_Params_Data {
        public:
            static File_Write_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Write_Params_Data))) File_Write_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> bytes_to_write;
            int64_t offset;
            int32_t whence;
            uint8_t padfinal_[4];

        private:
            File_Write_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Write_Params_Data() = delete;
        };
        static_assert(sizeof(File_Write_Params_Data) == 32,
            "Bad sizeof(File_Write_Params_Data)");
        class File_Write_ResponseParams_Data {
        public:
            static File_Write_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Write_ResponseParams_Data))) File_Write_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint32_t num_bytes_written;

        private:
            File_Write_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Write_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Write_ResponseParams_Data) == 16,
            "Bad sizeof(File_Write_ResponseParams_Data)");
        constexpr uint32_t kFile_Tell_Name = 3;
        class File_Tell_Params_Data {
        public:
            static File_Tell_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Tell_Params_Data))) File_Tell_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            File_Tell_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Tell_Params_Data() = delete;
        };
        static_assert(sizeof(File_Tell_Params_Data) == 8,
            "Bad sizeof(File_Tell_Params_Data)");
        class File_Tell_ResponseParams_Data {
        public:
            static File_Tell_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Tell_ResponseParams_Data))) File_Tell_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t pad0_[4];
            int64_t position;

        private:
            File_Tell_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Tell_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Tell_ResponseParams_Data) == 24,
            "Bad sizeof(File_Tell_ResponseParams_Data)");
        constexpr uint32_t kFile_Seek_Name = 4;
        class File_Seek_Params_Data {
        public:
            static File_Seek_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Seek_Params_Data))) File_Seek_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t offset;
            int32_t whence;
            uint8_t padfinal_[4];

        private:
            File_Seek_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Seek_Params_Data() = delete;
        };
        static_assert(sizeof(File_Seek_Params_Data) == 24,
            "Bad sizeof(File_Seek_Params_Data)");
        class File_Seek_ResponseParams_Data {
        public:
            static File_Seek_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Seek_ResponseParams_Data))) File_Seek_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t pad0_[4];
            int64_t position;

        private:
            File_Seek_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Seek_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Seek_ResponseParams_Data) == 24,
            "Bad sizeof(File_Seek_ResponseParams_Data)");
        constexpr uint32_t kFile_Stat_Name = 5;
        class File_Stat_Params_Data {
        public:
            static File_Stat_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Stat_Params_Data))) File_Stat_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            File_Stat_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Stat_Params_Data() = delete;
        };
        static_assert(sizeof(File_Stat_Params_Data) == 8,
            "Bad sizeof(File_Stat_Params_Data)");
        class File_Stat_ResponseParams_Data {
        public:
            static File_Stat_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Stat_ResponseParams_Data))) File_Stat_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::filesystem::mojom::internal::FileInformation_Data> file_information;

        private:
            File_Stat_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Stat_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Stat_ResponseParams_Data) == 24,
            "Bad sizeof(File_Stat_ResponseParams_Data)");
        constexpr uint32_t kFile_Truncate_Name = 6;
        class File_Truncate_Params_Data {
        public:
            static File_Truncate_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Truncate_Params_Data))) File_Truncate_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t size;

        private:
            File_Truncate_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Truncate_Params_Data() = delete;
        };
        static_assert(sizeof(File_Truncate_Params_Data) == 16,
            "Bad sizeof(File_Truncate_Params_Data)");
        class File_Truncate_ResponseParams_Data {
        public:
            static File_Truncate_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Truncate_ResponseParams_Data))) File_Truncate_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            File_Truncate_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Truncate_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Truncate_ResponseParams_Data) == 16,
            "Bad sizeof(File_Truncate_ResponseParams_Data)");
        constexpr uint32_t kFile_Touch_Name = 7;
        class File_Touch_Params_Data {
        public:
            static File_Touch_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Touch_Params_Data))) File_Touch_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::filesystem::mojom::internal::TimespecOrNow_Data> atime;
            mojo::internal::Pointer<::filesystem::mojom::internal::TimespecOrNow_Data> mtime;

        private:
            File_Touch_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Touch_Params_Data() = delete;
        };
        static_assert(sizeof(File_Touch_Params_Data) == 24,
            "Bad sizeof(File_Touch_Params_Data)");
        class File_Touch_ResponseParams_Data {
        public:
            static File_Touch_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Touch_ResponseParams_Data))) File_Touch_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            File_Touch_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Touch_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Touch_ResponseParams_Data) == 16,
            "Bad sizeof(File_Touch_ResponseParams_Data)");
        constexpr uint32_t kFile_Dup_Name = 8;
        class File_Dup_Params_Data {
        public:
            static File_Dup_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Dup_Params_Data))) File_Dup_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data file;
            uint8_t padfinal_[4];

        private:
            File_Dup_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Dup_Params_Data() = delete;
        };
        static_assert(sizeof(File_Dup_Params_Data) == 16,
            "Bad sizeof(File_Dup_Params_Data)");
        class File_Dup_ResponseParams_Data {
        public:
            static File_Dup_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Dup_ResponseParams_Data))) File_Dup_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            File_Dup_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Dup_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Dup_ResponseParams_Data) == 16,
            "Bad sizeof(File_Dup_ResponseParams_Data)");
        constexpr uint32_t kFile_Flush_Name = 9;
        class File_Flush_Params_Data {
        public:
            static File_Flush_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Flush_Params_Data))) File_Flush_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            File_Flush_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Flush_Params_Data() = delete;
        };
        static_assert(sizeof(File_Flush_Params_Data) == 8,
            "Bad sizeof(File_Flush_Params_Data)");
        class File_Flush_ResponseParams_Data {
        public:
            static File_Flush_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Flush_ResponseParams_Data))) File_Flush_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            File_Flush_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Flush_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Flush_ResponseParams_Data) == 16,
            "Bad sizeof(File_Flush_ResponseParams_Data)");
        constexpr uint32_t kFile_Lock_Name = 10;
        class File_Lock_Params_Data {
        public:
            static File_Lock_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Lock_Params_Data))) File_Lock_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            File_Lock_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Lock_Params_Data() = delete;
        };
        static_assert(sizeof(File_Lock_Params_Data) == 8,
            "Bad sizeof(File_Lock_Params_Data)");
        class File_Lock_ResponseParams_Data {
        public:
            static File_Lock_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Lock_ResponseParams_Data))) File_Lock_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            File_Lock_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Lock_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Lock_ResponseParams_Data) == 16,
            "Bad sizeof(File_Lock_ResponseParams_Data)");
        constexpr uint32_t kFile_Unlock_Name = 11;
        class File_Unlock_Params_Data {
        public:
            static File_Unlock_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Unlock_Params_Data))) File_Unlock_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            File_Unlock_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Unlock_Params_Data() = delete;
        };
        static_assert(sizeof(File_Unlock_Params_Data) == 8,
            "Bad sizeof(File_Unlock_Params_Data)");
        class File_Unlock_ResponseParams_Data {
        public:
            static File_Unlock_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_Unlock_ResponseParams_Data))) File_Unlock_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            File_Unlock_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_Unlock_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_Unlock_ResponseParams_Data) == 16,
            "Bad sizeof(File_Unlock_ResponseParams_Data)");
        constexpr uint32_t kFile_AsHandle_Name = 12;
        class File_AsHandle_Params_Data {
        public:
            static File_AsHandle_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_AsHandle_Params_Data))) File_AsHandle_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            File_AsHandle_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_AsHandle_Params_Data() = delete;
        };
        static_assert(sizeof(File_AsHandle_Params_Data) == 8,
            "Bad sizeof(File_AsHandle_Params_Data)");
        class File_AsHandle_ResponseParams_Data {
        public:
            static File_AsHandle_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(File_AsHandle_ResponseParams_Data))) File_AsHandle_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::File_Data> file_handle;

        private:
            File_AsHandle_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~File_AsHandle_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(File_AsHandle_ResponseParams_Data) == 24,
            "Bad sizeof(File_AsHandle_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace filesystem

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_MOJOM_SHARED_INTERNAL_H_