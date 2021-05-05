// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_USB_PUBLIC_INTERFACES_CHOOSER_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_USB_PUBLIC_INTERFACES_CHOOSER_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "device/usb/public/interfaces/device.mojom-shared-internal.h"
#include "device/usb/public/interfaces/device_manager.mojom-shared-internal.h"
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

#pragma pack(push, 1)
        constexpr uint32_t kChooserService_GetPermission_Name = 0;
        class ChooserService_GetPermission_Params_Data {
        public:
            static ChooserService_GetPermission_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ChooserService_GetPermission_Params_Data))) ChooserService_GetPermission_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::device::usb::internal::DeviceFilter_Data>>> device_filters;

        private:
            ChooserService_GetPermission_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ChooserService_GetPermission_Params_Data() = delete;
        };
        static_assert(sizeof(ChooserService_GetPermission_Params_Data) == 16,
            "Bad sizeof(ChooserService_GetPermission_Params_Data)");
        class ChooserService_GetPermission_ResponseParams_Data {
        public:
            static ChooserService_GetPermission_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ChooserService_GetPermission_ResponseParams_Data))) ChooserService_GetPermission_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::device::usb::internal::DeviceInfo_Data> result;

        private:
            ChooserService_GetPermission_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ChooserService_GetPermission_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ChooserService_GetPermission_ResponseParams_Data) == 16,
            "Bad sizeof(ChooserService_GetPermission_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace usb
} // namespace device

#endif // DEVICE_USB_PUBLIC_INTERFACES_CHOOSER_SERVICE_MOJOM_SHARED_INTERNAL_H_