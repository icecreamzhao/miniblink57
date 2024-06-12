// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BLUETOOTH_WEB_BLUETOOTH_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BLUETOOTH_WEB_BLUETOOTH_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "device/bluetooth/public/interfaces/uuid.mojom-shared-internal.h"
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
namespace blink {
namespace mojom {
    namespace internal {
        class WebBluetoothScanFilter_Data;
        class WebBluetoothRequestDeviceOptions_Data;
        class WebBluetoothDeviceId_Data;
        class WebBluetoothDevice_Data;
        class WebBluetoothRemoteGATTService_Data;
        class WebBluetoothRemoteGATTCharacteristic_Data;
        class WebBluetoothRemoteGATTDescriptor_Data;

        struct WebBluetoothResult_Data {
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
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                case 50:
                case 51:
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

        struct WebBluetoothGATTQueryQuantity_Data {
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
        class WebBluetoothScanFilter_Data {
        public:
            static WebBluetoothScanFilter_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothScanFilter_Data))) WebBluetoothScanFilter_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::bluetooth::mojom::internal::UUID_Data>>> services;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::String_Data> name_prefix;

        private:
            WebBluetoothScanFilter_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothScanFilter_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothScanFilter_Data) == 32,
            "Bad sizeof(WebBluetoothScanFilter_Data)");
        class WebBluetoothRequestDeviceOptions_Data {
        public:
            static WebBluetoothRequestDeviceOptions_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothRequestDeviceOptions_Data))) WebBluetoothRequestDeviceOptions_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::WebBluetoothScanFilter_Data>>> filters;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::bluetooth::mojom::internal::UUID_Data>>> optional_services;
            uint8_t accept_all_devices : 1;
            uint8_t padfinal_[7];

        private:
            WebBluetoothRequestDeviceOptions_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothRequestDeviceOptions_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothRequestDeviceOptions_Data) == 32,
            "Bad sizeof(WebBluetoothRequestDeviceOptions_Data)");
        class WebBluetoothDeviceId_Data {
        public:
            static WebBluetoothDeviceId_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothDeviceId_Data))) WebBluetoothDeviceId_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> device_id;

        private:
            WebBluetoothDeviceId_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothDeviceId_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothDeviceId_Data) == 16,
            "Bad sizeof(WebBluetoothDeviceId_Data)");
        class WebBluetoothDevice_Data {
        public:
            static WebBluetoothDevice_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothDevice_Data))) WebBluetoothDevice_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::WebBluetoothDeviceId_Data> id;
            mojo::internal::Pointer<mojo::internal::String_Data> name;

        private:
            WebBluetoothDevice_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothDevice_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothDevice_Data) == 24,
            "Bad sizeof(WebBluetoothDevice_Data)");
        class WebBluetoothRemoteGATTService_Data {
        public:
            static WebBluetoothRemoteGATTService_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothRemoteGATTService_Data))) WebBluetoothRemoteGATTService_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> instance_id;
            mojo::internal::Pointer<::bluetooth::mojom::internal::UUID_Data> uuid;

        private:
            WebBluetoothRemoteGATTService_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothRemoteGATTService_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothRemoteGATTService_Data) == 24,
            "Bad sizeof(WebBluetoothRemoteGATTService_Data)");
        class WebBluetoothRemoteGATTCharacteristic_Data {
        public:
            static WebBluetoothRemoteGATTCharacteristic_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothRemoteGATTCharacteristic_Data))) WebBluetoothRemoteGATTCharacteristic_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> instance_id;
            mojo::internal::Pointer<::bluetooth::mojom::internal::UUID_Data> uuid;
            uint32_t properties;
            uint8_t padfinal_[4];

        private:
            WebBluetoothRemoteGATTCharacteristic_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothRemoteGATTCharacteristic_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothRemoteGATTCharacteristic_Data) == 32,
            "Bad sizeof(WebBluetoothRemoteGATTCharacteristic_Data)");
        class WebBluetoothRemoteGATTDescriptor_Data {
        public:
            static WebBluetoothRemoteGATTDescriptor_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothRemoteGATTDescriptor_Data))) WebBluetoothRemoteGATTDescriptor_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> instance_id;
            mojo::internal::Pointer<::bluetooth::mojom::internal::UUID_Data> uuid;

        private:
            WebBluetoothRemoteGATTDescriptor_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothRemoteGATTDescriptor_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothRemoteGATTDescriptor_Data) == 24,
            "Bad sizeof(WebBluetoothRemoteGATTDescriptor_Data)");
        constexpr uint32_t kWebBluetoothService_SetClient_Name = 0;
        class WebBluetoothService_SetClient_Params_Data {
        public:
            static WebBluetoothService_SetClient_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_SetClient_Params_Data))) WebBluetoothService_SetClient_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterface_Data client;

        private:
            WebBluetoothService_SetClient_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_SetClient_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_SetClient_Params_Data) == 16,
            "Bad sizeof(WebBluetoothService_SetClient_Params_Data)");
        constexpr uint32_t kWebBluetoothService_RequestDevice_Name = 1;
        class WebBluetoothService_RequestDevice_Params_Data {
        public:
            static WebBluetoothService_RequestDevice_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RequestDevice_Params_Data))) WebBluetoothService_RequestDevice_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::WebBluetoothRequestDeviceOptions_Data> options;

        private:
            WebBluetoothService_RequestDevice_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RequestDevice_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RequestDevice_Params_Data) == 16,
            "Bad sizeof(WebBluetoothService_RequestDevice_Params_Data)");
        class WebBluetoothService_RequestDevice_ResponseParams_Data {
        public:
            static WebBluetoothService_RequestDevice_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RequestDevice_ResponseParams_Data))) WebBluetoothService_RequestDevice_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t pad0_[4];
            mojo::internal::Pointer<internal::WebBluetoothDevice_Data> device;

        private:
            WebBluetoothService_RequestDevice_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RequestDevice_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RequestDevice_ResponseParams_Data) == 24,
            "Bad sizeof(WebBluetoothService_RequestDevice_ResponseParams_Data)");
        constexpr uint32_t kWebBluetoothService_RemoteServerConnect_Name = 2;
        class WebBluetoothService_RemoteServerConnect_Params_Data {
        public:
            static WebBluetoothService_RemoteServerConnect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteServerConnect_Params_Data))) WebBluetoothService_RemoteServerConnect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::WebBluetoothDeviceId_Data> device_id;

        private:
            WebBluetoothService_RemoteServerConnect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteServerConnect_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteServerConnect_Params_Data) == 16,
            "Bad sizeof(WebBluetoothService_RemoteServerConnect_Params_Data)");
        class WebBluetoothService_RemoteServerConnect_ResponseParams_Data {
        public:
            static WebBluetoothService_RemoteServerConnect_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteServerConnect_ResponseParams_Data))) WebBluetoothService_RemoteServerConnect_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t padfinal_[4];

        private:
            WebBluetoothService_RemoteServerConnect_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteServerConnect_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteServerConnect_ResponseParams_Data) == 16,
            "Bad sizeof(WebBluetoothService_RemoteServerConnect_ResponseParams_Data)");
        constexpr uint32_t kWebBluetoothService_RemoteServerDisconnect_Name = 3;
        class WebBluetoothService_RemoteServerDisconnect_Params_Data {
        public:
            static WebBluetoothService_RemoteServerDisconnect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteServerDisconnect_Params_Data))) WebBluetoothService_RemoteServerDisconnect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::WebBluetoothDeviceId_Data> device_id;

        private:
            WebBluetoothService_RemoteServerDisconnect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteServerDisconnect_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteServerDisconnect_Params_Data) == 16,
            "Bad sizeof(WebBluetoothService_RemoteServerDisconnect_Params_Data)");
        constexpr uint32_t kWebBluetoothService_RemoteServerGetPrimaryServices_Name = 4;
        class WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data {
        public:
            static WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data))) WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::WebBluetoothDeviceId_Data> device_id;
            int32_t quantity;
            uint8_t pad1_[4];
            mojo::internal::Pointer<::bluetooth::mojom::internal::UUID_Data> services_uuid;

        private:
            WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data) == 32,
            "Bad sizeof(WebBluetoothService_RemoteServerGetPrimaryServices_Params_Data)");
        class WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data {
        public:
            static WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data))) WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::WebBluetoothRemoteGATTService_Data>>> services;

        private:
            WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data) == 24,
            "Bad sizeof(WebBluetoothService_RemoteServerGetPrimaryServices_ResponseParams_Data)");
        constexpr uint32_t kWebBluetoothService_RemoteServiceGetCharacteristics_Name = 5;
        class WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data {
        public:
            static WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data))) WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> service_instance_id;
            int32_t quantity;
            uint8_t pad1_[4];
            mojo::internal::Pointer<::bluetooth::mojom::internal::UUID_Data> characteristics_uuid;

        private:
            WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data) == 32,
            "Bad sizeof(WebBluetoothService_RemoteServiceGetCharacteristics_Params_Data)");
        class WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data {
        public:
            static WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data))) WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::WebBluetoothRemoteGATTCharacteristic_Data>>> characteristics;

        private:
            WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data) == 24,
            "Bad sizeof(WebBluetoothService_RemoteServiceGetCharacteristics_ResponseParams_Data)");
        constexpr uint32_t kWebBluetoothService_RemoteCharacteristicReadValue_Name = 6;
        class WebBluetoothService_RemoteCharacteristicReadValue_Params_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicReadValue_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicReadValue_Params_Data))) WebBluetoothService_RemoteCharacteristicReadValue_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> characteristic_instance_id;

        private:
            WebBluetoothService_RemoteCharacteristicReadValue_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicReadValue_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicReadValue_Params_Data) == 16,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicReadValue_Params_Data)");
        class WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data))) WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data) == 24,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicReadValue_ResponseParams_Data)");
        constexpr uint32_t kWebBluetoothService_RemoteCharacteristicWriteValue_Name = 7;
        class WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data))) WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> characteristic_instance_id;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data) == 24,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicWriteValue_Params_Data)");
        class WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data))) WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t padfinal_[4];

        private:
            WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data) == 16,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicWriteValue_ResponseParams_Data)");
        constexpr uint32_t kWebBluetoothService_RemoteCharacteristicStartNotifications_Name = 8;
        class WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data))) WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> characteristic_instance_id;

        private:
            WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data) == 16,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicStartNotifications_Params_Data)");
        class WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data))) WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t padfinal_[4];

        private:
            WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data) == 16,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicStartNotifications_ResponseParams_Data)");
        constexpr uint32_t kWebBluetoothService_RemoteCharacteristicStopNotifications_Name = 9;
        class WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data))) WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> characteristic_instance_id;

        private:
            WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data) == 16,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicStopNotifications_Params_Data)");
        class WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data))) WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data) == 8,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicStopNotifications_ResponseParams_Data)");
        constexpr uint32_t kWebBluetoothService_RemoteCharacteristicGetDescriptors_Name = 10;
        class WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data))) WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> characteristics_instance_id;
            int32_t quantity;
            uint8_t pad1_[4];
            mojo::internal::Pointer<::bluetooth::mojom::internal::UUID_Data> descriptor_uuid;

        private:
            WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data) == 32,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicGetDescriptors_Params_Data)");
        class WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data {
        public:
            static WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data))) WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::WebBluetoothRemoteGATTDescriptor_Data>>> descriptors;

        private:
            WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data) == 24,
            "Bad sizeof(WebBluetoothService_RemoteCharacteristicGetDescriptors_ResponseParams_Data)");
        constexpr uint32_t kWebBluetoothServiceClient_RemoteCharacteristicValueChanged_Name = 0;
        class WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data {
        public:
            static WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data))) WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> characteristic_instance_id;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data) == 24,
            "Bad sizeof(WebBluetoothServiceClient_RemoteCharacteristicValueChanged_Params_Data)");
        constexpr uint32_t kWebBluetoothServiceClient_GattServerDisconnected_Name = 1;
        class WebBluetoothServiceClient_GattServerDisconnected_Params_Data {
        public:
            static WebBluetoothServiceClient_GattServerDisconnected_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebBluetoothServiceClient_GattServerDisconnected_Params_Data))) WebBluetoothServiceClient_GattServerDisconnected_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::WebBluetoothDeviceId_Data> device_id;

        private:
            WebBluetoothServiceClient_GattServerDisconnected_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebBluetoothServiceClient_GattServerDisconnected_Params_Data() = delete;
        };
        static_assert(sizeof(WebBluetoothServiceClient_GattServerDisconnected_Params_Data) == 16,
            "Bad sizeof(WebBluetoothServiceClient_GattServerDisconnected_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BLUETOOTH_WEB_BLUETOOTH_MOJOM_SHARED_INTERNAL_H_