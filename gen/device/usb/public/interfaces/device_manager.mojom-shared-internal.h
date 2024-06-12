// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MANAGER_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MANAGER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "device/usb/public/interfaces/device.mojom-shared-internal.h"
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
namespace usb {
    namespace internal {
        class DeviceFilter_Data;
        class EnumerationOptions_Data;

#pragma pack(push, 1)
        class DeviceFilter_Data {
        public:
            static DeviceFilter_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceFilter_Data))) DeviceFilter_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t has_vendor_id : 1;
            uint8_t has_product_id : 1;
            uint8_t has_class_code : 1;
            uint8_t has_subclass_code : 1;
            uint8_t has_protocol_code : 1;
            uint8_t class_code;
            uint16_t vendor_id;
            uint16_t product_id;
            uint8_t subclass_code;
            uint8_t protocol_code;
            mojo::internal::Pointer<mojo::internal::String_Data> serial_number;

        private:
            DeviceFilter_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceFilter_Data() = delete;
        };
        static_assert(sizeof(DeviceFilter_Data) == 24,
            "Bad sizeof(DeviceFilter_Data)");
        class EnumerationOptions_Data {
        public:
            static EnumerationOptions_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EnumerationOptions_Data))) EnumerationOptions_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::DeviceFilter_Data>>> filters;

        private:
            EnumerationOptions_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EnumerationOptions_Data() = delete;
        };
        static_assert(sizeof(EnumerationOptions_Data) == 16,
            "Bad sizeof(EnumerationOptions_Data)");
        constexpr uint32_t kDeviceManager_GetDevices_Name = 0;
        class DeviceManager_GetDevices_Params_Data {
        public:
            static DeviceManager_GetDevices_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceManager_GetDevices_Params_Data))) DeviceManager_GetDevices_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::EnumerationOptions_Data> options;

        private:
            DeviceManager_GetDevices_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceManager_GetDevices_Params_Data() = delete;
        };
        static_assert(sizeof(DeviceManager_GetDevices_Params_Data) == 16,
            "Bad sizeof(DeviceManager_GetDevices_Params_Data)");
        class DeviceManager_GetDevices_ResponseParams_Data {
        public:
            static DeviceManager_GetDevices_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceManager_GetDevices_ResponseParams_Data))) DeviceManager_GetDevices_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::device::usb::internal::DeviceInfo_Data>>> results;

        private:
            DeviceManager_GetDevices_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceManager_GetDevices_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(DeviceManager_GetDevices_ResponseParams_Data) == 16,
            "Bad sizeof(DeviceManager_GetDevices_ResponseParams_Data)");
        constexpr uint32_t kDeviceManager_GetDevice_Name = 1;
        class DeviceManager_GetDevice_Params_Data {
        public:
            static DeviceManager_GetDevice_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceManager_GetDevice_Params_Data))) DeviceManager_GetDevice_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> guid;
            mojo::internal::Handle_Data device_request;
            uint8_t padfinal_[4];

        private:
            DeviceManager_GetDevice_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceManager_GetDevice_Params_Data() = delete;
        };
        static_assert(sizeof(DeviceManager_GetDevice_Params_Data) == 24,
            "Bad sizeof(DeviceManager_GetDevice_Params_Data)");
        constexpr uint32_t kDeviceManager_SetClient_Name = 2;
        class DeviceManager_SetClient_Params_Data {
        public:
            static DeviceManager_SetClient_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceManager_SetClient_Params_Data))) DeviceManager_SetClient_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data client;

        private:
            DeviceManager_SetClient_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceManager_SetClient_Params_Data() = delete;
        };
        static_assert(sizeof(DeviceManager_SetClient_Params_Data) == 16,
            "Bad sizeof(DeviceManager_SetClient_Params_Data)");
        constexpr uint32_t kDeviceManagerClient_OnDeviceAdded_Name = 0;
        class DeviceManagerClient_OnDeviceAdded_Params_Data {
        public:
            static DeviceManagerClient_OnDeviceAdded_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceManagerClient_OnDeviceAdded_Params_Data))) DeviceManagerClient_OnDeviceAdded_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::device::usb::internal::DeviceInfo_Data> device_info;

        private:
            DeviceManagerClient_OnDeviceAdded_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceManagerClient_OnDeviceAdded_Params_Data() = delete;
        };
        static_assert(sizeof(DeviceManagerClient_OnDeviceAdded_Params_Data) == 16,
            "Bad sizeof(DeviceManagerClient_OnDeviceAdded_Params_Data)");
        constexpr uint32_t kDeviceManagerClient_OnDeviceRemoved_Name = 1;
        class DeviceManagerClient_OnDeviceRemoved_Params_Data {
        public:
            static DeviceManagerClient_OnDeviceRemoved_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceManagerClient_OnDeviceRemoved_Params_Data))) DeviceManagerClient_OnDeviceRemoved_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::device::usb::internal::DeviceInfo_Data> device_info;

        private:
            DeviceManagerClient_OnDeviceRemoved_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceManagerClient_OnDeviceRemoved_Params_Data() = delete;
        };
        static_assert(sizeof(DeviceManagerClient_OnDeviceRemoved_Params_Data) == 16,
            "Bad sizeof(DeviceManagerClient_OnDeviceRemoved_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace usb
} // namespace device

#endif // DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MANAGER_MOJOM_SHARED_INTERNAL_H_