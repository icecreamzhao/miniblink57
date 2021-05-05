// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_SURFACE_HANDLE_MOJOM_SHARED_INTERNAL_H_
#define GPU_IPC_COMMON_SURFACE_HANDLE_MOJOM_SHARED_INTERNAL_H_

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
        class SurfaceHandle_Data;

#pragma pack(push, 1)
        class SurfaceHandle_Data {
        public:
            static SurfaceHandle_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SurfaceHandle_Data))) SurfaceHandle_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint64_t surface_handle;

        private:
            SurfaceHandle_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SurfaceHandle_Data() = delete;
        };
        static_assert(sizeof(SurfaceHandle_Data) == 16,
            "Bad sizeof(SurfaceHandle_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_SURFACE_HANDLE_MOJOM_SHARED_INTERNAL_H_