// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_ICC_PROFILE_MOJOM_SHARED_INTERNAL_H_
#define UI_GFX_MOJO_ICC_PROFILE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/mojo/color_space.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace gfx {
namespace mojom {
    namespace internal {
        class ICCProfile_Data;
        using ICCProfile_Type_Data = mojo::internal::NativeEnum_Data;

#pragma pack(push, 1)
        class ICCProfile_Data {
        public:
            static ICCProfile_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ICCProfile_Data))) ICCProfile_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::ColorSpace_Data> color_space;
            int32_t type;
            uint8_t pad1_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> data;
            uint64_t id;

        private:
            ICCProfile_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ICCProfile_Data() = delete;
        };
        static_assert(sizeof(ICCProfile_Data) == 40,
            "Bad sizeof(ICCProfile_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gfx

#endif // UI_GFX_MOJO_ICC_PROFILE_MOJOM_SHARED_INTERNAL_H_