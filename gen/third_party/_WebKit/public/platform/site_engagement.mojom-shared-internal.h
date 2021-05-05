// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_SITE_ENGAGEMENT_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_SITE_ENGAGEMENT_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/origin.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace blink {
namespace mojom {
    namespace internal {

        struct EngagementLevel_Data {
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
        constexpr uint32_t kEngagementClient_SetEngagementLevel_Name = 0;
        class EngagementClient_SetEngagementLevel_Params_Data {
        public:
            static EngagementClient_SetEngagementLevel_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EngagementClient_SetEngagementLevel_Params_Data))) EngagementClient_SetEngagementLevel_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> origin;
            int32_t level;
            uint8_t padfinal_[4];

        private:
            EngagementClient_SetEngagementLevel_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EngagementClient_SetEngagementLevel_Params_Data() = delete;
        };
        static_assert(sizeof(EngagementClient_SetEngagementLevel_Params_Data) == 24,
            "Bad sizeof(EngagementClient_SetEngagementLevel_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_SITE_ENGAGEMENT_MOJOM_SHARED_INTERNAL_H_