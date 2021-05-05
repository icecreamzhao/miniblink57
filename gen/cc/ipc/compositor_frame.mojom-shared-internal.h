// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_COMPOSITOR_FRAME_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_COMPOSITOR_FRAME_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/compositor_frame_metadata.mojom-shared-internal.h"
#include "cc/ipc/render_pass.mojom-shared-internal.h"
#include "cc/ipc/transferable_resource.mojom-shared-internal.h"
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
        class CompositorFrame_Data;

#pragma pack(push, 1)
        class CompositorFrame_Data {
        public:
            static CompositorFrame_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CompositorFrame_Data))) CompositorFrame_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::CompositorFrameMetadata_Data> metadata;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::cc::mojom::internal::TransferableResource_Data>>> resources;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::cc::mojom::internal::RenderPass_Data>>> passes;

        private:
            CompositorFrame_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CompositorFrame_Data() = delete;
        };
        static_assert(sizeof(CompositorFrame_Data) == 32,
            "Bad sizeof(CompositorFrame_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_COMPOSITOR_FRAME_MOJOM_SHARED_INTERNAL_H_