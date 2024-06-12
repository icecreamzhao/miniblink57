// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_BLUETOOTH_PUBLIC_INTERFACES_UUID_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_BLUETOOTH_PUBLIC_INTERFACES_UUID_MOJOM_SHARED_INTERNAL_H_

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
namespace bluetooth {
namespace mojom {
    namespace internal {
        class UUID_Data;

#pragma pack(push, 1)
        class UUID_Data {
        public:
            static UUID_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(UUID_Data))) UUID_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> uuid;

        private:
            UUID_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~UUID_Data() = delete;
        };
        static_assert(sizeof(UUID_Data) == 16,
            "Bad sizeof(UUID_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace bluetooth

#endif // DEVICE_BLUETOOTH_PUBLIC_INTERFACES_UUID_MOJOM_SHARED_INTERNAL_H_