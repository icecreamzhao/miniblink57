// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_MAILBOX_HOLDER_MOJOM_SHARED_INTERNAL_H_
#define GPU_IPC_COMMON_MAILBOX_HOLDER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "gpu/ipc/common/mailbox.mojom-shared-internal.h"
#include "gpu/ipc/common/sync_token.mojom-shared-internal.h"
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
namespace gpu {
namespace mojom {
    namespace internal {
        class MailboxHolder_Data;

#pragma pack(push, 1)
        class MailboxHolder_Data {
        public:
            static MailboxHolder_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MailboxHolder_Data))) MailboxHolder_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gpu::mojom::internal::Mailbox_Data> mailbox;
            mojo::internal::Pointer<::gpu::mojom::internal::SyncToken_Data> sync_token;
            uint32_t texture_target;
            uint8_t padfinal_[4];

        private:
            MailboxHolder_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MailboxHolder_Data() = delete;
        };
        static_assert(sizeof(MailboxHolder_Data) == 32,
            "Bad sizeof(MailboxHolder_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_MAILBOX_HOLDER_MOJOM_SHARED_INTERNAL_H_