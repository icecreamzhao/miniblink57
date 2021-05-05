// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_DISPLAY_COMPOSITOR_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_DISPLAY_COMPOSITOR_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/frame_sink_id.mojom-shared-internal.h"
#include "cc/ipc/mojo_compositor_frame_sink.mojom-shared-internal.h"
#include "cc/ipc/surface_id.mojom-shared-internal.h"
#include "cc/ipc/surface_info.mojom-shared-internal.h"
#include "gpu/ipc/common/surface_handle.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"
#include "ui/gfx/mojo/color_space.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kDisplayPrivate_SetDisplayVisible_Name = 0;
        class DisplayPrivate_SetDisplayVisible_Params_Data {
        public:
            static DisplayPrivate_SetDisplayVisible_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayPrivate_SetDisplayVisible_Params_Data))) DisplayPrivate_SetDisplayVisible_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t visible : 1;
            uint8_t padfinal_[7];

        private:
            DisplayPrivate_SetDisplayVisible_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayPrivate_SetDisplayVisible_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayPrivate_SetDisplayVisible_Params_Data) == 16,
            "Bad sizeof(DisplayPrivate_SetDisplayVisible_Params_Data)");
        constexpr uint32_t kDisplayPrivate_ResizeDisplay_Name = 1;
        class DisplayPrivate_ResizeDisplay_Params_Data {
        public:
            static DisplayPrivate_ResizeDisplay_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayPrivate_ResizeDisplay_Params_Data))) DisplayPrivate_ResizeDisplay_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> size_in_pixel;

        private:
            DisplayPrivate_ResizeDisplay_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayPrivate_ResizeDisplay_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayPrivate_ResizeDisplay_Params_Data) == 16,
            "Bad sizeof(DisplayPrivate_ResizeDisplay_Params_Data)");
        constexpr uint32_t kDisplayPrivate_SetDisplayColorSpace_Name = 2;
        class DisplayPrivate_SetDisplayColorSpace_Params_Data {
        public:
            static DisplayPrivate_SetDisplayColorSpace_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayPrivate_SetDisplayColorSpace_Params_Data))) DisplayPrivate_SetDisplayColorSpace_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::ColorSpace_Data> color_space;

        private:
            DisplayPrivate_SetDisplayColorSpace_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayPrivate_SetDisplayColorSpace_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayPrivate_SetDisplayColorSpace_Params_Data) == 16,
            "Bad sizeof(DisplayPrivate_SetDisplayColorSpace_Params_Data)");
        constexpr uint32_t kDisplayPrivate_SetOutputIsSecure_Name = 3;
        class DisplayPrivate_SetOutputIsSecure_Params_Data {
        public:
            static DisplayPrivate_SetOutputIsSecure_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayPrivate_SetOutputIsSecure_Params_Data))) DisplayPrivate_SetOutputIsSecure_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t secure : 1;
            uint8_t padfinal_[7];

        private:
            DisplayPrivate_SetOutputIsSecure_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayPrivate_SetOutputIsSecure_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayPrivate_SetOutputIsSecure_Params_Data) == 16,
            "Bad sizeof(DisplayPrivate_SetOutputIsSecure_Params_Data)");
        constexpr uint32_t kDisplayCompositor_CreateDisplayCompositorFrameSink_Name = 0;
        class DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data {
        public:
            static DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data))) DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::FrameSinkId_Data> frame_sink_id;
            mojo::internal::Pointer<::gpu::mojom::internal::SurfaceHandle_Data> widget;
            mojo::internal::Handle_Data compositor_frame_sink;
            mojo::internal::Handle_Data compositor_frame_sink_private;
            mojo::internal::Interface_Data compositor_frame_sink_client;
            mojo::internal::Handle_Data display_private;
            uint8_t padfinal_[4];

        private:
            DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data) == 48,
            "Bad sizeof(DisplayCompositor_CreateDisplayCompositorFrameSink_Params_Data)");
        constexpr uint32_t kDisplayCompositor_CreateOffscreenCompositorFrameSink_Name = 1;
        class DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data {
        public:
            static DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data))) DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::FrameSinkId_Data> frame_sink_id;
            mojo::internal::Handle_Data compositor_frame_sink;
            mojo::internal::Handle_Data compositor_frame_sink_private;
            mojo::internal::Interface_Data compositor_frame_sink_client;

        private:
            DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data) == 32,
            "Bad sizeof(DisplayCompositor_CreateOffscreenCompositorFrameSink_Params_Data)");
        constexpr uint32_t kDisplayCompositorClient_OnSurfaceCreated_Name = 0;
        class DisplayCompositorClient_OnSurfaceCreated_Params_Data {
        public:
            static DisplayCompositorClient_OnSurfaceCreated_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayCompositorClient_OnSurfaceCreated_Params_Data))) DisplayCompositorClient_OnSurfaceCreated_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceInfo_Data> surface_info;

        private:
            DisplayCompositorClient_OnSurfaceCreated_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayCompositorClient_OnSurfaceCreated_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayCompositorClient_OnSurfaceCreated_Params_Data) == 16,
            "Bad sizeof(DisplayCompositorClient_OnSurfaceCreated_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_DISPLAY_COMPOSITOR_MOJOM_SHARED_INTERNAL_H_