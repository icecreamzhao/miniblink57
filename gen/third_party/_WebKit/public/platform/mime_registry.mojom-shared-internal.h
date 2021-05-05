// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_SHARED_INTERNAL_H_

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
namespace blink {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kMimeRegistry_GetMimeTypeFromExtension_Name = 0;
        class MimeRegistry_GetMimeTypeFromExtension_Params_Data {
        public:
            static MimeRegistry_GetMimeTypeFromExtension_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MimeRegistry_GetMimeTypeFromExtension_Params_Data))) MimeRegistry_GetMimeTypeFromExtension_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> extension;

        private:
            MimeRegistry_GetMimeTypeFromExtension_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MimeRegistry_GetMimeTypeFromExtension_Params_Data() = delete;
        };
        static_assert(sizeof(MimeRegistry_GetMimeTypeFromExtension_Params_Data) == 16,
            "Bad sizeof(MimeRegistry_GetMimeTypeFromExtension_Params_Data)");
        class MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data {
        public:
            static MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data))) MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> mime_type;

        private:
            MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data) == 16,
            "Bad sizeof(MimeRegistry_GetMimeTypeFromExtension_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_SHARED_INTERNAL_H_