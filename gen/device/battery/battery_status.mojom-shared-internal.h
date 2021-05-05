// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_BATTERY_BATTERY_STATUS_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_BATTERY_BATTERY_STATUS_MOJOM_SHARED_INTERNAL_H_

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
namespace internal {
    class BatteryStatus_Data;

#pragma pack(push, 1)
    class BatteryStatus_Data {
    public:
        static BatteryStatus_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(BatteryStatus_Data))) BatteryStatus_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;
        uint8_t charging : 1;
        uint8_t pad0_[7];
        double charging_time;
        double discharging_time;
        double level;

    private:
        BatteryStatus_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~BatteryStatus_Data() = delete;
    };
    static_assert(sizeof(BatteryStatus_Data) == 40,
        "Bad sizeof(BatteryStatus_Data)");

#pragma pack(pop)

} // namespace internal
} // namespace device

#endif // DEVICE_BATTERY_BATTERY_STATUS_MOJOM_SHARED_INTERNAL_H_