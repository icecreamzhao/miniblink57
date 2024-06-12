// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_FRAME_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_FRAME_MOJOM_SHARED_INTERNAL_H_

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
namespace content {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kFrame_GetInterfaceProvider_Name = 0;
        class Frame_GetInterfaceProvider_Params_Data {
        public:
            static Frame_GetInterfaceProvider_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Frame_GetInterfaceProvider_Params_Data))) Frame_GetInterfaceProvider_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data interfaces;
            uint8_t padfinal_[4];

        private:
            Frame_GetInterfaceProvider_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Frame_GetInterfaceProvider_Params_Data() = delete;
        };
        static_assert(sizeof(Frame_GetInterfaceProvider_Params_Data) == 16,
            "Bad sizeof(Frame_GetInterfaceProvider_Params_Data)");
        constexpr uint32_t kFrameHost_GetInterfaceProvider_Name = 0;
        class FrameHost_GetInterfaceProvider_Params_Data {
        public:
            static FrameHost_GetInterfaceProvider_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FrameHost_GetInterfaceProvider_Params_Data))) FrameHost_GetInterfaceProvider_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data interfaces;
            uint8_t padfinal_[4];

        private:
            FrameHost_GetInterfaceProvider_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FrameHost_GetInterfaceProvider_Params_Data() = delete;
        };
        static_assert(sizeof(FrameHost_GetInterfaceProvider_Params_Data) == 16,
            "Bad sizeof(FrameHost_GetInterfaceProvider_Params_Data)");
        constexpr uint32_t kFrameFactory_CreateFrame_Name = 0;
        class FrameFactory_CreateFrame_Params_Data {
        public:
            static FrameFactory_CreateFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FrameFactory_CreateFrame_Params_Data))) FrameFactory_CreateFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t frame_routing_id;
            mojo::internal::Handle_Data frame;
            mojo::internal::Interface_Data host;

        private:
            FrameFactory_CreateFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FrameFactory_CreateFrame_Params_Data() = delete;
        };
        static_assert(sizeof(FrameFactory_CreateFrame_Params_Data) == 24,
            "Bad sizeof(FrameFactory_CreateFrame_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_FRAME_MOJOM_SHARED_INTERNAL_H_