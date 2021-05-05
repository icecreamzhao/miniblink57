// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "components/filesystem/public/interfaces/directory.mojom-shared-internal.h"
#include "components/filesystem/public/interfaces/types.mojom-shared-internal.h"
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
        constexpr uint32_t kFileSystem_OpenTempDirectory_Name = 0;
        class FileSystem_OpenTempDirectory_Params_Data {
        public:
            static FileSystem_OpenTempDirectory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileSystem_OpenTempDirectory_Params_Data))) FileSystem_OpenTempDirectory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data directory;
            uint8_t padfinal_[4];

        private:
            FileSystem_OpenTempDirectory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileSystem_OpenTempDirectory_Params_Data() = delete;
        };
        static_assert(sizeof(FileSystem_OpenTempDirectory_Params_Data) == 16,
            "Bad sizeof(FileSystem_OpenTempDirectory_Params_Data)");
        class FileSystem_OpenTempDirectory_ResponseParams_Data {
        public:
            static FileSystem_OpenTempDirectory_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileSystem_OpenTempDirectory_ResponseParams_Data))) FileSystem_OpenTempDirectory_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            FileSystem_OpenTempDirectory_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileSystem_OpenTempDirectory_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(FileSystem_OpenTempDirectory_ResponseParams_Data) == 16,
            "Bad sizeof(FileSystem_OpenTempDirectory_ResponseParams_Data)");
        constexpr uint32_t kFileSystem_OpenPersistentFileSystem_Name = 1;
        class FileSystem_OpenPersistentFileSystem_Params_Data {
        public:
            static FileSystem_OpenPersistentFileSystem_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileSystem_OpenPersistentFileSystem_Params_Data))) FileSystem_OpenPersistentFileSystem_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data directory;
            uint8_t padfinal_[4];

        private:
            FileSystem_OpenPersistentFileSystem_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileSystem_OpenPersistentFileSystem_Params_Data() = delete;
        };
        static_assert(sizeof(FileSystem_OpenPersistentFileSystem_Params_Data) == 16,
            "Bad sizeof(FileSystem_OpenPersistentFileSystem_Params_Data)");
        class FileSystem_OpenPersistentFileSystem_ResponseParams_Data {
        public:
            static FileSystem_OpenPersistentFileSystem_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileSystem_OpenPersistentFileSystem_ResponseParams_Data))) FileSystem_OpenPersistentFileSystem_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            FileSystem_OpenPersistentFileSystem_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileSystem_OpenPersistentFileSystem_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(FileSystem_OpenPersistentFileSystem_ResponseParams_Data) == 16,
            "Bad sizeof(FileSystem_OpenPersistentFileSystem_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace filesystem

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_INTERNAL_H_