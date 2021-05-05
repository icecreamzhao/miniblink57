// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_RANGE_MOJO_RANGE_MOJOM_SHARED_INTERNAL_H_
#define UI_GFX_RANGE_MOJO_RANGE_MOJOM_SHARED_INTERNAL_H_

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
        class Range_Data;
        class RangeF_Data;

#pragma pack(push, 1)
        class Range_Data {
        public:
            static Range_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Range_Data))) Range_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t start;
            uint32_t end;

        private:
            Range_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Range_Data() = delete;
        };
        static_assert(sizeof(Range_Data) == 16,
            "Bad sizeof(Range_Data)");
        class RangeF_Data {
        public:
            static RangeF_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RangeF_Data))) RangeF_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float start;
            float end;

        private:
            RangeF_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RangeF_Data() = delete;
        };
        static_assert(sizeof(RangeF_Data) == 16,
            "Bad sizeof(RangeF_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gfx

#endif // UI_GFX_RANGE_MOJO_RANGE_MOJOM_SHARED_INTERNAL_H_