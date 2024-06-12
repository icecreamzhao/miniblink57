// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SENSORS_PUBLIC_INTERFACES_MOTION_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_SENSORS_PUBLIC_INTERFACES_MOTION_MOJOM_SHARED_INTERNAL_H_

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
        constexpr uint32_t kMotionSensor_StartPolling_Name = 0;
        class MotionSensor_StartPolling_Params_Data {
        public:
            static MotionSensor_StartPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MotionSensor_StartPolling_Params_Data))) MotionSensor_StartPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            MotionSensor_StartPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MotionSensor_StartPolling_Params_Data() = delete;
        };
        static_assert(sizeof(MotionSensor_StartPolling_Params_Data) == 8,
            "Bad sizeof(MotionSensor_StartPolling_Params_Data)");
        class MotionSensor_StartPolling_ResponseParams_Data {
        public:
            static MotionSensor_StartPolling_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MotionSensor_StartPolling_ResponseParams_Data))) MotionSensor_StartPolling_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data memory_handle;
            uint8_t padfinal_[4];

        private:
            MotionSensor_StartPolling_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MotionSensor_StartPolling_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(MotionSensor_StartPolling_ResponseParams_Data) == 16,
            "Bad sizeof(MotionSensor_StartPolling_ResponseParams_Data)");
        constexpr uint32_t kMotionSensor_StopPolling_Name = 1;
        class MotionSensor_StopPolling_Params_Data {
        public:
            static MotionSensor_StopPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MotionSensor_StopPolling_Params_Data))) MotionSensor_StopPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            MotionSensor_StopPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MotionSensor_StopPolling_Params_Data() = delete;
        };
        static_assert(sizeof(MotionSensor_StopPolling_Params_Data) == 8,
            "Bad sizeof(MotionSensor_StopPolling_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_SENSORS_PUBLIC_INTERFACES_MOTION_MOJOM_SHARED_INTERNAL_H_