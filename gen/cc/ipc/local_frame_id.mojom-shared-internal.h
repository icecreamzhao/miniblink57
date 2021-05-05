// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_LOCAL_FRAME_ID_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_LOCAL_FRAME_ID_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/unguessable_token.mojom-shared-internal.h"
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
namespace cc {
namespace mojom {
    namespace internal {
        class LocalFrameId_Data;

#pragma pack(push, 1)
        class LocalFrameId_Data {
        public:
            static LocalFrameId_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LocalFrameId_Data))) LocalFrameId_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t local_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::UnguessableToken_Data> nonce;

        private:
            LocalFrameId_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LocalFrameId_Data() = delete;
        };
        static_assert(sizeof(LocalFrameId_Data) == 24,
            "Bad sizeof(LocalFrameId_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_LOCAL_FRAME_ID_MOJOM_SHARED_INTERNAL_H_