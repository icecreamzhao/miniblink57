// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_TIME_ZONE_MONITOR_PUBLIC_INTERFACES_TIME_ZONE_MONITOR_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_TIME_ZONE_MONITOR_PUBLIC_INTERFACES_TIME_ZONE_MONITOR_MOJOM_SHARED_INTERNAL_H_

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
        constexpr uint32_t kTimeZoneMonitor_AddClient_Name = 0;
        class TimeZoneMonitor_AddClient_Params_Data {
        public:
            static TimeZoneMonitor_AddClient_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TimeZoneMonitor_AddClient_Params_Data))) TimeZoneMonitor_AddClient_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data client;

        private:
            TimeZoneMonitor_AddClient_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TimeZoneMonitor_AddClient_Params_Data() = delete;
        };
        static_assert(sizeof(TimeZoneMonitor_AddClient_Params_Data) == 16,
            "Bad sizeof(TimeZoneMonitor_AddClient_Params_Data)");
        constexpr uint32_t kTimeZoneMonitorClient_OnTimeZoneChange_Name = 0;
        class TimeZoneMonitorClient_OnTimeZoneChange_Params_Data {
        public:
            static TimeZoneMonitorClient_OnTimeZoneChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TimeZoneMonitorClient_OnTimeZoneChange_Params_Data))) TimeZoneMonitorClient_OnTimeZoneChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> tz_info;

        private:
            TimeZoneMonitorClient_OnTimeZoneChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TimeZoneMonitorClient_OnTimeZoneChange_Params_Data() = delete;
        };
        static_assert(sizeof(TimeZoneMonitorClient_OnTimeZoneChange_Params_Data) == 16,
            "Bad sizeof(TimeZoneMonitorClient_OnTimeZoneChange_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_TIME_ZONE_MONITOR_PUBLIC_INTERFACES_TIME_ZONE_MONITOR_MOJOM_SHARED_INTERNAL_H_