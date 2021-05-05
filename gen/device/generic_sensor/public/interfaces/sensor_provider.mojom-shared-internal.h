// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_PROVIDER_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_PROVIDER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "device/generic_sensor/public/interfaces/sensor.mojom-shared-internal.h"
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
        class SensorInitParams_Data;

#pragma pack(push, 1)
        class SensorInitParams_Data {
        public:
            static SensorInitParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SensorInitParams_Data))) SensorInitParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data memory;
            int32_t mode;
            uint64_t buffer_offset;
            mojo::internal::Pointer<::device::mojom::internal::SensorConfiguration_Data> default_configuration;
            double maximum_frequency;

        private:
            SensorInitParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SensorInitParams_Data() = delete;
        };
        static_assert(sizeof(SensorInitParams_Data) == 40,
            "Bad sizeof(SensorInitParams_Data)");
        constexpr uint32_t kSensorProvider_GetSensor_Name = 0;
        class SensorProvider_GetSensor_Params_Data {
        public:
            static SensorProvider_GetSensor_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SensorProvider_GetSensor_Params_Data))) SensorProvider_GetSensor_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            mojo::internal::Handle_Data sensor_request;

        private:
            SensorProvider_GetSensor_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SensorProvider_GetSensor_Params_Data() = delete;
        };
        static_assert(sizeof(SensorProvider_GetSensor_Params_Data) == 16,
            "Bad sizeof(SensorProvider_GetSensor_Params_Data)");
        class SensorProvider_GetSensor_ResponseParams_Data {
        public:
            static SensorProvider_GetSensor_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SensorProvider_GetSensor_ResponseParams_Data))) SensorProvider_GetSensor_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::SensorInitParams_Data> init_params;
            mojo::internal::Handle_Data client_request;
            uint8_t padfinal_[4];

        private:
            SensorProvider_GetSensor_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SensorProvider_GetSensor_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(SensorProvider_GetSensor_ResponseParams_Data) == 24,
            "Bad sizeof(SensorProvider_GetSensor_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_PROVIDER_MOJOM_SHARED_INTERNAL_H_