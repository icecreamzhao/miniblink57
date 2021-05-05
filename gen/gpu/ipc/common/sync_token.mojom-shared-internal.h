// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_SYNC_TOKEN_MOJOM_SHARED_INTERNAL_H_
#define GPU_IPC_COMMON_SYNC_TOKEN_MOJOM_SHARED_INTERNAL_H_

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
namespace gpu {
namespace mojom {
    namespace internal {
        class SyncToken_Data;

        struct CommandBufferNamespace_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case -1:
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
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
        class SyncToken_Data {
        public:
            static SyncToken_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SyncToken_Data))) SyncToken_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t verified_flush : 1;
            uint8_t pad0_[3];
            int32_t namespace_id;
            int32_t extra_data_field;
            uint8_t pad2_[4];
            uint64_t command_buffer_id;
            uint64_t release_count;

        private:
            SyncToken_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SyncToken_Data() = delete;
        };
        static_assert(sizeof(SyncToken_Data) == 40,
            "Bad sizeof(SyncToken_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_SYNC_TOKEN_MOJOM_SHARED_INTERNAL_H_