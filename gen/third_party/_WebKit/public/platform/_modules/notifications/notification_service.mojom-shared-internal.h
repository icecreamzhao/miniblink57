// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "third_party/WebKit/public/platform/modules/permissions/permission_status.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace blink {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kNotificationService_GetPermissionStatus_Name = 0;
        class NotificationService_GetPermissionStatus_Params_Data {
        public:
            static NotificationService_GetPermissionStatus_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(NotificationService_GetPermissionStatus_Params_Data))) NotificationService_GetPermissionStatus_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> origin;

        private:
            NotificationService_GetPermissionStatus_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~NotificationService_GetPermissionStatus_Params_Data() = delete;
        };
        static_assert(sizeof(NotificationService_GetPermissionStatus_Params_Data) == 16,
            "Bad sizeof(NotificationService_GetPermissionStatus_Params_Data)");
        class NotificationService_GetPermissionStatus_ResponseParams_Data {
        public:
            static NotificationService_GetPermissionStatus_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(NotificationService_GetPermissionStatus_ResponseParams_Data))) NotificationService_GetPermissionStatus_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            NotificationService_GetPermissionStatus_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~NotificationService_GetPermissionStatus_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(NotificationService_GetPermissionStatus_ResponseParams_Data) == 16,
            "Bad sizeof(NotificationService_GetPermissionStatus_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_SERVICE_MOJOM_SHARED_INTERNAL_H_