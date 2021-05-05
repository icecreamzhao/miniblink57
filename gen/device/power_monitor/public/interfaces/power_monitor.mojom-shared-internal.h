// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_POWER_MONITOR_PUBLIC_INTERFACES_POWER_MONITOR_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_POWER_MONITOR_PUBLIC_INTERFACES_POWER_MONITOR_MOJOM_SHARED_INTERNAL_H_

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
        constexpr uint32_t kPowerMonitor_SetClient_Name = 0;
        class PowerMonitor_SetClient_Params_Data {
        public:
            static PowerMonitor_SetClient_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PowerMonitor_SetClient_Params_Data))) PowerMonitor_SetClient_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data client;

        private:
            PowerMonitor_SetClient_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PowerMonitor_SetClient_Params_Data() = delete;
        };
        static_assert(sizeof(PowerMonitor_SetClient_Params_Data) == 16,
            "Bad sizeof(PowerMonitor_SetClient_Params_Data)");
        constexpr uint32_t kPowerMonitorClient_PowerStateChange_Name = 0;
        class PowerMonitorClient_PowerStateChange_Params_Data {
        public:
            static PowerMonitorClient_PowerStateChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PowerMonitorClient_PowerStateChange_Params_Data))) PowerMonitorClient_PowerStateChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t on_battery_power : 1;
            uint8_t padfinal_[7];

        private:
            PowerMonitorClient_PowerStateChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PowerMonitorClient_PowerStateChange_Params_Data() = delete;
        };
        static_assert(sizeof(PowerMonitorClient_PowerStateChange_Params_Data) == 16,
            "Bad sizeof(PowerMonitorClient_PowerStateChange_Params_Data)");
        constexpr uint32_t kPowerMonitorClient_Suspend_Name = 1;
        class PowerMonitorClient_Suspend_Params_Data {
        public:
            static PowerMonitorClient_Suspend_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PowerMonitorClient_Suspend_Params_Data))) PowerMonitorClient_Suspend_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PowerMonitorClient_Suspend_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PowerMonitorClient_Suspend_Params_Data() = delete;
        };
        static_assert(sizeof(PowerMonitorClient_Suspend_Params_Data) == 8,
            "Bad sizeof(PowerMonitorClient_Suspend_Params_Data)");
        constexpr uint32_t kPowerMonitorClient_Resume_Name = 2;
        class PowerMonitorClient_Resume_Params_Data {
        public:
            static PowerMonitorClient_Resume_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PowerMonitorClient_Resume_Params_Data))) PowerMonitorClient_Resume_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PowerMonitorClient_Resume_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PowerMonitorClient_Resume_Params_Data() = delete;
        };
        static_assert(sizeof(PowerMonitorClient_Resume_Params_Data) == 8,
            "Bad sizeof(PowerMonitorClient_Resume_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_POWER_MONITOR_PUBLIC_INTERFACES_POWER_MONITOR_MOJOM_SHARED_INTERNAL_H_