// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/service_manager/public/interfaces/connector.mojom-shared-internal.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared-internal.h"
#include "services/service_manager/public/interfaces/interface_provider_spec.mojom-shared-internal.h"
#include "services/service_manager/public/interfaces/service_control.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace service_manager {
namespace mojom {
    namespace internal {
        class ServiceInfo_Data;

#pragma pack(push, 1)
        class ServiceInfo_Data {
        public:
            static ServiceInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceInfo_Data))) ServiceInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::service_manager::mojom::internal::Identity_Data> identity;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<::service_manager::mojom::internal::InterfaceProviderSpec_Data>>> interface_provider_specs;

        private:
            ServiceInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceInfo_Data() = delete;
        };
        static_assert(sizeof(ServiceInfo_Data) == 24,
            "Bad sizeof(ServiceInfo_Data)");
        constexpr uint32_t kService_OnStart_Name = 0;
        class Service_OnStart_Params_Data {
        public:
            static Service_OnStart_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Service_OnStart_Params_Data))) Service_OnStart_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ServiceInfo_Data> info;

        private:
            Service_OnStart_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Service_OnStart_Params_Data() = delete;
        };
        static_assert(sizeof(Service_OnStart_Params_Data) == 16,
            "Bad sizeof(Service_OnStart_Params_Data)");
        class Service_OnStart_ResponseParams_Data {
        public:
            static Service_OnStart_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Service_OnStart_ResponseParams_Data))) Service_OnStart_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data connector_request;
            mojo::internal::AssociatedInterfaceRequest_Data control_request;

        private:
            Service_OnStart_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Service_OnStart_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Service_OnStart_ResponseParams_Data) == 16,
            "Bad sizeof(Service_OnStart_ResponseParams_Data)");
        constexpr uint32_t kService_OnConnect_Name = 1;
        class Service_OnConnect_Params_Data {
        public:
            static Service_OnConnect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Service_OnConnect_Params_Data))) Service_OnConnect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ServiceInfo_Data> source_info;
            mojo::internal::Handle_Data interfaces;
            uint8_t padfinal_[4];

        private:
            Service_OnConnect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Service_OnConnect_Params_Data() = delete;
        };
        static_assert(sizeof(Service_OnConnect_Params_Data) == 24,
            "Bad sizeof(Service_OnConnect_Params_Data)");
        class Service_OnConnect_ResponseParams_Data {
        public:
            static Service_OnConnect_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Service_OnConnect_ResponseParams_Data))) Service_OnConnect_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Service_OnConnect_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Service_OnConnect_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Service_OnConnect_ResponseParams_Data) == 8,
            "Bad sizeof(Service_OnConnect_ResponseParams_Data)");
        constexpr uint32_t kService_OnBindInterface_Name = 2;
        class Service_OnBindInterface_Params_Data {
        public:
            static Service_OnBindInterface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Service_OnBindInterface_Params_Data))) Service_OnBindInterface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ServiceInfo_Data> source_info;
            mojo::internal::Pointer<mojo::internal::String_Data> interface_name;
            mojo::internal::Handle_Data interface_pipe;
            uint8_t padfinal_[4];

        private:
            Service_OnBindInterface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Service_OnBindInterface_Params_Data() = delete;
        };
        static_assert(sizeof(Service_OnBindInterface_Params_Data) == 32,
            "Bad sizeof(Service_OnBindInterface_Params_Data)");
        class Service_OnBindInterface_ResponseParams_Data {
        public:
            static Service_OnBindInterface_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Service_OnBindInterface_ResponseParams_Data))) Service_OnBindInterface_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Service_OnBindInterface_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Service_OnBindInterface_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Service_OnBindInterface_ResponseParams_Data) == 8,
            "Bad sizeof(Service_OnBindInterface_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_INTERNAL_H_