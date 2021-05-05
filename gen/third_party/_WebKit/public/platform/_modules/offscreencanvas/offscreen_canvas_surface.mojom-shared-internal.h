// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_OFFSCREENCANVAS_OFFSCREEN_CANVAS_SURFACE_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_OFFSCREENCANVAS_OFFSCREEN_CANVAS_SURFACE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/compositor_frame.mojom-shared-internal.h"
#include "cc/ipc/frame_sink_id.mojom-shared-internal.h"
#include "cc/ipc/mojo_compositor_frame_sink.mojom-shared-internal.h"
#include "cc/ipc/surface_id.mojom-shared-internal.h"
#include "cc/ipc/surface_info.mojom-shared-internal.h"
#include "cc/ipc/surface_sequence.mojom-shared-internal.h"
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
namespace blink {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kOffscreenCanvasSurface_Require_Name = 0;
        class OffscreenCanvasSurface_Require_Params_Data {
        public:
            static OffscreenCanvasSurface_Require_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OffscreenCanvasSurface_Require_Params_Data))) OffscreenCanvasSurface_Require_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceId_Data> surface_id;
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceSequence_Data> sequence;

        private:
            OffscreenCanvasSurface_Require_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OffscreenCanvasSurface_Require_Params_Data() = delete;
        };
        static_assert(sizeof(OffscreenCanvasSurface_Require_Params_Data) == 24,
            "Bad sizeof(OffscreenCanvasSurface_Require_Params_Data)");
        constexpr uint32_t kOffscreenCanvasSurface_Satisfy_Name = 1;
        class OffscreenCanvasSurface_Satisfy_Params_Data {
        public:
            static OffscreenCanvasSurface_Satisfy_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OffscreenCanvasSurface_Satisfy_Params_Data))) OffscreenCanvasSurface_Satisfy_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceSequence_Data> sequence;

        private:
            OffscreenCanvasSurface_Satisfy_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OffscreenCanvasSurface_Satisfy_Params_Data() = delete;
        };
        static_assert(sizeof(OffscreenCanvasSurface_Satisfy_Params_Data) == 16,
            "Bad sizeof(OffscreenCanvasSurface_Satisfy_Params_Data)");
        constexpr uint32_t kOffscreenCanvasSurfaceClient_OnSurfaceCreated_Name = 0;
        class OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data {
        public:
            static OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data))) OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceInfo_Data> surface_info;

        private:
            OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data() = delete;
        };
        static_assert(sizeof(OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data) == 16,
            "Bad sizeof(OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data)");
        constexpr uint32_t kOffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Name = 0;
        class OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data {
        public:
            static OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data))) OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::FrameSinkId_Data> frame_sink_id;
            mojo::internal::Interface_Data client;
            mojo::internal::Handle_Data service;
            uint8_t padfinal_[4];

        private:
            OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data() = delete;
        };
        static_assert(sizeof(OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data) == 32,
            "Bad sizeof(OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data)");
        constexpr uint32_t kOffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Name = 0;
        class OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data {
        public:
            static OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data))) OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::FrameSinkId_Data> frame_sink_id;
            mojo::internal::Interface_Data client;
            mojo::internal::Handle_Data sink;
            uint8_t padfinal_[4];

        private:
            OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data() = delete;
        };
        static_assert(sizeof(OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data) == 32,
            "Bad sizeof(OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_OFFSCREENCANVAS_OFFSCREEN_CANVAS_SURFACE_MOJOM_SHARED_INTERNAL_H_