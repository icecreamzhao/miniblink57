// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MANAGER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MANAGER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/service_manager/public/interfaces/connector.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace service_manager {
namespace mojom {
    namespace internal {
        class RunningServiceInfo_Data;

#pragma pack(push, 1)
        class RunningServiceInfo_Data {
        public:
            static RunningServiceInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RunningServiceInfo_Data))) RunningServiceInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t id;
            uint32_t pid;
            mojo::internal::Pointer<::service_manager::mojom::internal::Identity_Data> identity;

        private:
            RunningServiceInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RunningServiceInfo_Data() = delete;
        };
        static_assert(sizeof(RunningServiceInfo_Data) == 24,
            "Bad sizeof(RunningServiceInfo_Data)");
        constexpr uint32_t kServiceManagerListener_OnInit_Name = 0;
        class ServiceManagerListener_OnInit_Params_Data {
        public:
            static ServiceManagerListener_OnInit_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceManagerListener_OnInit_Params_Data))) ServiceManagerListener_OnInit_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::RunningServiceInfo_Data>>> running_services;

        private:
            ServiceManagerListener_OnInit_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceManagerListener_OnInit_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceManagerListener_OnInit_Params_Data) == 16,
            "Bad sizeof(ServiceManagerListener_OnInit_Params_Data)");
        constexpr uint32_t kServiceManagerListener_OnServiceCreated_Name = 1;
        class ServiceManagerListener_OnServiceCreated_Params_Data {
        public:
            static ServiceManagerListener_OnServiceCreated_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceManagerListener_OnServiceCreated_Params_Data))) ServiceManagerListener_OnServiceCreated_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::RunningServiceInfo_Data> service;

        private:
            ServiceManagerListener_OnServiceCreated_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceManagerListener_OnServiceCreated_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceManagerListener_OnServiceCreated_Params_Data) == 16,
            "Bad sizeof(ServiceManagerListener_OnServiceCreated_Params_Data)");
        constexpr uint32_t kServiceManagerListener_OnServiceStarted_Name = 2;
        class ServiceManagerListener_OnServiceStarted_Params_Data {
        public:
            static ServiceManagerListener_OnServiceStarted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceManagerListener_OnServiceStarted_Params_Data))) ServiceManagerListener_OnServiceStarted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::service_manager::mojom::internal::Identity_Data> identity;
            uint32_t pid;
            uint8_t padfinal_[4];

        private:
            ServiceManagerListener_OnServiceStarted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceManagerListener_OnServiceStarted_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceManagerListener_OnServiceStarted_Params_Data) == 24,
            "Bad sizeof(ServiceManagerListener_OnServiceStarted_Params_Data)");
        constexpr uint32_t kServiceManagerListener_OnServiceFailedToStart_Name = 3;
        class ServiceManagerListener_OnServiceFailedToStart_Params_Data {
        public:
            static ServiceManagerListener_OnServiceFailedToStart_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceManagerListener_OnServiceFailedToStart_Params_Data))) ServiceManagerListener_OnServiceFailedToStart_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::service_manager::mojom::internal::Identity_Data> identity;

        private:
            ServiceManagerListener_OnServiceFailedToStart_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceManagerListener_OnServiceFailedToStart_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceManagerListener_OnServiceFailedToStart_Params_Data) == 16,
            "Bad sizeof(ServiceManagerListener_OnServiceFailedToStart_Params_Data)");
        constexpr uint32_t kServiceManagerListener_OnServiceStopped_Name = 4;
        class ServiceManagerListener_OnServiceStopped_Params_Data {
        public:
            static ServiceManagerListener_OnServiceStopped_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceManagerListener_OnServiceStopped_Params_Data))) ServiceManagerListener_OnServiceStopped_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::service_manager::mojom::internal::Identity_Data> identity;

        private:
            ServiceManagerListener_OnServiceStopped_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceManagerListener_OnServiceStopped_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceManagerListener_OnServiceStopped_Params_Data) == 16,
            "Bad sizeof(ServiceManagerListener_OnServiceStopped_Params_Data)");
        constexpr uint32_t kServiceManager_AddListener_Name = 0;
        class ServiceManager_AddListener_Params_Data {
        public:
            static ServiceManager_AddListener_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceManager_AddListener_Params_Data))) ServiceManager_AddListener_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data listener;

        private:
            ServiceManager_AddListener_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceManager_AddListener_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceManager_AddListener_Params_Data) == 16,
            "Bad sizeof(ServiceManager_AddListener_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MANAGER_MOJOM_SHARED_INTERNAL_H_