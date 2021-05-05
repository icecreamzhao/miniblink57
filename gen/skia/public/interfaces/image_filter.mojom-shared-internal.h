// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKIA_PUBLIC_INTERFACES_IMAGE_FILTER_MOJOM_SHARED_INTERNAL_H_
#define SKIA_PUBLIC_INTERFACES_IMAGE_FILTER_MOJOM_SHARED_INTERNAL_H_

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
namespace skia {
namespace mojom {
    namespace internal {
        class ImageFilter_Data;

#pragma pack(push, 1)
        class ImageFilter_Data {
        public:
            static ImageFilter_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ImageFilter_Data))) ImageFilter_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> data;

        private:
            ImageFilter_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ImageFilter_Data() = delete;
        };
        static_assert(sizeof(ImageFilter_Data) == 16,
            "Bad sizeof(ImageFilter_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace skia

#endif // SKIA_PUBLIC_INTERFACES_IMAGE_FILTER_MOJOM_SHARED_INTERNAL_H_