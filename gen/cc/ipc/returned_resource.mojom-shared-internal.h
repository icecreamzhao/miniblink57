// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_RETURNED_RESOURCE_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_RETURNED_RESOURCE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "gpu/ipc/common/sync_token.mojom-shared-internal.h"
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
namespace cc {
namespace mojom {
    namespace internal {
        class ReturnedResource_Data;
        class ReturnedResourceArray_Data;

#pragma pack(push, 1)
        class ReturnedResource_Data {
        public:
            static ReturnedResource_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ReturnedResource_Data))) ReturnedResource_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t id;
            int32_t count;
            mojo::internal::Pointer<::gpu::mojom::internal::SyncToken_Data> sync_token;
            uint8_t lost : 1;
            uint8_t padfinal_[7];

        private:
            ReturnedResource_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ReturnedResource_Data() = delete;
        };
        static_assert(sizeof(ReturnedResource_Data) == 32,
            "Bad sizeof(ReturnedResource_Data)");
        class ReturnedResourceArray_Data {
        public:
            static ReturnedResourceArray_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ReturnedResourceArray_Data))) ReturnedResourceArray_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::ReturnedResource_Data>>> returned_resources;

        private:
            ReturnedResourceArray_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ReturnedResourceArray_Data() = delete;
        };
        static_assert(sizeof(ReturnedResourceArray_Data) == 16,
            "Bad sizeof(ReturnedResourceArray_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_RETURNED_RESOURCE_MOJOM_SHARED_INTERNAL_H_