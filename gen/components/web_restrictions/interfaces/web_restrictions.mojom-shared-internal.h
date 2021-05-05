// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_WEB_RESTRICTIONS_INTERFACES_WEB_RESTRICTIONS_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_WEB_RESTRICTIONS_INTERFACES_WEB_RESTRICTIONS_MOJOM_SHARED_INTERNAL_H_

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
namespace web_restrictions {
namespace mojom {
    namespace internal {
        class ClientResult_Data;

#pragma pack(push, 1)
        class ClientResult_Data {
        public:
            static ClientResult_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ClientResult_Data))) ClientResult_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, int32_t>> intParams;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<mojo::internal::String_Data>>> stringParams;

        private:
            ClientResult_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ClientResult_Data() = delete;
        };
        static_assert(sizeof(ClientResult_Data) == 24,
            "Bad sizeof(ClientResult_Data)");
        constexpr uint32_t kWebRestrictions_GetResult_Name = 0;
        class WebRestrictions_GetResult_Params_Data {
        public:
            static WebRestrictions_GetResult_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebRestrictions_GetResult_Params_Data))) WebRestrictions_GetResult_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> url;

        private:
            WebRestrictions_GetResult_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebRestrictions_GetResult_Params_Data() = delete;
        };
        static_assert(sizeof(WebRestrictions_GetResult_Params_Data) == 16,
            "Bad sizeof(WebRestrictions_GetResult_Params_Data)");
        class WebRestrictions_GetResult_ResponseParams_Data {
        public:
            static WebRestrictions_GetResult_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebRestrictions_GetResult_ResponseParams_Data))) WebRestrictions_GetResult_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ClientResult_Data> reply;

        private:
            WebRestrictions_GetResult_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebRestrictions_GetResult_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebRestrictions_GetResult_ResponseParams_Data) == 16,
            "Bad sizeof(WebRestrictions_GetResult_ResponseParams_Data)");
        constexpr uint32_t kWebRestrictions_RequestPermission_Name = 1;
        class WebRestrictions_RequestPermission_Params_Data {
        public:
            static WebRestrictions_RequestPermission_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebRestrictions_RequestPermission_Params_Data))) WebRestrictions_RequestPermission_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> url;

        private:
            WebRestrictions_RequestPermission_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebRestrictions_RequestPermission_Params_Data() = delete;
        };
        static_assert(sizeof(WebRestrictions_RequestPermission_Params_Data) == 16,
            "Bad sizeof(WebRestrictions_RequestPermission_Params_Data)");
        class WebRestrictions_RequestPermission_ResponseParams_Data {
        public:
            static WebRestrictions_RequestPermission_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WebRestrictions_RequestPermission_ResponseParams_Data))) WebRestrictions_RequestPermission_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t result : 1;
            uint8_t padfinal_[7];

        private:
            WebRestrictions_RequestPermission_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WebRestrictions_RequestPermission_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WebRestrictions_RequestPermission_ResponseParams_Data) == 16,
            "Bad sizeof(WebRestrictions_RequestPermission_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace web_restrictions

#endif // COMPONENTS_WEB_RESTRICTIONS_INTERFACES_WEB_RESTRICTIONS_MOJOM_SHARED_INTERNAL_H_