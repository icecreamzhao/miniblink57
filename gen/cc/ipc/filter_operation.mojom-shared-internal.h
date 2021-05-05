// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_FILTER_OPERATION_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_FILTER_OPERATION_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "skia/public/interfaces/image_filter.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {
        class FilterOperation_Data;

        struct FilterType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
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
        class FilterOperation_Data {
        public:
            static FilterOperation_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FilterOperation_Data))) FilterOperation_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            float amount;
            mojo::internal::Pointer<::gfx::mojom::internal::Point_Data> drop_shadow_offset;
            uint32_t drop_shadow_color;
            int32_t zoom_inset;
            mojo::internal::Pointer<::skia::mojom::internal::ImageFilter_Data> image_filter;
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> matrix;

        private:
            FilterOperation_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FilterOperation_Data() = delete;
        };
        static_assert(sizeof(FilterOperation_Data) == 48,
            "Bad sizeof(FilterOperation_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_FILTER_OPERATION_MOJOM_SHARED_INTERNAL_H_