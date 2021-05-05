// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_TRANSFORM_MOJOM_SHARED_INTERNAL_H_
#define UI_GFX_MOJO_TRANSFORM_MOJOM_SHARED_INTERNAL_H_

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
namespace gfx {
namespace mojom {
    namespace internal {
        class Transform_Data;

#pragma pack(push, 1)
        class Transform_Data {
        public:
            static Transform_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Transform_Data))) Transform_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> matrix;

        private:
            Transform_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Transform_Data() = delete;
        };
        static_assert(sizeof(Transform_Data) == 16,
            "Bad sizeof(Transform_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gfx

#endif // UI_GFX_MOJO_TRANSFORM_MOJOM_SHARED_INTERNAL_H_