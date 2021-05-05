// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef URL_MOJO_URL_MOJOM_SHARED_INTERNAL_H_
#define URL_MOJO_URL_MOJOM_SHARED_INTERNAL_H_

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
namespace url {
namespace mojom {
    namespace internal {
        class Url_Data;

#pragma pack(push, 1)
        class Url_Data {
        public:
            static Url_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Url_Data))) Url_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> url;

        private:
            Url_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Url_Data() = delete;
        };
        static_assert(sizeof(Url_Data) == 16,
            "Bad sizeof(Url_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace url

#endif // URL_MOJO_URL_MOJOM_SHARED_INTERNAL_H_