// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_DESCRIPTOR_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_DESCRIPTOR_MOJOM_SHARED_INTERNAL_H_

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
namespace video_capture {
namespace mojom {
    namespace internal {
        class DeviceDescriptor_Data;

        struct VideoCaptureApi_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
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

        struct VideoCaptureTransportType_Data {
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
        class DeviceDescriptor_Data {
        public:
            static DeviceDescriptor_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceDescriptor_Data))) DeviceDescriptor_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> display_name;
            mojo::internal::Pointer<mojo::internal::String_Data> device_id;
            mojo::internal::Pointer<mojo::internal::String_Data> model_id;
            int32_t capture_api;
            int32_t transport_type;

        private:
            DeviceDescriptor_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceDescriptor_Data() = delete;
        };
        static_assert(sizeof(DeviceDescriptor_Data) == 40,
            "Bad sizeof(DeviceDescriptor_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_DESCRIPTOR_MOJOM_SHARED_INTERNAL_H_