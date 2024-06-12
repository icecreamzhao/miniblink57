// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_FILE_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_FILE_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_INTERNAL_H_

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
namespace file {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kFileSystem_GetDirectory_Name = 0;
        class FileSystem_GetDirectory_Params_Data {
        public:
            static FileSystem_GetDirectory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileSystem_GetDirectory_Params_Data))) FileSystem_GetDirectory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data dir;
            uint8_t padfinal_[4];

        private:
            FileSystem_GetDirectory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileSystem_GetDirectory_Params_Data() = delete;
        };
        static_assert(sizeof(FileSystem_GetDirectory_Params_Data) == 16,
            "Bad sizeof(FileSystem_GetDirectory_Params_Data)");
        class FileSystem_GetDirectory_ResponseParams_Data {
        public:
            static FileSystem_GetDirectory_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileSystem_GetDirectory_ResponseParams_Data))) FileSystem_GetDirectory_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            FileSystem_GetDirectory_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileSystem_GetDirectory_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(FileSystem_GetDirectory_ResponseParams_Data) == 8,
            "Bad sizeof(FileSystem_GetDirectory_ResponseParams_Data)");
        constexpr uint32_t kFileSystem_GetSubDirectory_Name = 1;
        class FileSystem_GetSubDirectory_Params_Data {
        public:
            static FileSystem_GetSubDirectory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileSystem_GetSubDirectory_Params_Data))) FileSystem_GetSubDirectory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> dir_path;
            mojo::internal::Handle_Data dir;
            uint8_t padfinal_[4];

        private:
            FileSystem_GetSubDirectory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileSystem_GetSubDirectory_Params_Data() = delete;
        };
        static_assert(sizeof(FileSystem_GetSubDirectory_Params_Data) == 24,
            "Bad sizeof(FileSystem_GetSubDirectory_Params_Data)");
        class FileSystem_GetSubDirectory_ResponseParams_Data {
        public:
            static FileSystem_GetSubDirectory_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileSystem_GetSubDirectory_ResponseParams_Data))) FileSystem_GetSubDirectory_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t err;
            uint8_t padfinal_[4];

        private:
            FileSystem_GetSubDirectory_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileSystem_GetSubDirectory_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(FileSystem_GetSubDirectory_ResponseParams_Data) == 16,
            "Bad sizeof(FileSystem_GetSubDirectory_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace file

#endif // SERVICES_FILE_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_INTERNAL_H_