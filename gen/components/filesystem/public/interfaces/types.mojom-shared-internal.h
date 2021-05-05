// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_TYPES_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_TYPES_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

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
        class TimespecOrNow_Data;
        class FileInformation_Data;
        class DirectoryEntry_Data;

        struct FileError_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case -16:
                case -15:
                case -14:
                case -13:
                case -12:
                case -11:
                case -10:
                case -9:
                case -8:
                case -7:
                case -6:
                case -5:
                case -4:
                case -3:
                case -2:
                case -1:
                case 0:
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

        struct Whence_Data {
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

        struct FsFileType_Data {
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
        class TimespecOrNow_Data {
        public:
            static TimespecOrNow_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TimespecOrNow_Data))) TimespecOrNow_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t now : 1;
            uint8_t pad0_[7];
            double seconds;

        private:
            TimespecOrNow_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TimespecOrNow_Data() = delete;
        };
        static_assert(sizeof(TimespecOrNow_Data) == 24,
            "Bad sizeof(TimespecOrNow_Data)");
        class FileInformation_Data {
        public:
            static FileInformation_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FileInformation_Data))) FileInformation_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            uint8_t pad0_[4];
            int64_t size;
            double atime;
            double mtime;
            double ctime;

        private:
            FileInformation_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FileInformation_Data() = delete;
        };
        static_assert(sizeof(FileInformation_Data) == 48,
            "Bad sizeof(FileInformation_Data)");
        class DirectoryEntry_Data {
        public:
            static DirectoryEntry_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DirectoryEntry_Data))) DirectoryEntry_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> name;

        private:
            DirectoryEntry_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DirectoryEntry_Data() = delete;
        };
        static_assert(sizeof(DirectoryEntry_Data) == 24,
            "Bad sizeof(DirectoryEntry_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace filesystem

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_TYPES_MOJOM_SHARED_INTERNAL_H_