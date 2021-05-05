// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_ASSOCIATED_INTERFACES_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_ASSOCIATED_INTERFACES_MOJOM_SHARED_INTERNAL_H_

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
namespace content {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kAssociatedInterfaceProvider_GetAssociatedInterface_Name = 0;
        class AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data {
        public:
            static AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data))) AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::AssociatedInterfaceRequest_Data request;
            uint8_t padfinal_[4];

        private:
            AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data() = delete;
        };
        static_assert(sizeof(AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data) == 24,
            "Bad sizeof(AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data)");
        constexpr uint32_t kRouteProvider_GetRoute_Name = 0;
        class RouteProvider_GetRoute_Params_Data {
        public:
            static RouteProvider_GetRoute_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RouteProvider_GetRoute_Params_Data))) RouteProvider_GetRoute_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t routing_id;
            mojo::internal::AssociatedInterfaceRequest_Data request;

        private:
            RouteProvider_GetRoute_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RouteProvider_GetRoute_Params_Data() = delete;
        };
        static_assert(sizeof(RouteProvider_GetRoute_Params_Data) == 16,
            "Bad sizeof(RouteProvider_GetRoute_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_ASSOCIATED_INTERFACES_MOJOM_SHARED_INTERNAL_H_