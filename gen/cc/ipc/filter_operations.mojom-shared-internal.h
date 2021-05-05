// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_FILTER_OPERATIONS_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_FILTER_OPERATIONS_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/filter_operation.mojom-shared-internal.h"
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
        class FilterOperations_Data;

#pragma pack(push, 1)
        class FilterOperations_Data {
        public:
            static FilterOperations_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FilterOperations_Data))) FilterOperations_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::cc::mojom::internal::FilterOperation_Data>>> operations;

        private:
            FilterOperations_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FilterOperations_Data() = delete;
        };
        static_assert(sizeof(FilterOperations_Data) == 16,
            "Bad sizeof(FilterOperations_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_FILTER_OPERATIONS_MOJOM_SHARED_INTERNAL_H_