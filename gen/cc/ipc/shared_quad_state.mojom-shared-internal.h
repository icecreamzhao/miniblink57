// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SHARED_QUAD_STATE_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_SHARED_QUAD_STATE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"
#include "ui/gfx/mojo/transform.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {
        class SharedQuadState_Data;

#pragma pack(push, 1)
        class SharedQuadState_Data {
        public:
            static SharedQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SharedQuadState_Data))) SharedQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::Transform_Data> quad_to_target_transform;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> quad_layer_bounds;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> visible_quad_layer_rect;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> clip_rect;
            uint8_t is_clipped : 1;
            uint8_t pad4_[3];
            float opacity;
            uint32_t blend_mode;
            int32_t sorting_context_id;

        private:
            SharedQuadState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SharedQuadState_Data() = delete;
        };
        static_assert(sizeof(SharedQuadState_Data) == 56,
            "Bad sizeof(SharedQuadState_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_SHARED_QUAD_STATE_MOJOM_SHARED_INTERNAL_H_