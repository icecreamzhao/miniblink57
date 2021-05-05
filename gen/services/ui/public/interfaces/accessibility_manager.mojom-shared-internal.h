// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_ACCESSIBILITY_MANAGER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_ACCESSIBILITY_MANAGER_MOJOM_SHARED_INTERNAL_H_

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
namespace ui {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kAccessibilityManager_SetHighContrastMode_Name = 0;
        class AccessibilityManager_SetHighContrastMode_Params_Data {
        public:
            static AccessibilityManager_SetHighContrastMode_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AccessibilityManager_SetHighContrastMode_Params_Data))) AccessibilityManager_SetHighContrastMode_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t enabled : 1;
            uint8_t padfinal_[7];

        private:
            AccessibilityManager_SetHighContrastMode_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AccessibilityManager_SetHighContrastMode_Params_Data() = delete;
        };
        static_assert(sizeof(AccessibilityManager_SetHighContrastMode_Params_Data) == 16,
            "Bad sizeof(AccessibilityManager_SetHighContrastMode_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_ACCESSIBILITY_MANAGER_MOJOM_SHARED_INTERNAL_H_