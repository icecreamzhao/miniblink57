// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_UNGUESSABLE_TOKEN_MOJOM_SHARED_INTERNAL_H_
#define MOJO_COMMON_UNGUESSABLE_TOKEN_MOJOM_SHARED_INTERNAL_H_

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
namespace mojo {
namespace common {
    namespace mojom {
        namespace internal {
            class UnguessableToken_Data;

#pragma pack(push, 1)
            class UnguessableToken_Data {
            public:
                static UnguessableToken_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(UnguessableToken_Data))) UnguessableToken_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                uint64_t high;
                uint64_t low;

            private:
                UnguessableToken_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~UnguessableToken_Data() = delete;
            };
            static_assert(sizeof(UnguessableToken_Data) == 24,
                "Bad sizeof(UnguessableToken_Data)");

#pragma pack(pop)

        } // namespace internal
    } // namespace mojom
} // namespace common
} // namespace mojo

#endif // MOJO_COMMON_UNGUESSABLE_TOKEN_MOJOM_SHARED_INTERNAL_H_