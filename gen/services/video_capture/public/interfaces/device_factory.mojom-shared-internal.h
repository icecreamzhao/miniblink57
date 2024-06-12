// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_FACTORY_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_FACTORY_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/capture/mojo/video_capture_types.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/video_capture/public/interfaces/capture_settings.mojom-shared-internal.h"
#include "services/video_capture/public/interfaces/device.mojom-shared-internal.h"
#include "services/video_capture/public/interfaces/device_descriptor.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace video_capture {
namespace mojom {
    namespace internal {

        struct DeviceAccessResultCode_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
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
        constexpr uint32_t kDeviceFactory_EnumerateDeviceDescriptors_Name = 0;
        class DeviceFactory_EnumerateDeviceDescriptors_Params_Data {
        public:
            static DeviceFactory_EnumerateDeviceDescriptors_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceFactory_EnumerateDeviceDescriptors_Params_Data))) DeviceFactory_EnumerateDeviceDescriptors_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DeviceFactory_EnumerateDeviceDescriptors_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceFactory_EnumerateDeviceDescriptors_Params_Data() = delete;
        };
        static_assert(sizeof(DeviceFactory_EnumerateDeviceDescriptors_Params_Data) == 8,
            "Bad sizeof(DeviceFactory_EnumerateDeviceDescriptors_Params_Data)");
        class DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data {
        public:
            static DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data))) DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::video_capture::mojom::internal::DeviceDescriptor_Data>>> descriptors;

        private:
            DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data) == 16,
            "Bad sizeof(DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data)");
        constexpr uint32_t kDeviceFactory_GetSupportedFormats_Name = 1;
        class DeviceFactory_GetSupportedFormats_Params_Data {
        public:
            static DeviceFactory_GetSupportedFormats_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceFactory_GetSupportedFormats_Params_Data))) DeviceFactory_GetSupportedFormats_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> device_id;

        private:
            DeviceFactory_GetSupportedFormats_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceFactory_GetSupportedFormats_Params_Data() = delete;
        };
        static_assert(sizeof(DeviceFactory_GetSupportedFormats_Params_Data) == 16,
            "Bad sizeof(DeviceFactory_GetSupportedFormats_Params_Data)");
        class DeviceFactory_GetSupportedFormats_ResponseParams_Data {
        public:
            static DeviceFactory_GetSupportedFormats_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceFactory_GetSupportedFormats_ResponseParams_Data))) DeviceFactory_GetSupportedFormats_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::video_capture::mojom::internal::I420CaptureFormat_Data>>> supported_formats;

        private:
            DeviceFactory_GetSupportedFormats_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceFactory_GetSupportedFormats_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(DeviceFactory_GetSupportedFormats_ResponseParams_Data) == 16,
            "Bad sizeof(DeviceFactory_GetSupportedFormats_ResponseParams_Data)");
        constexpr uint32_t kDeviceFactory_CreateDevice_Name = 2;
        class DeviceFactory_CreateDevice_Params_Data {
        public:
            static DeviceFactory_CreateDevice_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceFactory_CreateDevice_Params_Data))) DeviceFactory_CreateDevice_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> device_id;
            mojo::internal::Handle_Data device_request;
            uint8_t padfinal_[4];

        private:
            DeviceFactory_CreateDevice_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceFactory_CreateDevice_Params_Data() = delete;
        };
        static_assert(sizeof(DeviceFactory_CreateDevice_Params_Data) == 24,
            "Bad sizeof(DeviceFactory_CreateDevice_Params_Data)");
        class DeviceFactory_CreateDevice_ResponseParams_Data {
        public:
            static DeviceFactory_CreateDevice_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceFactory_CreateDevice_ResponseParams_Data))) DeviceFactory_CreateDevice_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result_code;
            uint8_t padfinal_[4];

        private:
            DeviceFactory_CreateDevice_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceFactory_CreateDevice_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(DeviceFactory_CreateDevice_ResponseParams_Data) == 16,
            "Bad sizeof(DeviceFactory_CreateDevice_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_FACTORY_MOJOM_SHARED_INTERNAL_H_