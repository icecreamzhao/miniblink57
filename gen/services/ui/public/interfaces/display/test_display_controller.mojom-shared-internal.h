// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_TEST_DISPLAY_CONTROLLER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_TEST_DISPLAY_CONTROLLER_MOJOM_SHARED_INTERNAL_H_

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
namespace display {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kTestDisplayController_ToggleAddRemoveDisplay_Name = 0;
        class TestDisplayController_ToggleAddRemoveDisplay_Params_Data {
        public:
            static TestDisplayController_ToggleAddRemoveDisplay_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TestDisplayController_ToggleAddRemoveDisplay_Params_Data))) TestDisplayController_ToggleAddRemoveDisplay_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            TestDisplayController_ToggleAddRemoveDisplay_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TestDisplayController_ToggleAddRemoveDisplay_Params_Data() = delete;
        };
        static_assert(sizeof(TestDisplayController_ToggleAddRemoveDisplay_Params_Data) == 8,
            "Bad sizeof(TestDisplayController_ToggleAddRemoveDisplay_Params_Data)");
        constexpr uint32_t kTestDisplayController_ToggleDisplayResolution_Name = 1;
        class TestDisplayController_ToggleDisplayResolution_Params_Data {
        public:
            static TestDisplayController_ToggleDisplayResolution_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TestDisplayController_ToggleDisplayResolution_Params_Data))) TestDisplayController_ToggleDisplayResolution_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            TestDisplayController_ToggleDisplayResolution_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TestDisplayController_ToggleDisplayResolution_Params_Data() = delete;
        };
        static_assert(sizeof(TestDisplayController_ToggleDisplayResolution_Params_Data) == 8,
            "Bad sizeof(TestDisplayController_ToggleDisplayResolution_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace display

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_TEST_DISPLAY_CONTROLLER_MOJOM_SHARED_INTERNAL_H_