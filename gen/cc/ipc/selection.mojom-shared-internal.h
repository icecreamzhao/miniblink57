// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SELECTION_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_SELECTION_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/mojo/selection_bound.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {
        class Selection_Data;

#pragma pack(push, 1)
        class Selection_Data {
        public:
            static Selection_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Selection_Data))) Selection_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::SelectionBound_Data> start;
            mojo::internal::Pointer<::gfx::mojom::internal::SelectionBound_Data> end;
            uint8_t is_editable : 1;
            uint8_t is_empty_text_form_control : 1;
            uint8_t padfinal_[7];

        private:
            Selection_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Selection_Data() = delete;
        };
        static_assert(sizeof(Selection_Data) == 32,
            "Bad sizeof(Selection_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_SELECTION_MOJOM_SHARED_INTERNAL_H_