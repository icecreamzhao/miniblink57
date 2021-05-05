// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_FACTORY_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_FACTORY_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/service_manager/public/interfaces/service.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace service_manager {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kServiceFactory_CreateService_Name = 0;
        class ServiceFactory_CreateService_Params_Data {
        public:
            static ServiceFactory_CreateService_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceFactory_CreateService_Params_Data))) ServiceFactory_CreateService_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data service;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> name;

        private:
            ServiceFactory_CreateService_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceFactory_CreateService_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceFactory_CreateService_Params_Data) == 24,
            "Bad sizeof(ServiceFactory_CreateService_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_FACTORY_MOJOM_SHARED_INTERNAL_H_