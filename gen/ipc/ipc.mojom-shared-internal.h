// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IPC_IPC_MOJOM_SHARED_INTERNAL_H_
#define IPC_IPC_MOJOM_SHARED_INTERNAL_H_

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
namespace IPC {
namespace mojom {
    namespace internal {
        class SerializedHandle_Data;

        struct SerializedHandle_Type_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
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
        class SerializedHandle_Data {
        public:
            static SerializedHandle_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SerializedHandle_Data))) SerializedHandle_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data the_handle;
            int32_t type;

        private:
            SerializedHandle_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SerializedHandle_Data() = delete;
        };
        static_assert(sizeof(SerializedHandle_Data) == 16,
            "Bad sizeof(SerializedHandle_Data)");
        constexpr uint32_t kChannel_SetPeerPid_Name = 0;
        class Channel_SetPeerPid_Params_Data {
        public:
            static Channel_SetPeerPid_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Channel_SetPeerPid_Params_Data))) Channel_SetPeerPid_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t pid;
            uint8_t padfinal_[4];

        private:
            Channel_SetPeerPid_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Channel_SetPeerPid_Params_Data() = delete;
        };
        static_assert(sizeof(Channel_SetPeerPid_Params_Data) == 16,
            "Bad sizeof(Channel_SetPeerPid_Params_Data)");
        constexpr uint32_t kChannel_Receive_Name = 1;
        class Channel_Receive_Params_Data {
        public:
            static Channel_Receive_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Channel_Receive_Params_Data))) Channel_Receive_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::SerializedHandle_Data>>> handles;

        private:
            Channel_Receive_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Channel_Receive_Params_Data() = delete;
        };
        static_assert(sizeof(Channel_Receive_Params_Data) == 24,
            "Bad sizeof(Channel_Receive_Params_Data)");
        constexpr uint32_t kChannel_GetAssociatedInterface_Name = 2;
        class Channel_GetAssociatedInterface_Params_Data {
        public:
            static Channel_GetAssociatedInterface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Channel_GetAssociatedInterface_Params_Data))) Channel_GetAssociatedInterface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::AssociatedInterfaceRequest_Data request;
            uint8_t padfinal_[4];

        private:
            Channel_GetAssociatedInterface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Channel_GetAssociatedInterface_Params_Data() = delete;
        };
        static_assert(sizeof(Channel_GetAssociatedInterface_Params_Data) == 24,
            "Bad sizeof(Channel_GetAssociatedInterface_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace IPC

#endif // IPC_IPC_MOJOM_SHARED_INTERNAL_H_