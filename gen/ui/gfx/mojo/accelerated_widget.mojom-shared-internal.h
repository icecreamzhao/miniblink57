// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_ACCELERATED_WIDGET_MOJOM_SHARED_INTERNAL_H_
#define UI_GFX_MOJO_ACCELERATED_WIDGET_MOJOM_SHARED_INTERNAL_H_

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
        class AcceleratedWidget_Data;

#pragma pack(push, 1)
        class AcceleratedWidget_Data {
        public:
            static AcceleratedWidget_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AcceleratedWidget_Data))) AcceleratedWidget_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint64_t widget;

        private:
            AcceleratedWidget_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AcceleratedWidget_Data() = delete;
        };
        static_assert(sizeof(AcceleratedWidget_Data) == 16,
            "Bad sizeof(AcceleratedWidget_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gfx

#endif // UI_GFX_MOJO_ACCELERATED_WIDGET_MOJOM_SHARED_INTERNAL_H_