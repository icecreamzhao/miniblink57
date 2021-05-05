// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef URL_MOJO_ORIGIN_MOJOM_SHARED_INTERNAL_H_
#define URL_MOJO_ORIGIN_MOJOM_SHARED_INTERNAL_H_

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
        class Origin_Data;

#pragma pack(push, 1)
        class Origin_Data {
        public:
            static Origin_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Origin_Data))) Origin_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> scheme;
            mojo::internal::Pointer<mojo::internal::String_Data> host;
            uint16_t port;
            uint8_t unique : 1;
            uint8_t padfinal_[5];

        private:
            Origin_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Origin_Data() = delete;
        };
        static_assert(sizeof(Origin_Data) == 32,
            "Bad sizeof(Origin_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace url

#endif // URL_MOJO_ORIGIN_MOJOM_SHARED_INTERNAL_H_