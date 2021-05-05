// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SENSITIVE_INPUT_VISIBILITY_SENSITIVE_INPUT_VISIBILITY_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SENSITIVE_INPUT_VISIBILITY_SENSITIVE_INPUT_VISIBILITY_SERVICE_MOJOM_SHARED_INTERNAL_H_

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
namespace blink {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kSensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Name = 0;
        class SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data {
        public:
            static SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data))) SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data() = delete;
        };
        static_assert(sizeof(SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data) == 8,
            "Bad sizeof(SensitiveInputVisibilityService_PasswordFieldVisibleInInsecureContext_Params_Data)");
        constexpr uint32_t kSensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Name = 1;
        class SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data {
        public:
            static SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data))) SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data() = delete;
        };
        static_assert(sizeof(SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data) == 8,
            "Bad sizeof(SensitiveInputVisibilityService_AllPasswordFieldsInInsecureContextInvisible_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SENSITIVE_INPUT_VISIBILITY_SENSITIVE_INPUT_VISIBILITY_SERVICE_MOJOM_SHARED_INTERNAL_H_