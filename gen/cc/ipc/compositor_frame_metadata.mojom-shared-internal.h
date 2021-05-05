// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_COMPOSITOR_FRAME_METADATA_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_COMPOSITOR_FRAME_METADATA_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/selection.mojom-shared-internal.h"
#include "cc/ipc/surface_id.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/events/mojo/latency_info.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {
        class CompositorFrameMetadata_Data;

#pragma pack(push, 1)
        class CompositorFrameMetadata_Data {
        public:
            static CompositorFrameMetadata_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CompositorFrameMetadata_Data))) CompositorFrameMetadata_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float device_scale_factor;
            float page_scale_factor;
            mojo::internal::Pointer<::gfx::mojom::internal::Vector2dF_Data> root_scroll_offset;
            mojo::internal::Pointer<::gfx::mojom::internal::SizeF_Data> scrollable_viewport_size;
            mojo::internal::Pointer<::gfx::mojom::internal::SizeF_Data> root_layer_size;
            float min_page_scale_factor;
            float max_page_scale_factor;
            uint8_t root_overflow_x_hidden : 1;
            uint8_t root_overflow_y_hidden : 1;
            uint8_t may_contain_video : 1;
            uint8_t is_resourceless_software_draw_with_scroll_or_animation : 1;
            uint8_t pad10_[3];
            float top_controls_height;
            float top_controls_shown_ratio;
            float bottom_controls_height;
            float bottom_controls_shown_ratio;
            uint32_t root_background_color;
            mojo::internal::Pointer<::cc::mojom::internal::Selection_Data> selection;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::ui::mojom::internal::LatencyInfo_Data>>> latency_info;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::cc::mojom::internal::SurfaceId_Data>>> referenced_surfaces;

        private:
            CompositorFrameMetadata_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CompositorFrameMetadata_Data() = delete;
        };
        static_assert(sizeof(CompositorFrameMetadata_Data) == 96,
            "Bad sizeof(CompositorFrameMetadata_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_COMPOSITOR_FRAME_METADATA_MOJOM_SHARED_INTERNAL_H_