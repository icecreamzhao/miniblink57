// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_BATTERY_BATTERY_MONITOR_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_BATTERY_BATTERY_MONITOR_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "device/battery/battery_status.mojom-shared-internal.h"
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

#pragma pack(push, 1)
    constexpr uint32_t kBatteryMonitor_QueryNextStatus_Name = 0;
    class BatteryMonitor_QueryNextStatus_Params_Data {
    public:
        static BatteryMonitor_QueryNextStatus_Params_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(BatteryMonitor_QueryNextStatus_Params_Data))) BatteryMonitor_QueryNextStatus_Params_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;

    private:
        BatteryMonitor_QueryNextStatus_Params_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~BatteryMonitor_QueryNextStatus_Params_Data() = delete;
    };
    static_assert(sizeof(BatteryMonitor_QueryNextStatus_Params_Data) == 8,
        "Bad sizeof(BatteryMonitor_QueryNextStatus_Params_Data)");
    class BatteryMonitor_QueryNextStatus_ResponseParams_Data {
    public:
        static BatteryMonitor_QueryNextStatus_ResponseParams_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(BatteryMonitor_QueryNextStatus_ResponseParams_Data))) BatteryMonitor_QueryNextStatus_ResponseParams_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;
        mojo::internal::Pointer<::device::internal::BatteryStatus_Data> status;

    private:
        BatteryMonitor_QueryNextStatus_ResponseParams_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~BatteryMonitor_QueryNextStatus_ResponseParams_Data() = delete;
    };
    static_assert(sizeof(BatteryMonitor_QueryNextStatus_ResponseParams_Data) == 16,
        "Bad sizeof(BatteryMonitor_QueryNextStatus_ResponseParams_Data)");

#pragma pack(pop)

} // namespace internal
} // namespace device

#endif // DEVICE_BATTERY_BATTERY_MONITOR_MOJOM_SHARED_INTERNAL_H_