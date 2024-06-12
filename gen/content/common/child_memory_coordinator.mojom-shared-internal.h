// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_CHILD_MEMORY_COORDINATOR_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_CHILD_MEMORY_COORDINATOR_MOJOM_SHARED_INTERNAL_H_

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
namespace content {
namespace mojom {
    namespace internal {

        struct MemoryState_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case -1:
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
        constexpr uint32_t kChildMemoryCoordinator_OnStateChange_Name = 0;
        class ChildMemoryCoordinator_OnStateChange_Params_Data {
        public:
            static ChildMemoryCoordinator_OnStateChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ChildMemoryCoordinator_OnStateChange_Params_Data))) ChildMemoryCoordinator_OnStateChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t state;
            uint8_t padfinal_[4];

        private:
            ChildMemoryCoordinator_OnStateChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ChildMemoryCoordinator_OnStateChange_Params_Data() = delete;
        };
        static_assert(sizeof(ChildMemoryCoordinator_OnStateChange_Params_Data) == 16,
            "Bad sizeof(ChildMemoryCoordinator_OnStateChange_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_CHILD_MEMORY_COORDINATOR_MOJOM_SHARED_INTERNAL_H_