// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GEOLOCATION_PUBLIC_INTERFACES_GEOLOCATION_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_GEOLOCATION_PUBLIC_INTERFACES_GEOLOCATION_MOJOM_SHARED_INTERNAL_H_

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
        class Geoposition_Data;

        struct Geoposition_ErrorCode_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
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
        class Geoposition_Data {
        public:
            static Geoposition_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Geoposition_Data))) Geoposition_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t valid : 1;
            uint8_t pad0_[3];
            int32_t error_code;
            double latitude;
            double longitude;
            double altitude;
            double accuracy;
            double altitude_accuracy;
            double heading;
            double speed;
            double timestamp;
            mojo::internal::Pointer<mojo::internal::String_Data> error_message;

        private:
            Geoposition_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Geoposition_Data() = delete;
        };
        static_assert(sizeof(Geoposition_Data) == 88,
            "Bad sizeof(Geoposition_Data)");
        constexpr uint32_t kGeolocationService_SetHighAccuracy_Name = 0;
        class GeolocationService_SetHighAccuracy_Params_Data {
        public:
            static GeolocationService_SetHighAccuracy_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GeolocationService_SetHighAccuracy_Params_Data))) GeolocationService_SetHighAccuracy_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t high_accuracy : 1;
            uint8_t padfinal_[7];

        private:
            GeolocationService_SetHighAccuracy_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GeolocationService_SetHighAccuracy_Params_Data() = delete;
        };
        static_assert(sizeof(GeolocationService_SetHighAccuracy_Params_Data) == 16,
            "Bad sizeof(GeolocationService_SetHighAccuracy_Params_Data)");
        constexpr uint32_t kGeolocationService_QueryNextPosition_Name = 1;
        class GeolocationService_QueryNextPosition_Params_Data {
        public:
            static GeolocationService_QueryNextPosition_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GeolocationService_QueryNextPosition_Params_Data))) GeolocationService_QueryNextPosition_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            GeolocationService_QueryNextPosition_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GeolocationService_QueryNextPosition_Params_Data() = delete;
        };
        static_assert(sizeof(GeolocationService_QueryNextPosition_Params_Data) == 8,
            "Bad sizeof(GeolocationService_QueryNextPosition_Params_Data)");
        class GeolocationService_QueryNextPosition_ResponseParams_Data {
        public:
            static GeolocationService_QueryNextPosition_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GeolocationService_QueryNextPosition_ResponseParams_Data))) GeolocationService_QueryNextPosition_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::Geoposition_Data> geoposition;

        private:
            GeolocationService_QueryNextPosition_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GeolocationService_QueryNextPosition_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(GeolocationService_QueryNextPosition_ResponseParams_Data) == 16,
            "Bad sizeof(GeolocationService_QueryNextPosition_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_GEOLOCATION_PUBLIC_INTERFACES_GEOLOCATION_MOJOM_SHARED_INTERNAL_H_