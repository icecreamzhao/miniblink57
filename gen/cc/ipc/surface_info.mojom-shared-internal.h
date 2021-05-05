// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SURFACE_INFO_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_SURFACE_INFO_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/surface_id.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {
        class SurfaceInfo_Data;

#pragma pack(push, 1)
        class SurfaceInfo_Data {
        public:
            static SurfaceInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SurfaceInfo_Data))) SurfaceInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceId_Data> surface_id;
            float device_scale_factor;
            uint8_t pad1_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> size_in_pixels;

        private:
            SurfaceInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SurfaceInfo_Data() = delete;
        };
        static_assert(sizeof(SurfaceInfo_Data) == 32,
            "Bad sizeof(SurfaceInfo_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_SURFACE_INFO_MOJOM_SHARED_INTERNAL_H_