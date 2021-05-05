// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_DISCARDABLE_MEMORY_PUBLIC_INTERFACES_DISCARDABLE_SHARED_MEMORY_MANAGER_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_DISCARDABLE_MEMORY_PUBLIC_INTERFACES_DISCARDABLE_SHARED_MEMORY_MANAGER_MOJOM_SHARED_INTERNAL_H_

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
namespace discardable_memory {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kDiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Name = 0;
        class DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data {
        public:
            static DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data))) DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t size;
            int32_t id;

        private:
            DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data() = delete;
        };
        static_assert(sizeof(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data) == 16,
            "Bad sizeof(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data)");
        class DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data {
        public:
            static DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data))) DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data memory;
            uint8_t padfinal_[4];

        private:
            DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data) == 16,
            "Bad sizeof(DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data)");
        constexpr uint32_t kDiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Name = 1;
        class DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data {
        public:
            static DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data))) DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t id;
            uint8_t padfinal_[4];

        private:
            DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data() = delete;
        };
        static_assert(sizeof(DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data) == 16,
            "Bad sizeof(DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace discardable_memory

#endif // COMPONENTS_DISCARDABLE_MEMORY_PUBLIC_INTERFACES_DISCARDABLE_SHARED_MEMORY_MANAGER_MOJOM_SHARED_INTERNAL_H_