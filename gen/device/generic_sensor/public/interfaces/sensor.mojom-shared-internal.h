// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_MOJOM_SHARED_INTERNAL_H_

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
        class SensorConfiguration_Data;

        struct SensorType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct ReportingMode_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)
        class SensorConfiguration_Data {
        public:
            static SensorConfiguration_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SensorConfiguration_Data))) SensorConfiguration_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            double frequency;

        private:
            SensorConfiguration_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SensorConfiguration_Data() = delete;
        };
        static_assert(sizeof(SensorConfiguration_Data) == 16,
            "Bad sizeof(SensorConfiguration_Data)");
        constexpr uint32_t kSensor_GetDefaultConfiguration_Name = 0;
        class Sensor_GetDefaultConfiguration_Params_Data {
        public:
            static Sensor_GetDefaultConfiguration_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Sensor_GetDefaultConfiguration_Params_Data))) Sensor_GetDefaultConfiguration_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Sensor_GetDefaultConfiguration_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Sensor_GetDefaultConfiguration_Params_Data() = delete;
        };
        static_assert(sizeof(Sensor_GetDefaultConfiguration_Params_Data) == 8,
            "Bad sizeof(Sensor_GetDefaultConfiguration_Params_Data)");
        class Sensor_GetDefaultConfiguration_ResponseParams_Data {
        public:
            static Sensor_GetDefaultConfiguration_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Sensor_GetDefaultConfiguration_ResponseParams_Data))) Sensor_GetDefaultConfiguration_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::SensorConfiguration_Data> configuration;

        private:
            Sensor_GetDefaultConfiguration_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Sensor_GetDefaultConfiguration_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Sensor_GetDefaultConfiguration_ResponseParams_Data) == 16,
            "Bad sizeof(Sensor_GetDefaultConfiguration_ResponseParams_Data)");
        constexpr uint32_t kSensor_AddConfiguration_Name = 1;
        class Sensor_AddConfiguration_Params_Data {
        public:
            static Sensor_AddConfiguration_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Sensor_AddConfiguration_Params_Data))) Sensor_AddConfiguration_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::SensorConfiguration_Data> configuration;

        private:
            Sensor_AddConfiguration_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Sensor_AddConfiguration_Params_Data() = delete;
        };
        static_assert(sizeof(Sensor_AddConfiguration_Params_Data) == 16,
            "Bad sizeof(Sensor_AddConfiguration_Params_Data)");
        class Sensor_AddConfiguration_ResponseParams_Data {
        public:
            static Sensor_AddConfiguration_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Sensor_AddConfiguration_ResponseParams_Data))) Sensor_AddConfiguration_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Sensor_AddConfiguration_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Sensor_AddConfiguration_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Sensor_AddConfiguration_ResponseParams_Data) == 16,
            "Bad sizeof(Sensor_AddConfiguration_ResponseParams_Data)");
        constexpr uint32_t kSensor_RemoveConfiguration_Name = 2;
        class Sensor_RemoveConfiguration_Params_Data {
        public:
            static Sensor_RemoveConfiguration_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Sensor_RemoveConfiguration_Params_Data))) Sensor_RemoveConfiguration_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::SensorConfiguration_Data> configuration;

        private:
            Sensor_RemoveConfiguration_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Sensor_RemoveConfiguration_Params_Data() = delete;
        };
        static_assert(sizeof(Sensor_RemoveConfiguration_Params_Data) == 16,
            "Bad sizeof(Sensor_RemoveConfiguration_Params_Data)");
        class Sensor_RemoveConfiguration_ResponseParams_Data {
        public:
            static Sensor_RemoveConfiguration_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Sensor_RemoveConfiguration_ResponseParams_Data))) Sensor_RemoveConfiguration_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Sensor_RemoveConfiguration_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Sensor_RemoveConfiguration_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Sensor_RemoveConfiguration_ResponseParams_Data) == 16,
            "Bad sizeof(Sensor_RemoveConfiguration_ResponseParams_Data)");
        constexpr uint32_t kSensor_Suspend_Name = 3;
        class Sensor_Suspend_Params_Data {
        public:
            static Sensor_Suspend_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Sensor_Suspend_Params_Data))) Sensor_Suspend_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Sensor_Suspend_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Sensor_Suspend_Params_Data() = delete;
        };
        static_assert(sizeof(Sensor_Suspend_Params_Data) == 8,
            "Bad sizeof(Sensor_Suspend_Params_Data)");
        constexpr uint32_t kSensor_Resume_Name = 4;
        class Sensor_Resume_Params_Data {
        public:
            static Sensor_Resume_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Sensor_Resume_Params_Data))) Sensor_Resume_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Sensor_Resume_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Sensor_Resume_Params_Data() = delete;
        };
        static_assert(sizeof(Sensor_Resume_Params_Data) == 8,
            "Bad sizeof(Sensor_Resume_Params_Data)");
        constexpr uint32_t kSensorClient_RaiseError_Name = 0;
        class SensorClient_RaiseError_Params_Data {
        public:
            static SensorClient_RaiseError_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SensorClient_RaiseError_Params_Data))) SensorClient_RaiseError_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            SensorClient_RaiseError_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SensorClient_RaiseError_Params_Data() = delete;
        };
        static_assert(sizeof(SensorClient_RaiseError_Params_Data) == 8,
            "Bad sizeof(SensorClient_RaiseError_Params_Data)");
        constexpr uint32_t kSensorClient_SensorReadingChanged_Name = 1;
        class SensorClient_SensorReadingChanged_Params_Data {
        public:
            static SensorClient_SensorReadingChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SensorClient_SensorReadingChanged_Params_Data))) SensorClient_SensorReadingChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            SensorClient_SensorReadingChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SensorClient_SensorReadingChanged_Params_Data() = delete;
        };
        static_assert(sizeof(SensorClient_SensorReadingChanged_Params_Data) == 8,
            "Bad sizeof(SensorClient_SensorReadingChanged_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_MOJOM_SHARED_INTERNAL_H_