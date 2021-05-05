// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/video_capture/public/interfaces/device_factory.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace video_capture {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kService_ConnectToDeviceFactory_Name = 0;
        class Service_ConnectToDeviceFactory_Params_Data {
        public:
            static Service_ConnectToDeviceFactory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Service_ConnectToDeviceFactory_Params_Data))) Service_ConnectToDeviceFactory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data request;
            uint8_t padfinal_[4];

        private:
            Service_ConnectToDeviceFactory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Service_ConnectToDeviceFactory_Params_Data() = delete;
        };
        static_assert(sizeof(Service_ConnectToDeviceFactory_Params_Data) == 16,
            "Bad sizeof(Service_ConnectToDeviceFactory_Params_Data)");
        constexpr uint32_t kService_ConnectToFakeDeviceFactory_Name = 1;
        class Service_ConnectToFakeDeviceFactory_Params_Data {
        public:
            static Service_ConnectToFakeDeviceFactory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Service_ConnectToFakeDeviceFactory_Params_Data))) Service_ConnectToFakeDeviceFactory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data request;
            uint8_t padfinal_[4];

        private:
            Service_ConnectToFakeDeviceFactory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Service_ConnectToFakeDeviceFactory_Params_Data() = delete;
        };
        static_assert(sizeof(Service_ConnectToFakeDeviceFactory_Params_Data) == 16,
            "Bad sizeof(Service_ConnectToFakeDeviceFactory_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_INTERNAL_H_