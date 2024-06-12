// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_WAKE_LOCK_PUBLIC_INTERFACES_WAKE_LOCK_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_WAKE_LOCK_PUBLIC_INTERFACES_WAKE_LOCK_SERVICE_MOJOM_SHARED_INTERNAL_H_

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
namespace device {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kWakeLockService_RequestWakeLock_Name = 0;
        class WakeLockService_RequestWakeLock_Params_Data {
        public:
            static WakeLockService_RequestWakeLock_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WakeLockService_RequestWakeLock_Params_Data))) WakeLockService_RequestWakeLock_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            WakeLockService_RequestWakeLock_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WakeLockService_RequestWakeLock_Params_Data() = delete;
        };
        static_assert(sizeof(WakeLockService_RequestWakeLock_Params_Data) == 8,
            "Bad sizeof(WakeLockService_RequestWakeLock_Params_Data)");
        constexpr uint32_t kWakeLockService_CancelWakeLock_Name = 1;
        class WakeLockService_CancelWakeLock_Params_Data {
        public:
            static WakeLockService_CancelWakeLock_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WakeLockService_CancelWakeLock_Params_Data))) WakeLockService_CancelWakeLock_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            WakeLockService_CancelWakeLock_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WakeLockService_CancelWakeLock_Params_Data() = delete;
        };
        static_assert(sizeof(WakeLockService_CancelWakeLock_Params_Data) == 8,
            "Bad sizeof(WakeLockService_CancelWakeLock_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_WAKE_LOCK_PUBLIC_INTERFACES_WAKE_LOCK_SERVICE_MOJOM_SHARED_INTERNAL_H_