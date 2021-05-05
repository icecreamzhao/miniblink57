// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_SELECTION_BOUND_MOJOM_SHARED_INTERNAL_H_
#define UI_GFX_MOJO_SELECTION_BOUND_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

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
namespace gfx {
namespace mojom {
    namespace internal {
        class SelectionBound_Data;

        struct SelectionBoundType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
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
        class SelectionBound_Data {
        public:
            static SelectionBound_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SelectionBound_Data))) SelectionBound_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            uint8_t visible : 1;
            uint8_t pad1_[3];
            mojo::internal::Pointer<::gfx::mojom::internal::PointF_Data> edge_top;
            mojo::internal::Pointer<::gfx::mojom::internal::PointF_Data> edge_bottom;

        private:
            SelectionBound_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SelectionBound_Data() = delete;
        };
        static_assert(sizeof(SelectionBound_Data) == 32,
            "Bad sizeof(SelectionBound_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gfx

#endif // UI_GFX_MOJO_SELECTION_BOUND_MOJOM_SHARED_INTERNAL_H_