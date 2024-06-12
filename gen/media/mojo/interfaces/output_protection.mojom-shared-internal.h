// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_OUTPUT_PROTECTION_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_OUTPUT_PROTECTION_MOJOM_SHARED_INTERNAL_H_

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
namespace media {
namespace mojom {
    namespace internal {

        struct OutputProtection_ProtectionType_Data {
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

        struct OutputProtection_LinkType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 4:
                case 8:
                case 16:
                case 32:
                case 64:
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
        constexpr uint32_t kOutputProtection_QueryStatus_Name = 0;
        class OutputProtection_QueryStatus_Params_Data {
        public:
            static OutputProtection_QueryStatus_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OutputProtection_QueryStatus_Params_Data))) OutputProtection_QueryStatus_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            OutputProtection_QueryStatus_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OutputProtection_QueryStatus_Params_Data() = delete;
        };
        static_assert(sizeof(OutputProtection_QueryStatus_Params_Data) == 8,
            "Bad sizeof(OutputProtection_QueryStatus_Params_Data)");
        class OutputProtection_QueryStatus_ResponseParams_Data {
        public:
            static OutputProtection_QueryStatus_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OutputProtection_QueryStatus_ResponseParams_Data))) OutputProtection_QueryStatus_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t pad0_[3];
            uint32_t link_mask;
            uint32_t protection_mask;
            uint8_t padfinal_[4];

        private:
            OutputProtection_QueryStatus_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OutputProtection_QueryStatus_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(OutputProtection_QueryStatus_ResponseParams_Data) == 24,
            "Bad sizeof(OutputProtection_QueryStatus_ResponseParams_Data)");
        constexpr uint32_t kOutputProtection_EnableProtection_Name = 1;
        class OutputProtection_EnableProtection_Params_Data {
        public:
            static OutputProtection_EnableProtection_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OutputProtection_EnableProtection_Params_Data))) OutputProtection_EnableProtection_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t desired_protection_mask;
            uint8_t padfinal_[4];

        private:
            OutputProtection_EnableProtection_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OutputProtection_EnableProtection_Params_Data() = delete;
        };
        static_assert(sizeof(OutputProtection_EnableProtection_Params_Data) == 16,
            "Bad sizeof(OutputProtection_EnableProtection_Params_Data)");
        class OutputProtection_EnableProtection_ResponseParams_Data {
        public:
            static OutputProtection_EnableProtection_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OutputProtection_EnableProtection_ResponseParams_Data))) OutputProtection_EnableProtection_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            OutputProtection_EnableProtection_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OutputProtection_EnableProtection_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(OutputProtection_EnableProtection_ResponseParams_Data) == 16,
            "Bad sizeof(OutputProtection_EnableProtection_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_OUTPUT_PROTECTION_MOJOM_SHARED_INTERNAL_H_