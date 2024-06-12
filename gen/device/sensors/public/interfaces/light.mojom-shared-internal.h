// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SENSORS_PUBLIC_INTERFACES_LIGHT_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_SENSORS_PUBLIC_INTERFACES_LIGHT_MOJOM_SHARED_INTERNAL_H_

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
        constexpr uint32_t kLightSensor_StartPolling_Name = 0;
        class LightSensor_StartPolling_Params_Data {
        public:
            static LightSensor_StartPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LightSensor_StartPolling_Params_Data))) LightSensor_StartPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            LightSensor_StartPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LightSensor_StartPolling_Params_Data() = delete;
        };
        static_assert(sizeof(LightSensor_StartPolling_Params_Data) == 8,
            "Bad sizeof(LightSensor_StartPolling_Params_Data)");
        class LightSensor_StartPolling_ResponseParams_Data {
        public:
            static LightSensor_StartPolling_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LightSensor_StartPolling_ResponseParams_Data))) LightSensor_StartPolling_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data memory_handle;
            uint8_t padfinal_[4];

        private:
            LightSensor_StartPolling_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LightSensor_StartPolling_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(LightSensor_StartPolling_ResponseParams_Data) == 16,
            "Bad sizeof(LightSensor_StartPolling_ResponseParams_Data)");
        constexpr uint32_t kLightSensor_StopPolling_Name = 1;
        class LightSensor_StopPolling_Params_Data {
        public:
            static LightSensor_StopPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LightSensor_StopPolling_Params_Data))) LightSensor_StopPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            LightSensor_StopPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LightSensor_StopPolling_Params_Data() = delete;
        };
        static_assert(sizeof(LightSensor_StopPolling_Params_Data) == 8,
            "Bad sizeof(LightSensor_StopPolling_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_SENSORS_PUBLIC_INTERFACES_LIGHT_MOJOM_SHARED_INTERNAL_H_