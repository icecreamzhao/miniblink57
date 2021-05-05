// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "gpu/ipc/common/mailbox_holder.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {
        class TransferableResource_Data;

        struct ResourceFormat_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)
        class TransferableResource_Data {
        public:
            static TransferableResource_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TransferableResource_Data))) TransferableResource_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t id;
            int32_t format;
            uint32_t filter;
            uint8_t read_lock_fences_enabled : 1;
            uint8_t is_software : 1;
            uint8_t is_overlay_candidate : 1;
            uint8_t is_backed_by_surface_texture : 1;
            uint8_t wants_promotion_hint : 1;
            uint8_t pad7_[3];
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> size;
            mojo::internal::Pointer<::gpu::mojom::internal::MailboxHolder_Data> mailbox_holder;

        private:
            TransferableResource_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TransferableResource_Data() = delete;
        };
        static_assert(sizeof(TransferableResource_Data) == 40,
            "Bad sizeof(TransferableResource_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_SHARED_INTERNAL_H_