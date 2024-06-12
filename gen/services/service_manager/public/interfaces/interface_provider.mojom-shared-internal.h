// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_MOJOM_SHARED_INTERNAL_H_

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
namespace service_manager {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kInterfaceProvider_GetInterface_Name = 0;
        class InterfaceProvider_GetInterface_Params_Data {
        public:
            static InterfaceProvider_GetInterface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InterfaceProvider_GetInterface_Params_Data))) InterfaceProvider_GetInterface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> interface_name;
            mojo::internal::Handle_Data pipe;
            uint8_t padfinal_[4];

        private:
            InterfaceProvider_GetInterface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InterfaceProvider_GetInterface_Params_Data() = delete;
        };
        static_assert(sizeof(InterfaceProvider_GetInterface_Params_Data) == 24,
            "Bad sizeof(InterfaceProvider_GetInterface_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_MOJOM_SHARED_INTERNAL_H_