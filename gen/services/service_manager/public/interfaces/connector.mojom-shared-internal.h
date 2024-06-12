// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_CONNECTOR_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_CONNECTOR_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace service_manager {
namespace mojom {
    namespace internal {
        class Identity_Data;

        struct ConnectResult_Data {
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

#pragma pack(push, 1)
        class Identity_Data {
        public:
            static Identity_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Identity_Data))) Identity_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::String_Data> user_id;
            mojo::internal::Pointer<mojo::internal::String_Data> instance;

        private:
            Identity_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Identity_Data() = delete;
        };
        static_assert(sizeof(Identity_Data) == 32,
            "Bad sizeof(Identity_Data)");
        constexpr uint32_t kPIDReceiver_SetPID_Name = 0;
        class PIDReceiver_SetPID_Params_Data {
        public:
            static PIDReceiver_SetPID_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PIDReceiver_SetPID_Params_Data))) PIDReceiver_SetPID_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t pid;
            uint8_t padfinal_[4];

        private:
            PIDReceiver_SetPID_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PIDReceiver_SetPID_Params_Data() = delete;
        };
        static_assert(sizeof(PIDReceiver_SetPID_Params_Data) == 16,
            "Bad sizeof(PIDReceiver_SetPID_Params_Data)");
        constexpr uint32_t kConnector_StartService_Name = 0;
        class Connector_StartService_Params_Data {
        public:
            static Connector_StartService_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Connector_StartService_Params_Data))) Connector_StartService_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::Identity_Data> name;
            mojo::internal::Handle_Data service;
            mojo::internal::Handle_Data pid_receiver_request;

        private:
            Connector_StartService_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Connector_StartService_Params_Data() = delete;
        };
        static_assert(sizeof(Connector_StartService_Params_Data) == 24,
            "Bad sizeof(Connector_StartService_Params_Data)");
        constexpr uint32_t kConnector_Connect_Name = 1;
        class Connector_Connect_Params_Data {
        public:
            static Connector_Connect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Connector_Connect_Params_Data))) Connector_Connect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::Identity_Data> target;
            mojo::internal::Handle_Data remote_interfaces;
            uint8_t padfinal_[4];

        private:
            Connector_Connect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Connector_Connect_Params_Data() = delete;
        };
        static_assert(sizeof(Connector_Connect_Params_Data) == 24,
            "Bad sizeof(Connector_Connect_Params_Data)");
        class Connector_Connect_ResponseParams_Data {
        public:
            static Connector_Connect_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Connector_Connect_ResponseParams_Data))) Connector_Connect_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> user_id;

        private:
            Connector_Connect_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Connector_Connect_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Connector_Connect_ResponseParams_Data) == 24,
            "Bad sizeof(Connector_Connect_ResponseParams_Data)");
        constexpr uint32_t kConnector_BindInterface_Name = 2;
        class Connector_BindInterface_Params_Data {
        public:
            static Connector_BindInterface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Connector_BindInterface_Params_Data))) Connector_BindInterface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::Identity_Data> target;
            mojo::internal::Pointer<mojo::internal::String_Data> interface_name;
            mojo::internal::Handle_Data interface_pipe;
            uint8_t padfinal_[4];

        private:
            Connector_BindInterface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Connector_BindInterface_Params_Data() = delete;
        };
        static_assert(sizeof(Connector_BindInterface_Params_Data) == 32,
            "Bad sizeof(Connector_BindInterface_Params_Data)");
        class Connector_BindInterface_ResponseParams_Data {
        public:
            static Connector_BindInterface_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Connector_BindInterface_ResponseParams_Data))) Connector_BindInterface_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> user_id;

        private:
            Connector_BindInterface_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Connector_BindInterface_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Connector_BindInterface_ResponseParams_Data) == 24,
            "Bad sizeof(Connector_BindInterface_ResponseParams_Data)");
        constexpr uint32_t kConnector_Clone_Name = 3;
        class Connector_Clone_Params_Data {
        public:
            static Connector_Clone_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Connector_Clone_Params_Data))) Connector_Clone_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data request;
            uint8_t padfinal_[4];

        private:
            Connector_Clone_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Connector_Clone_Params_Data() = delete;
        };
        static_assert(sizeof(Connector_Clone_Params_Data) == 16,
            "Bad sizeof(Connector_Clone_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_CONNECTOR_MOJOM_SHARED_INTERNAL_H_