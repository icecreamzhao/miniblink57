// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SENSORS_PUBLIC_INTERFACES_ORIENTATION_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_SENSORS_PUBLIC_INTERFACES_ORIENTATION_MOJOM_SHARED_INTERNAL_H_

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
        constexpr uint32_t kOrientationAbsoluteSensor_StartPolling_Name = 0;
        class OrientationAbsoluteSensor_StartPolling_Params_Data {
        public:
            static OrientationAbsoluteSensor_StartPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OrientationAbsoluteSensor_StartPolling_Params_Data))) OrientationAbsoluteSensor_StartPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            OrientationAbsoluteSensor_StartPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OrientationAbsoluteSensor_StartPolling_Params_Data() = delete;
        };
        static_assert(sizeof(OrientationAbsoluteSensor_StartPolling_Params_Data) == 8,
            "Bad sizeof(OrientationAbsoluteSensor_StartPolling_Params_Data)");
        class OrientationAbsoluteSensor_StartPolling_ResponseParams_Data {
        public:
            static OrientationAbsoluteSensor_StartPolling_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OrientationAbsoluteSensor_StartPolling_ResponseParams_Data))) OrientationAbsoluteSensor_StartPolling_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data memory_handle;
            uint8_t padfinal_[4];

        private:
            OrientationAbsoluteSensor_StartPolling_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OrientationAbsoluteSensor_StartPolling_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(OrientationAbsoluteSensor_StartPolling_ResponseParams_Data) == 16,
            "Bad sizeof(OrientationAbsoluteSensor_StartPolling_ResponseParams_Data)");
        constexpr uint32_t kOrientationAbsoluteSensor_StopPolling_Name = 1;
        class OrientationAbsoluteSensor_StopPolling_Params_Data {
        public:
            static OrientationAbsoluteSensor_StopPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OrientationAbsoluteSensor_StopPolling_Params_Data))) OrientationAbsoluteSensor_StopPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            OrientationAbsoluteSensor_StopPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OrientationAbsoluteSensor_StopPolling_Params_Data() = delete;
        };
        static_assert(sizeof(OrientationAbsoluteSensor_StopPolling_Params_Data) == 8,
            "Bad sizeof(OrientationAbsoluteSensor_StopPolling_Params_Data)");
        constexpr uint32_t kOrientationSensor_StartPolling_Name = 0;
        class OrientationSensor_StartPolling_Params_Data {
        public:
            static OrientationSensor_StartPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OrientationSensor_StartPolling_Params_Data))) OrientationSensor_StartPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            OrientationSensor_StartPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OrientationSensor_StartPolling_Params_Data() = delete;
        };
        static_assert(sizeof(OrientationSensor_StartPolling_Params_Data) == 8,
            "Bad sizeof(OrientationSensor_StartPolling_Params_Data)");
        class OrientationSensor_StartPolling_ResponseParams_Data {
        public:
            static OrientationSensor_StartPolling_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OrientationSensor_StartPolling_ResponseParams_Data))) OrientationSensor_StartPolling_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data memory_handle;
            uint8_t padfinal_[4];

        private:
            OrientationSensor_StartPolling_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OrientationSensor_StartPolling_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(OrientationSensor_StartPolling_ResponseParams_Data) == 16,
            "Bad sizeof(OrientationSensor_StartPolling_ResponseParams_Data)");
        constexpr uint32_t kOrientationSensor_StopPolling_Name = 1;
        class OrientationSensor_StopPolling_Params_Data {
        public:
            static OrientationSensor_StopPolling_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OrientationSensor_StopPolling_Params_Data))) OrientationSensor_StopPolling_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            OrientationSensor_StopPolling_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OrientationSensor_StopPolling_Params_Data() = delete;
        };
        static_assert(sizeof(OrientationSensor_StopPolling_Params_Data) == 8,
            "Bad sizeof(OrientationSensor_StopPolling_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_SENSORS_PUBLIC_INTERFACES_ORIENTATION_MOJOM_SHARED_INTERNAL_H_