// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_SPEC_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_SPEC_MOJOM_SHARED_INTERNAL_H_

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
        class InterfaceSet_Data;
        class CapabilitySet_Data;
        class InterfaceProviderSpec_Data;

#pragma pack(push, 1)
        class InterfaceSet_Data {
        public:
            static InterfaceSet_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InterfaceSet_Data))) InterfaceSet_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> interfaces;

        private:
            InterfaceSet_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InterfaceSet_Data() = delete;
        };
        static_assert(sizeof(InterfaceSet_Data) == 16,
            "Bad sizeof(InterfaceSet_Data)");
        class CapabilitySet_Data {
        public:
            static CapabilitySet_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CapabilitySet_Data))) CapabilitySet_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> capabilities;

        private:
            CapabilitySet_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CapabilitySet_Data() = delete;
        };
        static_assert(sizeof(CapabilitySet_Data) == 16,
            "Bad sizeof(CapabilitySet_Data)");
        class InterfaceProviderSpec_Data {
        public:
            static InterfaceProviderSpec_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(InterfaceProviderSpec_Data))) InterfaceProviderSpec_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<internal::InterfaceSet_Data>>> provides;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<internal::CapabilitySet_Data>>> requires;

        private:
            InterfaceProviderSpec_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~InterfaceProviderSpec_Data() = delete;
        };
        static_assert(sizeof(InterfaceProviderSpec_Data) == 24,
            "Bad sizeof(InterfaceProviderSpec_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_SPEC_MOJOM_SHARED_INTERNAL_H_