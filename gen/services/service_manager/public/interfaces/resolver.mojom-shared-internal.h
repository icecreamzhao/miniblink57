// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_RESOLVER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_RESOLVER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/file_path.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/service_manager/public/interfaces/interface_provider_spec.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace service_manager {
namespace mojom {
    namespace internal {
        class ResolveResult_Data;

#pragma pack(push, 1)
        class ResolveResult_Data {
        public:
            static ResolveResult_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ResolveResult_Data))) ResolveResult_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<::service_manager::mojom::internal::InterfaceProviderSpec_Data>>> interface_provider_specs;
            mojo::internal::Pointer<::mojo::common::mojom::internal::FilePath_Data> package_path;

        private:
            ResolveResult_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ResolveResult_Data() = delete;
        };
        static_assert(sizeof(ResolveResult_Data) == 32,
            "Bad sizeof(ResolveResult_Data)");
        constexpr uint32_t kResolver_ResolveServiceName_Name = 0;
        class Resolver_ResolveServiceName_Params_Data {
        public:
            static Resolver_ResolveServiceName_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Resolver_ResolveServiceName_Params_Data))) Resolver_ResolveServiceName_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> service_name;

        private:
            Resolver_ResolveServiceName_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Resolver_ResolveServiceName_Params_Data() = delete;
        };
        static_assert(sizeof(Resolver_ResolveServiceName_Params_Data) == 16,
            "Bad sizeof(Resolver_ResolveServiceName_Params_Data)");
        class Resolver_ResolveServiceName_ResponseParams_Data {
        public:
            static Resolver_ResolveServiceName_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Resolver_ResolveServiceName_ResponseParams_Data))) Resolver_ResolveServiceName_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ResolveResult_Data> result;
            mojo::internal::Pointer<internal::ResolveResult_Data> parent;

        private:
            Resolver_ResolveServiceName_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Resolver_ResolveServiceName_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Resolver_ResolveServiceName_ResponseParams_Data) == 24,
            "Bad sizeof(Resolver_ResolveServiceName_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_RESOLVER_MOJOM_SHARED_INTERNAL_H_