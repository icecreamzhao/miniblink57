// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_MOJOM_SHARED_INTERNAL_H_

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
namespace display {
namespace mojom {
    namespace internal {
        class Display_Data;

        struct Rotation_Data {
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

        struct TouchSupport_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
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
        class Display_Data {
        public:
            static Display_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Display_Data))) Display_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t id;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> bounds;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> work_area;
            float device_scale_factor;
            int32_t rotation;
            int32_t touch_support;
            uint8_t pad5_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> maximum_cursor_size;

        private:
            Display_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Display_Data() = delete;
        };
        static_assert(sizeof(Display_Data) == 56,
            "Bad sizeof(Display_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace display

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_MOJOM_SHARED_INTERNAL_H_