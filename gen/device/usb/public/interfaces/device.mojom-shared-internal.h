// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_INTERNAL_H_

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
namespace usb {
    namespace internal {
        class EndpointInfo_Data;
        class AlternateInterfaceInfo_Data;
        class InterfaceInfo_Data;
        class ConfigurationInfo_Data;
        class DeviceInfo_Data;
        class ControlTransferParams_Data;
        class IsochronousPacket_Data;

        struct OpenDeviceError_Data {
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

        struct TransferDirection_Data {
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

        struct ControlTransferType_Data {
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

        struct ControlTransferRecipient_Data {
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

        struct EndpointType_Data {
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

        struct TransferStatus_Data {
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
        class EndpointInfo_Data {
        public:
            static EndpointInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EndpointInfo_Data))) EndpointInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t endpoint_number;
            uint8_t pad0_[3];
            int32_t direction;
            int32_t type;
            uint32_t packet_size;

        private:
            EndpointInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EndpointInfo_Data() = delete;
        };
        static_assert(sizeof(EndpointInfo_Data) == 24,
            "Bad sizeof(EndpointInfo_Data)");
        class AlternateInterfaceInfo_Data {
        public:
            static AlternateInterfaceInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AlternateInterfaceInfo_Data))) AlternateInterfaceInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t alternate_setting;
            uint8_t class_code;
            uint8_t subclass_code;
            uint8_t protocol_code;
            uint8_t pad3_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> interface_name;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::EndpointInfo_Data>>> endpoints;

        private:
            AlternateInterfaceInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AlternateInterfaceInfo_Data() = delete;
        };
        static_assert(sizeof(AlternateInterfaceInfo_Data) == 32,
            "Bad sizeof(AlternateInterfaceInfo_Data)");
        class InterfaceInfo_Data {
        public:
            static InterfaceInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InterfaceInfo_Data))) InterfaceInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t interface_number;
            uint8_t pad0_[7];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::AlternateInterfaceInfo_Data>>> alternates;

        private:
            InterfaceInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InterfaceInfo_Data() = delete;
        };
        static_assert(sizeof(InterfaceInfo_Data) == 24,
            "Bad sizeof(InterfaceInfo_Data)");
        class ConfigurationInfo_Data {
        public:
            static ConfigurationInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ConfigurationInfo_Data))) ConfigurationInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t configuration_value;
            uint8_t pad0_[7];
            mojo::internal::Pointer<mojo::internal::String_Data> configuration_name;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::InterfaceInfo_Data>>> interfaces;

        private:
            ConfigurationInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ConfigurationInfo_Data() = delete;
        };
        static_assert(sizeof(ConfigurationInfo_Data) == 32,
            "Bad sizeof(ConfigurationInfo_Data)");
        class DeviceInfo_Data {
        public:
            static DeviceInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DeviceInfo_Data))) DeviceInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> guid;
            uint8_t usb_version_major;
            uint8_t usb_version_minor;
            uint8_t usb_version_subminor;
            uint8_t class_code;
            uint8_t subclass_code;
            uint8_t protocol_code;
            uint16_t vendor_id;
            uint16_t product_id;
            uint8_t device_version_major;
            uint8_t device_version_minor;
            uint8_t device_version_subminor;
            uint8_t active_configuration;
            uint8_t pad12_[2];
            mojo::internal::Pointer<mojo::internal::String_Data> manufacturer_name;
            mojo::internal::Pointer<mojo::internal::String_Data> product_name;
            mojo::internal::Pointer<mojo::internal::String_Data> serial_number;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::ConfigurationInfo_Data>>> configurations;

        private:
            DeviceInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DeviceInfo_Data() = delete;
        };
        static_assert(sizeof(DeviceInfo_Data) == 64,
            "Bad sizeof(DeviceInfo_Data)");
        class ControlTransferParams_Data {
        public:
            static ControlTransferParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ControlTransferParams_Data))) ControlTransferParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            int32_t recipient;
            uint8_t request;
            uint8_t pad2_[1];
            uint16_t value;
            uint16_t index;
            uint8_t padfinal_[2];

        private:
            ControlTransferParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ControlTransferParams_Data() = delete;
        };
        static_assert(sizeof(ControlTransferParams_Data) == 24,
            "Bad sizeof(ControlTransferParams_Data)");
        class IsochronousPacket_Data {
        public:
            static IsochronousPacket_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(IsochronousPacket_Data))) IsochronousPacket_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t length;
            uint32_t transferred_length;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            IsochronousPacket_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~IsochronousPacket_Data() = delete;
        };
        static_assert(sizeof(IsochronousPacket_Data) == 24,
            "Bad sizeof(IsochronousPacket_Data)");
        constexpr uint32_t kDevice_GetDeviceInfo_Name = 0;
        class Device_GetDeviceInfo_Params_Data {
        public:
            static Device_GetDeviceInfo_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_GetDeviceInfo_Params_Data))) Device_GetDeviceInfo_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Device_GetDeviceInfo_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_GetDeviceInfo_Params_Data() = delete;
        };
        static_assert(sizeof(Device_GetDeviceInfo_Params_Data) == 8,
            "Bad sizeof(Device_GetDeviceInfo_Params_Data)");
        class Device_GetDeviceInfo_ResponseParams_Data {
        public:
            static Device_GetDeviceInfo_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_GetDeviceInfo_ResponseParams_Data))) Device_GetDeviceInfo_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::DeviceInfo_Data> info;

        private:
            Device_GetDeviceInfo_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_GetDeviceInfo_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_GetDeviceInfo_ResponseParams_Data) == 16,
            "Bad sizeof(Device_GetDeviceInfo_ResponseParams_Data)");
        constexpr uint32_t kDevice_Open_Name = 1;
        class Device_Open_Params_Data {
        public:
            static Device_Open_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_Open_Params_Data))) Device_Open_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Device_Open_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_Open_Params_Data() = delete;
        };
        static_assert(sizeof(Device_Open_Params_Data) == 8,
            "Bad sizeof(Device_Open_Params_Data)");
        class Device_Open_ResponseParams_Data {
        public:
            static Device_Open_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_Open_ResponseParams_Data))) Device_Open_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            Device_Open_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_Open_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_Open_ResponseParams_Data) == 16,
            "Bad sizeof(Device_Open_ResponseParams_Data)");
        constexpr uint32_t kDevice_Close_Name = 2;
        class Device_Close_Params_Data {
        public:
            static Device_Close_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_Close_Params_Data))) Device_Close_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Device_Close_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_Close_Params_Data() = delete;
        };
        static_assert(sizeof(Device_Close_Params_Data) == 8,
            "Bad sizeof(Device_Close_Params_Data)");
        class Device_Close_ResponseParams_Data {
        public:
            static Device_Close_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_Close_ResponseParams_Data))) Device_Close_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Device_Close_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_Close_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_Close_ResponseParams_Data) == 8,
            "Bad sizeof(Device_Close_ResponseParams_Data)");
        constexpr uint32_t kDevice_SetConfiguration_Name = 3;
        class Device_SetConfiguration_Params_Data {
        public:
            static Device_SetConfiguration_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_SetConfiguration_Params_Data))) Device_SetConfiguration_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t value;
            uint8_t padfinal_[7];

        private:
            Device_SetConfiguration_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_SetConfiguration_Params_Data() = delete;
        };
        static_assert(sizeof(Device_SetConfiguration_Params_Data) == 16,
            "Bad sizeof(Device_SetConfiguration_Params_Data)");
        class Device_SetConfiguration_ResponseParams_Data {
        public:
            static Device_SetConfiguration_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_SetConfiguration_ResponseParams_Data))) Device_SetConfiguration_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Device_SetConfiguration_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_SetConfiguration_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_SetConfiguration_ResponseParams_Data) == 16,
            "Bad sizeof(Device_SetConfiguration_ResponseParams_Data)");
        constexpr uint32_t kDevice_ClaimInterface_Name = 4;
        class Device_ClaimInterface_Params_Data {
        public:
            static Device_ClaimInterface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ClaimInterface_Params_Data))) Device_ClaimInterface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t interface_number;
            uint8_t padfinal_[7];

        private:
            Device_ClaimInterface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ClaimInterface_Params_Data() = delete;
        };
        static_assert(sizeof(Device_ClaimInterface_Params_Data) == 16,
            "Bad sizeof(Device_ClaimInterface_Params_Data)");
        class Device_ClaimInterface_ResponseParams_Data {
        public:
            static Device_ClaimInterface_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ClaimInterface_ResponseParams_Data))) Device_ClaimInterface_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Device_ClaimInterface_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ClaimInterface_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_ClaimInterface_ResponseParams_Data) == 16,
            "Bad sizeof(Device_ClaimInterface_ResponseParams_Data)");
        constexpr uint32_t kDevice_ReleaseInterface_Name = 5;
        class Device_ReleaseInterface_Params_Data {
        public:
            static Device_ReleaseInterface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ReleaseInterface_Params_Data))) Device_ReleaseInterface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t interface_number;
            uint8_t padfinal_[7];

        private:
            Device_ReleaseInterface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ReleaseInterface_Params_Data() = delete;
        };
        static_assert(sizeof(Device_ReleaseInterface_Params_Data) == 16,
            "Bad sizeof(Device_ReleaseInterface_Params_Data)");
        class Device_ReleaseInterface_ResponseParams_Data {
        public:
            static Device_ReleaseInterface_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ReleaseInterface_ResponseParams_Data))) Device_ReleaseInterface_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Device_ReleaseInterface_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ReleaseInterface_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_ReleaseInterface_ResponseParams_Data) == 16,
            "Bad sizeof(Device_ReleaseInterface_ResponseParams_Data)");
        constexpr uint32_t kDevice_SetInterfaceAlternateSetting_Name = 6;
        class Device_SetInterfaceAlternateSetting_Params_Data {
        public:
            static Device_SetInterfaceAlternateSetting_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_SetInterfaceAlternateSetting_Params_Data))) Device_SetInterfaceAlternateSetting_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t interface_number;
            uint8_t alternate_setting;
            uint8_t padfinal_[6];

        private:
            Device_SetInterfaceAlternateSetting_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_SetInterfaceAlternateSetting_Params_Data() = delete;
        };
        static_assert(sizeof(Device_SetInterfaceAlternateSetting_Params_Data) == 16,
            "Bad sizeof(Device_SetInterfaceAlternateSetting_Params_Data)");
        class Device_SetInterfaceAlternateSetting_ResponseParams_Data {
        public:
            static Device_SetInterfaceAlternateSetting_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_SetInterfaceAlternateSetting_ResponseParams_Data))) Device_SetInterfaceAlternateSetting_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Device_SetInterfaceAlternateSetting_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_SetInterfaceAlternateSetting_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_SetInterfaceAlternateSetting_ResponseParams_Data) == 16,
            "Bad sizeof(Device_SetInterfaceAlternateSetting_ResponseParams_Data)");
        constexpr uint32_t kDevice_Reset_Name = 7;
        class Device_Reset_Params_Data {
        public:
            static Device_Reset_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_Reset_Params_Data))) Device_Reset_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Device_Reset_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_Reset_Params_Data() = delete;
        };
        static_assert(sizeof(Device_Reset_Params_Data) == 8,
            "Bad sizeof(Device_Reset_Params_Data)");
        class Device_Reset_ResponseParams_Data {
        public:
            static Device_Reset_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_Reset_ResponseParams_Data))) Device_Reset_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Device_Reset_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_Reset_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_Reset_ResponseParams_Data) == 16,
            "Bad sizeof(Device_Reset_ResponseParams_Data)");
        constexpr uint32_t kDevice_ClearHalt_Name = 8;
        class Device_ClearHalt_Params_Data {
        public:
            static Device_ClearHalt_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ClearHalt_Params_Data))) Device_ClearHalt_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t endpoint;
            uint8_t padfinal_[7];

        private:
            Device_ClearHalt_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ClearHalt_Params_Data() = delete;
        };
        static_assert(sizeof(Device_ClearHalt_Params_Data) == 16,
            "Bad sizeof(Device_ClearHalt_Params_Data)");
        class Device_ClearHalt_ResponseParams_Data {
        public:
            static Device_ClearHalt_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ClearHalt_ResponseParams_Data))) Device_ClearHalt_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            Device_ClearHalt_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ClearHalt_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_ClearHalt_ResponseParams_Data) == 16,
            "Bad sizeof(Device_ClearHalt_ResponseParams_Data)");
        constexpr uint32_t kDevice_ControlTransferIn_Name = 9;
        class Device_ControlTransferIn_Params_Data {
        public:
            static Device_ControlTransferIn_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ControlTransferIn_Params_Data))) Device_ControlTransferIn_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ControlTransferParams_Data> params;
            uint32_t length;
            uint32_t timeout;

        private:
            Device_ControlTransferIn_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ControlTransferIn_Params_Data() = delete;
        };
        static_assert(sizeof(Device_ControlTransferIn_Params_Data) == 24,
            "Bad sizeof(Device_ControlTransferIn_Params_Data)");
        class Device_ControlTransferIn_ResponseParams_Data {
        public:
            static Device_ControlTransferIn_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ControlTransferIn_ResponseParams_Data))) Device_ControlTransferIn_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            Device_ControlTransferIn_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ControlTransferIn_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_ControlTransferIn_ResponseParams_Data) == 24,
            "Bad sizeof(Device_ControlTransferIn_ResponseParams_Data)");
        constexpr uint32_t kDevice_ControlTransferOut_Name = 10;
        class Device_ControlTransferOut_Params_Data {
        public:
            static Device_ControlTransferOut_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ControlTransferOut_Params_Data))) Device_ControlTransferOut_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ControlTransferParams_Data> params;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;
            uint32_t timeout;
            uint8_t padfinal_[4];

        private:
            Device_ControlTransferOut_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ControlTransferOut_Params_Data() = delete;
        };
        static_assert(sizeof(Device_ControlTransferOut_Params_Data) == 32,
            "Bad sizeof(Device_ControlTransferOut_Params_Data)");
        class Device_ControlTransferOut_ResponseParams_Data {
        public:
            static Device_ControlTransferOut_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_ControlTransferOut_ResponseParams_Data))) Device_ControlTransferOut_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            Device_ControlTransferOut_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_ControlTransferOut_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_ControlTransferOut_ResponseParams_Data) == 16,
            "Bad sizeof(Device_ControlTransferOut_ResponseParams_Data)");
        constexpr uint32_t kDevice_GenericTransferIn_Name = 11;
        class Device_GenericTransferIn_Params_Data {
        public:
            static Device_GenericTransferIn_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_GenericTransferIn_Params_Data))) Device_GenericTransferIn_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t endpoint_number;
            uint8_t pad0_[3];
            uint32_t length;
            uint32_t timeout;
            uint8_t padfinal_[4];

        private:
            Device_GenericTransferIn_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_GenericTransferIn_Params_Data() = delete;
        };
        static_assert(sizeof(Device_GenericTransferIn_Params_Data) == 24,
            "Bad sizeof(Device_GenericTransferIn_Params_Data)");
        class Device_GenericTransferIn_ResponseParams_Data {
        public:
            static Device_GenericTransferIn_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_GenericTransferIn_ResponseParams_Data))) Device_GenericTransferIn_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            Device_GenericTransferIn_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_GenericTransferIn_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_GenericTransferIn_ResponseParams_Data) == 24,
            "Bad sizeof(Device_GenericTransferIn_ResponseParams_Data)");
        constexpr uint32_t kDevice_GenericTransferOut_Name = 12;
        class Device_GenericTransferOut_Params_Data {
        public:
            static Device_GenericTransferOut_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_GenericTransferOut_Params_Data))) Device_GenericTransferOut_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t endpoint_number;
            uint8_t pad0_[3];
            uint32_t timeout;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            Device_GenericTransferOut_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_GenericTransferOut_Params_Data() = delete;
        };
        static_assert(sizeof(Device_GenericTransferOut_Params_Data) == 24,
            "Bad sizeof(Device_GenericTransferOut_Params_Data)");
        class Device_GenericTransferOut_ResponseParams_Data {
        public:
            static Device_GenericTransferOut_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_GenericTransferOut_ResponseParams_Data))) Device_GenericTransferOut_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t padfinal_[4];

        private:
            Device_GenericTransferOut_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_GenericTransferOut_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_GenericTransferOut_ResponseParams_Data) == 16,
            "Bad sizeof(Device_GenericTransferOut_ResponseParams_Data)");
        constexpr uint32_t kDevice_IsochronousTransferIn_Name = 13;
        class Device_IsochronousTransferIn_Params_Data {
        public:
            static Device_IsochronousTransferIn_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_IsochronousTransferIn_Params_Data))) Device_IsochronousTransferIn_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t endpoint_number;
            uint8_t pad0_[3];
            uint32_t timeout;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint32_t>> packet_lengths;

        private:
            Device_IsochronousTransferIn_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_IsochronousTransferIn_Params_Data() = delete;
        };
        static_assert(sizeof(Device_IsochronousTransferIn_Params_Data) == 24,
            "Bad sizeof(Device_IsochronousTransferIn_Params_Data)");
        class Device_IsochronousTransferIn_ResponseParams_Data {
        public:
            static Device_IsochronousTransferIn_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_IsochronousTransferIn_ResponseParams_Data))) Device_IsochronousTransferIn_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::IsochronousPacket_Data>>> packets;

        private:
            Device_IsochronousTransferIn_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_IsochronousTransferIn_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_IsochronousTransferIn_ResponseParams_Data) == 24,
            "Bad sizeof(Device_IsochronousTransferIn_ResponseParams_Data)");
        constexpr uint32_t kDevice_IsochronousTransferOut_Name = 14;
        class Device_IsochronousTransferOut_Params_Data {
        public:
            static Device_IsochronousTransferOut_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_IsochronousTransferOut_Params_Data))) Device_IsochronousTransferOut_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t endpoint_number;
            uint8_t pad0_[3];
            uint32_t timeout;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint32_t>> packet_lengths;

        private:
            Device_IsochronousTransferOut_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_IsochronousTransferOut_Params_Data() = delete;
        };
        static_assert(sizeof(Device_IsochronousTransferOut_Params_Data) == 32,
            "Bad sizeof(Device_IsochronousTransferOut_Params_Data)");
        class Device_IsochronousTransferOut_ResponseParams_Data {
        public:
            static Device_IsochronousTransferOut_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Device_IsochronousTransferOut_ResponseParams_Data))) Device_IsochronousTransferOut_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::IsochronousPacket_Data>>> packets;

        private:
            Device_IsochronousTransferOut_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Device_IsochronousTransferOut_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Device_IsochronousTransferOut_ResponseParams_Data) == 16,
            "Bad sizeof(Device_IsochronousTransferOut_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace usb
} // namespace device

#endif // DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MOJOM_SHARED_INTERNAL_H_